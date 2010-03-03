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


        #ifndef ADB_CONTENTBEAN_H
        #define ADB_CONTENTBEAN_H

       /**
        * adb_ContentBean.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/Java version: #axisVersion# #today#
        */

       /**
        *  adb_ContentBean class
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
        

        typedef struct adb_ContentBean adb_ContentBean_t;

        
        

        /******************************* Create and Free functions *********************************/

        /**
         * Constructor for creating adb_ContentBean_t
         * @param env pointer to environment struct
         * @return newly created adb_ContentBean_t object
         */
        adb_ContentBean_t* AXIS2_CALL
        adb_ContentBean_create(
            const axutil_env_t *env );

        /**
         * Wrapper for the "free" function, will invoke the extension mapper instead
         * @param  _ContentBean adb_ContentBean_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ContentBean_free (
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env);

        /**
         * Free adb_ContentBean_t object
         * @param  _ContentBean adb_ContentBean_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ContentBean_free_obj (
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env);



        /********************************** Getters and Setters **************************************/
        
        

        /**
         * Getter for absent. 
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ContentBean_get_absent(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env);

        /**
         * Setter for absent.
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @param arg_absent axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ContentBean_set_absent(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env,
            const axis2_char_t*  arg_absent);

        /**
         * Resetter for absent
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ContentBean_reset_absent(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env);

        
        

        /**
         * Getter for collection. 
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_ContentBean_get_collection(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env);

        /**
         * Setter for collection.
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @param arg_collection axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ContentBean_set_collection(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env,
            axis2_bool_t  arg_collection);

        /**
         * Resetter for collection
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ContentBean_reset_collection(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env);

        
        

        /**
         * Getter for contentPath. 
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ContentBean_get_contentPath(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env);

        /**
         * Setter for contentPath.
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @param arg_contentPath axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ContentBean_set_contentPath(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env,
            const axis2_char_t*  arg_contentPath);

        /**
         * Resetter for contentPath
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ContentBean_reset_contentPath(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env);

        
        

        /**
         * Getter for loggedIn. 
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_ContentBean_get_loggedIn(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env);

        /**
         * Setter for loggedIn.
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @param arg_loggedIn axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ContentBean_set_loggedIn(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env,
            axis2_bool_t  arg_loggedIn);

        /**
         * Resetter for loggedIn
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ContentBean_reset_loggedIn(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env);

        
        

        /**
         * Getter for mediaType. 
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ContentBean_get_mediaType(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env);

        /**
         * Setter for mediaType.
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @param arg_mediaType axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ContentBean_set_mediaType(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env,
            const axis2_char_t*  arg_mediaType);

        /**
         * Resetter for mediaType
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ContentBean_reset_mediaType(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env);

        
        

        /**
         * Getter for pathWithVersion. 
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ContentBean_get_pathWithVersion(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env);

        /**
         * Setter for pathWithVersion.
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @param arg_pathWithVersion axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ContentBean_set_pathWithVersion(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env,
            const axis2_char_t*  arg_pathWithVersion);

        /**
         * Resetter for pathWithVersion
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ContentBean_reset_pathWithVersion(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env);

        
        

        /**
         * Getter for putAllowed. 
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_ContentBean_get_putAllowed(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env);

        /**
         * Setter for putAllowed.
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @param arg_putAllowed axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ContentBean_set_putAllowed(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env,
            axis2_bool_t  arg_putAllowed);

        /**
         * Resetter for putAllowed
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ContentBean_reset_putAllowed(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env);

        
        

        /**
         * Getter for realPath. 
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ContentBean_get_realPath(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env);

        /**
         * Setter for realPath.
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @param arg_realPath axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ContentBean_set_realPath(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env,
            const axis2_char_t*  arg_realPath);

        /**
         * Resetter for realPath
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ContentBean_reset_realPath(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env);

        
        

        /**
         * Getter for versionView. 
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_ContentBean_get_versionView(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env);

        /**
         * Setter for versionView.
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @param arg_versionView axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ContentBean_set_versionView(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env,
            axis2_bool_t  arg_versionView);

        /**
         * Resetter for versionView
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ContentBean_reset_versionView(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env);

        


        /******************************* Checking and Setting NIL values *********************************/
        

        /**
         * NOTE: set_nil is only available for nillable properties
         */

        

        /**
         * Check whether absent is nill
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ContentBean_is_absent_nil(
                adb_ContentBean_t* _ContentBean,
                const axutil_env_t *env);


        
        /**
         * Set absent to nill (currently the same as reset)
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ContentBean_set_absent_nil(
                adb_ContentBean_t* _ContentBean,
                const axutil_env_t *env);
        

        /**
         * Check whether collection is nill
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ContentBean_is_collection_nil(
                adb_ContentBean_t* _ContentBean,
                const axutil_env_t *env);


        

        /**
         * Check whether contentPath is nill
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ContentBean_is_contentPath_nil(
                adb_ContentBean_t* _ContentBean,
                const axutil_env_t *env);


        
        /**
         * Set contentPath to nill (currently the same as reset)
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ContentBean_set_contentPath_nil(
                adb_ContentBean_t* _ContentBean,
                const axutil_env_t *env);
        

        /**
         * Check whether loggedIn is nill
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ContentBean_is_loggedIn_nil(
                adb_ContentBean_t* _ContentBean,
                const axutil_env_t *env);


        

        /**
         * Check whether mediaType is nill
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ContentBean_is_mediaType_nil(
                adb_ContentBean_t* _ContentBean,
                const axutil_env_t *env);


        
        /**
         * Set mediaType to nill (currently the same as reset)
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ContentBean_set_mediaType_nil(
                adb_ContentBean_t* _ContentBean,
                const axutil_env_t *env);
        

        /**
         * Check whether pathWithVersion is nill
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ContentBean_is_pathWithVersion_nil(
                adb_ContentBean_t* _ContentBean,
                const axutil_env_t *env);


        
        /**
         * Set pathWithVersion to nill (currently the same as reset)
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ContentBean_set_pathWithVersion_nil(
                adb_ContentBean_t* _ContentBean,
                const axutil_env_t *env);
        

        /**
         * Check whether putAllowed is nill
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ContentBean_is_putAllowed_nil(
                adb_ContentBean_t* _ContentBean,
                const axutil_env_t *env);


        

        /**
         * Check whether realPath is nill
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ContentBean_is_realPath_nil(
                adb_ContentBean_t* _ContentBean,
                const axutil_env_t *env);


        
        /**
         * Set realPath to nill (currently the same as reset)
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ContentBean_set_realPath_nil(
                adb_ContentBean_t* _ContentBean,
                const axutil_env_t *env);
        

        /**
         * Check whether versionView is nill
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ContentBean_is_versionView_nil(
                adb_ContentBean_t* _ContentBean,
                const axutil_env_t *env);


        

        /**************************** Serialize and Deserialize functions ***************************/
        /*********** These functions are for use only inside the generated code *********************/

        
        /**
         * Wrapper for the deserialization function, will invoke the extension mapper instead
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs, 
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ContentBean_deserialize(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);

        /**
         * Deserialize an XML to adb objects
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs,
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ContentBean_deserialize_obj(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);
                            
            

       /**
         * Declare namespace in the most parent node 
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @param parent_element parent element
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index pointer to an int which contain the next namespace index
         */
       void AXIS2_CALL
       adb_ContentBean_declare_parent_namespaces(
                    adb_ContentBean_t* _ContentBean,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index);

        

        /**
         * Wrapper for the serialization function, will invoke the extension mapper instead
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @param ContentBean_om_node node to serialize from
         * @param ContentBean_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_ContentBean_serialize(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env,
            axiom_node_t* ContentBean_om_node, axiom_element_t *ContentBean_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Serialize to an XML from the adb objects
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @param ContentBean_om_node node to serialize from
         * @param ContentBean_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_ContentBean_serialize_obj(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env,
            axiom_node_t* ContentBean_om_node, axiom_element_t *ContentBean_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Check whether the adb_ContentBean is a particle class (E.g. group, inner sequence)
         * @return whether this is a particle class.
         */
        axis2_bool_t AXIS2_CALL
        adb_ContentBean_is_particle();

        /******************************* Alternatives for Create and Free functions *********************************/

        

        /**
         * Constructor for creating adb_ContentBean_t
         * @param env pointer to environment struct
         * @param _absent axis2_char_t*
         * @param _collection axis2_bool_t
         * @param _contentPath axis2_char_t*
         * @param _loggedIn axis2_bool_t
         * @param _mediaType axis2_char_t*
         * @param _pathWithVersion axis2_char_t*
         * @param _putAllowed axis2_bool_t
         * @param _realPath axis2_char_t*
         * @param _versionView axis2_bool_t
         * @return newly created adb_ContentBean_t object
         */
        adb_ContentBean_t* AXIS2_CALL
        adb_ContentBean_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _absent,
                axis2_bool_t _collection,
                axis2_char_t* _contentPath,
                axis2_bool_t _loggedIn,
                axis2_char_t* _mediaType,
                axis2_char_t* _pathWithVersion,
                axis2_bool_t _putAllowed,
                axis2_char_t* _realPath,
                axis2_bool_t _versionView);

        


                /**
                 * Free adb_ContentBean_t object and return the property value.
                 * You can use this to free the adb object as returning the property value. If there are
                 * many properties, it will only return the first property. Other properties will get freed with the adb object.
                 * @param  _ContentBean adb_ContentBean_t object to free
                 * @param env pointer to environment struct
                 * @return the property value holded by the ADB object, if there are many properties only returns the first.
                 */
                axis2_char_t* AXIS2_CALL
                adb_ContentBean_free_popping_value(
                        adb_ContentBean_t* _ContentBean,
                        const axutil_env_t *env);
            

        /******************************* get the value by the property number  *********************************/
        /************NOTE: This method is introduced to resolve a problem in unwrapping mode *******************/

        
        

        /**
         * Getter for absent by property number (1)
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ContentBean_get_property1(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env);

    
        

        /**
         * Getter for collection by property number (2)
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_ContentBean_get_property2(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env);

    
        

        /**
         * Getter for contentPath by property number (3)
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ContentBean_get_property3(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env);

    
        

        /**
         * Getter for loggedIn by property number (4)
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_ContentBean_get_property4(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env);

    
        

        /**
         * Getter for mediaType by property number (5)
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ContentBean_get_property5(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env);

    
        

        /**
         * Getter for pathWithVersion by property number (6)
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ContentBean_get_property6(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env);

    
        

        /**
         * Getter for putAllowed by property number (7)
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_ContentBean_get_property7(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env);

    
        

        /**
         * Getter for realPath by property number (8)
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ContentBean_get_property8(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env);

    
        

        /**
         * Getter for versionView by property number (9)
         * @param  _ContentBean adb_ContentBean_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_ContentBean_get_property9(
            adb_ContentBean_t* _ContentBean,
            const axutil_env_t *env);

    
     #ifdef __cplusplus
     }
     #endif

     #endif /* ADB_CONTENTBEAN_H */
    

