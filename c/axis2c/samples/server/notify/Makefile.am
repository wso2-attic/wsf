prglibdir=$(prefix)/services/notify
samplesdir=$(prefix)/samples/server/notify
prglib_LTLIBRARIES = libnotify.la
samples_DATA=notify.c notify_skeleton.c notify.h services.xml Makefile.am Makefile.in
prglib_DATA= services.xml
EXTRA_DIST = services.xml notify.mk
noinst_HEADERS = notify.h
SUBDIRS =
libnotify_la_SOURCES = notify.c notify_skeleton.c
libnotify_la_LIBADD  =
INCLUDES = -I$(AXIS2C_HOME)/include/axis2-1.0 \
			@UTILINC@ \
			@AXIOMINC@
