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
         * adb_ContentDownloadBean.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_ContentDownloadBean.h"
        
                /*
                 * This type was generated from the piece of schema that had
                 * name = ContentDownloadBean
                 * Namespace URI = http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd
                 * Namespace Prefix = ns3
                 */
           


        struct adb_ContentDownloadBean
        {
            axis2_char_t *property_Type;

            axutil_base64_binary_t* property_content;

                
                axis2_bool_t is_valid_content;
            axutil_date_time_t* property_lastUpdatedTime;

                
                axis2_bool_t is_valid_lastUpdatedTime;
            axis2_char_t* property_mediatype;

                
                axis2_bool_t is_valid_mediatype;
            axis2_char_t* property_resourceName;

                
                axis2_bool_t is_valid_resourceName;
            
        };


       /************************* Private Function prototypes ********************************/
        


       /************************* Function Implmentations ********************************/
        adb_ContentDownloadBean_t* AXIS2_CALL
        adb_ContentDownloadBean_create(
            const axutil_env_t *env)
        {
            adb_ContentDownloadBean_t *_ContentDownloadBean = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _ContentDownloadBean = (adb_ContentDownloadBean_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_ContentDownloadBean_t));

            if(NULL == _ContentDownloadBean)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_ContentDownloadBean, 0, sizeof(adb_ContentDownloadBean_t));

            _ContentDownloadBean->property_Type = axutil_strdup(env, "adb_ContentDownloadBean");
            _ContentDownloadBean->property_content  = NULL;
                  _ContentDownloadBean->is_valid_content  = AXIS2_FALSE;
            _ContentDownloadBean->property_lastUpdatedTime  = NULL;
                  _ContentDownloadBean->is_valid_lastUpdatedTime  = AXIS2_FALSE;
            _ContentDownloadBean->property_mediatype  = NULL;
                  _ContentDownloadBean->is_valid_mediatype  = AXIS2_FALSE;
            _ContentDownloadBean->property_resourceName  = NULL;
                  _ContentDownloadBean->is_valid_resourceName  = AXIS2_FALSE;
            

            return _ContentDownloadBean;
        }

        adb_ContentDownloadBean_t* AXIS2_CALL
        adb_ContentDownloadBean_create_with_values(
            const axutil_env_t *env,
                axutil_base64_binary_t* _content,
                axutil_date_time_t* _lastUpdatedTime,
                axis2_char_t* _mediatype,
                axis2_char_t* _resourceName)
        {
            adb_ContentDownloadBean_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_ContentDownloadBean_create(env);

            
              status = adb_ContentDownloadBean_set_content(
                                     adb_obj,
                                     env,
                                     _content);
              if(status == AXIS2_FAILURE) {
                  adb_ContentDownloadBean_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ContentDownloadBean_set_lastUpdatedTime(
                                     adb_obj,
                                     env,
                                     _lastUpdatedTime);
              if(status == AXIS2_FAILURE) {
                  adb_ContentDownloadBean_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ContentDownloadBean_set_mediatype(
                                     adb_obj,
                                     env,
                                     _mediatype);
              if(status == AXIS2_FAILURE) {
                  adb_ContentDownloadBean_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ContentDownloadBean_set_resourceName(
                                     adb_obj,
                                     env,
                                     _resourceName);
              if(status == AXIS2_FAILURE) {
                  adb_ContentDownloadBean_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axutil_base64_binary_t* AXIS2_CALL
                adb_ContentDownloadBean_free_popping_value(
                        adb_ContentDownloadBean_t* _ContentDownloadBean,
                        const axutil_env_t *env)
                {
                    axutil_base64_binary_t* value;

                    
                    
                    value = _ContentDownloadBean->property_content;

                    _ContentDownloadBean->property_content = (axutil_base64_binary_t*)NULL;
                    adb_ContentDownloadBean_free(_ContentDownloadBean, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_ContentDownloadBean_free(
                adb_ContentDownloadBean_t* _ContentDownloadBean,
                const axutil_env_t *env)
        {
            
            
            return axis2_extension_mapper_free(
                (adb_type_t*) _ContentDownloadBean,
                env,
                "adb_ContentDownloadBean");
            
        }

        axis2_status_t AXIS2_CALL
        adb_ContentDownloadBean_free_obj(
                adb_ContentDownloadBean_t* _ContentDownloadBean,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _ContentDownloadBean, AXIS2_FAILURE);

            if (_ContentDownloadBean->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _ContentDownloadBean->property_Type);
            }

            adb_ContentDownloadBean_reset_content(_ContentDownloadBean, env);
            adb_ContentDownloadBean_reset_lastUpdatedTime(_ContentDownloadBean, env);
            adb_ContentDownloadBean_reset_mediatype(_ContentDownloadBean, env);
            adb_ContentDownloadBean_reset_resourceName(_ContentDownloadBean, env);
            

            if(_ContentDownloadBean)
            {
                AXIS2_FREE(env->allocator, _ContentDownloadBean);
                _ContentDownloadBean = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_ContentDownloadBean_deserialize(
                adb_ContentDownloadBean_t* _ContentDownloadBean,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return axis2_extension_mapper_deserialize(
                (adb_type_t*) _ContentDownloadBean,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs,
                "adb_ContentDownloadBean");
            
        }

        axis2_status_t AXIS2_CALL
        adb_ContentDownloadBean_deserialize_obj(
                adb_ContentDownloadBean_t* _ContentDownloadBean,
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
            AXIS2_PARAM_CHECK(env->error, _ContentDownloadBean, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for ContentDownloadBean : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              
                      
                      first_node = axiom_node_get_first_child(parent, env);
                      
                    

                     
                     /*
                      * building content element
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
                                   
                                 element_qname = axutil_qname_create(env, "content", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ContentDownloadBean_set_content(_ContentDownloadBean, env,
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
                      * building lastUpdatedTime element
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
                                 
                                 element_qname = axutil_qname_create(env, "lastUpdatedTime", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                          element = (void*)axutil_date_time_create(env);
                                          status = axutil_date_time_deserialize_date_time((axutil_date_time_t*)element, env,
                                                                          text_value);
                                          if(AXIS2_FAILURE ==  status)
                                          {
                                              if(element != NULL)
                                              {
                                                  axutil_date_time_free((axutil_date_time_t*)element, env);
                                              }
                                              AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building element lastUpdatedTime ");
                                          }
                                          else
                                          {
                                            status = adb_ContentDownloadBean_set_lastUpdatedTime(_ContentDownloadBean, env,
                                                                       (axutil_date_time_t*)element);
                                          }
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for lastUpdatedTime ");
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
                      * building mediatype element
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
                                 
                                 element_qname = axutil_qname_create(env, "mediatype", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ContentDownloadBean_set_mediatype(_ContentDownloadBean, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for mediatype ");
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
                                 
                                 element_qname = axutil_qname_create(env, "resourceName", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ContentDownloadBean_set_resourceName(_ContentDownloadBean, env,
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
          adb_ContentDownloadBean_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_ContentDownloadBean_declare_parent_namespaces(
                    adb_ContentDownloadBean_t* _ContentDownloadBean,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_ContentDownloadBean_serialize(
                adb_ContentDownloadBean_t* _ContentDownloadBean,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
            if (_ContentDownloadBean == NULL)
            {
                return adb_ContentDownloadBean_serialize_obj(
                    _ContentDownloadBean, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            }
            else
            {
                return axis2_extension_mapper_serialize(
                    (adb_type_t*) _ContentDownloadBean, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index, "adb_ContentDownloadBean");
            }
            
        }

        axiom_node_t* AXIS2_CALL
        adb_ContentDownloadBean_serialize_obj(
                adb_ContentDownloadBean_t* _ContentDownloadBean,
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

            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _ContentDownloadBean, NULL);
            
            
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
              type_attrib = axutil_strcat(env, " ", xsi_prefix, ":type=\"ContentDownloadBean\"", NULL);
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
                                 "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd",
                                 xsi_prefix);
            xsi_type_attri = axiom_attribute_create (env, "type", "ContentDownloadBean", xsi_ns);
            
            axiom_element_add_attribute (parent_element, env, xsi_type_attri, parent);
        
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ContentDownloadBean->is_valid_content)
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
                    
                          text_value_1 =axutil_base64_binary_get_encoded_binary(_ContentDownloadBean->property_content, env);
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_1, axutil_strlen(text_value_1));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ContentDownloadBean->is_valid_lastUpdatedTime)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("lastUpdatedTime"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("lastUpdatedTime")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing lastUpdatedTime element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%slastUpdatedTime>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%slastUpdatedTime>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                          text_value_2 = axutil_date_time_serialize_date_time(_ContentDownloadBean->property_lastUpdatedTime, env);
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_2, axutil_strlen(text_value_2));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ContentDownloadBean->is_valid_mediatype)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("mediatype"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("mediatype")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing mediatype element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%smediatype>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%smediatype>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_3 = _ContentDownloadBean->property_mediatype;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ContentDownloadBean->is_valid_resourceName)
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
                    
                           text_value_4 = _ContentDownloadBean->property_resourceName;
                           
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

                 

            return parent;
        }


        

            /**
             * Getter for content by  Property Number 1
             */
            axutil_base64_binary_t* AXIS2_CALL
            adb_ContentDownloadBean_get_property1(
                adb_ContentDownloadBean_t* _ContentDownloadBean,
                const axutil_env_t *env)
            {
                return adb_ContentDownloadBean_get_content(_ContentDownloadBean,
                                             env);
            }

            /**
             * getter for content.
             */
            axutil_base64_binary_t* AXIS2_CALL
            adb_ContentDownloadBean_get_content(
                    adb_ContentDownloadBean_t* _ContentDownloadBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ContentDownloadBean, NULL);
                  

                return _ContentDownloadBean->property_content;
             }

            /**
             * setter for content
             */
            axis2_status_t AXIS2_CALL
            adb_ContentDownloadBean_set_content(
                    adb_ContentDownloadBean_t* _ContentDownloadBean,
                    const axutil_env_t *env,
                    axutil_base64_binary_t*  arg_content)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ContentDownloadBean, AXIS2_FAILURE);
                
                if(_ContentDownloadBean->is_valid_content &&
                        arg_content == _ContentDownloadBean->property_content)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ContentDownloadBean_reset_content(_ContentDownloadBean, env);

                
                if(NULL == arg_content)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ContentDownloadBean->property_content = arg_content;
                        _ContentDownloadBean->is_valid_content = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for content
            */
           axis2_status_t AXIS2_CALL
           adb_ContentDownloadBean_reset_content(
                   adb_ContentDownloadBean_t* _ContentDownloadBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ContentDownloadBean, AXIS2_FAILURE);
               

               
            
                
                if(_ContentDownloadBean->property_content != NULL)
                {
                   
                   
                      axutil_base64_binary_free (_ContentDownloadBean->property_content, env);
                     _ContentDownloadBean->property_content = NULL;
                }
            
                
                
                _ContentDownloadBean->is_valid_content = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether content is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ContentDownloadBean_is_content_nil(
                   adb_ContentDownloadBean_t* _ContentDownloadBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ContentDownloadBean, AXIS2_TRUE);
               
               return !_ContentDownloadBean->is_valid_content;
           }

           /**
            * Set content to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ContentDownloadBean_set_content_nil(
                   adb_ContentDownloadBean_t* _ContentDownloadBean,
                   const axutil_env_t *env)
           {
               return adb_ContentDownloadBean_reset_content(_ContentDownloadBean, env);
           }

           

            /**
             * Getter for lastUpdatedTime by  Property Number 2
             */
            axutil_date_time_t* AXIS2_CALL
            adb_ContentDownloadBean_get_property2(
                adb_ContentDownloadBean_t* _ContentDownloadBean,
                const axutil_env_t *env)
            {
                return adb_ContentDownloadBean_get_lastUpdatedTime(_ContentDownloadBean,
                                             env);
            }

            /**
             * getter for lastUpdatedTime.
             */
            axutil_date_time_t* AXIS2_CALL
            adb_ContentDownloadBean_get_lastUpdatedTime(
                    adb_ContentDownloadBean_t* _ContentDownloadBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ContentDownloadBean, NULL);
                  

                return _ContentDownloadBean->property_lastUpdatedTime;
             }

            /**
             * setter for lastUpdatedTime
             */
            axis2_status_t AXIS2_CALL
            adb_ContentDownloadBean_set_lastUpdatedTime(
                    adb_ContentDownloadBean_t* _ContentDownloadBean,
                    const axutil_env_t *env,
                    axutil_date_time_t*  arg_lastUpdatedTime)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ContentDownloadBean, AXIS2_FAILURE);
                
                if(_ContentDownloadBean->is_valid_lastUpdatedTime &&
                        arg_lastUpdatedTime == _ContentDownloadBean->property_lastUpdatedTime)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ContentDownloadBean_reset_lastUpdatedTime(_ContentDownloadBean, env);

                
                if(NULL == arg_lastUpdatedTime)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ContentDownloadBean->property_lastUpdatedTime = arg_lastUpdatedTime;
                        _ContentDownloadBean->is_valid_lastUpdatedTime = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for lastUpdatedTime
            */
           axis2_status_t AXIS2_CALL
           adb_ContentDownloadBean_reset_lastUpdatedTime(
                   adb_ContentDownloadBean_t* _ContentDownloadBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ContentDownloadBean, AXIS2_FAILURE);
               

               
            
                
                if(_ContentDownloadBean->property_lastUpdatedTime != NULL)
                {
                   
                   
                      axutil_date_time_free(_ContentDownloadBean->property_lastUpdatedTime, env);
                     _ContentDownloadBean->property_lastUpdatedTime = NULL;
                }
            
                
                
                _ContentDownloadBean->is_valid_lastUpdatedTime = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether lastUpdatedTime is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ContentDownloadBean_is_lastUpdatedTime_nil(
                   adb_ContentDownloadBean_t* _ContentDownloadBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ContentDownloadBean, AXIS2_TRUE);
               
               return !_ContentDownloadBean->is_valid_lastUpdatedTime;
           }

           /**
            * Set lastUpdatedTime to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ContentDownloadBean_set_lastUpdatedTime_nil(
                   adb_ContentDownloadBean_t* _ContentDownloadBean,
                   const axutil_env_t *env)
           {
               return adb_ContentDownloadBean_reset_lastUpdatedTime(_ContentDownloadBean, env);
           }

           

            /**
             * Getter for mediatype by  Property Number 3
             */
            axis2_char_t* AXIS2_CALL
            adb_ContentDownloadBean_get_property3(
                adb_ContentDownloadBean_t* _ContentDownloadBean,
                const axutil_env_t *env)
            {
                return adb_ContentDownloadBean_get_mediatype(_ContentDownloadBean,
                                             env);
            }

            /**
             * getter for mediatype.
             */
            axis2_char_t* AXIS2_CALL
            adb_ContentDownloadBean_get_mediatype(
                    adb_ContentDownloadBean_t* _ContentDownloadBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ContentDownloadBean, NULL);
                  

                return _ContentDownloadBean->property_mediatype;
             }

            /**
             * setter for mediatype
             */
            axis2_status_t AXIS2_CALL
            adb_ContentDownloadBean_set_mediatype(
                    adb_ContentDownloadBean_t* _ContentDownloadBean,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_mediatype)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ContentDownloadBean, AXIS2_FAILURE);
                
                if(_ContentDownloadBean->is_valid_mediatype &&
                        arg_mediatype == _ContentDownloadBean->property_mediatype)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ContentDownloadBean_reset_mediatype(_ContentDownloadBean, env);

                
                if(NULL == arg_mediatype)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ContentDownloadBean->property_mediatype = (axis2_char_t *)axutil_strdup(env, arg_mediatype);
                        if(NULL == _ContentDownloadBean->property_mediatype)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for mediatype");
                            return AXIS2_FAILURE;
                        }
                        _ContentDownloadBean->is_valid_mediatype = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for mediatype
            */
           axis2_status_t AXIS2_CALL
           adb_ContentDownloadBean_reset_mediatype(
                   adb_ContentDownloadBean_t* _ContentDownloadBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ContentDownloadBean, AXIS2_FAILURE);
               

               
            
                
                if(_ContentDownloadBean->property_mediatype != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ContentDownloadBean->property_mediatype);
                     _ContentDownloadBean->property_mediatype = NULL;
                }
            
                
                
                _ContentDownloadBean->is_valid_mediatype = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether mediatype is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ContentDownloadBean_is_mediatype_nil(
                   adb_ContentDownloadBean_t* _ContentDownloadBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ContentDownloadBean, AXIS2_TRUE);
               
               return !_ContentDownloadBean->is_valid_mediatype;
           }

           /**
            * Set mediatype to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ContentDownloadBean_set_mediatype_nil(
                   adb_ContentDownloadBean_t* _ContentDownloadBean,
                   const axutil_env_t *env)
           {
               return adb_ContentDownloadBean_reset_mediatype(_ContentDownloadBean, env);
           }

           

            /**
             * Getter for resourceName by  Property Number 4
             */
            axis2_char_t* AXIS2_CALL
            adb_ContentDownloadBean_get_property4(
                adb_ContentDownloadBean_t* _ContentDownloadBean,
                const axutil_env_t *env)
            {
                return adb_ContentDownloadBean_get_resourceName(_ContentDownloadBean,
                                             env);
            }

            /**
             * getter for resourceName.
             */
            axis2_char_t* AXIS2_CALL
            adb_ContentDownloadBean_get_resourceName(
                    adb_ContentDownloadBean_t* _ContentDownloadBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ContentDownloadBean, NULL);
                  

                return _ContentDownloadBean->property_resourceName;
             }

            /**
             * setter for resourceName
             */
            axis2_status_t AXIS2_CALL
            adb_ContentDownloadBean_set_resourceName(
                    adb_ContentDownloadBean_t* _ContentDownloadBean,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_resourceName)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ContentDownloadBean, AXIS2_FAILURE);
                
                if(_ContentDownloadBean->is_valid_resourceName &&
                        arg_resourceName == _ContentDownloadBean->property_resourceName)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ContentDownloadBean_reset_resourceName(_ContentDownloadBean, env);

                
                if(NULL == arg_resourceName)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ContentDownloadBean->property_resourceName = (axis2_char_t *)axutil_strdup(env, arg_resourceName);
                        if(NULL == _ContentDownloadBean->property_resourceName)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for resourceName");
                            return AXIS2_FAILURE;
                        }
                        _ContentDownloadBean->is_valid_resourceName = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for resourceName
            */
           axis2_status_t AXIS2_CALL
           adb_ContentDownloadBean_reset_resourceName(
                   adb_ContentDownloadBean_t* _ContentDownloadBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ContentDownloadBean, AXIS2_FAILURE);
               

               
            
                
                if(_ContentDownloadBean->property_resourceName != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ContentDownloadBean->property_resourceName);
                     _ContentDownloadBean->property_resourceName = NULL;
                }
            
                
                
                _ContentDownloadBean->is_valid_resourceName = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether resourceName is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ContentDownloadBean_is_resourceName_nil(
                   adb_ContentDownloadBean_t* _ContentDownloadBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ContentDownloadBean, AXIS2_TRUE);
               
               return !_ContentDownloadBean->is_valid_resourceName;
           }

           /**
            * Set resourceName to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ContentDownloadBean_set_resourceName_nil(
                   adb_ContentDownloadBean_t* _ContentDownloadBean,
                   const axutil_env_t *env)
           {
               return adb_ContentDownloadBean_reset_resourceName(_ContentDownloadBean, env);
           }

           

