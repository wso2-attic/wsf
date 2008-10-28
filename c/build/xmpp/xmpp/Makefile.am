SUBDIRS = . sender receiver server
noinst_LTLIBRARIES = libaxis2_xmpp.la

libaxis2_xmpp_la_SOURCES = xmpp_worker.c \
                           xmpp_session.c \
                           xmpp_transport_utils.c

INCLUDES = -I$(top_builddir)/include \
            -I$(top_builddir)/src/wsdl \
            -I$(top_builddir)/src/core/engine \
            -I$(top_builddir)/xml_schema/include \
            -I$(top_builddir)/util/include \
            -I$(top_builddir)/axiom/include \
	    	@IKSEMELINC@

EXTRA_DIST=axis2_xmpp_server.h axis2_xmpp_transport.h axis2_xmpp_transport_utils.h axis2_xmpp_svr_thread.h axis2_xmpp_transport_sender.h axis2_xmpp_worker.h axis2_xmpp_session.h 

