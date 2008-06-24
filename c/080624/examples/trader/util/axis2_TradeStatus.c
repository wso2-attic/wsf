
       /**
        * axis2_TradeStatus.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/C version: #axisVersion# #today#
        *
        */

        #include <axis2_TradeStatus.h>
          
              /**
               * This type was generated from the piece of schema that had
               * name = TradeStatus
               * Namespace URI = http://www.wso2.org/types
               * Namespace Prefix = ns1
               */
             


        struct axis2_TradeStatus
        {
            axis2_bool_t attrib_status;
            axis2_char_t* attrib_reason;
            
        };


       /************************* Function Implmentations ********************************/
        AXIS2_EXTERN axis2_TradeStatus_t* AXIS2_CALL
        axis2_TradeStatus_create(
            const axutil_env_t *env )
        {
            axis2_TradeStatus_t *TradeStatus = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            TradeStatus = (axis2_TradeStatus_t *) AXIS2_MALLOC(env->
                allocator, sizeof(axis2_TradeStatus_t));

            if(NULL == TradeStatus)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            

            return TradeStatus;
         }

        axis2_status_t AXIS2_CALL
        axis2_TradeStatus_free (
                axis2_TradeStatus_t* TradeStatus,
                const axutil_env_t *env)
        {
            
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

            

            if(TradeStatus)
            {
                AXIS2_FREE( env->allocator, TradeStatus);
                TradeStatus = NULL;
            }
            return AXIS2_SUCCESS;
        }

        

        axis2_status_t AXIS2_CALL
        axis2_TradeStatus_deserialize(
                axis2_TradeStatus_t* TradeStatus,
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
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL elemenet for TradeStatus"
                                              " %d :: %s", env->error->error_number,
                                              AXIS2_ERROR_GET_MESSAGE(env->error));
                return AXIS2_FAILURE;
              }
            
                first_node = parent;
              

                     
                     /**
                      * building status element
                      */
                     
                     
                     
                                   current_node = first_node;
                                 
                           if ( current_node != NULL)
                           {
                              current_element = axiom_node_get_data_element( current_node, env);
                                      text_value = axiom_element_get_text(current_element, env, current_node );
                                         
                                                 if ( !strcmp ( text_value , "true" ) || !strcmp ( text_value, "TRUE") )
                                                {
                                                    status = axis2_TradeStatus_set_status( TradeStatus, env,
                                                                      AXIS2_TRUE);
                                                }
                                                else
                                                {
                                                    status = axis2_TradeStatus_set_status( TradeStatus, env,
                                                                      AXIS2_FALSE);
                                                }
                                             
                                 if( AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for status "
                                                         " %d :: %s", env->error->error_number,
                                                         AXIS2_ERROR_GET_MESSAGE(env->error));
                                     return AXIS2_FAILURE;
                                 }
                           }
                           
                               else
                               {
                                   /** this is not a nillable element*/
                                   AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "non nillable or minOuccrs != 0 element status missing"
                                                         " %d :: %s", env->error->error_number,
                                                         AXIS2_ERROR_GET_MESSAGE(env->error));
                                   return AXIS2_FAILURE;
                               }
                           

                     
                     /**
                      * building reason element
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
                                      status = axis2_TradeStatus_set_reason( TradeStatus, env,
                                                                   text_value);
                                    
                                 if( AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for reason "
                                                         " %d :: %s", env->error->error_number,
                                                         AXIS2_ERROR_GET_MESSAGE(env->error));
                                     return AXIS2_FAILURE;
                                 }
                           }
                           
                               else
                               {
                                   /** this is not a nillable element*/
                                   AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "non nillable or minOuccrs != 0 element reason missing"
                                                         " %d :: %s", env->error->error_number,
                                                         AXIS2_ERROR_GET_MESSAGE(env->error));
                                   return AXIS2_FAILURE;
                               }
                            

          return status;
       }

        axiom_node_t* AXIS2_CALL
        axis2_TradeStatus_serialize(
                axis2_TradeStatus_t* TradeStatus,
                const axutil_env_t *env, axiom_node_t* parent, int has_parent)
        {
            
            axiom_namespace_t *ns1 = NULL;
            
                    axis2_char_t text_value_1[64];
                    
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
                      * parsing status element
                      */
                     

                    
                    
                        start_input_str = "<ns1:status>";
                        start_input_str_len = axutil_strlen(start_input_str);
                        end_input_str = "</ns1:status>";
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy( text_value_1, (TradeStatus->attrib_status)?"true":"false" );
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           axutil_stream_write(stream, env, text_value_1, axutil_strlen(text_value_1));
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                        
                     
                     /**
                      * parsing reason element
                      */
                     

                    
                    
                        start_input_str = "<ns1:reason>";
                        start_input_str_len = axutil_strlen(start_input_str);
                        end_input_str = "</ns1:reason>";
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_2 = TradeStatus->attrib_reason;
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           axutil_stream_write(stream, env, text_value_2, axutil_strlen(text_value_2));
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                        
            return parent;
        }

        

            /**
             * getter for status.
             */
            axis2_bool_t AXIS2_CALL
            axis2_TradeStatus_get_status(
                    axis2_TradeStatus_t* TradeStatus,
                    const axutil_env_t *env)
             {
                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

                return TradeStatus-> attrib_status;
             }

            /**
             * setter for status
             */
            axis2_status_t AXIS2_CALL
            axis2_TradeStatus_set_status(
                    axis2_TradeStatus_t* TradeStatus,
                    const axutil_env_t *env,
                    axis2_bool_t  param_status)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                if(!TradeStatus)
                {
                    return AXIS2_FAILURE;
                }

                TradeStatus-> attrib_status = param_status;
                return AXIS2_SUCCESS;
             }

            

            /**
             * getter for reason.
             */
            axis2_char_t* AXIS2_CALL
            axis2_TradeStatus_get_reason(
                    axis2_TradeStatus_t* TradeStatus,
                    const axutil_env_t *env)
             {
                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

                return TradeStatus-> attrib_reason;
             }

            /**
             * setter for reason
             */
            axis2_status_t AXIS2_CALL
            axis2_TradeStatus_set_reason(
                    axis2_TradeStatus_t* TradeStatus,
                    const axutil_env_t *env,
                    axis2_char_t*  param_reason)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                if(!TradeStatus)
                {
                    return AXIS2_FAILURE;
                }

                
                  if( NULL == param_reason )
                  {
                      AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "reason is NULL, but not a nullable element"
                                                 " %d :: %s", env->error->error_number,
                                                 AXIS2_ERROR_GET_MESSAGE(env->error));
                      return AXIS2_FAILURE;
                  }
                TradeStatus-> attrib_reason = param_reason;
                return AXIS2_SUCCESS;
             }

            

