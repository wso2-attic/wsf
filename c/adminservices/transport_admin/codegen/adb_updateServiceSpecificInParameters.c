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
         * adb_updateServiceSpecificInParameters.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_updateServiceSpecificInParameters.h"
        
               /*
                * implmentation of the updateServiceSpecificInParameters|http://org.apache.axis2/xsd element
                */
           


        struct adb_updateServiceSpecificInParameters
        {
            axis2_char_t *property_Type;

            
                axutil_qname_t* qname;
            axis2_char_t* property_transport;

                
                axis2_bool_t is_valid_transport;
            axis2_char_t* property_service;

                
                axis2_bool_t is_valid_service;
            axutil_array_list_t* property_params;

                
                axis2_bool_t is_valid_params;
            
        };


       /************************* Private Function prototypes ********************************/
        


       /************************* Function Implmentations ********************************/
        adb_updateServiceSpecificInParameters_t* AXIS2_CALL
        adb_updateServiceSpecificInParameters_create(
            const axutil_env_t *env)
        {
            adb_updateServiceSpecificInParameters_t *_updateServiceSpecificInParameters = NULL;
            
                axutil_qname_t* qname = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _updateServiceSpecificInParameters = (adb_updateServiceSpecificInParameters_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_updateServiceSpecificInParameters_t));

            if(NULL == _updateServiceSpecificInParameters)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_updateServiceSpecificInParameters, 0, sizeof(adb_updateServiceSpecificInParameters_t));

            _updateServiceSpecificInParameters->property_Type = axutil_strdup(env, "adb_updateServiceSpecificInParameters");
            _updateServiceSpecificInParameters->property_transport  = NULL;
                  _updateServiceSpecificInParameters->is_valid_transport  = AXIS2_FALSE;
            _updateServiceSpecificInParameters->property_service  = NULL;
                  _updateServiceSpecificInParameters->is_valid_service  = AXIS2_FALSE;
            _updateServiceSpecificInParameters->property_params  = NULL;
                  _updateServiceSpecificInParameters->is_valid_params  = AXIS2_FALSE;
            
                  qname =  axutil_qname_create (env,
                        "updateServiceSpecificInParameters",
                        "http://org.apache.axis2/xsd",
                        NULL);
                _updateServiceSpecificInParameters->qname = qname;
            

            return _updateServiceSpecificInParameters;
        }

        adb_updateServiceSpecificInParameters_t* AXIS2_CALL
        adb_updateServiceSpecificInParameters_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _transport,
                axis2_char_t* _service,
                axutil_array_list_t* _params)
        {
            adb_updateServiceSpecificInParameters_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_updateServiceSpecificInParameters_create(env);

            
              status = adb_updateServiceSpecificInParameters_set_transport(
                                     adb_obj,
                                     env,
                                     _transport);
              if(status == AXIS2_FAILURE) {
                  adb_updateServiceSpecificInParameters_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_updateServiceSpecificInParameters_set_service(
                                     adb_obj,
                                     env,
                                     _service);
              if(status == AXIS2_FAILURE) {
                  adb_updateServiceSpecificInParameters_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_updateServiceSpecificInParameters_set_params(
                                     adb_obj,
                                     env,
                                     _params);
              if(status == AXIS2_FAILURE) {
                  adb_updateServiceSpecificInParameters_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_char_t* AXIS2_CALL
                adb_updateServiceSpecificInParameters_free_popping_value(
                        adb_updateServiceSpecificInParameters_t* _updateServiceSpecificInParameters,
                        const axutil_env_t *env)
                {
                    axis2_char_t* value;

                    
                    
                    value = _updateServiceSpecificInParameters->property_transport;

                    _updateServiceSpecificInParameters->property_transport = (axis2_char_t*)NULL;
                    adb_updateServiceSpecificInParameters_free(_updateServiceSpecificInParameters, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_updateServiceSpecificInParameters_free(
                adb_updateServiceSpecificInParameters_t* _updateServiceSpecificInParameters,
                const axutil_env_t *env)
        {
            
            
            return adb_updateServiceSpecificInParameters_free_obj(
                _updateServiceSpecificInParameters,
                env);
            
        }

        axis2_status_t AXIS2_CALL
        adb_updateServiceSpecificInParameters_free_obj(
                adb_updateServiceSpecificInParameters_t* _updateServiceSpecificInParameters,
                const axutil_env_t *env)
        {
            
                int i = 0;
                int count = 0;
                void *element = NULL;
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _updateServiceSpecificInParameters, AXIS2_FAILURE);

            if (_updateServiceSpecificInParameters->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _updateServiceSpecificInParameters->property_Type);
            }

            adb_updateServiceSpecificInParameters_reset_transport(_updateServiceSpecificInParameters, env);
            adb_updateServiceSpecificInParameters_reset_service(_updateServiceSpecificInParameters, env);
            adb_updateServiceSpecificInParameters_reset_params(_updateServiceSpecificInParameters, env);
            
              if(_updateServiceSpecificInParameters->qname)
              {
                  axutil_qname_free (_updateServiceSpecificInParameters->qname, env);
                  _updateServiceSpecificInParameters->qname = NULL;
              }
            

            if(_updateServiceSpecificInParameters)
            {
                AXIS2_FREE(env->allocator, _updateServiceSpecificInParameters);
                _updateServiceSpecificInParameters = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_updateServiceSpecificInParameters_deserialize(
                adb_updateServiceSpecificInParameters_t* _updateServiceSpecificInParameters,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return adb_updateServiceSpecificInParameters_deserialize_obj(
                _updateServiceSpecificInParameters,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs);
            
        }

        axis2_status_t AXIS2_CALL
        adb_updateServiceSpecificInParameters_deserialize_obj(
                adb_updateServiceSpecificInParameters_t* _updateServiceSpecificInParameters,
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
            AXIS2_PARAM_CHECK(env->error, _updateServiceSpecificInParameters, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for updateServiceSpecificInParameters : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              

                    current_element = (axiom_element_t *)axiom_node_get_data_element(parent, env);
                    qname = axiom_element_get_qname(current_element, env, parent);
                    if (axutil_qname_equals(qname, env, _updateServiceSpecificInParameters-> qname))
                    {
                        
                          first_node = axiom_node_get_first_child(parent, env);
                          
                    }
                    else
                    {
                        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                              "Failed in building adb object for updateServiceSpecificInParameters : "
                              "Expected %s but returned %s",
                              axutil_qname_to_string(_updateServiceSpecificInParameters-> qname, env),
                              axutil_qname_to_string(qname, env));
                        
                        return AXIS2_FAILURE;
                    }
                    

                     
                     /*
                      * building transport element
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
                                   
                                 element_qname = axutil_qname_create(env, "transport", "http://org.apache.axis2/xsd", NULL);
                                 

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
                                            status = adb_updateServiceSpecificInParameters_set_transport(_updateServiceSpecificInParameters, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for transport ");
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
                      * building service element
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
                                 
                                 element_qname = axutil_qname_create(env, "service", "http://org.apache.axis2/xsd", NULL);
                                 

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
                                            status = adb_updateServiceSpecificInParameters_set_service(_updateServiceSpecificInParameters, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for service ");
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
                     * building params array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building params element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "params", "http://org.apache.axis2/xsd", NULL);
                                  
                               
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

                                  if (adb_TransportParameter_is_particle() ||  
                                    (current_node && current_element && (axutil_qname_equals(element_qname, env, qname))))
                                  {
                                  
                                      if( current_node && current_element && (axutil_qname_equals(element_qname, env, qname)))
                                      {
                                          is_early_node_valid = AXIS2_TRUE;
                                      }
                                      
                                     
                                          element = (void*)axis2_extension_mapper_create_from_node(env, &current_node, "adb_TransportParameter");
                                          
                                          status =  adb_TransportParameter_deserialize((adb_TransportParameter_t*)element, env,
                                                                                 &current_node, &is_early_node_valid, AXIS2_FALSE);
                                          
                                          if(AXIS2_FAILURE ==  status)
                                          {
                                              AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building element params ");
                                          }
                                          else
                                          {
                                            axutil_array_list_add_at(arr_list, env, i, element);
                                          }
                                        
                                     if(AXIS2_FAILURE ==  status)
                                     {
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for params ");
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
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "params (@minOccurs = '0') only have %d elements", i);
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
                                    status = adb_updateServiceSpecificInParameters_set_params(_updateServiceSpecificInParameters, env,
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
          adb_updateServiceSpecificInParameters_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_updateServiceSpecificInParameters_declare_parent_namespaces(
                    adb_updateServiceSpecificInParameters_t* _updateServiceSpecificInParameters,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_updateServiceSpecificInParameters_serialize(
                adb_updateServiceSpecificInParameters_t* _updateServiceSpecificInParameters,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
                return adb_updateServiceSpecificInParameters_serialize_obj(
                    _updateServiceSpecificInParameters, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            
        }

        axiom_node_t* AXIS2_CALL
        adb_updateServiceSpecificInParameters_serialize_obj(
                adb_updateServiceSpecificInParameters_t* _updateServiceSpecificInParameters,
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
                    
                    axis2_char_t text_value_3[ADB_DEFAULT_DIGIT_LIMIT];
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

             
                int next_ns_index_value = 0;
            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _updateServiceSpecificInParameters, NULL);
            
             
                    namespaces = axutil_hash_make(env);
                    next_ns_index = &next_ns_index_value;
                     
                           ns1 = axiom_namespace_create (env,
                                             "http://org.apache.axis2/xsd",
                                             "n"); 
                           axutil_hash_set(namespaces, "http://org.apache.axis2/xsd", AXIS2_HASH_KEY_STRING, axutil_strdup(env, "n"));
                       
                     
                    parent_element = axiom_element_create (env, NULL, "updateServiceSpecificInParameters", ns1 , &parent);
                    
                    
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
                      

                   if (!_updateServiceSpecificInParameters->is_valid_transport)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("transport"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("transport")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing transport element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%stransport>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%stransport>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_1 = _updateServiceSpecificInParameters->property_transport;
                           
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
                      

                   if (!_updateServiceSpecificInParameters->is_valid_service)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("service"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("service")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing service element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sservice>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sservice>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_2 = _updateServiceSpecificInParameters->property_service;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://org.apache.axis2/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://org.apache.axis2/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://org.apache.axis2/xsd",
                                            p_prefix));
                       }
                      

                   if (!_updateServiceSpecificInParameters->is_valid_params)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("params"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("params")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing params array
                      */
                     if (_updateServiceSpecificInParameters->property_params != NULL)
                     {
                        

                            sprintf(start_input_str, "<%s%sparams",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%sparams>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_updateServiceSpecificInParameters->property_params, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_updateServiceSpecificInParameters->property_params, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing params element
                      */

                    
                     
                            if(!adb_TransportParameter_is_particle())
                            {
                                axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                            }
                            adb_TransportParameter_serialize((adb_TransportParameter_t*)element, 
                                                                                 env, current_node, parent_element,
                                                                                 adb_TransportParameter_is_particle() || AXIS2_FALSE, namespaces, next_ns_index);
                            
                            if(!adb_TransportParameter_is_particle())
                            {
                                axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                            }
                            
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
             * Getter for transport by  Property Number 1
             */
            axis2_char_t* AXIS2_CALL
            adb_updateServiceSpecificInParameters_get_property1(
                adb_updateServiceSpecificInParameters_t* _updateServiceSpecificInParameters,
                const axutil_env_t *env)
            {
                return adb_updateServiceSpecificInParameters_get_transport(_updateServiceSpecificInParameters,
                                             env);
            }

            /**
             * getter for transport.
             */
            axis2_char_t* AXIS2_CALL
            adb_updateServiceSpecificInParameters_get_transport(
                    adb_updateServiceSpecificInParameters_t* _updateServiceSpecificInParameters,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _updateServiceSpecificInParameters, NULL);
                  

                return _updateServiceSpecificInParameters->property_transport;
             }

            /**
             * setter for transport
             */
            axis2_status_t AXIS2_CALL
            adb_updateServiceSpecificInParameters_set_transport(
                    adb_updateServiceSpecificInParameters_t* _updateServiceSpecificInParameters,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_transport)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _updateServiceSpecificInParameters, AXIS2_FAILURE);
                
                if(_updateServiceSpecificInParameters->is_valid_transport &&
                        arg_transport == _updateServiceSpecificInParameters->property_transport)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_updateServiceSpecificInParameters_reset_transport(_updateServiceSpecificInParameters, env);

                
                if(NULL == arg_transport)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _updateServiceSpecificInParameters->property_transport = (axis2_char_t *)axutil_strdup(env, arg_transport);
                        if(NULL == _updateServiceSpecificInParameters->property_transport)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for transport");
                            return AXIS2_FAILURE;
                        }
                        _updateServiceSpecificInParameters->is_valid_transport = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for transport
            */
           axis2_status_t AXIS2_CALL
           adb_updateServiceSpecificInParameters_reset_transport(
                   adb_updateServiceSpecificInParameters_t* _updateServiceSpecificInParameters,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _updateServiceSpecificInParameters, AXIS2_FAILURE);
               

               
            
                
                if(_updateServiceSpecificInParameters->property_transport != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _updateServiceSpecificInParameters->property_transport);
                     _updateServiceSpecificInParameters->property_transport = NULL;
                }
            
                
                
                _updateServiceSpecificInParameters->is_valid_transport = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether transport is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_updateServiceSpecificInParameters_is_transport_nil(
                   adb_updateServiceSpecificInParameters_t* _updateServiceSpecificInParameters,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _updateServiceSpecificInParameters, AXIS2_TRUE);
               
               return !_updateServiceSpecificInParameters->is_valid_transport;
           }

           /**
            * Set transport to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_updateServiceSpecificInParameters_set_transport_nil(
                   adb_updateServiceSpecificInParameters_t* _updateServiceSpecificInParameters,
                   const axutil_env_t *env)
           {
               return adb_updateServiceSpecificInParameters_reset_transport(_updateServiceSpecificInParameters, env);
           }

           

            /**
             * Getter for service by  Property Number 2
             */
            axis2_char_t* AXIS2_CALL
            adb_updateServiceSpecificInParameters_get_property2(
                adb_updateServiceSpecificInParameters_t* _updateServiceSpecificInParameters,
                const axutil_env_t *env)
            {
                return adb_updateServiceSpecificInParameters_get_service(_updateServiceSpecificInParameters,
                                             env);
            }

            /**
             * getter for service.
             */
            axis2_char_t* AXIS2_CALL
            adb_updateServiceSpecificInParameters_get_service(
                    adb_updateServiceSpecificInParameters_t* _updateServiceSpecificInParameters,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _updateServiceSpecificInParameters, NULL);
                  

                return _updateServiceSpecificInParameters->property_service;
             }

            /**
             * setter for service
             */
            axis2_status_t AXIS2_CALL
            adb_updateServiceSpecificInParameters_set_service(
                    adb_updateServiceSpecificInParameters_t* _updateServiceSpecificInParameters,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_service)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _updateServiceSpecificInParameters, AXIS2_FAILURE);
                
                if(_updateServiceSpecificInParameters->is_valid_service &&
                        arg_service == _updateServiceSpecificInParameters->property_service)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_updateServiceSpecificInParameters_reset_service(_updateServiceSpecificInParameters, env);

                
                if(NULL == arg_service)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _updateServiceSpecificInParameters->property_service = (axis2_char_t *)axutil_strdup(env, arg_service);
                        if(NULL == _updateServiceSpecificInParameters->property_service)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for service");
                            return AXIS2_FAILURE;
                        }
                        _updateServiceSpecificInParameters->is_valid_service = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for service
            */
           axis2_status_t AXIS2_CALL
           adb_updateServiceSpecificInParameters_reset_service(
                   adb_updateServiceSpecificInParameters_t* _updateServiceSpecificInParameters,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _updateServiceSpecificInParameters, AXIS2_FAILURE);
               

               
            
                
                if(_updateServiceSpecificInParameters->property_service != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _updateServiceSpecificInParameters->property_service);
                     _updateServiceSpecificInParameters->property_service = NULL;
                }
            
                
                
                _updateServiceSpecificInParameters->is_valid_service = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether service is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_updateServiceSpecificInParameters_is_service_nil(
                   adb_updateServiceSpecificInParameters_t* _updateServiceSpecificInParameters,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _updateServiceSpecificInParameters, AXIS2_TRUE);
               
               return !_updateServiceSpecificInParameters->is_valid_service;
           }

           /**
            * Set service to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_updateServiceSpecificInParameters_set_service_nil(
                   adb_updateServiceSpecificInParameters_t* _updateServiceSpecificInParameters,
                   const axutil_env_t *env)
           {
               return adb_updateServiceSpecificInParameters_reset_service(_updateServiceSpecificInParameters, env);
           }

           

            /**
             * Getter for params by  Property Number 3
             */
            axutil_array_list_t* AXIS2_CALL
            adb_updateServiceSpecificInParameters_get_property3(
                adb_updateServiceSpecificInParameters_t* _updateServiceSpecificInParameters,
                const axutil_env_t *env)
            {
                return adb_updateServiceSpecificInParameters_get_params(_updateServiceSpecificInParameters,
                                             env);
            }

            /**
             * getter for params.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_updateServiceSpecificInParameters_get_params(
                    adb_updateServiceSpecificInParameters_t* _updateServiceSpecificInParameters,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _updateServiceSpecificInParameters, NULL);
                  

                return _updateServiceSpecificInParameters->property_params;
             }

            /**
             * setter for params
             */
            axis2_status_t AXIS2_CALL
            adb_updateServiceSpecificInParameters_set_params(
                    adb_updateServiceSpecificInParameters_t* _updateServiceSpecificInParameters,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_params)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _updateServiceSpecificInParameters, AXIS2_FAILURE);
                
                if(_updateServiceSpecificInParameters->is_valid_params &&
                        arg_params == _updateServiceSpecificInParameters->property_params)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_params, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "params has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_params, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_updateServiceSpecificInParameters_reset_params(_updateServiceSpecificInParameters, env);

                
                if(NULL == arg_params)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _updateServiceSpecificInParameters->property_params = arg_params;
                        if(non_nil_exists)
                        {
                            _updateServiceSpecificInParameters->is_valid_params = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of params.
             */
            adb_TransportParameter_t* AXIS2_CALL
            adb_updateServiceSpecificInParameters_get_params_at(
                    adb_updateServiceSpecificInParameters_t* _updateServiceSpecificInParameters,
                    const axutil_env_t *env, int i)
            {
                adb_TransportParameter_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _updateServiceSpecificInParameters, NULL);
                  

                if(_updateServiceSpecificInParameters->property_params == NULL)
                {
                    return (adb_TransportParameter_t*)0;
                }
                ret_val = (adb_TransportParameter_t*)axutil_array_list_get(_updateServiceSpecificInParameters->property_params, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of params.
             */
            axis2_status_t AXIS2_CALL
            adb_updateServiceSpecificInParameters_set_params_at(
                    adb_updateServiceSpecificInParameters_t* _updateServiceSpecificInParameters,
                    const axutil_env_t *env, int i,
                    adb_TransportParameter_t* arg_params)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _updateServiceSpecificInParameters, AXIS2_FAILURE);
                
                if( _updateServiceSpecificInParameters->is_valid_params &&
                    _updateServiceSpecificInParameters->property_params &&
                
                    arg_params == (adb_TransportParameter_t*)axutil_array_list_get(_updateServiceSpecificInParameters->property_params, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_params)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_updateServiceSpecificInParameters->property_params != NULL)
                        {
                            size = axutil_array_list_size(_updateServiceSpecificInParameters->property_params, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_updateServiceSpecificInParameters->property_params, env, i))
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
                  

                if(_updateServiceSpecificInParameters->property_params == NULL)
                {
                    _updateServiceSpecificInParameters->property_params = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_updateServiceSpecificInParameters->property_params, env, i);
                if(NULL != element)
                {
                  
                  
                  adb_TransportParameter_free((adb_TransportParameter_t*)element, env);
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _updateServiceSpecificInParameters->is_valid_params = AXIS2_FALSE;
                        axutil_array_list_set(_updateServiceSpecificInParameters->property_params , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_updateServiceSpecificInParameters->property_params , env, i, arg_params);
                  _updateServiceSpecificInParameters->is_valid_params = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to params.
             */
            axis2_status_t AXIS2_CALL
            adb_updateServiceSpecificInParameters_add_params(
                    adb_updateServiceSpecificInParameters_t* _updateServiceSpecificInParameters,
                    const axutil_env_t *env,
                    adb_TransportParameter_t* arg_params)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _updateServiceSpecificInParameters, AXIS2_FAILURE);

                
                    if(NULL == arg_params)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_updateServiceSpecificInParameters->property_params == NULL)
                {
                    _updateServiceSpecificInParameters->property_params = axutil_array_list_create(env, 10);
                }
                if(_updateServiceSpecificInParameters->property_params == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for params");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_updateServiceSpecificInParameters->property_params , env, arg_params);
                  _updateServiceSpecificInParameters->is_valid_params = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the params array.
             */
            int AXIS2_CALL
            adb_updateServiceSpecificInParameters_sizeof_params(
                    adb_updateServiceSpecificInParameters_t* _updateServiceSpecificInParameters,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _updateServiceSpecificInParameters, -1);
                if(_updateServiceSpecificInParameters->property_params == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_updateServiceSpecificInParameters->property_params, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_updateServiceSpecificInParameters_remove_params_at(
                    adb_updateServiceSpecificInParameters_t* _updateServiceSpecificInParameters,
                    const axutil_env_t *env, int i)
            {
                return adb_updateServiceSpecificInParameters_set_params_nil_at(_updateServiceSpecificInParameters, env, i);
            }

            

           /**
            * resetter for params
            */
           axis2_status_t AXIS2_CALL
           adb_updateServiceSpecificInParameters_reset_params(
                   adb_updateServiceSpecificInParameters_t* _updateServiceSpecificInParameters,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _updateServiceSpecificInParameters, AXIS2_FAILURE);
               

               
                  if (_updateServiceSpecificInParameters->property_params != NULL)
                  {
                      count = axutil_array_list_size(_updateServiceSpecificInParameters->property_params, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_updateServiceSpecificInParameters->property_params, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   adb_TransportParameter_free((adb_TransportParameter_t*)element, env);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_updateServiceSpecificInParameters->property_params, env);
                  }
                _updateServiceSpecificInParameters->is_valid_params = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether params is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_updateServiceSpecificInParameters_is_params_nil(
                   adb_updateServiceSpecificInParameters_t* _updateServiceSpecificInParameters,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _updateServiceSpecificInParameters, AXIS2_TRUE);
               
               return !_updateServiceSpecificInParameters->is_valid_params;
           }

           /**
            * Set params to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_updateServiceSpecificInParameters_set_params_nil(
                   adb_updateServiceSpecificInParameters_t* _updateServiceSpecificInParameters,
                   const axutil_env_t *env)
           {
               return adb_updateServiceSpecificInParameters_reset_params(_updateServiceSpecificInParameters, env);
           }

           
           /**
            * Check whether params is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_updateServiceSpecificInParameters_is_params_nil_at(
                   adb_updateServiceSpecificInParameters_t* _updateServiceSpecificInParameters,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _updateServiceSpecificInParameters, AXIS2_TRUE);
               
               return (_updateServiceSpecificInParameters->is_valid_params == AXIS2_FALSE ||
                        NULL == _updateServiceSpecificInParameters->property_params || 
                        NULL == axutil_array_list_get(_updateServiceSpecificInParameters->property_params, env, i));
           }

           /**
            * Set params to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_updateServiceSpecificInParameters_set_params_nil_at(
                   adb_updateServiceSpecificInParameters_t* _updateServiceSpecificInParameters,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _updateServiceSpecificInParameters, AXIS2_FAILURE);

                if(_updateServiceSpecificInParameters->property_params == NULL ||
                            _updateServiceSpecificInParameters->is_valid_params == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_updateServiceSpecificInParameters->property_params, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_updateServiceSpecificInParameters->property_params, env, i))
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
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of params is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_updateServiceSpecificInParameters->property_params == NULL)
                {
                    _updateServiceSpecificInParameters->is_valid_params = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_updateServiceSpecificInParameters->property_params, env, i);
                if(NULL != element)
                {
                  
                  
                  adb_TransportParameter_free((adb_TransportParameter_t*)element, env);
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _updateServiceSpecificInParameters->is_valid_params = AXIS2_FALSE;
                        axutil_array_list_set(_updateServiceSpecificInParameters->property_params , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_updateServiceSpecificInParameters->property_params , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

