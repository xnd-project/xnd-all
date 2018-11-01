.. meta::
   :robots: index, follow
   :description: xnd documentation
   :keywords: libxnd, xnd, libgumath, gumath, xndtools, C, Python, array computing

.. sectionauthor:: Stefan Krah <skrah at bytereef.org>


Introduction
============

XND is a collection of libraries for general typed containers. The XND container is capable
of holding data of many different shapes, sizes, and types. The data held
by XND is always strongly typed and is contiguous in memory, thus operations
on the data can be highly optimized.

Features
--------

- N-dimensional arrays (similar to NumPy's ``ndarray``),
- Variable-dimensional arrays (i.e. "ragged" arrays),
- Arrays of records (i.e. arrays of *structs* in C),
- *Native* ``NULL``,
   - Any value may be ``NULL`` within the array.
   - This stands in stark contract to many other array libraries (such as NumPy) where the closest concept of ``NULL`` is the floating-point ``NaN``.
- *Native* strings,
   - Again, a stark contrast to many other array libraries where the closest concept of a *string* is simply fixed-length bytes. In XND, strings values are variable length and have an encoding scheme.
   - Supports string-based categorical fields, where the values are internally mapped to integers for efficient storage.

Tutorials
---------

The following tutorials demonstrate the capabilities of XND:

- :ref:`naive_bayes`: Shows how XND handles variable-length arrays of strings, arrays of records, and categorical values. Also shows how to build pipelines of operations via fast JIT-compiled Numba kernels.
- :ref:`neural_net_gpu_dask`: Shows how XND can both (1) target the GPU and (2) be distributed via Dask tasks to a cluster of worker nodes.

Implementation Overview
-----------------------

XND's implementation is highly flexible both at the C-level and the Python-level.

At the C-level, XND's libxnd is a stand-alone C-library with no concrete ties to Python,
thus it can be leveraged by any other language through a thin wrapper.

At the Python-level, the XND python package will be compatible with the
`uarray interface <https://github.com/Quansight-Labs/uarray>`_, thus (in the future) it
could be leveraged beneath higher-level computational frameworks, such as under Pandas,
PyTorch, and Dask.

XND overall purpose is to be a cross-language, flexible, strongly-typed container for
your data. The XND project splits responsibilities into multiple sub-projects:

- `libndtypes <https://ndtypes.readthedocs.io/en/latest/libndtypes/index.html>`_: C-library for representing the *type* of your data (shape, strides, alignment, atomic datatypes, etc). Does not hold your data, just describes its in-memory structure.

- `ndtypes <https://ndtypes.readthedocs.io/en/latest/ndtypes/index.html>`_: Python-library wrapper atop ``libndtypes``.

- :ref:`libxnd`: C-library, depends on ``libndtypes``, and holds your data.

- :ref:`xnd`: Python-library wrapper atop ``libxnd``.

- :ref:`libgumath`: C-library for registering functions which operate on your data (we'll call these "kernels"). Gumath handles multi-dispatch to these kernels based on your data type and shape. Kernels can be registered at runtime, which allows the use of JIT compilers.

- :ref:`gumath`: Python-library wrapper atop ``libgumath``.


Documentation TOC
-----------------

.. toctree::
   :maxdepth: 1

   tutorials/index.rst
   libxnd/index.rst
   xnd/index.rst
   libgumath/index.rst
   gumath/index.rst
   xndtools/index.rst
   releases/index.rst

