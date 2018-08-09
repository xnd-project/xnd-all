mkdir build && cd build

git clone https://github.com/plures/ndtypes.git
git clone https://github.com/plures/xnd.git
git clone https://github.com/plures/gumath.git
git clone https://github.com/plures/xndtools.git

cd ndtypes
conda build .conda\libndtypes
conda build .conda\ndtypes
conda install --use-local --yes ndtypes

cd ..\xnd
conda build .conda\libxnd
conda build .conda\xnd
conda install --use-local --yes xnd

cd ..\gumath
conda build .conda\libgumath
conda build .conda\gumath
conda install --use-local --yes gumath

cd ..\xndtools
conda build .conda\xndtools
conda install --use-local --yes xndtools

cd ..\..\

