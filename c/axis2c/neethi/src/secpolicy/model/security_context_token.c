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



#include <rp_security_context_token.h>

struct rp_security_context_token_t
{
    axis2_char_t *inclusion;
    axis2_bool_t derivedkeys;
    axis2_bool_t require_external_uri_ref;
    axis2_bool_t sc10_security_context_token;
};

AXIS2_EXTERN rp_security_context_token_t *AXIS2_CALL 
rp_security_context_token_create(const axutil_env_t *env)
{
    rp_security_context_token_t *security_context_token = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    security_context_token =  (rp_security_context_token_t *) AXIS2_MALLOC (env->allocator,
    sizeof (rp_security_context_token_t));

    if(security_context_token == NULL)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    security_context_token->inclusion = RP_INCLUDE_ALWAYS;
    security_context_token->derivedkeys = AXIS2_FALSE;
    security_context_token->require_external_uri_ref = AXIS2_FALSE;
    security_context_token->sc10_security_context_token = AXIS2_FALSE;
    
    return security_context_token;

}

AXIS2_EXTERN void AXIS2_CALL 
rp_security_context_token_free(
    rp_security_context_token_t *security_context_token,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    if(security_context_token)
    {
        AXIS2_FREE(env->allocator, security_context_token);
        security_context_token = NULL;
    }
    return;
}


/* Implementations */

AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
rp_security_context_token_get_inclusion(
    rp_security_context_token_t *security_context_token,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
        
    return security_context_token->inclusion;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_security_context_token_set_inclusion(
    rp_security_context_token_t *security_context_token,
    const axutil_env_t *env,
    axis2_char_t *inclusion)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,inclusion,AXIS2_FAILURE);    

    security_context_token->inclusion = inclusion;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL 
rp_security_context_token_get_derivedkeys(
    rp_security_context_token_t *security_context_token,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return security_context_token->derivedkeys;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_security_context_token_set_derivedkeys(
    rp_security_context_token_t *security_context_token,
    const axutil_env_t *env,
    axis2_bool_t derivedkeys)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,derivedkeys,AXIS2_FAILURE);

    security_context_token->derivedkeys = derivedkeys;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL 
rp_security_context_token_get_require_external_uri_ref(
    rp_security_context_token_t *security_context_token,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return security_context_token->require_external_uri_ref;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_security_context_token_set_require_external_uri_ref(
    rp_security_context_token_t *security_context_token,
    const axutil_env_t *env,
    axis2_bool_t require_external_uri_ref)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,require_external_uri_ref,AXIS2_FAILURE);

    security_context_token->require_external_uri_ref = 
            require_external_uri_ref;

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL 
rp_security_context_token_get_sc10_security_context_token(
    rp_security_context_token_t *security_context_token,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return security_context_token->require_external_uri_ref;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_security_context_token_set_sc10_security_context_token(
    rp_security_context_token_t *security_context_token,
    const axutil_env_t *env,
    axis2_bool_t sc10_security_context_token)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,sc10_security_context_token,AXIS2_FAILURE);

    security_context_token->sc10_security_context_token = 
            sc10_security_context_token;

    return AXIS2_SUCCESS;
}
