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
         * adb_updateRoleName.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_updateRoleName.h"
        
               /*
                * implmentation of the updateRoleName|http://service.mgt.user.carbon.wso2.org element
                */
           


        struct adb_updateRoleName
        {
            axis2_char_t *property_Type;

            
                axutil_qname_t* qname;
            axis2_char_t* property_roleName;

                
                axis2_bool_t is_valid_roleName;
            axis2_char_t* property_newRoleName;

                
                axis2_bool_t is_valid_newRoleName;
            
        };


       /************************* Private Function prototypes ********************************/
        


       /************************* Function Implmentations ********************************/
        adb_updateRoleName_t* AXIS2_CALL
        adb_updateRoleName_create(
            const axutil_env_t *env)
        {
            adb_updateRoleName_t *_updateRoleName = NULL;
            
                axutil_qname_t* qname = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _updateRoleName = (adb_updateRoleName_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_updateRoleName_t));

            if(NULL == _updateRoleName)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_updateRoleName, 0, sizeof(adb_updateRoleName_t));

            _updateRoleName->property_Type = axutil_strdup(env, "adb_updateRoleName");
            _updateRoleName->property_roleName  = NULL;
                  _updateRoleName->is_valid_roleName  = AXIS2_FALSE;
            _updateRoleName->property_newRoleName  = NULL;
                  _updateRoleName->is_valid_newRoleName  = AXIS2_FALSE;
            
                  qname =  axutil_qname_create (env,
                        "updateRoleName",
                        "http://service.mgt.user.carbon.wso2.org",
                        NULL);
                _updateRoleName->qname = qname;
            

            return _updateRoleName;
        }

        adb_updateRoleName_t* AXIS2_CALL
        adb_updateRoleName_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _roleName,
                axis2_char_t* _newRoleName)
        {
            adb_updateRoleName_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_updateRoleName_create(env);

            
              status = adb_updateRoleName_set_roleName(
                                     adb_obj,
                                     env,
                                     _roleName);
              if(status == AXIS2_FAILURE) {
                  adb_updateRoleName_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_updateRoleName_set_newRoleName(
                                     adb_obj,
                                     env,
                                     _newRoleName);
              if(status == AXIS2_FAILURE) {
                  adb_updateRoleName_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_char_t* AXIS2_CALL
                adb_updateRoleName_free_popping_value(
                        adb_updateRoleName_t* _updateRoleName,
                        const axutil_env_t *env)
                {
                    axis2_char_t* value;

                    
                    
                    value = _updateRoleName->property_roleName;

                    _updateRoleName->property_roleName = (axis2_char_t*)NULL;
                    adb_updateRoleName_free(_updateRoleName, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_updateRoleName_free(
                adb_updateRoleName_t* _updateRoleName,
                const axutil_env_t *env)
        {
            
            
            return adb_updateRoleName_free_obj(
                _updateRoleName,
                env);
            
        }

        axis2_status_t AXIS2_CALL
        adb_updateRoleName_free_obj(
                adb_updateRoleName_t* _updateRoleName,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _updateRoleName, AXIS2_FAILURE);

            if (_updateRoleName->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _updateRoleName->property_Type);
            }

            adb_updateRoleName_reset_roleName(_updateRoleName, env);
            adb_updateRoleName_reset_newRoleName(_updateRoleName, env);
            
              if(_updateRoleName->qname)
              {
                  axutil_qname_free (_updateRoleName->qname, env);
                  _updateRoleName->qname = NULL;
              }
            

            if(_updateRoleName)
            {
                AXIS2_FREE(env->allocator, _updateRoleName);
                _updateRoleName = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_updateRoleName_deserialize(
                adb_updateRoleName_t* _updateRoleName,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return adb_updateRoleName_deserialize_obj(
                _updateRoleName,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs);
            
        }

        axis2_status_t AXIS2_CALL
        adb_updateRoleName_deserialize_obj(
                adb_updateRoleName_t* _updateRoleName,
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
            AXIS2_PARAM_CHECK(env->error, _updateRoleName, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for updateRoleName : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              

                    current_element = (axiom_element_t *)axiom_node_get_data_element(parent, env);
                    qname = axiom_element_get_qname(current_element, env, parent);
                    if (axutil_qname_equals(qname, env, _updateRoleName-> qname))
                    {
                        
                          first_node = axiom_node_get_first_child(parent, env);
                          
                    }
                    else
                    {
                        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                              "Failed in building adb object for updateRoleName : "
                              "Expected %s but returned %s",
                              axutil_qname_to_string(_updateRoleName-> qname, env),
                              axutil_qname_to_string(qname, env));
                        
                        return AXIS2_FAILURE;
                    }
                    

                     
                     /*
                      * building roleName element
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
                                   
                                 element_qname = axutil_qname_create(env, "roleName", "http://service.mgt.user.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_updateRoleName_set_roleName(_updateRoleName, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for roleName ");
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
                      * building newRoleName element
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
                                 
                                 element_qname = axutil_qname_create(env, "newRoleName", "http://service.mgt.user.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_updateRoleName_set_newRoleName(_updateRoleName, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for newRoleName ");
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
          adb_updateRoleName_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_updateRoleName_declare_parent_namespaces(
                    adb_updateRoleName_t* _updateRoleName,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_updateRoleName_serialize(
                adb_updateRoleName_t* _updateRoleName,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
                return adb_updateRoleName_serialize_obj(
                    _updateRoleName, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            
        }

        axiom_node_t* AXIS2_CALL
        adb_updateRoleName_serialize_obj(
                adb_updateRoleName_t* _updateRoleName,
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
            AXIS2_PARAM_CHECK(env->error, _updateRoleName, NULL);
            
             
                    namespaces = axutil_hash_make(env);
                    next_ns_index = &next_ns_index_value;
                     
                           ns1 = axiom_namespace_create (env,
                                             "http://service.mgt.user.carbon.wso2.org",
                                             "n"); 
                           axutil_hash_set(namespaces, "http://service.mgt.user.carbon.wso2.org", AXIS2_HASH_KEY_STRING, axutil_strdup(env, "n"));
                       
                     
                    parent_element = axiom_element_create (env, NULL, "updateRoleName", ns1 , &parent);
                    
                    
                    axiom_element_set_namespace(parent_element, env, ns1, parent);


            
                    data_source = axiom_data_source_create(env, parent, &current_node);
                    stream = axiom_data_source_get_stream(data_source, env);
                  
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.mgt.user.carbon.wso2.org", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.mgt.user.carbon.wso2.org", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.mgt.user.carbon.wso2.org",
                                            p_prefix));
                       }
                      

                   if (!_updateRoleName->is_valid_roleName)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("roleName"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("roleName")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing roleName element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sroleName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sroleName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_1 = _updateRoleName->property_roleName;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.mgt.user.carbon.wso2.org", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.mgt.user.carbon.wso2.org", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.mgt.user.carbon.wso2.org",
                                            p_prefix));
                       }
                      

                   if (!_updateRoleName->is_valid_newRoleName)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("newRoleName"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("newRoleName")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing newRoleName element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%snewRoleName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%snewRoleName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_2 = _updateRoleName->property_newRoleName;
                           
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
             * Getter for roleName by  Property Number 1
             */
            axis2_char_t* AXIS2_CALL
            adb_updateRoleName_get_property1(
                adb_updateRoleName_t* _updateRoleName,
                const axutil_env_t *env)
            {
                return adb_updateRoleName_get_roleName(_updateRoleName,
                                             env);
            }

            /**
             * getter for roleName.
             */
            axis2_char_t* AXIS2_CALL
            adb_updateRoleName_get_roleName(
                    adb_updateRoleName_t* _updateRoleName,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _updateRoleName, NULL);
                  

                return _updateRoleName->property_roleName;
             }

            /**
             * setter for roleName
             */
            axis2_status_t AXIS2_CALL
            adb_updateRoleName_set_roleName(
                    adb_updateRoleName_t* _updateRoleName,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_roleName)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _updateRoleName, AXIS2_FAILURE);
                
                if(_updateRoleName->is_valid_roleName &&
                        arg_roleName == _updateRoleName->property_roleName)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_updateRoleName_reset_roleName(_updateRoleName, env);

                
                if(NULL == arg_roleName)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _updateRoleName->property_roleName = (axis2_char_t *)axutil_strdup(env, arg_roleName);
                        if(NULL == _updateRoleName->property_roleName)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for roleName");
                            return AXIS2_FAILURE;
                        }
                        _updateRoleName->is_valid_roleName = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for roleName
            */
           axis2_status_t AXIS2_CALL
           adb_updateRoleName_reset_roleName(
                   adb_updateRoleName_t* _updateRoleName,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _updateRoleName, AXIS2_FAILURE);
               

               
            
                
                if(_updateRoleName->property_roleName != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _updateRoleName->property_roleName);
                     _updateRoleName->property_roleName = NULL;
                }
            
                
                
                _updateRoleName->is_valid_roleName = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether roleName is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_updateRoleName_is_roleName_nil(
                   adb_updateRoleName_t* _updateRoleName,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _updateRoleName, AXIS2_TRUE);
               
               return !_updateRoleName->is_valid_roleName;
           }

           /**
            * Set roleName to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_updateRoleName_set_roleName_nil(
                   adb_updateRoleName_t* _updateRoleName,
                   const axutil_env_t *env)
           {
               return adb_updateRoleName_reset_roleName(_updateRoleName, env);
           }

           

            /**
             * Getter for newRoleName by  Property Number 2
             */
            axis2_char_t* AXIS2_CALL
            adb_updateRoleName_get_property2(
                adb_updateRoleName_t* _updateRoleName,
                const axutil_env_t *env)
            {
                return adb_updateRoleName_get_newRoleName(_updateRoleName,
                                             env);
            }

            /**
             * getter for newRoleName.
             */
            axis2_char_t* AXIS2_CALL
            adb_updateRoleName_get_newRoleName(
                    adb_updateRoleName_t* _updateRoleName,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _updateRoleName, NULL);
                  

                return _updateRoleName->property_newRoleName;
             }

            /**
             * setter for newRoleName
             */
            axis2_status_t AXIS2_CALL
            adb_updateRoleName_set_newRoleName(
                    adb_updateRoleName_t* _updateRoleName,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_newRoleName)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _updateRoleName, AXIS2_FAILURE);
                
                if(_updateRoleName->is_valid_newRoleName &&
                        arg_newRoleName == _updateRoleName->property_newRoleName)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_updateRoleName_reset_newRoleName(_updateRoleName, env);

                
                if(NULL == arg_newRoleName)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _updateRoleName->property_newRoleName = (axis2_char_t *)axutil_strdup(env, arg_newRoleName);
                        if(NULL == _updateRoleName->property_newRoleName)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for newRoleName");
                            return AXIS2_FAILURE;
                        }
                        _updateRoleName->is_valid_newRoleName = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for newRoleName
            */
           axis2_status_t AXIS2_CALL
           adb_updateRoleName_reset_newRoleName(
                   adb_updateRoleName_t* _updateRoleName,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _updateRoleName, AXIS2_FAILURE);
               

               
            
                
                if(_updateRoleName->property_newRoleName != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _updateRoleName->property_newRoleName);
                     _updateRoleName->property_newRoleName = NULL;
                }
            
                
                
                _updateRoleName->is_valid_newRoleName = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether newRoleName is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_updateRoleName_is_newRoleName_nil(
                   adb_updateRoleName_t* _updateRoleName,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _updateRoleName, AXIS2_TRUE);
               
               return !_updateRoleName->is_valid_newRoleName;
           }

           /**
            * Set newRoleName to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_updateRoleName_set_newRoleName_nil(
                   adb_updateRoleName_t* _updateRoleName,
                   const axutil_env_t *env)
           {
               return adb_updateRoleName_reset_newRoleName(_updateRoleName, env);
           }

           

