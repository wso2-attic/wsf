

      /**
       * axis2_stub_TraderExchange.c
       *
       * This file was auto-generated from WSDL for "TraderExchange|http://www.wso2.org" service
       * by the Apache Axis2/C version: #axisVersion# #today#
       */

      #include "axis2_stub_TraderExchange.h"

      /**
       * axis2_stub_TraderExchange C implementation
       */

      axis2_stub_t*
      axis2_stub_TraderExchange_create (const axutil_env_t *env,
                                      axis2_char_t *client_home,
                                      axis2_char_t *endpoint_uri)
      {
         axis2_stub_t *stub = NULL;
         axis2_endpoint_ref_t *endpoint_ref = NULL;
         AXIS2_FUNC_PARAM_CHECK ( client_home, env, NULL)

         if (NULL == endpoint_uri )
         {
            endpoint_uri = axis2_stub_TraderExchange_get_endpoint_uri_from_wsdl( env );
         }

         endpoint_ref = axis2_endpoint_ref_create(env, endpoint_uri);

         stub = axis2_stub_create_with_endpoint_ref_and_client_home ( env, endpoint_ref, client_home );
         axis2_stub_TraderExchange_populate_services( stub, env );
         return stub;
      }


      void axis2_stub_TraderExchange_populate_services( axis2_stub_t *stub, const axutil_env_t *env)
      {
         axis2_svc_client_t *svc_client = NULL;
         axutil_qname_t *svc_qname =  NULL;
         axutil_qname_t *op_qname =  NULL;
         axis2_svc_t *svc = NULL;
         axis2_op_t *op = NULL;

         /* Modifying the Service */
         svc_client = axis2_stub_get_svc_client (stub, env );
         svc = (axis2_svc_t*)axis2_svc_client_get_svc( svc_client, env );
         axutil_qname_create(env,"TraderExchange" ,NULL, NULL);
         axis2_svc_set_qname (svc, env, svc_qname);

         /* creating the operations*/

         

           op_qname = axutil_qname_create(env,
                                         "update" ,
                                         "http://www.wso2.org",
                                         NULL);
           op = axis2_op_create_with_qname(env, op_qname);
           
               axis2_op_set_msg_exchange_pattern(op, env, AXIS2_MEP_URI_IN_ONLY);
             
           axis2_svc_add_op(svc, env, op);

         
      }

      /**
       *return end point picked from wsdl
       */
      axis2_char_t*
      axis2_stub_TraderExchange_get_endpoint_uri_from_wsdl ( const axutil_env_t *env )
      {
        axis2_char_t *endpoint_uri = NULL;
        /* set the address from here */
        
              endpoint_uri = "http://nagoya.apache.org:5049/axis/services/echo";
            
        return endpoint_uri;
      }


  
         /**
          * auto generated method signature for in only mep invocations
          * for "update|http://www.wso2.org" operation.
          
          * @param updateRequest2
          * @param on_complete callback to handle on complete
          * @param on_error callback to handle on error
          */
         axis2_status_t
         axis2_stub_TraderExchange_update( axis2_stub_t *stub, const axutil_env_t *env  ,
                                                 axis2_updateRequest_t* updateRequest2)
         {
            axis2_status_t status;

            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;

            const axis2_char_t *soap_action = NULL;
            axutil_qname_t *op_qname =  NULL;
            axiom_node_t *payload = NULL;

            
            
                            payload = axis2_updateRequest_serialize(updateRequest2, env, NULL, AXIS2_FALSE);
                        


            options = axis2_stub_get_options( stub, env);
            if ( NULL == options )
            {
              AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "options is null in stub: Error code:"
                      " %d :: %s", env->error->error_number,
                      AXIS2_ERROR_GET_MESSAGE(env->error));
              return AXIS2_FAILURE;
            }
            svc_client = axis2_stub_get_svc_client (stub, env );
            soap_action = axis2_options_get_action ( options, env );
            if ( NULL == soap_action )
            {
              soap_action = "\"\"";
              axis2_options_set_action( options, env, soap_action );
            }
            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP11 );
             
            op_qname = axutil_qname_create(env,
                                        "update" ,
                                        "http://www.wso2.org",
                                        NULL);
            status =  axis2_svc_client_send_robust_with_op_qname( svc_client, env, op_qname, payload);
            return status;

        }
       

