/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef WSF_TRADER_H
#define WSF_TRADER_H

/** @defgroup wsf_trader_h
 * @ingroup wsf_trader_h
 * @{
 */

#include <axis2_util.h>
#include <wsf_client_details.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct wsf_trader_t wsf_trader_t;

    AXIS2_EXTERN wsf_trader_t *AXIS2_CALL
    wsf_trader_create(const axutil_env_t *env);
    
    AXIS2_EXTERN void AXIS2_CALL
    wsf_trader_free(wsf_trader_t *wsf_trader,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    wsf_trader_create_account(wsf_trader_t *wsf_trader,
        const axutil_env_t *env,
        axis2_char_t *ssn,
        axis2_char_t *name,
        axis2_char_t *password);

    AXIS2_EXTERN wsf_client_details_t *AXIS2_CALL
    wsf_trader_get_client_details(wsf_trader_t *wsf_trader,
        const axutil_env_t *env,
        axis2_char_t *user_name,
        axis2_char_t *password);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    wsf_trader_buy(wsf_trader_t *wsf_trader,
        const axutil_env_t *env,
        axis2_char_t *user_name,
        axis2_char_t *password,
        axis2_char_t *symbol,
        int qty);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    wsf_trader_sell(wsf_trader_t *wsf_trader,
        const axutil_env_t *env,
        axis2_char_t *user_name,
        axis2_char_t *password,
        axis2_char_t *symbol,
        int qty);
    

#ifdef __cplusplus
}
#endif
#endif
