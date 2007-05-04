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

#include <axis2_msg_info_headers.h>
#include <axutil_string.h>

struct axis2_msg_info_headers
{
    /** The address of the intended receiver of the message. This is mandatory */
    axis2_endpoint_ref_t *to;
    /** Reference of the endpoint where the message originated from */
    axis2_endpoint_ref_t *from;
    /** Pair of values that indicate how this message relate to another message */
    axis2_relates_to_t *relates_to;
    /** Identifies the intended receiver for replies to the message,
        if this is set, none and anonymous settings are ignored */
    axis2_endpoint_ref_t *reply_to;
    /** reply to should be none */
    axis2_bool_t reply_to_none;
    /** reply to should be anonymous, this is overridden by none*/
    axis2_bool_t reply_to_anonymous;
    /** identifies the intended receiver for faults related to the message
        if this is set, none and anonymous settings are ignored */
    axis2_endpoint_ref_t *fault_to;
    /** fault to should be none */
    axis2_bool_t fault_to_none;
    /** fault to should be anonymous, this is overridden by none*/
    axis2_bool_t fault_to_anonymous;
    /** action */
    axis2_char_t *action;
    /** message Id */
    axis2_char_t *message_id;
    /** reference parameters */
    axutil_array_list_t *ref_params;
};

AXIS2_EXTERN axis2_msg_info_headers_t *AXIS2_CALL
axis2_msg_info_headers_create(const axutil_env_t *env,
    axis2_endpoint_ref_t *to,
    const axis2_char_t *action)
{
    axis2_msg_info_headers_t *msg_info_headers = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    msg_info_headers =
        AXIS2_MALLOC(env->allocator, sizeof(axis2_msg_info_headers_t));

    if (!msg_info_headers)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    msg_info_headers->to = NULL;
    msg_info_headers->from = NULL;
    msg_info_headers->relates_to = NULL;
    msg_info_headers->reply_to_none = AXIS2_FALSE;
    msg_info_headers->reply_to_anonymous = AXIS2_FALSE;
    msg_info_headers->reply_to = NULL;
    msg_info_headers->fault_to_none = AXIS2_FALSE;
    msg_info_headers->fault_to_anonymous = AXIS2_FALSE;
    msg_info_headers->fault_to = NULL;
    msg_info_headers->action = NULL;
    msg_info_headers->message_id = NULL;
    msg_info_headers->ref_params = NULL;

    if (to)
    {
        msg_info_headers->to = to;
    }

    if (action)
    {
        msg_info_headers->action = axutil_strdup(env, action);
        if (!(msg_info_headers->action))
        {
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            axis2_msg_info_headers_free(msg_info_headers, env);
            return NULL;
        }
    }

    return msg_info_headers;
}

/**
 * Method getTo
 *
 * @return
 */
