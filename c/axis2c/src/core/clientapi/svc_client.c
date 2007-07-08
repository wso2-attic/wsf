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

#include <axis2_svc_client.h>
#include <axis2_phases_info.h>
#include <axis2_const.h>
#include <axutil_hash.h>
#include <axutil_uri.h>
#include "axis2_callback_recv.h"
#include <axiom_soap_const.h>
#include <axiom_soap_body.h>
#include <axiom_soap_header.h>
#include <axiom_util.h>
#include <axis2_listener_manager.h>
#include <axis2_module_desc.h>
#include <axutil_array_list.h>
#include <axis2_options.h>
#include <axis2_conf_init.h>
#include <platforms/axutil_platform_auto_sense.h>
#include <stdio.h>
#include <axutil_generic_obj.h>
#include <axis2_http_transport.h>
#include <neethi_util.h>
#include <axis2_policy_include.h>

struct axis2_svc_client
{
    axis2_svc_t *svc;

    axis2_conf_t *conf;

    axis2_conf_ctx_t *conf_ctx;

    axis2_svc_ctx_t *svc_ctx;

    axis2_options_t *options;

    axis2_options_t *override_options;

    axutil_array_list_t *headers;

    /** for receiving the async messages */
    axis2_callback_recv_t *callback_recv;

    axis2_listener_manager_t *listener_manager;

    axis2_op_client_t *op_client;

    axiom_soap_envelope_t *last_response_soap_envelope;

    axis2_bool_t last_response_has_fault;

};

static axis2_svc_t *
axis2_svc_client_create_annonymous_svc(axis2_svc_client_t *svc_client,
    const axutil_env_t *env);

static axis2_bool_t
axis2_svc_client_init_transports_from_conf_ctx(const axutil_env_t *env,
    axis2_svc_client_t *svc_client,
    axis2_conf_ctx_t *conf_ctx,
    const axis2_char_t *client_home);

static axis2_bool_t
axis2_svc_client_init_data(const axutil_env_t *env,
    axis2_svc_client_t *svc_client);

static axis2_bool_t
axis2_svc_client_fill_soap_envelope(const axutil_env_t *env,
    axis2_svc_client_t *svc_client,
    axis2_msg_ctx_t *msg_ctx,
    const axiom_node_t *payload);
    
AXIS2_EXTERN axis2_svc_client_t *AXIS2_CALL
axis2_svc_client_create(const axutil_env_t *env,
    const axis2_char_t *client_home)
{
    axis2_svc_client_t *svc_client = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    svc_client = axis2_svc_client_create_with_conf_ctx_and_svc(env, 
        client_home, NULL, NULL);

    if (!svc_client)
    {
        return NULL;
    }

    return svc_client;
}

AXIS2_EXTERN axis2_svc_client_t *AXIS2_CALL
axis2_svc_client_create_for_dynamic_invocation(const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    const axutil_uri_t *wsdl_uri,
    const axutil_qname_t *wsdl_svc_qname,
    const axis2_char_t *endpoint_name,
    const axis2_char_t *client_home)
{
    axis2_svc_client_t *svc_client = NULL;
    axis2_svc_grp_t *svc_grp = NULL;
    axis2_svc_grp_ctx_t *svc_grp_ctx = NULL;
    const axis2_char_t *svc_grp_name = NULL;
    axutil_hash_t *ops = NULL;
    const axis2_char_t *repos_path = NULL;
    axis2_char_t *wsdl_path = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    svc_client = AXIS2_MALLOC(env->allocator, sizeof(axis2_svc_client_t));
    if (!svc_client)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    svc_client->svc = NULL;
    svc_client->conf = NULL;
    svc_client->conf_ctx = NULL;
    svc_client->svc_ctx = NULL;
    svc_client->options = NULL;
    svc_client->override_options = NULL;
    svc_client->headers = NULL;
    svc_client->callback_recv = NULL;
    svc_client->listener_manager = NULL;
    svc_client->op_client = NULL;

    /** initialize private data to NULL, create options */
    if (!axis2_svc_client_init_data(env, svc_client))
    {
        axis2_svc_client_free(svc_client, env);
        return NULL;
    }

    /* the following method call will create the default conf_ctx if it is NULL */
    if (!axis2_svc_client_init_transports_from_conf_ctx(env, svc_client,
        conf_ctx, client_home))
    {
        axis2_svc_client_free(svc_client, env);
        return NULL;
    }

    svc_client->conf =  axis2_conf_ctx_get_conf(svc_client->conf_ctx, env);
    repos_path =  axis2_conf_get_repo(svc_client->conf, env);
    wsdl_path = axutil_strcat(env, repos_path, AXIS2_PATH_SEP_STR, "woden", NULL);

    svc_client->options = axis2_options_create(env);
    if (svc_client->svc)
    {
        axutil_hash_index_t *i = NULL;
        void *v = NULL;
        axis2_op_t *op = NULL;

        ops = axis2_svc_get_all_ops(svc_client->svc, env);
        for (i = axutil_hash_first(ops, env); i; i = axutil_hash_next(env, i))
        {
            axis2_phases_info_t * info = NULL;
            axutil_hash_this(i, NULL, NULL, &v);
            op = (axis2_op_t *) v;

            /* Setting operation phase */
            info =  axis2_conf_get_phases_info(svc_client->conf, env);
            axis2_phases_info_set_op_phases(info, env, op);
        }
    }
    else
    return AXIS2_FAILURE;

    /** add the service to the config context if it isn't in there already */
    if (! axis2_conf_get_svc(svc_client->conf, env,
        axis2_svc_get_name(svc_client->svc, env)))
    {
         axis2_conf_add_svc(svc_client->conf, env, svc_client->svc);
    }

    /** create a service context for myself: create a new service group
     context and then get the service context for myself as I'll need that
     later for stuff that I gotta do */
    svc_grp = axis2_svc_get_parent(svc_client->svc, env);
    if (!svc_grp)
    {
        return NULL;
    }

    svc_grp_ctx =  axis2_svc_grp_get_svc_grp_ctx(svc_grp, env,
        svc_client->conf_ctx);
    if (!svc_grp_ctx)
    {
        return NULL;
    }

    svc_grp_name =  axis2_svc_grp_get_name(svc_grp, env);
    if (!svc_grp_name)
    {
        return NULL; /* service group name is mandatory */
    }

    axis2_conf_ctx_register_svc_grp_ctx(svc_client->conf_ctx, env,
        svc_grp_name, svc_grp_ctx);

    svc_client->svc_ctx =  axis2_svc_grp_ctx_get_svc_ctx(svc_grp_ctx, env,
        axis2_svc_get_name(svc_client->svc, env));

    return svc_client;
}

