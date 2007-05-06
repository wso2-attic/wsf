prgbindir=$(prefix)/bin
prgbin_PROGRAMS = wsclient

wsclient_SOURCES = wsclient.c \
		   option.c \
		   util.c \
		   stub.c

wsclient_LDADD   = $(LDFLAGS) \
                    -L$(AXIS2C_HOME)/lib \
		     		../../axis2c/util/src/libaxis2_util.la \
					../../axis2c/axiom/src/om/libaxis2_axiom.la \
					../../axis2c/src/core/engine/libaxis2_engine.la \
					../../axis2c/axiom/src/parser/libxml2/libaxis2_parser.la \
                    -lpthread \
					../../axis2c/src/core/transport/http/sender/libaxis2_http_sender.la \
					../../axis2c/src/core/transport/http/receiver/libaxis2_http_receiver.la \
                    $(GUTHTHILA_LIBS) \
                    $(LIBXML2_LIBS)

INCLUDES = -I$(AXIS2C_HOME)/include \
            -I ../../axis2c/util/include \
            -I ../../axis2c/include \
            -I ../../axis2c/axiom/include \
            -I ../../axis2c/rampart/include
