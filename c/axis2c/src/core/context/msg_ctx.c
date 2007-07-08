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

#include <axis2_msg_ctx.h>
#include <axis2_conf_ctx.h>
#include <axis2_op.h>
#include <axis2_svc.h>
#include <axis2_svc_grp.h>
#include <axis2_conf.h>
#include <axis2_transport_in_desc.h>
#include <axis2_transport_out_desc.h>
#include <axis2_http_out_transport_info.h>
#include <axiom_soap_envelope.h>
#include <axiom_soap_const.h>
#include <axis2_options.h>

struct axis2_msg_ctx
{
    /** base context struct */
    axis2_ctx_t *base;
    /** parent of message context is an op context instance */
    struct axis2_op_ctx *parent;
    /** process fault enabled? */
    axis2_bool_t process_fault;
    /**
     * Addressing Information for Axis 2
     * Following Properties will be kept inside this, these fields will be initially filled by
     * the transport. Then later an addressing handler will make relevant changes to this, if addressing
     * information is present in the SOAP header.
     */
    axis2_msg_info_headers_t *msg_info_headers;
    axis2_bool_t msg_info_headers_deep_copy;

    struct axis2_op_ctx *op_ctx;
    struct axis2_svc_ctx *svc_ctx;
    struct axis2_svc_grp_ctx *svc_grp_ctx;
    struct axis2_conf_ctx *conf_ctx;

    /** op */
    axis2_op_t *op;
    /** service */
    axis2_svc_t *svc;
    /** service group */
    axis2_svc_grp_t *svc_grp;

    axis2_transport_in_desc_t *transport_in_desc;
    axis2_transport_out_desc_t *transport_out_desc;

    /** SOAP envelope */
    axiom_soap_envelope_t *soap_envelope;
    /** Response SOAP envelope */
    axiom_soap_envelope_t *response_soap_envelope;
    /** SOAP Fault envelope */
    axiom_soap_envelope_t *fault_soap_envelope;
    /** in fault flow? */
    axis2_bool_t in_fault_flow;
    /** is this server side? */
    axis2_bool_t server_side;
    /** message ID */
    axis2_char_t *message_id;
    /** new thread required? */
    axis2_bool_t new_thread_required;
    /** paused */
    axis2_bool_t paused;
    axis2_bool_t keep_alive;
    /** output written? */
    axis2_bool_t output_written;
    /** service context ID */
    axis2_char_t *svc_ctx_id;
    /** paused phase name */
    axis2_char_t *paused_phase_name;
    /** paused handler name */
    axutil_string_t *paused_handler_name;
    /** SOAP action */
    axutil_string_t *soap_action;
    /** are we doing MTOM now? */
    axis2_bool_t doing_mtom;
    /** are we doing REST now? */
    axis2_bool_t doing_rest;
    /** Rest through HTTP POST? */
    axis2_bool_t do_rest_through_post;
    /** use SOAP 1.1? */
    axis2_bool_t is_soap_11;
    /** service group context id */
    axutil_string_t *svc_grp_ctx_id;
    /** qname of transport in */
    AXIS2_TRANSPORT_ENUMS transport_in_desc_enum;
    /** qname of transport out */
    AXIS2_TRANSPORT_ENUMS transport_out_desc_enum;
    /** service group id */
    axis2_char_t *svc_grp_id;
    /** service description qname */
    axutil_qname_t *svc_qname;
    /** op qname */
    axutil_qname_t *op_qname;
    /* To keep track of the direction */
    int flow;
    /** The chain of Handlers/Phases for processing this message */
    axutil_array_list_t *execution_chain;
    /** Index into the execution chain of the currently executing handler */
    int current_handler_index;
    /** Index of the paused  handler */
    int paused_handler_index;
    /** Index of the paused  phase */
    int paused_phase_index;
    /** Index into the current Phase of the currently executing handler (if any)*/
    int current_phase_index;

    /**
     * Finds the service to be invoked. This function is used by dispatchers 
     * to locate the service to be invoked.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @return pointer to service to be invoked
     */
    struct axis2_svc *(AXIS2_CALL *
            find_svc)(axis2_msg_ctx_t *msg_ctx,
                const axutil_env_t *env);
    /**
     * Finds the operation to be invoked in the given service. This function 
     * is used by dispatchers to locate the operation to be invoked.
     * @param msg_ctx message context
     * @param env pointer to environment struct
     * @param svc pointer to service to whom the operation belongs 
     * @return pointer to the operation to be invoked
     */
    struct axis2_op *(AXIS2_CALL *
            find_op)( axis2_msg_ctx_t *msg_ctx,
                const axutil_env_t *env,
                struct axis2_svc *svc);

    axutil_string_t *charset_encoding;
    axutil_stream_t *transport_out_stream;
    axis2_http_out_transport_info_t *http_out_transport_info;
    axutil_hash_t *transport_headers;
    axis2_char_t *transfer_encoding;
    axis2_char_t *transport_url;
};

