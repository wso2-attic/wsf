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
         * adb_addRolePermission.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_addRolePermission.h"
        
               /*
                * implmentation of the addRolePermission|http://services.resource.ui.mgt.registry.carbon.wso2.org element
                */
           


        struct adb_addRolePermission
        {
            axis2_char_t *property_Type;

            
                axutil_qname_t* qname;
            axis2_char_t* property_pathToAuthorize;

                
                axis2_bool_t is_valid_pathToAuthorize;
            axis2_char_t* property_roleToAuthorize;

                
                axis2_bool_t is_valid_roleToAuthorize;
            axis2_char_t* property_actionToAuthorize;

                
                axis2_bool_t is_valid_actionToAuthorize;
            axis2_char_t* property_permissionType;

                
                axis2_bool_t is_valid_permissionType;
            
        };


       /************************* Private Function prototypes ********************************/
        


       /************************* Function Implmentations ********************************/
        adb_addRolePermission_t* AXIS2_CALL
        adb_addRolePermission_create(
            const axutil_env_t *env)
        {
            adb_addRolePermission_t *_addRolePermission = NULL;
            
                axutil_qname_t* qname = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _addRolePermission = (adb_addRolePermission_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_addRolePermission_t));

            if(NULL == _addRolePermission)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_addRolePermission, 0, sizeof(adb_addRolePermission_t));

            _addRolePermission->property_Type = axutil_strdup(env, "adb_addRolePermission");
            _addRolePermission->property_pathToAuthorize  = NULL;
                  _addRolePermission->is_valid_pathToAuthorize  = AXIS2_FALSE;
            _addRolePermission->property_roleToAuthorize  = NULL;
                  _addRolePermission->is_valid_roleToAuthorize  = AXIS2_FALSE;
            _addRolePermission->property_actionToAuthorize  = NULL;
                  _addRolePermission->is_valid_actionToAuthorize  = AXIS2_FALSE;
            _addRolePermission->property_permissionType  = NULL;
                  _addRolePermission->is_valid_permissionType  = AXIS2_FALSE;
            
                  qname =  axutil_qname_create (env,
                        "addRolePermission",
                        "http://services.resource.ui.mgt.registry.carbon.wso2.org",
                        NULL);
                _addRolePermission->qname = qname;
            

            return _addRolePermission;
        }

        adb_addRolePermission_t* AXIS2_CALL
        adb_addRolePermission_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _pathToAuthorize,
                axis2_char_t* _roleToAuthorize,
                axis2_char_t* _actionToAuthorize,
                axis2_char_t* _permissionType)
        {
            adb_addRolePermission_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_addRolePermission_create(env);

            
              status = adb_addRolePermission_set_pathToAuthorize(
                                     adb_obj,
                                     env,
                                     _pathToAuthorize);
              if(status == AXIS2_FAILURE) {
                  adb_addRolePermission_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_addRolePermission_set_roleToAuthorize(
                                     adb_obj,
                                     env,
                                     _roleToAuthorize);
              if(status == AXIS2_FAILURE) {
                  adb_addRolePermission_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_addRolePermission_set_actionToAuthorize(
                                     adb_obj,
                                     env,
                                     _actionToAuthorize);
              if(status == AXIS2_FAILURE) {
                  adb_addRolePermission_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_addRolePermission_set_permissionType(
                                     adb_obj,
                                     env,
                                     _permissionType);
              if(status == AXIS2_FAILURE) {
                  adb_addRolePermission_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_char_t* AXIS2_CALL
                adb_addRolePermission_free_popping_value(
                        adb_addRolePermission_t* _addRolePermission,
                        const axutil_env_t *env)
                {
                    axis2_char_t* value;

                    
                    
                    value = _addRolePermission->property_pathToAuthorize;

                    _addRolePermission->property_pathToAuthorize = (axis2_char_t*)NULL;
                    adb_addRolePermission_free(_addRolePermission, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_addRolePermission_free(
                adb_addRolePermission_t* _addRolePermission,
                const axutil_env_t *env)
        {
            
            
            return adb_addRolePermission_free_obj(
                _addRolePermission,
                env);
            
        }

        axis2_status_t AXIS2_CALL
        adb_addRolePermission_free_obj(
                adb_addRolePermission_t* _addRolePermission,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _addRolePermission, AXIS2_FAILURE);

            if (_addRolePermission->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _addRolePermission->property_Type);
            }

            adb_addRolePermission_reset_pathToAuthorize(_addRolePermission, env);
            adb_addRolePermission_reset_roleToAuthorize(_addRolePermission, env);
            adb_addRolePermission_reset_actionToAuthorize(_addRolePermission, env);
            adb_addRolePermission_reset_permissionType(_addRolePermission, env);
            
              if(_addRolePermission->qname)
              {
                  axutil_qname_free (_addRolePermission->qname, env);
                  _addRolePermission->qname = NULL;
              }
            

            if(_addRolePermission)
            {
                AXIS2_FREE(env->allocator, _addRolePermission);
                _addRolePermission = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_addRolePermission_deserialize(
                adb_addRolePermission_t* _addRolePermission,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return adb_addRolePermission_deserialize_obj(
                _addRolePermission,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs);
            
        }

        axis2_status_t AXIS2_CALL
        adb_addRolePermission_deserialize_obj(
                adb_addRolePermission_t* _addRolePermission,
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
            AXIS2_PARAM_CHECK(env->error, _addRolePermission, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for addRolePermission : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              

                    current_element = (axiom_element_t *)axiom_node_get_data_element(parent, env);
                    qname = axiom_element_get_qname(current_element, env, parent);
                    if (axutil_qname_equals(qname, env, _addRolePermission-> qname))
                    {
                        
                          first_node = axiom_node_get_first_child(parent, env);
                          
                    }
                    else
                    {
                        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                              "Failed in building adb object for addRolePermission : "
                              "Expected %s but returned %s",
                              axutil_qname_to_string(_addRolePermission-> qname, env),
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
                                            status = adb_addRolePermission_set_pathToAuthorize(_addRolePermission, env,
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
                      * building roleToAuthorize element
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
                                 
                                 element_qname = axutil_qname_create(env, "roleToAuthorize", "http://services.resource.ui.mgt.registry.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_addRolePermission_set_roleToAuthorize(_addRolePermission, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for roleToAuthorize ");
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
                                            status = adb_addRolePermission_set_actionToAuthorize(_addRolePermission, env,
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
                                            status = adb_addRolePermission_set_permissionType(_addRolePermission, env,
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
          adb_addRolePermission_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_addRolePermission_declare_parent_namespaces(
                    adb_addRolePermission_t* _addRolePermission,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_addRolePermission_serialize(
                adb_addRolePermission_t* _addRolePermission,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
                return adb_addRolePermission_serialize_obj(
                    _addRolePermission, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            
        }

        axiom_node_t* AXIS2_CALL
        adb_addRolePermission_serialize_obj(
                adb_addRolePermission_t* _addRolePermission,
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
            AXIS2_PARAM_CHECK(env->error, _addRolePermission, NULL);
            
             
                    namespaces = axutil_hash_make(env);
                    next_ns_index = &next_ns_index_value;
                     
                           ns1 = axiom_namespace_create (env,
                                             "http://services.resource.ui.mgt.registry.carbon.wso2.org",
                                             "n"); 
                           axutil_hash_set(namespaces, "http://services.resource.ui.mgt.registry.carbon.wso2.org", AXIS2_HASH_KEY_STRING, axutil_strdup(env, "n"));
                       
                     
                    parent_element = axiom_element_create (env, NULL, "addRolePermission", ns1 , &parent);
                    
                    
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
                      

                   if (!_addRolePermission->is_valid_pathToAuthorize)
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
                    
                           text_value_1 = _addRolePermission->property_pathToAuthorize;
                           
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
                      

                   if (!_addRolePermission->is_valid_roleToAuthorize)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("roleToAuthorize"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("roleToAuthorize")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing roleToAuthorize element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sroleToAuthorize>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sroleToAuthorize>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_2 = _addRolePermission->property_roleToAuthorize;
                           
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
                      

                   if (!_addRolePermission->is_valid_actionToAuthorize)
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
                    
                           text_value_3 = _addRolePermission->property_actionToAuthorize;
                           
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
                      

                   if (!_addRolePermission->is_valid_permissionType)
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
                    
                           text_value_4 = _addRolePermission->property_permissionType;
                           
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
            adb_addRolePermission_get_property1(
                adb_addRolePermission_t* _addRolePermission,
                const axutil_env_t *env)
            {
                return adb_addRolePermission_get_pathToAuthorize(_addRolePermission,
                                             env);
            }

            /**
             * getter for pathToAuthorize.
             */
            axis2_char_t* AXIS2_CALL
            adb_addRolePermission_get_pathToAuthorize(
                    adb_addRolePermission_t* _addRolePermission,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addRolePermission, NULL);
                  

                return _addRolePermission->property_pathToAuthorize;
             }

            /**
             * setter for pathToAuthorize
             */
            axis2_status_t AXIS2_CALL
            adb_addRolePermission_set_pathToAuthorize(
                    adb_addRolePermission_t* _addRolePermission,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_pathToAuthorize)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addRolePermission, AXIS2_FAILURE);
                
                if(_addRolePermission->is_valid_pathToAuthorize &&
                        arg_pathToAuthorize == _addRolePermission->property_pathToAuthorize)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_addRolePermission_reset_pathToAuthorize(_addRolePermission, env);

                
                if(NULL == arg_pathToAuthorize)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addRolePermission->property_pathToAuthorize = (axis2_char_t *)axutil_strdup(env, arg_pathToAuthorize);
                        if(NULL == _addRolePermission->property_pathToAuthorize)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for pathToAuthorize");
                            return AXIS2_FAILURE;
                        }
                        _addRolePermission->is_valid_pathToAuthorize = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for pathToAuthorize
            */
           axis2_status_t AXIS2_CALL
           adb_addRolePermission_reset_pathToAuthorize(
                   adb_addRolePermission_t* _addRolePermission,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addRolePermission, AXIS2_FAILURE);
               

               
            
                
                if(_addRolePermission->property_pathToAuthorize != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _addRolePermission->property_pathToAuthorize);
                     _addRolePermission->property_pathToAuthorize = NULL;
                }
            
                
                
                _addRolePermission->is_valid_pathToAuthorize = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether pathToAuthorize is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addRolePermission_is_pathToAuthorize_nil(
                   adb_addRolePermission_t* _addRolePermission,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addRolePermission, AXIS2_TRUE);
               
               return !_addRolePermission->is_valid_pathToAuthorize;
           }

           /**
            * Set pathToAuthorize to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addRolePermission_set_pathToAuthorize_nil(
                   adb_addRolePermission_t* _addRolePermission,
                   const axutil_env_t *env)
           {
               return adb_addRolePermission_reset_pathToAuthorize(_addRolePermission, env);
           }

           

            /**
             * Getter for roleToAuthorize by  Property Number 2
             */
            axis2_char_t* AXIS2_CALL
            adb_addRolePermission_get_property2(
                adb_addRolePermission_t* _addRolePermission,
                const axutil_env_t *env)
            {
                return adb_addRolePermission_get_roleToAuthorize(_addRolePermission,
                                             env);
            }

            /**
             * getter for roleToAuthorize.
             */
            axis2_char_t* AXIS2_CALL
            adb_addRolePermission_get_roleToAuthorize(
                    adb_addRolePermission_t* _addRolePermission,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addRolePermission, NULL);
                  

                return _addRolePermission->property_roleToAuthorize;
             }

            /**
             * setter for roleToAuthorize
             */
            axis2_status_t AXIS2_CALL
            adb_addRolePermission_set_roleToAuthorize(
                    adb_addRolePermission_t* _addRolePermission,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_roleToAuthorize)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addRolePermission, AXIS2_FAILURE);
                
                if(_addRolePermission->is_valid_roleToAuthorize &&
                        arg_roleToAuthorize == _addRolePermission->property_roleToAuthorize)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_addRolePermission_reset_roleToAuthorize(_addRolePermission, env);

                
                if(NULL == arg_roleToAuthorize)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addRolePermission->property_roleToAuthorize = (axis2_char_t *)axutil_strdup(env, arg_roleToAuthorize);
                        if(NULL == _addRolePermission->property_roleToAuthorize)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for roleToAuthorize");
                            return AXIS2_FAILURE;
                        }
                        _addRolePermission->is_valid_roleToAuthorize = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for roleToAuthorize
            */
           axis2_status_t AXIS2_CALL
           adb_addRolePermission_reset_roleToAuthorize(
                   adb_addRolePermission_t* _addRolePermission,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addRolePermission, AXIS2_FAILURE);
               

               
            
                
                if(_addRolePermission->property_roleToAuthorize != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _addRolePermission->property_roleToAuthorize);
                     _addRolePermission->property_roleToAuthorize = NULL;
                }
            
                
                
                _addRolePermission->is_valid_roleToAuthorize = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether roleToAuthorize is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addRolePermission_is_roleToAuthorize_nil(
                   adb_addRolePermission_t* _addRolePermission,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addRolePermission, AXIS2_TRUE);
               
               return !_addRolePermission->is_valid_roleToAuthorize;
           }

           /**
            * Set roleToAuthorize to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addRolePermission_set_roleToAuthorize_nil(
                   adb_addRolePermission_t* _addRolePermission,
                   const axutil_env_t *env)
           {
               return adb_addRolePermission_reset_roleToAuthorize(_addRolePermission, env);
           }

           

            /**
             * Getter for actionToAuthorize by  Property Number 3
             */
            axis2_char_t* AXIS2_CALL
            adb_addRolePermission_get_property3(
                adb_addRolePermission_t* _addRolePermission,
                const axutil_env_t *env)
            {
                return adb_addRolePermission_get_actionToAuthorize(_addRolePermission,
                                             env);
            }

            /**
             * getter for actionToAuthorize.
             */
            axis2_char_t* AXIS2_CALL
            adb_addRolePermission_get_actionToAuthorize(
                    adb_addRolePermission_t* _addRolePermission,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addRolePermission, NULL);
                  

                return _addRolePermission->property_actionToAuthorize;
             }

            /**
             * setter for actionToAuthorize
             */
            axis2_status_t AXIS2_CALL
            adb_addRolePermission_set_actionToAuthorize(
                    adb_addRolePermission_t* _addRolePermission,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_actionToAuthorize)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addRolePermission, AXIS2_FAILURE);
                
                if(_addRolePermission->is_valid_actionToAuthorize &&
                        arg_actionToAuthorize == _addRolePermission->property_actionToAuthorize)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_addRolePermission_reset_actionToAuthorize(_addRolePermission, env);

                
                if(NULL == arg_actionToAuthorize)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addRolePermission->property_actionToAuthorize = (axis2_char_t *)axutil_strdup(env, arg_actionToAuthorize);
                        if(NULL == _addRolePermission->property_actionToAuthorize)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for actionToAuthorize");
                            return AXIS2_FAILURE;
                        }
                        _addRolePermission->is_valid_actionToAuthorize = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for actionToAuthorize
            */
           axis2_status_t AXIS2_CALL
           adb_addRolePermission_reset_actionToAuthorize(
                   adb_addRolePermission_t* _addRolePermission,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addRolePermission, AXIS2_FAILURE);
               

               
            
                
                if(_addRolePermission->property_actionToAuthorize != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _addRolePermission->property_actionToAuthorize);
                     _addRolePermission->property_actionToAuthorize = NULL;
                }
            
                
                
                _addRolePermission->is_valid_actionToAuthorize = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether actionToAuthorize is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addRolePermission_is_actionToAuthorize_nil(
                   adb_addRolePermission_t* _addRolePermission,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addRolePermission, AXIS2_TRUE);
               
               return !_addRolePermission->is_valid_actionToAuthorize;
           }

           /**
            * Set actionToAuthorize to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addRolePermission_set_actionToAuthorize_nil(
                   adb_addRolePermission_t* _addRolePermission,
                   const axutil_env_t *env)
           {
               return adb_addRolePermission_reset_actionToAuthorize(_addRolePermission, env);
           }

           

            /**
             * Getter for permissionType by  Property Number 4
             */
            axis2_char_t* AXIS2_CALL
            adb_addRolePermission_get_property4(
                adb_addRolePermission_t* _addRolePermission,
                const axutil_env_t *env)
            {
                return adb_addRolePermission_get_permissionType(_addRolePermission,
                                             env);
            }

            /**
             * getter for permissionType.
             */
            axis2_char_t* AXIS2_CALL
            adb_addRolePermission_get_permissionType(
                    adb_addRolePermission_t* _addRolePermission,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addRolePermission, NULL);
                  

                return _addRolePermission->property_permissionType;
             }

            /**
             * setter for permissionType
             */
            axis2_status_t AXIS2_CALL
            adb_addRolePermission_set_permissionType(
                    adb_addRolePermission_t* _addRolePermission,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_permissionType)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addRolePermission, AXIS2_FAILURE);
                
                if(_addRolePermission->is_valid_permissionType &&
                        arg_permissionType == _addRolePermission->property_permissionType)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_addRolePermission_reset_permissionType(_addRolePermission, env);

                
                if(NULL == arg_permissionType)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addRolePermission->property_permissionType = (axis2_char_t *)axutil_strdup(env, arg_permissionType);
                        if(NULL == _addRolePermission->property_permissionType)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for permissionType");
                            return AXIS2_FAILURE;
                        }
                        _addRolePermission->is_valid_permissionType = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for permissionType
            */
           axis2_status_t AXIS2_CALL
           adb_addRolePermission_reset_permissionType(
                   adb_addRolePermission_t* _addRolePermission,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addRolePermission, AXIS2_FAILURE);
               

               
            
                
                if(_addRolePermission->property_permissionType != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _addRolePermission->property_permissionType);
                     _addRolePermission->property_permissionType = NULL;
                }
            
                
                
                _addRolePermission->is_valid_permissionType = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether permissionType is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addRolePermission_is_permissionType_nil(
                   adb_addRolePermission_t* _addRolePermission,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addRolePermission, AXIS2_TRUE);
               
               return !_addRolePermission->is_valid_permissionType;
           }

           /**
            * Set permissionType to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addRolePermission_set_permissionType_nil(
                   adb_addRolePermission_t* _addRolePermission,
                   const axutil_env_t *env)
           {
               return adb_addRolePermission_reset_permissionType(_addRolePermission, env);
           }

           

