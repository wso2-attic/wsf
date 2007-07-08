datadir=$(prefix)
tmpincludedir=$(prefix)/include/axis2-1.1
includedir=$(prefix)/include/axis2-1.1
SUBDIRS = src $(TESTDIR) include
include_HEADERS=$(top_builddir)/include/*.h
tmpinclude_DATA=config.h
data_DATA= INSTALL README AUTHORS NEWS CREDITS LICENSE COPYING
EXTRA_DIST = build.sh autogen.sh CREDITS LICENSE
dist-hook:
	rm -rf `find $(distdir)/ -type d -name .svn`
	rm -rf `find $(distdir)/ -type d -name .deps`
