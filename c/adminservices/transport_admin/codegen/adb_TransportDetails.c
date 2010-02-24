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
         * adb_TransportDetails.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_TransportDetails.h"
        
                /*
                 * This type was generated from the piece of schema that had
                 * name = TransportDetails
                 * Namespace URI = http://util.transports.core.carbon.wso2.org/xsd
                 * Namespace Prefix = ns1
                 */
           


        struct adb_TransportDetails
        {
            axis2_char_t *property_Type;

            axutil_array_list_t* property_inParameters;

                
                axis2_bool_t is_valid_inParameters;
            axis2_bool_t property_listenerActive;

                
                axis2_bool_t is_valid_listenerActive;
            axutil_array_list_t* property_outParameters;

                
                axis2_bool_t is_valid_outParameters;
            axis2_bool_t property_senderActive;

                
                axis2_bool_t is_valid_senderActive;
            
        };


       /************************* Private Function prototypes ********************************/
        

                axis2_status_t AXIS2_CALL
                adb_TransportDetails_set_listenerActive_nil(
                        adb_TransportDetails_t* _TransportDetails,
                        const axutil_env_t *env);
            

                axis2_status_t AXIS2_CALL
                adb_TransportDetails_set_senderActive_nil(
                        adb_TransportDetails_t* _TransportDetails,
                        const axutil_env_t *env);
            


       /************************* Function Implmentations ********************************/
        adb_TransportDetails_t* AXIS2_CALL
        adb_TransportDetails_create(
            const axutil_env_t *env)
        {
            adb_TransportDetails_t *_TransportDetails = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _TransportDetails = (adb_TransportDetails_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_TransportDetails_t));

            if(NULL == _TransportDetails)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_TransportDetails, 0, sizeof(adb_TransportDetails_t));

            _TransportDetails->property_Type = axutil_strdup(env, "adb_TransportDetails");
            _TransportDetails->property_inParameters  = NULL;
                  _TransportDetails->is_valid_inParameters  = AXIS2_FALSE;
            _TransportDetails->is_valid_listenerActive  = AXIS2_FALSE;
            _TransportDetails->property_outParameters  = NULL;
                  _TransportDetails->is_valid_outParameters  = AXIS2_FALSE;
            _TransportDetails->is_valid_senderActive  = AXIS2_FALSE;
            

            return _TransportDetails;
        }

        adb_TransportDetails_t* AXIS2_CALL
        adb_TransportDetails_create_with_values(
            const axutil_env_t *env,
                axutil_array_list_t* _inParameters,
                axis2_bool_t _listenerActive,
                axutil_array_list_t* _outParameters,
                axis2_bool_t _senderActive)
        {
            adb_TransportDetails_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_TransportDetails_create(env);

            
              status = adb_TransportDetails_set_inParameters(
                                     adb_obj,
                                     env,
                                     _inParameters);
              if(status == AXIS2_FAILURE) {
                  adb_TransportDetails_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_TransportDetails_set_listenerActive(
                                     adb_obj,
                                     env,
                                     _listenerActive);
              if(status == AXIS2_FAILURE) {
                  adb_TransportDetails_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_TransportDetails_set_outParameters(
                                     adb_obj,
                                     env,
                                     _outParameters);
              if(status == AXIS2_FAILURE) {
                  adb_TransportDetails_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_TransportDetails_set_senderActive(
                                     adb_obj,
                                     env,
                                     _senderActive);
              if(status == AXIS2_FAILURE) {
                  adb_TransportDetails_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axutil_array_list_t* AXIS2_CALL
                adb_TransportDetails_free_popping_value(
                        adb_TransportDetails_t* _TransportDetails,
                        const axutil_env_t *env)
                {
                    axutil_array_list_t* value;

                    
                    
                    value = _TransportDetails->property_inParameters;

                    _TransportDetails->property_inParameters = (axutil_array_list_t*)NULL;
                    adb_TransportDetails_free(_TransportDetails, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_TransportDetails_free(
                adb_TransportDetails_t* _TransportDetails,
                const axutil_env_t *env)
        {
            
            
            return axis2_extension_mapper_free(
                (adb_type_t*) _TransportDetails,
                env,
                "adb_TransportDetails");
            
        }

        axis2_status_t AXIS2_CALL
        adb_TransportDetails_free_obj(
                adb_TransportDetails_t* _TransportDetails,
                const axutil_env_t *env)
        {
            
                int i = 0;
                int count = 0;
                void *element = NULL;
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _TransportDetails, AXIS2_FAILURE);

            if (_TransportDetails->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _TransportDetails->property_Type);
            }

            adb_TransportDetails_reset_inParameters(_TransportDetails, env);
            adb_TransportDetails_reset_listenerActive(_TransportDetails, env);
            adb_TransportDetails_reset_outParameters(_TransportDetails, env);
            adb_TransportDetails_reset_senderActive(_TransportDetails, env);
            

            if(_TransportDetails)
            {
                AXIS2_FREE(env->allocator, _TransportDetails);
                _TransportDetails = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_TransportDetails_deserialize(
                adb_TransportDetails_t* _TransportDetails,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return axis2_extension_mapper_deserialize(
                (adb_type_t*) _TransportDetails,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs,
                "adb_TransportDetails");
            
        }

        axis2_status_t AXIS2_CALL
        adb_TransportDetails_deserialize_obj(
                adb_TransportDetails_t* _TransportDetails,
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
            AXIS2_PARAM_CHECK(env->error, _TransportDetails, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for TransportDetails : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              
                      
                      first_node = axiom_node_get_first_child(parent, env);
                      
                    
                    /*
                     * building inParameters array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building inParameters element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "inParameters", "http://util.transports.core.carbon.wso2.org/xsd", NULL);
                                  
                               
                               for (i = 0, sequence_broken = 0, current_node = first_node; !sequence_broken && current_node != NULL;) 
                                             
                               {
                                  if(axiom_node_get_node_type(current_node, env) != AXIOM_ELEMENT)
                                  {
                                     current_node =axiom_node_get_next_sibling(current_node, env);
                                     is_early_node_valid = AXIS2_FALSE;
                                     continue;
                                  }
                                  
                                  current_element = (axiom_element_t *)axiom_node_get_data_element(current_node, env);
                                  qname = axiom_element_get_qname(current_element, env, current_node);

                                  if (adb_TransportParameter_is_particle() ||  
                                    (current_node && current_element && (axutil_qname_equals(element_qname, env, qname))))
                                  {
                                  
                                      if( current_node && current_element && (axutil_qname_equals(element_qname, env, qname)))
                                      {
                                          is_early_node_valid = AXIS2_TRUE;
                                      }
                                      
                                     
                                          element = (void*)axis2_extension_mapper_create_from_node(env, &current_node, "adb_TransportParameter");
                                          
                                          status =  adb_TransportParameter_deserialize((adb_TransportParameter_t*)element, env,
                                                                                 &current_node, &is_early_node_valid, AXIS2_FALSE);
                                          
                                          if(AXIS2_FAILURE ==  status)
                                          {
                                              AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building element inParameters ");
                                          }
                                          else
                                          {
                                            axutil_array_list_add_at(arr_list, env, i, element);
                                          }
                                        
                                     if(AXIS2_FAILURE ==  status)
                                     {
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for inParameters ");
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
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "inParameters (@minOccurs = '0') only have %d elements", i);
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
                                    status = adb_TransportDetails_set_inParameters(_TransportDetails, env,
                                                                   arr_list);
                               }

                             
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 

                     
                     /*
                      * building listenerActive element
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
                                 
                                 element_qname = axutil_qname_create(env, "listenerActive", "http://util.transports.core.carbon.wso2.org/xsd", NULL);
                                 

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
                                                status = adb_TransportDetails_set_listenerActive(_TransportDetails, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_TransportDetails_set_listenerActive(_TransportDetails, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element listenerActive");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for listenerActive ");
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
                     * building outParameters array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building outParameters element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "outParameters", "http://util.transports.core.carbon.wso2.org/xsd", NULL);
                                  
                               
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

                                  if (adb_TransportParameter_is_particle() ||  
                                    (current_node && current_element && (axutil_qname_equals(element_qname, env, qname))))
                                  {
                                  
                                      if( current_node && current_element && (axutil_qname_equals(element_qname, env, qname)))
                                      {
                                          is_early_node_valid = AXIS2_TRUE;
                                      }
                                      
                                     
                                          element = (void*)axis2_extension_mapper_create_from_node(env, &current_node, "adb_TransportParameter");
                                          
                                          status =  adb_TransportParameter_deserialize((adb_TransportParameter_t*)element, env,
                                                                                 &current_node, &is_early_node_valid, AXIS2_FALSE);
                                          
                                          if(AXIS2_FAILURE ==  status)
                                          {
                                              AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building element outParameters ");
                                          }
                                          else
                                          {
                                            axutil_array_list_add_at(arr_list, env, i, element);
                                          }
                                        
                                     if(AXIS2_FAILURE ==  status)
                                     {
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for outParameters ");
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
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "outParameters (@minOccurs = '0') only have %d elements", i);
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
                                    status = adb_TransportDetails_set_outParameters(_TransportDetails, env,
                                                                   arr_list);
                               }

                             
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 

                     
                     /*
                      * building senderActive element
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
                                 
                                 element_qname = axutil_qname_create(env, "senderActive", "http://util.transports.core.carbon.wso2.org/xsd", NULL);
                                 

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
                                                status = adb_TransportDetails_set_senderActive(_TransportDetails, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_TransportDetails_set_senderActive(_TransportDetails, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element senderActive");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for senderActive ");
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
          adb_TransportDetails_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_TransportDetails_declare_parent_namespaces(
                    adb_TransportDetails_t* _TransportDetails,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_TransportDetails_serialize(
                adb_TransportDetails_t* _TransportDetails,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
            if (_TransportDetails == NULL)
            {
                return adb_TransportDetails_serialize_obj(
                    _TransportDetails, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            }
            else
            {
                return axis2_extension_mapper_serialize(
                    (adb_type_t*) _TransportDetails, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index, "adb_TransportDetails");
            }
            
        }

        axiom_node_t* AXIS2_CALL
        adb_TransportDetails_serialize_obj(
                adb_TransportDetails_t* _TransportDetails,
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
                    
                    axis2_char_t text_value_3[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t text_value_4[ADB_DEFAULT_DIGIT_LIMIT];
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _TransportDetails, NULL);
            
            
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
              type_attrib = axutil_strcat(env, " ", xsi_prefix, ":type=\"TransportDetails\"", NULL);
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
                                 "http://util.transports.core.carbon.wso2.org/xsd",
                                 xsi_prefix);
            xsi_type_attri = axiom_attribute_create (env, "type", "TransportDetails", xsi_ns);
            
            axiom_element_add_attribute (parent_element, env, xsi_type_attri, parent);
        
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.transports.core.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.transports.core.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.transports.core.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_TransportDetails->is_valid_inParameters)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("inParameters"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("inParameters")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing inParameters array
                      */
                     if (_TransportDetails->property_inParameters != NULL)
                     {
                        

                            sprintf(start_input_str, "<%s%sinParameters",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%sinParameters>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_TransportDetails->property_inParameters, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_TransportDetails->property_inParameters, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing inParameters element
                      */

                    
                     
                            if(!adb_TransportParameter_is_particle())
                            {
                                axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                            }
                            adb_TransportParameter_serialize((adb_TransportParameter_t*)element, 
                                                                                 env, current_node, parent_element,
                                                                                 adb_TransportParameter_is_particle() || AXIS2_FALSE, namespaces, next_ns_index);
                            
                            if(!adb_TransportParameter_is_particle())
                            {
                                axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                            }
                            
                         }
                     }
                   
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.transports.core.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.transports.core.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.transports.core.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_TransportDetails->is_valid_listenerActive)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("listenerActive"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("listenerActive")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing listenerActive element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%slistenerActive>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%slistenerActive>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_2, (_TransportDetails->property_listenerActive)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_2, axutil_strlen(text_value_2));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.transports.core.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.transports.core.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.transports.core.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_TransportDetails->is_valid_outParameters)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("outParameters"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("outParameters")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing outParameters array
                      */
                     if (_TransportDetails->property_outParameters != NULL)
                     {
                        

                            sprintf(start_input_str, "<%s%soutParameters",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%soutParameters>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_TransportDetails->property_outParameters, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_TransportDetails->property_outParameters, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing outParameters element
                      */

                    
                     
                            if(!adb_TransportParameter_is_particle())
                            {
                                axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                            }
                            adb_TransportParameter_serialize((adb_TransportParameter_t*)element, 
                                                                                 env, current_node, parent_element,
                                                                                 adb_TransportParameter_is_particle() || AXIS2_FALSE, namespaces, next_ns_index);
                            
                            if(!adb_TransportParameter_is_particle())
                            {
                                axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                            }
                            
                         }
                     }
                   
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.transports.core.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.transports.core.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.transports.core.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_TransportDetails->is_valid_senderActive)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("senderActive"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("senderActive")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing senderActive element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%ssenderActive>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%ssenderActive>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_4, (_TransportDetails->property_senderActive)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_4, axutil_strlen(text_value_4));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 

            return parent;
        }


        

            /**
             * Getter for inParameters by  Property Number 1
             */
            axutil_array_list_t* AXIS2_CALL
            adb_TransportDetails_get_property1(
                adb_TransportDetails_t* _TransportDetails,
                const axutil_env_t *env)
            {
                return adb_TransportDetails_get_inParameters(_TransportDetails,
                                             env);
            }

            /**
             * getter for inParameters.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_TransportDetails_get_inParameters(
                    adb_TransportDetails_t* _TransportDetails,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _TransportDetails, NULL);
                  

                return _TransportDetails->property_inParameters;
             }

            /**
             * setter for inParameters
             */
            axis2_status_t AXIS2_CALL
            adb_TransportDetails_set_inParameters(
                    adb_TransportDetails_t* _TransportDetails,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_inParameters)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _TransportDetails, AXIS2_FAILURE);
                
                if(_TransportDetails->is_valid_inParameters &&
                        arg_inParameters == _TransportDetails->property_inParameters)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_inParameters, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "inParameters has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_inParameters, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_TransportDetails_reset_inParameters(_TransportDetails, env);

                
                if(NULL == arg_inParameters)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _TransportDetails->property_inParameters = arg_inParameters;
                        if(non_nil_exists)
                        {
                            _TransportDetails->is_valid_inParameters = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of inParameters.
             */
            adb_TransportParameter_t* AXIS2_CALL
            adb_TransportDetails_get_inParameters_at(
                    adb_TransportDetails_t* _TransportDetails,
                    const axutil_env_t *env, int i)
            {
                adb_TransportParameter_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _TransportDetails, NULL);
                  

                if(_TransportDetails->property_inParameters == NULL)
                {
                    return (adb_TransportParameter_t*)0;
                }
                ret_val = (adb_TransportParameter_t*)axutil_array_list_get(_TransportDetails->property_inParameters, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of inParameters.
             */
            axis2_status_t AXIS2_CALL
            adb_TransportDetails_set_inParameters_at(
                    adb_TransportDetails_t* _TransportDetails,
                    const axutil_env_t *env, int i,
                    adb_TransportParameter_t* arg_inParameters)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _TransportDetails, AXIS2_FAILURE);
                
                if( _TransportDetails->is_valid_inParameters &&
                    _TransportDetails->property_inParameters &&
                
                    arg_inParameters == (adb_TransportParameter_t*)axutil_array_list_get(_TransportDetails->property_inParameters, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_inParameters)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_TransportDetails->property_inParameters != NULL)
                        {
                            size = axutil_array_list_size(_TransportDetails->property_inParameters, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_TransportDetails->property_inParameters, env, i))
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
                  

                if(_TransportDetails->property_inParameters == NULL)
                {
                    _TransportDetails->property_inParameters = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_TransportDetails->property_inParameters, env, i);
                if(NULL != element)
                {
                  
                  
                  adb_TransportParameter_free((adb_TransportParameter_t*)element, env);
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _TransportDetails->is_valid_inParameters = AXIS2_FALSE;
                        axutil_array_list_set(_TransportDetails->property_inParameters , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_TransportDetails->property_inParameters , env, i, arg_inParameters);
                  _TransportDetails->is_valid_inParameters = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to inParameters.
             */
            axis2_status_t AXIS2_CALL
            adb_TransportDetails_add_inParameters(
                    adb_TransportDetails_t* _TransportDetails,
                    const axutil_env_t *env,
                    adb_TransportParameter_t* arg_inParameters)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _TransportDetails, AXIS2_FAILURE);

                
                    if(NULL == arg_inParameters)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_TransportDetails->property_inParameters == NULL)
                {
                    _TransportDetails->property_inParameters = axutil_array_list_create(env, 10);
                }
                if(_TransportDetails->property_inParameters == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for inParameters");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_TransportDetails->property_inParameters , env, arg_inParameters);
                  _TransportDetails->is_valid_inParameters = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the inParameters array.
             */
            int AXIS2_CALL
            adb_TransportDetails_sizeof_inParameters(
                    adb_TransportDetails_t* _TransportDetails,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _TransportDetails, -1);
                if(_TransportDetails->property_inParameters == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_TransportDetails->property_inParameters, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_TransportDetails_remove_inParameters_at(
                    adb_TransportDetails_t* _TransportDetails,
                    const axutil_env_t *env, int i)
            {
                return adb_TransportDetails_set_inParameters_nil_at(_TransportDetails, env, i);
            }

            

           /**
            * resetter for inParameters
            */
           axis2_status_t AXIS2_CALL
           adb_TransportDetails_reset_inParameters(
                   adb_TransportDetails_t* _TransportDetails,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _TransportDetails, AXIS2_FAILURE);
               

               
                  if (_TransportDetails->property_inParameters != NULL)
                  {
                      count = axutil_array_list_size(_TransportDetails->property_inParameters, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_TransportDetails->property_inParameters, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   adb_TransportParameter_free((adb_TransportParameter_t*)element, env);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_TransportDetails->property_inParameters, env);
                  }
                _TransportDetails->is_valid_inParameters = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether inParameters is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_TransportDetails_is_inParameters_nil(
                   adb_TransportDetails_t* _TransportDetails,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _TransportDetails, AXIS2_TRUE);
               
               return !_TransportDetails->is_valid_inParameters;
           }

           /**
            * Set inParameters to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_TransportDetails_set_inParameters_nil(
                   adb_TransportDetails_t* _TransportDetails,
                   const axutil_env_t *env)
           {
               return adb_TransportDetails_reset_inParameters(_TransportDetails, env);
           }

           
           /**
            * Check whether inParameters is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_TransportDetails_is_inParameters_nil_at(
                   adb_TransportDetails_t* _TransportDetails,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _TransportDetails, AXIS2_TRUE);
               
               return (_TransportDetails->is_valid_inParameters == AXIS2_FALSE ||
                        NULL == _TransportDetails->property_inParameters || 
                        NULL == axutil_array_list_get(_TransportDetails->property_inParameters, env, i));
           }

           /**
            * Set inParameters to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_TransportDetails_set_inParameters_nil_at(
                   adb_TransportDetails_t* _TransportDetails,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _TransportDetails, AXIS2_FAILURE);

                if(_TransportDetails->property_inParameters == NULL ||
                            _TransportDetails->is_valid_inParameters == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_TransportDetails->property_inParameters, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_TransportDetails->property_inParameters, env, i))
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
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of inParameters is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_TransportDetails->property_inParameters == NULL)
                {
                    _TransportDetails->is_valid_inParameters = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_TransportDetails->property_inParameters, env, i);
                if(NULL != element)
                {
                  
                  
                  adb_TransportParameter_free((adb_TransportParameter_t*)element, env);
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _TransportDetails->is_valid_inParameters = AXIS2_FALSE;
                        axutil_array_list_set(_TransportDetails->property_inParameters , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_TransportDetails->property_inParameters , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

            /**
             * Getter for listenerActive by  Property Number 2
             */
            axis2_bool_t AXIS2_CALL
            adb_TransportDetails_get_property2(
                adb_TransportDetails_t* _TransportDetails,
                const axutil_env_t *env)
            {
                return adb_TransportDetails_get_listenerActive(_TransportDetails,
                                             env);
            }

            /**
             * getter for listenerActive.
             */
            axis2_bool_t AXIS2_CALL
            adb_TransportDetails_get_listenerActive(
                    adb_TransportDetails_t* _TransportDetails,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _TransportDetails, (axis2_bool_t)0);
                  

                return _TransportDetails->property_listenerActive;
             }

            /**
             * setter for listenerActive
             */
            axis2_status_t AXIS2_CALL
            adb_TransportDetails_set_listenerActive(
                    adb_TransportDetails_t* _TransportDetails,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_listenerActive)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _TransportDetails, AXIS2_FAILURE);
                
                if(_TransportDetails->is_valid_listenerActive &&
                        arg_listenerActive == _TransportDetails->property_listenerActive)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_TransportDetails_reset_listenerActive(_TransportDetails, env);

                _TransportDetails->property_listenerActive = arg_listenerActive;
                        _TransportDetails->is_valid_listenerActive = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for listenerActive
            */
           axis2_status_t AXIS2_CALL
           adb_TransportDetails_reset_listenerActive(
                   adb_TransportDetails_t* _TransportDetails,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _TransportDetails, AXIS2_FAILURE);
               

               _TransportDetails->is_valid_listenerActive = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether listenerActive is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_TransportDetails_is_listenerActive_nil(
                   adb_TransportDetails_t* _TransportDetails,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _TransportDetails, AXIS2_TRUE);
               
               return !_TransportDetails->is_valid_listenerActive;
           }

           /**
            * Set listenerActive to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_TransportDetails_set_listenerActive_nil(
                   adb_TransportDetails_t* _TransportDetails,
                   const axutil_env_t *env)
           {
               return adb_TransportDetails_reset_listenerActive(_TransportDetails, env);
           }

           

            /**
             * Getter for outParameters by  Property Number 3
             */
            axutil_array_list_t* AXIS2_CALL
            adb_TransportDetails_get_property3(
                adb_TransportDetails_t* _TransportDetails,
                const axutil_env_t *env)
            {
                return adb_TransportDetails_get_outParameters(_TransportDetails,
                                             env);
            }

            /**
             * getter for outParameters.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_TransportDetails_get_outParameters(
                    adb_TransportDetails_t* _TransportDetails,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _TransportDetails, NULL);
                  

                return _TransportDetails->property_outParameters;
             }

            /**
             * setter for outParameters
             */
            axis2_status_t AXIS2_CALL
            adb_TransportDetails_set_outParameters(
                    adb_TransportDetails_t* _TransportDetails,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_outParameters)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _TransportDetails, AXIS2_FAILURE);
                
                if(_TransportDetails->is_valid_outParameters &&
                        arg_outParameters == _TransportDetails->property_outParameters)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_outParameters, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "outParameters has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_outParameters, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_TransportDetails_reset_outParameters(_TransportDetails, env);

                
                if(NULL == arg_outParameters)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _TransportDetails->property_outParameters = arg_outParameters;
                        if(non_nil_exists)
                        {
                            _TransportDetails->is_valid_outParameters = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of outParameters.
             */
            adb_TransportParameter_t* AXIS2_CALL
            adb_TransportDetails_get_outParameters_at(
                    adb_TransportDetails_t* _TransportDetails,
                    const axutil_env_t *env, int i)
            {
                adb_TransportParameter_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _TransportDetails, NULL);
                  

                if(_TransportDetails->property_outParameters == NULL)
                {
                    return (adb_TransportParameter_t*)0;
                }
                ret_val = (adb_TransportParameter_t*)axutil_array_list_get(_TransportDetails->property_outParameters, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of outParameters.
             */
            axis2_status_t AXIS2_CALL
            adb_TransportDetails_set_outParameters_at(
                    adb_TransportDetails_t* _TransportDetails,
                    const axutil_env_t *env, int i,
                    adb_TransportParameter_t* arg_outParameters)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _TransportDetails, AXIS2_FAILURE);
                
                if( _TransportDetails->is_valid_outParameters &&
                    _TransportDetails->property_outParameters &&
                
                    arg_outParameters == (adb_TransportParameter_t*)axutil_array_list_get(_TransportDetails->property_outParameters, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_outParameters)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_TransportDetails->property_outParameters != NULL)
                        {
                            size = axutil_array_list_size(_TransportDetails->property_outParameters, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_TransportDetails->property_outParameters, env, i))
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
                  

                if(_TransportDetails->property_outParameters == NULL)
                {
                    _TransportDetails->property_outParameters = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_TransportDetails->property_outParameters, env, i);
                if(NULL != element)
                {
                  
                  
                  adb_TransportParameter_free((adb_TransportParameter_t*)element, env);
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _TransportDetails->is_valid_outParameters = AXIS2_FALSE;
                        axutil_array_list_set(_TransportDetails->property_outParameters , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_TransportDetails->property_outParameters , env, i, arg_outParameters);
                  _TransportDetails->is_valid_outParameters = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to outParameters.
             */
            axis2_status_t AXIS2_CALL
            adb_TransportDetails_add_outParameters(
                    adb_TransportDetails_t* _TransportDetails,
                    const axutil_env_t *env,
                    adb_TransportParameter_t* arg_outParameters)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _TransportDetails, AXIS2_FAILURE);

                
                    if(NULL == arg_outParameters)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_TransportDetails->property_outParameters == NULL)
                {
                    _TransportDetails->property_outParameters = axutil_array_list_create(env, 10);
                }
                if(_TransportDetails->property_outParameters == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for outParameters");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_TransportDetails->property_outParameters , env, arg_outParameters);
                  _TransportDetails->is_valid_outParameters = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the outParameters array.
             */
            int AXIS2_CALL
            adb_TransportDetails_sizeof_outParameters(
                    adb_TransportDetails_t* _TransportDetails,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _TransportDetails, -1);
                if(_TransportDetails->property_outParameters == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_TransportDetails->property_outParameters, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_TransportDetails_remove_outParameters_at(
                    adb_TransportDetails_t* _TransportDetails,
                    const axutil_env_t *env, int i)
            {
                return adb_TransportDetails_set_outParameters_nil_at(_TransportDetails, env, i);
            }

            

           /**
            * resetter for outParameters
            */
           axis2_status_t AXIS2_CALL
           adb_TransportDetails_reset_outParameters(
                   adb_TransportDetails_t* _TransportDetails,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _TransportDetails, AXIS2_FAILURE);
               

               
                  if (_TransportDetails->property_outParameters != NULL)
                  {
                      count = axutil_array_list_size(_TransportDetails->property_outParameters, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_TransportDetails->property_outParameters, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   adb_TransportParameter_free((adb_TransportParameter_t*)element, env);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_TransportDetails->property_outParameters, env);
                  }
                _TransportDetails->is_valid_outParameters = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether outParameters is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_TransportDetails_is_outParameters_nil(
                   adb_TransportDetails_t* _TransportDetails,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _TransportDetails, AXIS2_TRUE);
               
               return !_TransportDetails->is_valid_outParameters;
           }

           /**
            * Set outParameters to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_TransportDetails_set_outParameters_nil(
                   adb_TransportDetails_t* _TransportDetails,
                   const axutil_env_t *env)
           {
               return adb_TransportDetails_reset_outParameters(_TransportDetails, env);
           }

           
           /**
            * Check whether outParameters is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_TransportDetails_is_outParameters_nil_at(
                   adb_TransportDetails_t* _TransportDetails,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _TransportDetails, AXIS2_TRUE);
               
               return (_TransportDetails->is_valid_outParameters == AXIS2_FALSE ||
                        NULL == _TransportDetails->property_outParameters || 
                        NULL == axutil_array_list_get(_TransportDetails->property_outParameters, env, i));
           }

           /**
            * Set outParameters to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_TransportDetails_set_outParameters_nil_at(
                   adb_TransportDetails_t* _TransportDetails,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _TransportDetails, AXIS2_FAILURE);

                if(_TransportDetails->property_outParameters == NULL ||
                            _TransportDetails->is_valid_outParameters == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_TransportDetails->property_outParameters, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_TransportDetails->property_outParameters, env, i))
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
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of outParameters is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_TransportDetails->property_outParameters == NULL)
                {
                    _TransportDetails->is_valid_outParameters = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_TransportDetails->property_outParameters, env, i);
                if(NULL != element)
                {
                  
                  
                  adb_TransportParameter_free((adb_TransportParameter_t*)element, env);
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _TransportDetails->is_valid_outParameters = AXIS2_FALSE;
                        axutil_array_list_set(_TransportDetails->property_outParameters , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_TransportDetails->property_outParameters , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

            /**
             * Getter for senderActive by  Property Number 4
             */
            axis2_bool_t AXIS2_CALL
            adb_TransportDetails_get_property4(
                adb_TransportDetails_t* _TransportDetails,
                const axutil_env_t *env)
            {
                return adb_TransportDetails_get_senderActive(_TransportDetails,
                                             env);
            }

            /**
             * getter for senderActive.
             */
            axis2_bool_t AXIS2_CALL
            adb_TransportDetails_get_senderActive(
                    adb_TransportDetails_t* _TransportDetails,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _TransportDetails, (axis2_bool_t)0);
                  

                return _TransportDetails->property_senderActive;
             }

            /**
             * setter for senderActive
             */
            axis2_status_t AXIS2_CALL
            adb_TransportDetails_set_senderActive(
                    adb_TransportDetails_t* _TransportDetails,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_senderActive)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _TransportDetails, AXIS2_FAILURE);
                
                if(_TransportDetails->is_valid_senderActive &&
                        arg_senderActive == _TransportDetails->property_senderActive)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_TransportDetails_reset_senderActive(_TransportDetails, env);

                _TransportDetails->property_senderActive = arg_senderActive;
                        _TransportDetails->is_valid_senderActive = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for senderActive
            */
           axis2_status_t AXIS2_CALL
           adb_TransportDetails_reset_senderActive(
                   adb_TransportDetails_t* _TransportDetails,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _TransportDetails, AXIS2_FAILURE);
               

               _TransportDetails->is_valid_senderActive = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether senderActive is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_TransportDetails_is_senderActive_nil(
                   adb_TransportDetails_t* _TransportDetails,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _TransportDetails, AXIS2_TRUE);
               
               return !_TransportDetails->is_valid_senderActive;
           }

           /**
            * Set senderActive to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_TransportDetails_set_senderActive_nil(
                   adb_TransportDetails_t* _TransportDetails,
                   const axutil_env_t *env)
           {
               return adb_TransportDetails_reset_senderActive(_TransportDetails, env);
           }

           

