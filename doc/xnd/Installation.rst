.. meta::
   :robots: index, follow
   :description: xnd-all documentation
   :keywords:

.. sectionauthor:: Andrew Fulton

============
Installation
============

===============
From Source
===============

Requirements (libndtypes)
=========================

Unless libndtypes has already been installed in the system directories,
it is recommended to clone libndtypes into the xnd directory.


Get ndtypes
-----------

.. code-block::

    $ git clone https://github.com/plures/ndtypes.git


For building libxnd only
------------------------

.. code-block::

    $ cd ndtypes
    $ ./configure
    $ make
    $ cd ..


For building the xnd Python module
----------------------------------

This also builds libndtypes and copies the ndtypes Python package into the python directory next to the xnd package.

.. code-block::

    $ cd ndtypes
    $ python3 setup.py install --local=../python
    $ cd ..


libxnd build instructions
===============================

Unix
----

Build
*****

.. code-block::

    $ ./configure
    $ make

Test
****

.. code-block::

    $ make check

Install
*******

.. code-block::

    $ make install

Clean
*****

.. code-block::

    $ make clean

Distclean
*********

.. code-block::

    $ make distclean


Windows
-------

.. code-block::

    $ cd vcbuild

Requirements
************

  - Visual Studio 2015 or later.


64-bit build
************


Set the build environment:
''''''''''''''''''''''''''

.. code-block::

    $ vcvarsall.bat x64

Build:
''''''

.. code-block::

    $ vcbuild64.bat

If successful, the static library, the dynamic library, the common header file and two executables for running the unit tests should be in the dist64 directory.

Test:
'''''

.. code-block::

    $ runtest64.bat


32-bit build
************

Set the build environment:
''''''''''''''''''''''''''

.. code-block::

    $ vcvarsall.bat x86

Build:
''''''

.. code-block::

    $ vcbuild32.bat

If successful, the static library, the dynamic library, the common header file and two executables for running the unit tests should be in the dist64 directory.

Test:
'''''

.. code-block::

    $ runtest32.bat


Python module build instructions (Unix/Windows)
================================================

To avoid shared library mismatches, the Python module builds with an rpath
and ships the library inside the package.

Unless you are a distributor with tight control over the system library
versions, it is not recommended to install the library for the Python
module.


Build all
---------

Build
*****

libxnd and the module (libxnd is copied into the package)

.. code-block:: console

    $ python3 setup.py build

Test
****

.. code-block:: console

    $ python3 setup.py test

Doctest (optional, relies on Sphinx)
************************************

.. code-block:: console

    $ python3 setup.py doctest

Install
*******

.. code-block:: console

    $ python3 setup.py install

Clean libxnd and the module
***************************

.. code-block:: console

    $ python3 setup.py distclean

================
Conda Install
================

.. code-block:: console

    $ conda install -c xnd/label/dev xnd

=============
Pip Install
=============

.. code-block:: console

    $ pip install xnd
