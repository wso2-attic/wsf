/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <sandesha2_rm_elements.h>
#include <sandesha2_constants.h>
#include <axutil_hash.h>
#include <axiom_soap_const.h>
#include <sandesha2_iom_rm_part.h>
#include <sandesha2_utils.h>
#include <axiom_soap_header.h>
#include <axiom_soap_body.h>
#include <stdio.h>
#include <axis2_addr.h>


/** 
 * @brief RM Elements struct impl
 *	Sandesha2 RM Elements
 */
  
struct sandesha2_rm_elements_t
{
    sandesha2_seq_t *seq;
    sandesha2_seq_ack_t *seq_ack;
    sandesha2_create_seq_t *create_seq;
    sandesha2_create_seq_res_t *create_seq_res;
    sandesha2_terminate_seq_t *terminate_seq;
    sandesha2_terminate_seq_res_t *terminate_seq_res;
    sandesha2_close_seq_t *close_seq;
    sandesha2_close_seq_res_t *close_seq_res;
    sandesha2_ack_requested_t *ack_requested;
    axis2_char_t *rm_ns_val;
    axis2_char_t *addr_ns_val;
    sandesha2_make_connection_t *make_connection;
    sandesha2_msg_pending_t *msg_pending;
};

AXIS2_EXTERN sandesha2_rm_elements_t* AXIS2_CALL
sandesha2_rm_elements_create(
    const axutil_env_t *env,
    axis2_char_t *addr_ns_val)
{
    sandesha2_rm_elements_t *rm_elements = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    
    rm_elements =  (sandesha2_rm_elements_t *)AXIS2_MALLOC 
        (env->allocator, sizeof(sandesha2_rm_elements_t));
    if(!rm_elements)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    rm_elements->seq = NULL;
    rm_elements->seq_ack = NULL;
    rm_elements->create_seq = NULL;
    rm_elements->create_seq_res = NULL;
    rm_elements->terminate_seq = NULL;
    rm_elements->terminate_seq_res = NULL;
    rm_elements->close_seq = NULL;
    rm_elements->close_seq_res = NULL;
    rm_elements->ack_requested = NULL;
    rm_elements->rm_ns_val = NULL;
    rm_elements->addr_ns_val = NULL;
    rm_elements->make_connection = NULL;
    rm_elements->msg_pending = NULL;
    
    rm_elements->addr_ns_val = axutil_strdup(env, addr_ns_val);
    
	return rm_elements;
}

