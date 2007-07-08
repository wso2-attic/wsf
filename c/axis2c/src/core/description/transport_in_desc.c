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

#include <axis2_transport_in_desc.h>
#include <axis2_transport_receiver.h>

struct axis2_transport_in_desc
{
    axis2_flow_t *in_flow;
    axis2_flow_t *fault_in_flow;
    AXIS2_TRANSPORT_ENUMS trans_enum;
    /**
     * transport receiver will have a shallow copy, but will be freed by 
     * free function.
     */
    axis2_transport_receiver_t *recv;
    axis2_phase_t *in_phase;
    axis2_phase_t *fault_phase;
    /** parameter container to hold transport in related parameters */
    axutil_param_container_t *param_container;
};

AXIS2_EXTERN axis2_transport_in_desc_t *AXIS2_CALL
axis2_transport_in_desc_create(const axutil_env_t *env,
    const AXIS2_TRANSPORT_ENUMS trans_enum)
{
    axis2_transport_in_desc_t *transport_in = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    transport_in = (axis2_transport_in_desc_t *) AXIS2_MALLOC(env->allocator,
        sizeof(axis2_transport_in_desc_t));

    if (! transport_in)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    transport_in->trans_enum = trans_enum;
    transport_in->in_phase = NULL;
    transport_in->fault_phase = NULL;
    transport_in->in_flow = NULL;
    transport_in->fault_in_flow = NULL;
    transport_in->recv = NULL;
    transport_in->param_container = NULL;

    transport_in->param_container = axutil_param_container_create(env);
    if (! transport_in->param_container)
    {
        axis2_transport_in_desc_free(transport_in, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    return transport_in;
}


void AXIS2_CALL
axis2_transport_in_desc_free(axis2_transport_in_desc_t *transport_in,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (transport_in->recv)
    {
        axis2_transport_receiver_free(transport_in->recv, env);
    }

    if (transport_in->param_container)
    {
        axutil_param_container_free(transport_in->param_container, env);
    }

    if (transport_in->in_flow)
    {
        axis2_flow_free(transport_in->in_flow, env);
    }

    if (transport_in->fault_in_flow)
    {
        axis2_flow_free(transport_in->fault_in_flow, env);
    }

    if (transport_in->in_phase)
    {
         axis2_phase_free(transport_in->in_phase, env);
    }

    if (transport_in->fault_phase)
    {
         axis2_phase_free(transport_in->fault_phase, env);
    }

    AXIS2_FREE(env->allocator, transport_in);

    return;
}

void AXIS2_CALL
axis2_transport_in_desc_free_void_arg(void *transport_in,
    const axutil_env_t *env)
{
    axis2_transport_in_desc_t *transport_in_l = NULL;

    AXIS2_ENV_CHECK(env, void);

    transport_in_l = (axis2_transport_in_desc_t *) transport_in;
    axis2_transport_in_desc_free(transport_in_l, env);
    return;
}

AXIS2_TRANSPORT_ENUMS AXIS2_CALL
axis2_transport_in_desc_get_enum(const axis2_transport_in_desc_t *transport_in,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    return transport_in->trans_enum;
}

axis2_status_t AXIS2_CALL
axis2_transport_in_desc_set_enum(axis2_transport_in_desc_t *transport_in,
    const axutil_env_t *env,
    const AXIS2_TRANSPORT_ENUMS trans_enum)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    transport_in->trans_enum = trans_enum;
    return AXIS2_SUCCESS;
}

axis2_flow_t *AXIS2_CALL
axis2_transport_in_desc_get_in_flow(const axis2_transport_in_desc_t *transport_in,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    return transport_in->in_flow;
}

axis2_status_t AXIS2_CALL
axis2_transport_in_desc_set_in_flow(axis2_transport_in_desc_t *transport_in,
    const axutil_env_t *env,
    axis2_flow_t *in_flow)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, in_flow, AXIS2_FAILURE);

    if (transport_in->in_flow)
    {
        axis2_flow_free(transport_in->in_flow, env);
    }
    transport_in->in_flow = in_flow;
    return AXIS2_SUCCESS;
}

