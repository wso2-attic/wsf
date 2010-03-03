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


        #ifndef ADB_LOGGERDATA_H
        #define ADB_LOGGERDATA_H

       /**
        * adb_LoggerData.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/Java version: #axisVersion# #today#
        */

       /**
        *  adb_LoggerData class
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
        

        typedef struct adb_LoggerData adb_LoggerData_t;

        
        

        /******************************* Create and Free functions *********************************/

        /**
         * Constructor for creating adb_LoggerData_t
         * @param env pointer to environment struct
         * @return newly created adb_LoggerData_t object
         */
        adb_LoggerData_t* AXIS2_CALL
        adb_LoggerData_create(
            const axutil_env_t *env );

        /**
         * Wrapper for the "free" function, will invoke the extension mapper instead
         * @param  _LoggerData adb_LoggerData_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_LoggerData_free (
            adb_LoggerData_t* _LoggerData,
            const axutil_env_t *env);

        /**
         * Free adb_LoggerData_t object
         * @param  _LoggerData adb_LoggerData_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_LoggerData_free_obj (
            adb_LoggerData_t* _LoggerData,
            const axutil_env_t *env);



        /********************************** Getters and Setters **************************************/
        
        

        /**
         * Getter for additivity. 
         * @param  _LoggerData adb_LoggerData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_LoggerData_get_additivity(
            adb_LoggerData_t* _LoggerData,
            const axutil_env_t *env);

        /**
         * Setter for additivity.
         * @param  _LoggerData adb_LoggerData_t object
         * @param env pointer to environment struct
         * @param arg_additivity axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_LoggerData_set_additivity(
            adb_LoggerData_t* _LoggerData,
            const axutil_env_t *env,
            axis2_bool_t  arg_additivity);

        /**
         * Resetter for additivity
         * @param  _LoggerData adb_LoggerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_LoggerData_reset_additivity(
            adb_LoggerData_t* _LoggerData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for level. 
         * @param  _LoggerData adb_LoggerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_LoggerData_get_level(
            adb_LoggerData_t* _LoggerData,
            const axutil_env_t *env);

        /**
         * Setter for level.
         * @param  _LoggerData adb_LoggerData_t object
         * @param env pointer to environment struct
         * @param arg_level axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_LoggerData_set_level(
            adb_LoggerData_t* _LoggerData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_level);

        /**
         * Resetter for level
         * @param  _LoggerData adb_LoggerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_LoggerData_reset_level(
            adb_LoggerData_t* _LoggerData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for name. 
         * @param  _LoggerData adb_LoggerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_LoggerData_get_name(
            adb_LoggerData_t* _LoggerData,
            const axutil_env_t *env);

        /**
         * Setter for name.
         * @param  _LoggerData adb_LoggerData_t object
         * @param env pointer to environment struct
         * @param arg_name axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_LoggerData_set_name(
            adb_LoggerData_t* _LoggerData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_name);

        /**
         * Resetter for name
         * @param  _LoggerData adb_LoggerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_LoggerData_reset_name(
            adb_LoggerData_t* _LoggerData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for parentName. 
         * @param  _LoggerData adb_LoggerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_LoggerData_get_parentName(
            adb_LoggerData_t* _LoggerData,
            const axutil_env_t *env);

        /**
         * Setter for parentName.
         * @param  _LoggerData adb_LoggerData_t object
         * @param env pointer to environment struct
         * @param arg_parentName axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_LoggerData_set_parentName(
            adb_LoggerData_t* _LoggerData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_parentName);

        /**
         * Resetter for parentName
         * @param  _LoggerData adb_LoggerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_LoggerData_reset_parentName(
            adb_LoggerData_t* _LoggerData,
            const axutil_env_t *env);

        


        /******************************* Checking and Setting NIL values *********************************/
        

        /**
         * NOTE: set_nil is only available for nillable properties
         */

        

        /**
         * Check whether additivity is nill
         * @param  _LoggerData adb_LoggerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_LoggerData_is_additivity_nil(
                adb_LoggerData_t* _LoggerData,
                const axutil_env_t *env);


        

        /**
         * Check whether level is nill
         * @param  _LoggerData adb_LoggerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_LoggerData_is_level_nil(
                adb_LoggerData_t* _LoggerData,
                const axutil_env_t *env);


        
        /**
         * Set level to nill (currently the same as reset)
         * @param  _LoggerData adb_LoggerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_LoggerData_set_level_nil(
                adb_LoggerData_t* _LoggerData,
                const axutil_env_t *env);
        

        /**
         * Check whether name is nill
         * @param  _LoggerData adb_LoggerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_LoggerData_is_name_nil(
                adb_LoggerData_t* _LoggerData,
                const axutil_env_t *env);


        
        /**
         * Set name to nill (currently the same as reset)
         * @param  _LoggerData adb_LoggerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_LoggerData_set_name_nil(
                adb_LoggerData_t* _LoggerData,
                const axutil_env_t *env);
        

        /**
         * Check whether parentName is nill
         * @param  _LoggerData adb_LoggerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_LoggerData_is_parentName_nil(
                adb_LoggerData_t* _LoggerData,
                const axutil_env_t *env);


        
        /**
         * Set parentName to nill (currently the same as reset)
         * @param  _LoggerData adb_LoggerData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_LoggerData_set_parentName_nil(
                adb_LoggerData_t* _LoggerData,
                const axutil_env_t *env);
        

        /**************************** Serialize and Deserialize functions ***************************/
        /*********** These functions are for use only inside the generated code *********************/

        
        /**
         * Wrapper for the deserialization function, will invoke the extension mapper instead
         * @param  _LoggerData adb_LoggerData_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs, 
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_LoggerData_deserialize(
            adb_LoggerData_t* _LoggerData,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);

        /**
         * Deserialize an XML to adb objects
         * @param  _LoggerData adb_LoggerData_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs,
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_LoggerData_deserialize_obj(
            adb_LoggerData_t* _LoggerData,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);
                            
            

       /**
         * Declare namespace in the most parent node 
         * @param  _LoggerData adb_LoggerData_t object
         * @param env pointer to environment struct
         * @param parent_element parent element
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index pointer to an int which contain the next namespace index
         */
       void AXIS2_CALL
       adb_LoggerData_declare_parent_namespaces(
                    adb_LoggerData_t* _LoggerData,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index);

        

        /**
         * Wrapper for the serialization function, will invoke the extension mapper instead
         * @param  _LoggerData adb_LoggerData_t object
         * @param env pointer to environment struct
         * @param LoggerData_om_node node to serialize from
         * @param LoggerData_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_LoggerData_serialize(
            adb_LoggerData_t* _LoggerData,
            const axutil_env_t *env,
            axiom_node_t* LoggerData_om_node, axiom_element_t *LoggerData_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Serialize to an XML from the adb objects
         * @param  _LoggerData adb_LoggerData_t object
         * @param env pointer to environment struct
         * @param LoggerData_om_node node to serialize from
         * @param LoggerData_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_LoggerData_serialize_obj(
            adb_LoggerData_t* _LoggerData,
            const axutil_env_t *env,
            axiom_node_t* LoggerData_om_node, axiom_element_t *LoggerData_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Check whether the adb_LoggerData is a particle class (E.g. group, inner sequence)
         * @return whether this is a particle class.
         */
        axis2_bool_t AXIS2_CALL
        adb_LoggerData_is_particle();

        /******************************* Alternatives for Create and Free functions *********************************/

        

        /**
         * Constructor for creating adb_LoggerData_t
         * @param env pointer to environment struct
         * @param _additivity axis2_bool_t
         * @param _level axis2_char_t*
         * @param _name axis2_char_t*
         * @param _parentName axis2_char_t*
         * @return newly created adb_LoggerData_t object
         */
        adb_LoggerData_t* AXIS2_CALL
        adb_LoggerData_create_with_values(
            const axutil_env_t *env,
                axis2_bool_t _additivity,
                axis2_char_t* _level,
                axis2_char_t* _name,
                axis2_char_t* _parentName);

        


                /**
                 * Free adb_LoggerData_t object and return the property value.
                 * You can use this to free the adb object as returning the property value. If there are
                 * many properties, it will only return the first property. Other properties will get freed with the adb object.
                 * @param  _LoggerData adb_LoggerData_t object to free
                 * @param env pointer to environment struct
                 * @return the property value holded by the ADB object, if there are many properties only returns the first.
                 */
                axis2_bool_t AXIS2_CALL
                adb_LoggerData_free_popping_value(
                        adb_LoggerData_t* _LoggerData,
                        const axutil_env_t *env);
            

        /******************************* get the value by the property number  *********************************/
        /************NOTE: This method is introduced to resolve a problem in unwrapping mode *******************/

        
        

        /**
         * Getter for additivity by property number (1)
         * @param  _LoggerData adb_LoggerData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_LoggerData_get_property1(
            adb_LoggerData_t* _LoggerData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for level by property number (2)
         * @param  _LoggerData adb_LoggerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_LoggerData_get_property2(
            adb_LoggerData_t* _LoggerData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for name by property number (3)
         * @param  _LoggerData adb_LoggerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_LoggerData_get_property3(
            adb_LoggerData_t* _LoggerData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for parentName by property number (4)
         * @param  _LoggerData adb_LoggerData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_LoggerData_get_property4(
            adb_LoggerData_t* _LoggerData,
            const axutil_env_t *env);

    
     #ifdef __cplusplus
     }
     #endif

     #endif /* ADB_LOGGERDATA_H */
    

