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

/*
 *
 */

#include <rampart_engine.h>
#include <axis2_ctx.h>
#include <axis2_svc.h>
#include <axis2_desc.h>
#include <axis2_policy_include.h>
#include <rp_secpolicy_builder.h>
#include <neethi_policy.h>
#include <rampart_authn_provider.h>
#include <rampart_util.h>
#include <rampart_constants.h>
#include <rampart_callback.h>
#include <rampart_replay_detector.h>
#include <axis2_msg.h>
#include <axis2_conf_ctx.h>
#include <rampart_handler_util.h>

/*This method sets all the configurations
 loads required modules and start rampart.*/


neethi_policy_t *AXIS2_CALL
build_policy(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    axis2_bool_t is_inflow);


axis2_status_t AXIS2_CALL
set_rampart_user_properties(
    const axutil_env_t *env,
    rampart_context_t *rampart_context);



AXIS2_EXTERN rampart_context_t *AXIS2_CALL
rampart_engine_build_configuration(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    axis2_bool_t is_inflow)
{

    rp_secpolicy_t *secpolicy = NULL;
    rampart_context_t *rampart_context = NULL;
    axis2_status_t status = AXIS2_SUCCESS;
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_ctx_t *ctx = NULL;
    axis2_bool_t is_server_side = AXIS2_TRUE;
    neethi_policy_t *policy = NULL;
    axutil_property_t *property = NULL;
    void *value = NULL;

    is_server_side = axis2_msg_ctx_get_server_side(msg_ctx, env);

    if(is_server_side || !is_inflow)
    {
        policy = build_policy(env, msg_ctx, is_inflow);
        if(!policy)
        {
            AXIS2_LOG_INFO(env->log, "[rampart][engine] Policy Creation failed. ");
            return NULL;
        }
    }
    else
    {
        property = axis2_msg_ctx_get_property(msg_ctx, env, RAMPART_CONTEXT);
        if(property)
            return (rampart_context_t *)axutil_property_get_value(property, env);
        else
        {
            AXIS2_LOG_INFO(env->log, "[rampart][rampart_engine] Cannot get saved rampart_context");
            return NULL;
        }
    }

    secpolicy = rp_secpolicy_builder_build(env, policy);
    if(!secpolicy)
    {
        AXIS2_LOG_INFO(env->log, "[rampart][rampart_engine] Cannot create security policy from policy.");
        return NULL;
    }

    value = rampart_get_rampart_configuration(env, msg_ctx, RAMPART_CONFIGURATION);
    if(value)
    {
        rampart_context = (rampart_context_t *)value;
        rampart_context_set_secpolicy(rampart_context, env, secpolicy);
    }
    else
    {
        rampart_context = rampart_context_create(env);
        rampart_context_set_secpolicy(rampart_context, env, secpolicy);

        status = set_rampart_user_properties(env, rampart_context);
        if(status != AXIS2_SUCCESS)
        {
            AXIS2_LOG_INFO(env->log, "[rampart][engine] User property creation fails ");
            return NULL;
        }
    }

    if(!is_server_side)
    {
        conf_ctx =  axis2_msg_ctx_get_conf_ctx(msg_ctx,env);
        if(!conf_ctx)
        {
            AXIS2_LOG_INFO(env->log, "[rampart][engine] Conf context is NULL ");
            return NULL;
        }

        ctx = axis2_conf_ctx_get_base(conf_ctx,env);
        if(!ctx)
        {
            AXIS2_LOG_INFO(env->log, "[rampart][engine] axis2 context is NULL ");
            return NULL;
        }
        property = axutil_property_create_with_args(env, AXIS2_SCOPE_APPLICATION,
                   AXIS2_FALSE, (void *)rampart_context_free, rampart_context);
        axis2_ctx_set_property(ctx, env, RAMPART_CONTEXT, property);

    }
    else
    { /*Server side only*/
        /*We set our default impl of replay detection function*/
        if(is_inflow)
        {
            rampart_context_set_replay_detect_function(rampart_context, env, rampart_replay_detector_with_linked_list/*rampart_replay_detector_default*/);
        }
    }
    return rampart_context;
}


