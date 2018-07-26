# Makefile for Sphinx documentation.
SPHINXBUILD = sphinx-build
BUILDDIR = build

default: html

html:
	${SPHINXBUILD} -b html -d build/doctrees . build/html

doctest:
	${SPHINXBUILD} -b doctest -d build/doctrees . build/html

clean:
	rm -rf $(BUILDDIR)/*
