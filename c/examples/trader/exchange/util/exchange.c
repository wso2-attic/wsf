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



#include <wsf_exchange.h>
#include <wsf_util.h>
#include <wsf_client_details.h>

struct wsf_exchange_t
{
    axutil_hash_t *registered_clients;
    axutil_hash_t *market;
    axis2_char_t *my_epr;
    int total_traded;
};




AXIS2_EXTERN wsf_exchange_t *AXIS2_CALL 
wsf_exchange_create(const axutil_env_t *env)
{
    wsf_exchange_t *wsf_exchange = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    wsf_exchange =  (wsf_exchange_t *) AXIS2_MALLOC (env->allocator,
    sizeof (wsf_exchange_t));


    if(wsf_exchange == NULL)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    
    wsf_exchange->registered_clients = NULL;
    wsf_exchange->market = NULL;

    wsf_exchange->market = wsf_create_stock_market(env);
    wsf_exchange->registered_clients = wsf_create_client_data(env);
    
    wsf_exchange->my_epr = "http://localhost:9090/axis2/services/exchangetrader";

    return wsf_exchange;
}

AXIS2_EXTERN void AXIS2_CALL 
wsf_exchange_free(wsf_exchange_t *wsf_exchange,
        const axutil_env_t *env)
{
    if(wsf_exchange)
    {
        AXIS2_FREE(env->allocator, wsf_exchange);
        wsf_exchange = NULL;
    }
    return;
}


/* Implementations */


AXIS2_EXTERN axis2_char_t *AXIS2_CALL
wsf_exchange_register_client(wsf_exchange_t *wsf_exchange,
        const axutil_env_t *env,
        axis2_ClientInfo_t *client_info)
{

    axis2_char_t *name = NULL;
    /*axis2_char_t *password = NULL;*/
    axis2_char_t *ssn = NULL;
    wsf_client_details_t *client_details = NULL;

    name = axis2_ClientInfo_get_name(client_info, env);
    ssn = axis2_ClientInfo_get_ssn(client_info, env);

    if(name && ssn)
    {
        client_details = wsf_client_details_create(env,
                ssn, name, name);
        axutil_hash_set(wsf_exchange->registered_clients, name, AXIS2_HASH_KEY_STRING, client_details);
        return name;
    }    
    return NULL;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
wsf_exchange_buy(wsf_exchange_t *wsf_exchange,
        const axutil_env_t *env,
        int quantity)
{
    wsf_exchange->total_traded =  wsf_exchange->total_traded + quantity;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
wsf_exchange_sell(wsf_exchange_t *wsf_exchange,
        const axutil_env_t *env,
        int quantity)
{
    wsf_exchange->total_traded =  wsf_exchange->total_traded + quantity;
    return AXIS2_SUCCESS;
}

