prglibdir=$(prefix)/services/traderclient
prglib_LTLIBRARIES = libtraderclient.la
prglib_DATA=services.xml Trader_Client.wsdl
EXTRA_DIST=services.xml Trader_Client.wsdl
noinst_HEADERS = axis2_skel_TraderClient.h 
libtraderclient_la_SOURCES = axis2_skel_TraderClient.c axis2_svc_skel_TraderClient.c 

libtraderclient_la_LIBADD  = $(LDFLAGS) \
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
