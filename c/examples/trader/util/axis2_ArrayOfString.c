
       /**
        * axis2_ArrayOfString.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/C version: #axisVersion# #today#
        *
        */

        #include <axis2_ArrayOfString.h>
          
              /**
               * This type was generated from the piece of schema that had
               * name = ArrayOfString
               * Namespace URI = http://www.wso2.org/types
               * Namespace Prefix = ns1
               */
             


        struct axis2_ArrayOfString
        {
            axutil_array_list_t* attrib_value;
            
        };


       /************************* Function Implmentations ********************************/
        AXIS2_EXTERN axis2_ArrayOfString_t* AXIS2_CALL
        axis2_ArrayOfString_create(
            const axutil_env_t *env )
        {
            axis2_ArrayOfString_t *ArrayOfString = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            ArrayOfString = (axis2_ArrayOfString_t *) AXIS2_MALLOC(env->
                allocator, sizeof(axis2_ArrayOfString_t));

            if(NULL == ArrayOfString)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            

            return ArrayOfString;
         }

        axis2_status_t AXIS2_CALL
        axis2_ArrayOfString_free (
                axis2_ArrayOfString_t* ArrayOfString,
                const axutil_env_t *env)
        {
            
            
                  int i = 0;
                  int count = 0;
                  void *element = NULL;
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

            
                if ( ArrayOfString->attrib_value != NULL)
                {
                    count = axutil_array_list_size( ArrayOfString->attrib_value, env);
                    for( i = 0; i < count; i ++)
                    {
                       element = axutil_array_list_get( ArrayOfString->attrib_value, env, i);
              
                    }
                    axutil_array_list_free( ArrayOfString->attrib_value, env);
                }
              

            if(ArrayOfString)
            {
                AXIS2_FREE( env->allocator, ArrayOfString);
                ArrayOfString = NULL;
            }
            return AXIS2_SUCCESS;
        }

        

        axis2_status_t AXIS2_CALL
        axis2_ArrayOfString_deserialize(
                axis2_ArrayOfString_t* ArrayOfString,
                const axutil_env_t *env,
                axiom_node_t* parent)
        {

            axis2_status_t status = AXIS2_SUCCESS;
            axiom_namespace_t *ns1 = NULL;
            
               int i = 0;
               int element_found = 0;
               axutil_array_list_t *arr_list = NULL;
            
               int sequence_broken = 0;
               axiom_node_t *tmp_node = NULL;
            
             axis2_char_t* text_value = NULL;
             axutil_qname_t *qname = NULL;
            
            
              axutil_qname_t *element_qname = NULL;
            
               axiom_node_t *first_node = NULL;
               
             
               axiom_node_t *current_node = NULL;
               axiom_element_t *current_element = NULL;
            
            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

            ns1 = axiom_namespace_create (env,
                                         "http://www.wso2.org/types",
                                         "ns1");
            
              if ( NULL == parent )
              {
                /** This should be checked above */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL elemenet for ArrayOfString"
                                              " %d :: %s", env->error->error_number,
                                              AXIS2_ERROR_GET_MESSAGE(env->error));
                return AXIS2_FAILURE;
              }
            
                first_node = parent;
              
                    /**
                     * building value array
                     */
                     
                       arr_list = axutil_array_list_create( env, 10);
                     

                     
                     /**
                      * building value element
                      */
                     
                     
                      
                               element_qname = axutil_qname_create( env, "value", "","");
                               for ( i = 0, sequence_broken = 0, tmp_node = current_node = first_node; current_node != NULL; current_node = axiom_node_get_next_sibling( current_node, env))
                               {
                                  current_element = axiom_node_get_data_element( current_node, env);
                                  qname = axiom_element_get_qname( current_element, env, current_node);

                                  if ( axutil_qname_equals( element_qname, env, qname) )
                                  {
                                      if( sequence_broken)
                                      {
                                        /** found element out of order */
                                        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "elements found out of order for arrayvalue missing"
                                                         " %d :: %s", env->error->error_number,
                                                         AXIS2_ERROR_GET_MESSAGE(env->error));
                                        return AXIS2_FAILURE;
                                      }
                                      tmp_node = current_node; /** always update the current node */
                                      element_found = 1;
                                      
                                     
                                          text_value = axiom_element_get_text(current_element, env, current_node );
                                          axutil_array_list_add_at( arr_list, env, i, (void*)text_value);
                                        
                                     if( AXIS2_FAILURE ==  status)
                                     {
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for value "
                                                             " %d :: %s", env->error->error_number,
                                                             AXIS2_ERROR_GET_MESSAGE(env->error));
                                         return AXIS2_FAILURE;
                                     }

                                     i ++;
                                  }
                                  else
                                  {
                                      sequence_broken = 1;
                                  }
                               }
                               current_node = tmp_node;
                               status = axis2_ArrayOfString_set_value( ArrayOfString, env,
                                                                   arr_list);

                              

          return status;
       }

        axiom_node_t* AXIS2_CALL
        axis2_ArrayOfString_serialize(
                axis2_ArrayOfString_t* ArrayOfString,
                const axutil_env_t *env, axiom_node_t* parent, int has_parent)
        {
            
            axiom_namespace_t *ns1 = NULL;
            
               long i = 0;
               long count = 0;
               void *element = NULL;
             
                    axis2_char_t *text_value_1;
                    
               axiom_node_t *current_node = NULL;
               /*axiom_element_t *current_element = NULL;*/
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            AXIS2_ENV_CHECK(env, NULL);

            ns1 = axiom_namespace_create (env,
                                         "http://www.wso2.org/types",
                                         "ns1");
            
                if(has_parent)
                {
                    data_source = axiom_node_get_data_element(parent, env);
                    if (!data_source)
                        return NULL;
                    stream = axiom_data_source_get_stream(data_source, env); /* assume parent is of type data source */
                    if (!stream)
                        return NULL;
                    current_node = parent;
                }
                else
                {
                    data_source = axiom_data_source_create(env, parent, &current_node);
                    stream = axiom_data_source_get_stream(data_source, env);
                }
             


                     /**
                      * parsing value array
                      */
                     if ( ArrayOfString->attrib_value != NULL)
                     {
                         start_input_str = "<ns1:value>";
                         start_input_str_len = axutil_strlen(start_input_str);
                         end_input_str = "</ns1:value>";
                         end_input_str_len = axutil_strlen(end_input_str);
                         count = axutil_array_list_size( ArrayOfString->attrib_value, env);
                         for( i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get( ArrayOfString->attrib_value, env, i);
                    
                     
                     /**
                      * parsing value element
                      */
                     

                    
                    
                           text_value_1 = (axis2_char_t*)element;
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           axutil_stream_write(stream, env, text_value_1, axutil_strlen(text_value_1));
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                        
                         }
                     }
                   
            return parent;
        }

        

            /**
             * getter for value.
             */
            axutil_array_list_t* AXIS2_CALL
            axis2_ArrayOfString_get_value(
                    axis2_ArrayOfString_t* ArrayOfString,
                    const axutil_env_t *env)
             {
                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

                return ArrayOfString-> attrib_value;
             }

            /**
             * setter for value
             */
            axis2_status_t AXIS2_CALL
            axis2_ArrayOfString_set_value(
                    axis2_ArrayOfString_t* ArrayOfString,
                    const axutil_env_t *env,
                    axutil_array_list_t*  param_value)
             {
                
                 int size = 0;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                if(!ArrayOfString)
                {
                    return AXIS2_FAILURE;
                }

                
                  size = axutil_array_list_size( param_value, env);
                  
                  if ( size < 0 )
                  {
                      AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "value has less than minOccurs(0)"
                                                 " %d :: %s", env->error->error_number,
                                                 AXIS2_ERROR_GET_MESSAGE(env->error));
                      return AXIS2_FAILURE;
                  }
                ArrayOfString-> attrib_value = param_value;
                return AXIS2_SUCCESS;
             }

            
            /**
             * resetter for value
             */
            axis2_status_t AXIS2_CALL
            axis2_ArrayOfString_reset_value(
                    axis2_ArrayOfString_t* ArrayOfString,
                    const axutil_env_t *env)
             {
                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                if(!ArrayOfString)
                {
                    return AXIS2_FAILURE;
                }
                ArrayOfString-> attrib_value = NULL;
                return AXIS2_SUCCESS;
             }
            

