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
         * adb_UserRealm.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_UserRealm.h"
        
                /*
                 * This type was generated from the piece of schema that had
                 * name = UserRealm
                 * Namespace URI = http://core.user.carbon.wso2.org/xsd
                 * Namespace Prefix = ns2
                 */
           


        struct adb_UserRealm
        {
            axis2_char_t *property_Type;

            adb_AccessControlAdmin_t* property_accessControlAdmin;

                
                axis2_bool_t is_valid_accessControlAdmin;
            adb_Authenticator_t* property_authenticator;

                
                axis2_bool_t is_valid_authenticator;
            adb_Authorizer_t* property_authorizer;

                
                axis2_bool_t is_valid_authorizer;
            adb_UserClaimsAdmin_t* property_claimsAdmin;

                
                axis2_bool_t is_valid_claimsAdmin;
            axiom_node_t* property_realmConfiguration;

                
                axis2_bool_t is_valid_realmConfiguration;
            adb_UserProfileAdmin_t* property_userProfileAdmin;

                
                axis2_bool_t is_valid_userProfileAdmin;
            adb_UserStoreAdmin_t* property_userStoreAdmin;

                
                axis2_bool_t is_valid_userStoreAdmin;
            adb_UserStoreReader_t* property_userStoreReader;

                
                axis2_bool_t is_valid_userStoreReader;
            
        };


       /************************* Private Function prototypes ********************************/
        


       /************************* Function Implmentations ********************************/
        adb_UserRealm_t* AXIS2_CALL
        adb_UserRealm_create(
            const axutil_env_t *env)
        {
            adb_UserRealm_t *_UserRealm = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _UserRealm = (adb_UserRealm_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_UserRealm_t));

            if(NULL == _UserRealm)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_UserRealm, 0, sizeof(adb_UserRealm_t));

            _UserRealm->property_Type = axutil_strdup(env, "adb_UserRealm");
            _UserRealm->property_accessControlAdmin  = NULL;
                  _UserRealm->is_valid_accessControlAdmin  = AXIS2_FALSE;
            _UserRealm->property_authenticator  = NULL;
                  _UserRealm->is_valid_authenticator  = AXIS2_FALSE;
            _UserRealm->property_authorizer  = NULL;
                  _UserRealm->is_valid_authorizer  = AXIS2_FALSE;
            _UserRealm->property_claimsAdmin  = NULL;
                  _UserRealm->is_valid_claimsAdmin  = AXIS2_FALSE;
            _UserRealm->is_valid_realmConfiguration  = AXIS2_FALSE;
            _UserRealm->property_userProfileAdmin  = NULL;
                  _UserRealm->is_valid_userProfileAdmin  = AXIS2_FALSE;
            _UserRealm->property_userStoreAdmin  = NULL;
                  _UserRealm->is_valid_userStoreAdmin  = AXIS2_FALSE;
            _UserRealm->property_userStoreReader  = NULL;
                  _UserRealm->is_valid_userStoreReader  = AXIS2_FALSE;
            

            return _UserRealm;
        }

        adb_UserRealm_t* AXIS2_CALL
        adb_UserRealm_create_with_values(
            const axutil_env_t *env,
                adb_AccessControlAdmin_t* _accessControlAdmin,
                adb_Authenticator_t* _authenticator,
                adb_Authorizer_t* _authorizer,
                adb_UserClaimsAdmin_t* _claimsAdmin,
                axiom_node_t* _realmConfiguration,
                adb_UserProfileAdmin_t* _userProfileAdmin,
                adb_UserStoreAdmin_t* _userStoreAdmin,
                adb_UserStoreReader_t* _userStoreReader)
        {
            adb_UserRealm_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_UserRealm_create(env);

            
              status = adb_UserRealm_set_accessControlAdmin(
                                     adb_obj,
                                     env,
                                     _accessControlAdmin);
              if(status == AXIS2_FAILURE) {
                  adb_UserRealm_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_UserRealm_set_authenticator(
                                     adb_obj,
                                     env,
                                     _authenticator);
              if(status == AXIS2_FAILURE) {
                  adb_UserRealm_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_UserRealm_set_authorizer(
                                     adb_obj,
                                     env,
                                     _authorizer);
              if(status == AXIS2_FAILURE) {
                  adb_UserRealm_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_UserRealm_set_claimsAdmin(
                                     adb_obj,
                                     env,
                                     _claimsAdmin);
              if(status == AXIS2_FAILURE) {
                  adb_UserRealm_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_UserRealm_set_realmConfiguration(
                                     adb_obj,
                                     env,
                                     _realmConfiguration);
              if(status == AXIS2_FAILURE) {
                  adb_UserRealm_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_UserRealm_set_userProfileAdmin(
                                     adb_obj,
                                     env,
                                     _userProfileAdmin);
              if(status == AXIS2_FAILURE) {
                  adb_UserRealm_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_UserRealm_set_userStoreAdmin(
                                     adb_obj,
                                     env,
                                     _userStoreAdmin);
              if(status == AXIS2_FAILURE) {
                  adb_UserRealm_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_UserRealm_set_userStoreReader(
                                     adb_obj,
                                     env,
                                     _userStoreReader);
              if(status == AXIS2_FAILURE) {
                  adb_UserRealm_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        adb_AccessControlAdmin_t* AXIS2_CALL
                adb_UserRealm_free_popping_value(
                        adb_UserRealm_t* _UserRealm,
                        const axutil_env_t *env)
                {
                    adb_AccessControlAdmin_t* value;

                    
                    
                    value = _UserRealm->property_accessControlAdmin;

                    _UserRealm->property_accessControlAdmin = (adb_AccessControlAdmin_t*)NULL;
                    adb_UserRealm_free(_UserRealm, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_UserRealm_free(
                adb_UserRealm_t* _UserRealm,
                const axutil_env_t *env)
        {
            
            
            return axis2_extension_mapper_free(
                (adb_type_t*) _UserRealm,
                env,
                "adb_UserRealm");
            
        }

        axis2_status_t AXIS2_CALL
        adb_UserRealm_free_obj(
                adb_UserRealm_t* _UserRealm,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _UserRealm, AXIS2_FAILURE);

            if (_UserRealm->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _UserRealm->property_Type);
            }

            adb_UserRealm_reset_accessControlAdmin(_UserRealm, env);
            adb_UserRealm_reset_authenticator(_UserRealm, env);
            adb_UserRealm_reset_authorizer(_UserRealm, env);
            adb_UserRealm_reset_claimsAdmin(_UserRealm, env);
            adb_UserRealm_reset_realmConfiguration(_UserRealm, env);
            adb_UserRealm_reset_userProfileAdmin(_UserRealm, env);
            adb_UserRealm_reset_userStoreAdmin(_UserRealm, env);
            adb_UserRealm_reset_userStoreReader(_UserRealm, env);
            

            if(_UserRealm)
            {
                AXIS2_FREE(env->allocator, _UserRealm);
                _UserRealm = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_UserRealm_deserialize(
                adb_UserRealm_t* _UserRealm,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return axis2_extension_mapper_deserialize(
                (adb_type_t*) _UserRealm,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs,
                "adb_UserRealm");
            
        }

        axis2_status_t AXIS2_CALL
        adb_UserRealm_deserialize_obj(
                adb_UserRealm_t* _UserRealm,
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
            AXIS2_PARAM_CHECK(env->error, _UserRealm, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for UserRealm : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              
                      
                      first_node = axiom_node_get_first_child(parent, env);
                      
                    

                     
                     /*
                      * building accessControlAdmin element
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
                                   
                                 element_qname = axutil_qname_create(env, "accessControlAdmin", "http://core.user.carbon.wso2.org/xsd", NULL);
                                 

                           if (adb_AccessControlAdmin_is_particle() ||  
                                (current_node   && current_element && (axutil_qname_equals(element_qname, env, qname))))
                           {
                              if( current_node   && current_element && (axutil_qname_equals(element_qname, env, qname)))
                              {
                                is_early_node_valid = AXIS2_TRUE;
                              }
                              
                                 
                                      element = (void*)axis2_extension_mapper_create_from_node(env, &current_node, "adb_AccessControlAdmin");

                                      status =  adb_AccessControlAdmin_deserialize((adb_AccessControlAdmin_t*)element,
                                                                            env, &current_node, &is_early_node_valid, AXIS2_FALSE);
                                      if(AXIS2_FAILURE == status)
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building adb object for element accessControlAdmin");
                                      }
                                      else
                                      {
                                          status = adb_UserRealm_set_accessControlAdmin(_UserRealm, env,
                                                                   (adb_AccessControlAdmin_t*)element);
                                      }
                                    
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for accessControlAdmin ");
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
                      * building authenticator element
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
                                 
                                 element_qname = axutil_qname_create(env, "authenticator", "http://core.user.carbon.wso2.org/xsd", NULL);
                                 

                           if (adb_Authenticator_is_particle() ||  
                                (current_node   && current_element && (axutil_qname_equals(element_qname, env, qname))))
                           {
                              if( current_node   && current_element && (axutil_qname_equals(element_qname, env, qname)))
                              {
                                is_early_node_valid = AXIS2_TRUE;
                              }
                              
                                 
                                      element = (void*)axis2_extension_mapper_create_from_node(env, &current_node, "adb_Authenticator");

                                      status =  adb_Authenticator_deserialize((adb_Authenticator_t*)element,
                                                                            env, &current_node, &is_early_node_valid, AXIS2_FALSE);
                                      if(AXIS2_FAILURE == status)
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building adb object for element authenticator");
                                      }
                                      else
                                      {
                                          status = adb_UserRealm_set_authenticator(_UserRealm, env,
                                                                   (adb_Authenticator_t*)element);
                                      }
                                    
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for authenticator ");
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
                      * building authorizer element
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
                                 
                                 element_qname = axutil_qname_create(env, "authorizer", "http://core.user.carbon.wso2.org/xsd", NULL);
                                 

                           if (adb_Authorizer_is_particle() ||  
                                (current_node   && current_element && (axutil_qname_equals(element_qname, env, qname))))
                           {
                              if( current_node   && current_element && (axutil_qname_equals(element_qname, env, qname)))
                              {
                                is_early_node_valid = AXIS2_TRUE;
                              }
                              
                                 
                                      element = (void*)axis2_extension_mapper_create_from_node(env, &current_node, "adb_Authorizer");

                                      status =  adb_Authorizer_deserialize((adb_Authorizer_t*)element,
                                                                            env, &current_node, &is_early_node_valid, AXIS2_FALSE);
                                      if(AXIS2_FAILURE == status)
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building adb object for element authorizer");
                                      }
                                      else
                                      {
                                          status = adb_UserRealm_set_authorizer(_UserRealm, env,
                                                                   (adb_Authorizer_t*)element);
                                      }
                                    
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for authorizer ");
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
                      * building claimsAdmin element
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
                                 
                                 element_qname = axutil_qname_create(env, "claimsAdmin", "http://core.user.carbon.wso2.org/xsd", NULL);
                                 

                           if (adb_UserClaimsAdmin_is_particle() ||  
                                (current_node   && current_element && (axutil_qname_equals(element_qname, env, qname))))
                           {
                              if( current_node   && current_element && (axutil_qname_equals(element_qname, env, qname)))
                              {
                                is_early_node_valid = AXIS2_TRUE;
                              }
                              
                                 
                                      element = (void*)axis2_extension_mapper_create_from_node(env, &current_node, "adb_UserClaimsAdmin");

                                      status =  adb_UserClaimsAdmin_deserialize((adb_UserClaimsAdmin_t*)element,
                                                                            env, &current_node, &is_early_node_valid, AXIS2_FALSE);
                                      if(AXIS2_FAILURE == status)
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building adb object for element claimsAdmin");
                                      }
                                      else
                                      {
                                          status = adb_UserRealm_set_claimsAdmin(_UserRealm, env,
                                                                   (adb_UserClaimsAdmin_t*)element);
                                      }
                                    
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for claimsAdmin ");
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
                      * building realmConfiguration element
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
                                 
                                 element_qname = axutil_qname_create(env, "realmConfiguration", "http://core.user.carbon.wso2.org/xsd", NULL);
                                 

                           if ( 
                                (current_node   && current_element && (axutil_qname_equals(element_qname, env, qname))))
                           {
                              if( current_node   && current_element && (axutil_qname_equals(element_qname, env, qname)))
                              {
                                is_early_node_valid = AXIS2_TRUE;
                              }
                              
                                 
                                      text_value = NULL; /* just to avoid warning */
                                      
                                          if(axiom_node_get_first_child(current_node, env))
                                          {
                                              axiom_node_t *current_property_node = axiom_node_get_first_child(current_node, env);
                                              axiom_node_detach(current_property_node, env);
                                              status = adb_UserRealm_set_realmConfiguration(_UserRealm, env,
                                                                          current_property_node);
                                          }
                                          else
                                          {
                                              status = adb_UserRealm_set_realmConfiguration(_UserRealm, env,
                                                                          NULL);
                                          }
                                        
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for realmConfiguration ");
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
                      * building userProfileAdmin element
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
                                 
                                 element_qname = axutil_qname_create(env, "userProfileAdmin", "http://core.user.carbon.wso2.org/xsd", NULL);
                                 

                           if (adb_UserProfileAdmin_is_particle() ||  
                                (current_node   && current_element && (axutil_qname_equals(element_qname, env, qname))))
                           {
                              if( current_node   && current_element && (axutil_qname_equals(element_qname, env, qname)))
                              {
                                is_early_node_valid = AXIS2_TRUE;
                              }
                              
                                 
                                      element = (void*)axis2_extension_mapper_create_from_node(env, &current_node, "adb_UserProfileAdmin");

                                      status =  adb_UserProfileAdmin_deserialize((adb_UserProfileAdmin_t*)element,
                                                                            env, &current_node, &is_early_node_valid, AXIS2_FALSE);
                                      if(AXIS2_FAILURE == status)
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building adb object for element userProfileAdmin");
                                      }
                                      else
                                      {
                                          status = adb_UserRealm_set_userProfileAdmin(_UserRealm, env,
                                                                   (adb_UserProfileAdmin_t*)element);
                                      }
                                    
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for userProfileAdmin ");
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
                      * building userStoreAdmin element
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
                                 
                                 element_qname = axutil_qname_create(env, "userStoreAdmin", "http://core.user.carbon.wso2.org/xsd", NULL);
                                 

                           if (adb_UserStoreAdmin_is_particle() ||  
                                (current_node   && current_element && (axutil_qname_equals(element_qname, env, qname))))
                           {
                              if( current_node   && current_element && (axutil_qname_equals(element_qname, env, qname)))
                              {
                                is_early_node_valid = AXIS2_TRUE;
                              }
                              
                                 
                                      element = (void*)axis2_extension_mapper_create_from_node(env, &current_node, "adb_UserStoreAdmin");

                                      status =  adb_UserStoreAdmin_deserialize((adb_UserStoreAdmin_t*)element,
                                                                            env, &current_node, &is_early_node_valid, AXIS2_FALSE);
                                      if(AXIS2_FAILURE == status)
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building adb object for element userStoreAdmin");
                                      }
                                      else
                                      {
                                          status = adb_UserRealm_set_userStoreAdmin(_UserRealm, env,
                                                                   (adb_UserStoreAdmin_t*)element);
                                      }
                                    
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for userStoreAdmin ");
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
                      * building userStoreReader element
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
                                 
                                 element_qname = axutil_qname_create(env, "userStoreReader", "http://core.user.carbon.wso2.org/xsd", NULL);
                                 

                           if (adb_UserStoreReader_is_particle() ||  
                                (current_node   && current_element && (axutil_qname_equals(element_qname, env, qname))))
                           {
                              if( current_node   && current_element && (axutil_qname_equals(element_qname, env, qname)))
                              {
                                is_early_node_valid = AXIS2_TRUE;
                              }
                              
                                 
                                      element = (void*)axis2_extension_mapper_create_from_node(env, &current_node, "adb_UserStoreReader");

                                      status =  adb_UserStoreReader_deserialize((adb_UserStoreReader_t*)element,
                                                                            env, &current_node, &is_early_node_valid, AXIS2_FALSE);
                                      if(AXIS2_FAILURE == status)
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building adb object for element userStoreReader");
                                      }
                                      else
                                      {
                                          status = adb_UserRealm_set_userStoreReader(_UserRealm, env,
                                                                   (adb_UserStoreReader_t*)element);
                                      }
                                    
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for userStoreReader ");
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
          adb_UserRealm_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_UserRealm_declare_parent_namespaces(
                    adb_UserRealm_t* _UserRealm,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_UserRealm_serialize(
                adb_UserRealm_t* _UserRealm,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
            if (_UserRealm == NULL)
            {
                return adb_UserRealm_serialize_obj(
                    _UserRealm, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            }
            else
            {
                return axis2_extension_mapper_serialize(
                    (adb_type_t*) _UserRealm, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index, "adb_UserRealm");
            }
            
        }

        axiom_node_t* AXIS2_CALL
        adb_UserRealm_serialize_obj(
                adb_UserRealm_t* _UserRealm,
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
                    
                    axis2_char_t *text_value_5;
                    axis2_char_t *text_value_5_temp;
                    
                    axis2_char_t text_value_6[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t text_value_7[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t text_value_8[ADB_DEFAULT_DIGIT_LIMIT];
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _UserRealm, NULL);
            
            
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
              type_attrib = axutil_strcat(env, " ", xsi_prefix, ":type=\"UserRealm\"", NULL);
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
                                 "http://core.user.carbon.wso2.org/xsd",
                                 xsi_prefix);
            xsi_type_attri = axiom_attribute_create (env, "type", "UserRealm", xsi_ns);
            
            axiom_element_add_attribute (parent_element, env, xsi_type_attri, parent);
        
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://core.user.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://core.user.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://core.user.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_UserRealm->is_valid_accessControlAdmin)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("accessControlAdmin"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("accessControlAdmin")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing accessControlAdmin element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%saccessControlAdmin",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%saccessControlAdmin>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                     
                            if(!adb_AccessControlAdmin_is_particle())
                            {
                                axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                            }
                            adb_AccessControlAdmin_serialize(_UserRealm->property_accessControlAdmin, 
                                                                                 env, current_node, parent_element,
                                                                                 adb_AccessControlAdmin_is_particle() || AXIS2_FALSE, namespaces, next_ns_index);
                            
                            if(!adb_AccessControlAdmin_is_particle())
                            {
                                axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                            }
                            
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://core.user.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://core.user.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://core.user.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_UserRealm->is_valid_authenticator)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("authenticator"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("authenticator")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing authenticator element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sauthenticator",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sauthenticator>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                     
                            if(!adb_Authenticator_is_particle())
                            {
                                axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                            }
                            adb_Authenticator_serialize(_UserRealm->property_authenticator, 
                                                                                 env, current_node, parent_element,
                                                                                 adb_Authenticator_is_particle() || AXIS2_FALSE, namespaces, next_ns_index);
                            
                            if(!adb_Authenticator_is_particle())
                            {
                                axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                            }
                            
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://core.user.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://core.user.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://core.user.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_UserRealm->is_valid_authorizer)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("authorizer"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("authorizer")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing authorizer element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sauthorizer",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sauthorizer>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                     
                            if(!adb_Authorizer_is_particle())
                            {
                                axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                            }
                            adb_Authorizer_serialize(_UserRealm->property_authorizer, 
                                                                                 env, current_node, parent_element,
                                                                                 adb_Authorizer_is_particle() || AXIS2_FALSE, namespaces, next_ns_index);
                            
                            if(!adb_Authorizer_is_particle())
                            {
                                axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                            }
                            
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://core.user.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://core.user.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://core.user.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_UserRealm->is_valid_claimsAdmin)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("claimsAdmin"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("claimsAdmin")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing claimsAdmin element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sclaimsAdmin",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sclaimsAdmin>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                     
                            if(!adb_UserClaimsAdmin_is_particle())
                            {
                                axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                            }
                            adb_UserClaimsAdmin_serialize(_UserRealm->property_claimsAdmin, 
                                                                                 env, current_node, parent_element,
                                                                                 adb_UserClaimsAdmin_is_particle() || AXIS2_FALSE, namespaces, next_ns_index);
                            
                            if(!adb_UserClaimsAdmin_is_particle())
                            {
                                axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                            }
                            
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://core.user.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://core.user.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://core.user.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_UserRealm->is_valid_realmConfiguration)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("realmConfiguration"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("realmConfiguration")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing realmConfiguration element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%srealmConfiguration>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%srealmConfiguration>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                                text_value_5 = axiom_node_to_string(_UserRealm->property_realmConfiguration, env);
                                
                                axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                                
                                axutil_stream_write(stream, env, text_value_5, axutil_strlen(text_value_5));
                                
                                axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                                
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://core.user.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://core.user.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://core.user.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_UserRealm->is_valid_userProfileAdmin)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("userProfileAdmin"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("userProfileAdmin")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing userProfileAdmin element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%suserProfileAdmin",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%suserProfileAdmin>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                     
                            if(!adb_UserProfileAdmin_is_particle())
                            {
                                axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                            }
                            adb_UserProfileAdmin_serialize(_UserRealm->property_userProfileAdmin, 
                                                                                 env, current_node, parent_element,
                                                                                 adb_UserProfileAdmin_is_particle() || AXIS2_FALSE, namespaces, next_ns_index);
                            
                            if(!adb_UserProfileAdmin_is_particle())
                            {
                                axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                            }
                            
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://core.user.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://core.user.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://core.user.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_UserRealm->is_valid_userStoreAdmin)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("userStoreAdmin"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("userStoreAdmin")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing userStoreAdmin element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%suserStoreAdmin",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%suserStoreAdmin>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                     
                            if(!adb_UserStoreAdmin_is_particle())
                            {
                                axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                            }
                            adb_UserStoreAdmin_serialize(_UserRealm->property_userStoreAdmin, 
                                                                                 env, current_node, parent_element,
                                                                                 adb_UserStoreAdmin_is_particle() || AXIS2_FALSE, namespaces, next_ns_index);
                            
                            if(!adb_UserStoreAdmin_is_particle())
                            {
                                axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                            }
                            
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://core.user.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://core.user.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://core.user.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_UserRealm->is_valid_userStoreReader)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("userStoreReader"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("userStoreReader")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing userStoreReader element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%suserStoreReader",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%suserStoreReader>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                     
                            if(!adb_UserStoreReader_is_particle())
                            {
                                axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                            }
                            adb_UserStoreReader_serialize(_UserRealm->property_userStoreReader, 
                                                                                 env, current_node, parent_element,
                                                                                 adb_UserStoreReader_is_particle() || AXIS2_FALSE, namespaces, next_ns_index);
                            
                            if(!adb_UserStoreReader_is_particle())
                            {
                                axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                            }
                            
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 

            return parent;
        }


        

            /**
             * Getter for accessControlAdmin by  Property Number 1
             */
            adb_AccessControlAdmin_t* AXIS2_CALL
            adb_UserRealm_get_property1(
                adb_UserRealm_t* _UserRealm,
                const axutil_env_t *env)
            {
                return adb_UserRealm_get_accessControlAdmin(_UserRealm,
                                             env);
            }

            /**
             * getter for accessControlAdmin.
             */
            adb_AccessControlAdmin_t* AXIS2_CALL
            adb_UserRealm_get_accessControlAdmin(
                    adb_UserRealm_t* _UserRealm,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _UserRealm, NULL);
                  

                return _UserRealm->property_accessControlAdmin;
             }

            /**
             * setter for accessControlAdmin
             */
            axis2_status_t AXIS2_CALL
            adb_UserRealm_set_accessControlAdmin(
                    adb_UserRealm_t* _UserRealm,
                    const axutil_env_t *env,
                    adb_AccessControlAdmin_t*  arg_accessControlAdmin)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _UserRealm, AXIS2_FAILURE);
                
                if(_UserRealm->is_valid_accessControlAdmin &&
                        arg_accessControlAdmin == _UserRealm->property_accessControlAdmin)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_UserRealm_reset_accessControlAdmin(_UserRealm, env);

                
                if(NULL == arg_accessControlAdmin)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _UserRealm->property_accessControlAdmin = arg_accessControlAdmin;
                        _UserRealm->is_valid_accessControlAdmin = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for accessControlAdmin
            */
           axis2_status_t AXIS2_CALL
           adb_UserRealm_reset_accessControlAdmin(
                   adb_UserRealm_t* _UserRealm,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _UserRealm, AXIS2_FAILURE);
               

               
            
                
                if(_UserRealm->property_accessControlAdmin != NULL)
                {
                   
                   adb_AccessControlAdmin_free(_UserRealm->property_accessControlAdmin, env);
                     _UserRealm->property_accessControlAdmin = NULL;
                }
            
                
                
                _UserRealm->is_valid_accessControlAdmin = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether accessControlAdmin is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_UserRealm_is_accessControlAdmin_nil(
                   adb_UserRealm_t* _UserRealm,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _UserRealm, AXIS2_TRUE);
               
               return !_UserRealm->is_valid_accessControlAdmin;
           }

           /**
            * Set accessControlAdmin to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_UserRealm_set_accessControlAdmin_nil(
                   adb_UserRealm_t* _UserRealm,
                   const axutil_env_t *env)
           {
               return adb_UserRealm_reset_accessControlAdmin(_UserRealm, env);
           }

           

            /**
             * Getter for authenticator by  Property Number 2
             */
            adb_Authenticator_t* AXIS2_CALL
            adb_UserRealm_get_property2(
                adb_UserRealm_t* _UserRealm,
                const axutil_env_t *env)
            {
                return adb_UserRealm_get_authenticator(_UserRealm,
                                             env);
            }

            /**
             * getter for authenticator.
             */
            adb_Authenticator_t* AXIS2_CALL
            adb_UserRealm_get_authenticator(
                    adb_UserRealm_t* _UserRealm,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _UserRealm, NULL);
                  

                return _UserRealm->property_authenticator;
             }

            /**
             * setter for authenticator
             */
            axis2_status_t AXIS2_CALL
            adb_UserRealm_set_authenticator(
                    adb_UserRealm_t* _UserRealm,
                    const axutil_env_t *env,
                    adb_Authenticator_t*  arg_authenticator)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _UserRealm, AXIS2_FAILURE);
                
                if(_UserRealm->is_valid_authenticator &&
                        arg_authenticator == _UserRealm->property_authenticator)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_UserRealm_reset_authenticator(_UserRealm, env);

                
                if(NULL == arg_authenticator)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _UserRealm->property_authenticator = arg_authenticator;
                        _UserRealm->is_valid_authenticator = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for authenticator
            */
           axis2_status_t AXIS2_CALL
           adb_UserRealm_reset_authenticator(
                   adb_UserRealm_t* _UserRealm,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _UserRealm, AXIS2_FAILURE);
               

               
            
                
                if(_UserRealm->property_authenticator != NULL)
                {
                   
                   adb_Authenticator_free(_UserRealm->property_authenticator, env);
                     _UserRealm->property_authenticator = NULL;
                }
            
                
                
                _UserRealm->is_valid_authenticator = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether authenticator is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_UserRealm_is_authenticator_nil(
                   adb_UserRealm_t* _UserRealm,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _UserRealm, AXIS2_TRUE);
               
               return !_UserRealm->is_valid_authenticator;
           }

           /**
            * Set authenticator to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_UserRealm_set_authenticator_nil(
                   adb_UserRealm_t* _UserRealm,
                   const axutil_env_t *env)
           {
               return adb_UserRealm_reset_authenticator(_UserRealm, env);
           }

           

            /**
             * Getter for authorizer by  Property Number 3
             */
            adb_Authorizer_t* AXIS2_CALL
            adb_UserRealm_get_property3(
                adb_UserRealm_t* _UserRealm,
                const axutil_env_t *env)
            {
                return adb_UserRealm_get_authorizer(_UserRealm,
                                             env);
            }

            /**
             * getter for authorizer.
             */
            adb_Authorizer_t* AXIS2_CALL
            adb_UserRealm_get_authorizer(
                    adb_UserRealm_t* _UserRealm,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _UserRealm, NULL);
                  

                return _UserRealm->property_authorizer;
             }

            /**
             * setter for authorizer
             */
            axis2_status_t AXIS2_CALL
            adb_UserRealm_set_authorizer(
                    adb_UserRealm_t* _UserRealm,
                    const axutil_env_t *env,
                    adb_Authorizer_t*  arg_authorizer)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _UserRealm, AXIS2_FAILURE);
                
                if(_UserRealm->is_valid_authorizer &&
                        arg_authorizer == _UserRealm->property_authorizer)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_UserRealm_reset_authorizer(_UserRealm, env);

                
                if(NULL == arg_authorizer)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _UserRealm->property_authorizer = arg_authorizer;
                        _UserRealm->is_valid_authorizer = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for authorizer
            */
           axis2_status_t AXIS2_CALL
           adb_UserRealm_reset_authorizer(
                   adb_UserRealm_t* _UserRealm,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _UserRealm, AXIS2_FAILURE);
               

               
            
                
                if(_UserRealm->property_authorizer != NULL)
                {
                   
                   adb_Authorizer_free(_UserRealm->property_authorizer, env);
                     _UserRealm->property_authorizer = NULL;
                }
            
                
                
                _UserRealm->is_valid_authorizer = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether authorizer is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_UserRealm_is_authorizer_nil(
                   adb_UserRealm_t* _UserRealm,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _UserRealm, AXIS2_TRUE);
               
               return !_UserRealm->is_valid_authorizer;
           }

           /**
            * Set authorizer to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_UserRealm_set_authorizer_nil(
                   adb_UserRealm_t* _UserRealm,
                   const axutil_env_t *env)
           {
               return adb_UserRealm_reset_authorizer(_UserRealm, env);
           }

           

            /**
             * Getter for claimsAdmin by  Property Number 4
             */
            adb_UserClaimsAdmin_t* AXIS2_CALL
            adb_UserRealm_get_property4(
                adb_UserRealm_t* _UserRealm,
                const axutil_env_t *env)
            {
                return adb_UserRealm_get_claimsAdmin(_UserRealm,
                                             env);
            }

            /**
             * getter for claimsAdmin.
             */
            adb_UserClaimsAdmin_t* AXIS2_CALL
            adb_UserRealm_get_claimsAdmin(
                    adb_UserRealm_t* _UserRealm,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _UserRealm, NULL);
                  

                return _UserRealm->property_claimsAdmin;
             }

            /**
             * setter for claimsAdmin
             */
            axis2_status_t AXIS2_CALL
            adb_UserRealm_set_claimsAdmin(
                    adb_UserRealm_t* _UserRealm,
                    const axutil_env_t *env,
                    adb_UserClaimsAdmin_t*  arg_claimsAdmin)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _UserRealm, AXIS2_FAILURE);
                
                if(_UserRealm->is_valid_claimsAdmin &&
                        arg_claimsAdmin == _UserRealm->property_claimsAdmin)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_UserRealm_reset_claimsAdmin(_UserRealm, env);

                
                if(NULL == arg_claimsAdmin)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _UserRealm->property_claimsAdmin = arg_claimsAdmin;
                        _UserRealm->is_valid_claimsAdmin = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for claimsAdmin
            */
           axis2_status_t AXIS2_CALL
           adb_UserRealm_reset_claimsAdmin(
                   adb_UserRealm_t* _UserRealm,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _UserRealm, AXIS2_FAILURE);
               

               
            
                
                if(_UserRealm->property_claimsAdmin != NULL)
                {
                   
                   adb_UserClaimsAdmin_free(_UserRealm->property_claimsAdmin, env);
                     _UserRealm->property_claimsAdmin = NULL;
                }
            
                
                
                _UserRealm->is_valid_claimsAdmin = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether claimsAdmin is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_UserRealm_is_claimsAdmin_nil(
                   adb_UserRealm_t* _UserRealm,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _UserRealm, AXIS2_TRUE);
               
               return !_UserRealm->is_valid_claimsAdmin;
           }

           /**
            * Set claimsAdmin to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_UserRealm_set_claimsAdmin_nil(
                   adb_UserRealm_t* _UserRealm,
                   const axutil_env_t *env)
           {
               return adb_UserRealm_reset_claimsAdmin(_UserRealm, env);
           }

           

            /**
             * Getter for realmConfiguration by  Property Number 5
             */
            axiom_node_t* AXIS2_CALL
            adb_UserRealm_get_property5(
                adb_UserRealm_t* _UserRealm,
                const axutil_env_t *env)
            {
                return adb_UserRealm_get_realmConfiguration(_UserRealm,
                                             env);
            }

            /**
             * getter for realmConfiguration.
             */
            axiom_node_t* AXIS2_CALL
            adb_UserRealm_get_realmConfiguration(
                    adb_UserRealm_t* _UserRealm,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _UserRealm, NULL);
                  

                return _UserRealm->property_realmConfiguration;
             }

            /**
             * setter for realmConfiguration
             */
            axis2_status_t AXIS2_CALL
            adb_UserRealm_set_realmConfiguration(
                    adb_UserRealm_t* _UserRealm,
                    const axutil_env_t *env,
                    axiom_node_t*  arg_realmConfiguration)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _UserRealm, AXIS2_FAILURE);
                
                if(_UserRealm->is_valid_realmConfiguration &&
                        arg_realmConfiguration == _UserRealm->property_realmConfiguration)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_UserRealm_reset_realmConfiguration(_UserRealm, env);

                
                if(NULL == arg_realmConfiguration)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _UserRealm->property_realmConfiguration = arg_realmConfiguration;
                        _UserRealm->is_valid_realmConfiguration = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for realmConfiguration
            */
           axis2_status_t AXIS2_CALL
           adb_UserRealm_reset_realmConfiguration(
                   adb_UserRealm_t* _UserRealm,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _UserRealm, AXIS2_FAILURE);
               

               _UserRealm->is_valid_realmConfiguration = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether realmConfiguration is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_UserRealm_is_realmConfiguration_nil(
                   adb_UserRealm_t* _UserRealm,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _UserRealm, AXIS2_TRUE);
               
               return !_UserRealm->is_valid_realmConfiguration;
           }

           /**
            * Set realmConfiguration to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_UserRealm_set_realmConfiguration_nil(
                   adb_UserRealm_t* _UserRealm,
                   const axutil_env_t *env)
           {
               return adb_UserRealm_reset_realmConfiguration(_UserRealm, env);
           }

           

            /**
             * Getter for userProfileAdmin by  Property Number 6
             */
            adb_UserProfileAdmin_t* AXIS2_CALL
            adb_UserRealm_get_property6(
                adb_UserRealm_t* _UserRealm,
                const axutil_env_t *env)
            {
                return adb_UserRealm_get_userProfileAdmin(_UserRealm,
                                             env);
            }

            /**
             * getter for userProfileAdmin.
             */
            adb_UserProfileAdmin_t* AXIS2_CALL
            adb_UserRealm_get_userProfileAdmin(
                    adb_UserRealm_t* _UserRealm,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _UserRealm, NULL);
                  

                return _UserRealm->property_userProfileAdmin;
             }

            /**
             * setter for userProfileAdmin
             */
            axis2_status_t AXIS2_CALL
            adb_UserRealm_set_userProfileAdmin(
                    adb_UserRealm_t* _UserRealm,
                    const axutil_env_t *env,
                    adb_UserProfileAdmin_t*  arg_userProfileAdmin)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _UserRealm, AXIS2_FAILURE);
                
                if(_UserRealm->is_valid_userProfileAdmin &&
                        arg_userProfileAdmin == _UserRealm->property_userProfileAdmin)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_UserRealm_reset_userProfileAdmin(_UserRealm, env);

                
                if(NULL == arg_userProfileAdmin)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _UserRealm->property_userProfileAdmin = arg_userProfileAdmin;
                        _UserRealm->is_valid_userProfileAdmin = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for userProfileAdmin
            */
           axis2_status_t AXIS2_CALL
           adb_UserRealm_reset_userProfileAdmin(
                   adb_UserRealm_t* _UserRealm,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _UserRealm, AXIS2_FAILURE);
               

               
            
                
                if(_UserRealm->property_userProfileAdmin != NULL)
                {
                   
                   adb_UserProfileAdmin_free(_UserRealm->property_userProfileAdmin, env);
                     _UserRealm->property_userProfileAdmin = NULL;
                }
            
                
                
                _UserRealm->is_valid_userProfileAdmin = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether userProfileAdmin is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_UserRealm_is_userProfileAdmin_nil(
                   adb_UserRealm_t* _UserRealm,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _UserRealm, AXIS2_TRUE);
               
               return !_UserRealm->is_valid_userProfileAdmin;
           }

           /**
            * Set userProfileAdmin to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_UserRealm_set_userProfileAdmin_nil(
                   adb_UserRealm_t* _UserRealm,
                   const axutil_env_t *env)
           {
               return adb_UserRealm_reset_userProfileAdmin(_UserRealm, env);
           }

           

            /**
             * Getter for userStoreAdmin by  Property Number 7
             */
            adb_UserStoreAdmin_t* AXIS2_CALL
            adb_UserRealm_get_property7(
                adb_UserRealm_t* _UserRealm,
                const axutil_env_t *env)
            {
                return adb_UserRealm_get_userStoreAdmin(_UserRealm,
                                             env);
            }

            /**
             * getter for userStoreAdmin.
             */
            adb_UserStoreAdmin_t* AXIS2_CALL
            adb_UserRealm_get_userStoreAdmin(
                    adb_UserRealm_t* _UserRealm,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _UserRealm, NULL);
                  

                return _UserRealm->property_userStoreAdmin;
             }

            /**
             * setter for userStoreAdmin
             */
            axis2_status_t AXIS2_CALL
            adb_UserRealm_set_userStoreAdmin(
                    adb_UserRealm_t* _UserRealm,
                    const axutil_env_t *env,
                    adb_UserStoreAdmin_t*  arg_userStoreAdmin)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _UserRealm, AXIS2_FAILURE);
                
                if(_UserRealm->is_valid_userStoreAdmin &&
                        arg_userStoreAdmin == _UserRealm->property_userStoreAdmin)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_UserRealm_reset_userStoreAdmin(_UserRealm, env);

                
                if(NULL == arg_userStoreAdmin)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _UserRealm->property_userStoreAdmin = arg_userStoreAdmin;
                        _UserRealm->is_valid_userStoreAdmin = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for userStoreAdmin
            */
           axis2_status_t AXIS2_CALL
           adb_UserRealm_reset_userStoreAdmin(
                   adb_UserRealm_t* _UserRealm,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _UserRealm, AXIS2_FAILURE);
               

               
            
                
                if(_UserRealm->property_userStoreAdmin != NULL)
                {
                   
                   adb_UserStoreAdmin_free(_UserRealm->property_userStoreAdmin, env);
                     _UserRealm->property_userStoreAdmin = NULL;
                }
            
                
                
                _UserRealm->is_valid_userStoreAdmin = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether userStoreAdmin is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_UserRealm_is_userStoreAdmin_nil(
                   adb_UserRealm_t* _UserRealm,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _UserRealm, AXIS2_TRUE);
               
               return !_UserRealm->is_valid_userStoreAdmin;
           }

           /**
            * Set userStoreAdmin to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_UserRealm_set_userStoreAdmin_nil(
                   adb_UserRealm_t* _UserRealm,
                   const axutil_env_t *env)
           {
               return adb_UserRealm_reset_userStoreAdmin(_UserRealm, env);
           }

           

            /**
             * Getter for userStoreReader by  Property Number 8
             */
            adb_UserStoreReader_t* AXIS2_CALL
            adb_UserRealm_get_property8(
                adb_UserRealm_t* _UserRealm,
                const axutil_env_t *env)
            {
                return adb_UserRealm_get_userStoreReader(_UserRealm,
                                             env);
            }

            /**
             * getter for userStoreReader.
             */
            adb_UserStoreReader_t* AXIS2_CALL
            adb_UserRealm_get_userStoreReader(
                    adb_UserRealm_t* _UserRealm,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _UserRealm, NULL);
                  

                return _UserRealm->property_userStoreReader;
             }

            /**
             * setter for userStoreReader
             */
            axis2_status_t AXIS2_CALL
            adb_UserRealm_set_userStoreReader(
                    adb_UserRealm_t* _UserRealm,
                    const axutil_env_t *env,
                    adb_UserStoreReader_t*  arg_userStoreReader)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _UserRealm, AXIS2_FAILURE);
                
                if(_UserRealm->is_valid_userStoreReader &&
                        arg_userStoreReader == _UserRealm->property_userStoreReader)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_UserRealm_reset_userStoreReader(_UserRealm, env);

                
                if(NULL == arg_userStoreReader)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _UserRealm->property_userStoreReader = arg_userStoreReader;
                        _UserRealm->is_valid_userStoreReader = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for userStoreReader
            */
           axis2_status_t AXIS2_CALL
           adb_UserRealm_reset_userStoreReader(
                   adb_UserRealm_t* _UserRealm,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _UserRealm, AXIS2_FAILURE);
               

               
            
                
                if(_UserRealm->property_userStoreReader != NULL)
                {
                   
                   adb_UserStoreReader_free(_UserRealm->property_userStoreReader, env);
                     _UserRealm->property_userStoreReader = NULL;
                }
            
                
                
                _UserRealm->is_valid_userStoreReader = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether userStoreReader is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_UserRealm_is_userStoreReader_nil(
                   adb_UserRealm_t* _UserRealm,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _UserRealm, AXIS2_TRUE);
               
               return !_UserRealm->is_valid_userStoreReader;
           }

           /**
            * Set userStoreReader to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_UserRealm_set_userStoreReader_nil(
                   adb_UserRealm_t* _UserRealm,
                   const axutil_env_t *env)
           {
               return adb_UserRealm_reset_userStoreReader(_UserRealm, env);
           }

           

