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

#include <axis2_op_ctx.h>
#include <axis2_conf_ctx.h>
#include <axis2_op.h>
#include <axis2_const.h>
#include <axutil_hash.h>

struct axis2_op_ctx
{
    /** base context struct */
    axis2_ctx_t *base;
    /** parent of operation context is a service context instance */
    struct axis2_svc_ctx *parent;
    /** message context map */
    axis2_msg_ctx_t *msg_ctx_array[AXIS2_WSDL_MESSAGE_LABEL_MAX];
    /**
     * the operation of which this is a running instance. The MEP of this
     * operation must be one of the 8 predefined ones in WSDL 2.0.
     */
    axis2_op_t *op;
    /** operation Message Exchange Pattern (MEP) */
    int op_mep;
    /** is complete? */
    axis2_bool_t is_complete;
    /** the global message_id -> op_ctx map which is stored in
     * the axis2_conf_ctx. We are caching it here for faster access.
     */
    axutil_hash_t *op_ctx_map;
    /** op qname */
    axutil_qname_t *op_qname;
    /** service qname */
    axutil_qname_t *svc_qname;
    /* mutex to synchronize the read/write operations */
    axutil_thread_mutex_t *mutex;
    axis2_bool_t response_written;
    axis2_bool_t is_in_use;
};

AXIS2_EXTERN axis2_op_ctx_t *AXIS2_CALL
axis2_op_ctx_create(const axutil_env_t *env,
    axis2_op_t *op,
    struct axis2_svc_ctx *svc_ctx)
{
    axis2_op_ctx_t *op_ctx = NULL;
    int i = 0;

    AXIS2_ENV_CHECK(env, NULL);

    op_ctx = AXIS2_MALLOC(env->allocator, sizeof(axis2_op_ctx_t));
    if (!op_ctx)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    op_ctx->base = NULL;
    op_ctx->parent = NULL;
    op_ctx->op = NULL;
    op_ctx->op_mep = 0;
    op_ctx->is_complete = AXIS2_FALSE;
    op_ctx->is_in_use = AXIS2_FALSE;
    op_ctx->op_ctx_map = NULL;
    op_ctx->op_qname = NULL;
    op_ctx->svc_qname = NULL;
    op_ctx->response_written = AXIS2_FALSE;
    op_ctx->mutex = axutil_thread_mutex_create(env->allocator,
            AXIS2_THREAD_MUTEX_DEFAULT);

    if (!op_ctx->mutex)
    {
        axis2_op_ctx_free(op_ctx, env);
        return NULL;
    }

    op_ctx->base = axis2_ctx_create(env);
    if (!(op_ctx->base))
    {
        axis2_op_ctx_free(op_ctx, env);
        return NULL;
    }

    if (op)
    {
        op_ctx->op = op;
    }

    for (i = 0; i < AXIS2_WSDL_MESSAGE_LABEL_MAX; i++)
    {
        op_ctx->msg_ctx_array[i] = NULL;
    }

    if (op_ctx->op)
    {
        op_ctx->op_qname = (axutil_qname_t *)axis2_op_get_qname(op_ctx->op, env);
        op_ctx->op_mep = axis2_op_get_axis_specific_mep_const(op_ctx->op, env);
    }

    axis2_op_ctx_set_parent(op_ctx, env, svc_ctx);

    return op_ctx;
}

AXIS2_EXTERN axis2_ctx_t *AXIS2_CALL
axis2_op_ctx_get_base(
    const axis2_op_ctx_t *op_ctx,
    const axutil_env_t *env)
{
    return op_ctx->base;
}