axis2_flow_t *AXIS2_CALL
axis2_transport_in_desc_get_fault_in_flow(const axis2_transport_in_desc_t *transport_in,
    const axutil_env_t *env)
{
    return transport_in->fault_in_flow;
}

axis2_status_t AXIS2_CALL
axis2_transport_in_desc_set_fault_in_flow(axis2_transport_in_desc_t *transport_in,
    const axutil_env_t *env,
    axis2_flow_t *fault_in_flow)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, fault_in_flow, AXIS2_FAILURE);

    if (transport_in->fault_in_flow)
    {
        axis2_flow_free(transport_in->fault_in_flow, env);
    }
    transport_in->fault_in_flow = fault_in_flow;
    return AXIS2_SUCCESS;
}

axis2_transport_receiver_t *AXIS2_CALL
axis2_transport_in_desc_get_recv(const axis2_transport_in_desc_t *transport_in,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    return transport_in->recv;
}

axis2_status_t AXIS2_CALL
axis2_transport_in_desc_set_recv(axis2_transport_in_desc_t *transport_in,
    const axutil_env_t *env,
    axis2_transport_receiver_t *recv)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, recv, AXIS2_FAILURE);

    if (transport_in->recv)
    {
        axis2_transport_receiver_free(transport_in->recv, env);
    }

    transport_in->recv = recv;
    return AXIS2_SUCCESS;
}

axis2_phase_t *AXIS2_CALL
axis2_transport_in_desc_get_in_phase(const axis2_transport_in_desc_t *transport_in,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    return transport_in->in_phase;
}

axis2_status_t AXIS2_CALL
axis2_transport_in_desc_set_in_phase(axis2_transport_in_desc_t *transport_in,
    const axutil_env_t *env,
    axis2_phase_t *in_phase)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, in_phase, AXIS2_FAILURE);

    if (transport_in->in_phase)
    {
         axis2_phase_free(transport_in->in_phase, env);
    }
    transport_in->in_phase = in_phase;
    return AXIS2_SUCCESS;
}

axis2_phase_t *AXIS2_CALL
axis2_transport_in_desc_get_fault_phase(const axis2_transport_in_desc_t *transport_in,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    return transport_in->fault_phase;
}

axis2_status_t AXIS2_CALL
axis2_transport_in_desc_set_fault_phase(axis2_transport_in_desc_t *transport_in,
    const axutil_env_t *env,
    axis2_phase_t *fault_phase)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, fault_phase, AXIS2_FAILURE);

    if (transport_in->fault_phase)
    {
         axis2_phase_free(transport_in->fault_phase, env);
    }
    transport_in->fault_phase = fault_phase;
    return AXIS2_SUCCESS;

}

axis2_status_t AXIS2_CALL
axis2_transport_in_desc_add_param(axis2_transport_in_desc_t *transport_in_desc,
    const axutil_env_t *env,
    axutil_param_t *param)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, param, AXIS2_FAILURE);

    return axutil_param_container_add_param(transport_in_desc->
            param_container, env, param);
}

axutil_param_t *AXIS2_CALL
axis2_transport_in_desc_get_param(const axis2_transport_in_desc_t *transport_in_desc,
    const axutil_env_t *env,
    const axis2_char_t *param_name)
{
    AXIS2_ENV_CHECK(env, NULL);

    return axutil_param_container_get_param(transport_in_desc->param_container,
            env, param_name);
}

axis2_bool_t AXIS2_CALL
axis2_transport_in_desc_is_param_locked(axis2_transport_in_desc_t *
    transport_in_desc,
    const axutil_env_t *env,
    const axis2_char_t *param_name)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, param_name, AXIS2_FAILURE);

    return axutil_param_container_is_param_locked(transport_in_desc->
            param_container, env, param_name);
}

AXIS2_EXTERN axutil_param_container_t *AXIS2_CALL
axis2_transport_in_desc_param_container(const axis2_transport_in_desc_t *transport_in_desc,
    const axutil_env_t *env)
{
    return transport_in_desc->param_container;
}



