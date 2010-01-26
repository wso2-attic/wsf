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

#include <axis2_counter.h>
#include <axutil_string.h>
#include <axis2_msg_ctx.h>

struct axis2_counter_t
{
    int count;
    axis2_char_t *svc_name;
    axis2_char_t *op_name;
};

AXIS2_EXTERN axis2_counter_t* AXIS2_CALL
axis2_counter_create(
    const axutil_env_t *env,
    const axis2_char_t *svc_name,
    const axis2_char_t *op_name)
{
    axis2_counter_t *counter = NULL;
    
    counter =  (axis2_counter_t *)AXIS2_MALLOC(env->allocator, 
            sizeof(axis2_counter_t));
	
    if(!counter)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    counter->count = 0;
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
axis2_counter_free(
    axis2_counter_t *counter, 
    const axutil_env_t *env)
{
    if(counter)
    {
        AXIS2_FREE(env->allocator, counter);
    }
}
 
void AXIS2_CALL
axis2_counter_increment (
    axis2_counter_t *counter,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    void *stat_count_fn_arg = NULL;
    axutil_property_t *property = NULL;
    
    property = axis2_msg_ctx_get_property(msg_ctx, env, AXIS2_STATISTICS_COUNT_ARG);
    stat_count_fn_arg = axutil_property_get_value(property, env);
    counter->count = env->get_statistics_count_fn(stat_count_fn_arg, counter->op_name, counter->svc_name);
    counter->count++;
    env->set_statistics_count_fn(stat_count_fn_arg, counter->op_name, counter->svc_name, counter->count);
}
 
int AXIS2_CALL
axis2_counter_get_count (
    axis2_counter_t *counter,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    void *stat_count_fn_arg = NULL;
    axutil_property_t *property = NULL;
    
    property = axis2_msg_ctx_get_property(msg_ctx, env, AXIS2_STATISTICS_COUNT_ARG);
    stat_count_fn_arg = axutil_property_get_value(property, env);
    counter->count = env->get_statistics_count_fn(stat_count_fn_arg, counter->op_name, counter->svc_name);
    return counter->count;
}

