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
#include <axutil_property.h>
#include "../../util/service_admin_counter.h"

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
    statistics_admin_svc_t *stat_admin_svc = NULL;
    adb_getServiceStatistics_t *get_svc_stat = NULL;
    adb_getServiceStatisticsResponse_t * get_svc_stat_res = NULL;
    adb_ServiceStatistics_t *svc_stat = NULL;
    int current_count = 0;
    int last_count = 0;
    axis2_char_t *str_threshold_count = NULL;
    int threshold_count = 0;

    svc = axis2_msg_ctx_get_svc(msg_ctx, env);
    if(svc)
    {
        svc_name = axis2_svc_get_name(svc, env);
    }
    get_svc_stat = adb_getServiceStatistics_create_with_values(env, svc_name);
    get_svc_stat_res = axis2_stub_StatisticsAdmin_getServiceStatistics(env, msg_ctx, get_svc_stat);
    if(get_svc_stat_res)
    {
        current_count = adb_getServiceStatisticsResponse_get_return(get_svc_stat_res, env);
    }
    param = axis2_conf_ctx_get_param(conf_ctx, env, BAM_PUBLISHER_THRESHOLD_COUNT_PARAM);
    if(param)
    {
        str_threshhold_count = axutil_param_get_value(param, env);
        if(str_threshold_count)
        {
            threshold_count = axutil_atoi(str_threshold_count);
        }
    }
    last_count = service_admin_counter_get_last_count(env, msg_ctx, svc_name, NULL);
    if((current_count - last_count) > threshold_count)
    {
        adb_Event_t *event = NULL;
        adb_ServiceStatisticsData_type0_t* svc_stat_data_type = NULL;
        axis2_char_t *epr = NULL;
        /* Eventing threshold count reached. So let's fire the event */
        axis2_counter_set_last_count(env, msg_ctx, svc_name, NULL, current_count);
        epr = service_admin_util_get_epr_address(env, msg_ctx, svc_name);
        svc_stat_data_type = adb_ServiceStatisticsData_type0_create_with_values(env, epr, avg_res_time, 
                min_res_time, max_res_time, request_count, response_count, fault_count, svc_name, op_name);
        if(svc_stat_data_type)
        {
            event = adb_Event_create_with_values(env, svc_stat_data_type);
        }
    }

    AXIS2_LOG_TRACE(env->log, AXIS2_LOG_SI, "[adminservices] End:bam_publisher_svc_stat_handler_invoke");
    
    return status;
}

