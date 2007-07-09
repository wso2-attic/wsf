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

#include <axis2_stub.h>

struct axis2_stub
{
    axis2_svc_client_t *svc_client;
    axis2_options_t *options;
};


AXIS2_EXTERN axis2_stub_t *AXIS2_CALL
axis2_stub_create(const axutil_env_t *env)
{
    axis2_stub_t *stub = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    stub = (axis2_stub_t *) AXIS2_MALLOC(env->allocator, sizeof(axis2_stub_t));

    if (! stub)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    stub->svc_client = NULL;
    stub->options = NULL;

    return stub;
}

AXIS2_EXTERN axis2_stub_t *AXIS2_CALL
axis2_stub_create_with_endpoint_ref_and_client_home(const axutil_env_t *env,
    axis2_endpoint_ref_t *endpoint_ref,
    const axis2_char_t *client_home)
{
    axis2_stub_t *stub = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, endpoint_ref, NULL);

    stub = (axis2_stub_t *) axis2_stub_create(env);
    if (!stub)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    /* create service_client*/
    stub->svc_client = axis2_svc_client_create(env , client_home);

    if (!stub->svc_client)
    {
        axis2_stub_free(stub, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    /* create options */
    stub->options = axis2_options_create(env);
    if (!stub->options)
    {
        axis2_stub_free(stub, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    /* Set service client options */
    axis2_svc_client_set_options(stub->svc_client, env, stub-> options);

    axis2_options_set_to(stub->options, env, endpoint_ref);

    return stub;
}

AXIS2_EXTERN axis2_stub_t *AXIS2_CALL
axis2_stub_create_with_endpoint_uri_and_client_home(const axutil_env_t *env,
    const axis2_char_t *endpoint_uri,
    const axis2_char_t *client_home)
{
    axis2_stub_t *stub = NULL;
    axis2_endpoint_ref_t *endpoint_ref = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, endpoint_uri, NULL);

    endpoint_ref = axis2_endpoint_ref_create(env, endpoint_uri);
    if (!endpoint_ref)
    {
        return NULL;
    }
    stub = (axis2_stub_t *)
        axis2_stub_create_with_endpoint_ref_and_client_home(env, endpoint_ref,
            client_home);

    if (!stub)
    {
        axis2_stub_free(stub, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    return stub;
}

void AXIS2_CALL
axis2_stub_free(axis2_stub_t *stub,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (stub->svc_client)
    {
        axis2_svc_client_free(stub->svc_client, env);
    }

    if (stub)
    {
        AXIS2_FREE(env->allocator, stub);
    }

    return;
}

axis2_status_t AXIS2_CALL
axis2_stub_set_endpoint_ref(axis2_stub_t *stub,
    const axutil_env_t *env,
    axis2_endpoint_ref_t *endpoint_ref)
{
    AXIS2_PARAM_CHECK(env->error, endpoint_ref, AXIS2_FAILURE);
    axis2_options_set_to(stub->options , env, endpoint_ref);
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_stub_set_endpoint_uri(axis2_stub_t *stub,
    const axutil_env_t *env,
    const axis2_char_t *endpoint_uri)
{
    axis2_endpoint_ref_t *endpoint_ref = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, endpoint_uri, AXIS2_FAILURE);

    endpoint_ref = axis2_endpoint_ref_create(env, endpoint_uri);
    if (!endpoint_ref)
    {
        return AXIS2_FAILURE;
    }
    axis2_options_set_to(stub->options , env, endpoint_ref);

    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_stub_set_use_separate_listener(axis2_stub_t *stub,
    const axutil_env_t *env,
    const axis2_bool_t use_separate_listener)
{
    return axis2_options_set_use_separate_listener(stub-> options, env,
            use_separate_listener);
}

axis2_status_t AXIS2_CALL
axis2_stub_engage_module(axis2_stub_t *stub,
    const axutil_env_t *env,
    const axis2_char_t *module_name)
{
    AXIS2_PARAM_CHECK(env->error, module_name, AXIS2_FAILURE);

    return axis2_svc_client_engage_module(stub->svc_client, env, module_name);
}

axis2_status_t AXIS2_CALL
axis2_stub_set_soap_version(axis2_stub_t *stub,
    const axutil_env_t *env,
    int soap_version)
{
    if (!stub-> options)
    {
        return AXIS2_FAILURE;
    }
    return axis2_options_set_soap_version(stub-> options, env, soap_version);
}

const axis2_char_t *AXIS2_CALL
axis2_stub_get_svc_ctx_id(const axis2_stub_t *stub,
    const axutil_env_t *env)
{
    const axis2_svc_ctx_t *svc_ctx = NULL;
    const axis2_char_t *svc_ctx_id = NULL;

    svc_ctx = axis2_svc_client_get_svc_ctx(stub->svc_client, env);
    svc_ctx_id =  axis2_svc_ctx_get_svc_id(svc_ctx, env);
    return svc_ctx_id;
}

axis2_svc_client_t *AXIS2_CALL
axis2_stub_get_svc_client(const axis2_stub_t *stub,
    const axutil_env_t *env)
{
    return stub->svc_client;
}

axis2_options_t *AXIS2_CALL
axis2_stub_get_options(const axis2_stub_t *stub,
    const axutil_env_t *env)
{
    return stub->options;
}



