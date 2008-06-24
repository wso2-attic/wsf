
       /**
        * axis2_depositRequest.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/C version: #axisVersion# #today#
        *
        */

        #include <axis2_depositRequest.h>
          
              /**
               * implmentation of the depositRequest|http://www.wso2.org/types element
               */
             


        struct axis2_depositRequest
        {
            
                axutil_qname_t* qname;
            axis2_char_t* attrib_useridr;
            axis2_char_t* attrib_password;
            float attrib_amount;
            
        };


       /************************* Function Implmentations ********************************/
        AXIS2_EXTERN axis2_depositRequest_t* AXIS2_CALL
        axis2_depositRequest_create(
            const axutil_env_t *env )
        {
            axis2_depositRequest_t *depositRequest = NULL;
            
              axutil_qname_t* qname = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            depositRequest = (axis2_depositRequest_t *) AXIS2_MALLOC(env->
                allocator, sizeof(axis2_depositRequest_t));

            if(NULL == depositRequest)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            
              qname =  axutil_qname_create (env,
                        "depositRequest",
                        "http://www.wso2.org/types",
                        "ns1");

              depositRequest->qname = qname;
            

            return depositRequest;
         }

        axis2_status_t AXIS2_CALL
        axis2_depositRequest_free (
                axis2_depositRequest_t* depositRequest,
                const axutil_env_t *env)
        {
            
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

            
              if(depositRequest->qname )
              {
                  axutil_qname_free (depositRequest->qname, env);
                  depositRequest->qname = NULL;
              }
            

            if(depositRequest)
            {
                AXIS2_FREE( env->allocator, depositRequest);
                depositRequest = NULL;
            }
            return AXIS2_SUCCESS;
        }

          
           axutil_qname_t* AXIS2_CALL
           axis2_depositRequest_get_qname (
                   axis2_depositRequest_t* depositRequest,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

               return depositRequest-> qname;
           }
        

        axis2_status_t AXIS2_CALL
        axis2_depositRequest_deserialize(
                axis2_depositRequest_t* depositRequest,
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
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL elemenet for depositRequest"
                                              " %d :: %s", env->error->error_number,
                                              AXIS2_ERROR_GET_MESSAGE(env->error));
                return AXIS2_FAILURE;
              }
            
                    current_element = axiom_node_get_data_element( parent, env);
                    qname = axiom_element_get_qname( current_element, env, parent);
                    if ( axutil_qname_equals( qname, env, depositRequest-> qname ) )
                    {
                        first_node = axiom_node_get_first_child( parent, env);
                    }
                    else
                    {
                        first_node = parent;
                    }
                 

                     
                     /**
                      * building useridr element
                      */
                     
                     
                     
                                   current_node = first_node;
                                 
                           if ( current_node != NULL)
                           {
                              current_element = axiom_node_get_data_element( current_node, env);
                                      text_value = axiom_element_get_text(current_element, env, current_node );
                                      status = axis2_depositRequest_set_useridr( depositRequest, env,
                                                                   text_value);
                                    
                                 if( AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for useridr "
                                                         " %d :: %s", env->error->error_number,
                                                         AXIS2_ERROR_GET_MESSAGE(env->error));
                                     return AXIS2_FAILURE;
                                 }
                           }
                           
                               else
                               {
                                   /** this is not a nillable element*/
                                   AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "non nillable or minOuccrs != 0 element useridr missing"
                                                         " %d :: %s", env->error->error_number,
                                                         AXIS2_ERROR_GET_MESSAGE(env->error));
                                   return AXIS2_FAILURE;
                               }
                           

                     
                     /**
                      * building password element
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
                                      status = axis2_depositRequest_set_password( depositRequest, env,
                                                                   text_value);
                                    
                                 if( AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for password "
                                                         " %d :: %s", env->error->error_number,
                                                         AXIS2_ERROR_GET_MESSAGE(env->error));
                                     return AXIS2_FAILURE;
                                 }
                           }
                           
                               else
                               {
                                   /** this is not a nillable element*/
                                   AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "non nillable or minOuccrs != 0 element password missing"
                                                         " %d :: %s", env->error->error_number,
                                                         AXIS2_ERROR_GET_MESSAGE(env->error));
                                   return AXIS2_FAILURE;
                               }
                           

                     
                     /**
                      * building amount element
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
                                      
                                      status = axis2_depositRequest_set_amount( depositRequest, env,
                                                                     atof( text_value));
                                        
                                 if( AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for amount "
                                                         " %d :: %s", env->error->error_number,
                                                         AXIS2_ERROR_GET_MESSAGE(env->error));
                                     return AXIS2_FAILURE;
                                 }
                           }
                           
                               else
                               {
                                   /** this is not a nillable element*/
                                   AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "non nillable or minOuccrs != 0 element amount missing"
                                                         " %d :: %s", env->error->error_number,
                                                         AXIS2_ERROR_GET_MESSAGE(env->error));
                                   return AXIS2_FAILURE;
                               }
                            

          return status;
       }

        axiom_node_t* AXIS2_CALL
        axis2_depositRequest_serialize(
                axis2_depositRequest_t* depositRequest,
                const axutil_env_t *env, axiom_node_t* parent, int has_parent)
        {
            
            axiom_namespace_t *ns1 = NULL;
            
                    axis2_char_t *text_value_1;
                    
                    axis2_char_t *text_value_2;
                    
                    axis2_char_t text_value_3[64];
                    
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
                    current_element = axiom_element_create (env, parent, "depositRequest", ns1 , &current_node);
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
                      * parsing useridr element
                      */
                     

                    
                    
                        start_input_str = "<ns1:useridr>";
                        start_input_str_len = axutil_strlen(start_input_str);
                        end_input_str = "</ns1:useridr>";
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_1 = depositRequest->attrib_useridr;
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           axutil_stream_write(stream, env, text_value_1, axutil_strlen(text_value_1));
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                        
                     
                     /**
                      * parsing password element
                      */
                     

                    
                    
                        start_input_str = "<ns1:password>";
                        start_input_str_len = axutil_strlen(start_input_str);
                        end_input_str = "</ns1:password>";
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_2 = depositRequest->attrib_password;
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           axutil_stream_write(stream, env, text_value_2, axutil_strlen(text_value_2));
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                        
                     
                     /**
                      * parsing amount element
                      */
                     

                    
                    
                        start_input_str = "<ns1:amount>";
                        start_input_str_len = axutil_strlen(start_input_str);
                        end_input_str = "</ns1:amount>";
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                               sprintf ( text_value_3, "%f", depositRequest->attrib_amount );
                             
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           axutil_stream_write(stream, env, text_value_3, axutil_strlen(text_value_3));
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                        
            return parent;
        }

        

            /**
             * getter for useridr.
             */
            axis2_char_t* AXIS2_CALL
            axis2_depositRequest_get_useridr(
                    axis2_depositRequest_t* depositRequest,
                    const axutil_env_t *env)
             {
                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

                return depositRequest-> attrib_useridr;
             }

            /**
             * setter for useridr
             */
            axis2_status_t AXIS2_CALL
            axis2_depositRequest_set_useridr(
                    axis2_depositRequest_t* depositRequest,
                    const axutil_env_t *env,
                    axis2_char_t*  param_useridr)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                if(!depositRequest)
                {
                    return AXIS2_FAILURE;
                }

                
                  if( NULL == param_useridr )
                  {
                      AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "useridr is NULL, but not a nullable element"
                                                 " %d :: %s", env->error->error_number,
                                                 AXIS2_ERROR_GET_MESSAGE(env->error));
                      return AXIS2_FAILURE;
                  }
                depositRequest-> attrib_useridr = param_useridr;
                return AXIS2_SUCCESS;
             }

            

            /**
             * getter for password.
             */
            axis2_char_t* AXIS2_CALL
            axis2_depositRequest_get_password(
                    axis2_depositRequest_t* depositRequest,
                    const axutil_env_t *env)
             {
                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

                return depositRequest-> attrib_password;
             }

            /**
             * setter for password
             */
            axis2_status_t AXIS2_CALL
            axis2_depositRequest_set_password(
                    axis2_depositRequest_t* depositRequest,
                    const axutil_env_t *env,
                    axis2_char_t*  param_password)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                if(!depositRequest)
                {
                    return AXIS2_FAILURE;
                }

                
                  if( NULL == param_password )
                  {
                      AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "password is NULL, but not a nullable element"
                                                 " %d :: %s", env->error->error_number,
                                                 AXIS2_ERROR_GET_MESSAGE(env->error));
                      return AXIS2_FAILURE;
                  }
                depositRequest-> attrib_password = param_password;
                return AXIS2_SUCCESS;
             }

            

            /**
             * getter for amount.
             */
            float AXIS2_CALL
            axis2_depositRequest_get_amount(
                    axis2_depositRequest_t* depositRequest,
                    const axutil_env_t *env)
             {
                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

                return depositRequest-> attrib_amount;
             }

            /**
             * setter for amount
             */
            axis2_status_t AXIS2_CALL
            axis2_depositRequest_set_amount(
                    axis2_depositRequest_t* depositRequest,
                    const axutil_env_t *env,
                    float  param_amount)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                if(!depositRequest)
                {
                    return AXIS2_FAILURE;
                }

                depositRequest-> attrib_amount = param_amount;
                return AXIS2_SUCCESS;
             }

            

