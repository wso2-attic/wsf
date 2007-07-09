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



#include <rp_username_token.h>

struct rp_username_token_t
{
    axis2_char_t *inclusion;
    axis2_bool_t derivedkeys;
    axis2_bool_t useUTprofile10;
    axis2_bool_t useUTprofile11;
    int ref;
};

AXIS2_EXTERN rp_username_token_t *AXIS2_CALL 
rp_username_token_create(const axutil_env_t *env)
{
    rp_username_token_t *username_token = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    username_token =  (rp_username_token_t *) AXIS2_MALLOC (env->allocator,
    sizeof (rp_username_token_t));

    if(username_token == NULL)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    username_token->inclusion = RP_INCLUDE_ALWAYS;
    username_token->derivedkeys = AXIS2_FALSE;
    username_token->useUTprofile10 = AXIS2_TRUE;
    username_token->useUTprofile11 = AXIS2_FALSE;
    username_token->ref = 0;

    return username_token;

}

AXIS2_EXTERN void AXIS2_CALL 
rp_username_token_free(
    rp_username_token_t *username_token,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    if (--(username_token->ref) > 0)
    {
        return;
    }
    
    if(username_token)
    {
        AXIS2_FREE(env->allocator, username_token);
        username_token = NULL;
    }
    return;
}


/* Implementations */

AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
rp_username_token_get_inclusion(
    rp_username_token_t *username_token,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    
    return username_token->inclusion;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_username_token_set_inclusion(
    rp_username_token_t *username_token,
    const axutil_env_t *env,
    axis2_char_t *inclusion)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,inclusion,AXIS2_FAILURE);
    
    username_token->inclusion = inclusion;

    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axis2_bool_t AXIS2_CALL 
rp_username_token_get_derivedkeys(
    rp_username_token_t *username_token,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
        
    return username_token->derivedkeys;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_username_token_set_derivedkeys(
    rp_username_token_t *username_token,
    const axutil_env_t *env,
    axis2_bool_t derivedkeys)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
     AXIS2_PARAM_CHECK(env->error,derivedkeys,AXIS2_FAILURE);    
    username_token->derivedkeys = derivedkeys;

    return AXIS2_SUCCESS;
    
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL 
rp_username_token_get_useUTprofile10(
    rp_username_token_t *username_token,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
        
    return username_token->useUTprofile10;
    
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_username_token_set_useUTprofile10(
    rp_username_token_t *username_token,
    const axutil_env_t *env,
    axis2_bool_t useUTprofile10)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,useUTprofile10,AXIS2_FAILURE);
    username_token->useUTprofile10 = useUTprofile10;

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL 
rp_username_token_get_useUTprofile11(
    rp_username_token_t *username_token,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
        
    return username_token->useUTprofile10;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_username_token_set_useUTprofile11(
    rp_username_token_t *username_token,
    const axutil_env_t *env,
    axis2_bool_t useUTprofile11)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,useUTprofile11,AXIS2_FAILURE);    
    username_token->useUTprofile11 = useUTprofile11;

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rp_username_token_increment_ref(rp_username_token_t *username_token,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    username_token->ref++;
    return AXIS2_SUCCESS;
}
