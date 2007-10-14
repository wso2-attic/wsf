lib_LTLIBRARIES = libaxis2_xmpp_receiver.la
libaxis2_xmpp_receiver_la_LIBADD=	../../../../../util/src/libaxutil.la


libaxis2_xmpp_receiver_la_SOURCES = xmpp_svr_thread.c\
                                    xmpp_server.c

INCLUDES = -I$(top_builddir)/include \
	       -I$(top_builddir)/src/wsdl\
	       -I$(top_builddir)/src/core/transport\
	       -I$(top_builddir)/src/core/transport/xmpp \
           -I$(top_builddir)/src/core/description \
           -I$(top_builddir)/src/core/context \
           -I$(top_builddir)/src/core/phaseresolver \
           -I$(top_builddir)/src/core/engine \
           -I$(top_builddir)/src/core/deployment \
           -I$(top_builddir)/xml_schema/include \
           -I$(top_builddir)/util/include \
           -I$(top_builddir)/axiom/include \
	   		@IKSEMELINC@
