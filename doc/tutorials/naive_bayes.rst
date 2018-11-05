.. meta::
   :robots: index, follow
   :description: Fast and Easy Naive Bayes via XND
   :keywords: xnd, kernel, string, categorical, NLP, pipeline, Numba

.. sectionauthor:: Ryan Henning <ryan at rhobota.com>

.. _naive_bayes:

Fast and Easy Naive Bayes via XND
=================================

The Naive Bayes algorithm for text classification is a common, well-used,
well-loved method. It is often used as a baseline for judging other algorithms,
although there are cases where it alone performs well-enough to be used in
production-grade systems. In this chapter, we will implement the Naive Bayes
algorithm for text classification using clean & beautiful & fast XND code.

After the algorithm is developed, we will apply it to the dataset of `NIPS
publications <https://papers.nips.cc/>`_ from 1987-2017. We will build a
model to predict the publication year, and in so doing we will see how the
subject-matter of the conference has changed over time.

**NOTE:** This code is does not work under the current version of XND. This
code is intended to demonstrate where XND is headed (if the developers of
XND agree with this vision). See the section at the bottom of this page
which details the :ref:`nb_missing_features`.


Reading the dataset
-------------------

Reading the data is trivial. We'll hard-code a small dataset to experiment with,
then we'll read a JSON file for the *real* dataset, which is a dataset of 7,124
NIPS articles. See below:

.. code-block:: python

    >>> demo_corpus = xnd([
    ...    "With great power comes great responsibility.",
    ...    "Sharing the world has never been humanity's defining attribute.",
    ...    "I'm the best there is at what I do but what I do best isn't very nice.",
    ...    "You wouldn't like me when I'm angry.",
    ...    "I don't like bullies. I don't care where they're from.",
    ...    "I am Iron Man.",
    ...    "I am Groot.",
    ...])
    >>>
    >>> demo_corpus
    xnd(['With great power comes great responsibility.',
         "Sharing the world has never been humanity's defining attribute.",
         "I'm the best there is at what I do but what I do best isn't very nice.",
         "You wouldn't like me when I'm angry.",
         "I don't like bullies. I don't care where they're from.",
         'I am Iron Man.',
         'I am Groot.'],
        type='7 * string')
    >>>
    >>> record_type = ndt("""
    ... {
    ...     year: int16,
    ...     title: string,
    ...     paper_text: string
    ... }
    ... """)
    >>> nips_corpus = xnd.read_json('nips_publications.json', record_type)
    >>> nips_corpus[:2]
    xnd([{'year': 1987,
          'title': 'Self-Organization of Associative Databas...',
          'paper_text': '767\n\nSELF-ORGANIZATION OF ASSOCIATIVE DA...'},
         {'year': 1987,
          'title': 'A Mean Field Theory of Layer IV of Visua...',
          'paper_text': '683\n\nA MEAN FIELD THEORY OF LAYER IV OF ...'}],
        type='2 * {year : int16, title : string, paper_text : string}')



Preprocessing
-------------

The first computation step of our Naive Bayes pipeline will be to "preprocess"
the text of each document. In the NLP-world, "preprocessing" commonly means to:

1. Convert all the text to lower-case.
2. Tokenize the text (in our case we will tokenize the text into individual words).
3. Remove common words (such as "a", "an", "but", "and", "they" ... etc). These are usually called "stop words" by the NLP folks.

The following code these things for the ``demo_corpus``. We won't use a complete
set of stop words, but we will use a few to show the overall goal.

