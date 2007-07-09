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

#ifndef AXIS2_SVC_GRP_H
#define AXIS2_SVC_GRP_H

/** 
 * @defgroup axis2_svc_grp service group
 * @ingroup axis2_desc
 * service group represents the static structure of a service group in 
 * the Axis2 configuration. 
 * In Axis2 description hierarchy, a service group lives inside the 
 * configuration. service groups are configured in services.xml files located 
 * in the respective service group folders of the services folder in the repository. 
 * In services.xml file, services groups are declared at top level.
 * A service group can have one or more services associated with it.
 * Sometimes services.xml would not have a service group defined, but only a 
 * service. In such cases a service group with the same name as that of the 
 * service mentioned in services.xml would be created by the deployment 
 * engine and the service would be associated with that newly created service 
 * group. The deployment engine would create service group instances to represent 
 * those configured service groups in services.xml files and would store 
 * them in the configuration.
 * service group encapsulates data on engaged module information and the 
 * service associated with service group.
 * @{
 */

/**
 * @file axis2_svc_grp.h
 */

#include <axutil_param_container.h>
#include <axis2_desc.h>
#include <axis2_svc.h>
#include <axis2_svc_grp_ctx.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /** Type name for struct axis2_svc_grp */
    typedef struct axis2_svc_grp axis2_svc_grp_t;

    struct axis2_svc;
    struct axis2_svc_grp_ctx;

    /**
      * Frees service group.
      * @param svc_grp pointer to service group struct
      * @param env pointer to environment struct
      * @return void
      */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_svc_grp_free(axis2_svc_grp_t *svc_grp,
        const axutil_env_t *env);

    /**
     * Sets service group name.
     * @param svc_grp pointer to service group struct
     * @param env pointer to environment struct
     * @param svc_grp_name service group name string 
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_grp_set_name(axis2_svc_grp_t *svc_grp,
        const axutil_env_t *env,
        const axis2_char_t *svc_grp_name);

    /**
     * Gets service group name.
     * @param svc_grp pointer to service group struct
     * @param env pointer to environment struct
     * @return service group name string 
     */
    AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
    axis2_svc_grp_get_name(const axis2_svc_grp_t *svc_grp,
        const axutil_env_t *env) ;

    /**
     * Adds given service to service group.
     * @param svc_grp pointer to service group struct
     * @param env pointer to environment struct
     * @param service service to be added, service group assumes ownership
     * of service
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_grp_add_svc(axis2_svc_grp_t *svc_grp,
        const axutil_env_t *env,
        struct axis2_svc *svc) ;

    /**
     * Gets named service from service group.
     * @param svc_grp pointer to service group struct
     * @param env pointer to environment struct
     * @param svc_qname pointer to QName of the service
     * @return pointer to service corresponding to given QName, returns a 
     * reference, not a cloned copy
     */
    AXIS2_EXTERN struct axis2_svc *AXIS2_CALL
    axis2_svc_grp_get_svc(const axis2_svc_grp_t *svc_grp,
        const axutil_env_t *env,
        const axutil_qname_t *svc_qname);

    /**
     * Gets all services associated with service group. 
     * @param svc_grp pointer to service group struct
     * @param env pointer to environment struct
     * @return pointer to hash table containing all services, returns a 
     * reference, not a cloned copy
     */
    AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
    axis2_svc_grp_get_all_svcs(const axis2_svc_grp_t *svc_grp,
        const axutil_env_t *env);

    /**
     * Removes named service from service group.
     * @param svc_grp pointer to service group struct
     * @param env pointer to environment struct
     * @param svc_name pointer to service QName
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_grp_remove_svc(axis2_svc_grp_t *svc_grp,
        const axutil_env_t *env,
        const axutil_qname_t *svc_qname);

    /**
     * Adds parameter.
     * @param svc_grp pointer to service group struct
     * @param env pointer to environment struct
     * @param param pointer to parameter, service group assumes ownership 
     * of parameter
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_grp_add_param(axis2_svc_grp_t *svc_grp,
        const axutil_env_t *env,
        axutil_param_t *param);

    /**
     * Gets named parameter.
     * @param svc_grp pointer to service group struct
     * @param env pointer to environment struct
     * @param name parameter name
     * @return pointer to named parameter if exists, else NULL. Returns a 
     * reference, not a cloned copy
     */
    AXIS2_EXTERN axutil_param_t *AXIS2_CALL
    axis2_svc_grp_get_param(const axis2_svc_grp_t *svc_grp,
        const axutil_env_t *env,
        const axis2_char_t *name);

    /**
     * Gets all parameters set on service group.
     * @param svc_grp pointer to service group struct
     * @param env pointer to environment struct
     * @return pointer to array list containing parameter, returns a 
     * reference, not a cloned copy
     */
    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    axis2_svc_grp_get_all_params(const axis2_svc_grp_t *svc_grp,
        const axutil_env_t *env);

    /**
     * Checks if the named parameter is locked.
     * @param svc_grp pointer to service group struct
     * @param env pointer to environment struct
     * @param param_name pointer to param name
     * @return AXIS2_TRUE if the named parameter is locked, else AXIS2_FALSE
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_svc_grp_is_param_locked(axis2_svc_grp_t *svc_grp,
        const axutil_env_t *env,
        const axis2_char_t *param_name);

    /**
     * Adds given module QName to list of module QNames.
     * @param svc_grp pointer to service group struct
     * @param env pointer to environment struct
     * @param module_name pointer to module QName
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_grp_add_module_qname(axis2_svc_grp_t *svc_grp,
        const axutil_env_t *env,
        const axutil_qname_t *module_qname);

    /**
     * Gets parent which is of type configuration.
     * @param svc_grp pointer to service group struct
     * @param env pointer to environment struct
     * @return pointer to parent configuration, returns a 
     * reference, not a cloned copy
     */
    AXIS2_EXTERN struct axis2_conf *AXIS2_CALL
    axis2_svc_grp_get_parent(const axis2_svc_grp_t *svc_grp,
        const axutil_env_t *env);

    /**
     * Sets parent which is of type configuration.
     * @param svc_grp pointer to service group struct
     * @param env pointer to environment struct
     * @param parent parent configuration, service group does not assume
     * the ownership of configuration
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_grp_set_parent(axis2_svc_grp_t *svc_grp,
        const axutil_env_t *env,
        struct axis2_conf *parent);

    /**
     * Engages named module to service group. Engaging a module to service 
     * group would ensure that the same module would be engaged to all 
     * services within the group.
     * @param svc_grp pointer to service group struct
     * @param env pointer to environment struct
     * @param module_name pointer to module QName
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_grp_engage_module(axis2_svc_grp_t *svc_grp,
        const axutil_env_t *env,
        const axutil_qname_t *module_qname);

    /**
     * Gets all module QNames associated with service group.
     * @param svc_grp pointer to service group struct
     * @param env pointer to environment struct
     * @return pointer to array list containing all QNames, returns a 
     * reference, not a cloned copy
     */
    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    axis2_svc_grp_get_all_module_qnames(const axis2_svc_grp_t *svc_grp,
        const axutil_env_t *env);

    /**
     * Adds module reference.
     * @param svc_grp pointer to service group struct
     * @param env pointer to environment struct
     * @param moduleref pointer to module QName
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_grp_add_module_ref(axis2_svc_grp_t *svc_grp,
        const axutil_env_t *env,
        const axutil_qname_t *moduleref);

    /**
     * Gets all module references.
     * @param svc_grp pointer to service group struct
     * @param env pointer to environment struct
     * @return pointer to array list containing module reference, returns 
     * a reference, not a cloned copy
     */
    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    axis2_svc_grp_get_all_module_refs(const axis2_svc_grp_t *svc_grp,
        const axutil_env_t *env);

    /**
     * Gets service group context related to this service group.
     * @param svc_grp pointer to service group struct
     * @param env pointer to environment struct
     * @param parent pointer to configuration context which is the parent of 
     * the context hierarchy
     * @return pointer to service group context related to this service 
     * group, returns a reference, not a cloned copy
     */
    AXIS2_EXTERN struct axis2_svc_grp_ctx *AXIS2_CALL
    axis2_svc_grp_get_svc_grp_ctx(const axis2_svc_grp_t *svc_grp,
        const axutil_env_t *env,
        struct axis2_conf_ctx *parent);

    AXIS2_EXTERN axutil_param_container_t *AXIS2_CALL
    axis2_svc_grp_get_param_container(const axis2_svc_grp_t *svc_grp,
        const axutil_env_t *env);

    /**
     * Creates a service group struct instance.
     * @param env pointer to environment struct
     * @return pointer to newly created service group
     */
    AXIS2_EXTERN axis2_svc_grp_t *AXIS2_CALL
    axis2_svc_grp_create(const axutil_env_t *env);

    /**
     * Creates service group with given configuration as the parent.
     * @param env pointer to environment struct
     * @param conf pointer to configuration, service group created does not 
     * assume ownership of configuration
     * @return pointer to newly created service group
     */
    AXIS2_EXTERN axis2_svc_grp_t *AXIS2_CALL
    axis2_svc_grp_create_with_conf(const axutil_env_t *env,
        struct axis2_conf *conf);

    /** 
     * Gets base description.
     * @param svc_grp pointer to message
     * @param env pointer to environment struct
     * @return pointer to base description struct
     */
    AXIS2_EXTERN axis2_desc_t *AXIS2_CALL
    axis2_svc_grp_get_base(const axis2_svc_grp_t *svc_grp,
        const axutil_env_t *env);

#ifdef __cplusplus
}
#endif
#endif                          /* AXIS2_SVC_GRP_H  */
