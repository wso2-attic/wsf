prglibdir=$(prefix)/services/exchangetrader
prglib_LTLIBRARIES = libexchangetrader.la
prglib_DATA=services.xml Exchange_Trader.wsdl
EXTRA_DIST=services.xml Exchange_Trader.wsdl
noinst_HEADERS = axis2_skel_ExchangeTrader.h

libexchangetrader_la_SOURCES = axis2_skel_ExchangeTrader.c axis2_svc_skel_ExchangeTrader.c 

libexchangetrader_la_LIBADD = $(LDFLAGS) \
                    -L$(WSFC_HOME)/lib \
                    -laxutil \
                    -laxis2_axiom \
                    -laxis2_parser \
                    -laxis2_http_sender \
                    -laxis2_http_receiver \
					../../util/libwsf_util.la \
					../util/libwsf_exchange_util.la \
                    $(GUTHTHILA_LIBS) \
                    $(LIBXML2_LIBS)
 

INCLUDES = 	-I ../../include \
			@AXIS2INC@
