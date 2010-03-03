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
         * adb_addUserToInternalStore.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_addUserToInternalStore.h"
        
               /*
                * implmentation of the addUserToInternalStore|http://service.mgt.user.carbon.wso2.org element
                */
           


        struct adb_addUserToInternalStore
        {
            axis2_char_t *property_Type;

            
                axutil_qname_t* qname;
            axis2_char_t* property_userName;

                
                axis2_bool_t is_valid_userName;
            axis2_char_t* property_password;

                
                axis2_bool_t is_valid_password;
            axutil_array_list_t* property_roles;

                
                axis2_bool_t is_valid_roles;
            
        };


       /************************* Private Function prototypes ********************************/
        


       /************************* Function Implmentations ********************************/
        adb_addUserToInternalStore_t* AXIS2_CALL
        adb_addUserToInternalStore_create(
            const axutil_env_t *env)
        {
            adb_addUserToInternalStore_t *_addUserToInternalStore = NULL;
            
                axutil_qname_t* qname = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _addUserToInternalStore = (adb_addUserToInternalStore_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_addUserToInternalStore_t));

            if(NULL == _addUserToInternalStore)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_addUserToInternalStore, 0, sizeof(adb_addUserToInternalStore_t));

            _addUserToInternalStore->property_Type = axutil_strdup(env, "adb_addUserToInternalStore");
            _addUserToInternalStore->property_userName  = NULL;
                  _addUserToInternalStore->is_valid_userName  = AXIS2_FALSE;
            _addUserToInternalStore->property_password  = NULL;
                  _addUserToInternalStore->is_valid_password  = AXIS2_FALSE;
            _addUserToInternalStore->property_roles  = NULL;
                  _addUserToInternalStore->is_valid_roles  = AXIS2_FALSE;
            
                  qname =  axutil_qname_create (env,
                        "addUserToInternalStore",
                        "http://service.mgt.user.carbon.wso2.org",
                        NULL);
                _addUserToInternalStore->qname = qname;
            

            return _addUserToInternalStore;
        }

        adb_addUserToInternalStore_t* AXIS2_CALL
        adb_addUserToInternalStore_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _userName,
                axis2_char_t* _password,
                axutil_array_list_t* _roles)
        {
            adb_addUserToInternalStore_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_addUserToInternalStore_create(env);

            
              status = adb_addUserToInternalStore_set_userName(
                                     adb_obj,
                                     env,
                                     _userName);
              if(status == AXIS2_FAILURE) {
                  adb_addUserToInternalStore_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_addUserToInternalStore_set_password(
                                     adb_obj,
                                     env,
                                     _password);
              if(status == AXIS2_FAILURE) {
                  adb_addUserToInternalStore_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_addUserToInternalStore_set_roles(
                                     adb_obj,
                                     env,
                                     _roles);
              if(status == AXIS2_FAILURE) {
                  adb_addUserToInternalStore_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_char_t* AXIS2_CALL
                adb_addUserToInternalStore_free_popping_value(
                        adb_addUserToInternalStore_t* _addUserToInternalStore,
                        const axutil_env_t *env)
                {
                    axis2_char_t* value;

                    
                    
                    value = _addUserToInternalStore->property_userName;

                    _addUserToInternalStore->property_userName = (axis2_char_t*)NULL;
                    adb_addUserToInternalStore_free(_addUserToInternalStore, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_addUserToInternalStore_free(
                adb_addUserToInternalStore_t* _addUserToInternalStore,
                const axutil_env_t *env)
        {
            
            
            return adb_addUserToInternalStore_free_obj(
                _addUserToInternalStore,
                env);
            
        }

        axis2_status_t AXIS2_CALL
        adb_addUserToInternalStore_free_obj(
                adb_addUserToInternalStore_t* _addUserToInternalStore,
                const axutil_env_t *env)
        {
            
                int i = 0;
                int count = 0;
                void *element = NULL;
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _addUserToInternalStore, AXIS2_FAILURE);

            if (_addUserToInternalStore->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _addUserToInternalStore->property_Type);
            }

            adb_addUserToInternalStore_reset_userName(_addUserToInternalStore, env);
            adb_addUserToInternalStore_reset_password(_addUserToInternalStore, env);
            adb_addUserToInternalStore_reset_roles(_addUserToInternalStore, env);
            
              if(_addUserToInternalStore->qname)
              {
                  axutil_qname_free (_addUserToInternalStore->qname, env);
                  _addUserToInternalStore->qname = NULL;
              }
            

            if(_addUserToInternalStore)
            {
                AXIS2_FREE(env->allocator, _addUserToInternalStore);
                _addUserToInternalStore = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_addUserToInternalStore_deserialize(
                adb_addUserToInternalStore_t* _addUserToInternalStore,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return adb_addUserToInternalStore_deserialize_obj(
                _addUserToInternalStore,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs);
            
        }

        axis2_status_t AXIS2_CALL
        adb_addUserToInternalStore_deserialize_obj(
                adb_addUserToInternalStore_t* _addUserToInternalStore,
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
            AXIS2_PARAM_CHECK(env->error, _addUserToInternalStore, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for addUserToInternalStore : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              

                    current_element = (axiom_element_t *)axiom_node_get_data_element(parent, env);
                    qname = axiom_element_get_qname(current_element, env, parent);
                    if (axutil_qname_equals(qname, env, _addUserToInternalStore-> qname))
                    {
                        
                          first_node = axiom_node_get_first_child(parent, env);
                          
                    }
                    else
                    {
                        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                              "Failed in building adb object for addUserToInternalStore : "
                              "Expected %s but returned %s",
                              axutil_qname_to_string(_addUserToInternalStore-> qname, env),
                              axutil_qname_to_string(qname, env));
                        
                        return AXIS2_FAILURE;
                    }
                    

                     
                     /*
                      * building userName element
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
                                   
                                 element_qname = axutil_qname_create(env, "userName", "http://service.mgt.user.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_addUserToInternalStore_set_userName(_addUserToInternalStore, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for userName ");
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
                      * building password element
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
                                 
                                 element_qname = axutil_qname_create(env, "password", "http://service.mgt.user.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_addUserToInternalStore_set_password(_addUserToInternalStore, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for password ");
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
                     * building roles array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building roles element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "roles", "http://service.mgt.user.carbon.wso2.org", NULL);
                                  
                               
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
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for roles ");
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
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "roles (@minOccurs = '0') only have %d elements", i);
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
                                    status = adb_addUserToInternalStore_set_roles(_addUserToInternalStore, env,
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
          adb_addUserToInternalStore_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_addUserToInternalStore_declare_parent_namespaces(
                    adb_addUserToInternalStore_t* _addUserToInternalStore,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_addUserToInternalStore_serialize(
                adb_addUserToInternalStore_t* _addUserToInternalStore,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
                return adb_addUserToInternalStore_serialize_obj(
                    _addUserToInternalStore, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            
        }

        axiom_node_t* AXIS2_CALL
        adb_addUserToInternalStore_serialize_obj(
                adb_addUserToInternalStore_t* _addUserToInternalStore,
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
                    
                    axis2_char_t *text_value_3;
                    axis2_char_t *text_value_3_temp;
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

             
                int next_ns_index_value = 0;
            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _addUserToInternalStore, NULL);
            
             
                    namespaces = axutil_hash_make(env);
                    next_ns_index = &next_ns_index_value;
                     
                           ns1 = axiom_namespace_create (env,
                                             "http://service.mgt.user.carbon.wso2.org",
                                             "n"); 
                           axutil_hash_set(namespaces, "http://service.mgt.user.carbon.wso2.org", AXIS2_HASH_KEY_STRING, axutil_strdup(env, "n"));
                       
                     
                    parent_element = axiom_element_create (env, NULL, "addUserToInternalStore", ns1 , &parent);
                    
                    
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
                      

                   if (!_addUserToInternalStore->is_valid_userName)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("userName"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("userName")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing userName element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%suserName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%suserName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_1 = _addUserToInternalStore->property_userName;
                           
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
                      

                   if (!_addUserToInternalStore->is_valid_password)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("password"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("password")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing password element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%spassword>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%spassword>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_2 = _addUserToInternalStore->property_password;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.mgt.user.carbon.wso2.org", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.mgt.user.carbon.wso2.org", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.mgt.user.carbon.wso2.org",
                                            p_prefix));
                       }
                      

                   if (!_addUserToInternalStore->is_valid_roles)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("roles"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("roles")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing roles array
                      */
                     if (_addUserToInternalStore->property_roles != NULL)
                     {
                        
                            sprintf(start_input_str, "<%s%sroles>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%sroles>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_addUserToInternalStore->property_roles, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_addUserToInternalStore->property_roles, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing roles element
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
             * Getter for userName by  Property Number 1
             */
            axis2_char_t* AXIS2_CALL
            adb_addUserToInternalStore_get_property1(
                adb_addUserToInternalStore_t* _addUserToInternalStore,
                const axutil_env_t *env)
            {
                return adb_addUserToInternalStore_get_userName(_addUserToInternalStore,
                                             env);
            }

            /**
             * getter for userName.
             */
            axis2_char_t* AXIS2_CALL
            adb_addUserToInternalStore_get_userName(
                    adb_addUserToInternalStore_t* _addUserToInternalStore,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addUserToInternalStore, NULL);
                  

                return _addUserToInternalStore->property_userName;
             }

            /**
             * setter for userName
             */
            axis2_status_t AXIS2_CALL
            adb_addUserToInternalStore_set_userName(
                    adb_addUserToInternalStore_t* _addUserToInternalStore,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_userName)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addUserToInternalStore, AXIS2_FAILURE);
                
                if(_addUserToInternalStore->is_valid_userName &&
                        arg_userName == _addUserToInternalStore->property_userName)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_addUserToInternalStore_reset_userName(_addUserToInternalStore, env);

                
                if(NULL == arg_userName)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addUserToInternalStore->property_userName = (axis2_char_t *)axutil_strdup(env, arg_userName);
                        if(NULL == _addUserToInternalStore->property_userName)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for userName");
                            return AXIS2_FAILURE;
                        }
                        _addUserToInternalStore->is_valid_userName = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for userName
            */
           axis2_status_t AXIS2_CALL
           adb_addUserToInternalStore_reset_userName(
                   adb_addUserToInternalStore_t* _addUserToInternalStore,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addUserToInternalStore, AXIS2_FAILURE);
               

               
            
                
                if(_addUserToInternalStore->property_userName != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _addUserToInternalStore->property_userName);
                     _addUserToInternalStore->property_userName = NULL;
                }
            
                
                
                _addUserToInternalStore->is_valid_userName = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether userName is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addUserToInternalStore_is_userName_nil(
                   adb_addUserToInternalStore_t* _addUserToInternalStore,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addUserToInternalStore, AXIS2_TRUE);
               
               return !_addUserToInternalStore->is_valid_userName;
           }

           /**
            * Set userName to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addUserToInternalStore_set_userName_nil(
                   adb_addUserToInternalStore_t* _addUserToInternalStore,
                   const axutil_env_t *env)
           {
               return adb_addUserToInternalStore_reset_userName(_addUserToInternalStore, env);
           }

           

            /**
             * Getter for password by  Property Number 2
             */
            axis2_char_t* AXIS2_CALL
            adb_addUserToInternalStore_get_property2(
                adb_addUserToInternalStore_t* _addUserToInternalStore,
                const axutil_env_t *env)
            {
                return adb_addUserToInternalStore_get_password(_addUserToInternalStore,
                                             env);
            }

            /**
             * getter for password.
             */
            axis2_char_t* AXIS2_CALL
            adb_addUserToInternalStore_get_password(
                    adb_addUserToInternalStore_t* _addUserToInternalStore,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addUserToInternalStore, NULL);
                  

                return _addUserToInternalStore->property_password;
             }

            /**
             * setter for password
             */
            axis2_status_t AXIS2_CALL
            adb_addUserToInternalStore_set_password(
                    adb_addUserToInternalStore_t* _addUserToInternalStore,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_password)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addUserToInternalStore, AXIS2_FAILURE);
                
                if(_addUserToInternalStore->is_valid_password &&
                        arg_password == _addUserToInternalStore->property_password)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_addUserToInternalStore_reset_password(_addUserToInternalStore, env);

                
                if(NULL == arg_password)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addUserToInternalStore->property_password = (axis2_char_t *)axutil_strdup(env, arg_password);
                        if(NULL == _addUserToInternalStore->property_password)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for password");
                            return AXIS2_FAILURE;
                        }
                        _addUserToInternalStore->is_valid_password = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for password
            */
           axis2_status_t AXIS2_CALL
           adb_addUserToInternalStore_reset_password(
                   adb_addUserToInternalStore_t* _addUserToInternalStore,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addUserToInternalStore, AXIS2_FAILURE);
               

               
            
                
                if(_addUserToInternalStore->property_password != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _addUserToInternalStore->property_password);
                     _addUserToInternalStore->property_password = NULL;
                }
            
                
                
                _addUserToInternalStore->is_valid_password = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether password is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addUserToInternalStore_is_password_nil(
                   adb_addUserToInternalStore_t* _addUserToInternalStore,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addUserToInternalStore, AXIS2_TRUE);
               
               return !_addUserToInternalStore->is_valid_password;
           }

           /**
            * Set password to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addUserToInternalStore_set_password_nil(
                   adb_addUserToInternalStore_t* _addUserToInternalStore,
                   const axutil_env_t *env)
           {
               return adb_addUserToInternalStore_reset_password(_addUserToInternalStore, env);
           }

           

            /**
             * Getter for roles by  Property Number 3
             */
            axutil_array_list_t* AXIS2_CALL
            adb_addUserToInternalStore_get_property3(
                adb_addUserToInternalStore_t* _addUserToInternalStore,
                const axutil_env_t *env)
            {
                return adb_addUserToInternalStore_get_roles(_addUserToInternalStore,
                                             env);
            }

            /**
             * getter for roles.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_addUserToInternalStore_get_roles(
                    adb_addUserToInternalStore_t* _addUserToInternalStore,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addUserToInternalStore, NULL);
                  

                return _addUserToInternalStore->property_roles;
             }

            /**
             * setter for roles
             */
            axis2_status_t AXIS2_CALL
            adb_addUserToInternalStore_set_roles(
                    adb_addUserToInternalStore_t* _addUserToInternalStore,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_roles)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addUserToInternalStore, AXIS2_FAILURE);
                
                if(_addUserToInternalStore->is_valid_roles &&
                        arg_roles == _addUserToInternalStore->property_roles)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_roles, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "roles has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_roles, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_addUserToInternalStore_reset_roles(_addUserToInternalStore, env);

                
                if(NULL == arg_roles)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addUserToInternalStore->property_roles = arg_roles;
                        if(non_nil_exists)
                        {
                            _addUserToInternalStore->is_valid_roles = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of roles.
             */
            axis2_char_t* AXIS2_CALL
            adb_addUserToInternalStore_get_roles_at(
                    adb_addUserToInternalStore_t* _addUserToInternalStore,
                    const axutil_env_t *env, int i)
            {
                axis2_char_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addUserToInternalStore, NULL);
                  

                if(_addUserToInternalStore->property_roles == NULL)
                {
                    return (axis2_char_t*)0;
                }
                ret_val = (axis2_char_t*)axutil_array_list_get(_addUserToInternalStore->property_roles, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of roles.
             */
            axis2_status_t AXIS2_CALL
            adb_addUserToInternalStore_set_roles_at(
                    adb_addUserToInternalStore_t* _addUserToInternalStore,
                    const axutil_env_t *env, int i,
                    const axis2_char_t* arg_roles)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addUserToInternalStore, AXIS2_FAILURE);
                
                if( _addUserToInternalStore->is_valid_roles &&
                    _addUserToInternalStore->property_roles &&
                
                    arg_roles == (axis2_char_t*)axutil_array_list_get(_addUserToInternalStore->property_roles, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_roles)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_addUserToInternalStore->property_roles != NULL)
                        {
                            size = axutil_array_list_size(_addUserToInternalStore->property_roles, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_addUserToInternalStore->property_roles, env, i))
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
                  

                if(_addUserToInternalStore->property_roles == NULL)
                {
                    _addUserToInternalStore->property_roles = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_addUserToInternalStore->property_roles, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _addUserToInternalStore->is_valid_roles = AXIS2_FALSE;
                        axutil_array_list_set(_addUserToInternalStore->property_roles , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_addUserToInternalStore->property_roles , env, i, axutil_strdup(env, arg_roles));
                  _addUserToInternalStore->is_valid_roles = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to roles.
             */
            axis2_status_t AXIS2_CALL
            adb_addUserToInternalStore_add_roles(
                    adb_addUserToInternalStore_t* _addUserToInternalStore,
                    const axutil_env_t *env,
                    const axis2_char_t* arg_roles)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addUserToInternalStore, AXIS2_FAILURE);

                
                    if(NULL == arg_roles)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_addUserToInternalStore->property_roles == NULL)
                {
                    _addUserToInternalStore->property_roles = axutil_array_list_create(env, 10);
                }
                if(_addUserToInternalStore->property_roles == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for roles");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_addUserToInternalStore->property_roles , env, axutil_strdup(env, arg_roles));
                  _addUserToInternalStore->is_valid_roles = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the roles array.
             */
            int AXIS2_CALL
            adb_addUserToInternalStore_sizeof_roles(
                    adb_addUserToInternalStore_t* _addUserToInternalStore,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _addUserToInternalStore, -1);
                if(_addUserToInternalStore->property_roles == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_addUserToInternalStore->property_roles, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_addUserToInternalStore_remove_roles_at(
                    adb_addUserToInternalStore_t* _addUserToInternalStore,
                    const axutil_env_t *env, int i)
            {
                return adb_addUserToInternalStore_set_roles_nil_at(_addUserToInternalStore, env, i);
            }

            

           /**
            * resetter for roles
            */
           axis2_status_t AXIS2_CALL
           adb_addUserToInternalStore_reset_roles(
                   adb_addUserToInternalStore_t* _addUserToInternalStore,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addUserToInternalStore, AXIS2_FAILURE);
               

               
                  if (_addUserToInternalStore->property_roles != NULL)
                  {
                      count = axutil_array_list_size(_addUserToInternalStore->property_roles, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_addUserToInternalStore->property_roles, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, (axis2_char_t*)element);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_addUserToInternalStore->property_roles, env);
                  }
                _addUserToInternalStore->is_valid_roles = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether roles is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addUserToInternalStore_is_roles_nil(
                   adb_addUserToInternalStore_t* _addUserToInternalStore,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addUserToInternalStore, AXIS2_TRUE);
               
               return !_addUserToInternalStore->is_valid_roles;
           }

           /**
            * Set roles to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addUserToInternalStore_set_roles_nil(
                   adb_addUserToInternalStore_t* _addUserToInternalStore,
                   const axutil_env_t *env)
           {
               return adb_addUserToInternalStore_reset_roles(_addUserToInternalStore, env);
           }

           
           /**
            * Check whether roles is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_addUserToInternalStore_is_roles_nil_at(
                   adb_addUserToInternalStore_t* _addUserToInternalStore,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addUserToInternalStore, AXIS2_TRUE);
               
               return (_addUserToInternalStore->is_valid_roles == AXIS2_FALSE ||
                        NULL == _addUserToInternalStore->property_roles || 
                        NULL == axutil_array_list_get(_addUserToInternalStore->property_roles, env, i));
           }

           /**
            * Set roles to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_addUserToInternalStore_set_roles_nil_at(
                   adb_addUserToInternalStore_t* _addUserToInternalStore,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addUserToInternalStore, AXIS2_FAILURE);

                if(_addUserToInternalStore->property_roles == NULL ||
                            _addUserToInternalStore->is_valid_roles == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_addUserToInternalStore->property_roles, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_addUserToInternalStore->property_roles, env, i))
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
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of roles is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_addUserToInternalStore->property_roles == NULL)
                {
                    _addUserToInternalStore->is_valid_roles = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_addUserToInternalStore->property_roles, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _addUserToInternalStore->is_valid_roles = AXIS2_FALSE;
                        axutil_array_list_set(_addUserToInternalStore->property_roles , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_addUserToInternalStore->property_roles , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

