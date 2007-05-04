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

#ifndef AXIS2_THREAD_WINDOWS_H
#define AXIS2_THREAD_WINDOWS_H

#include <windows.h>
#include <process.h>
#include <axutil_thread.h>

#define SHELL_PATH "cmd.exe"

typedef HANDLE axis2_os_thread_t; /* Native thread */
/* Chosen for us by apr_initialize */


struct axutil_thread_t 
{
   HANDLE *td;
    void *data;
    axutil_thread_start_t func;
};

struct axutil_threadattr_t 
{
    int detach;
    size_t stacksize;
};

struct axutil_threadkey_t 
{
   DWORD key;
};

struct axutil_thread_once_t 
{
   long value;
};

AXIS2_EXTERN axutil_threadattr_t* AXIS2_CALL
axutil_threadattr_create(axutil_allocator_t *allocator);

/* Destroy the threadattr object */
AXIS2_EXTERN axis2_status_t AXIS2_CALL
threadattr_cleanup(void *data);

AXIS2_EXTERN axis2_status_t AXIS2_CALL axutil_threadattr_detach_set(
    axutil_threadattr_t *attr,
    axis2_bool_t detached);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_threadattr_detach_get(axutil_threadattr_t *attr, const axutil_env_t *env);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_threadattr_stacksize_set(axutil_threadattr_t *attr, size_t stacksize);


AXIS2_EXTERN axutil_thread_t* AXIS2_CALL
axutil_thread_create(axutil_allocator_t *allocator, axutil_threadattr_t *attr,
        axutil_thread_start_t func, void *data);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_thread_exit(axutil_thread_t *thd, axutil_allocator_t *allocator);

AXIS2_EXTERN axis2_os_thread_t AXIS2_CALL
axis2_os_thread_current(void);

AXIS2_EXTERN int AXIS2_CALL
axis2_os_thread_equal(axis2_os_thread_t tid1, axis2_os_thread_t tid2);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_thread_join(axutil_thread_t *thd);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_thread_detach(axutil_thread_t *thd);

AXIS2_EXTERN axis2_os_thread_t AXIS2_CALL
axis2_os_thread_get(axutil_thread_t *thd, const axutil_env_t *env);

AXIS2_EXTERN axutil_thread_once_t * AXIS2_CALL
axutil_thread_once_init(axutil_allocator_t *allocator);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_thread_once(axutil_thread_once_t *control, void(*func)(void));

#endif  /* AXIS2_THREAD_WINDOWS_H */
