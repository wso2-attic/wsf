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


#ifndef AXIS2_THREAD_MUTEX_H
#define AXIS2_THREAD_MUTEX_H

/**
 * @file axutil_thread_mutex.h
 * @brief AXIS2 Thread Mutex Routines
 */

#include <axis2_const.h>
#include <axutil_allocator.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/**
 * @defgroup axis2_mutex thread mutex routines
 * @ingroup axis2_util 
 * @{
 */

/** Opaque thread-local mutex structure */
typedef struct axutil_thread_mutex_t axutil_thread_mutex_t;

#define AXIS2_THREAD_MUTEX_DEFAULT  0x0   /**< platform-optimal lock behavior */
#define AXIS2_THREAD_MUTEX_NESTED   0x1   /**< enable nested (recursive) locks */
#define AXIS2_THREAD_MUTEX_UNNESTED 0x2   /**< disable nested locks */

/**
 * Create and initialize a mutex that can be used to synchronize threads.
 * 
 * @param flags Or'ed value of:
 * <PRE>
 *           AXIS2_THREAD_MUTEX_DEFAULT   platform-optimal lock behavior.
 *           AXIS2_THREAD_MUTEX_NESTED    enable nested (recursive) locks.
 *           AXIS2_THREAD_MUTEX_UNNESTED  disable nested locks (non-recursive).
 * </PRE>
 * @param allocator the allocator from which to allocate the mutex.
 * @return mutex the memory address where the newly created mutex will be
 *        stored.
 * @warning Be cautious in using AXIS2_THREAD_MUTEX_DEFAULT.  While this is the
 * most optimial mutex based on a given platform's performance charateristics,
 * it will behave as either a nested or an unnested lock.
 */
AXIS2_EXTERN axutil_thread_mutex_t * AXIS2_CALL 
axutil_thread_mutex_create(axutil_allocator_t *allocator,
                          unsigned int flags);
/**
 * Acquire the lock for the given mutex. If the mutex is already locked,
 * the current thread will be put to sleep until the lock becomes available.
 * @param mutex the mutex on which to acquire the lock.
 */
AXIS2_EXTERN axis2_status_t AXIS2_CALL 
axutil_thread_mutex_lock(axutil_thread_mutex_t *mutex);

/**
 * Attempt to acquire the lock for the given mutex. If the mutex has already
 * been acquired, the call returns immediately 
 * @param mutex the mutex on which to attempt the lock acquiring.
 */
AXIS2_EXTERN axis2_status_t AXIS2_CALL 
axutil_thread_mutex_trylock(axutil_thread_mutex_t *mutex);

/**
 * Release the lock for the given mutex.
 * @param mutex the mutex from which to release the lock.
 */
AXIS2_EXTERN axis2_status_t AXIS2_CALL 
axutil_thread_mutex_unlock(axutil_thread_mutex_t *mutex);

/**
 * Destroy the mutex and free the memory associated with the lock.
 * @param mutex the mutex to destroy.
 */
AXIS2_EXTERN axis2_status_t AXIS2_CALL 
axutil_thread_mutex_destroy(axutil_thread_mutex_t *mutex);

/** @} */

#ifdef __cplusplus
}
#endif

#endif  /* AXIS2_THREAD_MUTEX_H */
