lib_LTLIBRARIES = libaxis2_xmpp_receiver.la
libaxis2_xmpp_receiver_la_LIBADD=	$(top_builddir)/util/src/libaxis2_util.la


libaxis2_xmpp_receiver_la_SOURCES = xmpp_svr_thread.c\
                                    xmpp_server.c

INCLUDES = -I$(top_builddir)/include \
	       -I$(top_builddir)/modules/wsdl\
	       -I$(top_builddir)/modules/core/transport\
	       -I$(top_builddir)/modules/core/transport/xmpp \
           -I$(top_builddir)/modules/core/description \
           -I$(top_builddir)/modules/core/context \
           -I$(top_builddir)/modules/core/phaseresolver \
           -I$(top_builddir)/modules/core/engine \
           -I$(top_builddir)/modules/core/deployment \
           -I$(top_builddir)/xml_schema/include \
           -I$(top_builddir)/util/include \
           -I$(top_builddir)/axiom/include
