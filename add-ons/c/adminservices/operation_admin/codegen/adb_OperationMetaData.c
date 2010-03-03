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
         * adb_OperationMetaData.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_OperationMetaData.h"
        
                /*
                 * This type was generated from the piece of schema that had
                 * name = OperationMetaData
                 * Namespace URI = http://mgt.operation.carbon.wso2.org/xsd
                 * Namespace Prefix = ns1
                 */
           


        struct adb_OperationMetaData
        {
            axis2_char_t *property_Type;

            axis2_bool_t property_controlOperation;

                
                axis2_bool_t is_valid_controlOperation;
            axis2_char_t* property_enableMTOM;

                
                axis2_bool_t is_valid_enableMTOM;
            axis2_char_t* property_name;

                
                axis2_bool_t is_valid_name;
            
        };


       /************************* Private Function prototypes ********************************/
        

                axis2_status_t AXIS2_CALL
                adb_OperationMetaData_set_controlOperation_nil(
                        adb_OperationMetaData_t* _OperationMetaData,
                        const axutil_env_t *env);
            


       /************************* Function Implmentations ********************************/
        adb_OperationMetaData_t* AXIS2_CALL
        adb_OperationMetaData_create(
            const axutil_env_t *env)
        {
            adb_OperationMetaData_t *_OperationMetaData = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _OperationMetaData = (adb_OperationMetaData_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_OperationMetaData_t));

            if(NULL == _OperationMetaData)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_OperationMetaData, 0, sizeof(adb_OperationMetaData_t));

            _OperationMetaData->property_Type = axutil_strdup(env, "adb_OperationMetaData");
            _OperationMetaData->is_valid_controlOperation  = AXIS2_FALSE;
            _OperationMetaData->property_enableMTOM  = NULL;
                  _OperationMetaData->is_valid_enableMTOM  = AXIS2_FALSE;
            _OperationMetaData->property_name  = NULL;
                  _OperationMetaData->is_valid_name  = AXIS2_FALSE;
            

            return _OperationMetaData;
        }

        adb_OperationMetaData_t* AXIS2_CALL
        adb_OperationMetaData_create_with_values(
            const axutil_env_t *env,
                axis2_bool_t _controlOperation,
                axis2_char_t* _enableMTOM,
                axis2_char_t* _name)
        {
            adb_OperationMetaData_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_OperationMetaData_create(env);

            
              status = adb_OperationMetaData_set_controlOperation(
                                     adb_obj,
                                     env,
                                     _controlOperation);
              if(status == AXIS2_FAILURE) {
                  adb_OperationMetaData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_OperationMetaData_set_enableMTOM(
                                     adb_obj,
                                     env,
                                     _enableMTOM);
              if(status == AXIS2_FAILURE) {
                  adb_OperationMetaData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_OperationMetaData_set_name(
                                     adb_obj,
                                     env,
                                     _name);
              if(status == AXIS2_FAILURE) {
                  adb_OperationMetaData_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_bool_t AXIS2_CALL
                adb_OperationMetaData_free_popping_value(
                        adb_OperationMetaData_t* _OperationMetaData,
                        const axutil_env_t *env)
                {
                    axis2_bool_t value;

                    
                    
                    value = _OperationMetaData->property_controlOperation;

                    adb_OperationMetaData_free(_OperationMetaData, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_OperationMetaData_free(
                adb_OperationMetaData_t* _OperationMetaData,
                const axutil_env_t *env)
        {
            
            
            return axis2_extension_mapper_free(
                (adb_type_t*) _OperationMetaData,
                env,
                "adb_OperationMetaData");
            
        }

        axis2_status_t AXIS2_CALL
        adb_OperationMetaData_free_obj(
                adb_OperationMetaData_t* _OperationMetaData,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _OperationMetaData, AXIS2_FAILURE);

            if (_OperationMetaData->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _OperationMetaData->property_Type);
            }

            adb_OperationMetaData_reset_controlOperation(_OperationMetaData, env);
            adb_OperationMetaData_reset_enableMTOM(_OperationMetaData, env);
            adb_OperationMetaData_reset_name(_OperationMetaData, env);
            

            if(_OperationMetaData)
            {
                AXIS2_FREE(env->allocator, _OperationMetaData);
                _OperationMetaData = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_OperationMetaData_deserialize(
                adb_OperationMetaData_t* _OperationMetaData,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return axis2_extension_mapper_deserialize(
                (adb_type_t*) _OperationMetaData,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs,
                "adb_OperationMetaData");
            
        }

        axis2_status_t AXIS2_CALL
        adb_OperationMetaData_deserialize_obj(
                adb_OperationMetaData_t* _OperationMetaData,
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
            AXIS2_PARAM_CHECK(env->error, _OperationMetaData, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for OperationMetaData : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              
                      
                      first_node = axiom_node_get_first_child(parent, env);
                      
                    

                     
                     /*
                      * building controlOperation element
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
                                   
                                 element_qname = axutil_qname_create(env, "controlOperation", "http://mgt.operation.carbon.wso2.org/xsd", NULL);
                                 

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
                                                status = adb_OperationMetaData_set_controlOperation(_OperationMetaData, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_OperationMetaData_set_controlOperation(_OperationMetaData, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element controlOperation");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for controlOperation ");
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
                      * building enableMTOM element
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
                                 
                                 element_qname = axutil_qname_create(env, "enableMTOM", "http://mgt.operation.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_OperationMetaData_set_enableMTOM(_OperationMetaData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for enableMTOM ");
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
                      * building name element
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
                                 
                                 element_qname = axutil_qname_create(env, "name", "http://mgt.operation.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_OperationMetaData_set_name(_OperationMetaData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for name ");
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
          adb_OperationMetaData_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_OperationMetaData_declare_parent_namespaces(
                    adb_OperationMetaData_t* _OperationMetaData,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_OperationMetaData_serialize(
                adb_OperationMetaData_t* _OperationMetaData,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
            if (_OperationMetaData == NULL)
            {
                return adb_OperationMetaData_serialize_obj(
                    _OperationMetaData, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            }
            else
            {
                return axis2_extension_mapper_serialize(
                    (adb_type_t*) _OperationMetaData, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index, "adb_OperationMetaData");
            }
            
        }

        axiom_node_t* AXIS2_CALL
        adb_OperationMetaData_serialize_obj(
                adb_OperationMetaData_t* _OperationMetaData,
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
                    
                    axis2_char_t *text_value_2;
                    axis2_char_t *text_value_2_temp;
                    
                    axis2_char_t *text_value_3;
                    axis2_char_t *text_value_3_temp;
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _OperationMetaData, NULL);
            
            
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
              type_attrib = axutil_strcat(env, " ", xsi_prefix, ":type=\"OperationMetaData\"", NULL);
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
                                 "http://mgt.operation.carbon.wso2.org/xsd",
                                 xsi_prefix);
            xsi_type_attri = axiom_attribute_create (env, "type", "OperationMetaData", xsi_ns);
            
            axiom_element_add_attribute (parent_element, env, xsi_type_attri, parent);
        
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://mgt.operation.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://mgt.operation.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://mgt.operation.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_OperationMetaData->is_valid_controlOperation)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("controlOperation"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("controlOperation")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing controlOperation element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%scontrolOperation>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%scontrolOperation>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_1, (_OperationMetaData->property_controlOperation)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_1, axutil_strlen(text_value_1));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://mgt.operation.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://mgt.operation.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://mgt.operation.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_OperationMetaData->is_valid_enableMTOM)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("enableMTOM"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("enableMTOM")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing enableMTOM element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%senableMTOM>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%senableMTOM>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_2 = _OperationMetaData->property_enableMTOM;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://mgt.operation.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://mgt.operation.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://mgt.operation.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_OperationMetaData->is_valid_name)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("name"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("name")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing name element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sname>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sname>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_3 = _OperationMetaData->property_name;
                           
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

                 

            return parent;
        }


        

            /**
             * Getter for controlOperation by  Property Number 1
             */
            axis2_bool_t AXIS2_CALL
            adb_OperationMetaData_get_property1(
                adb_OperationMetaData_t* _OperationMetaData,
                const axutil_env_t *env)
            {
                return adb_OperationMetaData_get_controlOperation(_OperationMetaData,
                                             env);
            }

            /**
             * getter for controlOperation.
             */
            axis2_bool_t AXIS2_CALL
            adb_OperationMetaData_get_controlOperation(
                    adb_OperationMetaData_t* _OperationMetaData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _OperationMetaData, (axis2_bool_t)0);
                  

                return _OperationMetaData->property_controlOperation;
             }

            /**
             * setter for controlOperation
             */
            axis2_status_t AXIS2_CALL
            adb_OperationMetaData_set_controlOperation(
                    adb_OperationMetaData_t* _OperationMetaData,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_controlOperation)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _OperationMetaData, AXIS2_FAILURE);
                
                if(_OperationMetaData->is_valid_controlOperation &&
                        arg_controlOperation == _OperationMetaData->property_controlOperation)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_OperationMetaData_reset_controlOperation(_OperationMetaData, env);

                _OperationMetaData->property_controlOperation = arg_controlOperation;
                        _OperationMetaData->is_valid_controlOperation = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for controlOperation
            */
           axis2_status_t AXIS2_CALL
           adb_OperationMetaData_reset_controlOperation(
                   adb_OperationMetaData_t* _OperationMetaData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _OperationMetaData, AXIS2_FAILURE);
               

               _OperationMetaData->is_valid_controlOperation = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether controlOperation is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_OperationMetaData_is_controlOperation_nil(
                   adb_OperationMetaData_t* _OperationMetaData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _OperationMetaData, AXIS2_TRUE);
               
               return !_OperationMetaData->is_valid_controlOperation;
           }

           /**
            * Set controlOperation to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_OperationMetaData_set_controlOperation_nil(
                   adb_OperationMetaData_t* _OperationMetaData,
                   const axutil_env_t *env)
           {
               return adb_OperationMetaData_reset_controlOperation(_OperationMetaData, env);
           }

           

            /**
             * Getter for enableMTOM by  Property Number 2
             */
            axis2_char_t* AXIS2_CALL
            adb_OperationMetaData_get_property2(
                adb_OperationMetaData_t* _OperationMetaData,
                const axutil_env_t *env)
            {
                return adb_OperationMetaData_get_enableMTOM(_OperationMetaData,
                                             env);
            }

            /**
             * getter for enableMTOM.
             */
            axis2_char_t* AXIS2_CALL
            adb_OperationMetaData_get_enableMTOM(
                    adb_OperationMetaData_t* _OperationMetaData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _OperationMetaData, NULL);
                  

                return _OperationMetaData->property_enableMTOM;
             }

            /**
             * setter for enableMTOM
             */
            axis2_status_t AXIS2_CALL
            adb_OperationMetaData_set_enableMTOM(
                    adb_OperationMetaData_t* _OperationMetaData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_enableMTOM)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _OperationMetaData, AXIS2_FAILURE);
                
                if(_OperationMetaData->is_valid_enableMTOM &&
                        arg_enableMTOM == _OperationMetaData->property_enableMTOM)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_OperationMetaData_reset_enableMTOM(_OperationMetaData, env);

                
                if(NULL == arg_enableMTOM)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _OperationMetaData->property_enableMTOM = (axis2_char_t *)axutil_strdup(env, arg_enableMTOM);
                        if(NULL == _OperationMetaData->property_enableMTOM)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for enableMTOM");
                            return AXIS2_FAILURE;
                        }
                        _OperationMetaData->is_valid_enableMTOM = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for enableMTOM
            */
           axis2_status_t AXIS2_CALL
           adb_OperationMetaData_reset_enableMTOM(
                   adb_OperationMetaData_t* _OperationMetaData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _OperationMetaData, AXIS2_FAILURE);
               

               
            
                
                if(_OperationMetaData->property_enableMTOM != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _OperationMetaData->property_enableMTOM);
                     _OperationMetaData->property_enableMTOM = NULL;
                }
            
                
                
                _OperationMetaData->is_valid_enableMTOM = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether enableMTOM is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_OperationMetaData_is_enableMTOM_nil(
                   adb_OperationMetaData_t* _OperationMetaData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _OperationMetaData, AXIS2_TRUE);
               
               return !_OperationMetaData->is_valid_enableMTOM;
           }

           /**
            * Set enableMTOM to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_OperationMetaData_set_enableMTOM_nil(
                   adb_OperationMetaData_t* _OperationMetaData,
                   const axutil_env_t *env)
           {
               return adb_OperationMetaData_reset_enableMTOM(_OperationMetaData, env);
           }

           

            /**
             * Getter for name by  Property Number 3
             */
            axis2_char_t* AXIS2_CALL
            adb_OperationMetaData_get_property3(
                adb_OperationMetaData_t* _OperationMetaData,
                const axutil_env_t *env)
            {
                return adb_OperationMetaData_get_name(_OperationMetaData,
                                             env);
            }

            /**
             * getter for name.
             */
            axis2_char_t* AXIS2_CALL
            adb_OperationMetaData_get_name(
                    adb_OperationMetaData_t* _OperationMetaData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _OperationMetaData, NULL);
                  

                return _OperationMetaData->property_name;
             }

            /**
             * setter for name
             */
            axis2_status_t AXIS2_CALL
            adb_OperationMetaData_set_name(
                    adb_OperationMetaData_t* _OperationMetaData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_name)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _OperationMetaData, AXIS2_FAILURE);
                
                if(_OperationMetaData->is_valid_name &&
                        arg_name == _OperationMetaData->property_name)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_OperationMetaData_reset_name(_OperationMetaData, env);

                
                if(NULL == arg_name)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _OperationMetaData->property_name = (axis2_char_t *)axutil_strdup(env, arg_name);
                        if(NULL == _OperationMetaData->property_name)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for name");
                            return AXIS2_FAILURE;
                        }
                        _OperationMetaData->is_valid_name = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for name
            */
           axis2_status_t AXIS2_CALL
           adb_OperationMetaData_reset_name(
                   adb_OperationMetaData_t* _OperationMetaData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _OperationMetaData, AXIS2_FAILURE);
               

               
            
                
                if(_OperationMetaData->property_name != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _OperationMetaData->property_name);
                     _OperationMetaData->property_name = NULL;
                }
            
                
                
                _OperationMetaData->is_valid_name = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether name is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_OperationMetaData_is_name_nil(
                   adb_OperationMetaData_t* _OperationMetaData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _OperationMetaData, AXIS2_TRUE);
               
               return !_OperationMetaData->is_valid_name;
           }

           /**
            * Set name to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_OperationMetaData_set_name_nil(
                   adb_OperationMetaData_t* _OperationMetaData,
                   const axutil_env_t *env)
           {
               return adb_OperationMetaData_reset_name(_OperationMetaData, env);
           }

           

