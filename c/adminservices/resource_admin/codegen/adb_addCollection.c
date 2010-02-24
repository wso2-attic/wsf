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
         * adb_addCollection.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_addCollection.h"
        
               /*
                * implmentation of the addCollection|http://services.resource.ui.mgt.registry.carbon.wso2.org element
                */
           


        struct adb_addCollection
        {
            axis2_char_t *property_Type;

            
                axutil_qname_t* qname;
            axis2_char_t* property_parentPath;

                
                axis2_bool_t is_valid_parentPath;
            axis2_char_t* property_collectionName;

                
                axis2_bool_t is_valid_collectionName;
            axis2_char_t* property_mediaType;

                
                axis2_bool_t is_valid_mediaType;
            axis2_char_t* property_description;

                
                axis2_bool_t is_valid_description;
            
        };


       /************************* Private Function prototypes ********************************/
        


       /************************* Function Implmentations ********************************/
        adb_addCollection_t* AXIS2_CALL
        adb_addCollection_create(
            const axutil_env_t *env)
        {
            adb_addCollection_t *_addCollection = NULL;
            
                axutil_qname_t* qname = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _addCollection = (adb_addCollection_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_addCollection_t));

            if(NULL == _addCollection)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_addCollection, 0, sizeof(adb_addCollection_t));

            _addCollection->property_Type = axutil_strdup(env, "adb_addCollection");
            _addCollection->property_parentPath  = NULL;
                  _addCollection->is_valid_parentPath  = AXIS2_FALSE;
            _addCollection->property_collectionName  = NULL;
                  _addCollection->is_valid_collectionName  = AXIS2_FALSE;
            _addCollection->property_mediaType  = NULL;
                  _addCollection->is_valid_mediaType  = AXIS2_FALSE;
            _addCollection->property_description  = NULL;
                  _addCollection->is_valid_description  = AXIS2_FALSE;
            
                  qname =  axutil_qname_create (env,
                        "addCollection",
                        "http://services.resource.ui.mgt.registry.carbon.wso2.org",
                        NULL);
                _addCollection->qname = qname;
            

            return _addCollection;
        }

        adb_addCollection_t* AXIS2_CALL
        adb_addCollection_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _parentPath,
                axis2_char_t* _collectionName,
                axis2_char_t* _mediaType,
                axis2_char_t* _description)
        {
            adb_addCollection_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_addCollection_create(env);

            
              status = adb_addCollection_set_parentPath(
                                     adb_obj,
                                     env,
                                     _parentPath);
              if(status == AXIS2_FAILURE) {
                  adb_addCollection_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_addCollection_set_collectionName(
                                     adb_obj,
                                     env,
                                     _collectionName);
              if(status == AXIS2_FAILURE) {
                  adb_addCollection_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_addCollection_set_mediaType(
                                     adb_obj,
                                     env,
                                     _mediaType);
              if(status == AXIS2_FAILURE) {
                  adb_addCollection_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_addCollection_set_description(
                                     adb_obj,
                                     env,
                                     _description);
              if(status == AXIS2_FAILURE) {
                  adb_addCollection_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_char_t* AXIS2_CALL
                adb_addCollection_free_popping_value(
                        adb_addCollection_t* _addCollection,
                        const axutil_env_t *env)
                {
                    axis2_char_t* value;

                    
                    
                    value = _addCollection->property_parentPath;

                    _addCollection->property_parentPath = (axis2_char_t*)NULL;
                    adb_addCollection_free(_addCollection, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_addCollection_free(
                adb_addCollection_t* _addCollection,
                const axutil_env_t *env)
        {
            
            
            return adb_addCollection_free_obj(
                _addCollection,
                env);
            
        }

        axis2_status_t AXIS2_CALL
        adb_addCollection_free_obj(
                adb_addCollection_t* _addCollection,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _addCollection, AXIS2_FAILURE);

            if (_addCollection->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _addCollection->property_Type);
            }

            adb_addCollection_reset_parentPath(_addCollection, env);
            adb_addCollection_reset_collectionName(_addCollection, env);
            adb_addCollection_reset_mediaType(_addCollection, env);
            adb_addCollection_reset_description(_addCollection, env);
            
              if(_addCollection->qname)
              {
                  axutil_qname_free (_addCollection->qname, env);
                  _addCollection->qname = NULL;
              }
            

            if(_addCollection)
            {
                AXIS2_FREE(env->allocator, _addCollection);
                _addCollection = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_addCollection_deserialize(
                adb_addCollection_t* _addCollection,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return adb_addCollection_deserialize_obj(
                _addCollection,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs);
            
        }

        axis2_status_t AXIS2_CALL
        adb_addCollection_deserialize_obj(
                adb_addCollection_t* _addCollection,
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
            AXIS2_PARAM_CHECK(env->error, _addCollection, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for addCollection : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              

                    current_element = (axiom_element_t *)axiom_node_get_data_element(parent, env);
                    qname = axiom_element_get_qname(current_element, env, parent);
                    if (axutil_qname_equals(qname, env, _addCollection-> qname))
                    {
                        
                          first_node = axiom_node_get_first_child(parent, env);
                          
                    }
                    else
                    {
                        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                              "Failed in building adb object for addCollection : "
                              "Expected %s but returned %s",
                              axutil_qname_to_string(_addCollection-> qname, env),
                              axutil_qname_to_string(qname, env));
                        
                        return AXIS2_FAILURE;
                    }
                    

                     
                     /*
                      * building parentPath element
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
                                   
                                 element_qname = axutil_qname_create(env, "parentPath", "http://services.resource.ui.mgt.registry.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_addCollection_set_parentPath(_addCollection, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for parentPath ");
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
                      * building collectionName element
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
                                 
                                 element_qname = axutil_qname_create(env, "collectionName", "http://services.resource.ui.mgt.registry.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_addCollection_set_collectionName(_addCollection, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for collectionName ");
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
                      * building mediaType element
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
                                 
                                 element_qname = axutil_qname_create(env, "mediaType", "http://services.resource.ui.mgt.registry.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_addCollection_set_mediaType(_addCollection, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for mediaType ");
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
                      * building description element
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
                                 
                                 element_qname = axutil_qname_create(env, "description", "http://services.resource.ui.mgt.registry.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_addCollection_set_description(_addCollection, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for description ");
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
          adb_addCollection_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_addCollection_declare_parent_namespaces(
                    adb_addCollection_t* _addCollection,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_addCollection_serialize(
                adb_addCollection_t* _addCollection,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
                return adb_addCollection_serialize_obj(
                    _addCollection, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            
        }

        axiom_node_t* AXIS2_CALL
        adb_addCollection_serialize_obj(
                adb_addCollection_t* _addCollection,
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
            AXIS2_PARAM_CHECK(env->error, _addCollection, NULL);
            
             
                    namespaces = axutil_hash_make(env);
                    next_ns_index = &next_ns_index_value;
                     
                           ns1 = axiom_namespace_create (env,
                                             "http://services.resource.ui.mgt.registry.carbon.wso2.org",
                                             "n"); 
                           axutil_hash_set(namespaces, "http://services.resource.ui.mgt.registry.carbon.wso2.org", AXIS2_HASH_KEY_STRING, axutil_strdup(env, "n"));
                       
                     
                    parent_element = axiom_element_create (env, NULL, "addCollection", ns1 , &parent);
                    
                    
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
                      

                   if (!_addCollection->is_valid_parentPath)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("parentPath"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("parentPath")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing parentPath element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sparentPath>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sparentPath>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_1 = _addCollection->property_parentPath;
                           
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
                      

                   if (!_addCollection->is_valid_collectionName)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("collectionName"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("collectionName")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing collectionName element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%scollectionName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%scollectionName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_2 = _addCollection->property_collectionName;
                           
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
                      

                   if (!_addCollection->is_valid_mediaType)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("mediaType"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("mediaType")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing mediaType element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%smediaType>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%smediaType>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_3 = _addCollection->property_mediaType;
                           
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
                      

                   if (!_addCollection->is_valid_description)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("description"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("description")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing description element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sdescription>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sdescription>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_4 = _addCollection->property_description;
                           
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
             * Getter for parentPath by  Property Number 1
             */
            axis2_char_t* AXIS2_CALL
            adb_addCollection_get_property1(
                adb_addCollection_t* _addCollection,
                const axutil_env_t *env)
            {
                return adb_addCollection_get_parentPath(_addCollection,
                                             env);
            }

            /**
             * getter for parentPath.
             */
            axis2_char_t* AXIS2_CALL
            adb_addCollection_get_parentPath(
                    adb_addCollection_t* _addCollection,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addCollection, NULL);
                  

                return _addCollection->property_parentPath;
             }

            /**
             * setter for parentPath
             */
            axis2_status_t AXIS2_CALL
            adb_addCollection_set_parentPath(
                    adb_addCollection_t* _addCollection,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_parentPath)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addCollection, AXIS2_FAILURE);
                
                if(_addCollection->is_valid_parentPath &&
                        arg_parentPath == _addCollection->property_parentPath)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_addCollection_reset_parentPath(_addCollection, env);

                
                if(NULL == arg_parentPath)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addCollection->property_parentPath = (axis2_char_t *)axutil_strdup(env, arg_parentPath);
                        if(NULL == _addCollection->property_parentPath)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for parentPath");
                            return AXIS2_FAILURE;
                        }
                        _addCollection->is_valid_parentPath = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for parentPath
            */
           axis2_status_t AXIS2_CALL
           adb_addCollection_reset_parentPath(
                   adb_addCollection_t* _addCollection,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addCollection, AXIS2_FAILURE);
               

               
            
                
                if(_addCollection->property_parentPath != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _addCollection->property_parentPath);
                     _addCollection->property_parentPath = NULL;
                }
            
                
                
                _addCollection->is_valid_parentPath = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether parentPath is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addCollection_is_parentPath_nil(
                   adb_addCollection_t* _addCollection,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addCollection, AXIS2_TRUE);
               
               return !_addCollection->is_valid_parentPath;
           }

           /**
            * Set parentPath to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addCollection_set_parentPath_nil(
                   adb_addCollection_t* _addCollection,
                   const axutil_env_t *env)
           {
               return adb_addCollection_reset_parentPath(_addCollection, env);
           }

           

            /**
             * Getter for collectionName by  Property Number 2
             */
            axis2_char_t* AXIS2_CALL
            adb_addCollection_get_property2(
                adb_addCollection_t* _addCollection,
                const axutil_env_t *env)
            {
                return adb_addCollection_get_collectionName(_addCollection,
                                             env);
            }

            /**
             * getter for collectionName.
             */
            axis2_char_t* AXIS2_CALL
            adb_addCollection_get_collectionName(
                    adb_addCollection_t* _addCollection,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addCollection, NULL);
                  

                return _addCollection->property_collectionName;
             }

            /**
             * setter for collectionName
             */
            axis2_status_t AXIS2_CALL
            adb_addCollection_set_collectionName(
                    adb_addCollection_t* _addCollection,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_collectionName)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addCollection, AXIS2_FAILURE);
                
                if(_addCollection->is_valid_collectionName &&
                        arg_collectionName == _addCollection->property_collectionName)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_addCollection_reset_collectionName(_addCollection, env);

                
                if(NULL == arg_collectionName)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addCollection->property_collectionName = (axis2_char_t *)axutil_strdup(env, arg_collectionName);
                        if(NULL == _addCollection->property_collectionName)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for collectionName");
                            return AXIS2_FAILURE;
                        }
                        _addCollection->is_valid_collectionName = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for collectionName
            */
           axis2_status_t AXIS2_CALL
           adb_addCollection_reset_collectionName(
                   adb_addCollection_t* _addCollection,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addCollection, AXIS2_FAILURE);
               

               
            
                
                if(_addCollection->property_collectionName != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _addCollection->property_collectionName);
                     _addCollection->property_collectionName = NULL;
                }
            
                
                
                _addCollection->is_valid_collectionName = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether collectionName is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addCollection_is_collectionName_nil(
                   adb_addCollection_t* _addCollection,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addCollection, AXIS2_TRUE);
               
               return !_addCollection->is_valid_collectionName;
           }

           /**
            * Set collectionName to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addCollection_set_collectionName_nil(
                   adb_addCollection_t* _addCollection,
                   const axutil_env_t *env)
           {
               return adb_addCollection_reset_collectionName(_addCollection, env);
           }

           

            /**
             * Getter for mediaType by  Property Number 3
             */
            axis2_char_t* AXIS2_CALL
            adb_addCollection_get_property3(
                adb_addCollection_t* _addCollection,
                const axutil_env_t *env)
            {
                return adb_addCollection_get_mediaType(_addCollection,
                                             env);
            }

            /**
             * getter for mediaType.
             */
            axis2_char_t* AXIS2_CALL
            adb_addCollection_get_mediaType(
                    adb_addCollection_t* _addCollection,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addCollection, NULL);
                  

                return _addCollection->property_mediaType;
             }

            /**
             * setter for mediaType
             */
            axis2_status_t AXIS2_CALL
            adb_addCollection_set_mediaType(
                    adb_addCollection_t* _addCollection,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_mediaType)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addCollection, AXIS2_FAILURE);
                
                if(_addCollection->is_valid_mediaType &&
                        arg_mediaType == _addCollection->property_mediaType)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_addCollection_reset_mediaType(_addCollection, env);

                
                if(NULL == arg_mediaType)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addCollection->property_mediaType = (axis2_char_t *)axutil_strdup(env, arg_mediaType);
                        if(NULL == _addCollection->property_mediaType)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for mediaType");
                            return AXIS2_FAILURE;
                        }
                        _addCollection->is_valid_mediaType = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for mediaType
            */
           axis2_status_t AXIS2_CALL
           adb_addCollection_reset_mediaType(
                   adb_addCollection_t* _addCollection,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addCollection, AXIS2_FAILURE);
               

               
            
                
                if(_addCollection->property_mediaType != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _addCollection->property_mediaType);
                     _addCollection->property_mediaType = NULL;
                }
            
                
                
                _addCollection->is_valid_mediaType = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether mediaType is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addCollection_is_mediaType_nil(
                   adb_addCollection_t* _addCollection,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addCollection, AXIS2_TRUE);
               
               return !_addCollection->is_valid_mediaType;
           }

           /**
            * Set mediaType to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addCollection_set_mediaType_nil(
                   adb_addCollection_t* _addCollection,
                   const axutil_env_t *env)
           {
               return adb_addCollection_reset_mediaType(_addCollection, env);
           }

           

            /**
             * Getter for description by  Property Number 4
             */
            axis2_char_t* AXIS2_CALL
            adb_addCollection_get_property4(
                adb_addCollection_t* _addCollection,
                const axutil_env_t *env)
            {
                return adb_addCollection_get_description(_addCollection,
                                             env);
            }

            /**
             * getter for description.
             */
            axis2_char_t* AXIS2_CALL
            adb_addCollection_get_description(
                    adb_addCollection_t* _addCollection,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addCollection, NULL);
                  

                return _addCollection->property_description;
             }

            /**
             * setter for description
             */
            axis2_status_t AXIS2_CALL
            adb_addCollection_set_description(
                    adb_addCollection_t* _addCollection,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_description)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addCollection, AXIS2_FAILURE);
                
                if(_addCollection->is_valid_description &&
                        arg_description == _addCollection->property_description)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_addCollection_reset_description(_addCollection, env);

                
                if(NULL == arg_description)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addCollection->property_description = (axis2_char_t *)axutil_strdup(env, arg_description);
                        if(NULL == _addCollection->property_description)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for description");
                            return AXIS2_FAILURE;
                        }
                        _addCollection->is_valid_description = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for description
            */
           axis2_status_t AXIS2_CALL
           adb_addCollection_reset_description(
                   adb_addCollection_t* _addCollection,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addCollection, AXIS2_FAILURE);
               

               
            
                
                if(_addCollection->property_description != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _addCollection->property_description);
                     _addCollection->property_description = NULL;
                }
            
                
                
                _addCollection->is_valid_description = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether description is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addCollection_is_description_nil(
                   adb_addCollection_t* _addCollection,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addCollection, AXIS2_TRUE);
               
               return !_addCollection->is_valid_description;
           }

           /**
            * Set description to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addCollection_set_description_nil(
                   adb_addCollection_t* _addCollection,
                   const axutil_env_t *env)
           {
               return adb_addCollection_reset_description(_addCollection, env);
           }

           

