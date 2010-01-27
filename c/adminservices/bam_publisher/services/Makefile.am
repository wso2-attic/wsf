prglibdir=$(prefix)/services/statistics_svc
samplesdir=$(prefix)/samples/server/statistics_svc
prglib_LTLIBRARIES = libstatistics_svc.la
prglib_DATA= services.xml
noinst_HEADERS = statistics_svc.h
SUBDIRS =

libstatistics_svc_la_SOURCES = statistics_svc.c statistics_svc_skeleton.c

libstatistics_svc_la_LIBADD  = -L$(AXIS2C_HOME)/lib -lsavan_client

INCLUDES =  @AXIS2INC@ @SAVANINC@

EXTRA_DIST=services.xml statistics_svc.h