AXIS2_EXTERN axis2_msg_ctx_t *AXIS2_CALL
axis2_msg_ctx_create(
    const axutil_env_t *env,
    struct axis2_conf_ctx *conf_ctx,
    struct axis2_transport_in_desc *transport_in_desc,
    struct axis2_transport_out_desc *transport_out_desc)
{
    axis2_msg_ctx_t *msg_ctx = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    msg_ctx = AXIS2_MALLOC(env->allocator, sizeof(axis2_msg_ctx_t));
    if (!msg_ctx)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    msg_ctx->base = NULL;
    msg_ctx->process_fault = AXIS2_FALSE;
    msg_ctx->msg_info_headers = NULL;
    msg_ctx->op_ctx = NULL;
    msg_ctx->svc_ctx = NULL;
    msg_ctx->svc_grp_ctx = NULL;
    msg_ctx->conf_ctx = NULL;
    msg_ctx->op = NULL;
    msg_ctx->svc = NULL;
    msg_ctx->svc_grp = NULL;
    msg_ctx->transport_in_desc = NULL;
    msg_ctx->transport_out_desc = NULL;
    msg_ctx->soap_envelope = NULL;
    msg_ctx->fault_soap_envelope = NULL;
    msg_ctx->in_fault_flow = AXIS2_FALSE;
    msg_ctx->server_side = AXIS2_FALSE;
    msg_ctx->message_id = NULL;
    msg_ctx->new_thread_required = AXIS2_FALSE;
    msg_ctx->paused = AXIS2_FALSE;
    msg_ctx->keep_alive = AXIS2_FALSE;
    msg_ctx->output_written = AXIS2_FALSE;
    msg_ctx->svc_ctx_id = NULL;
    msg_ctx->paused_phase_name = NULL;
    msg_ctx->paused_handler_name = NULL;
    msg_ctx->soap_action = NULL;
    msg_ctx->doing_mtom = AXIS2_FALSE;
    msg_ctx->doing_rest = AXIS2_FALSE;
    msg_ctx->do_rest_through_post = AXIS2_FALSE;
    msg_ctx->is_soap_11 = AXIS2_FALSE;
    msg_ctx->svc_grp_ctx_id = NULL;
    msg_ctx->transport_in_desc_enum = AXIS2_TRANSPORT_ENUM_MAX;
    msg_ctx->transport_out_desc_enum = AXIS2_TRANSPORT_ENUM_MAX;
    msg_ctx->svc_grp_id = NULL;
    msg_ctx->svc_qname = NULL;
    msg_ctx->op_qname = NULL;
    msg_ctx->flow = AXIS2_IN_FLOW;
    msg_ctx->execution_chain = NULL;
    msg_ctx->current_handler_index = -1;
    msg_ctx->paused_handler_index = -1;
    msg_ctx->current_phase_index = 0;
    msg_ctx->paused_phase_index = 0;
    msg_ctx->charset_encoding = NULL;
    msg_ctx->transport_out_stream = NULL;
    msg_ctx->http_out_transport_info = NULL;
    msg_ctx->transport_headers = NULL;
    msg_ctx->transfer_encoding = NULL;
    msg_ctx->transport_url = NULL;
    msg_ctx->response_soap_envelope = NULL;

    msg_ctx->base = axis2_ctx_create(env);
    if (!(msg_ctx->base))
    {
        axis2_msg_ctx_free(msg_ctx, env);
        return NULL;
    }

    if (transport_in_desc)
        msg_ctx->transport_in_desc = transport_in_desc;
    if (transport_out_desc)
        msg_ctx->transport_out_desc = transport_out_desc;
    if (conf_ctx)
        msg_ctx->conf_ctx = conf_ctx;

    if (msg_ctx->transport_in_desc)
        msg_ctx->transport_in_desc_enum =
            axis2_transport_in_desc_get_enum(transport_in_desc, env);
    if (msg_ctx->transport_out_desc)
        msg_ctx->transport_out_desc_enum =
            axis2_transport_out_desc_get_enum(transport_out_desc, env);

    msg_ctx->msg_info_headers = axis2_msg_info_headers_create(env, NULL, NULL);
    if (!(msg_ctx->msg_info_headers))
    {
        axis2_msg_ctx_free(msg_ctx, env);
        return NULL;
    }
    msg_ctx->msg_info_headers_deep_copy = AXIS2_TRUE;

    return msg_ctx;
}

/******************************************************************************/
struct axis2_ctx *AXIS2_CALL
            axis2_msg_ctx_get_base(
                const axis2_msg_ctx_t *msg_ctx,
                const axutil_env_t *env)
{
    return msg_ctx->base;
}


struct axis2_op_ctx *AXIS2_CALL
            axis2_msg_ctx_get_parent(
                const axis2_msg_ctx_t *msg_ctx,
                const axutil_env_t *env)
{
    return msg_ctx->parent;
}

axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_parent(
    struct axis2_msg_ctx *msg_ctx,
    const axutil_env_t *env,
    struct axis2_op_ctx *parent)
{
    if (parent)
    {
        msg_ctx->parent = parent;
    }

    return AXIS2_SUCCESS;
}

void AXIS2_CALL
axis2_msg_ctx_free(
    axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (msg_ctx->paused || msg_ctx->keep_alive)
        return;
    
    if (msg_ctx->base)
    {
         axis2_ctx_free(msg_ctx->base, env);
    }

    if (msg_ctx->msg_info_headers && msg_ctx->msg_info_headers_deep_copy)
    {
        axis2_msg_info_headers_free(msg_ctx->msg_info_headers, env);
    }

    if (msg_ctx->message_id)
    {
        AXIS2_FREE(env->allocator, msg_ctx->message_id);
    }

    if (msg_ctx->svc_ctx_id)
    {
        AXIS2_FREE(env->allocator, msg_ctx->svc_ctx_id);
    }

    if (msg_ctx->soap_action)
    {
        axutil_string_free(msg_ctx->soap_action, env);
    }

    if (msg_ctx->svc_grp_ctx_id)
    {
        axutil_string_free(msg_ctx->svc_grp_ctx_id, env);
    }

    if (msg_ctx->soap_envelope)
    {
        axiom_soap_envelope_free(msg_ctx->soap_envelope, env);
    }

    if (msg_ctx->fault_soap_envelope)
    {
        axiom_soap_envelope_free(msg_ctx->fault_soap_envelope, env);
    }

    if (msg_ctx->charset_encoding)
    {
        axutil_string_free(msg_ctx->charset_encoding, env);
    }
    
    if (msg_ctx->transport_out_stream)
    {
       axutil_stream_free(msg_ctx->transport_out_stream, env); 
    }
    
    if (msg_ctx->http_out_transport_info)
    {
        AXIS2_HTTP_OUT_TRANSPORT_INFO_FREE(msg_ctx->http_out_transport_info, env);
    }
        
    if (msg_ctx->transport_headers)
    {
        axutil_hash_free(msg_ctx->transport_headers, env);
    }
        
    if (msg_ctx->transfer_encoding)
    {
        AXIS2_FREE(env->allocator, msg_ctx->transfer_encoding);
    }
    
    AXIS2_FREE(env->allocator, msg_ctx);

    return;
}

