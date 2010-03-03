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


        #ifndef ADB_KEYSTOREDATA_H
        #define ADB_KEYSTOREDATA_H

       /**
        * adb_KeyStoreData.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/Java version: #axisVersion# #today#
        */

       /**
        *  adb_KeyStoreData class
        */

        
          #include "adb_CertData.h"
          
          #include "adb_CertData.h"
          

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
        

        typedef struct adb_KeyStoreData adb_KeyStoreData_t;

        
        

        /******************************* Create and Free functions *********************************/

        /**
         * Constructor for creating adb_KeyStoreData_t
         * @param env pointer to environment struct
         * @return newly created adb_KeyStoreData_t object
         */
        adb_KeyStoreData_t* AXIS2_CALL
        adb_KeyStoreData_create(
            const axutil_env_t *env );

        /**
         * Wrapper for the "free" function, will invoke the extension mapper instead
         * @param  _KeyStoreData adb_KeyStoreData_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_KeyStoreData_free (
            adb_KeyStoreData_t* _KeyStoreData,
            const axutil_env_t *env);

        /**
         * Free adb_KeyStoreData_t object
         * @param  _KeyStoreData adb_KeyStoreData_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_KeyStoreData_free_obj (
            adb_KeyStoreData_t* _KeyStoreData,
            const axutil_env_t *env);



        /********************************** Getters and Setters **************************************/
        /******** Deprecated for array types, Use 'Getters and Setters for Arrays' instead ***********/
        

        /**
         * Getter for certs. Deprecated for array types, Use adb_KeyStoreData_get_certs_at instead
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @return Array of adb_CertData_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_KeyStoreData_get_certs(
            adb_KeyStoreData_t* _KeyStoreData,
            const axutil_env_t *env);

        /**
         * Setter for certs.Deprecated for array types, Use adb_KeyStoreData_set_certs_at
         * or adb_KeyStoreData_add_certs instead.
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @param arg_certs Array of adb_CertData_t*s.
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_KeyStoreData_set_certs(
            adb_KeyStoreData_t* _KeyStoreData,
            const axutil_env_t *env,
            axutil_array_list_t*  arg_certs);

        /**
         * Resetter for certs
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_KeyStoreData_reset_certs(
            adb_KeyStoreData_t* _KeyStoreData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for key. 
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @return adb_CertData_t*
         */
        adb_CertData_t* AXIS2_CALL
        adb_KeyStoreData_get_key(
            adb_KeyStoreData_t* _KeyStoreData,
            const axutil_env_t *env);

        /**
         * Setter for key.
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @param arg_key adb_CertData_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_KeyStoreData_set_key(
            adb_KeyStoreData_t* _KeyStoreData,
            const axutil_env_t *env,
            adb_CertData_t*  arg_key);

        /**
         * Resetter for key
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_KeyStoreData_reset_key(
            adb_KeyStoreData_t* _KeyStoreData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for keyStoreName. 
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_KeyStoreData_get_keyStoreName(
            adb_KeyStoreData_t* _KeyStoreData,
            const axutil_env_t *env);

        /**
         * Setter for keyStoreName.
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @param arg_keyStoreName axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_KeyStoreData_set_keyStoreName(
            adb_KeyStoreData_t* _KeyStoreData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_keyStoreName);

        /**
         * Resetter for keyStoreName
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_KeyStoreData_reset_keyStoreName(
            adb_KeyStoreData_t* _KeyStoreData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for keyStoreType. 
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_KeyStoreData_get_keyStoreType(
            adb_KeyStoreData_t* _KeyStoreData,
            const axutil_env_t *env);

        /**
         * Setter for keyStoreType.
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @param arg_keyStoreType axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_KeyStoreData_set_keyStoreType(
            adb_KeyStoreData_t* _KeyStoreData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_keyStoreType);

        /**
         * Resetter for keyStoreType
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_KeyStoreData_reset_keyStoreType(
            adb_KeyStoreData_t* _KeyStoreData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for keyValue. 
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_KeyStoreData_get_keyValue(
            adb_KeyStoreData_t* _KeyStoreData,
            const axutil_env_t *env);

        /**
         * Setter for keyValue.
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @param arg_keyValue axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_KeyStoreData_set_keyValue(
            adb_KeyStoreData_t* _KeyStoreData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_keyValue);

        /**
         * Resetter for keyValue
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_KeyStoreData_reset_keyValue(
            adb_KeyStoreData_t* _KeyStoreData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for privateStore. 
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_KeyStoreData_get_privateStore(
            adb_KeyStoreData_t* _KeyStoreData,
            const axutil_env_t *env);

        /**
         * Setter for privateStore.
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @param arg_privateStore axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_KeyStoreData_set_privateStore(
            adb_KeyStoreData_t* _KeyStoreData,
            const axutil_env_t *env,
            axis2_bool_t  arg_privateStore);

        /**
         * Resetter for privateStore
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_KeyStoreData_reset_privateStore(
            adb_KeyStoreData_t* _KeyStoreData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for provider. 
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_KeyStoreData_get_provider(
            adb_KeyStoreData_t* _KeyStoreData,
            const axutil_env_t *env);

        /**
         * Setter for provider.
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @param arg_provider axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_KeyStoreData_set_provider(
            adb_KeyStoreData_t* _KeyStoreData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_provider);

        /**
         * Resetter for provider
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_KeyStoreData_reset_provider(
            adb_KeyStoreData_t* _KeyStoreData,
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
         * Get the ith element of certs.
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @return ith adb_CertData_t* of the array
         */
        adb_CertData_t* AXIS2_CALL
        adb_KeyStoreData_get_certs_at(
                adb_KeyStoreData_t* _KeyStoreData,
                const axutil_env_t *env, int i);

        /**
         * Set the ith element of certs. (If the ith already exist, it will be replaced)
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @param arg_certs element to set adb_CertData_t* to the array
         * @return ith adb_CertData_t* of the array
         */
        axis2_status_t AXIS2_CALL
        adb_KeyStoreData_set_certs_at(
                adb_KeyStoreData_t* _KeyStoreData,
                const axutil_env_t *env, int i,
                adb_CertData_t* arg_certs);


        /**
         * Add to certs.
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @param arg_certs element to add adb_CertData_t* to the array
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_KeyStoreData_add_certs(
                adb_KeyStoreData_t* _KeyStoreData,
                const axutil_env_t *env,
                adb_CertData_t* arg_certs);

        /**
         * Get the size of the certs array.
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct.
         * @return the size of the certs array.
         */
        int AXIS2_CALL
        adb_KeyStoreData_sizeof_certs(
                    adb_KeyStoreData_t* _KeyStoreData,
                    const axutil_env_t *env);

        /**
         * Remove the ith element of certs.
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @param i index of the item to remove
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_KeyStoreData_remove_certs_at(
                adb_KeyStoreData_t* _KeyStoreData,
                const axutil_env_t *env, int i);

        


        /******************************* Checking and Setting NIL values *********************************/
        /* Use 'Checking and Setting NIL values for Arrays' to check and set nil for individual elements */

        /**
         * NOTE: set_nil is only available for nillable properties
         */

        

        /**
         * Check whether certs is nill
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_KeyStoreData_is_certs_nil(
                adb_KeyStoreData_t* _KeyStoreData,
                const axutil_env_t *env);


        
        /**
         * Set certs to nill (currently the same as reset)
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_KeyStoreData_set_certs_nil(
                adb_KeyStoreData_t* _KeyStoreData,
                const axutil_env_t *env);
        

        /**
         * Check whether key is nill
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_KeyStoreData_is_key_nil(
                adb_KeyStoreData_t* _KeyStoreData,
                const axutil_env_t *env);


        
        /**
         * Set key to nill (currently the same as reset)
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_KeyStoreData_set_key_nil(
                adb_KeyStoreData_t* _KeyStoreData,
                const axutil_env_t *env);
        

        /**
         * Check whether keyStoreName is nill
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_KeyStoreData_is_keyStoreName_nil(
                adb_KeyStoreData_t* _KeyStoreData,
                const axutil_env_t *env);


        
        /**
         * Set keyStoreName to nill (currently the same as reset)
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_KeyStoreData_set_keyStoreName_nil(
                adb_KeyStoreData_t* _KeyStoreData,
                const axutil_env_t *env);
        

        /**
         * Check whether keyStoreType is nill
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_KeyStoreData_is_keyStoreType_nil(
                adb_KeyStoreData_t* _KeyStoreData,
                const axutil_env_t *env);


        
        /**
         * Set keyStoreType to nill (currently the same as reset)
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_KeyStoreData_set_keyStoreType_nil(
                adb_KeyStoreData_t* _KeyStoreData,
                const axutil_env_t *env);
        

        /**
         * Check whether keyValue is nill
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_KeyStoreData_is_keyValue_nil(
                adb_KeyStoreData_t* _KeyStoreData,
                const axutil_env_t *env);


        
        /**
         * Set keyValue to nill (currently the same as reset)
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_KeyStoreData_set_keyValue_nil(
                adb_KeyStoreData_t* _KeyStoreData,
                const axutil_env_t *env);
        

        /**
         * Check whether privateStore is nill
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_KeyStoreData_is_privateStore_nil(
                adb_KeyStoreData_t* _KeyStoreData,
                const axutil_env_t *env);


        

        /**
         * Check whether provider is nill
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_KeyStoreData_is_provider_nil(
                adb_KeyStoreData_t* _KeyStoreData,
                const axutil_env_t *env);


        
        /**
         * Set provider to nill (currently the same as reset)
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_KeyStoreData_set_provider_nil(
                adb_KeyStoreData_t* _KeyStoreData,
                const axutil_env_t *env);
        
        /*************************** Checking and Setting 'NIL' values in Arrays *****************************/

        /**
         * NOTE: You may set this to remove specific elements in the array
         *       But you can not remove elements, if the specific property is declared to be non-nillable or sizeof(array) < minOccurs
         */
        
        /**
         * Check whether certs is nill at i
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct.
         * @param i index of the item to return.
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_KeyStoreData_is_certs_nil_at(
                adb_KeyStoreData_t* _KeyStoreData,
                const axutil_env_t *env, int i);
 
       
        /**
         * Set certs to nill at i
         * @param  _KeyStoreData _ adb_KeyStoreData_t object
         * @param env pointer to environment struct.
         * @param i index of the item to set.
         * @return AXIS2_SUCCESS on success, or AXIS2_FAILURE otherwise.
         */
        axis2_status_t AXIS2_CALL
        adb_KeyStoreData_set_certs_nil_at(
                adb_KeyStoreData_t* _KeyStoreData, 
                const axutil_env_t *env, int i);

        

        /**************************** Serialize and Deserialize functions ***************************/
        /*********** These functions are for use only inside the generated code *********************/

        
        /**
         * Wrapper for the deserialization function, will invoke the extension mapper instead
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs, 
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_KeyStoreData_deserialize(
            adb_KeyStoreData_t* _KeyStoreData,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);

        /**
         * Deserialize an XML to adb objects
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs,
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_KeyStoreData_deserialize_obj(
            adb_KeyStoreData_t* _KeyStoreData,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);
                            
            

       /**
         * Declare namespace in the most parent node 
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @param parent_element parent element
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index pointer to an int which contain the next namespace index
         */
       void AXIS2_CALL
       adb_KeyStoreData_declare_parent_namespaces(
                    adb_KeyStoreData_t* _KeyStoreData,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index);

        

        /**
         * Wrapper for the serialization function, will invoke the extension mapper instead
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @param KeyStoreData_om_node node to serialize from
         * @param KeyStoreData_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_KeyStoreData_serialize(
            adb_KeyStoreData_t* _KeyStoreData,
            const axutil_env_t *env,
            axiom_node_t* KeyStoreData_om_node, axiom_element_t *KeyStoreData_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Serialize to an XML from the adb objects
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @param KeyStoreData_om_node node to serialize from
         * @param KeyStoreData_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_KeyStoreData_serialize_obj(
            adb_KeyStoreData_t* _KeyStoreData,
            const axutil_env_t *env,
            axiom_node_t* KeyStoreData_om_node, axiom_element_t *KeyStoreData_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Check whether the adb_KeyStoreData is a particle class (E.g. group, inner sequence)
         * @return whether this is a particle class.
         */
        axis2_bool_t AXIS2_CALL
        adb_KeyStoreData_is_particle();

        /******************************* Alternatives for Create and Free functions *********************************/

        

        /**
         * Constructor for creating adb_KeyStoreData_t
         * @param env pointer to environment struct
         * @param _certs axutil_array_list_t*
         * @param _key adb_CertData_t*
         * @param _keyStoreName axis2_char_t*
         * @param _keyStoreType axis2_char_t*
         * @param _keyValue axis2_char_t*
         * @param _privateStore axis2_bool_t
         * @param _provider axis2_char_t*
         * @return newly created adb_KeyStoreData_t object
         */
        adb_KeyStoreData_t* AXIS2_CALL
        adb_KeyStoreData_create_with_values(
            const axutil_env_t *env,
                axutil_array_list_t* _certs,
                adb_CertData_t* _key,
                axis2_char_t* _keyStoreName,
                axis2_char_t* _keyStoreType,
                axis2_char_t* _keyValue,
                axis2_bool_t _privateStore,
                axis2_char_t* _provider);

        


                /**
                 * Free adb_KeyStoreData_t object and return the property value.
                 * You can use this to free the adb object as returning the property value. If there are
                 * many properties, it will only return the first property. Other properties will get freed with the adb object.
                 * @param  _KeyStoreData adb_KeyStoreData_t object to free
                 * @param env pointer to environment struct
                 * @return the property value holded by the ADB object, if there are many properties only returns the first.
                 */
                axutil_array_list_t* AXIS2_CALL
                adb_KeyStoreData_free_popping_value(
                        adb_KeyStoreData_t* _KeyStoreData,
                        const axutil_env_t *env);
            

        /******************************* get the value by the property number  *********************************/
        /************NOTE: This method is introduced to resolve a problem in unwrapping mode *******************/

        
        

        /**
         * Getter for certs by property number (1)
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @return Array of adb_CertData_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_KeyStoreData_get_property1(
            adb_KeyStoreData_t* _KeyStoreData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for key by property number (2)
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @return adb_CertData_t*
         */
        adb_CertData_t* AXIS2_CALL
        adb_KeyStoreData_get_property2(
            adb_KeyStoreData_t* _KeyStoreData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for keyStoreName by property number (3)
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_KeyStoreData_get_property3(
            adb_KeyStoreData_t* _KeyStoreData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for keyStoreType by property number (4)
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_KeyStoreData_get_property4(
            adb_KeyStoreData_t* _KeyStoreData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for keyValue by property number (5)
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_KeyStoreData_get_property5(
            adb_KeyStoreData_t* _KeyStoreData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for privateStore by property number (6)
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_KeyStoreData_get_property6(
            adb_KeyStoreData_t* _KeyStoreData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for provider by property number (7)
         * @param  _KeyStoreData adb_KeyStoreData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_KeyStoreData_get_property7(
            adb_KeyStoreData_t* _KeyStoreData,
            const axutil_env_t *env);

    
     #ifdef __cplusplus
     }
     #endif

     #endif /* ADB_KEYSTOREDATA_H */
    

