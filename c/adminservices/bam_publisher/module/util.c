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

#include "bam_publisher_util.h"
#include <axutil_env.h>
#include <axutil_string.h>
#include <axis2_util.h>
#include <axis2_client.h>
#include <axis2_svc_client.h>
#include <axiom_soap.h>
#include <service_admin_util.h>
#include <stdio.h>

axiom_node_t *AXIS2_CALL
bam_publisher_util_get_payload (
    const axutil_env_t *env,
    const axis2_char_t* server_name,
    const double avg_res_time,
    const int min_res_time,
    const int max_res_time,
    const int req_count,
    const int res_count,
    const int fault_count,
    const axis2_char_t *svc_name,
    const axis2_char_t *op_name)

{
    axiom_namespace_t *stat_ns = NULL;
    axiom_node_t *event_node = NULL;
    axiom_element_t *event_element = NULL;
    axiom_node_t *svc_invocation_data_node = NULL;
    axiom_element_t *svc_invocation_data_element = NULL;
    axiom_node_t *server_name_node = NULL;
    axiom_element_t *server_name_element = NULL;
    axiom_node_t *min_res_time_node = NULL;
    axiom_element_t *min_res_time_element = NULL;
    axiom_node_t *max_res_time_node = NULL;
    axiom_element_t *max_res_time_element = NULL;
    axiom_node_t *avg_res_time_node = NULL;
    axiom_element_t *avg_res_time_element = NULL;
    axiom_node_t *req_count_node = NULL;
    axiom_element_t *req_count_element = NULL;
    axiom_node_t *res_count_node = NULL;
    axiom_element_t *res_count_element = NULL;
    axiom_node_t *fault_count_node = NULL;
    axiom_element_t *fault_count_element = NULL;
    axiom_node_t *svc_name_node = NULL;
    axiom_element_t *svc_name_element = NULL;
    axiom_node_t *op_name_node = NULL;
    axiom_element_t *op_name_element = NULL;
    axis2_char_t str_avg_res_time[8];
    axis2_char_t str_min_res_time[8];
    axis2_char_t str_max_res_time[8];
    axis2_char_t str_req_count[8];
    axis2_char_t str_res_count[8];
    axis2_char_t str_fault_count[8];
   
    sprintf(str_avg_res_time, "%f", avg_res_time);
    sprintf(str_min_res_time, "%d", min_res_time);
    sprintf(str_max_res_time, "%d", max_res_time);
    sprintf(str_req_count, "%d", req_count);
    sprintf(str_res_count, "%d", res_count);
    sprintf(str_fault_count, "%d", fault_count);
    stat_ns = axiom_namespace_create(env, STATISTICS_DATA_NS_URI, STATISTICS_DATA_NS_PREFIX);
    event_element =
        axiom_element_create(env, NULL, STATISTICS_DATA_ELEMENT_NAME_EVENT, stat_ns, &event_node);
    
    svc_invocation_data_element = axiom_element_create(env, event_node, 
            STATISTICS_DATA_ELEMENT_NAME_SERVICE_STATISTICS_DATA, stat_ns, &svc_invocation_data_node);

    server_name_element = axiom_element_create(env, svc_invocation_data_node, 
            STATISTICS_DATA_ELEMENT_NAME_SERVER_NAME, NULL, &server_name_node);
    axiom_element_set_text(server_name_element, env, server_name, server_name_node);
    
    min_res_time_element = axiom_element_create(env, svc_invocation_data_node, 
            STATISTICS_DATA_ELEMENT_NAME_MIN_RESPONSE_TIME, NULL, &min_res_time_node);
    axiom_element_set_text(min_res_time_element, env, str_min_res_time, min_res_time_node);
    
    max_res_time_element = axiom_element_create(env, svc_invocation_data_node, 
            STATISTICS_DATA_ELEMENT_NAME_MAX_RESPONSE_TIME, NULL, &max_res_time_node);
    axiom_element_set_text(max_res_time_element, env, str_max_res_time, max_res_time_node);
    
    avg_res_time_element = axiom_element_create(env, svc_invocation_data_node, 
            STATISTICS_DATA_ELEMENT_NAME_AVG_RESPONSE_TIME, NULL, &avg_res_time_node);
    axiom_element_set_text(avg_res_time_element, env, str_avg_res_time, avg_res_time_node);
    
    req_count_element = axiom_element_create(env, svc_invocation_data_node, 
            STATISTICS_DATA_ELEMENT_NAME_REQUEST_COUNT, NULL, &req_count_node);
    axiom_element_set_text(req_count_element, env, str_req_count, req_count_node);

    res_count_element = axiom_element_create(env, svc_invocation_data_node, 
            STATISTICS_DATA_ELEMENT_NAME_RESPONSE_COUNT, NULL, &res_count_node);
    axiom_element_set_text(res_count_element, env, str_res_count, res_count_node);

    fault_count_element = axiom_element_create(env, svc_invocation_data_node, 
            STATISTICS_DATA_ELEMENT_NAME_FAULT_COUNT, NULL, &fault_count_node);
    axiom_element_set_text(fault_count_element, env, str_fault_count, fault_count_node);

    if(svc_name)
    {
        svc_name_element = axiom_element_create(env, svc_invocation_data_node, 
            STATISTICS_DATA_ELEMENT_NAME_SERVICE_NAME, NULL, &svc_name_node);
        axiom_element_set_text(svc_name_element, env, svc_name, svc_name_node);
    }
    
    if(op_name)
    {
        op_name_element = axiom_element_create(env, svc_invocation_data_node, 
            STATISTICS_DATA_ELEMENT_NAME_OPERATION_NAME, NULL, &op_name_node);
        axiom_element_set_text(op_name_element, env, op_name, op_name_node);
    }

    return event_node;
}

