prgbindir=$(prefix)/bin
prgbin_PROGRAMS = wsclient

wsclient_SOURCES = wsclient.c \
		   option.c \
		   util.c \
		   stub.c

wsclient_LDADD   = $(LDFLAGS) \
                    -L$(AXIS2C_HOME)/lib \
		     		../../axis2c/util/src/libaxutil.la \
					../../axis2c/axiom/src/om/libaxis2_axiom.la \
					../../axis2c/src/core/engine/libaxis2_engine.la \
                    -lpthread \
					../../axis2c/src/core/transport/http/sender/libaxis2_http_sender.la \
					../../axis2c/src/core/transport/http/receiver/libaxis2_http_receiver.la \
					../../axis2c/neethi/src/util/libneethi_util.la \
					../../axis2c/neethi/src/libneethi.la \
					$(GUTHTHILA_LIBS) \
					$(RAMPART_LIBS) \
					$(OMXMLSEC_LIBS) \
					$(SECCONV_LIBS) \
                    $(LIBXML2_LIBS)

INCLUDES =	-I ../../axis2c/util/include \
            -I ../../axis2c/include \
            -I ../../axis2c/axiom/include \
            -I ../../axis2c/neethi/include \
			-I ../../axis2c/neethi/src/util \
            -I ../../rampartc/include 

EXTRA_DIST=constants.h error.h option.h stub.h util.h wsclient.h


