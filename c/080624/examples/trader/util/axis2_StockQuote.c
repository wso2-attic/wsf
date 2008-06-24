
       /**
        * axis2_StockQuote.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/C version: #axisVersion# #today#
        *
        */

        #include <axis2_StockQuote.h>
          
              /**
               * This type was generated from the piece of schema that had
               * name = StockQuote
               * Namespace URI = http://www.wso2.org/types
               * Namespace Prefix = ns1
               */
             


        struct axis2_StockQuote
        {
            axis2_char_t* attrib_name;
            axis2_char_t* attrib_symbol;
            float attrib_price;
            float attrib_high;
            float attrib_low;
            
        };


       /************************* Function Implmentations ********************************/
        AXIS2_EXTERN axis2_StockQuote_t* AXIS2_CALL
        axis2_StockQuote_create(
            const axutil_env_t *env )
        {
            axis2_StockQuote_t *StockQuote = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            StockQuote = (axis2_StockQuote_t *) AXIS2_MALLOC(env->
                allocator, sizeof(axis2_StockQuote_t));

            if(NULL == StockQuote)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            

            return StockQuote;
         }

        axis2_status_t AXIS2_CALL
        axis2_StockQuote_free (
                axis2_StockQuote_t* StockQuote,
                const axutil_env_t *env)
        {
            
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

            

            if(StockQuote)
            {
                AXIS2_FREE( env->allocator, StockQuote);
                StockQuote = NULL;
            }
            return AXIS2_SUCCESS;
        }

        

        axis2_status_t AXIS2_CALL
        axis2_StockQuote_deserialize(
                axis2_StockQuote_t* StockQuote,
                const axutil_env_t *env,
                axiom_node_t* parent)
        {

            axis2_status_t status = AXIS2_SUCCESS;
            axiom_namespace_t *ns1 = NULL;
            
             axis2_char_t* text_value = NULL;
             /*axutil_qname_t *qname = NULL;*/
            
            
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
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL elemenet for StockQuote"
                                              " %d :: %s", env->error->error_number,
                                              AXIS2_ERROR_GET_MESSAGE(env->error));
                return AXIS2_FAILURE;
              }
            
                first_node = parent;
              

                     
                     /**
                      * building name element
                      */
                     
                     
                     
                                   current_node = first_node;
                                 
                           if ( current_node != NULL)
                           {
                              current_element = axiom_node_get_data_element( current_node, env);
                                      text_value = axiom_element_get_text(current_element, env, current_node );
                                      status = axis2_StockQuote_set_name( StockQuote, env,
                                                                   text_value);
                                    
                                 if( AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for name "
                                                         " %d :: %s", env->error->error_number,
                                                         AXIS2_ERROR_GET_MESSAGE(env->error));
                                     return AXIS2_FAILURE;
                                 }
                           }
                           
                               else
                               {
                                   /** this is not a nillable element*/
                                   AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "non nillable or minOuccrs != 0 element name missing"
                                                         " %d :: %s", env->error->error_number,
                                                         AXIS2_ERROR_GET_MESSAGE(env->error));
                                   return AXIS2_FAILURE;
                               }
                           

                     
                     /**
                      * building symbol element
                      */
                     
                     
                     
                                   /**
                                     * because elements are ordered this works fine
                                     */
                                   
                                   if( current_node != NULL)
                                   {
                                       current_node = axiom_node_get_next_sibling( current_node, env);
                                   }
                                 
                           if ( current_node != NULL)
                           {
                              current_element = axiom_node_get_data_element( current_node, env);
                                      text_value = axiom_element_get_text(current_element, env, current_node );
                                      status = axis2_StockQuote_set_symbol( StockQuote, env,
                                                                   text_value);
                                    
                                 if( AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for symbol "
                                                         " %d :: %s", env->error->error_number,
                                                         AXIS2_ERROR_GET_MESSAGE(env->error));
                                     return AXIS2_FAILURE;
                                 }
                           }
                           
                               else
                               {
                                   /** this is not a nillable element*/
                                   AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "non nillable or minOuccrs != 0 element symbol missing"
                                                         " %d :: %s", env->error->error_number,
                                                         AXIS2_ERROR_GET_MESSAGE(env->error));
                                   return AXIS2_FAILURE;
                               }
                           

                     
                     /**
                      * building price element
                      */
                     
                     
                     
                                   /**
                                     * because elements are ordered this works fine
                                     */
                                   
                                   if( current_node != NULL)
                                   {
                                       current_node = axiom_node_get_next_sibling( current_node, env);
                                   }
                                 
                           if ( current_node != NULL)
                           {
                              current_element = axiom_node_get_data_element( current_node, env);
                                      text_value = axiom_element_get_text(current_element, env, current_node );
                                      
                                      status = axis2_StockQuote_set_price( StockQuote, env,
                                                                     atof( text_value));
                                        
                                 if( AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for price "
                                                         " %d :: %s", env->error->error_number,
                                                         AXIS2_ERROR_GET_MESSAGE(env->error));
                                     return AXIS2_FAILURE;
                                 }
                           }
                           
                               else
                               {
                                   /** this is not a nillable element*/
                                   AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "non nillable or minOuccrs != 0 element price missing"
                                                         " %d :: %s", env->error->error_number,
                                                         AXIS2_ERROR_GET_MESSAGE(env->error));
                                   return AXIS2_FAILURE;
                               }
                           

                     
                     /**
                      * building high element
                      */
                     
                     
                     
                                   /**
                                     * because elements are ordered this works fine
                                     */
                                   
                                   if( current_node != NULL)
                                   {
                                       current_node = axiom_node_get_next_sibling( current_node, env);
                                   }
                                 
                           if ( current_node != NULL)
                           {
                              current_element = axiom_node_get_data_element( current_node, env);
                                      text_value = axiom_element_get_text(current_element, env, current_node );
                                      
                                      status = axis2_StockQuote_set_high( StockQuote, env,
                                                                     atof( text_value));
                                        
                                 if( AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for high "
                                                         " %d :: %s", env->error->error_number,
                                                         AXIS2_ERROR_GET_MESSAGE(env->error));
                                     return AXIS2_FAILURE;
                                 }
                           }
                           
                               else
                               {
                                   /** this is not a nillable element*/
                                   AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "non nillable or minOuccrs != 0 element high missing"
                                                         " %d :: %s", env->error->error_number,
                                                         AXIS2_ERROR_GET_MESSAGE(env->error));
                                   return AXIS2_FAILURE;
                               }
                           

                     
                     /**
                      * building low element
                      */
                     
                     
                     
                                   /**
                                     * because elements are ordered this works fine
                                     */
                                   
                                   if( current_node != NULL)
                                   {
                                       current_node = axiom_node_get_next_sibling( current_node, env);
                                   }
                                 
                           if ( current_node != NULL)
                           {
                              current_element = axiom_node_get_data_element( current_node, env);
                                      text_value = axiom_element_get_text(current_element, env, current_node );
                                      
                                      status = axis2_StockQuote_set_low( StockQuote, env,
                                                                     atof( text_value));
                                        
                                 if( AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for low "
                                                         " %d :: %s", env->error->error_number,
                                                         AXIS2_ERROR_GET_MESSAGE(env->error));
                                     return AXIS2_FAILURE;
                                 }
                           }
                           
                               else
                               {
                                   /** this is not a nillable element*/
                                   AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "non nillable or minOuccrs != 0 element low missing"
                                                         " %d :: %s", env->error->error_number,
                                                         AXIS2_ERROR_GET_MESSAGE(env->error));
                                   return AXIS2_FAILURE;
                               }
                            

          return status;
       }

        axiom_node_t* AXIS2_CALL
        axis2_StockQuote_serialize(
                axis2_StockQuote_t* StockQuote,
                const axutil_env_t *env, axiom_node_t* parent, int has_parent)
        {
            
            axiom_namespace_t *ns1 = NULL;
            
                    axis2_char_t *text_value_1;
                    
                    axis2_char_t *text_value_2;
                    
                    axis2_char_t text_value_3[64];
                    
                    axis2_char_t text_value_4[64];
                    
                    axis2_char_t text_value_5[64];
                    
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
                      * parsing name element
                      */
                     

                    
                    
                        start_input_str = "<ns1:name>";
                        start_input_str_len = axutil_strlen(start_input_str);
                        end_input_str = "</ns1:name>";
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_1 = StockQuote->attrib_name;
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           axutil_stream_write(stream, env, text_value_1, axutil_strlen(text_value_1));
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                        
                     
                     /**
                      * parsing symbol element
                      */
                     

                    
                    
                        start_input_str = "<ns1:symbol>";
                        start_input_str_len = axutil_strlen(start_input_str);
                        end_input_str = "</ns1:symbol>";
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_2 = StockQuote->attrib_symbol;
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           axutil_stream_write(stream, env, text_value_2, axutil_strlen(text_value_2));
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                        
                     
                     /**
                      * parsing price element
                      */
                     

                    
                    
                        start_input_str = "<ns1:price>";
                        start_input_str_len = axutil_strlen(start_input_str);
                        end_input_str = "</ns1:price>";
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                               sprintf ( text_value_3, "%f", StockQuote->attrib_price );
                             
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           axutil_stream_write(stream, env, text_value_3, axutil_strlen(text_value_3));
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                        
                     
                     /**
                      * parsing high element
                      */
                     

                    
                    
                        start_input_str = "<ns1:high>";
                        start_input_str_len = axutil_strlen(start_input_str);
                        end_input_str = "</ns1:high>";
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                               sprintf ( text_value_4, "%f", StockQuote->attrib_high );
                             
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           axutil_stream_write(stream, env, text_value_4, axutil_strlen(text_value_4));
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                        
                     
                     /**
                      * parsing low element
                      */
                     

                    
                    
                        start_input_str = "<ns1:low>";
                        start_input_str_len = axutil_strlen(start_input_str);
                        end_input_str = "</ns1:low>";
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                               sprintf ( text_value_5, "%f", StockQuote->attrib_low );
                             
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           axutil_stream_write(stream, env, text_value_5, axutil_strlen(text_value_5));
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                        
            return parent;
        }

        

            /**
             * getter for name.
             */
            axis2_char_t* AXIS2_CALL
            axis2_StockQuote_get_name(
                    axis2_StockQuote_t* StockQuote,
                    const axutil_env_t *env)
             {
                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

                return StockQuote-> attrib_name;
             }

            /**
             * setter for name
             */
            axis2_status_t AXIS2_CALL
            axis2_StockQuote_set_name(
                    axis2_StockQuote_t* StockQuote,
                    const axutil_env_t *env,
                    axis2_char_t*  param_name)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                if(!StockQuote)
                {
                    return AXIS2_FAILURE;
                }

                
                  if( NULL == param_name )
                  {
                      AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "name is NULL, but not a nullable element"
                                                 " %d :: %s", env->error->error_number,
                                                 AXIS2_ERROR_GET_MESSAGE(env->error));
                      return AXIS2_FAILURE;
                  }
                StockQuote-> attrib_name = param_name;
                return AXIS2_SUCCESS;
             }

            

            /**
             * getter for symbol.
             */
            axis2_char_t* AXIS2_CALL
            axis2_StockQuote_get_symbol(
                    axis2_StockQuote_t* StockQuote,
                    const axutil_env_t *env)
             {
                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

                return StockQuote-> attrib_symbol;
             }

            /**
             * setter for symbol
             */
            axis2_status_t AXIS2_CALL
            axis2_StockQuote_set_symbol(
                    axis2_StockQuote_t* StockQuote,
                    const axutil_env_t *env,
                    axis2_char_t*  param_symbol)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                if(!StockQuote)
                {
                    return AXIS2_FAILURE;
                }

                
                  if( NULL == param_symbol )
                  {
                      AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "symbol is NULL, but not a nullable element"
                                                 " %d :: %s", env->error->error_number,
                                                 AXIS2_ERROR_GET_MESSAGE(env->error));
                      return AXIS2_FAILURE;
                  }
                StockQuote-> attrib_symbol = param_symbol;
                return AXIS2_SUCCESS;
             }

            

            /**
             * getter for price.
             */
            float AXIS2_CALL
            axis2_StockQuote_get_price(
                    axis2_StockQuote_t* StockQuote,
                    const axutil_env_t *env)
             {
                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

                return StockQuote-> attrib_price;
             }

            /**
             * setter for price
             */
            axis2_status_t AXIS2_CALL
            axis2_StockQuote_set_price(
                    axis2_StockQuote_t* StockQuote,
                    const axutil_env_t *env,
                    float  param_price)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                if(!StockQuote)
                {
                    return AXIS2_FAILURE;
                }

                StockQuote-> attrib_price = param_price;
                return AXIS2_SUCCESS;
             }

            

            /**
             * getter for high.
             */
            float AXIS2_CALL
            axis2_StockQuote_get_high(
                    axis2_StockQuote_t* StockQuote,
                    const axutil_env_t *env)
             {
                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

                return StockQuote-> attrib_high;
             }

            /**
             * setter for high
             */
            axis2_status_t AXIS2_CALL
            axis2_StockQuote_set_high(
                    axis2_StockQuote_t* StockQuote,
                    const axutil_env_t *env,
                    float  param_high)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                if(!StockQuote)
                {
                    return AXIS2_FAILURE;
                }

                StockQuote-> attrib_high = param_high;
                return AXIS2_SUCCESS;
             }

            

            /**
             * getter for low.
             */
            float AXIS2_CALL
            axis2_StockQuote_get_low(
                    axis2_StockQuote_t* StockQuote,
                    const axutil_env_t *env)
             {
                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

                return StockQuote-> attrib_low;
             }

            /**
             * setter for low
             */
            axis2_status_t AXIS2_CALL
            axis2_StockQuote_set_low(
                    axis2_StockQuote_t* StockQuote,
                    const axutil_env_t *env,
                    float  param_low)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                if(!StockQuote)
                {
                    return AXIS2_FAILURE;
                }

                StockQuote-> attrib_low = param_low;
                return AXIS2_SUCCESS;
             }

            

