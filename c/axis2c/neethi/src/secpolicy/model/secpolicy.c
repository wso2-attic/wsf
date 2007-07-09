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



#include <rp_secpolicy.h>

struct rp_secpolicy_t
{
    rp_property_t *binding;
    rp_property_t *wss;
    rp_supporting_tokens_t *supporting_tokens;
    rp_supporting_tokens_t *signed_supporting_tokens;
    rp_supporting_tokens_t *endorsing_supporting_tokens;
    rp_supporting_tokens_t *signed_endorsing_supporting_tokens;
    rp_signed_encrypted_parts_t *signed_parts;
    rp_signed_encrypted_parts_t *encrypted_parts;
    rp_signed_encrypted_elements_t *signed_elements;
    rp_signed_encrypted_elements_t *encrypted_elements;
    rp_signed_encrypted_items_t *signed_items;
    rp_signed_encrypted_items_t *encrypted_items;    
    rp_rampart_config_t *rampart_config;
    
};

AXIS2_EXTERN rp_secpolicy_t *AXIS2_CALL 
rp_secpolicy_create(const axutil_env_t *env)
{
    rp_secpolicy_t *secpolicy = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    secpolicy =  (rp_secpolicy_t *) AXIS2_MALLOC (env->allocator,
    sizeof (rp_secpolicy_t));

    if(secpolicy == NULL)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    secpolicy->binding = NULL;
    secpolicy->wss = NULL;
    secpolicy->supporting_tokens = NULL;
    secpolicy->signed_supporting_tokens = NULL;
    secpolicy->endorsing_supporting_tokens = NULL;
    secpolicy->signed_endorsing_supporting_tokens = NULL;
    secpolicy->signed_parts = NULL;
    secpolicy->encrypted_parts = NULL;
    secpolicy->signed_elements = NULL;
    secpolicy->encrypted_elements = NULL;
    secpolicy->signed_items = NULL;
    secpolicy->encrypted_items = NULL;
    secpolicy->rampart_config = NULL;

    return secpolicy;
}

AXIS2_EXTERN void AXIS2_CALL 
rp_secpolicy_free(
    rp_secpolicy_t *secpolicy,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    if(secpolicy)
    {
        if(secpolicy->binding)
        {
            rp_property_free(secpolicy->binding,env);
            secpolicy->binding = NULL;
        }
        if(secpolicy->wss)
        {
            rp_property_free(secpolicy->wss,env);            
            secpolicy->wss = NULL;
        }
        if(secpolicy->supporting_tokens)
        {
            rp_supporting_tokens_free(secpolicy->supporting_tokens,env);
            secpolicy->supporting_tokens = NULL;
        }
        if(secpolicy->signed_supporting_tokens)
        {
            rp_supporting_tokens_free(secpolicy->signed_supporting_tokens,env);
            secpolicy->signed_supporting_tokens = NULL;
        }
        if(secpolicy->endorsing_supporting_tokens)
        {
            rp_supporting_tokens_free(secpolicy->endorsing_supporting_tokens,env);
            secpolicy->endorsing_supporting_tokens = NULL;
        }
        if(secpolicy->signed_endorsing_supporting_tokens)
        {
            rp_supporting_tokens_free(secpolicy->signed_endorsing_supporting_tokens,env);
            secpolicy->signed_endorsing_supporting_tokens = NULL;
        }
        if(secpolicy->signed_parts)
        {
            rp_signed_encrypted_parts_free(secpolicy->signed_parts,env);
            secpolicy->signed_parts = NULL;
        }
        if(secpolicy->encrypted_parts)
        {
            rp_signed_encrypted_parts_free(secpolicy->encrypted_parts,env);
            secpolicy->encrypted_parts = NULL;
        }            
        if(secpolicy->signed_elements)
        {
            rp_signed_encrypted_elements_free(secpolicy->signed_elements,env);
            secpolicy->signed_elements = NULL;
        }            
        if(secpolicy->encrypted_elements)
        {
            rp_signed_encrypted_elements_free(secpolicy->encrypted_elements,env);
            secpolicy->encrypted_elements = NULL;
        }
        if(secpolicy->signed_items)
        {
            rp_signed_encrypted_items_free(secpolicy->signed_items,env);
            secpolicy->signed_items = NULL;
        }            
        if(secpolicy->encrypted_items)
        {
            rp_signed_encrypted_items_free(secpolicy->encrypted_items,env);
            secpolicy->encrypted_items = NULL;
        }
        if(secpolicy->rampart_config)
        {
            rp_rampart_config_free(secpolicy->rampart_config,env);
            secpolicy->rampart_config = NULL;
        }            
        AXIS2_FREE(env->allocator,secpolicy);           
    }

    return;
}


