SUBDIRS = src 
docsdir=$(prefix)/docs/rampartc
samplesdir=$(prefix)/samples/rampartc
includedir=$(prefix)/include/rampart-1.0

include_HEADERS=$(top_builddir)/include/*.h

docs_DATA=
samples_DATA=

EXTRA_DIST = LICENSE NOTICE build.sh autogen.sh build test xdocs

check:	
	./rampart-tests.sh


install-data-hook:
	cp -rf samples/* $(samplesdir)


