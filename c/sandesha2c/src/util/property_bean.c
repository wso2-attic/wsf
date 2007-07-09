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
#include <sandesha2_property_bean.h>
#include <sandesha2_constants.h>
#include <stdio.h>
#include <axutil_string.h>
#include <axutil_utils.h>

/** 
 * @brief Property Bean struct impl
 *	Sandesha2 Property Bean
 */
struct sandesha2_property_bean_t
{
    long inactive_timeout_interval;
    long ack_interval;
    long retrans_interval;
    axis2_bool_t is_exp_backoff;
    axis2_char_t *in_mem_storage_mgr;
    axis2_char_t *permanent_storage_mgr;
    axis2_char_t *storage_mgr;
    axis2_bool_t is_in_order;
    axutil_array_list_t *msg_types_to_drop;
    int max_retrans_count;
    axis2_char_t *db_path;
};

AXIS2_EXTERN sandesha2_property_bean_t* AXIS2_CALL
sandesha2_property_bean_create(
    const axutil_env_t *env)
{
    sandesha2_property_bean_t *bean = NULL;
    
    bean =  (sandesha2_property_bean_t *)AXIS2_MALLOC 
        (env->allocator, sizeof(sandesha2_property_bean_t));
	
    if(!bean)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    bean->inactive_timeout_interval = 0;
    bean->ack_interval = 0;
    bean->retrans_interval = 0;
    bean->is_exp_backoff = 0;
    bean->in_mem_storage_mgr = NULL;
    bean->permanent_storage_mgr= NULL;
    bean->storage_mgr= NULL;
    bean->is_in_order = AXIS2_FALSE;
    bean->msg_types_to_drop = NULL;
    bean->max_retrans_count = 0;
    bean->db_path = NULL;
    
	return bean;
}


axis2_status_t AXIS2_CALL 
sandesha2_property_bean_free(
    sandesha2_property_bean_t *bean, 
    const axutil_env_t *env)
{
    if(bean->msg_types_to_drop)
    {
        int count = axutil_array_list_size(bean->msg_types_to_drop,
            env);
        int i = 0;
        for(i = 0; i < count; i++)
        {
            int *msg_type = axutil_array_list_get(
                bean->msg_types_to_drop, env, i);
            if(NULL != msg_type)
                AXIS2_FREE(env->allocator, msg_type);
        }
        axutil_array_list_free(bean->msg_types_to_drop, env);
    }
    if(bean->db_path)
    {
        AXIS2_FREE(env->allocator, bean->db_path);
        bean->db_path = NULL;
    }
    if(bean->in_mem_storage_mgr)
    {
        AXIS2_FREE(env->allocator, bean->in_mem_storage_mgr);
        bean->in_mem_storage_mgr = NULL;
    }
    if(bean->permanent_storage_mgr)
    {
        AXIS2_FREE(env->allocator, bean->permanent_storage_mgr);
        bean->permanent_storage_mgr = NULL;
    }
	AXIS2_FREE(env->allocator, bean);
	return AXIS2_SUCCESS;
}

long AXIS2_CALL 
sandesha2_property_bean_get_inactive_timeout_interval(
    sandesha2_property_bean_t *bean, 
    const axutil_env_t *env)
{
    return bean->inactive_timeout_interval;
}
            
axis2_status_t AXIS2_CALL
sandesha2_property_bean_set_inactive_timeout_interval(
    sandesha2_property_bean_t *bean,
    const axutil_env_t *env, long interval)
{
    bean->inactive_timeout_interval = interval;
    return AXIS2_SUCCESS;
}
            
axis2_status_t AXIS2_CALL
sandesha2_property_bean_set_inactive_timeout_interval_with_units(
    sandesha2_property_bean_t *bean,
    const axutil_env_t *env, long interval,
    axis2_char_t *units)
{
    long multiplier = -1;
    
    AXIS2_PARAM_CHECK(env->error, units, AXIS2_FAILURE);
    
    if(0 == axutil_strcmp(units, "seconds"))
        multiplier = 1000;
    else if(0 == axutil_strcmp(units, "minutes"))
        multiplier = 60*1000;
    else if(0 == axutil_strcmp(units, "hours"))
        multiplier = 60*60*1000;
    else if(0 == axutil_strcmp(units, "days"))
        multiplier = 24*60*60*1000;
    else
        return AXIS2_FAILURE;
        
    return sandesha2_property_bean_set_inactive_timeout_interval(bean, env, 
        multiplier*interval);
}
            
long AXIS2_CALL
sandesha2_property_bean_get_ack_interval(
    sandesha2_property_bean_t *bean,
    const axutil_env_t *env)
{
    return bean->ack_interval;
}
            
axis2_status_t AXIS2_CALL
sandesha2_property_bean_set_ack_interval(
    sandesha2_property_bean_t *bean,
    const axutil_env_t *env, long interval)
{
    bean->ack_interval = interval;
    return AXIS2_SUCCESS;
}
            
long AXIS2_CALL
sandesha2_property_bean_get_retrans_interval( 
    sandesha2_property_bean_t *bean,
    const axutil_env_t *env)
{
    return bean->retrans_interval;
}
            
axis2_status_t AXIS2_CALL
sandesha2_property_bean_set_retrans_interval(
    sandesha2_property_bean_t *bean,
    const axutil_env_t *env, long interval)
{
    bean->retrans_interval = interval;
    return AXIS2_SUCCESS;
}
            
