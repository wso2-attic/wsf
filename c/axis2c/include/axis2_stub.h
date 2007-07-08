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

#ifndef AXIS2_STUB_H
#define AXIS2_STUB_H

/** @defgroup axis2_stub stub
 * @ingroup axis2_client_api
 * stub is a wrapper API for service client that helps users to use client API
 * easily.
 * @sa axis2_svc_client
 * @{
 */

/**
 * @file axis2_stub.h
 */

#include <axis2_endpoint_ref.h>
#include <axis2_svc_client.h>
#include <axis2_options.h>
#include <axiom_xml_reader.h>
#include <axutil_property.h>

/** Constant value representing SOAP version 1.1 */
#define AXIOM_SOAP_11 0
/** Constant value representing SOAP version 1.2 */
#define AXIOM_SOAP_12 1

#ifdef __cplusplus
extern "C"
{
#endif

    /** Type name for struct axis2_stub */
    typedef struct axis2_stub axis2_stub_t;

    /**
     * Frees stub struct.
     * @param stub pointer to stub struct
     * @param env pointer to environment struct
     * @return void
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_stub_free(axis2_stub_t *stub,
        const axutil_env_t *env);

    /**
     * Sets the endpoint reference.
     * @param stub pointer to stub struct
     * @param env pointer to environment struct
     * @param endpoint_ref pointer to endpoint reference. stub assumes the
     * ownership of the endpoint reference struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_stub_set_endpoint_ref(axis2_stub_t *stub,
        const axutil_env_t *env,
        axis2_endpoint_ref_t *endpoint_ref);

    /**
     * Sets the endpoint reference, represented by a string.
     * @param stub pointer to stub struct
     * @param env pointer to environment struct
     * @param endpoint_uri pointer to endpoint uri string
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_stub_set_endpoint_uri(axis2_stub_t *stub,
        const axutil_env_t *env,
        const axis2_char_t *endpoint_uri);


    /**
     * Sets the bool value specifying whether to use a separate listener
     * for receive channel.
     * @param stub pointer to stub struct
     * @param env pointer to environment struct
     * @param use_separate whether to use a separate listener
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_stub_set_use_separate_listener(axis2_stub_t *stub,
        const axutil_env_t *env,
        const axis2_bool_t use_separate_listener);

    /**
     * Sets the SOAP version.
     * @param stub pointer to stub struct
     * @param env pointer to environment struct
     * @param soap_version int value representing the SOAP version
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_stub_set_soap_version(axis2_stub_t *stub,
        const axutil_env_t *env,
        const int soap_version);


    /**
     * Gets the service context ID.
     * @param stub pointer to stub struct
     * @param env pointer to environment struct
     * @return service context ID if set, else NULL
     */
    AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
    axis2_stub_get_svc_ctx_id(const axis2_stub_t *stub,
        const axutil_env_t *env);

    /**
     * Engages the named module.
     * @param stub pointer to stub struct
     * @param env pointer to environment struct
     * @param module_name string representing the name of the module
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_stub_engage_module(axis2_stub_t *stub,
        const axutil_env_t *env,
        const axis2_char_t *module_name);

    /**
     * Gets the service client instance used by this stub.
     * @param stub pointer to stub struct
     * @param env pointer to environment struct
     * @return pointer to service client struct used by the stub
     */
    AXIS2_EXTERN axis2_svc_client_t *AXIS2_CALL
    axis2_stub_get_svc_client(const axis2_stub_t *stub,
        const axutil_env_t *env);

    /**
     * Gets the options used on top of the service client used by this stub.
     * @param stub pointer to stub struct
     * @param env pointer to environment struct
     * @return pointer to options used by the service client of this stub
     */
    AXIS2_EXTERN axis2_options_t *AXIS2_CALL
    axis2_stub_get_options(const axis2_stub_t *stub,
        const axutil_env_t *env);

    /**
     * Creates a stub instance.
     * @param env pointer to environment struct
     * @param endpoint_ref pointer to endpoint reference struct representing the
     * stub endpoint. Newly created stub assumes ownership of the endpoint
     * @param client_home name of the directory that contains the Axis2/C repository
     * @return pointer to newly created axis2_stub struct
     */
    AXIS2_EXTERN axis2_stub_t * AXIS2_CALL
    axis2_stub_create_with_endpoint_ref_and_client_home(const axutil_env_t *env,
        axis2_endpoint_ref_t *endpoint_ref,
        const axis2_char_t *client_home);

    /**
     * Creates a stub instance.
     * @param env pointer to environment struct
     * @param endpoint_uri string representing the endpoint reference
     * @param client_home name of the directory that contains the Axis2/C repository
     * @return pointer to newly created axis2_stub struct
     */
    AXIS2_EXTERN axis2_stub_t * AXIS2_CALL
    axis2_stub_create_with_endpoint_uri_and_client_home(const axutil_env_t *env,
        const axis2_char_t *endpoint_uri,
        const axis2_char_t *client_home);


    /** @} */

#ifdef __cplusplus
}
#endif

#endif /* AXIS2_STUB_H */
