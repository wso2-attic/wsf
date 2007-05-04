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

#include <axis2_svc_grp_ctx.h>
#include <axis2_svc_grp.h>
#include <axis2_const.h>
#include <axutil_hash.h>

struct axis2_svc_grp_ctx
{
    /** base context struct */
    axis2_ctx_t *base;
    /** parent of service group context is a configuration context instance */
    struct axis2_conf_ctx *parent;
    /** service group context ID */
    axis2_char_t *id;
    /** map of service contexts belonging to this service context group */
    axutil_hash_t *svc_ctx_map;
    /** service group associated with this service group context */
    axis2_svc_grp_t *svc_grp;
    /** name of the service group associated with this context */
    axis2_char_t *svc_grp_name;
};

AXIS2_EXTERN axis2_svc_grp_ctx_t *AXIS2_CALL
axis2_svc_grp_ctx_create(
    const axutil_env_t *env,
    axis2_svc_grp_t *svc_grp,
    struct axis2_conf_ctx *conf_ctx)
{
    axis2_svc_grp_ctx_t *svc_grp_ctx = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    svc_grp_ctx = AXIS2_MALLOC(env->allocator, sizeof(axis2_svc_grp_ctx_t));
    if (!svc_grp_ctx)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    svc_grp_ctx->base = NULL;
    svc_grp_ctx->parent = NULL;
    svc_grp_ctx->id = NULL;
    svc_grp_ctx->svc_ctx_map = NULL;
    svc_grp_ctx->svc_grp = NULL;
    svc_grp_ctx->svc_grp_name = NULL;


    svc_grp_ctx->base = axis2_ctx_create(env);
    if (!(svc_grp_ctx->base))
    {
        axis2_svc_grp_ctx_free(svc_grp_ctx, env);
        return NULL;
    }

    if (svc_grp)
    {
        svc_grp_ctx->svc_grp = svc_grp;
        svc_grp_ctx->svc_grp_name = (axis2_char_t *) axis2_svc_grp_get_name(svc_grp_ctx->svc_grp, env);
    }

    if (conf_ctx)
    {
        svc_grp_ctx->parent = conf_ctx;
    }

    svc_grp_ctx->svc_ctx_map = axutil_hash_make(env);
    if (!(svc_grp_ctx->svc_ctx_map))
    {
        axis2_svc_grp_ctx_free(svc_grp_ctx, env);
        return NULL;
    }

    axis2_svc_grp_ctx_fill_svc_ctx_map((svc_grp_ctx), env);

    return svc_grp_ctx;
}

AXIS2_EXTERN axis2_ctx_t *AXIS2_CALL
axis2_svc_grp_ctx_get_base(
    const axis2_svc_grp_ctx_t *svc_grp_ctx,
    const axutil_env_t *env)
{
    return svc_grp_ctx->base;
}

AXIS2_EXTERN struct axis2_conf_ctx *AXIS2_CALL
            axis2_svc_grp_ctx_get_parent(
                const axis2_svc_grp_ctx_t *svc_grp_ctx,
                const axutil_env_t *env)
{
    return svc_grp_ctx->parent;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_svc_grp_ctx_free(
    struct axis2_svc_grp_ctx *svc_grp_ctx,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (svc_grp_ctx->id)
    {
        AXIS2_FREE(env->allocator, svc_grp_ctx->id);
    }

    if (svc_grp_ctx->base)
    {
         axis2_ctx_free(svc_grp_ctx->base, env);
    }

    if (svc_grp_ctx->svc_ctx_map)
    {
        axutil_hash_index_t *hi = NULL;
        void *val = NULL;
        for (hi = axutil_hash_first(svc_grp_ctx->svc_ctx_map, env);
                hi; hi = axutil_hash_next(env, hi))
        {
            axutil_hash_this(hi, NULL, NULL, &val);
            if (val)
            {
                axis2_svc_ctx_t *svc_ctx = NULL;
                svc_ctx = (axis2_svc_ctx_t *)val;
                 axis2_svc_ctx_free(svc_ctx, env);
            }
        }

        axutil_hash_free(svc_grp_ctx->svc_ctx_map, env);
        svc_grp_ctx->base = NULL;
    }

    AXIS2_FREE(env->allocator, svc_grp_ctx);

    return;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_svc_grp_ctx_init(
    struct axis2_svc_grp_ctx *svc_grp_ctx,
    const axutil_env_t *env,
    axis2_conf_t *conf)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (svc_grp_ctx->svc_grp_name)
    {
        svc_grp_ctx->svc_grp =
            axis2_conf_get_svc_grp(conf, env, svc_grp_ctx->svc_grp_name);
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
axis2_svc_grp_ctx_get_id(
    const axis2_svc_grp_ctx_t *svc_grp_ctx,
    const axutil_env_t *env)
{
    return svc_grp_ctx->id;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_svc_grp_ctx_set_id(
    struct axis2_svc_grp_ctx *svc_grp_ctx,
    const axutil_env_t *env,
    const axis2_char_t *id)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (svc_grp_ctx->id)
    {
        AXIS2_FREE(env->allocator, svc_grp_ctx->id);
        svc_grp_ctx->id = NULL;
    }

    if (id)
    {
        svc_grp_ctx->id = axutil_strdup(env, id);
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_svc_ctx_t *AXIS2_CALL
axis2_svc_grp_ctx_get_svc_ctx(
    const axis2_svc_grp_ctx_t *svc_grp_ctx,
    const axutil_env_t *env,
    const axis2_char_t *svc_name)
{
    return (axis2_svc_ctx_t *) axutil_hash_get(svc_grp_ctx->svc_ctx_map, svc_name, AXIS2_HASH_KEY_STRING);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_svc_grp_ctx_fill_svc_ctx_map(
    struct axis2_svc_grp_ctx *svc_grp_ctx,
    const axutil_env_t *env)
{
    axutil_hash_index_t *hi = NULL;
    void *next_svc = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_SUCCESS);

    if (svc_grp_ctx->svc_grp)
    {
        axutil_hash_t *service_map =  axis2_svc_grp_get_all_svcs(svc_grp_ctx->svc_grp, env);
        if (service_map)
        {
            for (hi = axutil_hash_first(service_map, env);
                    hi; hi = axutil_hash_next(env, hi))
            {
                axutil_hash_this(hi, NULL, NULL, &next_svc);
                if (next_svc)
                {
                    axis2_svc_t *svc = NULL;
                    axis2_svc_ctx_t *svc_ctx = NULL;
                    axis2_char_t *svc_name = NULL;
                    svc = (axis2_svc_t*) next_svc;
                    svc_ctx = axis2_svc_ctx_create(env, svc, svc_grp_ctx);
                    svc_name = axutil_qname_get_localpart(axis2_svc_get_qname(svc, env), env);
                    if (svc_name)
                        axutil_hash_set(svc_grp_ctx->svc_ctx_map, svc_name, AXIS2_HASH_KEY_STRING, svc_ctx);
                }
            }
        }
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_svc_grp_t *AXIS2_CALL
axis2_svc_grp_ctx_get_svc_grp(
    const axis2_svc_grp_ctx_t *svc_grp_ctx,
    const axutil_env_t *env)
{
    return svc_grp_ctx->svc_grp;
}

AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
axis2_svc_grp_ctx_get_svc_ctx_map(
    const axis2_svc_grp_ctx_t *svc_grp_ctx,
    const axutil_env_t *env)
{
    return svc_grp_ctx->svc_ctx_map;
}
