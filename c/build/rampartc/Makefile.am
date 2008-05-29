SUBDIRS = src 
docsdir=$(prefix)/docs/rampartc
samplesdir=$(prefix)/samples/rampartc
includedir=$(prefix)/include/rampart-1.2.0

include_HEADERS=$(top_builddir)/include/*.h

docs_DATA=
samples_DATA=

EXTRA_DIST = LICENSE NOTICE build.sh autogen.sh build xdocs

install-data-hook:
	cp -rf samples/* $(samplesdir)


