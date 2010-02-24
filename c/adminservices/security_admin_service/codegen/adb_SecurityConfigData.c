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
         * adb_SecurityConfigData.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_SecurityConfigData.h"
        
                /*
                 * This type was generated from the piece of schema that had
                 * name = SecurityConfigData
                 * Namespace URI = http://service.config.security.carbon.wso2.org/xsd
                 * Namespace Prefix = ns1
                 */
           


        struct adb_SecurityConfigData
        {
            axis2_char_t *property_Type;

            axis2_char_t* property_privateStore;

                
                axis2_bool_t is_valid_privateStore;
            axutil_array_list_t* property_trustedKeyStores;

                
                axis2_bool_t is_valid_trustedKeyStores;
            axutil_array_list_t* property_userGroups;

                
                axis2_bool_t is_valid_userGroups;
            
        };


       /************************* Private Function prototypes ********************************/
        


       /************************* Function Implmentations ********************************/
        adb_SecurityConfigData_t* AXIS2_CALL
        adb_SecurityConfigData_create(
            const axutil_env_t *env)
        {
            adb_SecurityConfigData_t *_SecurityConfigData = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _SecurityConfigData = (adb_SecurityConfigData_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_SecurityConfigData_t));

            if(NULL == _SecurityConfigData)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_SecurityConfigData, 0, sizeof(adb_SecurityConfigData_t));

            _SecurityConfigData->property_Type = axutil_strdup(env, "adb_SecurityConfigData");
            _SecurityConfigData->property_privateStore  = NULL;
                  _SecurityConfigData->is_valid_privateStore  = AXIS2_FALSE;
            _SecurityConfigData->property_trustedKeyStores  = NULL;
                  _SecurityConfigData->is_valid_trustedKeyStores  = AXIS2_FALSE;
            _SecurityConfigData->property_userGroups  = NULL;
                  _SecurityConfigData->is_valid_userGroups  = AXIS2_FALSE;
            

            return _SecurityConfigData;
        }

        adb_SecurityConfigData_t* AXIS2_CALL
        adb_SecurityConfigData_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _privateStore,
                axutil_array_list_t* _trustedKeyStores,
                axutil_array_list_t* _userGroups)
        {
            adb_SecurityConfigData_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_SecurityConfigData_create(env);

            
              status = adb_SecurityConfigData_set_privateStore(
                                     adb_obj,
                                     env,
                                     _privateStore);
              if(status == AXIS2_FAILURE) {
                  adb_SecurityConfigData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_SecurityConfigData_set_trustedKeyStores(
                                     adb_obj,
                                     env,
                                     _trustedKeyStores);
              if(status == AXIS2_FAILURE) {
                  adb_SecurityConfigData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_SecurityConfigData_set_userGroups(
                                     adb_obj,
                                     env,
                                     _userGroups);
              if(status == AXIS2_FAILURE) {
                  adb_SecurityConfigData_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_char_t* AXIS2_CALL
                adb_SecurityConfigData_free_popping_value(
                        adb_SecurityConfigData_t* _SecurityConfigData,
                        const axutil_env_t *env)
                {
                    axis2_char_t* value;

                    
                    
                    value = _SecurityConfigData->property_privateStore;

                    _SecurityConfigData->property_privateStore = (axis2_char_t*)NULL;
                    adb_SecurityConfigData_free(_SecurityConfigData, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_SecurityConfigData_free(
                adb_SecurityConfigData_t* _SecurityConfigData,
                const axutil_env_t *env)
        {
            
            
            return axis2_extension_mapper_free(
                (adb_type_t*) _SecurityConfigData,
                env,
                "adb_SecurityConfigData");
            
        }

        axis2_status_t AXIS2_CALL
        adb_SecurityConfigData_free_obj(
                adb_SecurityConfigData_t* _SecurityConfigData,
                const axutil_env_t *env)
        {
            
                int i = 0;
                int count = 0;
                void *element = NULL;
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _SecurityConfigData, AXIS2_FAILURE);

            if (_SecurityConfigData->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _SecurityConfigData->property_Type);
            }

            adb_SecurityConfigData_reset_privateStore(_SecurityConfigData, env);
            adb_SecurityConfigData_reset_trustedKeyStores(_SecurityConfigData, env);
            adb_SecurityConfigData_reset_userGroups(_SecurityConfigData, env);
            

            if(_SecurityConfigData)
            {
                AXIS2_FREE(env->allocator, _SecurityConfigData);
                _SecurityConfigData = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_SecurityConfigData_deserialize(
                adb_SecurityConfigData_t* _SecurityConfigData,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return axis2_extension_mapper_deserialize(
                (adb_type_t*) _SecurityConfigData,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs,
                "adb_SecurityConfigData");
            
        }

        axis2_status_t AXIS2_CALL
        adb_SecurityConfigData_deserialize_obj(
                adb_SecurityConfigData_t* _SecurityConfigData,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
          axiom_node_t *parent = *dp_parent;
          
          axis2_status_t status = AXIS2_SUCCESS;
           
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
            AXIS2_PARAM_CHECK(env->error, _SecurityConfigData, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for SecurityConfigData : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              
                      
                      first_node = axiom_node_get_first_child(parent, env);
                      
                    

                     
                     /*
                      * building privateStore element
                      */
                     
                     
                     
                                   current_node = first_node;
                                   is_early_node_valid = AXIS2_FALSE;
                                   
                                   
                                    while(current_node && axiom_node_get_node_type(current_node, env) != AXIOM_ELEMENT)
                                    {
                                        current_node = axiom_node_get_next_sibling(current_node, env);
                                    }
                                    if(current_node != NULL)
                                    {
                                        current_element = (axiom_element_t *)axiom_node_get_data_element(current_node, env);
                                        qname = axiom_element_get_qname(current_element, env, current_node);
                                    }
                                   
                                 element_qname = axutil_qname_create(env, "privateStore", "http://service.config.security.carbon.wso2.org/xsd", NULL);
                                 

                           if ( 
                                (current_node   && current_element && (axutil_qname_equals(element_qname, env, qname))))
                           {
                              if( current_node   && current_element && (axutil_qname_equals(element_qname, env, qname)))
                              {
                                is_early_node_valid = AXIS2_TRUE;
                              }
                              
                                 
                                      text_value = axiom_element_get_text(current_element, env, current_node);
                                      if(text_value != NULL)
                                      {
                                            status = adb_SecurityConfigData_set_privateStore(_SecurityConfigData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for privateStore ");
                                     if(element_qname)
                                     {
                                         axutil_qname_free(element_qname, env);
                                     }
                                     return AXIS2_FAILURE;
                                 }
                              }
                           
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 
                    /*
                     * building trustedKeyStores array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building trustedKeyStores element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "trustedKeyStores", "http://service.config.security.carbon.wso2.org/xsd", NULL);
                                  
                               
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

                                  if ( 
                                    (current_node && current_element && (axutil_qname_equals(element_qname, env, qname))))
                                  {
                                  
                                      if( current_node && current_element && (axutil_qname_equals(element_qname, env, qname)))
                                      {
                                          is_early_node_valid = AXIS2_TRUE;
                                      }
                                      
                                     
                                          text_value = axiom_element_get_text(current_element, env, current_node);
                                          if(text_value != NULL)
                                          {
                                              axutil_array_list_add_at(arr_list, env, i, axutil_strdup(env, text_value));
                                          }
                                          
                                     if(AXIS2_FAILURE ==  status)
                                     {
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for trustedKeyStores ");
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
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "trustedKeyStores (@minOccurs = '0') only have %d elements", i);
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
                                    status = adb_SecurityConfigData_set_trustedKeyStores(_SecurityConfigData, env,
                                                                   arr_list);
                               }

                             
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 
                    /*
                     * building userGroups array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building userGroups element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "userGroups", "http://service.config.security.carbon.wso2.org/xsd", NULL);
                                  
                               
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

                                  if ( 
                                    (current_node && current_element && (axutil_qname_equals(element_qname, env, qname))))
                                  {
                                  
                                      if( current_node && current_element && (axutil_qname_equals(element_qname, env, qname)))
                                      {
                                          is_early_node_valid = AXIS2_TRUE;
                                      }
                                      
                                     
                                          text_value = axiom_element_get_text(current_element, env, current_node);
                                          if(text_value != NULL)
                                          {
                                              axutil_array_list_add_at(arr_list, env, i, axutil_strdup(env, text_value));
                                          }
                                          
                                     if(AXIS2_FAILURE ==  status)
                                     {
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for userGroups ");
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
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "userGroups (@minOccurs = '0') only have %d elements", i);
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
                                    status = adb_SecurityConfigData_set_userGroups(_SecurityConfigData, env,
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
          adb_SecurityConfigData_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_SecurityConfigData_declare_parent_namespaces(
                    adb_SecurityConfigData_t* _SecurityConfigData,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_SecurityConfigData_serialize(
                adb_SecurityConfigData_t* _SecurityConfigData,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
            if (_SecurityConfigData == NULL)
            {
                return adb_SecurityConfigData_serialize_obj(
                    _SecurityConfigData, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            }
            else
            {
                return axis2_extension_mapper_serialize(
                    (adb_type_t*) _SecurityConfigData, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index, "adb_SecurityConfigData");
            }
            
        }

        axiom_node_t* AXIS2_CALL
        adb_SecurityConfigData_serialize_obj(
                adb_SecurityConfigData_t* _SecurityConfigData,
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
             
                    axis2_char_t *text_value_1;
                    axis2_char_t *text_value_1_temp;
                    
                    axis2_char_t *text_value_2;
                    axis2_char_t *text_value_2_temp;
                    
                    axis2_char_t *text_value_3;
                    axis2_char_t *text_value_3_temp;
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _SecurityConfigData, NULL);
            
            
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
              type_attrib = axutil_strcat(env, " ", xsi_prefix, ":type=\"SecurityConfigData\"", NULL);
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
                                 "http://service.config.security.carbon.wso2.org/xsd",
                                 xsi_prefix);
            xsi_type_attri = axiom_attribute_create (env, "type", "SecurityConfigData", xsi_ns);
            
            axiom_element_add_attribute (parent_element, env, xsi_type_attri, parent);
        
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.config.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.config.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.config.security.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_SecurityConfigData->is_valid_privateStore)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("privateStore"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("privateStore")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing privateStore element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sprivateStore>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sprivateStore>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_1 = _SecurityConfigData->property_privateStore;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_1_temp = axutil_xml_quote_string(env, text_value_1, AXIS2_TRUE);
                           if (text_value_1_temp)
                           {
                               axutil_stream_write(stream, env, text_value_1_temp, axutil_strlen(text_value_1_temp));
                               AXIS2_FREE(env->allocator, text_value_1_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_1, axutil_strlen(text_value_1));
                           }
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.config.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.config.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.config.security.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_SecurityConfigData->is_valid_trustedKeyStores)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("trustedKeyStores"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("trustedKeyStores")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing trustedKeyStores array
                      */
                     if (_SecurityConfigData->property_trustedKeyStores != NULL)
                     {
                        
                            sprintf(start_input_str, "<%s%strustedKeyStores>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%strustedKeyStores>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_SecurityConfigData->property_trustedKeyStores, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_SecurityConfigData->property_trustedKeyStores, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing trustedKeyStores element
                      */

                    
                    
                           text_value_2 = (axis2_char_t*)element;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_2_temp = axutil_xml_quote_string(env, text_value_2, AXIS2_TRUE);
                           if (text_value_2_temp)
                           {
                               axutil_stream_write(stream, env, text_value_2_temp, axutil_strlen(text_value_2_temp));
                               AXIS2_FREE(env->allocator, text_value_2_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_2, axutil_strlen(text_value_2));
                           }
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                         }
                     }
                   
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.config.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.config.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.config.security.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_SecurityConfigData->is_valid_userGroups)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("userGroups"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("userGroups")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing userGroups array
                      */
                     if (_SecurityConfigData->property_userGroups != NULL)
                     {
                        
                            sprintf(start_input_str, "<%s%suserGroups>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%suserGroups>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_SecurityConfigData->property_userGroups, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_SecurityConfigData->property_userGroups, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing userGroups element
                      */

                    
                    
                           text_value_3 = (axis2_char_t*)element;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_3_temp = axutil_xml_quote_string(env, text_value_3, AXIS2_TRUE);
                           if (text_value_3_temp)
                           {
                               axutil_stream_write(stream, env, text_value_3_temp, axutil_strlen(text_value_3_temp));
                               AXIS2_FREE(env->allocator, text_value_3_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_3, axutil_strlen(text_value_3));
                           }
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                         }
                     }
                   
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 

            return parent;
        }


        

            /**
             * Getter for privateStore by  Property Number 1
             */
            axis2_char_t* AXIS2_CALL
            adb_SecurityConfigData_get_property1(
                adb_SecurityConfigData_t* _SecurityConfigData,
                const axutil_env_t *env)
            {
                return adb_SecurityConfigData_get_privateStore(_SecurityConfigData,
                                             env);
            }

            /**
             * getter for privateStore.
             */
            axis2_char_t* AXIS2_CALL
            adb_SecurityConfigData_get_privateStore(
                    adb_SecurityConfigData_t* _SecurityConfigData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _SecurityConfigData, NULL);
                  

                return _SecurityConfigData->property_privateStore;
             }

            /**
             * setter for privateStore
             */
            axis2_status_t AXIS2_CALL
            adb_SecurityConfigData_set_privateStore(
                    adb_SecurityConfigData_t* _SecurityConfigData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_privateStore)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _SecurityConfigData, AXIS2_FAILURE);
                
                if(_SecurityConfigData->is_valid_privateStore &&
                        arg_privateStore == _SecurityConfigData->property_privateStore)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_SecurityConfigData_reset_privateStore(_SecurityConfigData, env);

                
                if(NULL == arg_privateStore)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _SecurityConfigData->property_privateStore = (axis2_char_t *)axutil_strdup(env, arg_privateStore);
                        if(NULL == _SecurityConfigData->property_privateStore)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for privateStore");
                            return AXIS2_FAILURE;
                        }
                        _SecurityConfigData->is_valid_privateStore = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for privateStore
            */
           axis2_status_t AXIS2_CALL
           adb_SecurityConfigData_reset_privateStore(
                   adb_SecurityConfigData_t* _SecurityConfigData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _SecurityConfigData, AXIS2_FAILURE);
               

               
            
                
                if(_SecurityConfigData->property_privateStore != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _SecurityConfigData->property_privateStore);
                     _SecurityConfigData->property_privateStore = NULL;
                }
            
                
                
                _SecurityConfigData->is_valid_privateStore = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether privateStore is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_SecurityConfigData_is_privateStore_nil(
                   adb_SecurityConfigData_t* _SecurityConfigData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _SecurityConfigData, AXIS2_TRUE);
               
               return !_SecurityConfigData->is_valid_privateStore;
           }

           /**
            * Set privateStore to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_SecurityConfigData_set_privateStore_nil(
                   adb_SecurityConfigData_t* _SecurityConfigData,
                   const axutil_env_t *env)
           {
               return adb_SecurityConfigData_reset_privateStore(_SecurityConfigData, env);
           }

           

            /**
             * Getter for trustedKeyStores by  Property Number 2
             */
            axutil_array_list_t* AXIS2_CALL
            adb_SecurityConfigData_get_property2(
                adb_SecurityConfigData_t* _SecurityConfigData,
                const axutil_env_t *env)
            {
                return adb_SecurityConfigData_get_trustedKeyStores(_SecurityConfigData,
                                             env);
            }

            /**
             * getter for trustedKeyStores.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_SecurityConfigData_get_trustedKeyStores(
                    adb_SecurityConfigData_t* _SecurityConfigData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _SecurityConfigData, NULL);
                  

                return _SecurityConfigData->property_trustedKeyStores;
             }

            /**
             * setter for trustedKeyStores
             */
            axis2_status_t AXIS2_CALL
            adb_SecurityConfigData_set_trustedKeyStores(
                    adb_SecurityConfigData_t* _SecurityConfigData,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_trustedKeyStores)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _SecurityConfigData, AXIS2_FAILURE);
                
                if(_SecurityConfigData->is_valid_trustedKeyStores &&
                        arg_trustedKeyStores == _SecurityConfigData->property_trustedKeyStores)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_trustedKeyStores, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "trustedKeyStores has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_trustedKeyStores, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_SecurityConfigData_reset_trustedKeyStores(_SecurityConfigData, env);

                
                if(NULL == arg_trustedKeyStores)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _SecurityConfigData->property_trustedKeyStores = arg_trustedKeyStores;
                        if(non_nil_exists)
                        {
                            _SecurityConfigData->is_valid_trustedKeyStores = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of trustedKeyStores.
             */
            axis2_char_t* AXIS2_CALL
            adb_SecurityConfigData_get_trustedKeyStores_at(
                    adb_SecurityConfigData_t* _SecurityConfigData,
                    const axutil_env_t *env, int i)
            {
                axis2_char_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _SecurityConfigData, NULL);
                  

                if(_SecurityConfigData->property_trustedKeyStores == NULL)
                {
                    return (axis2_char_t*)0;
                }
                ret_val = (axis2_char_t*)axutil_array_list_get(_SecurityConfigData->property_trustedKeyStores, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of trustedKeyStores.
             */
            axis2_status_t AXIS2_CALL
            adb_SecurityConfigData_set_trustedKeyStores_at(
                    adb_SecurityConfigData_t* _SecurityConfigData,
                    const axutil_env_t *env, int i,
                    const axis2_char_t* arg_trustedKeyStores)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _SecurityConfigData, AXIS2_FAILURE);
                
                if( _SecurityConfigData->is_valid_trustedKeyStores &&
                    _SecurityConfigData->property_trustedKeyStores &&
                
                    arg_trustedKeyStores == (axis2_char_t*)axutil_array_list_get(_SecurityConfigData->property_trustedKeyStores, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_trustedKeyStores)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_SecurityConfigData->property_trustedKeyStores != NULL)
                        {
                            size = axutil_array_list_size(_SecurityConfigData->property_trustedKeyStores, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_SecurityConfigData->property_trustedKeyStores, env, i))
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
                  

                if(_SecurityConfigData->property_trustedKeyStores == NULL)
                {
                    _SecurityConfigData->property_trustedKeyStores = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_SecurityConfigData->property_trustedKeyStores, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _SecurityConfigData->is_valid_trustedKeyStores = AXIS2_FALSE;
                        axutil_array_list_set(_SecurityConfigData->property_trustedKeyStores , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_SecurityConfigData->property_trustedKeyStores , env, i, axutil_strdup(env, arg_trustedKeyStores));
                  _SecurityConfigData->is_valid_trustedKeyStores = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to trustedKeyStores.
             */
            axis2_status_t AXIS2_CALL
            adb_SecurityConfigData_add_trustedKeyStores(
                    adb_SecurityConfigData_t* _SecurityConfigData,
                    const axutil_env_t *env,
                    const axis2_char_t* arg_trustedKeyStores)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _SecurityConfigData, AXIS2_FAILURE);

                
                    if(NULL == arg_trustedKeyStores)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_SecurityConfigData->property_trustedKeyStores == NULL)
                {
                    _SecurityConfigData->property_trustedKeyStores = axutil_array_list_create(env, 10);
                }
                if(_SecurityConfigData->property_trustedKeyStores == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for trustedKeyStores");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_SecurityConfigData->property_trustedKeyStores , env, axutil_strdup(env, arg_trustedKeyStores));
                  _SecurityConfigData->is_valid_trustedKeyStores = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the trustedKeyStores array.
             */
            int AXIS2_CALL
            adb_SecurityConfigData_sizeof_trustedKeyStores(
                    adb_SecurityConfigData_t* _SecurityConfigData,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _SecurityConfigData, -1);
                if(_SecurityConfigData->property_trustedKeyStores == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_SecurityConfigData->property_trustedKeyStores, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_SecurityConfigData_remove_trustedKeyStores_at(
                    adb_SecurityConfigData_t* _SecurityConfigData,
                    const axutil_env_t *env, int i)
            {
                return adb_SecurityConfigData_set_trustedKeyStores_nil_at(_SecurityConfigData, env, i);
            }

            

           /**
            * resetter for trustedKeyStores
            */
           axis2_status_t AXIS2_CALL
           adb_SecurityConfigData_reset_trustedKeyStores(
                   adb_SecurityConfigData_t* _SecurityConfigData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _SecurityConfigData, AXIS2_FAILURE);
               

               
                  if (_SecurityConfigData->property_trustedKeyStores != NULL)
                  {
                      count = axutil_array_list_size(_SecurityConfigData->property_trustedKeyStores, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_SecurityConfigData->property_trustedKeyStores, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, (axis2_char_t*)element);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_SecurityConfigData->property_trustedKeyStores, env);
                  }
                _SecurityConfigData->is_valid_trustedKeyStores = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether trustedKeyStores is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_SecurityConfigData_is_trustedKeyStores_nil(
                   adb_SecurityConfigData_t* _SecurityConfigData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _SecurityConfigData, AXIS2_TRUE);
               
               return !_SecurityConfigData->is_valid_trustedKeyStores;
           }

           /**
            * Set trustedKeyStores to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_SecurityConfigData_set_trustedKeyStores_nil(
                   adb_SecurityConfigData_t* _SecurityConfigData,
                   const axutil_env_t *env)
           {
               return adb_SecurityConfigData_reset_trustedKeyStores(_SecurityConfigData, env);
           }

           
           /**
            * Check whether trustedKeyStores is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_SecurityConfigData_is_trustedKeyStores_nil_at(
                   adb_SecurityConfigData_t* _SecurityConfigData,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _SecurityConfigData, AXIS2_TRUE);
               
               return (_SecurityConfigData->is_valid_trustedKeyStores == AXIS2_FALSE ||
                        NULL == _SecurityConfigData->property_trustedKeyStores || 
                        NULL == axutil_array_list_get(_SecurityConfigData->property_trustedKeyStores, env, i));
           }

           /**
            * Set trustedKeyStores to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_SecurityConfigData_set_trustedKeyStores_nil_at(
                   adb_SecurityConfigData_t* _SecurityConfigData,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _SecurityConfigData, AXIS2_FAILURE);

                if(_SecurityConfigData->property_trustedKeyStores == NULL ||
                            _SecurityConfigData->is_valid_trustedKeyStores == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_SecurityConfigData->property_trustedKeyStores, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_SecurityConfigData->property_trustedKeyStores, env, i))
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
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of trustedKeyStores is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_SecurityConfigData->property_trustedKeyStores == NULL)
                {
                    _SecurityConfigData->is_valid_trustedKeyStores = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_SecurityConfigData->property_trustedKeyStores, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _SecurityConfigData->is_valid_trustedKeyStores = AXIS2_FALSE;
                        axutil_array_list_set(_SecurityConfigData->property_trustedKeyStores , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_SecurityConfigData->property_trustedKeyStores , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

            /**
             * Getter for userGroups by  Property Number 3
             */
            axutil_array_list_t* AXIS2_CALL
            adb_SecurityConfigData_get_property3(
                adb_SecurityConfigData_t* _SecurityConfigData,
                const axutil_env_t *env)
            {
                return adb_SecurityConfigData_get_userGroups(_SecurityConfigData,
                                             env);
            }

            /**
             * getter for userGroups.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_SecurityConfigData_get_userGroups(
                    adb_SecurityConfigData_t* _SecurityConfigData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _SecurityConfigData, NULL);
                  

                return _SecurityConfigData->property_userGroups;
             }

            /**
             * setter for userGroups
             */
            axis2_status_t AXIS2_CALL
            adb_SecurityConfigData_set_userGroups(
                    adb_SecurityConfigData_t* _SecurityConfigData,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_userGroups)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _SecurityConfigData, AXIS2_FAILURE);
                
                if(_SecurityConfigData->is_valid_userGroups &&
                        arg_userGroups == _SecurityConfigData->property_userGroups)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_userGroups, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "userGroups has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_userGroups, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_SecurityConfigData_reset_userGroups(_SecurityConfigData, env);

                
                if(NULL == arg_userGroups)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _SecurityConfigData->property_userGroups = arg_userGroups;
                        if(non_nil_exists)
                        {
                            _SecurityConfigData->is_valid_userGroups = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of userGroups.
             */
            axis2_char_t* AXIS2_CALL
            adb_SecurityConfigData_get_userGroups_at(
                    adb_SecurityConfigData_t* _SecurityConfigData,
                    const axutil_env_t *env, int i)
            {
                axis2_char_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _SecurityConfigData, NULL);
                  

                if(_SecurityConfigData->property_userGroups == NULL)
                {
                    return (axis2_char_t*)0;
                }
                ret_val = (axis2_char_t*)axutil_array_list_get(_SecurityConfigData->property_userGroups, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of userGroups.
             */
            axis2_status_t AXIS2_CALL
            adb_SecurityConfigData_set_userGroups_at(
                    adb_SecurityConfigData_t* _SecurityConfigData,
                    const axutil_env_t *env, int i,
                    const axis2_char_t* arg_userGroups)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _SecurityConfigData, AXIS2_FAILURE);
                
                if( _SecurityConfigData->is_valid_userGroups &&
                    _SecurityConfigData->property_userGroups &&
                
                    arg_userGroups == (axis2_char_t*)axutil_array_list_get(_SecurityConfigData->property_userGroups, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_userGroups)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_SecurityConfigData->property_userGroups != NULL)
                        {
                            size = axutil_array_list_size(_SecurityConfigData->property_userGroups, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_SecurityConfigData->property_userGroups, env, i))
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
                  

                if(_SecurityConfigData->property_userGroups == NULL)
                {
                    _SecurityConfigData->property_userGroups = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_SecurityConfigData->property_userGroups, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _SecurityConfigData->is_valid_userGroups = AXIS2_FALSE;
                        axutil_array_list_set(_SecurityConfigData->property_userGroups , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_SecurityConfigData->property_userGroups , env, i, axutil_strdup(env, arg_userGroups));
                  _SecurityConfigData->is_valid_userGroups = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to userGroups.
             */
            axis2_status_t AXIS2_CALL
            adb_SecurityConfigData_add_userGroups(
                    adb_SecurityConfigData_t* _SecurityConfigData,
                    const axutil_env_t *env,
                    const axis2_char_t* arg_userGroups)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _SecurityConfigData, AXIS2_FAILURE);

                
                    if(NULL == arg_userGroups)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_SecurityConfigData->property_userGroups == NULL)
                {
                    _SecurityConfigData->property_userGroups = axutil_array_list_create(env, 10);
                }
                if(_SecurityConfigData->property_userGroups == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for userGroups");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_SecurityConfigData->property_userGroups , env, axutil_strdup(env, arg_userGroups));
                  _SecurityConfigData->is_valid_userGroups = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the userGroups array.
             */
            int AXIS2_CALL
            adb_SecurityConfigData_sizeof_userGroups(
                    adb_SecurityConfigData_t* _SecurityConfigData,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _SecurityConfigData, -1);
                if(_SecurityConfigData->property_userGroups == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_SecurityConfigData->property_userGroups, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_SecurityConfigData_remove_userGroups_at(
                    adb_SecurityConfigData_t* _SecurityConfigData,
                    const axutil_env_t *env, int i)
            {
                return adb_SecurityConfigData_set_userGroups_nil_at(_SecurityConfigData, env, i);
            }

            

           /**
            * resetter for userGroups
            */
           axis2_status_t AXIS2_CALL
           adb_SecurityConfigData_reset_userGroups(
                   adb_SecurityConfigData_t* _SecurityConfigData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _SecurityConfigData, AXIS2_FAILURE);
               

               
                  if (_SecurityConfigData->property_userGroups != NULL)
                  {
                      count = axutil_array_list_size(_SecurityConfigData->property_userGroups, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_SecurityConfigData->property_userGroups, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, (axis2_char_t*)element);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_SecurityConfigData->property_userGroups, env);
                  }
                _SecurityConfigData->is_valid_userGroups = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether userGroups is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_SecurityConfigData_is_userGroups_nil(
                   adb_SecurityConfigData_t* _SecurityConfigData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _SecurityConfigData, AXIS2_TRUE);
               
               return !_SecurityConfigData->is_valid_userGroups;
           }

           /**
            * Set userGroups to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_SecurityConfigData_set_userGroups_nil(
                   adb_SecurityConfigData_t* _SecurityConfigData,
                   const axutil_env_t *env)
           {
               return adb_SecurityConfigData_reset_userGroups(_SecurityConfigData, env);
           }

           
           /**
            * Check whether userGroups is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_SecurityConfigData_is_userGroups_nil_at(
                   adb_SecurityConfigData_t* _SecurityConfigData,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _SecurityConfigData, AXIS2_TRUE);
               
               return (_SecurityConfigData->is_valid_userGroups == AXIS2_FALSE ||
                        NULL == _SecurityConfigData->property_userGroups || 
                        NULL == axutil_array_list_get(_SecurityConfigData->property_userGroups, env, i));
           }

           /**
            * Set userGroups to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_SecurityConfigData_set_userGroups_nil_at(
                   adb_SecurityConfigData_t* _SecurityConfigData,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _SecurityConfigData, AXIS2_FAILURE);

                if(_SecurityConfigData->property_userGroups == NULL ||
                            _SecurityConfigData->is_valid_userGroups == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_SecurityConfigData->property_userGroups, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_SecurityConfigData->property_userGroups, env, i))
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
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of userGroups is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_SecurityConfigData->property_userGroups == NULL)
                {
                    _SecurityConfigData->is_valid_userGroups = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_SecurityConfigData->property_userGroups, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _SecurityConfigData->is_valid_userGroups = AXIS2_FALSE;
                        axutil_array_list_set(_SecurityConfigData->property_userGroups , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_SecurityConfigData->property_userGroups , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

