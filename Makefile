
# ==============================================================================
#           Unix Makefile for installing libndtypes, libxnd, libgumath
# ==============================================================================


default:
	@echo "\nPlease use an explicit \"make install\". The combined build of all xnd"
	@echo "libraries relies on the successive install of libndtypes and libxnd."
	@exit 1

libndtypes_build:
	cd ndtypes && $(MAKE)

libndtypes_install: libndtypes_build
	cd ndtypes && $(MAKE) install

libndtypes_check: libndtypes_install
	cd ndtypes && $(MAKE) check

libndtypes_memcheck: libndtypes_install
	cd ndtypes && $(MAKE) memcheck


libxnd_build: libndtypes_install
	cd xnd && $(MAKE)

libxnd_install: libxnd_build
	cd xnd && $(MAKE) install

libxnd_check: libxnd_install
	cd xnd && $(MAKE) check

libxnd_memcheck: libxnd_install
	cd xnd && $(MAKE) memcheck


libgumath_build: libxnd_install
	cd gumath && $(MAKE)

libgumath_install: libgumath_build
	cd gumath && $(MAKE) install


check: libndtypes_check libxnd_check

memcheck: libndtypes_memcheck libxnd_memcheck

install: libndtypes_install libxnd_install libgumath_install


clean: FORCE
	- cd ndtypes && $(MAKE) clean
	- cd xnd && $(MAKE) clean
	- cd gumath && $(MAKE) clean

distclean: FORCE
	- cd ndtypes && $(MAKE) distclean
	- cd xnd && $(MAKE) distclean
	- cd gumath && $(MAKE) distclean
	- cd python && rm -rf ndtypes xnd gumath __pycache__ *.egg-info
	- cd python/test && rm -rf *.py __pycache__ *.egg-info
	- cd scripts && rm -rf build
	- cd doc && rm -rf build
	- rm -rf config.log build

FORCE:
