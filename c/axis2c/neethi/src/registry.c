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



#include <neethi_registry.h>

struct neethi_registry_t
{
    axutil_hash_t *registry;
    neethi_registry_t *parent;
};

AXIS2_EXTERN neethi_registry_t *AXIS2_CALL 
neethi_registry_create(const axutil_env_t *env)
{
    neethi_registry_t *neethi_registry = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    neethi_registry =  (neethi_registry_t *) AXIS2_MALLOC (env->allocator,
    sizeof (neethi_registry_t));

    if(neethi_registry == NULL)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    neethi_registry->registry = NULL;

    neethi_registry->registry = axutil_hash_make(env);
    if (!(neethi_registry->registry))
    {
        neethi_registry_free(neethi_registry, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    neethi_registry->parent = NULL;

    return neethi_registry;
}

AXIS2_EXTERN neethi_registry_t *AXIS2_CALL
neethi_registry_create_with_parent(
            const axutil_env_t *env,
            neethi_registry_t *parent)
{
    neethi_registry_t *neethi_registry = NULL;
    
    neethi_registry = neethi_registry_create(env);
    if(!neethi_registry)
        return NULL;
    
    neethi_registry->parent = parent;
    return neethi_registry;
}


AXIS2_EXTERN void AXIS2_CALL 
neethi_registry_free(neethi_registry_t *neethi_registry,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    if (neethi_registry->registry)
    {
        axutil_hash_index_t *hi = NULL;
        void *val = NULL;
        for (hi = axutil_hash_first(neethi_registry->registry, env); hi;
                hi = axutil_hash_next(env, hi))
        {
            neethi_policy_t *neethi_policy = NULL;
            axutil_hash_this(hi, NULL, NULL, &val);
            neethi_policy = (neethi_policy_t *) val;
            if (neethi_policy)
                 neethi_policy_free(neethi_policy, env);
            val = NULL;
            neethi_policy = NULL;

        }
        axutil_hash_free(neethi_registry->registry , env);
    }
    if(neethi_registry->parent)
    {
        /*neethi_registry_free(neethi_registry->parent, env);*/
        neethi_registry->parent = NULL;
    }
    AXIS2_FREE(env->allocator,neethi_registry);
}


/* Implementations */

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
neethi_registry_register(
    neethi_registry_t *neethi_registry,
    const axutil_env_t *env,
    axis2_char_t *key,
    neethi_policy_t *value)

{
    axutil_hash_set(neethi_registry->registry, key , AXIS2_HASH_KEY_STRING, value);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN neethi_policy_t *AXIS2_CALL 
neethi_registry_lookup(
    neethi_registry_t *neethi_registry,
    const axutil_env_t *env,
    axis2_char_t *key)
{
    neethi_policy_t *policy = NULL;

    policy = (neethi_policy_t *)axutil_hash_get(neethi_registry->registry,key ,
        AXIS2_HASH_KEY_STRING);

    if(!policy && neethi_registry->parent)
    {
        return neethi_registry_lookup(neethi_registry->parent, env, key);
    }
    return policy;
}
