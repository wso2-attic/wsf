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

#ifndef AXUTIL_STACK_H
#define AXUTIL_STACK_H


/**
* @file axutil_stack.h
* @brief represents a stack
*/

#include <axutil_utils_defines.h>
#include <axutil_env.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @defgroup axis2_util_stack stack
     * @ingroup axis2_util
     * @{
     */

    typedef struct axutil_stack axutil_stack_t;

    AXIS2_EXTERN axutil_stack_t * AXIS2_CALL
    axutil_stack_create(const axutil_env_t *env);

    /**
     * Free function of the stack
     * @param stack pointer to stack
     * @param env environemnt
     */
    AXIS2_EXTERN void AXIS2_CALL
    axutil_stack_free(axutil_stack_t *stack,
        const axutil_env_t *env);

    AXIS2_EXTERN void* AXIS2_CALL
    axutil_stack_pop(axutil_stack_t *stack,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_stack_push(axutil_stack_t *stack,
        const axutil_env_t *env,
        void* value);

    AXIS2_EXTERN int AXIS2_CALL
    axutil_stack_size(axutil_stack_t *stack,
        const axutil_env_t *env);
    /**
     * returns the last put value from the stack
     * without removing it from stack
     */
    AXIS2_EXTERN void* AXIS2_CALL
    axutil_stack_get(axutil_stack_t *stack,
        const axutil_env_t *env);

    AXIS2_EXTERN void* AXIS2_CALL
    axutil_stack_get_at(axutil_stack_t *stack,
        const axutil_env_t *env,
        int i);

    /** @} */

#ifdef __cplusplus
}
#endif
#endif /* AXIS2_STACK_H */

