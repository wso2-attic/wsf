

    /**
     * TraderClientSkeleton.h
     *
     * This file was auto-generated from WSDL for "TraderClient|http://www.wso2.org" service
     * by the WSO2 WSF/CPP Version: #axisVersion#
     * TraderClientSkeleton WSO2 WSF/CPP Skeleton for the Service Header File
     */
#ifndef TRADERCLIENTSKELETON_H
#define TRADERCLIENTSKELETON_H

    #include <OMElement.h>
    #include <MessageContext.h>
   
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

	  #include <SimpleTrader.h>
    
namespace org_wso2_www{
    

   /** we have to reserve some error codes for adb and for custom messages */
    #define TRADERCLIENTSKELETON_ERROR_CODES_START (AXIS2_ERROR_LAST + 2500)

    typedef enum
    {
        TRADERCLIENTSKELETON_ERROR_NONE = TRADERCLIENTSKELETON_ERROR_CODES_START,

        TRADERCLIENTSKELETON_ERROR_LAST
    } TraderClientSkeleton_error_codes;

    


class TraderClientSkeleton
{
		
		private:
			org_wso2_www::SimpleTrader *simpleTrader;

        public:
            TraderClientSkeleton();


     




		 


        /**
         * Auto generated method declaration
         * for "deposit|http://www.wso2.org" operation.
         * 
         * @param _depositRequest of the org_wso2_www_types::DepositRequest
         *
         * @return org_wso2_www_types::DepositResponse*
         */
        

         virtual 
        org_wso2_www_types::DepositResponse* deposit(wso2wsf::MessageContext *outCtx ,org_wso2_www_types::DepositRequest* _depositRequest);


     




		 


        /**
         * Auto generated method declaration
         * for "getSymbols|http://www.wso2.org" operation.
         * 
         * @param _getSymbolsRequest of the org_wso2_www_types::GetSymbolsRequest
         *
         * @return org_wso2_www_types::GetSymbolsResponse*
         */
        

         virtual 
        org_wso2_www_types::GetSymbolsResponse* getSymbols(wso2wsf::MessageContext *outCtx ,org_wso2_www_types::GetSymbolsRequest* _getSymbolsRequest);


     




		 


        /**
         * Auto generated method declaration
         * for "getQuote|http://www.wso2.org" operation.
         * 
         * @param _getQuoteRequest of the org_wso2_www_types::GetQuoteRequest
         *
         * @return org_wso2_www_types::GetQuoteResponse*
         */
        

         virtual 
        org_wso2_www_types::GetQuoteResponse* getQuote(wso2wsf::MessageContext *outCtx ,org_wso2_www_types::GetQuoteRequest* _getQuoteRequest);


     




		 


        /**
         * Auto generated method declaration
         * for "createAccount|http://www.wso2.org" operation.
         * 
         * @param _createAccountRequest of the org_wso2_www_types::CreateAccountRequest
         *
         * @return org_wso2_www_types::CreateAccountResponse*
         */
        

         virtual 
        org_wso2_www_types::CreateAccountResponse* createAccount(wso2wsf::MessageContext *outCtx ,org_wso2_www_types::CreateAccountRequest* _createAccountRequest);


     




		 


        /**
         * Auto generated method declaration
         * for "sell|http://www.wso2.org" operation.
         * 
         * @param _sellRequest of the org_wso2_www_types::SellRequest
         *
         * @return org_wso2_www_types::SellResponse*
         */
        

         virtual 
        org_wso2_www_types::SellResponse* sell(wso2wsf::MessageContext *outCtx ,org_wso2_www_types::SellRequest* _sellRequest);


     




		 


        /**
         * Auto generated method declaration
         * for "buy|http://www.wso2.org" operation.
         * 
         * @param _buyRequest of the org_wso2_www_types::BuyRequest
         *
         * @return org_wso2_www_types::BuyResponse*
         */
        

         virtual 
        org_wso2_www_types::BuyResponse* buy(wso2wsf::MessageContext *outCtx ,org_wso2_www_types::BuyRequest* _buyRequest);


     




		 


        /**
         * Auto generated method declaration
         * for "getPortfolio|http://www.wso2.org" operation.
         * 
         * @param _getPortfolioRequest of the org_wso2_www_types::GetPortfolioRequest
         *
         * @return org_wso2_www_types::GetPortfolioResponse*
         */
        

         virtual 
        org_wso2_www_types::GetPortfolioResponse* getPortfolio(wso2wsf::MessageContext *outCtx ,org_wso2_www_types::GetPortfolioRequest* _getPortfolioRequest);


     



};


}



        
#endif // TRADERCLIENTSKELETON_H
    

