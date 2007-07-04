

        /**
        * axis2_stub_TraderClient.h
        *
        * This file was auto-generated from WSDL for "TraderClient|http://www.wso2.org" service
        * by the Apache Axis2/C version: #axisVersion# #today#
        */

        #include <stdio.h>
        #include <axiom.h>
        #include <axutil_utils.h>
        #include <axiom_soap.h>
        #include <axis2_client.h>
        #include <axis2_stub.h>

       
         #include <axis2_buyResponse.h>
         #include <axis2_buyRequest.h>
         #include <axis2_getPortfolioResponse.h>
         #include <axis2_getPortfolioRequest.h>
         #include <axis2_depositResponse.h>
         #include <axis2_depositRequest.h>
         #include <axis2_getSymbolsResponse.h>
         #include <axis2_getSymbolsRequest.h>
         #include <axis2_getQuoteResponse.h>
         #include <axis2_getQuoteRequest.h>
         #include <axis2_createAccountResponse.h>
         #include <axis2_createAccountRequest.h>
         #include <axis2_sellResponse.h>
         #include <axis2_sellRequest.h>
        
        /* function prototypes - for header file*/
        /**
         * axis2_stub_TraderClient_create
         * create and return the stub with services populated
         * params - env : environment ( mandatory)
         *        - client_home : Axis2/C home ( mandatory )
         *        - endpoint_uri : service endpoint uri( optional ) - if NULL default picked from wsdl used
         */
        axis2_stub_t*
        axis2_stub_TraderClient_create (const axutil_env_t *env,
                                        axis2_char_t *client_home,
                                        axis2_char_t *endpoint_uri);
        /**
         * axis2_stub_TraderClient_populate_services
         * populate the svc in stub with the service and operations
         */
        void axis2_stub_TraderClient_populate_services( axis2_stub_t *stub, const axutil_env_t *env);
        /**
         * axis2_stub_TraderClient_get_endpoint_uri_from_wsdl
         * return the endpoint URI picked from wsdl
         */
        axis2_char_t *axis2_stub_TraderClient_get_endpoint_uri_from_wsdl ( const axutil_env_t *env );

        
        /**
         * auto generated function declaration
         * for "buy|http://www.wso2.org" operation.
         
         * @param buyRequest28
         */

        axis2_buyResponse_t* axis2_stub_TraderClient_buy( axis2_stub_t *stub, const axutil_env_t *env,
                                                    axis2_buyRequest_t* buyRequest28);
        
        /**
         * auto generated function declaration
         * for "getPortfolio|http://www.wso2.org" operation.
         
         * @param getPortfolioRequest30
         */

        axis2_getPortfolioResponse_t* axis2_stub_TraderClient_getPortfolio( axis2_stub_t *stub, const axutil_env_t *env,
                                                    axis2_getPortfolioRequest_t* getPortfolioRequest30);
        
        /**
         * auto generated function declaration
         * for "deposit|http://www.wso2.org" operation.
         
         * @param depositRequest32
         */

        axis2_depositResponse_t* axis2_stub_TraderClient_deposit( axis2_stub_t *stub, const axutil_env_t *env,
                                                    axis2_depositRequest_t* depositRequest32);
        
        /**
         * auto generated function declaration
         * for "getSymbols|http://www.wso2.org" operation.
         
         * @param getSymbolsRequest34
         */

        axis2_getSymbolsResponse_t* axis2_stub_TraderClient_getSymbols( axis2_stub_t *stub, const axutil_env_t *env,
                                                    axis2_getSymbolsRequest_t* getSymbolsRequest34);
        
        /**
         * auto generated function declaration
         * for "getQuote|http://www.wso2.org" operation.
         
         * @param getQuoteRequest36
         */

        axis2_getQuoteResponse_t* axis2_stub_TraderClient_getQuote( axis2_stub_t *stub, const axutil_env_t *env,
                                                    axis2_getQuoteRequest_t* getQuoteRequest36);
        
        /**
         * auto generated function declaration
         * for "createAccount|http://www.wso2.org" operation.
         
         * @param createAccountRequest38
         */

        axis2_createAccountResponse_t* axis2_stub_TraderClient_createAccount( axis2_stub_t *stub, const axutil_env_t *env,
                                                    axis2_createAccountRequest_t* createAccountRequest38);
        
        /**
         * auto generated function declaration
         * for "sell|http://www.wso2.org" operation.
         
         * @param sellRequest40
         */

        axis2_sellResponse_t* axis2_stub_TraderClient_sell( axis2_stub_t *stub, const axutil_env_t *env,
                                                    axis2_sellRequest_t* sellRequest40);
        
        /**
         * auto generated function declaration
         * for "buy|http://www.wso2.org" operation.
         
         * @param buyRequest28
         * @param on_complete callback to handle on complete
         * @param on_error callback to handle on error
         */

        
        void axis2_stub_TraderClient_buy_start( axis2_stub_t *stub, const axutil_env_t *env,
                                                        axis2_buyRequest_t* buyRequest28,
                                                        axis2_status_t ( AXIS2_CALL *on_complete ) (struct axis2_callback *, const axutil_env_t* ) ,
                                                        axis2_status_t ( AXIS2_CALL *on_error ) (struct axis2_callback *, const axutil_env_t*, int ) );

        
        /**
         * auto generated function declaration
         * for "getPortfolio|http://www.wso2.org" operation.
         
         * @param getPortfolioRequest30
         * @param on_complete callback to handle on complete
         * @param on_error callback to handle on error
         */

        
        void axis2_stub_TraderClient_getPortfolio_start( axis2_stub_t *stub, const axutil_env_t *env,
                                                        axis2_getPortfolioRequest_t* getPortfolioRequest30,
                                                        axis2_status_t ( AXIS2_CALL *on_complete ) (struct axis2_callback *, const axutil_env_t* ) ,
                                                        axis2_status_t ( AXIS2_CALL *on_error ) (struct axis2_callback *, const axutil_env_t*, int ) );

        
        /**
         * auto generated function declaration
         * for "deposit|http://www.wso2.org" operation.
         
         * @param depositRequest32
         * @param on_complete callback to handle on complete
         * @param on_error callback to handle on error
         */

        
        void axis2_stub_TraderClient_deposit_start( axis2_stub_t *stub, const axutil_env_t *env,
                                                        axis2_depositRequest_t* depositRequest32,
                                                        axis2_status_t ( AXIS2_CALL *on_complete ) (struct axis2_callback *, const axutil_env_t* ) ,
                                                        axis2_status_t ( AXIS2_CALL *on_error ) (struct axis2_callback *, const axutil_env_t*, int ) );

        
        /**
         * auto generated function declaration
         * for "getSymbols|http://www.wso2.org" operation.
         
         * @param getSymbolsRequest34
         * @param on_complete callback to handle on complete
         * @param on_error callback to handle on error
         */

        
        void axis2_stub_TraderClient_getSymbols_start( axis2_stub_t *stub, const axutil_env_t *env,
                                                        axis2_getSymbolsRequest_t* getSymbolsRequest34,
                                                        axis2_status_t ( AXIS2_CALL *on_complete ) (struct axis2_callback *, const axutil_env_t* ) ,
                                                        axis2_status_t ( AXIS2_CALL *on_error ) (struct axis2_callback *, const axutil_env_t*, int ) );

        
        /**
         * auto generated function declaration
         * for "getQuote|http://www.wso2.org" operation.
         
         * @param getQuoteRequest36
         * @param on_complete callback to handle on complete
         * @param on_error callback to handle on error
         */

        
        void axis2_stub_TraderClient_getQuote_start( axis2_stub_t *stub, const axutil_env_t *env,
                                                        axis2_getQuoteRequest_t* getQuoteRequest36,
                                                        axis2_status_t ( AXIS2_CALL *on_complete ) (struct axis2_callback *, const axutil_env_t* ) ,
                                                        axis2_status_t ( AXIS2_CALL *on_error ) (struct axis2_callback *, const axutil_env_t*, int ) );

        
        /**
         * auto generated function declaration
         * for "createAccount|http://www.wso2.org" operation.
         
         * @param createAccountRequest38
         * @param on_complete callback to handle on complete
         * @param on_error callback to handle on error
         */

        
        void axis2_stub_TraderClient_createAccount_start( axis2_stub_t *stub, const axutil_env_t *env,
                                                        axis2_createAccountRequest_t* createAccountRequest38,
                                                        axis2_status_t ( AXIS2_CALL *on_complete ) (struct axis2_callback *, const axutil_env_t* ) ,
                                                        axis2_status_t ( AXIS2_CALL *on_error ) (struct axis2_callback *, const axutil_env_t*, int ) );

        
        /**
         * auto generated function declaration
         * for "sell|http://www.wso2.org" operation.
         
         * @param sellRequest40
         * @param on_complete callback to handle on complete
         * @param on_error callback to handle on error
         */

        
        void axis2_stub_TraderClient_sell_start( axis2_stub_t *stub, const axutil_env_t *env,
                                                        axis2_sellRequest_t* sellRequest40,
                                                        axis2_status_t ( AXIS2_CALL *on_complete ) (struct axis2_callback *, const axutil_env_t* ) ,
                                                        axis2_status_t ( AXIS2_CALL *on_error ) (struct axis2_callback *, const axutil_env_t*, int ) );

        

