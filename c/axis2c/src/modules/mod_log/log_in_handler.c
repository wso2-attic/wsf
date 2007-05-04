/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
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
#include <axutil_array_list.h>
#include <axiom_soap_const.h>
#include <axiom_soap_envelope.h>
#include <axiom_soap_header.h>
#include <axiom_soap_header_block.h>
#include <axis2_op.h>
#include <axis2_msg_ctx.h>
#include <axis2_conf_ctx.h>
#include <axis2_msg_info_headers.h>
#include <axutil_property.h>

axis2_status_t AXIS2_CALL
axutil_log_in_handler_invoke(struct axis2_handler *handler, 
    const axutil_env_t *env,
    struct axis2_msg_ctx *msg_ctx);

AXIS2_EXTERN axis2_handler_t* AXIS2_CALL
axutil_log_in_handler_create(const axutil_env_t *env, 
    axutil_string_t *name) 
{
    axis2_handler_t *handler = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    
    handler = axis2_handler_create(env);
    if (!handler)
    {
        return NULL;
    }
   
    axis2_handler_set_invoke(handler, env, axutil_log_in_handler_invoke);

    return handler;
}


axis2_status_t AXIS2_CALL
axutil_log_in_handler_invoke(struct axis2_handler *handler, 
    const axutil_env_t *env,
    struct axis2_msg_ctx *msg_ctx)
{
    axiom_soap_envelope_t *soap_envelope = NULL;
    axiom_node_t *ret_node = NULL;

    AXIS2_ENV_CHECK( env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);
    
    AXIS2_LOG_INFO(env->log, "Starting logging in handler .........");
    
    soap_envelope =  axis2_msg_ctx_get_soap_envelope(msg_ctx, env);
    
    if (soap_envelope)
    {
        /* ensure SOAP buider state is in sync */
        axiom_soap_envelope_get_body(soap_envelope, env); 
        ret_node = axiom_soap_envelope_get_base_node(soap_envelope, env);

        if(ret_node)
        {
            axis2_char_t *om_str = NULL;
            om_str = axiom_node_to_string(ret_node, env);
            if(om_str)
            {
                AXIS2_LOG_INFO(env->log, "Input message: %s", om_str);
            }
        }
    }
    
    return AXIS2_SUCCESS;
}


