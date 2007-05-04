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

#include <axis2_engine.h>
#include <axis2_const.h>
#include <axutil_hash.h>
#include <axiom_soap_const.h>
#include <axiom_soap_envelope.h>
#include <axiom_soap_body.h>
#include <axiom_soap_fault.h>
#include <axiom_soap_header.h>
#include <axiom_soap_header_block.h>
#include <axis2_transport_sender.h>
#include <axis2_http_transport.h>
#include <axis2_addr.h>
#include <axutil_uuid_gen.h>

struct axis2_engine
{
    /** configuration context */
    axis2_conf_ctx_t *conf_ctx;
};

AXIS2_EXTERN axis2_engine_t *AXIS2_CALL
axis2_engine_create(
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx)
{
    axis2_engine_t *engine = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    engine = AXIS2_MALLOC(env->allocator, sizeof(axis2_engine_t));
    if (!engine)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    engine->conf_ctx = NULL;

    if (conf_ctx)
    {
        engine->conf_ctx =  conf_ctx;
    }

    return engine;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_engine_free(
    axis2_engine_t *engine,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);
    AXIS2_FREE(env->allocator, engine);
    return;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_engine_send(
    axis2_engine_t *engine,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    axis2_status_t status = AXIS2_SUCCESS;
    axis2_op_ctx_t *op_ctx = NULL;
    axutil_array_list_t *phases = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_conf_t *conf = NULL;

    AXIS2_LOG_TRACE(env->log, AXIS2_LOG_SI, "axis2_engine_send start");

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);

    /* find and invoke the phases */
    op_ctx =  axis2_msg_ctx_get_op_ctx(msg_ctx, env);
    if (op_ctx)
    {
        axis2_op_t *op =  axis2_op_ctx_get_op(op_ctx, env);
        if (op)
        {
            phases = axis2_op_get_out_flow(op, env);
        }
    }

    if ( axis2_msg_ctx_is_paused(msg_ctx, env))
    {
        /* message has paused, so rerun it from the position it stopped.
           The handler which paused the message will be the first one to resume 
           invocation
        */
        status = axis2_engine_resume_invocation_phases(engine, env, phases, msg_ctx);
        if (status != AXIS2_SUCCESS)
        {
            return status;
        }

        conf_ctx =  axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
        if (conf_ctx)
        {
            conf =  axis2_conf_ctx_get_conf(conf_ctx, env);
            if (conf)
            {
                axutil_array_list_t *global_out_phase =  axis2_conf_get_out_phases(conf, env);
                if (global_out_phase)
                {
                    axis2_engine_invoke_phases(engine, env, global_out_phase, msg_ctx);
                }
            }
        }
    }
    else
    {
        axis2_status_t status = AXIS2_FAILURE;
        status = axis2_engine_invoke_phases(engine, env, phases, msg_ctx);
        if (status != AXIS2_SUCCESS)
        {
            return status;
        }

        conf_ctx =  axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
        if (conf_ctx)
        {
            conf =  axis2_conf_ctx_get_conf(conf_ctx, env);
            if (conf)
            {
                axutil_array_list_t *global_out_phase =  axis2_conf_get_out_phases(conf, env);
                if (global_out_phase)
                {
                    axis2_engine_invoke_phases(engine, env, global_out_phase, msg_ctx);
                }
            }
        }
    }

    if (!( axis2_msg_ctx_is_paused(msg_ctx, env)))
    {
        /* write the message to wire */
        axis2_transport_sender_t *transport_sender = NULL;
        axis2_transport_out_desc_t *transport_out =  
            axis2_msg_ctx_get_transport_out_desc(msg_ctx, env);

        if (transport_out)
        {
            transport_sender = 
                axis2_transport_out_desc_get_sender(transport_out, env);

            if (transport_sender)
            {
                AXIS2_TRANSPORT_SENDER_INVOKE(transport_sender, env, msg_ctx);
            }
            else
                return AXIS2_FAILURE;
        }
        else
        {
            AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
                "Transport out is not set in message context");
            return AXIS2_FAILURE;
        }
    }

    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "Axis2 engine send successful");
    AXIS2_LOG_TRACE(env->log, AXIS2_LOG_SI, "axis2_engine_send end");
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_engine_receive(
    axis2_engine_t *engine,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_conf_t *conf = NULL;
    axis2_op_ctx_t *op_ctx = NULL;
    axis2_op_t *op = NULL;
    axutil_array_list_t *pre_calculated_phases = NULL;
    axutil_array_list_t *op_specific_phases = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    AXIS2_LOG_TRACE(env->log, AXIS2_LOG_SI, "Start:axis2_engine_receive");
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);

    conf_ctx =  axis2_msg_ctx_get_conf_ctx(msg_ctx, env);

    conf =  axis2_conf_ctx_get_conf(conf_ctx, env);

    pre_calculated_phases =
         axis2_conf_get_in_phases_upto_and_including_post_dispatch(conf, env);

    if ( axis2_msg_ctx_is_paused(msg_ctx, env))
    {
        /* the message has paused, so re-run them from the position they stopped. */
        axis2_engine_resume_invocation_phases(engine, env, 
            pre_calculated_phases, 
            msg_ctx);
        if (axis2_msg_ctx_is_paused(msg_ctx, env))
        {
            return AXIS2_SUCCESS;
        }

        /* resume op specific phases */
        op_ctx =  axis2_msg_ctx_get_op_ctx(msg_ctx, env);
        if (op_ctx)
        {
            op =  axis2_op_ctx_get_op(op_ctx, env);
            op_specific_phases = axis2_op_get_in_flow(op, env);
            axis2_engine_resume_invocation_phases(engine, env, 
                op_specific_phases, 
                msg_ctx);
            if (axis2_msg_ctx_is_paused(msg_ctx, env))
            {
                return AXIS2_SUCCESS;
            }
        }
    }
    else
    {
        status = axis2_engine_invoke_phases(engine, env, 
                     pre_calculated_phases, msg_ctx);
        if (status != AXIS2_SUCCESS)
        {
            if ( axis2_msg_ctx_get_server_side(msg_ctx, env))
                return status;
        }

        if (AXIS2_TRUE ==  axis2_msg_ctx_is_paused(msg_ctx, env))
        {
            return AXIS2_SUCCESS;
        }

        op_ctx =  axis2_msg_ctx_get_op_ctx(msg_ctx, env);
        if (op_ctx)
        {
            op =  axis2_op_ctx_get_op(op_ctx, env);
            op_specific_phases = axis2_op_get_in_flow(op, env);
            status = axis2_engine_invoke_phases(engine, env, 
                         op_specific_phases, msg_ctx);
            if (status != AXIS2_SUCCESS)
            {
                return status;
            }

            if (AXIS2_TRUE ==  axis2_msg_ctx_is_paused(msg_ctx, env))
            {
                return AXIS2_SUCCESS;
            }
        }
    }

    if ((axis2_msg_ctx_get_server_side(msg_ctx, env)) && 
        !( axis2_msg_ctx_is_paused(msg_ctx, env)))
    {
        axis2_msg_recv_t *receiver = NULL;

        status = axis2_engine_check_must_understand_headers(env, msg_ctx);
        if (status != AXIS2_SUCCESS)
            return status;

        /* invoke the message receivers */
        if (!op)
            return AXIS2_FAILURE;
        receiver = axis2_op_get_msg_recv(op, env);
        if (!receiver)
        {
            AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
                "Message receiver not set in operation description");
            return AXIS2_FAILURE;
        }
        status = axis2_msg_recv_receive(receiver, env, msg_ctx, 
            axis2_msg_recv_get_derived(receiver, env));
    }

    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "Axis2 engine receive completed!");
    AXIS2_LOG_TRACE(env->log, AXIS2_LOG_SI, "Exit:axis2_engine_receive");

    return status;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_engine_send_fault(
    axis2_engine_t *engine,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    axis2_op_ctx_t *op_ctx = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);

    op_ctx =  axis2_msg_ctx_get_op_ctx(msg_ctx, env);

    if (!( axis2_msg_ctx_is_paused(msg_ctx, env)))
    {
        /* send the SOAP Fault*/
        axis2_conf_ctx_t *conf_ctx = NULL;
        axis2_transport_sender_t *transport_sender = NULL;
        axis2_transport_out_desc_t *transport_out  = NULL;
        conf_ctx =  axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
        if (conf_ctx)
        {
            axis2_conf_t *conf =  axis2_conf_ctx_get_conf(conf_ctx, env);
            if (conf)
            {
                axutil_array_list_t *phases =  
                    axis2_conf_get_out_fault_flow(conf, env);
                if (phases)
                {
                    axis2_engine_invoke_phases(engine, env, phases, msg_ctx);
                }
            }
        }

        transport_out =  axis2_msg_ctx_get_transport_out_desc(msg_ctx, env);

        if (transport_out)
        {
            transport_sender = 
                axis2_transport_out_desc_get_sender(transport_out, env);
        }

        if (transport_sender)
        {
            AXIS2_TRANSPORT_SENDER_INVOKE(transport_sender, env, msg_ctx);
        }
    }
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_engine_receive_fault(
    axis2_engine_t *engine,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    axis2_op_ctx_t *op_ctx = NULL;

    AXIS2_LOG_TRACE(env->log, AXIS2_LOG_SI, "Start:axis2_engine_receive_fault");
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);

    op_ctx =  axis2_msg_ctx_get_op_ctx(msg_ctx, env);

    if (!op_ctx)
    {
        /* if we do not have an op context that means this may be an incoming
           dual channel response. So try to dispatch the service */
        axis2_conf_ctx_t *conf_ctx =  axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
        if (conf_ctx)
        {
            axis2_conf_t *conf =  axis2_conf_ctx_get_conf(conf_ctx, env);
            if (conf)
            {
                axutil_array_list_t *phases =  
                    axis2_conf_get_in_phases_upto_and_including_post_dispatch(conf, env);
                if (phases)
                {
                    if ( axis2_msg_ctx_is_paused(msg_ctx, env))
                    {
                        axis2_engine_resume_invocation_phases(engine, 
                            env, phases, msg_ctx);
                    }
                    else
                    {
                        axis2_engine_invoke_phases(engine, env, phases, msg_ctx);
                    }
                }
            }
        }
    }

    op_ctx =  axis2_msg_ctx_get_op_ctx(msg_ctx, env);
    /* find and execute the fault in flow handlers */
    if (op_ctx)
    {
        axis2_op_t *op =  axis2_op_ctx_get_op(op_ctx, env);
        axutil_array_list_t *phases = axis2_op_get_fault_in_flow(op, env);
        if ( axis2_msg_ctx_is_paused(msg_ctx, env))
        {
            axis2_engine_resume_invocation_phases(engine, env, phases, msg_ctx);
        }
        else
        {
            axis2_engine_invoke_phases(engine, env, phases, msg_ctx);
        }
    }
    AXIS2_LOG_TRACE(env->log, AXIS2_LOG_SI, "Exit:axis2_engine_receive_fault");
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_msg_ctx_t *AXIS2_CALL
axis2_engine_create_fault_msg_ctx(
    axis2_engine_t *engine,
    const axutil_env_t *env,
    axis2_msg_ctx_t *processing_context)
{
    axis2_msg_ctx_t *fault_ctx = NULL;
    axis2_endpoint_ref_t *fault_to = NULL;
    axis2_endpoint_ref_t *reply_to = NULL;
    axutil_stream_t *stream = NULL;
    axiom_soap_envelope_t *envelope = NULL;
    const axis2_char_t *wsa_action = NULL;
    const axis2_char_t *msg_id = NULL;
    axis2_relates_to_t *relates_to = NULL;
    axis2_char_t *msg_uuid = NULL;
    axis2_msg_info_headers_t *msg_info_headers = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, processing_context, AXIS2_FAILURE);

    if ( axis2_msg_ctx_get_process_fault(processing_context, env))
    {
        AXIS2_ERROR_SET(env->error,
                AXIS2_ERROR_INVALID_STATE_PROCESSING_FAULT_ALREADY, 
                AXIS2_FAILURE);
        return NULL;
    }

    fault_ctx = axis2_msg_ctx_create(env, engine->conf_ctx,
             axis2_msg_ctx_get_transport_in_desc(processing_context, env),
             axis2_msg_ctx_get_transport_out_desc(processing_context, env));

     axis2_msg_ctx_set_process_fault(fault_ctx, env, AXIS2_TRUE);

    fault_to =  axis2_msg_ctx_get_fault_to(processing_context, env);
    if (fault_to)
    {
        const axis2_char_t *address = axis2_endpoint_ref_get_address(fault_to, env);
        if (!address)
        {
            fault_to = NULL;
        }
        else if (axutil_strcmp(AXIS2_WSA_NONE_URL, address) == 0 ||
                axutil_strcmp(AXIS2_WSA_NONE_URL_SUBMISSION, address) == 0)
        {
            reply_to =  axis2_msg_ctx_get_reply_to(processing_context, env);
            if (reply_to)
            {
                 axis2_msg_ctx_set_fault_to(fault_ctx, env, reply_to);
            }
            else
            {
                 axis2_msg_ctx_set_fault_to(fault_ctx, env, fault_to);
            }
        }
        else
        {
             axis2_msg_ctx_set_fault_to(fault_ctx, env, fault_to);
        }

    }

    stream = axis2_msg_ctx_get_transport_out_stream(processing_context, env);

    if (stream)
    {
        axis2_msg_ctx_set_transport_out_stream(fault_ctx, env, stream);
    }

    if (!fault_to && !stream)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NOWHERE_TO_SEND_FAULT, AXIS2_FAILURE);
        return NULL;
    }

    /* set WSA action */
    msg_info_headers =  
        axis2_msg_ctx_get_msg_info_headers(processing_context, env);
    if (msg_info_headers)
    {
        wsa_action = axis2_msg_info_headers_get_action (msg_info_headers, env);
        if (wsa_action)
        {
            wsa_action = "http://www.w3.org/2005/08/addressing/fault";
             axis2_msg_ctx_set_wsa_action(fault_ctx, env, wsa_action);
        }
    }

    /* set relates to */
    msg_id =  axis2_msg_ctx_get_msg_id(processing_context, env);
    relates_to = axis2_relates_to_create(env, msg_id,
            AXIS2_WSA_RELATES_TO_RELATIONSHIP_TYPE_DEFAULT_VALUE);
     axis2_msg_ctx_set_relates_to(fault_ctx, env, relates_to);

    /* set msg id */
    msg_uuid =  axutil_uuid_gen(env);
    axis2_msg_ctx_set_message_id(fault_ctx, env, msg_uuid);
    if (msg_uuid)
    {
        AXIS2_FREE(env->allocator, msg_uuid);
        msg_uuid = NULL;
    }

     axis2_msg_ctx_set_op_ctx(fault_ctx, env,  
         axis2_msg_ctx_get_op_ctx(processing_context, env));
     axis2_msg_ctx_set_process_fault(fault_ctx, env, AXIS2_TRUE);
     axis2_msg_ctx_set_server_side(fault_ctx, env, AXIS2_TRUE);

    envelope =  axis2_msg_ctx_get_fault_soap_envelope(processing_context, env);

    if (!envelope)
    {
        if ( axis2_msg_ctx_get_is_soap_11(processing_context, env))
        {
            envelope = 
                axiom_soap_envelope_create_default_soap_envelope(env, AXIOM_SOAP11);

        }
        else
        {
            envelope = 
                axiom_soap_envelope_create_default_soap_envelope(env, AXIOM_SOAP12);
        }

        if (!envelope)
        {
            return NULL;
        }
    }

    axis2_msg_ctx_set_soap_envelope(fault_ctx, env, envelope);
    axis2_msg_ctx_set_http_out_transport_info(fault_ctx, env, 
        axis2_msg_ctx_get_http_out_transport_info(processing_context, env));
    return fault_ctx;
}



AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_engine_invoke_phases(
    axis2_engine_t *engine,
    const axutil_env_t *env,
    axutil_array_list_t *phases,
    axis2_msg_ctx_t *msg_ctx)
{
    int i = 0;
    int count = 0;
    axis2_status_t status = AXIS2_SUCCESS;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, phases, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);

    if (phases)
        count = axutil_array_list_size(phases, env);
    for (i = 0; (i < count && !( axis2_msg_ctx_is_paused(msg_ctx, env))); i++)
    {
        axis2_phase_t *phase = (axis2_phase_t *)
                axutil_array_list_get(phases, env, i);

        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
                "Invoking phase %s",  axis2_phase_get_name(phase, env));
                
        status = axis2_phase_invoke(phase, env, msg_ctx);

        if (status != AXIS2_SUCCESS)
        {
            return status;
        }
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_engine_resume_invocation_phases(
    axis2_engine_t *engine,
    const axutil_env_t *env,
    axutil_array_list_t *phases,
    axis2_msg_ctx_t *msg_ctx)
{
    int i = 0;
    int count = 0;
    axis2_bool_t found_match = AXIS2_FALSE;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, phases, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);

     axis2_msg_ctx_set_paused(msg_ctx, env, AXIS2_FALSE);

    count = axutil_array_list_size(phases, env);

    for (i = 0; i < count && !( axis2_msg_ctx_is_paused(msg_ctx, env)); i++)
    {
        axis2_phase_t *phase = (axis2_phase_t *) axutil_array_list_get(phases,
                env, i);
        const axis2_char_t *phase_name =  axis2_phase_get_name(phase, env);
        const axis2_char_t *paused_phase_name =  
            axis2_msg_ctx_get_paused_phase_name(msg_ctx, env);
        /* skip invoking handlers until we find the paused phase */
        if (phase_name && paused_phase_name && 0 == 
            axutil_strcmp(phase_name, paused_phase_name))
        {
            int paused_handler_i = -1;
            found_match = AXIS2_TRUE;

            paused_handler_i =  axis2_msg_ctx_get_current_handler_index(msg_ctx,
                    env);
            /* invoke the paused handler and rest of the handlers of the paused
             * phase */
            axis2_phase_invoke_start_from_handler(phase, env, paused_handler_i,
                    msg_ctx);
        }
        else 
        {
            /* now we have found the paused phase and invoked the rest of the
             * handlers of that phase, invoke all the phases after that */
            if (found_match)
            {
                axis2_phase_invoke(phase, env, msg_ctx);
            }
        }
    }

    return AXIS2_SUCCESS;
}


AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
axis2_engine_get_receiver_fault_code(
    const axis2_engine_t *engine,
    const axutil_env_t *env,
    const axis2_char_t *soap_namespace)
{
    if (axutil_strcmp(AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI, soap_namespace))
        return AXIOM_SOAP12_FAULT_CODE_RECEIVER;
    else
        return AXIOM_SOAP11_FAULT_CODE_RECEIVER;
    return NULL;
}

axis2_status_t
axis2_engine_check_must_understand_headers(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    axiom_soap_envelope_t *soap_envelope = NULL;
    axiom_soap_header_t *soap_header = NULL;
    axutil_hash_t *header_block_ht = NULL;
    axutil_hash_index_t *hash_index = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);

    soap_envelope =  axis2_msg_ctx_get_soap_envelope(msg_ctx, env);
    if (!soap_envelope)
        return AXIS2_FAILURE;

    soap_header = axiom_soap_envelope_get_header(soap_envelope, env);
    if (!soap_header)
        return AXIS2_SUCCESS;

    header_block_ht = axiom_soap_header_get_all_header_blocks(soap_header, env);
    if (!header_block_ht)
        return AXIS2_SUCCESS;

    for (hash_index = axutil_hash_first(header_block_ht, env); hash_index;
            hash_index = axutil_hash_next(env, hash_index))
    {
        void *hb = NULL;
        axiom_soap_header_block_t *header_block = NULL;
        axis2_char_t *role = NULL;

        axutil_hash_this(hash_index, NULL, NULL, &hb);
        header_block = (axiom_soap_header_block_t *)hb;

        if (header_block)
        {
            if (axiom_soap_header_block_is_processed(header_block , env) ||
                    !axiom_soap_header_block_get_must_understand(header_block, env))
            {
                continue;
            }

            /* if this header block is not targeted to me then its not my
               problem. Currently this code only supports the "next" role; we
               need to fix this to allow the engine/service to be in one or more
               additional roles and then to check that any headers targeted for
               that role too have been dealt with. */
            role = axiom_soap_header_block_get_role(header_block, env);

            if ( axis2_msg_ctx_get_is_soap_11(msg_ctx, env) != AXIS2_TRUE)
            {
                /* SOAP 1.2 */
                if (!role || axutil_strcmp(role, AXIOM_SOAP12_SOAP_ROLE_NEXT) != 0)
                {
                    axiom_soap_envelope_t *temp_env =
                        axiom_soap_envelope_create_default_soap_fault_envelope(env,
                                "soapenv:MustUnderstand",
                                "Header not understood",
                                AXIOM_SOAP12, NULL, NULL);
                     axis2_msg_ctx_set_fault_soap_envelope(msg_ctx, env, temp_env);
                     axis2_msg_ctx_set_wsa_action(msg_ctx, env,
                            "http://www.w3.org/2005/08/addressing/fault");
                    return AXIS2_FAILURE;
                }
            }
            else
            {
                /* SOAP 1.1 */
                if (!role || axutil_strcmp(role, AXIOM_SOAP11_SOAP_ACTOR_NEXT) != 0)
                {
                    axiom_soap_envelope_t *temp_env =
                        axiom_soap_envelope_create_default_soap_fault_envelope(env,
                                "soapenv:MustUnderstand",
                                "Header not understood",
                                AXIOM_SOAP11, NULL, NULL);
                     axis2_msg_ctx_set_fault_soap_envelope(msg_ctx, env, temp_env);
                     axis2_msg_ctx_set_wsa_action(msg_ctx, env,
                            "http://www.w3.org/2005/08/addressing/fault");
                    return AXIS2_FAILURE;
                }

            }

        }
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_engine_resume_receive(
    axis2_engine_t *engine,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    axis2_status_t status = AXIS2_FAILURE;
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_conf_t *conf = NULL;
    axutil_array_list_t *phases = NULL;

    AXIS2_LOG_TRACE(env->log, AXIS2_LOG_SI, "Start:axis2_engine_resume_receive");
    /* find and invoke the phases */
    conf_ctx =  axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
    conf =  axis2_conf_ctx_get_conf(conf_ctx, env);
    phases =
         axis2_conf_get_in_phases_upto_and_including_post_dispatch(conf, env);

    axis2_engine_resume_invocation_phases(engine, env, phases, msg_ctx);
    /* invoking the message receiver */
    if ( axis2_msg_ctx_get_server_side(msg_ctx, env) && 
         !axis2_msg_ctx_is_paused(msg_ctx, env))
    {
        /* invoke the message receivers */
        axis2_op_ctx_t *op_ctx = NULL;

        status = 
            axis2_engine_check_must_understand_headers(env, msg_ctx);

        if (status != AXIS2_SUCCESS)
            return status;

        op_ctx =  axis2_msg_ctx_get_op_ctx(msg_ctx, env);
        if (op_ctx)
        {
            axis2_op_t *op =  axis2_op_ctx_get_op(op_ctx, env);
            if (op)
            {
                axis2_msg_recv_t *receiver = NULL;
                receiver = axis2_op_get_msg_recv(op, env);
                if (!receiver)
                {
                    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
                        "Message receiver not set in operation description");
                    return AXIS2_FAILURE;
                }
                status = axis2_msg_recv_receive(receiver, env, msg_ctx, 
                    axis2_msg_recv_get_derived(receiver, env));
            }
        }
    }
    AXIS2_LOG_TRACE(env->log, AXIS2_LOG_SI, "Exit:axis2_engine_resume_receive");
    return status;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_engine_resume_send(
    axis2_engine_t *engine,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    axis2_op_ctx_t *op_ctx = NULL;
    axutil_array_list_t *phases = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    AXIS2_LOG_TRACE(env->log, AXIS2_LOG_SI, "Start:axis2_engine_resume_send");
    /* invoke the phases */
    op_ctx =  axis2_msg_ctx_get_op_ctx(msg_ctx, env);
    if (op_ctx)
    {
        axis2_op_t *op =  axis2_op_ctx_get_op(op_ctx, env);
        if (op)
        {
            phases = axis2_op_get_out_flow(op, env);
        }
    }
    axis2_engine_resume_invocation_phases(engine, env, phases, msg_ctx);

    /* invoking transport sender */
    if (!axis2_msg_ctx_is_paused(msg_ctx, env))
    {
        /* write the message to the wire */
        axis2_transport_out_desc_t *transport_out = NULL;
        axis2_transport_sender_t *sender = NULL;
        transport_out =  axis2_msg_ctx_get_transport_out_desc(msg_ctx, env);
        if (transport_out)
        {
            sender = axis2_transport_out_desc_get_sender(transport_out, env);
            if (sender)
            {
                status = AXIS2_TRANSPORT_SENDER_INVOKE(sender, env, msg_ctx);
            }
        }
    }
    AXIS2_LOG_TRACE(env->log, AXIS2_LOG_SI, "Exit:axis2_engine_resume_send");
    return status;
}
