#datadir=$(prefix)
SUBDIRS = src 
includedir=$(prefix)/include/axis2-1.1
include_HEADERS=$(top_builddir)/include/*.h
data_DATA= INSTALL README AUTHORS NEWS LICENSE COPYING
#EXTRA_DIST = build.sh autogen.sh CREDITS LICENSE
dist-hook:
	rm -rf `find $(distdir)/ -type d -name .svn`
	rm -rf `find $(distdir)/ -type d -name .deps`
