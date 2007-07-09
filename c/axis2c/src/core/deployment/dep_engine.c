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

#include "axis2_dep_engine.h"
#include <axutil_array_list.h>
#include <axis2_deployment.h>
#include <axutil_file_handler.h>
#include <axutil_dll_desc.h>
#include <axis2_flow.h>
#include <axis2_arch_reader.h>
#include <axis2_module_builder.h>
#include <axis2_svc_builder.h>
#include <axis2_svc_grp_builder.h>
#include <axiom_node.h>
#include <axutil_class_loader.h>
#include <axutil_string.h>
#include <axutil_utils.h>
#include <axis2_core_utils.h>
#include <axis2_module.h>

struct axis2_dep_engine
{
    axis2_arch_file_data_t *curr_file;
    axis2_arch_reader_t *arch_reader;

    /**
     * to keep a ref to engine register
     * this ref will pass to engine when it call start()
     * method
     */
    axis2_conf_t *conf;
    axis2_char_t *axis2_repos;
    axis2_bool_t hot_dep;   /* to do hot deployment or not */
    axis2_bool_t hot_update;  /* to do hot update or not */

    /**
     * This will store all the web Services to deploy
     */
    axutil_array_list_t *ws_to_deploy;

    /**
     * this will store all the web Services to undeploy
     */
    axutil_array_list_t *ws_to_undeploy;
    axis2_phases_info_t *phases_info; /* to store phases list in axis2.xml */

    /**
     * this constructor for the testing
     */
    axis2_char_t *folder_name;

    /**
     * Full path to the server xml file(axis2.xml)
     */
    axis2_char_t *conf_name;

    /**
     * To store the module specified in the server.xml at the document parsing 
     * time
     */
    axutil_array_list_t *module_list;
    axis2_repos_listener_t *repos_listener; /*Added this here to help with freeing
    memory allocated for this - Samisa*/
    axis2_conf_builder_t *conf_builder;
    axis2_svc_builder_t *svc_builder;
    axutil_array_list_t *desc_builders;
    axutil_array_list_t *module_builders;
    axutil_array_list_t *svc_builders;
    axutil_array_list_t *svc_grp_builders;
};

static axis2_status_t
axis2_dep_engine_set_dep_features(axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env);

static axis2_status_t
axis2_dep_engine_check_client_home(axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env,
    const axis2_char_t *client_home);

static axis2_status_t
axis2_dep_engine_engage_modules(axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env);

static axis2_status_t
axis2_dep_engine_validate_system_predefined_phases(axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env);

static axis2_status_t
axis2_dep_engine_add_new_svc(axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env,
    axis2_svc_grp_t *svc_metadata);

static axis2_status_t
axis2_dep_engine_load_module_dll(axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env,
    axis2_module_desc_t *module_desc);

static axis2_status_t
axis2_dep_engine_add_module_flow_handlers(axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env,
    axis2_flow_t *flow,
    axutil_hash_t *handler_create_func_map);

static axis2_status_t
axis2_dep_engine_add_new_module(axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env,
    axis2_module_desc_t *module_metadata);

static axis2_char_t *
axis2_dep_engine_get_axis_svc_name(const axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env,
    axis2_char_t *file_name);

AXIS2_EXTERN axis2_dep_engine_t *AXIS2_CALL
axis2_dep_engine_create(const axutil_env_t *env)
{
    axis2_dep_engine_t *dep_engine = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    dep_engine = (axis2_dep_engine_t *) AXIS2_MALLOC(env->allocator,
        sizeof(axis2_dep_engine_t));

    if (! dep_engine)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    dep_engine->conf = NULL;
    dep_engine->axis2_repos = NULL;
    dep_engine->curr_file = NULL;
    dep_engine->arch_reader = NULL;
    dep_engine->ws_to_deploy = NULL;
    dep_engine->ws_to_undeploy = NULL;
    dep_engine->phases_info = NULL;
    dep_engine->module_list = NULL;
    dep_engine->folder_name = NULL;
    dep_engine->conf_name = NULL;
    dep_engine->repos_listener = NULL;
    dep_engine->conf_builder = NULL;
    dep_engine->svc_builder = NULL;
    dep_engine->desc_builders = NULL;
    dep_engine->module_builders = NULL;
    dep_engine->svc_builders = NULL;
    dep_engine->svc_grp_builders = NULL;

    dep_engine->ws_to_deploy = axutil_array_list_create(env, 0);
    if (!(dep_engine->ws_to_deploy))
    {
        axis2_dep_engine_free(dep_engine, env);
        return NULL;
    }
    
    dep_engine->desc_builders = axutil_array_list_create(env, 0);
    dep_engine->module_builders = axutil_array_list_create(env, 0);
    dep_engine->svc_builders = axutil_array_list_create(env, 0);
    dep_engine->svc_grp_builders = axutil_array_list_create(env, 0);

    dep_engine->phases_info = axis2_phases_info_create(env);
    if (!(dep_engine->phases_info))
    {
        axis2_dep_engine_free(dep_engine, env);
        return NULL;
    }

    return dep_engine;
}

AXIS2_EXTERN axis2_dep_engine_t *AXIS2_CALL
axis2_dep_engine_create_with_repos_name(const axutil_env_t *env,
    const axis2_char_t *repos_path)
{
    axis2_dep_engine_t *dep_engine = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    dep_engine = (axis2_dep_engine_t *)
        axis2_dep_engine_create_with_repos_name_and_svr_xml_file(env,
            repos_path, AXIS2_SERVER_XML_FILE);
    if (!dep_engine)
    {
        return NULL;
    }

    return dep_engine;
}

