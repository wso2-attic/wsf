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


        #ifndef ADB_SERVICEGROUPMETADATA_H
        #define ADB_SERVICEGROUPMETADATA_H

       /**
        * adb_ServiceGroupMetaData.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/Java version: SNAPSHOT  Built on : Jan 19, 2010 (01:47:08 IST)
        */

       /**
        *  adb_ServiceGroupMetaData class
        */

        
          #include "adb_ServiceMetaData.h"
          

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
        

        typedef struct adb_ServiceGroupMetaData adb_ServiceGroupMetaData_t;

        
        

        /******************************* Create and Free functions *********************************/

        /**
         * Constructor for creating adb_ServiceGroupMetaData_t
         * @param env pointer to environment struct
         * @return newly created adb_ServiceGroupMetaData_t object
         */
        adb_ServiceGroupMetaData_t* AXIS2_CALL
        adb_ServiceGroupMetaData_create(
            const axutil_env_t *env );

        /**
         * Wrapper for the "free" function, will invoke the extension mapper instead
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaData_free (
            adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
            const axutil_env_t *env);

        /**
         * Free adb_ServiceGroupMetaData_t object
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaData_free_obj (
            adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
            const axutil_env_t *env);



        /********************************** Getters and Setters **************************************/
        /******** Deprecated for array types, Use 'Getters and Setters for Arrays' instead ***********/
        

        /**
         * Getter for engagedModules. Deprecated for array types, Use adb_ServiceGroupMetaData_get_engagedModules_at instead
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @return Array of axis2_char_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_ServiceGroupMetaData_get_engagedModules(
            adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
            const axutil_env_t *env);

        /**
         * Setter for engagedModules.Deprecated for array types, Use adb_ServiceGroupMetaData_set_engagedModules_at
         * or adb_ServiceGroupMetaData_add_engagedModules instead.
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @param arg_engagedModules Array of axis2_char_t*s.
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaData_set_engagedModules(
            adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
            const axutil_env_t *env,
            axutil_array_list_t*  arg_engagedModules);

        /**
         * Resetter for engagedModules
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaData_reset_engagedModules(
            adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for mtomStatus. 
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServiceGroupMetaData_get_mtomStatus(
            adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
            const axutil_env_t *env);

        /**
         * Setter for mtomStatus.
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @param arg_mtomStatus axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaData_set_mtomStatus(
            adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_mtomStatus);

        /**
         * Resetter for mtomStatus
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaData_reset_mtomStatus(
            adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for serviceContextPath. 
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServiceGroupMetaData_get_serviceContextPath(
            adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
            const axutil_env_t *env);

        /**
         * Setter for serviceContextPath.
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @param arg_serviceContextPath axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaData_set_serviceContextPath(
            adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_serviceContextPath);

        /**
         * Resetter for serviceContextPath
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaData_reset_serviceContextPath(
            adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for serviceGroupName. 
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServiceGroupMetaData_get_serviceGroupName(
            adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
            const axutil_env_t *env);

        /**
         * Setter for serviceGroupName.
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @param arg_serviceGroupName axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaData_set_serviceGroupName(
            adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_serviceGroupName);

        /**
         * Resetter for serviceGroupName
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaData_reset_serviceGroupName(
            adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for services. Deprecated for array types, Use adb_ServiceGroupMetaData_get_services_at instead
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @return Array of adb_ServiceMetaData_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_ServiceGroupMetaData_get_services(
            adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
            const axutil_env_t *env);

        /**
         * Setter for services.Deprecated for array types, Use adb_ServiceGroupMetaData_set_services_at
         * or adb_ServiceGroupMetaData_add_services instead.
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @param arg_services Array of adb_ServiceMetaData_t*s.
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaData_set_services(
            adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
            const axutil_env_t *env,
            axutil_array_list_t*  arg_services);

        /**
         * Resetter for services
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaData_reset_services(
            adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
            const axutil_env_t *env);

        
        /****************************** Getters and Setters For Arrays **********************************/
        /************ Array Specific Operations: get_at, set_at, add, remove_at, sizeof *****************/

        /**
         * E.g. use of get_at, set_at, add and sizeof
         *
         * for(i = 0; i < adb_element_sizeof_property(adb_object, env); i ++ )
         * {
         *     // Getting ith value to property_object variable
         *     property_object = adb_element_get_property_at(adb_object, env, i);
         *
         *     // Setting ith value from property_object variable
         *     adb_element_set_property_at(adb_object, env, i, property_object);
         *
         *     // Appending the value to the end of the array from property_object variable
         *     adb_element_add_property(adb_object, env, property_object);
         *
         *     // Removing the ith value from an array
         *     adb_element_remove_property_at(adb_object, env, i);
         *     
         * }
         *
         */

        
        
        /**
         * Get the ith element of engagedModules.
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @return ith axis2_char_t* of the array
         */
        axis2_char_t* AXIS2_CALL
        adb_ServiceGroupMetaData_get_engagedModules_at(
                adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                const axutil_env_t *env, int i);

        /**
         * Set the ith element of engagedModules. (If the ith already exist, it will be replaced)
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @param arg_engagedModules element to set axis2_char_t* to the array
         * @return ith axis2_char_t* of the array
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaData_set_engagedModules_at(
                adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                const axutil_env_t *env, int i,
                const axis2_char_t* arg_engagedModules);


        /**
         * Add to engagedModules.
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @param arg_engagedModules element to add axis2_char_t* to the array
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaData_add_engagedModules(
                adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                const axutil_env_t *env,
                const axis2_char_t* arg_engagedModules);

        /**
         * Get the size of the engagedModules array.
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct.
         * @return the size of the engagedModules array.
         */
        int AXIS2_CALL
        adb_ServiceGroupMetaData_sizeof_engagedModules(
                    adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                    const axutil_env_t *env);

        /**
         * Remove the ith element of engagedModules.
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @param i index of the item to remove
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaData_remove_engagedModules_at(
                adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                const axutil_env_t *env, int i);

        
        
        /**
         * Get the ith element of services.
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @return ith adb_ServiceMetaData_t* of the array
         */
        adb_ServiceMetaData_t* AXIS2_CALL
        adb_ServiceGroupMetaData_get_services_at(
                adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                const axutil_env_t *env, int i);

        /**
         * Set the ith element of services. (If the ith already exist, it will be replaced)
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @param arg_services element to set adb_ServiceMetaData_t* to the array
         * @return ith adb_ServiceMetaData_t* of the array
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaData_set_services_at(
                adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                const axutil_env_t *env, int i,
                adb_ServiceMetaData_t* arg_services);


        /**
         * Add to services.
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @param arg_services element to add adb_ServiceMetaData_t* to the array
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaData_add_services(
                adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                const axutil_env_t *env,
                adb_ServiceMetaData_t* arg_services);

        /**
         * Get the size of the services array.
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct.
         * @return the size of the services array.
         */
        int AXIS2_CALL
        adb_ServiceGroupMetaData_sizeof_services(
                    adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                    const axutil_env_t *env);

        /**
         * Remove the ith element of services.
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @param i index of the item to remove
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaData_remove_services_at(
                adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                const axutil_env_t *env, int i);

        


        /******************************* Checking and Setting NIL values *********************************/
        /* Use 'Checking and Setting NIL values for Arrays' to check and set nil for individual elements */

        /**
         * NOTE: set_nil is only available for nillable properties
         */

        

        /**
         * Check whether engagedModules is nill
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceGroupMetaData_is_engagedModules_nil(
                adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                const axutil_env_t *env);


        
        /**
         * Set engagedModules to nill (currently the same as reset)
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaData_set_engagedModules_nil(
                adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                const axutil_env_t *env);
        

        /**
         * Check whether mtomStatus is nill
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceGroupMetaData_is_mtomStatus_nil(
                adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                const axutil_env_t *env);


        
        /**
         * Set mtomStatus to nill (currently the same as reset)
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaData_set_mtomStatus_nil(
                adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                const axutil_env_t *env);
        

        /**
         * Check whether serviceContextPath is nill
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceGroupMetaData_is_serviceContextPath_nil(
                adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                const axutil_env_t *env);


        
        /**
         * Set serviceContextPath to nill (currently the same as reset)
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaData_set_serviceContextPath_nil(
                adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                const axutil_env_t *env);
        

        /**
         * Check whether serviceGroupName is nill
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceGroupMetaData_is_serviceGroupName_nil(
                adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                const axutil_env_t *env);


        
        /**
         * Set serviceGroupName to nill (currently the same as reset)
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaData_set_serviceGroupName_nil(
                adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                const axutil_env_t *env);
        

        /**
         * Check whether services is nill
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceGroupMetaData_is_services_nil(
                adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                const axutil_env_t *env);


        
        /**
         * Set services to nill (currently the same as reset)
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaData_set_services_nil(
                adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                const axutil_env_t *env);
        
        /*************************** Checking and Setting 'NIL' values in Arrays *****************************/

        /**
         * NOTE: You may set this to remove specific elements in the array
         *       But you can not remove elements, if the specific property is declared to be non-nillable or sizeof(array) < minOccurs
         */
        
        /**
         * Check whether engagedModules is nill at i
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct.
         * @param i index of the item to return.
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceGroupMetaData_is_engagedModules_nil_at(
                adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                const axutil_env_t *env, int i);
 
       
        /**
         * Set engagedModules to nill at i
         * @param  _ServiceGroupMetaData _ adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct.
         * @param i index of the item to set.
         * @return AXIS2_SUCCESS on success, or AXIS2_FAILURE otherwise.
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaData_set_engagedModules_nil_at(
                adb_ServiceGroupMetaData_t* _ServiceGroupMetaData, 
                const axutil_env_t *env, int i);

        
        /**
         * Check whether services is nill at i
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct.
         * @param i index of the item to return.
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceGroupMetaData_is_services_nil_at(
                adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                const axutil_env_t *env, int i);
 
       
        /**
         * Set services to nill at i
         * @param  _ServiceGroupMetaData _ adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct.
         * @param i index of the item to set.
         * @return AXIS2_SUCCESS on success, or AXIS2_FAILURE otherwise.
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaData_set_services_nil_at(
                adb_ServiceGroupMetaData_t* _ServiceGroupMetaData, 
                const axutil_env_t *env, int i);

        

        /**************************** Serialize and Deserialize functions ***************************/
        /*********** These functions are for use only inside the generated code *********************/

        
        /**
         * Wrapper for the deserialization function, will invoke the extension mapper instead
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs, 
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaData_deserialize(
            adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);

        /**
         * Deserialize an XML to adb objects
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs,
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaData_deserialize_obj(
            adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);
                            
            

       /**
         * Declare namespace in the most parent node 
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @param parent_element parent element
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index pointer to an int which contain the next namespace index
         */
       void AXIS2_CALL
       adb_ServiceGroupMetaData_declare_parent_namespaces(
                    adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index);

        

        /**
         * Wrapper for the serialization function, will invoke the extension mapper instead
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @param ServiceGroupMetaData_om_node node to serialize from
         * @param ServiceGroupMetaData_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_ServiceGroupMetaData_serialize(
            adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
            const axutil_env_t *env,
            axiom_node_t* ServiceGroupMetaData_om_node, axiom_element_t *ServiceGroupMetaData_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Serialize to an XML from the adb objects
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @param ServiceGroupMetaData_om_node node to serialize from
         * @param ServiceGroupMetaData_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_ServiceGroupMetaData_serialize_obj(
            adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
            const axutil_env_t *env,
            axiom_node_t* ServiceGroupMetaData_om_node, axiom_element_t *ServiceGroupMetaData_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Check whether the adb_ServiceGroupMetaData is a particle class (E.g. group, inner sequence)
         * @return whether this is a particle class.
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceGroupMetaData_is_particle();

        /******************************* Alternatives for Create and Free functions *********************************/

        

        /**
         * Constructor for creating adb_ServiceGroupMetaData_t
         * @param env pointer to environment struct
         * @param _engagedModules axutil_array_list_t*
         * @param _mtomStatus axis2_char_t*
         * @param _serviceContextPath axis2_char_t*
         * @param _serviceGroupName axis2_char_t*
         * @param _services axutil_array_list_t*
         * @return newly created adb_ServiceGroupMetaData_t object
         */
        adb_ServiceGroupMetaData_t* AXIS2_CALL
        adb_ServiceGroupMetaData_create_with_values(
            const axutil_env_t *env,
                axutil_array_list_t* _engagedModules,
                axis2_char_t* _mtomStatus,
                axis2_char_t* _serviceContextPath,
                axis2_char_t* _serviceGroupName,
                axutil_array_list_t* _services);

        


                /**
                 * Free adb_ServiceGroupMetaData_t object and return the property value.
                 * You can use this to free the adb object as returning the property value. If there are
                 * many properties, it will only return the first property. Other properties will get freed with the adb object.
                 * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object to free
                 * @param env pointer to environment struct
                 * @return the property value holded by the ADB object, if there are many properties only returns the first.
                 */
                axutil_array_list_t* AXIS2_CALL
                adb_ServiceGroupMetaData_free_popping_value(
                        adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                        const axutil_env_t *env);
            

        /******************************* get the value by the property number  *********************************/
        /************NOTE: This method is introduced to resolve a problem in unwrapping mode *******************/

        
        

        /**
         * Getter for engagedModules by property number (1)
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @return Array of axis2_char_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_ServiceGroupMetaData_get_property1(
            adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for mtomStatus by property number (2)
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServiceGroupMetaData_get_property2(
            adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for serviceContextPath by property number (3)
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServiceGroupMetaData_get_property3(
            adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for serviceGroupName by property number (4)
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServiceGroupMetaData_get_property4(
            adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for services by property number (5)
         * @param  _ServiceGroupMetaData adb_ServiceGroupMetaData_t object
         * @param env pointer to environment struct
         * @return Array of adb_ServiceMetaData_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_ServiceGroupMetaData_get_property5(
            adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
            const axutil_env_t *env);

    
     #ifdef __cplusplus
     }
     #endif

     #endif /* ADB_SERVICEGROUPMETADATA_H */
    

