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

        #include "adb_PolicyComponent.h"
        #include "adb_ServerException.h"
        #include "adb_Policy.h"
        #include "adb_FaultyService.h"
        #include "adb_AbstractPolicyOperator.h"
        #include "adb_Map.h"
        #include "adb_Exception.h"
        #include "adb_FaultyServicesWrapper.h"
        #include "adb_Iterator.h"
        #include "adb_ServiceGroupMetaData.h"
        #include "adb_ServiceGroupMetaDataWrapper.h"
        #include "adb_ServiceMetaData.h"
        #include "adb_PolicyMetaData.h"
        #include "adb_All.h"
        

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
                return AXIS2_FAILURE;
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
              
              if (axutil_strcmp(type, "PolicyComponent") == 0)
              {
                  return (adb_type_t*) adb_PolicyComponent_create(env);
              }
              
              if (axutil_strcmp(type, "ServerException") == 0)
              {
                  return (adb_type_t*) adb_ServerException_create(env);
              }
              
              if (axutil_strcmp(type, "Policy") == 0)
              {
                  return (adb_type_t*) adb_Policy_create(env);
              }
              
              if (axutil_strcmp(type, "FaultyService") == 0)
              {
                  return (adb_type_t*) adb_FaultyService_create(env);
              }
              
              if (axutil_strcmp(type, "AbstractPolicyOperator") == 0)
              {
                  return (adb_type_t*) adb_AbstractPolicyOperator_create(env);
              }
              
              if (axutil_strcmp(type, "Map") == 0)
              {
                  return (adb_type_t*) adb_Map_create(env);
              }
              
              if (axutil_strcmp(type, "Exception") == 0)
              {
                  return (adb_type_t*) adb_Exception_create(env);
              }
              
              if (axutil_strcmp(type, "FaultyServicesWrapper") == 0)
              {
                  return (adb_type_t*) adb_FaultyServicesWrapper_create(env);
              }
              
              if (axutil_strcmp(type, "Iterator") == 0)
              {
                  return (adb_type_t*) adb_Iterator_create(env);
              }
              
              if (axutil_strcmp(type, "ServiceGroupMetaData") == 0)
              {
                  return (adb_type_t*) adb_ServiceGroupMetaData_create(env);
              }
              
              if (axutil_strcmp(type, "ServiceGroupMetaDataWrapper") == 0)
              {
                  return (adb_type_t*) adb_ServiceGroupMetaDataWrapper_create(env);
              }
              
              if (axutil_strcmp(type, "ServiceMetaData") == 0)
              {
                  return (adb_type_t*) adb_ServiceMetaData_create(env);
              }
              
              if (axutil_strcmp(type, "PolicyMetaData") == 0)
              {
                  return (adb_type_t*) adb_PolicyMetaData_create(env);
              }
              
              if (axutil_strcmp(type, "All") == 0)
              {
                  return (adb_type_t*) adb_All_create(env);
              }
              
            }

            
            if (axutil_strcmp(default_type, "adb_PolicyComponent") == 0)
            {
                return (adb_type_t*) adb_PolicyComponent_create(env);
            }
            
            if (axutil_strcmp(default_type, "adb_ServerException") == 0)
            {
                return (adb_type_t*) adb_ServerException_create(env);
            }
            
            if (axutil_strcmp(default_type, "adb_Policy") == 0)
            {
                return (adb_type_t*) adb_Policy_create(env);
            }
            
            if (axutil_strcmp(default_type, "adb_FaultyService") == 0)
            {
                return (adb_type_t*) adb_FaultyService_create(env);
            }
            
            if (axutil_strcmp(default_type, "adb_AbstractPolicyOperator") == 0)
            {
                return (adb_type_t*) adb_AbstractPolicyOperator_create(env);
            }
            
            if (axutil_strcmp(default_type, "adb_Map") == 0)
            {
                return (adb_type_t*) adb_Map_create(env);
            }
            
            if (axutil_strcmp(default_type, "adb_Exception") == 0)
            {
                return (adb_type_t*) adb_Exception_create(env);
            }
            
            if (axutil_strcmp(default_type, "adb_FaultyServicesWrapper") == 0)
            {
                return (adb_type_t*) adb_FaultyServicesWrapper_create(env);
            }
            
            if (axutil_strcmp(default_type, "adb_Iterator") == 0)
            {
                return (adb_type_t*) adb_Iterator_create(env);
            }
            
            if (axutil_strcmp(default_type, "adb_ServiceGroupMetaData") == 0)
            {
                return (adb_type_t*) adb_ServiceGroupMetaData_create(env);
            }
            
            if (axutil_strcmp(default_type, "adb_ServiceGroupMetaDataWrapper") == 0)
            {
                return (adb_type_t*) adb_ServiceGroupMetaDataWrapper_create(env);
            }
            
            if (axutil_strcmp(default_type, "adb_ServiceMetaData") == 0)
            {
                return (adb_type_t*) adb_ServiceMetaData_create(env);
            }
            
            if (axutil_strcmp(default_type, "adb_PolicyMetaData") == 0)
            {
                return (adb_type_t*) adb_PolicyMetaData_create(env);
            }
            
            if (axutil_strcmp(default_type, "adb_All") == 0)
            {
                return (adb_type_t*) adb_All_create(env);
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
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_PolicyComponent") == 0)
                {
                    return adb_PolicyComponent_free_obj(
                    (adb_PolicyComponent_t*) _object, env);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_ServerException") == 0)
                {
                    return adb_ServerException_free_obj(
                    (adb_ServerException_t*) _object, env);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_Policy") == 0)
                {
                    return adb_Policy_free_obj(
                    (adb_Policy_t*) _object, env);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_FaultyService") == 0)
                {
                    return adb_FaultyService_free_obj(
                    (adb_FaultyService_t*) _object, env);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_AbstractPolicyOperator") == 0)
                {
                    return adb_AbstractPolicyOperator_free_obj(
                    (adb_AbstractPolicyOperator_t*) _object, env);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_Map") == 0)
                {
                    return adb_Map_free_obj(
                    (adb_Map_t*) _object, env);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_Exception") == 0)
                {
                    return adb_Exception_free_obj(
                    (adb_Exception_t*) _object, env);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_FaultyServicesWrapper") == 0)
                {
                    return adb_FaultyServicesWrapper_free_obj(
                    (adb_FaultyServicesWrapper_t*) _object, env);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_Iterator") == 0)
                {
                    return adb_Iterator_free_obj(
                    (adb_Iterator_t*) _object, env);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_ServiceGroupMetaData") == 0)
                {
                    return adb_ServiceGroupMetaData_free_obj(
                    (adb_ServiceGroupMetaData_t*) _object, env);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_ServiceGroupMetaDataWrapper") == 0)
                {
                    return adb_ServiceGroupMetaDataWrapper_free_obj(
                    (adb_ServiceGroupMetaDataWrapper_t*) _object, env);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_ServiceMetaData") == 0)
                {
                    return adb_ServiceMetaData_free_obj(
                    (adb_ServiceMetaData_t*) _object, env);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_PolicyMetaData") == 0)
                {
                    return adb_PolicyMetaData_free_obj(
                    (adb_PolicyMetaData_t*) _object, env);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_All") == 0)
                {
                    return adb_All_free_obj(
                    (adb_All_t*) _object, env);
                }
            
            }

            
            if (axutil_strcmp(default_type, "adb_PolicyComponent") == 0)
            {
                return adb_PolicyComponent_free_obj(
                (adb_PolicyComponent_t*) _object, env);
            }
            
            if (axutil_strcmp(default_type, "adb_ServerException") == 0)
            {
                return adb_ServerException_free_obj(
                (adb_ServerException_t*) _object, env);
            }
            
            if (axutil_strcmp(default_type, "adb_Policy") == 0)
            {
                return adb_Policy_free_obj(
                (adb_Policy_t*) _object, env);
            }
            
            if (axutil_strcmp(default_type, "adb_FaultyService") == 0)
            {
                return adb_FaultyService_free_obj(
                (adb_FaultyService_t*) _object, env);
            }
            
            if (axutil_strcmp(default_type, "adb_AbstractPolicyOperator") == 0)
            {
                return adb_AbstractPolicyOperator_free_obj(
                (adb_AbstractPolicyOperator_t*) _object, env);
            }
            
            if (axutil_strcmp(default_type, "adb_Map") == 0)
            {
                return adb_Map_free_obj(
                (adb_Map_t*) _object, env);
            }
            
            if (axutil_strcmp(default_type, "adb_Exception") == 0)
            {
                return adb_Exception_free_obj(
                (adb_Exception_t*) _object, env);
            }
            
            if (axutil_strcmp(default_type, "adb_FaultyServicesWrapper") == 0)
            {
                return adb_FaultyServicesWrapper_free_obj(
                (adb_FaultyServicesWrapper_t*) _object, env);
            }
            
            if (axutil_strcmp(default_type, "adb_Iterator") == 0)
            {
                return adb_Iterator_free_obj(
                (adb_Iterator_t*) _object, env);
            }
            
            if (axutil_strcmp(default_type, "adb_ServiceGroupMetaData") == 0)
            {
                return adb_ServiceGroupMetaData_free_obj(
                (adb_ServiceGroupMetaData_t*) _object, env);
            }
            
            if (axutil_strcmp(default_type, "adb_ServiceGroupMetaDataWrapper") == 0)
            {
                return adb_ServiceGroupMetaDataWrapper_free_obj(
                (adb_ServiceGroupMetaDataWrapper_t*) _object, env);
            }
            
            if (axutil_strcmp(default_type, "adb_ServiceMetaData") == 0)
            {
                return adb_ServiceMetaData_free_obj(
                (adb_ServiceMetaData_t*) _object, env);
            }
            
            if (axutil_strcmp(default_type, "adb_PolicyMetaData") == 0)
            {
                return adb_PolicyMetaData_free_obj(
                (adb_PolicyMetaData_t*) _object, env);
            }
            
            if (axutil_strcmp(default_type, "adb_All") == 0)
            {
                return adb_All_free_obj(
                (adb_All_t*) _object, env);
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
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_PolicyComponent") == 0)
                {
                    return adb_PolicyComponent_deserialize_obj(
                    (adb_PolicyComponent_t*) _object, env, dp_parent, dp_is_early_node_valid, dont_care_minoccurs);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_ServerException") == 0)
                {
                    return adb_ServerException_deserialize_obj(
                    (adb_ServerException_t*) _object, env, dp_parent, dp_is_early_node_valid, dont_care_minoccurs);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_Policy") == 0)
                {
                    return adb_Policy_deserialize_obj(
                    (adb_Policy_t*) _object, env, dp_parent, dp_is_early_node_valid, dont_care_minoccurs);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_FaultyService") == 0)
                {
                    return adb_FaultyService_deserialize_obj(
                    (adb_FaultyService_t*) _object, env, dp_parent, dp_is_early_node_valid, dont_care_minoccurs);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_AbstractPolicyOperator") == 0)
                {
                    return adb_AbstractPolicyOperator_deserialize_obj(
                    (adb_AbstractPolicyOperator_t*) _object, env, dp_parent, dp_is_early_node_valid, dont_care_minoccurs);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_Map") == 0)
                {
                    return adb_Map_deserialize_obj(
                    (adb_Map_t*) _object, env, dp_parent, dp_is_early_node_valid, dont_care_minoccurs);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_Exception") == 0)
                {
                    return adb_Exception_deserialize_obj(
                    (adb_Exception_t*) _object, env, dp_parent, dp_is_early_node_valid, dont_care_minoccurs);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_FaultyServicesWrapper") == 0)
                {
                    return adb_FaultyServicesWrapper_deserialize_obj(
                    (adb_FaultyServicesWrapper_t*) _object, env, dp_parent, dp_is_early_node_valid, dont_care_minoccurs);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_Iterator") == 0)
                {
                    return adb_Iterator_deserialize_obj(
                    (adb_Iterator_t*) _object, env, dp_parent, dp_is_early_node_valid, dont_care_minoccurs);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_ServiceGroupMetaData") == 0)
                {
                    return adb_ServiceGroupMetaData_deserialize_obj(
                    (adb_ServiceGroupMetaData_t*) _object, env, dp_parent, dp_is_early_node_valid, dont_care_minoccurs);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_ServiceGroupMetaDataWrapper") == 0)
                {
                    return adb_ServiceGroupMetaDataWrapper_deserialize_obj(
                    (adb_ServiceGroupMetaDataWrapper_t*) _object, env, dp_parent, dp_is_early_node_valid, dont_care_minoccurs);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_ServiceMetaData") == 0)
                {
                    return adb_ServiceMetaData_deserialize_obj(
                    (adb_ServiceMetaData_t*) _object, env, dp_parent, dp_is_early_node_valid, dont_care_minoccurs);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_PolicyMetaData") == 0)
                {
                    return adb_PolicyMetaData_deserialize_obj(
                    (adb_PolicyMetaData_t*) _object, env, dp_parent, dp_is_early_node_valid, dont_care_minoccurs);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_All") == 0)
                {
                    return adb_All_deserialize_obj(
                    (adb_All_t*) _object, env, dp_parent, dp_is_early_node_valid, dont_care_minoccurs);
                }
            
            }

            
            if (axutil_strcmp(default_type, "adb_PolicyComponent") == 0)
            {
                return adb_PolicyComponent_deserialize_obj(
                (adb_PolicyComponent_t*) _object, env, dp_parent, dp_is_early_node_valid, dont_care_minoccurs);
            }
            
            if (axutil_strcmp(default_type, "adb_ServerException") == 0)
            {
                return adb_ServerException_deserialize_obj(
                (adb_ServerException_t*) _object, env, dp_parent, dp_is_early_node_valid, dont_care_minoccurs);
            }
            
            if (axutil_strcmp(default_type, "adb_Policy") == 0)
            {
                return adb_Policy_deserialize_obj(
                (adb_Policy_t*) _object, env, dp_parent, dp_is_early_node_valid, dont_care_minoccurs);
            }
            
            if (axutil_strcmp(default_type, "adb_FaultyService") == 0)
            {
                return adb_FaultyService_deserialize_obj(
                (adb_FaultyService_t*) _object, env, dp_parent, dp_is_early_node_valid, dont_care_minoccurs);
            }
            
            if (axutil_strcmp(default_type, "adb_AbstractPolicyOperator") == 0)
            {
                return adb_AbstractPolicyOperator_deserialize_obj(
                (adb_AbstractPolicyOperator_t*) _object, env, dp_parent, dp_is_early_node_valid, dont_care_minoccurs);
            }
            
            if (axutil_strcmp(default_type, "adb_Map") == 0)
            {
                return adb_Map_deserialize_obj(
                (adb_Map_t*) _object, env, dp_parent, dp_is_early_node_valid, dont_care_minoccurs);
            }
            
            if (axutil_strcmp(default_type, "adb_Exception") == 0)
            {
                return adb_Exception_deserialize_obj(
                (adb_Exception_t*) _object, env, dp_parent, dp_is_early_node_valid, dont_care_minoccurs);
            }
            
            if (axutil_strcmp(default_type, "adb_FaultyServicesWrapper") == 0)
            {
                return adb_FaultyServicesWrapper_deserialize_obj(
                (adb_FaultyServicesWrapper_t*) _object, env, dp_parent, dp_is_early_node_valid, dont_care_minoccurs);
            }
            
            if (axutil_strcmp(default_type, "adb_Iterator") == 0)
            {
                return adb_Iterator_deserialize_obj(
                (adb_Iterator_t*) _object, env, dp_parent, dp_is_early_node_valid, dont_care_minoccurs);
            }
            
            if (axutil_strcmp(default_type, "adb_ServiceGroupMetaData") == 0)
            {
                return adb_ServiceGroupMetaData_deserialize_obj(
                (adb_ServiceGroupMetaData_t*) _object, env, dp_parent, dp_is_early_node_valid, dont_care_minoccurs);
            }
            
            if (axutil_strcmp(default_type, "adb_ServiceGroupMetaDataWrapper") == 0)
            {
                return adb_ServiceGroupMetaDataWrapper_deserialize_obj(
                (adb_ServiceGroupMetaDataWrapper_t*) _object, env, dp_parent, dp_is_early_node_valid, dont_care_minoccurs);
            }
            
            if (axutil_strcmp(default_type, "adb_ServiceMetaData") == 0)
            {
                return adb_ServiceMetaData_deserialize_obj(
                (adb_ServiceMetaData_t*) _object, env, dp_parent, dp_is_early_node_valid, dont_care_minoccurs);
            }
            
            if (axutil_strcmp(default_type, "adb_PolicyMetaData") == 0)
            {
                return adb_PolicyMetaData_deserialize_obj(
                (adb_PolicyMetaData_t*) _object, env, dp_parent, dp_is_early_node_valid, dont_care_minoccurs);
            }
            
            if (axutil_strcmp(default_type, "adb_All") == 0)
            {
                return adb_All_deserialize_obj(
                (adb_All_t*) _object, env, dp_parent, dp_is_early_node_valid, dont_care_minoccurs);
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
                
                if (axutil_strcmp(adb_type_get_type(_object), "adb_PolicyComponent") == 0)
                {
                    return adb_PolicyComponent_serialize_obj(
                    (adb_PolicyComponent_t*) _object, env, om_node, om_element, tag_closed, namespaces, next_ns_index);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_ServerException") == 0)
                {
                    return adb_ServerException_serialize_obj(
                    (adb_ServerException_t*) _object, env, om_node, om_element, tag_closed, namespaces, next_ns_index);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_Policy") == 0)
                {
                    return adb_Policy_serialize_obj(
                    (adb_Policy_t*) _object, env, om_node, om_element, tag_closed, namespaces, next_ns_index);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_FaultyService") == 0)
                {
                    return adb_FaultyService_serialize_obj(
                    (adb_FaultyService_t*) _object, env, om_node, om_element, tag_closed, namespaces, next_ns_index);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_AbstractPolicyOperator") == 0)
                {
                    return adb_AbstractPolicyOperator_serialize_obj(
                    (adb_AbstractPolicyOperator_t*) _object, env, om_node, om_element, tag_closed, namespaces, next_ns_index);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_Map") == 0)
                {
                    return adb_Map_serialize_obj(
                    (adb_Map_t*) _object, env, om_node, om_element, tag_closed, namespaces, next_ns_index);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_Exception") == 0)
                {
                    return adb_Exception_serialize_obj(
                    (adb_Exception_t*) _object, env, om_node, om_element, tag_closed, namespaces, next_ns_index);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_FaultyServicesWrapper") == 0)
                {
                    return adb_FaultyServicesWrapper_serialize_obj(
                    (adb_FaultyServicesWrapper_t*) _object, env, om_node, om_element, tag_closed, namespaces, next_ns_index);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_Iterator") == 0)
                {
                    return adb_Iterator_serialize_obj(
                    (adb_Iterator_t*) _object, env, om_node, om_element, tag_closed, namespaces, next_ns_index);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_ServiceGroupMetaData") == 0)
                {
                    return adb_ServiceGroupMetaData_serialize_obj(
                    (adb_ServiceGroupMetaData_t*) _object, env, om_node, om_element, tag_closed, namespaces, next_ns_index);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_ServiceGroupMetaDataWrapper") == 0)
                {
                    return adb_ServiceGroupMetaDataWrapper_serialize_obj(
                    (adb_ServiceGroupMetaDataWrapper_t*) _object, env, om_node, om_element, tag_closed, namespaces, next_ns_index);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_ServiceMetaData") == 0)
                {
                    return adb_ServiceMetaData_serialize_obj(
                    (adb_ServiceMetaData_t*) _object, env, om_node, om_element, tag_closed, namespaces, next_ns_index);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_PolicyMetaData") == 0)
                {
                    return adb_PolicyMetaData_serialize_obj(
                    (adb_PolicyMetaData_t*) _object, env, om_node, om_element, tag_closed, namespaces, next_ns_index);
                }
            
                if (axutil_strcmp(adb_type_get_type(_object), "adb_All") == 0)
                {
                    return adb_All_serialize_obj(
                    (adb_All_t*) _object, env, om_node, om_element, tag_closed, namespaces, next_ns_index);
                }
            
            }

            
            if (axutil_strcmp(default_type, "adb_PolicyComponent") == 0)
            {
                return adb_PolicyComponent_serialize_obj(
                (adb_PolicyComponent_t*) _object, env, om_node, om_element, tag_closed, namespaces, next_ns_index);
            }
            
            if (axutil_strcmp(default_type, "adb_ServerException") == 0)
            {
                return adb_ServerException_serialize_obj(
                (adb_ServerException_t*) _object, env, om_node, om_element, tag_closed, namespaces, next_ns_index);
            }
            
            if (axutil_strcmp(default_type, "adb_Policy") == 0)
            {
                return adb_Policy_serialize_obj(
                (adb_Policy_t*) _object, env, om_node, om_element, tag_closed, namespaces, next_ns_index);
            }
            
            if (axutil_strcmp(default_type, "adb_FaultyService") == 0)
            {
                return adb_FaultyService_serialize_obj(
                (adb_FaultyService_t*) _object, env, om_node, om_element, tag_closed, namespaces, next_ns_index);
            }
            
            if (axutil_strcmp(default_type, "adb_AbstractPolicyOperator") == 0)
            {
                return adb_AbstractPolicyOperator_serialize_obj(
                (adb_AbstractPolicyOperator_t*) _object, env, om_node, om_element, tag_closed, namespaces, next_ns_index);
            }
            
            if (axutil_strcmp(default_type, "adb_Map") == 0)
            {
                return adb_Map_serialize_obj(
                (adb_Map_t*) _object, env, om_node, om_element, tag_closed, namespaces, next_ns_index);
            }
            
            if (axutil_strcmp(default_type, "adb_Exception") == 0)
            {
                return adb_Exception_serialize_obj(
                (adb_Exception_t*) _object, env, om_node, om_element, tag_closed, namespaces, next_ns_index);
            }
            
            if (axutil_strcmp(default_type, "adb_FaultyServicesWrapper") == 0)
            {
                return adb_FaultyServicesWrapper_serialize_obj(
                (adb_FaultyServicesWrapper_t*) _object, env, om_node, om_element, tag_closed, namespaces, next_ns_index);
            }
            
            if (axutil_strcmp(default_type, "adb_Iterator") == 0)
            {
                return adb_Iterator_serialize_obj(
                (adb_Iterator_t*) _object, env, om_node, om_element, tag_closed, namespaces, next_ns_index);
            }
            
            if (axutil_strcmp(default_type, "adb_ServiceGroupMetaData") == 0)
            {
                return adb_ServiceGroupMetaData_serialize_obj(
                (adb_ServiceGroupMetaData_t*) _object, env, om_node, om_element, tag_closed, namespaces, next_ns_index);
            }
            
            if (axutil_strcmp(default_type, "adb_ServiceGroupMetaDataWrapper") == 0)
            {
                return adb_ServiceGroupMetaDataWrapper_serialize_obj(
                (adb_ServiceGroupMetaDataWrapper_t*) _object, env, om_node, om_element, tag_closed, namespaces, next_ns_index);
            }
            
            if (axutil_strcmp(default_type, "adb_ServiceMetaData") == 0)
            {
                return adb_ServiceMetaData_serialize_obj(
                (adb_ServiceMetaData_t*) _object, env, om_node, om_element, tag_closed, namespaces, next_ns_index);
            }
            
            if (axutil_strcmp(default_type, "adb_PolicyMetaData") == 0)
            {
                return adb_PolicyMetaData_serialize_obj(
                (adb_PolicyMetaData_t*) _object, env, om_node, om_element, tag_closed, namespaces, next_ns_index);
            }
            
            if (axutil_strcmp(default_type, "adb_All") == 0)
            {
                return adb_All_serialize_obj(
                (adb_All_t*) _object, env, om_node, om_element, tag_closed, namespaces, next_ns_index);
            }
            

            return AXIS2_FAILURE;
        }
    

