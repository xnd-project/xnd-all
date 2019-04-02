.. meta::
   :robots: index, follow
   :description: xnd-all documentation
   :keywords: gumath, installation

.. sectionauthor:: Andrew Fulton <andrewfulton9 at gmail.com>

============
Installation
============

From Source
===========

Prerequisites
~~~~~~~~~~~~~

Python2 is not supported. If not already present, install the Python3
development packages:

.. code-block:: sh

   # Debian, Ubuntu:
   sudo apt-get install gcc make
   sudo apt-get install python3-dev

   # Fedora, RedHat:
   sudo yum install gcc make
   sudo yum install python3-devel

   # openSUSE:
   sudo zypper install gcc make
   sudo zypper install python3-devel

   # BSD:
   # You know what to do.

   # Mac OS X:
   # Install Xcode and Python 3 headers.

Clone `gumath repo <https://github.com/plures/gumath/>`_

.. code-block:: console

    $ git clone https://github.com/plures/gumath
    $ cd gumath

Requirements
------------

`ndtypes <https://github.com/plures/ndtypes>`_
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: console

    $ git clone https://github.com/plures/ndtypes
    $ cd ndtypes
    $ python3 setup.py install
    $ cd ..

`xnd <https://github.com/plures/xnd>`_
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: console

    $ git clone https://github.com/plures/xnd
    $ cd xnd
    $ python3 setup.py install
    $ cd ..

Install gumath
--------------

.. code-block:: console

    $ python3 setup.py install

Conda Install
=============

.. code-block:: console

    $ conda install -c xnd/label/dev gumath


Pip Install
===========

.. code-block:: console

    $ python3 -m pip install gumath