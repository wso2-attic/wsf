prgbindir=$(prefix)/bin/samples
prgbin_PROGRAMS = notify
samplesdir=$(prefix)/samples/client/notify
samples_DATA=notify_client.c Makefile.am Makefile.in
notify_SOURCES = notify_client.c

notify_LDADD   =  \
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

EXTRA_DIST=notify.mk
