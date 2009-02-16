TESTS =
prglibdir=$(prefix)/modules/rampart
prglib_LTLIBRARIES = libmod_rampart.la
prglib_DATA= ../data/module.xml

libmod_rampart_la_SOURCES = mod_rampart.c

libmod_rampart_la_LIBADD  = ../handlers/librampart_handlers.la \
			    ../util/librampart_util.la \
			    ../omxmlsec/libomxmlsec.la \
			    ../secconv/libsecconv.la \
                            ../../../axis2c/src/core/engine/libaxis2_engine.la \
				@OPENSSLLIB@ \
				-lcrypto 
				

INCLUDES = -I$(top_builddir)/include \
			-I ../../include \
			@OPENSSLINC@ \
			@AXIS2INC@ \
			@UTILINC@ \
			@NEETHIINC@ \
			@AXIOMINC@