void AXIS2_CALL
bam_publisher_util_publish(
        const axutil_env_t *env,
        axis2_msg_ctx_t *msg_ctx,
        axiom_node_t *payload)
{
    const axis2_char_t *address = NULL;
    axis2_endpoint_ref_t* endpoint_ref = NULL;
    axis2_options_t *options = NULL;
    const axis2_char_t *client_home = NULL;
    axis2_svc_client_t* svc_client = NULL;
    axis2_status_t status = AXIS2_FAILURE;
    axis2_char_t *subs_status = NULL;
    int action = 0;
    axis2_conf_ctx_t *conf_ctx = NULL;

    conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
    client_home = axis2_conf_ctx_get_root_dir(conf_ctx, env);
    address = service_admin_util_get_epr_address(env, msg_ctx, 
            BAM_PUBLISHER_SERVICE_STATISTICS_SUBSCRIBER_SERVICE);
    endpoint_ref = axis2_endpoint_ref_create(env, address);
    options = axis2_options_create(env);
    axis2_options_set_to(options, env, endpoint_ref);
    svc_client = axis2_svc_client_create(env, client_home);
    if (!svc_client)
    {
        axis2_endpoint_ref_free(endpoint_ref, env);
        axis2_option_free(options, env);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[adminservices] Error creating service client");
        return;
    }
    axis2_svc_client_set_options(svc_client, env, options);    
    axis2_svc_client_engage_module(svc_client, env, AXIS2_MODULE_ADDRESSING);
    axis2_svc_client_engage_module(svc_client, env, "savan");

    axis2_options_set_action(options, env, BAM_PUBLISHER_SERVICE_ACTION);
    endpoint_ref = axis2_options_get_to(options, env);
    axis2_endpoint_ref_set_address(endpoint_ref, env, address);
    axis2_svc_client_remove_all_headers(svc_client, env);
    axis2_svc_client_fire_and_forget(svc_client, env, payload);

    if (svc_client)
    {
        axis2_svc_client_free(svc_client, env);
        svc_client = NULL;
    }
}

