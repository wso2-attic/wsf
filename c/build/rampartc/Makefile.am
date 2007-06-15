SUBDIRS = src 
docsdir=$(prefix)/docs/rampartc
includedir=$(prefix)/include/rampart-0.90
include_HEADERS=$(top_builddir)/include/*.h
docs_DATA=xdocs/*
EXTRA_DIST = LICENSE NOTICE build.sh autogen.sh samples build test

check:	
	./rampart-tests.sh

