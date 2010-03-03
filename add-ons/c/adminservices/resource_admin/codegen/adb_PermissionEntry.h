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


        #ifndef ADB_PERMISSIONENTRY_H
        #define ADB_PERMISSIONENTRY_H

       /**
        * adb_PermissionEntry.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/Java version: #axisVersion# #today#
        */

       /**
        *  adb_PermissionEntry class
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
        

        typedef struct adb_PermissionEntry adb_PermissionEntry_t;

        
        

        /******************************* Create and Free functions *********************************/

        /**
         * Constructor for creating adb_PermissionEntry_t
         * @param env pointer to environment struct
         * @return newly created adb_PermissionEntry_t object
         */
        adb_PermissionEntry_t* AXIS2_CALL
        adb_PermissionEntry_create(
            const axutil_env_t *env );

        /**
         * Wrapper for the "free" function, will invoke the extension mapper instead
         * @param  _PermissionEntry adb_PermissionEntry_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionEntry_free (
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env);

        /**
         * Free adb_PermissionEntry_t object
         * @param  _PermissionEntry adb_PermissionEntry_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionEntry_free_obj (
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env);



        /********************************** Getters and Setters **************************************/
        
        

        /**
         * Getter for authorizeAllow. 
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionEntry_get_authorizeAllow(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env);

        /**
         * Setter for authorizeAllow.
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @param arg_authorizeAllow axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionEntry_set_authorizeAllow(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env,
            axis2_bool_t  arg_authorizeAllow);

        /**
         * Resetter for authorizeAllow
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionEntry_reset_authorizeAllow(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env);

        
        

        /**
         * Getter for authorizeDeny. 
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionEntry_get_authorizeDeny(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env);

        /**
         * Setter for authorizeDeny.
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @param arg_authorizeDeny axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionEntry_set_authorizeDeny(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env,
            axis2_bool_t  arg_authorizeDeny);

        /**
         * Resetter for authorizeDeny
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionEntry_reset_authorizeDeny(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env);

        
        

        /**
         * Getter for deleteAllow. 
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionEntry_get_deleteAllow(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env);

        /**
         * Setter for deleteAllow.
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @param arg_deleteAllow axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionEntry_set_deleteAllow(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env,
            axis2_bool_t  arg_deleteAllow);

        /**
         * Resetter for deleteAllow
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionEntry_reset_deleteAllow(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env);

        
        

        /**
         * Getter for deleteDeny. 
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionEntry_get_deleteDeny(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env);

        /**
         * Setter for deleteDeny.
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @param arg_deleteDeny axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionEntry_set_deleteDeny(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env,
            axis2_bool_t  arg_deleteDeny);

        /**
         * Resetter for deleteDeny
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionEntry_reset_deleteDeny(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env);

        
        

        /**
         * Getter for readAllow. 
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionEntry_get_readAllow(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env);

        /**
         * Setter for readAllow.
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @param arg_readAllow axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionEntry_set_readAllow(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env,
            axis2_bool_t  arg_readAllow);

        /**
         * Resetter for readAllow
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionEntry_reset_readAllow(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env);

        
        

        /**
         * Getter for readDeny. 
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionEntry_get_readDeny(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env);

        /**
         * Setter for readDeny.
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @param arg_readDeny axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionEntry_set_readDeny(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env,
            axis2_bool_t  arg_readDeny);

        /**
         * Resetter for readDeny
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionEntry_reset_readDeny(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env);

        
        

        /**
         * Getter for userName. 
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_PermissionEntry_get_userName(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env);

        /**
         * Setter for userName.
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @param arg_userName axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionEntry_set_userName(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env,
            const axis2_char_t*  arg_userName);

        /**
         * Resetter for userName
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionEntry_reset_userName(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env);

        
        

        /**
         * Getter for writeAllow. 
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionEntry_get_writeAllow(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env);

        /**
         * Setter for writeAllow.
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @param arg_writeAllow axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionEntry_set_writeAllow(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env,
            axis2_bool_t  arg_writeAllow);

        /**
         * Resetter for writeAllow
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionEntry_reset_writeAllow(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env);

        
        

        /**
         * Getter for writeDeny. 
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionEntry_get_writeDeny(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env);

        /**
         * Setter for writeDeny.
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @param arg_writeDeny axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionEntry_set_writeDeny(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env,
            axis2_bool_t  arg_writeDeny);

        /**
         * Resetter for writeDeny
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionEntry_reset_writeDeny(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env);

        


        /******************************* Checking and Setting NIL values *********************************/
        

        /**
         * NOTE: set_nil is only available for nillable properties
         */

        

        /**
         * Check whether authorizeAllow is nill
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionEntry_is_authorizeAllow_nil(
                adb_PermissionEntry_t* _PermissionEntry,
                const axutil_env_t *env);


        

        /**
         * Check whether authorizeDeny is nill
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionEntry_is_authorizeDeny_nil(
                adb_PermissionEntry_t* _PermissionEntry,
                const axutil_env_t *env);


        

        /**
         * Check whether deleteAllow is nill
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionEntry_is_deleteAllow_nil(
                adb_PermissionEntry_t* _PermissionEntry,
                const axutil_env_t *env);


        

        /**
         * Check whether deleteDeny is nill
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionEntry_is_deleteDeny_nil(
                adb_PermissionEntry_t* _PermissionEntry,
                const axutil_env_t *env);


        

        /**
         * Check whether readAllow is nill
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionEntry_is_readAllow_nil(
                adb_PermissionEntry_t* _PermissionEntry,
                const axutil_env_t *env);


        

        /**
         * Check whether readDeny is nill
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionEntry_is_readDeny_nil(
                adb_PermissionEntry_t* _PermissionEntry,
                const axutil_env_t *env);


        

        /**
         * Check whether userName is nill
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionEntry_is_userName_nil(
                adb_PermissionEntry_t* _PermissionEntry,
                const axutil_env_t *env);


        
        /**
         * Set userName to nill (currently the same as reset)
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionEntry_set_userName_nil(
                adb_PermissionEntry_t* _PermissionEntry,
                const axutil_env_t *env);
        

        /**
         * Check whether writeAllow is nill
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionEntry_is_writeAllow_nil(
                adb_PermissionEntry_t* _PermissionEntry,
                const axutil_env_t *env);


        

        /**
         * Check whether writeDeny is nill
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionEntry_is_writeDeny_nil(
                adb_PermissionEntry_t* _PermissionEntry,
                const axutil_env_t *env);


        

        /**************************** Serialize and Deserialize functions ***************************/
        /*********** These functions are for use only inside the generated code *********************/

        
        /**
         * Wrapper for the deserialization function, will invoke the extension mapper instead
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs, 
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionEntry_deserialize(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);

        /**
         * Deserialize an XML to adb objects
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs,
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_PermissionEntry_deserialize_obj(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);
                            
            

       /**
         * Declare namespace in the most parent node 
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @param parent_element parent element
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index pointer to an int which contain the next namespace index
         */
       void AXIS2_CALL
       adb_PermissionEntry_declare_parent_namespaces(
                    adb_PermissionEntry_t* _PermissionEntry,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index);

        

        /**
         * Wrapper for the serialization function, will invoke the extension mapper instead
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @param PermissionEntry_om_node node to serialize from
         * @param PermissionEntry_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_PermissionEntry_serialize(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env,
            axiom_node_t* PermissionEntry_om_node, axiom_element_t *PermissionEntry_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Serialize to an XML from the adb objects
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @param PermissionEntry_om_node node to serialize from
         * @param PermissionEntry_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_PermissionEntry_serialize_obj(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env,
            axiom_node_t* PermissionEntry_om_node, axiom_element_t *PermissionEntry_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Check whether the adb_PermissionEntry is a particle class (E.g. group, inner sequence)
         * @return whether this is a particle class.
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionEntry_is_particle();

        /******************************* Alternatives for Create and Free functions *********************************/

        

        /**
         * Constructor for creating adb_PermissionEntry_t
         * @param env pointer to environment struct
         * @param _authorizeAllow axis2_bool_t
         * @param _authorizeDeny axis2_bool_t
         * @param _deleteAllow axis2_bool_t
         * @param _deleteDeny axis2_bool_t
         * @param _readAllow axis2_bool_t
         * @param _readDeny axis2_bool_t
         * @param _userName axis2_char_t*
         * @param _writeAllow axis2_bool_t
         * @param _writeDeny axis2_bool_t
         * @return newly created adb_PermissionEntry_t object
         */
        adb_PermissionEntry_t* AXIS2_CALL
        adb_PermissionEntry_create_with_values(
            const axutil_env_t *env,
                axis2_bool_t _authorizeAllow,
                axis2_bool_t _authorizeDeny,
                axis2_bool_t _deleteAllow,
                axis2_bool_t _deleteDeny,
                axis2_bool_t _readAllow,
                axis2_bool_t _readDeny,
                axis2_char_t* _userName,
                axis2_bool_t _writeAllow,
                axis2_bool_t _writeDeny);

        


                /**
                 * Free adb_PermissionEntry_t object and return the property value.
                 * You can use this to free the adb object as returning the property value. If there are
                 * many properties, it will only return the first property. Other properties will get freed with the adb object.
                 * @param  _PermissionEntry adb_PermissionEntry_t object to free
                 * @param env pointer to environment struct
                 * @return the property value holded by the ADB object, if there are many properties only returns the first.
                 */
                axis2_bool_t AXIS2_CALL
                adb_PermissionEntry_free_popping_value(
                        adb_PermissionEntry_t* _PermissionEntry,
                        const axutil_env_t *env);
            

        /******************************* get the value by the property number  *********************************/
        /************NOTE: This method is introduced to resolve a problem in unwrapping mode *******************/

        
        

        /**
         * Getter for authorizeAllow by property number (1)
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionEntry_get_property1(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env);

    
        

        /**
         * Getter for authorizeDeny by property number (2)
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionEntry_get_property2(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env);

    
        

        /**
         * Getter for deleteAllow by property number (3)
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionEntry_get_property3(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env);

    
        

        /**
         * Getter for deleteDeny by property number (4)
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionEntry_get_property4(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env);

    
        

        /**
         * Getter for readAllow by property number (5)
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionEntry_get_property5(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env);

    
        

        /**
         * Getter for readDeny by property number (6)
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionEntry_get_property6(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env);

    
        

        /**
         * Getter for userName by property number (7)
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_PermissionEntry_get_property7(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env);

    
        

        /**
         * Getter for writeAllow by property number (8)
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionEntry_get_property8(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env);

    
        

        /**
         * Getter for writeDeny by property number (9)
         * @param  _PermissionEntry adb_PermissionEntry_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_PermissionEntry_get_property9(
            adb_PermissionEntry_t* _PermissionEntry,
            const axutil_env_t *env);

    
     #ifdef __cplusplus
     }
     #endif

     #endif /* ADB_PERMISSIONENTRY_H */
    

