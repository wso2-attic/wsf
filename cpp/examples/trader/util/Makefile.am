noinst_LTLIBRARIES = libtrader_util.la

libwsf_util_la_SOURCES = ArrayOfString.cpp \
			BuyRequest.cpp \
			BuyRequest_ex.cpp \
			BuyResponse.cpp \
			ClientData.cpp \
			ClientInfo.cpp \
			CreateAccountRequest.cpp \
			CreateAccountResponse.cpp \
			DepositRequest.cpp \
			DepositResponse.cpp \
			GetPortfolioRequest.cpp \
			GetPortfolioResponse.cpp \
			GetQuoteRequest.cpp \
			GetQuoteResponse.cpp \
			GetSymbolsRequest.cpp \
			GetSymbolsResponse.cpp \
			LoginRequest.cpp \
			PortFolio.cpp \
			PortFolioItem.cpp \
			RegisterClientRequest.cpp \
			RegisterClientResponse.cpp \
			RegisterFeedTargetRequest.cpp \
			SellRequest.cpp \
			SellRequest_ex.cpp \
			SellResponse.cpp \
			StockQuote.cpp \
			TradeStatus.cpp	


libwsf_util_la_LIBADD  = $(LDFLAGS) \
                    -L$(WSFCPP_HOME)/lib \
       		../../../wsf_c/axis2c/util/src/libaxutil.la \
                ../../../wsf_c/axis2c/axiom/src/om/libaxis2_axiom.la \
                ../../../wsf_c/axis2c/src/core/engine/libaxis2_engine.la \
                ../../../wsf_c/axis2c/axiom/src/parser/guththila/libaxis2_parser.la \
                ../../../wsf_c/axis2c/src/core/transport/http/sender/libaxis2_http_sender.la \
                ../../../wsf_c/axis2c/src/core/transport/http/receiver/libaxis2_http_receiver.la \
                -lpthread \
                ../../../src/main/libwso2_wsf.la \
                $(GUTHTHILA_LIBS) \
                $(LIBXML2_LIBS)
 
INCLUDES = -I ../include \ 
	   -I ../../../include \
           -I ../../../wsf_c/axis2c/include \
           -I ../../../wsf_c/axis2c/neethi/include \
           -I ../../../wsf_c/axis2c/axiom/include \
           -I ../../../wsf_c/axis2c/util/include \
           -I ../../../wsf_c/axis2c/util/include/platforms 

