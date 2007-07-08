prgbindir=$(prefix)/bin/samples/sandesha2
prgbin_PROGRAMS = rm_mtom_1_0
samplesdir=$(prefix)/samples/client/rm_mtom_1_0
samples_DATA=rm_mtom_1_0.c Makefile.am Makefile.in
rm_mtom_1_0_SOURCES = rm_mtom_1_0.c mtom_util.c

rm_mtom_1_0_LDADD   =  \
			../../src/core/libsandesha2.la \
					-laxutil \
                    -laxis2_axiom \
                    -laxis2_engine \
                    -laxis2_parser \
                    -lpthread \
                    -laxis2_http_sender \
                    -laxis2_http_receiver \
                    -lsandesha2_client \
                    $(GUTHTHILA_LIBS) \
                    $(LIBXML2_LIBS)

INCLUDES = @AXIS2INC@ \
			-I../../include 

EXTRA_DIST=mtom_util.h
