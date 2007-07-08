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

#include <axis2_policy_include.h>
#include <neethi_policy.h>
#include <neethi_engine.h>

struct axis2_policy_include
{
    neethi_policy_t *policy;

    neethi_policy_t *effective_policy;

    neethi_registry_t *registry;

    axis2_desc_t *desc;

    axutil_hash_t *wrapper_elements;
};

typedef struct axis2_policy_wrapper
{
    int type;
    void *value;
} axis2_policy_wrapper_t;


AXIS2_EXTERN axis2_policy_include_t *AXIS2_CALL
axis2_policy_include_create(const axutil_env_t *env)
{
    axis2_policy_include_t *policy_include = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    policy_include = (axis2_policy_include_t *) AXIS2_MALLOC(env->allocator,
        sizeof(axis2_policy_include_t));

    if (!policy_include)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    policy_include->policy = NULL;
    policy_include->effective_policy = NULL;
    policy_include->registry = NULL;
    policy_include->desc = NULL;
    policy_include->wrapper_elements = NULL;

    policy_include->registry = neethi_registry_create(env);
    if (!policy_include->registry)
    {
        axis2_policy_include_free(policy_include, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    policy_include->wrapper_elements = axutil_hash_make(env);
    if (!policy_include->wrapper_elements)
    {
        axis2_policy_include_free(policy_include, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    return policy_include;
}

AXIS2_EXTERN axis2_policy_include_t *AXIS2_CALL
axis2_policy_include_create_with_desc(const axutil_env_t *env,
    axis2_desc_t *desc)
{
    axis2_policy_include_t *policy_include = NULL;
    axis2_desc_t *parent_desc = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    policy_include = (axis2_policy_include_t *) axis2_policy_include_create(env);
    
    parent_desc = axis2_desc_get_parent(desc, env);
    
    if (policy_include->registry)
    {
        neethi_registry_free(policy_include->registry, env);
        policy_include->registry = NULL;
    }

    if (parent_desc)
    {
        axis2_policy_include_t *preant_policy_include = 
            axis2_desc_get_policy_include(parent_desc, env);
        if (preant_policy_include)
        {
            policy_include->registry = neethi_registry_create_with_parent(env, 
                axis2_policy_include_get_registry(preant_policy_include, env));
        }
        else
        {
            policy_include->registry = neethi_registry_create(env);
        }
    }
    else
    {
        policy_include->registry = neethi_registry_create(env);
    }
    
    policy_include->desc = desc;
    
    return policy_include;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_policy_include_free(
    axis2_policy_include_t *policy_include,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (policy_include->registry)
    {
        neethi_registry_free(policy_include->registry, env);
    }

    if (policy_include->wrapper_elements)
    {
        axutil_hash_free(policy_include->wrapper_elements, env);
    }

    if (policy_include)
    {
        AXIS2_FREE(env->allocator, policy_include);
    }

    return;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_policy_include_set_registry(axis2_policy_include_t *policy_include,
    const axutil_env_t *env, 
    neethi_registry_t *registry)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (policy_include->registry)
    {
        neethi_registry_free(policy_include->registry, env);
    }
    
    policy_include->registry = registry;
    
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN neethi_registry_t *AXIS2_CALL
axis2_policy_include_get_registry(axis2_policy_include_t *policy_include,
    const axutil_env_t *env)
{
    return policy_include->registry;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_policy_include_set_policy(axis2_policy_include_t *policy_include,
    const axutil_env_t *env, 
    neethi_policy_t *policy)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    if (policy_include->wrapper_elements)
    {
        axutil_hash_free(policy_include->wrapper_elements, env);
        policy_include->wrapper_elements = NULL;
    }
    
    policy_include->wrapper_elements = axutil_hash_make(env);

    if (!neethi_policy_get_name(policy, env) && 
        !neethi_policy_get_id(policy, env))
    {
        neethi_policy_set_id(policy, env, 
            axutil_uuid_gen(env));
    }

    if (policy_include->wrapper_elements)
    {
        axis2_policy_wrapper_t *wrapper = NULL;

        wrapper = (axis2_policy_wrapper_t *) AXIS2_MALLOC(env->allocator,
            sizeof(axis2_policy_wrapper_t));
        if (wrapper)
        {
            axis2_char_t *policy_name = NULL;
            wrapper->type = AXIS2_ANON_POLICY;
            wrapper->value = policy;
            
            policy_name = neethi_policy_get_name(policy, env);
            
            if (policy_name)
            {
                axutil_hash_set(policy_include->wrapper_elements, policy_name,
                    AXIS2_HASH_KEY_STRING, wrapper);
            }
            else
            {
                axutil_hash_set(policy_include->wrapper_elements, 
                    neethi_policy_get_id(policy, env),
                    AXIS2_HASH_KEY_STRING, wrapper);
            }
        }
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_policy_include_update_policy(axis2_policy_include_t *policy_include,
    const axutil_env_t *env, 
    neethi_policy_t *policy)
{
    axis2_char_t *key;
    axis2_policy_wrapper_t *wrapper = NULL;

    key = neethi_policy_get_name(policy, env);
    if (!key)
        key = neethi_policy_get_id(policy, env);

    if (!key)
    {
        return AXIS2_FAILURE;
    }

    wrapper = axutil_hash_get(policy_include->wrapper_elements, key,
        AXIS2_HASH_KEY_STRING);
    if(wrapper)
    {
        wrapper->value = policy;
        return AXIS2_SUCCESS;
    }
    
    return AXIS2_FAILURE;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_policy_include_set_effective_policy(axis2_policy_include_t *policy_include,
    const axutil_env_t *env, 
    neethi_policy_t *effective_policy)
{
    policy_include->effective_policy = effective_policy;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_policy_include_set_desc(axis2_policy_include_t *policy_include,
    const axutil_env_t *env, 
    axis2_desc_t *desc)
{
    policy_include->desc = desc;
    return AXIS2_SUCCESS;
}        

AXIS2_EXTERN axis2_desc_t *AXIS2_CALL
axis2_policy_include_get_desc(axis2_policy_include_t *policy_include,
    const axutil_env_t *env)
{
    return policy_include->desc;
}

AXIS2_EXTERN axis2_policy_include_t *AXIS2_CALL
axis2_policy_include_get_parent(axis2_policy_include_t *policy_include,
    const axutil_env_t *env)
{
    if (policy_include->desc)
    {
        axis2_desc_t *parent = NULL;
        parent = axis2_desc_get_parent(policy_include->desc, env);
        if (parent)
        {
            return axis2_desc_get_policy_include(parent, env);
        }
    }

    return NULL;
}

static axis2_status_t
axis2_policy_include_calculate_policy(axis2_policy_include_t *policy_include,
    const axutil_env_t *env)
{
    neethi_policy_t *result = NULL;
    axutil_hash_index_t *hi = NULL;
    void *val = NULL;

    for (hi = axutil_hash_first(policy_include->wrapper_elements, env); hi;
        hi = axutil_hash_next(env, hi))
    {
        axis2_policy_wrapper_t *wrapper = NULL;

        axutil_hash_this(hi, NULL, NULL, &val);
        wrapper = (axis2_policy_wrapper_t *)val;

        if (wrapper)
        {
            neethi_policy_t *policy = NULL;
            if (wrapper->type == AXIS2_POLICY_REF) 
            {
                neethi_reference_t *reference = 
                    (neethi_reference_t *)wrapper->value;
                if (reference)
                {
                    /* TOOD add neethi_reference_normalize
                    policy = (neethi_policy_t*) neethi_reference_normalize(
                        reference, env, policy_include->registry, AXIS2_FALSE);
                    */
                }
            } 
            else 
            {
                policy = (neethi_policy_t *)wrapper->value;
            } 

            result = (result == NULL) ? (neethi_policy_t*) policy : 
                (neethi_policy_t*) neethi_engine_merge(env, result, policy);
        }
    }

    policy_include->policy = result;
    return AXIS2_SUCCESS;
}

static axis2_status_t
axis2_policy_include_calculate_effective_policy(axis2_policy_include_t *policy_include,
    const axutil_env_t *env)
{    
    neethi_policy_t *result;
    axis2_policy_include_t *parent = NULL;

    parent = axis2_policy_include_get_parent(policy_include, env);

    if (parent) 
    {
        neethi_policy_t *parent_policy =
            axis2_policy_include_get_effective_policy(parent, 
                env);

        if (!parent_policy) 
        {
            result = axis2_policy_include_get_policy(policy_include, env);

        } 
        else 
        {
            if (axis2_policy_include_get_policy(policy_include, env)) 
            {
                neethi_policy_t *temp_policy = NULL;
                parent_policy = (neethi_policy_t *)neethi_engine_get_normalize(env, AXIS2_FALSE, parent_policy);
                temp_policy = axis2_policy_include_get_policy(policy_include, env);
                temp_policy =  (neethi_policy_t *)neethi_engine_get_normalize(env, AXIS2_FALSE, temp_policy);
              /* result = (neethi_policy_t*) neethi_engine_merge(env, parent_policy,
                    axis2_policy_include_get_policy(policy_include, env));*/
                result = (neethi_policy_t*) neethi_engine_merge(env,parent_policy, temp_policy);

            } 
            else 
            {
                result = parent_policy;
            }
        }
    } 
    else 
    {
        result = axis2_policy_include_get_policy(policy_include, env);
    }
    
    policy_include->effective_policy = result;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN neethi_policy_t *AXIS2_CALL
axis2_policy_include_get_policy(axis2_policy_include_t *policy_include,
    const axutil_env_t *env)
{
    axis2_policy_include_calculate_policy(policy_include, env);
    return policy_include->policy;
}

AXIS2_EXTERN neethi_policy_t *AXIS2_CALL
axis2_policy_include_get_effective_policy(axis2_policy_include_t *policy_include,
    const axutil_env_t *env)
{
    axis2_policy_include_calculate_effective_policy(policy_include, env);
    return policy_include->effective_policy;
}

AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
axis2_policy_include_get_policy_elements(axis2_policy_include_t *policy_include,
    const axutil_env_t *env)
{
    axutil_array_list_t *policy_elements_list = NULL;
    axutil_hash_index_t *hi = NULL;
    void *val = NULL;

    policy_elements_list = axutil_array_list_create(env, 10);

    for (hi = axutil_hash_first(policy_include->wrapper_elements, env); hi;
        hi = axutil_hash_next(env, hi))
    {
        axis2_policy_wrapper_t *wrapper = NULL;

        axutil_hash_this(hi, NULL, NULL, &val);
        wrapper = (axis2_policy_wrapper_t *)val;

        if (wrapper)
        {
            axutil_array_list_add(policy_elements_list, env, wrapper->value);
        }
    }
    return policy_elements_list;
}

AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
axis2_policy_include_get_policy_elements_with_type(axis2_policy_include_t *policy_include,
    const axutil_env_t *env,
    int type)
{
    axutil_array_list_t *policy_elements_list = NULL;
    axutil_hash_index_t *hi = NULL;
    void *val = NULL;

    policy_elements_list = axutil_array_list_create(env, 10);

    for (hi = axutil_hash_first(policy_include->wrapper_elements, env); hi;
        hi = axutil_hash_next(env, hi))
    {
        axis2_policy_wrapper_t *wrapper = NULL;

        axutil_hash_this(hi, NULL, NULL, &val);
        wrapper = (axis2_policy_wrapper_t *)val;

        if (wrapper && wrapper->type == type)
        {
            axutil_array_list_add(policy_elements_list, env, wrapper->value);
        }
    }
    return policy_elements_list;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_policy_include_register_policy(axis2_policy_include_t *policy_include,
    const axutil_env_t *env,
    axis2_char_t *key,
    neethi_policy_t *policy)
{
    if (policy_include->registry)
    {
        return neethi_registry_register(policy_include->registry, env, key, 
            policy);
    }
    return AXIS2_FAILURE;
}

AXIS2_EXTERN neethi_policy_t *AXIS2_CALL
axis2_policy_include_get_policy_with_key(axis2_policy_include_t *policy_include,
    const axutil_env_t *env,
    axis2_char_t *key)
{
    if (policy_include->registry)
    {
        return neethi_registry_lookup(policy_include->registry, env, key);
    }
    return NULL;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_policy_include_add_policy_element(axis2_policy_include_t *policy_include,
    const axutil_env_t *env,
    int type,
    neethi_policy_t *policy)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    if (!neethi_policy_get_name(policy, env) && 
        !neethi_policy_get_id(policy, env))
    {
        neethi_policy_set_id(policy, env, 
            axutil_uuid_gen(env));
    }

    if (policy_include->wrapper_elements)
    {
        axis2_policy_wrapper_t *wrapper = NULL;

        wrapper = (axis2_policy_wrapper_t *) AXIS2_MALLOC(env->allocator,
            sizeof(axis2_policy_wrapper_t));
        if (wrapper)
        {
            axis2_char_t *policy_name = NULL;
            wrapper->type = type;
            wrapper->value = policy;
            
            policy_name = neethi_policy_get_name(policy, env);
            if (!policy_name)
                policy_name = neethi_policy_get_id(policy, env);
            
            if (policy_name)
            {
                axutil_hash_set(policy_include->wrapper_elements, policy_name,
                    AXIS2_HASH_KEY_STRING, wrapper);
                if (policy_include->registry)
                {
                    neethi_registry_register(policy_include->registry, 
                        env, policy_name, policy);
                }
                return AXIS2_SUCCESS;
            }
        }
    }
    return AXIS2_FAILURE;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_policy_include_add_policy_reference_element(axis2_policy_include_t *policy_include,
    const axutil_env_t *env,
    int type,
    neethi_reference_t *reference)
{
    axis2_policy_wrapper_t *wrapper = NULL;

    wrapper = (axis2_policy_wrapper_t *) AXIS2_MALLOC(env->allocator,
        sizeof(axis2_policy_wrapper_t));
    if (wrapper)
    {
        wrapper->type = type;
        wrapper->value = reference;
        axutil_hash_set(policy_include->wrapper_elements, 
            neethi_reference_get_uri(reference, env),
            AXIS2_HASH_KEY_STRING, wrapper);
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_policy_include_remove_policy_element(axis2_policy_include_t *policy_include,
    const axutil_env_t *env,
    axis2_char_t *policy_uri)
{  
    if (policy_include->wrapper_elements)
    {
        axutil_hash_set(policy_include->wrapper_elements,
            policy_uri,
            AXIS2_HASH_KEY_STRING, NULL);
    }
    if (policy_include->registry)
    {
         neethi_registry_register(policy_include->registry,
            env, policy_uri, NULL);
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_policy_include_remove_all_policy_element(axis2_policy_include_t *policy_include,
    const axutil_env_t *env)
{    
    if (policy_include->wrapper_elements)
    {
        axutil_hash_free(policy_include->wrapper_elements, env);
    }
    return AXIS2_SUCCESS;
}

