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


        #ifndef ADB_ADDRESOURCE_H
        #define ADB_ADDRESOURCE_H

       /**
        * adb_addResource.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/Java version: #axisVersion# #today#
        */

       /**
        *  adb_addResource class
        */

        
            #include <axutil_base64_binary.h>
          

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
        

        typedef struct adb_addResource adb_addResource_t;

        
        

        /******************************* Create and Free functions *********************************/

        /**
         * Constructor for creating adb_addResource_t
         * @param env pointer to environment struct
         * @return newly created adb_addResource_t object
         */
        adb_addResource_t* AXIS2_CALL
        adb_addResource_create(
            const axutil_env_t *env );

        /**
         * Wrapper for the "free" function, will invoke the extension mapper instead
         * @param  _addResource adb_addResource_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addResource_free (
            adb_addResource_t* _addResource,
            const axutil_env_t *env);

        /**
         * Free adb_addResource_t object
         * @param  _addResource adb_addResource_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addResource_free_obj (
            adb_addResource_t* _addResource,
            const axutil_env_t *env);



        /********************************** Getters and Setters **************************************/
        
        

        /**
         * Getter for path. 
         * @param  _addResource adb_addResource_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_addResource_get_path(
            adb_addResource_t* _addResource,
            const axutil_env_t *env);

        /**
         * Setter for path.
         * @param  _addResource adb_addResource_t object
         * @param env pointer to environment struct
         * @param arg_path axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addResource_set_path(
            adb_addResource_t* _addResource,
            const axutil_env_t *env,
            const axis2_char_t*  arg_path);

        /**
         * Resetter for path
         * @param  _addResource adb_addResource_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addResource_reset_path(
            adb_addResource_t* _addResource,
            const axutil_env_t *env);

        
        

        /**
         * Getter for mediaType. 
         * @param  _addResource adb_addResource_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_addResource_get_mediaType(
            adb_addResource_t* _addResource,
            const axutil_env_t *env);

        /**
         * Setter for mediaType.
         * @param  _addResource adb_addResource_t object
         * @param env pointer to environment struct
         * @param arg_mediaType axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addResource_set_mediaType(
            adb_addResource_t* _addResource,
            const axutil_env_t *env,
            const axis2_char_t*  arg_mediaType);

        /**
         * Resetter for mediaType
         * @param  _addResource adb_addResource_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addResource_reset_mediaType(
            adb_addResource_t* _addResource,
            const axutil_env_t *env);

        
        

        /**
         * Getter for description. 
         * @param  _addResource adb_addResource_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_addResource_get_description(
            adb_addResource_t* _addResource,
            const axutil_env_t *env);

        /**
         * Setter for description.
         * @param  _addResource adb_addResource_t object
         * @param env pointer to environment struct
         * @param arg_description axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addResource_set_description(
            adb_addResource_t* _addResource,
            const axutil_env_t *env,
            const axis2_char_t*  arg_description);

        /**
         * Resetter for description
         * @param  _addResource adb_addResource_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addResource_reset_description(
            adb_addResource_t* _addResource,
            const axutil_env_t *env);

        
        

        /**
         * Getter for content. 
         * @param  _addResource adb_addResource_t object
         * @param env pointer to environment struct
         * @return axutil_base64_binary_t*
         */
        axutil_base64_binary_t* AXIS2_CALL
        adb_addResource_get_content(
            adb_addResource_t* _addResource,
            const axutil_env_t *env);

        /**
         * Setter for content.
         * @param  _addResource adb_addResource_t object
         * @param env pointer to environment struct
         * @param arg_content axutil_base64_binary_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addResource_set_content(
            adb_addResource_t* _addResource,
            const axutil_env_t *env,
            axutil_base64_binary_t*  arg_content);

        /**
         * Resetter for content
         * @param  _addResource adb_addResource_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addResource_reset_content(
            adb_addResource_t* _addResource,
            const axutil_env_t *env);

        
        

        /**
         * Getter for symlinkLocation. 
         * @param  _addResource adb_addResource_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_addResource_get_symlinkLocation(
            adb_addResource_t* _addResource,
            const axutil_env_t *env);

        /**
         * Setter for symlinkLocation.
         * @param  _addResource adb_addResource_t object
         * @param env pointer to environment struct
         * @param arg_symlinkLocation axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addResource_set_symlinkLocation(
            adb_addResource_t* _addResource,
            const axutil_env_t *env,
            const axis2_char_t*  arg_symlinkLocation);

        /**
         * Resetter for symlinkLocation
         * @param  _addResource adb_addResource_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addResource_reset_symlinkLocation(
            adb_addResource_t* _addResource,
            const axutil_env_t *env);

        


        /******************************* Checking and Setting NIL values *********************************/
        

        /**
         * NOTE: set_nil is only available for nillable properties
         */

        

        /**
         * Check whether path is nill
         * @param  _addResource adb_addResource_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_addResource_is_path_nil(
                adb_addResource_t* _addResource,
                const axutil_env_t *env);


        
        /**
         * Set path to nill (currently the same as reset)
         * @param  _addResource adb_addResource_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addResource_set_path_nil(
                adb_addResource_t* _addResource,
                const axutil_env_t *env);
        

        /**
         * Check whether mediaType is nill
         * @param  _addResource adb_addResource_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_addResource_is_mediaType_nil(
                adb_addResource_t* _addResource,
                const axutil_env_t *env);


        
        /**
         * Set mediaType to nill (currently the same as reset)
         * @param  _addResource adb_addResource_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addResource_set_mediaType_nil(
                adb_addResource_t* _addResource,
                const axutil_env_t *env);
        

        /**
         * Check whether description is nill
         * @param  _addResource adb_addResource_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_addResource_is_description_nil(
                adb_addResource_t* _addResource,
                const axutil_env_t *env);


        
        /**
         * Set description to nill (currently the same as reset)
         * @param  _addResource adb_addResource_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addResource_set_description_nil(
                adb_addResource_t* _addResource,
                const axutil_env_t *env);
        

        /**
         * Check whether content is nill
         * @param  _addResource adb_addResource_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_addResource_is_content_nil(
                adb_addResource_t* _addResource,
                const axutil_env_t *env);


        
        /**
         * Set content to nill (currently the same as reset)
         * @param  _addResource adb_addResource_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addResource_set_content_nil(
                adb_addResource_t* _addResource,
                const axutil_env_t *env);
        

        /**
         * Check whether symlinkLocation is nill
         * @param  _addResource adb_addResource_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_addResource_is_symlinkLocation_nil(
                adb_addResource_t* _addResource,
                const axutil_env_t *env);


        
        /**
         * Set symlinkLocation to nill (currently the same as reset)
         * @param  _addResource adb_addResource_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addResource_set_symlinkLocation_nil(
                adb_addResource_t* _addResource,
                const axutil_env_t *env);
        

        /**************************** Serialize and Deserialize functions ***************************/
        /*********** These functions are for use only inside the generated code *********************/

        
        /**
         * Wrapper for the deserialization function, will invoke the extension mapper instead
         * @param  _addResource adb_addResource_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs, 
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addResource_deserialize(
            adb_addResource_t* _addResource,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);

        /**
         * Deserialize an XML to adb objects
         * @param  _addResource adb_addResource_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs,
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addResource_deserialize_obj(
            adb_addResource_t* _addResource,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);
                            
            

       /**
         * Declare namespace in the most parent node 
         * @param  _addResource adb_addResource_t object
         * @param env pointer to environment struct
         * @param parent_element parent element
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index pointer to an int which contain the next namespace index
         */
       void AXIS2_CALL
       adb_addResource_declare_parent_namespaces(
                    adb_addResource_t* _addResource,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index);

        

        /**
         * Wrapper for the serialization function, will invoke the extension mapper instead
         * @param  _addResource adb_addResource_t object
         * @param env pointer to environment struct
         * @param addResource_om_node node to serialize from
         * @param addResource_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_addResource_serialize(
            adb_addResource_t* _addResource,
            const axutil_env_t *env,
            axiom_node_t* addResource_om_node, axiom_element_t *addResource_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Serialize to an XML from the adb objects
         * @param  _addResource adb_addResource_t object
         * @param env pointer to environment struct
         * @param addResource_om_node node to serialize from
         * @param addResource_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_addResource_serialize_obj(
            adb_addResource_t* _addResource,
            const axutil_env_t *env,
            axiom_node_t* addResource_om_node, axiom_element_t *addResource_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Check whether the adb_addResource is a particle class (E.g. group, inner sequence)
         * @return whether this is a particle class.
         */
        axis2_bool_t AXIS2_CALL
        adb_addResource_is_particle();

        /******************************* Alternatives for Create and Free functions *********************************/

        

        /**
         * Constructor for creating adb_addResource_t
         * @param env pointer to environment struct
         * @param _path axis2_char_t*
         * @param _mediaType axis2_char_t*
         * @param _description axis2_char_t*
         * @param _content axutil_base64_binary_t*
         * @param _symlinkLocation axis2_char_t*
         * @return newly created adb_addResource_t object
         */
        adb_addResource_t* AXIS2_CALL
        adb_addResource_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _path,
                axis2_char_t* _mediaType,
                axis2_char_t* _description,
                axutil_base64_binary_t* _content,
                axis2_char_t* _symlinkLocation);

        


                /**
                 * Free adb_addResource_t object and return the property value.
                 * You can use this to free the adb object as returning the property value. If there are
                 * many properties, it will only return the first property. Other properties will get freed with the adb object.
                 * @param  _addResource adb_addResource_t object to free
                 * @param env pointer to environment struct
                 * @return the property value holded by the ADB object, if there are many properties only returns the first.
                 */
                axis2_char_t* AXIS2_CALL
                adb_addResource_free_popping_value(
                        adb_addResource_t* _addResource,
                        const axutil_env_t *env);
            

        /******************************* get the value by the property number  *********************************/
        /************NOTE: This method is introduced to resolve a problem in unwrapping mode *******************/

        
        

        /**
         * Getter for path by property number (1)
         * @param  _addResource adb_addResource_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_addResource_get_property1(
            adb_addResource_t* _addResource,
            const axutil_env_t *env);

    
        

        /**
         * Getter for mediaType by property number (2)
         * @param  _addResource adb_addResource_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_addResource_get_property2(
            adb_addResource_t* _addResource,
            const axutil_env_t *env);

    
        

        /**
         * Getter for description by property number (3)
         * @param  _addResource adb_addResource_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_addResource_get_property3(
            adb_addResource_t* _addResource,
            const axutil_env_t *env);

    
        

        /**
         * Getter for content by property number (4)
         * @param  _addResource adb_addResource_t object
         * @param env pointer to environment struct
         * @return axutil_base64_binary_t*
         */
        axutil_base64_binary_t* AXIS2_CALL
        adb_addResource_get_property4(
            adb_addResource_t* _addResource,
            const axutil_env_t *env);

    
        

        /**
         * Getter for symlinkLocation by property number (5)
         * @param  _addResource adb_addResource_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_addResource_get_property5(
            adb_addResource_t* _addResource,
            const axutil_env_t *env);

    
     #ifdef __cplusplus
     }
     #endif

     #endif /* ADB_ADDRESOURCE_H */
    

