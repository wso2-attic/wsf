datadir=$(prefix)
samplesdir=$(prefix)/samples/axis2c
logsdir=$(prefix)/logs
docsdir=$(prefix)/docs/axis2c
includedir=$(prefix)/include/axis2-1.3.0

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = axis2c.pc

SUBDIRS = util $(GUTHTHILA_DIR) axiom neethi src $(TESTDIR) include ides tools/tcpmon
include_HEADERS=$(top_builddir)/include/*.h
data_DATA= samples/server/axis2.xml README \
	INSTALL CREDITS COPYING NEWS NOTICE 

logs_DATA=
docs_DATA=
samples_DATA=
EXTRA_DIST = build.sh autogen.sh CREDITS LICENSE build axis2c_build.sh guththila tools AUTHORS NOTICE xdocs

dist-hook:
	sh dist.sh

bindist: $(bin_PROGRAMS)
	rm -rf axis2c-bin-${PACKAGE_VERSION}-linux
	sh bindist.sh
	mkdir axis2c-bin-${PACKAGE_VERSION}-linux
	cp -r `pwd`/deploy/* axis2c-bin-${PACKAGE_VERSION}-linux
	cp AUTHORS axis2c-bin-${PACKAGE_VERSION}-linux
	tar -cf - axis2c-bin-${PACKAGE_VERSION}-linux | gzip -c > axis2c-bin-${PACKAGE_VERSION}-linux.tar.gz
	rm -rf axis2c-bin-${PACKAGE_VERSION}-linux

install-data-hook:
	cp -rf samples/* $(samplesdir)

