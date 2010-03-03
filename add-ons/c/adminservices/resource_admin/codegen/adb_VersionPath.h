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


        #ifndef ADB_VERSIONPATH_H
        #define ADB_VERSIONPATH_H

       /**
        * adb_VersionPath.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/Java version: #axisVersion# #today#
        */

       /**
        *  adb_VersionPath class
        */

        
            #include <axutil_date_time.h>
          

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
        

        typedef struct adb_VersionPath adb_VersionPath_t;

        
        

        /******************************* Create and Free functions *********************************/

        /**
         * Constructor for creating adb_VersionPath_t
         * @param env pointer to environment struct
         * @return newly created adb_VersionPath_t object
         */
        adb_VersionPath_t* AXIS2_CALL
        adb_VersionPath_create(
            const axutil_env_t *env );

        /**
         * Wrapper for the "free" function, will invoke the extension mapper instead
         * @param  _VersionPath adb_VersionPath_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_VersionPath_free (
            adb_VersionPath_t* _VersionPath,
            const axutil_env_t *env);

        /**
         * Free adb_VersionPath_t object
         * @param  _VersionPath adb_VersionPath_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_VersionPath_free_obj (
            adb_VersionPath_t* _VersionPath,
            const axutil_env_t *env);



        /********************************** Getters and Setters **************************************/
        
        

        /**
         * Getter for activeResourcePath. 
         * @param  _VersionPath adb_VersionPath_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_VersionPath_get_activeResourcePath(
            adb_VersionPath_t* _VersionPath,
            const axutil_env_t *env);

        /**
         * Setter for activeResourcePath.
         * @param  _VersionPath adb_VersionPath_t object
         * @param env pointer to environment struct
         * @param arg_activeResourcePath axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_VersionPath_set_activeResourcePath(
            adb_VersionPath_t* _VersionPath,
            const axutil_env_t *env,
            const axis2_char_t*  arg_activeResourcePath);

        /**
         * Resetter for activeResourcePath
         * @param  _VersionPath adb_VersionPath_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_VersionPath_reset_activeResourcePath(
            adb_VersionPath_t* _VersionPath,
            const axutil_env_t *env);

        
        

        /**
         * Getter for completeVersionPath. 
         * @param  _VersionPath adb_VersionPath_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_VersionPath_get_completeVersionPath(
            adb_VersionPath_t* _VersionPath,
            const axutil_env_t *env);

        /**
         * Setter for completeVersionPath.
         * @param  _VersionPath adb_VersionPath_t object
         * @param env pointer to environment struct
         * @param arg_completeVersionPath axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_VersionPath_set_completeVersionPath(
            adb_VersionPath_t* _VersionPath,
            const axutil_env_t *env,
            const axis2_char_t*  arg_completeVersionPath);

        /**
         * Resetter for completeVersionPath
         * @param  _VersionPath adb_VersionPath_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_VersionPath_reset_completeVersionPath(
            adb_VersionPath_t* _VersionPath,
            const axutil_env_t *env);

        
        

        /**
         * Getter for updatedOn. 
         * @param  _VersionPath adb_VersionPath_t object
         * @param env pointer to environment struct
         * @return axutil_date_time_t*
         */
        axutil_date_time_t* AXIS2_CALL
        adb_VersionPath_get_updatedOn(
            adb_VersionPath_t* _VersionPath,
            const axutil_env_t *env);

        /**
         * Setter for updatedOn.
         * @param  _VersionPath adb_VersionPath_t object
         * @param env pointer to environment struct
         * @param arg_updatedOn axutil_date_time_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_VersionPath_set_updatedOn(
            adb_VersionPath_t* _VersionPath,
            const axutil_env_t *env,
            axutil_date_time_t*  arg_updatedOn);

        /**
         * Resetter for updatedOn
         * @param  _VersionPath adb_VersionPath_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_VersionPath_reset_updatedOn(
            adb_VersionPath_t* _VersionPath,
            const axutil_env_t *env);

        
        

        /**
         * Getter for updater. 
         * @param  _VersionPath adb_VersionPath_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_VersionPath_get_updater(
            adb_VersionPath_t* _VersionPath,
            const axutil_env_t *env);

        /**
         * Setter for updater.
         * @param  _VersionPath adb_VersionPath_t object
         * @param env pointer to environment struct
         * @param arg_updater axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_VersionPath_set_updater(
            adb_VersionPath_t* _VersionPath,
            const axutil_env_t *env,
            const axis2_char_t*  arg_updater);

        /**
         * Resetter for updater
         * @param  _VersionPath adb_VersionPath_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_VersionPath_reset_updater(
            adb_VersionPath_t* _VersionPath,
            const axutil_env_t *env);

        
        

        /**
         * Getter for versionNumber. 
         * @param  _VersionPath adb_VersionPath_t object
         * @param env pointer to environment struct
         * @return int64_t
         */
        int64_t AXIS2_CALL
        adb_VersionPath_get_versionNumber(
            adb_VersionPath_t* _VersionPath,
            const axutil_env_t *env);

        /**
         * Setter for versionNumber.
         * @param  _VersionPath adb_VersionPath_t object
         * @param env pointer to environment struct
         * @param arg_versionNumber int64_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_VersionPath_set_versionNumber(
            adb_VersionPath_t* _VersionPath,
            const axutil_env_t *env,
            const int64_t  arg_versionNumber);

        /**
         * Resetter for versionNumber
         * @param  _VersionPath adb_VersionPath_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_VersionPath_reset_versionNumber(
            adb_VersionPath_t* _VersionPath,
            const axutil_env_t *env);

        


        /******************************* Checking and Setting NIL values *********************************/
        

        /**
         * NOTE: set_nil is only available for nillable properties
         */

        

        /**
         * Check whether activeResourcePath is nill
         * @param  _VersionPath adb_VersionPath_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_VersionPath_is_activeResourcePath_nil(
                adb_VersionPath_t* _VersionPath,
                const axutil_env_t *env);


        
        /**
         * Set activeResourcePath to nill (currently the same as reset)
         * @param  _VersionPath adb_VersionPath_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_VersionPath_set_activeResourcePath_nil(
                adb_VersionPath_t* _VersionPath,
                const axutil_env_t *env);
        

        /**
         * Check whether completeVersionPath is nill
         * @param  _VersionPath adb_VersionPath_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_VersionPath_is_completeVersionPath_nil(
                adb_VersionPath_t* _VersionPath,
                const axutil_env_t *env);


        
        /**
         * Set completeVersionPath to nill (currently the same as reset)
         * @param  _VersionPath adb_VersionPath_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_VersionPath_set_completeVersionPath_nil(
                adb_VersionPath_t* _VersionPath,
                const axutil_env_t *env);
        

        /**
         * Check whether updatedOn is nill
         * @param  _VersionPath adb_VersionPath_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_VersionPath_is_updatedOn_nil(
                adb_VersionPath_t* _VersionPath,
                const axutil_env_t *env);


        
        /**
         * Set updatedOn to nill (currently the same as reset)
         * @param  _VersionPath adb_VersionPath_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_VersionPath_set_updatedOn_nil(
                adb_VersionPath_t* _VersionPath,
                const axutil_env_t *env);
        

        /**
         * Check whether updater is nill
         * @param  _VersionPath adb_VersionPath_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_VersionPath_is_updater_nil(
                adb_VersionPath_t* _VersionPath,
                const axutil_env_t *env);


        
        /**
         * Set updater to nill (currently the same as reset)
         * @param  _VersionPath adb_VersionPath_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_VersionPath_set_updater_nil(
                adb_VersionPath_t* _VersionPath,
                const axutil_env_t *env);
        

        /**
         * Check whether versionNumber is nill
         * @param  _VersionPath adb_VersionPath_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_VersionPath_is_versionNumber_nil(
                adb_VersionPath_t* _VersionPath,
                const axutil_env_t *env);


        

        /**************************** Serialize and Deserialize functions ***************************/
        /*********** These functions are for use only inside the generated code *********************/

        
        /**
         * Wrapper for the deserialization function, will invoke the extension mapper instead
         * @param  _VersionPath adb_VersionPath_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs, 
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_VersionPath_deserialize(
            adb_VersionPath_t* _VersionPath,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);

        /**
         * Deserialize an XML to adb objects
         * @param  _VersionPath adb_VersionPath_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs,
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_VersionPath_deserialize_obj(
            adb_VersionPath_t* _VersionPath,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);
                            
            

       /**
         * Declare namespace in the most parent node 
         * @param  _VersionPath adb_VersionPath_t object
         * @param env pointer to environment struct
         * @param parent_element parent element
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index pointer to an int which contain the next namespace index
         */
       void AXIS2_CALL
       adb_VersionPath_declare_parent_namespaces(
                    adb_VersionPath_t* _VersionPath,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index);

        

        /**
         * Wrapper for the serialization function, will invoke the extension mapper instead
         * @param  _VersionPath adb_VersionPath_t object
         * @param env pointer to environment struct
         * @param VersionPath_om_node node to serialize from
         * @param VersionPath_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_VersionPath_serialize(
            adb_VersionPath_t* _VersionPath,
            const axutil_env_t *env,
            axiom_node_t* VersionPath_om_node, axiom_element_t *VersionPath_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Serialize to an XML from the adb objects
         * @param  _VersionPath adb_VersionPath_t object
         * @param env pointer to environment struct
         * @param VersionPath_om_node node to serialize from
         * @param VersionPath_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_VersionPath_serialize_obj(
            adb_VersionPath_t* _VersionPath,
            const axutil_env_t *env,
            axiom_node_t* VersionPath_om_node, axiom_element_t *VersionPath_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Check whether the adb_VersionPath is a particle class (E.g. group, inner sequence)
         * @return whether this is a particle class.
         */
        axis2_bool_t AXIS2_CALL
        adb_VersionPath_is_particle();

        /******************************* Alternatives for Create and Free functions *********************************/

        

        /**
         * Constructor for creating adb_VersionPath_t
         * @param env pointer to environment struct
         * @param _activeResourcePath axis2_char_t*
         * @param _completeVersionPath axis2_char_t*
         * @param _updatedOn axutil_date_time_t*
         * @param _updater axis2_char_t*
         * @param _versionNumber int64_t
         * @return newly created adb_VersionPath_t object
         */
        adb_VersionPath_t* AXIS2_CALL
        adb_VersionPath_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _activeResourcePath,
                axis2_char_t* _completeVersionPath,
                axutil_date_time_t* _updatedOn,
                axis2_char_t* _updater,
                int64_t _versionNumber);

        


                /**
                 * Free adb_VersionPath_t object and return the property value.
                 * You can use this to free the adb object as returning the property value. If there are
                 * many properties, it will only return the first property. Other properties will get freed with the adb object.
                 * @param  _VersionPath adb_VersionPath_t object to free
                 * @param env pointer to environment struct
                 * @return the property value holded by the ADB object, if there are many properties only returns the first.
                 */
                axis2_char_t* AXIS2_CALL
                adb_VersionPath_free_popping_value(
                        adb_VersionPath_t* _VersionPath,
                        const axutil_env_t *env);
            

        /******************************* get the value by the property number  *********************************/
        /************NOTE: This method is introduced to resolve a problem in unwrapping mode *******************/

        
        

        /**
         * Getter for activeResourcePath by property number (1)
         * @param  _VersionPath adb_VersionPath_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_VersionPath_get_property1(
            adb_VersionPath_t* _VersionPath,
            const axutil_env_t *env);

    
        

        /**
         * Getter for completeVersionPath by property number (2)
         * @param  _VersionPath adb_VersionPath_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_VersionPath_get_property2(
            adb_VersionPath_t* _VersionPath,
            const axutil_env_t *env);

    
        

        /**
         * Getter for updatedOn by property number (3)
         * @param  _VersionPath adb_VersionPath_t object
         * @param env pointer to environment struct
         * @return axutil_date_time_t*
         */
        axutil_date_time_t* AXIS2_CALL
        adb_VersionPath_get_property3(
            adb_VersionPath_t* _VersionPath,
            const axutil_env_t *env);

    
        

        /**
         * Getter for updater by property number (4)
         * @param  _VersionPath adb_VersionPath_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_VersionPath_get_property4(
            adb_VersionPath_t* _VersionPath,
            const axutil_env_t *env);

    
        

        /**
         * Getter for versionNumber by property number (5)
         * @param  _VersionPath adb_VersionPath_t object
         * @param env pointer to environment struct
         * @return int64_t
         */
        int64_t AXIS2_CALL
        adb_VersionPath_get_property5(
            adb_VersionPath_t* _VersionPath,
            const axutil_env_t *env);

    
     #ifdef __cplusplus
     }
     #endif

     #endif /* ADB_VERSIONPATH_H */
    

