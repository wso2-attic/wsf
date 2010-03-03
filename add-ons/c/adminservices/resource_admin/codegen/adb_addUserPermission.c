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
         * adb_addUserPermission.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_addUserPermission.h"
        
               /*
                * implmentation of the addUserPermission|http://services.resource.ui.mgt.registry.carbon.wso2.org element
                */
           


        struct adb_addUserPermission
        {
            axis2_char_t *property_Type;

            
                axutil_qname_t* qname;
            axis2_char_t* property_pathToAuthorize;

                
                axis2_bool_t is_valid_pathToAuthorize;
            axis2_char_t* property_userToAuthorize;

                
                axis2_bool_t is_valid_userToAuthorize;
            axis2_char_t* property_actionToAuthorize;

                
                axis2_bool_t is_valid_actionToAuthorize;
            axis2_char_t* property_permissionType;

                
                axis2_bool_t is_valid_permissionType;
            
        };


       /************************* Private Function prototypes ********************************/
        


       /************************* Function Implmentations ********************************/
        adb_addUserPermission_t* AXIS2_CALL
        adb_addUserPermission_create(
            const axutil_env_t *env)
        {
            adb_addUserPermission_t *_addUserPermission = NULL;
            
                axutil_qname_t* qname = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _addUserPermission = (adb_addUserPermission_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_addUserPermission_t));

            if(NULL == _addUserPermission)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_addUserPermission, 0, sizeof(adb_addUserPermission_t));

            _addUserPermission->property_Type = axutil_strdup(env, "adb_addUserPermission");
            _addUserPermission->property_pathToAuthorize  = NULL;
                  _addUserPermission->is_valid_pathToAuthorize  = AXIS2_FALSE;
            _addUserPermission->property_userToAuthorize  = NULL;
                  _addUserPermission->is_valid_userToAuthorize  = AXIS2_FALSE;
            _addUserPermission->property_actionToAuthorize  = NULL;
                  _addUserPermission->is_valid_actionToAuthorize  = AXIS2_FALSE;
            _addUserPermission->property_permissionType  = NULL;
                  _addUserPermission->is_valid_permissionType  = AXIS2_FALSE;
            
                  qname =  axutil_qname_create (env,
                        "addUserPermission",
                        "http://services.resource.ui.mgt.registry.carbon.wso2.org",
                        NULL);
                _addUserPermission->qname = qname;
            

            return _addUserPermission;
        }

        adb_addUserPermission_t* AXIS2_CALL
        adb_addUserPermission_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _pathToAuthorize,
                axis2_char_t* _userToAuthorize,
                axis2_char_t* _actionToAuthorize,
                axis2_char_t* _permissionType)
        {
            adb_addUserPermission_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_addUserPermission_create(env);

            
              status = adb_addUserPermission_set_pathToAuthorize(
                                     adb_obj,
                                     env,
                                     _pathToAuthorize);
              if(status == AXIS2_FAILURE) {
                  adb_addUserPermission_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_addUserPermission_set_userToAuthorize(
                                     adb_obj,
                                     env,
                                     _userToAuthorize);
              if(status == AXIS2_FAILURE) {
                  adb_addUserPermission_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_addUserPermission_set_actionToAuthorize(
                                     adb_obj,
                                     env,
                                     _actionToAuthorize);
              if(status == AXIS2_FAILURE) {
                  adb_addUserPermission_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_addUserPermission_set_permissionType(
                                     adb_obj,
                                     env,
                                     _permissionType);
              if(status == AXIS2_FAILURE) {
                  adb_addUserPermission_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_char_t* AXIS2_CALL
                adb_addUserPermission_free_popping_value(
                        adb_addUserPermission_t* _addUserPermission,
                        const axutil_env_t *env)
                {
                    axis2_char_t* value;

                    
                    
                    value = _addUserPermission->property_pathToAuthorize;

                    _addUserPermission->property_pathToAuthorize = (axis2_char_t*)NULL;
                    adb_addUserPermission_free(_addUserPermission, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_addUserPermission_free(
                adb_addUserPermission_t* _addUserPermission,
                const axutil_env_t *env)
        {
            
            
            return adb_addUserPermission_free_obj(
                _addUserPermission,
                env);
            
        }

        axis2_status_t AXIS2_CALL
        adb_addUserPermission_free_obj(
                adb_addUserPermission_t* _addUserPermission,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _addUserPermission, AXIS2_FAILURE);

            if (_addUserPermission->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _addUserPermission->property_Type);
            }

            adb_addUserPermission_reset_pathToAuthorize(_addUserPermission, env);
            adb_addUserPermission_reset_userToAuthorize(_addUserPermission, env);
            adb_addUserPermission_reset_actionToAuthorize(_addUserPermission, env);
            adb_addUserPermission_reset_permissionType(_addUserPermission, env);
            
              if(_addUserPermission->qname)
              {
                  axutil_qname_free (_addUserPermission->qname, env);
                  _addUserPermission->qname = NULL;
              }
            

            if(_addUserPermission)
            {
                AXIS2_FREE(env->allocator, _addUserPermission);
                _addUserPermission = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_addUserPermission_deserialize(
                adb_addUserPermission_t* _addUserPermission,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return adb_addUserPermission_deserialize_obj(
                _addUserPermission,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs);
            
        }

        axis2_status_t AXIS2_CALL
        adb_addUserPermission_deserialize_obj(
                adb_addUserPermission_t* _addUserPermission,
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
            AXIS2_PARAM_CHECK(env->error, _addUserPermission, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for addUserPermission : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              

                    current_element = (axiom_element_t *)axiom_node_get_data_element(parent, env);
                    qname = axiom_element_get_qname(current_element, env, parent);
                    if (axutil_qname_equals(qname, env, _addUserPermission-> qname))
                    {
                        
                          first_node = axiom_node_get_first_child(parent, env);
                          
                    }
                    else
                    {
                        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                              "Failed in building adb object for addUserPermission : "
                              "Expected %s but returned %s",
                              axutil_qname_to_string(_addUserPermission-> qname, env),
                              axutil_qname_to_string(qname, env));
                        
                        return AXIS2_FAILURE;
                    }
                    

                     
                     /*
                      * building pathToAuthorize element
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
                                   
                                 element_qname = axutil_qname_create(env, "pathToAuthorize", "http://services.resource.ui.mgt.registry.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_addUserPermission_set_pathToAuthorize(_addUserPermission, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for pathToAuthorize ");
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
                      * building userToAuthorize element
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
                                 
                                 element_qname = axutil_qname_create(env, "userToAuthorize", "http://services.resource.ui.mgt.registry.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_addUserPermission_set_userToAuthorize(_addUserPermission, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for userToAuthorize ");
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
                      * building actionToAuthorize element
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
                                 
                                 element_qname = axutil_qname_create(env, "actionToAuthorize", "http://services.resource.ui.mgt.registry.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_addUserPermission_set_actionToAuthorize(_addUserPermission, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for actionToAuthorize ");
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
                      * building permissionType element
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
                                 
                                 element_qname = axutil_qname_create(env, "permissionType", "http://services.resource.ui.mgt.registry.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_addUserPermission_set_permissionType(_addUserPermission, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for permissionType ");
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
          adb_addUserPermission_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_addUserPermission_declare_parent_namespaces(
                    adb_addUserPermission_t* _addUserPermission,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_addUserPermission_serialize(
                adb_addUserPermission_t* _addUserPermission,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
                return adb_addUserPermission_serialize_obj(
                    _addUserPermission, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            
        }

        axiom_node_t* AXIS2_CALL
        adb_addUserPermission_serialize_obj(
                adb_addUserPermission_t* _addUserPermission,
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
                    
                    axis2_char_t *text_value_3;
                    axis2_char_t *text_value_3_temp;
                    
                    axis2_char_t *text_value_4;
                    axis2_char_t *text_value_4_temp;
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

             
                int next_ns_index_value = 0;
            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _addUserPermission, NULL);
            
             
                    namespaces = axutil_hash_make(env);
                    next_ns_index = &next_ns_index_value;
                     
                           ns1 = axiom_namespace_create (env,
                                             "http://services.resource.ui.mgt.registry.carbon.wso2.org",
                                             "n"); 
                           axutil_hash_set(namespaces, "http://services.resource.ui.mgt.registry.carbon.wso2.org", AXIS2_HASH_KEY_STRING, axutil_strdup(env, "n"));
                       
                     
                    parent_element = axiom_element_create (env, NULL, "addUserPermission", ns1 , &parent);
                    
                    
                    axiom_element_set_namespace(parent_element, env, ns1, parent);


            
                    data_source = axiom_data_source_create(env, parent, &current_node);
                    stream = axiom_data_source_get_stream(data_source, env);
                  
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://services.resource.ui.mgt.registry.carbon.wso2.org", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://services.resource.ui.mgt.registry.carbon.wso2.org", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://services.resource.ui.mgt.registry.carbon.wso2.org",
                                            p_prefix));
                       }
                      

                   if (!_addUserPermission->is_valid_pathToAuthorize)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("pathToAuthorize"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("pathToAuthorize")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing pathToAuthorize element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%spathToAuthorize>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%spathToAuthorize>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_1 = _addUserPermission->property_pathToAuthorize;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://services.resource.ui.mgt.registry.carbon.wso2.org", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://services.resource.ui.mgt.registry.carbon.wso2.org", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://services.resource.ui.mgt.registry.carbon.wso2.org",
                                            p_prefix));
                       }
                      

                   if (!_addUserPermission->is_valid_userToAuthorize)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("userToAuthorize"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("userToAuthorize")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing userToAuthorize element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%suserToAuthorize>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%suserToAuthorize>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_2 = _addUserPermission->property_userToAuthorize;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://services.resource.ui.mgt.registry.carbon.wso2.org", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://services.resource.ui.mgt.registry.carbon.wso2.org", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://services.resource.ui.mgt.registry.carbon.wso2.org",
                                            p_prefix));
                       }
                      

                   if (!_addUserPermission->is_valid_actionToAuthorize)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("actionToAuthorize"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("actionToAuthorize")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing actionToAuthorize element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sactionToAuthorize>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sactionToAuthorize>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_3 = _addUserPermission->property_actionToAuthorize;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://services.resource.ui.mgt.registry.carbon.wso2.org", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://services.resource.ui.mgt.registry.carbon.wso2.org", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://services.resource.ui.mgt.registry.carbon.wso2.org",
                                            p_prefix));
                       }
                      

                   if (!_addUserPermission->is_valid_permissionType)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("permissionType"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("permissionType")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing permissionType element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%spermissionType>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%spermissionType>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_4 = _addUserPermission->property_permissionType;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_4_temp = axutil_xml_quote_string(env, text_value_4, AXIS2_TRUE);
                           if (text_value_4_temp)
                           {
                               axutil_stream_write(stream, env, text_value_4_temp, axutil_strlen(text_value_4_temp));
                               AXIS2_FREE(env->allocator, text_value_4_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_4, axutil_strlen(text_value_4));
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
             * Getter for pathToAuthorize by  Property Number 1
             */
            axis2_char_t* AXIS2_CALL
            adb_addUserPermission_get_property1(
                adb_addUserPermission_t* _addUserPermission,
                const axutil_env_t *env)
            {
                return adb_addUserPermission_get_pathToAuthorize(_addUserPermission,
                                             env);
            }

            /**
             * getter for pathToAuthorize.
             */
            axis2_char_t* AXIS2_CALL
            adb_addUserPermission_get_pathToAuthorize(
                    adb_addUserPermission_t* _addUserPermission,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addUserPermission, NULL);
                  

                return _addUserPermission->property_pathToAuthorize;
             }

            /**
             * setter for pathToAuthorize
             */
            axis2_status_t AXIS2_CALL
            adb_addUserPermission_set_pathToAuthorize(
                    adb_addUserPermission_t* _addUserPermission,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_pathToAuthorize)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addUserPermission, AXIS2_FAILURE);
                
                if(_addUserPermission->is_valid_pathToAuthorize &&
                        arg_pathToAuthorize == _addUserPermission->property_pathToAuthorize)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_addUserPermission_reset_pathToAuthorize(_addUserPermission, env);

                
                if(NULL == arg_pathToAuthorize)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addUserPermission->property_pathToAuthorize = (axis2_char_t *)axutil_strdup(env, arg_pathToAuthorize);
                        if(NULL == _addUserPermission->property_pathToAuthorize)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for pathToAuthorize");
                            return AXIS2_FAILURE;
                        }
                        _addUserPermission->is_valid_pathToAuthorize = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for pathToAuthorize
            */
           axis2_status_t AXIS2_CALL
           adb_addUserPermission_reset_pathToAuthorize(
                   adb_addUserPermission_t* _addUserPermission,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addUserPermission, AXIS2_FAILURE);
               

               
            
                
                if(_addUserPermission->property_pathToAuthorize != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _addUserPermission->property_pathToAuthorize);
                     _addUserPermission->property_pathToAuthorize = NULL;
                }
            
                
                
                _addUserPermission->is_valid_pathToAuthorize = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether pathToAuthorize is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addUserPermission_is_pathToAuthorize_nil(
                   adb_addUserPermission_t* _addUserPermission,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addUserPermission, AXIS2_TRUE);
               
               return !_addUserPermission->is_valid_pathToAuthorize;
           }

           /**
            * Set pathToAuthorize to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addUserPermission_set_pathToAuthorize_nil(
                   adb_addUserPermission_t* _addUserPermission,
                   const axutil_env_t *env)
           {
               return adb_addUserPermission_reset_pathToAuthorize(_addUserPermission, env);
           }

           

            /**
             * Getter for userToAuthorize by  Property Number 2
             */
            axis2_char_t* AXIS2_CALL
            adb_addUserPermission_get_property2(
                adb_addUserPermission_t* _addUserPermission,
                const axutil_env_t *env)
            {
                return adb_addUserPermission_get_userToAuthorize(_addUserPermission,
                                             env);
            }

            /**
             * getter for userToAuthorize.
             */
            axis2_char_t* AXIS2_CALL
            adb_addUserPermission_get_userToAuthorize(
                    adb_addUserPermission_t* _addUserPermission,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addUserPermission, NULL);
                  

                return _addUserPermission->property_userToAuthorize;
             }

            /**
             * setter for userToAuthorize
             */
            axis2_status_t AXIS2_CALL
            adb_addUserPermission_set_userToAuthorize(
                    adb_addUserPermission_t* _addUserPermission,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_userToAuthorize)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addUserPermission, AXIS2_FAILURE);
                
                if(_addUserPermission->is_valid_userToAuthorize &&
                        arg_userToAuthorize == _addUserPermission->property_userToAuthorize)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_addUserPermission_reset_userToAuthorize(_addUserPermission, env);

                
                if(NULL == arg_userToAuthorize)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addUserPermission->property_userToAuthorize = (axis2_char_t *)axutil_strdup(env, arg_userToAuthorize);
                        if(NULL == _addUserPermission->property_userToAuthorize)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for userToAuthorize");
                            return AXIS2_FAILURE;
                        }
                        _addUserPermission->is_valid_userToAuthorize = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for userToAuthorize
            */
           axis2_status_t AXIS2_CALL
           adb_addUserPermission_reset_userToAuthorize(
                   adb_addUserPermission_t* _addUserPermission,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addUserPermission, AXIS2_FAILURE);
               

               
            
                
                if(_addUserPermission->property_userToAuthorize != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _addUserPermission->property_userToAuthorize);
                     _addUserPermission->property_userToAuthorize = NULL;
                }
            
                
                
                _addUserPermission->is_valid_userToAuthorize = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether userToAuthorize is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addUserPermission_is_userToAuthorize_nil(
                   adb_addUserPermission_t* _addUserPermission,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addUserPermission, AXIS2_TRUE);
               
               return !_addUserPermission->is_valid_userToAuthorize;
           }

           /**
            * Set userToAuthorize to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addUserPermission_set_userToAuthorize_nil(
                   adb_addUserPermission_t* _addUserPermission,
                   const axutil_env_t *env)
           {
               return adb_addUserPermission_reset_userToAuthorize(_addUserPermission, env);
           }

           

            /**
             * Getter for actionToAuthorize by  Property Number 3
             */
            axis2_char_t* AXIS2_CALL
            adb_addUserPermission_get_property3(
                adb_addUserPermission_t* _addUserPermission,
                const axutil_env_t *env)
            {
                return adb_addUserPermission_get_actionToAuthorize(_addUserPermission,
                                             env);
            }

            /**
             * getter for actionToAuthorize.
             */
            axis2_char_t* AXIS2_CALL
            adb_addUserPermission_get_actionToAuthorize(
                    adb_addUserPermission_t* _addUserPermission,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addUserPermission, NULL);
                  

                return _addUserPermission->property_actionToAuthorize;
             }

            /**
             * setter for actionToAuthorize
             */
            axis2_status_t AXIS2_CALL
            adb_addUserPermission_set_actionToAuthorize(
                    adb_addUserPermission_t* _addUserPermission,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_actionToAuthorize)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addUserPermission, AXIS2_FAILURE);
                
                if(_addUserPermission->is_valid_actionToAuthorize &&
                        arg_actionToAuthorize == _addUserPermission->property_actionToAuthorize)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_addUserPermission_reset_actionToAuthorize(_addUserPermission, env);

                
                if(NULL == arg_actionToAuthorize)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addUserPermission->property_actionToAuthorize = (axis2_char_t *)axutil_strdup(env, arg_actionToAuthorize);
                        if(NULL == _addUserPermission->property_actionToAuthorize)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for actionToAuthorize");
                            return AXIS2_FAILURE;
                        }
                        _addUserPermission->is_valid_actionToAuthorize = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for actionToAuthorize
            */
           axis2_status_t AXIS2_CALL
           adb_addUserPermission_reset_actionToAuthorize(
                   adb_addUserPermission_t* _addUserPermission,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addUserPermission, AXIS2_FAILURE);
               

               
            
                
                if(_addUserPermission->property_actionToAuthorize != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _addUserPermission->property_actionToAuthorize);
                     _addUserPermission->property_actionToAuthorize = NULL;
                }
            
                
                
                _addUserPermission->is_valid_actionToAuthorize = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether actionToAuthorize is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addUserPermission_is_actionToAuthorize_nil(
                   adb_addUserPermission_t* _addUserPermission,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addUserPermission, AXIS2_TRUE);
               
               return !_addUserPermission->is_valid_actionToAuthorize;
           }

           /**
            * Set actionToAuthorize to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addUserPermission_set_actionToAuthorize_nil(
                   adb_addUserPermission_t* _addUserPermission,
                   const axutil_env_t *env)
           {
               return adb_addUserPermission_reset_actionToAuthorize(_addUserPermission, env);
           }

           

            /**
             * Getter for permissionType by  Property Number 4
             */
            axis2_char_t* AXIS2_CALL
            adb_addUserPermission_get_property4(
                adb_addUserPermission_t* _addUserPermission,
                const axutil_env_t *env)
            {
                return adb_addUserPermission_get_permissionType(_addUserPermission,
                                             env);
            }

            /**
             * getter for permissionType.
             */
            axis2_char_t* AXIS2_CALL
            adb_addUserPermission_get_permissionType(
                    adb_addUserPermission_t* _addUserPermission,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addUserPermission, NULL);
                  

                return _addUserPermission->property_permissionType;
             }

            /**
             * setter for permissionType
             */
            axis2_status_t AXIS2_CALL
            adb_addUserPermission_set_permissionType(
                    adb_addUserPermission_t* _addUserPermission,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_permissionType)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addUserPermission, AXIS2_FAILURE);
                
                if(_addUserPermission->is_valid_permissionType &&
                        arg_permissionType == _addUserPermission->property_permissionType)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_addUserPermission_reset_permissionType(_addUserPermission, env);

                
                if(NULL == arg_permissionType)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addUserPermission->property_permissionType = (axis2_char_t *)axutil_strdup(env, arg_permissionType);
                        if(NULL == _addUserPermission->property_permissionType)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for permissionType");
                            return AXIS2_FAILURE;
                        }
                        _addUserPermission->is_valid_permissionType = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for permissionType
            */
           axis2_status_t AXIS2_CALL
           adb_addUserPermission_reset_permissionType(
                   adb_addUserPermission_t* _addUserPermission,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addUserPermission, AXIS2_FAILURE);
               

               
            
                
                if(_addUserPermission->property_permissionType != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _addUserPermission->property_permissionType);
                     _addUserPermission->property_permissionType = NULL;
                }
            
                
                
                _addUserPermission->is_valid_permissionType = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether permissionType is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addUserPermission_is_permissionType_nil(
                   adb_addUserPermission_t* _addUserPermission,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addUserPermission, AXIS2_TRUE);
               
               return !_addUserPermission->is_valid_permissionType;
           }

           /**
            * Set permissionType to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addUserPermission_set_permissionType_nil(
                   adb_addUserPermission_t* _addUserPermission,
                   const axutil_env_t *env)
           {
               return adb_addUserPermission_reset_permissionType(_addUserPermission, env);
           }

           

