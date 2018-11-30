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

This serves as a string-processing example using XND. For a numeric-computation
example of XND, see the next tutorial :ref:`neural_net_gpu_dask`.


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

The first computation step of our Naive Bayes pipeline will be to *preprocess*
the text of each document. In the NLP-world, *preprocessing* commonly means to:

1. Convert all the text to lower-case.
2. Tokenize the text (in our case this means splitting the text into individual words).
3. Remove common words (such as "a", "an", "but", "and", "they" ... etc). These are usually called *stop words* by the NLP folks.

The following code does these things for the ``demo_corpus``. We don't use a complete
set of stop words below, but we will use a few to show the strategy. The docstrings of each function
below describe their purpose and usage. See the shell output at the bottom shows how to perform
all three *preprocessing* steps in a pipelined/vectorized way with XND.

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


Compute the Vocabulary
----------------------

The next step is to create the *vocabulary*, which is a set of **all** the words that appear in our corpus.

(This may not be a job suitable for XND, but if it were, what follows is an idea of an interface for it.)

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
    >>> index_to_word = sorted(demo_vocab)
    >>> word_to_index = {word: index for index, word in enumerate(index_to_word)}


Build the Bag-of-Words (BOW)
----------------------------

Now let's create a "bag of words". The idea behind the "bag of words" is that we can make the problem **much simpler** by viewing each document as merely an unordered collection ("bag") of tokens ("words"). This, of course, throws out *a ton* of important information (the order of the words contains a lot of information which is being thrown away), but it is nonetheless a commonly-used way to simplify the problem, and insights can still usually be drawn from the data.

In the code below, we'll take our preprocessed XND container from above, and we'll convert it into a matrix. Each row *i* of the matrix represents one document. Each column *j* of the matrix represents one word in the vocabulary. The value of an element in the matrix represents how many times word *j* occurs in document *i*.

.. code-block:: python

    def build_bow_vectorizer(word_to_index):
        """
        Build a bag-of-words vectorizer, using the word-to-index mapping given.
        The columns will be words (denoted by the mapping of `word_to_index`),
        and the rows are documents.
        """
        N = len(word_to_index)

        @xndvectorize('... * var * string -> ... * {} * int16'.format(N))
        def bow_vectorize(tokens, result):
            result[:] = 0
            for token in tokens:
                result[word_to_index[token.value]] += 1
            return vect

        return bow_vectorize

    >>> bow_vectorize = build_bow_vectorizer(word_to_index)
    >>> bow = bow_vectorize(demo_corpus_preprocessed)
    >>>
    >>> bow
    xnd([[0, 0, 0, 0, 0, 0, 1, 0, 0, ...],
         [0, 1, 1, 0, 0, 0, 0, 1, 0, ...],
         [0, 0, 0, 2, 0, 0, 0, 0, 0, ...],
         [1, 0, 0, 0, 0, 0, 0, 0, 0, ...],
         [0, 0, 0, 0, 1, 1, 0, 0, 2, ...],
         [0, 0, 0, 0, 0, 0, 0, 0, 0, ...],
         [0, 0, 0, 0, 0, 0, 0, 0, 0, ...]],
        type='7 * 33 * int16')
    >>>
    >>> demo_corpus_preprocessed[2]
    xnd(["i'm", 'best', 'there', 'what', 'what', 'best', "isn't", 'very', 'nice'], type='var * string')
    >>> index_to_word
    ['angry', 'attribute', 'been', 'best', 'bullies', 'care', 'comes', 'defining', "don't", ...]


Naive Bayes Classifier
----------------------

Naive Bayes, as previously mentioned, is unlikely to be a top-performing algorithm for text
classification, but it is almost never "bad" thus it is a great benchmark. You'll see below
that we can vectorize the computation of Naive Bayes very nicely using XND. In case this is your first time
coming across the Naive Bayes implementation details, below is a description in "plane English"
about how it works.

We'll talk about all three words in its name "Naive Bayes Classifier" one-by-one.

Let's start with the last
word "Classifier" since it's the easiest. In machine learning we say something is a "classification
problem" if you are trying to find a mapping function *to* a finite set of outcomes (usually a *small*
finite set). Another common type of problem in machine learning is "regression", which is where you
are trying to find a mapping function to a continuous space (real numbers, for example). The problem we're
tackling here is to categorize (classify!) NIPS publications into the set of conference years (31 possible
outcomes, one for each of the years there has been a NIPS conference). You could argue that we should
model this problem as regression, treating time (year numbers) as continuous, but we'll go ahead and treat
it as categorical in this case so that we can use Naive Bayes.

Next word: "Bayes". Bayes' rule is so useful because you can flip around conditional probabilities.
Here's an example: Say you have a corpus of news articles. Some are sports, some are politics, and some
are science. We can easily answer questions like this: "What is the probability of seeing the word *football* in a sports article?" The way to estimate that is probably obvious to you (look through all the sports articles and see how many have that word, divided by the number of total sports articles). But what if I flip the question around like this: "What is the probability of an article being about sports when the word *football* is in it?". The way to estimate that is less obvious... and that's why we have Bayes' rule. We will use this this as a part of the Naive Bayes algorithm.

Final word: "Naive". This is the most confusion word in the name. Are we calling Thomas Bayes naive? No, we're not. He is far from naive I'm sure. The word "naive" is in reference to a very naive assumption that we make as a part of the Naive Bayes algorithm. Here's how it goes (sing the same example from above): Our *real* goal, if we could achieve it (hint: we can't) would be to estimate the probability of an article being about sports given *all* the words in the article. (In the example above, I only mentioned estimating the probability of *sports* given the single word *football*. Now I want to know what it is given *all* the words in the article.) It turns out this is not going to be possible. There are too many combinations of words that can (and do) appear in the same article, and estimating the probability of all those combinations would require more data than we could ever have, and more computation that we could ever have. So, we are forced on once again *simplify* the problem by making an assumption... a very "naive" assumption. Here it is: We'll assume that the words in a single article are independent events. That is, we'll assume that the probability of the word "football" appearing in a article is the same no matter if the word "game" is in the article. Put another way: We assume that knowing the word "game" is in an article will not change the probability that the word "football" is in that same article. This is of course a very silly assumption, but it simplifies the math to become doable, and it surprisingly still works okay.

No math above, just plane English. Feel free to look up the math, and without further ado here is the code:





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



