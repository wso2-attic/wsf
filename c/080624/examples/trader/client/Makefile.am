prgbindir=$(prefix)/bin/samples
samplesdir=$(prefix)/samples/client/trader
prgbin_PROGRAMS = trader
samples_DATA=trader_client.c Makefile.am Makefile.in README.txt
trader_SOURCES = trader_client.c axis2_stub_TraderClient.c axis2_stub_ExchangeClient.c

trader_LDADD   =    $(LDFLAGS) \
                    -L$(WSFC_HOME)/lib \
					-laxutil \
                    -laxis2_axiom \
                    -laxis2_engine \
                    -laxis2_parser \
                    -laxis2_http_sender \
                    -laxis2_http_receiver \
					../util/libwsf_util.la \
                    $(GUTHTHILA_LIBS) \
                    $(LIBXML2_LIBS)

INCLUDES = -I ../include \
		   @AXIS2INC@

