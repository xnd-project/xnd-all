.. meta::
   :robots: index, follow
   :description: xnd documentation
   :keywords: libxnd, xnd, libgumath, gumath, C, Python, array computing

.. sectionauthor:: Stefan Krah <skrah at bytereef.org>


xnd
===

xnd is a package for typing raw memory blocks using a close variant
of the datashape type language.


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


Releases
--------

.. toctree::
   :maxdepth: 1

   releases/index.rst
