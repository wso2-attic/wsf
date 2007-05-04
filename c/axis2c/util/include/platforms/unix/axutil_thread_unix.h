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

#ifndef AXUTIL_THREAD_UNIX_H
#define AXUTIL_THREAD_UNIX_H

#include <axutil_thread.h>
#include <pthread.h>

#define SHELL_PATH "/bin/sh"

typedef pthread_t axis2_os_thread_t; /* Native thread */

struct axutil_thread_t {
    pthread_t *td;
    void *data;
    axutil_thread_start_t func;
};

struct axutil_threadattr_t {
    pthread_attr_t attr;
};

struct axutil_threadkey_t {
    pthread_key_t key;
};

struct axutil_thread_once_t {
    pthread_once_t once;
};

/*************************Thread locking functions*****************************/
struct axutil_thread_mutex_t {
    axutil_allocator_t *allocator;
    pthread_mutex_t mutex;
};

#endif  /* AXIS2_THREAD_UNIX_H */
