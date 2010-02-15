prglibdir=$(prefix)/modules/bam_publisher
prglib_LTLIBRARIES = libbam_publisher.la
prglib_DATA= module.xml

libbam_publisher_la_SOURCES = svc_stat_handler.c \
								 op_stat_handler.c \
								 mod_bam_publisher.c \
								 util.c \
								 statistics.c 
libbam_publisher_la_LIBADD = ../../util/libservice_admin_util.la \
							 ../../../savanc/src/core/libmod_savan.la \
							 ../../../savanc/src/publishers/default/libsavan_publisher.la

INCLUDES = -I$(top_builddir)/include \
			-I. \
			-I./codegen \
			@AXIS2INC@ \
		   	@AXIOMINC@ \
		   	@SAVANINC@ \
		   	@NEETHIINC@ \
		   	@UTILINC@

EXTRA_DIST=module.xml
