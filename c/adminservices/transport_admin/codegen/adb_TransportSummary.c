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
         * adb_TransportSummary.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_TransportSummary.h"
        
                /*
                 * This type was generated from the piece of schema that had
                 * name = TransportSummary
                 * Namespace URI = http://util.transports.core.carbon.wso2.org/xsd
                 * Namespace Prefix = ns1
                 */
           


        struct adb_TransportSummary
        {
            axis2_char_t *property_Type;

            axis2_bool_t property_listenerActive;

                
                axis2_bool_t is_valid_listenerActive;
            axis2_bool_t property_nonRemovable;

                
                axis2_bool_t is_valid_nonRemovable;
            axis2_char_t* property_protocol;

                
                axis2_bool_t is_valid_protocol;
            axis2_bool_t property_senderActive;

                
                axis2_bool_t is_valid_senderActive;
            
        };


       /************************* Private Function prototypes ********************************/
        

                axis2_status_t AXIS2_CALL
                adb_TransportSummary_set_listenerActive_nil(
                        adb_TransportSummary_t* _TransportSummary,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_TransportSummary_set_nonRemovable_nil(
                        adb_TransportSummary_t* _TransportSummary,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_TransportSummary_set_senderActive_nil(
                        adb_TransportSummary_t* _TransportSummary,
                        const axutil_env_t *env);
            


       /************************* Function Implmentations ********************************/
        adb_TransportSummary_t* AXIS2_CALL
        adb_TransportSummary_create(
            const axutil_env_t *env)
        {
            adb_TransportSummary_t *_TransportSummary = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _TransportSummary = (adb_TransportSummary_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_TransportSummary_t));

            if(NULL == _TransportSummary)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_TransportSummary, 0, sizeof(adb_TransportSummary_t));

            _TransportSummary->property_Type = axutil_strdup(env, "adb_TransportSummary");
            _TransportSummary->is_valid_listenerActive  = AXIS2_FALSE;
            _TransportSummary->is_valid_nonRemovable  = AXIS2_FALSE;
            _TransportSummary->property_protocol  = NULL;
                  _TransportSummary->is_valid_protocol  = AXIS2_FALSE;
            _TransportSummary->is_valid_senderActive  = AXIS2_FALSE;
            

            return _TransportSummary;
        }

        adb_TransportSummary_t* AXIS2_CALL
        adb_TransportSummary_create_with_values(
            const axutil_env_t *env,
                axis2_bool_t _listenerActive,
                axis2_bool_t _nonRemovable,
                axis2_char_t* _protocol,
                axis2_bool_t _senderActive)
        {
            adb_TransportSummary_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_TransportSummary_create(env);

            
              status = adb_TransportSummary_set_listenerActive(
                                     adb_obj,
                                     env,
                                     _listenerActive);
              if(status == AXIS2_FAILURE) {
                  adb_TransportSummary_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_TransportSummary_set_nonRemovable(
                                     adb_obj,
                                     env,
                                     _nonRemovable);
              if(status == AXIS2_FAILURE) {
                  adb_TransportSummary_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_TransportSummary_set_protocol(
                                     adb_obj,
                                     env,
                                     _protocol);
              if(status == AXIS2_FAILURE) {
                  adb_TransportSummary_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_TransportSummary_set_senderActive(
                                     adb_obj,
                                     env,
                                     _senderActive);
              if(status == AXIS2_FAILURE) {
                  adb_TransportSummary_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_bool_t AXIS2_CALL
                adb_TransportSummary_free_popping_value(
                        adb_TransportSummary_t* _TransportSummary,
                        const axutil_env_t *env)
                {
                    axis2_bool_t value;

                    
                    
                    value = _TransportSummary->property_listenerActive;

                    adb_TransportSummary_free(_TransportSummary, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_TransportSummary_free(
                adb_TransportSummary_t* _TransportSummary,
                const axutil_env_t *env)
        {
            
            
            return axis2_extension_mapper_free(
                (adb_type_t*) _TransportSummary,
                env,
                "adb_TransportSummary");
            
        }

        axis2_status_t AXIS2_CALL
        adb_TransportSummary_free_obj(
                adb_TransportSummary_t* _TransportSummary,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _TransportSummary, AXIS2_FAILURE);

            if (_TransportSummary->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _TransportSummary->property_Type);
            }

            adb_TransportSummary_reset_listenerActive(_TransportSummary, env);
            adb_TransportSummary_reset_nonRemovable(_TransportSummary, env);
            adb_TransportSummary_reset_protocol(_TransportSummary, env);
            adb_TransportSummary_reset_senderActive(_TransportSummary, env);
            

            if(_TransportSummary)
            {
                AXIS2_FREE(env->allocator, _TransportSummary);
                _TransportSummary = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_TransportSummary_deserialize(
                adb_TransportSummary_t* _TransportSummary,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return axis2_extension_mapper_deserialize(
                (adb_type_t*) _TransportSummary,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs,
                "adb_TransportSummary");
            
        }

        axis2_status_t AXIS2_CALL
        adb_TransportSummary_deserialize_obj(
                adb_TransportSummary_t* _TransportSummary,
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
            AXIS2_PARAM_CHECK(env->error, _TransportSummary, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for TransportSummary : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              
                      
                      first_node = axiom_node_get_first_child(parent, env);
                      
                    

                     
                     /*
                      * building listenerActive element
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
                                   
                                 element_qname = axutil_qname_create(env, "listenerActive", "http://util.transports.core.carbon.wso2.org/xsd", NULL);
                                 

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
                                            if (!axutil_strcasecmp(text_value , "true"))
                                            {
                                                status = adb_TransportSummary_set_listenerActive(_TransportSummary, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_TransportSummary_set_listenerActive(_TransportSummary, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element listenerActive");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for listenerActive ");
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
                      * building nonRemovable element
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
                                 
                                 element_qname = axutil_qname_create(env, "nonRemovable", "http://util.transports.core.carbon.wso2.org/xsd", NULL);
                                 

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
                                            if (!axutil_strcasecmp(text_value , "true"))
                                            {
                                                status = adb_TransportSummary_set_nonRemovable(_TransportSummary, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_TransportSummary_set_nonRemovable(_TransportSummary, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element nonRemovable");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for nonRemovable ");
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
                      * building protocol element
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
                                 
                                 element_qname = axutil_qname_create(env, "protocol", "http://util.transports.core.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_TransportSummary_set_protocol(_TransportSummary, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for protocol ");
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
                      * building senderActive element
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
                                 
                                 element_qname = axutil_qname_create(env, "senderActive", "http://util.transports.core.carbon.wso2.org/xsd", NULL);
                                 

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
                                            if (!axutil_strcasecmp(text_value , "true"))
                                            {
                                                status = adb_TransportSummary_set_senderActive(_TransportSummary, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_TransportSummary_set_senderActive(_TransportSummary, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element senderActive");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for senderActive ");
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
          adb_TransportSummary_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_TransportSummary_declare_parent_namespaces(
                    adb_TransportSummary_t* _TransportSummary,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_TransportSummary_serialize(
                adb_TransportSummary_t* _TransportSummary,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
            if (_TransportSummary == NULL)
            {
                return adb_TransportSummary_serialize_obj(
                    _TransportSummary, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            }
            else
            {
                return axis2_extension_mapper_serialize(
                    (adb_type_t*) _TransportSummary, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index, "adb_TransportSummary");
            }
            
        }

        axiom_node_t* AXIS2_CALL
        adb_TransportSummary_serialize_obj(
                adb_TransportSummary_t* _TransportSummary,
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
                    
                    axis2_char_t *text_value_3;
                    axis2_char_t *text_value_3_temp;
                    
                    axis2_char_t text_value_4[ADB_DEFAULT_DIGIT_LIMIT];
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _TransportSummary, NULL);
            
            
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
              type_attrib = axutil_strcat(env, " ", xsi_prefix, ":type=\"TransportSummary\"", NULL);
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
                                 "http://util.transports.core.carbon.wso2.org/xsd",
                                 xsi_prefix);
            xsi_type_attri = axiom_attribute_create (env, "type", "TransportSummary", xsi_ns);
            
            axiom_element_add_attribute (parent_element, env, xsi_type_attri, parent);
        
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.transports.core.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.transports.core.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.transports.core.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_TransportSummary->is_valid_listenerActive)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("listenerActive"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("listenerActive")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing listenerActive element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%slistenerActive>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%slistenerActive>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_1, (_TransportSummary->property_listenerActive)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_1, axutil_strlen(text_value_1));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.transports.core.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.transports.core.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.transports.core.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_TransportSummary->is_valid_nonRemovable)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("nonRemovable"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("nonRemovable")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing nonRemovable element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%snonRemovable>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%snonRemovable>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_2, (_TransportSummary->property_nonRemovable)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_2, axutil_strlen(text_value_2));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.transports.core.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.transports.core.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.transports.core.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_TransportSummary->is_valid_protocol)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("protocol"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("protocol")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing protocol element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sprotocol>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sprotocol>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_3 = _TransportSummary->property_protocol;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.transports.core.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.transports.core.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.transports.core.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_TransportSummary->is_valid_senderActive)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("senderActive"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("senderActive")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing senderActive element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%ssenderActive>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%ssenderActive>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_4, (_TransportSummary->property_senderActive)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_4, axutil_strlen(text_value_4));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 

            return parent;
        }


        

            /**
             * Getter for listenerActive by  Property Number 1
             */
            axis2_bool_t AXIS2_CALL
            adb_TransportSummary_get_property1(
                adb_TransportSummary_t* _TransportSummary,
                const axutil_env_t *env)
            {
                return adb_TransportSummary_get_listenerActive(_TransportSummary,
                                             env);
            }

            /**
             * getter for listenerActive.
             */
            axis2_bool_t AXIS2_CALL
            adb_TransportSummary_get_listenerActive(
                    adb_TransportSummary_t* _TransportSummary,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _TransportSummary, (axis2_bool_t)0);
                  

                return _TransportSummary->property_listenerActive;
             }

            /**
             * setter for listenerActive
             */
            axis2_status_t AXIS2_CALL
            adb_TransportSummary_set_listenerActive(
                    adb_TransportSummary_t* _TransportSummary,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_listenerActive)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _TransportSummary, AXIS2_FAILURE);
                
                if(_TransportSummary->is_valid_listenerActive &&
                        arg_listenerActive == _TransportSummary->property_listenerActive)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_TransportSummary_reset_listenerActive(_TransportSummary, env);

                _TransportSummary->property_listenerActive = arg_listenerActive;
                        _TransportSummary->is_valid_listenerActive = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for listenerActive
            */
           axis2_status_t AXIS2_CALL
           adb_TransportSummary_reset_listenerActive(
                   adb_TransportSummary_t* _TransportSummary,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _TransportSummary, AXIS2_FAILURE);
               

               _TransportSummary->is_valid_listenerActive = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether listenerActive is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_TransportSummary_is_listenerActive_nil(
                   adb_TransportSummary_t* _TransportSummary,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _TransportSummary, AXIS2_TRUE);
               
               return !_TransportSummary->is_valid_listenerActive;
           }

           /**
            * Set listenerActive to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_TransportSummary_set_listenerActive_nil(
                   adb_TransportSummary_t* _TransportSummary,
                   const axutil_env_t *env)
           {
               return adb_TransportSummary_reset_listenerActive(_TransportSummary, env);
           }

           

            /**
             * Getter for nonRemovable by  Property Number 2
             */
            axis2_bool_t AXIS2_CALL
            adb_TransportSummary_get_property2(
                adb_TransportSummary_t* _TransportSummary,
                const axutil_env_t *env)
            {
                return adb_TransportSummary_get_nonRemovable(_TransportSummary,
                                             env);
            }

            /**
             * getter for nonRemovable.
             */
            axis2_bool_t AXIS2_CALL
            adb_TransportSummary_get_nonRemovable(
                    adb_TransportSummary_t* _TransportSummary,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _TransportSummary, (axis2_bool_t)0);
                  

                return _TransportSummary->property_nonRemovable;
             }

            /**
             * setter for nonRemovable
             */
            axis2_status_t AXIS2_CALL
            adb_TransportSummary_set_nonRemovable(
                    adb_TransportSummary_t* _TransportSummary,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_nonRemovable)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _TransportSummary, AXIS2_FAILURE);
                
                if(_TransportSummary->is_valid_nonRemovable &&
                        arg_nonRemovable == _TransportSummary->property_nonRemovable)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_TransportSummary_reset_nonRemovable(_TransportSummary, env);

                _TransportSummary->property_nonRemovable = arg_nonRemovable;
                        _TransportSummary->is_valid_nonRemovable = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for nonRemovable
            */
           axis2_status_t AXIS2_CALL
           adb_TransportSummary_reset_nonRemovable(
                   adb_TransportSummary_t* _TransportSummary,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _TransportSummary, AXIS2_FAILURE);
               

               _TransportSummary->is_valid_nonRemovable = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether nonRemovable is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_TransportSummary_is_nonRemovable_nil(
                   adb_TransportSummary_t* _TransportSummary,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _TransportSummary, AXIS2_TRUE);
               
               return !_TransportSummary->is_valid_nonRemovable;
           }

           /**
            * Set nonRemovable to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_TransportSummary_set_nonRemovable_nil(
                   adb_TransportSummary_t* _TransportSummary,
                   const axutil_env_t *env)
           {
               return adb_TransportSummary_reset_nonRemovable(_TransportSummary, env);
           }

           

            /**
             * Getter for protocol by  Property Number 3
             */
            axis2_char_t* AXIS2_CALL
            adb_TransportSummary_get_property3(
                adb_TransportSummary_t* _TransportSummary,
                const axutil_env_t *env)
            {
                return adb_TransportSummary_get_protocol(_TransportSummary,
                                             env);
            }

            /**
             * getter for protocol.
             */
            axis2_char_t* AXIS2_CALL
            adb_TransportSummary_get_protocol(
                    adb_TransportSummary_t* _TransportSummary,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _TransportSummary, NULL);
                  

                return _TransportSummary->property_protocol;
             }

            /**
             * setter for protocol
             */
            axis2_status_t AXIS2_CALL
            adb_TransportSummary_set_protocol(
                    adb_TransportSummary_t* _TransportSummary,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_protocol)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _TransportSummary, AXIS2_FAILURE);
                
                if(_TransportSummary->is_valid_protocol &&
                        arg_protocol == _TransportSummary->property_protocol)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_TransportSummary_reset_protocol(_TransportSummary, env);

                
                if(NULL == arg_protocol)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _TransportSummary->property_protocol = (axis2_char_t *)axutil_strdup(env, arg_protocol);
                        if(NULL == _TransportSummary->property_protocol)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for protocol");
                            return AXIS2_FAILURE;
                        }
                        _TransportSummary->is_valid_protocol = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for protocol
            */
           axis2_status_t AXIS2_CALL
           adb_TransportSummary_reset_protocol(
                   adb_TransportSummary_t* _TransportSummary,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _TransportSummary, AXIS2_FAILURE);
               

               
            
                
                if(_TransportSummary->property_protocol != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _TransportSummary->property_protocol);
                     _TransportSummary->property_protocol = NULL;
                }
            
                
                
                _TransportSummary->is_valid_protocol = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether protocol is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_TransportSummary_is_protocol_nil(
                   adb_TransportSummary_t* _TransportSummary,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _TransportSummary, AXIS2_TRUE);
               
               return !_TransportSummary->is_valid_protocol;
           }

           /**
            * Set protocol to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_TransportSummary_set_protocol_nil(
                   adb_TransportSummary_t* _TransportSummary,
                   const axutil_env_t *env)
           {
               return adb_TransportSummary_reset_protocol(_TransportSummary, env);
           }

           

            /**
             * Getter for senderActive by  Property Number 4
             */
            axis2_bool_t AXIS2_CALL
            adb_TransportSummary_get_property4(
                adb_TransportSummary_t* _TransportSummary,
                const axutil_env_t *env)
            {
                return adb_TransportSummary_get_senderActive(_TransportSummary,
                                             env);
            }

            /**
             * getter for senderActive.
             */
            axis2_bool_t AXIS2_CALL
            adb_TransportSummary_get_senderActive(
                    adb_TransportSummary_t* _TransportSummary,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _TransportSummary, (axis2_bool_t)0);
                  

                return _TransportSummary->property_senderActive;
             }

            /**
             * setter for senderActive
             */
            axis2_status_t AXIS2_CALL
            adb_TransportSummary_set_senderActive(
                    adb_TransportSummary_t* _TransportSummary,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_senderActive)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _TransportSummary, AXIS2_FAILURE);
                
                if(_TransportSummary->is_valid_senderActive &&
                        arg_senderActive == _TransportSummary->property_senderActive)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_TransportSummary_reset_senderActive(_TransportSummary, env);

                _TransportSummary->property_senderActive = arg_senderActive;
                        _TransportSummary->is_valid_senderActive = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for senderActive
            */
           axis2_status_t AXIS2_CALL
           adb_TransportSummary_reset_senderActive(
                   adb_TransportSummary_t* _TransportSummary,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _TransportSummary, AXIS2_FAILURE);
               

               _TransportSummary->is_valid_senderActive = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether senderActive is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_TransportSummary_is_senderActive_nil(
                   adb_TransportSummary_t* _TransportSummary,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _TransportSummary, AXIS2_TRUE);
               
               return !_TransportSummary->is_valid_senderActive;
           }

           /**
            * Set senderActive to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_TransportSummary_set_senderActive_nil(
                   adb_TransportSummary_t* _TransportSummary,
                   const axutil_env_t *env)
           {
               return adb_TransportSummary_reset_senderActive(_TransportSummary, env);
           }

           

