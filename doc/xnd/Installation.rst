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


Get ndtypes
-----------

.. code-block::

    $ git clone https://github.com/plures/ndtypes.git

For building the xnd Python module
----------------------------------

This also builds libndtypes and copies the ndtypes Python package into the python directory next to the xnd package.

.. code-block::

    $ cd ndtypes
    $ python3 setup.py install
    $ cd ..

Python Installation (Unix/Windows)
================================================

.. code-block:: console

    $ python3 setup.py install

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