.. code-block:: python

    def tolower(document):
        """
        Return the lower case version of the string `document`.

        >>> tolower('I am Groot.')
        'i am groot.'
        """
        return document.lower()


    def build_tokenizer(raw_re):
        """
        Closure to build a `tokenizer` function with the `raw_re` pre-compiled for speed.

        >>> tokenizer = build_tokenizer(r'\w+')
        >>> tokenizer("You wouldn't like me when I'm angry.")
        ['You', 'wouldn', 't', 'like', 'me', 'when', 'I', 'm', 'angry']
        """
        compiled_re = re.compile(raw_re)

        def tokenizer(document):
            """
            Tokenize the string `document`, returning a list of strings (the `tokens`).
            """
            tokens = compiled_re.findall(document)
            return tokens

        return tokenizer


    def build_stop_words_remover(stop_words):
        """
        Closure to build a `stop_words_remover` function.

        >>> stop_words = ['like', 'when', 'me']
        >>> stop_words_remover = build_stop_words_remover(stop_words)
        >>> stop_words_remover(['You', "wouldn't", 'like', 'me', 'when', "I'm", 'angry'])
        ['You', "wouldn't", "I'm", 'angry']
        """
        stop_words = set(stop_words)  # ensure fast 'is in'

        def stop_words_remover(tokens):
            """
            Remove stop words from the list given list of `tokens`.
            """
            return [token for token in tokens if token not in stop_words]

        return stop_words_remover


    def build_preprocesser(steps):
        """
        Create a xnd-vectorized, JIT function that preproccesses each document of our
        corpus by running the `steps` (which is a list of functions).
        """
        @xndvectorize('... * string -> ... * var * string')
        def preprocess(document):
            """
            Preprocess each document by performing the `steps` on each document.
            """
            result = document
            for step in steps:
                result = step(result)
            return result

        return preprocess


    >>> tokenizer = build_tokenizer(r"[\w'_]+")
    >>>
    >>> stop_words = ['with', 'i', 'the', 'am', 'has', 'is', 'at', 'do', 'but']
    >>> stop_words_remover = build_stop_words_remover(stop_words)
    >>>
    >>> preprocess = build_preprocesser([tolower, tokenizer, stop_words_remover])
    >>>
    >>> demo_corpus_preprocessed = preprocess(demo_corpus)
    >>> demo_corpus_preprocessed
    xnd([['great', 'power', 'comes', 'great', 'responsibility'],
         ['sharing', 'world', 'never', 'been', "humanity's", 'defining', 'attribute'],
         ["i'm", 'best', 'there', 'what', 'what', 'best', "isn't", 'very', 'nice'],
         ['you', "wouldn't", 'like', 'me', 'when', "i'm", 'angry'],
         ["don't", 'like', 'bullies', "don't", 'care', 'where', "they're", 'from'],
         ['iron', 'man'],
         ['groot']],
        type='var * var * string')


Naive Bayes Classifier
----------------------

Let's create the "vocabulary", which is a set of all the words that appear in our corpus.

This may not be a job for XND, but if it were, here is an idea for an interface for it.

.. code-block:: python

    from gumath import functions as fn

    def vocab_mapper(tokens):
        return fn.unique(tokens.value)

    def vocab_reducer(doc1_vocab, doc2_vocab):
        # Set union.
        return fn.unique(fn.concat(doc1_vocab, doc2_vocab))

    >>> demo_vocab = xnd.map_reduce(demo_corpus_preprocessed, vocab_mapper, vocab_reducer)
    >>> demo_vocab
    {'angry',
     'attribute',
     'been',
     'best',
     'bullies',
     'care',
     'comes',
     ...
     'when',
     'where',
     'world',
     "wouldn't",
     'you'}
    >>> index_to_word = list(demo_vocab)
    >>> word_to_index = {word: index for index, word in enumerate(index_to_word)}


Now let's create a bag-of-words.

.. code-block:: python

    def build_bow_vectorizer(word_to_index):
        """
        Build a bag-of-words vectorizer. Using the word-to-index mapping given.
        The columns will be words (denoted by the mapping of `word_to_index`),
        and the rows are documents. A value of one (1) in a cell denotes that
        that row's document contains that column's word.
        """
        N = len(word_to_index)

        @xndvectorize('... * var * string -> ... * {} * int16'.format(N))
        def bow_vectorize(tokens, result):
            result[:] = 0
            for token in tokens:
                result[word_to_index[token.value]] = 1
            return vect

        return bow_vectorize

    >>> bow_vectorize = build_bow_vectorizer(word_to_index)
    >>> bow = bow_vectorize(demo_corpus_preprocessed)
    >>> bow
    xnd([[0, 0, 0, 1, 0, 1, 0, 0, 0, ...],
         [1, 0, 0, 0, 0, 0, 0, 0, 0, ...],
         [0, 0, 0, 0, 0, 0, 1, 1, 1, ...],
         [0, 0, 0, 0, 1, 0, 0, 0, 0, ...],
         [0, 0, 1, 0, 0, 0, 0, 0, 0, ...],
         [0, 1, 0, 0, 0, 0, 0, 0, 0, ...],
         [0, 0, 0, 0, 0, 0, 0, 0, 0, ...]],
        type='7 * 33 * int16')


