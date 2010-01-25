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

AXIS2_EXTERN axis2_counter_t* AXIS2_CALL
axis2_counter_create(
    const axutil_env_t *env)
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
    counter->mutex = axutil_thread_mutex_create(env->allocator, AXIS2_THREAD_MUTEX_DEFAULT);
    if(!counter->mutex)
    {
        axis2_counter_free(counter, env);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Counter mutex creation failed");
        return NULL;
    }

	return counter;
}

axis2_status_t AXIS2_CALL 
axis2_counter_free(
    axis2_counter_t *counter, 
    const axutil_env_t *env)
{
    if(counter->mutex)
    {
        axutil_thread_mutex_destroy(counter->mutex);
    }
    if(counter)
    {
        AXIS2_FREE(env->allocator, counter);
    }
}
 
void AXIS2_CALL
axis2_counter_increment (
    axis2_counter_t *counter,
    const axutil_env_t *env)
{
    axutil_thread_mutex_lock(counter->mutex);
    counter->count++;
    axutil_thread_mutex_unlock(counter->mutex);
}
 
