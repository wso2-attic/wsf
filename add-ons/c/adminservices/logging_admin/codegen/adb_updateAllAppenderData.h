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


        #ifndef ADB_UPDATEALLAPPENDERDATA_H
        #define ADB_UPDATEALLAPPENDERDATA_H

       /**
        * adb_updateAllAppenderData.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/Java version: #axisVersion# #today#
        */

       /**
        *  adb_updateAllAppenderData class
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
        

        typedef struct adb_updateAllAppenderData adb_updateAllAppenderData_t;

        
        

        /******************************* Create and Free functions *********************************/

        /**
         * Constructor for creating adb_updateAllAppenderData_t
         * @param env pointer to environment struct
         * @return newly created adb_updateAllAppenderData_t object
         */
        adb_updateAllAppenderData_t* AXIS2_CALL
        adb_updateAllAppenderData_create(
            const axutil_env_t *env );

        /**
         * Wrapper for the "free" function, will invoke the extension mapper instead
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_updateAllAppenderData_free (
            adb_updateAllAppenderData_t* _updateAllAppenderData,
            const axutil_env_t *env);

        /**
         * Free adb_updateAllAppenderData_t object
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_updateAllAppenderData_free_obj (
            adb_updateAllAppenderData_t* _updateAllAppenderData,
            const axutil_env_t *env);



        /********************************** Getters and Setters **************************************/
        
        

        /**
         * Getter for appenderName. 
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_updateAllAppenderData_get_appenderName(
            adb_updateAllAppenderData_t* _updateAllAppenderData,
            const axutil_env_t *env);

        /**
         * Setter for appenderName.
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @param arg_appenderName axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_updateAllAppenderData_set_appenderName(
            adb_updateAllAppenderData_t* _updateAllAppenderData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_appenderName);

        /**
         * Resetter for appenderName
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_updateAllAppenderData_reset_appenderName(
            adb_updateAllAppenderData_t* _updateAllAppenderData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for appenderPattern. 
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_updateAllAppenderData_get_appenderPattern(
            adb_updateAllAppenderData_t* _updateAllAppenderData,
            const axutil_env_t *env);

        /**
         * Setter for appenderPattern.
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @param arg_appenderPattern axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_updateAllAppenderData_set_appenderPattern(
            adb_updateAllAppenderData_t* _updateAllAppenderData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_appenderPattern);

        /**
         * Resetter for appenderPattern
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_updateAllAppenderData_reset_appenderPattern(
            adb_updateAllAppenderData_t* _updateAllAppenderData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for threshold. 
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_updateAllAppenderData_get_threshold(
            adb_updateAllAppenderData_t* _updateAllAppenderData,
            const axutil_env_t *env);

        /**
         * Setter for threshold.
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @param arg_threshold axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_updateAllAppenderData_set_threshold(
            adb_updateAllAppenderData_t* _updateAllAppenderData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_threshold);

        /**
         * Resetter for threshold
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_updateAllAppenderData_reset_threshold(
            adb_updateAllAppenderData_t* _updateAllAppenderData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for logFileName. 
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_updateAllAppenderData_get_logFileName(
            adb_updateAllAppenderData_t* _updateAllAppenderData,
            const axutil_env_t *env);

        /**
         * Setter for logFileName.
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @param arg_logFileName axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_updateAllAppenderData_set_logFileName(
            adb_updateAllAppenderData_t* _updateAllAppenderData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_logFileName);

        /**
         * Resetter for logFileName
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_updateAllAppenderData_reset_logFileName(
            adb_updateAllAppenderData_t* _updateAllAppenderData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for sysLogHost. 
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_updateAllAppenderData_get_sysLogHost(
            adb_updateAllAppenderData_t* _updateAllAppenderData,
            const axutil_env_t *env);

        /**
         * Setter for sysLogHost.
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @param arg_sysLogHost axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_updateAllAppenderData_set_sysLogHost(
            adb_updateAllAppenderData_t* _updateAllAppenderData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_sysLogHost);

        /**
         * Resetter for sysLogHost
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_updateAllAppenderData_reset_sysLogHost(
            adb_updateAllAppenderData_t* _updateAllAppenderData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for facility. 
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_updateAllAppenderData_get_facility(
            adb_updateAllAppenderData_t* _updateAllAppenderData,
            const axutil_env_t *env);

        /**
         * Setter for facility.
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @param arg_facility axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_updateAllAppenderData_set_facility(
            adb_updateAllAppenderData_t* _updateAllAppenderData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_facility);

        /**
         * Resetter for facility
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_updateAllAppenderData_reset_facility(
            adb_updateAllAppenderData_t* _updateAllAppenderData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for persist. 
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_updateAllAppenderData_get_persist(
            adb_updateAllAppenderData_t* _updateAllAppenderData,
            const axutil_env_t *env);

        /**
         * Setter for persist.
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @param arg_persist axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_updateAllAppenderData_set_persist(
            adb_updateAllAppenderData_t* _updateAllAppenderData,
            const axutil_env_t *env,
            axis2_bool_t  arg_persist);

        /**
         * Resetter for persist
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_updateAllAppenderData_reset_persist(
            adb_updateAllAppenderData_t* _updateAllAppenderData,
            const axutil_env_t *env);

        


        /******************************* Checking and Setting NIL values *********************************/
        

        /**
         * NOTE: set_nil is only available for nillable properties
         */

        

        /**
         * Check whether appenderName is nill
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_updateAllAppenderData_is_appenderName_nil(
                adb_updateAllAppenderData_t* _updateAllAppenderData,
                const axutil_env_t *env);


        
        /**
         * Set appenderName to nill (currently the same as reset)
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_updateAllAppenderData_set_appenderName_nil(
                adb_updateAllAppenderData_t* _updateAllAppenderData,
                const axutil_env_t *env);
        

        /**
         * Check whether appenderPattern is nill
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_updateAllAppenderData_is_appenderPattern_nil(
                adb_updateAllAppenderData_t* _updateAllAppenderData,
                const axutil_env_t *env);


        
        /**
         * Set appenderPattern to nill (currently the same as reset)
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_updateAllAppenderData_set_appenderPattern_nil(
                adb_updateAllAppenderData_t* _updateAllAppenderData,
                const axutil_env_t *env);
        

        /**
         * Check whether threshold is nill
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_updateAllAppenderData_is_threshold_nil(
                adb_updateAllAppenderData_t* _updateAllAppenderData,
                const axutil_env_t *env);


        
        /**
         * Set threshold to nill (currently the same as reset)
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_updateAllAppenderData_set_threshold_nil(
                adb_updateAllAppenderData_t* _updateAllAppenderData,
                const axutil_env_t *env);
        

        /**
         * Check whether logFileName is nill
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_updateAllAppenderData_is_logFileName_nil(
                adb_updateAllAppenderData_t* _updateAllAppenderData,
                const axutil_env_t *env);


        
        /**
         * Set logFileName to nill (currently the same as reset)
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_updateAllAppenderData_set_logFileName_nil(
                adb_updateAllAppenderData_t* _updateAllAppenderData,
                const axutil_env_t *env);
        

        /**
         * Check whether sysLogHost is nill
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_updateAllAppenderData_is_sysLogHost_nil(
                adb_updateAllAppenderData_t* _updateAllAppenderData,
                const axutil_env_t *env);


        
        /**
         * Set sysLogHost to nill (currently the same as reset)
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_updateAllAppenderData_set_sysLogHost_nil(
                adb_updateAllAppenderData_t* _updateAllAppenderData,
                const axutil_env_t *env);
        

        /**
         * Check whether facility is nill
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_updateAllAppenderData_is_facility_nil(
                adb_updateAllAppenderData_t* _updateAllAppenderData,
                const axutil_env_t *env);


        
        /**
         * Set facility to nill (currently the same as reset)
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_updateAllAppenderData_set_facility_nil(
                adb_updateAllAppenderData_t* _updateAllAppenderData,
                const axutil_env_t *env);
        

        /**
         * Check whether persist is nill
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_updateAllAppenderData_is_persist_nil(
                adb_updateAllAppenderData_t* _updateAllAppenderData,
                const axutil_env_t *env);


        

        /**************************** Serialize and Deserialize functions ***************************/
        /*********** These functions are for use only inside the generated code *********************/

        
        /**
         * Wrapper for the deserialization function, will invoke the extension mapper instead
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs, 
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_updateAllAppenderData_deserialize(
            adb_updateAllAppenderData_t* _updateAllAppenderData,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);

        /**
         * Deserialize an XML to adb objects
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs,
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_updateAllAppenderData_deserialize_obj(
            adb_updateAllAppenderData_t* _updateAllAppenderData,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);
                            
            

       /**
         * Declare namespace in the most parent node 
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @param parent_element parent element
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index pointer to an int which contain the next namespace index
         */
       void AXIS2_CALL
       adb_updateAllAppenderData_declare_parent_namespaces(
                    adb_updateAllAppenderData_t* _updateAllAppenderData,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index);

        

        /**
         * Wrapper for the serialization function, will invoke the extension mapper instead
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @param updateAllAppenderData_om_node node to serialize from
         * @param updateAllAppenderData_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_updateAllAppenderData_serialize(
            adb_updateAllAppenderData_t* _updateAllAppenderData,
            const axutil_env_t *env,
            axiom_node_t* updateAllAppenderData_om_node, axiom_element_t *updateAllAppenderData_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Serialize to an XML from the adb objects
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @param updateAllAppenderData_om_node node to serialize from
         * @param updateAllAppenderData_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_updateAllAppenderData_serialize_obj(
            adb_updateAllAppenderData_t* _updateAllAppenderData,
            const axutil_env_t *env,
            axiom_node_t* updateAllAppenderData_om_node, axiom_element_t *updateAllAppenderData_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Check whether the adb_updateAllAppenderData is a particle class (E.g. group, inner sequence)
         * @return whether this is a particle class.
         */
        axis2_bool_t AXIS2_CALL
        adb_updateAllAppenderData_is_particle();

        /******************************* Alternatives for Create and Free functions *********************************/

        

        /**
         * Constructor for creating adb_updateAllAppenderData_t
         * @param env pointer to environment struct
         * @param _appenderName axis2_char_t*
         * @param _appenderPattern axis2_char_t*
         * @param _threshold axis2_char_t*
         * @param _logFileName axis2_char_t*
         * @param _sysLogHost axis2_char_t*
         * @param _facility axis2_char_t*
         * @param _persist axis2_bool_t
         * @return newly created adb_updateAllAppenderData_t object
         */
        adb_updateAllAppenderData_t* AXIS2_CALL
        adb_updateAllAppenderData_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _appenderName,
                axis2_char_t* _appenderPattern,
                axis2_char_t* _threshold,
                axis2_char_t* _logFileName,
                axis2_char_t* _sysLogHost,
                axis2_char_t* _facility,
                axis2_bool_t _persist);

        


                /**
                 * Free adb_updateAllAppenderData_t object and return the property value.
                 * You can use this to free the adb object as returning the property value. If there are
                 * many properties, it will only return the first property. Other properties will get freed with the adb object.
                 * @param  _updateAllAppenderData adb_updateAllAppenderData_t object to free
                 * @param env pointer to environment struct
                 * @return the property value holded by the ADB object, if there are many properties only returns the first.
                 */
                axis2_char_t* AXIS2_CALL
                adb_updateAllAppenderData_free_popping_value(
                        adb_updateAllAppenderData_t* _updateAllAppenderData,
                        const axutil_env_t *env);
            

        /******************************* get the value by the property number  *********************************/
        /************NOTE: This method is introduced to resolve a problem in unwrapping mode *******************/

        
        

        /**
         * Getter for appenderName by property number (1)
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_updateAllAppenderData_get_property1(
            adb_updateAllAppenderData_t* _updateAllAppenderData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for appenderPattern by property number (2)
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_updateAllAppenderData_get_property2(
            adb_updateAllAppenderData_t* _updateAllAppenderData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for threshold by property number (3)
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_updateAllAppenderData_get_property3(
            adb_updateAllAppenderData_t* _updateAllAppenderData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for logFileName by property number (4)
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_updateAllAppenderData_get_property4(
            adb_updateAllAppenderData_t* _updateAllAppenderData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for sysLogHost by property number (5)
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_updateAllAppenderData_get_property5(
            adb_updateAllAppenderData_t* _updateAllAppenderData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for facility by property number (6)
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_updateAllAppenderData_get_property6(
            adb_updateAllAppenderData_t* _updateAllAppenderData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for persist by property number (7)
         * @param  _updateAllAppenderData adb_updateAllAppenderData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_updateAllAppenderData_get_property7(
            adb_updateAllAppenderData_t* _updateAllAppenderData,
            const axutil_env_t *env);

    
     #ifdef __cplusplus
     }
     #endif

     #endif /* ADB_UPDATEALLAPPENDERDATA_H */
    

