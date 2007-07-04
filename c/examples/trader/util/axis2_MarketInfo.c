
       /**
        * axis2_MarketInfo.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/C version: #axisVersion# #today#
        *
        */

        #include <axis2_MarketInfo.h>
          
              /**
               * This type was generated from the piece of schema that had
               * name = MarketInfo
               * Namespace URI = http://www.wso2.org/types
               * Namespace Prefix = ns1
               */
             


        struct axis2_MarketInfo
        {
            float attrib_totalTraded;
            float attrib_avgPrice;
            float attrib_avgPriceOfTrade;
            float attrib_marketCap;
            
        };


       /************************* Function Implmentations ********************************/
        AXIS2_EXTERN axis2_MarketInfo_t* AXIS2_CALL
        axis2_MarketInfo_create(
            const axutil_env_t *env )
        {
            axis2_MarketInfo_t *MarketInfo = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            MarketInfo = (axis2_MarketInfo_t *) AXIS2_MALLOC(env->
                allocator, sizeof(axis2_MarketInfo_t));

            if(NULL == MarketInfo)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            

            return MarketInfo;
         }

        axis2_status_t AXIS2_CALL
        axis2_MarketInfo_free (
                axis2_MarketInfo_t* MarketInfo,
                const axutil_env_t *env)
        {
            
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

            

            if(MarketInfo)
            {
                AXIS2_FREE( env->allocator, MarketInfo);
                MarketInfo = NULL;
            }
            return AXIS2_SUCCESS;
        }

        

        axis2_status_t AXIS2_CALL
        axis2_MarketInfo_deserialize(
                axis2_MarketInfo_t* MarketInfo,
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
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL elemenet for MarketInfo"
                                              " %d :: %s", env->error->error_number,
                                              AXIS2_ERROR_GET_MESSAGE(env->error));
                return AXIS2_FAILURE;
              }
            
                first_node = parent;
              

                     
                     /**
                      * building totalTraded element
                      */
                     
                     
                     
                                   current_node = first_node;
                                 
                           if ( current_node != NULL)
                           {
                              current_element = axiom_node_get_data_element( current_node, env);
                                      text_value = axiom_element_get_text(current_element, env, current_node );
                                      
                                      status = axis2_MarketInfo_set_totalTraded( MarketInfo, env,
                                                                     atof( text_value));
                                        
                                 if( AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for totalTraded "
                                                         " %d :: %s", env->error->error_number,
                                                         AXIS2_ERROR_GET_MESSAGE(env->error));
                                     return AXIS2_FAILURE;
                                 }
                           }
                           
                               else
                               {
                                   /** this is not a nillable element*/
                                   AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "non nillable or minOuccrs != 0 element totalTraded missing"
                                                         " %d :: %s", env->error->error_number,
                                                         AXIS2_ERROR_GET_MESSAGE(env->error));
                                   return AXIS2_FAILURE;
                               }
                           

                     
                     /**
                      * building avgPrice element
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
                                      
                                      status = axis2_MarketInfo_set_avgPrice( MarketInfo, env,
                                                                     atof( text_value));
                                        
                                 if( AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for avgPrice "
                                                         " %d :: %s", env->error->error_number,
                                                         AXIS2_ERROR_GET_MESSAGE(env->error));
                                     return AXIS2_FAILURE;
                                 }
                           }
                           
                               else
                               {
                                   /** this is not a nillable element*/
                                   AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "non nillable or minOuccrs != 0 element avgPrice missing"
                                                         " %d :: %s", env->error->error_number,
                                                         AXIS2_ERROR_GET_MESSAGE(env->error));
                                   return AXIS2_FAILURE;
                               }
                           

                     
                     /**
                      * building avgPriceOfTrade element
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
                                      
                                      status = axis2_MarketInfo_set_avgPriceOfTrade( MarketInfo, env,
                                                                     atof( text_value));
                                        
                                 if( AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for avgPriceOfTrade "
                                                         " %d :: %s", env->error->error_number,
                                                         AXIS2_ERROR_GET_MESSAGE(env->error));
                                     return AXIS2_FAILURE;
                                 }
                           }
                           
                               else
                               {
                                   /** this is not a nillable element*/
                                   AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "non nillable or minOuccrs != 0 element avgPriceOfTrade missing"
                                                         " %d :: %s", env->error->error_number,
                                                         AXIS2_ERROR_GET_MESSAGE(env->error));
                                   return AXIS2_FAILURE;
                               }
                           

                     
                     /**
                      * building marketCap element
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
                                      
                                      status = axis2_MarketInfo_set_marketCap( MarketInfo, env,
                                                                     atof( text_value));
                                        
                                 if( AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for marketCap "
                                                         " %d :: %s", env->error->error_number,
                                                         AXIS2_ERROR_GET_MESSAGE(env->error));
                                     return AXIS2_FAILURE;
                                 }
                           }
                           
                               else
                               {
                                   /** this is not a nillable element*/
                                   AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "non nillable or minOuccrs != 0 element marketCap missing"
                                                         " %d :: %s", env->error->error_number,
                                                         AXIS2_ERROR_GET_MESSAGE(env->error));
                                   return AXIS2_FAILURE;
                               }
                            

          return status;
       }

        axiom_node_t* AXIS2_CALL
        axis2_MarketInfo_serialize(
                axis2_MarketInfo_t* MarketInfo,
                const axutil_env_t *env, axiom_node_t* parent, int has_parent)
        {
            
            axiom_namespace_t *ns1 = NULL;
            
                    axis2_char_t text_value_1[64];
                    
                    axis2_char_t text_value_2[64];
                    
                    axis2_char_t text_value_3[64];
                    
                    axis2_char_t text_value_4[64];
                    
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
                      * parsing totalTraded element
                      */
                     

                    
                    
                        start_input_str = "<ns1:totalTraded>";
                        start_input_str_len = axutil_strlen(start_input_str);
                        end_input_str = "</ns1:totalTraded>";
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                               sprintf ( text_value_1, "%f", MarketInfo->attrib_totalTraded );
                             
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           axutil_stream_write(stream, env, text_value_1, axutil_strlen(text_value_1));
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                        
                     
                     /**
                      * parsing avgPrice element
                      */
                     

                    
                    
                        start_input_str = "<ns1:avgPrice>";
                        start_input_str_len = axutil_strlen(start_input_str);
                        end_input_str = "</ns1:avgPrice>";
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                               sprintf ( text_value_2, "%f", MarketInfo->attrib_avgPrice );
                             
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           axutil_stream_write(stream, env, text_value_2, axutil_strlen(text_value_2));
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                        
                     
                     /**
                      * parsing avgPriceOfTrade element
                      */
                     

                    
                    
                        start_input_str = "<ns1:avgPriceOfTrade>";
                        start_input_str_len = axutil_strlen(start_input_str);
                        end_input_str = "</ns1:avgPriceOfTrade>";
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                               sprintf ( text_value_3, "%f", MarketInfo->attrib_avgPriceOfTrade );
                             
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           axutil_stream_write(stream, env, text_value_3, axutil_strlen(text_value_3));
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                        
                     
                     /**
                      * parsing marketCap element
                      */
                     

                    
                    
                        start_input_str = "<ns1:marketCap>";
                        start_input_str_len = axutil_strlen(start_input_str);
                        end_input_str = "</ns1:marketCap>";
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                               sprintf ( text_value_4, "%f", MarketInfo->attrib_marketCap );
                             
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           axutil_stream_write(stream, env, text_value_4, axutil_strlen(text_value_4));
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                        
            return parent;
        }

        

            /**
             * getter for totalTraded.
             */
            float AXIS2_CALL
            axis2_MarketInfo_get_totalTraded(
                    axis2_MarketInfo_t* MarketInfo,
                    const axutil_env_t *env)
             {
                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

                return MarketInfo-> attrib_totalTraded;
             }

            /**
             * setter for totalTraded
             */
            axis2_status_t AXIS2_CALL
            axis2_MarketInfo_set_totalTraded(
                    axis2_MarketInfo_t* MarketInfo,
                    const axutil_env_t *env,
                    float  param_totalTraded)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                if(!MarketInfo)
                {
                    return AXIS2_FAILURE;
                }

                MarketInfo-> attrib_totalTraded = param_totalTraded;
                return AXIS2_SUCCESS;
             }

            

            /**
             * getter for avgPrice.
             */
            float AXIS2_CALL
            axis2_MarketInfo_get_avgPrice(
                    axis2_MarketInfo_t* MarketInfo,
                    const axutil_env_t *env)
             {
                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

                return MarketInfo-> attrib_avgPrice;
             }

            /**
             * setter for avgPrice
             */
            axis2_status_t AXIS2_CALL
            axis2_MarketInfo_set_avgPrice(
                    axis2_MarketInfo_t* MarketInfo,
                    const axutil_env_t *env,
                    float  param_avgPrice)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                if(!MarketInfo)
                {
                    return AXIS2_FAILURE;
                }

                MarketInfo-> attrib_avgPrice = param_avgPrice;
                return AXIS2_SUCCESS;
             }

            

            /**
             * getter for avgPriceOfTrade.
             */
            float AXIS2_CALL
            axis2_MarketInfo_get_avgPriceOfTrade(
                    axis2_MarketInfo_t* MarketInfo,
                    const axutil_env_t *env)
             {
                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

                return MarketInfo-> attrib_avgPriceOfTrade;
             }

            /**
             * setter for avgPriceOfTrade
             */
            axis2_status_t AXIS2_CALL
            axis2_MarketInfo_set_avgPriceOfTrade(
                    axis2_MarketInfo_t* MarketInfo,
                    const axutil_env_t *env,
                    float  param_avgPriceOfTrade)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                if(!MarketInfo)
                {
                    return AXIS2_FAILURE;
                }

                MarketInfo-> attrib_avgPriceOfTrade = param_avgPriceOfTrade;
                return AXIS2_SUCCESS;
             }

            

            /**
             * getter for marketCap.
             */
            float AXIS2_CALL
            axis2_MarketInfo_get_marketCap(
                    axis2_MarketInfo_t* MarketInfo,
                    const axutil_env_t *env)
             {
                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

                return MarketInfo-> attrib_marketCap;
             }

            /**
             * setter for marketCap
             */
            axis2_status_t AXIS2_CALL
            axis2_MarketInfo_set_marketCap(
                    axis2_MarketInfo_t* MarketInfo,
                    const axutil_env_t *env,
                    float  param_marketCap)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                if(!MarketInfo)
                {
                    return AXIS2_FAILURE;
                }

                MarketInfo-> attrib_marketCap = param_marketCap;
                return AXIS2_SUCCESS;
             }

            

