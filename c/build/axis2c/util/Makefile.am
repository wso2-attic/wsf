datadir=$(prefix)
tmpincludedir=$(prefix)/include/wsfc-2.0.0/
includedir=$(prefix)/include/wsfc-2.0.0/
SUBDIRS = src $(TESTDIR) include
include_HEADERS=$(top_builddir)/include/*.h
tmpinclude_DATA=config.h
data_DATA= INSTALL README AUTHORS NEWS CREDITS LICENSE COPYING
EXTRA_DIST = build.sh autogen.sh CREDITS LICENSE
dist-hook:
	rm -rf `find $(distdir)/ -type d -name .svn`
	rm -rf `find $(distdir)/ -type d -name .deps`
