lib_LTLIBRARIES = libmod_axis2.la
libmod_axis2_la_SOURCES = mod_axis2.c\
                       apache2_stream.c\
                       apache2_out_transport_info.c\
                       apache2_worker.c

AM_CFLAGS = -DLINUX=2 -D_REENTRANT -D_XOPEN_SOURCE=500 -D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE

libmod_axis2_la_LIBADD   = $(LDFLAGS) \
		     $(top_builddir)/axiom/src/om/libaxis2_axiom.la \
		     $(top_builddir)/src/core/engine/libaxis2_engine.la\
		     $(top_builddir)/util/src/libaxutil.la \
		     $(top_builddir)/src/core/transport/http/util/libaxis2_http_util.la\
		     $(top_builddir)/src/core/transport/http/common/libaxis2_http_common.la\
		     $(top_builddir)/axiom/src/parser/$(WRAPPER_DIR)/libaxis2_parser.la\
                    -lpthread \
                    -L$(top_builddir)$(GUTHTHILA_LIBS) \
					$(PARSER_LIBS) \
					$(LIBXML2_LIBS)

libmod_axis2_la_LDFLAGS = -version-info $(VERSION_NO)

INCLUDES = -I$(top_builddir)/include \
	       -I$(top_builddir)/src/core/transport/http \
           -I$(top_builddir)/src/core/description \
           -I$(top_builddir)/src/core/context \
           -I$(top_builddir)/src/core/phaseresolver \
           -I$(top_builddir)/src/core/engine \
           -I$(top_builddir)/src/core/deployment \
           -I$(top_builddir)/axiom/include\
           -I$(top_builddir)/util/include\
            @APACHE2INC@ \
            @APRINC@

EXTRA_DIST=axis2_apache2_worker.h apache2_stream.h axis2_apache2_out_transport_info.h








