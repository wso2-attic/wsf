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
         * adb_addResource.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_addResource.h"
        
               /*
                * implmentation of the addResource|http://services.resource.ui.mgt.registry.carbon.wso2.org element
                */
           


        struct adb_addResource
        {
            axis2_char_t *property_Type;

            
                axutil_qname_t* qname;
            axis2_char_t* property_path;

                
                axis2_bool_t is_valid_path;
            axis2_char_t* property_mediaType;

                
                axis2_bool_t is_valid_mediaType;
            axis2_char_t* property_description;

                
                axis2_bool_t is_valid_description;
            axutil_base64_binary_t* property_content;

                
                axis2_bool_t is_valid_content;
            axis2_char_t* property_symlinkLocation;

                
                axis2_bool_t is_valid_symlinkLocation;
            
        };


       /************************* Private Function prototypes ********************************/
        


       /************************* Function Implmentations ********************************/
        adb_addResource_t* AXIS2_CALL
        adb_addResource_create(
            const axutil_env_t *env)
        {
            adb_addResource_t *_addResource = NULL;
            
                axutil_qname_t* qname = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _addResource = (adb_addResource_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_addResource_t));

            if(NULL == _addResource)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_addResource, 0, sizeof(adb_addResource_t));

            _addResource->property_Type = axutil_strdup(env, "adb_addResource");
            _addResource->property_path  = NULL;
                  _addResource->is_valid_path  = AXIS2_FALSE;
            _addResource->property_mediaType  = NULL;
                  _addResource->is_valid_mediaType  = AXIS2_FALSE;
            _addResource->property_description  = NULL;
                  _addResource->is_valid_description  = AXIS2_FALSE;
            _addResource->property_content  = NULL;
                  _addResource->is_valid_content  = AXIS2_FALSE;
            _addResource->property_symlinkLocation  = NULL;
                  _addResource->is_valid_symlinkLocation  = AXIS2_FALSE;
            
                  qname =  axutil_qname_create (env,
                        "addResource",
                        "http://services.resource.ui.mgt.registry.carbon.wso2.org",
                        NULL);
                _addResource->qname = qname;
            

            return _addResource;
        }

        adb_addResource_t* AXIS2_CALL
        adb_addResource_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _path,
                axis2_char_t* _mediaType,
                axis2_char_t* _description,
                axutil_base64_binary_t* _content,
                axis2_char_t* _symlinkLocation)
        {
            adb_addResource_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_addResource_create(env);

            
              status = adb_addResource_set_path(
                                     adb_obj,
                                     env,
                                     _path);
              if(status == AXIS2_FAILURE) {
                  adb_addResource_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_addResource_set_mediaType(
                                     adb_obj,
                                     env,
                                     _mediaType);
              if(status == AXIS2_FAILURE) {
                  adb_addResource_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_addResource_set_description(
                                     adb_obj,
                                     env,
                                     _description);
              if(status == AXIS2_FAILURE) {
                  adb_addResource_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_addResource_set_content(
                                     adb_obj,
                                     env,
                                     _content);
              if(status == AXIS2_FAILURE) {
                  adb_addResource_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_addResource_set_symlinkLocation(
                                     adb_obj,
                                     env,
                                     _symlinkLocation);
              if(status == AXIS2_FAILURE) {
                  adb_addResource_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_char_t* AXIS2_CALL
                adb_addResource_free_popping_value(
                        adb_addResource_t* _addResource,
                        const axutil_env_t *env)
                {
                    axis2_char_t* value;

                    
                    
                    value = _addResource->property_path;

                    _addResource->property_path = (axis2_char_t*)NULL;
                    adb_addResource_free(_addResource, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_addResource_free(
                adb_addResource_t* _addResource,
                const axutil_env_t *env)
        {
            
            
            return adb_addResource_free_obj(
                _addResource,
                env);
            
        }

        axis2_status_t AXIS2_CALL
        adb_addResource_free_obj(
                adb_addResource_t* _addResource,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _addResource, AXIS2_FAILURE);

            if (_addResource->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _addResource->property_Type);
            }

            adb_addResource_reset_path(_addResource, env);
            adb_addResource_reset_mediaType(_addResource, env);
            adb_addResource_reset_description(_addResource, env);
            adb_addResource_reset_content(_addResource, env);
            adb_addResource_reset_symlinkLocation(_addResource, env);
            
              if(_addResource->qname)
              {
                  axutil_qname_free (_addResource->qname, env);
                  _addResource->qname = NULL;
              }
            

            if(_addResource)
            {
                AXIS2_FREE(env->allocator, _addResource);
                _addResource = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_addResource_deserialize(
                adb_addResource_t* _addResource,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return adb_addResource_deserialize_obj(
                _addResource,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs);
            
        }

        axis2_status_t AXIS2_CALL
        adb_addResource_deserialize_obj(
                adb_addResource_t* _addResource,
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
          
            axutil_qname_t *element_qname = NULL; 
            
               axiom_node_t *first_node = NULL;
               axis2_bool_t is_early_node_valid = AXIS2_TRUE;
               axiom_node_t *current_node = NULL;
               axiom_element_t *current_element = NULL;
            
            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _addResource, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for addResource : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              

                    current_element = (axiom_element_t *)axiom_node_get_data_element(parent, env);
                    qname = axiom_element_get_qname(current_element, env, parent);
                    if (axutil_qname_equals(qname, env, _addResource-> qname))
                    {
                        
                          first_node = axiom_node_get_first_child(parent, env);
                          
                    }
                    else
                    {
                        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                              "Failed in building adb object for addResource : "
                              "Expected %s but returned %s",
                              axutil_qname_to_string(_addResource-> qname, env),
                              axutil_qname_to_string(qname, env));
                        
                        return AXIS2_FAILURE;
                    }
                    

                     
                     /*
                      * building path element
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
                                   
                                 element_qname = axutil_qname_create(env, "path", "http://services.resource.ui.mgt.registry.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_addResource_set_path(_addResource, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for path ");
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
                                            status = adb_addResource_set_mediaType(_addResource, env,
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
                                            status = adb_addResource_set_description(_addResource, env,
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
                 

                     
                     /*
                      * building content element
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
                                 
                                 element_qname = axutil_qname_create(env, "content", "http://services.resource.ui.mgt.registry.carbon.wso2.org", NULL);
                                 

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
                                          element = (void*)axutil_base64_binary_create(env);
                                          status = axutil_base64_binary_set_encoded_binary((axutil_base64_binary_t*)element, env,
                                                                          text_value);
                                          if(AXIS2_FAILURE ==  status)
                                          {
                                              if(element != NULL)
                                              {
                                                 axutil_base64_binary_free((axutil_base64_binary_t*)element, env);
                                              }
                                              AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building element content ");
                                          }
                                          else
                                          {
                                            status = adb_addResource_set_content(_addResource, env,
                                                                       (axutil_base64_binary_t*)element);
                                          }
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for content ");
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
                      * building symlinkLocation element
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
                                 
                                 element_qname = axutil_qname_create(env, "symlinkLocation", "http://services.resource.ui.mgt.registry.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_addResource_set_symlinkLocation(_addResource, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for symlinkLocation ");
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
          adb_addResource_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_addResource_declare_parent_namespaces(
                    adb_addResource_t* _addResource,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_addResource_serialize(
                adb_addResource_t* _addResource,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
                return adb_addResource_serialize_obj(
                    _addResource, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            
        }

        axiom_node_t* AXIS2_CALL
        adb_addResource_serialize_obj(
                adb_addResource_t* _addResource,
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
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

             
                int next_ns_index_value = 0;
            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _addResource, NULL);
            
             
                    namespaces = axutil_hash_make(env);
                    next_ns_index = &next_ns_index_value;
                     
                           ns1 = axiom_namespace_create (env,
                                             "http://services.resource.ui.mgt.registry.carbon.wso2.org",
                                             "n"); 
                           axutil_hash_set(namespaces, "http://services.resource.ui.mgt.registry.carbon.wso2.org", AXIS2_HASH_KEY_STRING, axutil_strdup(env, "n"));
                       
                     
                    parent_element = axiom_element_create (env, NULL, "addResource", ns1 , &parent);
                    
                    
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
                      

                   if (!_addResource->is_valid_path)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("path"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("path")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing path element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%spath>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%spath>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_1 = _addResource->property_path;
                           
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
                      

                   if (!_addResource->is_valid_mediaType)
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
                    
                           text_value_2 = _addResource->property_mediaType;
                           
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
                      

                   if (!_addResource->is_valid_description)
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
                    
                           text_value_3 = _addResource->property_description;
                           
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
                      

                   if (!_addResource->is_valid_content)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("content"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("content")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing content element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%scontent>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%scontent>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                          text_value_4 =axutil_base64_binary_get_encoded_binary(_addResource->property_content, env);
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_4, axutil_strlen(text_value_4));
                           
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
                      

                   if (!_addResource->is_valid_symlinkLocation)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("symlinkLocation"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("symlinkLocation")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing symlinkLocation element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%ssymlinkLocation>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%ssymlinkLocation>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_5 = _addResource->property_symlinkLocation;
                           
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
             * Getter for path by  Property Number 1
             */
            axis2_char_t* AXIS2_CALL
            adb_addResource_get_property1(
                adb_addResource_t* _addResource,
                const axutil_env_t *env)
            {
                return adb_addResource_get_path(_addResource,
                                             env);
            }

            /**
             * getter for path.
             */
            axis2_char_t* AXIS2_CALL
            adb_addResource_get_path(
                    adb_addResource_t* _addResource,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addResource, NULL);
                  

                return _addResource->property_path;
             }

            /**
             * setter for path
             */
            axis2_status_t AXIS2_CALL
            adb_addResource_set_path(
                    adb_addResource_t* _addResource,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_path)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addResource, AXIS2_FAILURE);
                
                if(_addResource->is_valid_path &&
                        arg_path == _addResource->property_path)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_addResource_reset_path(_addResource, env);

                
                if(NULL == arg_path)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addResource->property_path = (axis2_char_t *)axutil_strdup(env, arg_path);
                        if(NULL == _addResource->property_path)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for path");
                            return AXIS2_FAILURE;
                        }
                        _addResource->is_valid_path = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for path
            */
           axis2_status_t AXIS2_CALL
           adb_addResource_reset_path(
                   adb_addResource_t* _addResource,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addResource, AXIS2_FAILURE);
               

               
            
                
                if(_addResource->property_path != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _addResource->property_path);
                     _addResource->property_path = NULL;
                }
            
                
                
                _addResource->is_valid_path = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether path is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addResource_is_path_nil(
                   adb_addResource_t* _addResource,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addResource, AXIS2_TRUE);
               
               return !_addResource->is_valid_path;
           }

           /**
            * Set path to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addResource_set_path_nil(
                   adb_addResource_t* _addResource,
                   const axutil_env_t *env)
           {
               return adb_addResource_reset_path(_addResource, env);
           }

           

            /**
             * Getter for mediaType by  Property Number 2
             */
            axis2_char_t* AXIS2_CALL
            adb_addResource_get_property2(
                adb_addResource_t* _addResource,
                const axutil_env_t *env)
            {
                return adb_addResource_get_mediaType(_addResource,
                                             env);
            }

            /**
             * getter for mediaType.
             */
            axis2_char_t* AXIS2_CALL
            adb_addResource_get_mediaType(
                    adb_addResource_t* _addResource,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addResource, NULL);
                  

                return _addResource->property_mediaType;
             }

            /**
             * setter for mediaType
             */
            axis2_status_t AXIS2_CALL
            adb_addResource_set_mediaType(
                    adb_addResource_t* _addResource,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_mediaType)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addResource, AXIS2_FAILURE);
                
                if(_addResource->is_valid_mediaType &&
                        arg_mediaType == _addResource->property_mediaType)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_addResource_reset_mediaType(_addResource, env);

                
                if(NULL == arg_mediaType)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addResource->property_mediaType = (axis2_char_t *)axutil_strdup(env, arg_mediaType);
                        if(NULL == _addResource->property_mediaType)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for mediaType");
                            return AXIS2_FAILURE;
                        }
                        _addResource->is_valid_mediaType = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for mediaType
            */
           axis2_status_t AXIS2_CALL
           adb_addResource_reset_mediaType(
                   adb_addResource_t* _addResource,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addResource, AXIS2_FAILURE);
               

               
            
                
                if(_addResource->property_mediaType != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _addResource->property_mediaType);
                     _addResource->property_mediaType = NULL;
                }
            
                
                
                _addResource->is_valid_mediaType = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether mediaType is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addResource_is_mediaType_nil(
                   adb_addResource_t* _addResource,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addResource, AXIS2_TRUE);
               
               return !_addResource->is_valid_mediaType;
           }

           /**
            * Set mediaType to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addResource_set_mediaType_nil(
                   adb_addResource_t* _addResource,
                   const axutil_env_t *env)
           {
               return adb_addResource_reset_mediaType(_addResource, env);
           }

           

            /**
             * Getter for description by  Property Number 3
             */
            axis2_char_t* AXIS2_CALL
            adb_addResource_get_property3(
                adb_addResource_t* _addResource,
                const axutil_env_t *env)
            {
                return adb_addResource_get_description(_addResource,
                                             env);
            }

            /**
             * getter for description.
             */
            axis2_char_t* AXIS2_CALL
            adb_addResource_get_description(
                    adb_addResource_t* _addResource,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addResource, NULL);
                  

                return _addResource->property_description;
             }

            /**
             * setter for description
             */
            axis2_status_t AXIS2_CALL
            adb_addResource_set_description(
                    adb_addResource_t* _addResource,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_description)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addResource, AXIS2_FAILURE);
                
                if(_addResource->is_valid_description &&
                        arg_description == _addResource->property_description)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_addResource_reset_description(_addResource, env);

                
                if(NULL == arg_description)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addResource->property_description = (axis2_char_t *)axutil_strdup(env, arg_description);
                        if(NULL == _addResource->property_description)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for description");
                            return AXIS2_FAILURE;
                        }
                        _addResource->is_valid_description = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for description
            */
           axis2_status_t AXIS2_CALL
           adb_addResource_reset_description(
                   adb_addResource_t* _addResource,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addResource, AXIS2_FAILURE);
               

               
            
                
                if(_addResource->property_description != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _addResource->property_description);
                     _addResource->property_description = NULL;
                }
            
                
                
                _addResource->is_valid_description = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether description is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addResource_is_description_nil(
                   adb_addResource_t* _addResource,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addResource, AXIS2_TRUE);
               
               return !_addResource->is_valid_description;
           }

           /**
            * Set description to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addResource_set_description_nil(
                   adb_addResource_t* _addResource,
                   const axutil_env_t *env)
           {
               return adb_addResource_reset_description(_addResource, env);
           }

           

            /**
             * Getter for content by  Property Number 4
             */
            axutil_base64_binary_t* AXIS2_CALL
            adb_addResource_get_property4(
                adb_addResource_t* _addResource,
                const axutil_env_t *env)
            {
                return adb_addResource_get_content(_addResource,
                                             env);
            }

            /**
             * getter for content.
             */
            axutil_base64_binary_t* AXIS2_CALL
            adb_addResource_get_content(
                    adb_addResource_t* _addResource,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addResource, NULL);
                  

                return _addResource->property_content;
             }

            /**
             * setter for content
             */
            axis2_status_t AXIS2_CALL
            adb_addResource_set_content(
                    adb_addResource_t* _addResource,
                    const axutil_env_t *env,
                    axutil_base64_binary_t*  arg_content)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addResource, AXIS2_FAILURE);
                
                if(_addResource->is_valid_content &&
                        arg_content == _addResource->property_content)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_addResource_reset_content(_addResource, env);

                
                if(NULL == arg_content)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addResource->property_content = arg_content;
                        _addResource->is_valid_content = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for content
            */
           axis2_status_t AXIS2_CALL
           adb_addResource_reset_content(
                   adb_addResource_t* _addResource,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addResource, AXIS2_FAILURE);
               

               
            
                
                if(_addResource->property_content != NULL)
                {
                   
                   
                      axutil_base64_binary_free (_addResource->property_content, env);
                     _addResource->property_content = NULL;
                }
            
                
                
                _addResource->is_valid_content = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether content is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addResource_is_content_nil(
                   adb_addResource_t* _addResource,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addResource, AXIS2_TRUE);
               
               return !_addResource->is_valid_content;
           }

           /**
            * Set content to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addResource_set_content_nil(
                   adb_addResource_t* _addResource,
                   const axutil_env_t *env)
           {
               return adb_addResource_reset_content(_addResource, env);
           }

           

            /**
             * Getter for symlinkLocation by  Property Number 5
             */
            axis2_char_t* AXIS2_CALL
            adb_addResource_get_property5(
                adb_addResource_t* _addResource,
                const axutil_env_t *env)
            {
                return adb_addResource_get_symlinkLocation(_addResource,
                                             env);
            }

            /**
             * getter for symlinkLocation.
             */
            axis2_char_t* AXIS2_CALL
            adb_addResource_get_symlinkLocation(
                    adb_addResource_t* _addResource,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addResource, NULL);
                  

                return _addResource->property_symlinkLocation;
             }

            /**
             * setter for symlinkLocation
             */
            axis2_status_t AXIS2_CALL
            adb_addResource_set_symlinkLocation(
                    adb_addResource_t* _addResource,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_symlinkLocation)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addResource, AXIS2_FAILURE);
                
                if(_addResource->is_valid_symlinkLocation &&
                        arg_symlinkLocation == _addResource->property_symlinkLocation)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_addResource_reset_symlinkLocation(_addResource, env);

                
                if(NULL == arg_symlinkLocation)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addResource->property_symlinkLocation = (axis2_char_t *)axutil_strdup(env, arg_symlinkLocation);
                        if(NULL == _addResource->property_symlinkLocation)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for symlinkLocation");
                            return AXIS2_FAILURE;
                        }
                        _addResource->is_valid_symlinkLocation = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for symlinkLocation
            */
           axis2_status_t AXIS2_CALL
           adb_addResource_reset_symlinkLocation(
                   adb_addResource_t* _addResource,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addResource, AXIS2_FAILURE);
               

               
            
                
                if(_addResource->property_symlinkLocation != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _addResource->property_symlinkLocation);
                     _addResource->property_symlinkLocation = NULL;
                }
            
                
                
                _addResource->is_valid_symlinkLocation = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether symlinkLocation is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addResource_is_symlinkLocation_nil(
                   adb_addResource_t* _addResource,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addResource, AXIS2_TRUE);
               
               return !_addResource->is_valid_symlinkLocation;
           }

           /**
            * Set symlinkLocation to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addResource_set_symlinkLocation_nil(
                   adb_addResource_t* _addResource,
                   const axutil_env_t *env)
           {
               return adb_addResource_reset_symlinkLocation(_addResource, env);
           }

           

