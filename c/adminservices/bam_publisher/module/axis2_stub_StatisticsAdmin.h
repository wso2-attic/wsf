

        /**
        * axis2_stub_StatisticsAdmin.h
        *
        * This file was auto-generated from WSDL for "StatisticsAdmin|http://services.statistics.carbon.wso2.org" service
        * by the Apache Axis2/Java version: 1.5.1  Built on : Oct 19, 2009 (10:59:00 EDT)
        */

        #include <stdio.h>
        #include <axiom.h>
        #include <axutil_utils.h>
        #include <axiom_soap.h>
        #include <axis2_client.h>
        #include <axis2_stub.h>

       
         #include "adb_getMaxServiceResponseTime.h"
        
         #include "adb_getMaxServiceResponseTimeResponse.h"
        
         #include "adb_getServiceRequestCount.h"
        
         #include "adb_getServiceRequestCountResponse.h"
        
         #include "adb_getSystemResponseCountResponse.h"
        
         #include "adb_getOperationResponseCount.h"
        
         #include "adb_getOperationResponseCountResponse.h"
        
         #include "adb_getAvgOperationResponseTime.h"
        
         #include "adb_getAvgOperationResponseTimeResponse.h"
        
         #include "adb_getOperationStatistics.h"
        
         #include "adb_getOperationStatisticsResponse.h"
        
         #include "adb_getMinSystemResponseTimeResponse.h"
        
         #include "adb_getSystemFaultCountResponse.h"
        
         #include "adb_getMaxSystemResponseTimeResponse.h"
        
         #include "adb_getServiceFaultCount.h"
        
         #include "adb_getServiceFaultCountResponse.h"
        
         #include "adb_getMinServiceResponseTime.h"
        
         #include "adb_getMinServiceResponseTimeResponse.h"
        
         #include "adb_getMaxOperationResponseTime.h"
        
         #include "adb_getMaxOperationResponseTimeResponse.h"
        
         #include "adb_getServiceStatistics.h"
        
         #include "adb_getServiceStatisticsResponse.h"
        
         #include "adb_getOperationFaultCount.h"
        
         #include "adb_getOperationFaultCountResponse.h"
        
         #include "adb_getAvgServiceResponseTime.h"
        
         #include "adb_getAvgServiceResponseTimeResponse.h"
        
         #include "adb_getServiceResponseCount.h"
        
         #include "adb_getServiceResponseCountResponse.h"
        
         #include "adb_getSystemRequestCountResponse.h"
        
         #include "adb_getMinOperationResponseTime.h"
        
         #include "adb_getMinOperationResponseTimeResponse.h"
        
         #include "adb_getAvgSystemResponseTimeResponse.h"
        
         #include "adb_getSystemStatisticsResponse.h"
        
         #include "adb_getOperationRequestCount.h"
        
         #include "adb_getOperationRequestCountResponse.h"
        

	#ifdef __cplusplus
	extern "C" {
	#endif

        /***************** function prototypes - for header file *************/
        /**
         * axis2_stub_create_StatisticsAdmin
         * Create and return the stub with services populated
         * @param env Environment ( mandatory)
         * @param client_home Axis2/C home ( mandatory )
         * @param endpoint_uri Service endpoint uri( optional ) - if NULL default picked from WSDL used
         * @return Newly created stub object
         */
        axis2_stub_t* AXIS2_CALL
        axis2_stub_create_StatisticsAdmin(const axutil_env_t *env,
                                        const axis2_char_t *client_home,
                                        const axis2_char_t *endpoint_uri);
        /**
         * axis2_stub_populate_services_for_StatisticsAdmin
         * populate the svc in stub with the service and operations
         * @param stub The stub
         * @param env environment ( mandatory)
         */
        void AXIS2_CALL 
        axis2_stub_populate_services_for_StatisticsAdmin( axis2_stub_t *stub, const axutil_env_t *env);
        /**
         * axis2_stub_get_endpoint_uri_of_StatisticsAdmin
         * Return the endpoint URI picked from WSDL
         * @param env environment ( mandatory)
         * @return The endpoint picked from WSDL
         */
        axis2_char_t* AXIS2_CALL
        axis2_stub_get_endpoint_uri_of_StatisticsAdmin(const axutil_env_t *env);

        
            /**
             * Auto generated function declaration
             * for "getMaxServiceResponseTime|http://services.statistics.carbon.wso2.org" operation.
             * @param stub The stub (axis2_stub_t)
             * @param env environment ( mandatory)
             * @param _getMaxServiceResponseTime of the adb_getMaxServiceResponseTime_t*
             *
             * @return adb_getMaxServiceResponseTimeResponse_t*
             */

            adb_getMaxServiceResponseTimeResponse_t* AXIS2_CALL 
            axis2_stub_op_StatisticsAdmin_getMaxServiceResponseTime( axis2_stub_t *stub, const axutil_env_t *env,
                                                  adb_getMaxServiceResponseTime_t* _getMaxServiceResponseTime);
          
            /**
             * Auto generated function declaration
             * for "getServiceRequestCount|http://services.statistics.carbon.wso2.org" operation.
             * @param stub The stub (axis2_stub_t)
             * @param env environment ( mandatory)
             * @param _getServiceRequestCount of the adb_getServiceRequestCount_t*
             *
             * @return adb_getServiceRequestCountResponse_t*
             */

            adb_getServiceRequestCountResponse_t* AXIS2_CALL 
            axis2_stub_op_StatisticsAdmin_getServiceRequestCount( axis2_stub_t *stub, const axutil_env_t *env,
                                                  adb_getServiceRequestCount_t* _getServiceRequestCount);
          
            /**
             * Auto generated function declaration
             * for "getSystemResponseCount|http://services.statistics.carbon.wso2.org" operation.
             * @param stub The stub (axis2_stub_t)
             * @param env environment ( mandatory)
             *
             * @return adb_getSystemResponseCountResponse_t*
             */

            adb_getSystemResponseCountResponse_t* AXIS2_CALL 
            axis2_stub_op_StatisticsAdmin_getSystemResponseCount( axis2_stub_t *stub, const axutil_env_t *env);
          
            /**
             * Auto generated function declaration
             * for "getOperationResponseCount|http://services.statistics.carbon.wso2.org" operation.
             * @param stub The stub (axis2_stub_t)
             * @param env environment ( mandatory)
             * @param _getOperationResponseCount of the adb_getOperationResponseCount_t*
             *
             * @return adb_getOperationResponseCountResponse_t*
             */

            adb_getOperationResponseCountResponse_t* AXIS2_CALL 
            axis2_stub_op_StatisticsAdmin_getOperationResponseCount( axis2_stub_t *stub, const axutil_env_t *env,
                                                  adb_getOperationResponseCount_t* _getOperationResponseCount);
          
            /**
             * Auto generated function declaration
             * for "getAvgOperationResponseTime|http://services.statistics.carbon.wso2.org" operation.
             * @param stub The stub (axis2_stub_t)
             * @param env environment ( mandatory)
             * @param _getAvgOperationResponseTime of the adb_getAvgOperationResponseTime_t*
             *
             * @return adb_getAvgOperationResponseTimeResponse_t*
             */

            adb_getAvgOperationResponseTimeResponse_t* AXIS2_CALL 
            axis2_stub_op_StatisticsAdmin_getAvgOperationResponseTime( axis2_stub_t *stub, const axutil_env_t *env,
                                                  adb_getAvgOperationResponseTime_t* _getAvgOperationResponseTime);
          
            /**
             * Auto generated function declaration
             * for "getOperationStatistics|http://services.statistics.carbon.wso2.org" operation.
             * @param stub The stub (axis2_stub_t)
             * @param env environment ( mandatory)
             * @param _getOperationStatistics of the adb_getOperationStatistics_t*
             *
             * @return adb_getOperationStatisticsResponse_t*
             */

            adb_getOperationStatisticsResponse_t* AXIS2_CALL 
            axis2_stub_op_StatisticsAdmin_getOperationStatistics( axis2_stub_t *stub, const axutil_env_t *env,
                                                  adb_getOperationStatistics_t* _getOperationStatistics);
          
            /**
             * Auto generated function declaration
             * for "getMinSystemResponseTime|http://services.statistics.carbon.wso2.org" operation.
             * @param stub The stub (axis2_stub_t)
             * @param env environment ( mandatory)
             *
             * @return adb_getMinSystemResponseTimeResponse_t*
             */

            adb_getMinSystemResponseTimeResponse_t* AXIS2_CALL 
            axis2_stub_op_StatisticsAdmin_getMinSystemResponseTime( axis2_stub_t *stub, const axutil_env_t *env);
          
            /**
             * Auto generated function declaration
             * for "getSystemFaultCount|http://services.statistics.carbon.wso2.org" operation.
             * @param stub The stub (axis2_stub_t)
             * @param env environment ( mandatory)
             *
             * @return adb_getSystemFaultCountResponse_t*
             */

            adb_getSystemFaultCountResponse_t* AXIS2_CALL 
            axis2_stub_op_StatisticsAdmin_getSystemFaultCount( axis2_stub_t *stub, const axutil_env_t *env);
          
            /**
             * Auto generated function declaration
             * for "getMaxSystemResponseTime|http://services.statistics.carbon.wso2.org" operation.
             * @param stub The stub (axis2_stub_t)
             * @param env environment ( mandatory)
             *
             * @return adb_getMaxSystemResponseTimeResponse_t*
             */

            adb_getMaxSystemResponseTimeResponse_t* AXIS2_CALL 
            axis2_stub_op_StatisticsAdmin_getMaxSystemResponseTime( axis2_stub_t *stub, const axutil_env_t *env);
          
            /**
             * Auto generated function declaration
             * for "getServiceFaultCount|http://services.statistics.carbon.wso2.org" operation.
             * @param stub The stub (axis2_stub_t)
             * @param env environment ( mandatory)
             * @param _getServiceFaultCount of the adb_getServiceFaultCount_t*
             *
             * @return adb_getServiceFaultCountResponse_t*
             */

            adb_getServiceFaultCountResponse_t* AXIS2_CALL 
            axis2_stub_op_StatisticsAdmin_getServiceFaultCount( axis2_stub_t *stub, const axutil_env_t *env,
                                                  adb_getServiceFaultCount_t* _getServiceFaultCount);
          
            /**
             * Auto generated function declaration
             * for "getMinServiceResponseTime|http://services.statistics.carbon.wso2.org" operation.
             * @param stub The stub (axis2_stub_t)
             * @param env environment ( mandatory)
             * @param _getMinServiceResponseTime of the adb_getMinServiceResponseTime_t*
             *
             * @return adb_getMinServiceResponseTimeResponse_t*
             */

            adb_getMinServiceResponseTimeResponse_t* AXIS2_CALL 
            axis2_stub_op_StatisticsAdmin_getMinServiceResponseTime( axis2_stub_t *stub, const axutil_env_t *env,
                                                  adb_getMinServiceResponseTime_t* _getMinServiceResponseTime);
          
            /**
             * Auto generated function declaration
             * for "getMaxOperationResponseTime|http://services.statistics.carbon.wso2.org" operation.
             * @param stub The stub (axis2_stub_t)
             * @param env environment ( mandatory)
             * @param _getMaxOperationResponseTime of the adb_getMaxOperationResponseTime_t*
             *
             * @return adb_getMaxOperationResponseTimeResponse_t*
             */

            adb_getMaxOperationResponseTimeResponse_t* AXIS2_CALL 
            axis2_stub_op_StatisticsAdmin_getMaxOperationResponseTime( axis2_stub_t *stub, const axutil_env_t *env,
                                                  adb_getMaxOperationResponseTime_t* _getMaxOperationResponseTime);
          
            /**
             * Auto generated function declaration
             * for "getServiceStatistics|http://services.statistics.carbon.wso2.org" operation.
             * @param stub The stub (axis2_stub_t)
             * @param env environment ( mandatory)
             * @param _getServiceStatistics of the adb_getServiceStatistics_t*
             *
             * @return adb_getServiceStatisticsResponse_t*
             */

            adb_getServiceStatisticsResponse_t* AXIS2_CALL 
            axis2_stub_op_StatisticsAdmin_getServiceStatistics( axis2_stub_t *stub, const axutil_env_t *env,
                                                  adb_getServiceStatistics_t* _getServiceStatistics);
          
            /**
             * Auto generated function declaration
             * for "getOperationFaultCount|http://services.statistics.carbon.wso2.org" operation.
             * @param stub The stub (axis2_stub_t)
             * @param env environment ( mandatory)
             * @param _getOperationFaultCount of the adb_getOperationFaultCount_t*
             *
             * @return adb_getOperationFaultCountResponse_t*
             */

            adb_getOperationFaultCountResponse_t* AXIS2_CALL 
            axis2_stub_op_StatisticsAdmin_getOperationFaultCount( axis2_stub_t *stub, const axutil_env_t *env,
                                                  adb_getOperationFaultCount_t* _getOperationFaultCount);
          
            /**
             * Auto generated function declaration
             * for "getAvgServiceResponseTime|http://services.statistics.carbon.wso2.org" operation.
             * @param stub The stub (axis2_stub_t)
             * @param env environment ( mandatory)
             * @param _getAvgServiceResponseTime of the adb_getAvgServiceResponseTime_t*
             *
             * @return adb_getAvgServiceResponseTimeResponse_t*
             */

            adb_getAvgServiceResponseTimeResponse_t* AXIS2_CALL 
            axis2_stub_op_StatisticsAdmin_getAvgServiceResponseTime( axis2_stub_t *stub, const axutil_env_t *env,
                                                  adb_getAvgServiceResponseTime_t* _getAvgServiceResponseTime);
          
            /**
             * Auto generated function declaration
             * for "getServiceResponseCount|http://services.statistics.carbon.wso2.org" operation.
             * @param stub The stub (axis2_stub_t)
             * @param env environment ( mandatory)
             * @param _getServiceResponseCount of the adb_getServiceResponseCount_t*
             *
             * @return adb_getServiceResponseCountResponse_t*
             */

            adb_getServiceResponseCountResponse_t* AXIS2_CALL 
            axis2_stub_op_StatisticsAdmin_getServiceResponseCount( axis2_stub_t *stub, const axutil_env_t *env,
                                                  adb_getServiceResponseCount_t* _getServiceResponseCount);
          
            /**
             * Auto generated function declaration
             * for "getSystemRequestCount|http://services.statistics.carbon.wso2.org" operation.
             * @param stub The stub (axis2_stub_t)
             * @param env environment ( mandatory)
             *
             * @return adb_getSystemRequestCountResponse_t*
             */

            adb_getSystemRequestCountResponse_t* AXIS2_CALL 
            axis2_stub_op_StatisticsAdmin_getSystemRequestCount( axis2_stub_t *stub, const axutil_env_t *env);
          
            /**
             * Auto generated function declaration
             * for "getMinOperationResponseTime|http://services.statistics.carbon.wso2.org" operation.
             * @param stub The stub (axis2_stub_t)
             * @param env environment ( mandatory)
             * @param _getMinOperationResponseTime of the adb_getMinOperationResponseTime_t*
             *
             * @return adb_getMinOperationResponseTimeResponse_t*
             */

            adb_getMinOperationResponseTimeResponse_t* AXIS2_CALL 
            axis2_stub_op_StatisticsAdmin_getMinOperationResponseTime( axis2_stub_t *stub, const axutil_env_t *env,
                                                  adb_getMinOperationResponseTime_t* _getMinOperationResponseTime);
          
            /**
             * Auto generated function declaration
             * for "getAvgSystemResponseTime|http://services.statistics.carbon.wso2.org" operation.
             * @param stub The stub (axis2_stub_t)
             * @param env environment ( mandatory)
             *
             * @return adb_getAvgSystemResponseTimeResponse_t*
             */

            adb_getAvgSystemResponseTimeResponse_t* AXIS2_CALL 
            axis2_stub_op_StatisticsAdmin_getAvgSystemResponseTime( axis2_stub_t *stub, const axutil_env_t *env);
          
            /**
             * Auto generated function declaration
             * for "getSystemStatistics|http://services.statistics.carbon.wso2.org" operation.
             * @param stub The stub (axis2_stub_t)
             * @param env environment ( mandatory)
             *
             * @return adb_getSystemStatisticsResponse_t*
             */

            adb_getSystemStatisticsResponse_t* AXIS2_CALL 
            axis2_stub_op_StatisticsAdmin_getSystemStatistics( axis2_stub_t *stub, const axutil_env_t *env);
          
            /**
             * Auto generated function declaration
             * for "getOperationRequestCount|http://services.statistics.carbon.wso2.org" operation.
             * @param stub The stub (axis2_stub_t)
             * @param env environment ( mandatory)
             * @param _getOperationRequestCount of the adb_getOperationRequestCount_t*
             *
             * @return adb_getOperationRequestCountResponse_t*
             */

            adb_getOperationRequestCountResponse_t* AXIS2_CALL 
            axis2_stub_op_StatisticsAdmin_getOperationRequestCount( axis2_stub_t *stub, const axutil_env_t *env,
                                                  adb_getOperationRequestCount_t* _getOperationRequestCount);
          

        /**
         * Auto generated function for asynchronous invocations
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
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) );

        

        /**
         * Auto generated function for asynchronous invocations
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
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) );

        

        /**
         * Auto generated function for asynchronous invocations
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
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) );

        

        /**
         * Auto generated function for asynchronous invocations
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
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) );

        

        /**
         * Auto generated function for asynchronous invocations
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
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) );

        

        /**
         * Auto generated function for asynchronous invocations
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
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) );

        

        /**
         * Auto generated function for asynchronous invocations
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
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) );

        

        /**
         * Auto generated function for asynchronous invocations
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
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) );

        

        /**
         * Auto generated function for asynchronous invocations
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
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) );

        

        /**
         * Auto generated function for asynchronous invocations
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
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) );

        

        /**
         * Auto generated function for asynchronous invocations
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
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) );

        

        /**
         * Auto generated function for asynchronous invocations
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
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) );

        

        /**
         * Auto generated function for asynchronous invocations
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
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) );

        

        /**
         * Auto generated function for asynchronous invocations
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
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) );

        

        /**
         * Auto generated function for asynchronous invocations
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
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) );

        

        /**
         * Auto generated function for asynchronous invocations
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
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) );

        

        /**
         * Auto generated function for asynchronous invocations
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
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) );

        

        /**
         * Auto generated function for asynchronous invocations
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
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) );

        

        /**
         * Auto generated function for asynchronous invocations
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
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) );

        

        /**
         * Auto generated function for asynchronous invocations
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
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) );

        

        /**
         * Auto generated function for asynchronous invocations
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
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) );

        

	#ifdef __cplusplus
	}
	#endif
   

