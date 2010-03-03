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
         * adb_FaultyService.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_FaultyService.h"
        
                /*
                 * This type was generated from the piece of schema that had
                 * name = FaultyService
                 * Namespace URI = http://mgt.service.carbon.wso2.org/xsd
                 * Namespace Prefix = ns4
                 */
           


        struct adb_FaultyService
        {
            axis2_char_t *property_Type;

            axis2_char_t* property_artifact;

                
                axis2_bool_t is_valid_artifact;
            axis2_char_t* property_fault;

                
                axis2_bool_t is_valid_fault;
            axis2_char_t* property_serviceName;

                
                axis2_bool_t is_valid_serviceName;
            axis2_char_t* property_serviceType;

                
                axis2_bool_t is_valid_serviceType;
            
        };


       /************************* Private Function prototypes ********************************/
        


       /************************* Function Implmentations ********************************/
        adb_FaultyService_t* AXIS2_CALL
        adb_FaultyService_create(
            const axutil_env_t *env)
        {
            adb_FaultyService_t *_FaultyService = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _FaultyService = (adb_FaultyService_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_FaultyService_t));

            if(NULL == _FaultyService)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_FaultyService, 0, sizeof(adb_FaultyService_t));

            _FaultyService->property_Type = axutil_strdup(env, "adb_FaultyService");
            _FaultyService->property_artifact  = NULL;
                  _FaultyService->is_valid_artifact  = AXIS2_FALSE;
            _FaultyService->property_fault  = NULL;
                  _FaultyService->is_valid_fault  = AXIS2_FALSE;
            _FaultyService->property_serviceName  = NULL;
                  _FaultyService->is_valid_serviceName  = AXIS2_FALSE;
            _FaultyService->property_serviceType  = NULL;
                  _FaultyService->is_valid_serviceType  = AXIS2_FALSE;
            

            return _FaultyService;
        }

        adb_FaultyService_t* AXIS2_CALL
        adb_FaultyService_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _artifact,
                axis2_char_t* _fault,
                axis2_char_t* _serviceName,
                axis2_char_t* _serviceType)
        {
            adb_FaultyService_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_FaultyService_create(env);

            
              status = adb_FaultyService_set_artifact(
                                     adb_obj,
                                     env,
                                     _artifact);
              if(status == AXIS2_FAILURE) {
                  adb_FaultyService_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_FaultyService_set_fault(
                                     adb_obj,
                                     env,
                                     _fault);
              if(status == AXIS2_FAILURE) {
                  adb_FaultyService_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_FaultyService_set_serviceName(
                                     adb_obj,
                                     env,
                                     _serviceName);
              if(status == AXIS2_FAILURE) {
                  adb_FaultyService_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_FaultyService_set_serviceType(
                                     adb_obj,
                                     env,
                                     _serviceType);
              if(status == AXIS2_FAILURE) {
                  adb_FaultyService_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_char_t* AXIS2_CALL
                adb_FaultyService_free_popping_value(
                        adb_FaultyService_t* _FaultyService,
                        const axutil_env_t *env)
                {
                    axis2_char_t* value;

                    
                    
                    value = _FaultyService->property_artifact;

                    _FaultyService->property_artifact = (axis2_char_t*)NULL;
                    adb_FaultyService_free(_FaultyService, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_FaultyService_free(
                adb_FaultyService_t* _FaultyService,
                const axutil_env_t *env)
        {
            
            
            return axis2_extension_mapper_free(
                (adb_type_t*) _FaultyService,
                env,
                "adb_FaultyService");
            
        }

        axis2_status_t AXIS2_CALL
        adb_FaultyService_free_obj(
                adb_FaultyService_t* _FaultyService,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _FaultyService, AXIS2_FAILURE);

            if (_FaultyService->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _FaultyService->property_Type);
            }

            adb_FaultyService_reset_artifact(_FaultyService, env);
            adb_FaultyService_reset_fault(_FaultyService, env);
            adb_FaultyService_reset_serviceName(_FaultyService, env);
            adb_FaultyService_reset_serviceType(_FaultyService, env);
            

            if(_FaultyService)
            {
                AXIS2_FREE(env->allocator, _FaultyService);
                _FaultyService = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_FaultyService_deserialize(
                adb_FaultyService_t* _FaultyService,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return axis2_extension_mapper_deserialize(
                (adb_type_t*) _FaultyService,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs,
                "adb_FaultyService");
            
        }

        axis2_status_t AXIS2_CALL
        adb_FaultyService_deserialize_obj(
                adb_FaultyService_t* _FaultyService,
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
            AXIS2_PARAM_CHECK(env->error, _FaultyService, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for FaultyService : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              
                      
                      first_node = axiom_node_get_first_child(parent, env);
                      
                    

                     
                     /*
                      * building artifact element
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
                                   
                                 element_qname = axutil_qname_create(env, "artifact", "http://mgt.service.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_FaultyService_set_artifact(_FaultyService, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for artifact ");
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
                      * building fault element
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
                                 
                                 element_qname = axutil_qname_create(env, "fault", "http://mgt.service.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_FaultyService_set_fault(_FaultyService, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for fault ");
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
                      * building serviceName element
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
                                 
                                 element_qname = axutil_qname_create(env, "serviceName", "http://mgt.service.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_FaultyService_set_serviceName(_FaultyService, env,
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
                      * building serviceType element
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
                                 
                                 element_qname = axutil_qname_create(env, "serviceType", "http://mgt.service.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_FaultyService_set_serviceType(_FaultyService, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for serviceType ");
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
          adb_FaultyService_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_FaultyService_declare_parent_namespaces(
                    adb_FaultyService_t* _FaultyService,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_FaultyService_serialize(
                adb_FaultyService_t* _FaultyService,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
            if (_FaultyService == NULL)
            {
                return adb_FaultyService_serialize_obj(
                    _FaultyService, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            }
            else
            {
                return axis2_extension_mapper_serialize(
                    (adb_type_t*) _FaultyService, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index, "adb_FaultyService");
            }
            
        }

        axiom_node_t* AXIS2_CALL
        adb_FaultyService_serialize_obj(
                adb_FaultyService_t* _FaultyService,
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
            AXIS2_PARAM_CHECK(env->error, _FaultyService, NULL);
            
            
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
              type_attrib = axutil_strcat(env, " ", xsi_prefix, ":type=\"FaultyService\"", NULL);
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
                                 "http://mgt.service.carbon.wso2.org/xsd",
                                 xsi_prefix);
            xsi_type_attri = axiom_attribute_create (env, "type", "FaultyService", xsi_ns);
            
            axiom_element_add_attribute (parent_element, env, xsi_type_attri, parent);
        
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://mgt.service.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://mgt.service.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://mgt.service.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_FaultyService->is_valid_artifact)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("artifact"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("artifact")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing artifact element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sartifact>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sartifact>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_1 = _FaultyService->property_artifact;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://mgt.service.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://mgt.service.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://mgt.service.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_FaultyService->is_valid_fault)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("fault"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("fault")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing fault element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sfault>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sfault>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_2 = _FaultyService->property_fault;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://mgt.service.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://mgt.service.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://mgt.service.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_FaultyService->is_valid_serviceName)
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
                    
                           text_value_3 = _FaultyService->property_serviceName;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://mgt.service.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://mgt.service.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://mgt.service.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_FaultyService->is_valid_serviceType)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("serviceType"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("serviceType")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing serviceType element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sserviceType>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sserviceType>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_4 = _FaultyService->property_serviceType;
                           
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
             * Getter for artifact by  Property Number 1
             */
            axis2_char_t* AXIS2_CALL
            adb_FaultyService_get_property1(
                adb_FaultyService_t* _FaultyService,
                const axutil_env_t *env)
            {
                return adb_FaultyService_get_artifact(_FaultyService,
                                             env);
            }

            /**
             * getter for artifact.
             */
            axis2_char_t* AXIS2_CALL
            adb_FaultyService_get_artifact(
                    adb_FaultyService_t* _FaultyService,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _FaultyService, NULL);
                  

                return _FaultyService->property_artifact;
             }

            /**
             * setter for artifact
             */
            axis2_status_t AXIS2_CALL
            adb_FaultyService_set_artifact(
                    adb_FaultyService_t* _FaultyService,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_artifact)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _FaultyService, AXIS2_FAILURE);
                
                if(_FaultyService->is_valid_artifact &&
                        arg_artifact == _FaultyService->property_artifact)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_FaultyService_reset_artifact(_FaultyService, env);

                
                if(NULL == arg_artifact)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _FaultyService->property_artifact = (axis2_char_t *)axutil_strdup(env, arg_artifact);
                        if(NULL == _FaultyService->property_artifact)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for artifact");
                            return AXIS2_FAILURE;
                        }
                        _FaultyService->is_valid_artifact = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for artifact
            */
           axis2_status_t AXIS2_CALL
           adb_FaultyService_reset_artifact(
                   adb_FaultyService_t* _FaultyService,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _FaultyService, AXIS2_FAILURE);
               

               
            
                
                if(_FaultyService->property_artifact != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _FaultyService->property_artifact);
                     _FaultyService->property_artifact = NULL;
                }
            
                
                
                _FaultyService->is_valid_artifact = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether artifact is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_FaultyService_is_artifact_nil(
                   adb_FaultyService_t* _FaultyService,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _FaultyService, AXIS2_TRUE);
               
               return !_FaultyService->is_valid_artifact;
           }

           /**
            * Set artifact to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_FaultyService_set_artifact_nil(
                   adb_FaultyService_t* _FaultyService,
                   const axutil_env_t *env)
           {
               return adb_FaultyService_reset_artifact(_FaultyService, env);
           }

           

            /**
             * Getter for fault by  Property Number 2
             */
            axis2_char_t* AXIS2_CALL
            adb_FaultyService_get_property2(
                adb_FaultyService_t* _FaultyService,
                const axutil_env_t *env)
            {
                return adb_FaultyService_get_fault(_FaultyService,
                                             env);
            }

            /**
             * getter for fault.
             */
            axis2_char_t* AXIS2_CALL
            adb_FaultyService_get_fault(
                    adb_FaultyService_t* _FaultyService,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _FaultyService, NULL);
                  

                return _FaultyService->property_fault;
             }

            /**
             * setter for fault
             */
            axis2_status_t AXIS2_CALL
            adb_FaultyService_set_fault(
                    adb_FaultyService_t* _FaultyService,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_fault)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _FaultyService, AXIS2_FAILURE);
                
                if(_FaultyService->is_valid_fault &&
                        arg_fault == _FaultyService->property_fault)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_FaultyService_reset_fault(_FaultyService, env);

                
                if(NULL == arg_fault)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _FaultyService->property_fault = (axis2_char_t *)axutil_strdup(env, arg_fault);
                        if(NULL == _FaultyService->property_fault)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for fault");
                            return AXIS2_FAILURE;
                        }
                        _FaultyService->is_valid_fault = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for fault
            */
           axis2_status_t AXIS2_CALL
           adb_FaultyService_reset_fault(
                   adb_FaultyService_t* _FaultyService,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _FaultyService, AXIS2_FAILURE);
               

               
            
                
                if(_FaultyService->property_fault != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _FaultyService->property_fault);
                     _FaultyService->property_fault = NULL;
                }
            
                
                
                _FaultyService->is_valid_fault = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether fault is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_FaultyService_is_fault_nil(
                   adb_FaultyService_t* _FaultyService,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _FaultyService, AXIS2_TRUE);
               
               return !_FaultyService->is_valid_fault;
           }

           /**
            * Set fault to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_FaultyService_set_fault_nil(
                   adb_FaultyService_t* _FaultyService,
                   const axutil_env_t *env)
           {
               return adb_FaultyService_reset_fault(_FaultyService, env);
           }

           

            /**
             * Getter for serviceName by  Property Number 3
             */
            axis2_char_t* AXIS2_CALL
            adb_FaultyService_get_property3(
                adb_FaultyService_t* _FaultyService,
                const axutil_env_t *env)
            {
                return adb_FaultyService_get_serviceName(_FaultyService,
                                             env);
            }

            /**
             * getter for serviceName.
             */
            axis2_char_t* AXIS2_CALL
            adb_FaultyService_get_serviceName(
                    adb_FaultyService_t* _FaultyService,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _FaultyService, NULL);
                  

                return _FaultyService->property_serviceName;
             }

            /**
             * setter for serviceName
             */
            axis2_status_t AXIS2_CALL
            adb_FaultyService_set_serviceName(
                    adb_FaultyService_t* _FaultyService,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_serviceName)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _FaultyService, AXIS2_FAILURE);
                
                if(_FaultyService->is_valid_serviceName &&
                        arg_serviceName == _FaultyService->property_serviceName)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_FaultyService_reset_serviceName(_FaultyService, env);

                
                if(NULL == arg_serviceName)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _FaultyService->property_serviceName = (axis2_char_t *)axutil_strdup(env, arg_serviceName);
                        if(NULL == _FaultyService->property_serviceName)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for serviceName");
                            return AXIS2_FAILURE;
                        }
                        _FaultyService->is_valid_serviceName = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for serviceName
            */
           axis2_status_t AXIS2_CALL
           adb_FaultyService_reset_serviceName(
                   adb_FaultyService_t* _FaultyService,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _FaultyService, AXIS2_FAILURE);
               

               
            
                
                if(_FaultyService->property_serviceName != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _FaultyService->property_serviceName);
                     _FaultyService->property_serviceName = NULL;
                }
            
                
                
                _FaultyService->is_valid_serviceName = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether serviceName is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_FaultyService_is_serviceName_nil(
                   adb_FaultyService_t* _FaultyService,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _FaultyService, AXIS2_TRUE);
               
               return !_FaultyService->is_valid_serviceName;
           }

           /**
            * Set serviceName to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_FaultyService_set_serviceName_nil(
                   adb_FaultyService_t* _FaultyService,
                   const axutil_env_t *env)
           {
               return adb_FaultyService_reset_serviceName(_FaultyService, env);
           }

           

            /**
             * Getter for serviceType by  Property Number 4
             */
            axis2_char_t* AXIS2_CALL
            adb_FaultyService_get_property4(
                adb_FaultyService_t* _FaultyService,
                const axutil_env_t *env)
            {
                return adb_FaultyService_get_serviceType(_FaultyService,
                                             env);
            }

            /**
             * getter for serviceType.
             */
            axis2_char_t* AXIS2_CALL
            adb_FaultyService_get_serviceType(
                    adb_FaultyService_t* _FaultyService,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _FaultyService, NULL);
                  

                return _FaultyService->property_serviceType;
             }

            /**
             * setter for serviceType
             */
            axis2_status_t AXIS2_CALL
            adb_FaultyService_set_serviceType(
                    adb_FaultyService_t* _FaultyService,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_serviceType)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _FaultyService, AXIS2_FAILURE);
                
                if(_FaultyService->is_valid_serviceType &&
                        arg_serviceType == _FaultyService->property_serviceType)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_FaultyService_reset_serviceType(_FaultyService, env);

                
                if(NULL == arg_serviceType)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _FaultyService->property_serviceType = (axis2_char_t *)axutil_strdup(env, arg_serviceType);
                        if(NULL == _FaultyService->property_serviceType)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for serviceType");
                            return AXIS2_FAILURE;
                        }
                        _FaultyService->is_valid_serviceType = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for serviceType
            */
           axis2_status_t AXIS2_CALL
           adb_FaultyService_reset_serviceType(
                   adb_FaultyService_t* _FaultyService,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _FaultyService, AXIS2_FAILURE);
               

               
            
                
                if(_FaultyService->property_serviceType != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _FaultyService->property_serviceType);
                     _FaultyService->property_serviceType = NULL;
                }
            
                
                
                _FaultyService->is_valid_serviceType = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether serviceType is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_FaultyService_is_serviceType_nil(
                   adb_FaultyService_t* _FaultyService,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _FaultyService, AXIS2_TRUE);
               
               return !_FaultyService->is_valid_serviceType;
           }

           /**
            * Set serviceType to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_FaultyService_set_serviceType_nil(
                   adb_FaultyService_t* _FaultyService,
                   const axutil_env_t *env)
           {
               return adb_FaultyService_reset_serviceType(_FaultyService, env);
           }

           

