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

#include "axis2_disp_checker.h"
#include <axis2_handler_desc.h>
#include <axutil_string.h>
#include <axis2_relates_to.h>
#include <axis2_svc.h>
#include <axis2_const.h>
#include <axis2_msg_ctx.h>
#include <axis2_op_ctx.h>
#include <axis2_svc_ctx.h>
#include <axis2_endpoint_ref.h>
#include <axiom_soap.h>
#include <axiom.h>

const axis2_char_t *AXIS2_DISP_CHECKER_NAME = "dispatch_post_conditions_evaluator";

struct axis2_disp_checker
{
    /** base class, inherits from handler */
    axis2_handler_t *base;
    /** phase name */
    axutil_string_t *name;
};

axis2_status_t AXIS2_CALL
axis2_disp_checker_invoke(
    axis2_handler_t *handler,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx);


axis2_disp_checker_t *AXIS2_CALL
axis2_disp_checker_create(
    const axutil_env_t *env)
{
    axis2_disp_checker_t *disp_checker = NULL;
    axis2_handler_desc_t *handler_desc = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    disp_checker = AXIS2_MALLOC(env->allocator, sizeof(axis2_disp_checker_t));
    if (!disp_checker)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    disp_checker->name = NULL;
    disp_checker->base = NULL;

    /* create default name */
    disp_checker->name = axutil_string_create_const(env, 
        (axis2_char_t**)&AXIS2_DISP_CHECKER_NAME);

    if (!(disp_checker->name))
    {
        axis2_disp_checker_free(disp_checker, env);
        return NULL;
    }

    disp_checker->base = axis2_handler_create(env);
    if (!disp_checker->base)
    {
        axis2_disp_checker_free(disp_checker, env);
        return NULL;
    }
    axis2_handler_set_invoke(disp_checker->base, env, axis2_disp_checker_invoke);


    /* handler desc of base handler */
    handler_desc = axis2_handler_desc_create(env, disp_checker->name);
    if (!handler_desc)
    {
        axis2_disp_checker_free(disp_checker, env);
        return NULL;
    }

    axis2_handler_init(disp_checker->base, env, handler_desc);
    return disp_checker;
}

axis2_handler_t *AXIS2_CALL
axis2_disp_checker_get_base(
    const axis2_disp_checker_t *disp_checker,
    const axutil_env_t *env)
{
    return disp_checker->base;
}

axutil_string_t *AXIS2_CALL
axis2_disp_checker_get_name(
    const axis2_disp_checker_t *disp_checker,
    const axutil_env_t *env)
{
    return disp_checker->name;
}

axis2_status_t AXIS2_CALL
axis2_disp_checker_set_name(
    axis2_disp_checker_t *disp_checker,
    const axutil_env_t *env,
    const axutil_string_t *name)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (disp_checker->name)
    {
        axutil_string_free(disp_checker->name, env);
        disp_checker->name = NULL;
    }

    if (name)
    {
        disp_checker->name = axutil_string_clone((axutil_string_t *)name, env);
        if (!(disp_checker->name))
            return AXIS2_FAILURE;
    }

    return AXIS2_SUCCESS;
}

void AXIS2_CALL
axis2_disp_checker_free(
    axis2_disp_checker_t *disp_checker,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (disp_checker->name)
    {
        axutil_string_free(disp_checker->name, env);
    }

    AXIS2_FREE(env->allocator, disp_checker);

    return;
}

axis2_status_t AXIS2_CALL
axis2_disp_checker_invoke(
    axis2_handler_t *handler,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    axis2_op_t *op = NULL;
    axis2_op_ctx_t *op_ctx = NULL;
    axis2_svc_t *svc = NULL;
    axis2_svc_ctx_t *svc_ctx = NULL;
    axis2_endpoint_ref_t *endpoint_ref = NULL;
    const axis2_char_t *address = NULL;
	axiom_soap_fault_t *soap_fault;
	axiom_soap_envelope_t *soap_envelope;
	axiom_soap_body_t *soap_body;
	int soap_version = AXIOM_SOAP12;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);

    /*if is client side, no point in proceeding*/
    if (!(axis2_msg_ctx_get_server_side(msg_ctx, env))) 
        return AXIS2_SUCCESS;

    op =  axis2_msg_ctx_get_op(msg_ctx, env);

    if (!op)
    {
        op_ctx =  axis2_msg_ctx_get_op_ctx(msg_ctx, env);
        if (op_ctx)
        {
            axis2_op_t *op =  axis2_op_ctx_get_op(op_ctx, env);
            if (op)
                 axis2_msg_ctx_set_op(msg_ctx, env, op);
        }
    }

    svc =  axis2_msg_ctx_get_svc(msg_ctx, env);

    if (!svc)
    {
        svc_ctx =  axis2_msg_ctx_get_svc_ctx(msg_ctx, env);
        if (svc_ctx)
        {
            axis2_svc_t *tsvc =  axis2_svc_ctx_get_svc(svc_ctx, env);
            if (tsvc)
                 axis2_msg_ctx_set_svc(msg_ctx, env, tsvc);
        }
    }
    endpoint_ref =  axis2_msg_ctx_get_to(msg_ctx, env);

    if (endpoint_ref)
        address = axis2_endpoint_ref_get_address(endpoint_ref, env);

    svc =  axis2_msg_ctx_get_svc(msg_ctx, env);
    if (!svc)
    {
        AXIS2_LOG_INFO(env->log, "Service Not found. Endpoint reference is : %s", (address) ? address : "NULL");
		if ( axis2_msg_ctx_get_is_soap_11 (msg_ctx, env))
		{
			soap_version = AXIOM_SOAP11;
		}
		soap_envelope = axiom_soap_envelope_create_default_soap_envelope (env, soap_version); 
		soap_body = axiom_soap_envelope_get_body(soap_envelope, env);
		soap_fault = axiom_soap_fault_create_default_fault (env, soap_body, "Receiver", "Service Not Found", soap_version);
		 axis2_msg_ctx_set_fault_soap_envelope(msg_ctx, env, soap_envelope);
        return AXIS2_FAILURE;
    }

    op =  axis2_msg_ctx_get_op(msg_ctx, env);
    if (!op)
    {
        AXIS2_LOG_INFO(env->log, "Operation Not found. Endpoint reference is : %s", (address) ? address : "NULL");
		soap_envelope = axiom_soap_envelope_create_default_soap_envelope (env, soap_version); 
		soap_body = axiom_soap_envelope_get_body(soap_envelope, env);
		soap_fault = axiom_soap_fault_create_default_fault (env, soap_body, "Receiver", "Operation Not Found", soap_version);
		 axis2_msg_ctx_set_fault_soap_envelope(msg_ctx, env, soap_envelope);
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}
