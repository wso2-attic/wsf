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

#ifndef AXIS2_DISP_H
#define AXIS2_DISP_H

/**
 * @defgroup axis2_disp dispatcher
 * @ingroup axis2_engine
 * dispatcher is responsible for finding the service and operation for a given
 * invocation. A Web service request would contain information that help 
 * locate the service and the operation serving the request. This information
 * could be in various formats, and hence the mechanism to find the requested
 * service and operation based on the available information could too vary.
 * Hence there can be various types on dispatches involved in a dispatching 
 * phase of the engine, that implements the API given in this header.
 * @{
 */

/**
 * @file axis2_disp.h
 */

#include <axis2_defines.h>
#include <axutil_string.h>
#include <axis2_handler.h>
#include <axis2_svc.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define AXIS2_DISP_NAMESPACE "http://axis.ws.apache.org"

    /** Type name for struct axis2_disp */
    typedef struct axis2_disp axis2_disp_t;

    /**
     * Gets the base struct which is of type handler.
     * @param disp pointer to dispatcher
     * @param env pointer to environment struct
     * @return pointer to base handler struct. Returns a reference, not a 
     * cloned copy
     */
    AXIS2_EXTERN axis2_handler_t *AXIS2_CALL
    axis2_disp_get_base(const axis2_disp_t *disp,
        const axutil_env_t *env);

    /**
     * Gets the name of the dispatcher.
     * @param disp pointer to dispatcher
     * @param env pointer to environment struct
     * @return pointer to name. Returns a reference, not a 
     * cloned copy
     */
    AXIS2_EXTERN axutil_string_t *AXIS2_CALL
    axis2_disp_get_name(const axis2_disp_t *disp,
        const axutil_env_t *env);

    /**
     * Sets the name of the dispatcher.
     * @param disp pointer to dispatcher
     * @param env pointer to environment struct
     * @param name pointer to name, dispatcher assumes ownership of the 
     * name struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_disp_set_name(axis2_disp_t *disp,
        const axutil_env_t *env, 
        axutil_string_t *name);

    /**
     * Frees dispatcher struct.
     * @param disp pointer to dispatcher
     * @param env pointer to environment struct
     * @return void
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_disp_free(axis2_disp_t *disp,
        const axutil_env_t *env);

    /**
     * Creates a dispatcher struct instance.
     * @param env pointer to environment struct
     * @param name pointer to QName. QName is cloned by create method.
     * @return pointer to newly created dispatcher
     */
    AXIS2_EXTERN axis2_disp_t *AXIS2_CALL 
    axis2_disp_create(const axutil_env_t *env, 
        const axutil_string_t *name);

    axis2_status_t AXIS2_CALL
    axis2_disp_find_svc_and_op(
        struct axis2_handler *handler,
        const axutil_env_t *env,
        struct axis2_msg_ctx *msg_ctx);

    /**
     * Creates a WS-Addressing based dispatcher.
     * @param env pointer to environment struct
     * @return pointer to the newly created dispatcher with find_svc and find_op
     * methods implemented based on WS-Addressing
     */
    AXIS2_EXTERN axis2_disp_t *AXIS2_CALL 
    axis2_addr_disp_create(const axutil_env_t *env);

    /**
     * Creates a request URI based dispatcher.
     * @param env pointer to environment struct
     * @return pointer to the newly created dispatcher with find_svc and find_op
     * methods implemented based on request URI processing.
     */
    AXIS2_EXTERN axis2_disp_t *AXIS2_CALL 
    axis2_req_uri_disp_create(const axutil_env_t *env);

    /**
     * Creates a SOAP body based dispatcher.
     * @param env pointer to environment struct
     * @return pointer to the newly created dispatcher with find_svc and find_op
     * methods implemented based on SOAP body processing.
     */
    AXIS2_EXTERN axis2_disp_t *AXIS2_CALL 
    axiom_soap_body_disp_create(const axutil_env_t *env);

    /**
     * Creates a SOAP action based dispatcher.
     * @param env pointer to environment struct
     * @return pointer to the newly created dispatcher with find_svc and find_op
     * methods implemented based on SOAP action processing
     */
    AXIS2_EXTERN axis2_disp_t *AXIS2_CALL 
    axiom_soap_action_disp_create(const axutil_env_t *env);

#ifdef __cplusplus
}
#endif

#endif    /* AXIS2_DISP_H */
