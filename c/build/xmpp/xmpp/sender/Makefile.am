lib_LTLIBRARIES = libaxis2_xmpp_sender.la
libaxis2_xmpp_sender_la_SOURCES = xmpp_transport_sender.c

libaxis2_xmpp_sender_la_LIBADD = $(top_builddir)/modules/core/engine/libaxis2_engine.la \
								$(top_builddir)/axiom/src/om/libaxis2_axiom.la \
								$(top_builddir)/util/src/libaxis2_util.la \
								../libaxis2_xmpp.la

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
