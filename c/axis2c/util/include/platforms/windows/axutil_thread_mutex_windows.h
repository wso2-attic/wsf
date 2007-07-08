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

#ifndef AXIS2_THREAD_MUTEX_WINDOWS_H
#define AXIS2_THREAD_MUTEX_WINDOWS_H

#include <process.h>
#include <windows.h>
#include <axutil_allocator.h>
typedef enum thread_mutex_type 
{
    thread_mutex_critical_section,
    thread_mutex_unnested_event,
    thread_mutex_nested_mutex
} thread_mutex_type;

/* handle applies only to unnested_event on all platforms 
 * and nested_mutex on Win9x only.  Otherwise critical_section 
 * is used for NT nexted mutexes providing optimal performance.
 */
struct axutil_thread_mutex_t 
{
    thread_mutex_type type;
    HANDLE            handle;
    CRITICAL_SECTION  section;
    axutil_allocator_t *allocator;
};

#endif  /* AXIS2_THREAD_MUTEX_WINDOWS_H */

