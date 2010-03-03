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
#include <axis2_op.h>
#include <axutil_property.h>
#include <service_admin_counter.h>
#include <service_admin_util.h>
#include "bam_publisher_statistics.h"
#include "bam_publisher_util.h"
#include "axutil_types.h"

axis2_status_t AXIS2_CALL
bam_publisher_op_stat_handler_invoke(
        struct axis2_handler *handler, 
        const axutil_env_t *env,
        struct axis2_msg_ctx *msg_ctx);


AXIS2_EXTERN axis2_handler_t* AXIS2_CALL
bam_publisher_op_stat_handler_create(
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
	axis2_handler_set_invoke(handler, env, bam_publisher_op_stat_handler_invoke);

    return handler;
}

axis2_status_t AXIS2_CALL
bam_publisher_op_stat_handler_invoke(struct axis2_handler *handler, 
                        const axutil_env_t *env,
                        struct axis2_msg_ctx *msg_ctx)
{
    axis2_status_t status = AXIS2_SUCCESS;
    axis2_char_t *svc_name = NULL;
    axis2_char_t *op_name = NULL;
    axis2_svc_t *svc = NULL;
    axis2_op_t *op = NULL;
    int current_count = 0;
    int last_count = 0;
    axis2_char_t *str_threshold_count = NULL;
    long threshold_count = BAM_PUBLISHER_DEFAULT_THRESHOLD_COUNT;
    axutil_param_t *param = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_conf_t *conf = NULL;
    axis2_module_desc_t *module_desc = NULL;
    axutil_qname_t *mod_qname = NULL;

    AXIS2_LOG_TRACE(env->log, AXIS2_LOG_SI, "[adminservices] Entry:bam_publisher_op_stat_handler_invoke");
    conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
    conf = axis2_conf_ctx_get_conf(conf_ctx, env);
    svc = axis2_msg_ctx_get_svc(msg_ctx, env);
    if(svc)
    {
        svc_name = (axis2_char_t *) axis2_svc_get_name(svc, env);
        if(!bam_publisher_util_is_service_allowed_for_statistics_query(env, svc_name))
        {
            return AXIS2_SUCCESS;
        }
    }
    op = axis2_msg_ctx_get_op(msg_ctx, env);
    if(op)
    {
        op_name = axutil_qname_get_localpart(axis2_op_get_qname(op, env), env);
        current_count = bam_publisher_statistics_get_operation_request_count(env, msg_ctx, op);
    }
    mod_qname = axutil_qname_create(env, BAM_PUBLISHER_MODULE, NULL, NULL);
    module_desc = axis2_conf_get_module(conf, env, mod_qname);
    axutil_qname_free(mod_qname, env);
    param = axis2_module_desc_get_param(module_desc, env, 
            BAM_PUBLISHER_OPERATION_REQUEST_THRESHOLD_COUNT_PARAM);
    if(param)
    {
        str_threshold_count = axutil_param_get_value(param, env);
        if(str_threshold_count)
        {
            threshold_count = axutil_atoi(str_threshold_count);
        }
    }
    axutil_allocator_switch_to_global_pool(env->allocator);
    last_count = service_admin_counter_get_last_count(env, msg_ctx, svc_name, op_name);
    axutil_allocator_switch_to_local_pool(env->allocator);
    if((current_count - last_count) > threshold_count)
    {
        axis2_char_t *server_name = NULL;
        axiom_node_t *payload = NULL;
        double avg_res_time = bam_publisher_statistics_get_avg_operation_response_time(env, msg_ctx, op);
        long min_res_time = bam_publisher_statistics_get_min_operation_response_time(env, msg_ctx, op);
        long max_res_time = bam_publisher_statistics_get_max_operation_response_time(env, msg_ctx, op);
        long request_count = current_count;
        long response_count = bam_publisher_statistics_get_operation_response_count(env, msg_ctx, op);
        long fault_count = bam_publisher_statistics_get_operation_fault_count(env, msg_ctx, op);

        /* Eventing threshold count reached. So let's fire the event */
        axutil_allocator_switch_to_global_pool(env->allocator);
        service_admin_counter_set_last_count(env, msg_ctx, svc_name, op_name, current_count);
        axutil_allocator_switch_to_local_pool(env->allocator);
        server_name = service_admin_util_get_epr_address(env, msg_ctx, NULL);
        payload = bam_publisher_util_get_payload(env, server_name, avg_res_time, 
                min_res_time, max_res_time, request_count, response_count, fault_count, svc_name, 
                op_name);
        if(payload)
        {
            bam_publisher_util_publish(env, msg_ctx, payload);
        }
        else
        {
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                    "[adminservices] Event payload creation failed");
            status = AXIS2_FAILURE;
        }
    }
 
    AXIS2_LOG_TRACE(env->log, AXIS2_LOG_SI, "[adminservices] End:bam_publisher_op_stat_handler_invoke");
    
    return status;
}

