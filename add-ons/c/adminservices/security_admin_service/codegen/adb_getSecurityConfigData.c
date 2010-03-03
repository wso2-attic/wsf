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
         * adb_getSecurityConfigData.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_getSecurityConfigData.h"
        
               /*
                * implmentation of the getSecurityConfigData|http://service.config.security.carbon.wso2.org element
                */
           


        struct adb_getSecurityConfigData
        {
            axis2_char_t *property_Type;

            
                axutil_qname_t* qname;
            axis2_char_t* property_serviceName;

                
                axis2_bool_t is_valid_serviceName;
            axis2_char_t* property_scenarioId;

                
                axis2_bool_t is_valid_scenarioId;
            
        };


       /************************* Private Function prototypes ********************************/
        


       /************************* Function Implmentations ********************************/
        adb_getSecurityConfigData_t* AXIS2_CALL
        adb_getSecurityConfigData_create(
            const axutil_env_t *env)
        {
            adb_getSecurityConfigData_t *_getSecurityConfigData = NULL;
            
                axutil_qname_t* qname = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _getSecurityConfigData = (adb_getSecurityConfigData_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_getSecurityConfigData_t));

            if(NULL == _getSecurityConfigData)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_getSecurityConfigData, 0, sizeof(adb_getSecurityConfigData_t));

            _getSecurityConfigData->property_Type = axutil_strdup(env, "adb_getSecurityConfigData");
            _getSecurityConfigData->property_serviceName  = NULL;
                  _getSecurityConfigData->is_valid_serviceName  = AXIS2_FALSE;
            _getSecurityConfigData->property_scenarioId  = NULL;
                  _getSecurityConfigData->is_valid_scenarioId  = AXIS2_FALSE;
            
                  qname =  axutil_qname_create (env,
                        "getSecurityConfigData",
                        "http://service.config.security.carbon.wso2.org",
                        NULL);
                _getSecurityConfigData->qname = qname;
            

            return _getSecurityConfigData;
        }

        adb_getSecurityConfigData_t* AXIS2_CALL
        adb_getSecurityConfigData_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _serviceName,
                axis2_char_t* _scenarioId)
        {
            adb_getSecurityConfigData_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_getSecurityConfigData_create(env);

            
              status = adb_getSecurityConfigData_set_serviceName(
                                     adb_obj,
                                     env,
                                     _serviceName);
              if(status == AXIS2_FAILURE) {
                  adb_getSecurityConfigData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_getSecurityConfigData_set_scenarioId(
                                     adb_obj,
                                     env,
                                     _scenarioId);
              if(status == AXIS2_FAILURE) {
                  adb_getSecurityConfigData_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_char_t* AXIS2_CALL
                adb_getSecurityConfigData_free_popping_value(
                        adb_getSecurityConfigData_t* _getSecurityConfigData,
                        const axutil_env_t *env)
                {
                    axis2_char_t* value;

                    
                    
                    value = _getSecurityConfigData->property_serviceName;

                    _getSecurityConfigData->property_serviceName = (axis2_char_t*)NULL;
                    adb_getSecurityConfigData_free(_getSecurityConfigData, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_getSecurityConfigData_free(
                adb_getSecurityConfigData_t* _getSecurityConfigData,
                const axutil_env_t *env)
        {
            
            
            return adb_getSecurityConfigData_free_obj(
                _getSecurityConfigData,
                env);
            
        }

        axis2_status_t AXIS2_CALL
        adb_getSecurityConfigData_free_obj(
                adb_getSecurityConfigData_t* _getSecurityConfigData,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _getSecurityConfigData, AXIS2_FAILURE);

            if (_getSecurityConfigData->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _getSecurityConfigData->property_Type);
            }

            adb_getSecurityConfigData_reset_serviceName(_getSecurityConfigData, env);
            adb_getSecurityConfigData_reset_scenarioId(_getSecurityConfigData, env);
            
              if(_getSecurityConfigData->qname)
              {
                  axutil_qname_free (_getSecurityConfigData->qname, env);
                  _getSecurityConfigData->qname = NULL;
              }
            

            if(_getSecurityConfigData)
            {
                AXIS2_FREE(env->allocator, _getSecurityConfigData);
                _getSecurityConfigData = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_getSecurityConfigData_deserialize(
                adb_getSecurityConfigData_t* _getSecurityConfigData,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return adb_getSecurityConfigData_deserialize_obj(
                _getSecurityConfigData,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs);
            
        }

        axis2_status_t AXIS2_CALL
        adb_getSecurityConfigData_deserialize_obj(
                adb_getSecurityConfigData_t* _getSecurityConfigData,
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
            AXIS2_PARAM_CHECK(env->error, _getSecurityConfigData, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for getSecurityConfigData : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              

                    current_element = (axiom_element_t *)axiom_node_get_data_element(parent, env);
                    qname = axiom_element_get_qname(current_element, env, parent);
                    if (axutil_qname_equals(qname, env, _getSecurityConfigData-> qname))
                    {
                        
                          first_node = axiom_node_get_first_child(parent, env);
                          
                    }
                    else
                    {
                        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                              "Failed in building adb object for getSecurityConfigData : "
                              "Expected %s but returned %s",
                              axutil_qname_to_string(_getSecurityConfigData-> qname, env),
                              axutil_qname_to_string(qname, env));
                        
                        return AXIS2_FAILURE;
                    }
                    

                     
                     /*
                      * building serviceName element
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
                                   
                                 element_qname = axutil_qname_create(env, "serviceName", "http://service.config.security.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_getSecurityConfigData_set_serviceName(_getSecurityConfigData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for serviceName ");
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
                      * building scenarioId element
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
                                 
                                 element_qname = axutil_qname_create(env, "scenarioId", "http://service.config.security.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_getSecurityConfigData_set_scenarioId(_getSecurityConfigData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for scenarioId ");
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
          adb_getSecurityConfigData_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_getSecurityConfigData_declare_parent_namespaces(
                    adb_getSecurityConfigData_t* _getSecurityConfigData,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_getSecurityConfigData_serialize(
                adb_getSecurityConfigData_t* _getSecurityConfigData,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
                return adb_getSecurityConfigData_serialize_obj(
                    _getSecurityConfigData, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            
        }

        axiom_node_t* AXIS2_CALL
        adb_getSecurityConfigData_serialize_obj(
                adb_getSecurityConfigData_t* _getSecurityConfigData,
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
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

             
                int next_ns_index_value = 0;
            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _getSecurityConfigData, NULL);
            
             
                    namespaces = axutil_hash_make(env);
                    next_ns_index = &next_ns_index_value;
                     
                           ns1 = axiom_namespace_create (env,
                                             "http://service.config.security.carbon.wso2.org",
                                             "n"); 
                           axutil_hash_set(namespaces, "http://service.config.security.carbon.wso2.org", AXIS2_HASH_KEY_STRING, axutil_strdup(env, "n"));
                       
                     
                    parent_element = axiom_element_create (env, NULL, "getSecurityConfigData", ns1 , &parent);
                    
                    
                    axiom_element_set_namespace(parent_element, env, ns1, parent);


            
                    data_source = axiom_data_source_create(env, parent, &current_node);
                    stream = axiom_data_source_get_stream(data_source, env);
                  
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.config.security.carbon.wso2.org", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.config.security.carbon.wso2.org", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.config.security.carbon.wso2.org",
                                            p_prefix));
                       }
                      

                   if (!_getSecurityConfigData->is_valid_serviceName)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("serviceName"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("serviceName")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing serviceName element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sserviceName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sserviceName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_1 = _getSecurityConfigData->property_serviceName;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.config.security.carbon.wso2.org", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.config.security.carbon.wso2.org", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.config.security.carbon.wso2.org",
                                            p_prefix));
                       }
                      

                   if (!_getSecurityConfigData->is_valid_scenarioId)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("scenarioId"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("scenarioId")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing scenarioId element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sscenarioId>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sscenarioId>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_2 = _getSecurityConfigData->property_scenarioId;
                           
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
             * Getter for serviceName by  Property Number 1
             */
            axis2_char_t* AXIS2_CALL
            adb_getSecurityConfigData_get_property1(
                adb_getSecurityConfigData_t* _getSecurityConfigData,
                const axutil_env_t *env)
            {
                return adb_getSecurityConfigData_get_serviceName(_getSecurityConfigData,
                                             env);
            }

            /**
             * getter for serviceName.
             */
            axis2_char_t* AXIS2_CALL
            adb_getSecurityConfigData_get_serviceName(
                    adb_getSecurityConfigData_t* _getSecurityConfigData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _getSecurityConfigData, NULL);
                  

                return _getSecurityConfigData->property_serviceName;
             }

            /**
             * setter for serviceName
             */
            axis2_status_t AXIS2_CALL
            adb_getSecurityConfigData_set_serviceName(
                    adb_getSecurityConfigData_t* _getSecurityConfigData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_serviceName)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _getSecurityConfigData, AXIS2_FAILURE);
                
                if(_getSecurityConfigData->is_valid_serviceName &&
                        arg_serviceName == _getSecurityConfigData->property_serviceName)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_getSecurityConfigData_reset_serviceName(_getSecurityConfigData, env);

                
                if(NULL == arg_serviceName)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _getSecurityConfigData->property_serviceName = (axis2_char_t *)axutil_strdup(env, arg_serviceName);
                        if(NULL == _getSecurityConfigData->property_serviceName)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for serviceName");
                            return AXIS2_FAILURE;
                        }
                        _getSecurityConfigData->is_valid_serviceName = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for serviceName
            */
           axis2_status_t AXIS2_CALL
           adb_getSecurityConfigData_reset_serviceName(
                   adb_getSecurityConfigData_t* _getSecurityConfigData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _getSecurityConfigData, AXIS2_FAILURE);
               

               
            
                
                if(_getSecurityConfigData->property_serviceName != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _getSecurityConfigData->property_serviceName);
                     _getSecurityConfigData->property_serviceName = NULL;
                }
            
                
                
                _getSecurityConfigData->is_valid_serviceName = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether serviceName is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_getSecurityConfigData_is_serviceName_nil(
                   adb_getSecurityConfigData_t* _getSecurityConfigData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _getSecurityConfigData, AXIS2_TRUE);
               
               return !_getSecurityConfigData->is_valid_serviceName;
           }

           /**
            * Set serviceName to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_getSecurityConfigData_set_serviceName_nil(
                   adb_getSecurityConfigData_t* _getSecurityConfigData,
                   const axutil_env_t *env)
           {
               return adb_getSecurityConfigData_reset_serviceName(_getSecurityConfigData, env);
           }

           

            /**
             * Getter for scenarioId by  Property Number 2
             */
            axis2_char_t* AXIS2_CALL
            adb_getSecurityConfigData_get_property2(
                adb_getSecurityConfigData_t* _getSecurityConfigData,
                const axutil_env_t *env)
            {
                return adb_getSecurityConfigData_get_scenarioId(_getSecurityConfigData,
                                             env);
            }

            /**
             * getter for scenarioId.
             */
            axis2_char_t* AXIS2_CALL
            adb_getSecurityConfigData_get_scenarioId(
                    adb_getSecurityConfigData_t* _getSecurityConfigData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _getSecurityConfigData, NULL);
                  

                return _getSecurityConfigData->property_scenarioId;
             }

            /**
             * setter for scenarioId
             */
            axis2_status_t AXIS2_CALL
            adb_getSecurityConfigData_set_scenarioId(
                    adb_getSecurityConfigData_t* _getSecurityConfigData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_scenarioId)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _getSecurityConfigData, AXIS2_FAILURE);
                
                if(_getSecurityConfigData->is_valid_scenarioId &&
                        arg_scenarioId == _getSecurityConfigData->property_scenarioId)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_getSecurityConfigData_reset_scenarioId(_getSecurityConfigData, env);

                
                if(NULL == arg_scenarioId)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _getSecurityConfigData->property_scenarioId = (axis2_char_t *)axutil_strdup(env, arg_scenarioId);
                        if(NULL == _getSecurityConfigData->property_scenarioId)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for scenarioId");
                            return AXIS2_FAILURE;
                        }
                        _getSecurityConfigData->is_valid_scenarioId = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for scenarioId
            */
           axis2_status_t AXIS2_CALL
           adb_getSecurityConfigData_reset_scenarioId(
                   adb_getSecurityConfigData_t* _getSecurityConfigData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _getSecurityConfigData, AXIS2_FAILURE);
               

               
            
                
                if(_getSecurityConfigData->property_scenarioId != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _getSecurityConfigData->property_scenarioId);
                     _getSecurityConfigData->property_scenarioId = NULL;
                }
            
                
                
                _getSecurityConfigData->is_valid_scenarioId = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether scenarioId is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_getSecurityConfigData_is_scenarioId_nil(
                   adb_getSecurityConfigData_t* _getSecurityConfigData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _getSecurityConfigData, AXIS2_TRUE);
               
               return !_getSecurityConfigData->is_valid_scenarioId;
           }

           /**
            * Set scenarioId to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_getSecurityConfigData_set_scenarioId_nil(
                   adb_getSecurityConfigData_t* _getSecurityConfigData,
                   const axutil_env_t *env)
           {
               return adb_getSecurityConfigData_reset_scenarioId(_getSecurityConfigData, env);
           }

           

