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
         * adb_Metric.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_Metric.h"
        
                /*
                 * This type was generated from the piece of schema that had
                 * name = Metric
                 * Namespace URI = http://util.services.statistics.carbon.wso2.org/xsd
                 * Namespace Prefix = ns1
                 */
           


        struct adb_Metric
        {
            axis2_char_t* property_unit;

                
                axis2_bool_t is_valid_unit;


            double property_value;

                
                axis2_bool_t is_valid_value;


            
        };


       /************************* Private Function prototypes ********************************/
        

                axis2_status_t AXIS2_CALL
                adb_Metric_set_value_nil(
                        adb_Metric_t* _Metric,
                        const axutil_env_t *env);
            


       /************************* Function Implmentations ********************************/
        adb_Metric_t* AXIS2_CALL
        adb_Metric_create(
            const axutil_env_t *env)
        {
            adb_Metric_t *_Metric = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _Metric = (adb_Metric_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_Metric_t));

            if(NULL == _Metric)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_Metric, 0, sizeof(adb_Metric_t));

            _Metric->property_unit  = NULL;
                  _Metric->is_valid_unit  = AXIS2_FALSE;
            _Metric->is_valid_value  = AXIS2_FALSE;
            

            return _Metric;
        }

        adb_Metric_t* AXIS2_CALL
        adb_Metric_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _unit,
                double _value)
        {
            adb_Metric_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_Metric_create(env);

            
              status = adb_Metric_set_unit(
                                     adb_obj,
                                     env,
                                     _unit);
              if(status == AXIS2_FAILURE) {
                  adb_Metric_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_Metric_set_value(
                                     adb_obj,
                                     env,
                                     _value);
              if(status == AXIS2_FAILURE) {
                  adb_Metric_free (adb_obj, env);
                  return NULL;
              }
            
            

            return adb_obj;
        }
      
        axis2_char_t* AXIS2_CALL
                adb_Metric_free_popping_value(
                        adb_Metric_t* _Metric,
                        const axutil_env_t *env)
                {
                    axis2_char_t* value;
                    
                    value = _Metric->property_unit;

                    _Metric->property_unit = (axis2_char_t*)NULL;
                    adb_Metric_free(_Metric, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_Metric_free(
                adb_Metric_t* _Metric,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _Metric, AXIS2_FAILURE);

            adb_Metric_reset_unit(_Metric, env);
            adb_Metric_reset_value(_Metric, env);
            

            if(_Metric)
            {
                AXIS2_FREE(env->allocator, _Metric);
                _Metric = NULL;
            }
            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_Metric_deserialize(
                adb_Metric_t* _Metric,
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
            AXIS2_PARAM_CHECK(env->error, _Metric, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for Metric : "
                            "NULL elemenet can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              
                      
                      first_node = axiom_node_get_first_child(parent, env);
                      
                    

                     
                     /*
                      * building unit element
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
                                   
                                 element_qname = axutil_qname_create(env, "unit", "http://util.services.statistics.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_Metric_set_unit(_Metric, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for unit ");
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
                                 
                                 element_qname = axutil_qname_create(env, "value", "http://util.services.statistics.carbon.wso2.org/xsd", NULL);
                                 

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
                                            status = adb_Metric_set_value(_Metric, env,
                                                                   atof(text_value));
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element value");
                                          status = AXIS2_FAILURE;
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
          adb_Metric_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_Metric_declare_parent_namespaces(
                    adb_Metric_t* _Metric,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_Metric_serialize(
                adb_Metric_t* _Metric,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
             axis2_char_t *string_to_stream;
            
         
         axiom_node_t *current_node = NULL;
         int tag_closed = 0;

         
         
                axiom_namespace_t *ns1 = NULL;

                axis2_char_t *qname_uri = NULL;
                axis2_char_t *qname_prefix = NULL;
                axis2_char_t *p_prefix = NULL;
                axis2_bool_t ns_already_defined;
            
                    axis2_char_t *text_value_1;
                    axis2_char_t *text_value_1_temp;
                    
                    axis2_char_t text_value_2[ADB_DEFAULT_DIGIT_LIMIT];
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _Metric, NULL);
            
            
                    current_node = parent;
                    data_source = (axiom_data_source_t *)axiom_node_get_data_element(current_node, env);
                    if (!data_source)
                        return NULL;
                    stream = axiom_data_source_get_stream(data_source, env); /* assume parent is of type data source */
                    if (!stream)
                        return NULL;
                  
            if(!parent_tag_closed)
            {
            
              string_to_stream = ">"; 
              axutil_stream_write(stream, env, string_to_stream, axutil_strlen(string_to_stream));
              tag_closed = 1;
            
            }
            
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.services.statistics.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.services.statistics.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.services.statistics.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_Metric->is_valid_unit)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("unit"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("unit")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing unit element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sunit>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sunit>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_1 = _Metric->property_unit;
                           
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

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://util.services.statistics.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://util.services.statistics.carbon.wso2.org/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://util.services.statistics.carbon.wso2.org/xsd",
                                            p_prefix));
                       }
                      

                   if (!_Metric->is_valid_value)
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
                    
                               sprintf (text_value_2, "%f", (double)_Metric->property_value);
                             
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_2, axutil_strlen(text_value_2));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 

            return parent;
        }


        

            /**
             * Getter for unit by  Property Number 1
             */
            axis2_char_t* AXIS2_CALL
            adb_Metric_get_property1(
                adb_Metric_t* _Metric,
                const axutil_env_t *env)
            {
                return adb_Metric_get_unit(_Metric,
                                             env);
            }

            /**
             * getter for unit.
             */
            axis2_char_t* AXIS2_CALL
            adb_Metric_get_unit(
                    adb_Metric_t* _Metric,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _Metric, NULL);
                  

                return _Metric->property_unit;
             }

            /**
             * setter for unit
             */
            axis2_status_t AXIS2_CALL
            adb_Metric_set_unit(
                    adb_Metric_t* _Metric,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_unit)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _Metric, AXIS2_FAILURE);
                
                if(_Metric->is_valid_unit &&
                        arg_unit == _Metric->property_unit)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_Metric_reset_unit(_Metric, env);

                
                if(NULL == arg_unit)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _Metric->property_unit = (axis2_char_t *)axutil_strdup(env, arg_unit);
                        if(NULL == _Metric->property_unit)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for unit");
                            return AXIS2_FAILURE;
                        }
                        _Metric->is_valid_unit = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for unit
            */
           axis2_status_t AXIS2_CALL
           adb_Metric_reset_unit(
                   adb_Metric_t* _Metric,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _Metric, AXIS2_FAILURE);
               

               
            
                
                if(_Metric->property_unit != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _Metric->property_unit);
                     _Metric->property_unit = NULL;
                }
            
                
                
                _Metric->is_valid_unit = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether unit is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_Metric_is_unit_nil(
                   adb_Metric_t* _Metric,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _Metric, AXIS2_TRUE);
               
               return !_Metric->is_valid_unit;
           }

           /**
            * Set unit to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_Metric_set_unit_nil(
                   adb_Metric_t* _Metric,
                   const axutil_env_t *env)
           {
               return adb_Metric_reset_unit(_Metric, env);
           }

           

            /**
             * Getter for value by  Property Number 2
             */
            double AXIS2_CALL
            adb_Metric_get_property2(
                adb_Metric_t* _Metric,
                const axutil_env_t *env)
            {
                return adb_Metric_get_value(_Metric,
                                             env);
            }

            /**
             * getter for value.
             */
            double AXIS2_CALL
            adb_Metric_get_value(
                    adb_Metric_t* _Metric,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (double)0);
                    AXIS2_PARAM_CHECK(env->error, _Metric, (double)0);
                  

                return _Metric->property_value;
             }

            /**
             * setter for value
             */
            axis2_status_t AXIS2_CALL
            adb_Metric_set_value(
                    adb_Metric_t* _Metric,
                    const axutil_env_t *env,
                    const double  arg_value)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _Metric, AXIS2_FAILURE);
                
                if(_Metric->is_valid_value &&
                        arg_value == _Metric->property_value)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_Metric_reset_value(_Metric, env);

                _Metric->property_value = arg_value;
                        _Metric->is_valid_value = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for value
            */
           axis2_status_t AXIS2_CALL
           adb_Metric_reset_value(
                   adb_Metric_t* _Metric,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _Metric, AXIS2_FAILURE);
               

               _Metric->is_valid_value = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether value is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_Metric_is_value_nil(
                   adb_Metric_t* _Metric,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _Metric, AXIS2_TRUE);
               
               return !_Metric->is_valid_value;
           }

           /**
            * Set value to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_Metric_set_value_nil(
                   adb_Metric_t* _Metric,
                   const axutil_env_t *env)
           {
               return adb_Metric_reset_value(_Metric, env);
           }

           

