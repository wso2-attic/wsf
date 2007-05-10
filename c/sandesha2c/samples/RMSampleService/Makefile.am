prglibdir=$(prefix)/services/RMSampleService
samplesdir=$(prefix)/samples/server/rm/RMSampleService
prglib_LTLIBRARIES = libRMSampleService.la
samples_DATA=rm_sample_svc.c rm_sample_svc_skel.c rm_sample_svc.h services.xml Makefile.am Makefile.in
prglib_DATA= services.xml
EXTRA_DIST = services.xml
noinst_HEADERS = rm_sample_svc.h
libRMSampleService_la_SOURCES = rm_sample_svc.c rm_sample_svc_skel.c
INCLUDES = -I$(prefix)/include/axis2-1.0 \
			@UTILINC@ \
			@AXIOMINC@
