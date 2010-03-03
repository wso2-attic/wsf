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
         * adb_addTextResource.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_addTextResource.h"
        
               /*
                * implmentation of the addTextResource|http://services.resource.ui.mgt.registry.carbon.wso2.org element
                */
           


        struct adb_addTextResource
        {
            axis2_char_t *property_Type;

            
                axutil_qname_t* qname;
            axis2_char_t* property_parentPath;

                
                axis2_bool_t is_valid_parentPath;
            axis2_char_t* property_fileName;

                
                axis2_bool_t is_valid_fileName;
            axis2_char_t* property_mediaType;

                
                axis2_bool_t is_valid_mediaType;
            axis2_char_t* property_description;

                
                axis2_bool_t is_valid_description;
            axis2_char_t* property_content;

                
                axis2_bool_t is_valid_content;
            
        };


       /************************* Private Function prototypes ********************************/
        


       /************************* Function Implmentations ********************************/
        adb_addTextResource_t* AXIS2_CALL
        adb_addTextResource_create(
            const axutil_env_t *env)
        {
            adb_addTextResource_t *_addTextResource = NULL;
            
                axutil_qname_t* qname = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _addTextResource = (adb_addTextResource_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_addTextResource_t));

            if(NULL == _addTextResource)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_addTextResource, 0, sizeof(adb_addTextResource_t));

            _addTextResource->property_Type = axutil_strdup(env, "adb_addTextResource");
            _addTextResource->property_parentPath  = NULL;
                  _addTextResource->is_valid_parentPath  = AXIS2_FALSE;
            _addTextResource->property_fileName  = NULL;
                  _addTextResource->is_valid_fileName  = AXIS2_FALSE;
            _addTextResource->property_mediaType  = NULL;
                  _addTextResource->is_valid_mediaType  = AXIS2_FALSE;
            _addTextResource->property_description  = NULL;
                  _addTextResource->is_valid_description  = AXIS2_FALSE;
            _addTextResource->property_content  = NULL;
                  _addTextResource->is_valid_content  = AXIS2_FALSE;
            
                  qname =  axutil_qname_create (env,
                        "addTextResource",
                        "http://services.resource.ui.mgt.registry.carbon.wso2.org",
                        NULL);
                _addTextResource->qname = qname;
            

            return _addTextResource;
        }

        adb_addTextResource_t* AXIS2_CALL
        adb_addTextResource_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _parentPath,
                axis2_char_t* _fileName,
                axis2_char_t* _mediaType,
                axis2_char_t* _description,
                axis2_char_t* _content)
        {
            adb_addTextResource_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_addTextResource_create(env);

            
              status = adb_addTextResource_set_parentPath(
                                     adb_obj,
                                     env,
                                     _parentPath);
              if(status == AXIS2_FAILURE) {
                  adb_addTextResource_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_addTextResource_set_fileName(
                                     adb_obj,
                                     env,
                                     _fileName);
              if(status == AXIS2_FAILURE) {
                  adb_addTextResource_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_addTextResource_set_mediaType(
                                     adb_obj,
                                     env,
                                     _mediaType);
              if(status == AXIS2_FAILURE) {
                  adb_addTextResource_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_addTextResource_set_description(
                                     adb_obj,
                                     env,
                                     _description);
              if(status == AXIS2_FAILURE) {
                  adb_addTextResource_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_addTextResource_set_content(
                                     adb_obj,
                                     env,
                                     _content);
              if(status == AXIS2_FAILURE) {
                  adb_addTextResource_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_char_t* AXIS2_CALL
                adb_addTextResource_free_popping_value(
                        adb_addTextResource_t* _addTextResource,
                        const axutil_env_t *env)
                {
                    axis2_char_t* value;

                    
                    
                    value = _addTextResource->property_parentPath;

                    _addTextResource->property_parentPath = (axis2_char_t*)NULL;
                    adb_addTextResource_free(_addTextResource, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_addTextResource_free(
                adb_addTextResource_t* _addTextResource,
                const axutil_env_t *env)
        {
            
            
            return adb_addTextResource_free_obj(
                _addTextResource,
                env);
            
        }

        axis2_status_t AXIS2_CALL
        adb_addTextResource_free_obj(
                adb_addTextResource_t* _addTextResource,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _addTextResource, AXIS2_FAILURE);

            if (_addTextResource->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _addTextResource->property_Type);
            }

            adb_addTextResource_reset_parentPath(_addTextResource, env);
            adb_addTextResource_reset_fileName(_addTextResource, env);
            adb_addTextResource_reset_mediaType(_addTextResource, env);
            adb_addTextResource_reset_description(_addTextResource, env);
            adb_addTextResource_reset_content(_addTextResource, env);
            
              if(_addTextResource->qname)
              {
                  axutil_qname_free (_addTextResource->qname, env);
                  _addTextResource->qname = NULL;
              }
            

            if(_addTextResource)
            {
                AXIS2_FREE(env->allocator, _addTextResource);
                _addTextResource = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_addTextResource_deserialize(
                adb_addTextResource_t* _addTextResource,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return adb_addTextResource_deserialize_obj(
                _addTextResource,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs);
            
        }

        axis2_status_t AXIS2_CALL
        adb_addTextResource_deserialize_obj(
                adb_addTextResource_t* _addTextResource,
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
            AXIS2_PARAM_CHECK(env->error, _addTextResource, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for addTextResource : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              

                    current_element = (axiom_element_t *)axiom_node_get_data_element(parent, env);
                    qname = axiom_element_get_qname(current_element, env, parent);
                    if (axutil_qname_equals(qname, env, _addTextResource-> qname))
                    {
                        
                          first_node = axiom_node_get_first_child(parent, env);
                          
                    }
                    else
                    {
                        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                              "Failed in building adb object for addTextResource : "
                              "Expected %s but returned %s",
                              axutil_qname_to_string(_addTextResource-> qname, env),
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
                                            status = adb_addTextResource_set_parentPath(_addTextResource, env,
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
                      * building fileName element
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
                                 
                                 element_qname = axutil_qname_create(env, "fileName", "http://services.resource.ui.mgt.registry.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_addTextResource_set_fileName(_addTextResource, env,
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
                                            status = adb_addTextResource_set_mediaType(_addTextResource, env,
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
                                            status = adb_addTextResource_set_description(_addTextResource, env,
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
                                            status = adb_addTextResource_set_content(_addTextResource, env,
                                                               text_value);
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
                 
          return status;
       }

          axis2_bool_t AXIS2_CALL
          adb_addTextResource_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_addTextResource_declare_parent_namespaces(
                    adb_addTextResource_t* _addTextResource,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_addTextResource_serialize(
                adb_addTextResource_t* _addTextResource,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
                return adb_addTextResource_serialize_obj(
                    _addTextResource, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            
        }

        axiom_node_t* AXIS2_CALL
        adb_addTextResource_serialize_obj(
                adb_addTextResource_t* _addTextResource,
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
            AXIS2_PARAM_CHECK(env->error, _addTextResource, NULL);
            
             
                    namespaces = axutil_hash_make(env);
                    next_ns_index = &next_ns_index_value;
                     
                           ns1 = axiom_namespace_create (env,
                                             "http://services.resource.ui.mgt.registry.carbon.wso2.org",
                                             "n"); 
                           axutil_hash_set(namespaces, "http://services.resource.ui.mgt.registry.carbon.wso2.org", AXIS2_HASH_KEY_STRING, axutil_strdup(env, "n"));
                       
                     
                    parent_element = axiom_element_create (env, NULL, "addTextResource", ns1 , &parent);
                    
                    
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
                      

                   if (!_addTextResource->is_valid_parentPath)
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
                    
                           text_value_1 = _addTextResource->property_parentPath;
                           
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
                      

                   if (!_addTextResource->is_valid_fileName)
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
                    
                           text_value_2 = _addTextResource->property_fileName;
                           
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
                      

                   if (!_addTextResource->is_valid_mediaType)
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
                    
                           text_value_3 = _addTextResource->property_mediaType;
                           
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
                      

                   if (!_addTextResource->is_valid_description)
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
                    
                           text_value_4 = _addTextResource->property_description;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://services.resource.ui.mgt.registry.carbon.wso2.org", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://services.resource.ui.mgt.registry.carbon.wso2.org", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://services.resource.ui.mgt.registry.carbon.wso2.org",
                                            p_prefix));
                       }
                      

                   if (!_addTextResource->is_valid_content)
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
                    
                           text_value_5 = _addTextResource->property_content;
                           
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
             * Getter for parentPath by  Property Number 1
             */
            axis2_char_t* AXIS2_CALL
            adb_addTextResource_get_property1(
                adb_addTextResource_t* _addTextResource,
                const axutil_env_t *env)
            {
                return adb_addTextResource_get_parentPath(_addTextResource,
                                             env);
            }

            /**
             * getter for parentPath.
             */
            axis2_char_t* AXIS2_CALL
            adb_addTextResource_get_parentPath(
                    adb_addTextResource_t* _addTextResource,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addTextResource, NULL);
                  

                return _addTextResource->property_parentPath;
             }

            /**
             * setter for parentPath
             */
            axis2_status_t AXIS2_CALL
            adb_addTextResource_set_parentPath(
                    adb_addTextResource_t* _addTextResource,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_parentPath)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addTextResource, AXIS2_FAILURE);
                
                if(_addTextResource->is_valid_parentPath &&
                        arg_parentPath == _addTextResource->property_parentPath)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_addTextResource_reset_parentPath(_addTextResource, env);

                
                if(NULL == arg_parentPath)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addTextResource->property_parentPath = (axis2_char_t *)axutil_strdup(env, arg_parentPath);
                        if(NULL == _addTextResource->property_parentPath)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for parentPath");
                            return AXIS2_FAILURE;
                        }
                        _addTextResource->is_valid_parentPath = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for parentPath
            */
           axis2_status_t AXIS2_CALL
           adb_addTextResource_reset_parentPath(
                   adb_addTextResource_t* _addTextResource,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addTextResource, AXIS2_FAILURE);
               

               
            
                
                if(_addTextResource->property_parentPath != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _addTextResource->property_parentPath);
                     _addTextResource->property_parentPath = NULL;
                }
            
                
                
                _addTextResource->is_valid_parentPath = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether parentPath is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addTextResource_is_parentPath_nil(
                   adb_addTextResource_t* _addTextResource,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addTextResource, AXIS2_TRUE);
               
               return !_addTextResource->is_valid_parentPath;
           }

           /**
            * Set parentPath to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addTextResource_set_parentPath_nil(
                   adb_addTextResource_t* _addTextResource,
                   const axutil_env_t *env)
           {
               return adb_addTextResource_reset_parentPath(_addTextResource, env);
           }

           

            /**
             * Getter for fileName by  Property Number 2
             */
            axis2_char_t* AXIS2_CALL
            adb_addTextResource_get_property2(
                adb_addTextResource_t* _addTextResource,
                const axutil_env_t *env)
            {
                return adb_addTextResource_get_fileName(_addTextResource,
                                             env);
            }

            /**
             * getter for fileName.
             */
            axis2_char_t* AXIS2_CALL
            adb_addTextResource_get_fileName(
                    adb_addTextResource_t* _addTextResource,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addTextResource, NULL);
                  

                return _addTextResource->property_fileName;
             }

            /**
             * setter for fileName
             */
            axis2_status_t AXIS2_CALL
            adb_addTextResource_set_fileName(
                    adb_addTextResource_t* _addTextResource,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_fileName)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addTextResource, AXIS2_FAILURE);
                
                if(_addTextResource->is_valid_fileName &&
                        arg_fileName == _addTextResource->property_fileName)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_addTextResource_reset_fileName(_addTextResource, env);

                
                if(NULL == arg_fileName)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addTextResource->property_fileName = (axis2_char_t *)axutil_strdup(env, arg_fileName);
                        if(NULL == _addTextResource->property_fileName)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for fileName");
                            return AXIS2_FAILURE;
                        }
                        _addTextResource->is_valid_fileName = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for fileName
            */
           axis2_status_t AXIS2_CALL
           adb_addTextResource_reset_fileName(
                   adb_addTextResource_t* _addTextResource,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addTextResource, AXIS2_FAILURE);
               

               
            
                
                if(_addTextResource->property_fileName != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _addTextResource->property_fileName);
                     _addTextResource->property_fileName = NULL;
                }
            
                
                
                _addTextResource->is_valid_fileName = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether fileName is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addTextResource_is_fileName_nil(
                   adb_addTextResource_t* _addTextResource,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addTextResource, AXIS2_TRUE);
               
               return !_addTextResource->is_valid_fileName;
           }

           /**
            * Set fileName to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addTextResource_set_fileName_nil(
                   adb_addTextResource_t* _addTextResource,
                   const axutil_env_t *env)
           {
               return adb_addTextResource_reset_fileName(_addTextResource, env);
           }

           

            /**
             * Getter for mediaType by  Property Number 3
             */
            axis2_char_t* AXIS2_CALL
            adb_addTextResource_get_property3(
                adb_addTextResource_t* _addTextResource,
                const axutil_env_t *env)
            {
                return adb_addTextResource_get_mediaType(_addTextResource,
                                             env);
            }

            /**
             * getter for mediaType.
             */
            axis2_char_t* AXIS2_CALL
            adb_addTextResource_get_mediaType(
                    adb_addTextResource_t* _addTextResource,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addTextResource, NULL);
                  

                return _addTextResource->property_mediaType;
             }

            /**
             * setter for mediaType
             */
            axis2_status_t AXIS2_CALL
            adb_addTextResource_set_mediaType(
                    adb_addTextResource_t* _addTextResource,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_mediaType)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addTextResource, AXIS2_FAILURE);
                
                if(_addTextResource->is_valid_mediaType &&
                        arg_mediaType == _addTextResource->property_mediaType)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_addTextResource_reset_mediaType(_addTextResource, env);

                
                if(NULL == arg_mediaType)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addTextResource->property_mediaType = (axis2_char_t *)axutil_strdup(env, arg_mediaType);
                        if(NULL == _addTextResource->property_mediaType)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for mediaType");
                            return AXIS2_FAILURE;
                        }
                        _addTextResource->is_valid_mediaType = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for mediaType
            */
           axis2_status_t AXIS2_CALL
           adb_addTextResource_reset_mediaType(
                   adb_addTextResource_t* _addTextResource,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addTextResource, AXIS2_FAILURE);
               

               
            
                
                if(_addTextResource->property_mediaType != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _addTextResource->property_mediaType);
                     _addTextResource->property_mediaType = NULL;
                }
            
                
                
                _addTextResource->is_valid_mediaType = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether mediaType is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addTextResource_is_mediaType_nil(
                   adb_addTextResource_t* _addTextResource,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addTextResource, AXIS2_TRUE);
               
               return !_addTextResource->is_valid_mediaType;
           }

           /**
            * Set mediaType to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addTextResource_set_mediaType_nil(
                   adb_addTextResource_t* _addTextResource,
                   const axutil_env_t *env)
           {
               return adb_addTextResource_reset_mediaType(_addTextResource, env);
           }

           

            /**
             * Getter for description by  Property Number 4
             */
            axis2_char_t* AXIS2_CALL
            adb_addTextResource_get_property4(
                adb_addTextResource_t* _addTextResource,
                const axutil_env_t *env)
            {
                return adb_addTextResource_get_description(_addTextResource,
                                             env);
            }

            /**
             * getter for description.
             */
            axis2_char_t* AXIS2_CALL
            adb_addTextResource_get_description(
                    adb_addTextResource_t* _addTextResource,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addTextResource, NULL);
                  

                return _addTextResource->property_description;
             }

            /**
             * setter for description
             */
            axis2_status_t AXIS2_CALL
            adb_addTextResource_set_description(
                    adb_addTextResource_t* _addTextResource,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_description)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addTextResource, AXIS2_FAILURE);
                
                if(_addTextResource->is_valid_description &&
                        arg_description == _addTextResource->property_description)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_addTextResource_reset_description(_addTextResource, env);

                
                if(NULL == arg_description)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addTextResource->property_description = (axis2_char_t *)axutil_strdup(env, arg_description);
                        if(NULL == _addTextResource->property_description)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for description");
                            return AXIS2_FAILURE;
                        }
                        _addTextResource->is_valid_description = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for description
            */
           axis2_status_t AXIS2_CALL
           adb_addTextResource_reset_description(
                   adb_addTextResource_t* _addTextResource,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addTextResource, AXIS2_FAILURE);
               

               
            
                
                if(_addTextResource->property_description != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _addTextResource->property_description);
                     _addTextResource->property_description = NULL;
                }
            
                
                
                _addTextResource->is_valid_description = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether description is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addTextResource_is_description_nil(
                   adb_addTextResource_t* _addTextResource,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addTextResource, AXIS2_TRUE);
               
               return !_addTextResource->is_valid_description;
           }

           /**
            * Set description to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addTextResource_set_description_nil(
                   adb_addTextResource_t* _addTextResource,
                   const axutil_env_t *env)
           {
               return adb_addTextResource_reset_description(_addTextResource, env);
           }

           

            /**
             * Getter for content by  Property Number 5
             */
            axis2_char_t* AXIS2_CALL
            adb_addTextResource_get_property5(
                adb_addTextResource_t* _addTextResource,
                const axutil_env_t *env)
            {
                return adb_addTextResource_get_content(_addTextResource,
                                             env);
            }

            /**
             * getter for content.
             */
            axis2_char_t* AXIS2_CALL
            adb_addTextResource_get_content(
                    adb_addTextResource_t* _addTextResource,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addTextResource, NULL);
                  

                return _addTextResource->property_content;
             }

            /**
             * setter for content
             */
            axis2_status_t AXIS2_CALL
            adb_addTextResource_set_content(
                    adb_addTextResource_t* _addTextResource,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_content)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addTextResource, AXIS2_FAILURE);
                
                if(_addTextResource->is_valid_content &&
                        arg_content == _addTextResource->property_content)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_addTextResource_reset_content(_addTextResource, env);

                
                if(NULL == arg_content)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addTextResource->property_content = (axis2_char_t *)axutil_strdup(env, arg_content);
                        if(NULL == _addTextResource->property_content)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for content");
                            return AXIS2_FAILURE;
                        }
                        _addTextResource->is_valid_content = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for content
            */
           axis2_status_t AXIS2_CALL
           adb_addTextResource_reset_content(
                   adb_addTextResource_t* _addTextResource,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addTextResource, AXIS2_FAILURE);
               

               
            
                
                if(_addTextResource->property_content != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _addTextResource->property_content);
                     _addTextResource->property_content = NULL;
                }
            
                
                
                _addTextResource->is_valid_content = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether content is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addTextResource_is_content_nil(
                   adb_addTextResource_t* _addTextResource,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addTextResource, AXIS2_TRUE);
               
               return !_addTextResource->is_valid_content;
           }

           /**
            * Set content to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addTextResource_set_content_nil(
                   adb_addTextResource_t* _addTextResource,
                   const axutil_env_t *env)
           {
               return adb_addTextResource_reset_content(_addTextResource, env);
           }

           

