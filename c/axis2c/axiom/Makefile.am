datadir=$(prefix)
SUBDIRS = src $(TESTDIR) include
includedir=$(prefix)/include/axis2-1.0
include_HEADERS=$(top_builddir)/include/*.h
data_DATA= INSTALL README AUTHORS NEWS CREDITS LICENSE COPYING
EXTRA_DIST = build.sh autogen.sh CREDITS LICENSE
dist-hook:
	rm -rf `find $(distdir)/ -type d -name .svn`
	rm -rf `find $(distdir)/ -type d -name .deps`
