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
         * adb_ModuleMetaData.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_ModuleMetaData.h"
        
                /*
                 * This type was generated from the piece of schema that had
                 * name = ModuleMetaData
                 * Namespace URI = http://mgt.module.carbon.wso2.org/xsd
                 * Namespace Prefix = ns1
                 */
           


        struct adb_ModuleMetaData
        {
            axis2_char_t *property_Type;

            axis2_char_t* property_description;

                
                axis2_bool_t is_valid_description;
            axis2_bool_t property_engagedGlobalLevel;

                
                axis2_bool_t is_valid_engagedGlobalLevel;
            axis2_bool_t property_engagedOperationLevel;

                
                axis2_bool_t is_valid_engagedOperationLevel;
            axis2_bool_t property_engagedServiceGroupLevel;

                
                axis2_bool_t is_valid_engagedServiceGroupLevel;
            axis2_bool_t property_engagedServiceLevel;

                
                axis2_bool_t is_valid_engagedServiceLevel;
            axis2_bool_t property_managedModule;

                
                axis2_bool_t is_valid_managedModule;
            axis2_char_t* property_moduleId;

                
                axis2_bool_t is_valid_moduleId;
            axis2_char_t* property_moduleVersion;

                
                axis2_bool_t is_valid_moduleVersion;
            axis2_char_t* property_modulename;

                
                axis2_bool_t is_valid_modulename;
            
        };


       /************************* Private Function prototypes ********************************/
        

                axis2_status_t AXIS2_CALL
                adb_ModuleMetaData_set_engagedGlobalLevel_nil(
                        adb_ModuleMetaData_t* _ModuleMetaData,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_ModuleMetaData_set_engagedOperationLevel_nil(
                        adb_ModuleMetaData_t* _ModuleMetaData,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_ModuleMetaData_set_engagedServiceGroupLevel_nil(
                        adb_ModuleMetaData_t* _ModuleMetaData,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_ModuleMetaData_set_engagedServiceLevel_nil(
                        adb_ModuleMetaData_t* _ModuleMetaData,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_ModuleMetaData_set_managedModule_nil(
                        adb_ModuleMetaData_t* _ModuleMetaData,
                        const axutil_env_t *env);
            


       /************************* Function Implmentations ********************************/
        adb_ModuleMetaData_t* AXIS2_CALL
        adb_ModuleMetaData_create(
            const axutil_env_t *env)
        {
            adb_ModuleMetaData_t *_ModuleMetaData = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _ModuleMetaData = (adb_ModuleMetaData_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_ModuleMetaData_t));

            if(NULL == _ModuleMetaData)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_ModuleMetaData, 0, sizeof(adb_ModuleMetaData_t));

            _ModuleMetaData->property_Type = axutil_strdup(env, "adb_ModuleMetaData");
            _ModuleMetaData->property_description  = NULL;
                  _ModuleMetaData->is_valid_description  = AXIS2_FALSE;
            _ModuleMetaData->is_valid_engagedGlobalLevel  = AXIS2_FALSE;
            _ModuleMetaData->is_valid_engagedOperationLevel  = AXIS2_FALSE;
            _ModuleMetaData->is_valid_engagedServiceGroupLevel  = AXIS2_FALSE;
            _ModuleMetaData->is_valid_engagedServiceLevel  = AXIS2_FALSE;
            _ModuleMetaData->is_valid_managedModule  = AXIS2_FALSE;
            _ModuleMetaData->property_moduleId  = NULL;
                  _ModuleMetaData->is_valid_moduleId  = AXIS2_FALSE;
            _ModuleMetaData->property_moduleVersion  = NULL;
                  _ModuleMetaData->is_valid_moduleVersion  = AXIS2_FALSE;
            _ModuleMetaData->property_modulename  = NULL;
                  _ModuleMetaData->is_valid_modulename  = AXIS2_FALSE;
            

            return _ModuleMetaData;
        }

        adb_ModuleMetaData_t* AXIS2_CALL
        adb_ModuleMetaData_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _description,
                axis2_bool_t _engagedGlobalLevel,
                axis2_bool_t _engagedOperationLevel,
                axis2_bool_t _engagedServiceGroupLevel,
                axis2_bool_t _engagedServiceLevel,
                axis2_bool_t _managedModule,
                axis2_char_t* _moduleId,
                axis2_char_t* _moduleVersion,
                axis2_char_t* _modulename)
        {
            adb_ModuleMetaData_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_ModuleMetaData_create(env);

            
              status = adb_ModuleMetaData_set_description(
                                     adb_obj,
                                     env,
                                     _description);
              if(status == AXIS2_FAILURE) {
                  adb_ModuleMetaData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ModuleMetaData_set_engagedGlobalLevel(
                                     adb_obj,
                                     env,
                                     _engagedGlobalLevel);
              if(status == AXIS2_FAILURE) {
                  adb_ModuleMetaData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ModuleMetaData_set_engagedOperationLevel(
                                     adb_obj,
                                     env,
                                     _engagedOperationLevel);
              if(status == AXIS2_FAILURE) {
                  adb_ModuleMetaData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ModuleMetaData_set_engagedServiceGroupLevel(
                                     adb_obj,
                                     env,
                                     _engagedServiceGroupLevel);
              if(status == AXIS2_FAILURE) {
                  adb_ModuleMetaData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ModuleMetaData_set_engagedServiceLevel(
                                     adb_obj,
                                     env,
                                     _engagedServiceLevel);
              if(status == AXIS2_FAILURE) {
                  adb_ModuleMetaData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ModuleMetaData_set_managedModule(
                                     adb_obj,
                                     env,
                                     _managedModule);
              if(status == AXIS2_FAILURE) {
                  adb_ModuleMetaData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ModuleMetaData_set_moduleId(
                                     adb_obj,
                                     env,
                                     _moduleId);
              if(status == AXIS2_FAILURE) {
                  adb_ModuleMetaData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ModuleMetaData_set_moduleVersion(
                                     adb_obj,
                                     env,
                                     _moduleVersion);
              if(status == AXIS2_FAILURE) {
                  adb_ModuleMetaData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ModuleMetaData_set_modulename(
                                     adb_obj,
                                     env,
                                     _modulename);
              if(status == AXIS2_FAILURE) {
                  adb_ModuleMetaData_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_char_t* AXIS2_CALL
                adb_ModuleMetaData_free_popping_value(
                        adb_ModuleMetaData_t* _ModuleMetaData,
                        const axutil_env_t *env)
                {
                    axis2_char_t* value;

                    
                    
                    value = _ModuleMetaData->property_description;

                    _ModuleMetaData->property_description = (axis2_char_t*)NULL;
                    adb_ModuleMetaData_free(_ModuleMetaData, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_ModuleMetaData_free(
                adb_ModuleMetaData_t* _ModuleMetaData,
                const axutil_env_t *env)
        {
            
            
            return axis2_extension_mapper_free(
                (adb_type_t*) _ModuleMetaData,
                env,
                "adb_ModuleMetaData");
            
        }

        axis2_status_t AXIS2_CALL
        adb_ModuleMetaData_free_obj(
                adb_ModuleMetaData_t* _ModuleMetaData,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _ModuleMetaData, AXIS2_FAILURE);

            if (_ModuleMetaData->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _ModuleMetaData->property_Type);
            }

            adb_ModuleMetaData_reset_description(_ModuleMetaData, env);
            adb_ModuleMetaData_reset_engagedGlobalLevel(_ModuleMetaData, env);
            adb_ModuleMetaData_reset_engagedOperationLevel(_ModuleMetaData, env);
            adb_ModuleMetaData_reset_engagedServiceGroupLevel(_ModuleMetaData, env);
            adb_ModuleMetaData_reset_engagedServiceLevel(_ModuleMetaData, env);
            adb_ModuleMetaData_reset_managedModule(_ModuleMetaData, env);
            adb_ModuleMetaData_reset_moduleId(_ModuleMetaData, env);
            adb_ModuleMetaData_reset_moduleVersion(_ModuleMetaData, env);
            adb_ModuleMetaData_reset_modulename(_ModuleMetaData, env);
            

            if(_ModuleMetaData)
            {
                AXIS2_FREE(env->allocator, _ModuleMetaData);
                _ModuleMetaData = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_ModuleMetaData_deserialize(
                adb_ModuleMetaData_t* _ModuleMetaData,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return axis2_extension_mapper_deserialize(
                (adb_type_t*) _ModuleMetaData,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs,
                "adb_ModuleMetaData");
            
        }

        axis2_status_t AXIS2_CALL
        adb_ModuleMetaData_deserialize_obj(
                adb_ModuleMetaData_t* _ModuleMetaData,
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
            AXIS2_PARAM_CHECK(env->error, _ModuleMetaData, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for ModuleMetaData : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              
                      
                      first_node = axiom_node_get_first_child(parent, env);
                      
                    

                     
                     /*
                      * building description element
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
                                   
                                 element_qname = axutil_qname_create(env, "description", "http://mgt.module.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ModuleMetaData_set_description(_ModuleMetaData, env,
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
                      * building engagedGlobalLevel element
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
                                 
                                 element_qname = axutil_qname_create(env, "engagedGlobalLevel", "http://mgt.module.carbon.wso2.org/xsd", NULL);
                                 

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
                                                status = adb_ModuleMetaData_set_engagedGlobalLevel(_ModuleMetaData, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_ModuleMetaData_set_engagedGlobalLevel(_ModuleMetaData, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element engagedGlobalLevel");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for engagedGlobalLevel ");
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
                      * building engagedOperationLevel element
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
                                 
                                 element_qname = axutil_qname_create(env, "engagedOperationLevel", "http://mgt.module.carbon.wso2.org/xsd", NULL);
                                 

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
                                                status = adb_ModuleMetaData_set_engagedOperationLevel(_ModuleMetaData, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_ModuleMetaData_set_engagedOperationLevel(_ModuleMetaData, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element engagedOperationLevel");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for engagedOperationLevel ");
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
                      * building engagedServiceGroupLevel element
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
                                 
                                 element_qname = axutil_qname_create(env, "engagedServiceGroupLevel", "http://mgt.module.carbon.wso2.org/xsd", NULL);
                                 

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
                                                status = adb_ModuleMetaData_set_engagedServiceGroupLevel(_ModuleMetaData, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_ModuleMetaData_set_engagedServiceGroupLevel(_ModuleMetaData, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element engagedServiceGroupLevel");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for engagedServiceGroupLevel ");
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
                      * building engagedServiceLevel element
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
                                 
                                 element_qname = axutil_qname_create(env, "engagedServiceLevel", "http://mgt.module.carbon.wso2.org/xsd", NULL);
                                 

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
                                                status = adb_ModuleMetaData_set_engagedServiceLevel(_ModuleMetaData, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_ModuleMetaData_set_engagedServiceLevel(_ModuleMetaData, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element engagedServiceLevel");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for engagedServiceLevel ");
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
                      * building managedModule element
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
                                 
                                 element_qname = axutil_qname_create(env, "managedModule", "http://mgt.module.carbon.wso2.org/xsd", NULL);
                                 

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
                                                status = adb_ModuleMetaData_set_managedModule(_ModuleMetaData, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_ModuleMetaData_set_managedModule(_ModuleMetaData, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element managedModule");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for managedModule ");
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
                      * building moduleId element
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
                                 
                                 element_qname = axutil_qname_create(env, "moduleId", "http://mgt.module.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ModuleMetaData_set_moduleId(_ModuleMetaData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for moduleId ");
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
                      * building moduleVersion element
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
                                 
                                 element_qname = axutil_qname_create(env, "moduleVersion", "http://mgt.module.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ModuleMetaData_set_moduleVersion(_ModuleMetaData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for moduleVersion ");
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
                      * building modulename element
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
                                 
                                 element_qname = axutil_qname_create(env, "modulename", "http://mgt.module.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ModuleMetaData_set_modulename(_ModuleMetaData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for modulename ");
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
          adb_ModuleMetaData_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_ModuleMetaData_declare_parent_namespaces(
                    adb_ModuleMetaData_t* _ModuleMetaData,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_ModuleMetaData_serialize(
                adb_ModuleMetaData_t* _ModuleMetaData,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
            if (_ModuleMetaData == NULL)
            {
                return adb_ModuleMetaData_serialize_obj(
                    _ModuleMetaData, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            }
            else
            {
                return axis2_extension_mapper_serialize(
                    (adb_type_t*) _ModuleMetaData, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index, "adb_ModuleMetaData");
            }
            
        }

        axiom_node_t* AXIS2_CALL
        adb_ModuleMetaData_serialize_obj(
                adb_ModuleMetaData_t* _ModuleMetaData,
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
                    
                    axis2_char_t text_value_3[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t text_value_4[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t text_value_5[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t text_value_6[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t *text_value_7;
                    axis2_char_t *text_value_7_temp;
                    
                    axis2_char_t *text_value_8;
                    axis2_char_t *text_value_8_temp;
                    
                    axis2_char_t *text_value_9;
                    axis2_char_t *text_value_9_temp;
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _ModuleMetaData, NULL);
            
            
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
              type_attrib = axutil_strcat(env, " ", xsi_prefix, ":type=\"ModuleMetaData\"", NULL);
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
                                 "http://mgt.module.carbon.wso2.org/xsd",
                                 xsi_prefix);
            xsi_type_attri = axiom_attribute_create (env, "type", "ModuleMetaData", xsi_ns);
            
            axiom_element_add_attribute (parent_element, env, xsi_type_attri, parent);
        
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://mgt.module.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://mgt.module.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://mgt.module.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ModuleMetaData->is_valid_description)
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
                    
                           text_value_1 = _ModuleMetaData->property_description;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://mgt.module.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://mgt.module.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://mgt.module.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ModuleMetaData->is_valid_engagedGlobalLevel)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("engagedGlobalLevel"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("engagedGlobalLevel")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing engagedGlobalLevel element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sengagedGlobalLevel>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sengagedGlobalLevel>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_2, (_ModuleMetaData->property_engagedGlobalLevel)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_2, axutil_strlen(text_value_2));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://mgt.module.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://mgt.module.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://mgt.module.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ModuleMetaData->is_valid_engagedOperationLevel)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("engagedOperationLevel"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("engagedOperationLevel")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing engagedOperationLevel element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sengagedOperationLevel>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sengagedOperationLevel>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_3, (_ModuleMetaData->property_engagedOperationLevel)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_3, axutil_strlen(text_value_3));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://mgt.module.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://mgt.module.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://mgt.module.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ModuleMetaData->is_valid_engagedServiceGroupLevel)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("engagedServiceGroupLevel"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("engagedServiceGroupLevel")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing engagedServiceGroupLevel element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sengagedServiceGroupLevel>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sengagedServiceGroupLevel>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_4, (_ModuleMetaData->property_engagedServiceGroupLevel)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_4, axutil_strlen(text_value_4));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://mgt.module.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://mgt.module.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://mgt.module.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ModuleMetaData->is_valid_engagedServiceLevel)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("engagedServiceLevel"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("engagedServiceLevel")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing engagedServiceLevel element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sengagedServiceLevel>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sengagedServiceLevel>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_5, (_ModuleMetaData->property_engagedServiceLevel)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_5, axutil_strlen(text_value_5));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://mgt.module.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://mgt.module.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://mgt.module.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ModuleMetaData->is_valid_managedModule)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("managedModule"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("managedModule")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing managedModule element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%smanagedModule>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%smanagedModule>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_6, (_ModuleMetaData->property_managedModule)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_6, axutil_strlen(text_value_6));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://mgt.module.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://mgt.module.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://mgt.module.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ModuleMetaData->is_valid_moduleId)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("moduleId"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("moduleId")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing moduleId element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%smoduleId>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%smoduleId>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_7 = _ModuleMetaData->property_moduleId;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://mgt.module.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://mgt.module.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://mgt.module.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ModuleMetaData->is_valid_moduleVersion)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("moduleVersion"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("moduleVersion")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing moduleVersion element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%smoduleVersion>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%smoduleVersion>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_8 = _ModuleMetaData->property_moduleVersion;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://mgt.module.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://mgt.module.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://mgt.module.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ModuleMetaData->is_valid_modulename)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("modulename"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("modulename")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing modulename element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%smodulename>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%smodulename>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_9 = _ModuleMetaData->property_modulename;
                           
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

                 

            return parent;
        }


        

            /**
             * Getter for description by  Property Number 1
             */
            axis2_char_t* AXIS2_CALL
            adb_ModuleMetaData_get_property1(
                adb_ModuleMetaData_t* _ModuleMetaData,
                const axutil_env_t *env)
            {
                return adb_ModuleMetaData_get_description(_ModuleMetaData,
                                             env);
            }

            /**
             * getter for description.
             */
            axis2_char_t* AXIS2_CALL
            adb_ModuleMetaData_get_description(
                    adb_ModuleMetaData_t* _ModuleMetaData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ModuleMetaData, NULL);
                  

                return _ModuleMetaData->property_description;
             }

            /**
             * setter for description
             */
            axis2_status_t AXIS2_CALL
            adb_ModuleMetaData_set_description(
                    adb_ModuleMetaData_t* _ModuleMetaData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_description)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ModuleMetaData, AXIS2_FAILURE);
                
                if(_ModuleMetaData->is_valid_description &&
                        arg_description == _ModuleMetaData->property_description)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ModuleMetaData_reset_description(_ModuleMetaData, env);

                
                if(NULL == arg_description)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ModuleMetaData->property_description = (axis2_char_t *)axutil_strdup(env, arg_description);
                        if(NULL == _ModuleMetaData->property_description)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for description");
                            return AXIS2_FAILURE;
                        }
                        _ModuleMetaData->is_valid_description = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for description
            */
           axis2_status_t AXIS2_CALL
           adb_ModuleMetaData_reset_description(
                   adb_ModuleMetaData_t* _ModuleMetaData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ModuleMetaData, AXIS2_FAILURE);
               

               
            
                
                if(_ModuleMetaData->property_description != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ModuleMetaData->property_description);
                     _ModuleMetaData->property_description = NULL;
                }
            
                
                
                _ModuleMetaData->is_valid_description = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether description is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ModuleMetaData_is_description_nil(
                   adb_ModuleMetaData_t* _ModuleMetaData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ModuleMetaData, AXIS2_TRUE);
               
               return !_ModuleMetaData->is_valid_description;
           }

           /**
            * Set description to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ModuleMetaData_set_description_nil(
                   adb_ModuleMetaData_t* _ModuleMetaData,
                   const axutil_env_t *env)
           {
               return adb_ModuleMetaData_reset_description(_ModuleMetaData, env);
           }

           

            /**
             * Getter for engagedGlobalLevel by  Property Number 2
             */
            axis2_bool_t AXIS2_CALL
            adb_ModuleMetaData_get_property2(
                adb_ModuleMetaData_t* _ModuleMetaData,
                const axutil_env_t *env)
            {
                return adb_ModuleMetaData_get_engagedGlobalLevel(_ModuleMetaData,
                                             env);
            }

            /**
             * getter for engagedGlobalLevel.
             */
            axis2_bool_t AXIS2_CALL
            adb_ModuleMetaData_get_engagedGlobalLevel(
                    adb_ModuleMetaData_t* _ModuleMetaData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _ModuleMetaData, (axis2_bool_t)0);
                  

                return _ModuleMetaData->property_engagedGlobalLevel;
             }

            /**
             * setter for engagedGlobalLevel
             */
            axis2_status_t AXIS2_CALL
            adb_ModuleMetaData_set_engagedGlobalLevel(
                    adb_ModuleMetaData_t* _ModuleMetaData,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_engagedGlobalLevel)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ModuleMetaData, AXIS2_FAILURE);
                
                if(_ModuleMetaData->is_valid_engagedGlobalLevel &&
                        arg_engagedGlobalLevel == _ModuleMetaData->property_engagedGlobalLevel)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ModuleMetaData_reset_engagedGlobalLevel(_ModuleMetaData, env);

                _ModuleMetaData->property_engagedGlobalLevel = arg_engagedGlobalLevel;
                        _ModuleMetaData->is_valid_engagedGlobalLevel = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for engagedGlobalLevel
            */
           axis2_status_t AXIS2_CALL
           adb_ModuleMetaData_reset_engagedGlobalLevel(
                   adb_ModuleMetaData_t* _ModuleMetaData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ModuleMetaData, AXIS2_FAILURE);
               

               _ModuleMetaData->is_valid_engagedGlobalLevel = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether engagedGlobalLevel is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ModuleMetaData_is_engagedGlobalLevel_nil(
                   adb_ModuleMetaData_t* _ModuleMetaData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ModuleMetaData, AXIS2_TRUE);
               
               return !_ModuleMetaData->is_valid_engagedGlobalLevel;
           }

           /**
            * Set engagedGlobalLevel to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ModuleMetaData_set_engagedGlobalLevel_nil(
                   adb_ModuleMetaData_t* _ModuleMetaData,
                   const axutil_env_t *env)
           {
               return adb_ModuleMetaData_reset_engagedGlobalLevel(_ModuleMetaData, env);
           }

           

            /**
             * Getter for engagedOperationLevel by  Property Number 3
             */
            axis2_bool_t AXIS2_CALL
            adb_ModuleMetaData_get_property3(
                adb_ModuleMetaData_t* _ModuleMetaData,
                const axutil_env_t *env)
            {
                return adb_ModuleMetaData_get_engagedOperationLevel(_ModuleMetaData,
                                             env);
            }

            /**
             * getter for engagedOperationLevel.
             */
            axis2_bool_t AXIS2_CALL
            adb_ModuleMetaData_get_engagedOperationLevel(
                    adb_ModuleMetaData_t* _ModuleMetaData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _ModuleMetaData, (axis2_bool_t)0);
                  

                return _ModuleMetaData->property_engagedOperationLevel;
             }

            /**
             * setter for engagedOperationLevel
             */
            axis2_status_t AXIS2_CALL
            adb_ModuleMetaData_set_engagedOperationLevel(
                    adb_ModuleMetaData_t* _ModuleMetaData,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_engagedOperationLevel)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ModuleMetaData, AXIS2_FAILURE);
                
                if(_ModuleMetaData->is_valid_engagedOperationLevel &&
                        arg_engagedOperationLevel == _ModuleMetaData->property_engagedOperationLevel)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ModuleMetaData_reset_engagedOperationLevel(_ModuleMetaData, env);

                _ModuleMetaData->property_engagedOperationLevel = arg_engagedOperationLevel;
                        _ModuleMetaData->is_valid_engagedOperationLevel = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for engagedOperationLevel
            */
           axis2_status_t AXIS2_CALL
           adb_ModuleMetaData_reset_engagedOperationLevel(
                   adb_ModuleMetaData_t* _ModuleMetaData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ModuleMetaData, AXIS2_FAILURE);
               

               _ModuleMetaData->is_valid_engagedOperationLevel = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether engagedOperationLevel is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ModuleMetaData_is_engagedOperationLevel_nil(
                   adb_ModuleMetaData_t* _ModuleMetaData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ModuleMetaData, AXIS2_TRUE);
               
               return !_ModuleMetaData->is_valid_engagedOperationLevel;
           }

           /**
            * Set engagedOperationLevel to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ModuleMetaData_set_engagedOperationLevel_nil(
                   adb_ModuleMetaData_t* _ModuleMetaData,
                   const axutil_env_t *env)
           {
               return adb_ModuleMetaData_reset_engagedOperationLevel(_ModuleMetaData, env);
           }

           

            /**
             * Getter for engagedServiceGroupLevel by  Property Number 4
             */
            axis2_bool_t AXIS2_CALL
            adb_ModuleMetaData_get_property4(
                adb_ModuleMetaData_t* _ModuleMetaData,
                const axutil_env_t *env)
            {
                return adb_ModuleMetaData_get_engagedServiceGroupLevel(_ModuleMetaData,
                                             env);
            }

            /**
             * getter for engagedServiceGroupLevel.
             */
            axis2_bool_t AXIS2_CALL
            adb_ModuleMetaData_get_engagedServiceGroupLevel(
                    adb_ModuleMetaData_t* _ModuleMetaData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _ModuleMetaData, (axis2_bool_t)0);
                  

                return _ModuleMetaData->property_engagedServiceGroupLevel;
             }

            /**
             * setter for engagedServiceGroupLevel
             */
            axis2_status_t AXIS2_CALL
            adb_ModuleMetaData_set_engagedServiceGroupLevel(
                    adb_ModuleMetaData_t* _ModuleMetaData,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_engagedServiceGroupLevel)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ModuleMetaData, AXIS2_FAILURE);
                
                if(_ModuleMetaData->is_valid_engagedServiceGroupLevel &&
                        arg_engagedServiceGroupLevel == _ModuleMetaData->property_engagedServiceGroupLevel)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ModuleMetaData_reset_engagedServiceGroupLevel(_ModuleMetaData, env);

                _ModuleMetaData->property_engagedServiceGroupLevel = arg_engagedServiceGroupLevel;
                        _ModuleMetaData->is_valid_engagedServiceGroupLevel = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for engagedServiceGroupLevel
            */
           axis2_status_t AXIS2_CALL
           adb_ModuleMetaData_reset_engagedServiceGroupLevel(
                   adb_ModuleMetaData_t* _ModuleMetaData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ModuleMetaData, AXIS2_FAILURE);
               

               _ModuleMetaData->is_valid_engagedServiceGroupLevel = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether engagedServiceGroupLevel is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ModuleMetaData_is_engagedServiceGroupLevel_nil(
                   adb_ModuleMetaData_t* _ModuleMetaData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ModuleMetaData, AXIS2_TRUE);
               
               return !_ModuleMetaData->is_valid_engagedServiceGroupLevel;
           }

           /**
            * Set engagedServiceGroupLevel to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ModuleMetaData_set_engagedServiceGroupLevel_nil(
                   adb_ModuleMetaData_t* _ModuleMetaData,
                   const axutil_env_t *env)
           {
               return adb_ModuleMetaData_reset_engagedServiceGroupLevel(_ModuleMetaData, env);
           }

           

            /**
             * Getter for engagedServiceLevel by  Property Number 5
             */
            axis2_bool_t AXIS2_CALL
            adb_ModuleMetaData_get_property5(
                adb_ModuleMetaData_t* _ModuleMetaData,
                const axutil_env_t *env)
            {
                return adb_ModuleMetaData_get_engagedServiceLevel(_ModuleMetaData,
                                             env);
            }

            /**
             * getter for engagedServiceLevel.
             */
            axis2_bool_t AXIS2_CALL
            adb_ModuleMetaData_get_engagedServiceLevel(
                    adb_ModuleMetaData_t* _ModuleMetaData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _ModuleMetaData, (axis2_bool_t)0);
                  

                return _ModuleMetaData->property_engagedServiceLevel;
             }

            /**
             * setter for engagedServiceLevel
             */
            axis2_status_t AXIS2_CALL
            adb_ModuleMetaData_set_engagedServiceLevel(
                    adb_ModuleMetaData_t* _ModuleMetaData,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_engagedServiceLevel)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ModuleMetaData, AXIS2_FAILURE);
                
                if(_ModuleMetaData->is_valid_engagedServiceLevel &&
                        arg_engagedServiceLevel == _ModuleMetaData->property_engagedServiceLevel)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ModuleMetaData_reset_engagedServiceLevel(_ModuleMetaData, env);

                _ModuleMetaData->property_engagedServiceLevel = arg_engagedServiceLevel;
                        _ModuleMetaData->is_valid_engagedServiceLevel = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for engagedServiceLevel
            */
           axis2_status_t AXIS2_CALL
           adb_ModuleMetaData_reset_engagedServiceLevel(
                   adb_ModuleMetaData_t* _ModuleMetaData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ModuleMetaData, AXIS2_FAILURE);
               

               _ModuleMetaData->is_valid_engagedServiceLevel = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether engagedServiceLevel is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ModuleMetaData_is_engagedServiceLevel_nil(
                   adb_ModuleMetaData_t* _ModuleMetaData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ModuleMetaData, AXIS2_TRUE);
               
               return !_ModuleMetaData->is_valid_engagedServiceLevel;
           }

           /**
            * Set engagedServiceLevel to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ModuleMetaData_set_engagedServiceLevel_nil(
                   adb_ModuleMetaData_t* _ModuleMetaData,
                   const axutil_env_t *env)
           {
               return adb_ModuleMetaData_reset_engagedServiceLevel(_ModuleMetaData, env);
           }

           

            /**
             * Getter for managedModule by  Property Number 6
             */
            axis2_bool_t AXIS2_CALL
            adb_ModuleMetaData_get_property6(
                adb_ModuleMetaData_t* _ModuleMetaData,
                const axutil_env_t *env)
            {
                return adb_ModuleMetaData_get_managedModule(_ModuleMetaData,
                                             env);
            }

            /**
             * getter for managedModule.
             */
            axis2_bool_t AXIS2_CALL
            adb_ModuleMetaData_get_managedModule(
                    adb_ModuleMetaData_t* _ModuleMetaData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _ModuleMetaData, (axis2_bool_t)0);
                  

                return _ModuleMetaData->property_managedModule;
             }

            /**
             * setter for managedModule
             */
            axis2_status_t AXIS2_CALL
            adb_ModuleMetaData_set_managedModule(
                    adb_ModuleMetaData_t* _ModuleMetaData,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_managedModule)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ModuleMetaData, AXIS2_FAILURE);
                
                if(_ModuleMetaData->is_valid_managedModule &&
                        arg_managedModule == _ModuleMetaData->property_managedModule)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ModuleMetaData_reset_managedModule(_ModuleMetaData, env);

                _ModuleMetaData->property_managedModule = arg_managedModule;
                        _ModuleMetaData->is_valid_managedModule = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for managedModule
            */
           axis2_status_t AXIS2_CALL
           adb_ModuleMetaData_reset_managedModule(
                   adb_ModuleMetaData_t* _ModuleMetaData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ModuleMetaData, AXIS2_FAILURE);
               

               _ModuleMetaData->is_valid_managedModule = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether managedModule is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ModuleMetaData_is_managedModule_nil(
                   adb_ModuleMetaData_t* _ModuleMetaData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ModuleMetaData, AXIS2_TRUE);
               
               return !_ModuleMetaData->is_valid_managedModule;
           }

           /**
            * Set managedModule to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ModuleMetaData_set_managedModule_nil(
                   adb_ModuleMetaData_t* _ModuleMetaData,
                   const axutil_env_t *env)
           {
               return adb_ModuleMetaData_reset_managedModule(_ModuleMetaData, env);
           }

           

            /**
             * Getter for moduleId by  Property Number 7
             */
            axis2_char_t* AXIS2_CALL
            adb_ModuleMetaData_get_property7(
                adb_ModuleMetaData_t* _ModuleMetaData,
                const axutil_env_t *env)
            {
                return adb_ModuleMetaData_get_moduleId(_ModuleMetaData,
                                             env);
            }

            /**
             * getter for moduleId.
             */
            axis2_char_t* AXIS2_CALL
            adb_ModuleMetaData_get_moduleId(
                    adb_ModuleMetaData_t* _ModuleMetaData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ModuleMetaData, NULL);
                  

                return _ModuleMetaData->property_moduleId;
             }

            /**
             * setter for moduleId
             */
            axis2_status_t AXIS2_CALL
            adb_ModuleMetaData_set_moduleId(
                    adb_ModuleMetaData_t* _ModuleMetaData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_moduleId)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ModuleMetaData, AXIS2_FAILURE);
                
                if(_ModuleMetaData->is_valid_moduleId &&
                        arg_moduleId == _ModuleMetaData->property_moduleId)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ModuleMetaData_reset_moduleId(_ModuleMetaData, env);

                
                if(NULL == arg_moduleId)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ModuleMetaData->property_moduleId = (axis2_char_t *)axutil_strdup(env, arg_moduleId);
                        if(NULL == _ModuleMetaData->property_moduleId)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for moduleId");
                            return AXIS2_FAILURE;
                        }
                        _ModuleMetaData->is_valid_moduleId = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for moduleId
            */
           axis2_status_t AXIS2_CALL
           adb_ModuleMetaData_reset_moduleId(
                   adb_ModuleMetaData_t* _ModuleMetaData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ModuleMetaData, AXIS2_FAILURE);
               

               
            
                
                if(_ModuleMetaData->property_moduleId != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ModuleMetaData->property_moduleId);
                     _ModuleMetaData->property_moduleId = NULL;
                }
            
                
                
                _ModuleMetaData->is_valid_moduleId = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether moduleId is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ModuleMetaData_is_moduleId_nil(
                   adb_ModuleMetaData_t* _ModuleMetaData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ModuleMetaData, AXIS2_TRUE);
               
               return !_ModuleMetaData->is_valid_moduleId;
           }

           /**
            * Set moduleId to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ModuleMetaData_set_moduleId_nil(
                   adb_ModuleMetaData_t* _ModuleMetaData,
                   const axutil_env_t *env)
           {
               return adb_ModuleMetaData_reset_moduleId(_ModuleMetaData, env);
           }

           

            /**
             * Getter for moduleVersion by  Property Number 8
             */
            axis2_char_t* AXIS2_CALL
            adb_ModuleMetaData_get_property8(
                adb_ModuleMetaData_t* _ModuleMetaData,
                const axutil_env_t *env)
            {
                return adb_ModuleMetaData_get_moduleVersion(_ModuleMetaData,
                                             env);
            }

            /**
             * getter for moduleVersion.
             */
            axis2_char_t* AXIS2_CALL
            adb_ModuleMetaData_get_moduleVersion(
                    adb_ModuleMetaData_t* _ModuleMetaData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ModuleMetaData, NULL);
                  

                return _ModuleMetaData->property_moduleVersion;
             }

            /**
             * setter for moduleVersion
             */
            axis2_status_t AXIS2_CALL
            adb_ModuleMetaData_set_moduleVersion(
                    adb_ModuleMetaData_t* _ModuleMetaData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_moduleVersion)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ModuleMetaData, AXIS2_FAILURE);
                
                if(_ModuleMetaData->is_valid_moduleVersion &&
                        arg_moduleVersion == _ModuleMetaData->property_moduleVersion)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ModuleMetaData_reset_moduleVersion(_ModuleMetaData, env);

                
                if(NULL == arg_moduleVersion)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ModuleMetaData->property_moduleVersion = (axis2_char_t *)axutil_strdup(env, arg_moduleVersion);
                        if(NULL == _ModuleMetaData->property_moduleVersion)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for moduleVersion");
                            return AXIS2_FAILURE;
                        }
                        _ModuleMetaData->is_valid_moduleVersion = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for moduleVersion
            */
           axis2_status_t AXIS2_CALL
           adb_ModuleMetaData_reset_moduleVersion(
                   adb_ModuleMetaData_t* _ModuleMetaData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ModuleMetaData, AXIS2_FAILURE);
               

               
            
                
                if(_ModuleMetaData->property_moduleVersion != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ModuleMetaData->property_moduleVersion);
                     _ModuleMetaData->property_moduleVersion = NULL;
                }
            
                
                
                _ModuleMetaData->is_valid_moduleVersion = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether moduleVersion is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ModuleMetaData_is_moduleVersion_nil(
                   adb_ModuleMetaData_t* _ModuleMetaData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ModuleMetaData, AXIS2_TRUE);
               
               return !_ModuleMetaData->is_valid_moduleVersion;
           }

           /**
            * Set moduleVersion to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ModuleMetaData_set_moduleVersion_nil(
                   adb_ModuleMetaData_t* _ModuleMetaData,
                   const axutil_env_t *env)
           {
               return adb_ModuleMetaData_reset_moduleVersion(_ModuleMetaData, env);
           }

           

            /**
             * Getter for modulename by  Property Number 9
             */
            axis2_char_t* AXIS2_CALL
            adb_ModuleMetaData_get_property9(
                adb_ModuleMetaData_t* _ModuleMetaData,
                const axutil_env_t *env)
            {
                return adb_ModuleMetaData_get_modulename(_ModuleMetaData,
                                             env);
            }

            /**
             * getter for modulename.
             */
            axis2_char_t* AXIS2_CALL
            adb_ModuleMetaData_get_modulename(
                    adb_ModuleMetaData_t* _ModuleMetaData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ModuleMetaData, NULL);
                  

                return _ModuleMetaData->property_modulename;
             }

            /**
             * setter for modulename
             */
            axis2_status_t AXIS2_CALL
            adb_ModuleMetaData_set_modulename(
                    adb_ModuleMetaData_t* _ModuleMetaData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_modulename)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ModuleMetaData, AXIS2_FAILURE);
                
                if(_ModuleMetaData->is_valid_modulename &&
                        arg_modulename == _ModuleMetaData->property_modulename)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ModuleMetaData_reset_modulename(_ModuleMetaData, env);

                
                if(NULL == arg_modulename)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ModuleMetaData->property_modulename = (axis2_char_t *)axutil_strdup(env, arg_modulename);
                        if(NULL == _ModuleMetaData->property_modulename)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for modulename");
                            return AXIS2_FAILURE;
                        }
                        _ModuleMetaData->is_valid_modulename = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for modulename
            */
           axis2_status_t AXIS2_CALL
           adb_ModuleMetaData_reset_modulename(
                   adb_ModuleMetaData_t* _ModuleMetaData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ModuleMetaData, AXIS2_FAILURE);
               

               
            
                
                if(_ModuleMetaData->property_modulename != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ModuleMetaData->property_modulename);
                     _ModuleMetaData->property_modulename = NULL;
                }
            
                
                
                _ModuleMetaData->is_valid_modulename = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether modulename is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ModuleMetaData_is_modulename_nil(
                   adb_ModuleMetaData_t* _ModuleMetaData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ModuleMetaData, AXIS2_TRUE);
               
               return !_ModuleMetaData->is_valid_modulename;
           }

           /**
            * Set modulename to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ModuleMetaData_set_modulename_nil(
                   adb_ModuleMetaData_t* _ModuleMetaData,
                   const axutil_env_t *env)
           {
               return adb_ModuleMetaData_reset_modulename(_ModuleMetaData, env);
           }

           

