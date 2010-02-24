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
         * adb_importCertToStore.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_importCertToStore.h"
        
               /*
                * implmentation of the importCertToStore|http://service.keystore.security.carbon.wso2.org element
                */
           


        struct adb_importCertToStore
        {
            axis2_char_t *property_Type;

            
                axutil_qname_t* qname;
            axis2_char_t* property_fileName;

                
                axis2_bool_t is_valid_fileName;
            axis2_char_t* property_fileData;

                
                axis2_bool_t is_valid_fileData;
            axis2_char_t* property_keyStoreName;

                
                axis2_bool_t is_valid_keyStoreName;
            
        };


       /************************* Private Function prototypes ********************************/
        


       /************************* Function Implmentations ********************************/
        adb_importCertToStore_t* AXIS2_CALL
        adb_importCertToStore_create(
            const axutil_env_t *env)
        {
            adb_importCertToStore_t *_importCertToStore = NULL;
            
                axutil_qname_t* qname = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _importCertToStore = (adb_importCertToStore_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_importCertToStore_t));

            if(NULL == _importCertToStore)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_importCertToStore, 0, sizeof(adb_importCertToStore_t));

            _importCertToStore->property_Type = axutil_strdup(env, "adb_importCertToStore");
            _importCertToStore->property_fileName  = NULL;
                  _importCertToStore->is_valid_fileName  = AXIS2_FALSE;
            _importCertToStore->property_fileData  = NULL;
                  _importCertToStore->is_valid_fileData  = AXIS2_FALSE;
            _importCertToStore->property_keyStoreName  = NULL;
                  _importCertToStore->is_valid_keyStoreName  = AXIS2_FALSE;
            
                  qname =  axutil_qname_create (env,
                        "importCertToStore",
                        "http://service.keystore.security.carbon.wso2.org",
                        NULL);
                _importCertToStore->qname = qname;
            

            return _importCertToStore;
        }

        adb_importCertToStore_t* AXIS2_CALL
        adb_importCertToStore_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _fileName,
                axis2_char_t* _fileData,
                axis2_char_t* _keyStoreName)
        {
            adb_importCertToStore_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_importCertToStore_create(env);

            
              status = adb_importCertToStore_set_fileName(
                                     adb_obj,
                                     env,
                                     _fileName);
              if(status == AXIS2_FAILURE) {
                  adb_importCertToStore_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_importCertToStore_set_fileData(
                                     adb_obj,
                                     env,
                                     _fileData);
              if(status == AXIS2_FAILURE) {
                  adb_importCertToStore_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_importCertToStore_set_keyStoreName(
                                     adb_obj,
                                     env,
                                     _keyStoreName);
              if(status == AXIS2_FAILURE) {
                  adb_importCertToStore_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_char_t* AXIS2_CALL
                adb_importCertToStore_free_popping_value(
                        adb_importCertToStore_t* _importCertToStore,
                        const axutil_env_t *env)
                {
                    axis2_char_t* value;

                    
                    
                    value = _importCertToStore->property_fileName;

                    _importCertToStore->property_fileName = (axis2_char_t*)NULL;
                    adb_importCertToStore_free(_importCertToStore, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_importCertToStore_free(
                adb_importCertToStore_t* _importCertToStore,
                const axutil_env_t *env)
        {
            
            
            return adb_importCertToStore_free_obj(
                _importCertToStore,
                env);
            
        }

        axis2_status_t AXIS2_CALL
        adb_importCertToStore_free_obj(
                adb_importCertToStore_t* _importCertToStore,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _importCertToStore, AXIS2_FAILURE);

            if (_importCertToStore->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _importCertToStore->property_Type);
            }

            adb_importCertToStore_reset_fileName(_importCertToStore, env);
            adb_importCertToStore_reset_fileData(_importCertToStore, env);
            adb_importCertToStore_reset_keyStoreName(_importCertToStore, env);
            
              if(_importCertToStore->qname)
              {
                  axutil_qname_free (_importCertToStore->qname, env);
                  _importCertToStore->qname = NULL;
              }
            

            if(_importCertToStore)
            {
                AXIS2_FREE(env->allocator, _importCertToStore);
                _importCertToStore = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_importCertToStore_deserialize(
                adb_importCertToStore_t* _importCertToStore,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return adb_importCertToStore_deserialize_obj(
                _importCertToStore,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs);
            
        }

        axis2_status_t AXIS2_CALL
        adb_importCertToStore_deserialize_obj(
                adb_importCertToStore_t* _importCertToStore,
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
            AXIS2_PARAM_CHECK(env->error, _importCertToStore, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for importCertToStore : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              

                    current_element = (axiom_element_t *)axiom_node_get_data_element(parent, env);
                    qname = axiom_element_get_qname(current_element, env, parent);
                    if (axutil_qname_equals(qname, env, _importCertToStore-> qname))
                    {
                        
                          first_node = axiom_node_get_first_child(parent, env);
                          
                    }
                    else
                    {
                        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                              "Failed in building adb object for importCertToStore : "
                              "Expected %s but returned %s",
                              axutil_qname_to_string(_importCertToStore-> qname, env),
                              axutil_qname_to_string(qname, env));
                        
                        return AXIS2_FAILURE;
                    }
                    

                     
                     /*
                      * building fileName element
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
                                   
                                 element_qname = axutil_qname_create(env, "fileName", "http://service.keystore.security.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_importCertToStore_set_fileName(_importCertToStore, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for fileName ");
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
                      * building fileData element
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
                                            status = adb_importCertToStore_set_fileData(_importCertToStore, env,
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
                                 
                                 element_qname = axutil_qname_create(env, "keyStoreName", "http://service.keystore.security.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_importCertToStore_set_keyStoreName(_importCertToStore, env,
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
                 
          return status;
       }

          axis2_bool_t AXIS2_CALL
          adb_importCertToStore_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_importCertToStore_declare_parent_namespaces(
                    adb_importCertToStore_t* _importCertToStore,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_importCertToStore_serialize(
                adb_importCertToStore_t* _importCertToStore,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
                return adb_importCertToStore_serialize_obj(
                    _importCertToStore, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            
        }

        axiom_node_t* AXIS2_CALL
        adb_importCertToStore_serialize_obj(
                adb_importCertToStore_t* _importCertToStore,
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
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

             
                int next_ns_index_value = 0;
            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _importCertToStore, NULL);
            
             
                    namespaces = axutil_hash_make(env);
                    next_ns_index = &next_ns_index_value;
                     
                           ns1 = axiom_namespace_create (env,
                                             "http://service.keystore.security.carbon.wso2.org",
                                             "n"); 
                           axutil_hash_set(namespaces, "http://service.keystore.security.carbon.wso2.org", AXIS2_HASH_KEY_STRING, axutil_strdup(env, "n"));
                       
                     
                    parent_element = axiom_element_create (env, NULL, "importCertToStore", ns1 , &parent);
                    
                    
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
                      

                   if (!_importCertToStore->is_valid_fileName)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("fileName"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("fileName")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing fileName element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sfileName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sfileName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_1 = _importCertToStore->property_fileName;
                           
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
                      

                   if (!_importCertToStore->is_valid_fileData)
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
                    
                           text_value_2 = _importCertToStore->property_fileData;
                           
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
                      

                   if (!_importCertToStore->is_valid_keyStoreName)
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
                    
                           text_value_3 = _importCertToStore->property_keyStoreName;
                           
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
             * Getter for fileName by  Property Number 1
             */
            axis2_char_t* AXIS2_CALL
            adb_importCertToStore_get_property1(
                adb_importCertToStore_t* _importCertToStore,
                const axutil_env_t *env)
            {
                return adb_importCertToStore_get_fileName(_importCertToStore,
                                             env);
            }

            /**
             * getter for fileName.
             */
            axis2_char_t* AXIS2_CALL
            adb_importCertToStore_get_fileName(
                    adb_importCertToStore_t* _importCertToStore,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _importCertToStore, NULL);
                  

                return _importCertToStore->property_fileName;
             }

            /**
             * setter for fileName
             */
            axis2_status_t AXIS2_CALL
            adb_importCertToStore_set_fileName(
                    adb_importCertToStore_t* _importCertToStore,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_fileName)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _importCertToStore, AXIS2_FAILURE);
                
                if(_importCertToStore->is_valid_fileName &&
                        arg_fileName == _importCertToStore->property_fileName)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_importCertToStore_reset_fileName(_importCertToStore, env);

                
                if(NULL == arg_fileName)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _importCertToStore->property_fileName = (axis2_char_t *)axutil_strdup(env, arg_fileName);
                        if(NULL == _importCertToStore->property_fileName)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for fileName");
                            return AXIS2_FAILURE;
                        }
                        _importCertToStore->is_valid_fileName = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for fileName
            */
           axis2_status_t AXIS2_CALL
           adb_importCertToStore_reset_fileName(
                   adb_importCertToStore_t* _importCertToStore,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _importCertToStore, AXIS2_FAILURE);
               

               
            
                
                if(_importCertToStore->property_fileName != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _importCertToStore->property_fileName);
                     _importCertToStore->property_fileName = NULL;
                }
            
                
                
                _importCertToStore->is_valid_fileName = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether fileName is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_importCertToStore_is_fileName_nil(
                   adb_importCertToStore_t* _importCertToStore,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _importCertToStore, AXIS2_TRUE);
               
               return !_importCertToStore->is_valid_fileName;
           }

           /**
            * Set fileName to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_importCertToStore_set_fileName_nil(
                   adb_importCertToStore_t* _importCertToStore,
                   const axutil_env_t *env)
           {
               return adb_importCertToStore_reset_fileName(_importCertToStore, env);
           }

           

            /**
             * Getter for fileData by  Property Number 2
             */
            axis2_char_t* AXIS2_CALL
            adb_importCertToStore_get_property2(
                adb_importCertToStore_t* _importCertToStore,
                const axutil_env_t *env)
            {
                return adb_importCertToStore_get_fileData(_importCertToStore,
                                             env);
            }

            /**
             * getter for fileData.
             */
            axis2_char_t* AXIS2_CALL
            adb_importCertToStore_get_fileData(
                    adb_importCertToStore_t* _importCertToStore,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _importCertToStore, NULL);
                  

                return _importCertToStore->property_fileData;
             }

            /**
             * setter for fileData
             */
            axis2_status_t AXIS2_CALL
            adb_importCertToStore_set_fileData(
                    adb_importCertToStore_t* _importCertToStore,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_fileData)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _importCertToStore, AXIS2_FAILURE);
                
                if(_importCertToStore->is_valid_fileData &&
                        arg_fileData == _importCertToStore->property_fileData)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_importCertToStore_reset_fileData(_importCertToStore, env);

                
                if(NULL == arg_fileData)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _importCertToStore->property_fileData = (axis2_char_t *)axutil_strdup(env, arg_fileData);
                        if(NULL == _importCertToStore->property_fileData)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for fileData");
                            return AXIS2_FAILURE;
                        }
                        _importCertToStore->is_valid_fileData = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for fileData
            */
           axis2_status_t AXIS2_CALL
           adb_importCertToStore_reset_fileData(
                   adb_importCertToStore_t* _importCertToStore,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _importCertToStore, AXIS2_FAILURE);
               

               
            
                
                if(_importCertToStore->property_fileData != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _importCertToStore->property_fileData);
                     _importCertToStore->property_fileData = NULL;
                }
            
                
                
                _importCertToStore->is_valid_fileData = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether fileData is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_importCertToStore_is_fileData_nil(
                   adb_importCertToStore_t* _importCertToStore,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _importCertToStore, AXIS2_TRUE);
               
               return !_importCertToStore->is_valid_fileData;
           }

           /**
            * Set fileData to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_importCertToStore_set_fileData_nil(
                   adb_importCertToStore_t* _importCertToStore,
                   const axutil_env_t *env)
           {
               return adb_importCertToStore_reset_fileData(_importCertToStore, env);
           }

           

            /**
             * Getter for keyStoreName by  Property Number 3
             */
            axis2_char_t* AXIS2_CALL
            adb_importCertToStore_get_property3(
                adb_importCertToStore_t* _importCertToStore,
                const axutil_env_t *env)
            {
                return adb_importCertToStore_get_keyStoreName(_importCertToStore,
                                             env);
            }

            /**
             * getter for keyStoreName.
             */
            axis2_char_t* AXIS2_CALL
            adb_importCertToStore_get_keyStoreName(
                    adb_importCertToStore_t* _importCertToStore,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _importCertToStore, NULL);
                  

                return _importCertToStore->property_keyStoreName;
             }

            /**
             * setter for keyStoreName
             */
            axis2_status_t AXIS2_CALL
            adb_importCertToStore_set_keyStoreName(
                    adb_importCertToStore_t* _importCertToStore,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_keyStoreName)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _importCertToStore, AXIS2_FAILURE);
                
                if(_importCertToStore->is_valid_keyStoreName &&
                        arg_keyStoreName == _importCertToStore->property_keyStoreName)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_importCertToStore_reset_keyStoreName(_importCertToStore, env);

                
                if(NULL == arg_keyStoreName)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _importCertToStore->property_keyStoreName = (axis2_char_t *)axutil_strdup(env, arg_keyStoreName);
                        if(NULL == _importCertToStore->property_keyStoreName)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for keyStoreName");
                            return AXIS2_FAILURE;
                        }
                        _importCertToStore->is_valid_keyStoreName = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for keyStoreName
            */
           axis2_status_t AXIS2_CALL
           adb_importCertToStore_reset_keyStoreName(
                   adb_importCertToStore_t* _importCertToStore,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _importCertToStore, AXIS2_FAILURE);
               

               
            
                
                if(_importCertToStore->property_keyStoreName != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _importCertToStore->property_keyStoreName);
                     _importCertToStore->property_keyStoreName = NULL;
                }
            
                
                
                _importCertToStore->is_valid_keyStoreName = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether keyStoreName is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_importCertToStore_is_keyStoreName_nil(
                   adb_importCertToStore_t* _importCertToStore,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _importCertToStore, AXIS2_TRUE);
               
               return !_importCertToStore->is_valid_keyStoreName;
           }

           /**
            * Set keyStoreName to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_importCertToStore_set_keyStoreName_nil(
                   adb_importCertToStore_t* _importCertToStore,
                   const axutil_env_t *env)
           {
               return adb_importCertToStore_reset_keyStoreName(_importCertToStore, env);
           }

           

