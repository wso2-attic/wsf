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

#include <axutil_utils.h>
#include <platforms/windows/axutil_thread_windows.h>

DWORD tls_axutil_thread = 0;

AXIS2_EXTERN axutil_threadattr_t* AXIS2_CALL
axutil_threadattr_create(axutil_allocator_t *allocator)
{
    axutil_threadattr_t *new = NULL;

    new = AXIS2_MALLOC(allocator, sizeof(axutil_threadattr_t));
    if (! new)
    {
        /*AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE)*/
        return NULL;
    }
    new->detach = 0;
    new->stacksize = 0;

    return new;
}

/* Destroy the threadattr object */
AXIS2_EXTERN axis2_status_t AXIS2_CALL
threadattr_cleanup(void *data)
{
    axutil_threadattr_t *attr = data;
    /*nothing to clean up*/
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL axutil_threadattr_detach_set(
    axutil_threadattr_t *attr,
    axis2_bool_t detached)
{
    attr->detach = detached;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_threadattr_detach_get(axutil_threadattr_t *attr, const axutil_env_t *env)
{
    if (1 == attr->detach)
    {
        return AXIS2_TRUE;
    }
    return AXIS2_FALSE;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_threadattr_stacksize_set(axutil_threadattr_t *attr, size_t stacksize)
{
    attr->stacksize = stacksize;
    return AXIS2_SUCCESS;
}

static void *dummy_worker(void *opaque)
{
    axutil_thread_t *thd = (axutil_thread_t *)opaque;
    TlsSetValue(tls_axutil_thread, thd->td);
    return thd->func(thd, thd->data);
}

AXIS2_EXTERN axutil_thread_t* AXIS2_CALL
axutil_thread_create(axutil_allocator_t *allocator, axutil_threadattr_t *attr,
        axutil_thread_start_t func, void *data)
{
    HANDLE           handle;
    unsigned         temp;
    axutil_thread_t   *new = NULL;

    new = (axutil_thread_t *)AXIS2_MALLOC(allocator,
            sizeof(axutil_thread_t));

    if (! new)
    {
        return NULL;
    }

    new->data = data;
    new->func = func;
    new->td   = NULL;

    /* Use 0 for Thread Stack Size, because that will default the stack to the
      * same size as the calling thread. 
      */
    if ((handle = CreateThread(NULL,
            attr && attr->stacksize > 0 ? attr->stacksize : 0,
            (unsigned int(AXIS2_THREAD_FUNC *)(void *))dummy_worker,
            new, 0, &temp)) == 0)
    {
        return NULL;
    }

    if (attr && attr->detach)
    {
        CloseHandle(handle);
    }
    else
        new->td = handle;

    return new;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_thread_exit(axutil_thread_t *thd, axutil_allocator_t *allocator)
{
    if (thd)
    {
        AXIS2_FREE(allocator, thd);
    }
    ExitThread(0);

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_os_thread_t AXIS2_CALL
axis2_os_thread_current(void)
{
    HANDLE hthread = (HANDLE)TlsGetValue(tls_axutil_thread);
    HANDLE hproc;

    if (hthread)
    {
        return hthread;
    }

    hproc = GetCurrentProcess();
    hthread = GetCurrentThread();
    if (!DuplicateHandle(hproc, hthread,
            hproc, &hthread, 0, FALSE,
            DUPLICATE_SAME_ACCESS))
    {
        return NULL;
    }
    TlsSetValue(tls_axutil_thread, hthread);
    return hthread;
}

AXIS2_EXTERN int AXIS2_CALL
axis2_os_thread_equal(axis2_os_thread_t tid1, axis2_os_thread_t tid2)
{
    return (tid1 == tid2);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_thread_join(axutil_thread_t *thd)
{
    axis2_status_t rv = AXIS2_SUCCESS, rv1;

    if (!thd->td)
    {
        /* Can not join on detached threads */
        return AXIS2_FAILURE;
    }
    rv1 = WaitForSingleObject(thd->td, INFINITE);
    if (rv1 == WAIT_OBJECT_0 || rv1 == WAIT_ABANDONED)
    {
        /*rv = AXIS2_INCOMPLETE;*/
    }
    else
        rv = AXIS2_FAILURE;
    CloseHandle(thd->td);
    thd->td = NULL;

    return rv;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_thread_detach(axutil_thread_t *thd)
{
    if (thd->td && CloseHandle(thd->td))
    {
        thd->td = NULL;
        return AXIS2_SUCCESS;
    }
    else
    {
        return AXIS2_FAILURE;
    }
}

AXIS2_EXTERN axis2_os_thread_t AXIS2_CALL
axis2_os_thread_get(axutil_thread_t *thd, const axutil_env_t *env)
{
    return thd->td;
}

AXIS2_EXTERN axutil_thread_once_t * AXIS2_CALL
axutil_thread_once_init(axutil_allocator_t *allocator)
{
    axutil_thread_once_t *control = NULL;
    control = AXIS2_MALLOC(allocator, sizeof(*control));
    return control;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_thread_once(axutil_thread_once_t *control, void(*func)(void))
{
    if (!InterlockedExchange(&control->value, 1))
    {
        func();
    }
    return AXIS2_SUCCESS;
}
