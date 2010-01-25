prgbindir=$(prefix)/bin/samples/savan
prgbin_PROGRAMS = subscriber 
samplesdir=$(prefix)/samples/client/subscriber
subscriber_SOURCES = subscriber.c

subscriber_LDADD   = $(LDFLAGS) \
                    -L$(AXIS2C_HOME)/lib \
					-laxutil \
                    -laxis2_axiom \
                    -laxis2_engine \
                    -laxis2_http_sender \
                    -laxis2_http_receiver \
                    -lpthread \
                    $(GUTHTHILA_LIBS) \
                    $(LIBXML2_LIBS)\
					-lsavan_client

INCLUDES =  -I@AXIS2INC@ \
			@AXIS2INC@ \
			@SAVANINC@
