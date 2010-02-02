

        /**
        * bam_publisher_statistics.h
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

        adb_getOperationStatisticsResponse_t* AXIS2_CALL 
        bam_publisher_statistics_get_operation_statistics(
                const axutil_env_t *env,
                axis2_msg_ctx_t *msg_ctx,
                adb_getOperationStatistics_t *op_stat);
        
        adb_getServiceStatisticsResponse_t* AXIS2_CALL 
        bam_publisher_statistics_get_service_statistics( 
                const axutil_env_t *env, 
                axis2_msg_ctx_t *msg_ctx,
                adb_getServiceStatistics_t *svc_stat);
        

	#ifdef __cplusplus
	}
	#endif
   

