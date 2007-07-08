prglibdir=$(prefix)/services/listener
samplesdir=$(prefix)/samples/server/listener
prglib_LTLIBRARIES = liblistener.la
prglib_DATA= services.xml
noinst_HEADERS = listener.h
SUBDIRS =
liblistener_la_SOURCES = listener.c listener_skeleton.c
liblistener_la_LIBADD  =
INCLUDES = -I$(AXIS2C_HOME)/include \
		@AXIOMINC@ \
		@AXIS2INC@ \
		@UTILINC@ \
		@NEETHIINC@ 

EXTRA_DIST=services.xml
