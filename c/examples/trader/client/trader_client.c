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

#include "axis2_stub_TraderClient.h"
#include "axis2_stub_ExchangeClient.h"
#include <stdio.h>
#include <axiom.h>
#include <axis2_util.h>
#include <axiom_soap.h>
#include <axis2_client.h>
#include <wsf_trader_types.h>


axis2_status_t 
create_account(const axutil_env_t *env,
        axis2_char_t *user,
        axis2_char_t *password,
        axis2_char_t *epr,
        axis2_char_t *client_home);

axis2_status_t 
buy(const axutil_env_t *env,
        axis2_char_t *user,
        axis2_char_t *password,
        axis2_char_t *symbol,
        axis2_char_t *qty,
        axis2_char_t *epr,
        axis2_char_t *client_home);

axis2_status_t 
sell(const axutil_env_t *env,
        axis2_char_t *user,
        axis2_char_t *password,
        axis2_char_t *symbol,
        axis2_char_t *qty,
        axis2_char_t *epr,
        axis2_char_t *client_home);



int main(int argc, char** argv)
{
    /*axis2_stub_t *stub = NULL;*/
    /*axiom_node_t *node = NULL;*/
    axis2_status_t status = AXIS2_FAILURE;
    const axutil_env_t *env = NULL;
    axis2_char_t *address = NULL;
    axis2_char_t *client_home = NULL;
    /*axiom_node_t *ret_node = NULL;*/
    axis2_char_t *operation = NULL;

    env = axutil_env_create_all("trader_client.log", AXIS2_LOG_LEVEL_TRACE);

    client_home = getenv("WSFC_HOME");
    if (!(client_home))
    {
#ifdef WSFC_PREFIX
        client_home = WSFC_PREFIX;
        if (!client_home)
        {
#endif
            printf ("WSFC_HOME environment variable not set properly. Please recheck.\n");
            AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
                "[wsclient] WSFC_HOME is empty");
            return 0;
#ifdef WSFC_PREFIX
        }
        else
            AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
                "WSFC_HOME environment variable not set properly. Using %s as WSFC_HOME.\n", client_home);
#endif
    }

    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
        "[wsclient] WSFC_HOME %s", client_home);
    
    
    address = "http://localhost:9090/axis2/services/traderclient";
    if (argc > 1)
        operation = argv[1];

    else
    {
        printf("Type ./trader -h for usage\n");
        return 0;
    }    

    if (axutil_strcmp(operation, "-h") == 0)
    {
        printf("Usage : %s [create-account] [username] [password] [endpoint_url]\n", argv[0]);
        printf("Usage : %s [buy] [username] [password] [symbol] [quantity] [endpoint_url]\n", argv[0]);
        printf("Usage : %s [sell] [username] [password] [symbol] [quantity] [endpoint_url]\n", argv[0]);
        printf("use -h for help\n");
        printf("NOTE: command line arguments must appear in given order, with trailing ones being optional\n");
        return 0;
    }

    printf("Using endpoint : %s\n", address);

    if(axutil_strcmp(operation, "create-account") == 0)
    {
        if(argc < 4)
        {
            printf("Some arguments are missing\n .use -h for help\n");   
            return 0;
        }  
        else if(argc > 4)
        {    
            address = argv[4]; 
        }    
        status = create_account(env, argv[2], argv[3], address, client_home);
    }    
    else if(axutil_strcmp(operation, "buy") == 0)
    {
        if(argc < 6)
        {
            printf("Some arguments are missing\n .use -h for help\n");
            return 0;
        }
        else if(argc > 6)
        {    
            address = argv[6];    
        }    
        status = buy(env, argv[2], argv[3], argv[4], argv[5], address, client_home);
    }    
    else if(axutil_strcmp(operation, "sell") == 0)
    {
        if(argc < 6)
        {
            printf("Some arguments are missing\n .use -h for help\n");
            return 0;
        }
        else if(argc > 6)
        {
            address = argv[6];
        }    
        status = sell(env, argv[2], argv[3], argv[4], argv[5], address, client_home);
    }    

    else
    {
        printf("Unknown operation \n");
    }
    
    if(status != AXIS2_SUCCESS)
    {
        printf("Trader-Client invoke failed\n");
    }
    else
    {
        printf("Trader-Client invoke Successful\n");
    }
    if (env)
    {
        axutil_env_free((axutil_env_t *) env);
        env = NULL;
    }
    
    return status;
}