AXIS2_EXTERN axis2_svc_client_t *AXIS2_CALL
axis2_svc_client_create_with_conf_ctx_and_svc(const axutil_env_t *env,
    const axis2_char_t *client_home,
    axis2_conf_ctx_t *conf_ctx,
    axis2_svc_t *svc)
{
    axis2_svc_client_t *svc_client = NULL;
    axis2_svc_grp_t *svc_grp = NULL;
    axis2_svc_grp_ctx_t *svc_grp_ctx = NULL;
    const axis2_char_t *svc_grp_name = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    svc_client = AXIS2_MALLOC(env->allocator, sizeof(axis2_svc_client_t));
    if (!svc_client)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    svc_client->svc = NULL;
    svc_client->conf = NULL;
    svc_client->conf_ctx = NULL;
    svc_client->svc_ctx = NULL;
    svc_client->options = NULL;
    svc_client->override_options = NULL;
    svc_client->headers = NULL;
    svc_client->callback_recv = NULL;
    svc_client->listener_manager = NULL;
    svc_client->op_client = NULL;
    svc_client->last_response_soap_envelope = NULL;
    svc_client->last_response_has_fault = AXIS2_FALSE;

    /** initialize private data to NULL, create options */
    if (!axis2_svc_client_init_data(env, svc_client))
    {
        axis2_svc_client_free(svc_client, env);
        return NULL;
    }

    /* the following method call will create the default conf_ctx if it is NULL */
    if (!axis2_svc_client_init_transports_from_conf_ctx(env, svc_client,
        conf_ctx, client_home))
    {
        axis2_svc_client_free(svc_client, env);
        return NULL;
    }

    svc_client->conf =  axis2_conf_ctx_get_conf(svc_client->conf_ctx, env);

    if (svc)
    {
        svc_client->svc = svc;
    }
    else
    {
        if (! (svc_client->svc = axis2_svc_client_create_annonymous_svc(
            svc_client, env)))
        {
            axis2_svc_client_free(svc_client, env);
            return NULL;
        }
    }

    /** add the service to the config context if it isn't in there already */
    if (! axis2_conf_get_svc(svc_client->conf, env,
        axis2_svc_get_name(svc_client->svc, env)))
    {
         axis2_conf_add_svc(svc_client->conf, env, svc_client->svc);
    }

    /** create a service context for myself: create a new service group
     context and then get the service context for myself as I'll need that
     later for stuff that I gotta do */
    svc_grp = axis2_svc_get_parent(svc_client->svc, env);
    if (!svc_grp)
    {
        return NULL;
    }

    svc_grp_ctx =  axis2_svc_grp_get_svc_grp_ctx(svc_grp, env,
        svc_client->conf_ctx);
    if (!svc_grp_ctx)
    {
        return NULL;
    }

    svc_grp_name =  axis2_svc_grp_get_name(svc_grp, env);
    if (!svc_grp_name)
    {
        return NULL; /* service group name is mandatory */
    }

    axis2_conf_ctx_register_svc_grp_ctx(svc_client->conf_ctx, env,
        svc_grp_name, svc_grp_ctx);

    svc_client->svc_ctx =  axis2_svc_grp_ctx_get_svc_ctx(svc_grp_ctx, env,
        axis2_svc_get_name(svc_client->svc, env));

    return svc_client;
}

