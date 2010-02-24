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
         * adb_Policy.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

/*
 * =====================================================================================
 * NOTE : This WSDL is having schema inheritance. Due to that _type is generated twice
 * It is manually commented in this file
 * =====================================================================================
 */

        #include "codegen/adb_Policy.h"
        
                /*
                 * This type was generated from the piece of schema that had
                 * name = Policy
                 * Namespace URI = http://neethi.apache.org/xsd
                 * Namespace Prefix = ns1
                 */
           


        struct adb_Policy
        {
            axis2_char_t *property_Type;

            axis2_bool_t property_empty;

                
                axis2_bool_t is_valid_empty;
            adb_PolicyComponent_t* property_firstPolicyComponent;

                
                axis2_bool_t is_valid_firstPolicyComponent;
            axiom_node_t* property_policyComponents;

                
                axis2_bool_t is_valid_policyComponents;
            axiom_node_t* property_assertions;

                
                axis2_bool_t is_valid_assertions;
           /* short property_type; */

                
            /*    axis2_bool_t is_valid_type; */
            adb_Iterator_t* property_alternatives;

                
                axis2_bool_t is_valid_alternatives;
            adb_Map_t* property_attributes;

                
                axis2_bool_t is_valid_attributes;
            axis2_char_t* property_id;

                
                axis2_bool_t is_valid_id;
            axis2_char_t* property_name;

                
                axis2_bool_t is_valid_name;
            short property_type;

                
                axis2_bool_t is_valid_type;
            
        };


       /************************* Private Function prototypes ********************************/
        

                axis2_status_t AXIS2_CALL
                adb_Policy_set_empty_nil(
                        adb_Policy_t* _Policy,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_Policy_set_type_nil(
                        adb_Policy_t* _Policy,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_Policy_set_type_nil(
                        adb_Policy_t* _Policy,
                        const axutil_env_t *env);
            


       /************************* Function Implmentations ********************************/
        adb_Policy_t* AXIS2_CALL
        adb_Policy_create(
            const axutil_env_t *env)
        {
            adb_Policy_t *_Policy = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _Policy = (adb_Policy_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_Policy_t));

            if(NULL == _Policy)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_Policy, 0, sizeof(adb_Policy_t));

            _Policy->property_Type = axutil_strdup(env, "adb_Policy");
            _Policy->is_valid_empty  = AXIS2_FALSE;
            _Policy->property_firstPolicyComponent  = NULL;
                  _Policy->is_valid_firstPolicyComponent  = AXIS2_FALSE;
            _Policy->is_valid_policyComponents  = AXIS2_FALSE;
            _Policy->is_valid_assertions  = AXIS2_FALSE;
            _Policy->is_valid_type  = AXIS2_FALSE;
            _Policy->property_alternatives  = NULL;
                  _Policy->is_valid_alternatives  = AXIS2_FALSE;
            _Policy->property_attributes  = NULL;
                  _Policy->is_valid_attributes  = AXIS2_FALSE;
            _Policy->property_id  = NULL;
                  _Policy->is_valid_id  = AXIS2_FALSE;
            _Policy->property_name  = NULL;
                  _Policy->is_valid_name  = AXIS2_FALSE;
            _Policy->is_valid_type  = AXIS2_FALSE;
            

            return _Policy;
        }

        adb_Policy_t* AXIS2_CALL
        adb_Policy_create_with_values(
            const axutil_env_t *env,
                axis2_bool_t _empty,
                adb_PolicyComponent_t* _firstPolicyComponent,
                axiom_node_t* _policyComponents,
                axiom_node_t* _assertions,
                adb_Iterator_t* _alternatives,
                adb_Map_t* _attributes,
                axis2_char_t* _id,
                axis2_char_t* _name,
                short _type)
        {
            adb_Policy_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_Policy_create(env);

            
              status = adb_Policy_set_empty(
                                     adb_obj,
                                     env,
                                     _empty);
              if(status == AXIS2_FAILURE) {
                  adb_Policy_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_Policy_set_firstPolicyComponent(
                                     adb_obj,
                                     env,
                                     _firstPolicyComponent);
              if(status == AXIS2_FAILURE) {
                  adb_Policy_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_Policy_set_policyComponents(
                                     adb_obj,
                                     env,
                                     _policyComponents);
              if(status == AXIS2_FAILURE) {
                  adb_Policy_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_Policy_set_assertions(
                                     adb_obj,
                                     env,
                                     _assertions);
              if(status == AXIS2_FAILURE) {
                  adb_Policy_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_Policy_set_type(
                                     adb_obj,
                                     env,
                                     _type);
              if(status == AXIS2_FAILURE) {
                  adb_Policy_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_Policy_set_alternatives(
                                     adb_obj,
                                     env,
                                     _alternatives);
              if(status == AXIS2_FAILURE) {
                  adb_Policy_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_Policy_set_attributes(
                                     adb_obj,
                                     env,
                                     _attributes);
              if(status == AXIS2_FAILURE) {
                  adb_Policy_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_Policy_set_id(
                                     adb_obj,
                                     env,
                                     _id);
              if(status == AXIS2_FAILURE) {
                  adb_Policy_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_Policy_set_name(
                                     adb_obj,
                                     env,
                                     _name);
              if(status == AXIS2_FAILURE) {
                  adb_Policy_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_Policy_set_type(
                                     adb_obj,
                                     env,
                                     _type);
              if(status == AXIS2_FAILURE) {
                  adb_Policy_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_bool_t AXIS2_CALL
                adb_Policy_free_popping_value(
                        adb_Policy_t* _Policy,
                        const axutil_env_t *env)
                {
                    axis2_bool_t value;

                    
                    
                    value = _Policy->property_empty;

                    adb_Policy_free(_Policy, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_Policy_free(
                adb_Policy_t* _Policy,
                const axutil_env_t *env)
        {
            
            
            return axis2_extension_mapper_free(
                (adb_type_t*) _Policy,
                env,
                "adb_Policy");
            
        }

        axis2_status_t AXIS2_CALL
        adb_Policy_free_obj(
                adb_Policy_t* _Policy,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _Policy, AXIS2_FAILURE);

            if (_Policy->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _Policy->property_Type);
            }

            adb_Policy_reset_empty(_Policy, env);
            adb_Policy_reset_firstPolicyComponent(_Policy, env);
            adb_Policy_reset_policyComponents(_Policy, env);
            adb_Policy_reset_assertions(_Policy, env);
            adb_Policy_reset_type(_Policy, env);
            adb_Policy_reset_alternatives(_Policy, env);
            adb_Policy_reset_attributes(_Policy, env);
            adb_Policy_reset_id(_Policy, env);
            adb_Policy_reset_name(_Policy, env);
            adb_Policy_reset_type(_Policy, env);
            

            if(_Policy)
            {
                AXIS2_FREE(env->allocator, _Policy);
                _Policy = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_Policy_deserialize(
                adb_Policy_t* _Policy,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return axis2_extension_mapper_deserialize(
                (adb_type_t*) _Policy,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs,
                "adb_Policy");
            
        }

        axis2_status_t AXIS2_CALL
        adb_Policy_deserialize_obj(
                adb_Policy_t* _Policy,
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
            AXIS2_PARAM_CHECK(env->error, _Policy, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for Policy : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              
                      
                      first_node = axiom_node_get_first_child(parent, env);
                      
                    

                     
                     /*
                      * building empty element
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
                                   
                                 element_qname = axutil_qname_create(env, "empty", "http://neethi.apache.org/xsd", NULL);
                                 

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
                                                status = adb_Policy_set_empty(_Policy, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_Policy_set_empty(_Policy, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element empty");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for empty ");
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
                      * building firstPolicyComponent element
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
                                 
                                 element_qname = axutil_qname_create(env, "firstPolicyComponent", "http://neethi.apache.org/xsd", NULL);
                                 

                           if (adb_PolicyComponent_is_particle() ||  
                                (current_node   && current_element && (axutil_qname_equals(element_qname, env, qname))))
                           {
                              if( current_node   && current_element && (axutil_qname_equals(element_qname, env, qname)))
                              {
                                is_early_node_valid = AXIS2_TRUE;
                              }
                              
                                 
                                      element = (void*)axis2_extension_mapper_create_from_node(env, &current_node, "adb_PolicyComponent");

                                      status =  adb_PolicyComponent_deserialize((adb_PolicyComponent_t*)element,
                                                                            env, &current_node, &is_early_node_valid, AXIS2_FALSE);
                                      if(AXIS2_FAILURE == status)
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building adb object for element firstPolicyComponent");
                                      }
                                      else
                                      {
                                          status = adb_Policy_set_firstPolicyComponent(_Policy, env,
                                                                   (adb_PolicyComponent_t*)element);
                                      }
                                    
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for firstPolicyComponent ");
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
                      * building policyComponents element
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
                                 
                                 element_qname = axutil_qname_create(env, "policyComponents", "http://neethi.apache.org/xsd", NULL);
                                 

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
                                              status = adb_Policy_set_policyComponents(_Policy, env,
                                                                          current_property_node);
                                          }
                                          else
                                          {
                                              status = adb_Policy_set_policyComponents(_Policy, env,
                                                                          NULL);
                                          }
                                        
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for policyComponents ");
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
                      * building assertions element
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
                                 
                                 element_qname = axutil_qname_create(env, "assertions", "http://neethi.apache.org/xsd", NULL);
                                 

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
                                              status = adb_Policy_set_assertions(_Policy, env,
                                                                          current_property_node);
                                          }
                                          else
                                          {
                                              status = adb_Policy_set_assertions(_Policy, env,
                                                                          NULL);
                                          }
                                        
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for assertions ");
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
                      * building type element
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
                                 
                                 element_qname = axutil_qname_create(env, "type", "http://neethi.apache.org/xsd", NULL);
                                 

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
                                            status = adb_Policy_set_type(_Policy, env,
                                                                   atoi(text_value));
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element type");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for type ");
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
                      * building alternatives element
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
                                 
                                 element_qname = axutil_qname_create(env, "alternatives", "http://neethi.apache.org/xsd", NULL);
                                 

                           if (adb_Iterator_is_particle() ||  
                                (current_node   && current_element && (axutil_qname_equals(element_qname, env, qname))))
                           {
                              if( current_node   && current_element && (axutil_qname_equals(element_qname, env, qname)))
                              {
                                is_early_node_valid = AXIS2_TRUE;
                              }
                              
                                 
                                      element = (void*)axis2_extension_mapper_create_from_node(env, &current_node, "adb_Iterator");

                                      status =  adb_Iterator_deserialize((adb_Iterator_t*)element,
                                                                            env, &current_node, &is_early_node_valid, AXIS2_FALSE);
                                      if(AXIS2_FAILURE == status)
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building adb object for element alternatives");
                                      }
                                      else
                                      {
                                          status = adb_Policy_set_alternatives(_Policy, env,
                                                                   (adb_Iterator_t*)element);
                                      }
                                    
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for alternatives ");
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
                      * building attributes element
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
                                 
                                 element_qname = axutil_qname_create(env, "attributes", "http://neethi.apache.org/xsd", NULL);
                                 

                           if (adb_Map_is_particle() ||  
                                (current_node   && current_element && (axutil_qname_equals(element_qname, env, qname))))
                           {
                              if( current_node   && current_element && (axutil_qname_equals(element_qname, env, qname)))
                              {
                                is_early_node_valid = AXIS2_TRUE;
                              }
                              
                                 
                                      element = (void*)axis2_extension_mapper_create_from_node(env, &current_node, "adb_Map");

                                      status =  adb_Map_deserialize((adb_Map_t*)element,
                                                                            env, &current_node, &is_early_node_valid, AXIS2_FALSE);
                                      if(AXIS2_FAILURE == status)
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building adb object for element attributes");
                                      }
                                      else
                                      {
                                          status = adb_Policy_set_attributes(_Policy, env,
                                                                   (adb_Map_t*)element);
                                      }
                                    
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for attributes ");
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
                      * building id element
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
                                 
                                 element_qname = axutil_qname_create(env, "id", "http://neethi.apache.org/xsd", NULL);
                                 

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
                                            status = adb_Policy_set_id(_Policy, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for id ");
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
                                 
                                 element_qname = axutil_qname_create(env, "name", "http://neethi.apache.org/xsd", NULL);
                                 

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
                                            status = adb_Policy_set_name(_Policy, env,
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
                      * building type element
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
                                 
                                 element_qname = axutil_qname_create(env, "type", "http://neethi.apache.org/xsd", NULL);
                                 

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
                                            status = adb_Policy_set_type(_Policy, env,
                                                                   atoi(text_value));
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element type");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for type ");
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
          adb_Policy_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_Policy_declare_parent_namespaces(
                    adb_Policy_t* _Policy,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_Policy_serialize(
                adb_Policy_t* _Policy,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
            if (_Policy == NULL)
            {
                return adb_Policy_serialize_obj(
                    _Policy, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            }
            else
            {
                return axis2_extension_mapper_serialize(
                    (adb_type_t*) _Policy, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index, "adb_Policy");
            }
            
        }

        axiom_node_t* AXIS2_CALL
        adb_Policy_serialize_obj(
                adb_Policy_t* _Policy,
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
                    
                    axis2_char_t *text_value_4;
                    axis2_char_t *text_value_4_temp;
                    
                    axis2_char_t text_value_5[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t text_value_6[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t text_value_7[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t *text_value_8;
                    axis2_char_t *text_value_8_temp;
                    
                    axis2_char_t *text_value_9;
                    axis2_char_t *text_value_9_temp;
                    
                    axis2_char_t text_value_10[ADB_DEFAULT_DIGIT_LIMIT];
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _Policy, NULL);
            
            
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
              type_attrib = axutil_strcat(env, xsi_prefix, ":type=\"Policy\"", NULL);
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
                                 "http://neethi.apache.org/xsd",
                                 xsi_prefix);
            xsi_type_attri = axiom_attribute_create (env, "type", "Policy", xsi_ns);
            
            axiom_element_add_attribute (parent_element, env, xsi_type_attri, parent);
        
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://neethi.apache.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://neethi.apache.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://neethi.apache.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_Policy->is_valid_empty)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("empty"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("empty")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing empty element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sempty>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sempty>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_1, (_Policy->property_empty)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_1, axutil_strlen(text_value_1));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://neethi.apache.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://neethi.apache.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://neethi.apache.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_Policy->is_valid_firstPolicyComponent)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("firstPolicyComponent"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("firstPolicyComponent")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing firstPolicyComponent element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sfirstPolicyComponent",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sfirstPolicyComponent>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                     
                            if(!adb_PolicyComponent_is_particle())
                            {
                                axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                            }
                            adb_PolicyComponent_serialize(_Policy->property_firstPolicyComponent, 
                                                                                 env, current_node, parent_element,
                                                                                 adb_PolicyComponent_is_particle() || AXIS2_FALSE, namespaces, next_ns_index);
                            
                            if(!adb_PolicyComponent_is_particle())
                            {
                                axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                            }
                            
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://neethi.apache.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://neethi.apache.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://neethi.apache.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_Policy->is_valid_policyComponents)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("policyComponents"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("policyComponents")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing policyComponents element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%spolicyComponents>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%spolicyComponents>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                                text_value_3 = axiom_node_to_string(_Policy->property_policyComponents, env);
                                
                                axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                                
                                axutil_stream_write(stream, env, text_value_3, axutil_strlen(text_value_3));
                                
                                axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                                
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://neethi.apache.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://neethi.apache.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://neethi.apache.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_Policy->is_valid_assertions)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("assertions"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("assertions")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing assertions element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sassertions>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sassertions>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                                text_value_4 = axiom_node_to_string(_Policy->property_assertions, env);
                                
                                axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                                
                                axutil_stream_write(stream, env, text_value_4, axutil_strlen(text_value_4));
                                
                                axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                                
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://neethi.apache.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://neethi.apache.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://neethi.apache.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_Policy->is_valid_type)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("type"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("type")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing type element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%stype>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%stype>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                               sprintf (text_value_5, "%d", _Policy->property_type);
                             
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_5, axutil_strlen(text_value_5));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://neethi.apache.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://neethi.apache.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://neethi.apache.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_Policy->is_valid_alternatives)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("alternatives"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("alternatives")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing alternatives element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%salternatives",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%salternatives>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                     
                            if(!adb_Iterator_is_particle())
                            {
                                axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                            }
                            adb_Iterator_serialize(_Policy->property_alternatives, 
                                                                                 env, current_node, parent_element,
                                                                                 adb_Iterator_is_particle() || AXIS2_FALSE, namespaces, next_ns_index);
                            
                            if(!adb_Iterator_is_particle())
                            {
                                axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                            }
                            
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://neethi.apache.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://neethi.apache.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://neethi.apache.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_Policy->is_valid_attributes)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("attributes"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("attributes")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing attributes element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sattributes",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sattributes>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                     
                            if(!adb_Map_is_particle())
                            {
                                axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                            }
                            adb_Map_serialize(_Policy->property_attributes, 
                                                                                 env, current_node, parent_element,
                                                                                 adb_Map_is_particle() || AXIS2_FALSE, namespaces, next_ns_index);
                            
                            if(!adb_Map_is_particle())
                            {
                                axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                            }
                            
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://neethi.apache.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://neethi.apache.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://neethi.apache.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_Policy->is_valid_id)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("id"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("id")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing id element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sid>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sid>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_8 = _Policy->property_id;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://neethi.apache.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://neethi.apache.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://neethi.apache.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_Policy->is_valid_name)
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
                    
                           text_value_9 = _Policy->property_name;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://neethi.apache.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://neethi.apache.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://neethi.apache.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_Policy->is_valid_type)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("type"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("type")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing type element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%stype>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%stype>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                               sprintf (text_value_10, "%d", _Policy->property_type);
                             
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_10, axutil_strlen(text_value_10));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 

            return parent;
        }


        

            /**
             * Getter for empty by  Property Number 1
             */
            axis2_bool_t AXIS2_CALL
            adb_Policy_get_property1(
                adb_Policy_t* _Policy,
                const axutil_env_t *env)
            {
                return adb_Policy_get_empty(_Policy,
                                             env);
            }

            /**
             * getter for empty.
             */
            axis2_bool_t AXIS2_CALL
            adb_Policy_get_empty(
                    adb_Policy_t* _Policy,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _Policy, (axis2_bool_t)0);
                  

                return _Policy->property_empty;
             }

            /**
             * setter for empty
             */
            axis2_status_t AXIS2_CALL
            adb_Policy_set_empty(
                    adb_Policy_t* _Policy,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_empty)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _Policy, AXIS2_FAILURE);
                
                if(_Policy->is_valid_empty &&
                        arg_empty == _Policy->property_empty)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_Policy_reset_empty(_Policy, env);

                _Policy->property_empty = arg_empty;
                        _Policy->is_valid_empty = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for empty
            */
           axis2_status_t AXIS2_CALL
           adb_Policy_reset_empty(
                   adb_Policy_t* _Policy,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _Policy, AXIS2_FAILURE);
               

               _Policy->is_valid_empty = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether empty is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_Policy_is_empty_nil(
                   adb_Policy_t* _Policy,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _Policy, AXIS2_TRUE);
               
               return !_Policy->is_valid_empty;
           }

           /**
            * Set empty to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_Policy_set_empty_nil(
                   adb_Policy_t* _Policy,
                   const axutil_env_t *env)
           {
               return adb_Policy_reset_empty(_Policy, env);
           }

           

            /**
             * Getter for firstPolicyComponent by  Property Number 2
             */
            adb_PolicyComponent_t* AXIS2_CALL
            adb_Policy_get_property2(
                adb_Policy_t* _Policy,
                const axutil_env_t *env)
            {
                return adb_Policy_get_firstPolicyComponent(_Policy,
                                             env);
            }

            /**
             * getter for firstPolicyComponent.
             */
            adb_PolicyComponent_t* AXIS2_CALL
            adb_Policy_get_firstPolicyComponent(
                    adb_Policy_t* _Policy,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _Policy, NULL);
                  

                return _Policy->property_firstPolicyComponent;
             }

            /**
             * setter for firstPolicyComponent
             */
            axis2_status_t AXIS2_CALL
            adb_Policy_set_firstPolicyComponent(
                    adb_Policy_t* _Policy,
                    const axutil_env_t *env,
                    adb_PolicyComponent_t*  arg_firstPolicyComponent)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _Policy, AXIS2_FAILURE);
                
                if(_Policy->is_valid_firstPolicyComponent &&
                        arg_firstPolicyComponent == _Policy->property_firstPolicyComponent)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_Policy_reset_firstPolicyComponent(_Policy, env);

                
                if(NULL == arg_firstPolicyComponent)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _Policy->property_firstPolicyComponent = arg_firstPolicyComponent;
                        _Policy->is_valid_firstPolicyComponent = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for firstPolicyComponent
            */
           axis2_status_t AXIS2_CALL
           adb_Policy_reset_firstPolicyComponent(
                   adb_Policy_t* _Policy,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _Policy, AXIS2_FAILURE);
               

               
            
                
                if(_Policy->property_firstPolicyComponent != NULL)
                {
                   
                   adb_PolicyComponent_free(_Policy->property_firstPolicyComponent, env);
                     _Policy->property_firstPolicyComponent = NULL;
                }
            
                
                
                _Policy->is_valid_firstPolicyComponent = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether firstPolicyComponent is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_Policy_is_firstPolicyComponent_nil(
                   adb_Policy_t* _Policy,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _Policy, AXIS2_TRUE);
               
               return !_Policy->is_valid_firstPolicyComponent;
           }

           /**
            * Set firstPolicyComponent to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_Policy_set_firstPolicyComponent_nil(
                   adb_Policy_t* _Policy,
                   const axutil_env_t *env)
           {
               return adb_Policy_reset_firstPolicyComponent(_Policy, env);
           }

           

            /**
             * Getter for policyComponents by  Property Number 3
             */
            axiom_node_t* AXIS2_CALL
            adb_Policy_get_property3(
                adb_Policy_t* _Policy,
                const axutil_env_t *env)
            {
                return adb_Policy_get_policyComponents(_Policy,
                                             env);
            }

            /**
             * getter for policyComponents.
             */
            axiom_node_t* AXIS2_CALL
            adb_Policy_get_policyComponents(
                    adb_Policy_t* _Policy,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _Policy, NULL);
                  

                return _Policy->property_policyComponents;
             }

            /**
             * setter for policyComponents
             */
            axis2_status_t AXIS2_CALL
            adb_Policy_set_policyComponents(
                    adb_Policy_t* _Policy,
                    const axutil_env_t *env,
                    axiom_node_t*  arg_policyComponents)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _Policy, AXIS2_FAILURE);
                
                if(_Policy->is_valid_policyComponents &&
                        arg_policyComponents == _Policy->property_policyComponents)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_Policy_reset_policyComponents(_Policy, env);

                
                if(NULL == arg_policyComponents)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _Policy->property_policyComponents = arg_policyComponents;
                        _Policy->is_valid_policyComponents = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for policyComponents
            */
           axis2_status_t AXIS2_CALL
           adb_Policy_reset_policyComponents(
                   adb_Policy_t* _Policy,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _Policy, AXIS2_FAILURE);
               

               _Policy->is_valid_policyComponents = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether policyComponents is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_Policy_is_policyComponents_nil(
                   adb_Policy_t* _Policy,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _Policy, AXIS2_TRUE);
               
               return !_Policy->is_valid_policyComponents;
           }

           /**
            * Set policyComponents to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_Policy_set_policyComponents_nil(
                   adb_Policy_t* _Policy,
                   const axutil_env_t *env)
           {
               return adb_Policy_reset_policyComponents(_Policy, env);
           }

           

            /**
             * Getter for assertions by  Property Number 4
             */
            axiom_node_t* AXIS2_CALL
            adb_Policy_get_property4(
                adb_Policy_t* _Policy,
                const axutil_env_t *env)
            {
                return adb_Policy_get_assertions(_Policy,
                                             env);
            }

            /**
             * getter for assertions.
             */
            axiom_node_t* AXIS2_CALL
            adb_Policy_get_assertions(
                    adb_Policy_t* _Policy,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _Policy, NULL);
                  

                return _Policy->property_assertions;
             }

            /**
             * setter for assertions
             */
            axis2_status_t AXIS2_CALL
            adb_Policy_set_assertions(
                    adb_Policy_t* _Policy,
                    const axutil_env_t *env,
                    axiom_node_t*  arg_assertions)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _Policy, AXIS2_FAILURE);
                
                if(_Policy->is_valid_assertions &&
                        arg_assertions == _Policy->property_assertions)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_Policy_reset_assertions(_Policy, env);

                
                if(NULL == arg_assertions)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _Policy->property_assertions = arg_assertions;
                        _Policy->is_valid_assertions = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for assertions
            */
           axis2_status_t AXIS2_CALL
           adb_Policy_reset_assertions(
                   adb_Policy_t* _Policy,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _Policy, AXIS2_FAILURE);
               

               _Policy->is_valid_assertions = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether assertions is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_Policy_is_assertions_nil(
                   adb_Policy_t* _Policy,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _Policy, AXIS2_TRUE);
               
               return !_Policy->is_valid_assertions;
           }

           /**
            * Set assertions to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_Policy_set_assertions_nil(
                   adb_Policy_t* _Policy,
                   const axutil_env_t *env)
           {
               return adb_Policy_reset_assertions(_Policy, env);
           }

           

            /**
             * Getter for type by  Property Number 5
             */
            short AXIS2_CALL
            adb_Policy_get_property5(
                adb_Policy_t* _Policy,
                const axutil_env_t *env)
            {
                return adb_Policy_get_type(_Policy,
                                             env);
            }

            /**
             * getter for type.
             
            short AXIS2_CALL
            adb_Policy_get_type(
                    adb_Policy_t* _Policy,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (short)0);
                    AXIS2_PARAM_CHECK(env->error, _Policy, (short)0);
                  

                return _Policy->property_type;
             }
			 */

            /**
             * setter for type
            
            axis2_status_t AXIS2_CALL
            adb_Policy_set_type(
                    adb_Policy_t* _Policy,
                    const axutil_env_t *env,
                    const short  arg_type)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _Policy, AXIS2_FAILURE);
                
                if(_Policy->is_valid_type &&
                        arg_type == _Policy->property_type)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_Policy_reset_type(_Policy, env);

                _Policy->property_type = arg_type;
                        _Policy->is_valid_type = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }
			*/
             

           /**
            * resetter for type
           
           axis2_status_t AXIS2_CALL
           adb_Policy_reset_type(
                   adb_Policy_t* _Policy,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _Policy, AXIS2_FAILURE);
               

               _Policy->is_valid_type = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }
			 */
           /**
            * Check whether type is nill
          
           axis2_bool_t AXIS2_CALL
           adb_Policy_is_type_nil(
                   adb_Policy_t* _Policy,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _Policy, AXIS2_TRUE);
               
               return !_Policy->is_valid_type;
           }
			  */
           /**
            * Set type to nill (currently the same as reset)
           
           axis2_status_t AXIS2_CALL
           adb_Policy_set_type_nil(
                   adb_Policy_t* _Policy,
                   const axutil_env_t *env)
           {
               return adb_Policy_reset_type(_Policy, env);
           }
			*/
           

            /**
             * Getter for alternatives by  Property Number 6
             */
            adb_Iterator_t* AXIS2_CALL
            adb_Policy_get_property6(
                adb_Policy_t* _Policy,
                const axutil_env_t *env)
            {
                return adb_Policy_get_alternatives(_Policy,
                                             env);
            }

            /**
             * getter for alternatives.
             */
            adb_Iterator_t* AXIS2_CALL
            adb_Policy_get_alternatives(
                    adb_Policy_t* _Policy,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _Policy, NULL);
                  

                return _Policy->property_alternatives;
             }

            /**
             * setter for alternatives
             */
            axis2_status_t AXIS2_CALL
            adb_Policy_set_alternatives(
                    adb_Policy_t* _Policy,
                    const axutil_env_t *env,
                    adb_Iterator_t*  arg_alternatives)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _Policy, AXIS2_FAILURE);
                
                if(_Policy->is_valid_alternatives &&
                        arg_alternatives == _Policy->property_alternatives)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_Policy_reset_alternatives(_Policy, env);

                
                if(NULL == arg_alternatives)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _Policy->property_alternatives = arg_alternatives;
                        _Policy->is_valid_alternatives = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for alternatives
            */
           axis2_status_t AXIS2_CALL
           adb_Policy_reset_alternatives(
                   adb_Policy_t* _Policy,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _Policy, AXIS2_FAILURE);
               

               
            
                
                if(_Policy->property_alternatives != NULL)
                {
                   
                   adb_Iterator_free(_Policy->property_alternatives, env);
                     _Policy->property_alternatives = NULL;
                }
            
                
                
                _Policy->is_valid_alternatives = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether alternatives is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_Policy_is_alternatives_nil(
                   adb_Policy_t* _Policy,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _Policy, AXIS2_TRUE);
               
               return !_Policy->is_valid_alternatives;
           }

           /**
            * Set alternatives to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_Policy_set_alternatives_nil(
                   adb_Policy_t* _Policy,
                   const axutil_env_t *env)
           {
               return adb_Policy_reset_alternatives(_Policy, env);
           }

           

            /**
             * Getter for attributes by  Property Number 7
             */
            adb_Map_t* AXIS2_CALL
            adb_Policy_get_property7(
                adb_Policy_t* _Policy,
                const axutil_env_t *env)
            {
                return adb_Policy_get_attributes(_Policy,
                                             env);
            }

            /**
             * getter for attributes.
             */
            adb_Map_t* AXIS2_CALL
            adb_Policy_get_attributes(
                    adb_Policy_t* _Policy,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _Policy, NULL);
                  

                return _Policy->property_attributes;
             }

            /**
             * setter for attributes
             */
            axis2_status_t AXIS2_CALL
            adb_Policy_set_attributes(
                    adb_Policy_t* _Policy,
                    const axutil_env_t *env,
                    adb_Map_t*  arg_attributes)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _Policy, AXIS2_FAILURE);
                
                if(_Policy->is_valid_attributes &&
                        arg_attributes == _Policy->property_attributes)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_Policy_reset_attributes(_Policy, env);

                
                if(NULL == arg_attributes)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _Policy->property_attributes = arg_attributes;
                        _Policy->is_valid_attributes = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for attributes
            */
           axis2_status_t AXIS2_CALL
           adb_Policy_reset_attributes(
                   adb_Policy_t* _Policy,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _Policy, AXIS2_FAILURE);
               

               
            
                
                if(_Policy->property_attributes != NULL)
                {
                   
                   adb_Map_free(_Policy->property_attributes, env);
                     _Policy->property_attributes = NULL;
                }
            
                
                
                _Policy->is_valid_attributes = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether attributes is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_Policy_is_attributes_nil(
                   adb_Policy_t* _Policy,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _Policy, AXIS2_TRUE);
               
               return !_Policy->is_valid_attributes;
           }

           /**
            * Set attributes to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_Policy_set_attributes_nil(
                   adb_Policy_t* _Policy,
                   const axutil_env_t *env)
           {
               return adb_Policy_reset_attributes(_Policy, env);
           }

           

            /**
             * Getter for id by  Property Number 8
             */
            axis2_char_t* AXIS2_CALL
            adb_Policy_get_property8(
                adb_Policy_t* _Policy,
                const axutil_env_t *env)
            {
                return adb_Policy_get_id(_Policy,
                                             env);
            }

            /**
             * getter for id.
             */
            axis2_char_t* AXIS2_CALL
            adb_Policy_get_id(
                    adb_Policy_t* _Policy,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _Policy, NULL);
                  

                return _Policy->property_id;
             }

            /**
             * setter for id
             */
            axis2_status_t AXIS2_CALL
            adb_Policy_set_id(
                    adb_Policy_t* _Policy,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_id)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _Policy, AXIS2_FAILURE);
                
                if(_Policy->is_valid_id &&
                        arg_id == _Policy->property_id)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_Policy_reset_id(_Policy, env);

                
                if(NULL == arg_id)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _Policy->property_id = (axis2_char_t *)axutil_strdup(env, arg_id);
                        if(NULL == _Policy->property_id)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for id");
                            return AXIS2_FAILURE;
                        }
                        _Policy->is_valid_id = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for id
            */
           axis2_status_t AXIS2_CALL
           adb_Policy_reset_id(
                   adb_Policy_t* _Policy,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _Policy, AXIS2_FAILURE);
               

               
            
                
                if(_Policy->property_id != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _Policy->property_id);
                     _Policy->property_id = NULL;
                }
            
                
                
                _Policy->is_valid_id = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether id is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_Policy_is_id_nil(
                   adb_Policy_t* _Policy,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _Policy, AXIS2_TRUE);
               
               return !_Policy->is_valid_id;
           }

           /**
            * Set id to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_Policy_set_id_nil(
                   adb_Policy_t* _Policy,
                   const axutil_env_t *env)
           {
               return adb_Policy_reset_id(_Policy, env);
           }

           

            /**
             * Getter for name by  Property Number 9
             */
            axis2_char_t* AXIS2_CALL
            adb_Policy_get_property9(
                adb_Policy_t* _Policy,
                const axutil_env_t *env)
            {
                return adb_Policy_get_name(_Policy,
                                             env);
            }

            /**
             * getter for name.
             */
            axis2_char_t* AXIS2_CALL
            adb_Policy_get_name(
                    adb_Policy_t* _Policy,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _Policy, NULL);
                  

                return _Policy->property_name;
             }

            /**
             * setter for name
             */
            axis2_status_t AXIS2_CALL
            adb_Policy_set_name(
                    adb_Policy_t* _Policy,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_name)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _Policy, AXIS2_FAILURE);
                
                if(_Policy->is_valid_name &&
                        arg_name == _Policy->property_name)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_Policy_reset_name(_Policy, env);

                
                if(NULL == arg_name)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _Policy->property_name = (axis2_char_t *)axutil_strdup(env, arg_name);
                        if(NULL == _Policy->property_name)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for name");
                            return AXIS2_FAILURE;
                        }
                        _Policy->is_valid_name = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for name
            */
           axis2_status_t AXIS2_CALL
           adb_Policy_reset_name(
                   adb_Policy_t* _Policy,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _Policy, AXIS2_FAILURE);
               

               
            
                
                if(_Policy->property_name != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _Policy->property_name);
                     _Policy->property_name = NULL;
                }
            
                
                
                _Policy->is_valid_name = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether name is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_Policy_is_name_nil(
                   adb_Policy_t* _Policy,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _Policy, AXIS2_TRUE);
               
               return !_Policy->is_valid_name;
           }

           /**
            * Set name to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_Policy_set_name_nil(
                   adb_Policy_t* _Policy,
                   const axutil_env_t *env)
           {
               return adb_Policy_reset_name(_Policy, env);
           }

           

            /**
             * Getter for type by  Property Number 10
             */
            short AXIS2_CALL
            adb_Policy_get_property10(
                adb_Policy_t* _Policy,
                const axutil_env_t *env)
            {
                return adb_Policy_get_type(_Policy,
                                             env);
            }

            /**
             * getter for type.
             */
            short AXIS2_CALL
            adb_Policy_get_type(
                    adb_Policy_t* _Policy,
                    const axutil_env_t *env)
             {
                
                return _Policy->property_type;
             }

            /**
             * setter for type
             */
            axis2_status_t AXIS2_CALL
            adb_Policy_set_type(
                    adb_Policy_t* _Policy,
                    const axutil_env_t *env,
                    const short  arg_type)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _Policy, AXIS2_FAILURE);
                
                if(_Policy->is_valid_type &&
                        arg_type == _Policy->property_type)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_Policy_reset_type(_Policy, env);

                _Policy->property_type = arg_type;
                        _Policy->is_valid_type = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for type
            */
           axis2_status_t AXIS2_CALL
           adb_Policy_reset_type(
                   adb_Policy_t* _Policy,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _Policy, AXIS2_FAILURE);
               

               _Policy->is_valid_type = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether type is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_Policy_is_type_nil(
                   adb_Policy_t* _Policy,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _Policy, AXIS2_TRUE);
               
               return !_Policy->is_valid_type;
           }

           /**
            * Set type to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_Policy_set_type_nil(
                   adb_Policy_t* _Policy,
                   const axutil_env_t *env)
           {
               return adb_Policy_reset_type(_Policy, env);
           }

           

