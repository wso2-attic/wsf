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
         * adb_listServiceGroups.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_listServiceGroups.h"
        
               /*
                * implmentation of the listServiceGroups|http://org.apache.axis2/xsd element
                */
           


        struct adb_listServiceGroups
        {
            axis2_char_t *property_Type;

            
                axutil_qname_t* qname;
            axis2_char_t* property_serviceTypeFilter;

                
                axis2_bool_t is_valid_serviceTypeFilter;
            axis2_char_t* property_serviceGroupSearchString;

                
                axis2_bool_t is_valid_serviceGroupSearchString;
            int property_pageNumber;

                
                axis2_bool_t is_valid_pageNumber;
            
        };


       /************************* Private Function prototypes ********************************/
        

                axis2_status_t AXIS2_CALL
                adb_listServiceGroups_set_pageNumber_nil(
                        adb_listServiceGroups_t* _listServiceGroups,
                        const axutil_env_t *env);
            


       /************************* Function Implmentations ********************************/
        adb_listServiceGroups_t* AXIS2_CALL
        adb_listServiceGroups_create(
            const axutil_env_t *env)
        {
            adb_listServiceGroups_t *_listServiceGroups = NULL;
            
                axutil_qname_t* qname = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _listServiceGroups = (adb_listServiceGroups_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_listServiceGroups_t));

            if(NULL == _listServiceGroups)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_listServiceGroups, 0, sizeof(adb_listServiceGroups_t));

            _listServiceGroups->property_Type = axutil_strdup(env, "adb_listServiceGroups");
            _listServiceGroups->property_serviceTypeFilter  = NULL;
                  _listServiceGroups->is_valid_serviceTypeFilter  = AXIS2_FALSE;
            _listServiceGroups->property_serviceGroupSearchString  = NULL;
                  _listServiceGroups->is_valid_serviceGroupSearchString  = AXIS2_FALSE;
            _listServiceGroups->is_valid_pageNumber  = AXIS2_FALSE;
            
                  qname =  axutil_qname_create (env,
                        "listServiceGroups",
                        "http://org.apache.axis2/xsd",
                        NULL);
                _listServiceGroups->qname = qname;
            

            return _listServiceGroups;
        }

        adb_listServiceGroups_t* AXIS2_CALL
        adb_listServiceGroups_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _serviceTypeFilter,
                axis2_char_t* _serviceGroupSearchString,
                int _pageNumber)
        {
            adb_listServiceGroups_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_listServiceGroups_create(env);

            
              status = adb_listServiceGroups_set_serviceTypeFilter(
                                     adb_obj,
                                     env,
                                     _serviceTypeFilter);
              if(status == AXIS2_FAILURE) {
                  adb_listServiceGroups_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_listServiceGroups_set_serviceGroupSearchString(
                                     adb_obj,
                                     env,
                                     _serviceGroupSearchString);
              if(status == AXIS2_FAILURE) {
                  adb_listServiceGroups_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_listServiceGroups_set_pageNumber(
                                     adb_obj,
                                     env,
                                     _pageNumber);
              if(status == AXIS2_FAILURE) {
                  adb_listServiceGroups_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_char_t* AXIS2_CALL
                adb_listServiceGroups_free_popping_value(
                        adb_listServiceGroups_t* _listServiceGroups,
                        const axutil_env_t *env)
                {
                    axis2_char_t* value;

                    
                    
                    value = _listServiceGroups->property_serviceTypeFilter;

                    _listServiceGroups->property_serviceTypeFilter = (axis2_char_t*)NULL;
                    adb_listServiceGroups_free(_listServiceGroups, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_listServiceGroups_free(
                adb_listServiceGroups_t* _listServiceGroups,
                const axutil_env_t *env)
        {
            
            
            return adb_listServiceGroups_free_obj(
                _listServiceGroups,
                env);
            
        }

        axis2_status_t AXIS2_CALL
        adb_listServiceGroups_free_obj(
                adb_listServiceGroups_t* _listServiceGroups,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _listServiceGroups, AXIS2_FAILURE);

            if (_listServiceGroups->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _listServiceGroups->property_Type);
            }

            adb_listServiceGroups_reset_serviceTypeFilter(_listServiceGroups, env);
            adb_listServiceGroups_reset_serviceGroupSearchString(_listServiceGroups, env);
            adb_listServiceGroups_reset_pageNumber(_listServiceGroups, env);
            
              if(_listServiceGroups->qname)
              {
                  axutil_qname_free (_listServiceGroups->qname, env);
                  _listServiceGroups->qname = NULL;
              }
            

            if(_listServiceGroups)
            {
                AXIS2_FREE(env->allocator, _listServiceGroups);
                _listServiceGroups = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_listServiceGroups_deserialize(
                adb_listServiceGroups_t* _listServiceGroups,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return adb_listServiceGroups_deserialize_obj(
                _listServiceGroups,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs);
            
        }

        axis2_status_t AXIS2_CALL
        adb_listServiceGroups_deserialize_obj(
                adb_listServiceGroups_t* _listServiceGroups,
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
            AXIS2_PARAM_CHECK(env->error, _listServiceGroups, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for listServiceGroups : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              

                    current_element = (axiom_element_t *)axiom_node_get_data_element(parent, env);
                    qname = axiom_element_get_qname(current_element, env, parent);
                    if (axutil_qname_equals(qname, env, _listServiceGroups-> qname))
                    {
                        
                          first_node = axiom_node_get_first_child(parent, env);
                          
                    }
                    else
                    {
                        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                              "Failed in building adb object for listServiceGroups : "
                              "Expected %s but returned %s",
                              axutil_qname_to_string(_listServiceGroups-> qname, env),
                              axutil_qname_to_string(qname, env));
                        
                        return AXIS2_FAILURE;
                    }
                    

                     
                     /*
                      * building serviceTypeFilter element
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
                                   
                                 element_qname = axutil_qname_create(env, "serviceTypeFilter", "http://org.apache.axis2/xsd", NULL);
                                 

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
                                            status = adb_listServiceGroups_set_serviceTypeFilter(_listServiceGroups, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for serviceTypeFilter ");
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
                      * building serviceGroupSearchString element
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
                                 
                                 element_qname = axutil_qname_create(env, "serviceGroupSearchString", "http://org.apache.axis2/xsd", NULL);
                                 

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
                                            status = adb_listServiceGroups_set_serviceGroupSearchString(_listServiceGroups, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for serviceGroupSearchString ");
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
                      * building pageNumber element
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
                                 
                                 element_qname = axutil_qname_create(env, "pageNumber", "http://org.apache.axis2/xsd", NULL);
                                 

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
                                            status = adb_listServiceGroups_set_pageNumber(_listServiceGroups, env,
                                                                   atoi(text_value));
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element pageNumber");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for pageNumber ");
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
          adb_listServiceGroups_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_listServiceGroups_declare_parent_namespaces(
                    adb_listServiceGroups_t* _listServiceGroups,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_listServiceGroups_serialize(
                adb_listServiceGroups_t* _listServiceGroups,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
                return adb_listServiceGroups_serialize_obj(
                    _listServiceGroups, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            
        }

        axiom_node_t* AXIS2_CALL
        adb_listServiceGroups_serialize_obj(
                adb_listServiceGroups_t* _listServiceGroups,
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
            AXIS2_PARAM_CHECK(env->error, _listServiceGroups, NULL);
            
             
                    namespaces = axutil_hash_make(env);
                    next_ns_index = &next_ns_index_value;
                     
                           ns1 = axiom_namespace_create (env,
                                             "http://org.apache.axis2/xsd",
                                             "n"); 
                           axutil_hash_set(namespaces, "http://org.apache.axis2/xsd", AXIS2_HASH_KEY_STRING, axutil_strdup(env, "n"));
                       
                     
                    parent_element = axiom_element_create (env, NULL, "listServiceGroups", ns1 , &parent);
                    
                    
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
                      

                   if (!_listServiceGroups->is_valid_serviceTypeFilter)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("serviceTypeFilter"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("serviceTypeFilter")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing serviceTypeFilter element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sserviceTypeFilter>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sserviceTypeFilter>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_1 = _listServiceGroups->property_serviceTypeFilter;
                           
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
                      

                   if (!_listServiceGroups->is_valid_serviceGroupSearchString)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("serviceGroupSearchString"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("serviceGroupSearchString")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing serviceGroupSearchString element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sserviceGroupSearchString>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sserviceGroupSearchString>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_2 = _listServiceGroups->property_serviceGroupSearchString;
                           
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
                      

                   if (!_listServiceGroups->is_valid_pageNumber)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("pageNumber"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("pageNumber")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing pageNumber element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%spageNumber>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%spageNumber>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                               sprintf (text_value_3, AXIS2_PRINTF_INT32_FORMAT_SPECIFIER, _listServiceGroups->property_pageNumber);
                             
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
             * Getter for serviceTypeFilter by  Property Number 1
             */
            axis2_char_t* AXIS2_CALL
            adb_listServiceGroups_get_property1(
                adb_listServiceGroups_t* _listServiceGroups,
                const axutil_env_t *env)
            {
                return adb_listServiceGroups_get_serviceTypeFilter(_listServiceGroups,
                                             env);
            }

            /**
             * getter for serviceTypeFilter.
             */
            axis2_char_t* AXIS2_CALL
            adb_listServiceGroups_get_serviceTypeFilter(
                    adb_listServiceGroups_t* _listServiceGroups,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _listServiceGroups, NULL);
                  

                return _listServiceGroups->property_serviceTypeFilter;
             }

            /**
             * setter for serviceTypeFilter
             */
            axis2_status_t AXIS2_CALL
            adb_listServiceGroups_set_serviceTypeFilter(
                    adb_listServiceGroups_t* _listServiceGroups,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_serviceTypeFilter)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _listServiceGroups, AXIS2_FAILURE);
                
                if(_listServiceGroups->is_valid_serviceTypeFilter &&
                        arg_serviceTypeFilter == _listServiceGroups->property_serviceTypeFilter)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_listServiceGroups_reset_serviceTypeFilter(_listServiceGroups, env);

                
                if(NULL == arg_serviceTypeFilter)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _listServiceGroups->property_serviceTypeFilter = (axis2_char_t *)axutil_strdup(env, arg_serviceTypeFilter);
                        if(NULL == _listServiceGroups->property_serviceTypeFilter)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for serviceTypeFilter");
                            return AXIS2_FAILURE;
                        }
                        _listServiceGroups->is_valid_serviceTypeFilter = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for serviceTypeFilter
            */
           axis2_status_t AXIS2_CALL
           adb_listServiceGroups_reset_serviceTypeFilter(
                   adb_listServiceGroups_t* _listServiceGroups,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _listServiceGroups, AXIS2_FAILURE);
               

               
            
                
                if(_listServiceGroups->property_serviceTypeFilter != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _listServiceGroups->property_serviceTypeFilter);
                     _listServiceGroups->property_serviceTypeFilter = NULL;
                }
            
                
                
                _listServiceGroups->is_valid_serviceTypeFilter = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether serviceTypeFilter is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_listServiceGroups_is_serviceTypeFilter_nil(
                   adb_listServiceGroups_t* _listServiceGroups,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _listServiceGroups, AXIS2_TRUE);
               
               return !_listServiceGroups->is_valid_serviceTypeFilter;
           }

           /**
            * Set serviceTypeFilter to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_listServiceGroups_set_serviceTypeFilter_nil(
                   adb_listServiceGroups_t* _listServiceGroups,
                   const axutil_env_t *env)
           {
               return adb_listServiceGroups_reset_serviceTypeFilter(_listServiceGroups, env);
           }

           

            /**
             * Getter for serviceGroupSearchString by  Property Number 2
             */
            axis2_char_t* AXIS2_CALL
            adb_listServiceGroups_get_property2(
                adb_listServiceGroups_t* _listServiceGroups,
                const axutil_env_t *env)
            {
                return adb_listServiceGroups_get_serviceGroupSearchString(_listServiceGroups,
                                             env);
            }

            /**
             * getter for serviceGroupSearchString.
             */
            axis2_char_t* AXIS2_CALL
            adb_listServiceGroups_get_serviceGroupSearchString(
                    adb_listServiceGroups_t* _listServiceGroups,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _listServiceGroups, NULL);
                  

                return _listServiceGroups->property_serviceGroupSearchString;
             }

            /**
             * setter for serviceGroupSearchString
             */
            axis2_status_t AXIS2_CALL
            adb_listServiceGroups_set_serviceGroupSearchString(
                    adb_listServiceGroups_t* _listServiceGroups,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_serviceGroupSearchString)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _listServiceGroups, AXIS2_FAILURE);
                
                if(_listServiceGroups->is_valid_serviceGroupSearchString &&
                        arg_serviceGroupSearchString == _listServiceGroups->property_serviceGroupSearchString)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_listServiceGroups_reset_serviceGroupSearchString(_listServiceGroups, env);

                
                if(NULL == arg_serviceGroupSearchString)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _listServiceGroups->property_serviceGroupSearchString = (axis2_char_t *)axutil_strdup(env, arg_serviceGroupSearchString);
                        if(NULL == _listServiceGroups->property_serviceGroupSearchString)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for serviceGroupSearchString");
                            return AXIS2_FAILURE;
                        }
                        _listServiceGroups->is_valid_serviceGroupSearchString = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for serviceGroupSearchString
            */
           axis2_status_t AXIS2_CALL
           adb_listServiceGroups_reset_serviceGroupSearchString(
                   adb_listServiceGroups_t* _listServiceGroups,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _listServiceGroups, AXIS2_FAILURE);
               

               
            
                
                if(_listServiceGroups->property_serviceGroupSearchString != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _listServiceGroups->property_serviceGroupSearchString);
                     _listServiceGroups->property_serviceGroupSearchString = NULL;
                }
            
                
                
                _listServiceGroups->is_valid_serviceGroupSearchString = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether serviceGroupSearchString is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_listServiceGroups_is_serviceGroupSearchString_nil(
                   adb_listServiceGroups_t* _listServiceGroups,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _listServiceGroups, AXIS2_TRUE);
               
               return !_listServiceGroups->is_valid_serviceGroupSearchString;
           }

           /**
            * Set serviceGroupSearchString to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_listServiceGroups_set_serviceGroupSearchString_nil(
                   adb_listServiceGroups_t* _listServiceGroups,
                   const axutil_env_t *env)
           {
               return adb_listServiceGroups_reset_serviceGroupSearchString(_listServiceGroups, env);
           }

           

            /**
             * Getter for pageNumber by  Property Number 3
             */
            int AXIS2_CALL
            adb_listServiceGroups_get_property3(
                adb_listServiceGroups_t* _listServiceGroups,
                const axutil_env_t *env)
            {
                return adb_listServiceGroups_get_pageNumber(_listServiceGroups,
                                             env);
            }

            /**
             * getter for pageNumber.
             */
            int AXIS2_CALL
            adb_listServiceGroups_get_pageNumber(
                    adb_listServiceGroups_t* _listServiceGroups,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (int)0);
                    AXIS2_PARAM_CHECK(env->error, _listServiceGroups, (int)0);
                  

                return _listServiceGroups->property_pageNumber;
             }

            /**
             * setter for pageNumber
             */
            axis2_status_t AXIS2_CALL
            adb_listServiceGroups_set_pageNumber(
                    adb_listServiceGroups_t* _listServiceGroups,
                    const axutil_env_t *env,
                    const int  arg_pageNumber)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _listServiceGroups, AXIS2_FAILURE);
                
                if(_listServiceGroups->is_valid_pageNumber &&
                        arg_pageNumber == _listServiceGroups->property_pageNumber)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_listServiceGroups_reset_pageNumber(_listServiceGroups, env);

                _listServiceGroups->property_pageNumber = arg_pageNumber;
                        _listServiceGroups->is_valid_pageNumber = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for pageNumber
            */
           axis2_status_t AXIS2_CALL
           adb_listServiceGroups_reset_pageNumber(
                   adb_listServiceGroups_t* _listServiceGroups,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _listServiceGroups, AXIS2_FAILURE);
               

               _listServiceGroups->is_valid_pageNumber = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether pageNumber is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_listServiceGroups_is_pageNumber_nil(
                   adb_listServiceGroups_t* _listServiceGroups,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _listServiceGroups, AXIS2_TRUE);
               
               return !_listServiceGroups->is_valid_pageNumber;
           }

           /**
            * Set pageNumber to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_listServiceGroups_set_pageNumber_nil(
                   adb_listServiceGroups_t* _listServiceGroups,
                   const axutil_env_t *env)
           {
               return adb_listServiceGroups_reset_pageNumber(_listServiceGroups, env);
           }

           