axis2_status_t AXIS2_CALL
axis2_msg_ctx_init(
    struct axis2_msg_ctx *msg_ctx,
    const axutil_env_t *env,
    struct axis2_conf *conf)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, conf, AXIS2_FAILURE);

    msg_ctx->transport_in_desc =  axis2_conf_get_transport_in(conf, env,
        msg_ctx->transport_in_desc_enum);

    msg_ctx->transport_out_desc =  axis2_conf_get_transport_out(conf,
        env, msg_ctx->transport_out_desc_enum);

    if (msg_ctx->svc_grp_id)
    {
        msg_ctx->svc_grp = axis2_conf_get_svc_grp(conf, env,
                msg_ctx->svc_grp_id);
    }

    if (msg_ctx->svc_qname)
    {
        msg_ctx->svc = axis2_conf_get_svc(conf, env,
                axutil_qname_get_localpart(msg_ctx->svc_qname, env));
    }

    if (msg_ctx->op_qname)
    {
        if (msg_ctx->svc)
            msg_ctx->op = axis2_svc_get_op_with_qname(msg_ctx->svc,
                    env, msg_ctx->op_qname);
    }

    return AXIS2_SUCCESS;
}

axis2_endpoint_ref_t *AXIS2_CALL
axis2_msg_ctx_get_fault_to(
    const axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    if (msg_ctx->msg_info_headers)
    {
        return axis2_msg_info_headers_get_fault_to(msg_ctx->msg_info_headers, env);
    }

    return NULL;
}


axis2_endpoint_ref_t *AXIS2_CALL
axis2_msg_ctx_get_from(
    const axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    if (msg_ctx->msg_info_headers)
    {
        return axis2_msg_info_headers_get_from(msg_ctx->msg_info_headers, env);
    }

    return NULL;
}

axis2_bool_t AXIS2_CALL
axis2_msg_ctx_get_in_fault_flow(
    const axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    return msg_ctx->in_fault_flow;
}

axiom_soap_envelope_t *AXIS2_CALL
axis2_msg_ctx_get_soap_envelope(
    const axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    return msg_ctx->soap_envelope;
}

axiom_soap_envelope_t *AXIS2_CALL
axis2_msg_ctx_get_response_soap_envelope(
    const axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    return msg_ctx->response_soap_envelope;
}

axiom_soap_envelope_t *AXIS2_CALL
axis2_msg_ctx_get_fault_soap_envelope(
    const axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    return msg_ctx->fault_soap_envelope;
}

const axis2_char_t *AXIS2_CALL
axis2_msg_ctx_get_msg_id(
    const axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    if (msg_ctx->msg_info_headers)
    {
        return axis2_msg_info_headers_get_message_id(
                    msg_ctx->msg_info_headers, env);
    }

    return NULL;
}

axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_msg_id(
    const axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env,
    axis2_char_t *msg_id)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (msg_ctx->msg_info_headers)
    {
        return axis2_msg_info_headers_set_message_id(msg_ctx->msg_info_headers,
                                                     env, msg_id);
    }

    return AXIS2_SUCCESS;
}

axis2_bool_t AXIS2_CALL
axis2_msg_ctx_get_process_fault(
    const axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    return msg_ctx->process_fault;
}

axis2_relates_to_t *AXIS2_CALL
axis2_msg_ctx_get_relates_to(
    const axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    if (msg_ctx->msg_info_headers)
    {
        return axis2_msg_info_headers_get_relates_to(msg_ctx->msg_info_headers, env);
    }

    return NULL;
}

axis2_endpoint_ref_t *AXIS2_CALL
axis2_msg_ctx_get_reply_to(
    const axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    if (msg_ctx->msg_info_headers)
    {
        return axis2_msg_info_headers_get_reply_to(msg_ctx->msg_info_headers, env);
    }

    return NULL;
}

axis2_bool_t AXIS2_CALL
axis2_msg_ctx_get_server_side(
    const axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    return msg_ctx->server_side;
}

axis2_endpoint_ref_t *AXIS2_CALL
axis2_msg_ctx_get_to(
    const axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    if (msg_ctx->msg_info_headers)
    {
        return axis2_msg_info_headers_get_to(msg_ctx->msg_info_headers, env);
    }

    return NULL;
}


axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_fault_to(
    struct axis2_msg_ctx *msg_ctx,
    const axutil_env_t *env,
    axis2_endpoint_ref_t *reference)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (msg_ctx->msg_info_headers)
    {
        return axis2_msg_info_headers_set_to(msg_ctx->msg_info_headers,
                env, reference);
    }

    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_from(
    struct axis2_msg_ctx *msg_ctx,
    const axutil_env_t *env,
    axis2_endpoint_ref_t *reference)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (msg_ctx->msg_info_headers)
    {
        return axis2_msg_info_headers_set_from(msg_ctx->msg_info_headers,
                env, reference);
    }

    return AXIS2_SUCCESS;
}


axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_in_fault_flow(
    struct axis2_msg_ctx *msg_ctx,
    const axutil_env_t *env,
    axis2_bool_t in_fault_flow)
{
    msg_ctx->in_fault_flow = in_fault_flow;
    return  AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_soap_envelope(
    struct axis2_msg_ctx *msg_ctx,
    const axutil_env_t *env,
    axiom_soap_envelope_t *soap_envelope)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (soap_envelope)
    {
        int soap_v = AXIOM_SOAP12;
        soap_v = axiom_soap_envelope_get_soap_version(soap_envelope, env);
        msg_ctx->is_soap_11 = (soap_v == AXIOM_SOAP12) ? AXIS2_FALSE : AXIS2_TRUE;
        msg_ctx->soap_envelope = soap_envelope;
    }
    else
    {
        msg_ctx->soap_envelope = NULL;
    }

    return AXIS2_SUCCESS;
}


axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_response_soap_envelope(
    struct axis2_msg_ctx *msg_ctx,
    const axutil_env_t *env,
    axiom_soap_envelope_t *soap_envelope)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (soap_envelope)
    {
        int soap_v = AXIOM_SOAP12;
        soap_v = axiom_soap_envelope_get_soap_version(soap_envelope, env);
        msg_ctx->response_soap_envelope = soap_envelope;
    }
    else
    {
        msg_ctx->response_soap_envelope = NULL;
    }
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_fault_soap_envelope(
    struct axis2_msg_ctx *msg_ctx,
    const axutil_env_t *env,
    axiom_soap_envelope_t *soap_envelope)
{
    msg_ctx->fault_soap_envelope  = soap_envelope ;
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_message_id(
    struct axis2_msg_ctx *msg_ctx,
    const axutil_env_t *env,
    const axis2_char_t *message_id)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (msg_ctx->msg_info_headers)
    {
        return axis2_msg_info_headers_set_message_id(
                    msg_ctx->msg_info_headers, env, message_id);
    }

    return AXIS2_SUCCESS;
}


axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_process_fault(
    struct axis2_msg_ctx *msg_ctx,
    const axutil_env_t *env,
    axis2_bool_t process_fault)
{
    msg_ctx->process_fault  = process_fault;
    return  AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_relates_to(
    struct axis2_msg_ctx *msg_ctx,
    const axutil_env_t *env,
    axis2_relates_to_t *reference)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (msg_ctx->msg_info_headers)
    {
        return axis2_msg_info_headers_set_relates_to(
                    msg_ctx->msg_info_headers, env, reference);
    }

    return AXIS2_SUCCESS;
}


axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_reply_to(
    struct axis2_msg_ctx *msg_ctx,
    const axutil_env_t *env,
    axis2_endpoint_ref_t *reference)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (msg_ctx->msg_info_headers)
    {
        return axis2_msg_info_headers_set_reply_to(
                    msg_ctx->msg_info_headers, env, reference);
    }

    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_server_side(
    struct axis2_msg_ctx *msg_ctx,
    const axutil_env_t *env,
    axis2_bool_t server_side)
{
    msg_ctx->server_side = server_side;
    return  AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_to(
    struct axis2_msg_ctx *msg_ctx,
    const axutil_env_t *env,
    axis2_endpoint_ref_t *reference)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (msg_ctx->msg_info_headers)
    {
        return axis2_msg_info_headers_set_to(msg_ctx->msg_info_headers,
                env, reference);
    }

    return AXIS2_SUCCESS;
}

axis2_bool_t AXIS2_CALL
axis2_msg_ctx_get_new_thread_required(
    const axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    return msg_ctx->new_thread_required;
}

axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_new_thread_required(
    struct axis2_msg_ctx *msg_ctx,
    const axutil_env_t *env,
    axis2_bool_t new_thread_required)
{
    msg_ctx->new_thread_required = new_thread_required;
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_wsa_action(
    struct axis2_msg_ctx *msg_ctx,
    const axutil_env_t *env,
    const axis2_char_t *action_uri)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (msg_ctx->msg_info_headers)
    {
        return axis2_msg_info_headers_set_action(msg_ctx->msg_info_headers,
                env, action_uri);
    }

    return AXIS2_SUCCESS;
}

const axis2_char_t *AXIS2_CALL
axis2_msg_ctx_get_wsa_action(
    const axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    if (msg_ctx->msg_info_headers)
    {
        return axis2_msg_info_headers_get_action(msg_ctx->msg_info_headers,
                env);
    }

    return NULL;
}

axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_wsa_message_id(
    struct axis2_msg_ctx *msg_ctx,
    const axutil_env_t *env,
    const axis2_char_t *message_id)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (msg_ctx->msg_info_headers)
    {
        return axis2_msg_info_headers_set_message_id(
                    msg_ctx->msg_info_headers, env, message_id);
    }

    return AXIS2_SUCCESS;
}

const axis2_char_t *AXIS2_CALL
axis2_msg_ctx_get_wsa_message_id(
    const axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    if (msg_ctx->msg_info_headers)
    {
        return axis2_msg_info_headers_get_message_id(
                    msg_ctx->msg_info_headers, env);
    }

    return NULL;

}

axis2_msg_info_headers_t *AXIS2_CALL
axis2_msg_ctx_get_msg_info_headers(
    const axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    return msg_ctx->msg_info_headers;
}

axis2_bool_t AXIS2_CALL
axis2_msg_ctx_get_paused(
    const axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    return msg_ctx->paused;
}

axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_paused(
    struct axis2_msg_ctx *msg_ctx,
    const axutil_env_t *env,
    axis2_bool_t paused)
{
    msg_ctx->paused = paused;
    msg_ctx->paused_phase_index = msg_ctx->current_phase_index;
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_keep_alive(
    struct axis2_msg_ctx *msg_ctx,
    const axutil_env_t *env,
    axis2_bool_t keep_alive)
{
    msg_ctx->keep_alive = keep_alive;
    return AXIS2_SUCCESS;
}

axis2_bool_t AXIS2_CALL
axis2_msg_ctx_is_keep_alive(
    const axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    return msg_ctx->keep_alive;
}

struct axis2_transport_in_desc *AXIS2_CALL
            axis2_msg_ctx_get_transport_in_desc(
                const axis2_msg_ctx_t *msg_ctx,
                const axutil_env_t *env)
{
    return msg_ctx->transport_in_desc;
}

struct axis2_transport_out_desc *AXIS2_CALL
            axis2_msg_ctx_get_transport_out_desc(
                const axis2_msg_ctx_t *msg_ctx,
                const axutil_env_t *env)
{
    return msg_ctx->transport_out_desc;
}

axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_transport_in_desc(
    struct axis2_msg_ctx *msg_ctx,
    const axutil_env_t *env,
    struct axis2_transport_in_desc *transport_in_desc)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (transport_in_desc)
    {
        msg_ctx->transport_in_desc = transport_in_desc;
        msg_ctx->transport_in_desc_enum =
            axis2_transport_in_desc_get_enum(transport_in_desc, env);
    }

    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_transport_out_desc(
    struct axis2_msg_ctx *msg_ctx,
    const axutil_env_t *env,
    struct axis2_transport_out_desc *transport_out_desc)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (transport_out_desc)
    {
        msg_ctx->transport_out_desc = transport_out_desc;
        msg_ctx->transport_out_desc_enum =
            axis2_transport_out_desc_get_enum(transport_out_desc, env);
    }

    return AXIS2_SUCCESS;
}

