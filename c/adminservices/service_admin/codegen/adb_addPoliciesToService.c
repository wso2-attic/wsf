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
         * adb_addPoliciesToService.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_addPoliciesToService.h"
        
               /*
                * implmentation of the addPoliciesToService|http://org.apache.axis2/xsd element
                */
           


        struct adb_addPoliciesToService
        {
            axis2_char_t *property_Type;

            
                axutil_qname_t* qname;
            axis2_char_t* property_serviceName;

                
                axis2_bool_t is_valid_serviceName;
            adb_Policy_t* property_policy;

                
                axis2_bool_t is_valid_policy;
            int property_policyType;

                
                axis2_bool_t is_valid_policyType;
            axutil_array_list_t* property_modulePaths;

                
                axis2_bool_t is_valid_modulePaths;
            
        };


       /************************* Private Function prototypes ********************************/
        

                axis2_status_t AXIS2_CALL
                adb_addPoliciesToService_set_policyType_nil(
                        adb_addPoliciesToService_t* _addPoliciesToService,
                        const axutil_env_t *env);
            


       /************************* Function Implmentations ********************************/
        adb_addPoliciesToService_t* AXIS2_CALL
        adb_addPoliciesToService_create(
            const axutil_env_t *env)
        {
            adb_addPoliciesToService_t *_addPoliciesToService = NULL;
            
                axutil_qname_t* qname = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _addPoliciesToService = (adb_addPoliciesToService_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_addPoliciesToService_t));

            if(NULL == _addPoliciesToService)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_addPoliciesToService, 0, sizeof(adb_addPoliciesToService_t));

            _addPoliciesToService->property_Type = axutil_strdup(env, "adb_addPoliciesToService");
            _addPoliciesToService->property_serviceName  = NULL;
                  _addPoliciesToService->is_valid_serviceName  = AXIS2_FALSE;
            _addPoliciesToService->property_policy  = NULL;
                  _addPoliciesToService->is_valid_policy  = AXIS2_FALSE;
            _addPoliciesToService->is_valid_policyType  = AXIS2_FALSE;
            _addPoliciesToService->property_modulePaths  = NULL;
                  _addPoliciesToService->is_valid_modulePaths  = AXIS2_FALSE;
            
                  qname =  axutil_qname_create (env,
                        "addPoliciesToService",
                        "http://org.apache.axis2/xsd",
                        NULL);
                _addPoliciesToService->qname = qname;
            

            return _addPoliciesToService;
        }

        adb_addPoliciesToService_t* AXIS2_CALL
        adb_addPoliciesToService_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _serviceName,
                adb_Policy_t* _policy,
                int _policyType,
                axutil_array_list_t* _modulePaths)
        {
            adb_addPoliciesToService_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_addPoliciesToService_create(env);

            
              status = adb_addPoliciesToService_set_serviceName(
                                     adb_obj,
                                     env,
                                     _serviceName);
              if(status == AXIS2_FAILURE) {
                  adb_addPoliciesToService_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_addPoliciesToService_set_policy(
                                     adb_obj,
                                     env,
                                     _policy);
              if(status == AXIS2_FAILURE) {
                  adb_addPoliciesToService_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_addPoliciesToService_set_policyType(
                                     adb_obj,
                                     env,
                                     _policyType);
              if(status == AXIS2_FAILURE) {
                  adb_addPoliciesToService_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_addPoliciesToService_set_modulePaths(
                                     adb_obj,
                                     env,
                                     _modulePaths);
              if(status == AXIS2_FAILURE) {
                  adb_addPoliciesToService_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_char_t* AXIS2_CALL
                adb_addPoliciesToService_free_popping_value(
                        adb_addPoliciesToService_t* _addPoliciesToService,
                        const axutil_env_t *env)
                {
                    axis2_char_t* value;

                    
                    
                    value = _addPoliciesToService->property_serviceName;

                    _addPoliciesToService->property_serviceName = (axis2_char_t*)NULL;
                    adb_addPoliciesToService_free(_addPoliciesToService, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_addPoliciesToService_free(
                adb_addPoliciesToService_t* _addPoliciesToService,
                const axutil_env_t *env)
        {
            
            
            return adb_addPoliciesToService_free_obj(
                _addPoliciesToService,
                env);
            
        }

        axis2_status_t AXIS2_CALL
        adb_addPoliciesToService_free_obj(
                adb_addPoliciesToService_t* _addPoliciesToService,
                const axutil_env_t *env)
        {
            
                int i = 0;
                int count = 0;
                void *element = NULL;
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _addPoliciesToService, AXIS2_FAILURE);

            if (_addPoliciesToService->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _addPoliciesToService->property_Type);
            }

            adb_addPoliciesToService_reset_serviceName(_addPoliciesToService, env);
            adb_addPoliciesToService_reset_policy(_addPoliciesToService, env);
            adb_addPoliciesToService_reset_policyType(_addPoliciesToService, env);
            adb_addPoliciesToService_reset_modulePaths(_addPoliciesToService, env);
            
              if(_addPoliciesToService->qname)
              {
                  axutil_qname_free (_addPoliciesToService->qname, env);
                  _addPoliciesToService->qname = NULL;
              }
            

            if(_addPoliciesToService)
            {
                AXIS2_FREE(env->allocator, _addPoliciesToService);
                _addPoliciesToService = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_addPoliciesToService_deserialize(
                adb_addPoliciesToService_t* _addPoliciesToService,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return adb_addPoliciesToService_deserialize_obj(
                _addPoliciesToService,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs);
            
        }

        axis2_status_t AXIS2_CALL
        adb_addPoliciesToService_deserialize_obj(
                adb_addPoliciesToService_t* _addPoliciesToService,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
          axiom_node_t *parent = *dp_parent;
          
          axis2_status_t status = AXIS2_SUCCESS;
          
              void *element = NULL;
           
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
            AXIS2_PARAM_CHECK(env->error, _addPoliciesToService, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for addPoliciesToService : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              

                    current_element = (axiom_element_t *)axiom_node_get_data_element(parent, env);
                    qname = axiom_element_get_qname(current_element, env, parent);
                    if (axutil_qname_equals(qname, env, _addPoliciesToService-> qname))
                    {
                        
                          first_node = axiom_node_get_first_child(parent, env);
                          
                    }
                    else
                    {
                        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                              "Failed in building adb object for addPoliciesToService : "
                              "Expected %s but returned %s",
                              axutil_qname_to_string(_addPoliciesToService-> qname, env),
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
                                   
                                 element_qname = axutil_qname_create(env, "serviceName", "http://org.apache.axis2/xsd", NULL);
                                 

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
                                            status = adb_addPoliciesToService_set_serviceName(_addPoliciesToService, env,
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
                      * building policy element
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
                                 
                                 element_qname = axutil_qname_create(env, "policy", "http://org.apache.axis2/xsd", NULL);
                                 

                           if (adb_Policy_is_particle() ||  
                                (current_node   && current_element && (axutil_qname_equals(element_qname, env, qname))))
                           {
                              if( current_node   && current_element && (axutil_qname_equals(element_qname, env, qname)))
                              {
                                is_early_node_valid = AXIS2_TRUE;
                              }
                              
                                 
                                      element = (void*)axis2_extension_mapper_create_from_node(env, &current_node, "adb_Policy");

                                      status =  adb_Policy_deserialize((adb_Policy_t*)element,
                                                                            env, &current_node, &is_early_node_valid, AXIS2_FALSE);
                                      if(AXIS2_FAILURE == status)
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building adb object for element policy");
                                      }
                                      else
                                      {
                                          status = adb_addPoliciesToService_set_policy(_addPoliciesToService, env,
                                                                   (adb_Policy_t*)element);
                                      }
                                    
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for policy ");
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
                      * building policyType element
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
                                 
                                 element_qname = axutil_qname_create(env, "policyType", "http://org.apache.axis2/xsd", NULL);
                                 

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
                                            status = adb_addPoliciesToService_set_policyType(_addPoliciesToService, env,
                                                                   atoi(text_value));
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element policyType");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for policyType ");
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
                     * building modulePaths array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building modulePaths element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "modulePaths", "http://org.apache.axis2/xsd", NULL);
                                  
                               
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
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for modulePaths ");
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
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "modulePaths (@minOccurs = '0') only have %d elements", i);
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
                                    status = adb_addPoliciesToService_set_modulePaths(_addPoliciesToService, env,
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
          adb_addPoliciesToService_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_addPoliciesToService_declare_parent_namespaces(
                    adb_addPoliciesToService_t* _addPoliciesToService,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_addPoliciesToService_serialize(
                adb_addPoliciesToService_t* _addPoliciesToService,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
                return adb_addPoliciesToService_serialize_obj(
                    _addPoliciesToService, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            
        }

        axiom_node_t* AXIS2_CALL
        adb_addPoliciesToService_serialize_obj(
                adb_addPoliciesToService_t* _addPoliciesToService,
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
                    
                    axis2_char_t text_value_2[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t text_value_3[ADB_DEFAULT_DIGIT_LIMIT];
                    
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
            AXIS2_PARAM_CHECK(env->error, _addPoliciesToService, NULL);
            
             
                    namespaces = axutil_hash_make(env);
                    next_ns_index = &next_ns_index_value;
                     
                           ns1 = axiom_namespace_create (env,
                                             "http://org.apache.axis2/xsd",
                                             "n"); 
                           axutil_hash_set(namespaces, "http://org.apache.axis2/xsd", AXIS2_HASH_KEY_STRING, axutil_strdup(env, "n"));
                       
                     
                    parent_element = axiom_element_create (env, NULL, "addPoliciesToService", ns1 , &parent);
                    
                    
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
                      

                   if (!_addPoliciesToService->is_valid_serviceName)
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
                    
                           text_value_1 = _addPoliciesToService->property_serviceName;
                           
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
                      

                   if (!_addPoliciesToService->is_valid_policy)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("policy"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("policy")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing policy element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%spolicy",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%spolicy>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                     
                            if(!adb_Policy_is_particle())
                            {
                                axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                            }
                            adb_Policy_serialize(_addPoliciesToService->property_policy, 
                                                                                 env, current_node, parent_element,
                                                                                 adb_Policy_is_particle() || AXIS2_FALSE, namespaces, next_ns_index);
                            
                            if(!adb_Policy_is_particle())
                            {
                                axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                            }
                            
                     
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
                      

                   if (!_addPoliciesToService->is_valid_policyType)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("policyType"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("policyType")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing policyType element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%spolicyType>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%spolicyType>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                               sprintf (text_value_3, AXIS2_PRINTF_INT32_FORMAT_SPECIFIER, _addPoliciesToService->property_policyType);
                             
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_3, axutil_strlen(text_value_3));
                           
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
                      

                   if (!_addPoliciesToService->is_valid_modulePaths)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("modulePaths"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("modulePaths")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing modulePaths array
                      */
                     if (_addPoliciesToService->property_modulePaths != NULL)
                     {
                        
                            sprintf(start_input_str, "<%s%smodulePaths>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%smodulePaths>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_addPoliciesToService->property_modulePaths, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_addPoliciesToService->property_modulePaths, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing modulePaths element
                      */

                    
                    
                           text_value_4 = (axis2_char_t*)element;
                           
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
             * Getter for serviceName by  Property Number 1
             */
            axis2_char_t* AXIS2_CALL
            adb_addPoliciesToService_get_property1(
                adb_addPoliciesToService_t* _addPoliciesToService,
                const axutil_env_t *env)
            {
                return adb_addPoliciesToService_get_serviceName(_addPoliciesToService,
                                             env);
            }

            /**
             * getter for serviceName.
             */
            axis2_char_t* AXIS2_CALL
            adb_addPoliciesToService_get_serviceName(
                    adb_addPoliciesToService_t* _addPoliciesToService,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addPoliciesToService, NULL);
                  

                return _addPoliciesToService->property_serviceName;
             }

            /**
             * setter for serviceName
             */
            axis2_status_t AXIS2_CALL
            adb_addPoliciesToService_set_serviceName(
                    adb_addPoliciesToService_t* _addPoliciesToService,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_serviceName)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addPoliciesToService, AXIS2_FAILURE);
                
                if(_addPoliciesToService->is_valid_serviceName &&
                        arg_serviceName == _addPoliciesToService->property_serviceName)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_addPoliciesToService_reset_serviceName(_addPoliciesToService, env);

                
                if(NULL == arg_serviceName)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addPoliciesToService->property_serviceName = (axis2_char_t *)axutil_strdup(env, arg_serviceName);
                        if(NULL == _addPoliciesToService->property_serviceName)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for serviceName");
                            return AXIS2_FAILURE;
                        }
                        _addPoliciesToService->is_valid_serviceName = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for serviceName
            */
           axis2_status_t AXIS2_CALL
           adb_addPoliciesToService_reset_serviceName(
                   adb_addPoliciesToService_t* _addPoliciesToService,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addPoliciesToService, AXIS2_FAILURE);
               

               
            
                
                if(_addPoliciesToService->property_serviceName != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _addPoliciesToService->property_serviceName);
                     _addPoliciesToService->property_serviceName = NULL;
                }
            
                
                
                _addPoliciesToService->is_valid_serviceName = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether serviceName is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addPoliciesToService_is_serviceName_nil(
                   adb_addPoliciesToService_t* _addPoliciesToService,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addPoliciesToService, AXIS2_TRUE);
               
               return !_addPoliciesToService->is_valid_serviceName;
           }

           /**
            * Set serviceName to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addPoliciesToService_set_serviceName_nil(
                   adb_addPoliciesToService_t* _addPoliciesToService,
                   const axutil_env_t *env)
           {
               return adb_addPoliciesToService_reset_serviceName(_addPoliciesToService, env);
           }

           

            /**
             * Getter for policy by  Property Number 2
             */
            adb_Policy_t* AXIS2_CALL
            adb_addPoliciesToService_get_property2(
                adb_addPoliciesToService_t* _addPoliciesToService,
                const axutil_env_t *env)
            {
                return adb_addPoliciesToService_get_policy(_addPoliciesToService,
                                             env);
            }

            /**
             * getter for policy.
             */
            adb_Policy_t* AXIS2_CALL
            adb_addPoliciesToService_get_policy(
                    adb_addPoliciesToService_t* _addPoliciesToService,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addPoliciesToService, NULL);
                  

                return _addPoliciesToService->property_policy;
             }

            /**
             * setter for policy
             */
            axis2_status_t AXIS2_CALL
            adb_addPoliciesToService_set_policy(
                    adb_addPoliciesToService_t* _addPoliciesToService,
                    const axutil_env_t *env,
                    adb_Policy_t*  arg_policy)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addPoliciesToService, AXIS2_FAILURE);
                
                if(_addPoliciesToService->is_valid_policy &&
                        arg_policy == _addPoliciesToService->property_policy)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_addPoliciesToService_reset_policy(_addPoliciesToService, env);

                
                if(NULL == arg_policy)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addPoliciesToService->property_policy = arg_policy;
                        _addPoliciesToService->is_valid_policy = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for policy
            */
           axis2_status_t AXIS2_CALL
           adb_addPoliciesToService_reset_policy(
                   adb_addPoliciesToService_t* _addPoliciesToService,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addPoliciesToService, AXIS2_FAILURE);
               

               
            
                
                if(_addPoliciesToService->property_policy != NULL)
                {
                   
                   adb_Policy_free(_addPoliciesToService->property_policy, env);
                     _addPoliciesToService->property_policy = NULL;
                }
            
                
                
                _addPoliciesToService->is_valid_policy = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether policy is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addPoliciesToService_is_policy_nil(
                   adb_addPoliciesToService_t* _addPoliciesToService,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addPoliciesToService, AXIS2_TRUE);
               
               return !_addPoliciesToService->is_valid_policy;
           }

           /**
            * Set policy to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addPoliciesToService_set_policy_nil(
                   adb_addPoliciesToService_t* _addPoliciesToService,
                   const axutil_env_t *env)
           {
               return adb_addPoliciesToService_reset_policy(_addPoliciesToService, env);
           }

           

            /**
             * Getter for policyType by  Property Number 3
             */
            int AXIS2_CALL
            adb_addPoliciesToService_get_property3(
                adb_addPoliciesToService_t* _addPoliciesToService,
                const axutil_env_t *env)
            {
                return adb_addPoliciesToService_get_policyType(_addPoliciesToService,
                                             env);
            }

            /**
             * getter for policyType.
             */
            int AXIS2_CALL
            adb_addPoliciesToService_get_policyType(
                    adb_addPoliciesToService_t* _addPoliciesToService,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (int)0);
                    AXIS2_PARAM_CHECK(env->error, _addPoliciesToService, (int)0);
                  

                return _addPoliciesToService->property_policyType;
             }

            /**
             * setter for policyType
             */
            axis2_status_t AXIS2_CALL
            adb_addPoliciesToService_set_policyType(
                    adb_addPoliciesToService_t* _addPoliciesToService,
                    const axutil_env_t *env,
                    const int  arg_policyType)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addPoliciesToService, AXIS2_FAILURE);
                
                if(_addPoliciesToService->is_valid_policyType &&
                        arg_policyType == _addPoliciesToService->property_policyType)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_addPoliciesToService_reset_policyType(_addPoliciesToService, env);

                _addPoliciesToService->property_policyType = arg_policyType;
                        _addPoliciesToService->is_valid_policyType = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for policyType
            */
           axis2_status_t AXIS2_CALL
           adb_addPoliciesToService_reset_policyType(
                   adb_addPoliciesToService_t* _addPoliciesToService,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addPoliciesToService, AXIS2_FAILURE);
               

               _addPoliciesToService->is_valid_policyType = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether policyType is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addPoliciesToService_is_policyType_nil(
                   adb_addPoliciesToService_t* _addPoliciesToService,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addPoliciesToService, AXIS2_TRUE);
               
               return !_addPoliciesToService->is_valid_policyType;
           }

           /**
            * Set policyType to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addPoliciesToService_set_policyType_nil(
                   adb_addPoliciesToService_t* _addPoliciesToService,
                   const axutil_env_t *env)
           {
               return adb_addPoliciesToService_reset_policyType(_addPoliciesToService, env);
           }

           

            /**
             * Getter for modulePaths by  Property Number 4
             */
            axutil_array_list_t* AXIS2_CALL
            adb_addPoliciesToService_get_property4(
                adb_addPoliciesToService_t* _addPoliciesToService,
                const axutil_env_t *env)
            {
                return adb_addPoliciesToService_get_modulePaths(_addPoliciesToService,
                                             env);
            }

            /**
             * getter for modulePaths.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_addPoliciesToService_get_modulePaths(
                    adb_addPoliciesToService_t* _addPoliciesToService,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addPoliciesToService, NULL);
                  

                return _addPoliciesToService->property_modulePaths;
             }

            /**
             * setter for modulePaths
             */
            axis2_status_t AXIS2_CALL
            adb_addPoliciesToService_set_modulePaths(
                    adb_addPoliciesToService_t* _addPoliciesToService,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_modulePaths)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addPoliciesToService, AXIS2_FAILURE);
                
                if(_addPoliciesToService->is_valid_modulePaths &&
                        arg_modulePaths == _addPoliciesToService->property_modulePaths)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_modulePaths, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "modulePaths has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_modulePaths, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_addPoliciesToService_reset_modulePaths(_addPoliciesToService, env);

                
                if(NULL == arg_modulePaths)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addPoliciesToService->property_modulePaths = arg_modulePaths;
                        if(non_nil_exists)
                        {
                            _addPoliciesToService->is_valid_modulePaths = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of modulePaths.
             */
            axis2_char_t* AXIS2_CALL
            adb_addPoliciesToService_get_modulePaths_at(
                    adb_addPoliciesToService_t* _addPoliciesToService,
                    const axutil_env_t *env, int i)
            {
                axis2_char_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addPoliciesToService, NULL);
                  

                if(_addPoliciesToService->property_modulePaths == NULL)
                {
                    return (axis2_char_t*)0;
                }
                ret_val = (axis2_char_t*)axutil_array_list_get(_addPoliciesToService->property_modulePaths, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of modulePaths.
             */
            axis2_status_t AXIS2_CALL
            adb_addPoliciesToService_set_modulePaths_at(
                    adb_addPoliciesToService_t* _addPoliciesToService,
                    const axutil_env_t *env, int i,
                    const axis2_char_t* arg_modulePaths)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addPoliciesToService, AXIS2_FAILURE);
                
                if( _addPoliciesToService->is_valid_modulePaths &&
                    _addPoliciesToService->property_modulePaths &&
                
                    arg_modulePaths == (axis2_char_t*)axutil_array_list_get(_addPoliciesToService->property_modulePaths, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_modulePaths)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_addPoliciesToService->property_modulePaths != NULL)
                        {
                            size = axutil_array_list_size(_addPoliciesToService->property_modulePaths, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_addPoliciesToService->property_modulePaths, env, i))
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
                  

                if(_addPoliciesToService->property_modulePaths == NULL)
                {
                    _addPoliciesToService->property_modulePaths = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_addPoliciesToService->property_modulePaths, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _addPoliciesToService->is_valid_modulePaths = AXIS2_FALSE;
                        axutil_array_list_set(_addPoliciesToService->property_modulePaths , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_addPoliciesToService->property_modulePaths , env, i, axutil_strdup(env, arg_modulePaths));
                  _addPoliciesToService->is_valid_modulePaths = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to modulePaths.
             */
            axis2_status_t AXIS2_CALL
            adb_addPoliciesToService_add_modulePaths(
                    adb_addPoliciesToService_t* _addPoliciesToService,
                    const axutil_env_t *env,
                    const axis2_char_t* arg_modulePaths)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addPoliciesToService, AXIS2_FAILURE);

                
                    if(NULL == arg_modulePaths)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_addPoliciesToService->property_modulePaths == NULL)
                {
                    _addPoliciesToService->property_modulePaths = axutil_array_list_create(env, 10);
                }
                if(_addPoliciesToService->property_modulePaths == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for modulePaths");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_addPoliciesToService->property_modulePaths , env, axutil_strdup(env, arg_modulePaths));
                  _addPoliciesToService->is_valid_modulePaths = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the modulePaths array.
             */
            int AXIS2_CALL
            adb_addPoliciesToService_sizeof_modulePaths(
                    adb_addPoliciesToService_t* _addPoliciesToService,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _addPoliciesToService, -1);
                if(_addPoliciesToService->property_modulePaths == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_addPoliciesToService->property_modulePaths, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_addPoliciesToService_remove_modulePaths_at(
                    adb_addPoliciesToService_t* _addPoliciesToService,
                    const axutil_env_t *env, int i)
            {
                return adb_addPoliciesToService_set_modulePaths_nil_at(_addPoliciesToService, env, i);
            }

            

           /**
            * resetter for modulePaths
            */
           axis2_status_t AXIS2_CALL
           adb_addPoliciesToService_reset_modulePaths(
                   adb_addPoliciesToService_t* _addPoliciesToService,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addPoliciesToService, AXIS2_FAILURE);
               

               
                  if (_addPoliciesToService->property_modulePaths != NULL)
                  {
                      count = axutil_array_list_size(_addPoliciesToService->property_modulePaths, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_addPoliciesToService->property_modulePaths, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, (axis2_char_t*)element);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_addPoliciesToService->property_modulePaths, env);
                  }
                _addPoliciesToService->is_valid_modulePaths = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether modulePaths is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addPoliciesToService_is_modulePaths_nil(
                   adb_addPoliciesToService_t* _addPoliciesToService,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addPoliciesToService, AXIS2_TRUE);
               
               return !_addPoliciesToService->is_valid_modulePaths;
           }

           /**
            * Set modulePaths to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addPoliciesToService_set_modulePaths_nil(
                   adb_addPoliciesToService_t* _addPoliciesToService,
                   const axutil_env_t *env)
           {
               return adb_addPoliciesToService_reset_modulePaths(_addPoliciesToService, env);
           }

           
           /**
            * Check whether modulePaths is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_addPoliciesToService_is_modulePaths_nil_at(
                   adb_addPoliciesToService_t* _addPoliciesToService,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addPoliciesToService, AXIS2_TRUE);
               
               return (_addPoliciesToService->is_valid_modulePaths == AXIS2_FALSE ||
                        NULL == _addPoliciesToService->property_modulePaths || 
                        NULL == axutil_array_list_get(_addPoliciesToService->property_modulePaths, env, i));
           }

           /**
            * Set modulePaths to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_addPoliciesToService_set_modulePaths_nil_at(
                   adb_addPoliciesToService_t* _addPoliciesToService,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addPoliciesToService, AXIS2_FAILURE);

                if(_addPoliciesToService->property_modulePaths == NULL ||
                            _addPoliciesToService->is_valid_modulePaths == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_addPoliciesToService->property_modulePaths, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_addPoliciesToService->property_modulePaths, env, i))
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
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of modulePaths is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_addPoliciesToService->property_modulePaths == NULL)
                {
                    _addPoliciesToService->is_valid_modulePaths = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_addPoliciesToService->property_modulePaths, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _addPoliciesToService->is_valid_modulePaths = AXIS2_FALSE;
                        axutil_array_list_set(_addPoliciesToService->property_modulePaths , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_addPoliciesToService->property_modulePaths , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

