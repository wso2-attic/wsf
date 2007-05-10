/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
#include <sandesha2_constants.h>
#include "sandesha2_inmemory_bean_mgr.h"
#include <sandesha2_error.h>
#include <sandesha2_storage_mgr.h>
#include <axutil_log.h>
#include <axutil_hash.h>
#include <axutil_thread.h>
#include <axutil_property.h>

/** 
 * @brief Sandesha2 Inmemory Bean Manager Struct Impl
 *   Sandesha2 Inmemory Bean Manager
 */ 
typedef struct sandesha2_inmemory_bean_mgr_impl
{
    sandesha2_inmemory_bean_mgr_t bean_mgr;
    axutil_hash_t *table;
    sandesha2_storage_mgr_t *storage_mgr;
    axutil_thread_mutex_t *mutex;

}sandesha2_inmemory_bean_mgr_impl_t;

#define SANDESHA2_INTF_TO_IMPL(bean_mgr) \
    ((sandesha2_inmemory_bean_mgr_impl_t *) bean_mgr)

void AXIS2_CALL
sandesha2_inmemory_bean_mgr_free(
    sandesha2_inmemory_bean_mgr_t *bean_mgr,
    const axutil_env_t *env)
{
    bean_mgr->ops.free(bean_mgr, env);
}

axis2_bool_t AXIS2_CALL
sandesha2_inmemory_bean_mgr_insert(
    sandesha2_inmemory_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    axis2_char_t *key,
    sandesha2_rm_bean_t *bean)
{
    return bean_mgr->ops.insert(bean_mgr, env, key, bean); 
}

axis2_bool_t AXIS2_CALL
sandesha2_inmemory_bean_mgr_remove(
    sandesha2_inmemory_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    axis2_char_t *key)
{
    return bean_mgr->ops.remove(bean_mgr, env, key);
}

sandesha2_rm_bean_t *AXIS2_CALL
sandesha2_inmemory_bean_mgr_retrieve(
    sandesha2_inmemory_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    axis2_char_t *key)
{
    return bean_mgr->ops.retrieve(bean_mgr, env, key);
}

axis2_bool_t AXIS2_CALL
sandesha2_inmemory_bean_mgr_update(
    sandesha2_inmemory_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    axis2_char_t *key,
    sandesha2_rm_bean_t *bean)
{
    return bean_mgr->ops.update(bean_mgr, env, key, bean);
}

axutil_array_list_t *AXIS2_CALL
sandesha2_inmemory_bean_mgr_find(
    sandesha2_inmemory_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    sandesha2_rm_bean_t *bean)
{
    return bean_mgr->ops.find(bean_mgr, env, bean);
}

sandesha2_rm_bean_t *AXIS2_CALL
sandesha2_inmemory_bean_mgr_find_unique(
    sandesha2_inmemory_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    sandesha2_rm_bean_t *bean)
{
    return bean_mgr->ops.find_unique(bean_mgr, env, bean);
}

axis2_bool_t AXIS2_CALL
sandesha2_inmemory_bean_mgr_match(
    sandesha2_inmemory_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    sandesha2_rm_bean_t *bean,
    sandesha2_rm_bean_t *candidate)
{
    return bean_mgr->ops.match(bean_mgr, env, bean, candidate);
}

static void AXIS2_CALL
sandesha2_inmemory_bean_mgr_free_impl(
    sandesha2_inmemory_bean_mgr_t *bean_mgr,
    const axutil_env_t *env);

static axis2_bool_t AXIS2_CALL
sandesha2_inmemory_bean_mgr_insert_impl(
    sandesha2_inmemory_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    axis2_char_t *key,
    sandesha2_rm_bean_t *bean);

static axis2_bool_t AXIS2_CALL
sandesha2_inmemory_bean_mgr_remove_impl(
    sandesha2_inmemory_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    axis2_char_t *key);

static sandesha2_rm_bean_t *AXIS2_CALL
sandesha2_inmemory_bean_mgr_retrieve_impl(
    sandesha2_inmemory_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    axis2_char_t *key);

