SUBDIRS = src 
docsdir=$(prefix)/docs
includedir=$(prefix)/include/rampart-0.90
samplesdir=$(prefix)/samples/rampartc
include_HEADERS=$(top_builddir)/include/*.h
samples_DATA=
docs_DATA=xdocs/*
EXTRA_DIST = LICENSE NOTICE build.sh autogen.sh samples build test xdocs

check:	
	./rampart-tests.sh

install-data-hook:
	cp -rf samples/* $(samplesdir)
	sh copy_samples.sh $(prefix)


