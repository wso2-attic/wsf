prglibdir=$(prefix)/modules/statistics
prglib_LTLIBRARIES = libstatistics.la
prglib_DATA= module.xml

libstatistics_la_SOURCES = response_time_handler.c \
								 fault_count_handler.c \
								 in_op_count_handler.c \
								 out_op_count_handler.c \
								 svc_request_count_handler.c \
								 global_request_count_handler.c \
								 mod_statistics_admin.c
libstatistics_la_LIBADD = ../../util/libservice_admin_util.la

INCLUDES = -I$(top_builddir)/include \
			-I. \
			@AXIS2INC@ \
		   	@AXIOMINC@ \
		   	@NEETHIINC@ \
		   	@UTILINC@

EXTRA_DIST=module.xml mod_statistics_admin.h
