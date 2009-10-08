prglibdir=$(prefix)/services/TraderClient

prglib_LTLIBRARIES = libTraderClient.la

prglib_DATA=services.xml Trader_Client.wsdl

EXTRA_DIST=services.xml Trader_Client.wsdl

noinst_HEADERS = TraderClientSkeleton.h TraderClient.h 

libTraderClient_la_SOURCES = TraderClient.cpp TraderClientMacro.cpp TraderClientSkeleton.cpp

libTraderClient_la_LIBADD  = $(LDFLAGS) \
                    -L$(WSFCPP_HOME)/lib \
                    -laxutil \
                    -laxis2_axiom \
                    -laxis2_parser \
                    -laxis2_http_sender \
                    -laxis2_http_receiver \
		    ./../trader-util/libtrader_trader_util.la \
		    ./../../util/libtrader_util.la \
                    $(GUTHTHILA_LIBS) \
                    $(LIBXML2_LIBS)
 

INCLUDES = -I ../../include \
	   -I ../trader-util \
           -I ../../../../include \
           -I ../../../../wsf_c/axis2c/include \
           -I ../../../../wsf_c/axis2c/neethi/include \
           -I ../../../../wsf_c/axis2c/axiom/include \
           -I ../../../../wsf_c/axis2c/util/include \
           -I ../../../../wsf_c/axis2c/util/include/platforms