AXIS2_EXTERN axis2_dep_engine_t *AXIS2_CALL
axis2_dep_engine_create_with_repos_name_and_svr_xml_file(const axutil_env_t *env,
    const axis2_char_t *repos_path,
    const axis2_char_t *svr_xml_file)
{
    axis2_dep_engine_t *dep_engine = NULL;
    axis2_char_t *conf_file_l = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, repos_path, NULL);
    AXIS2_PARAM_CHECK(env->error, svr_xml_file, NULL);
    if (0 == axutil_strcmp("", repos_path))
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_REPO_CAN_NOT_BE_NULL,
            AXIS2_FAILURE);
        return NULL;
    }

    dep_engine = (axis2_dep_engine_t *) axis2_dep_engine_create(env);

    if (!dep_engine)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    status = axutil_file_handler_access(repos_path, AXIS2_F_OK);
    if (AXIS2_SUCCESS != status)
    {
        axis2_dep_engine_free(dep_engine, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_REPOSITORY_NOT_EXIST,
            AXIS2_FAILURE);
        return NULL;
    }

    dep_engine->folder_name = axutil_strdup(env, repos_path);
    if (! dep_engine->folder_name)
    {
        axis2_dep_engine_free(dep_engine, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    dep_engine->axis2_repos = axutil_strdup(env, repos_path);
    if (!dep_engine->axis2_repos)
    {
        axis2_dep_engine_free(dep_engine, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    conf_file_l = axutil_stracat(env, repos_path, AXIS2_PATH_SEP_STR);
    dep_engine->conf_name = axutil_stracat(env, conf_file_l, svr_xml_file);
    AXIS2_FREE(env->allocator, conf_file_l);
    if (!dep_engine->conf_name)
    {
        axis2_dep_engine_free(dep_engine, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_REPO_CAN_NOT_BE_NULL, AXIS2_FAILURE);
        return NULL;
    }
    status = axutil_file_handler_access(dep_engine->conf_name, AXIS2_F_OK);
    if (AXIS2_SUCCESS != status)
    {
        axis2_dep_engine_free(dep_engine, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_CONFIG_NOT_FOUND,
            AXIS2_FAILURE);
        return NULL;
    }

    return dep_engine;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_dep_engine_free(axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (dep_engine->curr_file)
    {
        axis2_arch_file_data_free(dep_engine->curr_file, env);
    }

    if (dep_engine->phases_info)
    {
        axis2_phases_info_free(dep_engine->phases_info, env);
    }

    if (dep_engine->conf_builder)
    {
        axis2_conf_builder_free(dep_engine->conf_builder, env);
    }

    if (dep_engine->arch_reader)
    {
        axis2_arch_reader_free(dep_engine->arch_reader, env);
    }

    if (dep_engine->svc_builder)
    {
        axis2_svc_builder_free(dep_engine->svc_builder, env);
    }

    if (dep_engine->ws_to_deploy)
    {
        int i = 0;
        int size = 0;

        size = axutil_array_list_size(dep_engine->ws_to_deploy, env);
        for (i = 0; i < size; i++)
        {
            axis2_arch_file_data_t *file_data = NULL;

            file_data = (axis2_arch_file_data_t *)
            axutil_array_list_get(dep_engine->ws_to_deploy, env, i);
            axis2_arch_file_data_free(file_data, env);
        }
        axutil_array_list_free(dep_engine->ws_to_deploy, env);
        dep_engine->ws_to_deploy = NULL;
    }

    if (dep_engine->desc_builders)
    {
        int i = 0;
        int size = 0;

        size = axutil_array_list_size(dep_engine->desc_builders, env);
        for (i = 0; i < size; i++)
        {
            axis2_desc_builder_t *desc_builder = NULL;

            desc_builder = (axis2_desc_builder_t *)
            axutil_array_list_get(dep_engine->desc_builders, env, i);
            axis2_desc_builder_free(desc_builder, env);
        }
        axutil_array_list_free(dep_engine->desc_builders, env);
    }

    if (dep_engine->module_builders)
    {
        int i = 0;
        int size = 0;

        size = axutil_array_list_size(dep_engine->module_builders, env);
        for (i = 0; i < size; i++)
        {
            axis2_module_builder_t *module_builder = NULL;

            module_builder = (axis2_module_builder_t *)
            axutil_array_list_get(dep_engine->module_builders, env, i);
            axis2_module_builder_free(module_builder, env);
        }
        axutil_array_list_free(dep_engine->module_builders, env);
    }

    if (dep_engine->svc_builders)
    {
        int i = 0;
        int size = 0;

        size = axutil_array_list_size(dep_engine->svc_builders, env);
        for (i = 0; i < size; i++)
        {
            axis2_svc_builder_t *svc_builder = NULL;

            svc_builder = (axis2_svc_builder_t *)
            axutil_array_list_get(dep_engine->svc_builders, env, i);
            axis2_svc_builder_free(svc_builder, env);
        }
        axutil_array_list_free(dep_engine->svc_builders, env);
    }

    if (dep_engine->svc_grp_builders)
    {
        int i = 0;
        int size = 0;

        size = axutil_array_list_size(dep_engine->svc_grp_builders, env);
        for (i = 0; i < size; i++)
        {
            axis2_svc_grp_builder_t *svc_grp_builder = NULL;

            svc_grp_builder = (axis2_svc_grp_builder_t *)
            axutil_array_list_get(dep_engine->svc_grp_builders, env, i);
            axis2_svc_grp_builder_free(svc_grp_builder, env);
        }
        axutil_array_list_free(dep_engine->svc_grp_builders, env);
    }

    if (dep_engine->ws_to_undeploy)
    {
        int i = 0;
        int size = 0;

        size = axutil_array_list_size(dep_engine->ws_to_undeploy, env);

        for (i = 0; i < size; i++)
        {
            axis2_arch_file_data_t *file_data = NULL;

            file_data = (axis2_arch_file_data_t *)
                axutil_array_list_get(dep_engine->ws_to_undeploy, env, i);
            axis2_arch_file_data_free(file_data, env);
        }
        axutil_array_list_free(dep_engine->ws_to_undeploy, env);
        dep_engine->ws_to_undeploy = NULL;
    }
    if (dep_engine->module_list)
    {
        int size = 0;
        int i = 0;

        size = axutil_array_list_size(dep_engine->module_list, env);

        for (i = 0; i < size; i++)
        {
            axutil_qname_t *qname = NULL;
            qname = axutil_array_list_get(dep_engine->module_list, env, i);
            if (qname)
            {
                axutil_qname_free(qname, env);
            }
        }
        axutil_array_list_free(dep_engine->module_list, env);
    }
    if (dep_engine->folder_name)
    {
        AXIS2_FREE(env->allocator, dep_engine->folder_name);
    }
    if (dep_engine->conf_name)
    {
        AXIS2_FREE(env->allocator, dep_engine->conf_name);
    }
    if (dep_engine->axis2_repos)
    {
        AXIS2_FREE(env->allocator, dep_engine->axis2_repos);
    }

    if (dep_engine->repos_listener)
    {
        axis2_repos_listener_free(dep_engine->repos_listener, env);
    }

    if (dep_engine)
    {
        AXIS2_FREE(env->allocator, dep_engine);
    }

    return;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_dep_engine_add_module(axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env,
    axutil_qname_t *module_qname)
{
    axutil_qname_t *qname = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, module_qname, AXIS2_FAILURE);

    qname = axutil_qname_clone(module_qname, env);
    if (!dep_engine->module_list)
    {
        dep_engine->module_list = axutil_array_list_create(env, 0);
        if (!dep_engine->module_list)
        {
            axutil_qname_free(qname, env);
            return AXIS2_FAILURE;
        }
    }
    return axutil_array_list_add(dep_engine->module_list, env, qname);
}

struct axis2_module_desc *AXIS2_CALL
axis2_dep_engine_get_module(const axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env,
    axutil_qname_t *module_name)
{
    AXIS2_PARAM_CHECK(env->error, module_name, NULL);

    return  axis2_conf_get_module(dep_engine->conf, env, module_name);
}

AXIS2_EXTERN struct axis2_arch_file_data *AXIS2_CALL
axis2_dep_engine_get_current_file_item(const axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env)
{
    return dep_engine->curr_file;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_dep_engine_add_ws_to_deploy(axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env,
    axis2_arch_file_data_t *file)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, file, AXIS2_FAILURE);

    return axutil_array_list_add(dep_engine->ws_to_deploy, env, file);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_dep_engine_add_ws_to_undeploy(axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env,
    axis2_ws_info_t *file)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, file, AXIS2_FAILURE);
    if (!(dep_engine->ws_to_undeploy))
    {
        dep_engine->ws_to_undeploy = axutil_array_list_create(env, 0);
    }
    return axutil_array_list_add(dep_engine->ws_to_undeploy, env, file);
}

AXIS2_EXTERN axis2_phases_info_t *AXIS2_CALL
axis2_dep_engine_get_phases_info(const axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env)
{
    return dep_engine->phases_info;
}

AXIS2_EXTERN axis2_conf_t *AXIS2_CALL
axis2_dep_engine_get_axis_conf(const axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env)
{
    return dep_engine->conf;
}

/**
 * To set hotDeployment and hot update
 */
static axis2_status_t
axis2_dep_engine_set_dep_features(axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env)
{
    axis2_char_t *value = NULL;
    axutil_param_t *para_hot_dep = NULL;
    axutil_param_t *para_hot_update = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    para_hot_dep =  axis2_conf_get_param(dep_engine->conf, env,
        AXIS2_HOTDEPLOYMENT);
    para_hot_update =  axis2_conf_get_param(dep_engine->conf, env,
        AXIS2_HOTUPDATE);

    if (para_hot_dep)
    {
        value = (axis2_char_t *) axutil_param_get_value(para_hot_dep, env);
        if (0 == axutil_strcasecmp("false", value))
        {
            dep_engine->hot_dep = AXIS2_FALSE;
        }
    }
    if (para_hot_update)
    {
        value = (axis2_char_t *) axutil_param_get_value(para_hot_update, env);
        if (0 == axutil_strcasecmp("false", value))
        {
            dep_engine->hot_update = AXIS2_FALSE;
        }
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_conf_t *AXIS2_CALL
axis2_dep_engine_load(axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env)
{
    axis2_status_t status = AXIS2_FAILURE;
    axutil_array_list_t *out_fault_phases = NULL;
    axutil_array_list_t *new_out_fault_phases = NULL;
    AXIS2_ENV_CHECK(env, NULL);

    if (! dep_engine->conf_name)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_PATH_TO_CONFIG_CAN_NOT_BE_NULL,
            AXIS2_FAILURE);
        return NULL;
    }

    dep_engine->conf = axis2_conf_create(env);

    if (!dep_engine->conf)
    {
        return NULL;
    }

    dep_engine->conf_builder = 
        axis2_conf_builder_create_with_file_and_dep_engine_and_conf(env,
            dep_engine->conf_name, dep_engine, dep_engine->conf);
    if (!(dep_engine->conf_builder))
    {
        axis2_conf_free(dep_engine->conf, env);
        dep_engine->conf = NULL;
    }
    status = axis2_conf_builder_populate_conf(dep_engine->conf_builder, env);
    if (AXIS2_SUCCESS != status)
    {
        axis2_conf_free(dep_engine->conf, env);
        dep_engine->conf = NULL;
        return NULL;
    }
    status = axis2_dep_engine_set_dep_features(dep_engine, env);
    if (AXIS2_SUCCESS != status)
    {
        return NULL;
    }

    if (dep_engine->repos_listener)
    {
        axis2_repos_listener_free(dep_engine->repos_listener, env);
    }
    dep_engine->repos_listener =
        axis2_repos_listener_create_with_folder_name_and_dep_engine(env,
            dep_engine->folder_name, dep_engine);
    if (!dep_engine->repos_listener)
    {
        axis2_conf_free(dep_engine->conf, env);
        return NULL;
    }
    axis2_conf_set_repo(dep_engine->conf, env, dep_engine->axis2_repos);
    axis2_core_utils_calculate_default_module_version(env,
        axis2_conf_get_all_modules(dep_engine->conf, env),
        dep_engine->conf);
    status = axis2_dep_engine_validate_system_predefined_phases(dep_engine, env);
    if (AXIS2_SUCCESS != status)
    {
        axis2_repos_listener_free(dep_engine->repos_listener, env);
        axis2_conf_free(dep_engine->conf, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_MODULE_VALIDATION_FAILED,
            AXIS2_FAILURE);
        return NULL;
    }

    status =  axis2_conf_set_phases_info(dep_engine->conf, env,
        dep_engine->phases_info);
    out_fault_phases =
        axis2_phases_info_get_op_out_faultphases(dep_engine->phases_info, env);
    new_out_fault_phases = axis2_phases_info_copy_flow(env, out_fault_phases);
    if (out_fault_phases)
    {
        axutil_array_list_free(out_fault_phases, env);
    }
    axis2_conf_set_out_fault_phases(dep_engine->conf, env, new_out_fault_phases);
    if (AXIS2_SUCCESS != status)
    {
        axis2_repos_listener_free(dep_engine->repos_listener, env);
        axis2_conf_free(dep_engine->conf, env);
        return NULL;
    }

    status = axis2_dep_engine_engage_modules(dep_engine, env);
    if (AXIS2_SUCCESS != status)
    {
        axis2_repos_listener_free(dep_engine->repos_listener, env);
        axis2_conf_free(dep_engine->conf, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_MODULE_VALIDATION_FAILED,
            AXIS2_FAILURE);
        return NULL;
    }
    /*}*/

    return dep_engine->conf;
}


AXIS2_EXTERN axis2_conf_t *AXIS2_CALL
axis2_dep_engine_load_client(axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env,
    const axis2_char_t *client_home)
{
    axis2_bool_t is_repos_exist = AXIS2_FALSE;
    axis2_status_t status = AXIS2_FAILURE;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, client_home, NULL);

    dep_engine->axis2_repos = axutil_strdup(env, client_home);
    if (!dep_engine->axis2_repos)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    if (client_home && 0 != axutil_strcmp("", client_home))
    {
        status = axis2_dep_engine_check_client_home(dep_engine, env, client_home);
        if (AXIS2_SUCCESS == status)
        {
            is_repos_exist = AXIS2_TRUE;
        }
    }
    else
    {
        dep_engine->conf_name = axutil_strdup(env, AXIS2_CONFIGURATION_RESOURCE);
        if (!dep_engine->conf_name)
        {
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            return NULL;
        }
    }
    dep_engine->conf = axis2_conf_create(env);
    if (!dep_engine->conf)
    {
        return NULL;
    }
    dep_engine->conf_builder =
        axis2_conf_builder_create_with_file_and_dep_engine_and_conf(env,
            dep_engine->conf_name, dep_engine, dep_engine->conf);
    if (!(dep_engine->conf_builder))
    {
        axis2_conf_free(dep_engine->conf, env);
        dep_engine->conf = NULL;
    }
    status = axis2_conf_builder_populate_conf(dep_engine->conf_builder, env);
    if (AXIS2_SUCCESS != status)
    {
        axis2_conf_free(dep_engine->conf, env);
        dep_engine->conf = NULL;
        return NULL;
    }

    if (AXIS2_TRUE == is_repos_exist)
    {
        dep_engine->hot_dep = AXIS2_FALSE;
        dep_engine->hot_update = AXIS2_FALSE;
        if (dep_engine->repos_listener)
        {
            axis2_repos_listener_free(dep_engine->repos_listener, env);
        }
        dep_engine->repos_listener =
            axis2_repos_listener_create_with_folder_name_and_dep_engine(env,
                dep_engine->folder_name, dep_engine);
    }

    axis2_conf_set_repo(dep_engine->conf, env, dep_engine->axis2_repos);
    axis2_core_utils_calculate_default_module_version(env,
        axis2_conf_get_all_modules(dep_engine->conf, env),
        dep_engine->conf);
    axis2_conf_set_phases_info(dep_engine->conf, env,
         dep_engine->phases_info);
    status = axis2_dep_engine_engage_modules(dep_engine, env);
    if (AXIS2_FAILURE == status)
    {
        axis2_repos_listener_free(dep_engine->repos_listener, env);
        axis2_conf_free(dep_engine->conf, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_MODULE_VALIDATION_FAILED,
            AXIS2_FAILURE);
        return NULL;
    }

    return dep_engine->conf;
}


static axis2_status_t
axis2_dep_engine_check_client_home(axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env,
    const axis2_char_t *client_home)
{
    axis2_char_t *path_l = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    dep_engine->folder_name = axutil_strdup(env, client_home);
    if (!dep_engine->folder_name)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    path_l = axutil_stracat(env, client_home, AXIS2_PATH_SEP_STR);
    dep_engine->conf_name = axutil_stracat(env, path_l, AXIS2_SERVER_XML_FILE);
    AXIS2_FREE(env->allocator, path_l);
    if (!dep_engine->conf_name)
    {
        dep_engine->conf_name = axutil_strdup(env, AXIS2_CONFIGURATION_RESOURCE);
        if (!dep_engine->conf_name)
        {
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_CONFIG_NOT_FOUND,
                AXIS2_FAILURE)
            return AXIS2_FAILURE;
        }
    }
    status = axutil_file_handler_access(dep_engine->conf_name, AXIS2_F_OK);
    if (AXIS2_SUCCESS != status)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_CONFIG_NOT_FOUND,
            AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }

    return AXIS2_SUCCESS;
}

