TESTS =
headerdir=$(prefix)/include/wsfc-2.0.0
lib_LTLIBRARIES = libneethi_util.la

libneethi_util_la_SOURCES = options.c

libneethi_util_la_LIBADD  = ../../../axiom/src/om/libaxis2_axiom.la \
				../../../util/src/libaxutil.la

INCLUDES = -I$(top_builddir)/include \
			-I ../../../include \
			-I ../../../util/include \
            -I ../../../axiom/include 

header_DATA=neethi_options.h
EXTRA_DIST=neethi_options.h neethi_util.mk
