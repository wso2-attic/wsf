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


        #ifndef ADB_PERMISSIONBEAN_H
        #define ADB_PERMISSIONBEAN_H

       /**
        * adb_PermissionBean.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/Java version: #axisVersion# #today#
        */

       /**
        *  adb_PermissionBean class
        */

        
          #include "adb_PermissionEntry.h"
          
          #include "adb_PermissionEntry.h"
          

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
        

        typedef struct adb_PermissionBean adb_PermissionBean_t;

        
        

        /******************************* Create and Free functions *********************************/

        /**
         * Constructor for creating adb_PermissionBean_t
         * @param env pointer to environment struct
         * @return newly created adb_PermissionBean_t object
         */
        adb_PermissionBean_t* AXIS2_CALL
        adb_PermissionBean_create(
            const axutil_env_t *env );

        /**
         * Wrapper for the "free" function, will invoke the extension mapper instead
         * @param  _PermissionBean adb_PermissionBean_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_free (
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env);

        /**
         * Free adb_PermissionBean_t object
         * @param  _PermissionBean adb_PermissionBean_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_free_obj (
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env);



        /********************************** Getters and Setters **************************************/
        /******** Deprecated for array types, Use 'Getters and Setters for Arrays' instead ***********/
        

        /**
         * Getter for authorizeAllowed. 
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionBean_get_authorizeAllowed(
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env);

        /**
         * Setter for authorizeAllowed.
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @param arg_authorizeAllowed axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_set_authorizeAllowed(
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env,
            axis2_bool_t  arg_authorizeAllowed);

        /**
         * Resetter for authorizeAllowed
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_reset_authorizeAllowed(
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env);

        
        

        /**
         * Getter for deleteAllowed. 
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionBean_get_deleteAllowed(
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env);

        /**
         * Setter for deleteAllowed.
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @param arg_deleteAllowed axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_set_deleteAllowed(
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env,
            axis2_bool_t  arg_deleteAllowed);

        /**
         * Resetter for deleteAllowed
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_reset_deleteAllowed(
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env);

        
        

        /**
         * Getter for pathWithVersion. 
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_PermissionBean_get_pathWithVersion(
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env);

        /**
         * Setter for pathWithVersion.
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @param arg_pathWithVersion axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_set_pathWithVersion(
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env,
            const axis2_char_t*  arg_pathWithVersion);

        /**
         * Resetter for pathWithVersion
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_reset_pathWithVersion(
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env);

        
        

        /**
         * Getter for putAllowed. 
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionBean_get_putAllowed(
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env);

        /**
         * Setter for putAllowed.
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @param arg_putAllowed axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_set_putAllowed(
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env,
            axis2_bool_t  arg_putAllowed);

        /**
         * Resetter for putAllowed
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_reset_putAllowed(
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env);

        
        

        /**
         * Getter for roleNames. Deprecated for array types, Use adb_PermissionBean_get_roleNames_at instead
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return Array of axis2_char_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_PermissionBean_get_roleNames(
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env);

        /**
         * Setter for roleNames.Deprecated for array types, Use adb_PermissionBean_set_roleNames_at
         * or adb_PermissionBean_add_roleNames instead.
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @param arg_roleNames Array of axis2_char_t*s.
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_set_roleNames(
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env,
            axutil_array_list_t*  arg_roleNames);

        /**
         * Resetter for roleNames
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_reset_roleNames(
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env);

        
        

        /**
         * Getter for rolePermissions. Deprecated for array types, Use adb_PermissionBean_get_rolePermissions_at instead
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return Array of adb_PermissionEntry_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_PermissionBean_get_rolePermissions(
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env);

        /**
         * Setter for rolePermissions.Deprecated for array types, Use adb_PermissionBean_set_rolePermissions_at
         * or adb_PermissionBean_add_rolePermissions instead.
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @param arg_rolePermissions Array of adb_PermissionEntry_t*s.
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_set_rolePermissions(
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env,
            axutil_array_list_t*  arg_rolePermissions);

        /**
         * Resetter for rolePermissions
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_reset_rolePermissions(
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env);

        
        

        /**
         * Getter for userNames. Deprecated for array types, Use adb_PermissionBean_get_userNames_at instead
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return Array of axis2_char_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_PermissionBean_get_userNames(
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env);

        /**
         * Setter for userNames.Deprecated for array types, Use adb_PermissionBean_set_userNames_at
         * or adb_PermissionBean_add_userNames instead.
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @param arg_userNames Array of axis2_char_t*s.
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_set_userNames(
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env,
            axutil_array_list_t*  arg_userNames);

        /**
         * Resetter for userNames
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_reset_userNames(
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env);

        
        

        /**
         * Getter for userPermissions. Deprecated for array types, Use adb_PermissionBean_get_userPermissions_at instead
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return Array of adb_PermissionEntry_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_PermissionBean_get_userPermissions(
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env);

        /**
         * Setter for userPermissions.Deprecated for array types, Use adb_PermissionBean_set_userPermissions_at
         * or adb_PermissionBean_add_userPermissions instead.
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @param arg_userPermissions Array of adb_PermissionEntry_t*s.
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_set_userPermissions(
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env,
            axutil_array_list_t*  arg_userPermissions);

        /**
         * Resetter for userPermissions
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_reset_userPermissions(
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env);

        
        

        /**
         * Getter for versionView. 
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionBean_get_versionView(
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env);

        /**
         * Setter for versionView.
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @param arg_versionView axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_set_versionView(
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env,
            axis2_bool_t  arg_versionView);

        /**
         * Resetter for versionView
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_reset_versionView(
            adb_PermissionBean_t* _PermissionBean,
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
         * Get the ith element of roleNames.
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @return ith axis2_char_t* of the array
         */
        axis2_char_t* AXIS2_CALL
        adb_PermissionBean_get_roleNames_at(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env, int i);

        /**
         * Set the ith element of roleNames. (If the ith already exist, it will be replaced)
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @param arg_roleNames element to set axis2_char_t* to the array
         * @return ith axis2_char_t* of the array
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_set_roleNames_at(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env, int i,
                const axis2_char_t* arg_roleNames);


        /**
         * Add to roleNames.
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @param arg_roleNames element to add axis2_char_t* to the array
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_add_roleNames(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env,
                const axis2_char_t* arg_roleNames);

        /**
         * Get the size of the roleNames array.
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct.
         * @return the size of the roleNames array.
         */
        int AXIS2_CALL
        adb_PermissionBean_sizeof_roleNames(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env);

        /**
         * Remove the ith element of roleNames.
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @param i index of the item to remove
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_remove_roleNames_at(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env, int i);

        
        
        /**
         * Get the ith element of rolePermissions.
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @return ith adb_PermissionEntry_t* of the array
         */
        adb_PermissionEntry_t* AXIS2_CALL
        adb_PermissionBean_get_rolePermissions_at(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env, int i);

        /**
         * Set the ith element of rolePermissions. (If the ith already exist, it will be replaced)
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @param arg_rolePermissions element to set adb_PermissionEntry_t* to the array
         * @return ith adb_PermissionEntry_t* of the array
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_set_rolePermissions_at(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env, int i,
                adb_PermissionEntry_t* arg_rolePermissions);


        /**
         * Add to rolePermissions.
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @param arg_rolePermissions element to add adb_PermissionEntry_t* to the array
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_add_rolePermissions(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env,
                adb_PermissionEntry_t* arg_rolePermissions);

        /**
         * Get the size of the rolePermissions array.
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct.
         * @return the size of the rolePermissions array.
         */
        int AXIS2_CALL
        adb_PermissionBean_sizeof_rolePermissions(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env);

        /**
         * Remove the ith element of rolePermissions.
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @param i index of the item to remove
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_remove_rolePermissions_at(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env, int i);

        
        
        /**
         * Get the ith element of userNames.
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @return ith axis2_char_t* of the array
         */
        axis2_char_t* AXIS2_CALL
        adb_PermissionBean_get_userNames_at(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env, int i);

        /**
         * Set the ith element of userNames. (If the ith already exist, it will be replaced)
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @param arg_userNames element to set axis2_char_t* to the array
         * @return ith axis2_char_t* of the array
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_set_userNames_at(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env, int i,
                const axis2_char_t* arg_userNames);


        /**
         * Add to userNames.
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @param arg_userNames element to add axis2_char_t* to the array
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_add_userNames(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env,
                const axis2_char_t* arg_userNames);

        /**
         * Get the size of the userNames array.
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct.
         * @return the size of the userNames array.
         */
        int AXIS2_CALL
        adb_PermissionBean_sizeof_userNames(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env);

        /**
         * Remove the ith element of userNames.
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @param i index of the item to remove
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_remove_userNames_at(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env, int i);

        
        
        /**
         * Get the ith element of userPermissions.
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @return ith adb_PermissionEntry_t* of the array
         */
        adb_PermissionEntry_t* AXIS2_CALL
        adb_PermissionBean_get_userPermissions_at(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env, int i);

        /**
         * Set the ith element of userPermissions. (If the ith already exist, it will be replaced)
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @param arg_userPermissions element to set adb_PermissionEntry_t* to the array
         * @return ith adb_PermissionEntry_t* of the array
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_set_userPermissions_at(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env, int i,
                adb_PermissionEntry_t* arg_userPermissions);


        /**
         * Add to userPermissions.
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @param arg_userPermissions element to add adb_PermissionEntry_t* to the array
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_add_userPermissions(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env,
                adb_PermissionEntry_t* arg_userPermissions);

        /**
         * Get the size of the userPermissions array.
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct.
         * @return the size of the userPermissions array.
         */
        int AXIS2_CALL
        adb_PermissionBean_sizeof_userPermissions(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env);

        /**
         * Remove the ith element of userPermissions.
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @param i index of the item to remove
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_remove_userPermissions_at(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env, int i);

        


        /******************************* Checking and Setting NIL values *********************************/
        /* Use 'Checking and Setting NIL values for Arrays' to check and set nil for individual elements */

        /**
         * NOTE: set_nil is only available for nillable properties
         */

        

        /**
         * Check whether authorizeAllowed is nill
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionBean_is_authorizeAllowed_nil(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env);


        

        /**
         * Check whether deleteAllowed is nill
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionBean_is_deleteAllowed_nil(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env);


        

        /**
         * Check whether pathWithVersion is nill
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionBean_is_pathWithVersion_nil(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env);


        
        /**
         * Set pathWithVersion to nill (currently the same as reset)
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_set_pathWithVersion_nil(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env);
        

        /**
         * Check whether putAllowed is nill
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionBean_is_putAllowed_nil(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env);


        

        /**
         * Check whether roleNames is nill
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionBean_is_roleNames_nil(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env);


        
        /**
         * Set roleNames to nill (currently the same as reset)
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_set_roleNames_nil(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env);
        

        /**
         * Check whether rolePermissions is nill
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionBean_is_rolePermissions_nil(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env);


        
        /**
         * Set rolePermissions to nill (currently the same as reset)
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_set_rolePermissions_nil(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env);
        

        /**
         * Check whether userNames is nill
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionBean_is_userNames_nil(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env);


        
        /**
         * Set userNames to nill (currently the same as reset)
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_set_userNames_nil(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env);
        

        /**
         * Check whether userPermissions is nill
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionBean_is_userPermissions_nil(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env);


        
        /**
         * Set userPermissions to nill (currently the same as reset)
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_set_userPermissions_nil(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env);
        

        /**
         * Check whether versionView is nill
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionBean_is_versionView_nil(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env);


        
        /*************************** Checking and Setting 'NIL' values in Arrays *****************************/

        /**
         * NOTE: You may set this to remove specific elements in the array
         *       But you can not remove elements, if the specific property is declared to be non-nillable or sizeof(array) < minOccurs
         */
        
        /**
         * Check whether roleNames is nill at i
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct.
         * @param i index of the item to return.
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionBean_is_roleNames_nil_at(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env, int i);
 
       
        /**
         * Set roleNames to nill at i
         * @param  _PermissionBean _ adb_PermissionBean_t object
         * @param env pointer to environment struct.
         * @param i index of the item to set.
         * @return AXIS2_SUCCESS on success, or AXIS2_FAILURE otherwise.
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_set_roleNames_nil_at(
                adb_PermissionBean_t* _PermissionBean, 
                const axutil_env_t *env, int i);

        
        /**
         * Check whether rolePermissions is nill at i
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct.
         * @param i index of the item to return.
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionBean_is_rolePermissions_nil_at(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env, int i);
 
       
        /**
         * Set rolePermissions to nill at i
         * @param  _PermissionBean _ adb_PermissionBean_t object
         * @param env pointer to environment struct.
         * @param i index of the item to set.
         * @return AXIS2_SUCCESS on success, or AXIS2_FAILURE otherwise.
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_set_rolePermissions_nil_at(
                adb_PermissionBean_t* _PermissionBean, 
                const axutil_env_t *env, int i);

        
        /**
         * Check whether userNames is nill at i
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct.
         * @param i index of the item to return.
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionBean_is_userNames_nil_at(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env, int i);
 
       
        /**
         * Set userNames to nill at i
         * @param  _PermissionBean _ adb_PermissionBean_t object
         * @param env pointer to environment struct.
         * @param i index of the item to set.
         * @return AXIS2_SUCCESS on success, or AXIS2_FAILURE otherwise.
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_set_userNames_nil_at(
                adb_PermissionBean_t* _PermissionBean, 
                const axutil_env_t *env, int i);

        
        /**
         * Check whether userPermissions is nill at i
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct.
         * @param i index of the item to return.
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionBean_is_userPermissions_nil_at(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env, int i);
 
       
        /**
         * Set userPermissions to nill at i
         * @param  _PermissionBean _ adb_PermissionBean_t object
         * @param env pointer to environment struct.
         * @param i index of the item to set.
         * @return AXIS2_SUCCESS on success, or AXIS2_FAILURE otherwise.
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_set_userPermissions_nil_at(
                adb_PermissionBean_t* _PermissionBean, 
                const axutil_env_t *env, int i);

        

        /**************************** Serialize and Deserialize functions ***************************/
        /*********** These functions are for use only inside the generated code *********************/

        
        /**
         * Wrapper for the deserialization function, will invoke the extension mapper instead
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs, 
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_deserialize(
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);

        /**
         * Deserialize an XML to adb objects
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs,
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionBean_deserialize_obj(
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);
                            
            

       /**
         * Declare namespace in the most parent node 
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @param parent_element parent element
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index pointer to an int which contain the next namespace index
         */
       void AXIS2_CALL
       adb_PermissionBean_declare_parent_namespaces(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index);

        

        /**
         * Wrapper for the serialization function, will invoke the extension mapper instead
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @param PermissionBean_om_node node to serialize from
         * @param PermissionBean_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_PermissionBean_serialize(
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env,
            axiom_node_t* PermissionBean_om_node, axiom_element_t *PermissionBean_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Serialize to an XML from the adb objects
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @param PermissionBean_om_node node to serialize from
         * @param PermissionBean_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_PermissionBean_serialize_obj(
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env,
            axiom_node_t* PermissionBean_om_node, axiom_element_t *PermissionBean_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Check whether the adb_PermissionBean is a particle class (E.g. group, inner sequence)
         * @return whether this is a particle class.
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionBean_is_particle();

        /******************************* Alternatives for Create and Free functions *********************************/

        

        /**
         * Constructor for creating adb_PermissionBean_t
         * @param env pointer to environment struct
         * @param _authorizeAllowed axis2_bool_t
         * @param _deleteAllowed axis2_bool_t
         * @param _pathWithVersion axis2_char_t*
         * @param _putAllowed axis2_bool_t
         * @param _roleNames axutil_array_list_t*
         * @param _rolePermissions axutil_array_list_t*
         * @param _userNames axutil_array_list_t*
         * @param _userPermissions axutil_array_list_t*
         * @param _versionView axis2_bool_t
         * @return newly created adb_PermissionBean_t object
         */
        adb_PermissionBean_t* AXIS2_CALL
        adb_PermissionBean_create_with_values(
            const axutil_env_t *env,
                axis2_bool_t _authorizeAllowed,
                axis2_bool_t _deleteAllowed,
                axis2_char_t* _pathWithVersion,
                axis2_bool_t _putAllowed,
                axutil_array_list_t* _roleNames,
                axutil_array_list_t* _rolePermissions,
                axutil_array_list_t* _userNames,
                axutil_array_list_t* _userPermissions,
                axis2_bool_t _versionView);

        


                /**
                 * Free adb_PermissionBean_t object and return the property value.
                 * You can use this to free the adb object as returning the property value. If there are
                 * many properties, it will only return the first property. Other properties will get freed with the adb object.
                 * @param  _PermissionBean adb_PermissionBean_t object to free
                 * @param env pointer to environment struct
                 * @return the property value holded by the ADB object, if there are many properties only returns the first.
                 */
                axis2_bool_t AXIS2_CALL
                adb_PermissionBean_free_popping_value(
                        adb_PermissionBean_t* _PermissionBean,
                        const axutil_env_t *env);
            

        /******************************* get the value by the property number  *********************************/
        /************NOTE: This method is introduced to resolve a problem in unwrapping mode *******************/

        
        

        /**
         * Getter for authorizeAllowed by property number (1)
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionBean_get_property1(
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env);

    
        

        /**
         * Getter for deleteAllowed by property number (2)
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionBean_get_property2(
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env);

    
        

        /**
         * Getter for pathWithVersion by property number (3)
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_PermissionBean_get_property3(
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env);

    
        

        /**
         * Getter for putAllowed by property number (4)
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionBean_get_property4(
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env);

    
        

        /**
         * Getter for roleNames by property number (5)
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return Array of axis2_char_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_PermissionBean_get_property5(
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env);

    
        

        /**
         * Getter for rolePermissions by property number (6)
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return Array of adb_PermissionEntry_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_PermissionBean_get_property6(
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env);

    
        

        /**
         * Getter for userNames by property number (7)
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return Array of axis2_char_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_PermissionBean_get_property7(
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env);

    
        

        /**
         * Getter for userPermissions by property number (8)
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return Array of adb_PermissionEntry_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_PermissionBean_get_property8(
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env);

    
        

        /**
         * Getter for versionView by property number (9)
         * @param  _PermissionBean adb_PermissionBean_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionBean_get_property9(
            adb_PermissionBean_t* _PermissionBean,
            const axutil_env_t *env);

    
     #ifdef __cplusplus
     }
     #endif

     #endif /* ADB_PERMISSIONBEAN_H */
    

