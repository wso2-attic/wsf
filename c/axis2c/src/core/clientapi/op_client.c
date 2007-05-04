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

#include <axis2_op_client.h>
#include <axis2_const.h>
#include <axutil_hash.h>
#include <axutil_uuid_gen.h>
#include <axis2_listener_manager.h>
#include <axis2_engine.h>
#include "axis2_callback_recv.h"
#include <axiom_xml_reader.h>
#include <axis2_core_utils.h>
#include <axiom_soap_envelope.h>
#include <axiom_soap_const.h>
#include <axiom_soap_body.h>
#include <axutil_types.h>
#include <platforms/axutil_platform_auto_sense.h>

struct axis2_op_client
{
    axis2_svc_ctx_t *svc_ctx;

    axis2_options_t *options;

    axis2_op_ctx_t *op_ctx;

    axis2_callback_t *callback;

    axis2_bool_t completed;
    /* to hold the locally created async result */
    axis2_async_result_t *async_result;
    axis2_callback_recv_t *callback_recv;

    /** message exchange pattern */
    axis2_char_t *mep;
    /** SOAP version URI */
    axis2_char_t *soap_version_uri;
    /** SOAP action */
    axutil_string_t *soap_action;
    /** WSA action  */
    axis2_char_t *wsa_action;

};


typedef struct axis2_op_client_worker_func_args
{
    const axutil_env_t *env;
    axis2_op_client_t *op_client;
    axis2_callback_t *callback;
    axis2_op_t *op;
    axis2_msg_ctx_t *msg_ctx;
}
axis2_op_client_worker_func_args_t;

void *AXIS2_THREAD_FUNC
axis2_op_client_worker_func(
    axutil_thread_t *thd,
    void *data);

static axis2_char_t *AXIS2_CALL
axis2_get_transport_from_url(
    const axis2_char_t *url,
    const axutil_env_t *env);

