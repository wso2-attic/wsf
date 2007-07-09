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

#ifndef AXIS2_DEP_ENGINE_H
#define AXIS2_DEP_ENGINE_H

/** 
 * @defgroup axis2_dep_engine Deployment Engine
 * @ingroup axis2_deployment
 * @{
 */

/**
 * @file axis2_dep_engine.h
 * @brief Axis2 Deployment Engine interface
 */

#include <axis2_const.h>
#include <axutil_error.h>
#include <axis2_defines.h>
#include <axutil_env.h>
#include <axutil_allocator.h>
#include "axis2_arch_file_data.h"
#include "axis2_ws_info.h"
#include "axis2_conf_builder.h"
#include "axis2_repos_listener.h"

#ifdef __cplusplus
extern "C"
{
#endif
    struct axis2_arch_file_data;
    struct axis2_arch_reader;
    struct axis2_ws_info;
    struct axis2_phases_info;
    struct axis2_svc;

    /** Type name for struct axis2_dep_engine */
    typedef struct axis2_dep_engine axis2_dep_engine_t;
    struct axis2_desc_builder;
    struct axis2_module_builder;
    struct axis2_svc_builder;
    struct axis2_grp_builder;
    struct axis2_svc_grp_builder;
    /** 
     * De-allocate memory
     * @param dep_engine pointer to deployment engine
     * @param env pointer to environment struct
     * @return void
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_dep_engine_free(axis2_dep_engine_t *dep_engine,
        const axutil_env_t *env);


    /**
     * while parsing the axis2.xml the module refferences have to be stored some 
     * where , since at that time none of module availble (they load after parsing 
     * the document)
     * @param dep_engine pointer to deployment engine
     * @param env pointer to environment struct
     * @param module_qname <code>QName</code>
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_dep_engine_add_module(axis2_dep_engine_t *dep_engine,
        const axutil_env_t *env,
        axutil_qname_t *module_qname);

    /** 
     * @param dep_engine pointer to deployment engine
     * @param env pointer to environment struct
     * @param module_name pointer to module name
     */
    AXIS2_EXTERN struct axis2_module_desc *AXIS2_CALL
    axis2_dep_engine_get_module(const axis2_dep_engine_t *dep_engine,
        const axutil_env_t *env,
        axutil_qname_t *module_name);

    /** 
     * @param dep_engine pointer to deployment engine
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN struct axis2_arch_file_data *AXIS2_CALL
    axis2_dep_engine_get_current_file_item(const axis2_dep_engine_t *dep_engine,
        const axutil_env_t *env);

    /** 
     * @param dep_engine pointer to deployment engine
     * @param env pointer to environment struct
     * @param file pointer to file
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_dep_engine_add_ws_to_deploy(axis2_dep_engine_t *dep_engine,
        const axutil_env_t *env,
        struct axis2_arch_file_data *file);

    /** 
     * @param dep_engine pointer to deployment engine
     * @param env pointer to environment struct
     * @param file pointer to file
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_dep_engine_add_ws_to_undeploy(axis2_dep_engine_t *dep_engine,
        const axutil_env_t *env,
        struct axis2_ws_info *file);

    /** 
     * @param dep_engine pointer to deployment engine
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN struct axis2_phases_info *AXIS2_CALL
    axis2_dep_engine_get_phases_info(const axis2_dep_engine_t *dep_engine,
        const axutil_env_t *env);

    /**
     * @param dep_engine pointer to deployment engine
     * @param env pointer to environment struct
     * @return AxisConfiguration <code>AxisConfiguration</code>
     */
    AXIS2_EXTERN struct axis2_conf *AXIS2_CALL
    axis2_dep_engine_get_axis_conf(const axis2_dep_engine_t *dep_engine,
        const axutil_env_t *env);

    /** 
     * @param dep_engine pointer to deployment engine
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN struct axis2_conf *AXIS2_CALL
    axis2_dep_engine_load(axis2_dep_engine_t *dep_engine,
        const axutil_env_t *env);

    /** 
     * @param dep_engine pointer to deployment engine
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN struct axis2_conf *AXIS2_CALL
    axis2_dep_engine_load_client(axis2_dep_engine_t *dep_engine,
        const axutil_env_t *env,
        const axis2_char_t *client_home);

    /** 
     * @param dep_engine pointer to deployment engine
     * @param env pointer to environment struct
     * @param dll_name pointer to dll_name
     */
    AXIS2_EXTERN void *AXIS2_CALL
    axis2_dep_engine_get_handler_dll(const axis2_dep_engine_t *dep_engine,
        const axutil_env_t *env,
        axis2_char_t *dll_name);

    /** 
     * @param dep_engine pointer to deployment engine
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_dep_engine_do_deploy(axis2_dep_engine_t *dep_engine,
        const axutil_env_t *env);

    /** 
     * @param dep_engine pointer to deployment engine
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_dep_engine_undeploy(axis2_dep_engine_t *dep_engine,
        const axutil_env_t *env);

    /** 
     * @param dep_engine pointer to deployment engine
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_dep_engine_is_hot_update(axis2_dep_engine_t *dep_engine,
        const axutil_env_t *env);

    /** 
     * @param dep_engine pointer to deployment engine
     * @param env pointer to environment struct
     * @param phases_info pointer to phases info
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_dep_engine_set_phases_info(axis2_dep_engine_t *dep_engine,
        const axutil_env_t *env,
        struct axis2_phases_info *phases_info);

    /**
     * This method is used to fill a axisservice object using services.xml , first it should create
     * an axisservice object using WSDL and then fill that using given servic.xml and load all the requed
     * class and build the chains , finally add the  servicecontext to EngineContext and axisservice into
     * EngineConfiguration
     * @param dep_engine pointer to deployment engine
     * @param env pointer to environment struct
     * @param svc pointer to service
     * @param file_name pointer to file name
     */
    AXIS2_EXTERN struct axis2_svc *AXIS2_CALL
    axis2_dep_engine_build_svc(axis2_dep_engine_t *dep_engine,
        const axutil_env_t *env,
        struct axis2_svc *svc,
        axis2_char_t *file_name);

    /**
     * This method can be used to build ModuleDescription for a given module archiev file
     * @param dep_engine pointer to deployment engine
     * @param env pointer to environment struct
     * @param module_archive pointer to module archive
     * @param conf pointer to conf
     */
    AXIS2_EXTERN struct axis2_module_desc *AXIS2_CALL
    axis2_dep_engine_build_module(axis2_dep_engine_t *dep_engine,
        const axutil_env_t *env,
        axutil_file_t *module_archive,
        struct axis2_conf *conf);

    /** 
     * @param dep_engine pointer to deployment engine
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    axis2_dep_engine_get_repos_path(const axis2_dep_engine_t *dep_engine,
        const axutil_env_t *env);

    /** 
     * @param dep_engine pointer to deployment engine
     * @param env pointer to environment struct
     * @param file_data pointer to file data
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_dep_engine_set_current_file_item(axis2_dep_engine_t *dep_engine,
        const axutil_env_t *env,
        struct axis2_arch_file_data *file_data);

    /** 
     * @param dep_engine pointer to deployment engine
     * @param env pointer to environment struct
     * @param arch_reader pointer to arch reader
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_dep_engine_set_arch_reader(axis2_dep_engine_t *dep_engine,
        const axutil_env_t *env,
        struct axis2_arch_reader *arch_reader);

    /**
     * No param constructor is need to deploye module and service programatically
     * @param env pointer to environment struct
     * @return pointer to newly created deployment engine
     */
    AXIS2_EXTERN axis2_dep_engine_t *AXIS2_CALL
    axis2_dep_engine_create(const axutil_env_t *env);

    /**
     * Creates description builder struct
     * This the constructor which is used by Engine in order to start
     * Deployment module,
     * @param env pointer to environment struct
     * @param repos_path is the path to which Repositary Listner should listen.
     * @return pointer to newly created deployment engine
     */
    AXIS2_EXTERN axis2_dep_engine_t *AXIS2_CALL
    axis2_dep_engine_create_with_repos_name(const axutil_env_t *env,
        const axis2_char_t *repos_path);

    /**
     * Creates deployment engine struct
     * @param env pointer to environment struct
     * @param repos_path is the path to which Repositary Listner should listen.
     * @param svr_xml_file pointer to service xml file
     * @return pointer to newly created deployment engine
     */
    AXIS2_EXTERN axis2_dep_engine_t *AXIS2_CALL
    axis2_dep_engine_create_with_repos_name_and_svr_xml_file(const axutil_env_t *env,
        const axis2_char_t *repos_path,
        const axis2_char_t *svr_xml_file);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_dep_engine_add_desc_builder(axis2_dep_engine_t *dep_engine,
        const axutil_env_t *env,
        struct axis2_desc_builder *desc_builder);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_dep_engine_add_module_builder(axis2_dep_engine_t *dep_engine,
        const axutil_env_t *env,
        struct axis2_module_builder *module_builder);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_dep_engine_add_svc_builder(axis2_dep_engine_t *dep_engine,
        const axutil_env_t *env,
        struct axis2_svc_builder *svc_builder);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_dep_engine_add_svc_grp_builder(axis2_dep_engine_t *dep_engine,
        const axutil_env_t *env,
        struct axis2_svc_grp_builder *svc_grp_builder);


/** @} */

#ifdef __cplusplus
}
#endif
#endif  /* AXIS2_DEP_ENGINE_H */
