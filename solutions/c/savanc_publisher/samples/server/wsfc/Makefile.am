prglibdir=$(prefix)/services/wsfc
samplesdir=$(prefix)/samples/server/wsfc
prglib_LTLIBRARIES = libwsfc.la
prglib_DATA= services.xml
noinst_HEADERS = wsfc.h
SUBDIRS =
libwsfc_la_SOURCES = wsfc.c wsfc_skel.c
libwsfc_la_LIBADD  =
INCLUDES =  -I@AXIS2INC@ \
		@AXIS2INC@ \
		@SAVANINC@

EXTRA_DIST=services.xml
