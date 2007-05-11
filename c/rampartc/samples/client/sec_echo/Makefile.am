SUBDIRS = data 
prgbindir=$(prefix)/bin/samples/rampart/client/sec_echo
prgbin_PROGRAMS = echo 
datadir=$(prefix)/bin/samples/rampart/client/sec_echo
data_DATA= README.txt update_n_run.sh deploy_client_repo.sh
#samplesdir=$(prefix)/samples/client/echo
#samples_DATA=echo.c README.txt Makefile.am Makefile.in
echo_SOURCES = echo.c

echo_LDADD   = $(LDFLAGS) \
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
            -I ../../../include \
			@UTILINC@ \
			@AXIOMINC@

EXTRA_DIST = README.txt