axis2_status_t AXIS2_CALL 
sandesha2_rm_elements_free(
    sandesha2_rm_elements_t *rm_elements, 
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    if(rm_elements->addr_ns_val)
    {
        AXIS2_FREE(env->allocator, rm_elements->addr_ns_val);
        rm_elements->addr_ns_val = NULL;
    }
	AXIS2_FREE(env->allocator, rm_elements);
	return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL 
sandesha2_rm_elements_from_soap_envelope(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env,
    axiom_soap_envelope_t *soap_envelope,
    axis2_char_t *action)
{
    int soap_version = -1;
    axiom_soap_header_t *soap_header = NULL;
    axiom_soap_body_t *soap_body = NULL;
    axiom_node_t *header_node = NULL;
    axiom_element_t *body_element = NULL;
    axiom_node_t *body_node = NULL;
    axiom_element_t *header_element = NULL;
    axiom_element_t *seq_element = NULL;
    axiom_node_t *seq_node = NULL;
    axiom_element_t *seq_ack_element = NULL;
    axiom_node_t *seq_ack_node = NULL;
    axiom_element_t *create_seq_element = NULL;
    axiom_node_t *create_seq_node = NULL;
    axiom_element_t *create_seq_res_element = NULL;
    axiom_node_t *create_seq_res_node = NULL;
    axiom_element_t *terminate_seq_element = NULL;
    axiom_node_t *terminate_seq_node = NULL;
    axiom_element_t *terminate_seq_res_element = NULL;
    axiom_node_t *terminate_seq_res_node = NULL;
    axiom_element_t *close_seq_element = NULL;
    axiom_node_t *close_seq_node = NULL;
    axiom_element_t *close_seq_res_element = NULL;
    axiom_node_t *close_seq_res_node = NULL;
    axiom_element_t *ack_requested_element = NULL;
    axiom_node_t *ack_requested_node = NULL;
    axiom_element_t *make_conn_element = NULL;
    axiom_node_t *make_conn_node = NULL;
    axiom_element_t *msg_pending_element = NULL;
    axiom_node_t *msg_pending_node = NULL;
    axutil_qname_t *qname = NULL;
    axis2_char_t *rm_ns_val = NULL;
    axis2_char_t *addr_ns_val = NULL;
    
    
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, soap_envelope, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, action, AXIS2_FAILURE);
    
    soap_version = axiom_soap_envelope_get_soap_version(soap_envelope, env);
    
    rm_elements->rm_ns_val = sandesha2_rm_elements_get_rm_ns_val(rm_elements,
                        env, soap_envelope, action);
                        
    if(!rm_elements->rm_ns_val)
        return AXIS2_SUCCESS;
        
    rm_elements->addr_ns_val =  
            sandesha2_rm_elements_get_addr_ns_val_from_env(
                        rm_elements, env, soap_envelope, action);
    if(!rm_elements->addr_ns_val)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[sandesha2] Cannot find the"
                        " addressing version");
        return AXIS2_FAILURE;
    }
    soap_header = axiom_soap_envelope_get_header(soap_envelope, env);    
    header_node = axiom_soap_header_get_base_node(soap_header, env);
    header_element = axiom_node_get_data_element(header_node, env);
    
    soap_body = axiom_soap_envelope_get_body(soap_envelope, env);
    body_node = axiom_soap_body_get_base_node(soap_body, env);
    body_element = axiom_node_get_data_element(body_node, env);
                        
    rm_ns_val = rm_elements->rm_ns_val;
    addr_ns_val = rm_elements->addr_ns_val;
    
    qname = axutil_qname_create(env, SANDESHA2_WSRM_COMMON_SEQ, rm_ns_val, NULL);
    seq_element = axiom_element_get_first_child_with_qname(header_element, env,
                        qname, header_node, &seq_node);
    if(seq_node)
    {
        rm_elements->seq = sandesha2_seq_create(env, rm_ns_val);
        sandesha2_iom_rm_element_from_om_node((sandesha2_iom_rm_element_t *)
            rm_elements->seq, env, seq_node);
    }
    qname = axutil_qname_create(env, SANDESHA2_WSRM_COMMON_SEQ_ACK, rm_ns_val, 
                        NULL);
    seq_ack_element = axiom_element_get_first_child_with_qname(header_element,
                        env, qname, header_node, &seq_ack_node);
    if(seq_ack_element)
    {
        rm_elements->seq_ack = sandesha2_seq_ack_create(env, rm_ns_val);
        sandesha2_iom_rm_element_from_om_node((sandesha2_iom_rm_element_t *)
            rm_elements->seq_ack, env, seq_ack_node);
    }
    qname = axutil_qname_create(env, SANDESHA2_WSRM_COMMON_CREATE_SEQ, rm_ns_val,
                        NULL);
    create_seq_element = axiom_element_get_first_child_with_qname(body_element,
                        env, qname, body_node, &create_seq_node);
    if(create_seq_node)
    {
        rm_elements->create_seq = sandesha2_create_seq_create(env,
                        addr_ns_val, rm_ns_val);
        sandesha2_iom_rm_element_from_om_node((sandesha2_iom_rm_element_t *)
            rm_elements->create_seq, env, create_seq_node);
    }
    
    qname = axutil_qname_create(env, SANDESHA2_WSRM_COMMON_CREATE_SEQ_RESPONSE, 
                        rm_ns_val, NULL);
    create_seq_res_element = axiom_element_get_first_child_with_qname(
        body_element, env, qname, body_node, &create_seq_res_node);
    if(create_seq_res_node)
    {
        rm_elements->create_seq_res = sandesha2_create_seq_res_create(env, 
                        rm_ns_val, addr_ns_val);
        sandesha2_iom_rm_element_from_om_node((sandesha2_iom_rm_element_t *)
            rm_elements->create_seq_res, env, create_seq_res_node);
    }
    
    qname = axutil_qname_create(env, SANDESHA2_WSRM_COMMON_TERMINATE_SEQ, 
                        rm_ns_val, NULL);
    terminate_seq_element = axiom_element_get_first_child_with_qname(
        body_element, env, qname, body_node, &terminate_seq_node);
    if(terminate_seq_node)
    {
        rm_elements->terminate_seq = sandesha2_terminate_seq_create(env, 
            rm_ns_val);
        sandesha2_iom_rm_element_from_om_node((sandesha2_iom_rm_element_t *)
            rm_elements->terminate_seq, env, terminate_seq_node);
    }
    
    qname = axutil_qname_create(env, SANDESHA2_WSRM_COMMON_TERMINATE_SEQ_RESPONSE, 
        rm_ns_val, NULL);
    terminate_seq_res_element = axiom_element_get_first_child_with_qname(
        body_element, env, qname, body_node, &terminate_seq_res_node);
    if(terminate_seq_res_node)
    {
        rm_elements->terminate_seq_res = sandesha2_terminate_seq_res_create(
            env, rm_ns_val);
        sandesha2_iom_rm_element_from_om_node((sandesha2_iom_rm_element_t *)
            rm_elements->terminate_seq_res, env, terminate_seq_res_node);
    }
    
    qname = axutil_qname_create(env, SANDESHA2_WSRM_COMMON_CLOSE_SEQ, rm_ns_val, 
        NULL);
    close_seq_element = axiom_element_get_first_child_with_qname(body_element, 
        env, qname, body_node, &close_seq_node);
    if(close_seq_node)
    {
        rm_elements->close_seq = sandesha2_close_seq_create(env, rm_ns_val);
        sandesha2_iom_rm_element_from_om_node((sandesha2_iom_rm_element_t *)
            rm_elements->close_seq, env, close_seq_node);
    }
    
    qname = axutil_qname_create(env, SANDESHA2_WSRM_COMMON_CLOSE_SEQ_RESPONSE, 
                        rm_ns_val, NULL);
    close_seq_res_element = axiom_element_get_first_child_with_qname(
        body_element, env, qname, body_node, &close_seq_res_node);
    if(close_seq_res_node)
    {
        rm_elements->close_seq_res = sandesha2_close_seq_res_create(env, 
            rm_ns_val);
        sandesha2_iom_rm_element_from_om_node((sandesha2_iom_rm_element_t *)
            rm_elements->close_seq_res, env, close_seq_res_node);
    }
    qname = axutil_qname_create(env, SANDESHA2_WSRM_COMMON_MAKE_CONNECTION, 
        rm_ns_val, NULL);
    make_conn_element = axiom_element_get_first_child_with_qname(body_element, 
        env, qname, body_node, &make_conn_node);
    if(make_conn_node)
    {
        rm_elements->make_connection = sandesha2_make_connection_create(env, 
            rm_ns_val);
        sandesha2_iom_rm_element_from_om_node((sandesha2_iom_rm_element_t *)
            rm_elements->make_connection, env, make_conn_node);
    }
    qname = axutil_qname_create(env, SANDESHA2_WSRM_COMMON_ACK_REQUESTED, 
                        rm_ns_val, NULL);
    ack_requested_element = axiom_element_get_first_child_with_qname(
        header_element, env, qname, header_node, &ack_requested_node);
    if(ack_requested_node)
    {
        rm_elements->ack_requested = sandesha2_ack_requested_create(env, 
            rm_ns_val);
        sandesha2_iom_rm_element_from_om_node((sandesha2_iom_rm_element_t *)
            rm_elements->ack_requested, env, ack_requested_node);
    }
    qname = axutil_qname_create(env, SANDESHA2_WSRM_COMMON_MESSAGE_PENDING, 
        rm_ns_val, NULL);
    msg_pending_element = axiom_element_get_first_child_with_qname(
        header_element, env, qname, header_node, &msg_pending_node);
    if(msg_pending_node)
    {
        rm_elements->msg_pending = sandesha2_msg_pending_create(env, 
                        rm_ns_val);
        sandesha2_iom_rm_element_from_om_node((sandesha2_iom_rm_element_t *)
            rm_elements->msg_pending, env, msg_pending_node);
    }
    return AXIS2_SUCCESS;
}
            
