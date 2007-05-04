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

/**
 * axis2_skel_StockQuoteService.c
 *
 * This file was auto-generated from WSDL for "StockQuoteService|http://w3.ibm.com/schemas/services/2002/11/15/stockquote/wsdl" service
 * by the Apache Axis2/C version: #axisVersion# #today#
 * axis2_skel_StockQuoteService Axis2/C skeleton for the axisService
 */

#include "axis2_skel_StockQuoteService.h"

/**
 * auto generated function definition signature
 * for "getStockQuote|" operation.
         
 * @param getStockQuote
 */
axis2_getStockQuoteResponse_t* axis2_skel_StockQuoteService_getStockQuote (const axutil_env_t *env, 
																		   axis2_getStockQuote_t* getStockQuote )
{
	/* TODO fill this with the necessary business logic */
	axis2_char_t *symbol_in = NULL;

	axis2_getStockQuoteResponse_t *response = NULL;
	axis2_quote_t *res_quote = NULL;
	axis2_changeType_t *res_change = NULL;
	axis2_lastTradeType_t *res_last_trade = NULL;
	
	symbol_in = AXIS2_GETSTOCKQUOTE_GET_SYMBOL(getStockQuote, env);
	if(!symbol_in)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_SVC_SKEL_INPUT_OM_NODE_NULL, AXIS2_FAILURE);
        printf("StockQuoteService client request ERROR: input parameter NULL\n");
        return NULL;
	}
	
	res_quote = axis2_quote_create(env);
	AXIS2_QUOTE_SET_SYMBOL(res_quote, env, symbol_in);
	AXIS2_QUOTE_SET_VOLUME(res_quote, env, 1000);

	res_change = axis2_changeType_create(env);
	AXIS2_CHANGETYPE_SET_PERCENT(res_change, env, 10);
	AXIS2_CHANGETYPE_SET_DOLLAR(res_change, env, 98);
	
	AXIS2_QUOTE_SET_CHANGE(res_quote, env, res_change);

	res_last_trade = axis2_lastTradeType_create(env);
	AXIS2_LASTTRADETYPE_SET_PRICE(res_last_trade, env, 23);
	AXIS2_LASTTRADETYPE_SET_DATE(res_last_trade, env, 1165997291);
	
	AXIS2_QUOTE_SET_LASTTRADE(res_quote, env, res_last_trade);

	response = axis2_getStockQuoteResponse_create(env);
	AXIS2_GETSTOCKQUOTERESPONSE_SET_RETURNQUOTE(response, env, res_quote);

	return response;
}
     



















