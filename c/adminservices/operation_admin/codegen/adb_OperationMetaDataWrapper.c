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
         * adb_OperationMetaDataWrapper.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_OperationMetaDataWrapper.h"
        
                /*
                 * This type was generated from the piece of schema that had
                 * name = OperationMetaDataWrapper
                 * Namespace URI = http://mgt.operation.carbon.wso2.org/xsd
                 * Namespace Prefix = ns1
                 */
           


        struct adb_OperationMetaDataWrapper
        {
            axis2_char_t *property_Type;

            axutil_array_list_t* property_controlOperations;

                
                axis2_bool_t is_valid_controlOperations;
            axutil_array_list_t* property_publishedOperations;

                
                axis2_bool_t is_valid_publishedOperations;
            
        };


       /************************* Private Function prototypes ********************************/
        


       /************************* Function Implmentations ********************************/
        adb_OperationMetaDataWrapper_t* AXIS2_CALL
        adb_OperationMetaDataWrapper_create(
            const axutil_env_t *env)
        {
            adb_OperationMetaDataWrapper_t *_OperationMetaDataWrapper = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _OperationMetaDataWrapper = (adb_OperationMetaDataWrapper_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_OperationMetaDataWrapper_t));

            if(NULL == _OperationMetaDataWrapper)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_OperationMetaDataWrapper, 0, sizeof(adb_OperationMetaDataWrapper_t));

            _OperationMetaDataWrapper->property_Type = axutil_strdup(env, "adb_OperationMetaDataWrapper");
            _OperationMetaDataWrapper->property_controlOperations  = NULL;
                  _OperationMetaDataWrapper->is_valid_controlOperations  = AXIS2_FALSE;
            _OperationMetaDataWrapper->property_publishedOperations  = NULL;
                  _OperationMetaDataWrapper->is_valid_publishedOperations  = AXIS2_FALSE;
            

            return _OperationMetaDataWrapper;
        }

        adb_OperationMetaDataWrapper_t* AXIS2_CALL
        adb_OperationMetaDataWrapper_create_with_values(
            const axutil_env_t *env,
                axutil_array_list_t* _controlOperations,
                axutil_array_list_t* _publishedOperations)
        {
            adb_OperationMetaDataWrapper_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_OperationMetaDataWrapper_create(env);

            
              status = adb_OperationMetaDataWrapper_set_controlOperations(
                                     adb_obj,
                                     env,
                                     _controlOperations);
              if(status == AXIS2_FAILURE) {
                  adb_OperationMetaDataWrapper_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_OperationMetaDataWrapper_set_publishedOperations(
                                     adb_obj,
                                     env,
                                     _publishedOperations);
              if(status == AXIS2_FAILURE) {
                  adb_OperationMetaDataWrapper_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axutil_array_list_t* AXIS2_CALL
                adb_OperationMetaDataWrapper_free_popping_value(
                        adb_OperationMetaDataWrapper_t* _OperationMetaDataWrapper,
                        const axutil_env_t *env)
                {
                    axutil_array_list_t* value;

                    
                    
                    value = _OperationMetaDataWrapper->property_controlOperations;

                    _OperationMetaDataWrapper->property_controlOperations = (axutil_array_list_t*)NULL;
                    adb_OperationMetaDataWrapper_free(_OperationMetaDataWrapper, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_OperationMetaDataWrapper_free(
                adb_OperationMetaDataWrapper_t* _OperationMetaDataWrapper,
                const axutil_env_t *env)
        {
            
            
            return axis2_extension_mapper_free(
                (adb_type_t*) _OperationMetaDataWrapper,
                env,
                "adb_OperationMetaDataWrapper");
            
        }

        axis2_status_t AXIS2_CALL
        adb_OperationMetaDataWrapper_free_obj(
                adb_OperationMetaDataWrapper_t* _OperationMetaDataWrapper,
                const axutil_env_t *env)
        {
            
                int i = 0;
                int count = 0;
                void *element = NULL;
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _OperationMetaDataWrapper, AXIS2_FAILURE);

            if (_OperationMetaDataWrapper->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _OperationMetaDataWrapper->property_Type);
            }

            adb_OperationMetaDataWrapper_reset_controlOperations(_OperationMetaDataWrapper, env);
            adb_OperationMetaDataWrapper_reset_publishedOperations(_OperationMetaDataWrapper, env);
            

            if(_OperationMetaDataWrapper)
            {
                AXIS2_FREE(env->allocator, _OperationMetaDataWrapper);
                _OperationMetaDataWrapper = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_OperationMetaDataWrapper_deserialize(
                adb_OperationMetaDataWrapper_t* _OperationMetaDataWrapper,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return axis2_extension_mapper_deserialize(
                (adb_type_t*) _OperationMetaDataWrapper,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs,
                "adb_OperationMetaDataWrapper");
            
        }

        axis2_status_t AXIS2_CALL
        adb_OperationMetaDataWrapper_deserialize_obj(
                adb_OperationMetaDataWrapper_t* _OperationMetaDataWrapper,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
          axiom_node_t *parent = *dp_parent;
          
          axis2_status_t status = AXIS2_SUCCESS;
          
              void *element = NULL;
           
             const axis2_char_t* text_value = NULL;
             axutil_qname_t *qname = NULL;
          
               int i = 0;
               axutil_array_list_t *arr_list = NULL;
            
               int sequence_broken = 0;
               axiom_node_t *tmp_node = NULL;
            
            axutil_qname_t *element_qname = NULL; 
            
               axiom_node_t *first_node = NULL;
               axis2_bool_t is_early_node_valid = AXIS2_TRUE;
               axiom_node_t *current_node = NULL;
               axiom_element_t *current_element = NULL;
            
            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _OperationMetaDataWrapper, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for OperationMetaDataWrapper : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              
                      
                      first_node = axiom_node_get_first_child(parent, env);
                      
                    
                    /*
                     * building controlOperations array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building controlOperations element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "controlOperations", "http://mgt.operation.carbon.wso2.org/xsd", NULL);
                                  
                               
                               for (i = 0, sequence_broken = 0, current_node = first_node; !sequence_broken && current_node != NULL;) 
                                             
                               {
                                  if(axiom_node_get_node_type(current_node, env) != AXIOM_ELEMENT)
                                  {
                                     current_node =axiom_node_get_next_sibling(current_node, env);
                                     is_early_node_valid = AXIS2_FALSE;
                                     continue;
                                  }
                                  
                                  current_element = (axiom_element_t *)axiom_node_get_data_element(current_node, env);
                                  qname = axiom_element_get_qname(current_element, env, current_node);

                                  if (adb_OperationMetaData_is_particle() ||  
                                    (current_node && current_element && (axutil_qname_equals(element_qname, env, qname))))
                                  {
                                  
                                      if( current_node && current_element && (axutil_qname_equals(element_qname, env, qname)))
                                      {
                                          is_early_node_valid = AXIS2_TRUE;
                                      }
                                      
                                     
                                          element = (void*)axis2_extension_mapper_create_from_node(env, &current_node, "adb_OperationMetaData");
                                          
                                          status =  adb_OperationMetaData_deserialize((adb_OperationMetaData_t*)element, env,
                                                                                 &current_node, &is_early_node_valid, AXIS2_FALSE);
                                          
                                          if(AXIS2_FAILURE ==  status)
                                          {
                                              AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building element controlOperations ");
                                          }
                                          else
                                          {
                                            axutil_array_list_add_at(arr_list, env, i, element);
                                          }
                                        
                                     if(AXIS2_FAILURE ==  status)
                                     {
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for controlOperations ");
                                         if(element_qname)
                                         {
                                            axutil_qname_free(element_qname, env);
                                         }
                                         if(arr_list)
                                         {
                                            axutil_array_list_free(arr_list, env);
                                         }
                                         return AXIS2_FAILURE;
                                     }

                                     i ++;
                                    current_node = axiom_node_get_next_sibling(current_node, env);
                                  }
                                  else
                                  {
                                      is_early_node_valid = AXIS2_FALSE;
                                      sequence_broken = 1;
                                  }
                                  
                               }

                               
                                   if (i < 0)
                                   {
                                     /* found element out of order */
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "controlOperations (@minOccurs = '0') only have %d elements", i);
                                     if(element_qname)
                                     {
                                        axutil_qname_free(element_qname, env);
                                     }
                                     if(arr_list)
                                     {
                                        axutil_array_list_free(arr_list, env);
                                     }
                                     return AXIS2_FAILURE;
                                   }
                               

                               if(0 == axutil_array_list_size(arr_list,env))
                               {
                                    axutil_array_list_free(arr_list, env);
                               }
                               else
                               {
                                    status = adb_OperationMetaDataWrapper_set_controlOperations(_OperationMetaDataWrapper, env,
                                                                   arr_list);
                               }

                             
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 
                    /*
                     * building publishedOperations array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building publishedOperations element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "publishedOperations", "http://mgt.operation.carbon.wso2.org/xsd", NULL);
                                  
                               
                               for (i = 0, sequence_broken = 0, current_node = (is_early_node_valid?axiom_node_get_next_sibling(current_node, env):current_node); !sequence_broken && current_node != NULL;) 
                                             
                               {
                                  if(axiom_node_get_node_type(current_node, env) != AXIOM_ELEMENT)
                                  {
                                     current_node =axiom_node_get_next_sibling(current_node, env);
                                     is_early_node_valid = AXIS2_FALSE;
                                     continue;
                                  }
                                  
                                  current_element = (axiom_element_t *)axiom_node_get_data_element(current_node, env);
                                  qname = axiom_element_get_qname(current_element, env, current_node);

                                  if (adb_OperationMetaData_is_particle() ||  
                                    (current_node && current_element && (axutil_qname_equals(element_qname, env, qname))))
                                  {
                                  
                                      if( current_node && current_element && (axutil_qname_equals(element_qname, env, qname)))
                                      {
                                          is_early_node_valid = AXIS2_TRUE;
                                      }
                                      
                                     
                                          element = (void*)axis2_extension_mapper_create_from_node(env, &current_node, "adb_OperationMetaData");
                                          
                                          status =  adb_OperationMetaData_deserialize((adb_OperationMetaData_t*)element, env,
                                                                                 &current_node, &is_early_node_valid, AXIS2_FALSE);
                                          
                                          if(AXIS2_FAILURE ==  status)
                                          {
                                              AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building element publishedOperations ");
                                          }
                                          else
                                          {
                                            axutil_array_list_add_at(arr_list, env, i, element);
                                          }
                                        
                                     if(AXIS2_FAILURE ==  status)
                                     {
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for publishedOperations ");
                                         if(element_qname)
                                         {
                                            axutil_qname_free(element_qname, env);
                                         }
                                         if(arr_list)
                                         {
                                            axutil_array_list_free(arr_list, env);
                                         }
                                         return AXIS2_FAILURE;
                                     }

                                     i ++;
                                    current_node = axiom_node_get_next_sibling(current_node, env);
                                  }
                                  else
                                  {
                                      is_early_node_valid = AXIS2_FALSE;
                                      sequence_broken = 1;
                                  }
                                  
                               }

                               
                                   if (i < 0)
                                   {
                                     /* found element out of order */
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "publishedOperations (@minOccurs = '0') only have %d elements", i);
                                     if(element_qname)
                                     {
                                        axutil_qname_free(element_qname, env);
                                     }
                                     if(arr_list)
                                     {
                                        axutil_array_list_free(arr_list, env);
                                     }
                                     return AXIS2_FAILURE;
                                   }
                               

                               if(0 == axutil_array_list_size(arr_list,env))
                               {
                                    axutil_array_list_free(arr_list, env);
                               }
                               else
                               {
                                    status = adb_OperationMetaDataWrapper_set_publishedOperations(_OperationMetaDataWrapper, env,
                                                                   arr_list);
                               }

                             
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 
          return status;
       }

          axis2_bool_t AXIS2_CALL
          adb_OperationMetaDataWrapper_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_OperationMetaDataWrapper_declare_parent_namespaces(
                    adb_OperationMetaDataWrapper_t* _OperationMetaDataWrapper,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_OperationMetaDataWrapper_serialize(
                adb_OperationMetaDataWrapper_t* _OperationMetaDataWrapper,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
            if (_OperationMetaDataWrapper == NULL)
            {
                return adb_OperationMetaDataWrapper_serialize_obj(
                    _OperationMetaDataWrapper, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            }
            else
            {
                return axis2_extension_mapper_serialize(
                    (adb_type_t*) _OperationMetaDataWrapper, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index, "adb_OperationMetaDataWrapper");
            }
            
        }

        axiom_node_t* AXIS2_CALL
        adb_OperationMetaDataWrapper_serialize_obj(
                adb_OperationMetaDataWrapper_t* _OperationMetaDataWrapper,
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
            
               int i = 0;
               int count = 0;
               void *element = NULL;
             
                    axis2_char_t text_value_1[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t text_value_2[ADB_DEFAULT_DIGIT_LIMIT];
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _OperationMetaDataWrapper, NULL);
            
            
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
              type_attrib = axutil_strcat(env, " ", xsi_prefix, ":type=\"OperationMetaDataWrapper\"", NULL);
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
                                 "http://mgt.operation.carbon.wso2.org/xsd",
                                 xsi_prefix);
            xsi_type_attri = axiom_attribute_create (env, "type", "OperationMetaDataWrapper", xsi_ns);
            
            axiom_element_add_attribute (parent_element, env, xsi_type_attri, parent);
        
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://mgt.operation.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://mgt.operation.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://mgt.operation.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_OperationMetaDataWrapper->is_valid_controlOperations)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("controlOperations"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("controlOperations")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing controlOperations array
                      */
                     if (_OperationMetaDataWrapper->property_controlOperations != NULL)
                     {
                        

                            sprintf(start_input_str, "<%s%scontrolOperations",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%scontrolOperations>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_OperationMetaDataWrapper->property_controlOperations, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_OperationMetaDataWrapper->property_controlOperations, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing controlOperations element
                      */

                    
                     
                            if(!adb_OperationMetaData_is_particle())
                            {
                                axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                            }
                            adb_OperationMetaData_serialize((adb_OperationMetaData_t*)element, 
                                                                                 env, current_node, parent_element,
                                                                                 adb_OperationMetaData_is_particle() || AXIS2_FALSE, namespaces, next_ns_index);
                            
                            if(!adb_OperationMetaData_is_particle())
                            {
                                axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                            }
                            
                         }
                     }
                   
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://mgt.operation.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://mgt.operation.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://mgt.operation.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_OperationMetaDataWrapper->is_valid_publishedOperations)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("publishedOperations"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("publishedOperations")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing publishedOperations array
                      */
                     if (_OperationMetaDataWrapper->property_publishedOperations != NULL)
                     {
                        

                            sprintf(start_input_str, "<%s%spublishedOperations",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%spublishedOperations>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_OperationMetaDataWrapper->property_publishedOperations, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_OperationMetaDataWrapper->property_publishedOperations, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing publishedOperations element
                      */

                    
                     
                            if(!adb_OperationMetaData_is_particle())
                            {
                                axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                            }
                            adb_OperationMetaData_serialize((adb_OperationMetaData_t*)element, 
                                                                                 env, current_node, parent_element,
                                                                                 adb_OperationMetaData_is_particle() || AXIS2_FALSE, namespaces, next_ns_index);
                            
                            if(!adb_OperationMetaData_is_particle())
                            {
                                axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                            }
                            
                         }
                     }
                   
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 

            return parent;
        }


        

            /**
             * Getter for controlOperations by  Property Number 1
             */
            axutil_array_list_t* AXIS2_CALL
            adb_OperationMetaDataWrapper_get_property1(
                adb_OperationMetaDataWrapper_t* _OperationMetaDataWrapper,
                const axutil_env_t *env)
            {
                return adb_OperationMetaDataWrapper_get_controlOperations(_OperationMetaDataWrapper,
                                             env);
            }

            /**
             * getter for controlOperations.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_OperationMetaDataWrapper_get_controlOperations(
                    adb_OperationMetaDataWrapper_t* _OperationMetaDataWrapper,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _OperationMetaDataWrapper, NULL);
                  

                return _OperationMetaDataWrapper->property_controlOperations;
             }

            /**
             * setter for controlOperations
             */
            axis2_status_t AXIS2_CALL
            adb_OperationMetaDataWrapper_set_controlOperations(
                    adb_OperationMetaDataWrapper_t* _OperationMetaDataWrapper,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_controlOperations)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _OperationMetaDataWrapper, AXIS2_FAILURE);
                
                if(_OperationMetaDataWrapper->is_valid_controlOperations &&
                        arg_controlOperations == _OperationMetaDataWrapper->property_controlOperations)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_controlOperations, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "controlOperations has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_controlOperations, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_OperationMetaDataWrapper_reset_controlOperations(_OperationMetaDataWrapper, env);

                
                if(NULL == arg_controlOperations)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _OperationMetaDataWrapper->property_controlOperations = arg_controlOperations;
                        if(non_nil_exists)
                        {
                            _OperationMetaDataWrapper->is_valid_controlOperations = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of controlOperations.
             */
            adb_OperationMetaData_t* AXIS2_CALL
            adb_OperationMetaDataWrapper_get_controlOperations_at(
                    adb_OperationMetaDataWrapper_t* _OperationMetaDataWrapper,
                    const axutil_env_t *env, int i)
            {
                adb_OperationMetaData_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _OperationMetaDataWrapper, NULL);
                  

                if(_OperationMetaDataWrapper->property_controlOperations == NULL)
                {
                    return (adb_OperationMetaData_t*)0;
                }
                ret_val = (adb_OperationMetaData_t*)axutil_array_list_get(_OperationMetaDataWrapper->property_controlOperations, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of controlOperations.
             */
            axis2_status_t AXIS2_CALL
            adb_OperationMetaDataWrapper_set_controlOperations_at(
                    adb_OperationMetaDataWrapper_t* _OperationMetaDataWrapper,
                    const axutil_env_t *env, int i,
                    adb_OperationMetaData_t* arg_controlOperations)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _OperationMetaDataWrapper, AXIS2_FAILURE);
                
                if( _OperationMetaDataWrapper->is_valid_controlOperations &&
                    _OperationMetaDataWrapper->property_controlOperations &&
                
                    arg_controlOperations == (adb_OperationMetaData_t*)axutil_array_list_get(_OperationMetaDataWrapper->property_controlOperations, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_controlOperations)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_OperationMetaDataWrapper->property_controlOperations != NULL)
                        {
                            size = axutil_array_list_size(_OperationMetaDataWrapper->property_controlOperations, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_OperationMetaDataWrapper->property_controlOperations, env, i))
                                {
                                    non_nil_count ++;
                                    non_nil_exists = AXIS2_TRUE;
                                    if(non_nil_count >= 0)
                                    {
                                        break;
                                    }
                                }
                            }

                        
                        }
                    }
                  

                if(_OperationMetaDataWrapper->property_controlOperations == NULL)
                {
                    _OperationMetaDataWrapper->property_controlOperations = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_OperationMetaDataWrapper->property_controlOperations, env, i);
                if(NULL != element)
                {
                  
                  
                  adb_OperationMetaData_free((adb_OperationMetaData_t*)element, env);
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _OperationMetaDataWrapper->is_valid_controlOperations = AXIS2_FALSE;
                        axutil_array_list_set(_OperationMetaDataWrapper->property_controlOperations , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_OperationMetaDataWrapper->property_controlOperations , env, i, arg_controlOperations);
                  _OperationMetaDataWrapper->is_valid_controlOperations = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to controlOperations.
             */
            axis2_status_t AXIS2_CALL
            adb_OperationMetaDataWrapper_add_controlOperations(
                    adb_OperationMetaDataWrapper_t* _OperationMetaDataWrapper,
                    const axutil_env_t *env,
                    adb_OperationMetaData_t* arg_controlOperations)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _OperationMetaDataWrapper, AXIS2_FAILURE);

                
                    if(NULL == arg_controlOperations)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_OperationMetaDataWrapper->property_controlOperations == NULL)
                {
                    _OperationMetaDataWrapper->property_controlOperations = axutil_array_list_create(env, 10);
                }
                if(_OperationMetaDataWrapper->property_controlOperations == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for controlOperations");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_OperationMetaDataWrapper->property_controlOperations , env, arg_controlOperations);
                  _OperationMetaDataWrapper->is_valid_controlOperations = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the controlOperations array.
             */
            int AXIS2_CALL
            adb_OperationMetaDataWrapper_sizeof_controlOperations(
                    adb_OperationMetaDataWrapper_t* _OperationMetaDataWrapper,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _OperationMetaDataWrapper, -1);
                if(_OperationMetaDataWrapper->property_controlOperations == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_OperationMetaDataWrapper->property_controlOperations, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_OperationMetaDataWrapper_remove_controlOperations_at(
                    adb_OperationMetaDataWrapper_t* _OperationMetaDataWrapper,
                    const axutil_env_t *env, int i)
            {
                return adb_OperationMetaDataWrapper_set_controlOperations_nil_at(_OperationMetaDataWrapper, env, i);
            }

            

           /**
            * resetter for controlOperations
            */
           axis2_status_t AXIS2_CALL
           adb_OperationMetaDataWrapper_reset_controlOperations(
                   adb_OperationMetaDataWrapper_t* _OperationMetaDataWrapper,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _OperationMetaDataWrapper, AXIS2_FAILURE);
               

               
                  if (_OperationMetaDataWrapper->property_controlOperations != NULL)
                  {
                      count = axutil_array_list_size(_OperationMetaDataWrapper->property_controlOperations, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_OperationMetaDataWrapper->property_controlOperations, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   adb_OperationMetaData_free((adb_OperationMetaData_t*)element, env);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_OperationMetaDataWrapper->property_controlOperations, env);
                  }
                _OperationMetaDataWrapper->is_valid_controlOperations = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether controlOperations is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_OperationMetaDataWrapper_is_controlOperations_nil(
                   adb_OperationMetaDataWrapper_t* _OperationMetaDataWrapper,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _OperationMetaDataWrapper, AXIS2_TRUE);
               
               return !_OperationMetaDataWrapper->is_valid_controlOperations;
           }

           /**
            * Set controlOperations to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_OperationMetaDataWrapper_set_controlOperations_nil(
                   adb_OperationMetaDataWrapper_t* _OperationMetaDataWrapper,
                   const axutil_env_t *env)
           {
               return adb_OperationMetaDataWrapper_reset_controlOperations(_OperationMetaDataWrapper, env);
           }

           
           /**
            * Check whether controlOperations is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_OperationMetaDataWrapper_is_controlOperations_nil_at(
                   adb_OperationMetaDataWrapper_t* _OperationMetaDataWrapper,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _OperationMetaDataWrapper, AXIS2_TRUE);
               
               return (_OperationMetaDataWrapper->is_valid_controlOperations == AXIS2_FALSE ||
                        NULL == _OperationMetaDataWrapper->property_controlOperations || 
                        NULL == axutil_array_list_get(_OperationMetaDataWrapper->property_controlOperations, env, i));
           }

           /**
            * Set controlOperations to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_OperationMetaDataWrapper_set_controlOperations_nil_at(
                   adb_OperationMetaDataWrapper_t* _OperationMetaDataWrapper,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _OperationMetaDataWrapper, AXIS2_FAILURE);

                if(_OperationMetaDataWrapper->property_controlOperations == NULL ||
                            _OperationMetaDataWrapper->is_valid_controlOperations == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_OperationMetaDataWrapper->property_controlOperations, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_OperationMetaDataWrapper->property_controlOperations, env, i))
                        {
                            k ++;
                            non_nil_exists = AXIS2_TRUE;
                            if( k >= 0)
                            {
                                break;
                            }
                        }
                    }
                }
                

                if( k < 0)
                {
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of controlOperations is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_OperationMetaDataWrapper->property_controlOperations == NULL)
                {
                    _OperationMetaDataWrapper->is_valid_controlOperations = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_OperationMetaDataWrapper->property_controlOperations, env, i);
                if(NULL != element)
                {
                  
                  
                  adb_OperationMetaData_free((adb_OperationMetaData_t*)element, env);
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _OperationMetaDataWrapper->is_valid_controlOperations = AXIS2_FALSE;
                        axutil_array_list_set(_OperationMetaDataWrapper->property_controlOperations , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_OperationMetaDataWrapper->property_controlOperations , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

            /**
             * Getter for publishedOperations by  Property Number 2
             */
            axutil_array_list_t* AXIS2_CALL
            adb_OperationMetaDataWrapper_get_property2(
                adb_OperationMetaDataWrapper_t* _OperationMetaDataWrapper,
                const axutil_env_t *env)
            {
                return adb_OperationMetaDataWrapper_get_publishedOperations(_OperationMetaDataWrapper,
                                             env);
            }

            /**
             * getter for publishedOperations.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_OperationMetaDataWrapper_get_publishedOperations(
                    adb_OperationMetaDataWrapper_t* _OperationMetaDataWrapper,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _OperationMetaDataWrapper, NULL);
                  

                return _OperationMetaDataWrapper->property_publishedOperations;
             }

            /**
             * setter for publishedOperations
             */
            axis2_status_t AXIS2_CALL
            adb_OperationMetaDataWrapper_set_publishedOperations(
                    adb_OperationMetaDataWrapper_t* _OperationMetaDataWrapper,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_publishedOperations)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _OperationMetaDataWrapper, AXIS2_FAILURE);
                
                if(_OperationMetaDataWrapper->is_valid_publishedOperations &&
                        arg_publishedOperations == _OperationMetaDataWrapper->property_publishedOperations)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_publishedOperations, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "publishedOperations has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_publishedOperations, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_OperationMetaDataWrapper_reset_publishedOperations(_OperationMetaDataWrapper, env);

                
                if(NULL == arg_publishedOperations)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _OperationMetaDataWrapper->property_publishedOperations = arg_publishedOperations;
                        if(non_nil_exists)
                        {
                            _OperationMetaDataWrapper->is_valid_publishedOperations = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of publishedOperations.
             */
            adb_OperationMetaData_t* AXIS2_CALL
            adb_OperationMetaDataWrapper_get_publishedOperations_at(
                    adb_OperationMetaDataWrapper_t* _OperationMetaDataWrapper,
                    const axutil_env_t *env, int i)
            {
                adb_OperationMetaData_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _OperationMetaDataWrapper, NULL);
                  

                if(_OperationMetaDataWrapper->property_publishedOperations == NULL)
                {
                    return (adb_OperationMetaData_t*)0;
                }
                ret_val = (adb_OperationMetaData_t*)axutil_array_list_get(_OperationMetaDataWrapper->property_publishedOperations, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of publishedOperations.
             */
            axis2_status_t AXIS2_CALL
            adb_OperationMetaDataWrapper_set_publishedOperations_at(
                    adb_OperationMetaDataWrapper_t* _OperationMetaDataWrapper,
                    const axutil_env_t *env, int i,
                    adb_OperationMetaData_t* arg_publishedOperations)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _OperationMetaDataWrapper, AXIS2_FAILURE);
                
                if( _OperationMetaDataWrapper->is_valid_publishedOperations &&
                    _OperationMetaDataWrapper->property_publishedOperations &&
                
                    arg_publishedOperations == (adb_OperationMetaData_t*)axutil_array_list_get(_OperationMetaDataWrapper->property_publishedOperations, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_publishedOperations)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_OperationMetaDataWrapper->property_publishedOperations != NULL)
                        {
                            size = axutil_array_list_size(_OperationMetaDataWrapper->property_publishedOperations, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_OperationMetaDataWrapper->property_publishedOperations, env, i))
                                {
                                    non_nil_count ++;
                                    non_nil_exists = AXIS2_TRUE;
                                    if(non_nil_count >= 0)
                                    {
                                        break;
                                    }
                                }
                            }

                        
                        }
                    }
                  

                if(_OperationMetaDataWrapper->property_publishedOperations == NULL)
                {
                    _OperationMetaDataWrapper->property_publishedOperations = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_OperationMetaDataWrapper->property_publishedOperations, env, i);
                if(NULL != element)
                {
                  
                  
                  adb_OperationMetaData_free((adb_OperationMetaData_t*)element, env);
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _OperationMetaDataWrapper->is_valid_publishedOperations = AXIS2_FALSE;
                        axutil_array_list_set(_OperationMetaDataWrapper->property_publishedOperations , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_OperationMetaDataWrapper->property_publishedOperations , env, i, arg_publishedOperations);
                  _OperationMetaDataWrapper->is_valid_publishedOperations = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to publishedOperations.
             */
            axis2_status_t AXIS2_CALL
            adb_OperationMetaDataWrapper_add_publishedOperations(
                    adb_OperationMetaDataWrapper_t* _OperationMetaDataWrapper,
                    const axutil_env_t *env,
                    adb_OperationMetaData_t* arg_publishedOperations)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _OperationMetaDataWrapper, AXIS2_FAILURE);

                
                    if(NULL == arg_publishedOperations)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_OperationMetaDataWrapper->property_publishedOperations == NULL)
                {
                    _OperationMetaDataWrapper->property_publishedOperations = axutil_array_list_create(env, 10);
                }
                if(_OperationMetaDataWrapper->property_publishedOperations == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for publishedOperations");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_OperationMetaDataWrapper->property_publishedOperations , env, arg_publishedOperations);
                  _OperationMetaDataWrapper->is_valid_publishedOperations = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the publishedOperations array.
             */
            int AXIS2_CALL
            adb_OperationMetaDataWrapper_sizeof_publishedOperations(
                    adb_OperationMetaDataWrapper_t* _OperationMetaDataWrapper,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _OperationMetaDataWrapper, -1);
                if(_OperationMetaDataWrapper->property_publishedOperations == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_OperationMetaDataWrapper->property_publishedOperations, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_OperationMetaDataWrapper_remove_publishedOperations_at(
                    adb_OperationMetaDataWrapper_t* _OperationMetaDataWrapper,
                    const axutil_env_t *env, int i)
            {
                return adb_OperationMetaDataWrapper_set_publishedOperations_nil_at(_OperationMetaDataWrapper, env, i);
            }

            

           /**
            * resetter for publishedOperations
            */
           axis2_status_t AXIS2_CALL
           adb_OperationMetaDataWrapper_reset_publishedOperations(
                   adb_OperationMetaDataWrapper_t* _OperationMetaDataWrapper,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _OperationMetaDataWrapper, AXIS2_FAILURE);
               

               
                  if (_OperationMetaDataWrapper->property_publishedOperations != NULL)
                  {
                      count = axutil_array_list_size(_OperationMetaDataWrapper->property_publishedOperations, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_OperationMetaDataWrapper->property_publishedOperations, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   adb_OperationMetaData_free((adb_OperationMetaData_t*)element, env);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_OperationMetaDataWrapper->property_publishedOperations, env);
                  }
                _OperationMetaDataWrapper->is_valid_publishedOperations = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether publishedOperations is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_OperationMetaDataWrapper_is_publishedOperations_nil(
                   adb_OperationMetaDataWrapper_t* _OperationMetaDataWrapper,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _OperationMetaDataWrapper, AXIS2_TRUE);
               
               return !_OperationMetaDataWrapper->is_valid_publishedOperations;
           }

           /**
            * Set publishedOperations to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_OperationMetaDataWrapper_set_publishedOperations_nil(
                   adb_OperationMetaDataWrapper_t* _OperationMetaDataWrapper,
                   const axutil_env_t *env)
           {
               return adb_OperationMetaDataWrapper_reset_publishedOperations(_OperationMetaDataWrapper, env);
           }

           
           /**
            * Check whether publishedOperations is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_OperationMetaDataWrapper_is_publishedOperations_nil_at(
                   adb_OperationMetaDataWrapper_t* _OperationMetaDataWrapper,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _OperationMetaDataWrapper, AXIS2_TRUE);
               
               return (_OperationMetaDataWrapper->is_valid_publishedOperations == AXIS2_FALSE ||
                        NULL == _OperationMetaDataWrapper->property_publishedOperations || 
                        NULL == axutil_array_list_get(_OperationMetaDataWrapper->property_publishedOperations, env, i));
           }

           /**
            * Set publishedOperations to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_OperationMetaDataWrapper_set_publishedOperations_nil_at(
                   adb_OperationMetaDataWrapper_t* _OperationMetaDataWrapper,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _OperationMetaDataWrapper, AXIS2_FAILURE);

                if(_OperationMetaDataWrapper->property_publishedOperations == NULL ||
                            _OperationMetaDataWrapper->is_valid_publishedOperations == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_OperationMetaDataWrapper->property_publishedOperations, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_OperationMetaDataWrapper->property_publishedOperations, env, i))
                        {
                            k ++;
                            non_nil_exists = AXIS2_TRUE;
                            if( k >= 0)
                            {
                                break;
                            }
                        }
                    }
                }
                

                if( k < 0)
                {
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of publishedOperations is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_OperationMetaDataWrapper->property_publishedOperations == NULL)
                {
                    _OperationMetaDataWrapper->is_valid_publishedOperations = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_OperationMetaDataWrapper->property_publishedOperations, env, i);
                if(NULL != element)
                {
                  
                  
                  adb_OperationMetaData_free((adb_OperationMetaData_t*)element, env);
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _OperationMetaDataWrapper->is_valid_publishedOperations = AXIS2_FALSE;
                        axutil_array_list_set(_OperationMetaDataWrapper->property_publishedOperations , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_OperationMetaDataWrapper->property_publishedOperations , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