axiom_soap_envelope_t* AXIS2_CALL 
sandesha2_rm_elements_to_soap_envelope(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env,
    axiom_soap_envelope_t *soap_envelope)
{
    axiom_soap_header_t *soap_header = NULL;
    axiom_soap_body_t *soap_body = NULL;
    axiom_node_t *body_node = NULL;
    
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, soap_envelope, NULL);
    
    soap_header = axiom_soap_envelope_get_header(soap_envelope, env);
    soap_body = axiom_soap_envelope_get_body(soap_envelope, env);
    body_node = axiom_soap_body_get_base_node(soap_body, env);
    
    if(rm_elements->seq)
    {
        sandesha2_iom_rm_element_to_om_node((sandesha2_iom_rm_element_t *)
            rm_elements->seq, env, soap_header);
    }
    if(rm_elements->seq_ack)
    {
        sandesha2_iom_rm_element_to_om_node((sandesha2_iom_rm_element_t *)
            rm_elements->seq_ack, env, soap_header);
    }
    if(rm_elements->msg_pending)
    {
        sandesha2_iom_rm_element_to_om_node((sandesha2_iom_rm_element_t *)
            rm_elements->msg_pending, env, soap_header);
    }
    if(rm_elements->create_seq)
    {
        sandesha2_iom_rm_element_to_om_node((sandesha2_iom_rm_element_t *)
            rm_elements->create_seq, env, body_node);
    }
    if(rm_elements->create_seq_res)
    {
        sandesha2_iom_rm_element_to_om_node((sandesha2_iom_rm_element_t *)
            rm_elements->create_seq_res, env, body_node);
    }
    if(rm_elements->terminate_seq)
    {
        sandesha2_iom_rm_element_to_om_node((sandesha2_iom_rm_element_t *)
            rm_elements->terminate_seq, env, body_node);
    }
    if(rm_elements->terminate_seq_res)
    {
        sandesha2_iom_rm_element_to_om_node((sandesha2_iom_rm_element_t *)
            rm_elements->terminate_seq_res, env, body_node);
    }
    if(rm_elements->close_seq)
    {
        sandesha2_iom_rm_element_to_om_node((sandesha2_iom_rm_element_t *)
            rm_elements->close_seq, env, body_node);
    }
    if(rm_elements->close_seq_res)
    {
        sandesha2_iom_rm_element_to_om_node((sandesha2_iom_rm_element_t *)
            rm_elements->close_seq_res, env, body_node);
    }
    if(rm_elements->make_connection)
    {
        sandesha2_iom_rm_element_to_om_node((sandesha2_iom_rm_element_t *)
            rm_elements->make_connection, env, body_node);
    }
    return soap_envelope;
}
            
