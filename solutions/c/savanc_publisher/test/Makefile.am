prgbindir=$(prefix)/bin/test
prgbin_PROGRAMS = test 
test_SOURCES = test.c

test_LDADD = -lcurl -L$(top_builddir)/src/ -lraptor $(top_builddir)/src/libreg_client.la \
					-laxutil \
                    -laxis2_axiom \
                    -laxis2_engine \
                    -laxis2_parser \
                    -lpthread \
                    -laxis2_http_sender \
                    -laxis2_http_receiver \
                    $(GUTHTHILA_LIBS)

INCLUDES = -I$(top_builddir)/ @AXIS2INC@

EXTRA_DIST=test.mk