static axis2_bool_t AXIS2_CALL
sandesha2_inmemory_bean_mgr_update_impl(
    sandesha2_inmemory_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    axis2_char_t *key,
    sandesha2_rm_bean_t *bean);

static axutil_array_list_t *AXIS2_CALL
sandesha2_inmemory_bean_mgr_find_impl(
    sandesha2_inmemory_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    sandesha2_rm_bean_t *bean);

static sandesha2_rm_bean_t *AXIS2_CALL
sandesha2_inmemory_bean_mgr_find_unique_impl(
    sandesha2_inmemory_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    sandesha2_rm_bean_t *bean);

const static sandesha2_inmemory_bean_mgr_ops_t bean_mgr_ops =
{
    sandesha2_inmemory_bean_mgr_free_impl,
    sandesha2_inmemory_bean_mgr_insert_impl,
    sandesha2_inmemory_bean_mgr_remove_impl,
    sandesha2_inmemory_bean_mgr_retrieve_impl,
    sandesha2_inmemory_bean_mgr_update_impl,
    sandesha2_inmemory_bean_mgr_find_impl,
    sandesha2_inmemory_bean_mgr_find_unique_impl,
    NULL
};

AXIS2_EXTERN sandesha2_inmemory_bean_mgr_t * AXIS2_CALL
sandesha2_inmemory_bean_mgr_create(
    const axutil_env_t *env,
    sandesha2_storage_mgr_t *storage_mgr,
    axis2_ctx_t *ctx,
    axis2_char_t *key)
{
    sandesha2_inmemory_bean_mgr_impl_t *bean_mgr_impl = NULL;
    axutil_property_t *property = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    bean_mgr_impl = AXIS2_MALLOC(env->allocator, 
        sizeof(sandesha2_inmemory_bean_mgr_impl_t));

    bean_mgr_impl->table = NULL;
    bean_mgr_impl->storage_mgr = storage_mgr;
    bean_mgr_impl->mutex = NULL;

    bean_mgr_impl->mutex = axutil_thread_mutex_create(env->allocator, 
        AXIS2_THREAD_MUTEX_DEFAULT);
    if(!bean_mgr_impl->mutex) 
    {
        sandesha2_inmemory_bean_mgr_free(&(bean_mgr_impl->bean_mgr), env);
        return NULL;
    }
    property = axis2_ctx_get_property(ctx, env, key);
    if(property)
    {
        bean_mgr_impl->table = (axutil_hash_t *) axutil_property_get_value(
            property, env);
    }
    if(!bean_mgr_impl->table)
    {
        axutil_property_t *property = NULL;
        property = axutil_property_create(env);
        bean_mgr_impl->table = axutil_hash_make(env);
        if(!property || !bean_mgr_impl->table)
        {
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            return NULL;
        }
        axutil_property_set_scope(property, env, AXIS2_SCOPE_APPLICATION);
        axutil_property_set_value(property, env, bean_mgr_impl->table);
        axutil_property_set_free_func(property, env, axutil_hash_free_void_arg);
        axis2_ctx_set_property(ctx, env, key, property);
    }
    bean_mgr_impl->bean_mgr.ops = bean_mgr_ops;
    return &(bean_mgr_impl->bean_mgr);
}

static void AXIS2_CALL
sandesha2_inmemory_bean_mgr_free_impl(
    sandesha2_inmemory_bean_mgr_t *bean_mgr,
    const axutil_env_t *env)
{
    sandesha2_inmemory_bean_mgr_impl_t *bean_mgr_impl = NULL;
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Start:sandesha2_inmemory_bean_mgr_free_impl");
    bean_mgr_impl = SANDESHA2_INTF_TO_IMPL(bean_mgr);

    if(bean_mgr_impl->mutex)
    {
        axutil_thread_mutex_destroy(bean_mgr_impl->mutex);
        bean_mgr_impl->mutex = NULL;
    }
    if(bean_mgr_impl->table)
    {
        axutil_hash_free(bean_mgr_impl->table, env);
        bean_mgr_impl->table = NULL;
    }
    if(bean_mgr_impl)
    {
        AXIS2_FREE(env->allocator, bean_mgr_impl);
        bean_mgr_impl = NULL;
    }
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Exit:sandesha2_inmemory_bean_mgr_free_impl");
}

