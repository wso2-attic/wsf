prglibdir=$(prefix)/services/echo
samplesdir=$(prefix)/samples/server/echo
prglib_LTLIBRARIES = libecho.la
samples_DATA=echo.c echo_skeleton.c echo.h services.xml Makefile.am Makefile.in
prglib_DATA= services.xml
EXTRA_DIST = services.xml echo.mk
noinst_HEADERS = echo.h
SUBDIRS =
libecho_la_SOURCES = echo.c echo_skeleton.c
libecho_la_LIBADD  =
INCLUDES = -I$(AXIS2C_HOME)/include/axis2-1.0 \
			@UTILINC@ \
			@AXIOMINC@
