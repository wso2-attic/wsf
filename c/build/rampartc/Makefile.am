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
	rm -rf `find $(distdir)/ -type d -name *.svn`
	rm -rf `find $(distdir)/ -type d -name *.deps`
	rm -rf `find $(distdir)/ -type d -name *.libs`
	rm -rf `find $(distdir)/ -type f -name Makefile`
	rm -rf `find $(distdir)/ -type d -name autom4te.cache`


