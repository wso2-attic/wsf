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


        #ifndef ADB_SERVICEMETADATA_H
        #define ADB_SERVICEMETADATA_H

       /**
        * adb_ServiceMetaData.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/Java version: #axisVersion# #today#
        */

       /**
        *  adb_ServiceMetaData class
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
        

        typedef struct adb_ServiceMetaData adb_ServiceMetaData_t;

        
        

        /******************************* Create and Free functions *********************************/

        /**
         * Constructor for creating adb_ServiceMetaData_t
         * @param env pointer to environment struct
         * @return newly created adb_ServiceMetaData_t object
         */
        adb_ServiceMetaData_t* AXIS2_CALL
        adb_ServiceMetaData_create(
            const axutil_env_t *env );

        /**
         * Wrapper for the "free" function, will invoke the extension mapper instead
         * @param  _ServiceMetaData adb_ServiceMetaData_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_free (
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

        /**
         * Free adb_ServiceMetaData_t object
         * @param  _ServiceMetaData adb_ServiceMetaData_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_free_obj (
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);



        /********************************** Getters and Setters **************************************/
        /******** Deprecated for array types, Use 'Getters and Setters for Arrays' instead ***********/
        

        /**
         * Getter for active. 
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceMetaData_get_active(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

        /**
         * Setter for active.
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @param arg_active axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_set_active(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env,
            axis2_bool_t  arg_active);

        /**
         * Resetter for active
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_reset_active(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for description. 
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServiceMetaData_get_description(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

        /**
         * Setter for description.
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @param arg_description axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_set_description(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_description);

        /**
         * Resetter for description
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_reset_description(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for disableTryit. 
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceMetaData_get_disableTryit(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

        /**
         * Setter for disableTryit.
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @param arg_disableTryit axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_set_disableTryit(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env,
            axis2_bool_t  arg_disableTryit);

        /**
         * Resetter for disableTryit
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_reset_disableTryit(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for eprs. Deprecated for array types, Use adb_ServiceMetaData_get_eprs_at instead
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return Array of axis2_char_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_ServiceMetaData_get_eprs(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

        /**
         * Setter for eprs.Deprecated for array types, Use adb_ServiceMetaData_set_eprs_at
         * or adb_ServiceMetaData_add_eprs instead.
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @param arg_eprs Array of axis2_char_t*s.
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_set_eprs(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env,
            axutil_array_list_t*  arg_eprs);

        /**
         * Resetter for eprs
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_reset_eprs(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for foundWebResources. 
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceMetaData_get_foundWebResources(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

        /**
         * Setter for foundWebResources.
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @param arg_foundWebResources axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_set_foundWebResources(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env,
            axis2_bool_t  arg_foundWebResources);

        /**
         * Resetter for foundWebResources
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_reset_foundWebResources(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for mtomStatus. 
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServiceMetaData_get_mtomStatus(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

        /**
         * Setter for mtomStatus.
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @param arg_mtomStatus axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_set_mtomStatus(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_mtomStatus);

        /**
         * Resetter for mtomStatus
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_reset_mtomStatus(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for name. 
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServiceMetaData_get_name(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

        /**
         * Setter for name.
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @param arg_name axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_set_name(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_name);

        /**
         * Resetter for name
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_reset_name(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for operations. Deprecated for array types, Use adb_ServiceMetaData_get_operations_at instead
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return Array of axis2_char_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_ServiceMetaData_get_operations(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

        /**
         * Setter for operations.Deprecated for array types, Use adb_ServiceMetaData_set_operations_at
         * or adb_ServiceMetaData_add_operations instead.
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @param arg_operations Array of axis2_char_t*s.
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_set_operations(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env,
            axutil_array_list_t*  arg_operations);

        /**
         * Resetter for operations
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_reset_operations(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for scope. 
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServiceMetaData_get_scope(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

        /**
         * Setter for scope.
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @param arg_scope axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_set_scope(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_scope);

        /**
         * Resetter for scope
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_reset_scope(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for serviceGroupName. 
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServiceMetaData_get_serviceGroupName(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

        /**
         * Setter for serviceGroupName.
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @param arg_serviceGroupName axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_set_serviceGroupName(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_serviceGroupName);

        /**
         * Resetter for serviceGroupName
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_reset_serviceGroupName(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for serviceId. 
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServiceMetaData_get_serviceId(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

        /**
         * Setter for serviceId.
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @param arg_serviceId axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_set_serviceId(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_serviceId);

        /**
         * Resetter for serviceId
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_reset_serviceId(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for serviceType. 
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServiceMetaData_get_serviceType(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

        /**
         * Setter for serviceType.
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @param arg_serviceType axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_set_serviceType(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_serviceType);

        /**
         * Resetter for serviceType
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_reset_serviceType(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for serviceVersion. 
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServiceMetaData_get_serviceVersion(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

        /**
         * Setter for serviceVersion.
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @param arg_serviceVersion axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_set_serviceVersion(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_serviceVersion);

        /**
         * Resetter for serviceVersion
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_reset_serviceVersion(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for tryitURL. 
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServiceMetaData_get_tryitURL(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

        /**
         * Setter for tryitURL.
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @param arg_tryitURL axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_set_tryitURL(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_tryitURL);

        /**
         * Resetter for tryitURL
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_reset_tryitURL(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for wsdlURLs. Deprecated for array types, Use adb_ServiceMetaData_get_wsdlURLs_at instead
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return Array of axis2_char_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_ServiceMetaData_get_wsdlURLs(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

        /**
         * Setter for wsdlURLs.Deprecated for array types, Use adb_ServiceMetaData_set_wsdlURLs_at
         * or adb_ServiceMetaData_add_wsdlURLs instead.
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @param arg_wsdlURLs Array of axis2_char_t*s.
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_set_wsdlURLs(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env,
            axutil_array_list_t*  arg_wsdlURLs);

        /**
         * Resetter for wsdlURLs
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_reset_wsdlURLs(
            adb_ServiceMetaData_t* _ServiceMetaData,
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
         * Get the ith element of eprs.
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @return ith axis2_char_t* of the array
         */
        axis2_char_t* AXIS2_CALL
        adb_ServiceMetaData_get_eprs_at(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env, int i);

        /**
         * Set the ith element of eprs. (If the ith already exist, it will be replaced)
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @param arg_eprs element to set axis2_char_t* to the array
         * @return ith axis2_char_t* of the array
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_set_eprs_at(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env, int i,
                const axis2_char_t* arg_eprs);


        /**
         * Add to eprs.
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @param arg_eprs element to add axis2_char_t* to the array
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_add_eprs(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env,
                const axis2_char_t* arg_eprs);

        /**
         * Get the size of the eprs array.
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct.
         * @return the size of the eprs array.
         */
        int AXIS2_CALL
        adb_ServiceMetaData_sizeof_eprs(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env);

        /**
         * Remove the ith element of eprs.
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @param i index of the item to remove
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_remove_eprs_at(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env, int i);

        
        
        /**
         * Get the ith element of operations.
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @return ith axis2_char_t* of the array
         */
        axis2_char_t* AXIS2_CALL
        adb_ServiceMetaData_get_operations_at(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env, int i);

        /**
         * Set the ith element of operations. (If the ith already exist, it will be replaced)
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @param arg_operations element to set axis2_char_t* to the array
         * @return ith axis2_char_t* of the array
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_set_operations_at(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env, int i,
                const axis2_char_t* arg_operations);


        /**
         * Add to operations.
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @param arg_operations element to add axis2_char_t* to the array
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_add_operations(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env,
                const axis2_char_t* arg_operations);

        /**
         * Get the size of the operations array.
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct.
         * @return the size of the operations array.
         */
        int AXIS2_CALL
        adb_ServiceMetaData_sizeof_operations(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env);

        /**
         * Remove the ith element of operations.
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @param i index of the item to remove
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_remove_operations_at(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env, int i);

        
        
        /**
         * Get the ith element of wsdlURLs.
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @return ith axis2_char_t* of the array
         */
        axis2_char_t* AXIS2_CALL
        adb_ServiceMetaData_get_wsdlURLs_at(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env, int i);

        /**
         * Set the ith element of wsdlURLs. (If the ith already exist, it will be replaced)
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @param arg_wsdlURLs element to set axis2_char_t* to the array
         * @return ith axis2_char_t* of the array
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_set_wsdlURLs_at(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env, int i,
                const axis2_char_t* arg_wsdlURLs);


        /**
         * Add to wsdlURLs.
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @param arg_wsdlURLs element to add axis2_char_t* to the array
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_add_wsdlURLs(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env,
                const axis2_char_t* arg_wsdlURLs);

        /**
         * Get the size of the wsdlURLs array.
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct.
         * @return the size of the wsdlURLs array.
         */
        int AXIS2_CALL
        adb_ServiceMetaData_sizeof_wsdlURLs(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env);

        /**
         * Remove the ith element of wsdlURLs.
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @param i index of the item to remove
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_remove_wsdlURLs_at(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env, int i);

        


        /******************************* Checking and Setting NIL values *********************************/
        /* Use 'Checking and Setting NIL values for Arrays' to check and set nil for individual elements */

        /**
         * NOTE: set_nil is only available for nillable properties
         */

        

        /**
         * Check whether active is nill
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceMetaData_is_active_nil(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env);


        

        /**
         * Check whether description is nill
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceMetaData_is_description_nil(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env);


        
        /**
         * Set description to nill (currently the same as reset)
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_set_description_nil(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env);
        

        /**
         * Check whether disableTryit is nill
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceMetaData_is_disableTryit_nil(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env);


        

        /**
         * Check whether eprs is nill
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceMetaData_is_eprs_nil(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env);


        
        /**
         * Set eprs to nill (currently the same as reset)
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_set_eprs_nil(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env);
        

        /**
         * Check whether foundWebResources is nill
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceMetaData_is_foundWebResources_nil(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env);


        

        /**
         * Check whether mtomStatus is nill
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceMetaData_is_mtomStatus_nil(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env);


        
        /**
         * Set mtomStatus to nill (currently the same as reset)
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_set_mtomStatus_nil(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env);
        

        /**
         * Check whether name is nill
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceMetaData_is_name_nil(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env);


        
        /**
         * Set name to nill (currently the same as reset)
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_set_name_nil(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env);
        

        /**
         * Check whether operations is nill
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceMetaData_is_operations_nil(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env);


        
        /**
         * Set operations to nill (currently the same as reset)
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_set_operations_nil(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env);
        

        /**
         * Check whether scope is nill
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceMetaData_is_scope_nil(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env);


        
        /**
         * Set scope to nill (currently the same as reset)
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_set_scope_nil(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env);
        

        /**
         * Check whether serviceGroupName is nill
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceMetaData_is_serviceGroupName_nil(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env);


        
        /**
         * Set serviceGroupName to nill (currently the same as reset)
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_set_serviceGroupName_nil(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env);
        

        /**
         * Check whether serviceId is nill
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceMetaData_is_serviceId_nil(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env);


        
        /**
         * Set serviceId to nill (currently the same as reset)
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_set_serviceId_nil(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env);
        

        /**
         * Check whether serviceType is nill
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceMetaData_is_serviceType_nil(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env);


        
        /**
         * Set serviceType to nill (currently the same as reset)
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_set_serviceType_nil(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env);
        

        /**
         * Check whether serviceVersion is nill
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceMetaData_is_serviceVersion_nil(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env);


        
        /**
         * Set serviceVersion to nill (currently the same as reset)
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_set_serviceVersion_nil(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env);
        

        /**
         * Check whether tryitURL is nill
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceMetaData_is_tryitURL_nil(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env);


        
        /**
         * Set tryitURL to nill (currently the same as reset)
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_set_tryitURL_nil(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env);
        

        /**
         * Check whether wsdlURLs is nill
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceMetaData_is_wsdlURLs_nil(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env);


        
        /**
         * Set wsdlURLs to nill (currently the same as reset)
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_set_wsdlURLs_nil(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env);
        
        /*************************** Checking and Setting 'NIL' values in Arrays *****************************/

        /**
         * NOTE: You may set this to remove specific elements in the array
         *       But you can not remove elements, if the specific property is declared to be non-nillable or sizeof(array) < minOccurs
         */
        
        /**
         * Check whether eprs is nill at i
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct.
         * @param i index of the item to return.
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceMetaData_is_eprs_nil_at(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env, int i);
 
       
        /**
         * Set eprs to nill at i
         * @param  _ServiceMetaData _ adb_ServiceMetaData_t object
         * @param env pointer to environment struct.
         * @param i index of the item to set.
         * @return AXIS2_SUCCESS on success, or AXIS2_FAILURE otherwise.
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_set_eprs_nil_at(
                adb_ServiceMetaData_t* _ServiceMetaData, 
                const axutil_env_t *env, int i);

        
        /**
         * Check whether operations is nill at i
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct.
         * @param i index of the item to return.
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceMetaData_is_operations_nil_at(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env, int i);
 
       
        /**
         * Set operations to nill at i
         * @param  _ServiceMetaData _ adb_ServiceMetaData_t object
         * @param env pointer to environment struct.
         * @param i index of the item to set.
         * @return AXIS2_SUCCESS on success, or AXIS2_FAILURE otherwise.
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_set_operations_nil_at(
                adb_ServiceMetaData_t* _ServiceMetaData, 
                const axutil_env_t *env, int i);

        
        /**
         * Check whether wsdlURLs is nill at i
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct.
         * @param i index of the item to return.
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceMetaData_is_wsdlURLs_nil_at(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env, int i);
 
       
        /**
         * Set wsdlURLs to nill at i
         * @param  _ServiceMetaData _ adb_ServiceMetaData_t object
         * @param env pointer to environment struct.
         * @param i index of the item to set.
         * @return AXIS2_SUCCESS on success, or AXIS2_FAILURE otherwise.
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_set_wsdlURLs_nil_at(
                adb_ServiceMetaData_t* _ServiceMetaData, 
                const axutil_env_t *env, int i);

        

        /**************************** Serialize and Deserialize functions ***************************/
        /*********** These functions are for use only inside the generated code *********************/

        
        /**
         * Wrapper for the deserialization function, will invoke the extension mapper instead
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs, 
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_deserialize(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);

        /**
         * Deserialize an XML to adb objects
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs,
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_deserialize_obj(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);
                            
            

       /**
         * Declare namespace in the most parent node 
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @param parent_element parent element
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index pointer to an int which contain the next namespace index
         */
       void AXIS2_CALL
       adb_ServiceMetaData_declare_parent_namespaces(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index);

        

        /**
         * Wrapper for the serialization function, will invoke the extension mapper instead
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @param ServiceMetaData_om_node node to serialize from
         * @param ServiceMetaData_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_ServiceMetaData_serialize(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env,
            axiom_node_t* ServiceMetaData_om_node, axiom_element_t *ServiceMetaData_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Serialize to an XML from the adb objects
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @param ServiceMetaData_om_node node to serialize from
         * @param ServiceMetaData_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_ServiceMetaData_serialize_obj(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env,
            axiom_node_t* ServiceMetaData_om_node, axiom_element_t *ServiceMetaData_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Check whether the adb_ServiceMetaData is a particle class (E.g. group, inner sequence)
         * @return whether this is a particle class.
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceMetaData_is_particle();

        /******************************* Alternatives for Create and Free functions *********************************/

        

        /**
         * Constructor for creating adb_ServiceMetaData_t
         * @param env pointer to environment struct
         * @param _active axis2_bool_t
         * @param _description axis2_char_t*
         * @param _disableTryit axis2_bool_t
         * @param _eprs axutil_array_list_t*
         * @param _foundWebResources axis2_bool_t
         * @param _mtomStatus axis2_char_t*
         * @param _name axis2_char_t*
         * @param _operations axutil_array_list_t*
         * @param _scope axis2_char_t*
         * @param _serviceGroupName axis2_char_t*
         * @param _serviceId axis2_char_t*
         * @param _serviceType axis2_char_t*
         * @param _serviceVersion axis2_char_t*
         * @param _tryitURL axis2_char_t*
         * @param _wsdlURLs axutil_array_list_t*
         * @return newly created adb_ServiceMetaData_t object
         */
        adb_ServiceMetaData_t* AXIS2_CALL
        adb_ServiceMetaData_create_with_values(
            const axutil_env_t *env,
                axis2_bool_t _active,
                axis2_char_t* _description,
                axis2_bool_t _disableTryit,
                axutil_array_list_t* _eprs,
                axis2_bool_t _foundWebResources,
                axis2_char_t* _mtomStatus,
                axis2_char_t* _name,
                axutil_array_list_t* _operations,
                axis2_char_t* _scope,
                axis2_char_t* _serviceGroupName,
                axis2_char_t* _serviceId,
                axis2_char_t* _serviceType,
                axis2_char_t* _serviceVersion,
                axis2_char_t* _tryitURL,
                axutil_array_list_t* _wsdlURLs);

        


                /**
                 * Free adb_ServiceMetaData_t object and return the property value.
                 * You can use this to free the adb object as returning the property value. If there are
                 * many properties, it will only return the first property. Other properties will get freed with the adb object.
                 * @param  _ServiceMetaData adb_ServiceMetaData_t object to free
                 * @param env pointer to environment struct
                 * @return the property value holded by the ADB object, if there are many properties only returns the first.
                 */
                axis2_bool_t AXIS2_CALL
                adb_ServiceMetaData_free_popping_value(
                        adb_ServiceMetaData_t* _ServiceMetaData,
                        const axutil_env_t *env);
            

        /******************************* get the value by the property number  *********************************/
        /************NOTE: This method is introduced to resolve a problem in unwrapping mode *******************/

        
        

        /**
         * Getter for active by property number (1)
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceMetaData_get_property1(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for description by property number (2)
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServiceMetaData_get_property2(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for disableTryit by property number (3)
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceMetaData_get_property3(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for eprs by property number (4)
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return Array of axis2_char_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_ServiceMetaData_get_property4(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for foundWebResources by property number (5)
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceMetaData_get_property5(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for mtomStatus by property number (6)
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServiceMetaData_get_property6(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for name by property number (7)
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServiceMetaData_get_property7(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for operations by property number (8)
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return Array of axis2_char_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_ServiceMetaData_get_property8(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for scope by property number (9)
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServiceMetaData_get_property9(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for serviceGroupName by property number (10)
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServiceMetaData_get_property10(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for serviceId by property number (11)
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServiceMetaData_get_property11(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for serviceType by property number (12)
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServiceMetaData_get_property12(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for serviceVersion by property number (13)
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServiceMetaData_get_property13(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for tryitURL by property number (14)
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ServiceMetaData_get_property14(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for wsdlURLs by property number (15)
         * @param  _ServiceMetaData adb_ServiceMetaData_t object
         * @param env pointer to environment struct
         * @return Array of axis2_char_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_ServiceMetaData_get_property15(
            adb_ServiceMetaData_t* _ServiceMetaData,
            const axutil_env_t *env);

    
     #ifdef __cplusplus
     }
     #endif

     #endif /* ADB_SERVICEMETADATA_H */
    

