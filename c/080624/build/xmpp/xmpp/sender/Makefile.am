lib_LTLIBRARIES = libaxis2_xmpp_sender.la
libaxis2_xmpp_sender_la_SOURCES = xmpp_transport_sender.c \
                                  xmpp_client.c

libaxis2_xmpp_sender_la_LIBADD = ../../../engine/libaxis2_engine.la \
				../../../../../axiom/src/om/libaxis2_axiom.la \
				../../../../../util/src/libaxutil.la \
                @IKSEMELLIB@ \
				../libaxis2_xmpp.la

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

EXTRA_DIST=axis2_xmpp_client.h
