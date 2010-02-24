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
         * adb_addRemoteLink.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_addRemoteLink.h"
        
               /*
                * implmentation of the addRemoteLink|http://services.resource.ui.mgt.registry.carbon.wso2.org element
                */
           


        struct adb_addRemoteLink
        {
            axis2_char_t *property_Type;

            
                axutil_qname_t* qname;
            axis2_char_t* property_parentPath;

                
                axis2_bool_t is_valid_parentPath;
            axis2_char_t* property_name;

                
                axis2_bool_t is_valid_name;
            axis2_char_t* property_instance;

                
                axis2_bool_t is_valid_instance;
            axis2_char_t* property_targetPath;

                
                axis2_bool_t is_valid_targetPath;
            
        };


       /************************* Private Function prototypes ********************************/
        


       /************************* Function Implmentations ********************************/
        adb_addRemoteLink_t* AXIS2_CALL
        adb_addRemoteLink_create(
            const axutil_env_t *env)
        {
            adb_addRemoteLink_t *_addRemoteLink = NULL;
            
                axutil_qname_t* qname = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _addRemoteLink = (adb_addRemoteLink_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_addRemoteLink_t));

            if(NULL == _addRemoteLink)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_addRemoteLink, 0, sizeof(adb_addRemoteLink_t));

            _addRemoteLink->property_Type = axutil_strdup(env, "adb_addRemoteLink");
            _addRemoteLink->property_parentPath  = NULL;
                  _addRemoteLink->is_valid_parentPath  = AXIS2_FALSE;
            _addRemoteLink->property_name  = NULL;
                  _addRemoteLink->is_valid_name  = AXIS2_FALSE;
            _addRemoteLink->property_instance  = NULL;
                  _addRemoteLink->is_valid_instance  = AXIS2_FALSE;
            _addRemoteLink->property_targetPath  = NULL;
                  _addRemoteLink->is_valid_targetPath  = AXIS2_FALSE;
            
                  qname =  axutil_qname_create (env,
                        "addRemoteLink",
                        "http://services.resource.ui.mgt.registry.carbon.wso2.org",
                        NULL);
                _addRemoteLink->qname = qname;
            

            return _addRemoteLink;
        }

        adb_addRemoteLink_t* AXIS2_CALL
        adb_addRemoteLink_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _parentPath,
                axis2_char_t* _name,
                axis2_char_t* _instance,
                axis2_char_t* _targetPath)
        {
            adb_addRemoteLink_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_addRemoteLink_create(env);

            
              status = adb_addRemoteLink_set_parentPath(
                                     adb_obj,
                                     env,
                                     _parentPath);
              if(status == AXIS2_FAILURE) {
                  adb_addRemoteLink_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_addRemoteLink_set_name(
                                     adb_obj,
                                     env,
                                     _name);
              if(status == AXIS2_FAILURE) {
                  adb_addRemoteLink_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_addRemoteLink_set_instance(
                                     adb_obj,
                                     env,
                                     _instance);
              if(status == AXIS2_FAILURE) {
                  adb_addRemoteLink_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_addRemoteLink_set_targetPath(
                                     adb_obj,
                                     env,
                                     _targetPath);
              if(status == AXIS2_FAILURE) {
                  adb_addRemoteLink_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_char_t* AXIS2_CALL
                adb_addRemoteLink_free_popping_value(
                        adb_addRemoteLink_t* _addRemoteLink,
                        const axutil_env_t *env)
                {
                    axis2_char_t* value;

                    
                    
                    value = _addRemoteLink->property_parentPath;

                    _addRemoteLink->property_parentPath = (axis2_char_t*)NULL;
                    adb_addRemoteLink_free(_addRemoteLink, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_addRemoteLink_free(
                adb_addRemoteLink_t* _addRemoteLink,
                const axutil_env_t *env)
        {
            
            
            return adb_addRemoteLink_free_obj(
                _addRemoteLink,
                env);
            
        }

        axis2_status_t AXIS2_CALL
        adb_addRemoteLink_free_obj(
                adb_addRemoteLink_t* _addRemoteLink,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _addRemoteLink, AXIS2_FAILURE);

            if (_addRemoteLink->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _addRemoteLink->property_Type);
            }

            adb_addRemoteLink_reset_parentPath(_addRemoteLink, env);
            adb_addRemoteLink_reset_name(_addRemoteLink, env);
            adb_addRemoteLink_reset_instance(_addRemoteLink, env);
            adb_addRemoteLink_reset_targetPath(_addRemoteLink, env);
            
              if(_addRemoteLink->qname)
              {
                  axutil_qname_free (_addRemoteLink->qname, env);
                  _addRemoteLink->qname = NULL;
              }
            

            if(_addRemoteLink)
            {
                AXIS2_FREE(env->allocator, _addRemoteLink);
                _addRemoteLink = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_addRemoteLink_deserialize(
                adb_addRemoteLink_t* _addRemoteLink,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return adb_addRemoteLink_deserialize_obj(
                _addRemoteLink,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs);
            
        }

        axis2_status_t AXIS2_CALL
        adb_addRemoteLink_deserialize_obj(
                adb_addRemoteLink_t* _addRemoteLink,
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
            AXIS2_PARAM_CHECK(env->error, _addRemoteLink, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for addRemoteLink : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              

                    current_element = (axiom_element_t *)axiom_node_get_data_element(parent, env);
                    qname = axiom_element_get_qname(current_element, env, parent);
                    if (axutil_qname_equals(qname, env, _addRemoteLink-> qname))
                    {
                        
                          first_node = axiom_node_get_first_child(parent, env);
                          
                    }
                    else
                    {
                        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                              "Failed in building adb object for addRemoteLink : "
                              "Expected %s but returned %s",
                              axutil_qname_to_string(_addRemoteLink-> qname, env),
                              axutil_qname_to_string(qname, env));
                        
                        return AXIS2_FAILURE;
                    }
                    

                     
                     /*
                      * building parentPath element
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
                                   
                                 element_qname = axutil_qname_create(env, "parentPath", "http://services.resource.ui.mgt.registry.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_addRemoteLink_set_parentPath(_addRemoteLink, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for parentPath ");
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
                                 
                                 element_qname = axutil_qname_create(env, "name", "http://services.resource.ui.mgt.registry.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_addRemoteLink_set_name(_addRemoteLink, env,
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
                      * building instance element
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
                                 
                                 element_qname = axutil_qname_create(env, "instance", "http://services.resource.ui.mgt.registry.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_addRemoteLink_set_instance(_addRemoteLink, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for instance ");
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
                      * building targetPath element
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
                                 
                                 element_qname = axutil_qname_create(env, "targetPath", "http://services.resource.ui.mgt.registry.carbon.wso2.org", NULL);
                                 

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
                                            status = adb_addRemoteLink_set_targetPath(_addRemoteLink, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for targetPath ");
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
          adb_addRemoteLink_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_addRemoteLink_declare_parent_namespaces(
                    adb_addRemoteLink_t* _addRemoteLink,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_addRemoteLink_serialize(
                adb_addRemoteLink_t* _addRemoteLink,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
                return adb_addRemoteLink_serialize_obj(
                    _addRemoteLink, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            
        }

        axiom_node_t* AXIS2_CALL
        adb_addRemoteLink_serialize_obj(
                adb_addRemoteLink_t* _addRemoteLink,
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

             
                int next_ns_index_value = 0;
            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _addRemoteLink, NULL);
            
             
                    namespaces = axutil_hash_make(env);
                    next_ns_index = &next_ns_index_value;
                     
                           ns1 = axiom_namespace_create (env,
                                             "http://services.resource.ui.mgt.registry.carbon.wso2.org",
                                             "n"); 
                           axutil_hash_set(namespaces, "http://services.resource.ui.mgt.registry.carbon.wso2.org", AXIS2_HASH_KEY_STRING, axutil_strdup(env, "n"));
                       
                     
                    parent_element = axiom_element_create (env, NULL, "addRemoteLink", ns1 , &parent);
                    
                    
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
                      

                   if (!_addRemoteLink->is_valid_parentPath)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("parentPath"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("parentPath")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing parentPath element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sparentPath>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sparentPath>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_1 = _addRemoteLink->property_parentPath;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://services.resource.ui.mgt.registry.carbon.wso2.org", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://services.resource.ui.mgt.registry.carbon.wso2.org", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://services.resource.ui.mgt.registry.carbon.wso2.org",
                                            p_prefix));
                       }
                      

                   if (!_addRemoteLink->is_valid_name)
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
                    
                           text_value_2 = _addRemoteLink->property_name;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://services.resource.ui.mgt.registry.carbon.wso2.org", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://services.resource.ui.mgt.registry.carbon.wso2.org", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://services.resource.ui.mgt.registry.carbon.wso2.org",
                                            p_prefix));
                       }
                      

                   if (!_addRemoteLink->is_valid_instance)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("instance"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("instance")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing instance element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sinstance>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sinstance>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_3 = _addRemoteLink->property_instance;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://services.resource.ui.mgt.registry.carbon.wso2.org", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://services.resource.ui.mgt.registry.carbon.wso2.org", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://services.resource.ui.mgt.registry.carbon.wso2.org",
                                            p_prefix));
                       }
                      

                   if (!_addRemoteLink->is_valid_targetPath)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("targetPath"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("targetPath")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing targetPath element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%stargetPath>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%stargetPath>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_4 = _addRemoteLink->property_targetPath;
                           
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
             * Getter for parentPath by  Property Number 1
             */
            axis2_char_t* AXIS2_CALL
            adb_addRemoteLink_get_property1(
                adb_addRemoteLink_t* _addRemoteLink,
                const axutil_env_t *env)
            {
                return adb_addRemoteLink_get_parentPath(_addRemoteLink,
                                             env);
            }

            /**
             * getter for parentPath.
             */
            axis2_char_t* AXIS2_CALL
            adb_addRemoteLink_get_parentPath(
                    adb_addRemoteLink_t* _addRemoteLink,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addRemoteLink, NULL);
                  

                return _addRemoteLink->property_parentPath;
             }

            /**
             * setter for parentPath
             */
            axis2_status_t AXIS2_CALL
            adb_addRemoteLink_set_parentPath(
                    adb_addRemoteLink_t* _addRemoteLink,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_parentPath)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addRemoteLink, AXIS2_FAILURE);
                
                if(_addRemoteLink->is_valid_parentPath &&
                        arg_parentPath == _addRemoteLink->property_parentPath)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_addRemoteLink_reset_parentPath(_addRemoteLink, env);

                
                if(NULL == arg_parentPath)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addRemoteLink->property_parentPath = (axis2_char_t *)axutil_strdup(env, arg_parentPath);
                        if(NULL == _addRemoteLink->property_parentPath)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for parentPath");
                            return AXIS2_FAILURE;
                        }
                        _addRemoteLink->is_valid_parentPath = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for parentPath
            */
           axis2_status_t AXIS2_CALL
           adb_addRemoteLink_reset_parentPath(
                   adb_addRemoteLink_t* _addRemoteLink,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addRemoteLink, AXIS2_FAILURE);
               

               
            
                
                if(_addRemoteLink->property_parentPath != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _addRemoteLink->property_parentPath);
                     _addRemoteLink->property_parentPath = NULL;
                }
            
                
                
                _addRemoteLink->is_valid_parentPath = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether parentPath is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addRemoteLink_is_parentPath_nil(
                   adb_addRemoteLink_t* _addRemoteLink,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addRemoteLink, AXIS2_TRUE);
               
               return !_addRemoteLink->is_valid_parentPath;
           }

           /**
            * Set parentPath to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addRemoteLink_set_parentPath_nil(
                   adb_addRemoteLink_t* _addRemoteLink,
                   const axutil_env_t *env)
           {
               return adb_addRemoteLink_reset_parentPath(_addRemoteLink, env);
           }

           

            /**
             * Getter for name by  Property Number 2
             */
            axis2_char_t* AXIS2_CALL
            adb_addRemoteLink_get_property2(
                adb_addRemoteLink_t* _addRemoteLink,
                const axutil_env_t *env)
            {
                return adb_addRemoteLink_get_name(_addRemoteLink,
                                             env);
            }

            /**
             * getter for name.
             */
            axis2_char_t* AXIS2_CALL
            adb_addRemoteLink_get_name(
                    adb_addRemoteLink_t* _addRemoteLink,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addRemoteLink, NULL);
                  

                return _addRemoteLink->property_name;
             }

            /**
             * setter for name
             */
            axis2_status_t AXIS2_CALL
            adb_addRemoteLink_set_name(
                    adb_addRemoteLink_t* _addRemoteLink,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_name)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addRemoteLink, AXIS2_FAILURE);
                
                if(_addRemoteLink->is_valid_name &&
                        arg_name == _addRemoteLink->property_name)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_addRemoteLink_reset_name(_addRemoteLink, env);

                
                if(NULL == arg_name)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addRemoteLink->property_name = (axis2_char_t *)axutil_strdup(env, arg_name);
                        if(NULL == _addRemoteLink->property_name)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for name");
                            return AXIS2_FAILURE;
                        }
                        _addRemoteLink->is_valid_name = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for name
            */
           axis2_status_t AXIS2_CALL
           adb_addRemoteLink_reset_name(
                   adb_addRemoteLink_t* _addRemoteLink,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addRemoteLink, AXIS2_FAILURE);
               

               
            
                
                if(_addRemoteLink->property_name != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _addRemoteLink->property_name);
                     _addRemoteLink->property_name = NULL;
                }
            
                
                
                _addRemoteLink->is_valid_name = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether name is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addRemoteLink_is_name_nil(
                   adb_addRemoteLink_t* _addRemoteLink,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addRemoteLink, AXIS2_TRUE);
               
               return !_addRemoteLink->is_valid_name;
           }

           /**
            * Set name to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addRemoteLink_set_name_nil(
                   adb_addRemoteLink_t* _addRemoteLink,
                   const axutil_env_t *env)
           {
               return adb_addRemoteLink_reset_name(_addRemoteLink, env);
           }

           

            /**
             * Getter for instance by  Property Number 3
             */
            axis2_char_t* AXIS2_CALL
            adb_addRemoteLink_get_property3(
                adb_addRemoteLink_t* _addRemoteLink,
                const axutil_env_t *env)
            {
                return adb_addRemoteLink_get_instance(_addRemoteLink,
                                             env);
            }

            /**
             * getter for instance.
             */
            axis2_char_t* AXIS2_CALL
            adb_addRemoteLink_get_instance(
                    adb_addRemoteLink_t* _addRemoteLink,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addRemoteLink, NULL);
                  

                return _addRemoteLink->property_instance;
             }

            /**
             * setter for instance
             */
            axis2_status_t AXIS2_CALL
            adb_addRemoteLink_set_instance(
                    adb_addRemoteLink_t* _addRemoteLink,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_instance)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addRemoteLink, AXIS2_FAILURE);
                
                if(_addRemoteLink->is_valid_instance &&
                        arg_instance == _addRemoteLink->property_instance)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_addRemoteLink_reset_instance(_addRemoteLink, env);

                
                if(NULL == arg_instance)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addRemoteLink->property_instance = (axis2_char_t *)axutil_strdup(env, arg_instance);
                        if(NULL == _addRemoteLink->property_instance)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for instance");
                            return AXIS2_FAILURE;
                        }
                        _addRemoteLink->is_valid_instance = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for instance
            */
           axis2_status_t AXIS2_CALL
           adb_addRemoteLink_reset_instance(
                   adb_addRemoteLink_t* _addRemoteLink,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addRemoteLink, AXIS2_FAILURE);
               

               
            
                
                if(_addRemoteLink->property_instance != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _addRemoteLink->property_instance);
                     _addRemoteLink->property_instance = NULL;
                }
            
                
                
                _addRemoteLink->is_valid_instance = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether instance is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addRemoteLink_is_instance_nil(
                   adb_addRemoteLink_t* _addRemoteLink,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addRemoteLink, AXIS2_TRUE);
               
               return !_addRemoteLink->is_valid_instance;
           }

           /**
            * Set instance to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addRemoteLink_set_instance_nil(
                   adb_addRemoteLink_t* _addRemoteLink,
                   const axutil_env_t *env)
           {
               return adb_addRemoteLink_reset_instance(_addRemoteLink, env);
           }

           

            /**
             * Getter for targetPath by  Property Number 4
             */
            axis2_char_t* AXIS2_CALL
            adb_addRemoteLink_get_property4(
                adb_addRemoteLink_t* _addRemoteLink,
                const axutil_env_t *env)
            {
                return adb_addRemoteLink_get_targetPath(_addRemoteLink,
                                             env);
            }

            /**
             * getter for targetPath.
             */
            axis2_char_t* AXIS2_CALL
            adb_addRemoteLink_get_targetPath(
                    adb_addRemoteLink_t* _addRemoteLink,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _addRemoteLink, NULL);
                  

                return _addRemoteLink->property_targetPath;
             }

            /**
             * setter for targetPath
             */
            axis2_status_t AXIS2_CALL
            adb_addRemoteLink_set_targetPath(
                    adb_addRemoteLink_t* _addRemoteLink,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_targetPath)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _addRemoteLink, AXIS2_FAILURE);
                
                if(_addRemoteLink->is_valid_targetPath &&
                        arg_targetPath == _addRemoteLink->property_targetPath)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_addRemoteLink_reset_targetPath(_addRemoteLink, env);

                
                if(NULL == arg_targetPath)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _addRemoteLink->property_targetPath = (axis2_char_t *)axutil_strdup(env, arg_targetPath);
                        if(NULL == _addRemoteLink->property_targetPath)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for targetPath");
                            return AXIS2_FAILURE;
                        }
                        _addRemoteLink->is_valid_targetPath = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for targetPath
            */
           axis2_status_t AXIS2_CALL
           adb_addRemoteLink_reset_targetPath(
                   adb_addRemoteLink_t* _addRemoteLink,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _addRemoteLink, AXIS2_FAILURE);
               

               
            
                
                if(_addRemoteLink->property_targetPath != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _addRemoteLink->property_targetPath);
                     _addRemoteLink->property_targetPath = NULL;
                }
            
                
                
                _addRemoteLink->is_valid_targetPath = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether targetPath is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_addRemoteLink_is_targetPath_nil(
                   adb_addRemoteLink_t* _addRemoteLink,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _addRemoteLink, AXIS2_TRUE);
               
               return !_addRemoteLink->is_valid_targetPath;
           }

           /**
            * Set targetPath to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_addRemoteLink_set_targetPath_nil(
                   adb_addRemoteLink_t* _addRemoteLink,
                   const axutil_env_t *env)
           {
               return adb_addRemoteLink_reset_targetPath(_addRemoteLink, env);
           }

           

