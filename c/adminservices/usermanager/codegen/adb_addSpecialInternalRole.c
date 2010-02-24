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
         * adb_addSpecialInternalRole.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_addSpecialInternalRole.h"
        
               /*
                * implmentation of the addSpecialInternalRole|http://service.mgt.user.carbon.wso2.org element
                */
           


        struct adb_addSpecialInternalRole
        {
            axis2_char_t *property_Type;

            
                axutil_qname_t* qname;
            axis2_char_t* property_roleName;

                
                axis2_bool_t is_valid_roleName;
            axutil_array_list_t* property_userNames;

                
                axis2_bool_t is_valid_userNames;
            axutil_array_list_t* property_permissions;

                
                axis2_bool_t is_valid_permissions;
            
        };


       /************************* Private Function prototypes ********************************/
        


       /************************* Function Implmentations ********************************/
        adb_addSpecialInternalRole_t* AXIS2_CALL
        adb_addSpecialInternalRole_create(
            const axutil_env_t *env)
        {
            adb_addSpecialInternalRole_t *_addSpecialInternalRole = NULL;
            
                axutil_qname_t* qname = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _addSpecialInternalRole = (adb_addSpecialInternalRole_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_addSpecialInternalRole_t));

            if(NULL == _addSpecialInternalRole)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_addSpecialInternalRole, 0, sizeof(adb_addSpecialInternalRole_t));

            _addSpecialInternalRole->property_Type = axutil_strdup(env, "adb_addSpecialInternalRole");
            _addSpecialInternalRole->property_roleName  = NULL;
                  _addSpecialInternalRole->is_valid_roleName  = AXIS2_FALSE;
            _addSpecialInternalRole->property_userNames  = NULL;
                  _addSpecialInternalRole->is_valid_userNames  = AXIS2_FALSE;
            _addSpecialInternalRole->property_permissions  = NULL;
                  _addSpecialInternalRole->is_valid_permissions  = AXIS2_FALSE;
            
                  qname =  axutil_qname_create (env,
                        "addSpecialInternalRole",
                        "http://service.mgt.user.carbon.wso2.org",
                        NULL);
                _addSpecialInternalRole->qname = qname;
            

            return _addSpecialInternalRole;
        }

        adb_addSpecialInternalRole_t* AXIS2_CALL
        adb_addSpecialInternalRole_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _roleName,
                axutil_array_list_t* _userNames,
                axutil_array_list_t* _permissions)
        {
            adb_addSpecialInternalRole_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_addSpecialInternalRole_create(env);

            
              status = adb_addSpecialInternalRole_set_roleName(
                                     adb_obj,
                                     env,
                                     _roleName);
              if(status == AXIS2_FAILURE) {
                  adb_addSpecialInternalRole_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_addSpecialInternalRole_set_userNames(
                                     adb_obj,
                                     env,
                                     _userNames);
              if(status == AXIS2_FAILURE) {
                  adb_addSpecialInternalRole_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_addSpecialInternalRole_set_permissions(
                                     adb_obj,
                                     env,
                                     _permissions);
              if(status == AXIS2_FAILURE) {
                  adb_addSpecialInternalRole_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_char_t* AXIS2_CALL
                adb_addSpecialInternalRole_free_popping_value(
                        adb_addSpecialInternalRole_t* _addSpecialInternalRole,
                        const axutil_env_t *env)
                {
                    axis2_char_t* value;

                    
                    
                    value = _addSpecialInternalRole->property_roleName;

                    _addSpecialInternalRole->property_roleName = (axis2_char_t*)NULL;
                    adb_addSpecialInternalRole_free(_addSpecialInternalRole, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_addSpecialInternalRole_free(
                adb_addSpecialInternalRole_t* _addSpecialInternalRole,
                const axutil_env_t *env)
        {
            
            
            return adb_addSpecialInternalRole_free_obj(
                _addSpecialInternalRole,
                env);
            
        }

        axis2_status_t AXIS2_CALL
        adb_addSpecialInternalRole_free_obj(
                adb_addSpecialInternalRole_t* _addSpecialInternalRole,
                const axutil_env_t *env)
        {
            
                int i = 0;
                int count = 0;
                void *element = NULL;
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _addSpecialInternalRole, AXIS2_FAILURE);

            if (_addSpecialInternalRole->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _addSpecialInternalRole->property_Type);
            }

            adb_addSpecialInternalRole_reset_roleName(_addSpecialInternalRole, env);
            adb_addSpecialInternalRole_reset_userNames(_addSpecialInternalRole, env);
            adb_addSpecialInternalRole_reset_permissions(_addSpecialInternalRole, env);
            
              if(_addSpecialInternalRole->qname)
              {
                  axutil_qname_free (_addSpecialInternalRole->qname, env);
                  _addSpecialInternalRole->qname = NULL;
              }
            

            if(_addSpecialInternalRole)
            {
                AXIS2_FREE(env->allocator, _addSpecialInternalRole);
                _addSpecialInternalRole = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_addSpecialInternalRole_deserialize(
                adb_addSpecialInternalRole_t* _addSpecialInternalRole,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return adb_addSpecialInternalRole_deserialize_obj(
                _addSpecialInternalRole,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs);
            
        }

        axis2_status_t AXIS2_CALL
        adb_addSpecialInternalRole_deserialize_obj(
                adb_addSpecialInternalRole_t* _addSpecialInternalRole,
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
            AXIS2_PARAM_CHECK(env->error, _addSpecialInternalRole, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for addSpecialInternalRole : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              

                    current_element = (axiom_element_t *)axiom_node_get_data_element(parent, env);
                    qname = axiom_element_get_qname(current_element, env, parent);
                    if (axutil_qname_equals(qname, env, _addSpecialInternalRole-> qname))
                    {
                        
                          first_node = axiom_node_get_first_child(parent, env);
                          
                    }
                    else
                    {
                        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                              "Failed in building adb object for addSpecialInternalRole : "
                              "Expected %s but returned %s",
                              axutil_qname_to_string(_addSpecialInternalRole-> qname, env),
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
                                            status = adb_addSpecialInternalRole_set_roleName(_addSpecialInternalRole, env,
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
                     * building userNames array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building userNames element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "userNames", "http://service.mgt.user.carbon.wso2.org", NULL);
                                  
                               
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
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for userNames ");
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
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "userNames (@minOccurs = '0') only have %d elements", i);
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
                                    status = adb_addSpecialInternalRole_set_userNames(_addSpecialInternalRole, env,
                                                                   arr_list);
                               }

                             
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 
                    /*
                     * building permissions array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building permissions element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "permissions", "http://service.mgt.user.carbon.wso2.org", NULL);
                                  
                               
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
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for permissions ");
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
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "permissions (@minOccurs = '0') only have %d elements", i);
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
                                    status = adb_addSpecialInternalRole_set_permissions(_addSpecialInternalRole, env,
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
          adb_addSpecialInternalRole_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_addSpecialInternalRole_declare_parent_namespaces(
                    adb_addSpecialInternalRole_t* _addSpecialInternalRole,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_addSpecialInternalRole_serialize(
                adb_addSpecialInternalRole_t* _addSpecialInternalRole,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
                return adb_addSpecialInternalRole_serialize_obj(
                    _addSpecialInternalRole, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            
        }

        axiom_node_t* AXIS2_CALL
        adb_addSpecialInternalRole_serialize_obj(
                adb_addSpecialInternalRole_t* _addSpecialInternalRole,
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
            AXIS2_PARAM_CHECK(env->error, _addSpecialInternalRole, NULL);
            
             
                    namespaces = axutil_hash_make(env);
                    next_ns_index = &next_ns_index_value;
                     
                           ns1 = axiom_namespace_create (env,
                                             "http://service.mgt.user.carbon.wso2.org",
                                             "n"); 
                           axutil_hash_set(namespaces, "http://service.mgt.user.carbon.wso2.org", AXIS2_HASH_KEY_STRING, axutil_strdup(env, "n"));
                       
                     
                    parent_element = axiom_element_create (env, NULL, "addSpecialInternalRole", ns1 , &parent);
                    
                    
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
                      

                   if (!_addSpecialInternalRole->is_valid_roleName)
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
                    
                           text_value_1 = _addSpecialInternalRole->property_roleName;
                           
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
                      

                   if (!_addSpecialInternalRole->is_valid_userNames)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("userNames"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("userNames")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing userNames array
                      */
                     if (_addSpecialInternalRole->property_userNames != NULL)
                     {
                        
                            sprintf(start_input_str, "<%s%suserNames>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%suserNames>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_addSpecialInternalRole->property_userNames, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_addSpecialInternalRole->property_userNames, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing userNames element
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.mgt.user.carbon.wso2.org", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.mgt.user.carbon.wso2.org", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.mgt.user.carbon.wso2.org",
                                            p_prefix));
                       }
                      

                   if (!_addSpecialInternalRole->is_valid_permissions)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("permissions"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("permissions")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing permissions array
                      */
                     if (_addSpecialInternalRole->property_permissions != NULL)
                     {
                        
                            sprintf(start_input_str, "<%s%spermissions>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%spermissions>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_addSpecialInternalRole->property_permissions, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_addSpecialInternalRole->property_permissions, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing permissions element
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
             * Getter for roleName by  Property Number 1
             */
            axis2_char_t* AXIS2_CALL
            adb_addSpecialInternalRole_get_property1(
                adb_addSpecialInternalRole_t* _addSpecialInternalRole,
                const axutil_env_t *env)
            {
                return adb_addSpecialInternalRole_get_roleName(_addSpecialInternalRole,
                                             env);
            }

            /**
             * getter for roleName.
             */
            axis2_char_t* AXIS2_CALL
            adb_addSpecialInternalRole_get_roleName(
                    adb_addSpecialInternalRole_t* _addSpecialInternalRole,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addSpecialInternalRole, NULL);
                  

                return _addSpecialInternalRole->property_roleName;
             }

            /**
             * setter for roleName
             */
            axis2_status_t AXIS2_CALL
            adb_addSpecialInternalRole_set_roleName(
                    adb_addSpecialInternalRole_t* _addSpecialInternalRole,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_roleName)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addSpecialInternalRole, AXIS2_FAILURE);
                
                if(_addSpecialInternalRole->is_valid_roleName &&
                        arg_roleName == _addSpecialInternalRole->property_roleName)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_addSpecialInternalRole_reset_roleName(_addSpecialInternalRole, env);

                
                if(NULL == arg_roleName)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addSpecialInternalRole->property_roleName = (axis2_char_t *)axutil_strdup(env, arg_roleName);
                        if(NULL == _addSpecialInternalRole->property_roleName)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for roleName");
                            return AXIS2_FAILURE;
                        }
                        _addSpecialInternalRole->is_valid_roleName = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for roleName
            */
           axis2_status_t AXIS2_CALL
           adb_addSpecialInternalRole_reset_roleName(
                   adb_addSpecialInternalRole_t* _addSpecialInternalRole,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addSpecialInternalRole, AXIS2_FAILURE);
               

               
            
                
                if(_addSpecialInternalRole->property_roleName != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _addSpecialInternalRole->property_roleName);
                     _addSpecialInternalRole->property_roleName = NULL;
                }
            
                
                
                _addSpecialInternalRole->is_valid_roleName = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether roleName is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addSpecialInternalRole_is_roleName_nil(
                   adb_addSpecialInternalRole_t* _addSpecialInternalRole,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addSpecialInternalRole, AXIS2_TRUE);
               
               return !_addSpecialInternalRole->is_valid_roleName;
           }

           /**
            * Set roleName to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addSpecialInternalRole_set_roleName_nil(
                   adb_addSpecialInternalRole_t* _addSpecialInternalRole,
                   const axutil_env_t *env)
           {
               return adb_addSpecialInternalRole_reset_roleName(_addSpecialInternalRole, env);
           }

           

            /**
             * Getter for userNames by  Property Number 2
             */
            axutil_array_list_t* AXIS2_CALL
            adb_addSpecialInternalRole_get_property2(
                adb_addSpecialInternalRole_t* _addSpecialInternalRole,
                const axutil_env_t *env)
            {
                return adb_addSpecialInternalRole_get_userNames(_addSpecialInternalRole,
                                             env);
            }

            /**
             * getter for userNames.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_addSpecialInternalRole_get_userNames(
                    adb_addSpecialInternalRole_t* _addSpecialInternalRole,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addSpecialInternalRole, NULL);
                  

                return _addSpecialInternalRole->property_userNames;
             }

            /**
             * setter for userNames
             */
            axis2_status_t AXIS2_CALL
            adb_addSpecialInternalRole_set_userNames(
                    adb_addSpecialInternalRole_t* _addSpecialInternalRole,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_userNames)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addSpecialInternalRole, AXIS2_FAILURE);
                
                if(_addSpecialInternalRole->is_valid_userNames &&
                        arg_userNames == _addSpecialInternalRole->property_userNames)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_userNames, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "userNames has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_userNames, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_addSpecialInternalRole_reset_userNames(_addSpecialInternalRole, env);

                
                if(NULL == arg_userNames)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addSpecialInternalRole->property_userNames = arg_userNames;
                        if(non_nil_exists)
                        {
                            _addSpecialInternalRole->is_valid_userNames = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of userNames.
             */
            axis2_char_t* AXIS2_CALL
            adb_addSpecialInternalRole_get_userNames_at(
                    adb_addSpecialInternalRole_t* _addSpecialInternalRole,
                    const axutil_env_t *env, int i)
            {
                axis2_char_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addSpecialInternalRole, NULL);
                  

                if(_addSpecialInternalRole->property_userNames == NULL)
                {
                    return (axis2_char_t*)0;
                }
                ret_val = (axis2_char_t*)axutil_array_list_get(_addSpecialInternalRole->property_userNames, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of userNames.
             */
            axis2_status_t AXIS2_CALL
            adb_addSpecialInternalRole_set_userNames_at(
                    adb_addSpecialInternalRole_t* _addSpecialInternalRole,
                    const axutil_env_t *env, int i,
                    const axis2_char_t* arg_userNames)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addSpecialInternalRole, AXIS2_FAILURE);
                
                if( _addSpecialInternalRole->is_valid_userNames &&
                    _addSpecialInternalRole->property_userNames &&
                
                    arg_userNames == (axis2_char_t*)axutil_array_list_get(_addSpecialInternalRole->property_userNames, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_userNames)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_addSpecialInternalRole->property_userNames != NULL)
                        {
                            size = axutil_array_list_size(_addSpecialInternalRole->property_userNames, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_addSpecialInternalRole->property_userNames, env, i))
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
                  

                if(_addSpecialInternalRole->property_userNames == NULL)
                {
                    _addSpecialInternalRole->property_userNames = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_addSpecialInternalRole->property_userNames, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _addSpecialInternalRole->is_valid_userNames = AXIS2_FALSE;
                        axutil_array_list_set(_addSpecialInternalRole->property_userNames , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_addSpecialInternalRole->property_userNames , env, i, axutil_strdup(env, arg_userNames));
                  _addSpecialInternalRole->is_valid_userNames = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to userNames.
             */
            axis2_status_t AXIS2_CALL
            adb_addSpecialInternalRole_add_userNames(
                    adb_addSpecialInternalRole_t* _addSpecialInternalRole,
                    const axutil_env_t *env,
                    const axis2_char_t* arg_userNames)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addSpecialInternalRole, AXIS2_FAILURE);

                
                    if(NULL == arg_userNames)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_addSpecialInternalRole->property_userNames == NULL)
                {
                    _addSpecialInternalRole->property_userNames = axutil_array_list_create(env, 10);
                }
                if(_addSpecialInternalRole->property_userNames == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for userNames");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_addSpecialInternalRole->property_userNames , env, axutil_strdup(env, arg_userNames));
                  _addSpecialInternalRole->is_valid_userNames = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the userNames array.
             */
            int AXIS2_CALL
            adb_addSpecialInternalRole_sizeof_userNames(
                    adb_addSpecialInternalRole_t* _addSpecialInternalRole,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _addSpecialInternalRole, -1);
                if(_addSpecialInternalRole->property_userNames == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_addSpecialInternalRole->property_userNames, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_addSpecialInternalRole_remove_userNames_at(
                    adb_addSpecialInternalRole_t* _addSpecialInternalRole,
                    const axutil_env_t *env, int i)
            {
                return adb_addSpecialInternalRole_set_userNames_nil_at(_addSpecialInternalRole, env, i);
            }

            

           /**
            * resetter for userNames
            */
           axis2_status_t AXIS2_CALL
           adb_addSpecialInternalRole_reset_userNames(
                   adb_addSpecialInternalRole_t* _addSpecialInternalRole,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addSpecialInternalRole, AXIS2_FAILURE);
               

               
                  if (_addSpecialInternalRole->property_userNames != NULL)
                  {
                      count = axutil_array_list_size(_addSpecialInternalRole->property_userNames, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_addSpecialInternalRole->property_userNames, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, (axis2_char_t*)element);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_addSpecialInternalRole->property_userNames, env);
                  }
                _addSpecialInternalRole->is_valid_userNames = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether userNames is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addSpecialInternalRole_is_userNames_nil(
                   adb_addSpecialInternalRole_t* _addSpecialInternalRole,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addSpecialInternalRole, AXIS2_TRUE);
               
               return !_addSpecialInternalRole->is_valid_userNames;
           }

           /**
            * Set userNames to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addSpecialInternalRole_set_userNames_nil(
                   adb_addSpecialInternalRole_t* _addSpecialInternalRole,
                   const axutil_env_t *env)
           {
               return adb_addSpecialInternalRole_reset_userNames(_addSpecialInternalRole, env);
           }

           
           /**
            * Check whether userNames is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_addSpecialInternalRole_is_userNames_nil_at(
                   adb_addSpecialInternalRole_t* _addSpecialInternalRole,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addSpecialInternalRole, AXIS2_TRUE);
               
               return (_addSpecialInternalRole->is_valid_userNames == AXIS2_FALSE ||
                        NULL == _addSpecialInternalRole->property_userNames || 
                        NULL == axutil_array_list_get(_addSpecialInternalRole->property_userNames, env, i));
           }

           /**
            * Set userNames to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_addSpecialInternalRole_set_userNames_nil_at(
                   adb_addSpecialInternalRole_t* _addSpecialInternalRole,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addSpecialInternalRole, AXIS2_FAILURE);

                if(_addSpecialInternalRole->property_userNames == NULL ||
                            _addSpecialInternalRole->is_valid_userNames == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_addSpecialInternalRole->property_userNames, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_addSpecialInternalRole->property_userNames, env, i))
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
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of userNames is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_addSpecialInternalRole->property_userNames == NULL)
                {
                    _addSpecialInternalRole->is_valid_userNames = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_addSpecialInternalRole->property_userNames, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _addSpecialInternalRole->is_valid_userNames = AXIS2_FALSE;
                        axutil_array_list_set(_addSpecialInternalRole->property_userNames , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_addSpecialInternalRole->property_userNames , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

            /**
             * Getter for permissions by  Property Number 3
             */
            axutil_array_list_t* AXIS2_CALL
            adb_addSpecialInternalRole_get_property3(
                adb_addSpecialInternalRole_t* _addSpecialInternalRole,
                const axutil_env_t *env)
            {
                return adb_addSpecialInternalRole_get_permissions(_addSpecialInternalRole,
                                             env);
            }

            /**
             * getter for permissions.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_addSpecialInternalRole_get_permissions(
                    adb_addSpecialInternalRole_t* _addSpecialInternalRole,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addSpecialInternalRole, NULL);
                  

                return _addSpecialInternalRole->property_permissions;
             }

            /**
             * setter for permissions
             */
            axis2_status_t AXIS2_CALL
            adb_addSpecialInternalRole_set_permissions(
                    adb_addSpecialInternalRole_t* _addSpecialInternalRole,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_permissions)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addSpecialInternalRole, AXIS2_FAILURE);
                
                if(_addSpecialInternalRole->is_valid_permissions &&
                        arg_permissions == _addSpecialInternalRole->property_permissions)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_permissions, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "permissions has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_permissions, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_addSpecialInternalRole_reset_permissions(_addSpecialInternalRole, env);

                
                if(NULL == arg_permissions)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addSpecialInternalRole->property_permissions = arg_permissions;
                        if(non_nil_exists)
                        {
                            _addSpecialInternalRole->is_valid_permissions = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of permissions.
             */
            axis2_char_t* AXIS2_CALL
            adb_addSpecialInternalRole_get_permissions_at(
                    adb_addSpecialInternalRole_t* _addSpecialInternalRole,
                    const axutil_env_t *env, int i)
            {
                axis2_char_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addSpecialInternalRole, NULL);
                  

                if(_addSpecialInternalRole->property_permissions == NULL)
                {
                    return (axis2_char_t*)0;
                }
                ret_val = (axis2_char_t*)axutil_array_list_get(_addSpecialInternalRole->property_permissions, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of permissions.
             */
            axis2_status_t AXIS2_CALL
            adb_addSpecialInternalRole_set_permissions_at(
                    adb_addSpecialInternalRole_t* _addSpecialInternalRole,
                    const axutil_env_t *env, int i,
                    const axis2_char_t* arg_permissions)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addSpecialInternalRole, AXIS2_FAILURE);
                
                if( _addSpecialInternalRole->is_valid_permissions &&
                    _addSpecialInternalRole->property_permissions &&
                
                    arg_permissions == (axis2_char_t*)axutil_array_list_get(_addSpecialInternalRole->property_permissions, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_permissions)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_addSpecialInternalRole->property_permissions != NULL)
                        {
                            size = axutil_array_list_size(_addSpecialInternalRole->property_permissions, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_addSpecialInternalRole->property_permissions, env, i))
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
                  

                if(_addSpecialInternalRole->property_permissions == NULL)
                {
                    _addSpecialInternalRole->property_permissions = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_addSpecialInternalRole->property_permissions, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _addSpecialInternalRole->is_valid_permissions = AXIS2_FALSE;
                        axutil_array_list_set(_addSpecialInternalRole->property_permissions , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_addSpecialInternalRole->property_permissions , env, i, axutil_strdup(env, arg_permissions));
                  _addSpecialInternalRole->is_valid_permissions = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to permissions.
             */
            axis2_status_t AXIS2_CALL
            adb_addSpecialInternalRole_add_permissions(
                    adb_addSpecialInternalRole_t* _addSpecialInternalRole,
                    const axutil_env_t *env,
                    const axis2_char_t* arg_permissions)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addSpecialInternalRole, AXIS2_FAILURE);

                
                    if(NULL == arg_permissions)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_addSpecialInternalRole->property_permissions == NULL)
                {
                    _addSpecialInternalRole->property_permissions = axutil_array_list_create(env, 10);
                }
                if(_addSpecialInternalRole->property_permissions == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for permissions");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_addSpecialInternalRole->property_permissions , env, axutil_strdup(env, arg_permissions));
                  _addSpecialInternalRole->is_valid_permissions = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the permissions array.
             */
            int AXIS2_CALL
            adb_addSpecialInternalRole_sizeof_permissions(
                    adb_addSpecialInternalRole_t* _addSpecialInternalRole,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _addSpecialInternalRole, -1);
                if(_addSpecialInternalRole->property_permissions == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_addSpecialInternalRole->property_permissions, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_addSpecialInternalRole_remove_permissions_at(
                    adb_addSpecialInternalRole_t* _addSpecialInternalRole,
                    const axutil_env_t *env, int i)
            {
                return adb_addSpecialInternalRole_set_permissions_nil_at(_addSpecialInternalRole, env, i);
            }

            

           /**
            * resetter for permissions
            */
           axis2_status_t AXIS2_CALL
           adb_addSpecialInternalRole_reset_permissions(
                   adb_addSpecialInternalRole_t* _addSpecialInternalRole,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addSpecialInternalRole, AXIS2_FAILURE);
               

               
                  if (_addSpecialInternalRole->property_permissions != NULL)
                  {
                      count = axutil_array_list_size(_addSpecialInternalRole->property_permissions, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_addSpecialInternalRole->property_permissions, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, (axis2_char_t*)element);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_addSpecialInternalRole->property_permissions, env);
                  }
                _addSpecialInternalRole->is_valid_permissions = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether permissions is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addSpecialInternalRole_is_permissions_nil(
                   adb_addSpecialInternalRole_t* _addSpecialInternalRole,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addSpecialInternalRole, AXIS2_TRUE);
               
               return !_addSpecialInternalRole->is_valid_permissions;
           }

           /**
            * Set permissions to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addSpecialInternalRole_set_permissions_nil(
                   adb_addSpecialInternalRole_t* _addSpecialInternalRole,
                   const axutil_env_t *env)
           {
               return adb_addSpecialInternalRole_reset_permissions(_addSpecialInternalRole, env);
           }

           
           /**
            * Check whether permissions is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_addSpecialInternalRole_is_permissions_nil_at(
                   adb_addSpecialInternalRole_t* _addSpecialInternalRole,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addSpecialInternalRole, AXIS2_TRUE);
               
               return (_addSpecialInternalRole->is_valid_permissions == AXIS2_FALSE ||
                        NULL == _addSpecialInternalRole->property_permissions || 
                        NULL == axutil_array_list_get(_addSpecialInternalRole->property_permissions, env, i));
           }

           /**
            * Set permissions to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_addSpecialInternalRole_set_permissions_nil_at(
                   adb_addSpecialInternalRole_t* _addSpecialInternalRole,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addSpecialInternalRole, AXIS2_FAILURE);

                if(_addSpecialInternalRole->property_permissions == NULL ||
                            _addSpecialInternalRole->is_valid_permissions == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_addSpecialInternalRole->property_permissions, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_addSpecialInternalRole->property_permissions, env, i))
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
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of permissions is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_addSpecialInternalRole->property_permissions == NULL)
                {
                    _addSpecialInternalRole->is_valid_permissions = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_addSpecialInternalRole->property_permissions, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _addSpecialInternalRole->is_valid_permissions = AXIS2_FALSE;
                        axutil_array_list_set(_addSpecialInternalRole->property_permissions , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_addSpecialInternalRole->property_permissions , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

