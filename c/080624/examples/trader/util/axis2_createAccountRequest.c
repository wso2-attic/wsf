
       /**
        * axis2_createAccountRequest.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/C version: #axisVersion# #today#
        *
        */

        #include <axis2_createAccountRequest.h>
          
              /**
               * implmentation of the createAccountRequest|http://www.wso2.org/types element
               */
             


        struct axis2_createAccountRequest
        {
            
                axutil_qname_t* qname;
            axis2_ClientInfo_t* attrib_clientinfo;
            axis2_char_t* attrib_password;
            
        };


       /************************* Function Implmentations ********************************/
        AXIS2_EXTERN axis2_createAccountRequest_t* AXIS2_CALL
        axis2_createAccountRequest_create(
            const axutil_env_t *env )
        {
            axis2_createAccountRequest_t *createAccountRequest = NULL;
            
              axutil_qname_t* qname = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            createAccountRequest = (axis2_createAccountRequest_t *) AXIS2_MALLOC(env->
                allocator, sizeof(axis2_createAccountRequest_t));

            if(NULL == createAccountRequest)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            createAccountRequest->attrib_clientinfo  = NULL;
                  
              qname =  axutil_qname_create (env,
                        "createAccount",
                        "http://www.wso2.org/types",
                        "ns1");

              createAccountRequest->qname = qname;
            

            return createAccountRequest;
         }

        axis2_status_t AXIS2_CALL
        axis2_createAccountRequest_free (
                axis2_createAccountRequest_t* createAccountRequest,
                const axutil_env_t *env)
        {
            
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

            
              if( createAccountRequest->attrib_clientinfo != NULL)
              {
                 
                 
                      axis2_ClientInfo_free( createAccountRequest->attrib_clientinfo, env);
                   createAccountRequest->attrib_clientinfo = NULL;
              }

              
              if(createAccountRequest->qname )
              {
                  axutil_qname_free (createAccountRequest->qname, env);
                  createAccountRequest->qname = NULL;
              }
            

            if(createAccountRequest)
            {
                AXIS2_FREE( env->allocator, createAccountRequest);
                createAccountRequest = NULL;
            }
            return AXIS2_SUCCESS;
        }

          
           axutil_qname_t* AXIS2_CALL
           axis2_createAccountRequest_get_qname (
                   axis2_createAccountRequest_t* createAccountRequest,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

               return createAccountRequest-> qname;
           }
        

        axis2_status_t AXIS2_CALL
        axis2_createAccountRequest_deserialize(
                axis2_createAccountRequest_t* createAccountRequest,
                const axutil_env_t *env,
                axiom_node_t* parent)
        {

            axis2_status_t status = AXIS2_SUCCESS;
            axiom_namespace_t *ns1 = NULL;
            
               void *element = NULL;
            
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
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL elemenet for createAccountRequest"
                                              " %d :: %s", env->error->error_number,
                                              AXIS2_ERROR_GET_MESSAGE(env->error));
                return AXIS2_FAILURE;
              }
            
                    current_element = axiom_node_get_data_element( parent, env);
                    qname = axiom_element_get_qname( current_element, env, parent);
                    if ( axutil_qname_equals( qname, env, createAccountRequest-> qname ) )
                    {
                        first_node = axiom_node_get_first_child( parent, env);
                    }
                    else
                    {
                        first_node = parent;
                    }
                 

                     
                     /**
                      * building clientinfo element
                      */
                     
                     
                     
                                   current_node = first_node;
                                 
                           if ( current_node != NULL)
                           {
                              current_element = axiom_node_get_data_element( current_node, env);
                                      element = (void*)axis2_ClientInfo_create( env);
                                      status =  axis2_ClientInfo_deserialize( ( axis2_ClientInfo_t*)element, env,
                                                                             axiom_node_get_first_child(current_node, env)==NULL?current_node:axiom_node_get_first_child(current_node, env));
                                      if( AXIS2_FAILURE ==  status)
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building element clientinfo "
                                                              " %d :: %s", env->error->error_number,
                                                              AXIS2_ERROR_GET_MESSAGE(env->error));
                                          return AXIS2_FAILURE;
                                      }
                                      status = axis2_createAccountRequest_set_clientinfo( createAccountRequest, env,
                                                                   ( axis2_ClientInfo_t*)element);
                                    
                                 if( AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for clientinfo "
                                                         " %d :: %s", env->error->error_number,
                                                         AXIS2_ERROR_GET_MESSAGE(env->error));
                                     return AXIS2_FAILURE;
                                 }
                           }
                           
                               else
                               {
                                   /** this is not a nillable element*/
                                   AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "non nillable or minOuccrs != 0 element clientinfo missing"
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
                                      status = axis2_createAccountRequest_set_password( createAccountRequest, env,
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
                            

          return status;
       }

        axiom_node_t* AXIS2_CALL
        axis2_createAccountRequest_serialize(
                axis2_createAccountRequest_t* createAccountRequest,
                const axutil_env_t *env, axiom_node_t* parent, int has_parent)
        {
            
            axiom_namespace_t *ns1 = NULL;
            
                    /*axis2_char_t text_value_1[64];*/
                    
                    axis2_char_t *text_value_2;
                    
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
                    current_element = axiom_element_create (env, parent, /*"createAccountRequest"*/"createAccount", ns1 , &current_node);
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
                      * parsing clientinfo element
                      */
                     

                    
                    
                        start_input_str = "<ns1:clientinfo xmlns:ns1=\"http://www.wso2.org/types\">";
                        start_input_str_len = axutil_strlen(start_input_str);
                        end_input_str = "</ns1:clientinfo>";
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                            axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                            axis2_ClientInfo_serialize( createAccountRequest->attrib_clientinfo, env, current_node, AXIS2_TRUE);
                            axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                        
                     
                     /**
                      * parsing password element
                      */
                     

                    
                    
                        start_input_str = "<ns1:password>";
                        start_input_str_len = axutil_strlen(start_input_str);
                        end_input_str = "</ns1:password>";
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_2 = createAccountRequest->attrib_password;
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           axutil_stream_write(stream, env, text_value_2, axutil_strlen(text_value_2));
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                        
            return parent;
        }

        

            /**
             * getter for clientinfo.
             */
            axis2_ClientInfo_t* AXIS2_CALL
            axis2_createAccountRequest_get_clientinfo(
                    axis2_createAccountRequest_t* createAccountRequest,
                    const axutil_env_t *env)
             {
                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

                return createAccountRequest-> attrib_clientinfo;
             }

            /**
             * setter for clientinfo
             */
            axis2_status_t AXIS2_CALL
            axis2_createAccountRequest_set_clientinfo(
                    axis2_createAccountRequest_t* createAccountRequest,
                    const axutil_env_t *env,
                    axis2_ClientInfo_t*  param_clientinfo)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                if(!createAccountRequest)
                {
                    return AXIS2_FAILURE;
                }

                
                  if( NULL == param_clientinfo )
                  {
                      AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "clientinfo is NULL, but not a nullable element"
                                                 " %d :: %s", env->error->error_number,
                                                 AXIS2_ERROR_GET_MESSAGE(env->error));
                      return AXIS2_FAILURE;
                  }
                createAccountRequest-> attrib_clientinfo = param_clientinfo;
                return AXIS2_SUCCESS;
             }

            

            /**
             * getter for password.
             */
            axis2_char_t* AXIS2_CALL
            axis2_createAccountRequest_get_password(
                    axis2_createAccountRequest_t* createAccountRequest,
                    const axutil_env_t *env)
             {
                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

                return createAccountRequest-> attrib_password;
             }

            /**
             * setter for password
             */
            axis2_status_t AXIS2_CALL
            axis2_createAccountRequest_set_password(
                    axis2_createAccountRequest_t* createAccountRequest,
                    const axutil_env_t *env,
                    axis2_char_t*  param_password)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                if(!createAccountRequest)
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
                createAccountRequest-> attrib_password = param_password;
                return AXIS2_SUCCESS;
             }

            

