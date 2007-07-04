
       /**
        * axis2_ClientInfo.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/C version: #axisVersion# #today#
        *
        */

        #include <axis2_ClientInfo.h>
          
              /**
               * This type was generated from the piece of schema that had
               * name = ClientInfo
               * Namespace URI = http://www.wso2.org/types
               * Namespace Prefix = ns1
               */
             


        struct axis2_ClientInfo
        {
            axis2_char_t* attrib_name;
            axis2_char_t* attrib_ssn;
            
        };


       /************************* Function Implmentations ********************************/
        AXIS2_EXTERN axis2_ClientInfo_t* AXIS2_CALL
        axis2_ClientInfo_create(
            const axutil_env_t *env )
        {
            axis2_ClientInfo_t *ClientInfo = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            ClientInfo = (axis2_ClientInfo_t *) AXIS2_MALLOC(env->
                allocator, sizeof(axis2_ClientInfo_t));

            if(NULL == ClientInfo)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            

            return ClientInfo;
         }

        axis2_status_t AXIS2_CALL
        axis2_ClientInfo_free (
                axis2_ClientInfo_t* ClientInfo,
                const axutil_env_t *env)
        {
            
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

            

            if(ClientInfo)
            {
                AXIS2_FREE( env->allocator, ClientInfo);
                ClientInfo = NULL;
            }
            return AXIS2_SUCCESS;
        }

        

        axis2_status_t AXIS2_CALL
        axis2_ClientInfo_deserialize(
                axis2_ClientInfo_t* ClientInfo,
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
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL elemenet for ClientInfo"
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
                                      status = axis2_ClientInfo_set_name( ClientInfo, env,
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
                      * building ssn element
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
                                      status = axis2_ClientInfo_set_ssn( ClientInfo, env,
                                                                   text_value);
                                    
                                 if( AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for ssn "
                                                         " %d :: %s", env->error->error_number,
                                                         AXIS2_ERROR_GET_MESSAGE(env->error));
                                     return AXIS2_FAILURE;
                                 }
                           }
                           
                               else
                               {
                                   /** this is not a nillable element*/
                                   AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "non nillable or minOuccrs != 0 element ssn missing"
                                                         " %d :: %s", env->error->error_number,
                                                         AXIS2_ERROR_GET_MESSAGE(env->error));
                                   return AXIS2_FAILURE;
                               }
                            

          return status;
       }

        axiom_node_t* AXIS2_CALL
        axis2_ClientInfo_serialize(
                axis2_ClientInfo_t* ClientInfo,
                const axutil_env_t *env, axiom_node_t* parent, int has_parent)
        {
            
            axiom_namespace_t *ns1 = NULL;
            
                    axis2_char_t *text_value_1;
                    
                    axis2_char_t *text_value_2;
                    
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
                    
                           text_value_1 = ClientInfo->attrib_name;
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           axutil_stream_write(stream, env, text_value_1, axutil_strlen(text_value_1));
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                        
                     
                     /**
                      * parsing ssn element
                      */
                     

                    
                    
                        start_input_str = "<ns1:ssn>";
                        start_input_str_len = axutil_strlen(start_input_str);
                        end_input_str = "</ns1:ssn>";
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_2 = ClientInfo->attrib_ssn;
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           axutil_stream_write(stream, env, text_value_2, axutil_strlen(text_value_2));
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                        
            return parent;
        }

        

            /**
             * getter for name.
             */
            axis2_char_t* AXIS2_CALL
            axis2_ClientInfo_get_name(
                    axis2_ClientInfo_t* ClientInfo,
                    const axutil_env_t *env)
             {
                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

                return ClientInfo-> attrib_name;
             }

            /**
             * setter for name
             */
            axis2_status_t AXIS2_CALL
            axis2_ClientInfo_set_name(
                    axis2_ClientInfo_t* ClientInfo,
                    const axutil_env_t *env,
                    axis2_char_t*  param_name)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                if(!ClientInfo)
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
                ClientInfo-> attrib_name = param_name;
                return AXIS2_SUCCESS;
             }

            

            /**
             * getter for ssn.
             */
            axis2_char_t* AXIS2_CALL
            axis2_ClientInfo_get_ssn(
                    axis2_ClientInfo_t* ClientInfo,
                    const axutil_env_t *env)
             {
                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

                return ClientInfo-> attrib_ssn;
             }

            /**
             * setter for ssn
             */
            axis2_status_t AXIS2_CALL
            axis2_ClientInfo_set_ssn(
                    axis2_ClientInfo_t* ClientInfo,
                    const axutil_env_t *env,
                    axis2_char_t*  param_ssn)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                if(!ClientInfo)
                {
                    return AXIS2_FAILURE;
                }

                
                  if( NULL == param_ssn )
                  {
                      AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "ssn is NULL, but not a nullable element"
                                                 " %d :: %s", env->error->error_number,
                                                 AXIS2_ERROR_GET_MESSAGE(env->error));
                      return AXIS2_FAILURE;
                  }
                ClientInfo-> attrib_ssn = param_ssn;
                return AXIS2_SUCCESS;
             }

            

