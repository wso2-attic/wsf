TESTS = test_round2
noinst_PROGRAMS = test_round2

#AM_CFLAGS = -g -O2 -pthread

test_round2_SOURCES =  test.c

INCLUDES = -I$(top_builddir)/include \
		    -I ../../include \
		    @AXIS2INC@

test_round2_LDADD   = $(top_builddir)/src/util/libneethi.la \
		    ${AXIS2C_HOME}/lib/libaxutil.la \
		    ${AXIS2C_HOME}/lib/libaxis2_axiom.la \
		    ${AXIS2C_HOME}/lib/libaxis2_parser.la \
           -lxml2
