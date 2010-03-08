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
#include <service_admin_constants.h>
#include <savan_subs_mgr.h>
#include <savan_publisher.h>
#include <stdio.h>

axiom_node_t *AXIS2_CALL
bam_publisher_util_get_payload (
    const axutil_env_t *env,
    const axis2_char_t* server_name,
    const double avg_res_time,
    const long min_res_time,
    const long max_res_time,
    const long req_count,
    const long res_count,
    const long fault_count,
    const axis2_char_t *svc_name,
    const axis2_char_t *op_name)

{
    axiom_namespace_t *stat_ns = NULL;
    axiom_node_t *event_node = NULL;
    axiom_element_t *event_element = NULL;
    axiom_node_t *svc_invocation_data_node = NULL;
    axiom_element_t *svc_invocation_data_element = NULL;
    axiom_node_t *is_aggregate_node = NULL;
    axiom_element_t *is_aggregate_element = NULL;
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
    axis2_char_t str_avg_res_time[64];
    axis2_char_t str_min_res_time[8];
    axis2_char_t str_max_res_time[8];
    axis2_char_t str_req_count[8];
    axis2_char_t str_res_count[8];
    axis2_char_t str_fault_count[8];
  
    sprintf(str_avg_res_time, "%f", avg_res_time);
    sprintf(str_min_res_time, "%ld", min_res_time);
    sprintf(str_max_res_time, "%ld", max_res_time);
    sprintf(str_req_count, "%ld", req_count);
    sprintf(str_res_count, "%ld", res_count);
    sprintf(str_fault_count, "%ld", fault_count);
    stat_ns = axiom_namespace_create(env, STATISTICS_DATA_NS_URI, STATISTICS_DATA_NS_PREFIX);
    event_element =
        axiom_element_create(env, NULL, STATISTICS_DATA_ELEMENT_NAME_EVENT, stat_ns, &event_node);
    
    svc_invocation_data_element = axiom_element_create(env, event_node, 
            STATISTICS_DATA_ELEMENT_NAME_SERVICE_STATISTICS_DATA, stat_ns, &svc_invocation_data_node);

    is_aggregate_element = axiom_element_create(env, svc_invocation_data_node, 
            STATISTICS_DATA_ELEMENT_IS_AGGREGATE, stat_ns, &is_aggregate_node);
    axiom_element_set_text(is_aggregate_element, env, "false", is_aggregate_node);

    server_name_element = axiom_element_create(env, svc_invocation_data_node, 
            STATISTICS_DATA_ELEMENT_NAME_SERVER_NAME, stat_ns, &server_name_node);
    axiom_element_set_text(server_name_element, env, server_name, server_name_node);
    
    min_res_time_element = axiom_element_create(env, svc_invocation_data_node, 
            STATISTICS_DATA_ELEMENT_NAME_MIN_RESPONSE_TIME, stat_ns, &min_res_time_node);
    axiom_element_set_text(min_res_time_element, env, str_min_res_time, min_res_time_node);
    
    max_res_time_element = axiom_element_create(env, svc_invocation_data_node, 
            STATISTICS_DATA_ELEMENT_NAME_MAX_RESPONSE_TIME, stat_ns, &max_res_time_node);
    axiom_element_set_text(max_res_time_element, env, str_max_res_time, max_res_time_node);
    
    avg_res_time_element = axiom_element_create(env, svc_invocation_data_node, 
            STATISTICS_DATA_ELEMENT_NAME_AVG_RESPONSE_TIME, stat_ns, &avg_res_time_node);
    axiom_element_set_text(avg_res_time_element, env, str_avg_res_time, avg_res_time_node);
    
    req_count_element = axiom_element_create(env, svc_invocation_data_node, 
            STATISTICS_DATA_ELEMENT_NAME_REQUEST_COUNT, stat_ns, &req_count_node);
    axiom_element_set_text(req_count_element, env, str_req_count, req_count_node);

    res_count_element = axiom_element_create(env, svc_invocation_data_node, 
            STATISTICS_DATA_ELEMENT_NAME_RESPONSE_COUNT, stat_ns, &res_count_node);
    axiom_element_set_text(res_count_element, env, str_res_count, res_count_node);

    fault_count_element = axiom_element_create(env, svc_invocation_data_node, 
            STATISTICS_DATA_ELEMENT_NAME_FAULT_COUNT, stat_ns, &fault_count_node);
    axiom_element_set_text(fault_count_element, env, str_fault_count, fault_count_node);

    if(svc_name)
    {
        svc_name_element = axiom_element_create(env, svc_invocation_data_node, 
            STATISTICS_DATA_ELEMENT_NAME_SERVICE_NAME, stat_ns, &svc_name_node);
        axiom_element_set_text(svc_name_element, env, svc_name, svc_name_node);
    }
    
    if(op_name)
    {
        op_name_element = axiom_element_create(env, svc_invocation_data_node, 
            STATISTICS_DATA_ELEMENT_NAME_OPERATION_NAME, stat_ns, &op_name_node);
        axiom_element_set_text(op_name_element, env, op_name, op_name_node);
    }

    return event_node;
}

