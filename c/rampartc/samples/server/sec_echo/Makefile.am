prglibdir=$(prefix)/services/sec_echo
samplesdir=$(prefix)/samples/server/sec_echo
prglib_LTLIBRARIES = libsec_echo.la
samples_DATA=echo.c echo_skeleton.c echo.h services.xml Makefile.am Makefile.in
prglib_DATA= services.xml
EXTRA_DIST = services.xml
noinst_HEADERS = echo.h
SUBDIRS =
libsec_echo_la_SOURCES = echo.c echo_skeleton.c
libsec_echo_la_LIBADD  =
INCLUDES = -I$(AXIS2C_HOME)/include/axis2-1.0 \
			@UTILINC@ \
			@AXIOMINC@
