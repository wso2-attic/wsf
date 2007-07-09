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

#include <axis2_transport_out_desc.h>

struct axis2_transport_out_desc
{
    axis2_flow_t *out_flow;
    axis2_flow_t *fault_out_flow;
    AXIS2_TRANSPORT_ENUMS trans_enum;
    axis2_transport_sender_t *sender;
    axis2_phase_t *out_phase;
    axis2_phase_t *fault_phase;
    /** parameter container that holds parameter */
    axutil_param_container_t *param_container;
};

AXIS2_EXTERN axis2_transport_out_desc_t *AXIS2_CALL
axis2_transport_out_desc_create(const axutil_env_t *env,
    const AXIS2_TRANSPORT_ENUMS trans_enum)
{
    axis2_transport_out_desc_t *transport_out = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    transport_out = (axis2_transport_out_desc_t *) AXIS2_MALLOC(env->
            allocator, sizeof(axis2_transport_out_desc_t));

    if (! transport_out)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    transport_out->trans_enum = trans_enum;
    transport_out->out_phase = NULL;
    transport_out->fault_phase = NULL;
    transport_out->out_flow = NULL;
    transport_out->fault_out_flow = NULL;
    transport_out->sender = NULL;
    transport_out->param_container = NULL;

    transport_out->param_container = axutil_param_container_create(env);
    if (! transport_out->param_container)
    {
        axis2_transport_out_desc_free(transport_out, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    return transport_out;
}

void AXIS2_CALL
axis2_transport_out_desc_free(axis2_transport_out_desc_t *transport_out,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (transport_out->sender)
    {
        AXIS2_TRANSPORT_SENDER_FREE(transport_out->sender, env);
    }

    if (transport_out->param_container)
    {
        axutil_param_container_free(transport_out->param_container, env);
    }

    if (transport_out->out_flow)
    {
        axis2_flow_free(transport_out->out_flow, env);
    }

    if (transport_out->fault_out_flow)
    {
        axis2_flow_free(transport_out->fault_out_flow, env);
    }

    if (transport_out->out_phase)
    {
         axis2_phase_free(transport_out->out_phase, env);
    }

    if (transport_out->fault_phase)
    {
         axis2_phase_free(transport_out->fault_phase, env);
    }

    AXIS2_FREE(env->allocator, transport_out);

    return;
}

void AXIS2_CALL
axis2_transport_out_desc_free_void_arg(void *transport_out,
    const axutil_env_t *env)
{
    axis2_transport_out_desc_t *transport_out_l = NULL;

    AXIS2_ENV_CHECK(env, void);

    transport_out_l = (axis2_transport_out_desc_t *) transport_out;
    axis2_transport_out_desc_free(transport_out_l, env);
    return;
}

AXIS2_TRANSPORT_ENUMS AXIS2_CALL
axis2_transport_out_desc_get_enum(const axis2_transport_out_desc_t *transport_out,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    return transport_out->trans_enum;
}

axis2_status_t AXIS2_CALL
axis2_transport_out_desc_set_enum(axis2_transport_out_desc_t *transport_out,
    const axutil_env_t *env,
    const AXIS2_TRANSPORT_ENUMS trans_enum)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    transport_out->trans_enum = trans_enum;
    return AXIS2_SUCCESS;
}

axis2_flow_t *AXIS2_CALL
axis2_transport_out_desc_get_out_flow(const axis2_transport_out_desc_t *transport_out,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    return transport_out->out_flow;
}

axis2_status_t AXIS2_CALL
axis2_transport_out_desc_set_out_flow(axis2_transport_out_desc_t *transport_out,
    const axutil_env_t *env,
    axis2_flow_t *out_flow)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, out_flow, AXIS2_FAILURE);

    if (transport_out->out_flow)
    {
        axis2_flow_free(transport_out->out_flow, env);
    }
    transport_out->out_flow = out_flow;
    return AXIS2_SUCCESS;
}

