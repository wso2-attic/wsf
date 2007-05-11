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



#include <rp_symmetric_asymmetric_binding_commons.h>

struct rp_symmetric_asymmetric_binding_commons_t
{
    rp_binding_commons_t *binding_commons;
    axis2_char_t *protection_order;
    axis2_bool_t signature_protection;
    axis2_bool_t token_protection;
    axis2_bool_t entire_headers_and_body_signatures;

};

AXIS2_EXTERN rp_symmetric_asymmetric_binding_commons_t *AXIS2_CALL 
rp_symmetric_asymmetric_binding_commons_create(const axutil_env_t *env)
{
    rp_symmetric_asymmetric_binding_commons_t *symmetric_asymmetric_binding_commons = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    symmetric_asymmetric_binding_commons =  (rp_symmetric_asymmetric_binding_commons_t *)
        AXIS2_MALLOC (env->allocator,sizeof (rp_symmetric_asymmetric_binding_commons_t));

    if(symmetric_asymmetric_binding_commons == NULL)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    symmetric_asymmetric_binding_commons->binding_commons = NULL;
    symmetric_asymmetric_binding_commons->protection_order = RP_SIGN_BEFORE_ENCRYPTING;
    symmetric_asymmetric_binding_commons->signature_protection = AXIS2_FALSE;
    symmetric_asymmetric_binding_commons->token_protection = AXIS2_FALSE;
    symmetric_asymmetric_binding_commons->entire_headers_and_body_signatures = AXIS2_FALSE;

    return symmetric_asymmetric_binding_commons;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_symmetric_asymmetric_binding_commons_free(
    rp_symmetric_asymmetric_binding_commons_t *symmetric_asymmetric_binding_commons,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    if(symmetric_asymmetric_binding_commons)
    {
        if(symmetric_asymmetric_binding_commons->binding_commons)
        {
            rp_binding_commons_free(symmetric_asymmetric_binding_commons->binding_commons,env);
            symmetric_asymmetric_binding_commons->binding_commons = NULL;
        }            
        AXIS2_FREE(env->allocator,symmetric_asymmetric_binding_commons);
        symmetric_asymmetric_binding_commons = NULL;
    }
    return AXIS2_SUCCESS;
}


/* Implementations */
AXIS2_EXTERN rp_binding_commons_t *AXIS2_CALL
rp_symmetric_asymmetric_binding_commons_get_binding_commons(
    rp_symmetric_asymmetric_binding_commons_t *symmetric_asymmetric_binding_commons,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
        
    return symmetric_asymmetric_binding_commons->binding_commons;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_symmetric_asymmetric_binding_commons_set_binding_commons(
    rp_symmetric_asymmetric_binding_commons_t *symmetric_asymmetric_binding_commons,
    const axutil_env_t *env,
    rp_binding_commons_t *binding_commons)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,binding_commons,AXIS2_FAILURE);   
        
    symmetric_asymmetric_binding_commons->binding_commons=binding_commons;    
    return AXIS2_SUCCESS;
}



AXIS2_EXTERN axis2_bool_t AXIS2_CALL 
rp_symmetric_asymmetric_binding_commons_get_signature_protection(
    rp_symmetric_asymmetric_binding_commons_t *symmetric_asymmetric_binding_commons,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    
    return symmetric_asymmetric_binding_commons->signature_protection;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_symmetric_asymmetric_binding_commons_set_signature_protection(
    rp_symmetric_asymmetric_binding_commons_t *symmetric_asymmetric_binding_commons,
    const axutil_env_t *env,
    axis2_bool_t signature_protection)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,signature_protection,AXIS2_FAILURE);    
    symmetric_asymmetric_binding_commons->signature_protection = signature_protection;

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL 
rp_symmetric_asymmetric_binding_commons_get_token_protection(
    rp_symmetric_asymmetric_binding_commons_t *symmetric_asymmetric_binding_commons,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    
    return symmetric_asymmetric_binding_commons->token_protection;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_symmetric_asymmetric_binding_commons_set_token_protection(
    rp_symmetric_asymmetric_binding_commons_t *symmetric_asymmetric_binding_commons,
    const axutil_env_t *env,
    axis2_bool_t token_protection)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,token_protection,AXIS2_FAILURE);

    symmetric_asymmetric_binding_commons->token_protection = token_protection;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL 
rp_symmetric_asymmetric_binding_commons_get_entire_headers_and_body_signatures(
    rp_symmetric_asymmetric_binding_commons_t *symmetric_asymmetric_binding_commons,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    
    return symmetric_asymmetric_binding_commons->entire_headers_and_body_signatures;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_symmetric_asymmetric_binding_commons_set_entire_headers_and_body_signatures(
    rp_symmetric_asymmetric_binding_commons_t *symmetric_asymmetric_binding_commons,
    const axutil_env_t *env,
    axis2_bool_t entire_headers_and_body_signatures)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,entire_headers_and_body_signatures,AXIS2_FAILURE);

    symmetric_asymmetric_binding_commons->entire_headers_and_body_signatures = 
        entire_headers_and_body_signatures;

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
rp_symmetric_asymmetric_binding_commons_get_protection_order(
    rp_symmetric_asymmetric_binding_commons_t *symmetric_asymmetric_binding_commons,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    
    return symmetric_asymmetric_binding_commons->protection_order;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_symmetric_asymmetric_binding_commons_set_protection_order(
    rp_symmetric_asymmetric_binding_commons_t *symmetric_asymmetric_binding_commons,
    const axutil_env_t *env,
    axis2_char_t *protection_order)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,protection_order,AXIS2_FAILURE);
    
    symmetric_asymmetric_binding_commons->protection_order = protection_order;    
    return AXIS2_SUCCESS;
}

