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

#ifndef AXIS2_SVC_H
#define AXIS2_SVC_H

/** @defgroup axis2_svc service
 * @ingroup axis2_desc
 * service represents the static structure of a service in a service group. 
 * In Axis2 description hierarchy, a service lives inside the service group to 
 * which it belongs. 
 * services are configured in services.xml files located in the respective 
 * service group folders of the services folder in the repository. 
 * In services.xml file, services are declared in association with a given 
 * service group or at top level as a stand alone service. In cases where a 
 * service is configured without an associated service group, a service group 
 * with the same name as that of the service would be created by the deployment 
 * engine and the service would be associated with that newly created service 
 * group. The deployment engine would create service instances to represent 
 * those configured services in services.xml files and would associate them with
 * the respective service group in the configuration.
 * service encapsulates data on engaged module information, the XML schema 
 * defined in WSDL that is associated with the service and the operations of 
 * the service.
 * @{
 */

/**
 * @file axis2_svc.h
 */

#include <axutil_param_container.h>
#include <axis2_flow_container.h>
#include <axis2_op.h>
#include <axis2_svc_grp.h>
#include <axutil_qname.h>
#include <axutil_error.h>
#include <axutil_array_list.h>
#include <axis2_const.h>
#include <axis2_phase_resolver.h>
#include <axis2_module_desc.h>
#include <axis2_conf.h>
#include <axutil_string.h>
#include <axutil_stream.h>

