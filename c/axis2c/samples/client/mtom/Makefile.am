SUBDIRS=resources
prgbindir=$(prefix)/bin/samples
prgbin_PROGRAMS = mtom
samplesdir=$(prefix)/samples/client/mtom
samples_DATA=mtom_client.c Makefile.am Makefile.in

mtom_SOURCES = mtom_client.c

mtom_LDADD   = $(LDFLAGS) \
                    -L$(AXIS2C_HOME)/lib \
					-laxutil \
                    -laxis2_axiom \
                    -laxis2_engine \
                    -laxis2_parser \
                    -lpthread \
                    -laxis2_http_sender \
                    -laxis2_http_receiver \
                    $(GUTHTHILA_LIBS) \
                    $(LIBXML2_LIBS)

INCLUDES = -I$(AXIS2C_HOME)/include/axis2-1.0 \
			@UTILINC@ \
			@AXIOMINC@

EXTRA_DIST=mtom.mk
