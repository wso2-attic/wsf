SUBDIRS = data 
prgbindir=$(prefix)/bin/samples/rampart/client/sec_echo
prgbin_PROGRAMS = echo 
datadir=$(prefix)/bin/samples/rampart/client/sec_echo
data_DATA= README.txt update_n_run.sh deploy_client_repo.sh
#samplesdir=$(prefix)/samples/client/echo
#samples_DATA=echo.c README.txt Makefile.am Makefile.in
echo_SOURCES = echo.c

echo_LDADD   = $(LDFLAGS) \
                    -L$(prefix)/lib \
                    $(prefix)/lib/libaxutil.la \
                    $(prefix)/lib/libaxis2_axiom.la \
                    $(prefix)/lib/libaxis2_engine.la \
                    $(prefix)/lib/libaxis2_parser.la \
                    $(prefix)/lib/libaxis2_http_sender.la \
                    $(prefix)/lib/libaxis2_http_receiver.la \
                    -lpthread \
                    $(GUTHTHILA_LIBS) \
                    $(LIBXML2_LIBS)

INCLUDES = -I$(AXIS2C_HOME)/include/axis2-1.1 \
            -I ../../../include \
			@UTILINC@ \
			@AXIOMINC@

EXTRA_DIST = README.txt
