
       /**
        * axis2_getQuoteRequest.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/C version: #axisVersion# #today#
        *
        */

        #include <axis2_getQuoteRequest.h>
          
              /**
               * implmentation of the getQuoteRequest|http://www.wso2.org/types element
               */
             


        struct axis2_getQuoteRequest
        {
            
                axutil_qname_t* qname;
            axis2_char_t* attrib_symbol;
            
        };


       /************************* Function Implmentations ********************************/
        AXIS2_EXTERN axis2_getQuoteRequest_t* AXIS2_CALL
        axis2_getQuoteRequest_create(
            const axutil_env_t *env )
        {
            axis2_getQuoteRequest_t *getQuoteRequest = NULL;
            
              axutil_qname_t* qname = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            getQuoteRequest = (axis2_getQuoteRequest_t *) AXIS2_MALLOC(env->
                allocator, sizeof(axis2_getQuoteRequest_t));

            if(NULL == getQuoteRequest)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            
              qname =  axutil_qname_create (env,
                        "getQuoteRequest",
                        "http://www.wso2.org/types",
                        "ns1");

              getQuoteRequest->qname = qname;
            

            return getQuoteRequest;
         }

        axis2_status_t AXIS2_CALL
        axis2_getQuoteRequest_free (
                axis2_getQuoteRequest_t* getQuoteRequest,
                const axutil_env_t *env)
        {
            
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

            
              if(getQuoteRequest->qname )
              {
                  axutil_qname_free (getQuoteRequest->qname, env);
                  getQuoteRequest->qname = NULL;
              }
            

            if(getQuoteRequest)
            {
                AXIS2_FREE( env->allocator, getQuoteRequest);
                getQuoteRequest = NULL;
            }
            return AXIS2_SUCCESS;
        }

          
           axutil_qname_t* AXIS2_CALL
           axis2_getQuoteRequest_get_qname (
                   axis2_getQuoteRequest_t* getQuoteRequest,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

               return getQuoteRequest-> qname;
           }
        

        axis2_status_t AXIS2_CALL
        axis2_getQuoteRequest_deserialize(
                axis2_getQuoteRequest_t* getQuoteRequest,
                const axutil_env_t *env,
                axiom_node_t* parent)
        {

            axis2_status_t status = AXIS2_SUCCESS;
            axiom_namespace_t *ns1 = NULL;
            
             axis2_char_t* text_value = NULL;
             axutil_qname_t *qname = NULL;
            
            
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
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL elemenet for getQuoteRequest"
                                              " %d :: %s", env->error->error_number,
                                              AXIS2_ERROR_GET_MESSAGE(env->error));
                return AXIS2_FAILURE;
              }
            
                    current_element = axiom_node_get_data_element( parent, env);
                    qname = axiom_element_get_qname( current_element, env, parent);
                    if ( axutil_qname_equals( qname, env, getQuoteRequest-> qname ) )
                    {
                        first_node = axiom_node_get_first_child( parent, env);
                    }
                    else
                    {
                        first_node = parent;
                    }
                 

                     
                     /**
                      * building symbol element
                      */
                     
                     
                     
                                   current_node = first_node;
                                 
                           if ( current_node != NULL)
                           {
                              current_element = axiom_node_get_data_element( current_node, env);
                                      text_value = axiom_element_get_text(current_element, env, current_node );
                                      status = axis2_getQuoteRequest_set_symbol( getQuoteRequest, env,
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
                            

          return status;
       }

        axiom_node_t* AXIS2_CALL
        axis2_getQuoteRequest_serialize(
                axis2_getQuoteRequest_t* getQuoteRequest,
                const axutil_env_t *env, axiom_node_t* parent, int has_parent)
        {
            
            axiom_namespace_t *ns1 = NULL;
            
                    axis2_char_t *text_value_1;
                    
               axiom_node_t *current_node = NULL;
               axiom_element_t *current_element = NULL;
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
            
                if( parent == NULL)
                {
                    current_element = axiom_element_create (env, parent, "getQuoteRequest", ns1 , &current_node);
                    axiom_element_set_namespace( current_element, env, ns1, current_node);
                    parent = current_node;
                }
               
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
                      * parsing symbol element
                      */
                     

                    
                    
                        start_input_str = "<ns1:symbol>";
                        start_input_str_len = axutil_strlen(start_input_str);
                        end_input_str = "</ns1:symbol>";
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_1 = getQuoteRequest->attrib_symbol;
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           axutil_stream_write(stream, env, text_value_1, axutil_strlen(text_value_1));
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                        
            return parent;
        }

        

            /**
             * getter for symbol.
             */
            axis2_char_t* AXIS2_CALL
            axis2_getQuoteRequest_get_symbol(
                    axis2_getQuoteRequest_t* getQuoteRequest,
                    const axutil_env_t *env)
             {
                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

                return getQuoteRequest-> attrib_symbol;
             }

            /**
             * setter for symbol
             */
            axis2_status_t AXIS2_CALL
            axis2_getQuoteRequest_set_symbol(
                    axis2_getQuoteRequest_t* getQuoteRequest,
                    const axutil_env_t *env,
                    axis2_char_t*  param_symbol)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                if(!getQuoteRequest)
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
                getQuoteRequest-> attrib_symbol = param_symbol;
                return AXIS2_SUCCESS;
             }

            

