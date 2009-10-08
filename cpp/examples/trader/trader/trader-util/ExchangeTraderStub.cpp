
      /**
       * ExchangeTraderStub.cpp
       *
       * This file was auto-generated from WSDL for "ExchangeTrader|http://www.wso2.org" service
       * by the Apache Axis2/Java version: #axisVersion# #today#
       */

      #include "ExchangeTraderStub.h"
      #include "IExchangeTraderCallback.h"
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
       * ExchangeTraderStub CPP implementation
       */
       ExchangeTraderStub::ExchangeTraderStub(std::string& clientHome)
        {
                if(clientHome.empty())
                {
                   cout<<"Please specify the client home";
                }
                std::string endpointUri= getEndpointUriOfExchangeTrader();

                init(clientHome,endpointUri);

                populateServicesForExchangeTrader();


        }


      ExchangeTraderStub::ExchangeTraderStub(std::string& clientHome,std::string& endpointURI)
      {
         std::string endpointUri;

         if(clientHome.empty())
         {
            cout<<"Please specify the client home";
         }
         endpointUri = endpointURI;

         if (endpointUri.empty())
         {
            endpointUri = getEndpointUriOfExchangeTrader();
         }


         init(clientHome,endpointUri);

         populateServicesForExchangeTrader();

      }


      void WSF_CALL
      ExchangeTraderStub::populateServicesForExchangeTrader()
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

         svc_qname = axutil_qname_create(Environment::getEnv(),"ExchangeTrader" ,NULL, NULL);
         axis2_svc_set_qname (svc, Environment::getEnv(), svc_qname);
		 axutil_qname_free(svc_qname,Environment::getEnv());

         /* creating the operations*/

         
           op_qname = axutil_qname_create(Environment::getEnv(),
                                         "login" ,
                                         "http://www.wso2.org",
                                         NULL);
           op = axis2_op_create_with_qname(Environment::getEnv(), op_qname);
           axutil_qname_free(op_qname,Environment::getEnv());

           
           axis2_op_set_msg_exchange_pattern(op, Environment::getEnv(), AXIS2_MEP_URI_OUT_ONLY);
             
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
                                         "registerClient" ,
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
                                         "registerFeedTarget" ,
                                         "http://www.wso2.org",
                                         NULL);
           op = axis2_op_create_with_qname(Environment::getEnv(), op_qname);
           axutil_qname_free(op_qname,Environment::getEnv());

           
           axis2_op_set_msg_exchange_pattern(op, Environment::getEnv(), AXIS2_MEP_URI_OUT_ONLY);
             
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

           
           axis2_op_set_msg_exchange_pattern(op, Environment::getEnv(), AXIS2_MEP_URI_OUT_ONLY);
             
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

           
           axis2_op_set_msg_exchange_pattern(op, Environment::getEnv(), AXIS2_MEP_URI_OUT_ONLY);
             
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
      ExchangeTraderStub::getEndpointUriOfExchangeTrader()
      {
        std::string endpoint_uri;
        /* set the address from here */
        
        endpoint_uri = string("http://nagoya.apache.org:5049/axis/services/echo");
            
        return endpoint_uri;
      }


  
         /**
          * Auto generated method signature
          * For "registerClient|http://www.wso2.org" operation.
          *
          * @param _registerClientRequest of the org_wso2_www_types::RegisterClientRequest
          *
          * @return org_wso2_www_types::RegisterClientResponse*
          */

         org_wso2_www_types::RegisterClientResponse* WSF_CALL ExchangeTraderStub::registerClient(org_wso2_www_types::RegisterClientRequest*  _registerClientRequest)
         {
            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;
            axiom_node_t *ret_node = NULL;

            const axis2_char_t *soap_action = NULL;
            axutil_qname_t *op_qname =  NULL;
            axiom_node_t *payload = NULL;
            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            org_wso2_www_types::RegisterClientResponse* ret_val;
            
                                payload = _registerClientRequest->serialize(NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           
	    svc_client = serviceClient->getAxis2SvcClient();
            
           
            
            

	    options = clientOptions->getAxis2Options();
            if (NULL == options)
            {
                AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
                AXIS2_LOG_ERROR(Environment::getEnv()->log, AXIS2_LOG_SI, "options is null in stub");
                return (org_wso2_www_types::RegisterClientResponse*)NULL;
            }
            soap_act = axis2_options_get_soap_action( options, Environment::getEnv() );
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "registerClient";
              soap_act = axutil_string_create(Environment::getEnv(), "registerClient");
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
                        return (org_wso2_www_types::RegisterClientResponse*)NULL;
                    }
                    ret_val = new org_wso2_www_types::RegisterClientResponse();

                    if(ret_val->deserialize(&ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                    {
                        if(ret_val != NULL)
                        {
                           delete ret_val;
                        }

                        AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "NULL returned from the _deserialize: "
                                                                "This should be due to an invalid XML");
                        return (org_wso2_www_types::RegisterClientResponse*)NULL;
                    }

                   
                            return ret_val;
                       
        }
        
         /**
          * auto generated method signature for in only mep invocations
          * for "login|http://www.wso2.org" operation.
          * @param stub The stub (axis2_stub_t)
          * @param env environment ( mandatory)
          * @param _loginRequest of the org_wso2_www_types::LoginRequest
          *
          * @return 
          */
         bool WSF_CALL
         ExchangeTraderStub::login(org_wso2_www_types::LoginRequest*  _loginRequest)
         {
            axis2_status_t status;

            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;

            const axis2_char_t *soap_action = NULL;
            axutil_qname_t *op_qname =  NULL;
            axiom_node_t *payload = NULL;

            axutil_string_t *soap_act = NULL;
            
                                payload = _loginRequest->serialize(NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           
            svc_client = serviceClient->getAxis2SvcClient();

            
           
            
            


	    options = clientOptions->getAxis2Options();
            if ( NULL == options )
            { 
              AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
              AXIS2_LOG_ERROR(Environment::getEnv()->log, AXIS2_LOG_SI, "options is null in stub");
              return AXIS2_FAILURE;
            }
           
            soap_act = axis2_options_get_soap_action ( options, Environment::getEnv() );
            if ( NULL == soap_act )
            {
              soap_action = "login";
              soap_act = axutil_string_create(Environment::getEnv(), "login");
              axis2_options_set_soap_action(options, Environment::getEnv(), soap_act);    
            }
            
            axis2_options_set_soap_version(options, Environment::getEnv(), AXIOM_SOAP11 );
             
            op_qname = axutil_qname_create(Environment::getEnv(),
                                        "login" ,
                                        "http://www.wso2.org",
                                        NULL);
            status =  axis2_svc_client_send_robust_with_op_qname( svc_client, Environment::getEnv(), op_qname, payload);
            return status;

        }
       

        struct axis2_stub_ExchangeTrader_registerClient_callback_data
        {   
            IExchangeTraderCallback *callback;
          
        };

        static axis2_status_t WSF_CALL axis2_stub_on_error_ExchangeTrader_registerClient(axis2_callback_t *axis_callback, const axutil_env_t *env, int exception)
        {
            struct axis2_stub_ExchangeTrader_registerClient_callback_data* callback_data = NULL;
            callback_data = (struct axis2_stub_ExchangeTrader_registerClient_callback_data*)axis2_callback_get_data(axis_callback);
        
            IExchangeTraderCallback* callback = NULL;
            callback = callback_data->callback;
            callback->receiveError_registerClient(exception);
            return AXIS2_SUCCESS;
        } 

        axis2_status_t  AXIS2_CALL axis2_stub_on_complete_ExchangeTrader_registerClient(axis2_callback_t *axis_callback, const axutil_env_t *env)
        {
            struct axis2_stub_ExchangeTrader_registerClient_callback_data* callback_data = NULL;
            axis2_status_t status = AXIS2_SUCCESS;
            org_wso2_www_types::RegisterClientResponse* ret_val;
            

            axiom_node_t *ret_node = NULL;
            axiom_soap_envelope_t *soap_envelope = NULL;

            

            IExchangeTraderCallback *callback = NULL;

            callback_data = (struct axis2_stub_ExchangeTrader_registerClient_callback_data*)axis2_callback_get_data(axis_callback);

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
                        ret_val = new org_wso2_www_types::RegisterClientResponse();
     
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

                     
                     callback->receiveResult_registerClient(ret_val);
                         
 
            if(callback_data)
            {
                AXIS2_FREE(Environment::getEnv()->allocator, callback_data);
            }
            return AXIS2_SUCCESS;
        }

        /**
          * auto generated method signature for asynchronous invocations
          * for "registerClient|http://www.wso2.org" operation.
          * @param stub The stub
          * @param env environment ( mandatory)
          * @param _registerClientRequest of the org_wso2_www_types::RegisterClientRequest
          * @param user_data user data to be accessed by the callbacks
          * @param on_complete callback to handle on complete
          * @param on_error callback to handle on error
          */

         void WSF_CALL
        ExchangeTraderStub::start_registerClient(org_wso2_www_types::RegisterClientRequest*  _registerClientRequest,
                                IExchangeTraderCallback* cb)
         {

            axis2_callback_t *callback = NULL;

            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;

            const axis2_char_t *soap_action = NULL;
            axiom_node_t *payload = NULL;

            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            
            
            struct axis2_stub_ExchangeTrader_registerClient_callback_data *callback_data;

            callback_data = (struct axis2_stub_ExchangeTrader_registerClient_callback_data*) AXIS2_MALLOC(Environment::getEnv()->allocator, 
                                    sizeof(struct axis2_stub_ExchangeTrader_registerClient_callback_data));
            if(NULL == callback_data)
            {
                AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "Can not allocate memory for the callback data structures");
                return;
            }
            

            
                                payload = _registerClientRequest->serialize(NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           

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
              soap_action = "registerClient";
              soap_act = axutil_string_create(Environment::getEnv(), "registerClient");
              axis2_options_set_soap_action(options, Environment::getEnv(), soap_act);
            }
            
            axis2_options_set_soap_version(options, Environment::getEnv(), AXIOM_SOAP11);
             

            callback = axis2_callback_create(Environment::getEnv());
            /* Set our on_complete function pointer to the callback object */
            axis2_callback_set_on_complete(callback, axis2_stub_on_complete_ExchangeTrader_registerClient);
            /* Set our on_error function pointer to the callback object */
            axis2_callback_set_on_error(callback, axis2_stub_on_error_ExchangeTrader_registerClient);

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

         
         /**
          * auto generated method signature for in only mep invocations
          * for "registerFeedTarget|http://www.wso2.org" operation.
          * @param stub The stub (axis2_stub_t)
          * @param env environment ( mandatory)
          * @param _registerFeedTargetRequest of the org_wso2_www_types::RegisterFeedTargetRequest
          *
          * @return 
          */
         bool WSF_CALL
         ExchangeTraderStub::registerFeedTarget(org_wso2_www_types::RegisterFeedTargetRequest*  _registerFeedTargetRequest)
         {
            axis2_status_t status;

            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;

            const axis2_char_t *soap_action = NULL;
            axutil_qname_t *op_qname =  NULL;
            axiom_node_t *payload = NULL;

            axutil_string_t *soap_act = NULL;
            
                                payload = _registerFeedTargetRequest->serialize(NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           
            svc_client = serviceClient->getAxis2SvcClient();

            
           
            
            


	    options = clientOptions->getAxis2Options();
            if ( NULL == options )
            { 
              AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
              AXIS2_LOG_ERROR(Environment::getEnv()->log, AXIS2_LOG_SI, "options is null in stub");
              return AXIS2_FAILURE;
            }
           
            soap_act = axis2_options_get_soap_action ( options, Environment::getEnv() );
            if ( NULL == soap_act )
            {
              soap_action = "registerFeedTarget";
              soap_act = axutil_string_create(Environment::getEnv(), "registerFeedTarget");
              axis2_options_set_soap_action(options, Environment::getEnv(), soap_act);    
            }
            
            axis2_options_set_soap_version(options, Environment::getEnv(), AXIOM_SOAP11 );
             
            op_qname = axutil_qname_create(Environment::getEnv(),
                                        "registerFeedTarget" ,
                                        "http://www.wso2.org",
                                        NULL);
            status =  axis2_svc_client_send_robust_with_op_qname( svc_client, Environment::getEnv(), op_qname, payload);
            return status;

        }
       
         /**
          * auto generated method signature for in only mep invocations
          * for "sell|http://www.wso2.org" operation.
          * @param stub The stub (axis2_stub_t)
          * @param env environment ( mandatory)
          * @param _sellRequest_ex of the org_wso2_www_types::SellRequest_ex
          *
          * @return 
          */
         bool WSF_CALL
         ExchangeTraderStub::sell(org_wso2_www_types::SellRequest_ex*  _sellRequest_ex)
         {
            axis2_status_t status;

            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;

            const axis2_char_t *soap_action = NULL;
            axutil_qname_t *op_qname =  NULL;
            axiom_node_t *payload = NULL;

            axutil_string_t *soap_act = NULL;
            
                                payload = _sellRequest_ex->serialize(NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           
            svc_client = serviceClient->getAxis2SvcClient();

            
           
            
            


	    options = clientOptions->getAxis2Options();
            if ( NULL == options )
            { 
              AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
              AXIS2_LOG_ERROR(Environment::getEnv()->log, AXIS2_LOG_SI, "options is null in stub");
              return AXIS2_FAILURE;
            }
           
            soap_act = axis2_options_get_soap_action ( options, Environment::getEnv() );
            if ( NULL == soap_act )
            {
              soap_action = "sell";
              soap_act = axutil_string_create(Environment::getEnv(), "sell");
              axis2_options_set_soap_action(options, Environment::getEnv(), soap_act);    
            }
            
            axis2_options_set_soap_version(options, Environment::getEnv(), AXIOM_SOAP11 );
             
            op_qname = axutil_qname_create(Environment::getEnv(),
                                        "sell" ,
                                        "http://www.wso2.org",
                                        NULL);
            status =  axis2_svc_client_send_robust_with_op_qname( svc_client, Environment::getEnv(), op_qname, payload);
            return status;

        }
       
         /**
          * auto generated method signature for in only mep invocations
          * for "buy|http://www.wso2.org" operation.
          * @param stub The stub (axis2_stub_t)
          * @param env environment ( mandatory)
          * @param _buyRequest_ex of the org_wso2_www_types::BuyRequest_ex
          *
          * @return 
          */
         bool WSF_CALL
         ExchangeTraderStub::buy(org_wso2_www_types::BuyRequest_ex*  _buyRequest_ex)
         {
            axis2_status_t status;

            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;

            const axis2_char_t *soap_action = NULL;
            axutil_qname_t *op_qname =  NULL;
            axiom_node_t *payload = NULL;

            axutil_string_t *soap_act = NULL;
            
                                payload = _buyRequest_ex->serialize(NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           
            svc_client = serviceClient->getAxis2SvcClient();

            
           
            
            


	    options = clientOptions->getAxis2Options();
            if ( NULL == options )
            { 
              AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
              AXIS2_LOG_ERROR(Environment::getEnv()->log, AXIS2_LOG_SI, "options is null in stub");
              return AXIS2_FAILURE;
            }
           
            soap_act = axis2_options_get_soap_action ( options, Environment::getEnv() );
            if ( NULL == soap_act )
            {
              soap_action = "buy";
              soap_act = axutil_string_create(Environment::getEnv(), "buy");
              axis2_options_set_soap_action(options, Environment::getEnv(), soap_act);    
            }
            
            axis2_options_set_soap_version(options, Environment::getEnv(), AXIOM_SOAP11 );
             
            op_qname = axutil_qname_create(Environment::getEnv(),
                                        "buy" ,
                                        "http://www.wso2.org",
                                        NULL);
            status =  axis2_svc_client_send_robust_with_op_qname( svc_client, Environment::getEnv(), op_qname, payload);
            return status;

        }
       

