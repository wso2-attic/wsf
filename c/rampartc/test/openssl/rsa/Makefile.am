TESTS = test 
noinst_PROGRAMS = test
SUBDIRS =

AM_CFLAGS = -g -O2 -pthread

#test_SOURCES = des_test.c
test_SOURCES = test_rsa.c

INCLUDES = -I$(top_builddir)/include \
			@UTILINC@ \
            @AXIOMINC@\
	    @OPENSSLINC@

test_LDADD   = $(top_builddir)/src/util/librampart_util.la \
                    $(top_builddir)/src/omxmlsec/libomxmlsec.la \
                    $(top_builddir)/src/omxmlsec/openssl/libomopenssl.la \
		   -laxis2_util \
		   -laxis2_axiom \
		   @OPENSSLLIB@\
            -laxis2_libxml2 \
            -lxml2
