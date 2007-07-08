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

#include <config.h>
#include "axutil_thread_unix.h"


AXIS2_EXTERN axutil_threadattr_t* AXIS2_CALL
axutil_threadattr_create(axutil_allocator_t* allocator)
{
    int stat = 0;
    axutil_threadattr_t *new = NULL;

    new = AXIS2_MALLOC(allocator, sizeof(axutil_threadattr_t));
    if (!new)
    {
        return NULL;
    }
    stat = pthread_attr_init(&(new->attr));

    if (stat != 0)
    {
        AXIS2_FREE(allocator, new);
        return NULL;
    }
    return new;
}

/* Destroy the threadattr object */
AXIS2_EXTERN axis2_status_t AXIS2_CALL
threadattr_cleanup(void *data)
{
    axutil_threadattr_t *attr = data;
    int rv;

    rv = pthread_attr_destroy(&(attr->attr));

    if (0 != rv)
    {
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}

#define DETACH_ARG(v) ((v) ? PTHREAD_CREATE_DETACHED : PTHREAD_CREATE_JOINABLE)

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_threadattr_detach_set(axutil_threadattr_t *attr, axis2_bool_t detached)
{
    if (0 == pthread_attr_setdetachstate(&(attr->attr), DETACH_ARG(detached)))
    {
        return AXIS2_SUCCESS;
    }
    return AXIS2_FAILURE;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_threadattr_detach_get(axutil_threadattr_t *attr)
{
    int state = 0;
    pthread_attr_getdetachstate(&(attr->attr), &state);
    if (state == 1)
    {
        return AXIS2_TRUE;
    }
    return AXIS2_FALSE;
}

static void *dummy_worker(void *opaque)
{
    axutil_thread_t *thread = (axutil_thread_t*)opaque;
    return thread->func(thread, thread->data);
}

AXIS2_EXTERN axutil_thread_t* AXIS2_CALL
axutil_thread_create(axutil_allocator_t* allocator, axutil_threadattr_t *attr,
    axutil_thread_start_t func, void *data)
{
    axis2_status_t stat;
    pthread_attr_t *temp = NULL;
    axutil_thread_t *new = NULL;

    new = (axutil_thread_t *)AXIS2_MALLOC(allocator, sizeof(axutil_thread_t));

    if (!new)
    {
        return NULL;
    }
    new->td = (pthread_t *)AXIS2_MALLOC(allocator, sizeof(pthread_t));
    if (!new->td)
    {
        return NULL;
    }

    new->data = data;
    new->func = func;

    if (attr)
    {
        temp = &(attr->attr);
    }
    else
    {
        temp = NULL;
    }

    if ((stat = pthread_create(new->td, temp, dummy_worker, new)) == 0)
    {
        return new;
    }
    return NULL;
}

AXIS2_EXTERN axis2_os_thread_t AXIS2_CALL
axis2_os_thread_current(void)
{
    return pthread_self();
}

AXIS2_EXTERN int AXIS2_CALL
axis2_os_thread_equal(axis2_os_thread_t tid1, axis2_os_thread_t tid2)
{
    return pthread_equal(tid1, tid2);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_thread_exit(axutil_thread_t *thd, axutil_allocator_t *allocator)
{
    if (thd)
    {
        if (thd->td)
        {
            AXIS2_FREE(allocator, thd->td);
        }
        AXIS2_FREE(allocator, thd);
    }
    pthread_exit(NULL);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_thread_join(axutil_thread_t *thd)
{
    void *thread_stat;
    if (0 == pthread_join(*(thd->td), (void *)(&thread_stat)))
    {
        return AXIS2_SUCCESS;
    }
    return AXIS2_FAILURE;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_thread_detach(axutil_thread_t *thd)
{
    if (0 == pthread_detach(*(thd->td)))
    {
        return AXIS2_SUCCESS;
    }
    return AXIS2_FAILURE;
}

void axutil_thread_yield(void)
{
    return;
}

/**
 * function is used to allocate a new key. This key now becomes valid for all threads in our process. 
 * When a key is created, the value it points to defaults to NULL. Later on each thread may change 
 * its copy of the value as it wishes.
 */
AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_thread_key_create(
    axutil_threadkey_t *axis2_key,
    void (*destructor)(void *))
{
    int rc = -1;
    pthread_key_t key = axis2_key->key;
    rc = pthread_key_create(&key, destructor);
    if(0 == rc)
        return AXIS2_SUCCESS;
    else
        return AXIS2_FAILURE;
}

/**
 * This function is used to get the value of a given key
 * @return void*. A key's value is simply a void pointer (void*)
 */
AXIS2_EXTERN void * AXIS2_CALL
axutil_thread_getspecific(
    axutil_threadkey_t *axis2_key)
{
    void *value = NULL;
    pthread_key_t key = axis2_key->key;
    value = pthread_getspecific(key);
    return value;
}

/**
 * This function is used to get the value of a given key
 * @param keys value. A key's value is simply a void pointer (void*), so we can 
 *        store in it anything that we want
 */
AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_thread_setspecific(
    axutil_threadkey_t *axis2_key,
    void *value)
{
    int rc = -1;
    pthread_key_t key = axis2_key->key;
    rc = pthread_setspecific(key, value);
    if(0 == rc)
        return AXIS2_SUCCESS;
    else
        return AXIS2_FAILURE;
}

AXIS2_EXTERN axis2_os_thread_t* AXIS2_CALL
axis2_os_thread_get(axutil_thread_t *thd)
{
    if (!thd)
    {
        return NULL;
    }
    return thd->td;
}

AXIS2_EXTERN axutil_thread_once_t* AXIS2_CALL
axutil_thread_once_init(axutil_allocator_t* allocator)
{
#ifdef AXIS2_SOLARIS
    static const pthread_once_t once_init = {PTHREAD_ONCE_INIT};
#else
    static const pthread_once_t once_init = PTHREAD_ONCE_INIT;
#endif
    axutil_thread_once_t *control = AXIS2_MALLOC(allocator,
            sizeof(axutil_thread_once_t));
    if (!control)
    {
        return NULL;
        ;
    }
    (control)->once = once_init;
    return control;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_thread_once(axutil_thread_once_t *control, void(*func)(void))
{
    return pthread_once(&(control->once), func);
}

/*************************Thread locking functions*****************************/
AXIS2_EXTERN axutil_thread_mutex_t * AXIS2_CALL
axutil_thread_mutex_create(axutil_allocator_t *allocator, unsigned int flags)
{
    axutil_thread_mutex_t *new_mutex = NULL;

    new_mutex = AXIS2_MALLOC(allocator, sizeof(axutil_thread_mutex_t));
    new_mutex->allocator = allocator;

    if (pthread_mutex_init(&(new_mutex->mutex), NULL) != 0)
    {
        AXIS2_FREE(allocator, new_mutex);
        return NULL;
    }
    return new_mutex;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_thread_mutex_lock(axutil_thread_mutex_t *mutex)
{
    return pthread_mutex_lock(&(mutex->mutex));
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_thread_mutex_unlock(axutil_thread_mutex_t *mutex)
{
    if (pthread_mutex_unlock(&(mutex->mutex)) != 0)
    {
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_thread_mutex_destroy(axutil_thread_mutex_t *mutex)
{
    if (0 != pthread_mutex_destroy(&(mutex->mutex)))
    {
        return AXIS2_FAILURE;
    }
    AXIS2_FREE(mutex->allocator, mutex);
    return AXIS2_SUCCESS;
}

