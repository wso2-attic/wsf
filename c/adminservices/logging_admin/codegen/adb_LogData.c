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
         * adb_LogData.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_LogData.h"
        
                /*
                 * This type was generated from the piece of schema that had
                 * name = LogData
                 * Namespace URI = http://data.service.logging.carbon.wso2.org/xsd
                 * Namespace Prefix = ns1
                 */
           


        struct adb_LogData
        {
            axis2_char_t *property_Type;

            axutil_array_list_t* property_appenderData;

                
                axis2_bool_t is_valid_appenderData;
            axis2_char_t* property_logFile;

                
                axis2_bool_t is_valid_logFile;
            axis2_char_t* property_logLevel;

                
                axis2_bool_t is_valid_logLevel;
            axis2_char_t* property_logPattern;

                
                axis2_bool_t is_valid_logPattern;
            axutil_array_list_t* property_loggerData;

                
                axis2_bool_t is_valid_loggerData;
            adb_AppenderData_t* property_selectedAppenderData;

                
                axis2_bool_t is_valid_selectedAppenderData;
            adb_LoggerData_t* property_selectedLoggerData;

                
                axis2_bool_t is_valid_selectedLoggerData;
            
        };


       /************************* Private Function prototypes ********************************/
        


       /************************* Function Implmentations ********************************/
        adb_LogData_t* AXIS2_CALL
        adb_LogData_create(
            const axutil_env_t *env)
        {
            adb_LogData_t *_LogData = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _LogData = (adb_LogData_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_LogData_t));

            if(NULL == _LogData)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_LogData, 0, sizeof(adb_LogData_t));

            _LogData->property_Type = axutil_strdup(env, "adb_LogData");
            _LogData->property_appenderData  = NULL;
                  _LogData->is_valid_appenderData  = AXIS2_FALSE;
            _LogData->property_logFile  = NULL;
                  _LogData->is_valid_logFile  = AXIS2_FALSE;
            _LogData->property_logLevel  = NULL;
                  _LogData->is_valid_logLevel  = AXIS2_FALSE;
            _LogData->property_logPattern  = NULL;
                  _LogData->is_valid_logPattern  = AXIS2_FALSE;
            _LogData->property_loggerData  = NULL;
                  _LogData->is_valid_loggerData  = AXIS2_FALSE;
            _LogData->property_selectedAppenderData  = NULL;
                  _LogData->is_valid_selectedAppenderData  = AXIS2_FALSE;
            _LogData->property_selectedLoggerData  = NULL;
                  _LogData->is_valid_selectedLoggerData  = AXIS2_FALSE;
            

            return _LogData;
        }

        adb_LogData_t* AXIS2_CALL
        adb_LogData_create_with_values(
            const axutil_env_t *env,
                axutil_array_list_t* _appenderData,
                axis2_char_t* _logFile,
                axis2_char_t* _logLevel,
                axis2_char_t* _logPattern,
                axutil_array_list_t* _loggerData,
                adb_AppenderData_t* _selectedAppenderData,
                adb_LoggerData_t* _selectedLoggerData)
        {
            adb_LogData_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_LogData_create(env);

            
              status = adb_LogData_set_appenderData(
                                     adb_obj,
                                     env,
                                     _appenderData);
              if(status == AXIS2_FAILURE) {
                  adb_LogData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_LogData_set_logFile(
                                     adb_obj,
                                     env,
                                     _logFile);
              if(status == AXIS2_FAILURE) {
                  adb_LogData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_LogData_set_logLevel(
                                     adb_obj,
                                     env,
                                     _logLevel);
              if(status == AXIS2_FAILURE) {
                  adb_LogData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_LogData_set_logPattern(
                                     adb_obj,
                                     env,
                                     _logPattern);
              if(status == AXIS2_FAILURE) {
                  adb_LogData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_LogData_set_loggerData(
                                     adb_obj,
                                     env,
                                     _loggerData);
              if(status == AXIS2_FAILURE) {
                  adb_LogData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_LogData_set_selectedAppenderData(
                                     adb_obj,
                                     env,
                                     _selectedAppenderData);
              if(status == AXIS2_FAILURE) {
                  adb_LogData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_LogData_set_selectedLoggerData(
                                     adb_obj,
                                     env,
                                     _selectedLoggerData);
              if(status == AXIS2_FAILURE) {
                  adb_LogData_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axutil_array_list_t* AXIS2_CALL
                adb_LogData_free_popping_value(
                        adb_LogData_t* _LogData,
                        const axutil_env_t *env)
                {
                    axutil_array_list_t* value;

                    
                    
                    value = _LogData->property_appenderData;

                    _LogData->property_appenderData = (axutil_array_list_t*)NULL;
                    adb_LogData_free(_LogData, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_LogData_free(
                adb_LogData_t* _LogData,
                const axutil_env_t *env)
        {
            
            
            return axis2_extension_mapper_free(
                (adb_type_t*) _LogData,
                env,
                "adb_LogData");
            
        }

        axis2_status_t AXIS2_CALL
        adb_LogData_free_obj(
                adb_LogData_t* _LogData,
                const axutil_env_t *env)
        {
            
                int i = 0;
                int count = 0;
                void *element = NULL;
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _LogData, AXIS2_FAILURE);

            if (_LogData->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _LogData->property_Type);
            }

            adb_LogData_reset_appenderData(_LogData, env);
            adb_LogData_reset_logFile(_LogData, env);
            adb_LogData_reset_logLevel(_LogData, env);
            adb_LogData_reset_logPattern(_LogData, env);
            adb_LogData_reset_loggerData(_LogData, env);
            adb_LogData_reset_selectedAppenderData(_LogData, env);
            adb_LogData_reset_selectedLoggerData(_LogData, env);
            

            if(_LogData)
            {
                AXIS2_FREE(env->allocator, _LogData);
                _LogData = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_LogData_deserialize(
                adb_LogData_t* _LogData,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return axis2_extension_mapper_deserialize(
                (adb_type_t*) _LogData,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs,
                "adb_LogData");
            
        }

        axis2_status_t AXIS2_CALL
        adb_LogData_deserialize_obj(
                adb_LogData_t* _LogData,
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
            AXIS2_PARAM_CHECK(env->error, _LogData, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for LogData : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              
                      
                      first_node = axiom_node_get_first_child(parent, env);
                      
                    
                    /*
                     * building appenderData array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building appenderData element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "appenderData", "http://data.service.logging.carbon.wso2.org/xsd", NULL);
                                  
                               
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

                                  if (adb_AppenderData_is_particle() ||  
                                    (current_node && current_element && (axutil_qname_equals(element_qname, env, qname))))
                                  {
                                  
                                      if( current_node && current_element && (axutil_qname_equals(element_qname, env, qname)))
                                      {
                                          is_early_node_valid = AXIS2_TRUE;
                                      }
                                      
                                     
                                          element = (void*)axis2_extension_mapper_create_from_node(env, &current_node, "adb_AppenderData");
                                          
                                          status =  adb_AppenderData_deserialize((adb_AppenderData_t*)element, env,
                                                                                 &current_node, &is_early_node_valid, AXIS2_FALSE);
                                          
                                          if(AXIS2_FAILURE ==  status)
                                          {
                                              AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building element appenderData ");
                                          }
                                          else
                                          {
                                            axutil_array_list_add_at(arr_list, env, i, element);
                                          }
                                        
                                     if(AXIS2_FAILURE ==  status)
                                     {
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for appenderData ");
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
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "appenderData (@minOccurs = '0') only have %d elements", i);
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
                                    status = adb_LogData_set_appenderData(_LogData, env,
                                                                   arr_list);
                               }

                             
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 

                     
                     /*
                      * building logFile element
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
                                 
                                 element_qname = axutil_qname_create(env, "logFile", "http://data.service.logging.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_LogData_set_logFile(_LogData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for logFile ");
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
                      * building logLevel element
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
                                 
                                 element_qname = axutil_qname_create(env, "logLevel", "http://data.service.logging.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_LogData_set_logLevel(_LogData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for logLevel ");
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
                      * building logPattern element
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
                                 
                                 element_qname = axutil_qname_create(env, "logPattern", "http://data.service.logging.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_LogData_set_logPattern(_LogData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for logPattern ");
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
                     * building loggerData array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building loggerData element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "loggerData", "http://data.service.logging.carbon.wso2.org/xsd", NULL);
                                  
                               
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

                                  if (adb_LoggerData_is_particle() ||  
                                    (current_node && current_element && (axutil_qname_equals(element_qname, env, qname))))
                                  {
                                  
                                      if( current_node && current_element && (axutil_qname_equals(element_qname, env, qname)))
                                      {
                                          is_early_node_valid = AXIS2_TRUE;
                                      }
                                      
                                     
                                          element = (void*)axis2_extension_mapper_create_from_node(env, &current_node, "adb_LoggerData");
                                          
                                          status =  adb_LoggerData_deserialize((adb_LoggerData_t*)element, env,
                                                                                 &current_node, &is_early_node_valid, AXIS2_FALSE);
                                          
                                          if(AXIS2_FAILURE ==  status)
                                          {
                                              AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building element loggerData ");
                                          }
                                          else
                                          {
                                            axutil_array_list_add_at(arr_list, env, i, element);
                                          }
                                        
                                     if(AXIS2_FAILURE ==  status)
                                     {
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for loggerData ");
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
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "loggerData (@minOccurs = '0') only have %d elements", i);
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
                                    status = adb_LogData_set_loggerData(_LogData, env,
                                                                   arr_list);
                               }

                             
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 

                     
                     /*
                      * building selectedAppenderData element
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
                                 
                                 element_qname = axutil_qname_create(env, "selectedAppenderData", "http://data.service.logging.carbon.wso2.org/xsd", NULL);
                                 

                           if (adb_AppenderData_is_particle() ||  
                                (current_node   && current_element && (axutil_qname_equals(element_qname, env, qname))))
                           {
                              if( current_node   && current_element && (axutil_qname_equals(element_qname, env, qname)))
                              {
                                is_early_node_valid = AXIS2_TRUE;
                              }
                              
                                 
                                      element = (void*)axis2_extension_mapper_create_from_node(env, &current_node, "adb_AppenderData");

                                      status =  adb_AppenderData_deserialize((adb_AppenderData_t*)element,
                                                                            env, &current_node, &is_early_node_valid, AXIS2_FALSE);
                                      if(AXIS2_FAILURE == status)
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building adb object for element selectedAppenderData");
                                      }
                                      else
                                      {
                                          status = adb_LogData_set_selectedAppenderData(_LogData, env,
                                                                   (adb_AppenderData_t*)element);
                                      }
                                    
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for selectedAppenderData ");
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
                      * building selectedLoggerData element
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
                                 
                                 element_qname = axutil_qname_create(env, "selectedLoggerData", "http://data.service.logging.carbon.wso2.org/xsd", NULL);
                                 

                           if (adb_LoggerData_is_particle() ||  
                                (current_node   && current_element && (axutil_qname_equals(element_qname, env, qname))))
                           {
                              if( current_node   && current_element && (axutil_qname_equals(element_qname, env, qname)))
                              {
                                is_early_node_valid = AXIS2_TRUE;
                              }
                              
                                 
                                      element = (void*)axis2_extension_mapper_create_from_node(env, &current_node, "adb_LoggerData");

                                      status =  adb_LoggerData_deserialize((adb_LoggerData_t*)element,
                                                                            env, &current_node, &is_early_node_valid, AXIS2_FALSE);
                                      if(AXIS2_FAILURE == status)
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building adb object for element selectedLoggerData");
                                      }
                                      else
                                      {
                                          status = adb_LogData_set_selectedLoggerData(_LogData, env,
                                                                   (adb_LoggerData_t*)element);
                                      }
                                    
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for selectedLoggerData ");
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
          adb_LogData_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_LogData_declare_parent_namespaces(
                    adb_LogData_t* _LogData,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_LogData_serialize(
                adb_LogData_t* _LogData,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
            if (_LogData == NULL)
            {
                return adb_LogData_serialize_obj(
                    _LogData, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            }
            else
            {
                return axis2_extension_mapper_serialize(
                    (adb_type_t*) _LogData, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index, "adb_LogData");
            }
            
        }

        axiom_node_t* AXIS2_CALL
        adb_LogData_serialize_obj(
                adb_LogData_t* _LogData,
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
                    
                    axis2_char_t *text_value_2;
                    axis2_char_t *text_value_2_temp;
                    
                    axis2_char_t *text_value_3;
                    axis2_char_t *text_value_3_temp;
                    
                    axis2_char_t *text_value_4;
                    axis2_char_t *text_value_4_temp;
                    
                    axis2_char_t text_value_5[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t text_value_6[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t text_value_7[ADB_DEFAULT_DIGIT_LIMIT];
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _LogData, NULL);
            
            
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
              type_attrib = axutil_strcat(env, " ", xsi_prefix, ":type=\"LogData\"", NULL);
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
                                 "http://data.service.logging.carbon.wso2.org/xsd",
                                 xsi_prefix);
            xsi_type_attri = axiom_attribute_create (env, "type", "LogData", xsi_ns);
            
            axiom_element_add_attribute (parent_element, env, xsi_type_attri, parent);
        
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://data.service.logging.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://data.service.logging.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://data.service.logging.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_LogData->is_valid_appenderData)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("appenderData"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("appenderData")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing appenderData array
                      */
                     if (_LogData->property_appenderData != NULL)
                     {
                        

                            sprintf(start_input_str, "<%s%sappenderData",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%sappenderData>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_LogData->property_appenderData, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_LogData->property_appenderData, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing appenderData element
                      */

                    
                     
                            if(!adb_AppenderData_is_particle())
                            {
                                axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                            }
                            adb_AppenderData_serialize((adb_AppenderData_t*)element, 
                                                                                 env, current_node, parent_element,
                                                                                 adb_AppenderData_is_particle() || AXIS2_FALSE, namespaces, next_ns_index);
                            
                            if(!adb_AppenderData_is_particle())
                            {
                                axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                            }
                            
                         }
                     }
                   
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://data.service.logging.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://data.service.logging.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://data.service.logging.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_LogData->is_valid_logFile)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("logFile"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("logFile")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing logFile element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%slogFile>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%slogFile>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_2 = _LogData->property_logFile;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://data.service.logging.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://data.service.logging.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://data.service.logging.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_LogData->is_valid_logLevel)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("logLevel"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("logLevel")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing logLevel element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%slogLevel>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%slogLevel>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_3 = _LogData->property_logLevel;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://data.service.logging.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://data.service.logging.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://data.service.logging.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_LogData->is_valid_logPattern)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("logPattern"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("logPattern")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing logPattern element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%slogPattern>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%slogPattern>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_4 = _LogData->property_logPattern;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://data.service.logging.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://data.service.logging.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://data.service.logging.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_LogData->is_valid_loggerData)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("loggerData"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("loggerData")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing loggerData array
                      */
                     if (_LogData->property_loggerData != NULL)
                     {
                        

                            sprintf(start_input_str, "<%s%sloggerData",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%sloggerData>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_LogData->property_loggerData, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_LogData->property_loggerData, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing loggerData element
                      */

                    
                     
                            if(!adb_LoggerData_is_particle())
                            {
                                axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                            }
                            adb_LoggerData_serialize((adb_LoggerData_t*)element, 
                                                                                 env, current_node, parent_element,
                                                                                 adb_LoggerData_is_particle() || AXIS2_FALSE, namespaces, next_ns_index);
                            
                            if(!adb_LoggerData_is_particle())
                            {
                                axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                            }
                            
                         }
                     }
                   
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://data.service.logging.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://data.service.logging.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://data.service.logging.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_LogData->is_valid_selectedAppenderData)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("selectedAppenderData"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("selectedAppenderData")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing selectedAppenderData element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sselectedAppenderData",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sselectedAppenderData>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                     
                            if(!adb_AppenderData_is_particle())
                            {
                                axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                            }
                            adb_AppenderData_serialize(_LogData->property_selectedAppenderData, 
                                                                                 env, current_node, parent_element,
                                                                                 adb_AppenderData_is_particle() || AXIS2_FALSE, namespaces, next_ns_index);
                            
                            if(!adb_AppenderData_is_particle())
                            {
                                axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                            }
                            
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://data.service.logging.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://data.service.logging.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://data.service.logging.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_LogData->is_valid_selectedLoggerData)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("selectedLoggerData"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("selectedLoggerData")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing selectedLoggerData element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sselectedLoggerData",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sselectedLoggerData>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                     
                            if(!adb_LoggerData_is_particle())
                            {
                                axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                            }
                            adb_LoggerData_serialize(_LogData->property_selectedLoggerData, 
                                                                                 env, current_node, parent_element,
                                                                                 adb_LoggerData_is_particle() || AXIS2_FALSE, namespaces, next_ns_index);
                            
                            if(!adb_LoggerData_is_particle())
                            {
                                axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                            }
                            
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 

            return parent;
        }


        

            /**
             * Getter for appenderData by  Property Number 1
             */
            axutil_array_list_t* AXIS2_CALL
            adb_LogData_get_property1(
                adb_LogData_t* _LogData,
                const axutil_env_t *env)
            {
                return adb_LogData_get_appenderData(_LogData,
                                             env);
            }

            /**
             * getter for appenderData.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_LogData_get_appenderData(
                    adb_LogData_t* _LogData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _LogData, NULL);
                  

                return _LogData->property_appenderData;
             }

            /**
             * setter for appenderData
             */
            axis2_status_t AXIS2_CALL
            adb_LogData_set_appenderData(
                    adb_LogData_t* _LogData,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_appenderData)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _LogData, AXIS2_FAILURE);
                
                if(_LogData->is_valid_appenderData &&
                        arg_appenderData == _LogData->property_appenderData)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_appenderData, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "appenderData has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_appenderData, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_LogData_reset_appenderData(_LogData, env);

                
                if(NULL == arg_appenderData)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _LogData->property_appenderData = arg_appenderData;
                        if(non_nil_exists)
                        {
                            _LogData->is_valid_appenderData = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of appenderData.
             */
            adb_AppenderData_t* AXIS2_CALL
            adb_LogData_get_appenderData_at(
                    adb_LogData_t* _LogData,
                    const axutil_env_t *env, int i)
            {
                adb_AppenderData_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _LogData, NULL);
                  

                if(_LogData->property_appenderData == NULL)
                {
                    return (adb_AppenderData_t*)0;
                }
                ret_val = (adb_AppenderData_t*)axutil_array_list_get(_LogData->property_appenderData, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of appenderData.
             */
            axis2_status_t AXIS2_CALL
            adb_LogData_set_appenderData_at(
                    adb_LogData_t* _LogData,
                    const axutil_env_t *env, int i,
                    adb_AppenderData_t* arg_appenderData)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _LogData, AXIS2_FAILURE);
                
                if( _LogData->is_valid_appenderData &&
                    _LogData->property_appenderData &&
                
                    arg_appenderData == (adb_AppenderData_t*)axutil_array_list_get(_LogData->property_appenderData, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_appenderData)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_LogData->property_appenderData != NULL)
                        {
                            size = axutil_array_list_size(_LogData->property_appenderData, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_LogData->property_appenderData, env, i))
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
                  

                if(_LogData->property_appenderData == NULL)
                {
                    _LogData->property_appenderData = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_LogData->property_appenderData, env, i);
                if(NULL != element)
                {
                  
                  
                  adb_AppenderData_free((adb_AppenderData_t*)element, env);
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _LogData->is_valid_appenderData = AXIS2_FALSE;
                        axutil_array_list_set(_LogData->property_appenderData , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_LogData->property_appenderData , env, i, arg_appenderData);
                  _LogData->is_valid_appenderData = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to appenderData.
             */
            axis2_status_t AXIS2_CALL
            adb_LogData_add_appenderData(
                    adb_LogData_t* _LogData,
                    const axutil_env_t *env,
                    adb_AppenderData_t* arg_appenderData)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _LogData, AXIS2_FAILURE);

                
                    if(NULL == arg_appenderData)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_LogData->property_appenderData == NULL)
                {
                    _LogData->property_appenderData = axutil_array_list_create(env, 10);
                }
                if(_LogData->property_appenderData == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for appenderData");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_LogData->property_appenderData , env, arg_appenderData);
                  _LogData->is_valid_appenderData = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the appenderData array.
             */
            int AXIS2_CALL
            adb_LogData_sizeof_appenderData(
                    adb_LogData_t* _LogData,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _LogData, -1);
                if(_LogData->property_appenderData == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_LogData->property_appenderData, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_LogData_remove_appenderData_at(
                    adb_LogData_t* _LogData,
                    const axutil_env_t *env, int i)
            {
                return adb_LogData_set_appenderData_nil_at(_LogData, env, i);
            }

            

           /**
            * resetter for appenderData
            */
           axis2_status_t AXIS2_CALL
           adb_LogData_reset_appenderData(
                   adb_LogData_t* _LogData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _LogData, AXIS2_FAILURE);
               

               
                  if (_LogData->property_appenderData != NULL)
                  {
                      count = axutil_array_list_size(_LogData->property_appenderData, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_LogData->property_appenderData, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   adb_AppenderData_free((adb_AppenderData_t*)element, env);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_LogData->property_appenderData, env);
                  }
                _LogData->is_valid_appenderData = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether appenderData is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_LogData_is_appenderData_nil(
                   adb_LogData_t* _LogData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _LogData, AXIS2_TRUE);
               
               return !_LogData->is_valid_appenderData;
           }

           /**
            * Set appenderData to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_LogData_set_appenderData_nil(
                   adb_LogData_t* _LogData,
                   const axutil_env_t *env)
           {
               return adb_LogData_reset_appenderData(_LogData, env);
           }

           
           /**
            * Check whether appenderData is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_LogData_is_appenderData_nil_at(
                   adb_LogData_t* _LogData,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _LogData, AXIS2_TRUE);
               
               return (_LogData->is_valid_appenderData == AXIS2_FALSE ||
                        NULL == _LogData->property_appenderData || 
                        NULL == axutil_array_list_get(_LogData->property_appenderData, env, i));
           }

           /**
            * Set appenderData to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_LogData_set_appenderData_nil_at(
                   adb_LogData_t* _LogData,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _LogData, AXIS2_FAILURE);

                if(_LogData->property_appenderData == NULL ||
                            _LogData->is_valid_appenderData == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_LogData->property_appenderData, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_LogData->property_appenderData, env, i))
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
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of appenderData is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_LogData->property_appenderData == NULL)
                {
                    _LogData->is_valid_appenderData = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_LogData->property_appenderData, env, i);
                if(NULL != element)
                {
                  
                  
                  adb_AppenderData_free((adb_AppenderData_t*)element, env);
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _LogData->is_valid_appenderData = AXIS2_FALSE;
                        axutil_array_list_set(_LogData->property_appenderData , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_LogData->property_appenderData , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

            /**
             * Getter for logFile by  Property Number 2
             */
            axis2_char_t* AXIS2_CALL
            adb_LogData_get_property2(
                adb_LogData_t* _LogData,
                const axutil_env_t *env)
            {
                return adb_LogData_get_logFile(_LogData,
                                             env);
            }

            /**
             * getter for logFile.
             */
            axis2_char_t* AXIS2_CALL
            adb_LogData_get_logFile(
                    adb_LogData_t* _LogData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _LogData, NULL);
                  

                return _LogData->property_logFile;
             }

            /**
             * setter for logFile
             */
            axis2_status_t AXIS2_CALL
            adb_LogData_set_logFile(
                    adb_LogData_t* _LogData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_logFile)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _LogData, AXIS2_FAILURE);
                
                if(_LogData->is_valid_logFile &&
                        arg_logFile == _LogData->property_logFile)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_LogData_reset_logFile(_LogData, env);

                
                if(NULL == arg_logFile)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _LogData->property_logFile = (axis2_char_t *)axutil_strdup(env, arg_logFile);
                        if(NULL == _LogData->property_logFile)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for logFile");
                            return AXIS2_FAILURE;
                        }
                        _LogData->is_valid_logFile = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for logFile
            */
           axis2_status_t AXIS2_CALL
           adb_LogData_reset_logFile(
                   adb_LogData_t* _LogData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _LogData, AXIS2_FAILURE);
               

               
            
                
                if(_LogData->property_logFile != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _LogData->property_logFile);
                     _LogData->property_logFile = NULL;
                }
            
                
                
                _LogData->is_valid_logFile = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether logFile is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_LogData_is_logFile_nil(
                   adb_LogData_t* _LogData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _LogData, AXIS2_TRUE);
               
               return !_LogData->is_valid_logFile;
           }

           /**
            * Set logFile to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_LogData_set_logFile_nil(
                   adb_LogData_t* _LogData,
                   const axutil_env_t *env)
           {
               return adb_LogData_reset_logFile(_LogData, env);
           }

           

            /**
             * Getter for logLevel by  Property Number 3
             */
            axis2_char_t* AXIS2_CALL
            adb_LogData_get_property3(
                adb_LogData_t* _LogData,
                const axutil_env_t *env)
            {
                return adb_LogData_get_logLevel(_LogData,
                                             env);
            }

            /**
             * getter for logLevel.
             */
            axis2_char_t* AXIS2_CALL
            adb_LogData_get_logLevel(
                    adb_LogData_t* _LogData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _LogData, NULL);
                  

                return _LogData->property_logLevel;
             }

            /**
             * setter for logLevel
             */
            axis2_status_t AXIS2_CALL
            adb_LogData_set_logLevel(
                    adb_LogData_t* _LogData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_logLevel)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _LogData, AXIS2_FAILURE);
                
                if(_LogData->is_valid_logLevel &&
                        arg_logLevel == _LogData->property_logLevel)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_LogData_reset_logLevel(_LogData, env);

                
                if(NULL == arg_logLevel)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _LogData->property_logLevel = (axis2_char_t *)axutil_strdup(env, arg_logLevel);
                        if(NULL == _LogData->property_logLevel)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for logLevel");
                            return AXIS2_FAILURE;
                        }
                        _LogData->is_valid_logLevel = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for logLevel
            */
           axis2_status_t AXIS2_CALL
           adb_LogData_reset_logLevel(
                   adb_LogData_t* _LogData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _LogData, AXIS2_FAILURE);
               

               
            
                
                if(_LogData->property_logLevel != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _LogData->property_logLevel);
                     _LogData->property_logLevel = NULL;
                }
            
                
                
                _LogData->is_valid_logLevel = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether logLevel is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_LogData_is_logLevel_nil(
                   adb_LogData_t* _LogData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _LogData, AXIS2_TRUE);
               
               return !_LogData->is_valid_logLevel;
           }

           /**
            * Set logLevel to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_LogData_set_logLevel_nil(
                   adb_LogData_t* _LogData,
                   const axutil_env_t *env)
           {
               return adb_LogData_reset_logLevel(_LogData, env);
           }

           

            /**
             * Getter for logPattern by  Property Number 4
             */
            axis2_char_t* AXIS2_CALL
            adb_LogData_get_property4(
                adb_LogData_t* _LogData,
                const axutil_env_t *env)
            {
                return adb_LogData_get_logPattern(_LogData,
                                             env);
            }

            /**
             * getter for logPattern.
             */
            axis2_char_t* AXIS2_CALL
            adb_LogData_get_logPattern(
                    adb_LogData_t* _LogData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _LogData, NULL);
                  

                return _LogData->property_logPattern;
             }

            /**
             * setter for logPattern
             */
            axis2_status_t AXIS2_CALL
            adb_LogData_set_logPattern(
                    adb_LogData_t* _LogData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_logPattern)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _LogData, AXIS2_FAILURE);
                
                if(_LogData->is_valid_logPattern &&
                        arg_logPattern == _LogData->property_logPattern)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_LogData_reset_logPattern(_LogData, env);

                
                if(NULL == arg_logPattern)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _LogData->property_logPattern = (axis2_char_t *)axutil_strdup(env, arg_logPattern);
                        if(NULL == _LogData->property_logPattern)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for logPattern");
                            return AXIS2_FAILURE;
                        }
                        _LogData->is_valid_logPattern = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for logPattern
            */
           axis2_status_t AXIS2_CALL
           adb_LogData_reset_logPattern(
                   adb_LogData_t* _LogData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _LogData, AXIS2_FAILURE);
               

               
            
                
                if(_LogData->property_logPattern != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _LogData->property_logPattern);
                     _LogData->property_logPattern = NULL;
                }
            
                
                
                _LogData->is_valid_logPattern = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether logPattern is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_LogData_is_logPattern_nil(
                   adb_LogData_t* _LogData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _LogData, AXIS2_TRUE);
               
               return !_LogData->is_valid_logPattern;
           }

           /**
            * Set logPattern to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_LogData_set_logPattern_nil(
                   adb_LogData_t* _LogData,
                   const axutil_env_t *env)
           {
               return adb_LogData_reset_logPattern(_LogData, env);
           }

           

            /**
             * Getter for loggerData by  Property Number 5
             */
            axutil_array_list_t* AXIS2_CALL
            adb_LogData_get_property5(
                adb_LogData_t* _LogData,
                const axutil_env_t *env)
            {
                return adb_LogData_get_loggerData(_LogData,
                                             env);
            }

            /**
             * getter for loggerData.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_LogData_get_loggerData(
                    adb_LogData_t* _LogData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _LogData, NULL);
                  

                return _LogData->property_loggerData;
             }

            /**
             * setter for loggerData
             */
            axis2_status_t AXIS2_CALL
            adb_LogData_set_loggerData(
                    adb_LogData_t* _LogData,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_loggerData)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _LogData, AXIS2_FAILURE);
                
                if(_LogData->is_valid_loggerData &&
                        arg_loggerData == _LogData->property_loggerData)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_loggerData, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "loggerData has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_loggerData, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_LogData_reset_loggerData(_LogData, env);

                
                if(NULL == arg_loggerData)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _LogData->property_loggerData = arg_loggerData;
                        if(non_nil_exists)
                        {
                            _LogData->is_valid_loggerData = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of loggerData.
             */
            adb_LoggerData_t* AXIS2_CALL
            adb_LogData_get_loggerData_at(
                    adb_LogData_t* _LogData,
                    const axutil_env_t *env, int i)
            {
                adb_LoggerData_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _LogData, NULL);
                  

                if(_LogData->property_loggerData == NULL)
                {
                    return (adb_LoggerData_t*)0;
                }
                ret_val = (adb_LoggerData_t*)axutil_array_list_get(_LogData->property_loggerData, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of loggerData.
             */
            axis2_status_t AXIS2_CALL
            adb_LogData_set_loggerData_at(
                    adb_LogData_t* _LogData,
                    const axutil_env_t *env, int i,
                    adb_LoggerData_t* arg_loggerData)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _LogData, AXIS2_FAILURE);
                
                if( _LogData->is_valid_loggerData &&
                    _LogData->property_loggerData &&
                
                    arg_loggerData == (adb_LoggerData_t*)axutil_array_list_get(_LogData->property_loggerData, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_loggerData)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_LogData->property_loggerData != NULL)
                        {
                            size = axutil_array_list_size(_LogData->property_loggerData, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_LogData->property_loggerData, env, i))
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
                  

                if(_LogData->property_loggerData == NULL)
                {
                    _LogData->property_loggerData = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_LogData->property_loggerData, env, i);
                if(NULL != element)
                {
                  
                  
                  adb_LoggerData_free((adb_LoggerData_t*)element, env);
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _LogData->is_valid_loggerData = AXIS2_FALSE;
                        axutil_array_list_set(_LogData->property_loggerData , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_LogData->property_loggerData , env, i, arg_loggerData);
                  _LogData->is_valid_loggerData = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to loggerData.
             */
            axis2_status_t AXIS2_CALL
            adb_LogData_add_loggerData(
                    adb_LogData_t* _LogData,
                    const axutil_env_t *env,
                    adb_LoggerData_t* arg_loggerData)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _LogData, AXIS2_FAILURE);

                
                    if(NULL == arg_loggerData)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_LogData->property_loggerData == NULL)
                {
                    _LogData->property_loggerData = axutil_array_list_create(env, 10);
                }
                if(_LogData->property_loggerData == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for loggerData");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_LogData->property_loggerData , env, arg_loggerData);
                  _LogData->is_valid_loggerData = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the loggerData array.
             */
            int AXIS2_CALL
            adb_LogData_sizeof_loggerData(
                    adb_LogData_t* _LogData,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _LogData, -1);
                if(_LogData->property_loggerData == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_LogData->property_loggerData, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_LogData_remove_loggerData_at(
                    adb_LogData_t* _LogData,
                    const axutil_env_t *env, int i)
            {
                return adb_LogData_set_loggerData_nil_at(_LogData, env, i);
            }

            

           /**
            * resetter for loggerData
            */
           axis2_status_t AXIS2_CALL
           adb_LogData_reset_loggerData(
                   adb_LogData_t* _LogData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _LogData, AXIS2_FAILURE);
               

               
                  if (_LogData->property_loggerData != NULL)
                  {
                      count = axutil_array_list_size(_LogData->property_loggerData, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_LogData->property_loggerData, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   adb_LoggerData_free((adb_LoggerData_t*)element, env);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_LogData->property_loggerData, env);
                  }
                _LogData->is_valid_loggerData = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether loggerData is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_LogData_is_loggerData_nil(
                   adb_LogData_t* _LogData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _LogData, AXIS2_TRUE);
               
               return !_LogData->is_valid_loggerData;
           }

           /**
            * Set loggerData to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_LogData_set_loggerData_nil(
                   adb_LogData_t* _LogData,
                   const axutil_env_t *env)
           {
               return adb_LogData_reset_loggerData(_LogData, env);
           }

           
           /**
            * Check whether loggerData is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_LogData_is_loggerData_nil_at(
                   adb_LogData_t* _LogData,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _LogData, AXIS2_TRUE);
               
               return (_LogData->is_valid_loggerData == AXIS2_FALSE ||
                        NULL == _LogData->property_loggerData || 
                        NULL == axutil_array_list_get(_LogData->property_loggerData, env, i));
           }

           /**
            * Set loggerData to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_LogData_set_loggerData_nil_at(
                   adb_LogData_t* _LogData,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _LogData, AXIS2_FAILURE);

                if(_LogData->property_loggerData == NULL ||
                            _LogData->is_valid_loggerData == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_LogData->property_loggerData, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_LogData->property_loggerData, env, i))
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
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of loggerData is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_LogData->property_loggerData == NULL)
                {
                    _LogData->is_valid_loggerData = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_LogData->property_loggerData, env, i);
                if(NULL != element)
                {
                  
                  
                  adb_LoggerData_free((adb_LoggerData_t*)element, env);
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _LogData->is_valid_loggerData = AXIS2_FALSE;
                        axutil_array_list_set(_LogData->property_loggerData , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_LogData->property_loggerData , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

            /**
             * Getter for selectedAppenderData by  Property Number 6
             */
            adb_AppenderData_t* AXIS2_CALL
            adb_LogData_get_property6(
                adb_LogData_t* _LogData,
                const axutil_env_t *env)
            {
                return adb_LogData_get_selectedAppenderData(_LogData,
                                             env);
            }

            /**
             * getter for selectedAppenderData.
             */
            adb_AppenderData_t* AXIS2_CALL
            adb_LogData_get_selectedAppenderData(
                    adb_LogData_t* _LogData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _LogData, NULL);
                  

                return _LogData->property_selectedAppenderData;
             }

            /**
             * setter for selectedAppenderData
             */
            axis2_status_t AXIS2_CALL
            adb_LogData_set_selectedAppenderData(
                    adb_LogData_t* _LogData,
                    const axutil_env_t *env,
                    adb_AppenderData_t*  arg_selectedAppenderData)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _LogData, AXIS2_FAILURE);
                
                if(_LogData->is_valid_selectedAppenderData &&
                        arg_selectedAppenderData == _LogData->property_selectedAppenderData)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_LogData_reset_selectedAppenderData(_LogData, env);

                
                if(NULL == arg_selectedAppenderData)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _LogData->property_selectedAppenderData = arg_selectedAppenderData;
                        _LogData->is_valid_selectedAppenderData = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for selectedAppenderData
            */
           axis2_status_t AXIS2_CALL
           adb_LogData_reset_selectedAppenderData(
                   adb_LogData_t* _LogData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _LogData, AXIS2_FAILURE);
               

               
            
                
                if(_LogData->property_selectedAppenderData != NULL)
                {
                   
                   adb_AppenderData_free(_LogData->property_selectedAppenderData, env);
                     _LogData->property_selectedAppenderData = NULL;
                }
            
                
                
                _LogData->is_valid_selectedAppenderData = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether selectedAppenderData is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_LogData_is_selectedAppenderData_nil(
                   adb_LogData_t* _LogData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _LogData, AXIS2_TRUE);
               
               return !_LogData->is_valid_selectedAppenderData;
           }

           /**
            * Set selectedAppenderData to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_LogData_set_selectedAppenderData_nil(
                   adb_LogData_t* _LogData,
                   const axutil_env_t *env)
           {
               return adb_LogData_reset_selectedAppenderData(_LogData, env);
           }

           

            /**
             * Getter for selectedLoggerData by  Property Number 7
             */
            adb_LoggerData_t* AXIS2_CALL
            adb_LogData_get_property7(
                adb_LogData_t* _LogData,
                const axutil_env_t *env)
            {
                return adb_LogData_get_selectedLoggerData(_LogData,
                                             env);
            }

            /**
             * getter for selectedLoggerData.
             */
            adb_LoggerData_t* AXIS2_CALL
            adb_LogData_get_selectedLoggerData(
                    adb_LogData_t* _LogData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _LogData, NULL);
                  

                return _LogData->property_selectedLoggerData;
             }

            /**
             * setter for selectedLoggerData
             */
            axis2_status_t AXIS2_CALL
            adb_LogData_set_selectedLoggerData(
                    adb_LogData_t* _LogData,
                    const axutil_env_t *env,
                    adb_LoggerData_t*  arg_selectedLoggerData)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _LogData, AXIS2_FAILURE);
                
                if(_LogData->is_valid_selectedLoggerData &&
                        arg_selectedLoggerData == _LogData->property_selectedLoggerData)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_LogData_reset_selectedLoggerData(_LogData, env);

                
                if(NULL == arg_selectedLoggerData)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _LogData->property_selectedLoggerData = arg_selectedLoggerData;
                        _LogData->is_valid_selectedLoggerData = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for selectedLoggerData
            */
           axis2_status_t AXIS2_CALL
           adb_LogData_reset_selectedLoggerData(
                   adb_LogData_t* _LogData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _LogData, AXIS2_FAILURE);
               

               
            
                
                if(_LogData->property_selectedLoggerData != NULL)
                {
                   
                   adb_LoggerData_free(_LogData->property_selectedLoggerData, env);
                     _LogData->property_selectedLoggerData = NULL;
                }
            
                
                
                _LogData->is_valid_selectedLoggerData = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether selectedLoggerData is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_LogData_is_selectedLoggerData_nil(
                   adb_LogData_t* _LogData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _LogData, AXIS2_TRUE);
               
               return !_LogData->is_valid_selectedLoggerData;
           }

           /**
            * Set selectedLoggerData to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_LogData_set_selectedLoggerData_nil(
                   adb_LogData_t* _LogData,
                   const axutil_env_t *env)
           {
               return adb_LogData_reset_selectedLoggerData(_LogData, env);
           }

           