axis2_flow_t *AXIS2_CALL
axis2_transport_out_desc_get_fault_out_flow(const axis2_transport_out_desc_t *transport_out,
    const axutil_env_t *env)
{
    return transport_out->fault_out_flow;
}

axis2_status_t AXIS2_CALL
axis2_transport_out_desc_set_fault_out_flow(axis2_transport_out_desc_t *transport_out,
    const axutil_env_t *env,
    axis2_flow_t *fault_out_flow)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, fault_out_flow, AXIS2_FAILURE);

    if (transport_out->fault_out_flow)
    {
        axis2_flow_free(transport_out->fault_out_flow, env);
    }
    transport_out->fault_out_flow = fault_out_flow;
    return AXIS2_SUCCESS;
}

axis2_transport_sender_t *AXIS2_CALL
axis2_transport_out_desc_get_sender(const axis2_transport_out_desc_t *transport_out,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    return transport_out->sender;
}

axis2_status_t AXIS2_CALL
axis2_transport_out_desc_set_sender(axis2_transport_out_desc_t *transport_out,
    const axutil_env_t *env,
    axis2_transport_sender_t *sender)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, sender, AXIS2_FAILURE);

    if (transport_out->sender)
    {
        AXIS2_TRANSPORT_SENDER_FREE(transport_out->sender, env);
    }

    transport_out->sender = sender;
    return AXIS2_SUCCESS;
}

axis2_phase_t *AXIS2_CALL
axis2_transport_out_desc_get_out_phase(const axis2_transport_out_desc_t *transport_out,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    return transport_out->out_phase;
}

axis2_status_t AXIS2_CALL
axis2_transport_out_desc_set_out_phase(axis2_transport_out_desc_t *transport_out,
    const axutil_env_t *env,
    axis2_phase_t *out_phase)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, out_phase, AXIS2_FAILURE);

    if (transport_out->out_phase)
    {
         axis2_phase_free(transport_out->out_phase, env);
    }
    transport_out->out_phase = out_phase;
    return AXIS2_SUCCESS;
}

axis2_phase_t *AXIS2_CALL
axis2_transport_out_desc_get_fault_phase(const axis2_transport_out_desc_t *transport_out,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    return transport_out->fault_phase;
}

axis2_status_t AXIS2_CALL
axis2_transport_out_desc_set_fault_phase(axis2_transport_out_desc_t *transport_out,
    const axutil_env_t *env,
    axis2_phase_t *fault_phase)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, fault_phase, AXIS2_FAILURE);

    if (transport_out->fault_phase)
    {
         axis2_phase_free(transport_out->fault_phase, env);
    }
    transport_out->fault_phase = fault_phase;
    return AXIS2_SUCCESS;

}

axis2_status_t AXIS2_CALL
axis2_transport_out_desc_add_param(axis2_transport_out_desc_t *transport_out_desc,
    const axutil_env_t *env,
    axutil_param_t *param)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, param, AXIS2_FAILURE);

    return axutil_param_container_add_param(transport_out_desc->
        param_container, env, param);
}

axutil_param_t *AXIS2_CALL
axis2_transport_out_desc_get_param(const axis2_transport_out_desc_t *transport_out_desc,
    const axutil_env_t *env,
    const axis2_char_t *param_name)
{
    AXIS2_ENV_CHECK(env, NULL);

    return axutil_param_container_get_param(transport_out_desc->param_container,
        env, param_name);
}

axis2_bool_t AXIS2_CALL
axis2_transport_out_desc_is_param_locked(axis2_transport_out_desc_t *
    transport_out_desc,
    const axutil_env_t *env,
    const axis2_char_t *param_name)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, param_name, AXIS2_FAILURE);

    return axutil_param_container_is_param_locked(transport_out_desc->
        param_container, env, param_name);
}

AXIS2_EXTERN axutil_param_container_t *AXIS2_CALL
axis2_transport_out_desc_param_container(const axis2_transport_out_desc_t *transport_out_desc,
    const axutil_env_t *env)
{
    return transport_out_desc->param_container;
}