static axis2_status_t
axis2_dep_engine_engage_modules(axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env)
{
    int size = 0;
    int i = 0;
    axis2_status_t status = AXIS2_FAILURE;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (!dep_engine->module_list)
    {
        /* there are no modules */
        return AXIS2_SUCCESS;
    }
    size = axutil_array_list_size(dep_engine->module_list, env);

    for (i = 0; i < size; i++)
    {
        axutil_qname_t *qname = NULL;
        qname = (axutil_qname_t *)
            axutil_array_list_get(dep_engine->module_list, env, i);
        if (qname && dep_engine->conf)
        {
            status =  axis2_conf_engage_module(dep_engine->conf, env, qname);
            if (AXIS2_SUCCESS != status)
            {
                return status;
            }
        }
    }
    return AXIS2_SUCCESS;
}

static axis2_status_t
axis2_dep_engine_validate_system_predefined_phases(axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env)
{
    axutil_array_list_t *in_phases = NULL;
    axis2_char_t *phase0 = NULL;
    axis2_char_t *phase1 = NULL;
    axis2_char_t *phase2 = NULL;
    axis2_char_t *phase3 = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    in_phases = axis2_phases_info_get_in_phases(dep_engine->phases_info, env);
    if (in_phases)
    {
        phase0 = (axis2_char_t *) axutil_array_list_get(in_phases, env, 0);
        phase1 = (axis2_char_t *) axutil_array_list_get(in_phases, env, 1);
        phase2 = (axis2_char_t *) axutil_array_list_get(in_phases, env, 2);
        phase3 = (axis2_char_t *) axutil_array_list_get(in_phases, env, 3);
    }
    if ((phase0 && 0 != axutil_strcmp(phase0, AXIS2_PHASE_TRANSPORT_IN)) ||
        (phase1 && 0 != axutil_strcmp(phase1, AXIS2_PHASE_PRE_DISPATCH)) ||
        (phase2 && 0 != axutil_strcmp(phase2, AXIS2_PHASE_DISPATCH)) ||
        (phase3 && 0 != axutil_strcmp(phase3, AXIS2_PHASE_POST_DISPATCH)))
    {
        AXIS2_ERROR_SET(env->error, AXI2_ERROR_INVALID_PHASE, AXIS2_FAILURE);
        return AXIS2_SUCCESS;
    }

    return AXIS2_SUCCESS;
}

