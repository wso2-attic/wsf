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
#include <axis2_flow_container.h>

struct axis2_flow_container
{
    axis2_flow_t *in;
    axis2_flow_t *out;
    axis2_flow_t *in_fault;
    axis2_flow_t *out_fault;
};

AXIS2_EXTERN axis2_flow_container_t *AXIS2_CALL
axis2_flow_container_create(const axutil_env_t *env)
{
    axis2_flow_container_t *flow_container = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    flow_container = (axis2_flow_container_t *) AXIS2_MALLOC(env->
        allocator, sizeof(axis2_flow_container_t));


    if (! flow_container)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    flow_container->in = NULL;
    flow_container->out = NULL;
    flow_container->in_fault = NULL;
    flow_container->out_fault = NULL;

    return flow_container;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_flow_container_free(axis2_flow_container_t *flow_container,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (flow_container->in)
    {
        axis2_flow_free(flow_container->in, env);
    }

    if (flow_container->out)
    {
        axis2_flow_free(flow_container->out, env);
    }

    if (flow_container->in_fault)
    {
        axis2_flow_free(flow_container->in_fault, env);
    }

    if (flow_container->out_fault)
    {
        axis2_flow_free(flow_container->out_fault, env);
    }

    if (flow_container)
    {
        AXIS2_FREE(env->allocator, flow_container);
    }

    return;
}

AXIS2_EXTERN axis2_flow_t *AXIS2_CALL
axis2_flow_container_get_in_flow(const axis2_flow_container_t *flow_container,
    const axutil_env_t *env)
{
    return flow_container->in;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_flow_container_set_in_flow(axis2_flow_container_t *flow_container,
    const axutil_env_t *env,
    axis2_flow_t *in_flow)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (flow_container->in)
    {
        axis2_flow_free(flow_container->in, env);
    }
    flow_container->in = in_flow;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_flow_t *AXIS2_CALL
axis2_flow_container_get_out_flow(const axis2_flow_container_t *flow_container,
    const axutil_env_t *env)
{
    return flow_container->out;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_flow_container_set_out_flow(axis2_flow_container_t *flow_container,
    const axutil_env_t *env,
    axis2_flow_t *out_flow)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (flow_container->out)
    {
        axis2_flow_free(flow_container->out, env);
    }
    flow_container->out = out_flow;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_flow_t *AXIS2_CALL
axis2_flow_container_get_fault_in_flow(const axis2_flow_container_t *flow_container,
    const axutil_env_t *env)
{
    return flow_container->in_fault;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_flow_container_set_fault_in_flow(axis2_flow_container_t *flow_container,
    const axutil_env_t *env,
    axis2_flow_t *falut_in_flow)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    if (flow_container->in_fault)
    {
        axis2_flow_free(flow_container->in_fault, env);
    }
    flow_container->in_fault = falut_in_flow;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_flow_t *AXIS2_CALL
axis2_flow_container_get_fault_out_flow(const axis2_flow_container_t *flow_container,
    const axutil_env_t *env)
{
    return flow_container->out_fault;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_flow_container_set_fault_out_flow(axis2_flow_container_t *flow_container,
    const axutil_env_t *env,
    axis2_flow_t *fault_out_flow)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, fault_out_flow, AXIS2_FAILURE);
    if (flow_container->out_fault)
    {
        axis2_flow_free(flow_container->out_fault, env);
    }
    flow_container->out_fault = fault_out_flow;
    return AXIS2_SUCCESS;
}
