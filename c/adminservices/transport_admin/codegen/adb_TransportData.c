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
         * adb_TransportData.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_TransportData.h"
        
                /*
                 * This type was generated from the piece of schema that had
                 * name = TransportData
                 * Namespace URI = http://mgt.transport.carbon.wso2.org/xsd
                 * Namespace Prefix = ns3
                 */
           


        struct adb_TransportData
        {
            axis2_char_t *property_Type;

            adb_TransportDetails_t* property_details;

                
                axis2_bool_t is_valid_details;
            adb_TransportSummary_t* property_summary;

                
                axis2_bool_t is_valid_summary;
            
        };


       /************************* Private Function prototypes ********************************/
        


       /************************* Function Implmentations ********************************/
        adb_TransportData_t* AXIS2_CALL
        adb_TransportData_create(
            const axutil_env_t *env)
        {
            adb_TransportData_t *_TransportData = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _TransportData = (adb_TransportData_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_TransportData_t));

            if(NULL == _TransportData)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_TransportData, 0, sizeof(adb_TransportData_t));

            _TransportData->property_Type = axutil_strdup(env, "adb_TransportData");
            _TransportData->property_details  = NULL;
                  _TransportData->is_valid_details  = AXIS2_FALSE;
            _TransportData->property_summary  = NULL;
                  _TransportData->is_valid_summary  = AXIS2_FALSE;
            

            return _TransportData;
        }

        adb_TransportData_t* AXIS2_CALL
        adb_TransportData_create_with_values(
            const axutil_env_t *env,
                adb_TransportDetails_t* _details,
                adb_TransportSummary_t* _summary)
        {
            adb_TransportData_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_TransportData_create(env);

            
              status = adb_TransportData_set_details(
                                     adb_obj,
                                     env,
                                     _details);
              if(status == AXIS2_FAILURE) {
                  adb_TransportData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_TransportData_set_summary(
                                     adb_obj,
                                     env,
                                     _summary);
              if(status == AXIS2_FAILURE) {
                  adb_TransportData_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        adb_TransportDetails_t* AXIS2_CALL
                adb_TransportData_free_popping_value(
                        adb_TransportData_t* _TransportData,
                        const axutil_env_t *env)
                {
                    adb_TransportDetails_t* value;

                    
                    
                    value = _TransportData->property_details;

                    _TransportData->property_details = (adb_TransportDetails_t*)NULL;
                    adb_TransportData_free(_TransportData, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_TransportData_free(
                adb_TransportData_t* _TransportData,
                const axutil_env_t *env)
        {
            
            
            return axis2_extension_mapper_free(
                (adb_type_t*) _TransportData,
                env,
                "adb_TransportData");
            
        }

        axis2_status_t AXIS2_CALL
        adb_TransportData_free_obj(
                adb_TransportData_t* _TransportData,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _TransportData, AXIS2_FAILURE);

            if (_TransportData->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _TransportData->property_Type);
            }

            adb_TransportData_reset_details(_TransportData, env);
            adb_TransportData_reset_summary(_TransportData, env);
            

            if(_TransportData)
            {
                AXIS2_FREE(env->allocator, _TransportData);
                _TransportData = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_TransportData_deserialize(
                adb_TransportData_t* _TransportData,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return axis2_extension_mapper_deserialize(
                (adb_type_t*) _TransportData,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs,
                "adb_TransportData");
            
        }

        axis2_status_t AXIS2_CALL
        adb_TransportData_deserialize_obj(
                adb_TransportData_t* _TransportData,
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
            AXIS2_PARAM_CHECK(env->error, _TransportData, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for TransportData : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              
                      
                      first_node = axiom_node_get_first_child(parent, env);
                      
                    

                     
                     /*
                      * building details element
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
                                   
                                 element_qname = axutil_qname_create(env, "details", "http://mgt.transport.carbon.wso2.org/xsd", NULL);
                                 

                           if (adb_TransportDetails_is_particle() ||  
                                (current_node   && current_element && (axutil_qname_equals(element_qname, env, qname))))
                           {
                              if( current_node   && current_element && (axutil_qname_equals(element_qname, env, qname)))
                              {
                                is_early_node_valid = AXIS2_TRUE;
                              }
                              
                                 
                                      element = (void*)axis2_extension_mapper_create_from_node(env, &current_node, "adb_TransportDetails");

                                      status =  adb_TransportDetails_deserialize((adb_TransportDetails_t*)element,
                                                                            env, &current_node, &is_early_node_valid, AXIS2_FALSE);
                                      if(AXIS2_FAILURE == status)
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building adb object for element details");
                                      }
                                      else
                                      {
                                          status = adb_TransportData_set_details(_TransportData, env,
                                                                   (adb_TransportDetails_t*)element);
                                      }
                                    
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for details ");
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
                      * building summary element
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
                                 
                                 element_qname = axutil_qname_create(env, "summary", "http://mgt.transport.carbon.wso2.org/xsd", NULL);
                                 

                           if (adb_TransportSummary_is_particle() ||  
                                (current_node   && current_element && (axutil_qname_equals(element_qname, env, qname))))
                           {
                              if( current_node   && current_element && (axutil_qname_equals(element_qname, env, qname)))
                              {
                                is_early_node_valid = AXIS2_TRUE;
                              }
                              
                                 
                                      element = (void*)axis2_extension_mapper_create_from_node(env, &current_node, "adb_TransportSummary");

                                      status =  adb_TransportSummary_deserialize((adb_TransportSummary_t*)element,
                                                                            env, &current_node, &is_early_node_valid, AXIS2_FALSE);
                                      if(AXIS2_FAILURE == status)
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building adb object for element summary");
                                      }
                                      else
                                      {
                                          status = adb_TransportData_set_summary(_TransportData, env,
                                                                   (adb_TransportSummary_t*)element);
                                      }
                                    
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for summary ");
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
          adb_TransportData_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_TransportData_declare_parent_namespaces(
                    adb_TransportData_t* _TransportData,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_TransportData_serialize(
                adb_TransportData_t* _TransportData,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
            if (_TransportData == NULL)
            {
                return adb_TransportData_serialize_obj(
                    _TransportData, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            }
            else
            {
                return axis2_extension_mapper_serialize(
                    (adb_type_t*) _TransportData, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index, "adb_TransportData");
            }
            
        }

        axiom_node_t* AXIS2_CALL
        adb_TransportData_serialize_obj(
                adb_TransportData_t* _TransportData,
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
            
                    axis2_char_t text_value_1[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t text_value_2[ADB_DEFAULT_DIGIT_LIMIT];
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _TransportData, NULL);
            
            
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
              type_attrib = axutil_strcat(env, " ", xsi_prefix, ":type=\"TransportData\"", NULL);
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
                                 "http://mgt.transport.carbon.wso2.org/xsd",
                                 xsi_prefix);
            xsi_type_attri = axiom_attribute_create (env, "type", "TransportData", xsi_ns);
            
            axiom_element_add_attribute (parent_element, env, xsi_type_attri, parent);
        
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://mgt.transport.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://mgt.transport.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://mgt.transport.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_TransportData->is_valid_details)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("details"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("details")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing details element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sdetails",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sdetails>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                     
                            if(!adb_TransportDetails_is_particle())
                            {
                                axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                            }
                            adb_TransportDetails_serialize(_TransportData->property_details, 
                                                                                 env, current_node, parent_element,
                                                                                 adb_TransportDetails_is_particle() || AXIS2_FALSE, namespaces, next_ns_index);
                            
                            if(!adb_TransportDetails_is_particle())
                            {
                                axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                            }
                            
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://mgt.transport.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://mgt.transport.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://mgt.transport.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_TransportData->is_valid_summary)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("summary"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("summary")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing summary element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%ssummary",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%ssummary>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                     
                            if(!adb_TransportSummary_is_particle())
                            {
                                axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                            }
                            adb_TransportSummary_serialize(_TransportData->property_summary, 
                                                                                 env, current_node, parent_element,
                                                                                 adb_TransportSummary_is_particle() || AXIS2_FALSE, namespaces, next_ns_index);
                            
                            if(!adb_TransportSummary_is_particle())
                            {
                                axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                            }
                            
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 

            return parent;
        }


        

            /**
             * Getter for details by  Property Number 1
             */
            adb_TransportDetails_t* AXIS2_CALL
            adb_TransportData_get_property1(
                adb_TransportData_t* _TransportData,
                const axutil_env_t *env)
            {
                return adb_TransportData_get_details(_TransportData,
                                             env);
            }

            /**
             * getter for details.
             */
            adb_TransportDetails_t* AXIS2_CALL
            adb_TransportData_get_details(
                    adb_TransportData_t* _TransportData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _TransportData, NULL);
                  

                return _TransportData->property_details;
             }

            /**
             * setter for details
             */
            axis2_status_t AXIS2_CALL
            adb_TransportData_set_details(
                    adb_TransportData_t* _TransportData,
                    const axutil_env_t *env,
                    adb_TransportDetails_t*  arg_details)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _TransportData, AXIS2_FAILURE);
                
                if(_TransportData->is_valid_details &&
                        arg_details == _TransportData->property_details)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_TransportData_reset_details(_TransportData, env);

                
                if(NULL == arg_details)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _TransportData->property_details = arg_details;
                        _TransportData->is_valid_details = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for details
            */
           axis2_status_t AXIS2_CALL
           adb_TransportData_reset_details(
                   adb_TransportData_t* _TransportData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _TransportData, AXIS2_FAILURE);
               

               
            
                
                if(_TransportData->property_details != NULL)
                {
                   
                   adb_TransportDetails_free(_TransportData->property_details, env);
                     _TransportData->property_details = NULL;
                }
            
                
                
                _TransportData->is_valid_details = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether details is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_TransportData_is_details_nil(
                   adb_TransportData_t* _TransportData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _TransportData, AXIS2_TRUE);
               
               return !_TransportData->is_valid_details;
           }

           /**
            * Set details to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_TransportData_set_details_nil(
                   adb_TransportData_t* _TransportData,
                   const axutil_env_t *env)
           {
               return adb_TransportData_reset_details(_TransportData, env);
           }

           

            /**
             * Getter for summary by  Property Number 2
             */
            adb_TransportSummary_t* AXIS2_CALL
            adb_TransportData_get_property2(
                adb_TransportData_t* _TransportData,
                const axutil_env_t *env)
            {
                return adb_TransportData_get_summary(_TransportData,
                                             env);
            }

            /**
             * getter for summary.
             */
            adb_TransportSummary_t* AXIS2_CALL
            adb_TransportData_get_summary(
                    adb_TransportData_t* _TransportData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _TransportData, NULL);
                  

                return _TransportData->property_summary;
             }

            /**
             * setter for summary
             */
            axis2_status_t AXIS2_CALL
            adb_TransportData_set_summary(
                    adb_TransportData_t* _TransportData,
                    const axutil_env_t *env,
                    adb_TransportSummary_t*  arg_summary)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _TransportData, AXIS2_FAILURE);
                
                if(_TransportData->is_valid_summary &&
                        arg_summary == _TransportData->property_summary)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_TransportData_reset_summary(_TransportData, env);

                
                if(NULL == arg_summary)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _TransportData->property_summary = arg_summary;
                        _TransportData->is_valid_summary = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for summary
            */
           axis2_status_t AXIS2_CALL
           adb_TransportData_reset_summary(
                   adb_TransportData_t* _TransportData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _TransportData, AXIS2_FAILURE);
               

               
            
                
                if(_TransportData->property_summary != NULL)
                {
                   
                   adb_TransportSummary_free(_TransportData->property_summary, env);
                     _TransportData->property_summary = NULL;
                }
            
                
                
                _TransportData->is_valid_summary = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether summary is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_TransportData_is_summary_nil(
                   adb_TransportData_t* _TransportData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _TransportData, AXIS2_TRUE);
               
               return !_TransportData->is_valid_summary;
           }

           /**
            * Set summary to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_TransportData_set_summary_nil(
                   adb_TransportData_t* _TransportData,
                   const axutil_env_t *env)
           {
               return adb_TransportData_reset_summary(_TransportData, env);
           }

           

