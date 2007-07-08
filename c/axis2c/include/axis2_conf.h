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

#ifndef AXIS2_CONFIG_H
#define AXIS2_CONFIG_H

/**
 * @defgroup axis2_engine engine
 * @ingroup axis2
 * @{
 * @}
 */

/** 
 * @defgroup axis2_config configuration
 * @ingroup axis2_engine
 * Axis2 configuration captures all configuration information. Configuration
 * information includes user preferences along with module and 
 * service information that is either statically configured using axis2.xml
 * file, service.xml files and module.xml files or dynamically using the 
 * functions defined in the ops struct related to this conf struct.
 * @{
 */

/**
 * @file axis2_config.h
 */

#include <axutil_param_container.h>
#include <axis2_svc_grp.h>
#include <axis2_transport_in_desc.h>
#include <axis2_transport_out_desc.h>
#include <axutil_qname.h>
#include <axutil_hash.h>
#include <axis2_phases_info.h>
#include <axis2_msg_recv.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /** Type name for struct axis2_conf */
    typedef struct axis2_conf axis2_conf_t;

    struct axis2_msg_recv;
    struct axis2_phases_info;
    struct axis2_svc_grp;
    struct axis2_svc;
    struct axis2_op;
    struct axis2_dep_engine;
    struct axis2_desp;

    /**
     * Frees conf struct.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_conf_free(axis2_conf_t *conf,
        const axutil_env_t *env);

    /**
     * Adds a service group to the configuration.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @param svc_grp pointer to service group, conf takes over the 
     * ownership of the service group
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_conf_add_svc_grp(axis2_conf_t *conf,
        const axutil_env_t *env,
        struct axis2_svc_grp *svc_grp);

    /** 
     * Gets a named service group.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @param svc_grp_name name of the service group to be accessed
     * @return pointer to service group with the given name if exists, 
     * else NULL. Returns a reference, not a cloned copy
     */
    AXIS2_EXTERN struct axis2_svc_grp *AXIS2_CALL
    axis2_conf_get_svc_grp(const axis2_conf_t *conf,
        const axutil_env_t *env,
        const axis2_char_t *svc_grp_name);

    /** 
     * Gets all service group added to conf.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @return pointer to hash table containing the service groups, returns 
     * a reference, not a cloned copy
     */
    AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
    axis2_conf_get_all_svc_grps(const axis2_conf_t *conf,
        const axutil_env_t *env);

    /**
     * Adds a service to configuration.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @param svc pointer to service, conf takes over the ownership of the 
     * service
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_conf_add_svc(axis2_conf_t *conf,
        const axutil_env_t *env,
        struct axis2_svc* svc);

    /**
     * Gets a service with given name.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @param svc_name service name string
     * @return pointer to service with the given name if exists, else NULL.
     * Returns a reference, not a cloned copy
     */
    AXIS2_EXTERN struct axis2_svc *AXIS2_CALL
    axis2_conf_get_svc(const axis2_conf_t *conf,
        const axutil_env_t *env,
        const axis2_char_t* svc_name);

    /**
     * Removes the named service from configuration.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @param name name of service to be removed
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_conf_remove_svc(axis2_conf_t *conf,
        const axutil_env_t *env,
        const axis2_char_t *name);

    /**
     * Adds a parameter to configuration.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @param param pointer to parameter struct to be added
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_conf_add_param(axis2_conf_t *conf,
        const axutil_env_t *env,
        axutil_param_t *param);

    /**
     * Gets a parameter with the given name.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @param name name of the parameter to be accessed
     * @return pointer to parameter with the given name if exists, else NULL.
     * Returns a reference, not a cloned copy
     */
    AXIS2_EXTERN axutil_param_t *AXIS2_CALL
    axis2_conf_get_param(const axis2_conf_t *conf,
        const axutil_env_t *env,
        const axis2_char_t *name);

    /**
     * Gets all the parameters added to the configuration.
     * @param conf pointer to conf struct
     * @param env pointer to environment
     * @return pointer to array list containing parameters if exists, 
     * else NULL. Returns a reference, not a cloned copy
     */
    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    axis2_conf_get_all_params(const axis2_conf_t *conf,
        const axutil_env_t *env);

    /**
     * Checks if the named parameter is locked.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @param param_name name of the parameter
     * @return AXIS2_TRUE if parameter is locked, else AXIS2_FALSE
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_conf_is_param_locked(const axis2_conf_t *conf,
        const axutil_env_t *env,
        const axis2_char_t *param_name);

    /**
     * Gets in transport corresponding to the given transport QName.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @param qname QName of transport 
     * @return pointer to transport in description if exists, 
     * else NULL. Returns a reference, not a cloned copy
     */
    AXIS2_EXTERN axis2_transport_in_desc_t *AXIS2_CALL
    axis2_conf_get_transport_in(const axis2_conf_t *conf,
        const axutil_env_t *env,
        const AXIS2_TRANSPORT_ENUMS trans_enum);

    /**
     * Adds a transport in description.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @param transport  pointer to transport in description. conf assumes
     * ownership of the struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_conf_add_transport_in(axis2_conf_t *conf,
        const axutil_env_t *env,
        axis2_transport_in_desc_t *transport,
        const AXIS2_TRANSPORT_ENUMS trans_enum);

    /**
     * Gets out transport corresponding to the given transport QName.
     * @param conf pointer to conf struct
     * @param env pointer to environment strcut
     * @param qname pointer to transport qname
     * @return pointer to transport out description if exists, 
     * else NULL. Returns a reference, not a cloned copy
     */
    AXIS2_EXTERN axis2_transport_out_desc_t *AXIS2_CALL
    axis2_conf_get_transport_out(const axis2_conf_t *conf,
        const axutil_env_t *env,
        const AXIS2_TRANSPORT_ENUMS trans_enum);

   /**
    * Adds a transport out description.
    * @param conf pointer to conf struct
    * @param env pointer to environment struct
    * @param transport pointer to transport out description. conf assumes
    * ownership of the struct
    * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
    */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_conf_add_transport_out(axis2_conf_t *conf,
        const axutil_env_t *env,
        axis2_transport_out_desc_t *transport,
        const AXIS2_TRANSPORT_ENUMS trans_enum);

    /**
     * Gets all in transports.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @return hash table containing all transport in descriptions. 
     * Returns a reference, not a cloned copy
     */
    AXIS2_EXTERN axis2_transport_in_desc_t **AXIS2_CALL
    axis2_conf_get_all_in_transports(const axis2_conf_t *conf,
        const axutil_env_t *env);

    /**
     * Gets all out transports.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @return hash table containing all transport out descriptions. 
     * Returns a reference, not a cloned copy
     */
    AXIS2_EXTERN axis2_transport_out_desc_t **AXIS2_CALL
    axis2_conf_get_all_out_transports(const axis2_conf_t *conf,
        const axutil_env_t *env);

   /**
    * Gets a module with given QName.
    * @param conf pointer to conf struct
    * @param env pointer to environment struct
    * @param qname pointer to qname
    * @return module description corresponding to the given qname
    */
    AXIS2_EXTERN struct axis2_module_desc *AXIS2_CALL
    axis2_conf_get_module(const axis2_conf_t *conf,
        const axutil_env_t *env,
        const axutil_qname_t *qname);

   /**
    * Gets the list of engaged modules.
    * @param conf pointer to conf struct
    * @param env pointer to environment struct
    * @return a pointer to the array list of engaged modules. Returns a 
    * reference, not a cloned copy
    */
    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    axis2_conf_get_all_engaged_modules(const axis2_conf_t *conf,
        const axutil_env_t *env);

    /**
     * Gets the in phases up to and including port dispatch phase.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @return a pointer to the array list of in phases up to post dispatch
     * inclusive. Returns a reference, not a cloned copy
     */
    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    axis2_conf_get_in_phases_upto_and_including_post_dispatch(const axis2_conf_t *conf,
        const axutil_env_t *env);

    /**
     * Gets the out flow. Out flow is a list of phases invoked in the out 
     * path of execution of the engine.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @return a pointer to the array list of out flow phases. Returns a 
     * reference, not a cloned copy
     */
    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    axis2_conf_get_out_flow(const axis2_conf_t *conf,
        const axutil_env_t *env);


   /**
    * Gets the in fault flow. In fault flow is a list of phases invoked in 
    * the in path of execution, if some fault happens.
    * @param conf pointer to conf struct
    * @param env pointer to environment struct
    * @return a pointer to the array list of in fault flow phases. Returns a 
    * reference, not a cloned copy
    */
    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    axis2_conf_get_in_fault_flow(const axis2_conf_t *conf,
        const axutil_env_t *env);

   /**
    * Gets the out fault flow. Out fault flow is a list of phases invoked in 
    * the out path of execution, if some fault happens.
    * @param conf pointer to conf struct
    * @param env pointer to environment struct
    * @return a pointer to the array list of out fault flow phases. Returns a 
    * reference, not a cloned copy
    */
    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    axis2_conf_get_out_fault_flow(const axis2_conf_t *conf,
        const axutil_env_t *env);

    /**
     * Gets faulty services. A faulty service is a service that does not 
     * meet the service configuration criteria or a service with errors in 
     * the service dynamic link library.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @return a pointer to the hash table of faulty services. Returns a 
     * reference, not a cloned copy
     */
    AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
    axis2_conf_get_all_faulty_svcs(const axis2_conf_t *conf,
        const axutil_env_t *env);

    /**
     * Gets faulty modules. A faulty module is a module that does not 
     * meet the module configuration criteria or a module with errors in 
     * the service dynamic link library.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @return a pointer to the hash table of faulty modules. Returns a 
     * reference, not a cloned copy
     */
    AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
    axis2_conf_get_all_faulty_modules(const axis2_conf_t *conf,
        const axutil_env_t *env);

    /**        
     * Gets all the list of services loaded into configuration.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @return a pointer to the hash table of services. Returns a 
     * reference, not a cloned copy
     */
    AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
    axis2_conf_get_all_svcs(const axis2_conf_t *conf,
        const axutil_env_t *env);

    /**        
     * Gets all the list of services that need to be loaded into configuration
     * at the start up of the axis2 engine.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @return a pointer to the hash table of services. Returns a 
     * reference, not a cloned copy
     */
    AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
    axis2_conf_get_all_svcs_to_load(
        const axis2_conf_t *conf,
        const axutil_env_t *env);

    /**
     * Checks is the named module is engaged.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @param module_name pointer to QName representing the module name
     * @return AXIS2_TRUE if named module is engaged, else AXIS2_FALSE
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_conf_is_engaged(axis2_conf_t *conf,
        const axutil_env_t *env,
        const axutil_qname_t *module_name);

    /**
     * Gets phases information struct.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @return a pointer to the struct containing phases information. 
     * Returns a reference, not a cloned copy
     */
    AXIS2_EXTERN struct axis2_phases_info *AXIS2_CALL
    axis2_conf_get_phases_info(const axis2_conf_t *conf,
        const axutil_env_t *env);

    /**
     * Sets phases information struct.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @param phases_info pointer to phases_info struct. conf assumes 
     * ownership of the struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_conf_set_phases_info(axis2_conf_t *conf,
        const axutil_env_t *env,
        struct axis2_phases_info *phases_info);

    /**
     * Adds message receiver with the given key.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @param key key string with which the message receive is to be added
     * @param msg_recv pointer to message receiver 
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_conf_add_msg_recv(axis2_conf_t *conf,
        const axutil_env_t *env,
        const axis2_char_t *key,
        struct axis2_msg_recv *msg_recv);

    /**
     * Gets message receiver with the given key.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @param key key string corresponding to the message receiver to 
     * be retrieved
     * @return pointer to the message receiver with the given key if it 
     * exists, else null. Returns a reference, not a cloned copy
     */
    AXIS2_EXTERN struct axis2_msg_recv *AXIS2_CALL
    axis2_conf_get_msg_recv(const axis2_conf_t *conf,
        const axutil_env_t *env,
        axis2_char_t *key);

    /**
     * Sets the list of out phases.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @param out_phases pointer to array list of the phases. conf assumes 
     * ownership of the struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_conf_set_out_phases(axis2_conf_t *conf,
        const axutil_env_t *env,
        axutil_array_list_t *out_phases);

    /**
     * Gets the list of out phases.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @return pointer to array list of out phases. Returns a reference, 
     * not a cloned copy
     */
    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    axis2_conf_get_out_phases(const axis2_conf_t *conf,
        const axutil_env_t *env);

    /**
     * Sets fault phases for in path.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @param list pointer to array list of phases
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_conf_set_in_fault_phases(axis2_conf_t *conf,
        const axutil_env_t *env,
        axutil_array_list_t *list);

    /**
     * Sets fault phases for out path.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @param list pointer to array list of phases
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_conf_set_out_fault_phases(axis2_conf_t *conf,
        const axutil_env_t *env,
        axutil_array_list_t *list);

    /**
     * Gets all modules configured,
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @return a pointer to hash table containing the list of modules. 
     * Returns a reference, not a cloned copy
     */
    AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
    axis2_conf_get_all_modules(const axis2_conf_t *conf,
        const axutil_env_t *env);

    /**
     * Adds a module.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @param module pointer to module struct to be added
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_conf_add_module(axis2_conf_t *conf,
        const axutil_env_t *env,
        struct axis2_module_desc *module);

    /**
     * Sets the default dispatchers.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_conf_set_default_dispatchers(axis2_conf_t *conf,
        const axutil_env_t *env);

    /**
     * Sets a custom dispatching phase.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @param dispatch pointer to phase to be dispatched
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_conf_set_dispatch_phase(axis2_conf_t *conf,
        const axutil_env_t *env,
        axis2_phase_t *dispatch);

    /**
     * Gets the repository location.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @return returns repository location as a string
     */
    AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
    axis2_conf_get_repo(const axis2_conf_t *conf,
        const axutil_env_t *env);

    /**
     * Sets the repository location.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @param axis2_repo repository location as a string
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_conf_set_repo(axis2_conf_t *conf,
        const axutil_env_t *env,
        axis2_char_t *axis2_repo);

    /**
     * Engages the named module.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @param module_ref pointer to the QName of the module to be engaged
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_conf_engage_module(axis2_conf_t *conf,
        const axutil_env_t *env,
        const axutil_qname_t *module_ref);

    /**
     * Sets the deployment engine.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @param dep_engine pointer to dep_engine struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_conf_set_dep_engine(axis2_conf_t *conf,
        const axutil_env_t *env,
        struct axis2_dep_engine *dep_engine);

    /**
     * Gets the default module version for the named module.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @param module_name module name string
     * @return default module version as a string
     */
    AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
    axis2_conf_get_default_module_version(const axis2_conf_t *conf,
        const axutil_env_t *env,
        const axis2_char_t *module_name);

    /**
     * Gets the default module reference for the named module.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @param module_name module name string
     * @return pointer to the module description struct corresponding to
     * the given name
     */
    AXIS2_EXTERN struct axis2_module_desc *AXIS2_CALL
    axis2_conf_get_default_module(const axis2_conf_t *conf, 
        const axutil_env_t *env,
        const axis2_char_t *module_name);

    /**
     * Adds a default module version for the named module.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @param module_name name of the module
     * @param module_version default version for the module
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_conf_add_default_module_version(axis2_conf_t *conf, 
        const axutil_env_t *env,
        const axis2_char_t *module_name,
        const axis2_char_t *module_version);

    /**
     * Engages the module with the given version.
     * @param conf pointer to conf struct
     * @param env pointer to environment struct
     * @param module_name name of the module to be engaged
     * @param version_id version of the module to be engaged
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_conf_engage_module_with_version(axis2_conf_t *conf, 
        const axutil_env_t *env,
        const axis2_char_t *module_name,
        const axis2_char_t *version_id);

    /** 
     * Creates configuration struct.
     * @param env pointer to environment struct
     * @return pointer to newly created configuration
     */
    AXIS2_EXTERN axis2_conf_t *AXIS2_CALL
    axis2_conf_create(const axutil_env_t *env);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_conf_get_enable_mtom(axis2_conf_t *conf,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_conf_set_enable_mtom(axis2_conf_t *conf,
        const axutil_env_t *env,
        axis2_bool_t enable_mtom);

/*The following two methods are used in Rampart to 
 *check whether security is engaed. */

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_conf_get_enable_security(axis2_conf_t *conf,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_conf_set_enable_security(axis2_conf_t *conf,
        const axutil_env_t *env,
        axis2_bool_t enable_security);

    AXIS2_EXTERN void* AXIS2_CALL
    axis2_conf_get_security_context(
        axis2_conf_t *conf,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_conf_set_security_context(
        axis2_conf_t *conf,
        const axutil_env_t *env,
        void* security_context);


    AXIS2_EXTERN axutil_param_container_t *AXIS2_CALL
    axis2_conf_get_param_container(const axis2_conf_t *conf,
        const axutil_env_t *env);

    /** 
     * Gets base description.
     * @param conf pointer to message
     * @param env pointer to environment struct
     * @return pointer to base description struct
     */
    AXIS2_EXTERN axis2_desc_t *AXIS2_CALL
    axis2_conf_get_base(const axis2_conf_t *conf,
        const axutil_env_t *env);
#ifdef __cplusplus
}
#endif
#endif /* AXIS2_CONFIG_H */
