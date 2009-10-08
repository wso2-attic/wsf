

#ifndef EXCHANGETRADERSTUB_H
#define EXCHANGETRADERSTUB_H
/**
* ExchangeTraderStub.h
*
* This file was auto-generated from WSDL for "ExchangeTrader|http://www.wso2.org" service
* by the Apache Axis2/Java version: #axisVersion# #today#
*/

#include <stdio.h>
#include <OMElement.h>
#include <Stub.h>
#include <ServiceClient.h>


#include <LoginRequest.h>

#include <RegisterClientRequest.h>

#include <RegisterClientResponse.h>

#include <RegisterFeedTargetRequest.h>

#include <SellRequest_ex.h>

#include <BuyRequest_ex.h>


namespace org_wso2_www
{

#define EXCHANGETRADERSTUB_ERROR_CODES_START (AXIS2_ERROR_LAST + 2000)

typedef enum
{
     EXCHANGETRADERSTUB_ERROR_NONE = EXCHANGETRADERSTUB_ERROR_CODES_START,

    EXCHANGETRADERSTUB_ERROR_LAST
} ExchangeTraderStub_error_codes;

 class IExchangeTraderCallback;

 

class ExchangeTraderStub : public wso2wsf::Stub
{

        public:
        /**
         *  Constructor of ExchangeTrader class
         *  @param client_home WSF/C home directory
         *  
         */
        ExchangeTraderStub(std::string& client_home);

        /**
         *  Constructor of ExchangeTrader class
         *  @param client_home WSF/C home directory
         *  @param endpoint_uri The to endpoint uri,
         */

        ExchangeTraderStub(std::string& client_home, std::string& endpoint_uri);

        /**
         * Populate Services for ExchangeTraderStub
         */
        void WSF_CALL
        populateServicesForExchangeTrader();

        /**
         * Get the endpoint uri of the ExchangeTraderStub
         */

        std::string WSF_CALL
        getEndpointUriOfExchangeTrader();

        

            /**
             * Auto generated function declaration
             * for "login|http://www.wso2.org" operation.
             * 
             * @param _loginRequest of the org_wso2_www_types::LoginRequest
             *
             * @return 
             */

            bool WSF_CALL login( org_wso2_www_types::LoginRequest*  _loginRequest);
          

            /**
             * Auto generated function declaration
             * for "registerClient|http://www.wso2.org" operation.
             * 
             * @param _registerClientRequest of the org_wso2_www_types::RegisterClientRequest
             *
             * @return org_wso2_www_types::RegisterClientResponse*
             */

            org_wso2_www_types::RegisterClientResponse* WSF_CALL registerClient( org_wso2_www_types::RegisterClientRequest*  _registerClientRequest);
          

            /**
             * Auto generated function declaration
             * for "registerFeedTarget|http://www.wso2.org" operation.
             * 
             * @param _registerFeedTargetRequest of the org_wso2_www_types::RegisterFeedTargetRequest
             *
             * @return 
             */

            bool WSF_CALL registerFeedTarget( org_wso2_www_types::RegisterFeedTargetRequest*  _registerFeedTargetRequest);
          

            /**
             * Auto generated function declaration
             * for "sell|http://www.wso2.org" operation.
             * 
             * @param _sellRequest_ex of the org_wso2_www_types::SellRequest_ex
             *
             * @return 
             */

            bool WSF_CALL sell( org_wso2_www_types::SellRequest_ex*  _sellRequest_ex);
          

            /**
             * Auto generated function declaration
             * for "buy|http://www.wso2.org" operation.
             * 
             * @param _buyRequest_ex of the org_wso2_www_types::BuyRequest_ex
             *
             * @return 
             */

            bool WSF_CALL buy( org_wso2_www_types::BuyRequest_ex*  _buyRequest_ex);
          

        /**
         * Auto generated function for asynchronous invocations
         * for "registerClient|http://www.wso2.org" operation.
         * @param stub The stub
         * 
         * @param _registerClientRequest of the org_wso2_www_types::RegisterClientRequest
         * @param ICallback callback handler
         */


        void WSF_CALL
        start_registerClient(org_wso2_www_types::RegisterClientRequest*  _registerClientRequest,IExchangeTraderCallback* callback);

          


};

/** we have to reserve some error codes for adb and for custom messages */



}


        
#endif        
   

