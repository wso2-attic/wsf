TESTS = test_oxs
noinst_PROGRAMS = test_oxs

#AM_CFLAGS = -g -O2 -pthread

test_oxs_SOURCES =  test.c

INCLUDES = -I$(top_builddir)/include \
		    -I ../../include \
		    -I ../../../axis2c/include \
		    -I ../../../axis2c/axiom/include \
		    -I ../../../axis2c/util/include \
		    @AXIS2INC@

test_oxs_LDADD   = $(top_builddir)/src/util/librampart_util.la \
                    $(top_builddir)/src/omxmlsec/libomxmlsec.la \
                    $(top_builddir)/src/omxmlsec/openssl/libomopenssl.la \
                    $(top_builddir)/src/omxmlsec/tokens/liboxstokens.la \
		    ../../../axis2c/util/src/libaxutil.la \
		    ../../../axis2c/axiom/src/om/libaxis2_axiom.la \
		    ../../../axis2c/axiom/src/parser/libxml2/libaxis2_parser.la \
           -lxml2