axis2_bool_t AXIS2_CALL
bam_publisher_util_is_service_allowed_for_statistics_query(
            const axutil_env_t *env, 
            axis2_char_t *svc_name)
{
    axis2_bool_t ret = AXIS2_TRUE;
    if(svc_name && !axutil_strcmp(svc_name, ADMIN_SERVICE_STATISTICS_SVC_NAME))
    {
        /* We don't request statistics for statistics admin service it self */
        return AXIS2_FALSE;
    }
    if(!axutil_strcmp(svc_name, AXIS2_ANON_SERVICE))
    {
        return AXIS2_FALSE;
    }

    return ret;
}

void AXIS2_CALL
bam_publisher_util_publish(
        const axutil_env_t *env,
        axis2_msg_ctx_t *msg_ctx,
        axiom_node_t *payload)
{
    axis2_conf_t *conf = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;
    savan_subs_mgr_t *subs_mgr = NULL;
    
    AXIS2_LOG_TRACE(env->log, AXIS2_LOG_SI, "[adminservices] Entry:bam_publisher_util_publish");
   
    conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
    conf = axis2_conf_ctx_get_conf(conf_ctx, env);

    subs_mgr = savan_subs_mgr_get_subs_mgr(env, conf_ctx, conf);
    if(subs_mgr)
    {
        axis2_msg_ctx_t *new_msg_ctx = NULL;

        new_msg_ctx = axis2_msg_ctx_create(env, conf_ctx, NULL, NULL);
        if(new_msg_ctx)
        {
            axiom_soap_envelope_t *envelope = NULL;

            envelope = axiom_soap_envelope_create_default_soap_envelope(env, 
                axiom_soap_envelope_get_soap_version(axis2_msg_ctx_get_soap_envelope(msg_ctx, env), 
                    env));
            if(envelope)
            {
                axiom_soap_body_t *body = NULL;
                axiom_node_t *base = NULL;
                savan_publisher_t *pub_mod = NULL;
                axis2_svc_t *svc = NULL;
                axutil_property_t *property = NULL;

                body = axiom_soap_envelope_get_body(envelope, env);
                base = axiom_soap_body_get_base_node(body, env);
                axiom_node_add_child(base, env, payload);
                axis2_msg_ctx_set_soap_envelope(new_msg_ctx, env, envelope);
            
                svc = axis2_conf_get_svc(conf, env, ADMIN_SERVICE_STATISTICS_SAVAN_SERVICE);
                axis2_msg_ctx_set_svc(new_msg_ctx, env, svc);
                property = axutil_property_create_with_args(env, 0, 0, 0, 
                        "/carbon/bam/data/publishers/service_stats");
                axis2_msg_ctx_set_property(msg_ctx, env, "Topic", property);
                pub_mod = savan_publisher_create_with_conf(env, conf);
                if(pub_mod)
                {
                    savan_publisher_publish(pub_mod, env, new_msg_ctx, subs_mgr);
                    savan_publisher_free(pub_mod, env);
                }
            }
            axis2_msg_ctx_free(new_msg_ctx, env);
        }
    }
    
    AXIS2_LOG_TRACE(env->log, AXIS2_LOG_SI, "[adminservices] Exit:bam_publisher_util_publish");
}