/* Implementations */
AXIS2_EXTERN rp_property_t *AXIS2_CALL
rp_secpolicy_get_binding(
    rp_secpolicy_t *secpolicy,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return secpolicy->binding;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_secpolicy_set_binding(
    rp_secpolicy_t *secpolicy,
    const axutil_env_t *env,
    rp_property_t *binding)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,binding,AXIS2_FAILURE);
    
    secpolicy->binding = binding; 
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_secpolicy_set_supporting_tokens(
    rp_secpolicy_t *secpolicy,
    const axutil_env_t *env,
    rp_supporting_tokens_t *supporting_tokens)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,supporting_tokens,AXIS2_FAILURE);
    
    secpolicy->supporting_tokens = supporting_tokens; 
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN rp_supporting_tokens_t *AXIS2_CALL
rp_secpolicy_get_supporting_tokens(
    rp_secpolicy_t *secpolicy,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
        
    return secpolicy->supporting_tokens;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_secpolicy_set_signed_supporting_tokens(
    rp_secpolicy_t *secpolicy,
    const axutil_env_t *env,
    rp_supporting_tokens_t *signed_supporting_tokens)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,signed_supporting_tokens,AXIS2_FAILURE);
    
    secpolicy->signed_supporting_tokens = signed_supporting_tokens; 
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN rp_supporting_tokens_t *AXIS2_CALL
rp_secpolicy_get_signed_supporting_tokens(
    rp_secpolicy_t *secpolicy,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return secpolicy->signed_supporting_tokens;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_secpolicy_set_endorsing_supporting_tokens(
    rp_secpolicy_t *secpolicy,
    const axutil_env_t *env,
    rp_supporting_tokens_t *endorsing_supporting_tokens)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,endorsing_supporting_tokens,AXIS2_FAILURE);   
    
    secpolicy->endorsing_supporting_tokens = endorsing_supporting_tokens; 
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN rp_supporting_tokens_t *AXIS2_CALL
rp_secpolicy_get_endorsing_supporting_tokens(
    rp_secpolicy_t *secpolicy,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
        
    return secpolicy->endorsing_supporting_tokens;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_secpolicy_set_signed_endorsing_supporting_tokens(
    rp_secpolicy_t *secpolicy,
    const axutil_env_t *env,
    rp_supporting_tokens_t *signed_endorsing_supporting_tokens)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,signed_endorsing_supporting_tokens,AXIS2_FAILURE);

    secpolicy->signed_endorsing_supporting_tokens = signed_endorsing_supporting_tokens; 
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN rp_supporting_tokens_t *AXIS2_CALL
rp_secpolicy_get_signed_endorsing_supporting_tokens(
    rp_secpolicy_t *secpolicy,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return secpolicy->signed_endorsing_supporting_tokens;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_secpolicy_set_signed_parts(
    rp_secpolicy_t *secpolicy,
    const axutil_env_t *env,
    rp_signed_encrypted_parts_t *signed_parts)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,signed_parts,AXIS2_FAILURE);    
    secpolicy->signed_parts = signed_parts; 

    return AXIS2_SUCCESS;
    
}

