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

#ifndef AXUTIL_THREAD_H
#define AXUTIL_THREAD_H


/**
  * @file axutil_thread.h
  * @brief axis2 thread api
  */

#include <axutil_allocator.h>
#include <axutil_utils_defines.h>
#include <axutil_error.h>



#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @defgroup axutil_thread thread
     * @ingroup axis2_util
     * @{
     */

    /**
     * Thread callbacks from axis2 functions must be declared with AXIS2_THREAD_FUNC
     * so that they follow the platform's calling convention.
     */
    /*#define AXIS2_THREAD_FUNC*/

    /** Thread structure. */
    typedef struct axutil_thread_t           axutil_thread_t;

    /** Thread attributes structure. */
    typedef struct axutil_threadattr_t       axutil_threadattr_t;

    /** Control variable for one-time atomic variables.  */
    typedef struct axutil_thread_once_t      axutil_thread_once_t;

    /**
     * The prototype for any AXIS2 thread worker functions.
     */
    typedef void *(AXIS2_THREAD_FUNC *axutil_thread_start_t)(axutil_thread_t*, void*);

    /** Thread private address space. */
    typedef struct axutil_threadkey_t        axutil_threadkey_t;

    /* Thread Function definitions */

    /**
     * Create and initialize a new threadattr variable
     * @param cont The pool to use
     * @return Newly created thread attribute
     */
    AXIS2_EXTERN axutil_threadattr_t* AXIS2_CALL
    axutil_threadattr_create(axutil_allocator_t *allocator);

    /**
     * Set if newly created threads should be created in detached state.
     * @param attr The threadattr to affect
     * @param on Non-zero if detached threads should be created.
     * @return The status of the operation
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_threadattr_detach_set(axutil_threadattr_t *attr, 
        axis2_bool_t detached);

    /**
     * Get the detach state for this threadattr.
     * @param attr The threadattr to reference
     * @return AXIS2_TRUE if threads are to be detached, or AXIS2_FALSE
     * if threads are to be joinable.
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axutil_threadattr_is_detach(axutil_threadattr_t *attr, 
        axutil_allocator_t *allocator);


    /**
     * Create a new thread of execution
     * @param attr The threadattr to use to determine how to create the thread
     * @param func The function to start the new thread in
     * @param data Any data to be passed to the starting function
     * @param cont The pool to use
     * @return The newly created thread handle.
     */
    AXIS2_EXTERN axutil_thread_t* AXIS2_CALL
    axutil_thread_create(axutil_allocator_t *allocator, 
        axutil_threadattr_t *attr,
        axutil_thread_start_t func, void *data);

    /**
     * Stop the current thread
     * @param thd The thread to stop
     * @return The status of the operation
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_thread_exit(axutil_thread_t *thd, 
        axutil_allocator_t *allocator);

    /**
     * Block until the desired thread stops executing.
     * @param thd The thread to join
     * @return The status of the operation
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_thread_join(axutil_thread_t *thd);

    /**
     * force the current thread to yield the processor
     */
    AXIS2_EXTERN void AXIS2_CALL
    axutil_thread_yield();

    /**
     * Initialize the control variable for axutil_thread_once.
     * @param control The control variable to initialize
     * @return The status of the operation
     */
    AXIS2_EXTERN axutil_thread_once_t* AXIS2_CALL
    axutil_thread_once_init(axutil_allocator_t *allocator);

    /**
     * Run the specified function one time, regardless of how many threads
     * call it.
     * @param control The control variable.  The same variable should
     *                be passed in each time the function is tried to be
     *                called.  This is how the underlying functions determine
     *                if the function has ever been called before.
     * @param func The function to call.
     * @return The status of the operation
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_thread_once(axutil_thread_once_t *control, 
        void(*func)(void));

    /**
     * detach a thread
     * @param thd The thread to detach
     * @return The status of the operation
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_thread_detach(axutil_thread_t *thd);

    /*************************Thread locking functions*****************************/

    /** Opaque thread-local mutex structure */
    typedef struct axutil_thread_mutex_t axutil_thread_mutex_t;

#define AXIS2_THREAD_MUTEX_DEFAULT  0x0   /**< platform-optimal lock behavior */
#define AXIS2_THREAD_MUTEX_NESTED   0x1   /**< enable nested (recursive) locks */
#define AXIS2_THREAD_MUTEX_UNNESTED 0x2   /**< disable nested locks */

    /**
     * Create and initialize a mutex that can be used to synchronize threads.
     * @param allocator Memory allocator to allocate memory for the mutex
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

#endif                          /* AXIS2_THREAD_H */
