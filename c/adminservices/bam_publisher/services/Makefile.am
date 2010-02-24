prglibdir=$(prefix)/services/BAMServiceStatisticsPublisherService
prglib_LTLIBRARIES = libBAMServiceStatisticsPublisherService.la
prglib_DATA= services.xml
noinst_HEADERS = statistics_svc.h
SUBDIRS =

libBAMServiceStatisticsPublisherService_la_SOURCES = statistics_svc.c statistics_svc_skeleton.c

libBAMServiceStatisticsPublisherService_la_LIBADD  = ../../util/libservice_admin_util.la

INCLUDES = -I$(top_builddir)/include \
			-I. \
			@AXIS2INC@ \
			@SAVANINC@ \
		   	@AXIOMINC@ \
		   	@NEETHIINC@ \
		   	@UTILINC@

EXTRA_DIST=services.xml statistics_svc.h
