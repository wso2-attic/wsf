prgbindir=$(prefix)/samples/bin/wsf_c/
#samplesdir=$(prefix)/samples/client/flickr
prgbin_PROGRAMS = flickr
#samples_DATA=flickr_client.c Makefile.am README.txt Makefile.in
flickr_SOURCES = flickr_client.c

flickr_LDADD   =    $(LDFLAGS) \
                    -L$(WSFC_HOME)/lib \
					-laxutil \
                    -laxis2_axiom \
                    -laxis2_engine \
                    -laxis2_parser \
                    -laxis2_http_sender \
                    -laxis2_http_receiver \
                    $(GUTHTHILA_LIBS) \
                    $(LIBXML2_LIBS)

INCLUDES = @AXIS2INC@

EXTRA_DIST=README.txt flickr.mk
