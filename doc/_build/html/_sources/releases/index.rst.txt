.. meta::
   :robots: index, follow
   :description: xnd-all documentation
   :keywords: C, array computing

.. sectionauthor:: Stefan Krah <skrah at bytereef.org>


========
Releases
========


v0.2.0b2 (February 5th 2018)
----------------------------

Second release (beta2). This release addresses several build and packaging issues:

  - Avoid copying libraries into the Python package if system libraries are used.

  - The build and install partially relied on the dev setup (ndtypes checked out
    in the xnd directory).  This dependency has been removed.

  - The conda build now supports separate library and Python module installs.

  - Configure now has a **–without-docs** option for skipping the doc install.

  - The generated parsers are now checked into the source tree to avoid
    bison/flex dependencies and unnecessary rebuilds after cloning.

  - Non-API global symbols are hidden on Linux (as long as the compiler
    supports gcc pragmas).

  - The conda build supports separate library and Python module installs.

  - Configure now has a **--without-docs** option for skipping the doc install.


v0.2.0b1 (January 20th 2018)
----------------------------

First release (beta1).
