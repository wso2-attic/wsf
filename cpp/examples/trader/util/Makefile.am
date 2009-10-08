
noinst_LTLIBRARIES = libtrader_util.la

libtrader_util_la_SOURCES = ArrayOfString.cpp \
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


libtrader_util_la_LIBADD  = $(LDFLAGS) \
                -L$(WSFCPP_HOME)/lib \
                -laxutil \
                -laxis2_axiom \
                -laxis2_engine \
                -lpthread \
                -lwso2_wsf 
 
INCLUDES = -I ../include \
           -I ../../../include \
           -I ../../../wsf_c/axis2c/include \
           -I ../../../wsf_c/axis2c/neethi/include \
           -I ../../../wsf_c/axis2c/axiom/include \
           -I ../../../wsf_c/axis2c/util/include \
           -I ../../../wsf_c/axis2c/util/include/platforms 