static axis2_status_t
axis2_dep_engine_add_new_svc(axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env,
    axis2_svc_grp_t *svc_metadata)
{
    axutil_array_list_t *svcs = NULL;
    int sizei = 0;
    int i = 0;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, svc_metadata, AXIS2_FAILURE);

    svcs = axis2_arch_file_data_get_deployable_svcs(dep_engine->curr_file,
        env);
    if (svcs)
    {
        sizei = axutil_array_list_size(svcs, env);
    }

    for (i = 0; i < sizei; i++)
    {
        axis2_svc_t *svc = NULL;
        axutil_file_t *file = NULL;
        axutil_array_list_t *grp_modules = NULL;
        axutil_array_list_t *list = NULL;
        int sizej = 0;
        int j = 0;
        axutil_hash_t *ops = NULL;
        axutil_hash_index_t *index_i = NULL;
        axis2_char_t *file_name = NULL;

        svc = (axis2_svc_t *) axutil_array_list_get(svcs, env, i);

        /*axis2_dep_engine_load_svc_props(dep_engine, env, svc);*/
        file = axis2_arch_file_data_get_file(dep_engine->curr_file, env);
        file_name =  axutil_file_get_name(file, env);
        axis2_svc_set_file_name(svc, env, file_name);

        /* modules from svc group */
        grp_modules =  axis2_svc_grp_get_all_module_qnames(svc_metadata, env);
        if (grp_modules)
        {
            sizej = axutil_array_list_size(grp_modules, env);
        }
        for (j = 0; j < sizej; j++)
        {
            axis2_module_desc_t *module_desc = NULL;
            axutil_qname_t *qmodulename = NULL;

            qmodulename = (axutil_qname_t *) axutil_array_list_get(grp_modules,
                env, j);
            module_desc =  axis2_conf_get_module(dep_engine->conf, env,
                qmodulename);
            if (module_desc)
            {
                axis2_svc_engage_module(svc, env, module_desc, dep_engine->conf);
            }
            else
            {
                AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
                    "Invalid module reference taken from conf");
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_MODUELE_REF,
                    AXIS2_FAILURE);
                return AXIS2_FAILURE;
            }
        }

        /* modules from <service> */
        list = axis2_svc_get_all_module_qnames(svc, env);
        sizej = axutil_array_list_size(list, env);
        for (j = 0; j < sizej; j++)
        {
            axis2_module_desc_t *module_desc = NULL;
            axutil_qname_t *qmodulename = NULL;

            qmodulename = (axutil_qname_t *) axutil_array_list_get(list,
                env, j);
            module_desc =  axis2_conf_get_module(dep_engine->conf, env,
                qmodulename);
            if (module_desc)
            {
                axis2_status_t status = AXIS2_FAILURE;
                status = axis2_svc_engage_module(svc, env, module_desc, dep_engine->conf);
                if(!status)
                {
                    return status;
                }
            }
            else
            {
                AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
                    "Invalid module reference taken from conf");
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_MODUELE_REF,
                    AXIS2_FAILURE);
                return AXIS2_FAILURE;
            }
        }

        ops = axis2_svc_get_all_ops(svc, env);
        for (index_i = axutil_hash_first(ops, env);
            index_i; index_i = axutil_hash_next(env, index_i))
        {
            void *v = NULL;
            axis2_op_t *op_desc = NULL;
            axutil_array_list_t *modules = NULL;
            int sizek = 0;
            int k = 0;

            axutil_hash_this(index_i, NULL, NULL, &v);
            op_desc = (axis2_op_t *)v;

            modules = axis2_op_get_all_module_qnames(op_desc, env);
            if (modules)
            {
                sizek = axutil_array_list_size(modules, env);
            }
            for (k = 0; k < sizek; k++)
            {
                axutil_qname_t *module_qname = NULL;
                axis2_module_desc_t *module = NULL;

                module_qname = (axutil_qname_t *) axutil_array_list_get(modules,
                    env, k);
                module =  axis2_conf_get_module(dep_engine->conf, env,
                    module_qname);

                if (module)
                {
                    axis2_op_engage_module(op_desc, env, module,
                        dep_engine->conf);
                }
                else
                {
                    AXIS2_ERROR_SET(env->error,
                        AXIS2_ERROR_INVALID_MODUELE_REF_BY_OP, AXIS2_FAILURE);
                    return AXIS2_FAILURE;
                }
            }
        }
         axis2_svc_grp_add_svc(svc_metadata, env, svc);
    }
    return  axis2_conf_add_svc_grp(dep_engine->conf, env, svc_metadata);
}

