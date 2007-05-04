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

#ifndef AXIS2_FLOW_H
#define AXIS2_FLOW_H

/** 
 * @defgroup axis2_flow flow
 * @ingroup axis2_desc
 * flow is a collection of handlers. This struct encapsulates the concept
 * of an execution flow in the engine.
 * @{
 */

#include <axis2_const.h>
#include <axutil_error.h>
#include <axis2_defines.h>
#include <axutil_env.h>
#include <axutil_allocator.h>
#include <axutil_string.h>
#include <axutil_array_list.h>
#include <axis2_handler_desc.h>


#ifdef __cplusplus
extern "C"
{
#endif

    /** Type name for struct axis2_flow */
    typedef struct axis2_flow axis2_flow_t;

	/**
     * Creates flow struct.
     * @param env pointer to environment struct
     * @return pointer to newly created flow
     */
    AXIS2_EXTERN axis2_flow_t *AXIS2_CALL
    axis2_flow_create (const axutil_env_t *env);

    /** 
     * Frees flow struct.
     * @param flow pointer to flow
     * @param env pointer to environment struct
     * @return void
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_flow_free(axis2_flow_t *flow,
        const axutil_env_t *env);

    /**
     * Adds a handler description to flow.
     * @param flow pointer to flow
     * @param env pointer to environment struct
     * @param handler pointer to handler description
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_flow_add_handler(axis2_flow_t *flow,
        const axutil_env_t *env,
        axis2_handler_desc_t *handler);

    /**
     * Gets handler description at given index.
     * @param flow pointer to flow
     * @param env pointer to environment struct
     * @param index index of the handler
     * @return pointer to handler description
     */
    AXIS2_EXTERN axis2_handler_desc_t *AXIS2_CALL
    axis2_flow_get_handler(const axis2_flow_t *flow,
        const axutil_env_t *env,
        const int index);

    /**
     * Gets handler count.
     * @param flow pointer to flow
     * @param env pointer to environment struct
     * @return handler count
     */
    AXIS2_EXTERN int AXIS2_CALL
    axis2_flow_get_handler_count(const axis2_flow_t *flow,
        const axutil_env_t *env);

    /**
     * Frees flow passed as void pointer. This method would cast the void 
     * pointer to appropriate type and then call free method.
     * @param flow pointer to flow
     * @param env pointer to environment struct
     * @return void
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_flow_free_void_arg (void *flow,
        const axutil_env_t *env);

/** @} */

#ifdef __cplusplus
}
#endif
#endif  /* AXIS2_FLOW_H */
