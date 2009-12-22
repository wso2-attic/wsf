

        /**
         * ExchangeTrader.cpp
         *
         * This file was auto-generated from WSDL for "ExchangeTrader|http://www.wso2.org" service
         * by the Apache Axis2 version: #axisVersion# #today#
         *  ExchangeTrader
         */

        #include "ExchangeTraderSkeleton.h"
        #include "ExchangeTrader.h"  
        #include <ServiceSkeleton.h>
        #include <stdio.h>
        #include <axis2_svc.h>
        #include <Environment.h>
        #include <axiom_soap.h>


        using namespace wso2wsf;
        
        using namespace org_wso2_www;
        

        /** Load the service into axis2 engine */
        WSF_SERVICE_INIT(ExchangeTrader)

          
         /**
          * function to free any soap input headers
          */
         ExchangeTrader::ExchangeTrader()
	{
          skel = wsfGetExchangeTraderSkeleton();
    }


	bool WSF_CALL
	ExchangeTrader::init()
	{
		
      return true;
	}


	ExchangeTrader::~ExchangeTrader()
	{
    }


     

     




	/*
	 * This method invokes the right service method
	 */
	OMElement* WSF_CALL
	ExchangeTrader::invoke(OMElement *omEle, MessageContext *msgCtx)
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

          
            axis2_status_t ret_val1;
            org_wso2_www_types::LoginRequest* input_val1;
            
            org_wso2_www_types::RegisterClientResponse* ret_val2;
            org_wso2_www_types::RegisterClientRequest* input_val2;
            
            axis2_status_t ret_val3;
            org_wso2_www_types::RegisterFeedTargetRequest* input_val3;
            
            axis2_status_t ret_val4;
            org_wso2_www_types::SellRequest_ex* input_val4;
            
            axis2_status_t ret_val5;
            org_wso2_www_types::BuyRequest_ex* input_val5;
            
       
          msg_ctx = msgCtx->getAxis2MessageContext();
          operation_ctx = axis2_msg_ctx_get_op_ctx(msg_ctx, Environment::getEnv());
          operation = axis2_op_ctx_get_op(operation_ctx, Environment::getEnv());
          op_qname = (axutil_qname_t *)axis2_op_get_qname(operation, Environment::getEnv());
          op_name = axutil_qname_get_localpart(op_qname, Environment::getEnv());

          if (op_name)
          {
               

                if ( axutil_strcmp(op_name, "login") == 0 )
                {

                    
                    input_val1 =
                        
                        new org_wso2_www_types::LoginRequest();
                        if( AXIS2_FAILURE ==  input_val1->deserialize(&content_node, NULL, false))
                        {
                                        
                            AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "NULL returned from the org_wso2_www_types::LoginRequest_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val1 =  skel->login(msgCtx ,input_val1);
                    
                        if( AXIS2_FAILURE == ret_val1 )
                        {
                            AXIS2_LOG_ERROR(Environment::getEnv()->log, AXIS2_LOG_SI, "NULL returned from the business logic from login ");
                        }
                        
                           delete input_val1;
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "registerClient") == 0 )
                {

                    
                    input_val2 =
                        
                        new org_wso2_www_types::RegisterClientRequest();
                        if( AXIS2_FAILURE ==  input_val2->deserialize(&content_node, NULL, false))
                        {
                                        
                            AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "NULL returned from the org_wso2_www_types::RegisterClientRequest_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        //ExchangeTraderSkeleton skel;
                        ret_val2 =  skel->registerClient(msgCtx ,input_val2);
                    
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
             

                if ( axutil_strcmp(op_name, "registerFeedTarget") == 0 )
                {

                    
                    input_val3 =
                        
                        new org_wso2_www_types::RegisterFeedTargetRequest();
                        if( AXIS2_FAILURE ==  input_val3->deserialize(&content_node, NULL, false))
                        {
                                        
                            AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "NULL returned from the org_wso2_www_types::RegisterFeedTargetRequest_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        //ExchangeTraderSkeleton skel;
                        ret_val3 =  skel->registerFeedTarget(msgCtx ,input_val3);
                    
                        if( AXIS2_FAILURE == ret_val3 )
                        {
                            AXIS2_LOG_ERROR(Environment::getEnv()->log, AXIS2_LOG_SI, "NULL returnted from the business logic from registerFeedTarget ");
                        }
                        
                           delete input_val3;
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "sell") == 0 )
                {

                    
                    input_val4 =
                        
                        new org_wso2_www_types::SellRequest_ex();
                        if( AXIS2_FAILURE ==  input_val4->deserialize(&content_node, NULL, false))
                        {
                                        
                            AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "NULL returned from the org_wso2_www_types::SellRequest_ex_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        //ExchangeTraderSkeleton skel;
                        ret_val4 =  skel->sell(msgCtx ,input_val4);
                    
                        if( AXIS2_FAILURE == ret_val4 )
                        {
                            AXIS2_LOG_ERROR(Environment::getEnv()->log, AXIS2_LOG_SI, "NULL returnted from the business logic from sell ");
                        }
                        
                           delete input_val4;
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "buy") == 0 )
                {

                    
                    input_val5 =
                        
                        new org_wso2_www_types::BuyRequest_ex();
                        if( AXIS2_FAILURE ==  input_val5->deserialize(&content_node, NULL, false))
                        {
                                        
                            AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "NULL returned from the org_wso2_www_types::BuyRequest_ex_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        //ExchangeTraderSkeleton skel;
                        ret_val5 =  skel->buy(msgCtx ,input_val5);
                    
                        if( AXIS2_FAILURE == ret_val5 )
                        {
                            AXIS2_LOG_ERROR(Environment::getEnv()->log, AXIS2_LOG_SI, "NULL returnted from the business logic from buy ");
                        }
                        
                           delete input_val5;
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             
             }
            
          AXIS2_LOG_ERROR(Environment::getEnv()->log, AXIS2_LOG_SI, "ExchangeTrader service ERROR: invalid OM parameters in request\n");
          return NULL;
    }

    OMElement* WSF_CALL
    ExchangeTrader::onFault(OMElement* omEle)
	{
		axiom_node_t *error_node = NULL;
		axiom_element_t *error_ele = NULL;
        axutil_error_codes_t error_code;
        axiom_node_t *node = omEle->getAxiomNode();
        error_code = (axutil_error_codes_t)Environment::getEnv()->error->error_number;

        if(error_code <= EXCHANGETRADERSKELETON_ERROR_NONE ||
                error_code >= EXCHANGETRADERSKELETON_ERROR_LAST )
        {
            error_ele = axiom_element_create(Environment::getEnv(), node, "fault", NULL,
                            &error_node);
            axiom_element_set_text(error_ele, Environment::getEnv(), "ExchangeTrader|http://www.wso2.org failed",
                            error_node);
        }
        

		return new OMElement(NULL,error_node);
	}

    

