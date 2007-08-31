logsdir=$(prefix)/logs
confdir=$(prefix)
SUBDIRS = src samples
data_DATA= README \
	INSTALL CREDITS COPYING NEWS 

logs_DATA=

EXTRA_DIST = build.sh autogen.sh CREDITS LICENSE build.sh wsclient.mk docs
dist-hook:
	rm -rf `find $(distdir)/ -type d -name .svn`
	rm -rf `find $(distdir)/ -type d -name .deps`
	rm -rf `find $(distdir)/ -type d -name .libs`

bindist: $(bin_PROGRAMS)
	rm -rf wsclient-bin-${PACKAGE_VERSION}-linux
	sh bindist.sh
	mkdir wsclient-bin-${PACKAGE_VERSION}-linux
	cp -r ${AXIS2C_HOME}/* wsclient-bin-${PACKAGE_VERSION}-linux
	tar -cf - wsclient-bin-${PACKAGE_VERSION}-linux | gzip -c > wsclient-bin-${PACKAGE_VERSION}-linux.tar.gz
	rm -rf wsclient-bin-${PACKAGE_VERSION}-linux
