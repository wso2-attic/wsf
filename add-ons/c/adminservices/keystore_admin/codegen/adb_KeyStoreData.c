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
         * adb_KeyStoreData.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_KeyStoreData.h"
        
                /*
                 * This type was generated from the piece of schema that had
                 * name = KeyStoreData
                 * Namespace URI = http://service.keystore.security.carbon.wso2.org/xsd
                 * Namespace Prefix = ns1
                 */
           


        struct adb_KeyStoreData
        {
            axis2_char_t *property_Type;

            axutil_array_list_t* property_certs;

                
                axis2_bool_t is_valid_certs;
            adb_CertData_t* property_key;

                
                axis2_bool_t is_valid_key;
            axis2_char_t* property_keyStoreName;

                
                axis2_bool_t is_valid_keyStoreName;
            axis2_char_t* property_keyStoreType;

                
                axis2_bool_t is_valid_keyStoreType;
            axis2_char_t* property_keyValue;

                
                axis2_bool_t is_valid_keyValue;
            axis2_bool_t property_privateStore;

                
                axis2_bool_t is_valid_privateStore;
            axis2_char_t* property_provider;

                
                axis2_bool_t is_valid_provider;
            
        };


       /************************* Private Function prototypes ********************************/
        

                axis2_status_t AXIS2_CALL
                adb_KeyStoreData_set_privateStore_nil(
                        adb_KeyStoreData_t* _KeyStoreData,
                        const axutil_env_t *env);
            


       /************************* Function Implmentations ********************************/
        adb_KeyStoreData_t* AXIS2_CALL
        adb_KeyStoreData_create(
            const axutil_env_t *env)
        {
            adb_KeyStoreData_t *_KeyStoreData = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _KeyStoreData = (adb_KeyStoreData_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_KeyStoreData_t));

            if(NULL == _KeyStoreData)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_KeyStoreData, 0, sizeof(adb_KeyStoreData_t));

            _KeyStoreData->property_Type = axutil_strdup(env, "adb_KeyStoreData");
            _KeyStoreData->property_certs  = NULL;
                  _KeyStoreData->is_valid_certs  = AXIS2_FALSE;
            _KeyStoreData->property_key  = NULL;
                  _KeyStoreData->is_valid_key  = AXIS2_FALSE;
            _KeyStoreData->property_keyStoreName  = NULL;
                  _KeyStoreData->is_valid_keyStoreName  = AXIS2_FALSE;
            _KeyStoreData->property_keyStoreType  = NULL;
                  _KeyStoreData->is_valid_keyStoreType  = AXIS2_FALSE;
            _KeyStoreData->property_keyValue  = NULL;
                  _KeyStoreData->is_valid_keyValue  = AXIS2_FALSE;
            _KeyStoreData->is_valid_privateStore  = AXIS2_FALSE;
            _KeyStoreData->property_provider  = NULL;
                  _KeyStoreData->is_valid_provider  = AXIS2_FALSE;
            

            return _KeyStoreData;
        }

        adb_KeyStoreData_t* AXIS2_CALL
        adb_KeyStoreData_create_with_values(
            const axutil_env_t *env,
                axutil_array_list_t* _certs,
                adb_CertData_t* _key,
                axis2_char_t* _keyStoreName,
                axis2_char_t* _keyStoreType,
                axis2_char_t* _keyValue,
                axis2_bool_t _privateStore,
                axis2_char_t* _provider)
        {
            adb_KeyStoreData_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_KeyStoreData_create(env);

            
              status = adb_KeyStoreData_set_certs(
                                     adb_obj,
                                     env,
                                     _certs);
              if(status == AXIS2_FAILURE) {
                  adb_KeyStoreData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_KeyStoreData_set_key(
                                     adb_obj,
                                     env,
                                     _key);
              if(status == AXIS2_FAILURE) {
                  adb_KeyStoreData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_KeyStoreData_set_keyStoreName(
                                     adb_obj,
                                     env,
                                     _keyStoreName);
              if(status == AXIS2_FAILURE) {
                  adb_KeyStoreData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_KeyStoreData_set_keyStoreType(
                                     adb_obj,
                                     env,
                                     _keyStoreType);
              if(status == AXIS2_FAILURE) {
                  adb_KeyStoreData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_KeyStoreData_set_keyValue(
                                     adb_obj,
                                     env,
                                     _keyValue);
              if(status == AXIS2_FAILURE) {
                  adb_KeyStoreData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_KeyStoreData_set_privateStore(
                                     adb_obj,
                                     env,
                                     _privateStore);
              if(status == AXIS2_FAILURE) {
                  adb_KeyStoreData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_KeyStoreData_set_provider(
                                     adb_obj,
                                     env,
                                     _provider);
              if(status == AXIS2_FAILURE) {
                  adb_KeyStoreData_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axutil_array_list_t* AXIS2_CALL
                adb_KeyStoreData_free_popping_value(
                        adb_KeyStoreData_t* _KeyStoreData,
                        const axutil_env_t *env)
                {
                    axutil_array_list_t* value;

                    
                    
                    value = _KeyStoreData->property_certs;

                    _KeyStoreData->property_certs = (axutil_array_list_t*)NULL;
                    adb_KeyStoreData_free(_KeyStoreData, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_KeyStoreData_free(
                adb_KeyStoreData_t* _KeyStoreData,
                const axutil_env_t *env)
        {
            
            
            return axis2_extension_mapper_free(
                (adb_type_t*) _KeyStoreData,
                env,
                "adb_KeyStoreData");
            
        }

        axis2_status_t AXIS2_CALL
        adb_KeyStoreData_free_obj(
                adb_KeyStoreData_t* _KeyStoreData,
                const axutil_env_t *env)
        {
            
                int i = 0;
                int count = 0;
                void *element = NULL;
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _KeyStoreData, AXIS2_FAILURE);

            if (_KeyStoreData->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _KeyStoreData->property_Type);
            }

            adb_KeyStoreData_reset_certs(_KeyStoreData, env);
            adb_KeyStoreData_reset_key(_KeyStoreData, env);
            adb_KeyStoreData_reset_keyStoreName(_KeyStoreData, env);
            adb_KeyStoreData_reset_keyStoreType(_KeyStoreData, env);
            adb_KeyStoreData_reset_keyValue(_KeyStoreData, env);
            adb_KeyStoreData_reset_privateStore(_KeyStoreData, env);
            adb_KeyStoreData_reset_provider(_KeyStoreData, env);
            

            if(_KeyStoreData)
            {
                AXIS2_FREE(env->allocator, _KeyStoreData);
                _KeyStoreData = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_KeyStoreData_deserialize(
                adb_KeyStoreData_t* _KeyStoreData,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return axis2_extension_mapper_deserialize(
                (adb_type_t*) _KeyStoreData,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs,
                "adb_KeyStoreData");
            
        }

        axis2_status_t AXIS2_CALL
        adb_KeyStoreData_deserialize_obj(
                adb_KeyStoreData_t* _KeyStoreData,
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
            AXIS2_PARAM_CHECK(env->error, _KeyStoreData, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for KeyStoreData : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              
                      
                      first_node = axiom_node_get_first_child(parent, env);
                      
                    
                    /*
                     * building certs array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building certs element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "certs", "http://service.keystore.security.carbon.wso2.org/xsd", NULL);
                                  
                               
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

                                  if (adb_CertData_is_particle() ||  
                                    (current_node && current_element && (axutil_qname_equals(element_qname, env, qname))))
                                  {
                                  
                                      if( current_node && current_element && (axutil_qname_equals(element_qname, env, qname)))
                                      {
                                          is_early_node_valid = AXIS2_TRUE;
                                      }
                                      
                                     
                                          element = (void*)axis2_extension_mapper_create_from_node(env, &current_node, "adb_CertData");
                                          
                                          status =  adb_CertData_deserialize((adb_CertData_t*)element, env,
                                                                                 &current_node, &is_early_node_valid, AXIS2_FALSE);
                                          
                                          if(AXIS2_FAILURE ==  status)
                                          {
                                              AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building element certs ");
                                          }
                                          else
                                          {
                                            axutil_array_list_add_at(arr_list, env, i, element);
                                          }
                                        
                                     if(AXIS2_FAILURE ==  status)
                                     {
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for certs ");
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
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "certs (@minOccurs = '0') only have %d elements", i);
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
                                    status = adb_KeyStoreData_set_certs(_KeyStoreData, env,
                                                                   arr_list);
                               }

                             
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 

                     
                     /*
                      * building key element
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
                                 
                                 element_qname = axutil_qname_create(env, "key", "http://service.keystore.security.carbon.wso2.org/xsd", NULL);
                                 

                           if (adb_CertData_is_particle() ||  
                                (current_node   && current_element && (axutil_qname_equals(element_qname, env, qname))))
                           {
                              if( current_node   && current_element && (axutil_qname_equals(element_qname, env, qname)))
                              {
                                is_early_node_valid = AXIS2_TRUE;
                              }
                              
                                 
                                      element = (void*)axis2_extension_mapper_create_from_node(env, &current_node, "adb_CertData");

                                      status =  adb_CertData_deserialize((adb_CertData_t*)element,
                                                                            env, &current_node, &is_early_node_valid, AXIS2_FALSE);
                                      if(AXIS2_FAILURE == status)
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building adb object for element key");
                                      }
                                      else
                                      {
                                          status = adb_KeyStoreData_set_key(_KeyStoreData, env,
                                                                   (adb_CertData_t*)element);
                                      }
                                    
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for key ");
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
                      * building keyStoreName element
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
                                 
                                 element_qname = axutil_qname_create(env, "keyStoreName", "http://service.keystore.security.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_KeyStoreData_set_keyStoreName(_KeyStoreData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for keyStoreName ");
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
                      * building keyStoreType element
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
                                 
                                 element_qname = axutil_qname_create(env, "keyStoreType", "http://service.keystore.security.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_KeyStoreData_set_keyStoreType(_KeyStoreData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for keyStoreType ");
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
                      * building keyValue element
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
                                 
                                 element_qname = axutil_qname_create(env, "keyValue", "http://service.keystore.security.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_KeyStoreData_set_keyValue(_KeyStoreData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for keyValue ");
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
                                 
                                 element_qname = axutil_qname_create(env, "privateStore", "http://service.keystore.security.carbon.wso2.org/xsd", NULL);
                                 

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
                                            if (!axutil_strcasecmp(text_value , "true"))
                                            {
                                                status = adb_KeyStoreData_set_privateStore(_KeyStoreData, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_KeyStoreData_set_privateStore(_KeyStoreData, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element privateStore");
                                          status = AXIS2_FAILURE;
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
                      * building provider element
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
                                 
                                 element_qname = axutil_qname_create(env, "provider", "http://service.keystore.security.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_KeyStoreData_set_provider(_KeyStoreData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for provider ");
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
          adb_KeyStoreData_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_KeyStoreData_declare_parent_namespaces(
                    adb_KeyStoreData_t* _KeyStoreData,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_KeyStoreData_serialize(
                adb_KeyStoreData_t* _KeyStoreData,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
            if (_KeyStoreData == NULL)
            {
                return adb_KeyStoreData_serialize_obj(
                    _KeyStoreData, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            }
            else
            {
                return axis2_extension_mapper_serialize(
                    (adb_type_t*) _KeyStoreData, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index, "adb_KeyStoreData");
            }
            
        }

        axiom_node_t* AXIS2_CALL
        adb_KeyStoreData_serialize_obj(
                adb_KeyStoreData_t* _KeyStoreData,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
             axis2_char_t *string_to_stream;
            
         
         axiom_node_t* current_node = NULL;
         int tag_closed = 0;
         
         axis2_char_t* xsi_prefix = NULL;
         
         axis2_char_t* type_attrib = NULL;
         axiom_namespace_t* xsi_ns = NULL;
         axiom_attribute_t* xsi_type_attri = NULL;
         
                axiom_namespace_t *ns1 = NULL;

                axis2_char_t *qname_uri = NULL;
                axis2_char_t *qname_prefix = NULL;
                axis2_char_t *p_prefix = NULL;
                axis2_bool_t ns_already_defined;
            
               int i = 0;
               int count = 0;
               void *element = NULL;
             
                    axis2_char_t text_value_1[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t text_value_2[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t *text_value_3;
                    axis2_char_t *text_value_3_temp;
                    
                    axis2_char_t *text_value_4;
                    axis2_char_t *text_value_4_temp;
                    
                    axis2_char_t *text_value_5;
                    axis2_char_t *text_value_5_temp;
                    
                    axis2_char_t text_value_6[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t *text_value_7;
                    axis2_char_t *text_value_7_temp;
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _KeyStoreData, NULL);
            
            
                    current_node = parent;
                    data_source = (axiom_data_source_t *)axiom_node_get_data_element(current_node, env);
                    if (!data_source)
                        return NULL;
                    stream = axiom_data_source_get_stream(data_source, env); /* assume parent is of type data source */
                    if (!stream)
                        return NULL;
                  
            if(!parent_tag_closed)
            {
            
              
 
              if(!(xsi_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://www.w3.org/2001/XMLSchema-instance", AXIS2_HASH_KEY_STRING)))
              {
                  /* it is better to stick with the standard prefix */
                  xsi_prefix = (axis2_char_t*)axutil_strdup(env, "xsi");
                  
                  axutil_hash_set(namespaces, "http://www.w3.org/2001/XMLSchema-instance", AXIS2_HASH_KEY_STRING, xsi_prefix);

                  if(parent_element)
                  {
                        axiom_namespace_t *element_ns = NULL;
                        element_ns = axiom_namespace_create(env, "http://www.w3.org/2001/XMLSchema-instance",
                                                            xsi_prefix);
                        axiom_element_declare_namespace_assume_param_ownership(parent_element, env, element_ns);
                  }
              }
              type_attrib = axutil_strcat(env, " ", xsi_prefix, ":type=\"KeyStoreData\"", NULL);
              axutil_stream_write(stream, env, type_attrib, axutil_strlen(type_attrib));

              AXIS2_FREE(env->allocator, type_attrib);
                
              string_to_stream = ">"; 
              axutil_stream_write(stream, env, string_to_stream, axutil_strlen(string_to_stream));
              tag_closed = 1;
            
            }
            else {
              /* if the parent tag closed we would be able to declare the type directly on the parent element */ 
              if(!(xsi_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://www.w3.org/2001/XMLSchema-instance", AXIS2_HASH_KEY_STRING)))
              {
                  /* it is better to stick with the standard prefix */
                  xsi_prefix = (axis2_char_t*)axutil_strdup(env, "xsi");
                  
                  axutil_hash_set(namespaces, "http://www.w3.org/2001/XMLSchema-instance", AXIS2_HASH_KEY_STRING, xsi_prefix);

                  if(parent_element)
                  {
                        axiom_namespace_t *element_ns = NULL;
                        element_ns = axiom_namespace_create(env, "http://www.w3.org/2001/XMLSchema-instance",
                                                            xsi_prefix);
                        axiom_element_declare_namespace_assume_param_ownership(parent_element, env, element_ns);
                  }
              }
            }
            xsi_ns = axiom_namespace_create (env,
                                 "http://service.keystore.security.carbon.wso2.org/xsd",
                                 xsi_prefix);
            xsi_type_attri = axiom_attribute_create (env, "type", "KeyStoreData", xsi_ns);
            
            axiom_element_add_attribute (parent_element, env, xsi_type_attri, parent);
        
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.keystore.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.keystore.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.keystore.security.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_KeyStoreData->is_valid_certs)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("certs"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("certs")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing certs array
                      */
                     if (_KeyStoreData->property_certs != NULL)
                     {
                        

                            sprintf(start_input_str, "<%s%scerts",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%scerts>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_KeyStoreData->property_certs, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_KeyStoreData->property_certs, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing certs element
                      */

                    
                     
                            if(!adb_CertData_is_particle())
                            {
                                axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                            }
                            adb_CertData_serialize((adb_CertData_t*)element, 
                                                                                 env, current_node, parent_element,
                                                                                 adb_CertData_is_particle() || AXIS2_FALSE, namespaces, next_ns_index);
                            
                            if(!adb_CertData_is_particle())
                            {
                                axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                            }
                            
                         }
                     }
                   
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.keystore.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.keystore.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.keystore.security.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_KeyStoreData->is_valid_key)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("key"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("key")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing key element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%skey",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%skey>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                     
                            if(!adb_CertData_is_particle())
                            {
                                axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                            }
                            adb_CertData_serialize(_KeyStoreData->property_key, 
                                                                                 env, current_node, parent_element,
                                                                                 adb_CertData_is_particle() || AXIS2_FALSE, namespaces, next_ns_index);
                            
                            if(!adb_CertData_is_particle())
                            {
                                axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                            }
                            
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.keystore.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.keystore.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.keystore.security.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_KeyStoreData->is_valid_keyStoreName)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("keyStoreName"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("keyStoreName")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing keyStoreName element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%skeyStoreName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%skeyStoreName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_3 = _KeyStoreData->property_keyStoreName;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.keystore.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.keystore.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.keystore.security.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_KeyStoreData->is_valid_keyStoreType)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("keyStoreType"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("keyStoreType")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing keyStoreType element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%skeyStoreType>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%skeyStoreType>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_4 = _KeyStoreData->property_keyStoreType;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.keystore.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.keystore.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.keystore.security.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_KeyStoreData->is_valid_keyValue)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("keyValue"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("keyValue")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing keyValue element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%skeyValue>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%skeyValue>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_5 = _KeyStoreData->property_keyValue;
                           
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
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.keystore.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.keystore.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.keystore.security.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_KeyStoreData->is_valid_privateStore)
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
                    
                           strcpy(text_value_6, (_KeyStoreData->property_privateStore)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_6, axutil_strlen(text_value_6));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.keystore.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.keystore.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.keystore.security.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_KeyStoreData->is_valid_provider)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("provider"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("provider")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing provider element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sprovider>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sprovider>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_7 = _KeyStoreData->property_provider;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_7_temp = axutil_xml_quote_string(env, text_value_7, AXIS2_TRUE);
                           if (text_value_7_temp)
                           {
                               axutil_stream_write(stream, env, text_value_7_temp, axutil_strlen(text_value_7_temp));
                               AXIS2_FREE(env->allocator, text_value_7_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_7, axutil_strlen(text_value_7));
                           }
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 

            return parent;
        }


        

            /**
             * Getter for certs by  Property Number 1
             */
            axutil_array_list_t* AXIS2_CALL
            adb_KeyStoreData_get_property1(
                adb_KeyStoreData_t* _KeyStoreData,
                const axutil_env_t *env)
            {
                return adb_KeyStoreData_get_certs(_KeyStoreData,
                                             env);
            }

            /**
             * getter for certs.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_KeyStoreData_get_certs(
                    adb_KeyStoreData_t* _KeyStoreData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _KeyStoreData, NULL);
                  

                return _KeyStoreData->property_certs;
             }

            /**
             * setter for certs
             */
            axis2_status_t AXIS2_CALL
            adb_KeyStoreData_set_certs(
                    adb_KeyStoreData_t* _KeyStoreData,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_certs)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _KeyStoreData, AXIS2_FAILURE);
                
                if(_KeyStoreData->is_valid_certs &&
                        arg_certs == _KeyStoreData->property_certs)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_certs, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "certs has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_certs, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_KeyStoreData_reset_certs(_KeyStoreData, env);

                
                if(NULL == arg_certs)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _KeyStoreData->property_certs = arg_certs;
                        if(non_nil_exists)
                        {
                            _KeyStoreData->is_valid_certs = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of certs.
             */
            adb_CertData_t* AXIS2_CALL
            adb_KeyStoreData_get_certs_at(
                    adb_KeyStoreData_t* _KeyStoreData,
                    const axutil_env_t *env, int i)
            {
                adb_CertData_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _KeyStoreData, NULL);
                  

                if(_KeyStoreData->property_certs == NULL)
                {
                    return (adb_CertData_t*)0;
                }
                ret_val = (adb_CertData_t*)axutil_array_list_get(_KeyStoreData->property_certs, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of certs.
             */
            axis2_status_t AXIS2_CALL
            adb_KeyStoreData_set_certs_at(
                    adb_KeyStoreData_t* _KeyStoreData,
                    const axutil_env_t *env, int i,
                    adb_CertData_t* arg_certs)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _KeyStoreData, AXIS2_FAILURE);
                
                if( _KeyStoreData->is_valid_certs &&
                    _KeyStoreData->property_certs &&
                
                    arg_certs == (adb_CertData_t*)axutil_array_list_get(_KeyStoreData->property_certs, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_certs)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_KeyStoreData->property_certs != NULL)
                        {
                            size = axutil_array_list_size(_KeyStoreData->property_certs, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_KeyStoreData->property_certs, env, i))
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
                  

                if(_KeyStoreData->property_certs == NULL)
                {
                    _KeyStoreData->property_certs = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_KeyStoreData->property_certs, env, i);
                if(NULL != element)
                {
                  
                  
                  adb_CertData_free((adb_CertData_t*)element, env);
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _KeyStoreData->is_valid_certs = AXIS2_FALSE;
                        axutil_array_list_set(_KeyStoreData->property_certs , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_KeyStoreData->property_certs , env, i, arg_certs);
                  _KeyStoreData->is_valid_certs = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to certs.
             */
            axis2_status_t AXIS2_CALL
            adb_KeyStoreData_add_certs(
                    adb_KeyStoreData_t* _KeyStoreData,
                    const axutil_env_t *env,
                    adb_CertData_t* arg_certs)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _KeyStoreData, AXIS2_FAILURE);

                
                    if(NULL == arg_certs)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_KeyStoreData->property_certs == NULL)
                {
                    _KeyStoreData->property_certs = axutil_array_list_create(env, 10);
                }
                if(_KeyStoreData->property_certs == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for certs");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_KeyStoreData->property_certs , env, arg_certs);
                  _KeyStoreData->is_valid_certs = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the certs array.
             */
            int AXIS2_CALL
            adb_KeyStoreData_sizeof_certs(
                    adb_KeyStoreData_t* _KeyStoreData,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _KeyStoreData, -1);
                if(_KeyStoreData->property_certs == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_KeyStoreData->property_certs, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_KeyStoreData_remove_certs_at(
                    adb_KeyStoreData_t* _KeyStoreData,
                    const axutil_env_t *env, int i)
            {
                return adb_KeyStoreData_set_certs_nil_at(_KeyStoreData, env, i);
            }

            

           /**
            * resetter for certs
            */
           axis2_status_t AXIS2_CALL
           adb_KeyStoreData_reset_certs(
                   adb_KeyStoreData_t* _KeyStoreData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _KeyStoreData, AXIS2_FAILURE);
               

               
                  if (_KeyStoreData->property_certs != NULL)
                  {
                      count = axutil_array_list_size(_KeyStoreData->property_certs, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_KeyStoreData->property_certs, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   adb_CertData_free((adb_CertData_t*)element, env);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_KeyStoreData->property_certs, env);
                  }
                _KeyStoreData->is_valid_certs = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether certs is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_KeyStoreData_is_certs_nil(
                   adb_KeyStoreData_t* _KeyStoreData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _KeyStoreData, AXIS2_TRUE);
               
               return !_KeyStoreData->is_valid_certs;
           }

           /**
            * Set certs to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_KeyStoreData_set_certs_nil(
                   adb_KeyStoreData_t* _KeyStoreData,
                   const axutil_env_t *env)
           {
               return adb_KeyStoreData_reset_certs(_KeyStoreData, env);
           }

           
           /**
            * Check whether certs is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_KeyStoreData_is_certs_nil_at(
                   adb_KeyStoreData_t* _KeyStoreData,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _KeyStoreData, AXIS2_TRUE);
               
               return (_KeyStoreData->is_valid_certs == AXIS2_FALSE ||
                        NULL == _KeyStoreData->property_certs || 
                        NULL == axutil_array_list_get(_KeyStoreData->property_certs, env, i));
           }

           /**
            * Set certs to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_KeyStoreData_set_certs_nil_at(
                   adb_KeyStoreData_t* _KeyStoreData,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _KeyStoreData, AXIS2_FAILURE);

                if(_KeyStoreData->property_certs == NULL ||
                            _KeyStoreData->is_valid_certs == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_KeyStoreData->property_certs, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_KeyStoreData->property_certs, env, i))
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
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of certs is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_KeyStoreData->property_certs == NULL)
                {
                    _KeyStoreData->is_valid_certs = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_KeyStoreData->property_certs, env, i);
                if(NULL != element)
                {
                  
                  
                  adb_CertData_free((adb_CertData_t*)element, env);
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _KeyStoreData->is_valid_certs = AXIS2_FALSE;
                        axutil_array_list_set(_KeyStoreData->property_certs , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_KeyStoreData->property_certs , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

            /**
             * Getter for key by  Property Number 2
             */
            adb_CertData_t* AXIS2_CALL
            adb_KeyStoreData_get_property2(
                adb_KeyStoreData_t* _KeyStoreData,
                const axutil_env_t *env)
            {
                return adb_KeyStoreData_get_key(_KeyStoreData,
                                             env);
            }

            /**
             * getter for key.
             */
            adb_CertData_t* AXIS2_CALL
            adb_KeyStoreData_get_key(
                    adb_KeyStoreData_t* _KeyStoreData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _KeyStoreData, NULL);
                  

                return _KeyStoreData->property_key;
             }

            /**
             * setter for key
             */
            axis2_status_t AXIS2_CALL
            adb_KeyStoreData_set_key(
                    adb_KeyStoreData_t* _KeyStoreData,
                    const axutil_env_t *env,
                    adb_CertData_t*  arg_key)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _KeyStoreData, AXIS2_FAILURE);
                
                if(_KeyStoreData->is_valid_key &&
                        arg_key == _KeyStoreData->property_key)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_KeyStoreData_reset_key(_KeyStoreData, env);

                
                if(NULL == arg_key)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _KeyStoreData->property_key = arg_key;
                        _KeyStoreData->is_valid_key = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for key
            */
           axis2_status_t AXIS2_CALL
           adb_KeyStoreData_reset_key(
                   adb_KeyStoreData_t* _KeyStoreData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _KeyStoreData, AXIS2_FAILURE);
               

               
            
                
                if(_KeyStoreData->property_key != NULL)
                {
                   
                   adb_CertData_free(_KeyStoreData->property_key, env);
                     _KeyStoreData->property_key = NULL;
                }
            
                
                
                _KeyStoreData->is_valid_key = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether key is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_KeyStoreData_is_key_nil(
                   adb_KeyStoreData_t* _KeyStoreData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _KeyStoreData, AXIS2_TRUE);
               
               return !_KeyStoreData->is_valid_key;
           }

           /**
            * Set key to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_KeyStoreData_set_key_nil(
                   adb_KeyStoreData_t* _KeyStoreData,
                   const axutil_env_t *env)
           {
               return adb_KeyStoreData_reset_key(_KeyStoreData, env);
           }

           

            /**
             * Getter for keyStoreName by  Property Number 3
             */
            axis2_char_t* AXIS2_CALL
            adb_KeyStoreData_get_property3(
                adb_KeyStoreData_t* _KeyStoreData,
                const axutil_env_t *env)
            {
                return adb_KeyStoreData_get_keyStoreName(_KeyStoreData,
                                             env);
            }

            /**
             * getter for keyStoreName.
             */
            axis2_char_t* AXIS2_CALL
            adb_KeyStoreData_get_keyStoreName(
                    adb_KeyStoreData_t* _KeyStoreData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _KeyStoreData, NULL);
                  

                return _KeyStoreData->property_keyStoreName;
             }

            /**
             * setter for keyStoreName
             */
            axis2_status_t AXIS2_CALL
            adb_KeyStoreData_set_keyStoreName(
                    adb_KeyStoreData_t* _KeyStoreData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_keyStoreName)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _KeyStoreData, AXIS2_FAILURE);
                
                if(_KeyStoreData->is_valid_keyStoreName &&
                        arg_keyStoreName == _KeyStoreData->property_keyStoreName)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_KeyStoreData_reset_keyStoreName(_KeyStoreData, env);

                
                if(NULL == arg_keyStoreName)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _KeyStoreData->property_keyStoreName = (axis2_char_t *)axutil_strdup(env, arg_keyStoreName);
                        if(NULL == _KeyStoreData->property_keyStoreName)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for keyStoreName");
                            return AXIS2_FAILURE;
                        }
                        _KeyStoreData->is_valid_keyStoreName = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for keyStoreName
            */
           axis2_status_t AXIS2_CALL
           adb_KeyStoreData_reset_keyStoreName(
                   adb_KeyStoreData_t* _KeyStoreData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _KeyStoreData, AXIS2_FAILURE);
               

               
            
                
                if(_KeyStoreData->property_keyStoreName != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _KeyStoreData->property_keyStoreName);
                     _KeyStoreData->property_keyStoreName = NULL;
                }
            
                
                
                _KeyStoreData->is_valid_keyStoreName = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether keyStoreName is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_KeyStoreData_is_keyStoreName_nil(
                   adb_KeyStoreData_t* _KeyStoreData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _KeyStoreData, AXIS2_TRUE);
               
               return !_KeyStoreData->is_valid_keyStoreName;
           }

           /**
            * Set keyStoreName to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_KeyStoreData_set_keyStoreName_nil(
                   adb_KeyStoreData_t* _KeyStoreData,
                   const axutil_env_t *env)
           {
               return adb_KeyStoreData_reset_keyStoreName(_KeyStoreData, env);
           }

           

            /**
             * Getter for keyStoreType by  Property Number 4
             */
            axis2_char_t* AXIS2_CALL
            adb_KeyStoreData_get_property4(
                adb_KeyStoreData_t* _KeyStoreData,
                const axutil_env_t *env)
            {
                return adb_KeyStoreData_get_keyStoreType(_KeyStoreData,
                                             env);
            }

            /**
             * getter for keyStoreType.
             */
            axis2_char_t* AXIS2_CALL
            adb_KeyStoreData_get_keyStoreType(
                    adb_KeyStoreData_t* _KeyStoreData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _KeyStoreData, NULL);
                  

                return _KeyStoreData->property_keyStoreType;
             }

            /**
             * setter for keyStoreType
             */
            axis2_status_t AXIS2_CALL
            adb_KeyStoreData_set_keyStoreType(
                    adb_KeyStoreData_t* _KeyStoreData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_keyStoreType)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _KeyStoreData, AXIS2_FAILURE);
                
                if(_KeyStoreData->is_valid_keyStoreType &&
                        arg_keyStoreType == _KeyStoreData->property_keyStoreType)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_KeyStoreData_reset_keyStoreType(_KeyStoreData, env);

                
                if(NULL == arg_keyStoreType)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _KeyStoreData->property_keyStoreType = (axis2_char_t *)axutil_strdup(env, arg_keyStoreType);
                        if(NULL == _KeyStoreData->property_keyStoreType)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for keyStoreType");
                            return AXIS2_FAILURE;
                        }
                        _KeyStoreData->is_valid_keyStoreType = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for keyStoreType
            */
           axis2_status_t AXIS2_CALL
           adb_KeyStoreData_reset_keyStoreType(
                   adb_KeyStoreData_t* _KeyStoreData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _KeyStoreData, AXIS2_FAILURE);
               

               
            
                
                if(_KeyStoreData->property_keyStoreType != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _KeyStoreData->property_keyStoreType);
                     _KeyStoreData->property_keyStoreType = NULL;
                }
            
                
                
                _KeyStoreData->is_valid_keyStoreType = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether keyStoreType is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_KeyStoreData_is_keyStoreType_nil(
                   adb_KeyStoreData_t* _KeyStoreData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _KeyStoreData, AXIS2_TRUE);
               
               return !_KeyStoreData->is_valid_keyStoreType;
           }

           /**
            * Set keyStoreType to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_KeyStoreData_set_keyStoreType_nil(
                   adb_KeyStoreData_t* _KeyStoreData,
                   const axutil_env_t *env)
           {
               return adb_KeyStoreData_reset_keyStoreType(_KeyStoreData, env);
           }

           

            /**
             * Getter for keyValue by  Property Number 5
             */
            axis2_char_t* AXIS2_CALL
            adb_KeyStoreData_get_property5(
                adb_KeyStoreData_t* _KeyStoreData,
                const axutil_env_t *env)
            {
                return adb_KeyStoreData_get_keyValue(_KeyStoreData,
                                             env);
            }

            /**
             * getter for keyValue.
             */
            axis2_char_t* AXIS2_CALL
            adb_KeyStoreData_get_keyValue(
                    adb_KeyStoreData_t* _KeyStoreData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _KeyStoreData, NULL);
                  

                return _KeyStoreData->property_keyValue;
             }

            /**
             * setter for keyValue
             */
            axis2_status_t AXIS2_CALL
            adb_KeyStoreData_set_keyValue(
                    adb_KeyStoreData_t* _KeyStoreData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_keyValue)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _KeyStoreData, AXIS2_FAILURE);
                
                if(_KeyStoreData->is_valid_keyValue &&
                        arg_keyValue == _KeyStoreData->property_keyValue)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_KeyStoreData_reset_keyValue(_KeyStoreData, env);

                
                if(NULL == arg_keyValue)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _KeyStoreData->property_keyValue = (axis2_char_t *)axutil_strdup(env, arg_keyValue);
                        if(NULL == _KeyStoreData->property_keyValue)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for keyValue");
                            return AXIS2_FAILURE;
                        }
                        _KeyStoreData->is_valid_keyValue = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for keyValue
            */
           axis2_status_t AXIS2_CALL
           adb_KeyStoreData_reset_keyValue(
                   adb_KeyStoreData_t* _KeyStoreData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _KeyStoreData, AXIS2_FAILURE);
               

               
            
                
                if(_KeyStoreData->property_keyValue != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _KeyStoreData->property_keyValue);
                     _KeyStoreData->property_keyValue = NULL;
                }
            
                
                
                _KeyStoreData->is_valid_keyValue = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether keyValue is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_KeyStoreData_is_keyValue_nil(
                   adb_KeyStoreData_t* _KeyStoreData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _KeyStoreData, AXIS2_TRUE);
               
               return !_KeyStoreData->is_valid_keyValue;
           }

           /**
            * Set keyValue to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_KeyStoreData_set_keyValue_nil(
                   adb_KeyStoreData_t* _KeyStoreData,
                   const axutil_env_t *env)
           {
               return adb_KeyStoreData_reset_keyValue(_KeyStoreData, env);
           }

           

            /**
             * Getter for privateStore by  Property Number 6
             */
            axis2_bool_t AXIS2_CALL
            adb_KeyStoreData_get_property6(
                adb_KeyStoreData_t* _KeyStoreData,
                const axutil_env_t *env)
            {
                return adb_KeyStoreData_get_privateStore(_KeyStoreData,
                                             env);
            }

            /**
             * getter for privateStore.
             */
            axis2_bool_t AXIS2_CALL
            adb_KeyStoreData_get_privateStore(
                    adb_KeyStoreData_t* _KeyStoreData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _KeyStoreData, (axis2_bool_t)0);
                  

                return _KeyStoreData->property_privateStore;
             }

            /**
             * setter for privateStore
             */
            axis2_status_t AXIS2_CALL
            adb_KeyStoreData_set_privateStore(
                    adb_KeyStoreData_t* _KeyStoreData,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_privateStore)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _KeyStoreData, AXIS2_FAILURE);
                
                if(_KeyStoreData->is_valid_privateStore &&
                        arg_privateStore == _KeyStoreData->property_privateStore)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_KeyStoreData_reset_privateStore(_KeyStoreData, env);

                _KeyStoreData->property_privateStore = arg_privateStore;
                        _KeyStoreData->is_valid_privateStore = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for privateStore
            */
           axis2_status_t AXIS2_CALL
           adb_KeyStoreData_reset_privateStore(
                   adb_KeyStoreData_t* _KeyStoreData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _KeyStoreData, AXIS2_FAILURE);
               

               _KeyStoreData->is_valid_privateStore = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether privateStore is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_KeyStoreData_is_privateStore_nil(
                   adb_KeyStoreData_t* _KeyStoreData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _KeyStoreData, AXIS2_TRUE);
               
               return !_KeyStoreData->is_valid_privateStore;
           }

           /**
            * Set privateStore to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_KeyStoreData_set_privateStore_nil(
                   adb_KeyStoreData_t* _KeyStoreData,
                   const axutil_env_t *env)
           {
               return adb_KeyStoreData_reset_privateStore(_KeyStoreData, env);
           }

           

            /**
             * Getter for provider by  Property Number 7
             */
            axis2_char_t* AXIS2_CALL
            adb_KeyStoreData_get_property7(
                adb_KeyStoreData_t* _KeyStoreData,
                const axutil_env_t *env)
            {
                return adb_KeyStoreData_get_provider(_KeyStoreData,
                                             env);
            }

            /**
             * getter for provider.
             */
            axis2_char_t* AXIS2_CALL
            adb_KeyStoreData_get_provider(
                    adb_KeyStoreData_t* _KeyStoreData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _KeyStoreData, NULL);
                  

                return _KeyStoreData->property_provider;
             }

            /**
             * setter for provider
             */
            axis2_status_t AXIS2_CALL
            adb_KeyStoreData_set_provider(
                    adb_KeyStoreData_t* _KeyStoreData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_provider)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _KeyStoreData, AXIS2_FAILURE);
                
                if(_KeyStoreData->is_valid_provider &&
                        arg_provider == _KeyStoreData->property_provider)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_KeyStoreData_reset_provider(_KeyStoreData, env);

                
                if(NULL == arg_provider)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _KeyStoreData->property_provider = (axis2_char_t *)axutil_strdup(env, arg_provider);
                        if(NULL == _KeyStoreData->property_provider)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for provider");
                            return AXIS2_FAILURE;
                        }
                        _KeyStoreData->is_valid_provider = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for provider
            */
           axis2_status_t AXIS2_CALL
           adb_KeyStoreData_reset_provider(
                   adb_KeyStoreData_t* _KeyStoreData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _KeyStoreData, AXIS2_FAILURE);
               

               
            
                
                if(_KeyStoreData->property_provider != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _KeyStoreData->property_provider);
                     _KeyStoreData->property_provider = NULL;
                }
            
                
                
                _KeyStoreData->is_valid_provider = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether provider is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_KeyStoreData_is_provider_nil(
                   adb_KeyStoreData_t* _KeyStoreData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _KeyStoreData, AXIS2_TRUE);
               
               return !_KeyStoreData->is_valid_provider;
           }

           /**
            * Set provider to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_KeyStoreData_set_provider_nil(
                   adb_KeyStoreData_t* _KeyStoreData,
                   const axutil_env_t *env)
           {
               return adb_KeyStoreData_reset_provider(_KeyStoreData, env);
           }

           

