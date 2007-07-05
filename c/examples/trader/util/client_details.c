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



#include <wsf_client_details.h>

struct wsf_client_details_t
{

    axis2_char_t *ssn;
    axis2_char_t *name;
    axis2_char_t *password;
    double credit;
    axutil_hash_t *stock_holdings;

};

AXIS2_EXTERN wsf_client_details_t *AXIS2_CALL 
wsf_client_details_create(
        const axutil_env_t *env,
        axis2_char_t *ssn,
        axis2_char_t *name,
        axis2_char_t *password)
{
    wsf_client_details_t *wsf_client_details = NULL;
    int *phold = (int*) malloc(sizeof(int));
    *phold = 5;

    AXIS2_ENV_CHECK(env, NULL);

    wsf_client_details =  (wsf_client_details_t *) AXIS2_MALLOC (env->allocator,
    sizeof (wsf_client_details_t));


    if(wsf_client_details == NULL)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    
    wsf_client_details->ssn = axutil_strdup(env,ssn);
    wsf_client_details->name = axutil_strdup(env, name);
    wsf_client_details->password = axutil_strdup(env, password);
    wsf_client_details->credit = 10000;
    wsf_client_details->stock_holdings = NULL;
    wsf_client_details->stock_holdings = axutil_hash_make(env);
    axutil_hash_set(wsf_client_details->stock_holdings, "aa", AXIS2_HASH_KEY_STRING, phold);
    
    return wsf_client_details;
}

AXIS2_EXTERN void AXIS2_CALL 
wsf_client_details_free(wsf_client_details_t *wsf_client_details,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    if(wsf_client_details)
    {
        AXIS2_FREE(env->allocator, wsf_client_details);
        wsf_client_details = NULL;
    }
    return;
}


/* Implementations */

AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
wsf_client_details_get_ssn(wsf_client_details_t *wsf_client_details,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
        
    return wsf_client_details->ssn;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
wsf_client_details_set_ssn(wsf_client_details_t *wsf_client_details,
            const axutil_env_t *env,
            axis2_char_t *ssn)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    wsf_client_details->ssn= ssn;

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
wsf_client_details_get_name(wsf_client_details_t *wsf_client_details,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    return wsf_client_details->name;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
wsf_client_details_set_name(wsf_client_details_t *wsf_client_details,
            const axutil_env_t *env,
            axis2_char_t *name)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    wsf_client_details->name = name;

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
wsf_client_details_get_password(wsf_client_details_t *wsf_client_details,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    return wsf_client_details->password;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
wsf_client_details_set_password(wsf_client_details_t *wsf_client_details,
            const axutil_env_t *env,
            axis2_char_t *password)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    wsf_client_details->password = password;

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN double AXIS2_CALL
wsf_client_details_get_credit(wsf_client_details_t *wsf_client_details,
                    const axutil_env_t *env)
{
        AXIS2_ENV_CHECK(env, NULL);

        return wsf_client_details->credit;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
wsf_client_details_set_credit(wsf_client_details_t *wsf_client_details,
            const axutil_env_t *env,
            double credit)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    wsf_client_details->credit = credit;

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
wsf_client_details_get_stock_holdings(wsf_client_details_t *wsf_client_details,
                    const axutil_env_t *env)
{
        AXIS2_ENV_CHECK(env, NULL);

        return wsf_client_details->stock_holdings;
}
