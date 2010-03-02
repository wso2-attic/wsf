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
#include <axis2_op.h>
#include <axis2_msg_ctx.h>
#include <axutil_property.h>
#include <axis2_op.h>
#include <service_admin_counter.h>
#include <service_admin_constants.h>
#include <service_admin_response_time_processor.h>
#include "service_admin_util.h"

static axis2_status_t AXIS2_CALL
axis2_statistics_admin_calculate_response_times( 
                        const axutil_env_t *env,
                        struct axis2_msg_ctx *msg_ctx);

axis2_status_t AXIS2_CALL
axis2_statistics_admin_response_time_handler_invoke(
        struct axis2_handler *handler, 
        const axutil_env_t *env,
        struct axis2_msg_ctx *msg_ctx);


AXIS2_EXTERN axis2_handler_t* AXIS2_CALL
axis2_statistics_admin_response_time_handler_create(
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
	axis2_handler_set_invoke(handler, env, axis2_statistics_admin_response_time_handler_invoke);

    return handler;
}

axis2_status_t AXIS2_CALL
axis2_statistics_admin_response_time_handler_invoke(struct axis2_handler *handler, 
                        const axutil_env_t *env,
                        struct axis2_msg_ctx *msg_ctx)
{
    axis2_status_t status = AXIS2_SUCCESS;
    axis2_svc_t *svc = NULL;
    
    AXIS2_LOG_TRACE(env->log, AXIS2_LOG_SI, "[adminservices] Start:axis2_statistics_admin_response_time_handler_invoke");
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);

    svc = axis2_msg_ctx_get_svc(msg_ctx, env);
    if(svc)
    {
        status = axis2_statistics_admin_calculate_response_times(env, msg_ctx);
    }
        
    AXIS2_LOG_TRACE(env->log, AXIS2_LOG_SI, "[adminservices] End:axis2_statistics_admin_response_time_handler_invoke");
    
    return status;
}


static axis2_status_t AXIS2_CALL
axis2_statistics_admin_calculate_response_times( 
                        const axutil_env_t *env,
                        struct axis2_msg_ctx *msg_ctx)
{
    axis2_status_t status = AXIS2_SUCCESS;
    axis2_op_ctx_t *op_ctx = NULL;

    op_ctx = axis2_msg_ctx_get_op_ctx(msg_ctx, env);
    if(op_ctx)
    {
        axis2_msg_ctx_t *in_msg_ctx = NULL;
        in_msg_ctx =  axis2_op_ctx_get_msg_ctx(op_ctx, env, AXIS2_WSDL_MESSAGE_LABEL_IN);
        if(in_msg_ctx)
        {
            axutil_property_t *property = NULL;
            long *received_time = NULL;
            long response_time = 0;
            long current_time = 0;
            axis2_svc_t *svc = NULL;
            axis2_op_t *op = NULL;

            property = axis2_msg_ctx_get_property(in_msg_ctx, env, AXIS2_REQUEST_RECEIVED_TIME);
            if(property)
            {
                received_time = axutil_property_get_value(property, env);
            }
            current_time = service_admin_util_get_current_time_in_millis(env);
            if(received_time)
            {
                response_time = current_time - *received_time;
            }
            svc = axis2_msg_ctx_get_svc(msg_ctx, env);
            if(svc)
            {
                axutil_param_t *param = NULL;
                axutil_param_t *src_param = NULL;
                service_admin_response_time_processor_t *res_time_processor = NULL;
                service_admin_counter_t *counter = NULL;
                long src_count = 0;
                
                src_param = axis2_svc_get_param(svc, env, AXIS2_SERVICE_REQUEST_COUNTER);
                if(src_param)
                {
                    counter = axutil_param_get_value(src_param, env);
                    src_count = service_admin_counter_get_count(counter, env, msg_ctx);
                }
                param = axis2_svc_get_param(svc, env, AXIS2_SERVICE_RESPONSE_TIME_PROCESSOR);
                if(param)
                {
                    res_time_processor = axutil_param_get_value(param, env);
                    service_admin_response_time_processor_add_response_time(res_time_processor, env, 
                            response_time, src_count);
                }
                else
                {
                    axutil_allocator_switch_to_global_pool(env->allocator);
                    res_time_processor = service_admin_response_time_processor_create(env);
                    if(res_time_processor)
                    {
                        service_admin_response_time_processor_add_response_time(res_time_processor, env, 
                            response_time, src_count);
                        param = axutil_param_create(env, AXIS2_SERVICE_RESPONSE_TIME_PROCESSOR, 
                                res_time_processor);
                        axis2_svc_add_param(svc, env, param);
                    }
                    axutil_allocator_switch_to_local_pool(env->allocator);
                }
            }
            op = axis2_msg_ctx_get_op(msg_ctx, env);
            if(op)
            {
                axutil_param_t *param = NULL;
                axutil_param_t *op_req_counter_param = NULL;
                service_admin_response_time_processor_t *res_time_processor = NULL;
                service_admin_counter_t *counter = NULL;
                int op_req_count = 0;
               
                op_req_counter_param = axis2_op_get_param(op, env, AXIS2_IN_OPERATION_COUNTER);
                if(op_req_counter_param)
                {
                    counter = axutil_param_get_value(op_req_counter_param, env);
                    op_req_count = service_admin_counter_get_count(counter, env, msg_ctx);
                }
                param = axis2_op_get_param(op, env, AXIS2_OPERATION_RESPONSE_TIME_PROCESSOR);
                if(param)
                {
                    res_time_processor = axutil_param_get_value(param, env);
                    service_admin_response_time_processor_add_response_time(res_time_processor, env, 
                            response_time, op_req_count);
                }
                else
                {
                    axutil_allocator_switch_to_global_pool(env->allocator);
                    res_time_processor = service_admin_response_time_processor_create(env);
                    if(res_time_processor)
                    {
                        service_admin_response_time_processor_add_response_time(res_time_processor, env, 
                            response_time, op_req_count);
                        param = axutil_param_create(env, AXIS2_OPERATION_RESPONSE_TIME_PROCESSOR, 
                                res_time_processor);
                        axis2_op_add_param(op, env, param);
                    }
                    axutil_allocator_switch_to_local_pool(env->allocator);
                }
            }

        }
    }
    return status;
}

