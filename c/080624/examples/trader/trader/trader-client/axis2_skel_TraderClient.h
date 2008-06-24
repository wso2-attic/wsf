

    /**
     * axis2_skel_TraderClient.h
     *
     * This file was auto-generated from WSDL for "TraderClient|http://www.wso2.org" service
     * by the Apache Axis2/C version: #axisVersion# #today#
     * axis2_skel_TraderClient Axis2/C skeleton for the axisService- Header file
     */


	#include <axis2_svc_skeleton.h>
	#include <axutil_log_default.h>
	#include <axutil_error_default.h>
	#include <axiom_text.h>
	#include <axiom_node.h>
	#include <axiom_element.h>
    #include <stdio.h>


   
     #include  "axis2_buyResponse.h"
    
     #include "axis2_buyRequest.h"
    
     #include  "axis2_getPortfolioResponse.h"
    
     #include "axis2_getPortfolioRequest.h"
    
     #include  "axis2_depositResponse.h"
    
     #include "axis2_depositRequest.h"
    
     #include  "axis2_getSymbolsResponse.h"
    
     #include "axis2_getSymbolsRequest.h"
    
     #include  "axis2_getQuoteResponse.h"
    
     #include "axis2_getQuoteRequest.h"
    
     #include  "axis2_createAccountResponse.h"
    
     #include "axis2_createAccountRequest.h"
    
     #include  "axis2_sellResponse.h"
    
     #include "axis2_sellRequest.h"
    

	

        axis2_status_t
        axis2_skel_TraderClient_init(
                const axutil_env_t *env);
       

        /**
         * auto generated function declaration
         * for "buy|http://www.wso2.org" operation.
         
         * @param buyRequest
         */
        axis2_buyResponse_t* axis2_skel_TraderClient_buy (const axutil_env_t *env  ,
                                          axis2_buyRequest_t* buyRequest );
     

		 
        /**
         * auto generated function declaration
         * for "getPortfolio|http://www.wso2.org" operation.
         
         * @param getPortfolioRequest
         */
        axis2_getPortfolioResponse_t* axis2_skel_TraderClient_getPortfolio (const axutil_env_t *env  ,
                                          axis2_getPortfolioRequest_t* getPortfolioRequest );
     

		 
        /**
         * auto generated function declaration
         * for "deposit|http://www.wso2.org" operation.
         
         * @param depositRequest
         */
        axis2_depositResponse_t* axis2_skel_TraderClient_deposit (const axutil_env_t *env  ,
                                          axis2_depositRequest_t* depositRequest );
     

		 
        /**
         * auto generated function declaration
         * for "getSymbols|http://www.wso2.org" operation.
         
         * @param getSymbolsRequest
         */
        axis2_getSymbolsResponse_t* axis2_skel_TraderClient_getSymbols (const axutil_env_t *env  ,
                                          axis2_getSymbolsRequest_t* getSymbolsRequest );
     

		 
        /**
         * auto generated function declaration
         * for "getQuote|http://www.wso2.org" operation.
         
         * @param getQuoteRequest
         */
        axis2_getQuoteResponse_t* axis2_skel_TraderClient_getQuote (const axutil_env_t *env  ,
                                          axis2_getQuoteRequest_t* getQuoteRequest );
     

		 
        /**
         * auto generated function declaration
         * for "createAccount|http://www.wso2.org" operation.
         
         * @param createAccountRequest
         */
        axis2_createAccountResponse_t* axis2_skel_TraderClient_createAccount (const axutil_env_t *env  ,
                                          axis2_createAccountRequest_t* createAccountRequest );
     

		 
        /**
         * auto generated function declaration
         * for "sell|http://www.wso2.org" operation.
         
         * @param sellRequest
         */
        axis2_sellResponse_t* axis2_skel_TraderClient_sell (const axutil_env_t *env  ,
                                          axis2_sellRequest_t* sellRequest );
     

