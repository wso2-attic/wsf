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


#include <rp_binding_commons.h>

struct rp_binding_commons_t
{
    rp_algorithmsuite_t *algorithmsuite;
    axis2_bool_t include_timestamp;
    rp_layout_t *layout;
    rp_supporting_tokens_t *signed_supporting_tokens;
    rp_supporting_tokens_t *signed_endorsing_supporting_tokens;
    rp_supporting_tokens_t *endorsing_supporting_tokens;
    rp_supporting_tokens_t *supporting_tokens;
};

AXIS2_EXTERN rp_binding_commons_t *AXIS2_CALL 
rp_binding_commons_create(const axutil_env_t *env)
{
    rp_binding_commons_t *binding_commons = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    binding_commons =  (rp_binding_commons_t *) AXIS2_MALLOC (env->allocator,
    sizeof (rp_binding_commons_t));

    if(binding_commons == NULL)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    binding_commons->algorithmsuite = NULL;
    binding_commons->include_timestamp = AXIS2_FALSE;
    binding_commons->layout = NULL;
    binding_commons->signed_supporting_tokens = NULL;
    binding_commons->signed_endorsing_supporting_tokens = NULL;
    binding_commons->endorsing_supporting_tokens = NULL;
    binding_commons->supporting_tokens = NULL;

    return binding_commons;

}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_binding_commons_free(rp_binding_commons_t *binding_commons,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    if(binding_commons)
    {
        
        if(binding_commons->algorithmsuite)
        {
            rp_algorithmsuite_free(binding_commons->algorithmsuite,env);
            binding_commons->algorithmsuite = NULL;
        }
        if(binding_commons->layout)
        {
            rp_layout_free(binding_commons->layout,env);
            binding_commons->layout = NULL;
        }
        if(binding_commons->signed_supporting_tokens)
        {
            rp_supporting_tokens_free(binding_commons->signed_supporting_tokens,env);
            binding_commons->signed_supporting_tokens = NULL;
        }
        if(binding_commons->signed_endorsing_supporting_tokens)
        {
            rp_supporting_tokens_free(binding_commons->signed_endorsing_supporting_tokens,env);
            binding_commons->signed_endorsing_supporting_tokens = NULL;
        }      
        if(binding_commons->endorsing_supporting_tokens)
        {
            rp_supporting_tokens_free(binding_commons->endorsing_supporting_tokens,env);
            binding_commons->endorsing_supporting_tokens = NULL;
        }
        if(binding_commons->supporting_tokens)
        {
            rp_supporting_tokens_free(binding_commons->supporting_tokens,env);
            binding_commons->supporting_tokens = NULL;
        }            
        AXIS2_FREE(env->allocator,binding_commons);
        binding_commons = NULL;

    }
    return AXIS2_SUCCESS;
}


/* Implementations */

AXIS2_EXTERN axis2_bool_t AXIS2_CALL 
rp_binding_commons_get_include_timestamp(rp_binding_commons_t *binding_commons,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return binding_commons->include_timestamp;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_binding_commons_set_include_timestamp(rp_binding_commons_t *binding_commons,
            const axutil_env_t *env,
            axis2_bool_t include_timestamp)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,include_timestamp,AXIS2_FAILURE);
    
    binding_commons->include_timestamp = include_timestamp;

    return AXIS2_SUCCESS;
    
}

AXIS2_EXTERN rp_algorithmsuite_t *AXIS2_CALL
rp_binding_commons_get_algorithmsuite(
    rp_binding_commons_t *binding_commons,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    
    return binding_commons->algorithmsuite;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_binding_commons_set_algorithmsuite(rp_binding_commons_t *binding_commons,
            const axutil_env_t *env,
            rp_algorithmsuite_t *algorithmsuite)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,algorithmsuite,AXIS2_FAILURE);
    
    binding_commons->algorithmsuite = algorithmsuite;    
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN rp_layout_t *AXIS2_CALL
rp_binding_commons_get_layout(
    rp_binding_commons_t *binding_commons,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    
    return binding_commons->layout;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_binding_commons_set_layout(rp_binding_commons_t *binding_commons,
            const axutil_env_t *env,
            rp_layout_t *layout)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,layout,AXIS2_FAILURE);
    
    binding_commons->layout = layout;    
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN rp_supporting_tokens_t *AXIS2_CALL
rp_binding_commons_get_signed_supporting_tokens(
    rp_binding_commons_t *binding_commons,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    
    return binding_commons->signed_supporting_tokens;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rp_binding_commons_set_signed_supporting_tokens(
            rp_binding_commons_t *binding_commons,
            const axutil_env_t *env,
            rp_supporting_tokens_t *signed_supporting_tokens)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,signed_supporting_tokens,AXIS2_FAILURE);
 
    binding_commons->signed_supporting_tokens = signed_supporting_tokens;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN rp_supporting_tokens_t *AXIS2_CALL
rp_binding_commons_get_signed_endorsing_supporting_tokens(
    rp_binding_commons_t *binding_commons,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    return binding_commons->signed_endorsing_supporting_tokens;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_binding_commons_set_signed_endorsing_supporting_tokens(
            rp_binding_commons_t *binding_commons,
            const axutil_env_t *env,
            rp_supporting_tokens_t *signed_endorsing_supporting_tokens)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,signed_endorsing_supporting_tokens,AXIS2_FAILURE);

    binding_commons->signed_endorsing_supporting_tokens = signed_endorsing_supporting_tokens;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN rp_supporting_tokens_t *AXIS2_CALL
rp_binding_commons_get_endorsing_supporting_tokens(
    rp_binding_commons_t *binding_commons,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    
    return binding_commons->endorsing_supporting_tokens;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rp_binding_commons_set_endorsing_supporting_tokens(
            rp_binding_commons_t *binding_commons,
            const axutil_env_t *env,
            rp_supporting_tokens_t *endorsing_supporting_tokens)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,endorsing_supporting_tokens,AXIS2_FAILURE);
    binding_commons->endorsing_supporting_tokens = endorsing_supporting_tokens;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN rp_supporting_tokens_t *AXIS2_CALL
rp_binding_commons_get_supporting_tokens(
    rp_binding_commons_t *binding_commons,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    
    return binding_commons->supporting_tokens;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rp_binding_commons_set_supporting_tokens(
            rp_binding_commons_t *binding_commons,
            const axutil_env_t *env,
            rp_supporting_tokens_t *supporting_tokens)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,supporting_tokens,AXIS2_FAILURE);
        
    binding_commons->supporting_tokens = supporting_tokens;
    return AXIS2_SUCCESS;
}
