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

axis2_status_t AXIS2_CALL
axis2_statistics_admin_svc_request_count_handler_invoke(
        struct axis2_handler *handler, 
        const axutil_env_t *env,
        struct axis2_msg_ctx *msg_ctx);


AXIS2_EXTERN axis2_handler_t* AXIS2_CALL
axis2_statistics_admin_svc_request_count_handler_create(
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
	axis2_handler_set_invoke(handler, env, axis2_statistics_admin_svc_request_count_handler_invoke);

    return handler;
}

axis2_status_t AXIS2_CALL
axis2_statistics_admin_svc_request_count_handler_invoke(struct axis2_handler *handler, 
                        const axutil_env_t *env,
                        struct axis2_msg_ctx *msg_ctx)
{
    axis2_status_t status = AXIS2_SUCCESS;
    service_admin_counter_t *counter = NULL;
    axutil_param_t *param = NULL;
    axis2_svc_t *svc = NULL;
    
    AXIS2_LOG_TRACE(env->log, AXIS2_LOG_SI, "[adminservices] Start:axis2_statistics_admin_svc_request_count_handler_invoke");
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);

    svc = axis2_msg_ctx_get_svc(msg_ctx, env);
    if(svc)
    {
        param = axis2_svc_get_param(svc, env, AXIS2_SERVICE_REQUEST_COUNTER);
        if(param)
        {
            counter = axutil_param_get_value(param, env);
            if(counter)
            {
                service_admin_counter_increment(counter, env, msg_ctx);
            }
        }
        else
        {
            const axis2_char_t *svc_name = NULL;

            svc_name = axis2_svc_get_name(svc, env);
            axutil_allocator_switch_to_global_pool(env->allocator);
            counter = service_admin_counter_create(env, svc_name, NULL);
            if(counter)
            {
                service_admin_counter_increment(counter, env, msg_ctx);
                param = axutil_param_create(env, AXIS2_SERVICE_REQUEST_COUNTER, counter);
                if(param)
                {
                    axis2_svc_add_param(svc, env, param);
                }
            }
            axutil_allocator_switch_to_local_pool(env->allocator);
        }
    }
    
    AXIS2_LOG_TRACE(env->log, AXIS2_LOG_SI, "[adminservices] End:axis2_statistics_admin_svc_request_count_handler_invoke");
    
    return status;
}

