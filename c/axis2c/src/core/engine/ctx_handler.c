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


#include <axis2_handler_desc.h>
#include <axutil_string.h>
#include <axis2_svc.h>
#include <axis2_conf_ctx.h>

const axis2_char_t *AXIS2_CTX_HANDLER_NAME = "context_handler";

/**
 * By the time the control comes to this handler, the dispatching must have
 * happened so that the message context contains the service group, service and
 * operation. This will then try to find the contexts for service group, service
 * and the operation.
 */

axis2_status_t AXIS2_CALL
axis2_ctx_handler_invoke(
    axis2_handler_t *handler,
    const axutil_env_t *env,
    struct axis2_msg_ctx *msg_ctx);

axis2_handler_t *AXIS2_CALL
axis2_ctx_handler_create(
    const axutil_env_t *env,
    const axutil_string_t *string)
{
    axis2_handler_t *handler = NULL;
    axis2_handler_desc_t *handler_desc = NULL;
    axutil_string_t *handler_string = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    if (string)
    {
        handler_string = axutil_string_clone((axutil_string_t *)string, env);
        if (!(handler_string))
        {
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            return NULL;
        }
    }
    else
    {
        /* create default string */
        handler_string = axutil_string_create_const(env, (axis2_char_t**)&AXIS2_CTX_HANDLER_NAME);
        if (!handler_string)
        {
            return NULL;
        }
    }

    handler = axis2_handler_create(env);
    if (!handler)
    {
        return NULL;
    }

    /* handler desc of base handler */
    handler_desc = axis2_handler_desc_create(env, handler_string);
    axutil_string_free(handler_string, env);
    if (!handler_desc)
    {
        axis2_handler_free(handler, env);
        return NULL;
    }

    axis2_handler_init(handler, env, handler_desc);

    /* set the base struct's invoke op */
    axis2_handler_set_invoke(handler, env, axis2_ctx_handler_invoke);

    return handler;
}


axis2_status_t AXIS2_CALL
axis2_ctx_handler_invoke(
    axis2_handler_t *handler,
    const axutil_env_t *env,
    struct axis2_msg_ctx *msg_ctx)
{
    axis2_op_t *op = NULL;
    axis2_svc_ctx_t *svc_ctx = NULL;
    axis2_op_ctx_t *op_ctx = NULL;
    axis2_svc_grp_ctx_t *svc_grp_ctx = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);

    op_ctx =  axis2_msg_ctx_get_op_ctx(msg_ctx, env);
    svc_ctx =  axis2_msg_ctx_get_svc_ctx(msg_ctx, env);

    if (op_ctx && svc_ctx)
    {
        svc_grp_ctx = axis2_svc_ctx_get_parent(svc_ctx, env);
        if (svc_grp_ctx)
        {
            axutil_string_t *svc_grp_ctx_id_str = 
                axutil_string_create(env,  axis2_svc_grp_ctx_get_id(svc_grp_ctx, env));
             axis2_msg_ctx_set_svc_grp_ctx_id(msg_ctx, env, svc_grp_ctx_id_str);
            axutil_string_free(svc_grp_ctx_id_str, env);
        }
        return AXIS2_SUCCESS;
    }

    op =  axis2_msg_ctx_get_op(msg_ctx, env);
    if (op)
        op_ctx = axis2_op_find_existing_op_ctx(op, env, msg_ctx);

    if (op_ctx)
    {
        axis2_op_register_op_ctx(op, env, msg_ctx, op_ctx);
        svc_ctx =  axis2_op_ctx_get_parent(op_ctx, env);
        if (svc_ctx)
        {
            axutil_string_t *svc_grp_ctx_id_str = NULL;

            svc_grp_ctx = axis2_svc_ctx_get_parent(svc_ctx, env);
             axis2_msg_ctx_set_svc_ctx(msg_ctx, env, svc_ctx);
             axis2_msg_ctx_set_svc_grp_ctx(msg_ctx, env, svc_grp_ctx);

            svc_grp_ctx_id_str = axutil_string_create(env,  axis2_svc_grp_ctx_get_id(svc_grp_ctx, env));
             axis2_msg_ctx_set_svc_grp_ctx_id(msg_ctx, env, svc_grp_ctx_id_str);
            axutil_string_free(svc_grp_ctx_id_str, env);
        }
        return AXIS2_SUCCESS;
    }
    else if (op) /*  2. if no op_ctx, create new op_ctx */
    {
        axis2_conf_ctx_t *conf_ctx = NULL;
        axis2_bool_t use_pools = AXIS2_FALSE;
        axutil_param_t *param =  axis2_msg_ctx_get_parameter(msg_ctx, env,
            AXIS2_PERSIST_OP_CTX);

        use_pools = (param && 0 == axutil_strcmp(AXIS2_VALUE_TRUE,
                axutil_param_get_value(param, env)));
        if (use_pools)
        {
            axutil_allocator_switch_to_global_pool(env->allocator);
        }
        op_ctx = axis2_op_ctx_create(env, op, NULL);
        if (!op_ctx)
        {
            return AXIS2_FAILURE;
        }

        axis2_msg_ctx_set_op_ctx(msg_ctx, env, op_ctx);

        axis2_op_register_op_ctx(op, env, msg_ctx, op_ctx);

        conf_ctx =  axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
        if (conf_ctx)
        {
            if (!use_pools)
            {
                axutil_allocator_switch_to_global_pool(env->allocator);
            }
            
            svc_grp_ctx =  axis2_conf_ctx_fill_ctxs(conf_ctx, env, msg_ctx);

            if (!use_pools)
            {
                axutil_allocator_switch_to_local_pool(env->allocator);
            }
        }
        
        if (use_pools)
        {
            axutil_allocator_switch_to_local_pool(env->allocator);
        }
    }

    if (!svc_grp_ctx && (axis2_msg_ctx_get_server_side(msg_ctx, env)))
        return AXIS2_FAILURE;
    return AXIS2_SUCCESS;
}
