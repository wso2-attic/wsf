prglibdir=$(prefix)/modules/addressing
prglib_LTLIBRARIES = libaxis2_mod_addr.la
prglib_DATA= module.xml
EXTRA_DIST = module.xml
libaxis2_mod_addr_la_SOURCES = addr_in_handler.c \
                                addr_out_handler.c \
                                mod_addr.c

libaxis2_mod_addr_la_LIBADD =	$(top_builddir)/src/core/engine/libaxis2_engine.la \
							$(top_builddir)/axiom/src/om/libaxis2_axiom.la \
							$(top_builddir)/util/src/libaxutil.la 

lib_LTLIBRARIES = libaxis2.la
libaxis2_la_SOURCES = addr_in_handler.c \
                                addr_out_handler.c \
                                mod_addr.c

libaxis2_la_LIBADD =	$(top_builddir)/src/core/engine/libaxis2_engine.la \
			$(top_builddir)/axiom/src/om/libaxis2_axiom.la \
			$(top_builddir)/src/core/transport/http/util/libaxis2_http_util.la \
			$(top_builddir)/src/core/transport/http/common/libaxis2_http_common.la \
			$(top_builddir)/axiom/src/parser/${WRAPPER_DIR}/libaxis2_parser.la



INCLUDES = -I$(top_builddir)/include \
            -I$(top_builddir)/src/core/description \
            -I$(top_builddir)/src/core/context \
            -I$(top_builddir)/src/core/phaseresolver \
            -I$(top_builddir)/src/core/engine \
            -I$(top_builddir)/src/core/deployment \
            -I$(top_builddir)/util/include \
            -I$(top_builddir)/axiom/include
