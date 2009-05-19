prgbindir=$(prefix)/bin/
prgbin_PROGRAMS = axis2_xmpp_server
SUBDIRS =
AM_CFLAGS = -g -pthread
axis2_xmpp_server_SOURCES = xmpp_server_main.c

axis2_xmpp_server_LDADD   =  $(LDFLAGS) \
                             $(top_builddir)/src/core/transport/http/util/libaxis2_http_util.la \
                             $(top_builddir)/src/core/transport/http/common/libaxis2_http_common.la \
                            -L$(top_builddir)/src/core/transport/xmpp/sender \
                            -L$(top_builddir)/src/core/transport/xmpp/receiver \
			      $(top_builddir)/axiom/src/om/libaxis2_axiom.la \
			      $(top_builddir)/util/src/libaxutil.la \
			      $(top_builddir)/neethi/src/libneethi.la \
			    ../../../../../../axiom/src/parser/$(WRAPPER_DIR)/libaxis2_parser.la \
			      $(top_builddir)/src/core/engine/libaxis2_engine.la \
	                    @IKSEMELLIB@ \
                            -lpthread \
                            -laxis2_xmpp_sender \
                            -laxis2_xmpp_receiver \
			    -L$(top_builddir)$(GUTHTHILA_LIBS) \
                            $(LIBXML2_LIBS)

INCLUDES =  -I$(top_builddir)/include \
            -I$(top_builddir)/src/wsdl\
            -I$(top_builddir)/src/core/description\
            -I$(top_builddir)/src/core/context \
            -I$(top_builddir)/src/core/deployment\
            -I$(top_builddir)/src/core/phaseresolver \
            -I$(top_builddir)/src/core/engine \
            -I$(top_builddir)/util/include \
            -I../../  \
            -I$(top_builddir)/axiom/include \
	    	@IKSEMELINC@
