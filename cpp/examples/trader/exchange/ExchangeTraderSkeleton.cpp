

    /**
     * ExchangeTraderSkeleton.cpp
     *
     * This file was Auto-Generated from WSDL for "ExchangeTrader|http://www.wso2.org" service
     * by the WSO2 WSF/CPP version:
     * ExchangeTraderSkeleton WSF/CPP Skeleton For the Service
     */

     #include "ExchangeTraderSkeleton.h"

    
     #include <LoginRequest.h>
    
     #include <RegisterClientRequest.h>
    
     #include <RegisterClientResponse.h>
    
     #include <RegisterFeedTargetRequest.h>
    
     #include <SellRequest_ex.h>
    
     #include <BuyRequest_ex.h>
    
    using namespace org_wso2_www;


	ExchangeTraderSkeleton::ExchangeTraderSkeleton()
	{
		exchange = new SimpleExchange();
	}

		 
        /**
         * Auto generated function definition signature
         * for "login|http://www.wso2.org" operation.
         * 
         * @param _loginRequest of the org_wso2_www_types::LoginRequest
         *
         * @return 
         */
        bool  ExchangeTraderSkeleton::login(wso2wsf::MessageContext *outCtx ,org_wso2_www_types::LoginRequest* _loginRequest)

        {
          /* TODO fill this with the necessary business logic */
          return true;
        }
     

		 
        /**
         * Auto generated function definition signature
         * for "registerClient|http://www.wso2.org" operation.
         * 
         * @param _registerClientRequest of the org_wso2_www_types::RegisterClientRequest
         *
         * @return org_wso2_www_types::RegisterClientResponse*
         */
        org_wso2_www_types::RegisterClientResponse* ExchangeTraderSkeleton::registerClient(wso2wsf::MessageContext *outCtx ,org_wso2_www_types::RegisterClientRequest* _registerClientRequest)

        {
			std::string userId = "";
			org_wso2_www_types::ClientInfo *clientInfo =  _registerClientRequest->getClientInfo();
			if(clientInfo)
			{
				userId = exchange->registerClient(clientInfo);
				if(userId != "")
				{
					org_wso2_www_types::RegisterClientResponse *registerClientResponse = new org_wso2_www_types::RegisterClientResponse();
					registerClientResponse->setUserid(userId);
					return registerClientResponse;
				}
			}
			return NULL;			
        }
     

		 
        /**
         * Auto generated function definition signature
         * for "registerFeedTarget|http://www.wso2.org" operation.
         * 
         * @param _registerFeedTargetRequest of the org_wso2_www_types::RegisterFeedTargetRequest
         *
         * @return 
         */
        bool  ExchangeTraderSkeleton::registerFeedTarget(wso2wsf::MessageContext *outCtx ,org_wso2_www_types::RegisterFeedTargetRequest* _registerFeedTargetRequest)

        {
          /* TODO fill this with the necessary business logic */
          return true;
        }
     

		 
        /**
         * Auto generated function definition signature
         * for "sell|http://www.wso2.org" operation.
         * 
         * @param _sellRequest_ex of the org_wso2_www_types::SellRequest_ex
         *
         * @return 
         */
        bool  ExchangeTraderSkeleton::sell(wso2wsf::MessageContext *outCtx ,org_wso2_www_types::SellRequest_ex* _sellRequest_ex)

        {
          int quantity = _sellRequest_ex->getQty();
		  exchange->sell(quantity);
		  return true;
		}
     

		 
        /**
         * Auto generated function definition signature
         * for "buy|http://www.wso2.org" operation.
         * 
         * @param _buyRequest_ex of the org_wso2_www_types::BuyRequest_ex
         *
         * @return 
         */
        bool  ExchangeTraderSkeleton::buy(wso2wsf::MessageContext *outCtx ,org_wso2_www_types::BuyRequest_ex* _buyRequest_ex)

        {
			if(_buyRequest_ex)
			{
				int quantity = _buyRequest_ex->getQty();
				exchange->buy(quantity);
			}
          return true;
        }
     

