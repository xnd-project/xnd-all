#!/bin/bash

PREFIX=`python -c "from distutils.sysconfig import get_python_lib; print(get_python_lib())"`
echo "Python installation directory is $PREFIX"

cd ndtypes
./configure --prefix=$PREFIX
make
make install
pip install -U .
cd ..

cd xnd
./configure --prefix=$PREFIX --with-includes=$PREFIX/include
make
make install
pip install -U .
cd ..

cd gumath
./configure --prefix=$PREFIX --with-includes=$PREFIX/include
make
make install
pip install -U .
cd ..

cd xndtools
pip install -U .