AXIS2_EXTERN axis2_endpoint_ref_t *AXIS2_CALL
axis2_msg_info_headers_get_to(const axis2_msg_info_headers_t *msg_info_headers,
    const axutil_env_t *env)
{
    return msg_info_headers->to;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_msg_info_headers_set_to(
    struct axis2_msg_info_headers *msg_info_headers,
    const axutil_env_t *env,
    axis2_endpoint_ref_t *to)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (msg_info_headers->to && to) /* if the incoming to is NULL,
                                       we consider that to be a reset,
                                       so don't free */
    {
        axis2_endpoint_ref_free(msg_info_headers->to, env);
        msg_info_headers->to = NULL;
    }
    msg_info_headers->to = to;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_endpoint_ref_t *AXIS2_CALL
axis2_msg_info_headers_get_from(const axis2_msg_info_headers_t *msg_info_headers,
    const axutil_env_t *env)
{
    return msg_info_headers->from;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_msg_info_headers_set_from(struct axis2_msg_info_headers *msg_info_headers,
    const axutil_env_t *env,
    axis2_endpoint_ref_t *from)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    msg_info_headers->from = from;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_endpoint_ref_t *AXIS2_CALL
axis2_msg_info_headers_get_reply_to(const axis2_msg_info_headers_t *msg_info_headers,
    const axutil_env_t *env)
{
    return msg_info_headers->reply_to;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_msg_info_headers_set_reply_to(struct axis2_msg_info_headers *msg_info_headers,
    const axutil_env_t *env,
    axis2_endpoint_ref_t *reply_to)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    msg_info_headers->reply_to = reply_to;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_endpoint_ref_t *AXIS2_CALL
axis2_msg_info_headers_get_fault_to(const axis2_msg_info_headers_t *msg_info_headers,
    const axutil_env_t *env)
{
    return msg_info_headers->fault_to;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_msg_info_headers_set_fault_to(struct axis2_msg_info_headers *msg_info_headers,
    const axutil_env_t *env,
    axis2_endpoint_ref_t *fault_to)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    msg_info_headers->fault_to = fault_to;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
axis2_msg_info_headers_get_action(const axis2_msg_info_headers_t *msg_info_headers,
    const axutil_env_t *env)
{
    return msg_info_headers->action;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_msg_info_headers_set_action(struct axis2_msg_info_headers *msg_info_headers,
    const axutil_env_t *env,
    const axis2_char_t *action)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    if (msg_info_headers->action)
    {
        AXIS2_FREE(env->allocator, msg_info_headers->action);
        msg_info_headers->action = NULL;
    }
    if (action)
	{
        msg_info_headers->action = axutil_strdup(env, action);
	}
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
axis2_msg_info_headers_get_message_id(const axis2_msg_info_headers_t *msg_info_headers,
    const axutil_env_t *env)
{
    return msg_info_headers->message_id;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_msg_info_headers_set_message_id(struct axis2_msg_info_headers *msg_info_headers,
    const axutil_env_t *env,
    const axis2_char_t *message_id)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (msg_info_headers->message_id)
    {
        AXIS2_FREE(env->allocator, msg_info_headers->message_id);
        msg_info_headers->message_id = NULL;
    }

    if (message_id)
    {
        msg_info_headers->message_id = axutil_strdup(env, message_id);
        if (!(msg_info_headers->message_id))
        {
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            return AXIS2_FAILURE;
        }
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_relates_to_t *AXIS2_CALL
axis2_msg_info_headers_get_relates_to(const axis2_msg_info_headers_t *msg_info_headers,
    const axutil_env_t *env)
{
    return msg_info_headers->relates_to;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_msg_info_headers_set_relates_to(struct axis2_msg_info_headers *msg_info_headers,
    const axutil_env_t *env,
    axis2_relates_to_t *relates_to)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    msg_info_headers->relates_to = relates_to;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
axis2_msg_info_headers_get_all_ref_params(const axis2_msg_info_headers_t *msg_info_headers,
    const axutil_env_t *env)
{
    return msg_info_headers->ref_params;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_msg_info_headers_add_ref_param(struct axis2_msg_info_headers *msg_info_headers,
    const axutil_env_t *env,
    axiom_node_t *ref_param)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (!(msg_info_headers->ref_params))
    {
        msg_info_headers->ref_params = axutil_array_list_create(env, 10);
        if (!(msg_info_headers->ref_params))
            return AXIS2_FAILURE;
    }

    if (ref_param)
    {
        return axutil_array_list_add(msg_info_headers->ref_params, env, ref_param);
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_msg_info_headers_free(
    struct axis2_msg_info_headers *msg_info_headers,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (msg_info_headers->to)
    {
        axis2_endpoint_ref_free(msg_info_headers->to, env);
    }
    if (msg_info_headers->from)
    {
        axis2_endpoint_ref_free(msg_info_headers->from, env);
    }
    if (msg_info_headers->reply_to)
    {
        axis2_endpoint_ref_free(msg_info_headers->reply_to, env);
    }
    if (msg_info_headers->relates_to)
    {
        axis2_relates_to_free(msg_info_headers->relates_to, env);
    }

    if (msg_info_headers->fault_to)
    {
        axis2_endpoint_ref_free(msg_info_headers->fault_to, env);
    }

    if (msg_info_headers->ref_params)
    {
        axutil_array_list_free(msg_info_headers->ref_params, env);
    }
    if (msg_info_headers->action)
    {
        AXIS2_FREE(env->allocator, msg_info_headers->action);
    }
    if (msg_info_headers->message_id)
    {
        AXIS2_FREE(env->allocator, msg_info_headers->message_id);
    }

    AXIS2_FREE(env->allocator, msg_info_headers);
    
    return;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_msg_info_headers_set_reply_to_none(struct axis2_msg_info_headers *msg_info_headers,
    const axutil_env_t *env,
    const axis2_bool_t none)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    msg_info_headers->reply_to_none = none;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axis2_msg_info_headers_get_reply_to_none(const axis2_msg_info_headers_t *msg_info_headers,
    const axutil_env_t *env)
{
    return msg_info_headers->reply_to_none;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_msg_info_headers_set_reply_to_anonymous(struct axis2_msg_info_headers *msg_info_headers,
    const axutil_env_t *env,
    const axis2_bool_t anonymous)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    msg_info_headers->reply_to_anonymous = anonymous;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axis2_msg_info_headers_get_reply_to_anonymous(const axis2_msg_info_headers_t *msg_info_headers,
    const axutil_env_t *env)
{
    return msg_info_headers->reply_to_anonymous;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_msg_info_headers_set_fault_to_none(struct axis2_msg_info_headers *msg_info_headers,
    const axutil_env_t *env,
    const axis2_bool_t none)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    msg_info_headers->fault_to_none = none;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axis2_msg_info_headers_get_fault_to_none(const axis2_msg_info_headers_t *msg_info_headers,
    const axutil_env_t *env)
{
    return msg_info_headers->fault_to_none;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_msg_info_headers_set_fault_to_anonymous(struct axis2_msg_info_headers *msg_info_headers,
    const axutil_env_t *env,
    const axis2_bool_t anonymous)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    msg_info_headers->fault_to_anonymous = anonymous;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axis2_msg_info_headers_get_fault_to_anonymous(const axis2_msg_info_headers_t *msg_info_headers,
    const axutil_env_t *env)
{
    return msg_info_headers->fault_to_anonymous;
}
