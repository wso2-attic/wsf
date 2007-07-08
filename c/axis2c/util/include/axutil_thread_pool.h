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

#ifndef AXUTIL_THREAD_POOL_H
#define AXUTIL_THREAD_POOL_H

/**
 * @file axutil_thread_pool.h
 * @brief Axis2 thread pool interface
 */

#include <axutil_utils_defines.h>
#include <axutil_allocator.h>
#include <axutil_thread.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @defgroup axutil_thread_pool thread pool
     * @ingroup axis2_util
     * @{
     */

    typedef struct axutil_thread_pool axutil_thread_pool_t;
    struct axutil_env;

    /**
     * Retrives a thread from the thread pool
     * @param func function to be executed in the new thread
     * @param data arguments to be passed to the function
     * @return pointer to a thread in ready state.
     */
    AXIS2_EXTERN axutil_thread_t *AXIS2_CALL
    axutil_thread_pool_get_thread(axutil_thread_pool_t *pool,
            axutil_thread_start_t func,
            void *data);
    /**
     * Blocks until the desired thread stops executing.
     * @param thd The thread to joined
     * @return status of the operation
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_thread_pool_join_thread(axutil_thread_pool_t *pool,
            axutil_thread_t *thd);

    /**
     * Stop the execution of current thread
     * @param thd thread to be stopped
     * @return status of the operation
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_thread_pool_exit_thread(axutil_thread_pool_t *pool,
            axutil_thread_t *thd);
    
    /**
     * Detaches a thread
     * @param thd thread to be detached
     * @return status of the operation
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_thread_pool_thread_detach(axutil_thread_pool_t *pool,
            axutil_thread_t *thd);

    /**
     * Frees resources used by thread_pool
     * @param pool thread_pool to be freed
     */
    AXIS2_EXTERN void AXIS2_CALL
    axutil_thread_pool_free(axutil_thread_pool_t *pool);

    /**
    * Initializes (creates) an thread_pool.
    * @param allocator user defined allocator for the memory allocation.
    * @return initialized thread_pool. NULL on error.
    */
    AXIS2_EXTERN axutil_thread_pool_t * AXIS2_CALL 
    axutil_thread_pool_init(axutil_allocator_t *allocator);

    /**
     * This function can be used to initialize the environment in case of
     * spawning a new thread via a thread function
     */
    AXIS2_EXTERN struct axutil_env * AXIS2_CALL
    axutil_init_thread_env(const struct axutil_env *system_env);

    /**
     * This function can be used to free the environment that was used
     * in a thread function
     */
    AXIS2_EXTERN void AXIS2_CALL
    axutil_free_thread_env(struct axutil_env *thread_env);

    /** @} */

#ifdef __cplusplus
}
#endif

#endif    /* AXIS2_THREAD_POOL_H */
