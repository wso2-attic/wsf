

        /**
         * GetPortfolioResponse.cpp
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "GetPortfolioResponse.h"
        #include <Environment.h>
        #include <WSFError.h>


        using namespace wso2wsf;
        using namespace std;
        
        using namespace org_wso2_www_types;
        
               /*
                * Implementation of the getPortfolioResponse|http://www.wso2.org/types Element
                */
           org_wso2_www_types::GetPortfolioResponse::GetPortfolioResponse()
        {

        
            qname = NULL;
        
                property_PortFolio  = NULL;
              
            isValidPortFolio  = false;
        
                  qname =  axutil_qname_create (Environment::getEnv(),
                        "getPortfolioResponse",
                        "http://www.wso2.org/types",
                        NULL);
                
        }

       org_wso2_www_types::GetPortfolioResponse::GetPortfolioResponse(org_wso2_www_types::PortFolio* arg_PortFolio)
        {
             
                   qname = NULL;
             
               property_PortFolio  = NULL;
             
            isValidPortFolio  = true;
            
                 qname =  axutil_qname_create (Environment::getEnv(),
                       "getPortfolioResponse",
                       "http://www.wso2.org/types",
                       NULL);
               
                    property_PortFolio = arg_PortFolio;
            
        }
        org_wso2_www_types::GetPortfolioResponse::~GetPortfolioResponse()
        {

        }

        

        bool WSF_CALL
        org_wso2_www_types::GetPortfolioResponse::deserialize(axiom_node_t** dp_parent,bool *dp_is_early_node_valid, bool dont_care_minoccurs)
        {
          axiom_node_t *parent = *dp_parent;
          
          bool status = AXIS2_SUCCESS;
           
         const axis2_char_t* text_value = NULL;
         axutil_qname_t *mqname = NULL;
          
            axutil_qname_t *element_qname = NULL; 
            
               axiom_node_t *first_node = NULL;
               bool is_early_node_valid = true;
               axiom_node_t *current_node = NULL;
               axiom_element_t *current_element = NULL;
            
              
              while(parent && axiom_node_get_node_type(parent, Environment::getEnv()) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, Environment::getEnv());
              }
              if (NULL == parent)
              {   
                return AXIS2_FAILURE;
              }
              

                    current_element = (axiom_element_t *)axiom_node_get_data_element(parent, Environment::getEnv());
                    mqname = axiom_element_get_qname(current_element, Environment::getEnv(), parent);
                    if (axutil_qname_equals(mqname, Environment::getEnv(), this->qname))
                    {
                        
                          first_node = axiom_node_get_first_child(parent, Environment::getEnv());
                          
                    }
                    else
                    {
                        WSF_LOG_ERROR_MSG(Environment::getEnv()->log, WSF_LOG_SI,
                              "Failed in building adb object for getPortfolioResponse : "
                              "Expected %s but returned %s",
                              axutil_qname_to_string(qname, Environment::getEnv()),
                              axutil_qname_to_string(mqname, Environment::getEnv()));
                        
                        return AXIS2_FAILURE;
                    }
                    

                     
                     /*
                      * building portFolio element
                      */
                     
                     
                     
                                   current_node = first_node;
                                   is_early_node_valid = false;
                                   
                                   
                                    while(current_node && axiom_node_get_node_type(current_node, Environment::getEnv()) != AXIOM_ELEMENT)
                                    {
                                        current_node = axiom_node_get_next_sibling(current_node, Environment::getEnv());
                                    }
                                    if(current_node != NULL)
                                    {
                                        current_element = (axiom_element_t *)axiom_node_get_data_element(current_node, Environment::getEnv());
                                        mqname = axiom_element_get_qname(current_element, Environment::getEnv(), current_node);
                                    }
                                   
                                 element_qname = axutil_qname_create(Environment::getEnv(), "portFolio", NULL, NULL);
                                 

                           if (isParticle() ||  
                                (current_node   && current_element && (axutil_qname_equals(element_qname, Environment::getEnv(), mqname) || !axutil_strcmp("portFolio", axiom_element_get_localname(current_element, Environment::getEnv())))))
                           {
                              if( current_node   && current_element && (axutil_qname_equals(element_qname, Environment::getEnv(), mqname) || !axutil_strcmp("portFolio", axiom_element_get_localname(current_element, Environment::getEnv()))))
                              {
                                is_early_node_valid = true;
                              }
                              
                                 org_wso2_www_types::PortFolio* element = new org_wso2_www_types::PortFolio();

                                      status =  element->deserialize(&current_node, &is_early_node_valid, false);
                                      if(AXIS2_FAILURE == status)
                                      {
                                          WSF_LOG_ERROR_MSG(Environment::getEnv()->log, WSF_LOG_SI, "failed in building adb object for element portFolio");
                                      }
                                      else
                                      {
                                          status = setPortFolio(element);
                                      }
                                    
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"failed in setting the value for portFolio ");
                                     if(element_qname)
                                     {
                                         axutil_qname_free(element_qname, Environment::getEnv());
                                     }
                                     return AXIS2_FAILURE;
                                 }
                              }
                           
                              else if(!dont_care_minoccurs)
                              {
                                  if(element_qname)
                                  {
                                      axutil_qname_free(element_qname, Environment::getEnv());
                                  }
                                  /* this is not a nillable element*/
				  WSF_LOG_ERROR_MSG(Environment::getEnv()->log,WSF_LOG_SI, "non nillable or minOuccrs != 0 element portFolio missing");
                                  return AXIS2_FAILURE;
                              }
                           
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, Environment::getEnv());
                     element_qname = NULL;
                  }
                 
          return status;
       }

          bool WSF_CALL
          org_wso2_www_types::GetPortfolioResponse::isParticle()
          {
            
                 return false;
              
          }


          void WSF_CALL
          org_wso2_www_types::GetPortfolioResponse::declareParentNamespaces(
                    axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* WSF_CALL
	org_wso2_www_types::GetPortfolioResponse::serialize(axiom_node_t *parent, 
			axiom_element_t *parent_element, 
			int parent_tag_closed, 
			axutil_hash_t *namespaces, 
			int *next_ns_index)
        {
            
            
         
         axiom_node_t *current_node = NULL;
         int tag_closed = 0;

         
         
                axiom_namespace_t *ns1 = NULL;

                axis2_char_t *qname_uri = NULL;
                axis2_char_t *qname_prefix = NULL;
                axis2_char_t *p_prefix = NULL;
            
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

             
                int next_ns_index_value = 0;
             
                    namespaces = axutil_hash_make(Environment::getEnv());
                    next_ns_index = &next_ns_index_value;
                     
                           ns1 = axiom_namespace_create (Environment::getEnv(),
                                             "http://www.wso2.org/types",
                                             "n"); 
                           axutil_hash_set(namespaces, "http://www.wso2.org/types", AXIS2_HASH_KEY_STRING, axutil_strdup(Environment::getEnv(), "n"));
                       
                     
                    parent_element = axiom_element_create (Environment::getEnv(), NULL, "getPortfolioResponse", ns1 , &parent);
                    
                    
                    axiom_element_set_namespace(parent_element, Environment::getEnv(), ns1, parent);


            
                    data_source = axiom_data_source_create(Environment::getEnv(), parent, &current_node);
                    stream = axiom_data_source_get_stream(data_source, Environment::getEnv());
                  
                       p_prefix = NULL;
                      

                   if (!isValidPortFolio)
                   {
                      
                            
                            WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"Nil value found in non-nillable property portFolio");
                            return NULL;
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(Environment::getEnv()->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("portFolio"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(Environment::getEnv()->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("portFolio")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing portFolio element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sportFolio",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sportFolio>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                     
                            if(!property_PortFolio->isParticle())
                            {
                                axutil_stream_write(stream, Environment::getEnv(), start_input_str, start_input_str_len);
                            }
                            property_PortFolio->serialize(current_node, parent_element,
                                                                                 property_PortFolio->isParticle() || false, namespaces, next_ns_index);
                            
                            if(!property_PortFolio->isParticle())
                            {
                                axutil_stream_write(stream, Environment::getEnv(), end_input_str, end_input_str_len);
                            }
                            
                     
                     AXIS2_FREE(Environment::getEnv()->allocator,start_input_str);
                     AXIS2_FREE(Environment::getEnv()->allocator,end_input_str);
                 } 

                 
                   if(namespaces)
                   {
                       axutil_hash_index_t *hi;
                       void *val;
                       for (hi = axutil_hash_first(namespaces, Environment::getEnv()); hi; hi = axutil_hash_next(Environment::getEnv(), hi))
                       {
                           axutil_hash_this(hi, NULL, NULL, &val);
                           AXIS2_FREE(Environment::getEnv()->allocator, val);
                       }
                       axutil_hash_free(namespaces, Environment::getEnv());
                   }
                

            return parent;
        }


        

            /**
             * Getter for portFolio by  Property Number 1
             */
            org_wso2_www_types::PortFolio* WSF_CALL
            org_wso2_www_types::GetPortfolioResponse::getProperty1()
            {
                return getPortFolio();
            }

            /**
             * getter for portFolio.
             */
            org_wso2_www_types::PortFolio* WSF_CALL
            org_wso2_www_types::GetPortfolioResponse::getPortFolio()
             {
                return property_PortFolio;
             }

            /**
             * setter for portFolio
             */
            bool WSF_CALL
            org_wso2_www_types::GetPortfolioResponse::setPortFolio(
                    org_wso2_www_types::PortFolio*  arg_PortFolio)
             {
                

                if(isValidPortFolio &&
                        arg_PortFolio == property_PortFolio)
                {
                    
                    return true;
                }

                
                  if(NULL == arg_PortFolio)
                       
                  {
                      WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"portFolio is being set to NULL, but it is not a nullable element");
                      return AXIS2_FAILURE;
                  }
                

                
                resetPortFolio();

                
                    if(NULL == arg_PortFolio)
                         
                {
                    /* We are already done */
                    return true;
                }
                
                        property_PortFolio = arg_PortFolio;
                        isValidPortFolio = true;
                    
                return true;
             }

             

           /**
            * resetter for portFolio
            */
           bool WSF_CALL
           org_wso2_www_types::GetPortfolioResponse::resetPortFolio()
           {
               int i = 0;
               int count = 0;


               
            
                

                if(property_PortFolio != NULL)
                {
                   
                   
                         delete  property_PortFolio;
                     

                   }

                
                
                
               isValidPortFolio = false; 
               return true;
           }

           /**
            * Check whether portFolio is nill
            */
           bool WSF_CALL
           org_wso2_www_types::GetPortfolioResponse::isPortFolioNil()
           {
               return !isValidPortFolio;
           }

           /**
            * Set portFolio to nill (currently the same as reset)
            */
           bool WSF_CALL
           org_wso2_www_types::GetPortfolioResponse::setPortFolioNil()
           {
               return resetPortFolio();
           }

           

