

#ifndef TRADERCLIENTSTUB_H
#define TRADERCLIENTSTUB_H
/**
* TraderClientStub.h
*
* This file was auto-generated from WSDL for "TraderClient|http://www.wso2.org" service
* by the Apache Axis2/Java version: #axisVersion# #today#
*/

#include <stdio.h>
#include <OMElement.h>
#include <Stub.h>
#include <ServiceClient.h>


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


namespace org_wso2_www
{

#define TRADERCLIENTSTUB_ERROR_CODES_START (AXIS2_ERROR_LAST + 2000)

typedef enum
{
     TRADERCLIENTSTUB_ERROR_NONE = TRADERCLIENTSTUB_ERROR_CODES_START,

    TRADERCLIENTSTUB_ERROR_LAST
} TraderClientStub_error_codes;

 class ITraderClientCallback;

 

class TraderClientStub : public wso2wsf::Stub
{

        public:
        /**
         *  Constructor of TraderClient class
         *  @param client_home WSF/C home directory
         *  
         */
        TraderClientStub(std::string& client_home);

        /**
         *  Constructor of TraderClient class
         *  @param client_home WSF/C home directory
         *  @param endpoint_uri The to endpoint uri,
         */

        TraderClientStub(std::string& client_home, std::string& endpoint_uri);

        /**
         * Populate Services for TraderClientStub
         */
        void WSF_CALL
        populateServicesForTraderClient();

        /**
         * Get the endpoint uri of the TraderClientStub
         */

        std::string WSF_CALL
        getEndpointUriOfTraderClient();

        

            /**
             * Auto generated function declaration
             * for "deposit|http://www.wso2.org" operation.
             * 
             * @param _depositRequest of the org_wso2_www_types::DepositRequest
             *
             * @return org_wso2_www_types::DepositResponse*
             */

            org_wso2_www_types::DepositResponse* WSF_CALL deposit( org_wso2_www_types::DepositRequest*  _depositRequest);
          

            /**
             * Auto generated function declaration
             * for "getSymbols|http://www.wso2.org" operation.
             * 
             * @param _getSymbolsRequest of the org_wso2_www_types::GetSymbolsRequest
             *
             * @return org_wso2_www_types::GetSymbolsResponse*
             */

            org_wso2_www_types::GetSymbolsResponse* WSF_CALL getSymbols( org_wso2_www_types::GetSymbolsRequest*  _getSymbolsRequest);
          

            /**
             * Auto generated function declaration
             * for "getQuote|http://www.wso2.org" operation.
             * 
             * @param _getQuoteRequest of the org_wso2_www_types::GetQuoteRequest
             *
             * @return org_wso2_www_types::GetQuoteResponse*
             */

            org_wso2_www_types::GetQuoteResponse* WSF_CALL getQuote( org_wso2_www_types::GetQuoteRequest*  _getQuoteRequest);
          

            /**
             * Auto generated function declaration
             * for "createAccount|http://www.wso2.org" operation.
             * 
             * @param _createAccountRequest of the org_wso2_www_types::CreateAccountRequest
             *
             * @return org_wso2_www_types::CreateAccountResponse*
             */

            org_wso2_www_types::CreateAccountResponse* WSF_CALL createAccount( org_wso2_www_types::CreateAccountRequest*  _createAccountRequest);
          

            /**
             * Auto generated function declaration
             * for "sell|http://www.wso2.org" operation.
             * 
             * @param _sellRequest of the org_wso2_www_types::SellRequest
             *
             * @return org_wso2_www_types::SellResponse*
             */

            org_wso2_www_types::SellResponse* WSF_CALL sell( org_wso2_www_types::SellRequest*  _sellRequest);
          

            /**
             * Auto generated function declaration
             * for "buy|http://www.wso2.org" operation.
             * 
             * @param _buyRequest of the org_wso2_www_types::BuyRequest
             *
             * @return org_wso2_www_types::BuyResponse*
             */

            org_wso2_www_types::BuyResponse* WSF_CALL buy( org_wso2_www_types::BuyRequest*  _buyRequest);
          

            /**
             * Auto generated function declaration
             * for "getPortfolio|http://www.wso2.org" operation.
             * 
             * @param _getPortfolioRequest of the org_wso2_www_types::GetPortfolioRequest
             *
             * @return org_wso2_www_types::GetPortfolioResponse*
             */

            org_wso2_www_types::GetPortfolioResponse* WSF_CALL getPortfolio( org_wso2_www_types::GetPortfolioRequest*  _getPortfolioRequest);
          

        /**
         * Auto generated function for asynchronous invocations
         * for "deposit|http://www.wso2.org" operation.
         * @param stub The stub
         * 
         * @param _depositRequest of the org_wso2_www_types::DepositRequest
         * @param ICallback callback handler
         */


        void WSF_CALL
        start_deposit(org_wso2_www_types::DepositRequest*  _depositRequest,ITraderClientCallback* callback);

        

        /**
         * Auto generated function for asynchronous invocations
         * for "getSymbols|http://www.wso2.org" operation.
         * @param stub The stub
         * 
         * @param _getSymbolsRequest of the org_wso2_www_types::GetSymbolsRequest
         * @param ICallback callback handler
         */


        void WSF_CALL
        start_getSymbols(org_wso2_www_types::GetSymbolsRequest*  _getSymbolsRequest,ITraderClientCallback* callback);

        

        /**
         * Auto generated function for asynchronous invocations
         * for "getQuote|http://www.wso2.org" operation.
         * @param stub The stub
         * 
         * @param _getQuoteRequest of the org_wso2_www_types::GetQuoteRequest
         * @param ICallback callback handler
         */


        void WSF_CALL
        start_getQuote(org_wso2_www_types::GetQuoteRequest*  _getQuoteRequest,ITraderClientCallback* callback);

        

        /**
         * Auto generated function for asynchronous invocations
         * for "createAccount|http://www.wso2.org" operation.
         * @param stub The stub
         * 
         * @param _createAccountRequest of the org_wso2_www_types::CreateAccountRequest
         * @param ICallback callback handler
         */


        void WSF_CALL
        start_createAccount(org_wso2_www_types::CreateAccountRequest*  _createAccountRequest,ITraderClientCallback* callback);

        

        /**
         * Auto generated function for asynchronous invocations
         * for "sell|http://www.wso2.org" operation.
         * @param stub The stub
         * 
         * @param _sellRequest of the org_wso2_www_types::SellRequest
         * @param ICallback callback handler
         */


        void WSF_CALL
        start_sell(org_wso2_www_types::SellRequest*  _sellRequest,ITraderClientCallback* callback);

        

        /**
         * Auto generated function for asynchronous invocations
         * for "buy|http://www.wso2.org" operation.
         * @param stub The stub
         * 
         * @param _buyRequest of the org_wso2_www_types::BuyRequest
         * @param ICallback callback handler
         */


        void WSF_CALL
        start_buy(org_wso2_www_types::BuyRequest*  _buyRequest,ITraderClientCallback* callback);

        

        /**
         * Auto generated function for asynchronous invocations
         * for "getPortfolio|http://www.wso2.org" operation.
         * @param stub The stub
         * 
         * @param _getPortfolioRequest of the org_wso2_www_types::GetPortfolioRequest
         * @param ICallback callback handler
         */


        void WSF_CALL
        start_getPortfolio(org_wso2_www_types::GetPortfolioRequest*  _getPortfolioRequest,ITraderClientCallback* callback);

          


};

/** we have to reserve some error codes for adb and for custom messages */



}


        
#endif        
   

