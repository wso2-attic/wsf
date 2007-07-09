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

#ifndef AXIS2_TRANSPORT_OUT_DESC_H
#define AXIS2_TRANSPORT_OUT_DESC_H

/** 
 * @defgroup axis2_transport_out_desc transport out description
 * @ingroup axis2_desc
 * transport out description represents a transport sender configured in 
 * Axis2 configuration. There can be multiple transport senders configured 
 * in axis2.xml file and each of them will be represented with a transport 
 * out description instance. deployment engine takes care of creating and 
 * instantiating transport out descriptions.
 * transport out description encapsulates flows related to the transport out
 * and also holds a reference to related transport sender.
 * @{
 */

/**
 * @file axis2_transport_out_desc.h
 */

#include <axis2_const.h>
#include <axutil_error.h>
#include <axis2_defines.h>
#include <axutil_env.h>
#include <axutil_allocator.h>
#include <axutil_array_list.h>
#include <axis2_phase_meta.h>
#include <axis2_phase.h>
#include <axis2_flow.h>
#include <axis2_transport_sender.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /** Type name for struct axis2_transport_out_desc */
    typedef struct axis2_transport_out_desc axis2_transport_out_desc_t;

    struct axis2_phase;
    struct axis2_transport_sender;

    /**
     * Frees transport out description.
     * @param transport_out_dec pointer to transport out description
     * @param env pointer to environment struct
     * @return void
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_transport_out_desc_free(axis2_transport_out_desc_t *transport_out_desc,
        const axutil_env_t *env);

    /**
     * Frees transport out description given as a void pointer.
     * @param transport_out_dec pointer to transport out description as a 
     * void pointer 
     * @param env pointer to environment struct
     * @return void
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_transport_out_desc_free_void_arg(void *transport_out,
        const axutil_env_t *env);

    /**
     * Gets transport enum.
     * @param transport_out pointer to transport_out
     * @param env pointer to environment struct
     * @return transport enum 
     */
    AXIS2_EXTERN AXIS2_TRANSPORT_ENUMS AXIS2_CALL
    axis2_transport_out_desc_get_enum(const axis2_transport_out_desc_t *transport_out,
        const axutil_env_t *env);

    /**
     * Sets transport enum.
     * @param transport_out pointer to transport_out
     * @param env pointer to environment struct
     * @param trans_enum transport enum
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_transport_out_desc_set_enum(struct axis2_transport_out_desc *transport_out,
        const axutil_env_t *env,
        const AXIS2_TRANSPORT_ENUMS trans_enum);

    /**
     * Gets out flow. Out flow represents the list of phases invoked 
     * along the sender path.
     * @param transport_out pointer to transport_out
     * @param env pointer to environment struct
     * @return pointer to flow representing out flow, returns a reference,
     * not a cloned copy
     */
    AXIS2_EXTERN struct axis2_flow *AXIS2_CALL
    axis2_transport_out_desc_get_out_flow(const axis2_transport_out_desc_t *transport_out,
        const axutil_env_t *env);

    /**
     * Sets out flow. Out flow represents the list of phases invoked 
     * along the sender path.
     * @param transport_out pointer to transport_out
     * @param env pointer to environment struct
     * @param out_flow pointer to out flow, transport out description 
     * assumes ownership of flow
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_transport_out_desc_set_out_flow(struct axis2_transport_out_desc *transport_out,
        const axutil_env_t *env,
        struct axis2_flow *out_flow);

    /**
     * Gets fault out flow. Fault out flow represents the list of phases 
     * invoked along the sender path if a fault happens.         
     * @param transport_out pointer to transport_out
     * @param env pointer to environment struct
     * @return pointer to flow representing fault out flow
     */
    AXIS2_EXTERN struct axis2_flow *AXIS2_CALL
    axis2_transport_out_desc_get_fault_out_flow(const axis2_transport_out_desc_t *transport_out,
        const axutil_env_t *env);

    /**
     * Sets fault out flow. Fault out flow represents the list of phases 
     * invoked along the sender path if a fault happens.         
     * @param transport_out pointer to transport_out
     * @param env pointer to environment struct
     * @param fault_out_flow pointer to fault_out_flow
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_transport_out_desc_set_fault_out_flow(struct axis2_transport_out_desc *transport_out,
        const axutil_env_t *env,
        struct axis2_flow *fault_out_flow);

    /**
     * Gets transport sender.
     * @param transport_out pointer to transport_out
     * @param env pointer to environment struct
     * @return pointer to transport sender associated wit the transport out
     * description, returns a reference, not a cloned copy
     */
    AXIS2_EXTERN axis2_transport_sender_t *AXIS2_CALL
    axis2_transport_out_desc_get_sender(const axis2_transport_out_desc_t *transport_out,
        const axutil_env_t *env);

    /**
     * Sets transport sender.
     * @param transport_out pointer to transport_out
     * @param env pointer to environment struct
     * @param sender pointer to transport sender, transport description
     * assumes ownership of sender 
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_transport_out_desc_set_sender(struct axis2_transport_out_desc *transport_out,
        const axutil_env_t *env,
        axis2_transport_sender_t *sender);

    /**
     * Gets transport out phase.
     * @param transport_out pointer to transport_out
     * @param env pointer to environment struct
     * @return pointer to phase representing transport out phase, returns a 
     * reference, not a cloned copy
     */
    AXIS2_EXTERN struct axis2_phase * AXIS2_CALL
    axis2_transport_out_desc_get_out_phase(const axis2_transport_out_desc_t *transport_out,
        const axutil_env_t *env);

    /**
     * Sets transport out phase.
     * @param transport_out pointer to transport_out 
     * @param env pointer to environment struct
     * @param out_phase pointer to phase representing transport out phase,
     * transport out description assumes ownership of phase
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_transport_out_desc_set_out_phase(struct axis2_transport_out_desc *transport_out,
        const axutil_env_t *env,
        struct axis2_phase *out_phase);

    /**
     * Gets fault phase.
     * @param transport_out  pointer to transport_out
     * @param env pointer to environment struct
     * @return pointer to phase representing fault phase, returns a 
     * reference, not a cloned copy
     */
    AXIS2_EXTERN struct axis2_phase *AXIS2_CALL
    axis2_transport_out_desc_get_fault_phase(const axis2_transport_out_desc_t *transport_out,
        const axutil_env_t *env);

    /**
     * Sets fault phase.
     * @param transport_out pointer to transport_out
     * @param env pointer to environment struct
     * @param fault_phase pointer to phase representing fault phase, 
     * transport description assumes ownership of phase
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_transport_out_desc_set_fault_phase(struct axis2_transport_out_desc *transport_out,
        const axutil_env_t *env,
        struct axis2_phase *fault_phase);

    /**
     * Adds parameter.
     * @param transport_out_desc pointer to tarn sport out description
     * @param env pointer to environment struct
     * @param param pointer to parameter, transport out description assumes
     * ownership of parameter
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_transport_out_desc_add_param(axis2_transport_out_desc_t *transport_out_desc,
        const axutil_env_t *env,
        axutil_param_t *param);

    /**
     * Gets named parameter. 
     * @param transport_out_desc pointer to transport out description
     * @param env pointer to environment struct
     * @param param_name parameter name string
     */
    AXIS2_EXTERN axutil_param_t *AXIS2_CALL
    axis2_transport_out_desc_get_param(const axis2_transport_out_desc_t *transport_out_desc,
        const axutil_env_t *env,
        const axis2_char_t *param_name);

    /**
     * Checks if the named parameter is locked.
     * @param transport_out_desc pointer to transport out description
     * @param env pointer to environment struct
     * @param param_name pointer to parameter name
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_transport_out_desc_is_param_locked(axis2_transport_out_desc_t *transport_out_desc,
        const axutil_env_t *env,
        const axis2_char_t *param_name);

    AXIS2_EXTERN axutil_param_container_t *AXIS2_CALL
    axis2_transport_out_desc_param_container(const axis2_transport_out_desc_t *transport_out_desc,
        const axutil_env_t *env);

    /**
     * Creates transport out description with given transport enum.
     * @param env pointer to environment struct
     * @param trans_enum pointer to transport enum
     * @return pointer to newly created transport out
     */
    AXIS2_EXTERN axis2_transport_out_desc_t * AXIS2_CALL
    axis2_transport_out_desc_create(const axutil_env_t *env,
        const AXIS2_TRANSPORT_ENUMS trans_enum);

    /**
     * Frees transport out description given as a void pointer.
     * @param transport_out_dec pointer to transport out description as a 
     * void pointer 
     * @param env pointer to environment struct
     * @return void
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_transport_out_desc_free_void_arg(void *transport_out,
        const axutil_env_t *env);


/** @} */

#ifdef __cplusplus
}
#endif
#endif  /* AXIS2_TRANSPORT_OUT_DESC_H */
