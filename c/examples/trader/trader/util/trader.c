/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */



#include <wsf_trader.h>
#include <wsf_util.h>
#include <axis2_stub_ExchangeTrader.h>
#include <wsf_trader_types.h>

struct wsf_trader_t
{
    axutil_hash_t *client_data;
    axutil_hash_t *stock_market;
    axis2_char_t *exchange_epr;
    axis2_char_t *my_epr;
    axis2_char_t *client_home;    
    
};



AXIS2_EXTERN wsf_trader_t *AXIS2_CALL 
wsf_trader_create(const axutil_env_t *env)
{
    wsf_trader_t *wsf_trader = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    wsf_trader =  (wsf_trader_t *) AXIS2_MALLOC (env->allocator,
    sizeof (wsf_trader_t));


    if(wsf_trader == NULL)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    
    wsf_trader->client_data = NULL;
    wsf_trader->stock_market = NULL;   

    wsf_trader->stock_market = wsf_create_stock_market(env);
    wsf_trader->client_data = wsf_create_client_data(env);

    wsf_trader->exchange_epr = "http://localhost:9090/axis2/services/exchangetrader";
    wsf_trader->my_epr = "http://localhost:9090/axis2/services/traderclient";

    wsf_trader->client_home = AXIS2_GETENV("WSFC_HOME");
    if (!(wsf_trader->client_home))
    {
#ifdef WSFC_PREFIX
        wsf_trade->client_home = WSFC_PREFIX;
        if (!(wsf_trader->client_home))
        {
#endif
            printf ("WSFC_HOME environment variable not set properly. Please recheck.\n");
            AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
                "[wsclient] WSFC_HOME is empty");
            return NULL;
#ifdef WSFC_PREFIX
        }
        else
            AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
                "WSFC_HOME environment variable not set properly. Using %s as WSFC_HOME.\n", client_home);
#endif
    }

    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
        "[wsclient] WSFC_HOME %s", wsf_trader->client_home);

    return wsf_trader;
}

AXIS2_EXTERN void AXIS2_CALL 
wsf_trader_free(wsf_trader_t *wsf_trader,
        const axutil_env_t *env)
{
    if(wsf_trader)
    {
        AXIS2_FREE(env->allocator, wsf_trader);
        wsf_trader = NULL;
    }
    return;
}


/* Implementations */



