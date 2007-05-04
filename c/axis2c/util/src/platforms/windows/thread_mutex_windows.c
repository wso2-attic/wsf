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


#include <axutil_thread.h>
#include <platforms/windows/axutil_thread_mutex_windows.h>

static axis2_status_t thread_mutex_cleanup(void *data)
{
    axutil_thread_mutex_t *lock = NULL;
    axutil_allocator_t *allocator = NULL;
    if (!data)
        return AXIS2_FAILURE;

    lock = (axutil_thread_mutex_t *)data;
    allocator = lock ->allocator;

if (lock ->type == thread_mutex_critical_section)
    {
        DeleteCriticalSection(&lock ->section);
    }
    else
    {
        if (!CloseHandle(lock ->handle))
        {
            return AXIS2_FAILURE;
        }
    }

    AXIS2_FREE(allocator, lock);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axutil_thread_mutex_t * AXIS2_CALL axutil_thread_mutex_create(axutil_allocator_t *allocator,
        unsigned int flags)
{
    axutil_thread_mutex_t *mutex = NULL;

    mutex = (axutil_thread_mutex_t *)AXIS2_MALLOC(allocator, sizeof(axutil_thread_mutex_t));
    mutex->allocator = allocator;

    if (flags == AXIS2_THREAD_MUTEX_DEFAULT) /*unnested*/
    {
        /* Use an auto-reset signaled event, ready to accept one
         * waiting thread.
         */
        mutex->type = thread_mutex_unnested_event;
        mutex->handle = CreateEvent(NULL, FALSE, TRUE, NULL);
    }
    else
    {
        /* TODO :support critical_section and nested_mutex*/
    }

    return mutex;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_thread_mutex_lock(axutil_thread_mutex_t *mutex)
{
    if (mutex->type == thread_mutex_critical_section)
    {
        EnterCriticalSection(&mutex->section);
    }
    else
    {
        DWORD rv = WaitForSingleObject(mutex->handle, INFINITE);
        if ((rv != WAIT_OBJECT_0) && (rv != WAIT_ABANDONED))
        {
            return AXIS2_FAILURE;
            /*can be either BUSY or an os specific error*/
        }
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_thread_mutex_trylock(axutil_thread_mutex_t *mutex)
{

    if (mutex->type == thread_mutex_critical_section)
    {
        /* TODO :implement trylock for critical section*/
    }
    else
    {
        DWORD rv = WaitForSingleObject(mutex->handle, 0);
        if ((rv != WAIT_OBJECT_0) && (rv != WAIT_ABANDONED))
        {
            /*can be either BUSY or an os specific error*/
            return AXIS2_FAILURE;
        }
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_thread_mutex_unlock(axutil_thread_mutex_t *mutex)
{
    if (mutex->type == thread_mutex_critical_section)
    {
        LeaveCriticalSection(&mutex->section);
    }
    else if (mutex->type == thread_mutex_unnested_event)
    {
        if (!SetEvent(mutex->handle))
        {
            /*os specific error*/
            return AXIS2_FAILURE;
        }
    }
    else if (mutex->type == thread_mutex_nested_mutex)
    {
        if (!ReleaseMutex(mutex->handle))
        {
            /*os specific error*/
            return AXIS2_FAILURE;
        }
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_thread_mutex_destroy(axutil_thread_mutex_t *mutex)
{
    return thread_mutex_cleanup((void*)mutex);
}
