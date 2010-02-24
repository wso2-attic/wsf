/*
* Copyright 2009-2010 WSO2, Inc. http://wso2.com
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/


    /**
     * axis2_skel_StatisticsAdmin.h
     *
     * This file was auto-generated from WSDL for "StatisticsAdmin|http://services.statistics.carbon.wso2.org" service
     * by the Apache Axis2/C version: #axisVersion# #today#
     * axis2_skel_StatisticsAdmin Axis2/C skeleton for the axisService- Header file
     */


	#include <axis2_svc_skeleton.h>
	#include <axutil_log_default.h>
	#include <axutil_error_default.h>
    #include <axutil_error.h>
	#include <axiom_text.h>
	#include <axiom_node.h>
	#include <axiom_element.h>
    #include <stdio.h>


   
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

     

		 
        /**
         * auto generated function declaration
         * for "getMaxServiceResponseTime|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getMaxServiceResponseTime of the adb_getMaxServiceResponseTime_t*
         *
         * @return adb_getMaxServiceResponseTimeResponse_t*
         */
        adb_getMaxServiceResponseTimeResponse_t* axis2_skel_StatisticsAdmin_getMaxServiceResponseTime(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getMaxServiceResponseTime_t* _getMaxServiceResponseTime);


     

		 
        /**
         * auto generated function declaration
         * for "getServiceRequestCount|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getServiceRequestCount of the adb_getServiceRequestCount_t*
         *
         * @return adb_getServiceRequestCountResponse_t*
         */
        adb_getServiceRequestCountResponse_t* axis2_skel_StatisticsAdmin_getServiceRequestCount(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getServiceRequestCount_t* _getServiceRequestCount);


     

		 
        /**
         * auto generated function declaration
         * for "getSystemResponseCount|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_getSystemResponseCountResponse_t*
         */
        adb_getSystemResponseCountResponse_t* axis2_skel_StatisticsAdmin_getSystemResponseCount(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx);


     

		 
        /**
         * auto generated function declaration
         * for "getOperationResponseCount|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getOperationResponseCount of the adb_getOperationResponseCount_t*
         *
         * @return adb_getOperationResponseCountResponse_t*
         */
        adb_getOperationResponseCountResponse_t* axis2_skel_StatisticsAdmin_getOperationResponseCount(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getOperationResponseCount_t* _getOperationResponseCount);


     

		 
        /**
         * auto generated function declaration
         * for "getAvgOperationResponseTime|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getAvgOperationResponseTime of the adb_getAvgOperationResponseTime_t*
         *
         * @return adb_getAvgOperationResponseTimeResponse_t*
         */
        adb_getAvgOperationResponseTimeResponse_t* axis2_skel_StatisticsAdmin_getAvgOperationResponseTime(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getAvgOperationResponseTime_t* _getAvgOperationResponseTime);


     

		 
        /**
         * auto generated function declaration
         * for "getOperationStatistics|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getOperationStatistics of the adb_getOperationStatistics_t*
         *
         * @return adb_getOperationStatisticsResponse_t*
         */
        adb_getOperationStatisticsResponse_t* axis2_skel_StatisticsAdmin_getOperationStatistics(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getOperationStatistics_t* _getOperationStatistics);


     

		 
        /**
         * auto generated function declaration
         * for "getMinSystemResponseTime|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_getMinSystemResponseTimeResponse_t*
         */
        adb_getMinSystemResponseTimeResponse_t* axis2_skel_StatisticsAdmin_getMinSystemResponseTime(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx);


     

		 
        /**
         * auto generated function declaration
         * for "getSystemFaultCount|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_getSystemFaultCountResponse_t*
         */
        adb_getSystemFaultCountResponse_t* axis2_skel_StatisticsAdmin_getSystemFaultCount(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx);


     

		 
        /**
         * auto generated function declaration
         * for "getMaxSystemResponseTime|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_getMaxSystemResponseTimeResponse_t*
         */
        adb_getMaxSystemResponseTimeResponse_t* axis2_skel_StatisticsAdmin_getMaxSystemResponseTime(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx);


     

		 
        /**
         * auto generated function declaration
         * for "getServiceFaultCount|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getServiceFaultCount of the adb_getServiceFaultCount_t*
         *
         * @return adb_getServiceFaultCountResponse_t*
         */
        adb_getServiceFaultCountResponse_t* axis2_skel_StatisticsAdmin_getServiceFaultCount(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getServiceFaultCount_t* _getServiceFaultCount);


     

		 
        /**
         * auto generated function declaration
         * for "getMinServiceResponseTime|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getMinServiceResponseTime of the adb_getMinServiceResponseTime_t*
         *
         * @return adb_getMinServiceResponseTimeResponse_t*
         */
        adb_getMinServiceResponseTimeResponse_t* axis2_skel_StatisticsAdmin_getMinServiceResponseTime(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getMinServiceResponseTime_t* _getMinServiceResponseTime);


     

		 
        /**
         * auto generated function declaration
         * for "getMaxOperationResponseTime|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getMaxOperationResponseTime of the adb_getMaxOperationResponseTime_t*
         *
         * @return adb_getMaxOperationResponseTimeResponse_t*
         */
        adb_getMaxOperationResponseTimeResponse_t* axis2_skel_StatisticsAdmin_getMaxOperationResponseTime(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getMaxOperationResponseTime_t* _getMaxOperationResponseTime);


     

		 
        /**
         * auto generated function declaration
         * for "getServiceStatistics|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getServiceStatistics of the adb_getServiceStatistics_t*
         *
         * @return adb_getServiceStatisticsResponse_t*
         */
        adb_getServiceStatisticsResponse_t* axis2_skel_StatisticsAdmin_getServiceStatistics(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getServiceStatistics_t* _getServiceStatistics);


     

		 
        /**
         * auto generated function declaration
         * for "getOperationFaultCount|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getOperationFaultCount of the adb_getOperationFaultCount_t*
         *
         * @return adb_getOperationFaultCountResponse_t*
         */
        adb_getOperationFaultCountResponse_t* axis2_skel_StatisticsAdmin_getOperationFaultCount(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getOperationFaultCount_t* _getOperationFaultCount);


     

		 
        /**
         * auto generated function declaration
         * for "getAvgServiceResponseTime|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getAvgServiceResponseTime of the adb_getAvgServiceResponseTime_t*
         *
         * @return adb_getAvgServiceResponseTimeResponse_t*
         */
        adb_getAvgServiceResponseTimeResponse_t* axis2_skel_StatisticsAdmin_getAvgServiceResponseTime(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getAvgServiceResponseTime_t* _getAvgServiceResponseTime);


     

		 
        /**
         * auto generated function declaration
         * for "getServiceResponseCount|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getServiceResponseCount of the adb_getServiceResponseCount_t*
         *
         * @return adb_getServiceResponseCountResponse_t*
         */
        adb_getServiceResponseCountResponse_t* axis2_skel_StatisticsAdmin_getServiceResponseCount(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getServiceResponseCount_t* _getServiceResponseCount);


     

		 
        /**
         * auto generated function declaration
         * for "getSystemRequestCount|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_getSystemRequestCountResponse_t*
         */
        adb_getSystemRequestCountResponse_t* axis2_skel_StatisticsAdmin_getSystemRequestCount(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx);


     

		 
        /**
         * auto generated function declaration
         * for "getMinOperationResponseTime|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getMinOperationResponseTime of the adb_getMinOperationResponseTime_t*
         *
         * @return adb_getMinOperationResponseTimeResponse_t*
         */
        adb_getMinOperationResponseTimeResponse_t* axis2_skel_StatisticsAdmin_getMinOperationResponseTime(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getMinOperationResponseTime_t* _getMinOperationResponseTime);


     

		 
        /**
         * auto generated function declaration
         * for "getAvgSystemResponseTime|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_getAvgSystemResponseTimeResponse_t*
         */
        adb_getAvgSystemResponseTimeResponse_t* axis2_skel_StatisticsAdmin_getAvgSystemResponseTime(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx);


     

		 
        /**
         * auto generated function declaration
         * for "getSystemStatistics|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_getSystemStatisticsResponse_t*
         */
        adb_getSystemStatisticsResponse_t* axis2_skel_StatisticsAdmin_getSystemStatistics(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx);


     

		 
        /**
         * auto generated function declaration
         * for "getOperationRequestCount|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getOperationRequestCount of the adb_getOperationRequestCount_t*
         *
         * @return adb_getOperationRequestCountResponse_t*
         */
        adb_getOperationRequestCountResponse_t* axis2_skel_StatisticsAdmin_getOperationRequestCount(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getOperationRequestCount_t* _getOperationRequestCount);


     

    /** we have to reserve some error codes for adb and for custom messages */
    #define AXIS2_SKEL_STATISTICSADMIN_ERROR_CODES_START (AXIS2_ERROR_LAST + 2500)

    typedef enum 
    {
        AXIS2_SKEL_STATISTICSADMIN_ERROR_NONE = AXIS2_SKEL_STATISTICSADMIN_ERROR_CODES_START,
        
        AXIS2_SKEL_STATISTICSADMIN_ERROR_LAST
    } axis2_skel_StatisticsAdmin_error_codes;

	#ifdef __cplusplus
	}
	#endif
    

