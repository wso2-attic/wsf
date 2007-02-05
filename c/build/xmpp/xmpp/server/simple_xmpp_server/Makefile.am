prgbindir=$(prefix)/bin/
prgbin_PROGRAMS = axis2_xmpp_server
SUBDIRS =
AM_CFLAGS = -g -pthread
axis2_xmpp_server_SOURCES = xmpp_server_main.c

axis2_xmpp_server_LDADD   =  $(LDFLAGS) \
                            -L$(top_builddir)/modules/wsdl \
                            -L$(top_builddir)/modules/core/engine \
                            -L$(top_builddir)/modules/core/transport/xmpp/sender \
                            -L$(top_builddir)/modules/core/transport/xmpp/receiver \
							$(top_builddir)/axiom/src/om/libaxis2_axiom.la \
							$(top_builddir)/util/src/libaxis2_util.la \
							../../../../../../axiom/src/parser/$(WRAPPER_DIR)/libaxis2_parser.la \
							$(top_builddir)/woden/src/wsdl20/libwoden.la \
							$(top_builddir)/xml_schema/src/libaxis2_xml_schema.la \
                            -laxis2_engine \
							-liksemel \
                            -lpthread \
                            -laxis2_wsdl \
                            -laxis2_xmpp_sender \
                            -laxis2_xmpp_receiver \
							-L$(top_builddir)$(GUTHTHILA_LIBS) \
                            $(LIBXML2_LIBS)
                    
INCLUDES =  -I$(top_builddir)/include \
            -I$(top_builddir)/modules/wsdl\
            -I$(top_builddir)/modules/core/description\
            -I$(top_builddir)/modules/core/context \
            -I$(top_builddir)/modules/core/deployment\
            -I$(top_builddir)/modules/core/phaseresolver \
            -I$(top_builddir)/modules/core/engine \
            -I$(top_builddir)/xml_schema/include \
            -I$(top_builddir)/util/include \
            -I$(top_builddir)/axiom/include
