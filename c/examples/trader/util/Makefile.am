TESTS =

noinst_LTLIBRARIES = libwsf_util.la

libwsf_util_la_SOURCES = axis2_ArrayOfString.c axis2_buyRequest.c axis2_buyRequest_ex.c axis2_buyResponse.c \
						   axis2_ClientInfo.c axis2_createAccountRequest.c axis2_createAccountResponse.c \
						   axis2_depositRequest.c axis2_depositResponse.c axis2_getInfoRequest.c \
						   axis2_getInfoResponse.c axis2_getPortfolioRequest.c axis2_getPortfolioResponse.c \
						   axis2_getQuoteRequest.c axis2_getQuoteResponse.c axis2_getSymbolsRequest.c \
						   axis2_getSymbolsResponse.c axis2_loginRequest.c axis2_MarketInfo.c \
						   axis2_PortFolio.c axis2_PortFolioItem.c axis2_registerClientRequest.c \
						   axis2_registerClientResponse.c axis2_registerFeedTargetRequest.c axis2_sellRequest.c \
						   axis2_sellRequest_ex.c axis2_sellResponse.c axis2_StockQuote.c axis2_TradeStatus.c \
						   axis2_updateRequest.c client_details.c util.c


libwsf_util_la_LIBADD  = $(LDFLAGS) \
                    -L$(WSFC_HOME)/lib \
                    -laxutil \
                    -laxis2_axiom \
                    -laxis2_parser \
                    -laxis2_http_sender \
                    -laxis2_http_receiver \
                    $(GUTHTHILA_LIBS) \
                    $(LIBXML2_LIBS)
 

INCLUDES = 	-I ../include \
			@AXIS2INC@