static axis2_status_t
axis2_dep_engine_load_module_dll(axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env,
    axis2_module_desc_t *module_desc)
{
    axis2_char_t *read_in_dll = NULL;
    axis2_module_t *module = NULL;
    axutil_dll_desc_t *dll_desc = NULL;
    axutil_param_t *impl_info_param = NULL;
    axutil_file_t *module_folder = NULL;
    AXIS2_TIME_T timestamp = 0;
    axis2_char_t *module_folder_path = NULL;
    axis2_char_t *temp_path = NULL;
    axis2_char_t *dll_path = NULL;
    axis2_status_t status = AXIS2_FAILURE;
    axis2_char_t *dll_name = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, module_desc, AXIS2_FAILURE);

    read_in_dll =
        axis2_arch_file_data_get_module_dll_name(dep_engine->curr_file, env);
    dll_desc = axutil_dll_desc_create(env);
    dll_name =  axutil_dll_desc_create_platform_specific_dll_name(dll_desc, env,
        read_in_dll);

    module_folder = axis2_arch_file_data_get_file(dep_engine->curr_file, env);
    timestamp =  axutil_file_get_timestamp(module_folder, env);
    axutil_dll_desc_set_timestamp(dll_desc, env, timestamp);
    module_folder_path =  axutil_file_get_path(module_folder, env);
    temp_path = axutil_stracat(env, module_folder_path, AXIS2_PATH_SEP_STR);
    dll_path = axutil_stracat(env, temp_path, dll_name);
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
        "axis2_dep_engine_load_module_dll: DLL path is : %s", dll_path);
    status =  axutil_dll_desc_set_name(dll_desc, env, dll_path);
    if (AXIS2_SUCCESS != status)
    {
        axutil_dll_desc_free(dll_desc, env);
        return AXIS2_FAILURE;
    }
    /* free all temp vars */
    AXIS2_FREE(env->allocator, temp_path);
    temp_path = NULL;
    AXIS2_FREE(env->allocator, dll_path);
    dll_path = NULL;

    axutil_dll_desc_set_type(dll_desc, env, AXIS2_MODULE_DLL);
    impl_info_param = axutil_param_create(env, read_in_dll, NULL);
    axutil_param_set_value(impl_info_param, env, dll_desc);
    axutil_param_set_value_free(impl_info_param, env, axutil_dll_desc_free_void_arg);
    axutil_class_loader_init(env);
    module = (axis2_module_t *) axutil_class_loader_create_dll(env,
        impl_info_param);
    /* We cannot free the created impl_info_param here because by freeing
     * so, it will free dll_desc which in turn unload the module. So we
     * add this as a param to module_desc
     */
    axis2_module_desc_add_param(module_desc, env, impl_info_param);
    return axis2_module_desc_set_module(module_desc, env, module);
}


