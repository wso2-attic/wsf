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
         * adb_Claim.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_Claim.h"
        
                /*
                 * This type was generated from the piece of schema that had
                 * name = Claim
                 * Namespace URI = http://core.user.carbon.wso2.org/xsd
                 * Namespace Prefix = ns2
                 */
           


        struct adb_Claim
        {
            axis2_char_t *property_Type;

            axis2_char_t* property_claimUri;

                
                axis2_bool_t is_valid_claimUri;
            axis2_char_t* property_description;

                
                axis2_bool_t is_valid_description;
            axis2_char_t* property_dialectURI;

                
                axis2_bool_t is_valid_dialectURI;
            int property_displayOrder;

                
                axis2_bool_t is_valid_displayOrder;
            axis2_char_t* property_displayTag;

                
                axis2_bool_t is_valid_displayTag;
            axis2_char_t* property_regEx;

                
                axis2_bool_t is_valid_regEx;
            axis2_bool_t property_required;

                
                axis2_bool_t is_valid_required;
            axis2_bool_t property_supportedByDefault;

                
                axis2_bool_t is_valid_supportedByDefault;
            axis2_char_t* property_value;

                
                axis2_bool_t is_valid_value;
            
        };


       /************************* Private Function prototypes ********************************/
        

                axis2_status_t AXIS2_CALL
                adb_Claim_set_displayOrder_nil(
                        adb_Claim_t* _Claim,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_Claim_set_required_nil(
                        adb_Claim_t* _Claim,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_Claim_set_supportedByDefault_nil(
                        adb_Claim_t* _Claim,
                        const axutil_env_t *env);
            


       /************************* Function Implmentations ********************************/
        adb_Claim_t* AXIS2_CALL
        adb_Claim_create(
            const axutil_env_t *env)
        {
            adb_Claim_t *_Claim = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _Claim = (adb_Claim_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_Claim_t));

            if(NULL == _Claim)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_Claim, 0, sizeof(adb_Claim_t));

            _Claim->property_Type = axutil_strdup(env, "adb_Claim");
            _Claim->property_claimUri  = NULL;
                  _Claim->is_valid_claimUri  = AXIS2_FALSE;
            _Claim->property_description  = NULL;
                  _Claim->is_valid_description  = AXIS2_FALSE;
            _Claim->property_dialectURI  = NULL;
                  _Claim->is_valid_dialectURI  = AXIS2_FALSE;
            _Claim->is_valid_displayOrder  = AXIS2_FALSE;
            _Claim->property_displayTag  = NULL;
                  _Claim->is_valid_displayTag  = AXIS2_FALSE;
            _Claim->property_regEx  = NULL;
                  _Claim->is_valid_regEx  = AXIS2_FALSE;
            _Claim->is_valid_required  = AXIS2_FALSE;
            _Claim->is_valid_supportedByDefault  = AXIS2_FALSE;
            _Claim->property_value  = NULL;
                  _Claim->is_valid_value  = AXIS2_FALSE;
            

            return _Claim;
        }

        adb_Claim_t* AXIS2_CALL
        adb_Claim_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _claimUri,
                axis2_char_t* _description,
                axis2_char_t* _dialectURI,
                int _displayOrder,
                axis2_char_t* _displayTag,
                axis2_char_t* _regEx,
                axis2_bool_t _required,
                axis2_bool_t _supportedByDefault,
                axis2_char_t* _value)
        {
            adb_Claim_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_Claim_create(env);

            
              status = adb_Claim_set_claimUri(
                                     adb_obj,
                                     env,
                                     _claimUri);
              if(status == AXIS2_FAILURE) {
                  adb_Claim_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_Claim_set_description(
                                     adb_obj,
                                     env,
                                     _description);
              if(status == AXIS2_FAILURE) {
                  adb_Claim_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_Claim_set_dialectURI(
                                     adb_obj,
                                     env,
                                     _dialectURI);
              if(status == AXIS2_FAILURE) {
                  adb_Claim_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_Claim_set_displayOrder(
                                     adb_obj,
                                     env,
                                     _displayOrder);
              if(status == AXIS2_FAILURE) {
                  adb_Claim_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_Claim_set_displayTag(
                                     adb_obj,
                                     env,
                                     _displayTag);
              if(status == AXIS2_FAILURE) {
                  adb_Claim_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_Claim_set_regEx(
                                     adb_obj,
                                     env,
                                     _regEx);
              if(status == AXIS2_FAILURE) {
                  adb_Claim_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_Claim_set_required(
                                     adb_obj,
                                     env,
                                     _required);
              if(status == AXIS2_FAILURE) {
                  adb_Claim_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_Claim_set_supportedByDefault(
                                     adb_obj,
                                     env,
                                     _supportedByDefault);
              if(status == AXIS2_FAILURE) {
                  adb_Claim_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_Claim_set_value(
                                     adb_obj,
                                     env,
                                     _value);
              if(status == AXIS2_FAILURE) {
                  adb_Claim_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_char_t* AXIS2_CALL
                adb_Claim_free_popping_value(
                        adb_Claim_t* _Claim,
                        const axutil_env_t *env)
                {
                    axis2_char_t* value;

                    
                    
                    value = _Claim->property_claimUri;

                    _Claim->property_claimUri = (axis2_char_t*)NULL;
                    adb_Claim_free(_Claim, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_Claim_free(
                adb_Claim_t* _Claim,
                const axutil_env_t *env)
        {
            
            
            return axis2_extension_mapper_free(
                (adb_type_t*) _Claim,
                env,
                "adb_Claim");
            
        }

        axis2_status_t AXIS2_CALL
        adb_Claim_free_obj(
                adb_Claim_t* _Claim,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _Claim, AXIS2_FAILURE);

            if (_Claim->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _Claim->property_Type);
            }

            adb_Claim_reset_claimUri(_Claim, env);
            adb_Claim_reset_description(_Claim, env);
            adb_Claim_reset_dialectURI(_Claim, env);
            adb_Claim_reset_displayOrder(_Claim, env);
            adb_Claim_reset_displayTag(_Claim, env);
            adb_Claim_reset_regEx(_Claim, env);
            adb_Claim_reset_required(_Claim, env);
            adb_Claim_reset_supportedByDefault(_Claim, env);
            adb_Claim_reset_value(_Claim, env);
            

            if(_Claim)
            {
                AXIS2_FREE(env->allocator, _Claim);
                _Claim = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_Claim_deserialize(
                adb_Claim_t* _Claim,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return axis2_extension_mapper_deserialize(
                (adb_type_t*) _Claim,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs,
                "adb_Claim");
            
        }

        axis2_status_t AXIS2_CALL
        adb_Claim_deserialize_obj(
                adb_Claim_t* _Claim,
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
            AXIS2_PARAM_CHECK(env->error, _Claim, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for Claim : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              
                      
                      first_node = axiom_node_get_first_child(parent, env);
                      
                    

                     
                     /*
                      * building claimUri element
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
                                   
                                 element_qname = axutil_qname_create(env, "claimUri", "http://core.user.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_Claim_set_claimUri(_Claim, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for claimUri ");
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
                                 
                                 element_qname = axutil_qname_create(env, "description", "http://core.user.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_Claim_set_description(_Claim, env,
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
                      * building dialectURI element
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
                                 
                                 element_qname = axutil_qname_create(env, "dialectURI", "http://core.user.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_Claim_set_dialectURI(_Claim, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for dialectURI ");
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
                      * building displayOrder element
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
                                 
                                 element_qname = axutil_qname_create(env, "displayOrder", "http://core.user.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_Claim_set_displayOrder(_Claim, env,
                                                                   atoi(text_value));
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element displayOrder");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for displayOrder ");
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
                      * building displayTag element
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
                                 
                                 element_qname = axutil_qname_create(env, "displayTag", "http://core.user.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_Claim_set_displayTag(_Claim, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for displayTag ");
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
                      * building regEx element
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
                                 
                                 element_qname = axutil_qname_create(env, "regEx", "http://core.user.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_Claim_set_regEx(_Claim, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for regEx ");
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
                      * building required element
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
                                 
                                 element_qname = axutil_qname_create(env, "required", "http://core.user.carbon.wso2.org/xsd", NULL);
                                 

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
                                                status = adb_Claim_set_required(_Claim, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_Claim_set_required(_Claim, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element required");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for required ");
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
                      * building supportedByDefault element
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
                                 
                                 element_qname = axutil_qname_create(env, "supportedByDefault", "http://core.user.carbon.wso2.org/xsd", NULL);
                                 

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
                                                status = adb_Claim_set_supportedByDefault(_Claim, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_Claim_set_supportedByDefault(_Claim, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element supportedByDefault");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for supportedByDefault ");
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
                      * building value element
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
                                 
                                 element_qname = axutil_qname_create(env, "value", "http://core.user.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_Claim_set_value(_Claim, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for value ");
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
          adb_Claim_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_Claim_declare_parent_namespaces(
                    adb_Claim_t* _Claim,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_Claim_serialize(
                adb_Claim_t* _Claim,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
            if (_Claim == NULL)
            {
                return adb_Claim_serialize_obj(
                    _Claim, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            }
            else
            {
                return axis2_extension_mapper_serialize(
                    (adb_type_t*) _Claim, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index, "adb_Claim");
            }
            
        }

        axiom_node_t* AXIS2_CALL
        adb_Claim_serialize_obj(
                adb_Claim_t* _Claim,
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
                    
                    axis2_char_t text_value_4[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t *text_value_5;
                    axis2_char_t *text_value_5_temp;
                    
                    axis2_char_t *text_value_6;
                    axis2_char_t *text_value_6_temp;
                    
                    axis2_char_t text_value_7[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t text_value_8[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t *text_value_9;
                    axis2_char_t *text_value_9_temp;
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _Claim, NULL);
            
            
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
              type_attrib = axutil_strcat(env, " ", xsi_prefix, ":type=\"Claim\"", NULL);
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
            xsi_type_attri = axiom_attribute_create (env, "type", "Claim", xsi_ns);
            
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
                      

                   if (!_Claim->is_valid_claimUri)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("claimUri"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("claimUri")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing claimUri element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sclaimUri>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sclaimUri>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_1 = _Claim->property_claimUri;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://core.user.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://core.user.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://core.user.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_Claim->is_valid_description)
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
                    
                           text_value_2 = _Claim->property_description;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://core.user.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://core.user.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://core.user.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_Claim->is_valid_dialectURI)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("dialectURI"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("dialectURI")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing dialectURI element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sdialectURI>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sdialectURI>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_3 = _Claim->property_dialectURI;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://core.user.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://core.user.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://core.user.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_Claim->is_valid_displayOrder)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("displayOrder"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("displayOrder")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing displayOrder element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sdisplayOrder>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sdisplayOrder>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                               sprintf (text_value_4, AXIS2_PRINTF_INT32_FORMAT_SPECIFIER, _Claim->property_displayOrder);
                             
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_4, axutil_strlen(text_value_4));
                           
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
                      

                   if (!_Claim->is_valid_displayTag)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("displayTag"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("displayTag")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing displayTag element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sdisplayTag>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sdisplayTag>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_5 = _Claim->property_displayTag;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://core.user.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://core.user.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://core.user.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_Claim->is_valid_regEx)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("regEx"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("regEx")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing regEx element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sregEx>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sregEx>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_6 = _Claim->property_regEx;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://core.user.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://core.user.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://core.user.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_Claim->is_valid_required)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("required"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("required")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing required element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%srequired>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%srequired>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_7, (_Claim->property_required)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_7, axutil_strlen(text_value_7));
                           
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
                      

                   if (!_Claim->is_valid_supportedByDefault)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("supportedByDefault"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("supportedByDefault")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing supportedByDefault element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%ssupportedByDefault>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%ssupportedByDefault>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_8, (_Claim->property_supportedByDefault)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_8, axutil_strlen(text_value_8));
                           
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
                      

                   if (!_Claim->is_valid_value)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("value"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("value")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing value element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%svalue>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%svalue>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_9 = _Claim->property_value;
                           
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
             * Getter for claimUri by  Property Number 1
             */
            axis2_char_t* AXIS2_CALL
            adb_Claim_get_property1(
                adb_Claim_t* _Claim,
                const axutil_env_t *env)
            {
                return adb_Claim_get_claimUri(_Claim,
                                             env);
            }

            /**
             * getter for claimUri.
             */
            axis2_char_t* AXIS2_CALL
            adb_Claim_get_claimUri(
                    adb_Claim_t* _Claim,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _Claim, NULL);
                  

                return _Claim->property_claimUri;
             }

            /**
             * setter for claimUri
             */
            axis2_status_t AXIS2_CALL
            adb_Claim_set_claimUri(
                    adb_Claim_t* _Claim,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_claimUri)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _Claim, AXIS2_FAILURE);
                
                if(_Claim->is_valid_claimUri &&
                        arg_claimUri == _Claim->property_claimUri)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_Claim_reset_claimUri(_Claim, env);

                
                if(NULL == arg_claimUri)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _Claim->property_claimUri = (axis2_char_t *)axutil_strdup(env, arg_claimUri);
                        if(NULL == _Claim->property_claimUri)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for claimUri");
                            return AXIS2_FAILURE;
                        }
                        _Claim->is_valid_claimUri = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for claimUri
            */
           axis2_status_t AXIS2_CALL
           adb_Claim_reset_claimUri(
                   adb_Claim_t* _Claim,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _Claim, AXIS2_FAILURE);
               

               
            
                
                if(_Claim->property_claimUri != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _Claim->property_claimUri);
                     _Claim->property_claimUri = NULL;
                }
            
                
                
                _Claim->is_valid_claimUri = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether claimUri is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_Claim_is_claimUri_nil(
                   adb_Claim_t* _Claim,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _Claim, AXIS2_TRUE);
               
               return !_Claim->is_valid_claimUri;
           }

           /**
            * Set claimUri to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_Claim_set_claimUri_nil(
                   adb_Claim_t* _Claim,
                   const axutil_env_t *env)
           {
               return adb_Claim_reset_claimUri(_Claim, env);
           }

           

            /**
             * Getter for description by  Property Number 2
             */
            axis2_char_t* AXIS2_CALL
            adb_Claim_get_property2(
                adb_Claim_t* _Claim,
                const axutil_env_t *env)
            {
                return adb_Claim_get_description(_Claim,
                                             env);
            }

            /**
             * getter for description.
             */
            axis2_char_t* AXIS2_CALL
            adb_Claim_get_description(
                    adb_Claim_t* _Claim,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _Claim, NULL);
                  

                return _Claim->property_description;
             }

            /**
             * setter for description
             */
            axis2_status_t AXIS2_CALL
            adb_Claim_set_description(
                    adb_Claim_t* _Claim,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_description)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _Claim, AXIS2_FAILURE);
                
                if(_Claim->is_valid_description &&
                        arg_description == _Claim->property_description)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_Claim_reset_description(_Claim, env);

                
                if(NULL == arg_description)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _Claim->property_description = (axis2_char_t *)axutil_strdup(env, arg_description);
                        if(NULL == _Claim->property_description)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for description");
                            return AXIS2_FAILURE;
                        }
                        _Claim->is_valid_description = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for description
            */
           axis2_status_t AXIS2_CALL
           adb_Claim_reset_description(
                   adb_Claim_t* _Claim,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _Claim, AXIS2_FAILURE);
               

               
            
                
                if(_Claim->property_description != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _Claim->property_description);
                     _Claim->property_description = NULL;
                }
            
                
                
                _Claim->is_valid_description = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether description is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_Claim_is_description_nil(
                   adb_Claim_t* _Claim,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _Claim, AXIS2_TRUE);
               
               return !_Claim->is_valid_description;
           }

           /**
            * Set description to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_Claim_set_description_nil(
                   adb_Claim_t* _Claim,
                   const axutil_env_t *env)
           {
               return adb_Claim_reset_description(_Claim, env);
           }

           

            /**
             * Getter for dialectURI by  Property Number 3
             */
            axis2_char_t* AXIS2_CALL
            adb_Claim_get_property3(
                adb_Claim_t* _Claim,
                const axutil_env_t *env)
            {
                return adb_Claim_get_dialectURI(_Claim,
                                             env);
            }

            /**
             * getter for dialectURI.
             */
            axis2_char_t* AXIS2_CALL
            adb_Claim_get_dialectURI(
                    adb_Claim_t* _Claim,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _Claim, NULL);
                  

                return _Claim->property_dialectURI;
             }

            /**
             * setter for dialectURI
             */
            axis2_status_t AXIS2_CALL
            adb_Claim_set_dialectURI(
                    adb_Claim_t* _Claim,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_dialectURI)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _Claim, AXIS2_FAILURE);
                
                if(_Claim->is_valid_dialectURI &&
                        arg_dialectURI == _Claim->property_dialectURI)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_Claim_reset_dialectURI(_Claim, env);

                
                if(NULL == arg_dialectURI)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _Claim->property_dialectURI = (axis2_char_t *)axutil_strdup(env, arg_dialectURI);
                        if(NULL == _Claim->property_dialectURI)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for dialectURI");
                            return AXIS2_FAILURE;
                        }
                        _Claim->is_valid_dialectURI = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for dialectURI
            */
           axis2_status_t AXIS2_CALL
           adb_Claim_reset_dialectURI(
                   adb_Claim_t* _Claim,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _Claim, AXIS2_FAILURE);
               

               
            
                
                if(_Claim->property_dialectURI != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _Claim->property_dialectURI);
                     _Claim->property_dialectURI = NULL;
                }
            
                
                
                _Claim->is_valid_dialectURI = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether dialectURI is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_Claim_is_dialectURI_nil(
                   adb_Claim_t* _Claim,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _Claim, AXIS2_TRUE);
               
               return !_Claim->is_valid_dialectURI;
           }

           /**
            * Set dialectURI to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_Claim_set_dialectURI_nil(
                   adb_Claim_t* _Claim,
                   const axutil_env_t *env)
           {
               return adb_Claim_reset_dialectURI(_Claim, env);
           }

           

            /**
             * Getter for displayOrder by  Property Number 4
             */
            int AXIS2_CALL
            adb_Claim_get_property4(
                adb_Claim_t* _Claim,
                const axutil_env_t *env)
            {
                return adb_Claim_get_displayOrder(_Claim,
                                             env);
            }

            /**
             * getter for displayOrder.
             */
            int AXIS2_CALL
            adb_Claim_get_displayOrder(
                    adb_Claim_t* _Claim,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (int)0);
                    AXIS2_PARAM_CHECK(env->error, _Claim, (int)0);
                  

                return _Claim->property_displayOrder;
             }

            /**
             * setter for displayOrder
             */
            axis2_status_t AXIS2_CALL
            adb_Claim_set_displayOrder(
                    adb_Claim_t* _Claim,
                    const axutil_env_t *env,
                    const int  arg_displayOrder)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _Claim, AXIS2_FAILURE);
                
                if(_Claim->is_valid_displayOrder &&
                        arg_displayOrder == _Claim->property_displayOrder)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_Claim_reset_displayOrder(_Claim, env);

                _Claim->property_displayOrder = arg_displayOrder;
                        _Claim->is_valid_displayOrder = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for displayOrder
            */
           axis2_status_t AXIS2_CALL
           adb_Claim_reset_displayOrder(
                   adb_Claim_t* _Claim,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _Claim, AXIS2_FAILURE);
               

               _Claim->is_valid_displayOrder = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether displayOrder is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_Claim_is_displayOrder_nil(
                   adb_Claim_t* _Claim,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _Claim, AXIS2_TRUE);
               
               return !_Claim->is_valid_displayOrder;
           }

           /**
            * Set displayOrder to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_Claim_set_displayOrder_nil(
                   adb_Claim_t* _Claim,
                   const axutil_env_t *env)
           {
               return adb_Claim_reset_displayOrder(_Claim, env);
           }

           

            /**
             * Getter for displayTag by  Property Number 5
             */
            axis2_char_t* AXIS2_CALL
            adb_Claim_get_property5(
                adb_Claim_t* _Claim,
                const axutil_env_t *env)
            {
                return adb_Claim_get_displayTag(_Claim,
                                             env);
            }

            /**
             * getter for displayTag.
             */
            axis2_char_t* AXIS2_CALL
            adb_Claim_get_displayTag(
                    adb_Claim_t* _Claim,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _Claim, NULL);
                  

                return _Claim->property_displayTag;
             }

            /**
             * setter for displayTag
             */
            axis2_status_t AXIS2_CALL
            adb_Claim_set_displayTag(
                    adb_Claim_t* _Claim,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_displayTag)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _Claim, AXIS2_FAILURE);
                
                if(_Claim->is_valid_displayTag &&
                        arg_displayTag == _Claim->property_displayTag)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_Claim_reset_displayTag(_Claim, env);

                
                if(NULL == arg_displayTag)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _Claim->property_displayTag = (axis2_char_t *)axutil_strdup(env, arg_displayTag);
                        if(NULL == _Claim->property_displayTag)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for displayTag");
                            return AXIS2_FAILURE;
                        }
                        _Claim->is_valid_displayTag = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for displayTag
            */
           axis2_status_t AXIS2_CALL
           adb_Claim_reset_displayTag(
                   adb_Claim_t* _Claim,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _Claim, AXIS2_FAILURE);
               

               
            
                
                if(_Claim->property_displayTag != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _Claim->property_displayTag);
                     _Claim->property_displayTag = NULL;
                }
            
                
                
                _Claim->is_valid_displayTag = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether displayTag is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_Claim_is_displayTag_nil(
                   adb_Claim_t* _Claim,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _Claim, AXIS2_TRUE);
               
               return !_Claim->is_valid_displayTag;
           }

           /**
            * Set displayTag to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_Claim_set_displayTag_nil(
                   adb_Claim_t* _Claim,
                   const axutil_env_t *env)
           {
               return adb_Claim_reset_displayTag(_Claim, env);
           }

           

            /**
             * Getter for regEx by  Property Number 6
             */
            axis2_char_t* AXIS2_CALL
            adb_Claim_get_property6(
                adb_Claim_t* _Claim,
                const axutil_env_t *env)
            {
                return adb_Claim_get_regEx(_Claim,
                                             env);
            }

            /**
             * getter for regEx.
             */
            axis2_char_t* AXIS2_CALL
            adb_Claim_get_regEx(
                    adb_Claim_t* _Claim,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _Claim, NULL);
                  

                return _Claim->property_regEx;
             }

            /**
             * setter for regEx
             */
            axis2_status_t AXIS2_CALL
            adb_Claim_set_regEx(
                    adb_Claim_t* _Claim,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_regEx)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _Claim, AXIS2_FAILURE);
                
                if(_Claim->is_valid_regEx &&
                        arg_regEx == _Claim->property_regEx)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_Claim_reset_regEx(_Claim, env);

                
                if(NULL == arg_regEx)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _Claim->property_regEx = (axis2_char_t *)axutil_strdup(env, arg_regEx);
                        if(NULL == _Claim->property_regEx)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for regEx");
                            return AXIS2_FAILURE;
                        }
                        _Claim->is_valid_regEx = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for regEx
            */
           axis2_status_t AXIS2_CALL
           adb_Claim_reset_regEx(
                   adb_Claim_t* _Claim,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _Claim, AXIS2_FAILURE);
               

               
            
                
                if(_Claim->property_regEx != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _Claim->property_regEx);
                     _Claim->property_regEx = NULL;
                }
            
                
                
                _Claim->is_valid_regEx = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether regEx is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_Claim_is_regEx_nil(
                   adb_Claim_t* _Claim,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _Claim, AXIS2_TRUE);
               
               return !_Claim->is_valid_regEx;
           }

           /**
            * Set regEx to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_Claim_set_regEx_nil(
                   adb_Claim_t* _Claim,
                   const axutil_env_t *env)
           {
               return adb_Claim_reset_regEx(_Claim, env);
           }

           

            /**
             * Getter for required by  Property Number 7
             */
            axis2_bool_t AXIS2_CALL
            adb_Claim_get_property7(
                adb_Claim_t* _Claim,
                const axutil_env_t *env)
            {
                return adb_Claim_get_required(_Claim,
                                             env);
            }

            /**
             * getter for required.
             */
            axis2_bool_t AXIS2_CALL
            adb_Claim_get_required(
                    adb_Claim_t* _Claim,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _Claim, (axis2_bool_t)0);
                  

                return _Claim->property_required;
             }

            /**
             * setter for required
             */
            axis2_status_t AXIS2_CALL
            adb_Claim_set_required(
                    adb_Claim_t* _Claim,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_required)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _Claim, AXIS2_FAILURE);
                
                if(_Claim->is_valid_required &&
                        arg_required == _Claim->property_required)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_Claim_reset_required(_Claim, env);

                _Claim->property_required = arg_required;
                        _Claim->is_valid_required = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for required
            */
           axis2_status_t AXIS2_CALL
           adb_Claim_reset_required(
                   adb_Claim_t* _Claim,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _Claim, AXIS2_FAILURE);
               

               _Claim->is_valid_required = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether required is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_Claim_is_required_nil(
                   adb_Claim_t* _Claim,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _Claim, AXIS2_TRUE);
               
               return !_Claim->is_valid_required;
           }

           /**
            * Set required to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_Claim_set_required_nil(
                   adb_Claim_t* _Claim,
                   const axutil_env_t *env)
           {
               return adb_Claim_reset_required(_Claim, env);
           }

           

            /**
             * Getter for supportedByDefault by  Property Number 8
             */
            axis2_bool_t AXIS2_CALL
            adb_Claim_get_property8(
                adb_Claim_t* _Claim,
                const axutil_env_t *env)
            {
                return adb_Claim_get_supportedByDefault(_Claim,
                                             env);
            }

            /**
             * getter for supportedByDefault.
             */
            axis2_bool_t AXIS2_CALL
            adb_Claim_get_supportedByDefault(
                    adb_Claim_t* _Claim,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _Claim, (axis2_bool_t)0);
                  

                return _Claim->property_supportedByDefault;
             }

            /**
             * setter for supportedByDefault
             */
            axis2_status_t AXIS2_CALL
            adb_Claim_set_supportedByDefault(
                    adb_Claim_t* _Claim,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_supportedByDefault)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _Claim, AXIS2_FAILURE);
                
                if(_Claim->is_valid_supportedByDefault &&
                        arg_supportedByDefault == _Claim->property_supportedByDefault)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_Claim_reset_supportedByDefault(_Claim, env);

                _Claim->property_supportedByDefault = arg_supportedByDefault;
                        _Claim->is_valid_supportedByDefault = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for supportedByDefault
            */
           axis2_status_t AXIS2_CALL
           adb_Claim_reset_supportedByDefault(
                   adb_Claim_t* _Claim,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _Claim, AXIS2_FAILURE);
               

               _Claim->is_valid_supportedByDefault = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether supportedByDefault is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_Claim_is_supportedByDefault_nil(
                   adb_Claim_t* _Claim,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _Claim, AXIS2_TRUE);
               
               return !_Claim->is_valid_supportedByDefault;
           }

           /**
            * Set supportedByDefault to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_Claim_set_supportedByDefault_nil(
                   adb_Claim_t* _Claim,
                   const axutil_env_t *env)
           {
               return adb_Claim_reset_supportedByDefault(_Claim, env);
           }

           

            /**
             * Getter for value by  Property Number 9
             */
            axis2_char_t* AXIS2_CALL
            adb_Claim_get_property9(
                adb_Claim_t* _Claim,
                const axutil_env_t *env)
            {
                return adb_Claim_get_value(_Claim,
                                             env);
            }

            /**
             * getter for value.
             */
            axis2_char_t* AXIS2_CALL
            adb_Claim_get_value(
                    adb_Claim_t* _Claim,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _Claim, NULL);
                  

                return _Claim->property_value;
             }

            /**
             * setter for value
             */
            axis2_status_t AXIS2_CALL
            adb_Claim_set_value(
                    adb_Claim_t* _Claim,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_value)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _Claim, AXIS2_FAILURE);
                
                if(_Claim->is_valid_value &&
                        arg_value == _Claim->property_value)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_Claim_reset_value(_Claim, env);

                
                if(NULL == arg_value)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _Claim->property_value = (axis2_char_t *)axutil_strdup(env, arg_value);
                        if(NULL == _Claim->property_value)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for value");
                            return AXIS2_FAILURE;
                        }
                        _Claim->is_valid_value = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for value
            */
           axis2_status_t AXIS2_CALL
           adb_Claim_reset_value(
                   adb_Claim_t* _Claim,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _Claim, AXIS2_FAILURE);
               

               
            
                
                if(_Claim->property_value != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _Claim->property_value);
                     _Claim->property_value = NULL;
                }
            
                
                
                _Claim->is_valid_value = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether value is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_Claim_is_value_nil(
                   adb_Claim_t* _Claim,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _Claim, AXIS2_TRUE);
               
               return !_Claim->is_valid_value;
           }

           /**
            * Set value to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_Claim_set_value_nil(
                   adb_Claim_t* _Claim,
                   const axutil_env_t *env)
           {
               return adb_Claim_reset_value(_Claim, env);
           }

           

