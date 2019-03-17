.. meta::
   :robots: index, follow
   :description: xnd documentation
   :keywords: libxnd, xnd, libgumath, gumath, xndtools, C, Python, array computing

.. sectionauthor:: Stefan Krah <skrah at bytereef.org>


xnd
===

xnd is a package for general typed containers.  xnd relies on
the `libndtypes <http://ndtypes.readthedocs.io>`_ library for
typing and memory layout information.


Libxnd
------

C library.

.. toctree::
   :maxdepth: 1

   libxnd/index.rst


Xnd
---

Python bindings for libxnd.


.. toctree::
   :maxdepth: 1

   xnd/index.rst


gumath
======

gumath is a package for extensible dispatch of computational kernels that
target xnd containers.  Kernels can be added at runtime, which allows the
use of JIT compilers.


Libgumath
---------

C library.

.. toctree::
   :maxdepth: 1

   libgumath/index.rst


Gumath
------

Python bindings for libgumath.


.. toctree::
   :maxdepth: 1

   gumath/index.rst


XndTools
--------

XndTools is a Python package containing development tools for the XND project.


.. toctree::
   :maxdepth: 1

   xndtools/index.rst


Releases
--------

.. toctree::
   :maxdepth: 1

   releases/index.rst

Installation
------------

.. toctree::
   :maxdepth: 1

    installation/index.rst
