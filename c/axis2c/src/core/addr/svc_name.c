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


#include <axis2_svc_name.h>
#include <axutil_string.h>

struct axis2_svc_name
{
    /** service QName */
    axutil_qname_t *qname;
    /** service endpoint name */
    axis2_char_t *endpoint_name;
};

axis2_svc_name_t *AXIS2_CALL
axis2_svc_name_create(const axutil_env_t *env,
    const axutil_qname_t *qname,
    const axis2_char_t *endpoint_name)
{
    axis2_svc_name_t *svc_name = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    svc_name =
        AXIS2_MALLOC(env->allocator, sizeof(axis2_svc_name_t));
    if (!svc_name)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    svc_name->qname = NULL;
    svc_name->endpoint_name = NULL;

    if (qname)
    {
        svc_name->qname = axutil_qname_clone((axutil_qname_t *)qname, env);
        if (!(svc_name->qname))
        {
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            axis2_svc_name_free(svc_name, env);
            return NULL;
        }
    }

    if (endpoint_name)
    {
        svc_name->endpoint_name = axutil_strdup(env, endpoint_name);
        if (!(svc_name->endpoint_name))
        {
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            axis2_svc_name_free(svc_name, env);
            return NULL;
        }
    }

    return svc_name;
}

const axutil_qname_t *AXIS2_CALL
axis2_svc_name_get_qname(const axis2_svc_name_t *svc_name,
    const axutil_env_t *env)
{
    return svc_name->qname;
}

axis2_status_t AXIS2_CALL
axis2_svc_name_set_qname(struct axis2_svc_name *svc_name,
    const axutil_env_t *env,
    const axutil_qname_t *qname)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (svc_name->qname)
    {
        axutil_qname_free(svc_name->qname, env);
    }

    if (qname)
    {
        svc_name->qname = axutil_qname_clone((axutil_qname_t *)qname, env);
        if (!(svc_name->qname))
            return AXIS2_FAILURE;
    }

    return AXIS2_SUCCESS;
}

const axis2_char_t *AXIS2_CALL
axis2_svc_name_get_endpoint_name(const axis2_svc_name_t *svc_name,
    const axutil_env_t *env)
{
    return svc_name->endpoint_name;
}

axis2_status_t AXIS2_CALL
axis2_svc_name_set_endpoint_name(struct axis2_svc_name *svc_name,
    const axutil_env_t *env,
    const axis2_char_t *endpoint_name)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (svc_name->endpoint_name)
    {
        AXIS2_FREE(env->allocator, svc_name->endpoint_name);
    }

    if (endpoint_name)
    {
        svc_name->endpoint_name = axutil_strdup(env, endpoint_name);
        if (!(svc_name->endpoint_name))
            return AXIS2_FAILURE;
    }

    return AXIS2_SUCCESS;
}

void AXIS2_CALL
axis2_svc_name_free(struct axis2_svc_name *svc_name,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (svc_name->qname)
    {
        axutil_qname_free(svc_name->qname, env);
    }

    if (svc_name->endpoint_name)
    {
        AXIS2_FREE(env->allocator, svc_name->endpoint_name);
    }

    AXIS2_FREE(env->allocator, svc_name);

    return;
}
