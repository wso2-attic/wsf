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


        #ifndef ADB_CLAIM_H
        #define ADB_CLAIM_H

       /**
        * adb_Claim.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/Java version: SNAPSHOT  Built on : Jan 19, 2010 (01:47:08 IST)
        */

       /**
        *  adb_Claim class
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
        

        typedef struct adb_Claim adb_Claim_t;

        
        

        /******************************* Create and Free functions *********************************/

        /**
         * Constructor for creating adb_Claim_t
         * @param env pointer to environment struct
         * @return newly created adb_Claim_t object
         */
        adb_Claim_t* AXIS2_CALL
        adb_Claim_create(
            const axutil_env_t *env );

        /**
         * Wrapper for the "free" function, will invoke the extension mapper instead
         * @param  _Claim adb_Claim_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_Claim_free (
            adb_Claim_t* _Claim,
            const axutil_env_t *env);

        /**
         * Free adb_Claim_t object
         * @param  _Claim adb_Claim_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_Claim_free_obj (
            adb_Claim_t* _Claim,
            const axutil_env_t *env);



        /********************************** Getters and Setters **************************************/
        
        

        /**
         * Getter for claimUri. 
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_Claim_get_claimUri(
            adb_Claim_t* _Claim,
            const axutil_env_t *env);

        /**
         * Setter for claimUri.
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @param arg_claimUri axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_Claim_set_claimUri(
            adb_Claim_t* _Claim,
            const axutil_env_t *env,
            const axis2_char_t*  arg_claimUri);

        /**
         * Resetter for claimUri
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_Claim_reset_claimUri(
            adb_Claim_t* _Claim,
            const axutil_env_t *env);

        
        

        /**
         * Getter for description. 
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_Claim_get_description(
            adb_Claim_t* _Claim,
            const axutil_env_t *env);

        /**
         * Setter for description.
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @param arg_description axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_Claim_set_description(
            adb_Claim_t* _Claim,
            const axutil_env_t *env,
            const axis2_char_t*  arg_description);

        /**
         * Resetter for description
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_Claim_reset_description(
            adb_Claim_t* _Claim,
            const axutil_env_t *env);

        
        

        /**
         * Getter for dialectURI. 
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_Claim_get_dialectURI(
            adb_Claim_t* _Claim,
            const axutil_env_t *env);

        /**
         * Setter for dialectURI.
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @param arg_dialectURI axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_Claim_set_dialectURI(
            adb_Claim_t* _Claim,
            const axutil_env_t *env,
            const axis2_char_t*  arg_dialectURI);

        /**
         * Resetter for dialectURI
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_Claim_reset_dialectURI(
            adb_Claim_t* _Claim,
            const axutil_env_t *env);

        
        

        /**
         * Getter for displayOrder. 
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return int
         */
        int AXIS2_CALL
        adb_Claim_get_displayOrder(
            adb_Claim_t* _Claim,
            const axutil_env_t *env);

        /**
         * Setter for displayOrder.
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @param arg_displayOrder int
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_Claim_set_displayOrder(
            adb_Claim_t* _Claim,
            const axutil_env_t *env,
            const int  arg_displayOrder);

        /**
         * Resetter for displayOrder
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_Claim_reset_displayOrder(
            adb_Claim_t* _Claim,
            const axutil_env_t *env);

        
        

        /**
         * Getter for displayTag. 
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_Claim_get_displayTag(
            adb_Claim_t* _Claim,
            const axutil_env_t *env);

        /**
         * Setter for displayTag.
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @param arg_displayTag axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_Claim_set_displayTag(
            adb_Claim_t* _Claim,
            const axutil_env_t *env,
            const axis2_char_t*  arg_displayTag);

        /**
         * Resetter for displayTag
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_Claim_reset_displayTag(
            adb_Claim_t* _Claim,
            const axutil_env_t *env);

        
        

        /**
         * Getter for regEx. 
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_Claim_get_regEx(
            adb_Claim_t* _Claim,
            const axutil_env_t *env);

        /**
         * Setter for regEx.
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @param arg_regEx axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_Claim_set_regEx(
            adb_Claim_t* _Claim,
            const axutil_env_t *env,
            const axis2_char_t*  arg_regEx);

        /**
         * Resetter for regEx
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_Claim_reset_regEx(
            adb_Claim_t* _Claim,
            const axutil_env_t *env);

        
        

        /**
         * Getter for required. 
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_Claim_get_required(
            adb_Claim_t* _Claim,
            const axutil_env_t *env);

        /**
         * Setter for required.
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @param arg_required axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_Claim_set_required(
            adb_Claim_t* _Claim,
            const axutil_env_t *env,
            axis2_bool_t  arg_required);

        /**
         * Resetter for required
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_Claim_reset_required(
            adb_Claim_t* _Claim,
            const axutil_env_t *env);

        
        

        /**
         * Getter for supportedByDefault. 
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_Claim_get_supportedByDefault(
            adb_Claim_t* _Claim,
            const axutil_env_t *env);

        /**
         * Setter for supportedByDefault.
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @param arg_supportedByDefault axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_Claim_set_supportedByDefault(
            adb_Claim_t* _Claim,
            const axutil_env_t *env,
            axis2_bool_t  arg_supportedByDefault);

        /**
         * Resetter for supportedByDefault
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_Claim_reset_supportedByDefault(
            adb_Claim_t* _Claim,
            const axutil_env_t *env);

        
        

        /**
         * Getter for value. 
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_Claim_get_value(
            adb_Claim_t* _Claim,
            const axutil_env_t *env);

        /**
         * Setter for value.
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @param arg_value axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_Claim_set_value(
            adb_Claim_t* _Claim,
            const axutil_env_t *env,
            const axis2_char_t*  arg_value);

        /**
         * Resetter for value
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_Claim_reset_value(
            adb_Claim_t* _Claim,
            const axutil_env_t *env);

        


        /******************************* Checking and Setting NIL values *********************************/
        

        /**
         * NOTE: set_nil is only available for nillable properties
         */

        

        /**
         * Check whether claimUri is nill
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_Claim_is_claimUri_nil(
                adb_Claim_t* _Claim,
                const axutil_env_t *env);


        
        /**
         * Set claimUri to nill (currently the same as reset)
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_Claim_set_claimUri_nil(
                adb_Claim_t* _Claim,
                const axutil_env_t *env);
        

        /**
         * Check whether description is nill
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_Claim_is_description_nil(
                adb_Claim_t* _Claim,
                const axutil_env_t *env);


        
        /**
         * Set description to nill (currently the same as reset)
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_Claim_set_description_nil(
                adb_Claim_t* _Claim,
                const axutil_env_t *env);
        

        /**
         * Check whether dialectURI is nill
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_Claim_is_dialectURI_nil(
                adb_Claim_t* _Claim,
                const axutil_env_t *env);


        
        /**
         * Set dialectURI to nill (currently the same as reset)
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_Claim_set_dialectURI_nil(
                adb_Claim_t* _Claim,
                const axutil_env_t *env);
        

        /**
         * Check whether displayOrder is nill
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_Claim_is_displayOrder_nil(
                adb_Claim_t* _Claim,
                const axutil_env_t *env);


        

        /**
         * Check whether displayTag is nill
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_Claim_is_displayTag_nil(
                adb_Claim_t* _Claim,
                const axutil_env_t *env);


        
        /**
         * Set displayTag to nill (currently the same as reset)
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_Claim_set_displayTag_nil(
                adb_Claim_t* _Claim,
                const axutil_env_t *env);
        

        /**
         * Check whether regEx is nill
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_Claim_is_regEx_nil(
                adb_Claim_t* _Claim,
                const axutil_env_t *env);


        
        /**
         * Set regEx to nill (currently the same as reset)
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_Claim_set_regEx_nil(
                adb_Claim_t* _Claim,
                const axutil_env_t *env);
        

        /**
         * Check whether required is nill
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_Claim_is_required_nil(
                adb_Claim_t* _Claim,
                const axutil_env_t *env);


        

        /**
         * Check whether supportedByDefault is nill
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_Claim_is_supportedByDefault_nil(
                adb_Claim_t* _Claim,
                const axutil_env_t *env);


        

        /**
         * Check whether value is nill
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_Claim_is_value_nil(
                adb_Claim_t* _Claim,
                const axutil_env_t *env);


        
        /**
         * Set value to nill (currently the same as reset)
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_Claim_set_value_nil(
                adb_Claim_t* _Claim,
                const axutil_env_t *env);
        

        /**************************** Serialize and Deserialize functions ***************************/
        /*********** These functions are for use only inside the generated code *********************/

        
        /**
         * Wrapper for the deserialization function, will invoke the extension mapper instead
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs, 
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_Claim_deserialize(
            adb_Claim_t* _Claim,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);

        /**
         * Deserialize an XML to adb objects
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs,
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_Claim_deserialize_obj(
            adb_Claim_t* _Claim,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);
                            
            

       /**
         * Declare namespace in the most parent node 
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @param parent_element parent element
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index pointer to an int which contain the next namespace index
         */
       void AXIS2_CALL
       adb_Claim_declare_parent_namespaces(
                    adb_Claim_t* _Claim,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index);

        

        /**
         * Wrapper for the serialization function, will invoke the extension mapper instead
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @param Claim_om_node node to serialize from
         * @param Claim_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_Claim_serialize(
            adb_Claim_t* _Claim,
            const axutil_env_t *env,
            axiom_node_t* Claim_om_node, axiom_element_t *Claim_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Serialize to an XML from the adb objects
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @param Claim_om_node node to serialize from
         * @param Claim_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_Claim_serialize_obj(
            adb_Claim_t* _Claim,
            const axutil_env_t *env,
            axiom_node_t* Claim_om_node, axiom_element_t *Claim_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Check whether the adb_Claim is a particle class (E.g. group, inner sequence)
         * @return whether this is a particle class.
         */
        axis2_bool_t AXIS2_CALL
        adb_Claim_is_particle();

        /******************************* Alternatives for Create and Free functions *********************************/

        

        /**
         * Constructor for creating adb_Claim_t
         * @param env pointer to environment struct
         * @param _claimUri axis2_char_t*
         * @param _description axis2_char_t*
         * @param _dialectURI axis2_char_t*
         * @param _displayOrder int
         * @param _displayTag axis2_char_t*
         * @param _regEx axis2_char_t*
         * @param _required axis2_bool_t
         * @param _supportedByDefault axis2_bool_t
         * @param _value axis2_char_t*
         * @return newly created adb_Claim_t object
         */
        adb_Claim_t* AXIS2_CALL
        adb_Claim_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _claimUri,
                axis2_char_t* _description,
                axis2_char_t* _dialectURI,
                int _displayOrder,
                axis2_char_t* _displayTag,
                axis2_char_t* _regEx,
                axis2_bool_t _required,
                axis2_bool_t _supportedByDefault,
                axis2_char_t* _value);

        


                /**
                 * Free adb_Claim_t object and return the property value.
                 * You can use this to free the adb object as returning the property value. If there are
                 * many properties, it will only return the first property. Other properties will get freed with the adb object.
                 * @param  _Claim adb_Claim_t object to free
                 * @param env pointer to environment struct
                 * @return the property value holded by the ADB object, if there are many properties only returns the first.
                 */
                axis2_char_t* AXIS2_CALL
                adb_Claim_free_popping_value(
                        adb_Claim_t* _Claim,
                        const axutil_env_t *env);
            

        /******************************* get the value by the property number  *********************************/
        /************NOTE: This method is introduced to resolve a problem in unwrapping mode *******************/

        
        

        /**
         * Getter for claimUri by property number (1)
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_Claim_get_property1(
            adb_Claim_t* _Claim,
            const axutil_env_t *env);

    
        

        /**
         * Getter for description by property number (2)
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_Claim_get_property2(
            adb_Claim_t* _Claim,
            const axutil_env_t *env);

    
        

        /**
         * Getter for dialectURI by property number (3)
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_Claim_get_property3(
            adb_Claim_t* _Claim,
            const axutil_env_t *env);

    
        

        /**
         * Getter for displayOrder by property number (4)
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return int
         */
        int AXIS2_CALL
        adb_Claim_get_property4(
            adb_Claim_t* _Claim,
            const axutil_env_t *env);

    
        

        /**
         * Getter for displayTag by property number (5)
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_Claim_get_property5(
            adb_Claim_t* _Claim,
            const axutil_env_t *env);

    
        

        /**
         * Getter for regEx by property number (6)
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_Claim_get_property6(
            adb_Claim_t* _Claim,
            const axutil_env_t *env);

    
        

        /**
         * Getter for required by property number (7)
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_Claim_get_property7(
            adb_Claim_t* _Claim,
            const axutil_env_t *env);

    
        

        /**
         * Getter for supportedByDefault by property number (8)
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_Claim_get_property8(
            adb_Claim_t* _Claim,
            const axutil_env_t *env);

    
        

        /**
         * Getter for value by property number (9)
         * @param  _Claim adb_Claim_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_Claim_get_property9(
            adb_Claim_t* _Claim,
            const axutil_env_t *env);

    
     #ifdef __cplusplus
     }
     #endif

     #endif /* ADB_CLAIM_H */
    

