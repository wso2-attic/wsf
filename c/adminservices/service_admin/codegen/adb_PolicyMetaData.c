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
         * adb_PolicyMetaData.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_PolicyMetaData.h"
        
                /*
                 * This type was generated from the piece of schema that had
                 * name = PolicyMetaData
                 * Namespace URI = http://mgt.service.carbon.wso2.org/xsd
                 * Namespace Prefix = ns4
                 */
           


        struct adb_PolicyMetaData
        {
            axis2_char_t *property_Type;

            axutil_array_list_t* property_polycies;

                
                axis2_bool_t is_valid_polycies;
            axis2_char_t* property_wrapper;

                
                axis2_bool_t is_valid_wrapper;
            
        };


       /************************* Private Function prototypes ********************************/
        


       /************************* Function Implmentations ********************************/
        adb_PolicyMetaData_t* AXIS2_CALL
        adb_PolicyMetaData_create(
            const axutil_env_t *env)
        {
            adb_PolicyMetaData_t *_PolicyMetaData = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _PolicyMetaData = (adb_PolicyMetaData_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_PolicyMetaData_t));

            if(NULL == _PolicyMetaData)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_PolicyMetaData, 0, sizeof(adb_PolicyMetaData_t));

            _PolicyMetaData->property_Type = axutil_strdup(env, "adb_PolicyMetaData");
            _PolicyMetaData->property_polycies  = NULL;
                  _PolicyMetaData->is_valid_polycies  = AXIS2_FALSE;
            _PolicyMetaData->property_wrapper  = NULL;
                  _PolicyMetaData->is_valid_wrapper  = AXIS2_FALSE;
            

            return _PolicyMetaData;
        }

        adb_PolicyMetaData_t* AXIS2_CALL
        adb_PolicyMetaData_create_with_values(
            const axutil_env_t *env,
                axutil_array_list_t* _polycies,
                axis2_char_t* _wrapper)
        {
            adb_PolicyMetaData_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_PolicyMetaData_create(env);

            
              status = adb_PolicyMetaData_set_polycies(
                                     adb_obj,
                                     env,
                                     _polycies);
              if(status == AXIS2_FAILURE) {
                  adb_PolicyMetaData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_PolicyMetaData_set_wrapper(
                                     adb_obj,
                                     env,
                                     _wrapper);
              if(status == AXIS2_FAILURE) {
                  adb_PolicyMetaData_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axutil_array_list_t* AXIS2_CALL
                adb_PolicyMetaData_free_popping_value(
                        adb_PolicyMetaData_t* _PolicyMetaData,
                        const axutil_env_t *env)
                {
                    axutil_array_list_t* value;

                    
                    
                    value = _PolicyMetaData->property_polycies;

                    _PolicyMetaData->property_polycies = (axutil_array_list_t*)NULL;
                    adb_PolicyMetaData_free(_PolicyMetaData, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_PolicyMetaData_free(
                adb_PolicyMetaData_t* _PolicyMetaData,
                const axutil_env_t *env)
        {
            
            
            return axis2_extension_mapper_free(
                (adb_type_t*) _PolicyMetaData,
                env,
                "adb_PolicyMetaData");
            
        }

        axis2_status_t AXIS2_CALL
        adb_PolicyMetaData_free_obj(
                adb_PolicyMetaData_t* _PolicyMetaData,
                const axutil_env_t *env)
        {
            
                int i = 0;
                int count = 0;
                void *element = NULL;
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _PolicyMetaData, AXIS2_FAILURE);

            if (_PolicyMetaData->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _PolicyMetaData->property_Type);
            }

            adb_PolicyMetaData_reset_polycies(_PolicyMetaData, env);
            adb_PolicyMetaData_reset_wrapper(_PolicyMetaData, env);
            

            if(_PolicyMetaData)
            {
                AXIS2_FREE(env->allocator, _PolicyMetaData);
                _PolicyMetaData = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_PolicyMetaData_deserialize(
                adb_PolicyMetaData_t* _PolicyMetaData,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return axis2_extension_mapper_deserialize(
                (adb_type_t*) _PolicyMetaData,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs,
                "adb_PolicyMetaData");
            
        }

        axis2_status_t AXIS2_CALL
        adb_PolicyMetaData_deserialize_obj(
                adb_PolicyMetaData_t* _PolicyMetaData,
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
            AXIS2_PARAM_CHECK(env->error, _PolicyMetaData, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for PolicyMetaData : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              
                      
                      first_node = axiom_node_get_first_child(parent, env);
                      
                    
                    /*
                     * building polycies array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building polycies element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "polycies", "http://mgt.service.carbon.wso2.org/xsd", NULL);
                                  
                               
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
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for polycies ");
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
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "polycies (@minOccurs = '0') only have %d elements", i);
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
                                    status = adb_PolicyMetaData_set_polycies(_PolicyMetaData, env,
                                                                   arr_list);
                               }

                             
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 

                     
                     /*
                      * building wrapper element
                      */
                     
                     
                     
                                    /*
                                     * because elements are ordered this works fine
                                     */
                                  
                                   
                                   if(current_node != NULL && is_early_node_valid)
                                   {
                                       current_node = axiom_node_get_next_sibling(current_node, env);
                                       
                                       
                                        while(current_node && axiom_node_get_node_type(current_node, env) != AXIOM_ELEMENT)
                                        {
                                            current_node = axiom_node_get_next_sibling(current_node, env);
                                        }
                                        if(current_node != NULL)
                                        {
                                            current_element = (axiom_element_t *)axiom_node_get_data_element(current_node, env);
                                            qname = axiom_element_get_qname(current_element, env, current_node);
                                        }
                                       
                                   }
                                   is_early_node_valid = AXIS2_FALSE;
                                 
                                 element_qname = axutil_qname_create(env, "wrapper", "http://mgt.service.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_PolicyMetaData_set_wrapper(_PolicyMetaData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for wrapper ");
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
                 
          return status;
       }

          axis2_bool_t AXIS2_CALL
          adb_PolicyMetaData_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_PolicyMetaData_declare_parent_namespaces(
                    adb_PolicyMetaData_t* _PolicyMetaData,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_PolicyMetaData_serialize(
                adb_PolicyMetaData_t* _PolicyMetaData,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
            if (_PolicyMetaData == NULL)
            {
                return adb_PolicyMetaData_serialize_obj(
                    _PolicyMetaData, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            }
            else
            {
                return axis2_extension_mapper_serialize(
                    (adb_type_t*) _PolicyMetaData, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index, "adb_PolicyMetaData");
            }
            
        }

        axiom_node_t* AXIS2_CALL
        adb_PolicyMetaData_serialize_obj(
                adb_PolicyMetaData_t* _PolicyMetaData,
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
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _PolicyMetaData, NULL);
            
            
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
              type_attrib = axutil_strcat(env, " ", xsi_prefix, ":type=\"PolicyMetaData\"", NULL);
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
                                 "http://mgt.service.carbon.wso2.org/xsd",
                                 xsi_prefix);
            xsi_type_attri = axiom_attribute_create (env, "type", "PolicyMetaData", xsi_ns);
            
            axiom_element_add_attribute (parent_element, env, xsi_type_attri, parent);
        
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://mgt.service.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://mgt.service.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://mgt.service.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_PolicyMetaData->is_valid_polycies)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("polycies"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("polycies")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing polycies array
                      */
                     if (_PolicyMetaData->property_polycies != NULL)
                     {
                        
                            sprintf(start_input_str, "<%s%spolycies>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%spolycies>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_PolicyMetaData->property_polycies, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_PolicyMetaData->property_polycies, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing polycies element
                      */

                    
                    
                           text_value_1 = (axis2_char_t*)element;
                           
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
                           
                         }
                     }
                   
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://mgt.service.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://mgt.service.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://mgt.service.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_PolicyMetaData->is_valid_wrapper)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("wrapper"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("wrapper")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing wrapper element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%swrapper>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%swrapper>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_2 = _PolicyMetaData->property_wrapper;
                           
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
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 

            return parent;
        }


        

            /**
             * Getter for polycies by  Property Number 1
             */
            axutil_array_list_t* AXIS2_CALL
            adb_PolicyMetaData_get_property1(
                adb_PolicyMetaData_t* _PolicyMetaData,
                const axutil_env_t *env)
            {
                return adb_PolicyMetaData_get_polycies(_PolicyMetaData,
                                             env);
            }

            /**
             * getter for polycies.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_PolicyMetaData_get_polycies(
                    adb_PolicyMetaData_t* _PolicyMetaData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _PolicyMetaData, NULL);
                  

                return _PolicyMetaData->property_polycies;
             }

            /**
             * setter for polycies
             */
            axis2_status_t AXIS2_CALL
            adb_PolicyMetaData_set_polycies(
                    adb_PolicyMetaData_t* _PolicyMetaData,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_polycies)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _PolicyMetaData, AXIS2_FAILURE);
                
                if(_PolicyMetaData->is_valid_polycies &&
                        arg_polycies == _PolicyMetaData->property_polycies)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_polycies, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "polycies has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_polycies, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_PolicyMetaData_reset_polycies(_PolicyMetaData, env);

                
                if(NULL == arg_polycies)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _PolicyMetaData->property_polycies = arg_polycies;
                        if(non_nil_exists)
                        {
                            _PolicyMetaData->is_valid_polycies = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of polycies.
             */
            axis2_char_t* AXIS2_CALL
            adb_PolicyMetaData_get_polycies_at(
                    adb_PolicyMetaData_t* _PolicyMetaData,
                    const axutil_env_t *env, int i)
            {
                axis2_char_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _PolicyMetaData, NULL);
                  

                if(_PolicyMetaData->property_polycies == NULL)
                {
                    return (axis2_char_t*)0;
                }
                ret_val = (axis2_char_t*)axutil_array_list_get(_PolicyMetaData->property_polycies, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of polycies.
             */
            axis2_status_t AXIS2_CALL
            adb_PolicyMetaData_set_polycies_at(
                    adb_PolicyMetaData_t* _PolicyMetaData,
                    const axutil_env_t *env, int i,
                    const axis2_char_t* arg_polycies)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _PolicyMetaData, AXIS2_FAILURE);
                
                if( _PolicyMetaData->is_valid_polycies &&
                    _PolicyMetaData->property_polycies &&
                
                    arg_polycies == (axis2_char_t*)axutil_array_list_get(_PolicyMetaData->property_polycies, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_polycies)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_PolicyMetaData->property_polycies != NULL)
                        {
                            size = axutil_array_list_size(_PolicyMetaData->property_polycies, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_PolicyMetaData->property_polycies, env, i))
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
                  

                if(_PolicyMetaData->property_polycies == NULL)
                {
                    _PolicyMetaData->property_polycies = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_PolicyMetaData->property_polycies, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _PolicyMetaData->is_valid_polycies = AXIS2_FALSE;
                        axutil_array_list_set(_PolicyMetaData->property_polycies , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_PolicyMetaData->property_polycies , env, i, axutil_strdup(env, arg_polycies));
                  _PolicyMetaData->is_valid_polycies = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to polycies.
             */
            axis2_status_t AXIS2_CALL
            adb_PolicyMetaData_add_polycies(
                    adb_PolicyMetaData_t* _PolicyMetaData,
                    const axutil_env_t *env,
                    const axis2_char_t* arg_polycies)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _PolicyMetaData, AXIS2_FAILURE);

                
                    if(NULL == arg_polycies)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_PolicyMetaData->property_polycies == NULL)
                {
                    _PolicyMetaData->property_polycies = axutil_array_list_create(env, 10);
                }
                if(_PolicyMetaData->property_polycies == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for polycies");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_PolicyMetaData->property_polycies , env, axutil_strdup(env, arg_polycies));
                  _PolicyMetaData->is_valid_polycies = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the polycies array.
             */
            int AXIS2_CALL
            adb_PolicyMetaData_sizeof_polycies(
                    adb_PolicyMetaData_t* _PolicyMetaData,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _PolicyMetaData, -1);
                if(_PolicyMetaData->property_polycies == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_PolicyMetaData->property_polycies, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_PolicyMetaData_remove_polycies_at(
                    adb_PolicyMetaData_t* _PolicyMetaData,
                    const axutil_env_t *env, int i)
            {
                return adb_PolicyMetaData_set_polycies_nil_at(_PolicyMetaData, env, i);
            }

            

           /**
            * resetter for polycies
            */
           axis2_status_t AXIS2_CALL
           adb_PolicyMetaData_reset_polycies(
                   adb_PolicyMetaData_t* _PolicyMetaData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _PolicyMetaData, AXIS2_FAILURE);
               

               
                  if (_PolicyMetaData->property_polycies != NULL)
                  {
                      count = axutil_array_list_size(_PolicyMetaData->property_polycies, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_PolicyMetaData->property_polycies, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, (axis2_char_t*)element);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_PolicyMetaData->property_polycies, env);
                  }
                _PolicyMetaData->is_valid_polycies = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether polycies is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_PolicyMetaData_is_polycies_nil(
                   adb_PolicyMetaData_t* _PolicyMetaData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _PolicyMetaData, AXIS2_TRUE);
               
               return !_PolicyMetaData->is_valid_polycies;
           }

           /**
            * Set polycies to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_PolicyMetaData_set_polycies_nil(
                   adb_PolicyMetaData_t* _PolicyMetaData,
                   const axutil_env_t *env)
           {
               return adb_PolicyMetaData_reset_polycies(_PolicyMetaData, env);
           }

           
           /**
            * Check whether polycies is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_PolicyMetaData_is_polycies_nil_at(
                   adb_PolicyMetaData_t* _PolicyMetaData,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _PolicyMetaData, AXIS2_TRUE);
               
               return (_PolicyMetaData->is_valid_polycies == AXIS2_FALSE ||
                        NULL == _PolicyMetaData->property_polycies || 
                        NULL == axutil_array_list_get(_PolicyMetaData->property_polycies, env, i));
           }

           /**
            * Set polycies to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_PolicyMetaData_set_polycies_nil_at(
                   adb_PolicyMetaData_t* _PolicyMetaData,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _PolicyMetaData, AXIS2_FAILURE);

                if(_PolicyMetaData->property_polycies == NULL ||
                            _PolicyMetaData->is_valid_polycies == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_PolicyMetaData->property_polycies, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_PolicyMetaData->property_polycies, env, i))
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
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of polycies is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_PolicyMetaData->property_polycies == NULL)
                {
                    _PolicyMetaData->is_valid_polycies = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_PolicyMetaData->property_polycies, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _PolicyMetaData->is_valid_polycies = AXIS2_FALSE;
                        axutil_array_list_set(_PolicyMetaData->property_polycies , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_PolicyMetaData->property_polycies , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

            /**
             * Getter for wrapper by  Property Number 2
             */
            axis2_char_t* AXIS2_CALL
            adb_PolicyMetaData_get_property2(
                adb_PolicyMetaData_t* _PolicyMetaData,
                const axutil_env_t *env)
            {
                return adb_PolicyMetaData_get_wrapper(_PolicyMetaData,
                                             env);
            }

            /**
             * getter for wrapper.
             */
            axis2_char_t* AXIS2_CALL
            adb_PolicyMetaData_get_wrapper(
                    adb_PolicyMetaData_t* _PolicyMetaData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _PolicyMetaData, NULL);
                  

                return _PolicyMetaData->property_wrapper;
             }

            /**
             * setter for wrapper
             */
            axis2_status_t AXIS2_CALL
            adb_PolicyMetaData_set_wrapper(
                    adb_PolicyMetaData_t* _PolicyMetaData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_wrapper)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _PolicyMetaData, AXIS2_FAILURE);
                
                if(_PolicyMetaData->is_valid_wrapper &&
                        arg_wrapper == _PolicyMetaData->property_wrapper)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_PolicyMetaData_reset_wrapper(_PolicyMetaData, env);

                
                if(NULL == arg_wrapper)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _PolicyMetaData->property_wrapper = (axis2_char_t *)axutil_strdup(env, arg_wrapper);
                        if(NULL == _PolicyMetaData->property_wrapper)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for wrapper");
                            return AXIS2_FAILURE;
                        }
                        _PolicyMetaData->is_valid_wrapper = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for wrapper
            */
           axis2_status_t AXIS2_CALL
           adb_PolicyMetaData_reset_wrapper(
                   adb_PolicyMetaData_t* _PolicyMetaData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _PolicyMetaData, AXIS2_FAILURE);
               

               
            
                
                if(_PolicyMetaData->property_wrapper != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _PolicyMetaData->property_wrapper);
                     _PolicyMetaData->property_wrapper = NULL;
                }
            
                
                
                _PolicyMetaData->is_valid_wrapper = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether wrapper is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_PolicyMetaData_is_wrapper_nil(
                   adb_PolicyMetaData_t* _PolicyMetaData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _PolicyMetaData, AXIS2_TRUE);
               
               return !_PolicyMetaData->is_valid_wrapper;
           }

           /**
            * Set wrapper to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_PolicyMetaData_set_wrapper_nil(
                   adb_PolicyMetaData_t* _PolicyMetaData,
                   const axutil_env_t *env)
           {
               return adb_PolicyMetaData_reset_wrapper(_PolicyMetaData, env);
           }

           

