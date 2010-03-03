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
         * adb_updateRolesofResource.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_updateRolesofResource.h"
        
               /*
                * implmentation of the updateRolesofResource|http://service.mgt.user.carbon.wso2.org element
                */
           


        struct adb_updateRolesofResource
        {
            axis2_char_t *property_Type;

            
                axutil_qname_t* qname;
            axutil_array_list_t* property_roleNames;

                
                axis2_bool_t is_valid_roleNames;
            axis2_char_t* property_resource;

                
                axis2_bool_t is_valid_resource;
            axis2_char_t* property_action;

                
                axis2_bool_t is_valid_action;
            
        };


       /************************* Private Function prototypes ********************************/
        


       /************************* Function Implmentations ********************************/
        adb_updateRolesofResource_t* AXIS2_CALL
        adb_updateRolesofResource_create(
            const axutil_env_t *env)
        {
            adb_updateRolesofResource_t *_updateRolesofResource = NULL;
            
                axutil_qname_t* qname = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _updateRolesofResource = (adb_updateRolesofResource_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_updateRolesofResource_t));

            if(NULL == _updateRolesofResource)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_updateRolesofResource, 0, sizeof(adb_updateRolesofResource_t));

            _updateRolesofResource->property_Type = axutil_strdup(env, "adb_updateRolesofResource");
            _updateRolesofResource->property_roleNames  = NULL;
                  _updateRolesofResource->is_valid_roleNames  = AXIS2_FALSE;
            _updateRolesofResource->property_resource  = NULL;
                  _updateRolesofResource->is_valid_resource  = AXIS2_FALSE;
            _updateRolesofResource->property_action  = NULL;
                  _updateRolesofResource->is_valid_action  = AXIS2_FALSE;
            
                  qname =  axutil_qname_create (env,
                        "updateRolesofResource",
                        "http://service.mgt.user.carbon.wso2.org",
                        NULL);
                _updateRolesofResource->qname = qname;
            

            return _updateRolesofResource;
        }

        adb_updateRolesofResource_t* AXIS2_CALL
        adb_updateRolesofResource_create_with_values(
            const axutil_env_t *env,
                axutil_array_list_t* _roleNames,
                axis2_char_t* _resource,
                axis2_char_t* _action)
        {
            adb_updateRolesofResource_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_updateRolesofResource_create(env);

            
              status = adb_updateRolesofResource_set_roleNames(
                                     adb_obj,
                                     env,
                                     _roleNames);
              if(status == AXIS2_FAILURE) {
                  adb_updateRolesofResource_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_updateRolesofResource_set_resource(
                                     adb_obj,
                                     env,
                                     _resource);
              if(status == AXIS2_FAILURE) {
                  adb_updateRolesofResource_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_updateRolesofResource_set_action(
                                     adb_obj,
                                     env,
                                     _action);
              if(status == AXIS2_FAILURE) {
                  adb_updateRolesofResource_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axutil_array_list_t* AXIS2_CALL
                adb_updateRolesofResource_free_popping_value(
                        adb_updateRolesofResource_t* _updateRolesofResource,
                        const axutil_env_t *env)
                {
                    axutil_array_list_t* value;

                    
                    
                    value = _updateRolesofResource->property_roleNames;

                    _updateRolesofResource->property_roleNames = (axutil_array_list_t*)NULL;
                    adb_updateRolesofResource_free(_updateRolesofResource, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_updateRolesofResource_free(
                adb_updateRolesofResource_t* _updateRolesofResource,
                const axutil_env_t *env)
        {
            
            
            return adb_updateRolesofResource_free_obj(
                _updateRolesofResource,
                env);
            
        }

        axis2_status_t AXIS2_CALL
        adb_updateRolesofResource_free_obj(
                adb_updateRolesofResource_t* _updateRolesofResource,
                const axutil_env_t *env)
        {
            
                int i = 0;
                int count = 0;
                void *element = NULL;
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _updateRolesofResource, AXIS2_FAILURE);

            if (_updateRolesofResource->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _updateRolesofResource->property_Type);
            }

            adb_updateRolesofResource_reset_roleNames(_updateRolesofResource, env);
            adb_updateRolesofResource_reset_resource(_updateRolesofResource, env);
            adb_updateRolesofResource_reset_action(_updateRolesofResource, env);
            
              if(_updateRolesofResource->qname)
              {
                  axutil_qname_free (_updateRolesofResource->qname, env);
                  _updateRolesofResource->qname = NULL;
              }
            

            if(_updateRolesofResource)
            {
                AXIS2_FREE(env->allocator, _updateRolesofResource);
                _updateRolesofResource = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_updateRolesofResource_deserialize(
                adb_updateRolesofResource_t* _updateRolesofResource,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return adb_updateRolesofResource_deserialize_obj(
                _updateRolesofResource,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs);
            
        }

        axis2_status_t AXIS2_CALL
        adb_updateRolesofResource_deserialize_obj(
                adb_updateRolesofResource_t* _updateRolesofResource,
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
            AXIS2_PARAM_CHECK(env->error, _updateRolesofResource, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for updateRolesofResource : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              

                    current_element = (axiom_element_t *)axiom_node_get_data_element(parent, env);
                    qname = axiom_element_get_qname(current_element, env, parent);
                    if (axutil_qname_equals(qname, env, _updateRolesofResource-> qname))
                    {
                        
                          first_node = axiom_node_get_first_child(parent, env);
                          
                    }
                    else
                    {
                        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                              "Failed in building adb object for updateRolesofResource : "
                              "Expected %s but returned %s",
                              axutil_qname_to_string(_updateRolesofResource-> qname, env),
                              axutil_qname_to_string(qname, env));
                        
                        return AXIS2_FAILURE;
                    }
                    
                    /*
                     * building roleNames array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building roleNames element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "roleNames", "http://service.mgt.user.carbon.wso2.org", NULL);
                                  
                               
                               for (i = 0, sequence_broken = 0, current_node = first_node; !sequence_broken && current_node != NULL;) 
                                             
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
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for roleNames ");
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
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "roleNames (@minOccurs = '0') only have %d elements", i);
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
                                    status = adb_updateRolesofResource_set_roleNames(_updateRolesofResource, env,
                                                                   arr_list);
                               }

                             
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 

                     
                     /*
                      * building resource element
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
                                 
                                 element_qname = axutil_qname_create(env, "resource", "http://service.mgt.user.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_updateRolesofResource_set_resource(_updateRolesofResource, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for resource ");
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
                      * building action element
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
                                 
                                 element_qname = axutil_qname_create(env, "action", "http://service.mgt.user.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_updateRolesofResource_set_action(_updateRolesofResource, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for action ");
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
          adb_updateRolesofResource_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_updateRolesofResource_declare_parent_namespaces(
                    adb_updateRolesofResource_t* _updateRolesofResource,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_updateRolesofResource_serialize(
                adb_updateRolesofResource_t* _updateRolesofResource,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
                return adb_updateRolesofResource_serialize_obj(
                    _updateRolesofResource, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            
        }

        axiom_node_t* AXIS2_CALL
        adb_updateRolesofResource_serialize_obj(
                adb_updateRolesofResource_t* _updateRolesofResource,
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
            AXIS2_PARAM_CHECK(env->error, _updateRolesofResource, NULL);
            
             
                    namespaces = axutil_hash_make(env);
                    next_ns_index = &next_ns_index_value;
                     
                           ns1 = axiom_namespace_create (env,
                                             "http://service.mgt.user.carbon.wso2.org",
                                             "n"); 
                           axutil_hash_set(namespaces, "http://service.mgt.user.carbon.wso2.org", AXIS2_HASH_KEY_STRING, axutil_strdup(env, "n"));
                       
                     
                    parent_element = axiom_element_create (env, NULL, "updateRolesofResource", ns1 , &parent);
                    
                    
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
                      

                   if (!_updateRolesofResource->is_valid_roleNames)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("roleNames"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("roleNames")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing roleNames array
                      */
                     if (_updateRolesofResource->property_roleNames != NULL)
                     {
                        
                            sprintf(start_input_str, "<%s%sroleNames>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%sroleNames>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_updateRolesofResource->property_roleNames, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_updateRolesofResource->property_roleNames, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing roleNames element
                      */

                    
                    
                           text_value_1 = (axis2_char_t*)element;
                           
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
                      

                   if (!_updateRolesofResource->is_valid_resource)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("resource"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("resource")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing resource element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sresource>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sresource>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_2 = _updateRolesofResource->property_resource;
                           
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
                      

                   if (!_updateRolesofResource->is_valid_action)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("action"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("action")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing action element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%saction>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%saction>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_3 = _updateRolesofResource->property_action;
                           
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
             * Getter for roleNames by  Property Number 1
             */
            axutil_array_list_t* AXIS2_CALL
            adb_updateRolesofResource_get_property1(
                adb_updateRolesofResource_t* _updateRolesofResource,
                const axutil_env_t *env)
            {
                return adb_updateRolesofResource_get_roleNames(_updateRolesofResource,
                                             env);
            }

            /**
             * getter for roleNames.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_updateRolesofResource_get_roleNames(
                    adb_updateRolesofResource_t* _updateRolesofResource,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _updateRolesofResource, NULL);
                  

                return _updateRolesofResource->property_roleNames;
             }

            /**
             * setter for roleNames
             */
            axis2_status_t AXIS2_CALL
            adb_updateRolesofResource_set_roleNames(
                    adb_updateRolesofResource_t* _updateRolesofResource,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_roleNames)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _updateRolesofResource, AXIS2_FAILURE);
                
                if(_updateRolesofResource->is_valid_roleNames &&
                        arg_roleNames == _updateRolesofResource->property_roleNames)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_roleNames, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "roleNames has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_roleNames, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_updateRolesofResource_reset_roleNames(_updateRolesofResource, env);

                
                if(NULL == arg_roleNames)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _updateRolesofResource->property_roleNames = arg_roleNames;
                        if(non_nil_exists)
                        {
                            _updateRolesofResource->is_valid_roleNames = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of roleNames.
             */
            axis2_char_t* AXIS2_CALL
            adb_updateRolesofResource_get_roleNames_at(
                    adb_updateRolesofResource_t* _updateRolesofResource,
                    const axutil_env_t *env, int i)
            {
                axis2_char_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _updateRolesofResource, NULL);
                  

                if(_updateRolesofResource->property_roleNames == NULL)
                {
                    return (axis2_char_t*)0;
                }
                ret_val = (axis2_char_t*)axutil_array_list_get(_updateRolesofResource->property_roleNames, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of roleNames.
             */
            axis2_status_t AXIS2_CALL
            adb_updateRolesofResource_set_roleNames_at(
                    adb_updateRolesofResource_t* _updateRolesofResource,
                    const axutil_env_t *env, int i,
                    const axis2_char_t* arg_roleNames)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _updateRolesofResource, AXIS2_FAILURE);
                
                if( _updateRolesofResource->is_valid_roleNames &&
                    _updateRolesofResource->property_roleNames &&
                
                    arg_roleNames == (axis2_char_t*)axutil_array_list_get(_updateRolesofResource->property_roleNames, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_roleNames)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_updateRolesofResource->property_roleNames != NULL)
                        {
                            size = axutil_array_list_size(_updateRolesofResource->property_roleNames, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_updateRolesofResource->property_roleNames, env, i))
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
                  

                if(_updateRolesofResource->property_roleNames == NULL)
                {
                    _updateRolesofResource->property_roleNames = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_updateRolesofResource->property_roleNames, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _updateRolesofResource->is_valid_roleNames = AXIS2_FALSE;
                        axutil_array_list_set(_updateRolesofResource->property_roleNames , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_updateRolesofResource->property_roleNames , env, i, axutil_strdup(env, arg_roleNames));
                  _updateRolesofResource->is_valid_roleNames = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to roleNames.
             */
            axis2_status_t AXIS2_CALL
            adb_updateRolesofResource_add_roleNames(
                    adb_updateRolesofResource_t* _updateRolesofResource,
                    const axutil_env_t *env,
                    const axis2_char_t* arg_roleNames)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _updateRolesofResource, AXIS2_FAILURE);

                
                    if(NULL == arg_roleNames)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_updateRolesofResource->property_roleNames == NULL)
                {
                    _updateRolesofResource->property_roleNames = axutil_array_list_create(env, 10);
                }
                if(_updateRolesofResource->property_roleNames == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for roleNames");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_updateRolesofResource->property_roleNames , env, axutil_strdup(env, arg_roleNames));
                  _updateRolesofResource->is_valid_roleNames = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the roleNames array.
             */
            int AXIS2_CALL
            adb_updateRolesofResource_sizeof_roleNames(
                    adb_updateRolesofResource_t* _updateRolesofResource,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _updateRolesofResource, -1);
                if(_updateRolesofResource->property_roleNames == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_updateRolesofResource->property_roleNames, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_updateRolesofResource_remove_roleNames_at(
                    adb_updateRolesofResource_t* _updateRolesofResource,
                    const axutil_env_t *env, int i)
            {
                return adb_updateRolesofResource_set_roleNames_nil_at(_updateRolesofResource, env, i);
            }

            

           /**
            * resetter for roleNames
            */
           axis2_status_t AXIS2_CALL
           adb_updateRolesofResource_reset_roleNames(
                   adb_updateRolesofResource_t* _updateRolesofResource,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _updateRolesofResource, AXIS2_FAILURE);
               

               
                  if (_updateRolesofResource->property_roleNames != NULL)
                  {
                      count = axutil_array_list_size(_updateRolesofResource->property_roleNames, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_updateRolesofResource->property_roleNames, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, (axis2_char_t*)element);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_updateRolesofResource->property_roleNames, env);
                  }
                _updateRolesofResource->is_valid_roleNames = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether roleNames is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_updateRolesofResource_is_roleNames_nil(
                   adb_updateRolesofResource_t* _updateRolesofResource,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _updateRolesofResource, AXIS2_TRUE);
               
               return !_updateRolesofResource->is_valid_roleNames;
           }

           /**
            * Set roleNames to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_updateRolesofResource_set_roleNames_nil(
                   adb_updateRolesofResource_t* _updateRolesofResource,
                   const axutil_env_t *env)
           {
               return adb_updateRolesofResource_reset_roleNames(_updateRolesofResource, env);
           }

           
           /**
            * Check whether roleNames is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_updateRolesofResource_is_roleNames_nil_at(
                   adb_updateRolesofResource_t* _updateRolesofResource,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _updateRolesofResource, AXIS2_TRUE);
               
               return (_updateRolesofResource->is_valid_roleNames == AXIS2_FALSE ||
                        NULL == _updateRolesofResource->property_roleNames || 
                        NULL == axutil_array_list_get(_updateRolesofResource->property_roleNames, env, i));
           }

           /**
            * Set roleNames to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_updateRolesofResource_set_roleNames_nil_at(
                   adb_updateRolesofResource_t* _updateRolesofResource,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _updateRolesofResource, AXIS2_FAILURE);

                if(_updateRolesofResource->property_roleNames == NULL ||
                            _updateRolesofResource->is_valid_roleNames == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_updateRolesofResource->property_roleNames, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_updateRolesofResource->property_roleNames, env, i))
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
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of roleNames is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_updateRolesofResource->property_roleNames == NULL)
                {
                    _updateRolesofResource->is_valid_roleNames = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_updateRolesofResource->property_roleNames, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _updateRolesofResource->is_valid_roleNames = AXIS2_FALSE;
                        axutil_array_list_set(_updateRolesofResource->property_roleNames , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_updateRolesofResource->property_roleNames , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

            /**
             * Getter for resource by  Property Number 2
             */
            axis2_char_t* AXIS2_CALL
            adb_updateRolesofResource_get_property2(
                adb_updateRolesofResource_t* _updateRolesofResource,
                const axutil_env_t *env)
            {
                return adb_updateRolesofResource_get_resource(_updateRolesofResource,
                                             env);
            }

            /**
             * getter for resource.
             */
            axis2_char_t* AXIS2_CALL
            adb_updateRolesofResource_get_resource(
                    adb_updateRolesofResource_t* _updateRolesofResource,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _updateRolesofResource, NULL);
                  

                return _updateRolesofResource->property_resource;
             }

            /**
             * setter for resource
             */
            axis2_status_t AXIS2_CALL
            adb_updateRolesofResource_set_resource(
                    adb_updateRolesofResource_t* _updateRolesofResource,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_resource)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _updateRolesofResource, AXIS2_FAILURE);
                
                if(_updateRolesofResource->is_valid_resource &&
                        arg_resource == _updateRolesofResource->property_resource)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_updateRolesofResource_reset_resource(_updateRolesofResource, env);

                
                if(NULL == arg_resource)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _updateRolesofResource->property_resource = (axis2_char_t *)axutil_strdup(env, arg_resource);
                        if(NULL == _updateRolesofResource->property_resource)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for resource");
                            return AXIS2_FAILURE;
                        }
                        _updateRolesofResource->is_valid_resource = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for resource
            */
           axis2_status_t AXIS2_CALL
           adb_updateRolesofResource_reset_resource(
                   adb_updateRolesofResource_t* _updateRolesofResource,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _updateRolesofResource, AXIS2_FAILURE);
               

               
            
                
                if(_updateRolesofResource->property_resource != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _updateRolesofResource->property_resource);
                     _updateRolesofResource->property_resource = NULL;
                }
            
                
                
                _updateRolesofResource->is_valid_resource = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether resource is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_updateRolesofResource_is_resource_nil(
                   adb_updateRolesofResource_t* _updateRolesofResource,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _updateRolesofResource, AXIS2_TRUE);
               
               return !_updateRolesofResource->is_valid_resource;
           }

           /**
            * Set resource to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_updateRolesofResource_set_resource_nil(
                   adb_updateRolesofResource_t* _updateRolesofResource,
                   const axutil_env_t *env)
           {
               return adb_updateRolesofResource_reset_resource(_updateRolesofResource, env);
           }

           

            /**
             * Getter for action by  Property Number 3
             */
            axis2_char_t* AXIS2_CALL
            adb_updateRolesofResource_get_property3(
                adb_updateRolesofResource_t* _updateRolesofResource,
                const axutil_env_t *env)
            {
                return adb_updateRolesofResource_get_action(_updateRolesofResource,
                                             env);
            }

            /**
             * getter for action.
             */
            axis2_char_t* AXIS2_CALL
            adb_updateRolesofResource_get_action(
                    adb_updateRolesofResource_t* _updateRolesofResource,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _updateRolesofResource, NULL);
                  

                return _updateRolesofResource->property_action;
             }

            /**
             * setter for action
             */
            axis2_status_t AXIS2_CALL
            adb_updateRolesofResource_set_action(
                    adb_updateRolesofResource_t* _updateRolesofResource,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_action)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _updateRolesofResource, AXIS2_FAILURE);
                
                if(_updateRolesofResource->is_valid_action &&
                        arg_action == _updateRolesofResource->property_action)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_updateRolesofResource_reset_action(_updateRolesofResource, env);

                
                if(NULL == arg_action)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _updateRolesofResource->property_action = (axis2_char_t *)axutil_strdup(env, arg_action);
                        if(NULL == _updateRolesofResource->property_action)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for action");
                            return AXIS2_FAILURE;
                        }
                        _updateRolesofResource->is_valid_action = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for action
            */
           axis2_status_t AXIS2_CALL
           adb_updateRolesofResource_reset_action(
                   adb_updateRolesofResource_t* _updateRolesofResource,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _updateRolesofResource, AXIS2_FAILURE);
               

               
            
                
                if(_updateRolesofResource->property_action != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _updateRolesofResource->property_action);
                     _updateRolesofResource->property_action = NULL;
                }
            
                
                
                _updateRolesofResource->is_valid_action = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether action is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_updateRolesofResource_is_action_nil(
                   adb_updateRolesofResource_t* _updateRolesofResource,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _updateRolesofResource, AXIS2_TRUE);
               
               return !_updateRolesofResource->is_valid_action;
           }

           /**
            * Set action to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_updateRolesofResource_set_action_nil(
                   adb_updateRolesofResource_t* _updateRolesofResource,
                   const axutil_env_t *env)
           {
               return adb_updateRolesofResource_reset_action(_updateRolesofResource, env);
           }

           

