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

#include <axis2_svr_callback.h>
#include <axis2_engine.h>

struct axis2_svr_callback
{
    axis2_char_t *scope;
};

AXIS2_EXPORT axis2_svr_callback_t *AXIS2_CALL
axis2_svr_callback_create(const axutil_env_t *env)
{
    axis2_svr_callback_t *svr_callback = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    svr_callback = (axis2_svr_callback_t *)
        AXIS2_MALLOC(env->allocator, sizeof(axis2_svr_callback_t));

    if (!svr_callback)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    return svr_callback;
}

AXIS2_EXPORT void AXIS2_CALL
axis2_svr_callback_free(axis2_svr_callback_t *svr_callback,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (svr_callback)
    {
        AXIS2_FREE(env->allocator, svr_callback);
    }

    return;
}

AXIS2_EXPORT axis2_status_t AXIS2_CALL
axis2_svr_callback_handle_result(axis2_svr_callback_t *svr_callback,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    axis2_engine_t *engine = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_svc_ctx_t *svc_ctx = NULL;
    axis2_op_ctx_t *op_ctx = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);

    op_ctx = axis2_msg_ctx_get_op_ctx(msg_ctx, env);
    svc_ctx = axis2_op_ctx_get_parent(op_ctx, env);
    conf_ctx = axis2_svc_ctx_get_conf_ctx(svc_ctx, env);
    engine = axis2_engine_create(env, conf_ctx);
    if (!engine)
    {
        return AXIS2_FAILURE;
    }
    return axis2_engine_send(engine, env, msg_ctx);
}

AXIS2_EXPORT axis2_status_t AXIS2_CALL
axis2_svr_callback_handle_fault(axis2_svr_callback_t *svr_callback,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    axis2_engine_t *engine = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_svc_ctx_t *svc_ctx = NULL;
    axis2_op_ctx_t *op_ctx = NULL;
    axis2_msg_ctx_t *fault_ctx = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);

    op_ctx = axis2_msg_ctx_get_op_ctx(msg_ctx, env);
    svc_ctx = axis2_op_ctx_get_parent(op_ctx, env);
    conf_ctx = axis2_svc_ctx_get_conf_ctx(svc_ctx, env);
    engine = axis2_engine_create(env, conf_ctx);
    if (!engine)
    {
        return AXIS2_FAILURE;
    }

    fault_ctx = axis2_engine_create_fault_msg_ctx(engine, env, msg_ctx);
    return axis2_engine_send_fault(engine, env, fault_ctx);
}