sandesha2_create_seq_t* AXIS2_CALL 
sandesha2_rm_elements_get_create_seq(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    
    return rm_elements->create_seq;
}
            
axis2_status_t AXIS2_CALL 
sandesha2_rm_elements_set_create_seq(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env,
    sandesha2_create_seq_t *create_seq)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, create_seq, AXIS2_FAILURE);
    rm_elements->create_seq = create_seq;
    return AXIS2_SUCCESS;
}
    
sandesha2_create_seq_res_t* AXIS2_CALL 
sandesha2_rm_elements_get_create_seq_res(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    
    return rm_elements->create_seq_res;
}
            
axis2_status_t AXIS2_CALL 
sandesha2_rm_elements_set_create_seq_res(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env,
    sandesha2_create_seq_res_t *create_seq_res)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, create_seq_res, AXIS2_FAILURE);
    rm_elements->create_seq_res = create_seq_res;
    return AXIS2_SUCCESS;
}
            
sandesha2_seq_t* AXIS2_CALL 
sandesha2_rm_elements_get_seq(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    
    return rm_elements->seq;
}
            
axis2_status_t AXIS2_CALL 
sandesha2_rm_elements_set_seq(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env,
    sandesha2_seq_t *seq)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, seq, AXIS2_FAILURE);
    rm_elements->seq = seq;
    return AXIS2_SUCCESS;
}
            
sandesha2_seq_ack_t* AXIS2_CALL 
sandesha2_rm_elements_get_seq_ack(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    
    return rm_elements->seq_ack;
}
            
