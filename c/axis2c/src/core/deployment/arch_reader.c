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

#include <axis2_arch_reader.h>
#include <string.h>
#include <axutil_class_loader.h>
#include <axis2_svc_builder.h>
#include <axis2_module_builder.h>
#include <axis2_svc.h>

struct axis2_arch_reader
{
    axis2_desc_builder_t *desc_builder;
};

AXIS2_EXTERN axis2_arch_reader_t *AXIS2_CALL
axis2_arch_reader_create(const axutil_env_t *env)
{
    axis2_arch_reader_t *arch_reader = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    arch_reader = (axis2_arch_reader_t *) AXIS2_MALLOC(env->
        allocator, sizeof(axis2_arch_reader_t));

    if (!arch_reader)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    arch_reader->desc_builder = NULL;

    return arch_reader;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_arch_reader_free(axis2_arch_reader_t *arch_reader,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    /* desc builder is owned by dep_engine, so do not free it here */

    if (arch_reader)
    {
        AXIS2_FREE(env->allocator, arch_reader);
    }

    return;
}

AXIS2_EXTERN struct axis2_svc *AXIS2_CALL
axis2_arch_reader_create_svc(axis2_arch_reader_t *arch_reader,
    const axutil_env_t *env,
    struct axis2_arch_file_data *file)
{
    axis2_svc_t *svc = NULL;
    svc = axis2_svc_create(env);
    return svc;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_arch_reader_process_svc_grp(axis2_arch_reader_t *arch_reader,
    const axutil_env_t *env,
    axis2_char_t *file_name,
    struct axis2_dep_engine *dep_engine,
    axis2_svc_grp_t *svc_grp)
{
    axis2_status_t status = AXIS2_FAILURE;
    axis2_char_t *svcs_xml = NULL;
    axis2_char_t *repos_path = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, file_name, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, dep_engine, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, svc_grp, AXIS2_FAILURE);

    repos_path = axis2_dep_engine_get_repos_path(dep_engine, env);

    svcs_xml = axutil_strcat(env, repos_path, AXIS2_PATH_SEP_STR,
        AXIS2_SERVICE_FOLDER, AXIS2_PATH_SEP_STR, file_name,
        AXIS2_PATH_SEP_STR, AXIS2_SVC_XML, NULL);

    if (!svcs_xml)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    status = axutil_file_handler_access(svcs_xml, AXIS2_F_OK);
    if (AXIS2_SUCCESS == status)
    {
        struct axis2_arch_file_data *arch_file_data = NULL;
        axis2_char_t *svc_name = NULL;

        status = axis2_arch_reader_build_svc_grp(arch_reader, env, svcs_xml,
            dep_engine, svc_grp);
        if (AXIS2_SUCCESS != status)
        {
            return status;
        }
        arch_file_data = axis2_dep_engine_get_current_file_item(dep_engine, env);
        svc_name = axis2_arch_file_data_get_svc_name(arch_file_data, env);
         axis2_svc_grp_set_name(svc_grp, env, svc_name);
    }
    else
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_SERVICE_XML_NOT_FOUND,
            AXIS2_FAILURE);
        status = AXIS2_FAILURE;
    }
    AXIS2_FREE(env->allocator, svcs_xml);
    return status;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_arch_reader_build_svc_grp(axis2_arch_reader_t *arch_reader,
    const axutil_env_t *env,
    axis2_char_t *svc_xml,
    axis2_dep_engine_t *dep_engine,
    axis2_svc_grp_t *svc_grp)
{
    axis2_char_t *root_element_name = NULL;
    axiom_node_t *svcs = NULL;
    axiom_element_t *svcs_element = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, svc_xml, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, dep_engine, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, svc_grp, AXIS2_FAILURE);

    arch_reader->desc_builder =
        axis2_desc_builder_create_with_file_and_dep_engine(env, svc_xml,
            dep_engine);
    if (!arch_reader->desc_builder)
    {
        return AXIS2_FAILURE;
    }
    axis2_dep_engine_add_desc_builder(dep_engine, env, arch_reader->desc_builder);

    svcs = axis2_desc_builder_build_om(arch_reader->desc_builder, env);

    if (svcs)
    {
        svcs_element = axiom_node_get_data_element(svcs, env);
        if (svcs_element)
        {
            root_element_name = axiom_element_get_localname(svcs_element, env);
        }
    }

    if (root_element_name && 0 == axutil_strcmp(AXIS2_SVC_ELEMENT, root_element_name))
    {
        axis2_svc_t *svc = NULL;
        axis2_svc_builder_t *svc_builder = NULL;
        axis2_arch_file_data_t *file_data = NULL;
        axutil_array_list_t *dep_svcs = NULL;
        axis2_char_t *svc_name = NULL;

        file_data = axis2_dep_engine_get_current_file_item(dep_engine, env);
        svc_name = axis2_arch_file_data_get_name(file_data, env);
        svc = axis2_arch_file_data_get_svc(file_data, env, svc_name);
        if (!svc)
        {
            axutil_qname_t *svc_qname = NULL;

            svc_qname = axutil_qname_create(env, svc_name, NULL, NULL);
            svc = axis2_svc_create_with_qname(env, svc_qname);
            status = axis2_arch_file_data_add_svc(file_data, env, svc);
            axutil_qname_free(svc_qname, env);
            if (AXIS2_SUCCESS != status)
            {
                axis2_svc_free(svc, env);
                return status;
            }
        }
        axis2_svc_set_parent(svc, env, svc_grp);

        svc_builder = axis2_svc_builder_create_with_dep_engine_and_svc(env,
            dep_engine, svc);
        status = axis2_svc_builder_populate_svc(svc_builder, env, svcs);
        axis2_dep_engine_add_svc_builder(dep_engine, env, svc_builder);
        if (AXIS2_SUCCESS != status)
        {
            AXIS2_LOG_INFO(env->log, AXIS2_LOG_SI, "populating service is not successful");

            return AXIS2_FAILURE;
        }

        dep_svcs = axis2_arch_file_data_get_deployable_svcs(file_data, env);
        if (!dep_svcs)
        {
            return AXIS2_FAILURE;
        }
        status = axutil_array_list_add(dep_svcs, env, svc);
        if (AXIS2_SUCCESS != status)
        {
            return AXIS2_FAILURE;
        }

    }
    else if (root_element_name &&
        0 == axutil_strcmp(AXIS2_SVC_GRP_ELEMENT, root_element_name))
    {
        axis2_svc_grp_builder_t *grp_builder = NULL;
        grp_builder = axis2_svc_grp_builder_create_with_svc_and_dep_engine(env,
            svcs, dep_engine);
        status = axis2_svc_grp_builder_populate_svc_grp(grp_builder, env, svc_grp);
        axis2_dep_engine_add_svc_grp_builder(dep_engine, env, grp_builder);
    }
    return status;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_arch_reader_read_module_arch(axis2_arch_reader_t *arch_reader,
    const axutil_env_t *env,
    axis2_char_t *file_name,
    axis2_dep_engine_t *dep_engine,
    axis2_module_desc_t *module_desc)
{
    axis2_status_t status = AXIS2_FAILURE;
    axis2_char_t *module_xml = NULL;
    axis2_char_t *repos_path = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, file_name, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, dep_engine, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, module_desc, AXIS2_FAILURE);

    repos_path = axis2_dep_engine_get_repos_path(dep_engine, env);
    module_xml = axutil_strcat(env, repos_path, AXIS2_PATH_SEP_STR,
        AXIS2_MODULE_FOLDER, AXIS2_PATH_SEP_STR, file_name,
        AXIS2_PATH_SEP_STR, AXIS2_MODULE_XML, NULL);
    if (!module_xml)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    status = axutil_file_handler_access(module_xml, AXIS2_F_OK);

    if (AXIS2_SUCCESS == status)
    {
        axis2_module_builder_t *module_builder = NULL;
        module_builder =
            axis2_module_builder_create_with_file_and_dep_engine_and_module(env,
                module_xml, dep_engine, module_desc);
        status = axis2_module_builder_populate_module(module_builder, env);
        axis2_dep_engine_add_module_builder(dep_engine, env, module_builder);
    }
    else
    {
        AXIS2_ERROR_SET(env->error,
            AXIS2_ERROR_MODULE_XML_NOT_FOUND_FOR_THE_MODULE, AXIS2_FAILURE);
        status = AXIS2_FAILURE;
    }
    AXIS2_FREE(env->allocator, module_xml);
    return status;
}

AXIS2_EXTERN axutil_file_t *AXIS2_CALL
axis2_arch_reader_create_module_arch(axis2_arch_reader_t *arch_reader,
    const axutil_env_t *env,
    axis2_char_t *module_name)
{
    axutil_file_t *file = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    file = axutil_file_create(env);
    if (!file)
    {
        return NULL;
    }
     axutil_file_set_name(file, env, module_name);
    return file;
}


