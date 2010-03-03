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
         * adb_WebResourcePath.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_WebResourcePath.h"
        
                /*
                 * This type was generated from the piece of schema that had
                 * name = WebResourcePath
                 * Namespace URI = http://common.registry.carbon.wso2.org/xsd
                 * Namespace Prefix = ns4
                 */
           


        struct adb_WebResourcePath
        {
            axis2_char_t *property_Type;

            axis2_char_t* property_navigateName;

                
                axis2_bool_t is_valid_navigateName;
            axis2_char_t* property_navigatePath;

                
                axis2_bool_t is_valid_navigatePath;
            
        };


       /************************* Private Function prototypes ********************************/
        


       /************************* Function Implmentations ********************************/
        adb_WebResourcePath_t* AXIS2_CALL
        adb_WebResourcePath_create(
            const axutil_env_t *env)
        {
            adb_WebResourcePath_t *_WebResourcePath = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _WebResourcePath = (adb_WebResourcePath_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_WebResourcePath_t));

            if(NULL == _WebResourcePath)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_WebResourcePath, 0, sizeof(adb_WebResourcePath_t));

            _WebResourcePath->property_Type = axutil_strdup(env, "adb_WebResourcePath");
            _WebResourcePath->property_navigateName  = NULL;
                  _WebResourcePath->is_valid_navigateName  = AXIS2_FALSE;
            _WebResourcePath->property_navigatePath  = NULL;
                  _WebResourcePath->is_valid_navigatePath  = AXIS2_FALSE;
            

            return _WebResourcePath;
        }

        adb_WebResourcePath_t* AXIS2_CALL
        adb_WebResourcePath_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _navigateName,
                axis2_char_t* _navigatePath)
        {
            adb_WebResourcePath_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_WebResourcePath_create(env);

            
              status = adb_WebResourcePath_set_navigateName(
                                     adb_obj,
                                     env,
                                     _navigateName);
              if(status == AXIS2_FAILURE) {
                  adb_WebResourcePath_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_WebResourcePath_set_navigatePath(
                                     adb_obj,
                                     env,
                                     _navigatePath);
              if(status == AXIS2_FAILURE) {
                  adb_WebResourcePath_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_char_t* AXIS2_CALL
                adb_WebResourcePath_free_popping_value(
                        adb_WebResourcePath_t* _WebResourcePath,
                        const axutil_env_t *env)
                {
                    axis2_char_t* value;

                    
                    
                    value = _WebResourcePath->property_navigateName;

                    _WebResourcePath->property_navigateName = (axis2_char_t*)NULL;
                    adb_WebResourcePath_free(_WebResourcePath, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_WebResourcePath_free(
                adb_WebResourcePath_t* _WebResourcePath,
                const axutil_env_t *env)
        {
            
            
            return axis2_extension_mapper_free(
                (adb_type_t*) _WebResourcePath,
                env,
                "adb_WebResourcePath");
            
        }

        axis2_status_t AXIS2_CALL
        adb_WebResourcePath_free_obj(
                adb_WebResourcePath_t* _WebResourcePath,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _WebResourcePath, AXIS2_FAILURE);

            if (_WebResourcePath->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _WebResourcePath->property_Type);
            }

            adb_WebResourcePath_reset_navigateName(_WebResourcePath, env);
            adb_WebResourcePath_reset_navigatePath(_WebResourcePath, env);
            

            if(_WebResourcePath)
            {
                AXIS2_FREE(env->allocator, _WebResourcePath);
                _WebResourcePath = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_WebResourcePath_deserialize(
                adb_WebResourcePath_t* _WebResourcePath,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return axis2_extension_mapper_deserialize(
                (adb_type_t*) _WebResourcePath,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs,
                "adb_WebResourcePath");
            
        }

        axis2_status_t AXIS2_CALL
        adb_WebResourcePath_deserialize_obj(
                adb_WebResourcePath_t* _WebResourcePath,
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
            AXIS2_PARAM_CHECK(env->error, _WebResourcePath, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for WebResourcePath : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              
                      
                      first_node = axiom_node_get_first_child(parent, env);
                      
                    

                     
                     /*
                      * building navigateName element
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
                                   
                                 element_qname = axutil_qname_create(env, "navigateName", "http://common.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_WebResourcePath_set_navigateName(_WebResourcePath, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for navigateName ");
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
                      * building navigatePath element
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
                                 
                                 element_qname = axutil_qname_create(env, "navigatePath", "http://common.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_WebResourcePath_set_navigatePath(_WebResourcePath, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for navigatePath ");
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
          adb_WebResourcePath_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_WebResourcePath_declare_parent_namespaces(
                    adb_WebResourcePath_t* _WebResourcePath,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_WebResourcePath_serialize(
                adb_WebResourcePath_t* _WebResourcePath,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
            if (_WebResourcePath == NULL)
            {
                return adb_WebResourcePath_serialize_obj(
                    _WebResourcePath, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            }
            else
            {
                return axis2_extension_mapper_serialize(
                    (adb_type_t*) _WebResourcePath, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index, "adb_WebResourcePath");
            }
            
        }

        axiom_node_t* AXIS2_CALL
        adb_WebResourcePath_serialize_obj(
                adb_WebResourcePath_t* _WebResourcePath,
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
            
                    axis2_char_t *text_value_1;
                    axis2_char_t *text_value_1_temp;
                    
                    axis2_char_t *text_value_2;
                    axis2_char_t *text_value_2_temp;
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _WebResourcePath, NULL);
            
            
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
              type_attrib = axutil_strcat(env, " ", xsi_prefix, ":type=\"WebResourcePath\"", NULL);
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
                                 "http://common.registry.carbon.wso2.org/xsd",
                                 xsi_prefix);
            xsi_type_attri = axiom_attribute_create (env, "type", "WebResourcePath", xsi_ns);
            
            axiom_element_add_attribute (parent_element, env, xsi_type_attri, parent);
        
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://common.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_WebResourcePath->is_valid_navigateName)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("navigateName"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("navigateName")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing navigateName element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%snavigateName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%snavigateName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_1 = _WebResourcePath->property_navigateName;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://common.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://common.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_WebResourcePath->is_valid_navigatePath)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("navigatePath"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("navigatePath")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing navigatePath element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%snavigatePath>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%snavigatePath>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_2 = _WebResourcePath->property_navigatePath;
                           
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

                 

            return parent;
        }


        

            /**
             * Getter for navigateName by  Property Number 1
             */
            axis2_char_t* AXIS2_CALL
            adb_WebResourcePath_get_property1(
                adb_WebResourcePath_t* _WebResourcePath,
                const axutil_env_t *env)
            {
                return adb_WebResourcePath_get_navigateName(_WebResourcePath,
                                             env);
            }

            /**
             * getter for navigateName.
             */
            axis2_char_t* AXIS2_CALL
            adb_WebResourcePath_get_navigateName(
                    adb_WebResourcePath_t* _WebResourcePath,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _WebResourcePath, NULL);
                  

                return _WebResourcePath->property_navigateName;
             }

            /**
             * setter for navigateName
             */
            axis2_status_t AXIS2_CALL
            adb_WebResourcePath_set_navigateName(
                    adb_WebResourcePath_t* _WebResourcePath,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_navigateName)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _WebResourcePath, AXIS2_FAILURE);
                
                if(_WebResourcePath->is_valid_navigateName &&
                        arg_navigateName == _WebResourcePath->property_navigateName)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_WebResourcePath_reset_navigateName(_WebResourcePath, env);

                
                if(NULL == arg_navigateName)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _WebResourcePath->property_navigateName = (axis2_char_t *)axutil_strdup(env, arg_navigateName);
                        if(NULL == _WebResourcePath->property_navigateName)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for navigateName");
                            return AXIS2_FAILURE;
                        }
                        _WebResourcePath->is_valid_navigateName = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for navigateName
            */
           axis2_status_t AXIS2_CALL
           adb_WebResourcePath_reset_navigateName(
                   adb_WebResourcePath_t* _WebResourcePath,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _WebResourcePath, AXIS2_FAILURE);
               

               
            
                
                if(_WebResourcePath->property_navigateName != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _WebResourcePath->property_navigateName);
                     _WebResourcePath->property_navigateName = NULL;
                }
            
                
                
                _WebResourcePath->is_valid_navigateName = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether navigateName is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_WebResourcePath_is_navigateName_nil(
                   adb_WebResourcePath_t* _WebResourcePath,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _WebResourcePath, AXIS2_TRUE);
               
               return !_WebResourcePath->is_valid_navigateName;
           }

           /**
            * Set navigateName to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_WebResourcePath_set_navigateName_nil(
                   adb_WebResourcePath_t* _WebResourcePath,
                   const axutil_env_t *env)
           {
               return adb_WebResourcePath_reset_navigateName(_WebResourcePath, env);
           }

           

            /**
             * Getter for navigatePath by  Property Number 2
             */
            axis2_char_t* AXIS2_CALL
            adb_WebResourcePath_get_property2(
                adb_WebResourcePath_t* _WebResourcePath,
                const axutil_env_t *env)
            {
                return adb_WebResourcePath_get_navigatePath(_WebResourcePath,
                                             env);
            }

            /**
             * getter for navigatePath.
             */
            axis2_char_t* AXIS2_CALL
            adb_WebResourcePath_get_navigatePath(
                    adb_WebResourcePath_t* _WebResourcePath,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _WebResourcePath, NULL);
                  

                return _WebResourcePath->property_navigatePath;
             }

            /**
             * setter for navigatePath
             */
            axis2_status_t AXIS2_CALL
            adb_WebResourcePath_set_navigatePath(
                    adb_WebResourcePath_t* _WebResourcePath,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_navigatePath)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _WebResourcePath, AXIS2_FAILURE);
                
                if(_WebResourcePath->is_valid_navigatePath &&
                        arg_navigatePath == _WebResourcePath->property_navigatePath)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_WebResourcePath_reset_navigatePath(_WebResourcePath, env);

                
                if(NULL == arg_navigatePath)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _WebResourcePath->property_navigatePath = (axis2_char_t *)axutil_strdup(env, arg_navigatePath);
                        if(NULL == _WebResourcePath->property_navigatePath)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for navigatePath");
                            return AXIS2_FAILURE;
                        }
                        _WebResourcePath->is_valid_navigatePath = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for navigatePath
            */
           axis2_status_t AXIS2_CALL
           adb_WebResourcePath_reset_navigatePath(
                   adb_WebResourcePath_t* _WebResourcePath,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _WebResourcePath, AXIS2_FAILURE);
               

               
            
                
                if(_WebResourcePath->property_navigatePath != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _WebResourcePath->property_navigatePath);
                     _WebResourcePath->property_navigatePath = NULL;
                }
            
                
                
                _WebResourcePath->is_valid_navigatePath = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether navigatePath is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_WebResourcePath_is_navigatePath_nil(
                   adb_WebResourcePath_t* _WebResourcePath,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _WebResourcePath, AXIS2_TRUE);
               
               return !_WebResourcePath->is_valid_navigatePath;
           }

           /**
            * Set navigatePath to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_WebResourcePath_set_navigatePath_nil(
                   adb_WebResourcePath_t* _WebResourcePath,
                   const axutil_env_t *env)
           {
               return adb_WebResourcePath_reset_navigatePath(_WebResourcePath, env);
           }

           

