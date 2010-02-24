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
         * adb_updateSystemLog.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_updateSystemLog.h"
        
               /*
                * implmentation of the updateSystemLog|http://org.apache.axis2/xsd element
                */
           


        struct adb_updateSystemLog
        {
            axis2_char_t *property_Type;

            
                axutil_qname_t* qname;
            axis2_char_t* property_logLevel;

                
                axis2_bool_t is_valid_logLevel;
            axis2_char_t* property_logPattern;

                
                axis2_bool_t is_valid_logPattern;
            axis2_bool_t property_persist;

                
                axis2_bool_t is_valid_persist;
            
        };


       /************************* Private Function prototypes ********************************/
        

                axis2_status_t AXIS2_CALL
                adb_updateSystemLog_set_persist_nil(
                        adb_updateSystemLog_t* _updateSystemLog,
                        const axutil_env_t *env);
            


       /************************* Function Implmentations ********************************/
        adb_updateSystemLog_t* AXIS2_CALL
        adb_updateSystemLog_create(
            const axutil_env_t *env)
        {
            adb_updateSystemLog_t *_updateSystemLog = NULL;
            
                axutil_qname_t* qname = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _updateSystemLog = (adb_updateSystemLog_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_updateSystemLog_t));

            if(NULL == _updateSystemLog)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_updateSystemLog, 0, sizeof(adb_updateSystemLog_t));

            _updateSystemLog->property_Type = axutil_strdup(env, "adb_updateSystemLog");
            _updateSystemLog->property_logLevel  = NULL;
                  _updateSystemLog->is_valid_logLevel  = AXIS2_FALSE;
            _updateSystemLog->property_logPattern  = NULL;
                  _updateSystemLog->is_valid_logPattern  = AXIS2_FALSE;
            _updateSystemLog->is_valid_persist  = AXIS2_FALSE;
            
                  qname =  axutil_qname_create (env,
                        "updateSystemLog",
                        "http://org.apache.axis2/xsd",
                        NULL);
                _updateSystemLog->qname = qname;
            

            return _updateSystemLog;
        }

        adb_updateSystemLog_t* AXIS2_CALL
        adb_updateSystemLog_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _logLevel,
                axis2_char_t* _logPattern,
                axis2_bool_t _persist)
        {
            adb_updateSystemLog_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_updateSystemLog_create(env);

            
              status = adb_updateSystemLog_set_logLevel(
                                     adb_obj,
                                     env,
                                     _logLevel);
              if(status == AXIS2_FAILURE) {
                  adb_updateSystemLog_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_updateSystemLog_set_logPattern(
                                     adb_obj,
                                     env,
                                     _logPattern);
              if(status == AXIS2_FAILURE) {
                  adb_updateSystemLog_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_updateSystemLog_set_persist(
                                     adb_obj,
                                     env,
                                     _persist);
              if(status == AXIS2_FAILURE) {
                  adb_updateSystemLog_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_char_t* AXIS2_CALL
                adb_updateSystemLog_free_popping_value(
                        adb_updateSystemLog_t* _updateSystemLog,
                        const axutil_env_t *env)
                {
                    axis2_char_t* value;

                    
                    
                    value = _updateSystemLog->property_logLevel;

                    _updateSystemLog->property_logLevel = (axis2_char_t*)NULL;
                    adb_updateSystemLog_free(_updateSystemLog, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_updateSystemLog_free(
                adb_updateSystemLog_t* _updateSystemLog,
                const axutil_env_t *env)
        {
            
            
            return adb_updateSystemLog_free_obj(
                _updateSystemLog,
                env);
            
        }

        axis2_status_t AXIS2_CALL
        adb_updateSystemLog_free_obj(
                adb_updateSystemLog_t* _updateSystemLog,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _updateSystemLog, AXIS2_FAILURE);

            if (_updateSystemLog->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _updateSystemLog->property_Type);
            }

            adb_updateSystemLog_reset_logLevel(_updateSystemLog, env);
            adb_updateSystemLog_reset_logPattern(_updateSystemLog, env);
            adb_updateSystemLog_reset_persist(_updateSystemLog, env);
            
              if(_updateSystemLog->qname)
              {
                  axutil_qname_free (_updateSystemLog->qname, env);
                  _updateSystemLog->qname = NULL;
              }
            

            if(_updateSystemLog)
            {
                AXIS2_FREE(env->allocator, _updateSystemLog);
                _updateSystemLog = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_updateSystemLog_deserialize(
                adb_updateSystemLog_t* _updateSystemLog,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return adb_updateSystemLog_deserialize_obj(
                _updateSystemLog,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs);
            
        }

        axis2_status_t AXIS2_CALL
        adb_updateSystemLog_deserialize_obj(
                adb_updateSystemLog_t* _updateSystemLog,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
          axiom_node_t *parent = *dp_parent;
          
          axis2_status_t status = AXIS2_SUCCESS;
           
             const axis2_char_t* text_value = NULL;
             axutil_qname_t *qname = NULL;
          
            axutil_qname_t *element_qname = NULL; 
            
               axiom_node_t *first_node = NULL;
               axis2_bool_t is_early_node_valid = AXIS2_TRUE;
               axiom_node_t *current_node = NULL;
               axiom_element_t *current_element = NULL;
            
            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _updateSystemLog, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for updateSystemLog : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              

                    current_element = (axiom_element_t *)axiom_node_get_data_element(parent, env);
                    qname = axiom_element_get_qname(current_element, env, parent);
                    if (axutil_qname_equals(qname, env, _updateSystemLog-> qname))
                    {
                        
                          first_node = axiom_node_get_first_child(parent, env);
                          
                    }
                    else
                    {
                        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                              "Failed in building adb object for updateSystemLog : "
                              "Expected %s but returned %s",
                              axutil_qname_to_string(_updateSystemLog-> qname, env),
                              axutil_qname_to_string(qname, env));
                        
                        return AXIS2_FAILURE;
                    }
                    

                     
                     /*
                      * building logLevel element
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
                                   
                                 element_qname = axutil_qname_create(env, "logLevel", "http://org.apache.axis2/xsd", NULL);
                                 

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
                                            status = adb_updateSystemLog_set_logLevel(_updateSystemLog, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for logLevel ");
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
                      * building logPattern element
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
                                 
                                 element_qname = axutil_qname_create(env, "logPattern", "http://org.apache.axis2/xsd", NULL);
                                 

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
                                            status = adb_updateSystemLog_set_logPattern(_updateSystemLog, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for logPattern ");
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
                      * building persist element
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
                                 
                                 element_qname = axutil_qname_create(env, "persist", "http://org.apache.axis2/xsd", NULL);
                                 

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
                                            if (!axutil_strcasecmp(text_value , "true"))
                                            {
                                                status = adb_updateSystemLog_set_persist(_updateSystemLog, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_updateSystemLog_set_persist(_updateSystemLog, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element persist");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for persist ");
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
          adb_updateSystemLog_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_updateSystemLog_declare_parent_namespaces(
                    adb_updateSystemLog_t* _updateSystemLog,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_updateSystemLog_serialize(
                adb_updateSystemLog_t* _updateSystemLog,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
                return adb_updateSystemLog_serialize_obj(
                    _updateSystemLog, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            
        }

        axiom_node_t* AXIS2_CALL
        adb_updateSystemLog_serialize_obj(
                adb_updateSystemLog_t* _updateSystemLog,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
         
         axiom_node_t* current_node = NULL;
         int tag_closed = 0;
         
                axiom_namespace_t *ns1 = NULL;

                axis2_char_t *qname_uri = NULL;
                axis2_char_t *qname_prefix = NULL;
                axis2_char_t *p_prefix = NULL;
                axis2_bool_t ns_already_defined;
            
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
            AXIS2_PARAM_CHECK(env->error, _updateSystemLog, NULL);
            
             
                    namespaces = axutil_hash_make(env);
                    next_ns_index = &next_ns_index_value;
                     
                           ns1 = axiom_namespace_create (env,
                                             "http://org.apache.axis2/xsd",
                                             "n"); 
                           axutil_hash_set(namespaces, "http://org.apache.axis2/xsd", AXIS2_HASH_KEY_STRING, axutil_strdup(env, "n"));
                       
                     
                    parent_element = axiom_element_create (env, NULL, "updateSystemLog", ns1 , &parent);
                    
                    
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
                      

                   if (!_updateSystemLog->is_valid_logLevel)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("logLevel"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("logLevel")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing logLevel element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%slogLevel>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%slogLevel>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_1 = _updateSystemLog->property_logLevel;
                           
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
                      

                   if (!_updateSystemLog->is_valid_logPattern)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("logPattern"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("logPattern")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing logPattern element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%slogPattern>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%slogPattern>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_2 = _updateSystemLog->property_logPattern;
                           
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
                      

                   if (!_updateSystemLog->is_valid_persist)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("persist"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("persist")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing persist element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%spersist>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%spersist>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_3, (_updateSystemLog->property_persist)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_3, axutil_strlen(text_value_3));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
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
             * Getter for logLevel by  Property Number 1
             */
            axis2_char_t* AXIS2_CALL
            adb_updateSystemLog_get_property1(
                adb_updateSystemLog_t* _updateSystemLog,
                const axutil_env_t *env)
            {
                return adb_updateSystemLog_get_logLevel(_updateSystemLog,
                                             env);
            }

            /**
             * getter for logLevel.
             */
            axis2_char_t* AXIS2_CALL
            adb_updateSystemLog_get_logLevel(
                    adb_updateSystemLog_t* _updateSystemLog,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _updateSystemLog, NULL);
                  

                return _updateSystemLog->property_logLevel;
             }

            /**
             * setter for logLevel
             */
            axis2_status_t AXIS2_CALL
            adb_updateSystemLog_set_logLevel(
                    adb_updateSystemLog_t* _updateSystemLog,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_logLevel)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _updateSystemLog, AXIS2_FAILURE);
                
                if(_updateSystemLog->is_valid_logLevel &&
                        arg_logLevel == _updateSystemLog->property_logLevel)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_updateSystemLog_reset_logLevel(_updateSystemLog, env);

                
                if(NULL == arg_logLevel)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _updateSystemLog->property_logLevel = (axis2_char_t *)axutil_strdup(env, arg_logLevel);
                        if(NULL == _updateSystemLog->property_logLevel)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for logLevel");
                            return AXIS2_FAILURE;
                        }
                        _updateSystemLog->is_valid_logLevel = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for logLevel
            */
           axis2_status_t AXIS2_CALL
           adb_updateSystemLog_reset_logLevel(
                   adb_updateSystemLog_t* _updateSystemLog,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _updateSystemLog, AXIS2_FAILURE);
               

               
            
                
                if(_updateSystemLog->property_logLevel != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _updateSystemLog->property_logLevel);
                     _updateSystemLog->property_logLevel = NULL;
                }
            
                
                
                _updateSystemLog->is_valid_logLevel = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether logLevel is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_updateSystemLog_is_logLevel_nil(
                   adb_updateSystemLog_t* _updateSystemLog,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _updateSystemLog, AXIS2_TRUE);
               
               return !_updateSystemLog->is_valid_logLevel;
           }

           /**
            * Set logLevel to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_updateSystemLog_set_logLevel_nil(
                   adb_updateSystemLog_t* _updateSystemLog,
                   const axutil_env_t *env)
           {
               return adb_updateSystemLog_reset_logLevel(_updateSystemLog, env);
           }

           

            /**
             * Getter for logPattern by  Property Number 2
             */
            axis2_char_t* AXIS2_CALL
            adb_updateSystemLog_get_property2(
                adb_updateSystemLog_t* _updateSystemLog,
                const axutil_env_t *env)
            {
                return adb_updateSystemLog_get_logPattern(_updateSystemLog,
                                             env);
            }

            /**
             * getter for logPattern.
             */
            axis2_char_t* AXIS2_CALL
            adb_updateSystemLog_get_logPattern(
                    adb_updateSystemLog_t* _updateSystemLog,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _updateSystemLog, NULL);
                  

                return _updateSystemLog->property_logPattern;
             }

            /**
             * setter for logPattern
             */
            axis2_status_t AXIS2_CALL
            adb_updateSystemLog_set_logPattern(
                    adb_updateSystemLog_t* _updateSystemLog,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_logPattern)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _updateSystemLog, AXIS2_FAILURE);
                
                if(_updateSystemLog->is_valid_logPattern &&
                        arg_logPattern == _updateSystemLog->property_logPattern)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_updateSystemLog_reset_logPattern(_updateSystemLog, env);

                
                if(NULL == arg_logPattern)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _updateSystemLog->property_logPattern = (axis2_char_t *)axutil_strdup(env, arg_logPattern);
                        if(NULL == _updateSystemLog->property_logPattern)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for logPattern");
                            return AXIS2_FAILURE;
                        }
                        _updateSystemLog->is_valid_logPattern = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for logPattern
            */
           axis2_status_t AXIS2_CALL
           adb_updateSystemLog_reset_logPattern(
                   adb_updateSystemLog_t* _updateSystemLog,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _updateSystemLog, AXIS2_FAILURE);
               

               
            
                
                if(_updateSystemLog->property_logPattern != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _updateSystemLog->property_logPattern);
                     _updateSystemLog->property_logPattern = NULL;
                }
            
                
                
                _updateSystemLog->is_valid_logPattern = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether logPattern is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_updateSystemLog_is_logPattern_nil(
                   adb_updateSystemLog_t* _updateSystemLog,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _updateSystemLog, AXIS2_TRUE);
               
               return !_updateSystemLog->is_valid_logPattern;
           }

           /**
            * Set logPattern to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_updateSystemLog_set_logPattern_nil(
                   adb_updateSystemLog_t* _updateSystemLog,
                   const axutil_env_t *env)
           {
               return adb_updateSystemLog_reset_logPattern(_updateSystemLog, env);
           }

           

            /**
             * Getter for persist by  Property Number 3
             */
            axis2_bool_t AXIS2_CALL
            adb_updateSystemLog_get_property3(
                adb_updateSystemLog_t* _updateSystemLog,
                const axutil_env_t *env)
            {
                return adb_updateSystemLog_get_persist(_updateSystemLog,
                                             env);
            }

            /**
             * getter for persist.
             */
            axis2_bool_t AXIS2_CALL
            adb_updateSystemLog_get_persist(
                    adb_updateSystemLog_t* _updateSystemLog,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _updateSystemLog, (axis2_bool_t)0);
                  

                return _updateSystemLog->property_persist;
             }

            /**
             * setter for persist
             */
            axis2_status_t AXIS2_CALL
            adb_updateSystemLog_set_persist(
                    adb_updateSystemLog_t* _updateSystemLog,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_persist)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _updateSystemLog, AXIS2_FAILURE);
                
                if(_updateSystemLog->is_valid_persist &&
                        arg_persist == _updateSystemLog->property_persist)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_updateSystemLog_reset_persist(_updateSystemLog, env);

                _updateSystemLog->property_persist = arg_persist;
                        _updateSystemLog->is_valid_persist = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for persist
            */
           axis2_status_t AXIS2_CALL
           adb_updateSystemLog_reset_persist(
                   adb_updateSystemLog_t* _updateSystemLog,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _updateSystemLog, AXIS2_FAILURE);
               

               _updateSystemLog->is_valid_persist = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether persist is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_updateSystemLog_is_persist_nil(
                   adb_updateSystemLog_t* _updateSystemLog,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _updateSystemLog, AXIS2_TRUE);
               
               return !_updateSystemLog->is_valid_persist;
           }

           /**
            * Set persist to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_updateSystemLog_set_persist_nil(
                   adb_updateSystemLog_t* _updateSystemLog,
                   const axutil_env_t *env)
           {
               return adb_updateSystemLog_reset_persist(_updateSystemLog, env);
           }

           

