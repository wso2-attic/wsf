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

#include <service_admin_counter.h>
#include <axutil_string.h>
#include <axis2_msg_ctx.h>
#include <axis2_conf_ctx.h>

struct service_admin_counter_t
{
    int count;
    axis2_char_t *svc_name;
    axis2_char_t *op_name;
    axutil_hash_t *last_counts;
    axutil_thread_mutex_t *mutex;
};

static void AXIS2_CALL
service_admin_counter_last_counts_free_void_arg(
    void *lcounts,
    const axutil_env_t *env);

AXIS2_EXTERN service_admin_counter_t* AXIS2_CALL
service_admin_counter_create(
    const axutil_env_t *env,
    const axis2_char_t *svc_name,
    const axis2_char_t *op_name)
{
    service_admin_counter_t *counter = NULL;
    
    counter =  (service_admin_counter_t *)AXIS2_MALLOC(env->allocator, 
            sizeof(service_admin_counter_t));
	
    if(!counter)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    counter->count = 0;
    counter->last_counts = axutil_hash_make(env);
    if(!counter->last_counts)
    {
        service_admin_counter_free(counter, env);
    }
    counter->mutex = axutil_thread_mutex_create(env->allocator, AXIS2_THREAD_MUTEX_DEFAULT);

    if(!counter->mutex)
    {
        service_admin_counter_free(counter, env);
        return NULL;
    }
    if(svc_name)
    {
        counter->svc_name = axutil_strdup(env, svc_name);
    }
    if(op_name)
    {
        counter->op_name = axutil_strdup(env, op_name);
    }

	return counter;
}

void AXIS2_CALL 
service_admin_counter_free(
    service_admin_counter_t *counter, 
    const axutil_env_t *env)
{
    if(counter->mutex)
    {
        axutil_thread_mutex_destroy(counter->mutex);
        counter->mutex = NULL;
    }

    if(counter)
    {
        AXIS2_FREE(env->allocator, counter);
    }
}

static void AXIS2_CALL
service_admin_counter_last_counts_free_void_arg(
    void *lcounts,
    const axutil_env_t *env)
{
    axutil_hash_t *last_counts = NULL;
    
    axutil_allocator_switch_to_global_pool(env->allocator);
    last_counts = (axutil_hash_t *) lcounts;
    if(last_counts)
    {
        axutil_hash_index_t *hi;
        void *val;
        void *key;
        for (hi = axutil_hash_first(last_counts, env); hi; hi = axutil_hash_next(env, hi)) 
        {
            axutil_hash_this(hi, (const void**)&key, NULL, &val);
            if(key)
            {
                AXIS2_FREE(env->allocator, key);
            }
            if(val)
            {
                AXIS2_FREE(env->allocator, val);
            }
        }
        axutil_hash_free(last_counts, env);
        last_counts = NULL;
    }
    axutil_allocator_switch_to_local_pool(env->allocator);
}

void AXIS2_CALL
service_admin_counter_increment (
    service_admin_counter_t *counter,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    axutil_thread_mutex_lock(counter->mutex);
    counter->count++;
    axutil_thread_mutex_unlock(counter->mutex);
}
 
int AXIS2_CALL
service_admin_counter_get_count (
    service_admin_counter_t *counter,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    return counter->count;
}

int AXIS2_CALL
service_admin_counter_get_last_count (
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    axis2_char_t *svc_name,
    axis2_char_t *op_name)
{
    int *count = NULL;
    axutil_hash_t *last_counts = NULL;
    axutil_property_t *property = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;

    conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
    if(svc_name && op_name)
    {
        axis2_char_t *key = NULL;
        key = axutil_strcat(env, svc_name, "-", op_name, NULL);
        property = axis2_conf_ctx_get_property(conf_ctx, env, SERVICE_ADMIN_COUNTER_LAST_OPERATION_COUNT);
        if(!property)
        {
            last_counts = axutil_hash_make(env);
            property = axutil_property_create_with_args(env, AXIS2_TRUE, AXIS2_SCOPE_APPLICATION, 
                    service_admin_counter_last_counts_free_void_arg, last_counts);
            axis2_conf_ctx_set_property(conf_ctx, env, SERVICE_ADMIN_COUNTER_LAST_OPERATION_COUNT, property);
        }
        else
        {
            last_counts = axutil_property_get_value(property, env);
        }
        count = axutil_hash_get(last_counts, key, AXIS2_HASH_KEY_STRING);
        if(count)
        {
            AXIS2_FREE(env->allocator, key);
        }
        else
        {
            count = AXIS2_MALLOC(env->allocator, sizeof(int));
            *count = 0;
            axutil_hash_set(last_counts, key, AXIS2_HASH_KEY_STRING, count);
        }
    }
    else if(svc_name)
    {
        property = axis2_conf_ctx_get_property(conf_ctx, env, SERVICE_ADMIN_COUNTER_LAST_SERVICE_COUNT);
        if(!property)
        {
            last_counts = axutil_hash_make(env);
            property = axutil_property_create_with_args(env, AXIS2_TRUE, AXIS2_SCOPE_APPLICATION,
                    service_admin_counter_last_counts_free_void_arg, last_counts);
            axis2_conf_ctx_set_property(conf_ctx, env, SERVICE_ADMIN_COUNTER_LAST_SERVICE_COUNT, property);
        }
        else
        {
            last_counts = axutil_property_get_value(property, env);
        }
        count = axutil_hash_get(last_counts, svc_name, AXIS2_HASH_KEY_STRING);
        if(!count)
        {
            count = AXIS2_MALLOC(env->allocator, sizeof(int));
            *count = 0;
            axutil_hash_set(last_counts, axutil_strdup(env, svc_name) , 
                    AXIS2_HASH_KEY_STRING, count);
        }
    }
    return *count;
}

void AXIS2_CALL
service_admin_counter_set_last_count (
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    axis2_char_t *svc_name,
    axis2_char_t *op_name,
    int last_count)
{
    int *count = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;
    axutil_property_t *property = NULL;
    axutil_hash_t *last_counts = NULL;
   
    conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
    if(svc_name && op_name)
    {
        axis2_char_t *key = NULL;
        key = axutil_strcat(env, svc_name, "-", op_name, NULL);
        property = axis2_conf_ctx_get_property(conf_ctx, env, SERVICE_ADMIN_COUNTER_LAST_OPERATION_COUNT);
        /* set_last_count is always called after get_last_count. So checking for existence of property
         * is not necessary here 
         */
        last_counts = axutil_property_get_value(property, env);
        count = axutil_hash_get(last_counts, key, AXIS2_HASH_KEY_STRING);
        *count = last_count;
        AXIS2_FREE(env->allocator, key);
    }
    else if(svc_name)
    {
        property = axis2_conf_ctx_get_property(conf_ctx, env, SERVICE_ADMIN_COUNTER_LAST_SERVICE_COUNT); 
        /* set_last_count is always called after get_last_count. So checking for existence of property
         * is not necessary here 
         */
        last_counts = axutil_property_get_value(property, env);
        count = axutil_hash_get(last_counts, svc_name, AXIS2_HASH_KEY_STRING);
        *count = last_count;
    }
}