struct axis2_op_ctx *AXIS2_CALL
            axis2_msg_ctx_get_op_ctx(
                const axis2_msg_ctx_t *msg_ctx,
                const axutil_env_t *env)
{
    return msg_ctx->op_ctx;
}

axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_op_ctx(
    struct axis2_msg_ctx *msg_ctx,
    const axutil_env_t *env,
    struct axis2_op_ctx *op_ctx)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (op_ctx)
    {
        msg_ctx->op_ctx = op_ctx;

        if (msg_ctx->svc_ctx)
        {
            if (!( axis2_op_ctx_get_parent(msg_ctx->op_ctx, env)))
            {
                 axis2_op_ctx_set_parent(msg_ctx->op_ctx, env,
                        msg_ctx->svc_ctx);
            }
        }
        axis2_msg_ctx_set_parent(msg_ctx, env, op_ctx);
        axis2_msg_ctx_set_op(msg_ctx, env,  axis2_op_ctx_get_op(op_ctx, env));
    }
    return AXIS2_SUCCESS;
}

axis2_bool_t AXIS2_CALL
axis2_msg_ctx_get_output_written(
    const axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    return msg_ctx->output_written;
}

axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_output_written(
    struct axis2_msg_ctx *msg_ctx,
    const axutil_env_t *env,
    axis2_bool_t output_written)
{
    msg_ctx->output_written = output_written;
    return AXIS2_SUCCESS;
}

const axis2_char_t *AXIS2_CALL
axis2_msg_ctx_get_svc_ctx_id(
    const axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    return msg_ctx->svc_ctx_id;
}

axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_svc_ctx_id(
    struct axis2_msg_ctx *msg_ctx,
    const axutil_env_t *env,
    const axis2_char_t *svc_ctx_id)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (msg_ctx->svc_ctx_id)
    {
        AXIS2_FREE(env->allocator, msg_ctx->svc_ctx_id);
        msg_ctx->svc_ctx_id = NULL;
    }

    if (svc_ctx_id)
    {
        msg_ctx->svc_ctx_id = axutil_strdup(env, svc_ctx_id);
        if (!(msg_ctx->svc_ctx_id))
        {
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            return AXIS2_FAILURE;
        }
    }
    return AXIS2_SUCCESS;
}

struct axis2_conf_ctx *AXIS2_CALL
            axis2_msg_ctx_get_conf_ctx(
                const axis2_msg_ctx_t *msg_ctx,
                const axutil_env_t *env)
{
    return msg_ctx->conf_ctx;
}

struct axis2_svc_ctx *AXIS2_CALL
            axis2_msg_ctx_get_svc_ctx(
                const axis2_msg_ctx_t *msg_ctx,
                const axutil_env_t *env)
{
    return msg_ctx->svc_ctx;
}

axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_conf_ctx(
    struct axis2_msg_ctx *msg_ctx,
    const axutil_env_t *env,
    struct axis2_conf_ctx *conf_ctx)
{
    if (conf_ctx)
    {
        msg_ctx->conf_ctx = conf_ctx;
    }

    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_svc_ctx(
    struct axis2_msg_ctx *msg_ctx,
    const axutil_env_t *env,
    struct axis2_svc_ctx *svc_ctx)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (svc_ctx)
    {
        msg_ctx->svc_ctx = svc_ctx;

        if (msg_ctx->op_ctx)
        {
            if (! axis2_op_ctx_get_parent(msg_ctx->op_ctx, env))
                 axis2_op_ctx_set_parent(msg_ctx->op_ctx, env, svc_ctx);
        }
        axis2_msg_ctx_set_svc(msg_ctx, env,  axis2_svc_ctx_get_svc(svc_ctx, env));
    }

    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_msg_info_headers(
    struct axis2_msg_ctx *msg_ctx,
    const axutil_env_t *env,
    axis2_msg_info_headers_t *msg_info_headers)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (msg_info_headers)
    {
        if (msg_ctx->msg_info_headers && 
            msg_ctx->msg_info_headers_deep_copy)
        {
            axis2_msg_info_headers_free(msg_ctx->msg_info_headers, env);
            msg_ctx->msg_info_headers = NULL;
        }
        msg_ctx->msg_info_headers = msg_info_headers;
        msg_ctx->msg_info_headers_deep_copy = AXIS2_FALSE;
    }

    return AXIS2_SUCCESS;
}


axutil_param_t *AXIS2_CALL
axis2_msg_ctx_get_parameter(
    const axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env,
    const axis2_char_t *key)
{
    axutil_param_t *param = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (msg_ctx->op)
    {
        param = axis2_op_get_param(msg_ctx->op, env, key);
        if (param)
        {
            return param;
        }
    }

    if (msg_ctx->svc)
    {
        param = axis2_svc_get_param(msg_ctx->svc, env, key);
        if (param)
        {
            return param;
        }
    }

    if (msg_ctx->svc_grp)
    {
        param =  axis2_svc_grp_get_param(msg_ctx->svc_grp, env, key);
        if (param)
        {
            return param;
        }
    }

    if (msg_ctx->conf_ctx)
    {
        axis2_conf_t *conf =  axis2_conf_ctx_get_conf(msg_ctx->conf_ctx, env);
        param =  axis2_conf_get_param(conf, env, key);
    }

    return param;
}

