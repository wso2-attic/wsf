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

#include "axis2_math_stub.h"


axis2_stub_t *
axis2_math_stub_create_with_endpoint_ref_and_client_home(const axutil_env_t *env,
        axis2_endpoint_ref_t *endpoint_ref,
        axis2_char_t *client_home)
{
    axis2_stub_t *stub = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    stub = (axis2_stub_t *)
            axis2_stub_create_with_endpoint_ref_and_client_home(env, endpoint_ref,
                    client_home);
    if (! stub)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    axis2_populate_axis_service(stub, env);
    return stub;
}

void axis2_populate_axis_service(axis2_stub_t* stub, const axutil_env_t *env)
{
    axis2_svc_client_t* svc_client = NULL;
    axutil_qname_t *op_qname =  NULL;
    axis2_svc_t* svc = NULL;
    axis2_op_t* op = NULL;

    /*Modifying the Service*/
    svc_client = axis2_stub_get_svc_client(stub, env);
    svc = axis2_svc_client_get_svc(svc_client, env);

    /*creating the operations*/

    op_qname = axutil_qname_create(env, "add" , "", NULL);
    op = axis2_op_create_with_qname(env, op_qname);
    axis2_op_set_msg_exchange_pattern(op, env, AXIS2_MEP_URI_OUT_IN);
    axis2_svc_add_op(svc, env, op);
    axutil_qname_free(op_qname, env);

    op_qname = axutil_qname_create(env, "sub" , "", NULL);
    op = axis2_op_create_with_qname(env, op_qname);
    axis2_op_set_msg_exchange_pattern(op, env, AXIS2_MEP_URI_OUT_IN);
    axis2_svc_add_op(svc, env, op);
    axutil_qname_free(op_qname, env);

    op_qname = axutil_qname_create(env, "mul" , "", NULL);
    op = axis2_op_create_with_qname(env, op_qname);
    axis2_op_set_msg_exchange_pattern(op, env, AXIS2_MEP_URI_OUT_IN);
    axis2_svc_add_op(svc, env, op);
    axutil_qname_free(op_qname, env);

    op_qname = axutil_qname_create(env, "div" , "", NULL);
    op = axis2_op_create_with_qname(env, op_qname);
    axis2_op_set_msg_exchange_pattern(op, env, AXIS2_MEP_URI_OUT_IN);
    axis2_svc_add_op(svc, env, op);
    axutil_qname_free(op_qname, env);
}

axis2_stub_t *
axis2_math_stub_create_with_endpoint_uri_and_client_home(const axutil_env_t *env,
        const axis2_char_t *endpoint_uri,
        const axis2_char_t *client_home)
{
    axis2_stub_t *stub = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    stub = (axis2_stub_t *)
            axis2_stub_create_with_endpoint_uri_and_client_home(env, endpoint_uri,
                    client_home);
    if (! stub)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    axis2_populate_axis_service(stub, env);

    return stub;
}

/***************************Function implementation****************************/

axiom_node_t *
axis2_math_stub_add(axis2_stub_t *stub,
        const axutil_env_t *env,
        axiom_node_t *node)
{
    axis2_svc_client_t *svc_client = NULL;
    axiom_node_t *ret_node = NULL;
    axutil_qname_t *op_qname =  NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    svc_client = axis2_stub_get_svc_client(stub, env);
    op_qname = axutil_qname_create(env, "add" , "", NULL);
    ret_node =  axis2_svc_client_send_receive_with_op_qname(svc_client, env, op_qname, node);
    axutil_qname_free(op_qname, env);

    return ret_node;
}

axiom_node_t *
axis2_math_stub_sub(axis2_stub_t *stub,
        const axutil_env_t *env,
        axiom_node_t *node)
{
    axis2_svc_client_t *svc_client = NULL;
    axiom_node_t *ret_node = NULL;
    axutil_qname_t *op_qname =  NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    svc_client = axis2_stub_get_svc_client(stub, env);
    op_qname = axutil_qname_create(env, "sub" , "", NULL);
    ret_node =  axis2_svc_client_send_receive_with_op_qname(svc_client, env, op_qname, node);

    return ret_node;
}

axiom_node_t *
axis2_math_stub_mul(axis2_stub_t *stub,
        const axutil_env_t *env,
        axiom_node_t *node)
{
    axis2_svc_client_t *svc_client = NULL;
    axiom_node_t *ret_node = NULL;
    axutil_qname_t *op_qname =  NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    svc_client = axis2_stub_get_svc_client(stub, env);
    op_qname = axutil_qname_create(env, "mul" , "", NULL);
    ret_node =  axis2_svc_client_send_receive_with_op_qname(svc_client, env, op_qname, node);

    return ret_node;
}

axiom_node_t *
axis2_math_stub_div(axis2_stub_t *stub,
        const axutil_env_t *env,
        axiom_node_t *node)
{
    axis2_svc_client_t *svc_client = NULL;
    axiom_node_t *ret_node = NULL;
    axutil_qname_t *op_qname =  NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    svc_client = axis2_stub_get_svc_client(stub, env);
    op_qname = axutil_qname_create(env, "div" , "", NULL);
    ret_node =  axis2_svc_client_send_receive_with_op_qname(svc_client, env, op_qname, node);

    return ret_node;
}

