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

#include <axis2_arch_file_data.h>
#include <string.h>
#include <axutil_class_loader.h>

struct axis2_arch_file_data
{
    axutil_file_t *file;
    int type;
    axis2_char_t *msg_recv;
    axis2_char_t *module_name;
    axis2_char_t *module_dll_name;
    axis2_char_t *name;
    /*
     * To store services in a serviceGroup. If there are wsdl for those 
     * servics ,so wsdl service will be created for each wsdl an those will be 
     * temporarily store in this table
     */
    axutil_hash_t *svc_map;
    axutil_array_list_t *deployable_svcs;

};

AXIS2_EXTERN axis2_arch_file_data_t *AXIS2_CALL
axis2_arch_file_data_create(const axutil_env_t *env)
{
    axis2_arch_file_data_t *arch_file_data = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    arch_file_data = (axis2_arch_file_data_t *) AXIS2_MALLOC(env->
        allocator, sizeof(axis2_arch_file_data_t));


    if (!arch_file_data)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    arch_file_data->file = NULL;
    arch_file_data->type = 0;
    arch_file_data->msg_recv = NULL;
    arch_file_data->module_name = NULL;
    arch_file_data->module_dll_name = NULL;
    arch_file_data->name = NULL;
    arch_file_data->svc_map = NULL;
    arch_file_data->deployable_svcs = NULL;

    arch_file_data->deployable_svcs = axutil_array_list_create(env, 0);
    if (!arch_file_data->deployable_svcs)
    {
        axis2_arch_file_data_free(arch_file_data, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    return arch_file_data;
}

AXIS2_EXTERN axis2_arch_file_data_t *AXIS2_CALL
axis2_arch_file_data_create_with_type_and_file(const axutil_env_t *env,
    int type,
    axutil_file_t *file)
{
    axis2_arch_file_data_t *arch_file_data = NULL;
    arch_file_data = (axis2_arch_file_data_t *)

        axis2_arch_file_data_create(env);
    if (!arch_file_data)
    {
        return NULL;
    }

    arch_file_data->type = type;
    arch_file_data->file =  axutil_file_clone(file, env);
    return arch_file_data;
}

AXIS2_EXTERN axis2_arch_file_data_t *AXIS2_CALL
axis2_arch_file_data_create_with_type_and_name(const axutil_env_t *env,
    int type,
    const axis2_char_t *name)
{
    axis2_arch_file_data_t *arch_file_data = NULL;
    arch_file_data = (axis2_arch_file_data_t *)
        axis2_arch_file_data_create(env);
    if (!arch_file_data)
    {
        return NULL;
    }
    arch_file_data->type = type;
    arch_file_data->name = axutil_strdup(env, name);
    return arch_file_data;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_arch_file_data_free(axis2_arch_file_data_t *arch_file_data,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (arch_file_data->file)
    {
        axutil_file_free(arch_file_data->file, env);
    }
    if (arch_file_data->msg_recv)
    {
        AXIS2_FREE(env->allocator, arch_file_data->msg_recv);
    }
    if (arch_file_data->module_name)
    {
        AXIS2_FREE(env->allocator, arch_file_data->module_name);
    }
    if (arch_file_data->module_dll_name)
    {
        AXIS2_FREE(env->allocator, arch_file_data->module_dll_name);
    }
    if (arch_file_data->name)
    {
        AXIS2_FREE(env->allocator, arch_file_data->name);
    }

    if (arch_file_data->svc_map)
    {
        axutil_hash_index_t *hi = NULL;
        void *val = NULL;

        for (hi = axutil_hash_first(arch_file_data->svc_map, env); hi;
            hi = axutil_hash_next(env, hi))
        {
            axis2_svc_t *svc = NULL;
            axutil_hash_this(hi, NULL, NULL, &val);
            svc = (axis2_svc_t *) val;
            if (svc)
            {
                axis2_svc_free(svc, env);
            }
        }
        axutil_hash_free(arch_file_data->svc_map, env);
    }
    if (arch_file_data->deployable_svcs)
    {
        axutil_array_list_free(arch_file_data->deployable_svcs, env);
    }

    if (arch_file_data)
    {
        AXIS2_FREE(env->allocator, arch_file_data);
    }

    return;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
axis2_arch_file_data_get_msg_recv(const axis2_arch_file_data_t *arch_file_data,
    const axutil_env_t *env)
{
    return arch_file_data->msg_recv;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_arch_file_data_set_msg_recv(axis2_arch_file_data_t *arch_file_data,
    const axutil_env_t *env,
    axis2_char_t *msg_recv)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_recv, AXIS2_FAILURE);

    if (arch_file_data->msg_recv)
    {
        AXIS2_FREE(env->allocator, arch_file_data->msg_recv);
        arch_file_data->msg_recv = NULL;
    }
    arch_file_data->msg_recv = axutil_strdup(env, msg_recv);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
axis2_arch_file_data_get_name(const axis2_arch_file_data_t *arch_file_data,
    const axutil_env_t *env)
{
    return  axutil_file_get_name(arch_file_data->file, env);
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
axis2_arch_file_data_get_svc_name(const axis2_arch_file_data_t *arch_file_data,
    const axutil_env_t *env)
{
    axis2_char_t *svc_name = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    if (arch_file_data->file)
    {
        svc_name =  axutil_file_get_name(arch_file_data->file, env);
    }
    else
    {
        svc_name = arch_file_data->name;
    }

    return svc_name;
}

AXIS2_EXTERN int AXIS2_CALL
axis2_arch_file_data_get_type(const axis2_arch_file_data_t *arch_file_data,
    const axutil_env_t *env)
{
    return arch_file_data->type;
}

AXIS2_EXTERN axutil_file_t *AXIS2_CALL
axis2_arch_file_data_get_file(const axis2_arch_file_data_t *arch_file_data,
    const axutil_env_t *env)
{
    return arch_file_data->file;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
axis2_arch_file_data_get_module_name(const axis2_arch_file_data_t *arch_file_data,
    const axutil_env_t *env)
{
    axis2_char_t *module_name = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    if (arch_file_data->file)
    {
        module_name =  axutil_file_get_name(arch_file_data->file, env);
    }
    else
    {
        module_name = arch_file_data->module_name;
    }
    return module_name;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_arch_file_data_set_module_name(axis2_arch_file_data_t *arch_file_data,
    const axutil_env_t *env,
    axis2_char_t *module_name)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, module_name, AXIS2_FAILURE);

    if (arch_file_data->module_name)
    {
        AXIS2_FREE(env->allocator, arch_file_data->module_name);
        arch_file_data->module_name = NULL;
    }
    arch_file_data->module_name = axutil_strdup(env, module_name);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
axis2_arch_file_data_get_module_dll_name(const axis2_arch_file_data_t *arch_file_data,
    const axutil_env_t *env)
{
    return arch_file_data->module_dll_name;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_arch_file_data_set_module_dll_name(axis2_arch_file_data_t *arch_file_data,
    const axutil_env_t *env,
    axis2_char_t *module_dll_name)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, module_dll_name, AXIS2_FAILURE);

    if (arch_file_data->module_dll_name)
    {
        AXIS2_FREE(env->allocator, arch_file_data->module_dll_name);
        arch_file_data->module_dll_name = NULL;
    }
    arch_file_data->module_dll_name = axutil_strdup(env, module_dll_name);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_arch_file_data_add_svc(axis2_arch_file_data_t *arch_file_data,
    const axutil_env_t *env,
    axis2_svc_t *svc_desc)
{
    const axutil_qname_t *svc_qname = NULL;
    axis2_char_t *svc_name = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, svc_desc, AXIS2_FAILURE);

    svc_qname = axis2_svc_get_qname(svc_desc, env);
    svc_name = axutil_qname_to_string((axutil_qname_t *)svc_qname, env);
    if (!arch_file_data->svc_map)
    {
        arch_file_data->svc_map = axutil_hash_make(env);
        if (!arch_file_data->svc_map)
        {
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            return AXIS2_FAILURE;
        }
    }
    axutil_hash_set(arch_file_data->svc_map, svc_name, AXIS2_HASH_KEY_STRING,
        svc_desc);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN struct axis2_svc *AXIS2_CALL
axis2_arch_file_data_get_svc(const axis2_arch_file_data_t *arch_file_data,
    const axutil_env_t *env,
    axis2_char_t *svc_name)
{
    axis2_svc_t *svc = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, svc_name, AXIS2_FAILURE);

    if (arch_file_data->svc_map)
    {
        svc = (axis2_svc_t *) axutil_hash_get(arch_file_data->svc_map, svc_name,
            AXIS2_HASH_KEY_STRING);
    }
    else
    {
        return NULL;
    }
    return svc;
}

AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
axis2_arch_file_data_get_svc_map(const axis2_arch_file_data_t *arch_file_data,
    const axutil_env_t *env)
{
    return arch_file_data->svc_map;
}

AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
axis2_arch_file_data_get_deployable_svcs(const axis2_arch_file_data_t *arch_file_data,
    const axutil_env_t *env)
{
    return arch_file_data->deployable_svcs;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_arch_file_data_set_deployable_svcs(axis2_arch_file_data_t *arch_file_data,
    const axutil_env_t *env,
    axutil_array_list_t *deployable_svcs)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, deployable_svcs, AXIS2_FAILURE);
    if (arch_file_data->deployable_svcs)
    {
        AXIS2_FREE(env->allocator, arch_file_data->deployable_svcs);
        arch_file_data->deployable_svcs = NULL;
    }
    arch_file_data->deployable_svcs = deployable_svcs;
    return AXIS2_SUCCESS;
}

