TESTS =

lib_LTLIBRARIES = libneethi_util.la

libneethi_util_la_SOURCES = options.c

libneethi_util_la_LIBADD  = ../../../axiom/src/om/libaxis2_axiom.la \
				../../../util/src/libaxutil.la

INCLUDES = -I$(top_builddir)/include \
			-I ../../../include \
			-I ../../../util/include \
            -I ../../../axiom/include 


EXTRA_DIST=neethi_options.h
