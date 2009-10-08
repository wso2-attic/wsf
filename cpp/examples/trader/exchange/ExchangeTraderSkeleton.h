

    /**
     * ExchangeTraderSkeleton.h
     *
     * This file was auto-generated from WSDL for "ExchangeTrader|http://www.wso2.org" service
     * by the WSO2 WSF/CPP Version: #axisVersion#
     * ExchangeTraderSkeleton WSO2 WSF/CPP Skeleton for the Service Header File
     */
#ifndef EXCHANGETRADERSKELETON_H
#define EXCHANGETRADERSKELETON_H

    #include <OMElement.h>
    #include <MessageContext.h>
   
     #include <LoginRequest.h>
    
     #include <RegisterClientRequest.h>
    
     #include <RegisterClientResponse.h>
    
     #include <RegisterFeedTargetRequest.h>
    
     #include <SellRequest_ex.h>
    
     #include <BuyRequest_ex.h>
	#include <SimpleExchange.h>
    
namespace org_wso2_www{
    

   /** we have to reserve some error codes for adb and for custom messages */
    #define EXCHANGETRADERSKELETON_ERROR_CODES_START (AXIS2_ERROR_LAST + 2500)

    typedef enum
    {
        EXCHANGETRADERSKELETON_ERROR_NONE = EXCHANGETRADERSKELETON_ERROR_CODES_START,

        EXCHANGETRADERSKELETON_ERROR_LAST
    } ExchangeTraderSkeleton_error_codes;

    


class ExchangeTraderSkeleton
{

		private:
			SimpleExchange *exchange;

        public:
            ExchangeTraderSkeleton();

     




		 


        /**
         * Auto generated method declaration
         * for "login|http://www.wso2.org" operation.
         * 
         * @param _loginRequest of the org_wso2_www_types::LoginRequest
         *
         * @return 
         */
        

         virtual 
        bool  login(wso2wsf::MessageContext *outCtx ,org_wso2_www_types::LoginRequest* _loginRequest);


     




		 


        /**
         * Auto generated method declaration
         * for "registerClient|http://www.wso2.org" operation.
         * 
         * @param _registerClientRequest of the org_wso2_www_types::RegisterClientRequest
         *
         * @return org_wso2_www_types::RegisterClientResponse*
         */
        

         virtual 
        org_wso2_www_types::RegisterClientResponse* registerClient(wso2wsf::MessageContext *outCtx ,org_wso2_www_types::RegisterClientRequest* _registerClientRequest);


     




		 


        /**
         * Auto generated method declaration
         * for "registerFeedTarget|http://www.wso2.org" operation.
         * 
         * @param _registerFeedTargetRequest of the org_wso2_www_types::RegisterFeedTargetRequest
         *
         * @return 
         */
        

         virtual 
        bool  registerFeedTarget(wso2wsf::MessageContext *outCtx ,org_wso2_www_types::RegisterFeedTargetRequest* _registerFeedTargetRequest);


     




		 


        /**
         * Auto generated method declaration
         * for "sell|http://www.wso2.org" operation.
         * 
         * @param _sellRequest_ex of the org_wso2_www_types::SellRequest_ex
         *
         * @return 
         */
        

         virtual 
        bool  sell(wso2wsf::MessageContext *outCtx ,org_wso2_www_types::SellRequest_ex* _sellRequest_ex);


     




		 


        /**
         * Auto generated method declaration
         * for "buy|http://www.wso2.org" operation.
         * 
         * @param _buyRequest_ex of the org_wso2_www_types::BuyRequest_ex
         *
         * @return 
         */
        

         virtual 
        bool  buy(wso2wsf::MessageContext *outCtx ,org_wso2_www_types::BuyRequest_ex* _buyRequest_ex);


     



};


}



        
#endif // EXCHANGETRADERSKELETON_H
    