axis2_status_t 
create_account(const axutil_env_t *env,
        axis2_char_t *user,
        axis2_char_t *password,
        axis2_char_t *epr,
        axis2_char_t *client_home)
{
    axis2_createAccountRequest_t *create_account_req = NULL;
    axis2_ClientInfo_t *client_info = NULL;
    axis2_createAccountResponse_t *create_account_resp = NULL;
    axis2_stub_t *trader_client = NULL;

    client_info = axis2_ClientInfo_create(env);
    create_account_req = axis2_createAccountRequest_create(env);

    axis2_ClientInfo_set_name(client_info, env, user);
    axis2_ClientInfo_set_ssn(client_info, env, "11111");
    axis2_createAccountRequest_set_clientinfo(create_account_req, 
            env, client_info);
    axis2_createAccountRequest_set_password(create_account_req,
            env, password);

    trader_client = axis2_stub_TraderClient_create(env, client_home, epr);

    if (trader_client)
    {
        create_account_resp = axis2_stub_TraderClient_createAccount(
            trader_client, env, create_account_req);
    }
    
    if(create_account_resp)
    {
        printf("RESULTS : Your User id is %s\n", axis2_createAccountResponse_get_userid(create_account_resp, env));
        return AXIS2_SUCCESS;
    }
    else
        return AXIS2_FAILURE;     

}

axis2_status_t 
buy(const axutil_env_t *env,
        axis2_char_t *user,
        axis2_char_t *password,
        axis2_char_t *symbol,
        axis2_char_t *qty,
        axis2_char_t *epr,
        axis2_char_t *client_home)
{

    axis2_buyRequest_t *buy_request = NULL;
    axis2_buyResponse_t *buy_response = NULL;
    axis2_stub_t *trader_client = NULL;

    buy_request = axis2_buyRequest_create(env);

    axis2_buyRequest_set_userid(buy_request, env, user);
    axis2_buyRequest_set_password(buy_request, env, password);
    axis2_buyRequest_set_symbol(buy_request, env, symbol);    
    axis2_buyRequest_set_qty(buy_request, env, axutil_atoi(qty));
    
    trader_client = axis2_stub_TraderClient_create(env, client_home, epr);

    buy_response = axis2_stub_TraderClient_buy(trader_client, env, buy_request);
    if(buy_response)
    {
        axis2_TradeStatus_t *trade_status = NULL;
        trade_status = axis2_buyResponse_get_trade_status(buy_response, env);
        if(trade_status)
        {
            printf("RESULTS : %s\n", axis2_TradeStatus_get_reason(trade_status, env));
            if(axis2_TradeStatus_get_status(trade_status, env))
                return AXIS2_SUCCESS;
            else
                return AXIS2_FAILURE;
        }
        else 
            return AXIS2_FAILURE;
    }
    else
        return AXIS2_FAILURE;
}

axis2_status_t 
sell(const axutil_env_t *env,
        axis2_char_t *user,
        axis2_char_t *password,
        axis2_char_t *symbol,
        axis2_char_t *qty,
        axis2_char_t *epr,
        axis2_char_t *client_home)
{
    axis2_sellRequest_t *sell_request = NULL;
    axis2_sellResponse_t *sell_response = NULL;
    axis2_stub_t *trader_client = NULL;

    sell_request = axis2_sellRequest_create(env);

    axis2_sellRequest_set_userid(sell_request, env, user);
    axis2_sellRequest_set_password(sell_request, env, password);
    axis2_sellRequest_set_symbol(sell_request, env, symbol);    
    axis2_sellRequest_set_qty(sell_request, env, axutil_atoi(qty));
    
    trader_client = axis2_stub_TraderClient_create(env, client_home, epr);

    sell_response = axis2_stub_TraderClient_sell(trader_client, env, sell_request);
    if(sell_response)
    {
        axis2_TradeStatus_t *trade_status = NULL;
        trade_status = axis2_sellResponse_get_trade_status(sell_response, env);
        if(trade_status)
        {
            printf("RESULTS : %s\n", axis2_TradeStatus_get_reason(trade_status, env));
            if(axis2_TradeStatus_get_status(trade_status, env))
                return AXIS2_SUCCESS;
            else
                return AXIS2_FAILURE;
        }
        else 
            return AXIS2_FAILURE;
    }
    else
        return AXIS2_FAILURE;
}
