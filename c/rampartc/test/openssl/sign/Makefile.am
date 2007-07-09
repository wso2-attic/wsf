TESTS = test 
noinst_PROGRAMS = test
SUBDIRS =

AM_CFLAGS = -g  -pthread

#test_SOURCES = des_test.c
test_SOURCES = test.c


INCLUDES = -I$(top_builddir)/include \
            -I ../../../include \
	    @OPENSSLINC@ \
	    @UTILINC@ \
	    @AXIOMINC@ \
	    @AXIS2INC@

test_LDADD   = $(top_builddir)/src/util/librampart_util.la \
                    $(top_builddir)/src/omxmlsec/libomxmlsec.la \
                    $(top_builddir)/src/omxmlsec/openssl/libomopenssl.la \
                    $(top_builddir)/src/omxmlsec/tokens/liboxstokens.la \
		    ${AXIS2C_HOME}/lib/libaxis2_parser.la \
		    ${AXIS2C_HOME}/lib/libaxis2_axiom.la \
		    ${AXIS2C_HOME}/lib/libaxutil.la \
		    @OPENSSLLIB@\
		    -lxml2 \
		    -lssl

