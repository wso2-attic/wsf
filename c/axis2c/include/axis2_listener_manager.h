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

#ifndef AXIS2_LISTENER_MANAGER_H
#define AXIS2_LISTENER_MANAGER_H

/**
 * @defgroup axis2_listener_manager listener manager
 * @ingroup axis2_core_context
 * listener manager manages the listeners in case of dual channel invocations.
 * In case of a dual channel invocation, request is sent along one channel
 * and the response is received on another channel. When the response is
 * expected to be received along another transport channel, it has to be
 * made sure that the listener socket is up in anticipation of the response
 * and also that listener must be closed once the response is received.
 * listener manager is responsible for dealing with these tasks.
 * @{
 */


/**
  * @file axis2_listener_manager.h
  */

#include <axis2_defines.h>
#include <axutil_env.h>
#include <axis2_conf_ctx.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /** Type name for struct axis2_listener_manager */
    typedef struct axis2_listener_manager axis2_listener_manager_t;


    /**
     * Ensures that the named transport's listener is started. Starts a listener 
     * if it is not already started. Only one listener would be started for a given 
     * transport.
     * @param listener_manager pointer to listener manager struct
     * @param env pointer to environment struct         
     * @param transport name of the transport
     * @param conf_ctx configuration context to pick transport info for the 
     * named transport
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_listener_manager_make_sure_started(axis2_listener_manager_t *listener_manager,
        const axutil_env_t *env,
        const AXIS2_TRANSPORT_ENUMS transport,
        axis2_conf_ctx_t *conf_ctx);

   /**
     * Stops the named listener transport.
     * @param listener_manager pointer to listener manager struct
     * @param env pointer to environment struct         
     * @param transport name of the transport whose listener is to be stopped
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_listener_manager_stop(axis2_listener_manager_t *listener_manager,
        const axutil_env_t *env,
        const AXIS2_TRANSPORT_ENUMS transport);

    /**
     * Gets reply to end point reference. The engine will direct the 
     * response for the message to this reply to address.
     * @param listener_manager pointer to listener manager struct
     * @param env pointer to environment struct         
     * @param svc_name name of the service for which the epr is to be returned
     * @param transport name of the transport corresponding to the endpoint
     * @return a pointer to endpoint reference struct representing the reply 
     * endpoint
     */
    AXIS2_EXTERN axis2_endpoint_ref_t* AXIS2_CALL
    axis2_listener_manager_get_reply_to_epr(const axis2_listener_manager_t *listener_manager,
        const axutil_env_t *env,
        const axis2_char_t *svc_name,
        const AXIS2_TRANSPORT_ENUMS transport);

    /**
     * Gets the configuration context that holds information on the transports 
     * managed by the listener manager.
     * @param listener_manager pointer to listener manager struct
     * @param env pointer to environment struct         
     */
    AXIS2_EXTERN axis2_conf_ctx_t *AXIS2_CALL
    axis2_listener_manager_get_conf_ctx(const axis2_listener_manager_t *listener_manager,
        const axutil_env_t *env);

   /**
     * Frees listener manager struct.
     * @param listener_manager pointer to listener manager struct
     * @param env pointer to environment struct         
     * @return void
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_listener_manager_free(axis2_listener_manager_t *listener_manager,
        const axutil_env_t *env);


    /**
     * Creates a listener manager struct instance.
     * @param env pointer to environment struct
     * @return a pointer to newly created listener manager struct,
     *         or NULL on error with error code set in environment's error
     */
    AXIS2_EXTERN axis2_listener_manager_t *AXIS2_CALL
    axis2_listener_manager_create(const axutil_env_t *env);


    /** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* AXIS2_LISTENER_MANAGER_H */
