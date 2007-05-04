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
#include <axis2_msg_ctx.h>

const axis2_char_t *AXIS2_DISP_NAME = "abstract_dispatcher";

struct axis2_disp
{
    /** base class, inherits from handler */
    axis2_handler_t *base;
    /** phase name */
    axutil_string_t *name;
    /** derived struct */
    void* derived; /* deep copy */
    int derived_type;
};

axis2_disp_t *AXIS2_CALL
axis2_disp_create(
    const axutil_env_t *env,
    const axutil_string_t *name)
{
    axis2_disp_t *disp = NULL;
    axis2_handler_desc_t *handler_desc = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    disp = AXIS2_MALLOC(env->allocator, sizeof(axis2_disp_t));
    if (!disp)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    disp->name = NULL;
    disp->base = NULL;

    if (name)
    {
        disp->name = axutil_string_clone((axutil_string_t *)name, env);
        if (!(disp->name))
        {
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            axis2_disp_free(disp, env);
            return NULL;
        }
    }
    else
    {
        /* create default name */
        disp->name = axutil_string_create_const(env, (axis2_char_t**)&AXIS2_DISP_NAME);
        if (!(disp->name))
        {
            axis2_disp_free(disp, env);
            return NULL;
        }
    }

    disp->base = axis2_handler_create(env);
    if (!disp->base)
    {
        axis2_disp_free(disp, env);
        return NULL;
    }

    /* handler desc of base handler */
    handler_desc = axis2_handler_desc_create(env, disp->name);
    if (!handler_desc)
    {
        axis2_disp_free(disp, env);
        return NULL;
    }

    axis2_handler_init(disp->base, env, handler_desc);

    return disp;
}

axis2_handler_t *AXIS2_CALL
axis2_disp_get_base(
    const axis2_disp_t *disp,
    const axutil_env_t *env)
{
    return disp->base;
}

axutil_string_t *AXIS2_CALL
axis2_disp_get_name(
    const axis2_disp_t *disp,
    const axutil_env_t *env)
{
    return disp->name;
}

axis2_status_t AXIS2_CALL
axis2_disp_set_name(
    struct axis2_disp *disp,
    const axutil_env_t *env,
    axutil_string_t *name)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (disp->name)
    {
        axutil_string_free(disp->name, env);
    }

    if (name)
    {
        disp->name = axutil_string_clone(name, env);
        if (!(disp->name))
            return AXIS2_FAILURE;
    }

    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_disp_find_svc_and_op(
    struct axis2_handler *handler,
    const axutil_env_t *env,
    struct axis2_msg_ctx *msg_ctx)
{
    axis2_svc_t *axis_service = NULL;
    axis2_op_t *op = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);

    axis_service =  axis2_msg_ctx_get_svc(msg_ctx, env);

    if (!axis_service)
    {
        axis_service =  axis2_msg_ctx_find_svc(msg_ctx, env);
        if (axis_service)
        {
             axis2_msg_ctx_set_svc(msg_ctx, env, axis_service);
        }
    }
    op =  axis2_msg_ctx_get_op(msg_ctx, env);
    if (!op)
    {
        op =  axis2_msg_ctx_find_op(msg_ctx, env, axis_service);

        if (op)
        {
             axis2_msg_ctx_set_op(msg_ctx, env, op);
        }
    }

    return AXIS2_SUCCESS;
}

void AXIS2_CALL
axis2_disp_free(
    struct axis2_disp *disp,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);
    if (disp->name)
    {
        axutil_string_free(disp->name, env);
    }
    AXIS2_FREE(env->allocator, disp);
    return;
}

