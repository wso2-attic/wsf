prglibdir=$(prefix)/modules/sandesha2
prglib_LTLIBRARIES = libsandesha2_client.la

libsandesha2_client_la_SOURCES = \
							sequence_report.c \
							report.c \
							client.c

INCLUDES = -I$(top_builddir)/include \
		-I ../../../axis2c/util/include \
		-I ../../../axis2c/axiom/include \
		-I ../../../axis2c/include \
		   	@AXIS2INC@