AXIS2_EXTERN rp_signed_encrypted_parts_t *AXIS2_CALL
rp_secpolicy_get_signed_parts(
    rp_secpolicy_t *secpolicy,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
        
    return secpolicy->signed_parts;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_secpolicy_set_encrypted_parts(
    rp_secpolicy_t *secpolicy,
    const axutil_env_t *env,
    rp_signed_encrypted_parts_t *encrypted_parts)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,encrypted_parts,AXIS2_FAILURE);    

    secpolicy->encrypted_parts = encrypted_parts; 
    return AXIS2_SUCCESS;
    
}

AXIS2_EXTERN rp_signed_encrypted_parts_t *AXIS2_CALL
rp_secpolicy_get_encrypted_parts(
    rp_secpolicy_t *secpolicy,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return secpolicy->encrypted_parts;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_secpolicy_set_signed_elements(
    rp_secpolicy_t *secpolicy,
    const axutil_env_t *env,
    rp_signed_encrypted_elements_t *signed_elements)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,signed_elements,AXIS2_FAILURE);

    secpolicy->signed_elements = signed_elements; 
    return AXIS2_SUCCESS;
    
}

AXIS2_EXTERN rp_signed_encrypted_elements_t *AXIS2_CALL
rp_secpolicy_get_signed_elements(
    rp_secpolicy_t *secpolicy,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return secpolicy->signed_elements;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_secpolicy_set_encrypted_elements(
    rp_secpolicy_t *secpolicy,
    const axutil_env_t *env,
    rp_signed_encrypted_elements_t *encrypted_elements)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,encrypted_elements,AXIS2_FAILURE);   

    secpolicy->encrypted_elements = encrypted_elements; 
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN rp_signed_encrypted_elements_t *AXIS2_CALL
rp_secpolicy_get_encrypted_elements(
    rp_secpolicy_t *secpolicy,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return secpolicy->encrypted_elements;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_secpolicy_set_signed_items(
    rp_secpolicy_t *secpolicy,
    const axutil_env_t *env,
    rp_signed_encrypted_items_t *signed_items)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,signed_items,AXIS2_FAILURE);

    secpolicy->signed_items = signed_items; 
    return AXIS2_SUCCESS;
    
}

AXIS2_EXTERN rp_signed_encrypted_items_t *AXIS2_CALL
rp_secpolicy_get_signed_items(
    rp_secpolicy_t *secpolicy,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return secpolicy->signed_items;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_secpolicy_set_encrypted_items(
    rp_secpolicy_t *secpolicy,
    const axutil_env_t *env,
    rp_signed_encrypted_items_t *encrypted_items)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,encrypted_items,AXIS2_FAILURE);   

    secpolicy->encrypted_items = encrypted_items; 
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN rp_signed_encrypted_items_t *AXIS2_CALL
rp_secpolicy_get_encrypted_items(
    rp_secpolicy_t *secpolicy,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return secpolicy->encrypted_items;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_secpolicy_set_wss(
    rp_secpolicy_t *secpolicy,
    const axutil_env_t *env,
    rp_property_t *wss)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,wss,AXIS2_FAILURE);
    
    secpolicy->wss = wss; 
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN rp_property_t *AXIS2_CALL
rp_secpolicy_get_wss(
    rp_secpolicy_t *secpolicy,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
        
    return secpolicy->wss;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_secpolicy_set_rampart_config(
    rp_secpolicy_t *secpolicy,
    const axutil_env_t *env,
    rp_rampart_config_t *rampart_config)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,rampart_config,AXIS2_FAILURE);   
    
    secpolicy->rampart_config = rampart_config; 
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN rp_rampart_config_t *AXIS2_CALL
rp_secpolicy_get_rampart_config(
    rp_secpolicy_t *secpolicy,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
        
    return secpolicy->rampart_config;
}
