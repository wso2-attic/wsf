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
         * adb_applySecurity.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_applySecurity.h"
        
               /*
                * implmentation of the applySecurity|http://service.config.security.carbon.wso2.org element
                */
           


        struct adb_applySecurity
        {
            axis2_char_t *property_Type;

            
                axutil_qname_t* qname;
            axis2_char_t* property_serviceName;

                
                axis2_bool_t is_valid_serviceName;
            axis2_char_t* property_policyId;

                
                axis2_bool_t is_valid_policyId;
            axutil_array_list_t* property_trustedStores;

                
                axis2_bool_t is_valid_trustedStores;
            axis2_char_t* property_privateStore;

                
                axis2_bool_t is_valid_privateStore;
            axutil_array_list_t* property_userGroupNames;

                
                axis2_bool_t is_valid_userGroupNames;
            
        };


       /************************* Private Function prototypes ********************************/
        


       /************************* Function Implmentations ********************************/
        adb_applySecurity_t* AXIS2_CALL
        adb_applySecurity_create(
            const axutil_env_t *env)
        {
            adb_applySecurity_t *_applySecurity = NULL;
            
                axutil_qname_t* qname = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _applySecurity = (adb_applySecurity_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_applySecurity_t));

            if(NULL == _applySecurity)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_applySecurity, 0, sizeof(adb_applySecurity_t));

            _applySecurity->property_Type = axutil_strdup(env, "adb_applySecurity");
            _applySecurity->property_serviceName  = NULL;
                  _applySecurity->is_valid_serviceName  = AXIS2_FALSE;
            _applySecurity->property_policyId  = NULL;
                  _applySecurity->is_valid_policyId  = AXIS2_FALSE;
            _applySecurity->property_trustedStores  = NULL;
                  _applySecurity->is_valid_trustedStores  = AXIS2_FALSE;
            _applySecurity->property_privateStore  = NULL;
                  _applySecurity->is_valid_privateStore  = AXIS2_FALSE;
            _applySecurity->property_userGroupNames  = NULL;
                  _applySecurity->is_valid_userGroupNames  = AXIS2_FALSE;
            
                  qname =  axutil_qname_create (env,
                        "applySecurity",
                        "http://service.config.security.carbon.wso2.org",
                        NULL);
                _applySecurity->qname = qname;
            

            return _applySecurity;
        }

        adb_applySecurity_t* AXIS2_CALL
        adb_applySecurity_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _serviceName,
                axis2_char_t* _policyId,
                axutil_array_list_t* _trustedStores,
                axis2_char_t* _privateStore,
                axutil_array_list_t* _userGroupNames)
        {
            adb_applySecurity_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_applySecurity_create(env);

            
              status = adb_applySecurity_set_serviceName(
                                     adb_obj,
                                     env,
                                     _serviceName);
              if(status == AXIS2_FAILURE) {
                  adb_applySecurity_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_applySecurity_set_policyId(
                                     adb_obj,
                                     env,
                                     _policyId);
              if(status == AXIS2_FAILURE) {
                  adb_applySecurity_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_applySecurity_set_trustedStores(
                                     adb_obj,
                                     env,
                                     _trustedStores);
              if(status == AXIS2_FAILURE) {
                  adb_applySecurity_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_applySecurity_set_privateStore(
                                     adb_obj,
                                     env,
                                     _privateStore);
              if(status == AXIS2_FAILURE) {
                  adb_applySecurity_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_applySecurity_set_userGroupNames(
                                     adb_obj,
                                     env,
                                     _userGroupNames);
              if(status == AXIS2_FAILURE) {
                  adb_applySecurity_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_char_t* AXIS2_CALL
                adb_applySecurity_free_popping_value(
                        adb_applySecurity_t* _applySecurity,
                        const axutil_env_t *env)
                {
                    axis2_char_t* value;

                    
                    
                    value = _applySecurity->property_serviceName;

                    _applySecurity->property_serviceName = (axis2_char_t*)NULL;
                    adb_applySecurity_free(_applySecurity, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_applySecurity_free(
                adb_applySecurity_t* _applySecurity,
                const axutil_env_t *env)
        {
            
            
            return adb_applySecurity_free_obj(
                _applySecurity,
                env);
            
        }

        axis2_status_t AXIS2_CALL
        adb_applySecurity_free_obj(
                adb_applySecurity_t* _applySecurity,
                const axutil_env_t *env)
        {
            
                int i = 0;
                int count = 0;
                void *element = NULL;
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _applySecurity, AXIS2_FAILURE);

            if (_applySecurity->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _applySecurity->property_Type);
            }

            adb_applySecurity_reset_serviceName(_applySecurity, env);
            adb_applySecurity_reset_policyId(_applySecurity, env);
            adb_applySecurity_reset_trustedStores(_applySecurity, env);
            adb_applySecurity_reset_privateStore(_applySecurity, env);
            adb_applySecurity_reset_userGroupNames(_applySecurity, env);
            
              if(_applySecurity->qname)
              {
                  axutil_qname_free (_applySecurity->qname, env);
                  _applySecurity->qname = NULL;
              }
            

            if(_applySecurity)
            {
                AXIS2_FREE(env->allocator, _applySecurity);
                _applySecurity = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_applySecurity_deserialize(
                adb_applySecurity_t* _applySecurity,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return adb_applySecurity_deserialize_obj(
                _applySecurity,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs);
            
        }

        axis2_status_t AXIS2_CALL
        adb_applySecurity_deserialize_obj(
                adb_applySecurity_t* _applySecurity,
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
            AXIS2_PARAM_CHECK(env->error, _applySecurity, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for applySecurity : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              

                    current_element = (axiom_element_t *)axiom_node_get_data_element(parent, env);
                    qname = axiom_element_get_qname(current_element, env, parent);
                    if (axutil_qname_equals(qname, env, _applySecurity-> qname))
                    {
                        
                          first_node = axiom_node_get_first_child(parent, env);
                          
                    }
                    else
                    {
                        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                              "Failed in building adb object for applySecurity : "
                              "Expected %s but returned %s",
                              axutil_qname_to_string(_applySecurity-> qname, env),
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
                                   
                                 element_qname = axutil_qname_create(env, "serviceName", "http://service.config.security.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_applySecurity_set_serviceName(_applySecurity, env,
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
                      * building policyId element
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
                                 
                                 element_qname = axutil_qname_create(env, "policyId", "http://service.config.security.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_applySecurity_set_policyId(_applySecurity, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for policyId ");
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
                     * building trustedStores array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building trustedStores element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "trustedStores", "http://service.config.security.carbon.wso2.org", NULL);
                                  
                               
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
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for trustedStores ");
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
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "trustedStores (@minOccurs = '0') only have %d elements", i);
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
                                    status = adb_applySecurity_set_trustedStores(_applySecurity, env,
                                                                   arr_list);
                               }

                             
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 

                     
                     /*
                      * building privateStore element
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
                                 
                                 element_qname = axutil_qname_create(env, "privateStore", "http://service.config.security.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_applySecurity_set_privateStore(_applySecurity, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for privateStore ");
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
                     * building userGroupNames array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building userGroupNames element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "userGroupNames", "http://service.config.security.carbon.wso2.org", NULL);
                                  
                               
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
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for userGroupNames ");
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
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "userGroupNames (@minOccurs = '0') only have %d elements", i);
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
                                    status = adb_applySecurity_set_userGroupNames(_applySecurity, env,
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
          adb_applySecurity_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_applySecurity_declare_parent_namespaces(
                    adb_applySecurity_t* _applySecurity,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_applySecurity_serialize(
                adb_applySecurity_t* _applySecurity,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
                return adb_applySecurity_serialize_obj(
                    _applySecurity, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            
        }

        axiom_node_t* AXIS2_CALL
        adb_applySecurity_serialize_obj(
                adb_applySecurity_t* _applySecurity,
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
                    
                    axis2_char_t *text_value_4;
                    axis2_char_t *text_value_4_temp;
                    
                    axis2_char_t *text_value_5;
                    axis2_char_t *text_value_5_temp;
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

             
                int next_ns_index_value = 0;
            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _applySecurity, NULL);
            
             
                    namespaces = axutil_hash_make(env);
                    next_ns_index = &next_ns_index_value;
                     
                           ns1 = axiom_namespace_create (env,
                                             "http://service.config.security.carbon.wso2.org",
                                             "n"); 
                           axutil_hash_set(namespaces, "http://service.config.security.carbon.wso2.org", AXIS2_HASH_KEY_STRING, axutil_strdup(env, "n"));
                       
                     
                    parent_element = axiom_element_create (env, NULL, "applySecurity", ns1 , &parent);
                    
                    
                    axiom_element_set_namespace(parent_element, env, ns1, parent);


            
                    data_source = axiom_data_source_create(env, parent, &current_node);
                    stream = axiom_data_source_get_stream(data_source, env);
                  
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.config.security.carbon.wso2.org", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.config.security.carbon.wso2.org", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.config.security.carbon.wso2.org",
                                            p_prefix));
                       }
                      

                   if (!_applySecurity->is_valid_serviceName)
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
                    
                           text_value_1 = _applySecurity->property_serviceName;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.config.security.carbon.wso2.org", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.config.security.carbon.wso2.org", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.config.security.carbon.wso2.org",
                                            p_prefix));
                       }
                      

                   if (!_applySecurity->is_valid_policyId)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("policyId"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("policyId")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing policyId element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%spolicyId>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%spolicyId>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_2 = _applySecurity->property_policyId;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.config.security.carbon.wso2.org", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.config.security.carbon.wso2.org", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.config.security.carbon.wso2.org",
                                            p_prefix));
                       }
                      

                   if (!_applySecurity->is_valid_trustedStores)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("trustedStores"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("trustedStores")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing trustedStores array
                      */
                     if (_applySecurity->property_trustedStores != NULL)
                     {
                        
                            sprintf(start_input_str, "<%s%strustedStores>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%strustedStores>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_applySecurity->property_trustedStores, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_applySecurity->property_trustedStores, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing trustedStores element
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.config.security.carbon.wso2.org", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.config.security.carbon.wso2.org", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.config.security.carbon.wso2.org",
                                            p_prefix));
                       }
                      

                   if (!_applySecurity->is_valid_privateStore)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("privateStore"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("privateStore")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing privateStore element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sprivateStore>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sprivateStore>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_4 = _applySecurity->property_privateStore;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.config.security.carbon.wso2.org", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.config.security.carbon.wso2.org", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.config.security.carbon.wso2.org",
                                            p_prefix));
                       }
                      

                   if (!_applySecurity->is_valid_userGroupNames)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("userGroupNames"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("userGroupNames")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing userGroupNames array
                      */
                     if (_applySecurity->property_userGroupNames != NULL)
                     {
                        
                            sprintf(start_input_str, "<%s%suserGroupNames>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%suserGroupNames>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_applySecurity->property_userGroupNames, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_applySecurity->property_userGroupNames, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing userGroupNames element
                      */

                    
                    
                           text_value_5 = (axis2_char_t*)element;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_5_temp = axutil_xml_quote_string(env, text_value_5, AXIS2_TRUE);
                           if (text_value_5_temp)
                           {
                               axutil_stream_write(stream, env, text_value_5_temp, axutil_strlen(text_value_5_temp));
                               AXIS2_FREE(env->allocator, text_value_5_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_5, axutil_strlen(text_value_5));
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
            adb_applySecurity_get_property1(
                adb_applySecurity_t* _applySecurity,
                const axutil_env_t *env)
            {
                return adb_applySecurity_get_serviceName(_applySecurity,
                                             env);
            }

            /**
             * getter for serviceName.
             */
            axis2_char_t* AXIS2_CALL
            adb_applySecurity_get_serviceName(
                    adb_applySecurity_t* _applySecurity,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _applySecurity, NULL);
                  

                return _applySecurity->property_serviceName;
             }

            /**
             * setter for serviceName
             */
            axis2_status_t AXIS2_CALL
            adb_applySecurity_set_serviceName(
                    adb_applySecurity_t* _applySecurity,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_serviceName)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _applySecurity, AXIS2_FAILURE);
                
                if(_applySecurity->is_valid_serviceName &&
                        arg_serviceName == _applySecurity->property_serviceName)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_applySecurity_reset_serviceName(_applySecurity, env);

                
                if(NULL == arg_serviceName)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _applySecurity->property_serviceName = (axis2_char_t *)axutil_strdup(env, arg_serviceName);
                        if(NULL == _applySecurity->property_serviceName)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for serviceName");
                            return AXIS2_FAILURE;
                        }
                        _applySecurity->is_valid_serviceName = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for serviceName
            */
           axis2_status_t AXIS2_CALL
           adb_applySecurity_reset_serviceName(
                   adb_applySecurity_t* _applySecurity,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _applySecurity, AXIS2_FAILURE);
               

               
            
                
                if(_applySecurity->property_serviceName != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _applySecurity->property_serviceName);
                     _applySecurity->property_serviceName = NULL;
                }
            
                
                
                _applySecurity->is_valid_serviceName = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether serviceName is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_applySecurity_is_serviceName_nil(
                   adb_applySecurity_t* _applySecurity,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _applySecurity, AXIS2_TRUE);
               
               return !_applySecurity->is_valid_serviceName;
           }

           /**
            * Set serviceName to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_applySecurity_set_serviceName_nil(
                   adb_applySecurity_t* _applySecurity,
                   const axutil_env_t *env)
           {
               return adb_applySecurity_reset_serviceName(_applySecurity, env);
           }

           

            /**
             * Getter for policyId by  Property Number 2
             */
            axis2_char_t* AXIS2_CALL
            adb_applySecurity_get_property2(
                adb_applySecurity_t* _applySecurity,
                const axutil_env_t *env)
            {
                return adb_applySecurity_get_policyId(_applySecurity,
                                             env);
            }

            /**
             * getter for policyId.
             */
            axis2_char_t* AXIS2_CALL
            adb_applySecurity_get_policyId(
                    adb_applySecurity_t* _applySecurity,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _applySecurity, NULL);
                  

                return _applySecurity->property_policyId;
             }

            /**
             * setter for policyId
             */
            axis2_status_t AXIS2_CALL
            adb_applySecurity_set_policyId(
                    adb_applySecurity_t* _applySecurity,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_policyId)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _applySecurity, AXIS2_FAILURE);
                
                if(_applySecurity->is_valid_policyId &&
                        arg_policyId == _applySecurity->property_policyId)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_applySecurity_reset_policyId(_applySecurity, env);

                
                if(NULL == arg_policyId)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _applySecurity->property_policyId = (axis2_char_t *)axutil_strdup(env, arg_policyId);
                        if(NULL == _applySecurity->property_policyId)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for policyId");
                            return AXIS2_FAILURE;
                        }
                        _applySecurity->is_valid_policyId = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for policyId
            */
           axis2_status_t AXIS2_CALL
           adb_applySecurity_reset_policyId(
                   adb_applySecurity_t* _applySecurity,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _applySecurity, AXIS2_FAILURE);
               

               
            
                
                if(_applySecurity->property_policyId != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _applySecurity->property_policyId);
                     _applySecurity->property_policyId = NULL;
                }
            
                
                
                _applySecurity->is_valid_policyId = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether policyId is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_applySecurity_is_policyId_nil(
                   adb_applySecurity_t* _applySecurity,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _applySecurity, AXIS2_TRUE);
               
               return !_applySecurity->is_valid_policyId;
           }

           /**
            * Set policyId to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_applySecurity_set_policyId_nil(
                   adb_applySecurity_t* _applySecurity,
                   const axutil_env_t *env)
           {
               return adb_applySecurity_reset_policyId(_applySecurity, env);
           }

           

            /**
             * Getter for trustedStores by  Property Number 3
             */
            axutil_array_list_t* AXIS2_CALL
            adb_applySecurity_get_property3(
                adb_applySecurity_t* _applySecurity,
                const axutil_env_t *env)
            {
                return adb_applySecurity_get_trustedStores(_applySecurity,
                                             env);
            }

            /**
             * getter for trustedStores.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_applySecurity_get_trustedStores(
                    adb_applySecurity_t* _applySecurity,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _applySecurity, NULL);
                  

                return _applySecurity->property_trustedStores;
             }

            /**
             * setter for trustedStores
             */
            axis2_status_t AXIS2_CALL
            adb_applySecurity_set_trustedStores(
                    adb_applySecurity_t* _applySecurity,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_trustedStores)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _applySecurity, AXIS2_FAILURE);
                
                if(_applySecurity->is_valid_trustedStores &&
                        arg_trustedStores == _applySecurity->property_trustedStores)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_trustedStores, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "trustedStores has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_trustedStores, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_applySecurity_reset_trustedStores(_applySecurity, env);

                
                if(NULL == arg_trustedStores)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _applySecurity->property_trustedStores = arg_trustedStores;
                        if(non_nil_exists)
                        {
                            _applySecurity->is_valid_trustedStores = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of trustedStores.
             */
            axis2_char_t* AXIS2_CALL
            adb_applySecurity_get_trustedStores_at(
                    adb_applySecurity_t* _applySecurity,
                    const axutil_env_t *env, int i)
            {
                axis2_char_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _applySecurity, NULL);
                  

                if(_applySecurity->property_trustedStores == NULL)
                {
                    return (axis2_char_t*)0;
                }
                ret_val = (axis2_char_t*)axutil_array_list_get(_applySecurity->property_trustedStores, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of trustedStores.
             */
            axis2_status_t AXIS2_CALL
            adb_applySecurity_set_trustedStores_at(
                    adb_applySecurity_t* _applySecurity,
                    const axutil_env_t *env, int i,
                    const axis2_char_t* arg_trustedStores)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _applySecurity, AXIS2_FAILURE);
                
                if( _applySecurity->is_valid_trustedStores &&
                    _applySecurity->property_trustedStores &&
                
                    arg_trustedStores == (axis2_char_t*)axutil_array_list_get(_applySecurity->property_trustedStores, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_trustedStores)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_applySecurity->property_trustedStores != NULL)
                        {
                            size = axutil_array_list_size(_applySecurity->property_trustedStores, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_applySecurity->property_trustedStores, env, i))
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
                  

                if(_applySecurity->property_trustedStores == NULL)
                {
                    _applySecurity->property_trustedStores = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_applySecurity->property_trustedStores, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _applySecurity->is_valid_trustedStores = AXIS2_FALSE;
                        axutil_array_list_set(_applySecurity->property_trustedStores , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_applySecurity->property_trustedStores , env, i, axutil_strdup(env, arg_trustedStores));
                  _applySecurity->is_valid_trustedStores = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to trustedStores.
             */
            axis2_status_t AXIS2_CALL
            adb_applySecurity_add_trustedStores(
                    adb_applySecurity_t* _applySecurity,
                    const axutil_env_t *env,
                    const axis2_char_t* arg_trustedStores)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _applySecurity, AXIS2_FAILURE);

                
                    if(NULL == arg_trustedStores)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_applySecurity->property_trustedStores == NULL)
                {
                    _applySecurity->property_trustedStores = axutil_array_list_create(env, 10);
                }
                if(_applySecurity->property_trustedStores == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for trustedStores");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_applySecurity->property_trustedStores , env, axutil_strdup(env, arg_trustedStores));
                  _applySecurity->is_valid_trustedStores = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the trustedStores array.
             */
            int AXIS2_CALL
            adb_applySecurity_sizeof_trustedStores(
                    adb_applySecurity_t* _applySecurity,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _applySecurity, -1);
                if(_applySecurity->property_trustedStores == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_applySecurity->property_trustedStores, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_applySecurity_remove_trustedStores_at(
                    adb_applySecurity_t* _applySecurity,
                    const axutil_env_t *env, int i)
            {
                return adb_applySecurity_set_trustedStores_nil_at(_applySecurity, env, i);
            }

            

           /**
            * resetter for trustedStores
            */
           axis2_status_t AXIS2_CALL
           adb_applySecurity_reset_trustedStores(
                   adb_applySecurity_t* _applySecurity,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _applySecurity, AXIS2_FAILURE);
               

               
                  if (_applySecurity->property_trustedStores != NULL)
                  {
                      count = axutil_array_list_size(_applySecurity->property_trustedStores, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_applySecurity->property_trustedStores, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, (axis2_char_t*)element);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_applySecurity->property_trustedStores, env);
                  }
                _applySecurity->is_valid_trustedStores = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether trustedStores is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_applySecurity_is_trustedStores_nil(
                   adb_applySecurity_t* _applySecurity,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _applySecurity, AXIS2_TRUE);
               
               return !_applySecurity->is_valid_trustedStores;
           }

           /**
            * Set trustedStores to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_applySecurity_set_trustedStores_nil(
                   adb_applySecurity_t* _applySecurity,
                   const axutil_env_t *env)
           {
               return adb_applySecurity_reset_trustedStores(_applySecurity, env);
           }

           
           /**
            * Check whether trustedStores is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_applySecurity_is_trustedStores_nil_at(
                   adb_applySecurity_t* _applySecurity,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _applySecurity, AXIS2_TRUE);
               
               return (_applySecurity->is_valid_trustedStores == AXIS2_FALSE ||
                        NULL == _applySecurity->property_trustedStores || 
                        NULL == axutil_array_list_get(_applySecurity->property_trustedStores, env, i));
           }

           /**
            * Set trustedStores to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_applySecurity_set_trustedStores_nil_at(
                   adb_applySecurity_t* _applySecurity,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _applySecurity, AXIS2_FAILURE);

                if(_applySecurity->property_trustedStores == NULL ||
                            _applySecurity->is_valid_trustedStores == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_applySecurity->property_trustedStores, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_applySecurity->property_trustedStores, env, i))
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
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of trustedStores is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_applySecurity->property_trustedStores == NULL)
                {
                    _applySecurity->is_valid_trustedStores = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_applySecurity->property_trustedStores, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _applySecurity->is_valid_trustedStores = AXIS2_FALSE;
                        axutil_array_list_set(_applySecurity->property_trustedStores , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_applySecurity->property_trustedStores , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

            /**
             * Getter for privateStore by  Property Number 4
             */
            axis2_char_t* AXIS2_CALL
            adb_applySecurity_get_property4(
                adb_applySecurity_t* _applySecurity,
                const axutil_env_t *env)
            {
                return adb_applySecurity_get_privateStore(_applySecurity,
                                             env);
            }

            /**
             * getter for privateStore.
             */
            axis2_char_t* AXIS2_CALL
            adb_applySecurity_get_privateStore(
                    adb_applySecurity_t* _applySecurity,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _applySecurity, NULL);
                  

                return _applySecurity->property_privateStore;
             }

            /**
             * setter for privateStore
             */
            axis2_status_t AXIS2_CALL
            adb_applySecurity_set_privateStore(
                    adb_applySecurity_t* _applySecurity,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_privateStore)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _applySecurity, AXIS2_FAILURE);
                
                if(_applySecurity->is_valid_privateStore &&
                        arg_privateStore == _applySecurity->property_privateStore)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_applySecurity_reset_privateStore(_applySecurity, env);

                
                if(NULL == arg_privateStore)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _applySecurity->property_privateStore = (axis2_char_t *)axutil_strdup(env, arg_privateStore);
                        if(NULL == _applySecurity->property_privateStore)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for privateStore");
                            return AXIS2_FAILURE;
                        }
                        _applySecurity->is_valid_privateStore = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for privateStore
            */
           axis2_status_t AXIS2_CALL
           adb_applySecurity_reset_privateStore(
                   adb_applySecurity_t* _applySecurity,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _applySecurity, AXIS2_FAILURE);
               

               
            
                
                if(_applySecurity->property_privateStore != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _applySecurity->property_privateStore);
                     _applySecurity->property_privateStore = NULL;
                }
            
                
                
                _applySecurity->is_valid_privateStore = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether privateStore is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_applySecurity_is_privateStore_nil(
                   adb_applySecurity_t* _applySecurity,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _applySecurity, AXIS2_TRUE);
               
               return !_applySecurity->is_valid_privateStore;
           }

           /**
            * Set privateStore to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_applySecurity_set_privateStore_nil(
                   adb_applySecurity_t* _applySecurity,
                   const axutil_env_t *env)
           {
               return adb_applySecurity_reset_privateStore(_applySecurity, env);
           }

           

            /**
             * Getter for userGroupNames by  Property Number 5
             */
            axutil_array_list_t* AXIS2_CALL
            adb_applySecurity_get_property5(
                adb_applySecurity_t* _applySecurity,
                const axutil_env_t *env)
            {
                return adb_applySecurity_get_userGroupNames(_applySecurity,
                                             env);
            }

            /**
             * getter for userGroupNames.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_applySecurity_get_userGroupNames(
                    adb_applySecurity_t* _applySecurity,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _applySecurity, NULL);
                  

                return _applySecurity->property_userGroupNames;
             }

            /**
             * setter for userGroupNames
             */
            axis2_status_t AXIS2_CALL
            adb_applySecurity_set_userGroupNames(
                    adb_applySecurity_t* _applySecurity,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_userGroupNames)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _applySecurity, AXIS2_FAILURE);
                
                if(_applySecurity->is_valid_userGroupNames &&
                        arg_userGroupNames == _applySecurity->property_userGroupNames)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_userGroupNames, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "userGroupNames has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_userGroupNames, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_applySecurity_reset_userGroupNames(_applySecurity, env);

                
                if(NULL == arg_userGroupNames)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _applySecurity->property_userGroupNames = arg_userGroupNames;
                        if(non_nil_exists)
                        {
                            _applySecurity->is_valid_userGroupNames = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of userGroupNames.
             */
            axis2_char_t* AXIS2_CALL
            adb_applySecurity_get_userGroupNames_at(
                    adb_applySecurity_t* _applySecurity,
                    const axutil_env_t *env, int i)
            {
                axis2_char_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _applySecurity, NULL);
                  

                if(_applySecurity->property_userGroupNames == NULL)
                {
                    return (axis2_char_t*)0;
                }
                ret_val = (axis2_char_t*)axutil_array_list_get(_applySecurity->property_userGroupNames, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of userGroupNames.
             */
            axis2_status_t AXIS2_CALL
            adb_applySecurity_set_userGroupNames_at(
                    adb_applySecurity_t* _applySecurity,
                    const axutil_env_t *env, int i,
                    const axis2_char_t* arg_userGroupNames)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _applySecurity, AXIS2_FAILURE);
                
                if( _applySecurity->is_valid_userGroupNames &&
                    _applySecurity->property_userGroupNames &&
                
                    arg_userGroupNames == (axis2_char_t*)axutil_array_list_get(_applySecurity->property_userGroupNames, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_userGroupNames)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_applySecurity->property_userGroupNames != NULL)
                        {
                            size = axutil_array_list_size(_applySecurity->property_userGroupNames, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_applySecurity->property_userGroupNames, env, i))
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
                  

                if(_applySecurity->property_userGroupNames == NULL)
                {
                    _applySecurity->property_userGroupNames = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_applySecurity->property_userGroupNames, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _applySecurity->is_valid_userGroupNames = AXIS2_FALSE;
                        axutil_array_list_set(_applySecurity->property_userGroupNames , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_applySecurity->property_userGroupNames , env, i, axutil_strdup(env, arg_userGroupNames));
                  _applySecurity->is_valid_userGroupNames = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to userGroupNames.
             */
            axis2_status_t AXIS2_CALL
            adb_applySecurity_add_userGroupNames(
                    adb_applySecurity_t* _applySecurity,
                    const axutil_env_t *env,
                    const axis2_char_t* arg_userGroupNames)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _applySecurity, AXIS2_FAILURE);

                
                    if(NULL == arg_userGroupNames)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_applySecurity->property_userGroupNames == NULL)
                {
                    _applySecurity->property_userGroupNames = axutil_array_list_create(env, 10);
                }
                if(_applySecurity->property_userGroupNames == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for userGroupNames");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_applySecurity->property_userGroupNames , env, axutil_strdup(env, arg_userGroupNames));
                  _applySecurity->is_valid_userGroupNames = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the userGroupNames array.
             */
            int AXIS2_CALL
            adb_applySecurity_sizeof_userGroupNames(
                    adb_applySecurity_t* _applySecurity,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _applySecurity, -1);
                if(_applySecurity->property_userGroupNames == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_applySecurity->property_userGroupNames, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_applySecurity_remove_userGroupNames_at(
                    adb_applySecurity_t* _applySecurity,
                    const axutil_env_t *env, int i)
            {
                return adb_applySecurity_set_userGroupNames_nil_at(_applySecurity, env, i);
            }

            

           /**
            * resetter for userGroupNames
            */
           axis2_status_t AXIS2_CALL
           adb_applySecurity_reset_userGroupNames(
                   adb_applySecurity_t* _applySecurity,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _applySecurity, AXIS2_FAILURE);
               

               
                  if (_applySecurity->property_userGroupNames != NULL)
                  {
                      count = axutil_array_list_size(_applySecurity->property_userGroupNames, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_applySecurity->property_userGroupNames, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, (axis2_char_t*)element);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_applySecurity->property_userGroupNames, env);
                  }
                _applySecurity->is_valid_userGroupNames = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether userGroupNames is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_applySecurity_is_userGroupNames_nil(
                   adb_applySecurity_t* _applySecurity,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _applySecurity, AXIS2_TRUE);
               
               return !_applySecurity->is_valid_userGroupNames;
           }

           /**
            * Set userGroupNames to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_applySecurity_set_userGroupNames_nil(
                   adb_applySecurity_t* _applySecurity,
                   const axutil_env_t *env)
           {
               return adb_applySecurity_reset_userGroupNames(_applySecurity, env);
           }

           
           /**
            * Check whether userGroupNames is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_applySecurity_is_userGroupNames_nil_at(
                   adb_applySecurity_t* _applySecurity,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _applySecurity, AXIS2_TRUE);
               
               return (_applySecurity->is_valid_userGroupNames == AXIS2_FALSE ||
                        NULL == _applySecurity->property_userGroupNames || 
                        NULL == axutil_array_list_get(_applySecurity->property_userGroupNames, env, i));
           }

           /**
            * Set userGroupNames to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_applySecurity_set_userGroupNames_nil_at(
                   adb_applySecurity_t* _applySecurity,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _applySecurity, AXIS2_FAILURE);

                if(_applySecurity->property_userGroupNames == NULL ||
                            _applySecurity->is_valid_userGroupNames == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_applySecurity->property_userGroupNames, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_applySecurity->property_userGroupNames, env, i))
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
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of userGroupNames is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_applySecurity->property_userGroupNames == NULL)
                {
                    _applySecurity->is_valid_userGroupNames = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_applySecurity->property_userGroupNames, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _applySecurity->is_valid_userGroupNames = AXIS2_FALSE;
                        axutil_array_list_set(_applySecurity->property_userGroupNames , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_applySecurity->property_userGroupNames , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

