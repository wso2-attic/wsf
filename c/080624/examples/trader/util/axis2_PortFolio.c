
       /**
        * axis2_PortFolio.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/C version: #axisVersion# #today#
        *
        */

        #include <axis2_PortFolio.h>
          
              /**
               * This type was generated from the piece of schema that had
               * name = PortFolio
               * Namespace URI = http://www.wso2.org/types
               * Namespace Prefix = ns1
               */
             


        struct axis2_PortFolio
        {
            axutil_array_list_t* attrib_portFolioItem;
            
        };


       /************************* Function Implmentations ********************************/
        AXIS2_EXTERN axis2_PortFolio_t* AXIS2_CALL
        axis2_PortFolio_create(
            const axutil_env_t *env )
        {
            axis2_PortFolio_t *PortFolio = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            PortFolio = (axis2_PortFolio_t *) AXIS2_MALLOC(env->
                allocator, sizeof(axis2_PortFolio_t));

            if(NULL == PortFolio)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            PortFolio->attrib_portFolioItem  = NULL;
                  

            return PortFolio;
         }

        axis2_status_t AXIS2_CALL
        axis2_PortFolio_free (
                axis2_PortFolio_t* PortFolio,
                const axutil_env_t *env)
        {
            
            
                  int i = 0;
                  int count = 0;
                  void *element = NULL;
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

            
                if ( PortFolio->attrib_portFolioItem != NULL)
                {
                    count = axutil_array_list_size( PortFolio->attrib_portFolioItem, env);
                    for( i = 0; i < count; i ++)
                    {
                       element = axutil_array_list_get( PortFolio->attrib_portFolioItem, env, i);
              
              if( element != NULL)
              {
                 
                 
                      axis2_PortFolioItem_free( (axis2_PortFolioItem_t*)element, env);
                   element = NULL;
              }

              
                    }
                    axutil_array_list_free( PortFolio->attrib_portFolioItem, env);
                }
              

            if(PortFolio)
            {
                AXIS2_FREE( env->allocator, PortFolio);
                PortFolio = NULL;
            }
            return AXIS2_SUCCESS;
        }

        

        axis2_status_t AXIS2_CALL
        axis2_PortFolio_deserialize(
                axis2_PortFolio_t* PortFolio,
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
            
               void *element = NULL;
            
             /*axis2_char_t* text_value = NULL;*/
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
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL elemenet for PortFolio"
                                              " %d :: %s", env->error->error_number,
                                              AXIS2_ERROR_GET_MESSAGE(env->error));
                return AXIS2_FAILURE;
              }
            
                first_node = parent;
              
                    /**
                     * building portFolioItem array
                     */
                     
                       arr_list = axutil_array_list_create( env, 10);
                     

                     
                     /**
                      * building portFolioItem element
                      */
                     
                     
                      
                               element_qname = axutil_qname_create( env, "portFolioItem", "","");
                               for ( i = 0, sequence_broken = 0, tmp_node = current_node = first_node; current_node != NULL; current_node = axiom_node_get_next_sibling( current_node, env))
                               {
                                  current_element = axiom_node_get_data_element( current_node, env);
                                  qname = axiom_element_get_qname( current_element, env, current_node);

                                  if ( axutil_qname_equals( element_qname, env, qname) )
                                  {
                                      if( sequence_broken)
                                      {
                                        /** found element out of order */
                                        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "elements found out of order for arrayportFolioItem missing"
                                                         " %d :: %s", env->error->error_number,
                                                         AXIS2_ERROR_GET_MESSAGE(env->error));
                                        return AXIS2_FAILURE;
                                      }
                                      tmp_node = current_node; /** always update the current node */
                                      element_found = 1;
                                      
                                     
                                          element = (void*)axis2_PortFolioItem_create( env);
                                          status =  axis2_PortFolioItem_deserialize( ( axis2_PortFolioItem_t*)element, env,
                                                                             axiom_node_get_first_child(current_node, env)==NULL?current_node:axiom_node_get_first_child(current_node, env));
                                          if( AXIS2_FAILURE ==  status)
                                          {
                                              AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building element portFolioItem "
                                                                  " %d :: %s", env->error->error_number,
                                                                  AXIS2_ERROR_GET_MESSAGE(env->error));
                                              return AXIS2_FAILURE;
                                          }
                                          axutil_array_list_add_at( arr_list, env, i, element);
                                        
                                     if( AXIS2_FAILURE ==  status)
                                     {
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for portFolioItem "
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
                               status = axis2_PortFolio_set_portFolioItem( PortFolio, env,
                                                                   arr_list);

                              

          return status;
       }

        axiom_node_t* AXIS2_CALL
        axis2_PortFolio_serialize(
                axis2_PortFolio_t* PortFolio,
                const axutil_env_t *env, axiom_node_t* parent, int has_parent)
        {
            
            axiom_namespace_t *ns1 = NULL;
            
               long i = 0;
               long count = 0;
               void *element = NULL;
             
                    /*axis2_char_t text_value_1[64];*/
                    
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
                      * parsing portFolioItem array
                      */
                     if ( PortFolio->attrib_portFolioItem != NULL)
                     {
                         start_input_str = "<ns1:portFolioItem xmlns:ns1=\"http://www.wso2.org/types\">";
                         start_input_str_len = axutil_strlen(start_input_str);
                         end_input_str = "</ns1:portFolioItem>";
                         end_input_str_len = axutil_strlen(end_input_str);
                         count = axutil_array_list_size( PortFolio->attrib_portFolioItem, env);
                         for( i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get( PortFolio->attrib_portFolioItem, env, i);
                    
                     
                     /**
                      * parsing portFolioItem element
                      */
                     

                    
                    
                            axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                            axis2_PortFolioItem_serialize( (axis2_PortFolioItem_t*)element, env, current_node, AXIS2_TRUE);
                            axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                        
                         }
                     }
                   
            return parent;
        }

        

            /**
             * getter for portFolioItem.
             */
            axutil_array_list_t* AXIS2_CALL
            axis2_PortFolio_get_portFolioItem(
                    axis2_PortFolio_t* PortFolio,
                    const axutil_env_t *env)
             {
                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

                return PortFolio-> attrib_portFolioItem;
             }

            /**
             * setter for portFolioItem
             */
            axis2_status_t AXIS2_CALL
            axis2_PortFolio_set_portFolioItem(
                    axis2_PortFolio_t* PortFolio,
                    const axutil_env_t *env,
                    axutil_array_list_t*  param_portFolioItem)
             {
                
                 int size = 0;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                if(!PortFolio)
                {
                    return AXIS2_FAILURE;
                }

                
                  size = axutil_array_list_size( param_portFolioItem, env);
                  
                  if ( size < 0 )
                  {
                      AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "portFolioItem has less than minOccurs(0)"
                                                 " %d :: %s", env->error->error_number,
                                                 AXIS2_ERROR_GET_MESSAGE(env->error));
                      return AXIS2_FAILURE;
                  }
                PortFolio-> attrib_portFolioItem = param_portFolioItem;
                return AXIS2_SUCCESS;
             }

            
            /**
             * resetter for portFolioItem
             */
            axis2_status_t AXIS2_CALL
            axis2_PortFolio_reset_portFolioItem(
                    axis2_PortFolio_t* PortFolio,
                    const axutil_env_t *env)
             {
                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                if(!PortFolio)
                {
                    return AXIS2_FAILURE;
                }
                PortFolio-> attrib_portFolioItem = NULL;
                return AXIS2_SUCCESS;
             }
            

