

    /**
     * SimpleStockQuoteServiceSkeleton.cpp
     *
     * This file was Auto-Generated from WSDL for "SimpleStockQuoteService|http://services.samples" service
     * by the WSO2 WSF/CPP version:
     * SimpleStockQuoteServiceSkeleton WSF/CPP Skeleton For the Service
     */

     #include "SimpleStockQuoteServiceSkeleton.h"

    
     #include <GetMarketActivityE3.h>
    
     #include <GetMarketActivityResponseE7.h>
    
     #include <GetQuoteE4.h>
    
     #include <GetQuoteResponseE1.h>
    
     #include <ExceptionE5.h>
    
     #include <GetFullQuoteE6.h>
    
     #include <GetFullQuoteResponseE0.h>
    
     #include <PlaceOrderE2.h>
    
     #include <GetSimpleQuote.h>
    
     #include <GetSimpleQuoteResponse.h>
	 
	 #include <PlaceOrder.h>
	 
	 #include <GetQuoteResponse.h>

	 #include <GetSimpleQuoteResponse.h>

	 #include <TradingDay.h>
    
    using namespace samples_services;
	using namespace samples_services_xsd;


static double getRandom(double base, double varience, bool onlypositive) {
	double r = 0;
	srand((int)time(NULL));
	r = ((double)(rand() % 100))/100;
	return (base + ((r > 0.5 ? 1 : -1) * varience * base * r))
		* (onlypositive ? 1 : (r > 0.5 ? 1 : -1));
}

static TradingDay* create_trading_day(int day, samples_services_xsd::GetQuoteResponse *response)
{
	samples_services_xsd::TradingDay *tday = new samples_services_xsd::TradingDay();
	tday->setDay(day);
	tday->setQuote(response);
	return tday;
}	