AXIS2_EXTERN void AXIS2_CALL
axis2_op_ctx_free(
    struct axis2_op_ctx *op_ctx,
    const axutil_env_t *env)
{
    int i = 0;
    AXIS2_ENV_CHECK(env, void);

    if (op_ctx->base)
    {
         axis2_ctx_free(op_ctx->base, env);
    }

    for (i = 0; i < AXIS2_WSDL_MESSAGE_LABEL_MAX; i ++)
    {
        if(op_ctx->msg_ctx_array[i])
        {
             axis2_msg_ctx_free(op_ctx->msg_ctx_array[i], env);
            op_ctx->msg_ctx_array[i] = NULL;
        }
    }

    if (op_ctx->mutex)
    {
        axutil_thread_mutex_destroy(op_ctx->mutex);
    }

    AXIS2_FREE(env->allocator, op_ctx);

    return;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_op_ctx_destroy_mutex(
    struct axis2_op_ctx *op_ctx,
    const axutil_env_t *env)
{

    if (op_ctx->mutex)
    {
        axutil_thread_mutex_destroy(op_ctx->mutex);
        op_ctx->mutex = NULL;
    }
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_ctx_init(
    struct axis2_op_ctx *op_ctx,
    const axutil_env_t *env,
    struct axis2_conf *conf)
{
    int i = 0;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (op_ctx->op_qname && op_ctx->svc_qname)
    {
        axis2_svc_t *svc = NULL;
        axis2_char_t *svc_name = NULL;

        svc_name = axutil_qname_get_localpart(op_ctx->svc_qname, env);

        if (svc_name)
        {
            svc = axis2_conf_get_svc(conf, env, svc_name);

            if (svc)
            {
                op_ctx->op =
                    axis2_svc_get_op_with_qname(svc, env, op_ctx->op_qname);
            }
        }
    }

    for (i = 0; i < AXIS2_WSDL_MESSAGE_LABEL_MAX; i ++)
    {
        if(op_ctx->msg_ctx_array[i])
        {
             axis2_msg_ctx_init(op_ctx->msg_ctx_array[i], env, conf);
        }
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_op_t *AXIS2_CALL
axis2_op_ctx_get_op(
    const axis2_op_ctx_t *op_ctx,
    const axutil_env_t *env)
{
    return op_ctx->op;
}

AXIS2_EXTERN struct axis2_svc_ctx *AXIS2_CALL
            axis2_op_ctx_get_parent(
                const axis2_op_ctx_t *op_ctx,
                const axutil_env_t *env)
{
    return op_ctx->parent;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_ctx_add_msg_ctx(
    struct axis2_op_ctx *op_ctx,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    axis2_msg_ctx_t *out_msg_ctx = NULL;
    axis2_msg_ctx_t *in_msg_ctx = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    axutil_thread_mutex_lock(op_ctx->mutex);

    out_msg_ctx = op_ctx->msg_ctx_array[AXIS2_WSDL_MESSAGE_LABEL_OUT];
    in_msg_ctx = op_ctx->msg_ctx_array[AXIS2_WSDL_MESSAGE_LABEL_IN];

    if (out_msg_ctx && in_msg_ctx)
    {
        axutil_thread_mutex_unlock(op_ctx->mutex);
        return AXIS2_FAILURE;
    }

    if (!out_msg_ctx)
    {
        op_ctx->msg_ctx_array[AXIS2_WSDL_MESSAGE_LABEL_OUT] =  msg_ctx;
    }
    else
    {
        op_ctx->msg_ctx_array[AXIS2_WSDL_MESSAGE_LABEL_IN] = msg_ctx;
    }

    axutil_thread_mutex_unlock(op_ctx->mutex);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_msg_ctx_t *AXIS2_CALL
axis2_op_ctx_get_msg_ctx(
    const axis2_op_ctx_t *op_ctx,
    const axutil_env_t *env,
    const axis2_wsdl_msg_labels_t message_id)
{
    axutil_thread_mutex_lock(op_ctx->mutex);
    if (op_ctx->msg_ctx_array)
    {
        axis2_msg_ctx_t *rv = NULL;
        rv = op_ctx->msg_ctx_array[message_id];
        axutil_thread_mutex_unlock(op_ctx->mutex);
        return rv;
    }
    axutil_thread_mutex_unlock(op_ctx->mutex);
    return NULL;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axis2_op_ctx_get_is_complete(
    const axis2_op_ctx_t *op_ctx,
    const axutil_env_t *env)
{
    return op_ctx->is_complete;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_ctx_set_complete(
    struct axis2_op_ctx *op_ctx,
    const axutil_env_t *env,
    axis2_bool_t is_complete)
{
    op_ctx->is_complete = is_complete;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axis2_op_ctx_is_in_use(
    const axis2_op_ctx_t *op_ctx,
    const axutil_env_t *env)
{
    return op_ctx->is_in_use;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_ctx_set_in_use(
    struct axis2_op_ctx *op_ctx,
    const axutil_env_t *env,
    axis2_bool_t is_in_use)
{
    op_ctx->is_in_use = is_in_use;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_ctx_cleanup(
    struct axis2_op_ctx *op_ctx,
    const axutil_env_t *env)
{
    int i = 0;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    for (i = 0; i < AXIS2_WSDL_MESSAGE_LABEL_MAX; i ++)
    {
        if(op_ctx->msg_ctx_array[i])
        {
             axis2_msg_ctx_free(op_ctx->msg_ctx_array[i], env);
            op_ctx->msg_ctx_array[i] = NULL;
        }
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_ctx_set_parent(
    struct axis2_op_ctx *op_ctx,
    const axutil_env_t *env,
    struct axis2_svc_ctx *svc_ctx)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (svc_ctx)
    {
        op_ctx->parent = svc_ctx;
    }

    if (op_ctx->parent) /* that is if there is a service context associated */
    {
        axis2_conf_ctx_t *conf_ctx = NULL;
        conf_ctx =  axis2_svc_ctx_get_conf_ctx(op_ctx->parent, env);
        if (conf_ctx)
        {
            op_ctx->op_ctx_map =
                 axis2_conf_ctx_get_op_ctx_map(conf_ctx, env);
        }
        op_ctx->svc_qname =
            (axutil_qname_t *)axis2_svc_get_qname( axis2_svc_ctx_get_svc(op_ctx->parent, env), env);
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_msg_ctx_t **AXIS2_CALL
axis2_op_ctx_get_msg_ctx_map(
    const axis2_op_ctx_t *op_ctx,
    const axutil_env_t *env)
{
    return (axis2_msg_ctx_t **)(op_ctx->msg_ctx_array);
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axis2_op_ctx_get_response_written(const axis2_op_ctx_t *op_ctx,
    const axutil_env_t *env)
{
    if (op_ctx)
        return op_ctx->response_written;
    else
        return AXIS2_FAILURE;

}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_ctx_set_response_written(axis2_op_ctx_t *op_ctx,
    const axutil_env_t *env,
    const axis2_bool_t written)
{
    if (op_ctx)
    {
        op_ctx->response_written = written;
    }
    else
    {
        return AXIS2_FAILURE;
    }
 
    return AXIS2_SUCCESS;
}

