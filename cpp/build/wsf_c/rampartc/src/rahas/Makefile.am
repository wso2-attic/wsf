TESTS =

prglibdir=$(prefix)/modules/rahas

prglib_LTLIBRARIES = libmod_rahas.la

prglib_DATA= ../data/rahas_module.xml

libmod_rahas_la_SOURCES = mod_rahas.c rahas_in_handler.c rahas_request_processor.c

libmod_rahas_la_LIBADD  = ../util/librampart_util.la \
			  ../omxmlsec/libomxmlsec.la \
			  ../secconv/libsecconv.la \
				@OPENSSLLIB@ \
				-lcrypto 
				

INCLUDES = -I$(top_builddir)/include \
			-I ../../include \
			@OPENSSLINC@ \
			@AXIS2INC@ \
			@UTILINC@ \
			@NEETHIINC@ \
			@AXIOMINC@

install-data-hook:
	cp $(prefix)/modules/rahas/libmod_rahas* $(prefix)/lib
	mv $(prefix)/modules/rahas/rahas_module.xml $(prefix)/modules/rahas/module.xml
	
