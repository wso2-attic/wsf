noinst_LTLIBRARIES = libaxis2_attachments.la
AM_CPPFLAGS = $(CPPFLAGS)
libaxis2_attachments_la_SOURCES = mime_output.c \
					data_handler.c \
					mime_body_part.c \
                    mime_parser.c

libaxis2_attachments_la_LIBADD = ../../../util/src/libaxutil.la 

INCLUDES =	-I$(top_builddir)/include \
            -I$(top_builddir)/parser \
			-I ../../../util/include

EXTRA_DIST = axiom_mime_body_part.h axiom_mime_output.h