AXIS2_EXTERN void * AXIS2_CALL
axis2_msg_ctx_get_property_value(
    axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env,
    const axis2_char_t *property_str)
{
    axutil_property_t *property;
    void *property_value = NULL;

    property = axis2_msg_ctx_get_property(msg_ctx, env, property_str);
    
    if (!property)
    {
        AXIS2_LOG_ERROR(env->log, 
                        AXIS2_LOG_SI, 
                        "%s not set in message context", property_str);
    }
    
    property_value = axutil_property_get_value(property, env);
    if (!property_value)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                        "%s properties not set in message context", 
                        property_str);
    }

    return property_value;
}


axutil_property_t *AXIS2_CALL
axis2_msg_ctx_get_property(
    const axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env,
    const axis2_char_t *key)
{
    void *obj = NULL;
    axis2_ctx_t *ctx = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    /* search in message context */
    obj =  axis2_ctx_get_property(msg_ctx->base, env, key);
    if (obj)
    {
        return obj;
    }

    if (msg_ctx->op_ctx)
    {
        ctx = axis2_op_ctx_get_base(msg_ctx->op_ctx, env);
        if (ctx)
        {
            obj =  axis2_ctx_get_property(ctx, env, key);
            if (obj)
            {
                return obj;
            }
        }
    }

    if (msg_ctx->svc_ctx)
    {
        ctx = axis2_svc_ctx_get_base(msg_ctx->svc_ctx, env);
        if (ctx)
        {
            obj =  axis2_ctx_get_property(ctx, env, key);
            if (obj)
            {
                return obj;
            }
        }
    }

    if (msg_ctx->svc_grp_ctx)
    {
        ctx =  axis2_svc_grp_ctx_get_base(msg_ctx->svc_grp_ctx, env);
        if (ctx)
        {
            obj =  axis2_ctx_get_property(ctx, env, key);
            if (obj)
            {
                return obj;
            }
        }
    }

    if (msg_ctx->conf_ctx)
    {
        ctx =  axis2_conf_ctx_get_base(msg_ctx->conf_ctx, env);
        if (ctx)
        {
            obj =  axis2_ctx_get_property(ctx, env, key);
            if (obj)
            {
                return obj;
            }
        }
    }

    return NULL;
}

axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_property(
    struct axis2_msg_ctx *msg_ctx,
    const axutil_env_t *env,
    const axis2_char_t *key,
    axutil_property_t *value)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    return axis2_ctx_set_property(msg_ctx->base, env, key, value);
}


const axutil_string_t *AXIS2_CALL
axis2_msg_ctx_get_paused_handler_name(
    const axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    return msg_ctx->paused_handler_name;
}

const axis2_char_t *AXIS2_CALL
axis2_msg_ctx_get_paused_phase_name(
    const axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    return msg_ctx->paused_phase_name;
}

axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_paused_phase_name(
    struct axis2_msg_ctx *msg_ctx,
    const axutil_env_t *env,
    const axis2_char_t *paused_phase_name)
{
    /* a shallow copy is sufficient as phase lives beyond message */
    msg_ctx->paused_phase_name = (axis2_char_t *)paused_phase_name; 
    return AXIS2_SUCCESS;
}

axutil_string_t *AXIS2_CALL
  axis2_msg_ctx_get_soap_action(
    const axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    return msg_ctx->soap_action;
}

axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_soap_action(
    struct axis2_msg_ctx *msg_ctx,
    const axutil_env_t *env,
    axutil_string_t *soap_action)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (msg_ctx->soap_action)
    {
        axutil_string_free(msg_ctx->soap_action, env);
    }

    if (soap_action)
    {
        msg_ctx->soap_action = axutil_string_clone(soap_action, env);
        if (!(msg_ctx->soap_action))
        {
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            return AXIS2_FAILURE;
        }
    }
    return AXIS2_SUCCESS;
}

axis2_bool_t AXIS2_CALL
axis2_msg_ctx_get_doing_mtom(
    axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (!(msg_ctx->doing_mtom) && msg_ctx->conf_ctx)
    {
        axis2_conf_t *conf =  axis2_conf_ctx_get_conf(msg_ctx->conf_ctx, env);
        msg_ctx->doing_mtom  = axis2_conf_get_enable_mtom(conf, env);
    }

    return msg_ctx->doing_mtom;
}

axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_doing_mtom(
    struct axis2_msg_ctx *msg_ctx,
    const axutil_env_t *env,
    axis2_bool_t doing_mtom)
{
    msg_ctx->doing_mtom = doing_mtom;
    return AXIS2_SUCCESS;
}

axis2_bool_t AXIS2_CALL
axis2_msg_ctx_get_doing_rest(
    const axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    return msg_ctx->doing_rest;
}

axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_doing_rest(
    struct axis2_msg_ctx *msg_ctx,
    const axutil_env_t *env,
    axis2_bool_t doing_rest)
{
    msg_ctx->doing_rest = doing_rest;
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_do_rest_through_post(
    struct axis2_msg_ctx *msg_ctx,
    const axutil_env_t *env,
    axis2_bool_t do_rest_through_post)
{
    msg_ctx->do_rest_through_post = do_rest_through_post;
    return AXIS2_SUCCESS;
}

axis2_bool_t AXIS2_CALL
axis2_msg_ctx_get_do_rest_through_post(
    const axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    return msg_ctx->do_rest_through_post;
}

axis2_bool_t AXIS2_CALL
axis2_msg_ctx_get_is_soap_11(
    const axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    return msg_ctx->is_soap_11;
}

axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_is_soap_11(
    struct axis2_msg_ctx *msg_ctx,
    const axutil_env_t *env,
    axis2_bool_t is_soap11)
{
    msg_ctx->is_soap_11 = is_soap11;
    return AXIS2_SUCCESS;
}

struct axis2_svc_grp_ctx *AXIS2_CALL
            axis2_msg_ctx_get_svc_grp_ctx(
                const axis2_msg_ctx_t *msg_ctx,
                const axutil_env_t *env)
{
    return msg_ctx->svc_grp_ctx;
}

axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_svc_grp_ctx(
    struct axis2_msg_ctx *msg_ctx,
    const axutil_env_t *env,
    struct axis2_svc_grp_ctx *svc_grp_ctx)
{

    if (svc_grp_ctx)
    {
        msg_ctx->svc_grp_ctx = svc_grp_ctx;
    }

    return AXIS2_SUCCESS;
}

axis2_op_t *AXIS2_CALL
axis2_msg_ctx_get_op(
    const axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    return msg_ctx->op;
}

axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_op(
    struct axis2_msg_ctx *msg_ctx,
    const axutil_env_t *env,
    axis2_op_t *op)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (op)
    {
        msg_ctx->op = op;
        msg_ctx->op_qname = (axutil_qname_t *)axis2_op_get_qname(op, env);
    }

    return AXIS2_SUCCESS;
}

