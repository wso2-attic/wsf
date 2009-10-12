noinst_LTLIBRARIES = libtrader_trader_util.la
EXTRA_DIST=Exchange_Trader.wsdl
noinst_HEADERS=ExchangeTraderStub.h  IExchangeTraderCallback.h  SimpleTrader.h

libtrader_trader_util_la_SOURCES = ExchangeTraderStub.cpp SimpleTrader.cpp


libtrader_trader_util_la_LIBADD  = $(LDFLAGS) \
                    -L$(WSFCPP_HOME)/lib \
                    -laxutil \
                    -laxis2_axiom \
                    -laxis2_parser \
                    -laxis2_http_sender \
                    -laxis2_http_receiver \
                    $(GUTHTHILA_LIBS) \
                    $(LIBXML2_LIBS)
 

INCLUDES = -I ../../include \
	   -I ../../../../include \
           -I ../../../../wsf_c/axis2c/include \
           -I ../../../../wsf_c/axis2c/neethi/include \
           -I ../../../../wsf_c/axis2c/axiom/include \
           -I ../../../../wsf_c/axis2c/util/include \
           -I ../../../../wsf_c/axis2c/util/include/platforms
