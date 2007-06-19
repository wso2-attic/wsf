SUBDIRS = src 
docsdir=$(prefix)/docs/rampartc
includedir=$(prefix)/include/rampart-0.90

include_HEADERS=$(top_builddir)/include/*.h

docs_DATA=

EXTRA_DIST = LICENSE NOTICE build.sh autogen.sh samples build test xdocs

check:	
	./rampart-tests.sh

install-data-hook: 
	cp -rf xdocs/* $(docsdir)
