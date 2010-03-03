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
         * adb_ServerData.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_ServerData.h"
        
                /*
                 * This type was generated from the piece of schema that had
                 * name = ServerData
                 * Namespace URI = http://util.service.admin.server.carbon.wso2.org/xsd
                 * Namespace Prefix = ns1
                 */
           


        struct adb_ServerData
        {
            axis2_char_t *property_Type;

            axis2_char_t* property_axis2Location;

                
                axis2_bool_t is_valid_axis2Location;
            axis2_char_t* property_dbDriverName;

                
                axis2_bool_t is_valid_dbDriverName;
            axis2_char_t* property_dbDriverVersion;

                
                axis2_bool_t is_valid_dbDriverVersion;
            axis2_char_t* property_dbName;

                
                axis2_bool_t is_valid_dbName;
            axis2_char_t* property_dbURL;

                
                axis2_bool_t is_valid_dbURL;
            axis2_char_t* property_dbVersion;

                
                axis2_bool_t is_valid_dbVersion;
            axis2_char_t* property_javaHome;

                
                axis2_bool_t is_valid_javaHome;
            axis2_char_t* property_javaRuntimeName;

                
                axis2_bool_t is_valid_javaRuntimeName;
            axis2_char_t* property_javaVMVendor;

                
                axis2_bool_t is_valid_javaVMVendor;
            axis2_char_t* property_javaVMVersion;

                
                axis2_bool_t is_valid_javaVMVersion;
            axis2_char_t* property_javaVersion;

                
                axis2_bool_t is_valid_javaVersion;
            axis2_char_t* property_osName;

                
                axis2_bool_t is_valid_osName;
            axis2_char_t* property_osVersion;

                
                axis2_bool_t is_valid_osVersion;
            axis2_char_t* property_registryType;

                
                axis2_bool_t is_valid_registryType;
            axis2_char_t* property_remoteRegistryChroot;

                
                axis2_bool_t is_valid_remoteRegistryChroot;
            axis2_char_t* property_remoteRegistryURL;

                
                axis2_bool_t is_valid_remoteRegistryURL;
            axis2_char_t* property_repoLocation;

                
                axis2_bool_t is_valid_repoLocation;
            axis2_char_t* property_serverIp;

                
                axis2_bool_t is_valid_serverIp;
            axis2_char_t* property_serverName;

                
                axis2_bool_t is_valid_serverName;
            axis2_char_t* property_serverStartTime;

                
                axis2_bool_t is_valid_serverStartTime;
            axis2_char_t* property_systemUpTime;

                
                axis2_bool_t is_valid_systemUpTime;
            axis2_char_t* property_userCountry;

                
                axis2_bool_t is_valid_userCountry;
            axis2_char_t* property_userHome;

                
                axis2_bool_t is_valid_userHome;
            axis2_char_t* property_userName;

                
                axis2_bool_t is_valid_userName;
            axis2_char_t* property_userTimezone;

                
                axis2_bool_t is_valid_userTimezone;
            axis2_char_t* property_wso2wsasVersion;

                
                axis2_bool_t is_valid_wso2wsasVersion;
            
        };


       /************************* Private Function prototypes ********************************/
        


       /************************* Function Implmentations ********************************/
        adb_ServerData_t* AXIS2_CALL
        adb_ServerData_create(
            const axutil_env_t *env)
        {
            adb_ServerData_t *_ServerData = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _ServerData = (adb_ServerData_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_ServerData_t));

            if(NULL == _ServerData)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_ServerData, 0, sizeof(adb_ServerData_t));

            _ServerData->property_Type = axutil_strdup(env, "adb_ServerData");
            _ServerData->property_axis2Location  = NULL;
                  _ServerData->is_valid_axis2Location  = AXIS2_FALSE;
            _ServerData->property_dbDriverName  = NULL;
                  _ServerData->is_valid_dbDriverName  = AXIS2_FALSE;
            _ServerData->property_dbDriverVersion  = NULL;
                  _ServerData->is_valid_dbDriverVersion  = AXIS2_FALSE;
            _ServerData->property_dbName  = NULL;
                  _ServerData->is_valid_dbName  = AXIS2_FALSE;
            _ServerData->property_dbURL  = NULL;
                  _ServerData->is_valid_dbURL  = AXIS2_FALSE;
            _ServerData->property_dbVersion  = NULL;
                  _ServerData->is_valid_dbVersion  = AXIS2_FALSE;
            _ServerData->property_javaHome  = NULL;
                  _ServerData->is_valid_javaHome  = AXIS2_FALSE;
            _ServerData->property_javaRuntimeName  = NULL;
                  _ServerData->is_valid_javaRuntimeName  = AXIS2_FALSE;
            _ServerData->property_javaVMVendor  = NULL;
                  _ServerData->is_valid_javaVMVendor  = AXIS2_FALSE;
            _ServerData->property_javaVMVersion  = NULL;
                  _ServerData->is_valid_javaVMVersion  = AXIS2_FALSE;
            _ServerData->property_javaVersion  = NULL;
                  _ServerData->is_valid_javaVersion  = AXIS2_FALSE;
            _ServerData->property_osName  = NULL;
                  _ServerData->is_valid_osName  = AXIS2_FALSE;
            _ServerData->property_osVersion  = NULL;
                  _ServerData->is_valid_osVersion  = AXIS2_FALSE;
            _ServerData->property_registryType  = NULL;
                  _ServerData->is_valid_registryType  = AXIS2_FALSE;
            _ServerData->property_remoteRegistryChroot  = NULL;
                  _ServerData->is_valid_remoteRegistryChroot  = AXIS2_FALSE;
            _ServerData->property_remoteRegistryURL  = NULL;
                  _ServerData->is_valid_remoteRegistryURL  = AXIS2_FALSE;
            _ServerData->property_repoLocation  = NULL;
                  _ServerData->is_valid_repoLocation  = AXIS2_FALSE;
            _ServerData->property_serverIp  = NULL;
                  _ServerData->is_valid_serverIp  = AXIS2_FALSE;
            _ServerData->property_serverName  = NULL;
                  _ServerData->is_valid_serverName  = AXIS2_FALSE;
            _ServerData->property_serverStartTime  = NULL;
                  _ServerData->is_valid_serverStartTime  = AXIS2_FALSE;
            _ServerData->property_systemUpTime  = NULL;
                  _ServerData->is_valid_systemUpTime  = AXIS2_FALSE;
            _ServerData->property_userCountry  = NULL;
                  _ServerData->is_valid_userCountry  = AXIS2_FALSE;
            _ServerData->property_userHome  = NULL;
                  _ServerData->is_valid_userHome  = AXIS2_FALSE;
            _ServerData->property_userName  = NULL;
                  _ServerData->is_valid_userName  = AXIS2_FALSE;
            _ServerData->property_userTimezone  = NULL;
                  _ServerData->is_valid_userTimezone  = AXIS2_FALSE;
            _ServerData->property_wso2wsasVersion  = NULL;
                  _ServerData->is_valid_wso2wsasVersion  = AXIS2_FALSE;
            

            return _ServerData;
        }

        adb_ServerData_t* AXIS2_CALL
        adb_ServerData_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _axis2Location,
                axis2_char_t* _dbDriverName,
                axis2_char_t* _dbDriverVersion,
                axis2_char_t* _dbName,
                axis2_char_t* _dbURL,
                axis2_char_t* _dbVersion,
                axis2_char_t* _javaHome,
                axis2_char_t* _javaRuntimeName,
                axis2_char_t* _javaVMVendor,
                axis2_char_t* _javaVMVersion,
                axis2_char_t* _javaVersion,
                axis2_char_t* _osName,
                axis2_char_t* _osVersion,
                axis2_char_t* _registryType,
                axis2_char_t* _remoteRegistryChroot,
                axis2_char_t* _remoteRegistryURL,
                axis2_char_t* _repoLocation,
                axis2_char_t* _serverIp,
                axis2_char_t* _serverName,
                axis2_char_t* _serverStartTime,
                axis2_char_t* _systemUpTime,
                axis2_char_t* _userCountry,
                axis2_char_t* _userHome,
                axis2_char_t* _userName,
                axis2_char_t* _userTimezone,
                axis2_char_t* _wso2wsasVersion)
        {
            adb_ServerData_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_ServerData_create(env);

            
              status = adb_ServerData_set_axis2Location(
                                     adb_obj,
                                     env,
                                     _axis2Location);
              if(status == AXIS2_FAILURE) {
                  adb_ServerData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServerData_set_dbDriverName(
                                     adb_obj,
                                     env,
                                     _dbDriverName);
              if(status == AXIS2_FAILURE) {
                  adb_ServerData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServerData_set_dbDriverVersion(
                                     adb_obj,
                                     env,
                                     _dbDriverVersion);
              if(status == AXIS2_FAILURE) {
                  adb_ServerData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServerData_set_dbName(
                                     adb_obj,
                                     env,
                                     _dbName);
              if(status == AXIS2_FAILURE) {
                  adb_ServerData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServerData_set_dbURL(
                                     adb_obj,
                                     env,
                                     _dbURL);
              if(status == AXIS2_FAILURE) {
                  adb_ServerData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServerData_set_dbVersion(
                                     adb_obj,
                                     env,
                                     _dbVersion);
              if(status == AXIS2_FAILURE) {
                  adb_ServerData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServerData_set_javaHome(
                                     adb_obj,
                                     env,
                                     _javaHome);
              if(status == AXIS2_FAILURE) {
                  adb_ServerData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServerData_set_javaRuntimeName(
                                     adb_obj,
                                     env,
                                     _javaRuntimeName);
              if(status == AXIS2_FAILURE) {
                  adb_ServerData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServerData_set_javaVMVendor(
                                     adb_obj,
                                     env,
                                     _javaVMVendor);
              if(status == AXIS2_FAILURE) {
                  adb_ServerData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServerData_set_javaVMVersion(
                                     adb_obj,
                                     env,
                                     _javaVMVersion);
              if(status == AXIS2_FAILURE) {
                  adb_ServerData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServerData_set_javaVersion(
                                     adb_obj,
                                     env,
                                     _javaVersion);
              if(status == AXIS2_FAILURE) {
                  adb_ServerData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServerData_set_osName(
                                     adb_obj,
                                     env,
                                     _osName);
              if(status == AXIS2_FAILURE) {
                  adb_ServerData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServerData_set_osVersion(
                                     adb_obj,
                                     env,
                                     _osVersion);
              if(status == AXIS2_FAILURE) {
                  adb_ServerData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServerData_set_registryType(
                                     adb_obj,
                                     env,
                                     _registryType);
              if(status == AXIS2_FAILURE) {
                  adb_ServerData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServerData_set_remoteRegistryChroot(
                                     adb_obj,
                                     env,
                                     _remoteRegistryChroot);
              if(status == AXIS2_FAILURE) {
                  adb_ServerData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServerData_set_remoteRegistryURL(
                                     adb_obj,
                                     env,
                                     _remoteRegistryURL);
              if(status == AXIS2_FAILURE) {
                  adb_ServerData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServerData_set_repoLocation(
                                     adb_obj,
                                     env,
                                     _repoLocation);
              if(status == AXIS2_FAILURE) {
                  adb_ServerData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServerData_set_serverIp(
                                     adb_obj,
                                     env,
                                     _serverIp);
              if(status == AXIS2_FAILURE) {
                  adb_ServerData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServerData_set_serverName(
                                     adb_obj,
                                     env,
                                     _serverName);
              if(status == AXIS2_FAILURE) {
                  adb_ServerData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServerData_set_serverStartTime(
                                     adb_obj,
                                     env,
                                     _serverStartTime);
              if(status == AXIS2_FAILURE) {
                  adb_ServerData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServerData_set_systemUpTime(
                                     adb_obj,
                                     env,
                                     _systemUpTime);
              if(status == AXIS2_FAILURE) {
                  adb_ServerData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServerData_set_userCountry(
                                     adb_obj,
                                     env,
                                     _userCountry);
              if(status == AXIS2_FAILURE) {
                  adb_ServerData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServerData_set_userHome(
                                     adb_obj,
                                     env,
                                     _userHome);
              if(status == AXIS2_FAILURE) {
                  adb_ServerData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServerData_set_userName(
                                     adb_obj,
                                     env,
                                     _userName);
              if(status == AXIS2_FAILURE) {
                  adb_ServerData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServerData_set_userTimezone(
                                     adb_obj,
                                     env,
                                     _userTimezone);
              if(status == AXIS2_FAILURE) {
                  adb_ServerData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServerData_set_wso2wsasVersion(
                                     adb_obj,
                                     env,
                                     _wso2wsasVersion);
              if(status == AXIS2_FAILURE) {
                  adb_ServerData_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_char_t* AXIS2_CALL
                adb_ServerData_free_popping_value(
                        adb_ServerData_t* _ServerData,
                        const axutil_env_t *env)
                {
                    axis2_char_t* value;

                    
                    
                    value = _ServerData->property_axis2Location;

                    _ServerData->property_axis2Location = (axis2_char_t*)NULL;
                    adb_ServerData_free(_ServerData, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_ServerData_free(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env)
        {
            
            
            return axis2_extension_mapper_free(
                (adb_type_t*) _ServerData,
                env,
                "adb_ServerData");
            
        }

        axis2_status_t AXIS2_CALL
        adb_ServerData_free_obj(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);

            if (_ServerData->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _ServerData->property_Type);
            }

            adb_ServerData_reset_axis2Location(_ServerData, env);
            adb_ServerData_reset_dbDriverName(_ServerData, env);
            adb_ServerData_reset_dbDriverVersion(_ServerData, env);
            adb_ServerData_reset_dbName(_ServerData, env);
            adb_ServerData_reset_dbURL(_ServerData, env);
            adb_ServerData_reset_dbVersion(_ServerData, env);
            adb_ServerData_reset_javaHome(_ServerData, env);
            adb_ServerData_reset_javaRuntimeName(_ServerData, env);
            adb_ServerData_reset_javaVMVendor(_ServerData, env);
            adb_ServerData_reset_javaVMVersion(_ServerData, env);
            adb_ServerData_reset_javaVersion(_ServerData, env);
            adb_ServerData_reset_osName(_ServerData, env);
            adb_ServerData_reset_osVersion(_ServerData, env);
            adb_ServerData_reset_registryType(_ServerData, env);
            adb_ServerData_reset_remoteRegistryChroot(_ServerData, env);
            adb_ServerData_reset_remoteRegistryURL(_ServerData, env);
            adb_ServerData_reset_repoLocation(_ServerData, env);
            adb_ServerData_reset_serverIp(_ServerData, env);
            adb_ServerData_reset_serverName(_ServerData, env);
            adb_ServerData_reset_serverStartTime(_ServerData, env);
            adb_ServerData_reset_systemUpTime(_ServerData, env);
            adb_ServerData_reset_userCountry(_ServerData, env);
            adb_ServerData_reset_userHome(_ServerData, env);
            adb_ServerData_reset_userName(_ServerData, env);
            adb_ServerData_reset_userTimezone(_ServerData, env);
            adb_ServerData_reset_wso2wsasVersion(_ServerData, env);
            

            if(_ServerData)
            {
                AXIS2_FREE(env->allocator, _ServerData);
                _ServerData = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_ServerData_deserialize(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return axis2_extension_mapper_deserialize(
                (adb_type_t*) _ServerData,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs,
                "adb_ServerData");
            
        }

        axis2_status_t AXIS2_CALL
        adb_ServerData_deserialize_obj(
                adb_ServerData_t* _ServerData,
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
            AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for ServerData : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              
                      
                      first_node = axiom_node_get_first_child(parent, env);
                      
                    

                     
                     /*
                      * building axis2Location element
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
                                   
                                 element_qname = axutil_qname_create(env, "axis2Location", "http://util.service.admin.server.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ServerData_set_axis2Location(_ServerData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for axis2Location ");
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
                      * building dbDriverName element
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
                                 
                                 element_qname = axutil_qname_create(env, "dbDriverName", "http://util.service.admin.server.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ServerData_set_dbDriverName(_ServerData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for dbDriverName ");
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
                      * building dbDriverVersion element
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
                                 
                                 element_qname = axutil_qname_create(env, "dbDriverVersion", "http://util.service.admin.server.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ServerData_set_dbDriverVersion(_ServerData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for dbDriverVersion ");
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
                      * building dbName element
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
                                 
                                 element_qname = axutil_qname_create(env, "dbName", "http://util.service.admin.server.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ServerData_set_dbName(_ServerData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for dbName ");
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
                      * building dbURL element
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
                                 
                                 element_qname = axutil_qname_create(env, "dbURL", "http://util.service.admin.server.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ServerData_set_dbURL(_ServerData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for dbURL ");
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
                      * building dbVersion element
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
                                 
                                 element_qname = axutil_qname_create(env, "dbVersion", "http://util.service.admin.server.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ServerData_set_dbVersion(_ServerData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for dbVersion ");
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
                      * building javaHome element
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
                                 
                                 element_qname = axutil_qname_create(env, "javaHome", "http://util.service.admin.server.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ServerData_set_javaHome(_ServerData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for javaHome ");
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
                      * building javaRuntimeName element
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
                                 
                                 element_qname = axutil_qname_create(env, "javaRuntimeName", "http://util.service.admin.server.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ServerData_set_javaRuntimeName(_ServerData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for javaRuntimeName ");
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
                      * building javaVMVendor element
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
                                 
                                 element_qname = axutil_qname_create(env, "javaVMVendor", "http://util.service.admin.server.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ServerData_set_javaVMVendor(_ServerData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for javaVMVendor ");
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
                      * building javaVMVersion element
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
                                 
                                 element_qname = axutil_qname_create(env, "javaVMVersion", "http://util.service.admin.server.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ServerData_set_javaVMVersion(_ServerData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for javaVMVersion ");
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
                                 
                                 element_qname = axutil_qname_create(env, "javaVersion", "http://util.service.admin.server.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ServerData_set_javaVersion(_ServerData, env,
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
                      * building osName element
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
                                 
                                 element_qname = axutil_qname_create(env, "osName", "http://util.service.admin.server.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ServerData_set_osName(_ServerData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for osName ");
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
                      * building osVersion element
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
                                 
                                 element_qname = axutil_qname_create(env, "osVersion", "http://util.service.admin.server.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ServerData_set_osVersion(_ServerData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for osVersion ");
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
                      * building registryType element
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
                                 
                                 element_qname = axutil_qname_create(env, "registryType", "http://util.service.admin.server.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ServerData_set_registryType(_ServerData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for registryType ");
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
                      * building remoteRegistryChroot element
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
                                 
                                 element_qname = axutil_qname_create(env, "remoteRegistryChroot", "http://util.service.admin.server.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ServerData_set_remoteRegistryChroot(_ServerData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for remoteRegistryChroot ");
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
                      * building remoteRegistryURL element
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
                                 
                                 element_qname = axutil_qname_create(env, "remoteRegistryURL", "http://util.service.admin.server.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ServerData_set_remoteRegistryURL(_ServerData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for remoteRegistryURL ");
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
                      * building repoLocation element
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
                                 
                                 element_qname = axutil_qname_create(env, "repoLocation", "http://util.service.admin.server.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ServerData_set_repoLocation(_ServerData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for repoLocation ");
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
                      * building serverIp element
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
                                 
                                 element_qname = axutil_qname_create(env, "serverIp", "http://util.service.admin.server.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ServerData_set_serverIp(_ServerData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for serverIp ");
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
                                 
                                 element_qname = axutil_qname_create(env, "serverName", "http://util.service.admin.server.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ServerData_set_serverName(_ServerData, env,
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
                                 
                                 element_qname = axutil_qname_create(env, "serverStartTime", "http://util.service.admin.server.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ServerData_set_serverStartTime(_ServerData, env,
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
                                 
                                 element_qname = axutil_qname_create(env, "systemUpTime", "http://util.service.admin.server.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ServerData_set_systemUpTime(_ServerData, env,
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
                      * building userCountry element
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
                                 
                                 element_qname = axutil_qname_create(env, "userCountry", "http://util.service.admin.server.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ServerData_set_userCountry(_ServerData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for userCountry ");
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
                      * building userHome element
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
                                 
                                 element_qname = axutil_qname_create(env, "userHome", "http://util.service.admin.server.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ServerData_set_userHome(_ServerData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for userHome ");
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
                      * building userName element
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
                                 
                                 element_qname = axutil_qname_create(env, "userName", "http://util.service.admin.server.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ServerData_set_userName(_ServerData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for userName ");
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
                      * building userTimezone element
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
                                 
                                 element_qname = axutil_qname_create(env, "userTimezone", "http://util.service.admin.server.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ServerData_set_userTimezone(_ServerData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for userTimezone ");
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
                                 
                                 element_qname = axutil_qname_create(env, "wso2wsasVersion", "http://util.service.admin.server.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ServerData_set_wso2wsasVersion(_ServerData, env,
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
          adb_ServerData_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_ServerData_declare_parent_namespaces(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_ServerData_serialize(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
            if (_ServerData == NULL)
            {
                return adb_ServerData_serialize_obj(
                    _ServerData, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            }
            else
            {
                return axis2_extension_mapper_serialize(
                    (adb_type_t*) _ServerData, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index, "adb_ServerData");
            }
            
        }

        axiom_node_t* AXIS2_CALL
        adb_ServerData_serialize_obj(
                adb_ServerData_t* _ServerData,
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
                    
                    axis2_char_t *text_value_5;
                    axis2_char_t *text_value_5_temp;
                    
                    axis2_char_t *text_value_6;
                    axis2_char_t *text_value_6_temp;
                    
                    axis2_char_t *text_value_7;
                    axis2_char_t *text_value_7_temp;
                    
                    axis2_char_t *text_value_8;
                    axis2_char_t *text_value_8_temp;
                    
                    axis2_char_t *text_value_9;
                    axis2_char_t *text_value_9_temp;
                    
                    axis2_char_t *text_value_10;
                    axis2_char_t *text_value_10_temp;
                    
                    axis2_char_t *text_value_11;
                    axis2_char_t *text_value_11_temp;
                    
                    axis2_char_t *text_value_12;
                    axis2_char_t *text_value_12_temp;
                    
                    axis2_char_t *text_value_13;
                    axis2_char_t *text_value_13_temp;
                    
                    axis2_char_t *text_value_14;
                    axis2_char_t *text_value_14_temp;
                    
                    axis2_char_t *text_value_15;
                    axis2_char_t *text_value_15_temp;
                    
                    axis2_char_t *text_value_16;
                    axis2_char_t *text_value_16_temp;
                    
                    axis2_char_t *text_value_17;
                    axis2_char_t *text_value_17_temp;
                    
                    axis2_char_t *text_value_18;
                    axis2_char_t *text_value_18_temp;
                    
                    axis2_char_t *text_value_19;
                    axis2_char_t *text_value_19_temp;
                    
                    axis2_char_t *text_value_20;
                    axis2_char_t *text_value_20_temp;
                    
                    axis2_char_t *text_value_21;
                    axis2_char_t *text_value_21_temp;
                    
                    axis2_char_t *text_value_22;
                    axis2_char_t *text_value_22_temp;
                    
                    axis2_char_t *text_value_23;
                    axis2_char_t *text_value_23_temp;
                    
                    axis2_char_t *text_value_24;
                    axis2_char_t *text_value_24_temp;
                    
                    axis2_char_t *text_value_25;
                    axis2_char_t *text_value_25_temp;
                    
                    axis2_char_t *text_value_26;
                    axis2_char_t *text_value_26_temp;
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _ServerData, NULL);
            
            
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
              type_attrib = axutil_strcat(env, " ", xsi_prefix, ":type=\"ServerData\"", NULL);
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
                                 "http://util.service.admin.server.carbon.wso2.org/xsd",
                                 xsi_prefix);
            xsi_type_attri = axiom_attribute_create (env, "type", "ServerData", xsi_ns);
            
            axiom_element_add_attribute (parent_element, env, xsi_type_attri, parent);
        
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.service.admin.server.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ServerData->is_valid_axis2Location)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("axis2Location"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("axis2Location")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing axis2Location element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%saxis2Location>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%saxis2Location>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_1 = _ServerData->property_axis2Location;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.service.admin.server.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ServerData->is_valid_dbDriverName)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("dbDriverName"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("dbDriverName")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing dbDriverName element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sdbDriverName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sdbDriverName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_2 = _ServerData->property_dbDriverName;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.service.admin.server.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ServerData->is_valid_dbDriverVersion)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("dbDriverVersion"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("dbDriverVersion")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing dbDriverVersion element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sdbDriverVersion>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sdbDriverVersion>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_3 = _ServerData->property_dbDriverVersion;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.service.admin.server.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ServerData->is_valid_dbName)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("dbName"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("dbName")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing dbName element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sdbName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sdbName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_4 = _ServerData->property_dbName;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.service.admin.server.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ServerData->is_valid_dbURL)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("dbURL"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("dbURL")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing dbURL element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sdbURL>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sdbURL>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_5 = _ServerData->property_dbURL;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.service.admin.server.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ServerData->is_valid_dbVersion)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("dbVersion"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("dbVersion")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing dbVersion element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sdbVersion>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sdbVersion>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_6 = _ServerData->property_dbVersion;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.service.admin.server.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ServerData->is_valid_javaHome)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("javaHome"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("javaHome")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing javaHome element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sjavaHome>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sjavaHome>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_7 = _ServerData->property_javaHome;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_7_temp = axutil_xml_quote_string(env, text_value_7, AXIS2_TRUE);
                           if (text_value_7_temp)
                           {
                               axutil_stream_write(stream, env, text_value_7_temp, axutil_strlen(text_value_7_temp));
                               AXIS2_FREE(env->allocator, text_value_7_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_7, axutil_strlen(text_value_7));
                           }
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.service.admin.server.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ServerData->is_valid_javaRuntimeName)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("javaRuntimeName"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("javaRuntimeName")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing javaRuntimeName element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sjavaRuntimeName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sjavaRuntimeName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_8 = _ServerData->property_javaRuntimeName;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.service.admin.server.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ServerData->is_valid_javaVMVendor)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("javaVMVendor"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("javaVMVendor")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing javaVMVendor element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sjavaVMVendor>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sjavaVMVendor>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_9 = _ServerData->property_javaVMVendor;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.service.admin.server.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ServerData->is_valid_javaVMVersion)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("javaVMVersion"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("javaVMVersion")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing javaVMVersion element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sjavaVMVersion>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sjavaVMVersion>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_10 = _ServerData->property_javaVMVersion;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_10_temp = axutil_xml_quote_string(env, text_value_10, AXIS2_TRUE);
                           if (text_value_10_temp)
                           {
                               axutil_stream_write(stream, env, text_value_10_temp, axutil_strlen(text_value_10_temp));
                               AXIS2_FREE(env->allocator, text_value_10_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_10, axutil_strlen(text_value_10));
                           }
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.service.admin.server.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ServerData->is_valid_javaVersion)
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
                    
                           text_value_11 = _ServerData->property_javaVersion;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.service.admin.server.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ServerData->is_valid_osName)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("osName"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("osName")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing osName element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sosName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sosName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_12 = _ServerData->property_osName;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_12_temp = axutil_xml_quote_string(env, text_value_12, AXIS2_TRUE);
                           if (text_value_12_temp)
                           {
                               axutil_stream_write(stream, env, text_value_12_temp, axutil_strlen(text_value_12_temp));
                               AXIS2_FREE(env->allocator, text_value_12_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_12, axutil_strlen(text_value_12));
                           }
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.service.admin.server.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ServerData->is_valid_osVersion)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("osVersion"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("osVersion")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing osVersion element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sosVersion>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sosVersion>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_13 = _ServerData->property_osVersion;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_13_temp = axutil_xml_quote_string(env, text_value_13, AXIS2_TRUE);
                           if (text_value_13_temp)
                           {
                               axutil_stream_write(stream, env, text_value_13_temp, axutil_strlen(text_value_13_temp));
                               AXIS2_FREE(env->allocator, text_value_13_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_13, axutil_strlen(text_value_13));
                           }
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.service.admin.server.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ServerData->is_valid_registryType)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("registryType"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("registryType")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing registryType element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sregistryType>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sregistryType>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_14 = _ServerData->property_registryType;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.service.admin.server.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ServerData->is_valid_remoteRegistryChroot)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("remoteRegistryChroot"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("remoteRegistryChroot")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing remoteRegistryChroot element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sremoteRegistryChroot>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sremoteRegistryChroot>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_15 = _ServerData->property_remoteRegistryChroot;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_15_temp = axutil_xml_quote_string(env, text_value_15, AXIS2_TRUE);
                           if (text_value_15_temp)
                           {
                               axutil_stream_write(stream, env, text_value_15_temp, axutil_strlen(text_value_15_temp));
                               AXIS2_FREE(env->allocator, text_value_15_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_15, axutil_strlen(text_value_15));
                           }
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.service.admin.server.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ServerData->is_valid_remoteRegistryURL)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("remoteRegistryURL"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("remoteRegistryURL")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing remoteRegistryURL element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sremoteRegistryURL>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sremoteRegistryURL>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_16 = _ServerData->property_remoteRegistryURL;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_16_temp = axutil_xml_quote_string(env, text_value_16, AXIS2_TRUE);
                           if (text_value_16_temp)
                           {
                               axutil_stream_write(stream, env, text_value_16_temp, axutil_strlen(text_value_16_temp));
                               AXIS2_FREE(env->allocator, text_value_16_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_16, axutil_strlen(text_value_16));
                           }
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.service.admin.server.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ServerData->is_valid_repoLocation)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("repoLocation"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("repoLocation")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing repoLocation element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%srepoLocation>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%srepoLocation>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_17 = _ServerData->property_repoLocation;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_17_temp = axutil_xml_quote_string(env, text_value_17, AXIS2_TRUE);
                           if (text_value_17_temp)
                           {
                               axutil_stream_write(stream, env, text_value_17_temp, axutil_strlen(text_value_17_temp));
                               AXIS2_FREE(env->allocator, text_value_17_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_17, axutil_strlen(text_value_17));
                           }
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.service.admin.server.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ServerData->is_valid_serverIp)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("serverIp"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("serverIp")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing serverIp element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sserverIp>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sserverIp>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_18 = _ServerData->property_serverIp;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_18_temp = axutil_xml_quote_string(env, text_value_18, AXIS2_TRUE);
                           if (text_value_18_temp)
                           {
                               axutil_stream_write(stream, env, text_value_18_temp, axutil_strlen(text_value_18_temp));
                               AXIS2_FREE(env->allocator, text_value_18_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_18, axutil_strlen(text_value_18));
                           }
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.service.admin.server.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ServerData->is_valid_serverName)
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
                    
                           text_value_19 = _ServerData->property_serverName;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_19_temp = axutil_xml_quote_string(env, text_value_19, AXIS2_TRUE);
                           if (text_value_19_temp)
                           {
                               axutil_stream_write(stream, env, text_value_19_temp, axutil_strlen(text_value_19_temp));
                               AXIS2_FREE(env->allocator, text_value_19_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_19, axutil_strlen(text_value_19));
                           }
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.service.admin.server.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ServerData->is_valid_serverStartTime)
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
                    
                           text_value_20 = _ServerData->property_serverStartTime;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_20_temp = axutil_xml_quote_string(env, text_value_20, AXIS2_TRUE);
                           if (text_value_20_temp)
                           {
                               axutil_stream_write(stream, env, text_value_20_temp, axutil_strlen(text_value_20_temp));
                               AXIS2_FREE(env->allocator, text_value_20_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_20, axutil_strlen(text_value_20));
                           }
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.service.admin.server.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ServerData->is_valid_systemUpTime)
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
                    
                           text_value_21 = _ServerData->property_systemUpTime;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_21_temp = axutil_xml_quote_string(env, text_value_21, AXIS2_TRUE);
                           if (text_value_21_temp)
                           {
                               axutil_stream_write(stream, env, text_value_21_temp, axutil_strlen(text_value_21_temp));
                               AXIS2_FREE(env->allocator, text_value_21_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_21, axutil_strlen(text_value_21));
                           }
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.service.admin.server.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ServerData->is_valid_userCountry)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("userCountry"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("userCountry")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing userCountry element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%suserCountry>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%suserCountry>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_22 = _ServerData->property_userCountry;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_22_temp = axutil_xml_quote_string(env, text_value_22, AXIS2_TRUE);
                           if (text_value_22_temp)
                           {
                               axutil_stream_write(stream, env, text_value_22_temp, axutil_strlen(text_value_22_temp));
                               AXIS2_FREE(env->allocator, text_value_22_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_22, axutil_strlen(text_value_22));
                           }
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.service.admin.server.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ServerData->is_valid_userHome)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("userHome"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("userHome")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing userHome element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%suserHome>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%suserHome>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_23 = _ServerData->property_userHome;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_23_temp = axutil_xml_quote_string(env, text_value_23, AXIS2_TRUE);
                           if (text_value_23_temp)
                           {
                               axutil_stream_write(stream, env, text_value_23_temp, axutil_strlen(text_value_23_temp));
                               AXIS2_FREE(env->allocator, text_value_23_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_23, axutil_strlen(text_value_23));
                           }
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.service.admin.server.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ServerData->is_valid_userName)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("userName"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("userName")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing userName element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%suserName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%suserName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_24 = _ServerData->property_userName;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_24_temp = axutil_xml_quote_string(env, text_value_24, AXIS2_TRUE);
                           if (text_value_24_temp)
                           {
                               axutil_stream_write(stream, env, text_value_24_temp, axutil_strlen(text_value_24_temp));
                               AXIS2_FREE(env->allocator, text_value_24_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_24, axutil_strlen(text_value_24));
                           }
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.service.admin.server.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ServerData->is_valid_userTimezone)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("userTimezone"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("userTimezone")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing userTimezone element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%suserTimezone>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%suserTimezone>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_25 = _ServerData->property_userTimezone;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_25_temp = axutil_xml_quote_string(env, text_value_25, AXIS2_TRUE);
                           if (text_value_25_temp)
                           {
                               axutil_stream_write(stream, env, text_value_25_temp, axutil_strlen(text_value_25_temp));
                               AXIS2_FREE(env->allocator, text_value_25_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_25, axutil_strlen(text_value_25));
                           }
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.service.admin.server.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.service.admin.server.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ServerData->is_valid_wso2wsasVersion)
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
                    
                           text_value_26 = _ServerData->property_wso2wsasVersion;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_26_temp = axutil_xml_quote_string(env, text_value_26, AXIS2_TRUE);
                           if (text_value_26_temp)
                           {
                               axutil_stream_write(stream, env, text_value_26_temp, axutil_strlen(text_value_26_temp));
                               AXIS2_FREE(env->allocator, text_value_26_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_26, axutil_strlen(text_value_26));
                           }
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 

            return parent;
        }


        

            /**
             * Getter for axis2Location by  Property Number 1
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_property1(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env)
            {
                return adb_ServerData_get_axis2Location(_ServerData,
                                             env);
            }

            /**
             * getter for axis2Location.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_axis2Location(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServerData, NULL);
                  

                return _ServerData->property_axis2Location;
             }

            /**
             * setter for axis2Location
             */
            axis2_status_t AXIS2_CALL
            adb_ServerData_set_axis2Location(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_axis2Location)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
                
                if(_ServerData->is_valid_axis2Location &&
                        arg_axis2Location == _ServerData->property_axis2Location)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServerData_reset_axis2Location(_ServerData, env);

                
                if(NULL == arg_axis2Location)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServerData->property_axis2Location = (axis2_char_t *)axutil_strdup(env, arg_axis2Location);
                        if(NULL == _ServerData->property_axis2Location)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for axis2Location");
                            return AXIS2_FAILURE;
                        }
                        _ServerData->is_valid_axis2Location = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for axis2Location
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_reset_axis2Location(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
               

               
            
                
                if(_ServerData->property_axis2Location != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ServerData->property_axis2Location);
                     _ServerData->property_axis2Location = NULL;
                }
            
                
                
                _ServerData->is_valid_axis2Location = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether axis2Location is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServerData_is_axis2Location_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_TRUE);
               
               return !_ServerData->is_valid_axis2Location;
           }

           /**
            * Set axis2Location to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_set_axis2Location_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               return adb_ServerData_reset_axis2Location(_ServerData, env);
           }

           

            /**
             * Getter for dbDriverName by  Property Number 2
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_property2(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env)
            {
                return adb_ServerData_get_dbDriverName(_ServerData,
                                             env);
            }

            /**
             * getter for dbDriverName.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_dbDriverName(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServerData, NULL);
                  

                return _ServerData->property_dbDriverName;
             }

            /**
             * setter for dbDriverName
             */
            axis2_status_t AXIS2_CALL
            adb_ServerData_set_dbDriverName(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_dbDriverName)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
                
                if(_ServerData->is_valid_dbDriverName &&
                        arg_dbDriverName == _ServerData->property_dbDriverName)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServerData_reset_dbDriverName(_ServerData, env);

                
                if(NULL == arg_dbDriverName)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServerData->property_dbDriverName = (axis2_char_t *)axutil_strdup(env, arg_dbDriverName);
                        if(NULL == _ServerData->property_dbDriverName)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for dbDriverName");
                            return AXIS2_FAILURE;
                        }
                        _ServerData->is_valid_dbDriverName = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for dbDriverName
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_reset_dbDriverName(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
               

               
            
                
                if(_ServerData->property_dbDriverName != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ServerData->property_dbDriverName);
                     _ServerData->property_dbDriverName = NULL;
                }
            
                
                
                _ServerData->is_valid_dbDriverName = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether dbDriverName is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServerData_is_dbDriverName_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_TRUE);
               
               return !_ServerData->is_valid_dbDriverName;
           }

           /**
            * Set dbDriverName to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_set_dbDriverName_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               return adb_ServerData_reset_dbDriverName(_ServerData, env);
           }

           

            /**
             * Getter for dbDriverVersion by  Property Number 3
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_property3(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env)
            {
                return adb_ServerData_get_dbDriverVersion(_ServerData,
                                             env);
            }

            /**
             * getter for dbDriverVersion.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_dbDriverVersion(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServerData, NULL);
                  

                return _ServerData->property_dbDriverVersion;
             }

            /**
             * setter for dbDriverVersion
             */
            axis2_status_t AXIS2_CALL
            adb_ServerData_set_dbDriverVersion(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_dbDriverVersion)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
                
                if(_ServerData->is_valid_dbDriverVersion &&
                        arg_dbDriverVersion == _ServerData->property_dbDriverVersion)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServerData_reset_dbDriverVersion(_ServerData, env);

                
                if(NULL == arg_dbDriverVersion)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServerData->property_dbDriverVersion = (axis2_char_t *)axutil_strdup(env, arg_dbDriverVersion);
                        if(NULL == _ServerData->property_dbDriverVersion)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for dbDriverVersion");
                            return AXIS2_FAILURE;
                        }
                        _ServerData->is_valid_dbDriverVersion = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for dbDriverVersion
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_reset_dbDriverVersion(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
               

               
            
                
                if(_ServerData->property_dbDriverVersion != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ServerData->property_dbDriverVersion);
                     _ServerData->property_dbDriverVersion = NULL;
                }
            
                
                
                _ServerData->is_valid_dbDriverVersion = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether dbDriverVersion is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServerData_is_dbDriverVersion_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_TRUE);
               
               return !_ServerData->is_valid_dbDriverVersion;
           }

           /**
            * Set dbDriverVersion to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_set_dbDriverVersion_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               return adb_ServerData_reset_dbDriverVersion(_ServerData, env);
           }

           

            /**
             * Getter for dbName by  Property Number 4
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_property4(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env)
            {
                return adb_ServerData_get_dbName(_ServerData,
                                             env);
            }

            /**
             * getter for dbName.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_dbName(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServerData, NULL);
                  

                return _ServerData->property_dbName;
             }

            /**
             * setter for dbName
             */
            axis2_status_t AXIS2_CALL
            adb_ServerData_set_dbName(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_dbName)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
                
                if(_ServerData->is_valid_dbName &&
                        arg_dbName == _ServerData->property_dbName)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServerData_reset_dbName(_ServerData, env);

                
                if(NULL == arg_dbName)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServerData->property_dbName = (axis2_char_t *)axutil_strdup(env, arg_dbName);
                        if(NULL == _ServerData->property_dbName)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for dbName");
                            return AXIS2_FAILURE;
                        }
                        _ServerData->is_valid_dbName = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for dbName
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_reset_dbName(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
               

               
            
                
                if(_ServerData->property_dbName != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ServerData->property_dbName);
                     _ServerData->property_dbName = NULL;
                }
            
                
                
                _ServerData->is_valid_dbName = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether dbName is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServerData_is_dbName_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_TRUE);
               
               return !_ServerData->is_valid_dbName;
           }

           /**
            * Set dbName to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_set_dbName_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               return adb_ServerData_reset_dbName(_ServerData, env);
           }

           

            /**
             * Getter for dbURL by  Property Number 5
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_property5(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env)
            {
                return adb_ServerData_get_dbURL(_ServerData,
                                             env);
            }

            /**
             * getter for dbURL.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_dbURL(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServerData, NULL);
                  

                return _ServerData->property_dbURL;
             }

            /**
             * setter for dbURL
             */
            axis2_status_t AXIS2_CALL
            adb_ServerData_set_dbURL(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_dbURL)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
                
                if(_ServerData->is_valid_dbURL &&
                        arg_dbURL == _ServerData->property_dbURL)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServerData_reset_dbURL(_ServerData, env);

                
                if(NULL == arg_dbURL)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServerData->property_dbURL = (axis2_char_t *)axutil_strdup(env, arg_dbURL);
                        if(NULL == _ServerData->property_dbURL)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for dbURL");
                            return AXIS2_FAILURE;
                        }
                        _ServerData->is_valid_dbURL = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for dbURL
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_reset_dbURL(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
               

               
            
                
                if(_ServerData->property_dbURL != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ServerData->property_dbURL);
                     _ServerData->property_dbURL = NULL;
                }
            
                
                
                _ServerData->is_valid_dbURL = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether dbURL is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServerData_is_dbURL_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_TRUE);
               
               return !_ServerData->is_valid_dbURL;
           }

           /**
            * Set dbURL to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_set_dbURL_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               return adb_ServerData_reset_dbURL(_ServerData, env);
           }

           

            /**
             * Getter for dbVersion by  Property Number 6
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_property6(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env)
            {
                return adb_ServerData_get_dbVersion(_ServerData,
                                             env);
            }

            /**
             * getter for dbVersion.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_dbVersion(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServerData, NULL);
                  

                return _ServerData->property_dbVersion;
             }

            /**
             * setter for dbVersion
             */
            axis2_status_t AXIS2_CALL
            adb_ServerData_set_dbVersion(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_dbVersion)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
                
                if(_ServerData->is_valid_dbVersion &&
                        arg_dbVersion == _ServerData->property_dbVersion)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServerData_reset_dbVersion(_ServerData, env);

                
                if(NULL == arg_dbVersion)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServerData->property_dbVersion = (axis2_char_t *)axutil_strdup(env, arg_dbVersion);
                        if(NULL == _ServerData->property_dbVersion)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for dbVersion");
                            return AXIS2_FAILURE;
                        }
                        _ServerData->is_valid_dbVersion = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for dbVersion
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_reset_dbVersion(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
               

               
            
                
                if(_ServerData->property_dbVersion != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ServerData->property_dbVersion);
                     _ServerData->property_dbVersion = NULL;
                }
            
                
                
                _ServerData->is_valid_dbVersion = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether dbVersion is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServerData_is_dbVersion_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_TRUE);
               
               return !_ServerData->is_valid_dbVersion;
           }

           /**
            * Set dbVersion to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_set_dbVersion_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               return adb_ServerData_reset_dbVersion(_ServerData, env);
           }

           

            /**
             * Getter for javaHome by  Property Number 7
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_property7(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env)
            {
                return adb_ServerData_get_javaHome(_ServerData,
                                             env);
            }

            /**
             * getter for javaHome.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_javaHome(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServerData, NULL);
                  

                return _ServerData->property_javaHome;
             }

            /**
             * setter for javaHome
             */
            axis2_status_t AXIS2_CALL
            adb_ServerData_set_javaHome(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_javaHome)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
                
                if(_ServerData->is_valid_javaHome &&
                        arg_javaHome == _ServerData->property_javaHome)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServerData_reset_javaHome(_ServerData, env);

                
                if(NULL == arg_javaHome)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServerData->property_javaHome = (axis2_char_t *)axutil_strdup(env, arg_javaHome);
                        if(NULL == _ServerData->property_javaHome)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for javaHome");
                            return AXIS2_FAILURE;
                        }
                        _ServerData->is_valid_javaHome = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for javaHome
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_reset_javaHome(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
               

               
            
                
                if(_ServerData->property_javaHome != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ServerData->property_javaHome);
                     _ServerData->property_javaHome = NULL;
                }
            
                
                
                _ServerData->is_valid_javaHome = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether javaHome is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServerData_is_javaHome_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_TRUE);
               
               return !_ServerData->is_valid_javaHome;
           }

           /**
            * Set javaHome to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_set_javaHome_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               return adb_ServerData_reset_javaHome(_ServerData, env);
           }

           

            /**
             * Getter for javaRuntimeName by  Property Number 8
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_property8(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env)
            {
                return adb_ServerData_get_javaRuntimeName(_ServerData,
                                             env);
            }

            /**
             * getter for javaRuntimeName.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_javaRuntimeName(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServerData, NULL);
                  

                return _ServerData->property_javaRuntimeName;
             }

            /**
             * setter for javaRuntimeName
             */
            axis2_status_t AXIS2_CALL
            adb_ServerData_set_javaRuntimeName(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_javaRuntimeName)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
                
                if(_ServerData->is_valid_javaRuntimeName &&
                        arg_javaRuntimeName == _ServerData->property_javaRuntimeName)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServerData_reset_javaRuntimeName(_ServerData, env);

                
                if(NULL == arg_javaRuntimeName)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServerData->property_javaRuntimeName = (axis2_char_t *)axutil_strdup(env, arg_javaRuntimeName);
                        if(NULL == _ServerData->property_javaRuntimeName)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for javaRuntimeName");
                            return AXIS2_FAILURE;
                        }
                        _ServerData->is_valid_javaRuntimeName = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for javaRuntimeName
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_reset_javaRuntimeName(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
               

               
            
                
                if(_ServerData->property_javaRuntimeName != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ServerData->property_javaRuntimeName);
                     _ServerData->property_javaRuntimeName = NULL;
                }
            
                
                
                _ServerData->is_valid_javaRuntimeName = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether javaRuntimeName is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServerData_is_javaRuntimeName_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_TRUE);
               
               return !_ServerData->is_valid_javaRuntimeName;
           }

           /**
            * Set javaRuntimeName to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_set_javaRuntimeName_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               return adb_ServerData_reset_javaRuntimeName(_ServerData, env);
           }

           

            /**
             * Getter for javaVMVendor by  Property Number 9
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_property9(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env)
            {
                return adb_ServerData_get_javaVMVendor(_ServerData,
                                             env);
            }

            /**
             * getter for javaVMVendor.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_javaVMVendor(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServerData, NULL);
                  

                return _ServerData->property_javaVMVendor;
             }

            /**
             * setter for javaVMVendor
             */
            axis2_status_t AXIS2_CALL
            adb_ServerData_set_javaVMVendor(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_javaVMVendor)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
                
                if(_ServerData->is_valid_javaVMVendor &&
                        arg_javaVMVendor == _ServerData->property_javaVMVendor)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServerData_reset_javaVMVendor(_ServerData, env);

                
                if(NULL == arg_javaVMVendor)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServerData->property_javaVMVendor = (axis2_char_t *)axutil_strdup(env, arg_javaVMVendor);
                        if(NULL == _ServerData->property_javaVMVendor)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for javaVMVendor");
                            return AXIS2_FAILURE;
                        }
                        _ServerData->is_valid_javaVMVendor = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for javaVMVendor
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_reset_javaVMVendor(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
               

               
            
                
                if(_ServerData->property_javaVMVendor != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ServerData->property_javaVMVendor);
                     _ServerData->property_javaVMVendor = NULL;
                }
            
                
                
                _ServerData->is_valid_javaVMVendor = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether javaVMVendor is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServerData_is_javaVMVendor_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_TRUE);
               
               return !_ServerData->is_valid_javaVMVendor;
           }

           /**
            * Set javaVMVendor to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_set_javaVMVendor_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               return adb_ServerData_reset_javaVMVendor(_ServerData, env);
           }

           

            /**
             * Getter for javaVMVersion by  Property Number 10
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_property10(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env)
            {
                return adb_ServerData_get_javaVMVersion(_ServerData,
                                             env);
            }

            /**
             * getter for javaVMVersion.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_javaVMVersion(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServerData, NULL);
                  

                return _ServerData->property_javaVMVersion;
             }

            /**
             * setter for javaVMVersion
             */
            axis2_status_t AXIS2_CALL
            adb_ServerData_set_javaVMVersion(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_javaVMVersion)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
                
                if(_ServerData->is_valid_javaVMVersion &&
                        arg_javaVMVersion == _ServerData->property_javaVMVersion)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServerData_reset_javaVMVersion(_ServerData, env);

                
                if(NULL == arg_javaVMVersion)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServerData->property_javaVMVersion = (axis2_char_t *)axutil_strdup(env, arg_javaVMVersion);
                        if(NULL == _ServerData->property_javaVMVersion)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for javaVMVersion");
                            return AXIS2_FAILURE;
                        }
                        _ServerData->is_valid_javaVMVersion = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for javaVMVersion
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_reset_javaVMVersion(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
               

               
            
                
                if(_ServerData->property_javaVMVersion != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ServerData->property_javaVMVersion);
                     _ServerData->property_javaVMVersion = NULL;
                }
            
                
                
                _ServerData->is_valid_javaVMVersion = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether javaVMVersion is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServerData_is_javaVMVersion_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_TRUE);
               
               return !_ServerData->is_valid_javaVMVersion;
           }

           /**
            * Set javaVMVersion to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_set_javaVMVersion_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               return adb_ServerData_reset_javaVMVersion(_ServerData, env);
           }

           

            /**
             * Getter for javaVersion by  Property Number 11
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_property11(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env)
            {
                return adb_ServerData_get_javaVersion(_ServerData,
                                             env);
            }

            /**
             * getter for javaVersion.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_javaVersion(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServerData, NULL);
                  

                return _ServerData->property_javaVersion;
             }

            /**
             * setter for javaVersion
             */
            axis2_status_t AXIS2_CALL
            adb_ServerData_set_javaVersion(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_javaVersion)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
                
                if(_ServerData->is_valid_javaVersion &&
                        arg_javaVersion == _ServerData->property_javaVersion)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServerData_reset_javaVersion(_ServerData, env);

                
                if(NULL == arg_javaVersion)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServerData->property_javaVersion = (axis2_char_t *)axutil_strdup(env, arg_javaVersion);
                        if(NULL == _ServerData->property_javaVersion)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for javaVersion");
                            return AXIS2_FAILURE;
                        }
                        _ServerData->is_valid_javaVersion = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for javaVersion
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_reset_javaVersion(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
               

               
            
                
                if(_ServerData->property_javaVersion != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ServerData->property_javaVersion);
                     _ServerData->property_javaVersion = NULL;
                }
            
                
                
                _ServerData->is_valid_javaVersion = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether javaVersion is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServerData_is_javaVersion_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_TRUE);
               
               return !_ServerData->is_valid_javaVersion;
           }

           /**
            * Set javaVersion to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_set_javaVersion_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               return adb_ServerData_reset_javaVersion(_ServerData, env);
           }

           

            /**
             * Getter for osName by  Property Number 12
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_property12(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env)
            {
                return adb_ServerData_get_osName(_ServerData,
                                             env);
            }

            /**
             * getter for osName.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_osName(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServerData, NULL);
                  

                return _ServerData->property_osName;
             }

            /**
             * setter for osName
             */
            axis2_status_t AXIS2_CALL
            adb_ServerData_set_osName(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_osName)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
                
                if(_ServerData->is_valid_osName &&
                        arg_osName == _ServerData->property_osName)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServerData_reset_osName(_ServerData, env);

                
                if(NULL == arg_osName)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServerData->property_osName = (axis2_char_t *)axutil_strdup(env, arg_osName);
                        if(NULL == _ServerData->property_osName)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for osName");
                            return AXIS2_FAILURE;
                        }
                        _ServerData->is_valid_osName = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for osName
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_reset_osName(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
               

               
            
                
                if(_ServerData->property_osName != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ServerData->property_osName);
                     _ServerData->property_osName = NULL;
                }
            
                
                
                _ServerData->is_valid_osName = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether osName is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServerData_is_osName_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_TRUE);
               
               return !_ServerData->is_valid_osName;
           }

           /**
            * Set osName to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_set_osName_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               return adb_ServerData_reset_osName(_ServerData, env);
           }

           

            /**
             * Getter for osVersion by  Property Number 13
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_property13(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env)
            {
                return adb_ServerData_get_osVersion(_ServerData,
                                             env);
            }

            /**
             * getter for osVersion.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_osVersion(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServerData, NULL);
                  

                return _ServerData->property_osVersion;
             }

            /**
             * setter for osVersion
             */
            axis2_status_t AXIS2_CALL
            adb_ServerData_set_osVersion(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_osVersion)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
                
                if(_ServerData->is_valid_osVersion &&
                        arg_osVersion == _ServerData->property_osVersion)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServerData_reset_osVersion(_ServerData, env);

                
                if(NULL == arg_osVersion)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServerData->property_osVersion = (axis2_char_t *)axutil_strdup(env, arg_osVersion);
                        if(NULL == _ServerData->property_osVersion)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for osVersion");
                            return AXIS2_FAILURE;
                        }
                        _ServerData->is_valid_osVersion = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for osVersion
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_reset_osVersion(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
               

               
            
                
                if(_ServerData->property_osVersion != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ServerData->property_osVersion);
                     _ServerData->property_osVersion = NULL;
                }
            
                
                
                _ServerData->is_valid_osVersion = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether osVersion is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServerData_is_osVersion_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_TRUE);
               
               return !_ServerData->is_valid_osVersion;
           }

           /**
            * Set osVersion to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_set_osVersion_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               return adb_ServerData_reset_osVersion(_ServerData, env);
           }

           

            /**
             * Getter for registryType by  Property Number 14
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_property14(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env)
            {
                return adb_ServerData_get_registryType(_ServerData,
                                             env);
            }

            /**
             * getter for registryType.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_registryType(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServerData, NULL);
                  

                return _ServerData->property_registryType;
             }

            /**
             * setter for registryType
             */
            axis2_status_t AXIS2_CALL
            adb_ServerData_set_registryType(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_registryType)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
                
                if(_ServerData->is_valid_registryType &&
                        arg_registryType == _ServerData->property_registryType)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServerData_reset_registryType(_ServerData, env);

                
                if(NULL == arg_registryType)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServerData->property_registryType = (axis2_char_t *)axutil_strdup(env, arg_registryType);
                        if(NULL == _ServerData->property_registryType)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for registryType");
                            return AXIS2_FAILURE;
                        }
                        _ServerData->is_valid_registryType = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for registryType
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_reset_registryType(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
               

               
            
                
                if(_ServerData->property_registryType != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ServerData->property_registryType);
                     _ServerData->property_registryType = NULL;
                }
            
                
                
                _ServerData->is_valid_registryType = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether registryType is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServerData_is_registryType_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_TRUE);
               
               return !_ServerData->is_valid_registryType;
           }

           /**
            * Set registryType to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_set_registryType_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               return adb_ServerData_reset_registryType(_ServerData, env);
           }

           

            /**
             * Getter for remoteRegistryChroot by  Property Number 15
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_property15(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env)
            {
                return adb_ServerData_get_remoteRegistryChroot(_ServerData,
                                             env);
            }

            /**
             * getter for remoteRegistryChroot.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_remoteRegistryChroot(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServerData, NULL);
                  

                return _ServerData->property_remoteRegistryChroot;
             }

            /**
             * setter for remoteRegistryChroot
             */
            axis2_status_t AXIS2_CALL
            adb_ServerData_set_remoteRegistryChroot(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_remoteRegistryChroot)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
                
                if(_ServerData->is_valid_remoteRegistryChroot &&
                        arg_remoteRegistryChroot == _ServerData->property_remoteRegistryChroot)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServerData_reset_remoteRegistryChroot(_ServerData, env);

                
                if(NULL == arg_remoteRegistryChroot)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServerData->property_remoteRegistryChroot = (axis2_char_t *)axutil_strdup(env, arg_remoteRegistryChroot);
                        if(NULL == _ServerData->property_remoteRegistryChroot)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for remoteRegistryChroot");
                            return AXIS2_FAILURE;
                        }
                        _ServerData->is_valid_remoteRegistryChroot = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for remoteRegistryChroot
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_reset_remoteRegistryChroot(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
               

               
            
                
                if(_ServerData->property_remoteRegistryChroot != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ServerData->property_remoteRegistryChroot);
                     _ServerData->property_remoteRegistryChroot = NULL;
                }
            
                
                
                _ServerData->is_valid_remoteRegistryChroot = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether remoteRegistryChroot is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServerData_is_remoteRegistryChroot_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_TRUE);
               
               return !_ServerData->is_valid_remoteRegistryChroot;
           }

           /**
            * Set remoteRegistryChroot to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_set_remoteRegistryChroot_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               return adb_ServerData_reset_remoteRegistryChroot(_ServerData, env);
           }

           

            /**
             * Getter for remoteRegistryURL by  Property Number 16
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_property16(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env)
            {
                return adb_ServerData_get_remoteRegistryURL(_ServerData,
                                             env);
            }

            /**
             * getter for remoteRegistryURL.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_remoteRegistryURL(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServerData, NULL);
                  

                return _ServerData->property_remoteRegistryURL;
             }

            /**
             * setter for remoteRegistryURL
             */
            axis2_status_t AXIS2_CALL
            adb_ServerData_set_remoteRegistryURL(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_remoteRegistryURL)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
                
                if(_ServerData->is_valid_remoteRegistryURL &&
                        arg_remoteRegistryURL == _ServerData->property_remoteRegistryURL)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServerData_reset_remoteRegistryURL(_ServerData, env);

                
                if(NULL == arg_remoteRegistryURL)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServerData->property_remoteRegistryURL = (axis2_char_t *)axutil_strdup(env, arg_remoteRegistryURL);
                        if(NULL == _ServerData->property_remoteRegistryURL)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for remoteRegistryURL");
                            return AXIS2_FAILURE;
                        }
                        _ServerData->is_valid_remoteRegistryURL = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for remoteRegistryURL
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_reset_remoteRegistryURL(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
               

               
            
                
                if(_ServerData->property_remoteRegistryURL != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ServerData->property_remoteRegistryURL);
                     _ServerData->property_remoteRegistryURL = NULL;
                }
            
                
                
                _ServerData->is_valid_remoteRegistryURL = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether remoteRegistryURL is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServerData_is_remoteRegistryURL_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_TRUE);
               
               return !_ServerData->is_valid_remoteRegistryURL;
           }

           /**
            * Set remoteRegistryURL to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_set_remoteRegistryURL_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               return adb_ServerData_reset_remoteRegistryURL(_ServerData, env);
           }

           

            /**
             * Getter for repoLocation by  Property Number 17
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_property17(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env)
            {
                return adb_ServerData_get_repoLocation(_ServerData,
                                             env);
            }

            /**
             * getter for repoLocation.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_repoLocation(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServerData, NULL);
                  

                return _ServerData->property_repoLocation;
             }

            /**
             * setter for repoLocation
             */
            axis2_status_t AXIS2_CALL
            adb_ServerData_set_repoLocation(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_repoLocation)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
                
                if(_ServerData->is_valid_repoLocation &&
                        arg_repoLocation == _ServerData->property_repoLocation)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServerData_reset_repoLocation(_ServerData, env);

                
                if(NULL == arg_repoLocation)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServerData->property_repoLocation = (axis2_char_t *)axutil_strdup(env, arg_repoLocation);
                        if(NULL == _ServerData->property_repoLocation)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for repoLocation");
                            return AXIS2_FAILURE;
                        }
                        _ServerData->is_valid_repoLocation = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for repoLocation
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_reset_repoLocation(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
               

               
            
                
                if(_ServerData->property_repoLocation != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ServerData->property_repoLocation);
                     _ServerData->property_repoLocation = NULL;
                }
            
                
                
                _ServerData->is_valid_repoLocation = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether repoLocation is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServerData_is_repoLocation_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_TRUE);
               
               return !_ServerData->is_valid_repoLocation;
           }

           /**
            * Set repoLocation to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_set_repoLocation_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               return adb_ServerData_reset_repoLocation(_ServerData, env);
           }

           

            /**
             * Getter for serverIp by  Property Number 18
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_property18(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env)
            {
                return adb_ServerData_get_serverIp(_ServerData,
                                             env);
            }

            /**
             * getter for serverIp.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_serverIp(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServerData, NULL);
                  

                return _ServerData->property_serverIp;
             }

            /**
             * setter for serverIp
             */
            axis2_status_t AXIS2_CALL
            adb_ServerData_set_serverIp(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_serverIp)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
                
                if(_ServerData->is_valid_serverIp &&
                        arg_serverIp == _ServerData->property_serverIp)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServerData_reset_serverIp(_ServerData, env);

                
                if(NULL == arg_serverIp)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServerData->property_serverIp = (axis2_char_t *)axutil_strdup(env, arg_serverIp);
                        if(NULL == _ServerData->property_serverIp)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for serverIp");
                            return AXIS2_FAILURE;
                        }
                        _ServerData->is_valid_serverIp = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for serverIp
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_reset_serverIp(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
               

               
            
                
                if(_ServerData->property_serverIp != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ServerData->property_serverIp);
                     _ServerData->property_serverIp = NULL;
                }
            
                
                
                _ServerData->is_valid_serverIp = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether serverIp is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServerData_is_serverIp_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_TRUE);
               
               return !_ServerData->is_valid_serverIp;
           }

           /**
            * Set serverIp to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_set_serverIp_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               return adb_ServerData_reset_serverIp(_ServerData, env);
           }

           

            /**
             * Getter for serverName by  Property Number 19
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_property19(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env)
            {
                return adb_ServerData_get_serverName(_ServerData,
                                             env);
            }

            /**
             * getter for serverName.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_serverName(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServerData, NULL);
                  

                return _ServerData->property_serverName;
             }

            /**
             * setter for serverName
             */
            axis2_status_t AXIS2_CALL
            adb_ServerData_set_serverName(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_serverName)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
                
                if(_ServerData->is_valid_serverName &&
                        arg_serverName == _ServerData->property_serverName)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServerData_reset_serverName(_ServerData, env);

                
                if(NULL == arg_serverName)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServerData->property_serverName = (axis2_char_t *)axutil_strdup(env, arg_serverName);
                        if(NULL == _ServerData->property_serverName)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for serverName");
                            return AXIS2_FAILURE;
                        }
                        _ServerData->is_valid_serverName = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for serverName
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_reset_serverName(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
               

               
            
                
                if(_ServerData->property_serverName != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ServerData->property_serverName);
                     _ServerData->property_serverName = NULL;
                }
            
                
                
                _ServerData->is_valid_serverName = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether serverName is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServerData_is_serverName_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_TRUE);
               
               return !_ServerData->is_valid_serverName;
           }

           /**
            * Set serverName to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_set_serverName_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               return adb_ServerData_reset_serverName(_ServerData, env);
           }

           

            /**
             * Getter for serverStartTime by  Property Number 20
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_property20(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env)
            {
                return adb_ServerData_get_serverStartTime(_ServerData,
                                             env);
            }

            /**
             * getter for serverStartTime.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_serverStartTime(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServerData, NULL);
                  

                return _ServerData->property_serverStartTime;
             }

            /**
             * setter for serverStartTime
             */
            axis2_status_t AXIS2_CALL
            adb_ServerData_set_serverStartTime(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_serverStartTime)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
                
                if(_ServerData->is_valid_serverStartTime &&
                        arg_serverStartTime == _ServerData->property_serverStartTime)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServerData_reset_serverStartTime(_ServerData, env);

                
                if(NULL == arg_serverStartTime)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServerData->property_serverStartTime = (axis2_char_t *)axutil_strdup(env, arg_serverStartTime);
                        if(NULL == _ServerData->property_serverStartTime)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for serverStartTime");
                            return AXIS2_FAILURE;
                        }
                        _ServerData->is_valid_serverStartTime = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for serverStartTime
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_reset_serverStartTime(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
               

               
            
                
                if(_ServerData->property_serverStartTime != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ServerData->property_serverStartTime);
                     _ServerData->property_serverStartTime = NULL;
                }
            
                
                
                _ServerData->is_valid_serverStartTime = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether serverStartTime is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServerData_is_serverStartTime_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_TRUE);
               
               return !_ServerData->is_valid_serverStartTime;
           }

           /**
            * Set serverStartTime to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_set_serverStartTime_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               return adb_ServerData_reset_serverStartTime(_ServerData, env);
           }

           

            /**
             * Getter for systemUpTime by  Property Number 21
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_property21(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env)
            {
                return adb_ServerData_get_systemUpTime(_ServerData,
                                             env);
            }

            /**
             * getter for systemUpTime.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_systemUpTime(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServerData, NULL);
                  

                return _ServerData->property_systemUpTime;
             }

            /**
             * setter for systemUpTime
             */
            axis2_status_t AXIS2_CALL
            adb_ServerData_set_systemUpTime(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_systemUpTime)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
                
                if(_ServerData->is_valid_systemUpTime &&
                        arg_systemUpTime == _ServerData->property_systemUpTime)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServerData_reset_systemUpTime(_ServerData, env);

                
                if(NULL == arg_systemUpTime)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServerData->property_systemUpTime = (axis2_char_t *)axutil_strdup(env, arg_systemUpTime);
                        if(NULL == _ServerData->property_systemUpTime)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for systemUpTime");
                            return AXIS2_FAILURE;
                        }
                        _ServerData->is_valid_systemUpTime = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for systemUpTime
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_reset_systemUpTime(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
               

               
            
                
                if(_ServerData->property_systemUpTime != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ServerData->property_systemUpTime);
                     _ServerData->property_systemUpTime = NULL;
                }
            
                
                
                _ServerData->is_valid_systemUpTime = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether systemUpTime is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServerData_is_systemUpTime_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_TRUE);
               
               return !_ServerData->is_valid_systemUpTime;
           }

           /**
            * Set systemUpTime to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_set_systemUpTime_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               return adb_ServerData_reset_systemUpTime(_ServerData, env);
           }

           

            /**
             * Getter for userCountry by  Property Number 22
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_property22(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env)
            {
                return adb_ServerData_get_userCountry(_ServerData,
                                             env);
            }

            /**
             * getter for userCountry.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_userCountry(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServerData, NULL);
                  

                return _ServerData->property_userCountry;
             }

            /**
             * setter for userCountry
             */
            axis2_status_t AXIS2_CALL
            adb_ServerData_set_userCountry(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_userCountry)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
                
                if(_ServerData->is_valid_userCountry &&
                        arg_userCountry == _ServerData->property_userCountry)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServerData_reset_userCountry(_ServerData, env);

                
                if(NULL == arg_userCountry)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServerData->property_userCountry = (axis2_char_t *)axutil_strdup(env, arg_userCountry);
                        if(NULL == _ServerData->property_userCountry)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for userCountry");
                            return AXIS2_FAILURE;
                        }
                        _ServerData->is_valid_userCountry = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for userCountry
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_reset_userCountry(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
               

               
            
                
                if(_ServerData->property_userCountry != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ServerData->property_userCountry);
                     _ServerData->property_userCountry = NULL;
                }
            
                
                
                _ServerData->is_valid_userCountry = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether userCountry is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServerData_is_userCountry_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_TRUE);
               
               return !_ServerData->is_valid_userCountry;
           }

           /**
            * Set userCountry to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_set_userCountry_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               return adb_ServerData_reset_userCountry(_ServerData, env);
           }

           

            /**
             * Getter for userHome by  Property Number 23
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_property23(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env)
            {
                return adb_ServerData_get_userHome(_ServerData,
                                             env);
            }

            /**
             * getter for userHome.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_userHome(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServerData, NULL);
                  

                return _ServerData->property_userHome;
             }

            /**
             * setter for userHome
             */
            axis2_status_t AXIS2_CALL
            adb_ServerData_set_userHome(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_userHome)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
                
                if(_ServerData->is_valid_userHome &&
                        arg_userHome == _ServerData->property_userHome)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServerData_reset_userHome(_ServerData, env);

                
                if(NULL == arg_userHome)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServerData->property_userHome = (axis2_char_t *)axutil_strdup(env, arg_userHome);
                        if(NULL == _ServerData->property_userHome)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for userHome");
                            return AXIS2_FAILURE;
                        }
                        _ServerData->is_valid_userHome = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for userHome
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_reset_userHome(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
               

               
            
                
                if(_ServerData->property_userHome != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ServerData->property_userHome);
                     _ServerData->property_userHome = NULL;
                }
            
                
                
                _ServerData->is_valid_userHome = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether userHome is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServerData_is_userHome_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_TRUE);
               
               return !_ServerData->is_valid_userHome;
           }

           /**
            * Set userHome to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_set_userHome_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               return adb_ServerData_reset_userHome(_ServerData, env);
           }

           

            /**
             * Getter for userName by  Property Number 24
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_property24(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env)
            {
                return adb_ServerData_get_userName(_ServerData,
                                             env);
            }

            /**
             * getter for userName.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_userName(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServerData, NULL);
                  

                return _ServerData->property_userName;
             }

            /**
             * setter for userName
             */
            axis2_status_t AXIS2_CALL
            adb_ServerData_set_userName(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_userName)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
                
                if(_ServerData->is_valid_userName &&
                        arg_userName == _ServerData->property_userName)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServerData_reset_userName(_ServerData, env);

                
                if(NULL == arg_userName)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServerData->property_userName = (axis2_char_t *)axutil_strdup(env, arg_userName);
                        if(NULL == _ServerData->property_userName)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for userName");
                            return AXIS2_FAILURE;
                        }
                        _ServerData->is_valid_userName = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for userName
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_reset_userName(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
               

               
            
                
                if(_ServerData->property_userName != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ServerData->property_userName);
                     _ServerData->property_userName = NULL;
                }
            
                
                
                _ServerData->is_valid_userName = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether userName is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServerData_is_userName_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_TRUE);
               
               return !_ServerData->is_valid_userName;
           }

           /**
            * Set userName to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_set_userName_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               return adb_ServerData_reset_userName(_ServerData, env);
           }

           

            /**
             * Getter for userTimezone by  Property Number 25
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_property25(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env)
            {
                return adb_ServerData_get_userTimezone(_ServerData,
                                             env);
            }

            /**
             * getter for userTimezone.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_userTimezone(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServerData, NULL);
                  

                return _ServerData->property_userTimezone;
             }

            /**
             * setter for userTimezone
             */
            axis2_status_t AXIS2_CALL
            adb_ServerData_set_userTimezone(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_userTimezone)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
                
                if(_ServerData->is_valid_userTimezone &&
                        arg_userTimezone == _ServerData->property_userTimezone)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServerData_reset_userTimezone(_ServerData, env);

                
                if(NULL == arg_userTimezone)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServerData->property_userTimezone = (axis2_char_t *)axutil_strdup(env, arg_userTimezone);
                        if(NULL == _ServerData->property_userTimezone)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for userTimezone");
                            return AXIS2_FAILURE;
                        }
                        _ServerData->is_valid_userTimezone = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for userTimezone
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_reset_userTimezone(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
               

               
            
                
                if(_ServerData->property_userTimezone != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ServerData->property_userTimezone);
                     _ServerData->property_userTimezone = NULL;
                }
            
                
                
                _ServerData->is_valid_userTimezone = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether userTimezone is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServerData_is_userTimezone_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_TRUE);
               
               return !_ServerData->is_valid_userTimezone;
           }

           /**
            * Set userTimezone to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_set_userTimezone_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               return adb_ServerData_reset_userTimezone(_ServerData, env);
           }

           

            /**
             * Getter for wso2wsasVersion by  Property Number 26
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_property26(
                adb_ServerData_t* _ServerData,
                const axutil_env_t *env)
            {
                return adb_ServerData_get_wso2wsasVersion(_ServerData,
                                             env);
            }

            /**
             * getter for wso2wsasVersion.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServerData_get_wso2wsasVersion(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServerData, NULL);
                  

                return _ServerData->property_wso2wsasVersion;
             }

            /**
             * setter for wso2wsasVersion
             */
            axis2_status_t AXIS2_CALL
            adb_ServerData_set_wso2wsasVersion(
                    adb_ServerData_t* _ServerData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_wso2wsasVersion)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
                
                if(_ServerData->is_valid_wso2wsasVersion &&
                        arg_wso2wsasVersion == _ServerData->property_wso2wsasVersion)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServerData_reset_wso2wsasVersion(_ServerData, env);

                
                if(NULL == arg_wso2wsasVersion)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServerData->property_wso2wsasVersion = (axis2_char_t *)axutil_strdup(env, arg_wso2wsasVersion);
                        if(NULL == _ServerData->property_wso2wsasVersion)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for wso2wsasVersion");
                            return AXIS2_FAILURE;
                        }
                        _ServerData->is_valid_wso2wsasVersion = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for wso2wsasVersion
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_reset_wso2wsasVersion(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_FAILURE);
               

               
            
                
                if(_ServerData->property_wso2wsasVersion != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ServerData->property_wso2wsasVersion);
                     _ServerData->property_wso2wsasVersion = NULL;
                }
            
                
                
                _ServerData->is_valid_wso2wsasVersion = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether wso2wsasVersion is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServerData_is_wso2wsasVersion_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServerData, AXIS2_TRUE);
               
               return !_ServerData->is_valid_wso2wsasVersion;
           }

           /**
            * Set wso2wsasVersion to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServerData_set_wso2wsasVersion_nil(
                   adb_ServerData_t* _ServerData,
                   const axutil_env_t *env)
           {
               return adb_ServerData_reset_wso2wsasVersion(_ServerData, env);
           }

           

