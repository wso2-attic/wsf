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


        #ifndef ADB_RESOURCEDATA_H
        #define ADB_RESOURCEDATA_H

       /**
        * adb_ResourceData.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/Java version: #axisVersion# #today#
        */

       /**
        *  adb_ResourceData class
        */

        
          #include "adb_TagCount.h"
          
            #include <axutil_date_time.h>
          

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
        

        typedef struct adb_ResourceData adb_ResourceData_t;

        
        

        /******************************* Create and Free functions *********************************/

        /**
         * Constructor for creating adb_ResourceData_t
         * @param env pointer to environment struct
         * @return newly created adb_ResourceData_t object
         */
        adb_ResourceData_t* AXIS2_CALL
        adb_ResourceData_create(
            const axutil_env_t *env );

        /**
         * Wrapper for the "free" function, will invoke the extension mapper instead
         * @param  _ResourceData adb_ResourceData_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_free (
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

        /**
         * Free adb_ResourceData_t object
         * @param  _ResourceData adb_ResourceData_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_free_obj (
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);



        /********************************** Getters and Setters **************************************/
        /******** Deprecated for array types, Use 'Getters and Setters for Arrays' instead ***********/
        

        /**
         * Getter for absent. 
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ResourceData_get_absent(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

        /**
         * Setter for absent.
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @param arg_absent axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_set_absent(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_absent);

        /**
         * Resetter for absent
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_reset_absent(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for authorUserName. 
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ResourceData_get_authorUserName(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

        /**
         * Setter for authorUserName.
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @param arg_authorUserName axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_set_authorUserName(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_authorUserName);

        /**
         * Resetter for authorUserName
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_reset_authorUserName(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for averageRating. 
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return float
         */
        float AXIS2_CALL
        adb_ResourceData_get_averageRating(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

        /**
         * Setter for averageRating.
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @param arg_averageRating float
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_set_averageRating(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env,
            const float  arg_averageRating);

        /**
         * Resetter for averageRating
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_reset_averageRating(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for averageStars. Deprecated for array types, Use adb_ResourceData_get_averageStars_at instead
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return Array of axis2_char_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_ResourceData_get_averageStars(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

        /**
         * Setter for averageStars.Deprecated for array types, Use adb_ResourceData_set_averageStars_at
         * or adb_ResourceData_add_averageStars instead.
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @param arg_averageStars Array of axis2_char_t*s.
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_set_averageStars(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env,
            axutil_array_list_t*  arg_averageStars);

        /**
         * Resetter for averageStars
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_reset_averageStars(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for createdOn. 
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return axutil_date_time_t*
         */
        axutil_date_time_t* AXIS2_CALL
        adb_ResourceData_get_createdOn(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

        /**
         * Setter for createdOn.
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @param arg_createdOn axutil_date_time_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_set_createdOn(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env,
            axutil_date_time_t*  arg_createdOn);

        /**
         * Resetter for createdOn
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_reset_createdOn(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for deleteAllowed. 
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_ResourceData_get_deleteAllowed(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

        /**
         * Setter for deleteAllowed.
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @param arg_deleteAllowed axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_set_deleteAllowed(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env,
            axis2_bool_t  arg_deleteAllowed);

        /**
         * Resetter for deleteAllowed
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_reset_deleteAllowed(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for description. 
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ResourceData_get_description(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

        /**
         * Setter for description.
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @param arg_description axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_set_description(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_description);

        /**
         * Resetter for description
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_reset_description(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for externalLink. 
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_ResourceData_get_externalLink(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

        /**
         * Setter for externalLink.
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @param arg_externalLink axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_set_externalLink(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env,
            axis2_bool_t  arg_externalLink);

        /**
         * Resetter for externalLink
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_reset_externalLink(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for formattedCreatedOn. 
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ResourceData_get_formattedCreatedOn(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

        /**
         * Setter for formattedCreatedOn.
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @param arg_formattedCreatedOn axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_set_formattedCreatedOn(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_formattedCreatedOn);

        /**
         * Resetter for formattedCreatedOn
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_reset_formattedCreatedOn(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for getAllowed. 
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_ResourceData_get_getAllowed(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

        /**
         * Setter for getAllowed.
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @param arg_getAllowed axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_set_getAllowed(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env,
            axis2_bool_t  arg_getAllowed);

        /**
         * Resetter for getAllowed
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_reset_getAllowed(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for link. 
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_ResourceData_get_link(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

        /**
         * Setter for link.
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @param arg_link axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_set_link(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env,
            axis2_bool_t  arg_link);

        /**
         * Resetter for link
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_reset_link(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for mounted. 
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_ResourceData_get_mounted(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

        /**
         * Setter for mounted.
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @param arg_mounted axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_set_mounted(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env,
            axis2_bool_t  arg_mounted);

        /**
         * Resetter for mounted
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_reset_mounted(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for name. 
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ResourceData_get_name(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

        /**
         * Setter for name.
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @param arg_name axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_set_name(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_name);

        /**
         * Resetter for name
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_reset_name(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for putAllowed. 
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_ResourceData_get_putAllowed(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

        /**
         * Setter for putAllowed.
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @param arg_putAllowed axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_set_putAllowed(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env,
            axis2_bool_t  arg_putAllowed);

        /**
         * Resetter for putAllowed
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_reset_putAllowed(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for realPath. 
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ResourceData_get_realPath(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

        /**
         * Setter for realPath.
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @param arg_realPath axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_set_realPath(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_realPath);

        /**
         * Resetter for realPath
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_reset_realPath(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for relativePath. 
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ResourceData_get_relativePath(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

        /**
         * Setter for relativePath.
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @param arg_relativePath axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_set_relativePath(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_relativePath);

        /**
         * Resetter for relativePath
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_reset_relativePath(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for resourcePath. 
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ResourceData_get_resourcePath(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

        /**
         * Setter for resourcePath.
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @param arg_resourcePath axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_set_resourcePath(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_resourcePath);

        /**
         * Resetter for resourcePath
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_reset_resourcePath(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for resourceType. 
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ResourceData_get_resourceType(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

        /**
         * Setter for resourceType.
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @param arg_resourceType axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_set_resourceType(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_resourceType);

        /**
         * Resetter for resourceType
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_reset_resourceType(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for tagCounts. Deprecated for array types, Use adb_ResourceData_get_tagCounts_at instead
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return Array of adb_TagCount_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_ResourceData_get_tagCounts(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

        /**
         * Setter for tagCounts.Deprecated for array types, Use adb_ResourceData_set_tagCounts_at
         * or adb_ResourceData_add_tagCounts instead.
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @param arg_tagCounts Array of adb_TagCount_t*s.
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_set_tagCounts(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env,
            axutil_array_list_t*  arg_tagCounts);

        /**
         * Resetter for tagCounts
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_reset_tagCounts(
            adb_ResourceData_t* _ResourceData,
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
         * Get the ith element of averageStars.
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @return ith axis2_char_t* of the array
         */
        axis2_char_t* AXIS2_CALL
        adb_ResourceData_get_averageStars_at(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env, int i);

        /**
         * Set the ith element of averageStars. (If the ith already exist, it will be replaced)
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @param arg_averageStars element to set axis2_char_t* to the array
         * @return ith axis2_char_t* of the array
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_set_averageStars_at(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env, int i,
                const axis2_char_t* arg_averageStars);


        /**
         * Add to averageStars.
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @param arg_averageStars element to add axis2_char_t* to the array
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_add_averageStars(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env,
                const axis2_char_t* arg_averageStars);

        /**
         * Get the size of the averageStars array.
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct.
         * @return the size of the averageStars array.
         */
        int AXIS2_CALL
        adb_ResourceData_sizeof_averageStars(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env);

        /**
         * Remove the ith element of averageStars.
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @param i index of the item to remove
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_remove_averageStars_at(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env, int i);

        
        
        /**
         * Get the ith element of tagCounts.
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @return ith adb_TagCount_t* of the array
         */
        adb_TagCount_t* AXIS2_CALL
        adb_ResourceData_get_tagCounts_at(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env, int i);

        /**
         * Set the ith element of tagCounts. (If the ith already exist, it will be replaced)
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @param arg_tagCounts element to set adb_TagCount_t* to the array
         * @return ith adb_TagCount_t* of the array
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_set_tagCounts_at(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env, int i,
                adb_TagCount_t* arg_tagCounts);


        /**
         * Add to tagCounts.
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @param arg_tagCounts element to add adb_TagCount_t* to the array
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_add_tagCounts(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env,
                adb_TagCount_t* arg_tagCounts);

        /**
         * Get the size of the tagCounts array.
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct.
         * @return the size of the tagCounts array.
         */
        int AXIS2_CALL
        adb_ResourceData_sizeof_tagCounts(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env);

        /**
         * Remove the ith element of tagCounts.
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @param i index of the item to remove
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_remove_tagCounts_at(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env, int i);

        


        /******************************* Checking and Setting NIL values *********************************/
        /* Use 'Checking and Setting NIL values for Arrays' to check and set nil for individual elements */

        /**
         * NOTE: set_nil is only available for nillable properties
         */

        

        /**
         * Check whether absent is nill
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ResourceData_is_absent_nil(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env);


        
        /**
         * Set absent to nill (currently the same as reset)
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_set_absent_nil(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env);
        

        /**
         * Check whether authorUserName is nill
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ResourceData_is_authorUserName_nil(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env);


        
        /**
         * Set authorUserName to nill (currently the same as reset)
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_set_authorUserName_nil(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env);
        

        /**
         * Check whether averageRating is nill
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ResourceData_is_averageRating_nil(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env);


        

        /**
         * Check whether averageStars is nill
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ResourceData_is_averageStars_nil(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env);


        
        /**
         * Set averageStars to nill (currently the same as reset)
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_set_averageStars_nil(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env);
        

        /**
         * Check whether createdOn is nill
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ResourceData_is_createdOn_nil(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env);


        
        /**
         * Set createdOn to nill (currently the same as reset)
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_set_createdOn_nil(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env);
        

        /**
         * Check whether deleteAllowed is nill
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ResourceData_is_deleteAllowed_nil(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env);


        

        /**
         * Check whether description is nill
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ResourceData_is_description_nil(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env);


        
        /**
         * Set description to nill (currently the same as reset)
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_set_description_nil(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env);
        

        /**
         * Check whether externalLink is nill
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ResourceData_is_externalLink_nil(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env);


        

        /**
         * Check whether formattedCreatedOn is nill
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ResourceData_is_formattedCreatedOn_nil(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env);


        
        /**
         * Set formattedCreatedOn to nill (currently the same as reset)
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_set_formattedCreatedOn_nil(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env);
        

        /**
         * Check whether getAllowed is nill
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ResourceData_is_getAllowed_nil(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env);


        

        /**
         * Check whether link is nill
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ResourceData_is_link_nil(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env);


        

        /**
         * Check whether mounted is nill
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ResourceData_is_mounted_nil(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env);


        

        /**
         * Check whether name is nill
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ResourceData_is_name_nil(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env);


        
        /**
         * Set name to nill (currently the same as reset)
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_set_name_nil(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env);
        

        /**
         * Check whether putAllowed is nill
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ResourceData_is_putAllowed_nil(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env);


        

        /**
         * Check whether realPath is nill
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ResourceData_is_realPath_nil(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env);


        
        /**
         * Set realPath to nill (currently the same as reset)
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_set_realPath_nil(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env);
        

        /**
         * Check whether relativePath is nill
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ResourceData_is_relativePath_nil(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env);


        
        /**
         * Set relativePath to nill (currently the same as reset)
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_set_relativePath_nil(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env);
        

        /**
         * Check whether resourcePath is nill
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ResourceData_is_resourcePath_nil(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env);


        
        /**
         * Set resourcePath to nill (currently the same as reset)
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_set_resourcePath_nil(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env);
        

        /**
         * Check whether resourceType is nill
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ResourceData_is_resourceType_nil(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env);


        
        /**
         * Set resourceType to nill (currently the same as reset)
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_set_resourceType_nil(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env);
        

        /**
         * Check whether tagCounts is nill
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ResourceData_is_tagCounts_nil(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env);


        
        /**
         * Set tagCounts to nill (currently the same as reset)
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_set_tagCounts_nil(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env);
        
        /*************************** Checking and Setting 'NIL' values in Arrays *****************************/

        /**
         * NOTE: You may set this to remove specific elements in the array
         *       But you can not remove elements, if the specific property is declared to be non-nillable or sizeof(array) < minOccurs
         */
        
        /**
         * Check whether averageStars is nill at i
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct.
         * @param i index of the item to return.
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ResourceData_is_averageStars_nil_at(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env, int i);
 
       
        /**
         * Set averageStars to nill at i
         * @param  _ResourceData _ adb_ResourceData_t object
         * @param env pointer to environment struct.
         * @param i index of the item to set.
         * @return AXIS2_SUCCESS on success, or AXIS2_FAILURE otherwise.
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_set_averageStars_nil_at(
                adb_ResourceData_t* _ResourceData, 
                const axutil_env_t *env, int i);

        
        /**
         * Check whether tagCounts is nill at i
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct.
         * @param i index of the item to return.
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ResourceData_is_tagCounts_nil_at(
                adb_ResourceData_t* _ResourceData,
                const axutil_env_t *env, int i);
 
       
        /**
         * Set tagCounts to nill at i
         * @param  _ResourceData _ adb_ResourceData_t object
         * @param env pointer to environment struct.
         * @param i index of the item to set.
         * @return AXIS2_SUCCESS on success, or AXIS2_FAILURE otherwise.
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_set_tagCounts_nil_at(
                adb_ResourceData_t* _ResourceData, 
                const axutil_env_t *env, int i);

        

        /**************************** Serialize and Deserialize functions ***************************/
        /*********** These functions are for use only inside the generated code *********************/

        
        /**
         * Wrapper for the deserialization function, will invoke the extension mapper instead
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs, 
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_deserialize(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);

        /**
         * Deserialize an XML to adb objects
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs,
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ResourceData_deserialize_obj(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);
                            
            

       /**
         * Declare namespace in the most parent node 
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @param parent_element parent element
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index pointer to an int which contain the next namespace index
         */
       void AXIS2_CALL
       adb_ResourceData_declare_parent_namespaces(
                    adb_ResourceData_t* _ResourceData,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index);

        

        /**
         * Wrapper for the serialization function, will invoke the extension mapper instead
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @param ResourceData_om_node node to serialize from
         * @param ResourceData_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_ResourceData_serialize(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env,
            axiom_node_t* ResourceData_om_node, axiom_element_t *ResourceData_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Serialize to an XML from the adb objects
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @param ResourceData_om_node node to serialize from
         * @param ResourceData_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_ResourceData_serialize_obj(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env,
            axiom_node_t* ResourceData_om_node, axiom_element_t *ResourceData_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Check whether the adb_ResourceData is a particle class (E.g. group, inner sequence)
         * @return whether this is a particle class.
         */
        axis2_bool_t AXIS2_CALL
        adb_ResourceData_is_particle();

        /******************************* Alternatives for Create and Free functions *********************************/

        

        /**
         * Constructor for creating adb_ResourceData_t
         * @param env pointer to environment struct
         * @param _absent axis2_char_t*
         * @param _authorUserName axis2_char_t*
         * @param _averageRating float
         * @param _averageStars axutil_array_list_t*
         * @param _createdOn axutil_date_time_t*
         * @param _deleteAllowed axis2_bool_t
         * @param _description axis2_char_t*
         * @param _externalLink axis2_bool_t
         * @param _formattedCreatedOn axis2_char_t*
         * @param _getAllowed axis2_bool_t
         * @param _link axis2_bool_t
         * @param _mounted axis2_bool_t
         * @param _name axis2_char_t*
         * @param _putAllowed axis2_bool_t
         * @param _realPath axis2_char_t*
         * @param _relativePath axis2_char_t*
         * @param _resourcePath axis2_char_t*
         * @param _resourceType axis2_char_t*
         * @param _tagCounts axutil_array_list_t*
         * @return newly created adb_ResourceData_t object
         */
        adb_ResourceData_t* AXIS2_CALL
        adb_ResourceData_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _absent,
                axis2_char_t* _authorUserName,
                float _averageRating,
                axutil_array_list_t* _averageStars,
                axutil_date_time_t* _createdOn,
                axis2_bool_t _deleteAllowed,
                axis2_char_t* _description,
                axis2_bool_t _externalLink,
                axis2_char_t* _formattedCreatedOn,
                axis2_bool_t _getAllowed,
                axis2_bool_t _link,
                axis2_bool_t _mounted,
                axis2_char_t* _name,
                axis2_bool_t _putAllowed,
                axis2_char_t* _realPath,
                axis2_char_t* _relativePath,
                axis2_char_t* _resourcePath,
                axis2_char_t* _resourceType,
                axutil_array_list_t* _tagCounts);

        


                /**
                 * Free adb_ResourceData_t object and return the property value.
                 * You can use this to free the adb object as returning the property value. If there are
                 * many properties, it will only return the first property. Other properties will get freed with the adb object.
                 * @param  _ResourceData adb_ResourceData_t object to free
                 * @param env pointer to environment struct
                 * @return the property value holded by the ADB object, if there are many properties only returns the first.
                 */
                axis2_char_t* AXIS2_CALL
                adb_ResourceData_free_popping_value(
                        adb_ResourceData_t* _ResourceData,
                        const axutil_env_t *env);
            

        /******************************* get the value by the property number  *********************************/
        /************NOTE: This method is introduced to resolve a problem in unwrapping mode *******************/

        
        

        /**
         * Getter for absent by property number (1)
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ResourceData_get_property1(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for authorUserName by property number (2)
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ResourceData_get_property2(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for averageRating by property number (3)
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return float
         */
        float AXIS2_CALL
        adb_ResourceData_get_property3(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for averageStars by property number (4)
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return Array of axis2_char_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_ResourceData_get_property4(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for createdOn by property number (5)
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return axutil_date_time_t*
         */
        axutil_date_time_t* AXIS2_CALL
        adb_ResourceData_get_property5(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for deleteAllowed by property number (6)
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_ResourceData_get_property6(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for description by property number (7)
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ResourceData_get_property7(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for externalLink by property number (8)
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_ResourceData_get_property8(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for formattedCreatedOn by property number (9)
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ResourceData_get_property9(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for getAllowed by property number (10)
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_ResourceData_get_property10(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for link by property number (11)
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_ResourceData_get_property11(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for mounted by property number (12)
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_ResourceData_get_property12(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for name by property number (13)
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ResourceData_get_property13(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for putAllowed by property number (14)
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_ResourceData_get_property14(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for realPath by property number (15)
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ResourceData_get_property15(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for relativePath by property number (16)
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ResourceData_get_property16(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for resourcePath by property number (17)
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ResourceData_get_property17(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for resourceType by property number (18)
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ResourceData_get_property18(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for tagCounts by property number (19)
         * @param  _ResourceData adb_ResourceData_t object
         * @param env pointer to environment struct
         * @return Array of adb_TagCount_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_ResourceData_get_property19(
            adb_ResourceData_t* _ResourceData,
            const axutil_env_t *env);

    
     #ifdef __cplusplus
     }
     #endif

     #endif /* ADB_RESOURCEDATA_H */
    

