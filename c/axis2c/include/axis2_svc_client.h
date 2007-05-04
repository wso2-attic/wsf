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

#ifndef AXIS2_SVC_CLIENT_H
#define AXIS2_SVC_CLIENT_H

/**
 * @defgroup axis2_svc_client service client
 * @ingroup axis2_client_api
 * The service client interface serves as the primary client
 * interface for consuming services. You can set the options to be
 * used by the service client and then invoke an operation on a given
 * service. There are several ways of invoking a service operation,
 * which are based on the concept of a message exchange pattern
 * (MEP). The two basic MEPs supported by service client are out-only
 * and out-in. Each MEP can be used in either blocking or
 * non-blocking mode. The operation invocations using the service
 * client API are based on the XML-in/XML-out principle: both the
 * payload to be sent to the service and the result from the service
 * are in XML, represented in AXIOM.
 * @{
 */


/**
 * @file axis2_svc_client.h
 */

#include <axis2_defines.h>
#include <axutil_env.h>
#include <axutil_uri.h>
#include <axis2_svc.h>
#include <axis2_options.h>
#include <axutil_qname.h>
#include <axiom_element.h>
#include <axis2_callback.h>
#include <axis2_endpoint_ref.h>
#include <axis2_svc_ctx.h>
#include <axis2_conf_ctx.h>
#include <axis2_op_client.h>
#include <axutil_string.h>

/** Name of anonymous service */
#define AXIS2_ANON_SERVICE  "__ANONYMOUS_SERVICE__"

/** out-only MEP operation name */
#define AXIS2_ANON_OUT_ONLY_OP "__OPERATION_OUT_ONLY__"

/** out-only robust MEP operation name */
#define AXIS2_ANON_ROBUST_OUT_ONLY_OP "__OPERATION_ROBUST_OUT_ONLY__"

/** out-in MEP operation name */
#define AXIS2_ANON_OUT_IN_OP "__OPERATION_OUT_IN__"