axis2_status_t AXIS2_CALL 
sandesha2_rm_elements_set_seq_ack(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env,
    sandesha2_seq_ack_t *seq_ack)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, seq_ack, AXIS2_FAILURE);
    rm_elements->seq_ack = seq_ack;
    return AXIS2_SUCCESS;
}
            
sandesha2_terminate_seq_t* AXIS2_CALL 
sandesha2_rm_elements_get_terminate_seq(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    
    return rm_elements->terminate_seq;
}
            
axis2_status_t AXIS2_CALL 
sandesha2_rm_elements_set_terminate_seq(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env,
    sandesha2_terminate_seq_t *terminate_seq)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, terminate_seq, AXIS2_FAILURE);
    rm_elements->terminate_seq = terminate_seq;
    return AXIS2_SUCCESS;
}
            
sandesha2_terminate_seq_res_t* AXIS2_CALL 
sandesha2_rm_elements_get_terminate_seq_res(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    
    return rm_elements->terminate_seq_res;
}
            
axis2_status_t AXIS2_CALL 
sandesha2_rm_elements_set_terminate_seq_res(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env,
    sandesha2_terminate_seq_res_t *terminate_seq_res)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, terminate_seq_res, AXIS2_FAILURE);
    rm_elements->terminate_seq_res = terminate_seq_res;
    return AXIS2_SUCCESS;
}
            
sandesha2_ack_requested_t* AXIS2_CALL 
sandesha2_rm_elements_get_ack_requested(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    
    return rm_elements->ack_requested;
}
            
axis2_status_t AXIS2_CALL 
sandesha2_rm_elements_set_ack_requested(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env,
    sandesha2_ack_requested_t *ack_requested)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, ack_requested, AXIS2_FAILURE);
    rm_elements->ack_requested = ack_requested;
    return AXIS2_SUCCESS;
}
    
sandesha2_close_seq_t* AXIS2_CALL 
sandesha2_rm_elements_get_close_seq(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    
    return rm_elements->close_seq;
}
            
axis2_status_t AXIS2_CALL 
sandesha2_rm_elements_set_close_seq(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env,
    sandesha2_close_seq_t *close_seq)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, close_seq, AXIS2_FAILURE);
    rm_elements->close_seq = close_seq;
    return AXIS2_SUCCESS;
}
    
sandesha2_close_seq_res_t* AXIS2_CALL 
sandesha2_rm_elements_get_close_seq_res(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    
    return rm_elements->close_seq_res;
}
            
axis2_status_t AXIS2_CALL 
sandesha2_rm_elements_set_close_seq_res(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env,
    sandesha2_close_seq_res_t *close_seq_res)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, close_seq_res, AXIS2_FAILURE);
    rm_elements->close_seq_res = close_seq_res;
    return AXIS2_SUCCESS;
}
    
axis2_char_t* AXIS2_CALL 
sandesha2_rm_elements_get_addr_ns_val(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    
    return rm_elements->addr_ns_val;
}

sandesha2_make_connection_t* AXIS2_CALL 
sandesha2_rm_elements_get_make_connection(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    
    return rm_elements->make_connection;
}

sandesha2_msg_pending_t* AXIS2_CALL 
sandesha2_rm_elements_get_msg_pending(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    
    return rm_elements->msg_pending;
}

