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
         * adb_PermissionBean.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_PermissionBean.h"
        
                /*
                 * This type was generated from the piece of schema that had
                 * name = PermissionBean
                 * Namespace URI = http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd
                 * Namespace Prefix = ns3
                 */
           


        struct adb_PermissionBean
        {
            axis2_char_t *property_Type;

            axis2_bool_t property_authorizeAllowed;

                
                axis2_bool_t is_valid_authorizeAllowed;
            axis2_bool_t property_deleteAllowed;

                
                axis2_bool_t is_valid_deleteAllowed;
            axis2_char_t* property_pathWithVersion;

                
                axis2_bool_t is_valid_pathWithVersion;
            axis2_bool_t property_putAllowed;

                
                axis2_bool_t is_valid_putAllowed;
            axutil_array_list_t* property_roleNames;

                
                axis2_bool_t is_valid_roleNames;
            axutil_array_list_t* property_rolePermissions;

                
                axis2_bool_t is_valid_rolePermissions;
            axutil_array_list_t* property_userNames;

                
                axis2_bool_t is_valid_userNames;
            axutil_array_list_t* property_userPermissions;

                
                axis2_bool_t is_valid_userPermissions;
            axis2_bool_t property_versionView;

                
                axis2_bool_t is_valid_versionView;
            
        };


       /************************* Private Function prototypes ********************************/
        

                axis2_status_t AXIS2_CALL
                adb_PermissionBean_set_authorizeAllowed_nil(
                        adb_PermissionBean_t* _PermissionBean,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_PermissionBean_set_deleteAllowed_nil(
                        adb_PermissionBean_t* _PermissionBean,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_PermissionBean_set_putAllowed_nil(
                        adb_PermissionBean_t* _PermissionBean,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_PermissionBean_set_versionView_nil(
                        adb_PermissionBean_t* _PermissionBean,
                        const axutil_env_t *env);
            


       /************************* Function Implmentations ********************************/
        adb_PermissionBean_t* AXIS2_CALL
        adb_PermissionBean_create(
            const axutil_env_t *env)
        {
            adb_PermissionBean_t *_PermissionBean = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _PermissionBean = (adb_PermissionBean_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_PermissionBean_t));

            if(NULL == _PermissionBean)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_PermissionBean, 0, sizeof(adb_PermissionBean_t));

            _PermissionBean->property_Type = axutil_strdup(env, "adb_PermissionBean");
            _PermissionBean->is_valid_authorizeAllowed  = AXIS2_FALSE;
            _PermissionBean->is_valid_deleteAllowed  = AXIS2_FALSE;
            _PermissionBean->property_pathWithVersion  = NULL;
                  _PermissionBean->is_valid_pathWithVersion  = AXIS2_FALSE;
            _PermissionBean->is_valid_putAllowed  = AXIS2_FALSE;
            _PermissionBean->property_roleNames  = NULL;
                  _PermissionBean->is_valid_roleNames  = AXIS2_FALSE;
            _PermissionBean->property_rolePermissions  = NULL;
                  _PermissionBean->is_valid_rolePermissions  = AXIS2_FALSE;
            _PermissionBean->property_userNames  = NULL;
                  _PermissionBean->is_valid_userNames  = AXIS2_FALSE;
            _PermissionBean->property_userPermissions  = NULL;
                  _PermissionBean->is_valid_userPermissions  = AXIS2_FALSE;
            _PermissionBean->is_valid_versionView  = AXIS2_FALSE;
            

            return _PermissionBean;
        }

        adb_PermissionBean_t* AXIS2_CALL
        adb_PermissionBean_create_with_values(
            const axutil_env_t *env,
                axis2_bool_t _authorizeAllowed,
                axis2_bool_t _deleteAllowed,
                axis2_char_t* _pathWithVersion,
                axis2_bool_t _putAllowed,
                axutil_array_list_t* _roleNames,
                axutil_array_list_t* _rolePermissions,
                axutil_array_list_t* _userNames,
                axutil_array_list_t* _userPermissions,
                axis2_bool_t _versionView)
        {
            adb_PermissionBean_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_PermissionBean_create(env);

            
              status = adb_PermissionBean_set_authorizeAllowed(
                                     adb_obj,
                                     env,
                                     _authorizeAllowed);
              if(status == AXIS2_FAILURE) {
                  adb_PermissionBean_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_PermissionBean_set_deleteAllowed(
                                     adb_obj,
                                     env,
                                     _deleteAllowed);
              if(status == AXIS2_FAILURE) {
                  adb_PermissionBean_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_PermissionBean_set_pathWithVersion(
                                     adb_obj,
                                     env,
                                     _pathWithVersion);
              if(status == AXIS2_FAILURE) {
                  adb_PermissionBean_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_PermissionBean_set_putAllowed(
                                     adb_obj,
                                     env,
                                     _putAllowed);
              if(status == AXIS2_FAILURE) {
                  adb_PermissionBean_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_PermissionBean_set_roleNames(
                                     adb_obj,
                                     env,
                                     _roleNames);
              if(status == AXIS2_FAILURE) {
                  adb_PermissionBean_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_PermissionBean_set_rolePermissions(
                                     adb_obj,
                                     env,
                                     _rolePermissions);
              if(status == AXIS2_FAILURE) {
                  adb_PermissionBean_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_PermissionBean_set_userNames(
                                     adb_obj,
                                     env,
                                     _userNames);
              if(status == AXIS2_FAILURE) {
                  adb_PermissionBean_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_PermissionBean_set_userPermissions(
                                     adb_obj,
                                     env,
                                     _userPermissions);
              if(status == AXIS2_FAILURE) {
                  adb_PermissionBean_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_PermissionBean_set_versionView(
                                     adb_obj,
                                     env,
                                     _versionView);
              if(status == AXIS2_FAILURE) {
                  adb_PermissionBean_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_bool_t AXIS2_CALL
                adb_PermissionBean_free_popping_value(
                        adb_PermissionBean_t* _PermissionBean,
                        const axutil_env_t *env)
                {
                    axis2_bool_t value;

                    
                    
                    value = _PermissionBean->property_authorizeAllowed;

                    adb_PermissionBean_free(_PermissionBean, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_PermissionBean_free(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env)
        {
            
            
            return axis2_extension_mapper_free(
                (adb_type_t*) _PermissionBean,
                env,
                "adb_PermissionBean");
            
        }

        axis2_status_t AXIS2_CALL
        adb_PermissionBean_free_obj(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env)
        {
            
                int i = 0;
                int count = 0;
                void *element = NULL;
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_FAILURE);

            if (_PermissionBean->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _PermissionBean->property_Type);
            }

            adb_PermissionBean_reset_authorizeAllowed(_PermissionBean, env);
            adb_PermissionBean_reset_deleteAllowed(_PermissionBean, env);
            adb_PermissionBean_reset_pathWithVersion(_PermissionBean, env);
            adb_PermissionBean_reset_putAllowed(_PermissionBean, env);
            adb_PermissionBean_reset_roleNames(_PermissionBean, env);
            adb_PermissionBean_reset_rolePermissions(_PermissionBean, env);
            adb_PermissionBean_reset_userNames(_PermissionBean, env);
            adb_PermissionBean_reset_userPermissions(_PermissionBean, env);
            adb_PermissionBean_reset_versionView(_PermissionBean, env);
            

            if(_PermissionBean)
            {
                AXIS2_FREE(env->allocator, _PermissionBean);
                _PermissionBean = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_PermissionBean_deserialize(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return axis2_extension_mapper_deserialize(
                (adb_type_t*) _PermissionBean,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs,
                "adb_PermissionBean");
            
        }

        axis2_status_t AXIS2_CALL
        adb_PermissionBean_deserialize_obj(
                adb_PermissionBean_t* _PermissionBean,
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
            AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for PermissionBean : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              
                      
                      first_node = axiom_node_get_first_child(parent, env);
                      
                    

                     
                     /*
                      * building authorizeAllowed element
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
                                   
                                 element_qname = axutil_qname_create(env, "authorizeAllowed", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                                status = adb_PermissionBean_set_authorizeAllowed(_PermissionBean, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_PermissionBean_set_authorizeAllowed(_PermissionBean, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element authorizeAllowed");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for authorizeAllowed ");
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
                      * building deleteAllowed element
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
                                 
                                 element_qname = axutil_qname_create(env, "deleteAllowed", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                                status = adb_PermissionBean_set_deleteAllowed(_PermissionBean, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_PermissionBean_set_deleteAllowed(_PermissionBean, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element deleteAllowed");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for deleteAllowed ");
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
                      * building pathWithVersion element
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
                                 
                                 element_qname = axutil_qname_create(env, "pathWithVersion", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_PermissionBean_set_pathWithVersion(_PermissionBean, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for pathWithVersion ");
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
                      * building putAllowed element
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
                                 
                                 element_qname = axutil_qname_create(env, "putAllowed", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                                status = adb_PermissionBean_set_putAllowed(_PermissionBean, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_PermissionBean_set_putAllowed(_PermissionBean, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element putAllowed");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for putAllowed ");
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
                     * building roleNames array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building roleNames element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "roleNames", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                  
                               
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
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for roleNames ");
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
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "roleNames (@minOccurs = '0') only have %d elements", i);
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
                                    status = adb_PermissionBean_set_roleNames(_PermissionBean, env,
                                                                   arr_list);
                               }

                             
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 
                    /*
                     * building rolePermissions array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building rolePermissions element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "rolePermissions", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                  
                               
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

                                  if (adb_PermissionEntry_is_particle() ||  
                                    (current_node && current_element && (axutil_qname_equals(element_qname, env, qname))))
                                  {
                                  
                                      if( current_node && current_element && (axutil_qname_equals(element_qname, env, qname)))
                                      {
                                          is_early_node_valid = AXIS2_TRUE;
                                      }
                                      
                                     
                                          element = (void*)axis2_extension_mapper_create_from_node(env, &current_node, "adb_PermissionEntry");
                                          
                                          status =  adb_PermissionEntry_deserialize((adb_PermissionEntry_t*)element, env,
                                                                                 &current_node, &is_early_node_valid, AXIS2_FALSE);
                                          
                                          if(AXIS2_FAILURE ==  status)
                                          {
                                              AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building element rolePermissions ");
                                          }
                                          else
                                          {
                                            axutil_array_list_add_at(arr_list, env, i, element);
                                          }
                                        
                                     if(AXIS2_FAILURE ==  status)
                                     {
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for rolePermissions ");
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
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "rolePermissions (@minOccurs = '0') only have %d elements", i);
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
                                    status = adb_PermissionBean_set_rolePermissions(_PermissionBean, env,
                                                                   arr_list);
                               }

                             
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 
                    /*
                     * building userNames array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building userNames element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "userNames", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                  
                               
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
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for userNames ");
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
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "userNames (@minOccurs = '0') only have %d elements", i);
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
                                    status = adb_PermissionBean_set_userNames(_PermissionBean, env,
                                                                   arr_list);
                               }

                             
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 
                    /*
                     * building userPermissions array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building userPermissions element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "userPermissions", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                  
                               
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

                                  if (adb_PermissionEntry_is_particle() ||  
                                    (current_node && current_element && (axutil_qname_equals(element_qname, env, qname))))
                                  {
                                  
                                      if( current_node && current_element && (axutil_qname_equals(element_qname, env, qname)))
                                      {
                                          is_early_node_valid = AXIS2_TRUE;
                                      }
                                      
                                     
                                          element = (void*)axis2_extension_mapper_create_from_node(env, &current_node, "adb_PermissionEntry");
                                          
                                          status =  adb_PermissionEntry_deserialize((adb_PermissionEntry_t*)element, env,
                                                                                 &current_node, &is_early_node_valid, AXIS2_FALSE);
                                          
                                          if(AXIS2_FAILURE ==  status)
                                          {
                                              AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building element userPermissions ");
                                          }
                                          else
                                          {
                                            axutil_array_list_add_at(arr_list, env, i, element);
                                          }
                                        
                                     if(AXIS2_FAILURE ==  status)
                                     {
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for userPermissions ");
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
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "userPermissions (@minOccurs = '0') only have %d elements", i);
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
                                    status = adb_PermissionBean_set_userPermissions(_PermissionBean, env,
                                                                   arr_list);
                               }

                             
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 

                     
                     /*
                      * building versionView element
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
                                 
                                 element_qname = axutil_qname_create(env, "versionView", "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", NULL);
                                 

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
                                                status = adb_PermissionBean_set_versionView(_PermissionBean, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_PermissionBean_set_versionView(_PermissionBean, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element versionView");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for versionView ");
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
          adb_PermissionBean_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_PermissionBean_declare_parent_namespaces(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_PermissionBean_serialize(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
            if (_PermissionBean == NULL)
            {
                return adb_PermissionBean_serialize_obj(
                    _PermissionBean, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            }
            else
            {
                return axis2_extension_mapper_serialize(
                    (adb_type_t*) _PermissionBean, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index, "adb_PermissionBean");
            }
            
        }

        axiom_node_t* AXIS2_CALL
        adb_PermissionBean_serialize_obj(
                adb_PermissionBean_t* _PermissionBean,
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
                    
                    axis2_char_t text_value_2[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t *text_value_3;
                    axis2_char_t *text_value_3_temp;
                    
                    axis2_char_t text_value_4[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t *text_value_5;
                    axis2_char_t *text_value_5_temp;
                    
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
            AXIS2_PARAM_CHECK(env->error, _PermissionBean, NULL);
            
            
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
              type_attrib = axutil_strcat(env, " ", xsi_prefix, ":type=\"PermissionBean\"", NULL);
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
            xsi_type_attri = axiom_attribute_create (env, "type", "PermissionBean", xsi_ns);
            
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
                      

                   if (!_PermissionBean->is_valid_authorizeAllowed)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("authorizeAllowed"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("authorizeAllowed")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing authorizeAllowed element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sauthorizeAllowed>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sauthorizeAllowed>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_1, (_PermissionBean->property_authorizeAllowed)?"true":"false");
                           
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
                      

                   if (!_PermissionBean->is_valid_deleteAllowed)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("deleteAllowed"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("deleteAllowed")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing deleteAllowed element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sdeleteAllowed>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sdeleteAllowed>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_2, (_PermissionBean->property_deleteAllowed)?"true":"false");
                           
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
                      

                   if (!_PermissionBean->is_valid_pathWithVersion)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("pathWithVersion"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("pathWithVersion")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing pathWithVersion element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%spathWithVersion>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%spathWithVersion>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_3 = _PermissionBean->property_pathWithVersion;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://beans.resource.ui.mgt.registry.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_PermissionBean->is_valid_putAllowed)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("putAllowed"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("putAllowed")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing putAllowed element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sputAllowed>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sputAllowed>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_4, (_PermissionBean->property_putAllowed)?"true":"false");
                           
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
                      

                   if (!_PermissionBean->is_valid_roleNames)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("roleNames"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("roleNames")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing roleNames array
                      */
                     if (_PermissionBean->property_roleNames != NULL)
                     {
                        
                            sprintf(start_input_str, "<%s%sroleNames>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%sroleNames>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_PermissionBean->property_roleNames, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_PermissionBean->property_roleNames, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing roleNames element
                      */

                    
                    
                           text_value_5 = (axis2_char_t*)element;
                           
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
                           
                         }
                     }
                   
                     
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
                      

                   if (!_PermissionBean->is_valid_rolePermissions)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("rolePermissions"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("rolePermissions")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing rolePermissions array
                      */
                     if (_PermissionBean->property_rolePermissions != NULL)
                     {
                        

                            sprintf(start_input_str, "<%s%srolePermissions",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%srolePermissions>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_PermissionBean->property_rolePermissions, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_PermissionBean->property_rolePermissions, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing rolePermissions element
                      */

                    
                     
                            if(!adb_PermissionEntry_is_particle())
                            {
                                axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                            }
                            adb_PermissionEntry_serialize((adb_PermissionEntry_t*)element, 
                                                                                 env, current_node, parent_element,
                                                                                 adb_PermissionEntry_is_particle() || AXIS2_FALSE, namespaces, next_ns_index);
                            
                            if(!adb_PermissionEntry_is_particle())
                            {
                                axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                            }
                            
                         }
                     }
                   
                     
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
                      

                   if (!_PermissionBean->is_valid_userNames)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("userNames"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("userNames")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing userNames array
                      */
                     if (_PermissionBean->property_userNames != NULL)
                     {
                        
                            sprintf(start_input_str, "<%s%suserNames>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%suserNames>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_PermissionBean->property_userNames, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_PermissionBean->property_userNames, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing userNames element
                      */

                    
                    
                           text_value_7 = (axis2_char_t*)element;
                           
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
                           
                         }
                     }
                   
                     
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
                      

                   if (!_PermissionBean->is_valid_userPermissions)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("userPermissions"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("userPermissions")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing userPermissions array
                      */
                     if (_PermissionBean->property_userPermissions != NULL)
                     {
                        

                            sprintf(start_input_str, "<%s%suserPermissions",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%suserPermissions>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_PermissionBean->property_userPermissions, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_PermissionBean->property_userPermissions, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing userPermissions element
                      */

                    
                     
                            if(!adb_PermissionEntry_is_particle())
                            {
                                axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                            }
                            adb_PermissionEntry_serialize((adb_PermissionEntry_t*)element, 
                                                                                 env, current_node, parent_element,
                                                                                 adb_PermissionEntry_is_particle() || AXIS2_FALSE, namespaces, next_ns_index);
                            
                            if(!adb_PermissionEntry_is_particle())
                            {
                                axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                            }
                            
                         }
                     }
                   
                     
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
                      

                   if (!_PermissionBean->is_valid_versionView)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("versionView"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("versionView")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing versionView element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sversionView>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sversionView>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_9, (_PermissionBean->property_versionView)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_9, axutil_strlen(text_value_9));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 

            return parent;
        }


        

            /**
             * Getter for authorizeAllowed by  Property Number 1
             */
            axis2_bool_t AXIS2_CALL
            adb_PermissionBean_get_property1(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env)
            {
                return adb_PermissionBean_get_authorizeAllowed(_PermissionBean,
                                             env);
            }

            /**
             * getter for authorizeAllowed.
             */
            axis2_bool_t AXIS2_CALL
            adb_PermissionBean_get_authorizeAllowed(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _PermissionBean, (axis2_bool_t)0);
                  

                return _PermissionBean->property_authorizeAllowed;
             }

            /**
             * setter for authorizeAllowed
             */
            axis2_status_t AXIS2_CALL
            adb_PermissionBean_set_authorizeAllowed(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_authorizeAllowed)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_FAILURE);
                
                if(_PermissionBean->is_valid_authorizeAllowed &&
                        arg_authorizeAllowed == _PermissionBean->property_authorizeAllowed)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_PermissionBean_reset_authorizeAllowed(_PermissionBean, env);

                _PermissionBean->property_authorizeAllowed = arg_authorizeAllowed;
                        _PermissionBean->is_valid_authorizeAllowed = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for authorizeAllowed
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionBean_reset_authorizeAllowed(
                   adb_PermissionBean_t* _PermissionBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_FAILURE);
               

               _PermissionBean->is_valid_authorizeAllowed = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether authorizeAllowed is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_PermissionBean_is_authorizeAllowed_nil(
                   adb_PermissionBean_t* _PermissionBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_TRUE);
               
               return !_PermissionBean->is_valid_authorizeAllowed;
           }

           /**
            * Set authorizeAllowed to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionBean_set_authorizeAllowed_nil(
                   adb_PermissionBean_t* _PermissionBean,
                   const axutil_env_t *env)
           {
               return adb_PermissionBean_reset_authorizeAllowed(_PermissionBean, env);
           }

           

            /**
             * Getter for deleteAllowed by  Property Number 2
             */
            axis2_bool_t AXIS2_CALL
            adb_PermissionBean_get_property2(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env)
            {
                return adb_PermissionBean_get_deleteAllowed(_PermissionBean,
                                             env);
            }

            /**
             * getter for deleteAllowed.
             */
            axis2_bool_t AXIS2_CALL
            adb_PermissionBean_get_deleteAllowed(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _PermissionBean, (axis2_bool_t)0);
                  

                return _PermissionBean->property_deleteAllowed;
             }

            /**
             * setter for deleteAllowed
             */
            axis2_status_t AXIS2_CALL
            adb_PermissionBean_set_deleteAllowed(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_deleteAllowed)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_FAILURE);
                
                if(_PermissionBean->is_valid_deleteAllowed &&
                        arg_deleteAllowed == _PermissionBean->property_deleteAllowed)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_PermissionBean_reset_deleteAllowed(_PermissionBean, env);

                _PermissionBean->property_deleteAllowed = arg_deleteAllowed;
                        _PermissionBean->is_valid_deleteAllowed = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for deleteAllowed
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionBean_reset_deleteAllowed(
                   adb_PermissionBean_t* _PermissionBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_FAILURE);
               

               _PermissionBean->is_valid_deleteAllowed = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether deleteAllowed is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_PermissionBean_is_deleteAllowed_nil(
                   adb_PermissionBean_t* _PermissionBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_TRUE);
               
               return !_PermissionBean->is_valid_deleteAllowed;
           }

           /**
            * Set deleteAllowed to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionBean_set_deleteAllowed_nil(
                   adb_PermissionBean_t* _PermissionBean,
                   const axutil_env_t *env)
           {
               return adb_PermissionBean_reset_deleteAllowed(_PermissionBean, env);
           }

           

            /**
             * Getter for pathWithVersion by  Property Number 3
             */
            axis2_char_t* AXIS2_CALL
            adb_PermissionBean_get_property3(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env)
            {
                return adb_PermissionBean_get_pathWithVersion(_PermissionBean,
                                             env);
            }

            /**
             * getter for pathWithVersion.
             */
            axis2_char_t* AXIS2_CALL
            adb_PermissionBean_get_pathWithVersion(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _PermissionBean, NULL);
                  

                return _PermissionBean->property_pathWithVersion;
             }

            /**
             * setter for pathWithVersion
             */
            axis2_status_t AXIS2_CALL
            adb_PermissionBean_set_pathWithVersion(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_pathWithVersion)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_FAILURE);
                
                if(_PermissionBean->is_valid_pathWithVersion &&
                        arg_pathWithVersion == _PermissionBean->property_pathWithVersion)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_PermissionBean_reset_pathWithVersion(_PermissionBean, env);

                
                if(NULL == arg_pathWithVersion)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _PermissionBean->property_pathWithVersion = (axis2_char_t *)axutil_strdup(env, arg_pathWithVersion);
                        if(NULL == _PermissionBean->property_pathWithVersion)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for pathWithVersion");
                            return AXIS2_FAILURE;
                        }
                        _PermissionBean->is_valid_pathWithVersion = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for pathWithVersion
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionBean_reset_pathWithVersion(
                   adb_PermissionBean_t* _PermissionBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_FAILURE);
               

               
            
                
                if(_PermissionBean->property_pathWithVersion != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _PermissionBean->property_pathWithVersion);
                     _PermissionBean->property_pathWithVersion = NULL;
                }
            
                
                
                _PermissionBean->is_valid_pathWithVersion = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether pathWithVersion is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_PermissionBean_is_pathWithVersion_nil(
                   adb_PermissionBean_t* _PermissionBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_TRUE);
               
               return !_PermissionBean->is_valid_pathWithVersion;
           }

           /**
            * Set pathWithVersion to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionBean_set_pathWithVersion_nil(
                   adb_PermissionBean_t* _PermissionBean,
                   const axutil_env_t *env)
           {
               return adb_PermissionBean_reset_pathWithVersion(_PermissionBean, env);
           }

           

            /**
             * Getter for putAllowed by  Property Number 4
             */
            axis2_bool_t AXIS2_CALL
            adb_PermissionBean_get_property4(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env)
            {
                return adb_PermissionBean_get_putAllowed(_PermissionBean,
                                             env);
            }

            /**
             * getter for putAllowed.
             */
            axis2_bool_t AXIS2_CALL
            adb_PermissionBean_get_putAllowed(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _PermissionBean, (axis2_bool_t)0);
                  

                return _PermissionBean->property_putAllowed;
             }

            /**
             * setter for putAllowed
             */
            axis2_status_t AXIS2_CALL
            adb_PermissionBean_set_putAllowed(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_putAllowed)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_FAILURE);
                
                if(_PermissionBean->is_valid_putAllowed &&
                        arg_putAllowed == _PermissionBean->property_putAllowed)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_PermissionBean_reset_putAllowed(_PermissionBean, env);

                _PermissionBean->property_putAllowed = arg_putAllowed;
                        _PermissionBean->is_valid_putAllowed = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for putAllowed
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionBean_reset_putAllowed(
                   adb_PermissionBean_t* _PermissionBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_FAILURE);
               

               _PermissionBean->is_valid_putAllowed = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether putAllowed is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_PermissionBean_is_putAllowed_nil(
                   adb_PermissionBean_t* _PermissionBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_TRUE);
               
               return !_PermissionBean->is_valid_putAllowed;
           }

           /**
            * Set putAllowed to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionBean_set_putAllowed_nil(
                   adb_PermissionBean_t* _PermissionBean,
                   const axutil_env_t *env)
           {
               return adb_PermissionBean_reset_putAllowed(_PermissionBean, env);
           }

           

            /**
             * Getter for roleNames by  Property Number 5
             */
            axutil_array_list_t* AXIS2_CALL
            adb_PermissionBean_get_property5(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env)
            {
                return adb_PermissionBean_get_roleNames(_PermissionBean,
                                             env);
            }

            /**
             * getter for roleNames.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_PermissionBean_get_roleNames(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _PermissionBean, NULL);
                  

                return _PermissionBean->property_roleNames;
             }

            /**
             * setter for roleNames
             */
            axis2_status_t AXIS2_CALL
            adb_PermissionBean_set_roleNames(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_roleNames)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_FAILURE);
                
                if(_PermissionBean->is_valid_roleNames &&
                        arg_roleNames == _PermissionBean->property_roleNames)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_roleNames, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "roleNames has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_roleNames, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_PermissionBean_reset_roleNames(_PermissionBean, env);

                
                if(NULL == arg_roleNames)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _PermissionBean->property_roleNames = arg_roleNames;
                        if(non_nil_exists)
                        {
                            _PermissionBean->is_valid_roleNames = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of roleNames.
             */
            axis2_char_t* AXIS2_CALL
            adb_PermissionBean_get_roleNames_at(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env, int i)
            {
                axis2_char_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _PermissionBean, NULL);
                  

                if(_PermissionBean->property_roleNames == NULL)
                {
                    return (axis2_char_t*)0;
                }
                ret_val = (axis2_char_t*)axutil_array_list_get(_PermissionBean->property_roleNames, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of roleNames.
             */
            axis2_status_t AXIS2_CALL
            adb_PermissionBean_set_roleNames_at(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env, int i,
                    const axis2_char_t* arg_roleNames)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_FAILURE);
                
                if( _PermissionBean->is_valid_roleNames &&
                    _PermissionBean->property_roleNames &&
                
                    arg_roleNames == (axis2_char_t*)axutil_array_list_get(_PermissionBean->property_roleNames, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_roleNames)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_PermissionBean->property_roleNames != NULL)
                        {
                            size = axutil_array_list_size(_PermissionBean->property_roleNames, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_PermissionBean->property_roleNames, env, i))
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
                  

                if(_PermissionBean->property_roleNames == NULL)
                {
                    _PermissionBean->property_roleNames = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_PermissionBean->property_roleNames, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _PermissionBean->is_valid_roleNames = AXIS2_FALSE;
                        axutil_array_list_set(_PermissionBean->property_roleNames , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_PermissionBean->property_roleNames , env, i, axutil_strdup(env, arg_roleNames));
                  _PermissionBean->is_valid_roleNames = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to roleNames.
             */
            axis2_status_t AXIS2_CALL
            adb_PermissionBean_add_roleNames(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env,
                    const axis2_char_t* arg_roleNames)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_FAILURE);

                
                    if(NULL == arg_roleNames)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_PermissionBean->property_roleNames == NULL)
                {
                    _PermissionBean->property_roleNames = axutil_array_list_create(env, 10);
                }
                if(_PermissionBean->property_roleNames == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for roleNames");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_PermissionBean->property_roleNames , env, axutil_strdup(env, arg_roleNames));
                  _PermissionBean->is_valid_roleNames = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the roleNames array.
             */
            int AXIS2_CALL
            adb_PermissionBean_sizeof_roleNames(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _PermissionBean, -1);
                if(_PermissionBean->property_roleNames == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_PermissionBean->property_roleNames, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_PermissionBean_remove_roleNames_at(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env, int i)
            {
                return adb_PermissionBean_set_roleNames_nil_at(_PermissionBean, env, i);
            }

            

           /**
            * resetter for roleNames
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionBean_reset_roleNames(
                   adb_PermissionBean_t* _PermissionBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_FAILURE);
               

               
                  if (_PermissionBean->property_roleNames != NULL)
                  {
                      count = axutil_array_list_size(_PermissionBean->property_roleNames, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_PermissionBean->property_roleNames, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, (axis2_char_t*)element);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_PermissionBean->property_roleNames, env);
                  }
                _PermissionBean->is_valid_roleNames = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether roleNames is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_PermissionBean_is_roleNames_nil(
                   adb_PermissionBean_t* _PermissionBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_TRUE);
               
               return !_PermissionBean->is_valid_roleNames;
           }

           /**
            * Set roleNames to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionBean_set_roleNames_nil(
                   adb_PermissionBean_t* _PermissionBean,
                   const axutil_env_t *env)
           {
               return adb_PermissionBean_reset_roleNames(_PermissionBean, env);
           }

           
           /**
            * Check whether roleNames is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_PermissionBean_is_roleNames_nil_at(
                   adb_PermissionBean_t* _PermissionBean,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_TRUE);
               
               return (_PermissionBean->is_valid_roleNames == AXIS2_FALSE ||
                        NULL == _PermissionBean->property_roleNames || 
                        NULL == axutil_array_list_get(_PermissionBean->property_roleNames, env, i));
           }

           /**
            * Set roleNames to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionBean_set_roleNames_nil_at(
                   adb_PermissionBean_t* _PermissionBean,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_FAILURE);

                if(_PermissionBean->property_roleNames == NULL ||
                            _PermissionBean->is_valid_roleNames == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_PermissionBean->property_roleNames, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_PermissionBean->property_roleNames, env, i))
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
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of roleNames is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_PermissionBean->property_roleNames == NULL)
                {
                    _PermissionBean->is_valid_roleNames = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_PermissionBean->property_roleNames, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _PermissionBean->is_valid_roleNames = AXIS2_FALSE;
                        axutil_array_list_set(_PermissionBean->property_roleNames , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_PermissionBean->property_roleNames , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

            /**
             * Getter for rolePermissions by  Property Number 6
             */
            axutil_array_list_t* AXIS2_CALL
            adb_PermissionBean_get_property6(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env)
            {
                return adb_PermissionBean_get_rolePermissions(_PermissionBean,
                                             env);
            }

            /**
             * getter for rolePermissions.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_PermissionBean_get_rolePermissions(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _PermissionBean, NULL);
                  

                return _PermissionBean->property_rolePermissions;
             }

            /**
             * setter for rolePermissions
             */
            axis2_status_t AXIS2_CALL
            adb_PermissionBean_set_rolePermissions(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_rolePermissions)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_FAILURE);
                
                if(_PermissionBean->is_valid_rolePermissions &&
                        arg_rolePermissions == _PermissionBean->property_rolePermissions)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_rolePermissions, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "rolePermissions has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_rolePermissions, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_PermissionBean_reset_rolePermissions(_PermissionBean, env);

                
                if(NULL == arg_rolePermissions)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _PermissionBean->property_rolePermissions = arg_rolePermissions;
                        if(non_nil_exists)
                        {
                            _PermissionBean->is_valid_rolePermissions = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of rolePermissions.
             */
            adb_PermissionEntry_t* AXIS2_CALL
            adb_PermissionBean_get_rolePermissions_at(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env, int i)
            {
                adb_PermissionEntry_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _PermissionBean, NULL);
                  

                if(_PermissionBean->property_rolePermissions == NULL)
                {
                    return (adb_PermissionEntry_t*)0;
                }
                ret_val = (adb_PermissionEntry_t*)axutil_array_list_get(_PermissionBean->property_rolePermissions, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of rolePermissions.
             */
            axis2_status_t AXIS2_CALL
            adb_PermissionBean_set_rolePermissions_at(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env, int i,
                    adb_PermissionEntry_t* arg_rolePermissions)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_FAILURE);
                
                if( _PermissionBean->is_valid_rolePermissions &&
                    _PermissionBean->property_rolePermissions &&
                
                    arg_rolePermissions == (adb_PermissionEntry_t*)axutil_array_list_get(_PermissionBean->property_rolePermissions, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_rolePermissions)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_PermissionBean->property_rolePermissions != NULL)
                        {
                            size = axutil_array_list_size(_PermissionBean->property_rolePermissions, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_PermissionBean->property_rolePermissions, env, i))
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
                  

                if(_PermissionBean->property_rolePermissions == NULL)
                {
                    _PermissionBean->property_rolePermissions = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_PermissionBean->property_rolePermissions, env, i);
                if(NULL != element)
                {
                  
                  
                  adb_PermissionEntry_free((adb_PermissionEntry_t*)element, env);
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _PermissionBean->is_valid_rolePermissions = AXIS2_FALSE;
                        axutil_array_list_set(_PermissionBean->property_rolePermissions , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_PermissionBean->property_rolePermissions , env, i, arg_rolePermissions);
                  _PermissionBean->is_valid_rolePermissions = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to rolePermissions.
             */
            axis2_status_t AXIS2_CALL
            adb_PermissionBean_add_rolePermissions(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env,
                    adb_PermissionEntry_t* arg_rolePermissions)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_FAILURE);

                
                    if(NULL == arg_rolePermissions)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_PermissionBean->property_rolePermissions == NULL)
                {
                    _PermissionBean->property_rolePermissions = axutil_array_list_create(env, 10);
                }
                if(_PermissionBean->property_rolePermissions == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for rolePermissions");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_PermissionBean->property_rolePermissions , env, arg_rolePermissions);
                  _PermissionBean->is_valid_rolePermissions = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the rolePermissions array.
             */
            int AXIS2_CALL
            adb_PermissionBean_sizeof_rolePermissions(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _PermissionBean, -1);
                if(_PermissionBean->property_rolePermissions == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_PermissionBean->property_rolePermissions, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_PermissionBean_remove_rolePermissions_at(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env, int i)
            {
                return adb_PermissionBean_set_rolePermissions_nil_at(_PermissionBean, env, i);
            }

            

           /**
            * resetter for rolePermissions
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionBean_reset_rolePermissions(
                   adb_PermissionBean_t* _PermissionBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_FAILURE);
               

               
                  if (_PermissionBean->property_rolePermissions != NULL)
                  {
                      count = axutil_array_list_size(_PermissionBean->property_rolePermissions, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_PermissionBean->property_rolePermissions, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   adb_PermissionEntry_free((adb_PermissionEntry_t*)element, env);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_PermissionBean->property_rolePermissions, env);
                  }
                _PermissionBean->is_valid_rolePermissions = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether rolePermissions is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_PermissionBean_is_rolePermissions_nil(
                   adb_PermissionBean_t* _PermissionBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_TRUE);
               
               return !_PermissionBean->is_valid_rolePermissions;
           }

           /**
            * Set rolePermissions to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionBean_set_rolePermissions_nil(
                   adb_PermissionBean_t* _PermissionBean,
                   const axutil_env_t *env)
           {
               return adb_PermissionBean_reset_rolePermissions(_PermissionBean, env);
           }

           
           /**
            * Check whether rolePermissions is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_PermissionBean_is_rolePermissions_nil_at(
                   adb_PermissionBean_t* _PermissionBean,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_TRUE);
               
               return (_PermissionBean->is_valid_rolePermissions == AXIS2_FALSE ||
                        NULL == _PermissionBean->property_rolePermissions || 
                        NULL == axutil_array_list_get(_PermissionBean->property_rolePermissions, env, i));
           }

           /**
            * Set rolePermissions to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionBean_set_rolePermissions_nil_at(
                   adb_PermissionBean_t* _PermissionBean,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_FAILURE);

                if(_PermissionBean->property_rolePermissions == NULL ||
                            _PermissionBean->is_valid_rolePermissions == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_PermissionBean->property_rolePermissions, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_PermissionBean->property_rolePermissions, env, i))
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
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of rolePermissions is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_PermissionBean->property_rolePermissions == NULL)
                {
                    _PermissionBean->is_valid_rolePermissions = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_PermissionBean->property_rolePermissions, env, i);
                if(NULL != element)
                {
                  
                  
                  adb_PermissionEntry_free((adb_PermissionEntry_t*)element, env);
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _PermissionBean->is_valid_rolePermissions = AXIS2_FALSE;
                        axutil_array_list_set(_PermissionBean->property_rolePermissions , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_PermissionBean->property_rolePermissions , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

            /**
             * Getter for userNames by  Property Number 7
             */
            axutil_array_list_t* AXIS2_CALL
            adb_PermissionBean_get_property7(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env)
            {
                return adb_PermissionBean_get_userNames(_PermissionBean,
                                             env);
            }

            /**
             * getter for userNames.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_PermissionBean_get_userNames(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _PermissionBean, NULL);
                  

                return _PermissionBean->property_userNames;
             }

            /**
             * setter for userNames
             */
            axis2_status_t AXIS2_CALL
            adb_PermissionBean_set_userNames(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_userNames)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_FAILURE);
                
                if(_PermissionBean->is_valid_userNames &&
                        arg_userNames == _PermissionBean->property_userNames)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_userNames, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "userNames has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_userNames, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_PermissionBean_reset_userNames(_PermissionBean, env);

                
                if(NULL == arg_userNames)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _PermissionBean->property_userNames = arg_userNames;
                        if(non_nil_exists)
                        {
                            _PermissionBean->is_valid_userNames = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of userNames.
             */
            axis2_char_t* AXIS2_CALL
            adb_PermissionBean_get_userNames_at(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env, int i)
            {
                axis2_char_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _PermissionBean, NULL);
                  

                if(_PermissionBean->property_userNames == NULL)
                {
                    return (axis2_char_t*)0;
                }
                ret_val = (axis2_char_t*)axutil_array_list_get(_PermissionBean->property_userNames, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of userNames.
             */
            axis2_status_t AXIS2_CALL
            adb_PermissionBean_set_userNames_at(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env, int i,
                    const axis2_char_t* arg_userNames)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_FAILURE);
                
                if( _PermissionBean->is_valid_userNames &&
                    _PermissionBean->property_userNames &&
                
                    arg_userNames == (axis2_char_t*)axutil_array_list_get(_PermissionBean->property_userNames, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_userNames)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_PermissionBean->property_userNames != NULL)
                        {
                            size = axutil_array_list_size(_PermissionBean->property_userNames, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_PermissionBean->property_userNames, env, i))
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
                  

                if(_PermissionBean->property_userNames == NULL)
                {
                    _PermissionBean->property_userNames = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_PermissionBean->property_userNames, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _PermissionBean->is_valid_userNames = AXIS2_FALSE;
                        axutil_array_list_set(_PermissionBean->property_userNames , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_PermissionBean->property_userNames , env, i, axutil_strdup(env, arg_userNames));
                  _PermissionBean->is_valid_userNames = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to userNames.
             */
            axis2_status_t AXIS2_CALL
            adb_PermissionBean_add_userNames(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env,
                    const axis2_char_t* arg_userNames)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_FAILURE);

                
                    if(NULL == arg_userNames)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_PermissionBean->property_userNames == NULL)
                {
                    _PermissionBean->property_userNames = axutil_array_list_create(env, 10);
                }
                if(_PermissionBean->property_userNames == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for userNames");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_PermissionBean->property_userNames , env, axutil_strdup(env, arg_userNames));
                  _PermissionBean->is_valid_userNames = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the userNames array.
             */
            int AXIS2_CALL
            adb_PermissionBean_sizeof_userNames(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _PermissionBean, -1);
                if(_PermissionBean->property_userNames == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_PermissionBean->property_userNames, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_PermissionBean_remove_userNames_at(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env, int i)
            {
                return adb_PermissionBean_set_userNames_nil_at(_PermissionBean, env, i);
            }

            

           /**
            * resetter for userNames
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionBean_reset_userNames(
                   adb_PermissionBean_t* _PermissionBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_FAILURE);
               

               
                  if (_PermissionBean->property_userNames != NULL)
                  {
                      count = axutil_array_list_size(_PermissionBean->property_userNames, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_PermissionBean->property_userNames, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, (axis2_char_t*)element);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_PermissionBean->property_userNames, env);
                  }
                _PermissionBean->is_valid_userNames = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether userNames is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_PermissionBean_is_userNames_nil(
                   adb_PermissionBean_t* _PermissionBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_TRUE);
               
               return !_PermissionBean->is_valid_userNames;
           }

           /**
            * Set userNames to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionBean_set_userNames_nil(
                   adb_PermissionBean_t* _PermissionBean,
                   const axutil_env_t *env)
           {
               return adb_PermissionBean_reset_userNames(_PermissionBean, env);
           }

           
           /**
            * Check whether userNames is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_PermissionBean_is_userNames_nil_at(
                   adb_PermissionBean_t* _PermissionBean,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_TRUE);
               
               return (_PermissionBean->is_valid_userNames == AXIS2_FALSE ||
                        NULL == _PermissionBean->property_userNames || 
                        NULL == axutil_array_list_get(_PermissionBean->property_userNames, env, i));
           }

           /**
            * Set userNames to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionBean_set_userNames_nil_at(
                   adb_PermissionBean_t* _PermissionBean,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_FAILURE);

                if(_PermissionBean->property_userNames == NULL ||
                            _PermissionBean->is_valid_userNames == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_PermissionBean->property_userNames, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_PermissionBean->property_userNames, env, i))
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
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of userNames is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_PermissionBean->property_userNames == NULL)
                {
                    _PermissionBean->is_valid_userNames = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_PermissionBean->property_userNames, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _PermissionBean->is_valid_userNames = AXIS2_FALSE;
                        axutil_array_list_set(_PermissionBean->property_userNames , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_PermissionBean->property_userNames , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

            /**
             * Getter for userPermissions by  Property Number 8
             */
            axutil_array_list_t* AXIS2_CALL
            adb_PermissionBean_get_property8(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env)
            {
                return adb_PermissionBean_get_userPermissions(_PermissionBean,
                                             env);
            }

            /**
             * getter for userPermissions.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_PermissionBean_get_userPermissions(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _PermissionBean, NULL);
                  

                return _PermissionBean->property_userPermissions;
             }

            /**
             * setter for userPermissions
             */
            axis2_status_t AXIS2_CALL
            adb_PermissionBean_set_userPermissions(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_userPermissions)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_FAILURE);
                
                if(_PermissionBean->is_valid_userPermissions &&
                        arg_userPermissions == _PermissionBean->property_userPermissions)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_userPermissions, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "userPermissions has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_userPermissions, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_PermissionBean_reset_userPermissions(_PermissionBean, env);

                
                if(NULL == arg_userPermissions)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _PermissionBean->property_userPermissions = arg_userPermissions;
                        if(non_nil_exists)
                        {
                            _PermissionBean->is_valid_userPermissions = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of userPermissions.
             */
            adb_PermissionEntry_t* AXIS2_CALL
            adb_PermissionBean_get_userPermissions_at(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env, int i)
            {
                adb_PermissionEntry_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _PermissionBean, NULL);
                  

                if(_PermissionBean->property_userPermissions == NULL)
                {
                    return (adb_PermissionEntry_t*)0;
                }
                ret_val = (adb_PermissionEntry_t*)axutil_array_list_get(_PermissionBean->property_userPermissions, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of userPermissions.
             */
            axis2_status_t AXIS2_CALL
            adb_PermissionBean_set_userPermissions_at(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env, int i,
                    adb_PermissionEntry_t* arg_userPermissions)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_FAILURE);
                
                if( _PermissionBean->is_valid_userPermissions &&
                    _PermissionBean->property_userPermissions &&
                
                    arg_userPermissions == (adb_PermissionEntry_t*)axutil_array_list_get(_PermissionBean->property_userPermissions, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_userPermissions)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_PermissionBean->property_userPermissions != NULL)
                        {
                            size = axutil_array_list_size(_PermissionBean->property_userPermissions, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_PermissionBean->property_userPermissions, env, i))
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
                  

                if(_PermissionBean->property_userPermissions == NULL)
                {
                    _PermissionBean->property_userPermissions = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_PermissionBean->property_userPermissions, env, i);
                if(NULL != element)
                {
                  
                  
                  adb_PermissionEntry_free((adb_PermissionEntry_t*)element, env);
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _PermissionBean->is_valid_userPermissions = AXIS2_FALSE;
                        axutil_array_list_set(_PermissionBean->property_userPermissions , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_PermissionBean->property_userPermissions , env, i, arg_userPermissions);
                  _PermissionBean->is_valid_userPermissions = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to userPermissions.
             */
            axis2_status_t AXIS2_CALL
            adb_PermissionBean_add_userPermissions(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env,
                    adb_PermissionEntry_t* arg_userPermissions)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_FAILURE);

                
                    if(NULL == arg_userPermissions)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_PermissionBean->property_userPermissions == NULL)
                {
                    _PermissionBean->property_userPermissions = axutil_array_list_create(env, 10);
                }
                if(_PermissionBean->property_userPermissions == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for userPermissions");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_PermissionBean->property_userPermissions , env, arg_userPermissions);
                  _PermissionBean->is_valid_userPermissions = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the userPermissions array.
             */
            int AXIS2_CALL
            adb_PermissionBean_sizeof_userPermissions(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _PermissionBean, -1);
                if(_PermissionBean->property_userPermissions == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_PermissionBean->property_userPermissions, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_PermissionBean_remove_userPermissions_at(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env, int i)
            {
                return adb_PermissionBean_set_userPermissions_nil_at(_PermissionBean, env, i);
            }

            

           /**
            * resetter for userPermissions
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionBean_reset_userPermissions(
                   adb_PermissionBean_t* _PermissionBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_FAILURE);
               

               
                  if (_PermissionBean->property_userPermissions != NULL)
                  {
                      count = axutil_array_list_size(_PermissionBean->property_userPermissions, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_PermissionBean->property_userPermissions, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   adb_PermissionEntry_free((adb_PermissionEntry_t*)element, env);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_PermissionBean->property_userPermissions, env);
                  }
                _PermissionBean->is_valid_userPermissions = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether userPermissions is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_PermissionBean_is_userPermissions_nil(
                   adb_PermissionBean_t* _PermissionBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_TRUE);
               
               return !_PermissionBean->is_valid_userPermissions;
           }

           /**
            * Set userPermissions to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionBean_set_userPermissions_nil(
                   adb_PermissionBean_t* _PermissionBean,
                   const axutil_env_t *env)
           {
               return adb_PermissionBean_reset_userPermissions(_PermissionBean, env);
           }

           
           /**
            * Check whether userPermissions is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_PermissionBean_is_userPermissions_nil_at(
                   adb_PermissionBean_t* _PermissionBean,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_TRUE);
               
               return (_PermissionBean->is_valid_userPermissions == AXIS2_FALSE ||
                        NULL == _PermissionBean->property_userPermissions || 
                        NULL == axutil_array_list_get(_PermissionBean->property_userPermissions, env, i));
           }

           /**
            * Set userPermissions to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionBean_set_userPermissions_nil_at(
                   adb_PermissionBean_t* _PermissionBean,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_FAILURE);

                if(_PermissionBean->property_userPermissions == NULL ||
                            _PermissionBean->is_valid_userPermissions == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_PermissionBean->property_userPermissions, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_PermissionBean->property_userPermissions, env, i))
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
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of userPermissions is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_PermissionBean->property_userPermissions == NULL)
                {
                    _PermissionBean->is_valid_userPermissions = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_PermissionBean->property_userPermissions, env, i);
                if(NULL != element)
                {
                  
                  
                  adb_PermissionEntry_free((adb_PermissionEntry_t*)element, env);
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _PermissionBean->is_valid_userPermissions = AXIS2_FALSE;
                        axutil_array_list_set(_PermissionBean->property_userPermissions , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_PermissionBean->property_userPermissions , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

            /**
             * Getter for versionView by  Property Number 9
             */
            axis2_bool_t AXIS2_CALL
            adb_PermissionBean_get_property9(
                adb_PermissionBean_t* _PermissionBean,
                const axutil_env_t *env)
            {
                return adb_PermissionBean_get_versionView(_PermissionBean,
                                             env);
            }

            /**
             * getter for versionView.
             */
            axis2_bool_t AXIS2_CALL
            adb_PermissionBean_get_versionView(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _PermissionBean, (axis2_bool_t)0);
                  

                return _PermissionBean->property_versionView;
             }

            /**
             * setter for versionView
             */
            axis2_status_t AXIS2_CALL
            adb_PermissionBean_set_versionView(
                    adb_PermissionBean_t* _PermissionBean,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_versionView)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_FAILURE);
                
                if(_PermissionBean->is_valid_versionView &&
                        arg_versionView == _PermissionBean->property_versionView)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_PermissionBean_reset_versionView(_PermissionBean, env);

                _PermissionBean->property_versionView = arg_versionView;
                        _PermissionBean->is_valid_versionView = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for versionView
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionBean_reset_versionView(
                   adb_PermissionBean_t* _PermissionBean,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_FAILURE);
               

               _PermissionBean->is_valid_versionView = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether versionView is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_PermissionBean_is_versionView_nil(
                   adb_PermissionBean_t* _PermissionBean,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _PermissionBean, AXIS2_TRUE);
               
               return !_PermissionBean->is_valid_versionView;
           }

           /**
            * Set versionView to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_PermissionBean_set_versionView_nil(
                   adb_PermissionBean_t* _PermissionBean,
                   const axutil_env_t *env)
           {
               return adb_PermissionBean_reset_versionView(_PermissionBean, env);
           }

           