AXIS2_EXTERN axis2_char_t *AXIS2_CALL
wsf_trader_create_account(wsf_trader_t *wsf_trader,
        const axutil_env_t *env,
        axis2_char_t *ssn,
        axis2_char_t *name,
        axis2_char_t *password)
{

    wsf_client_details_t *client_details = NULL;
    axis2_stub_t *exchange_trader_stub = NULL;
    axis2_ClientInfo_t *client_info = NULL;
    axis2_registerClientRequest_t *reg_client_request = NULL;
    axis2_registerClientResponse_t *reg_client_response = NULL;

	AXIS2_PARAM_CHECK(env->error, wsf_trader, NULL);

    client_details = wsf_client_details_create(env,
                ssn, name, password);

    if(client_details)
    {
        
        axutil_hash_set(wsf_trader->client_data, axutil_strdup(env, name), AXIS2_HASH_KEY_STRING, client_details);
    }
    
    exchange_trader_stub = axis2_stub_ExchangeTrader_create(env,
                wsf_trader->client_home, wsf_trader->exchange_epr);    

    if(exchange_trader_stub)
    {
        reg_client_request = axis2_registerClientRequest_create(env);
        client_info = axis2_ClientInfo_create(env);
        axis2_ClientInfo_set_name(client_info, env, name);
        axis2_ClientInfo_set_ssn(client_info, env, ssn);
        axis2_registerClientRequest_set_ClientInfo(reg_client_request, env, client_info);
        
        reg_client_response = axis2_stub_ExchangeTrader_registerClient(
                                exchange_trader_stub, env, reg_client_request);
        if(reg_client_response)
        {
            return axis2_registerClientResponse_get_userid(reg_client_response, env);
        }
        else
            return NULL;
    }
    else
        return NULL;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
wsf_trader_buy(wsf_trader_t *wsf_trader,
        const axutil_env_t *env,
        axis2_char_t *user_name,
        axis2_char_t *password,
        axis2_char_t *symbol,
        int qty)
{

    wsf_client_details_t *client_details = NULL;
    axis2_StockQuote_t *stock_details = NULL;
    double credit = 0;
    float amount_required = 0;
    axutil_hash_t *stock_holdings = NULL;
    axis2_stub_t *exchange_trader_stub = NULL;
    axis2_buyRequest_ex_t *buy_request = NULL;

	AXIS2_PARAM_CHECK(env->error, wsf_trader, AXIS2_FAILURE);

    client_details = wsf_trader_get_client_details(wsf_trader,
            env, user_name, password);


    if(!client_details)
    {    
        return AXIS2_FAILURE;        
    }

    if(!axutil_hash_contains_key(wsf_trader->stock_market, env, symbol))
    {    
        return AXIS2_FAILURE;
    }
    stock_details = (axis2_StockQuote_t *)axutil_hash_get(wsf_trader->stock_market, 
                symbol, AXIS2_HASH_KEY_STRING);     

    if(!stock_details)
    {    
        return AXIS2_FAILURE;
    }
    credit = wsf_client_details_get_credit(client_details, env);

    amount_required = (axis2_StockQuote_get_price(stock_details, env))*qty;
    
    if(credit < amount_required)
    {
        printf("Not enough credit to complete transaction\n");
        return AXIS2_FAILURE;
    }
    wsf_client_details_set_credit(client_details, env, (credit-amount_required));

    stock_holdings = wsf_client_details_get_stock_holdings(client_details, env); 
    
    if(stock_holdings)
    {
        int *pstock_hold = NULL;
        int new_val = 0;
        if(axutil_hash_contains_key(stock_holdings, env, symbol))
        {
            pstock_hold = (int *)axutil_hash_get(stock_holdings, symbol, AXIS2_HASH_KEY_STRING);

            new_val = (*pstock_hold + qty);            
            *pstock_hold = new_val;

            axutil_hash_set(stock_holdings, symbol, 
                    AXIS2_HASH_KEY_STRING, pstock_hold);
        }   
        else
        {
            pstock_hold = (int*) malloc(sizeof(int));
            axutil_hash_set(stock_holdings, symbol, AXIS2_HASH_KEY_STRING, pstock_hold);
        }
    }
    else 
        return AXIS2_FAILURE;

    exchange_trader_stub = axis2_stub_ExchangeTrader_create(env,
                wsf_trader->client_home, wsf_trader->exchange_epr);

    buy_request = axis2_buyRequest_ex_create(env);

    axis2_buyRequest_ex_set_userid(buy_request, env, user_name);
    axis2_buyRequest_ex_set_symbol(buy_request, env, symbol);
    axis2_buyRequest_ex_set_qty(buy_request, env, qty);
                
    return axis2_stub_ExchangeTrader_buy(exchange_trader_stub, 
                            env, buy_request);

}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
wsf_trader_sell(wsf_trader_t *wsf_trader,
        const axutil_env_t *env,
        axis2_char_t *user_name,
        axis2_char_t *password,
        axis2_char_t *symbol,
        int qty)
{

    wsf_client_details_t *client_details = NULL;
    axutil_hash_t *stock_holdings = NULL;
    axis2_stub_t *exchange_trader_stub = NULL;
    axis2_sellRequest_ex_t *sell_request = NULL;

	AXIS2_PARAM_CHECK(env->error, wsf_trader, AXIS2_FAILURE);

    client_details = wsf_trader_get_client_details(wsf_trader,
            env, user_name, password);

    if(!client_details)
        return AXIS2_FAILURE;        

    if(!axutil_hash_contains_key(wsf_trader->stock_market, env, symbol))
        return AXIS2_FAILURE;


    stock_holdings = wsf_client_details_get_stock_holdings(client_details, env); 
    
    if(stock_holdings)
    {
        int *pstock_hold = NULL;
        int new_val = 0;
        if(axutil_hash_contains_key(stock_holdings, env, symbol))
        {
            pstock_hold = (int *)axutil_hash_get(stock_holdings, symbol, AXIS2_HASH_KEY_STRING);
            if((*pstock_hold) < qty)
            {
                printf("Cannot sell more than you have\n");
                return AXIS2_FAILURE;
            }
            else
            {
                new_val = (*pstock_hold - qty);
                *pstock_hold = new_val;
                axutil_hash_set(stock_holdings, symbol, 
                        AXIS2_HASH_KEY_STRING, pstock_hold);
            }
        }   
        else
        {
            printf("You cannot sell an item you don't have\n");
            return AXIS2_FAILURE;
        }
    }
    else 
        return AXIS2_FAILURE;

    exchange_trader_stub = axis2_stub_ExchangeTrader_create(env,
                wsf_trader->client_home, wsf_trader->exchange_epr);

    sell_request = axis2_sellRequest_ex_create(env);

    axis2_sellRequest_ex_set_userid(sell_request, env, user_name);
    axis2_sellRequest_ex_set_symbol(sell_request, env, symbol);
    axis2_sellRequest_ex_set_qty(sell_request, env, qty);
                
    return axis2_stub_ExchangeTrader_sell(exchange_trader_stub, 
                            env, sell_request);

}


AXIS2_EXTERN wsf_client_details_t *AXIS2_CALL
wsf_trader_get_client_details(wsf_trader_t *wsf_trader,
        const axutil_env_t *env,
        axis2_char_t *user_name,
        axis2_char_t *password)
{

    wsf_client_details_t *client_details = NULL;
    axis2_char_t *pass = NULL;

	AXIS2_PARAM_CHECK(env->error, wsf_trader, AXIS2_FAILURE);

    if(!user_name && !password)
    {
        return NULL;
    }
   

    client_details = (wsf_client_details_t *)axutil_hash_get(wsf_trader->client_data, 
            user_name, AXIS2_HASH_KEY_STRING);

    if(client_details)
    {
        pass = wsf_client_details_get_password(client_details, env);
        if(axutil_strcmp(pass, password)==0)
        {
            return client_details;
        }
        else 
            return NULL;
    }
    else 
    {    
        return NULL;
    }
}


