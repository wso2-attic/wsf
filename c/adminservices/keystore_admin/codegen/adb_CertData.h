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


        #ifndef ADB_CERTDATA_H
        #define ADB_CERTDATA_H

       /**
        * adb_CertData.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/Java version: #axisVersion# #today#
        */

       /**
        *  adb_CertData class
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
        

        typedef struct adb_CertData adb_CertData_t;

        
        

        /******************************* Create and Free functions *********************************/

        /**
         * Constructor for creating adb_CertData_t
         * @param env pointer to environment struct
         * @return newly created adb_CertData_t object
         */
        adb_CertData_t* AXIS2_CALL
        adb_CertData_create(
            const axutil_env_t *env );

        /**
         * Wrapper for the "free" function, will invoke the extension mapper instead
         * @param  _CertData adb_CertData_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CertData_free (
            adb_CertData_t* _CertData,
            const axutil_env_t *env);

        /**
         * Free adb_CertData_t object
         * @param  _CertData adb_CertData_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CertData_free_obj (
            adb_CertData_t* _CertData,
            const axutil_env_t *env);



        /********************************** Getters and Setters **************************************/
        
        

        /**
         * Getter for alias. 
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_CertData_get_alias(
            adb_CertData_t* _CertData,
            const axutil_env_t *env);

        /**
         * Setter for alias.
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @param arg_alias axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CertData_set_alias(
            adb_CertData_t* _CertData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_alias);

        /**
         * Resetter for alias
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CertData_reset_alias(
            adb_CertData_t* _CertData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for issuerDN. 
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_CertData_get_issuerDN(
            adb_CertData_t* _CertData,
            const axutil_env_t *env);

        /**
         * Setter for issuerDN.
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @param arg_issuerDN axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CertData_set_issuerDN(
            adb_CertData_t* _CertData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_issuerDN);

        /**
         * Resetter for issuerDN
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CertData_reset_issuerDN(
            adb_CertData_t* _CertData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for notAfter. 
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_CertData_get_notAfter(
            adb_CertData_t* _CertData,
            const axutil_env_t *env);

        /**
         * Setter for notAfter.
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @param arg_notAfter axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CertData_set_notAfter(
            adb_CertData_t* _CertData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_notAfter);

        /**
         * Resetter for notAfter
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CertData_reset_notAfter(
            adb_CertData_t* _CertData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for notBefore. 
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_CertData_get_notBefore(
            adb_CertData_t* _CertData,
            const axutil_env_t *env);

        /**
         * Setter for notBefore.
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @param arg_notBefore axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CertData_set_notBefore(
            adb_CertData_t* _CertData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_notBefore);

        /**
         * Resetter for notBefore
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CertData_reset_notBefore(
            adb_CertData_t* _CertData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for publicKey. 
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_CertData_get_publicKey(
            adb_CertData_t* _CertData,
            const axutil_env_t *env);

        /**
         * Setter for publicKey.
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @param arg_publicKey axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CertData_set_publicKey(
            adb_CertData_t* _CertData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_publicKey);

        /**
         * Resetter for publicKey
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CertData_reset_publicKey(
            adb_CertData_t* _CertData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for serialNumber. 
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @return int
         */
        int AXIS2_CALL
        adb_CertData_get_serialNumber(
            adb_CertData_t* _CertData,
            const axutil_env_t *env);

        /**
         * Setter for serialNumber.
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @param arg_serialNumber int
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CertData_set_serialNumber(
            adb_CertData_t* _CertData,
            const axutil_env_t *env,
            const int  arg_serialNumber);

        /**
         * Resetter for serialNumber
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CertData_reset_serialNumber(
            adb_CertData_t* _CertData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for subjectDN. 
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_CertData_get_subjectDN(
            adb_CertData_t* _CertData,
            const axutil_env_t *env);

        /**
         * Setter for subjectDN.
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @param arg_subjectDN axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CertData_set_subjectDN(
            adb_CertData_t* _CertData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_subjectDN);

        /**
         * Resetter for subjectDN
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CertData_reset_subjectDN(
            adb_CertData_t* _CertData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for version. 
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @return int
         */
        int AXIS2_CALL
        adb_CertData_get_version(
            adb_CertData_t* _CertData,
            const axutil_env_t *env);

        /**
         * Setter for version.
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @param arg_version int
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CertData_set_version(
            adb_CertData_t* _CertData,
            const axutil_env_t *env,
            const int  arg_version);

        /**
         * Resetter for version
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CertData_reset_version(
            adb_CertData_t* _CertData,
            const axutil_env_t *env);

        


        /******************************* Checking and Setting NIL values *********************************/
        

        /**
         * NOTE: set_nil is only available for nillable properties
         */

        

        /**
         * Check whether alias is nill
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_CertData_is_alias_nil(
                adb_CertData_t* _CertData,
                const axutil_env_t *env);


        
        /**
         * Set alias to nill (currently the same as reset)
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CertData_set_alias_nil(
                adb_CertData_t* _CertData,
                const axutil_env_t *env);
        

        /**
         * Check whether issuerDN is nill
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_CertData_is_issuerDN_nil(
                adb_CertData_t* _CertData,
                const axutil_env_t *env);


        
        /**
         * Set issuerDN to nill (currently the same as reset)
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CertData_set_issuerDN_nil(
                adb_CertData_t* _CertData,
                const axutil_env_t *env);
        

        /**
         * Check whether notAfter is nill
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_CertData_is_notAfter_nil(
                adb_CertData_t* _CertData,
                const axutil_env_t *env);


        
        /**
         * Set notAfter to nill (currently the same as reset)
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CertData_set_notAfter_nil(
                adb_CertData_t* _CertData,
                const axutil_env_t *env);
        

        /**
         * Check whether notBefore is nill
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_CertData_is_notBefore_nil(
                adb_CertData_t* _CertData,
                const axutil_env_t *env);


        
        /**
         * Set notBefore to nill (currently the same as reset)
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CertData_set_notBefore_nil(
                adb_CertData_t* _CertData,
                const axutil_env_t *env);
        

        /**
         * Check whether publicKey is nill
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_CertData_is_publicKey_nil(
                adb_CertData_t* _CertData,
                const axutil_env_t *env);


        
        /**
         * Set publicKey to nill (currently the same as reset)
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CertData_set_publicKey_nil(
                adb_CertData_t* _CertData,
                const axutil_env_t *env);
        

        /**
         * Check whether serialNumber is nill
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_CertData_is_serialNumber_nil(
                adb_CertData_t* _CertData,
                const axutil_env_t *env);


        
        /**
         * Set serialNumber to nill (currently the same as reset)
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CertData_set_serialNumber_nil(
                adb_CertData_t* _CertData,
                const axutil_env_t *env);
        

        /**
         * Check whether subjectDN is nill
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_CertData_is_subjectDN_nil(
                adb_CertData_t* _CertData,
                const axutil_env_t *env);


        
        /**
         * Set subjectDN to nill (currently the same as reset)
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CertData_set_subjectDN_nil(
                adb_CertData_t* _CertData,
                const axutil_env_t *env);
        

        /**
         * Check whether version is nill
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_CertData_is_version_nil(
                adb_CertData_t* _CertData,
                const axutil_env_t *env);


        

        /**************************** Serialize and Deserialize functions ***************************/
        /*********** These functions are for use only inside the generated code *********************/

        
        /**
         * Wrapper for the deserialization function, will invoke the extension mapper instead
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs, 
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CertData_deserialize(
            adb_CertData_t* _CertData,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);

        /**
         * Deserialize an XML to adb objects
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs,
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_CertData_deserialize_obj(
            adb_CertData_t* _CertData,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);
                            
            

       /**
         * Declare namespace in the most parent node 
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @param parent_element parent element
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index pointer to an int which contain the next namespace index
         */
       void AXIS2_CALL
       adb_CertData_declare_parent_namespaces(
                    adb_CertData_t* _CertData,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index);

        

        /**
         * Wrapper for the serialization function, will invoke the extension mapper instead
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @param CertData_om_node node to serialize from
         * @param CertData_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_CertData_serialize(
            adb_CertData_t* _CertData,
            const axutil_env_t *env,
            axiom_node_t* CertData_om_node, axiom_element_t *CertData_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Serialize to an XML from the adb objects
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @param CertData_om_node node to serialize from
         * @param CertData_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_CertData_serialize_obj(
            adb_CertData_t* _CertData,
            const axutil_env_t *env,
            axiom_node_t* CertData_om_node, axiom_element_t *CertData_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Check whether the adb_CertData is a particle class (E.g. group, inner sequence)
         * @return whether this is a particle class.
         */
        axis2_bool_t AXIS2_CALL
        adb_CertData_is_particle();

        /******************************* Alternatives for Create and Free functions *********************************/

        

        /**
         * Constructor for creating adb_CertData_t
         * @param env pointer to environment struct
         * @param _alias axis2_char_t*
         * @param _issuerDN axis2_char_t*
         * @param _notAfter axis2_char_t*
         * @param _notBefore axis2_char_t*
         * @param _publicKey axis2_char_t*
         * @param _serialNumber int
         * @param _subjectDN axis2_char_t*
         * @param _version int
         * @return newly created adb_CertData_t object
         */
        adb_CertData_t* AXIS2_CALL
        adb_CertData_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _alias,
                axis2_char_t* _issuerDN,
                axis2_char_t* _notAfter,
                axis2_char_t* _notBefore,
                axis2_char_t* _publicKey,
                int _serialNumber,
                axis2_char_t* _subjectDN,
                int _version);

        


                /**
                 * Free adb_CertData_t object and return the property value.
                 * You can use this to free the adb object as returning the property value. If there are
                 * many properties, it will only return the first property. Other properties will get freed with the adb object.
                 * @param  _CertData adb_CertData_t object to free
                 * @param env pointer to environment struct
                 * @return the property value holded by the ADB object, if there are many properties only returns the first.
                 */
                axis2_char_t* AXIS2_CALL
                adb_CertData_free_popping_value(
                        adb_CertData_t* _CertData,
                        const axutil_env_t *env);
            

        /******************************* get the value by the property number  *********************************/
        /************NOTE: This method is introduced to resolve a problem in unwrapping mode *******************/

        
        

        /**
         * Getter for alias by property number (1)
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_CertData_get_property1(
            adb_CertData_t* _CertData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for issuerDN by property number (2)
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_CertData_get_property2(
            adb_CertData_t* _CertData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for notAfter by property number (3)
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_CertData_get_property3(
            adb_CertData_t* _CertData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for notBefore by property number (4)
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_CertData_get_property4(
            adb_CertData_t* _CertData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for publicKey by property number (5)
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_CertData_get_property5(
            adb_CertData_t* _CertData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for serialNumber by property number (6)
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @return int
         */
        int AXIS2_CALL
        adb_CertData_get_property6(
            adb_CertData_t* _CertData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for subjectDN by property number (7)
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_CertData_get_property7(
            adb_CertData_t* _CertData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for version by property number (8)
         * @param  _CertData adb_CertData_t object
         * @param env pointer to environment struct
         * @return int
         */
        int AXIS2_CALL
        adb_CertData_get_property8(
            adb_CertData_t* _CertData,
            const axutil_env_t *env);

    
     #ifdef __cplusplus
     }
     #endif

     #endif /* ADB_CERTDATA_H */
    

