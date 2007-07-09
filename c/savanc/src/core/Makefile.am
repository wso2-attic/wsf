prglibdir=$(prefix)/modules/savan
prglib_LTLIBRARIES = libmod_savan.la
prglib_DATA= ../data/module.xml

libmod_savan_la_SOURCES = mod_savan.c savan_sub_processor.c

INCLUDES = -I$(top_builddir)/include \
		@AXIOMINC@ \
		@UTILINC@ \
		@AXIS2INC@ 

libmod_savan_la_LIBADD = ../client/libsavan_client.la\
                        ../handlers/libsavan_handlers.la\
                        ../msgreceivers/libsavan_msgreceivers.la\
						../subscribers/libsavan_subscribers.la\
						../util/libsavan_util.la
