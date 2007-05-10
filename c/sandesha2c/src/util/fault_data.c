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
#include <sandesha2_fault_data.h>
#include <sandesha2_constants.h>
#include <axutil_string.h>


/** 
 * @brief Fault Data struct impl
 *	Sandesha2 Fault Data
 */
  
struct sandesha2_fault_data_t
{
    int type;
    axis2_char_t *code;
    axis2_char_t *sub_code;
    axis2_char_t *reason;
    axis2_char_t *seq_id;
    axiom_node_t *detail;
};

AXIS2_EXTERN sandesha2_fault_data_t* AXIS2_CALL
sandesha2_fault_data_create(
    const axutil_env_t *env)
{
    sandesha2_fault_data_t *fault_data = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    
    fault_data =  (sandesha2_fault_data_t *)AXIS2_MALLOC 
                        (env->allocator, sizeof(sandesha2_fault_data_t));
	
    if(!fault_data)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    fault_data->type = -1;
    fault_data->code = NULL;
    fault_data->sub_code = NULL;
    fault_data->reason = NULL;
    fault_data->seq_id = NULL;
    fault_data->detail = NULL;
    
	return fault_data;
}


axis2_status_t AXIS2_CALL 
sandesha2_fault_data_free(
    sandesha2_fault_data_t *data, 
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    data->type = -1;
    if(data->code)
    {
        AXIS2_FREE(env->allocator, data->code);
        data->code = NULL;
    }
    if(data->sub_code)
    {
        AXIS2_FREE(env->allocator, data->sub_code);
        data->sub_code = NULL;
    }
    if(data->reason)
    {
        AXIS2_FREE(env->allocator, data->reason);
        data->reason = NULL;
    }
    if(data->seq_id)
    {
        AXIS2_FREE(env->allocator, data->seq_id);
        data->seq_id = NULL;
    }
    /* Not sure we have to free this.
     * TODO consider in memory cleaning stage
     */
    data->detail = NULL;
    
	AXIS2_FREE(env->allocator, data);
	return AXIS2_SUCCESS;
}

axiom_node_t *AXIS2_CALL 
sandesha2_fault_data_get_detail(
    sandesha2_fault_data_t *data,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    return data->detail;
}
            
axis2_status_t AXIS2_CALL 
sandesha2_fault_data_set_detail(
    sandesha2_fault_data_t *data,
    const axutil_env_t *env,
    axiom_node_t *detail)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, detail, AXIS2_FAILURE);
    
    data->detail = detail;
    return AXIS2_SUCCESS;
}
            
axis2_char_t *AXIS2_CALL 
sandesha2_fault_data_get_reason(
    sandesha2_fault_data_t *data,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    return data->reason;
}
            
axis2_status_t AXIS2_CALL 
sandesha2_fault_data_set_reason(
    sandesha2_fault_data_t *data,
    const axutil_env_t *env,
    axis2_char_t *reason)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, reason, AXIS2_FAILURE);
    
    if(data->reason)
    {
        AXIS2_FREE(env->allocator, data->reason);
        data->reason = NULL;
    }
    data->reason = axutil_strdup(env, reason);
    return AXIS2_SUCCESS;
}

axis2_char_t *AXIS2_CALL 
sandesha2_fault_data_get_sub_code( 
    sandesha2_fault_data_t *data,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    return data->sub_code;
}
            
axis2_status_t AXIS2_CALL 
sandesha2_fault_data_set_sub_code(
    sandesha2_fault_data_t *data,
    const axutil_env_t *env,
    axis2_char_t *sub_code)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, sub_code, AXIS2_FAILURE);
    
    if(data->sub_code)
    {
        AXIS2_FREE(env->allocator, data->sub_code);
        data->sub_code = NULL;
    }
    data->sub_code = axutil_strdup(env, sub_code);
    return AXIS2_SUCCESS;
}
            
axis2_char_t *AXIS2_CALL 
sandesha2_fault_data_get_code(
    sandesha2_fault_data_t *data,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    return data->code;
}
            
axis2_status_t AXIS2_CALL 
sandesha2_fault_data_set_code(
    sandesha2_fault_data_t *data,
    const axutil_env_t *env,
    axis2_char_t *code)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, code, AXIS2_FAILURE);
    
    if(data->code)
    {
        AXIS2_FREE(env->allocator, data->code);
        data->code = NULL;
    }
    data->code = axutil_strdup(env, code);
    return AXIS2_SUCCESS;
}
            
int AXIS2_CALL 
sandesha2_fault_data_get_type(
    sandesha2_fault_data_t *data,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, -1);
    return data->type;
}
            
axis2_status_t AXIS2_CALL 
sandesha2_fault_data_set_type(
    sandesha2_fault_data_t *data,
    const axutil_env_t *env,
    int type)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    data->type = type;
    return AXIS2_SUCCESS;
}
            
axis2_char_t *AXIS2_CALL 
sandesha2_fault_data_get_seq_id(
    sandesha2_fault_data_t *data,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    return data->seq_id;
}
            
axis2_status_t AXIS2_CALL 
sandesha2_fault_data_set_seq_id( 
    sandesha2_fault_data_t *data,
    const axutil_env_t *env,
    axis2_char_t *seq_id)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, seq_id, AXIS2_FAILURE);
    
    if(data->seq_id)
    {
        AXIS2_FREE(env->allocator, data->seq_id);
        data->seq_id = NULL;
    }
    data->seq_id = axutil_strdup(env, seq_id);
    return AXIS2_SUCCESS;
    
}

