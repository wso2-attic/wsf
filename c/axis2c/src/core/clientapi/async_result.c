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

#include <axis2_async_result.h>
#include <axis2_const.h>
#include <axutil_hash.h>

struct axis2_async_result
{
    /** result message context */
    axis2_msg_ctx_t *result;
};

AXIS2_EXTERN axis2_async_result_t *AXIS2_CALL
axis2_async_result_create(const axutil_env_t *env,
    axis2_msg_ctx_t *result)
{
    axis2_async_result_t *async_result = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    async_result = AXIS2_MALLOC(env->allocator,
            sizeof(axis2_async_result_t));
    if (!async_result)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    async_result->result = NULL;

    if (result)
    {
        async_result->result = result; /* shallow copy */
    }

    return async_result;
}

AXIS2_EXTERN axiom_soap_envelope_t *AXIS2_CALL
axis2_async_result_get_envelope(axis2_async_result_t *async_result,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    if (async_result->result)
    {
        return  axis2_msg_ctx_get_soap_envelope(async_result->result, env);
    }

    return NULL;
}

AXIS2_EXTERN axis2_msg_ctx_t *AXIS2_CALL
axis2_async_result_get_result(axis2_async_result_t *async_result,
    const axutil_env_t *env)
{
    return async_result->result;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_async_result_free(axis2_async_result_t *async_result,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    AXIS2_FREE(env->allocator, async_result);

    return;
}


