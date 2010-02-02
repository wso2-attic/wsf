prglibdir=$(prefix)/services/BAMServiceStatisticsSubscriberService
prglib_LTLIBRARIES = libBAMServiceStatisticsSubscriberService.la
prglib_DATA= services.xml
noinst_HEADERS = statistics_svc.h
SUBDIRS =

libBAMServiceStatisticsSubscriberService_la_SOURCES = statistics_svc.c statistics_svc_skeleton.c

libBAMServiceStatisticsSubscriberService_la_LIBADD  = ../../util/libservice_admin_util.la

INCLUDES = -I$(top_builddir)/include \
			-I. \
			@AXIS2INC@ \
			@SAVANINC@ \
		   	@AXIOMINC@ \
		   	@NEETHIINC@ \
		   	@UTILINC@

EXTRA_DIST=services.xml statistics_svc.h