static GetQuoteResponse* createGetQuoteResponse(std::string symbol) 
{
	double last = 0;
	double change = 0;
	double prevClose = 0;
	GetQuoteResponse *response = new GetQuoteResponse();
	response->setSymbol(symbol);
	last = getRandom(100,0.9, true);
	response->setLast(last);
	response->setLastTradeTimestamp("2009-10-11");
	change = getRandom(3,0.5,false);
	response->setChange(change);
	response->setOpen(getRandom(last,0.05,false));
	response->setHigh(getRandom(last,0.05,false));
	response->setLow(getRandom(last, 0.05, false));
	response->setVolume((int)getRandom(10000, 1, true));
	response->setMarketCap(getRandom(100000, 5, true));
	prevClose = getRandom(last,0.15,false);
	response->setPrevClose(prevClose);
	response->setPercentageChange((change/prevClose)*100);
	response->setEarnings(getRandom(10, 0.4, false));
	response->setPeRatio(getRandom(20, .3, false));
	response->setName("Company");
	return response;
}

		 
        /**
         * Auto generated function definition signature
         * for "getMarketActivity|http://services.samples" operation.
         * 
         * @param _getMarketActivity of the samples_services_xsd::GetMarketActivityE3
         *
         * @return samples_services_xsd::GetMarketActivityResponseE7*
         */
        samples_services_xsd::GetMarketActivityResponseE7* SimpleStockQuoteServiceSkeleton::getMarketActivity(wso2wsf::MessageContext *outCtx ,samples_services_xsd::GetMarketActivityE3* _getMarketActivity)

        {
			GetMarketActivity *marketActivity =  _getMarketActivity->getRequest();
			std::vector<std::string*>* symbols = marketActivity->getSymbols();
			std::vector<GetQuoteResponse*> *responses =  new std::vector<GetQuoteResponse*>();
			GetMarketActivityResponseE7 *getMarketActivityResponseE7 = new GetMarketActivityResponseE7();
			GetMarketActivityResponse *marketActivityResponse = new GetMarketActivityResponse();
			if (symbols != NULL) {						
				std::vector<std::string*>::iterator it= symbols->begin();
				for(;it < symbols->end(); ++it)
				{
					std::string *symbol = *it;
					GetQuoteResponse *response = createGetQuoteResponse(*symbol);
					responses->push_back(response);
				}
			}

			marketActivityResponse->setQuotes(responses);
			getMarketActivityResponseE7->set_return(marketActivityResponse);
			return getMarketActivityResponseE7;
        }
     

		 
        /**
         * Auto generated function definition signature
         * for "getQuote|http://services.samples" operation.
         * 
         * @param _getQuote of the samples_services_xsd::GetQuoteE4
         *
         * @return samples_services_xsd::GetQuoteResponseE1*
         */
        samples_services_xsd::GetQuoteResponseE1* SimpleStockQuoteServiceSkeleton::getQuote(wso2wsf::MessageContext *outCtx ,samples_services_xsd::GetQuoteE4* _getQuote,
                                                  SimpleStockQuoteServiceSkeleton_getQuote_fault *fault)

        {
			GetQuoteResponseE1 *responseE1 = new GetQuoteResponseE1();
			GetQuote *getQuote = _getQuote->getRequest();
			std::string symbol = getQuote->getSymbol();
			GetQuoteResponse *response = createGetQuoteResponse(symbol);
			responseE1->set_return(response);
			return responseE1;
        }
     

		 
        /**
         * Auto generated function definition signature
         * for "getFullQuote|http://services.samples" operation.
         * 
         * @param _getFullQuote of the samples_services_xsd::GetFullQuoteE6
         *
         * @return samples_services_xsd::GetFullQuoteResponseE0*
         */
        samples_services_xsd::GetFullQuoteResponseE0* SimpleStockQuoteServiceSkeleton::getFullQuote(wso2wsf::MessageContext *outCtx ,samples_services_xsd::GetFullQuoteE6* _getFullQuote)

        {
			std::string symbol = NULL;

			GetFullQuoteResponseE0 *getFullQuoteResponseE0 = new GetFullQuoteResponseE0();
			GetFullQuoteResponse *getFullQuoteResponse = new GetFullQuoteResponse();
			GetFullQuote *fullQuote = _getFullQuote->getRequest();
			symbol = fullQuote->getSymbol();
			std::vector<TradingDay*> *days = new std::vector<TradingDay*>();
			for(int i=0;i<365;i++)
			{
				TradingDay *newday = create_trading_day(i, createGetQuoteResponse(symbol));
				days->push_back(newday);
			}

			getFullQuoteResponse->setTradeHistory(days);
			getFullQuoteResponseE0->set_return(getFullQuoteResponse);
			return getFullQuoteResponseE0;
		}
     

		 
        /**
         * Auto generated function definition signature
         * for "placeOrder|http://services.samples" operation.
         * 
         * @param _placeOrder of the samples_services_xsd::PlaceOrderE2
         *
         * @return 
         */
        bool  SimpleStockQuoteServiceSkeleton::placeOrder(wso2wsf::MessageContext *outCtx ,samples_services_xsd::PlaceOrderE2* _placeOrder)

        {
			double price;
			int quantity = 0;
			std::string symbol;
			PlaceOrder *order = _placeOrder->getOrder();
			price = order->getPrice();
			quantity = order->getQuantity();
			symbol = order->getSymbol();
			std::cout<<"Accepted order for"<<quantity<<" stocks of "<<symbol <<" at"<<price<<std::endl;
	          return true;
        }
     

		 
        /**
         * Auto generated function definition signature
         * for "getSimpleQuote|http://services.samples" operation.
         * 
         * @param _getSimpleQuote of the samples_services_xsd::GetSimpleQuote
         *
         * @return samples_services_xsd::GetSimpleQuoteResponse*
         */
        samples_services_xsd::GetSimpleQuoteResponse* SimpleStockQuoteServiceSkeleton::getSimpleQuote(wso2wsf::MessageContext *outCtx ,samples_services_xsd::GetSimpleQuote* _getSimpleQuote)

        {
			std::string symbol;
			GetSimpleQuoteResponse *simpleResponse = new GetSimpleQuoteResponse();
			GetQuoteResponse *response = new GetQuoteResponse();
			symbol = _getSimpleQuote->getSymbol();
			response->setSymbol(symbol);
			simpleResponse->set_return(response);
          return simpleResponse;
        }
     