axis2_char_t* AXIS2_CALL 
sandesha2_rm_elements_get_rm_ns_val(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env,
    axiom_soap_envelope_t *soap_envelope,
    axis2_char_t *action)
{
    axiom_soap_header_t *soap_header = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, soap_envelope, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, action, AXIS2_FAILURE);
    
    soap_header = axiom_soap_envelope_get_header(soap_envelope, env);
    if(soap_header)
    {
        axutil_array_list_t *headers = NULL;
        
        headers = axiom_soap_header_get_header_blocks_with_namespace_uri(
            soap_header, env, SANDESHA2_SPEC_2005_02_NS_URI);
        if(headers && 0 < axutil_array_list_size(headers, env))
            return SANDESHA2_SPEC_2005_02_NS_URI;
        headers = axiom_soap_header_get_header_blocks_with_namespace_uri(
            soap_header, env, SANDESHA2_SPEC_2006_08_NS_URI);                
        if(headers && 0 < axutil_array_list_size(headers, env))
            return SANDESHA2_SPEC_2006_08_NS_URI;
    }
    if(!action)
        return NULL;
    
    if(0 == axutil_strcmp(action, SANDESHA2_SPEC_2005_02_ACTION_CREATE_SEQ))
        return SANDESHA2_SPEC_2005_02_NS_URI;
    if(0 == axutil_strcmp(action, SANDESHA2_SPEC_2005_02_ACTION_CREATE_SEQ_RESPONSE))
        return SANDESHA2_SPEC_2005_02_NS_URI;
    if(0 == axutil_strcmp(action, SANDESHA2_SPEC_2005_02_ACTION_SEQ_ACKNOWLEDGEMENT))
        return SANDESHA2_SPEC_2005_02_NS_URI;
    if(0 == axutil_strcmp(action, SANDESHA2_SPEC_2005_02_ACTION_TERMINATE_SEQ))
        return SANDESHA2_SPEC_2005_02_NS_URI;
        
    if(0 == axutil_strcmp(action, SANDESHA2_SPEC_2006_08_ACTION_CREATE_SEQ))
        return SANDESHA2_SPEC_2006_08_NS_URI;
    if(0 == axutil_strcmp(action, SANDESHA2_SPEC_2006_08_ACTION_CREATE_SEQ_RESPONSE))
        return SANDESHA2_SPEC_2006_08_NS_URI;
    if(0 == axutil_strcmp(action, SANDESHA2_SPEC_2006_08_ACTION_SEQ_ACKNOWLEDGEMENT))
        return SANDESHA2_SPEC_2006_08_NS_URI;
    if(0 == axutil_strcmp(action, SANDESHA2_SPEC_2006_08_ACTION_TERMINATE_SEQ))
        return SANDESHA2_SPEC_2006_08_NS_URI;
    if(0 == axutil_strcmp(action, SANDESHA2_SPEC_2006_08_ACTION_CLOSE_SEQ))
        return SANDESHA2_SPEC_2006_08_NS_URI;
    if(0 == axutil_strcmp(action, SANDESHA2_SPEC_2006_08_ACTION_TERMINATE_SEQ_RESPONSE))
        return SANDESHA2_SPEC_2006_08_NS_URI;
    if(0 == axutil_strcmp(action, SANDESHA2_SPEC_2006_08_ACTION_CLOSE_SEQ_RESPONSE))
        return SANDESHA2_SPEC_2006_08_NS_URI;
    if(0 == axutil_strcmp(action, SANDESHA2_SPEC_2006_08_ACTION_MAKE_CONNECTION))
        return SANDESHA2_SPEC_2006_08_NS_URI;
    
    return NULL;
    
}

axis2_char_t* AXIS2_CALL 
sandesha2_rm_elements_get_addr_ns_val_from_env(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env,
    axiom_soap_envelope_t *soap_envelope,
    axis2_char_t *action)
{
    axiom_soap_header_t *soap_header = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, soap_envelope, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, action, AXIS2_FAILURE);
    
    soap_header = axiom_soap_envelope_get_header(soap_envelope, env);
    if(soap_header)
    {
        axutil_array_list_t *headers = NULL;
        axiom_node_t *soap_header_node = NULL;
        axiom_element_t *soap_header_element = NULL;
        axiom_namespace_t *addr_ns = NULL;
 
        headers = axiom_soap_header_get_header_blocks_with_namespace_uri(
                        soap_header, env, AXIS2_WSA_NAMESPACE);
        if(headers && 0 < axutil_array_list_size(headers, env))
            return AXIS2_WSA_NAMESPACE;
            
        headers = axiom_soap_header_get_header_blocks_with_namespace_uri(
                        soap_header, env, AXIS2_WSA_NAMESPACE_SUBMISSION); 
        if(headers && 0 < axutil_array_list_size(headers, env))
            return AXIS2_WSA_NAMESPACE_SUBMISSION;

        soap_header_node = axiom_soap_header_get_base_node(soap_header, env);
        soap_header_element = axiom_node_get_data_element(soap_header_node, 
            env);
        addr_ns = axiom_element_get_namespace(soap_header_element, env, 
            soap_header_node);
        if(addr_ns)
        {
            axis2_char_t *str_addr_ns = axiom_namespace_get_uri(addr_ns, env);
            return str_addr_ns;
        }
    }
    return NULL;
}

