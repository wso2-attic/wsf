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



#include <rp_symmetric_binding.h>

struct rp_symmetric_binding_t
{
    rp_symmetric_asymmetric_binding_commons_t *symmetric_asymmetric_binding_commons;
    rp_property_t *protection_token;
    rp_property_t *signature_token;
    rp_property_t *encryption_token;
};

AXIS2_EXTERN rp_symmetric_binding_t *AXIS2_CALL 
rp_symmetric_binding_create(const axutil_env_t *env)
{
    rp_symmetric_binding_t *symmetric_binding = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    symmetric_binding =  (rp_symmetric_binding_t *) AXIS2_MALLOC (env->allocator,
    sizeof (rp_symmetric_binding_t));

    if(symmetric_binding == NULL)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    symmetric_binding->symmetric_asymmetric_binding_commons = NULL;
    symmetric_binding->protection_token = NULL;
    symmetric_binding->signature_token = NULL;
    symmetric_binding->encryption_token = NULL;
    
    return symmetric_binding;
}

AXIS2_EXTERN void AXIS2_CALL 
rp_symmetric_binding_free(
    rp_symmetric_binding_t *symmetric_binding,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    if(symmetric_binding)
    {
        if(symmetric_binding->symmetric_asymmetric_binding_commons)
        {
            rp_symmetric_asymmetric_binding_commons_free(
                symmetric_binding->symmetric_asymmetric_binding_commons,
                env);
            symmetric_binding->symmetric_asymmetric_binding_commons=NULL;
        }
        if(symmetric_binding->protection_token)
        {
            rp_property_free(symmetric_binding->protection_token,env);
            symmetric_binding->protection_token = NULL;
        }
        if(symmetric_binding->encryption_token)
        {
            rp_property_free(symmetric_binding->encryption_token,env);            
            symmetric_binding->encryption_token = NULL;
        }
        if(symmetric_binding->signature_token)
        {
            rp_property_free(symmetric_binding->signature_token,env);            
            symmetric_binding->signature_token = NULL;
        }
        AXIS2_FREE(env->allocator,symmetric_binding);           
    }

    return;
}


/* Implementations */

AXIS2_EXTERN rp_symmetric_asymmetric_binding_commons_t *AXIS2_CALL
rp_symmetric_binding_get_symmetric_asymmetric_binding_commons(
    rp_symmetric_binding_t *symmetric_binding,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
        
    return symmetric_binding->symmetric_asymmetric_binding_commons;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rp_symmetric_binding_set_symmetric_asymmetric_binding_commons(
    rp_symmetric_binding_t *symmetric_binding,
    const axutil_env_t *env,
    rp_symmetric_asymmetric_binding_commons_t *symmetric_asymmetric_binding_commons)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,symmetric_asymmetric_binding_commons,AXIS2_FAILURE);
        
    symmetric_binding->symmetric_asymmetric_binding_commons
            =symmetric_asymmetric_binding_commons;

    return AXIS2_SUCCESS;
}



AXIS2_EXTERN rp_property_t *AXIS2_CALL
rp_symmetric_binding_get_protection_token(
    rp_symmetric_binding_t *symmetric_binding,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
        
    return symmetric_binding->protection_token;
}



AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_symmetric_binding_set_protection_token(
    rp_symmetric_binding_t *symmetric_binding,
    const axutil_env_t *env,
    rp_property_t *protection_token)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,protection_token,AXIS2_FAILURE);
    if(symmetric_binding->signature_token ||
        symmetric_binding->encryption_token)
    {
        return AXIS2_FAILURE;
    }
    symmetric_binding->protection_token=protection_token; 

    return AXIS2_SUCCESS;
    
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_symmetric_binding_set_encryption_token(
    rp_symmetric_binding_t *symmetric_binding,
    const axutil_env_t *env,
    rp_property_t *encryption_token)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,encryption_token,AXIS2_FAILURE);
    if(symmetric_binding->protection_token)
    {
        return AXIS2_FAILURE;
    }
    symmetric_binding->encryption_token = encryption_token; 

    return AXIS2_SUCCESS;
    
}

AXIS2_EXTERN rp_property_t *AXIS2_CALL
rp_symmetric_binding_get_encryption_token(
    rp_symmetric_binding_t *symmetric_binding,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    
    return symmetric_binding->encryption_token;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_symmetric_binding_set_signature_token(
    rp_symmetric_binding_t *symmetric_binding,
    const axutil_env_t *env,
    rp_property_t *signature_token)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,signature_token,AXIS2_FAILURE);
    if(symmetric_binding->protection_token)
    {
        return AXIS2_FAILURE;
    }
    symmetric_binding->signature_token = signature_token; 

    return AXIS2_SUCCESS;
    
}

AXIS2_EXTERN rp_property_t *AXIS2_CALL
rp_symmetric_binding_get_signature_token(
    rp_symmetric_binding_t *symmetric_binding,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    
    return symmetric_binding->signature_token;
}
