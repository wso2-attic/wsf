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


        #ifndef ADB_UPDATEEXTERNALUSERSTORECONFIG_H
        #define ADB_UPDATEEXTERNALUSERSTORECONFIG_H

       /**
        * adb_updateExternalUserStoreConfig.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/Java version: #axisVersion# #today#
        */

       /**
        *  adb_updateExternalUserStoreConfig class
        */

        
          #include "adb_StoreProperty.h"
          

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
        

        typedef struct adb_updateExternalUserStoreConfig adb_updateExternalUserStoreConfig_t;

        
        

        /******************************* Create and Free functions *********************************/

        /**
         * Constructor for creating adb_updateExternalUserStoreConfig_t
         * @param env pointer to environment struct
         * @return newly created adb_updateExternalUserStoreConfig_t object
         */
        adb_updateExternalUserStoreConfig_t* AXIS2_CALL
        adb_updateExternalUserStoreConfig_create(
            const axutil_env_t *env );

        /**
         * Wrapper for the "free" function, will invoke the extension mapper instead
         * @param  _updateExternalUserStoreConfig adb_updateExternalUserStoreConfig_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_updateExternalUserStoreConfig_free (
            adb_updateExternalUserStoreConfig_t* _updateExternalUserStoreConfig,
            const axutil_env_t *env);

        /**
         * Free adb_updateExternalUserStoreConfig_t object
         * @param  _updateExternalUserStoreConfig adb_updateExternalUserStoreConfig_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_updateExternalUserStoreConfig_free_obj (
            adb_updateExternalUserStoreConfig_t* _updateExternalUserStoreConfig,
            const axutil_env_t *env);



        /********************************** Getters and Setters **************************************/
        /******** Deprecated for array types, Use 'Getters and Setters for Arrays' instead ***********/
        

        /**
         * Getter for props. Deprecated for array types, Use adb_updateExternalUserStoreConfig_get_props_at instead
         * @param  _updateExternalUserStoreConfig adb_updateExternalUserStoreConfig_t object
         * @param env pointer to environment struct
         * @return Array of adb_StoreProperty_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_updateExternalUserStoreConfig_get_props(
            adb_updateExternalUserStoreConfig_t* _updateExternalUserStoreConfig,
            const axutil_env_t *env);

        /**
         * Setter for props.Deprecated for array types, Use adb_updateExternalUserStoreConfig_set_props_at
         * or adb_updateExternalUserStoreConfig_add_props instead.
         * @param  _updateExternalUserStoreConfig adb_updateExternalUserStoreConfig_t object
         * @param env pointer to environment struct
         * @param arg_props Array of adb_StoreProperty_t*s.
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_updateExternalUserStoreConfig_set_props(
            adb_updateExternalUserStoreConfig_t* _updateExternalUserStoreConfig,
            const axutil_env_t *env,
            axutil_array_list_t*  arg_props);

        /**
         * Resetter for props
         * @param  _updateExternalUserStoreConfig adb_updateExternalUserStoreConfig_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_updateExternalUserStoreConfig_reset_props(
            adb_updateExternalUserStoreConfig_t* _updateExternalUserStoreConfig,
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
         * Get the ith element of props.
         * @param  _updateExternalUserStoreConfig adb_updateExternalUserStoreConfig_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @return ith adb_StoreProperty_t* of the array
         */
        adb_StoreProperty_t* AXIS2_CALL
        adb_updateExternalUserStoreConfig_get_props_at(
                adb_updateExternalUserStoreConfig_t* _updateExternalUserStoreConfig,
                const axutil_env_t *env, int i);

        /**
         * Set the ith element of props. (If the ith already exist, it will be replaced)
         * @param  _updateExternalUserStoreConfig adb_updateExternalUserStoreConfig_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @param arg_props element to set adb_StoreProperty_t* to the array
         * @return ith adb_StoreProperty_t* of the array
         */
        axis2_status_t AXIS2_CALL
        adb_updateExternalUserStoreConfig_set_props_at(
                adb_updateExternalUserStoreConfig_t* _updateExternalUserStoreConfig,
                const axutil_env_t *env, int i,
                adb_StoreProperty_t* arg_props);


        /**
         * Add to props.
         * @param  _updateExternalUserStoreConfig adb_updateExternalUserStoreConfig_t object
         * @param env pointer to environment struct
         * @param arg_props element to add adb_StoreProperty_t* to the array
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_updateExternalUserStoreConfig_add_props(
                adb_updateExternalUserStoreConfig_t* _updateExternalUserStoreConfig,
                const axutil_env_t *env,
                adb_StoreProperty_t* arg_props);

        /**
         * Get the size of the props array.
         * @param  _updateExternalUserStoreConfig adb_updateExternalUserStoreConfig_t object
         * @param env pointer to environment struct.
         * @return the size of the props array.
         */
        int AXIS2_CALL
        adb_updateExternalUserStoreConfig_sizeof_props(
                    adb_updateExternalUserStoreConfig_t* _updateExternalUserStoreConfig,
                    const axutil_env_t *env);

        /**
         * Remove the ith element of props.
         * @param  _updateExternalUserStoreConfig adb_updateExternalUserStoreConfig_t object
         * @param env pointer to environment struct
         * @param i index of the item to remove
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_updateExternalUserStoreConfig_remove_props_at(
                adb_updateExternalUserStoreConfig_t* _updateExternalUserStoreConfig,
                const axutil_env_t *env, int i);

        


        /******************************* Checking and Setting NIL values *********************************/
        /* Use 'Checking and Setting NIL values for Arrays' to check and set nil for individual elements */

        /**
         * NOTE: set_nil is only available for nillable properties
         */

        

        /**
         * Check whether props is nill
         * @param  _updateExternalUserStoreConfig adb_updateExternalUserStoreConfig_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_updateExternalUserStoreConfig_is_props_nil(
                adb_updateExternalUserStoreConfig_t* _updateExternalUserStoreConfig,
                const axutil_env_t *env);


        
        /**
         * Set props to nill (currently the same as reset)
         * @param  _updateExternalUserStoreConfig adb_updateExternalUserStoreConfig_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_updateExternalUserStoreConfig_set_props_nil(
                adb_updateExternalUserStoreConfig_t* _updateExternalUserStoreConfig,
                const axutil_env_t *env);
        
        /*************************** Checking and Setting 'NIL' values in Arrays *****************************/

        /**
         * NOTE: You may set this to remove specific elements in the array
         *       But you can not remove elements, if the specific property is declared to be non-nillable or sizeof(array) < minOccurs
         */
        
        /**
         * Check whether props is nill at i
         * @param  _updateExternalUserStoreConfig adb_updateExternalUserStoreConfig_t object
         * @param env pointer to environment struct.
         * @param i index of the item to return.
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_updateExternalUserStoreConfig_is_props_nil_at(
                adb_updateExternalUserStoreConfig_t* _updateExternalUserStoreConfig,
                const axutil_env_t *env, int i);
 
       
        /**
         * Set props to nill at i
         * @param  _updateExternalUserStoreConfig _ adb_updateExternalUserStoreConfig_t object
         * @param env pointer to environment struct.
         * @param i index of the item to set.
         * @return AXIS2_SUCCESS on success, or AXIS2_FAILURE otherwise.
         */
        axis2_status_t AXIS2_CALL
        adb_updateExternalUserStoreConfig_set_props_nil_at(
                adb_updateExternalUserStoreConfig_t* _updateExternalUserStoreConfig, 
                const axutil_env_t *env, int i);

        

        /**************************** Serialize and Deserialize functions ***************************/
        /*********** These functions are for use only inside the generated code *********************/

        
        /**
         * Wrapper for the deserialization function, will invoke the extension mapper instead
         * @param  _updateExternalUserStoreConfig adb_updateExternalUserStoreConfig_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs, 
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_updateExternalUserStoreConfig_deserialize(
            adb_updateExternalUserStoreConfig_t* _updateExternalUserStoreConfig,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);

        /**
         * Deserialize an XML to adb objects
         * @param  _updateExternalUserStoreConfig adb_updateExternalUserStoreConfig_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs,
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_updateExternalUserStoreConfig_deserialize_obj(
            adb_updateExternalUserStoreConfig_t* _updateExternalUserStoreConfig,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);
                            
            

       /**
         * Declare namespace in the most parent node 
         * @param  _updateExternalUserStoreConfig adb_updateExternalUserStoreConfig_t object
         * @param env pointer to environment struct
         * @param parent_element parent element
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index pointer to an int which contain the next namespace index
         */
       void AXIS2_CALL
       adb_updateExternalUserStoreConfig_declare_parent_namespaces(
                    adb_updateExternalUserStoreConfig_t* _updateExternalUserStoreConfig,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index);

        

        /**
         * Wrapper for the serialization function, will invoke the extension mapper instead
         * @param  _updateExternalUserStoreConfig adb_updateExternalUserStoreConfig_t object
         * @param env pointer to environment struct
         * @param updateExternalUserStoreConfig_om_node node to serialize from
         * @param updateExternalUserStoreConfig_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_updateExternalUserStoreConfig_serialize(
            adb_updateExternalUserStoreConfig_t* _updateExternalUserStoreConfig,
            const axutil_env_t *env,
            axiom_node_t* updateExternalUserStoreConfig_om_node, axiom_element_t *updateExternalUserStoreConfig_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Serialize to an XML from the adb objects
         * @param  _updateExternalUserStoreConfig adb_updateExternalUserStoreConfig_t object
         * @param env pointer to environment struct
         * @param updateExternalUserStoreConfig_om_node node to serialize from
         * @param updateExternalUserStoreConfig_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_updateExternalUserStoreConfig_serialize_obj(
            adb_updateExternalUserStoreConfig_t* _updateExternalUserStoreConfig,
            const axutil_env_t *env,
            axiom_node_t* updateExternalUserStoreConfig_om_node, axiom_element_t *updateExternalUserStoreConfig_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Check whether the adb_updateExternalUserStoreConfig is a particle class (E.g. group, inner sequence)
         * @return whether this is a particle class.
         */
        axis2_bool_t AXIS2_CALL
        adb_updateExternalUserStoreConfig_is_particle();

        /******************************* Alternatives for Create and Free functions *********************************/

        

        /**
         * Constructor for creating adb_updateExternalUserStoreConfig_t
         * @param env pointer to environment struct
         * @param _props axutil_array_list_t*
         * @return newly created adb_updateExternalUserStoreConfig_t object
         */
        adb_updateExternalUserStoreConfig_t* AXIS2_CALL
        adb_updateExternalUserStoreConfig_create_with_values(
            const axutil_env_t *env,
                axutil_array_list_t* _props);

        


                /**
                 * Free adb_updateExternalUserStoreConfig_t object and return the property value.
                 * You can use this to free the adb object as returning the property value. If there are
                 * many properties, it will only return the first property. Other properties will get freed with the adb object.
                 * @param  _updateExternalUserStoreConfig adb_updateExternalUserStoreConfig_t object to free
                 * @param env pointer to environment struct
                 * @return the property value holded by the ADB object, if there are many properties only returns the first.
                 */
                axutil_array_list_t* AXIS2_CALL
                adb_updateExternalUserStoreConfig_free_popping_value(
                        adb_updateExternalUserStoreConfig_t* _updateExternalUserStoreConfig,
                        const axutil_env_t *env);
            

        /******************************* get the value by the property number  *********************************/
        /************NOTE: This method is introduced to resolve a problem in unwrapping mode *******************/

        
        

        /**
         * Getter for props by property number (1)
         * @param  _updateExternalUserStoreConfig adb_updateExternalUserStoreConfig_t object
         * @param env pointer to environment struct
         * @return Array of adb_StoreProperty_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_updateExternalUserStoreConfig_get_property1(
            adb_updateExternalUserStoreConfig_t* _updateExternalUserStoreConfig,
            const axutil_env_t *env);

    
     #ifdef __cplusplus
     }
     #endif

     #endif /* ADB_UPDATEEXTERNALUSERSTORECONFIG_H */
    

