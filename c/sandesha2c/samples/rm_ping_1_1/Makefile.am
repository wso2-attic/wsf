prgbindir=$(prefix)/bin/samples/sandesha2
prgbin_PROGRAMS = rm_ping_1_1
samplesdir=$(prefix)/samples/client/rm_ping_1_1
samples_DATA=rm_ping_1_1.c Makefile.am Makefile.in
rm_ping_1_1_SOURCES = rm_ping_1_1.c

rm_ping_1_1_LDADD   =  \
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
