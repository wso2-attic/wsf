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

#include <axis2_disp.h>
#include <axis2_handler_desc.h>
#include <axutil_string.h>
#include <axis2_relates_to.h>
#include <axis2_svc.h>
#include <axis2_const.h>
#include <axis2_conf_ctx.h>
#include <axis2_addr.h>
#include <axutil_utils.h>

const axis2_char_t *AXIS2_REQ_URI_DISP_NAME = "request_uri_based_dispatcher";

axis2_status_t AXIS2_CALL
axis2_req_uri_disp_invoke(
    axis2_handler_t * handler,
    const axutil_env_t *env,
    struct axis2_msg_ctx *msg_ctx);

axis2_svc_t *AXIS2_CALL
axis2_req_uri_disp_find_svc(
    axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env);

axis2_op_t *AXIS2_CALL
axis2_req_uri_disp_find_op(
    axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env,
    axis2_svc_t *svc);


AXIS2_EXTERN axis2_disp_t *AXIS2_CALL
axis2_req_uri_disp_create(
    const axutil_env_t *env)
{
    axis2_disp_t *disp = NULL;
    axis2_handler_t *handler = NULL;
    axutil_string_t *name = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    name = axutil_string_create_const(env, 
               (axis2_char_t **)&AXIS2_REQ_URI_DISP_NAME);

    disp = axis2_disp_create(env, name);
    if (!disp)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    handler = axis2_disp_get_base(disp, env);
    if (!handler)
    {
        AXIS2_ERROR_SET(env->error,
                AXIS2_ERROR_INVALID_HANDLER_STATE, AXIS2_FAILURE);
        return NULL;
    }

    axis2_handler_set_invoke(handler, env, axis2_req_uri_disp_invoke);

    axutil_string_free(name, env);

    return disp;
}

axis2_svc_t *AXIS2_CALL
axis2_req_uri_disp_find_svc(
    axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    axis2_endpoint_ref_t *endpoint_ref = NULL;
    axis2_svc_t *svc = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    endpoint_ref =  axis2_msg_ctx_get_to(msg_ctx, env);

    if (endpoint_ref)
    {
        const axis2_char_t *address = NULL;

        address = axis2_endpoint_ref_get_address(endpoint_ref, env);
        if (address)
        {
            axis2_char_t **url_tokens = NULL;
            AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
                    "Checking for service using target endpoint address : %s",
                     address);

            url_tokens = axutil_parse_request_url_for_svc_and_op(env, address);

            if (url_tokens)
            {
                if (url_tokens[0])
                {
                    axis2_conf_ctx_t *conf_ctx = NULL;

                    conf_ctx =  axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
                    if (conf_ctx)
                    {
                        axis2_conf_t *conf = NULL;
                        conf =  axis2_conf_ctx_get_conf(conf_ctx, env);
                        if (conf)
                        {
                            svc = axis2_conf_get_svc(conf, env, url_tokens[0]);
                            if (svc)
                                AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
                                        "Service found using target endpoint address");
                        }
                    }
                    AXIS2_FREE(env->allocator, url_tokens[0]);
                }
                AXIS2_FREE(env->allocator, url_tokens);
                url_tokens = NULL;
            }
        }
    }

    return svc;
}

axis2_op_t *AXIS2_CALL
axis2_req_uri_disp_find_op(
    axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env,
    axis2_svc_t *svc)
{
    axis2_endpoint_ref_t *endpoint_ref = NULL;
    axis2_op_t *op = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, svc, NULL);

    endpoint_ref =  axis2_msg_ctx_get_to(msg_ctx, env);

    if (endpoint_ref)
    {
        const axis2_char_t *address = NULL;

        address = axis2_endpoint_ref_get_address(endpoint_ref, env);
        if (address)
        {
            axis2_char_t **url_tokens = NULL;

            url_tokens = axutil_parse_request_url_for_svc_and_op(env, address);

            if (url_tokens)
            {
                if (url_tokens[1])
                {
                    axutil_qname_t *op_qname = NULL;
                    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
                            "Checking for operation using \
                             target endpoint uri fragment : %s",
                             url_tokens[1]);
                    op_qname = axutil_qname_create(env, url_tokens[1], NULL, NULL);
                    op = axis2_svc_get_op_with_name(svc, env, 
                             axutil_qname_get_localpart(op_qname, env));
                    axutil_qname_free(op_qname, env);
                    if (op)
                        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
                                "Operation found using target endpoint uri fragment");
                }
                if (url_tokens[0])
                    AXIS2_FREE(env->allocator, url_tokens[0]);
                if (url_tokens[1])
                    AXIS2_FREE(env->allocator, url_tokens[1]);
                AXIS2_FREE(env->allocator, url_tokens);
            }
        }
    }

    return op;
}

axis2_status_t AXIS2_CALL
axis2_req_uri_disp_invoke(
    axis2_handler_t * handler,
    const axutil_env_t *env,
    struct axis2_msg_ctx *msg_ctx)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    axis2_msg_ctx_set_find_svc(msg_ctx, env, axis2_req_uri_disp_find_svc);
    axis2_msg_ctx_set_find_op(msg_ctx, env, axis2_req_uri_disp_find_op);
    return axis2_disp_find_svc_and_op(handler, env, msg_ctx);
}
