prgbindir=$(prefix)/bin/samples
samplesdir=$(prefix)/samples/client/google
prgbin_PROGRAMS = google
samples_DATA=google_client.c Makefile.am README.txt Makefile.in
google_SOURCES = google_client.c

google_LDADD   =    $(LDFLAGS) \
                    -L$(AXIS2C_HOME)/lib \
					-laxutil \
                    -laxis2_axiom \
                    -laxis2_engine \
                    -laxis2_parser \
                    -laxis2_http_sender \
                    -laxis2_http_receiver \
                    $(GUTHTHILA_LIBS) \
                    $(LIBXML2_LIBS)

INCLUDES = -I$(AXIS2C_HOME)/include/axis2-1.0 \
			@UTILINC@ \
			@AXIOMINC@

EXTRA_DIST=README.txt google.mk
