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

#include <axis2_handler_desc.h>
#include <axis2_msg_ctx.h>
#include <axis2_svc.h>
#include <axutil_property.h>
#include <service_admin_counter.h>
#include <service_admin_util.h>
#include <codegen/adb_ServiceStatistics.h>
#include <codegen/adb_getServiceStatistics.h>
#include <codegen/adb_getServiceStatisticsResponse.h>
#include <bam_publisher_statistics.h>
#include "bam_publisher_util.h"

axis2_status_t AXIS2_CALL
bam_publisher_svc_stat_handler_invoke(
        struct axis2_handler *handler, 
        const axutil_env_t *env,
        struct axis2_msg_ctx *msg_ctx);


AXIS2_EXTERN axis2_handler_t* AXIS2_CALL
bam_publisher_svc_stat_handler_create(
        const axutil_env_t *env, 
        axutil_qname_t *qname) 
{
    axis2_handler_t *handler = NULL;
    
    handler = axis2_handler_create(env);
    if (!handler)
    {
        return NULL;
    }
   
    /* Handler init is handled by conf loading, so no need to do it here */
    
    /* Set the base struct's invoke op */
	axis2_handler_set_invoke(handler, env, bam_publisher_svc_stat_handler_invoke);

    return handler;
}

axis2_status_t AXIS2_CALL
bam_publisher_svc_stat_handler_invoke(struct axis2_handler *handler, 
                        const axutil_env_t *env,
                        struct axis2_msg_ctx *msg_ctx)
{
    axis2_status_t status = AXIS2_SUCCESS;
    axis2_char_t *svc_name = NULL;
    axis2_svc_t *svc = NULL;
    axis2_svc_t *stat_admin_svc = NULL;
    adb_getServiceStatistics_t *get_svc_stat = NULL;
    adb_getServiceStatisticsResponse_t * get_svc_stat_res = NULL;
    adb_ServiceStatistics_t *svc_stat = NULL;
    int current_count = 0;
    int last_count = 0;
    axis2_char_t *str_threshold_count = NULL;
    int threshold_count = 0;
    axutil_param_t *param = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_conf_t *conf = NULL;

    conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
    conf = axis2_conf_ctx_get_conf(conf_ctx, env);
    svc = axis2_msg_ctx_get_svc(msg_ctx, env);
    if(svc)
    {
        svc_name = (axis2_char_t *) axis2_svc_get_name(svc, env);
    }
    get_svc_stat = adb_getServiceStatistics_create_with_values(env, svc_name);
    get_svc_stat_res = bam_publisher_statistics_get_service_statistics(env, msg_ctx, get_svc_stat);
    if(get_svc_stat_res)
    {
        svc_stat = adb_getServiceStatisticsResponse_get_return(get_svc_stat_res, env);
        if(svc_stat)
        {
            current_count = adb_ServiceStatistics_get_requestCount(svc_stat, env);
        }
    }
    param = axis2_conf_get_param(conf, env, BAM_PUBLISHER_SERVICE_REQUEST_THRESHOLD_COUNT_PARAM);
    if(param)
    {
        str_threshold_count = axutil_param_get_value(param, env);
        if(str_threshold_count)
        {
            threshold_count = axutil_atoi(str_threshold_count);
        }
    }
    last_count = service_admin_counter_get_last_count(env, msg_ctx, svc_name, NULL);
    if((current_count - last_count) > threshold_count)
    {
        axis2_char_t *server_name = NULL;
        axiom_node_t *payload = NULL;
        int avg_res_time = adb_ServiceStatistics_get_avgResponseTime(svc_stat, env);
        int min_res_time = adb_ServiceStatistics_get_minResponseTime(svc_stat, env);
        int max_res_time = adb_ServiceStatistics_get_maxResponseTime(svc_stat, env);
        int request_count = current_count;
        int response_count = adb_ServiceStatistics_get_responseCount(svc_stat, env);
        int fault_count = adb_ServiceStatistics_get_faultCount(svc_stat, env);

        /* Eventing threshold count reached. So let's fire the event */
        axis2_counter_set_last_count(env, msg_ctx, svc_name, NULL, current_count);
        server_name = service_admin_util_get_epr_address(env, msg_ctx, svc_name);
        payload = bam_publisher_util_get_payload(env, server_name, avg_res_time, 
                min_res_time, max_res_time, request_count, response_count, fault_count, svc_name, NULL);
    }

    AXIS2_LOG_TRACE(env->log, AXIS2_LOG_SI, "[adminservices] End:bam_publisher_svc_stat_handler_invoke");
    
    return status;
}

