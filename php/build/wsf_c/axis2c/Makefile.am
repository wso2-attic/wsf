datadir=$(prefix)
logsdir=$(prefix)/logs
docsdir=$(prefix)/docs

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = axis2c.pc

SUBDIRS = util $(GUTHTHILA_DIR) axiom src $(TESTDIR) include ides
include_HEADERS=$(top_builddir)/include/*.h

logs_DATA=
docs_DATA=docs/* samples/server/axis2.xml
EXTRA_DIST = build.sh autogen.sh CREDITS LICENSE samples/server/axis2.log samples build axis2c_build.sh docs guththila tools rampart AUTHORS

dist-hook:
	rm -rf `find $(distdir)/ -type d -name .svn`
	rm -rf `find $(distdir)/ -type f -name *.la`
	rm -rf `find $(distdir)/ -type f -name *.o`
	rm -rf `find $(distdir)/ -type f -name *.lo`
	rm -rf `find $(distdir)/ -type f -name *.loT`
	rm -rf `find $(distdir)/ -type d -name .deps`
	rm -rf `find $(distdir)/ -type d -name .libs`
	rm -rf `find $(distdir)/ -type f -name Makefile`
	rm -rf `find $(distdir)/ -type f -name axis2c-sample-src-${PACKAGE_VERSION}.tar.gz`
	rm -rf `find $(distdir)/ -type d -name autom4te.cache`
	sh dist.sh

bindist: $(bin_PROGRAMS)
	rm -rf axis2c-bin-${PACKAGE_VERSION}-linux
	sh bindist.sh
	mkdir axis2c-bin-${PACKAGE_VERSION}-linux
	cp -r `pwd`/deploy/* axis2c-bin-${PACKAGE_VERSION}-linux
	tar -cf - axis2c-bin-${PACKAGE_VERSION}-linux | gzip -c > axis2c-bin-${PACKAGE_VERSION}-linux.tar.gz
	rm -rf axis2c-bin-${PACKAGE_VERSION}-linux