#ifdef __cplusplus
extern "C"
{
#endif


    /** Type name for struct axis2_svc */
    typedef struct axis2_svc axis2_svc_t;

    struct axis2_svc_grp;
    struct axis2_flow_container;
    struct axutil_param_container;
    struct axis2_module_desc;
    struct axis2_conf;

    /**
     * Frees service.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @return void
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_svc_free(axis2_svc_t *svc,
        const axutil_env_t *env);

    /**
     * Adds operation.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @param op pointer to operation struct, service assumes ownership of 
     * operation
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_add_op(axis2_svc_t *svc,
        const axutil_env_t *env,
        struct axis2_op *op);

    /**
     * Gets operation corresponding to the given QName.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @param op_qname pointer to QName representing operation QName
     * @return pointer to operation corresponding to given QName
     */
    AXIS2_EXTERN struct axis2_op *AXIS2_CALL
    axis2_svc_get_op_with_qname(const axis2_svc_t *svc,
        const axutil_env_t *env,
        const axutil_qname_t *op_qname);

    /**
     * Gets operation corresponding to the name.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @param op_name operation name string
     * @return pointer to operation corresponding to given name
     */
    AXIS2_EXTERN struct axis2_op *AXIS2_CALL
    axis2_svc_get_op_with_name(const axis2_svc_t *svc,
        const axutil_env_t *env,
        const axis2_char_t *op_name);

    /**
     * Gets all operations of service.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @return pointer to hash map containing all operations of the service
     */
    AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
    axis2_svc_get_all_ops(const axis2_svc_t *svc,
        const axutil_env_t *env);

    /**
     * Sets parent which is of type service group.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @param svc_grp pointer to parent service group
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_set_parent(axis2_svc_t *svc,
        const axutil_env_t *env,
        struct axis2_svc_grp *svc_grp);

    /**
     * Gets parent which is of type service group.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @return pointer to parent service group
     */
    AXIS2_EXTERN struct axis2_svc_grp *AXIS2_CALL
    axis2_svc_get_parent(const axis2_svc_t *svc,
        const axutil_env_t *env);

    /**
     * Sets QName.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @param qname pointer to QName
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_set_qname(axis2_svc_t *svc,
        const axutil_env_t *env,
        const axutil_qname_t *qname);

    /**
     * Gets QName.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @return pointer to QName
     */
    AXIS2_EXTERN const axutil_qname_t *AXIS2_CALL
    axis2_svc_get_qname(const axis2_svc_t *svc,
        const axutil_env_t *env);

    /**
     * Adds given parameter to operation.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @param param pointer to parameter, service assumes ownership of
     * parameter
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_add_param(axis2_svc_t *svc,
        const axutil_env_t *env,
        axutil_param_t *param);

    /**
     * Gets named parameter.         
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @param name name string
     * @return pointer to named parameter if exists, else NULL. Returns a 
     * reference, not a cloned copy         
     */
    AXIS2_EXTERN axutil_param_t *AXIS2_CALL
    axis2_svc_get_param(const axis2_svc_t *svc,
        const axutil_env_t *env,
        const axis2_char_t *name);

    /**
     * Gets all parameters stored within service.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @return pointer to array list of parameters, returns a reference,
     * not a cloned copy
     */
    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    axis2_svc_get_all_params(const axis2_svc_t *svc,
        const axutil_env_t *env);

    /**
     * Checks if the named parameter is locked.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @param param_name parameter name
     * @return AXIS2_TRUE if the named parameter is locked, else AXIS2_FALSE
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_svc_is_param_locked(axis2_svc_t *svc,
        const axutil_env_t *env,
        const axis2_char_t *param_name);

    /**
     * Engages given module to service.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @param  module_desc pointer to module description to be engaged, 
     * service does not assume the ownership of module 
     * @param conf pointer to configuration, it is configuration that holds 
     * module information
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_engage_module(axis2_svc_t *svc,
        const axutil_env_t *env,
        struct axis2_module_desc *module_desc,
        struct axis2_conf *conf);

    /**
     * Disengages given module from service.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @param  module_desc pointer to module description to be engaged, 
     * service does not assume the ownership of module 
     * @param conf pointer to configuration, it is configuration that holds 
     * module information
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_disengage_module(axis2_svc_t *svc,
        const axutil_env_t *env,
        struct axis2_module_desc *module_desc,
        struct axis2_conf *conf);

        
    /**
     * Check whether a given module is engaged to the service.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @param  module_qname pointer to module qname to be engaged, 
     * @return AXIS2_TRUE if module is engaged, else AXIS2_FALSE 
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL 
    axis2_svc_is_module_engaged (axis2_svc_t *svc,
        const axutil_env_t *env,
        axutil_qname_t *module_qname);

    /**
     * Adds operations defined in a module to this service. It is possible 
     * to define operations that are associated to a module in a module.xml 
     * file. These operations in turn could be invoked in relation to a 
     * service. This method allows those module related operation to be 
     * added to a service. 
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @param module_desc pointer to module description containing module
     * related operation information. service does not assume the ownership
     * of module description
     * @param conf pointer to configuration, it is configuration that stores 
     * the modules
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL 
    axis2_svc_add_module_ops(axis2_svc_t *svc,
        const axutil_env_t *env,
        struct axis2_module_desc *module_desc,
        struct axis2_conf *axis2_config);

    /**
     * Adds given module description to engaged module list.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @param module_desc pointer to module description, service does not 
     * assume the ownership of module description
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    /*AXIS2_EXTERN axis2_status_t AXIS2_CALL
      axis2_svc_add_to_engaged_module_list(axis2_svc_t *svc,
          const axutil_env_t *env,
          struct axis2_module_desc *module_desc);*/

    /**
     * Gets all engaged modules.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @return pointer to array list containing all engaged modules
     */
    /*AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
      axis2_svc_get_all_engaged_modules(const axis2_svc_t *svc,
          const axutil_env_t *env);*/

    /**
     * Sets style. Style can be either RPC or document literal.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @param style style of service as defined in WSDL
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_set_style(axis2_svc_t *svc,
        const axutil_env_t *env,
        const axis2_char_t *style);

    /**
     * Gets style. Style can be either RPC or document literal.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @return string representing the style of service
     */
    AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
    axis2_svc_get_style(const axis2_svc_t *svc,
        const axutil_env_t *env);

    /**
     * Gets in flow. In flow is the list of phases invoked
     * along in path.         
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @return pointer to flow representing in flow
     */
    /*AXIS2_EXTERN struct axis2_flow *AXIS2_CALL
      axis2_svc_get_in_flow(const axis2_svc_t *svc,
          const axutil_env_t *env);*/

    /**
     * Sets in flow. In flow is the list of phases invoked
     * along in path.         
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @param in_flow pointer to flow representing in flow
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    /*AXIS2_EXTERN axis2_status_t AXIS2_CALL
      axis2_svc_set_in_flow(axis2_svc_t *svc,
          const axutil_env_t *env,
          struct axis2_flow *in_flow);*/

    /**
     * Gets out flow. Out flow is the list of phases invoked
     * along out path.         
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @return pointer to flow representing out flow
     */
    /*AXIS2_EXTERN struct axis2_flow *AXIS2_CALL
            axis2_svc_get_out_flow(
                const axis2_svc_t *svc,
                const axutil_env_t *env);*/

    /**
     * Sets out flow. Out flow is the list of phases invoked
     * along out path.         
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @return out_flow pointer to flow representing out flow
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    /*AXIS2_EXTERN axis2_status_t AXIS2_CALL
            axis2_svc_set_out_flow(
                axis2_svc_t *svc,
                const axutil_env_t *env,
                struct axis2_flow *out_flow);*/

    /**
     * Gets fault in flow. Fault in flow is the list of phases invoked
     * along in path if a fault happens.         
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @return pointer to flow representing fault in flow
     */
    /*AXIS2_EXTERN struct axis2_flow *AXIS2_CALL
            axis2_svc_get_fault_in_flow(
                const axis2_svc_t *svc,
                const axutil_env_t *env);*/

    /**
     * Sets fault in flow. Fault in flow is the list of phases invoked
     * along in path if a fault happens.         
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @param fault_flow pointer to flow representing fault in flow
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    /*AXIS2_EXTERN axis2_status_t AXIS2_CALL
            axis2_svc_set_fault_in_flow(
                axis2_svc_t *svc,
                const axutil_env_t *env,
                struct axis2_flow *fault_flow);*/

    /**
     * Gets fault out flow. Fault out flow is the list of phases invoked
     * along out path if a fault happens.         
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @return pointer to flow representing fault out flow
     */
    /*AXIS2_EXTERN struct axis2_flow *AXIS2_CALL
            axis2_svc_get_fault_out_flow(
                const axis2_svc_t *svc,
                const axutil_env_t *env);*/

    /**
     * Sets fault out flow. Fault out flow is the list of phases invoked
     * along out path if a fault happens.         
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @param fault_flow pointer to flow representing fault out flow
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    /*AXIS2_EXTERN axis2_status_t AXIS2_CALL
            axis2_svc_set_fault_out_flow(
                axis2_svc_t *svc,
                const axutil_env_t *env,
                struct axis2_flow *fault_flow);*/

    /**
     * Gets operation corresponding to given SOAP Action.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @param soap_action SOAP action string
     * @return pointer to operation corresponding to given SOAP action if 
     * one exists, else NULL. Returns a reference, not a cloned copy
     */
    AXIS2_EXTERN struct axis2_op *AXIS2_CALL
    axis2_svc_get_op_by_soap_action(const axis2_svc_t *svc,
        const axutil_env_t *env,
        const axis2_char_t *soap_action);

    /**
     * Gets operation corresponding to given SOAP Action and endpoint QName.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @param soap_action SOAP action string
     * @param endpoint pointer QName representing endpoint URI
     * @return pointer operation corresponding to given SOAP Action and 
     * endpoint QName.
     */
    /*AXIS2_EXTERN struct axis2_op *AXIS2_CALL
            axis2_svc_get_op_by_soap_action_and_endpoint(
                const axis2_svc_t *svc,
                const axutil_env_t *env,
                const axis2_char_t *soap_action,
                const axutil_qname_t *endpoint);*/

    /**
     * Gets service name.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @return service name string
     */
    AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
    axis2_svc_get_name(const axis2_svc_t *svc,
        const axutil_env_t *env);

    /**
     * Sets service name.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @param svc_name service name string
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_set_name(axis2_svc_t *svc,
        const axutil_env_t *env,
        const axis2_char_t *svc_name);

    /**
     * Sets current time as last update time of the service.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_set_last_update(axis2_svc_t *svc,
        const axutil_env_t *env);

    /**
     * Gets last update time of the service.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @return last updated time in seconds
     */
    AXIS2_EXTERN long AXIS2_CALL
    axis2_svc_get_last_update(const axis2_svc_t *svc,
          const axutil_env_t *env);

    /**
     * Get the description of the services, which is in the
     * service.xml, <description> tag
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @return services description string
     */
    AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
    axis2_svc_get_svc_desc(const axis2_svc_t *svc,
          const axutil_env_t *env);

    /**
     * Set the description of the service which is in service.xml
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_set_svc_desc(axis2_svc_t *svc,
         const axutil_env_t *env,
         const axis2_char_t *svc_desc);


    /**
     * Get the static wsdl file of the services, which is in the
     * service.xml, <wsdl> tag
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @return services description string
     */
    AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
    axis2_svc_get_svc_wsdl_path(const axis2_svc_t *svc,
          const axutil_env_t *env);

    /**
     * Set the wsdl path of the service which is in service.xml
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_set_svc_wsdl_path(axis2_svc_t *svc,
         const axutil_env_t *env,
         const axis2_char_t *wsdl_path);


    /**
     * Gets the name of the file that holds the implementation of the 
     * service. service implementation is compiled into shared libraries 
     * and is placed in the respective sub folder in the services folder 
     * of Axis2 repository.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @return file name string
     */
    AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
    axis2_svc_get_file_name(const axis2_svc_t *svc,
        const axutil_env_t *env);

    /**
     * Sets the name of the file that holds the implementation of the 
     * service. service implementation is compiled into shared libraries 
     * and is placed in the respective sub folder in the services folder 
     * of Axis2 repository.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @param file_name file name string
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_set_file_name(axis2_svc_t *svc,
        const axutil_env_t *env,
        const axis2_char_t *file_name);

    /**
     * Gets all endpoints associated with the service.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @return pointer to hash map containing all endpoints
     */
    /*AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
            axis2_svc_get_all_endpoints(
                const axis2_svc_t *svc,
                const axutil_env_t *env);*/

    /**
     * Sets the list of endpoints associated with the service. 
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @param endpoints pointer to hash map containing all endpoints
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    /*AXIS2_EXTERN axis2_status_t AXIS2_CALL
            axis2_svc_set_all_endpoints(
                axis2_svc_t *svc,
                const axutil_env_t *env,
                axutil_hash_t *endpoints);*/

    /**
     * Gets namespace. 
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @return namespace URI string
     */
    /*AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
            axis2_svc_get_namespace(
                const axis2_svc_t *svc,
                const axutil_env_t *env);
    */

    /**
     * Adds WS-Addressing mapping for a given operation. The services.xml
     * configuration file could specify a SOAP action that would map to 
     * one of the service operations. This method could be used to register 
     * that mapping against operations. WS-Addressing based dispatcher 
     * makes use of this mapping to identify the operation to be invoked,
     * given WSA action.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @param wsa_action WSA action string
     * @param op pointer to operation that maps to the given WSA action
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_add_mapping(axis2_svc_t *svc,
        const axutil_env_t *env,
        const axis2_char_t *wsa_action ,
        struct axis2_op *axis2_op);

    /**
     * Adds a module qname to list of module QNames associated with service.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @param module_qname pointer to QName to be added, this method clones
     * the QName
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_add_module_qname(axis2_svc_t *svc,
        const axutil_env_t *env,
        const axutil_qname_t *module_qname);

    /**
     * Gets all module QNames associated with the service as a list.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @return pointer to array list containing QNames
     */
    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    axis2_svc_get_all_module_qnames(const axis2_svc_t *svc,
        const axutil_env_t *env);

    /**
     * Checks if the XML schema location is adjusted.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @return AXIS2_TRUE if XML schema is adjusted, else AXIS2_FALSE
     */
    /*AXIS2_EXTERN axis2_bool_t AXIS2_CALL
            axis2_svc_is_schema_location_adjusted(
                axis2_svc_t *svc,
                const axutil_env_t *env);
    */

    /**
     * Sets the bool value indicating if the XML schema location is adjusted.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @param adjusted AXIS2_TRUE if XML schema is adjusted, else AXIS2_FALSE
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
     /*
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
            axis2_svc_set_schema_location_adjusted(
                axis2_svc_t *svc,
                const axutil_env_t *env,
                const axis2_bool_t adjusted);*/

    /**
     * Gets XML schema mapping table for service. 
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @return pointer to hash map with XML schema mappings, returns a 
     * reference, not a cloned copy
     */
     /*
    AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
            axis2_svc_axis2_svc_get_schema_mapping_table(
                const axis2_svc_t *svc,
                const axutil_env_t *env);*/

    /**
     * Sets XML schema mapping table for service. 
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @param table pointer to hash map with XML schema mappings, service 
     * assumes ownership of the map
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     *//*
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
            axis2_svc_set_schema_mapping_table(
                axis2_svc_t *svc,
                const axutil_env_t *env,
                axutil_hash_t *table);*/

    /**
     * Gets custom schema prefix.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @return custom schema prefix string
     *//*
    AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
            axis2_svc_get_custom_schema_prefix(
                const axis2_svc_t *svc,
                const axutil_env_t *env);*/

    /**
     * Sets custom schema prefix.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @param prefix custom schema prefix string
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     *//*
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
            axis2_svc_set_custom_schema_prefix(
                axis2_svc_t *svc,
                const axutil_env_t *env,
                const axis2_char_t *prefix);*/

    /**
     * Gets custom schema suffix.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @return custom schema suffix string
     */
     /*
    AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
            axis2_svc_get_custom_schema_suffix(
                const axis2_svc_t *svc,
                const axutil_env_t *env);*/

    /**
     * Sets custom schema suffix.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @param suffix custom schema suffix string
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
     /*
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
            axis2_svc_set_custom_schema_suffix(
                axis2_svc_t *svc,
                const axutil_env_t *env,
                const axis2_char_t *suffix);*/

    /**
     * Prints the schema to given stream.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @param out_stream stream to print to
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     *//*
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
            axis2_svc_print_schema(
                axis2_svc_t *svc,
                const axutil_env_t *env,
                axutil_stream_t *out_stream);*/

    /**
     * Gets the XML schema at the given index of XML schema array list.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @param index index of the XML schema to be retrieved
     * @return pointer to XML schema, returns a reference, not a cloned copy
     */
    /*AXIS2_EXTERN xml_schema_t *AXIS2_CALL
            axis2_svc_get_schema(
                const axis2_svc_t *svc,
                const axutil_env_t *env,
                const int index);*/

    /**
     * Adds all namespaces in the namespace map to the XML schema at 
     * the given index of the XML schema array list.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @param index index of the XML schema to be processed
     * @return pointer to XML schema with namespaces added, 
     * returns a reference, not a cloned copy         
     */
/*        AXIS2_EXTERN xml_schema_t *AXIS2_CALL
            axis2_svc_add_all_namespaces(
                axis2_svc_t *svc,
                const axutil_env_t *env,
                int index);*/

    /**
     * Gets the list of XML schemas associated with service. 
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @return pointer to array list of XML schemas, returns a reference,
     * not a cloned copy
     */
     /*
    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
            axis2_svc_get_all_schemas(
                const axis2_svc_t *svc,
                const axutil_env_t *env);*/

    /**
     * Adds the given XML schema to the list of XML schemas associated 
     * with the service.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @param schema pointer to XML schema struct, service assumes the 
     * ownership of struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
     /*
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
            axis2_svc_add_schema(
                axis2_svc_t *svc,
                const axutil_env_t *env,
                xml_schema_t *schema);*/

    /**
     * Adds the list of all XML schemas to service.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @param schemas pointer to array list containing XML schemas
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     *//*
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
            axis2_svc_add_all_schemas(
                axis2_svc_t *svc,
                const axutil_env_t *env,
                axutil_array_list_t *schemas);*/

    /**
     * Gets XML schema's target namespace.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @return XML schema target namespace string 
     *//*
    AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
            axis2_svc_get_schema_target_ns(
                const axis2_svc_t *svc,
                const axutil_env_t *env);*/

    /**
     * Sets XML schema's target namespace.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @param ns namespace string 
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     *//*
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
            axis2_svc_set_schema_target_ns(
                axis2_svc_t *svc,
                const axutil_env_t *env,
                const axis2_char_t *ns);*/

    /**
     * Gets XML schema's target namespace prefix.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @return XML schema target namespace prefix string 
     *//*
    AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
            axis2_svc_get_schema_target_ns_prefix(
                const axis2_svc_t *svc,
                const axutil_env_t *env);*/

    /**
     * Sets XML schema's target namespace prefix.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @param prefix namespace prefix string 
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     *//*
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
            axis2_svc_set_schema_target_ns_prefix(
                axis2_svc_t *svc,
                const axutil_env_t *env,
                const axis2_char_t *prefix);*/

    /**
     * Gets target namespace.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @return target namespace as a string 
     */
    AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
    axis2_svc_get_target_ns(const axis2_svc_t *svc,
        const axutil_env_t *env);

    /**
     * Sets target namespace.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @param ns target namespace as a string 
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    saxis2_svc_et_target_ns(axis2_svc_t *svc,
        const axutil_env_t *env,
        const axis2_char_t *ns);

    /**
     * Gets target namespace prefix.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @return target namespace prefix string
     */
    AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
    axis2_svc_get_target_ns_prefix(const axis2_svc_t *svc,
        const axutil_env_t *env);

    /**
     * Sets target namespace prefix.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @param prefix target namespace prefix string
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_set_target_ns_prefix(axis2_svc_t *svc,
        const axutil_env_t *env,
        const axis2_char_t *prefix);

    /**
     * Gets XML schemas element corresponding to the given QName.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @param qname QName of the XML schema element to be retrieved
     * @return pointer to XML schema element, returns a reference, not a 
     * cloned copy
     */
    /*AXIS2_EXTERN xml_schema_element_t *AXIS2_CALL
            axis2_svc_get_schema_element(
                const axis2_svc_t *svc,
                const axutil_env_t *env,
                const axutil_qname_t *qname);*/

    /**
     * Gets the namespace map with all namespaces related to service.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @return pointer to hash map containing all namespaces, returns a 
     * reference, not a cloned copy
     */
    AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
    gaxis2_svc_et_ns_map(const axis2_svc_t *svc,
        const axutil_env_t *env);

    /**
     * Sets the namespace map with all namespaces related to service.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @param ns_map pointer to hash map containing all namespaces
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_set_ns_map(axis2_svc_t *svc,
        const axutil_env_t *env,
        axutil_hash_t *ns_map);

    /**
     * Populates the schema mappings. This method is used in code generation
     * and WSDL generation (WSDL2C and C2WSDL). This method deals with the 
     * imported schemas that would be there in the WSDL.
     * @param svc pointer to service struct
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    /*AXIS2_EXTERN axis2_status_t AXIS2_CALL
            axis2_svc_populate_schema_mappings(
                axis2_svc_t *svc,
                const axutil_env_t *env);*/

    AXIS2_EXTERN axutil_param_container_t *AXIS2_CALL
    axis2_svc_get_param_container(const axis2_svc_t *svc,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_flow_container_t *AXIS2_CALL
    axis2_svc_get_flow_container(const axis2_svc_t *svc,
        const axutil_env_t *env);

    /**
     * Creates a service struct instance.
     * @param env pointer to environment struct
     * @return pointer to newly created service
     */
    AXIS2_EXTERN axis2_svc_t *AXIS2_CALL
    axis2_svc_create(const axutil_env_t *env);

    /**
     * Creates a service struct with given QName.
     * @param env pointer to environment struct
     * @param qname service QName
     * @return pointer to newly created service
     */
    AXIS2_EXTERN axis2_svc_t *AXIS2_CALL
    axis2_svc_create_with_qname(const axutil_env_t *env,
        const axutil_qname_t *qname);

    AXIS2_EXTERN void *AXIS2_CALL
    axis2_svc_get_impl_class(const axis2_svc_t *svc,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_set_impl_class(axis2_svc_t *svc,
        const axutil_env_t *env,
        void *impl_class);

    /** 
     * Gets base description.
     * @param svc pointer to message
     * @param env pointer to environment struct
     * @return pointer to base description struct
     */
    AXIS2_EXTERN axis2_desc_t *AXIS2_CALL
    axis2_svc_get_base(const axis2_svc_t *svc,
        const axutil_env_t *env);

/** @} */
#ifdef __cplusplus
}
#endif
#endif                          /* AXIS2_SVC_H */
