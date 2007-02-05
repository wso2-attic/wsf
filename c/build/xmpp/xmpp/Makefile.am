SUBDIRS = . sender receiver server
noinst_LTLIBRARIES = libaxis2_xmpp.la

libaxis2_xmpp_la_SOURCES = xmpp_worker.c \
                           xmpp_transport_utils.c

INCLUDES = -I$(top_builddir)/include \
            -I$(top_builddir)/modules/wsdl \
            -I$(top_builddir)/modules/core/engine \
            -I$(top_builddir)/xml_schema/include \
            -I$(top_builddir)/util/include \
            -I$(top_builddir)/axiom/include
