prgbindir=$(prefix)/bin/samples
samplesdir=$(prefix)/samples/client/flicker
prgbin_PROGRAMS = flicker
samples_DATA=flicker_client.c Makefile.am README.txt Makefile.in
flicker_SOURCES = flicker_client.c

flicker_LDADD   =    $(LDFLAGS) \
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

EXTRA_DIST=README.txt flicker.mk
