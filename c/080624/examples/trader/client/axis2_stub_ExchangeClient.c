

      /**
       * axis2_stub_ExchangeClient.c
       *
       * This file was auto-generated from WSDL for "ExchangeClient|http://www.wso2.org" service
       * by the Apache Axis2/C version: #axisVersion# #today#
       */

      #include "axis2_stub_ExchangeClient.h"

      /**
       * axis2_stub_ExchangeClient C implementation
       */

      axis2_stub_t*
      axis2_stub_ExchangeClient_create (const axutil_env_t *env,
                                      axis2_char_t *client_home,
                                      axis2_char_t *endpoint_uri)
      {
         axis2_stub_t *stub = NULL;
         axis2_endpoint_ref_t *endpoint_ref = NULL;
         AXIS2_FUNC_PARAM_CHECK ( client_home, env, NULL)

         if (NULL == endpoint_uri )
         {
            endpoint_uri = axis2_stub_ExchangeClient_get_endpoint_uri_from_wsdl( env );
         }

         endpoint_ref = axis2_endpoint_ref_create(env, endpoint_uri);

         stub = axis2_stub_create_with_endpoint_ref_and_client_home ( env, endpoint_ref, client_home );
         axis2_stub_ExchangeClient_populate_services( stub, env );
         return stub;
      }


      void axis2_stub_ExchangeClient_populate_services( axis2_stub_t *stub, const axutil_env_t *env)
      {
         axis2_svc_client_t *svc_client = NULL;
         axutil_qname_t *svc_qname =  NULL;
         axutil_qname_t *op_qname =  NULL;
         axis2_svc_t *svc = NULL;
         axis2_op_t *op = NULL;

         /* Modifying the Service */
         svc_client = axis2_stub_get_svc_client (stub, env );
         svc = (axis2_svc_t*)axis2_svc_client_get_svc( svc_client, env );
         axutil_qname_create(env,"ExchangeClient" ,NULL, NULL);
         axis2_svc_set_qname (svc, env, svc_qname);

         /* creating the operations*/

         

           op_qname = axutil_qname_create(env,
                                         "getInfo" ,
                                         "http://www.wso2.org",
                                         NULL);
           op = axis2_op_create_with_qname(env, op_qname);
           
               axis2_op_set_msg_exchange_pattern(op, env, AXIS2_MEP_URI_OUT_IN);
             
           axis2_svc_add_op(svc, env, op);

         
      }

      /**
       *return end point picked from wsdl
       */
      axis2_char_t*
      axis2_stub_ExchangeClient_get_endpoint_uri_from_wsdl ( const axutil_env_t *env )
      {
        axis2_char_t *endpoint_uri = NULL;
        /* set the address from here */
        
              endpoint_uri = "http://nagoya.apache.org:5049/axis/services/echo";
            
        return endpoint_uri;
      }


  
         /**
          * auto generated method signature
          * for "getInfo|http://www.wso2.org" operation.
          * @param getInfoRequest4
          * @return
          */
         axis2_getInfoResponse_t* axis2_stub_ExchangeClient_getInfo( axis2_stub_t *stub, const axutil_env_t *env,
                                              axis2_getInfoRequest_t* getInfoRequest4)
         {
            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;
            axiom_node_t *ret_node = NULL;

            const axis2_char_t *soap_action = NULL;
            axutil_qname_t *op_qname =  NULL;
            axiom_node_t *payload = NULL;
            axis2_getInfoResponse_t* ret_val = NULL;
            
                            payload = axis2_getInfoRequest_serialize(getInfoRequest4, env, NULL, AXIS2_FALSE);
                        


            options = axis2_stub_get_options( stub, env);
            if ( NULL == options )
            {
              AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "options is null in stub: Error code:"
                    " %d :: %s", env->error->error_number,
                    AXIS2_ERROR_GET_MESSAGE(env->error));
              return NULL;
            }
            svc_client = axis2_stub_get_svc_client(stub, env );
            soap_action = axis2_options_get_action( options, env );
            if ( NULL == soap_action )
            {
              soap_action = "\"\"";
              axis2_options_set_action( options, env, soap_action );
            }
            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP11 );
            
            op_qname = axutil_qname_create(env,
                                        "getInfo" ,
                                        "http://www.wso2.org",
                                        NULL);
            ret_node =  axis2_svc_client_send_receive_with_op_qname( svc_client, env, op_qname, payload);


            
                    if ( NULL == ret_node )
                    {
                        return NULL;
                    }
                    ret_val = axis2_getInfoResponse_create(env);

                    axis2_getInfoResponse_deserialize(ret_val, env, ret_node );
                    return ret_val;
                
        }
        
        /**
          * auto generated method signature for asynchronous invocations
          * for "getInfo|http://www.wso2.org" operation.
          
          * @param getInfoRequest4
          * @param on_complete callback to handle on complete
          * @param on_error callback to handle on error
          */
         
         void axis2_stub_ExchangeClient_getInfo_start( axis2_stub_t *stub, const axutil_env_t *env,
                                                    axis2_getInfoRequest_t* getInfoRequest4,
                                                  axis2_status_t ( AXIS2_CALL *on_complete ) (struct axis2_callback *, const axutil_env_t *) ,
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (struct axis2_callback *, const axutil_env_t *, int ) )
         {

            axis2_callback_t *callback = NULL;

            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;

            const axis2_char_t *soap_action = NULL;
            axiom_node_t *payload = NULL;

            
            
                            payload = axis2_getInfoRequest_serialize(getInfoRequest4, env, NULL, AXIS2_FALSE);
                        


            options = axis2_stub_get_options( stub, env);
            if ( NULL == options )
            {
              AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "options is null in stub: Error code:"
                      " %d :: %s", env->error->error_number,
                      AXIS2_ERROR_GET_MESSAGE(env->error));
              return;
            }
            svc_client = axis2_stub_get_svc_client (stub, env );
            soap_action =axis2_options_get_action ( options, env );
            if ( NULL == soap_action )
            {
              soap_action = "\"\"";
              axis2_options_set_action( options, env, soap_action );
            }
            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP11 );
             

            callback = axis2_callback_create(env);
            /* Set our on_complete fucntion pointer to the callback object */
            axis2_callback_set_on_complete(callback, on_complete);
            /* Set our on_error function pointer to the callback object */
            axis2_callback_set_on_error(callback, on_error);

            /* Send request */
            axis2_svc_client_send_receive_non_blocking(svc_client, env, payload, callback);
         }

         