axis2_bool_t AXIS2_CALL
sandesha2_property_bean_is_exp_backoff(
    sandesha2_property_bean_t *bean,
    const axutil_env_t *env)

{
    return bean->is_exp_backoff;
}
            
axis2_status_t AXIS2_CALL
sandesha2_property_bean_set_exp_backoff(
    sandesha2_property_bean_t *bean,
    const axutil_env_t *env, axis2_bool_t exp_backoff)
{
    bean->is_exp_backoff = exp_backoff;
    return AXIS2_SUCCESS;
}
            
axis2_char_t* AXIS2_CALL
sandesha2_property_bean_get_in_mem_storage_mgr(
    sandesha2_property_bean_t *bean,
    const axutil_env_t *env)
{
    return bean->in_mem_storage_mgr;
}
            
axis2_status_t AXIS2_CALL
sandesha2_property_bean_set_in_mem_storage_mgr(
    sandesha2_property_bean_t *bean,
    const axutil_env_t *env, axis2_char_t *manager)
{
    AXIS2_PARAM_CHECK(env->error, manager, AXIS2_FAILURE);
    bean->in_mem_storage_mgr = axutil_strdup(env, manager);
    return AXIS2_SUCCESS;
}
            
axis2_char_t* AXIS2_CALL
sandesha2_property_bean_get_permanent_storage_mgr(
    sandesha2_property_bean_t *bean,
    const axutil_env_t *env)
{
    return bean->permanent_storage_mgr;
}
            
axis2_status_t AXIS2_CALL
sandesha2_property_bean_set_permanent_storage_mgr(
    sandesha2_property_bean_t *bean,
    const axutil_env_t *env, axis2_char_t *manager)
{
    AXIS2_PARAM_CHECK(env->error, manager, AXIS2_FAILURE);
    bean->permanent_storage_mgr = axutil_strdup(env, manager);
    return AXIS2_SUCCESS;
}
 
axis2_char_t* AXIS2_CALL
sandesha2_property_bean_get_storage_mgr(
    sandesha2_property_bean_t *bean,
    const axutil_env_t *env)
{
    return bean->storage_mgr;
}
            
axis2_status_t AXIS2_CALL
sandesha2_property_bean_set_storage_mgr(
    sandesha2_property_bean_t *bean,
    const axutil_env_t *env, 
    axis2_char_t *manager)
{
    AXIS2_PARAM_CHECK(env->error, manager, AXIS2_FAILURE);
    bean->storage_mgr = axutil_strdup(env, manager);
    return AXIS2_SUCCESS;
}
            
axis2_bool_t AXIS2_CALL
sandesha2_property_bean_is_in_order(
    sandesha2_property_bean_t *bean,
    const axutil_env_t *env)
{
    return bean->is_in_order;
}
            
axis2_status_t AXIS2_CALL
sandesha2_property_bean_set_in_order(
    sandesha2_property_bean_t *bean,
    const axutil_env_t *env, axis2_bool_t in_order)
{
    bean->is_in_order = in_order;
    return AXIS2_SUCCESS;
}
            
axutil_array_list_t* AXIS2_CALL
sandesha2_property_bean_get_msg_types_to_drop(
    sandesha2_property_bean_t *bean,
    const axutil_env_t *env)
{
    return bean->msg_types_to_drop;
}
            
axis2_status_t AXIS2_CALL
sandesha2_property_bean_set_msg_types_to_drop(
    sandesha2_property_bean_t *bean,
    const axutil_env_t *env, 
    axutil_array_list_t *msg_types)
{
    AXIS2_PARAM_CHECK(env->error, msg_types, AXIS2_FAILURE);
    bean->msg_types_to_drop = msg_types;
    return AXIS2_SUCCESS;
}
            
axis2_status_t AXIS2_CALL
sandesha2_property_bean_add_msg_type_to_drop(
    sandesha2_property_bean_t *bean,
    const axutil_env_t *env, 
    int msg_type)
{
    int *_msg_type = NULL;
    if(!bean->msg_types_to_drop)
        return AXIS2_FAILURE;
    _msg_type = AXIS2_MALLOC(env->allocator, sizeof(int));
    axutil_array_list_add(bean->msg_types_to_drop, env, _msg_type);
    return AXIS2_SUCCESS;
}
            
int AXIS2_CALL
sandesha2_property_bean_get_max_retrans_count (
    sandesha2_property_bean_t *bean,
    const axutil_env_t *env)
{
    return bean->max_retrans_count;
}
            
axis2_status_t AXIS2_CALL
sandesha2_property_bean_set_max_retrans_count(
    sandesha2_property_bean_t *bean,
    const axutil_env_t *env, int count)
{
    bean->max_retrans_count = count;
    return AXIS2_SUCCESS;
}

axis2_char_t *AXIS2_CALL
sandesha2_property_bean_get_db_path(
    sandesha2_property_bean_t *bean,
    const axutil_env_t *env)
{
    return bean->db_path;
}
axis2_status_t AXIS2_CALL
sandesha2_property_bean_set_db_path(
    sandesha2_property_bean_t *bean,
    const axutil_env_t *env,
    axis2_char_t *db_path)
{
    bean->db_path = axutil_strdup(env, db_path);
    return AXIS2_SUCCESS;
}