static axis2_status_t
axis2_dep_engine_add_module_flow_handlers(axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env,
    axis2_flow_t *flow,
    axutil_hash_t *handler_create_func_map)
{
    int count = 0;
    int j = 0;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, flow, AXIS2_FAILURE);

    count = axis2_flow_get_handler_count(flow, env);

    for (j = 0; j < count; j++)
    {
        axis2_handler_desc_t *handlermd = NULL;
        axis2_handler_t *handler = NULL;
        const axutil_string_t *handler_name = NULL;
        AXIS2_HANDLER_CREATE_FUNC handler_create_func = NULL;

        handlermd = axis2_flow_get_handler(flow, env, j);
        handler_name = axis2_handler_desc_get_name(handlermd, env);
        handler_create_func = axutil_hash_get(handler_create_func_map,
            axutil_string_get_buffer(handler_name, env), AXIS2_HASH_KEY_STRING);
        handler = handler_create_func(env, handler_name);
        axis2_handler_init(handler, env, handlermd);
        axis2_handler_desc_set_handler(handlermd, env, handler);
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN void *AXIS2_CALL
axis2_dep_engine_get_handler_dll(const axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env,
    axis2_char_t *class_name)
{
    axutil_dll_desc_t *dll_desc = NULL;
    axutil_param_t *impl_info_param = NULL;
    axis2_handler_t *handler = NULL;
    axis2_char_t *dll_name = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, class_name, NULL);

    dll_desc = axutil_dll_desc_create(env);
    dll_name =
         axutil_dll_desc_create_platform_specific_dll_name(dll_desc, env,
             class_name);
    axutil_dll_desc_set_name(dll_desc, env, dll_name);
    axutil_dll_desc_set_type(dll_desc, env, AXIS2_HANDLER_DLL);
    axutil_class_loader_init(env);
    impl_info_param = axutil_param_create(env, NULL, NULL);
    axutil_param_set_value(impl_info_param, env, dll_desc);
    handler = (axis2_handler_t *) axutil_class_loader_create_dll(env,
        impl_info_param);

    return handler;
}


