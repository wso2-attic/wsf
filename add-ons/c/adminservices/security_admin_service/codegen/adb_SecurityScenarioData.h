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


        #ifndef ADB_SECURITYSCENARIODATA_H
        #define ADB_SECURITYSCENARIODATA_H

       /**
        * adb_SecurityScenarioData.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/Java version: #axisVersion# #today#
        */

       /**
        *  adb_SecurityScenarioData class
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
        

        typedef struct adb_SecurityScenarioData adb_SecurityScenarioData_t;

        
        

        /******************************* Create and Free functions *********************************/

        /**
         * Constructor for creating adb_SecurityScenarioData_t
         * @param env pointer to environment struct
         * @return newly created adb_SecurityScenarioData_t object
         */
        adb_SecurityScenarioData_t* AXIS2_CALL
        adb_SecurityScenarioData_create(
            const axutil_env_t *env );

        /**
         * Wrapper for the "free" function, will invoke the extension mapper instead
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SecurityScenarioData_free (
            adb_SecurityScenarioData_t* _SecurityScenarioData,
            const axutil_env_t *env);

        /**
         * Free adb_SecurityScenarioData_t object
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SecurityScenarioData_free_obj (
            adb_SecurityScenarioData_t* _SecurityScenarioData,
            const axutil_env_t *env);



        /********************************** Getters and Setters **************************************/
        
        

        /**
         * Getter for category. 
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_SecurityScenarioData_get_category(
            adb_SecurityScenarioData_t* _SecurityScenarioData,
            const axutil_env_t *env);

        /**
         * Setter for category.
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @param arg_category axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SecurityScenarioData_set_category(
            adb_SecurityScenarioData_t* _SecurityScenarioData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_category);

        /**
         * Resetter for category
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SecurityScenarioData_reset_category(
            adb_SecurityScenarioData_t* _SecurityScenarioData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for currentScenario. 
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_SecurityScenarioData_get_currentScenario(
            adb_SecurityScenarioData_t* _SecurityScenarioData,
            const axutil_env_t *env);

        /**
         * Setter for currentScenario.
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @param arg_currentScenario axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SecurityScenarioData_set_currentScenario(
            adb_SecurityScenarioData_t* _SecurityScenarioData,
            const axutil_env_t *env,
            axis2_bool_t  arg_currentScenario);

        /**
         * Resetter for currentScenario
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SecurityScenarioData_reset_currentScenario(
            adb_SecurityScenarioData_t* _SecurityScenarioData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for description. 
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_SecurityScenarioData_get_description(
            adb_SecurityScenarioData_t* _SecurityScenarioData,
            const axutil_env_t *env);

        /**
         * Setter for description.
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @param arg_description axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SecurityScenarioData_set_description(
            adb_SecurityScenarioData_t* _SecurityScenarioData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_description);

        /**
         * Resetter for description
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SecurityScenarioData_reset_description(
            adb_SecurityScenarioData_t* _SecurityScenarioData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for scenarioId. 
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_SecurityScenarioData_get_scenarioId(
            adb_SecurityScenarioData_t* _SecurityScenarioData,
            const axutil_env_t *env);

        /**
         * Setter for scenarioId.
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @param arg_scenarioId axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SecurityScenarioData_set_scenarioId(
            adb_SecurityScenarioData_t* _SecurityScenarioData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_scenarioId);

        /**
         * Resetter for scenarioId
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SecurityScenarioData_reset_scenarioId(
            adb_SecurityScenarioData_t* _SecurityScenarioData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for summary. 
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_SecurityScenarioData_get_summary(
            adb_SecurityScenarioData_t* _SecurityScenarioData,
            const axutil_env_t *env);

        /**
         * Setter for summary.
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @param arg_summary axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SecurityScenarioData_set_summary(
            adb_SecurityScenarioData_t* _SecurityScenarioData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_summary);

        /**
         * Resetter for summary
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SecurityScenarioData_reset_summary(
            adb_SecurityScenarioData_t* _SecurityScenarioData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for type. 
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_SecurityScenarioData_get_type(
            adb_SecurityScenarioData_t* _SecurityScenarioData,
            const axutil_env_t *env);

        /**
         * Setter for type.
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @param arg_type axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SecurityScenarioData_set_type(
            adb_SecurityScenarioData_t* _SecurityScenarioData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_type);

        /**
         * Resetter for type
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SecurityScenarioData_reset_type(
            adb_SecurityScenarioData_t* _SecurityScenarioData,
            const axutil_env_t *env);

        


        /******************************* Checking and Setting NIL values *********************************/
        

        /**
         * NOTE: set_nil is only available for nillable properties
         */

        

        /**
         * Check whether category is nill
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_SecurityScenarioData_is_category_nil(
                adb_SecurityScenarioData_t* _SecurityScenarioData,
                const axutil_env_t *env);


        
        /**
         * Set category to nill (currently the same as reset)
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SecurityScenarioData_set_category_nil(
                adb_SecurityScenarioData_t* _SecurityScenarioData,
                const axutil_env_t *env);
        

        /**
         * Check whether currentScenario is nill
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_SecurityScenarioData_is_currentScenario_nil(
                adb_SecurityScenarioData_t* _SecurityScenarioData,
                const axutil_env_t *env);


        

        /**
         * Check whether description is nill
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_SecurityScenarioData_is_description_nil(
                adb_SecurityScenarioData_t* _SecurityScenarioData,
                const axutil_env_t *env);


        
        /**
         * Set description to nill (currently the same as reset)
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SecurityScenarioData_set_description_nil(
                adb_SecurityScenarioData_t* _SecurityScenarioData,
                const axutil_env_t *env);
        

        /**
         * Check whether scenarioId is nill
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_SecurityScenarioData_is_scenarioId_nil(
                adb_SecurityScenarioData_t* _SecurityScenarioData,
                const axutil_env_t *env);


        
        /**
         * Set scenarioId to nill (currently the same as reset)
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SecurityScenarioData_set_scenarioId_nil(
                adb_SecurityScenarioData_t* _SecurityScenarioData,
                const axutil_env_t *env);
        

        /**
         * Check whether summary is nill
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_SecurityScenarioData_is_summary_nil(
                adb_SecurityScenarioData_t* _SecurityScenarioData,
                const axutil_env_t *env);


        
        /**
         * Set summary to nill (currently the same as reset)
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SecurityScenarioData_set_summary_nil(
                adb_SecurityScenarioData_t* _SecurityScenarioData,
                const axutil_env_t *env);
        

        /**
         * Check whether type is nill
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_SecurityScenarioData_is_type_nil(
                adb_SecurityScenarioData_t* _SecurityScenarioData,
                const axutil_env_t *env);


        
        /**
         * Set type to nill (currently the same as reset)
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SecurityScenarioData_set_type_nil(
                adb_SecurityScenarioData_t* _SecurityScenarioData,
                const axutil_env_t *env);
        

        /**************************** Serialize and Deserialize functions ***************************/
        /*********** These functions are for use only inside the generated code *********************/

        
        /**
         * Wrapper for the deserialization function, will invoke the extension mapper instead
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs, 
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SecurityScenarioData_deserialize(
            adb_SecurityScenarioData_t* _SecurityScenarioData,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);

        /**
         * Deserialize an XML to adb objects
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs,
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SecurityScenarioData_deserialize_obj(
            adb_SecurityScenarioData_t* _SecurityScenarioData,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);
                            
            

       /**
         * Declare namespace in the most parent node 
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @param parent_element parent element
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index pointer to an int which contain the next namespace index
         */
       void AXIS2_CALL
       adb_SecurityScenarioData_declare_parent_namespaces(
                    adb_SecurityScenarioData_t* _SecurityScenarioData,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index);

        

        /**
         * Wrapper for the serialization function, will invoke the extension mapper instead
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @param SecurityScenarioData_om_node node to serialize from
         * @param SecurityScenarioData_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_SecurityScenarioData_serialize(
            adb_SecurityScenarioData_t* _SecurityScenarioData,
            const axutil_env_t *env,
            axiom_node_t* SecurityScenarioData_om_node, axiom_element_t *SecurityScenarioData_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Serialize to an XML from the adb objects
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @param SecurityScenarioData_om_node node to serialize from
         * @param SecurityScenarioData_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_SecurityScenarioData_serialize_obj(
            adb_SecurityScenarioData_t* _SecurityScenarioData,
            const axutil_env_t *env,
            axiom_node_t* SecurityScenarioData_om_node, axiom_element_t *SecurityScenarioData_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Check whether the adb_SecurityScenarioData is a particle class (E.g. group, inner sequence)
         * @return whether this is a particle class.
         */
        axis2_bool_t AXIS2_CALL
        adb_SecurityScenarioData_is_particle();

        /******************************* Alternatives for Create and Free functions *********************************/

        

        /**
         * Constructor for creating adb_SecurityScenarioData_t
         * @param env pointer to environment struct
         * @param _category axis2_char_t*
         * @param _currentScenario axis2_bool_t
         * @param _description axis2_char_t*
         * @param _scenarioId axis2_char_t*
         * @param _summary axis2_char_t*
         * @param _type axis2_char_t*
         * @return newly created adb_SecurityScenarioData_t object
         */
        adb_SecurityScenarioData_t* AXIS2_CALL
        adb_SecurityScenarioData_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _category,
                axis2_bool_t _currentScenario,
                axis2_char_t* _description,
                axis2_char_t* _scenarioId,
                axis2_char_t* _summary,
                axis2_char_t* _type);

        


                /**
                 * Free adb_SecurityScenarioData_t object and return the property value.
                 * You can use this to free the adb object as returning the property value. If there are
                 * many properties, it will only return the first property. Other properties will get freed with the adb object.
                 * @param  _SecurityScenarioData adb_SecurityScenarioData_t object to free
                 * @param env pointer to environment struct
                 * @return the property value holded by the ADB object, if there are many properties only returns the first.
                 */
                axis2_char_t* AXIS2_CALL
                adb_SecurityScenarioData_free_popping_value(
                        adb_SecurityScenarioData_t* _SecurityScenarioData,
                        const axutil_env_t *env);
            

        /******************************* get the value by the property number  *********************************/
        /************NOTE: This method is introduced to resolve a problem in unwrapping mode *******************/

        
        

        /**
         * Getter for category by property number (1)
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_SecurityScenarioData_get_property1(
            adb_SecurityScenarioData_t* _SecurityScenarioData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for currentScenario by property number (2)
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_SecurityScenarioData_get_property2(
            adb_SecurityScenarioData_t* _SecurityScenarioData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for description by property number (3)
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_SecurityScenarioData_get_property3(
            adb_SecurityScenarioData_t* _SecurityScenarioData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for scenarioId by property number (4)
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_SecurityScenarioData_get_property4(
            adb_SecurityScenarioData_t* _SecurityScenarioData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for summary by property number (5)
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_SecurityScenarioData_get_property5(
            adb_SecurityScenarioData_t* _SecurityScenarioData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for type by property number (6)
         * @param  _SecurityScenarioData adb_SecurityScenarioData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_SecurityScenarioData_get_property6(
            adb_SecurityScenarioData_t* _SecurityScenarioData,
            const axutil_env_t *env);

    
     #ifdef __cplusplus
     }
     #endif

     #endif /* ADB_SECURITYSCENARIODATA_H */
    