static axis2_bool_t AXIS2_CALL
sandesha2_inmemory_bean_mgr_insert_impl(
    sandesha2_inmemory_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    axis2_char_t *key,
    sandesha2_rm_bean_t *bean)
{
    sandesha2_inmemory_bean_mgr_impl_t *bean_mgr_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, bean, AXIS2_FALSE);
    bean_mgr_impl = SANDESHA2_INTF_TO_IMPL(bean_mgr);
    /*sandesha2_storage_mgr_enlist_bean(bean_mgr_impl->storage_mgr, env, bean);*/
    axutil_thread_mutex_lock(bean_mgr_impl->mutex);
    axutil_hash_set(bean_mgr_impl->table, key, AXIS2_HASH_KEY_STRING, bean);
    axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
    return AXIS2_TRUE;
}

static axis2_bool_t AXIS2_CALL
sandesha2_inmemory_bean_mgr_remove_impl(
    sandesha2_inmemory_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    axis2_char_t *key)
{
    sandesha2_inmemory_bean_mgr_impl_t *bean_mgr_impl = NULL;
    sandesha2_rm_bean_t *bean = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, key, AXIS2_FALSE);
    bean_mgr_impl = SANDESHA2_INTF_TO_IMPL(bean_mgr);
    axutil_thread_mutex_lock(bean_mgr_impl->mutex);
    bean = (sandesha2_rm_bean_t *) axutil_hash_get(bean_mgr_impl->table, key,
        AXIS2_HASH_KEY_STRING);
    axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
    /*if(bean)
        sandesha2_storage_mgr_enlist_bean(bean_mgr_impl->storage_mgr, env, bean);*/
    axutil_thread_mutex_lock(bean_mgr_impl->mutex);
    axutil_hash_set(bean_mgr_impl->table, key, AXIS2_HASH_KEY_STRING, NULL);
    axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
    return AXIS2_TRUE;
}

static sandesha2_rm_bean_t *AXIS2_CALL
sandesha2_inmemory_bean_mgr_retrieve_impl(
    sandesha2_inmemory_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    axis2_char_t *key)
{
    sandesha2_inmemory_bean_mgr_impl_t *bean_mgr_impl = NULL;
    sandesha2_rm_bean_t *bean = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, key, AXIS2_FALSE);
    bean_mgr_impl = SANDESHA2_INTF_TO_IMPL(bean_mgr);
    axutil_thread_mutex_lock(bean_mgr_impl->mutex);
    AXIS2_LOG_INFO(env->log, "%s\n", key);
    bean = (sandesha2_rm_bean_t *) axutil_hash_get(bean_mgr_impl->table, 
            key, AXIS2_HASH_KEY_STRING);
    axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
    /*if(bean)
        sandesha2_storage_mgr_enlist_bean(bean_mgr_impl->storage_mgr, env, bean);
    axutil_thread_mutex_lock(bean_mgr_impl->mutex);
    bean = (sandesha2_rm_bean_t *) axutil_hash_get(bean_mgr_impl->table, 
            key, AXIS2_HASH_KEY_STRING);
    axutil_thread_mutex_unlock(bean_mgr_impl->mutex);*/
    return bean;
}

static axis2_bool_t AXIS2_CALL
sandesha2_inmemory_bean_mgr_update_impl(
    sandesha2_inmemory_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    axis2_char_t *key,
    sandesha2_rm_bean_t *bean)
{
    sandesha2_inmemory_bean_mgr_impl_t *bean_mgr_impl = NULL;
    sandesha2_rm_bean_t *old_bean = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, bean, AXIS2_FALSE);
    bean_mgr_impl = SANDESHA2_INTF_TO_IMPL(bean_mgr);
    /*if(bean)
        sandesha2_storage_mgr_enlist_bean(bean_mgr_impl->storage_mgr, env, bean);*/
    axutil_thread_mutex_lock(bean_mgr_impl->mutex);
    old_bean = (sandesha2_rm_bean_t *) axutil_hash_get(bean_mgr_impl->table, key, 
        AXIS2_HASH_KEY_STRING); 
    axutil_hash_set(bean_mgr_impl->table, key, AXIS2_HASH_KEY_STRING, bean);
    axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
    if(!old_bean)
        return AXIS2_FALSE;
    /*sandesha2_storage_mgr_enlist_bean(bean_mgr_impl->storage_mgr, env, old_bean);*/
    return AXIS2_TRUE;
}

