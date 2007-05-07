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
#include <rampart_replay_detector.h>
/*This method sets all the configurations
 loads required modules and start rampart.*/

rampart_context_t *AXIS2_CALL
get_rampart_context_with_secpolicy_from_om(
    rampart_context_t *rampart_context,
    const axutil_env_t *env);

rampart_context_t *AXIS2_CALL
build_rampart_context_from_file(
    const axutil_env_t *env,
    axis2_char_t *file_name);

rampart_context_t *AXIS2_CALL
get_rampart_context_in_server_side(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    const axis2_char_t *key);


AXIS2_EXTERN rampart_context_t* AXIS2_CALL
rampart_engine_init(const axutil_env_t *env,
                    axis2_msg_ctx_t *msg_ctx,
                    axis2_bool_t is_inflow)
{

    axis2_char_t *file_name = NULL;
    rampart_context_t *rampart_context = NULL;
    void *value = NULL;

    /*First we try to load the rampart_context*
     *This can be set from an extension like PHP
     So first extract it from such a scenario.*/

    if(is_inflow)
    {
        value = rampart_get_rampart_configuration(env,msg_ctx,INFLOW_RAMPART_CONTEXT);
        if(value)
        {
            /*We need a rampart_context*/
            rampart_context = (rampart_context_t *)value;
            if(!rampart_context)
            {
                AXIS2_LOG_INFO(env->log,"[rampart][rampart_engine] Type in the parameter is not rampart_context");
                return NULL;
            }
            /*We will build sec policy from the axiom representation of the policy. Used in PHP ext*/
            rampart_context = get_rampart_context_with_secpolicy_from_om(rampart_context,env);

        }else{
            /*For the performance we will first chk if we have a saved configuration in the conf ctx.[else block]
             *If not we will extract configurations from the descriptor files*/
            if(axis2_msg_ctx_get_server_side(msg_ctx,env)) {
                /*If the server side*/
                rampart_context =  get_rampart_context_in_server_side(env,msg_ctx,IN_MESSAGE_SECURITY);
            }else{
                value = rampart_get_rampart_configuration(env,msg_ctx,RAMPART_INFLOW_SECURITY_POLICY);
                if(!value){
                    AXIS2_LOG_INFO(env->log,"[rampart][rampart_engine] Errors in the configurations");
                    return NULL;
                }
                file_name = (axis2_char_t *)value;
                rampart_context =  build_rampart_context_from_file(env,file_name);
            }
        }
        /*We set our default impl of replay detection function*/
        rampart_context_set_replay_detect_function(rampart_context, env, rampart_replay_detector_default);
    }else{
        /*Outflow*/
        value = rampart_get_rampart_configuration(env,msg_ctx,OUTFLOW_RAMPART_CONTEXT);
        if(value)
        {
            rampart_context = (rampart_context_t *)value;
            if(!rampart_context)
            {
                AXIS2_LOG_INFO(env->log,"[rampart][rampart_engine] Type in the parameter is not rampart_context");
                return NULL;
            }
            rampart_context =  get_rampart_context_with_secpolicy_from_om(rampart_context,env);
        }else{
            if(axis2_msg_ctx_get_server_side(msg_ctx,env))
            {
                rampart_context = get_rampart_context_in_server_side(env,msg_ctx,OUT_MESSAGE_SECURITY);
            }
            else
            {
                value = rampart_get_rampart_configuration(env,msg_ctx,RAMPART_OUTFLOW_SECURITY_POLICY);
                if(!value)
                {
                    AXIS2_LOG_INFO(env->log,"[rampart][rampart_engine] Errors in the configurations");
                    return NULL;
                }
                file_name = (axis2_char_t *)value;
                rampart_context =  build_rampart_context_from_file(env,file_name);
            }
        }
    }

    return rampart_context;
}

rampart_context_t *AXIS2_CALL
get_rampart_context_with_secpolicy_from_om(
    rampart_context_t *rampart_context,
    const axutil_env_t *env)
{
    axiom_node_t *policy_node = NULL;
    rp_secpolicy_t *secpolicy = NULL;

    policy_node = rampart_context_get_policy_node(rampart_context,env);
    if(!policy_node)
    {
        AXIS2_LOG_INFO(env->log,"[rampart][rampart_engine] Policy node is null.");
        return NULL;
    }
    secpolicy = rp_policy_create_from_om_node(env,policy_node);
    if(!secpolicy)
    {
        AXIS2_LOG_INFO(env->log,"[rampart][rampart_engine] Cannot create policy from the node");
        return NULL;
    }
    rampart_context_set_secpolicy(rampart_context,env,secpolicy);
    return rampart_context;
}

