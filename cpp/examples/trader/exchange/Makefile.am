prglibdir=$(prefix)/services/ExchangeTrader
prglib_LTLIBRARIES = libExchangeTrader.la
prglib_DATA=services.xml Exchange_Trader.wsdl
EXTRA_DIST=services.xml Exchange_Trader.wsdl
noinst_HEADERS = ExchangeTrader.h ExchangeTraderSkeleton.h SimpleExchange.h 

libExchangeTrader_la_SOURCES = ExchangeTrader.cpp ExchangeTraderMacro.cpp ExchangeTraderSkeleton.cpp SimpleExchange.cpp 

libExchangeTrader_la_LIBADD = $(LDFLAGS) \
                    -L$(WSFC_HOME)/lib \
                    -laxutil \
                    -laxis2_axiom \
                    -laxis2_http_sender \
		    -laxis2_http_receiver \
                    -lpthread \
		    ./../util/libtrader_util.la \
                    $(GUTHTHILA_LIBS) \
                    $(LIBXML2_LIBS)
 

INCLUDES = -I ./../include \
	   -I ./../../../include \
           -I ./../../../wsf_c/axis2c/include \
           -I ./../../../wsf_c/axis2c/axiom/include \
           -I ./../../../wsf_c/axis2c/util/include \
	   -I ./../../../wsf_c/axis2c/util/include/platforms \
	   -I ./../../../wsf_c/axis2c/neethi/include

