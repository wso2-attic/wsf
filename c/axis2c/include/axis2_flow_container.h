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

#ifndef AXIS2_FLOW_CONTAINER_H
#define AXIS2_FLOW_CONTAINER_H

/** 
 * @defgroup axis2_flow_container flow container
 * @ingroup axis2_desc
 * Flow container is the encapsulating struct for all the four flows. The four flows 
 * possible are in flow, out flow, in fault flow and out fault flow.
 * @{
 */

/**
 * @file axis2_flow_container.h
 */

#include <axis2_const.h>
#include <axutil_error.h>
#include <axis2_defines.h>
#include <axutil_env.h>
#include <axutil_allocator.h>
#include <axutil_string.h>
#include <axutil_array_list.h>
#include <axis2_flow.h>


#ifdef __cplusplus
extern "C"
{
#endif

    /** Type name for struct axis2_flow_container */
    typedef struct axis2_flow_container axis2_flow_container_t;


    /** 
     * Frees flow container.
     * @param flow_container pointer to flow container
     * @param env pointer to environment struct
     * @return void
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_flow_container_free(axis2_flow_container_t *flow_container,
        const axutil_env_t *env);

    /**
     * Gets in flow.
     * @param flow_container pointer to flow container
     * @param env pointer to environment struct
     * @return pointer to in flow, returns a reference, not a cloned copy
     */
    AXIS2_EXTERN axis2_flow_t *AXIS2_CALL
    axis2_flow_container_get_in_flow(const axis2_flow_container_t *flow_container,
        const axutil_env_t *env);

    /**
     * Sets in flow.
     * @param flow_container pointer to flow container
     * @param env pointer to environment struct
     * @param in_flow pointer to in flow struct, flow container assumes 
     * ownership of struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_flow_container_set_in_flow(axis2_flow_container_t *flow_container,
        const axutil_env_t *env,
        axis2_flow_t *in_flow);

    /**
     * Gets out flow.
     * @param flow_container pointer to flow container
     * @param env pointer to environment struct
     * @return out flow, returns a reference, not a cloned copy
     */
    AXIS2_EXTERN axis2_flow_t *AXIS2_CALL
    axis2_flow_container_get_out_flow(const axis2_flow_container_t *flow_container,
        const axutil_env_t *env);

    /**
     * Sets out flow.
     * @param flow_container pointer to flow container
     * @param env pointer to environment struct
     * @param out_flow pointer to out flow, flow container assumes 
     * ownership of struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_flow_container_set_out_flow(axis2_flow_container_t *flow_container,
        const axutil_env_t *env,
        axis2_flow_t *out_flow);

    /**
     * Gets fault in flow.
     * @param flow_container pointer to flow container
     * @param env pointer to environment struct
     * @return fault in flow, returns a reference, not a cloned copy
     */
    AXIS2_EXTERN axis2_flow_t *AXIS2_CALL
    axis2_flow_container_get_fault_in_flow(const axis2_flow_container_t *flow_container,
        const axutil_env_t *env);

    /**
     * Sets fault in flow.
     * @param flow_container pointer to flow container
     * @param env pointer to environment struct
     * @param falut_in_flow pointer to falut in flow, flow container assumes 
     * ownership of struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_flow_container_set_fault_in_flow(axis2_flow_container_t *flow_container,
        const axutil_env_t *env,
        axis2_flow_t *falut_in_flow);

    /**
     * Gets fault out flow.
     * @param flow_container pointer to flow container
     * @param env pointer to environment struct
     * @return fault out flow, returns a reference, not a cloned copy
     */
    AXIS2_EXTERN axis2_flow_t *AXIS2_CALL
    axis2_flow_container_get_fault_out_flow(const axis2_flow_container_t *flow_container,
        const axutil_env_t *env);

    /**
     * Sets fault out flow.
     * @param flow_container pointer to flow container
     * @param env pointer to environment struct
     * @param fault_out_flow pointer to fault out flow, flow container assumes 
     * ownership of struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_flow_container_set_fault_out_flow(axis2_flow_container_t *flow_container,
        const axutil_env_t *env,
        axis2_flow_t *fault_out_flow);

    /**
     * Creates flow container struct.
     * @param env pointer to environment struct
     * @return pointer to newly created flow container
     */
    AXIS2_EXTERN axis2_flow_container_t *AXIS2_CALL
    axis2_flow_container_create (const axutil_env_t *env);


/** @} */

#ifdef __cplusplus
}
#endif
#endif  /* AXIS2_FLOW_CONTAINER_H */
