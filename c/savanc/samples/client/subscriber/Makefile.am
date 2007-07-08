prgbindir=$(prefix)/bin/samples/savan
prgbin_PROGRAMS = subscriber 
samplesdir=$(prefix)/samples/client/subscriber
subscriber_SOURCES = subscriber.c

subscriber_LDADD   = $(LDFLAGS) \
                    -L$(AXIS2C_HOME)/lib \
					-L../../../src/core \
                    ../../../../axis2c/util/src/libaxutil.la\
                    ../../../../axis2c/axiom/src/om/libaxis2_axiom.la\
                    ../../../../axis2c/src/core/engine/libaxis2_engine.la\
                    ../../../../axis2c/src/core/transport/http/sender/libaxis2_http_sender.la \
                    ../../../../axis2c/src/core/transport/http/receiver/libaxis2_http_receiver.la \
                    -lpthread \
                    $(GUTHTHILA_LIBS) \
                    $(LIBXML2_LIBS)\
					-lmod_savan

INCLUDES = -I$(AXIS2C_HOME)/include \
			@AXIOMINC@ \
			@UTILINC@ \
			@AXIS2INC@ \
			@NEETHIINC@ \
			-I../../../include
