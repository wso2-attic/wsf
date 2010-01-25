prgbindir=$(prefix)/bin/test/
CFLAGS = -g -O0
prgbin_PROGRAMS = tests
tests_SOURCES = main.c rest_test.c feed_test.c reg_test.c subscriber.c get_test.c

tests_LDADD   = $(LDFLAGS) \
				-L$(LIBCURL_LIBS) \
                -L$(AXIS2C_HOME)/lib \
                -laxutil \
                -laxis2_axiom \
				-L../src/.libs \
				-lregistry_client \
				-lcurl \
                $(GUTHTHILA_LIBS)

INCLUDES = @AXIS2INC@ \
		-I$(top_builddir)/include
