

    /**
     * axis2_skel_TraderClient.c
     *
     * This file was auto-generated from WSDL for "TraderClient|http://www.wso2.org" service
     * by the Apache Axis2/C version: #axisVersion# #today#
     * axis2_skel_TraderClient Axis2/C skeleton for the axisService
     */

    #include "axis2_skel_TraderClient.h"
    #include <wsf_trader.h>        
     

		 
        /**
         * auto generated function definition signature
         * for "buy|http://www.wso2.org" operation.
         
         * @param buyRequest
         */

        wsf_trader_t *trader;

        
        axis2_status_t
        axis2_skel_TraderClient_init(
                const axutil_env_t *env)
                
        {
            trader = NULL;
            trader = wsf_trader_create(env);            
        
            return AXIS2_SUCCESS;
        }


         axis2_TradeStatus_t *get_trade_status(const axutil_env_t *env,
                                axis2_bool_t status,
                                axis2_char_t *reason);
        

        axis2_buyResponse_t* axis2_skel_TraderClient_buy (const axutil_env_t *env  ,
                                              axis2_buyRequest_t* buyRequest )
        {
          /* TODO fill this with the necessary business logic */
                        
            axis2_char_t *user_name = NULL;
            axis2_char_t *password = NULL;
            axis2_char_t *symbol = NULL;
            int qty = 0;
            axis2_status_t status = AXIS2_SUCCESS;
            axis2_buyResponse_t *buy_response = NULL;
            axis2_TradeStatus_t* trade_status = NULL;

            user_name = axis2_buyRequest_get_userid(buyRequest, env);
            password = axis2_buyRequest_get_password(buyRequest, env);
            symbol = axis2_buyRequest_get_symbol(buyRequest, env);
            qty = axis2_buyRequest_get_qty(buyRequest, env);                                                                                            
            status = wsf_trader_buy(trader, env, user_name, password, symbol, qty);

            buy_response = axis2_buyResponse_create(env);

            if(status == AXIS2_SUCCESS)
            {
                trade_status = get_trade_status(env, AXIS2_TRUE, "Success");
            }
            else
            {
                trade_status = get_trade_status(env, AXIS2_FALSE, "Failure");
            }

            axis2_buyResponse_set_trade_status(buy_response, env, trade_status);

            return buy_response;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "getPortfolio|http://www.wso2.org" operation.
         
         * @param getPortfolioRequest
         */
        axis2_getPortfolioResponse_t* axis2_skel_TraderClient_getPortfolio (const axutil_env_t *env  ,
                                              axis2_getPortfolioRequest_t* getPortfolioRequest )
        {
          /* TODO fill this with the necessary business logic */
          return NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "deposit|http://www.wso2.org" operation.
         
         * @param depositRequest
         */
        axis2_depositResponse_t* axis2_skel_TraderClient_deposit (const axutil_env_t *env  ,
                                              axis2_depositRequest_t* depositRequest )
        {
          /* TODO fill this with the necessary business logic */
          return NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "getSymbols|http://www.wso2.org" operation.
         
         * @param getSymbolsRequest
         */
        axis2_getSymbolsResponse_t* axis2_skel_TraderClient_getSymbols (const axutil_env_t *env  ,
                                              axis2_getSymbolsRequest_t* getSymbolsRequest )
        {
          /* TODO fill this with the necessary business logic */
          return NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "getQuote|http://www.wso2.org" operation.
         
         * @param getQuoteRequest
         */
        axis2_getQuoteResponse_t* axis2_skel_TraderClient_getQuote (const axutil_env_t *env  ,
                                              axis2_getQuoteRequest_t* getQuoteRequest )
        {
          /* TODO fill this with the necessary business logic */
          return NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "createAccount|http://www.wso2.org" operation.
         
         * @param createAccountRequest
         */
        axis2_createAccountResponse_t* axis2_skel_TraderClient_createAccount (const axutil_env_t *env  ,
                                              axis2_createAccountRequest_t* createAccountRequest )
        {
          /* TODO fill this with the necessary business logic */

          axis2_createAccountResponse_t *create_account_response = NULL;
          axis2_char_t *password = NULL;
          axis2_char_t *name = NULL;
          axis2_char_t *ssn = NULL;
          axis2_ClientInfo_t *client_info = NULL;    
          axis2_char_t *user_id = NULL;  

          create_account_response = axis2_createAccountResponse_create(env);

          password = axis2_createAccountRequest_get_password(createAccountRequest, env);

          client_info = axis2_createAccountRequest_get_clientinfo(createAccountRequest, env);

          name = axis2_ClientInfo_get_name(client_info, env);
          ssn = axis2_ClientInfo_get_ssn(client_info, env);

         user_id = wsf_trader_create_account(trader, env, ssn, name, password);      
         
         if(user_id)
         {
            axis2_createAccountResponse_set_userid(create_account_response, env, user_id);       
            return create_account_response;
         }

          return NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "sell|http://www.wso2.org" operation.
         
         * @param sellRequest
         */
        axis2_sellResponse_t* axis2_skel_TraderClient_sell (const axutil_env_t *env  ,
                                              axis2_sellRequest_t* sellRequest )
        {
          /* TODO fill this with the necessary business logic */
            axis2_char_t *user_name = NULL;
            axis2_char_t *password = NULL;
            axis2_char_t *symbol = NULL;
            int qty = 0;
            axis2_status_t status = AXIS2_SUCCESS;
            axis2_sellResponse_t *sell_response = NULL;
            axis2_TradeStatus_t* trade_status = NULL;

            user_name = axis2_sellRequest_get_userid(sellRequest, env);
            password = axis2_sellRequest_get_password(sellRequest, env);
            symbol = axis2_sellRequest_get_symbol(sellRequest, env);
            qty = axis2_sellRequest_get_qty(sellRequest, env);                                                                                            
            status = wsf_trader_sell(trader, env, user_name, password, symbol, qty);

            sell_response = axis2_sellResponse_create(env);

            if(status == AXIS2_SUCCESS)
            {
                trade_status = get_trade_status(env, AXIS2_TRUE, "Success");
            }
            else
            {
                trade_status = get_trade_status(env, AXIS2_FALSE, "Failure");
            }

            axis2_sellResponse_set_trade_status(sell_response, env, trade_status);

            return sell_response;
        }
     

    axis2_TradeStatus_t *get_trade_status(const axutil_env_t *env,
                                axis2_bool_t status,
                                axis2_char_t *reason)
    {
    
        axis2_TradeStatus_t *trade_status = NULL;
        trade_status = axis2_TradeStatus_create(env);
        axis2_TradeStatus_set_status(trade_status, env, status);
        axis2_TradeStatus_set_reason(trade_status, env, reason);

        return trade_status;
    }