AXIS2_EXTERN axis2_op_client_t *AXIS2_CALL
axis2_op_client_create(const axutil_env_t *env, axis2_op_t *op,
    axis2_svc_ctx_t *svc_ctx,
    axis2_options_t *options)
{
    axis2_op_client_t *op_client = NULL;
    const axis2_char_t *mep_uri = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, op, NULL);
    AXIS2_PARAM_CHECK(env->error, svc_ctx, NULL);
    AXIS2_PARAM_CHECK(env->error, options, NULL);

    op_client = AXIS2_MALLOC(env->allocator, sizeof(axis2_op_client_t));
    if(!op_client)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    /** initialize data */
    op_client->svc_ctx = NULL;
    op_client->options = NULL;
    op_client->op_ctx = NULL;
    op_client->callback = NULL;
    op_client->completed = AXIS2_FALSE;
    op_client->async_result = NULL;
    op_client->callback_recv = NULL;

    op_client->options = options;
    op_client->svc_ctx = svc_ctx;

    op_client->mep = NULL;
    op_client->soap_version_uri = NULL;
    op_client->soap_action = NULL;
    op_client->wsa_action = NULL;

    op_client->op_ctx = axis2_op_ctx_create(env, op,
            op_client->svc_ctx);
    if(!(op_client->op_ctx))
    {
        axis2_op_client_free(op_client, env);
        return NULL;
    }

    mep_uri = axis2_op_get_msg_exchange_pattern(op, env);

    if(!mep_uri)
    {
        axis2_op_client_free(op_client, env);
        return NULL;
    }
    else
    {
        op_client->mep = axutil_strdup(env, mep_uri);
    }

    op_client->soap_version_uri = axutil_strdup(env, AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI);
    if (!(op_client->soap_version_uri))
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        axis2_op_client_free(op_client, env);
        return NULL;
    }

    /** initialize parser for thread safety */
    axiom_xml_reader_init();
    return op_client;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_client_set_options(axis2_op_client_t *op_client,
    const axutil_env_t *env,
    const axis2_options_t *options)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if(op_client->options)
    {
        axis2_options_free(op_client->options, env);
    }
    op_client->options = (axis2_options_t *)options;

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN const axis2_options_t *AXIS2_CALL
axis2_op_client_get_options(const axis2_op_client_t *op_client,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    return op_client->options;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_client_add_msg_ctx(axis2_op_client_t *op_client,
    const axutil_env_t *env,
    axis2_msg_ctx_t *mc)
{
    axis2_msg_ctx_t *out_msg_ctx = NULL, *in_msg_ctx = NULL;
    axis2_msg_ctx_t **msg_ctx_map = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    msg_ctx_map =  axis2_op_ctx_get_msg_ctx_map(op_client->op_ctx, env);

    out_msg_ctx = msg_ctx_map[AXIS2_WSDL_MESSAGE_LABEL_OUT];
    in_msg_ctx = msg_ctx_map[AXIS2_WSDL_MESSAGE_LABEL_IN];

    if(out_msg_ctx && in_msg_ctx)
    {
        /* may be this is the second invocation using the same service clinet,
           so reset */
        axis2_msg_ctx_free(out_msg_ctx, env);
        out_msg_ctx = NULL;
        msg_ctx_map[AXIS2_WSDL_MESSAGE_LABEL_OUT] = NULL;
        axis2_msg_ctx_free(in_msg_ctx, env);
        in_msg_ctx = NULL;
        msg_ctx_map[AXIS2_WSDL_MESSAGE_LABEL_IN] = NULL;
        axis2_op_ctx_set_complete(op_client->op_ctx, env, AXIS2_FALSE);
    }

    if(!out_msg_ctx)
    {
        msg_ctx_map[AXIS2_WSDL_MESSAGE_LABEL_OUT] = mc;
    }
    else
    {
        msg_ctx_map[AXIS2_WSDL_MESSAGE_LABEL_IN] = mc;
        axis2_op_ctx_set_complete(op_client->op_ctx, env, AXIS2_TRUE);
    }

    if(out_msg_ctx && !mc)
    {
        axutil_property_t *dump_property;
        axis2_char_t *dump_value = NULL;
        if(! axis2_msg_ctx_get_doing_rest(out_msg_ctx, env))
        {
            dump_property =  axis2_msg_ctx_get_property(out_msg_ctx, env,
                AXIS2_DUMP_INPUT_MSG_TRUE);
            if(dump_property)
	    {
                dump_value = (axis2_char_t *) axutil_property_get_value (
                    dump_property, env);
            }
	}
		
        if(axutil_strcmp(dump_value, AXIS2_VALUE_TRUE))
        {
            axis2_msg_ctx_free(out_msg_ctx, env);
            out_msg_ctx = NULL;
            msg_ctx_map[AXIS2_WSDL_MESSAGE_LABEL_OUT] = NULL;
        }
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_client_add_out_msg_ctx(axis2_op_client_t *op_client,
    const axutil_env_t *env,
    axis2_msg_ctx_t *mc)
{
    axis2_msg_ctx_t **msg_ctx_map = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    msg_ctx_map =  axis2_op_ctx_get_msg_ctx_map(op_client->op_ctx, env);

    msg_ctx_map[AXIS2_WSDL_MESSAGE_LABEL_OUT] = mc;

    return AXIS2_SUCCESS;
}



AXIS2_EXTERN const axis2_msg_ctx_t *AXIS2_CALL
axis2_op_client_get_msg_ctx(const axis2_op_client_t *op_client,
    const axutil_env_t *env,
    const axis2_wsdl_msg_labels_t message_label)
{
    return  axis2_op_ctx_get_msg_ctx(op_client->op_ctx, env, message_label);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_client_set_callback(axis2_op_client_t *op_client,
    const axutil_env_t *env,
    axis2_callback_t *callback)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if(op_client->callback)
    {
        axis2_callback_free(op_client->callback, env);
    }

    op_client->callback = callback;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_callback_t *AXIS2_CALL
axis2_op_client_get_callback(axis2_op_client_t *op_client,
    const axutil_env_t *env)
{
    return op_client->callback;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_client_execute(axis2_op_client_t *op_client,
    const axutil_env_t *env,
    const axis2_bool_t block)
{
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_msg_ctx_t *msg_ctx = NULL;

    axis2_transport_out_desc_t *transport_out = NULL;
    axis2_transport_in_desc_t *transport_in = NULL;

    axis2_status_t status = AXIS2_FAILURE;
    axis2_op_t *op = NULL;
    axis2_char_t *msg_id = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if(op_client->completed)
    {
        return AXIS2_FAILURE;
    }

    conf_ctx =  axis2_svc_ctx_get_conf_ctx(op_client->svc_ctx, env);

    msg_ctx = (axis2_msg_ctx_t *)axis2_op_client_get_msg_ctx(op_client, env,
            AXIS2_WSDL_MESSAGE_LABEL_OUT);

    if(!msg_ctx)
    {
        return AXIS2_FAILURE;
    }

     axis2_msg_ctx_set_options(msg_ctx, env, op_client->options);

    /**
     if the transport to use for sending is not specified, try to find it
     from the URL
    */
    transport_out = axis2_options_get_transport_out(op_client->options,
            env);
    if(!transport_out)
    {
        axis2_endpoint_ref_t *to_epr = NULL;
        axutil_property_t *property = NULL;
        property = axis2_options_get_property(op_client->options, env, 
            AXIS2_TARGET_EPR);
        if(property)
	{
            to_epr = axutil_property_get_value(property, env);
	}
        if(!to_epr)
	{
            to_epr = axis2_options_get_to(op_client->options, env);
	}
        if(!to_epr)
	{
            to_epr =  axis2_msg_ctx_get_to(msg_ctx, env);
	}
        transport_out = axis2_op_client_infer_transport(op_client, env, to_epr);
    }

    if(!transport_out)
    {
        return AXIS2_FAILURE;
    }

    if(!( axis2_msg_ctx_get_transport_out_desc(msg_ctx, env)))
    {
         axis2_msg_ctx_set_transport_out_desc(msg_ctx, env, transport_out);
    }


    transport_in = axis2_options_get_transport_in(op_client->options, env);
    if(!transport_in)
    {
        axis2_conf_ctx_t *conf_ctx =  axis2_svc_ctx_get_conf_ctx(op_client->svc_ctx, env);

        if(conf_ctx)
        {
            axis2_conf_t *conf =  axis2_conf_ctx_get_conf(conf_ctx, env);
            if(conf)
            {
                transport_in =  axis2_conf_get_transport_in(conf, env,
                    axis2_transport_out_desc_get_enum(transport_out, env));
            }
        }
    }

    if(!( axis2_msg_ctx_get_transport_in_desc(msg_ctx, env)))
    {
         axis2_msg_ctx_set_transport_in_desc(msg_ctx, env, transport_in);
    }

    op =  axis2_op_ctx_get_op(op_client->op_ctx, env);

    if(!op)
    {
        return AXIS2_FAILURE;
    }
    status = axis2_op_client_prepare_invocation(op_client, env, op, msg_ctx);
    if(status != AXIS2_SUCCESS)
    {
        return AXIS2_FAILURE;
    }
    msg_id = (axis2_char_t*)axutil_uuid_gen(env);
     axis2_msg_ctx_set_message_id(msg_ctx, env, msg_id);
    if(msg_id)
    {
        AXIS2_FREE(env->allocator, msg_id);
        msg_id = NULL;
    }

    if(axis2_options_get_use_separate_listener(op_client->options, env))
    {
        axis2_engine_t *engine = NULL;

        AXIS2_CALLBACK_RECV_ADD_CALLBACK(op_client->callback_recv, env,
            axis2_msg_ctx_get_msg_id(msg_ctx, env),
            op_client->callback);
         axis2_msg_ctx_set_op_ctx(msg_ctx, env, axis2_op_find_op_ctx(op, env,
                msg_ctx, op_client->svc_ctx));
         axis2_msg_ctx_set_svc_ctx(msg_ctx, env, op_client->svc_ctx);

        /* send the message */
        engine = axis2_engine_create(env, conf_ctx);
        if(!engine)
	{
            return AXIS2_FAILURE;
	}
        axis2_engine_send(engine, env, msg_ctx);
        axis2_engine_free(engine, env);
    }
    else
    {
        if(block)
        {
            axis2_msg_ctx_t *response_mc = NULL;
            
            axis2_msg_ctx_set_svc_ctx(msg_ctx, env, op_client->svc_ctx);
            axis2_msg_ctx_set_conf_ctx(msg_ctx, env,
                axis2_svc_ctx_get_conf_ctx(op_client->svc_ctx, env));
            axis2_msg_ctx_set_op_ctx(msg_ctx, env, op_client->op_ctx);


            /*Send the SOAP Message and receive a response */
            response_mc = axis2_op_client_two_way_send(env, msg_ctx);
            if(!response_mc)
            {
                const axis2_char_t *mep = axis2_op_get_msg_exchange_pattern(op, env);
                if(axutil_strcmp(mep, AXIS2_MEP_URI_OUT_ONLY) == 0 ||
                    axutil_strcmp(mep, AXIS2_MEP_URI_ROBUST_OUT_ONLY) == 0)
                {
                    if(env->error)
		    {
                        return env->error->status_code;
                    }
                    else
		    {
                        return AXIS2_FAILURE;
                    }
                }
                else
		{
                    return AXIS2_FAILURE;
		}
            }
            axis2_op_client_add_msg_ctx(op_client, env,
                response_mc);
        }
        else
        {
            axutil_thread_t *worker_thread = NULL;
            axis2_op_client_worker_func_args_t *arg_list = NULL;
            arg_list = AXIS2_MALLOC(env->allocator,
                sizeof(axis2_op_client_worker_func_args_t));
            if(! arg_list)
            {
                return AXIS2_FAILURE;
            }
            arg_list->env = env;
            arg_list->op_client = op_client;
            arg_list->callback = op_client->callback;
            arg_list->op = op;
            arg_list->msg_ctx = msg_ctx;
#ifdef AXIS2_SVR_MULTI_THREADED
            if(env->thread_pool)
            {
                worker_thread = axutil_thread_pool_get_thread(env->thread_pool,
                    axis2_op_client_worker_func, (void*)arg_list);
                if(! worker_thread)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Thread creation failed"
                        "call invoke non blocking");
                }
                axutil_thread_pool_thread_detach(env->thread_pool, worker_thread);
            }
            else
            {
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Thread pool not set in environment."
                    " Cannot invoke call non blocking");
            }
#else
            axis2_op_client_worker_func(NULL, (void*)arg_list);
#endif

        }
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_client_reset(axis2_op_client_t *op_client,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if(!op_client->completed)
        return AXIS2_FAILURE;

    op_client->completed = AXIS2_FALSE;

    op_client->op_ctx = NULL;

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_client_complete(axis2_op_client_t *op_client,
    const axutil_env_t *env, axis2_msg_ctx_t *mc)
{
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_listener_manager_t *listener_manager = NULL;
    AXIS2_TRANSPORT_ENUMS transport = AXIS2_TRANSPORT_ENUM_HTTP;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    conf_ctx =  axis2_msg_ctx_get_conf_ctx(mc, env);

    if(!conf_ctx)
        return AXIS2_FAILURE;

    if(!listener_manager)
        return AXIS2_FAILURE;

    return axis2_listener_manager_stop(listener_manager, env, transport);
}

AXIS2_EXTERN axis2_op_ctx_t *AXIS2_CALL
axis2_op_client_get_operation_context(const axis2_op_client_t *op_client,
    const axutil_env_t *env)
{
    return op_client->op_ctx;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_op_client_free(axis2_op_client_t *op_client,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if(op_client->callback)
    {
        axis2_callback_free(op_client->callback, env);
    }

    if(op_client->op_ctx)
    {
        axis2_op_ctx_free(op_client->op_ctx, env);
        op_client->op_ctx = NULL;
    }
    
    if (op_client->soap_version_uri)
    {
        AXIS2_FREE(env->allocator, op_client->soap_version_uri);
    }

    if (op_client->mep)
    {
        AXIS2_FREE(env->allocator, op_client->mep);
    }

	if(axis2_options_get_xml_parser_reset(op_client->options, env))
	{
        axiom_xml_reader_cleanup(); 
	}

    AXIS2_FREE(env->allocator, op_client);

    return;
}


void *AXIS2_THREAD_FUNC
axis2_op_client_worker_func(axutil_thread_t *thd,
    void *data)
{
    axis2_op_client_worker_func_args_t *args_list = NULL;
    axis2_op_ctx_t *op_ctx = NULL;
    axis2_msg_ctx_t *response = NULL;
    axutil_env_t *th_env = NULL;
    axutil_thread_pool_t *th_pool = NULL;

    args_list = (axis2_op_client_worker_func_args_t *) data;
    if(!args_list)
    {
        return NULL;
    }

    AXIS2_ENV_CHECK(args_list->env, AXIS2_FAILURE);
    th_env = axutil_init_thread_env(args_list->env);

    op_ctx = axis2_op_ctx_create(th_env, args_list->op, args_list->op_client->svc_ctx);
    if(!op_ctx)
    {
        return NULL;
    }
    axis2_msg_ctx_set_op_ctx(args_list->msg_ctx, th_env, op_ctx);
    axis2_msg_ctx_set_svc_ctx(args_list->msg_ctx, th_env, args_list->op_client->svc_ctx);

    /* send the request and wait for response */
    response = axis2_op_client_two_way_send(th_env, args_list->msg_ctx);

    axis2_op_client_add_msg_ctx(args_list->op_client, th_env, response);
    args_list->op_client->async_result = axis2_async_result_create(th_env, response);
    axis2_callback_invoke_on_complete(args_list->callback, th_env, args_list->op_client->async_result);
    axis2_callback_set_complete(args_list->callback, th_env, AXIS2_TRUE);

    /* clean up memory */
    axis2_async_result_free(args_list->op_client->async_result, th_env);
    
    axis2_op_ctx_free(op_ctx, th_env);
        
    th_pool = th_env->thread_pool;
    
    AXIS2_FREE(th_env->allocator, args_list);
    
    if(th_env)
    {
        axutil_free_thread_env(th_env);
        th_env = NULL;
    }
    axutil_thread_pool_exit_thread(th_pool, thd);
    return NULL;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_client_set_callback_recv(axis2_op_client_t *op_client,
    const axutil_env_t *env,
    axis2_callback_recv_t *callback_recv)
{
    op_client->callback_recv = callback_recv;
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axutil_string_t *AXIS2_CALL
axis2_op_client_get_soap_action(
    const axis2_op_client_t *op_client,
    const axutil_env_t *env)
{
    return op_client->soap_action;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_client_prepare_invocation(
    axis2_op_client_t *op_client,
    const axutil_env_t *env,
    axis2_op_t *op,
    axis2_msg_ctx_t *msg_ctx)
{
    axis2_svc_t *svc = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, op, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);

    /* make sure operation's MEP is the same as given MEP */
    if (op_client->mep)
    {
        if (axutil_strcmp(op_client->mep, axis2_op_get_msg_exchange_pattern(op, env)) != 0)
        {
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_MEP_MISMATCH_IN_MEP_CLIENT, AXIS2_FAILURE);
            return AXIS2_FAILURE;
        }
    }
    else
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_MEP_CANNOT_BE_NULL_IN_MEP_CLIENT, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    /* If operation has a parent service get it */
    svc = axis2_op_get_parent(op, env);
    if (svc)
    {
         axis2_svc_ctx_set_svc(op_client->svc_ctx, env, svc);
    }
    else
    {
        svc =  axis2_svc_ctx_get_svc(op_client->svc_ctx, env);
        if (svc)
        {
            axis2_op_t *temp_op = NULL;
            const axutil_qname_t *op_qname = axis2_op_get_qname(op, env);
            temp_op = axis2_svc_get_op_with_qname(svc, env, op_qname);
            if (!temp_op)
            {
                axis2_svc_add_op(svc, env, op);
            }
        }
    }

    if (op_client->wsa_action)
    {
         axis2_msg_ctx_set_wsa_action(msg_ctx, env, op_client->wsa_action);
    }

    if (op_client->soap_action)
    {
          axis2_msg_ctx_set_soap_action(msg_ctx, env, op_client->soap_action);
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_msg_ctx_t *AXIS2_CALL
axis2_op_client_prepare_soap_envelope(
    axis2_op_client_t *op_client,
    const axutil_env_t *env,
    axiom_node_t *to_send)
{
    axis2_msg_ctx_t *msg_ctx = NULL;
    axiom_soap_envelope_t *envelope = NULL;
    int soap_version = AXIOM_SOAP12;

    AXIS2_ENV_CHECK(env, NULL);

    if (op_client->svc_ctx)
    {
        msg_ctx = axis2_msg_ctx_create(env,
                 axis2_svc_ctx_get_conf_ctx(op_client->svc_ctx, env),
                 NULL, NULL);
    }

    if (!msg_ctx)
    {
        return NULL;
    }

    if (op_client->soap_version_uri)
    {
        if (axutil_strcmp(op_client->soap_version_uri,
                AXIOM_SOAP11_SOAP_ENVELOPE_NAMESPACE_URI) == 0)
            soap_version = AXIOM_SOAP11;
        else
            soap_version = AXIOM_SOAP12;
    }

    envelope = axiom_soap_envelope_create_default_soap_envelope(env, soap_version);
    if (!envelope)
    {
        return NULL;
    }

    if (to_send)
    {
        axiom_soap_body_t *soap_body = NULL;
        soap_body = axiom_soap_envelope_get_body(envelope, env);
        if (soap_body)
        {
            axiom_node_t *node = NULL;
            node = axiom_soap_body_get_base_node(soap_body, env);
            if (node)
            {
                axiom_node_add_child(node, env, to_send);
            }
        }
    }

    axis2_msg_ctx_set_soap_envelope(msg_ctx, env, envelope);

    return msg_ctx;
}

AXIS2_EXTERN axis2_transport_out_desc_t *AXIS2_CALL
axis2_op_client_infer_transport(
    axis2_op_client_t *op_client,
    const axutil_env_t *env,
    axis2_endpoint_ref_t *epr)
{
    axis2_char_t *transport = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    if (epr)
    {
        const axis2_char_t *to_url = axis2_endpoint_ref_get_address(epr, env);

        transport = axis2_get_transport_from_url(to_url, env);
    }

    if (transport)
    {
        axis2_conf_ctx_t *conf_ctx = NULL;
        axis2_conf_t *conf = NULL;
        axis2_transport_out_desc_t *transport_out_desc = NULL;
		AXIS2_TRANSPORT_ENUMS transport_enum = 0;
        
		if (!axutil_strcmp(transport, "http"))
		{
			transport_enum = AXIS2_TRANSPORT_ENUM_HTTP;
		}
		else if (!axutil_strcmp (transport, "https"))
		{
			transport_enum = AXIS2_TRANSPORT_ENUM_HTTPS;
		}

        conf_ctx =  axis2_svc_ctx_get_conf_ctx(op_client->svc_ctx, env);
        if (conf_ctx)
        {
            conf =  axis2_conf_ctx_get_conf(conf_ctx, env);
            if (conf)
            {
                transport_out_desc =  axis2_conf_get_transport_out(conf, env, transport_enum);
            }
        }

        AXIS2_FREE(env->allocator, transport);
        transport = NULL;
        return transport_out_desc;

    }

    AXIS2_ERROR_SET(env->error, AXIS2_ERROR_CANNOT_INFER_TRANSPORT, AXIS2_FAILURE);
    return NULL;
}

AXIS2_EXTERN axiom_soap_envelope_t *AXIS2_CALL
axis2_op_client_create_default_soap_envelope(
    axis2_op_client_t *op_client,
    const axutil_env_t *env)
{
    axiom_soap_envelope_t *envelope = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    if (axutil_strcmp(AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI, op_client->soap_version_uri) == 0)
    {
        envelope = axiom_soap_envelope_create_with_soap_version_prefix(env, AXIOM_SOAP12, NULL);
    }

    if (axutil_strcmp(AXIOM_SOAP11_SOAP_ENVELOPE_NAMESPACE_URI, op_client->soap_version_uri) == 0)
    {
        envelope = axiom_soap_envelope_create_with_soap_version_prefix(env, AXIOM_SOAP11, NULL);
    }
    return envelope;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_client_engage_module(
    axis2_op_client_t *op_client,
    const axutil_env_t *env,
    const axutil_qname_t *qname)
{
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_conf_t *conf = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (op_client->svc_ctx)
    {
        conf_ctx =  axis2_svc_ctx_get_conf_ctx(op_client->svc_ctx, env);
        if (conf_ctx)
        {
            conf =  axis2_conf_ctx_get_conf(conf_ctx, env);
            if (conf)
            {
                /*if it is already engaged do not engage it again*/
                if (!( axis2_conf_is_engaged(conf, env, qname)))
                {
                    return  axis2_conf_engage_module(conf, env, qname);
                }
            }
        }
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_client_set_soap_version_uri(
    axis2_op_client_t *op_client,
    const axutil_env_t *env,
    const axis2_char_t *soap_version_uri)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (op_client->soap_version_uri)
    {
        AXIS2_FREE(env->allocator, op_client->soap_version_uri);
        op_client->soap_version_uri = NULL;
    }

    if (soap_version_uri)
    {
        op_client->soap_version_uri = axutil_strdup(env, soap_version_uri);
        if (!(op_client->soap_version_uri))
        {
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            return AXIS2_FAILURE;
        }
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_client_set_soap_action(
    axis2_op_client_t *op_client,
    const axutil_env_t *env,
    axutil_string_t *soap_action)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (op_client->soap_action)
    {
        axutil_string_free(op_client->soap_action, env);
        op_client->soap_action = NULL;
    }

    if (soap_action)
    {
        op_client->soap_action = axutil_string_clone(soap_action, env);
        if (!(op_client->soap_action))
        {
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            return AXIS2_FAILURE;
        }
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_client_set_wsa_action(
    axis2_op_client_t *op_client,
    const axutil_env_t *env,
    const axis2_char_t *wsa_action)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (op_client->wsa_action)
    {
        AXIS2_FREE(env->allocator, op_client->wsa_action);
        op_client->wsa_action = NULL;
    }

    if (wsa_action)
    {
        op_client->wsa_action = axutil_strdup(env, wsa_action);
        if (!(op_client->wsa_action))
        {
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            return AXIS2_FAILURE;
        }
    }

    return AXIS2_SUCCESS;
}

static axis2_char_t *AXIS2_CALL
axis2_get_transport_from_url(
    const axis2_char_t *url,
    const axutil_env_t *env)
{
    axis2_char_t *transport = NULL;
    const axis2_char_t *start = NULL;
    const axis2_char_t *end = NULL;
    AXIS2_PARAM_CHECK(env->error, url, AXIS2_FAILURE);
    start = url;
    end = url;
    while (end && (*end) != ':')
        end++;

    if ((*end) == ':')
    {
        const axis2_char_t *c = NULL;
        transport = AXIS2_MALLOC(env->allocator, (end - start + 1) * sizeof(char));
        if (!transport)
        {
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            return NULL;
        }

        for (c = start; c < end; c++)
            transport[c - start] = *c;
        transport[c-start] = '\0';
    }

    return transport;
}

AXIS2_EXTERN axis2_svc_ctx_t *AXIS2_CALL
axis2_op_client_get_svc_ctx(
    const axis2_op_client_t *op_client,
    const axutil_env_t *env)
{
    return op_client->svc_ctx;
}


AXIS2_EXTERN axis2_msg_ctx_t *AXIS2_CALL
axis2_op_client_two_way_send(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    axis2_engine_t *engine = NULL;
    axis2_status_t status = AXIS2_SUCCESS;
    axis2_msg_ctx_t *response = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_op_t *op = NULL;
    axiom_soap_envelope_t *response_envelope = NULL;
    axutil_property_t *property = NULL;
    long index = -1;
    axis2_bool_t wait_indefinitely = AXIS2_FALSE;

    AXIS2_ENV_CHECK(env, NULL);

    conf_ctx =  axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
    engine = axis2_engine_create(env, conf_ctx);
    if (!engine)
        return NULL;
    property = axis2_msg_ctx_get_property(msg_ctx, env, AXIS2_TIMEOUT_IN_SECONDS);
    if(property)
    {
        axis2_char_t *value = axutil_property_get_value(property, env);
        if(value)
            index = AXIS2_ATOI(value);
        if(index == -1)
        {
            wait_indefinitely = AXIS2_TRUE;
            index = 1;
        }
    }

    status = axis2_engine_send(engine, env, msg_ctx);
    
     axis2_engine_free(engine, env);
    engine = NULL;
    
    if (status != AXIS2_SUCCESS)
        return NULL;

    op =  axis2_msg_ctx_get_op(msg_ctx, env);
    if (op)
    {
        /* handle one way case */
        const axis2_char_t *mep = axis2_op_get_msg_exchange_pattern(op, env);
        if (axutil_strcmp(mep, AXIS2_MEP_URI_OUT_ONLY) == 0 ||
            axutil_strcmp(mep, AXIS2_MEP_URI_ROBUST_OUT_ONLY) == 0)
        {
            return NULL;
        }
    }

    /* create the response */
    response = axis2_msg_ctx_create(env, conf_ctx,
             axis2_msg_ctx_get_transport_in_desc(msg_ctx, env),
             axis2_msg_ctx_get_transport_out_desc(msg_ctx, env));
    if (!response)
        return NULL;

    property =  axis2_msg_ctx_get_property(msg_ctx, env,AXIS2_TRANSPORT_IN);
    if (property)
    {
         axis2_msg_ctx_set_property(response, env, AXIS2_TRANSPORT_IN, property);
        property = NULL;
    }

    if (op)
    {
        axis2_op_register_op_ctx(op, env, response,  axis2_msg_ctx_get_op_ctx(msg_ctx, env));
    }
     axis2_msg_ctx_set_server_side(response, env, AXIS2_FALSE);
     axis2_msg_ctx_set_conf_ctx(response, env,  axis2_msg_ctx_get_conf_ctx(msg_ctx, env));
     axis2_msg_ctx_set_svc_grp_ctx(response, env,  axis2_msg_ctx_get_svc_grp_ctx(msg_ctx, env));

    /* If request is REST we assume the response is REST, so set the variable*/
     axis2_msg_ctx_set_doing_rest(response, env,  axis2_msg_ctx_get_doing_rest(msg_ctx, env));
	/* set response envelope */
    if (engine)
    {
         axis2_engine_free(engine, env);
        engine = NULL;
    }
 	response_envelope =  axis2_msg_ctx_get_response_soap_envelope (msg_ctx, env);
    if(response_envelope)
    {
        axis2_msg_ctx_set_soap_envelope(response, env, response_envelope);
        engine = axis2_engine_create(env, conf_ctx);
        if (engine)
        {
            status =  axis2_engine_receive(engine, env, response);
            if (status != AXIS2_SUCCESS)
                return NULL;
        }
    }
    else
    {
        while(!response_envelope && index > 0)
        {
            /*wait till the response arrives*/
            AXIS2_SLEEP(1);
            if(!wait_indefinitely)
                index--;
            response_envelope = axis2_msg_ctx_get_response_soap_envelope(
                msg_ctx, env);
        }
        /* if it is a two way message, then the status should be in error,
           else it is a one way message */
        if (response_envelope)
        {
            axis2_msg_ctx_set_soap_envelope(response, env, response_envelope);
            /* There could be a scenaria where the message has already passed
             * through the incoming phases. eg. Reliable Messaging 1.0 two
             * way single channel
             */
            property = axis2_msg_ctx_get_property(msg_ctx, env, 
                AXIS2_HANDLER_ALREADY_VISITED);
            if(property)
            {
                axis2_char_t *value = axutil_property_get_value(property, env);
                if(0 == axutil_strcmp(AXIS2_VALUE_TRUE, value))
                {
                    return response;
                }
            }
            engine = axis2_engine_create(env, conf_ctx);
            if (engine)
            {
                status =  axis2_engine_receive(engine, env, response);
                if (status != AXIS2_SUCCESS)
                    return NULL;
            }
        }
        else
        {
            if (AXIS2_ERROR_GET_STATUS_CODE(env->error) != AXIS2_SUCCESS)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_BLOCKING_INVOCATION_EXPECTS_RESPONSE, AXIS2_FAILURE);
                if (engine)
                {
                     axis2_engine_free(engine, env);
                    engine = NULL;
                }
                 axis2_msg_ctx_free(response, env);
                return NULL;
            }
        }
    }

    /* property is NULL, and we set null for AXIS2_TRANSPORT_IN in msg_ctx to
    avoid double free of this property */
     axis2_msg_ctx_set_property(msg_ctx, env, AXIS2_TRANSPORT_IN, property);

    if (engine)
    {
         axis2_engine_free(engine, env);
        engine = NULL;
    }
    return response;
}

AXIS2_EXTERN axis2_msg_ctx_t *AXIS2_CALL
axis2_op_client_receive(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    axis2_engine_t *engine = NULL;
    axis2_status_t status = AXIS2_SUCCESS;
    axis2_msg_ctx_t *response = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_op_t *op = NULL;
    axiom_soap_envelope_t *response_envelope = NULL;
    axutil_property_t *property = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    /* create the response */
    response = axis2_msg_ctx_create(env, conf_ctx,
             axis2_msg_ctx_get_transport_in_desc(msg_ctx, env),
             axis2_msg_ctx_get_transport_out_desc(msg_ctx, env));
    if (!response)
        return NULL;

    property =  axis2_msg_ctx_get_property(msg_ctx, env, AXIS2_TRANSPORT_IN);
    if (property)
    {
         axis2_msg_ctx_set_property(response, env, AXIS2_TRANSPORT_IN, property);
        property = NULL;
    }

    op =  axis2_msg_ctx_get_op(msg_ctx, env);
    if (op)
    {
        axis2_op_register_op_ctx(op, env, response,  axis2_msg_ctx_get_op_ctx(msg_ctx, env));
    }
     axis2_msg_ctx_set_server_side(response, env, AXIS2_FALSE);
     axis2_msg_ctx_set_conf_ctx(response, env,  axis2_msg_ctx_get_conf_ctx(msg_ctx, env));
     axis2_msg_ctx_set_svc_grp_ctx(response, env,  axis2_msg_ctx_get_svc_grp_ctx(msg_ctx, env));

    /* If request is REST we assume the response is REST, so set the variable*/
     axis2_msg_ctx_set_doing_rest(response, env,  axis2_msg_ctx_get_doing_rest(msg_ctx, env));

 	response_envelope =  axis2_msg_ctx_get_response_soap_envelope (msg_ctx, env);
    if (response_envelope)
    {
        axis2_msg_ctx_set_soap_envelope(response, env, response_envelope);
        if (engine)
        {
             axis2_engine_free(engine, env);
            engine = NULL;
        }

        engine = axis2_engine_create(env, conf_ctx);
        if (engine)
        {
            status =  axis2_engine_receive(engine, env, response);
            if (status != AXIS2_SUCCESS)
            {
                return NULL;
            }
        }

    }
    else
    {
        /* if it is a two way message, then the status should be in error,
           else it is a one way message */
        if (AXIS2_ERROR_GET_STATUS_CODE(env->error) != AXIS2_SUCCESS)
        {
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_BLOCKING_INVOCATION_EXPECTS_RESPONSE, AXIS2_FAILURE);
            return NULL;
        }
    }

    /* property is NULL, and we set null for AXIS2_TRANSPORT_IN in msg_ctx to
    avoid double free of this property */
     axis2_msg_ctx_set_property(msg_ctx, env, AXIS2_TRANSPORT_IN, property);

    if (engine)
    {
         axis2_engine_free(engine, env);
        engine = NULL;
    }
    return response;
}

