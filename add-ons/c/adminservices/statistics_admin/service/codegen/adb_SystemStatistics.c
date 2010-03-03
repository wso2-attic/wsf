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
         * adb_SystemStatistics.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_SystemStatistics.h"
        
                /*
                 * This type was generated from the piece of schema that had
                 * name = SystemStatistics
                 * Namespace URI = http://util.services.statistics.carbon.wso2.org/xsd
                 * Namespace Prefix = ns1
                 */
           


        struct adb_SystemStatistics
        {
            axis2_char_t *property_Type;

            double property_avgResponseTime;

                
                axis2_bool_t is_valid_avgResponseTime;
            int property_faultCount;

                
                axis2_bool_t is_valid_faultCount;
            axis2_char_t* property_javaVersion;

                
                axis2_bool_t is_valid_javaVersion;
            int64_t property_maxResponseTime;

                
                axis2_bool_t is_valid_maxResponseTime;
            int64_t property_minResponseTime;

                
                axis2_bool_t is_valid_minResponseTime;
            int property_requestCount;

                
                axis2_bool_t is_valid_requestCount;
            int property_responseCount;

                
                axis2_bool_t is_valid_responseCount;
            axis2_char_t* property_serverName;

                
                axis2_bool_t is_valid_serverName;
            axis2_char_t* property_serverStartTime;

                
                axis2_bool_t is_valid_serverStartTime;
            int property_services;

                
                axis2_bool_t is_valid_services;
            axis2_char_t* property_systemUpTime;

                
                axis2_bool_t is_valid_systemUpTime;
            adb_Metric_t* property_totalMemory;

                
                axis2_bool_t is_valid_totalMemory;
            adb_Metric_t* property_usedMemory;

                
                axis2_bool_t is_valid_usedMemory;
            axis2_char_t* property_wso2wsasVersion;

                
                axis2_bool_t is_valid_wso2wsasVersion;
            
        };


       /************************* Private Function prototypes ********************************/
        

                axis2_status_t AXIS2_CALL
                adb_SystemStatistics_set_avgResponseTime_nil(
                        adb_SystemStatistics_t* _SystemStatistics,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_SystemStatistics_set_faultCount_nil(
                        adb_SystemStatistics_t* _SystemStatistics,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_SystemStatistics_set_maxResponseTime_nil(
                        adb_SystemStatistics_t* _SystemStatistics,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_SystemStatistics_set_minResponseTime_nil(
                        adb_SystemStatistics_t* _SystemStatistics,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_SystemStatistics_set_requestCount_nil(
                        adb_SystemStatistics_t* _SystemStatistics,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_SystemStatistics_set_responseCount_nil(
                        adb_SystemStatistics_t* _SystemStatistics,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_SystemStatistics_set_services_nil(
                        adb_SystemStatistics_t* _SystemStatistics,
                        const axutil_env_t *env);
            


       /************************* Function Implmentations ********************************/
        adb_SystemStatistics_t* AXIS2_CALL
        adb_SystemStatistics_create(
            const axutil_env_t *env)
        {
            adb_SystemStatistics_t *_SystemStatistics = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _SystemStatistics = (adb_SystemStatistics_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_SystemStatistics_t));

            if(NULL == _SystemStatistics)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_SystemStatistics, 0, sizeof(adb_SystemStatistics_t));

            _SystemStatistics->property_Type = axutil_strdup(env, "adb_SystemStatistics");
            _SystemStatistics->is_valid_avgResponseTime  = AXIS2_FALSE;
            _SystemStatistics->is_valid_faultCount  = AXIS2_FALSE;
            _SystemStatistics->property_javaVersion  = NULL;
                  _SystemStatistics->is_valid_javaVersion  = AXIS2_FALSE;
            _SystemStatistics->is_valid_maxResponseTime  = AXIS2_FALSE;
            _SystemStatistics->is_valid_minResponseTime  = AXIS2_FALSE;
            _SystemStatistics->is_valid_requestCount  = AXIS2_FALSE;
            _SystemStatistics->is_valid_responseCount  = AXIS2_FALSE;
            _SystemStatistics->property_serverName  = NULL;
                  _SystemStatistics->is_valid_serverName  = AXIS2_FALSE;
            _SystemStatistics->property_serverStartTime  = NULL;
                  _SystemStatistics->is_valid_serverStartTime  = AXIS2_FALSE;
            _SystemStatistics->is_valid_services  = AXIS2_FALSE;
            _SystemStatistics->property_systemUpTime  = NULL;
                  _SystemStatistics->is_valid_systemUpTime  = AXIS2_FALSE;
            _SystemStatistics->property_totalMemory  = NULL;
                  _SystemStatistics->is_valid_totalMemory  = AXIS2_FALSE;
            _SystemStatistics->property_usedMemory  = NULL;
                  _SystemStatistics->is_valid_usedMemory  = AXIS2_FALSE;
            _SystemStatistics->property_wso2wsasVersion  = NULL;
                  _SystemStatistics->is_valid_wso2wsasVersion  = AXIS2_FALSE;
            

            return _SystemStatistics;
        }

        adb_SystemStatistics_t* AXIS2_CALL
        adb_SystemStatistics_create_with_values(
            const axutil_env_t *env,
                double _avgResponseTime,
                int _faultCount,
                axis2_char_t* _javaVersion,
                int64_t _maxResponseTime,
                int64_t _minResponseTime,
                int _requestCount,
                int _responseCount,
                axis2_char_t* _serverName,
                axis2_char_t* _serverStartTime,
                int _services,
                axis2_char_t* _systemUpTime,
                adb_Metric_t* _totalMemory,
                adb_Metric_t* _usedMemory,
                axis2_char_t* _wso2wsasVersion)
        {
            adb_SystemStatistics_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_SystemStatistics_create(env);

            
              status = adb_SystemStatistics_set_avgResponseTime(
                                     adb_obj,
                                     env,
                                     _avgResponseTime);
              if(status == AXIS2_FAILURE) {
                  adb_SystemStatistics_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_SystemStatistics_set_faultCount(
                                     adb_obj,
                                     env,
                                     _faultCount);
              if(status == AXIS2_FAILURE) {
                  adb_SystemStatistics_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_SystemStatistics_set_javaVersion(
                                     adb_obj,
                                     env,
                                     _javaVersion);
              if(status == AXIS2_FAILURE) {
                  adb_SystemStatistics_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_SystemStatistics_set_maxResponseTime(
                                     adb_obj,
                                     env,
                                     _maxResponseTime);
              if(status == AXIS2_FAILURE) {
                  adb_SystemStatistics_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_SystemStatistics_set_minResponseTime(
                                     adb_obj,
                                     env,
                                     _minResponseTime);
              if(status == AXIS2_FAILURE) {
                  adb_SystemStatistics_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_SystemStatistics_set_requestCount(
                                     adb_obj,
                                     env,
                                     _requestCount);
              if(status == AXIS2_FAILURE) {
                  adb_SystemStatistics_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_SystemStatistics_set_responseCount(
                                     adb_obj,
                                     env,
                                     _responseCount);
              if(status == AXIS2_FAILURE) {
                  adb_SystemStatistics_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_SystemStatistics_set_serverName(
                                     adb_obj,
                                     env,
                                     _serverName);
              if(status == AXIS2_FAILURE) {
                  adb_SystemStatistics_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_SystemStatistics_set_serverStartTime(
                                     adb_obj,
                                     env,
                                     _serverStartTime);
              if(status == AXIS2_FAILURE) {
                  adb_SystemStatistics_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_SystemStatistics_set_services(
                                     adb_obj,
                                     env,
                                     _services);
              if(status == AXIS2_FAILURE) {
                  adb_SystemStatistics_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_SystemStatistics_set_systemUpTime(
                                     adb_obj,
                                     env,
                                     _systemUpTime);
              if(status == AXIS2_FAILURE) {
                  adb_SystemStatistics_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_SystemStatistics_set_totalMemory(
                                     adb_obj,
                                     env,
                                     _totalMemory);
              if(status == AXIS2_FAILURE) {
                  adb_SystemStatistics_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_SystemStatistics_set_usedMemory(
                                     adb_obj,
                                     env,
                                     _usedMemory);
              if(status == AXIS2_FAILURE) {
                  adb_SystemStatistics_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_SystemStatistics_set_wso2wsasVersion(
                                     adb_obj,
                                     env,
                                     _wso2wsasVersion);
              if(status == AXIS2_FAILURE) {
                  adb_SystemStatistics_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        double AXIS2_CALL
                adb_SystemStatistics_free_popping_value(
                        adb_SystemStatistics_t* _SystemStatistics,
                        const axutil_env_t *env)
                {
                    double value;

                    
                    
                    value = _SystemStatistics->property_avgResponseTime;

                    adb_SystemStatistics_free(_SystemStatistics, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_free(
                adb_SystemStatistics_t* _SystemStatistics,
                const axutil_env_t *env)
        {
            
            
            return axis2_extension_mapper_free(
                (adb_type_t*) _SystemStatistics,
                env,
                "adb_SystemStatistics");
            
        }

        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_free_obj(
                adb_SystemStatistics_t* _SystemStatistics,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_FAILURE);

            if (_SystemStatistics->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _SystemStatistics->property_Type);
            }

            adb_SystemStatistics_reset_avgResponseTime(_SystemStatistics, env);
            adb_SystemStatistics_reset_faultCount(_SystemStatistics, env);
            adb_SystemStatistics_reset_javaVersion(_SystemStatistics, env);
            adb_SystemStatistics_reset_maxResponseTime(_SystemStatistics, env);
            adb_SystemStatistics_reset_minResponseTime(_SystemStatistics, env);
            adb_SystemStatistics_reset_requestCount(_SystemStatistics, env);
            adb_SystemStatistics_reset_responseCount(_SystemStatistics, env);
            adb_SystemStatistics_reset_serverName(_SystemStatistics, env);
            adb_SystemStatistics_reset_serverStartTime(_SystemStatistics, env);
            adb_SystemStatistics_reset_services(_SystemStatistics, env);
            adb_SystemStatistics_reset_systemUpTime(_SystemStatistics, env);
            adb_SystemStatistics_reset_totalMemory(_SystemStatistics, env);
            adb_SystemStatistics_reset_usedMemory(_SystemStatistics, env);
            adb_SystemStatistics_reset_wso2wsasVersion(_SystemStatistics, env);
            

            if(_SystemStatistics)
            {
                AXIS2_FREE(env->allocator, _SystemStatistics);
                _SystemStatistics = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_deserialize(
                adb_SystemStatistics_t* _SystemStatistics,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return axis2_extension_mapper_deserialize(
                (adb_type_t*) _SystemStatistics,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs,
                "adb_SystemStatistics");
            
        }

        axis2_status_t AXIS2_CALL
        adb_SystemStatistics_deserialize_obj(
                adb_SystemStatistics_t* _SystemStatistics,
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
            AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for SystemStatistics : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              
                      
                      first_node = axiom_node_get_first_child(parent, env);
                      
                    

                     
                     /*
                      * building avgResponseTime element
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
                                   
                                 element_qname = axutil_qname_create(env, "avgResponseTime", "http://util.services.statistics.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_SystemStatistics_set_avgResponseTime(_SystemStatistics, env,
                                                                   atof(text_value));
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element avgResponseTime");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for avgResponseTime ");
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
                      * building faultCount element
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
                                 
                                 element_qname = axutil_qname_create(env, "faultCount", "http://util.services.statistics.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_SystemStatistics_set_faultCount(_SystemStatistics, env,
                                                                   atoi(text_value));
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element faultCount");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for faultCount ");
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
                      * building javaVersion element
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
                                 
                                 element_qname = axutil_qname_create(env, "javaVersion", "http://util.services.statistics.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_SystemStatistics_set_javaVersion(_SystemStatistics, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for javaVersion ");
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
                      * building maxResponseTime element
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
                                 
                                 element_qname = axutil_qname_create(env, "maxResponseTime", "http://util.services.statistics.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_SystemStatistics_set_maxResponseTime(_SystemStatistics, env,
                                                                   axutil_strtol(text_value, (char**)NULL, 0));
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element maxResponseTime");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for maxResponseTime ");
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
                      * building minResponseTime element
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
                                 
                                 element_qname = axutil_qname_create(env, "minResponseTime", "http://util.services.statistics.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_SystemStatistics_set_minResponseTime(_SystemStatistics, env,
                                                                   axutil_strtol(text_value, (char**)NULL, 0));
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element minResponseTime");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for minResponseTime ");
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
                      * building requestCount element
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
                                 
                                 element_qname = axutil_qname_create(env, "requestCount", "http://util.services.statistics.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_SystemStatistics_set_requestCount(_SystemStatistics, env,
                                                                   atoi(text_value));
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element requestCount");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for requestCount ");
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
                      * building responseCount element
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
                                 
                                 element_qname = axutil_qname_create(env, "responseCount", "http://util.services.statistics.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_SystemStatistics_set_responseCount(_SystemStatistics, env,
                                                                   atoi(text_value));
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element responseCount");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for responseCount ");
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
                      * building serverName element
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
                                 
                                 element_qname = axutil_qname_create(env, "serverName", "http://util.services.statistics.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_SystemStatistics_set_serverName(_SystemStatistics, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for serverName ");
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
                      * building serverStartTime element
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
                                 
                                 element_qname = axutil_qname_create(env, "serverStartTime", "http://util.services.statistics.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_SystemStatistics_set_serverStartTime(_SystemStatistics, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for serverStartTime ");
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
                      * building services element
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
                                 
                                 element_qname = axutil_qname_create(env, "services", "http://util.services.statistics.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_SystemStatistics_set_services(_SystemStatistics, env,
                                                                   atoi(text_value));
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element services");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for services ");
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
                      * building systemUpTime element
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
                                 
                                 element_qname = axutil_qname_create(env, "systemUpTime", "http://util.services.statistics.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_SystemStatistics_set_systemUpTime(_SystemStatistics, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for systemUpTime ");
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
                      * building totalMemory element
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
                                 
                                 element_qname = axutil_qname_create(env, "totalMemory", "http://util.services.statistics.carbon.wso2.org/xsd", NULL);
                                 

                           if (adb_Metric_is_particle() ||  
                                (current_node   && current_element && (axutil_qname_equals(element_qname, env, qname))))
                           {
                              if( current_node   && current_element && (axutil_qname_equals(element_qname, env, qname)))
                              {
                                is_early_node_valid = AXIS2_TRUE;
                              }
                              
                                 
                                      element = (void*)axis2_extension_mapper_create_from_node(env, &current_node, "adb_Metric");

                                      status =  adb_Metric_deserialize((adb_Metric_t*)element,
                                                                            env, &current_node, &is_early_node_valid, AXIS2_FALSE);
                                      if(AXIS2_FAILURE == status)
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building adb object for element totalMemory");
                                      }
                                      else
                                      {
                                          status = adb_SystemStatistics_set_totalMemory(_SystemStatistics, env,
                                                                   (adb_Metric_t*)element);
                                      }
                                    
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for totalMemory ");
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
                      * building usedMemory element
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
                                 
                                 element_qname = axutil_qname_create(env, "usedMemory", "http://util.services.statistics.carbon.wso2.org/xsd", NULL);
                                 

                           if (adb_Metric_is_particle() ||  
                                (current_node   && current_element && (axutil_qname_equals(element_qname, env, qname))))
                           {
                              if( current_node   && current_element && (axutil_qname_equals(element_qname, env, qname)))
                              {
                                is_early_node_valid = AXIS2_TRUE;
                              }
                              
                                 
                                      element = (void*)axis2_extension_mapper_create_from_node(env, &current_node, "adb_Metric");

                                      status =  adb_Metric_deserialize((adb_Metric_t*)element,
                                                                            env, &current_node, &is_early_node_valid, AXIS2_FALSE);
                                      if(AXIS2_FAILURE == status)
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building adb object for element usedMemory");
                                      }
                                      else
                                      {
                                          status = adb_SystemStatistics_set_usedMemory(_SystemStatistics, env,
                                                                   (adb_Metric_t*)element);
                                      }
                                    
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for usedMemory ");
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
                      * building wso2wsasVersion element
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
                                 
                                 element_qname = axutil_qname_create(env, "wso2wsasVersion", "http://util.services.statistics.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_SystemStatistics_set_wso2wsasVersion(_SystemStatistics, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for wso2wsasVersion ");
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
          adb_SystemStatistics_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_SystemStatistics_declare_parent_namespaces(
                    adb_SystemStatistics_t* _SystemStatistics,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_SystemStatistics_serialize(
                adb_SystemStatistics_t* _SystemStatistics,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
            if (_SystemStatistics == NULL)
            {
                return adb_SystemStatistics_serialize_obj(
                    _SystemStatistics, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            }
            else
            {
                return axis2_extension_mapper_serialize(
                    (adb_type_t*) _SystemStatistics, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index, "adb_SystemStatistics");
            }
            
        }

        axiom_node_t* AXIS2_CALL
        adb_SystemStatistics_serialize_obj(
                adb_SystemStatistics_t* _SystemStatistics,
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
                    
                    axis2_char_t text_value_5[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t text_value_6[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t text_value_7[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t *text_value_8;
                    axis2_char_t *text_value_8_temp;
                    
                    axis2_char_t *text_value_9;
                    axis2_char_t *text_value_9_temp;
                    
                    axis2_char_t text_value_10[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t *text_value_11;
                    axis2_char_t *text_value_11_temp;
                    
                    axis2_char_t text_value_12[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t text_value_13[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t *text_value_14;
                    axis2_char_t *text_value_14_temp;
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _SystemStatistics, NULL);
            
            
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
              type_attrib = axutil_strcat(env, " ", xsi_prefix, ":type=\"SystemStatistics\"", NULL);
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
                                 "http://util.services.statistics.carbon.wso2.org/xsd",
                                 xsi_prefix);
            xsi_type_attri = axiom_attribute_create (env, "type", "SystemStatistics", xsi_ns);
            
            axiom_element_add_attribute (parent_element, env, xsi_type_attri, parent);
        
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.services.statistics.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.services.statistics.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.services.statistics.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_SystemStatistics->is_valid_avgResponseTime)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("avgResponseTime"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("avgResponseTime")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing avgResponseTime element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%savgResponseTime>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%savgResponseTime>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                               sprintf (text_value_1, "%f", (double)_SystemStatistics->property_avgResponseTime);
                             
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_1, axutil_strlen(text_value_1));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.services.statistics.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.services.statistics.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.services.statistics.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_SystemStatistics->is_valid_faultCount)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("faultCount"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("faultCount")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing faultCount element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sfaultCount>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sfaultCount>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                               sprintf (text_value_2, AXIS2_PRINTF_INT32_FORMAT_SPECIFIER, _SystemStatistics->property_faultCount);
                             
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_2, axutil_strlen(text_value_2));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.services.statistics.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.services.statistics.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.services.statistics.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_SystemStatistics->is_valid_javaVersion)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("javaVersion"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("javaVersion")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing javaVersion element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sjavaVersion>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sjavaVersion>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_3 = _SystemStatistics->property_javaVersion;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.services.statistics.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.services.statistics.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.services.statistics.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_SystemStatistics->is_valid_maxResponseTime)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("maxResponseTime"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("maxResponseTime")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing maxResponseTime element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%smaxResponseTime>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%smaxResponseTime>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                               sprintf (text_value_4, AXIS2_PRINTF_INT64_FORMAT_SPECIFIER, (int64_t) _SystemStatistics->property_maxResponseTime);
                             
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_4, axutil_strlen(text_value_4));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.services.statistics.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.services.statistics.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.services.statistics.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_SystemStatistics->is_valid_minResponseTime)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("minResponseTime"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("minResponseTime")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing minResponseTime element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sminResponseTime>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sminResponseTime>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                               sprintf (text_value_5, AXIS2_PRINTF_INT64_FORMAT_SPECIFIER, (int64_t) _SystemStatistics->property_minResponseTime);
                             
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_5, axutil_strlen(text_value_5));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.services.statistics.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.services.statistics.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.services.statistics.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_SystemStatistics->is_valid_requestCount)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("requestCount"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("requestCount")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing requestCount element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%srequestCount>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%srequestCount>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                               sprintf (text_value_6, AXIS2_PRINTF_INT32_FORMAT_SPECIFIER, _SystemStatistics->property_requestCount);
                             
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_6, axutil_strlen(text_value_6));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.services.statistics.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.services.statistics.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.services.statistics.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_SystemStatistics->is_valid_responseCount)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("responseCount"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("responseCount")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing responseCount element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sresponseCount>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sresponseCount>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                               sprintf (text_value_7, AXIS2_PRINTF_INT32_FORMAT_SPECIFIER, _SystemStatistics->property_responseCount);
                             
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_7, axutil_strlen(text_value_7));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.services.statistics.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.services.statistics.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.services.statistics.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_SystemStatistics->is_valid_serverName)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("serverName"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("serverName")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing serverName element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sserverName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sserverName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_8 = _SystemStatistics->property_serverName;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_8_temp = axutil_xml_quote_string(env, text_value_8, AXIS2_TRUE);
                           if (text_value_8_temp)
                           {
                               axutil_stream_write(stream, env, text_value_8_temp, axutil_strlen(text_value_8_temp));
                               AXIS2_FREE(env->allocator, text_value_8_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_8, axutil_strlen(text_value_8));
                           }
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.services.statistics.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.services.statistics.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.services.statistics.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_SystemStatistics->is_valid_serverStartTime)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("serverStartTime"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("serverStartTime")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing serverStartTime element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sserverStartTime>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sserverStartTime>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_9 = _SystemStatistics->property_serverStartTime;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_9_temp = axutil_xml_quote_string(env, text_value_9, AXIS2_TRUE);
                           if (text_value_9_temp)
                           {
                               axutil_stream_write(stream, env, text_value_9_temp, axutil_strlen(text_value_9_temp));
                               AXIS2_FREE(env->allocator, text_value_9_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_9, axutil_strlen(text_value_9));
                           }
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.services.statistics.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.services.statistics.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.services.statistics.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_SystemStatistics->is_valid_services)
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
                      * parsing services element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sservices>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sservices>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                               sprintf (text_value_10, AXIS2_PRINTF_INT32_FORMAT_SPECIFIER, _SystemStatistics->property_services);
                             
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_10, axutil_strlen(text_value_10));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.services.statistics.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.services.statistics.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.services.statistics.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_SystemStatistics->is_valid_systemUpTime)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("systemUpTime"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("systemUpTime")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing systemUpTime element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%ssystemUpTime>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%ssystemUpTime>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_11 = _SystemStatistics->property_systemUpTime;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_11_temp = axutil_xml_quote_string(env, text_value_11, AXIS2_TRUE);
                           if (text_value_11_temp)
                           {
                               axutil_stream_write(stream, env, text_value_11_temp, axutil_strlen(text_value_11_temp));
                               AXIS2_FREE(env->allocator, text_value_11_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_11, axutil_strlen(text_value_11));
                           }
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.services.statistics.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.services.statistics.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.services.statistics.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_SystemStatistics->is_valid_totalMemory)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("totalMemory"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("totalMemory")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing totalMemory element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%stotalMemory",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%stotalMemory>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                     
                            if(!adb_Metric_is_particle())
                            {
                                axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                            }
                            adb_Metric_serialize(_SystemStatistics->property_totalMemory, 
                                                                                 env, current_node, parent_element,
                                                                                 adb_Metric_is_particle() || AXIS2_FALSE, namespaces, next_ns_index);
                            
                            if(!adb_Metric_is_particle())
                            {
                                axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                            }
                            
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.services.statistics.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.services.statistics.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.services.statistics.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_SystemStatistics->is_valid_usedMemory)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("usedMemory"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("usedMemory")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing usedMemory element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%susedMemory",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%susedMemory>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                     
                            if(!adb_Metric_is_particle())
                            {
                                axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                            }
                            adb_Metric_serialize(_SystemStatistics->property_usedMemory, 
                                                                                 env, current_node, parent_element,
                                                                                 adb_Metric_is_particle() || AXIS2_FALSE, namespaces, next_ns_index);
                            
                            if(!adb_Metric_is_particle())
                            {
                                axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                            }
                            
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.services.statistics.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.services.statistics.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.services.statistics.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_SystemStatistics->is_valid_wso2wsasVersion)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("wso2wsasVersion"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("wso2wsasVersion")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing wso2wsasVersion element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%swso2wsasVersion>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%swso2wsasVersion>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_14 = _SystemStatistics->property_wso2wsasVersion;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_14_temp = axutil_xml_quote_string(env, text_value_14, AXIS2_TRUE);
                           if (text_value_14_temp)
                           {
                               axutil_stream_write(stream, env, text_value_14_temp, axutil_strlen(text_value_14_temp));
                               AXIS2_FREE(env->allocator, text_value_14_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_14, axutil_strlen(text_value_14));
                           }
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 

            return parent;
        }


        

            /**
             * Getter for avgResponseTime by  Property Number 1
             */
            double AXIS2_CALL
            adb_SystemStatistics_get_property1(
                adb_SystemStatistics_t* _SystemStatistics,
                const axutil_env_t *env)
            {
                return adb_SystemStatistics_get_avgResponseTime(_SystemStatistics,
                                             env);
            }

            /**
             * getter for avgResponseTime.
             */
            double AXIS2_CALL
            adb_SystemStatistics_get_avgResponseTime(
                    adb_SystemStatistics_t* _SystemStatistics,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (double)0);
                    AXIS2_PARAM_CHECK(env->error, _SystemStatistics, (double)0);
                  

                return _SystemStatistics->property_avgResponseTime;
             }

            /**
             * setter for avgResponseTime
             */
            axis2_status_t AXIS2_CALL
            adb_SystemStatistics_set_avgResponseTime(
                    adb_SystemStatistics_t* _SystemStatistics,
                    const axutil_env_t *env,
                    const double  arg_avgResponseTime)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_FAILURE);
                
                if(_SystemStatistics->is_valid_avgResponseTime &&
                        arg_avgResponseTime == _SystemStatistics->property_avgResponseTime)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_SystemStatistics_reset_avgResponseTime(_SystemStatistics, env);

                _SystemStatistics->property_avgResponseTime = arg_avgResponseTime;
                        _SystemStatistics->is_valid_avgResponseTime = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for avgResponseTime
            */
           axis2_status_t AXIS2_CALL
           adb_SystemStatistics_reset_avgResponseTime(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_FAILURE);
               

               _SystemStatistics->is_valid_avgResponseTime = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether avgResponseTime is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_SystemStatistics_is_avgResponseTime_nil(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_TRUE);
               
               return !_SystemStatistics->is_valid_avgResponseTime;
           }

           /**
            * Set avgResponseTime to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_SystemStatistics_set_avgResponseTime_nil(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               return adb_SystemStatistics_reset_avgResponseTime(_SystemStatistics, env);
           }

           

            /**
             * Getter for faultCount by  Property Number 2
             */
            int AXIS2_CALL
            adb_SystemStatistics_get_property2(
                adb_SystemStatistics_t* _SystemStatistics,
                const axutil_env_t *env)
            {
                return adb_SystemStatistics_get_faultCount(_SystemStatistics,
                                             env);
            }

            /**
             * getter for faultCount.
             */
            int AXIS2_CALL
            adb_SystemStatistics_get_faultCount(
                    adb_SystemStatistics_t* _SystemStatistics,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (int)0);
                    AXIS2_PARAM_CHECK(env->error, _SystemStatistics, (int)0);
                  

                return _SystemStatistics->property_faultCount;
             }

            /**
             * setter for faultCount
             */
            axis2_status_t AXIS2_CALL
            adb_SystemStatistics_set_faultCount(
                    adb_SystemStatistics_t* _SystemStatistics,
                    const axutil_env_t *env,
                    const int  arg_faultCount)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_FAILURE);
                
                if(_SystemStatistics->is_valid_faultCount &&
                        arg_faultCount == _SystemStatistics->property_faultCount)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_SystemStatistics_reset_faultCount(_SystemStatistics, env);

                _SystemStatistics->property_faultCount = arg_faultCount;
                        _SystemStatistics->is_valid_faultCount = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for faultCount
            */
           axis2_status_t AXIS2_CALL
           adb_SystemStatistics_reset_faultCount(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_FAILURE);
               

               _SystemStatistics->is_valid_faultCount = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether faultCount is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_SystemStatistics_is_faultCount_nil(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_TRUE);
               
               return !_SystemStatistics->is_valid_faultCount;
           }

           /**
            * Set faultCount to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_SystemStatistics_set_faultCount_nil(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               return adb_SystemStatistics_reset_faultCount(_SystemStatistics, env);
           }

           

            /**
             * Getter for javaVersion by  Property Number 3
             */
            axis2_char_t* AXIS2_CALL
            adb_SystemStatistics_get_property3(
                adb_SystemStatistics_t* _SystemStatistics,
                const axutil_env_t *env)
            {
                return adb_SystemStatistics_get_javaVersion(_SystemStatistics,
                                             env);
            }

            /**
             * getter for javaVersion.
             */
            axis2_char_t* AXIS2_CALL
            adb_SystemStatistics_get_javaVersion(
                    adb_SystemStatistics_t* _SystemStatistics,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _SystemStatistics, NULL);
                  

                return _SystemStatistics->property_javaVersion;
             }

            /**
             * setter for javaVersion
             */
            axis2_status_t AXIS2_CALL
            adb_SystemStatistics_set_javaVersion(
                    adb_SystemStatistics_t* _SystemStatistics,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_javaVersion)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_FAILURE);
                
                if(_SystemStatistics->is_valid_javaVersion &&
                        arg_javaVersion == _SystemStatistics->property_javaVersion)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_SystemStatistics_reset_javaVersion(_SystemStatistics, env);

                
                if(NULL == arg_javaVersion)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _SystemStatistics->property_javaVersion = (axis2_char_t *)axutil_strdup(env, arg_javaVersion);
                        if(NULL == _SystemStatistics->property_javaVersion)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for javaVersion");
                            return AXIS2_FAILURE;
                        }
                        _SystemStatistics->is_valid_javaVersion = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for javaVersion
            */
           axis2_status_t AXIS2_CALL
           adb_SystemStatistics_reset_javaVersion(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_FAILURE);
               

               
            
                
                if(_SystemStatistics->property_javaVersion != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _SystemStatistics->property_javaVersion);
                     _SystemStatistics->property_javaVersion = NULL;
                }
            
                
                
                _SystemStatistics->is_valid_javaVersion = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether javaVersion is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_SystemStatistics_is_javaVersion_nil(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_TRUE);
               
               return !_SystemStatistics->is_valid_javaVersion;
           }

           /**
            * Set javaVersion to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_SystemStatistics_set_javaVersion_nil(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               return adb_SystemStatistics_reset_javaVersion(_SystemStatistics, env);
           }

           

            /**
             * Getter for maxResponseTime by  Property Number 4
             */
            int64_t AXIS2_CALL
            adb_SystemStatistics_get_property4(
                adb_SystemStatistics_t* _SystemStatistics,
                const axutil_env_t *env)
            {
                return adb_SystemStatistics_get_maxResponseTime(_SystemStatistics,
                                             env);
            }

            /**
             * getter for maxResponseTime.
             */
            int64_t AXIS2_CALL
            adb_SystemStatistics_get_maxResponseTime(
                    adb_SystemStatistics_t* _SystemStatistics,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (int64_t)0);
                    AXIS2_PARAM_CHECK(env->error, _SystemStatistics, (int64_t)0);
                  

                return _SystemStatistics->property_maxResponseTime;
             }

            /**
             * setter for maxResponseTime
             */
            axis2_status_t AXIS2_CALL
            adb_SystemStatistics_set_maxResponseTime(
                    adb_SystemStatistics_t* _SystemStatistics,
                    const axutil_env_t *env,
                    const int64_t  arg_maxResponseTime)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_FAILURE);
                
                if(_SystemStatistics->is_valid_maxResponseTime &&
                        arg_maxResponseTime == _SystemStatistics->property_maxResponseTime)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_SystemStatistics_reset_maxResponseTime(_SystemStatistics, env);

                _SystemStatistics->property_maxResponseTime = arg_maxResponseTime;
                        _SystemStatistics->is_valid_maxResponseTime = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for maxResponseTime
            */
           axis2_status_t AXIS2_CALL
           adb_SystemStatistics_reset_maxResponseTime(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_FAILURE);
               

               _SystemStatistics->is_valid_maxResponseTime = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether maxResponseTime is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_SystemStatistics_is_maxResponseTime_nil(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_TRUE);
               
               return !_SystemStatistics->is_valid_maxResponseTime;
           }

           /**
            * Set maxResponseTime to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_SystemStatistics_set_maxResponseTime_nil(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               return adb_SystemStatistics_reset_maxResponseTime(_SystemStatistics, env);
           }

           

            /**
             * Getter for minResponseTime by  Property Number 5
             */
            int64_t AXIS2_CALL
            adb_SystemStatistics_get_property5(
                adb_SystemStatistics_t* _SystemStatistics,
                const axutil_env_t *env)
            {
                return adb_SystemStatistics_get_minResponseTime(_SystemStatistics,
                                             env);
            }

            /**
             * getter for minResponseTime.
             */
            int64_t AXIS2_CALL
            adb_SystemStatistics_get_minResponseTime(
                    adb_SystemStatistics_t* _SystemStatistics,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (int64_t)0);
                    AXIS2_PARAM_CHECK(env->error, _SystemStatistics, (int64_t)0);
                  

                return _SystemStatistics->property_minResponseTime;
             }

            /**
             * setter for minResponseTime
             */
            axis2_status_t AXIS2_CALL
            adb_SystemStatistics_set_minResponseTime(
                    adb_SystemStatistics_t* _SystemStatistics,
                    const axutil_env_t *env,
                    const int64_t  arg_minResponseTime)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_FAILURE);
                
                if(_SystemStatistics->is_valid_minResponseTime &&
                        arg_minResponseTime == _SystemStatistics->property_minResponseTime)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_SystemStatistics_reset_minResponseTime(_SystemStatistics, env);

                _SystemStatistics->property_minResponseTime = arg_minResponseTime;
                        _SystemStatistics->is_valid_minResponseTime = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for minResponseTime
            */
           axis2_status_t AXIS2_CALL
           adb_SystemStatistics_reset_minResponseTime(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_FAILURE);
               

               _SystemStatistics->is_valid_minResponseTime = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether minResponseTime is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_SystemStatistics_is_minResponseTime_nil(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_TRUE);
               
               return !_SystemStatistics->is_valid_minResponseTime;
           }

           /**
            * Set minResponseTime to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_SystemStatistics_set_minResponseTime_nil(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               return adb_SystemStatistics_reset_minResponseTime(_SystemStatistics, env);
           }

           

            /**
             * Getter for requestCount by  Property Number 6
             */
            int AXIS2_CALL
            adb_SystemStatistics_get_property6(
                adb_SystemStatistics_t* _SystemStatistics,
                const axutil_env_t *env)
            {
                return adb_SystemStatistics_get_requestCount(_SystemStatistics,
                                             env);
            }

            /**
             * getter for requestCount.
             */
            int AXIS2_CALL
            adb_SystemStatistics_get_requestCount(
                    adb_SystemStatistics_t* _SystemStatistics,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (int)0);
                    AXIS2_PARAM_CHECK(env->error, _SystemStatistics, (int)0);
                  

                return _SystemStatistics->property_requestCount;
             }

            /**
             * setter for requestCount
             */
            axis2_status_t AXIS2_CALL
            adb_SystemStatistics_set_requestCount(
                    adb_SystemStatistics_t* _SystemStatistics,
                    const axutil_env_t *env,
                    const int  arg_requestCount)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_FAILURE);
                
                if(_SystemStatistics->is_valid_requestCount &&
                        arg_requestCount == _SystemStatistics->property_requestCount)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_SystemStatistics_reset_requestCount(_SystemStatistics, env);

                _SystemStatistics->property_requestCount = arg_requestCount;
                        _SystemStatistics->is_valid_requestCount = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for requestCount
            */
           axis2_status_t AXIS2_CALL
           adb_SystemStatistics_reset_requestCount(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_FAILURE);
               

               _SystemStatistics->is_valid_requestCount = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether requestCount is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_SystemStatistics_is_requestCount_nil(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_TRUE);
               
               return !_SystemStatistics->is_valid_requestCount;
           }

           /**
            * Set requestCount to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_SystemStatistics_set_requestCount_nil(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               return adb_SystemStatistics_reset_requestCount(_SystemStatistics, env);
           }

           

            /**
             * Getter for responseCount by  Property Number 7
             */
            int AXIS2_CALL
            adb_SystemStatistics_get_property7(
                adb_SystemStatistics_t* _SystemStatistics,
                const axutil_env_t *env)
            {
                return adb_SystemStatistics_get_responseCount(_SystemStatistics,
                                             env);
            }

            /**
             * getter for responseCount.
             */
            int AXIS2_CALL
            adb_SystemStatistics_get_responseCount(
                    adb_SystemStatistics_t* _SystemStatistics,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (int)0);
                    AXIS2_PARAM_CHECK(env->error, _SystemStatistics, (int)0);
                  

                return _SystemStatistics->property_responseCount;
             }

            /**
             * setter for responseCount
             */
            axis2_status_t AXIS2_CALL
            adb_SystemStatistics_set_responseCount(
                    adb_SystemStatistics_t* _SystemStatistics,
                    const axutil_env_t *env,
                    const int  arg_responseCount)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_FAILURE);
                
                if(_SystemStatistics->is_valid_responseCount &&
                        arg_responseCount == _SystemStatistics->property_responseCount)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_SystemStatistics_reset_responseCount(_SystemStatistics, env);

                _SystemStatistics->property_responseCount = arg_responseCount;
                        _SystemStatistics->is_valid_responseCount = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for responseCount
            */
           axis2_status_t AXIS2_CALL
           adb_SystemStatistics_reset_responseCount(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_FAILURE);
               

               _SystemStatistics->is_valid_responseCount = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether responseCount is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_SystemStatistics_is_responseCount_nil(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_TRUE);
               
               return !_SystemStatistics->is_valid_responseCount;
           }

           /**
            * Set responseCount to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_SystemStatistics_set_responseCount_nil(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               return adb_SystemStatistics_reset_responseCount(_SystemStatistics, env);
           }

           

            /**
             * Getter for serverName by  Property Number 8
             */
            axis2_char_t* AXIS2_CALL
            adb_SystemStatistics_get_property8(
                adb_SystemStatistics_t* _SystemStatistics,
                const axutil_env_t *env)
            {
                return adb_SystemStatistics_get_serverName(_SystemStatistics,
                                             env);
            }

            /**
             * getter for serverName.
             */
            axis2_char_t* AXIS2_CALL
            adb_SystemStatistics_get_serverName(
                    adb_SystemStatistics_t* _SystemStatistics,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _SystemStatistics, NULL);
                  

                return _SystemStatistics->property_serverName;
             }

            /**
             * setter for serverName
             */
            axis2_status_t AXIS2_CALL
            adb_SystemStatistics_set_serverName(
                    adb_SystemStatistics_t* _SystemStatistics,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_serverName)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_FAILURE);
                
                if(_SystemStatistics->is_valid_serverName &&
                        arg_serverName == _SystemStatistics->property_serverName)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_SystemStatistics_reset_serverName(_SystemStatistics, env);

                
                if(NULL == arg_serverName)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _SystemStatistics->property_serverName = (axis2_char_t *)axutil_strdup(env, arg_serverName);
                        if(NULL == _SystemStatistics->property_serverName)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for serverName");
                            return AXIS2_FAILURE;
                        }
                        _SystemStatistics->is_valid_serverName = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for serverName
            */
           axis2_status_t AXIS2_CALL
           adb_SystemStatistics_reset_serverName(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_FAILURE);
               

               
            
                
                if(_SystemStatistics->property_serverName != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _SystemStatistics->property_serverName);
                     _SystemStatistics->property_serverName = NULL;
                }
            
                
                
                _SystemStatistics->is_valid_serverName = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether serverName is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_SystemStatistics_is_serverName_nil(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_TRUE);
               
               return !_SystemStatistics->is_valid_serverName;
           }

           /**
            * Set serverName to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_SystemStatistics_set_serverName_nil(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               return adb_SystemStatistics_reset_serverName(_SystemStatistics, env);
           }

           

            /**
             * Getter for serverStartTime by  Property Number 9
             */
            axis2_char_t* AXIS2_CALL
            adb_SystemStatistics_get_property9(
                adb_SystemStatistics_t* _SystemStatistics,
                const axutil_env_t *env)
            {
                return adb_SystemStatistics_get_serverStartTime(_SystemStatistics,
                                             env);
            }

            /**
             * getter for serverStartTime.
             */
            axis2_char_t* AXIS2_CALL
            adb_SystemStatistics_get_serverStartTime(
                    adb_SystemStatistics_t* _SystemStatistics,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _SystemStatistics, NULL);
                  

                return _SystemStatistics->property_serverStartTime;
             }

            /**
             * setter for serverStartTime
             */
            axis2_status_t AXIS2_CALL
            adb_SystemStatistics_set_serverStartTime(
                    adb_SystemStatistics_t* _SystemStatistics,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_serverStartTime)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_FAILURE);
                
                if(_SystemStatistics->is_valid_serverStartTime &&
                        arg_serverStartTime == _SystemStatistics->property_serverStartTime)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_SystemStatistics_reset_serverStartTime(_SystemStatistics, env);

                
                if(NULL == arg_serverStartTime)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _SystemStatistics->property_serverStartTime = (axis2_char_t *)axutil_strdup(env, arg_serverStartTime);
                        if(NULL == _SystemStatistics->property_serverStartTime)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for serverStartTime");
                            return AXIS2_FAILURE;
                        }
                        _SystemStatistics->is_valid_serverStartTime = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for serverStartTime
            */
           axis2_status_t AXIS2_CALL
           adb_SystemStatistics_reset_serverStartTime(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_FAILURE);
               

               
            
                
                if(_SystemStatistics->property_serverStartTime != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _SystemStatistics->property_serverStartTime);
                     _SystemStatistics->property_serverStartTime = NULL;
                }
            
                
                
                _SystemStatistics->is_valid_serverStartTime = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether serverStartTime is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_SystemStatistics_is_serverStartTime_nil(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_TRUE);
               
               return !_SystemStatistics->is_valid_serverStartTime;
           }

           /**
            * Set serverStartTime to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_SystemStatistics_set_serverStartTime_nil(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               return adb_SystemStatistics_reset_serverStartTime(_SystemStatistics, env);
           }

           

            /**
             * Getter for services by  Property Number 10
             */
            int AXIS2_CALL
            adb_SystemStatistics_get_property10(
                adb_SystemStatistics_t* _SystemStatistics,
                const axutil_env_t *env)
            {
                return adb_SystemStatistics_get_services(_SystemStatistics,
                                             env);
            }

            /**
             * getter for services.
             */
            int AXIS2_CALL
            adb_SystemStatistics_get_services(
                    adb_SystemStatistics_t* _SystemStatistics,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (int)0);
                    AXIS2_PARAM_CHECK(env->error, _SystemStatistics, (int)0);
                  

                return _SystemStatistics->property_services;
             }

            /**
             * setter for services
             */
            axis2_status_t AXIS2_CALL
            adb_SystemStatistics_set_services(
                    adb_SystemStatistics_t* _SystemStatistics,
                    const axutil_env_t *env,
                    const int  arg_services)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_FAILURE);
                
                if(_SystemStatistics->is_valid_services &&
                        arg_services == _SystemStatistics->property_services)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_SystemStatistics_reset_services(_SystemStatistics, env);

                _SystemStatistics->property_services = arg_services;
                        _SystemStatistics->is_valid_services = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for services
            */
           axis2_status_t AXIS2_CALL
           adb_SystemStatistics_reset_services(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_FAILURE);
               

               _SystemStatistics->is_valid_services = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether services is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_SystemStatistics_is_services_nil(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_TRUE);
               
               return !_SystemStatistics->is_valid_services;
           }

           /**
            * Set services to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_SystemStatistics_set_services_nil(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               return adb_SystemStatistics_reset_services(_SystemStatistics, env);
           }

           

            /**
             * Getter for systemUpTime by  Property Number 11
             */
            axis2_char_t* AXIS2_CALL
            adb_SystemStatistics_get_property11(
                adb_SystemStatistics_t* _SystemStatistics,
                const axutil_env_t *env)
            {
                return adb_SystemStatistics_get_systemUpTime(_SystemStatistics,
                                             env);
            }

            /**
             * getter for systemUpTime.
             */
            axis2_char_t* AXIS2_CALL
            adb_SystemStatistics_get_systemUpTime(
                    adb_SystemStatistics_t* _SystemStatistics,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _SystemStatistics, NULL);
                  

                return _SystemStatistics->property_systemUpTime;
             }

            /**
             * setter for systemUpTime
             */
            axis2_status_t AXIS2_CALL
            adb_SystemStatistics_set_systemUpTime(
                    adb_SystemStatistics_t* _SystemStatistics,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_systemUpTime)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_FAILURE);
                
                if(_SystemStatistics->is_valid_systemUpTime &&
                        arg_systemUpTime == _SystemStatistics->property_systemUpTime)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_SystemStatistics_reset_systemUpTime(_SystemStatistics, env);

                
                if(NULL == arg_systemUpTime)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _SystemStatistics->property_systemUpTime = (axis2_char_t *)axutil_strdup(env, arg_systemUpTime);
                        if(NULL == _SystemStatistics->property_systemUpTime)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for systemUpTime");
                            return AXIS2_FAILURE;
                        }
                        _SystemStatistics->is_valid_systemUpTime = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for systemUpTime
            */
           axis2_status_t AXIS2_CALL
           adb_SystemStatistics_reset_systemUpTime(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_FAILURE);
               

               
            
                
                if(_SystemStatistics->property_systemUpTime != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _SystemStatistics->property_systemUpTime);
                     _SystemStatistics->property_systemUpTime = NULL;
                }
            
                
                
                _SystemStatistics->is_valid_systemUpTime = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether systemUpTime is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_SystemStatistics_is_systemUpTime_nil(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_TRUE);
               
               return !_SystemStatistics->is_valid_systemUpTime;
           }

           /**
            * Set systemUpTime to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_SystemStatistics_set_systemUpTime_nil(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               return adb_SystemStatistics_reset_systemUpTime(_SystemStatistics, env);
           }

           

            /**
             * Getter for totalMemory by  Property Number 12
             */
            adb_Metric_t* AXIS2_CALL
            adb_SystemStatistics_get_property12(
                adb_SystemStatistics_t* _SystemStatistics,
                const axutil_env_t *env)
            {
                return adb_SystemStatistics_get_totalMemory(_SystemStatistics,
                                             env);
            }

            /**
             * getter for totalMemory.
             */
            adb_Metric_t* AXIS2_CALL
            adb_SystemStatistics_get_totalMemory(
                    adb_SystemStatistics_t* _SystemStatistics,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _SystemStatistics, NULL);
                  

                return _SystemStatistics->property_totalMemory;
             }

            /**
             * setter for totalMemory
             */
            axis2_status_t AXIS2_CALL
            adb_SystemStatistics_set_totalMemory(
                    adb_SystemStatistics_t* _SystemStatistics,
                    const axutil_env_t *env,
                    adb_Metric_t*  arg_totalMemory)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_FAILURE);
                
                if(_SystemStatistics->is_valid_totalMemory &&
                        arg_totalMemory == _SystemStatistics->property_totalMemory)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_SystemStatistics_reset_totalMemory(_SystemStatistics, env);

                
                if(NULL == arg_totalMemory)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _SystemStatistics->property_totalMemory = arg_totalMemory;
                        _SystemStatistics->is_valid_totalMemory = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for totalMemory
            */
           axis2_status_t AXIS2_CALL
           adb_SystemStatistics_reset_totalMemory(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_FAILURE);
               

               
            
                
                if(_SystemStatistics->property_totalMemory != NULL)
                {
                   
                   adb_Metric_free(_SystemStatistics->property_totalMemory, env);
                     _SystemStatistics->property_totalMemory = NULL;
                }
            
                
                
                _SystemStatistics->is_valid_totalMemory = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether totalMemory is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_SystemStatistics_is_totalMemory_nil(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_TRUE);
               
               return !_SystemStatistics->is_valid_totalMemory;
           }

           /**
            * Set totalMemory to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_SystemStatistics_set_totalMemory_nil(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               return adb_SystemStatistics_reset_totalMemory(_SystemStatistics, env);
           }

           

            /**
             * Getter for usedMemory by  Property Number 13
             */
            adb_Metric_t* AXIS2_CALL
            adb_SystemStatistics_get_property13(
                adb_SystemStatistics_t* _SystemStatistics,
                const axutil_env_t *env)
            {
                return adb_SystemStatistics_get_usedMemory(_SystemStatistics,
                                             env);
            }

            /**
             * getter for usedMemory.
             */
            adb_Metric_t* AXIS2_CALL
            adb_SystemStatistics_get_usedMemory(
                    adb_SystemStatistics_t* _SystemStatistics,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _SystemStatistics, NULL);
                  

                return _SystemStatistics->property_usedMemory;
             }

            /**
             * setter for usedMemory
             */
            axis2_status_t AXIS2_CALL
            adb_SystemStatistics_set_usedMemory(
                    adb_SystemStatistics_t* _SystemStatistics,
                    const axutil_env_t *env,
                    adb_Metric_t*  arg_usedMemory)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_FAILURE);
                
                if(_SystemStatistics->is_valid_usedMemory &&
                        arg_usedMemory == _SystemStatistics->property_usedMemory)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_SystemStatistics_reset_usedMemory(_SystemStatistics, env);

                
                if(NULL == arg_usedMemory)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _SystemStatistics->property_usedMemory = arg_usedMemory;
                        _SystemStatistics->is_valid_usedMemory = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for usedMemory
            */
           axis2_status_t AXIS2_CALL
           adb_SystemStatistics_reset_usedMemory(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_FAILURE);
               

               
            
                
                if(_SystemStatistics->property_usedMemory != NULL)
                {
                   
                   adb_Metric_free(_SystemStatistics->property_usedMemory, env);
                     _SystemStatistics->property_usedMemory = NULL;
                }
            
                
                
                _SystemStatistics->is_valid_usedMemory = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether usedMemory is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_SystemStatistics_is_usedMemory_nil(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_TRUE);
               
               return !_SystemStatistics->is_valid_usedMemory;
           }

           /**
            * Set usedMemory to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_SystemStatistics_set_usedMemory_nil(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               return adb_SystemStatistics_reset_usedMemory(_SystemStatistics, env);
           }

           

            /**
             * Getter for wso2wsasVersion by  Property Number 14
             */
            axis2_char_t* AXIS2_CALL
            adb_SystemStatistics_get_property14(
                adb_SystemStatistics_t* _SystemStatistics,
                const axutil_env_t *env)
            {
                return adb_SystemStatistics_get_wso2wsasVersion(_SystemStatistics,
                                             env);
            }

            /**
             * getter for wso2wsasVersion.
             */
            axis2_char_t* AXIS2_CALL
            adb_SystemStatistics_get_wso2wsasVersion(
                    adb_SystemStatistics_t* _SystemStatistics,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _SystemStatistics, NULL);
                  

                return _SystemStatistics->property_wso2wsasVersion;
             }

            /**
             * setter for wso2wsasVersion
             */
            axis2_status_t AXIS2_CALL
            adb_SystemStatistics_set_wso2wsasVersion(
                    adb_SystemStatistics_t* _SystemStatistics,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_wso2wsasVersion)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_FAILURE);
                
                if(_SystemStatistics->is_valid_wso2wsasVersion &&
                        arg_wso2wsasVersion == _SystemStatistics->property_wso2wsasVersion)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_SystemStatistics_reset_wso2wsasVersion(_SystemStatistics, env);

                
                if(NULL == arg_wso2wsasVersion)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _SystemStatistics->property_wso2wsasVersion = (axis2_char_t *)axutil_strdup(env, arg_wso2wsasVersion);
                        if(NULL == _SystemStatistics->property_wso2wsasVersion)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for wso2wsasVersion");
                            return AXIS2_FAILURE;
                        }
                        _SystemStatistics->is_valid_wso2wsasVersion = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for wso2wsasVersion
            */
           axis2_status_t AXIS2_CALL
           adb_SystemStatistics_reset_wso2wsasVersion(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_FAILURE);
               

               
            
                
                if(_SystemStatistics->property_wso2wsasVersion != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _SystemStatistics->property_wso2wsasVersion);
                     _SystemStatistics->property_wso2wsasVersion = NULL;
                }
            
                
                
                _SystemStatistics->is_valid_wso2wsasVersion = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether wso2wsasVersion is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_SystemStatistics_is_wso2wsasVersion_nil(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _SystemStatistics, AXIS2_TRUE);
               
               return !_SystemStatistics->is_valid_wso2wsasVersion;
           }

           /**
            * Set wso2wsasVersion to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_SystemStatistics_set_wso2wsasVersion_nil(
                   adb_SystemStatistics_t* _SystemStatistics,
                   const axutil_env_t *env)
           {
               return adb_SystemStatistics_reset_wso2wsasVersion(_SystemStatistics, env);
           }

           

