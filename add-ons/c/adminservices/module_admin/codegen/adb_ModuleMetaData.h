/*
* Copyright 2009-2010 WSO2, Inc. http://wso2.com
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/


        #ifndef ADB_MODULEMETADATA_H
        #define ADB_MODULEMETADATA_H

       /**
        * adb_ModuleMetaData.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/Java version: #axisVersion# #today#
        */

       /**
        *  adb_ModuleMetaData class
        */

        

        #include <stdio.h>
        #include <axiom.h>
        #include <axis2_util.h>
        #include <axiom_soap.h>
        #include <axis2_client.h>

        #include "axis2_extension_mapper.h"

        #ifdef __cplusplus
        extern "C"
        {
        #endif

        #define ADB_DEFAULT_DIGIT_LIMIT 1024
        #define ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT 64
        

        typedef struct adb_ModuleMetaData adb_ModuleMetaData_t;

        
        

        /******************************* Create and Free functions *********************************/

        /**
         * Constructor for creating adb_ModuleMetaData_t
         * @param env pointer to environment struct
         * @return newly created adb_ModuleMetaData_t object
         */
        adb_ModuleMetaData_t* AXIS2_CALL
        adb_ModuleMetaData_create(
            const axutil_env_t *env );

        /**
         * Wrapper for the "free" function, will invoke the extension mapper instead
         * @param  _ModuleMetaData adb_ModuleMetaData_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ModuleMetaData_free (
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env);

        /**
         * Free adb_ModuleMetaData_t object
         * @param  _ModuleMetaData adb_ModuleMetaData_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ModuleMetaData_free_obj (
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env);



        /********************************** Getters and Setters **************************************/
        
        

        /**
         * Getter for description. 
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ModuleMetaData_get_description(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env);

        /**
         * Setter for description.
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @param arg_description axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ModuleMetaData_set_description(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_description);

        /**
         * Resetter for description
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ModuleMetaData_reset_description(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for engagedGlobalLevel. 
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_ModuleMetaData_get_engagedGlobalLevel(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env);

        /**
         * Setter for engagedGlobalLevel.
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @param arg_engagedGlobalLevel axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ModuleMetaData_set_engagedGlobalLevel(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env,
            axis2_bool_t  arg_engagedGlobalLevel);

        /**
         * Resetter for engagedGlobalLevel
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ModuleMetaData_reset_engagedGlobalLevel(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for engagedOperationLevel. 
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_ModuleMetaData_get_engagedOperationLevel(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env);

        /**
         * Setter for engagedOperationLevel.
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @param arg_engagedOperationLevel axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ModuleMetaData_set_engagedOperationLevel(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env,
            axis2_bool_t  arg_engagedOperationLevel);

        /**
         * Resetter for engagedOperationLevel
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ModuleMetaData_reset_engagedOperationLevel(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for engagedServiceGroupLevel. 
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_ModuleMetaData_get_engagedServiceGroupLevel(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env);

        /**
         * Setter for engagedServiceGroupLevel.
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @param arg_engagedServiceGroupLevel axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ModuleMetaData_set_engagedServiceGroupLevel(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env,
            axis2_bool_t  arg_engagedServiceGroupLevel);

        /**
         * Resetter for engagedServiceGroupLevel
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ModuleMetaData_reset_engagedServiceGroupLevel(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for engagedServiceLevel. 
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_ModuleMetaData_get_engagedServiceLevel(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env);

        /**
         * Setter for engagedServiceLevel.
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @param arg_engagedServiceLevel axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ModuleMetaData_set_engagedServiceLevel(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env,
            axis2_bool_t  arg_engagedServiceLevel);

        /**
         * Resetter for engagedServiceLevel
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ModuleMetaData_reset_engagedServiceLevel(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for managedModule. 
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_ModuleMetaData_get_managedModule(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env);

        /**
         * Setter for managedModule.
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @param arg_managedModule axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ModuleMetaData_set_managedModule(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env,
            axis2_bool_t  arg_managedModule);

        /**
         * Resetter for managedModule
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ModuleMetaData_reset_managedModule(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for moduleId. 
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ModuleMetaData_get_moduleId(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env);

        /**
         * Setter for moduleId.
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @param arg_moduleId axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ModuleMetaData_set_moduleId(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_moduleId);

        /**
         * Resetter for moduleId
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ModuleMetaData_reset_moduleId(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for moduleVersion. 
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ModuleMetaData_get_moduleVersion(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env);

        /**
         * Setter for moduleVersion.
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @param arg_moduleVersion axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ModuleMetaData_set_moduleVersion(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_moduleVersion);

        /**
         * Resetter for moduleVersion
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ModuleMetaData_reset_moduleVersion(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for modulename. 
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ModuleMetaData_get_modulename(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env);

        /**
         * Setter for modulename.
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @param arg_modulename axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ModuleMetaData_set_modulename(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_modulename);

        /**
         * Resetter for modulename
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ModuleMetaData_reset_modulename(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env);

        


        /******************************* Checking and Setting NIL values *********************************/
        

        /**
         * NOTE: set_nil is only available for nillable properties
         */

        

        /**
         * Check whether description is nill
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ModuleMetaData_is_description_nil(
                adb_ModuleMetaData_t* _ModuleMetaData,
                const axutil_env_t *env);


        
        /**
         * Set description to nill (currently the same as reset)
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ModuleMetaData_set_description_nil(
                adb_ModuleMetaData_t* _ModuleMetaData,
                const axutil_env_t *env);
        

        /**
         * Check whether engagedGlobalLevel is nill
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ModuleMetaData_is_engagedGlobalLevel_nil(
                adb_ModuleMetaData_t* _ModuleMetaData,
                const axutil_env_t *env);


        

        /**
         * Check whether engagedOperationLevel is nill
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ModuleMetaData_is_engagedOperationLevel_nil(
                adb_ModuleMetaData_t* _ModuleMetaData,
                const axutil_env_t *env);


        

        /**
         * Check whether engagedServiceGroupLevel is nill
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ModuleMetaData_is_engagedServiceGroupLevel_nil(
                adb_ModuleMetaData_t* _ModuleMetaData,
                const axutil_env_t *env);


        

        /**
         * Check whether engagedServiceLevel is nill
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ModuleMetaData_is_engagedServiceLevel_nil(
                adb_ModuleMetaData_t* _ModuleMetaData,
                const axutil_env_t *env);


        

        /**
         * Check whether managedModule is nill
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ModuleMetaData_is_managedModule_nil(
                adb_ModuleMetaData_t* _ModuleMetaData,
                const axutil_env_t *env);


        

        /**
         * Check whether moduleId is nill
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ModuleMetaData_is_moduleId_nil(
                adb_ModuleMetaData_t* _ModuleMetaData,
                const axutil_env_t *env);


        
        /**
         * Set moduleId to nill (currently the same as reset)
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ModuleMetaData_set_moduleId_nil(
                adb_ModuleMetaData_t* _ModuleMetaData,
                const axutil_env_t *env);
        

        /**
         * Check whether moduleVersion is nill
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ModuleMetaData_is_moduleVersion_nil(
                adb_ModuleMetaData_t* _ModuleMetaData,
                const axutil_env_t *env);


        
        /**
         * Set moduleVersion to nill (currently the same as reset)
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ModuleMetaData_set_moduleVersion_nil(
                adb_ModuleMetaData_t* _ModuleMetaData,
                const axutil_env_t *env);
        

        /**
         * Check whether modulename is nill
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ModuleMetaData_is_modulename_nil(
                adb_ModuleMetaData_t* _ModuleMetaData,
                const axutil_env_t *env);


        
        /**
         * Set modulename to nill (currently the same as reset)
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ModuleMetaData_set_modulename_nil(
                adb_ModuleMetaData_t* _ModuleMetaData,
                const axutil_env_t *env);
        

        /**************************** Serialize and Deserialize functions ***************************/
        /*********** These functions are for use only inside the generated code *********************/

        
        /**
         * Wrapper for the deserialization function, will invoke the extension mapper instead
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs, 
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ModuleMetaData_deserialize(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);

        /**
         * Deserialize an XML to adb objects
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs,
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ModuleMetaData_deserialize_obj(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);
                            
            

       /**
         * Declare namespace in the most parent node 
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @param parent_element parent element
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index pointer to an int which contain the next namespace index
         */
       void AXIS2_CALL
       adb_ModuleMetaData_declare_parent_namespaces(
                    adb_ModuleMetaData_t* _ModuleMetaData,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index);

        

        /**
         * Wrapper for the serialization function, will invoke the extension mapper instead
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @param ModuleMetaData_om_node node to serialize from
         * @param ModuleMetaData_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_ModuleMetaData_serialize(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env,
            axiom_node_t* ModuleMetaData_om_node, axiom_element_t *ModuleMetaData_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Serialize to an XML from the adb objects
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @param ModuleMetaData_om_node node to serialize from
         * @param ModuleMetaData_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_ModuleMetaData_serialize_obj(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env,
            axiom_node_t* ModuleMetaData_om_node, axiom_element_t *ModuleMetaData_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Check whether the adb_ModuleMetaData is a particle class (E.g. group, inner sequence)
         * @return whether this is a particle class.
         */
        axis2_bool_t AXIS2_CALL
        adb_ModuleMetaData_is_particle();

        /******************************* Alternatives for Create and Free functions *********************************/

        

        /**
         * Constructor for creating adb_ModuleMetaData_t
         * @param env pointer to environment struct
         * @param _description axis2_char_t*
         * @param _engagedGlobalLevel axis2_bool_t
         * @param _engagedOperationLevel axis2_bool_t
         * @param _engagedServiceGroupLevel axis2_bool_t
         * @param _engagedServiceLevel axis2_bool_t
         * @param _managedModule axis2_bool_t
         * @param _moduleId axis2_char_t*
         * @param _moduleVersion axis2_char_t*
         * @param _modulename axis2_char_t*
         * @return newly created adb_ModuleMetaData_t object
         */
        adb_ModuleMetaData_t* AXIS2_CALL
        adb_ModuleMetaData_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _description,
                axis2_bool_t _engagedGlobalLevel,
                axis2_bool_t _engagedOperationLevel,
                axis2_bool_t _engagedServiceGroupLevel,
                axis2_bool_t _engagedServiceLevel,
                axis2_bool_t _managedModule,
                axis2_char_t* _moduleId,
                axis2_char_t* _moduleVersion,
                axis2_char_t* _modulename);

        


                /**
                 * Free adb_ModuleMetaData_t object and return the property value.
                 * You can use this to free the adb object as returning the property value. If there are
                 * many properties, it will only return the first property. Other properties will get freed with the adb object.
                 * @param  _ModuleMetaData adb_ModuleMetaData_t object to free
                 * @param env pointer to environment struct
                 * @return the property value holded by the ADB object, if there are many properties only returns the first.
                 */
                axis2_char_t* AXIS2_CALL
                adb_ModuleMetaData_free_popping_value(
                        adb_ModuleMetaData_t* _ModuleMetaData,
                        const axutil_env_t *env);
            

        /******************************* get the value by the property number  *********************************/
        /************NOTE: This method is introduced to resolve a problem in unwrapping mode *******************/

        
        

        /**
         * Getter for description by property number (1)
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ModuleMetaData_get_property1(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for engagedGlobalLevel by property number (2)
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_ModuleMetaData_get_property2(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for engagedOperationLevel by property number (3)
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_ModuleMetaData_get_property3(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for engagedServiceGroupLevel by property number (4)
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_ModuleMetaData_get_property4(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for engagedServiceLevel by property number (5)
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_ModuleMetaData_get_property5(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for managedModule by property number (6)
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_ModuleMetaData_get_property6(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for moduleId by property number (7)
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ModuleMetaData_get_property7(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for moduleVersion by property number (8)
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ModuleMetaData_get_property8(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for modulename by property number (9)
         * @param  _ModuleMetaData adb_ModuleMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ModuleMetaData_get_property9(
            adb_ModuleMetaData_t* _ModuleMetaData,
            const axutil_env_t *env);

    
     #ifdef __cplusplus
     }
     #endif

     #endif /* ADB_MODULEMETADATA_H */
    

