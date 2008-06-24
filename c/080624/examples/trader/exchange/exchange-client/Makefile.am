prglibdir=$(prefix)/services/exchangeclient
prglib_LTLIBRARIES = libexchangeclient.la
prglib_DATA=services.xml Exchange_Client.wsdl
EXTRA_DIST=services.xml Exchange_Client.wsdl
noinst_HEADERS = axis2_skel_ExchangeClient.h

libexchangeclient_la_SOURCES = axis2_skel_ExchangeClient.c axis2_svc_skel_ExchangeClient.c 

libexchangeclient_la_LIBADD  = $(LDFLAGS) \
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