static axis2_status_t
axis2_dep_engine_add_new_module(axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env,
    axis2_module_desc_t *module_metadata)
{
    axis2_flow_t *in_flow = NULL;
    axis2_flow_t *out_flow = NULL;
    axis2_flow_t *in_fault_flow = NULL;
    axis2_flow_t *out_fault_flow = NULL;
    axis2_module_t *module = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    status = axis2_dep_engine_load_module_dll(dep_engine, env, module_metadata);
    if (AXIS2_SUCCESS != status)
    {
        return status;
    }
    module = axis2_module_desc_get_module(module_metadata, env);
    if (!module)
    {
        return AXIS2_FAILURE;
    }
    status = AXIS2_MODULE_FILL_HANDLER_CREATE_FUNC_MAP(module, env);
    if (AXIS2_SUCCESS != status)
    {
        return status;
    }

    in_flow = axis2_module_desc_get_in_flow(module_metadata, env);
    if (in_flow)
    {
        axis2_dep_engine_add_module_flow_handlers(dep_engine, env, in_flow,
            module->handler_create_func_map);
    }

    out_flow = axis2_module_desc_get_out_flow(module_metadata, env);
    if (out_flow)
    {
        axis2_dep_engine_add_module_flow_handlers(dep_engine, env, out_flow,
            module->handler_create_func_map);
    }

    in_fault_flow = axis2_module_desc_get_fault_in_flow(module_metadata, env);
    if (in_fault_flow)
    {
        axis2_dep_engine_add_module_flow_handlers(dep_engine, env, in_fault_flow,
            module->handler_create_func_map);
    }

    out_fault_flow = axis2_module_desc_get_fault_out_flow(module_metadata, env);
    if (out_fault_flow)
    {
        axis2_dep_engine_add_module_flow_handlers(dep_engine, env, out_fault_flow,
            module->handler_create_func_map);
    }

     axis2_conf_add_module(dep_engine->conf, env,
         module_metadata);

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_dep_engine_do_deploy(axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env)
{
    int size = 0;
    axis2_status_t status = AXIS2_FAILURE;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    size = axutil_array_list_size(dep_engine->ws_to_deploy, env);

    if (size > 0)
    {
        int i = 0;
        for (i = 0; i < size; i++)
        {
            int type = 0;
            axis2_svc_grp_t *svc_grp = NULL;
            axis2_char_t *file_name = NULL;
            axis2_module_desc_t *meta_data = NULL;
            axis2_arch_reader_t *arch_reader = NULL;

            dep_engine->curr_file = (axis2_arch_file_data_t *)
                axutil_array_list_get(dep_engine->ws_to_deploy, env, i);

            type = axis2_arch_file_data_get_type(dep_engine->curr_file, env);
            switch (type)
            {
                case AXIS2_SVC:
                    arch_reader = axis2_arch_reader_create(env);

                    svc_grp = axis2_svc_grp_create_with_conf(env,
                        dep_engine->conf);
                    file_name = axis2_arch_file_data_get_name(dep_engine->
                        curr_file, env);
                    status = axis2_arch_reader_process_svc_grp(arch_reader, env,
                        file_name, dep_engine, svc_grp);
                    if (AXIS2_SUCCESS != status)
                    {
                        axis2_arch_reader_free(arch_reader, env);
                        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_SVC,
                            AXIS2_FAILURE);
                        return status;
                    }
                    status = axis2_dep_engine_add_new_svc(dep_engine, env,
                        svc_grp);
                    if (AXIS2_SUCCESS != status)
                    {
                        axis2_arch_reader_free(arch_reader, env);
                        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_SVC,
                            AXIS2_FAILURE);
                        return status;
                    }
                    dep_engine->curr_file = NULL;
                    break;
                case AXIS2_MODULE:
                    arch_reader = axis2_arch_reader_create(env);
                    if (dep_engine->arch_reader)
                    {
                        axis2_arch_reader_free(dep_engine->arch_reader, env);
                    }
                    dep_engine->arch_reader = axis2_arch_reader_create(env);
                    meta_data = axis2_module_desc_create(env);
                    file_name = axis2_arch_file_data_get_name(dep_engine->
                        curr_file, env);
                    status = axis2_arch_reader_read_module_arch(
                        dep_engine->arch_reader, env, file_name, dep_engine,
                            meta_data);
                    if (AXIS2_SUCCESS != status)
                    {
                        axis2_arch_reader_free(arch_reader, env);
                        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_MODULE,
                            AXIS2_FAILURE);
                        return AXIS2_FAILURE;
                    }
                    status = axis2_dep_engine_add_new_module(dep_engine, env,
                        meta_data);
                    if (AXIS2_SUCCESS != status)
                    {
                        axis2_arch_reader_free(arch_reader, env);
                        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_MODULE,
                            AXIS2_FAILURE);
                        return AXIS2_FAILURE;
                    }

                    dep_engine->curr_file = NULL;
                    break;
            }
            axis2_arch_reader_free(arch_reader, env);
        }
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_dep_engine_undeploy(axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env)
{
    int size = 0;
    axis2_char_t *svc_name = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    size = axutil_array_list_size(dep_engine->ws_to_undeploy, env);

    if (size > 0)
    {
        int i = 0;
        for (i = 0; i < size; i++)
        {
            int type = 0;
            axis2_ws_info_t *ws_info = NULL;
            axutil_hash_t *faulty_svcs = NULL;

            ws_info = (axis2_ws_info_t *)
                axutil_array_list_get(dep_engine->ws_to_undeploy, env, i);
            type = axis2_ws_info_get_type(ws_info, env);
            if (type == AXIS2_SVC)
            {
                axis2_char_t *file_name = NULL;

                file_name = axis2_ws_info_get_file_name(ws_info, env);
                svc_name = axis2_dep_engine_get_axis_svc_name(dep_engine, env,
                    file_name);

                 axis2_conf_remove_svc(dep_engine->conf, env, svc_name);
            }
            faulty_svcs =  axis2_conf_get_all_faulty_svcs(dep_engine->conf, env);
            axutil_hash_set(faulty_svcs, svc_name, AXIS2_HASH_KEY_STRING, NULL);
        }

    }
    axutil_array_list_free(dep_engine->ws_to_undeploy, env);

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axis2_dep_engine_is_hot_update(axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env)
{
    return dep_engine->hot_update;
}

static axis2_char_t *
axis2_dep_engine_get_axis_svc_name(const axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env,
    axis2_char_t *file_name)
{
    axis2_char_t name_sep = '.';
    axis2_char_t *temp_name = NULL;
    axis2_char_t *ptr = NULL;
    axis2_char_t *file_name_l = NULL;
    axis2_char_t *svc_name = NULL;
    int len = 0;

    file_name_l = axutil_strdup(env, file_name);
    ptr = AXIS2_STRRCHR(file_name_l, AXIS2_PATH_SEP_CHAR);

    temp_name = ptr + 1;
    ptr = AXIS2_STRRCHR(temp_name, name_sep);
    ptr[0] = '\0';
    len = strlen(temp_name);
    svc_name = AXIS2_MALLOC(env->allocator, len + 1);
    sscanf(temp_name, "%s", svc_name);
    AXIS2_FREE(env->allocator, file_name_l);
    return svc_name;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_dep_engine_set_phases_info(axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env,
    axis2_phases_info_t *phases_info)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, phases_info, AXIS2_FAILURE);
    dep_engine->phases_info = phases_info;
    return AXIS2_SUCCESS;
}

