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



#include <rp_supporting_tokens.h>

struct rp_supporting_tokens_t
{
    rp_algorithmsuite_t *algorithmsuite;
    axutil_array_list_t *tokens;
    rp_signed_encrypted_elements_t *signed_elements;
    rp_signed_encrypted_parts_t *signed_parts;
    rp_signed_encrypted_elements_t *encrypted_elements;
    rp_signed_encrypted_parts_t *encrypted_parts;
    int type;
    int ref;
};

AXIS2_EXTERN rp_supporting_tokens_t *AXIS2_CALL 
rp_supporting_tokens_create(const axutil_env_t *env)
{
    rp_supporting_tokens_t *supporting_tokens = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    supporting_tokens =  (rp_supporting_tokens_t *) AXIS2_MALLOC (env->allocator,
    sizeof (rp_supporting_tokens_t));

    if(supporting_tokens == NULL)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    supporting_tokens->tokens = NULL;
    supporting_tokens->tokens = axutil_array_list_create(env,0);
    if (!(supporting_tokens->tokens))
    {
        rp_supporting_tokens_free(supporting_tokens, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    
    supporting_tokens->algorithmsuite = NULL;
    supporting_tokens->signed_parts = NULL;
    supporting_tokens->signed_elements = NULL;
    supporting_tokens->encrypted_parts = NULL;
    supporting_tokens->encrypted_elements = NULL;
    supporting_tokens->type = 0;
    supporting_tokens->ref = 0;
    return supporting_tokens;
}

AXIS2_EXTERN void AXIS2_CALL
rp_supporting_tokens_free(rp_supporting_tokens_t *supporting_tokens,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if(supporting_tokens)
    {

        if (--(supporting_tokens->ref) > 0)
        {
            return;
        }
        
        if(supporting_tokens->tokens)
        {
            int i = 0;
            for (i = 0; i < axutil_array_list_size(supporting_tokens->tokens,
                env); i++)
            {
                rp_property_t *token = NULL;
                token = (rp_property_t *)
                    axutil_array_list_get(supporting_tokens->tokens,env, i);
                if (token)
                    rp_property_free(token, env);

                token = NULL;
            }
            axutil_array_list_free(supporting_tokens->tokens, env);
            supporting_tokens->tokens = NULL;

        }
        if(supporting_tokens->algorithmsuite)
        {
            rp_algorithmsuite_free(supporting_tokens->algorithmsuite,env);
            supporting_tokens->algorithmsuite = NULL;
        }            
        if(supporting_tokens->signed_parts)
        {
            rp_signed_encrypted_parts_free(supporting_tokens->signed_parts,env);
            supporting_tokens->signed_parts = NULL;
        }    
        if(supporting_tokens->signed_elements)
        {
            rp_signed_encrypted_elements_free(supporting_tokens->signed_elements,env);
            supporting_tokens->signed_elements = NULL;
        }
        if(supporting_tokens->encrypted_parts)
        {
            rp_signed_encrypted_parts_free(supporting_tokens->encrypted_parts,env);
            supporting_tokens->encrypted_parts = NULL;
        }
        if(supporting_tokens->encrypted_elements)
        {
            rp_signed_encrypted_elements_free(supporting_tokens->encrypted_elements,env);
            supporting_tokens->encrypted_elements = NULL;
        }
        AXIS2_FREE(env->allocator,supporting_tokens);
        supporting_tokens = NULL;
    }
    return;
}


/* Implementations */

AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
rp_supporting_tokens_get_tokens(
    rp_supporting_tokens_t *supporting_tokens,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    return supporting_tokens->tokens;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rp_supporting_tokens_add_token(rp_supporting_tokens_t *supporting_tokens,
            const axutil_env_t *env,
            rp_property_t *token)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, token, AXIS2_FAILURE);
    
    rp_property_increment_ref(token, env);
    axutil_array_list_add(supporting_tokens->tokens, env, token);
    return AXIS2_SUCCESS;
}



AXIS2_EXTERN rp_algorithmsuite_t *AXIS2_CALL
rp_supporting_tokens_get_algorithmsuite(
    rp_supporting_tokens_t *supporting_tokens,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    return supporting_tokens->algorithmsuite;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rp_supporting_tokens_set_algorithmsuite(rp_supporting_tokens_t *supporting_tokens,
            const axutil_env_t *env,
            rp_algorithmsuite_t *algorithmsuite)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,algorithmsuite,AXIS2_FAILURE);

    rp_algorithmsuite_increment_ref(algorithmsuite, env);
    supporting_tokens->algorithmsuite = algorithmsuite;
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN rp_signed_encrypted_parts_t *AXIS2_CALL
rp_supporting_tokens_get_signed_parts(
    rp_supporting_tokens_t *supporting_tokens,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
        
    return supporting_tokens->signed_parts;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rp_supporting_tokens_set_signed_parts(rp_supporting_tokens_t *supporting_tokens,
            const axutil_env_t *env,
            rp_signed_encrypted_parts_t *signed_parts)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,signed_parts,AXIS2_FAILURE);
        
    supporting_tokens->signed_parts = signed_parts;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN rp_signed_encrypted_elements_t *AXIS2_CALL
rp_supporting_tokens_get_signed_elements(
    rp_supporting_tokens_t *supporting_tokens,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    return supporting_tokens->signed_elements;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rp_supporting_tokens_set_signed_elements(rp_supporting_tokens_t *supporting_tokens,
            const axutil_env_t *env,
            rp_signed_encrypted_elements_t *signed_elements)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,signed_elements,AXIS2_FAILURE);
        
    supporting_tokens->signed_elements = signed_elements;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN rp_signed_encrypted_parts_t *AXIS2_CALL
rp_supporting_tokens_get_encrypted_parts(
    rp_supporting_tokens_t *supporting_tokens,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    return supporting_tokens->encrypted_parts;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rp_supporting_tokens_set_encrypted_parts(rp_supporting_tokens_t *supporting_tokens,
            const axutil_env_t *env,
            rp_signed_encrypted_parts_t *encrypted_parts)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,encrypted_parts,AXIS2_FAILURE);

    supporting_tokens->encrypted_parts = encrypted_parts;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN rp_signed_encrypted_elements_t *AXIS2_CALL
rp_supporting_tokens_get_encrypted_elements(
    rp_supporting_tokens_t *supporting_tokens,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
        
    return supporting_tokens->encrypted_elements;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rp_supporting_tokens_set_encrypted_elements(rp_supporting_tokens_t *supporting_tokens,
            const axutil_env_t *env,
            rp_signed_encrypted_elements_t *encrypted_elements)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,encrypted_elements,AXIS2_FAILURE);
        
    supporting_tokens->encrypted_elements = encrypted_elements;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN int AXIS2_CALL
rp_supporting_tokens_get_type(
    rp_supporting_tokens_t *supporting_tokens,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
        
    return supporting_tokens->type;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rp_supporting_tokens_set_type(rp_supporting_tokens_t *supporting_tokens,
            const axutil_env_t *env,
            int type)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    supporting_tokens->type = type;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rp_supporting_tokens_increment_ref(rp_supporting_tokens_t *supporting_tokens,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    supporting_tokens->ref++;
    return AXIS2_SUCCESS;
}

