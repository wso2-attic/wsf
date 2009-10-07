

    /**
     * TraderClientSkeleton.cpp
     *
     * This file was Auto-Generated from WSDL for "TraderClient|http://www.wso2.org" service
     * by the WSO2 WSF/CPP version:
     * TraderClientSkeleton WSF/CPP Skeleton For the Service
     */

     #include "TraderClientSkeleton.h"

    
     #include <DepositRequest.h>
    
     #include <DepositResponse.h>
    
     #include <GetSymbolsRequest.h>
    
     #include <GetSymbolsResponse.h>
    
     #include <GetQuoteRequest.h>
    
     #include <GetQuoteResponse.h>
    
     #include <CreateAccountRequest.h>
    
     #include <CreateAccountResponse.h>
    
     #include <SellRequest.h>
    
     #include <SellResponse.h>
    
     #include <BuyRequest.h>
    
     #include <BuyResponse.h>
    
     #include <GetPortfolioRequest.h>
    
     #include <GetPortfolioResponse.h>
    
    using namespace org_wso2_www;

	
	org_wso2_www::TraderClientSkeleton::TraderClientSkeleton()
	{
		simpleTrader = new SimpleTrader();
	}

		 
        /**
         * Auto generated function definition signature
         * for "deposit|http://www.wso2.org" operation.
         * 
         * @param _depositRequest of the org_wso2_www_types::DepositRequest
         *
         * @return org_wso2_www_types::DepositResponse*
         */
        org_wso2_www_types::DepositResponse* TraderClientSkeleton::deposit(wso2wsf::MessageContext *outCtx ,org_wso2_www_types::DepositRequest* _depositRequest)

        {
          /* TODO fill this with the necessary business logic */
          return (org_wso2_www_types::DepositResponse*)NULL;
        }
     

		 
        /**
         * Auto generated function definition signature
         * for "getSymbols|http://www.wso2.org" operation.
         * 
         * @param _getSymbolsRequest of the org_wso2_www_types::GetSymbolsRequest
         *
         * @return org_wso2_www_types::GetSymbolsResponse*
         */
        org_wso2_www_types::GetSymbolsResponse* TraderClientSkeleton::getSymbols(wso2wsf::MessageContext *outCtx ,org_wso2_www_types::GetSymbolsRequest* _getSymbolsRequest)

        {
          /* TODO fill this with the necessary business logic */
          return (org_wso2_www_types::GetSymbolsResponse*)NULL;
        }
     

		 
        /**
         * Auto generated function definition signature
         * for "getQuote|http://www.wso2.org" operation.
         * 
         * @param _getQuoteRequest of the org_wso2_www_types::GetQuoteRequest
         *
         * @return org_wso2_www_types::GetQuoteResponse*
         */
        org_wso2_www_types::GetQuoteResponse* TraderClientSkeleton::getQuote(wso2wsf::MessageContext *outCtx ,org_wso2_www_types::GetQuoteRequest* _getQuoteRequest)

        {
          /* TODO fill this with the necessary business logic */
          return (org_wso2_www_types::GetQuoteResponse*)NULL;
        }
     

		 
        /**
         * Auto generated function definition signature
         * for "createAccount|http://www.wso2.org" operation.
         * 
         * @param _createAccountRequest of the org_wso2_www_types::CreateAccountRequest
         *
         * @return org_wso2_www_types::CreateAccountResponse*
         */
        org_wso2_www_types::CreateAccountResponse* TraderClientSkeleton::createAccount(wso2wsf::MessageContext *outCtx ,org_wso2_www_types::CreateAccountRequest* _createAccountRequest)

        {
			std::string password = _createAccountRequest->getPassword();
			org_wso2_www_types::ClientInfo *clientInfo = _createAccountRequest->getClientinfo();
			std::string name =  clientInfo->getName();
			std::string ssn  = clientInfo->getSsn();

			std::string userId = simpleTrader->createAccount(ssn, name, password);
			if(userId != "")
			{
				org_wso2_www_types::CreateAccountResponse *response = new org_wso2_www_types::CreateAccountResponse();
				response->setUserid(userId);
				return response;
			}
			return NULL;
        }
     

		 
        /**
         * Auto generated function definition signature
         * for "sell|http://www.wso2.org" operation.
         * 
         * @param _sellRequest of the org_wso2_www_types::SellRequest
         *
         * @return org_wso2_www_types::SellResponse*
         */
        org_wso2_www_types::SellResponse* TraderClientSkeleton::sell(wso2wsf::MessageContext *outCtx ,org_wso2_www_types::SellRequest* _sellRequest)

        {
			std::string username = _sellRequest->getUserid();
			std::string password = _sellRequest->getPassword();
			std::string symbol   = _sellRequest->getSymbol();
			int qty = _sellRequest->getQty();

			bool status = simpleTrader->sell(username, password, symbol, qty);

			org_wso2_www_types::SellResponse *response = new org_wso2_www_types::SellResponse();

			org_wso2_www_types::TradeStatus *sts = new org_wso2_www_types::TradeStatus();
			if(status)
			{
				sts->setStatus(true);
				sts->setReason("Success");
			}
			else
			{
				sts->setStatus(false);
				sts->setReason("Failure");
			}

			response->setTrade_status(sts);
			return response;
        }
     

		 
        /**
         * Auto generated function definition signature
         * for "buy|http://www.wso2.org" operation.
         * 
         * @param _buyRequest of the org_wso2_www_types::BuyRequest
         *
         * @return org_wso2_www_types::BuyResponse*
         */
        org_wso2_www_types::BuyResponse* TraderClientSkeleton::buy(wso2wsf::MessageContext *outCtx ,org_wso2_www_types::BuyRequest* _buyRequest)

        {
			
			std::string username = _buyRequest->getUserid();
			std::string password = _buyRequest->getPassword();
			std::string symbol   = _buyRequest->getSymbol();
			int qty = _buyRequest->getQty();
			
			bool status = simpleTrader->buy(username, password, symbol, qty);

			org_wso2_www_types::BuyResponse *response = new org_wso2_www_types::BuyResponse();

			org_wso2_www_types::TradeStatus *sts = new org_wso2_www_types::TradeStatus();
			if(status)
			{
				sts->setStatus(true);
				sts->setReason("Success");
			}
			else
			{
				sts->setStatus(false);
				sts->setReason("Failure");
			}

			response->setTrade_status(sts);
			return response;
		}
     

		 
        /**
         * Auto generated function definition signature
         * for "getPortfolio|http://www.wso2.org" operation.
         * 
         * @param _getPortfolioRequest of the org_wso2_www_types::GetPortfolioRequest
         *
         * @return org_wso2_www_types::GetPortfolioResponse*
         */
        org_wso2_www_types::GetPortfolioResponse* TraderClientSkeleton::getPortfolio(wso2wsf::MessageContext *outCtx ,org_wso2_www_types::GetPortfolioRequest* _getPortfolioRequest)

        {
          /* TODO fill this with the necessary business logic */
          return (org_wso2_www_types::GetPortfolioResponse*)NULL;
        }
     

