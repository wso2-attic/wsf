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
         * adb_addKeyStore.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_addKeyStore.h"
        
               /*
                * implmentation of the addKeyStore|http://service.keystore.security.carbon.wso2.org element
                */
           


        struct adb_addKeyStore
        {
            axis2_char_t *property_Type;

            
                axutil_qname_t* qname;
            axis2_char_t* property_fileData;

                
                axis2_bool_t is_valid_fileData;
            axis2_char_t* property_filename;

                
                axis2_bool_t is_valid_filename;
            axis2_char_t* property_password;

                
                axis2_bool_t is_valid_password;
            axis2_char_t* property_provider;

                
                axis2_bool_t is_valid_provider;
            axis2_char_t* property_type;

                
                axis2_bool_t is_valid_type;
            axis2_char_t* property_pvtkeyPass;

                
                axis2_bool_t is_valid_pvtkeyPass;
            
        };


       /************************* Private Function prototypes ********************************/
        


       /************************* Function Implmentations ********************************/
        adb_addKeyStore_t* AXIS2_CALL
        adb_addKeyStore_create(
            const axutil_env_t *env)
        {
            adb_addKeyStore_t *_addKeyStore = NULL;
            
                axutil_qname_t* qname = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _addKeyStore = (adb_addKeyStore_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_addKeyStore_t));

            if(NULL == _addKeyStore)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_addKeyStore, 0, sizeof(adb_addKeyStore_t));

            _addKeyStore->property_Type = axutil_strdup(env, "adb_addKeyStore");
            _addKeyStore->property_fileData  = NULL;
                  _addKeyStore->is_valid_fileData  = AXIS2_FALSE;
            _addKeyStore->property_filename  = NULL;
                  _addKeyStore->is_valid_filename  = AXIS2_FALSE;
            _addKeyStore->property_password  = NULL;
                  _addKeyStore->is_valid_password  = AXIS2_FALSE;
            _addKeyStore->property_provider  = NULL;
                  _addKeyStore->is_valid_provider  = AXIS2_FALSE;
            _addKeyStore->property_type  = NULL;
                  _addKeyStore->is_valid_type  = AXIS2_FALSE;
            _addKeyStore->property_pvtkeyPass  = NULL;
                  _addKeyStore->is_valid_pvtkeyPass  = AXIS2_FALSE;
            
                  qname =  axutil_qname_create (env,
                        "addKeyStore",
                        "http://service.keystore.security.carbon.wso2.org",
                        NULL);
                _addKeyStore->qname = qname;
            

            return _addKeyStore;
        }

        adb_addKeyStore_t* AXIS2_CALL
        adb_addKeyStore_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _fileData,
                axis2_char_t* _filename,
                axis2_char_t* _password,
                axis2_char_t* _provider,
                axis2_char_t* _type,
                axis2_char_t* _pvtkeyPass)
        {
            adb_addKeyStore_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_addKeyStore_create(env);

            
              status = adb_addKeyStore_set_fileData(
                                     adb_obj,
                                     env,
                                     _fileData);
              if(status == AXIS2_FAILURE) {
                  adb_addKeyStore_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_addKeyStore_set_filename(
                                     adb_obj,
                                     env,
                                     _filename);
              if(status == AXIS2_FAILURE) {
                  adb_addKeyStore_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_addKeyStore_set_password(
                                     adb_obj,
                                     env,
                                     _password);
              if(status == AXIS2_FAILURE) {
                  adb_addKeyStore_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_addKeyStore_set_provider(
                                     adb_obj,
                                     env,
                                     _provider);
              if(status == AXIS2_FAILURE) {
                  adb_addKeyStore_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_addKeyStore_set_type(
                                     adb_obj,
                                     env,
                                     _type);
              if(status == AXIS2_FAILURE) {
                  adb_addKeyStore_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_addKeyStore_set_pvtkeyPass(
                                     adb_obj,
                                     env,
                                     _pvtkeyPass);
              if(status == AXIS2_FAILURE) {
                  adb_addKeyStore_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_char_t* AXIS2_CALL
                adb_addKeyStore_free_popping_value(
                        adb_addKeyStore_t* _addKeyStore,
                        const axutil_env_t *env)
                {
                    axis2_char_t* value;

                    
                    
                    value = _addKeyStore->property_fileData;

                    _addKeyStore->property_fileData = (axis2_char_t*)NULL;
                    adb_addKeyStore_free(_addKeyStore, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_addKeyStore_free(
                adb_addKeyStore_t* _addKeyStore,
                const axutil_env_t *env)
        {
            
            
            return adb_addKeyStore_free_obj(
                _addKeyStore,
                env);
            
        }

        axis2_status_t AXIS2_CALL
        adb_addKeyStore_free_obj(
                adb_addKeyStore_t* _addKeyStore,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _addKeyStore, AXIS2_FAILURE);

            if (_addKeyStore->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _addKeyStore->property_Type);
            }

            adb_addKeyStore_reset_fileData(_addKeyStore, env);
            adb_addKeyStore_reset_filename(_addKeyStore, env);
            adb_addKeyStore_reset_password(_addKeyStore, env);
            adb_addKeyStore_reset_provider(_addKeyStore, env);
            adb_addKeyStore_reset_type(_addKeyStore, env);
            adb_addKeyStore_reset_pvtkeyPass(_addKeyStore, env);
            
              if(_addKeyStore->qname)
              {
                  axutil_qname_free (_addKeyStore->qname, env);
                  _addKeyStore->qname = NULL;
              }
            

            if(_addKeyStore)
            {
                AXIS2_FREE(env->allocator, _addKeyStore);
                _addKeyStore = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_addKeyStore_deserialize(
                adb_addKeyStore_t* _addKeyStore,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return adb_addKeyStore_deserialize_obj(
                _addKeyStore,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs);
            
        }

        axis2_status_t AXIS2_CALL
        adb_addKeyStore_deserialize_obj(
                adb_addKeyStore_t* _addKeyStore,
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
            AXIS2_PARAM_CHECK(env->error, _addKeyStore, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for addKeyStore : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              

                    current_element = (axiom_element_t *)axiom_node_get_data_element(parent, env);
                    qname = axiom_element_get_qname(current_element, env, parent);
                    if (axutil_qname_equals(qname, env, _addKeyStore-> qname))
                    {
                        
                          first_node = axiom_node_get_first_child(parent, env);
                          
                    }
                    else
                    {
                        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                              "Failed in building adb object for addKeyStore : "
                              "Expected %s but returned %s",
                              axutil_qname_to_string(_addKeyStore-> qname, env),
                              axutil_qname_to_string(qname, env));
                        
                        return AXIS2_FAILURE;
                    }
                    

                     
                     /*
                      * building fileData element
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
                                   
                                 element_qname = axutil_qname_create(env, "fileData", "http://service.keystore.security.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_addKeyStore_set_fileData(_addKeyStore, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for fileData ");
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
                      * building filename element
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
                                 
                                 element_qname = axutil_qname_create(env, "filename", "http://service.keystore.security.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_addKeyStore_set_filename(_addKeyStore, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for filename ");
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
                                 
                                 element_qname = axutil_qname_create(env, "password", "http://service.keystore.security.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_addKeyStore_set_password(_addKeyStore, env,
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
                                 
                                 element_qname = axutil_qname_create(env, "provider", "http://service.keystore.security.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_addKeyStore_set_provider(_addKeyStore, env,
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
                 

                     
                     /*
                      * building type element
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
                                 
                                 element_qname = axutil_qname_create(env, "type", "http://service.keystore.security.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_addKeyStore_set_type(_addKeyStore, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for type ");
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
                      * building pvtkeyPass element
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
                                 
                                 element_qname = axutil_qname_create(env, "pvtkeyPass", "http://service.keystore.security.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_addKeyStore_set_pvtkeyPass(_addKeyStore, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for pvtkeyPass ");
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
          adb_addKeyStore_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_addKeyStore_declare_parent_namespaces(
                    adb_addKeyStore_t* _addKeyStore,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_addKeyStore_serialize(
                adb_addKeyStore_t* _addKeyStore,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
                return adb_addKeyStore_serialize_obj(
                    _addKeyStore, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            
        }

        axiom_node_t* AXIS2_CALL
        adb_addKeyStore_serialize_obj(
                adb_addKeyStore_t* _addKeyStore,
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
                    
                    axis2_char_t *text_value_5;
                    axis2_char_t *text_value_5_temp;
                    
                    axis2_char_t *text_value_6;
                    axis2_char_t *text_value_6_temp;
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

             
                int next_ns_index_value = 0;
            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _addKeyStore, NULL);
            
             
                    namespaces = axutil_hash_make(env);
                    next_ns_index = &next_ns_index_value;
                     
                           ns1 = axiom_namespace_create (env,
                                             "http://service.keystore.security.carbon.wso2.org",
                                             "n"); 
                           axutil_hash_set(namespaces, "http://service.keystore.security.carbon.wso2.org", AXIS2_HASH_KEY_STRING, axutil_strdup(env, "n"));
                       
                     
                    parent_element = axiom_element_create (env, NULL, "addKeyStore", ns1 , &parent);
                    
                    
                    axiom_element_set_namespace(parent_element, env, ns1, parent);


            
                    data_source = axiom_data_source_create(env, parent, &current_node);
                    stream = axiom_data_source_get_stream(data_source, env);
                  
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.keystore.security.carbon.wso2.org", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.keystore.security.carbon.wso2.org", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.keystore.security.carbon.wso2.org",
                                            p_prefix));
                       }
                      

                   if (!_addKeyStore->is_valid_fileData)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("fileData"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("fileData")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing fileData element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sfileData>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sfileData>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_1 = _addKeyStore->property_fileData;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.keystore.security.carbon.wso2.org", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.keystore.security.carbon.wso2.org", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.keystore.security.carbon.wso2.org",
                                            p_prefix));
                       }
                      

                   if (!_addKeyStore->is_valid_filename)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("filename"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("filename")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing filename element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sfilename>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sfilename>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_2 = _addKeyStore->property_filename;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.keystore.security.carbon.wso2.org", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.keystore.security.carbon.wso2.org", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.keystore.security.carbon.wso2.org",
                                            p_prefix));
                       }
                      

                   if (!_addKeyStore->is_valid_password)
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
                    
                           text_value_3 = _addKeyStore->property_password;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.keystore.security.carbon.wso2.org", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.keystore.security.carbon.wso2.org", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.keystore.security.carbon.wso2.org",
                                            p_prefix));
                       }
                      

                   if (!_addKeyStore->is_valid_provider)
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
                    
                           text_value_4 = _addKeyStore->property_provider;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.keystore.security.carbon.wso2.org", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.keystore.security.carbon.wso2.org", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.keystore.security.carbon.wso2.org",
                                            p_prefix));
                       }
                      

                   if (!_addKeyStore->is_valid_type)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("type"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("type")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing type element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%stype>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%stype>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_5 = _addKeyStore->property_type;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.keystore.security.carbon.wso2.org", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.keystore.security.carbon.wso2.org", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.keystore.security.carbon.wso2.org",
                                            p_prefix));
                       }
                      

                   if (!_addKeyStore->is_valid_pvtkeyPass)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("pvtkeyPass"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("pvtkeyPass")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing pvtkeyPass element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%spvtkeyPass>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%spvtkeyPass>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_6 = _addKeyStore->property_pvtkeyPass;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_6_temp = axutil_xml_quote_string(env, text_value_6, AXIS2_TRUE);
                           if (text_value_6_temp)
                           {
                               axutil_stream_write(stream, env, text_value_6_temp, axutil_strlen(text_value_6_temp));
                               AXIS2_FREE(env->allocator, text_value_6_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_6, axutil_strlen(text_value_6));
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
             * Getter for fileData by  Property Number 1
             */
            axis2_char_t* AXIS2_CALL
            adb_addKeyStore_get_property1(
                adb_addKeyStore_t* _addKeyStore,
                const axutil_env_t *env)
            {
                return adb_addKeyStore_get_fileData(_addKeyStore,
                                             env);
            }

            /**
             * getter for fileData.
             */
            axis2_char_t* AXIS2_CALL
            adb_addKeyStore_get_fileData(
                    adb_addKeyStore_t* _addKeyStore,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addKeyStore, NULL);
                  

                return _addKeyStore->property_fileData;
             }

            /**
             * setter for fileData
             */
            axis2_status_t AXIS2_CALL
            adb_addKeyStore_set_fileData(
                    adb_addKeyStore_t* _addKeyStore,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_fileData)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addKeyStore, AXIS2_FAILURE);
                
                if(_addKeyStore->is_valid_fileData &&
                        arg_fileData == _addKeyStore->property_fileData)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_addKeyStore_reset_fileData(_addKeyStore, env);

                
                if(NULL == arg_fileData)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addKeyStore->property_fileData = (axis2_char_t *)axutil_strdup(env, arg_fileData);
                        if(NULL == _addKeyStore->property_fileData)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for fileData");
                            return AXIS2_FAILURE;
                        }
                        _addKeyStore->is_valid_fileData = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for fileData
            */
           axis2_status_t AXIS2_CALL
           adb_addKeyStore_reset_fileData(
                   adb_addKeyStore_t* _addKeyStore,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addKeyStore, AXIS2_FAILURE);
               

               
            
                
                if(_addKeyStore->property_fileData != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _addKeyStore->property_fileData);
                     _addKeyStore->property_fileData = NULL;
                }
            
                
                
                _addKeyStore->is_valid_fileData = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether fileData is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addKeyStore_is_fileData_nil(
                   adb_addKeyStore_t* _addKeyStore,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addKeyStore, AXIS2_TRUE);
               
               return !_addKeyStore->is_valid_fileData;
           }

           /**
            * Set fileData to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addKeyStore_set_fileData_nil(
                   adb_addKeyStore_t* _addKeyStore,
                   const axutil_env_t *env)
           {
               return adb_addKeyStore_reset_fileData(_addKeyStore, env);
           }

           

            /**
             * Getter for filename by  Property Number 2
             */
            axis2_char_t* AXIS2_CALL
            adb_addKeyStore_get_property2(
                adb_addKeyStore_t* _addKeyStore,
                const axutil_env_t *env)
            {
                return adb_addKeyStore_get_filename(_addKeyStore,
                                             env);
            }

            /**
             * getter for filename.
             */
            axis2_char_t* AXIS2_CALL
            adb_addKeyStore_get_filename(
                    adb_addKeyStore_t* _addKeyStore,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addKeyStore, NULL);
                  

                return _addKeyStore->property_filename;
             }

            /**
             * setter for filename
             */
            axis2_status_t AXIS2_CALL
            adb_addKeyStore_set_filename(
                    adb_addKeyStore_t* _addKeyStore,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_filename)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addKeyStore, AXIS2_FAILURE);
                
                if(_addKeyStore->is_valid_filename &&
                        arg_filename == _addKeyStore->property_filename)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_addKeyStore_reset_filename(_addKeyStore, env);

                
                if(NULL == arg_filename)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addKeyStore->property_filename = (axis2_char_t *)axutil_strdup(env, arg_filename);
                        if(NULL == _addKeyStore->property_filename)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for filename");
                            return AXIS2_FAILURE;
                        }
                        _addKeyStore->is_valid_filename = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for filename
            */
           axis2_status_t AXIS2_CALL
           adb_addKeyStore_reset_filename(
                   adb_addKeyStore_t* _addKeyStore,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addKeyStore, AXIS2_FAILURE);
               

               
            
                
                if(_addKeyStore->property_filename != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _addKeyStore->property_filename);
                     _addKeyStore->property_filename = NULL;
                }
            
                
                
                _addKeyStore->is_valid_filename = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether filename is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addKeyStore_is_filename_nil(
                   adb_addKeyStore_t* _addKeyStore,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addKeyStore, AXIS2_TRUE);
               
               return !_addKeyStore->is_valid_filename;
           }

           /**
            * Set filename to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addKeyStore_set_filename_nil(
                   adb_addKeyStore_t* _addKeyStore,
                   const axutil_env_t *env)
           {
               return adb_addKeyStore_reset_filename(_addKeyStore, env);
           }

           

            /**
             * Getter for password by  Property Number 3
             */
            axis2_char_t* AXIS2_CALL
            adb_addKeyStore_get_property3(
                adb_addKeyStore_t* _addKeyStore,
                const axutil_env_t *env)
            {
                return adb_addKeyStore_get_password(_addKeyStore,
                                             env);
            }

            /**
             * getter for password.
             */
            axis2_char_t* AXIS2_CALL
            adb_addKeyStore_get_password(
                    adb_addKeyStore_t* _addKeyStore,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addKeyStore, NULL);
                  

                return _addKeyStore->property_password;
             }

            /**
             * setter for password
             */
            axis2_status_t AXIS2_CALL
            adb_addKeyStore_set_password(
                    adb_addKeyStore_t* _addKeyStore,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_password)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addKeyStore, AXIS2_FAILURE);
                
                if(_addKeyStore->is_valid_password &&
                        arg_password == _addKeyStore->property_password)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_addKeyStore_reset_password(_addKeyStore, env);

                
                if(NULL == arg_password)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addKeyStore->property_password = (axis2_char_t *)axutil_strdup(env, arg_password);
                        if(NULL == _addKeyStore->property_password)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for password");
                            return AXIS2_FAILURE;
                        }
                        _addKeyStore->is_valid_password = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for password
            */
           axis2_status_t AXIS2_CALL
           adb_addKeyStore_reset_password(
                   adb_addKeyStore_t* _addKeyStore,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addKeyStore, AXIS2_FAILURE);
               

               
            
                
                if(_addKeyStore->property_password != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _addKeyStore->property_password);
                     _addKeyStore->property_password = NULL;
                }
            
                
                
                _addKeyStore->is_valid_password = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether password is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addKeyStore_is_password_nil(
                   adb_addKeyStore_t* _addKeyStore,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addKeyStore, AXIS2_TRUE);
               
               return !_addKeyStore->is_valid_password;
           }

           /**
            * Set password to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addKeyStore_set_password_nil(
                   adb_addKeyStore_t* _addKeyStore,
                   const axutil_env_t *env)
           {
               return adb_addKeyStore_reset_password(_addKeyStore, env);
           }

           

            /**
             * Getter for provider by  Property Number 4
             */
            axis2_char_t* AXIS2_CALL
            adb_addKeyStore_get_property4(
                adb_addKeyStore_t* _addKeyStore,
                const axutil_env_t *env)
            {
                return adb_addKeyStore_get_provider(_addKeyStore,
                                             env);
            }

            /**
             * getter for provider.
             */
            axis2_char_t* AXIS2_CALL
            adb_addKeyStore_get_provider(
                    adb_addKeyStore_t* _addKeyStore,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addKeyStore, NULL);
                  

                return _addKeyStore->property_provider;
             }

            /**
             * setter for provider
             */
            axis2_status_t AXIS2_CALL
            adb_addKeyStore_set_provider(
                    adb_addKeyStore_t* _addKeyStore,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_provider)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addKeyStore, AXIS2_FAILURE);
                
                if(_addKeyStore->is_valid_provider &&
                        arg_provider == _addKeyStore->property_provider)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_addKeyStore_reset_provider(_addKeyStore, env);

                
                if(NULL == arg_provider)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addKeyStore->property_provider = (axis2_char_t *)axutil_strdup(env, arg_provider);
                        if(NULL == _addKeyStore->property_provider)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for provider");
                            return AXIS2_FAILURE;
                        }
                        _addKeyStore->is_valid_provider = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for provider
            */
           axis2_status_t AXIS2_CALL
           adb_addKeyStore_reset_provider(
                   adb_addKeyStore_t* _addKeyStore,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addKeyStore, AXIS2_FAILURE);
               

               
            
                
                if(_addKeyStore->property_provider != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _addKeyStore->property_provider);
                     _addKeyStore->property_provider = NULL;
                }
            
                
                
                _addKeyStore->is_valid_provider = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether provider is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addKeyStore_is_provider_nil(
                   adb_addKeyStore_t* _addKeyStore,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addKeyStore, AXIS2_TRUE);
               
               return !_addKeyStore->is_valid_provider;
           }

           /**
            * Set provider to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addKeyStore_set_provider_nil(
                   adb_addKeyStore_t* _addKeyStore,
                   const axutil_env_t *env)
           {
               return adb_addKeyStore_reset_provider(_addKeyStore, env);
           }

           

            /**
             * Getter for type by  Property Number 5
             */
            axis2_char_t* AXIS2_CALL
            adb_addKeyStore_get_property5(
                adb_addKeyStore_t* _addKeyStore,
                const axutil_env_t *env)
            {
                return adb_addKeyStore_get_type(_addKeyStore,
                                             env);
            }

            /**
             * getter for type.
             */
            axis2_char_t* AXIS2_CALL
            adb_addKeyStore_get_type(
                    adb_addKeyStore_t* _addKeyStore,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addKeyStore, NULL);
                  

                return _addKeyStore->property_type;
             }

            /**
             * setter for type
             */
            axis2_status_t AXIS2_CALL
            adb_addKeyStore_set_type(
                    adb_addKeyStore_t* _addKeyStore,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_type)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addKeyStore, AXIS2_FAILURE);
                
                if(_addKeyStore->is_valid_type &&
                        arg_type == _addKeyStore->property_type)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_addKeyStore_reset_type(_addKeyStore, env);

                
                if(NULL == arg_type)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addKeyStore->property_type = (axis2_char_t *)axutil_strdup(env, arg_type);
                        if(NULL == _addKeyStore->property_type)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for type");
                            return AXIS2_FAILURE;
                        }
                        _addKeyStore->is_valid_type = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for type
            */
           axis2_status_t AXIS2_CALL
           adb_addKeyStore_reset_type(
                   adb_addKeyStore_t* _addKeyStore,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addKeyStore, AXIS2_FAILURE);
               

               
            
                
                if(_addKeyStore->property_type != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _addKeyStore->property_type);
                     _addKeyStore->property_type = NULL;
                }
            
                
                
                _addKeyStore->is_valid_type = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether type is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addKeyStore_is_type_nil(
                   adb_addKeyStore_t* _addKeyStore,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addKeyStore, AXIS2_TRUE);
               
               return !_addKeyStore->is_valid_type;
           }

           /**
            * Set type to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addKeyStore_set_type_nil(
                   adb_addKeyStore_t* _addKeyStore,
                   const axutil_env_t *env)
           {
               return adb_addKeyStore_reset_type(_addKeyStore, env);
           }

           

            /**
             * Getter for pvtkeyPass by  Property Number 6
             */
            axis2_char_t* AXIS2_CALL
            adb_addKeyStore_get_property6(
                adb_addKeyStore_t* _addKeyStore,
                const axutil_env_t *env)
            {
                return adb_addKeyStore_get_pvtkeyPass(_addKeyStore,
                                             env);
            }

            /**
             * getter for pvtkeyPass.
             */
            axis2_char_t* AXIS2_CALL
            adb_addKeyStore_get_pvtkeyPass(
                    adb_addKeyStore_t* _addKeyStore,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addKeyStore, NULL);
                  

                return _addKeyStore->property_pvtkeyPass;
             }

            /**
             * setter for pvtkeyPass
             */
            axis2_status_t AXIS2_CALL
            adb_addKeyStore_set_pvtkeyPass(
                    adb_addKeyStore_t* _addKeyStore,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_pvtkeyPass)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addKeyStore, AXIS2_FAILURE);
                
                if(_addKeyStore->is_valid_pvtkeyPass &&
                        arg_pvtkeyPass == _addKeyStore->property_pvtkeyPass)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_addKeyStore_reset_pvtkeyPass(_addKeyStore, env);

                
                if(NULL == arg_pvtkeyPass)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addKeyStore->property_pvtkeyPass = (axis2_char_t *)axutil_strdup(env, arg_pvtkeyPass);
                        if(NULL == _addKeyStore->property_pvtkeyPass)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for pvtkeyPass");
                            return AXIS2_FAILURE;
                        }
                        _addKeyStore->is_valid_pvtkeyPass = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for pvtkeyPass
            */
           axis2_status_t AXIS2_CALL
           adb_addKeyStore_reset_pvtkeyPass(
                   adb_addKeyStore_t* _addKeyStore,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addKeyStore, AXIS2_FAILURE);
               

               
            
                
                if(_addKeyStore->property_pvtkeyPass != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _addKeyStore->property_pvtkeyPass);
                     _addKeyStore->property_pvtkeyPass = NULL;
                }
            
                
                
                _addKeyStore->is_valid_pvtkeyPass = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether pvtkeyPass is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addKeyStore_is_pvtkeyPass_nil(
                   adb_addKeyStore_t* _addKeyStore,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addKeyStore, AXIS2_TRUE);
               
               return !_addKeyStore->is_valid_pvtkeyPass;
           }

           /**
            * Set pvtkeyPass to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addKeyStore_set_pvtkeyPass_nil(
                   adb_addKeyStore_t* _addKeyStore,
                   const axutil_env_t *env)
           {
               return adb_addKeyStore_reset_pvtkeyPass(_addKeyStore, env);
           }

           

