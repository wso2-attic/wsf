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
#include <axis2_engine.h>
#include <axis2_svc.h>

#include <savan_constants.h>
#include <savan_error.h>
#include <savan_sub_processor.h>
#include <savan_util.h>
#include <savan_msg_recv.h>

/* Function Prototypes ********************************************************/

axis2_status_t AXIS2_CALL
savan_in_handler_invoke(struct axis2_handler *handler, 
                         const axutil_env_t *env,
                         struct axis2_msg_ctx *msg_ctx);


/* End of Function Prototypes *************************************************/

AXIS2_EXTERN axis2_handler_t* AXIS2_CALL
savan_in_handler_create(const axutil_env_t *env, 
                         axutil_qname_t *qname) 
{
    axis2_handler_t *handler = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    
    handler = axis2_handler_create(env);
    if (!handler)
    {
        return NULL;
    }
   
    /* Handler init is handled by conf loading, so no need to do it here */
    
    /* Set the base struct's invoke op */
	axis2_handler_set_invoke(handler, env, savan_in_handler_invoke);

    return handler;
}

/******************************************************************************/

axis2_status_t AXIS2_CALL
savan_in_handler_invoke(struct axis2_handler *handler, 
                         const axutil_env_t *env,
                         struct axis2_msg_ctx *msg_ctx)
{
    savan_message_types_t msg_type = SAVAN_MSG_TYPE_UNKNOWN;
    savan_sub_processor_t *processor = NULL;
    axis2_bool_t from_client = AXIS2_FALSE;
    const axis2_svc_t *svc = NULL;
    const axis2_char_t *svc_name = NULL;
    
    AXIS2_ENV_CHECK( env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);
    
    svc =  axis2_msg_ctx_get_svc(msg_ctx, env);
    if (svc)
        svc_name = axis2_svc_get_name(svc, env);
    
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[%s][savan][in handler] invoke",
        svc_name);
    
    /* create a subscription processor */
    processor = savan_sub_processor_create(env);
    if (!processor)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[savan] Failed to create "
            "subscription processor"); 
        /*AXIS2_ERROR_SET(env->error, SAVAN_ERROR_FAILED_TO_CREATE_SUB_PROCESSOR,
            AXIS2_FAILURE);
        return AXIS2_FAILURE;*/
        return AXIS2_SUCCESS; /* returning FAILURE will break handler chain */
    }
    
    /* determine the eventing msg type */
    msg_type = savan_util_get_message_type(msg_ctx, env);
    if (msg_type == SAVAN_MSG_TYPE_UNKNOWN)
    {
          /* not an error. just log it */
        AXIS2_LOG_INFO(env->log, "[savan][in handler] Unhandled message type"); 
        return AXIS2_SUCCESS;
    }
    
    /* now call the appropriate method of the subscription processor */
    if (msg_type == SAVAN_MSG_TYPE_SUB)
    {
        from_client = AXIS2_TRUE;
        savan_sub_processor_subscribe(processor, env, msg_ctx);
    }
    else if (msg_type == SAVAN_MSG_TYPE_UNSUB)
    {
        from_client = AXIS2_TRUE;
        savan_sub_processor_unsubscribe(processor, env, msg_ctx);
    }
    else if (msg_type == SAVAN_MSG_TYPE_RENEW)
    {
        from_client = AXIS2_TRUE;
        savan_sub_processor_renew_subscription(processor, env, msg_ctx);
    }
    else if (msg_type == SAVAN_MSG_TYPE_GET_STATUS)
    {
        from_client = AXIS2_TRUE;
        savan_sub_processor_get_status(processor, env, msg_ctx);
    }
     
    if (from_client) /* send reply to client */
    {
        axis2_op_t *op =  axis2_msg_ctx_get_op(msg_ctx, env);
        axis2_msg_recv_t* msg_recv = savan_msg_recv_create(env);
        axis2_op_set_msg_recv(op, env, msg_recv);
    }
    
    return AXIS2_SUCCESS;
}
