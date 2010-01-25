noinst_LTLIBRARIES = libstatistics_admin.la

libstatistics_admin_la_SOURCES = response_time_processor.c \
								 fault_count_handler.c \
								 in_op_count_handler.c \
								 out_op_count_handler.c \
								 svc_request_count_handler.c \
								 mod_statistics_admin.c
libstatistics_admin_la_LIBADD = 

INCLUDES = -I$(top_builddir)/include \
			-I. \
			@AXIS2INC@ \
		   	@AXIOMINC@ \
		   	@NEETHIINC@ \
		   	@UTILINC@

EXTRA_DIST=
