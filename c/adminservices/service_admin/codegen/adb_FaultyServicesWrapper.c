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
         * adb_FaultyServicesWrapper.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_FaultyServicesWrapper.h"
        
                /*
                 * This type was generated from the piece of schema that had
                 * name = FaultyServicesWrapper
                 * Namespace URI = http://mgt.service.carbon.wso2.org/xsd
                 * Namespace Prefix = ns4
                 */
           


        struct adb_FaultyServicesWrapper
        {
            axis2_char_t *property_Type;

            axutil_array_list_t* property_faultyServices;

                
                axis2_bool_t is_valid_faultyServices;
            int property_numberOfFaultyServiceGroups;

                
                axis2_bool_t is_valid_numberOfFaultyServiceGroups;
            int property_numberOfPages;

                
                axis2_bool_t is_valid_numberOfPages;
            
        };


       /************************* Private Function prototypes ********************************/
        

                axis2_status_t AXIS2_CALL
                adb_FaultyServicesWrapper_set_numberOfFaultyServiceGroups_nil(
                        adb_FaultyServicesWrapper_t* _FaultyServicesWrapper,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_FaultyServicesWrapper_set_numberOfPages_nil(
                        adb_FaultyServicesWrapper_t* _FaultyServicesWrapper,
                        const axutil_env_t *env);
            


       /************************* Function Implmentations ********************************/
        adb_FaultyServicesWrapper_t* AXIS2_CALL
        adb_FaultyServicesWrapper_create(
            const axutil_env_t *env)
        {
            adb_FaultyServicesWrapper_t *_FaultyServicesWrapper = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _FaultyServicesWrapper = (adb_FaultyServicesWrapper_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_FaultyServicesWrapper_t));

            if(NULL == _FaultyServicesWrapper)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_FaultyServicesWrapper, 0, sizeof(adb_FaultyServicesWrapper_t));

            _FaultyServicesWrapper->property_Type = axutil_strdup(env, "adb_FaultyServicesWrapper");
            _FaultyServicesWrapper->property_faultyServices  = NULL;
                  _FaultyServicesWrapper->is_valid_faultyServices  = AXIS2_FALSE;
            _FaultyServicesWrapper->is_valid_numberOfFaultyServiceGroups  = AXIS2_FALSE;
            _FaultyServicesWrapper->is_valid_numberOfPages  = AXIS2_FALSE;
            

            return _FaultyServicesWrapper;
        }

        adb_FaultyServicesWrapper_t* AXIS2_CALL
        adb_FaultyServicesWrapper_create_with_values(
            const axutil_env_t *env,
                axutil_array_list_t* _faultyServices,
                int _numberOfFaultyServiceGroups,
                int _numberOfPages)
        {
            adb_FaultyServicesWrapper_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_FaultyServicesWrapper_create(env);

            
              status = adb_FaultyServicesWrapper_set_faultyServices(
                                     adb_obj,
                                     env,
                                     _faultyServices);
              if(status == AXIS2_FAILURE) {
                  adb_FaultyServicesWrapper_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_FaultyServicesWrapper_set_numberOfFaultyServiceGroups(
                                     adb_obj,
                                     env,
                                     _numberOfFaultyServiceGroups);
              if(status == AXIS2_FAILURE) {
                  adb_FaultyServicesWrapper_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_FaultyServicesWrapper_set_numberOfPages(
                                     adb_obj,
                                     env,
                                     _numberOfPages);
              if(status == AXIS2_FAILURE) {
                  adb_FaultyServicesWrapper_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axutil_array_list_t* AXIS2_CALL
                adb_FaultyServicesWrapper_free_popping_value(
                        adb_FaultyServicesWrapper_t* _FaultyServicesWrapper,
                        const axutil_env_t *env)
                {
                    axutil_array_list_t* value;

                    
                    
                    value = _FaultyServicesWrapper->property_faultyServices;

                    _FaultyServicesWrapper->property_faultyServices = (axutil_array_list_t*)NULL;
                    adb_FaultyServicesWrapper_free(_FaultyServicesWrapper, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_FaultyServicesWrapper_free(
                adb_FaultyServicesWrapper_t* _FaultyServicesWrapper,
                const axutil_env_t *env)
        {
            
            
            return axis2_extension_mapper_free(
                (adb_type_t*) _FaultyServicesWrapper,
                env,
                "adb_FaultyServicesWrapper");
            
        }

        axis2_status_t AXIS2_CALL
        adb_FaultyServicesWrapper_free_obj(
                adb_FaultyServicesWrapper_t* _FaultyServicesWrapper,
                const axutil_env_t *env)
        {
            
                int i = 0;
                int count = 0;
                void *element = NULL;
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _FaultyServicesWrapper, AXIS2_FAILURE);

            if (_FaultyServicesWrapper->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _FaultyServicesWrapper->property_Type);
            }

            adb_FaultyServicesWrapper_reset_faultyServices(_FaultyServicesWrapper, env);
            adb_FaultyServicesWrapper_reset_numberOfFaultyServiceGroups(_FaultyServicesWrapper, env);
            adb_FaultyServicesWrapper_reset_numberOfPages(_FaultyServicesWrapper, env);
            

            if(_FaultyServicesWrapper)
            {
                AXIS2_FREE(env->allocator, _FaultyServicesWrapper);
                _FaultyServicesWrapper = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_FaultyServicesWrapper_deserialize(
                adb_FaultyServicesWrapper_t* _FaultyServicesWrapper,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return axis2_extension_mapper_deserialize(
                (adb_type_t*) _FaultyServicesWrapper,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs,
                "adb_FaultyServicesWrapper");
            
        }

        axis2_status_t AXIS2_CALL
        adb_FaultyServicesWrapper_deserialize_obj(
                adb_FaultyServicesWrapper_t* _FaultyServicesWrapper,
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
            AXIS2_PARAM_CHECK(env->error, _FaultyServicesWrapper, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for FaultyServicesWrapper : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              
                      
                      first_node = axiom_node_get_first_child(parent, env);
                      
                    
                    /*
                     * building faultyServices array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building faultyServices element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "faultyServices", "http://mgt.service.carbon.wso2.org/xsd", NULL);
                                  
                               
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

                                  if (adb_FaultyService_is_particle() ||  
                                    (current_node && current_element && (axutil_qname_equals(element_qname, env, qname))))
                                  {
                                  
                                      if( current_node && current_element && (axutil_qname_equals(element_qname, env, qname)))
                                      {
                                          is_early_node_valid = AXIS2_TRUE;
                                      }
                                      
                                     
                                          element = (void*)axis2_extension_mapper_create_from_node(env, &current_node, "adb_FaultyService");
                                          
                                          status =  adb_FaultyService_deserialize((adb_FaultyService_t*)element, env,
                                                                                 &current_node, &is_early_node_valid, AXIS2_FALSE);
                                          
                                          if(AXIS2_FAILURE ==  status)
                                          {
                                              AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building element faultyServices ");
                                          }
                                          else
                                          {
                                            axutil_array_list_add_at(arr_list, env, i, element);
                                          }
                                        
                                     if(AXIS2_FAILURE ==  status)
                                     {
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for faultyServices ");
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
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "faultyServices (@minOccurs = '0') only have %d elements", i);
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
                                    status = adb_FaultyServicesWrapper_set_faultyServices(_FaultyServicesWrapper, env,
                                                                   arr_list);
                               }

                             
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 

                     
                     /*
                      * building numberOfFaultyServiceGroups element
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
                                 
                                 element_qname = axutil_qname_create(env, "numberOfFaultyServiceGroups", "http://mgt.service.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_FaultyServicesWrapper_set_numberOfFaultyServiceGroups(_FaultyServicesWrapper, env,
                                                                   atoi(text_value));
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element numberOfFaultyServiceGroups");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for numberOfFaultyServiceGroups ");
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
                      * building numberOfPages element
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
                                 
                                 element_qname = axutil_qname_create(env, "numberOfPages", "http://mgt.service.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_FaultyServicesWrapper_set_numberOfPages(_FaultyServicesWrapper, env,
                                                                   atoi(text_value));
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element numberOfPages");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for numberOfPages ");
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
          adb_FaultyServicesWrapper_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_FaultyServicesWrapper_declare_parent_namespaces(
                    adb_FaultyServicesWrapper_t* _FaultyServicesWrapper,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_FaultyServicesWrapper_serialize(
                adb_FaultyServicesWrapper_t* _FaultyServicesWrapper,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
            if (_FaultyServicesWrapper == NULL)
            {
                return adb_FaultyServicesWrapper_serialize_obj(
                    _FaultyServicesWrapper, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            }
            else
            {
                return axis2_extension_mapper_serialize(
                    (adb_type_t*) _FaultyServicesWrapper, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index, "adb_FaultyServicesWrapper");
            }
            
        }

        axiom_node_t* AXIS2_CALL
        adb_FaultyServicesWrapper_serialize_obj(
                adb_FaultyServicesWrapper_t* _FaultyServicesWrapper,
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
                    
                    axis2_char_t text_value_3[ADB_DEFAULT_DIGIT_LIMIT];
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _FaultyServicesWrapper, NULL);
            
            
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
              type_attrib = axutil_strcat(env, " ", xsi_prefix, ":type=\"FaultyServicesWrapper\"", NULL);
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
            xsi_type_attri = axiom_attribute_create (env, "type", "FaultyServicesWrapper", xsi_ns);
            
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
                      

                   if (!_FaultyServicesWrapper->is_valid_faultyServices)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("faultyServices"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("faultyServices")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing faultyServices array
                      */
                     if (_FaultyServicesWrapper->property_faultyServices != NULL)
                     {
                        

                            sprintf(start_input_str, "<%s%sfaultyServices",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%sfaultyServices>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_FaultyServicesWrapper->property_faultyServices, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_FaultyServicesWrapper->property_faultyServices, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing faultyServices element
                      */

                    
                     
                            if(!adb_FaultyService_is_particle())
                            {
                                axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                            }
                            adb_FaultyService_serialize((adb_FaultyService_t*)element, 
                                                                                 env, current_node, parent_element,
                                                                                 adb_FaultyService_is_particle() || AXIS2_FALSE, namespaces, next_ns_index);
                            
                            if(!adb_FaultyService_is_particle())
                            {
                                axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                            }
                            
                         }
                     }
                   
                     
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
                      

                   if (!_FaultyServicesWrapper->is_valid_numberOfFaultyServiceGroups)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("numberOfFaultyServiceGroups"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("numberOfFaultyServiceGroups")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing numberOfFaultyServiceGroups element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%snumberOfFaultyServiceGroups>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%snumberOfFaultyServiceGroups>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                               sprintf (text_value_2, AXIS2_PRINTF_INT32_FORMAT_SPECIFIER, _FaultyServicesWrapper->property_numberOfFaultyServiceGroups);
                             
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_2, axutil_strlen(text_value_2));
                           
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
                      

                   if (!_FaultyServicesWrapper->is_valid_numberOfPages)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("numberOfPages"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("numberOfPages")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing numberOfPages element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%snumberOfPages>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%snumberOfPages>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                               sprintf (text_value_3, AXIS2_PRINTF_INT32_FORMAT_SPECIFIER, _FaultyServicesWrapper->property_numberOfPages);
                             
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_3, axutil_strlen(text_value_3));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 

            return parent;
        }


        

            /**
             * Getter for faultyServices by  Property Number 1
             */
            axutil_array_list_t* AXIS2_CALL
            adb_FaultyServicesWrapper_get_property1(
                adb_FaultyServicesWrapper_t* _FaultyServicesWrapper,
                const axutil_env_t *env)
            {
                return adb_FaultyServicesWrapper_get_faultyServices(_FaultyServicesWrapper,
                                             env);
            }

            /**
             * getter for faultyServices.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_FaultyServicesWrapper_get_faultyServices(
                    adb_FaultyServicesWrapper_t* _FaultyServicesWrapper,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _FaultyServicesWrapper, NULL);
                  

                return _FaultyServicesWrapper->property_faultyServices;
             }

            /**
             * setter for faultyServices
             */
            axis2_status_t AXIS2_CALL
            adb_FaultyServicesWrapper_set_faultyServices(
                    adb_FaultyServicesWrapper_t* _FaultyServicesWrapper,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_faultyServices)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _FaultyServicesWrapper, AXIS2_FAILURE);
                
                if(_FaultyServicesWrapper->is_valid_faultyServices &&
                        arg_faultyServices == _FaultyServicesWrapper->property_faultyServices)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_faultyServices, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "faultyServices has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_faultyServices, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_FaultyServicesWrapper_reset_faultyServices(_FaultyServicesWrapper, env);

                
                if(NULL == arg_faultyServices)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _FaultyServicesWrapper->property_faultyServices = arg_faultyServices;
                        if(non_nil_exists)
                        {
                            _FaultyServicesWrapper->is_valid_faultyServices = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of faultyServices.
             */
            adb_FaultyService_t* AXIS2_CALL
            adb_FaultyServicesWrapper_get_faultyServices_at(
                    adb_FaultyServicesWrapper_t* _FaultyServicesWrapper,
                    const axutil_env_t *env, int i)
            {
                adb_FaultyService_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _FaultyServicesWrapper, NULL);
                  

                if(_FaultyServicesWrapper->property_faultyServices == NULL)
                {
                    return (adb_FaultyService_t*)0;
                }
                ret_val = (adb_FaultyService_t*)axutil_array_list_get(_FaultyServicesWrapper->property_faultyServices, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of faultyServices.
             */
            axis2_status_t AXIS2_CALL
            adb_FaultyServicesWrapper_set_faultyServices_at(
                    adb_FaultyServicesWrapper_t* _FaultyServicesWrapper,
                    const axutil_env_t *env, int i,
                    adb_FaultyService_t* arg_faultyServices)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _FaultyServicesWrapper, AXIS2_FAILURE);
                
                if( _FaultyServicesWrapper->is_valid_faultyServices &&
                    _FaultyServicesWrapper->property_faultyServices &&
                
                    arg_faultyServices == (adb_FaultyService_t*)axutil_array_list_get(_FaultyServicesWrapper->property_faultyServices, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_faultyServices)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_FaultyServicesWrapper->property_faultyServices != NULL)
                        {
                            size = axutil_array_list_size(_FaultyServicesWrapper->property_faultyServices, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_FaultyServicesWrapper->property_faultyServices, env, i))
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
                  

                if(_FaultyServicesWrapper->property_faultyServices == NULL)
                {
                    _FaultyServicesWrapper->property_faultyServices = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_FaultyServicesWrapper->property_faultyServices, env, i);
                if(NULL != element)
                {
                  
                  
                  adb_FaultyService_free((adb_FaultyService_t*)element, env);
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _FaultyServicesWrapper->is_valid_faultyServices = AXIS2_FALSE;
                        axutil_array_list_set(_FaultyServicesWrapper->property_faultyServices , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_FaultyServicesWrapper->property_faultyServices , env, i, arg_faultyServices);
                  _FaultyServicesWrapper->is_valid_faultyServices = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to faultyServices.
             */
            axis2_status_t AXIS2_CALL
            adb_FaultyServicesWrapper_add_faultyServices(
                    adb_FaultyServicesWrapper_t* _FaultyServicesWrapper,
                    const axutil_env_t *env,
                    adb_FaultyService_t* arg_faultyServices)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _FaultyServicesWrapper, AXIS2_FAILURE);

                
                    if(NULL == arg_faultyServices)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_FaultyServicesWrapper->property_faultyServices == NULL)
                {
                    _FaultyServicesWrapper->property_faultyServices = axutil_array_list_create(env, 10);
                }
                if(_FaultyServicesWrapper->property_faultyServices == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for faultyServices");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_FaultyServicesWrapper->property_faultyServices , env, arg_faultyServices);
                  _FaultyServicesWrapper->is_valid_faultyServices = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the faultyServices array.
             */
            int AXIS2_CALL
            adb_FaultyServicesWrapper_sizeof_faultyServices(
                    adb_FaultyServicesWrapper_t* _FaultyServicesWrapper,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _FaultyServicesWrapper, -1);
                if(_FaultyServicesWrapper->property_faultyServices == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_FaultyServicesWrapper->property_faultyServices, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_FaultyServicesWrapper_remove_faultyServices_at(
                    adb_FaultyServicesWrapper_t* _FaultyServicesWrapper,
                    const axutil_env_t *env, int i)
            {
                return adb_FaultyServicesWrapper_set_faultyServices_nil_at(_FaultyServicesWrapper, env, i);
            }

            

           /**
            * resetter for faultyServices
            */
           axis2_status_t AXIS2_CALL
           adb_FaultyServicesWrapper_reset_faultyServices(
                   adb_FaultyServicesWrapper_t* _FaultyServicesWrapper,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _FaultyServicesWrapper, AXIS2_FAILURE);
               

               
                  if (_FaultyServicesWrapper->property_faultyServices != NULL)
                  {
                      count = axutil_array_list_size(_FaultyServicesWrapper->property_faultyServices, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_FaultyServicesWrapper->property_faultyServices, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   adb_FaultyService_free((adb_FaultyService_t*)element, env);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_FaultyServicesWrapper->property_faultyServices, env);
                  }
                _FaultyServicesWrapper->is_valid_faultyServices = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether faultyServices is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_FaultyServicesWrapper_is_faultyServices_nil(
                   adb_FaultyServicesWrapper_t* _FaultyServicesWrapper,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _FaultyServicesWrapper, AXIS2_TRUE);
               
               return !_FaultyServicesWrapper->is_valid_faultyServices;
           }

           /**
            * Set faultyServices to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_FaultyServicesWrapper_set_faultyServices_nil(
                   adb_FaultyServicesWrapper_t* _FaultyServicesWrapper,
                   const axutil_env_t *env)
           {
               return adb_FaultyServicesWrapper_reset_faultyServices(_FaultyServicesWrapper, env);
           }

           
           /**
            * Check whether faultyServices is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_FaultyServicesWrapper_is_faultyServices_nil_at(
                   adb_FaultyServicesWrapper_t* _FaultyServicesWrapper,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _FaultyServicesWrapper, AXIS2_TRUE);
               
               return (_FaultyServicesWrapper->is_valid_faultyServices == AXIS2_FALSE ||
                        NULL == _FaultyServicesWrapper->property_faultyServices || 
                        NULL == axutil_array_list_get(_FaultyServicesWrapper->property_faultyServices, env, i));
           }

           /**
            * Set faultyServices to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_FaultyServicesWrapper_set_faultyServices_nil_at(
                   adb_FaultyServicesWrapper_t* _FaultyServicesWrapper,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _FaultyServicesWrapper, AXIS2_FAILURE);

                if(_FaultyServicesWrapper->property_faultyServices == NULL ||
                            _FaultyServicesWrapper->is_valid_faultyServices == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_FaultyServicesWrapper->property_faultyServices, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_FaultyServicesWrapper->property_faultyServices, env, i))
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
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of faultyServices is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_FaultyServicesWrapper->property_faultyServices == NULL)
                {
                    _FaultyServicesWrapper->is_valid_faultyServices = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_FaultyServicesWrapper->property_faultyServices, env, i);
                if(NULL != element)
                {
                  
                  
                  adb_FaultyService_free((adb_FaultyService_t*)element, env);
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _FaultyServicesWrapper->is_valid_faultyServices = AXIS2_FALSE;
                        axutil_array_list_set(_FaultyServicesWrapper->property_faultyServices , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_FaultyServicesWrapper->property_faultyServices , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

            /**
             * Getter for numberOfFaultyServiceGroups by  Property Number 2
             */
            int AXIS2_CALL
            adb_FaultyServicesWrapper_get_property2(
                adb_FaultyServicesWrapper_t* _FaultyServicesWrapper,
                const axutil_env_t *env)
            {
                return adb_FaultyServicesWrapper_get_numberOfFaultyServiceGroups(_FaultyServicesWrapper,
                                             env);
            }

            /**
             * getter for numberOfFaultyServiceGroups.
             */
            int AXIS2_CALL
            adb_FaultyServicesWrapper_get_numberOfFaultyServiceGroups(
                    adb_FaultyServicesWrapper_t* _FaultyServicesWrapper,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (int)0);
                    AXIS2_PARAM_CHECK(env->error, _FaultyServicesWrapper, (int)0);
                  

                return _FaultyServicesWrapper->property_numberOfFaultyServiceGroups;
             }

            /**
             * setter for numberOfFaultyServiceGroups
             */
            axis2_status_t AXIS2_CALL
            adb_FaultyServicesWrapper_set_numberOfFaultyServiceGroups(
                    adb_FaultyServicesWrapper_t* _FaultyServicesWrapper,
                    const axutil_env_t *env,
                    const int  arg_numberOfFaultyServiceGroups)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _FaultyServicesWrapper, AXIS2_FAILURE);
                
                if(_FaultyServicesWrapper->is_valid_numberOfFaultyServiceGroups &&
                        arg_numberOfFaultyServiceGroups == _FaultyServicesWrapper->property_numberOfFaultyServiceGroups)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_FaultyServicesWrapper_reset_numberOfFaultyServiceGroups(_FaultyServicesWrapper, env);

                _FaultyServicesWrapper->property_numberOfFaultyServiceGroups = arg_numberOfFaultyServiceGroups;
                        _FaultyServicesWrapper->is_valid_numberOfFaultyServiceGroups = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for numberOfFaultyServiceGroups
            */
           axis2_status_t AXIS2_CALL
           adb_FaultyServicesWrapper_reset_numberOfFaultyServiceGroups(
                   adb_FaultyServicesWrapper_t* _FaultyServicesWrapper,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _FaultyServicesWrapper, AXIS2_FAILURE);
               

               _FaultyServicesWrapper->is_valid_numberOfFaultyServiceGroups = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether numberOfFaultyServiceGroups is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_FaultyServicesWrapper_is_numberOfFaultyServiceGroups_nil(
                   adb_FaultyServicesWrapper_t* _FaultyServicesWrapper,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _FaultyServicesWrapper, AXIS2_TRUE);
               
               return !_FaultyServicesWrapper->is_valid_numberOfFaultyServiceGroups;
           }

           /**
            * Set numberOfFaultyServiceGroups to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_FaultyServicesWrapper_set_numberOfFaultyServiceGroups_nil(
                   adb_FaultyServicesWrapper_t* _FaultyServicesWrapper,
                   const axutil_env_t *env)
           {
               return adb_FaultyServicesWrapper_reset_numberOfFaultyServiceGroups(_FaultyServicesWrapper, env);
           }

           

            /**
             * Getter for numberOfPages by  Property Number 3
             */
            int AXIS2_CALL
            adb_FaultyServicesWrapper_get_property3(
                adb_FaultyServicesWrapper_t* _FaultyServicesWrapper,
                const axutil_env_t *env)
            {
                return adb_FaultyServicesWrapper_get_numberOfPages(_FaultyServicesWrapper,
                                             env);
            }

            /**
             * getter for numberOfPages.
             */
            int AXIS2_CALL
            adb_FaultyServicesWrapper_get_numberOfPages(
                    adb_FaultyServicesWrapper_t* _FaultyServicesWrapper,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (int)0);
                    AXIS2_PARAM_CHECK(env->error, _FaultyServicesWrapper, (int)0);
                  

                return _FaultyServicesWrapper->property_numberOfPages;
             }

            /**
             * setter for numberOfPages
             */
            axis2_status_t AXIS2_CALL
            adb_FaultyServicesWrapper_set_numberOfPages(
                    adb_FaultyServicesWrapper_t* _FaultyServicesWrapper,
                    const axutil_env_t *env,
                    const int  arg_numberOfPages)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _FaultyServicesWrapper, AXIS2_FAILURE);
                
                if(_FaultyServicesWrapper->is_valid_numberOfPages &&
                        arg_numberOfPages == _FaultyServicesWrapper->property_numberOfPages)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_FaultyServicesWrapper_reset_numberOfPages(_FaultyServicesWrapper, env);

                _FaultyServicesWrapper->property_numberOfPages = arg_numberOfPages;
                        _FaultyServicesWrapper->is_valid_numberOfPages = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for numberOfPages
            */
           axis2_status_t AXIS2_CALL
           adb_FaultyServicesWrapper_reset_numberOfPages(
                   adb_FaultyServicesWrapper_t* _FaultyServicesWrapper,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _FaultyServicesWrapper, AXIS2_FAILURE);
               

               _FaultyServicesWrapper->is_valid_numberOfPages = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether numberOfPages is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_FaultyServicesWrapper_is_numberOfPages_nil(
                   adb_FaultyServicesWrapper_t* _FaultyServicesWrapper,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _FaultyServicesWrapper, AXIS2_TRUE);
               
               return !_FaultyServicesWrapper->is_valid_numberOfPages;
           }

           /**
            * Set numberOfPages to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_FaultyServicesWrapper_set_numberOfPages_nil(
                   adb_FaultyServicesWrapper_t* _FaultyServicesWrapper,
                   const axutil_env_t *env)
           {
               return adb_FaultyServicesWrapper_reset_numberOfPages(_FaultyServicesWrapper, env);
           }

           

