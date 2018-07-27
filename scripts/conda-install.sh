#!/bin/sh

#
# The build uses new clones instead of subtrees in order to avoid problems
# with ``git describe --tags''.
#

mkdir build && cd build || exit 1

git clone https://github.com/plures/ndtypes.git || exit 1
git clone https://github.com/plures/xnd.git || exit 1
git clone https://github.com/plures/gumath.git || exit 1

cd ndtypes || exit 1
conda build .conda/libndtypes || exit 1
conda build .conda/ndtypes || exit 1
conda install --use-local --yes ndtypes || exit 1

cd ../xnd || exit 1
conda build .conda/libxnd || exit 1
conda build .conda/xnd || exit 1
conda install --use-local --yes xnd || exit 1

cd ../gumath || exit 1
conda build .conda/libgumath || exit 1
conda build .conda/gumath || exit 1
conda install --use-local --yes gumath || exit 1


