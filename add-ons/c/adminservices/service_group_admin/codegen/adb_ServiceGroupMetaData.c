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
         * adb_ServiceGroupMetaData.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_ServiceGroupMetaData.h"
        
                /*
                 * This type was generated from the piece of schema that had
                 * name = ServiceGroupMetaData
                 * Namespace URI = http://mgt.service.carbon.wso2.org/xsd
                 * Namespace Prefix = ns1
                 */
           


        struct adb_ServiceGroupMetaData
        {
            axis2_char_t *property_Type;

            axutil_array_list_t* property_engagedModules;

                
                axis2_bool_t is_valid_engagedModules;
            axis2_char_t* property_mtomStatus;

                
                axis2_bool_t is_valid_mtomStatus;
            axis2_char_t* property_serviceContextPath;

                
                axis2_bool_t is_valid_serviceContextPath;
            axis2_char_t* property_serviceGroupName;

                
                axis2_bool_t is_valid_serviceGroupName;
            axutil_array_list_t* property_services;

                
                axis2_bool_t is_valid_services;
            
        };


       /************************* Private Function prototypes ********************************/
        


       /************************* Function Implmentations ********************************/
        adb_ServiceGroupMetaData_t* AXIS2_CALL
        adb_ServiceGroupMetaData_create(
            const axutil_env_t *env)
        {
            adb_ServiceGroupMetaData_t *_ServiceGroupMetaData = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _ServiceGroupMetaData = (adb_ServiceGroupMetaData_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_ServiceGroupMetaData_t));

            if(NULL == _ServiceGroupMetaData)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_ServiceGroupMetaData, 0, sizeof(adb_ServiceGroupMetaData_t));

            _ServiceGroupMetaData->property_Type = axutil_strdup(env, "adb_ServiceGroupMetaData");
            _ServiceGroupMetaData->property_engagedModules  = NULL;
                  _ServiceGroupMetaData->is_valid_engagedModules  = AXIS2_FALSE;
            _ServiceGroupMetaData->property_mtomStatus  = NULL;
                  _ServiceGroupMetaData->is_valid_mtomStatus  = AXIS2_FALSE;
            _ServiceGroupMetaData->property_serviceContextPath  = NULL;
                  _ServiceGroupMetaData->is_valid_serviceContextPath  = AXIS2_FALSE;
            _ServiceGroupMetaData->property_serviceGroupName  = NULL;
                  _ServiceGroupMetaData->is_valid_serviceGroupName  = AXIS2_FALSE;
            _ServiceGroupMetaData->property_services  = NULL;
                  _ServiceGroupMetaData->is_valid_services  = AXIS2_FALSE;
            

            return _ServiceGroupMetaData;
        }

        adb_ServiceGroupMetaData_t* AXIS2_CALL
        adb_ServiceGroupMetaData_create_with_values(
            const axutil_env_t *env,
                axutil_array_list_t* _engagedModules,
                axis2_char_t* _mtomStatus,
                axis2_char_t* _serviceContextPath,
                axis2_char_t* _serviceGroupName,
                axutil_array_list_t* _services)
        {
            adb_ServiceGroupMetaData_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_ServiceGroupMetaData_create(env);

            
              status = adb_ServiceGroupMetaData_set_engagedModules(
                                     adb_obj,
                                     env,
                                     _engagedModules);
              if(status == AXIS2_FAILURE) {
                  adb_ServiceGroupMetaData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServiceGroupMetaData_set_mtomStatus(
                                     adb_obj,
                                     env,
                                     _mtomStatus);
              if(status == AXIS2_FAILURE) {
                  adb_ServiceGroupMetaData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServiceGroupMetaData_set_serviceContextPath(
                                     adb_obj,
                                     env,
                                     _serviceContextPath);
              if(status == AXIS2_FAILURE) {
                  adb_ServiceGroupMetaData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServiceGroupMetaData_set_serviceGroupName(
                                     adb_obj,
                                     env,
                                     _serviceGroupName);
              if(status == AXIS2_FAILURE) {
                  adb_ServiceGroupMetaData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServiceGroupMetaData_set_services(
                                     adb_obj,
                                     env,
                                     _services);
              if(status == AXIS2_FAILURE) {
                  adb_ServiceGroupMetaData_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axutil_array_list_t* AXIS2_CALL
                adb_ServiceGroupMetaData_free_popping_value(
                        adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                        const axutil_env_t *env)
                {
                    axutil_array_list_t* value;

                    
                    
                    value = _ServiceGroupMetaData->property_engagedModules;

                    _ServiceGroupMetaData->property_engagedModules = (axutil_array_list_t*)NULL;
                    adb_ServiceGroupMetaData_free(_ServiceGroupMetaData, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaData_free(
                adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                const axutil_env_t *env)
        {
            
            
            return axis2_extension_mapper_free(
                (adb_type_t*) _ServiceGroupMetaData,
                env,
                "adb_ServiceGroupMetaData");
            
        }

        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaData_free_obj(
                adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                const axutil_env_t *env)
        {
            
                int i = 0;
                int count = 0;
                void *element = NULL;
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _ServiceGroupMetaData, AXIS2_FAILURE);

            if (_ServiceGroupMetaData->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _ServiceGroupMetaData->property_Type);
            }

            adb_ServiceGroupMetaData_reset_engagedModules(_ServiceGroupMetaData, env);
            adb_ServiceGroupMetaData_reset_mtomStatus(_ServiceGroupMetaData, env);
            adb_ServiceGroupMetaData_reset_serviceContextPath(_ServiceGroupMetaData, env);
            adb_ServiceGroupMetaData_reset_serviceGroupName(_ServiceGroupMetaData, env);
            adb_ServiceGroupMetaData_reset_services(_ServiceGroupMetaData, env);
            

            if(_ServiceGroupMetaData)
            {
                AXIS2_FREE(env->allocator, _ServiceGroupMetaData);
                _ServiceGroupMetaData = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaData_deserialize(
                adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return axis2_extension_mapper_deserialize(
                (adb_type_t*) _ServiceGroupMetaData,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs,
                "adb_ServiceGroupMetaData");
            
        }

        axis2_status_t AXIS2_CALL
        adb_ServiceGroupMetaData_deserialize_obj(
                adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
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
            AXIS2_PARAM_CHECK(env->error, _ServiceGroupMetaData, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for ServiceGroupMetaData : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              
                      
                      first_node = axiom_node_get_first_child(parent, env);
                      
                    
                    /*
                     * building engagedModules array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building engagedModules element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "engagedModules", "http://mgt.service.carbon.wso2.org/xsd", NULL);
                                  
                               
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

                                  if ( 
                                    (current_node && current_element && (axutil_qname_equals(element_qname, env, qname))))
                                  {
                                  
                                      if( current_node && current_element && (axutil_qname_equals(element_qname, env, qname)))
                                      {
                                          is_early_node_valid = AXIS2_TRUE;
                                      }
                                      
                                     
                                          text_value = axiom_element_get_text(current_element, env, current_node);
                                          if(text_value != NULL)
                                          {
                                              axutil_array_list_add_at(arr_list, env, i, axutil_strdup(env, text_value));
                                          }
                                          
                                     if(AXIS2_FAILURE ==  status)
                                     {
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for engagedModules ");
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
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "engagedModules (@minOccurs = '0') only have %d elements", i);
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
                                    status = adb_ServiceGroupMetaData_set_engagedModules(_ServiceGroupMetaData, env,
                                                                   arr_list);
                               }

                             
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 

                     
                     /*
                      * building mtomStatus element
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
                                 
                                 element_qname = axutil_qname_create(env, "mtomStatus", "http://mgt.service.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ServiceGroupMetaData_set_mtomStatus(_ServiceGroupMetaData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for mtomStatus ");
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
                      * building serviceContextPath element
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
                                 
                                 element_qname = axutil_qname_create(env, "serviceContextPath", "http://mgt.service.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ServiceGroupMetaData_set_serviceContextPath(_ServiceGroupMetaData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for serviceContextPath ");
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
                      * building serviceGroupName element
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
                                 
                                 element_qname = axutil_qname_create(env, "serviceGroupName", "http://mgt.service.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ServiceGroupMetaData_set_serviceGroupName(_ServiceGroupMetaData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for serviceGroupName ");
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
                     * building services array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building services element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "services", "http://mgt.service.carbon.wso2.org/xsd", NULL);
                                  
                               
                               for (i = 0, sequence_broken = 0, current_node = (is_early_node_valid?axiom_node_get_next_sibling(current_node, env):current_node); !sequence_broken && current_node != NULL;) 
                                             
                               {
                                  if(axiom_node_get_node_type(current_node, env) != AXIOM_ELEMENT)
                                  {
                                     current_node =axiom_node_get_next_sibling(current_node, env);
                                     is_early_node_valid = AXIS2_FALSE;
                                     continue;
                                  }
                                  
                                  current_element = (axiom_element_t *)axiom_node_get_data_element(current_node, env);
                                  qname = axiom_element_get_qname(current_element, env, current_node);

                                  if (adb_ServiceMetaData_is_particle() ||  
                                    (current_node && current_element && (axutil_qname_equals(element_qname, env, qname))))
                                  {
                                  
                                      if( current_node && current_element && (axutil_qname_equals(element_qname, env, qname)))
                                      {
                                          is_early_node_valid = AXIS2_TRUE;
                                      }
                                      
                                     
                                          element = (void*)axis2_extension_mapper_create_from_node(env, &current_node, "adb_ServiceMetaData");
                                          
                                          status =  adb_ServiceMetaData_deserialize((adb_ServiceMetaData_t*)element, env,
                                                                                 &current_node, &is_early_node_valid, AXIS2_FALSE);
                                          
                                          if(AXIS2_FAILURE ==  status)
                                          {
                                              AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building element services ");
                                          }
                                          else
                                          {
                                            axutil_array_list_add_at(arr_list, env, i, element);
                                          }
                                        
                                     if(AXIS2_FAILURE ==  status)
                                     {
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for services ");
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
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "services (@minOccurs = '0') only have %d elements", i);
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
                                    status = adb_ServiceGroupMetaData_set_services(_ServiceGroupMetaData, env,
                                                                   arr_list);
                               }

                             
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 
          return status;
       }

          axis2_bool_t AXIS2_CALL
          adb_ServiceGroupMetaData_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_ServiceGroupMetaData_declare_parent_namespaces(
                    adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_ServiceGroupMetaData_serialize(
                adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
            if (_ServiceGroupMetaData == NULL)
            {
                return adb_ServiceGroupMetaData_serialize_obj(
                    _ServiceGroupMetaData, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            }
            else
            {
                return axis2_extension_mapper_serialize(
                    (adb_type_t*) _ServiceGroupMetaData, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index, "adb_ServiceGroupMetaData");
            }
            
        }

        axiom_node_t* AXIS2_CALL
        adb_ServiceGroupMetaData_serialize_obj(
                adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
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
             
                    axis2_char_t *text_value_1;
                    axis2_char_t *text_value_1_temp;
                    
                    axis2_char_t *text_value_2;
                    axis2_char_t *text_value_2_temp;
                    
                    axis2_char_t *text_value_3;
                    axis2_char_t *text_value_3_temp;
                    
                    axis2_char_t *text_value_4;
                    axis2_char_t *text_value_4_temp;
                    
                    axis2_char_t text_value_5[ADB_DEFAULT_DIGIT_LIMIT];
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _ServiceGroupMetaData, NULL);
            
            
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
              type_attrib = axutil_strcat(env, " ", xsi_prefix, ":type=\"ServiceGroupMetaData\"", NULL);
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
            xsi_type_attri = axiom_attribute_create (env, "type", "ServiceGroupMetaData", xsi_ns);
            
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
                      

                   if (!_ServiceGroupMetaData->is_valid_engagedModules)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("engagedModules"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("engagedModules")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing engagedModules array
                      */
                     if (_ServiceGroupMetaData->property_engagedModules != NULL)
                     {
                        
                            sprintf(start_input_str, "<%s%sengagedModules>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%sengagedModules>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_ServiceGroupMetaData->property_engagedModules, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_ServiceGroupMetaData->property_engagedModules, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing engagedModules element
                      */

                    
                    
                           text_value_1 = (axis2_char_t*)element;
                           
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
                      

                   if (!_ServiceGroupMetaData->is_valid_mtomStatus)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("mtomStatus"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("mtomStatus")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing mtomStatus element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%smtomStatus>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%smtomStatus>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_2 = _ServiceGroupMetaData->property_mtomStatus;
                           
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
                      

                   if (!_ServiceGroupMetaData->is_valid_serviceContextPath)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("serviceContextPath"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("serviceContextPath")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing serviceContextPath element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sserviceContextPath>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sserviceContextPath>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_3 = _ServiceGroupMetaData->property_serviceContextPath;
                           
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
                      

                   if (!_ServiceGroupMetaData->is_valid_serviceGroupName)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("serviceGroupName"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("serviceGroupName")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing serviceGroupName element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sserviceGroupName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sserviceGroupName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_4 = _ServiceGroupMetaData->property_serviceGroupName;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://mgt.service.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://mgt.service.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://mgt.service.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ServiceGroupMetaData->is_valid_services)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("services"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("services")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing services array
                      */
                     if (_ServiceGroupMetaData->property_services != NULL)
                     {
                        

                            sprintf(start_input_str, "<%s%sservices",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%sservices>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_ServiceGroupMetaData->property_services, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_ServiceGroupMetaData->property_services, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing services element
                      */

                    
                     
                            if(!adb_ServiceMetaData_is_particle())
                            {
                                axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                            }
                            adb_ServiceMetaData_serialize((adb_ServiceMetaData_t*)element, 
                                                                                 env, current_node, parent_element,
                                                                                 adb_ServiceMetaData_is_particle() || AXIS2_FALSE, namespaces, next_ns_index);
                            
                            if(!adb_ServiceMetaData_is_particle())
                            {
                                axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                            }
                            
                         }
                     }
                   
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 

            return parent;
        }


        

            /**
             * Getter for engagedModules by  Property Number 1
             */
            axutil_array_list_t* AXIS2_CALL
            adb_ServiceGroupMetaData_get_property1(
                adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                const axutil_env_t *env)
            {
                return adb_ServiceGroupMetaData_get_engagedModules(_ServiceGroupMetaData,
                                             env);
            }

            /**
             * getter for engagedModules.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_ServiceGroupMetaData_get_engagedModules(
                    adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServiceGroupMetaData, NULL);
                  

                return _ServiceGroupMetaData->property_engagedModules;
             }

            /**
             * setter for engagedModules
             */
            axis2_status_t AXIS2_CALL
            adb_ServiceGroupMetaData_set_engagedModules(
                    adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_engagedModules)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServiceGroupMetaData, AXIS2_FAILURE);
                
                if(_ServiceGroupMetaData->is_valid_engagedModules &&
                        arg_engagedModules == _ServiceGroupMetaData->property_engagedModules)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_engagedModules, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "engagedModules has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_engagedModules, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_ServiceGroupMetaData_reset_engagedModules(_ServiceGroupMetaData, env);

                
                if(NULL == arg_engagedModules)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServiceGroupMetaData->property_engagedModules = arg_engagedModules;
                        if(non_nil_exists)
                        {
                            _ServiceGroupMetaData->is_valid_engagedModules = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of engagedModules.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServiceGroupMetaData_get_engagedModules_at(
                    adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                    const axutil_env_t *env, int i)
            {
                axis2_char_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServiceGroupMetaData, NULL);
                  

                if(_ServiceGroupMetaData->property_engagedModules == NULL)
                {
                    return (axis2_char_t*)0;
                }
                ret_val = (axis2_char_t*)axutil_array_list_get(_ServiceGroupMetaData->property_engagedModules, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of engagedModules.
             */
            axis2_status_t AXIS2_CALL
            adb_ServiceGroupMetaData_set_engagedModules_at(
                    adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                    const axutil_env_t *env, int i,
                    const axis2_char_t* arg_engagedModules)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServiceGroupMetaData, AXIS2_FAILURE);
                
                if( _ServiceGroupMetaData->is_valid_engagedModules &&
                    _ServiceGroupMetaData->property_engagedModules &&
                
                    arg_engagedModules == (axis2_char_t*)axutil_array_list_get(_ServiceGroupMetaData->property_engagedModules, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_engagedModules)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_ServiceGroupMetaData->property_engagedModules != NULL)
                        {
                            size = axutil_array_list_size(_ServiceGroupMetaData->property_engagedModules, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_ServiceGroupMetaData->property_engagedModules, env, i))
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
                  

                if(_ServiceGroupMetaData->property_engagedModules == NULL)
                {
                    _ServiceGroupMetaData->property_engagedModules = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_ServiceGroupMetaData->property_engagedModules, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _ServiceGroupMetaData->is_valid_engagedModules = AXIS2_FALSE;
                        axutil_array_list_set(_ServiceGroupMetaData->property_engagedModules , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_ServiceGroupMetaData->property_engagedModules , env, i, axutil_strdup(env, arg_engagedModules));
                  _ServiceGroupMetaData->is_valid_engagedModules = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to engagedModules.
             */
            axis2_status_t AXIS2_CALL
            adb_ServiceGroupMetaData_add_engagedModules(
                    adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                    const axutil_env_t *env,
                    const axis2_char_t* arg_engagedModules)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServiceGroupMetaData, AXIS2_FAILURE);

                
                    if(NULL == arg_engagedModules)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_ServiceGroupMetaData->property_engagedModules == NULL)
                {
                    _ServiceGroupMetaData->property_engagedModules = axutil_array_list_create(env, 10);
                }
                if(_ServiceGroupMetaData->property_engagedModules == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for engagedModules");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_ServiceGroupMetaData->property_engagedModules , env, axutil_strdup(env, arg_engagedModules));
                  _ServiceGroupMetaData->is_valid_engagedModules = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the engagedModules array.
             */
            int AXIS2_CALL
            adb_ServiceGroupMetaData_sizeof_engagedModules(
                    adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _ServiceGroupMetaData, -1);
                if(_ServiceGroupMetaData->property_engagedModules == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_ServiceGroupMetaData->property_engagedModules, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_ServiceGroupMetaData_remove_engagedModules_at(
                    adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                    const axutil_env_t *env, int i)
            {
                return adb_ServiceGroupMetaData_set_engagedModules_nil_at(_ServiceGroupMetaData, env, i);
            }

            

           /**
            * resetter for engagedModules
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceGroupMetaData_reset_engagedModules(
                   adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServiceGroupMetaData, AXIS2_FAILURE);
               

               
                  if (_ServiceGroupMetaData->property_engagedModules != NULL)
                  {
                      count = axutil_array_list_size(_ServiceGroupMetaData->property_engagedModules, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_ServiceGroupMetaData->property_engagedModules, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, (axis2_char_t*)element);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_ServiceGroupMetaData->property_engagedModules, env);
                  }
                _ServiceGroupMetaData->is_valid_engagedModules = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether engagedModules is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServiceGroupMetaData_is_engagedModules_nil(
                   adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServiceGroupMetaData, AXIS2_TRUE);
               
               return !_ServiceGroupMetaData->is_valid_engagedModules;
           }

           /**
            * Set engagedModules to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceGroupMetaData_set_engagedModules_nil(
                   adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                   const axutil_env_t *env)
           {
               return adb_ServiceGroupMetaData_reset_engagedModules(_ServiceGroupMetaData, env);
           }

           
           /**
            * Check whether engagedModules is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_ServiceGroupMetaData_is_engagedModules_nil_at(
                   adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServiceGroupMetaData, AXIS2_TRUE);
               
               return (_ServiceGroupMetaData->is_valid_engagedModules == AXIS2_FALSE ||
                        NULL == _ServiceGroupMetaData->property_engagedModules || 
                        NULL == axutil_array_list_get(_ServiceGroupMetaData->property_engagedModules, env, i));
           }

           /**
            * Set engagedModules to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceGroupMetaData_set_engagedModules_nil_at(
                   adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServiceGroupMetaData, AXIS2_FAILURE);

                if(_ServiceGroupMetaData->property_engagedModules == NULL ||
                            _ServiceGroupMetaData->is_valid_engagedModules == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_ServiceGroupMetaData->property_engagedModules, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_ServiceGroupMetaData->property_engagedModules, env, i))
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
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of engagedModules is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_ServiceGroupMetaData->property_engagedModules == NULL)
                {
                    _ServiceGroupMetaData->is_valid_engagedModules = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_ServiceGroupMetaData->property_engagedModules, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _ServiceGroupMetaData->is_valid_engagedModules = AXIS2_FALSE;
                        axutil_array_list_set(_ServiceGroupMetaData->property_engagedModules , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_ServiceGroupMetaData->property_engagedModules , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

            /**
             * Getter for mtomStatus by  Property Number 2
             */
            axis2_char_t* AXIS2_CALL
            adb_ServiceGroupMetaData_get_property2(
                adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                const axutil_env_t *env)
            {
                return adb_ServiceGroupMetaData_get_mtomStatus(_ServiceGroupMetaData,
                                             env);
            }

            /**
             * getter for mtomStatus.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServiceGroupMetaData_get_mtomStatus(
                    adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServiceGroupMetaData, NULL);
                  

                return _ServiceGroupMetaData->property_mtomStatus;
             }

            /**
             * setter for mtomStatus
             */
            axis2_status_t AXIS2_CALL
            adb_ServiceGroupMetaData_set_mtomStatus(
                    adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_mtomStatus)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServiceGroupMetaData, AXIS2_FAILURE);
                
                if(_ServiceGroupMetaData->is_valid_mtomStatus &&
                        arg_mtomStatus == _ServiceGroupMetaData->property_mtomStatus)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServiceGroupMetaData_reset_mtomStatus(_ServiceGroupMetaData, env);

                
                if(NULL == arg_mtomStatus)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServiceGroupMetaData->property_mtomStatus = (axis2_char_t *)axutil_strdup(env, arg_mtomStatus);
                        if(NULL == _ServiceGroupMetaData->property_mtomStatus)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for mtomStatus");
                            return AXIS2_FAILURE;
                        }
                        _ServiceGroupMetaData->is_valid_mtomStatus = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for mtomStatus
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceGroupMetaData_reset_mtomStatus(
                   adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServiceGroupMetaData, AXIS2_FAILURE);
               

               
            
                
                if(_ServiceGroupMetaData->property_mtomStatus != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ServiceGroupMetaData->property_mtomStatus);
                     _ServiceGroupMetaData->property_mtomStatus = NULL;
                }
            
                
                
                _ServiceGroupMetaData->is_valid_mtomStatus = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether mtomStatus is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServiceGroupMetaData_is_mtomStatus_nil(
                   adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServiceGroupMetaData, AXIS2_TRUE);
               
               return !_ServiceGroupMetaData->is_valid_mtomStatus;
           }

           /**
            * Set mtomStatus to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceGroupMetaData_set_mtomStatus_nil(
                   adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                   const axutil_env_t *env)
           {
               return adb_ServiceGroupMetaData_reset_mtomStatus(_ServiceGroupMetaData, env);
           }

           

            /**
             * Getter for serviceContextPath by  Property Number 3
             */
            axis2_char_t* AXIS2_CALL
            adb_ServiceGroupMetaData_get_property3(
                adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                const axutil_env_t *env)
            {
                return adb_ServiceGroupMetaData_get_serviceContextPath(_ServiceGroupMetaData,
                                             env);
            }

            /**
             * getter for serviceContextPath.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServiceGroupMetaData_get_serviceContextPath(
                    adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServiceGroupMetaData, NULL);
                  

                return _ServiceGroupMetaData->property_serviceContextPath;
             }

            /**
             * setter for serviceContextPath
             */
            axis2_status_t AXIS2_CALL
            adb_ServiceGroupMetaData_set_serviceContextPath(
                    adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_serviceContextPath)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServiceGroupMetaData, AXIS2_FAILURE);
                
                if(_ServiceGroupMetaData->is_valid_serviceContextPath &&
                        arg_serviceContextPath == _ServiceGroupMetaData->property_serviceContextPath)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServiceGroupMetaData_reset_serviceContextPath(_ServiceGroupMetaData, env);

                
                if(NULL == arg_serviceContextPath)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServiceGroupMetaData->property_serviceContextPath = (axis2_char_t *)axutil_strdup(env, arg_serviceContextPath);
                        if(NULL == _ServiceGroupMetaData->property_serviceContextPath)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for serviceContextPath");
                            return AXIS2_FAILURE;
                        }
                        _ServiceGroupMetaData->is_valid_serviceContextPath = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for serviceContextPath
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceGroupMetaData_reset_serviceContextPath(
                   adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServiceGroupMetaData, AXIS2_FAILURE);
               

               
            
                
                if(_ServiceGroupMetaData->property_serviceContextPath != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ServiceGroupMetaData->property_serviceContextPath);
                     _ServiceGroupMetaData->property_serviceContextPath = NULL;
                }
            
                
                
                _ServiceGroupMetaData->is_valid_serviceContextPath = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether serviceContextPath is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServiceGroupMetaData_is_serviceContextPath_nil(
                   adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServiceGroupMetaData, AXIS2_TRUE);
               
               return !_ServiceGroupMetaData->is_valid_serviceContextPath;
           }

           /**
            * Set serviceContextPath to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceGroupMetaData_set_serviceContextPath_nil(
                   adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                   const axutil_env_t *env)
           {
               return adb_ServiceGroupMetaData_reset_serviceContextPath(_ServiceGroupMetaData, env);
           }

           

            /**
             * Getter for serviceGroupName by  Property Number 4
             */
            axis2_char_t* AXIS2_CALL
            adb_ServiceGroupMetaData_get_property4(
                adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                const axutil_env_t *env)
            {
                return adb_ServiceGroupMetaData_get_serviceGroupName(_ServiceGroupMetaData,
                                             env);
            }

            /**
             * getter for serviceGroupName.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServiceGroupMetaData_get_serviceGroupName(
                    adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServiceGroupMetaData, NULL);
                  

                return _ServiceGroupMetaData->property_serviceGroupName;
             }

            /**
             * setter for serviceGroupName
             */
            axis2_status_t AXIS2_CALL
            adb_ServiceGroupMetaData_set_serviceGroupName(
                    adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_serviceGroupName)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServiceGroupMetaData, AXIS2_FAILURE);
                
                if(_ServiceGroupMetaData->is_valid_serviceGroupName &&
                        arg_serviceGroupName == _ServiceGroupMetaData->property_serviceGroupName)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServiceGroupMetaData_reset_serviceGroupName(_ServiceGroupMetaData, env);

                
                if(NULL == arg_serviceGroupName)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServiceGroupMetaData->property_serviceGroupName = (axis2_char_t *)axutil_strdup(env, arg_serviceGroupName);
                        if(NULL == _ServiceGroupMetaData->property_serviceGroupName)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for serviceGroupName");
                            return AXIS2_FAILURE;
                        }
                        _ServiceGroupMetaData->is_valid_serviceGroupName = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for serviceGroupName
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceGroupMetaData_reset_serviceGroupName(
                   adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServiceGroupMetaData, AXIS2_FAILURE);
               

               
            
                
                if(_ServiceGroupMetaData->property_serviceGroupName != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ServiceGroupMetaData->property_serviceGroupName);
                     _ServiceGroupMetaData->property_serviceGroupName = NULL;
                }
            
                
                
                _ServiceGroupMetaData->is_valid_serviceGroupName = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether serviceGroupName is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServiceGroupMetaData_is_serviceGroupName_nil(
                   adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServiceGroupMetaData, AXIS2_TRUE);
               
               return !_ServiceGroupMetaData->is_valid_serviceGroupName;
           }

           /**
            * Set serviceGroupName to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceGroupMetaData_set_serviceGroupName_nil(
                   adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                   const axutil_env_t *env)
           {
               return adb_ServiceGroupMetaData_reset_serviceGroupName(_ServiceGroupMetaData, env);
           }

           

            /**
             * Getter for services by  Property Number 5
             */
            axutil_array_list_t* AXIS2_CALL
            adb_ServiceGroupMetaData_get_property5(
                adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                const axutil_env_t *env)
            {
                return adb_ServiceGroupMetaData_get_services(_ServiceGroupMetaData,
                                             env);
            }

            /**
             * getter for services.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_ServiceGroupMetaData_get_services(
                    adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServiceGroupMetaData, NULL);
                  

                return _ServiceGroupMetaData->property_services;
             }

            /**
             * setter for services
             */
            axis2_status_t AXIS2_CALL
            adb_ServiceGroupMetaData_set_services(
                    adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_services)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServiceGroupMetaData, AXIS2_FAILURE);
                
                if(_ServiceGroupMetaData->is_valid_services &&
                        arg_services == _ServiceGroupMetaData->property_services)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_services, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "services has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_services, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_ServiceGroupMetaData_reset_services(_ServiceGroupMetaData, env);

                
                if(NULL == arg_services)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServiceGroupMetaData->property_services = arg_services;
                        if(non_nil_exists)
                        {
                            _ServiceGroupMetaData->is_valid_services = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of services.
             */
            adb_ServiceMetaData_t* AXIS2_CALL
            adb_ServiceGroupMetaData_get_services_at(
                    adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                    const axutil_env_t *env, int i)
            {
                adb_ServiceMetaData_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServiceGroupMetaData, NULL);
                  

                if(_ServiceGroupMetaData->property_services == NULL)
                {
                    return (adb_ServiceMetaData_t*)0;
                }
                ret_val = (adb_ServiceMetaData_t*)axutil_array_list_get(_ServiceGroupMetaData->property_services, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of services.
             */
            axis2_status_t AXIS2_CALL
            adb_ServiceGroupMetaData_set_services_at(
                    adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                    const axutil_env_t *env, int i,
                    adb_ServiceMetaData_t* arg_services)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServiceGroupMetaData, AXIS2_FAILURE);
                
                if( _ServiceGroupMetaData->is_valid_services &&
                    _ServiceGroupMetaData->property_services &&
                
                    arg_services == (adb_ServiceMetaData_t*)axutil_array_list_get(_ServiceGroupMetaData->property_services, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_services)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_ServiceGroupMetaData->property_services != NULL)
                        {
                            size = axutil_array_list_size(_ServiceGroupMetaData->property_services, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_ServiceGroupMetaData->property_services, env, i))
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
                  

                if(_ServiceGroupMetaData->property_services == NULL)
                {
                    _ServiceGroupMetaData->property_services = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_ServiceGroupMetaData->property_services, env, i);
                if(NULL != element)
                {
                  
                  
                  adb_ServiceMetaData_free((adb_ServiceMetaData_t*)element, env);
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _ServiceGroupMetaData->is_valid_services = AXIS2_FALSE;
                        axutil_array_list_set(_ServiceGroupMetaData->property_services , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_ServiceGroupMetaData->property_services , env, i, arg_services);
                  _ServiceGroupMetaData->is_valid_services = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to services.
             */
            axis2_status_t AXIS2_CALL
            adb_ServiceGroupMetaData_add_services(
                    adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                    const axutil_env_t *env,
                    adb_ServiceMetaData_t* arg_services)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServiceGroupMetaData, AXIS2_FAILURE);

                
                    if(NULL == arg_services)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_ServiceGroupMetaData->property_services == NULL)
                {
                    _ServiceGroupMetaData->property_services = axutil_array_list_create(env, 10);
                }
                if(_ServiceGroupMetaData->property_services == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for services");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_ServiceGroupMetaData->property_services , env, arg_services);
                  _ServiceGroupMetaData->is_valid_services = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the services array.
             */
            int AXIS2_CALL
            adb_ServiceGroupMetaData_sizeof_services(
                    adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _ServiceGroupMetaData, -1);
                if(_ServiceGroupMetaData->property_services == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_ServiceGroupMetaData->property_services, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_ServiceGroupMetaData_remove_services_at(
                    adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                    const axutil_env_t *env, int i)
            {
                return adb_ServiceGroupMetaData_set_services_nil_at(_ServiceGroupMetaData, env, i);
            }

            

           /**
            * resetter for services
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceGroupMetaData_reset_services(
                   adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServiceGroupMetaData, AXIS2_FAILURE);
               

               
                  if (_ServiceGroupMetaData->property_services != NULL)
                  {
                      count = axutil_array_list_size(_ServiceGroupMetaData->property_services, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_ServiceGroupMetaData->property_services, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   adb_ServiceMetaData_free((adb_ServiceMetaData_t*)element, env);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_ServiceGroupMetaData->property_services, env);
                  }
                _ServiceGroupMetaData->is_valid_services = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether services is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServiceGroupMetaData_is_services_nil(
                   adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServiceGroupMetaData, AXIS2_TRUE);
               
               return !_ServiceGroupMetaData->is_valid_services;
           }

           /**
            * Set services to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceGroupMetaData_set_services_nil(
                   adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                   const axutil_env_t *env)
           {
               return adb_ServiceGroupMetaData_reset_services(_ServiceGroupMetaData, env);
           }

           
           /**
            * Check whether services is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_ServiceGroupMetaData_is_services_nil_at(
                   adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServiceGroupMetaData, AXIS2_TRUE);
               
               return (_ServiceGroupMetaData->is_valid_services == AXIS2_FALSE ||
                        NULL == _ServiceGroupMetaData->property_services || 
                        NULL == axutil_array_list_get(_ServiceGroupMetaData->property_services, env, i));
           }

           /**
            * Set services to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceGroupMetaData_set_services_nil_at(
                   adb_ServiceGroupMetaData_t* _ServiceGroupMetaData,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServiceGroupMetaData, AXIS2_FAILURE);

                if(_ServiceGroupMetaData->property_services == NULL ||
                            _ServiceGroupMetaData->is_valid_services == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_ServiceGroupMetaData->property_services, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_ServiceGroupMetaData->property_services, env, i))
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
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of services is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_ServiceGroupMetaData->property_services == NULL)
                {
                    _ServiceGroupMetaData->is_valid_services = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_ServiceGroupMetaData->property_services, env, i);
                if(NULL != element)
                {
                  
                  
                  adb_ServiceMetaData_free((adb_ServiceMetaData_t*)element, env);
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _ServiceGroupMetaData->is_valid_services = AXIS2_FALSE;
                        axutil_array_list_set(_ServiceGroupMetaData->property_services , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_ServiceGroupMetaData->property_services , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

