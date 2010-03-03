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
         * adb_copyResource.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_copyResource.h"
        
               /*
                * implmentation of the copyResource|http://services.resource.ui.mgt.registry.carbon.wso2.org element
                */
           


        struct adb_copyResource
        {
            axis2_char_t *property_Type;

            
                axutil_qname_t* qname;
            axis2_char_t* property_parentPath;

                
                axis2_bool_t is_valid_parentPath;
            axis2_char_t* property_oldResourcePath;

                
                axis2_bool_t is_valid_oldResourcePath;
            axis2_char_t* property_destinationPath;

                
                axis2_bool_t is_valid_destinationPath;
            axis2_char_t* property_resourceName;

                
                axis2_bool_t is_valid_resourceName;
            
        };


       /************************* Private Function prototypes ********************************/
        


       /************************* Function Implmentations ********************************/
        adb_copyResource_t* AXIS2_CALL
        adb_copyResource_create(
            const axutil_env_t *env)
        {
            adb_copyResource_t *_copyResource = NULL;
            
                axutil_qname_t* qname = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _copyResource = (adb_copyResource_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_copyResource_t));

            if(NULL == _copyResource)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_copyResource, 0, sizeof(adb_copyResource_t));

            _copyResource->property_Type = axutil_strdup(env, "adb_copyResource");
            _copyResource->property_parentPath  = NULL;
                  _copyResource->is_valid_parentPath  = AXIS2_FALSE;
            _copyResource->property_oldResourcePath  = NULL;
                  _copyResource->is_valid_oldResourcePath  = AXIS2_FALSE;
            _copyResource->property_destinationPath  = NULL;
                  _copyResource->is_valid_destinationPath  = AXIS2_FALSE;
            _copyResource->property_resourceName  = NULL;
                  _copyResource->is_valid_resourceName  = AXIS2_FALSE;
            
                  qname =  axutil_qname_create (env,
                        "copyResource",
                        "http://services.resource.ui.mgt.registry.carbon.wso2.org",
                        NULL);
                _copyResource->qname = qname;
            

            return _copyResource;
        }

        adb_copyResource_t* AXIS2_CALL
        adb_copyResource_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _parentPath,
                axis2_char_t* _oldResourcePath,
                axis2_char_t* _destinationPath,
                axis2_char_t* _resourceName)
        {
            adb_copyResource_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_copyResource_create(env);

            
              status = adb_copyResource_set_parentPath(
                                     adb_obj,
                                     env,
                                     _parentPath);
              if(status == AXIS2_FAILURE) {
                  adb_copyResource_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_copyResource_set_oldResourcePath(
                                     adb_obj,
                                     env,
                                     _oldResourcePath);
              if(status == AXIS2_FAILURE) {
                  adb_copyResource_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_copyResource_set_destinationPath(
                                     adb_obj,
                                     env,
                                     _destinationPath);
              if(status == AXIS2_FAILURE) {
                  adb_copyResource_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_copyResource_set_resourceName(
                                     adb_obj,
                                     env,
                                     _resourceName);
              if(status == AXIS2_FAILURE) {
                  adb_copyResource_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_char_t* AXIS2_CALL
                adb_copyResource_free_popping_value(
                        adb_copyResource_t* _copyResource,
                        const axutil_env_t *env)
                {
                    axis2_char_t* value;

                    
                    
                    value = _copyResource->property_parentPath;

                    _copyResource->property_parentPath = (axis2_char_t*)NULL;
                    adb_copyResource_free(_copyResource, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_copyResource_free(
                adb_copyResource_t* _copyResource,
                const axutil_env_t *env)
        {
            
            
            return adb_copyResource_free_obj(
                _copyResource,
                env);
            
        }

        axis2_status_t AXIS2_CALL
        adb_copyResource_free_obj(
                adb_copyResource_t* _copyResource,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _copyResource, AXIS2_FAILURE);

            if (_copyResource->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _copyResource->property_Type);
            }

            adb_copyResource_reset_parentPath(_copyResource, env);
            adb_copyResource_reset_oldResourcePath(_copyResource, env);
            adb_copyResource_reset_destinationPath(_copyResource, env);
            adb_copyResource_reset_resourceName(_copyResource, env);
            
              if(_copyResource->qname)
              {
                  axutil_qname_free (_copyResource->qname, env);
                  _copyResource->qname = NULL;
              }
            

            if(_copyResource)
            {
                AXIS2_FREE(env->allocator, _copyResource);
                _copyResource = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_copyResource_deserialize(
                adb_copyResource_t* _copyResource,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return adb_copyResource_deserialize_obj(
                _copyResource,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs);
            
        }

        axis2_status_t AXIS2_CALL
        adb_copyResource_deserialize_obj(
                adb_copyResource_t* _copyResource,
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
            AXIS2_PARAM_CHECK(env->error, _copyResource, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for copyResource : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              

                    current_element = (axiom_element_t *)axiom_node_get_data_element(parent, env);
                    qname = axiom_element_get_qname(current_element, env, parent);
                    if (axutil_qname_equals(qname, env, _copyResource-> qname))
                    {
                        
                          first_node = axiom_node_get_first_child(parent, env);
                          
                    }
                    else
                    {
                        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                              "Failed in building adb object for copyResource : "
                              "Expected %s but returned %s",
                              axutil_qname_to_string(_copyResource-> qname, env),
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
                                            status = adb_copyResource_set_parentPath(_copyResource, env,
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
                      * building oldResourcePath element
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
                                 
                                 element_qname = axutil_qname_create(env, "oldResourcePath", "http://services.resource.ui.mgt.registry.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_copyResource_set_oldResourcePath(_copyResource, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for oldResourcePath ");
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
                      * building destinationPath element
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
                                 
                                 element_qname = axutil_qname_create(env, "destinationPath", "http://services.resource.ui.mgt.registry.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_copyResource_set_destinationPath(_copyResource, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for destinationPath ");
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
                      * building resourceName element
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
                                 
                                 element_qname = axutil_qname_create(env, "resourceName", "http://services.resource.ui.mgt.registry.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_copyResource_set_resourceName(_copyResource, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for resourceName ");
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
          adb_copyResource_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_copyResource_declare_parent_namespaces(
                    adb_copyResource_t* _copyResource,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_copyResource_serialize(
                adb_copyResource_t* _copyResource,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
                return adb_copyResource_serialize_obj(
                    _copyResource, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            
        }

        axiom_node_t* AXIS2_CALL
        adb_copyResource_serialize_obj(
                adb_copyResource_t* _copyResource,
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
            AXIS2_PARAM_CHECK(env->error, _copyResource, NULL);
            
             
                    namespaces = axutil_hash_make(env);
                    next_ns_index = &next_ns_index_value;
                     
                           ns1 = axiom_namespace_create (env,
                                             "http://services.resource.ui.mgt.registry.carbon.wso2.org",
                                             "n"); 
                           axutil_hash_set(namespaces, "http://services.resource.ui.mgt.registry.carbon.wso2.org", AXIS2_HASH_KEY_STRING, axutil_strdup(env, "n"));
                       
                     
                    parent_element = axiom_element_create (env, NULL, "copyResource", ns1 , &parent);
                    
                    
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
                      

                   if (!_copyResource->is_valid_parentPath)
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
                    
                           text_value_1 = _copyResource->property_parentPath;
                           
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
                      

                   if (!_copyResource->is_valid_oldResourcePath)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("oldResourcePath"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("oldResourcePath")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing oldResourcePath element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%soldResourcePath>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%soldResourcePath>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_2 = _copyResource->property_oldResourcePath;
                           
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
                      

                   if (!_copyResource->is_valid_destinationPath)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("destinationPath"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("destinationPath")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing destinationPath element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sdestinationPath>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sdestinationPath>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_3 = _copyResource->property_destinationPath;
                           
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
                      

                   if (!_copyResource->is_valid_resourceName)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("resourceName"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("resourceName")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing resourceName element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sresourceName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sresourceName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_4 = _copyResource->property_resourceName;
                           
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
            adb_copyResource_get_property1(
                adb_copyResource_t* _copyResource,
                const axutil_env_t *env)
            {
                return adb_copyResource_get_parentPath(_copyResource,
                                             env);
            }

            /**
             * getter for parentPath.
             */
            axis2_char_t* AXIS2_CALL
            adb_copyResource_get_parentPath(
                    adb_copyResource_t* _copyResource,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _copyResource, NULL);
                  

                return _copyResource->property_parentPath;
             }

            /**
             * setter for parentPath
             */
            axis2_status_t AXIS2_CALL
            adb_copyResource_set_parentPath(
                    adb_copyResource_t* _copyResource,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_parentPath)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _copyResource, AXIS2_FAILURE);
                
                if(_copyResource->is_valid_parentPath &&
                        arg_parentPath == _copyResource->property_parentPath)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_copyResource_reset_parentPath(_copyResource, env);

                
                if(NULL == arg_parentPath)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _copyResource->property_parentPath = (axis2_char_t *)axutil_strdup(env, arg_parentPath);
                        if(NULL == _copyResource->property_parentPath)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for parentPath");
                            return AXIS2_FAILURE;
                        }
                        _copyResource->is_valid_parentPath = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for parentPath
            */
           axis2_status_t AXIS2_CALL
           adb_copyResource_reset_parentPath(
                   adb_copyResource_t* _copyResource,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _copyResource, AXIS2_FAILURE);
               

               
            
                
                if(_copyResource->property_parentPath != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _copyResource->property_parentPath);
                     _copyResource->property_parentPath = NULL;
                }
            
                
                
                _copyResource->is_valid_parentPath = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether parentPath is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_copyResource_is_parentPath_nil(
                   adb_copyResource_t* _copyResource,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _copyResource, AXIS2_TRUE);
               
               return !_copyResource->is_valid_parentPath;
           }

           /**
            * Set parentPath to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_copyResource_set_parentPath_nil(
                   adb_copyResource_t* _copyResource,
                   const axutil_env_t *env)
           {
               return adb_copyResource_reset_parentPath(_copyResource, env);
           }

           

            /**
             * Getter for oldResourcePath by  Property Number 2
             */
            axis2_char_t* AXIS2_CALL
            adb_copyResource_get_property2(
                adb_copyResource_t* _copyResource,
                const axutil_env_t *env)
            {
                return adb_copyResource_get_oldResourcePath(_copyResource,
                                             env);
            }

            /**
             * getter for oldResourcePath.
             */
            axis2_char_t* AXIS2_CALL
            adb_copyResource_get_oldResourcePath(
                    adb_copyResource_t* _copyResource,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _copyResource, NULL);
                  

                return _copyResource->property_oldResourcePath;
             }

            /**
             * setter for oldResourcePath
             */
            axis2_status_t AXIS2_CALL
            adb_copyResource_set_oldResourcePath(
                    adb_copyResource_t* _copyResource,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_oldResourcePath)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _copyResource, AXIS2_FAILURE);
                
                if(_copyResource->is_valid_oldResourcePath &&
                        arg_oldResourcePath == _copyResource->property_oldResourcePath)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_copyResource_reset_oldResourcePath(_copyResource, env);

                
                if(NULL == arg_oldResourcePath)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _copyResource->property_oldResourcePath = (axis2_char_t *)axutil_strdup(env, arg_oldResourcePath);
                        if(NULL == _copyResource->property_oldResourcePath)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for oldResourcePath");
                            return AXIS2_FAILURE;
                        }
                        _copyResource->is_valid_oldResourcePath = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for oldResourcePath
            */
           axis2_status_t AXIS2_CALL
           adb_copyResource_reset_oldResourcePath(
                   adb_copyResource_t* _copyResource,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _copyResource, AXIS2_FAILURE);
               

               
            
                
                if(_copyResource->property_oldResourcePath != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _copyResource->property_oldResourcePath);
                     _copyResource->property_oldResourcePath = NULL;
                }
            
                
                
                _copyResource->is_valid_oldResourcePath = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether oldResourcePath is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_copyResource_is_oldResourcePath_nil(
                   adb_copyResource_t* _copyResource,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _copyResource, AXIS2_TRUE);
               
               return !_copyResource->is_valid_oldResourcePath;
           }

           /**
            * Set oldResourcePath to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_copyResource_set_oldResourcePath_nil(
                   adb_copyResource_t* _copyResource,
                   const axutil_env_t *env)
           {
               return adb_copyResource_reset_oldResourcePath(_copyResource, env);
           }

           

            /**
             * Getter for destinationPath by  Property Number 3
             */
            axis2_char_t* AXIS2_CALL
            adb_copyResource_get_property3(
                adb_copyResource_t* _copyResource,
                const axutil_env_t *env)
            {
                return adb_copyResource_get_destinationPath(_copyResource,
                                             env);
            }

            /**
             * getter for destinationPath.
             */
            axis2_char_t* AXIS2_CALL
            adb_copyResource_get_destinationPath(
                    adb_copyResource_t* _copyResource,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _copyResource, NULL);
                  

                return _copyResource->property_destinationPath;
             }

            /**
             * setter for destinationPath
             */
            axis2_status_t AXIS2_CALL
            adb_copyResource_set_destinationPath(
                    adb_copyResource_t* _copyResource,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_destinationPath)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _copyResource, AXIS2_FAILURE);
                
                if(_copyResource->is_valid_destinationPath &&
                        arg_destinationPath == _copyResource->property_destinationPath)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_copyResource_reset_destinationPath(_copyResource, env);

                
                if(NULL == arg_destinationPath)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _copyResource->property_destinationPath = (axis2_char_t *)axutil_strdup(env, arg_destinationPath);
                        if(NULL == _copyResource->property_destinationPath)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for destinationPath");
                            return AXIS2_FAILURE;
                        }
                        _copyResource->is_valid_destinationPath = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for destinationPath
            */
           axis2_status_t AXIS2_CALL
           adb_copyResource_reset_destinationPath(
                   adb_copyResource_t* _copyResource,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _copyResource, AXIS2_FAILURE);
               

               
            
                
                if(_copyResource->property_destinationPath != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _copyResource->property_destinationPath);
                     _copyResource->property_destinationPath = NULL;
                }
            
                
                
                _copyResource->is_valid_destinationPath = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether destinationPath is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_copyResource_is_destinationPath_nil(
                   adb_copyResource_t* _copyResource,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _copyResource, AXIS2_TRUE);
               
               return !_copyResource->is_valid_destinationPath;
           }

           /**
            * Set destinationPath to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_copyResource_set_destinationPath_nil(
                   adb_copyResource_t* _copyResource,
                   const axutil_env_t *env)
           {
               return adb_copyResource_reset_destinationPath(_copyResource, env);
           }

           

            /**
             * Getter for resourceName by  Property Number 4
             */
            axis2_char_t* AXIS2_CALL
            adb_copyResource_get_property4(
                adb_copyResource_t* _copyResource,
                const axutil_env_t *env)
            {
                return adb_copyResource_get_resourceName(_copyResource,
                                             env);
            }

            /**
             * getter for resourceName.
             */
            axis2_char_t* AXIS2_CALL
            adb_copyResource_get_resourceName(
                    adb_copyResource_t* _copyResource,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _copyResource, NULL);
                  

                return _copyResource->property_resourceName;
             }

            /**
             * setter for resourceName
             */
            axis2_status_t AXIS2_CALL
            adb_copyResource_set_resourceName(
                    adb_copyResource_t* _copyResource,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_resourceName)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _copyResource, AXIS2_FAILURE);
                
                if(_copyResource->is_valid_resourceName &&
                        arg_resourceName == _copyResource->property_resourceName)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_copyResource_reset_resourceName(_copyResource, env);

                
                if(NULL == arg_resourceName)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _copyResource->property_resourceName = (axis2_char_t *)axutil_strdup(env, arg_resourceName);
                        if(NULL == _copyResource->property_resourceName)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for resourceName");
                            return AXIS2_FAILURE;
                        }
                        _copyResource->is_valid_resourceName = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for resourceName
            */
           axis2_status_t AXIS2_CALL
           adb_copyResource_reset_resourceName(
                   adb_copyResource_t* _copyResource,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _copyResource, AXIS2_FAILURE);
               

               
            
                
                if(_copyResource->property_resourceName != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _copyResource->property_resourceName);
                     _copyResource->property_resourceName = NULL;
                }
            
                
                
                _copyResource->is_valid_resourceName = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether resourceName is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_copyResource_is_resourceName_nil(
                   adb_copyResource_t* _copyResource,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _copyResource, AXIS2_TRUE);
               
               return !_copyResource->is_valid_resourceName;
           }

           /**
            * Set resourceName to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_copyResource_set_resourceName_nil(
                   adb_copyResource_t* _copyResource,
                   const axutil_env_t *env)
           {
               return adb_copyResource_reset_resourceName(_copyResource, env);
           }

           

