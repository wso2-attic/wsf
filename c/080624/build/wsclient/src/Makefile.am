prgbindir=$(prefix)/bin
prgbin_PROGRAMS = wsclient

wsclient_SOURCES = wsclient.c \
		   wsclient_option.c \
		   wsclient_util.c \
		   wsclient_stub.c

wsclient_LDADD   = $(LDFLAGS) \
                    -L$(AXIS2C_HOME)/lib \
		     		../../axis2/util/src/libaxis2_util.la \
					../../axis2/axiom/src/om/libaxis2_axiom.la \
					../../axis2/modules/wsdl/libaxis2_wsdl.la \
					../../axis2/modules/core/engine/libaxis2_engine.la \
					../../axis2/axiom/src/parser/libxml2/libaxis2_parser.la \
                    -lpthread \
					../../axis2/woden/src/wsdl20/libwoden.la \
					../../axis2/xml_schema/src/libaxis2_xml_schema.la \
					../../axis2/modules/core/transport/http/sender/libaxis2_http_sender.la \
					../../axis2/modules/core/transport/http/receiver/libaxis2_http_receiver.la \
                    $(GUTHTHILA_LIBS) \
                    $(LIBXML2_LIBS)

INCLUDES = -I$(AXIS2C_HOME)/include \
            -I ../../axis2/util/include \
            -I ../../axis2/include \
            -I ../../axis2/axiom/include \
            -I ../../axis2/xml_schema/include \
            -I ../../axis2/rampart/include \
            -I ../../axis2/woden/include


