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


        #ifndef ADB_USERCLAIMSADMIN_H
        #define ADB_USERCLAIMSADMIN_H

       /**
        * adb_UserClaimsAdmin.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/Java version: SNAPSHOT  Built on : Jan 19, 2010 (01:47:08 IST)
        */

       /**
        *  adb_UserClaimsAdmin class
        */

        
          #include "adb_Claim.h"
          
          #include "adb_Claim.h"
          
          #include "adb_Claim.h"
          

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
        

        typedef struct adb_UserClaimsAdmin adb_UserClaimsAdmin_t;

        
        

        /******************************* Create and Free functions *********************************/

        /**
         * Constructor for creating adb_UserClaimsAdmin_t
         * @param env pointer to environment struct
         * @return newly created adb_UserClaimsAdmin_t object
         */
        adb_UserClaimsAdmin_t* AXIS2_CALL
        adb_UserClaimsAdmin_create(
            const axutil_env_t *env );

        /**
         * Wrapper for the "free" function, will invoke the extension mapper instead
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserClaimsAdmin_free (
            adb_UserClaimsAdmin_t* _UserClaimsAdmin,
            const axutil_env_t *env);

        /**
         * Free adb_UserClaimsAdmin_t object
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserClaimsAdmin_free_obj (
            adb_UserClaimsAdmin_t* _UserClaimsAdmin,
            const axutil_env_t *env);



        /********************************** Getters and Setters **************************************/
        /******** Deprecated for array types, Use 'Getters and Setters for Arrays' instead ***********/
        

        /**
         * Getter for allClaimUris. Deprecated for array types, Use adb_UserClaimsAdmin_get_allClaimUris_at instead
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @return Array of axis2_char_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_UserClaimsAdmin_get_allClaimUris(
            adb_UserClaimsAdmin_t* _UserClaimsAdmin,
            const axutil_env_t *env);

        /**
         * Setter for allClaimUris.Deprecated for array types, Use adb_UserClaimsAdmin_set_allClaimUris_at
         * or adb_UserClaimsAdmin_add_allClaimUris instead.
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @param arg_allClaimUris Array of axis2_char_t*s.
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserClaimsAdmin_set_allClaimUris(
            adb_UserClaimsAdmin_t* _UserClaimsAdmin,
            const axutil_env_t *env,
            axutil_array_list_t*  arg_allClaimUris);

        /**
         * Resetter for allClaimUris
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserClaimsAdmin_reset_allClaimUris(
            adb_UserClaimsAdmin_t* _UserClaimsAdmin,
            const axutil_env_t *env);

        
        

        /**
         * Getter for allClaims. Deprecated for array types, Use adb_UserClaimsAdmin_get_allClaims_at instead
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @return Array of adb_Claim_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_UserClaimsAdmin_get_allClaims(
            adb_UserClaimsAdmin_t* _UserClaimsAdmin,
            const axutil_env_t *env);

        /**
         * Setter for allClaims.Deprecated for array types, Use adb_UserClaimsAdmin_set_allClaims_at
         * or adb_UserClaimsAdmin_add_allClaims instead.
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @param arg_allClaims Array of adb_Claim_t*s.
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserClaimsAdmin_set_allClaims(
            adb_UserClaimsAdmin_t* _UserClaimsAdmin,
            const axutil_env_t *env,
            axutil_array_list_t*  arg_allClaims);

        /**
         * Resetter for allClaims
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserClaimsAdmin_reset_allClaims(
            adb_UserClaimsAdmin_t* _UserClaimsAdmin,
            const axutil_env_t *env);

        
        

        /**
         * Getter for allRequiredClaims. Deprecated for array types, Use adb_UserClaimsAdmin_get_allRequiredClaims_at instead
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @return Array of adb_Claim_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_UserClaimsAdmin_get_allRequiredClaims(
            adb_UserClaimsAdmin_t* _UserClaimsAdmin,
            const axutil_env_t *env);

        /**
         * Setter for allRequiredClaims.Deprecated for array types, Use adb_UserClaimsAdmin_set_allRequiredClaims_at
         * or adb_UserClaimsAdmin_add_allRequiredClaims instead.
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @param arg_allRequiredClaims Array of adb_Claim_t*s.
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserClaimsAdmin_set_allRequiredClaims(
            adb_UserClaimsAdmin_t* _UserClaimsAdmin,
            const axutil_env_t *env,
            axutil_array_list_t*  arg_allRequiredClaims);

        /**
         * Resetter for allRequiredClaims
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserClaimsAdmin_reset_allRequiredClaims(
            adb_UserClaimsAdmin_t* _UserClaimsAdmin,
            const axutil_env_t *env);

        
        

        /**
         * Getter for allSupportClaimsByDefault. Deprecated for array types, Use adb_UserClaimsAdmin_get_allSupportClaimsByDefault_at instead
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @return Array of adb_Claim_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_UserClaimsAdmin_get_allSupportClaimsByDefault(
            adb_UserClaimsAdmin_t* _UserClaimsAdmin,
            const axutil_env_t *env);

        /**
         * Setter for allSupportClaimsByDefault.Deprecated for array types, Use adb_UserClaimsAdmin_set_allSupportClaimsByDefault_at
         * or adb_UserClaimsAdmin_add_allSupportClaimsByDefault instead.
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @param arg_allSupportClaimsByDefault Array of adb_Claim_t*s.
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserClaimsAdmin_set_allSupportClaimsByDefault(
            adb_UserClaimsAdmin_t* _UserClaimsAdmin,
            const axutil_env_t *env,
            axutil_array_list_t*  arg_allSupportClaimsByDefault);

        /**
         * Resetter for allSupportClaimsByDefault
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserClaimsAdmin_reset_allSupportClaimsByDefault(
            adb_UserClaimsAdmin_t* _UserClaimsAdmin,
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
         * Get the ith element of allClaimUris.
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @return ith axis2_char_t* of the array
         */
        axis2_char_t* AXIS2_CALL
        adb_UserClaimsAdmin_get_allClaimUris_at(
                adb_UserClaimsAdmin_t* _UserClaimsAdmin,
                const axutil_env_t *env, int i);

        /**
         * Set the ith element of allClaimUris. (If the ith already exist, it will be replaced)
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @param arg_allClaimUris element to set axis2_char_t* to the array
         * @return ith axis2_char_t* of the array
         */
        axis2_status_t AXIS2_CALL
        adb_UserClaimsAdmin_set_allClaimUris_at(
                adb_UserClaimsAdmin_t* _UserClaimsAdmin,
                const axutil_env_t *env, int i,
                const axis2_char_t* arg_allClaimUris);


        /**
         * Add to allClaimUris.
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @param arg_allClaimUris element to add axis2_char_t* to the array
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserClaimsAdmin_add_allClaimUris(
                adb_UserClaimsAdmin_t* _UserClaimsAdmin,
                const axutil_env_t *env,
                const axis2_char_t* arg_allClaimUris);

        /**
         * Get the size of the allClaimUris array.
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct.
         * @return the size of the allClaimUris array.
         */
        int AXIS2_CALL
        adb_UserClaimsAdmin_sizeof_allClaimUris(
                    adb_UserClaimsAdmin_t* _UserClaimsAdmin,
                    const axutil_env_t *env);

        /**
         * Remove the ith element of allClaimUris.
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @param i index of the item to remove
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserClaimsAdmin_remove_allClaimUris_at(
                adb_UserClaimsAdmin_t* _UserClaimsAdmin,
                const axutil_env_t *env, int i);

        
        
        /**
         * Get the ith element of allClaims.
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @return ith adb_Claim_t* of the array
         */
        adb_Claim_t* AXIS2_CALL
        adb_UserClaimsAdmin_get_allClaims_at(
                adb_UserClaimsAdmin_t* _UserClaimsAdmin,
                const axutil_env_t *env, int i);

        /**
         * Set the ith element of allClaims. (If the ith already exist, it will be replaced)
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @param arg_allClaims element to set adb_Claim_t* to the array
         * @return ith adb_Claim_t* of the array
         */
        axis2_status_t AXIS2_CALL
        adb_UserClaimsAdmin_set_allClaims_at(
                adb_UserClaimsAdmin_t* _UserClaimsAdmin,
                const axutil_env_t *env, int i,
                adb_Claim_t* arg_allClaims);


        /**
         * Add to allClaims.
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @param arg_allClaims element to add adb_Claim_t* to the array
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserClaimsAdmin_add_allClaims(
                adb_UserClaimsAdmin_t* _UserClaimsAdmin,
                const axutil_env_t *env,
                adb_Claim_t* arg_allClaims);

        /**
         * Get the size of the allClaims array.
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct.
         * @return the size of the allClaims array.
         */
        int AXIS2_CALL
        adb_UserClaimsAdmin_sizeof_allClaims(
                    adb_UserClaimsAdmin_t* _UserClaimsAdmin,
                    const axutil_env_t *env);

        /**
         * Remove the ith element of allClaims.
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @param i index of the item to remove
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserClaimsAdmin_remove_allClaims_at(
                adb_UserClaimsAdmin_t* _UserClaimsAdmin,
                const axutil_env_t *env, int i);

        
        
        /**
         * Get the ith element of allRequiredClaims.
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @return ith adb_Claim_t* of the array
         */
        adb_Claim_t* AXIS2_CALL
        adb_UserClaimsAdmin_get_allRequiredClaims_at(
                adb_UserClaimsAdmin_t* _UserClaimsAdmin,
                const axutil_env_t *env, int i);

        /**
         * Set the ith element of allRequiredClaims. (If the ith already exist, it will be replaced)
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @param arg_allRequiredClaims element to set adb_Claim_t* to the array
         * @return ith adb_Claim_t* of the array
         */
        axis2_status_t AXIS2_CALL
        adb_UserClaimsAdmin_set_allRequiredClaims_at(
                adb_UserClaimsAdmin_t* _UserClaimsAdmin,
                const axutil_env_t *env, int i,
                adb_Claim_t* arg_allRequiredClaims);


        /**
         * Add to allRequiredClaims.
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @param arg_allRequiredClaims element to add adb_Claim_t* to the array
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserClaimsAdmin_add_allRequiredClaims(
                adb_UserClaimsAdmin_t* _UserClaimsAdmin,
                const axutil_env_t *env,
                adb_Claim_t* arg_allRequiredClaims);

        /**
         * Get the size of the allRequiredClaims array.
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct.
         * @return the size of the allRequiredClaims array.
         */
        int AXIS2_CALL
        adb_UserClaimsAdmin_sizeof_allRequiredClaims(
                    adb_UserClaimsAdmin_t* _UserClaimsAdmin,
                    const axutil_env_t *env);

        /**
         * Remove the ith element of allRequiredClaims.
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @param i index of the item to remove
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserClaimsAdmin_remove_allRequiredClaims_at(
                adb_UserClaimsAdmin_t* _UserClaimsAdmin,
                const axutil_env_t *env, int i);

        
        
        /**
         * Get the ith element of allSupportClaimsByDefault.
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @return ith adb_Claim_t* of the array
         */
        adb_Claim_t* AXIS2_CALL
        adb_UserClaimsAdmin_get_allSupportClaimsByDefault_at(
                adb_UserClaimsAdmin_t* _UserClaimsAdmin,
                const axutil_env_t *env, int i);

        /**
         * Set the ith element of allSupportClaimsByDefault. (If the ith already exist, it will be replaced)
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @param arg_allSupportClaimsByDefault element to set adb_Claim_t* to the array
         * @return ith adb_Claim_t* of the array
         */
        axis2_status_t AXIS2_CALL
        adb_UserClaimsAdmin_set_allSupportClaimsByDefault_at(
                adb_UserClaimsAdmin_t* _UserClaimsAdmin,
                const axutil_env_t *env, int i,
                adb_Claim_t* arg_allSupportClaimsByDefault);


        /**
         * Add to allSupportClaimsByDefault.
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @param arg_allSupportClaimsByDefault element to add adb_Claim_t* to the array
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserClaimsAdmin_add_allSupportClaimsByDefault(
                adb_UserClaimsAdmin_t* _UserClaimsAdmin,
                const axutil_env_t *env,
                adb_Claim_t* arg_allSupportClaimsByDefault);

        /**
         * Get the size of the allSupportClaimsByDefault array.
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct.
         * @return the size of the allSupportClaimsByDefault array.
         */
        int AXIS2_CALL
        adb_UserClaimsAdmin_sizeof_allSupportClaimsByDefault(
                    adb_UserClaimsAdmin_t* _UserClaimsAdmin,
                    const axutil_env_t *env);

        /**
         * Remove the ith element of allSupportClaimsByDefault.
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @param i index of the item to remove
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserClaimsAdmin_remove_allSupportClaimsByDefault_at(
                adb_UserClaimsAdmin_t* _UserClaimsAdmin,
                const axutil_env_t *env, int i);

        


        /******************************* Checking and Setting NIL values *********************************/
        /* Use 'Checking and Setting NIL values for Arrays' to check and set nil for individual elements */

        /**
         * NOTE: set_nil is only available for nillable properties
         */

        

        /**
         * Check whether allClaimUris is nill
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_UserClaimsAdmin_is_allClaimUris_nil(
                adb_UserClaimsAdmin_t* _UserClaimsAdmin,
                const axutil_env_t *env);


        
        /**
         * Set allClaimUris to nill (currently the same as reset)
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserClaimsAdmin_set_allClaimUris_nil(
                adb_UserClaimsAdmin_t* _UserClaimsAdmin,
                const axutil_env_t *env);
        

        /**
         * Check whether allClaims is nill
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_UserClaimsAdmin_is_allClaims_nil(
                adb_UserClaimsAdmin_t* _UserClaimsAdmin,
                const axutil_env_t *env);


        
        /**
         * Set allClaims to nill (currently the same as reset)
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserClaimsAdmin_set_allClaims_nil(
                adb_UserClaimsAdmin_t* _UserClaimsAdmin,
                const axutil_env_t *env);
        

        /**
         * Check whether allRequiredClaims is nill
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_UserClaimsAdmin_is_allRequiredClaims_nil(
                adb_UserClaimsAdmin_t* _UserClaimsAdmin,
                const axutil_env_t *env);


        
        /**
         * Set allRequiredClaims to nill (currently the same as reset)
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserClaimsAdmin_set_allRequiredClaims_nil(
                adb_UserClaimsAdmin_t* _UserClaimsAdmin,
                const axutil_env_t *env);
        

        /**
         * Check whether allSupportClaimsByDefault is nill
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_UserClaimsAdmin_is_allSupportClaimsByDefault_nil(
                adb_UserClaimsAdmin_t* _UserClaimsAdmin,
                const axutil_env_t *env);


        
        /**
         * Set allSupportClaimsByDefault to nill (currently the same as reset)
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserClaimsAdmin_set_allSupportClaimsByDefault_nil(
                adb_UserClaimsAdmin_t* _UserClaimsAdmin,
                const axutil_env_t *env);
        
        /*************************** Checking and Setting 'NIL' values in Arrays *****************************/

        /**
         * NOTE: You may set this to remove specific elements in the array
         *       But you can not remove elements, if the specific property is declared to be non-nillable or sizeof(array) < minOccurs
         */
        
        /**
         * Check whether allClaimUris is nill at i
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct.
         * @param i index of the item to return.
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_UserClaimsAdmin_is_allClaimUris_nil_at(
                adb_UserClaimsAdmin_t* _UserClaimsAdmin,
                const axutil_env_t *env, int i);
 
       
        /**
         * Set allClaimUris to nill at i
         * @param  _UserClaimsAdmin _ adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct.
         * @param i index of the item to set.
         * @return AXIS2_SUCCESS on success, or AXIS2_FAILURE otherwise.
         */
        axis2_status_t AXIS2_CALL
        adb_UserClaimsAdmin_set_allClaimUris_nil_at(
                adb_UserClaimsAdmin_t* _UserClaimsAdmin, 
                const axutil_env_t *env, int i);

        
        /**
         * Check whether allClaims is nill at i
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct.
         * @param i index of the item to return.
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_UserClaimsAdmin_is_allClaims_nil_at(
                adb_UserClaimsAdmin_t* _UserClaimsAdmin,
                const axutil_env_t *env, int i);
 
       
        /**
         * Set allClaims to nill at i
         * @param  _UserClaimsAdmin _ adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct.
         * @param i index of the item to set.
         * @return AXIS2_SUCCESS on success, or AXIS2_FAILURE otherwise.
         */
        axis2_status_t AXIS2_CALL
        adb_UserClaimsAdmin_set_allClaims_nil_at(
                adb_UserClaimsAdmin_t* _UserClaimsAdmin, 
                const axutil_env_t *env, int i);

        
        /**
         * Check whether allRequiredClaims is nill at i
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct.
         * @param i index of the item to return.
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_UserClaimsAdmin_is_allRequiredClaims_nil_at(
                adb_UserClaimsAdmin_t* _UserClaimsAdmin,
                const axutil_env_t *env, int i);
 
       
        /**
         * Set allRequiredClaims to nill at i
         * @param  _UserClaimsAdmin _ adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct.
         * @param i index of the item to set.
         * @return AXIS2_SUCCESS on success, or AXIS2_FAILURE otherwise.
         */
        axis2_status_t AXIS2_CALL
        adb_UserClaimsAdmin_set_allRequiredClaims_nil_at(
                adb_UserClaimsAdmin_t* _UserClaimsAdmin, 
                const axutil_env_t *env, int i);

        
        /**
         * Check whether allSupportClaimsByDefault is nill at i
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct.
         * @param i index of the item to return.
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_UserClaimsAdmin_is_allSupportClaimsByDefault_nil_at(
                adb_UserClaimsAdmin_t* _UserClaimsAdmin,
                const axutil_env_t *env, int i);
 
       
        /**
         * Set allSupportClaimsByDefault to nill at i
         * @param  _UserClaimsAdmin _ adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct.
         * @param i index of the item to set.
         * @return AXIS2_SUCCESS on success, or AXIS2_FAILURE otherwise.
         */
        axis2_status_t AXIS2_CALL
        adb_UserClaimsAdmin_set_allSupportClaimsByDefault_nil_at(
                adb_UserClaimsAdmin_t* _UserClaimsAdmin, 
                const axutil_env_t *env, int i);

        

        /**************************** Serialize and Deserialize functions ***************************/
        /*********** These functions are for use only inside the generated code *********************/

        
        /**
         * Wrapper for the deserialization function, will invoke the extension mapper instead
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs, 
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserClaimsAdmin_deserialize(
            adb_UserClaimsAdmin_t* _UserClaimsAdmin,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);

        /**
         * Deserialize an XML to adb objects
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs,
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_UserClaimsAdmin_deserialize_obj(
            adb_UserClaimsAdmin_t* _UserClaimsAdmin,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);
                            
            

       /**
         * Declare namespace in the most parent node 
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @param parent_element parent element
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index pointer to an int which contain the next namespace index
         */
       void AXIS2_CALL
       adb_UserClaimsAdmin_declare_parent_namespaces(
                    adb_UserClaimsAdmin_t* _UserClaimsAdmin,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index);

        

        /**
         * Wrapper for the serialization function, will invoke the extension mapper instead
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @param UserClaimsAdmin_om_node node to serialize from
         * @param UserClaimsAdmin_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_UserClaimsAdmin_serialize(
            adb_UserClaimsAdmin_t* _UserClaimsAdmin,
            const axutil_env_t *env,
            axiom_node_t* UserClaimsAdmin_om_node, axiom_element_t *UserClaimsAdmin_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Serialize to an XML from the adb objects
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @param UserClaimsAdmin_om_node node to serialize from
         * @param UserClaimsAdmin_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_UserClaimsAdmin_serialize_obj(
            adb_UserClaimsAdmin_t* _UserClaimsAdmin,
            const axutil_env_t *env,
            axiom_node_t* UserClaimsAdmin_om_node, axiom_element_t *UserClaimsAdmin_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Check whether the adb_UserClaimsAdmin is a particle class (E.g. group, inner sequence)
         * @return whether this is a particle class.
         */
        axis2_bool_t AXIS2_CALL
        adb_UserClaimsAdmin_is_particle();

        /******************************* Alternatives for Create and Free functions *********************************/

        

        /**
         * Constructor for creating adb_UserClaimsAdmin_t
         * @param env pointer to environment struct
         * @param _allClaimUris axutil_array_list_t*
         * @param _allClaims axutil_array_list_t*
         * @param _allRequiredClaims axutil_array_list_t*
         * @param _allSupportClaimsByDefault axutil_array_list_t*
         * @return newly created adb_UserClaimsAdmin_t object
         */
        adb_UserClaimsAdmin_t* AXIS2_CALL
        adb_UserClaimsAdmin_create_with_values(
            const axutil_env_t *env,
                axutil_array_list_t* _allClaimUris,
                axutil_array_list_t* _allClaims,
                axutil_array_list_t* _allRequiredClaims,
                axutil_array_list_t* _allSupportClaimsByDefault);

        


                /**
                 * Free adb_UserClaimsAdmin_t object and return the property value.
                 * You can use this to free the adb object as returning the property value. If there are
                 * many properties, it will only return the first property. Other properties will get freed with the adb object.
                 * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object to free
                 * @param env pointer to environment struct
                 * @return the property value holded by the ADB object, if there are many properties only returns the first.
                 */
                axutil_array_list_t* AXIS2_CALL
                adb_UserClaimsAdmin_free_popping_value(
                        adb_UserClaimsAdmin_t* _UserClaimsAdmin,
                        const axutil_env_t *env);
            

        /******************************* get the value by the property number  *********************************/
        /************NOTE: This method is introduced to resolve a problem in unwrapping mode *******************/

        
        

        /**
         * Getter for allClaimUris by property number (1)
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @return Array of axis2_char_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_UserClaimsAdmin_get_property1(
            adb_UserClaimsAdmin_t* _UserClaimsAdmin,
            const axutil_env_t *env);

    
        

        /**
         * Getter for allClaims by property number (2)
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @return Array of adb_Claim_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_UserClaimsAdmin_get_property2(
            adb_UserClaimsAdmin_t* _UserClaimsAdmin,
            const axutil_env_t *env);

    
        

        /**
         * Getter for allRequiredClaims by property number (3)
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @return Array of adb_Claim_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_UserClaimsAdmin_get_property3(
            adb_UserClaimsAdmin_t* _UserClaimsAdmin,
            const axutil_env_t *env);

    
        

        /**
         * Getter for allSupportClaimsByDefault by property number (4)
         * @param  _UserClaimsAdmin adb_UserClaimsAdmin_t object
         * @param env pointer to environment struct
         * @return Array of adb_Claim_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_UserClaimsAdmin_get_property4(
            adb_UserClaimsAdmin_t* _UserClaimsAdmin,
            const axutil_env_t *env);

    
     #ifdef __cplusplus
     }
     #endif

     #endif /* ADB_USERCLAIMSADMIN_H */
    

