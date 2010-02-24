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
         * adb_getAllLoggerData.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_getAllLoggerData.h"
        
               /*
                * implmentation of the getAllLoggerData|http://org.apache.axis2/xsd element
                */
           


        struct adb_getAllLoggerData
        {
            axis2_char_t *property_Type;

            
                axutil_qname_t* qname;
            axis2_char_t* property_logNameFilter;

                
                axis2_bool_t is_valid_logNameFilter;
            axis2_bool_t property_beginsWith;

                
                axis2_bool_t is_valid_beginsWith;
            
        };


       /************************* Private Function prototypes ********************************/
        

                axis2_status_t AXIS2_CALL
                adb_getAllLoggerData_set_beginsWith_nil(
                        adb_getAllLoggerData_t* _getAllLoggerData,
                        const axutil_env_t *env);
            


       /************************* Function Implmentations ********************************/
        adb_getAllLoggerData_t* AXIS2_CALL
        adb_getAllLoggerData_create(
            const axutil_env_t *env)
        {
            adb_getAllLoggerData_t *_getAllLoggerData = NULL;
            
                axutil_qname_t* qname = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _getAllLoggerData = (adb_getAllLoggerData_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_getAllLoggerData_t));

            if(NULL == _getAllLoggerData)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_getAllLoggerData, 0, sizeof(adb_getAllLoggerData_t));

            _getAllLoggerData->property_Type = axutil_strdup(env, "adb_getAllLoggerData");
            _getAllLoggerData->property_logNameFilter  = NULL;
                  _getAllLoggerData->is_valid_logNameFilter  = AXIS2_FALSE;
            _getAllLoggerData->is_valid_beginsWith  = AXIS2_FALSE;
            
                  qname =  axutil_qname_create (env,
                        "getAllLoggerData",
                        "http://org.apache.axis2/xsd",
                        NULL);
                _getAllLoggerData->qname = qname;
            

            return _getAllLoggerData;
        }

        adb_getAllLoggerData_t* AXIS2_CALL
        adb_getAllLoggerData_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _logNameFilter,
                axis2_bool_t _beginsWith)
        {
            adb_getAllLoggerData_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_getAllLoggerData_create(env);

            
              status = adb_getAllLoggerData_set_logNameFilter(
                                     adb_obj,
                                     env,
                                     _logNameFilter);
              if(status == AXIS2_FAILURE) {
                  adb_getAllLoggerData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_getAllLoggerData_set_beginsWith(
                                     adb_obj,
                                     env,
                                     _beginsWith);
              if(status == AXIS2_FAILURE) {
                  adb_getAllLoggerData_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_char_t* AXIS2_CALL
                adb_getAllLoggerData_free_popping_value(
                        adb_getAllLoggerData_t* _getAllLoggerData,
                        const axutil_env_t *env)
                {
                    axis2_char_t* value;

                    
                    
                    value = _getAllLoggerData->property_logNameFilter;

                    _getAllLoggerData->property_logNameFilter = (axis2_char_t*)NULL;
                    adb_getAllLoggerData_free(_getAllLoggerData, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_getAllLoggerData_free(
                adb_getAllLoggerData_t* _getAllLoggerData,
                const axutil_env_t *env)
        {
            
            
            return adb_getAllLoggerData_free_obj(
                _getAllLoggerData,
                env);
            
        }

        axis2_status_t AXIS2_CALL
        adb_getAllLoggerData_free_obj(
                adb_getAllLoggerData_t* _getAllLoggerData,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _getAllLoggerData, AXIS2_FAILURE);

            if (_getAllLoggerData->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _getAllLoggerData->property_Type);
            }

            adb_getAllLoggerData_reset_logNameFilter(_getAllLoggerData, env);
            adb_getAllLoggerData_reset_beginsWith(_getAllLoggerData, env);
            
              if(_getAllLoggerData->qname)
              {
                  axutil_qname_free (_getAllLoggerData->qname, env);
                  _getAllLoggerData->qname = NULL;
              }
            

            if(_getAllLoggerData)
            {
                AXIS2_FREE(env->allocator, _getAllLoggerData);
                _getAllLoggerData = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_getAllLoggerData_deserialize(
                adb_getAllLoggerData_t* _getAllLoggerData,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return adb_getAllLoggerData_deserialize_obj(
                _getAllLoggerData,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs);
            
        }

        axis2_status_t AXIS2_CALL
        adb_getAllLoggerData_deserialize_obj(
                adb_getAllLoggerData_t* _getAllLoggerData,
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
            AXIS2_PARAM_CHECK(env->error, _getAllLoggerData, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for getAllLoggerData : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              

                    current_element = (axiom_element_t *)axiom_node_get_data_element(parent, env);
                    qname = axiom_element_get_qname(current_element, env, parent);
                    if (axutil_qname_equals(qname, env, _getAllLoggerData-> qname))
                    {
                        
                          first_node = axiom_node_get_first_child(parent, env);
                          
                    }
                    else
                    {
                        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                              "Failed in building adb object for getAllLoggerData : "
                              "Expected %s but returned %s",
                              axutil_qname_to_string(_getAllLoggerData-> qname, env),
                              axutil_qname_to_string(qname, env));
                        
                        return AXIS2_FAILURE;
                    }
                    

                     
                     /*
                      * building logNameFilter element
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
                                   
                                 element_qname = axutil_qname_create(env, "logNameFilter", "http://org.apache.axis2/xsd", NULL);
                                 

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
                                            status = adb_getAllLoggerData_set_logNameFilter(_getAllLoggerData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for logNameFilter ");
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
                      * building beginsWith element
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
                                 
                                 element_qname = axutil_qname_create(env, "beginsWith", "http://org.apache.axis2/xsd", NULL);
                                 

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
                                                status = adb_getAllLoggerData_set_beginsWith(_getAllLoggerData, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_getAllLoggerData_set_beginsWith(_getAllLoggerData, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element beginsWith");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for beginsWith ");
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
          adb_getAllLoggerData_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_getAllLoggerData_declare_parent_namespaces(
                    adb_getAllLoggerData_t* _getAllLoggerData,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_getAllLoggerData_serialize(
                adb_getAllLoggerData_t* _getAllLoggerData,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
                return adb_getAllLoggerData_serialize_obj(
                    _getAllLoggerData, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            
        }

        axiom_node_t* AXIS2_CALL
        adb_getAllLoggerData_serialize_obj(
                adb_getAllLoggerData_t* _getAllLoggerData,
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
                    
                    axis2_char_t text_value_2[ADB_DEFAULT_DIGIT_LIMIT];
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

             
                int next_ns_index_value = 0;
            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _getAllLoggerData, NULL);
            
             
                    namespaces = axutil_hash_make(env);
                    next_ns_index = &next_ns_index_value;
                     
                           ns1 = axiom_namespace_create (env,
                                             "http://org.apache.axis2/xsd",
                                             "n"); 
                           axutil_hash_set(namespaces, "http://org.apache.axis2/xsd", AXIS2_HASH_KEY_STRING, axutil_strdup(env, "n"));
                       
                     
                    parent_element = axiom_element_create (env, NULL, "getAllLoggerData", ns1 , &parent);
                    
                    
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
                      

                   if (!_getAllLoggerData->is_valid_logNameFilter)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("logNameFilter"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("logNameFilter")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing logNameFilter element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%slogNameFilter>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%slogNameFilter>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_1 = _getAllLoggerData->property_logNameFilter;
                           
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
                      

                   if (!_getAllLoggerData->is_valid_beginsWith)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("beginsWith"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("beginsWith")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing beginsWith element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sbeginsWith>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sbeginsWith>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_2, (_getAllLoggerData->property_beginsWith)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_2, axutil_strlen(text_value_2));
                           
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
             * Getter for logNameFilter by  Property Number 1
             */
            axis2_char_t* AXIS2_CALL
            adb_getAllLoggerData_get_property1(
                adb_getAllLoggerData_t* _getAllLoggerData,
                const axutil_env_t *env)
            {
                return adb_getAllLoggerData_get_logNameFilter(_getAllLoggerData,
                                             env);
            }

            /**
             * getter for logNameFilter.
             */
            axis2_char_t* AXIS2_CALL
            adb_getAllLoggerData_get_logNameFilter(
                    adb_getAllLoggerData_t* _getAllLoggerData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _getAllLoggerData, NULL);
                  

                return _getAllLoggerData->property_logNameFilter;
             }

            /**
             * setter for logNameFilter
             */
            axis2_status_t AXIS2_CALL
            adb_getAllLoggerData_set_logNameFilter(
                    adb_getAllLoggerData_t* _getAllLoggerData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_logNameFilter)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _getAllLoggerData, AXIS2_FAILURE);
                
                if(_getAllLoggerData->is_valid_logNameFilter &&
                        arg_logNameFilter == _getAllLoggerData->property_logNameFilter)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_getAllLoggerData_reset_logNameFilter(_getAllLoggerData, env);

                
                if(NULL == arg_logNameFilter)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _getAllLoggerData->property_logNameFilter = (axis2_char_t *)axutil_strdup(env, arg_logNameFilter);
                        if(NULL == _getAllLoggerData->property_logNameFilter)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for logNameFilter");
                            return AXIS2_FAILURE;
                        }
                        _getAllLoggerData->is_valid_logNameFilter = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for logNameFilter
            */
           axis2_status_t AXIS2_CALL
           adb_getAllLoggerData_reset_logNameFilter(
                   adb_getAllLoggerData_t* _getAllLoggerData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _getAllLoggerData, AXIS2_FAILURE);
               

               
            
                
                if(_getAllLoggerData->property_logNameFilter != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _getAllLoggerData->property_logNameFilter);
                     _getAllLoggerData->property_logNameFilter = NULL;
                }
            
                
                
                _getAllLoggerData->is_valid_logNameFilter = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether logNameFilter is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_getAllLoggerData_is_logNameFilter_nil(
                   adb_getAllLoggerData_t* _getAllLoggerData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _getAllLoggerData, AXIS2_TRUE);
               
               return !_getAllLoggerData->is_valid_logNameFilter;
           }

           /**
            * Set logNameFilter to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_getAllLoggerData_set_logNameFilter_nil(
                   adb_getAllLoggerData_t* _getAllLoggerData,
                   const axutil_env_t *env)
           {
               return adb_getAllLoggerData_reset_logNameFilter(_getAllLoggerData, env);
           }

           

            /**
             * Getter for beginsWith by  Property Number 2
             */
            axis2_bool_t AXIS2_CALL
            adb_getAllLoggerData_get_property2(
                adb_getAllLoggerData_t* _getAllLoggerData,
                const axutil_env_t *env)
            {
                return adb_getAllLoggerData_get_beginsWith(_getAllLoggerData,
                                             env);
            }

            /**
             * getter for beginsWith.
             */
            axis2_bool_t AXIS2_CALL
            adb_getAllLoggerData_get_beginsWith(
                    adb_getAllLoggerData_t* _getAllLoggerData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _getAllLoggerData, (axis2_bool_t)0);
                  

                return _getAllLoggerData->property_beginsWith;
             }

            /**
             * setter for beginsWith
             */
            axis2_status_t AXIS2_CALL
            adb_getAllLoggerData_set_beginsWith(
                    adb_getAllLoggerData_t* _getAllLoggerData,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_beginsWith)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _getAllLoggerData, AXIS2_FAILURE);
                
                if(_getAllLoggerData->is_valid_beginsWith &&
                        arg_beginsWith == _getAllLoggerData->property_beginsWith)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_getAllLoggerData_reset_beginsWith(_getAllLoggerData, env);

                _getAllLoggerData->property_beginsWith = arg_beginsWith;
                        _getAllLoggerData->is_valid_beginsWith = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for beginsWith
            */
           axis2_status_t AXIS2_CALL
           adb_getAllLoggerData_reset_beginsWith(
                   adb_getAllLoggerData_t* _getAllLoggerData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _getAllLoggerData, AXIS2_FAILURE);
               

               _getAllLoggerData->is_valid_beginsWith = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether beginsWith is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_getAllLoggerData_is_beginsWith_nil(
                   adb_getAllLoggerData_t* _getAllLoggerData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _getAllLoggerData, AXIS2_TRUE);
               
               return !_getAllLoggerData->is_valid_beginsWith;
           }

           /**
            * Set beginsWith to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_getAllLoggerData_set_beginsWith_nil(
                   adb_getAllLoggerData_t* _getAllLoggerData,
                   const axutil_env_t *env)
           {
               return adb_getAllLoggerData_reset_beginsWith(_getAllLoggerData, env);
           }

           

