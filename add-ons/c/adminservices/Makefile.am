logsdir=$(prefix)/logs
confdir=$(prefix)
includedir=$(prefix)/include
datadir=$(prefix)/share/wso2-wsf-admin
SUBDIRS = util authentication keystore_admin logging_admin module_admin server_admin service_admin service_group_admin statistics_admin transport_admin usermanager operation_admin security_admin_service
noinst_HEADERS=$(top_builddir)/include/*.h
data_DATA= README INSTALL CREDITS COPYING NEWS
logs_DATA=
EXTRA_DIST = build.sh autogen.sh CREDITS LICENSE README build.sh adminservices.mk docs carbon setup.sh setup.bat deploy.js deploy.sh clean.bat build.bat configure.in_win32
dist-hook:
	rm -rf `find $(distdir)/ -type d -name .svn`
	rm -rf `find $(distdir)/ -type d -name .deps`
	rm -rf `find $(distdir)/ -type d -name .libs`
bindist: $(bin_PROGRAMS)
	rm -rf adminservices-bin-${PACKAGE_VERSION}-linux
	sh bindist.sh
	mkdir adminservices-bin-${PACKAGE_VERSION}-linux
	cp -r ${AXIS2C_HOME}/* adminservices-bin-${PACKAGE_VERSION}-linux
	tar -cf - adminservices-bin-${PACKAGE_VERSION}-linux | gzip -c > adminservices-bin-${PACKAGE_VERSION}-linux.tar.gz
	rm -rf adminservices-bin-${PACKAGE_VERSION}-linux
