/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed
 * with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version
 * 2.0
 * (the "License"); you may not use this file except in compliance
 * with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
 * implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "axis2_stub_StockQuoteService.h"
#include <stdio.h>

void
handle_response(axis2_getStockQuoteResponse_t *res, axutil_env_t *env);

int
main(int argc, char *argv[])
{
	axutil_env_t *env = NULL;
	axis2_char_t *client_home = NULL;
	axis2_char_t *endpoint_uri = NULL;
	axis2_stub_t *stub = NULL;
	axis2_char_t *symbol = NULL;

	axis2_getStockQuote_t *req = NULL;

	axis2_getStockQuoteResponse_t *res = NULL;
    
	if(argc > 1)
	{
		symbol = argv[1];		
	}
	else
	{
		printf("\nEnter Symbol Name!");
		return -1;
	}

	endpoint_uri = "http://localhost:9090/axis2/services/StockQuoteService";
	env = axutil_env_create_all("codegen_sample_stock_quote.log", AXIS2_LOG_LEVEL_TRACE);
	/* Set up deploy folder.*/
	client_home = AXIS2_GETENV("AXIS2C_HOME");
	if (!client_home)
		client_home = "../../../deploy";
	
	stub = axis2_stub_StockQuoteService_create(env, client_home, endpoint_uri);

	/* Create the struct */
	req = axis2_getStockQuote_create(env);
	AXIS2_GETSTOCKQUOTE_SET_SYMBOL(req, env, symbol);

	res = axis2_stub_StockQuoteService_getStockQuote(stub, env, req);
    
	if(!res)
	{
		printf("Error: response NULL!\n");
		return -1;
    }
	
	handle_response(res, env); /*Handle Response */

	return 0;
}

void
handle_response(axis2_getStockQuoteResponse_t *res, axutil_env_t *env)
{
	
	axis2_quote_t *quote = NULL;

	axis2_changeType_t *change = NULL;
	axis2_lastTradeType_t *last_trade = NULL;
	
	/*Attributes of Quote*/
	axis2_char_t *symbol_res = NULL;
	int volume = 0;
	
	/*Attributes of Last Trade */
	float price = 0;
	long date = 0;

	/*Attributes of Change*/
	float dollar = 0;
	float precent = 0;
		
	quote = AXIS2_GETSTOCKQUOTERESPONSE_GET_RETURNQUOTE(res, env);
    
    if(!quote)
    {
        printf("Error: Quote response NULL!\n");
        return;
    }
    
	last_trade = AXIS2_QUOTE_GET_LASTTRADE(quote, env);
	change = AXIS2_QUOTE_GET_CHANGE(quote, env);
	symbol_res = AXIS2_QUOTE_GET_SYMBOL(quote, env);
	volume = AXIS2_QUOTE_GET_VOLUME(quote, env);

	price = AXIS2_LASTTRADETYPE_GET_PRICE(last_trade, env);
	date = AXIS2_LASTTRADETYPE_GET_DATE(last_trade, env);

	dollar = AXIS2_CHANGETYPE_GET_DOLLAR(change, env);
	precent = AXIS2_CHANGETYPE_GET_PERCENT(change, env);
	
	printf("\nSTOCK QUOTERESPONSE\n");
	printf("\tSYMBOL\t\t: %s\n", symbol_res);
	printf("\tVOLUME\t\t: %d\n", volume);
	printf("\tPRICE\t\t: %f\n", price);
	printf("\tDATE\t\t: %l\n", date);
	printf("\tDOLLAR\t\t: %f\n", dollar);
	printf("\tPRECENT\t\t: %f\n", precent);
	
}	















