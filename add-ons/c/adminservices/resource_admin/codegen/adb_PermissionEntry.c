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
         * adb_PermissionEntry.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_PermissionEntry.h"
        
                /*
                 * This type was generated from the piece of schema that had
                 * name = PermissionEntry
                 * Namespace URI = http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd
                 * Namespace Prefix = ns3
                 */
           


        struct adb_PermissionEntry
        {
            axis2_char_t *property_Type;

            axis2_bool_t property_authorizeAllow;

                
                axis2_bool_t is_valid_authorizeAllow;
            axis2_bool_t property_authorizeDeny;

                
                axis2_bool_t is_valid_authorizeDeny;
            axis2_bool_t property_deleteAllow;

                
                axis2_bool_t is_valid_deleteAllow;
            axis2_bool_t property_deleteDeny;

                
                axis2_bool_t is_valid_deleteDeny;
            axis2_bool_t property_readAllow;

                
                axis2_bool_t is_valid_readAllow;
            axis2_bool_t property_readDeny;

                
                axis2_bool_t is_valid_readDeny;
            axis2_char_t* property_userName;

                
                axis2_bool_t is_valid_userName;
            axis2_bool_t property_writeAllow;

                
                axis2_bool_t is_valid_writeAllow;
            axis2_bool_t property_writeDeny;

                
                axis2_bool_t is_valid_writeDeny;
            
        };


       /************************* Private Function prototypes ********************************/
        

                axis2_status_t AXIS2_CALL
                adb_PermissionEntry_set_authorizeAllow_nil(
                        adb_PermissionEntry_t* _PermissionEntry,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_PermissionEntry_set_authorizeDeny_nil(
                        adb_PermissionEntry_t* _PermissionEntry,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_PermissionEntry_set_deleteAllow_nil(
                        adb_PermissionEntry_t* _PermissionEntry,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_PermissionEntry_set_deleteDeny_nil(
                        adb_PermissionEntry_t* _PermissionEntry,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_PermissionEntry_set_readAllow_nil(
                        adb_PermissionEntry_t* _PermissionEntry,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_PermissionEntry_set_readDeny_nil(
                        adb_PermissionEntry_t* _PermissionEntry,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_PermissionEntry_set_writeAllow_nil(
                        adb_PermissionEntry_t* _PermissionEntry,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_PermissionEntry_set_writeDeny_nil(
                        adb_PermissionEntry_t* _PermissionEntry,
                        const axutil_env_t *env);
            


       /************************* Function Implmentations ********************************/
        adb_PermissionEntry_t* AXIS2_CALL
        adb_PermissionEntry_create(
            const axutil_env_t *env)
        {
            adb_PermissionEntry_t *_PermissionEntry = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _PermissionEntry = (adb_PermissionEntry_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_PermissionEntry_t));

            if(NULL == _PermissionEntry)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_PermissionEntry, 0, sizeof(adb_PermissionEntry_t));

            _PermissionEntry->property_Type = axutil_strdup(env, "adb_PermissionEntry");
            _PermissionEntry->is_valid_authorizeAllow  = AXIS2_FALSE;
            _PermissionEntry->is_valid_authorizeDeny  = AXIS2_FALSE;
            _PermissionEntry->is_valid_deleteAllow  = AXIS2_FALSE;
            _PermissionEntry->is_valid_deleteDeny  = AXIS2_FALSE;
            _PermissionEntry->is_valid_readAllow  = AXIS2_FALSE;
            _PermissionEntry->is_valid_readDeny  = AXIS2_FALSE;
            _PermissionEntry->property_userName  = NULL;
                  _PermissionEntry->is_valid_userName  = AXIS2_FALSE;
            _PermissionEntry->is_valid_writeAllow  = AXIS2_FALSE;
            _PermissionEntry->is_valid_writeDeny  = AXIS2_FALSE;
            

            return _PermissionEntry;
        }

        adb_PermissionEntry_t* AXIS2_CALL
        adb_PermissionEntry_create_with_values(
            const axutil_env_t *env,
                axis2_bool_t _authorizeAllow,
                axis2_bool_t _authorizeDeny,
                axis2_bool_t _deleteAllow,
                axis2_bool_t _deleteDeny,
                axis2_bool_t _readAllow,
                axis2_bool_t _readDeny,
                axis2_char_t* _userName,
                axis2_bool_t _writeAllow,
                axis2_bool_t _writeDeny)
        {
            adb_PermissionEntry_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_PermissionEntry_create(env);

            
              status = adb_PermissionEntry_set_authorizeAllow(
                                     adb_obj,
                                     env,
                                     _authorizeAllow);
              if(status == AXIS2_FAILURE) {
                  adb_PermissionEntry_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_PermissionEntry_set_authorizeDeny(
                                     adb_obj,
                                     env,
                                     _authorizeDeny);
              if(status == AXIS2_FAILURE) {
                  adb_PermissionEntry_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_PermissionEntry_set_deleteAllow(
                                     adb_obj,
                                     env,
                                     _deleteAllow);
              if(status == AXIS2_FAILURE) {
                  adb_PermissionEntry_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_PermissionEntry_set_deleteDeny(
                                     adb_obj,
                                     env,
                                     _deleteDeny);
              if(status == AXIS2_FAILURE) {
                  adb_PermissionEntry_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_PermissionEntry_set_readAllow(
                                     adb_obj,
                                     env,
                                     _readAllow);
              if(status == AXIS2_FAILURE) {
                  adb_PermissionEntry_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_PermissionEntry_set_readDeny(
                                     adb_obj,
                                     env,
                                     _readDeny);
              if(status == AXIS2_FAILURE) {
                  adb_PermissionEntry_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_PermissionEntry_set_userName(
                                     adb_obj,
                                     env,
                                     _userName);
              if(status == AXIS2_FAILURE) {
                  adb_PermissionEntry_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_PermissionEntry_set_writeAllow(
                                     adb_obj,
                                     env,
                                     _writeAllow);
              if(status == AXIS2_FAILURE) {
                  adb_PermissionEntry_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_PermissionEntry_set_writeDeny(
                                     adb_obj,
                                     env,
                                     _writeDeny);
              if(status == AXIS2_FAILURE) {
                  adb_PermissionEntry_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_bool_t AXIS2_CALL
                adb_PermissionEntry_free_popping_value(
                        adb_PermissionEntry_t* _PermissionEntry,
                        const axutil_env_t *env)
                {
                    axis2_bool_t value;

                    
                    
                    value = _PermissionEntry->property_authorizeAllow;

                    adb_PermissionEntry_free(_PermissionEntry, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_PermissionEntry_free(
                adb_PermissionEntry_t* _PermissionEntry,
                const axutil_env_t *env)
        {
            
            
            return axis2_extension_mapper_free(
                (adb_type_t*) _PermissionEntry,
                env,
                "adb_PermissionEntry");
            
        }

        axis2_status_t AXIS2_CALL
        adb_PermissionEntry_free_obj(
                adb_PermissionEntry_t* _PermissionEntry,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _PermissionEntry, AXIS2_FAILURE);

            if (_PermissionEntry->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _PermissionEntry->property_Type);
            }

            adb_PermissionEntry_reset_authorizeAllow(_PermissionEntry, env);
            adb_PermissionEntry_reset_authorizeDeny(_PermissionEntry, env);
            adb_PermissionEntry_reset_deleteAllow(_PermissionEntry, env);
            adb_PermissionEntry_reset_deleteDeny(_PermissionEntry, env);
            adb_PermissionEntry_reset_readAllow(_PermissionEntry, env);
            adb_PermissionEntry_reset_readDeny(_PermissionEntry, env);
            adb_PermissionEntry_reset_userName(_PermissionEntry, env);
            adb_PermissionEntry_reset_writeAllow(_PermissionEntry, env);
            adb_PermissionEntry_reset_writeDeny(_PermissionEntry, env);
            

            if(_PermissionEntry)
            {
                AXIS2_FREE(env->allocator, _PermissionEntry);
                _PermissionEntry = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_PermissionEntry_deserialize(
                adb_PermissionEntry_t* _PermissionEntry,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return axis2_extension_mapper_deserialize(
                (adb_type_t*) _PermissionEntry,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs,
                "adb_PermissionEntry");
            
        }

        axis2_status_t AXIS2_CALL
        adb_PermissionEntry_deserialize_obj(
                adb_PermissionEntry_t* _PermissionEntry,
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
            AXIS2_PARAM_CHECK(env->error, _PermissionEntry, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for PermissionEntry : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              
                      
                      first_node = axiom_node_get_first_child(parent, env);
                      
                    

                     
                     /*
                      * building authorizeAllow element
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
                                   
                                 element_qname = axutil_qname_create(env, "authorizeAllow", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                                status = adb_PermissionEntry_set_authorizeAllow(_PermissionEntry, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_PermissionEntry_set_authorizeAllow(_PermissionEntry, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element authorizeAllow");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for authorizeAllow ");
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
                      * building authorizeDeny element
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
                                 
                                 element_qname = axutil_qname_create(env, "authorizeDeny", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                                status = adb_PermissionEntry_set_authorizeDeny(_PermissionEntry, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_PermissionEntry_set_authorizeDeny(_PermissionEntry, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element authorizeDeny");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for authorizeDeny ");
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
                      * building deleteAllow element
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
                                 
                                 element_qname = axutil_qname_create(env, "deleteAllow", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                                status = adb_PermissionEntry_set_deleteAllow(_PermissionEntry, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_PermissionEntry_set_deleteAllow(_PermissionEntry, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element deleteAllow");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for deleteAllow ");
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
                      * building deleteDeny element
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
                                 
                                 element_qname = axutil_qname_create(env, "deleteDeny", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                                status = adb_PermissionEntry_set_deleteDeny(_PermissionEntry, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_PermissionEntry_set_deleteDeny(_PermissionEntry, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element deleteDeny");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for deleteDeny ");
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
                      * building readAllow element
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
                                 
                                 element_qname = axutil_qname_create(env, "readAllow", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                                status = adb_PermissionEntry_set_readAllow(_PermissionEntry, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_PermissionEntry_set_readAllow(_PermissionEntry, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element readAllow");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for readAllow ");
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
                      * building readDeny element
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
                                 
                                 element_qname = axutil_qname_create(env, "readDeny", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                                status = adb_PermissionEntry_set_readDeny(_PermissionEntry, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_PermissionEntry_set_readDeny(_PermissionEntry, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element readDeny");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for readDeny ");
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
                                 
                                 element_qname = axutil_qname_create(env, "userName", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_PermissionEntry_set_userName(_PermissionEntry, env,
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
                      * building writeAllow element
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
                                 
                                 element_qname = axutil_qname_create(env, "writeAllow", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                                status = adb_PermissionEntry_set_writeAllow(_PermissionEntry, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_PermissionEntry_set_writeAllow(_PermissionEntry, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element writeAllow");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for writeAllow ");
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
                      * building writeDeny element
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
                                 
                                 element_qname = axutil_qname_create(env, "writeDeny", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                                status = adb_PermissionEntry_set_writeDeny(_PermissionEntry, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_PermissionEntry_set_writeDeny(_PermissionEntry, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element writeDeny");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for writeDeny ");
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
          adb_PermissionEntry_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_PermissionEntry_declare_parent_namespaces(
                    adb_PermissionEntry_t* _PermissionEntry,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_PermissionEntry_serialize(
                adb_PermissionEntry_t* _PermissionEntry,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
            if (_PermissionEntry == NULL)
            {
                return adb_PermissionEntry_serialize_obj(
                    _PermissionEntry, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            }
            else
            {
                return axis2_extension_mapper_serialize(
                    (adb_type_t*) _PermissionEntry, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index, "adb_PermissionEntry");
            }
            
        }

        axiom_node_t* AXIS2_CALL
        adb_PermissionEntry_serialize_obj(
                adb_PermissionEntry_t* _PermissionEntry,
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
                    
                    axis2_char_t text_value_3[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t text_value_4[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t text_value_5[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t text_value_6[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t *text_value_7;
                    axis2_char_t *text_value_7_temp;
                    
                    axis2_char_t text_value_8[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t text_value_9[ADB_DEFAULT_DIGIT_LIMIT];
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _PermissionEntry, NULL);
            
            
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
              type_attrib = axutil_strcat(env, " ", xsi_prefix, ":type=\"PermissionEntry\"", NULL);
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
                                 "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd",
                                 xsi_prefix);
            xsi_type_attri = axiom_attribute_create (env, "type", "PermissionEntry", xsi_ns);
            
            axiom_element_add_attribute (parent_element, env, xsi_type_attri, parent);
        
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_PermissionEntry->is_valid_authorizeAllow)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("authorizeAllow"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("authorizeAllow")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing authorizeAllow element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sauthorizeAllow>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sauthorizeAllow>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_1, (_PermissionEntry->property_authorizeAllow)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_1, axutil_strlen(text_value_1));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_PermissionEntry->is_valid_authorizeDeny)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("authorizeDeny"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("authorizeDeny")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing authorizeDeny element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sauthorizeDeny>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sauthorizeDeny>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_2, (_PermissionEntry->property_authorizeDeny)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_2, axutil_strlen(text_value_2));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_PermissionEntry->is_valid_deleteAllow)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("deleteAllow"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("deleteAllow")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing deleteAllow element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sdeleteAllow>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sdeleteAllow>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_3, (_PermissionEntry->property_deleteAllow)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_3, axutil_strlen(text_value_3));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_PermissionEntry->is_valid_deleteDeny)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("deleteDeny"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("deleteDeny")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing deleteDeny element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sdeleteDeny>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sdeleteDeny>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_4, (_PermissionEntry->property_deleteDeny)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_4, axutil_strlen(text_value_4));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_PermissionEntry->is_valid_readAllow)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("readAllow"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("readAllow")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing readAllow element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sreadAllow>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sreadAllow>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_5, (_PermissionEntry->property_readAllow)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_5, axutil_strlen(text_value_5));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_PermissionEntry->is_valid_readDeny)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("readDeny"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("readDeny")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing readDeny element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sreadDeny>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sreadDeny>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_6, (_PermissionEntry->property_readDeny)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_6, axutil_strlen(text_value_6));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_PermissionEntry->is_valid_userName)
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
                    
                           text_value_7 = _PermissionEntry->property_userName;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_PermissionEntry->is_valid_writeAllow)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("writeAllow"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("writeAllow")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing writeAllow element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%swriteAllow>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%swriteAllow>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_8, (_PermissionEntry->property_writeAllow)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_8, axutil_strlen(text_value_8));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_PermissionEntry->is_valid_writeDeny)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("writeDeny"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("writeDeny")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing writeDeny element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%swriteDeny>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%swriteDeny>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_9, (_PermissionEntry->property_writeDeny)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_9, axutil_strlen(text_value_9));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 

            return parent;
        }


        

            /**
             * Getter for authorizeAllow by  Property Number 1
             */
            axis2_bool_t AXIS2_CALL
            adb_PermissionEntry_get_property1(
                adb_PermissionEntry_t* _PermissionEntry,
                const axutil_env_t *env)
            {
                return adb_PermissionEntry_get_authorizeAllow(_PermissionEntry,
                                             env);
            }

            /**
             * getter for authorizeAllow.
             */
            axis2_bool_t AXIS2_CALL
            adb_PermissionEntry_get_authorizeAllow(
                    adb_PermissionEntry_t* _PermissionEntry,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _PermissionEntry, (axis2_bool_t)0);
                  

                return _PermissionEntry->property_authorizeAllow;
             }

            /**
             * setter for authorizeAllow
             */
            axis2_status_t AXIS2_CALL
            adb_PermissionEntry_set_authorizeAllow(
                    adb_PermissionEntry_t* _PermissionEntry,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_authorizeAllow)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _PermissionEntry, AXIS2_FAILURE);
                
                if(_PermissionEntry->is_valid_authorizeAllow &&
                        arg_authorizeAllow == _PermissionEntry->property_authorizeAllow)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_PermissionEntry_reset_authorizeAllow(_PermissionEntry, env);

                _PermissionEntry->property_authorizeAllow = arg_authorizeAllow;
                        _PermissionEntry->is_valid_authorizeAllow = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for authorizeAllow
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionEntry_reset_authorizeAllow(
                   adb_PermissionEntry_t* _PermissionEntry,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _PermissionEntry, AXIS2_FAILURE);
               

               _PermissionEntry->is_valid_authorizeAllow = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether authorizeAllow is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_PermissionEntry_is_authorizeAllow_nil(
                   adb_PermissionEntry_t* _PermissionEntry,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _PermissionEntry, AXIS2_TRUE);
               
               return !_PermissionEntry->is_valid_authorizeAllow;
           }

           /**
            * Set authorizeAllow to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionEntry_set_authorizeAllow_nil(
                   adb_PermissionEntry_t* _PermissionEntry,
                   const axutil_env_t *env)
           {
               return adb_PermissionEntry_reset_authorizeAllow(_PermissionEntry, env);
           }

           

            /**
             * Getter for authorizeDeny by  Property Number 2
             */
            axis2_bool_t AXIS2_CALL
            adb_PermissionEntry_get_property2(
                adb_PermissionEntry_t* _PermissionEntry,
                const axutil_env_t *env)
            {
                return adb_PermissionEntry_get_authorizeDeny(_PermissionEntry,
                                             env);
            }

            /**
             * getter for authorizeDeny.
             */
            axis2_bool_t AXIS2_CALL
            adb_PermissionEntry_get_authorizeDeny(
                    adb_PermissionEntry_t* _PermissionEntry,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _PermissionEntry, (axis2_bool_t)0);
                  

                return _PermissionEntry->property_authorizeDeny;
             }

            /**
             * setter for authorizeDeny
             */
            axis2_status_t AXIS2_CALL
            adb_PermissionEntry_set_authorizeDeny(
                    adb_PermissionEntry_t* _PermissionEntry,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_authorizeDeny)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _PermissionEntry, AXIS2_FAILURE);
                
                if(_PermissionEntry->is_valid_authorizeDeny &&
                        arg_authorizeDeny == _PermissionEntry->property_authorizeDeny)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_PermissionEntry_reset_authorizeDeny(_PermissionEntry, env);

                _PermissionEntry->property_authorizeDeny = arg_authorizeDeny;
                        _PermissionEntry->is_valid_authorizeDeny = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for authorizeDeny
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionEntry_reset_authorizeDeny(
                   adb_PermissionEntry_t* _PermissionEntry,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _PermissionEntry, AXIS2_FAILURE);
               

               _PermissionEntry->is_valid_authorizeDeny = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether authorizeDeny is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_PermissionEntry_is_authorizeDeny_nil(
                   adb_PermissionEntry_t* _PermissionEntry,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _PermissionEntry, AXIS2_TRUE);
               
               return !_PermissionEntry->is_valid_authorizeDeny;
           }

           /**
            * Set authorizeDeny to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionEntry_set_authorizeDeny_nil(
                   adb_PermissionEntry_t* _PermissionEntry,
                   const axutil_env_t *env)
           {
               return adb_PermissionEntry_reset_authorizeDeny(_PermissionEntry, env);
           }

           

            /**
             * Getter for deleteAllow by  Property Number 3
             */
            axis2_bool_t AXIS2_CALL
            adb_PermissionEntry_get_property3(
                adb_PermissionEntry_t* _PermissionEntry,
                const axutil_env_t *env)
            {
                return adb_PermissionEntry_get_deleteAllow(_PermissionEntry,
                                             env);
            }

            /**
             * getter for deleteAllow.
             */
            axis2_bool_t AXIS2_CALL
            adb_PermissionEntry_get_deleteAllow(
                    adb_PermissionEntry_t* _PermissionEntry,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _PermissionEntry, (axis2_bool_t)0);
                  

                return _PermissionEntry->property_deleteAllow;
             }

            /**
             * setter for deleteAllow
             */
            axis2_status_t AXIS2_CALL
            adb_PermissionEntry_set_deleteAllow(
                    adb_PermissionEntry_t* _PermissionEntry,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_deleteAllow)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _PermissionEntry, AXIS2_FAILURE);
                
                if(_PermissionEntry->is_valid_deleteAllow &&
                        arg_deleteAllow == _PermissionEntry->property_deleteAllow)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_PermissionEntry_reset_deleteAllow(_PermissionEntry, env);

                _PermissionEntry->property_deleteAllow = arg_deleteAllow;
                        _PermissionEntry->is_valid_deleteAllow = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for deleteAllow
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionEntry_reset_deleteAllow(
                   adb_PermissionEntry_t* _PermissionEntry,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _PermissionEntry, AXIS2_FAILURE);
               

               _PermissionEntry->is_valid_deleteAllow = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether deleteAllow is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_PermissionEntry_is_deleteAllow_nil(
                   adb_PermissionEntry_t* _PermissionEntry,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _PermissionEntry, AXIS2_TRUE);
               
               return !_PermissionEntry->is_valid_deleteAllow;
           }

           /**
            * Set deleteAllow to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionEntry_set_deleteAllow_nil(
                   adb_PermissionEntry_t* _PermissionEntry,
                   const axutil_env_t *env)
           {
               return adb_PermissionEntry_reset_deleteAllow(_PermissionEntry, env);
           }

           

            /**
             * Getter for deleteDeny by  Property Number 4
             */
            axis2_bool_t AXIS2_CALL
            adb_PermissionEntry_get_property4(
                adb_PermissionEntry_t* _PermissionEntry,
                const axutil_env_t *env)
            {
                return adb_PermissionEntry_get_deleteDeny(_PermissionEntry,
                                             env);
            }

            /**
             * getter for deleteDeny.
             */
            axis2_bool_t AXIS2_CALL
            adb_PermissionEntry_get_deleteDeny(
                    adb_PermissionEntry_t* _PermissionEntry,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _PermissionEntry, (axis2_bool_t)0);
                  

                return _PermissionEntry->property_deleteDeny;
             }

            /**
             * setter for deleteDeny
             */
            axis2_status_t AXIS2_CALL
            adb_PermissionEntry_set_deleteDeny(
                    adb_PermissionEntry_t* _PermissionEntry,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_deleteDeny)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _PermissionEntry, AXIS2_FAILURE);
                
                if(_PermissionEntry->is_valid_deleteDeny &&
                        arg_deleteDeny == _PermissionEntry->property_deleteDeny)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_PermissionEntry_reset_deleteDeny(_PermissionEntry, env);

                _PermissionEntry->property_deleteDeny = arg_deleteDeny;
                        _PermissionEntry->is_valid_deleteDeny = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for deleteDeny
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionEntry_reset_deleteDeny(
                   adb_PermissionEntry_t* _PermissionEntry,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _PermissionEntry, AXIS2_FAILURE);
               

               _PermissionEntry->is_valid_deleteDeny = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether deleteDeny is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_PermissionEntry_is_deleteDeny_nil(
                   adb_PermissionEntry_t* _PermissionEntry,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _PermissionEntry, AXIS2_TRUE);
               
               return !_PermissionEntry->is_valid_deleteDeny;
           }

           /**
            * Set deleteDeny to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionEntry_set_deleteDeny_nil(
                   adb_PermissionEntry_t* _PermissionEntry,
                   const axutil_env_t *env)
           {
               return adb_PermissionEntry_reset_deleteDeny(_PermissionEntry, env);
           }

           

            /**
             * Getter for readAllow by  Property Number 5
             */
            axis2_bool_t AXIS2_CALL
            adb_PermissionEntry_get_property5(
                adb_PermissionEntry_t* _PermissionEntry,
                const axutil_env_t *env)
            {
                return adb_PermissionEntry_get_readAllow(_PermissionEntry,
                                             env);
            }

            /**
             * getter for readAllow.
             */
            axis2_bool_t AXIS2_CALL
            adb_PermissionEntry_get_readAllow(
                    adb_PermissionEntry_t* _PermissionEntry,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _PermissionEntry, (axis2_bool_t)0);
                  

                return _PermissionEntry->property_readAllow;
             }

            /**
             * setter for readAllow
             */
            axis2_status_t AXIS2_CALL
            adb_PermissionEntry_set_readAllow(
                    adb_PermissionEntry_t* _PermissionEntry,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_readAllow)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _PermissionEntry, AXIS2_FAILURE);
                
                if(_PermissionEntry->is_valid_readAllow &&
                        arg_readAllow == _PermissionEntry->property_readAllow)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_PermissionEntry_reset_readAllow(_PermissionEntry, env);

                _PermissionEntry->property_readAllow = arg_readAllow;
                        _PermissionEntry->is_valid_readAllow = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for readAllow
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionEntry_reset_readAllow(
                   adb_PermissionEntry_t* _PermissionEntry,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _PermissionEntry, AXIS2_FAILURE);
               

               _PermissionEntry->is_valid_readAllow = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether readAllow is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_PermissionEntry_is_readAllow_nil(
                   adb_PermissionEntry_t* _PermissionEntry,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _PermissionEntry, AXIS2_TRUE);
               
               return !_PermissionEntry->is_valid_readAllow;
           }

           /**
            * Set readAllow to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionEntry_set_readAllow_nil(
                   adb_PermissionEntry_t* _PermissionEntry,
                   const axutil_env_t *env)
           {
               return adb_PermissionEntry_reset_readAllow(_PermissionEntry, env);
           }

           

            /**
             * Getter for readDeny by  Property Number 6
             */
            axis2_bool_t AXIS2_CALL
            adb_PermissionEntry_get_property6(
                adb_PermissionEntry_t* _PermissionEntry,
                const axutil_env_t *env)
            {
                return adb_PermissionEntry_get_readDeny(_PermissionEntry,
                                             env);
            }

            /**
             * getter for readDeny.
             */
            axis2_bool_t AXIS2_CALL
            adb_PermissionEntry_get_readDeny(
                    adb_PermissionEntry_t* _PermissionEntry,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _PermissionEntry, (axis2_bool_t)0);
                  

                return _PermissionEntry->property_readDeny;
             }

            /**
             * setter for readDeny
             */
            axis2_status_t AXIS2_CALL
            adb_PermissionEntry_set_readDeny(
                    adb_PermissionEntry_t* _PermissionEntry,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_readDeny)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _PermissionEntry, AXIS2_FAILURE);
                
                if(_PermissionEntry->is_valid_readDeny &&
                        arg_readDeny == _PermissionEntry->property_readDeny)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_PermissionEntry_reset_readDeny(_PermissionEntry, env);

                _PermissionEntry->property_readDeny = arg_readDeny;
                        _PermissionEntry->is_valid_readDeny = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for readDeny
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionEntry_reset_readDeny(
                   adb_PermissionEntry_t* _PermissionEntry,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _PermissionEntry, AXIS2_FAILURE);
               

               _PermissionEntry->is_valid_readDeny = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether readDeny is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_PermissionEntry_is_readDeny_nil(
                   adb_PermissionEntry_t* _PermissionEntry,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _PermissionEntry, AXIS2_TRUE);
               
               return !_PermissionEntry->is_valid_readDeny;
           }

           /**
            * Set readDeny to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionEntry_set_readDeny_nil(
                   adb_PermissionEntry_t* _PermissionEntry,
                   const axutil_env_t *env)
           {
               return adb_PermissionEntry_reset_readDeny(_PermissionEntry, env);
           }

           

            /**
             * Getter for userName by  Property Number 7
             */
            axis2_char_t* AXIS2_CALL
            adb_PermissionEntry_get_property7(
                adb_PermissionEntry_t* _PermissionEntry,
                const axutil_env_t *env)
            {
                return adb_PermissionEntry_get_userName(_PermissionEntry,
                                             env);
            }

            /**
             * getter for userName.
             */
            axis2_char_t* AXIS2_CALL
            adb_PermissionEntry_get_userName(
                    adb_PermissionEntry_t* _PermissionEntry,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _PermissionEntry, NULL);
                  

                return _PermissionEntry->property_userName;
             }

            /**
             * setter for userName
             */
            axis2_status_t AXIS2_CALL
            adb_PermissionEntry_set_userName(
                    adb_PermissionEntry_t* _PermissionEntry,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_userName)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _PermissionEntry, AXIS2_FAILURE);
                
                if(_PermissionEntry->is_valid_userName &&
                        arg_userName == _PermissionEntry->property_userName)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_PermissionEntry_reset_userName(_PermissionEntry, env);

                
                if(NULL == arg_userName)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _PermissionEntry->property_userName = (axis2_char_t *)axutil_strdup(env, arg_userName);
                        if(NULL == _PermissionEntry->property_userName)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for userName");
                            return AXIS2_FAILURE;
                        }
                        _PermissionEntry->is_valid_userName = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for userName
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionEntry_reset_userName(
                   adb_PermissionEntry_t* _PermissionEntry,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _PermissionEntry, AXIS2_FAILURE);
               

               
            
                
                if(_PermissionEntry->property_userName != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _PermissionEntry->property_userName);
                     _PermissionEntry->property_userName = NULL;
                }
            
                
                
                _PermissionEntry->is_valid_userName = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether userName is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_PermissionEntry_is_userName_nil(
                   adb_PermissionEntry_t* _PermissionEntry,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _PermissionEntry, AXIS2_TRUE);
               
               return !_PermissionEntry->is_valid_userName;
           }

           /**
            * Set userName to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionEntry_set_userName_nil(
                   adb_PermissionEntry_t* _PermissionEntry,
                   const axutil_env_t *env)
           {
               return adb_PermissionEntry_reset_userName(_PermissionEntry, env);
           }

           

            /**
             * Getter for writeAllow by  Property Number 8
             */
            axis2_bool_t AXIS2_CALL
            adb_PermissionEntry_get_property8(
                adb_PermissionEntry_t* _PermissionEntry,
                const axutil_env_t *env)
            {
                return adb_PermissionEntry_get_writeAllow(_PermissionEntry,
                                             env);
            }

            /**
             * getter for writeAllow.
             */
            axis2_bool_t AXIS2_CALL
            adb_PermissionEntry_get_writeAllow(
                    adb_PermissionEntry_t* _PermissionEntry,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _PermissionEntry, (axis2_bool_t)0);
                  

                return _PermissionEntry->property_writeAllow;
             }

            /**
             * setter for writeAllow
             */
            axis2_status_t AXIS2_CALL
            adb_PermissionEntry_set_writeAllow(
                    adb_PermissionEntry_t* _PermissionEntry,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_writeAllow)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _PermissionEntry, AXIS2_FAILURE);
                
                if(_PermissionEntry->is_valid_writeAllow &&
                        arg_writeAllow == _PermissionEntry->property_writeAllow)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_PermissionEntry_reset_writeAllow(_PermissionEntry, env);

                _PermissionEntry->property_writeAllow = arg_writeAllow;
                        _PermissionEntry->is_valid_writeAllow = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for writeAllow
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionEntry_reset_writeAllow(
                   adb_PermissionEntry_t* _PermissionEntry,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _PermissionEntry, AXIS2_FAILURE);
               

               _PermissionEntry->is_valid_writeAllow = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether writeAllow is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_PermissionEntry_is_writeAllow_nil(
                   adb_PermissionEntry_t* _PermissionEntry,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _PermissionEntry, AXIS2_TRUE);
               
               return !_PermissionEntry->is_valid_writeAllow;
           }

           /**
            * Set writeAllow to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionEntry_set_writeAllow_nil(
                   adb_PermissionEntry_t* _PermissionEntry,
                   const axutil_env_t *env)
           {
               return adb_PermissionEntry_reset_writeAllow(_PermissionEntry, env);
           }

           

            /**
             * Getter for writeDeny by  Property Number 9
             */
            axis2_bool_t AXIS2_CALL
            adb_PermissionEntry_get_property9(
                adb_PermissionEntry_t* _PermissionEntry,
                const axutil_env_t *env)
            {
                return adb_PermissionEntry_get_writeDeny(_PermissionEntry,
                                             env);
            }

            /**
             * getter for writeDeny.
             */
            axis2_bool_t AXIS2_CALL
            adb_PermissionEntry_get_writeDeny(
                    adb_PermissionEntry_t* _PermissionEntry,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _PermissionEntry, (axis2_bool_t)0);
                  

                return _PermissionEntry->property_writeDeny;
             }

            /**
             * setter for writeDeny
             */
            axis2_status_t AXIS2_CALL
            adb_PermissionEntry_set_writeDeny(
                    adb_PermissionEntry_t* _PermissionEntry,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_writeDeny)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _PermissionEntry, AXIS2_FAILURE);
                
                if(_PermissionEntry->is_valid_writeDeny &&
                        arg_writeDeny == _PermissionEntry->property_writeDeny)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_PermissionEntry_reset_writeDeny(_PermissionEntry, env);

                _PermissionEntry->property_writeDeny = arg_writeDeny;
                        _PermissionEntry->is_valid_writeDeny = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for writeDeny
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionEntry_reset_writeDeny(
                   adb_PermissionEntry_t* _PermissionEntry,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _PermissionEntry, AXIS2_FAILURE);
               

               _PermissionEntry->is_valid_writeDeny = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether writeDeny is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_PermissionEntry_is_writeDeny_nil(
                   adb_PermissionEntry_t* _PermissionEntry,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _PermissionEntry, AXIS2_TRUE);
               
               return !_PermissionEntry->is_valid_writeDeny;
           }

           /**
            * Set writeDeny to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionEntry_set_writeDeny_nil(
                   adb_PermissionEntry_t* _PermissionEntry,
                   const axutil_env_t *env)
           {
               return adb_PermissionEntry_reset_writeDeny(_PermissionEntry, env);
           }

           