AXIS2_EXTERN axis2_svc_t *AXIS2_CALL
axis2_svc_client_get_svc(const axis2_svc_client_t *svc_client,
    const axutil_env_t *env)
{
    return svc_client->svc;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_svc_client_set_options(axis2_svc_client_t *svc_client,
    const axutil_env_t *env,
    const axis2_options_t *options)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (svc_client->options)
    {
        axis2_options_free(svc_client->options, env);
    }
    svc_client->options = (axis2_options_t *)options;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN const axis2_options_t *AXIS2_CALL
axis2_svc_client_get_options(const axis2_svc_client_t *svc_client,
    const axutil_env_t *env)
{
    return svc_client->options;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_svc_client_set_override_options(axis2_svc_client_t *svc_client,
    const axutil_env_t *env,
    const axis2_options_t *override_options)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (svc_client->override_options)
    {
        axis2_options_free(svc_client->override_options, env);
    }

    svc_client->override_options = (axis2_options_t *)override_options;

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN const axis2_options_t *AXIS2_CALL
axis2_svc_client_get_override_options(const axis2_svc_client_t *svc_client,
    const axutil_env_t *env)
{
    return svc_client->override_options;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_svc_client_engage_module(axis2_svc_client_t *svc_client,
    const axutil_env_t *env,
    const axis2_char_t *module_name)
{
    axis2_module_desc_t *module = NULL;
    axutil_qname_t *mod_qname = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, module_name, AXIS2_FAILURE);

    mod_qname = axutil_qname_create(env, module_name, NULL, NULL);

    if (mod_qname)
    {
        module =  axis2_conf_get_module(svc_client->conf, env, mod_qname);

        axutil_qname_free(mod_qname, env);
        mod_qname = NULL;
    }
    else
    {
        return AXIS2_FAILURE;
    }

    if (module)
    {
        return axis2_svc_engage_module(svc_client->svc, env, module,
            svc_client->conf);
    }
    return AXIS2_FAILURE;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_svc_client_disengage_module(axis2_svc_client_t *svc_client,
    const axutil_env_t *env,
    const axis2_char_t *module_name)
{
    axis2_module_desc_t *module = NULL;
    axutil_qname_t *mod_qname = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, module_name, AXIS2_FAILURE);

    mod_qname = axutil_qname_create(env, module_name, NULL, NULL);
    if (mod_qname)
    {
        module =  axis2_conf_get_module(svc_client->conf, env, mod_qname);
        axutil_qname_free(mod_qname, env);
        mod_qname = NULL;
    }
    else
    {
        return AXIS2_FAILURE;
    }

    if (module)
    {
        return axis2_svc_disengage_module(svc_client->svc, env, module,
            svc_client->conf);
    }
    return AXIS2_FAILURE;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_svc_client_add_header(axis2_svc_client_t *svc_client,
    const axutil_env_t *env,
    axiom_node_t *header)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (!svc_client->headers)
    {
        svc_client->headers = axutil_array_list_create(env, 0);
        if (!svc_client->headers)
        {
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            return AXIS2_FAILURE;
        }
    }
    axutil_array_list_add(svc_client->headers, env, header);

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_svc_client_remove_all_headers(axis2_svc_client_t *svc_client,
    const axutil_env_t *env)
{
    int i = 0, size = 0;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (!svc_client->headers)
    {
        return AXIS2_FAILURE;
    }

    size = axutil_array_list_size(svc_client->headers, env);

    for (i = 0; i < size; i++)
    {
        axiom_node_t *node = NULL;
        node = axutil_array_list_get(svc_client->headers, env, i);

        if (node)
        {
            axiom_node_free_tree(node, env);
            node = NULL;
        }
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_svc_client_send_robust_with_op_qname(axis2_svc_client_t *svc_client,
    const axutil_env_t *env,
    const axutil_qname_t *op_qname,
    const axiom_node_t *payload)
{
    axis2_msg_ctx_t *msg_ctx = NULL;
    axis2_status_t status = AXIS2_FAILURE;
    axis2_bool_t qname_free_flag = AXIS2_FALSE;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (!op_qname)
    {
        op_qname = axutil_qname_create(env, AXIS2_ANON_ROBUST_OUT_ONLY_OP, NULL, NULL);
        qname_free_flag = AXIS2_TRUE;
    }

    msg_ctx = axis2_msg_ctx_create(env,
        axis2_svc_ctx_get_conf_ctx(svc_client->svc_ctx, env), NULL, NULL);
    if (!axis2_svc_client_fill_soap_envelope(env, svc_client, msg_ctx, payload))
    {
        return AXIS2_FAILURE;
    }

    if(!axis2_svc_client_create_op_client(svc_client, env, op_qname))
    {
        return AXIS2_FAILURE;
    }

    axis2_op_client_add_out_msg_ctx(svc_client->op_client, env, msg_ctx);
    status = axis2_op_client_execute(svc_client->op_client, env, AXIS2_TRUE);
    
    if (qname_free_flag)
    {
        axutil_qname_free((axutil_qname_t *) op_qname, env);
    }

    return status;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_svc_client_send_robust(axis2_svc_client_t *svc_client,
    const axutil_env_t *env,
    const axiom_node_t *payload)
{
    return axis2_svc_client_send_robust_with_op_qname(svc_client, env, NULL, payload);
}

AXIS2_EXTERN void AXIS2_CALL
axis2_svc_client_fire_and_forget_with_op_qname(axis2_svc_client_t *svc_client,
    const axutil_env_t *env,
    const axutil_qname_t *op_qname,
    const axiom_node_t *payload)
{
    axis2_op_client_t *op_client = NULL;
    axis2_msg_ctx_t *msg_ctx = NULL;
    axis2_bool_t qname_free_flag = AXIS2_FALSE;

    if (!env)
    {
        return;
    }

    if (!op_qname)
    {
        op_qname = axutil_qname_create(env, AXIS2_ANON_OUT_ONLY_OP, NULL, NULL);
        qname_free_flag = AXIS2_TRUE;
    }

    msg_ctx = axis2_msg_ctx_create(env,
       axis2_svc_ctx_get_conf_ctx(svc_client->svc_ctx, env), NULL, NULL);
    if (!axis2_svc_client_fill_soap_envelope(env, svc_client, msg_ctx, payload))
    {
        return;
    }

    if(!axis2_svc_client_create_op_client(svc_client, env, op_qname))
    {
        return;
    }

    axis2_op_client_add_out_msg_ctx(svc_client->op_client, env, msg_ctx);
    axis2_op_client_execute(op_client, env, AXIS2_FALSE);
    
    if (qname_free_flag)
    {
        axutil_qname_free((axutil_qname_t *) op_qname, env);
    }

    return;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_svc_client_fire_and_forget(axis2_svc_client_t *svc_client,
    const axutil_env_t *env,
    const axiom_node_t *payload)
{
    return axis2_svc_client_fire_and_forget_with_op_qname(svc_client, env, NULL,
        payload);
}

AXIS2_EXTERN axiom_node_t* AXIS2_CALL
axis2_svc_client_send_receive_with_op_qname(axis2_svc_client_t *svc_client,
    const axutil_env_t *env,
    const axutil_qname_t *op_qname,
    const axiom_node_t *payload)
{
    axiom_soap_envelope_t *soap_envelope = NULL;
    axiom_soap_body_t *soap_body = NULL;
    axiom_node_t *soap_node = NULL;
    axis2_op_t *op = NULL;
    axutil_param_t *param = NULL;
    axutil_uri_t *action_uri = NULL;
    axis2_char_t *action_str = NULL;
    axis2_bool_t qname_free_flag = AXIS2_FALSE;

    AXIS2_ENV_CHECK(env, NULL);

    svc_client->last_response_soap_envelope = NULL;
    svc_client->last_response_has_fault = AXIS2_FALSE;

    op = axis2_svc_get_op_with_qname(svc_client->svc, env, op_qname);
    if (op)
    {
        param = axis2_op_get_param(op, env, AXIS2_SOAP_ACTION);
        if (param)
        {
            action_uri = (axutil_uri_t *) axutil_param_get_value(param, env);
            action_str = axutil_uri_to_string(action_uri, env, AXIS2_URI_UNP_OMITUSERINFO);
            axis2_options_set_action(svc_client->options, env, action_str);
        }
    }

    if (!op_qname)
    {
        qname_free_flag = AXIS2_TRUE;
        op_qname = axutil_qname_create(env, AXIS2_ANON_OUT_IN_OP, NULL, NULL);
    }

    if (axis2_options_get_use_separate_listener(svc_client->options, env))
    {
        axis2_callback_t *callback = NULL;
        axis2_msg_ctx_t *msg_ctx = NULL;
        long index = 0;

        /* This means doing a Request-Response invocation using two channels.
        If the transport is a two way transport (e.g. http), only one channel is used
        (e.g. in http cases 202 OK is sent to say no response available).
        Axis2 gets blocked and return when the response is available. */

        callback = axis2_callback_create(env);
        if (!callback)
        {
            return NULL;
        }

        /* call two channel non blocking invoke to do the work and wait on the callback */
        axis2_svc_client_send_receive_non_blocking_with_op_qname(
            svc_client, env, op_qname, payload, callback);

        index = axis2_options_get_timeout_in_milli_seconds(svc_client->options, env) / 10;

        while (!(axis2_callback_get_complete(callback, env)))
        {
            /*wait till the response arrives*/
            if (index-- >= 0)
            {
                AXIS2_USLEEP(10000);
                msg_ctx = (axis2_msg_ctx_t *)axis2_op_client_get_msg_ctx(
                    svc_client->op_client, env,
                    AXIS2_WSDL_MESSAGE_LABEL_OUT);
                if (msg_ctx)
                {
                    axis2_msg_ctx_t *res_msg_ctx = axis2_op_client_receive(env, msg_ctx);
                    if (res_msg_ctx)
                    {
                        soap_envelope =  axis2_msg_ctx_get_soap_envelope(res_msg_ctx, env);
                        svc_client->last_response_soap_envelope = soap_envelope;
                        if (soap_envelope)
                        {
                            soap_body = axiom_soap_envelope_get_body(soap_envelope, env);

                            if (soap_body)
                            {
                                svc_client->last_response_has_fault = 
                                    axiom_soap_body_has_fault(soap_body, env);
                                soap_node = axiom_soap_body_get_base_node(soap_body, env);
                                if (soap_node)
                                {
                                    return axiom_node_get_first_element(soap_node, env);
                                }
                            }
                        }
                    }
                }

            }
            else
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_RESPONSE_TIMED_OUT, AXIS2_FAILURE);
                return NULL;
            }
        }

        soap_envelope = axis2_callback_get_envelope(callback, env);

        /* start of hack to get rid of memory leak */
        msg_ctx = axis2_msg_ctx_create(env,
            axis2_svc_ctx_get_conf_ctx(svc_client->svc_ctx, env), NULL, NULL);
        axis2_op_client_add_msg_ctx(svc_client->op_client, env, msg_ctx);

         axis2_msg_ctx_set_soap_envelope(msg_ctx, env, soap_envelope);
        /* end of hack to get rid of memory leak */

        /* process the result of the invocation */
        if (!soap_envelope)
        {
            if (axis2_callback_get_error(callback, env) != AXIS2_ERROR_NONE)
            {
                AXIS2_ERROR_SET(env->error, axis2_callback_get_error(callback, env), AXIS2_FAILURE);
                return NULL;
            }
        }
    }
    else
    {
        axis2_msg_ctx_t *res_msg_ctx = NULL;
        axis2_msg_ctx_t *msg_ctx = NULL;

        msg_ctx = axis2_msg_ctx_create(env,
            axis2_svc_ctx_get_conf_ctx(svc_client->svc_ctx, env), NULL, NULL);
        if (!axis2_svc_client_fill_soap_envelope(env, svc_client, msg_ctx,
            payload))
        {
            return NULL;
        }

        if(!axis2_svc_client_create_op_client(svc_client, 
            env, op_qname))
        {
            return NULL;
        }

        axis2_op_client_add_msg_ctx(svc_client->op_client, env, msg_ctx);
        axis2_op_client_execute(svc_client->op_client, env, AXIS2_TRUE);
        res_msg_ctx = (axis2_msg_ctx_t *)axis2_op_client_get_msg_ctx(
            svc_client->op_client, env, AXIS2_WSDL_MESSAGE_LABEL_IN);

        if (res_msg_ctx)
        {
            soap_envelope =  axis2_msg_ctx_get_soap_envelope(res_msg_ctx, env);
        }
        else
        {
            axis2_op_client_add_msg_ctx(svc_client->op_client, env, 
                res_msg_ctx); /* set in msg_ctx to be NULL to reset */
        }
    }

    if (qname_free_flag)
    {
        axutil_qname_free((axutil_qname_t *) op_qname, env);
    }

    if (!soap_envelope)
    {
        return NULL;
    }
    svc_client->last_response_soap_envelope = soap_envelope;

    soap_body = axiom_soap_envelope_get_body(soap_envelope, env);

    if (!soap_body)
    {
        axiom_node_t *node =  axiom_soap_envelope_get_base_node(soap_envelope, env);
        if (node)
        {
            axiom_element_t *envelope_element = 
                (axiom_element_t*) axiom_node_get_data_element(node, env);
            axiom_util_get_first_child_element_with_localname(envelope_element,     
                env, node, AXIOM_SOAP_BODY_LOCAL_NAME, &soap_node);
            if (soap_node){
                return axiom_node_get_first_element(soap_node, env);
            }
        }
        return NULL;
    }

    svc_client->last_response_has_fault = 
        axiom_soap_body_has_fault(soap_body, env);                                

	if (AXIOM_SOAP11 == axiom_soap_envelope_get_soap_version(soap_envelope, env))
	{
            axiom_soap_body_convert_fault_to_soap11(soap_body, env);
	}

    soap_node = axiom_soap_body_get_base_node(soap_body, env);
    if (!soap_node)
    {
        return NULL;
    }
    return axiom_node_get_first_element(soap_node, env);
}

AXIS2_EXTERN axiom_node_t *AXIS2_CALL
axis2_svc_client_send_receive(axis2_svc_client_t *svc_client,
    const axutil_env_t *env,
    const axiom_node_t *payload)
{
    return axis2_svc_client_send_receive_with_op_qname(svc_client, env, NULL,
        payload);
}

AXIS2_EXTERN void AXIS2_CALL
axis2_svc_client_send_receive_non_blocking_with_op_qname(axis2_svc_client_t *svc_client,
    const axutil_env_t *env,
    const axutil_qname_t *op_qname,
    const axiom_node_t *payload,
    axis2_callback_t *callback)
{
    axis2_msg_ctx_t *msg_ctx = NULL;
    AXIS2_TRANSPORT_ENUMS transport_in_protocol;
    axis2_bool_t qname_free_flag = AXIS2_FALSE;

    if (!op_qname)
    {
        op_qname = axutil_qname_create(env, AXIS2_ANON_OUT_IN_OP, NULL, NULL);
        qname_free_flag = AXIS2_TRUE;
    }

    msg_ctx = axis2_msg_ctx_create(env,
        axis2_svc_ctx_get_conf_ctx(svc_client->svc_ctx, env), NULL, NULL);
    if (!axis2_svc_client_fill_soap_envelope(env, svc_client, msg_ctx, payload))
    {
        return;
    }

    if(!axis2_svc_client_create_op_client(svc_client,
        env, op_qname))
    {
        return;
    }

    axis2_op_client_set_callback(svc_client->op_client, env, callback);
    axis2_op_client_add_out_msg_ctx(svc_client->op_client, env, msg_ctx);

    if (axis2_options_get_use_separate_listener(svc_client->options, env))
    {
        axis2_op_t *op = NULL;

        transport_in_protocol = axis2_options_get_transport_in_protocol(
           svc_client->options, env);
        axis2_listener_manager_make_sure_started(svc_client->listener_manager, env,
           transport_in_protocol, svc_client->conf_ctx);
        /* Following sleep is required to ensure the listner is ready to receive response.
           If it is missing, the response gets lost. - Samisa */
        AXIS2_USLEEP(1);

        op = axis2_svc_get_op_with_qname(svc_client->svc, env, op_qname);
        axis2_op_set_msg_recv(op, env,
            AXIS2_CALLBACK_RECV_GET_BASE(svc_client->callback_recv, env));
        axis2_op_client_set_callback_recv(svc_client->op_client, env,
            svc_client->callback_recv);
    }

    axis2_op_client_execute(svc_client->op_client, env, AXIS2_FALSE);
    
    if (qname_free_flag)
    {
        axutil_qname_free((axutil_qname_t *) op_qname, env);
        op_qname = NULL;
    }

    return;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_svc_client_send_receive_non_blocking(axis2_svc_client_t *svc_client,
    const axutil_env_t *env,
    const axiom_node_t *payload,
    axis2_callback_t *callback)
{
    return axis2_svc_client_send_receive_non_blocking_with_op_qname(svc_client,env, NULL,
        payload, callback);
}

AXIS2_EXTERN axis2_op_client_t *AXIS2_CALL
axis2_svc_client_create_op_client(axis2_svc_client_t *svc_client,
    const axutil_env_t *env,
    const axutil_qname_t *op_qname)
{
    axis2_op_t *op = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    op = axis2_svc_get_op_with_qname(svc_client->svc, env, op_qname);

    if (!op)
    {
        return NULL;
    }

    if (!(svc_client->op_client))
    {
        svc_client->op_client = axis2_op_client_create(env, op, svc_client->svc_ctx,
                svc_client->options);
    }

    /**
      If override options have been set, that means we need to make sure
      those options override the options of even the operation client. So,
      what we do is switch the parents around to make that work.
    */
    if (svc_client->override_options)
    {
        axis2_options_set_parent(svc_client->override_options, env,
            axis2_op_client_get_options(svc_client->op_client, env));
        axis2_op_client_set_options(svc_client->op_client, env,
            svc_client->override_options);
    }

    return svc_client->op_client;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_svc_client_finalize_invoke(axis2_svc_client_t *svc_client,
    const axutil_env_t *env)
{
    AXIS2_TRANSPORT_ENUMS transport_in_protocol;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    transport_in_protocol = axis2_options_get_transport_in_protocol(
        svc_client->options, env);

    if (svc_client->listener_manager)
    {
        return axis2_listener_manager_stop(svc_client->listener_manager,
            env, transport_in_protocol);
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN const axis2_endpoint_ref_t *AXIS2_CALL
axis2_svc_client_get_own_endpoint_ref(const axis2_svc_client_t *svc_client,
    const axutil_env_t *env,
    const axis2_char_t *transport)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    return NULL;
}

AXIS2_EXTERN const axis2_endpoint_ref_t *AXIS2_CALL
axis2_svc_client_get_target_endpoint_ref(const axis2_svc_client_t *svc_client,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    return NULL;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_svc_client_set_target_endpoint_ref(axis2_svc_client_t *svc_client,
    const axutil_env_t *env,
    axis2_endpoint_ref_t *target_endpoint_ref)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    return AXIS2_FAILURE;
}

AXIS2_EXTERN axis2_svc_ctx_t *AXIS2_CALL
axis2_svc_client_get_svc_ctx(const axis2_svc_client_t *svc_client,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    return svc_client->svc_ctx;
}

static axis2_bool_t
axis2_svc_client_init_transports_from_conf_ctx(const axutil_env_t *env,
    axis2_svc_client_t *svc_client,
    axis2_conf_ctx_t *conf_ctx,
    const axis2_char_t *client_home)
{

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    svc_client->conf_ctx = conf_ctx;
    if (!(svc_client->conf_ctx))
    {
        svc_client->conf_ctx = axis2_build_client_conf_ctx(env, client_home);
        if (!(svc_client->conf_ctx))
        {
            return AXIS2_FALSE;
        }
    }

    if (!(svc_client->listener_manager))
    {
        svc_client->listener_manager = axis2_listener_manager_create(env);
    }

    if (!(svc_client->listener_manager))
    {
        return AXIS2_FALSE;
    }

    return AXIS2_TRUE;
}

static axis2_bool_t
axis2_svc_client_init_data(const axutil_env_t *env,
    axis2_svc_client_t *svc_client)
{
    svc_client->svc = NULL;

    svc_client->conf_ctx = NULL;

    svc_client->svc_ctx = NULL;

    svc_client->options = axis2_options_create(env);
    if (!svc_client->options)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return AXIS2_FALSE;
    }

    svc_client->override_options = NULL;

    svc_client->headers = NULL;

    if (svc_client->callback_recv)
    {
        AXIS2_CALLBACK_RECV_FREE(svc_client->callback_recv, env);
        svc_client->callback_recv = NULL;
    }

    svc_client->callback_recv = axis2_callback_recv_create(env);
    if (!(svc_client->callback_recv))
    {
        axis2_svc_client_free(svc_client, env);
        return AXIS2_FALSE;
    }

    return AXIS2_TRUE;
}

static axis2_svc_t *
axis2_svc_client_create_annonymous_svc(axis2_svc_client_t *svc_client,
    const axutil_env_t *env)
{
    /**
     now add anonymous operations to the axis2 service for use with the
     shortcut client API. NOTE: We only add the ones we know we'll use
     later in the convenience API; if you use
     this constructor then you can't expect any magic!
    */
    axutil_qname_t *tmp_qname;
    axis2_svc_t *svc;
    axis2_op_t *op_out_in, *op_out_only, *op_robust_out_only;
    axis2_phases_info_t *info = NULL;

    tmp_qname = axutil_qname_create(env, AXIS2_ANON_SERVICE, NULL, NULL);

    if (!tmp_qname)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    svc = axis2_svc_create_with_qname(env, tmp_qname);

    if (!svc)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    axutil_qname_free(tmp_qname, env);

    tmp_qname = axutil_qname_create(env, AXIS2_ANON_OUT_IN_OP, NULL, NULL);

    if (!tmp_qname)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    op_out_in = axis2_op_create_with_qname(env, tmp_qname);
    axutil_qname_free(tmp_qname, env);


    tmp_qname = axutil_qname_create(env, AXIS2_ANON_OUT_ONLY_OP, NULL, NULL);

    if (!tmp_qname)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    op_out_only = axis2_op_create_with_qname(env, tmp_qname);
    axutil_qname_free(tmp_qname, env);

    tmp_qname = axutil_qname_create(env, AXIS2_ANON_ROBUST_OUT_ONLY_OP, NULL, NULL);

    if (!tmp_qname)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    op_robust_out_only = axis2_op_create_with_qname(env, tmp_qname);
    axutil_qname_free(tmp_qname, env);

    if (!op_out_in || !op_out_only || !op_robust_out_only)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        if (op_out_in)
        {
            axis2_op_free(op_out_in, env);
        }
        if (op_out_only)
        {
            axis2_op_free(op_out_only, env);
        }
        if (op_robust_out_only)
        {
            axis2_op_free(op_robust_out_only, env);
        }

        return NULL;
    }

    axis2_op_set_msg_exchange_pattern(op_out_in, env, AXIS2_MEP_URI_OUT_IN);
    axis2_op_set_msg_exchange_pattern(op_out_only, env, AXIS2_MEP_URI_OUT_ONLY);
    axis2_op_set_msg_exchange_pattern(op_robust_out_only, env, AXIS2_MEP_URI_ROBUST_OUT_ONLY);

    /* Setting operation phase */
    info =  axis2_conf_get_phases_info(svc_client->conf, env);
    axis2_phases_info_set_op_phases(info, env, op_out_in);
    axis2_phases_info_set_op_phases(info, env, op_out_only);
    axis2_phases_info_set_op_phases(info, env, op_robust_out_only);
    axis2_svc_add_op(svc, env, op_out_in);
    axis2_svc_add_op(svc, env, op_out_only);
    axis2_svc_add_op(svc, env, op_robust_out_only);
    return svc;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_svc_client_free(axis2_svc_client_t *svc_client,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (svc_client->svc)
    {
        axis2_svc_free(svc_client->svc, env);
    }

    if (svc_client->callback_recv)
    {
        AXIS2_CALLBACK_RECV_FREE(svc_client->callback_recv, env);
    }

    if (svc_client->op_client)
    {
        axis2_op_client_free(svc_client->op_client, env);
    }

    if (svc_client->options)
    {
        axis2_options_free(svc_client->options, env);
    }

    if (svc_client->listener_manager)
    {
        axis2_listener_manager_free(svc_client->listener_manager, env);
    }

    if (svc_client->conf_ctx)
    {
        axis2_conf_ctx_free(svc_client->conf_ctx, env);
    }

    AXIS2_FREE(env->allocator, svc_client);

    return;
}

static axis2_bool_t
axis2_svc_client_fill_soap_envelope(const axutil_env_t *env,
    axis2_svc_client_t *svc_client,
    axis2_msg_ctx_t *msg_ctx,
    const axiom_node_t *payload)
{
    const axis2_char_t *soap_version_uri;
    int soap_version;
    axiom_soap_envelope_t *envelope = NULL;

    soap_version_uri = axis2_options_get_soap_version_uri(svc_client->options, env);

    if (!soap_version_uri)
    {
        return AXIS2_FALSE;
    }

    if (axutil_strcmp(soap_version_uri, AXIOM_SOAP11_SOAP_ENVELOPE_NAMESPACE_URI) == 0)
    {
        soap_version = AXIOM_SOAP11;
    }
    else
    {
        soap_version = AXIOM_SOAP12;
    }


    envelope = axiom_soap_envelope_create_default_soap_envelope(env, soap_version);
    if (!envelope)
    {
        return AXIS2_FALSE;
    }

    if (svc_client->headers)
    {
        axiom_soap_header_t *soap_header = NULL;
        soap_header = axiom_soap_envelope_get_header(envelope, env);

        if (soap_header)
        {
            axiom_node_t *header_node = NULL;
            header_node = axiom_soap_header_get_base_node(soap_header, env);

            if (header_node)
            {
                int size = 0;
                int i = 0;
                size = axutil_array_list_size(svc_client->headers, env);
                for (i = 0; i < size; i++)
                {
                    axiom_node_t *node = NULL;
                    node = axutil_array_list_get(svc_client->headers, env, i);
                    if (node)
                    {
                        axiom_node_add_child(header_node, env, node);
                    }
                }
            }
        }
    }

    if (payload)
    {
        axiom_soap_body_t *soap_body = NULL;
        soap_body = axiom_soap_envelope_get_body(envelope, env);
        if (soap_body)
        {
            axiom_node_t *node = NULL;
            node = axiom_soap_body_get_base_node(soap_body, env);
            if (node)
            {
                axiom_node_add_child(node, env, (axiom_node_t *)payload);
            }
        }
    }

     axis2_msg_ctx_set_soap_envelope(msg_ctx, env, envelope);

    return AXIS2_TRUE;
}


AXIS2_EXTERN axis2_op_client_t *AXIS2_CALL
axis2_svc_client_get_op_client(const axis2_svc_client_t *svc_client,
    const axutil_env_t *env)
{
    return svc_client->op_client;
}

AXIS2_EXTERN axiom_soap_envelope_t *AXIS2_CALL
axis2_svc_client_get_last_response_soap_envelope(const axis2_svc_client_t *svc_client,
    const axutil_env_t *env)
{
    return svc_client->last_response_soap_envelope;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axis2_svc_client_get_last_response_has_fault(const axis2_svc_client_t *svc_client,
    const axutil_env_t *env)
{
    return svc_client->last_response_has_fault;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_svc_client_set_proxy(axis2_svc_client_t *svc_client,
    const axutil_env_t *env,
    axis2_char_t *proxy_host,
    axis2_char_t *proxy_port)
{
    axis2_transport_out_desc_t *trans_desc = NULL;
    axis2_conf_t *conf = NULL;
    axutil_param_container_t *param_container;
    axutil_param_t *param;
    axis2_char_t *proxy = AXIS2_HTTP_PROXY_API;
    axutil_hash_t *attribute;
    axutil_generic_obj_t *host_obj = NULL;
    axutil_generic_obj_t *port_obj = NULL;
    axiom_attribute_t *host_attr = NULL;
    axiom_attribute_t *port_attr = NULL;

    AXIS2_PARAM_CHECK(env->error, proxy_host, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, proxy_port, AXIS2_FAILURE);
    
    if (svc_client->conf)
    {
        conf = svc_client->conf;
        trans_desc =  axis2_conf_get_transport_out(conf, env, AXIS2_TRANSPORT_ENUM_HTTP);
        if (! trans_desc)
        {
            return AXIS2_FAILURE;
        }
        param_container = axis2_transport_out_desc_param_container (trans_desc, env);
        param = axutil_param_create (env, proxy, (void *)NULL);

        if (!param)
        {
            return AXIS2_FAILURE;
        }

        attribute = axutil_hash_make (env);
        host_obj = axutil_generic_obj_create(env);
        port_obj  = axutil_generic_obj_create(env);
        host_attr = axiom_attribute_create(env, proxy_host, NULL, NULL);
        port_attr = axiom_attribute_create(env, proxy_port, NULL,  NULL); 
        axutil_generic_obj_set_value(host_obj, env, host_attr);
        axutil_generic_obj_set_value(port_obj, env, port_attr);

        axutil_hash_set (attribute, AXIS2_HTTP_PROXY_HOST, AXIS2_HASH_KEY_STRING, host_obj);
        axutil_hash_set (attribute, AXIS2_HTTP_PROXY_PORT, AXIS2_HASH_KEY_STRING, port_obj);
        axutil_param_set_attributes (param, env, attribute);
        axutil_param_container_add_param (param_container, env, param);

    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_svc_client_set_policy_from_om(axis2_svc_client_t *svc_client,
    const axutil_env_t *env,
    axiom_node_t *root_node)
{

    neethi_policy_t *neethi_policy = NULL;

    neethi_policy = neethi_util_create_policy_from_om(env, root_node);

    if(neethi_policy)
    {
        return axis2_svc_client_set_policy(svc_client, env, neethi_policy);
    }
    else
    {
        return AXIS2_FAILURE;
    }
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_svc_client_set_policy(axis2_svc_client_t *svc_client,
    const axutil_env_t *env,
    neethi_policy_t *policy)
{

    axis2_svc_t *svc = NULL;
    axis2_desc_t *desc = NULL;
    axis2_policy_include_t *policy_include = NULL;

    svc = axis2_svc_client_get_svc(svc_client, env);

    if(!svc)
    {
        return AXIS2_FAILURE;
    }

    desc = axis2_svc_get_base(svc, env);
    if(!desc)
    {
        return AXIS2_FAILURE;
    }

    policy_include = axis2_desc_get_policy_include(desc, env);
    if(!policy_include)
    {
        return AXIS2_FAILURE;
    }
    axis2_policy_include_add_policy_element(policy_include, env, AXIS2_SERVICE_POLICY, policy);
    return AXIS2_SUCCESS;
}

