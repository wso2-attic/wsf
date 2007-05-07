TESTS =
prglibdir=$(prefix)/modules/rampart
prglib_LTLIBRARIES = libmod_rampart.la
prglib_DATA= ../data/module.xml

libmod_rampart_la_SOURCES = mod_rampart.c

libmod_rampart_la_LIBADD  = ../handlers/librampart_handlers.la \
			    ../util/librampart_util.la \
			    ../omxmlsec/libomxmlsec.la \
				../secpolicy/model/librp_model.la \
				../secpolicy/builder/librp_builder.la \
				${AXIS2C_HOME}/lib

INCLUDES = -I$(top_builddir)/include \
			-I ../../include \
			-I ../../../axis2c/include \
			-I ../../../axis2c/axiom/include \
			-I ../../../axis2c/util/include \
			@AXIS2INC@
