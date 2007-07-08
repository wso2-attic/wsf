prglibdir=$(prefix)/lib
prglib_LTLIBRARIES = libsavan_client.la

libsavan_client_la_SOURCES = savan_client.c savan_publishing_client.c
libsavan_client_la_LIBADD = ../subscribers/libsavan_subscribers.la \
							../util/libsavan_util.la

INCLUDES = -I$(top_builddir)/include \
		@AXIS2INC@ \
		@UTILINC@ \
		@AXIOMINC@ \
		@NEETHIINC@ 
