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


        #ifndef ADB_COLLECTIONCONTENTBEAN_H
        #define ADB_COLLECTIONCONTENTBEAN_H

       /**
        * adb_CollectionContentBean.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/Java version: #axisVersion# #today#
        */

       /**
        *  adb_CollectionContentBean class
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
        

        typedef struct adb_CollectionContentBean adb_CollectionContentBean_t;

        
        

        /******************************* Create and Free functions *********************************/

        /**
         * Constructor for creating adb_CollectionContentBean_t
         * @param env pointer to environment struct
         * @return newly created adb_CollectionContentBean_t object
         */
        adb_CollectionContentBean_t* AXIS2_CALL
        adb_CollectionContentBean_create(
            const axutil_env_t *env );

        /**
         * Wrapper for the "free" function, will invoke the extension mapper instead
         * @param  _CollectionContentBean adb_CollectionContentBean_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CollectionContentBean_free (
            adb_CollectionContentBean_t* _CollectionContentBean,
            const axutil_env_t *env);

        /**
         * Free adb_CollectionContentBean_t object
         * @param  _CollectionContentBean adb_CollectionContentBean_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CollectionContentBean_free_obj (
            adb_CollectionContentBean_t* _CollectionContentBean,
            const axutil_env_t *env);



        /********************************** Getters and Setters **************************************/
        /******** Deprecated for array types, Use 'Getters and Setters for Arrays' instead ***********/
        

        /**
         * Getter for childCount. 
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @return int
         */
        int AXIS2_CALL
        adb_CollectionContentBean_get_childCount(
            adb_CollectionContentBean_t* _CollectionContentBean,
            const axutil_env_t *env);

        /**
         * Setter for childCount.
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @param arg_childCount int
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CollectionContentBean_set_childCount(
            adb_CollectionContentBean_t* _CollectionContentBean,
            const axutil_env_t *env,
            const int  arg_childCount);

        /**
         * Resetter for childCount
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CollectionContentBean_reset_childCount(
            adb_CollectionContentBean_t* _CollectionContentBean,
            const axutil_env_t *env);

        
        

        /**
         * Getter for childPaths. Deprecated for array types, Use adb_CollectionContentBean_get_childPaths_at instead
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @return Array of axis2_char_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_CollectionContentBean_get_childPaths(
            adb_CollectionContentBean_t* _CollectionContentBean,
            const axutil_env_t *env);

        /**
         * Setter for childPaths.Deprecated for array types, Use adb_CollectionContentBean_set_childPaths_at
         * or adb_CollectionContentBean_add_childPaths instead.
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @param arg_childPaths Array of axis2_char_t*s.
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CollectionContentBean_set_childPaths(
            adb_CollectionContentBean_t* _CollectionContentBean,
            const axutil_env_t *env,
            axutil_array_list_t*  arg_childPaths);

        /**
         * Resetter for childPaths
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CollectionContentBean_reset_childPaths(
            adb_CollectionContentBean_t* _CollectionContentBean,
            const axutil_env_t *env);

        
        

        /**
         * Getter for collectionTypes. Deprecated for array types, Use adb_CollectionContentBean_get_collectionTypes_at instead
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @return Array of axis2_char_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_CollectionContentBean_get_collectionTypes(
            adb_CollectionContentBean_t* _CollectionContentBean,
            const axutil_env_t *env);

        /**
         * Setter for collectionTypes.Deprecated for array types, Use adb_CollectionContentBean_set_collectionTypes_at
         * or adb_CollectionContentBean_add_collectionTypes instead.
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @param arg_collectionTypes Array of axis2_char_t*s.
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CollectionContentBean_set_collectionTypes(
            adb_CollectionContentBean_t* _CollectionContentBean,
            const axutil_env_t *env,
            axutil_array_list_t*  arg_collectionTypes);

        /**
         * Resetter for collectionTypes
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CollectionContentBean_reset_collectionTypes(
            adb_CollectionContentBean_t* _CollectionContentBean,
            const axutil_env_t *env);

        
        

        /**
         * Getter for pathWithVersion. 
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_CollectionContentBean_get_pathWithVersion(
            adb_CollectionContentBean_t* _CollectionContentBean,
            const axutil_env_t *env);

        /**
         * Setter for pathWithVersion.
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @param arg_pathWithVersion axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CollectionContentBean_set_pathWithVersion(
            adb_CollectionContentBean_t* _CollectionContentBean,
            const axutil_env_t *env,
            const axis2_char_t*  arg_pathWithVersion);

        /**
         * Resetter for pathWithVersion
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CollectionContentBean_reset_pathWithVersion(
            adb_CollectionContentBean_t* _CollectionContentBean,
            const axutil_env_t *env);

        
        

        /**
         * Getter for remoteInstances. Deprecated for array types, Use adb_CollectionContentBean_get_remoteInstances_at instead
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @return Array of axis2_char_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_CollectionContentBean_get_remoteInstances(
            adb_CollectionContentBean_t* _CollectionContentBean,
            const axutil_env_t *env);

        /**
         * Setter for remoteInstances.Deprecated for array types, Use adb_CollectionContentBean_set_remoteInstances_at
         * or adb_CollectionContentBean_add_remoteInstances instead.
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @param arg_remoteInstances Array of axis2_char_t*s.
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CollectionContentBean_set_remoteInstances(
            adb_CollectionContentBean_t* _CollectionContentBean,
            const axutil_env_t *env,
            axutil_array_list_t*  arg_remoteInstances);

        /**
         * Resetter for remoteInstances
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CollectionContentBean_reset_remoteInstances(
            adb_CollectionContentBean_t* _CollectionContentBean,
            const axutil_env_t *env);

        
        

        /**
         * Getter for versionView. 
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_CollectionContentBean_get_versionView(
            adb_CollectionContentBean_t* _CollectionContentBean,
            const axutil_env_t *env);

        /**
         * Setter for versionView.
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @param arg_versionView axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CollectionContentBean_set_versionView(
            adb_CollectionContentBean_t* _CollectionContentBean,
            const axutil_env_t *env,
            axis2_bool_t  arg_versionView);

        /**
         * Resetter for versionView
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CollectionContentBean_reset_versionView(
            adb_CollectionContentBean_t* _CollectionContentBean,
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
         * Get the ith element of childPaths.
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @return ith axis2_char_t* of the array
         */
        axis2_char_t* AXIS2_CALL
        adb_CollectionContentBean_get_childPaths_at(
                adb_CollectionContentBean_t* _CollectionContentBean,
                const axutil_env_t *env, int i);

        /**
         * Set the ith element of childPaths. (If the ith already exist, it will be replaced)
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @param arg_childPaths element to set axis2_char_t* to the array
         * @return ith axis2_char_t* of the array
         */
        axis2_status_t AXIS2_CALL
        adb_CollectionContentBean_set_childPaths_at(
                adb_CollectionContentBean_t* _CollectionContentBean,
                const axutil_env_t *env, int i,
                const axis2_char_t* arg_childPaths);


        /**
         * Add to childPaths.
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @param arg_childPaths element to add axis2_char_t* to the array
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CollectionContentBean_add_childPaths(
                adb_CollectionContentBean_t* _CollectionContentBean,
                const axutil_env_t *env,
                const axis2_char_t* arg_childPaths);

        /**
         * Get the size of the childPaths array.
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct.
         * @return the size of the childPaths array.
         */
        int AXIS2_CALL
        adb_CollectionContentBean_sizeof_childPaths(
                    adb_CollectionContentBean_t* _CollectionContentBean,
                    const axutil_env_t *env);

        /**
         * Remove the ith element of childPaths.
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @param i index of the item to remove
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CollectionContentBean_remove_childPaths_at(
                adb_CollectionContentBean_t* _CollectionContentBean,
                const axutil_env_t *env, int i);

        
        
        /**
         * Get the ith element of collectionTypes.
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @return ith axis2_char_t* of the array
         */
        axis2_char_t* AXIS2_CALL
        adb_CollectionContentBean_get_collectionTypes_at(
                adb_CollectionContentBean_t* _CollectionContentBean,
                const axutil_env_t *env, int i);

        /**
         * Set the ith element of collectionTypes. (If the ith already exist, it will be replaced)
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @param arg_collectionTypes element to set axis2_char_t* to the array
         * @return ith axis2_char_t* of the array
         */
        axis2_status_t AXIS2_CALL
        adb_CollectionContentBean_set_collectionTypes_at(
                adb_CollectionContentBean_t* _CollectionContentBean,
                const axutil_env_t *env, int i,
                const axis2_char_t* arg_collectionTypes);


        /**
         * Add to collectionTypes.
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @param arg_collectionTypes element to add axis2_char_t* to the array
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CollectionContentBean_add_collectionTypes(
                adb_CollectionContentBean_t* _CollectionContentBean,
                const axutil_env_t *env,
                const axis2_char_t* arg_collectionTypes);

        /**
         * Get the size of the collectionTypes array.
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct.
         * @return the size of the collectionTypes array.
         */
        int AXIS2_CALL
        adb_CollectionContentBean_sizeof_collectionTypes(
                    adb_CollectionContentBean_t* _CollectionContentBean,
                    const axutil_env_t *env);

        /**
         * Remove the ith element of collectionTypes.
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @param i index of the item to remove
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CollectionContentBean_remove_collectionTypes_at(
                adb_CollectionContentBean_t* _CollectionContentBean,
                const axutil_env_t *env, int i);

        
        
        /**
         * Get the ith element of remoteInstances.
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @return ith axis2_char_t* of the array
         */
        axis2_char_t* AXIS2_CALL
        adb_CollectionContentBean_get_remoteInstances_at(
                adb_CollectionContentBean_t* _CollectionContentBean,
                const axutil_env_t *env, int i);

        /**
         * Set the ith element of remoteInstances. (If the ith already exist, it will be replaced)
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @param arg_remoteInstances element to set axis2_char_t* to the array
         * @return ith axis2_char_t* of the array
         */
        axis2_status_t AXIS2_CALL
        adb_CollectionContentBean_set_remoteInstances_at(
                adb_CollectionContentBean_t* _CollectionContentBean,
                const axutil_env_t *env, int i,
                const axis2_char_t* arg_remoteInstances);


        /**
         * Add to remoteInstances.
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @param arg_remoteInstances element to add axis2_char_t* to the array
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CollectionContentBean_add_remoteInstances(
                adb_CollectionContentBean_t* _CollectionContentBean,
                const axutil_env_t *env,
                const axis2_char_t* arg_remoteInstances);

        /**
         * Get the size of the remoteInstances array.
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct.
         * @return the size of the remoteInstances array.
         */
        int AXIS2_CALL
        adb_CollectionContentBean_sizeof_remoteInstances(
                    adb_CollectionContentBean_t* _CollectionContentBean,
                    const axutil_env_t *env);

        /**
         * Remove the ith element of remoteInstances.
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @param i index of the item to remove
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CollectionContentBean_remove_remoteInstances_at(
                adb_CollectionContentBean_t* _CollectionContentBean,
                const axutil_env_t *env, int i);

        


        /******************************* Checking and Setting NIL values *********************************/
        /* Use 'Checking and Setting NIL values for Arrays' to check and set nil for individual elements */

        /**
         * NOTE: set_nil is only available for nillable properties
         */

        

        /**
         * Check whether childCount is nill
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_CollectionContentBean_is_childCount_nil(
                adb_CollectionContentBean_t* _CollectionContentBean,
                const axutil_env_t *env);


        

        /**
         * Check whether childPaths is nill
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_CollectionContentBean_is_childPaths_nil(
                adb_CollectionContentBean_t* _CollectionContentBean,
                const axutil_env_t *env);


        
        /**
         * Set childPaths to nill (currently the same as reset)
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CollectionContentBean_set_childPaths_nil(
                adb_CollectionContentBean_t* _CollectionContentBean,
                const axutil_env_t *env);
        

        /**
         * Check whether collectionTypes is nill
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_CollectionContentBean_is_collectionTypes_nil(
                adb_CollectionContentBean_t* _CollectionContentBean,
                const axutil_env_t *env);


        
        /**
         * Set collectionTypes to nill (currently the same as reset)
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CollectionContentBean_set_collectionTypes_nil(
                adb_CollectionContentBean_t* _CollectionContentBean,
                const axutil_env_t *env);
        

        /**
         * Check whether pathWithVersion is nill
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_CollectionContentBean_is_pathWithVersion_nil(
                adb_CollectionContentBean_t* _CollectionContentBean,
                const axutil_env_t *env);


        
        /**
         * Set pathWithVersion to nill (currently the same as reset)
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CollectionContentBean_set_pathWithVersion_nil(
                adb_CollectionContentBean_t* _CollectionContentBean,
                const axutil_env_t *env);
        

        /**
         * Check whether remoteInstances is nill
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_CollectionContentBean_is_remoteInstances_nil(
                adb_CollectionContentBean_t* _CollectionContentBean,
                const axutil_env_t *env);


        
        /**
         * Set remoteInstances to nill (currently the same as reset)
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CollectionContentBean_set_remoteInstances_nil(
                adb_CollectionContentBean_t* _CollectionContentBean,
                const axutil_env_t *env);
        

        /**
         * Check whether versionView is nill
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_CollectionContentBean_is_versionView_nil(
                adb_CollectionContentBean_t* _CollectionContentBean,
                const axutil_env_t *env);


        
        /*************************** Checking and Setting 'NIL' values in Arrays *****************************/

        /**
         * NOTE: You may set this to remove specific elements in the array
         *       But you can not remove elements, if the specific property is declared to be non-nillable or sizeof(array) < minOccurs
         */
        
        /**
         * Check whether childPaths is nill at i
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct.
         * @param i index of the item to return.
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_CollectionContentBean_is_childPaths_nil_at(
                adb_CollectionContentBean_t* _CollectionContentBean,
                const axutil_env_t *env, int i);
 
       
        /**
         * Set childPaths to nill at i
         * @param  _CollectionContentBean _ adb_CollectionContentBean_t object
         * @param env pointer to environment struct.
         * @param i index of the item to set.
         * @return AXIS2_SUCCESS on success, or AXIS2_FAILURE otherwise.
         */
        axis2_status_t AXIS2_CALL
        adb_CollectionContentBean_set_childPaths_nil_at(
                adb_CollectionContentBean_t* _CollectionContentBean, 
                const axutil_env_t *env, int i);

        
        /**
         * Check whether collectionTypes is nill at i
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct.
         * @param i index of the item to return.
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_CollectionContentBean_is_collectionTypes_nil_at(
                adb_CollectionContentBean_t* _CollectionContentBean,
                const axutil_env_t *env, int i);
 
       
        /**
         * Set collectionTypes to nill at i
         * @param  _CollectionContentBean _ adb_CollectionContentBean_t object
         * @param env pointer to environment struct.
         * @param i index of the item to set.
         * @return AXIS2_SUCCESS on success, or AXIS2_FAILURE otherwise.
         */
        axis2_status_t AXIS2_CALL
        adb_CollectionContentBean_set_collectionTypes_nil_at(
                adb_CollectionContentBean_t* _CollectionContentBean, 
                const axutil_env_t *env, int i);

        
        /**
         * Check whether remoteInstances is nill at i
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct.
         * @param i index of the item to return.
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_CollectionContentBean_is_remoteInstances_nil_at(
                adb_CollectionContentBean_t* _CollectionContentBean,
                const axutil_env_t *env, int i);
 
       
        /**
         * Set remoteInstances to nill at i
         * @param  _CollectionContentBean _ adb_CollectionContentBean_t object
         * @param env pointer to environment struct.
         * @param i index of the item to set.
         * @return AXIS2_SUCCESS on success, or AXIS2_FAILURE otherwise.
         */
        axis2_status_t AXIS2_CALL
        adb_CollectionContentBean_set_remoteInstances_nil_at(
                adb_CollectionContentBean_t* _CollectionContentBean, 
                const axutil_env_t *env, int i);

        

        /**************************** Serialize and Deserialize functions ***************************/
        /*********** These functions are for use only inside the generated code *********************/

        
        /**
         * Wrapper for the deserialization function, will invoke the extension mapper instead
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs, 
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CollectionContentBean_deserialize(
            adb_CollectionContentBean_t* _CollectionContentBean,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);

        /**
         * Deserialize an XML to adb objects
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs,
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CollectionContentBean_deserialize_obj(
            adb_CollectionContentBean_t* _CollectionContentBean,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);
                            
            

       /**
         * Declare namespace in the most parent node 
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @param parent_element parent element
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index pointer to an int which contain the next namespace index
         */
       void AXIS2_CALL
       adb_CollectionContentBean_declare_parent_namespaces(
                    adb_CollectionContentBean_t* _CollectionContentBean,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index);

        

        /**
         * Wrapper for the serialization function, will invoke the extension mapper instead
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @param CollectionContentBean_om_node node to serialize from
         * @param CollectionContentBean_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_CollectionContentBean_serialize(
            adb_CollectionContentBean_t* _CollectionContentBean,
            const axutil_env_t *env,
            axiom_node_t* CollectionContentBean_om_node, axiom_element_t *CollectionContentBean_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Serialize to an XML from the adb objects
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @param CollectionContentBean_om_node node to serialize from
         * @param CollectionContentBean_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_CollectionContentBean_serialize_obj(
            adb_CollectionContentBean_t* _CollectionContentBean,
            const axutil_env_t *env,
            axiom_node_t* CollectionContentBean_om_node, axiom_element_t *CollectionContentBean_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Check whether the adb_CollectionContentBean is a particle class (E.g. group, inner sequence)
         * @return whether this is a particle class.
         */
        axis2_bool_t AXIS2_CALL
        adb_CollectionContentBean_is_particle();

        /******************************* Alternatives for Create and Free functions *********************************/

        

        /**
         * Constructor for creating adb_CollectionContentBean_t
         * @param env pointer to environment struct
         * @param _childCount int
         * @param _childPaths axutil_array_list_t*
         * @param _collectionTypes axutil_array_list_t*
         * @param _pathWithVersion axis2_char_t*
         * @param _remoteInstances axutil_array_list_t*
         * @param _versionView axis2_bool_t
         * @return newly created adb_CollectionContentBean_t object
         */
        adb_CollectionContentBean_t* AXIS2_CALL
        adb_CollectionContentBean_create_with_values(
            const axutil_env_t *env,
                int _childCount,
                axutil_array_list_t* _childPaths,
                axutil_array_list_t* _collectionTypes,
                axis2_char_t* _pathWithVersion,
                axutil_array_list_t* _remoteInstances,
                axis2_bool_t _versionView);

        


                /**
                 * Free adb_CollectionContentBean_t object and return the property value.
                 * You can use this to free the adb object as returning the property value. If there are
                 * many properties, it will only return the first property. Other properties will get freed with the adb object.
                 * @param  _CollectionContentBean adb_CollectionContentBean_t object to free
                 * @param env pointer to environment struct
                 * @return the property value holded by the ADB object, if there are many properties only returns the first.
                 */
                int AXIS2_CALL
                adb_CollectionContentBean_free_popping_value(
                        adb_CollectionContentBean_t* _CollectionContentBean,
                        const axutil_env_t *env);
            

        /******************************* get the value by the property number  *********************************/
        /************NOTE: This method is introduced to resolve a problem in unwrapping mode *******************/

        
        

        /**
         * Getter for childCount by property number (1)
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @return int
         */
        int AXIS2_CALL
        adb_CollectionContentBean_get_property1(
            adb_CollectionContentBean_t* _CollectionContentBean,
            const axutil_env_t *env);

    
        

        /**
         * Getter for childPaths by property number (2)
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @return Array of axis2_char_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_CollectionContentBean_get_property2(
            adb_CollectionContentBean_t* _CollectionContentBean,
            const axutil_env_t *env);

    
        

        /**
         * Getter for collectionTypes by property number (3)
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @return Array of axis2_char_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_CollectionContentBean_get_property3(
            adb_CollectionContentBean_t* _CollectionContentBean,
            const axutil_env_t *env);

    
        

        /**
         * Getter for pathWithVersion by property number (4)
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_CollectionContentBean_get_property4(
            adb_CollectionContentBean_t* _CollectionContentBean,
            const axutil_env_t *env);

    
        

        /**
         * Getter for remoteInstances by property number (5)
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @return Array of axis2_char_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_CollectionContentBean_get_property5(
            adb_CollectionContentBean_t* _CollectionContentBean,
            const axutil_env_t *env);

    
        

        /**
         * Getter for versionView by property number (6)
         * @param  _CollectionContentBean adb_CollectionContentBean_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_CollectionContentBean_get_property6(
            adb_CollectionContentBean_t* _CollectionContentBean,
            const axutil_env_t *env);

    
     #ifdef __cplusplus
     }
     #endif

     #endif /* ADB_COLLECTIONCONTENTBEAN_H */
    

