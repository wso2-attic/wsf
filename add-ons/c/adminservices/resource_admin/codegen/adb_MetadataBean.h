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


        #ifndef ADB_METADATABEAN_H
        #define ADB_METADATABEAN_H

       /**
        * adb_MetadataBean.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/Java version: #axisVersion# #today#
        */

       /**
        *  adb_MetadataBean class
        */

        
          #include "adb_WebResourcePath.h"
          

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
        

        typedef struct adb_MetadataBean adb_MetadataBean_t;

        
        

        /******************************* Create and Free functions *********************************/

        /**
         * Constructor for creating adb_MetadataBean_t
         * @param env pointer to environment struct
         * @return newly created adb_MetadataBean_t object
         */
        adb_MetadataBean_t* AXIS2_CALL
        adb_MetadataBean_create(
            const axutil_env_t *env );

        /**
         * Wrapper for the "free" function, will invoke the extension mapper instead
         * @param  _MetadataBean adb_MetadataBean_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_free (
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

        /**
         * Free adb_MetadataBean_t object
         * @param  _MetadataBean adb_MetadataBean_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_free_obj (
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);



        /********************************** Getters and Setters **************************************/
        /******** Deprecated for array types, Use 'Getters and Setters for Arrays' instead ***********/
        

        /**
         * Getter for activeResourcePath. 
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_MetadataBean_get_activeResourcePath(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

        /**
         * Setter for activeResourcePath.
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @param arg_activeResourcePath axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_set_activeResourcePath(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env,
            const axis2_char_t*  arg_activeResourcePath);

        /**
         * Resetter for activeResourcePath
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_reset_activeResourcePath(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

        
        

        /**
         * Getter for author. 
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_MetadataBean_get_author(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

        /**
         * Setter for author.
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @param arg_author axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_set_author(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env,
            const axis2_char_t*  arg_author);

        /**
         * Resetter for author
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_reset_author(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

        
        

        /**
         * Getter for collection. 
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_MetadataBean_get_collection(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

        /**
         * Setter for collection.
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @param arg_collection axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_set_collection(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env,
            axis2_bool_t  arg_collection);

        /**
         * Resetter for collection
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_reset_collection(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

        
        

        /**
         * Getter for contentPath. 
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_MetadataBean_get_contentPath(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

        /**
         * Setter for contentPath.
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @param arg_contentPath axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_set_contentPath(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env,
            const axis2_char_t*  arg_contentPath);

        /**
         * Resetter for contentPath
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_reset_contentPath(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

        
        

        /**
         * Getter for description. 
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_MetadataBean_get_description(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

        /**
         * Setter for description.
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @param arg_description axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_set_description(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env,
            const axis2_char_t*  arg_description);

        /**
         * Resetter for description
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_reset_description(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

        
        

        /**
         * Getter for formattedCreatedOn. 
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_MetadataBean_get_formattedCreatedOn(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

        /**
         * Setter for formattedCreatedOn.
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @param arg_formattedCreatedOn axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_set_formattedCreatedOn(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env,
            const axis2_char_t*  arg_formattedCreatedOn);

        /**
         * Resetter for formattedCreatedOn
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_reset_formattedCreatedOn(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

        
        

        /**
         * Getter for formattedLastModified. 
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_MetadataBean_get_formattedLastModified(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

        /**
         * Setter for formattedLastModified.
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @param arg_formattedLastModified axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_set_formattedLastModified(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env,
            const axis2_char_t*  arg_formattedLastModified);

        /**
         * Resetter for formattedLastModified
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_reset_formattedLastModified(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

        
        

        /**
         * Getter for lastUpdater. 
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_MetadataBean_get_lastUpdater(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

        /**
         * Setter for lastUpdater.
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @param arg_lastUpdater axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_set_lastUpdater(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env,
            const axis2_char_t*  arg_lastUpdater);

        /**
         * Resetter for lastUpdater
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_reset_lastUpdater(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

        
        

        /**
         * Getter for mediaType. 
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_MetadataBean_get_mediaType(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

        /**
         * Setter for mediaType.
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @param arg_mediaType axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_set_mediaType(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env,
            const axis2_char_t*  arg_mediaType);

        /**
         * Resetter for mediaType
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_reset_mediaType(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

        
        

        /**
         * Getter for navigatablePaths. Deprecated for array types, Use adb_MetadataBean_get_navigatablePaths_at instead
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return Array of adb_WebResourcePath_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_MetadataBean_get_navigatablePaths(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

        /**
         * Setter for navigatablePaths.Deprecated for array types, Use adb_MetadataBean_set_navigatablePaths_at
         * or adb_MetadataBean_add_navigatablePaths instead.
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @param arg_navigatablePaths Array of adb_WebResourcePath_t*s.
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_set_navigatablePaths(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env,
            axutil_array_list_t*  arg_navigatablePaths);

        /**
         * Resetter for navigatablePaths
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_reset_navigatablePaths(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

        
        

        /**
         * Getter for path. 
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_MetadataBean_get_path(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

        /**
         * Setter for path.
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @param arg_path axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_set_path(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env,
            const axis2_char_t*  arg_path);

        /**
         * Resetter for path
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_reset_path(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

        
        

        /**
         * Getter for pathWithVersion. 
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_MetadataBean_get_pathWithVersion(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

        /**
         * Setter for pathWithVersion.
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @param arg_pathWithVersion axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_set_pathWithVersion(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env,
            const axis2_char_t*  arg_pathWithVersion);

        /**
         * Resetter for pathWithVersion
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_reset_pathWithVersion(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

        
        

        /**
         * Getter for permalink. 
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_MetadataBean_get_permalink(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

        /**
         * Setter for permalink.
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @param arg_permalink axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_set_permalink(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env,
            const axis2_char_t*  arg_permalink);

        /**
         * Resetter for permalink
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_reset_permalink(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

        
        

        /**
         * Getter for putAllowed. 
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_MetadataBean_get_putAllowed(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

        /**
         * Setter for putAllowed.
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @param arg_putAllowed axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_set_putAllowed(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env,
            axis2_bool_t  arg_putAllowed);

        /**
         * Resetter for putAllowed
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_reset_putAllowed(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

        
        

        /**
         * Getter for serverBaseURL. 
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_MetadataBean_get_serverBaseURL(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

        /**
         * Setter for serverBaseURL.
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @param arg_serverBaseURL axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_set_serverBaseURL(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env,
            const axis2_char_t*  arg_serverBaseURL);

        /**
         * Resetter for serverBaseURL
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_reset_serverBaseURL(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

        
        

        /**
         * Getter for versionView. 
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_MetadataBean_get_versionView(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

        /**
         * Setter for versionView.
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @param arg_versionView axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_set_versionView(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env,
            axis2_bool_t  arg_versionView);

        /**
         * Resetter for versionView
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_reset_versionView(
            adb_MetadataBean_t* _MetadataBean,
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
         * Get the ith element of navigatablePaths.
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @return ith adb_WebResourcePath_t* of the array
         */
        adb_WebResourcePath_t* AXIS2_CALL
        adb_MetadataBean_get_navigatablePaths_at(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env, int i);

        /**
         * Set the ith element of navigatablePaths. (If the ith already exist, it will be replaced)
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @param arg_navigatablePaths element to set adb_WebResourcePath_t* to the array
         * @return ith adb_WebResourcePath_t* of the array
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_set_navigatablePaths_at(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env, int i,
                adb_WebResourcePath_t* arg_navigatablePaths);


        /**
         * Add to navigatablePaths.
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @param arg_navigatablePaths element to add adb_WebResourcePath_t* to the array
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_add_navigatablePaths(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env,
                adb_WebResourcePath_t* arg_navigatablePaths);

        /**
         * Get the size of the navigatablePaths array.
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct.
         * @return the size of the navigatablePaths array.
         */
        int AXIS2_CALL
        adb_MetadataBean_sizeof_navigatablePaths(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env);

        /**
         * Remove the ith element of navigatablePaths.
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @param i index of the item to remove
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_remove_navigatablePaths_at(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env, int i);

        


        /******************************* Checking and Setting NIL values *********************************/
        /* Use 'Checking and Setting NIL values for Arrays' to check and set nil for individual elements */

        /**
         * NOTE: set_nil is only available for nillable properties
         */

        

        /**
         * Check whether activeResourcePath is nill
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_MetadataBean_is_activeResourcePath_nil(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env);


        
        /**
         * Set activeResourcePath to nill (currently the same as reset)
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_set_activeResourcePath_nil(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env);
        

        /**
         * Check whether author is nill
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_MetadataBean_is_author_nil(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env);


        
        /**
         * Set author to nill (currently the same as reset)
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_set_author_nil(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env);
        

        /**
         * Check whether collection is nill
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_MetadataBean_is_collection_nil(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env);


        

        /**
         * Check whether contentPath is nill
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_MetadataBean_is_contentPath_nil(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env);


        
        /**
         * Set contentPath to nill (currently the same as reset)
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_set_contentPath_nil(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env);
        

        /**
         * Check whether description is nill
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_MetadataBean_is_description_nil(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env);


        
        /**
         * Set description to nill (currently the same as reset)
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_set_description_nil(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env);
        

        /**
         * Check whether formattedCreatedOn is nill
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_MetadataBean_is_formattedCreatedOn_nil(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env);


        
        /**
         * Set formattedCreatedOn to nill (currently the same as reset)
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_set_formattedCreatedOn_nil(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env);
        

        /**
         * Check whether formattedLastModified is nill
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_MetadataBean_is_formattedLastModified_nil(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env);


        
        /**
         * Set formattedLastModified to nill (currently the same as reset)
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_set_formattedLastModified_nil(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env);
        

        /**
         * Check whether lastUpdater is nill
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_MetadataBean_is_lastUpdater_nil(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env);


        
        /**
         * Set lastUpdater to nill (currently the same as reset)
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_set_lastUpdater_nil(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env);
        

        /**
         * Check whether mediaType is nill
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_MetadataBean_is_mediaType_nil(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env);


        
        /**
         * Set mediaType to nill (currently the same as reset)
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_set_mediaType_nil(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env);
        

        /**
         * Check whether navigatablePaths is nill
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_MetadataBean_is_navigatablePaths_nil(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env);


        
        /**
         * Set navigatablePaths to nill (currently the same as reset)
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_set_navigatablePaths_nil(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env);
        

        /**
         * Check whether path is nill
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_MetadataBean_is_path_nil(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env);


        
        /**
         * Set path to nill (currently the same as reset)
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_set_path_nil(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env);
        

        /**
         * Check whether pathWithVersion is nill
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_MetadataBean_is_pathWithVersion_nil(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env);


        
        /**
         * Set pathWithVersion to nill (currently the same as reset)
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_set_pathWithVersion_nil(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env);
        

        /**
         * Check whether permalink is nill
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_MetadataBean_is_permalink_nil(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env);


        
        /**
         * Set permalink to nill (currently the same as reset)
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_set_permalink_nil(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env);
        

        /**
         * Check whether putAllowed is nill
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_MetadataBean_is_putAllowed_nil(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env);


        

        /**
         * Check whether serverBaseURL is nill
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_MetadataBean_is_serverBaseURL_nil(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env);


        
        /**
         * Set serverBaseURL to nill (currently the same as reset)
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_set_serverBaseURL_nil(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env);
        

        /**
         * Check whether versionView is nill
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_MetadataBean_is_versionView_nil(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env);


        
        /*************************** Checking and Setting 'NIL' values in Arrays *****************************/

        /**
         * NOTE: You may set this to remove specific elements in the array
         *       But you can not remove elements, if the specific property is declared to be non-nillable or sizeof(array) < minOccurs
         */
        
        /**
         * Check whether navigatablePaths is nill at i
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct.
         * @param i index of the item to return.
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_MetadataBean_is_navigatablePaths_nil_at(
                adb_MetadataBean_t* _MetadataBean,
                const axutil_env_t *env, int i);
 
       
        /**
         * Set navigatablePaths to nill at i
         * @param  _MetadataBean _ adb_MetadataBean_t object
         * @param env pointer to environment struct.
         * @param i index of the item to set.
         * @return AXIS2_SUCCESS on success, or AXIS2_FAILURE otherwise.
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_set_navigatablePaths_nil_at(
                adb_MetadataBean_t* _MetadataBean, 
                const axutil_env_t *env, int i);

        

        /**************************** Serialize and Deserialize functions ***************************/
        /*********** These functions are for use only inside the generated code *********************/

        
        /**
         * Wrapper for the deserialization function, will invoke the extension mapper instead
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs, 
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_deserialize(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);

        /**
         * Deserialize an XML to adb objects
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs,
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_MetadataBean_deserialize_obj(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);
                            
            

       /**
         * Declare namespace in the most parent node 
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @param parent_element parent element
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index pointer to an int which contain the next namespace index
         */
       void AXIS2_CALL
       adb_MetadataBean_declare_parent_namespaces(
                    adb_MetadataBean_t* _MetadataBean,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index);

        

        /**
         * Wrapper for the serialization function, will invoke the extension mapper instead
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @param MetadataBean_om_node node to serialize from
         * @param MetadataBean_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_MetadataBean_serialize(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env,
            axiom_node_t* MetadataBean_om_node, axiom_element_t *MetadataBean_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Serialize to an XML from the adb objects
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @param MetadataBean_om_node node to serialize from
         * @param MetadataBean_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_MetadataBean_serialize_obj(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env,
            axiom_node_t* MetadataBean_om_node, axiom_element_t *MetadataBean_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Check whether the adb_MetadataBean is a particle class (E.g. group, inner sequence)
         * @return whether this is a particle class.
         */
        axis2_bool_t AXIS2_CALL
        adb_MetadataBean_is_particle();

        /******************************* Alternatives for Create and Free functions *********************************/

        

        /**
         * Constructor for creating adb_MetadataBean_t
         * @param env pointer to environment struct
         * @param _activeResourcePath axis2_char_t*
         * @param _author axis2_char_t*
         * @param _collection axis2_bool_t
         * @param _contentPath axis2_char_t*
         * @param _description axis2_char_t*
         * @param _formattedCreatedOn axis2_char_t*
         * @param _formattedLastModified axis2_char_t*
         * @param _lastUpdater axis2_char_t*
         * @param _mediaType axis2_char_t*
         * @param _navigatablePaths axutil_array_list_t*
         * @param _path axis2_char_t*
         * @param _pathWithVersion axis2_char_t*
         * @param _permalink axis2_char_t*
         * @param _putAllowed axis2_bool_t
         * @param _serverBaseURL axis2_char_t*
         * @param _versionView axis2_bool_t
         * @return newly created adb_MetadataBean_t object
         */
        adb_MetadataBean_t* AXIS2_CALL
        adb_MetadataBean_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _activeResourcePath,
                axis2_char_t* _author,
                axis2_bool_t _collection,
                axis2_char_t* _contentPath,
                axis2_char_t* _description,
                axis2_char_t* _formattedCreatedOn,
                axis2_char_t* _formattedLastModified,
                axis2_char_t* _lastUpdater,
                axis2_char_t* _mediaType,
                axutil_array_list_t* _navigatablePaths,
                axis2_char_t* _path,
                axis2_char_t* _pathWithVersion,
                axis2_char_t* _permalink,
                axis2_bool_t _putAllowed,
                axis2_char_t* _serverBaseURL,
                axis2_bool_t _versionView);

        


                /**
                 * Free adb_MetadataBean_t object and return the property value.
                 * You can use this to free the adb object as returning the property value. If there are
                 * many properties, it will only return the first property. Other properties will get freed with the adb object.
                 * @param  _MetadataBean adb_MetadataBean_t object to free
                 * @param env pointer to environment struct
                 * @return the property value holded by the ADB object, if there are many properties only returns the first.
                 */
                axis2_char_t* AXIS2_CALL
                adb_MetadataBean_free_popping_value(
                        adb_MetadataBean_t* _MetadataBean,
                        const axutil_env_t *env);
            

        /******************************* get the value by the property number  *********************************/
        /************NOTE: This method is introduced to resolve a problem in unwrapping mode *******************/

        
        

        /**
         * Getter for activeResourcePath by property number (1)
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_MetadataBean_get_property1(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

    
        

        /**
         * Getter for author by property number (2)
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_MetadataBean_get_property2(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

    
        

        /**
         * Getter for collection by property number (3)
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_MetadataBean_get_property3(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

    
        

        /**
         * Getter for contentPath by property number (4)
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_MetadataBean_get_property4(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

    
        

        /**
         * Getter for description by property number (5)
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_MetadataBean_get_property5(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

    
        

        /**
         * Getter for formattedCreatedOn by property number (6)
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_MetadataBean_get_property6(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

    
        

        /**
         * Getter for formattedLastModified by property number (7)
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_MetadataBean_get_property7(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

    
        

        /**
         * Getter for lastUpdater by property number (8)
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_MetadataBean_get_property8(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

    
        

        /**
         * Getter for mediaType by property number (9)
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_MetadataBean_get_property9(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

    
        

        /**
         * Getter for navigatablePaths by property number (10)
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return Array of adb_WebResourcePath_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_MetadataBean_get_property10(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

    
        

        /**
         * Getter for path by property number (11)
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_MetadataBean_get_property11(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

    
        

        /**
         * Getter for pathWithVersion by property number (12)
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_MetadataBean_get_property12(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

    
        

        /**
         * Getter for permalink by property number (13)
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_MetadataBean_get_property13(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

    
        

        /**
         * Getter for putAllowed by property number (14)
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_MetadataBean_get_property14(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

    
        

        /**
         * Getter for serverBaseURL by property number (15)
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_MetadataBean_get_property15(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

    
        

        /**
         * Getter for versionView by property number (16)
         * @param  _MetadataBean adb_MetadataBean_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_MetadataBean_get_property16(
            adb_MetadataBean_t* _MetadataBean,
            const axutil_env_t *env);

    
     #ifdef __cplusplus
     }
     #endif

     #endif /* ADB_METADATABEAN_H */
    

