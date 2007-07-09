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

#include <axis2_conf_ctx.h>
#include <axis2_svc_grp.h>
#include <axis2_const.h>
#include <axutil_uuid_gen.h>

struct axis2_conf_ctx
{
    /** base context struct */
    axis2_ctx_t *base;
    /** engine configuration */
    axis2_conf_t *conf;
    /** root directory */
    /* should be handled as a URL string ? */
    axis2_char_t *root_dir;
    /**
     * axutil_hash_t *containing message ID to
     * operation context mapping.
     */
    axutil_hash_t *op_ctx_map;

    axutil_hash_t *svc_ctx_map;

    axutil_hash_t *svc_grp_ctx_map;

    /* Mutex to synchronize the read/write operations */
    axutil_thread_mutex_t *mutex;
};

AXIS2_EXTERN axis2_conf_ctx_t *AXIS2_CALL
axis2_conf_ctx_create(
    const axutil_env_t *env,
    axis2_conf_t *conf)
{
    axis2_conf_ctx_t *conf_ctx = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    conf_ctx = AXIS2_MALLOC(env->allocator, sizeof(axis2_conf_ctx_t));
    if (!conf_ctx)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    conf_ctx->base = NULL;
    conf_ctx->conf = NULL;
    conf_ctx->root_dir = NULL;
    conf_ctx->op_ctx_map = NULL;
    conf_ctx->svc_ctx_map = NULL;
    conf_ctx->svc_grp_ctx_map = NULL;
    conf_ctx->mutex = axutil_thread_mutex_create(env->allocator,
            AXIS2_THREAD_MUTEX_DEFAULT);
    if (!conf_ctx->mutex)
    {
        axis2_conf_ctx_free(conf_ctx, env);
        return NULL;
    }

    if (conf)
        conf_ctx->conf = conf;

    conf_ctx->base = axis2_ctx_create(env);
    if (!(conf_ctx->base))
    {
        axis2_conf_ctx_free(conf_ctx, env);
        return NULL;
    }

    conf_ctx->op_ctx_map = axutil_hash_make(env);
    if (!(conf_ctx->op_ctx_map))
    {
        axis2_conf_ctx_free(conf_ctx, env);
        return NULL;
    }

    conf_ctx->svc_ctx_map = axutil_hash_make(env);
    if (!(conf_ctx->svc_ctx_map))
    {
        axis2_conf_ctx_free(conf_ctx, env);
        return NULL;
    }

    conf_ctx->svc_grp_ctx_map = axutil_hash_make(env);
    if (!(conf_ctx->svc_grp_ctx_map))
    {
        axis2_conf_ctx_free(conf_ctx, env);
        return NULL;
    }

    return conf_ctx;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_conf_ctx_set_conf(
    axis2_conf_ctx_t *conf_ctx,
    const axutil_env_t *env,
    axis2_conf_t *conf)
{
    conf_ctx->conf = conf; /* we just maintain a shallow copy here */
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_ctx_t *AXIS2_CALL
axis2_conf_ctx_get_base(
    const axis2_conf_ctx_t *conf_ctx,
    const axutil_env_t *env)
{
    return conf_ctx->base;
}

AXIS2_EXTERN axis2_conf_t *AXIS2_CALL
axis2_conf_ctx_get_conf(
    const axis2_conf_ctx_t *conf_ctx,
    const axutil_env_t *env)
{
    return conf_ctx->conf;
}

AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
axis2_conf_ctx_get_op_ctx_map(
    const axis2_conf_ctx_t *conf_ctx,
    const axutil_env_t *env)
{
    return conf_ctx->op_ctx_map;
}

AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
axis2_conf_ctx_get_svc_ctx_map(
    const axis2_conf_ctx_t *conf_ctx,
    const axutil_env_t *env)
{
    return conf_ctx->svc_ctx_map;
}

AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
axis2_conf_ctx_get_svc_grp_ctx_map(
    const axis2_conf_ctx_t *conf_ctx,
    const axutil_env_t *env)
{
    return conf_ctx->svc_grp_ctx_map;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_conf_ctx_register_op_ctx(
    axis2_conf_ctx_t *conf_ctx,
    const axutil_env_t *env,
    const axis2_char_t *message_id,
    axis2_op_ctx_t *op_ctx)
{
    axutil_thread_mutex_lock(conf_ctx->mutex);
    if (conf_ctx->op_ctx_map)
    {
        axutil_hash_set(conf_ctx->op_ctx_map,
                message_id, AXIS2_HASH_KEY_STRING, op_ctx);
    }
    axutil_thread_mutex_unlock(conf_ctx->mutex);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_op_ctx_t *AXIS2_CALL
axis2_conf_ctx_get_op_ctx(
    const axis2_conf_ctx_t *conf_ctx,
    const axutil_env_t *env,
    const axis2_char_t *message_id)
{
    axis2_op_ctx_t *rv = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, message_id, NULL);

    axutil_thread_mutex_lock(conf_ctx->mutex);
    if (conf_ctx->op_ctx_map)
    {
        rv = (axis2_op_ctx_t*)axutil_hash_get(conf_ctx->op_ctx_map,
                message_id, AXIS2_HASH_KEY_STRING);
    }
    axutil_thread_mutex_unlock(conf_ctx->mutex);
    return rv;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_conf_ctx_register_svc_ctx(
    axis2_conf_ctx_t *conf_ctx,
    const axutil_env_t *env,
    const axis2_char_t *svc_id,
    axis2_svc_ctx_t *svc_ctx)
{
    axutil_thread_mutex_lock(conf_ctx->mutex);
    if (conf_ctx->svc_ctx_map)
    {
        axutil_hash_set(conf_ctx->svc_ctx_map,
                svc_id, AXIS2_HASH_KEY_STRING, svc_ctx);
    }
    axutil_thread_mutex_unlock(conf_ctx->mutex);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_svc_ctx_t *AXIS2_CALL
axis2_conf_ctx_get_svc_ctx(
    const axis2_conf_ctx_t *conf_ctx,
    const axutil_env_t *env,
    const axis2_char_t *svc_id)
{
    axis2_svc_ctx_t *rv = NULL;

    axutil_thread_mutex_lock(conf_ctx->mutex);
    if (conf_ctx->svc_ctx_map)
    {
        rv = (axis2_svc_ctx_t*)axutil_hash_get(conf_ctx->svc_ctx_map,
                svc_id, AXIS2_HASH_KEY_STRING);
    }
    axutil_thread_mutex_unlock(conf_ctx->mutex);
    return rv;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_conf_ctx_register_svc_grp_ctx(
    axis2_conf_ctx_t *conf_ctx,
    const axutil_env_t *env,
    const axis2_char_t *svc_grp_id,
    axis2_svc_grp_ctx_t *svc_grp_ctx)
{
    axutil_thread_mutex_lock(conf_ctx->mutex);
    if (conf_ctx->svc_grp_ctx_map)
    {
        axutil_hash_set(conf_ctx->svc_grp_ctx_map,
                svc_grp_id, AXIS2_HASH_KEY_STRING, svc_grp_ctx);
    }
    axutil_thread_mutex_unlock(conf_ctx->mutex);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_svc_grp_ctx_t *AXIS2_CALL
axis2_conf_ctx_get_svc_grp_ctx(
    const axis2_conf_ctx_t *conf_ctx,
    const axutil_env_t *env,
    const axis2_char_t *svc_grp_id)
{
    axis2_svc_grp_ctx_t *rv = NULL;
    axutil_thread_mutex_lock(conf_ctx->mutex);
    if (conf_ctx->svc_grp_ctx_map)
    {
        rv = (axis2_svc_grp_ctx_t*)axutil_hash_get(conf_ctx->svc_grp_ctx_map, 
            svc_grp_id, AXIS2_HASH_KEY_STRING);
    }
    axutil_thread_mutex_unlock(conf_ctx->mutex);
    return rv;
}

AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
axis2_conf_ctx_get_root_dir(
    const axis2_conf_ctx_t *conf_ctx,
    const axutil_env_t *env)
{
    axis2_char_t *rv = NULL;
    axutil_thread_mutex_lock(conf_ctx->mutex);
    rv = conf_ctx->root_dir;
    axutil_thread_mutex_unlock(conf_ctx->mutex);
    return rv;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_conf_ctx_set_root_dir(
    axis2_conf_ctx_t *conf_ctx,
    const axutil_env_t *env,
    const axis2_char_t *path)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    axutil_thread_mutex_lock(conf_ctx->mutex);
    if (conf_ctx->root_dir)
    {
        AXIS2_FREE(env->allocator, conf_ctx->root_dir);
        conf_ctx->root_dir = NULL;
    }

    if (path)
    {
        conf_ctx->root_dir = axutil_strdup(env, path);
        if (!(conf_ctx->root_dir))
        {
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            axutil_thread_mutex_unlock(conf_ctx->mutex);
            return AXIS2_FAILURE;
        }
    }
    axutil_thread_mutex_unlock(conf_ctx->mutex);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_conf_ctx_init(
    axis2_conf_ctx_t *conf_ctx,
    const axutil_env_t *env,
    axis2_conf_t *conf)
{
    axutil_hash_index_t *hi = NULL;
    void *ctx = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    axutil_thread_mutex_lock(conf_ctx->mutex);
    conf_ctx->conf = conf;

    for (hi = axutil_hash_first(conf_ctx->op_ctx_map, env);
            hi; hi = axutil_hash_next(env, hi))
    {
        axutil_hash_this(hi, NULL, NULL, &ctx);
        if (ctx)
        {
            axis2_op_ctx_t *op_ctx = (axis2_op_ctx_t*) ctx;
             axis2_op_ctx_init(op_ctx, env, conf);
        }
    }

    for (hi = axutil_hash_first(conf_ctx->svc_ctx_map, env);
            hi; hi = axutil_hash_next(env, hi))
    {
        axutil_hash_this(hi, NULL, NULL, &ctx);
        if (ctx)
        {
            axis2_svc_ctx_t *svc_ctx = (axis2_svc_ctx_t*) ctx;
             axis2_svc_ctx_init(svc_ctx, env, conf);
        }
    }

    for (hi = axutil_hash_first(conf_ctx->svc_grp_ctx_map, env);
            hi; hi = axutil_hash_next(env, hi))
    {
        axutil_hash_this(hi, NULL, NULL, &ctx);
        if (ctx)
        {
            axis2_svc_grp_ctx_t *svc_grp_ctx = (axis2_svc_grp_ctx_t*) ctx;
             axis2_svc_grp_ctx_init(svc_grp_ctx, env, conf);
        }
    }
    axutil_thread_mutex_unlock(conf_ctx->mutex);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_conf_ctx_free(
    axis2_conf_ctx_t *conf_ctx,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (conf_ctx->base)
    {
         axis2_ctx_free(conf_ctx->base, env);
    }

    if (conf_ctx->op_ctx_map)
    {
        axutil_hash_index_t *hi = NULL;
        void *val = NULL;
        for (hi = axutil_hash_first(conf_ctx->op_ctx_map, env); hi;
                hi = axutil_hash_next(env, hi))
        {
            axis2_op_ctx_t *op_ctx = NULL;
            axutil_hash_this(hi, NULL, NULL, &val);
            op_ctx = (axis2_op_ctx_t *) val;
            if (op_ctx)
                 axis2_op_ctx_free(op_ctx, env);
            val = NULL;
            op_ctx = NULL;

        }
        axutil_hash_free(conf_ctx->op_ctx_map, env);
    }

    if (conf_ctx->svc_ctx_map)
    {
        axutil_hash_index_t *hi = NULL;
        void *val = NULL;
        for (hi = axutil_hash_first(conf_ctx->svc_ctx_map, env); hi;
                hi = axutil_hash_next(env, hi))
        {
            axis2_svc_ctx_t *svc_ctx = NULL;
            axutil_hash_this(hi, NULL, NULL, &val);
            svc_ctx = (axis2_svc_ctx_t *) val;
            if (svc_ctx)
                 axis2_svc_ctx_free(svc_ctx, env);

            val = NULL;
            svc_ctx = NULL;

        }
        axutil_hash_free(conf_ctx->svc_ctx_map, env);
    }

    if (conf_ctx->svc_grp_ctx_map)
    {
        axutil_hash_index_t *hi = NULL;
        void *val = NULL;
        for (hi = axutil_hash_first(conf_ctx->svc_grp_ctx_map, env); hi;
                hi = axutil_hash_next(env, hi))
        {
            axis2_svc_grp_ctx_t *svc_grp_ctx = NULL;
            axutil_hash_this(hi, NULL, NULL, &val);
            svc_grp_ctx = (axis2_svc_grp_ctx_t *) val;
            if (svc_grp_ctx)
                 axis2_svc_grp_ctx_free(svc_grp_ctx, env);

            val = NULL;
            svc_grp_ctx = NULL;

        }
        axutil_hash_free(conf_ctx->svc_grp_ctx_map, env);
    }
    if (conf_ctx->conf)
    {
         axis2_conf_free(conf_ctx->conf, env);
    }
    if (conf_ctx->mutex)
    {
        axutil_thread_mutex_destroy(conf_ctx->mutex);
    }

    AXIS2_FREE(env->allocator, conf_ctx);

    return;
}

AXIS2_EXTERN axis2_svc_grp_ctx_t *AXIS2_CALL
axis2_conf_ctx_fill_ctxs(
    axis2_conf_ctx_t *conf_ctx,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    axis2_char_t *svc_grp_ctx_id = NULL;
    axis2_svc_grp_ctx_t *svc_grp_ctx = NULL;
    axis2_svc_ctx_t *svc_ctx = NULL;
    axis2_svc_t *svc = NULL;
    axis2_svc_grp_t *svc_grp = NULL;
    const axutil_qname_t *qname = NULL;
    axis2_char_t *svc_id = NULL;
    axis2_op_ctx_t *op_ctx = NULL;


    AXIS2_ENV_CHECK(env, NULL);

    AXIS2_PARAM_CHECK(env->error, msg_ctx, NULL);

    svc =  axis2_msg_ctx_get_svc(msg_ctx, env);
    if (!svc)
    {
        AXIS2_ERROR_SET(env->error,
                AXIS2_ERROR_SERVICE_NOT_YET_FOUND, AXIS2_FAILURE);
        return NULL;
    }

    qname = axis2_svc_get_qname(svc, env);
    if (!qname)
    {
        AXIS2_ERROR_SET(env->error,
                AXIS2_ERROR_INVALID_STATE_SVC, AXIS2_FAILURE);
        return NULL;
    }

    svc_id = axutil_qname_get_localpart(qname, env);
    if (!svc_id)
    {
        AXIS2_ERROR_SET(env->error,
                AXIS2_ERROR_INVALID_STATE_SVC, AXIS2_FAILURE);
        return NULL;
    }

    svc_grp = axis2_svc_get_parent(svc, env);
    if (svc_grp)
    {
        svc_grp_ctx_id = (axis2_char_t*) axis2_svc_grp_get_name(svc_grp, env);
    }

    if (!svc_grp_ctx_id)
    {
        svc_grp_ctx_id = (axis2_char_t*)axutil_string_get_buffer(
             axis2_msg_ctx_get_svc_grp_ctx_id(msg_ctx, env), env);
    }

    /* by this time service group context id must have a value,
       either from transport or from addressing */
    if (svc_grp_ctx_id)
    {
        svc_grp_ctx = (axis2_svc_grp_ctx_t*)
                axutil_hash_get(conf_ctx->svc_grp_ctx_map,
                        svc_grp_ctx_id, AXIS2_HASH_KEY_STRING);
        if (svc_grp_ctx)
        {
            svc_ctx =  axis2_svc_grp_ctx_get_svc_ctx(svc_grp_ctx, env, svc_id);
            if (!svc_ctx)
            {
                AXIS2_ERROR_SET(env->error,
                        AXIS2_ERROR_INVALID_STATE_SVC_GRP, AXIS2_FAILURE);
                return NULL;
            }
        }
    }

    if (!svc_grp_ctx_id)
    {
        svc_grp_ctx_id = axutil_uuid_gen(env);
        if (svc_grp_ctx_id)
        {
            axutil_string_t *svc_grp_ctx_id_str = 
                axutil_string_create_assume_ownership(env, &svc_grp_ctx_id);
             axis2_msg_ctx_set_svc_grp_ctx_id(msg_ctx, env, svc_grp_ctx_id_str);
            axutil_string_free(svc_grp_ctx_id_str, env);
        }
    }

    if (!svc_grp_ctx)
    {
        axis2_svc_grp_t *svc_grp = NULL;
        svc_grp = axis2_svc_get_parent(svc, env);
        svc_grp_ctx =  axis2_svc_grp_get_svc_grp_ctx(svc_grp, env, conf_ctx);
        svc_ctx =  axis2_svc_grp_ctx_get_svc_ctx(svc_grp_ctx, env, svc_id);
        if (!svc_ctx)
        {
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_STATE_SVC_GRP, AXIS2_FAILURE);
            return NULL;
        }
         axis2_svc_grp_ctx_set_id(svc_grp_ctx, env, svc_grp_ctx_id);
        axis2_conf_ctx_register_svc_grp_ctx(conf_ctx, env, svc_grp_ctx_id, svc_grp_ctx);
    }

    /* when you come here operation context MUST already been assigned
       to the message context */
    op_ctx =  axis2_msg_ctx_get_op_ctx(msg_ctx, env);
    if (!op_ctx)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_STATE_MSG_CTX, AXIS2_FAILURE);
        return NULL;
    }

     axis2_op_ctx_set_parent(op_ctx, env, svc_ctx);
     axis2_msg_ctx_set_svc_ctx(msg_ctx, env, svc_ctx);
     axis2_msg_ctx_set_svc_grp_ctx(msg_ctx, env, svc_grp_ctx);
    return svc_grp_ctx;
}
