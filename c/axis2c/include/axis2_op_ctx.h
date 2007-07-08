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

#ifndef AXIS2_OP_CTX_H
#define AXIS2_OP_CTX_H

/**
 * @defgroup axis2_op_ctx operation context 
 * @ingroup axis2_context
 * operation context represents a running "instance" of an operation.
 * operation context allows messages to be grouped into operations as in 
 * WSDL 2.0 specification. operations are essentially arbitrary message exchange 
 * patterns (MEP). So as messages are being exchanged, operation context remembers 
 * the state of message exchange pattern specifics.
 * The implementation of operation context supports MEPs which have one input 
 * message and/or one output message. In order to support other MEPs one must 
 * extend this struct.
 * @{
 */

/**
 * @file axis2_op_ctx.h
 */

#include <axis2_defines.h>
#include <axutil_hash.h>
#include <axutil_env.h>
#include <axis2_msg_ctx.h>
#include <axis2_op.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /** Type name for struct axis2_op_ctx */
    typedef struct axis2_op_ctx axis2_op_ctx_t;
        
    struct axis2_svc_ctx;

    /**
     * Creates an operation context struct instance.
     * @param env pointer to environment struct
     * @param op pointer to operation that is related to operation context. 
     * operation context does not assume the ownership of the struct
     * @param svc_ctx pointer to parent service context
     * @return pointer to newly created operation context
     */
    AXIS2_EXTERN axis2_op_ctx_t *AXIS2_CALL
    axis2_op_ctx_create(const axutil_env_t *env,
       struct axis2_op *op,
       struct axis2_svc_ctx *svc_ctx);

   /**
    * Gets base which is of context type.
    * @param op_ctx pointer to operation context
    * @param env pointer to environment struct
    * @return pointer to base context
    */
    AXIS2_EXTERN axis2_ctx_t *AXIS2_CALL
    axis2_op_ctx_get_base(const axis2_op_ctx_t *op_ctx,
        const axutil_env_t *env);

   /**
    * Frees operation context.
    * @param op_ctx pointer to operation context
    * @param env pointer to environment struct
    * @return void
    */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_op_ctx_free(struct axis2_op_ctx *op_ctx,
        const axutil_env_t *env);

    /**
     * Initializes operation context. This method traverses through all the 
     * message contexts stored within it and initialize them all.
     * @param op_ctx pointer to operation context
     * @param env pointer to environment struct
     * @param conf pointer to conf configuration
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_op_ctx_init(struct axis2_op_ctx *op_ctx,
        const axutil_env_t *env,
        struct axis2_conf *conf);

    /**
     * Gets operation the operation context is related to.
     * @param op_ctx pointer to operation context
     * @param env pointer to environment struct
     * @return pointer to operation
     */
    AXIS2_EXTERN struct axis2_op *AXIS2_CALL
    axis2_op_ctx_get_op(const axis2_op_ctx_t *op_ctx,
        const axutil_env_t *env);

    /**
     * Gets parent which is of service context type. 
     * @param op_ctx pointer to operation context
     * @param env pointer to environment struct
     * @return pointer to service context within which this operation 
     * context lives
     */
    AXIS2_EXTERN struct axis2_svc_ctx *AXIS2_CALL
    axis2_op_ctx_get_parent(const axis2_op_ctx_t *op_ctx,
        const axutil_env_t *env);

    /**
     * Adds a message context. 
     * @param op_ctx pointer to operation context
     * @param env pointer to environment struct
     * @param msg_ctx pointer to message context struct, message context 
     * does not assume the ownership of the struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_op_ctx_add_msg_ctx(struct axis2_op_ctx *op_ctx,
        const axutil_env_t *env,
        axis2_msg_ctx_t *msg_ctx);

    /**
     * Gets message context with the given message ID.
     * @param op_ctx pointer to operation context
     * @param env pointer to environment struct
     * @param message_id message ID string
     * @return pointer to message context with given ID
     */
    AXIS2_EXTERN axis2_msg_ctx_t *AXIS2_CALL
    axis2_op_ctx_get_msg_ctx(const axis2_op_ctx_t *op_ctx,
        const axutil_env_t *env,
        const axis2_wsdl_msg_labels_t message_id);

    /**
     * Gets the bool value indicating if the MEP is complete.
     * MEP is considered complete when all the messages that
     * are associated with the MEP has arrived.
     * @param op_ctx pointer to operation context
     * @param env pointer to environment struct
     * @return AXIS2_TRUE if MEP invocation is complete, else AXIS2_FALSE
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_op_ctx_get_is_complete(const axis2_op_ctx_t *op_ctx,
        const axutil_env_t *env);

    /**
     * Sets the bool value indicating if the MEP is complete.
     * MEP is considered complete when all the messages that
     * are associated with the MEP has arrived.
     * @param op_ctx pointer to operating context
     * @param env pointer to environment struct
     * @param is_complete AXIS2_TRUE if MEP invocation is complete, else 
     * AXIS2_FALSE
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_op_ctx_set_complete(struct axis2_op_ctx *op_ctx,
        const axutil_env_t *env,
        axis2_bool_t is_complete);

    /**
     * Cleans up the operation context. Clean up includes removing all 
     * message context references recorded in operation context.
     * @param op_ctx pointer to operation context
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_op_ctx_cleanup(struct axis2_op_ctx *op_ctx,
        const axutil_env_t *env);

    /**
     * Sets parent service context.
     * @param op_ctx pointer to operation context
     * @param env pointer to environment struct
     * @param svc_ctx pointer to service context, message context does not
     * assume the ownership of the struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_op_ctx_set_parent(struct axis2_op_ctx *op_ctx,
        const axutil_env_t *env,
        struct axis2_svc_ctx *svc_ctx);

    /**
     * Gets the message context map.
     * @param op_ctx pointer to operation context
     * @param env pointer to environment struct
     * @return pointer to hash table containing message contexts
     */
    AXIS2_EXTERN axis2_msg_ctx_t **AXIS2_CALL
    axis2_op_ctx_get_msg_ctx_map(const axis2_op_ctx_t *op_ctx,
        const axutil_env_t *env);

    /**
     * Sets the bool value indicating the status of response.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param response_written AXIS2_TRUE if response is written, else 
     * AXIS2_FALSE
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_op_ctx_set_response_written(axis2_op_ctx_t *op_ctx,
        const axutil_env_t *env,
        const axis2_bool_t response_written);


    /**
     * Checks the response status, whether it is written or not.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return AXIS2_TRUE if response is already written, else AXIS2_FALSE         
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_op_ctx_get_response_written(const axis2_op_ctx_t *op_ctx,
        const axutil_env_t *env);

    AXIS2_EXTERN void AXIS2_CALL
    axis2_op_ctx_destroy_mutex(
        struct axis2_op_ctx *op_ctx,
        const axutil_env_t *env);

    /**
     * Checks whether op_ctx is in use. This is necessary when destroying the
     * thread mutex at the http_worker to check whether the operation context
     * is still in use
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return AXIS2_TRUE if still in use, else AXIS2_FALSE         
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_op_ctx_is_in_use(
        const axis2_op_ctx_t *op_ctx,
        const axutil_env_t *env);

    /**
     * Set operation context's is_in_use attribute. This is necessary when 
     * destroying the thread mutex at the http_worker to check whether the 
     * operation context is still in use
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return AXIS2_TRUE if still in use, else AXIS2_FALSE         
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_op_ctx_set_in_use(
        struct axis2_op_ctx *op_ctx,
        const axutil_env_t *env,
        axis2_bool_t is_in_use);


#ifdef __cplusplus
}
#endif

#endif                          /* AXIS2_OP_CTX_H */
