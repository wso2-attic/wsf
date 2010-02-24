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


        /**
         * axis2_extension_mapper.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/Java version: #axisVersion# #today#
         */

        #include "axis2_extension_mapper.h"

        #include "adb_OperationMetaDataWrapper.h"
        #include "adb_OperationMetaData.h"
        

        struct adb_type
        {
            axis2_char_t *property_Type;
        };

        /**
         * Auxiliary function to determine an ADB object type from its Axiom node.
         * @param env pointer to environment struct
         * @param node double pointer to the parent node to deserialize
         * @return type name on success, else NULL
         */
        axis2_char_t *AXIS2_CALL
        axis2_extension_mapper_type_from_node(
            const axutil_env_t *env,
            axiom_node_t** node)
        {
            axiom_node_t *parent = *node;
            axutil_qname_t *element_qname = NULL;
            axiom_element_t *element = NULL;

            axutil_hash_index_t *hi;
            void *val;
            axiom_attribute_t *type_attr;
            axutil_hash_t *ht;
            axis2_char_t *temp;
            axis2_char_t *type;

            while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
            {
                parent = axiom_node_get_next_sibling(parent, env);
            }

            if (NULL == parent)
            {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
                            "Failed in building adb object : "
                            "NULL elemenet can not be passed to deserialize");
				return NULL;
            }

            element = (axiom_element_t *)axiom_node_get_data_element(parent, env);

            ht = axiom_element_get_all_attributes(element, env);

            if (ht == NULL)
                return NULL;

            for (hi = axutil_hash_first(ht, env); hi; hi = axutil_hash_next(env, hi)) {
                axis2_char_t *localpart;
                axutil_hash_this(hi, NULL, NULL, &val);
                type_attr = (axiom_attribute_t *)val;
                localpart = axutil_qname_get_localpart(axiom_attribute_get_qname(type_attr, env), env);
                if (axutil_strcmp(localpart, "type") == 0) break;
            }

            type = axiom_attribute_get_value(type_attr, env);
            if (type != NULL && (temp = axutil_strchr(type, ':')) != NULL)
            {
                if (axutil_strchr(temp, ':') != NULL)
                    type = temp + 1; /* Pointer arithmetic */
            }

            return type;
        }

        axis2_char_t* AXIS2_CALL
        adb_type_get_type(const adb_type_t *object)
        {
            if (object != NULL)
              return object->property_Type;

            return NULL;
        }

        adb_type_t* AXIS2_CALL
        axis2_extension_mapper_create_from_node(
            const axutil_env_t *env,
            axiom_node_t** node,
            axis2_char_t *default_type)
        {
            axis2_char_t *type = axis2_extension_mapper_type_from_node(env, node);

            if (type != NULL)
            {
              
              if (axutil_strcmp(type, "OperationMetaDataWrapper") == 0)
              {
                  return (adb_type_t*) adb_OperationMetaDataWrapper_create(env);
              }
              
              if (axutil_strcmp(type, "OperationMetaData") == 0)
              {
                  return (adb_type_t*) adb_OperationMetaData_create(env);
              }
              
            }

            
            if (axutil_strcmp(default_type, "adb_OperationMetaDataWrapper") == 0)
            {
                return (adb_type_t*) adb_OperationMetaDataWrapper_create(env);
            }
            
            if (axutil_strcmp(default_type, "adb_OperationMetaData") == 0)
            {
                return (adb_type_t*) adb_OperationMetaData_create(env);
            }
            

            return NULL;
        }

        axis2_status_t AXIS2_CALL
        axis2_extension_mapper_free(
            adb_type_t* _object,
            const axutil_env_t *env,
            axis2_char_t *default_type)
        {
            if (_object != NULL && adb_type_get_type(_object) != NULL)
            {
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_OperationMetaDataWrapper") == 0)
                {
                    return adb_OperationMetaDataWrapper_free_obj(
                    (adb_OperationMetaDataWrapper_t*) _object, env);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_OperationMetaData") == 0)
                {
                    return adb_OperationMetaData_free_obj(
                    (adb_OperationMetaData_t*) _object, env);
                }
            }
            if (axutil_strcmp(default_type, "adb_OperationMetaDataWrapper") == 0)
            {
                return adb_OperationMetaDataWrapper_free_obj(
                (adb_OperationMetaDataWrapper_t*) _object, env);
            }
            
            if (axutil_strcmp(default_type, "adb_OperationMetaData") == 0)
            {
                return adb_OperationMetaData_free_obj(
                (adb_OperationMetaData_t*) _object, env);
            }
            

            return AXIS2_FAILURE;
        }

        axis2_status_t AXIS2_CALL
        axis2_extension_mapper_deserialize(
            adb_type_t* _object,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs,
            axis2_char_t *default_type)
        {
            if (_object != NULL && adb_type_get_type(_object) != NULL)
            {
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_OperationMetaDataWrapper") == 0)
                {
                    return adb_OperationMetaDataWrapper_deserialize_obj(
                    (adb_OperationMetaDataWrapper_t*) _object, env, dp_parent, dp_is_early_node_valid, dont_care_minoccurs);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_OperationMetaData") == 0)
                {
                    return adb_OperationMetaData_deserialize_obj(
                    (adb_OperationMetaData_t*) _object, env, dp_parent, dp_is_early_node_valid, dont_care_minoccurs);
                }
            
            }

            
            if (axutil_strcmp(default_type, "adb_OperationMetaDataWrapper") == 0)
            {
                return adb_OperationMetaDataWrapper_deserialize_obj(
                (adb_OperationMetaDataWrapper_t*) _object, env, dp_parent, dp_is_early_node_valid, dont_care_minoccurs);
            }
            
            if (axutil_strcmp(default_type, "adb_OperationMetaData") == 0)
            {
                return adb_OperationMetaData_deserialize_obj(
                (adb_OperationMetaData_t*) _object, env, dp_parent, dp_is_early_node_valid, dont_care_minoccurs);
            }
            

            return AXIS2_FAILURE;
        }

        axiom_node_t* AXIS2_CALL
        axis2_extension_mapper_serialize(
            adb_type_t* _object,
            const axutil_env_t *env,
            axiom_node_t* om_node,
            axiom_element_t *om_element,
            int tag_closed,
            axutil_hash_t *namespaces,
            int *next_ns_index,
            axis2_char_t *default_type)
        {
            if (_object != NULL && adb_type_get_type(_object) != NULL)
            {
                
                if (axutil_strcmp(adb_type_get_type(_object), "adb_OperationMetaDataWrapper") == 0)
                {
                    return adb_OperationMetaDataWrapper_serialize_obj(
                    (adb_OperationMetaDataWrapper_t*) _object, env, om_node, om_element, tag_closed, namespaces, next_ns_index);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_OperationMetaData") == 0)
                {
                    return adb_OperationMetaData_serialize_obj(
                    (adb_OperationMetaData_t*) _object, env, om_node, om_element, tag_closed, namespaces, next_ns_index);
                }
            
            }

            
            if (axutil_strcmp(default_type, "adb_OperationMetaDataWrapper") == 0)
            {
                return adb_OperationMetaDataWrapper_serialize_obj(
                (adb_OperationMetaDataWrapper_t*) _object, env, om_node, om_element, tag_closed, namespaces, next_ns_index);
            }
            
            if (axutil_strcmp(default_type, "adb_OperationMetaData") == 0)
            {
                return adb_OperationMetaData_serialize_obj(
                (adb_OperationMetaData_t*) _object, env, om_node, om_element, tag_closed, namespaces, next_ns_index);
            }
            

			return NULL;
        }
    

