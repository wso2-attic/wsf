

      /**
       * axis2_stub_StatisticsAdmin.c
       *
       * This file was auto-generated from WSDL for "StatisticsAdmin|http://services.statistics.carbon.wso2.org" service
       * by the Apache Axis2/Java version: 1.5.1  Built on : Oct 19, 2009 (10:59:00 EDT)
       */

      #include "axis2_stub_StatisticsAdmin.h"
      #include <axis2_msg.h>
      #include <axis2_policy_include.h>
      #include <neethi_engine.h>


      /**
       * axis2_stub_StatisticsAdmin C implementation
       */

      axis2_stub_t* AXIS2_CALL
      axis2_stub_create_StatisticsAdmin(const axutil_env_t *env,
                                      const axis2_char_t *client_home,
                                      const axis2_char_t *endpoint_uri)
      {
         axis2_stub_t *stub = NULL;
         axis2_endpoint_ref_t *endpoint_ref = NULL;
         AXIS2_FUNC_PARAM_CHECK (client_home, env, NULL)

         if (NULL == endpoint_uri)
         {
            endpoint_uri = axis2_stub_get_endpoint_uri_of_StatisticsAdmin(env);
         }

         endpoint_ref = axis2_endpoint_ref_create(env, endpoint_uri);

         stub = axis2_stub_create_with_endpoint_ref_and_client_home (env, endpoint_ref, client_home);

         if (NULL == stub)
         {
            if(NULL != endpoint_ref)
            {
                axis2_endpoint_ref_free(endpoint_ref, env);
            }
            return NULL;
         }


         axis2_stub_populate_services_for_StatisticsAdmin(stub, env);
         return stub;
      }


      void AXIS2_CALL
      axis2_stub_populate_services_for_StatisticsAdmin(axis2_stub_t *stub, const axutil_env_t *env)
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
         axis2_status_t status;

         /* Modifying the Service */
         svc_client = axis2_stub_get_svc_client (stub, env );
         svc = (axis2_svc_t*)axis2_svc_client_get_svc( svc_client, env );

         annon_op = axis2_svc_get_op_with_name(svc, env, AXIS2_ANON_OUT_IN_OP);
         msg_out = axis2_op_get_msg(annon_op, env, AXIS2_MSG_OUT);
         msg_in = axis2_op_get_msg(annon_op, env, AXIS2_MSG_IN);
         msg_out_fault = axis2_op_get_msg(annon_op, env, AXIS2_MSG_OUT_FAULT);
         msg_in_fault = axis2_op_get_msg(annon_op, env, AXIS2_MSG_IN_FAULT);

         svc_qname = axutil_qname_create(env,"StatisticsAdmin" ,NULL, NULL);
         axis2_svc_set_qname (svc, env, svc_qname);
		 axutil_qname_free(svc_qname,env);

         /* creating the operations*/

         
           op_qname = axutil_qname_create(env,
                                         "getMaxServiceResponseTime" ,
                                         "http://services.statistics.carbon.wso2.org",
                                         NULL);
           op = axis2_op_create_with_qname(env, op_qname);
           
               axis2_op_set_msg_exchange_pattern(op, env, AXIS2_MEP_URI_OUT_IN);
             
           axis2_msg_increment_ref(msg_out, env);
           axis2_msg_increment_ref(msg_in, env);
           axis2_msg_increment_ref(msg_out_fault, env);
           axis2_msg_increment_ref(msg_in_fault, env);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT, msg_out);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN, msg_in);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT_FAULT, msg_out_fault);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN_FAULT, msg_in_fault);
       
           
           axis2_svc_add_op(svc, env, op);
         
           op_qname = axutil_qname_create(env,
                                         "getServiceRequestCount" ,
                                         "http://services.statistics.carbon.wso2.org",
                                         NULL);
           op = axis2_op_create_with_qname(env, op_qname);
           
               axis2_op_set_msg_exchange_pattern(op, env, AXIS2_MEP_URI_OUT_IN);
             
           axis2_msg_increment_ref(msg_out, env);
           axis2_msg_increment_ref(msg_in, env);
           axis2_msg_increment_ref(msg_out_fault, env);
           axis2_msg_increment_ref(msg_in_fault, env);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT, msg_out);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN, msg_in);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT_FAULT, msg_out_fault);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN_FAULT, msg_in_fault);
       
           
           axis2_svc_add_op(svc, env, op);
         
           op_qname = axutil_qname_create(env,
                                         "getSystemResponseCount" ,
                                         "http://services.statistics.carbon.wso2.org",
                                         NULL);
           op = axis2_op_create_with_qname(env, op_qname);
           
               axis2_op_set_msg_exchange_pattern(op, env, AXIS2_MEP_URI_OUT_IN);
             
           axis2_msg_increment_ref(msg_out, env);
           axis2_msg_increment_ref(msg_in, env);
           axis2_msg_increment_ref(msg_out_fault, env);
           axis2_msg_increment_ref(msg_in_fault, env);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT, msg_out);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN, msg_in);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT_FAULT, msg_out_fault);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN_FAULT, msg_in_fault);
       
           
           axis2_svc_add_op(svc, env, op);
         
           op_qname = axutil_qname_create(env,
                                         "getOperationResponseCount" ,
                                         "http://services.statistics.carbon.wso2.org",
                                         NULL);
           op = axis2_op_create_with_qname(env, op_qname);
           
               axis2_op_set_msg_exchange_pattern(op, env, AXIS2_MEP_URI_OUT_IN);
             
           axis2_msg_increment_ref(msg_out, env);
           axis2_msg_increment_ref(msg_in, env);
           axis2_msg_increment_ref(msg_out_fault, env);
           axis2_msg_increment_ref(msg_in_fault, env);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT, msg_out);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN, msg_in);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT_FAULT, msg_out_fault);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN_FAULT, msg_in_fault);
       
           
           axis2_svc_add_op(svc, env, op);
         
           op_qname = axutil_qname_create(env,
                                         "getAvgOperationResponseTime" ,
                                         "http://services.statistics.carbon.wso2.org",
                                         NULL);
           op = axis2_op_create_with_qname(env, op_qname);
           
               axis2_op_set_msg_exchange_pattern(op, env, AXIS2_MEP_URI_OUT_IN);
             
           axis2_msg_increment_ref(msg_out, env);
           axis2_msg_increment_ref(msg_in, env);
           axis2_msg_increment_ref(msg_out_fault, env);
           axis2_msg_increment_ref(msg_in_fault, env);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT, msg_out);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN, msg_in);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT_FAULT, msg_out_fault);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN_FAULT, msg_in_fault);
       
           
           axis2_svc_add_op(svc, env, op);
         
           op_qname = axutil_qname_create(env,
                                         "getOperationStatistics" ,
                                         "http://services.statistics.carbon.wso2.org",
                                         NULL);
           op = axis2_op_create_with_qname(env, op_qname);
           
               axis2_op_set_msg_exchange_pattern(op, env, AXIS2_MEP_URI_OUT_IN);
             
           axis2_msg_increment_ref(msg_out, env);
           axis2_msg_increment_ref(msg_in, env);
           axis2_msg_increment_ref(msg_out_fault, env);
           axis2_msg_increment_ref(msg_in_fault, env);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT, msg_out);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN, msg_in);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT_FAULT, msg_out_fault);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN_FAULT, msg_in_fault);
       
           
           axis2_svc_add_op(svc, env, op);
         
           op_qname = axutil_qname_create(env,
                                         "getMinSystemResponseTime" ,
                                         "http://services.statistics.carbon.wso2.org",
                                         NULL);
           op = axis2_op_create_with_qname(env, op_qname);
           
               axis2_op_set_msg_exchange_pattern(op, env, AXIS2_MEP_URI_OUT_IN);
             
           axis2_msg_increment_ref(msg_out, env);
           axis2_msg_increment_ref(msg_in, env);
           axis2_msg_increment_ref(msg_out_fault, env);
           axis2_msg_increment_ref(msg_in_fault, env);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT, msg_out);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN, msg_in);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT_FAULT, msg_out_fault);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN_FAULT, msg_in_fault);
       
           
           axis2_svc_add_op(svc, env, op);
         
           op_qname = axutil_qname_create(env,
                                         "getSystemFaultCount" ,
                                         "http://services.statistics.carbon.wso2.org",
                                         NULL);
           op = axis2_op_create_with_qname(env, op_qname);
           
               axis2_op_set_msg_exchange_pattern(op, env, AXIS2_MEP_URI_OUT_IN);
             
           axis2_msg_increment_ref(msg_out, env);
           axis2_msg_increment_ref(msg_in, env);
           axis2_msg_increment_ref(msg_out_fault, env);
           axis2_msg_increment_ref(msg_in_fault, env);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT, msg_out);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN, msg_in);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT_FAULT, msg_out_fault);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN_FAULT, msg_in_fault);
       
           
           axis2_svc_add_op(svc, env, op);
         
           op_qname = axutil_qname_create(env,
                                         "getMaxSystemResponseTime" ,
                                         "http://services.statistics.carbon.wso2.org",
                                         NULL);
           op = axis2_op_create_with_qname(env, op_qname);
           
               axis2_op_set_msg_exchange_pattern(op, env, AXIS2_MEP_URI_OUT_IN);
             
           axis2_msg_increment_ref(msg_out, env);
           axis2_msg_increment_ref(msg_in, env);
           axis2_msg_increment_ref(msg_out_fault, env);
           axis2_msg_increment_ref(msg_in_fault, env);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT, msg_out);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN, msg_in);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT_FAULT, msg_out_fault);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN_FAULT, msg_in_fault);
       
           
           axis2_svc_add_op(svc, env, op);
         
           op_qname = axutil_qname_create(env,
                                         "getServiceFaultCount" ,
                                         "http://services.statistics.carbon.wso2.org",
                                         NULL);
           op = axis2_op_create_with_qname(env, op_qname);
           
               axis2_op_set_msg_exchange_pattern(op, env, AXIS2_MEP_URI_OUT_IN);
             
           axis2_msg_increment_ref(msg_out, env);
           axis2_msg_increment_ref(msg_in, env);
           axis2_msg_increment_ref(msg_out_fault, env);
           axis2_msg_increment_ref(msg_in_fault, env);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT, msg_out);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN, msg_in);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT_FAULT, msg_out_fault);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN_FAULT, msg_in_fault);
       
           
           axis2_svc_add_op(svc, env, op);
         
           op_qname = axutil_qname_create(env,
                                         "getMinServiceResponseTime" ,
                                         "http://services.statistics.carbon.wso2.org",
                                         NULL);
           op = axis2_op_create_with_qname(env, op_qname);
           
               axis2_op_set_msg_exchange_pattern(op, env, AXIS2_MEP_URI_OUT_IN);
             
           axis2_msg_increment_ref(msg_out, env);
           axis2_msg_increment_ref(msg_in, env);
           axis2_msg_increment_ref(msg_out_fault, env);
           axis2_msg_increment_ref(msg_in_fault, env);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT, msg_out);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN, msg_in);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT_FAULT, msg_out_fault);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN_FAULT, msg_in_fault);
       
           
           axis2_svc_add_op(svc, env, op);
         
           op_qname = axutil_qname_create(env,
                                         "getMaxOperationResponseTime" ,
                                         "http://services.statistics.carbon.wso2.org",
                                         NULL);
           op = axis2_op_create_with_qname(env, op_qname);
           
               axis2_op_set_msg_exchange_pattern(op, env, AXIS2_MEP_URI_OUT_IN);
             
           axis2_msg_increment_ref(msg_out, env);
           axis2_msg_increment_ref(msg_in, env);
           axis2_msg_increment_ref(msg_out_fault, env);
           axis2_msg_increment_ref(msg_in_fault, env);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT, msg_out);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN, msg_in);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT_FAULT, msg_out_fault);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN_FAULT, msg_in_fault);
       
           
           axis2_svc_add_op(svc, env, op);
         
           op_qname = axutil_qname_create(env,
                                         "getServiceStatistics" ,
                                         "http://services.statistics.carbon.wso2.org",
                                         NULL);
           op = axis2_op_create_with_qname(env, op_qname);
           
               axis2_op_set_msg_exchange_pattern(op, env, AXIS2_MEP_URI_OUT_IN);
             
           axis2_msg_increment_ref(msg_out, env);
           axis2_msg_increment_ref(msg_in, env);
           axis2_msg_increment_ref(msg_out_fault, env);
           axis2_msg_increment_ref(msg_in_fault, env);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT, msg_out);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN, msg_in);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT_FAULT, msg_out_fault);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN_FAULT, msg_in_fault);
       
           
           axis2_svc_add_op(svc, env, op);
         
           op_qname = axutil_qname_create(env,
                                         "getOperationFaultCount" ,
                                         "http://services.statistics.carbon.wso2.org",
                                         NULL);
           op = axis2_op_create_with_qname(env, op_qname);
           
               axis2_op_set_msg_exchange_pattern(op, env, AXIS2_MEP_URI_OUT_IN);
             
           axis2_msg_increment_ref(msg_out, env);
           axis2_msg_increment_ref(msg_in, env);
           axis2_msg_increment_ref(msg_out_fault, env);
           axis2_msg_increment_ref(msg_in_fault, env);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT, msg_out);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN, msg_in);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT_FAULT, msg_out_fault);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN_FAULT, msg_in_fault);
       
           
           axis2_svc_add_op(svc, env, op);
         
           op_qname = axutil_qname_create(env,
                                         "getAvgServiceResponseTime" ,
                                         "http://services.statistics.carbon.wso2.org",
                                         NULL);
           op = axis2_op_create_with_qname(env, op_qname);
           
               axis2_op_set_msg_exchange_pattern(op, env, AXIS2_MEP_URI_OUT_IN);
             
           axis2_msg_increment_ref(msg_out, env);
           axis2_msg_increment_ref(msg_in, env);
           axis2_msg_increment_ref(msg_out_fault, env);
           axis2_msg_increment_ref(msg_in_fault, env);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT, msg_out);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN, msg_in);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT_FAULT, msg_out_fault);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN_FAULT, msg_in_fault);
       
           
           axis2_svc_add_op(svc, env, op);
         
           op_qname = axutil_qname_create(env,
                                         "getServiceResponseCount" ,
                                         "http://services.statistics.carbon.wso2.org",
                                         NULL);
           op = axis2_op_create_with_qname(env, op_qname);
           
               axis2_op_set_msg_exchange_pattern(op, env, AXIS2_MEP_URI_OUT_IN);
             
           axis2_msg_increment_ref(msg_out, env);
           axis2_msg_increment_ref(msg_in, env);
           axis2_msg_increment_ref(msg_out_fault, env);
           axis2_msg_increment_ref(msg_in_fault, env);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT, msg_out);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN, msg_in);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT_FAULT, msg_out_fault);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN_FAULT, msg_in_fault);
       
           
           axis2_svc_add_op(svc, env, op);
         
           op_qname = axutil_qname_create(env,
                                         "getSystemRequestCount" ,
                                         "http://services.statistics.carbon.wso2.org",
                                         NULL);
           op = axis2_op_create_with_qname(env, op_qname);
           
               axis2_op_set_msg_exchange_pattern(op, env, AXIS2_MEP_URI_OUT_IN);
             
           axis2_msg_increment_ref(msg_out, env);
           axis2_msg_increment_ref(msg_in, env);
           axis2_msg_increment_ref(msg_out_fault, env);
           axis2_msg_increment_ref(msg_in_fault, env);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT, msg_out);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN, msg_in);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT_FAULT, msg_out_fault);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN_FAULT, msg_in_fault);
       
           
           axis2_svc_add_op(svc, env, op);
         
           op_qname = axutil_qname_create(env,
                                         "getMinOperationResponseTime" ,
                                         "http://services.statistics.carbon.wso2.org",
                                         NULL);
           op = axis2_op_create_with_qname(env, op_qname);
           
               axis2_op_set_msg_exchange_pattern(op, env, AXIS2_MEP_URI_OUT_IN);
             
           axis2_msg_increment_ref(msg_out, env);
           axis2_msg_increment_ref(msg_in, env);
           axis2_msg_increment_ref(msg_out_fault, env);
           axis2_msg_increment_ref(msg_in_fault, env);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT, msg_out);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN, msg_in);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT_FAULT, msg_out_fault);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN_FAULT, msg_in_fault);
       
           
           axis2_svc_add_op(svc, env, op);
         
           op_qname = axutil_qname_create(env,
                                         "getAvgSystemResponseTime" ,
                                         "http://services.statistics.carbon.wso2.org",
                                         NULL);
           op = axis2_op_create_with_qname(env, op_qname);
           
               axis2_op_set_msg_exchange_pattern(op, env, AXIS2_MEP_URI_OUT_IN);
             
           axis2_msg_increment_ref(msg_out, env);
           axis2_msg_increment_ref(msg_in, env);
           axis2_msg_increment_ref(msg_out_fault, env);
           axis2_msg_increment_ref(msg_in_fault, env);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT, msg_out);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN, msg_in);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT_FAULT, msg_out_fault);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN_FAULT, msg_in_fault);
       
           
           axis2_svc_add_op(svc, env, op);
         
           op_qname = axutil_qname_create(env,
                                         "getSystemStatistics" ,
                                         "http://services.statistics.carbon.wso2.org",
                                         NULL);
           op = axis2_op_create_with_qname(env, op_qname);
           
               axis2_op_set_msg_exchange_pattern(op, env, AXIS2_MEP_URI_OUT_IN);
             
           axis2_msg_increment_ref(msg_out, env);
           axis2_msg_increment_ref(msg_in, env);
           axis2_msg_increment_ref(msg_out_fault, env);
           axis2_msg_increment_ref(msg_in_fault, env);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT, msg_out);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN, msg_in);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT_FAULT, msg_out_fault);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN_FAULT, msg_in_fault);
       
           
           axis2_svc_add_op(svc, env, op);
         
           op_qname = axutil_qname_create(env,
                                         "getOperationRequestCount" ,
                                         "http://services.statistics.carbon.wso2.org",
                                         NULL);
           op = axis2_op_create_with_qname(env, op_qname);
           
               axis2_op_set_msg_exchange_pattern(op, env, AXIS2_MEP_URI_OUT_IN);
             
           axis2_msg_increment_ref(msg_out, env);
           axis2_msg_increment_ref(msg_in, env);
           axis2_msg_increment_ref(msg_out_fault, env);
           axis2_msg_increment_ref(msg_in_fault, env);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT, msg_out);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN, msg_in);
           axis2_op_add_msg(op, env, AXIS2_MSG_OUT_FAULT, msg_out_fault);
           axis2_op_add_msg(op, env, AXIS2_MSG_IN_FAULT, msg_in_fault);
       
           
           axis2_svc_add_op(svc, env, op);
         
      }

      /**
       *return end point picked from wsdl
       */
      axis2_char_t* AXIS2_CALL
      axis2_stub_get_endpoint_uri_of_StatisticsAdmin( const axutil_env_t *env )
      {
        axis2_char_t *endpoint_uri = NULL;
        /* set the address from here */
        
              endpoint_uri = "https://192.168.175.1:9443/services/StatisticsAdmin.StatisticsAdminHttpsSoap12Endpoint/";
            
        return endpoint_uri;
      }


  
         /**
          * auto generated method signature
          * for "getMaxServiceResponseTime|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub (axis2_stub_t)
          * @param env environment ( mandatory)
          * @param _getMaxServiceResponseTime of the adb_getMaxServiceResponseTime_t*
          *
          * @return adb_getMaxServiceResponseTimeResponse_t*
          */

         adb_getMaxServiceResponseTimeResponse_t* AXIS2_CALL 
         axis2_stub_op_StatisticsAdmin_getMaxServiceResponseTime( axis2_stub_t *stub, const axutil_env_t *env,
                                               adb_getMaxServiceResponseTime_t* _getMaxServiceResponseTime)
         {
            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;
            axiom_node_t *ret_node = NULL;

            const axis2_char_t *soap_action = NULL;
            axutil_qname_t *op_qname =  NULL;
            axiom_node_t *payload = NULL;
            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            adb_getMaxServiceResponseTimeResponse_t* ret_val;
            
                                payload = adb_getMaxServiceResponseTime_serialize(_getMaxServiceResponseTime, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           
            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "options is null in stub");
                return (adb_getMaxServiceResponseTimeResponse_t*)NULL;
            }
            soap_act = axis2_options_get_soap_action( options, env );
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getMaxServiceResponseTime";
              soap_act = axutil_string_create(env, "urn:getMaxServiceResponseTime");
              axis2_options_set_soap_action(options, env, soap_act);    
            }

            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             
            ret_node =  axis2_svc_client_send_receive_with_op_qname( svc_client, env, op_qname, payload);
 
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);    
              
              axis2_options_set_action( options, env, NULL);
            }
            if(soap_act)
            {
              axutil_string_free(soap_act, env);
            }

            
            
                    if ( NULL == ret_node )
                    {
                        return (adb_getMaxServiceResponseTimeResponse_t*)NULL;
                    }
                    ret_val = adb_getMaxServiceResponseTimeResponse_create(env);

                    if(adb_getMaxServiceResponseTimeResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                    {
                        if(ret_val != NULL)
                        {
                            adb_getMaxServiceResponseTimeResponse_free(ret_val, env);
                        }

                        AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getMaxServiceResponseTimeResponse_deserialize: "
                                                                "This should be due to an invalid XML");
                        return (adb_getMaxServiceResponseTimeResponse_t*)NULL;
                    }

                   
                            return ret_val;
                       
        }
        
         /**
          * auto generated method signature
          * for "getServiceRequestCount|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub (axis2_stub_t)
          * @param env environment ( mandatory)
          * @param _getServiceRequestCount of the adb_getServiceRequestCount_t*
          *
          * @return adb_getServiceRequestCountResponse_t*
          */

         adb_getServiceRequestCountResponse_t* AXIS2_CALL 
         axis2_stub_op_StatisticsAdmin_getServiceRequestCount( axis2_stub_t *stub, const axutil_env_t *env,
                                               adb_getServiceRequestCount_t* _getServiceRequestCount)
         {
            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;
            axiom_node_t *ret_node = NULL;

            const axis2_char_t *soap_action = NULL;
            axutil_qname_t *op_qname =  NULL;
            axiom_node_t *payload = NULL;
            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            adb_getServiceRequestCountResponse_t* ret_val;
            
                                payload = adb_getServiceRequestCount_serialize(_getServiceRequestCount, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           
            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "options is null in stub");
                return (adb_getServiceRequestCountResponse_t*)NULL;
            }
            soap_act = axis2_options_get_soap_action( options, env );
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getServiceRequestCount";
              soap_act = axutil_string_create(env, "urn:getServiceRequestCount");
              axis2_options_set_soap_action(options, env, soap_act);    
            }

            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             
            ret_node =  axis2_svc_client_send_receive_with_op_qname( svc_client, env, op_qname, payload);
 
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);    
              
              axis2_options_set_action( options, env, NULL);
            }
            if(soap_act)
            {
              axutil_string_free(soap_act, env);
            }

            
            
                    if ( NULL == ret_node )
                    {
                        return (adb_getServiceRequestCountResponse_t*)NULL;
                    }
                    ret_val = adb_getServiceRequestCountResponse_create(env);

                    if(adb_getServiceRequestCountResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                    {
                        if(ret_val != NULL)
                        {
                            adb_getServiceRequestCountResponse_free(ret_val, env);
                        }

                        AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getServiceRequestCountResponse_deserialize: "
                                                                "This should be due to an invalid XML");
                        return (adb_getServiceRequestCountResponse_t*)NULL;
                    }

                   
                            return ret_val;
                       
        }
        
         /**
          * auto generated method signature
          * for "getSystemResponseCount|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub (axis2_stub_t)
          * @param env environment ( mandatory)
          *
          * @return adb_getSystemResponseCountResponse_t*
          */

         adb_getSystemResponseCountResponse_t* AXIS2_CALL 
         axis2_stub_op_StatisticsAdmin_getSystemResponseCount( axis2_stub_t *stub, const axutil_env_t *env)
         {
            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;
            axiom_node_t *ret_node = NULL;

            const axis2_char_t *soap_action = NULL;
            axutil_qname_t *op_qname =  NULL;
            axiom_node_t *payload = NULL;
            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            adb_getSystemResponseCountResponse_t* ret_val;
            
            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "options is null in stub");
                return (adb_getSystemResponseCountResponse_t*)NULL;
            }
            soap_act = axis2_options_get_soap_action( options, env );
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getSystemResponseCount";
              soap_act = axutil_string_create(env, "urn:getSystemResponseCount");
              axis2_options_set_soap_action(options, env, soap_act);    
            }

            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             
            ret_node =  axis2_svc_client_send_receive_with_op_qname( svc_client, env, op_qname, payload);
 
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);    
              
              axis2_options_set_action( options, env, NULL);
            }
            if(soap_act)
            {
              axutil_string_free(soap_act, env);
            }

            
            
                    if ( NULL == ret_node )
                    {
                        return (adb_getSystemResponseCountResponse_t*)NULL;
                    }
                    ret_val = adb_getSystemResponseCountResponse_create(env);

                    if(adb_getSystemResponseCountResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                    {
                        if(ret_val != NULL)
                        {
                            adb_getSystemResponseCountResponse_free(ret_val, env);
                        }

                        AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getSystemResponseCountResponse_deserialize: "
                                                                "This should be due to an invalid XML");
                        return (adb_getSystemResponseCountResponse_t*)NULL;
                    }

                   
                            return ret_val;
                       
        }
        
         /**
          * auto generated method signature
          * for "getOperationResponseCount|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub (axis2_stub_t)
          * @param env environment ( mandatory)
          * @param _getOperationResponseCount of the adb_getOperationResponseCount_t*
          *
          * @return adb_getOperationResponseCountResponse_t*
          */

         adb_getOperationResponseCountResponse_t* AXIS2_CALL 
         axis2_stub_op_StatisticsAdmin_getOperationResponseCount( axis2_stub_t *stub, const axutil_env_t *env,
                                               adb_getOperationResponseCount_t* _getOperationResponseCount)
         {
            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;
            axiom_node_t *ret_node = NULL;

            const axis2_char_t *soap_action = NULL;
            axutil_qname_t *op_qname =  NULL;
            axiom_node_t *payload = NULL;
            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            adb_getOperationResponseCountResponse_t* ret_val;
            
                                payload = adb_getOperationResponseCount_serialize(_getOperationResponseCount, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           
            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "options is null in stub");
                return (adb_getOperationResponseCountResponse_t*)NULL;
            }
            soap_act = axis2_options_get_soap_action( options, env );
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getOperationResponseCount";
              soap_act = axutil_string_create(env, "urn:getOperationResponseCount");
              axis2_options_set_soap_action(options, env, soap_act);    
            }

            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             
            ret_node =  axis2_svc_client_send_receive_with_op_qname( svc_client, env, op_qname, payload);
 
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);    
              
              axis2_options_set_action( options, env, NULL);
            }
            if(soap_act)
            {
              axutil_string_free(soap_act, env);
            }

            
            
                    if ( NULL == ret_node )
                    {
                        return (adb_getOperationResponseCountResponse_t*)NULL;
                    }
                    ret_val = adb_getOperationResponseCountResponse_create(env);

                    if(adb_getOperationResponseCountResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                    {
                        if(ret_val != NULL)
                        {
                            adb_getOperationResponseCountResponse_free(ret_val, env);
                        }

                        AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getOperationResponseCountResponse_deserialize: "
                                                                "This should be due to an invalid XML");
                        return (adb_getOperationResponseCountResponse_t*)NULL;
                    }

                   
                            return ret_val;
                       
        }
        
         /**
          * auto generated method signature
          * for "getAvgOperationResponseTime|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub (axis2_stub_t)
          * @param env environment ( mandatory)
          * @param _getAvgOperationResponseTime of the adb_getAvgOperationResponseTime_t*
          *
          * @return adb_getAvgOperationResponseTimeResponse_t*
          */

         adb_getAvgOperationResponseTimeResponse_t* AXIS2_CALL 
         axis2_stub_op_StatisticsAdmin_getAvgOperationResponseTime( axis2_stub_t *stub, const axutil_env_t *env,
                                               adb_getAvgOperationResponseTime_t* _getAvgOperationResponseTime)
         {
            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;
            axiom_node_t *ret_node = NULL;

            const axis2_char_t *soap_action = NULL;
            axutil_qname_t *op_qname =  NULL;
            axiom_node_t *payload = NULL;
            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            adb_getAvgOperationResponseTimeResponse_t* ret_val;
            
                                payload = adb_getAvgOperationResponseTime_serialize(_getAvgOperationResponseTime, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           
            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "options is null in stub");
                return (adb_getAvgOperationResponseTimeResponse_t*)NULL;
            }
            soap_act = axis2_options_get_soap_action( options, env );
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getAvgOperationResponseTime";
              soap_act = axutil_string_create(env, "urn:getAvgOperationResponseTime");
              axis2_options_set_soap_action(options, env, soap_act);    
            }

            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             
            ret_node =  axis2_svc_client_send_receive_with_op_qname( svc_client, env, op_qname, payload);
 
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);    
              
              axis2_options_set_action( options, env, NULL);
            }
            if(soap_act)
            {
              axutil_string_free(soap_act, env);
            }

            
            
                    if ( NULL == ret_node )
                    {
                        return (adb_getAvgOperationResponseTimeResponse_t*)NULL;
                    }
                    ret_val = adb_getAvgOperationResponseTimeResponse_create(env);

                    if(adb_getAvgOperationResponseTimeResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                    {
                        if(ret_val != NULL)
                        {
                            adb_getAvgOperationResponseTimeResponse_free(ret_val, env);
                        }

                        AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getAvgOperationResponseTimeResponse_deserialize: "
                                                                "This should be due to an invalid XML");
                        return (adb_getAvgOperationResponseTimeResponse_t*)NULL;
                    }

                   
                            return ret_val;
                       
        }
        
         /**
          * auto generated method signature
          * for "getOperationStatistics|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub (axis2_stub_t)
          * @param env environment ( mandatory)
          * @param _getOperationStatistics of the adb_getOperationStatistics_t*
          *
          * @return adb_getOperationStatisticsResponse_t*
          */

         adb_getOperationStatisticsResponse_t* AXIS2_CALL 
         axis2_stub_op_StatisticsAdmin_getOperationStatistics( axis2_stub_t *stub, const axutil_env_t *env,
                                               adb_getOperationStatistics_t* _getOperationStatistics)
         {
            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;
            axiom_node_t *ret_node = NULL;

            const axis2_char_t *soap_action = NULL;
            axutil_qname_t *op_qname =  NULL;
            axiom_node_t *payload = NULL;
            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            adb_getOperationStatisticsResponse_t* ret_val;
            
                                payload = adb_getOperationStatistics_serialize(_getOperationStatistics, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           
            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "options is null in stub");
                return (adb_getOperationStatisticsResponse_t*)NULL;
            }
            soap_act = axis2_options_get_soap_action( options, env );
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getOperationStatistics";
              soap_act = axutil_string_create(env, "urn:getOperationStatistics");
              axis2_options_set_soap_action(options, env, soap_act);    
            }

            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             
            ret_node =  axis2_svc_client_send_receive_with_op_qname( svc_client, env, op_qname, payload);
 
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);    
              
              axis2_options_set_action( options, env, NULL);
            }
            if(soap_act)
            {
              axutil_string_free(soap_act, env);
            }

            
            
                    if ( NULL == ret_node )
                    {
                        return (adb_getOperationStatisticsResponse_t*)NULL;
                    }
                    ret_val = adb_getOperationStatisticsResponse_create(env);

                    if(adb_getOperationStatisticsResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                    {
                        if(ret_val != NULL)
                        {
                            adb_getOperationStatisticsResponse_free(ret_val, env);
                        }

                        AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getOperationStatisticsResponse_deserialize: "
                                                                "This should be due to an invalid XML");
                        return (adb_getOperationStatisticsResponse_t*)NULL;
                    }

                   
                            return ret_val;
                       
        }
        
         /**
          * auto generated method signature
          * for "getMinSystemResponseTime|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub (axis2_stub_t)
          * @param env environment ( mandatory)
          *
          * @return adb_getMinSystemResponseTimeResponse_t*
          */

         adb_getMinSystemResponseTimeResponse_t* AXIS2_CALL 
         axis2_stub_op_StatisticsAdmin_getMinSystemResponseTime( axis2_stub_t *stub, const axutil_env_t *env)
         {
            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;
            axiom_node_t *ret_node = NULL;

            const axis2_char_t *soap_action = NULL;
            axutil_qname_t *op_qname =  NULL;
            axiom_node_t *payload = NULL;
            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            adb_getMinSystemResponseTimeResponse_t* ret_val;
            
            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "options is null in stub");
                return (adb_getMinSystemResponseTimeResponse_t*)NULL;
            }
            soap_act = axis2_options_get_soap_action( options, env );
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getMinSystemResponseTime";
              soap_act = axutil_string_create(env, "urn:getMinSystemResponseTime");
              axis2_options_set_soap_action(options, env, soap_act);    
            }

            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             
            ret_node =  axis2_svc_client_send_receive_with_op_qname( svc_client, env, op_qname, payload);
 
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);    
              
              axis2_options_set_action( options, env, NULL);
            }
            if(soap_act)
            {
              axutil_string_free(soap_act, env);
            }

            
            
                    if ( NULL == ret_node )
                    {
                        return (adb_getMinSystemResponseTimeResponse_t*)NULL;
                    }
                    ret_val = adb_getMinSystemResponseTimeResponse_create(env);

                    if(adb_getMinSystemResponseTimeResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                    {
                        if(ret_val != NULL)
                        {
                            adb_getMinSystemResponseTimeResponse_free(ret_val, env);
                        }

                        AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getMinSystemResponseTimeResponse_deserialize: "
                                                                "This should be due to an invalid XML");
                        return (adb_getMinSystemResponseTimeResponse_t*)NULL;
                    }

                   
                            return ret_val;
                       
        }
        
         /**
          * auto generated method signature
          * for "getSystemFaultCount|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub (axis2_stub_t)
          * @param env environment ( mandatory)
          *
          * @return adb_getSystemFaultCountResponse_t*
          */

         adb_getSystemFaultCountResponse_t* AXIS2_CALL 
         axis2_stub_op_StatisticsAdmin_getSystemFaultCount( axis2_stub_t *stub, const axutil_env_t *env)
         {
            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;
            axiom_node_t *ret_node = NULL;

            const axis2_char_t *soap_action = NULL;
            axutil_qname_t *op_qname =  NULL;
            axiom_node_t *payload = NULL;
            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            adb_getSystemFaultCountResponse_t* ret_val;
            
            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "options is null in stub");
                return (adb_getSystemFaultCountResponse_t*)NULL;
            }
            soap_act = axis2_options_get_soap_action( options, env );
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getSystemFaultCount";
              soap_act = axutil_string_create(env, "urn:getSystemFaultCount");
              axis2_options_set_soap_action(options, env, soap_act);    
            }

            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             
            ret_node =  axis2_svc_client_send_receive_with_op_qname( svc_client, env, op_qname, payload);
 
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);    
              
              axis2_options_set_action( options, env, NULL);
            }
            if(soap_act)
            {
              axutil_string_free(soap_act, env);
            }

            
            
                    if ( NULL == ret_node )
                    {
                        return (adb_getSystemFaultCountResponse_t*)NULL;
                    }
                    ret_val = adb_getSystemFaultCountResponse_create(env);

                    if(adb_getSystemFaultCountResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                    {
                        if(ret_val != NULL)
                        {
                            adb_getSystemFaultCountResponse_free(ret_val, env);
                        }

                        AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getSystemFaultCountResponse_deserialize: "
                                                                "This should be due to an invalid XML");
                        return (adb_getSystemFaultCountResponse_t*)NULL;
                    }

                   
                            return ret_val;
                       
        }
        
         /**
          * auto generated method signature
          * for "getMaxSystemResponseTime|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub (axis2_stub_t)
          * @param env environment ( mandatory)
          *
          * @return adb_getMaxSystemResponseTimeResponse_t*
          */

         adb_getMaxSystemResponseTimeResponse_t* AXIS2_CALL 
         axis2_stub_op_StatisticsAdmin_getMaxSystemResponseTime( axis2_stub_t *stub, const axutil_env_t *env)
         {
            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;
            axiom_node_t *ret_node = NULL;

            const axis2_char_t *soap_action = NULL;
            axutil_qname_t *op_qname =  NULL;
            axiom_node_t *payload = NULL;
            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            adb_getMaxSystemResponseTimeResponse_t* ret_val;
            
            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "options is null in stub");
                return (adb_getMaxSystemResponseTimeResponse_t*)NULL;
            }
            soap_act = axis2_options_get_soap_action( options, env );
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getMaxSystemResponseTime";
              soap_act = axutil_string_create(env, "urn:getMaxSystemResponseTime");
              axis2_options_set_soap_action(options, env, soap_act);    
            }

            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             
            ret_node =  axis2_svc_client_send_receive_with_op_qname( svc_client, env, op_qname, payload);
 
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);    
              
              axis2_options_set_action( options, env, NULL);
            }
            if(soap_act)
            {
              axutil_string_free(soap_act, env);
            }

            
            
                    if ( NULL == ret_node )
                    {
                        return (adb_getMaxSystemResponseTimeResponse_t*)NULL;
                    }
                    ret_val = adb_getMaxSystemResponseTimeResponse_create(env);

                    if(adb_getMaxSystemResponseTimeResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                    {
                        if(ret_val != NULL)
                        {
                            adb_getMaxSystemResponseTimeResponse_free(ret_val, env);
                        }

                        AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getMaxSystemResponseTimeResponse_deserialize: "
                                                                "This should be due to an invalid XML");
                        return (adb_getMaxSystemResponseTimeResponse_t*)NULL;
                    }

                   
                            return ret_val;
                       
        }
        
         /**
          * auto generated method signature
          * for "getServiceFaultCount|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub (axis2_stub_t)
          * @param env environment ( mandatory)
          * @param _getServiceFaultCount of the adb_getServiceFaultCount_t*
          *
          * @return adb_getServiceFaultCountResponse_t*
          */

         adb_getServiceFaultCountResponse_t* AXIS2_CALL 
         axis2_stub_op_StatisticsAdmin_getServiceFaultCount( axis2_stub_t *stub, const axutil_env_t *env,
                                               adb_getServiceFaultCount_t* _getServiceFaultCount)
         {
            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;
            axiom_node_t *ret_node = NULL;

            const axis2_char_t *soap_action = NULL;
            axutil_qname_t *op_qname =  NULL;
            axiom_node_t *payload = NULL;
            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            adb_getServiceFaultCountResponse_t* ret_val;
            
                                payload = adb_getServiceFaultCount_serialize(_getServiceFaultCount, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           
            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "options is null in stub");
                return (adb_getServiceFaultCountResponse_t*)NULL;
            }
            soap_act = axis2_options_get_soap_action( options, env );
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getServiceFaultCount";
              soap_act = axutil_string_create(env, "urn:getServiceFaultCount");
              axis2_options_set_soap_action(options, env, soap_act);    
            }

            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             
            ret_node =  axis2_svc_client_send_receive_with_op_qname( svc_client, env, op_qname, payload);
 
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);    
              
              axis2_options_set_action( options, env, NULL);
            }
            if(soap_act)
            {
              axutil_string_free(soap_act, env);
            }

            
            
                    if ( NULL == ret_node )
                    {
                        return (adb_getServiceFaultCountResponse_t*)NULL;
                    }
                    ret_val = adb_getServiceFaultCountResponse_create(env);

                    if(adb_getServiceFaultCountResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                    {
                        if(ret_val != NULL)
                        {
                            adb_getServiceFaultCountResponse_free(ret_val, env);
                        }

                        AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getServiceFaultCountResponse_deserialize: "
                                                                "This should be due to an invalid XML");
                        return (adb_getServiceFaultCountResponse_t*)NULL;
                    }

                   
                            return ret_val;
                       
        }
        
         /**
          * auto generated method signature
          * for "getMinServiceResponseTime|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub (axis2_stub_t)
          * @param env environment ( mandatory)
          * @param _getMinServiceResponseTime of the adb_getMinServiceResponseTime_t*
          *
          * @return adb_getMinServiceResponseTimeResponse_t*
          */

         adb_getMinServiceResponseTimeResponse_t* AXIS2_CALL 
         axis2_stub_op_StatisticsAdmin_getMinServiceResponseTime( axis2_stub_t *stub, const axutil_env_t *env,
                                               adb_getMinServiceResponseTime_t* _getMinServiceResponseTime)
         {
            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;
            axiom_node_t *ret_node = NULL;

            const axis2_char_t *soap_action = NULL;
            axutil_qname_t *op_qname =  NULL;
            axiom_node_t *payload = NULL;
            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            adb_getMinServiceResponseTimeResponse_t* ret_val;
            
                                payload = adb_getMinServiceResponseTime_serialize(_getMinServiceResponseTime, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           
            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "options is null in stub");
                return (adb_getMinServiceResponseTimeResponse_t*)NULL;
            }
            soap_act = axis2_options_get_soap_action( options, env );
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getMinServiceResponseTime";
              soap_act = axutil_string_create(env, "urn:getMinServiceResponseTime");
              axis2_options_set_soap_action(options, env, soap_act);    
            }

            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             
            ret_node =  axis2_svc_client_send_receive_with_op_qname( svc_client, env, op_qname, payload);
 
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);    
              
              axis2_options_set_action( options, env, NULL);
            }
            if(soap_act)
            {
              axutil_string_free(soap_act, env);
            }

            
            
                    if ( NULL == ret_node )
                    {
                        return (adb_getMinServiceResponseTimeResponse_t*)NULL;
                    }
                    ret_val = adb_getMinServiceResponseTimeResponse_create(env);

                    if(adb_getMinServiceResponseTimeResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                    {
                        if(ret_val != NULL)
                        {
                            adb_getMinServiceResponseTimeResponse_free(ret_val, env);
                        }

                        AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getMinServiceResponseTimeResponse_deserialize: "
                                                                "This should be due to an invalid XML");
                        return (adb_getMinServiceResponseTimeResponse_t*)NULL;
                    }

                   
                            return ret_val;
                       
        }
        
         /**
          * auto generated method signature
          * for "getMaxOperationResponseTime|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub (axis2_stub_t)
          * @param env environment ( mandatory)
          * @param _getMaxOperationResponseTime of the adb_getMaxOperationResponseTime_t*
          *
          * @return adb_getMaxOperationResponseTimeResponse_t*
          */

         adb_getMaxOperationResponseTimeResponse_t* AXIS2_CALL 
         axis2_stub_op_StatisticsAdmin_getMaxOperationResponseTime( axis2_stub_t *stub, const axutil_env_t *env,
                                               adb_getMaxOperationResponseTime_t* _getMaxOperationResponseTime)
         {
            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;
            axiom_node_t *ret_node = NULL;

            const axis2_char_t *soap_action = NULL;
            axutil_qname_t *op_qname =  NULL;
            axiom_node_t *payload = NULL;
            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            adb_getMaxOperationResponseTimeResponse_t* ret_val;
            
                                payload = adb_getMaxOperationResponseTime_serialize(_getMaxOperationResponseTime, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           
            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "options is null in stub");
                return (adb_getMaxOperationResponseTimeResponse_t*)NULL;
            }
            soap_act = axis2_options_get_soap_action( options, env );
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getMaxOperationResponseTime";
              soap_act = axutil_string_create(env, "urn:getMaxOperationResponseTime");
              axis2_options_set_soap_action(options, env, soap_act);    
            }

            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             
            ret_node =  axis2_svc_client_send_receive_with_op_qname( svc_client, env, op_qname, payload);
 
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);    
              
              axis2_options_set_action( options, env, NULL);
            }
            if(soap_act)
            {
              axutil_string_free(soap_act, env);
            }

            
            
                    if ( NULL == ret_node )
                    {
                        return (adb_getMaxOperationResponseTimeResponse_t*)NULL;
                    }
                    ret_val = adb_getMaxOperationResponseTimeResponse_create(env);

                    if(adb_getMaxOperationResponseTimeResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                    {
                        if(ret_val != NULL)
                        {
                            adb_getMaxOperationResponseTimeResponse_free(ret_val, env);
                        }

                        AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getMaxOperationResponseTimeResponse_deserialize: "
                                                                "This should be due to an invalid XML");
                        return (adb_getMaxOperationResponseTimeResponse_t*)NULL;
                    }

                   
                            return ret_val;
                       
        }
        
         /**
          * auto generated method signature
          * for "getServiceStatistics|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub (axis2_stub_t)
          * @param env environment ( mandatory)
          * @param _getServiceStatistics of the adb_getServiceStatistics_t*
          *
          * @return adb_getServiceStatisticsResponse_t*
          */

         adb_getServiceStatisticsResponse_t* AXIS2_CALL 
         axis2_stub_op_StatisticsAdmin_getServiceStatistics( axis2_stub_t *stub, const axutil_env_t *env,
                                               adb_getServiceStatistics_t* _getServiceStatistics)
         {
            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;
            axiom_node_t *ret_node = NULL;

            const axis2_char_t *soap_action = NULL;
            axutil_qname_t *op_qname =  NULL;
            axiom_node_t *payload = NULL;
            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            adb_getServiceStatisticsResponse_t* ret_val;
            
                                payload = adb_getServiceStatistics_serialize(_getServiceStatistics, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           
            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "options is null in stub");
                return (adb_getServiceStatisticsResponse_t*)NULL;
            }
            soap_act = axis2_options_get_soap_action( options, env );
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getServiceStatistics";
              soap_act = axutil_string_create(env, "urn:getServiceStatistics");
              axis2_options_set_soap_action(options, env, soap_act);    
            }

            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             
            ret_node =  axis2_svc_client_send_receive_with_op_qname( svc_client, env, op_qname, payload);
 
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);    
              
              axis2_options_set_action( options, env, NULL);
            }
            if(soap_act)
            {
              axutil_string_free(soap_act, env);
            }

            
            
                    if ( NULL == ret_node )
                    {
                        return (adb_getServiceStatisticsResponse_t*)NULL;
                    }
                    ret_val = adb_getServiceStatisticsResponse_create(env);

                    if(adb_getServiceStatisticsResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                    {
                        if(ret_val != NULL)
                        {
                            adb_getServiceStatisticsResponse_free(ret_val, env);
                        }

                        AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getServiceStatisticsResponse_deserialize: "
                                                                "This should be due to an invalid XML");
                        return (adb_getServiceStatisticsResponse_t*)NULL;
                    }

                   
                            return ret_val;
                       
        }
        
         /**
          * auto generated method signature
          * for "getOperationFaultCount|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub (axis2_stub_t)
          * @param env environment ( mandatory)
          * @param _getOperationFaultCount of the adb_getOperationFaultCount_t*
          *
          * @return adb_getOperationFaultCountResponse_t*
          */

         adb_getOperationFaultCountResponse_t* AXIS2_CALL 
         axis2_stub_op_StatisticsAdmin_getOperationFaultCount( axis2_stub_t *stub, const axutil_env_t *env,
                                               adb_getOperationFaultCount_t* _getOperationFaultCount)
         {
            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;
            axiom_node_t *ret_node = NULL;

            const axis2_char_t *soap_action = NULL;
            axutil_qname_t *op_qname =  NULL;
            axiom_node_t *payload = NULL;
            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            adb_getOperationFaultCountResponse_t* ret_val;
            
                                payload = adb_getOperationFaultCount_serialize(_getOperationFaultCount, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           
            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "options is null in stub");
                return (adb_getOperationFaultCountResponse_t*)NULL;
            }
            soap_act = axis2_options_get_soap_action( options, env );
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getOperationFaultCount";
              soap_act = axutil_string_create(env, "urn:getOperationFaultCount");
              axis2_options_set_soap_action(options, env, soap_act);    
            }

            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             
            ret_node =  axis2_svc_client_send_receive_with_op_qname( svc_client, env, op_qname, payload);
 
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);    
              
              axis2_options_set_action( options, env, NULL);
            }
            if(soap_act)
            {
              axutil_string_free(soap_act, env);
            }

            
            
                    if ( NULL == ret_node )
                    {
                        return (adb_getOperationFaultCountResponse_t*)NULL;
                    }
                    ret_val = adb_getOperationFaultCountResponse_create(env);

                    if(adb_getOperationFaultCountResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                    {
                        if(ret_val != NULL)
                        {
                            adb_getOperationFaultCountResponse_free(ret_val, env);
                        }

                        AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getOperationFaultCountResponse_deserialize: "
                                                                "This should be due to an invalid XML");
                        return (adb_getOperationFaultCountResponse_t*)NULL;
                    }

                   
                            return ret_val;
                       
        }
        
         /**
          * auto generated method signature
          * for "getAvgServiceResponseTime|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub (axis2_stub_t)
          * @param env environment ( mandatory)
          * @param _getAvgServiceResponseTime of the adb_getAvgServiceResponseTime_t*
          *
          * @return adb_getAvgServiceResponseTimeResponse_t*
          */

         adb_getAvgServiceResponseTimeResponse_t* AXIS2_CALL 
         axis2_stub_op_StatisticsAdmin_getAvgServiceResponseTime( axis2_stub_t *stub, const axutil_env_t *env,
                                               adb_getAvgServiceResponseTime_t* _getAvgServiceResponseTime)
         {
            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;
            axiom_node_t *ret_node = NULL;

            const axis2_char_t *soap_action = NULL;
            axutil_qname_t *op_qname =  NULL;
            axiom_node_t *payload = NULL;
            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            adb_getAvgServiceResponseTimeResponse_t* ret_val;
            
                                payload = adb_getAvgServiceResponseTime_serialize(_getAvgServiceResponseTime, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           
            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "options is null in stub");
                return (adb_getAvgServiceResponseTimeResponse_t*)NULL;
            }
            soap_act = axis2_options_get_soap_action( options, env );
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getAvgServiceResponseTime";
              soap_act = axutil_string_create(env, "urn:getAvgServiceResponseTime");
              axis2_options_set_soap_action(options, env, soap_act);    
            }

            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             
            ret_node =  axis2_svc_client_send_receive_with_op_qname( svc_client, env, op_qname, payload);
 
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);    
              
              axis2_options_set_action( options, env, NULL);
            }
            if(soap_act)
            {
              axutil_string_free(soap_act, env);
            }

            
            
                    if ( NULL == ret_node )
                    {
                        return (adb_getAvgServiceResponseTimeResponse_t*)NULL;
                    }
                    ret_val = adb_getAvgServiceResponseTimeResponse_create(env);

                    if(adb_getAvgServiceResponseTimeResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                    {
                        if(ret_val != NULL)
                        {
                            adb_getAvgServiceResponseTimeResponse_free(ret_val, env);
                        }

                        AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getAvgServiceResponseTimeResponse_deserialize: "
                                                                "This should be due to an invalid XML");
                        return (adb_getAvgServiceResponseTimeResponse_t*)NULL;
                    }

                   
                            return ret_val;
                       
        }
        
         /**
          * auto generated method signature
          * for "getServiceResponseCount|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub (axis2_stub_t)
          * @param env environment ( mandatory)
          * @param _getServiceResponseCount of the adb_getServiceResponseCount_t*
          *
          * @return adb_getServiceResponseCountResponse_t*
          */

         adb_getServiceResponseCountResponse_t* AXIS2_CALL 
         axis2_stub_op_StatisticsAdmin_getServiceResponseCount( axis2_stub_t *stub, const axutil_env_t *env,
                                               adb_getServiceResponseCount_t* _getServiceResponseCount)
         {
            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;
            axiom_node_t *ret_node = NULL;

            const axis2_char_t *soap_action = NULL;
            axutil_qname_t *op_qname =  NULL;
            axiom_node_t *payload = NULL;
            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            adb_getServiceResponseCountResponse_t* ret_val;
            
                                payload = adb_getServiceResponseCount_serialize(_getServiceResponseCount, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           
            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "options is null in stub");
                return (adb_getServiceResponseCountResponse_t*)NULL;
            }
            soap_act = axis2_options_get_soap_action( options, env );
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getServiceResponseCount";
              soap_act = axutil_string_create(env, "urn:getServiceResponseCount");
              axis2_options_set_soap_action(options, env, soap_act);    
            }

            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             
            ret_node =  axis2_svc_client_send_receive_with_op_qname( svc_client, env, op_qname, payload);
 
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);    
              
              axis2_options_set_action( options, env, NULL);
            }
            if(soap_act)
            {
              axutil_string_free(soap_act, env);
            }

            
            
                    if ( NULL == ret_node )
                    {
                        return (adb_getServiceResponseCountResponse_t*)NULL;
                    }
                    ret_val = adb_getServiceResponseCountResponse_create(env);

                    if(adb_getServiceResponseCountResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                    {
                        if(ret_val != NULL)
                        {
                            adb_getServiceResponseCountResponse_free(ret_val, env);
                        }

                        AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getServiceResponseCountResponse_deserialize: "
                                                                "This should be due to an invalid XML");
                        return (adb_getServiceResponseCountResponse_t*)NULL;
                    }

                   
                            return ret_val;
                       
        }
        
         /**
          * auto generated method signature
          * for "getSystemRequestCount|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub (axis2_stub_t)
          * @param env environment ( mandatory)
          *
          * @return adb_getSystemRequestCountResponse_t*
          */

         adb_getSystemRequestCountResponse_t* AXIS2_CALL 
         axis2_stub_op_StatisticsAdmin_getSystemRequestCount( axis2_stub_t *stub, const axutil_env_t *env)
         {
            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;
            axiom_node_t *ret_node = NULL;

            const axis2_char_t *soap_action = NULL;
            axutil_qname_t *op_qname =  NULL;
            axiom_node_t *payload = NULL;
            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            adb_getSystemRequestCountResponse_t* ret_val;
            
            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "options is null in stub");
                return (adb_getSystemRequestCountResponse_t*)NULL;
            }
            soap_act = axis2_options_get_soap_action( options, env );
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getSystemRequestCount";
              soap_act = axutil_string_create(env, "urn:getSystemRequestCount");
              axis2_options_set_soap_action(options, env, soap_act);    
            }

            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             
            ret_node =  axis2_svc_client_send_receive_with_op_qname( svc_client, env, op_qname, payload);
 
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);    
              
              axis2_options_set_action( options, env, NULL);
            }
            if(soap_act)
            {
              axutil_string_free(soap_act, env);
            }

            
            
                    if ( NULL == ret_node )
                    {
                        return (adb_getSystemRequestCountResponse_t*)NULL;
                    }
                    ret_val = adb_getSystemRequestCountResponse_create(env);

                    if(adb_getSystemRequestCountResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                    {
                        if(ret_val != NULL)
                        {
                            adb_getSystemRequestCountResponse_free(ret_val, env);
                        }

                        AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getSystemRequestCountResponse_deserialize: "
                                                                "This should be due to an invalid XML");
                        return (adb_getSystemRequestCountResponse_t*)NULL;
                    }

                   
                            return ret_val;
                       
        }
        
         /**
          * auto generated method signature
          * for "getMinOperationResponseTime|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub (axis2_stub_t)
          * @param env environment ( mandatory)
          * @param _getMinOperationResponseTime of the adb_getMinOperationResponseTime_t*
          *
          * @return adb_getMinOperationResponseTimeResponse_t*
          */

         adb_getMinOperationResponseTimeResponse_t* AXIS2_CALL 
         axis2_stub_op_StatisticsAdmin_getMinOperationResponseTime( axis2_stub_t *stub, const axutil_env_t *env,
                                               adb_getMinOperationResponseTime_t* _getMinOperationResponseTime)
         {
            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;
            axiom_node_t *ret_node = NULL;

            const axis2_char_t *soap_action = NULL;
            axutil_qname_t *op_qname =  NULL;
            axiom_node_t *payload = NULL;
            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            adb_getMinOperationResponseTimeResponse_t* ret_val;
            
                                payload = adb_getMinOperationResponseTime_serialize(_getMinOperationResponseTime, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           
            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "options is null in stub");
                return (adb_getMinOperationResponseTimeResponse_t*)NULL;
            }
            soap_act = axis2_options_get_soap_action( options, env );
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getMinOperationResponseTime";
              soap_act = axutil_string_create(env, "urn:getMinOperationResponseTime");
              axis2_options_set_soap_action(options, env, soap_act);    
            }

            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             
            ret_node =  axis2_svc_client_send_receive_with_op_qname( svc_client, env, op_qname, payload);
 
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);    
              
              axis2_options_set_action( options, env, NULL);
            }
            if(soap_act)
            {
              axutil_string_free(soap_act, env);
            }

            
            
                    if ( NULL == ret_node )
                    {
                        return (adb_getMinOperationResponseTimeResponse_t*)NULL;
                    }
                    ret_val = adb_getMinOperationResponseTimeResponse_create(env);

                    if(adb_getMinOperationResponseTimeResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                    {
                        if(ret_val != NULL)
                        {
                            adb_getMinOperationResponseTimeResponse_free(ret_val, env);
                        }

                        AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getMinOperationResponseTimeResponse_deserialize: "
                                                                "This should be due to an invalid XML");
                        return (adb_getMinOperationResponseTimeResponse_t*)NULL;
                    }

                   
                            return ret_val;
                       
        }
        
         /**
          * auto generated method signature
          * for "getAvgSystemResponseTime|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub (axis2_stub_t)
          * @param env environment ( mandatory)
          *
          * @return adb_getAvgSystemResponseTimeResponse_t*
          */

         adb_getAvgSystemResponseTimeResponse_t* AXIS2_CALL 
         axis2_stub_op_StatisticsAdmin_getAvgSystemResponseTime( axis2_stub_t *stub, const axutil_env_t *env)
         {
            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;
            axiom_node_t *ret_node = NULL;

            const axis2_char_t *soap_action = NULL;
            axutil_qname_t *op_qname =  NULL;
            axiom_node_t *payload = NULL;
            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            adb_getAvgSystemResponseTimeResponse_t* ret_val;
            
            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "options is null in stub");
                return (adb_getAvgSystemResponseTimeResponse_t*)NULL;
            }
            soap_act = axis2_options_get_soap_action( options, env );
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getAvgSystemResponseTime";
              soap_act = axutil_string_create(env, "urn:getAvgSystemResponseTime");
              axis2_options_set_soap_action(options, env, soap_act);    
            }

            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             
            ret_node =  axis2_svc_client_send_receive_with_op_qname( svc_client, env, op_qname, payload);
 
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);    
              
              axis2_options_set_action( options, env, NULL);
            }
            if(soap_act)
            {
              axutil_string_free(soap_act, env);
            }

            
            
                    if ( NULL == ret_node )
                    {
                        return (adb_getAvgSystemResponseTimeResponse_t*)NULL;
                    }
                    ret_val = adb_getAvgSystemResponseTimeResponse_create(env);

                    if(adb_getAvgSystemResponseTimeResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                    {
                        if(ret_val != NULL)
                        {
                            adb_getAvgSystemResponseTimeResponse_free(ret_val, env);
                        }

                        AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getAvgSystemResponseTimeResponse_deserialize: "
                                                                "This should be due to an invalid XML");
                        return (adb_getAvgSystemResponseTimeResponse_t*)NULL;
                    }

                   
                            return ret_val;
                       
        }
        
         /**
          * auto generated method signature
          * for "getSystemStatistics|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub (axis2_stub_t)
          * @param env environment ( mandatory)
          *
          * @return adb_getSystemStatisticsResponse_t*
          */

         adb_getSystemStatisticsResponse_t* AXIS2_CALL 
         axis2_stub_op_StatisticsAdmin_getSystemStatistics( axis2_stub_t *stub, const axutil_env_t *env)
         {
            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;
            axiom_node_t *ret_node = NULL;

            const axis2_char_t *soap_action = NULL;
            axutil_qname_t *op_qname =  NULL;
            axiom_node_t *payload = NULL;
            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            adb_getSystemStatisticsResponse_t* ret_val;
            
            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "options is null in stub");
                return (adb_getSystemStatisticsResponse_t*)NULL;
            }
            soap_act = axis2_options_get_soap_action( options, env );
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getSystemStatistics";
              soap_act = axutil_string_create(env, "urn:getSystemStatistics");
              axis2_options_set_soap_action(options, env, soap_act);    
            }

            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             
            ret_node =  axis2_svc_client_send_receive_with_op_qname( svc_client, env, op_qname, payload);
 
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);    
              
              axis2_options_set_action( options, env, NULL);
            }
            if(soap_act)
            {
              axutil_string_free(soap_act, env);
            }

            
            
                    if ( NULL == ret_node )
                    {
                        return (adb_getSystemStatisticsResponse_t*)NULL;
                    }
                    ret_val = adb_getSystemStatisticsResponse_create(env);

                    if(adb_getSystemStatisticsResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                    {
                        if(ret_val != NULL)
                        {
                            adb_getSystemStatisticsResponse_free(ret_val, env);
                        }

                        AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getSystemStatisticsResponse_deserialize: "
                                                                "This should be due to an invalid XML");
                        return (adb_getSystemStatisticsResponse_t*)NULL;
                    }

                   
                            return ret_val;
                       
        }
        
         /**
          * auto generated method signature
          * for "getOperationRequestCount|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub (axis2_stub_t)
          * @param env environment ( mandatory)
          * @param _getOperationRequestCount of the adb_getOperationRequestCount_t*
          *
          * @return adb_getOperationRequestCountResponse_t*
          */

         adb_getOperationRequestCountResponse_t* AXIS2_CALL 
         axis2_stub_op_StatisticsAdmin_getOperationRequestCount( axis2_stub_t *stub, const axutil_env_t *env,
                                               adb_getOperationRequestCount_t* _getOperationRequestCount)
         {
            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;
            axiom_node_t *ret_node = NULL;

            const axis2_char_t *soap_action = NULL;
            axutil_qname_t *op_qname =  NULL;
            axiom_node_t *payload = NULL;
            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            adb_getOperationRequestCountResponse_t* ret_val;
            
                                payload = adb_getOperationRequestCount_serialize(_getOperationRequestCount, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           
            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "options is null in stub");
                return (adb_getOperationRequestCountResponse_t*)NULL;
            }
            soap_act = axis2_options_get_soap_action( options, env );
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getOperationRequestCount";
              soap_act = axutil_string_create(env, "urn:getOperationRequestCount");
              axis2_options_set_soap_action(options, env, soap_act);    
            }

            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             
            ret_node =  axis2_svc_client_send_receive_with_op_qname( svc_client, env, op_qname, payload);
 
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);    
              
              axis2_options_set_action( options, env, NULL);
            }
            if(soap_act)
            {
              axutil_string_free(soap_act, env);
            }

            
            
                    if ( NULL == ret_node )
                    {
                        return (adb_getOperationRequestCountResponse_t*)NULL;
                    }
                    ret_val = adb_getOperationRequestCountResponse_create(env);

                    if(adb_getOperationRequestCountResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                    {
                        if(ret_val != NULL)
                        {
                            adb_getOperationRequestCountResponse_free(ret_val, env);
                        }

                        AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getOperationRequestCountResponse_deserialize: "
                                                                "This should be due to an invalid XML");
                        return (adb_getOperationRequestCountResponse_t*)NULL;
                    }

                   
                            return ret_val;
                       
        }
        

        struct axis2_stub_StatisticsAdmin_getMaxServiceResponseTime_callback_data
        {   
            void *data;
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getMaxServiceResponseTimeResponse_t* _getMaxServiceResponseTimeResponse, void *data);
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data);
        };

        static axis2_status_t AXIS2_CALL axis2_stub_on_error_StatisticsAdmin_getMaxServiceResponseTime(axis2_callback_t *callback, const axutil_env_t *env, int exception)
        {
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int, void *data);
            struct axis2_stub_StatisticsAdmin_getMaxServiceResponseTime_callback_data* callback_data = NULL;
            void *user_data = NULL;

            axis2_status_t status;
        
            callback_data = (struct axis2_stub_StatisticsAdmin_getMaxServiceResponseTime_callback_data*)axis2_callback_get_data(callback);
        
            user_data = callback_data->data;
            on_error = callback_data->on_error;
        
            status = on_error(env, exception, user_data);

            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        } 

        axis2_status_t AXIS2_CALL axis2_stub_on_complete_StatisticsAdmin_getMaxServiceResponseTime(axis2_callback_t *callback, const axutil_env_t *env)
        {
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getMaxServiceResponseTimeResponse_t* _getMaxServiceResponseTimeResponse, void *data);
            struct axis2_stub_StatisticsAdmin_getMaxServiceResponseTime_callback_data* callback_data = NULL;
            void *user_data = NULL;
            axis2_status_t status = AXIS2_SUCCESS;
 
            adb_getMaxServiceResponseTimeResponse_t* ret_val;
            

            axiom_node_t *ret_node = NULL;
            axiom_soap_envelope_t *soap_envelope = NULL;

            

            callback_data = (struct axis2_stub_StatisticsAdmin_getMaxServiceResponseTime_callback_data*)axis2_callback_get_data(callback);

            soap_envelope = axis2_callback_get_envelope(callback, env);
            if(soap_envelope)
            {
                axiom_soap_body_t *soap_body;
                soap_body = axiom_soap_envelope_get_body(soap_envelope, env);
                if(soap_body)
                {
                    axiom_node_t *body_node = axiom_soap_body_get_base_node(soap_body, env);
                    if(body_node)
                    {
                        ret_node = axiom_node_get_first_child(body_node, env);
                    }
                }
                
                
            }

            user_data = callback_data->data;
            on_complete = callback_data->on_complete;

            
                    if(ret_node != NULL)
                    {
                        ret_val = adb_getMaxServiceResponseTimeResponse_create(env);
     
                        if(adb_getMaxServiceResponseTimeResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                        {
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the LendResponse_deserialize: "
                                                                    "This should be due to an invalid XML");
                            adb_getMaxServiceResponseTimeResponse_free(ret_val, env);
                            ret_val = NULL;
                        }
                     }
                     else
                     {
                         ret_val = NULL; 
                     }

                     
                         status = on_complete(env, ret_val, user_data);
                         
 
            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        }

        /**
          * auto generated method signature for asynchronous invocations
          * for "getMaxServiceResponseTime|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub
          * @param env environment ( mandatory)
          * @param _getMaxServiceResponseTime of the adb_getMaxServiceResponseTime_t*
          * @param user_data user data to be accessed by the callbacks
          * @param on_complete callback to handle on complete
          * @param on_error callback to handle on error
          */

         void AXIS2_CALL
         axis2_stub_start_op_StatisticsAdmin_getMaxServiceResponseTime( axis2_stub_t *stub, const axutil_env_t *env,
                                              adb_getMaxServiceResponseTime_t* _getMaxServiceResponseTime,
                                                  void *user_data,
                                                  axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getMaxServiceResponseTimeResponse_t* _getMaxServiceResponseTimeResponse, void *data) ,
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) )
         {

            axis2_callback_t *callback = NULL;

            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;

            const axis2_char_t *soap_action = NULL;
            axiom_node_t *payload = NULL;

            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            
            
            struct axis2_stub_StatisticsAdmin_getMaxServiceResponseTime_callback_data *callback_data;

            callback_data = (struct axis2_stub_StatisticsAdmin_getMaxServiceResponseTime_callback_data*) AXIS2_MALLOC(env->allocator, 
                                    sizeof(struct axis2_stub_StatisticsAdmin_getMaxServiceResponseTime_callback_data));
            if(NULL == callback_data)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "Can not allocate memeory for the callback data structures");
                return;
            }
            

            
                                payload = adb_getMaxServiceResponseTime_serialize(_getMaxServiceResponseTime, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           


            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
              AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
              AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "options is null in stub");
              return;
            }

            soap_act =axis2_options_get_soap_action (options, env);
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getMaxServiceResponseTime";
              soap_act = axutil_string_create(env, "urn:getMaxServiceResponseTime");
              axis2_options_set_soap_action(options, env, soap_act);
            }
            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             

            callback = axis2_callback_create(env);
            /* Set our on_complete fucntion pointer to the callback object */
            axis2_callback_set_on_complete(callback, axis2_stub_on_complete_StatisticsAdmin_getMaxServiceResponseTime);
            /* Set our on_error function pointer to the callback object */
            axis2_callback_set_on_error(callback, axis2_stub_on_error_StatisticsAdmin_getMaxServiceResponseTime);

            callback_data-> data = user_data;
            callback_data-> on_complete = on_complete;
            callback_data-> on_error = on_error;

            axis2_callback_set_data(callback, (void*)callback_data);

            /* Send request */
            axis2_svc_client_send_receive_non_blocking(svc_client, env, payload, callback);
            
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);
              
              axis2_options_set_action(options, env, NULL);
            }
         }

         

        struct axis2_stub_StatisticsAdmin_getServiceRequestCount_callback_data
        {   
            void *data;
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getServiceRequestCountResponse_t* _getServiceRequestCountResponse, void *data);
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data);
        };

        static axis2_status_t AXIS2_CALL axis2_stub_on_error_StatisticsAdmin_getServiceRequestCount(axis2_callback_t *callback, const axutil_env_t *env, int exception)
        {
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int, void *data);
            struct axis2_stub_StatisticsAdmin_getServiceRequestCount_callback_data* callback_data = NULL;
            void *user_data = NULL;

            axis2_status_t status;
        
            callback_data = (struct axis2_stub_StatisticsAdmin_getServiceRequestCount_callback_data*)axis2_callback_get_data(callback);
        
            user_data = callback_data->data;
            on_error = callback_data->on_error;
        
            status = on_error(env, exception, user_data);

            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        } 

        axis2_status_t AXIS2_CALL axis2_stub_on_complete_StatisticsAdmin_getServiceRequestCount(axis2_callback_t *callback, const axutil_env_t *env)
        {
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getServiceRequestCountResponse_t* _getServiceRequestCountResponse, void *data);
            struct axis2_stub_StatisticsAdmin_getServiceRequestCount_callback_data* callback_data = NULL;
            void *user_data = NULL;
            axis2_status_t status = AXIS2_SUCCESS;
 
            adb_getServiceRequestCountResponse_t* ret_val;
            

            axiom_node_t *ret_node = NULL;
            axiom_soap_envelope_t *soap_envelope = NULL;

            

            callback_data = (struct axis2_stub_StatisticsAdmin_getServiceRequestCount_callback_data*)axis2_callback_get_data(callback);

            soap_envelope = axis2_callback_get_envelope(callback, env);
            if(soap_envelope)
            {
                axiom_soap_body_t *soap_body;
                soap_body = axiom_soap_envelope_get_body(soap_envelope, env);
                if(soap_body)
                {
                    axiom_node_t *body_node = axiom_soap_body_get_base_node(soap_body, env);
                    if(body_node)
                    {
                        ret_node = axiom_node_get_first_child(body_node, env);
                    }
                }
                
                
            }

            user_data = callback_data->data;
            on_complete = callback_data->on_complete;

            
                    if(ret_node != NULL)
                    {
                        ret_val = adb_getServiceRequestCountResponse_create(env);
     
                        if(adb_getServiceRequestCountResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                        {
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the LendResponse_deserialize: "
                                                                    "This should be due to an invalid XML");
                            adb_getServiceRequestCountResponse_free(ret_val, env);
                            ret_val = NULL;
                        }
                     }
                     else
                     {
                         ret_val = NULL; 
                     }

                     
                         status = on_complete(env, ret_val, user_data);
                         
 
            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        }

        /**
          * auto generated method signature for asynchronous invocations
          * for "getServiceRequestCount|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub
          * @param env environment ( mandatory)
          * @param _getServiceRequestCount of the adb_getServiceRequestCount_t*
          * @param user_data user data to be accessed by the callbacks
          * @param on_complete callback to handle on complete
          * @param on_error callback to handle on error
          */

         void AXIS2_CALL
         axis2_stub_start_op_StatisticsAdmin_getServiceRequestCount( axis2_stub_t *stub, const axutil_env_t *env,
                                              adb_getServiceRequestCount_t* _getServiceRequestCount,
                                                  void *user_data,
                                                  axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getServiceRequestCountResponse_t* _getServiceRequestCountResponse, void *data) ,
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) )
         {

            axis2_callback_t *callback = NULL;

            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;

            const axis2_char_t *soap_action = NULL;
            axiom_node_t *payload = NULL;

            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            
            
            struct axis2_stub_StatisticsAdmin_getServiceRequestCount_callback_data *callback_data;

            callback_data = (struct axis2_stub_StatisticsAdmin_getServiceRequestCount_callback_data*) AXIS2_MALLOC(env->allocator, 
                                    sizeof(struct axis2_stub_StatisticsAdmin_getServiceRequestCount_callback_data));
            if(NULL == callback_data)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "Can not allocate memeory for the callback data structures");
                return;
            }
            

            
                                payload = adb_getServiceRequestCount_serialize(_getServiceRequestCount, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           


            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
              AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
              AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "options is null in stub");
              return;
            }

            soap_act =axis2_options_get_soap_action (options, env);
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getServiceRequestCount";
              soap_act = axutil_string_create(env, "urn:getServiceRequestCount");
              axis2_options_set_soap_action(options, env, soap_act);
            }
            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             

            callback = axis2_callback_create(env);
            /* Set our on_complete fucntion pointer to the callback object */
            axis2_callback_set_on_complete(callback, axis2_stub_on_complete_StatisticsAdmin_getServiceRequestCount);
            /* Set our on_error function pointer to the callback object */
            axis2_callback_set_on_error(callback, axis2_stub_on_error_StatisticsAdmin_getServiceRequestCount);

            callback_data-> data = user_data;
            callback_data-> on_complete = on_complete;
            callback_data-> on_error = on_error;

            axis2_callback_set_data(callback, (void*)callback_data);

            /* Send request */
            axis2_svc_client_send_receive_non_blocking(svc_client, env, payload, callback);
            
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);
              
              axis2_options_set_action(options, env, NULL);
            }
         }

         

        struct axis2_stub_StatisticsAdmin_getSystemResponseCount_callback_data
        {   
            void *data;
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getSystemResponseCountResponse_t* _getSystemResponseCountResponse, void *data);
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data);
        };

        static axis2_status_t AXIS2_CALL axis2_stub_on_error_StatisticsAdmin_getSystemResponseCount(axis2_callback_t *callback, const axutil_env_t *env, int exception)
        {
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int, void *data);
            struct axis2_stub_StatisticsAdmin_getSystemResponseCount_callback_data* callback_data = NULL;
            void *user_data = NULL;

            axis2_status_t status;
        
            callback_data = (struct axis2_stub_StatisticsAdmin_getSystemResponseCount_callback_data*)axis2_callback_get_data(callback);
        
            user_data = callback_data->data;
            on_error = callback_data->on_error;
        
            status = on_error(env, exception, user_data);

            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        } 

        axis2_status_t AXIS2_CALL axis2_stub_on_complete_StatisticsAdmin_getSystemResponseCount(axis2_callback_t *callback, const axutil_env_t *env)
        {
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getSystemResponseCountResponse_t* _getSystemResponseCountResponse, void *data);
            struct axis2_stub_StatisticsAdmin_getSystemResponseCount_callback_data* callback_data = NULL;
            void *user_data = NULL;
            axis2_status_t status = AXIS2_SUCCESS;
 
            adb_getSystemResponseCountResponse_t* ret_val;
            

            axiom_node_t *ret_node = NULL;
            axiom_soap_envelope_t *soap_envelope = NULL;

            

            callback_data = (struct axis2_stub_StatisticsAdmin_getSystemResponseCount_callback_data*)axis2_callback_get_data(callback);

            soap_envelope = axis2_callback_get_envelope(callback, env);
            if(soap_envelope)
            {
                axiom_soap_body_t *soap_body;
                soap_body = axiom_soap_envelope_get_body(soap_envelope, env);
                if(soap_body)
                {
                    axiom_node_t *body_node = axiom_soap_body_get_base_node(soap_body, env);
                    if(body_node)
                    {
                        ret_node = axiom_node_get_first_child(body_node, env);
                    }
                }
                
                
            }

            user_data = callback_data->data;
            on_complete = callback_data->on_complete;

            
                    if(ret_node != NULL)
                    {
                        ret_val = adb_getSystemResponseCountResponse_create(env);
     
                        if(adb_getSystemResponseCountResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                        {
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the LendResponse_deserialize: "
                                                                    "This should be due to an invalid XML");
                            adb_getSystemResponseCountResponse_free(ret_val, env);
                            ret_val = NULL;
                        }
                     }
                     else
                     {
                         ret_val = NULL; 
                     }

                     
                         status = on_complete(env, ret_val, user_data);
                         
 
            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        }

        /**
          * auto generated method signature for asynchronous invocations
          * for "getSystemResponseCount|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub
          * @param env environment ( mandatory)
          * @param user_data user data to be accessed by the callbacks
          * @param on_complete callback to handle on complete
          * @param on_error callback to handle on error
          */

         void AXIS2_CALL
         axis2_stub_start_op_StatisticsAdmin_getSystemResponseCount( axis2_stub_t *stub, const axutil_env_t *env,
                                                  void *user_data,
                                                  axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getSystemResponseCountResponse_t* _getSystemResponseCountResponse, void *data) ,
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) )
         {

            axis2_callback_t *callback = NULL;

            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;

            const axis2_char_t *soap_action = NULL;
            axiom_node_t *payload = NULL;

            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            
            
            struct axis2_stub_StatisticsAdmin_getSystemResponseCount_callback_data *callback_data;

            callback_data = (struct axis2_stub_StatisticsAdmin_getSystemResponseCount_callback_data*) AXIS2_MALLOC(env->allocator, 
                                    sizeof(struct axis2_stub_StatisticsAdmin_getSystemResponseCount_callback_data));
            if(NULL == callback_data)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "Can not allocate memeory for the callback data structures");
                return;
            }
            

            


            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
              AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
              AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "options is null in stub");
              return;
            }

            soap_act =axis2_options_get_soap_action (options, env);
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getSystemResponseCount";
              soap_act = axutil_string_create(env, "urn:getSystemResponseCount");
              axis2_options_set_soap_action(options, env, soap_act);
            }
            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             

            callback = axis2_callback_create(env);
            /* Set our on_complete fucntion pointer to the callback object */
            axis2_callback_set_on_complete(callback, axis2_stub_on_complete_StatisticsAdmin_getSystemResponseCount);
            /* Set our on_error function pointer to the callback object */
            axis2_callback_set_on_error(callback, axis2_stub_on_error_StatisticsAdmin_getSystemResponseCount);

            callback_data-> data = user_data;
            callback_data-> on_complete = on_complete;
            callback_data-> on_error = on_error;

            axis2_callback_set_data(callback, (void*)callback_data);

            /* Send request */
            axis2_svc_client_send_receive_non_blocking(svc_client, env, payload, callback);
            
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);
              
              axis2_options_set_action(options, env, NULL);
            }
         }

         

        struct axis2_stub_StatisticsAdmin_getOperationResponseCount_callback_data
        {   
            void *data;
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getOperationResponseCountResponse_t* _getOperationResponseCountResponse, void *data);
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data);
        };

        static axis2_status_t AXIS2_CALL axis2_stub_on_error_StatisticsAdmin_getOperationResponseCount(axis2_callback_t *callback, const axutil_env_t *env, int exception)
        {
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int, void *data);
            struct axis2_stub_StatisticsAdmin_getOperationResponseCount_callback_data* callback_data = NULL;
            void *user_data = NULL;

            axis2_status_t status;
        
            callback_data = (struct axis2_stub_StatisticsAdmin_getOperationResponseCount_callback_data*)axis2_callback_get_data(callback);
        
            user_data = callback_data->data;
            on_error = callback_data->on_error;
        
            status = on_error(env, exception, user_data);

            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        } 

        axis2_status_t AXIS2_CALL axis2_stub_on_complete_StatisticsAdmin_getOperationResponseCount(axis2_callback_t *callback, const axutil_env_t *env)
        {
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getOperationResponseCountResponse_t* _getOperationResponseCountResponse, void *data);
            struct axis2_stub_StatisticsAdmin_getOperationResponseCount_callback_data* callback_data = NULL;
            void *user_data = NULL;
            axis2_status_t status = AXIS2_SUCCESS;
 
            adb_getOperationResponseCountResponse_t* ret_val;
            

            axiom_node_t *ret_node = NULL;
            axiom_soap_envelope_t *soap_envelope = NULL;

            

            callback_data = (struct axis2_stub_StatisticsAdmin_getOperationResponseCount_callback_data*)axis2_callback_get_data(callback);

            soap_envelope = axis2_callback_get_envelope(callback, env);
            if(soap_envelope)
            {
                axiom_soap_body_t *soap_body;
                soap_body = axiom_soap_envelope_get_body(soap_envelope, env);
                if(soap_body)
                {
                    axiom_node_t *body_node = axiom_soap_body_get_base_node(soap_body, env);
                    if(body_node)
                    {
                        ret_node = axiom_node_get_first_child(body_node, env);
                    }
                }
                
                
            }

            user_data = callback_data->data;
            on_complete = callback_data->on_complete;

            
                    if(ret_node != NULL)
                    {
                        ret_val = adb_getOperationResponseCountResponse_create(env);
     
                        if(adb_getOperationResponseCountResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                        {
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the LendResponse_deserialize: "
                                                                    "This should be due to an invalid XML");
                            adb_getOperationResponseCountResponse_free(ret_val, env);
                            ret_val = NULL;
                        }
                     }
                     else
                     {
                         ret_val = NULL; 
                     }

                     
                         status = on_complete(env, ret_val, user_data);
                         
 
            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        }

        /**
          * auto generated method signature for asynchronous invocations
          * for "getOperationResponseCount|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub
          * @param env environment ( mandatory)
          * @param _getOperationResponseCount of the adb_getOperationResponseCount_t*
          * @param user_data user data to be accessed by the callbacks
          * @param on_complete callback to handle on complete
          * @param on_error callback to handle on error
          */

         void AXIS2_CALL
         axis2_stub_start_op_StatisticsAdmin_getOperationResponseCount( axis2_stub_t *stub, const axutil_env_t *env,
                                              adb_getOperationResponseCount_t* _getOperationResponseCount,
                                                  void *user_data,
                                                  axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getOperationResponseCountResponse_t* _getOperationResponseCountResponse, void *data) ,
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) )
         {

            axis2_callback_t *callback = NULL;

            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;

            const axis2_char_t *soap_action = NULL;
            axiom_node_t *payload = NULL;

            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            
            
            struct axis2_stub_StatisticsAdmin_getOperationResponseCount_callback_data *callback_data;

            callback_data = (struct axis2_stub_StatisticsAdmin_getOperationResponseCount_callback_data*) AXIS2_MALLOC(env->allocator, 
                                    sizeof(struct axis2_stub_StatisticsAdmin_getOperationResponseCount_callback_data));
            if(NULL == callback_data)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "Can not allocate memeory for the callback data structures");
                return;
            }
            

            
                                payload = adb_getOperationResponseCount_serialize(_getOperationResponseCount, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           


            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
              AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
              AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "options is null in stub");
              return;
            }

            soap_act =axis2_options_get_soap_action (options, env);
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getOperationResponseCount";
              soap_act = axutil_string_create(env, "urn:getOperationResponseCount");
              axis2_options_set_soap_action(options, env, soap_act);
            }
            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             

            callback = axis2_callback_create(env);
            /* Set our on_complete fucntion pointer to the callback object */
            axis2_callback_set_on_complete(callback, axis2_stub_on_complete_StatisticsAdmin_getOperationResponseCount);
            /* Set our on_error function pointer to the callback object */
            axis2_callback_set_on_error(callback, axis2_stub_on_error_StatisticsAdmin_getOperationResponseCount);

            callback_data-> data = user_data;
            callback_data-> on_complete = on_complete;
            callback_data-> on_error = on_error;

            axis2_callback_set_data(callback, (void*)callback_data);

            /* Send request */
            axis2_svc_client_send_receive_non_blocking(svc_client, env, payload, callback);
            
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);
              
              axis2_options_set_action(options, env, NULL);
            }
         }

         

        struct axis2_stub_StatisticsAdmin_getAvgOperationResponseTime_callback_data
        {   
            void *data;
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getAvgOperationResponseTimeResponse_t* _getAvgOperationResponseTimeResponse, void *data);
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data);
        };

        static axis2_status_t AXIS2_CALL axis2_stub_on_error_StatisticsAdmin_getAvgOperationResponseTime(axis2_callback_t *callback, const axutil_env_t *env, int exception)
        {
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int, void *data);
            struct axis2_stub_StatisticsAdmin_getAvgOperationResponseTime_callback_data* callback_data = NULL;
            void *user_data = NULL;

            axis2_status_t status;
        
            callback_data = (struct axis2_stub_StatisticsAdmin_getAvgOperationResponseTime_callback_data*)axis2_callback_get_data(callback);
        
            user_data = callback_data->data;
            on_error = callback_data->on_error;
        
            status = on_error(env, exception, user_data);

            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        } 

        axis2_status_t AXIS2_CALL axis2_stub_on_complete_StatisticsAdmin_getAvgOperationResponseTime(axis2_callback_t *callback, const axutil_env_t *env)
        {
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getAvgOperationResponseTimeResponse_t* _getAvgOperationResponseTimeResponse, void *data);
            struct axis2_stub_StatisticsAdmin_getAvgOperationResponseTime_callback_data* callback_data = NULL;
            void *user_data = NULL;
            axis2_status_t status = AXIS2_SUCCESS;
 
            adb_getAvgOperationResponseTimeResponse_t* ret_val;
            

            axiom_node_t *ret_node = NULL;
            axiom_soap_envelope_t *soap_envelope = NULL;

            

            callback_data = (struct axis2_stub_StatisticsAdmin_getAvgOperationResponseTime_callback_data*)axis2_callback_get_data(callback);

            soap_envelope = axis2_callback_get_envelope(callback, env);
            if(soap_envelope)
            {
                axiom_soap_body_t *soap_body;
                soap_body = axiom_soap_envelope_get_body(soap_envelope, env);
                if(soap_body)
                {
                    axiom_node_t *body_node = axiom_soap_body_get_base_node(soap_body, env);
                    if(body_node)
                    {
                        ret_node = axiom_node_get_first_child(body_node, env);
                    }
                }
                
                
            }

            user_data = callback_data->data;
            on_complete = callback_data->on_complete;

            
                    if(ret_node != NULL)
                    {
                        ret_val = adb_getAvgOperationResponseTimeResponse_create(env);
     
                        if(adb_getAvgOperationResponseTimeResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                        {
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the LendResponse_deserialize: "
                                                                    "This should be due to an invalid XML");
                            adb_getAvgOperationResponseTimeResponse_free(ret_val, env);
                            ret_val = NULL;
                        }
                     }
                     else
                     {
                         ret_val = NULL; 
                     }

                     
                         status = on_complete(env, ret_val, user_data);
                         
 
            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        }

        /**
          * auto generated method signature for asynchronous invocations
          * for "getAvgOperationResponseTime|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub
          * @param env environment ( mandatory)
          * @param _getAvgOperationResponseTime of the adb_getAvgOperationResponseTime_t*
          * @param user_data user data to be accessed by the callbacks
          * @param on_complete callback to handle on complete
          * @param on_error callback to handle on error
          */

         void AXIS2_CALL
         axis2_stub_start_op_StatisticsAdmin_getAvgOperationResponseTime( axis2_stub_t *stub, const axutil_env_t *env,
                                              adb_getAvgOperationResponseTime_t* _getAvgOperationResponseTime,
                                                  void *user_data,
                                                  axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getAvgOperationResponseTimeResponse_t* _getAvgOperationResponseTimeResponse, void *data) ,
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) )
         {

            axis2_callback_t *callback = NULL;

            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;

            const axis2_char_t *soap_action = NULL;
            axiom_node_t *payload = NULL;

            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            
            
            struct axis2_stub_StatisticsAdmin_getAvgOperationResponseTime_callback_data *callback_data;

            callback_data = (struct axis2_stub_StatisticsAdmin_getAvgOperationResponseTime_callback_data*) AXIS2_MALLOC(env->allocator, 
                                    sizeof(struct axis2_stub_StatisticsAdmin_getAvgOperationResponseTime_callback_data));
            if(NULL == callback_data)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "Can not allocate memeory for the callback data structures");
                return;
            }
            

            
                                payload = adb_getAvgOperationResponseTime_serialize(_getAvgOperationResponseTime, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           


            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
              AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
              AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "options is null in stub");
              return;
            }

            soap_act =axis2_options_get_soap_action (options, env);
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getAvgOperationResponseTime";
              soap_act = axutil_string_create(env, "urn:getAvgOperationResponseTime");
              axis2_options_set_soap_action(options, env, soap_act);
            }
            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             

            callback = axis2_callback_create(env);
            /* Set our on_complete fucntion pointer to the callback object */
            axis2_callback_set_on_complete(callback, axis2_stub_on_complete_StatisticsAdmin_getAvgOperationResponseTime);
            /* Set our on_error function pointer to the callback object */
            axis2_callback_set_on_error(callback, axis2_stub_on_error_StatisticsAdmin_getAvgOperationResponseTime);

            callback_data-> data = user_data;
            callback_data-> on_complete = on_complete;
            callback_data-> on_error = on_error;

            axis2_callback_set_data(callback, (void*)callback_data);

            /* Send request */
            axis2_svc_client_send_receive_non_blocking(svc_client, env, payload, callback);
            
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);
              
              axis2_options_set_action(options, env, NULL);
            }
         }

         

        struct axis2_stub_StatisticsAdmin_getOperationStatistics_callback_data
        {   
            void *data;
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getOperationStatisticsResponse_t* _getOperationStatisticsResponse, void *data);
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data);
        };

        static axis2_status_t AXIS2_CALL axis2_stub_on_error_StatisticsAdmin_getOperationStatistics(axis2_callback_t *callback, const axutil_env_t *env, int exception)
        {
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int, void *data);
            struct axis2_stub_StatisticsAdmin_getOperationStatistics_callback_data* callback_data = NULL;
            void *user_data = NULL;

            axis2_status_t status;
        
            callback_data = (struct axis2_stub_StatisticsAdmin_getOperationStatistics_callback_data*)axis2_callback_get_data(callback);
        
            user_data = callback_data->data;
            on_error = callback_data->on_error;
        
            status = on_error(env, exception, user_data);

            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        } 

        axis2_status_t AXIS2_CALL axis2_stub_on_complete_StatisticsAdmin_getOperationStatistics(axis2_callback_t *callback, const axutil_env_t *env)
        {
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getOperationStatisticsResponse_t* _getOperationStatisticsResponse, void *data);
            struct axis2_stub_StatisticsAdmin_getOperationStatistics_callback_data* callback_data = NULL;
            void *user_data = NULL;
            axis2_status_t status = AXIS2_SUCCESS;
 
            adb_getOperationStatisticsResponse_t* ret_val;
            

            axiom_node_t *ret_node = NULL;
            axiom_soap_envelope_t *soap_envelope = NULL;

            

            callback_data = (struct axis2_stub_StatisticsAdmin_getOperationStatistics_callback_data*)axis2_callback_get_data(callback);

            soap_envelope = axis2_callback_get_envelope(callback, env);
            if(soap_envelope)
            {
                axiom_soap_body_t *soap_body;
                soap_body = axiom_soap_envelope_get_body(soap_envelope, env);
                if(soap_body)
                {
                    axiom_node_t *body_node = axiom_soap_body_get_base_node(soap_body, env);
                    if(body_node)
                    {
                        ret_node = axiom_node_get_first_child(body_node, env);
                    }
                }
                
                
            }

            user_data = callback_data->data;
            on_complete = callback_data->on_complete;

            
                    if(ret_node != NULL)
                    {
                        ret_val = adb_getOperationStatisticsResponse_create(env);
     
                        if(adb_getOperationStatisticsResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                        {
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the LendResponse_deserialize: "
                                                                    "This should be due to an invalid XML");
                            adb_getOperationStatisticsResponse_free(ret_val, env);
                            ret_val = NULL;
                        }
                     }
                     else
                     {
                         ret_val = NULL; 
                     }

                     
                         status = on_complete(env, ret_val, user_data);
                         
 
            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        }

        /**
          * auto generated method signature for asynchronous invocations
          * for "getOperationStatistics|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub
          * @param env environment ( mandatory)
          * @param _getOperationStatistics of the adb_getOperationStatistics_t*
          * @param user_data user data to be accessed by the callbacks
          * @param on_complete callback to handle on complete
          * @param on_error callback to handle on error
          */

         void AXIS2_CALL
         axis2_stub_start_op_StatisticsAdmin_getOperationStatistics( axis2_stub_t *stub, const axutil_env_t *env,
                                              adb_getOperationStatistics_t* _getOperationStatistics,
                                                  void *user_data,
                                                  axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getOperationStatisticsResponse_t* _getOperationStatisticsResponse, void *data) ,
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) )
         {

            axis2_callback_t *callback = NULL;

            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;

            const axis2_char_t *soap_action = NULL;
            axiom_node_t *payload = NULL;

            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            
            
            struct axis2_stub_StatisticsAdmin_getOperationStatistics_callback_data *callback_data;

            callback_data = (struct axis2_stub_StatisticsAdmin_getOperationStatistics_callback_data*) AXIS2_MALLOC(env->allocator, 
                                    sizeof(struct axis2_stub_StatisticsAdmin_getOperationStatistics_callback_data));
            if(NULL == callback_data)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "Can not allocate memeory for the callback data structures");
                return;
            }
            

            
                                payload = adb_getOperationStatistics_serialize(_getOperationStatistics, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           


            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
              AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
              AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "options is null in stub");
              return;
            }

            soap_act =axis2_options_get_soap_action (options, env);
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getOperationStatistics";
              soap_act = axutil_string_create(env, "urn:getOperationStatistics");
              axis2_options_set_soap_action(options, env, soap_act);
            }
            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             

            callback = axis2_callback_create(env);
            /* Set our on_complete fucntion pointer to the callback object */
            axis2_callback_set_on_complete(callback, axis2_stub_on_complete_StatisticsAdmin_getOperationStatistics);
            /* Set our on_error function pointer to the callback object */
            axis2_callback_set_on_error(callback, axis2_stub_on_error_StatisticsAdmin_getOperationStatistics);

            callback_data-> data = user_data;
            callback_data-> on_complete = on_complete;
            callback_data-> on_error = on_error;

            axis2_callback_set_data(callback, (void*)callback_data);

            /* Send request */
            axis2_svc_client_send_receive_non_blocking(svc_client, env, payload, callback);
            
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);
              
              axis2_options_set_action(options, env, NULL);
            }
         }

         

        struct axis2_stub_StatisticsAdmin_getMinSystemResponseTime_callback_data
        {   
            void *data;
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getMinSystemResponseTimeResponse_t* _getMinSystemResponseTimeResponse, void *data);
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data);
        };

        static axis2_status_t AXIS2_CALL axis2_stub_on_error_StatisticsAdmin_getMinSystemResponseTime(axis2_callback_t *callback, const axutil_env_t *env, int exception)
        {
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int, void *data);
            struct axis2_stub_StatisticsAdmin_getMinSystemResponseTime_callback_data* callback_data = NULL;
            void *user_data = NULL;

            axis2_status_t status;
        
            callback_data = (struct axis2_stub_StatisticsAdmin_getMinSystemResponseTime_callback_data*)axis2_callback_get_data(callback);
        
            user_data = callback_data->data;
            on_error = callback_data->on_error;
        
            status = on_error(env, exception, user_data);

            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        } 

        axis2_status_t AXIS2_CALL axis2_stub_on_complete_StatisticsAdmin_getMinSystemResponseTime(axis2_callback_t *callback, const axutil_env_t *env)
        {
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getMinSystemResponseTimeResponse_t* _getMinSystemResponseTimeResponse, void *data);
            struct axis2_stub_StatisticsAdmin_getMinSystemResponseTime_callback_data* callback_data = NULL;
            void *user_data = NULL;
            axis2_status_t status = AXIS2_SUCCESS;
 
            adb_getMinSystemResponseTimeResponse_t* ret_val;
            

            axiom_node_t *ret_node = NULL;
            axiom_soap_envelope_t *soap_envelope = NULL;

            

            callback_data = (struct axis2_stub_StatisticsAdmin_getMinSystemResponseTime_callback_data*)axis2_callback_get_data(callback);

            soap_envelope = axis2_callback_get_envelope(callback, env);
            if(soap_envelope)
            {
                axiom_soap_body_t *soap_body;
                soap_body = axiom_soap_envelope_get_body(soap_envelope, env);
                if(soap_body)
                {
                    axiom_node_t *body_node = axiom_soap_body_get_base_node(soap_body, env);
                    if(body_node)
                    {
                        ret_node = axiom_node_get_first_child(body_node, env);
                    }
                }
                
                
            }

            user_data = callback_data->data;
            on_complete = callback_data->on_complete;

            
                    if(ret_node != NULL)
                    {
                        ret_val = adb_getMinSystemResponseTimeResponse_create(env);
     
                        if(adb_getMinSystemResponseTimeResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                        {
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the LendResponse_deserialize: "
                                                                    "This should be due to an invalid XML");
                            adb_getMinSystemResponseTimeResponse_free(ret_val, env);
                            ret_val = NULL;
                        }
                     }
                     else
                     {
                         ret_val = NULL; 
                     }

                     
                         status = on_complete(env, ret_val, user_data);
                         
 
            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        }

        /**
          * auto generated method signature for asynchronous invocations
          * for "getMinSystemResponseTime|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub
          * @param env environment ( mandatory)
          * @param user_data user data to be accessed by the callbacks
          * @param on_complete callback to handle on complete
          * @param on_error callback to handle on error
          */

         void AXIS2_CALL
         axis2_stub_start_op_StatisticsAdmin_getMinSystemResponseTime( axis2_stub_t *stub, const axutil_env_t *env,
                                                  void *user_data,
                                                  axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getMinSystemResponseTimeResponse_t* _getMinSystemResponseTimeResponse, void *data) ,
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) )
         {

            axis2_callback_t *callback = NULL;

            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;

            const axis2_char_t *soap_action = NULL;
            axiom_node_t *payload = NULL;

            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            
            
            struct axis2_stub_StatisticsAdmin_getMinSystemResponseTime_callback_data *callback_data;

            callback_data = (struct axis2_stub_StatisticsAdmin_getMinSystemResponseTime_callback_data*) AXIS2_MALLOC(env->allocator, 
                                    sizeof(struct axis2_stub_StatisticsAdmin_getMinSystemResponseTime_callback_data));
            if(NULL == callback_data)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "Can not allocate memeory for the callback data structures");
                return;
            }
            

            


            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
              AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
              AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "options is null in stub");
              return;
            }

            soap_act =axis2_options_get_soap_action (options, env);
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getMinSystemResponseTime";
              soap_act = axutil_string_create(env, "urn:getMinSystemResponseTime");
              axis2_options_set_soap_action(options, env, soap_act);
            }
            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             

            callback = axis2_callback_create(env);
            /* Set our on_complete fucntion pointer to the callback object */
            axis2_callback_set_on_complete(callback, axis2_stub_on_complete_StatisticsAdmin_getMinSystemResponseTime);
            /* Set our on_error function pointer to the callback object */
            axis2_callback_set_on_error(callback, axis2_stub_on_error_StatisticsAdmin_getMinSystemResponseTime);

            callback_data-> data = user_data;
            callback_data-> on_complete = on_complete;
            callback_data-> on_error = on_error;

            axis2_callback_set_data(callback, (void*)callback_data);

            /* Send request */
            axis2_svc_client_send_receive_non_blocking(svc_client, env, payload, callback);
            
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);
              
              axis2_options_set_action(options, env, NULL);
            }
         }

         

        struct axis2_stub_StatisticsAdmin_getSystemFaultCount_callback_data
        {   
            void *data;
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getSystemFaultCountResponse_t* _getSystemFaultCountResponse, void *data);
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data);
        };

        static axis2_status_t AXIS2_CALL axis2_stub_on_error_StatisticsAdmin_getSystemFaultCount(axis2_callback_t *callback, const axutil_env_t *env, int exception)
        {
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int, void *data);
            struct axis2_stub_StatisticsAdmin_getSystemFaultCount_callback_data* callback_data = NULL;
            void *user_data = NULL;

            axis2_status_t status;
        
            callback_data = (struct axis2_stub_StatisticsAdmin_getSystemFaultCount_callback_data*)axis2_callback_get_data(callback);
        
            user_data = callback_data->data;
            on_error = callback_data->on_error;
        
            status = on_error(env, exception, user_data);

            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        } 

        axis2_status_t AXIS2_CALL axis2_stub_on_complete_StatisticsAdmin_getSystemFaultCount(axis2_callback_t *callback, const axutil_env_t *env)
        {
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getSystemFaultCountResponse_t* _getSystemFaultCountResponse, void *data);
            struct axis2_stub_StatisticsAdmin_getSystemFaultCount_callback_data* callback_data = NULL;
            void *user_data = NULL;
            axis2_status_t status = AXIS2_SUCCESS;
 
            adb_getSystemFaultCountResponse_t* ret_val;
            

            axiom_node_t *ret_node = NULL;
            axiom_soap_envelope_t *soap_envelope = NULL;

            

            callback_data = (struct axis2_stub_StatisticsAdmin_getSystemFaultCount_callback_data*)axis2_callback_get_data(callback);

            soap_envelope = axis2_callback_get_envelope(callback, env);
            if(soap_envelope)
            {
                axiom_soap_body_t *soap_body;
                soap_body = axiom_soap_envelope_get_body(soap_envelope, env);
                if(soap_body)
                {
                    axiom_node_t *body_node = axiom_soap_body_get_base_node(soap_body, env);
                    if(body_node)
                    {
                        ret_node = axiom_node_get_first_child(body_node, env);
                    }
                }
                
                
            }

            user_data = callback_data->data;
            on_complete = callback_data->on_complete;

            
                    if(ret_node != NULL)
                    {
                        ret_val = adb_getSystemFaultCountResponse_create(env);
     
                        if(adb_getSystemFaultCountResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                        {
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the LendResponse_deserialize: "
                                                                    "This should be due to an invalid XML");
                            adb_getSystemFaultCountResponse_free(ret_val, env);
                            ret_val = NULL;
                        }
                     }
                     else
                     {
                         ret_val = NULL; 
                     }

                     
                         status = on_complete(env, ret_val, user_data);
                         
 
            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        }

        /**
          * auto generated method signature for asynchronous invocations
          * for "getSystemFaultCount|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub
          * @param env environment ( mandatory)
          * @param user_data user data to be accessed by the callbacks
          * @param on_complete callback to handle on complete
          * @param on_error callback to handle on error
          */

         void AXIS2_CALL
         axis2_stub_start_op_StatisticsAdmin_getSystemFaultCount( axis2_stub_t *stub, const axutil_env_t *env,
                                                  void *user_data,
                                                  axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getSystemFaultCountResponse_t* _getSystemFaultCountResponse, void *data) ,
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) )
         {

            axis2_callback_t *callback = NULL;

            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;

            const axis2_char_t *soap_action = NULL;
            axiom_node_t *payload = NULL;

            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            
            
            struct axis2_stub_StatisticsAdmin_getSystemFaultCount_callback_data *callback_data;

            callback_data = (struct axis2_stub_StatisticsAdmin_getSystemFaultCount_callback_data*) AXIS2_MALLOC(env->allocator, 
                                    sizeof(struct axis2_stub_StatisticsAdmin_getSystemFaultCount_callback_data));
            if(NULL == callback_data)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "Can not allocate memeory for the callback data structures");
                return;
            }
            

            


            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
              AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
              AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "options is null in stub");
              return;
            }

            soap_act =axis2_options_get_soap_action (options, env);
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getSystemFaultCount";
              soap_act = axutil_string_create(env, "urn:getSystemFaultCount");
              axis2_options_set_soap_action(options, env, soap_act);
            }
            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             

            callback = axis2_callback_create(env);
            /* Set our on_complete fucntion pointer to the callback object */
            axis2_callback_set_on_complete(callback, axis2_stub_on_complete_StatisticsAdmin_getSystemFaultCount);
            /* Set our on_error function pointer to the callback object */
            axis2_callback_set_on_error(callback, axis2_stub_on_error_StatisticsAdmin_getSystemFaultCount);

            callback_data-> data = user_data;
            callback_data-> on_complete = on_complete;
            callback_data-> on_error = on_error;

            axis2_callback_set_data(callback, (void*)callback_data);

            /* Send request */
            axis2_svc_client_send_receive_non_blocking(svc_client, env, payload, callback);
            
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);
              
              axis2_options_set_action(options, env, NULL);
            }
         }

         

        struct axis2_stub_StatisticsAdmin_getMaxSystemResponseTime_callback_data
        {   
            void *data;
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getMaxSystemResponseTimeResponse_t* _getMaxSystemResponseTimeResponse, void *data);
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data);
        };

        static axis2_status_t AXIS2_CALL axis2_stub_on_error_StatisticsAdmin_getMaxSystemResponseTime(axis2_callback_t *callback, const axutil_env_t *env, int exception)
        {
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int, void *data);
            struct axis2_stub_StatisticsAdmin_getMaxSystemResponseTime_callback_data* callback_data = NULL;
            void *user_data = NULL;

            axis2_status_t status;
        
            callback_data = (struct axis2_stub_StatisticsAdmin_getMaxSystemResponseTime_callback_data*)axis2_callback_get_data(callback);
        
            user_data = callback_data->data;
            on_error = callback_data->on_error;
        
            status = on_error(env, exception, user_data);

            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        } 

        axis2_status_t AXIS2_CALL axis2_stub_on_complete_StatisticsAdmin_getMaxSystemResponseTime(axis2_callback_t *callback, const axutil_env_t *env)
        {
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getMaxSystemResponseTimeResponse_t* _getMaxSystemResponseTimeResponse, void *data);
            struct axis2_stub_StatisticsAdmin_getMaxSystemResponseTime_callback_data* callback_data = NULL;
            void *user_data = NULL;
            axis2_status_t status = AXIS2_SUCCESS;
 
            adb_getMaxSystemResponseTimeResponse_t* ret_val;
            

            axiom_node_t *ret_node = NULL;
            axiom_soap_envelope_t *soap_envelope = NULL;

            

            callback_data = (struct axis2_stub_StatisticsAdmin_getMaxSystemResponseTime_callback_data*)axis2_callback_get_data(callback);

            soap_envelope = axis2_callback_get_envelope(callback, env);
            if(soap_envelope)
            {
                axiom_soap_body_t *soap_body;
                soap_body = axiom_soap_envelope_get_body(soap_envelope, env);
                if(soap_body)
                {
                    axiom_node_t *body_node = axiom_soap_body_get_base_node(soap_body, env);
                    if(body_node)
                    {
                        ret_node = axiom_node_get_first_child(body_node, env);
                    }
                }
                
                
            }

            user_data = callback_data->data;
            on_complete = callback_data->on_complete;

            
                    if(ret_node != NULL)
                    {
                        ret_val = adb_getMaxSystemResponseTimeResponse_create(env);
     
                        if(adb_getMaxSystemResponseTimeResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                        {
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the LendResponse_deserialize: "
                                                                    "This should be due to an invalid XML");
                            adb_getMaxSystemResponseTimeResponse_free(ret_val, env);
                            ret_val = NULL;
                        }
                     }
                     else
                     {
                         ret_val = NULL; 
                     }

                     
                         status = on_complete(env, ret_val, user_data);
                         
 
            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        }

        /**
          * auto generated method signature for asynchronous invocations
          * for "getMaxSystemResponseTime|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub
          * @param env environment ( mandatory)
          * @param user_data user data to be accessed by the callbacks
          * @param on_complete callback to handle on complete
          * @param on_error callback to handle on error
          */

         void AXIS2_CALL
         axis2_stub_start_op_StatisticsAdmin_getMaxSystemResponseTime( axis2_stub_t *stub, const axutil_env_t *env,
                                                  void *user_data,
                                                  axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getMaxSystemResponseTimeResponse_t* _getMaxSystemResponseTimeResponse, void *data) ,
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) )
         {

            axis2_callback_t *callback = NULL;

            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;

            const axis2_char_t *soap_action = NULL;
            axiom_node_t *payload = NULL;

            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            
            
            struct axis2_stub_StatisticsAdmin_getMaxSystemResponseTime_callback_data *callback_data;

            callback_data = (struct axis2_stub_StatisticsAdmin_getMaxSystemResponseTime_callback_data*) AXIS2_MALLOC(env->allocator, 
                                    sizeof(struct axis2_stub_StatisticsAdmin_getMaxSystemResponseTime_callback_data));
            if(NULL == callback_data)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "Can not allocate memeory for the callback data structures");
                return;
            }
            

            


            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
              AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
              AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "options is null in stub");
              return;
            }

            soap_act =axis2_options_get_soap_action (options, env);
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getMaxSystemResponseTime";
              soap_act = axutil_string_create(env, "urn:getMaxSystemResponseTime");
              axis2_options_set_soap_action(options, env, soap_act);
            }
            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             

            callback = axis2_callback_create(env);
            /* Set our on_complete fucntion pointer to the callback object */
            axis2_callback_set_on_complete(callback, axis2_stub_on_complete_StatisticsAdmin_getMaxSystemResponseTime);
            /* Set our on_error function pointer to the callback object */
            axis2_callback_set_on_error(callback, axis2_stub_on_error_StatisticsAdmin_getMaxSystemResponseTime);

            callback_data-> data = user_data;
            callback_data-> on_complete = on_complete;
            callback_data-> on_error = on_error;

            axis2_callback_set_data(callback, (void*)callback_data);

            /* Send request */
            axis2_svc_client_send_receive_non_blocking(svc_client, env, payload, callback);
            
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);
              
              axis2_options_set_action(options, env, NULL);
            }
         }

         

        struct axis2_stub_StatisticsAdmin_getServiceFaultCount_callback_data
        {   
            void *data;
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getServiceFaultCountResponse_t* _getServiceFaultCountResponse, void *data);
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data);
        };

        static axis2_status_t AXIS2_CALL axis2_stub_on_error_StatisticsAdmin_getServiceFaultCount(axis2_callback_t *callback, const axutil_env_t *env, int exception)
        {
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int, void *data);
            struct axis2_stub_StatisticsAdmin_getServiceFaultCount_callback_data* callback_data = NULL;
            void *user_data = NULL;

            axis2_status_t status;
        
            callback_data = (struct axis2_stub_StatisticsAdmin_getServiceFaultCount_callback_data*)axis2_callback_get_data(callback);
        
            user_data = callback_data->data;
            on_error = callback_data->on_error;
        
            status = on_error(env, exception, user_data);

            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        } 

        axis2_status_t AXIS2_CALL axis2_stub_on_complete_StatisticsAdmin_getServiceFaultCount(axis2_callback_t *callback, const axutil_env_t *env)
        {
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getServiceFaultCountResponse_t* _getServiceFaultCountResponse, void *data);
            struct axis2_stub_StatisticsAdmin_getServiceFaultCount_callback_data* callback_data = NULL;
            void *user_data = NULL;
            axis2_status_t status = AXIS2_SUCCESS;
 
            adb_getServiceFaultCountResponse_t* ret_val;
            

            axiom_node_t *ret_node = NULL;
            axiom_soap_envelope_t *soap_envelope = NULL;

            

            callback_data = (struct axis2_stub_StatisticsAdmin_getServiceFaultCount_callback_data*)axis2_callback_get_data(callback);

            soap_envelope = axis2_callback_get_envelope(callback, env);
            if(soap_envelope)
            {
                axiom_soap_body_t *soap_body;
                soap_body = axiom_soap_envelope_get_body(soap_envelope, env);
                if(soap_body)
                {
                    axiom_node_t *body_node = axiom_soap_body_get_base_node(soap_body, env);
                    if(body_node)
                    {
                        ret_node = axiom_node_get_first_child(body_node, env);
                    }
                }
                
                
            }

            user_data = callback_data->data;
            on_complete = callback_data->on_complete;

            
                    if(ret_node != NULL)
                    {
                        ret_val = adb_getServiceFaultCountResponse_create(env);
     
                        if(adb_getServiceFaultCountResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                        {
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the LendResponse_deserialize: "
                                                                    "This should be due to an invalid XML");
                            adb_getServiceFaultCountResponse_free(ret_val, env);
                            ret_val = NULL;
                        }
                     }
                     else
                     {
                         ret_val = NULL; 
                     }

                     
                         status = on_complete(env, ret_val, user_data);
                         
 
            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        }

        /**
          * auto generated method signature for asynchronous invocations
          * for "getServiceFaultCount|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub
          * @param env environment ( mandatory)
          * @param _getServiceFaultCount of the adb_getServiceFaultCount_t*
          * @param user_data user data to be accessed by the callbacks
          * @param on_complete callback to handle on complete
          * @param on_error callback to handle on error
          */

         void AXIS2_CALL
         axis2_stub_start_op_StatisticsAdmin_getServiceFaultCount( axis2_stub_t *stub, const axutil_env_t *env,
                                              adb_getServiceFaultCount_t* _getServiceFaultCount,
                                                  void *user_data,
                                                  axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getServiceFaultCountResponse_t* _getServiceFaultCountResponse, void *data) ,
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) )
         {

            axis2_callback_t *callback = NULL;

            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;

            const axis2_char_t *soap_action = NULL;
            axiom_node_t *payload = NULL;

            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            
            
            struct axis2_stub_StatisticsAdmin_getServiceFaultCount_callback_data *callback_data;

            callback_data = (struct axis2_stub_StatisticsAdmin_getServiceFaultCount_callback_data*) AXIS2_MALLOC(env->allocator, 
                                    sizeof(struct axis2_stub_StatisticsAdmin_getServiceFaultCount_callback_data));
            if(NULL == callback_data)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "Can not allocate memeory for the callback data structures");
                return;
            }
            

            
                                payload = adb_getServiceFaultCount_serialize(_getServiceFaultCount, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           


            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
              AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
              AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "options is null in stub");
              return;
            }

            soap_act =axis2_options_get_soap_action (options, env);
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getServiceFaultCount";
              soap_act = axutil_string_create(env, "urn:getServiceFaultCount");
              axis2_options_set_soap_action(options, env, soap_act);
            }
            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             

            callback = axis2_callback_create(env);
            /* Set our on_complete fucntion pointer to the callback object */
            axis2_callback_set_on_complete(callback, axis2_stub_on_complete_StatisticsAdmin_getServiceFaultCount);
            /* Set our on_error function pointer to the callback object */
            axis2_callback_set_on_error(callback, axis2_stub_on_error_StatisticsAdmin_getServiceFaultCount);

            callback_data-> data = user_data;
            callback_data-> on_complete = on_complete;
            callback_data-> on_error = on_error;

            axis2_callback_set_data(callback, (void*)callback_data);

            /* Send request */
            axis2_svc_client_send_receive_non_blocking(svc_client, env, payload, callback);
            
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);
              
              axis2_options_set_action(options, env, NULL);
            }
         }

         

        struct axis2_stub_StatisticsAdmin_getMinServiceResponseTime_callback_data
        {   
            void *data;
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getMinServiceResponseTimeResponse_t* _getMinServiceResponseTimeResponse, void *data);
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data);
        };

        static axis2_status_t AXIS2_CALL axis2_stub_on_error_StatisticsAdmin_getMinServiceResponseTime(axis2_callback_t *callback, const axutil_env_t *env, int exception)
        {
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int, void *data);
            struct axis2_stub_StatisticsAdmin_getMinServiceResponseTime_callback_data* callback_data = NULL;
            void *user_data = NULL;

            axis2_status_t status;
        
            callback_data = (struct axis2_stub_StatisticsAdmin_getMinServiceResponseTime_callback_data*)axis2_callback_get_data(callback);
        
            user_data = callback_data->data;
            on_error = callback_data->on_error;
        
            status = on_error(env, exception, user_data);

            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        } 

        axis2_status_t AXIS2_CALL axis2_stub_on_complete_StatisticsAdmin_getMinServiceResponseTime(axis2_callback_t *callback, const axutil_env_t *env)
        {
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getMinServiceResponseTimeResponse_t* _getMinServiceResponseTimeResponse, void *data);
            struct axis2_stub_StatisticsAdmin_getMinServiceResponseTime_callback_data* callback_data = NULL;
            void *user_data = NULL;
            axis2_status_t status = AXIS2_SUCCESS;
 
            adb_getMinServiceResponseTimeResponse_t* ret_val;
            

            axiom_node_t *ret_node = NULL;
            axiom_soap_envelope_t *soap_envelope = NULL;

            

            callback_data = (struct axis2_stub_StatisticsAdmin_getMinServiceResponseTime_callback_data*)axis2_callback_get_data(callback);

            soap_envelope = axis2_callback_get_envelope(callback, env);
            if(soap_envelope)
            {
                axiom_soap_body_t *soap_body;
                soap_body = axiom_soap_envelope_get_body(soap_envelope, env);
                if(soap_body)
                {
                    axiom_node_t *body_node = axiom_soap_body_get_base_node(soap_body, env);
                    if(body_node)
                    {
                        ret_node = axiom_node_get_first_child(body_node, env);
                    }
                }
                
                
            }

            user_data = callback_data->data;
            on_complete = callback_data->on_complete;

            
                    if(ret_node != NULL)
                    {
                        ret_val = adb_getMinServiceResponseTimeResponse_create(env);
     
                        if(adb_getMinServiceResponseTimeResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                        {
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the LendResponse_deserialize: "
                                                                    "This should be due to an invalid XML");
                            adb_getMinServiceResponseTimeResponse_free(ret_val, env);
                            ret_val = NULL;
                        }
                     }
                     else
                     {
                         ret_val = NULL; 
                     }

                     
                         status = on_complete(env, ret_val, user_data);
                         
 
            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        }

        /**
          * auto generated method signature for asynchronous invocations
          * for "getMinServiceResponseTime|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub
          * @param env environment ( mandatory)
          * @param _getMinServiceResponseTime of the adb_getMinServiceResponseTime_t*
          * @param user_data user data to be accessed by the callbacks
          * @param on_complete callback to handle on complete
          * @param on_error callback to handle on error
          */

         void AXIS2_CALL
         axis2_stub_start_op_StatisticsAdmin_getMinServiceResponseTime( axis2_stub_t *stub, const axutil_env_t *env,
                                              adb_getMinServiceResponseTime_t* _getMinServiceResponseTime,
                                                  void *user_data,
                                                  axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getMinServiceResponseTimeResponse_t* _getMinServiceResponseTimeResponse, void *data) ,
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) )
         {

            axis2_callback_t *callback = NULL;

            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;

            const axis2_char_t *soap_action = NULL;
            axiom_node_t *payload = NULL;

            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            
            
            struct axis2_stub_StatisticsAdmin_getMinServiceResponseTime_callback_data *callback_data;

            callback_data = (struct axis2_stub_StatisticsAdmin_getMinServiceResponseTime_callback_data*) AXIS2_MALLOC(env->allocator, 
                                    sizeof(struct axis2_stub_StatisticsAdmin_getMinServiceResponseTime_callback_data));
            if(NULL == callback_data)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "Can not allocate memeory for the callback data structures");
                return;
            }
            

            
                                payload = adb_getMinServiceResponseTime_serialize(_getMinServiceResponseTime, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           


            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
              AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
              AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "options is null in stub");
              return;
            }

            soap_act =axis2_options_get_soap_action (options, env);
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getMinServiceResponseTime";
              soap_act = axutil_string_create(env, "urn:getMinServiceResponseTime");
              axis2_options_set_soap_action(options, env, soap_act);
            }
            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             

            callback = axis2_callback_create(env);
            /* Set our on_complete fucntion pointer to the callback object */
            axis2_callback_set_on_complete(callback, axis2_stub_on_complete_StatisticsAdmin_getMinServiceResponseTime);
            /* Set our on_error function pointer to the callback object */
            axis2_callback_set_on_error(callback, axis2_stub_on_error_StatisticsAdmin_getMinServiceResponseTime);

            callback_data-> data = user_data;
            callback_data-> on_complete = on_complete;
            callback_data-> on_error = on_error;

            axis2_callback_set_data(callback, (void*)callback_data);

            /* Send request */
            axis2_svc_client_send_receive_non_blocking(svc_client, env, payload, callback);
            
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);
              
              axis2_options_set_action(options, env, NULL);
            }
         }

         

        struct axis2_stub_StatisticsAdmin_getMaxOperationResponseTime_callback_data
        {   
            void *data;
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getMaxOperationResponseTimeResponse_t* _getMaxOperationResponseTimeResponse, void *data);
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data);
        };

        static axis2_status_t AXIS2_CALL axis2_stub_on_error_StatisticsAdmin_getMaxOperationResponseTime(axis2_callback_t *callback, const axutil_env_t *env, int exception)
        {
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int, void *data);
            struct axis2_stub_StatisticsAdmin_getMaxOperationResponseTime_callback_data* callback_data = NULL;
            void *user_data = NULL;

            axis2_status_t status;
        
            callback_data = (struct axis2_stub_StatisticsAdmin_getMaxOperationResponseTime_callback_data*)axis2_callback_get_data(callback);
        
            user_data = callback_data->data;
            on_error = callback_data->on_error;
        
            status = on_error(env, exception, user_data);

            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        } 

        axis2_status_t AXIS2_CALL axis2_stub_on_complete_StatisticsAdmin_getMaxOperationResponseTime(axis2_callback_t *callback, const axutil_env_t *env)
        {
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getMaxOperationResponseTimeResponse_t* _getMaxOperationResponseTimeResponse, void *data);
            struct axis2_stub_StatisticsAdmin_getMaxOperationResponseTime_callback_data* callback_data = NULL;
            void *user_data = NULL;
            axis2_status_t status = AXIS2_SUCCESS;
 
            adb_getMaxOperationResponseTimeResponse_t* ret_val;
            

            axiom_node_t *ret_node = NULL;
            axiom_soap_envelope_t *soap_envelope = NULL;

            

            callback_data = (struct axis2_stub_StatisticsAdmin_getMaxOperationResponseTime_callback_data*)axis2_callback_get_data(callback);

            soap_envelope = axis2_callback_get_envelope(callback, env);
            if(soap_envelope)
            {
                axiom_soap_body_t *soap_body;
                soap_body = axiom_soap_envelope_get_body(soap_envelope, env);
                if(soap_body)
                {
                    axiom_node_t *body_node = axiom_soap_body_get_base_node(soap_body, env);
                    if(body_node)
                    {
                        ret_node = axiom_node_get_first_child(body_node, env);
                    }
                }
                
                
            }

            user_data = callback_data->data;
            on_complete = callback_data->on_complete;

            
                    if(ret_node != NULL)
                    {
                        ret_val = adb_getMaxOperationResponseTimeResponse_create(env);
     
                        if(adb_getMaxOperationResponseTimeResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                        {
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the LendResponse_deserialize: "
                                                                    "This should be due to an invalid XML");
                            adb_getMaxOperationResponseTimeResponse_free(ret_val, env);
                            ret_val = NULL;
                        }
                     }
                     else
                     {
                         ret_val = NULL; 
                     }

                     
                         status = on_complete(env, ret_val, user_data);
                         
 
            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        }

        /**
          * auto generated method signature for asynchronous invocations
          * for "getMaxOperationResponseTime|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub
          * @param env environment ( mandatory)
          * @param _getMaxOperationResponseTime of the adb_getMaxOperationResponseTime_t*
          * @param user_data user data to be accessed by the callbacks
          * @param on_complete callback to handle on complete
          * @param on_error callback to handle on error
          */

         void AXIS2_CALL
         axis2_stub_start_op_StatisticsAdmin_getMaxOperationResponseTime( axis2_stub_t *stub, const axutil_env_t *env,
                                              adb_getMaxOperationResponseTime_t* _getMaxOperationResponseTime,
                                                  void *user_data,
                                                  axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getMaxOperationResponseTimeResponse_t* _getMaxOperationResponseTimeResponse, void *data) ,
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) )
         {

            axis2_callback_t *callback = NULL;

            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;

            const axis2_char_t *soap_action = NULL;
            axiom_node_t *payload = NULL;

            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            
            
            struct axis2_stub_StatisticsAdmin_getMaxOperationResponseTime_callback_data *callback_data;

            callback_data = (struct axis2_stub_StatisticsAdmin_getMaxOperationResponseTime_callback_data*) AXIS2_MALLOC(env->allocator, 
                                    sizeof(struct axis2_stub_StatisticsAdmin_getMaxOperationResponseTime_callback_data));
            if(NULL == callback_data)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "Can not allocate memeory for the callback data structures");
                return;
            }
            

            
                                payload = adb_getMaxOperationResponseTime_serialize(_getMaxOperationResponseTime, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           


            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
              AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
              AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "options is null in stub");
              return;
            }

            soap_act =axis2_options_get_soap_action (options, env);
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getMaxOperationResponseTime";
              soap_act = axutil_string_create(env, "urn:getMaxOperationResponseTime");
              axis2_options_set_soap_action(options, env, soap_act);
            }
            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             

            callback = axis2_callback_create(env);
            /* Set our on_complete fucntion pointer to the callback object */
            axis2_callback_set_on_complete(callback, axis2_stub_on_complete_StatisticsAdmin_getMaxOperationResponseTime);
            /* Set our on_error function pointer to the callback object */
            axis2_callback_set_on_error(callback, axis2_stub_on_error_StatisticsAdmin_getMaxOperationResponseTime);

            callback_data-> data = user_data;
            callback_data-> on_complete = on_complete;
            callback_data-> on_error = on_error;

            axis2_callback_set_data(callback, (void*)callback_data);

            /* Send request */
            axis2_svc_client_send_receive_non_blocking(svc_client, env, payload, callback);
            
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);
              
              axis2_options_set_action(options, env, NULL);
            }
         }

         

        struct axis2_stub_StatisticsAdmin_getServiceStatistics_callback_data
        {   
            void *data;
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getServiceStatisticsResponse_t* _getServiceStatisticsResponse, void *data);
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data);
        };

        static axis2_status_t AXIS2_CALL axis2_stub_on_error_StatisticsAdmin_getServiceStatistics(axis2_callback_t *callback, const axutil_env_t *env, int exception)
        {
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int, void *data);
            struct axis2_stub_StatisticsAdmin_getServiceStatistics_callback_data* callback_data = NULL;
            void *user_data = NULL;

            axis2_status_t status;
        
            callback_data = (struct axis2_stub_StatisticsAdmin_getServiceStatistics_callback_data*)axis2_callback_get_data(callback);
        
            user_data = callback_data->data;
            on_error = callback_data->on_error;
        
            status = on_error(env, exception, user_data);

            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        } 

        axis2_status_t AXIS2_CALL axis2_stub_on_complete_StatisticsAdmin_getServiceStatistics(axis2_callback_t *callback, const axutil_env_t *env)
        {
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getServiceStatisticsResponse_t* _getServiceStatisticsResponse, void *data);
            struct axis2_stub_StatisticsAdmin_getServiceStatistics_callback_data* callback_data = NULL;
            void *user_data = NULL;
            axis2_status_t status = AXIS2_SUCCESS;
 
            adb_getServiceStatisticsResponse_t* ret_val;
            

            axiom_node_t *ret_node = NULL;
            axiom_soap_envelope_t *soap_envelope = NULL;

            

            callback_data = (struct axis2_stub_StatisticsAdmin_getServiceStatistics_callback_data*)axis2_callback_get_data(callback);

            soap_envelope = axis2_callback_get_envelope(callback, env);
            if(soap_envelope)
            {
                axiom_soap_body_t *soap_body;
                soap_body = axiom_soap_envelope_get_body(soap_envelope, env);
                if(soap_body)
                {
                    axiom_node_t *body_node = axiom_soap_body_get_base_node(soap_body, env);
                    if(body_node)
                    {
                        ret_node = axiom_node_get_first_child(body_node, env);
                    }
                }
                
                
            }

            user_data = callback_data->data;
            on_complete = callback_data->on_complete;

            
                    if(ret_node != NULL)
                    {
                        ret_val = adb_getServiceStatisticsResponse_create(env);
     
                        if(adb_getServiceStatisticsResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                        {
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the LendResponse_deserialize: "
                                                                    "This should be due to an invalid XML");
                            adb_getServiceStatisticsResponse_free(ret_val, env);
                            ret_val = NULL;
                        }
                     }
                     else
                     {
                         ret_val = NULL; 
                     }

                     
                         status = on_complete(env, ret_val, user_data);
                         
 
            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        }

        /**
          * auto generated method signature for asynchronous invocations
          * for "getServiceStatistics|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub
          * @param env environment ( mandatory)
          * @param _getServiceStatistics of the adb_getServiceStatistics_t*
          * @param user_data user data to be accessed by the callbacks
          * @param on_complete callback to handle on complete
          * @param on_error callback to handle on error
          */

         void AXIS2_CALL
         axis2_stub_start_op_StatisticsAdmin_getServiceStatistics( axis2_stub_t *stub, const axutil_env_t *env,
                                              adb_getServiceStatistics_t* _getServiceStatistics,
                                                  void *user_data,
                                                  axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getServiceStatisticsResponse_t* _getServiceStatisticsResponse, void *data) ,
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) )
         {

            axis2_callback_t *callback = NULL;

            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;

            const axis2_char_t *soap_action = NULL;
            axiom_node_t *payload = NULL;

            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            
            
            struct axis2_stub_StatisticsAdmin_getServiceStatistics_callback_data *callback_data;

            callback_data = (struct axis2_stub_StatisticsAdmin_getServiceStatistics_callback_data*) AXIS2_MALLOC(env->allocator, 
                                    sizeof(struct axis2_stub_StatisticsAdmin_getServiceStatistics_callback_data));
            if(NULL == callback_data)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "Can not allocate memeory for the callback data structures");
                return;
            }
            

            
                                payload = adb_getServiceStatistics_serialize(_getServiceStatistics, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           


            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
              AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
              AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "options is null in stub");
              return;
            }

            soap_act =axis2_options_get_soap_action (options, env);
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getServiceStatistics";
              soap_act = axutil_string_create(env, "urn:getServiceStatistics");
              axis2_options_set_soap_action(options, env, soap_act);
            }
            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             

            callback = axis2_callback_create(env);
            /* Set our on_complete fucntion pointer to the callback object */
            axis2_callback_set_on_complete(callback, axis2_stub_on_complete_StatisticsAdmin_getServiceStatistics);
            /* Set our on_error function pointer to the callback object */
            axis2_callback_set_on_error(callback, axis2_stub_on_error_StatisticsAdmin_getServiceStatistics);

            callback_data-> data = user_data;
            callback_data-> on_complete = on_complete;
            callback_data-> on_error = on_error;

            axis2_callback_set_data(callback, (void*)callback_data);

            /* Send request */
            axis2_svc_client_send_receive_non_blocking(svc_client, env, payload, callback);
            
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);
              
              axis2_options_set_action(options, env, NULL);
            }
         }

         

        struct axis2_stub_StatisticsAdmin_getOperationFaultCount_callback_data
        {   
            void *data;
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getOperationFaultCountResponse_t* _getOperationFaultCountResponse, void *data);
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data);
        };

        static axis2_status_t AXIS2_CALL axis2_stub_on_error_StatisticsAdmin_getOperationFaultCount(axis2_callback_t *callback, const axutil_env_t *env, int exception)
        {
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int, void *data);
            struct axis2_stub_StatisticsAdmin_getOperationFaultCount_callback_data* callback_data = NULL;
            void *user_data = NULL;

            axis2_status_t status;
        
            callback_data = (struct axis2_stub_StatisticsAdmin_getOperationFaultCount_callback_data*)axis2_callback_get_data(callback);
        
            user_data = callback_data->data;
            on_error = callback_data->on_error;
        
            status = on_error(env, exception, user_data);

            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        } 

        axis2_status_t AXIS2_CALL axis2_stub_on_complete_StatisticsAdmin_getOperationFaultCount(axis2_callback_t *callback, const axutil_env_t *env)
        {
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getOperationFaultCountResponse_t* _getOperationFaultCountResponse, void *data);
            struct axis2_stub_StatisticsAdmin_getOperationFaultCount_callback_data* callback_data = NULL;
            void *user_data = NULL;
            axis2_status_t status = AXIS2_SUCCESS;
 
            adb_getOperationFaultCountResponse_t* ret_val;
            

            axiom_node_t *ret_node = NULL;
            axiom_soap_envelope_t *soap_envelope = NULL;

            

            callback_data = (struct axis2_stub_StatisticsAdmin_getOperationFaultCount_callback_data*)axis2_callback_get_data(callback);

            soap_envelope = axis2_callback_get_envelope(callback, env);
            if(soap_envelope)
            {
                axiom_soap_body_t *soap_body;
                soap_body = axiom_soap_envelope_get_body(soap_envelope, env);
                if(soap_body)
                {
                    axiom_node_t *body_node = axiom_soap_body_get_base_node(soap_body, env);
                    if(body_node)
                    {
                        ret_node = axiom_node_get_first_child(body_node, env);
                    }
                }
                
                
            }

            user_data = callback_data->data;
            on_complete = callback_data->on_complete;

            
                    if(ret_node != NULL)
                    {
                        ret_val = adb_getOperationFaultCountResponse_create(env);
     
                        if(adb_getOperationFaultCountResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                        {
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the LendResponse_deserialize: "
                                                                    "This should be due to an invalid XML");
                            adb_getOperationFaultCountResponse_free(ret_val, env);
                            ret_val = NULL;
                        }
                     }
                     else
                     {
                         ret_val = NULL; 
                     }

                     
                         status = on_complete(env, ret_val, user_data);
                         
 
            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        }

        /**
          * auto generated method signature for asynchronous invocations
          * for "getOperationFaultCount|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub
          * @param env environment ( mandatory)
          * @param _getOperationFaultCount of the adb_getOperationFaultCount_t*
          * @param user_data user data to be accessed by the callbacks
          * @param on_complete callback to handle on complete
          * @param on_error callback to handle on error
          */

         void AXIS2_CALL
         axis2_stub_start_op_StatisticsAdmin_getOperationFaultCount( axis2_stub_t *stub, const axutil_env_t *env,
                                              adb_getOperationFaultCount_t* _getOperationFaultCount,
                                                  void *user_data,
                                                  axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getOperationFaultCountResponse_t* _getOperationFaultCountResponse, void *data) ,
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) )
         {

            axis2_callback_t *callback = NULL;

            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;

            const axis2_char_t *soap_action = NULL;
            axiom_node_t *payload = NULL;

            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            
            
            struct axis2_stub_StatisticsAdmin_getOperationFaultCount_callback_data *callback_data;

            callback_data = (struct axis2_stub_StatisticsAdmin_getOperationFaultCount_callback_data*) AXIS2_MALLOC(env->allocator, 
                                    sizeof(struct axis2_stub_StatisticsAdmin_getOperationFaultCount_callback_data));
            if(NULL == callback_data)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "Can not allocate memeory for the callback data structures");
                return;
            }
            

            
                                payload = adb_getOperationFaultCount_serialize(_getOperationFaultCount, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           


            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
              AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
              AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "options is null in stub");
              return;
            }

            soap_act =axis2_options_get_soap_action (options, env);
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getOperationFaultCount";
              soap_act = axutil_string_create(env, "urn:getOperationFaultCount");
              axis2_options_set_soap_action(options, env, soap_act);
            }
            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             

            callback = axis2_callback_create(env);
            /* Set our on_complete fucntion pointer to the callback object */
            axis2_callback_set_on_complete(callback, axis2_stub_on_complete_StatisticsAdmin_getOperationFaultCount);
            /* Set our on_error function pointer to the callback object */
            axis2_callback_set_on_error(callback, axis2_stub_on_error_StatisticsAdmin_getOperationFaultCount);

            callback_data-> data = user_data;
            callback_data-> on_complete = on_complete;
            callback_data-> on_error = on_error;

            axis2_callback_set_data(callback, (void*)callback_data);

            /* Send request */
            axis2_svc_client_send_receive_non_blocking(svc_client, env, payload, callback);
            
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);
              
              axis2_options_set_action(options, env, NULL);
            }
         }

         

        struct axis2_stub_StatisticsAdmin_getAvgServiceResponseTime_callback_data
        {   
            void *data;
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getAvgServiceResponseTimeResponse_t* _getAvgServiceResponseTimeResponse, void *data);
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data);
        };

        static axis2_status_t AXIS2_CALL axis2_stub_on_error_StatisticsAdmin_getAvgServiceResponseTime(axis2_callback_t *callback, const axutil_env_t *env, int exception)
        {
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int, void *data);
            struct axis2_stub_StatisticsAdmin_getAvgServiceResponseTime_callback_data* callback_data = NULL;
            void *user_data = NULL;

            axis2_status_t status;
        
            callback_data = (struct axis2_stub_StatisticsAdmin_getAvgServiceResponseTime_callback_data*)axis2_callback_get_data(callback);
        
            user_data = callback_data->data;
            on_error = callback_data->on_error;
        
            status = on_error(env, exception, user_data);

            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        } 

        axis2_status_t AXIS2_CALL axis2_stub_on_complete_StatisticsAdmin_getAvgServiceResponseTime(axis2_callback_t *callback, const axutil_env_t *env)
        {
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getAvgServiceResponseTimeResponse_t* _getAvgServiceResponseTimeResponse, void *data);
            struct axis2_stub_StatisticsAdmin_getAvgServiceResponseTime_callback_data* callback_data = NULL;
            void *user_data = NULL;
            axis2_status_t status = AXIS2_SUCCESS;
 
            adb_getAvgServiceResponseTimeResponse_t* ret_val;
            

            axiom_node_t *ret_node = NULL;
            axiom_soap_envelope_t *soap_envelope = NULL;

            

            callback_data = (struct axis2_stub_StatisticsAdmin_getAvgServiceResponseTime_callback_data*)axis2_callback_get_data(callback);

            soap_envelope = axis2_callback_get_envelope(callback, env);
            if(soap_envelope)
            {
                axiom_soap_body_t *soap_body;
                soap_body = axiom_soap_envelope_get_body(soap_envelope, env);
                if(soap_body)
                {
                    axiom_node_t *body_node = axiom_soap_body_get_base_node(soap_body, env);
                    if(body_node)
                    {
                        ret_node = axiom_node_get_first_child(body_node, env);
                    }
                }
                
                
            }

            user_data = callback_data->data;
            on_complete = callback_data->on_complete;

            
                    if(ret_node != NULL)
                    {
                        ret_val = adb_getAvgServiceResponseTimeResponse_create(env);
     
                        if(adb_getAvgServiceResponseTimeResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                        {
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the LendResponse_deserialize: "
                                                                    "This should be due to an invalid XML");
                            adb_getAvgServiceResponseTimeResponse_free(ret_val, env);
                            ret_val = NULL;
                        }
                     }
                     else
                     {
                         ret_val = NULL; 
                     }

                     
                         status = on_complete(env, ret_val, user_data);
                         
 
            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        }

        /**
          * auto generated method signature for asynchronous invocations
          * for "getAvgServiceResponseTime|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub
          * @param env environment ( mandatory)
          * @param _getAvgServiceResponseTime of the adb_getAvgServiceResponseTime_t*
          * @param user_data user data to be accessed by the callbacks
          * @param on_complete callback to handle on complete
          * @param on_error callback to handle on error
          */

         void AXIS2_CALL
         axis2_stub_start_op_StatisticsAdmin_getAvgServiceResponseTime( axis2_stub_t *stub, const axutil_env_t *env,
                                              adb_getAvgServiceResponseTime_t* _getAvgServiceResponseTime,
                                                  void *user_data,
                                                  axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getAvgServiceResponseTimeResponse_t* _getAvgServiceResponseTimeResponse, void *data) ,
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) )
         {

            axis2_callback_t *callback = NULL;

            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;

            const axis2_char_t *soap_action = NULL;
            axiom_node_t *payload = NULL;

            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            
            
            struct axis2_stub_StatisticsAdmin_getAvgServiceResponseTime_callback_data *callback_data;

            callback_data = (struct axis2_stub_StatisticsAdmin_getAvgServiceResponseTime_callback_data*) AXIS2_MALLOC(env->allocator, 
                                    sizeof(struct axis2_stub_StatisticsAdmin_getAvgServiceResponseTime_callback_data));
            if(NULL == callback_data)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "Can not allocate memeory for the callback data structures");
                return;
            }
            

            
                                payload = adb_getAvgServiceResponseTime_serialize(_getAvgServiceResponseTime, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           


            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
              AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
              AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "options is null in stub");
              return;
            }

            soap_act =axis2_options_get_soap_action (options, env);
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getAvgServiceResponseTime";
              soap_act = axutil_string_create(env, "urn:getAvgServiceResponseTime");
              axis2_options_set_soap_action(options, env, soap_act);
            }
            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             

            callback = axis2_callback_create(env);
            /* Set our on_complete fucntion pointer to the callback object */
            axis2_callback_set_on_complete(callback, axis2_stub_on_complete_StatisticsAdmin_getAvgServiceResponseTime);
            /* Set our on_error function pointer to the callback object */
            axis2_callback_set_on_error(callback, axis2_stub_on_error_StatisticsAdmin_getAvgServiceResponseTime);

            callback_data-> data = user_data;
            callback_data-> on_complete = on_complete;
            callback_data-> on_error = on_error;

            axis2_callback_set_data(callback, (void*)callback_data);

            /* Send request */
            axis2_svc_client_send_receive_non_blocking(svc_client, env, payload, callback);
            
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);
              
              axis2_options_set_action(options, env, NULL);
            }
         }

         

        struct axis2_stub_StatisticsAdmin_getServiceResponseCount_callback_data
        {   
            void *data;
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getServiceResponseCountResponse_t* _getServiceResponseCountResponse, void *data);
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data);
        };

        static axis2_status_t AXIS2_CALL axis2_stub_on_error_StatisticsAdmin_getServiceResponseCount(axis2_callback_t *callback, const axutil_env_t *env, int exception)
        {
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int, void *data);
            struct axis2_stub_StatisticsAdmin_getServiceResponseCount_callback_data* callback_data = NULL;
            void *user_data = NULL;

            axis2_status_t status;
        
            callback_data = (struct axis2_stub_StatisticsAdmin_getServiceResponseCount_callback_data*)axis2_callback_get_data(callback);
        
            user_data = callback_data->data;
            on_error = callback_data->on_error;
        
            status = on_error(env, exception, user_data);

            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        } 

        axis2_status_t AXIS2_CALL axis2_stub_on_complete_StatisticsAdmin_getServiceResponseCount(axis2_callback_t *callback, const axutil_env_t *env)
        {
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getServiceResponseCountResponse_t* _getServiceResponseCountResponse, void *data);
            struct axis2_stub_StatisticsAdmin_getServiceResponseCount_callback_data* callback_data = NULL;
            void *user_data = NULL;
            axis2_status_t status = AXIS2_SUCCESS;
 
            adb_getServiceResponseCountResponse_t* ret_val;
            

            axiom_node_t *ret_node = NULL;
            axiom_soap_envelope_t *soap_envelope = NULL;

            

            callback_data = (struct axis2_stub_StatisticsAdmin_getServiceResponseCount_callback_data*)axis2_callback_get_data(callback);

            soap_envelope = axis2_callback_get_envelope(callback, env);
            if(soap_envelope)
            {
                axiom_soap_body_t *soap_body;
                soap_body = axiom_soap_envelope_get_body(soap_envelope, env);
                if(soap_body)
                {
                    axiom_node_t *body_node = axiom_soap_body_get_base_node(soap_body, env);
                    if(body_node)
                    {
                        ret_node = axiom_node_get_first_child(body_node, env);
                    }
                }
                
                
            }

            user_data = callback_data->data;
            on_complete = callback_data->on_complete;

            
                    if(ret_node != NULL)
                    {
                        ret_val = adb_getServiceResponseCountResponse_create(env);
     
                        if(adb_getServiceResponseCountResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                        {
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the LendResponse_deserialize: "
                                                                    "This should be due to an invalid XML");
                            adb_getServiceResponseCountResponse_free(ret_val, env);
                            ret_val = NULL;
                        }
                     }
                     else
                     {
                         ret_val = NULL; 
                     }

                     
                         status = on_complete(env, ret_val, user_data);
                         
 
            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        }

        /**
          * auto generated method signature for asynchronous invocations
          * for "getServiceResponseCount|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub
          * @param env environment ( mandatory)
          * @param _getServiceResponseCount of the adb_getServiceResponseCount_t*
          * @param user_data user data to be accessed by the callbacks
          * @param on_complete callback to handle on complete
          * @param on_error callback to handle on error
          */

         void AXIS2_CALL
         axis2_stub_start_op_StatisticsAdmin_getServiceResponseCount( axis2_stub_t *stub, const axutil_env_t *env,
                                              adb_getServiceResponseCount_t* _getServiceResponseCount,
                                                  void *user_data,
                                                  axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getServiceResponseCountResponse_t* _getServiceResponseCountResponse, void *data) ,
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) )
         {

            axis2_callback_t *callback = NULL;

            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;

            const axis2_char_t *soap_action = NULL;
            axiom_node_t *payload = NULL;

            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            
            
            struct axis2_stub_StatisticsAdmin_getServiceResponseCount_callback_data *callback_data;

            callback_data = (struct axis2_stub_StatisticsAdmin_getServiceResponseCount_callback_data*) AXIS2_MALLOC(env->allocator, 
                                    sizeof(struct axis2_stub_StatisticsAdmin_getServiceResponseCount_callback_data));
            if(NULL == callback_data)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "Can not allocate memeory for the callback data structures");
                return;
            }
            

            
                                payload = adb_getServiceResponseCount_serialize(_getServiceResponseCount, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           


            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
              AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
              AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "options is null in stub");
              return;
            }

            soap_act =axis2_options_get_soap_action (options, env);
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getServiceResponseCount";
              soap_act = axutil_string_create(env, "urn:getServiceResponseCount");
              axis2_options_set_soap_action(options, env, soap_act);
            }
            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             

            callback = axis2_callback_create(env);
            /* Set our on_complete fucntion pointer to the callback object */
            axis2_callback_set_on_complete(callback, axis2_stub_on_complete_StatisticsAdmin_getServiceResponseCount);
            /* Set our on_error function pointer to the callback object */
            axis2_callback_set_on_error(callback, axis2_stub_on_error_StatisticsAdmin_getServiceResponseCount);

            callback_data-> data = user_data;
            callback_data-> on_complete = on_complete;
            callback_data-> on_error = on_error;

            axis2_callback_set_data(callback, (void*)callback_data);

            /* Send request */
            axis2_svc_client_send_receive_non_blocking(svc_client, env, payload, callback);
            
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);
              
              axis2_options_set_action(options, env, NULL);
            }
         }

         

        struct axis2_stub_StatisticsAdmin_getSystemRequestCount_callback_data
        {   
            void *data;
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getSystemRequestCountResponse_t* _getSystemRequestCountResponse, void *data);
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data);
        };

        static axis2_status_t AXIS2_CALL axis2_stub_on_error_StatisticsAdmin_getSystemRequestCount(axis2_callback_t *callback, const axutil_env_t *env, int exception)
        {
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int, void *data);
            struct axis2_stub_StatisticsAdmin_getSystemRequestCount_callback_data* callback_data = NULL;
            void *user_data = NULL;

            axis2_status_t status;
        
            callback_data = (struct axis2_stub_StatisticsAdmin_getSystemRequestCount_callback_data*)axis2_callback_get_data(callback);
        
            user_data = callback_data->data;
            on_error = callback_data->on_error;
        
            status = on_error(env, exception, user_data);

            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        } 

        axis2_status_t AXIS2_CALL axis2_stub_on_complete_StatisticsAdmin_getSystemRequestCount(axis2_callback_t *callback, const axutil_env_t *env)
        {
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getSystemRequestCountResponse_t* _getSystemRequestCountResponse, void *data);
            struct axis2_stub_StatisticsAdmin_getSystemRequestCount_callback_data* callback_data = NULL;
            void *user_data = NULL;
            axis2_status_t status = AXIS2_SUCCESS;
 
            adb_getSystemRequestCountResponse_t* ret_val;
            

            axiom_node_t *ret_node = NULL;
            axiom_soap_envelope_t *soap_envelope = NULL;

            

            callback_data = (struct axis2_stub_StatisticsAdmin_getSystemRequestCount_callback_data*)axis2_callback_get_data(callback);

            soap_envelope = axis2_callback_get_envelope(callback, env);
            if(soap_envelope)
            {
                axiom_soap_body_t *soap_body;
                soap_body = axiom_soap_envelope_get_body(soap_envelope, env);
                if(soap_body)
                {
                    axiom_node_t *body_node = axiom_soap_body_get_base_node(soap_body, env);
                    if(body_node)
                    {
                        ret_node = axiom_node_get_first_child(body_node, env);
                    }
                }
                
                
            }

            user_data = callback_data->data;
            on_complete = callback_data->on_complete;

            
                    if(ret_node != NULL)
                    {
                        ret_val = adb_getSystemRequestCountResponse_create(env);
     
                        if(adb_getSystemRequestCountResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                        {
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the LendResponse_deserialize: "
                                                                    "This should be due to an invalid XML");
                            adb_getSystemRequestCountResponse_free(ret_val, env);
                            ret_val = NULL;
                        }
                     }
                     else
                     {
                         ret_val = NULL; 
                     }

                     
                         status = on_complete(env, ret_val, user_data);
                         
 
            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        }

        /**
          * auto generated method signature for asynchronous invocations
          * for "getSystemRequestCount|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub
          * @param env environment ( mandatory)
          * @param user_data user data to be accessed by the callbacks
          * @param on_complete callback to handle on complete
          * @param on_error callback to handle on error
          */

         void AXIS2_CALL
         axis2_stub_start_op_StatisticsAdmin_getSystemRequestCount( axis2_stub_t *stub, const axutil_env_t *env,
                                                  void *user_data,
                                                  axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getSystemRequestCountResponse_t* _getSystemRequestCountResponse, void *data) ,
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) )
         {

            axis2_callback_t *callback = NULL;

            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;

            const axis2_char_t *soap_action = NULL;
            axiom_node_t *payload = NULL;

            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            
            
            struct axis2_stub_StatisticsAdmin_getSystemRequestCount_callback_data *callback_data;

            callback_data = (struct axis2_stub_StatisticsAdmin_getSystemRequestCount_callback_data*) AXIS2_MALLOC(env->allocator, 
                                    sizeof(struct axis2_stub_StatisticsAdmin_getSystemRequestCount_callback_data));
            if(NULL == callback_data)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "Can not allocate memeory for the callback data structures");
                return;
            }
            

            


            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
              AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
              AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "options is null in stub");
              return;
            }

            soap_act =axis2_options_get_soap_action (options, env);
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getSystemRequestCount";
              soap_act = axutil_string_create(env, "urn:getSystemRequestCount");
              axis2_options_set_soap_action(options, env, soap_act);
            }
            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             

            callback = axis2_callback_create(env);
            /* Set our on_complete fucntion pointer to the callback object */
            axis2_callback_set_on_complete(callback, axis2_stub_on_complete_StatisticsAdmin_getSystemRequestCount);
            /* Set our on_error function pointer to the callback object */
            axis2_callback_set_on_error(callback, axis2_stub_on_error_StatisticsAdmin_getSystemRequestCount);

            callback_data-> data = user_data;
            callback_data-> on_complete = on_complete;
            callback_data-> on_error = on_error;

            axis2_callback_set_data(callback, (void*)callback_data);

            /* Send request */
            axis2_svc_client_send_receive_non_blocking(svc_client, env, payload, callback);
            
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);
              
              axis2_options_set_action(options, env, NULL);
            }
         }

         

        struct axis2_stub_StatisticsAdmin_getMinOperationResponseTime_callback_data
        {   
            void *data;
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getMinOperationResponseTimeResponse_t* _getMinOperationResponseTimeResponse, void *data);
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data);
        };

        static axis2_status_t AXIS2_CALL axis2_stub_on_error_StatisticsAdmin_getMinOperationResponseTime(axis2_callback_t *callback, const axutil_env_t *env, int exception)
        {
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int, void *data);
            struct axis2_stub_StatisticsAdmin_getMinOperationResponseTime_callback_data* callback_data = NULL;
            void *user_data = NULL;

            axis2_status_t status;
        
            callback_data = (struct axis2_stub_StatisticsAdmin_getMinOperationResponseTime_callback_data*)axis2_callback_get_data(callback);
        
            user_data = callback_data->data;
            on_error = callback_data->on_error;
        
            status = on_error(env, exception, user_data);

            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        } 

        axis2_status_t AXIS2_CALL axis2_stub_on_complete_StatisticsAdmin_getMinOperationResponseTime(axis2_callback_t *callback, const axutil_env_t *env)
        {
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getMinOperationResponseTimeResponse_t* _getMinOperationResponseTimeResponse, void *data);
            struct axis2_stub_StatisticsAdmin_getMinOperationResponseTime_callback_data* callback_data = NULL;
            void *user_data = NULL;
            axis2_status_t status = AXIS2_SUCCESS;
 
            adb_getMinOperationResponseTimeResponse_t* ret_val;
            

            axiom_node_t *ret_node = NULL;
            axiom_soap_envelope_t *soap_envelope = NULL;

            

            callback_data = (struct axis2_stub_StatisticsAdmin_getMinOperationResponseTime_callback_data*)axis2_callback_get_data(callback);

            soap_envelope = axis2_callback_get_envelope(callback, env);
            if(soap_envelope)
            {
                axiom_soap_body_t *soap_body;
                soap_body = axiom_soap_envelope_get_body(soap_envelope, env);
                if(soap_body)
                {
                    axiom_node_t *body_node = axiom_soap_body_get_base_node(soap_body, env);
                    if(body_node)
                    {
                        ret_node = axiom_node_get_first_child(body_node, env);
                    }
                }
                
                
            }

            user_data = callback_data->data;
            on_complete = callback_data->on_complete;

            
                    if(ret_node != NULL)
                    {
                        ret_val = adb_getMinOperationResponseTimeResponse_create(env);
     
                        if(adb_getMinOperationResponseTimeResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                        {
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the LendResponse_deserialize: "
                                                                    "This should be due to an invalid XML");
                            adb_getMinOperationResponseTimeResponse_free(ret_val, env);
                            ret_val = NULL;
                        }
                     }
                     else
                     {
                         ret_val = NULL; 
                     }

                     
                         status = on_complete(env, ret_val, user_data);
                         
 
            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        }

        /**
          * auto generated method signature for asynchronous invocations
          * for "getMinOperationResponseTime|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub
          * @param env environment ( mandatory)
          * @param _getMinOperationResponseTime of the adb_getMinOperationResponseTime_t*
          * @param user_data user data to be accessed by the callbacks
          * @param on_complete callback to handle on complete
          * @param on_error callback to handle on error
          */

         void AXIS2_CALL
         axis2_stub_start_op_StatisticsAdmin_getMinOperationResponseTime( axis2_stub_t *stub, const axutil_env_t *env,
                                              adb_getMinOperationResponseTime_t* _getMinOperationResponseTime,
                                                  void *user_data,
                                                  axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getMinOperationResponseTimeResponse_t* _getMinOperationResponseTimeResponse, void *data) ,
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) )
         {

            axis2_callback_t *callback = NULL;

            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;

            const axis2_char_t *soap_action = NULL;
            axiom_node_t *payload = NULL;

            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            
            
            struct axis2_stub_StatisticsAdmin_getMinOperationResponseTime_callback_data *callback_data;

            callback_data = (struct axis2_stub_StatisticsAdmin_getMinOperationResponseTime_callback_data*) AXIS2_MALLOC(env->allocator, 
                                    sizeof(struct axis2_stub_StatisticsAdmin_getMinOperationResponseTime_callback_data));
            if(NULL == callback_data)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "Can not allocate memeory for the callback data structures");
                return;
            }
            

            
                                payload = adb_getMinOperationResponseTime_serialize(_getMinOperationResponseTime, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           


            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
              AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
              AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "options is null in stub");
              return;
            }

            soap_act =axis2_options_get_soap_action (options, env);
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getMinOperationResponseTime";
              soap_act = axutil_string_create(env, "urn:getMinOperationResponseTime");
              axis2_options_set_soap_action(options, env, soap_act);
            }
            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             

            callback = axis2_callback_create(env);
            /* Set our on_complete fucntion pointer to the callback object */
            axis2_callback_set_on_complete(callback, axis2_stub_on_complete_StatisticsAdmin_getMinOperationResponseTime);
            /* Set our on_error function pointer to the callback object */
            axis2_callback_set_on_error(callback, axis2_stub_on_error_StatisticsAdmin_getMinOperationResponseTime);

            callback_data-> data = user_data;
            callback_data-> on_complete = on_complete;
            callback_data-> on_error = on_error;

            axis2_callback_set_data(callback, (void*)callback_data);

            /* Send request */
            axis2_svc_client_send_receive_non_blocking(svc_client, env, payload, callback);
            
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);
              
              axis2_options_set_action(options, env, NULL);
            }
         }

         

        struct axis2_stub_StatisticsAdmin_getAvgSystemResponseTime_callback_data
        {   
            void *data;
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getAvgSystemResponseTimeResponse_t* _getAvgSystemResponseTimeResponse, void *data);
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data);
        };

        static axis2_status_t AXIS2_CALL axis2_stub_on_error_StatisticsAdmin_getAvgSystemResponseTime(axis2_callback_t *callback, const axutil_env_t *env, int exception)
        {
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int, void *data);
            struct axis2_stub_StatisticsAdmin_getAvgSystemResponseTime_callback_data* callback_data = NULL;
            void *user_data = NULL;

            axis2_status_t status;
        
            callback_data = (struct axis2_stub_StatisticsAdmin_getAvgSystemResponseTime_callback_data*)axis2_callback_get_data(callback);
        
            user_data = callback_data->data;
            on_error = callback_data->on_error;
        
            status = on_error(env, exception, user_data);

            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        } 

        axis2_status_t AXIS2_CALL axis2_stub_on_complete_StatisticsAdmin_getAvgSystemResponseTime(axis2_callback_t *callback, const axutil_env_t *env)
        {
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getAvgSystemResponseTimeResponse_t* _getAvgSystemResponseTimeResponse, void *data);
            struct axis2_stub_StatisticsAdmin_getAvgSystemResponseTime_callback_data* callback_data = NULL;
            void *user_data = NULL;
            axis2_status_t status = AXIS2_SUCCESS;
 
            adb_getAvgSystemResponseTimeResponse_t* ret_val;
            

            axiom_node_t *ret_node = NULL;
            axiom_soap_envelope_t *soap_envelope = NULL;

            

            callback_data = (struct axis2_stub_StatisticsAdmin_getAvgSystemResponseTime_callback_data*)axis2_callback_get_data(callback);

            soap_envelope = axis2_callback_get_envelope(callback, env);
            if(soap_envelope)
            {
                axiom_soap_body_t *soap_body;
                soap_body = axiom_soap_envelope_get_body(soap_envelope, env);
                if(soap_body)
                {
                    axiom_node_t *body_node = axiom_soap_body_get_base_node(soap_body, env);
                    if(body_node)
                    {
                        ret_node = axiom_node_get_first_child(body_node, env);
                    }
                }
                
                
            }

            user_data = callback_data->data;
            on_complete = callback_data->on_complete;

            
                    if(ret_node != NULL)
                    {
                        ret_val = adb_getAvgSystemResponseTimeResponse_create(env);
     
                        if(adb_getAvgSystemResponseTimeResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                        {
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the LendResponse_deserialize: "
                                                                    "This should be due to an invalid XML");
                            adb_getAvgSystemResponseTimeResponse_free(ret_val, env);
                            ret_val = NULL;
                        }
                     }
                     else
                     {
                         ret_val = NULL; 
                     }

                     
                         status = on_complete(env, ret_val, user_data);
                         
 
            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        }

        /**
          * auto generated method signature for asynchronous invocations
          * for "getAvgSystemResponseTime|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub
          * @param env environment ( mandatory)
          * @param user_data user data to be accessed by the callbacks
          * @param on_complete callback to handle on complete
          * @param on_error callback to handle on error
          */

         void AXIS2_CALL
         axis2_stub_start_op_StatisticsAdmin_getAvgSystemResponseTime( axis2_stub_t *stub, const axutil_env_t *env,
                                                  void *user_data,
                                                  axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getAvgSystemResponseTimeResponse_t* _getAvgSystemResponseTimeResponse, void *data) ,
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) )
         {

            axis2_callback_t *callback = NULL;

            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;

            const axis2_char_t *soap_action = NULL;
            axiom_node_t *payload = NULL;

            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            
            
            struct axis2_stub_StatisticsAdmin_getAvgSystemResponseTime_callback_data *callback_data;

            callback_data = (struct axis2_stub_StatisticsAdmin_getAvgSystemResponseTime_callback_data*) AXIS2_MALLOC(env->allocator, 
                                    sizeof(struct axis2_stub_StatisticsAdmin_getAvgSystemResponseTime_callback_data));
            if(NULL == callback_data)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "Can not allocate memeory for the callback data structures");
                return;
            }
            

            


            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
              AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
              AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "options is null in stub");
              return;
            }

            soap_act =axis2_options_get_soap_action (options, env);
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getAvgSystemResponseTime";
              soap_act = axutil_string_create(env, "urn:getAvgSystemResponseTime");
              axis2_options_set_soap_action(options, env, soap_act);
            }
            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             

            callback = axis2_callback_create(env);
            /* Set our on_complete fucntion pointer to the callback object */
            axis2_callback_set_on_complete(callback, axis2_stub_on_complete_StatisticsAdmin_getAvgSystemResponseTime);
            /* Set our on_error function pointer to the callback object */
            axis2_callback_set_on_error(callback, axis2_stub_on_error_StatisticsAdmin_getAvgSystemResponseTime);

            callback_data-> data = user_data;
            callback_data-> on_complete = on_complete;
            callback_data-> on_error = on_error;

            axis2_callback_set_data(callback, (void*)callback_data);

            /* Send request */
            axis2_svc_client_send_receive_non_blocking(svc_client, env, payload, callback);
            
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);
              
              axis2_options_set_action(options, env, NULL);
            }
         }

         

        struct axis2_stub_StatisticsAdmin_getSystemStatistics_callback_data
        {   
            void *data;
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getSystemStatisticsResponse_t* _getSystemStatisticsResponse, void *data);
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data);
        };

        static axis2_status_t AXIS2_CALL axis2_stub_on_error_StatisticsAdmin_getSystemStatistics(axis2_callback_t *callback, const axutil_env_t *env, int exception)
        {
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int, void *data);
            struct axis2_stub_StatisticsAdmin_getSystemStatistics_callback_data* callback_data = NULL;
            void *user_data = NULL;

            axis2_status_t status;
        
            callback_data = (struct axis2_stub_StatisticsAdmin_getSystemStatistics_callback_data*)axis2_callback_get_data(callback);
        
            user_data = callback_data->data;
            on_error = callback_data->on_error;
        
            status = on_error(env, exception, user_data);

            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        } 

        axis2_status_t AXIS2_CALL axis2_stub_on_complete_StatisticsAdmin_getSystemStatistics(axis2_callback_t *callback, const axutil_env_t *env)
        {
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getSystemStatisticsResponse_t* _getSystemStatisticsResponse, void *data);
            struct axis2_stub_StatisticsAdmin_getSystemStatistics_callback_data* callback_data = NULL;
            void *user_data = NULL;
            axis2_status_t status = AXIS2_SUCCESS;
 
            adb_getSystemStatisticsResponse_t* ret_val;
            

            axiom_node_t *ret_node = NULL;
            axiom_soap_envelope_t *soap_envelope = NULL;

            

            callback_data = (struct axis2_stub_StatisticsAdmin_getSystemStatistics_callback_data*)axis2_callback_get_data(callback);

            soap_envelope = axis2_callback_get_envelope(callback, env);
            if(soap_envelope)
            {
                axiom_soap_body_t *soap_body;
                soap_body = axiom_soap_envelope_get_body(soap_envelope, env);
                if(soap_body)
                {
                    axiom_node_t *body_node = axiom_soap_body_get_base_node(soap_body, env);
                    if(body_node)
                    {
                        ret_node = axiom_node_get_first_child(body_node, env);
                    }
                }
                
                
            }

            user_data = callback_data->data;
            on_complete = callback_data->on_complete;

            
                    if(ret_node != NULL)
                    {
                        ret_val = adb_getSystemStatisticsResponse_create(env);
     
                        if(adb_getSystemStatisticsResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                        {
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the LendResponse_deserialize: "
                                                                    "This should be due to an invalid XML");
                            adb_getSystemStatisticsResponse_free(ret_val, env);
                            ret_val = NULL;
                        }
                     }
                     else
                     {
                         ret_val = NULL; 
                     }

                     
                         status = on_complete(env, ret_val, user_data);
                         
 
            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        }

        /**
          * auto generated method signature for asynchronous invocations
          * for "getSystemStatistics|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub
          * @param env environment ( mandatory)
          * @param user_data user data to be accessed by the callbacks
          * @param on_complete callback to handle on complete
          * @param on_error callback to handle on error
          */

         void AXIS2_CALL
         axis2_stub_start_op_StatisticsAdmin_getSystemStatistics( axis2_stub_t *stub, const axutil_env_t *env,
                                                  void *user_data,
                                                  axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getSystemStatisticsResponse_t* _getSystemStatisticsResponse, void *data) ,
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) )
         {

            axis2_callback_t *callback = NULL;

            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;

            const axis2_char_t *soap_action = NULL;
            axiom_node_t *payload = NULL;

            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            
            
            struct axis2_stub_StatisticsAdmin_getSystemStatistics_callback_data *callback_data;

            callback_data = (struct axis2_stub_StatisticsAdmin_getSystemStatistics_callback_data*) AXIS2_MALLOC(env->allocator, 
                                    sizeof(struct axis2_stub_StatisticsAdmin_getSystemStatistics_callback_data));
            if(NULL == callback_data)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "Can not allocate memeory for the callback data structures");
                return;
            }
            

            


            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
              AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
              AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "options is null in stub");
              return;
            }

            soap_act =axis2_options_get_soap_action (options, env);
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getSystemStatistics";
              soap_act = axutil_string_create(env, "urn:getSystemStatistics");
              axis2_options_set_soap_action(options, env, soap_act);
            }
            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             

            callback = axis2_callback_create(env);
            /* Set our on_complete fucntion pointer to the callback object */
            axis2_callback_set_on_complete(callback, axis2_stub_on_complete_StatisticsAdmin_getSystemStatistics);
            /* Set our on_error function pointer to the callback object */
            axis2_callback_set_on_error(callback, axis2_stub_on_error_StatisticsAdmin_getSystemStatistics);

            callback_data-> data = user_data;
            callback_data-> on_complete = on_complete;
            callback_data-> on_error = on_error;

            axis2_callback_set_data(callback, (void*)callback_data);

            /* Send request */
            axis2_svc_client_send_receive_non_blocking(svc_client, env, payload, callback);
            
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);
              
              axis2_options_set_action(options, env, NULL);
            }
         }

         

        struct axis2_stub_StatisticsAdmin_getOperationRequestCount_callback_data
        {   
            void *data;
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getOperationRequestCountResponse_t* _getOperationRequestCountResponse, void *data);
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data);
        };

        static axis2_status_t AXIS2_CALL axis2_stub_on_error_StatisticsAdmin_getOperationRequestCount(axis2_callback_t *callback, const axutil_env_t *env, int exception)
        {
            axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int, void *data);
            struct axis2_stub_StatisticsAdmin_getOperationRequestCount_callback_data* callback_data = NULL;
            void *user_data = NULL;

            axis2_status_t status;
        
            callback_data = (struct axis2_stub_StatisticsAdmin_getOperationRequestCount_callback_data*)axis2_callback_get_data(callback);
        
            user_data = callback_data->data;
            on_error = callback_data->on_error;
        
            status = on_error(env, exception, user_data);

            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        } 

        axis2_status_t AXIS2_CALL axis2_stub_on_complete_StatisticsAdmin_getOperationRequestCount(axis2_callback_t *callback, const axutil_env_t *env)
        {
            axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getOperationRequestCountResponse_t* _getOperationRequestCountResponse, void *data);
            struct axis2_stub_StatisticsAdmin_getOperationRequestCount_callback_data* callback_data = NULL;
            void *user_data = NULL;
            axis2_status_t status = AXIS2_SUCCESS;
 
            adb_getOperationRequestCountResponse_t* ret_val;
            

            axiom_node_t *ret_node = NULL;
            axiom_soap_envelope_t *soap_envelope = NULL;

            

            callback_data = (struct axis2_stub_StatisticsAdmin_getOperationRequestCount_callback_data*)axis2_callback_get_data(callback);

            soap_envelope = axis2_callback_get_envelope(callback, env);
            if(soap_envelope)
            {
                axiom_soap_body_t *soap_body;
                soap_body = axiom_soap_envelope_get_body(soap_envelope, env);
                if(soap_body)
                {
                    axiom_node_t *body_node = axiom_soap_body_get_base_node(soap_body, env);
                    if(body_node)
                    {
                        ret_node = axiom_node_get_first_child(body_node, env);
                    }
                }
                
                
            }

            user_data = callback_data->data;
            on_complete = callback_data->on_complete;

            
                    if(ret_node != NULL)
                    {
                        ret_val = adb_getOperationRequestCountResponse_create(env);
     
                        if(adb_getOperationRequestCountResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                        {
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the LendResponse_deserialize: "
                                                                    "This should be due to an invalid XML");
                            adb_getOperationRequestCountResponse_free(ret_val, env);
                            ret_val = NULL;
                        }
                     }
                     else
                     {
                         ret_val = NULL; 
                     }

                     
                         status = on_complete(env, ret_val, user_data);
                         
 
            if(callback_data)
            {
                AXIS2_FREE(env->allocator, callback_data);
            }
            return status;
        }

        /**
          * auto generated method signature for asynchronous invocations
          * for "getOperationRequestCount|http://services.statistics.carbon.wso2.org" operation.
          * @param stub The stub
          * @param env environment ( mandatory)
          * @param _getOperationRequestCount of the adb_getOperationRequestCount_t*
          * @param user_data user data to be accessed by the callbacks
          * @param on_complete callback to handle on complete
          * @param on_error callback to handle on error
          */

         void AXIS2_CALL
         axis2_stub_start_op_StatisticsAdmin_getOperationRequestCount( axis2_stub_t *stub, const axutil_env_t *env,
                                              adb_getOperationRequestCount_t* _getOperationRequestCount,
                                                  void *user_data,
                                                  axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_getOperationRequestCountResponse_t* _getOperationRequestCountResponse, void *data) ,
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) )
         {

            axis2_callback_t *callback = NULL;

            axis2_svc_client_t *svc_client = NULL;
            axis2_options_t *options = NULL;

            const axis2_char_t *soap_action = NULL;
            axiom_node_t *payload = NULL;

            axis2_bool_t is_soap_act_set = AXIS2_TRUE;
            axutil_string_t *soap_act = NULL;

            
            
            struct axis2_stub_StatisticsAdmin_getOperationRequestCount_callback_data *callback_data;

            callback_data = (struct axis2_stub_StatisticsAdmin_getOperationRequestCount_callback_data*) AXIS2_MALLOC(env->allocator, 
                                    sizeof(struct axis2_stub_StatisticsAdmin_getOperationRequestCount_callback_data));
            if(NULL == callback_data)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "Can not allocate memeory for the callback data structures");
                return;
            }
            

            
                                payload = adb_getOperationRequestCount_serialize(_getOperationRequestCount, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                           


            svc_client = axis2_stub_get_svc_client(stub, env );
            
           
            
            

            options = axis2_stub_get_options( stub, env);
            if (NULL == options)
            {
              AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
              AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "options is null in stub");
              return;
            }

            soap_act =axis2_options_get_soap_action (options, env);
            if (NULL == soap_act)
            {
              is_soap_act_set = AXIS2_FALSE;
              soap_action = "urn:getOperationRequestCount";
              soap_act = axutil_string_create(env, "urn:getOperationRequestCount");
              axis2_options_set_soap_action(options, env, soap_act);
            }
            
            axis2_options_set_soap_version(options, env, AXIOM_SOAP12);
             

            callback = axis2_callback_create(env);
            /* Set our on_complete fucntion pointer to the callback object */
            axis2_callback_set_on_complete(callback, axis2_stub_on_complete_StatisticsAdmin_getOperationRequestCount);
            /* Set our on_error function pointer to the callback object */
            axis2_callback_set_on_error(callback, axis2_stub_on_error_StatisticsAdmin_getOperationRequestCount);

            callback_data-> data = user_data;
            callback_data-> on_complete = on_complete;
            callback_data-> on_error = on_error;

            axis2_callback_set_data(callback, (void*)callback_data);

            /* Send request */
            axis2_svc_client_send_receive_non_blocking(svc_client, env, payload, callback);
            
            if (!is_soap_act_set)
            {
              
              axis2_options_set_soap_action(options, env, NULL);
              
              axis2_options_set_action(options, env, NULL);
            }
         }

         

