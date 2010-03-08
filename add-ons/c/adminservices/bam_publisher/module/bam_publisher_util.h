/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
#ifndef BAM_PUBLISHER_UTIL_H
#define BAM_PUBLISHER_UTIL_H

/**
  * @file axis2_counter.h
  * @brief 
  */

#include <axutil_utils_defines.h>
#include <axutil_env.h>
#include <axiom_node.h>

#ifdef __cplusplus
extern "C"
{
#endif

/** 
 * @ingroup axis2_counter
 * @{
 */
#define BAM_PUBLISHER_SERVICE_STAT_HANDLER "ServiceStatHandler"
#define BAM_PUBLISHER_OPERATION_STAT_HANDLER "OperationStatHandler"

#define TRANSPORT "https" /* TODO: it is not ideal to assume https is always availabe */

#define STATISTICS_DATA_NS_URI "http://wso2.org/ns/2009/09/bam/service/statistics/data"
#define STATISTICS_DATA_NS_PREFIX "statdata"

/* OM element names */
#define STATISTICS_DATA_ELEMENT_NAME_EVENT "Event"
#define STATISTICS_DATA_ELEMENT_NAME_SERVICE_STATISTICS_DATA "ServiceStatisticsData"
#define STATISTICS_DATA_ELEMENT_NAME_SERVER_NAME "ServerName"
#define STATISTICS_DATA_ELEMENT_NAME_AVG_RESPONSE_TIME "AveageResponseTime"
#define STATISTICS_DATA_ELEMENT_NAME_MIN_RESPONSE_TIME "MinimumResponseTime"
#define STATISTICS_DATA_ELEMENT_NAME_MAX_RESPONSE_TIME "MaximumResponseTime"
#define STATISTICS_DATA_ELEMENT_NAME_REQUEST_COUNT "RequestCount"
#define STATISTICS_DATA_ELEMENT_NAME_RESPONSE_COUNT "ResponseCount"
#define STATISTICS_DATA_ELEMENT_NAME_FAULT_COUNT "FaultCount"
#define STATISTICS_DATA_ELEMENT_IS_AGGREGATE "IsAggregateEvent"

#define STATISTICS_DATA_ELEMENT_NAME_SERVICE_NAME "ServiceName"

#define STATISTICS_DATA_ELEMENT_NAME_OPERATION_NAME "OperationName"

#define BAM_PUBLISHER_MODULE "bam_publisher"
#define BAM_PUBLISHER_SERVICE_REQUEST_THRESHOLD_COUNT_PARAM "service_request_count_threshold"
#define BAM_PUBLISHER_OPERATION_REQUEST_THRESHOLD_COUNT_PARAM "operation_request_count_threshold"
#define BAM_PUBLISHER_DEFAULT_THRESHOLD_COUNT 5
/** 
 * @brief counter struct impl
 *	Counter Struct
 */

struct axis2_msg_ctx;

axiom_node_t *AXIS2_CALL
bam_publisher_util_get_payload (
    const axutil_env_t *env,
    const axis2_char_t* server_name,
    const double avg_res_time,
    const long min_res_time,
    const long max_res_time,
    const long req_ount,
    const long res_count,
    const long fault_count,
    const axis2_char_t *svc_name,
    const axis2_char_t *op_name);

void AXIS2_CALL
bam_publisher_util_publish(
        const axutil_env_t *env,
        struct axis2_msg_ctx *msg_ctx,
        axiom_node_t *node);
    
axis2_bool_t AXIS2_CALL
bam_publisher_util_is_service_allowed_for_statistics_query(
        const axutil_env_t *env, 
        axis2_char_t *svc_name);

/** @} */
#ifdef __cplusplus
}
#endif

#endif /*BAM_PUBLISHER_UTIL_H*/
