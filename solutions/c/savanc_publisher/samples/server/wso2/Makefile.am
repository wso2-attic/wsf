prglibdir=$(prefix)/services/wso2
samplesdir=$(prefix)/samples/server/wso2
prglib_LTLIBRARIES = libwso2.la
prglib_DATA= services.xml
noinst_HEADERS = wso2.h
SUBDIRS =

libwso2_la_SOURCES = wso2.c wso2_skel.c

libwso2_la_LIBADD  = -L$(AXIS2C_HOME)/lib -lsavan_client -L$(AXIS2C_HOME)/lib -lreg_client

INCLUDES =  -I@AXIS2INC@ \
		    	@AXIS2INC@ \
				@SAVANINC@

EXTRA_DIST=services.xml
