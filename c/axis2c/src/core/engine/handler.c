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

#include <axis2_handler.h>
#include <axis2_handler_desc.h>

struct axis2_handler
{
    /** handler description. This is a reference, hence a shallow copy. */
    axis2_handler_desc_t *handler_desc;
    /**
     * Invoke is called to do the actual work assigned to the handler.
     * The phase that owns the handler is responsible for calling invoke
     * on top of the handler. Those structs that implement the interface 
     * of the handler should implement the logic for invoke and assign the
     * respective function pointer to invoke operation.
     * @param handler pointer to handler
     * @param env pointer to environment struct
     * @param msg_ctx pointer to message context
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    axis2_status_t (AXIS2_CALL *
    invoke)(axis2_handler_t *handler,
        const axutil_env_t *env,
        struct axis2_msg_ctx *msg_ctx);
};

AXIS2_EXTERN axis2_handler_t *AXIS2_CALL
axis2_handler_create(
    const axutil_env_t *env)
{
    axis2_handler_t *handler = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    handler = AXIS2_MALLOC(env->allocator, sizeof(axis2_handler_t));
    if (!handler)
    {
        AXIS2_ERROR_SET_ERROR_NUMBER(env->error, AXIS2_ERROR_NO_MEMORY);
        AXIS2_ERROR_SET_STATUS_CODE(env->error, AXIS2_FAILURE);
        return NULL;
    }

    handler->handler_desc = NULL;

    return handler;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_handler_free(
    axis2_handler_t *handler,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_FREE(env->allocator, handler);
    return;
}

AXIS2_EXTERN const axutil_string_t *AXIS2_CALL
axis2_handler_get_name(
    const axis2_handler_t *handler,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    if (!(handler->handler_desc))
        return NULL;

    return axis2_handler_desc_get_name(handler->handler_desc, env);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_handler_invoke(axis2_handler_t *handler,
    const axutil_env_t *env,
    struct axis2_msg_ctx *msg_ctx)
{
    return handler->invoke(handler, env, msg_ctx);
}

AXIS2_EXTERN axutil_param_t *AXIS2_CALL
axis2_handler_get_param(
    const axis2_handler_t *handler,
    const axutil_env_t *env,
    const axis2_char_t *name)
{
    AXIS2_ENV_CHECK(env, NULL);

    if (!(handler->handler_desc))
        return NULL;

    return axis2_handler_desc_get_param(handler->handler_desc, env, name);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_handler_init(
    axis2_handler_t *handler,
    const axutil_env_t *env,
    axis2_handler_desc_t *handler_desc)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    handler->handler_desc = handler_desc;
    axis2_handler_desc_set_handler(handler_desc, env, handler);

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_handler_desc_t *AXIS2_CALL
axis2_handler_get_handler_desc(
    const axis2_handler_t *handler,
    const axutil_env_t *env)
{
    return handler->handler_desc;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_handler_set_invoke(
    axis2_handler_t *handler,
    const axutil_env_t *env, 
    void *func)
{
    handler->invoke = func;
    return AXIS2_SUCCESS;
}
