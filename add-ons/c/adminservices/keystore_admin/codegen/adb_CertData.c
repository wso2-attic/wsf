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
         * adb_CertData.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_CertData.h"
        
                /*
                 * This type was generated from the piece of schema that had
                 * name = CertData
                 * Namespace URI = http://service.keystore.security.carbon.wso2.org/xsd
                 * Namespace Prefix = ns1
                 */
           


        struct adb_CertData
        {
            axis2_char_t *property_Type;

            axis2_char_t* property_alias;

                
                axis2_bool_t is_valid_alias;
            axis2_char_t* property_issuerDN;

                
                axis2_bool_t is_valid_issuerDN;
            axis2_char_t* property_notAfter;

                
                axis2_bool_t is_valid_notAfter;
            axis2_char_t* property_notBefore;

                
                axis2_bool_t is_valid_notBefore;
            axis2_char_t* property_publicKey;

                
                axis2_bool_t is_valid_publicKey;
            int property_serialNumber;

                
                axis2_bool_t is_valid_serialNumber;
            axis2_char_t* property_subjectDN;

                
                axis2_bool_t is_valid_subjectDN;
            int property_version;

                
                axis2_bool_t is_valid_version;
            
        };


       /************************* Private Function prototypes ********************************/
        

                axis2_status_t AXIS2_CALL
                adb_CertData_set_version_nil(
                        adb_CertData_t* _CertData,
                        const axutil_env_t *env);
            


       /************************* Function Implmentations ********************************/
        adb_CertData_t* AXIS2_CALL
        adb_CertData_create(
            const axutil_env_t *env)
        {
            adb_CertData_t *_CertData = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _CertData = (adb_CertData_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_CertData_t));

            if(NULL == _CertData)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_CertData, 0, sizeof(adb_CertData_t));

            _CertData->property_Type = axutil_strdup(env, "adb_CertData");
            _CertData->property_alias  = NULL;
                  _CertData->is_valid_alias  = AXIS2_FALSE;
            _CertData->property_issuerDN  = NULL;
                  _CertData->is_valid_issuerDN  = AXIS2_FALSE;
            _CertData->property_notAfter  = NULL;
                  _CertData->is_valid_notAfter  = AXIS2_FALSE;
            _CertData->property_notBefore  = NULL;
                  _CertData->is_valid_notBefore  = AXIS2_FALSE;
            _CertData->property_publicKey  = NULL;
                  _CertData->is_valid_publicKey  = AXIS2_FALSE;
            _CertData->is_valid_serialNumber  = AXIS2_FALSE;
            _CertData->property_subjectDN  = NULL;
                  _CertData->is_valid_subjectDN  = AXIS2_FALSE;
            _CertData->is_valid_version  = AXIS2_FALSE;
            

            return _CertData;
        }

        adb_CertData_t* AXIS2_CALL
        adb_CertData_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _alias,
                axis2_char_t* _issuerDN,
                axis2_char_t* _notAfter,
                axis2_char_t* _notBefore,
                axis2_char_t* _publicKey,
                int _serialNumber,
                axis2_char_t* _subjectDN,
                int _version)
        {
            adb_CertData_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_CertData_create(env);

            
              status = adb_CertData_set_alias(
                                     adb_obj,
                                     env,
                                     _alias);
              if(status == AXIS2_FAILURE) {
                  adb_CertData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_CertData_set_issuerDN(
                                     adb_obj,
                                     env,
                                     _issuerDN);
              if(status == AXIS2_FAILURE) {
                  adb_CertData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_CertData_set_notAfter(
                                     adb_obj,
                                     env,
                                     _notAfter);
              if(status == AXIS2_FAILURE) {
                  adb_CertData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_CertData_set_notBefore(
                                     adb_obj,
                                     env,
                                     _notBefore);
              if(status == AXIS2_FAILURE) {
                  adb_CertData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_CertData_set_publicKey(
                                     adb_obj,
                                     env,
                                     _publicKey);
              if(status == AXIS2_FAILURE) {
                  adb_CertData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_CertData_set_serialNumber(
                                     adb_obj,
                                     env,
                                     _serialNumber);
              if(status == AXIS2_FAILURE) {
                  adb_CertData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_CertData_set_subjectDN(
                                     adb_obj,
                                     env,
                                     _subjectDN);
              if(status == AXIS2_FAILURE) {
                  adb_CertData_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_CertData_set_version(
                                     adb_obj,
                                     env,
                                     _version);
              if(status == AXIS2_FAILURE) {
                  adb_CertData_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_char_t* AXIS2_CALL
                adb_CertData_free_popping_value(
                        adb_CertData_t* _CertData,
                        const axutil_env_t *env)
                {
                    axis2_char_t* value;

                    
                    
                    value = _CertData->property_alias;

                    _CertData->property_alias = (axis2_char_t*)NULL;
                    adb_CertData_free(_CertData, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_CertData_free(
                adb_CertData_t* _CertData,
                const axutil_env_t *env)
        {
            
            
            return axis2_extension_mapper_free(
                (adb_type_t*) _CertData,
                env,
                "adb_CertData");
            
        }

        axis2_status_t AXIS2_CALL
        adb_CertData_free_obj(
                adb_CertData_t* _CertData,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _CertData, AXIS2_FAILURE);

            if (_CertData->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _CertData->property_Type);
            }

            adb_CertData_reset_alias(_CertData, env);
            adb_CertData_reset_issuerDN(_CertData, env);
            adb_CertData_reset_notAfter(_CertData, env);
            adb_CertData_reset_notBefore(_CertData, env);
            adb_CertData_reset_publicKey(_CertData, env);
            adb_CertData_reset_serialNumber(_CertData, env);
            adb_CertData_reset_subjectDN(_CertData, env);
            adb_CertData_reset_version(_CertData, env);
            

            if(_CertData)
            {
                AXIS2_FREE(env->allocator, _CertData);
                _CertData = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_CertData_deserialize(
                adb_CertData_t* _CertData,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return axis2_extension_mapper_deserialize(
                (adb_type_t*) _CertData,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs,
                "adb_CertData");
            
        }

        axis2_status_t AXIS2_CALL
        adb_CertData_deserialize_obj(
                adb_CertData_t* _CertData,
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
            AXIS2_PARAM_CHECK(env->error, _CertData, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for CertData : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              
                      
                      first_node = axiom_node_get_first_child(parent, env);
                      
                    

                     
                     /*
                      * building alias element
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
                                   
                                 element_qname = axutil_qname_create(env, "alias", "http://service.keystore.security.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_CertData_set_alias(_CertData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for alias ");
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
                      * building issuerDN element
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
                                 
                                 element_qname = axutil_qname_create(env, "issuerDN", "http://service.keystore.security.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_CertData_set_issuerDN(_CertData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for issuerDN ");
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
                      * building notAfter element
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
                                 
                                 element_qname = axutil_qname_create(env, "notAfter", "http://service.keystore.security.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_CertData_set_notAfter(_CertData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for notAfter ");
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
                      * building notBefore element
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
                                 
                                 element_qname = axutil_qname_create(env, "notBefore", "http://service.keystore.security.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_CertData_set_notBefore(_CertData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for notBefore ");
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
                      * building publicKey element
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
                                 
                                 element_qname = axutil_qname_create(env, "publicKey", "http://service.keystore.security.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_CertData_set_publicKey(_CertData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for publicKey ");
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
                      * building serialNumber element
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
                                 
                                 element_qname = axutil_qname_create(env, "serialNumber", "http://service.keystore.security.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_CertData_set_serialNumber(_CertData, env,
                                                                   atoi(text_value));
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for serialNumber ");
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
                      * building subjectDN element
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
                                 
                                 element_qname = axutil_qname_create(env, "subjectDN", "http://service.keystore.security.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_CertData_set_subjectDN(_CertData, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for subjectDN ");
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
                      * building version element
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
                                 
                                 element_qname = axutil_qname_create(env, "version", "http://service.keystore.security.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_CertData_set_version(_CertData, env,
                                                                   atoi(text_value));
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element version");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for version ");
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
          adb_CertData_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_CertData_declare_parent_namespaces(
                    adb_CertData_t* _CertData,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_CertData_serialize(
                adb_CertData_t* _CertData,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
            if (_CertData == NULL)
            {
                return adb_CertData_serialize_obj(
                    _CertData, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            }
            else
            {
                return axis2_extension_mapper_serialize(
                    (adb_type_t*) _CertData, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index, "adb_CertData");
            }
            
        }

        axiom_node_t* AXIS2_CALL
        adb_CertData_serialize_obj(
                adb_CertData_t* _CertData,
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
                    
                    axis2_char_t text_value_6[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t *text_value_7;
                    axis2_char_t *text_value_7_temp;
                    
                    axis2_char_t text_value_8[ADB_DEFAULT_DIGIT_LIMIT];
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _CertData, NULL);
            
            
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
              type_attrib = axutil_strcat(env, " ", xsi_prefix, ":type=\"CertData\"", NULL);
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
                                 "http://service.keystore.security.carbon.wso2.org/xsd",
                                 xsi_prefix);
            xsi_type_attri = axiom_attribute_create (env, "type", "CertData", xsi_ns);
            
            axiom_element_add_attribute (parent_element, env, xsi_type_attri, parent);
        
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.keystore.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.keystore.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.keystore.security.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_CertData->is_valid_alias)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("alias"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("alias")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing alias element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%salias>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%salias>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_1 = _CertData->property_alias;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.keystore.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.keystore.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.keystore.security.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_CertData->is_valid_issuerDN)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("issuerDN"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("issuerDN")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing issuerDN element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sissuerDN>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sissuerDN>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_2 = _CertData->property_issuerDN;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.keystore.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.keystore.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.keystore.security.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_CertData->is_valid_notAfter)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("notAfter"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("notAfter")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing notAfter element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%snotAfter>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%snotAfter>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_3 = _CertData->property_notAfter;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.keystore.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.keystore.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.keystore.security.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_CertData->is_valid_notBefore)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("notBefore"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("notBefore")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing notBefore element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%snotBefore>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%snotBefore>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_4 = _CertData->property_notBefore;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.keystore.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.keystore.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.keystore.security.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_CertData->is_valid_publicKey)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("publicKey"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("publicKey")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing publicKey element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%spublicKey>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%spublicKey>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_5 = _CertData->property_publicKey;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.keystore.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.keystore.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.keystore.security.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_CertData->is_valid_serialNumber)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("serialNumber"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("serialNumber")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing serialNumber element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sserialNumber>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sserialNumber>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                               sprintf (text_value_6, AXIS2_PRINTF_INT32_FORMAT_SPECIFIER, _CertData->property_serialNumber);
                             
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_6, axutil_strlen(text_value_6));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.keystore.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.keystore.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.keystore.security.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_CertData->is_valid_subjectDN)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("subjectDN"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("subjectDN")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing subjectDN element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%ssubjectDN>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%ssubjectDN>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_7 = _CertData->property_subjectDN;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://service.keystore.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://service.keystore.security.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://service.keystore.security.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_CertData->is_valid_version)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("version"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("version")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing version element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sversion>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sversion>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                               sprintf (text_value_8, AXIS2_PRINTF_INT32_FORMAT_SPECIFIER, _CertData->property_version);
                             
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_8, axutil_strlen(text_value_8));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 

            return parent;
        }


        

            /**
             * Getter for alias by  Property Number 1
             */
            axis2_char_t* AXIS2_CALL
            adb_CertData_get_property1(
                adb_CertData_t* _CertData,
                const axutil_env_t *env)
            {
                return adb_CertData_get_alias(_CertData,
                                             env);
            }

            /**
             * getter for alias.
             */
            axis2_char_t* AXIS2_CALL
            adb_CertData_get_alias(
                    adb_CertData_t* _CertData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _CertData, NULL);
                  

                return _CertData->property_alias;
             }

            /**
             * setter for alias
             */
            axis2_status_t AXIS2_CALL
            adb_CertData_set_alias(
                    adb_CertData_t* _CertData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_alias)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _CertData, AXIS2_FAILURE);
                
                if(_CertData->is_valid_alias &&
                        arg_alias == _CertData->property_alias)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_CertData_reset_alias(_CertData, env);

                
                if(NULL == arg_alias)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _CertData->property_alias = (axis2_char_t *)axutil_strdup(env, arg_alias);
                        if(NULL == _CertData->property_alias)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for alias");
                            return AXIS2_FAILURE;
                        }
                        _CertData->is_valid_alias = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for alias
            */
           axis2_status_t AXIS2_CALL
           adb_CertData_reset_alias(
                   adb_CertData_t* _CertData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _CertData, AXIS2_FAILURE);
               

               
            
                
                if(_CertData->property_alias != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _CertData->property_alias);
                     _CertData->property_alias = NULL;
                }
            
                
                
                _CertData->is_valid_alias = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether alias is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_CertData_is_alias_nil(
                   adb_CertData_t* _CertData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _CertData, AXIS2_TRUE);
               
               return !_CertData->is_valid_alias;
           }

           /**
            * Set alias to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_CertData_set_alias_nil(
                   adb_CertData_t* _CertData,
                   const axutil_env_t *env)
           {
               return adb_CertData_reset_alias(_CertData, env);
           }

           

            /**
             * Getter for issuerDN by  Property Number 2
             */
            axis2_char_t* AXIS2_CALL
            adb_CertData_get_property2(
                adb_CertData_t* _CertData,
                const axutil_env_t *env)
            {
                return adb_CertData_get_issuerDN(_CertData,
                                             env);
            }

            /**
             * getter for issuerDN.
             */
            axis2_char_t* AXIS2_CALL
            adb_CertData_get_issuerDN(
                    adb_CertData_t* _CertData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _CertData, NULL);
                  

                return _CertData->property_issuerDN;
             }

            /**
             * setter for issuerDN
             */
            axis2_status_t AXIS2_CALL
            adb_CertData_set_issuerDN(
                    adb_CertData_t* _CertData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_issuerDN)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _CertData, AXIS2_FAILURE);
                
                if(_CertData->is_valid_issuerDN &&
                        arg_issuerDN == _CertData->property_issuerDN)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_CertData_reset_issuerDN(_CertData, env);

                
                if(NULL == arg_issuerDN)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _CertData->property_issuerDN = (axis2_char_t *)axutil_strdup(env, arg_issuerDN);
                        if(NULL == _CertData->property_issuerDN)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for issuerDN");
                            return AXIS2_FAILURE;
                        }
                        _CertData->is_valid_issuerDN = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for issuerDN
            */
           axis2_status_t AXIS2_CALL
           adb_CertData_reset_issuerDN(
                   adb_CertData_t* _CertData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _CertData, AXIS2_FAILURE);
               

               
            
                
                if(_CertData->property_issuerDN != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _CertData->property_issuerDN);
                     _CertData->property_issuerDN = NULL;
                }
            
                
                
                _CertData->is_valid_issuerDN = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether issuerDN is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_CertData_is_issuerDN_nil(
                   adb_CertData_t* _CertData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _CertData, AXIS2_TRUE);
               
               return !_CertData->is_valid_issuerDN;
           }

           /**
            * Set issuerDN to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_CertData_set_issuerDN_nil(
                   adb_CertData_t* _CertData,
                   const axutil_env_t *env)
           {
               return adb_CertData_reset_issuerDN(_CertData, env);
           }

           

            /**
             * Getter for notAfter by  Property Number 3
             */
            axis2_char_t* AXIS2_CALL
            adb_CertData_get_property3(
                adb_CertData_t* _CertData,
                const axutil_env_t *env)
            {
                return adb_CertData_get_notAfter(_CertData,
                                             env);
            }

            /**
             * getter for notAfter.
             */
            axis2_char_t* AXIS2_CALL
            adb_CertData_get_notAfter(
                    adb_CertData_t* _CertData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _CertData, NULL);
                  

                return _CertData->property_notAfter;
             }

            /**
             * setter for notAfter
             */
            axis2_status_t AXIS2_CALL
            adb_CertData_set_notAfter(
                    adb_CertData_t* _CertData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_notAfter)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _CertData, AXIS2_FAILURE);
                
                if(_CertData->is_valid_notAfter &&
                        arg_notAfter == _CertData->property_notAfter)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_CertData_reset_notAfter(_CertData, env);

                
                if(NULL == arg_notAfter)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _CertData->property_notAfter = (axis2_char_t *)axutil_strdup(env, arg_notAfter);
                        if(NULL == _CertData->property_notAfter)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for notAfter");
                            return AXIS2_FAILURE;
                        }
                        _CertData->is_valid_notAfter = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for notAfter
            */
           axis2_status_t AXIS2_CALL
           adb_CertData_reset_notAfter(
                   adb_CertData_t* _CertData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _CertData, AXIS2_FAILURE);
               

               
            
                
                if(_CertData->property_notAfter != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _CertData->property_notAfter);
                     _CertData->property_notAfter = NULL;
                }
            
                
                
                _CertData->is_valid_notAfter = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether notAfter is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_CertData_is_notAfter_nil(
                   adb_CertData_t* _CertData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _CertData, AXIS2_TRUE);
               
               return !_CertData->is_valid_notAfter;
           }

           /**
            * Set notAfter to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_CertData_set_notAfter_nil(
                   adb_CertData_t* _CertData,
                   const axutil_env_t *env)
           {
               return adb_CertData_reset_notAfter(_CertData, env);
           }

           

            /**
             * Getter for notBefore by  Property Number 4
             */
            axis2_char_t* AXIS2_CALL
            adb_CertData_get_property4(
                adb_CertData_t* _CertData,
                const axutil_env_t *env)
            {
                return adb_CertData_get_notBefore(_CertData,
                                             env);
            }

            /**
             * getter for notBefore.
             */
            axis2_char_t* AXIS2_CALL
            adb_CertData_get_notBefore(
                    adb_CertData_t* _CertData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _CertData, NULL);
                  

                return _CertData->property_notBefore;
             }

            /**
             * setter for notBefore
             */
            axis2_status_t AXIS2_CALL
            adb_CertData_set_notBefore(
                    adb_CertData_t* _CertData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_notBefore)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _CertData, AXIS2_FAILURE);
                
                if(_CertData->is_valid_notBefore &&
                        arg_notBefore == _CertData->property_notBefore)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_CertData_reset_notBefore(_CertData, env);

                
                if(NULL == arg_notBefore)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _CertData->property_notBefore = (axis2_char_t *)axutil_strdup(env, arg_notBefore);
                        if(NULL == _CertData->property_notBefore)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for notBefore");
                            return AXIS2_FAILURE;
                        }
                        _CertData->is_valid_notBefore = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for notBefore
            */
           axis2_status_t AXIS2_CALL
           adb_CertData_reset_notBefore(
                   adb_CertData_t* _CertData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _CertData, AXIS2_FAILURE);
               

               
            
                
                if(_CertData->property_notBefore != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _CertData->property_notBefore);
                     _CertData->property_notBefore = NULL;
                }
            
                
                
                _CertData->is_valid_notBefore = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether notBefore is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_CertData_is_notBefore_nil(
                   adb_CertData_t* _CertData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _CertData, AXIS2_TRUE);
               
               return !_CertData->is_valid_notBefore;
           }

           /**
            * Set notBefore to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_CertData_set_notBefore_nil(
                   adb_CertData_t* _CertData,
                   const axutil_env_t *env)
           {
               return adb_CertData_reset_notBefore(_CertData, env);
           }

           

            /**
             * Getter for publicKey by  Property Number 5
             */
            axis2_char_t* AXIS2_CALL
            adb_CertData_get_property5(
                adb_CertData_t* _CertData,
                const axutil_env_t *env)
            {
                return adb_CertData_get_publicKey(_CertData,
                                             env);
            }

            /**
             * getter for publicKey.
             */
            axis2_char_t* AXIS2_CALL
            adb_CertData_get_publicKey(
                    adb_CertData_t* _CertData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _CertData, NULL);
                  

                return _CertData->property_publicKey;
             }

            /**
             * setter for publicKey
             */
            axis2_status_t AXIS2_CALL
            adb_CertData_set_publicKey(
                    adb_CertData_t* _CertData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_publicKey)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _CertData, AXIS2_FAILURE);
                
                if(_CertData->is_valid_publicKey &&
                        arg_publicKey == _CertData->property_publicKey)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_CertData_reset_publicKey(_CertData, env);

                
                if(NULL == arg_publicKey)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _CertData->property_publicKey = (axis2_char_t *)axutil_strdup(env, arg_publicKey);
                        if(NULL == _CertData->property_publicKey)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for publicKey");
                            return AXIS2_FAILURE;
                        }
                        _CertData->is_valid_publicKey = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for publicKey
            */
           axis2_status_t AXIS2_CALL
           adb_CertData_reset_publicKey(
                   adb_CertData_t* _CertData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _CertData, AXIS2_FAILURE);
               

               
            
                
                if(_CertData->property_publicKey != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _CertData->property_publicKey);
                     _CertData->property_publicKey = NULL;
                }
            
                
                
                _CertData->is_valid_publicKey = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether publicKey is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_CertData_is_publicKey_nil(
                   adb_CertData_t* _CertData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _CertData, AXIS2_TRUE);
               
               return !_CertData->is_valid_publicKey;
           }

           /**
            * Set publicKey to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_CertData_set_publicKey_nil(
                   adb_CertData_t* _CertData,
                   const axutil_env_t *env)
           {
               return adb_CertData_reset_publicKey(_CertData, env);
           }

           

            /**
             * Getter for serialNumber by  Property Number 6
             */
            int AXIS2_CALL
            adb_CertData_get_property6(
                adb_CertData_t* _CertData,
                const axutil_env_t *env)
            {
                return adb_CertData_get_serialNumber(_CertData,
                                             env);
            }

            /**
             * getter for serialNumber.
             */
            int AXIS2_CALL
            adb_CertData_get_serialNumber(
                    adb_CertData_t* _CertData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (int)0);
                    AXIS2_PARAM_CHECK(env->error, _CertData, (int)0);
                  

                return _CertData->property_serialNumber;
             }

            /**
             * setter for serialNumber
             */
            axis2_status_t AXIS2_CALL
            adb_CertData_set_serialNumber(
                    adb_CertData_t* _CertData,
                    const axutil_env_t *env,
                    const int  arg_serialNumber)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _CertData, AXIS2_FAILURE);
                
                if(_CertData->is_valid_serialNumber &&
                        arg_serialNumber == _CertData->property_serialNumber)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_CertData_reset_serialNumber(_CertData, env);

                _CertData->property_serialNumber = arg_serialNumber;
                        _CertData->is_valid_serialNumber = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for serialNumber
            */
           axis2_status_t AXIS2_CALL
           adb_CertData_reset_serialNumber(
                   adb_CertData_t* _CertData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _CertData, AXIS2_FAILURE);
               

               _CertData->is_valid_serialNumber = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether serialNumber is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_CertData_is_serialNumber_nil(
                   adb_CertData_t* _CertData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _CertData, AXIS2_TRUE);
               
               return !_CertData->is_valid_serialNumber;
           }

           /**
            * Set serialNumber to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_CertData_set_serialNumber_nil(
                   adb_CertData_t* _CertData,
                   const axutil_env_t *env)
           {
               return adb_CertData_reset_serialNumber(_CertData, env);
           }

           

            /**
             * Getter for subjectDN by  Property Number 7
             */
            axis2_char_t* AXIS2_CALL
            adb_CertData_get_property7(
                adb_CertData_t* _CertData,
                const axutil_env_t *env)
            {
                return adb_CertData_get_subjectDN(_CertData,
                                             env);
            }

            /**
             * getter for subjectDN.
             */
            axis2_char_t* AXIS2_CALL
            adb_CertData_get_subjectDN(
                    adb_CertData_t* _CertData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _CertData, NULL);
                  

                return _CertData->property_subjectDN;
             }

            /**
             * setter for subjectDN
             */
            axis2_status_t AXIS2_CALL
            adb_CertData_set_subjectDN(
                    adb_CertData_t* _CertData,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_subjectDN)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _CertData, AXIS2_FAILURE);
                
                if(_CertData->is_valid_subjectDN &&
                        arg_subjectDN == _CertData->property_subjectDN)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_CertData_reset_subjectDN(_CertData, env);

                
                if(NULL == arg_subjectDN)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _CertData->property_subjectDN = (axis2_char_t *)axutil_strdup(env, arg_subjectDN);
                        if(NULL == _CertData->property_subjectDN)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for subjectDN");
                            return AXIS2_FAILURE;
                        }
                        _CertData->is_valid_subjectDN = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for subjectDN
            */
           axis2_status_t AXIS2_CALL
           adb_CertData_reset_subjectDN(
                   adb_CertData_t* _CertData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _CertData, AXIS2_FAILURE);
               

               
            
                
                if(_CertData->property_subjectDN != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _CertData->property_subjectDN);
                     _CertData->property_subjectDN = NULL;
                }
            
                
                
                _CertData->is_valid_subjectDN = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether subjectDN is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_CertData_is_subjectDN_nil(
                   adb_CertData_t* _CertData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _CertData, AXIS2_TRUE);
               
               return !_CertData->is_valid_subjectDN;
           }

           /**
            * Set subjectDN to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_CertData_set_subjectDN_nil(
                   adb_CertData_t* _CertData,
                   const axutil_env_t *env)
           {
               return adb_CertData_reset_subjectDN(_CertData, env);
           }

           

            /**
             * Getter for version by  Property Number 8
             */
            int AXIS2_CALL
            adb_CertData_get_property8(
                adb_CertData_t* _CertData,
                const axutil_env_t *env)
            {
                return adb_CertData_get_version(_CertData,
                                             env);
            }

            /**
             * getter for version.
             */
            int AXIS2_CALL
            adb_CertData_get_version(
                    adb_CertData_t* _CertData,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (int)0);
                    AXIS2_PARAM_CHECK(env->error, _CertData, (int)0);
                  

                return _CertData->property_version;
             }

            /**
             * setter for version
             */
            axis2_status_t AXIS2_CALL
            adb_CertData_set_version(
                    adb_CertData_t* _CertData,
                    const axutil_env_t *env,
                    const int  arg_version)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _CertData, AXIS2_FAILURE);
                
                if(_CertData->is_valid_version &&
                        arg_version == _CertData->property_version)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_CertData_reset_version(_CertData, env);

                _CertData->property_version = arg_version;
                        _CertData->is_valid_version = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for version
            */
           axis2_status_t AXIS2_CALL
           adb_CertData_reset_version(
                   adb_CertData_t* _CertData,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _CertData, AXIS2_FAILURE);
               

               _CertData->is_valid_version = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether version is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_CertData_is_version_nil(
                   adb_CertData_t* _CertData,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _CertData, AXIS2_TRUE);
               
               return !_CertData->is_valid_version;
           }

           /**
            * Set version to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_CertData_set_version_nil(
                   adb_CertData_t* _CertData,
                   const axutil_env_t *env)
           {
               return adb_CertData_reset_version(_CertData, env);
           }

           

