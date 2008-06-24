prglibdir=$(prefix)/services/traderexchange
prglib_LTLIBRARIES = libtraderexchange.la
prglib_DATA=services.xml Trader_Exchange.wsdl
EXTRA_DIST=services.xml Trader_Exchange.wsdl
noinst_HEADERS = axis2_skel_TraderExchange.h

libtraderexchange_la_SOURCES = axis2_skel_TraderExchange.c axis2_svc_skel_TraderExchange.c 

libtraderexchange_la_LIBADD  = $(LDFLAGS) \
                    -L$(WSFC_HOME)/lib \
                    -laxutil \
                    -laxis2_axiom \
                    -laxis2_parser \
                    -laxis2_http_sender \
                    -laxis2_http_receiver \
					../../util/libwsf_util.la \
					../util/libwsf_trader_util.la \
                    $(GUTHTHILA_LIBS) \
                    $(LIBXML2_LIBS)
 

INCLUDES = 	-I ../../include \
			@AXIS2INC@
