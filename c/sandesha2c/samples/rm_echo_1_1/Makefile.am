prgbindir=$(prefix)/bin/samples/sandesha2
prgbin_PROGRAMS = rm_echo_1_1
samplesdir=$(prefix)/samples/client/rm_echo_1_1
samples_DATA=rm_echo_1_1.c Makefile.am Makefile.in
rm_echo_1_1_SOURCES = rm_echo_1_1.c echo_util.c

rm_echo_1_1_LDADD   =  \
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

INCLUDES =	-I../../include \
		@AXIS2INC@

EXTRA_DIST=echo_util.h
