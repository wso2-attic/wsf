NSUBDIRS = 
noinst_LTLIBRARIES = libaxis2_http_util.la

libaxis2_http_util_la_SOURCES = http_transport_utils.c\
		           http_chunked_stream.c

libaxis2_http_util_la_LIBADD=$(top_builddir)/util/src/libaxutil.la \
			$(top_builddir)/axiom/src/parser/${WRAPPER_DIR}/libaxis2_parser.la\
			$(top_builddir)/axiom/src/om/libaxis2_axiom.la 


INCLUDES = -I$(top_builddir)/include \
            -I$(top_builddir)/src/core/engine \
            -I$(top_builddir)/util/include \
            -I$(top_builddir)/axiom/include
