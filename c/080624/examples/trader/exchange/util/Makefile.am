TESTS =

noinst_LTLIBRARIES = libwsf_exchange_util.la

libwsf_exchange_util_la_SOURCES = axis2_stub_TraderExchange.c exchange.c 


libwsf_exchange_util_la_LIBADD  = $(LDFLAGS) \
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
