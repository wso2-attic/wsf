

        /**
        * axis2_stub_ExchangeTrader.h
        *
        * This file was auto-generated from WSDL for "ExchangeTrader|http://www.wso2.org" service
        * by the Apache Axis2/C version: #axisVersion# #today#
        */

        #include <stdio.h>
        #include <axiom.h>
        #include <axutil_utils.h>
        #include <axiom_soap.h>
        #include <axis2_client.h>
        #include <axis2_stub.h>

       
         #include "axis2_buyRequest_ex.h"
        
         #include "axis2_loginRequest.h"
        
         #include "axis2_registerClientResponse.h"
        
         #include "axis2_registerClientRequest.h"
        
         #include "axis2_registerFeedTargetRequest.h"
        
         #include "axis2_sellRequest_ex.h"
        
        /* function prototypes - for header file*/
        /**
         * axis2_stub_ExchangeTrader_create
         * create and return the stub with services populated
         * params - env : environment ( mandatory)
         *        - client_home : Axis2/C home ( mandatory )
         *        - endpoint_uri : service endpoint uri( optional ) - if NULL default picked from wsdl used
         */
        axis2_stub_t*
        axis2_stub_ExchangeTrader_create (const axutil_env_t *env,
                                        axis2_char_t *client_home,
                                        axis2_char_t *endpoint_uri);
        /**
         * axis2_stub_ExchangeTrader_populate_services
         * populate the svc in stub with the service and operations
         */
        void axis2_stub_ExchangeTrader_populate_services( axis2_stub_t *stub, const axutil_env_t *env);
        /**
         * axis2_stub_ExchangeTrader_get_endpoint_uri_from_wsdl
         * return the endpoint URI picked from wsdl
         */
        axis2_char_t *axis2_stub_ExchangeTrader_get_endpoint_uri_from_wsdl ( const axutil_env_t *env );

        
        /**
         * auto generated function declaration
         * for "buy|http://www.wso2.org" operation.
         
         * @param buyRequest_ex12
         */

        axis2_status_t axis2_stub_ExchangeTrader_buy( axis2_stub_t *stub, const axutil_env_t *env,
                                                    axis2_buyRequest_ex_t* buyRequest_ex12);
        
        /**
         * auto generated function declaration
         * for "login|http://www.wso2.org" operation.
         
         * @param loginRequest13
         */

        axis2_status_t axis2_stub_ExchangeTrader_login( axis2_stub_t *stub, const axutil_env_t *env,
                                                    axis2_loginRequest_t* loginRequest13);
        
        /**
         * auto generated function declaration
         * for "registerClient|http://www.wso2.org" operation.
         
         * @param registerClientRequest14
         */

        axis2_registerClientResponse_t* axis2_stub_ExchangeTrader_registerClient( axis2_stub_t *stub, const axutil_env_t *env,
                                                    axis2_registerClientRequest_t* registerClientRequest14);
        
        /**
         * auto generated function declaration
         * for "registerFeedTarget|http://www.wso2.org" operation.
         
         * @param registerFeedTargetRequest16
         */

        axis2_status_t axis2_stub_ExchangeTrader_registerFeedTarget( axis2_stub_t *stub, const axutil_env_t *env,
                                                    axis2_registerFeedTargetRequest_t* registerFeedTargetRequest16);
        
        /**
         * auto generated function declaration
         * for "sell|http://www.wso2.org" operation.
         
         * @param sellRequest_ex17
         */

        axis2_status_t axis2_stub_ExchangeTrader_sell( axis2_stub_t *stub, const axutil_env_t *env,
                                                    axis2_sellRequest_ex_t* sellRequest_ex17);
        
        /**
         * auto generated function declaration
         * for "buy|http://www.wso2.org" operation.
         
         * @param buyRequest_ex12
         * @param on_complete callback to handle on complete
         * @param on_error callback to handle on error
         */

        
        /**
         * auto generated function declaration
         * for "login|http://www.wso2.org" operation.
         
         * @param loginRequest13
         * @param on_complete callback to handle on complete
         * @param on_error callback to handle on error
         */

        
        /**
         * auto generated function declaration
         * for "registerClient|http://www.wso2.org" operation.
         
         * @param registerClientRequest14
         * @param on_complete callback to handle on complete
         * @param on_error callback to handle on error
         */

        
        void axis2_stub_ExchangeTrader_registerClient_start( axis2_stub_t *stub, const axutil_env_t *env,
                                                        axis2_registerClientRequest_t* registerClientRequest14,
                                                        axis2_status_t ( AXIS2_CALL *on_complete ) (struct axis2_callback *, const axutil_env_t* ) ,
                                                        axis2_status_t ( AXIS2_CALL *on_error ) (struct axis2_callback *, const axutil_env_t*, int ) );

        
        /**
         * auto generated function declaration
         * for "registerFeedTarget|http://www.wso2.org" operation.
         
         * @param registerFeedTargetRequest16
         * @param on_complete callback to handle on complete
         * @param on_error callback to handle on error
         */

        
        /**
         * auto generated function declaration
         * for "sell|http://www.wso2.org" operation.
         
         * @param sellRequest_ex17
         * @param on_complete callback to handle on complete
         * @param on_error callback to handle on error
         */

        

