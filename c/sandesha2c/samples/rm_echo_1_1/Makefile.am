prgbindir=$(prefix)/bin/samples
prgbin_PROGRAMS = rm_echo_1_1
samplesdir=$(prefix)/samples/client/rm_echo_1_1
samples_DATA=rm_echo_1_1.c Makefile.am Makefile.in
rm_echo_1_1_SOURCES = rm_echo_1_1.c echo_util.c

rm_echo_1_1_LDADD   =  \
                    -L$(prefix)/lib \
                    -L$(prefix)/modules/sandesha2/libsandesha2.la \
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

INCLUDES = -I$(prefix)/include/axis2-1.0 \
			-I../../include \
			@UTILINC@ \
			@AXIOMINC@
