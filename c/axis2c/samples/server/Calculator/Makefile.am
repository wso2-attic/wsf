prglibdir=$(prefix)/services/Calculator
samplesdir=$(prefix)/samples/server/Calculator
prglib_LTLIBRARIES = libCalculator.la
samples_DATA=services.xml calc.h calc.c calc_skeleton.c Makefile.am Makefile.in
prglib_DATA=services.xml
EXTRA_DIST = services.xml Calculator.mk
noinst_HEADERS = calc.h
SUBDIRS =
libCalculator_la_SOURCES = calc.c calc_skeleton.c
libCalculator_la_LIBADD  =
INCLUDES = -I$(AXIS2C_HOME)/include/axis2-1.0 \
			@UTILINC@ \
			@AXIOMINC@
