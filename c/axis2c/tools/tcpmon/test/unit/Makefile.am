TESTS =
prgbindir=$(prefix)/bin/unit_test
prgbin_PROGRAMS = tcpmon_unit_test_suite

tcpmon_unit_test_suite_SOURCES = main.c tcpmon_test.c

tcpmon_unit_test_suite_LDADD   =   \
                     $(top_builddir)/src/libaxis2_tcpmon.la \
                     -L$(CUTEST_HOME)/lib \
                     -lcutest \
					 ../../../../util/src/libaxutil.la \
					 ../../../../axiom/src/om/libaxis2_axiom.la \
                     $(NULL)


INCLUDES = -I${CUTEST_HOME}/include \
           -I$(top_builddir)/include \
		   -I ../../../../util/include \
           $(NULL)
