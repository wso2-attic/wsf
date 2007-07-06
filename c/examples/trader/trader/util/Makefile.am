TESTS =

noinst_LTLIBRARIES = libwsf_trader_util.la

libwsf_trader_util_la_SOURCES = axis2_stub_ExchangeTrader.c trader.c 


libwsf_trader_util_la_LIBADD  = $(LDFLAGS) \
                    -L$(WSFC_HOME)/lib \
                    -laxutil \
                    -laxis2_axiom \
                    -laxis2_parser \
                    -laxis2_http_sender \
                    -laxis2_http_receiver \
                    $(GUTHTHILA_LIBS) \
                    $(LIBXML2_LIBS)
 

INCLUDES = 	-I ../../include \
			@AXIS2INC@
