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

#include <service_admin_response_time_processor.h>
#include <axutil_utils.h>

AXIS2_EXTERN service_admin_response_time_processor_t* AXIS2_CALL
service_admin_response_time_processor_create(
    const axutil_env_t *env)
{
    service_admin_response_time_processor_t *res_time_proc = NULL;
    
    res_time_proc =  (service_admin_response_time_processor_t *)AXIS2_MALLOC(env->allocator, 
            sizeof(service_admin_response_time_processor_t));
	
    if(!res_time_proc)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    res_time_proc->max_response_time = 0;
    res_time_proc->min_response_time = -1;
    res_time_proc->avg_response_time = 0.0;
    res_time_proc->total_response_time = 0.0;

	return res_time_proc;
}

void AXIS2_CALL 
service_admin_response_time_processor_free(
    service_admin_response_time_processor_t *res_time_proc, 
    const axutil_env_t *env)
{
    if(res_time_proc)
    {
        AXIS2_FREE(env->allocator, res_time_proc);
    }
}
 
axis2_status_t AXIS2_CALL
service_admin_response_time_processor_add_response_time (
    service_admin_response_time_processor_t *res_time_proc,
    const axutil_env_t *env,
    long response_time,
    long request_count)
{
    if(res_time_proc->max_response_time < response_time)
    {
        res_time_proc->max_response_time = response_time;
    }
    
    if(res_time_proc->min_response_time > response_time)
    {
        res_time_proc->min_response_time = response_time;
    }

    if(res_time_proc->min_response_time == -1)
    {
        res_time_proc->min_response_time = response_time;
    }

    res_time_proc->total_response_time = res_time_proc->total_response_time + response_time;
    res_time_proc->avg_response_time = res_time_proc->total_response_time / request_count;
   
    return AXIS2_SUCCESS;
}
 
