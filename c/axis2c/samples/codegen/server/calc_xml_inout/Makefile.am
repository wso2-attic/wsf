prglibdir=$(prefix)/services/Calculator
samplesdir=$(prefix)/samples/server/Calculator
prglib_LTLIBRARIES = libCalculator.la
prglib_DATA= services.xml
EXTRA_DIST = services.xml
SUBDIRS =
libCalculator_la_SOURCES =  \
	axis2_Calculator.c \
	axis2_Calculator_svc_skeleton.c

libCalculator_la_LIBADD  =
INCLUDES = -I$(AXIS2C_HOME)/include \
			@UTILINC@ \
			@AXIOMINC@
