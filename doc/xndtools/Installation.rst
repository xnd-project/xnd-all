.. meta::
   :robots: index, follow
   :description: xnd-all documentation
   :keywords: xndtools, installation

.. sectionauthor:: Andrew Fulton <andrewfulton9 at gmail.com>

============
Installation
============



From Source
===========

Prerequisites
-------------

Python2 is not supported. If not already present, install the Python3
development packages:

.. code-block:: console

   # Debian, Ubuntu:
   $ sudo apt-get install gcc make
   $ sudo apt-get install python3-dev

   # Fedora, RedHat:
   $ sudo yum install gcc make
   $ sudo yum install python3-devel

   # openSUSE:
   $ sudo zypper install gcc make
   $ sudo zypper install python3-devel

   # BSD:
   # You know what to do.

   # Mac OS X:
   # Install Xcode and Python 3 headers.


Requirements
------------

`ndtypes <https://github.com/plures/ndtypes>`_
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: console

    $ git clone https://github.com/plures/ndtypes.git
    $ cd ndtypes
    $ ./configure --prefix=$PREFIX
    $ make
    $ make install
    $ pip install -U .
    $ cd ..

`xnd <https://github.com/plures/xnd>`_
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: console

    $ git clone https://github.com/plures/xnd.git
    $ cd xnd
    $ ./configure --prefix=$PREFIX --with-includes=$PREFIX/include
    $ make
    $ make install
    $ pip install -U .
    $ cd ..

`gumath <https://github.com/plures/gumath>`_
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: console

    $ git clone https://github.com/plures/gumath.git
    $ cd gumath
    $ ./configure --prefix=$PREFIX --with-includes=$PREFIX/include
    $ make
    $ make install
    $ pip install -U .
    $ cd ..

Installation
------------

.. code-block:: console

    $ git clone https://github.com/plures/xndtools.git
    $ cd xndtools
    $ pip install -U



Conda Install
==============

.. code-block:: console

    $ conda install -c xnd/label/dev xndtools

