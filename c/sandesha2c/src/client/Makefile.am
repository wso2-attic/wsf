prglibdir=$(prefix)/lib
prglib_LTLIBRARIES = libsandesha2_client.la

libsandesha2_client_la_SOURCES = \
							sequence_report.c \
							report.c \
							client.c

libsandesha2_client_la_LIBADD = ../core/libsandesha2.la

INCLUDES = -I$(top_builddir)/include \
		   	@AXIS2INC@