rampart_context_t *AXIS2_CALL
build_rampart_context_from_file(
    const axutil_env_t *env,
    axis2_char_t *file_name)
{
    rp_secpolicy_t *secpolicy = NULL;
    rampart_context_t *rampart_context = NULL;
    rampart_callback_t* password_callback_module = NULL;
    rampart_authn_provider_t *authn_provider = NULL;
    axis2_char_t *pwcb_module_name = NULL;
    axis2_char_t *authn_provider_name = NULL;
    axis2_status_t status = AXIS2_SUCCESS;

    if(!file_name)
    {
        AXIS2_LOG_INFO(env->log,
                       "[rampart][rampart_Engine] No Security in the flow. So nothing to do");
        return NULL;
    }
    AXIS2_LOG_INFO(env->log, "[rampart][rampart_Engine] Trying to build rampart context from file %s ", file_name);

    secpolicy = rp_policy_create_from_file(env,file_name);

    if(!secpolicy)
    {
        AXIS2_LOG_INFO(env->log, "[rampart][rampart_Engine] Cannot get policy" );
        /*No policy so we cant proceed.*/
        return NULL;
    }
    rampart_context = rampart_context_create(env);

    if(!rampart_context)
    {
        AXIS2_LOG_INFO(env->log, "[rampart][rampart_Engine]System is out of memory. Cannot get Rampart Context ");
        /*No policy so we cant proceed.*/
        return NULL;
    }

    rampart_context_set_secpolicy(rampart_context,env,secpolicy);

    status = rampart_context_set_user_from_file(rampart_context,env);
    if(status!=AXIS2_SUCCESS)
        return NULL;

    status = rampart_context_set_ttl_from_file(rampart_context,env);
    if(status!=AXIS2_SUCCESS)
        return NULL;

    status = rampart_context_set_password_type_from_file(rampart_context,env);
    if(status!=AXIS2_SUCCESS)
        return NULL;

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
    return rampart_context;

}

rampart_context_t *AXIS2_CALL
get_rampart_context_in_server_side(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    const axis2_char_t *key)
{

    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_ctx_t *ctx = NULL;
    axutil_property_t *property = NULL;

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
    /*Possible Keys : IN_MESSAGE_SECURITY, OUT_MESSAGE_SECURITY*/
    property = axis2_ctx_get_property(ctx,env,key);
    if(property)
    {
        return (rampart_context_t *)axutil_property_get_value(property,env);
    }else{
        /*We cannot find the rampart_context as a property in axis2_ctx. Thus we need to create*/
        axis2_char_t *file_name = NULL;
        rampart_context_t *rampart_context = NULL;

        if(axutil_strcmp(key, IN_MESSAGE_SECURITY)==0)
        {
            file_name =(axis2_char_t *)rampart_get_rampart_configuration(env,msg_ctx,RAMPART_INFLOW_SECURITY_POLICY);
            if(file_name)
            {
                rampart_context = build_rampart_context_from_file(env,file_name);
                /*
                property = axutil_property_create(env);
                axutil_property_set_value(property,env,rampart_context);
                */
                
                property = axutil_property_create_with_args(env, AXIS2_SCOPE_APPLICATION,
                            AXIS2_FALSE, (void *)rampart_engine_shutdown, rampart_context );
                            
                axis2_ctx_set_property(ctx, env, key, property);
                return rampart_context;
            }
            else
            {
                AXIS2_LOG_INFO(env->log,"[rampart][rampart_engine] Errors in the configurations");
                return NULL;
            }
        }
        else if(axutil_strcmp(key,OUT_MESSAGE_SECURITY)==0)
        {
            file_name =(axis2_char_t *)rampart_get_rampart_configuration(env,msg_ctx,RAMPART_OUTFLOW_SECURITY_POLICY);
            if(file_name)
            {
                rampart_context = build_rampart_context_from_file(env,file_name);
                /*property = axutil_property_create(env);
                axutil_property_set_value(property,env,rampart_context);*/
                
                property = axutil_property_create_with_args(env, AXIS2_SCOPE_APPLICATION,
                                            AXIS2_FALSE, (void *)rampart_engine_shutdown, rampart_context );
                axis2_ctx_set_property(ctx,env,key,property);
                return rampart_context;
            }
            else
            {
                AXIS2_LOG_INFO(env->log,"[rampart][rampart_engine] Errors in the configurations");
                return NULL;
            }
        }
        else return NULL;
    }
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rampart_engine_shutdown(const axutil_env_t *env,
                        rampart_context_t *rampart_context)
{

    /*  rp_secpolicy_t *secpolicy = NULL;*/
    axis2_status_t status = AXIS2_FAILURE;

    /*  secpolicy = rampart_context_get_secpolicy(rampart_context,env);
        status = rp_secpolicy_free(secpolicy,env);
        secpolicy = NULL;
    */
    status = rampart_context_free(rampart_context,env);
    rampart_context = NULL;
    return status;
}
