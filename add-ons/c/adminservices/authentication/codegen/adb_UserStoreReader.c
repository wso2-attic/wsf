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
         * adb_UserStoreReader.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_UserStoreReader.h"
        
                /*
                 * This type was generated from the piece of schema that had
                 * name = UserStoreReader
                 * Namespace URI = http://core.user.carbon.wso2.org/xsd
                 * Namespace Prefix = ns2
                 */
           


        struct adb_UserStoreReader
        {
            axis2_char_t *property_Type;

            axutil_array_list_t* property_allProfileNames;

                
                axis2_bool_t is_valid_allProfileNames;
            axutil_array_list_t* property_allRoleNames;

                
                axis2_bool_t is_valid_allRoleNames;
            axutil_array_list_t* property_allUserNames;

                
                axis2_bool_t is_valid_allUserNames;
            axutil_array_list_t* property_userPropertyNames;

                
                axis2_bool_t is_valid_userPropertyNames;
            
        };


       /************************* Private Function prototypes ********************************/
        


       /************************* Function Implmentations ********************************/
        adb_UserStoreReader_t* AXIS2_CALL
        adb_UserStoreReader_create(
            const axutil_env_t *env)
        {
            adb_UserStoreReader_t *_UserStoreReader = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _UserStoreReader = (adb_UserStoreReader_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_UserStoreReader_t));

            if(NULL == _UserStoreReader)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_UserStoreReader, 0, sizeof(adb_UserStoreReader_t));

            _UserStoreReader->property_Type = axutil_strdup(env, "adb_UserStoreReader");
            _UserStoreReader->property_allProfileNames  = NULL;
                  _UserStoreReader->is_valid_allProfileNames  = AXIS2_FALSE;
            _UserStoreReader->property_allRoleNames  = NULL;
                  _UserStoreReader->is_valid_allRoleNames  = AXIS2_FALSE;
            _UserStoreReader->property_allUserNames  = NULL;
                  _UserStoreReader->is_valid_allUserNames  = AXIS2_FALSE;
            _UserStoreReader->property_userPropertyNames  = NULL;
                  _UserStoreReader->is_valid_userPropertyNames  = AXIS2_FALSE;
            

            return _UserStoreReader;
        }

        adb_UserStoreReader_t* AXIS2_CALL
        adb_UserStoreReader_create_with_values(
            const axutil_env_t *env,
                axutil_array_list_t* _allProfileNames,
                axutil_array_list_t* _allRoleNames,
                axutil_array_list_t* _allUserNames,
                axutil_array_list_t* _userPropertyNames)
        {
            adb_UserStoreReader_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_UserStoreReader_create(env);

            
              status = adb_UserStoreReader_set_allProfileNames(
                                     adb_obj,
                                     env,
                                     _allProfileNames);
              if(status == AXIS2_FAILURE) {
                  adb_UserStoreReader_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_UserStoreReader_set_allRoleNames(
                                     adb_obj,
                                     env,
                                     _allRoleNames);
              if(status == AXIS2_FAILURE) {
                  adb_UserStoreReader_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_UserStoreReader_set_allUserNames(
                                     adb_obj,
                                     env,
                                     _allUserNames);
              if(status == AXIS2_FAILURE) {
                  adb_UserStoreReader_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_UserStoreReader_set_userPropertyNames(
                                     adb_obj,
                                     env,
                                     _userPropertyNames);
              if(status == AXIS2_FAILURE) {
                  adb_UserStoreReader_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axutil_array_list_t* AXIS2_CALL
                adb_UserStoreReader_free_popping_value(
                        adb_UserStoreReader_t* _UserStoreReader,
                        const axutil_env_t *env)
                {
                    axutil_array_list_t* value;

                    
                    
                    value = _UserStoreReader->property_allProfileNames;

                    _UserStoreReader->property_allProfileNames = (axutil_array_list_t*)NULL;
                    adb_UserStoreReader_free(_UserStoreReader, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_UserStoreReader_free(
                adb_UserStoreReader_t* _UserStoreReader,
                const axutil_env_t *env)
        {
            
            
            return axis2_extension_mapper_free(
                (adb_type_t*) _UserStoreReader,
                env,
                "adb_UserStoreReader");
            
        }

        axis2_status_t AXIS2_CALL
        adb_UserStoreReader_free_obj(
                adb_UserStoreReader_t* _UserStoreReader,
                const axutil_env_t *env)
        {
            
                int i = 0;
                int count = 0;
                void *element = NULL;
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _UserStoreReader, AXIS2_FAILURE);

            if (_UserStoreReader->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _UserStoreReader->property_Type);
            }

            adb_UserStoreReader_reset_allProfileNames(_UserStoreReader, env);
            adb_UserStoreReader_reset_allRoleNames(_UserStoreReader, env);
            adb_UserStoreReader_reset_allUserNames(_UserStoreReader, env);
            adb_UserStoreReader_reset_userPropertyNames(_UserStoreReader, env);
            

            if(_UserStoreReader)
            {
                AXIS2_FREE(env->allocator, _UserStoreReader);
                _UserStoreReader = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_UserStoreReader_deserialize(
                adb_UserStoreReader_t* _UserStoreReader,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return axis2_extension_mapper_deserialize(
                (adb_type_t*) _UserStoreReader,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs,
                "adb_UserStoreReader");
            
        }

        axis2_status_t AXIS2_CALL
        adb_UserStoreReader_deserialize_obj(
                adb_UserStoreReader_t* _UserStoreReader,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
          axiom_node_t *parent = *dp_parent;
          
          axis2_status_t status = AXIS2_SUCCESS;
           
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
            AXIS2_PARAM_CHECK(env->error, _UserStoreReader, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for UserStoreReader : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              
                      
                      first_node = axiom_node_get_first_child(parent, env);
                      
                    
                    /*
                     * building allProfileNames array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building allProfileNames element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "allProfileNames", "http://core.user.carbon.wso2.org/xsd", NULL);
                                  
                               
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
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for allProfileNames ");
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
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "allProfileNames (@minOccurs = '0') only have %d elements", i);
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
                                    status = adb_UserStoreReader_set_allProfileNames(_UserStoreReader, env,
                                                                   arr_list);
                               }

                             
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 
                    /*
                     * building allRoleNames array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building allRoleNames element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "allRoleNames", "http://core.user.carbon.wso2.org/xsd", NULL);
                                  
                               
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
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for allRoleNames ");
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
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "allRoleNames (@minOccurs = '0') only have %d elements", i);
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
                                    status = adb_UserStoreReader_set_allRoleNames(_UserStoreReader, env,
                                                                   arr_list);
                               }

                             
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 
                    /*
                     * building allUserNames array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building allUserNames element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "allUserNames", "http://core.user.carbon.wso2.org/xsd", NULL);
                                  
                               
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
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for allUserNames ");
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
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "allUserNames (@minOccurs = '0') only have %d elements", i);
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
                                    status = adb_UserStoreReader_set_allUserNames(_UserStoreReader, env,
                                                                   arr_list);
                               }

                             
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 
                    /*
                     * building userPropertyNames array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building userPropertyNames element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "userPropertyNames", "http://core.user.carbon.wso2.org/xsd", NULL);
                                  
                               
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
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for userPropertyNames ");
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
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "userPropertyNames (@minOccurs = '0') only have %d elements", i);
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
                                    status = adb_UserStoreReader_set_userPropertyNames(_UserStoreReader, env,
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
          adb_UserStoreReader_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_UserStoreReader_declare_parent_namespaces(
                    adb_UserStoreReader_t* _UserStoreReader,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_UserStoreReader_serialize(
                adb_UserStoreReader_t* _UserStoreReader,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
            if (_UserStoreReader == NULL)
            {
                return adb_UserStoreReader_serialize_obj(
                    _UserStoreReader, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            }
            else
            {
                return axis2_extension_mapper_serialize(
                    (adb_type_t*) _UserStoreReader, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index, "adb_UserStoreReader");
            }
            
        }

        axiom_node_t* AXIS2_CALL
        adb_UserStoreReader_serialize_obj(
                adb_UserStoreReader_t* _UserStoreReader,
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
             
                    axis2_char_t *text_value_1;
                    axis2_char_t *text_value_1_temp;
                    
                    axis2_char_t *text_value_2;
                    axis2_char_t *text_value_2_temp;
                    
                    axis2_char_t *text_value_3;
                    axis2_char_t *text_value_3_temp;
                    
                    axis2_char_t *text_value_4;
                    axis2_char_t *text_value_4_temp;
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _UserStoreReader, NULL);
            
            
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
              type_attrib = axutil_strcat(env, " ", xsi_prefix, ":type=\"UserStoreReader\"", NULL);
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
            xsi_type_attri = axiom_attribute_create (env, "type", "UserStoreReader", xsi_ns);
            
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
                      

                   if (!_UserStoreReader->is_valid_allProfileNames)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("allProfileNames"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("allProfileNames")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing allProfileNames array
                      */
                     if (_UserStoreReader->property_allProfileNames != NULL)
                     {
                        
                            sprintf(start_input_str, "<%s%sallProfileNames>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%sallProfileNames>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_UserStoreReader->property_allProfileNames, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_UserStoreReader->property_allProfileNames, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing allProfileNames element
                      */

                    
                    
                           text_value_1 = (axis2_char_t*)element;
                           
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
                           
                         }
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
                      

                   if (!_UserStoreReader->is_valid_allRoleNames)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("allRoleNames"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("allRoleNames")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing allRoleNames array
                      */
                     if (_UserStoreReader->property_allRoleNames != NULL)
                     {
                        
                            sprintf(start_input_str, "<%s%sallRoleNames>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%sallRoleNames>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_UserStoreReader->property_allRoleNames, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_UserStoreReader->property_allRoleNames, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing allRoleNames element
                      */

                    
                    
                           text_value_2 = (axis2_char_t*)element;
                           
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
                           
                         }
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
                      

                   if (!_UserStoreReader->is_valid_allUserNames)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("allUserNames"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("allUserNames")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing allUserNames array
                      */
                     if (_UserStoreReader->property_allUserNames != NULL)
                     {
                        
                            sprintf(start_input_str, "<%s%sallUserNames>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%sallUserNames>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_UserStoreReader->property_allUserNames, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_UserStoreReader->property_allUserNames, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing allUserNames element
                      */

                    
                    
                           text_value_3 = (axis2_char_t*)element;
                           
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
                           
                         }
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
                      

                   if (!_UserStoreReader->is_valid_userPropertyNames)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("userPropertyNames"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("userPropertyNames")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing userPropertyNames array
                      */
                     if (_UserStoreReader->property_userPropertyNames != NULL)
                     {
                        
                            sprintf(start_input_str, "<%s%suserPropertyNames>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%suserPropertyNames>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_UserStoreReader->property_userPropertyNames, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_UserStoreReader->property_userPropertyNames, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing userPropertyNames element
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

                 

            return parent;
        }


        

            /**
             * Getter for allProfileNames by  Property Number 1
             */
            axutil_array_list_t* AXIS2_CALL
            adb_UserStoreReader_get_property1(
                adb_UserStoreReader_t* _UserStoreReader,
                const axutil_env_t *env)
            {
                return adb_UserStoreReader_get_allProfileNames(_UserStoreReader,
                                             env);
            }

            /**
             * getter for allProfileNames.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_UserStoreReader_get_allProfileNames(
                    adb_UserStoreReader_t* _UserStoreReader,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _UserStoreReader, NULL);
                  

                return _UserStoreReader->property_allProfileNames;
             }

            /**
             * setter for allProfileNames
             */
            axis2_status_t AXIS2_CALL
            adb_UserStoreReader_set_allProfileNames(
                    adb_UserStoreReader_t* _UserStoreReader,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_allProfileNames)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _UserStoreReader, AXIS2_FAILURE);
                
                if(_UserStoreReader->is_valid_allProfileNames &&
                        arg_allProfileNames == _UserStoreReader->property_allProfileNames)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_allProfileNames, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "allProfileNames has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_allProfileNames, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_UserStoreReader_reset_allProfileNames(_UserStoreReader, env);

                
                if(NULL == arg_allProfileNames)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _UserStoreReader->property_allProfileNames = arg_allProfileNames;
                        if(non_nil_exists)
                        {
                            _UserStoreReader->is_valid_allProfileNames = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of allProfileNames.
             */
            axis2_char_t* AXIS2_CALL
            adb_UserStoreReader_get_allProfileNames_at(
                    adb_UserStoreReader_t* _UserStoreReader,
                    const axutil_env_t *env, int i)
            {
                axis2_char_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _UserStoreReader, NULL);
                  

                if(_UserStoreReader->property_allProfileNames == NULL)
                {
                    return (axis2_char_t*)0;
                }
                ret_val = (axis2_char_t*)axutil_array_list_get(_UserStoreReader->property_allProfileNames, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of allProfileNames.
             */
            axis2_status_t AXIS2_CALL
            adb_UserStoreReader_set_allProfileNames_at(
                    adb_UserStoreReader_t* _UserStoreReader,
                    const axutil_env_t *env, int i,
                    const axis2_char_t* arg_allProfileNames)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _UserStoreReader, AXIS2_FAILURE);
                
                if( _UserStoreReader->is_valid_allProfileNames &&
                    _UserStoreReader->property_allProfileNames &&
                
                    arg_allProfileNames == (axis2_char_t*)axutil_array_list_get(_UserStoreReader->property_allProfileNames, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_allProfileNames)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_UserStoreReader->property_allProfileNames != NULL)
                        {
                            size = axutil_array_list_size(_UserStoreReader->property_allProfileNames, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_UserStoreReader->property_allProfileNames, env, i))
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
                  

                if(_UserStoreReader->property_allProfileNames == NULL)
                {
                    _UserStoreReader->property_allProfileNames = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_UserStoreReader->property_allProfileNames, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _UserStoreReader->is_valid_allProfileNames = AXIS2_FALSE;
                        axutil_array_list_set(_UserStoreReader->property_allProfileNames , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_UserStoreReader->property_allProfileNames , env, i, axutil_strdup(env, arg_allProfileNames));
                  _UserStoreReader->is_valid_allProfileNames = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to allProfileNames.
             */
            axis2_status_t AXIS2_CALL
            adb_UserStoreReader_add_allProfileNames(
                    adb_UserStoreReader_t* _UserStoreReader,
                    const axutil_env_t *env,
                    const axis2_char_t* arg_allProfileNames)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _UserStoreReader, AXIS2_FAILURE);

                
                    if(NULL == arg_allProfileNames)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_UserStoreReader->property_allProfileNames == NULL)
                {
                    _UserStoreReader->property_allProfileNames = axutil_array_list_create(env, 10);
                }
                if(_UserStoreReader->property_allProfileNames == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for allProfileNames");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_UserStoreReader->property_allProfileNames , env, axutil_strdup(env, arg_allProfileNames));
                  _UserStoreReader->is_valid_allProfileNames = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the allProfileNames array.
             */
            int AXIS2_CALL
            adb_UserStoreReader_sizeof_allProfileNames(
                    adb_UserStoreReader_t* _UserStoreReader,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _UserStoreReader, -1);
                if(_UserStoreReader->property_allProfileNames == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_UserStoreReader->property_allProfileNames, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_UserStoreReader_remove_allProfileNames_at(
                    adb_UserStoreReader_t* _UserStoreReader,
                    const axutil_env_t *env, int i)
            {
                return adb_UserStoreReader_set_allProfileNames_nil_at(_UserStoreReader, env, i);
            }

            

           /**
            * resetter for allProfileNames
            */
           axis2_status_t AXIS2_CALL
           adb_UserStoreReader_reset_allProfileNames(
                   adb_UserStoreReader_t* _UserStoreReader,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _UserStoreReader, AXIS2_FAILURE);
               

               
                  if (_UserStoreReader->property_allProfileNames != NULL)
                  {
                      count = axutil_array_list_size(_UserStoreReader->property_allProfileNames, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_UserStoreReader->property_allProfileNames, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, (axis2_char_t*)element);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_UserStoreReader->property_allProfileNames, env);
                  }
                _UserStoreReader->is_valid_allProfileNames = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether allProfileNames is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_UserStoreReader_is_allProfileNames_nil(
                   adb_UserStoreReader_t* _UserStoreReader,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _UserStoreReader, AXIS2_TRUE);
               
               return !_UserStoreReader->is_valid_allProfileNames;
           }

           /**
            * Set allProfileNames to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_UserStoreReader_set_allProfileNames_nil(
                   adb_UserStoreReader_t* _UserStoreReader,
                   const axutil_env_t *env)
           {
               return adb_UserStoreReader_reset_allProfileNames(_UserStoreReader, env);
           }

           
           /**
            * Check whether allProfileNames is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_UserStoreReader_is_allProfileNames_nil_at(
                   adb_UserStoreReader_t* _UserStoreReader,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _UserStoreReader, AXIS2_TRUE);
               
               return (_UserStoreReader->is_valid_allProfileNames == AXIS2_FALSE ||
                        NULL == _UserStoreReader->property_allProfileNames || 
                        NULL == axutil_array_list_get(_UserStoreReader->property_allProfileNames, env, i));
           }

           /**
            * Set allProfileNames to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_UserStoreReader_set_allProfileNames_nil_at(
                   adb_UserStoreReader_t* _UserStoreReader,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _UserStoreReader, AXIS2_FAILURE);

                if(_UserStoreReader->property_allProfileNames == NULL ||
                            _UserStoreReader->is_valid_allProfileNames == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_UserStoreReader->property_allProfileNames, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_UserStoreReader->property_allProfileNames, env, i))
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
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of allProfileNames is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_UserStoreReader->property_allProfileNames == NULL)
                {
                    _UserStoreReader->is_valid_allProfileNames = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_UserStoreReader->property_allProfileNames, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _UserStoreReader->is_valid_allProfileNames = AXIS2_FALSE;
                        axutil_array_list_set(_UserStoreReader->property_allProfileNames , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_UserStoreReader->property_allProfileNames , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

            /**
             * Getter for allRoleNames by  Property Number 2
             */
            axutil_array_list_t* AXIS2_CALL
            adb_UserStoreReader_get_property2(
                adb_UserStoreReader_t* _UserStoreReader,
                const axutil_env_t *env)
            {
                return adb_UserStoreReader_get_allRoleNames(_UserStoreReader,
                                             env);
            }

            /**
             * getter for allRoleNames.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_UserStoreReader_get_allRoleNames(
                    adb_UserStoreReader_t* _UserStoreReader,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _UserStoreReader, NULL);
                  

                return _UserStoreReader->property_allRoleNames;
             }

            /**
             * setter for allRoleNames
             */
            axis2_status_t AXIS2_CALL
            adb_UserStoreReader_set_allRoleNames(
                    adb_UserStoreReader_t* _UserStoreReader,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_allRoleNames)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _UserStoreReader, AXIS2_FAILURE);
                
                if(_UserStoreReader->is_valid_allRoleNames &&
                        arg_allRoleNames == _UserStoreReader->property_allRoleNames)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_allRoleNames, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "allRoleNames has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_allRoleNames, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_UserStoreReader_reset_allRoleNames(_UserStoreReader, env);

                
                if(NULL == arg_allRoleNames)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _UserStoreReader->property_allRoleNames = arg_allRoleNames;
                        if(non_nil_exists)
                        {
                            _UserStoreReader->is_valid_allRoleNames = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of allRoleNames.
             */
            axis2_char_t* AXIS2_CALL
            adb_UserStoreReader_get_allRoleNames_at(
                    adb_UserStoreReader_t* _UserStoreReader,
                    const axutil_env_t *env, int i)
            {
                axis2_char_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _UserStoreReader, NULL);
                  

                if(_UserStoreReader->property_allRoleNames == NULL)
                {
                    return (axis2_char_t*)0;
                }
                ret_val = (axis2_char_t*)axutil_array_list_get(_UserStoreReader->property_allRoleNames, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of allRoleNames.
             */
            axis2_status_t AXIS2_CALL
            adb_UserStoreReader_set_allRoleNames_at(
                    adb_UserStoreReader_t* _UserStoreReader,
                    const axutil_env_t *env, int i,
                    const axis2_char_t* arg_allRoleNames)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _UserStoreReader, AXIS2_FAILURE);
                
                if( _UserStoreReader->is_valid_allRoleNames &&
                    _UserStoreReader->property_allRoleNames &&
                
                    arg_allRoleNames == (axis2_char_t*)axutil_array_list_get(_UserStoreReader->property_allRoleNames, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_allRoleNames)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_UserStoreReader->property_allRoleNames != NULL)
                        {
                            size = axutil_array_list_size(_UserStoreReader->property_allRoleNames, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_UserStoreReader->property_allRoleNames, env, i))
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
                  

                if(_UserStoreReader->property_allRoleNames == NULL)
                {
                    _UserStoreReader->property_allRoleNames = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_UserStoreReader->property_allRoleNames, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _UserStoreReader->is_valid_allRoleNames = AXIS2_FALSE;
                        axutil_array_list_set(_UserStoreReader->property_allRoleNames , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_UserStoreReader->property_allRoleNames , env, i, axutil_strdup(env, arg_allRoleNames));
                  _UserStoreReader->is_valid_allRoleNames = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to allRoleNames.
             */
            axis2_status_t AXIS2_CALL
            adb_UserStoreReader_add_allRoleNames(
                    adb_UserStoreReader_t* _UserStoreReader,
                    const axutil_env_t *env,
                    const axis2_char_t* arg_allRoleNames)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _UserStoreReader, AXIS2_FAILURE);

                
                    if(NULL == arg_allRoleNames)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_UserStoreReader->property_allRoleNames == NULL)
                {
                    _UserStoreReader->property_allRoleNames = axutil_array_list_create(env, 10);
                }
                if(_UserStoreReader->property_allRoleNames == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for allRoleNames");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_UserStoreReader->property_allRoleNames , env, axutil_strdup(env, arg_allRoleNames));
                  _UserStoreReader->is_valid_allRoleNames = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the allRoleNames array.
             */
            int AXIS2_CALL
            adb_UserStoreReader_sizeof_allRoleNames(
                    adb_UserStoreReader_t* _UserStoreReader,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _UserStoreReader, -1);
                if(_UserStoreReader->property_allRoleNames == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_UserStoreReader->property_allRoleNames, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_UserStoreReader_remove_allRoleNames_at(
                    adb_UserStoreReader_t* _UserStoreReader,
                    const axutil_env_t *env, int i)
            {
                return adb_UserStoreReader_set_allRoleNames_nil_at(_UserStoreReader, env, i);
            }

            

           /**
            * resetter for allRoleNames
            */
           axis2_status_t AXIS2_CALL
           adb_UserStoreReader_reset_allRoleNames(
                   adb_UserStoreReader_t* _UserStoreReader,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _UserStoreReader, AXIS2_FAILURE);
               

               
                  if (_UserStoreReader->property_allRoleNames != NULL)
                  {
                      count = axutil_array_list_size(_UserStoreReader->property_allRoleNames, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_UserStoreReader->property_allRoleNames, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, (axis2_char_t*)element);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_UserStoreReader->property_allRoleNames, env);
                  }
                _UserStoreReader->is_valid_allRoleNames = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether allRoleNames is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_UserStoreReader_is_allRoleNames_nil(
                   adb_UserStoreReader_t* _UserStoreReader,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _UserStoreReader, AXIS2_TRUE);
               
               return !_UserStoreReader->is_valid_allRoleNames;
           }

           /**
            * Set allRoleNames to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_UserStoreReader_set_allRoleNames_nil(
                   adb_UserStoreReader_t* _UserStoreReader,
                   const axutil_env_t *env)
           {
               return adb_UserStoreReader_reset_allRoleNames(_UserStoreReader, env);
           }

           
           /**
            * Check whether allRoleNames is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_UserStoreReader_is_allRoleNames_nil_at(
                   adb_UserStoreReader_t* _UserStoreReader,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _UserStoreReader, AXIS2_TRUE);
               
               return (_UserStoreReader->is_valid_allRoleNames == AXIS2_FALSE ||
                        NULL == _UserStoreReader->property_allRoleNames || 
                        NULL == axutil_array_list_get(_UserStoreReader->property_allRoleNames, env, i));
           }

           /**
            * Set allRoleNames to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_UserStoreReader_set_allRoleNames_nil_at(
                   adb_UserStoreReader_t* _UserStoreReader,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _UserStoreReader, AXIS2_FAILURE);

                if(_UserStoreReader->property_allRoleNames == NULL ||
                            _UserStoreReader->is_valid_allRoleNames == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_UserStoreReader->property_allRoleNames, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_UserStoreReader->property_allRoleNames, env, i))
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
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of allRoleNames is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_UserStoreReader->property_allRoleNames == NULL)
                {
                    _UserStoreReader->is_valid_allRoleNames = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_UserStoreReader->property_allRoleNames, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _UserStoreReader->is_valid_allRoleNames = AXIS2_FALSE;
                        axutil_array_list_set(_UserStoreReader->property_allRoleNames , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_UserStoreReader->property_allRoleNames , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

            /**
             * Getter for allUserNames by  Property Number 3
             */
            axutil_array_list_t* AXIS2_CALL
            adb_UserStoreReader_get_property3(
                adb_UserStoreReader_t* _UserStoreReader,
                const axutil_env_t *env)
            {
                return adb_UserStoreReader_get_allUserNames(_UserStoreReader,
                                             env);
            }

            /**
             * getter for allUserNames.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_UserStoreReader_get_allUserNames(
                    adb_UserStoreReader_t* _UserStoreReader,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _UserStoreReader, NULL);
                  

                return _UserStoreReader->property_allUserNames;
             }

            /**
             * setter for allUserNames
             */
            axis2_status_t AXIS2_CALL
            adb_UserStoreReader_set_allUserNames(
                    adb_UserStoreReader_t* _UserStoreReader,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_allUserNames)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _UserStoreReader, AXIS2_FAILURE);
                
                if(_UserStoreReader->is_valid_allUserNames &&
                        arg_allUserNames == _UserStoreReader->property_allUserNames)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_allUserNames, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "allUserNames has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_allUserNames, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_UserStoreReader_reset_allUserNames(_UserStoreReader, env);

                
                if(NULL == arg_allUserNames)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _UserStoreReader->property_allUserNames = arg_allUserNames;
                        if(non_nil_exists)
                        {
                            _UserStoreReader->is_valid_allUserNames = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of allUserNames.
             */
            axis2_char_t* AXIS2_CALL
            adb_UserStoreReader_get_allUserNames_at(
                    adb_UserStoreReader_t* _UserStoreReader,
                    const axutil_env_t *env, int i)
            {
                axis2_char_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _UserStoreReader, NULL);
                  

                if(_UserStoreReader->property_allUserNames == NULL)
                {
                    return (axis2_char_t*)0;
                }
                ret_val = (axis2_char_t*)axutil_array_list_get(_UserStoreReader->property_allUserNames, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of allUserNames.
             */
            axis2_status_t AXIS2_CALL
            adb_UserStoreReader_set_allUserNames_at(
                    adb_UserStoreReader_t* _UserStoreReader,
                    const axutil_env_t *env, int i,
                    const axis2_char_t* arg_allUserNames)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _UserStoreReader, AXIS2_FAILURE);
                
                if( _UserStoreReader->is_valid_allUserNames &&
                    _UserStoreReader->property_allUserNames &&
                
                    arg_allUserNames == (axis2_char_t*)axutil_array_list_get(_UserStoreReader->property_allUserNames, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_allUserNames)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_UserStoreReader->property_allUserNames != NULL)
                        {
                            size = axutil_array_list_size(_UserStoreReader->property_allUserNames, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_UserStoreReader->property_allUserNames, env, i))
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
                  

                if(_UserStoreReader->property_allUserNames == NULL)
                {
                    _UserStoreReader->property_allUserNames = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_UserStoreReader->property_allUserNames, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _UserStoreReader->is_valid_allUserNames = AXIS2_FALSE;
                        axutil_array_list_set(_UserStoreReader->property_allUserNames , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_UserStoreReader->property_allUserNames , env, i, axutil_strdup(env, arg_allUserNames));
                  _UserStoreReader->is_valid_allUserNames = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to allUserNames.
             */
            axis2_status_t AXIS2_CALL
            adb_UserStoreReader_add_allUserNames(
                    adb_UserStoreReader_t* _UserStoreReader,
                    const axutil_env_t *env,
                    const axis2_char_t* arg_allUserNames)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _UserStoreReader, AXIS2_FAILURE);

                
                    if(NULL == arg_allUserNames)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_UserStoreReader->property_allUserNames == NULL)
                {
                    _UserStoreReader->property_allUserNames = axutil_array_list_create(env, 10);
                }
                if(_UserStoreReader->property_allUserNames == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for allUserNames");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_UserStoreReader->property_allUserNames , env, axutil_strdup(env, arg_allUserNames));
                  _UserStoreReader->is_valid_allUserNames = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the allUserNames array.
             */
            int AXIS2_CALL
            adb_UserStoreReader_sizeof_allUserNames(
                    adb_UserStoreReader_t* _UserStoreReader,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _UserStoreReader, -1);
                if(_UserStoreReader->property_allUserNames == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_UserStoreReader->property_allUserNames, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_UserStoreReader_remove_allUserNames_at(
                    adb_UserStoreReader_t* _UserStoreReader,
                    const axutil_env_t *env, int i)
            {
                return adb_UserStoreReader_set_allUserNames_nil_at(_UserStoreReader, env, i);
            }

            

           /**
            * resetter for allUserNames
            */
           axis2_status_t AXIS2_CALL
           adb_UserStoreReader_reset_allUserNames(
                   adb_UserStoreReader_t* _UserStoreReader,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _UserStoreReader, AXIS2_FAILURE);
               

               
                  if (_UserStoreReader->property_allUserNames != NULL)
                  {
                      count = axutil_array_list_size(_UserStoreReader->property_allUserNames, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_UserStoreReader->property_allUserNames, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, (axis2_char_t*)element);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_UserStoreReader->property_allUserNames, env);
                  }
                _UserStoreReader->is_valid_allUserNames = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether allUserNames is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_UserStoreReader_is_allUserNames_nil(
                   adb_UserStoreReader_t* _UserStoreReader,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _UserStoreReader, AXIS2_TRUE);
               
               return !_UserStoreReader->is_valid_allUserNames;
           }

           /**
            * Set allUserNames to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_UserStoreReader_set_allUserNames_nil(
                   adb_UserStoreReader_t* _UserStoreReader,
                   const axutil_env_t *env)
           {
               return adb_UserStoreReader_reset_allUserNames(_UserStoreReader, env);
           }

           
           /**
            * Check whether allUserNames is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_UserStoreReader_is_allUserNames_nil_at(
                   adb_UserStoreReader_t* _UserStoreReader,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _UserStoreReader, AXIS2_TRUE);
               
               return (_UserStoreReader->is_valid_allUserNames == AXIS2_FALSE ||
                        NULL == _UserStoreReader->property_allUserNames || 
                        NULL == axutil_array_list_get(_UserStoreReader->property_allUserNames, env, i));
           }

           /**
            * Set allUserNames to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_UserStoreReader_set_allUserNames_nil_at(
                   adb_UserStoreReader_t* _UserStoreReader,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _UserStoreReader, AXIS2_FAILURE);

                if(_UserStoreReader->property_allUserNames == NULL ||
                            _UserStoreReader->is_valid_allUserNames == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_UserStoreReader->property_allUserNames, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_UserStoreReader->property_allUserNames, env, i))
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
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of allUserNames is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_UserStoreReader->property_allUserNames == NULL)
                {
                    _UserStoreReader->is_valid_allUserNames = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_UserStoreReader->property_allUserNames, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _UserStoreReader->is_valid_allUserNames = AXIS2_FALSE;
                        axutil_array_list_set(_UserStoreReader->property_allUserNames , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_UserStoreReader->property_allUserNames , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

            /**
             * Getter for userPropertyNames by  Property Number 4
             */
            axutil_array_list_t* AXIS2_CALL
            adb_UserStoreReader_get_property4(
                adb_UserStoreReader_t* _UserStoreReader,
                const axutil_env_t *env)
            {
                return adb_UserStoreReader_get_userPropertyNames(_UserStoreReader,
                                             env);
            }

            /**
             * getter for userPropertyNames.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_UserStoreReader_get_userPropertyNames(
                    adb_UserStoreReader_t* _UserStoreReader,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _UserStoreReader, NULL);
                  

                return _UserStoreReader->property_userPropertyNames;
             }

            /**
             * setter for userPropertyNames
             */
            axis2_status_t AXIS2_CALL
            adb_UserStoreReader_set_userPropertyNames(
                    adb_UserStoreReader_t* _UserStoreReader,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_userPropertyNames)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _UserStoreReader, AXIS2_FAILURE);
                
                if(_UserStoreReader->is_valid_userPropertyNames &&
                        arg_userPropertyNames == _UserStoreReader->property_userPropertyNames)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_userPropertyNames, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "userPropertyNames has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_userPropertyNames, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_UserStoreReader_reset_userPropertyNames(_UserStoreReader, env);

                
                if(NULL == arg_userPropertyNames)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _UserStoreReader->property_userPropertyNames = arg_userPropertyNames;
                        if(non_nil_exists)
                        {
                            _UserStoreReader->is_valid_userPropertyNames = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of userPropertyNames.
             */
            axis2_char_t* AXIS2_CALL
            adb_UserStoreReader_get_userPropertyNames_at(
                    adb_UserStoreReader_t* _UserStoreReader,
                    const axutil_env_t *env, int i)
            {
                axis2_char_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _UserStoreReader, NULL);
                  

                if(_UserStoreReader->property_userPropertyNames == NULL)
                {
                    return (axis2_char_t*)0;
                }
                ret_val = (axis2_char_t*)axutil_array_list_get(_UserStoreReader->property_userPropertyNames, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of userPropertyNames.
             */
            axis2_status_t AXIS2_CALL
            adb_UserStoreReader_set_userPropertyNames_at(
                    adb_UserStoreReader_t* _UserStoreReader,
                    const axutil_env_t *env, int i,
                    const axis2_char_t* arg_userPropertyNames)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _UserStoreReader, AXIS2_FAILURE);
                
                if( _UserStoreReader->is_valid_userPropertyNames &&
                    _UserStoreReader->property_userPropertyNames &&
                
                    arg_userPropertyNames == (axis2_char_t*)axutil_array_list_get(_UserStoreReader->property_userPropertyNames, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_userPropertyNames)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_UserStoreReader->property_userPropertyNames != NULL)
                        {
                            size = axutil_array_list_size(_UserStoreReader->property_userPropertyNames, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_UserStoreReader->property_userPropertyNames, env, i))
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
                  

                if(_UserStoreReader->property_userPropertyNames == NULL)
                {
                    _UserStoreReader->property_userPropertyNames = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_UserStoreReader->property_userPropertyNames, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _UserStoreReader->is_valid_userPropertyNames = AXIS2_FALSE;
                        axutil_array_list_set(_UserStoreReader->property_userPropertyNames , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_UserStoreReader->property_userPropertyNames , env, i, axutil_strdup(env, arg_userPropertyNames));
                  _UserStoreReader->is_valid_userPropertyNames = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to userPropertyNames.
             */
            axis2_status_t AXIS2_CALL
            adb_UserStoreReader_add_userPropertyNames(
                    adb_UserStoreReader_t* _UserStoreReader,
                    const axutil_env_t *env,
                    const axis2_char_t* arg_userPropertyNames)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _UserStoreReader, AXIS2_FAILURE);

                
                    if(NULL == arg_userPropertyNames)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_UserStoreReader->property_userPropertyNames == NULL)
                {
                    _UserStoreReader->property_userPropertyNames = axutil_array_list_create(env, 10);
                }
                if(_UserStoreReader->property_userPropertyNames == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for userPropertyNames");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_UserStoreReader->property_userPropertyNames , env, axutil_strdup(env, arg_userPropertyNames));
                  _UserStoreReader->is_valid_userPropertyNames = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the userPropertyNames array.
             */
            int AXIS2_CALL
            adb_UserStoreReader_sizeof_userPropertyNames(
                    adb_UserStoreReader_t* _UserStoreReader,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _UserStoreReader, -1);
                if(_UserStoreReader->property_userPropertyNames == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_UserStoreReader->property_userPropertyNames, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_UserStoreReader_remove_userPropertyNames_at(
                    adb_UserStoreReader_t* _UserStoreReader,
                    const axutil_env_t *env, int i)
            {
                return adb_UserStoreReader_set_userPropertyNames_nil_at(_UserStoreReader, env, i);
            }

            

           /**
            * resetter for userPropertyNames
            */
           axis2_status_t AXIS2_CALL
           adb_UserStoreReader_reset_userPropertyNames(
                   adb_UserStoreReader_t* _UserStoreReader,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _UserStoreReader, AXIS2_FAILURE);
               

               
                  if (_UserStoreReader->property_userPropertyNames != NULL)
                  {
                      count = axutil_array_list_size(_UserStoreReader->property_userPropertyNames, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_UserStoreReader->property_userPropertyNames, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, (axis2_char_t*)element);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_UserStoreReader->property_userPropertyNames, env);
                  }
                _UserStoreReader->is_valid_userPropertyNames = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether userPropertyNames is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_UserStoreReader_is_userPropertyNames_nil(
                   adb_UserStoreReader_t* _UserStoreReader,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _UserStoreReader, AXIS2_TRUE);
               
               return !_UserStoreReader->is_valid_userPropertyNames;
           }

           /**
            * Set userPropertyNames to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_UserStoreReader_set_userPropertyNames_nil(
                   adb_UserStoreReader_t* _UserStoreReader,
                   const axutil_env_t *env)
           {
               return adb_UserStoreReader_reset_userPropertyNames(_UserStoreReader, env);
           }

           
           /**
            * Check whether userPropertyNames is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_UserStoreReader_is_userPropertyNames_nil_at(
                   adb_UserStoreReader_t* _UserStoreReader,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _UserStoreReader, AXIS2_TRUE);
               
               return (_UserStoreReader->is_valid_userPropertyNames == AXIS2_FALSE ||
                        NULL == _UserStoreReader->property_userPropertyNames || 
                        NULL == axutil_array_list_get(_UserStoreReader->property_userPropertyNames, env, i));
           }

           /**
            * Set userPropertyNames to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_UserStoreReader_set_userPropertyNames_nil_at(
                   adb_UserStoreReader_t* _UserStoreReader,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _UserStoreReader, AXIS2_FAILURE);

                if(_UserStoreReader->property_userPropertyNames == NULL ||
                            _UserStoreReader->is_valid_userPropertyNames == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_UserStoreReader->property_userPropertyNames, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_UserStoreReader->property_userPropertyNames, env, i))
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
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of userPropertyNames is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_UserStoreReader->property_userPropertyNames == NULL)
                {
                    _UserStoreReader->is_valid_userPropertyNames = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_UserStoreReader->property_userPropertyNames, env, i);
                if(NULL != element)
                {
                  
                  
                  
                       /* This is an unknown type or a primitive. Please free this manually*/
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _UserStoreReader->is_valid_userPropertyNames = AXIS2_FALSE;
                        axutil_array_list_set(_UserStoreReader->property_userPropertyNames , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_UserStoreReader->property_userPropertyNames , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

