

        /**
         * TraderClient.cpp
         *
         * This file was auto-generated from WSDL for "TraderClient|http://www.wso2.org" service
         * by the Apache Axis2 version: #axisVersion# #today#
         *  TraderClient
         */

        #include "TraderClientSkeleton.h"
        #include "TraderClient.h"  
        #include <ServiceSkeleton.h>
        #include <stdio.h>
        #include <axis2_svc.h>
        #include <Environment.h>
        #include <axiom_soap.h>


        using namespace wso2wsf;
        
        using namespace org_wso2_www;
        

        /** Load the service into axis2 engine */
        WSF_SERVICE_INIT(TraderClient)

          
         /**
          * function to free any soap input headers
          */
         TraderClient::TraderClient()
	{
          skel = wsfGetTraderClientSkeleton();
    }


	bool WSF_CALL
	TraderClient::init()
	{

      return true;
	}


	TraderClient::~TraderClient()
	{
    }


     

     




	/*
	 * This method invokes the right service method
	 */
	OMElement* WSF_CALL
	TraderClient::invoke(OMElement *omEle, MessageContext *msgCtx)
	{
         /* Using the function name, invoke the corresponding method
          */

          axis2_op_ctx_t *operation_ctx = NULL;
          axis2_op_t *operation = NULL;
          axutil_qname_t *op_qname = NULL;
          axis2_char_t *op_name = NULL;
          axis2_msg_ctx_t *in_msg_ctx = NULL;
          
          axiom_soap_envelope_t *req_soap_env = NULL;
          axiom_soap_header_t *req_soap_header = NULL;
          axiom_soap_envelope_t *res_soap_env = NULL;
          axiom_soap_header_t *res_soap_header = NULL;

          axiom_node_t *ret_node = NULL;
          axiom_node_t *input_header = NULL;
          axiom_node_t *output_header = NULL;
          axiom_node_t *header_base_node = NULL;
          axis2_msg_ctx_t *msg_ctx = NULL;
          axiom_node_t* content_node = omEle->getAxiomNode();

          
            org_wso2_www_types::DepositResponse* ret_val1;
            org_wso2_www_types::DepositRequest* input_val1;
            
            org_wso2_www_types::GetSymbolsResponse* ret_val2;
            org_wso2_www_types::GetSymbolsRequest* input_val2;
            
            org_wso2_www_types::GetQuoteResponse* ret_val3;
            org_wso2_www_types::GetQuoteRequest* input_val3;
            
            org_wso2_www_types::CreateAccountResponse* ret_val4;
            org_wso2_www_types::CreateAccountRequest* input_val4;
            
            org_wso2_www_types::SellResponse* ret_val5;
            org_wso2_www_types::SellRequest* input_val5;
            
            org_wso2_www_types::BuyResponse* ret_val6;
            org_wso2_www_types::BuyRequest* input_val6;
            
            org_wso2_www_types::GetPortfolioResponse* ret_val7;
            org_wso2_www_types::GetPortfolioRequest* input_val7;
            
       
          msg_ctx = msgCtx->getAxis2MessageContext();
          operation_ctx = axis2_msg_ctx_get_op_ctx(msg_ctx, Environment::getEnv());
          operation = axis2_op_ctx_get_op(operation_ctx, Environment::getEnv());
          op_qname = (axutil_qname_t *)axis2_op_get_qname(operation, Environment::getEnv());
          op_name = axutil_qname_get_localpart(op_qname, Environment::getEnv());

          if (op_name)
          {
               

                if ( axutil_strcmp(op_name, "deposit") == 0 )
                {

                    
                    input_val1 =
                        
                        new org_wso2_www_types::DepositRequest();
                        if( AXIS2_FAILURE ==  input_val1->deserialize(&content_node, NULL, false))
                        {
                                        
                            AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "NULL returned from the org_wso2_www_types::DepositRequest_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        //TraderClientSkeleton skel;
                        ret_val1 =  skel->deposit(msgCtx ,input_val1);
                    
                        if ( NULL == ret_val1 )
                        {
                            
                                delete input_val1;
                            
                            return NULL; 
                        }
                        ret_node = 
                                            ret_val1->serialize(NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                            delete ret_val1;
                                        
                                            delete input_val1;
                                        

                        return new OMElement(NULL,ret_node);
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getSymbols") == 0 )
                {

                    
                    input_val2 =
                        
                        new org_wso2_www_types::GetSymbolsRequest();
                        if( AXIS2_FAILURE ==  input_val2->deserialize(&content_node, NULL, false))
                        {
                                        
                            AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "NULL returned from the org_wso2_www_types::GetSymbolsRequest_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        //TraderClientSkeleton skel;
                        ret_val2 =  skel->getSymbols(msgCtx ,input_val2);
                    
                        if ( NULL == ret_val2 )
                        {
                            
                                delete input_val2;
                            
                            return NULL; 
                        }
                        ret_node = 
                                            ret_val2->serialize(NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                            delete ret_val2;
                                        
                                            delete input_val2;
                                        

                        return new OMElement(NULL,ret_node);
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getQuote") == 0 )
                {

                    
                    input_val3 =
                        
                        new org_wso2_www_types::GetQuoteRequest();
                        if( AXIS2_FAILURE ==  input_val3->deserialize(&content_node, NULL, false))
                        {
                                        
                            AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "NULL returned from the org_wso2_www_types::GetQuoteRequest_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        //TraderClientSkeleton skel;
                        ret_val3 =  skel->getQuote(msgCtx ,input_val3);
                    
                        if ( NULL == ret_val3 )
                        {
                            
                                delete input_val3;
                            
                            return NULL; 
                        }
                        ret_node = 
                                            ret_val3->serialize(NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                            delete ret_val3;
                                        
                                            delete input_val3;
                                        

                        return new OMElement(NULL,ret_node);
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "createAccount") == 0 )
                {

                    
                    input_val4 =
                        
                        new org_wso2_www_types::CreateAccountRequest();
                        if( AXIS2_FAILURE ==  input_val4->deserialize(&content_node, NULL, false))
                        {
                                        
                            AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "NULL returned from the org_wso2_www_types::CreateAccountRequest_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        //TraderClientSkeleton skel;
                        ret_val4 =  skel->createAccount(msgCtx ,input_val4);
                    
                        if ( NULL == ret_val4 )
                        {
                            
                                delete input_val4;
                            
                            return NULL; 
                        }
                        ret_node = 
                                            ret_val4->serialize(NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                            delete ret_val4;
                                        
                                            delete input_val4;
                                        

                        return new OMElement(NULL,ret_node);
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "sell") == 0 )
                {

                    
                    input_val5 =
                        
                        new org_wso2_www_types::SellRequest();
                        if( AXIS2_FAILURE ==  input_val5->deserialize(&content_node, NULL, false))
                        {
                                        
                            AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "NULL returned from the org_wso2_www_types::SellRequest_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        //TraderClientSkeleton skel;
                        ret_val5 =  skel->sell(msgCtx ,input_val5);
                    
                        if ( NULL == ret_val5 )
                        {
                            
                                delete input_val5;
                            
                            return NULL; 
                        }
                        ret_node = 
                                            ret_val5->serialize(NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                            delete ret_val5;
                                        
                                            delete input_val5;
                                        

                        return new OMElement(NULL,ret_node);
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "buy") == 0 )
                {

                    
                    input_val6 =
                        
                        new org_wso2_www_types::BuyRequest();
                        if( AXIS2_FAILURE ==  input_val6->deserialize(&content_node, NULL, false))
                        {
                                        
                            AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "NULL returned from the org_wso2_www_types::BuyRequest_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        //TraderClientSkeleton skel;
                        ret_val6 =  skel->buy(msgCtx ,input_val6);
                    
                        if ( NULL == ret_val6 )
                        {
                            
                                delete input_val6;
                            
                            return NULL; 
                        }
                        ret_node = 
                                            ret_val6->serialize(NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                            delete ret_val6;
                                        
                                            delete input_val6;
                                        

                        return new OMElement(NULL,ret_node);
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getPortfolio") == 0 )
                {

                    
                    input_val7 =
                        
                        new org_wso2_www_types::GetPortfolioRequest();
                        if( AXIS2_FAILURE ==  input_val7->deserialize(&content_node, NULL, false))
                        {
                                        
                            AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "NULL returned from the org_wso2_www_types::GetPortfolioRequest_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        //TraderClientSkeleton skel;
                        ret_val7 =  skel->getPortfolio(msgCtx ,input_val7);
                    
                        if ( NULL == ret_val7 )
                        {
                            
                                delete input_val7;
                            
                            return NULL; 
                        }
                        ret_node = 
                                            ret_val7->serialize(NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                            delete ret_val7;
                                        
                                            delete input_val7;
                                        

                        return new OMElement(NULL,ret_node);
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             
             }
            
          AXIS2_LOG_ERROR(Environment::getEnv()->log, AXIS2_LOG_SI, "TraderClient service ERROR: invalid OM parameters in request\n");
          return NULL;
    }

    OMElement* WSF_CALL
    TraderClient::onFault(OMElement* omEle)
	{
		axiom_node_t *error_node = NULL;
		axiom_element_t *error_ele = NULL;
        axutil_error_codes_t error_code;
        axiom_node_t *node = omEle->getAxiomNode();
        error_code = (axutil_error_codes_t)Environment::getEnv()->error->error_number;

        if(error_code <= TRADERCLIENTSKELETON_ERROR_NONE ||
                error_code >= TRADERCLIENTSKELETON_ERROR_LAST )
        {
            error_ele = axiom_element_create(Environment::getEnv(), node, "fault", NULL,
                            &error_node);
            axiom_element_set_text(error_ele, Environment::getEnv(), "TraderClient|http://www.wso2.org failed",
                            error_node);
        }
        

		return new OMElement(NULL,error_node);
	}

    

