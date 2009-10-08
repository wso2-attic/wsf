prglibdir=$(prefix)/services/ExchangeTrader
prglib_LTLIBRARIES = libExchangeTrader.la
prglib_DATA=services.xml Exchange_Trader.wsdl
EXTRA_DIST=services.xml Exchange_Trader.wsdl
noinst_HEADERS = ExchangeTrader.h ExchangeTraderSkeleton.h SimpleExchange.h 

libExchangeTrader_la_SOURCES = ExchangeTrader.cpp ExchangeTraderMacro.cpp ExchangeTraderSkeleton.cpp SimpleExchange.cpp 

libExchangeTrader_la_LIBADD = $(LDFLAGS) \
                    -L$(WSFC_HOME)/lib \
                    -l./../../../wsf_c/axis2c/util/src/libaxutil.la \
                    -l./../../../wsf_c/axis2c/axiom/src/om/libaxis2_axiom.la \
                    -l./../../../wsf_c/axis2c/src/core/transport/http/sender/libaxis2_http_sender.la \
		    -l./../../../wsf_c/axis2c/src/core/transport/http/receiver/libaxis2_http_receiver.la \
                    -lpthread \
		    -l./../util/libtrader_util.la \
                    $(GUTHTHILA_LIBS) \
                    $(LIBXML2_LIBS)
 

INCLUDES = -I ./../include \
	   -I ./../../../include \
           -I ./../../../wsf_c/axis2c/include \
           -I ./../../../wsf_c/axis2c/axiom/include \
           -I ./../../../wsf_c/axis2c/util/include
