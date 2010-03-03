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
         * adb_updateLoggerData.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_updateLoggerData.h"
        
               /*
                * implmentation of the updateLoggerData|http://org.apache.axis2/xsd element
                */
           


        struct adb_updateLoggerData
        {
            axis2_char_t *property_Type;

            
                axutil_qname_t* qname;
            axis2_char_t* property_loggerName;

                
                axis2_bool_t is_valid_loggerName;
            axis2_char_t* property_loggerLevel;

                
                axis2_bool_t is_valid_loggerLevel;
            axis2_bool_t property_additivity;

                
                axis2_bool_t is_valid_additivity;
            axis2_bool_t property_persist;

                
                axis2_bool_t is_valid_persist;
            
        };


       /************************* Private Function prototypes ********************************/
        

                axis2_status_t AXIS2_CALL
                adb_updateLoggerData_set_additivity_nil(
                        adb_updateLoggerData_t* _updateLoggerData,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_updateLoggerData_set_persist_nil(
                        adb_updateLoggerData_t* _updateLoggerData,
                        const axutil_env_t *env);
            


       /************************* Function Implmentations ********************************/
        adb_updateLoggerData_t* AXIS2_CALL
        adb_updateLoggerData_create(
            const axutil_env_t *env)
        {
            adb_updateLoggerData_t *_updateLoggerData = NULL;
            
                axutil_qname_t* qname = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _updateLoggerData = (adb_updateLoggerData_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_updateLoggerData_t));

            if(NULL == _updateLoggerData)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_updateLoggerData, 0, sizeof(adb_updateLoggerData_t));

            _updateLoggerData->property_Type = axutil_strdup(env, "adb_updateLoggerData");
            _updateLoggerData->property_loggerName  = NULL;
                  _updateLoggerData->is_valid_loggerName  = AXIS2_FALSE;
            _updateLoggerData->property_loggerLevel  = NULL;
                  _updateLoggerData->is_valid_loggerLevel  = AXIS2_FALSE;
            _updateLoggerData->is_valid_additivity  = AXIS2_FALSE;
            _updateLoggerData->is_valid_persist  = AXIS2_FALSE;
            
                  qname =  axutil_qname_create (env,
                        "updateLoggerData",
                        "http://org.apache.axis2/xsd",
                        NULL);
                _updateLoggerData->qname = qname;
            

            return _updateLoggerData;
        }

        adb_updateLoggerData_t* AXIS2_CALL
        adb_updateLoggerData_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _loggerName,
                axis2_char_t* _loggerLevel,
                axis2_bool_t _additivity,
                axis2_bool_t _persist)
        {
            adb_updateLoggerData_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_updateLoggerData_create(env);

            
              status = adb_updateLoggerData_set_loggerName(
                                     adb_obj,
                                     env,
                                     _loggerName);
              if(status == AXIS2_FAILURE) {
                  adb_updateLoggerData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_updateLoggerData_set_loggerLevel(
                                     adb_obj,
                                     env,
                                     _loggerLevel);
              if(status == AXIS2_FAILURE) {
                  adb_updateLoggerData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_updateLoggerData_set_additivity(
                                     adb_obj,
                                     env,
                                     _additivity);
              if(status == AXIS2_FAILURE) {
                  adb_updateLoggerData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_updateLoggerData_set_persist(
                                     adb_obj,
                                     env,
                                     _persist);
              if(status == AXIS2_FAILURE) {
                  adb_updateLoggerData_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_char_t* AXIS2_CALL
                adb_updateLoggerData_free_popping_value(
                        adb_updateLoggerData_t* _updateLoggerData,
                        const axutil_env_t *env)
                {
                    axis2_char_t* value;

                    
                    
                    value = _updateLoggerData->property_loggerName;

                    _updateLoggerData->property_loggerName = (axis2_char_t*)NULL;
                    adb_updateLoggerData_free(_updateLoggerData, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_updateLoggerData_free(
                adb_updateLoggerData_t* _updateLoggerData,
                const axutil_env_t *env)
        {
            
            
            return adb_updateLoggerData_free_obj(
                _updateLoggerData,
                env);
            
        }

        axis2_status_t AXIS2_CALL
        adb_updateLoggerData_free_obj(
                adb_updateLoggerData_t* _updateLoggerData,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _updateLoggerData, AXIS2_FAILURE);

            if (_updateLoggerData->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _updateLoggerData->property_Type);
            }

            adb_updateLoggerData_reset_loggerName(_updateLoggerData, env);
            adb_updateLoggerData_reset_loggerLevel(_updateLoggerData, env);
            adb_updateLoggerData_reset_additivity(_updateLoggerData, env);
            adb_updateLoggerData_reset_persist(_updateLoggerData, env);
            
              if(_updateLoggerData->qname)
              {
                  axutil_qname_free (_updateLoggerData->qname, env);
                  _updateLoggerData->qname = NULL;
              }
            

            if(_updateLoggerData)
            {
                AXIS2_FREE(env->allocator, _updateLoggerData);
                _updateLoggerData = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_updateLoggerData_deserialize(
                adb_updateLoggerData_t* _updateLoggerData,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return adb_updateLoggerData_deserialize_obj(
                _updateLoggerData,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs);
            
        }

        axis2_status_t AXIS2_CALL
        adb_updateLoggerData_deserialize_obj(
                adb_updateLoggerData_t* _updateLoggerData,
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
            AXIS2_PARAM_CHECK(env->error, _updateLoggerData, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for updateLoggerData : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              

                    current_element = (axiom_element_t *)axiom_node_get_data_element(parent, env);
                    qname = axiom_element_get_qname(current_element, env, parent);
                    if (axutil_qname_equals(qname, env, _updateLoggerData-> qname))
                    {
                        
                          first_node = axiom_node_get_first_child(parent, env);
                          
                    }
                    else
                    {
                        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                              "Failed in building adb object for updateLoggerData : "
                              "Expected %s but returned %s",
                              axutil_qname_to_string(_updateLoggerData-> qname, env),
                              axutil_qname_to_string(qname, env));
                        
                        return AXIS2_FAILURE;
                    }
                    

                     
                     /*
                      * building loggerName element
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
                                   
                                 element_qname = axutil_qname_create(env, "loggerName", "http://org.apache.axis2/xsd", NULL);
                                 

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
                                            status = adb_updateLoggerData_set_loggerName(_updateLoggerData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for loggerName ");
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
                      * building loggerLevel element
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
                                 
                                 element_qname = axutil_qname_create(env, "loggerLevel", "http://org.apache.axis2/xsd", NULL);
                                 

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
                                            status = adb_updateLoggerData_set_loggerLevel(_updateLoggerData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for loggerLevel ");
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
                      * building additivity element
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
                                 
                                 element_qname = axutil_qname_create(env, "additivity", "http://org.apache.axis2/xsd", NULL);
                                 

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
                                                status = adb_updateLoggerData_set_additivity(_updateLoggerData, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_updateLoggerData_set_additivity(_updateLoggerData, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element additivity");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for additivity ");
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
                                                status = adb_updateLoggerData_set_persist(_updateLoggerData, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_updateLoggerData_set_persist(_updateLoggerData, env,
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
          adb_updateLoggerData_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_updateLoggerData_declare_parent_namespaces(
                    adb_updateLoggerData_t* _updateLoggerData,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_updateLoggerData_serialize(
                adb_updateLoggerData_t* _updateLoggerData,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
                return adb_updateLoggerData_serialize_obj(
                    _updateLoggerData, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            
        }

        axiom_node_t* AXIS2_CALL
        adb_updateLoggerData_serialize_obj(
                adb_updateLoggerData_t* _updateLoggerData,
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
                    
                    axis2_char_t text_value_4[ADB_DEFAULT_DIGIT_LIMIT];
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

             
                int next_ns_index_value = 0;
            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _updateLoggerData, NULL);
            
             
                    namespaces = axutil_hash_make(env);
                    next_ns_index = &next_ns_index_value;
                     
                           ns1 = axiom_namespace_create (env,
                                             "http://org.apache.axis2/xsd",
                                             "n"); 
                           axutil_hash_set(namespaces, "http://org.apache.axis2/xsd", AXIS2_HASH_KEY_STRING, axutil_strdup(env, "n"));
                       
                     
                    parent_element = axiom_element_create (env, NULL, "updateLoggerData", ns1 , &parent);
                    
                    
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
                      

                   if (!_updateLoggerData->is_valid_loggerName)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("loggerName"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("loggerName")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing loggerName element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sloggerName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sloggerName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_1 = _updateLoggerData->property_loggerName;
                           
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
                      

                   if (!_updateLoggerData->is_valid_loggerLevel)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("loggerLevel"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("loggerLevel")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing loggerLevel element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sloggerLevel>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sloggerLevel>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_2 = _updateLoggerData->property_loggerLevel;
                           
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
                      

                   if (!_updateLoggerData->is_valid_additivity)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("additivity"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("additivity")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing additivity element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sadditivity>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sadditivity>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_3, (_updateLoggerData->property_additivity)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_3, axutil_strlen(text_value_3));
                           
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
                      

                   if (!_updateLoggerData->is_valid_persist)
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
                    
                           strcpy(text_value_4, (_updateLoggerData->property_persist)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_4, axutil_strlen(text_value_4));
                           
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
             * Getter for loggerName by  Property Number 1
             */
            axis2_char_t* AXIS2_CALL
            adb_updateLoggerData_get_property1(
                adb_updateLoggerData_t* _updateLoggerData,
                const axutil_env_t *env)
            {
                return adb_updateLoggerData_get_loggerName(_updateLoggerData,
                                             env);
            }

            /**
             * getter for loggerName.
             */
            axis2_char_t* AXIS2_CALL
            adb_updateLoggerData_get_loggerName(
                    adb_updateLoggerData_t* _updateLoggerData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _updateLoggerData, NULL);
                  

                return _updateLoggerData->property_loggerName;
             }

            /**
             * setter for loggerName
             */
            axis2_status_t AXIS2_CALL
            adb_updateLoggerData_set_loggerName(
                    adb_updateLoggerData_t* _updateLoggerData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_loggerName)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _updateLoggerData, AXIS2_FAILURE);
                
                if(_updateLoggerData->is_valid_loggerName &&
                        arg_loggerName == _updateLoggerData->property_loggerName)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_updateLoggerData_reset_loggerName(_updateLoggerData, env);

                
                if(NULL == arg_loggerName)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _updateLoggerData->property_loggerName = (axis2_char_t *)axutil_strdup(env, arg_loggerName);
                        if(NULL == _updateLoggerData->property_loggerName)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for loggerName");
                            return AXIS2_FAILURE;
                        }
                        _updateLoggerData->is_valid_loggerName = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for loggerName
            */
           axis2_status_t AXIS2_CALL
           adb_updateLoggerData_reset_loggerName(
                   adb_updateLoggerData_t* _updateLoggerData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _updateLoggerData, AXIS2_FAILURE);
               

               
            
                
                if(_updateLoggerData->property_loggerName != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _updateLoggerData->property_loggerName);
                     _updateLoggerData->property_loggerName = NULL;
                }
            
                
                
                _updateLoggerData->is_valid_loggerName = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether loggerName is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_updateLoggerData_is_loggerName_nil(
                   adb_updateLoggerData_t* _updateLoggerData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _updateLoggerData, AXIS2_TRUE);
               
               return !_updateLoggerData->is_valid_loggerName;
           }

           /**
            * Set loggerName to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_updateLoggerData_set_loggerName_nil(
                   adb_updateLoggerData_t* _updateLoggerData,
                   const axutil_env_t *env)
           {
               return adb_updateLoggerData_reset_loggerName(_updateLoggerData, env);
           }

           

            /**
             * Getter for loggerLevel by  Property Number 2
             */
            axis2_char_t* AXIS2_CALL
            adb_updateLoggerData_get_property2(
                adb_updateLoggerData_t* _updateLoggerData,
                const axutil_env_t *env)
            {
                return adb_updateLoggerData_get_loggerLevel(_updateLoggerData,
                                             env);
            }

            /**
             * getter for loggerLevel.
             */
            axis2_char_t* AXIS2_CALL
            adb_updateLoggerData_get_loggerLevel(
                    adb_updateLoggerData_t* _updateLoggerData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _updateLoggerData, NULL);
                  

                return _updateLoggerData->property_loggerLevel;
             }

            /**
             * setter for loggerLevel
             */
            axis2_status_t AXIS2_CALL
            adb_updateLoggerData_set_loggerLevel(
                    adb_updateLoggerData_t* _updateLoggerData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_loggerLevel)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _updateLoggerData, AXIS2_FAILURE);
                
                if(_updateLoggerData->is_valid_loggerLevel &&
                        arg_loggerLevel == _updateLoggerData->property_loggerLevel)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_updateLoggerData_reset_loggerLevel(_updateLoggerData, env);

                
                if(NULL == arg_loggerLevel)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _updateLoggerData->property_loggerLevel = (axis2_char_t *)axutil_strdup(env, arg_loggerLevel);
                        if(NULL == _updateLoggerData->property_loggerLevel)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for loggerLevel");
                            return AXIS2_FAILURE;
                        }
                        _updateLoggerData->is_valid_loggerLevel = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for loggerLevel
            */
           axis2_status_t AXIS2_CALL
           adb_updateLoggerData_reset_loggerLevel(
                   adb_updateLoggerData_t* _updateLoggerData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _updateLoggerData, AXIS2_FAILURE);
               

               
            
                
                if(_updateLoggerData->property_loggerLevel != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _updateLoggerData->property_loggerLevel);
                     _updateLoggerData->property_loggerLevel = NULL;
                }
            
                
                
                _updateLoggerData->is_valid_loggerLevel = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether loggerLevel is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_updateLoggerData_is_loggerLevel_nil(
                   adb_updateLoggerData_t* _updateLoggerData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _updateLoggerData, AXIS2_TRUE);
               
               return !_updateLoggerData->is_valid_loggerLevel;
           }

           /**
            * Set loggerLevel to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_updateLoggerData_set_loggerLevel_nil(
                   adb_updateLoggerData_t* _updateLoggerData,
                   const axutil_env_t *env)
           {
               return adb_updateLoggerData_reset_loggerLevel(_updateLoggerData, env);
           }

           

            /**
             * Getter for additivity by  Property Number 3
             */
            axis2_bool_t AXIS2_CALL
            adb_updateLoggerData_get_property3(
                adb_updateLoggerData_t* _updateLoggerData,
                const axutil_env_t *env)
            {
                return adb_updateLoggerData_get_additivity(_updateLoggerData,
                                             env);
            }

            /**
             * getter for additivity.
             */
            axis2_bool_t AXIS2_CALL
            adb_updateLoggerData_get_additivity(
                    adb_updateLoggerData_t* _updateLoggerData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _updateLoggerData, (axis2_bool_t)0);
                  

                return _updateLoggerData->property_additivity;
             }

            /**
             * setter for additivity
             */
            axis2_status_t AXIS2_CALL
            adb_updateLoggerData_set_additivity(
                    adb_updateLoggerData_t* _updateLoggerData,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_additivity)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _updateLoggerData, AXIS2_FAILURE);
                
                if(_updateLoggerData->is_valid_additivity &&
                        arg_additivity == _updateLoggerData->property_additivity)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_updateLoggerData_reset_additivity(_updateLoggerData, env);

                _updateLoggerData->property_additivity = arg_additivity;
                        _updateLoggerData->is_valid_additivity = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for additivity
            */
           axis2_status_t AXIS2_CALL
           adb_updateLoggerData_reset_additivity(
                   adb_updateLoggerData_t* _updateLoggerData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _updateLoggerData, AXIS2_FAILURE);
               

               _updateLoggerData->is_valid_additivity = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether additivity is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_updateLoggerData_is_additivity_nil(
                   adb_updateLoggerData_t* _updateLoggerData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _updateLoggerData, AXIS2_TRUE);
               
               return !_updateLoggerData->is_valid_additivity;
           }

           /**
            * Set additivity to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_updateLoggerData_set_additivity_nil(
                   adb_updateLoggerData_t* _updateLoggerData,
                   const axutil_env_t *env)
           {
               return adb_updateLoggerData_reset_additivity(_updateLoggerData, env);
           }

           

            /**
             * Getter for persist by  Property Number 4
             */
            axis2_bool_t AXIS2_CALL
            adb_updateLoggerData_get_property4(
                adb_updateLoggerData_t* _updateLoggerData,
                const axutil_env_t *env)
            {
                return adb_updateLoggerData_get_persist(_updateLoggerData,
                                             env);
            }

            /**
             * getter for persist.
             */
            axis2_bool_t AXIS2_CALL
            adb_updateLoggerData_get_persist(
                    adb_updateLoggerData_t* _updateLoggerData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _updateLoggerData, (axis2_bool_t)0);
                  

                return _updateLoggerData->property_persist;
             }

            /**
             * setter for persist
             */
            axis2_status_t AXIS2_CALL
            adb_updateLoggerData_set_persist(
                    adb_updateLoggerData_t* _updateLoggerData,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_persist)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _updateLoggerData, AXIS2_FAILURE);
                
                if(_updateLoggerData->is_valid_persist &&
                        arg_persist == _updateLoggerData->property_persist)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_updateLoggerData_reset_persist(_updateLoggerData, env);

                _updateLoggerData->property_persist = arg_persist;
                        _updateLoggerData->is_valid_persist = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for persist
            */
           axis2_status_t AXIS2_CALL
           adb_updateLoggerData_reset_persist(
                   adb_updateLoggerData_t* _updateLoggerData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _updateLoggerData, AXIS2_FAILURE);
               

               _updateLoggerData->is_valid_persist = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether persist is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_updateLoggerData_is_persist_nil(
                   adb_updateLoggerData_t* _updateLoggerData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _updateLoggerData, AXIS2_TRUE);
               
               return !_updateLoggerData->is_valid_persist;
           }

           /**
            * Set persist to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_updateLoggerData_set_persist_nil(
                   adb_updateLoggerData_t* _updateLoggerData,
                   const axutil_env_t *env)
           {
               return adb_updateLoggerData_reset_persist(_updateLoggerData, env);
           }

           

