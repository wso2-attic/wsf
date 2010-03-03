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


        #ifndef ADB_USERREALM_H
        #define ADB_USERREALM_H

       /**
        * adb_UserRealm.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/Java version: SNAPSHOT  Built on : Jan 19, 2010 (01:47:08 IST)
        */

       /**
        *  adb_UserRealm class
        */

        
          #include "adb_AccessControlAdmin.h"
          
          #include "adb_Authenticator.h"
          
          #include "adb_Authorizer.h"
          
          #include "adb_UserClaimsAdmin.h"
          
          #include "adb_UserProfileAdmin.h"
          
          #include "adb_UserStoreAdmin.h"
          
          #include "adb_UserStoreReader.h"
          

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
        

        typedef struct adb_UserRealm adb_UserRealm_t;

        
        

        /******************************* Create and Free functions *********************************/

        /**
         * Constructor for creating adb_UserRealm_t
         * @param env pointer to environment struct
         * @return newly created adb_UserRealm_t object
         */
        adb_UserRealm_t* AXIS2_CALL
        adb_UserRealm_create(
            const axutil_env_t *env );

        /**
         * Wrapper for the "free" function, will invoke the extension mapper instead
         * @param  _UserRealm adb_UserRealm_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserRealm_free (
            adb_UserRealm_t* _UserRealm,
            const axutil_env_t *env);

        /**
         * Free adb_UserRealm_t object
         * @param  _UserRealm adb_UserRealm_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserRealm_free_obj (
            adb_UserRealm_t* _UserRealm,
            const axutil_env_t *env);



        /********************************** Getters and Setters **************************************/
        
        

        /**
         * Getter for accessControlAdmin. 
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return adb_AccessControlAdmin_t*
         */
        adb_AccessControlAdmin_t* AXIS2_CALL
        adb_UserRealm_get_accessControlAdmin(
            adb_UserRealm_t* _UserRealm,
            const axutil_env_t *env);

        /**
         * Setter for accessControlAdmin.
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @param arg_accessControlAdmin adb_AccessControlAdmin_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserRealm_set_accessControlAdmin(
            adb_UserRealm_t* _UserRealm,
            const axutil_env_t *env,
            adb_AccessControlAdmin_t*  arg_accessControlAdmin);

        /**
         * Resetter for accessControlAdmin
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserRealm_reset_accessControlAdmin(
            adb_UserRealm_t* _UserRealm,
            const axutil_env_t *env);

        
        

        /**
         * Getter for authenticator. 
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return adb_Authenticator_t*
         */
        adb_Authenticator_t* AXIS2_CALL
        adb_UserRealm_get_authenticator(
            adb_UserRealm_t* _UserRealm,
            const axutil_env_t *env);

        /**
         * Setter for authenticator.
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @param arg_authenticator adb_Authenticator_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserRealm_set_authenticator(
            adb_UserRealm_t* _UserRealm,
            const axutil_env_t *env,
            adb_Authenticator_t*  arg_authenticator);

        /**
         * Resetter for authenticator
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserRealm_reset_authenticator(
            adb_UserRealm_t* _UserRealm,
            const axutil_env_t *env);

        
        

        /**
         * Getter for authorizer. 
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return adb_Authorizer_t*
         */
        adb_Authorizer_t* AXIS2_CALL
        adb_UserRealm_get_authorizer(
            adb_UserRealm_t* _UserRealm,
            const axutil_env_t *env);

        /**
         * Setter for authorizer.
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @param arg_authorizer adb_Authorizer_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserRealm_set_authorizer(
            adb_UserRealm_t* _UserRealm,
            const axutil_env_t *env,
            adb_Authorizer_t*  arg_authorizer);

        /**
         * Resetter for authorizer
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserRealm_reset_authorizer(
            adb_UserRealm_t* _UserRealm,
            const axutil_env_t *env);

        
        

        /**
         * Getter for claimsAdmin. 
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return adb_UserClaimsAdmin_t*
         */
        adb_UserClaimsAdmin_t* AXIS2_CALL
        adb_UserRealm_get_claimsAdmin(
            adb_UserRealm_t* _UserRealm,
            const axutil_env_t *env);

        /**
         * Setter for claimsAdmin.
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @param arg_claimsAdmin adb_UserClaimsAdmin_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserRealm_set_claimsAdmin(
            adb_UserRealm_t* _UserRealm,
            const axutil_env_t *env,
            adb_UserClaimsAdmin_t*  arg_claimsAdmin);

        /**
         * Resetter for claimsAdmin
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserRealm_reset_claimsAdmin(
            adb_UserRealm_t* _UserRealm,
            const axutil_env_t *env);

        
        

        /**
         * Getter for realmConfiguration. 
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return axiom_node_t*
         */
        axiom_node_t* AXIS2_CALL
        adb_UserRealm_get_realmConfiguration(
            adb_UserRealm_t* _UserRealm,
            const axutil_env_t *env);

        /**
         * Setter for realmConfiguration.
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @param arg_realmConfiguration axiom_node_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserRealm_set_realmConfiguration(
            adb_UserRealm_t* _UserRealm,
            const axutil_env_t *env,
            axiom_node_t*  arg_realmConfiguration);

        /**
         * Resetter for realmConfiguration
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserRealm_reset_realmConfiguration(
            adb_UserRealm_t* _UserRealm,
            const axutil_env_t *env);

        
        

        /**
         * Getter for userProfileAdmin. 
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return adb_UserProfileAdmin_t*
         */
        adb_UserProfileAdmin_t* AXIS2_CALL
        adb_UserRealm_get_userProfileAdmin(
            adb_UserRealm_t* _UserRealm,
            const axutil_env_t *env);

        /**
         * Setter for userProfileAdmin.
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @param arg_userProfileAdmin adb_UserProfileAdmin_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserRealm_set_userProfileAdmin(
            adb_UserRealm_t* _UserRealm,
            const axutil_env_t *env,
            adb_UserProfileAdmin_t*  arg_userProfileAdmin);

        /**
         * Resetter for userProfileAdmin
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserRealm_reset_userProfileAdmin(
            adb_UserRealm_t* _UserRealm,
            const axutil_env_t *env);

        
        

        /**
         * Getter for userStoreAdmin. 
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return adb_UserStoreAdmin_t*
         */
        adb_UserStoreAdmin_t* AXIS2_CALL
        adb_UserRealm_get_userStoreAdmin(
            adb_UserRealm_t* _UserRealm,
            const axutil_env_t *env);

        /**
         * Setter for userStoreAdmin.
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @param arg_userStoreAdmin adb_UserStoreAdmin_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserRealm_set_userStoreAdmin(
            adb_UserRealm_t* _UserRealm,
            const axutil_env_t *env,
            adb_UserStoreAdmin_t*  arg_userStoreAdmin);

        /**
         * Resetter for userStoreAdmin
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserRealm_reset_userStoreAdmin(
            adb_UserRealm_t* _UserRealm,
            const axutil_env_t *env);

        
        

        /**
         * Getter for userStoreReader. 
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return adb_UserStoreReader_t*
         */
        adb_UserStoreReader_t* AXIS2_CALL
        adb_UserRealm_get_userStoreReader(
            adb_UserRealm_t* _UserRealm,
            const axutil_env_t *env);

        /**
         * Setter for userStoreReader.
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @param arg_userStoreReader adb_UserStoreReader_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserRealm_set_userStoreReader(
            adb_UserRealm_t* _UserRealm,
            const axutil_env_t *env,
            adb_UserStoreReader_t*  arg_userStoreReader);

        /**
         * Resetter for userStoreReader
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserRealm_reset_userStoreReader(
            adb_UserRealm_t* _UserRealm,
            const axutil_env_t *env);

        


        /******************************* Checking and Setting NIL values *********************************/
        

        /**
         * NOTE: set_nil is only available for nillable properties
         */

        

        /**
         * Check whether accessControlAdmin is nill
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_UserRealm_is_accessControlAdmin_nil(
                adb_UserRealm_t* _UserRealm,
                const axutil_env_t *env);


        
        /**
         * Set accessControlAdmin to nill (currently the same as reset)
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserRealm_set_accessControlAdmin_nil(
                adb_UserRealm_t* _UserRealm,
                const axutil_env_t *env);
        

        /**
         * Check whether authenticator is nill
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_UserRealm_is_authenticator_nil(
                adb_UserRealm_t* _UserRealm,
                const axutil_env_t *env);


        
        /**
         * Set authenticator to nill (currently the same as reset)
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserRealm_set_authenticator_nil(
                adb_UserRealm_t* _UserRealm,
                const axutil_env_t *env);
        

        /**
         * Check whether authorizer is nill
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_UserRealm_is_authorizer_nil(
                adb_UserRealm_t* _UserRealm,
                const axutil_env_t *env);


        
        /**
         * Set authorizer to nill (currently the same as reset)
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserRealm_set_authorizer_nil(
                adb_UserRealm_t* _UserRealm,
                const axutil_env_t *env);
        

        /**
         * Check whether claimsAdmin is nill
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_UserRealm_is_claimsAdmin_nil(
                adb_UserRealm_t* _UserRealm,
                const axutil_env_t *env);


        
        /**
         * Set claimsAdmin to nill (currently the same as reset)
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserRealm_set_claimsAdmin_nil(
                adb_UserRealm_t* _UserRealm,
                const axutil_env_t *env);
        

        /**
         * Check whether realmConfiguration is nill
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_UserRealm_is_realmConfiguration_nil(
                adb_UserRealm_t* _UserRealm,
                const axutil_env_t *env);


        
        /**
         * Set realmConfiguration to nill (currently the same as reset)
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserRealm_set_realmConfiguration_nil(
                adb_UserRealm_t* _UserRealm,
                const axutil_env_t *env);
        

        /**
         * Check whether userProfileAdmin is nill
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_UserRealm_is_userProfileAdmin_nil(
                adb_UserRealm_t* _UserRealm,
                const axutil_env_t *env);


        
        /**
         * Set userProfileAdmin to nill (currently the same as reset)
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserRealm_set_userProfileAdmin_nil(
                adb_UserRealm_t* _UserRealm,
                const axutil_env_t *env);
        

        /**
         * Check whether userStoreAdmin is nill
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_UserRealm_is_userStoreAdmin_nil(
                adb_UserRealm_t* _UserRealm,
                const axutil_env_t *env);


        
        /**
         * Set userStoreAdmin to nill (currently the same as reset)
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserRealm_set_userStoreAdmin_nil(
                adb_UserRealm_t* _UserRealm,
                const axutil_env_t *env);
        

        /**
         * Check whether userStoreReader is nill
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_UserRealm_is_userStoreReader_nil(
                adb_UserRealm_t* _UserRealm,
                const axutil_env_t *env);


        
        /**
         * Set userStoreReader to nill (currently the same as reset)
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserRealm_set_userStoreReader_nil(
                adb_UserRealm_t* _UserRealm,
                const axutil_env_t *env);
        

        /**************************** Serialize and Deserialize functions ***************************/
        /*********** These functions are for use only inside the generated code *********************/

        
        /**
         * Wrapper for the deserialization function, will invoke the extension mapper instead
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs, 
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserRealm_deserialize(
            adb_UserRealm_t* _UserRealm,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);

        /**
         * Deserialize an XML to adb objects
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs,
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserRealm_deserialize_obj(
            adb_UserRealm_t* _UserRealm,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);
                            
            

       /**
         * Declare namespace in the most parent node 
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @param parent_element parent element
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index pointer to an int which contain the next namespace index
         */
       void AXIS2_CALL
       adb_UserRealm_declare_parent_namespaces(
                    adb_UserRealm_t* _UserRealm,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index);

        

        /**
         * Wrapper for the serialization function, will invoke the extension mapper instead
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @param UserRealm_om_node node to serialize from
         * @param UserRealm_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_UserRealm_serialize(
            adb_UserRealm_t* _UserRealm,
            const axutil_env_t *env,
            axiom_node_t* UserRealm_om_node, axiom_element_t *UserRealm_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Serialize to an XML from the adb objects
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @param UserRealm_om_node node to serialize from
         * @param UserRealm_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_UserRealm_serialize_obj(
            adb_UserRealm_t* _UserRealm,
            const axutil_env_t *env,
            axiom_node_t* UserRealm_om_node, axiom_element_t *UserRealm_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Check whether the adb_UserRealm is a particle class (E.g. group, inner sequence)
         * @return whether this is a particle class.
         */
        axis2_bool_t AXIS2_CALL
        adb_UserRealm_is_particle();

        /******************************* Alternatives for Create and Free functions *********************************/

        

        /**
         * Constructor for creating adb_UserRealm_t
         * @param env pointer to environment struct
         * @param _accessControlAdmin adb_AccessControlAdmin_t*
         * @param _authenticator adb_Authenticator_t*
         * @param _authorizer adb_Authorizer_t*
         * @param _claimsAdmin adb_UserClaimsAdmin_t*
         * @param _realmConfiguration axiom_node_t*
         * @param _userProfileAdmin adb_UserProfileAdmin_t*
         * @param _userStoreAdmin adb_UserStoreAdmin_t*
         * @param _userStoreReader adb_UserStoreReader_t*
         * @return newly created adb_UserRealm_t object
         */
        adb_UserRealm_t* AXIS2_CALL
        adb_UserRealm_create_with_values(
            const axutil_env_t *env,
                adb_AccessControlAdmin_t* _accessControlAdmin,
                adb_Authenticator_t* _authenticator,
                adb_Authorizer_t* _authorizer,
                adb_UserClaimsAdmin_t* _claimsAdmin,
                axiom_node_t* _realmConfiguration,
                adb_UserProfileAdmin_t* _userProfileAdmin,
                adb_UserStoreAdmin_t* _userStoreAdmin,
                adb_UserStoreReader_t* _userStoreReader);

        


                /**
                 * Free adb_UserRealm_t object and return the property value.
                 * You can use this to free the adb object as returning the property value. If there are
                 * many properties, it will only return the first property. Other properties will get freed with the adb object.
                 * @param  _UserRealm adb_UserRealm_t object to free
                 * @param env pointer to environment struct
                 * @return the property value holded by the ADB object, if there are many properties only returns the first.
                 */
                adb_AccessControlAdmin_t* AXIS2_CALL
                adb_UserRealm_free_popping_value(
                        adb_UserRealm_t* _UserRealm,
                        const axutil_env_t *env);
            

        /******************************* get the value by the property number  *********************************/
        /************NOTE: This method is introduced to resolve a problem in unwrapping mode *******************/

        
        

        /**
         * Getter for accessControlAdmin by property number (1)
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return adb_AccessControlAdmin_t*
         */
        adb_AccessControlAdmin_t* AXIS2_CALL
        adb_UserRealm_get_property1(
            adb_UserRealm_t* _UserRealm,
            const axutil_env_t *env);

    
        

        /**
         * Getter for authenticator by property number (2)
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return adb_Authenticator_t*
         */
        adb_Authenticator_t* AXIS2_CALL
        adb_UserRealm_get_property2(
            adb_UserRealm_t* _UserRealm,
            const axutil_env_t *env);

    
        

        /**
         * Getter for authorizer by property number (3)
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return adb_Authorizer_t*
         */
        adb_Authorizer_t* AXIS2_CALL
        adb_UserRealm_get_property3(
            adb_UserRealm_t* _UserRealm,
            const axutil_env_t *env);

    
        

        /**
         * Getter for claimsAdmin by property number (4)
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return adb_UserClaimsAdmin_t*
         */
        adb_UserClaimsAdmin_t* AXIS2_CALL
        adb_UserRealm_get_property4(
            adb_UserRealm_t* _UserRealm,
            const axutil_env_t *env);

    
        

        /**
         * Getter for realmConfiguration by property number (5)
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return axiom_node_t*
         */
        axiom_node_t* AXIS2_CALL
        adb_UserRealm_get_property5(
            adb_UserRealm_t* _UserRealm,
            const axutil_env_t *env);

    
        

        /**
         * Getter for userProfileAdmin by property number (6)
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return adb_UserProfileAdmin_t*
         */
        adb_UserProfileAdmin_t* AXIS2_CALL
        adb_UserRealm_get_property6(
            adb_UserRealm_t* _UserRealm,
            const axutil_env_t *env);

    
        

        /**
         * Getter for userStoreAdmin by property number (7)
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return adb_UserStoreAdmin_t*
         */
        adb_UserStoreAdmin_t* AXIS2_CALL
        adb_UserRealm_get_property7(
            adb_UserRealm_t* _UserRealm,
            const axutil_env_t *env);

    
        

        /**
         * Getter for userStoreReader by property number (8)
         * @param  _UserRealm adb_UserRealm_t object
         * @param env pointer to environment struct
         * @return adb_UserStoreReader_t*
         */
        adb_UserStoreReader_t* AXIS2_CALL
        adb_UserRealm_get_property8(
            adb_UserRealm_t* _UserRealm,
            const axutil_env_t *env);

    
     #ifdef __cplusplus
     }
     #endif

     #endif /* ADB_USERREALM_H */
    

