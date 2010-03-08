datadir=$(prefix)
samplesdir=$(prefix)/samples
logsdir=$(prefix)/logs
docsdir=$(prefix)/docs/axis2c
includedir=$(prefix)/include/wsfc-2.0.0

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = axis2c.pc

SUBDIRS = util $(GUTHTHILA_DIR) axiom neethi src $(TESTDIR) include ides tools/tcpmon
include_HEADERS=$(top_builddir)/include/*.h
data_DATA= README \
	INSTALL CREDITS COPYING NEWS NOTICE 

logs_DATA=
docs_DATA=
samples_DATA=
EXTRA_DIST = build.sh autogen.sh CREDITS LICENSE build guththila tools AUTHORS NOTICE xdocs samples

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
	mkdir -p $(samplesdir)/src/axis2c
	cp -rf samples/* $(samplesdir)/src/axis2c