axis2_svc_t *AXIS2_CALL
axis2_msg_ctx_get_svc(
    const axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    return msg_ctx->svc;
}

axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_svc(
    struct axis2_msg_ctx *msg_ctx,
    const axutil_env_t *env,
    axis2_svc_t *svc)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (svc)
    {
        axis2_svc_grp_t *svc_grp = NULL;
        msg_ctx->svc = svc;
        msg_ctx->svc_qname = (axutil_qname_t *)axis2_svc_get_qname(svc, env);

        svc_grp = axis2_svc_get_parent(svc, env);
        if (svc_grp)
        {
            msg_ctx->svc_grp = svc_grp;
            msg_ctx->svc_grp_id =
                (axis2_char_t *) axis2_svc_grp_get_name(svc_grp, env);
        }
    }

    return AXIS2_SUCCESS;
}

axis2_svc_grp_t *AXIS2_CALL
 axis2_msg_ctx_get_svc_grp(
    const axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    return msg_ctx->svc_grp;
}

axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_svc_grp(
    struct axis2_msg_ctx *msg_ctx,
    const axutil_env_t *env,
    axis2_svc_grp_t *svc_grp)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (svc_grp)
    {
        msg_ctx->svc_grp = svc_grp;
        msg_ctx->svc_grp_id =
            (axis2_char_t *) axis2_svc_grp_get_name(svc_grp, env);
    }

    return AXIS2_SUCCESS;
}

const axutil_string_t *AXIS2_CALL
axis2_msg_ctx_get_svc_grp_ctx_id(
    const axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    return msg_ctx->svc_grp_ctx_id;
}

axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_svc_grp_ctx_id(
    struct axis2_msg_ctx *msg_ctx,
    const axutil_env_t *env,
    axutil_string_t *svc_grp_ctx_id)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (msg_ctx->svc_grp_ctx_id)
    {
        axutil_string_free(msg_ctx->svc_grp_ctx_id, env);
        msg_ctx->svc_grp_ctx_id = NULL;
    }

    if (svc_grp_ctx_id)
    {
        msg_ctx->svc_grp_ctx_id = axutil_string_clone(svc_grp_ctx_id, env);
    }
    return AXIS2_SUCCESS;
}

axis2_bool_t AXIS2_CALL
axis2_msg_ctx_is_paused(
    axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    return msg_ctx->paused;
}

axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_find_svc(
    axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env, 
    void *func)
{
    msg_ctx->find_svc = func;
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_find_op(
    axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env,
    void *func)
{
    msg_ctx->find_op = func;
    return AXIS2_SUCCESS;
}

axis2_options_t *AXIS2_CALL
axis2_msg_ctx_get_options(
    axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    axis2_options_t *options = NULL;
    axutil_hash_t *properties = NULL;
    AXIS2_ENV_CHECK(env, NULL);

    options = axis2_options_create(env);
    axis2_options_set_msg_info_headers(options, env, 
        msg_ctx->msg_info_headers);
    properties =  axis2_ctx_get_property_map(msg_ctx->base, env);
    axis2_options_set_properties(options, env, properties);
    return options;
}


axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_options(
    axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env,
    axis2_options_t *options)
{
    axutil_property_t *rest_val = NULL;
	axis2_char_t *value;
	axutil_string_t *soap_action = NULL;;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, options, AXIS2_FAILURE);

    if (msg_ctx->msg_info_headers && msg_ctx->msg_info_headers_deep_copy)
    {
        axis2_msg_info_headers_free(
            msg_ctx->msg_info_headers, env);
    }
    msg_ctx->msg_info_headers =

        axis2_options_get_msg_info_headers(options, env);
    msg_ctx->msg_info_headers_deep_copy = AXIS2_FALSE;
    
    msg_ctx->doing_mtom = axis2_options_get_enable_mtom(options, env);

    axis2_ctx_set_property_map(msg_ctx->base, env,
         axis2_options_get_properties(options, env));
    rest_val = (axutil_property_t *)  axis2_msg_ctx_get_property(msg_ctx, env,
            AXIS2_ENABLE_REST);
    if (rest_val)
    {
		value = (axis2_char_t *)axutil_property_get_value(rest_val, env);
		if (value)
		{
			if (axutil_strcmp(value, AXIS2_VALUE_TRUE) == 0)
				 axis2_msg_ctx_set_doing_rest(msg_ctx, env, AXIS2_TRUE);
		}
    }

    if (msg_ctx->soap_action)
    {
        axutil_string_free(msg_ctx->soap_action, env);
    }
    
    soap_action = axis2_options_get_soap_action(options, env);
    if (soap_action)
    {
        msg_ctx->soap_action = axutil_string_clone(soap_action, env);
    }

    return AXIS2_SUCCESS;
}


axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_flow(
    axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env,
    int flow)
{
    msg_ctx->flow = flow;
    return AXIS2_SUCCESS;
}

int AXIS2_CALL
axis2_msg_ctx_get_flow(
    const axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    return msg_ctx->flow;
}


axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_execution_chain(
    axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env,
    axutil_array_list_t *execution_chain)
{
    msg_ctx->execution_chain = execution_chain;
    msg_ctx->current_handler_index = -1;
    msg_ctx->paused_handler_index = -1;
    msg_ctx->current_phase_index = 0;
    return AXIS2_SUCCESS;
}