static axutil_array_list_t *AXIS2_CALL
sandesha2_inmemory_bean_mgr_find_impl(
    sandesha2_inmemory_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    sandesha2_rm_bean_t *bean)
{
    sandesha2_inmemory_bean_mgr_impl_t *bean_mgr_impl = NULL;
    axutil_array_list_t *beans = NULL;
    axutil_hash_index_t *index = NULL;
    int i = 0, size = 0;
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    bean_mgr_impl = SANDESHA2_INTF_TO_IMPL(bean_mgr);
    beans = axutil_array_list_create(env, 0);
    if(!beans)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    axutil_thread_mutex_lock(bean_mgr_impl->mutex);
    for (index = axutil_hash_first (bean_mgr_impl->table, env); index; 
            index = axutil_hash_next (env, index))
    {
        void *v = NULL;
        const void *key = NULL;
        sandesha2_rm_bean_t *candidate = NULL;
        axutil_hash_this (index, &key, NULL, &v);
        candidate = (sandesha2_rm_bean_t *) v;
        if(!candidate)
            continue;
    
        if(bean && sandesha2_inmemory_bean_mgr_match(bean_mgr, env, bean, 
            candidate))
        {
            axutil_array_list_add(beans, env, candidate);
        }
        if(!bean)
            axutil_array_list_add(beans, env, candidate);
    }
    axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
    /* Now we have a point-in-time view of the beans, lock them all.*/
    size = axutil_array_list_size(beans, env);
    for(i = 0; i < size; i++)
    {
        /*sandesha2_rm_bean_t *temp = axutil_array_list_get(beans, env, i);
        if(temp)
            sandesha2_storage_mgr_enlist_bean(bean_mgr_impl->storage_mgr, env, 
                temp);*/
    }
    /* Finally remove any beans that are no longer in the table */
    axutil_thread_mutex_lock(bean_mgr_impl->mutex);
    size = axutil_array_list_size(beans, env);
    for(i = 0; i < size; i++)
    {
        sandesha2_rm_bean_t *temp = axutil_array_list_get(beans, env, i);
        if(temp)
        {
            axis2_char_t *key = sandesha2_rm_bean_get_key(temp, env);
            if(axutil_hash_contains_key(bean_mgr_impl->table, env, key))
            {
                void *value = axutil_hash_get(bean_mgr_impl->table, key, 
                    AXIS2_HASH_KEY_STRING);
                if(!value)
                {
                    axutil_array_list_remove(beans, env, i);
                }
            }
            else
            {
                axutil_array_list_remove(beans, env, i);
            }
        }
    }
    axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
    return beans;
}

static sandesha2_rm_bean_t *AXIS2_CALL
sandesha2_inmemory_bean_mgr_find_unique_impl(
    sandesha2_inmemory_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    sandesha2_rm_bean_t *bean)
{
    sandesha2_inmemory_bean_mgr_impl_t *bean_mgr_impl = NULL;
    axutil_array_list_t *beans = NULL;
    int size = 0;
    sandesha2_rm_bean_t *ret = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, bean, AXIS2_FALSE);
    bean_mgr_impl = SANDESHA2_INTF_TO_IMPL(bean_mgr);
    beans = sandesha2_inmemory_bean_mgr_find(bean_mgr, env, bean);
    if(beans)
        size = axutil_array_list_size(beans, env);
    if( size > 1)
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[sandesha2] Non-Unique result");
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_NON_UNIQUE_RESULT, AXIS2_FAILURE);
        return NULL;
    }
    if(size == 1)
       ret = axutil_array_list_get(beans, env, 0);
    return ret;
}

