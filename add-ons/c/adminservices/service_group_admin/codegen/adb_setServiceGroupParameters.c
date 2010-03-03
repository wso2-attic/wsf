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
         * adb_setServiceGroupParameters.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_setServiceGroupParameters.h"
        
               /*
                * implmentation of the setServiceGroupParameters|http://org.apache.axis2/xsd element
                */
           


        struct adb_setServiceGroupParameters
        {
            axis2_char_t *property_Type;

            
                axutil_qname_t* qname;
            axis2_char_t* property_serviceGroupId;

                
                axis2_bool_t is_valid_serviceGroupId;
            axutil_array_list_t* property_parameterElement;

                
                axis2_bool_t is_valid_parameterElement;
            
        };


       /************************* Private Function prototypes ********************************/
        


       /************************* Function Implmentations ********************************/
        adb_setServiceGroupParameters_t* AXIS2_CALL
        adb_setServiceGroupParameters_create(
            const axutil_env_t *env)
        {
            adb_setServiceGroupParameters_t *_setServiceGroupParameters = NULL;
            
                axutil_qname_t* qname = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _setServiceGroupParameters = (adb_setServiceGroupParameters_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_setServiceGroupParameters_t));

            if(NULL == _setServiceGroupParameters)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_setServiceGroupParameters, 0, sizeof(adb_setServiceGroupParameters_t));

            _setServiceGroupParameters->property_Type = axutil_strdup(env, "adb_setServiceGroupParameters");
            _setServiceGroupParameters->property_serviceGroupId  = NULL;
                  _setServiceGroupParameters->is_valid_serviceGroupId  = AXIS2_FALSE;
            _setServiceGroupParameters->property_parameterElement  = NULL;
                  _setServiceGroupParameters->is_valid_parameterElement  = AXIS2_FALSE;
            
                  qname =  axutil_qname_create (env,
                        "setServiceGroupParameters",
                        "http://org.apache.axis2/xsd",
                        NULL);
                _setServiceGroupParameters->qname = qname;
            

            return _setServiceGroupParameters;
        }

        adb_setServiceGroupParameters_t* AXIS2_CALL
        adb_setServiceGroupParameters_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _serviceGroupId,
                axutil_array_list_t* _parameterElement)
        {
            adb_setServiceGroupParameters_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_setServiceGroupParameters_create(env);

            
              status = adb_setServiceGroupParameters_set_serviceGroupId(
                                     adb_obj,
                                     env,
                                     _serviceGroupId);
              if(status == AXIS2_FAILURE) {
                  adb_setServiceGroupParameters_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_setServiceGroupParameters_set_parameterElement(
                                     adb_obj,
                                     env,
                                     _parameterElement);
              if(status == AXIS2_FAILURE) {
                  adb_setServiceGroupParameters_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_char_t* AXIS2_CALL
                adb_setServiceGroupParameters_free_popping_value(
                        adb_setServiceGroupParameters_t* _setServiceGroupParameters,
                        const axutil_env_t *env)
                {
                    axis2_char_t* value;

                    
                    
                    value = _setServiceGroupParameters->property_serviceGroupId;

                    _setServiceGroupParameters->property_serviceGroupId = (axis2_char_t*)NULL;
                    adb_setServiceGroupParameters_free(_setServiceGroupParameters, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_setServiceGroupParameters_free(
                adb_setServiceGroupParameters_t* _setServiceGroupParameters,
                const axutil_env_t *env)
        {
            
            
            return adb_setServiceGroupParameters_free_obj(
                _setServiceGroupParameters,
                env);
            
        }

        axis2_status_t AXIS2_CALL
        adb_setServiceGroupParameters_free_obj(
                adb_setServiceGroupParameters_t* _setServiceGroupParameters,
                const axutil_env_t *env)
        {
            
                int i = 0;
                int count = 0;
                void *element = NULL;
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _setServiceGroupParameters, AXIS2_FAILURE);

            if (_setServiceGroupParameters->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _setServiceGroupParameters->property_Type);
            }

            adb_setServiceGroupParameters_reset_serviceGroupId(_setServiceGroupParameters, env);
            adb_setServiceGroupParameters_reset_parameterElement(_setServiceGroupParameters, env);
            
              if(_setServiceGroupParameters->qname)
              {
                  axutil_qname_free (_setServiceGroupParameters->qname, env);
                  _setServiceGroupParameters->qname = NULL;
              }
            

            if(_setServiceGroupParameters)
            {
                AXIS2_FREE(env->allocator, _setServiceGroupParameters);
                _setServiceGroupParameters = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_setServiceGroupParameters_deserialize(
                adb_setServiceGroupParameters_t* _setServiceGroupParameters,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return adb_setServiceGroupParameters_deserialize_obj(
                _setServiceGroupParameters,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs);
            
        }

        axis2_status_t AXIS2_CALL
        adb_setServiceGroupParameters_deserialize_obj(
                adb_setServiceGroupParameters_t* _setServiceGroupParameters,
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
            AXIS2_PARAM_CHECK(env->error, _setServiceGroupParameters, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for setServiceGroupParameters : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              

                    current_element = (axiom_element_t *)axiom_node_get_data_element(parent, env);
                    qname = axiom_element_get_qname(current_element, env, parent);
                    if (axutil_qname_equals(qname, env, _setServiceGroupParameters-> qname))
                    {
                        
                          first_node = axiom_node_get_first_child(parent, env);
                          
                    }
                    else
                    {
                        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                              "Failed in building adb object for setServiceGroupParameters : "
                              "Expected %s but returned %s",
                              axutil_qname_to_string(_setServiceGroupParameters-> qname, env),
                              axutil_qname_to_string(qname, env));
                        
                        return AXIS2_FAILURE;
                    }
                    

                     
                     /*
                      * building serviceGroupId element
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
                                   
                                 element_qname = axutil_qname_create(env, "serviceGroupId", "http://org.apache.axis2/xsd", NULL);
                                 

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
                                            status = adb_setServiceGroupParameters_set_serviceGroupId(_setServiceGroupParameters, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for serviceGroupId ");
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
                     * building parameterElement array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building parameterElement element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "parameterElement", "http://org.apache.axis2/xsd", NULL);
                                  
                               
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
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for parameterElement ");
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
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "parameterElement (@minOccurs = '0') only have %d elements", i);
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
                                    status = adb_setServiceGroupParameters_set_parameterElement(_setServiceGroupParameters, env,
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
          adb_setServiceGroupParameters_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_setServiceGroupParameters_declare_parent_namespaces(
                    adb_setServiceGroupParameters_t* _setServiceGroupParameters,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_setServiceGroupParameters_serialize(
                adb_setServiceGroupParameters_t* _setServiceGroupParameters,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
                return adb_setServiceGroupParameters_serialize_obj(
                    _setServiceGroupParameters, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            
        }

        axiom_node_t* AXIS2_CALL
        adb_setServiceGroupParameters_serialize_obj(
                adb_setServiceGroupParameters_t* _setServiceGroupParameters,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
         
         axiom_node_t* current_node = NULL;
         int tag_closed = 0;
         
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

             
                int next_ns_index_value = 0;
            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _setServiceGroupParameters, NULL);
            
             
                    namespaces = axutil_hash_make(env);
                    next_ns_index = &next_ns_index_value;
                     
                           ns1 = axiom_namespace_create (env,
                                             "http://org.apache.axis2/xsd",
                                             "n"); 
                           axutil_hash_set(namespaces, "http://org.apache.axis2/xsd", AXIS2_HASH_KEY_STRING, axutil_strdup(env, "n"));
                       
                     
                    parent_element = axiom_element_create (env, NULL, "setServiceGroupParameters", ns1 , &parent);
                    
                    
                    axiom_element_set_namespace(parent_element, env, ns1, parent);


            
                    data_source = axiom_data_source_create(env, parent, &current_node);
                    stream = axiom_data_source_get_stream(data_source, env);
                  
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://org.apache.axis2/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://org.apache.axis2/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://org.apache.axis2/xsd",
                                            p_prefix));
                       }
                      

                   if (!_setServiceGroupParameters->is_valid_serviceGroupId)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("serviceGroupId"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("serviceGroupId")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing serviceGroupId element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sserviceGroupId>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sserviceGroupId>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_1 = _setServiceGroupParameters->property_serviceGroupId;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://org.apache.axis2/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://org.apache.axis2/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://org.apache.axis2/xsd",
                                            p_prefix));
                       }
                      

                   if (!_setServiceGroupParameters->is_valid_parameterElement)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("parameterElement"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("parameterElement")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing parameterElement array
                      */
                     if (_setServiceGroupParameters->property_parameterElement != NULL)
                     {
                        
                            sprintf(start_input_str, "<%s%sparameterElement>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%sparameterElement>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_setServiceGroupParameters->property_parameterElement, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_setServiceGroupParameters->property_parameterElement, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing parameterElement element
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

                 
                   if(namespaces)
                   {
                       axutil_hash_index_t *hi;
                       void *val;
                       for (hi = axutil_hash_first(namespaces, env); hi; hi = axutil_hash_next(env, hi)) 
                       {
                           axutil_hash_this(hi, NULL, NULL, &val);
                           AXIS2_FREE(env->allocator, val);
                       }
                       axutil_hash_free(namespaces, env);
                   }
                

            return parent;
        }


        

            /**
             * Getter for serviceGroupId by  Property Number 1
             */
            axis2_char_t* AXIS2_CALL
            adb_setServiceGroupParameters_get_property1(
                adb_setServiceGroupParameters_t* _setServiceGroupParameters,
                const axutil_env_t *env)
            {
                return adb_setServiceGroupParameters_get_serviceGroupId(_setServiceGroupParameters,
                                             env);
            }

            /**
             * getter for serviceGroupId.
             */
            axis2_char_t* AXIS2_CALL
            adb_setServiceGroupParameters_get_serviceGroupId(
                    adb_setServiceGroupParameters_t* _setServiceGroupParameters,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _setServiceGroupParameters, NULL);
                  

                return _setServiceGroupParameters->property_serviceGroupId;
             }

            /**
             * setter for serviceGroupId
             */
            axis2_status_t AXIS2_CALL
            adb_setServiceGroupParameters_set_serviceGroupId(
                    adb_setServiceGroupParameters_t* _setServiceGroupParameters,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_serviceGroupId)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _setServiceGroupParameters, AXIS2_FAILURE);
                
                if(_setServiceGroupParameters->is_valid_serviceGroupId &&
                        arg_serviceGroupId == _setServiceGroupParameters->property_serviceGroupId)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_setServiceGroupParameters_reset_serviceGroupId(_setServiceGroupParameters, env);

                
                if(NULL == arg_serviceGroupId)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _setServiceGroupParameters->property_serviceGroupId = (axis2_char_t *)axutil_strdup(env, arg_serviceGroupId);
                        if(NULL == _setServiceGroupParameters->property_serviceGroupId)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for serviceGroupId");
                            return AXIS2_FAILURE;
                        }
                        _setServiceGroupParameters->is_valid_serviceGroupId = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for serviceGroupId
            */
           axis2_status_t AXIS2_CALL
           adb_setServiceGroupParameters_reset_serviceGroupId(
                   adb_setServiceGroupParameters_t* _setServiceGroupParameters,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _setServiceGroupParameters, AXIS2_FAILURE);
               

               
            
                
                if(_setServiceGroupParameters->property_serviceGroupId != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _setServiceGroupParameters->property_serviceGroupId);
                     _setServiceGroupParameters->property_serviceGroupId = NULL;
                }
            
                
                
                _setServiceGroupParameters->is_valid_serviceGroupId = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether serviceGroupId is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_setServiceGroupParameters_is_serviceGroupId_nil(
                   adb_setServiceGroupParameters_t* _setServiceGroupParameters,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _setServiceGroupParameters, AXIS2_TRUE);
               
               return !_setServiceGroupParameters->is_valid_serviceGroupId;
           }

           /**
            * Set serviceGroupId to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_setServiceGroupParameters_set_serviceGroupId_nil(
                   adb_setServiceGroupParameters_t* _setServiceGroupParameters,
                   const axutil_env_t *env)
           {
               return adb_setServiceGroupParameters_reset_serviceGroupId(_setServiceGroupParameters, env);
           }

           

            /**
             * Getter for parameterElement by  Property Number 2
             */
            axutil_array_list_t* AXIS2_CALL
            adb_setServiceGroupParameters_get_property2(
                adb_setServiceGroupParameters_t* _setServiceGroupParameters,
                const axutil_env_t *env)
            {
                return adb_setServiceGroupParameters_get_parameterElement(_setServiceGroupParameters,
                                             env);
            }

            /**
             * getter for parameterElement.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_setServiceGroupParameters_get_parameterElement(
                    adb_setServiceGroupParameters_t* _setServiceGroupParameters,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _setServiceGroupParameters, NULL);
                  

                return _setServiceGroupParameters->property_parameterElement;
             }

            /**
             * setter for parameterElement
             */
            axis2_status_t AXIS2_CALL
            adb_setServiceGroupParameters_set_parameterElement(
                    adb_setServiceGroupParameters_t* _setServiceGroupParameters,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_parameterElement)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _setServiceGroupParameters, AXIS2_FAILURE);
                
                if(_setServiceGroupParameters->is_valid_parameterElement &&
                        arg_parameterElement == _setServiceGroupParameters->property_parameterElement)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_parameterElement, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "parameterElement has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_parameterElement, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_setServiceGroupParameters_reset_parameterElement(_setServiceGroupParameters, env);

                
                if(NULL == arg_parameterElement)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _setServiceGroupParameters->property_parameterElement = arg_parameterElement;
                        if(non_nil_exists)
                        {
                            _setServiceGroupParameters->is_valid_parameterElement = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of parameterElement.
             */
            axis2_char_t* AXIS2_CALL
            adb_setServiceGroupParameters_get_parameterElement_at(
                    adb_setServiceGroupParameters_t* _setServiceGroupParameters,
                    const axutil_env_t *env, int i)
            {
                axis2_char_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _setServiceGroupParameters, NULL);
                  

                if(_setServiceGroupParameters->property_parameterElement == NULL)
                {
                    return (axis2_char_t*)0;
                }
                ret_val = (axis2_char_t*)axutil_array_list_get(_setServiceGroupParameters->property_parameterElement, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of parameterElement.
             */
            axis2_status_t AXIS2_CALL
            adb_setServiceGroupParameters_set_parameterElement_at(
                    adb_setServiceGroupParameters_t* _setServiceGroupParameters,
                    const axutil_env_t *env, int i,
                    const axis2_char_t* arg_parameterElement)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _setServiceGroupParameters, AXIS2_FAILURE);
                
                if( _setServiceGroupParameters->is_valid_parameterElement &&
                    _setServiceGroupParameters->property_parameterElement &&
                
                    arg_parameterElement == (axis2_char_t*)axutil_array_list_get(_setServiceGroupParameters->property_parameterElement, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_parameterElement)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_setServiceGroupParameters->property_parameterElement != NULL)
                        {
                            size = axutil_array_list_size(_setServiceGroupParameters->property_parameterElement, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_setServiceGroupParameters->property_parameterElement, env, i))
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
                  

                if(_setServiceGroupParameters->property_parameterElement == NULL)
                {
                    _setServiceGroupParameters->property_parameterElement = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_setServiceGroupParameters->property_parameterElement, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _setServiceGroupParameters->is_valid_parameterElement = AXIS2_FALSE;
                        axutil_array_list_set(_setServiceGroupParameters->property_parameterElement , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_setServiceGroupParameters->property_parameterElement , env, i, axutil_strdup(env, arg_parameterElement));
                  _setServiceGroupParameters->is_valid_parameterElement = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to parameterElement.
             */
            axis2_status_t AXIS2_CALL
            adb_setServiceGroupParameters_add_parameterElement(
                    adb_setServiceGroupParameters_t* _setServiceGroupParameters,
                    const axutil_env_t *env,
                    const axis2_char_t* arg_parameterElement)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _setServiceGroupParameters, AXIS2_FAILURE);

                
                    if(NULL == arg_parameterElement)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_setServiceGroupParameters->property_parameterElement == NULL)
                {
                    _setServiceGroupParameters->property_parameterElement = axutil_array_list_create(env, 10);
                }
                if(_setServiceGroupParameters->property_parameterElement == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for parameterElement");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_setServiceGroupParameters->property_parameterElement , env, axutil_strdup(env, arg_parameterElement));
                  _setServiceGroupParameters->is_valid_parameterElement = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the parameterElement array.
             */
            int AXIS2_CALL
            adb_setServiceGroupParameters_sizeof_parameterElement(
                    adb_setServiceGroupParameters_t* _setServiceGroupParameters,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _setServiceGroupParameters, -1);
                if(_setServiceGroupParameters->property_parameterElement == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_setServiceGroupParameters->property_parameterElement, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_setServiceGroupParameters_remove_parameterElement_at(
                    adb_setServiceGroupParameters_t* _setServiceGroupParameters,
                    const axutil_env_t *env, int i)
            {
                return adb_setServiceGroupParameters_set_parameterElement_nil_at(_setServiceGroupParameters, env, i);
            }

            

           /**
            * resetter for parameterElement
            */
           axis2_status_t AXIS2_CALL
           adb_setServiceGroupParameters_reset_parameterElement(
                   adb_setServiceGroupParameters_t* _setServiceGroupParameters,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _setServiceGroupParameters, AXIS2_FAILURE);
               

               
                  if (_setServiceGroupParameters->property_parameterElement != NULL)
                  {
                      count = axutil_array_list_size(_setServiceGroupParameters->property_parameterElement, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_setServiceGroupParameters->property_parameterElement, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, (axis2_char_t*)element);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_setServiceGroupParameters->property_parameterElement, env);
                  }
                _setServiceGroupParameters->is_valid_parameterElement = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether parameterElement is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_setServiceGroupParameters_is_parameterElement_nil(
                   adb_setServiceGroupParameters_t* _setServiceGroupParameters,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _setServiceGroupParameters, AXIS2_TRUE);
               
               return !_setServiceGroupParameters->is_valid_parameterElement;
           }

           /**
            * Set parameterElement to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_setServiceGroupParameters_set_parameterElement_nil(
                   adb_setServiceGroupParameters_t* _setServiceGroupParameters,
                   const axutil_env_t *env)
           {
               return adb_setServiceGroupParameters_reset_parameterElement(_setServiceGroupParameters, env);
           }

           
           /**
            * Check whether parameterElement is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_setServiceGroupParameters_is_parameterElement_nil_at(
                   adb_setServiceGroupParameters_t* _setServiceGroupParameters,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _setServiceGroupParameters, AXIS2_TRUE);
               
               return (_setServiceGroupParameters->is_valid_parameterElement == AXIS2_FALSE ||
                        NULL == _setServiceGroupParameters->property_parameterElement || 
                        NULL == axutil_array_list_get(_setServiceGroupParameters->property_parameterElement, env, i));
           }

           /**
            * Set parameterElement to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_setServiceGroupParameters_set_parameterElement_nil_at(
                   adb_setServiceGroupParameters_t* _setServiceGroupParameters,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _setServiceGroupParameters, AXIS2_FAILURE);

                if(_setServiceGroupParameters->property_parameterElement == NULL ||
                            _setServiceGroupParameters->is_valid_parameterElement == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_setServiceGroupParameters->property_parameterElement, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_setServiceGroupParameters->property_parameterElement, env, i))
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
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of parameterElement is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_setServiceGroupParameters->property_parameterElement == NULL)
                {
                    _setServiceGroupParameters->is_valid_parameterElement = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_setServiceGroupParameters->property_parameterElement, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _setServiceGroupParameters->is_valid_parameterElement = AXIS2_FALSE;
                        axutil_array_list_set(_setServiceGroupParameters->property_parameterElement , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_setServiceGroupParameters->property_parameterElement , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

