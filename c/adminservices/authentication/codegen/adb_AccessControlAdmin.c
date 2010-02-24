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
         * adb_AccessControlAdmin.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_AccessControlAdmin.h"
        
                /*
                 * This type was generated from the piece of schema that had
                 * name = AccessControlAdmin
                 * Namespace URI = http://core.user.carbon.wso2.org/xsd
                 * Namespace Prefix = ns2
                 */
           


        struct adb_AccessControlAdmin
        {
            axis2_char_t *property_Type;

            
        };


       /************************* Private Function prototypes ********************************/
        


       /************************* Function Implmentations ********************************/
        adb_AccessControlAdmin_t* AXIS2_CALL
        adb_AccessControlAdmin_create(
            const axutil_env_t *env)
        {
            adb_AccessControlAdmin_t *_AccessControlAdmin = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _AccessControlAdmin = (adb_AccessControlAdmin_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_AccessControlAdmin_t));

            if(NULL == _AccessControlAdmin)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_AccessControlAdmin, 0, sizeof(adb_AccessControlAdmin_t));

            _AccessControlAdmin->property_Type = axutil_strdup(env, "adb_AccessControlAdmin");
            

            return _AccessControlAdmin;
        }

        adb_AccessControlAdmin_t* AXIS2_CALL
        adb_AccessControlAdmin_create_with_values(
            const axutil_env_t *env)
        {
            adb_AccessControlAdmin_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_AccessControlAdmin_create(env);

            

            return adb_obj;
        }
      
        
                void* AXIS2_CALL
                adb_AccessControlAdmin_free_popping_value(
                        adb_AccessControlAdmin_t* _AccessControlAdmin,
                        const axutil_env_t *env)
                {
                    adb_AccessControlAdmin_free(_AccessControlAdmin, env);
                    return NULL;
                }
            

        axis2_status_t AXIS2_CALL
        adb_AccessControlAdmin_free(
                adb_AccessControlAdmin_t* _AccessControlAdmin,
                const axutil_env_t *env)
        {
            
            
            return axis2_extension_mapper_free(
                (adb_type_t*) _AccessControlAdmin,
                env,
                "adb_AccessControlAdmin");
            
        }

        axis2_status_t AXIS2_CALL
        adb_AccessControlAdmin_free_obj(
                adb_AccessControlAdmin_t* _AccessControlAdmin,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _AccessControlAdmin, AXIS2_FAILURE);

            if (_AccessControlAdmin->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _AccessControlAdmin->property_Type);
            }

            

            if(_AccessControlAdmin)
            {
                AXIS2_FREE(env->allocator, _AccessControlAdmin);
                _AccessControlAdmin = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_AccessControlAdmin_deserialize(
                adb_AccessControlAdmin_t* _AccessControlAdmin,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return axis2_extension_mapper_deserialize(
                (adb_type_t*) _AccessControlAdmin,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs,
                "adb_AccessControlAdmin");
            
        }

        axis2_status_t AXIS2_CALL
        adb_AccessControlAdmin_deserialize_obj(
                adb_AccessControlAdmin_t* _AccessControlAdmin,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
          axiom_node_t *parent = *dp_parent;
          
          axis2_status_t status = AXIS2_SUCCESS;
          
            axutil_qname_t *element_qname = NULL; 
            
            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _AccessControlAdmin, AXIS2_FAILURE);

            
          return status;
       }

          axis2_bool_t AXIS2_CALL
          adb_AccessControlAdmin_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_AccessControlAdmin_declare_parent_namespaces(
                    adb_AccessControlAdmin_t* _AccessControlAdmin,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_AccessControlAdmin_serialize(
                adb_AccessControlAdmin_t* _AccessControlAdmin,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
            if (_AccessControlAdmin == NULL)
            {
                return adb_AccessControlAdmin_serialize_obj(
                    _AccessControlAdmin, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            }
            else
            {
                return axis2_extension_mapper_serialize(
                    (adb_type_t*) _AccessControlAdmin, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index, "adb_AccessControlAdmin");
            }
            
        }

        axiom_node_t* AXIS2_CALL
        adb_AccessControlAdmin_serialize_obj(
                adb_AccessControlAdmin_t* _AccessControlAdmin,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
             axis2_char_t *string_to_stream;
            
         
         axiom_node_t* current_node = NULL;
         int tag_closed = 0;
         
         axis2_char_t* xsi_prefix = NULL;
         
         axis2_char_t* type_attrib = NULL;
         axiom_namespace_t* xsi_ns = NULL;
         axiom_attribute_t* xsi_type_attri = NULL;
         
                axiom_namespace_t *ns1 = NULL;

                axis2_char_t *qname_uri = NULL;
                axis2_char_t *qname_prefix = NULL;
                axis2_char_t *p_prefix = NULL;
                axis2_bool_t ns_already_defined;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _AccessControlAdmin, NULL);
            
            
                    current_node = parent;
                    data_source = (axiom_data_source_t *)axiom_node_get_data_element(current_node, env);
                    if (!data_source)
                        return NULL;
                    stream = axiom_data_source_get_stream(data_source, env); /* assume parent is of type data source */
                    if (!stream)
                        return NULL;
                  
            if(!parent_tag_closed)
            {
            
              
 
              if(!(xsi_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://www.w3.org/2001/XMLSchema-instance", AXIS2_HASH_KEY_STRING)))
              {
                  /* it is better to stick with the standard prefix */
                  xsi_prefix = (axis2_char_t*)axutil_strdup(env, "xsi");
                  
                  axutil_hash_set(namespaces, "http://www.w3.org/2001/XMLSchema-instance", AXIS2_HASH_KEY_STRING, xsi_prefix);

                  if(parent_element)
                  {
                        axiom_namespace_t *element_ns = NULL;
                        element_ns = axiom_namespace_create(env, "http://www.w3.org/2001/XMLSchema-instance",
                                                            xsi_prefix);
                        axiom_element_declare_namespace_assume_param_ownership(parent_element, env, element_ns);
                  }
              }
              type_attrib = axutil_strcat(env, " ", xsi_prefix, ":type=\"AccessControlAdmin\"", NULL);
              axutil_stream_write(stream, env, type_attrib, axutil_strlen(type_attrib));

              AXIS2_FREE(env->allocator, type_attrib);
                
              string_to_stream = ">"; 
              axutil_stream_write(stream, env, string_to_stream, axutil_strlen(string_to_stream));
              tag_closed = 1;
            
            }
            else {
              /* if the parent tag closed we would be able to declare the type directly on the parent element */ 
              if(!(xsi_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://www.w3.org/2001/XMLSchema-instance", AXIS2_HASH_KEY_STRING)))
              {
                  /* it is better to stick with the standard prefix */
                  xsi_prefix = (axis2_char_t*)axutil_strdup(env, "xsi");
                  
                  axutil_hash_set(namespaces, "http://www.w3.org/2001/XMLSchema-instance", AXIS2_HASH_KEY_STRING, xsi_prefix);

                  if(parent_element)
                  {
                        axiom_namespace_t *element_ns = NULL;
                        element_ns = axiom_namespace_create(env, "http://www.w3.org/2001/XMLSchema-instance",
                                                            xsi_prefix);
                        axiom_element_declare_namespace_assume_param_ownership(parent_element, env, element_ns);
                  }
              }
            }
            xsi_ns = axiom_namespace_create (env,
                                 "http://core.user.carbon.wso2.org/xsd",
                                 xsi_prefix);
            xsi_type_attri = axiom_attribute_create (env, "type", "AccessControlAdmin", xsi_ns);
            
            axiom_element_add_attribute (parent_element, env, xsi_type_attri, parent);
        

            return parent;
        }


        

