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
         * adb_SecurityScenarioData.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_SecurityScenarioData.h"
        
                /*
                 * This type was generated from the piece of schema that had
                 * name = SecurityScenarioData
                 * Namespace URI = http://service.config.security.carbon.wso2.org/xsd
                 * Namespace Prefix = ns1
                 */
           


        struct adb_SecurityScenarioData
        {
            axis2_char_t *property_Type;

            axis2_char_t* property_category;

                
                axis2_bool_t is_valid_category;
            axis2_bool_t property_currentScenario;

                
                axis2_bool_t is_valid_currentScenario;
            axis2_char_t* property_description;

                
                axis2_bool_t is_valid_description;
            axis2_char_t* property_scenarioId;

                
                axis2_bool_t is_valid_scenarioId;
            axis2_char_t* property_summary;

                
                axis2_bool_t is_valid_summary;
            axis2_char_t* property_type;

                
                axis2_bool_t is_valid_type;
            
        };


       /************************* Private Function prototypes ********************************/
        

                axis2_status_t AXIS2_CALL
                adb_SecurityScenarioData_set_currentScenario_nil(
                        adb_SecurityScenarioData_t* _SecurityScenarioData,
                        const axutil_env_t *env);
            


       /************************* Function Implmentations ********************************/
        adb_SecurityScenarioData_t* AXIS2_CALL
        adb_SecurityScenarioData_create(
            const axutil_env_t *env)
        {
            adb_SecurityScenarioData_t *_SecurityScenarioData = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _SecurityScenarioData = (adb_SecurityScenarioData_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_SecurityScenarioData_t));

            if(NULL == _SecurityScenarioData)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_SecurityScenarioData, 0, sizeof(adb_SecurityScenarioData_t));

            _SecurityScenarioData->property_Type = axutil_strdup(env, "adb_SecurityScenarioData");
            _SecurityScenarioData->property_category  = NULL;
                  _SecurityScenarioData->is_valid_category  = AXIS2_FALSE;
            _SecurityScenarioData->is_valid_currentScenario  = AXIS2_FALSE;
            _SecurityScenarioData->property_description  = NULL;
                  _SecurityScenarioData->is_valid_description  = AXIS2_FALSE;
            _SecurityScenarioData->property_scenarioId  = NULL;
                  _SecurityScenarioData->is_valid_scenarioId  = AXIS2_FALSE;
            _SecurityScenarioData->property_summary  = NULL;
                  _SecurityScenarioData->is_valid_summary  = AXIS2_FALSE;
            _SecurityScenarioData->property_type  = NULL;
                  _SecurityScenarioData->is_valid_type  = AXIS2_FALSE;
            

            return _SecurityScenarioData;
        }

        adb_SecurityScenarioData_t* AXIS2_CALL
        adb_SecurityScenarioData_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _category,
                axis2_bool_t _currentScenario,
                axis2_char_t* _description,
                axis2_char_t* _scenarioId,
                axis2_char_t* _summary,
                axis2_char_t* _type)
        {
            adb_SecurityScenarioData_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_SecurityScenarioData_create(env);

            
              status = adb_SecurityScenarioData_set_category(
                                     adb_obj,
                                     env,
                                     _category);
              if(status == AXIS2_FAILURE) {
                  adb_SecurityScenarioData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_SecurityScenarioData_set_currentScenario(
                                     adb_obj,
                                     env,
                                     _currentScenario);
              if(status == AXIS2_FAILURE) {
                  adb_SecurityScenarioData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_SecurityScenarioData_set_description(
                                     adb_obj,
                                     env,
                                     _description);
              if(status == AXIS2_FAILURE) {
                  adb_SecurityScenarioData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_SecurityScenarioData_set_scenarioId(
                                     adb_obj,
                                     env,
                                     _scenarioId);
              if(status == AXIS2_FAILURE) {
                  adb_SecurityScenarioData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_SecurityScenarioData_set_summary(
                                     adb_obj,
                                     env,
                                     _summary);
              if(status == AXIS2_FAILURE) {
                  adb_SecurityScenarioData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_SecurityScenarioData_set_type(
                                     adb_obj,
                                     env,
                                     _type);
              if(status == AXIS2_FAILURE) {
                  adb_SecurityScenarioData_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_char_t* AXIS2_CALL
                adb_SecurityScenarioData_free_popping_value(
                        adb_SecurityScenarioData_t* _SecurityScenarioData,
                        const axutil_env_t *env)
                {
                    axis2_char_t* value;

                    
                    
                    value = _SecurityScenarioData->property_category;

                    _SecurityScenarioData->property_category = (axis2_char_t*)NULL;
                    adb_SecurityScenarioData_free(_SecurityScenarioData, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_SecurityScenarioData_free(
                adb_SecurityScenarioData_t* _SecurityScenarioData,
                const axutil_env_t *env)
        {
            
            
            return axis2_extension_mapper_free(
                (adb_type_t*) _SecurityScenarioData,
                env,
                "adb_SecurityScenarioData");
            
        }

        axis2_status_t AXIS2_CALL
        adb_SecurityScenarioData_free_obj(
                adb_SecurityScenarioData_t* _SecurityScenarioData,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _SecurityScenarioData, AXIS2_FAILURE);

            if (_SecurityScenarioData->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _SecurityScenarioData->property_Type);
            }

            adb_SecurityScenarioData_reset_category(_SecurityScenarioData, env);
            adb_SecurityScenarioData_reset_currentScenario(_SecurityScenarioData, env);
            adb_SecurityScenarioData_reset_description(_SecurityScenarioData, env);
            adb_SecurityScenarioData_reset_scenarioId(_SecurityScenarioData, env);
            adb_SecurityScenarioData_reset_summary(_SecurityScenarioData, env);
            adb_SecurityScenarioData_reset_type(_SecurityScenarioData, env);
            

            if(_SecurityScenarioData)
            {
                AXIS2_FREE(env->allocator, _SecurityScenarioData);
                _SecurityScenarioData = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_SecurityScenarioData_deserialize(
                adb_SecurityScenarioData_t* _SecurityScenarioData,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return axis2_extension_mapper_deserialize(
                (adb_type_t*) _SecurityScenarioData,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs,
                "adb_SecurityScenarioData");
            
        }

        axis2_status_t AXIS2_CALL
        adb_SecurityScenarioData_deserialize_obj(
                adb_SecurityScenarioData_t* _SecurityScenarioData,
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
            AXIS2_PARAM_CHECK(env->error, _SecurityScenarioData, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for SecurityScenarioData : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              
                      
                      first_node = axiom_node_get_first_child(parent, env);
                      
                    

                     
                     /*
                      * building category element
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
                                   
                                 element_qname = axutil_qname_create(env, "category", "http://service.config.security.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_SecurityScenarioData_set_category(_SecurityScenarioData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for category ");
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
                      * building currentScenario element
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
                                 
                                 element_qname = axutil_qname_create(env, "currentScenario", "http://service.config.security.carbon.wso2.org/xsd", NULL);
                                 

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
                                                status = adb_SecurityScenarioData_set_currentScenario(_SecurityScenarioData, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_SecurityScenarioData_set_currentScenario(_SecurityScenarioData, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element currentScenario");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for currentScenario ");
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
                                 
                                 element_qname = axutil_qname_create(env, "description", "http://service.config.security.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_SecurityScenarioData_set_description(_SecurityScenarioData, env,
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
                      * building scenarioId element
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
                                 
                                 element_qname = axutil_qname_create(env, "scenarioId", "http://service.config.security.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_SecurityScenarioData_set_scenarioId(_SecurityScenarioData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for scenarioId ");
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
                                 
                                 element_qname = axutil_qname_create(env, "summary", "http://service.config.security.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_SecurityScenarioData_set_summary(_SecurityScenarioData, env,
                                                               text_value);
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
                 

                     
                     /*
                      * building type element
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
                                 
                                 element_qname = axutil_qname_create(env, "type", "http://service.config.security.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_SecurityScenarioData_set_type(_SecurityScenarioData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for type ");
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
          adb_SecurityScenarioData_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_SecurityScenarioData_declare_parent_namespaces(
                    adb_SecurityScenarioData_t* _SecurityScenarioData,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_SecurityScenarioData_serialize(
                adb_SecurityScenarioData_t* _SecurityScenarioData,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
            if (_SecurityScenarioData == NULL)
            {
                return adb_SecurityScenarioData_serialize_obj(
                    _SecurityScenarioData, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            }
            else
            {
                return axis2_extension_mapper_serialize(
                    (adb_type_t*) _SecurityScenarioData, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index, "adb_SecurityScenarioData");
            }
            
        }

        axiom_node_t* AXIS2_CALL
        adb_SecurityScenarioData_serialize_obj(
                adb_SecurityScenarioData_t* _SecurityScenarioData,
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
                    
                    axis2_char_t text_value_2[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t *text_value_3;
                    axis2_char_t *text_value_3_temp;
                    
                    axis2_char_t *text_value_4;
                    axis2_char_t *text_value_4_temp;
                    
                    axis2_char_t *text_value_5;
                    axis2_char_t *text_value_5_temp;
                    
                    axis2_char_t *text_value_6;
                    axis2_char_t *text_value_6_temp;
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _SecurityScenarioData, NULL);
            
            
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
              type_attrib = axutil_strcat(env, " ", xsi_prefix, ":type=\"SecurityScenarioData\"", NULL);
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
                                 "http://service.config.security.carbon.wso2.org/xsd",
                                 xsi_prefix);
            xsi_type_attri = axiom_attribute_create (env, "type", "SecurityScenarioData", xsi_ns);
            
            axiom_element_add_attribute (parent_element, env, xsi_type_attri, parent);
        
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.config.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.config.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.config.security.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_SecurityScenarioData->is_valid_category)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("category"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("category")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing category element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%scategory>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%scategory>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_1 = _SecurityScenarioData->property_category;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.config.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.config.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.config.security.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_SecurityScenarioData->is_valid_currentScenario)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("currentScenario"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("currentScenario")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing currentScenario element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%scurrentScenario>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%scurrentScenario>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_2, (_SecurityScenarioData->property_currentScenario)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_2, axutil_strlen(text_value_2));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.config.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.config.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.config.security.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_SecurityScenarioData->is_valid_description)
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
                    
                           text_value_3 = _SecurityScenarioData->property_description;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.config.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.config.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.config.security.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_SecurityScenarioData->is_valid_scenarioId)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("scenarioId"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("scenarioId")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing scenarioId element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sscenarioId>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sscenarioId>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_4 = _SecurityScenarioData->property_scenarioId;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.config.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.config.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.config.security.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_SecurityScenarioData->is_valid_summary)
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

                    
                    
                            sprintf(start_input_str, "<%s%ssummary>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%ssummary>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_5 = _SecurityScenarioData->property_summary;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.config.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.config.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.config.security.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_SecurityScenarioData->is_valid_type)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("type"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("type")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing type element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%stype>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%stype>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_6 = _SecurityScenarioData->property_type;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_6_temp = axutil_xml_quote_string(env, text_value_6, AXIS2_TRUE);
                           if (text_value_6_temp)
                           {
                               axutil_stream_write(stream, env, text_value_6_temp, axutil_strlen(text_value_6_temp));
                               AXIS2_FREE(env->allocator, text_value_6_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_6, axutil_strlen(text_value_6));
                           }
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 

            return parent;
        }


        

            /**
             * Getter for category by  Property Number 1
             */
            axis2_char_t* AXIS2_CALL
            adb_SecurityScenarioData_get_property1(
                adb_SecurityScenarioData_t* _SecurityScenarioData,
                const axutil_env_t *env)
            {
                return adb_SecurityScenarioData_get_category(_SecurityScenarioData,
                                             env);
            }

            /**
             * getter for category.
             */
            axis2_char_t* AXIS2_CALL
            adb_SecurityScenarioData_get_category(
                    adb_SecurityScenarioData_t* _SecurityScenarioData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _SecurityScenarioData, NULL);
                  

                return _SecurityScenarioData->property_category;
             }

            /**
             * setter for category
             */
            axis2_status_t AXIS2_CALL
            adb_SecurityScenarioData_set_category(
                    adb_SecurityScenarioData_t* _SecurityScenarioData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_category)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _SecurityScenarioData, AXIS2_FAILURE);
                
                if(_SecurityScenarioData->is_valid_category &&
                        arg_category == _SecurityScenarioData->property_category)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_SecurityScenarioData_reset_category(_SecurityScenarioData, env);

                
                if(NULL == arg_category)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _SecurityScenarioData->property_category = (axis2_char_t *)axutil_strdup(env, arg_category);
                        if(NULL == _SecurityScenarioData->property_category)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for category");
                            return AXIS2_FAILURE;
                        }
                        _SecurityScenarioData->is_valid_category = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for category
            */
           axis2_status_t AXIS2_CALL
           adb_SecurityScenarioData_reset_category(
                   adb_SecurityScenarioData_t* _SecurityScenarioData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _SecurityScenarioData, AXIS2_FAILURE);
               

               
            
                
                if(_SecurityScenarioData->property_category != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _SecurityScenarioData->property_category);
                     _SecurityScenarioData->property_category = NULL;
                }
            
                
                
                _SecurityScenarioData->is_valid_category = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether category is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_SecurityScenarioData_is_category_nil(
                   adb_SecurityScenarioData_t* _SecurityScenarioData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _SecurityScenarioData, AXIS2_TRUE);
               
               return !_SecurityScenarioData->is_valid_category;
           }

           /**
            * Set category to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_SecurityScenarioData_set_category_nil(
                   adb_SecurityScenarioData_t* _SecurityScenarioData,
                   const axutil_env_t *env)
           {
               return adb_SecurityScenarioData_reset_category(_SecurityScenarioData, env);
           }

           

            /**
             * Getter for currentScenario by  Property Number 2
             */
            axis2_bool_t AXIS2_CALL
            adb_SecurityScenarioData_get_property2(
                adb_SecurityScenarioData_t* _SecurityScenarioData,
                const axutil_env_t *env)
            {
                return adb_SecurityScenarioData_get_currentScenario(_SecurityScenarioData,
                                             env);
            }

            /**
             * getter for currentScenario.
             */
            axis2_bool_t AXIS2_CALL
            adb_SecurityScenarioData_get_currentScenario(
                    adb_SecurityScenarioData_t* _SecurityScenarioData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _SecurityScenarioData, (axis2_bool_t)0);
                  

                return _SecurityScenarioData->property_currentScenario;
             }

            /**
             * setter for currentScenario
             */
            axis2_status_t AXIS2_CALL
            adb_SecurityScenarioData_set_currentScenario(
                    adb_SecurityScenarioData_t* _SecurityScenarioData,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_currentScenario)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _SecurityScenarioData, AXIS2_FAILURE);
                
                if(_SecurityScenarioData->is_valid_currentScenario &&
                        arg_currentScenario == _SecurityScenarioData->property_currentScenario)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_SecurityScenarioData_reset_currentScenario(_SecurityScenarioData, env);

                _SecurityScenarioData->property_currentScenario = arg_currentScenario;
                        _SecurityScenarioData->is_valid_currentScenario = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for currentScenario
            */
           axis2_status_t AXIS2_CALL
           adb_SecurityScenarioData_reset_currentScenario(
                   adb_SecurityScenarioData_t* _SecurityScenarioData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _SecurityScenarioData, AXIS2_FAILURE);
               

               _SecurityScenarioData->is_valid_currentScenario = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether currentScenario is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_SecurityScenarioData_is_currentScenario_nil(
                   adb_SecurityScenarioData_t* _SecurityScenarioData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _SecurityScenarioData, AXIS2_TRUE);
               
               return !_SecurityScenarioData->is_valid_currentScenario;
           }

           /**
            * Set currentScenario to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_SecurityScenarioData_set_currentScenario_nil(
                   adb_SecurityScenarioData_t* _SecurityScenarioData,
                   const axutil_env_t *env)
           {
               return adb_SecurityScenarioData_reset_currentScenario(_SecurityScenarioData, env);
           }

           

            /**
             * Getter for description by  Property Number 3
             */
            axis2_char_t* AXIS2_CALL
            adb_SecurityScenarioData_get_property3(
                adb_SecurityScenarioData_t* _SecurityScenarioData,
                const axutil_env_t *env)
            {
                return adb_SecurityScenarioData_get_description(_SecurityScenarioData,
                                             env);
            }

            /**
             * getter for description.
             */
            axis2_char_t* AXIS2_CALL
            adb_SecurityScenarioData_get_description(
                    adb_SecurityScenarioData_t* _SecurityScenarioData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _SecurityScenarioData, NULL);
                  

                return _SecurityScenarioData->property_description;
             }

            /**
             * setter for description
             */
            axis2_status_t AXIS2_CALL
            adb_SecurityScenarioData_set_description(
                    adb_SecurityScenarioData_t* _SecurityScenarioData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_description)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _SecurityScenarioData, AXIS2_FAILURE);
                
                if(_SecurityScenarioData->is_valid_description &&
                        arg_description == _SecurityScenarioData->property_description)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_SecurityScenarioData_reset_description(_SecurityScenarioData, env);

                
                if(NULL == arg_description)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _SecurityScenarioData->property_description = (axis2_char_t *)axutil_strdup(env, arg_description);
                        if(NULL == _SecurityScenarioData->property_description)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for description");
                            return AXIS2_FAILURE;
                        }
                        _SecurityScenarioData->is_valid_description = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for description
            */
           axis2_status_t AXIS2_CALL
           adb_SecurityScenarioData_reset_description(
                   adb_SecurityScenarioData_t* _SecurityScenarioData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _SecurityScenarioData, AXIS2_FAILURE);
               

               
            
                
                if(_SecurityScenarioData->property_description != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _SecurityScenarioData->property_description);
                     _SecurityScenarioData->property_description = NULL;
                }
            
                
                
                _SecurityScenarioData->is_valid_description = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether description is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_SecurityScenarioData_is_description_nil(
                   adb_SecurityScenarioData_t* _SecurityScenarioData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _SecurityScenarioData, AXIS2_TRUE);
               
               return !_SecurityScenarioData->is_valid_description;
           }

           /**
            * Set description to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_SecurityScenarioData_set_description_nil(
                   adb_SecurityScenarioData_t* _SecurityScenarioData,
                   const axutil_env_t *env)
           {
               return adb_SecurityScenarioData_reset_description(_SecurityScenarioData, env);
           }

           

            /**
             * Getter for scenarioId by  Property Number 4
             */
            axis2_char_t* AXIS2_CALL
            adb_SecurityScenarioData_get_property4(
                adb_SecurityScenarioData_t* _SecurityScenarioData,
                const axutil_env_t *env)
            {
                return adb_SecurityScenarioData_get_scenarioId(_SecurityScenarioData,
                                             env);
            }

            /**
             * getter for scenarioId.
             */
            axis2_char_t* AXIS2_CALL
            adb_SecurityScenarioData_get_scenarioId(
                    adb_SecurityScenarioData_t* _SecurityScenarioData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _SecurityScenarioData, NULL);
                  

                return _SecurityScenarioData->property_scenarioId;
             }

            /**
             * setter for scenarioId
             */
            axis2_status_t AXIS2_CALL
            adb_SecurityScenarioData_set_scenarioId(
                    adb_SecurityScenarioData_t* _SecurityScenarioData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_scenarioId)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _SecurityScenarioData, AXIS2_FAILURE);
                
                if(_SecurityScenarioData->is_valid_scenarioId &&
                        arg_scenarioId == _SecurityScenarioData->property_scenarioId)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_SecurityScenarioData_reset_scenarioId(_SecurityScenarioData, env);

                
                if(NULL == arg_scenarioId)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _SecurityScenarioData->property_scenarioId = (axis2_char_t *)axutil_strdup(env, arg_scenarioId);
                        if(NULL == _SecurityScenarioData->property_scenarioId)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for scenarioId");
                            return AXIS2_FAILURE;
                        }
                        _SecurityScenarioData->is_valid_scenarioId = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for scenarioId
            */
           axis2_status_t AXIS2_CALL
           adb_SecurityScenarioData_reset_scenarioId(
                   adb_SecurityScenarioData_t* _SecurityScenarioData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _SecurityScenarioData, AXIS2_FAILURE);
               

               
            
                
                if(_SecurityScenarioData->property_scenarioId != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _SecurityScenarioData->property_scenarioId);
                     _SecurityScenarioData->property_scenarioId = NULL;
                }
            
                
                
                _SecurityScenarioData->is_valid_scenarioId = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether scenarioId is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_SecurityScenarioData_is_scenarioId_nil(
                   adb_SecurityScenarioData_t* _SecurityScenarioData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _SecurityScenarioData, AXIS2_TRUE);
               
               return !_SecurityScenarioData->is_valid_scenarioId;
           }

           /**
            * Set scenarioId to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_SecurityScenarioData_set_scenarioId_nil(
                   adb_SecurityScenarioData_t* _SecurityScenarioData,
                   const axutil_env_t *env)
           {
               return adb_SecurityScenarioData_reset_scenarioId(_SecurityScenarioData, env);
           }

           

            /**
             * Getter for summary by  Property Number 5
             */
            axis2_char_t* AXIS2_CALL
            adb_SecurityScenarioData_get_property5(
                adb_SecurityScenarioData_t* _SecurityScenarioData,
                const axutil_env_t *env)
            {
                return adb_SecurityScenarioData_get_summary(_SecurityScenarioData,
                                             env);
            }

            /**
             * getter for summary.
             */
            axis2_char_t* AXIS2_CALL
            adb_SecurityScenarioData_get_summary(
                    adb_SecurityScenarioData_t* _SecurityScenarioData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _SecurityScenarioData, NULL);
                  

                return _SecurityScenarioData->property_summary;
             }

            /**
             * setter for summary
             */
            axis2_status_t AXIS2_CALL
            adb_SecurityScenarioData_set_summary(
                    adb_SecurityScenarioData_t* _SecurityScenarioData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_summary)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _SecurityScenarioData, AXIS2_FAILURE);
                
                if(_SecurityScenarioData->is_valid_summary &&
                        arg_summary == _SecurityScenarioData->property_summary)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_SecurityScenarioData_reset_summary(_SecurityScenarioData, env);

                
                if(NULL == arg_summary)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _SecurityScenarioData->property_summary = (axis2_char_t *)axutil_strdup(env, arg_summary);
                        if(NULL == _SecurityScenarioData->property_summary)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for summary");
                            return AXIS2_FAILURE;
                        }
                        _SecurityScenarioData->is_valid_summary = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for summary
            */
           axis2_status_t AXIS2_CALL
           adb_SecurityScenarioData_reset_summary(
                   adb_SecurityScenarioData_t* _SecurityScenarioData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _SecurityScenarioData, AXIS2_FAILURE);
               

               
            
                
                if(_SecurityScenarioData->property_summary != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _SecurityScenarioData->property_summary);
                     _SecurityScenarioData->property_summary = NULL;
                }
            
                
                
                _SecurityScenarioData->is_valid_summary = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether summary is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_SecurityScenarioData_is_summary_nil(
                   adb_SecurityScenarioData_t* _SecurityScenarioData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _SecurityScenarioData, AXIS2_TRUE);
               
               return !_SecurityScenarioData->is_valid_summary;
           }

           /**
            * Set summary to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_SecurityScenarioData_set_summary_nil(
                   adb_SecurityScenarioData_t* _SecurityScenarioData,
                   const axutil_env_t *env)
           {
               return adb_SecurityScenarioData_reset_summary(_SecurityScenarioData, env);
           }

           

            /**
             * Getter for type by  Property Number 6
             */
            axis2_char_t* AXIS2_CALL
            adb_SecurityScenarioData_get_property6(
                adb_SecurityScenarioData_t* _SecurityScenarioData,
                const axutil_env_t *env)
            {
                return adb_SecurityScenarioData_get_type(_SecurityScenarioData,
                                             env);
            }

            /**
             * getter for type.
             */
            axis2_char_t* AXIS2_CALL
            adb_SecurityScenarioData_get_type(
                    adb_SecurityScenarioData_t* _SecurityScenarioData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _SecurityScenarioData, NULL);
                  

                return _SecurityScenarioData->property_type;
             }

            /**
             * setter for type
             */
            axis2_status_t AXIS2_CALL
            adb_SecurityScenarioData_set_type(
                    adb_SecurityScenarioData_t* _SecurityScenarioData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_type)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _SecurityScenarioData, AXIS2_FAILURE);
                
                if(_SecurityScenarioData->is_valid_type &&
                        arg_type == _SecurityScenarioData->property_type)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_SecurityScenarioData_reset_type(_SecurityScenarioData, env);

                
                if(NULL == arg_type)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _SecurityScenarioData->property_type = (axis2_char_t *)axutil_strdup(env, arg_type);
                        if(NULL == _SecurityScenarioData->property_type)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for type");
                            return AXIS2_FAILURE;
                        }
                        _SecurityScenarioData->is_valid_type = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for type
            */
           axis2_status_t AXIS2_CALL
           adb_SecurityScenarioData_reset_type(
                   adb_SecurityScenarioData_t* _SecurityScenarioData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _SecurityScenarioData, AXIS2_FAILURE);
               

               
            
                
                if(_SecurityScenarioData->property_type != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _SecurityScenarioData->property_type);
                     _SecurityScenarioData->property_type = NULL;
                }
            
                
                
                _SecurityScenarioData->is_valid_type = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether type is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_SecurityScenarioData_is_type_nil(
                   adb_SecurityScenarioData_t* _SecurityScenarioData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _SecurityScenarioData, AXIS2_TRUE);
               
               return !_SecurityScenarioData->is_valid_type;
           }

           /**
            * Set type to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_SecurityScenarioData_set_type_nil(
                   adb_SecurityScenarioData_t* _SecurityScenarioData,
                   const axutil_env_t *env)
           {
               return adb_SecurityScenarioData_reset_type(_SecurityScenarioData, env);
           }

           

