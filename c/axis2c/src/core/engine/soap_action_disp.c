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


#include <axis2_disp.h>
#include <axis2_handler_desc.h>
#include <axutil_string.h>
#include <axis2_relates_to.h>
#include <axis2_svc.h>
#include <axis2_const.h>
#include <axis2_conf_ctx.h>
#include <axis2_addr.h>
#include <axutil_utils.h>

const axis2_char_t *AXIS2_SOAP_ACTION_DISP_NAME = "soap_action_based_dispatcher";

axis2_status_t AXIS2_CALL
axiom_soap_action_disp_invoke(
    axis2_handler_t *handler,
    const axutil_env_t *env,
    struct axis2_msg_ctx *msg_ctx);

axis2_svc_t *AXIS2_CALL
axiom_soap_action_disp_find_svc(
    axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env);

axis2_op_t *AXIS2_CALL
axiom_soap_action_disp_find_op(
    axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env,
    axis2_svc_t *svc);

axis2_disp_t *AXIS2_CALL
axiom_soap_action_disp_create(
    const axutil_env_t *env)
{
    axis2_disp_t *disp = NULL;
    axis2_handler_t *handler = NULL;
    axutil_string_t *name = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    name = axutil_string_create_const(env, 
                (axis2_char_t**)&AXIS2_SOAP_ACTION_DISP_NAME);

    disp = axis2_disp_create(env, name);
    if (!disp)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    handler = axis2_disp_get_base(disp, env);
    if (!handler)
    {
        AXIS2_ERROR_SET(env->error, 
             AXIS2_ERROR_INVALID_HANDLER_STATE, AXIS2_FAILURE);
        return NULL;
    }

    axis2_handler_set_invoke(handler, env, axiom_soap_action_disp_invoke);

    axutil_string_free(name, env);

    return disp;
}

axis2_svc_t *AXIS2_CALL
axiom_soap_action_disp_find_svc(axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env)
{
    AXIS2_LOG_DEBUG(env->log, 
         AXIS2_LOG_SI, "Checking for service using SOAPAction is not implemented");
    return NULL;
}

axis2_op_t *AXIS2_CALL
axiom_soap_action_disp_find_op(
    axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env,
    axis2_svc_t *svc)
{
    const axis2_char_t *action = NULL;
    axis2_op_t *op = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, svc, NULL);

    action = axutil_string_get_buffer(
                 axis2_msg_ctx_get_soap_action(msg_ctx, env), env);

    if (action)
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
                "Checking for operation using SOAPAction : %s", action);

        if (!op)
        {
            const axis2_char_t * op_name = NULL;
            op_name = axutil_rindex(action, '/');

            if (op_name)
            {
                op_name += 1;
            }
            else
            {
                op_name = action;
            }

            if (op_name)
            {
                op = axis2_svc_get_op_with_name(svc, env, op_name);
            }
        }

        if (op)
            AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "Operation found using SOAPAction");
    }
    return op;
}

axis2_status_t AXIS2_CALL
axiom_soap_action_disp_invoke(
    axis2_handler_t * handler,
    const axutil_env_t *env,
    struct axis2_msg_ctx *msg_ctx)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    axis2_msg_ctx_set_find_svc(msg_ctx, env, axiom_soap_action_disp_find_svc);
    axis2_msg_ctx_set_find_op(msg_ctx, env, axiom_soap_action_disp_find_op);

    return axis2_disp_find_svc_and_op(handler, env, msg_ctx);
}

