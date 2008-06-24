

        /**
        * axis2_stub_TraderExchange.h
        *
        * This file was auto-generated from WSDL for "TraderExchange|http://www.wso2.org" service
        * by the Apache Axis2/C version: #axisVersion# #today#
        */

        #include <stdio.h>
        #include <axiom.h>
        #include <axutil_utils.h>
        #include <axiom_soap.h>
        #include <axis2_client.h>
        #include <axis2_stub.h>

       
         #include "axis2_updateRequest.h"
        
        /* function prototypes - for header file*/
        /**
         * axis2_stub_TraderExchange_create
         * create and return the stub with services populated
         * params - env : environment ( mandatory)
         *        - client_home : Axis2/C home ( mandatory )
         *        - endpoint_uri : service endpoint uri( optional ) - if NULL default picked from wsdl used
         */
        axis2_stub_t*
        axis2_stub_TraderExchange_create (const axutil_env_t *env,
                                        axis2_char_t *client_home,
                                        axis2_char_t *endpoint_uri);
        /**
         * axis2_stub_TraderExchange_populate_services
         * populate the svc in stub with the service and operations
         */
        void axis2_stub_TraderExchange_populate_services( axis2_stub_t *stub, const axutil_env_t *env);
        /**
         * axis2_stub_TraderExchange_get_endpoint_uri_from_wsdl
         * return the endpoint URI picked from wsdl
         */
        axis2_char_t *axis2_stub_TraderExchange_get_endpoint_uri_from_wsdl ( const axutil_env_t *env );

        
        /**
         * auto generated function declaration
         * for "update|http://www.wso2.org" operation.
         
         * @param updateRequest2
         */

        axis2_status_t axis2_stub_TraderExchange_update( axis2_stub_t *stub, const axutil_env_t *env,
                                                    axis2_updateRequest_t* updateRequest2);
        
        /**
         * auto generated function declaration
         * for "update|http://www.wso2.org" operation.
         
         * @param updateRequest2
         * @param on_complete callback to handle on complete
         * @param on_error callback to handle on error
         */

        

