

    /**
     * SimpleStockQuoteServiceSkeleton.cpp
     *
     * This file was Auto-Generated from WSDL for "SimpleStockQuoteService|http://services.samples" service
     * by the WSO2 WSF/CPP version:
     * SimpleStockQuoteServiceSkeleton WSF/CPP Skeleton For the Service
     */

     #include "SimpleStockQuoteServiceSkeleton.h"

    
     #include <GetQuoteE7.h>
    
     #include <GetQuoteResponseE2.h>
    
     #include <ExceptionE0.h>
    
     #include <GetMarketActivityE4.h>
    
     #include <GetMarketActivityResponseE3.h>
    
     #include <PlaceOrderE1.h>
    
     #include <GetFullQuoteE5.h>
    
     #include <GetFullQuoteResponseE6.h>
    
     #include <GetSimpleQuote.h>
    
     #include <GetSimpleQuoteResponse.h>
	
	#include <GetQuoteResponse.h>
    
    using namespace samples_services;


	static double getRandom(double base, double varience, bool onlypositive)
	{
		double r = 0;
		srand((int)time(NULL));
		r = ((double)(rand() % 100))/100;
		return (base + ((r > 0.5 ? 1 : -1) * varience * base * r))
			* (onlypositive ? 1 : (r > 0.5 ? 1 : -1));
	}

	static TradingDay* create_trading_day(int day, samples_services::GetQuoteResponse *response)
	{
		samples_services::TradingDay *tday = new samples_services::TradingDay();
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
         * for "getQuote|http://services.samples" operation.
         * 
         * @param _getQuote of the samples_services::GetQuoteE7
         *
         * @return samples_services::GetQuoteResponseE2*
         */
        samples_services::GetQuoteResponseE2* SimpleStockQuoteServiceSkeleton::getQuote(samples_services::GetQuoteE7* _getQuote,
                                                  SimpleStockQuoteServiceSkeleton_getQuote_fault *fault)

        {
			GetQuoteResponseE2 *responseE7 = new GetQuoteResponseE2();
			GetQuote *getQuote = _getQuote->getRequest();
			std::string symbol = getQuote->getSymbol();
			GetQuoteResponse *response = createGetQuoteResponse(symbol);
			responseE7->set_return(response);
			return responseE7;
        }
     

		 
        /**
         * Auto generated function definition signature
         * for "getMarketActivity|http://services.samples" operation.
         * 
         * @param _getMarketActivity of the samples_services::GetMarketActivityE4
         *
         * @return samples_services::GetMarketActivityResponseE3*
         */
        samples_services::GetMarketActivityResponseE3* SimpleStockQuoteServiceSkeleton::getMarketActivity(samples_services::GetMarketActivityE4* _getMarketActivity)

        {
			GetMarketActivity *marketActivity =  _getMarketActivity->getRequest();
			std::vector<std::string*>* symbols = marketActivity->getSymbols();
			std::vector<GetQuoteResponse*> *responses =  new std::vector<GetQuoteResponse*>();
			GetMarketActivityResponseE3 *getMarketActivityResponseE3 = new GetMarketActivityResponseE3();
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
			getMarketActivityResponseE3->set_return(marketActivityResponse);
			return getMarketActivityResponseE3;
        }
     

		 
        /**
         * Auto generated function definition signature
         * for "placeOrder|http://services.samples" operation.
         * 
         * @param _placeOrder of the samples_services::PlaceOrderE1
         *
         * @return 
         */
        bool  SimpleStockQuoteServiceSkeleton::placeOrder(samples_services::PlaceOrderE1* _placeOrder)

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
         * for "getFullQuote|http://services.samples" operation.
         * 
         * @param _getFullQuote of the samples_services::GetFullQuoteE5
         *
         * @return samples_services::GetFullQuoteResponseE6*
         */
        samples_services::GetFullQuoteResponseE6* SimpleStockQuoteServiceSkeleton::getFullQuote(samples_services::GetFullQuoteE5* _getFullQuote)

        {
			std::string symbol = NULL;

			GetFullQuoteResponseE6 *getFullQuoteResponseE6 = new GetFullQuoteResponseE6();
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
			getFullQuoteResponseE6->set_return(getFullQuoteResponse);
			return getFullQuoteResponseE6;
        }
     

		 
        /**
         * Auto generated function definition signature
         * for "getSimpleQuote|http://services.samples" operation.
         * 
         * @param _getSimpleQuote of the samples_services::GetSimpleQuote
         *
         * @return samples_services::GetSimpleQuoteResponse*
         */
        samples_services::GetSimpleQuoteResponse* SimpleStockQuoteServiceSkeleton::getSimpleQuote(samples_services::GetSimpleQuote* _getSimpleQuote)

        {
			std::string symbol;
			GetSimpleQuoteResponse *simpleResponse = new GetSimpleQuoteResponse();
			GetQuoteResponse *response = new GetQuoteResponse();
			symbol = _getSimpleQuote->getSymbol();
			response->setSymbol(symbol);
			simpleResponse->set_return(response);
			return simpleResponse;
        }
     

