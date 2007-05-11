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



#include <rp_wss10.h>

struct rp_wss10_t
{
    axis2_bool_t must_support_ref_key_identifier;
    axis2_bool_t must_support_ref_issuer_serial;
    axis2_bool_t must_support_ref_external_uri;
    axis2_bool_t must_support_ref_embedded_token;
    axis2_bool_t must_support_direct_reference;
};

AXIS2_EXTERN rp_wss10_t *AXIS2_CALL
rp_wss10_create(const axutil_env_t *env)
{
    rp_wss10_t *wss10 = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    wss10 =  (rp_wss10_t *) AXIS2_MALLOC (env->allocator,
    sizeof (rp_wss10_t));

    if(wss10 == NULL)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    wss10->must_support_ref_key_identifier = AXIS2_FALSE;
    wss10->must_support_ref_issuer_serial  = AXIS2_FALSE;
    wss10->must_support_ref_external_uri = AXIS2_FALSE;
    wss10->must_support_ref_embedded_token = AXIS2_FALSE;
    wss10->must_support_direct_reference = AXIS2_TRUE;

    return wss10;

}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_wss10_free(rp_wss10_t *wss10,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    if(wss10)
    {
        AXIS2_FREE(env->allocator, wss10);
        wss10 = NULL;
    }
    return AXIS2_SUCCESS;
}


/* Implementations */
AXIS2_EXTERN axis2_bool_t AXIS2_CALL 
rp_wss10_get_must_support_ref_key_identifier(rp_wss10_t *wss10,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
        
    return wss10->must_support_ref_key_identifier;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_wss10_set_must_support_ref_key_identifier(rp_wss10_t *wss10,
            const axutil_env_t *env,
            axis2_bool_t must_support_ref_key_identifier)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,must_support_ref_key_identifier,AXIS2_FAILURE);    
    wss10->must_support_ref_key_identifier = must_support_ref_key_identifier;

    return AXIS2_SUCCESS;
    
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL 
rp_wss10_get_must_support_ref_issuer_serial(rp_wss10_t *wss10,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    
    return wss10->must_support_ref_issuer_serial;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_wss10_set_must_support_ref_issuer_serial(rp_wss10_t *wss10,
            const axutil_env_t *env,
            axis2_bool_t must_support_ref_issuer_serial)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,must_support_ref_issuer_serial,AXIS2_FAILURE);    
    wss10->must_support_ref_issuer_serial = must_support_ref_issuer_serial;

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL 
rp_wss10_get_must_support_ref_external_uri(rp_wss10_t *wss10,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    
    return wss10->must_support_ref_external_uri;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_wss10_set_must_support_ref_external_uri(rp_wss10_t *wss10,
            const axutil_env_t *env,
            axis2_bool_t must_support_ref_external_uri)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,must_support_ref_external_uri,AXIS2_FAILURE);    
    wss10->must_support_ref_external_uri = must_support_ref_external_uri;

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL 
rp_wss10_get_must_support_ref_embedded_token(rp_wss10_t *wss10,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
        
    return wss10->must_support_ref_embedded_token;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_wss10_set_must_support_ref_embedded_token(rp_wss10_t *wss10,
            const axutil_env_t *env,
            axis2_bool_t must_support_ref_embedded_token)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,must_support_ref_embedded_token,AXIS2_FAILURE);    
    wss10->must_support_ref_embedded_token = must_support_ref_embedded_token;

    return AXIS2_SUCCESS;
}

