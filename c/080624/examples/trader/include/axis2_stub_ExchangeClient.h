

        /**
        * axis2_stub_ExchangeClient.h
        *
        * This file was auto-generated from WSDL for "ExchangeClient|http://www.wso2.org" service
        * by the Apache Axis2/C version: #axisVersion# #today#
        */

        #include <stdio.h>
        #include <axiom.h>
        #include <axutil_utils.h>
        #include <axiom_soap.h>
        #include <axis2_client.h>
        #include <axis2_stub.h>

       
         #include "axis2_getInfoResponse.h"
        
         #include "axis2_getInfoRequest.h"
        
        /* function prototypes - for header file*/
        /**
         * axis2_stub_ExchangeClient_create
         * create and return the stub with services populated
         * params - env : environment ( mandatory)
         *        - client_home : Axis2/C home ( mandatory )
         *        - endpoint_uri : service endpoint uri( optional ) - if NULL default picked from wsdl used
         */
        axis2_stub_t*
        axis2_stub_ExchangeClient_create (const axutil_env_t *env,
                                        axis2_char_t *client_home,
                                        axis2_char_t *endpoint_uri);
        /**
         * axis2_stub_ExchangeClient_populate_services
         * populate the svc in stub with the service and operations
         */
        void axis2_stub_ExchangeClient_populate_services( axis2_stub_t *stub, const axutil_env_t *env);
        /**
         * axis2_stub_ExchangeClient_get_endpoint_uri_from_wsdl
         * return the endpoint URI picked from wsdl
         */
        axis2_char_t *axis2_stub_ExchangeClient_get_endpoint_uri_from_wsdl ( const axutil_env_t *env );

        
        /**
         * auto generated function declaration
         * for "getInfo|http://www.wso2.org" operation.
         
         * @param getInfoRequest4
         */

        axis2_getInfoResponse_t* axis2_stub_ExchangeClient_getInfo( axis2_stub_t *stub, const axutil_env_t *env,
                                                    axis2_getInfoRequest_t* getInfoRequest4);
        
        /**
         * auto generated function declaration
         * for "getInfo|http://www.wso2.org" operation.
         
         * @param getInfoRequest4
         * @param on_complete callback to handle on complete
         * @param on_error callback to handle on error
         */

        
        void axis2_stub_ExchangeClient_getInfo_start( axis2_stub_t *stub, const axutil_env_t *env,
                                                        axis2_getInfoRequest_t* getInfoRequest4,
                                                        axis2_status_t ( AXIS2_CALL *on_complete ) (struct axis2_callback *, const axutil_env_t* ) ,
                                                        axis2_status_t ( AXIS2_CALL *on_error ) (struct axis2_callback *, const axutil_env_t*, int ) );

        

