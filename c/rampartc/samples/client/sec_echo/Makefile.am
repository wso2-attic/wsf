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
		    $(prefix)/lib/libaxis2_axiom.la \
		    $(prefix)/lib/libaxutil.la \
		    $(prefix)/lib/libaxis2_engine.la \
		    $(prefix)/lib/libaxis2_parser.la \
                    -lpthread \
                    $(GUTHTHILA_LIBS) \
                    $(LIBXML2_LIBS)

INCLUDES = -I$(prefix)/include/axis2-1.0 \
            -I ../../../include \
            -I ../../../../axis2c/include \
            -I ../../../../axis2c/util/include \
            -I ../../../../axis2c/axiom/include \
			@UTILINC@ \
			@AXIOMINC@

EXTRA_DIST = README.txt
