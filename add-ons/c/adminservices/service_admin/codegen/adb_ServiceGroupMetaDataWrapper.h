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


        #ifndef ADB_SERVICEGROUPMETADATAWRAPPER_H
        #define ADB_SERVICEGROUPMETADATAWRAPPER_H

       /**
        * adb_ServiceGroupMetaDataWrapper.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/Java version: SNAPSHOT  Built on : Jan 19, 2010 (01:47:08 IST)
        */

       /**
        *  adb_ServiceGroupMetaDataWrapper class
        */

        
          #include "adb_ServiceGroupMetaData.h"
          

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
        

        typedef struct adb_ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t;

        
        

        /******************************* Create and Free functions *********************************/

        /**
         * Constructor for creating adb_ServiceGroupMetaDataWrapper_t
         * @param env pointer to environment struct
         * @return newly created adb_ServiceGroupMetaDataWrapper_t object
         */
        adb_ServiceGroupMetaDataWrapper_t* AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_create(
            const axutil_env_t *env );

        /**
         * Wrapper for the "free" function, will invoke the extension mapper instead
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_free (
            adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
            const axutil_env_t *env);

        /**
         * Free adb_ServiceGroupMetaDataWrapper_t object
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_free_obj (
            adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
            const axutil_env_t *env);



        /********************************** Getters and Setters **************************************/
        /******** Deprecated for array types, Use 'Getters and Setters for Arrays' instead ***********/
        

        /**
         * Getter for metadataList. Deprecated for array types, Use adb_ServiceGroupMetaDataWrapper_get_metadataList_at instead
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @return Array of adb_ServiceGroupMetaData_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_get_metadataList(
            adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
            const axutil_env_t *env);

        /**
         * Setter for metadataList.Deprecated for array types, Use adb_ServiceGroupMetaDataWrapper_set_metadataList_at
         * or adb_ServiceGroupMetaDataWrapper_add_metadataList instead.
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @param arg_metadataList Array of adb_ServiceGroupMetaData_t*s.
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_set_metadataList(
            adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
            const axutil_env_t *env,
            axutil_array_list_t*  arg_metadataList);

        /**
         * Resetter for metadataList
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_reset_metadataList(
            adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
            const axutil_env_t *env);

        
        

        /**
         * Getter for numberOfCorrectServiceGroups. 
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @return int
         */
        int AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_get_numberOfCorrectServiceGroups(
            adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
            const axutil_env_t *env);

        /**
         * Setter for numberOfCorrectServiceGroups.
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @param arg_numberOfCorrectServiceGroups int
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_set_numberOfCorrectServiceGroups(
            adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
            const axutil_env_t *env,
            const int  arg_numberOfCorrectServiceGroups);

        /**
         * Resetter for numberOfCorrectServiceGroups
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_reset_numberOfCorrectServiceGroups(
            adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
            const axutil_env_t *env);

        
        

        /**
         * Getter for numberOfFaultyServiceGroups. 
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @return int
         */
        int AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_get_numberOfFaultyServiceGroups(
            adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
            const axutil_env_t *env);

        /**
         * Setter for numberOfFaultyServiceGroups.
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @param arg_numberOfFaultyServiceGroups int
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_set_numberOfFaultyServiceGroups(
            adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
            const axutil_env_t *env,
            const int  arg_numberOfFaultyServiceGroups);

        /**
         * Resetter for numberOfFaultyServiceGroups
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_reset_numberOfFaultyServiceGroups(
            adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
            const axutil_env_t *env);

        
        

        /**
         * Getter for numberOfPages. 
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @return int
         */
        int AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_get_numberOfPages(
            adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
            const axutil_env_t *env);

        /**
         * Setter for numberOfPages.
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @param arg_numberOfPages int
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_set_numberOfPages(
            adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
            const axutil_env_t *env,
            const int  arg_numberOfPages);

        /**
         * Resetter for numberOfPages
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_reset_numberOfPages(
            adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
            const axutil_env_t *env);

        
        

        /**
         * Getter for serviceTypes. Deprecated for array types, Use adb_ServiceGroupMetaDataWrapper_get_serviceTypes_at instead
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @return Array of axis2_char_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_get_serviceTypes(
            adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
            const axutil_env_t *env);

        /**
         * Setter for serviceTypes.Deprecated for array types, Use adb_ServiceGroupMetaDataWrapper_set_serviceTypes_at
         * or adb_ServiceGroupMetaDataWrapper_add_serviceTypes instead.
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @param arg_serviceTypes Array of axis2_char_t*s.
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_set_serviceTypes(
            adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
            const axutil_env_t *env,
            axutil_array_list_t*  arg_serviceTypes);

        /**
         * Resetter for serviceTypes
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_reset_serviceTypes(
            adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
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
         * Get the ith element of metadataList.
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @return ith adb_ServiceGroupMetaData_t* of the array
         */
        adb_ServiceGroupMetaData_t* AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_get_metadataList_at(
                adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
                const axutil_env_t *env, int i);

        /**
         * Set the ith element of metadataList. (If the ith already exist, it will be replaced)
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @param arg_metadataList element to set adb_ServiceGroupMetaData_t* to the array
         * @return ith adb_ServiceGroupMetaData_t* of the array
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_set_metadataList_at(
                adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
                const axutil_env_t *env, int i,
                adb_ServiceGroupMetaData_t* arg_metadataList);


        /**
         * Add to metadataList.
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @param arg_metadataList element to add adb_ServiceGroupMetaData_t* to the array
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_add_metadataList(
                adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
                const axutil_env_t *env,
                adb_ServiceGroupMetaData_t* arg_metadataList);

        /**
         * Get the size of the metadataList array.
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct.
         * @return the size of the metadataList array.
         */
        int AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_sizeof_metadataList(
                    adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
                    const axutil_env_t *env);

        /**
         * Remove the ith element of metadataList.
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @param i index of the item to remove
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_remove_metadataList_at(
                adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
                const axutil_env_t *env, int i);

        
        
        /**
         * Get the ith element of serviceTypes.
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @return ith axis2_char_t* of the array
         */
        axis2_char_t* AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_get_serviceTypes_at(
                adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
                const axutil_env_t *env, int i);

        /**
         * Set the ith element of serviceTypes. (If the ith already exist, it will be replaced)
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @param arg_serviceTypes element to set axis2_char_t* to the array
         * @return ith axis2_char_t* of the array
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_set_serviceTypes_at(
                adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
                const axutil_env_t *env, int i,
                const axis2_char_t* arg_serviceTypes);


        /**
         * Add to serviceTypes.
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @param arg_serviceTypes element to add axis2_char_t* to the array
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_add_serviceTypes(
                adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
                const axutil_env_t *env,
                const axis2_char_t* arg_serviceTypes);

        /**
         * Get the size of the serviceTypes array.
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct.
         * @return the size of the serviceTypes array.
         */
        int AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_sizeof_serviceTypes(
                    adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
                    const axutil_env_t *env);

        /**
         * Remove the ith element of serviceTypes.
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @param i index of the item to remove
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_remove_serviceTypes_at(
                adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
                const axutil_env_t *env, int i);

        


        /******************************* Checking and Setting NIL values *********************************/
        /* Use 'Checking and Setting NIL values for Arrays' to check and set nil for individual elements */

        /**
         * NOTE: set_nil is only available for nillable properties
         */

        

        /**
         * Check whether metadataList is nill
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_is_metadataList_nil(
                adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
                const axutil_env_t *env);


        
        /**
         * Set metadataList to nill (currently the same as reset)
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_set_metadataList_nil(
                adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
                const axutil_env_t *env);
        

        /**
         * Check whether numberOfCorrectServiceGroups is nill
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_is_numberOfCorrectServiceGroups_nil(
                adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
                const axutil_env_t *env);


        

        /**
         * Check whether numberOfFaultyServiceGroups is nill
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_is_numberOfFaultyServiceGroups_nil(
                adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
                const axutil_env_t *env);


        

        /**
         * Check whether numberOfPages is nill
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_is_numberOfPages_nil(
                adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
                const axutil_env_t *env);


        

        /**
         * Check whether serviceTypes is nill
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_is_serviceTypes_nil(
                adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
                const axutil_env_t *env);


        
        /**
         * Set serviceTypes to nill (currently the same as reset)
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_set_serviceTypes_nil(
                adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
                const axutil_env_t *env);
        
        /*************************** Checking and Setting 'NIL' values in Arrays *****************************/

        /**
         * NOTE: You may set this to remove specific elements in the array
         *       But you can not remove elements, if the specific property is declared to be non-nillable or sizeof(array) < minOccurs
         */
        
        /**
         * Check whether metadataList is nill at i
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct.
         * @param i index of the item to return.
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_is_metadataList_nil_at(
                adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
                const axutil_env_t *env, int i);
 
       
        /**
         * Set metadataList to nill at i
         * @param  _ServiceGroupMetaDataWrapper _ adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct.
         * @param i index of the item to set.
         * @return AXIS2_SUCCESS on success, or AXIS2_FAILURE otherwise.
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_set_metadataList_nil_at(
                adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper, 
                const axutil_env_t *env, int i);

        
        /**
         * Check whether serviceTypes is nill at i
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct.
         * @param i index of the item to return.
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_is_serviceTypes_nil_at(
                adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
                const axutil_env_t *env, int i);
 
       
        /**
         * Set serviceTypes to nill at i
         * @param  _ServiceGroupMetaDataWrapper _ adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct.
         * @param i index of the item to set.
         * @return AXIS2_SUCCESS on success, or AXIS2_FAILURE otherwise.
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_set_serviceTypes_nil_at(
                adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper, 
                const axutil_env_t *env, int i);

        

        /**************************** Serialize and Deserialize functions ***************************/
        /*********** These functions are for use only inside the generated code *********************/

        
        /**
         * Wrapper for the deserialization function, will invoke the extension mapper instead
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs, 
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_deserialize(
            adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);

        /**
         * Deserialize an XML to adb objects
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs,
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_deserialize_obj(
            adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);
                            
            

       /**
         * Declare namespace in the most parent node 
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @param parent_element parent element
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index pointer to an int which contain the next namespace index
         */
       void AXIS2_CALL
       adb_ServiceGroupMetaDataWrapper_declare_parent_namespaces(
                    adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index);

        

        /**
         * Wrapper for the serialization function, will invoke the extension mapper instead
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @param ServiceGroupMetaDataWrapper_om_node node to serialize from
         * @param ServiceGroupMetaDataWrapper_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_serialize(
            adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
            const axutil_env_t *env,
            axiom_node_t* ServiceGroupMetaDataWrapper_om_node, axiom_element_t *ServiceGroupMetaDataWrapper_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Serialize to an XML from the adb objects
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @param ServiceGroupMetaDataWrapper_om_node node to serialize from
         * @param ServiceGroupMetaDataWrapper_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_serialize_obj(
            adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
            const axutil_env_t *env,
            axiom_node_t* ServiceGroupMetaDataWrapper_om_node, axiom_element_t *ServiceGroupMetaDataWrapper_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Check whether the adb_ServiceGroupMetaDataWrapper is a particle class (E.g. group, inner sequence)
         * @return whether this is a particle class.
         */
        axis2_bool_t AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_is_particle();

        /******************************* Alternatives for Create and Free functions *********************************/

        

        /**
         * Constructor for creating adb_ServiceGroupMetaDataWrapper_t
         * @param env pointer to environment struct
         * @param _metadataList axutil_array_list_t*
         * @param _numberOfCorrectServiceGroups int
         * @param _numberOfFaultyServiceGroups int
         * @param _numberOfPages int
         * @param _serviceTypes axutil_array_list_t*
         * @return newly created adb_ServiceGroupMetaDataWrapper_t object
         */
        adb_ServiceGroupMetaDataWrapper_t* AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_create_with_values(
            const axutil_env_t *env,
                axutil_array_list_t* _metadataList,
                int _numberOfCorrectServiceGroups,
                int _numberOfFaultyServiceGroups,
                int _numberOfPages,
                axutil_array_list_t* _serviceTypes);

        


                /**
                 * Free adb_ServiceGroupMetaDataWrapper_t object and return the property value.
                 * You can use this to free the adb object as returning the property value. If there are
                 * many properties, it will only return the first property. Other properties will get freed with the adb object.
                 * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object to free
                 * @param env pointer to environment struct
                 * @return the property value holded by the ADB object, if there are many properties only returns the first.
                 */
                axutil_array_list_t* AXIS2_CALL
                adb_ServiceGroupMetaDataWrapper_free_popping_value(
                        adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
                        const axutil_env_t *env);
            

        /******************************* get the value by the property number  *********************************/
        /************NOTE: This method is introduced to resolve a problem in unwrapping mode *******************/

        
        

        /**
         * Getter for metadataList by property number (1)
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @return Array of adb_ServiceGroupMetaData_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_get_property1(
            adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
            const axutil_env_t *env);

    
        

        /**
         * Getter for numberOfCorrectServiceGroups by property number (2)
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @return int
         */
        int AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_get_property2(
            adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
            const axutil_env_t *env);

    
        

        /**
         * Getter for numberOfFaultyServiceGroups by property number (3)
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @return int
         */
        int AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_get_property3(
            adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
            const axutil_env_t *env);

    
        

        /**
         * Getter for numberOfPages by property number (4)
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @return int
         */
        int AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_get_property4(
            adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
            const axutil_env_t *env);

    
        

        /**
         * Getter for serviceTypes by property number (5)
         * @param  _ServiceGroupMetaDataWrapper adb_ServiceGroupMetaDataWrapper_t object
         * @param env pointer to environment struct
         * @return Array of axis2_char_t*s.
         */
        axutil_array_list_t* AXIS2_CALL
        adb_ServiceGroupMetaDataWrapper_get_property5(
            adb_ServiceGroupMetaDataWrapper_t* _ServiceGroupMetaDataWrapper,
            const axutil_env_t *env);

    
     #ifdef __cplusplus
     }
     #endif

     #endif /* ADB_SERVICEGROUPMETADATAWRAPPER_H */
    

