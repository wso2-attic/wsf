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



#include <wsf_util.h>
#include <axis2_StockQuote.h>
#include <wsf_client_details.h>

AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
wsf_create_stock_market(
        const axutil_env_t *env)
{

    axutil_hash_t *market = NULL;

    axis2_char_t *symbol [] =
            {("aa"),("bb"),("cc"),("dd")};

    axis2_char_t *symbol_name [] =
            {("IBM"),("WSO2"),("MICROSOFT"),("SUN")};

    int i = 0;
    
    market = axutil_hash_make(env);

    for(i=0; i<array_sizeof(symbol); i++)
    {
        axis2_StockQuote_t *stock_quote = NULL;
        stock_quote = axis2_StockQuote_create(env);

        axis2_StockQuote_set_name(stock_quote, env, symbol_name[i]);
        axis2_StockQuote_set_symbol(stock_quote, env, symbol[i]);
        axis2_StockQuote_set_price(stock_quote, env, i*100);

        axutil_hash_set(market, symbol[i], AXIS2_HASH_KEY_STRING, stock_quote);
    }

    return market;
}


AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
wsf_create_client_data(
        const axutil_env_t *env)
{

    axutil_hash_t *client_data = NULL;

    axis2_char_t *ssn [] =
            {("11"),("22"),("33"),("44")};

    axis2_char_t *name [] =
            {("manjula"),("kau"),("samisa"),("dimuthu")};

    int i = 0;
    
    client_data = axutil_hash_make(env);

    for(i=0; i<array_sizeof(ssn); i++)
    {
        wsf_client_details_t *client_details = NULL;
        client_details = wsf_client_details_create(env, ssn[i], name[i], name[i]); /*password is same as the username*/

        axutil_hash_set(client_data, name[i], AXIS2_HASH_KEY_STRING, client_details);
    }

    return client_data;
}

