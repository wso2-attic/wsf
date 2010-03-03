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
         * adb_ServiceMetaData.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_ServiceMetaData.h"
        
                /*
                 * This type was generated from the piece of schema that had
                 * name = ServiceMetaData
                 * Namespace URI = http://mgt.service.carbon.wso2.org/xsd
                 * Namespace Prefix = ns4
                 */
           


        struct adb_ServiceMetaData
        {
            axis2_char_t *property_Type;

            axis2_bool_t property_active;

                
                axis2_bool_t is_valid_active;
            axis2_char_t* property_description;

                
                axis2_bool_t is_valid_description;
            axis2_bool_t property_disableTryit;

                
                axis2_bool_t is_valid_disableTryit;
            axutil_array_list_t* property_eprs;

                
                axis2_bool_t is_valid_eprs;
            axis2_bool_t property_foundWebResources;

                
                axis2_bool_t is_valid_foundWebResources;
            axis2_char_t* property_mtomStatus;

                
                axis2_bool_t is_valid_mtomStatus;
            axis2_char_t* property_name;

                
                axis2_bool_t is_valid_name;
            axutil_array_list_t* property_operations;

                
                axis2_bool_t is_valid_operations;
            axis2_char_t* property_scope;

                
                axis2_bool_t is_valid_scope;
            axis2_char_t* property_serviceGroupName;

                
                axis2_bool_t is_valid_serviceGroupName;
            axis2_char_t* property_serviceId;

                
                axis2_bool_t is_valid_serviceId;
            axis2_char_t* property_serviceType;

                
                axis2_bool_t is_valid_serviceType;
            axis2_char_t* property_serviceVersion;

                
                axis2_bool_t is_valid_serviceVersion;
            axis2_char_t* property_tryitURL;

                
                axis2_bool_t is_valid_tryitURL;
            axutil_array_list_t* property_wsdlURLs;

                
                axis2_bool_t is_valid_wsdlURLs;
            
        };


       /************************* Private Function prototypes ********************************/
        

                axis2_status_t AXIS2_CALL
                adb_ServiceMetaData_set_active_nil(
                        adb_ServiceMetaData_t* _ServiceMetaData,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_ServiceMetaData_set_disableTryit_nil(
                        adb_ServiceMetaData_t* _ServiceMetaData,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_ServiceMetaData_set_foundWebResources_nil(
                        adb_ServiceMetaData_t* _ServiceMetaData,
                        const axutil_env_t *env);
            


       /************************* Function Implmentations ********************************/
        adb_ServiceMetaData_t* AXIS2_CALL
        adb_ServiceMetaData_create(
            const axutil_env_t *env)
        {
            adb_ServiceMetaData_t *_ServiceMetaData = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _ServiceMetaData = (adb_ServiceMetaData_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_ServiceMetaData_t));

            if(NULL == _ServiceMetaData)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_ServiceMetaData, 0, sizeof(adb_ServiceMetaData_t));

            _ServiceMetaData->property_Type = axutil_strdup(env, "adb_ServiceMetaData");
            _ServiceMetaData->is_valid_active  = AXIS2_FALSE;
            _ServiceMetaData->property_description  = NULL;
                  _ServiceMetaData->is_valid_description  = AXIS2_FALSE;
            _ServiceMetaData->is_valid_disableTryit  = AXIS2_FALSE;
            _ServiceMetaData->property_eprs  = NULL;
                  _ServiceMetaData->is_valid_eprs  = AXIS2_FALSE;
            _ServiceMetaData->is_valid_foundWebResources  = AXIS2_FALSE;
            _ServiceMetaData->property_mtomStatus  = NULL;
                  _ServiceMetaData->is_valid_mtomStatus  = AXIS2_FALSE;
            _ServiceMetaData->property_name  = NULL;
                  _ServiceMetaData->is_valid_name  = AXIS2_FALSE;
            _ServiceMetaData->property_operations  = NULL;
                  _ServiceMetaData->is_valid_operations  = AXIS2_FALSE;
            _ServiceMetaData->property_scope  = NULL;
                  _ServiceMetaData->is_valid_scope  = AXIS2_FALSE;
            _ServiceMetaData->property_serviceGroupName  = NULL;
                  _ServiceMetaData->is_valid_serviceGroupName  = AXIS2_FALSE;
            _ServiceMetaData->property_serviceId  = NULL;
                  _ServiceMetaData->is_valid_serviceId  = AXIS2_FALSE;
            _ServiceMetaData->property_serviceType  = NULL;
                  _ServiceMetaData->is_valid_serviceType  = AXIS2_FALSE;
            _ServiceMetaData->property_serviceVersion  = NULL;
                  _ServiceMetaData->is_valid_serviceVersion  = AXIS2_FALSE;
            _ServiceMetaData->property_tryitURL  = NULL;
                  _ServiceMetaData->is_valid_tryitURL  = AXIS2_FALSE;
            _ServiceMetaData->property_wsdlURLs  = NULL;
                  _ServiceMetaData->is_valid_wsdlURLs  = AXIS2_FALSE;
            

            return _ServiceMetaData;
        }

        adb_ServiceMetaData_t* AXIS2_CALL
        adb_ServiceMetaData_create_with_values(
            const axutil_env_t *env,
                axis2_bool_t _active,
                axis2_char_t* _description,
                axis2_bool_t _disableTryit,
                axutil_array_list_t* _eprs,
                axis2_bool_t _foundWebResources,
                axis2_char_t* _mtomStatus,
                axis2_char_t* _name,
                axutil_array_list_t* _operations,
                axis2_char_t* _scope,
                axis2_char_t* _serviceGroupName,
                axis2_char_t* _serviceId,
                axis2_char_t* _serviceType,
                axis2_char_t* _serviceVersion,
                axis2_char_t* _tryitURL,
                axutil_array_list_t* _wsdlURLs)
        {
            adb_ServiceMetaData_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_ServiceMetaData_create(env);

            
              status = adb_ServiceMetaData_set_active(
                                     adb_obj,
                                     env,
                                     _active);
              if(status == AXIS2_FAILURE) {
                  adb_ServiceMetaData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServiceMetaData_set_description(
                                     adb_obj,
                                     env,
                                     _description);
              if(status == AXIS2_FAILURE) {
                  adb_ServiceMetaData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServiceMetaData_set_disableTryit(
                                     adb_obj,
                                     env,
                                     _disableTryit);
              if(status == AXIS2_FAILURE) {
                  adb_ServiceMetaData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServiceMetaData_set_eprs(
                                     adb_obj,
                                     env,
                                     _eprs);
              if(status == AXIS2_FAILURE) {
                  adb_ServiceMetaData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServiceMetaData_set_foundWebResources(
                                     adb_obj,
                                     env,
                                     _foundWebResources);
              if(status == AXIS2_FAILURE) {
                  adb_ServiceMetaData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServiceMetaData_set_mtomStatus(
                                     adb_obj,
                                     env,
                                     _mtomStatus);
              if(status == AXIS2_FAILURE) {
                  adb_ServiceMetaData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServiceMetaData_set_name(
                                     adb_obj,
                                     env,
                                     _name);
              if(status == AXIS2_FAILURE) {
                  adb_ServiceMetaData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServiceMetaData_set_operations(
                                     adb_obj,
                                     env,
                                     _operations);
              if(status == AXIS2_FAILURE) {
                  adb_ServiceMetaData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServiceMetaData_set_scope(
                                     adb_obj,
                                     env,
                                     _scope);
              if(status == AXIS2_FAILURE) {
                  adb_ServiceMetaData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServiceMetaData_set_serviceGroupName(
                                     adb_obj,
                                     env,
                                     _serviceGroupName);
              if(status == AXIS2_FAILURE) {
                  adb_ServiceMetaData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServiceMetaData_set_serviceId(
                                     adb_obj,
                                     env,
                                     _serviceId);
              if(status == AXIS2_FAILURE) {
                  adb_ServiceMetaData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServiceMetaData_set_serviceType(
                                     adb_obj,
                                     env,
                                     _serviceType);
              if(status == AXIS2_FAILURE) {
                  adb_ServiceMetaData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServiceMetaData_set_serviceVersion(
                                     adb_obj,
                                     env,
                                     _serviceVersion);
              if(status == AXIS2_FAILURE) {
                  adb_ServiceMetaData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServiceMetaData_set_tryitURL(
                                     adb_obj,
                                     env,
                                     _tryitURL);
              if(status == AXIS2_FAILURE) {
                  adb_ServiceMetaData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_ServiceMetaData_set_wsdlURLs(
                                     adb_obj,
                                     env,
                                     _wsdlURLs);
              if(status == AXIS2_FAILURE) {
                  adb_ServiceMetaData_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_bool_t AXIS2_CALL
                adb_ServiceMetaData_free_popping_value(
                        adb_ServiceMetaData_t* _ServiceMetaData,
                        const axutil_env_t *env)
                {
                    axis2_bool_t value;

                    
                    
                    value = _ServiceMetaData->property_active;

                    adb_ServiceMetaData_free(_ServiceMetaData, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_free(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env)
        {
            
            
            return axis2_extension_mapper_free(
                (adb_type_t*) _ServiceMetaData,
                env,
                "adb_ServiceMetaData");
            
        }

        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_free_obj(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env)
        {
            
                int i = 0;
                int count = 0;
                void *element = NULL;
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);

            if (_ServiceMetaData->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _ServiceMetaData->property_Type);
            }

            adb_ServiceMetaData_reset_active(_ServiceMetaData, env);
            adb_ServiceMetaData_reset_description(_ServiceMetaData, env);
            adb_ServiceMetaData_reset_disableTryit(_ServiceMetaData, env);
            adb_ServiceMetaData_reset_eprs(_ServiceMetaData, env);
            adb_ServiceMetaData_reset_foundWebResources(_ServiceMetaData, env);
            adb_ServiceMetaData_reset_mtomStatus(_ServiceMetaData, env);
            adb_ServiceMetaData_reset_name(_ServiceMetaData, env);
            adb_ServiceMetaData_reset_operations(_ServiceMetaData, env);
            adb_ServiceMetaData_reset_scope(_ServiceMetaData, env);
            adb_ServiceMetaData_reset_serviceGroupName(_ServiceMetaData, env);
            adb_ServiceMetaData_reset_serviceId(_ServiceMetaData, env);
            adb_ServiceMetaData_reset_serviceType(_ServiceMetaData, env);
            adb_ServiceMetaData_reset_serviceVersion(_ServiceMetaData, env);
            adb_ServiceMetaData_reset_tryitURL(_ServiceMetaData, env);
            adb_ServiceMetaData_reset_wsdlURLs(_ServiceMetaData, env);
            

            if(_ServiceMetaData)
            {
                AXIS2_FREE(env->allocator, _ServiceMetaData);
                _ServiceMetaData = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_deserialize(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return axis2_extension_mapper_deserialize(
                (adb_type_t*) _ServiceMetaData,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs,
                "adb_ServiceMetaData");
            
        }

        axis2_status_t AXIS2_CALL
        adb_ServiceMetaData_deserialize_obj(
                adb_ServiceMetaData_t* _ServiceMetaData,
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
            AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for ServiceMetaData : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              
                      
                      first_node = axiom_node_get_first_child(parent, env);
                      
                    

                     
                     /*
                      * building active element
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
                                   
                                 element_qname = axutil_qname_create(env, "active", "http://mgt.service.carbon.wso2.org/xsd", NULL);
                                 

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
                                                status = adb_ServiceMetaData_set_active(_ServiceMetaData, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_ServiceMetaData_set_active(_ServiceMetaData, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element active");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for active ");
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
                                 
                                 element_qname = axutil_qname_create(env, "description", "http://mgt.service.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ServiceMetaData_set_description(_ServiceMetaData, env,
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
                      * building disableTryit element
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
                                 
                                 element_qname = axutil_qname_create(env, "disableTryit", "http://mgt.service.carbon.wso2.org/xsd", NULL);
                                 

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
                                                status = adb_ServiceMetaData_set_disableTryit(_ServiceMetaData, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_ServiceMetaData_set_disableTryit(_ServiceMetaData, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element disableTryit");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for disableTryit ");
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
                     * building eprs array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building eprs element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "eprs", "http://mgt.service.carbon.wso2.org/xsd", NULL);
                                  
                               
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
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for eprs ");
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
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "eprs (@minOccurs = '0') only have %d elements", i);
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
                                    status = adb_ServiceMetaData_set_eprs(_ServiceMetaData, env,
                                                                   arr_list);
                               }

                             
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 

                     
                     /*
                      * building foundWebResources element
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
                                 
                                 element_qname = axutil_qname_create(env, "foundWebResources", "http://mgt.service.carbon.wso2.org/xsd", NULL);
                                 

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
                                                status = adb_ServiceMetaData_set_foundWebResources(_ServiceMetaData, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_ServiceMetaData_set_foundWebResources(_ServiceMetaData, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element foundWebResources");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for foundWebResources ");
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
                                            status = adb_ServiceMetaData_set_mtomStatus(_ServiceMetaData, env,
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
                                 
                                 element_qname = axutil_qname_create(env, "name", "http://mgt.service.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ServiceMetaData_set_name(_ServiceMetaData, env,
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
                 
                    /*
                     * building operations array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building operations element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "operations", "http://mgt.service.carbon.wso2.org/xsd", NULL);
                                  
                               
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
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for operations ");
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
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "operations (@minOccurs = '0') only have %d elements", i);
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
                                    status = adb_ServiceMetaData_set_operations(_ServiceMetaData, env,
                                                                   arr_list);
                               }

                             
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 

                     
                     /*
                      * building scope element
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
                                 
                                 element_qname = axutil_qname_create(env, "scope", "http://mgt.service.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ServiceMetaData_set_scope(_ServiceMetaData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for scope ");
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
                                            status = adb_ServiceMetaData_set_serviceGroupName(_ServiceMetaData, env,
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
                      * building serviceId element
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
                                 
                                 element_qname = axutil_qname_create(env, "serviceId", "http://mgt.service.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ServiceMetaData_set_serviceId(_ServiceMetaData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for serviceId ");
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
                      * building serviceType element
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
                                 
                                 element_qname = axutil_qname_create(env, "serviceType", "http://mgt.service.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ServiceMetaData_set_serviceType(_ServiceMetaData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for serviceType ");
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
                      * building serviceVersion element
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
                                 
                                 element_qname = axutil_qname_create(env, "serviceVersion", "http://mgt.service.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ServiceMetaData_set_serviceVersion(_ServiceMetaData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for serviceVersion ");
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
                      * building tryitURL element
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
                                 
                                 element_qname = axutil_qname_create(env, "tryitURL", "http://mgt.service.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_ServiceMetaData_set_tryitURL(_ServiceMetaData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for tryitURL ");
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
                     * building wsdlURLs array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building wsdlURLs element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "wsdlURLs", "http://mgt.service.carbon.wso2.org/xsd", NULL);
                                  
                               
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
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for wsdlURLs ");
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
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "wsdlURLs (@minOccurs = '0') only have %d elements", i);
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
                                    status = adb_ServiceMetaData_set_wsdlURLs(_ServiceMetaData, env,
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
          adb_ServiceMetaData_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_ServiceMetaData_declare_parent_namespaces(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_ServiceMetaData_serialize(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
            if (_ServiceMetaData == NULL)
            {
                return adb_ServiceMetaData_serialize_obj(
                    _ServiceMetaData, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            }
            else
            {
                return axis2_extension_mapper_serialize(
                    (adb_type_t*) _ServiceMetaData, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index, "adb_ServiceMetaData");
            }
            
        }

        axiom_node_t* AXIS2_CALL
        adb_ServiceMetaData_serialize_obj(
                adb_ServiceMetaData_t* _ServiceMetaData,
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
                    
                    axis2_char_t text_value_3[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t *text_value_4;
                    axis2_char_t *text_value_4_temp;
                    
                    axis2_char_t text_value_5[ADB_DEFAULT_DIGIT_LIMIT];
                    
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
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, NULL);
            
            
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
              type_attrib = axutil_strcat(env, " ", xsi_prefix, ":type=\"ServiceMetaData\"", NULL);
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
            xsi_type_attri = axiom_attribute_create (env, "type", "ServiceMetaData", xsi_ns);
            
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
                      

                   if (!_ServiceMetaData->is_valid_active)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("active"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("active")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing active element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sactive>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sactive>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_1, (_ServiceMetaData->property_active)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_1, axutil_strlen(text_value_1));
                           
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
                      

                   if (!_ServiceMetaData->is_valid_description)
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
                    
                           text_value_2 = _ServiceMetaData->property_description;
                           
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
                      

                   if (!_ServiceMetaData->is_valid_disableTryit)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("disableTryit"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("disableTryit")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing disableTryit element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sdisableTryit>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sdisableTryit>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_3, (_ServiceMetaData->property_disableTryit)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_3, axutil_strlen(text_value_3));
                           
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
                      

                   if (!_ServiceMetaData->is_valid_eprs)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("eprs"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("eprs")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing eprs array
                      */
                     if (_ServiceMetaData->property_eprs != NULL)
                     {
                        
                            sprintf(start_input_str, "<%s%seprs>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%seprs>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_ServiceMetaData->property_eprs, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_ServiceMetaData->property_eprs, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing eprs element
                      */

                    
                    
                           text_value_4 = (axis2_char_t*)element;
                           
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
                      

                   if (!_ServiceMetaData->is_valid_foundWebResources)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("foundWebResources"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("foundWebResources")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing foundWebResources element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sfoundWebResources>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sfoundWebResources>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_5, (_ServiceMetaData->property_foundWebResources)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_5, axutil_strlen(text_value_5));
                           
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
                      

                   if (!_ServiceMetaData->is_valid_mtomStatus)
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
                    
                           text_value_6 = _ServiceMetaData->property_mtomStatus;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://mgt.service.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://mgt.service.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://mgt.service.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ServiceMetaData->is_valid_name)
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
                    
                           text_value_7 = _ServiceMetaData->property_name;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://mgt.service.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://mgt.service.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://mgt.service.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ServiceMetaData->is_valid_operations)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("operations"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("operations")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing operations array
                      */
                     if (_ServiceMetaData->property_operations != NULL)
                     {
                        
                            sprintf(start_input_str, "<%s%soperations>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%soperations>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_ServiceMetaData->property_operations, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_ServiceMetaData->property_operations, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing operations element
                      */

                    
                    
                           text_value_8 = (axis2_char_t*)element;
                           
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
                      

                   if (!_ServiceMetaData->is_valid_scope)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("scope"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("scope")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing scope element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sscope>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sscope>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_9 = _ServiceMetaData->property_scope;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://mgt.service.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://mgt.service.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://mgt.service.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ServiceMetaData->is_valid_serviceGroupName)
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
                    
                           text_value_10 = _ServiceMetaData->property_serviceGroupName;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://mgt.service.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://mgt.service.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://mgt.service.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ServiceMetaData->is_valid_serviceId)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("serviceId"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("serviceId")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing serviceId element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sserviceId>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sserviceId>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_11 = _ServiceMetaData->property_serviceId;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://mgt.service.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://mgt.service.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://mgt.service.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ServiceMetaData->is_valid_serviceType)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("serviceType"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("serviceType")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing serviceType element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sserviceType>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sserviceType>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_12 = _ServiceMetaData->property_serviceType;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://mgt.service.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://mgt.service.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://mgt.service.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ServiceMetaData->is_valid_serviceVersion)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("serviceVersion"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("serviceVersion")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing serviceVersion element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sserviceVersion>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sserviceVersion>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_13 = _ServiceMetaData->property_serviceVersion;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://mgt.service.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://mgt.service.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://mgt.service.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ServiceMetaData->is_valid_tryitURL)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("tryitURL"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("tryitURL")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing tryitURL element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%stryitURL>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%stryitURL>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_14 = _ServiceMetaData->property_tryitURL;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://mgt.service.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://mgt.service.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://mgt.service.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_ServiceMetaData->is_valid_wsdlURLs)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("wsdlURLs"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("wsdlURLs")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing wsdlURLs array
                      */
                     if (_ServiceMetaData->property_wsdlURLs != NULL)
                     {
                        
                            sprintf(start_input_str, "<%s%swsdlURLs>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%swsdlURLs>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_ServiceMetaData->property_wsdlURLs, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_ServiceMetaData->property_wsdlURLs, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing wsdlURLs element
                      */

                    
                    
                           text_value_15 = (axis2_char_t*)element;
                           
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
                           
                         }
                     }
                   
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 

            return parent;
        }


        

            /**
             * Getter for active by  Property Number 1
             */
            axis2_bool_t AXIS2_CALL
            adb_ServiceMetaData_get_property1(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env)
            {
                return adb_ServiceMetaData_get_active(_ServiceMetaData,
                                             env);
            }

            /**
             * getter for active.
             */
            axis2_bool_t AXIS2_CALL
            adb_ServiceMetaData_get_active(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, (axis2_bool_t)0);
                  

                return _ServiceMetaData->property_active;
             }

            /**
             * setter for active
             */
            axis2_status_t AXIS2_CALL
            adb_ServiceMetaData_set_active(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_active)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);
                
                if(_ServiceMetaData->is_valid_active &&
                        arg_active == _ServiceMetaData->property_active)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServiceMetaData_reset_active(_ServiceMetaData, env);

                _ServiceMetaData->property_active = arg_active;
                        _ServiceMetaData->is_valid_active = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for active
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceMetaData_reset_active(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);
               

               _ServiceMetaData->is_valid_active = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether active is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServiceMetaData_is_active_nil(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_TRUE);
               
               return !_ServiceMetaData->is_valid_active;
           }

           /**
            * Set active to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceMetaData_set_active_nil(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               return adb_ServiceMetaData_reset_active(_ServiceMetaData, env);
           }

           

            /**
             * Getter for description by  Property Number 2
             */
            axis2_char_t* AXIS2_CALL
            adb_ServiceMetaData_get_property2(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env)
            {
                return adb_ServiceMetaData_get_description(_ServiceMetaData,
                                             env);
            }

            /**
             * getter for description.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServiceMetaData_get_description(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, NULL);
                  

                return _ServiceMetaData->property_description;
             }

            /**
             * setter for description
             */
            axis2_status_t AXIS2_CALL
            adb_ServiceMetaData_set_description(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_description)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);
                
                if(_ServiceMetaData->is_valid_description &&
                        arg_description == _ServiceMetaData->property_description)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServiceMetaData_reset_description(_ServiceMetaData, env);

                
                if(NULL == arg_description)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServiceMetaData->property_description = (axis2_char_t *)axutil_strdup(env, arg_description);
                        if(NULL == _ServiceMetaData->property_description)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for description");
                            return AXIS2_FAILURE;
                        }
                        _ServiceMetaData->is_valid_description = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for description
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceMetaData_reset_description(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);
               

               
            
                
                if(_ServiceMetaData->property_description != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ServiceMetaData->property_description);
                     _ServiceMetaData->property_description = NULL;
                }
            
                
                
                _ServiceMetaData->is_valid_description = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether description is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServiceMetaData_is_description_nil(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_TRUE);
               
               return !_ServiceMetaData->is_valid_description;
           }

           /**
            * Set description to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceMetaData_set_description_nil(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               return adb_ServiceMetaData_reset_description(_ServiceMetaData, env);
           }

           

            /**
             * Getter for disableTryit by  Property Number 3
             */
            axis2_bool_t AXIS2_CALL
            adb_ServiceMetaData_get_property3(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env)
            {
                return adb_ServiceMetaData_get_disableTryit(_ServiceMetaData,
                                             env);
            }

            /**
             * getter for disableTryit.
             */
            axis2_bool_t AXIS2_CALL
            adb_ServiceMetaData_get_disableTryit(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, (axis2_bool_t)0);
                  

                return _ServiceMetaData->property_disableTryit;
             }

            /**
             * setter for disableTryit
             */
            axis2_status_t AXIS2_CALL
            adb_ServiceMetaData_set_disableTryit(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_disableTryit)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);
                
                if(_ServiceMetaData->is_valid_disableTryit &&
                        arg_disableTryit == _ServiceMetaData->property_disableTryit)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServiceMetaData_reset_disableTryit(_ServiceMetaData, env);

                _ServiceMetaData->property_disableTryit = arg_disableTryit;
                        _ServiceMetaData->is_valid_disableTryit = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for disableTryit
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceMetaData_reset_disableTryit(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);
               

               _ServiceMetaData->is_valid_disableTryit = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether disableTryit is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServiceMetaData_is_disableTryit_nil(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_TRUE);
               
               return !_ServiceMetaData->is_valid_disableTryit;
           }

           /**
            * Set disableTryit to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceMetaData_set_disableTryit_nil(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               return adb_ServiceMetaData_reset_disableTryit(_ServiceMetaData, env);
           }

           

            /**
             * Getter for eprs by  Property Number 4
             */
            axutil_array_list_t* AXIS2_CALL
            adb_ServiceMetaData_get_property4(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env)
            {
                return adb_ServiceMetaData_get_eprs(_ServiceMetaData,
                                             env);
            }

            /**
             * getter for eprs.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_ServiceMetaData_get_eprs(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, NULL);
                  

                return _ServiceMetaData->property_eprs;
             }

            /**
             * setter for eprs
             */
            axis2_status_t AXIS2_CALL
            adb_ServiceMetaData_set_eprs(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_eprs)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);
                
                if(_ServiceMetaData->is_valid_eprs &&
                        arg_eprs == _ServiceMetaData->property_eprs)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_eprs, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "eprs has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_eprs, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_ServiceMetaData_reset_eprs(_ServiceMetaData, env);

                
                if(NULL == arg_eprs)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServiceMetaData->property_eprs = arg_eprs;
                        if(non_nil_exists)
                        {
                            _ServiceMetaData->is_valid_eprs = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of eprs.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServiceMetaData_get_eprs_at(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env, int i)
            {
                axis2_char_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, NULL);
                  

                if(_ServiceMetaData->property_eprs == NULL)
                {
                    return (axis2_char_t*)0;
                }
                ret_val = (axis2_char_t*)axutil_array_list_get(_ServiceMetaData->property_eprs, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of eprs.
             */
            axis2_status_t AXIS2_CALL
            adb_ServiceMetaData_set_eprs_at(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env, int i,
                    const axis2_char_t* arg_eprs)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);
                
                if( _ServiceMetaData->is_valid_eprs &&
                    _ServiceMetaData->property_eprs &&
                
                    arg_eprs == (axis2_char_t*)axutil_array_list_get(_ServiceMetaData->property_eprs, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_eprs)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_ServiceMetaData->property_eprs != NULL)
                        {
                            size = axutil_array_list_size(_ServiceMetaData->property_eprs, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_ServiceMetaData->property_eprs, env, i))
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
                  

                if(_ServiceMetaData->property_eprs == NULL)
                {
                    _ServiceMetaData->property_eprs = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_ServiceMetaData->property_eprs, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _ServiceMetaData->is_valid_eprs = AXIS2_FALSE;
                        axutil_array_list_set(_ServiceMetaData->property_eprs , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_ServiceMetaData->property_eprs , env, i, axutil_strdup(env, arg_eprs));
                  _ServiceMetaData->is_valid_eprs = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to eprs.
             */
            axis2_status_t AXIS2_CALL
            adb_ServiceMetaData_add_eprs(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env,
                    const axis2_char_t* arg_eprs)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);

                
                    if(NULL == arg_eprs)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_ServiceMetaData->property_eprs == NULL)
                {
                    _ServiceMetaData->property_eprs = axutil_array_list_create(env, 10);
                }
                if(_ServiceMetaData->property_eprs == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for eprs");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_ServiceMetaData->property_eprs , env, axutil_strdup(env, arg_eprs));
                  _ServiceMetaData->is_valid_eprs = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the eprs array.
             */
            int AXIS2_CALL
            adb_ServiceMetaData_sizeof_eprs(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, -1);
                if(_ServiceMetaData->property_eprs == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_ServiceMetaData->property_eprs, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_ServiceMetaData_remove_eprs_at(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env, int i)
            {
                return adb_ServiceMetaData_set_eprs_nil_at(_ServiceMetaData, env, i);
            }

            

           /**
            * resetter for eprs
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceMetaData_reset_eprs(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);
               

               
                  if (_ServiceMetaData->property_eprs != NULL)
                  {
                      count = axutil_array_list_size(_ServiceMetaData->property_eprs, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_ServiceMetaData->property_eprs, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, (axis2_char_t*)element);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_ServiceMetaData->property_eprs, env);
                  }
                _ServiceMetaData->is_valid_eprs = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether eprs is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServiceMetaData_is_eprs_nil(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_TRUE);
               
               return !_ServiceMetaData->is_valid_eprs;
           }

           /**
            * Set eprs to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceMetaData_set_eprs_nil(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               return adb_ServiceMetaData_reset_eprs(_ServiceMetaData, env);
           }

           
           /**
            * Check whether eprs is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_ServiceMetaData_is_eprs_nil_at(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_TRUE);
               
               return (_ServiceMetaData->is_valid_eprs == AXIS2_FALSE ||
                        NULL == _ServiceMetaData->property_eprs || 
                        NULL == axutil_array_list_get(_ServiceMetaData->property_eprs, env, i));
           }

           /**
            * Set eprs to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceMetaData_set_eprs_nil_at(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);

                if(_ServiceMetaData->property_eprs == NULL ||
                            _ServiceMetaData->is_valid_eprs == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_ServiceMetaData->property_eprs, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_ServiceMetaData->property_eprs, env, i))
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
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of eprs is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_ServiceMetaData->property_eprs == NULL)
                {
                    _ServiceMetaData->is_valid_eprs = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_ServiceMetaData->property_eprs, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _ServiceMetaData->is_valid_eprs = AXIS2_FALSE;
                        axutil_array_list_set(_ServiceMetaData->property_eprs , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_ServiceMetaData->property_eprs , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

            /**
             * Getter for foundWebResources by  Property Number 5
             */
            axis2_bool_t AXIS2_CALL
            adb_ServiceMetaData_get_property5(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env)
            {
                return adb_ServiceMetaData_get_foundWebResources(_ServiceMetaData,
                                             env);
            }

            /**
             * getter for foundWebResources.
             */
            axis2_bool_t AXIS2_CALL
            adb_ServiceMetaData_get_foundWebResources(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, (axis2_bool_t)0);
                  

                return _ServiceMetaData->property_foundWebResources;
             }

            /**
             * setter for foundWebResources
             */
            axis2_status_t AXIS2_CALL
            adb_ServiceMetaData_set_foundWebResources(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_foundWebResources)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);
                
                if(_ServiceMetaData->is_valid_foundWebResources &&
                        arg_foundWebResources == _ServiceMetaData->property_foundWebResources)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServiceMetaData_reset_foundWebResources(_ServiceMetaData, env);

                _ServiceMetaData->property_foundWebResources = arg_foundWebResources;
                        _ServiceMetaData->is_valid_foundWebResources = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for foundWebResources
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceMetaData_reset_foundWebResources(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);
               

               _ServiceMetaData->is_valid_foundWebResources = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether foundWebResources is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServiceMetaData_is_foundWebResources_nil(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_TRUE);
               
               return !_ServiceMetaData->is_valid_foundWebResources;
           }

           /**
            * Set foundWebResources to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceMetaData_set_foundWebResources_nil(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               return adb_ServiceMetaData_reset_foundWebResources(_ServiceMetaData, env);
           }

           

            /**
             * Getter for mtomStatus by  Property Number 6
             */
            axis2_char_t* AXIS2_CALL
            adb_ServiceMetaData_get_property6(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env)
            {
                return adb_ServiceMetaData_get_mtomStatus(_ServiceMetaData,
                                             env);
            }

            /**
             * getter for mtomStatus.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServiceMetaData_get_mtomStatus(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, NULL);
                  

                return _ServiceMetaData->property_mtomStatus;
             }

            /**
             * setter for mtomStatus
             */
            axis2_status_t AXIS2_CALL
            adb_ServiceMetaData_set_mtomStatus(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_mtomStatus)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);
                
                if(_ServiceMetaData->is_valid_mtomStatus &&
                        arg_mtomStatus == _ServiceMetaData->property_mtomStatus)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServiceMetaData_reset_mtomStatus(_ServiceMetaData, env);

                
                if(NULL == arg_mtomStatus)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServiceMetaData->property_mtomStatus = (axis2_char_t *)axutil_strdup(env, arg_mtomStatus);
                        if(NULL == _ServiceMetaData->property_mtomStatus)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for mtomStatus");
                            return AXIS2_FAILURE;
                        }
                        _ServiceMetaData->is_valid_mtomStatus = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for mtomStatus
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceMetaData_reset_mtomStatus(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);
               

               
            
                
                if(_ServiceMetaData->property_mtomStatus != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ServiceMetaData->property_mtomStatus);
                     _ServiceMetaData->property_mtomStatus = NULL;
                }
            
                
                
                _ServiceMetaData->is_valid_mtomStatus = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether mtomStatus is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServiceMetaData_is_mtomStatus_nil(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_TRUE);
               
               return !_ServiceMetaData->is_valid_mtomStatus;
           }

           /**
            * Set mtomStatus to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceMetaData_set_mtomStatus_nil(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               return adb_ServiceMetaData_reset_mtomStatus(_ServiceMetaData, env);
           }

           

            /**
             * Getter for name by  Property Number 7
             */
            axis2_char_t* AXIS2_CALL
            adb_ServiceMetaData_get_property7(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env)
            {
                return adb_ServiceMetaData_get_name(_ServiceMetaData,
                                             env);
            }

            /**
             * getter for name.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServiceMetaData_get_name(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, NULL);
                  

                return _ServiceMetaData->property_name;
             }

            /**
             * setter for name
             */
            axis2_status_t AXIS2_CALL
            adb_ServiceMetaData_set_name(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_name)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);
                
                if(_ServiceMetaData->is_valid_name &&
                        arg_name == _ServiceMetaData->property_name)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServiceMetaData_reset_name(_ServiceMetaData, env);

                
                if(NULL == arg_name)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServiceMetaData->property_name = (axis2_char_t *)axutil_strdup(env, arg_name);
                        if(NULL == _ServiceMetaData->property_name)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for name");
                            return AXIS2_FAILURE;
                        }
                        _ServiceMetaData->is_valid_name = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for name
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceMetaData_reset_name(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);
               

               
            
                
                if(_ServiceMetaData->property_name != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ServiceMetaData->property_name);
                     _ServiceMetaData->property_name = NULL;
                }
            
                
                
                _ServiceMetaData->is_valid_name = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether name is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServiceMetaData_is_name_nil(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_TRUE);
               
               return !_ServiceMetaData->is_valid_name;
           }

           /**
            * Set name to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceMetaData_set_name_nil(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               return adb_ServiceMetaData_reset_name(_ServiceMetaData, env);
           }

           

            /**
             * Getter for operations by  Property Number 8
             */
            axutil_array_list_t* AXIS2_CALL
            adb_ServiceMetaData_get_property8(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env)
            {
                return adb_ServiceMetaData_get_operations(_ServiceMetaData,
                                             env);
            }

            /**
             * getter for operations.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_ServiceMetaData_get_operations(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, NULL);
                  

                return _ServiceMetaData->property_operations;
             }

            /**
             * setter for operations
             */
            axis2_status_t AXIS2_CALL
            adb_ServiceMetaData_set_operations(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_operations)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);
                
                if(_ServiceMetaData->is_valid_operations &&
                        arg_operations == _ServiceMetaData->property_operations)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_operations, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "operations has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_operations, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_ServiceMetaData_reset_operations(_ServiceMetaData, env);

                
                if(NULL == arg_operations)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServiceMetaData->property_operations = arg_operations;
                        if(non_nil_exists)
                        {
                            _ServiceMetaData->is_valid_operations = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of operations.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServiceMetaData_get_operations_at(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env, int i)
            {
                axis2_char_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, NULL);
                  

                if(_ServiceMetaData->property_operations == NULL)
                {
                    return (axis2_char_t*)0;
                }
                ret_val = (axis2_char_t*)axutil_array_list_get(_ServiceMetaData->property_operations, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of operations.
             */
            axis2_status_t AXIS2_CALL
            adb_ServiceMetaData_set_operations_at(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env, int i,
                    const axis2_char_t* arg_operations)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);
                
                if( _ServiceMetaData->is_valid_operations &&
                    _ServiceMetaData->property_operations &&
                
                    arg_operations == (axis2_char_t*)axutil_array_list_get(_ServiceMetaData->property_operations, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_operations)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_ServiceMetaData->property_operations != NULL)
                        {
                            size = axutil_array_list_size(_ServiceMetaData->property_operations, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_ServiceMetaData->property_operations, env, i))
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
                  

                if(_ServiceMetaData->property_operations == NULL)
                {
                    _ServiceMetaData->property_operations = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_ServiceMetaData->property_operations, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _ServiceMetaData->is_valid_operations = AXIS2_FALSE;
                        axutil_array_list_set(_ServiceMetaData->property_operations , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_ServiceMetaData->property_operations , env, i, axutil_strdup(env, arg_operations));
                  _ServiceMetaData->is_valid_operations = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to operations.
             */
            axis2_status_t AXIS2_CALL
            adb_ServiceMetaData_add_operations(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env,
                    const axis2_char_t* arg_operations)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);

                
                    if(NULL == arg_operations)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_ServiceMetaData->property_operations == NULL)
                {
                    _ServiceMetaData->property_operations = axutil_array_list_create(env, 10);
                }
                if(_ServiceMetaData->property_operations == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for operations");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_ServiceMetaData->property_operations , env, axutil_strdup(env, arg_operations));
                  _ServiceMetaData->is_valid_operations = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the operations array.
             */
            int AXIS2_CALL
            adb_ServiceMetaData_sizeof_operations(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, -1);
                if(_ServiceMetaData->property_operations == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_ServiceMetaData->property_operations, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_ServiceMetaData_remove_operations_at(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env, int i)
            {
                return adb_ServiceMetaData_set_operations_nil_at(_ServiceMetaData, env, i);
            }

            

           /**
            * resetter for operations
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceMetaData_reset_operations(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);
               

               
                  if (_ServiceMetaData->property_operations != NULL)
                  {
                      count = axutil_array_list_size(_ServiceMetaData->property_operations, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_ServiceMetaData->property_operations, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, (axis2_char_t*)element);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_ServiceMetaData->property_operations, env);
                  }
                _ServiceMetaData->is_valid_operations = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether operations is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServiceMetaData_is_operations_nil(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_TRUE);
               
               return !_ServiceMetaData->is_valid_operations;
           }

           /**
            * Set operations to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceMetaData_set_operations_nil(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               return adb_ServiceMetaData_reset_operations(_ServiceMetaData, env);
           }

           
           /**
            * Check whether operations is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_ServiceMetaData_is_operations_nil_at(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_TRUE);
               
               return (_ServiceMetaData->is_valid_operations == AXIS2_FALSE ||
                        NULL == _ServiceMetaData->property_operations || 
                        NULL == axutil_array_list_get(_ServiceMetaData->property_operations, env, i));
           }

           /**
            * Set operations to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceMetaData_set_operations_nil_at(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);

                if(_ServiceMetaData->property_operations == NULL ||
                            _ServiceMetaData->is_valid_operations == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_ServiceMetaData->property_operations, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_ServiceMetaData->property_operations, env, i))
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
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of operations is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_ServiceMetaData->property_operations == NULL)
                {
                    _ServiceMetaData->is_valid_operations = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_ServiceMetaData->property_operations, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _ServiceMetaData->is_valid_operations = AXIS2_FALSE;
                        axutil_array_list_set(_ServiceMetaData->property_operations , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_ServiceMetaData->property_operations , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

            /**
             * Getter for scope by  Property Number 9
             */
            axis2_char_t* AXIS2_CALL
            adb_ServiceMetaData_get_property9(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env)
            {
                return adb_ServiceMetaData_get_scope(_ServiceMetaData,
                                             env);
            }

            /**
             * getter for scope.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServiceMetaData_get_scope(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, NULL);
                  

                return _ServiceMetaData->property_scope;
             }

            /**
             * setter for scope
             */
            axis2_status_t AXIS2_CALL
            adb_ServiceMetaData_set_scope(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_scope)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);
                
                if(_ServiceMetaData->is_valid_scope &&
                        arg_scope == _ServiceMetaData->property_scope)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServiceMetaData_reset_scope(_ServiceMetaData, env);

                
                if(NULL == arg_scope)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServiceMetaData->property_scope = (axis2_char_t *)axutil_strdup(env, arg_scope);
                        if(NULL == _ServiceMetaData->property_scope)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for scope");
                            return AXIS2_FAILURE;
                        }
                        _ServiceMetaData->is_valid_scope = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for scope
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceMetaData_reset_scope(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);
               

               
            
                
                if(_ServiceMetaData->property_scope != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ServiceMetaData->property_scope);
                     _ServiceMetaData->property_scope = NULL;
                }
            
                
                
                _ServiceMetaData->is_valid_scope = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether scope is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServiceMetaData_is_scope_nil(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_TRUE);
               
               return !_ServiceMetaData->is_valid_scope;
           }

           /**
            * Set scope to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceMetaData_set_scope_nil(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               return adb_ServiceMetaData_reset_scope(_ServiceMetaData, env);
           }

           

            /**
             * Getter for serviceGroupName by  Property Number 10
             */
            axis2_char_t* AXIS2_CALL
            adb_ServiceMetaData_get_property10(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env)
            {
                return adb_ServiceMetaData_get_serviceGroupName(_ServiceMetaData,
                                             env);
            }

            /**
             * getter for serviceGroupName.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServiceMetaData_get_serviceGroupName(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, NULL);
                  

                return _ServiceMetaData->property_serviceGroupName;
             }

            /**
             * setter for serviceGroupName
             */
            axis2_status_t AXIS2_CALL
            adb_ServiceMetaData_set_serviceGroupName(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_serviceGroupName)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);
                
                if(_ServiceMetaData->is_valid_serviceGroupName &&
                        arg_serviceGroupName == _ServiceMetaData->property_serviceGroupName)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServiceMetaData_reset_serviceGroupName(_ServiceMetaData, env);

                
                if(NULL == arg_serviceGroupName)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServiceMetaData->property_serviceGroupName = (axis2_char_t *)axutil_strdup(env, arg_serviceGroupName);
                        if(NULL == _ServiceMetaData->property_serviceGroupName)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for serviceGroupName");
                            return AXIS2_FAILURE;
                        }
                        _ServiceMetaData->is_valid_serviceGroupName = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for serviceGroupName
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceMetaData_reset_serviceGroupName(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);
               

               
            
                
                if(_ServiceMetaData->property_serviceGroupName != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ServiceMetaData->property_serviceGroupName);
                     _ServiceMetaData->property_serviceGroupName = NULL;
                }
            
                
                
                _ServiceMetaData->is_valid_serviceGroupName = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether serviceGroupName is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServiceMetaData_is_serviceGroupName_nil(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_TRUE);
               
               return !_ServiceMetaData->is_valid_serviceGroupName;
           }

           /**
            * Set serviceGroupName to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceMetaData_set_serviceGroupName_nil(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               return adb_ServiceMetaData_reset_serviceGroupName(_ServiceMetaData, env);
           }

           

            /**
             * Getter for serviceId by  Property Number 11
             */
            axis2_char_t* AXIS2_CALL
            adb_ServiceMetaData_get_property11(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env)
            {
                return adb_ServiceMetaData_get_serviceId(_ServiceMetaData,
                                             env);
            }

            /**
             * getter for serviceId.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServiceMetaData_get_serviceId(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, NULL);
                  

                return _ServiceMetaData->property_serviceId;
             }

            /**
             * setter for serviceId
             */
            axis2_status_t AXIS2_CALL
            adb_ServiceMetaData_set_serviceId(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_serviceId)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);
                
                if(_ServiceMetaData->is_valid_serviceId &&
                        arg_serviceId == _ServiceMetaData->property_serviceId)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServiceMetaData_reset_serviceId(_ServiceMetaData, env);

                
                if(NULL == arg_serviceId)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServiceMetaData->property_serviceId = (axis2_char_t *)axutil_strdup(env, arg_serviceId);
                        if(NULL == _ServiceMetaData->property_serviceId)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for serviceId");
                            return AXIS2_FAILURE;
                        }
                        _ServiceMetaData->is_valid_serviceId = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for serviceId
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceMetaData_reset_serviceId(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);
               

               
            
                
                if(_ServiceMetaData->property_serviceId != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ServiceMetaData->property_serviceId);
                     _ServiceMetaData->property_serviceId = NULL;
                }
            
                
                
                _ServiceMetaData->is_valid_serviceId = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether serviceId is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServiceMetaData_is_serviceId_nil(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_TRUE);
               
               return !_ServiceMetaData->is_valid_serviceId;
           }

           /**
            * Set serviceId to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceMetaData_set_serviceId_nil(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               return adb_ServiceMetaData_reset_serviceId(_ServiceMetaData, env);
           }

           

            /**
             * Getter for serviceType by  Property Number 12
             */
            axis2_char_t* AXIS2_CALL
            adb_ServiceMetaData_get_property12(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env)
            {
                return adb_ServiceMetaData_get_serviceType(_ServiceMetaData,
                                             env);
            }

            /**
             * getter for serviceType.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServiceMetaData_get_serviceType(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, NULL);
                  

                return _ServiceMetaData->property_serviceType;
             }

            /**
             * setter for serviceType
             */
            axis2_status_t AXIS2_CALL
            adb_ServiceMetaData_set_serviceType(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_serviceType)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);
                
                if(_ServiceMetaData->is_valid_serviceType &&
                        arg_serviceType == _ServiceMetaData->property_serviceType)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServiceMetaData_reset_serviceType(_ServiceMetaData, env);

                
                if(NULL == arg_serviceType)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServiceMetaData->property_serviceType = (axis2_char_t *)axutil_strdup(env, arg_serviceType);
                        if(NULL == _ServiceMetaData->property_serviceType)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for serviceType");
                            return AXIS2_FAILURE;
                        }
                        _ServiceMetaData->is_valid_serviceType = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for serviceType
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceMetaData_reset_serviceType(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);
               

               
            
                
                if(_ServiceMetaData->property_serviceType != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ServiceMetaData->property_serviceType);
                     _ServiceMetaData->property_serviceType = NULL;
                }
            
                
                
                _ServiceMetaData->is_valid_serviceType = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether serviceType is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServiceMetaData_is_serviceType_nil(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_TRUE);
               
               return !_ServiceMetaData->is_valid_serviceType;
           }

           /**
            * Set serviceType to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceMetaData_set_serviceType_nil(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               return adb_ServiceMetaData_reset_serviceType(_ServiceMetaData, env);
           }

           

            /**
             * Getter for serviceVersion by  Property Number 13
             */
            axis2_char_t* AXIS2_CALL
            adb_ServiceMetaData_get_property13(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env)
            {
                return adb_ServiceMetaData_get_serviceVersion(_ServiceMetaData,
                                             env);
            }

            /**
             * getter for serviceVersion.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServiceMetaData_get_serviceVersion(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, NULL);
                  

                return _ServiceMetaData->property_serviceVersion;
             }

            /**
             * setter for serviceVersion
             */
            axis2_status_t AXIS2_CALL
            adb_ServiceMetaData_set_serviceVersion(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_serviceVersion)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);
                
                if(_ServiceMetaData->is_valid_serviceVersion &&
                        arg_serviceVersion == _ServiceMetaData->property_serviceVersion)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServiceMetaData_reset_serviceVersion(_ServiceMetaData, env);

                
                if(NULL == arg_serviceVersion)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServiceMetaData->property_serviceVersion = (axis2_char_t *)axutil_strdup(env, arg_serviceVersion);
                        if(NULL == _ServiceMetaData->property_serviceVersion)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for serviceVersion");
                            return AXIS2_FAILURE;
                        }
                        _ServiceMetaData->is_valid_serviceVersion = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for serviceVersion
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceMetaData_reset_serviceVersion(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);
               

               
            
                
                if(_ServiceMetaData->property_serviceVersion != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ServiceMetaData->property_serviceVersion);
                     _ServiceMetaData->property_serviceVersion = NULL;
                }
            
                
                
                _ServiceMetaData->is_valid_serviceVersion = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether serviceVersion is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServiceMetaData_is_serviceVersion_nil(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_TRUE);
               
               return !_ServiceMetaData->is_valid_serviceVersion;
           }

           /**
            * Set serviceVersion to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceMetaData_set_serviceVersion_nil(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               return adb_ServiceMetaData_reset_serviceVersion(_ServiceMetaData, env);
           }

           

            /**
             * Getter for tryitURL by  Property Number 14
             */
            axis2_char_t* AXIS2_CALL
            adb_ServiceMetaData_get_property14(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env)
            {
                return adb_ServiceMetaData_get_tryitURL(_ServiceMetaData,
                                             env);
            }

            /**
             * getter for tryitURL.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServiceMetaData_get_tryitURL(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, NULL);
                  

                return _ServiceMetaData->property_tryitURL;
             }

            /**
             * setter for tryitURL
             */
            axis2_status_t AXIS2_CALL
            adb_ServiceMetaData_set_tryitURL(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_tryitURL)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);
                
                if(_ServiceMetaData->is_valid_tryitURL &&
                        arg_tryitURL == _ServiceMetaData->property_tryitURL)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ServiceMetaData_reset_tryitURL(_ServiceMetaData, env);

                
                if(NULL == arg_tryitURL)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServiceMetaData->property_tryitURL = (axis2_char_t *)axutil_strdup(env, arg_tryitURL);
                        if(NULL == _ServiceMetaData->property_tryitURL)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for tryitURL");
                            return AXIS2_FAILURE;
                        }
                        _ServiceMetaData->is_valid_tryitURL = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for tryitURL
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceMetaData_reset_tryitURL(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);
               

               
            
                
                if(_ServiceMetaData->property_tryitURL != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ServiceMetaData->property_tryitURL);
                     _ServiceMetaData->property_tryitURL = NULL;
                }
            
                
                
                _ServiceMetaData->is_valid_tryitURL = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether tryitURL is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServiceMetaData_is_tryitURL_nil(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_TRUE);
               
               return !_ServiceMetaData->is_valid_tryitURL;
           }

           /**
            * Set tryitURL to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceMetaData_set_tryitURL_nil(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               return adb_ServiceMetaData_reset_tryitURL(_ServiceMetaData, env);
           }

           

            /**
             * Getter for wsdlURLs by  Property Number 15
             */
            axutil_array_list_t* AXIS2_CALL
            adb_ServiceMetaData_get_property15(
                adb_ServiceMetaData_t* _ServiceMetaData,
                const axutil_env_t *env)
            {
                return adb_ServiceMetaData_get_wsdlURLs(_ServiceMetaData,
                                             env);
            }

            /**
             * getter for wsdlURLs.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_ServiceMetaData_get_wsdlURLs(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, NULL);
                  

                return _ServiceMetaData->property_wsdlURLs;
             }

            /**
             * setter for wsdlURLs
             */
            axis2_status_t AXIS2_CALL
            adb_ServiceMetaData_set_wsdlURLs(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_wsdlURLs)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);
                
                if(_ServiceMetaData->is_valid_wsdlURLs &&
                        arg_wsdlURLs == _ServiceMetaData->property_wsdlURLs)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_wsdlURLs, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "wsdlURLs has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_wsdlURLs, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_ServiceMetaData_reset_wsdlURLs(_ServiceMetaData, env);

                
                if(NULL == arg_wsdlURLs)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ServiceMetaData->property_wsdlURLs = arg_wsdlURLs;
                        if(non_nil_exists)
                        {
                            _ServiceMetaData->is_valid_wsdlURLs = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of wsdlURLs.
             */
            axis2_char_t* AXIS2_CALL
            adb_ServiceMetaData_get_wsdlURLs_at(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env, int i)
            {
                axis2_char_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, NULL);
                  

                if(_ServiceMetaData->property_wsdlURLs == NULL)
                {
                    return (axis2_char_t*)0;
                }
                ret_val = (axis2_char_t*)axutil_array_list_get(_ServiceMetaData->property_wsdlURLs, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of wsdlURLs.
             */
            axis2_status_t AXIS2_CALL
            adb_ServiceMetaData_set_wsdlURLs_at(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env, int i,
                    const axis2_char_t* arg_wsdlURLs)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);
                
                if( _ServiceMetaData->is_valid_wsdlURLs &&
                    _ServiceMetaData->property_wsdlURLs &&
                
                    arg_wsdlURLs == (axis2_char_t*)axutil_array_list_get(_ServiceMetaData->property_wsdlURLs, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_wsdlURLs)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_ServiceMetaData->property_wsdlURLs != NULL)
                        {
                            size = axutil_array_list_size(_ServiceMetaData->property_wsdlURLs, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_ServiceMetaData->property_wsdlURLs, env, i))
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
                  

                if(_ServiceMetaData->property_wsdlURLs == NULL)
                {
                    _ServiceMetaData->property_wsdlURLs = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_ServiceMetaData->property_wsdlURLs, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _ServiceMetaData->is_valid_wsdlURLs = AXIS2_FALSE;
                        axutil_array_list_set(_ServiceMetaData->property_wsdlURLs , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_ServiceMetaData->property_wsdlURLs , env, i, axutil_strdup(env, arg_wsdlURLs));
                  _ServiceMetaData->is_valid_wsdlURLs = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to wsdlURLs.
             */
            axis2_status_t AXIS2_CALL
            adb_ServiceMetaData_add_wsdlURLs(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env,
                    const axis2_char_t* arg_wsdlURLs)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);

                
                    if(NULL == arg_wsdlURLs)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_ServiceMetaData->property_wsdlURLs == NULL)
                {
                    _ServiceMetaData->property_wsdlURLs = axutil_array_list_create(env, 10);
                }
                if(_ServiceMetaData->property_wsdlURLs == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for wsdlURLs");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_ServiceMetaData->property_wsdlURLs , env, axutil_strdup(env, arg_wsdlURLs));
                  _ServiceMetaData->is_valid_wsdlURLs = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the wsdlURLs array.
             */
            int AXIS2_CALL
            adb_ServiceMetaData_sizeof_wsdlURLs(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, -1);
                if(_ServiceMetaData->property_wsdlURLs == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_ServiceMetaData->property_wsdlURLs, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_ServiceMetaData_remove_wsdlURLs_at(
                    adb_ServiceMetaData_t* _ServiceMetaData,
                    const axutil_env_t *env, int i)
            {
                return adb_ServiceMetaData_set_wsdlURLs_nil_at(_ServiceMetaData, env, i);
            }

            

           /**
            * resetter for wsdlURLs
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceMetaData_reset_wsdlURLs(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);
               

               
                  if (_ServiceMetaData->property_wsdlURLs != NULL)
                  {
                      count = axutil_array_list_size(_ServiceMetaData->property_wsdlURLs, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_ServiceMetaData->property_wsdlURLs, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, (axis2_char_t*)element);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_ServiceMetaData->property_wsdlURLs, env);
                  }
                _ServiceMetaData->is_valid_wsdlURLs = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether wsdlURLs is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ServiceMetaData_is_wsdlURLs_nil(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_TRUE);
               
               return !_ServiceMetaData->is_valid_wsdlURLs;
           }

           /**
            * Set wsdlURLs to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceMetaData_set_wsdlURLs_nil(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env)
           {
               return adb_ServiceMetaData_reset_wsdlURLs(_ServiceMetaData, env);
           }

           
           /**
            * Check whether wsdlURLs is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_ServiceMetaData_is_wsdlURLs_nil_at(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_TRUE);
               
               return (_ServiceMetaData->is_valid_wsdlURLs == AXIS2_FALSE ||
                        NULL == _ServiceMetaData->property_wsdlURLs || 
                        NULL == axutil_array_list_get(_ServiceMetaData->property_wsdlURLs, env, i));
           }

           /**
            * Set wsdlURLs to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_ServiceMetaData_set_wsdlURLs_nil_at(
                   adb_ServiceMetaData_t* _ServiceMetaData,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ServiceMetaData, AXIS2_FAILURE);

                if(_ServiceMetaData->property_wsdlURLs == NULL ||
                            _ServiceMetaData->is_valid_wsdlURLs == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_ServiceMetaData->property_wsdlURLs, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_ServiceMetaData->property_wsdlURLs, env, i))
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
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of wsdlURLs is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_ServiceMetaData->property_wsdlURLs == NULL)
                {
                    _ServiceMetaData->is_valid_wsdlURLs = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_ServiceMetaData->property_wsdlURLs, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _ServiceMetaData->is_valid_wsdlURLs = AXIS2_FALSE;
                        axutil_array_list_set(_ServiceMetaData->property_wsdlURLs , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_ServiceMetaData->property_wsdlURLs , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

