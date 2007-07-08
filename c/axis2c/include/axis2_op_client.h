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

#ifndef AXIS2_OP_CLIENT_H
#define AXIS2_OP_CLIENT_H

/**
 * @defgroup axis2_client_api client API
 * @ingroup axis2
 * @{
 * @}
 */

/**
 * @defgroup axis2_op_client operation client
 * @ingroup axis2_client_api
 * The operation client is meant to be used by advanced users to consume services.
 * Operation client understands a specific Message Exchange Pattern (op) and 
 * hence the behavior is defined by the op. 
 * To consume services with an operation client, an operation (of type axis2_op_t) 
 * and a service context (of type axis2_svc_ctx_t)
 * has to be provided along with options to be used. The execute() function
 * can be used to send the request and get the response. 
 * The service client implementation uses the operation client and provides an
 * easy to use API for consuming services. Hence the service client 
 * implementation is a very good example of how to use the operation client API.
 * @sa axis2_svc_client
 * @{
 */


/**
 * @file axis2_op_client.h
 */

#include <axis2_defines.h>
#include <axutil_env.h>
#include <axis2_options.h>
#include <axis2_msg_ctx.h>
#include <axis2_callback.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /** Type name for struct axis2_op_client */
    typedef struct axis2_op_client axis2_op_client_t;
        
    struct axis2_callback_recv;


    /**
     * Sets the options that is to be used by this operation client. 
     * @param op_client pointer to operation client struct
     * @param env pointer to environment struct
     * @param options pointer to options struct to be set
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_op_client_set_options(axis2_op_client_t *op_client,
        const axutil_env_t *env,
        const axis2_options_t *options);

    /**
     * Gets options used by operation client. 
     * @param op_client pointer to operation client struct
     * @param env pointer to environment struct
     * @return a pointer to the options struct if options set, else NULL.
     * Returns a reference, not a cloned copy.         
     */
    AXIS2_EXTERN const axis2_options_t* AXIS2_CALL
    axis2_op_client_get_options(const axis2_op_client_t *op_client,
        const axutil_env_t *env);

    /**
     * Adds a message context to the client for processing. 
     * @param op_client pointer to operation client struct
     * @param env pointer to environment struct
     * @param msg_ctx message context to be added. operation client takes 
     * over the ownership of the message context struct.
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_op_client_add_msg_ctx(
        axis2_op_client_t *op_client,
        const axutil_env_t *env,
        axis2_msg_ctx_t *msg_ctx);

    /**
     * Adds out message context to the client for processing. 
     * @param op_client pointer to operation client struct
     * @param env pointer to environment struct
     * @param msg_ctx message context to be added. operation client takes 
     * over the ownership of the message context struct.
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_op_client_add_out_msg_ctx(axis2_op_client_t *op_client,
        const axutil_env_t *env,
        axis2_msg_ctx_t *msg_ctx);


    /**
     * Gets a message corresponding to the given label.
     * @param op_client pointer to operation client struct
     * @param env pointer to environment struct
     * @param message_label the message label of the desired message context
     * @return the desired message context or NULL if its not available.
     * Returns a reference, not a cloned copy.
     */
    AXIS2_EXTERN const axis2_msg_ctx_t* AXIS2_CALL
    axis2_op_client_get_msg_ctx(const axis2_op_client_t *op_client,
        const axutil_env_t *env,
        const axis2_wsdl_msg_labels_t message_label);

    /**
     * Sets the callback to be executed when a response message is received. 
     * @param op_client pointer to operation client struct
     * @param env pointer to environment struct
     * @param callback the callback to be used. operation client takes 
     * over the ownership of the message context struct.
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_op_client_set_callback(axis2_op_client_t *op_client,
        const axutil_env_t *env,
        axis2_callback_t *callback);
    /**
     * Gets the callback. 
     * @param op_client pointer to operation client struct
     * @param env pointer to environment struct
     * @return callback
     */
    AXIS2_EXTERN axis2_callback_t *AXIS2_CALL
    axis2_op_client_get_callback(axis2_op_client_t *op_client,
        const axutil_env_t *env);

    /**
     * Execute the op. What this does depends on the specific operation client.
     * The basic idea is to have the operation client execute and do something
     * with the messages that have been added to it so far. For example, if its
     * an Out-In op, and if the Out message has been set, then executing the
     * client asks it to send the out message and get the in message
     * @param op_client pointer to operation client
     * @param env pointer to environment struct
     * @param block indicates whether execution should block or return ASAP
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_op_client_execute(axis2_op_client_t *op_client,
        const axutil_env_t *env,
        const axis2_bool_t block);

    /**
     * Resets the operation client to a clean status after the op has completed.
     * This is how you can reuse an operation client. Note that this does not reset
     * the options; only the internal state so the client can be used again.
     * @param op_client pointer to operation client
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_op_client_reset(axis2_op_client_t *op_client,
        const axutil_env_t *env);

    /**
     * Completes the execution by closing the transports if necessary.
     * This method is useful when client uses two transports for sending and 
     * receiving.
     * @param op_client pointer to operation client struct
     * @param env pointer to environment struct
     * @param msg_ctx message context which contains the transport information
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_op_client_complete(axis2_op_client_t *op_client,
        const axutil_env_t *env,
        axis2_msg_ctx_t *msg_ctx);

    /**
     * Gets the operation context of the operation client.
     * @param op_client pointer to operation client struct
     * @param env pointer to environment struct                
     * @return operation context related to operation client
     */
    AXIS2_EXTERN axis2_op_ctx_t* AXIS2_CALL
    axis2_op_client_get_operation_context(const axis2_op_client_t *op_client,
        const axutil_env_t *env);

    /**
     * Sets callback receiver.
     * @param op_client pointer to operation client struct
     * @param env pointer to environment struct
     * @param callback_recv pointer to callback receiver struct.
     * operation client assumes ownership of the callback struct.
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_op_client_set_callback_recv(axis2_op_client_t *op_client,
        const axutil_env_t *env,
        struct axis2_callback_recv *callback_recv);

    /**
     * Frees the operation client
     * @param op_client pointer to operation client struct
     * @param env pointer to environment struct
     * @return void
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_op_client_free(axis2_op_client_t *op_client,
        const axutil_env_t *env);

    /**
     * Creates an operation client struct for the specified operation, service 
     * context and given options.
     * @param env pointer to environment struct
     * @param op pointer to operation struct corresponding to the operation to 
     * to be executed. Newly created client assumes ownership of the operation.
     * @param svc_ctx pointer to service context struct representing the service
     * to be consumed. Newly created client assumes ownership of the service 
     * context.
     * @param options options to be used by operation client. Newly created 
     * client assumes ownership of the options
     * context.
     * @return a pointer to newly created operation client struct,
     * or NULL on error with error code set in environment's error
     */
    AXIS2_EXTERN axis2_op_client_t* AXIS2_CALL 
    axis2_op_client_create(const axutil_env_t *env,
        axis2_op_t *op,
        axis2_svc_ctx_t *svc_ctx,
        axis2_options_t *options);

     
    /**
     * Gets SOAP action.
     * @param op_client pointer to op client struct
     * @param env pointer to environment struct
     * @return a pointer to SOAP action string
     */
    AXIS2_EXTERN axutil_string_t *AXIS2_CALL
    axis2_op_client_get_soap_action(const axis2_op_client_t *op_client,
        const axutil_env_t *env);
    
    /**
     * Prepares the message context for invocation. Here the properties kept
     * in the op_client are copied to the message context.
     * @param op_client pointer to op client struct
     * @param env pointer to environment struct
     * @param op pointer operation to be invoked
     * @param msg_ctx pointer to message context to be filled
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_op_client_prepare_invocation(axis2_op_client_t *op_client,
        const axutil_env_t *env,
        axis2_op_t *op,
        axis2_msg_ctx_t *msg_ctx);

    /**
     * Prepares the SOAP envelope using the payload. 
     * @param op_client pointer to op client struct
     * @param env pointer to environment struct
     * @param to_send payload to be sent in AXIOM node format
     * @return a pointer to message context struct filled with the SOAP 
     * envelope to be sent
     */
    AXIS2_EXTERN axis2_msg_ctx_t* AXIS2_CALL
    axis2_op_client_prepare_soap_envelope(axis2_op_client_t *op_client,
        const axutil_env_t *env,
        axiom_node_t *to_send);

    /**
     * Tries to infer the transport looking at the URL, the URL can be http://
     * tcp:// mail:// local://. The method will look for the transport name as the
     * protocol part of the transport.
     * @param op_client pointer to op client struct
     * @param env pointer to environment struct
     * @param epr endpoint reference struct representing the endpoint URL
     * @return pointer to the transport description with inferred information
     */
    AXIS2_EXTERN axis2_transport_out_desc_t *AXIS2_CALL
    axis2_op_client_infer_transport(axis2_op_client_t *op_client,
        const axutil_env_t *env,
        axis2_endpoint_ref_t *epr);

    /**
     * Creates default SOAP envelope.
     * @param op_client pointer to op client struct
     * @param env pointer to environment struct
     * @return pointer to default SOAP envelope created
     */
    AXIS2_EXTERN axiom_soap_envelope_t *AXIS2_CALL
    axis2_op_client_create_default_soap_envelope(axis2_op_client_t *op_client,
        const axutil_env_t *env);

    /**
     * Engage named module. The named module must have been configured in 
     * the Axis2 configuration. For a module to be detected by the 
     * deployment engine, the modules has to be placed in the 
     * AXIS2_REPOSITORY/modules directory.
     * @param op_client pointer to op client struct
     * @param env pointer to environment struct
     * @param qname QName representing the module name 
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_op_client_engage_module(axis2_op_client_t *op_client,
        const axutil_env_t *env,
        const axutil_qname_t *qname);
    
    /**
     * Sets SOAP version URI.
     * @param op_client pointer to op client struct
     * @param env pointer to environment struct
     * @param soap_version_uri SOAP version URI
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_op_client_set_soap_version_uri(axis2_op_client_t *op_client,
        const axutil_env_t *env,
        const axis2_char_t *soap_version_uri);
    
    /**
     * Sets SOAP action.
     * @param op_client pointer to op client struct
     * @param env pointer to environment struct
     * @param soap_action SOAP action
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_op_client_set_soap_action(axis2_op_client_t *op_client,
        const axutil_env_t *env,
        axutil_string_t *soap_action);
    
    /**
     * Sets WSA action.
     * @param op_client pointer to op client struct
     * @param env pointer to environment struct
     * @param wsa_action Web services Addressing action
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_op_client_set_wsa_action(axis2_op_client_t *op_client,
        const axutil_env_t *env,
        const axis2_char_t *wsa_action);

    /**
     * Gets service context.
     * @param op_client pointer to op client struct
     * @param env pointer to environment struct         
     * @return pointer to service context struct if set, else NULL
     */
    AXIS2_EXTERN axis2_svc_ctx_t *AXIS2_CALL
    axis2_op_client_get_svc_ctx(const axis2_op_client_t *op_client,
        const axutil_env_t *env);


    /**
     * Sends a message represented by the given message context and captures
     * the response in return message context.
     * @param env pointer to environment struct
     * @param msg_ctx pointer to message context representing the message to 
     * be sent
     * @return message context representing the received response
     */    
    AXIS2_EXTERN axis2_msg_ctx_t *AXIS2_CALL
    axis2_op_client_two_way_send(const axutil_env_t *env,
        axis2_msg_ctx_t *msg_ctx);

    /**
     * Receives a message corresponding to a request depicted by given 
     * message context.
     * @param env pointer to environment struct
     * @param msg_ctx pointer to message context representing the response to 
     * be received
     * @return message context representing the received response
     */
    AXIS2_EXTERN axis2_msg_ctx_t *AXIS2_CALL
    axis2_op_client_receive(const axutil_env_t *env,
        axis2_msg_ctx_t *msg_ctx);

/** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* AXIS2_OP_CLIENT_H */
