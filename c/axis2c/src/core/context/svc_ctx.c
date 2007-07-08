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

#include <axis2_svc_ctx.h>
#include <axis2_conf_ctx.h>
#include <axis2_const.h>
#include <axutil_hash.h>

struct axis2_svc_ctx
{
    /** base context struct */
    axis2_ctx_t *base;
    /** parent of op context is a service context instance */
    struct axis2_svc_grp_ctx *parent;
    /** service associated with this service context */
    axis2_svc_t *svc;
    /** id of the service associated with this context */
    axis2_char_t *svc_id;
    /** service qname */
    axutil_qname_t *svc_qname;
};

AXIS2_EXTERN axis2_svc_ctx_t *AXIS2_CALL
axis2_svc_ctx_create(
    const axutil_env_t *env,
    axis2_svc_t *svc,
    struct axis2_svc_grp_ctx *svc_grp_ctx)
{
    axis2_svc_ctx_t *svc_ctx = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    svc_ctx = AXIS2_MALLOC(env->allocator, sizeof(axis2_svc_ctx_t));
    if (!svc_ctx)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    svc_ctx->base = NULL;
    svc_ctx->parent = NULL;
    svc_ctx->svc = NULL;
    svc_ctx->svc_id = NULL;
    svc_ctx->svc_qname = NULL;

    svc_ctx->base = axis2_ctx_create(env);
    if (!(svc_ctx->base))
    {
        axis2_svc_ctx_free(svc_ctx, env);
        return NULL;
    }

    if (svc)
    {
        svc_ctx->svc = svc;
        svc_ctx->svc_qname = (axutil_qname_t *)axis2_svc_get_qname(svc, env);
        if (svc_ctx->svc_qname)
        {
            svc_ctx->svc_id = axutil_qname_get_localpart(svc_ctx->svc_qname, env);
        }
    }

    if (svc_grp_ctx)
    {
        svc_ctx->parent = svc_grp_ctx;
    }

    return svc_ctx;
}

axis2_ctx_t *AXIS2_CALL
axis2_svc_ctx_get_base(
    const axis2_svc_ctx_t *svc_ctx,
    const axutil_env_t *env)
{
    return svc_ctx->base;
}


struct axis2_svc_grp_ctx *AXIS2_CALL
            axis2_svc_ctx_get_parent(
                const axis2_svc_ctx_t *svc_ctx,
                const axutil_env_t *env)
{
    return svc_ctx->parent;
}

axis2_status_t AXIS2_CALL
            axis2_svc_ctx_set_parent(
                axis2_svc_ctx_t *svc_ctx,
                const axutil_env_t *env,
                axis2_svc_grp_ctx_t *parent)
{
    svc_ctx->parent = parent;
    return AXIS2_SUCCESS;
}

void AXIS2_CALL
axis2_svc_ctx_free(
    struct axis2_svc_ctx *svc_ctx,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (svc_ctx->base)
    {
         axis2_ctx_free(svc_ctx->base, env);
    }

    AXIS2_FREE(env->allocator, svc_ctx);
    return;
}

axis2_status_t AXIS2_CALL
axis2_svc_ctx_init(
    struct axis2_svc_ctx *svc_ctx,
    const axutil_env_t *env,
    axis2_conf_t *conf)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (svc_ctx->svc_qname)
    {
        axis2_char_t *svc_name = axutil_qname_get_localpart(svc_ctx->svc_qname, env);
        svc_ctx->svc = axis2_conf_get_svc(conf, env, svc_name);
    }

    return AXIS2_SUCCESS;
}

const axis2_char_t *AXIS2_CALL
axis2_svc_ctx_get_svc_id(
    const axis2_svc_ctx_t *svc_ctx,
    const axutil_env_t *env)
{
    return svc_ctx->svc_id;
}


axis2_svc_t *AXIS2_CALL
axis2_svc_ctx_get_svc(
    const axis2_svc_ctx_t *svc_ctx,
    const axutil_env_t *env)
{
    return svc_ctx->svc;
}

axis2_status_t AXIS2_CALL
axis2_svc_ctx_set_svc(
    axis2_svc_ctx_t *svc_ctx,
    const axutil_env_t *env,
    axis2_svc_t *svc)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, svc, AXIS2_FAILURE);

    svc_ctx->svc = svc;
    svc_ctx->svc_qname = (axutil_qname_t *)axis2_svc_get_qname(svc, env);
    if (svc_ctx->svc_qname)
    {
        svc_ctx->svc_id = axutil_qname_get_localpart(svc_ctx->
                svc_qname, env);
    }
    return AXIS2_SUCCESS;
}

struct axis2_conf_ctx *AXIS2_CALL
            axis2_svc_ctx_get_conf_ctx(
                const axis2_svc_ctx_t *svc_ctx,
                const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    return  axis2_svc_grp_ctx_get_parent(svc_ctx->parent, env);
}

axis2_op_ctx_t *AXIS2_CALL
axis2_svc_ctx_create_op_ctx(
    struct axis2_svc_ctx *svc_ctx,
    const axutil_env_t *env,
    const axutil_qname_t *qname)
{
    axis2_op_t *op = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    if (svc_ctx->svc)
    {
        op = axis2_svc_get_op_with_qname(svc_ctx->svc, env, qname);
        return axis2_op_ctx_create(env, op, svc_ctx);
    }

    return NULL;
}