TO BE CONTINUED


.. _nb_missing_features:

Missing Features
================

xnd.read_json
-------------

.. code-block:: python

    >>> record_type = ndt("""
    ...    {
    ...        year: int16,
    ...        title: string,
    ...        paper_text: string
    ...    }
    ...""")
    >>>
    >>> dataset = xnd.read_json('nips_publications.json', record_type)
    >>>
    >>> dataset[:2]
    xnd([{'year': 1987,
          'title': 'Self-Organization of Associative Databas...',
          'paper_text': '767\n\nSELF-ORGANIZATION OF ASSOCIATIVE DA...'},
         {'year': 1987,
          'title': 'A Mean Field Theory of Layer IV of Visua...',
          'paper_text': '683\n\nA MEAN FIELD THEORY OF LAYER IV OF ...'}],
        type='2 * {year : int16, title : string, paper_text : string}')


Abbreviated Printouts
---------------------

XND doesn't currently print abbreviated data like NumPy and Pandas do. The example above shows
abbreviated data in the `paper_text` field, but this is fake output. In reality this output
will include the entire `paper_text` field and would be hard to deal with as a human.


Severe Limiations in ``xndvectorize()``
---------------------------------------

This works:

.. code-block:: python

    @xndvectorize('... * N * int16 -> ... * N * int16')
    def square(x, y):
        N = x.shape[0]
        for i in range(N):
            y[i] = x[i] * x[i]

    >>> square(xnd([[1, 2, 3], [4, 5, 6]], dtype='int16'))
    xnd([[1, 4, 9], [16, 25, 36]], type='2 * 3 * int16')


But this doesn't:

.. code-block:: python

    @xndvectorize('... * int16 -> ... * int16')
    def negate(x, y):
        y = -x

    >>> negate(xnd([[1, 2, 3], [4, 5, 6]], dtype='int16'))
    xnd([[-9192, -3227, 32627], [0, 23616, 4822]], type='2 * 3 * int16')

Of course maybe Numba is simulating Python's "reference-style" variables, so the above wouldn't work for that reason. I also tried this:

.. code-block:: python

    @xndvectorize('... * int16 -> ... * int16')
    def negate(x, y):
        y[()] = -x

    >>> negate(xnd([[1, 2, 3], [4, 5, 6]], dtype='int16'))
    TypingError: Failed at nopython (nopython frontend)
    Cannot resolve setitem: int16[()] = int64

And I tried a few other things, but it seems that this use-case isn't supported yet.

**The other area** where ``xndvectorize()`` is limited is in it's handling of strings. It doesn't seem to support strings at all.

.. code-block:: python

    @xndvectorize('... * string -> ... * string')
    def tolower(x, y):
        pass  # <-- doesn't matter what's here; the error is thrown by `@xndvectorize`.

    >>> tolower(xnd(['hi', 'friend']))
    ValueError
    ...
    ----> 1 @xndvectorize('... * string -> ... * string')
    ...
    ...
    ValueError: unsupported dtype


Advanced Slicing
----------------

.. code-block:: python

    >>> x = xnd([{'a': 7, 'b': 8}, {'a': 14, 'b': 16}])
    >>> x
    xnd([{'a': 7, 'b': 8}, {'a': 14, 'b': 16}], type='2 * {a : int64, b : int64}')
    >>>
    >>> x[:, 'a']
    IndexError: too many indices



