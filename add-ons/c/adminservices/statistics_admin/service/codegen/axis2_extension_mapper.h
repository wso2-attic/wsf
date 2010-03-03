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

        #ifndef AXIS2_EXTENSION_MAPPER_H
        #define AXIS2_EXTENSION_MAPPER_H

        /**
         * axis2_extension_mapper.h
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/Java version: #axisVersion# #today#
         */

        #include <stdio.h>
        #include <axiom.h>
        #include <axis2_util.h>
        #include <axiom_soap.h>
        #include <axis2_client.h>

        #ifdef __cplusplus
        extern "C"
        {
        #endif

        typedef struct adb_type adb_type_t;

        /**
         * Returns the type for an ADB object.
         * @param object ADB object
         * @return string with the object type
         */
        axis2_char_t* AXIS2_CALL
        adb_type_get_type(const adb_type_t *object);

        /**
         * Will invoke the creation function for the appropriate type, given an Axiom node.
         * @param env pointer to environment struct
         * @param node double pointer to the parent node to deserialize
         * @param default_type string with the default type, in case the node has none
         * @return ADB object on success, else NULL
         */
        adb_type_t* AXIS2_CALL
        axis2_extension_mapper_create_from_node(
            const axutil_env_t *env,
            axiom_node_t** node,
            axis2_char_t *default_type);

        /**
         * Will invoke the "free" function for the appropriate type.
         * @param  _object ADB object
         * @param env pointer to environment struct
         * @param default_type string with the default type, in case the object has none
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        axis2_extension_mapper_free(
            adb_type_t* _object,
            const axutil_env_t *env,
            axis2_char_t *default_type);

        /**
         * Will invoke the deserialization function for the appropriate type.
         * @param  _object ADB object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs,
         *              (Parent will order this in a case of choice)
         * @param default_type string with the default type, in case the object has none
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        axis2_extension_mapper_deserialize(
            adb_type_t* _object,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs,
            axis2_char_t *default_type);

        /**
         * Will invoke the serialization function for the appropriate type.
         * @param  _object ADB object
         * @param env pointer to environment struct
         * @param om_node node to serialize from
         * @param om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @param default_type string with the default type, in case the object has none
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        axis2_extension_mapper_serialize(
            adb_type_t* _object,
            const axutil_env_t *env,
            axiom_node_t* om_node,
            axiom_element_t *om_element,
            int tag_closed,
            axutil_hash_t *namespaces,
            int *next_ns_index,
            axis2_char_t *default_type);


        #ifdef __cplusplus
        }
        #endif

        #endif /* AXIS2_EXTENSION_MAPPER_H */
    

