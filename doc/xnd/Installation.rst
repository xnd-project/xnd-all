.. meta::
   :robots: index, follow
   :description: xnd-all documentation
   :keywords: xnd, installation

.. sectionauthor:: Andrew Fulton <andrewfulton9 at gmail.com>

============
Installation
============

From Source
============

Prerequisites
--------------

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

Clone the `xnd GitHub repo <https://github.com/plures/xnd/>`_.

.. code-block:: console

    $ git clone https://github.com/plures/xnd.git
    $ cd xnd

Requirements
-------------

`ndtypes <https://github.com/plures/ndtypes>`_
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

This builds libndtypes and copies the ndtypes Python package into the Python directory

.. code-block:: console

    $ git clone https://github.com/plures/ndtypes.git
    $ cd ndtypes
    $ python3 setup.py install
    $ cd ..

Python Installation (Unix/Windows)
-----------------------------------

.. code-block:: console

    $ python3 setup.py install


Conda Install
================

.. code-block:: console

    $ conda install -c xnd/label/dev xnd


Pip Install
=============

.. code-block:: console

    $ pip install xnd
