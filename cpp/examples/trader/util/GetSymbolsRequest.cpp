

        /**
         * GetSymbolsRequest.cpp
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "GetSymbolsRequest.h"
        #include <Environment.h>
        #include <WSFError.h>


        using namespace wso2wsf;
        using namespace std;
        
        using namespace org_wso2_www_types;
        
               /*
                * Implementation of the getSymbolsRequest|http://www.wso2.org/types Element
                */
           org_wso2_www_types::GetSymbolsRequest::GetSymbolsRequest()
        {

        
            qname = NULL;
        
                  qname =  axutil_qname_create (Environment::getEnv(),
                        "getSymbolsRequest",
                        "http://www.wso2.org/types",
                        NULL);
                
        }

       org_wso2_www_types::GetSymbolsRequest::~GetSymbolsRequest()
        {

        }

        

        bool WSF_CALL
        org_wso2_www_types::GetSymbolsRequest::deserialize(axiom_node_t** dp_parent,bool *dp_is_early_node_valid, bool dont_care_minoccurs)
        {
          axiom_node_t *parent = *dp_parent;
          
          bool status = AXIS2_SUCCESS;
          
            axutil_qname_t *element_qname = NULL; 
            
          return status;
       }

          bool WSF_CALL
          org_wso2_www_types::GetSymbolsRequest::isParticle()
          {
            
                 return false;
              
          }


          void WSF_CALL
          org_wso2_www_types::GetSymbolsRequest::declareParentNamespaces(
                    axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* WSF_CALL
	org_wso2_www_types::GetSymbolsRequest::serialize(axiom_node_t *parent, 
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
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

             
                int next_ns_index_value = 0;
             
                    namespaces = axutil_hash_make(Environment::getEnv());
                    next_ns_index = &next_ns_index_value;
                     
                           ns1 = axiom_namespace_create (Environment::getEnv(),
                                             "http://www.wso2.org/types",
                                             "n"); 
                           axutil_hash_set(namespaces, "http://www.wso2.org/types", AXIS2_HASH_KEY_STRING, axutil_strdup(Environment::getEnv(), "n"));
                       
                     
                    parent_element = axiom_element_create (Environment::getEnv(), NULL, "getSymbolsRequest", ns1 , &parent);
                    
                    
                    axiom_element_set_namespace(parent_element, Environment::getEnv(), ns1, parent);


            

            return parent;
        }


        

