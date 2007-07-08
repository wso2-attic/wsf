prglibdir=$(prefix)/services/Calculator
samplesdir=$(prefix)/samples/server/Calculator
prglib_LTLIBRARIES = libCalculator.la
prglib_DATA= services.xml
EXTRA_DIST = services.xml
SUBDIRS =
libCalculator_la_SOURCES =  \
axis2_add.c            axis2_Calculator.c               axis2_divResponse16.c  axis2_mulResponse14.c  axis2_subResponse12.c \
axis2_addRequest.c     axis2_Calculator_svc_skeleton.c  axis2_divResponse.c    axis2_mulResponse.c    axis2_subResponse.c \
axis2_addResponse20.c  axis2_div.c                      axis2_mul.c            axis2_sub.c \
axis2_addResponse.c    axis2_divRequest.c               axis2_mulRequest.c     axis2_subRequest.c 
libCalculator_la_LIBADD  =
INCLUDES = -I$(AXIS2C_HOME)/include \
			@UTILINC@ \
			@AXIOMINC@
