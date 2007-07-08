prgbindir=$(prefix)/bin/samples
prgbin_PROGRAMS = yahoosearch
yahoosearch_SOURCES = yahoo_client.c

yahoosearch_LDADD   =    $(LDFLAGS) \
                    -L$(AXIS2C_HOME)/lib \
					-laxutil \
                    -laxis2_axiom \
                    -laxis2_engine \
                    -laxis2_parser \
                    -laxis2_http_sender \
                    -laxis2_http_receiver \
                    $(GUTHTHILA_LIBS) \
                    $(LIBXML2_LIBS)

INCLUDES = @AXIS2INC@

EXTRA_DIST=yahoo.mk
