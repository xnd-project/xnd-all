
AC_PREREQ([2.67])
AC_INIT(xnd-all, 0.2.0dev3, skrah@bytereef.org, xnd-all, https://github.com/plures/)
AC_CONFIG_HEADER(config.h)


if test "$prefix" = "NONE"; then
    prefix=$PWD/build
fi

cd ndtypes && ./configure --prefix=$prefix && cd .. || exit 1
cd xnd && ./configure --prefix=$prefix --with-includes=$prefix/include --with-libs=$prefix/lib && cd .. || exit 1
cd gumath && ./configure --prefix=$prefix --with-includes=$prefix/include --with-libs=$prefix/lib && cd .. || exit 1