neethi_policy_t *AXIS2_CALL
build_policy(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    axis2_bool_t is_inflow)
{

    axis2_svc_t *svc = NULL;
    axis2_desc_t *desc = NULL;
    axis2_policy_include_t *policy_include = NULL;
    neethi_policy_t *service_policy = NULL;
    axis2_op_t *op = NULL;
    axis2_msg_t *msg = NULL;

    svc =  axis2_msg_ctx_get_svc(msg_ctx,env);
    if(!svc)
    {
        AXIS2_LOG_INFO(env->log, "[rampart][rampart_neethi] Service is NULL.");
        return NULL;
    }

    op = axis2_msg_ctx_get_op(msg_ctx, env);
    if(!op)
    {
        AXIS2_LOG_INFO(env->log, "[rampart][rampart_engine] Operation is NULL.");
        return NULL;
    }

    if(is_inflow)
    {
        msg = axis2_op_get_msg(op, env, "in");
    }
    else
    {
        msg = axis2_op_get_msg(op, env, "out");
    }

    if(!msg)
    {
        AXIS2_LOG_INFO(env->log, "[rampart][rampart_engine] Message is NULL.");
        return NULL;
    }

    /*desc = axis2_svc_get_base(svc, env);*/
    desc = axis2_msg_get_base(msg, env);
    if(!desc)
    {
        AXIS2_LOG_INFO(env->log, "[rampart][rampart_engine] axis2 description is NULL.");
        return NULL;
    }

    policy_include = axis2_desc_get_policy_include(desc, env);
    if(!policy_include)
    {
        AXIS2_LOG_INFO(env->log, "[rampart][rampart_engine] Policy include is NULL.");
        return NULL;
    }
    /*service_policy = axis2_policy_include_get_policy(policy_include, env);*/
    service_policy = axis2_policy_include_get_effective_policy(policy_include, env);

    if(!service_policy)
    {
        AXIS2_LOG_INFO(env->log, "[rampart][rampart_engine] Policy is NULL.");
        return NULL;
    }

    return service_policy;

}


axis2_status_t AXIS2_CALL
set_rampart_user_properties(
    const axutil_env_t *env,
    rampart_context_t *rampart_context)
{

    rampart_callback_t* password_callback_module = NULL;
    rampart_authn_provider_t *authn_provider = NULL;
    axis2_char_t *pwcb_module_name = NULL;
    axis2_char_t *authn_provider_name = NULL;
    axis2_status_t status = AXIS2_SUCCESS;

    status = rampart_context_set_user_from_file(rampart_context,env);
    if(status!=AXIS2_SUCCESS)
    {
        return AXIS2_FAILURE;
    }

    status = rampart_context_set_ttl_from_file(rampart_context,env);
    if(status!=AXIS2_SUCCESS)
    {
        return AXIS2_FAILURE;
    }

    status = rampart_context_set_rd_val_from_file(rampart_context,env);
    if(status!=AXIS2_SUCCESS)
    {
        return AXIS2_FAILURE;
    }

    status = rampart_context_set_password_type_from_file(rampart_context,env);
    if(status!=AXIS2_SUCCESS)
    {
        return AXIS2_FAILURE;
    }

    pwcb_module_name = rampart_context_get_password_callback_class(rampart_context,env);

    if(pwcb_module_name)
    {
        password_callback_module = rampart_load_pwcb_module(env,pwcb_module_name);
        if(password_callback_module)
            rampart_context_set_password_callback(rampart_context,env,password_callback_module);
    }
    authn_provider_name = rampart_context_get_authn_module_name(rampart_context,env);

    if(authn_provider_name)
    {
        authn_provider = rampart_load_auth_module(env,authn_provider_name);
        if(authn_provider)
            rampart_context_set_authn_provider(rampart_context,env,authn_provider);
    }
    return status;
}
