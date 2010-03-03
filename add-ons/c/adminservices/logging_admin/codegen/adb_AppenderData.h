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


        #ifndef ADB_APPENDERDATA_H
        #define ADB_APPENDERDATA_H

       /**
        * adb_AppenderData.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/Java version: #axisVersion# #today#
        */

       /**
        *  adb_AppenderData class
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
        

        typedef struct adb_AppenderData adb_AppenderData_t;

        
        

        /******************************* Create and Free functions *********************************/

        /**
         * Constructor for creating adb_AppenderData_t
         * @param env pointer to environment struct
         * @return newly created adb_AppenderData_t object
         */
        adb_AppenderData_t* AXIS2_CALL
        adb_AppenderData_create(
            const axutil_env_t *env );

        /**
         * Wrapper for the "free" function, will invoke the extension mapper instead
         * @param  _AppenderData adb_AppenderData_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_AppenderData_free (
            adb_AppenderData_t* _AppenderData,
            const axutil_env_t *env);

        /**
         * Free adb_AppenderData_t object
         * @param  _AppenderData adb_AppenderData_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_AppenderData_free_obj (
            adb_AppenderData_t* _AppenderData,
            const axutil_env_t *env);



        /********************************** Getters and Setters **************************************/
        
        

        /**
         * Getter for facility. 
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_AppenderData_get_facility(
            adb_AppenderData_t* _AppenderData,
            const axutil_env_t *env);

        /**
         * Setter for facility.
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @param arg_facility axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_AppenderData_set_facility(
            adb_AppenderData_t* _AppenderData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_facility);

        /**
         * Resetter for facility
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_AppenderData_reset_facility(
            adb_AppenderData_t* _AppenderData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for isFileAppender. 
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_AppenderData_get_isFileAppender(
            adb_AppenderData_t* _AppenderData,
            const axutil_env_t *env);

        /**
         * Setter for isFileAppender.
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @param arg_isFileAppender axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_AppenderData_set_isFileAppender(
            adb_AppenderData_t* _AppenderData,
            const axutil_env_t *env,
            axis2_bool_t  arg_isFileAppender);

        /**
         * Resetter for isFileAppender
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_AppenderData_reset_isFileAppender(
            adb_AppenderData_t* _AppenderData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for isSysLogAppender. 
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_AppenderData_get_isSysLogAppender(
            adb_AppenderData_t* _AppenderData,
            const axutil_env_t *env);

        /**
         * Setter for isSysLogAppender.
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @param arg_isSysLogAppender axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_AppenderData_set_isSysLogAppender(
            adb_AppenderData_t* _AppenderData,
            const axutil_env_t *env,
            axis2_bool_t  arg_isSysLogAppender);

        /**
         * Resetter for isSysLogAppender
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_AppenderData_reset_isSysLogAppender(
            adb_AppenderData_t* _AppenderData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for logFile. 
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_AppenderData_get_logFile(
            adb_AppenderData_t* _AppenderData,
            const axutil_env_t *env);

        /**
         * Setter for logFile.
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @param arg_logFile axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_AppenderData_set_logFile(
            adb_AppenderData_t* _AppenderData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_logFile);

        /**
         * Resetter for logFile
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_AppenderData_reset_logFile(
            adb_AppenderData_t* _AppenderData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for name. 
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_AppenderData_get_name(
            adb_AppenderData_t* _AppenderData,
            const axutil_env_t *env);

        /**
         * Setter for name.
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @param arg_name axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_AppenderData_set_name(
            adb_AppenderData_t* _AppenderData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_name);

        /**
         * Resetter for name
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_AppenderData_reset_name(
            adb_AppenderData_t* _AppenderData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for pattern. 
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_AppenderData_get_pattern(
            adb_AppenderData_t* _AppenderData,
            const axutil_env_t *env);

        /**
         * Setter for pattern.
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @param arg_pattern axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_AppenderData_set_pattern(
            adb_AppenderData_t* _AppenderData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_pattern);

        /**
         * Resetter for pattern
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_AppenderData_reset_pattern(
            adb_AppenderData_t* _AppenderData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for sysLogHost. 
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_AppenderData_get_sysLogHost(
            adb_AppenderData_t* _AppenderData,
            const axutil_env_t *env);

        /**
         * Setter for sysLogHost.
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @param arg_sysLogHost axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_AppenderData_set_sysLogHost(
            adb_AppenderData_t* _AppenderData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_sysLogHost);

        /**
         * Resetter for sysLogHost
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_AppenderData_reset_sysLogHost(
            adb_AppenderData_t* _AppenderData,
            const axutil_env_t *env);

        
        

        /**
         * Getter for threshold. 
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_AppenderData_get_threshold(
            adb_AppenderData_t* _AppenderData,
            const axutil_env_t *env);

        /**
         * Setter for threshold.
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @param arg_threshold axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_AppenderData_set_threshold(
            adb_AppenderData_t* _AppenderData,
            const axutil_env_t *env,
            const axis2_char_t*  arg_threshold);

        /**
         * Resetter for threshold
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_AppenderData_reset_threshold(
            adb_AppenderData_t* _AppenderData,
            const axutil_env_t *env);

        


        /******************************* Checking and Setting NIL values *********************************/
        

        /**
         * NOTE: set_nil is only available for nillable properties
         */

        

        /**
         * Check whether facility is nill
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_AppenderData_is_facility_nil(
                adb_AppenderData_t* _AppenderData,
                const axutil_env_t *env);


        
        /**
         * Set facility to nill (currently the same as reset)
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_AppenderData_set_facility_nil(
                adb_AppenderData_t* _AppenderData,
                const axutil_env_t *env);
        

        /**
         * Check whether isFileAppender is nill
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_AppenderData_is_isFileAppender_nil(
                adb_AppenderData_t* _AppenderData,
                const axutil_env_t *env);


        

        /**
         * Check whether isSysLogAppender is nill
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_AppenderData_is_isSysLogAppender_nil(
                adb_AppenderData_t* _AppenderData,
                const axutil_env_t *env);


        

        /**
         * Check whether logFile is nill
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_AppenderData_is_logFile_nil(
                adb_AppenderData_t* _AppenderData,
                const axutil_env_t *env);


        
        /**
         * Set logFile to nill (currently the same as reset)
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_AppenderData_set_logFile_nil(
                adb_AppenderData_t* _AppenderData,
                const axutil_env_t *env);
        

        /**
         * Check whether name is nill
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_AppenderData_is_name_nil(
                adb_AppenderData_t* _AppenderData,
                const axutil_env_t *env);


        
        /**
         * Set name to nill (currently the same as reset)
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_AppenderData_set_name_nil(
                adb_AppenderData_t* _AppenderData,
                const axutil_env_t *env);
        

        /**
         * Check whether pattern is nill
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_AppenderData_is_pattern_nil(
                adb_AppenderData_t* _AppenderData,
                const axutil_env_t *env);


        
        /**
         * Set pattern to nill (currently the same as reset)
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_AppenderData_set_pattern_nil(
                adb_AppenderData_t* _AppenderData,
                const axutil_env_t *env);
        

        /**
         * Check whether sysLogHost is nill
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_AppenderData_is_sysLogHost_nil(
                adb_AppenderData_t* _AppenderData,
                const axutil_env_t *env);


        
        /**
         * Set sysLogHost to nill (currently the same as reset)
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_AppenderData_set_sysLogHost_nil(
                adb_AppenderData_t* _AppenderData,
                const axutil_env_t *env);
        

        /**
         * Check whether threshold is nill
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_AppenderData_is_threshold_nil(
                adb_AppenderData_t* _AppenderData,
                const axutil_env_t *env);


        
        /**
         * Set threshold to nill (currently the same as reset)
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_AppenderData_set_threshold_nil(
                adb_AppenderData_t* _AppenderData,
                const axutil_env_t *env);
        

        /**************************** Serialize and Deserialize functions ***************************/
        /*********** These functions are for use only inside the generated code *********************/

        
        /**
         * Wrapper for the deserialization function, will invoke the extension mapper instead
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs, 
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_AppenderData_deserialize(
            adb_AppenderData_t* _AppenderData,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);

        /**
         * Deserialize an XML to adb objects
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs,
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_AppenderData_deserialize_obj(
            adb_AppenderData_t* _AppenderData,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);
                            
            

       /**
         * Declare namespace in the most parent node 
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @param parent_element parent element
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index pointer to an int which contain the next namespace index
         */
       void AXIS2_CALL
       adb_AppenderData_declare_parent_namespaces(
                    adb_AppenderData_t* _AppenderData,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index);

        

        /**
         * Wrapper for the serialization function, will invoke the extension mapper instead
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @param AppenderData_om_node node to serialize from
         * @param AppenderData_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_AppenderData_serialize(
            adb_AppenderData_t* _AppenderData,
            const axutil_env_t *env,
            axiom_node_t* AppenderData_om_node, axiom_element_t *AppenderData_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Serialize to an XML from the adb objects
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @param AppenderData_om_node node to serialize from
         * @param AppenderData_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_AppenderData_serialize_obj(
            adb_AppenderData_t* _AppenderData,
            const axutil_env_t *env,
            axiom_node_t* AppenderData_om_node, axiom_element_t *AppenderData_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Check whether the adb_AppenderData is a particle class (E.g. group, inner sequence)
         * @return whether this is a particle class.
         */
        axis2_bool_t AXIS2_CALL
        adb_AppenderData_is_particle();

        /******************************* Alternatives for Create and Free functions *********************************/

        

        /**
         * Constructor for creating adb_AppenderData_t
         * @param env pointer to environment struct
         * @param _facility axis2_char_t*
         * @param _isFileAppender axis2_bool_t
         * @param _isSysLogAppender axis2_bool_t
         * @param _logFile axis2_char_t*
         * @param _name axis2_char_t*
         * @param _pattern axis2_char_t*
         * @param _sysLogHost axis2_char_t*
         * @param _threshold axis2_char_t*
         * @return newly created adb_AppenderData_t object
         */
        adb_AppenderData_t* AXIS2_CALL
        adb_AppenderData_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _facility,
                axis2_bool_t _isFileAppender,
                axis2_bool_t _isSysLogAppender,
                axis2_char_t* _logFile,
                axis2_char_t* _name,
                axis2_char_t* _pattern,
                axis2_char_t* _sysLogHost,
                axis2_char_t* _threshold);

        


                /**
                 * Free adb_AppenderData_t object and return the property value.
                 * You can use this to free the adb object as returning the property value. If there are
                 * many properties, it will only return the first property. Other properties will get freed with the adb object.
                 * @param  _AppenderData adb_AppenderData_t object to free
                 * @param env pointer to environment struct
                 * @return the property value holded by the ADB object, if there are many properties only returns the first.
                 */
                axis2_char_t* AXIS2_CALL
                adb_AppenderData_free_popping_value(
                        adb_AppenderData_t* _AppenderData,
                        const axutil_env_t *env);
            

        /******************************* get the value by the property number  *********************************/
        /************NOTE: This method is introduced to resolve a problem in unwrapping mode *******************/

        
        

        /**
         * Getter for facility by property number (1)
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_AppenderData_get_property1(
            adb_AppenderData_t* _AppenderData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for isFileAppender by property number (2)
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_AppenderData_get_property2(
            adb_AppenderData_t* _AppenderData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for isSysLogAppender by property number (3)
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_AppenderData_get_property3(
            adb_AppenderData_t* _AppenderData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for logFile by property number (4)
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_AppenderData_get_property4(
            adb_AppenderData_t* _AppenderData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for name by property number (5)
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_AppenderData_get_property5(
            adb_AppenderData_t* _AppenderData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for pattern by property number (6)
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_AppenderData_get_property6(
            adb_AppenderData_t* _AppenderData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for sysLogHost by property number (7)
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_AppenderData_get_property7(
            adb_AppenderData_t* _AppenderData,
            const axutil_env_t *env);

    
        

        /**
         * Getter for threshold by property number (8)
         * @param  _AppenderData adb_AppenderData_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_AppenderData_get_property8(
            adb_AppenderData_t* _AppenderData,
            const axutil_env_t *env);

    
     #ifdef __cplusplus
     }
     #endif

     #endif /* ADB_APPENDERDATA_H */
    

