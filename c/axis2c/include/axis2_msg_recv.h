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

#ifndef AXIS2_MSG_RECV_H
#define AXIS2_MSG_RECV_H

/**
 * @defgroup axis2_receivers receivers
 * @ingroup axis2
 * @{
 * @} 
 */

/** @defgroup axis2_msg_recv message receiver
 * @ingroup axis2_receivers
 * Description.
 * @{
 */

/**
 * @file axis2_msg_recv.h
 * @brief Axis Message Receiver interface. Message Receiver struct. 
 * This interface is extended by custom message receivers
 */

#ifdef __cplusplus
extern "C"
{
#endif

#include <axis2_defines.h>
#include <axis2_const.h>
#include <axis2_svc_skeleton.h>
#include <axis2_msg_ctx.h>
#include <axis2_op_ctx.h>
#include <axis2_svr_callback.h>

/** Sets AXIS2_SUCCESS to 1 */
#define AXIS2_SUCCESS 1
/** Sets AXIS2_FAILURE to 0 */
#define AXIS2_FAILURE 0

    struct axis2_msg_ctx;
    /** Type name for struct axis2_msg_recv*/
    typedef struct axis2_msg_recv axis2_msg_recv_t;

    /**
     * Deallocate memory
     * @param msg_recv pinter to message receiver
     * @param env pointer to environment struct
     * @return void
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_msg_recv_free(axis2_msg_recv_t *msg_recv,
        const axutil_env_t *env);

    /**
     * This method is called from axis2_engine_receive method. This method's
     * actual implementation is decided from the create method of the 
     * extended message receiver object. There depending on the synchronous or
     * asynchronous type, receive metho is assigned with the synchronous or
     * asynchronous implementation of receive.
     * @see raw_xml_in_out_msg_recv_create method where receive is assigned
     * to receive_sync
     * @param msg_recv pointer to message receiver
     * @param env pointer to environment struct
     * @param in_msg_ctx pointer to in message context
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_recv_receive(axis2_msg_recv_t *msg_recv,
        const axutil_env_t *env,
        struct axis2_msg_ctx *in_msg_ctx,
        void *callback_recv_param);

    /**
     * This contain in out synchronous business invoke logic
     * @param msg_recv pointer to message receiver
     * @param env pointer to environment struct
     * @param in_msg_ctx pointer to in message context
     * @param out_msg_ctx pointer to out message context
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_recv_invoke_business_logic(axis2_msg_recv_t *msg_recv,
        const axutil_env_t *env,
        struct axis2_msg_ctx *in_msg_ctx,
        struct axis2_msg_ctx *out_msg_ctx);

    /**
     * this will create a new service skeleton object
     * @param msg_recv pointer to message receiver
     * @param env pointer to enviornment struct
     * @param msg_ctx pointer to message context
     * @return service skeleton object
     */
    AXIS2_EXTERN axis2_svc_skeleton_t *AXIS2_CALL
    axis2_msg_recv_make_new_svc_obj(axis2_msg_recv_t *msg_recv,
        const axutil_env_t *env,
        struct axis2_msg_ctx *msg_ctx);

    /**
     * This will return the service skeleton object
     * @param msg_recv pointer to message receiver
     * @param env pointer to environment struct
     * @param msg_ctx pointer to message context
     * @return service skeleton object
     */
    AXIS2_EXTERN axis2_svc_skeleton_t *AXIS2_CALL
    axis2_msg_recv_get_impl_obj(axis2_msg_recv_t *msg_recv,
        const axutil_env_t *env,
        struct axis2_msg_ctx *msg_ctx);

    /**
     * Set the application scope
     * @param msg_recv pointer to message receiver
     * @param env pointer to environment struct
     * @param scope ointer to scope
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_recv_set_scope(axis2_msg_recv_t *msg_recv,
        const axutil_env_t *env,
        const axis2_char_t *scope);


    /**
     * Get the application scope
     * @param msg_recv pointer to message receiver
     * @env pointer to enviornment struct
     * @return scope
     */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    axis2_msg_recv_get_scope(axis2_msg_recv_t *msg_recv,
        const axutil_env_t *env);

    /**
     * Delete the service skeleton object created by make_new_svc_obj
     * @param msg_recv pointer to message receiver
     * @env pointer to environment struct
     * @param msg_ctx pointer to message context
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_recv_delete_svc_obj(axis2_msg_recv_t *msg_recv,
        const axutil_env_t *env,
        axis2_msg_ctx_t *msg_ctx);

    AXIS2_EXPORT axis2_status_t AXIS2_CALL
    axis2_msg_recv_set_invoke_business_logic(axis2_msg_recv_t *msg_recv,
        const axutil_env_t *env,
        void *func);

    AXIS2_EXPORT axis2_status_t AXIS2_CALL
    axis2_msg_recv_set_derived(axis2_msg_recv_t *msg_recv,
        const axutil_env_t *env,
        void *derived);

    AXIS2_EXPORT void *AXIS2_CALL
    axis2_msg_recv_get_derived(const axis2_msg_recv_t *msg_recv,
        const axutil_env_t *env);

	AXIS2_EXPORT axis2_status_t AXIS2_CALL
	axis2_msg_recv_set_receive(axis2_msg_recv_t *msg_recv,
		const axutil_env_t *env,
		void *func);

    /**
     * Create new message receiver object. usually this will be called from the
     * extended message receiver object.
     * @see create method of raw_xml_in_out_msg_recv
     * @param env pointer to environment struct
     * @return newly created message receiver object
     **/
    AXIS2_EXTERN axis2_msg_recv_t *AXIS2_CALL
    axis2_msg_recv_create (const axutil_env_t *env);


/** @} */
#ifdef __cplusplus
}
#endif

#endif  /* AXIS2_MSG_RECV_H */
