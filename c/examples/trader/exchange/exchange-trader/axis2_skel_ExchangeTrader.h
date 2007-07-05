

    /**
     * axis2_skel_ExchangeTrader.h
     *
     * This file was auto-generated from WSDL for "ExchangeTrader|http://www.wso2.org" service
     * by the Apache Axis2/C version: #axisVersion# #today#
     * axis2_skel_ExchangeTrader Axis2/C skeleton for the axisService- Header file
     */


	#include <axis2_svc_skeleton.h>
	#include <axutil_log_default.h>
	#include <axutil_error_default.h>
	#include <axiom_text.h>
	#include <axiom_node.h>
	#include <axiom_element.h>
    #include <stdio.h>


   
     #include "axis2_buyRequest_ex.h"
    
     #include "axis2_loginRequest.h"
    
     #include  "axis2_registerClientResponse.h"
    
     #include "axis2_registerClientRequest.h"
    
     #include "axis2_registerFeedTargetRequest.h"
    
     #include "axis2_sellRequest_ex.h"
    

		 
        /**
         * auto generated function declaration
         * for "buy|http://www.wso2.org" operation.
         
         * @param buyRequest_ex
         */
        axis2_status_t  axis2_skel_ExchangeTrader_buy (const axutil_env_t *env  ,
                                          axis2_buyRequest_ex_t* buyRequest_ex );
     

		 
        /**
         * auto generated function declaration
         * for "login|http://www.wso2.org" operation.
         
         * @param loginRequest
         */
        axis2_status_t  axis2_skel_ExchangeTrader_login (const axutil_env_t *env  ,
                                          axis2_loginRequest_t* loginRequest );
     

        axis2_status_t
        axis2_skel_ExchangeTrader_init(
                const axutil_env_t *env);
        

        /**
         * auto generated function declaration
         * for "registerClient|http://www.wso2.org" operation.
         
         * @param registerClientRequest
         */
        axis2_registerClientResponse_t* axis2_skel_ExchangeTrader_registerClient (const axutil_env_t *env  ,
                                          axis2_registerClientRequest_t* registerClientRequest );
     

		 
        /**
         * auto generated function declaration
         * for "registerFeedTarget|http://www.wso2.org" operation.
         
         * @param registerFeedTargetRequest
         */
        axis2_status_t  axis2_skel_ExchangeTrader_registerFeedTarget (const axutil_env_t *env  ,
                                          axis2_registerFeedTargetRequest_t* registerFeedTargetRequest );
     

		 
        /**
         * auto generated function declaration
         * for "sell|http://www.wso2.org" operation.
         
         * @param sellRequest_ex
         */
        axis2_status_t  axis2_skel_ExchangeTrader_sell (const axutil_env_t *env  ,
                                          axis2_sellRequest_ex_t* sellRequest_ex );
     

