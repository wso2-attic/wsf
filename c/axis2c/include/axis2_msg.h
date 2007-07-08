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

#ifndef AXIS2_MSG_H
#define AXIS2_MSG_H

/** 
 * @defgroup axis2_msg message
 * @ingroup axis2_desc
 * message represents a message in a WSDL. It captures SOAP headers related to 
 * a given message, the direction as well as the phases to be invoked along
 * the flow. Based on the message direction, there could be only one flow 
 * associated with a message.
 * @{
 */

#include <axutil_param_container.h>
#include <axis2_op.h>
#include <axutil_array_list.h>
#include <axis2_description.h>
#include <axis2_phase_meta.h>

#define AXIS2_MSG_IN            "in"
#define AXIS2_MSG_OUT           "out"
#define AXIS2_MSG_IN_FAULT      "InFaultMessage"
#define AXIS2_MSG_OUT_FAULT     "OutFaultMessage"


#ifdef __cplusplus
extern "C"
{
#endif

    /** Type name for struct axis2_msg */ 
    typedef struct axis2_msg axis2_msg_t;

    /**
     * Creates message struct instance.
     * @param env pointer to environment struct
     * @return pointer to newly created message
     */
    AXIS2_EXTERN axis2_msg_t *AXIS2_CALL
    axis2_msg_create(const axutil_env_t *env);

    /** 
     * Frees message.
     * @param msg pointer to message
     * @param env pointer to environment struct
     * @return void
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_msg_free(axis2_msg_t *msg,
        const axutil_env_t *env);

    /** 
     * Adds a parameter.
     * @param msg pointer to message
     * @param env pointer to environment struct
     * @param param pointer to parameter, message assumes ownership of 
     * parameter
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_add_param(axis2_msg_t *msg,
        const axutil_env_t *env,
        axutil_param_t *param);

    /**
     * Gets the named parameter.
     * @param msg pointer to message
     * @param env pointer to environment struct
     * @param name parameter name string
     * @return pointer to parameter corresponding to the same name, returns
     * a reference, not a cloned copy
     */
    AXIS2_EXTERN axutil_param_t *AXIS2_CALL
    axis2_msg_get_param(const axis2_msg_t *msg,
        const axutil_env_t *env,
        const axis2_char_t *name);

    /** 
     * Gets all parameters stored in message.
     * @param msg pointer to message
     * @param env pointer to environment struct
     * @return pointer to list of parameters, returns a reference, not a 
     * cloned copy
     */
    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    axis2_msg_get_all_params(const axis2_msg_t *msg,
        const axutil_env_t *env);

    /** 
     * Checks if the named parameter is locked.
     * @param msg pointer to message
     * @param env pointer to environment struct
     * @param param_name parameter name string
     * @return AXIS2_TRUE if the parameter is locked, else AXIS2_FALSE         
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_msg_is_param_locked(axis2_msg_t *msg,
        const axutil_env_t *env,
        const axis2_char_t *param_name);

    /** 
     * Sets parent. Parent of a message is of type operation.
     * @param msg pointer to message
     * @param env pointer to environment struct
     * @param op pointer to parent operation, message does not assume 
     * ownership of parent
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_set_parent(axis2_msg_t *msg,
        const axutil_env_t *env,
        axis2_op_t *op);

    /** 
     * Gets parent. Parent of a message is of type operation.
     * @param msg pointer to message
     * @param env pointer to environment struct
     * @return pointer to parent operation, returns a reference, not a 
     * cloned copy
     */
    AXIS2_EXTERN axis2_op_t *AXIS2_CALL
    axis2_msg_get_parent(const axis2_msg_t *msg,
        const axutil_env_t *env);

    /**
     * Gets flow of execution associated with the message.
     * @param msg pointer to message
     * @param env pointer to environment struct
     * @return pointer to array list containing the list of phases 
     * representing the flow
     */
    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    axis2_msg_get_flow( const axis2_msg_t *msg,
        const axutil_env_t *env);

    /** 
     * Sets flow of execution associated with the message.
     * @param msg pointer to message
     * @param env pointer to environment struct
     * @param flow pointer to array list of phases representing the flow,
     * message assumes ownership of flow
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_set_flow(axis2_msg_t *msg,
        const axutil_env_t *env,
        axutil_array_list_t *flow);

    /** 
     * Gets direction of message.
     * @param msg pointer to message
     * @param env pointer to environment struct
     * @return direction string
     */
    AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
    axis2_msg_get_direction(const axis2_msg_t *msg,
        const axutil_env_t *env);

    /** 
     * Sets direction of message.
     * @param msg pointer to message
     * @param env pointer to environment struct
     * @param direction pointer to direction
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_set_direction(axis2_msg_t *msg,
        const axutil_env_t *env,
        const axis2_char_t *direction);

    /** 
     * Gets QName representing message.
     * @param msg pointer to message
     * @param env pointer to environment struct
     * @return pointer to QName, returns a reference, not a cloned copy
     */
    AXIS2_EXTERN const axutil_qname_t *AXIS2_CALL
    axis2_msg_get_element_qname(const axis2_msg_t *msg,
        const axutil_env_t *env);

    /** 
     * Sets QName representing message.
     * @param msg pointer to message
     * @param env pointer to environment struct
     * @param element_qname pointer to QName representing message, this 
     * function creates a clone of QName
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_set_element_qname(axis2_msg_t *msg,
        const axutil_env_t *env,
        const axutil_qname_t *element_qname);

    /** 
     * Gets message name.
     * @param msg pointer to message
     * @param env pointer to environment struct
     * @return message name string.
     */
    AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
    axis2_msg_get_name(const axis2_msg_t *msg,
        const axutil_env_t *env);

    /** 
     * Sets message name.
     * @param msg pointer to message
     * @param env pointer to environment struct
     * @param message name string
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_set_name(axis2_msg_t *msg,
        const axutil_env_t *env,
        const axis2_char_t *name);

    /** 
     * Gets base description.
     * @param msg pointer to message
     * @param env pointer to environment struct
     * @return pointer to base description struct
     */
    AXIS2_EXTERN axis2_desc_t *AXIS2_CALL
    axis2_msg_get_base(const axis2_msg_t *msg,
        const axutil_env_t *env);

    AXIS2_EXTERN axutil_param_container_t *AXIS2_CALL
    axis2_msg_get_param_container(const axis2_msg_t *msg,
        const axutil_env_t *env);

/** @} */
#ifdef __cplusplus
}
#endif
#endif  /* AXIS2_MSG_H */
