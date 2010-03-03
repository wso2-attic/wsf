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
         * adb_loginWithDelegation.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_loginWithDelegation.h"
        
               /*
                * implmentation of the loginWithDelegation|http://authentication.services.core.carbon.wso2.org element
                */
           


        struct adb_loginWithDelegation
        {
            axis2_char_t *property_Type;

            
                axutil_qname_t* qname;
            axis2_char_t* property_username;

                
                axis2_bool_t is_valid_username;
            axis2_char_t* property_password;

                
                axis2_bool_t is_valid_password;
            axis2_char_t* property_authenticatedUser;

                
                axis2_bool_t is_valid_authenticatedUser;
            axis2_char_t* property_remoteAddress;

                
                axis2_bool_t is_valid_remoteAddress;
            
        };


       /************************* Private Function prototypes ********************************/
        


       /************************* Function Implmentations ********************************/
        adb_loginWithDelegation_t* AXIS2_CALL
        adb_loginWithDelegation_create(
            const axutil_env_t *env)
        {
            adb_loginWithDelegation_t *_loginWithDelegation = NULL;
            
                axutil_qname_t* qname = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _loginWithDelegation = (adb_loginWithDelegation_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_loginWithDelegation_t));

            if(NULL == _loginWithDelegation)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_loginWithDelegation, 0, sizeof(adb_loginWithDelegation_t));

            _loginWithDelegation->property_Type = axutil_strdup(env, "adb_loginWithDelegation");
            _loginWithDelegation->property_username  = NULL;
                  _loginWithDelegation->is_valid_username  = AXIS2_FALSE;
            _loginWithDelegation->property_password  = NULL;
                  _loginWithDelegation->is_valid_password  = AXIS2_FALSE;
            _loginWithDelegation->property_authenticatedUser  = NULL;
                  _loginWithDelegation->is_valid_authenticatedUser  = AXIS2_FALSE;
            _loginWithDelegation->property_remoteAddress  = NULL;
                  _loginWithDelegation->is_valid_remoteAddress  = AXIS2_FALSE;
            
                  qname =  axutil_qname_create (env,
                        "loginWithDelegation",
                        "http://authentication.services.core.carbon.wso2.org",
                        NULL);
                _loginWithDelegation->qname = qname;
            

            return _loginWithDelegation;
        }

        adb_loginWithDelegation_t* AXIS2_CALL
        adb_loginWithDelegation_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _username,
                axis2_char_t* _password,
                axis2_char_t* _authenticatedUser,
                axis2_char_t* _remoteAddress)
        {
            adb_loginWithDelegation_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_loginWithDelegation_create(env);

            
              status = adb_loginWithDelegation_set_username(
                                     adb_obj,
                                     env,
                                     _username);
              if(status == AXIS2_FAILURE) {
                  adb_loginWithDelegation_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_loginWithDelegation_set_password(
                                     adb_obj,
                                     env,
                                     _password);
              if(status == AXIS2_FAILURE) {
                  adb_loginWithDelegation_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_loginWithDelegation_set_authenticatedUser(
                                     adb_obj,
                                     env,
                                     _authenticatedUser);
              if(status == AXIS2_FAILURE) {
                  adb_loginWithDelegation_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_loginWithDelegation_set_remoteAddress(
                                     adb_obj,
                                     env,
                                     _remoteAddress);
              if(status == AXIS2_FAILURE) {
                  adb_loginWithDelegation_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_char_t* AXIS2_CALL
                adb_loginWithDelegation_free_popping_value(
                        adb_loginWithDelegation_t* _loginWithDelegation,
                        const axutil_env_t *env)
                {
                    axis2_char_t* value;

                    
                    
                    value = _loginWithDelegation->property_username;

                    _loginWithDelegation->property_username = (axis2_char_t*)NULL;
                    adb_loginWithDelegation_free(_loginWithDelegation, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_loginWithDelegation_free(
                adb_loginWithDelegation_t* _loginWithDelegation,
                const axutil_env_t *env)
        {
            
            
            return adb_loginWithDelegation_free_obj(
                _loginWithDelegation,
                env);
            
        }

        axis2_status_t AXIS2_CALL
        adb_loginWithDelegation_free_obj(
                adb_loginWithDelegation_t* _loginWithDelegation,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _loginWithDelegation, AXIS2_FAILURE);

            if (_loginWithDelegation->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _loginWithDelegation->property_Type);
            }

            adb_loginWithDelegation_reset_username(_loginWithDelegation, env);
            adb_loginWithDelegation_reset_password(_loginWithDelegation, env);
            adb_loginWithDelegation_reset_authenticatedUser(_loginWithDelegation, env);
            adb_loginWithDelegation_reset_remoteAddress(_loginWithDelegation, env);
            
              if(_loginWithDelegation->qname)
              {
                  axutil_qname_free (_loginWithDelegation->qname, env);
                  _loginWithDelegation->qname = NULL;
              }
            

            if(_loginWithDelegation)
            {
                AXIS2_FREE(env->allocator, _loginWithDelegation);
                _loginWithDelegation = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_loginWithDelegation_deserialize(
                adb_loginWithDelegation_t* _loginWithDelegation,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return adb_loginWithDelegation_deserialize_obj(
                _loginWithDelegation,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs);
            
        }

        axis2_status_t AXIS2_CALL
        adb_loginWithDelegation_deserialize_obj(
                adb_loginWithDelegation_t* _loginWithDelegation,
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
            AXIS2_PARAM_CHECK(env->error, _loginWithDelegation, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for loginWithDelegation : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              

                    current_element = (axiom_element_t *)axiom_node_get_data_element(parent, env);
                    qname = axiom_element_get_qname(current_element, env, parent);
                    if (axutil_qname_equals(qname, env, _loginWithDelegation-> qname))
                    {
                        
                          first_node = axiom_node_get_first_child(parent, env);
                          
                    }
                    else
                    {
                        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                              "Failed in building adb object for loginWithDelegation : "
                              "Expected %s but returned %s",
                              axutil_qname_to_string(_loginWithDelegation-> qname, env),
                              axutil_qname_to_string(qname, env));
                        
                        return AXIS2_FAILURE;
                    }
                    

                     
                     /*
                      * building username element
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
                                   
                                 element_qname = axutil_qname_create(env, "username", "http://authentication.services.core.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_loginWithDelegation_set_username(_loginWithDelegation, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for username ");
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
                                 
                                 element_qname = axutil_qname_create(env, "password", "http://authentication.services.core.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_loginWithDelegation_set_password(_loginWithDelegation, env,
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
                      * building authenticatedUser element
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
                                 
                                 element_qname = axutil_qname_create(env, "authenticatedUser", "http://authentication.services.core.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_loginWithDelegation_set_authenticatedUser(_loginWithDelegation, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for authenticatedUser ");
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
                      * building remoteAddress element
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
                                 
                                 element_qname = axutil_qname_create(env, "remoteAddress", "http://authentication.services.core.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_loginWithDelegation_set_remoteAddress(_loginWithDelegation, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for remoteAddress ");
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
          adb_loginWithDelegation_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_loginWithDelegation_declare_parent_namespaces(
                    adb_loginWithDelegation_t* _loginWithDelegation,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_loginWithDelegation_serialize(
                adb_loginWithDelegation_t* _loginWithDelegation,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
                return adb_loginWithDelegation_serialize_obj(
                    _loginWithDelegation, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            
        }

        axiom_node_t* AXIS2_CALL
        adb_loginWithDelegation_serialize_obj(
                adb_loginWithDelegation_t* _loginWithDelegation,
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
            AXIS2_PARAM_CHECK(env->error, _loginWithDelegation, NULL);
            
             
                    namespaces = axutil_hash_make(env);
                    next_ns_index = &next_ns_index_value;
                     
                           ns1 = axiom_namespace_create (env,
                                             "http://authentication.services.core.carbon.wso2.org",
                                             "n"); 
                           axutil_hash_set(namespaces, "http://authentication.services.core.carbon.wso2.org", AXIS2_HASH_KEY_STRING, axutil_strdup(env, "n"));
                       
                     
                    parent_element = axiom_element_create (env, NULL, "loginWithDelegation", ns1 , &parent);
                    
                    
                    axiom_element_set_namespace(parent_element, env, ns1, parent);


            
                    data_source = axiom_data_source_create(env, parent, &current_node);
                    stream = axiom_data_source_get_stream(data_source, env);
                  
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://authentication.services.core.carbon.wso2.org", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://authentication.services.core.carbon.wso2.org", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://authentication.services.core.carbon.wso2.org",
                                            p_prefix));
                       }
                      

                   if (!_loginWithDelegation->is_valid_username)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("username"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("username")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing username element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%susername>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%susername>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_1 = _loginWithDelegation->property_username;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://authentication.services.core.carbon.wso2.org", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://authentication.services.core.carbon.wso2.org", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://authentication.services.core.carbon.wso2.org",
                                            p_prefix));
                       }
                      

                   if (!_loginWithDelegation->is_valid_password)
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
                    
                           text_value_2 = _loginWithDelegation->property_password;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://authentication.services.core.carbon.wso2.org", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://authentication.services.core.carbon.wso2.org", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://authentication.services.core.carbon.wso2.org",
                                            p_prefix));
                       }
                      

                   if (!_loginWithDelegation->is_valid_authenticatedUser)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("authenticatedUser"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("authenticatedUser")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing authenticatedUser element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sauthenticatedUser>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sauthenticatedUser>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_3 = _loginWithDelegation->property_authenticatedUser;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://authentication.services.core.carbon.wso2.org", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://authentication.services.core.carbon.wso2.org", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://authentication.services.core.carbon.wso2.org",
                                            p_prefix));
                       }
                      

                   if (!_loginWithDelegation->is_valid_remoteAddress)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("remoteAddress"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("remoteAddress")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing remoteAddress element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sremoteAddress>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sremoteAddress>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_4 = _loginWithDelegation->property_remoteAddress;
                           
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
             * Getter for username by  Property Number 1
             */
            axis2_char_t* AXIS2_CALL
            adb_loginWithDelegation_get_property1(
                adb_loginWithDelegation_t* _loginWithDelegation,
                const axutil_env_t *env)
            {
                return adb_loginWithDelegation_get_username(_loginWithDelegation,
                                             env);
            }

            /**
             * getter for username.
             */
            axis2_char_t* AXIS2_CALL
            adb_loginWithDelegation_get_username(
                    adb_loginWithDelegation_t* _loginWithDelegation,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _loginWithDelegation, NULL);
                  

                return _loginWithDelegation->property_username;
             }

            /**
             * setter for username
             */
            axis2_status_t AXIS2_CALL
            adb_loginWithDelegation_set_username(
                    adb_loginWithDelegation_t* _loginWithDelegation,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_username)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _loginWithDelegation, AXIS2_FAILURE);
                
                if(_loginWithDelegation->is_valid_username &&
                        arg_username == _loginWithDelegation->property_username)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_loginWithDelegation_reset_username(_loginWithDelegation, env);

                
                if(NULL == arg_username)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _loginWithDelegation->property_username = (axis2_char_t *)axutil_strdup(env, arg_username);
                        if(NULL == _loginWithDelegation->property_username)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for username");
                            return AXIS2_FAILURE;
                        }
                        _loginWithDelegation->is_valid_username = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for username
            */
           axis2_status_t AXIS2_CALL
           adb_loginWithDelegation_reset_username(
                   adb_loginWithDelegation_t* _loginWithDelegation,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _loginWithDelegation, AXIS2_FAILURE);
               

               
            
                
                if(_loginWithDelegation->property_username != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _loginWithDelegation->property_username);
                     _loginWithDelegation->property_username = NULL;
                }
            
                
                
                _loginWithDelegation->is_valid_username = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether username is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_loginWithDelegation_is_username_nil(
                   adb_loginWithDelegation_t* _loginWithDelegation,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _loginWithDelegation, AXIS2_TRUE);
               
               return !_loginWithDelegation->is_valid_username;
           }

           /**
            * Set username to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_loginWithDelegation_set_username_nil(
                   adb_loginWithDelegation_t* _loginWithDelegation,
                   const axutil_env_t *env)
           {
               return adb_loginWithDelegation_reset_username(_loginWithDelegation, env);
           }

           

            /**
             * Getter for password by  Property Number 2
             */
            axis2_char_t* AXIS2_CALL
            adb_loginWithDelegation_get_property2(
                adb_loginWithDelegation_t* _loginWithDelegation,
                const axutil_env_t *env)
            {
                return adb_loginWithDelegation_get_password(_loginWithDelegation,
                                             env);
            }

            /**
             * getter for password.
             */
            axis2_char_t* AXIS2_CALL
            adb_loginWithDelegation_get_password(
                    adb_loginWithDelegation_t* _loginWithDelegation,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _loginWithDelegation, NULL);
                  

                return _loginWithDelegation->property_password;
             }

            /**
             * setter for password
             */
            axis2_status_t AXIS2_CALL
            adb_loginWithDelegation_set_password(
                    adb_loginWithDelegation_t* _loginWithDelegation,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_password)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _loginWithDelegation, AXIS2_FAILURE);
                
                if(_loginWithDelegation->is_valid_password &&
                        arg_password == _loginWithDelegation->property_password)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_loginWithDelegation_reset_password(_loginWithDelegation, env);

                
                if(NULL == arg_password)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _loginWithDelegation->property_password = (axis2_char_t *)axutil_strdup(env, arg_password);
                        if(NULL == _loginWithDelegation->property_password)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for password");
                            return AXIS2_FAILURE;
                        }
                        _loginWithDelegation->is_valid_password = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for password
            */
           axis2_status_t AXIS2_CALL
           adb_loginWithDelegation_reset_password(
                   adb_loginWithDelegation_t* _loginWithDelegation,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _loginWithDelegation, AXIS2_FAILURE);
               

               
            
                
                if(_loginWithDelegation->property_password != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _loginWithDelegation->property_password);
                     _loginWithDelegation->property_password = NULL;
                }
            
                
                
                _loginWithDelegation->is_valid_password = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether password is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_loginWithDelegation_is_password_nil(
                   adb_loginWithDelegation_t* _loginWithDelegation,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _loginWithDelegation, AXIS2_TRUE);
               
               return !_loginWithDelegation->is_valid_password;
           }

           /**
            * Set password to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_loginWithDelegation_set_password_nil(
                   adb_loginWithDelegation_t* _loginWithDelegation,
                   const axutil_env_t *env)
           {
               return adb_loginWithDelegation_reset_password(_loginWithDelegation, env);
           }

           

            /**
             * Getter for authenticatedUser by  Property Number 3
             */
            axis2_char_t* AXIS2_CALL
            adb_loginWithDelegation_get_property3(
                adb_loginWithDelegation_t* _loginWithDelegation,
                const axutil_env_t *env)
            {
                return adb_loginWithDelegation_get_authenticatedUser(_loginWithDelegation,
                                             env);
            }

            /**
             * getter for authenticatedUser.
             */
            axis2_char_t* AXIS2_CALL
            adb_loginWithDelegation_get_authenticatedUser(
                    adb_loginWithDelegation_t* _loginWithDelegation,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _loginWithDelegation, NULL);
                  

                return _loginWithDelegation->property_authenticatedUser;
             }

            /**
             * setter for authenticatedUser
             */
            axis2_status_t AXIS2_CALL
            adb_loginWithDelegation_set_authenticatedUser(
                    adb_loginWithDelegation_t* _loginWithDelegation,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_authenticatedUser)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _loginWithDelegation, AXIS2_FAILURE);
                
                if(_loginWithDelegation->is_valid_authenticatedUser &&
                        arg_authenticatedUser == _loginWithDelegation->property_authenticatedUser)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_loginWithDelegation_reset_authenticatedUser(_loginWithDelegation, env);

                
                if(NULL == arg_authenticatedUser)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _loginWithDelegation->property_authenticatedUser = (axis2_char_t *)axutil_strdup(env, arg_authenticatedUser);
                        if(NULL == _loginWithDelegation->property_authenticatedUser)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for authenticatedUser");
                            return AXIS2_FAILURE;
                        }
                        _loginWithDelegation->is_valid_authenticatedUser = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for authenticatedUser
            */
           axis2_status_t AXIS2_CALL
           adb_loginWithDelegation_reset_authenticatedUser(
                   adb_loginWithDelegation_t* _loginWithDelegation,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _loginWithDelegation, AXIS2_FAILURE);
               

               
            
                
                if(_loginWithDelegation->property_authenticatedUser != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _loginWithDelegation->property_authenticatedUser);
                     _loginWithDelegation->property_authenticatedUser = NULL;
                }
            
                
                
                _loginWithDelegation->is_valid_authenticatedUser = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether authenticatedUser is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_loginWithDelegation_is_authenticatedUser_nil(
                   adb_loginWithDelegation_t* _loginWithDelegation,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _loginWithDelegation, AXIS2_TRUE);
               
               return !_loginWithDelegation->is_valid_authenticatedUser;
           }

           /**
            * Set authenticatedUser to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_loginWithDelegation_set_authenticatedUser_nil(
                   adb_loginWithDelegation_t* _loginWithDelegation,
                   const axutil_env_t *env)
           {
               return adb_loginWithDelegation_reset_authenticatedUser(_loginWithDelegation, env);
           }

           

            /**
             * Getter for remoteAddress by  Property Number 4
             */
            axis2_char_t* AXIS2_CALL
            adb_loginWithDelegation_get_property4(
                adb_loginWithDelegation_t* _loginWithDelegation,
                const axutil_env_t *env)
            {
                return adb_loginWithDelegation_get_remoteAddress(_loginWithDelegation,
                                             env);
            }

            /**
             * getter for remoteAddress.
             */
            axis2_char_t* AXIS2_CALL
            adb_loginWithDelegation_get_remoteAddress(
                    adb_loginWithDelegation_t* _loginWithDelegation,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _loginWithDelegation, NULL);
                  

                return _loginWithDelegation->property_remoteAddress;
             }

            /**
             * setter for remoteAddress
             */
            axis2_status_t AXIS2_CALL
            adb_loginWithDelegation_set_remoteAddress(
                    adb_loginWithDelegation_t* _loginWithDelegation,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_remoteAddress)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _loginWithDelegation, AXIS2_FAILURE);
                
                if(_loginWithDelegation->is_valid_remoteAddress &&
                        arg_remoteAddress == _loginWithDelegation->property_remoteAddress)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_loginWithDelegation_reset_remoteAddress(_loginWithDelegation, env);

                
                if(NULL == arg_remoteAddress)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _loginWithDelegation->property_remoteAddress = (axis2_char_t *)axutil_strdup(env, arg_remoteAddress);
                        if(NULL == _loginWithDelegation->property_remoteAddress)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for remoteAddress");
                            return AXIS2_FAILURE;
                        }
                        _loginWithDelegation->is_valid_remoteAddress = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for remoteAddress
            */
           axis2_status_t AXIS2_CALL
           adb_loginWithDelegation_reset_remoteAddress(
                   adb_loginWithDelegation_t* _loginWithDelegation,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _loginWithDelegation, AXIS2_FAILURE);
               

               
            
                
                if(_loginWithDelegation->property_remoteAddress != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _loginWithDelegation->property_remoteAddress);
                     _loginWithDelegation->property_remoteAddress = NULL;
                }
            
                
                
                _loginWithDelegation->is_valid_remoteAddress = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether remoteAddress is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_loginWithDelegation_is_remoteAddress_nil(
                   adb_loginWithDelegation_t* _loginWithDelegation,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _loginWithDelegation, AXIS2_TRUE);
               
               return !_loginWithDelegation->is_valid_remoteAddress;
           }

           /**
            * Set remoteAddress to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_loginWithDelegation_set_remoteAddress_nil(
                   adb_loginWithDelegation_t* _loginWithDelegation,
                   const axutil_env_t *env)
           {
               return adb_loginWithDelegation_reset_remoteAddress(_loginWithDelegation, env);
           }

           

