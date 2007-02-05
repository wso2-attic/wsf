prglibdir=$(prefix)/modules/sandesha2
prglib_LTLIBRARIES = libsandesha2_client.la

libsandesha2_client_la_SOURCES = \
							sequence_report.c \
							report.c \
							client.c

INCLUDES = -I$(top_builddir)/include \
			-I$(top_builddir)/include/sandesha2 \
            -I ../../../axis2/util/include \
            -I ../../../axis2/include \
            -I ../../../axis2/axiom/include \
            -I ../../../axis2/xml_schema/include \
            -I ../../../axis2/woden/include