/**
 * This method is used to fill a axisservice object using services.xml ,
 * first it should create
 * an axisservice object using WSDL and then fill that using given servic.xml 
 * and load all the requed
 * class and build the chains , finally add the  servicecontext to EngineContext \
 * and axisservice into EngineConfiguration
 */
AXIS2_EXTERN axis2_svc_t *AXIS2_CALL
axis2_dep_engine_build_svc(axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env,
    axis2_svc_t *svc,
    axis2_char_t *file_name)
{
    axiom_node_t *node = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, file_name, NULL);

    dep_engine->curr_file = axis2_arch_file_data_create_with_type_and_name(env,
        AXIS2_SVC, "");

    dep_engine->svc_builder =
        axis2_svc_builder_create_with_file_and_dep_engine_and_svc(env,
            file_name, dep_engine, svc);

    node = axis2_desc_builder_build_om(
        axis2_svc_builder_get_desc_builder(dep_engine->svc_builder, env),
        env);
    axis2_svc_builder_populate_svc(dep_engine->svc_builder, env, node);
    /*axis2_dep_engine_load_svc_props(dep_engine, env, svc);*/

    return svc;
}

/**
 * This method can be used to build ModuleDescription for a given module archiev file
 */
AXIS2_EXTERN axis2_module_desc_t *AXIS2_CALL
axis2_dep_engine_build_module(axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env,
    axutil_file_t *module_archive,
    axis2_conf_t *conf)
{
    axis2_module_desc_t *module_desc = NULL;
    axis2_module_t *module = NULL;
    axis2_phases_info_t *phases_info = NULL;
    axis2_arch_reader_t *arch_reader = NULL;
    axis2_flow_t *in_flow = NULL;
    axis2_flow_t *out_flow = NULL;
    axis2_flow_t *in_fault_flow = NULL;
    axis2_flow_t *out_fault_flow = NULL;
    axis2_char_t *file_name = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, module_archive, NULL);
    AXIS2_PARAM_CHECK(env->error, conf, NULL);

    phases_info =  axis2_conf_get_phases_info(conf, env);
    axis2_dep_engine_set_phases_info(dep_engine, env, phases_info);
    dep_engine->curr_file = axis2_arch_file_data_create_with_type_and_file(env,
        AXIS2_MODULE, module_archive);
    module_desc = axis2_module_desc_create(env);
    arch_reader = axis2_arch_reader_create(env);
    file_name =  axutil_file_get_name(module_archive, env);
    status = axis2_arch_reader_read_module_arch(arch_reader, env, file_name,
        dep_engine, module_desc);
    axis2_arch_reader_free(arch_reader, env);
    if (AXIS2_SUCCESS != status)
    {
        axis2_module_desc_free(module_desc, env);
        return NULL;
    }
    status = axis2_dep_engine_load_module_dll(dep_engine, env, module_desc);
    if (AXIS2_SUCCESS != status)
    {
        axis2_module_desc_free(module_desc, env);
        return NULL;
    }

    module = axis2_module_desc_get_module(module_desc, env);
    AXIS2_MODULE_FILL_HANDLER_CREATE_FUNC_MAP(module, env);

    in_flow = axis2_module_desc_get_in_flow(module_desc, env);
    if (in_flow)
    {
        axis2_dep_engine_add_module_flow_handlers(dep_engine, env, in_flow,
            module->handler_create_func_map);
    }

    out_flow = axis2_module_desc_get_out_flow(module_desc, env);
    if (out_flow)
    {
        axis2_dep_engine_add_module_flow_handlers(dep_engine, env, out_flow,
            module->handler_create_func_map);
    }

    in_fault_flow = axis2_module_desc_get_fault_in_flow(module_desc, env);
    if (in_fault_flow)
    {
        axis2_dep_engine_add_module_flow_handlers(dep_engine, env, in_fault_flow,
            module->handler_create_func_map);
    }

    out_fault_flow = axis2_module_desc_get_fault_out_flow(module_desc, env);
    if (out_fault_flow)
    {
        axis2_dep_engine_add_module_flow_handlers(dep_engine, env, out_fault_flow,
            module->handler_create_func_map);
    }

    dep_engine->curr_file = NULL;

    return module_desc;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
axis2_dep_engine_get_repos_path(const axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env)
{
    return dep_engine->folder_name;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_dep_engine_set_current_file_item(axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env,
    axis2_arch_file_data_t *file_data)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (dep_engine->curr_file)
    {
        axis2_arch_file_data_free(dep_engine->curr_file, env);
        dep_engine->curr_file = NULL;
    }
    dep_engine->curr_file = file_data;
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_dep_engine_set_arch_reader(axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env,
    axis2_arch_reader_t *arch_reader)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (dep_engine->arch_reader)
    {
        axis2_arch_reader_free(dep_engine->arch_reader, env);
        dep_engine->arch_reader = NULL;
    }
    dep_engine->arch_reader = arch_reader;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_dep_engine_add_module_builder(
    axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env,
    axis2_module_builder_t *module_builder)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, module_builder, AXIS2_FAILURE);

    return axutil_array_list_add(dep_engine->module_builders, env, module_builder);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_dep_engine_add_svc_builder(
    axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env,
    axis2_svc_builder_t *svc_builder)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, svc_builder, AXIS2_FAILURE);

    return axutil_array_list_add(dep_engine->svc_builders, env, svc_builder);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_dep_engine_add_svc_grp_builder(
    axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env,
    axis2_svc_grp_builder_t *svc_grp_builder)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, svc_grp_builder, AXIS2_FAILURE);

    return axutil_array_list_add(dep_engine->svc_grp_builders, env, svc_grp_builder);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_dep_engine_add_desc_builder(axis2_dep_engine_t *dep_engine,
    const axutil_env_t *env,
    struct axis2_desc_builder *desc_builder)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, desc_builder, AXIS2_FAILURE);

    return axutil_array_list_add(dep_engine->desc_builders, env, desc_builder);
}
