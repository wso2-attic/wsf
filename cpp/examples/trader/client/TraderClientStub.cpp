
      /**
       * TraderClientStub.cpp
       *
       * This file was auto-generated from WSDL for "TraderClient|http://www.wso2.org" service
       * by the Apache Axis2/Java version: #axisVersion# #today#
       */

      #include "TraderClientStub.h"
      #include "ITraderClientCallback.h"
      #include <axis2_msg.h>
      #include <axis2_policy_include.h>
      #include <neethi_engine.h>
      #include <Stub.h>
      #include <Environment.h>
      #include <WSFError.h>
      
      using namespace std;
      using namespace wso2wsf;
        
      using namespace org_wso2_www;
        
      /**
       * TraderClientStub CPP implementation
       */
       TraderClientStub::TraderClientStub(std::string& clientHome)
        {
                if(clientHome.empty())
                {
                   cout<<"Please specify the client home";
                }
                std::string endpointUri= getEndpointUriOfTraderClient();

                init(clientHome,endpointUri);

                populateServicesForTraderClient();


        }


      TraderClientStub::TraderClientStub(std::string& clientHome,std::string& endpointURI)
      {
         std::string endpointUri;

         if(clientHome.empty())
         {
            cout<<"Please specify the client home";
         }
         endpointUri = endpointURI;

         if (endpointUri.empty())
         {
            endpointUri = getEndpointUriOfTraderClient();
         }


         init(clientHome,endpointUri);

         populateServicesForTraderClient();

      }


      void WSF_CALL
      TraderClientStub::populateServicesForTraderClient()
      {
         axis2_svc_client_t *svc_client = NULL;
         axutil_qname_t *svc_qname =  NULL;
         axutil_qname_t *op_qname =  NULL;
         axis2_svc_t *svc = NULL;
         axis2_op_t *op = NULL;
         axis2_op_t *annon_op = NULL;
         axis2_msg_t *msg_out = NULL;
         axis2_msg_t *msg_in = NULL;
         axis2_msg_t *msg_out_fault = NULL;
         axis2_msg_t *msg_in_fault = NULL;
         axis2_policy_include_t *policy_include = NULL;

         axis2_desc_t *desc = NULL;
         axiom_node_t *policy_node = NULL;
         axiom_element_t *policy_root_ele = NULL;
         neethi_policy_t *neethi_policy = NULL;


         /* Modifying the Service */
	 svc_client = serviceClient->getAxis2SvcClient();
         svc = (axis2_svc_t*)axis2_svc_client_get_svc( svc_client, Environment::getEnv() );

         annon_op = axis2_svc_get_op_with_name(svc, Environment::getEnv(), AXIS2_ANON_OUT_IN_OP);
         msg_out = axis2_op_get_msg(annon_op, Environment::getEnv(), AXIS2_MSG_OUT);
         msg_in = axis2_op_get_msg(annon_op, Environment::getEnv(), AXIS2_MSG_IN);
         msg_out_fault = axis2_op_get_msg(annon_op, Environment::getEnv(), AXIS2_MSG_OUT_FAULT);
         msg_in_fault = axis2_op_get_msg(annon_op, Environment::getEnv(), AXIS2_MSG_IN_FAULT);

         svc_qname = axutil_qname_create(Environment::getEnv(),"TraderClient" ,NULL, NULL);
         axis2_svc_set_qname (svc, Environment::getEnv(), svc_qname);
		 axutil_qname_free(svc_qname,Environment::getEnv());

         /* creating the operations*/

         
           op_qname = axutil_qname_create(Environment::getEnv(),
                                         "deposit" ,
                                         "http://www.wso2.org",
                                         NULL);
           op = axis2_op_create_with_qname(Environment::getEnv(), op_qname);
           axutil_qname_free(op_qname,Environment::getEnv());

           
           axis2_op_set_msg_exchange_pattern(op, Environment::getEnv(), AXIS2_MEP_URI_OUT_IN);
             
           axis2_msg_increment_ref(msg_out, Environment::getEnv());
           axis2_msg_increment_ref(msg_in, Environment::getEnv());
           axis2_msg_increment_ref(msg_out_fault, Environment::getEnv());
           axis2_msg_increment_ref(msg_in_fault, Environment::getEnv());
           axis2_op_add_msg(op, Environment::getEnv(), AXIS2_MSG_OUT, msg_out);
           axis2_op_add_msg(op, Environment::getEnv(), AXIS2_MSG_IN, msg_in);
           axis2_op_add_msg(op, Environment::getEnv(), AXIS2_MSG_OUT_FAULT, msg_out_fault);
           axis2_op_add_msg(op, Environment::getEnv(), AXIS2_MSG_IN_FAULT, msg_in_fault);
       
           
           axis2_svc_add_op(svc, Environment::getEnv(), op);
         
           op_qname = axutil_qname_create(Environment::getEnv(),
                                         "getSymbols" ,
                                         "http://www.wso2.org",
                                         NULL);
           op = axis2_op_create_with_qname(Environment::getEnv(), op_qname);
           axutil_qname_free(op_qname,Environment::getEnv());

           
           axis2_op_set_msg_exchange_pattern(op, Environment::getEnv(), AXIS2_MEP_URI_OUT_IN);
             
           axis2_msg_increment_ref(msg_out, Environment::getEnv());
           axis2_msg_increment_ref(msg_in, Environment::getEnv());
           axis2_msg_increment_ref(msg_out_fault, Environment::getEnv());
           axis2_msg_increment_ref(msg_in_fault, Environment::getEnv());
           axis2_op_add_msg(op, Environment::getEnv(), AXIS2_MSG_OUT, msg_out);
           axis2_op_add_msg(op, Environment::getEnv(), AXIS2_MSG_IN, msg_in);
           axis2_op_add_msg(op, Environment::getEnv(), AXIS2_MSG_OUT_FAULT, msg_out_fault);
           axis2_op_add_msg(op, Environment::getEnv(), AXIS2_MSG_IN_FAULT, msg_in_fault);
       
           
           axis2_svc_add_op(svc, Environment::getEnv(), op);
         
           op_qname = axutil_qname_create(Environment::getEnv(),
                                         "getQuote" ,
                                         "http://www.wso2.org",
                                         NULL);
           op = axis2_op_create_with_qname(Environment::getEnv(), op_qname);
           axutil_qname_free(op_qname,Environment::getEnv());

           
           axis2_op_set_msg_exchange_pattern(op, Environment::getEnv(), AXIS2_MEP_URI_OUT_IN);
             
           axis2_msg_increment_ref(msg_out, Environment::getEnv());
           axis2_msg_increment_ref(msg_in, Environment::getEnv());
           axis2_msg_increment_ref(msg_out_fault, Environment::getEnv());
           axis2_msg_increment_ref(msg_in_fault, Environment::getEnv());
           axis2_op_add_msg(op, Environment::getEnv(), AXIS2_MSG_OUT, msg_out);
           axis2_op_add_msg(op, Environment::getEnv(), AXIS2_MSG_IN, msg_in);
           axis2_op_add_msg(op, Environment::getEnv(), AXIS2_MSG_OUT_FAULT, msg_out_fault);
           axis2_op_add_msg(op, Environment::getEnv(), AXIS2_MSG_IN_FAULT, msg_in_fault);
       
           
           axis2_svc_add_op(svc, Environment::getEnv(), op);
         
           op_qname = axutil_qname_create(Environment::getEnv(),
                                         "createAccount" ,
                                         "http://www.wso2.org",
                                         NULL);
           op = axis2_op_create_with_qname(Environment::getEnv(), op_qname);
           axutil_qname_free(op_qname,Environment::getEnv());

           
           axis2_op_set_msg_exchange_pattern(op, Environment::getEnv(), AXIS2_MEP_URI_OUT_IN);
             
           axis2_msg_increment_ref(msg_out, Environment::getEnv());
           axis2_msg_increment_ref(msg_in, Environment::getEnv());
           axis2_msg_increment_ref(msg_out_fault, Environment::getEnv());
           axis2_msg_increment_ref(msg_in_fault, Environment::getEnv());
           axis2_op_add_msg(op, Environment::getEnv(), AXIS2_MSG_OUT, msg_out);
           axis2_op_add_msg(op, Environment::getEnv(), AXIS2_MSG_IN, msg_in);
           axis2_op_add_msg(op, Environment::getEnv(), AXIS2_MSG_OUT_FAULT, msg_out_fault);
           axis2_op_add_msg(op, Environment::getEnv(), AXIS2_MSG_IN_FAULT, msg_in_fault);
       
           
           axis2_svc_add_op(svc, Environment::getEnv(), op);
         
           op_qname = axutil_qname_create(Environment::getEnv(),
                                         "sell" ,
                                         "http://www.wso2.org",
                                         NULL);
           op = axis2_op_create_with_qname(Environment::getEnv(), op_qname);
           axutil_qname_free(op_qname,Environment::getEnv());

           
           axis2_op_set_msg_exchange_pattern(op, Environment::getEnv(), AXIS2_MEP_URI_OUT_IN);
             
           axis2_msg_increment_ref(msg_out, Environment::getEnv());
           axis2_msg_increment_ref(msg_in, Environment::getEnv());
           axis2_msg_increment_ref(msg_out_fault, Environment::getEnv());
           axis2_msg_increment_ref(msg_in_fault, Environment::getEnv());
           axis2_op_add_msg(op, Environment::getEnv(), AXIS2_MSG_OUT, msg_out);
           axis2_op_add_msg(op, Environment::getEnv(), AXIS2_MSG_IN, msg_in);
           axis2_op_add_msg(op, Environment::getEnv(), AXIS2_MSG_OUT_FAULT, msg_out_fault);
           axis2_op_add_msg(op, Environment::getEnv(), AXIS2_MSG_IN_FAULT, msg_in_fault);
       
           
           axis2_svc_add_op(svc, Environment::getEnv(), op);
         
           op_qname = axutil_qname_create(Environment::getEnv(),
                                         "buy" ,
                                         "http://www.wso2.org",
                                         NULL);
           op = axis2_op_create_with_qname(Environment::getEnv(), op_qname);
           axutil_qname_free(op_qname,Environment::getEnv());

           
           axis2_op_set_msg_exchange_pattern(op, Environment::getEnv(), AXIS2_MEP_URI_OUT_IN);
             
           axis2_msg_increment_ref(msg_out, Environment::getEnv());
           axis2_msg_increment_ref(msg_in, Environment::getEnv());
           axis2_msg_increment_ref(msg_out_fault, Environment::getEnv());
           axis2_msg_increment_ref(msg_in_fault, Environment::getEnv());
           axis2_op_add_msg(op, Environment::getEnv(), AXIS2_MSG_OUT, msg_out);
           axis2_op_add_msg(op, Environment::getEnv(), AXIS2_MSG_IN, msg_in);
           axis2_op_add_msg(op, Environment::getEnv(), AXIS2_MSG_OUT_FAULT, msg_out_fault);
           axis2_op_add_msg(op, Environment::getEnv(), AXIS2_MSG_IN_FAULT, msg_in_fault);
       
           
           axis2_svc_add_op(svc, Environment::getEnv(), op);
         
           op_qname = axutil_qname_create(Environment::getEnv(),
                                         "getPortfolio" ,
                                         "http://www.wso2.org",
                                         NULL);
           op = axis2_op_create_with_qname(Environment::getEnv(), op_qname);
           axutil_qname_free(op_qname,Environment::getEnv());

           
           axis2_op_set_msg_exchange_pattern(op, Environment::getEnv(), AXIS2_MEP_URI_OUT_IN);
             
           axis2_msg_increment_ref(msg_out, Environment::getEnv());
           axis2_msg_increment_ref(msg_in, Environment::getEnv());
           axis2_msg_increment_ref(msg_out_fault, Environment::getEnv());
           axis2_msg_increment_ref(msg_in_fault, Environment::getEnv());
           axis2_op_add_msg(op, Environment::getEnv(), AXIS2_MSG_OUT, msg_out);
           axis2_op_add_msg(op, Environment::getEnv(), AXIS2_MSG_IN, msg_in);
           axis2_op_add_msg(op, Environment::getEnv(), AXIS2_MSG_OUT_FAULT, msg_out_fault);
           axis2_op_add_msg(op, Environment::getEnv(), AXIS2_MSG_IN_FAULT, msg_in_fault);
       
           
           axis2_svc_add_op(svc, Environment::getEnv(), op);
         
      }

      /**
       *return end point picked from wsdl
       */
      std::string WSF_CALL
      TraderClientStub::getEndpointUriOfTraderClient()
      {
        std::string endpoint_uri;
        /* set the address from here */
        
        endpoint_uri = string("http://nagoya.apache.org:5049/axis/services/echo");
            
        return endpoint_uri;
      }


  
         /**
          * Auto generated method signature
          * For "deposit|http://www.wso2.org" operation.
          *
          * @param _depositRequest of the org_wso2_www_types::DepositRequest
          *
          * @return org_wso2_www_types::DepositResponse*
          */

         org_wso2_www_types::DepositResponse* WSF_CALL TraderClientStub::deposit(org_wso2_www_types::DepositRequest*  _depositRequest)
         {
            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;
            axiom_node_t *ret_node = NULL;

            const axis2_char_t *soap_action = NULL;
            axutil_qname_t *op_qname =  NULL;
            axiom_node_t *payload = NULL;
            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            org_wso2_www_types::DepositResponse* ret_val;
            
                                payload = _depositRequest->serialize(NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           
	    svc_client = serviceClient->getAxis2SvcClient();
            
           
            
            

	    options = clientOptions->getAxis2Options();
            if (NULL == options)
            {
                AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
                AXIS2_LOG_ERROR(Environment::getEnv()->log, AXIS2_LOG_SI, "options is null in stub");
                return (org_wso2_www_types::DepositResponse*)NULL;
            }
            soap_act = axis2_options_get_soap_action( options, Environment::getEnv() );
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "deposit";
              soap_act = axutil_string_create(Environment::getEnv(), "deposit");
              axis2_options_set_soap_action(options, Environment::getEnv(), soap_act);    
            }

            
            axis2_options_set_soap_version(options, Environment::getEnv(), AXIOM_SOAP11);
             
            ret_node =  axis2_svc_client_send_receive_with_op_qname( svc_client, Environment::getEnv(), op_qname, payload);
 
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, Environment::getEnv(), NULL);    
              
              axis2_options_set_action( options, Environment::getEnv(), NULL);
            }
            if(soap_act)
            {
              axutil_string_free(soap_act, Environment::getEnv());
            }

            
                    if ( NULL == ret_node )
                    {
                        return (org_wso2_www_types::DepositResponse*)NULL;
                    }
                    ret_val = new org_wso2_www_types::DepositResponse();

                    if(ret_val->deserialize(&ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                    {
                        if(ret_val != NULL)
                        {
                           delete ret_val;
                        }

                        AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "NULL returned from the _deserialize: "
                                                                "This should be due to an invalid XML");
                        return (org_wso2_www_types::DepositResponse*)NULL;
                    }

                   
                            return ret_val;
                       
        }
        
         /**
          * Auto generated method signature
          * For "getSymbols|http://www.wso2.org" operation.
          *
          * @param _getSymbolsRequest of the org_wso2_www_types::GetSymbolsRequest
          *
          * @return org_wso2_www_types::GetSymbolsResponse*
          */

         org_wso2_www_types::GetSymbolsResponse* WSF_CALL TraderClientStub::getSymbols(org_wso2_www_types::GetSymbolsRequest*  _getSymbolsRequest)
         {
            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;
            axiom_node_t *ret_node = NULL;

            const axis2_char_t *soap_action = NULL;
            axutil_qname_t *op_qname =  NULL;
            axiom_node_t *payload = NULL;
            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            org_wso2_www_types::GetSymbolsResponse* ret_val;
            
                                payload = _getSymbolsRequest->serialize(NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           
	    svc_client = serviceClient->getAxis2SvcClient();
            
           
            
            

	    options = clientOptions->getAxis2Options();
            if (NULL == options)
            {
                AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
                AXIS2_LOG_ERROR(Environment::getEnv()->log, AXIS2_LOG_SI, "options is null in stub");
                return (org_wso2_www_types::GetSymbolsResponse*)NULL;
            }
            soap_act = axis2_options_get_soap_action( options, Environment::getEnv() );
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "getSymbols";
              soap_act = axutil_string_create(Environment::getEnv(), "getSymbols");
              axis2_options_set_soap_action(options, Environment::getEnv(), soap_act);    
            }

            
            axis2_options_set_soap_version(options, Environment::getEnv(), AXIOM_SOAP11);
             
            ret_node =  axis2_svc_client_send_receive_with_op_qname( svc_client, Environment::getEnv(), op_qname, payload);
 
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, Environment::getEnv(), NULL);    
              
              axis2_options_set_action( options, Environment::getEnv(), NULL);
            }
            if(soap_act)
            {
              axutil_string_free(soap_act, Environment::getEnv());
            }

            
                    if ( NULL == ret_node )
                    {
                        return (org_wso2_www_types::GetSymbolsResponse*)NULL;
                    }
                    ret_val = new org_wso2_www_types::GetSymbolsResponse();

                    if(ret_val->deserialize(&ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                    {
                        if(ret_val != NULL)
                        {
                           delete ret_val;
                        }

                        AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "NULL returned from the _deserialize: "
                                                                "This should be due to an invalid XML");
                        return (org_wso2_www_types::GetSymbolsResponse*)NULL;
                    }

                   
                            return ret_val;
                       
        }
        
         /**
          * Auto generated method signature
          * For "getQuote|http://www.wso2.org" operation.
          *
          * @param _getQuoteRequest of the org_wso2_www_types::GetQuoteRequest
          *
          * @return org_wso2_www_types::GetQuoteResponse*
          */

         org_wso2_www_types::GetQuoteResponse* WSF_CALL TraderClientStub::getQuote(org_wso2_www_types::GetQuoteRequest*  _getQuoteRequest)
         {
            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;
            axiom_node_t *ret_node = NULL;

            const axis2_char_t *soap_action = NULL;
            axutil_qname_t *op_qname =  NULL;
            axiom_node_t *payload = NULL;
            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            org_wso2_www_types::GetQuoteResponse* ret_val;
            
                                payload = _getQuoteRequest->serialize(NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           
	    svc_client = serviceClient->getAxis2SvcClient();
            
           
            
            

	    options = clientOptions->getAxis2Options();
            if (NULL == options)
            {
                AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
                AXIS2_LOG_ERROR(Environment::getEnv()->log, AXIS2_LOG_SI, "options is null in stub");
                return (org_wso2_www_types::GetQuoteResponse*)NULL;
            }
            soap_act = axis2_options_get_soap_action( options, Environment::getEnv() );
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "getQuote";
              soap_act = axutil_string_create(Environment::getEnv(), "getQuote");
              axis2_options_set_soap_action(options, Environment::getEnv(), soap_act);    
            }

            
            axis2_options_set_soap_version(options, Environment::getEnv(), AXIOM_SOAP11);
             
            ret_node =  axis2_svc_client_send_receive_with_op_qname( svc_client, Environment::getEnv(), op_qname, payload);
 
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, Environment::getEnv(), NULL);    
              
              axis2_options_set_action( options, Environment::getEnv(), NULL);
            }
            if(soap_act)
            {
              axutil_string_free(soap_act, Environment::getEnv());
            }

            
                    if ( NULL == ret_node )
                    {
                        return (org_wso2_www_types::GetQuoteResponse*)NULL;
                    }
                    ret_val = new org_wso2_www_types::GetQuoteResponse();

                    if(ret_val->deserialize(&ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                    {
                        if(ret_val != NULL)
                        {
                           delete ret_val;
                        }

                        AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "NULL returned from the _deserialize: "
                                                                "This should be due to an invalid XML");
                        return (org_wso2_www_types::GetQuoteResponse*)NULL;
                    }

                   
                            return ret_val;
                       
        }
        
         /**
          * Auto generated method signature
          * For "createAccount|http://www.wso2.org" operation.
          *
          * @param _createAccountRequest of the org_wso2_www_types::CreateAccountRequest
          *
          * @return org_wso2_www_types::CreateAccountResponse*
          */

         org_wso2_www_types::CreateAccountResponse* WSF_CALL TraderClientStub::createAccount(org_wso2_www_types::CreateAccountRequest*  _createAccountRequest)
         {
            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;
            axiom_node_t *ret_node = NULL;

            const axis2_char_t *soap_action = NULL;
            axutil_qname_t *op_qname =  NULL;
            axiom_node_t *payload = NULL;
            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            org_wso2_www_types::CreateAccountResponse* ret_val;
            
                                payload = _createAccountRequest->serialize(NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           
	    svc_client = serviceClient->getAxis2SvcClient();
            
           
            
            

	    options = clientOptions->getAxis2Options();
            if (NULL == options)
            {
                AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
                AXIS2_LOG_ERROR(Environment::getEnv()->log, AXIS2_LOG_SI, "options is null in stub");
                return (org_wso2_www_types::CreateAccountResponse*)NULL;
            }
            soap_act = axis2_options_get_soap_action( options, Environment::getEnv() );
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "createAccount";
              soap_act = axutil_string_create(Environment::getEnv(), "createAccount");
              axis2_options_set_soap_action(options, Environment::getEnv(), soap_act);    
            }

            
            axis2_options_set_soap_version(options, Environment::getEnv(), AXIOM_SOAP11);
             
            ret_node =  axis2_svc_client_send_receive_with_op_qname( svc_client, Environment::getEnv(), op_qname, payload);
 
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, Environment::getEnv(), NULL);    
              
              axis2_options_set_action( options, Environment::getEnv(), NULL);
            }
            if(soap_act)
            {
              axutil_string_free(soap_act, Environment::getEnv());
            }

            
                    if ( NULL == ret_node )
                    {
                        return (org_wso2_www_types::CreateAccountResponse*)NULL;
                    }
                    ret_val = new org_wso2_www_types::CreateAccountResponse();

                    if(ret_val->deserialize(&ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                    {
                        if(ret_val != NULL)
                        {
                           delete ret_val;
                        }

                        AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "NULL returned from the _deserialize: "
                                                                "This should be due to an invalid XML");
                        return (org_wso2_www_types::CreateAccountResponse*)NULL;
                    }

                   
                            return ret_val;
                       
        }
        
         /**
          * Auto generated method signature
          * For "sell|http://www.wso2.org" operation.
          *
          * @param _sellRequest of the org_wso2_www_types::SellRequest
          *
          * @return org_wso2_www_types::SellResponse*
          */

         org_wso2_www_types::SellResponse* WSF_CALL TraderClientStub::sell(org_wso2_www_types::SellRequest*  _sellRequest)
         {
            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;
            axiom_node_t *ret_node = NULL;

            const axis2_char_t *soap_action = NULL;
            axutil_qname_t *op_qname =  NULL;
            axiom_node_t *payload = NULL;
            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            org_wso2_www_types::SellResponse* ret_val;
            
                                payload = _sellRequest->serialize(NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           
	    svc_client = serviceClient->getAxis2SvcClient();
            
           
            
            

	    options = clientOptions->getAxis2Options();
            if (NULL == options)
            {
                AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
                AXIS2_LOG_ERROR(Environment::getEnv()->log, AXIS2_LOG_SI, "options is null in stub");
                return (org_wso2_www_types::SellResponse*)NULL;
            }
            soap_act = axis2_options_get_soap_action( options, Environment::getEnv() );
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "sell";
              soap_act = axutil_string_create(Environment::getEnv(), "sell");
              axis2_options_set_soap_action(options, Environment::getEnv(), soap_act);    
            }

            
            axis2_options_set_soap_version(options, Environment::getEnv(), AXIOM_SOAP11);
             
            ret_node =  axis2_svc_client_send_receive_with_op_qname( svc_client, Environment::getEnv(), op_qname, payload);
 
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, Environment::getEnv(), NULL);    
              
              axis2_options_set_action( options, Environment::getEnv(), NULL);
            }
            if(soap_act)
            {
              axutil_string_free(soap_act, Environment::getEnv());
            }

            
                    if ( NULL == ret_node )
                    {
                        return (org_wso2_www_types::SellResponse*)NULL;
                    }
                    ret_val = new org_wso2_www_types::SellResponse();

                    if(ret_val->deserialize(&ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                    {
                        if(ret_val != NULL)
                        {
                           delete ret_val;
                        }

                        AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "NULL returned from the _deserialize: "
                                                                "This should be due to an invalid XML");
                        return (org_wso2_www_types::SellResponse*)NULL;
                    }

                   
                            return ret_val;
                       
        }
        
         /**
          * Auto generated method signature
          * For "buy|http://www.wso2.org" operation.
          *
          * @param _buyRequest of the org_wso2_www_types::BuyRequest
          *
          * @return org_wso2_www_types::BuyResponse*
          */

         org_wso2_www_types::BuyResponse* WSF_CALL TraderClientStub::buy(org_wso2_www_types::BuyRequest*  _buyRequest)
         {
            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;
            axiom_node_t *ret_node = NULL;

            const axis2_char_t *soap_action = NULL;
            axutil_qname_t *op_qname =  NULL;
            axiom_node_t *payload = NULL;
            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            org_wso2_www_types::BuyResponse* ret_val;
            
                                payload = _buyRequest->serialize(NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           
	    svc_client = serviceClient->getAxis2SvcClient();
            
           
            
            

	    options = clientOptions->getAxis2Options();
            if (NULL == options)
            {
                AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
                AXIS2_LOG_ERROR(Environment::getEnv()->log, AXIS2_LOG_SI, "options is null in stub");
                return (org_wso2_www_types::BuyResponse*)NULL;
            }
            soap_act = axis2_options_get_soap_action( options, Environment::getEnv() );
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "buy";
              soap_act = axutil_string_create(Environment::getEnv(), "buy");
              axis2_options_set_soap_action(options, Environment::getEnv(), soap_act);    
            }

            
            axis2_options_set_soap_version(options, Environment::getEnv(), AXIOM_SOAP11);
             
            ret_node =  axis2_svc_client_send_receive_with_op_qname( svc_client, Environment::getEnv(), op_qname, payload);
 
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, Environment::getEnv(), NULL);    
              
              axis2_options_set_action( options, Environment::getEnv(), NULL);
            }
            if(soap_act)
            {
              axutil_string_free(soap_act, Environment::getEnv());
            }

            
                    if ( NULL == ret_node )
                    {
                        return (org_wso2_www_types::BuyResponse*)NULL;
                    }
                    ret_val = new org_wso2_www_types::BuyResponse();

                    if(ret_val->deserialize(&ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                    {
                        if(ret_val != NULL)
                        {
                           delete ret_val;
                        }

                        AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "NULL returned from the _deserialize: "
                                                                "This should be due to an invalid XML");
                        return (org_wso2_www_types::BuyResponse*)NULL;
                    }

                   
                            return ret_val;
                       
        }
        
         /**
          * Auto generated method signature
          * For "getPortfolio|http://www.wso2.org" operation.
          *
          * @param _getPortfolioRequest of the org_wso2_www_types::GetPortfolioRequest
          *
          * @return org_wso2_www_types::GetPortfolioResponse*
          */

         org_wso2_www_types::GetPortfolioResponse* WSF_CALL TraderClientStub::getPortfolio(org_wso2_www_types::GetPortfolioRequest*  _getPortfolioRequest)
         {
            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;
            axiom_node_t *ret_node = NULL;

            const axis2_char_t *soap_action = NULL;
            axutil_qname_t *op_qname =  NULL;
            axiom_node_t *payload = NULL;
            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            org_wso2_www_types::GetPortfolioResponse* ret_val;
            
                                payload = _getPortfolioRequest->serialize(NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           
	    svc_client = serviceClient->getAxis2SvcClient();
            
           
            
            

	    options = clientOptions->getAxis2Options();
            if (NULL == options)
            {
                AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
                AXIS2_LOG_ERROR(Environment::getEnv()->log, AXIS2_LOG_SI, "options is null in stub");
                return (org_wso2_www_types::GetPortfolioResponse*)NULL;
            }
            soap_act = axis2_options_get_soap_action( options, Environment::getEnv() );
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "getPortfolio";
              soap_act = axutil_string_create(Environment::getEnv(), "getPortfolio");
              axis2_options_set_soap_action(options, Environment::getEnv(), soap_act);    
            }

            
            axis2_options_set_soap_version(options, Environment::getEnv(), AXIOM_SOAP11);
             
            ret_node =  axis2_svc_client_send_receive_with_op_qname( svc_client, Environment::getEnv(), op_qname, payload);
 
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, Environment::getEnv(), NULL);    
              
              axis2_options_set_action( options, Environment::getEnv(), NULL);
            }
            if(soap_act)
            {
              axutil_string_free(soap_act, Environment::getEnv());
            }

            
                    if ( NULL == ret_node )
                    {
                        return (org_wso2_www_types::GetPortfolioResponse*)NULL;
                    }
                    ret_val = new org_wso2_www_types::GetPortfolioResponse();

                    if(ret_val->deserialize(&ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                    {
                        if(ret_val != NULL)
                        {
                           delete ret_val;
                        }

                        AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "NULL returned from the _deserialize: "
                                                                "This should be due to an invalid XML");
                        return (org_wso2_www_types::GetPortfolioResponse*)NULL;
                    }

                   
                            return ret_val;
                       
        }
        

        struct axis2_stub_TraderClient_deposit_callback_data
        {   
            ITraderClientCallback *callback;
          
        };

        static axis2_status_t WSF_CALL axis2_stub_on_error_TraderClient_deposit(axis2_callback_t *axis_callback, const axutil_env_t *env, int exception)
        {
            struct axis2_stub_TraderClient_deposit_callback_data* callback_data = NULL;
            callback_data = (struct axis2_stub_TraderClient_deposit_callback_data*)axis2_callback_get_data(axis_callback);
        
            ITraderClientCallback* callback = NULL;
            callback = callback_data->callback;
            callback->receiveError_deposit(exception);
            return AXIS2_SUCCESS;
        } 

        axis2_status_t  AXIS2_CALL axis2_stub_on_complete_TraderClient_deposit(axis2_callback_t *axis_callback, const axutil_env_t *env)
        {
            struct axis2_stub_TraderClient_deposit_callback_data* callback_data = NULL;
            axis2_status_t status = AXIS2_SUCCESS;
            org_wso2_www_types::DepositResponse* ret_val;
            

            axiom_node_t *ret_node = NULL;
            axiom_soap_envelope_t *soap_envelope = NULL;

            

            ITraderClientCallback *callback = NULL;

            callback_data = (struct axis2_stub_TraderClient_deposit_callback_data*)axis2_callback_get_data(axis_callback);

            callback = callback_data->callback;

            soap_envelope = axis2_callback_get_envelope(axis_callback, Environment::getEnv());
            if(soap_envelope)
            {
                axiom_soap_body_t *soap_body;
                soap_body = axiom_soap_envelope_get_body(soap_envelope, Environment::getEnv());
                if(soap_body)
                {
                    axiom_soap_fault_t *soap_fault = NULL;
                    axiom_node_t *body_node = axiom_soap_body_get_base_node(soap_body, Environment::getEnv());

                      if(body_node)
                    {
                        ret_node = axiom_node_get_first_child(body_node, Environment::getEnv());
                    }
                }
                
                
            }


            
                    if(ret_node != NULL)
                    {
                        ret_val = new org_wso2_www_types::DepositResponse();
     
                        if(ret_val->deserialize(&ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                        {
                            WSF_LOG_ERROR_MSG( Environment::getEnv()->log, AXIS2_LOG_SI, "NULL returned from the LendResponse_deserialize: "
                                                                    "This should be due to an invalid XML");
                            delete ret_val;
                            ret_val = NULL;
                        }
                     }
                     else
                     {
                         ret_val = NULL; 
                     }

                     
                     callback->receiveResult_deposit(ret_val);
                         
 
            if(callback_data)
            {
                AXIS2_FREE(Environment::getEnv()->allocator, callback_data);
            }
            return AXIS2_SUCCESS;
        }

        /**
          * auto generated method signature for asynchronous invocations
          * for "deposit|http://www.wso2.org" operation.
          * @param stub The stub
          * @param env environment ( mandatory)
          * @param _depositRequest of the org_wso2_www_types::DepositRequest
          * @param user_data user data to be accessed by the callbacks
          * @param on_complete callback to handle on complete
          * @param on_error callback to handle on error
          */

         void WSF_CALL
        TraderClientStub::start_deposit(org_wso2_www_types::DepositRequest*  _depositRequest,
                                ITraderClientCallback* cb)
         {

            axis2_callback_t *callback = NULL;

            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;

            const axis2_char_t *soap_action = NULL;
            axiom_node_t *payload = NULL;

            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            
            
            struct axis2_stub_TraderClient_deposit_callback_data *callback_data;

            callback_data = (struct axis2_stub_TraderClient_deposit_callback_data*) AXIS2_MALLOC(Environment::getEnv()->allocator, 
                                    sizeof(struct axis2_stub_TraderClient_deposit_callback_data));
            if(NULL == callback_data)
            {
                AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "Can not allocate memory for the callback data structures");
                return;
            }
            

            
                                payload = _depositRequest->serialize(NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           

	    svc_client =   serviceClient->getAxis2SvcClient();
            
           
            
            

	    options = clientOptions->getAxis2Options();
            if (NULL == options)
            {
              AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
              AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "options is null in stub");
              return;
            }

            soap_act =axis2_options_get_soap_action (options, Environment::getEnv());
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "deposit";
              soap_act = axutil_string_create(Environment::getEnv(), "deposit");
              axis2_options_set_soap_action(options, Environment::getEnv(), soap_act);
            }
            
            axis2_options_set_soap_version(options, Environment::getEnv(), AXIOM_SOAP11);
             

            callback = axis2_callback_create(Environment::getEnv());
            /* Set our on_complete function pointer to the callback object */
            axis2_callback_set_on_complete(callback, axis2_stub_on_complete_TraderClient_deposit);
            /* Set our on_error function pointer to the callback object */
            axis2_callback_set_on_error(callback, axis2_stub_on_error_TraderClient_deposit);

            callback_data->callback = cb;
            axis2_callback_set_data(callback, (void*)callback_data);

            /* Send request */
            axis2_svc_client_send_receive_non_blocking(svc_client, Environment::getEnv(), payload, callback);
            
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, Environment::getEnv(), NULL);
              
              axis2_options_set_action(options, Environment::getEnv(), NULL);
            }
         }

         

        struct axis2_stub_TraderClient_getSymbols_callback_data
        {   
            ITraderClientCallback *callback;
          
        };

        static axis2_status_t WSF_CALL axis2_stub_on_error_TraderClient_getSymbols(axis2_callback_t *axis_callback, const axutil_env_t *env, int exception)
        {
            struct axis2_stub_TraderClient_getSymbols_callback_data* callback_data = NULL;
            callback_data = (struct axis2_stub_TraderClient_getSymbols_callback_data*)axis2_callback_get_data(axis_callback);
        
            ITraderClientCallback* callback = NULL;
            callback = callback_data->callback;
            callback->receiveError_getSymbols(exception);
            return AXIS2_SUCCESS;
        } 

        axis2_status_t  AXIS2_CALL axis2_stub_on_complete_TraderClient_getSymbols(axis2_callback_t *axis_callback, const axutil_env_t *env)
        {
            struct axis2_stub_TraderClient_getSymbols_callback_data* callback_data = NULL;
            axis2_status_t status = AXIS2_SUCCESS;
            org_wso2_www_types::GetSymbolsResponse* ret_val;
            

            axiom_node_t *ret_node = NULL;
            axiom_soap_envelope_t *soap_envelope = NULL;

            

            ITraderClientCallback *callback = NULL;

            callback_data = (struct axis2_stub_TraderClient_getSymbols_callback_data*)axis2_callback_get_data(axis_callback);

            callback = callback_data->callback;

            soap_envelope = axis2_callback_get_envelope(axis_callback, Environment::getEnv());
            if(soap_envelope)
            {
                axiom_soap_body_t *soap_body;
                soap_body = axiom_soap_envelope_get_body(soap_envelope, Environment::getEnv());
                if(soap_body)
                {
                    axiom_soap_fault_t *soap_fault = NULL;
                    axiom_node_t *body_node = axiom_soap_body_get_base_node(soap_body, Environment::getEnv());

                      if(body_node)
                    {
                        ret_node = axiom_node_get_first_child(body_node, Environment::getEnv());
                    }
                }
                
                
            }


            
                    if(ret_node != NULL)
                    {
                        ret_val = new org_wso2_www_types::GetSymbolsResponse();
     
                        if(ret_val->deserialize(&ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                        {
                            WSF_LOG_ERROR_MSG( Environment::getEnv()->log, AXIS2_LOG_SI, "NULL returned from the LendResponse_deserialize: "
                                                                    "This should be due to an invalid XML");
                            delete ret_val;
                            ret_val = NULL;
                        }
                     }
                     else
                     {
                         ret_val = NULL; 
                     }

                     
                     callback->receiveResult_getSymbols(ret_val);
                         
 
            if(callback_data)
            {
                AXIS2_FREE(Environment::getEnv()->allocator, callback_data);
            }
            return AXIS2_SUCCESS;
        }

        /**
          * auto generated method signature for asynchronous invocations
          * for "getSymbols|http://www.wso2.org" operation.
          * @param stub The stub
          * @param env environment ( mandatory)
          * @param _getSymbolsRequest of the org_wso2_www_types::GetSymbolsRequest
          * @param user_data user data to be accessed by the callbacks
          * @param on_complete callback to handle on complete
          * @param on_error callback to handle on error
          */

         void WSF_CALL
        TraderClientStub::start_getSymbols(org_wso2_www_types::GetSymbolsRequest*  _getSymbolsRequest,
                                ITraderClientCallback* cb)
         {

            axis2_callback_t *callback = NULL;

            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;

            const axis2_char_t *soap_action = NULL;
            axiom_node_t *payload = NULL;

            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            
            
            struct axis2_stub_TraderClient_getSymbols_callback_data *callback_data;

            callback_data = (struct axis2_stub_TraderClient_getSymbols_callback_data*) AXIS2_MALLOC(Environment::getEnv()->allocator, 
                                    sizeof(struct axis2_stub_TraderClient_getSymbols_callback_data));
            if(NULL == callback_data)
            {
                AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "Can not allocate memory for the callback data structures");
                return;
            }
            

            
                                payload = _getSymbolsRequest->serialize(NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           

	    svc_client =   serviceClient->getAxis2SvcClient();
            
           
            
            

	    options = clientOptions->getAxis2Options();
            if (NULL == options)
            {
              AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
              AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "options is null in stub");
              return;
            }

            soap_act =axis2_options_get_soap_action (options, Environment::getEnv());
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "getSymbols";
              soap_act = axutil_string_create(Environment::getEnv(), "getSymbols");
              axis2_options_set_soap_action(options, Environment::getEnv(), soap_act);
            }
            
            axis2_options_set_soap_version(options, Environment::getEnv(), AXIOM_SOAP11);
             

            callback = axis2_callback_create(Environment::getEnv());
            /* Set our on_complete function pointer to the callback object */
            axis2_callback_set_on_complete(callback, axis2_stub_on_complete_TraderClient_getSymbols);
            /* Set our on_error function pointer to the callback object */
            axis2_callback_set_on_error(callback, axis2_stub_on_error_TraderClient_getSymbols);

            callback_data->callback = cb;
            axis2_callback_set_data(callback, (void*)callback_data);

            /* Send request */
            axis2_svc_client_send_receive_non_blocking(svc_client, Environment::getEnv(), payload, callback);
            
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, Environment::getEnv(), NULL);
              
              axis2_options_set_action(options, Environment::getEnv(), NULL);
            }
         }

         

        struct axis2_stub_TraderClient_getQuote_callback_data
        {   
            ITraderClientCallback *callback;
          
        };

        static axis2_status_t WSF_CALL axis2_stub_on_error_TraderClient_getQuote(axis2_callback_t *axis_callback, const axutil_env_t *env, int exception)
        {
            struct axis2_stub_TraderClient_getQuote_callback_data* callback_data = NULL;
            callback_data = (struct axis2_stub_TraderClient_getQuote_callback_data*)axis2_callback_get_data(axis_callback);
        
            ITraderClientCallback* callback = NULL;
            callback = callback_data->callback;
            callback->receiveError_getQuote(exception);
            return AXIS2_SUCCESS;
        } 

        axis2_status_t  AXIS2_CALL axis2_stub_on_complete_TraderClient_getQuote(axis2_callback_t *axis_callback, const axutil_env_t *env)
        {
            struct axis2_stub_TraderClient_getQuote_callback_data* callback_data = NULL;
            axis2_status_t status = AXIS2_SUCCESS;
            org_wso2_www_types::GetQuoteResponse* ret_val;
            

            axiom_node_t *ret_node = NULL;
            axiom_soap_envelope_t *soap_envelope = NULL;

            

            ITraderClientCallback *callback = NULL;

            callback_data = (struct axis2_stub_TraderClient_getQuote_callback_data*)axis2_callback_get_data(axis_callback);

            callback = callback_data->callback;

            soap_envelope = axis2_callback_get_envelope(axis_callback, Environment::getEnv());
            if(soap_envelope)
            {
                axiom_soap_body_t *soap_body;
                soap_body = axiom_soap_envelope_get_body(soap_envelope, Environment::getEnv());
                if(soap_body)
                {
                    axiom_soap_fault_t *soap_fault = NULL;
                    axiom_node_t *body_node = axiom_soap_body_get_base_node(soap_body, Environment::getEnv());

                      if(body_node)
                    {
                        ret_node = axiom_node_get_first_child(body_node, Environment::getEnv());
                    }
                }
                
                
            }


            
                    if(ret_node != NULL)
                    {
                        ret_val = new org_wso2_www_types::GetQuoteResponse();
     
                        if(ret_val->deserialize(&ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                        {
                            WSF_LOG_ERROR_MSG( Environment::getEnv()->log, AXIS2_LOG_SI, "NULL returned from the LendResponse_deserialize: "
                                                                    "This should be due to an invalid XML");
                            delete ret_val;
                            ret_val = NULL;
                        }
                     }
                     else
                     {
                         ret_val = NULL; 
                     }

                     
                     callback->receiveResult_getQuote(ret_val);
                         
 
            if(callback_data)
            {
                AXIS2_FREE(Environment::getEnv()->allocator, callback_data);
            }
            return AXIS2_SUCCESS;
        }

        /**
          * auto generated method signature for asynchronous invocations
          * for "getQuote|http://www.wso2.org" operation.
          * @param stub The stub
          * @param env environment ( mandatory)
          * @param _getQuoteRequest of the org_wso2_www_types::GetQuoteRequest
          * @param user_data user data to be accessed by the callbacks
          * @param on_complete callback to handle on complete
          * @param on_error callback to handle on error
          */

         void WSF_CALL
        TraderClientStub::start_getQuote(org_wso2_www_types::GetQuoteRequest*  _getQuoteRequest,
                                ITraderClientCallback* cb)
         {

            axis2_callback_t *callback = NULL;

            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;

            const axis2_char_t *soap_action = NULL;
            axiom_node_t *payload = NULL;

            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            
            
            struct axis2_stub_TraderClient_getQuote_callback_data *callback_data;

            callback_data = (struct axis2_stub_TraderClient_getQuote_callback_data*) AXIS2_MALLOC(Environment::getEnv()->allocator, 
                                    sizeof(struct axis2_stub_TraderClient_getQuote_callback_data));
            if(NULL == callback_data)
            {
                AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "Can not allocate memory for the callback data structures");
                return;
            }
            

            
                                payload = _getQuoteRequest->serialize(NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           

	    svc_client =   serviceClient->getAxis2SvcClient();
            
           
            
            

	    options = clientOptions->getAxis2Options();
            if (NULL == options)
            {
              AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
              AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "options is null in stub");
              return;
            }

            soap_act =axis2_options_get_soap_action (options, Environment::getEnv());
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "getQuote";
              soap_act = axutil_string_create(Environment::getEnv(), "getQuote");
              axis2_options_set_soap_action(options, Environment::getEnv(), soap_act);
            }
            
            axis2_options_set_soap_version(options, Environment::getEnv(), AXIOM_SOAP11);
             

            callback = axis2_callback_create(Environment::getEnv());
            /* Set our on_complete function pointer to the callback object */
            axis2_callback_set_on_complete(callback, axis2_stub_on_complete_TraderClient_getQuote);
            /* Set our on_error function pointer to the callback object */
            axis2_callback_set_on_error(callback, axis2_stub_on_error_TraderClient_getQuote);

            callback_data->callback = cb;
            axis2_callback_set_data(callback, (void*)callback_data);

            /* Send request */
            axis2_svc_client_send_receive_non_blocking(svc_client, Environment::getEnv(), payload, callback);
            
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, Environment::getEnv(), NULL);
              
              axis2_options_set_action(options, Environment::getEnv(), NULL);
            }
         }

         

        struct axis2_stub_TraderClient_createAccount_callback_data
        {   
            ITraderClientCallback *callback;
          
        };

        static axis2_status_t WSF_CALL axis2_stub_on_error_TraderClient_createAccount(axis2_callback_t *axis_callback, const axutil_env_t *env, int exception)
        {
            struct axis2_stub_TraderClient_createAccount_callback_data* callback_data = NULL;
            callback_data = (struct axis2_stub_TraderClient_createAccount_callback_data*)axis2_callback_get_data(axis_callback);
        
            ITraderClientCallback* callback = NULL;
            callback = callback_data->callback;
            callback->receiveError_createAccount(exception);
            return AXIS2_SUCCESS;
        } 

        axis2_status_t  AXIS2_CALL axis2_stub_on_complete_TraderClient_createAccount(axis2_callback_t *axis_callback, const axutil_env_t *env)
        {
            struct axis2_stub_TraderClient_createAccount_callback_data* callback_data = NULL;
            axis2_status_t status = AXIS2_SUCCESS;
            org_wso2_www_types::CreateAccountResponse* ret_val;
            

            axiom_node_t *ret_node = NULL;
            axiom_soap_envelope_t *soap_envelope = NULL;

            

            ITraderClientCallback *callback = NULL;

            callback_data = (struct axis2_stub_TraderClient_createAccount_callback_data*)axis2_callback_get_data(axis_callback);

            callback = callback_data->callback;

            soap_envelope = axis2_callback_get_envelope(axis_callback, Environment::getEnv());
            if(soap_envelope)
            {
                axiom_soap_body_t *soap_body;
                soap_body = axiom_soap_envelope_get_body(soap_envelope, Environment::getEnv());
                if(soap_body)
                {
                    axiom_soap_fault_t *soap_fault = NULL;
                    axiom_node_t *body_node = axiom_soap_body_get_base_node(soap_body, Environment::getEnv());

                      if(body_node)
                    {
                        ret_node = axiom_node_get_first_child(body_node, Environment::getEnv());
                    }
                }
                
                
            }


            
                    if(ret_node != NULL)
                    {
                        ret_val = new org_wso2_www_types::CreateAccountResponse();
     
                        if(ret_val->deserialize(&ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                        {
                            WSF_LOG_ERROR_MSG( Environment::getEnv()->log, AXIS2_LOG_SI, "NULL returned from the LendResponse_deserialize: "
                                                                    "This should be due to an invalid XML");
                            delete ret_val;
                            ret_val = NULL;
                        }
                     }
                     else
                     {
                         ret_val = NULL; 
                     }

                     
                     callback->receiveResult_createAccount(ret_val);
                         
 
            if(callback_data)
            {
                AXIS2_FREE(Environment::getEnv()->allocator, callback_data);
            }
            return AXIS2_SUCCESS;
        }

        /**
          * auto generated method signature for asynchronous invocations
          * for "createAccount|http://www.wso2.org" operation.
          * @param stub The stub
          * @param env environment ( mandatory)
          * @param _createAccountRequest of the org_wso2_www_types::CreateAccountRequest
          * @param user_data user data to be accessed by the callbacks
          * @param on_complete callback to handle on complete
          * @param on_error callback to handle on error
          */

         void WSF_CALL
        TraderClientStub::start_createAccount(org_wso2_www_types::CreateAccountRequest*  _createAccountRequest,
                                ITraderClientCallback* cb)
         {

            axis2_callback_t *callback = NULL;

            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;

            const axis2_char_t *soap_action = NULL;
            axiom_node_t *payload = NULL;

            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            
            
            struct axis2_stub_TraderClient_createAccount_callback_data *callback_data;

            callback_data = (struct axis2_stub_TraderClient_createAccount_callback_data*) AXIS2_MALLOC(Environment::getEnv()->allocator, 
                                    sizeof(struct axis2_stub_TraderClient_createAccount_callback_data));
            if(NULL == callback_data)
            {
                AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "Can not allocate memory for the callback data structures");
                return;
            }
            

            
                                payload = _createAccountRequest->serialize(NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           

	    svc_client =   serviceClient->getAxis2SvcClient();
            
           
            
            

	    options = clientOptions->getAxis2Options();
            if (NULL == options)
            {
              AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
              AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "options is null in stub");
              return;
            }

            soap_act =axis2_options_get_soap_action (options, Environment::getEnv());
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "createAccount";
              soap_act = axutil_string_create(Environment::getEnv(), "createAccount");
              axis2_options_set_soap_action(options, Environment::getEnv(), soap_act);
            }
            
            axis2_options_set_soap_version(options, Environment::getEnv(), AXIOM_SOAP11);
             

            callback = axis2_callback_create(Environment::getEnv());
            /* Set our on_complete function pointer to the callback object */
            axis2_callback_set_on_complete(callback, axis2_stub_on_complete_TraderClient_createAccount);
            /* Set our on_error function pointer to the callback object */
            axis2_callback_set_on_error(callback, axis2_stub_on_error_TraderClient_createAccount);

            callback_data->callback = cb;
            axis2_callback_set_data(callback, (void*)callback_data);

            /* Send request */
            axis2_svc_client_send_receive_non_blocking(svc_client, Environment::getEnv(), payload, callback);
            
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, Environment::getEnv(), NULL);
              
              axis2_options_set_action(options, Environment::getEnv(), NULL);
            }
         }

         

        struct axis2_stub_TraderClient_sell_callback_data
        {   
            ITraderClientCallback *callback;
          
        };

        static axis2_status_t WSF_CALL axis2_stub_on_error_TraderClient_sell(axis2_callback_t *axis_callback, const axutil_env_t *env, int exception)
        {
            struct axis2_stub_TraderClient_sell_callback_data* callback_data = NULL;
            callback_data = (struct axis2_stub_TraderClient_sell_callback_data*)axis2_callback_get_data(axis_callback);
        
            ITraderClientCallback* callback = NULL;
            callback = callback_data->callback;
            callback->receiveError_sell(exception);
            return AXIS2_SUCCESS;
        } 

        axis2_status_t  AXIS2_CALL axis2_stub_on_complete_TraderClient_sell(axis2_callback_t *axis_callback, const axutil_env_t *env)
        {
            struct axis2_stub_TraderClient_sell_callback_data* callback_data = NULL;
            axis2_status_t status = AXIS2_SUCCESS;
            org_wso2_www_types::SellResponse* ret_val;
            

            axiom_node_t *ret_node = NULL;
            axiom_soap_envelope_t *soap_envelope = NULL;

            

            ITraderClientCallback *callback = NULL;

            callback_data = (struct axis2_stub_TraderClient_sell_callback_data*)axis2_callback_get_data(axis_callback);

            callback = callback_data->callback;

            soap_envelope = axis2_callback_get_envelope(axis_callback, Environment::getEnv());
            if(soap_envelope)
            {
                axiom_soap_body_t *soap_body;
                soap_body = axiom_soap_envelope_get_body(soap_envelope, Environment::getEnv());
                if(soap_body)
                {
                    axiom_soap_fault_t *soap_fault = NULL;
                    axiom_node_t *body_node = axiom_soap_body_get_base_node(soap_body, Environment::getEnv());

                      if(body_node)
                    {
                        ret_node = axiom_node_get_first_child(body_node, Environment::getEnv());
                    }
                }
                
                
            }


            
                    if(ret_node != NULL)
                    {
                        ret_val = new org_wso2_www_types::SellResponse();
     
                        if(ret_val->deserialize(&ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                        {
                            WSF_LOG_ERROR_MSG( Environment::getEnv()->log, AXIS2_LOG_SI, "NULL returned from the LendResponse_deserialize: "
                                                                    "This should be due to an invalid XML");
                            delete ret_val;
                            ret_val = NULL;
                        }
                     }
                     else
                     {
                         ret_val = NULL; 
                     }

                     
                     callback->receiveResult_sell(ret_val);
                         
 
            if(callback_data)
            {
                AXIS2_FREE(Environment::getEnv()->allocator, callback_data);
            }
            return AXIS2_SUCCESS;
        }

        /**
          * auto generated method signature for asynchronous invocations
          * for "sell|http://www.wso2.org" operation.
          * @param stub The stub
          * @param env environment ( mandatory)
          * @param _sellRequest of the org_wso2_www_types::SellRequest
          * @param user_data user data to be accessed by the callbacks
          * @param on_complete callback to handle on complete
          * @param on_error callback to handle on error
          */

         void WSF_CALL
        TraderClientStub::start_sell(org_wso2_www_types::SellRequest*  _sellRequest,
                                ITraderClientCallback* cb)
         {

            axis2_callback_t *callback = NULL;

            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;

            const axis2_char_t *soap_action = NULL;
            axiom_node_t *payload = NULL;

            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            
            
            struct axis2_stub_TraderClient_sell_callback_data *callback_data;

            callback_data = (struct axis2_stub_TraderClient_sell_callback_data*) AXIS2_MALLOC(Environment::getEnv()->allocator, 
                                    sizeof(struct axis2_stub_TraderClient_sell_callback_data));
            if(NULL == callback_data)
            {
                AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "Can not allocate memory for the callback data structures");
                return;
            }
            

            
                                payload = _sellRequest->serialize(NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           

	    svc_client =   serviceClient->getAxis2SvcClient();
            
           
            
            

	    options = clientOptions->getAxis2Options();
            if (NULL == options)
            {
              AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
              AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "options is null in stub");
              return;
            }

            soap_act =axis2_options_get_soap_action (options, Environment::getEnv());
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "sell";
              soap_act = axutil_string_create(Environment::getEnv(), "sell");
              axis2_options_set_soap_action(options, Environment::getEnv(), soap_act);
            }
            
            axis2_options_set_soap_version(options, Environment::getEnv(), AXIOM_SOAP11);
             

            callback = axis2_callback_create(Environment::getEnv());
            /* Set our on_complete function pointer to the callback object */
            axis2_callback_set_on_complete(callback, axis2_stub_on_complete_TraderClient_sell);
            /* Set our on_error function pointer to the callback object */
            axis2_callback_set_on_error(callback, axis2_stub_on_error_TraderClient_sell);

            callback_data->callback = cb;
            axis2_callback_set_data(callback, (void*)callback_data);

            /* Send request */
            axis2_svc_client_send_receive_non_blocking(svc_client, Environment::getEnv(), payload, callback);
            
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, Environment::getEnv(), NULL);
              
              axis2_options_set_action(options, Environment::getEnv(), NULL);
            }
         }

         

        struct axis2_stub_TraderClient_buy_callback_data
        {   
            ITraderClientCallback *callback;
          
        };

        static axis2_status_t WSF_CALL axis2_stub_on_error_TraderClient_buy(axis2_callback_t *axis_callback, const axutil_env_t *env, int exception)
        {
            struct axis2_stub_TraderClient_buy_callback_data* callback_data = NULL;
            callback_data = (struct axis2_stub_TraderClient_buy_callback_data*)axis2_callback_get_data(axis_callback);
        
            ITraderClientCallback* callback = NULL;
            callback = callback_data->callback;
            callback->receiveError_buy(exception);
            return AXIS2_SUCCESS;
        } 

        axis2_status_t  AXIS2_CALL axis2_stub_on_complete_TraderClient_buy(axis2_callback_t *axis_callback, const axutil_env_t *env)
        {
            struct axis2_stub_TraderClient_buy_callback_data* callback_data = NULL;
            axis2_status_t status = AXIS2_SUCCESS;
            org_wso2_www_types::BuyResponse* ret_val;
            

            axiom_node_t *ret_node = NULL;
            axiom_soap_envelope_t *soap_envelope = NULL;

            

            ITraderClientCallback *callback = NULL;

            callback_data = (struct axis2_stub_TraderClient_buy_callback_data*)axis2_callback_get_data(axis_callback);

            callback = callback_data->callback;

            soap_envelope = axis2_callback_get_envelope(axis_callback, Environment::getEnv());
            if(soap_envelope)
            {
                axiom_soap_body_t *soap_body;
                soap_body = axiom_soap_envelope_get_body(soap_envelope, Environment::getEnv());
                if(soap_body)
                {
                    axiom_soap_fault_t *soap_fault = NULL;
                    axiom_node_t *body_node = axiom_soap_body_get_base_node(soap_body, Environment::getEnv());

                      if(body_node)
                    {
                        ret_node = axiom_node_get_first_child(body_node, Environment::getEnv());
                    }
                }
                
                
            }


            
                    if(ret_node != NULL)
                    {
                        ret_val = new org_wso2_www_types::BuyResponse();
     
                        if(ret_val->deserialize(&ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                        {
                            WSF_LOG_ERROR_MSG( Environment::getEnv()->log, AXIS2_LOG_SI, "NULL returned from the LendResponse_deserialize: "
                                                                    "This should be due to an invalid XML");
                            delete ret_val;
                            ret_val = NULL;
                        }
                     }
                     else
                     {
                         ret_val = NULL; 
                     }

                     
                     callback->receiveResult_buy(ret_val);
                         
 
            if(callback_data)
            {
                AXIS2_FREE(Environment::getEnv()->allocator, callback_data);
            }
            return AXIS2_SUCCESS;
        }

        /**
          * auto generated method signature for asynchronous invocations
          * for "buy|http://www.wso2.org" operation.
          * @param stub The stub
          * @param env environment ( mandatory)
          * @param _buyRequest of the org_wso2_www_types::BuyRequest
          * @param user_data user data to be accessed by the callbacks
          * @param on_complete callback to handle on complete
          * @param on_error callback to handle on error
          */

         void WSF_CALL
        TraderClientStub::start_buy(org_wso2_www_types::BuyRequest*  _buyRequest,
                                ITraderClientCallback* cb)
         {

            axis2_callback_t *callback = NULL;

            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;

            const axis2_char_t *soap_action = NULL;
            axiom_node_t *payload = NULL;

            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            
            
            struct axis2_stub_TraderClient_buy_callback_data *callback_data;

            callback_data = (struct axis2_stub_TraderClient_buy_callback_data*) AXIS2_MALLOC(Environment::getEnv()->allocator, 
                                    sizeof(struct axis2_stub_TraderClient_buy_callback_data));
            if(NULL == callback_data)
            {
                AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "Can not allocate memory for the callback data structures");
                return;
            }
            

            
                                payload = _buyRequest->serialize(NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           

	    svc_client =   serviceClient->getAxis2SvcClient();
            
           
            
            

	    options = clientOptions->getAxis2Options();
            if (NULL == options)
            {
              AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
              AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "options is null in stub");
              return;
            }

            soap_act =axis2_options_get_soap_action (options, Environment::getEnv());
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "buy";
              soap_act = axutil_string_create(Environment::getEnv(), "buy");
              axis2_options_set_soap_action(options, Environment::getEnv(), soap_act);
            }
            
            axis2_options_set_soap_version(options, Environment::getEnv(), AXIOM_SOAP11);
             

            callback = axis2_callback_create(Environment::getEnv());
            /* Set our on_complete function pointer to the callback object */
            axis2_callback_set_on_complete(callback, axis2_stub_on_complete_TraderClient_buy);
            /* Set our on_error function pointer to the callback object */
            axis2_callback_set_on_error(callback, axis2_stub_on_error_TraderClient_buy);

            callback_data->callback = cb;
            axis2_callback_set_data(callback, (void*)callback_data);

            /* Send request */
            axis2_svc_client_send_receive_non_blocking(svc_client, Environment::getEnv(), payload, callback);
            
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, Environment::getEnv(), NULL);
              
              axis2_options_set_action(options, Environment::getEnv(), NULL);
            }
         }

         

        struct axis2_stub_TraderClient_getPortfolio_callback_data
        {   
            ITraderClientCallback *callback;
          
        };

        static axis2_status_t WSF_CALL axis2_stub_on_error_TraderClient_getPortfolio(axis2_callback_t *axis_callback, const axutil_env_t *env, int exception)
        {
            struct axis2_stub_TraderClient_getPortfolio_callback_data* callback_data = NULL;
            callback_data = (struct axis2_stub_TraderClient_getPortfolio_callback_data*)axis2_callback_get_data(axis_callback);
        
            ITraderClientCallback* callback = NULL;
            callback = callback_data->callback;
            callback->receiveError_getPortfolio(exception);
            return AXIS2_SUCCESS;
        } 

        axis2_status_t  AXIS2_CALL axis2_stub_on_complete_TraderClient_getPortfolio(axis2_callback_t *axis_callback, const axutil_env_t *env)
        {
            struct axis2_stub_TraderClient_getPortfolio_callback_data* callback_data = NULL;
            axis2_status_t status = AXIS2_SUCCESS;
            org_wso2_www_types::GetPortfolioResponse* ret_val;
            

            axiom_node_t *ret_node = NULL;
            axiom_soap_envelope_t *soap_envelope = NULL;

            

            ITraderClientCallback *callback = NULL;

            callback_data = (struct axis2_stub_TraderClient_getPortfolio_callback_data*)axis2_callback_get_data(axis_callback);

            callback = callback_data->callback;

            soap_envelope = axis2_callback_get_envelope(axis_callback, Environment::getEnv());
            if(soap_envelope)
            {
                axiom_soap_body_t *soap_body;
                soap_body = axiom_soap_envelope_get_body(soap_envelope, Environment::getEnv());
                if(soap_body)
                {
                    axiom_soap_fault_t *soap_fault = NULL;
                    axiom_node_t *body_node = axiom_soap_body_get_base_node(soap_body, Environment::getEnv());

                      if(body_node)
                    {
                        ret_node = axiom_node_get_first_child(body_node, Environment::getEnv());
                    }
                }
                
                
            }


            
                    if(ret_node != NULL)
                    {
                        ret_val = new org_wso2_www_types::GetPortfolioResponse();
     
                        if(ret_val->deserialize(&ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                        {
                            WSF_LOG_ERROR_MSG( Environment::getEnv()->log, AXIS2_LOG_SI, "NULL returned from the LendResponse_deserialize: "
                                                                    "This should be due to an invalid XML");
                            delete ret_val;
                            ret_val = NULL;
                        }
                     }
                     else
                     {
                         ret_val = NULL; 
                     }

                     
                     callback->receiveResult_getPortfolio(ret_val);
                         
 
            if(callback_data)
            {
                AXIS2_FREE(Environment::getEnv()->allocator, callback_data);
            }
            return AXIS2_SUCCESS;
        }

        /**
          * auto generated method signature for asynchronous invocations
          * for "getPortfolio|http://www.wso2.org" operation.
          * @param stub The stub
          * @param env environment ( mandatory)
          * @param _getPortfolioRequest of the org_wso2_www_types::GetPortfolioRequest
          * @param user_data user data to be accessed by the callbacks
          * @param on_complete callback to handle on complete
          * @param on_error callback to handle on error
          */

         void WSF_CALL
        TraderClientStub::start_getPortfolio(org_wso2_www_types::GetPortfolioRequest*  _getPortfolioRequest,
                                ITraderClientCallback* cb)
         {

            axis2_callback_t *callback = NULL;

            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;

            const axis2_char_t *soap_action = NULL;
            axiom_node_t *payload = NULL;

            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            
            
            struct axis2_stub_TraderClient_getPortfolio_callback_data *callback_data;

            callback_data = (struct axis2_stub_TraderClient_getPortfolio_callback_data*) AXIS2_MALLOC(Environment::getEnv()->allocator, 
                                    sizeof(struct axis2_stub_TraderClient_getPortfolio_callback_data));
            if(NULL == callback_data)
            {
                AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "Can not allocate memory for the callback data structures");
                return;
            }
            

            
                                payload = _getPortfolioRequest->serialize(NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           

	    svc_client =   serviceClient->getAxis2SvcClient();
            
           
            
            

	    options = clientOptions->getAxis2Options();
            if (NULL == options)
            {
              AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
              AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "options is null in stub");
              return;
            }

            soap_act =axis2_options_get_soap_action (options, Environment::getEnv());
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "getPortfolio";
              soap_act = axutil_string_create(Environment::getEnv(), "getPortfolio");
              axis2_options_set_soap_action(options, Environment::getEnv(), soap_act);
            }
            
            axis2_options_set_soap_version(options, Environment::getEnv(), AXIOM_SOAP11);
             

            callback = axis2_callback_create(Environment::getEnv());
            /* Set our on_complete function pointer to the callback object */
            axis2_callback_set_on_complete(callback, axis2_stub_on_complete_TraderClient_getPortfolio);
            /* Set our on_error function pointer to the callback object */
            axis2_callback_set_on_error(callback, axis2_stub_on_error_TraderClient_getPortfolio);

            callback_data->callback = cb;
            axis2_callback_set_data(callback, (void*)callback_data);

            /* Send request */
            axis2_svc_client_send_receive_non_blocking(svc_client, Environment::getEnv(), payload, callback);
            
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, Environment::getEnv(), NULL);
              
              axis2_options_set_action(options, Environment::getEnv(), NULL);
            }
         }

         

