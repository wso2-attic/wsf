prglibdir=$(prefix)/services/math
samplesdir=$(prefix)/samples/server/math
prglib_LTLIBRARIES = libmath.la
samples_DATA=services.xml  math.h math.c math_skeleton.c Makefile.am Makefile.in
prglib_DATA=services.xml 
EXTRA_DIST = services.xml math.mk
noinst_HEADERS = math.h
SUBDIRS =
libmath_la_SOURCES = math.c math_skeleton.c
libmath_la_LIBADD  =
INCLUDES = -I$(AXIS2C_HOME)/include/axis2-1.0 \
			@UTILINC@ \
			@AXIOMINC@
