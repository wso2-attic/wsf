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

#include <axis2_flow.h>

struct axis2_flow
{
    axutil_array_list_t *list;
};

AXIS2_EXTERN axis2_flow_t *AXIS2_CALL
axis2_flow_create(const axutil_env_t *env)
{
    axis2_flow_t *flow = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    flow = (axis2_flow_t *) AXIS2_MALLOC(env->allocator,
        sizeof(axis2_flow_t));

    if (!flow)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    flow->list = NULL;

    flow->list = axutil_array_list_create(env, 20);
    if (!(flow->list))
    {
        axis2_flow_free(flow, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    return flow;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_flow_free(axis2_flow_t *flow,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (flow->list)
    {
        int i = 0;
        int size = 0;

        size = axutil_array_list_size(flow->list, env);
        for (i = 0; i < size; i++)
        {
            axis2_handler_desc_t *handler_desc = NULL;

            handler_desc = 
			    (axis2_handler_desc_t *) axutil_array_list_get(flow->list, env, i);
            axis2_handler_desc_free(handler_desc, env);
        }
        axutil_array_list_free(flow->list, env);
    }

    if (flow)
    {
        AXIS2_FREE(env->allocator, flow);
    }

    return;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_flow_free_void_arg(void *flow,
    const axutil_env_t *env)
{
    axis2_flow_t *flow_l = NULL;

    AXIS2_ENV_CHECK(env, void);
    flow_l = (axis2_flow_t *) flow;
    axis2_flow_free(flow_l, env);
    return;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_flow_add_handler(axis2_flow_t *flow,
    const axutil_env_t *env,
    axis2_handler_desc_t *handler)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, handler, AXIS2_FAILURE);

    if (!flow->list)
    {
        flow->list = axutil_array_list_create(env, 0);
        if (!flow->list)
        {
            axis2_flow_free(flow, env);
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            return AXIS2_FAILURE;
        }
    }
    return axutil_array_list_add(flow->list, env, handler);
}

AXIS2_EXTERN axis2_handler_desc_t *AXIS2_CALL
axis2_flow_get_handler(const axis2_flow_t *flow,
    const axutil_env_t *env,
    const int index)
{
    return axutil_array_list_get(flow->list, env, index);
}

AXIS2_EXTERN int AXIS2_CALL
axis2_flow_get_handler_count(const axis2_flow_t *flow,
    const axutil_env_t *env)
{
    return axutil_array_list_size(flow->list, env);
}