#define AXIS2_HTTP_PROXY_API "PROXY_API"
#define AXIS2_HTTP_PROXY_HOST "proxy_host"
#define AXIS2_HTTP_PROXY_PORT "proxy_port"
#ifdef __cplusplus
extern "C"
{
#endif

    /** Type name for struct axis2_svc_client */
    typedef struct axis2_svc_client axis2_svc_client_t;


    /**
     * Returns the axis2_svc_t this is a client for. This is primarily 
     * useful when the service is created anonymously or from WSDL.
     * @param svc_client pointer to service client struct
     * @param env pointer to environment struct
     * @return a pointer to axis service struct, or NULL if no service 
     * is associated. Returns a reference, not a cloned copy. 
     */
    AXIS2_EXTERN axis2_svc_t *AXIS2_CALL
    axis2_svc_client_get_svc(const axis2_svc_client_t *svc_client,
        const axutil_env_t *env);

    /**
     * Sets the options to be used by service client.
     * @param svc_client pointer to service client struct
     * @param env pointer to environment struct
     * @param options pointer to options struct to be set
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_client_set_options(axis2_svc_client_t *svc_client,
        const axutil_env_t *env,
        const axis2_options_t *options);

    /**
     * Gets options used by service client. 
     * @param svc_client pointer to service client struct
     * @param env pointer to environment struct
     * @return a pointer to the options struct if options set, else NULL.
     * Returns a reference, not a cloned copy.
     */
    AXIS2_EXTERN const axis2_options_t *AXIS2_CALL
    axis2_svc_client_get_options(const axis2_svc_client_t *svc_client,
        const axutil_env_t *env);

    /**
     * Sets the overriding options. The overriding client options related 
     * to this service interaction override any options that the 
     * underlying operation client may have.
     * @param svc_client pointer to service client struct
     * @param env pointer to environment struct
     * @param options pointer to options struct to be set
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_client_set_override_options(axis2_svc_client_t *svc_client,
        const axutil_env_t *env,
        const axis2_options_t *override_options);

    /**
     * Gets the overriding options.
     * @param svc_client pointer to service client struct
     * @param env pointer to environment struct
     * @return pointer to overriding options struct if options set, else NULL.
     * Returns a reference, not a cloned copy.
     */
    AXIS2_EXTERN const axis2_options_t *AXIS2_CALL
    axis2_svc_client_get_override_options(const axis2_svc_client_t *svc_client,
        const axutil_env_t *env);

    /**
     * Engages the named module. The engaged modules extend the message
     * processing when consuming services. Modules help to apply QoS
     * norms in messaging. Once a module is engaged to a service client,
     * the axis2_engine makes sure to invoke the module for all the 
     * interactions between the client and the service.
     * @param svc_client pointer to service client struct
     * @param env pointer to environment struct
     * @param module_name name of the module to be engaged
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_client_engage_module(axis2_svc_client_t *svc_client,
        const axutil_env_t *env,
        const axis2_char_t *module_name);

    /**
     * Dis-engages the named module. Dis-engaging a module on a service 
     * client ensures that the axis2_engine would not invoke the named 
     * module when sending and receiving messages.
     * @param svc_client pointer to service client struct
     * @param env pointer to environment struct
     * @param module_name name of the module to be dis-engaged
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_client_disengage_module(axis2_svc_client_t *svc_client,
        const axutil_env_t *env,
        const axis2_char_t *module_name);

    /**
     * Adds an XML element as a header to be sent to the server side.
     * This allows users to go beyond the usual XML-in/XML-out pattern,
     * and send custom SOAP headers. Once added, service client owns
     * the header and will clean up when the service client is freed.
     * @param svc_client pointer to service client struct
     * @param env pointer to environment struct
     * @param header om node representing the SOAP header in XML
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_client_add_header(axis2_svc_client_t *svc_client,
        const axutil_env_t *env,
        axiom_node_t *header);

    /**
     * Removes all the headers added to service client.
     * @param svc_client pointer to service client struct
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_client_remove_all_headers(axis2_svc_client_t *svc_client,
        const axutil_env_t *env);

    /**
     * This method can be used to send an XML message.
     * This is a simple method to invoke a service operation whose MEP is
     * Robust Out-Only. If a fault triggers on server side, this method 
     * would report an error back to the caller.
     * @param svc_client pointer to service client struct
     * @param env pointer to environment struct
     * @param op_qname operation qname. NULL is equivalent to an
     * operation name of "__OPERATION_ROBUST_OUT_ONLY__"
     * @param payload pointer to OM node representing the XML payload to be sent
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_client_send_robust_with_op_qname(axis2_svc_client_t *svc_client,
        const axutil_env_t *env,
        const axutil_qname_t *op_qname,
        const axiom_node_t *payload);

    /**
     * This method can be used to send an XML message.
     * This is a simple method to invoke a service operation whose MEP is
     * Robust Out-Only. If a fault triggers on server side, this method 
     * would report an error back to the caller.
     * @param svc_client pointer to service client struct
     * @param env pointer to environment struct
     * operation name of "__OPERATION_ROBUST_OUT_ONLY__"
     * @param payload pointer to OM node representing the XML payload to be sent
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_client_send_robust(axis2_svc_client_t *svc_client,
        const axutil_env_t *env,
        const axiom_node_t *payload);

    /**
     * Sends a message and forget about it. This method is used to interact with
     * a service operation whose MEP is In-Only. That is, there is no
     * opportunity to get an error from the service via this method; one may still
     * get client-side errors, such as host unknown etc.
     * @param svc_client pointer to service client struct
     * @param env pointer to environment struct
     * @param op_qname operation qname. NULL is equivalent to an
     * operation name of "__OPERATION_OUT_ONLY__"
     * @param payload pointer to OM node representing the XML payload to be sent
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_svc_client_fire_and_forget_with_op_qname(axis2_svc_client_t *svc_client,
        const axutil_env_t *env,
        const axutil_qname_t *op_qname,
        const axiom_node_t *payload);

    /**
     * Sends a message and forget about it. This method is used to interact with
     * a service operation whose MEP is In-Only. That is, there is no
     * opportunity to get an error from the service via this method; one may still
     * get client-side errors, such as host unknown etc.
     * @param svc_client pointer to service client struct
     * @param env pointer to environment struct
     * @param payload pointer to OM node representing the XML payload to be sent
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_svc_client_fire_and_forget(axis2_svc_client_t *svc_client,
        const axutil_env_t *env,
        const axiom_node_t *payload);

    /**
     * Sends XML request and receives XML response.
     * This method is used to interact with a service operation whose MEP is In-Out.
     * @param svc_client pointer to service client struct
     * @param env pointer to environment struct
     * @param op_qname operation qname. NULL is equivalent to an
     * operation name of "__OPERATION_OUT_IN__"
     * @param payload pointer to OM node representing the XML payload to be sent
     * @return pointer to OM node representing the XML response. The 
     * caller owns the returned node.
     */
    AXIS2_EXTERN axiom_node_t *AXIS2_CALL
    axis2_svc_client_send_receive_with_op_qname(axis2_svc_client_t *svc_client,
        const axutil_env_t *env,
        const axutil_qname_t *op_qname,
        const axiom_node_t *payload);

    /**
     * Sends XML request and receives XML response.
     * This method is used to interact with a service operation whose MEP is In-Out.
     * @param svc_client pointer to service client struct
     * @param env pointer to environment struct
     * @param payload pointer to OM node representing the XML payload to be sent
     * @return pointer to OM node representing the XML response. The 
     * caller owns the returned node.
     */
    AXIS2_EXTERN axiom_node_t *AXIS2_CALL
    axis2_svc_client_send_receive(axis2_svc_client_t *svc_client,
        const axutil_env_t *env,
        const axiom_node_t *payload);

    /**
     * Sends XML request and receives XML response, but does not block for response.
     * This method is used to interact in non-blocking mode with a service
     * operation whose MEP is In-Out.
     * @param svc_client pointer to service client struct
     * @param env pointer to environment struct
     * @param op_qname operation qname. NULL is equivalent to an
     * operation name of "__OPERATION_OUT_IN__"
     * @param payload pointer to OM node representing the XML payload to be sent
     * @callback pointer to callback struct used to capture response
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_svc_client_send_receive_non_blocking_with_op_qname(axis2_svc_client_t *svc_client,
        const axutil_env_t *env,
        const axutil_qname_t *op_qname,
        const axiom_node_t *payload,
        axis2_callback_t *callback);

    /**
     * Sends XML request and receives XML response, but does not block for response.
     * This method is used to interact in non-blocking mode with a service
     * operation whose MEP is In-Out.
     * @param svc_client pointer to service client struct
     * @param env pointer to environment struct
     * @param payload pointer to OM node representing the XML payload to be sent
     * @callback pointer to callback struct used to capture response
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_svc_client_send_receive_non_blocking(axis2_svc_client_t *svc_client,
        const axutil_env_t *env,
        const axiom_node_t *payload,
        axis2_callback_t *callback);

    /**
     * Creates an op_client for a specific operation. This is the way to  
     * create a full functional MEP client which can be used to exchange 
     * messages for this specific operation.
     * @param svc_client pointer to service client struct
     * @param env pointer to environment struct
     * @param op_qname axutil_qname_t of the operation
     * @return pointer to newly created op_client configured for the given operation
     */
    AXIS2_EXTERN axis2_op_client_t *AXIS2_CALL
    axis2_svc_client_create_op_client(axis2_svc_client_t *svc_client,
        const axutil_env_t *env,
        const axutil_qname_t *op_qname);

    /**
     * Cleans up service client invocation. This will close the output 
     * stream and/or remove entry from waiting queue of the transport 
     * listener queue.
     * @param svc_client pointer to service client struct
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_client_finalize_invoke(axis2_svc_client_t *svc_client,
        const axutil_env_t *env);

    /**
     * Gets the service client's own endpoint_ref, that is the
     * endpoint the client will be sending from.
     * @param svc_client pointer to service client struct
     * @param env pointer to environment struct
     * @param transport name of the transport, e.g "http"
     * @return pointer to the endpoint_ref struct. Returns a reference, 
     * not a cloned copy.
     */
    AXIS2_EXTERN const axis2_endpoint_ref_t *AXIS2_CALL
    axis2_svc_client_get_own_endpoint_ref(const axis2_svc_client_t *svc_client,
        const axutil_env_t *env,
        const axis2_char_t *transport);

    /**
     * Gets the target endpoint ref.
     * @param svc_client pointer to service client struct
     * @param env pointer to environment struct
     * @return pointer to the endpoint_ref struct. Returns a reference, 
     * not a cloned copy.
     */
    AXIS2_EXTERN const axis2_endpoint_ref_t *AXIS2_CALL
    axis2_svc_client_get_target_endpoint_ref(const axis2_svc_client_t *svc_client,
        const axutil_env_t *env);

    /**
     * Sets the target endpoint ref.
     * @param svc_client pointer to service client struct
     * @param env pointer to environment struct
     * @param target_epr pointer to the endpoint_ref struct to be set as 
     * target. service client takes over the ownership of the struct.
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_client_set_target_endpoint_ref(axis2_svc_client_t *svc_client,
        const axutil_env_t *env,
        axis2_endpoint_ref_t *target_epr);


    /**
     * Sets the proxy.
     * @param svc_client pointer to service client struct
     * @param env pointer to environment struct
     * @param proxy_host pointer to the proxy_host settings to be set
     * as 
     * @param proxy_port pointer to the proxy_port settings to be set
     * as  
     * target. service client takes over the ownership of the struct.
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_client_set_proxy(axis2_svc_client_t *svc_client,
        const axutil_env_t *env,
        axis2_char_t *proxy_host,
        axis2_char_t *proxy_port);

    /**
     * Gets the service context.
     * @param svc_client pointer to service client struct
     * @param env pointer to environment struct
     * @return pointer to service context struct. service client owns
     * the returned pointer.
     */
    AXIS2_EXTERN axis2_svc_ctx_t *AXIS2_CALL
    axis2_svc_client_get_svc_ctx(const axis2_svc_client_t *svc_client,
        const axutil_env_t *env);

    /**
     * Frees the service client.
     * @param svc_client pointer to service client struct
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */

    AXIS2_EXTERN void AXIS2_CALL
    axis2_svc_client_free(axis2_svc_client_t *svc_client,
        const axutil_env_t *env);

    /**
     * Gets the operation client
     * @param svc_client pointer to service_client struct
     * @param env env pointer to environemt struct
     * @return pointer to service context struct. service client owns 
     * the returned pointer
     */
    AXIS2_EXTERN axis2_op_client_t *AXIS2_CALL
    axis2_svc_client_get_op_client(const axis2_svc_client_t *svc_client,
        const axutil_env_t *env);

    /**
     * Creates a service client struct.
     * @param env pointer to environment struct
     * @param client_home name of the directory that contains the Axis2/C repository
     * @return a pointer to newly created service client struct,
     *         or NULL on error with error code set in environment's error
     */
    AXIS2_EXTERN axis2_svc_client_t * AXIS2_CALL
    axis2_svc_client_create(const axutil_env_t *env,
        const axis2_char_t *client_home);

    /**
     * Creates a service client struct for a specified service and configuration
     * context.
     * @param env pointer to environment struct
     * @param conf_ctx pointer to configuration context. Newly created client 
     * assumes ownership of the conf_ctx
     * @param svc pointer to service struct representing the service to be consumed.
     * Newly created client assumes ownership of the service 
     * @param client_home name of the directory that contains the Axis2/C repository
     * @return a pointer to newly created service client struct,
     *         or NULL on error with error code set in environment's error
     */
    AXIS2_EXTERN axis2_svc_client_t * AXIS2_CALL
    axis2_svc_client_create_with_conf_ctx_and_svc(const axutil_env_t *env,
        const axis2_char_t *client_home,
        axis2_conf_ctx_t *conf_ctx,
        axis2_svc_t *svc);

    /**
     * Creates a service client struct. This constructor is used in dynamic
     * invocation.
     * @param env pointer to environment struct
     * @param conf_ctx pointer to configuration context. Newly created client 
     * assumes ownership of the conf_ctx
     * @param wsdl_uri pointer to uri of the wsdl file.
     * @param wsdl_svc_qname pointer to qname of the wsdl service. If this is NULL
     * first service is assumed
     * @param endpoint_name pointer to endpoint name. If this is NULL first endpoint
     * is assumed.
     * @param client_home name of the directory that contains the Axis2/C repository
     * @return a pointer to newly created service client struct,
     *         or NULL on error with error code set in environment's error
     */
    AXIS2_EXTERN axis2_svc_client_t* AXIS2_CALL
    axis2_svc_client_create_for_dynamic_invocation(const axutil_env_t *env,
        axis2_conf_ctx_t *conf_ctx,
        const axutil_uri_t *wsdl_uri,
        const axutil_qname_t *wsdl_svc_qname,
        const axis2_char_t *endpoint_name,
        const axis2_char_t *client_home);

    /**
     * Gets the last respose SOAP envelope. 
     * @param svc_client pointer to service_client struct
     * @param env env pointer to environemt struct
     * @return pointer to SOAP envelope that was returned as a result 
     * when send_receieve was called last time
     */
    AXIS2_EXTERN axiom_soap_envelope_t *AXIS2_CALL
    axis2_svc_client_get_last_response_soap_envelope(const axis2_svc_client_t *svc_client,
        const axutil_env_t *env);

    /**
     * Gets the boolean value indicating if the last respose had a SOAP fault. 
     * @param svc_client pointer to service_client struct
     * @param env env pointer to environemt struct
     * @return AXIS2_TRUE if there was a fault, else AXIS2_FALSE
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_svc_client_get_last_response_has_fault(const axis2_svc_client_t *svc_client,
        const axutil_env_t *env);

/** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* AXIS2_SVC_CLIENT_H */
