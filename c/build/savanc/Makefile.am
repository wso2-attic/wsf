SUBDIRS = src samples
includedir=$(prefix)/include/axis2-1.1

docsdir=$(prefix)/docs/savanc

docs_DATA=
include_HEADERS=$(top_builddir)/include/*.h

install-data-hook:
	cp -rf xdocs/* $(docsdir)

EXTRA_DIST = build.sh autogen.sh build xdocs


