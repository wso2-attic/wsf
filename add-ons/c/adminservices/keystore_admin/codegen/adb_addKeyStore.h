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


        #ifndef ADB_ADDKEYSTORE_H
        #define ADB_ADDKEYSTORE_H

       /**
        * adb_addKeyStore.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/Java version: #axisVersion# #today#
        */

       /**
        *  adb_addKeyStore class
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
        

        typedef struct adb_addKeyStore adb_addKeyStore_t;

        
        

        /******************************* Create and Free functions *********************************/

        /**
         * Constructor for creating adb_addKeyStore_t
         * @param env pointer to environment struct
         * @return newly created adb_addKeyStore_t object
         */
        adb_addKeyStore_t* AXIS2_CALL
        adb_addKeyStore_create(
            const axutil_env_t *env );

        /**
         * Wrapper for the "free" function, will invoke the extension mapper instead
         * @param  _addKeyStore adb_addKeyStore_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addKeyStore_free (
            adb_addKeyStore_t* _addKeyStore,
            const axutil_env_t *env);

        /**
         * Free adb_addKeyStore_t object
         * @param  _addKeyStore adb_addKeyStore_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addKeyStore_free_obj (
            adb_addKeyStore_t* _addKeyStore,
            const axutil_env_t *env);



        /********************************** Getters and Setters **************************************/
        
        

        /**
         * Getter for fileData. 
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_addKeyStore_get_fileData(
            adb_addKeyStore_t* _addKeyStore,
            const axutil_env_t *env);

        /**
         * Setter for fileData.
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @param arg_fileData axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addKeyStore_set_fileData(
            adb_addKeyStore_t* _addKeyStore,
            const axutil_env_t *env,
            const axis2_char_t*  arg_fileData);

        /**
         * Resetter for fileData
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addKeyStore_reset_fileData(
            adb_addKeyStore_t* _addKeyStore,
            const axutil_env_t *env);

        
        

        /**
         * Getter for filename. 
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_addKeyStore_get_filename(
            adb_addKeyStore_t* _addKeyStore,
            const axutil_env_t *env);

        /**
         * Setter for filename.
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @param arg_filename axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addKeyStore_set_filename(
            adb_addKeyStore_t* _addKeyStore,
            const axutil_env_t *env,
            const axis2_char_t*  arg_filename);

        /**
         * Resetter for filename
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addKeyStore_reset_filename(
            adb_addKeyStore_t* _addKeyStore,
            const axutil_env_t *env);

        
        

        /**
         * Getter for password. 
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_addKeyStore_get_password(
            adb_addKeyStore_t* _addKeyStore,
            const axutil_env_t *env);

        /**
         * Setter for password.
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @param arg_password axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addKeyStore_set_password(
            adb_addKeyStore_t* _addKeyStore,
            const axutil_env_t *env,
            const axis2_char_t*  arg_password);

        /**
         * Resetter for password
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addKeyStore_reset_password(
            adb_addKeyStore_t* _addKeyStore,
            const axutil_env_t *env);

        
        

        /**
         * Getter for provider. 
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_addKeyStore_get_provider(
            adb_addKeyStore_t* _addKeyStore,
            const axutil_env_t *env);

        /**
         * Setter for provider.
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @param arg_provider axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addKeyStore_set_provider(
            adb_addKeyStore_t* _addKeyStore,
            const axutil_env_t *env,
            const axis2_char_t*  arg_provider);

        /**
         * Resetter for provider
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addKeyStore_reset_provider(
            adb_addKeyStore_t* _addKeyStore,
            const axutil_env_t *env);

        
        

        /**
         * Getter for type. 
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_addKeyStore_get_type(
            adb_addKeyStore_t* _addKeyStore,
            const axutil_env_t *env);

        /**
         * Setter for type.
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @param arg_type axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addKeyStore_set_type(
            adb_addKeyStore_t* _addKeyStore,
            const axutil_env_t *env,
            const axis2_char_t*  arg_type);

        /**
         * Resetter for type
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addKeyStore_reset_type(
            adb_addKeyStore_t* _addKeyStore,
            const axutil_env_t *env);

        
        

        /**
         * Getter for pvtkeyPass. 
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_addKeyStore_get_pvtkeyPass(
            adb_addKeyStore_t* _addKeyStore,
            const axutil_env_t *env);

        /**
         * Setter for pvtkeyPass.
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @param arg_pvtkeyPass axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addKeyStore_set_pvtkeyPass(
            adb_addKeyStore_t* _addKeyStore,
            const axutil_env_t *env,
            const axis2_char_t*  arg_pvtkeyPass);

        /**
         * Resetter for pvtkeyPass
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addKeyStore_reset_pvtkeyPass(
            adb_addKeyStore_t* _addKeyStore,
            const axutil_env_t *env);

        


        /******************************* Checking and Setting NIL values *********************************/
        

        /**
         * NOTE: set_nil is only available for nillable properties
         */

        

        /**
         * Check whether fileData is nill
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_addKeyStore_is_fileData_nil(
                adb_addKeyStore_t* _addKeyStore,
                const axutil_env_t *env);


        
        /**
         * Set fileData to nill (currently the same as reset)
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addKeyStore_set_fileData_nil(
                adb_addKeyStore_t* _addKeyStore,
                const axutil_env_t *env);
        

        /**
         * Check whether filename is nill
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_addKeyStore_is_filename_nil(
                adb_addKeyStore_t* _addKeyStore,
                const axutil_env_t *env);


        
        /**
         * Set filename to nill (currently the same as reset)
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addKeyStore_set_filename_nil(
                adb_addKeyStore_t* _addKeyStore,
                const axutil_env_t *env);
        

        /**
         * Check whether password is nill
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_addKeyStore_is_password_nil(
                adb_addKeyStore_t* _addKeyStore,
                const axutil_env_t *env);


        
        /**
         * Set password to nill (currently the same as reset)
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addKeyStore_set_password_nil(
                adb_addKeyStore_t* _addKeyStore,
                const axutil_env_t *env);
        

        /**
         * Check whether provider is nill
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_addKeyStore_is_provider_nil(
                adb_addKeyStore_t* _addKeyStore,
                const axutil_env_t *env);


        
        /**
         * Set provider to nill (currently the same as reset)
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addKeyStore_set_provider_nil(
                adb_addKeyStore_t* _addKeyStore,
                const axutil_env_t *env);
        

        /**
         * Check whether type is nill
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_addKeyStore_is_type_nil(
                adb_addKeyStore_t* _addKeyStore,
                const axutil_env_t *env);


        
        /**
         * Set type to nill (currently the same as reset)
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addKeyStore_set_type_nil(
                adb_addKeyStore_t* _addKeyStore,
                const axutil_env_t *env);
        

        /**
         * Check whether pvtkeyPass is nill
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_addKeyStore_is_pvtkeyPass_nil(
                adb_addKeyStore_t* _addKeyStore,
                const axutil_env_t *env);


        
        /**
         * Set pvtkeyPass to nill (currently the same as reset)
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addKeyStore_set_pvtkeyPass_nil(
                adb_addKeyStore_t* _addKeyStore,
                const axutil_env_t *env);
        

        /**************************** Serialize and Deserialize functions ***************************/
        /*********** These functions are for use only inside the generated code *********************/

        
        /**
         * Wrapper for the deserialization function, will invoke the extension mapper instead
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs, 
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addKeyStore_deserialize(
            adb_addKeyStore_t* _addKeyStore,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);

        /**
         * Deserialize an XML to adb objects
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs,
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_addKeyStore_deserialize_obj(
            adb_addKeyStore_t* _addKeyStore,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);
                            
            

       /**
         * Declare namespace in the most parent node 
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @param parent_element parent element
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index pointer to an int which contain the next namespace index
         */
       void AXIS2_CALL
       adb_addKeyStore_declare_parent_namespaces(
                    adb_addKeyStore_t* _addKeyStore,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index);

        

        /**
         * Wrapper for the serialization function, will invoke the extension mapper instead
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @param addKeyStore_om_node node to serialize from
         * @param addKeyStore_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_addKeyStore_serialize(
            adb_addKeyStore_t* _addKeyStore,
            const axutil_env_t *env,
            axiom_node_t* addKeyStore_om_node, axiom_element_t *addKeyStore_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Serialize to an XML from the adb objects
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @param addKeyStore_om_node node to serialize from
         * @param addKeyStore_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_addKeyStore_serialize_obj(
            adb_addKeyStore_t* _addKeyStore,
            const axutil_env_t *env,
            axiom_node_t* addKeyStore_om_node, axiom_element_t *addKeyStore_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Check whether the adb_addKeyStore is a particle class (E.g. group, inner sequence)
         * @return whether this is a particle class.
         */
        axis2_bool_t AXIS2_CALL
        adb_addKeyStore_is_particle();

        /******************************* Alternatives for Create and Free functions *********************************/

        

        /**
         * Constructor for creating adb_addKeyStore_t
         * @param env pointer to environment struct
         * @param _fileData axis2_char_t*
         * @param _filename axis2_char_t*
         * @param _password axis2_char_t*
         * @param _provider axis2_char_t*
         * @param _type axis2_char_t*
         * @param _pvtkeyPass axis2_char_t*
         * @return newly created adb_addKeyStore_t object
         */
        adb_addKeyStore_t* AXIS2_CALL
        adb_addKeyStore_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _fileData,
                axis2_char_t* _filename,
                axis2_char_t* _password,
                axis2_char_t* _provider,
                axis2_char_t* _type,
                axis2_char_t* _pvtkeyPass);

        


                /**
                 * Free adb_addKeyStore_t object and return the property value.
                 * You can use this to free the adb object as returning the property value. If there are
                 * many properties, it will only return the first property. Other properties will get freed with the adb object.
                 * @param  _addKeyStore adb_addKeyStore_t object to free
                 * @param env pointer to environment struct
                 * @return the property value holded by the ADB object, if there are many properties only returns the first.
                 */
                axis2_char_t* AXIS2_CALL
                adb_addKeyStore_free_popping_value(
                        adb_addKeyStore_t* _addKeyStore,
                        const axutil_env_t *env);
            

        /******************************* get the value by the property number  *********************************/
        /************NOTE: This method is introduced to resolve a problem in unwrapping mode *******************/

        
        

        /**
         * Getter for fileData by property number (1)
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_addKeyStore_get_property1(
            adb_addKeyStore_t* _addKeyStore,
            const axutil_env_t *env);

    
        

        /**
         * Getter for filename by property number (2)
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_addKeyStore_get_property2(
            adb_addKeyStore_t* _addKeyStore,
            const axutil_env_t *env);

    
        

        /**
         * Getter for password by property number (3)
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_addKeyStore_get_property3(
            adb_addKeyStore_t* _addKeyStore,
            const axutil_env_t *env);

    
        

        /**
         * Getter for provider by property number (4)
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_addKeyStore_get_property4(
            adb_addKeyStore_t* _addKeyStore,
            const axutil_env_t *env);

    
        

        /**
         * Getter for type by property number (5)
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_addKeyStore_get_property5(
            adb_addKeyStore_t* _addKeyStore,
            const axutil_env_t *env);

    
        

        /**
         * Getter for pvtkeyPass by property number (6)
         * @param  _addKeyStore adb_addKeyStore_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_addKeyStore_get_property6(
            adb_addKeyStore_t* _addKeyStore,
            const axutil_env_t *env);

    
     #ifdef __cplusplus
     }
     #endif

     #endif /* ADB_ADDKEYSTORE_H */
    

