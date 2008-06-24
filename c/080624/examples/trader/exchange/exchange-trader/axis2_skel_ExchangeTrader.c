

    /**
     * axis2_skel_ExchangeTrader.c
     *
     * This file was auto-generated from WSDL for "ExchangeTrader|http://www.wso2.org" service
     * by the Apache Axis2/C version: #axisVersion# #today#
     * axis2_skel_ExchangeTrader Axis2/C skeleton for the axisService
     */

     #include "axis2_skel_ExchangeTrader.h"
     #include <wsf_exchange.h>   
     
        wsf_exchange_t *exchange;


        axis2_status_t
        axis2_skel_ExchangeTrader_init(
                const axutil_env_t *env)

        {
            exchange = NULL;
            exchange = wsf_exchange_create(env);

            return AXIS2_SUCCESS;
        }
        
		 
        /**
         * auto generated function definition signature
         * for "buy|http://www.wso2.org" operation.
         
         * @param buyRequest_ex
         */
        axis2_status_t  axis2_skel_ExchangeTrader_buy (const axutil_env_t *env  ,
                                              axis2_buyRequest_ex_t* buyRequest_ex )
        {
          /* TODO fill this with the necessary business logic */
        
            int qty = axis2_buyRequest_ex_get_qty(buyRequest_ex, env);
            return wsf_exchange_buy(exchange, env, qty);
    
        }
     

		 
        /**
         * auto generated function definition signature
         * for "login|http://www.wso2.org" operation.
         
         * @param loginRequest
         */
        axis2_status_t  axis2_skel_ExchangeTrader_login (const axutil_env_t *env  ,
                                              axis2_loginRequest_t* loginRequest )
        {
          /* TODO fill this with the necessary business logic */
          return AXIS2_SUCCESS;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "registerClient|http://www.wso2.org" operation.
         
         * @param registerClientRequest
         */
        axis2_registerClientResponse_t* axis2_skel_ExchangeTrader_registerClient (const axutil_env_t *env  ,
                                              axis2_registerClientRequest_t* registerClientRequest )
        {
          /* TODO fill this with the necessary business logic */

            axis2_char_t *user_id = NULL;
            axis2_ClientInfo_t *client_info = NULL;
            axis2_registerClientResponse_t *response = NULL;

            client_info = axis2_registerClientRequest_get_ClientInfo(
                    registerClientRequest, env);

            if(client_info)
            {
                user_id = wsf_exchange_register_client(exchange, env, client_info);
                if(user_id)
                {
                    response = axis2_registerClientResponse_create(env);
                    axis2_registerClientResponse_set_userid(response, env, user_id);
                    return response;
                }    
                else 
                    return NULL;    
            }    
            return NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "registerFeedTarget|http://www.wso2.org" operation.
         
         * @param registerFeedTargetRequest
         */
        axis2_status_t  axis2_skel_ExchangeTrader_registerFeedTarget (const axutil_env_t *env  ,
                                              axis2_registerFeedTargetRequest_t* registerFeedTargetRequest )
        {
          /* TODO fill this with the necessary business logic */
          return AXIS2_SUCCESS;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "sell|http://www.wso2.org" operation.
         
         * @param sellRequest_ex
         */
        axis2_status_t  axis2_skel_ExchangeTrader_sell (const axutil_env_t *env  ,
                                              axis2_sellRequest_ex_t* sellRequest_ex )
        {
          /* TODO fill this with the necessary business logic */
            int qty = axis2_sellRequest_ex_get_qty(sellRequest_ex, env);
            return wsf_exchange_sell(exchange, env, qty);
        }
     