axutil_array_list_t *AXIS2_CALL
axis2_msg_ctx_get_execution_chain(
    const axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    return msg_ctx->execution_chain;
}

axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_current_handler_index(
    axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env,
    const int index)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    msg_ctx->current_handler_index = index;
    if (msg_ctx->execution_chain)
    {
        axis2_handler_t *handler = (axis2_handler_t *)
                axutil_array_list_get(msg_ctx->execution_chain,
                        env, index);
        if (handler)
        {
            msg_ctx->paused_handler_name =
                (axutil_string_t *)axis2_handler_get_name(handler, env);
        }
    }
    return AXIS2_SUCCESS;
}

int AXIS2_CALL
axis2_msg_ctx_get_current_handler_index(
    const axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    return msg_ctx->current_handler_index;
}

int AXIS2_CALL
axis2_msg_ctx_get_paused_handler_index(const axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env)
{
    return msg_ctx->paused_handler_index;
}


axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_current_phase_index(
    axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env,
    const int index)
{
    msg_ctx->current_phase_index = index;
    return AXIS2_SUCCESS;

}

int AXIS2_CALL
axis2_msg_ctx_get_current_phase_index(
    const axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    return msg_ctx->current_phase_index;
}

int AXIS2_CALL
axis2_msg_ctx_get_paused_phase_index(
    const axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    return msg_ctx->paused_phase_index;
}

AXIS2_EXTERN axis2_svc_t * AXIS2_CALL
axis2_msg_ctx_find_svc(axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    return msg_ctx->find_svc(msg_ctx, env);
}

AXIS2_EXTERN axis2_op_t * AXIS2_CALL
axis2_msg_ctx_find_op(axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env,
    axis2_svc_t *svc)
{
    return msg_ctx->find_op(msg_ctx, env, svc);
}


AXIS2_EXTERN axutil_string_t* AXIS2_CALL
axis2_msg_ctx_get_charset_encoding(axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{    
    if (msg_ctx)
        return msg_ctx->charset_encoding;
    else
        return NULL;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_charset_encoding(axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env,
    axutil_string_t *str)
{    
    if (msg_ctx)
    {
        if (msg_ctx->charset_encoding)
        {
            axutil_string_free(msg_ctx->charset_encoding, env);
            msg_ctx->charset_encoding = NULL;
        }
        if (str)
        {
            msg_ctx->charset_encoding = axutil_string_clone(str, env);
        }
    }
    else
    {
        return AXIS2_FAILURE;
    }
    
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axutil_stream_t *AXIS2_CALL
axis2_msg_ctx_get_transport_out_stream(axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    if (msg_ctx)
    {
        return msg_ctx->transport_out_stream;
    }
    else
    {
        return NULL;
    }
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_transport_out_stream(axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env,
    axutil_stream_t *stream)
{
    if (msg_ctx)
    {
        if (msg_ctx->transport_out_stream)
        {
           axutil_stream_free(msg_ctx->transport_out_stream, env); 
        }
        
        msg_ctx->transport_out_stream = stream;
    }
    else
    {
        return AXIS2_FAILURE;
    }
    
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_msg_ctx_reset_transport_out_stream(axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    if (msg_ctx)
    {
        msg_ctx->transport_out_stream = NULL;
    }
    else
    {
        return AXIS2_FAILURE;
    }
    
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_http_out_transport_info_t *AXIS2_CALL
axis2_msg_ctx_get_http_out_transport_info(axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    if (msg_ctx)
    {
        return msg_ctx->http_out_transport_info;
    }
    else
    {
        return NULL;
    }
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_http_out_transport_info(axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env,
    axis2_http_out_transport_info_t *http_out_transport_info)
{
    if (msg_ctx)
    {
        if (msg_ctx->http_out_transport_info)
        {
           AXIS2_HTTP_OUT_TRANSPORT_INFO_FREE(msg_ctx->http_out_transport_info, env); 
        }
        
        msg_ctx->http_out_transport_info = http_out_transport_info;
    }
    else
    {
        return AXIS2_FAILURE;
    }
    
    return AXIS2_SUCCESS;
}      

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_msg_ctx_reset_http_out_transport_info(axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    if (msg_ctx)
    {
        msg_ctx->http_out_transport_info = NULL;
    }
    else
    {
        return AXIS2_FAILURE;
    }

    return AXIS2_SUCCESS;
}
   
AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
axis2_msg_ctx_get_transport_headers(axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    if (msg_ctx)
    {
        return msg_ctx->transport_headers;
    }
    else
    {
        return NULL;
    }
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_transport_headers(axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env,
    axutil_hash_t *transport_headers)
{
    if (msg_ctx)
    {
        if (msg_ctx->transport_headers)
        {
            axutil_hash_free(msg_ctx->transport_headers, env); 
        }
        
        msg_ctx->transport_headers = transport_headers;
    }
    else
    {
        return AXIS2_FAILURE;
    }
    
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
axis2_msg_ctx_get_transfer_encoding(axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{    
    if (msg_ctx)
        return msg_ctx->transfer_encoding;
    else
        return NULL;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_transfer_encoding(axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env,
    axis2_char_t *str)
{    
    if (msg_ctx)
    {
        if (msg_ctx->transfer_encoding)
        {
            AXIS2_FREE(env->allocator, msg_ctx->transfer_encoding);
            msg_ctx->transfer_encoding = NULL;
        }
        if (str)
        {
            msg_ctx->transfer_encoding = str;
        }
    }
    else
    {
        return AXIS2_FAILURE;
    }
    
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
axis2_msg_ctx_get_transport_url(axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{    
    if (msg_ctx)
        return msg_ctx->transport_url;
    else
        return NULL;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_msg_ctx_set_transport_url(axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env,
    axis2_char_t *str)
{    
    if (msg_ctx)
    {
        /* this is a shallow copy, no need to free */
        msg_ctx->transport_url = str;
    }
    else
    {
        return AXIS2_FAILURE;
    }
    
    return AXIS2_SUCCESS;
}



