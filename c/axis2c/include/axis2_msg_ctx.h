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

#ifndef AXIS2_MSG_CTX_H
#define AXIS2_MSG_CTX_H

/** 
 * @defgroup axis2_msg_ctx message context
 * @ingroup axis2_context
 * message context captures all state information related to a message 
 * invocation. It holds information on the service and operation to be invoked
 * as well as context hierarchy information related to the service and operation. 
 * It also has information on transports, that are to be used in invocation. The 
 * phase information is kept, along with the phase at which message invocation was 
 * paused as well as the handler in the phase from which the invocation is to be 
 * resumed. message context would hold the request SOAP message along the out 
 * path and would capture response along the in path.
 * message context also has information on various engine specific information, 
 * such as if it should be doing MTOM, REST. 
 * As message context is inherited form context, it has the capability of 
 * storing user defined properties.
 * @{
 */

/**
 * @file axis2_msg_ctx.h
 */

#include <axis2_defines.h>
#include <axutil_env.h>
#include <axis2_ctx.h>
#include <axis2_relates_to.h>
#include <axutil_param.h>
#include <axis2_handler_desc.h>
#include <axutil_qname.h>
#include <axutil_stream.h>
#include <axis2_msg_info_headers.h>

#ifdef __cplusplus
extern "C"
{
#endif

/** transport headers */
#define AXIS2_TRANSPORT_HEADERS "AXIS2_TRANSPORT_HEADERS" 

/** transport in */
#define AXIS2_TRANSPORT_OUT "AXIS2_TRANSPORT_OUT" 

/** transport out */
#define AXIS2_TRANSPORT_IN "AXIS2_TRANSPORT_IN" 

/** character set encoding */
#define AXIS2_CHARACTER_SET_ENCODING "AXIS2_CHARACTER_SET_ENCODING" 

/** UTF_8; This is the 'utf-8' value for AXIS2_CHARACTER_SET_ENCODING property  */
#define AXIS2_UTF_8 "UTF-8" 

/** UTF_16; This is the 'utf-16' value for AXIS2_CHARACTER_SET_ENCODING property  */
#define AXIS2_UTF_16 "utf-16" 

/** default char set encoding; This is the default value for AXIS2_CHARACTER_SET_ENCODING property */
#define AXIS2_DEFAULT_CHAR_SET_ENCODING "UTF-8" 

/** transport succeeded */
#define AXIS2_TRANSPORT_SUCCEED "AXIS2_TRANSPORT_SUCCEED" 

/** HTTP Client */
#define AXIS2_HTTP_CLIENT "AXIS2_HTTP_CLIENT"

/** Transport URL */
#define AXIS2_TRANSPORT_URL "TransportURL" 

#define AXIS2_SVR_PEER_IP_ADDR "peer_ip_addr"
/* Message flows */
/** In flow */
/*#define AXIS2_IN_FLOW 1*/

/** In fault flow */
/*#define AXIS2_IN_FAULT_FLOW 2*/

/** Out flow */
/*#define AXIS2_OUT_FLOW 3*/

/** Out fault flow */
/*#define AXIS2_OUT_FAULT_FLOW 4*/

    /** Type name for struct axis2_msg_ctx */
    typedef struct axis2_msg_ctx axis2_msg_ctx_t;

    struct axis2_svc;
    struct axis2_op;

    struct axis2_conf_ctx;
    struct axis2_svc_grp_ctx;
    struct axis2_svc_ctx;
    struct axis2_op_ctx;
    struct axis2_conf;
    struct axiom_soap_envelope;
    struct axis2_options;
    struct axis2_transport_in_desc;    
    struct axis2_transport_out_desc;
    struct axis2_http_out_transport_info;

    /**
     * Creates a message context struct instance.
     * @param env pointer to environment struct
     * @param conf_ctx pointer to configuration context struct, message context
     * does not assume the ownership of the struct
     * @param transport_in_desc pointer to transport in description struct, 
     * message context does not assume the ownership of the struct
     * @param transport_out_desc pointer to transport out description struct,
     * message context does not assume the ownership of the struct
     * @return pointer to newly created message context instance
     */
    AXIS2_EXTERN axis2_msg_ctx_t *AXIS2_CALL
    axis2_msg_ctx_create (const axutil_env_t *env,
        struct axis2_conf_ctx *conf_ctx,
        struct axis2_transport_in_desc *transport_in_desc,
        struct axis2_transport_out_desc *transport_out_des);

    /**
     * Gets the base, which is of type context.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return pointer to base context struct
     */
    AXIS2_EXTERN axis2_ctx_t *AXIS2_CALL
    axis2_msg_ctx_get_base(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Gets parent. Parent of a message context is of type operation.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return pointer to operation which is the parent
     */
    AXIS2_EXTERN struct axis2_op_ctx *AXIS2_CALL
    axis2_msg_ctx_get_parent(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Sets parent. Parent of a message context is of type operation.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param parent pointer to parent operation
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_parent(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        struct axis2_op_ctx *parent);

    /**
     * Frees message context.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return void
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_msg_ctx_free(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Initializes the message context. Based on the transport, service and
     * operation qnames set on top of message context, correct instances of 
     * those struct instances would be extracted from configuration and 
     * set within message context.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param conf pointer to configuration
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_init(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        struct axis2_conf *conf);

    /**
     * Gets WS-Addressing fault to address. Fault to address tells where to 
     * send the fault in case there is an error.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return pointer to endpoint reference struct representing the fault 
     * to address, returns a reference not a cloned copy
     */
    AXIS2_EXTERN axis2_endpoint_ref_t *AXIS2_CALL
    axis2_msg_ctx_get_fault_to(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Gets WS-Addressing from endpoint. From address tells where the 
     * request came from.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return pointer to endpoint reference struct representing the from 
     * address, returns a reference not a cloned copy
     */
    AXIS2_EXTERN axis2_endpoint_ref_t *AXIS2_CALL
    axis2_msg_ctx_get_from(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Checks if there is a SOAP fault on in flow.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return AXIS2_TRUE if there is an in flow fault, else AXIS2_FALSE
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_msg_ctx_get_in_fault_flow(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Gets the SOAP envelope. This SOAP envelope could be either request
     * SOAP envelope or the response SOAP envelope, based on the state
     * the message context is in.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return pointer to SOAP envelope stored within message context
     */
    AXIS2_EXTERN struct axiom_soap_envelope *AXIS2_CALL
    axis2_msg_ctx_get_soap_envelope(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);


    AXIS2_EXTERN struct axiom_soap_envelope *AXIS2_CALL
    axis2_msg_ctx_get_response_soap_envelope(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Gets fault SOAP envelope.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return pointer to fault SOAP envelope stored within message context
     */
    AXIS2_EXTERN struct axiom_soap_envelope *AXIS2_CALL
    axis2_msg_ctx_get_fault_soap_envelope(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Sets message ID.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param msg_id
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_msg_id(
        const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        axis2_char_t *msg_id);

    /**
     * Gets message ID.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return message ID string corresponding to the message the message 
     * context is related to
     */
    AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
    axis2_msg_ctx_get_msg_id(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Gets process fault status.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return AXIS2_TRUE if process fault is on, else AXIS2_FALSE
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_msg_ctx_get_process_fault(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Gets relates to information for the message context.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return pointer to relates to struct 
     */
    AXIS2_EXTERN axis2_relates_to_t *AXIS2_CALL
    axis2_msg_ctx_get_relates_to(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Gets WS-Addressing reply to endpoint. Reply to address tells where 
     * the the response should be sent to.         
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return pointer to endpoint reference struct representing the reply 
     * to address, returns a reference not a cloned copy
     */
    AXIS2_EXTERN axis2_endpoint_ref_t *AXIS2_CALL
    axis2_msg_ctx_get_reply_to(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Checks if it is on the server side that the message is being dealt 
     * with, or on the client side.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return AXIS2_TRUE if it is server side, AXIS2_FALSE if it is client
     * side
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_msg_ctx_get_server_side(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Gets WS-Addressing to endpoint. To address tells where message should 
     * be sent to.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return pointer to endpoint reference struct representing the 
     * to address, returns a reference not a cloned copy
     */
    AXIS2_EXTERN axis2_endpoint_ref_t *AXIS2_CALL
    axis2_msg_ctx_get_to(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Sets WS-Addressing fault to endpoint. Fault to address tells where 
     * the fault message should be sent when there is an error.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param reference pointer to endpoint reference representing fault to 
     * address. message context assumes the ownership of endpoint struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_fault_to(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        axis2_endpoint_ref_t *reference);

    /**
     * Sets WS-Addressing from endpoint. From address tells where 
     * the message came from.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param reference pointer to endpoint reference representing from 
     * address. message context assumes the ownership of endpoint struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_from(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        axis2_endpoint_ref_t *reference);

    /**
     * Sets in fault flow status. 
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param in_fault_flow AXIS2_TRUE if there is a fault on in path, 
     * else AXIS2_FALSE
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_in_fault_flow(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        const axis2_bool_t in_fault_flow);

    /**
     * Sets SOAP envelope. The fact that if it is the request SOAP envelope
     * or that of response depends on the current status represented by 
     * message context.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param soap_envelope pointer to SOAP envelope, message context
     * assumes ownership of SOAP envelope
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_soap_envelope(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        struct axiom_soap_envelope *soap_envelope);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_response_soap_envelope(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        struct axiom_soap_envelope *soap_envelope);


    /**
     * Sets fault SOAP envelope.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param soap_envelope pointer to SOAP envelope, message context
     * assumes ownership of SOAP envelope
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_fault_soap_envelope(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        struct axiom_soap_envelope *soap_envelope);

    /**
     * Sets message ID.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param message_id message ID string
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_message_id(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        const axis2_char_t *message_id);

    /**
     * Sets process fault bool value.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param process_fault AXIS2_TRUE if SOAP faults are to be processed,
     * else AXIS2_FALSE
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_process_fault(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        const axis2_bool_t process_fault);

    /**
     * Sets relates to struct.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param reference pointer to relates to struct, message context 
     * assumes ownership of the struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_relates_to(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        axis2_relates_to_t *reference);

    /**
     * Sets WS-Addressing reply to address indicating the location to which
     * the reply would be sent.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param reference pointer to endpoint reference representing reply to 
     * address         
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_reply_to(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        axis2_endpoint_ref_t *referance);

    /**
     * Sets the bool value indicating if it is the server side or the
     * client side.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param server_side AXIS2_TRUE if it is server side, AXIS2_FALSE if it
     * is client side
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_server_side(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        const axis2_bool_t server_side);

    /**
     * Sets WS-Addressing to address.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param reference pointer to endpoint reference struct representing
     * the address where the request should be sent to. message context
     * assumes ownership of endpoint struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_to(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        axis2_endpoint_ref_t *referance);

    /**
     * Gets the bool value indicating if it is required to have a new thread
     * for the invocation, or if the same thread of execution could be used.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return AXIS2_TRUE if new thread is required, else AXIS2_FALSE
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_msg_ctx_get_new_thread_required(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Sets the bool value indicating if it is required to have a new thread
     * for the invocation, or if the same thread of execution could be used.         
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param new_thread_required AXIS2_TRUE if a new thread is required, 
     * else AXIS2_FALSE
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_new_thread_required(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        const axis2_bool_t new_thread_required);

    /**
     * Sets WS-Addressing action. 
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param action_uri WSA action URI string
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_wsa_action(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        const axis2_char_t *action_uri);

    /**
     * Gets WS-Addressing action.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return pointer to WSA action URI string
     */
    AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
    axis2_msg_ctx_get_wsa_action(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Sets WS-Addressing message ID.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param message_id pointer to message ID string
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_wsa_message_id(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        const axis2_char_t *message_id);

    /**
     * Gets WS-Addressing message ID. 
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return WSA message ID string
     */
    AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
    axis2_msg_ctx_get_wsa_message_id(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Gets WS-Addressing message information headers.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return pointer to message information headers struct with 
     * WS-Addressing information. Returns a reference, not a cloned copy
     */
    AXIS2_EXTERN axis2_msg_info_headers_t *AXIS2_CALL
    axis2_msg_ctx_get_msg_info_headers(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Gets the bool value indicating the paused status. It is possible 
     * to pause the engine invocation by any handler. By calling this method
     * one can find out if some handler has paused the invocation.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return AXIS2_TRUE if message context is paused, else AXIS2_FALSE
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_msg_ctx_get_paused(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Sets the bool value indicating the paused status of invocation.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param paused paused
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_paused(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        const axis2_bool_t paused);

    /**
     * Gets the bool value indicating the keep value status. It is possible 
     * to keep alive the message context by any handler. By calling this method
     * one can see whether it is possible to clean the message context.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return AXIS2_TRUE if message context is keep alive, else AXIS2_FALSE
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_msg_ctx_is_keep_alive(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Sets the bool value indicating the keep alive status of invocation.
     * By setting this one can indicate the engine not to clean the message 
     * context.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param keep_alive keep alive
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_keep_alive(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        const axis2_bool_t keep_alive);


    /**
     * Gets transport in description.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return pointer to transport in description struct, returns a 
     * reference not a cloned copy
     */
    AXIS2_EXTERN struct axis2_transport_in_desc *AXIS2_CALL
    axis2_msg_ctx_get_transport_in_desc(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Gets transport out description.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return pointer to transport out description struct, returns a 
     * reference not a cloned copy
     */
    AXIS2_EXTERN struct axis2_transport_out_desc *AXIS2_CALL
    axis2_msg_ctx_get_transport_out_desc(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Sets transport in description.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param transport_in_desc pointer to transport in description struct,
     * message context does not assume the ownership of the struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_transport_in_desc(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        struct axis2_transport_in_desc *transport_in_desc);

    /**
     * Sets transport out description.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param transport_out_desc pointer to transport out description,
     * message context does not assume the ownership of the struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_transport_out_desc(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        struct axis2_transport_out_desc *transport_out_desc);

    /**
     * Gets operation context related to the operation that this message
     * context is related to.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return pointer to operation context struct
     */
    AXIS2_EXTERN struct axis2_op_ctx *AXIS2_CALL
    axis2_msg_ctx_get_op_ctx(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Sets operation context related to the operation that this message
     * context is related to.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param op_ctx pointer to operation context, message context does not 
     * assume the ownership of operation context
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_op_ctx(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        struct axis2_op_ctx *op_ctx);

    /**
     * Gets the bool value indicating the output written status. 
     * @param msg_ctx message context
     * @param env pointer to environment struct 
     * @return AXIS2_TRUE if output is written, else AXIS2_FALSE
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_msg_ctx_get_output_written(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Sets the bool value indicating the output written status. 
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param output_written AXIS2_TRUE if output is written, else AXIS2_FALSE
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_output_written(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        const axis2_bool_t output_written);

    /**
     * Gets the ID of service context that relates to the service that is 
     * related to the message context.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return service context ID string
     */
    AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
    axis2_msg_ctx_get_svc_ctx_id(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Sets the ID of service context that relates to the service that is 
     * related to the message context.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param svc_ctx_id The service context ID string
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_svc_ctx_id(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        const axis2_char_t *svc_ctx_id);

    /**
     * Gets configuration context.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return pointer to configuration context
     */
    AXIS2_EXTERN struct axis2_conf_ctx *AXIS2_CALL
    axis2_msg_ctx_get_conf_ctx(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Gets service context that relates to the service that the message 
     * context is related to.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return pointer to message context struct
     */
    AXIS2_EXTERN struct axis2_svc_ctx *AXIS2_CALL
    axis2_msg_ctx_get_svc_ctx(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Sets configuration context.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param conf_ctx pointer to configuration context struct, message 
     * context does not assume the ownership of struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_conf_ctx(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        struct axis2_conf_ctx *conf_ctx);
 
    /**
     * Sets service context.                     
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param svc_ctx pointer to service context struct,  message 
     * context does not assume the ownership of struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_svc_ctx(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        struct axis2_svc_ctx *svc_ctx);

    /**
     * Sets message information headers.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param msg_info_headers pointer to message information headers,
     * message context assumes the ownership of the struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_msg_info_headers(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        axis2_msg_info_headers_t *msg_info_headers);

    /**
     * Gets configuration descriptor parameter with given key. This method 
     * recursively search the related description hierarchy for the parameter 
     * with given key until it is found or the parent of the description 
     * hierarchy is reached. The order of search is as follows:
     * 1. search in operation description, if its there return
     * 2. if the parameter is not found in operation or operation is NULL, 
     * search in service
     * 3. if the parameter is not found in service or service is NULL search 
     * in configuration
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param key parameter key  
     * @return pointer to parameter struct corresponding to the given key
     */
    AXIS2_EXTERN axutil_param_t *AXIS2_CALL
    axis2_msg_ctx_get_parameter(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        const axis2_char_t *key);

    /**
     * Gets parameters related to a named module and a given handler 
     * description. The order of searching for parameter is as follows:
     * 1. search in module configuration stored inside corresponding operation 
     * description if its there
     * 2. search in corresponding operation if its there
     * 3. search in module configurations stored inside corresponding 
     * service description if its there
     * 4. search in corresponding service description if its there
     * 5. search in module configurations stored inside configuration
     * 6. search in configuration for parameters
     * 7. get the corresponding module and search for the parameters
     * 8. search in handler description for the parameter
     * @param msg_ctx pointer to message context
     * @param env pointer to environment struct
     * @param key parameter key
     * @param module_name name of the module
     * @param handler_desc pointer to handler description
     * @return pointer to parameter 
     */
    AXIS2_EXTERN axutil_param_t *AXIS2_CALL
    axis2_msg_ctx_get_module_parameter(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        const axis2_char_t *key,
        const axis2_char_t *module_name,
        axis2_handler_desc_t *handler_desc);

    /**
     * Gets property corresponding to the given key.
     * @param msg_ctx pointer to message context
     * @param env pointer to environment struct
     * @param key key string with which the property is stored
     * @param persistent AXIS2_TRUE if the property is to be retrieved from
     * persistent map, AXIS2_FALSE if the property is to be retrieved from
     * non-persistent map
     * @return pointer to property struct
     */
    AXIS2_EXTERN axutil_property_t *AXIS2_CALL
    axis2_msg_ctx_get_property(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        const axis2_char_t *key);

    /**
     * Sets property with given key.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param key key string
     * @param value property to be stored
     * @param persistent AXIS2_TRUE if the property is to be stored in
     * persistent map, AXIS2_FALSE if the property is to be stored in 
     * non-persistent map
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_property(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        const axis2_char_t *key,
        axutil_property_t *value);
    /**
     * Gets the QName of the handler at which invocation was paused.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return pointer to QName of the paused handler
     */
    AXIS2_EXTERN const axutil_string_t *AXIS2_CALL
    axis2_msg_ctx_get_paused_handler_name(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Gets the name of the phase at which the invocation was paused.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return name string of the paused phase.
     */
    AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
    axis2_msg_ctx_get_paused_phase_name(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Sets the name of the phase at which the invocation was paused.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param paused_phase_name paused phase name string
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_paused_phase_name(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        const axis2_char_t *paused_phase_name);

    /**
     * Gets SOAP action.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return SOAP action string
     */
    AXIS2_EXTERN axutil_string_t *AXIS2_CALL
      axis2_msg_ctx_get_soap_action(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Sets SOAP action.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param soap_action SOAP action string
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_soap_action(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        axutil_string_t *soap_action);

    /**
     * Gets the boolean value indicating if MTOM is enabled or not.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return AXIS2_TRUE if MTOM is enabled, else AXIS2_FALSE
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_msg_ctx_get_doing_mtom(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Sets the boolean value indicating if MTOM is enabled or not.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param doing_mtom AXIS2_TRUE if MTOM is enabled, else AXIS2_FALSE
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_doing_mtom(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        const axis2_bool_t doing_mtom);

    /**
     * Gets the boolean value indicating if REST is enabled or not.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return AXIS2_TRUE if REST is enabled, else AXIS2_FALSE
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_msg_ctx_get_doing_rest(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Sets the boolean value indicating if REST is enabled or not.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param doing_rest AXIS2_TRUE if REST is enabled, else AXIS2_FALSE
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_doing_rest(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        const axis2_bool_t doing_rest);

    /**
     * Sets the boolean value indicating if REST should be done through 
     * HTTP POST or HTTP GET.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param do_rest_through_post AXIS2_TRUE if REST is to be done with 
     * HTTP POST, else AXIS2_FALSE if REST is to be done with HTTP GET
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_do_rest_through_post(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        const axis2_bool_t do_rest_through_post);


    /**
     * Sets the boolean value indicating if REST should be done through 
     * HTTP POST or HTTP GET.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return AXIS2_TRUE if REST is to be done with HTTP POST, else 
     * AXIS2_FALSE if REST is to be done with HTTP GET
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_msg_ctx_get_do_rest_through_post(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Gets the bool value indicating the SOAP version being used either
     * SOAP 1.1 or SOAP 1.2
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return AXIS2_TRUE if SOAP 1.1 is being used, else AXIS2_FALSE if 
     * SOAP 1.2 is being used
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_msg_ctx_get_is_soap_11(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Sets the bool value indicating the SOAP version being used either
     * SOAP 1.1 or SOAP 1.2
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param is_soap11 AXIS2_TRUE if SOAP 1.1 is being used, else 
     * AXIS2_FALSE if SOAP 1.2 is being used
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_is_soap_11(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        const axis2_bool_t is_soap11);

    /**
     * Gets service group context. The returned service group context 
     * relates to the service group to which the service, related to the 
     * message context, belongs.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return pointer to service group struct
     */
    AXIS2_EXTERN struct axis2_svc_grp_ctx *AXIS2_CALL
    axis2_msg_ctx_get_svc_grp_ctx(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Gets service group context. The returned service group context 
     * relates to the service group to which the service, related to the 
     * message context, belongs.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param svc_grp_ctx pointer to service group context
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_svc_grp_ctx(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        struct axis2_svc_grp_ctx *svc_grp_ctx);


    /**
     * Gets the operation that is to be invoked.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return pointer to operation, returns a reference not a cloned copy
     */
    AXIS2_EXTERN struct axis2_op *AXIS2_CALL
    axis2_msg_ctx_get_op(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);


    /**
     * Sets the operation that is to be invoked.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param op pointer to operation, message context does not assume the 
     * ownership of operation
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_op(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        struct axis2_op *op);


    /**
     * Gets the service to which the operation to be invoked belongs.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return pointer to service struct, returns a reference not a cloned copy
     */
    AXIS2_EXTERN struct axis2_svc *AXIS2_CALL
    axis2_msg_ctx_get_svc(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);


    /**
     * Sets the service to which the operation to be invoked belongs.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param svc pointer to service struct, message context does not assume
     * the ownership of struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_svc(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        struct axis2_svc *svc);

    /**
     * Gets the service group to which the service to be invoked belongs.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return pointer to service group struct, returns a reference not 
     * a cloned copy
     */
    AXIS2_EXTERN struct axis2_svc_grp *AXIS2_CALL
     axis2_msg_ctx_get_svc_grp(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Sets the service group to which the service to be invoked belongs.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param svc_grp pointer to service group struct, message context does 
     * not assume the ownership of the struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_svc_grp(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        struct axis2_svc_grp *svc_grp);


    /**
     * Gets the service group context ID.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return service group context ID string
     */
    AXIS2_EXTERN const axutil_string_t *AXIS2_CALL
    axis2_msg_ctx_get_svc_grp_ctx_id(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Sets the service group context ID.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param svc_grp_ctx_id service group context ID string 
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_svc_grp_ctx_id(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        axutil_string_t *svc_grp_ctx_id);

    /**
     * Finds the service to be invoked. This function is used by dispatchers 
     * to locate the service to be invoked.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return pointer to service to be invoked
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_find_svc(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        void* func);
    /**
     * Finds the operation to be invoked in the given service. This function 
     * is used by dispatchers to locate the operation to be invoked.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param svc pointer to service to whom the operation belongs 
     * @return pointer to the operation to be invoked
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_find_op(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        void *func);
    /**
     * Finds the service to be invoked. This function is used by dispatchers 
     * to locate the service to be invoked.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return pointer to service to be invoked
     */
    AXIS2_EXTERN struct axis2_svc * AXIS2_CALL
    axis2_msg_ctx_find_svc(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);
    /**
     * Finds the operation to be invoked in the given service. This function 
     * is used by dispatchers to locate the operation to be invoked.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param svc pointer to service to whom the operation belongs 
     * @return pointer to the operation to be invoked
     */
    AXIS2_EXTERN struct axis2_op * AXIS2_CALL
    axis2_msg_ctx_find_op(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        struct axis2_svc *svc);
   /**
     * Gets the options to be used in invocation.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return  options pointer to options struct , message context does not 
     * assume the ownership of the struct
     */
    AXIS2_EXTERN struct axis2_options *AXIS2_CALL
        axis2_msg_ctx_get_options(
            axis2_msg_ctx_t *msg_ctx,
            const axutil_env_t *env);

    /**
     * Gets the bool value indicating the paused status.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return AXIS2_TRUE if invocation is paused, else AXIS2_FALSE
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_msg_ctx_is_paused(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);
        
    /**
     * Sets the options to be used in invocation.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param options pointer to options struct , message context does not 
     * assume the ownership of the struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_options (axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        struct axis2_options *options);
    
    /**
     * Sets the flow to be invoked.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param flow int value indicating the flow
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_flow (axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        int flow);

    /**
     * Gets the flow to be invoked.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return int value indicating the flow
     */
    AXIS2_EXTERN int AXIS2_CALL
    axis2_msg_ctx_get_flow (const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Sets the execution chain to be invoked. The execution chain is a 
     * list of phases containing the handlers to be invoked.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param execution_chain pointer array list containing the list of 
     * handlers that constitute the execution chain. message context does
     * not assume the ownership of the array list
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_execution_chain(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        axutil_array_list_t *execution_chain);

    /**
     * Gets the execution chain to be invoked. The execution chain is a 
     * list of phases containing the handlers to be invoked.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return pointer array list containing the list of handlers that 
     * constitute the execution chain. message context does not assume 
     * the ownership of the array list
     */
    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    axis2_msg_ctx_get_execution_chain(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Sets current handler index, indicating which handler is currently 
     * being invoked in the execution chain
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param index index of currently executed handler
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_current_handler_index(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        const int index);

    /**
     * Gets current handler index, indicating which handler is currently 
     * being invoked in the execution chain         
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return index of currently executed handler
     */
    AXIS2_EXTERN int AXIS2_CALL
    axis2_msg_ctx_get_current_handler_index(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

   /**
    * Gets paused handler index, indicating at which handler the execution 
    * chain was paused.
    * @param msg_ctx message context
    * @param env pointer to environment struct
    * @return index of handler at which invocation was paused
    */
    AXIS2_EXTERN int AXIS2_CALL
    axis2_msg_ctx_get_paused_handler_index(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);


    /**
     * Sets index of the current phase being invoked.        
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param index index of current phase
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_current_phase_index(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        const int index);

    /**
     * Gets index of the current phase being invoked.        
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return index of current phase
     */
    AXIS2_EXTERN int AXIS2_CALL
    axis2_msg_ctx_get_current_phase_index(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Gets the phase at which the invocation was paused.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return index of paused phase
     */
    AXIS2_EXTERN int AXIS2_CALL
    axis2_msg_ctx_get_paused_phase_index(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Gets character set encoding to be used.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axutil_string_t* AXIS2_CALL
    axis2_msg_ctx_get_charset_encoding(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    /**
     * Sets character set encoding to be used.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param str pointer to string struct representing encoding
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_charset_encoding(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        axutil_string_t *str);

    AXIS2_EXTERN axutil_stream_t *AXIS2_CALL
    axis2_msg_ctx_get_transport_out_stream(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_transport_out_stream(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        axutil_stream_t *stream);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_reset_transport_out_stream(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    AXIS2_EXTERN struct axis2_http_out_transport_info *AXIS2_CALL
    axis2_msg_ctx_get_http_out_transport_info(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_http_out_transport_info(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        struct axis2_http_out_transport_info *http_out_transport_info);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_reset_http_out_transport_info(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
    axis2_msg_ctx_get_transport_headers(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_transport_headers(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        axutil_hash_t *transport_headers);

    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    axis2_msg_ctx_get_transfer_encoding(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_transfer_encoding(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        axis2_char_t *str);

    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    axis2_msg_ctx_get_transport_url(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_msg_ctx_set_transport_url(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env,
        axis2_char_t *str);

#ifdef __cplusplus
}
#endif

#endif                          /* AXIS2_MSG_CTX_H */
