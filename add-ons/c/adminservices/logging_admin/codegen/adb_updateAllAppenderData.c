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
         * adb_updateAllAppenderData.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_updateAllAppenderData.h"
        
               /*
                * implmentation of the updateAllAppenderData|http://org.apache.axis2/xsd element
                */
           


        struct adb_updateAllAppenderData
        {
            axis2_char_t *property_Type;

            
                axutil_qname_t* qname;
            axis2_char_t* property_appenderName;

                
                axis2_bool_t is_valid_appenderName;
            axis2_char_t* property_appenderPattern;

                
                axis2_bool_t is_valid_appenderPattern;
            axis2_char_t* property_threshold;

                
                axis2_bool_t is_valid_threshold;
            axis2_char_t* property_logFileName;

                
                axis2_bool_t is_valid_logFileName;
            axis2_char_t* property_sysLogHost;

                
                axis2_bool_t is_valid_sysLogHost;
            axis2_char_t* property_facility;

                
                axis2_bool_t is_valid_facility;
            axis2_bool_t property_persist;

                
                axis2_bool_t is_valid_persist;
            
        };


       /************************* Private Function prototypes ********************************/
        

                axis2_status_t AXIS2_CALL
                adb_updateAllAppenderData_set_persist_nil(
                        adb_updateAllAppenderData_t* _updateAllAppenderData,
                        const axutil_env_t *env);
            


       /************************* Function Implmentations ********************************/
        adb_updateAllAppenderData_t* AXIS2_CALL
        adb_updateAllAppenderData_create(
            const axutil_env_t *env)
        {
            adb_updateAllAppenderData_t *_updateAllAppenderData = NULL;
            
                axutil_qname_t* qname = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _updateAllAppenderData = (adb_updateAllAppenderData_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_updateAllAppenderData_t));

            if(NULL == _updateAllAppenderData)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_updateAllAppenderData, 0, sizeof(adb_updateAllAppenderData_t));

            _updateAllAppenderData->property_Type = axutil_strdup(env, "adb_updateAllAppenderData");
            _updateAllAppenderData->property_appenderName  = NULL;
                  _updateAllAppenderData->is_valid_appenderName  = AXIS2_FALSE;
            _updateAllAppenderData->property_appenderPattern  = NULL;
                  _updateAllAppenderData->is_valid_appenderPattern  = AXIS2_FALSE;
            _updateAllAppenderData->property_threshold  = NULL;
                  _updateAllAppenderData->is_valid_threshold  = AXIS2_FALSE;
            _updateAllAppenderData->property_logFileName  = NULL;
                  _updateAllAppenderData->is_valid_logFileName  = AXIS2_FALSE;
            _updateAllAppenderData->property_sysLogHost  = NULL;
                  _updateAllAppenderData->is_valid_sysLogHost  = AXIS2_FALSE;
            _updateAllAppenderData->property_facility  = NULL;
                  _updateAllAppenderData->is_valid_facility  = AXIS2_FALSE;
            _updateAllAppenderData->is_valid_persist  = AXIS2_FALSE;
            
                  qname =  axutil_qname_create (env,
                        "updateAllAppenderData",
                        "http://org.apache.axis2/xsd",
                        NULL);
                _updateAllAppenderData->qname = qname;
            

            return _updateAllAppenderData;
        }

        adb_updateAllAppenderData_t* AXIS2_CALL
        adb_updateAllAppenderData_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _appenderName,
                axis2_char_t* _appenderPattern,
                axis2_char_t* _threshold,
                axis2_char_t* _logFileName,
                axis2_char_t* _sysLogHost,
                axis2_char_t* _facility,
                axis2_bool_t _persist)
        {
            adb_updateAllAppenderData_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_updateAllAppenderData_create(env);

            
              status = adb_updateAllAppenderData_set_appenderName(
                                     adb_obj,
                                     env,
                                     _appenderName);
              if(status == AXIS2_FAILURE) {
                  adb_updateAllAppenderData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_updateAllAppenderData_set_appenderPattern(
                                     adb_obj,
                                     env,
                                     _appenderPattern);
              if(status == AXIS2_FAILURE) {
                  adb_updateAllAppenderData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_updateAllAppenderData_set_threshold(
                                     adb_obj,
                                     env,
                                     _threshold);
              if(status == AXIS2_FAILURE) {
                  adb_updateAllAppenderData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_updateAllAppenderData_set_logFileName(
                                     adb_obj,
                                     env,
                                     _logFileName);
              if(status == AXIS2_FAILURE) {
                  adb_updateAllAppenderData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_updateAllAppenderData_set_sysLogHost(
                                     adb_obj,
                                     env,
                                     _sysLogHost);
              if(status == AXIS2_FAILURE) {
                  adb_updateAllAppenderData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_updateAllAppenderData_set_facility(
                                     adb_obj,
                                     env,
                                     _facility);
              if(status == AXIS2_FAILURE) {
                  adb_updateAllAppenderData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_updateAllAppenderData_set_persist(
                                     adb_obj,
                                     env,
                                     _persist);
              if(status == AXIS2_FAILURE) {
                  adb_updateAllAppenderData_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_char_t* AXIS2_CALL
                adb_updateAllAppenderData_free_popping_value(
                        adb_updateAllAppenderData_t* _updateAllAppenderData,
                        const axutil_env_t *env)
                {
                    axis2_char_t* value;

                    
                    
                    value = _updateAllAppenderData->property_appenderName;

                    _updateAllAppenderData->property_appenderName = (axis2_char_t*)NULL;
                    adb_updateAllAppenderData_free(_updateAllAppenderData, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_updateAllAppenderData_free(
                adb_updateAllAppenderData_t* _updateAllAppenderData,
                const axutil_env_t *env)
        {
            
            
            return adb_updateAllAppenderData_free_obj(
                _updateAllAppenderData,
                env);
            
        }

        axis2_status_t AXIS2_CALL
        adb_updateAllAppenderData_free_obj(
                adb_updateAllAppenderData_t* _updateAllAppenderData,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _updateAllAppenderData, AXIS2_FAILURE);

            if (_updateAllAppenderData->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _updateAllAppenderData->property_Type);
            }

            adb_updateAllAppenderData_reset_appenderName(_updateAllAppenderData, env);
            adb_updateAllAppenderData_reset_appenderPattern(_updateAllAppenderData, env);
            adb_updateAllAppenderData_reset_threshold(_updateAllAppenderData, env);
            adb_updateAllAppenderData_reset_logFileName(_updateAllAppenderData, env);
            adb_updateAllAppenderData_reset_sysLogHost(_updateAllAppenderData, env);
            adb_updateAllAppenderData_reset_facility(_updateAllAppenderData, env);
            adb_updateAllAppenderData_reset_persist(_updateAllAppenderData, env);
            
              if(_updateAllAppenderData->qname)
              {
                  axutil_qname_free (_updateAllAppenderData->qname, env);
                  _updateAllAppenderData->qname = NULL;
              }
            

            if(_updateAllAppenderData)
            {
                AXIS2_FREE(env->allocator, _updateAllAppenderData);
                _updateAllAppenderData = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_updateAllAppenderData_deserialize(
                adb_updateAllAppenderData_t* _updateAllAppenderData,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return adb_updateAllAppenderData_deserialize_obj(
                _updateAllAppenderData,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs);
            
        }

        axis2_status_t AXIS2_CALL
        adb_updateAllAppenderData_deserialize_obj(
                adb_updateAllAppenderData_t* _updateAllAppenderData,
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
            AXIS2_PARAM_CHECK(env->error, _updateAllAppenderData, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for updateAllAppenderData : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              

                    current_element = (axiom_element_t *)axiom_node_get_data_element(parent, env);
                    qname = axiom_element_get_qname(current_element, env, parent);
                    if (axutil_qname_equals(qname, env, _updateAllAppenderData-> qname))
                    {
                        
                          first_node = axiom_node_get_first_child(parent, env);
                          
                    }
                    else
                    {
                        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                              "Failed in building adb object for updateAllAppenderData : "
                              "Expected %s but returned %s",
                              axutil_qname_to_string(_updateAllAppenderData-> qname, env),
                              axutil_qname_to_string(qname, env));
                        
                        return AXIS2_FAILURE;
                    }
                    

                     
                     /*
                      * building appenderName element
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
                                   
                                 element_qname = axutil_qname_create(env, "appenderName", "http://org.apache.axis2/xsd", NULL);
                                 

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
                                            status = adb_updateAllAppenderData_set_appenderName(_updateAllAppenderData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for appenderName ");
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
                      * building appenderPattern element
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
                                 
                                 element_qname = axutil_qname_create(env, "appenderPattern", "http://org.apache.axis2/xsd", NULL);
                                 

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
                                            status = adb_updateAllAppenderData_set_appenderPattern(_updateAllAppenderData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for appenderPattern ");
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
                      * building threshold element
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
                                 
                                 element_qname = axutil_qname_create(env, "threshold", "http://org.apache.axis2/xsd", NULL);
                                 

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
                                            status = adb_updateAllAppenderData_set_threshold(_updateAllAppenderData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for threshold ");
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
                      * building logFileName element
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
                                 
                                 element_qname = axutil_qname_create(env, "logFileName", "http://org.apache.axis2/xsd", NULL);
                                 

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
                                            status = adb_updateAllAppenderData_set_logFileName(_updateAllAppenderData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for logFileName ");
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
                      * building sysLogHost element
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
                                 
                                 element_qname = axutil_qname_create(env, "sysLogHost", "http://org.apache.axis2/xsd", NULL);
                                 

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
                                            status = adb_updateAllAppenderData_set_sysLogHost(_updateAllAppenderData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for sysLogHost ");
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
                      * building facility element
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
                                 
                                 element_qname = axutil_qname_create(env, "facility", "http://org.apache.axis2/xsd", NULL);
                                 

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
                                            status = adb_updateAllAppenderData_set_facility(_updateAllAppenderData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for facility ");
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
                      * building persist element
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
                                 
                                 element_qname = axutil_qname_create(env, "persist", "http://org.apache.axis2/xsd", NULL);
                                 

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
                                                status = adb_updateAllAppenderData_set_persist(_updateAllAppenderData, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_updateAllAppenderData_set_persist(_updateAllAppenderData, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element persist");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for persist ");
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
          adb_updateAllAppenderData_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_updateAllAppenderData_declare_parent_namespaces(
                    adb_updateAllAppenderData_t* _updateAllAppenderData,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_updateAllAppenderData_serialize(
                adb_updateAllAppenderData_t* _updateAllAppenderData,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
                return adb_updateAllAppenderData_serialize_obj(
                    _updateAllAppenderData, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            
        }

        axiom_node_t* AXIS2_CALL
        adb_updateAllAppenderData_serialize_obj(
                adb_updateAllAppenderData_t* _updateAllAppenderData,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
         
         axiom_node_t* current_node = NULL;
         int tag_closed = 0;
         
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
                    
                    axis2_char_t *text_value_5;
                    axis2_char_t *text_value_5_temp;
                    
                    axis2_char_t *text_value_6;
                    axis2_char_t *text_value_6_temp;
                    
                    axis2_char_t text_value_7[ADB_DEFAULT_DIGIT_LIMIT];
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

             
                int next_ns_index_value = 0;
            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _updateAllAppenderData, NULL);
            
             
                    namespaces = axutil_hash_make(env);
                    next_ns_index = &next_ns_index_value;
                     
                           ns1 = axiom_namespace_create (env,
                                             "http://org.apache.axis2/xsd",
                                             "n"); 
                           axutil_hash_set(namespaces, "http://org.apache.axis2/xsd", AXIS2_HASH_KEY_STRING, axutil_strdup(env, "n"));
                       
                     
                    parent_element = axiom_element_create (env, NULL, "updateAllAppenderData", ns1 , &parent);
                    
                    
                    axiom_element_set_namespace(parent_element, env, ns1, parent);


            
                    data_source = axiom_data_source_create(env, parent, &current_node);
                    stream = axiom_data_source_get_stream(data_source, env);
                  
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://org.apache.axis2/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://org.apache.axis2/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://org.apache.axis2/xsd",
                                            p_prefix));
                       }
                      

                   if (!_updateAllAppenderData->is_valid_appenderName)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("appenderName"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("appenderName")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing appenderName element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sappenderName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sappenderName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_1 = _updateAllAppenderData->property_appenderName;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://org.apache.axis2/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://org.apache.axis2/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://org.apache.axis2/xsd",
                                            p_prefix));
                       }
                      

                   if (!_updateAllAppenderData->is_valid_appenderPattern)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("appenderPattern"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("appenderPattern")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing appenderPattern element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sappenderPattern>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sappenderPattern>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_2 = _updateAllAppenderData->property_appenderPattern;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://org.apache.axis2/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://org.apache.axis2/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://org.apache.axis2/xsd",
                                            p_prefix));
                       }
                      

                   if (!_updateAllAppenderData->is_valid_threshold)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("threshold"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("threshold")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing threshold element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sthreshold>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sthreshold>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_3 = _updateAllAppenderData->property_threshold;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://org.apache.axis2/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://org.apache.axis2/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://org.apache.axis2/xsd",
                                            p_prefix));
                       }
                      

                   if (!_updateAllAppenderData->is_valid_logFileName)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("logFileName"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("logFileName")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing logFileName element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%slogFileName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%slogFileName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_4 = _updateAllAppenderData->property_logFileName;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://org.apache.axis2/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://org.apache.axis2/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://org.apache.axis2/xsd",
                                            p_prefix));
                       }
                      

                   if (!_updateAllAppenderData->is_valid_sysLogHost)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("sysLogHost"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("sysLogHost")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing sysLogHost element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%ssysLogHost>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%ssysLogHost>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_5 = _updateAllAppenderData->property_sysLogHost;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://org.apache.axis2/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://org.apache.axis2/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://org.apache.axis2/xsd",
                                            p_prefix));
                       }
                      

                   if (!_updateAllAppenderData->is_valid_facility)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("facility"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("facility")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing facility element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sfacility>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sfacility>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_6 = _updateAllAppenderData->property_facility;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://org.apache.axis2/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://org.apache.axis2/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://org.apache.axis2/xsd",
                                            p_prefix));
                       }
                      

                   if (!_updateAllAppenderData->is_valid_persist)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("persist"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("persist")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing persist element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%spersist>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%spersist>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_7, (_updateAllAppenderData->property_persist)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_7, axutil_strlen(text_value_7));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                   if(namespaces)
                   {
                       axutil_hash_index_t *hi;
                       void *val;
                       for (hi = axutil_hash_first(namespaces, env); hi; hi = axutil_hash_next(env, hi)) 
                       {
                           axutil_hash_this(hi, NULL, NULL, &val);
                           AXIS2_FREE(env->allocator, val);
                       }
                       axutil_hash_free(namespaces, env);
                   }
                

            return parent;
        }


        

            /**
             * Getter for appenderName by  Property Number 1
             */
            axis2_char_t* AXIS2_CALL
            adb_updateAllAppenderData_get_property1(
                adb_updateAllAppenderData_t* _updateAllAppenderData,
                const axutil_env_t *env)
            {
                return adb_updateAllAppenderData_get_appenderName(_updateAllAppenderData,
                                             env);
            }

            /**
             * getter for appenderName.
             */
            axis2_char_t* AXIS2_CALL
            adb_updateAllAppenderData_get_appenderName(
                    adb_updateAllAppenderData_t* _updateAllAppenderData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _updateAllAppenderData, NULL);
                  

                return _updateAllAppenderData->property_appenderName;
             }

            /**
             * setter for appenderName
             */
            axis2_status_t AXIS2_CALL
            adb_updateAllAppenderData_set_appenderName(
                    adb_updateAllAppenderData_t* _updateAllAppenderData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_appenderName)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _updateAllAppenderData, AXIS2_FAILURE);
                
                if(_updateAllAppenderData->is_valid_appenderName &&
                        arg_appenderName == _updateAllAppenderData->property_appenderName)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_updateAllAppenderData_reset_appenderName(_updateAllAppenderData, env);

                
                if(NULL == arg_appenderName)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _updateAllAppenderData->property_appenderName = (axis2_char_t *)axutil_strdup(env, arg_appenderName);
                        if(NULL == _updateAllAppenderData->property_appenderName)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for appenderName");
                            return AXIS2_FAILURE;
                        }
                        _updateAllAppenderData->is_valid_appenderName = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for appenderName
            */
           axis2_status_t AXIS2_CALL
           adb_updateAllAppenderData_reset_appenderName(
                   adb_updateAllAppenderData_t* _updateAllAppenderData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _updateAllAppenderData, AXIS2_FAILURE);
               

               
            
                
                if(_updateAllAppenderData->property_appenderName != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _updateAllAppenderData->property_appenderName);
                     _updateAllAppenderData->property_appenderName = NULL;
                }
            
                
                
                _updateAllAppenderData->is_valid_appenderName = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether appenderName is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_updateAllAppenderData_is_appenderName_nil(
                   adb_updateAllAppenderData_t* _updateAllAppenderData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _updateAllAppenderData, AXIS2_TRUE);
               
               return !_updateAllAppenderData->is_valid_appenderName;
           }

           /**
            * Set appenderName to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_updateAllAppenderData_set_appenderName_nil(
                   adb_updateAllAppenderData_t* _updateAllAppenderData,
                   const axutil_env_t *env)
           {
               return adb_updateAllAppenderData_reset_appenderName(_updateAllAppenderData, env);
           }

           

            /**
             * Getter for appenderPattern by  Property Number 2
             */
            axis2_char_t* AXIS2_CALL
            adb_updateAllAppenderData_get_property2(
                adb_updateAllAppenderData_t* _updateAllAppenderData,
                const axutil_env_t *env)
            {
                return adb_updateAllAppenderData_get_appenderPattern(_updateAllAppenderData,
                                             env);
            }

            /**
             * getter for appenderPattern.
             */
            axis2_char_t* AXIS2_CALL
            adb_updateAllAppenderData_get_appenderPattern(
                    adb_updateAllAppenderData_t* _updateAllAppenderData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _updateAllAppenderData, NULL);
                  

                return _updateAllAppenderData->property_appenderPattern;
             }

            /**
             * setter for appenderPattern
             */
            axis2_status_t AXIS2_CALL
            adb_updateAllAppenderData_set_appenderPattern(
                    adb_updateAllAppenderData_t* _updateAllAppenderData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_appenderPattern)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _updateAllAppenderData, AXIS2_FAILURE);
                
                if(_updateAllAppenderData->is_valid_appenderPattern &&
                        arg_appenderPattern == _updateAllAppenderData->property_appenderPattern)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_updateAllAppenderData_reset_appenderPattern(_updateAllAppenderData, env);

                
                if(NULL == arg_appenderPattern)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _updateAllAppenderData->property_appenderPattern = (axis2_char_t *)axutil_strdup(env, arg_appenderPattern);
                        if(NULL == _updateAllAppenderData->property_appenderPattern)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for appenderPattern");
                            return AXIS2_FAILURE;
                        }
                        _updateAllAppenderData->is_valid_appenderPattern = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for appenderPattern
            */
           axis2_status_t AXIS2_CALL
           adb_updateAllAppenderData_reset_appenderPattern(
                   adb_updateAllAppenderData_t* _updateAllAppenderData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _updateAllAppenderData, AXIS2_FAILURE);
               

               
            
                
                if(_updateAllAppenderData->property_appenderPattern != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _updateAllAppenderData->property_appenderPattern);
                     _updateAllAppenderData->property_appenderPattern = NULL;
                }
            
                
                
                _updateAllAppenderData->is_valid_appenderPattern = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether appenderPattern is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_updateAllAppenderData_is_appenderPattern_nil(
                   adb_updateAllAppenderData_t* _updateAllAppenderData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _updateAllAppenderData, AXIS2_TRUE);
               
               return !_updateAllAppenderData->is_valid_appenderPattern;
           }

           /**
            * Set appenderPattern to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_updateAllAppenderData_set_appenderPattern_nil(
                   adb_updateAllAppenderData_t* _updateAllAppenderData,
                   const axutil_env_t *env)
           {
               return adb_updateAllAppenderData_reset_appenderPattern(_updateAllAppenderData, env);
           }

           

            /**
             * Getter for threshold by  Property Number 3
             */
            axis2_char_t* AXIS2_CALL
            adb_updateAllAppenderData_get_property3(
                adb_updateAllAppenderData_t* _updateAllAppenderData,
                const axutil_env_t *env)
            {
                return adb_updateAllAppenderData_get_threshold(_updateAllAppenderData,
                                             env);
            }

            /**
             * getter for threshold.
             */
            axis2_char_t* AXIS2_CALL
            adb_updateAllAppenderData_get_threshold(
                    adb_updateAllAppenderData_t* _updateAllAppenderData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _updateAllAppenderData, NULL);
                  

                return _updateAllAppenderData->property_threshold;
             }

            /**
             * setter for threshold
             */
            axis2_status_t AXIS2_CALL
            adb_updateAllAppenderData_set_threshold(
                    adb_updateAllAppenderData_t* _updateAllAppenderData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_threshold)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _updateAllAppenderData, AXIS2_FAILURE);
                
                if(_updateAllAppenderData->is_valid_threshold &&
                        arg_threshold == _updateAllAppenderData->property_threshold)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_updateAllAppenderData_reset_threshold(_updateAllAppenderData, env);

                
                if(NULL == arg_threshold)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _updateAllAppenderData->property_threshold = (axis2_char_t *)axutil_strdup(env, arg_threshold);
                        if(NULL == _updateAllAppenderData->property_threshold)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for threshold");
                            return AXIS2_FAILURE;
                        }
                        _updateAllAppenderData->is_valid_threshold = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for threshold
            */
           axis2_status_t AXIS2_CALL
           adb_updateAllAppenderData_reset_threshold(
                   adb_updateAllAppenderData_t* _updateAllAppenderData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _updateAllAppenderData, AXIS2_FAILURE);
               

               
            
                
                if(_updateAllAppenderData->property_threshold != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _updateAllAppenderData->property_threshold);
                     _updateAllAppenderData->property_threshold = NULL;
                }
            
                
                
                _updateAllAppenderData->is_valid_threshold = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether threshold is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_updateAllAppenderData_is_threshold_nil(
                   adb_updateAllAppenderData_t* _updateAllAppenderData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _updateAllAppenderData, AXIS2_TRUE);
               
               return !_updateAllAppenderData->is_valid_threshold;
           }

           /**
            * Set threshold to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_updateAllAppenderData_set_threshold_nil(
                   adb_updateAllAppenderData_t* _updateAllAppenderData,
                   const axutil_env_t *env)
           {
               return adb_updateAllAppenderData_reset_threshold(_updateAllAppenderData, env);
           }

           

            /**
             * Getter for logFileName by  Property Number 4
             */
            axis2_char_t* AXIS2_CALL
            adb_updateAllAppenderData_get_property4(
                adb_updateAllAppenderData_t* _updateAllAppenderData,
                const axutil_env_t *env)
            {
                return adb_updateAllAppenderData_get_logFileName(_updateAllAppenderData,
                                             env);
            }

            /**
             * getter for logFileName.
             */
            axis2_char_t* AXIS2_CALL
            adb_updateAllAppenderData_get_logFileName(
                    adb_updateAllAppenderData_t* _updateAllAppenderData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _updateAllAppenderData, NULL);
                  

                return _updateAllAppenderData->property_logFileName;
             }

            /**
             * setter for logFileName
             */
            axis2_status_t AXIS2_CALL
            adb_updateAllAppenderData_set_logFileName(
                    adb_updateAllAppenderData_t* _updateAllAppenderData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_logFileName)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _updateAllAppenderData, AXIS2_FAILURE);
                
                if(_updateAllAppenderData->is_valid_logFileName &&
                        arg_logFileName == _updateAllAppenderData->property_logFileName)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_updateAllAppenderData_reset_logFileName(_updateAllAppenderData, env);

                
                if(NULL == arg_logFileName)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _updateAllAppenderData->property_logFileName = (axis2_char_t *)axutil_strdup(env, arg_logFileName);
                        if(NULL == _updateAllAppenderData->property_logFileName)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for logFileName");
                            return AXIS2_FAILURE;
                        }
                        _updateAllAppenderData->is_valid_logFileName = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for logFileName
            */
           axis2_status_t AXIS2_CALL
           adb_updateAllAppenderData_reset_logFileName(
                   adb_updateAllAppenderData_t* _updateAllAppenderData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _updateAllAppenderData, AXIS2_FAILURE);
               

               
            
                
                if(_updateAllAppenderData->property_logFileName != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _updateAllAppenderData->property_logFileName);
                     _updateAllAppenderData->property_logFileName = NULL;
                }
            
                
                
                _updateAllAppenderData->is_valid_logFileName = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether logFileName is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_updateAllAppenderData_is_logFileName_nil(
                   adb_updateAllAppenderData_t* _updateAllAppenderData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _updateAllAppenderData, AXIS2_TRUE);
               
               return !_updateAllAppenderData->is_valid_logFileName;
           }

           /**
            * Set logFileName to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_updateAllAppenderData_set_logFileName_nil(
                   adb_updateAllAppenderData_t* _updateAllAppenderData,
                   const axutil_env_t *env)
           {
               return adb_updateAllAppenderData_reset_logFileName(_updateAllAppenderData, env);
           }

           

            /**
             * Getter for sysLogHost by  Property Number 5
             */
            axis2_char_t* AXIS2_CALL
            adb_updateAllAppenderData_get_property5(
                adb_updateAllAppenderData_t* _updateAllAppenderData,
                const axutil_env_t *env)
            {
                return adb_updateAllAppenderData_get_sysLogHost(_updateAllAppenderData,
                                             env);
            }

            /**
             * getter for sysLogHost.
             */
            axis2_char_t* AXIS2_CALL
            adb_updateAllAppenderData_get_sysLogHost(
                    adb_updateAllAppenderData_t* _updateAllAppenderData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _updateAllAppenderData, NULL);
                  

                return _updateAllAppenderData->property_sysLogHost;
             }

            /**
             * setter for sysLogHost
             */
            axis2_status_t AXIS2_CALL
            adb_updateAllAppenderData_set_sysLogHost(
                    adb_updateAllAppenderData_t* _updateAllAppenderData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_sysLogHost)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _updateAllAppenderData, AXIS2_FAILURE);
                
                if(_updateAllAppenderData->is_valid_sysLogHost &&
                        arg_sysLogHost == _updateAllAppenderData->property_sysLogHost)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_updateAllAppenderData_reset_sysLogHost(_updateAllAppenderData, env);

                
                if(NULL == arg_sysLogHost)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _updateAllAppenderData->property_sysLogHost = (axis2_char_t *)axutil_strdup(env, arg_sysLogHost);
                        if(NULL == _updateAllAppenderData->property_sysLogHost)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for sysLogHost");
                            return AXIS2_FAILURE;
                        }
                        _updateAllAppenderData->is_valid_sysLogHost = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for sysLogHost
            */
           axis2_status_t AXIS2_CALL
           adb_updateAllAppenderData_reset_sysLogHost(
                   adb_updateAllAppenderData_t* _updateAllAppenderData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _updateAllAppenderData, AXIS2_FAILURE);
               

               
            
                
                if(_updateAllAppenderData->property_sysLogHost != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _updateAllAppenderData->property_sysLogHost);
                     _updateAllAppenderData->property_sysLogHost = NULL;
                }
            
                
                
                _updateAllAppenderData->is_valid_sysLogHost = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether sysLogHost is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_updateAllAppenderData_is_sysLogHost_nil(
                   adb_updateAllAppenderData_t* _updateAllAppenderData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _updateAllAppenderData, AXIS2_TRUE);
               
               return !_updateAllAppenderData->is_valid_sysLogHost;
           }

           /**
            * Set sysLogHost to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_updateAllAppenderData_set_sysLogHost_nil(
                   adb_updateAllAppenderData_t* _updateAllAppenderData,
                   const axutil_env_t *env)
           {
               return adb_updateAllAppenderData_reset_sysLogHost(_updateAllAppenderData, env);
           }

           

            /**
             * Getter for facility by  Property Number 6
             */
            axis2_char_t* AXIS2_CALL
            adb_updateAllAppenderData_get_property6(
                adb_updateAllAppenderData_t* _updateAllAppenderData,
                const axutil_env_t *env)
            {
                return adb_updateAllAppenderData_get_facility(_updateAllAppenderData,
                                             env);
            }

            /**
             * getter for facility.
             */
            axis2_char_t* AXIS2_CALL
            adb_updateAllAppenderData_get_facility(
                    adb_updateAllAppenderData_t* _updateAllAppenderData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _updateAllAppenderData, NULL);
                  

                return _updateAllAppenderData->property_facility;
             }

            /**
             * setter for facility
             */
            axis2_status_t AXIS2_CALL
            adb_updateAllAppenderData_set_facility(
                    adb_updateAllAppenderData_t* _updateAllAppenderData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_facility)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _updateAllAppenderData, AXIS2_FAILURE);
                
                if(_updateAllAppenderData->is_valid_facility &&
                        arg_facility == _updateAllAppenderData->property_facility)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_updateAllAppenderData_reset_facility(_updateAllAppenderData, env);

                
                if(NULL == arg_facility)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _updateAllAppenderData->property_facility = (axis2_char_t *)axutil_strdup(env, arg_facility);
                        if(NULL == _updateAllAppenderData->property_facility)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for facility");
                            return AXIS2_FAILURE;
                        }
                        _updateAllAppenderData->is_valid_facility = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for facility
            */
           axis2_status_t AXIS2_CALL
           adb_updateAllAppenderData_reset_facility(
                   adb_updateAllAppenderData_t* _updateAllAppenderData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _updateAllAppenderData, AXIS2_FAILURE);
               

               
            
                
                if(_updateAllAppenderData->property_facility != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _updateAllAppenderData->property_facility);
                     _updateAllAppenderData->property_facility = NULL;
                }
            
                
                
                _updateAllAppenderData->is_valid_facility = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether facility is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_updateAllAppenderData_is_facility_nil(
                   adb_updateAllAppenderData_t* _updateAllAppenderData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _updateAllAppenderData, AXIS2_TRUE);
               
               return !_updateAllAppenderData->is_valid_facility;
           }

           /**
            * Set facility to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_updateAllAppenderData_set_facility_nil(
                   adb_updateAllAppenderData_t* _updateAllAppenderData,
                   const axutil_env_t *env)
           {
               return adb_updateAllAppenderData_reset_facility(_updateAllAppenderData, env);
           }

           

            /**
             * Getter for persist by  Property Number 7
             */
            axis2_bool_t AXIS2_CALL
            adb_updateAllAppenderData_get_property7(
                adb_updateAllAppenderData_t* _updateAllAppenderData,
                const axutil_env_t *env)
            {
                return adb_updateAllAppenderData_get_persist(_updateAllAppenderData,
                                             env);
            }

            /**
             * getter for persist.
             */
            axis2_bool_t AXIS2_CALL
            adb_updateAllAppenderData_get_persist(
                    adb_updateAllAppenderData_t* _updateAllAppenderData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _updateAllAppenderData, (axis2_bool_t)0);
                  

                return _updateAllAppenderData->property_persist;
             }

            /**
             * setter for persist
             */
            axis2_status_t AXIS2_CALL
            adb_updateAllAppenderData_set_persist(
                    adb_updateAllAppenderData_t* _updateAllAppenderData,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_persist)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _updateAllAppenderData, AXIS2_FAILURE);
                
                if(_updateAllAppenderData->is_valid_persist &&
                        arg_persist == _updateAllAppenderData->property_persist)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_updateAllAppenderData_reset_persist(_updateAllAppenderData, env);

                _updateAllAppenderData->property_persist = arg_persist;
                        _updateAllAppenderData->is_valid_persist = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for persist
            */
           axis2_status_t AXIS2_CALL
           adb_updateAllAppenderData_reset_persist(
                   adb_updateAllAppenderData_t* _updateAllAppenderData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _updateAllAppenderData, AXIS2_FAILURE);
               

               _updateAllAppenderData->is_valid_persist = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether persist is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_updateAllAppenderData_is_persist_nil(
                   adb_updateAllAppenderData_t* _updateAllAppenderData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _updateAllAppenderData, AXIS2_TRUE);
               
               return !_updateAllAppenderData->is_valid_persist;
           }

           /**
            * Set persist to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_updateAllAppenderData_set_persist_nil(
                   adb_updateAllAppenderData_t* _updateAllAppenderData,
                   const axutil_env_t *env)
           {
               return adb_updateAllAppenderData_reset_persist(_updateAllAppenderData, env);
           }

           

