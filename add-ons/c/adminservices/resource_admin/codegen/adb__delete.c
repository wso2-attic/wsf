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
         * adb__delete.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb__delete.h"
        
               /*
                * implmentation of the delete|http://services.resource.ui.mgt.registry.carbon.wso2.org element
                */
           


        struct adb__delete
        {
            axis2_char_t *property_Type;

            
                axutil_qname_t* qname;
            axis2_char_t* property_pathToDelete;

                
                axis2_bool_t is_valid_pathToDelete;
            
        };


       /************************* Private Function prototypes ********************************/
        


       /************************* Function Implmentations ********************************/
        adb__delete_t* AXIS2_CALL
        adb__delete_create(
            const axutil_env_t *env)
        {
            adb__delete_t *__delete = NULL;
            
                axutil_qname_t* qname = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            __delete = (adb__delete_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb__delete_t));

            if(NULL == __delete)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(__delete, 0, sizeof(adb__delete_t));

            __delete->property_Type = axutil_strdup(env, "adb__delete");
            __delete->property_pathToDelete  = NULL;
                  __delete->is_valid_pathToDelete  = AXIS2_FALSE;
            
                  qname =  axutil_qname_create (env,
                        "delete",
                        "http://services.resource.ui.mgt.registry.carbon.wso2.org",
                        NULL);
                __delete->qname = qname;
            

            return __delete;
        }

        adb__delete_t* AXIS2_CALL
        adb__delete_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _pathToDelete)
        {
            adb__delete_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb__delete_create(env);

            
              status = adb__delete_set_pathToDelete(
                                     adb_obj,
                                     env,
                                     _pathToDelete);
              if(status == AXIS2_FAILURE) {
                  adb__delete_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_char_t* AXIS2_CALL
                adb__delete_free_popping_value(
                        adb__delete_t* __delete,
                        const axutil_env_t *env)
                {
                    axis2_char_t* value;

                    
                    
                    value = __delete->property_pathToDelete;

                    __delete->property_pathToDelete = (axis2_char_t*)NULL;
                    adb__delete_free(__delete, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb__delete_free(
                adb__delete_t* __delete,
                const axutil_env_t *env)
        {
            
            
            return adb__delete_free_obj(
                __delete,
                env);
            
        }

        axis2_status_t AXIS2_CALL
        adb__delete_free_obj(
                adb__delete_t* __delete,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, __delete, AXIS2_FAILURE);

            if (__delete->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, __delete->property_Type);
            }

            adb__delete_reset_pathToDelete(__delete, env);
            
              if(__delete->qname)
              {
                  axutil_qname_free (__delete->qname, env);
                  __delete->qname = NULL;
              }
            

            if(__delete)
            {
                AXIS2_FREE(env->allocator, __delete);
                __delete = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb__delete_deserialize(
                adb__delete_t* __delete,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return adb__delete_deserialize_obj(
                __delete,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs);
            
        }

        axis2_status_t AXIS2_CALL
        adb__delete_deserialize_obj(
                adb__delete_t* __delete,
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
            AXIS2_PARAM_CHECK(env->error, __delete, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for delete : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              

                    current_element = (axiom_element_t *)axiom_node_get_data_element(parent, env);
                    qname = axiom_element_get_qname(current_element, env, parent);
                    if (axutil_qname_equals(qname, env, __delete-> qname))
                    {
                        
                          first_node = axiom_node_get_first_child(parent, env);
                          
                    }
                    else
                    {
                        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                              "Failed in building adb object for delete : "
                              "Expected %s but returned %s",
                              axutil_qname_to_string(__delete-> qname, env),
                              axutil_qname_to_string(qname, env));
                        
                        return AXIS2_FAILURE;
                    }
                    

                     
                     /*
                      * building pathToDelete element
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
                                   
                                 element_qname = axutil_qname_create(env, "pathToDelete", "http://services.resource.ui.mgt.registry.carbon.wso2.org", NULL);
                                 

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
                                            status = adb__delete_set_pathToDelete(__delete, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for pathToDelete ");
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
          adb__delete_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb__delete_declare_parent_namespaces(
                    adb__delete_t* __delete,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb__delete_serialize(
                adb__delete_t* __delete,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
                return adb__delete_serialize_obj(
                    __delete, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            
        }

        axiom_node_t* AXIS2_CALL
        adb__delete_serialize_obj(
                adb__delete_t* __delete,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
         
         axiom_node_t* current_node = NULL;
         int tag_closed = 0;
         
                axiom_namespace_t *ns1 = NULL;

                axis2_char_t *qname_uri = NULL;
                axis2_char_t *qname_prefix = NULL;
                axis2_char_t *p_prefix = NULL;
                axis2_bool_t ns_already_defined;
            
                    axis2_char_t *text_value_1;
                    axis2_char_t *text_value_1_temp;
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

             
                int next_ns_index_value = 0;
            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, __delete, NULL);
            
             
                    namespaces = axutil_hash_make(env);
                    next_ns_index = &next_ns_index_value;
                     
                           ns1 = axiom_namespace_create (env,
                                             "http://services.resource.ui.mgt.registry.carbon.wso2.org",
                                             "n"); 
                           axutil_hash_set(namespaces, "http://services.resource.ui.mgt.registry.carbon.wso2.org", AXIS2_HASH_KEY_STRING, axutil_strdup(env, "n"));
                       
                     
                    parent_element = axiom_element_create (env, NULL, "delete", ns1 , &parent);
                    
                    
                    axiom_element_set_namespace(parent_element, env, ns1, parent);


            
                    data_source = axiom_data_source_create(env, parent, &current_node);
                    stream = axiom_data_source_get_stream(data_source, env);
                  
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://services.resource.ui.mgt.registry.carbon.wso2.org", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://services.resource.ui.mgt.registry.carbon.wso2.org", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://services.resource.ui.mgt.registry.carbon.wso2.org",
                                            p_prefix));
                       }
                      

                   if (!__delete->is_valid_pathToDelete)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("pathToDelete"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("pathToDelete")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing pathToDelete element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%spathToDelete>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%spathToDelete>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_1 = __delete->property_pathToDelete;
                           
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

                 
                   if(namespaces)
                   {
                       axutil_hash_index_t *hi;
                       void *val;
                       for (hi = axutil_hash_first(namespaces, env); hi; hi = axutil_hash_next(env, hi)) 
                       {
                           axutil_hash_this(hi, NULL, NULL, &val);
                           AXIS2_FREE(env->allocator, val);
                       }
                       axutil_hash_free(namespaces, env);
                   }
                

            return parent;
        }


        

            /**
             * Getter for pathToDelete by  Property Number 1
             */
            axis2_char_t* AXIS2_CALL
            adb__delete_get_property1(
                adb__delete_t* __delete,
                const axutil_env_t *env)
            {
                return adb__delete_get_pathToDelete(__delete,
                                             env);
            }

            /**
             * getter for pathToDelete.
             */
            axis2_char_t* AXIS2_CALL
            adb__delete_get_pathToDelete(
                    adb__delete_t* __delete,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, __delete, NULL);
                  

                return __delete->property_pathToDelete;
             }

            /**
             * setter for pathToDelete
             */
            axis2_status_t AXIS2_CALL
            adb__delete_set_pathToDelete(
                    adb__delete_t* __delete,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_pathToDelete)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, __delete, AXIS2_FAILURE);
                
                if(__delete->is_valid_pathToDelete &&
                        arg_pathToDelete == __delete->property_pathToDelete)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb__delete_reset_pathToDelete(__delete, env);

                
                if(NULL == arg_pathToDelete)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                __delete->property_pathToDelete = (axis2_char_t *)axutil_strdup(env, arg_pathToDelete);
                        if(NULL == __delete->property_pathToDelete)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for pathToDelete");
                            return AXIS2_FAILURE;
                        }
                        __delete->is_valid_pathToDelete = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for pathToDelete
            */
           axis2_status_t AXIS2_CALL
           adb__delete_reset_pathToDelete(
                   adb__delete_t* __delete,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, __delete, AXIS2_FAILURE);
               

               
            
                
                if(__delete->property_pathToDelete != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, __delete->property_pathToDelete);
                     __delete->property_pathToDelete = NULL;
                }
            
                
                
                __delete->is_valid_pathToDelete = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether pathToDelete is nill
            */
           axis2_bool_t AXIS2_CALL
           adb__delete_is_pathToDelete_nil(
                   adb__delete_t* __delete,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, __delete, AXIS2_TRUE);
               
               return !__delete->is_valid_pathToDelete;
           }

           /**
            * Set pathToDelete to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb__delete_set_pathToDelete_nil(
                   adb__delete_t* __delete,
                   const axutil_env_t *env)
           {
               return adb__delete_reset_pathToDelete(__delete, env);
           }

           

