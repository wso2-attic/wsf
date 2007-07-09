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
 
#include <sandesha2_utils.h>
#include <sandesha2_constants.h>
#include <sandesha2_in_order_invoker.h>
#include <sandesha2_transport_sender.h>
#include <sandesha2_seq_property_mgr.h>
#include <sandesha2_error.h>
#include <sandesha2_sender.h>
#include <sandesha2_seq.h>
#include <sandesha2_seq_ack.h>
#include <sandesha2_ack_requested.h>
#include <sandesha2_close_seq.h>
#include <sandesha2_close_seq_res.h>
#include <sandesha2_polling_mgr.h>
#include <sandesha2_inmemory_storage_mgr.h>
#include <sandesha2_permanent_storage_mgr.h>
#include <axutil_string.h>
#include <axis2_conf.h>
#include <axutil_property.h>
#include <axiom_soap_body.h>
#include <axis2_options.h>
#include <axis2_msg_ctx.h>
#include <axis2_engine.h>
#include <axis2_transport_out_desc.h>
#include <axis2_transport_in_desc.h>
#include <axutil_qname.h>
#include <axis2_http_transport.h>
#include <axis2_addr.h>
#include <axiom_soap_header.h>
#include <axutil_param.h>
#include <stdlib.h>
#include <sys/timeb.h>


static axutil_array_list_t *
get_sorted_msg_no_list(
        const axutil_env_t *env,
        axis2_char_t *msg_no_str,
        axis2_char_t *delim);

static axutil_array_list_t *
sandesha2_utils_sort(
        const axutil_env_t *env,
        axutil_array_list_t *list);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_utils_remove_soap_body_part(const axutil_env_t *env, 
                        axiom_soap_envelope_t *envelope, axutil_qname_t *qname)
{
    axiom_soap_body_t *soap_body = NULL;
    axiom_node_t *body_node = NULL;
    axiom_node_t *body_rm_node = NULL;
    axiom_element_t *body_element = NULL;
    axiom_element_t *body_rm_element = NULL;
    
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, envelope, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, qname, AXIS2_FAILURE);
    
    soap_body = axiom_soap_envelope_get_body(envelope, env);
    if(!soap_body)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
            "[sandesha2]Soap envelope does not have a soap body");
        return AXIS2_FAILURE;
    }
    body_node = axiom_soap_body_get_base_node(soap_body, env);
    if(!body_node)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
            "[sandesha2]Soap body does not have a base node");
        return AXIS2_FAILURE;
    }
    body_element = axiom_node_get_data_element(body_node, env);
    if(!body_element)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
            "[sandesha2]Soap body node does not have a node element");
        return AXIS2_FAILURE;
    }
    body_rm_element = axiom_element_get_first_child_with_qname(body_element,
                            env, qname, body_node, &body_rm_node);
    if(body_rm_element)
    {
        axiom_node_detach(body_rm_node, env);
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN long AXIS2_CALL
sandesha2_utils_get_current_time_in_millis(
    const axutil_env_t *env)
{
    /*const long fixed_time = 1153918446;
    long millis = -1;*/
    long seconds = -1;
    struct timeb *tp = AXIS2_MALLOC(env->allocator, sizeof(struct timeb));
    ftime(tp);
    /* To prevent an overflow we substract a contstant from seconds value
     * This value is taken as 18.23.xx seconds on 26 Jul 2006
     *
     */
    seconds = tp->time;
    /*seconds -= fixed_time;
    seconds *= 1000;
    millis = tp->millitm;
    millis = millis + seconds;

    return millis;*/
    return seconds;
}

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
sandesha2_utils_get_rm_version(
    const axutil_env_t *env,
    axis2_char_t *key,
    sandesha2_storage_mgr_t *storage_mgr)
{
    sandesha2_seq_property_mgr_t *seq_prop_mgr = NULL;
    sandesha2_seq_property_bean_t *rm_version_bean = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, key, NULL);
    AXIS2_PARAM_CHECK(env->error, storage_mgr, NULL);
    
    seq_prop_mgr = sandesha2_storage_mgr_get_seq_property_mgr(
        storage_mgr, env);
    if(seq_prop_mgr)
        rm_version_bean = sandesha2_seq_property_mgr_retrieve(seq_prop_mgr, 
            env, key, SANDESHA2_SEQ_PROP_RM_SPEC_VERSION);
    if(!rm_version_bean)
        return NULL;
    return sandesha2_seq_property_bean_get_value(rm_version_bean, env);
}

AXIS2_EXTERN sandesha2_storage_mgr_t* AXIS2_CALL
sandesha2_utils_get_storage_mgr(
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    axis2_conf_t *conf)
{
    axis2_char_t *value = NULL;
    sandesha2_storage_mgr_t *storage_mgr = NULL;
    sandesha2_property_bean_t *prop_bean = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, conf_ctx, NULL);
    AXIS2_PARAM_CHECK(env->error, conf, NULL);
    
    axutil_allocator_switch_to_global_pool(env->allocator);
    prop_bean = (sandesha2_property_bean_t *)sandesha2_utils_get_property_bean(
        env, conf);
    if (prop_bean)
    {
        value = sandesha2_property_bean_get_storage_mgr(prop_bean, env);
    }
    
    if(value && (0 == axutil_strcmp(value, SANDESHA2_INMEMORY_STORAGE_MGR)))
        storage_mgr = sandesha2_utils_get_inmemory_storage_mgr(env, conf_ctx);
    else if (value && (0 == axutil_strcmp(value, SANDESHA2_PERMANENT_STORAGE_MGR)))
        storage_mgr = sandesha2_utils_get_permanent_storage_mgr(env, conf_ctx);
    else
    {
        axutil_allocator_switch_to_local_pool(env->allocator);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[sandesha2]Unknown storage manager");
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_UNKNOWN_STORAGE_MGR,
                        AXIS2_FAILURE);
        return NULL;
    }
    axutil_allocator_switch_to_local_pool(env->allocator);
    return storage_mgr;
}
                        
AXIS2_EXTERN axis2_char_t* AXIS2_CALL
sandesha2_utils_get_seq_property(
    const axutil_env_t *env,
    axis2_char_t *incoming_seq_id,
    axis2_char_t *name,
    sandesha2_storage_mgr_t *storage_mgr)
{
    sandesha2_seq_property_mgr_t *seq_prop_mgr = NULL;
    sandesha2_seq_property_bean_t *seq_prop_bean = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, incoming_seq_id, NULL);
    AXIS2_PARAM_CHECK(env->error, name, NULL);
    AXIS2_PARAM_CHECK(env->error, storage_mgr, NULL);
    
    seq_prop_mgr = sandesha2_storage_mgr_get_seq_property_mgr(
        storage_mgr, env);
    seq_prop_bean = sandesha2_seq_property_mgr_retrieve(seq_prop_mgr,
        env, incoming_seq_id, name);
    if(!seq_prop_bean)
        return NULL;
    return  sandesha2_seq_property_bean_get_value(seq_prop_bean, env);
}

AXIS2_EXTERN sandesha2_property_bean_t* AXIS2_CALL
sandesha2_utils_get_property_bean(
    const axutil_env_t *env,
    axis2_conf_t *conf)
{
    axutil_param_t *param = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, conf, NULL);
    
    param = axis2_conf_get_param(conf, env, SANDESHA2_SANDESHA_PROPERTY_BEAN);
    if(!param)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[sandesha2]Configuration not set");
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_CONFIGURATION_NOT_SET,
            AXIS2_FAILURE);
        return NULL;
    }
    return (sandesha2_property_bean_t*)axutil_param_get_value(param, env);
    
}

AXIS2_EXTERN axutil_array_list_t* AXIS2_CALL
sandesha2_utils_get_array_list_from_string(
    const axutil_env_t *env,
    axis2_char_t *str)
{
    axis2_char_t *dup_str = NULL;
    axis2_char_t *temp_str = NULL;
    axutil_array_list_t *ret = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    if(!str || 0 == axutil_strcmp("", str))
    {
        ret = axutil_array_list_create(env, AXIS2_ARRAY_LIST_DEFAULT_CAPACITY);
        return ret;
    }
    if(2 > axutil_strlen(str))
    {
        axis2_char_t *ret_str = NULL;

        ret_str = axutil_strcat(env, "[sandesha2]Invalid String Array", str, NULL);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, ret_str);
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_INVALID_STRING_ARRAY, 
            AXIS2_FAILURE);
        AXIS2_FREE(env->allocator, ret_str);
        return NULL;
    }
    /* remove the array markers - []  if present */
    if('[' == *str)
        temp_str = str + sizeof(axis2_char_t);
    else
    {
        axis2_char_t *ret_str = NULL;

        ret_str = axutil_strcat(env, "[sandesha2]Invalid String Array", str, NULL);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, ret_str);
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_INVALID_STRING_ARRAY, 
            AXIS2_FAILURE);
        AXIS2_FREE(env->allocator, ret_str);
        return NULL;
    }
    dup_str = axutil_strdup(env, temp_str);
    if(']' == dup_str[axutil_strlen(dup_str) - 1])
        dup_str[axutil_strlen(dup_str) - 1] = '\0';
    else
    {
        axis2_char_t *ret_str = NULL;

        ret_str = axutil_strcat(env, "[sandesha2]Invalid String Array", str, NULL);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, ret_str);
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_INVALID_STRING_ARRAY, 
            AXIS2_FAILURE);
        AXIS2_FREE(env->allocator, ret_str);
        return NULL;
    }
        
    ret = axutil_array_list_create(env, AXIS2_ARRAY_LIST_DEFAULT_CAPACITY);
    temp_str = NULL;
    temp_str = strtok(dup_str, ",");
    while(temp_str)
    {
        if(!sandesha2_utils_array_list_contains(env, ret, temp_str))
        {
            axis2_char_t *temp_element = axutil_strdup(env, temp_str);
            axutil_array_list_add(ret, env, temp_element);
        }
        temp_str = strtok(NULL, ",");
    }
    AXIS2_FREE(env->allocator, dup_str);
    return ret;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
sandesha2_utils_array_list_contains(
    const axutil_env_t *env,
    axutil_array_list_t *list,
    axis2_char_t *str)
{
    int i = 0;
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, list, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, str, AXIS2_FALSE);
    
    for(i = 0; i < axutil_array_list_size(list, env); i++)
    {
        axis2_char_t *element = axutil_array_list_get(list, env, i);
        if(element && 0 == axutil_strcmp(element, str))
            return AXIS2_TRUE;
    }
    return AXIS2_FAILURE;
}

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
sandesha2_utils_array_list_to_string(
        const axutil_env_t *env,
        axutil_array_list_t *list, 
        int type)
{
    axis2_char_t *list_str = NULL;
    int i = 0, size = 0;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, list, NULL);
    
    list_str = axutil_strdup(env, "[");
    size = axutil_array_list_size(list, env);
    for(i = 0; i < size; i++)
    {
        if(SANDESHA2_ARRAY_LIST_STRING == type)
        {
            axis2_char_t *element = axutil_array_list_get(list, env, i);
            if(0 == i)
                list_str = axutil_strcat(env, list_str, element, NULL);
            list_str = axutil_strcat(env, list_str, ",", element, NULL);
        }
        else if(SANDESHA2_ARRAY_LIST_LONG == type)
        {
            long *element = axutil_array_list_get(list, env, i);
            axis2_char_t value[32];
            sprintf(value, "%ld", *element);
            if(0 == i)
                list_str = axutil_strcat(env, list_str, value, NULL);
            list_str = axutil_strcat(env, list_str, ",", value, NULL);
        } 
    }
    list_str = axutil_strcat(env, list_str, "]", NULL);
    
    return list_str;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL                        
sandesha2_utils_start_invoker_for_seq(
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    axis2_char_t *seq_id)
{
    sandesha2_in_order_invoker_t *invoker = NULL;
    axutil_property_t *property = NULL;
    axis2_status_t status = AXIS2_FAILURE;
    
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, conf_ctx, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, seq_id, AXIS2_FAILURE);
    
    property = axis2_ctx_get_property(axis2_conf_ctx_get_base(conf_ctx, env),
        env, SANDESHA2_INVOKER);
    if(property)
        invoker = axutil_property_get_value(property, env);
    if(!invoker)
    {
        invoker = sandesha2_in_order_invoker_create(env);
        property = axutil_property_create_with_args(env, AXIS2_SCOPE_APPLICATION, 
            AXIS2_FALSE, (void *)sandesha2_in_order_invoker_free_void_arg, 
            invoker);
        axis2_ctx_set_property(axis2_conf_ctx_get_base(conf_ctx, env),
            env, SANDESHA2_INVOKER, property);
    }
    status = sandesha2_in_order_invoker_run_for_seq(invoker, env, conf_ctx, 
        seq_id);
    return status;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL                        
sandesha2_utils_start_sender_for_seq(
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    axis2_char_t *seq_id,
    const axis2_bool_t persistent)
{
    sandesha2_sender_t *sender = NULL;
    axutil_property_t *property = NULL;
    axis2_status_t status = AXIS2_FAILURE;
    
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, conf_ctx, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, seq_id, AXIS2_FAILURE);
    
    property = axis2_ctx_get_property(axis2_conf_ctx_get_base(conf_ctx, env),
                        env, SANDESHA2_SENDER);
    if(property)
        sender = axutil_property_get_value(property, env);
        
    if(!sender)
    {
        sender = sandesha2_sender_create(env);
        property = axutil_property_create_with_args(env, AXIS2_SCOPE_APPLICATION, 
            AXIS2_FALSE, (void *)sandesha2_sender_free_void_arg, sender);
        axis2_ctx_set_property(axis2_conf_ctx_get_base(conf_ctx, env),
                        env, SANDESHA2_SENDER, property);
    }
    status = sandesha2_sender_run_for_seq(sender, env, conf_ctx, seq_id, 
        persistent);
    return status;
}
 
AXIS2_EXTERN axis2_status_t AXIS2_CALL                        
sandesha2_utils_start_polling_mgr(
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    const axis2_char_t *internal_seq_id)
{
    sandesha2_polling_mgr_t *polling_mgr = NULL;
    axutil_property_t *property = NULL;
    axis2_status_t status = AXIS2_FAILURE;
    
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, conf_ctx, AXIS2_FAILURE);
    
    axutil_allocator_switch_to_global_pool(env->allocator);
    property = axis2_ctx_get_property(axis2_conf_ctx_get_base(conf_ctx, env),
        env, SANDESHA2_POLLING_MGR);
    if(property)
        polling_mgr = axutil_property_get_value(property, env);
       
    /* Assumes that if someone has set the polling_mgr, he must have already 
     * started it 
     */
    if(!polling_mgr)
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
            "[sandesha2] Starting the polling manager");
        polling_mgr = sandesha2_polling_mgr_create(env);
        property = axutil_property_create_with_args(env, 0, AXIS2_FALSE,
            (void *)sandesha2_polling_mgr_free_void_arg, polling_mgr);
        axis2_ctx_set_property(axis2_conf_ctx_get_base(conf_ctx, env),
            env, SANDESHA2_POLLING_MGR, property);
    }
    status = sandesha2_polling_mgr_start(polling_mgr, env, conf_ctx, 
        internal_seq_id);
    axutil_allocator_switch_to_local_pool(env->allocator);
    return status;
}
                   
                        
AXIS2_EXTERN axis2_char_t* AXIS2_CALL
sandesha2_utils_get_outgoing_internal_seq_id(
    const axutil_env_t *env,
    axis2_char_t *seq_id)
{
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, seq_id, NULL);
    
    return axutil_strcat(env, SANDESHA2_INTERNAL_SEQ_PREFIX, ":",
        seq_id, NULL);
}

AXIS2_EXTERN axis2_transport_out_desc_t* AXIS2_CALL
sandesha2_utils_get_transport_out(const axutil_env_t *env)
{
    axis2_transport_out_desc_t *out_desc = NULL;
    axis2_transport_sender_t *transport_sender = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    
    transport_sender = sandesha2_transport_sender_create(env);
    out_desc = axis2_transport_out_desc_create(env, AXIS2_TRANSPORT_ENUM_HTTP);
    axis2_transport_out_desc_set_sender(out_desc, env, transport_sender);
    return out_desc;
}

AXIS2_EXTERN sandesha2_storage_mgr_t* AXIS2_CALL
sandesha2_utils_get_inmemory_storage_mgr(
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx)
{
    axutil_property_t *property = NULL;
    axis2_ctx_t *ctx = axis2_conf_ctx_get_base(conf_ctx, env);
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, conf_ctx, NULL);
    
    property = axis2_ctx_get_property(ctx, env, SANDESHA2_INMEMORY_STORAGE_MGR);

    if(property && axutil_property_get_value(property, env))
    {
        sandesha2_storage_mgr_t *storage_mgr = NULL;
        storage_mgr = (sandesha2_storage_mgr_t*)axutil_property_get_value(
            property, env);
        return storage_mgr;
    }
    else
    {
        /* TODO we need to class load the proper storage mgr */
        sandesha2_storage_mgr_t *storage_mgr = 
            sandesha2_inmemory_storage_mgr_create(env, conf_ctx);
        property = axutil_property_create_with_args(env, AXIS2_SCOPE_APPLICATION,
            AXIS2_FALSE, (void *)sandesha2_storage_mgr_free_void_arg, storage_mgr);
        axis2_ctx_set_property(ctx, env, SANDESHA2_INMEMORY_STORAGE_MGR, 
            property);
        return storage_mgr;
    }
    return NULL;    
}

AXIS2_EXTERN sandesha2_storage_mgr_t* AXIS2_CALL
sandesha2_utils_get_permanent_storage_mgr(
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx)
{
    axutil_property_t *property = NULL;
    axis2_ctx_t *ctx = axis2_conf_ctx_get_base(conf_ctx, env);
    sandesha2_storage_mgr_t *storage_mgr = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, conf_ctx, NULL);
   
    property = axis2_ctx_get_property(ctx, env, SANDESHA2_PERMANENT_STORAGE_MGR);
    if(property)
        storage_mgr = axutil_property_get_value(property, env);
    else
        storage_mgr = sandesha2_permanent_storage_mgr_create(env, conf_ctx);
    property = axutil_property_create_with_args(env, AXIS2_SCOPE_APPLICATION, 
        AXIS2_FALSE, 0, storage_mgr);
    axis2_ctx_set_property(ctx, env, SANDESHA2_PERMANENT_STORAGE_MGR, 
        property);
    return storage_mgr;
}

AXIS2_EXTERN axis2_char_t* AXIS2_CALL                       
sandesha2_utils_get_svr_side_incoming_seq_id(const axutil_env_t *env,
                        axis2_char_t *incoming_seq_id)
{
    axis2_char_t *start_str = NULL;
    axis2_char_t *ret = NULL;
    int start_len = 0;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, incoming_seq_id, NULL);
    
    start_str = axutil_strcat(env, SANDESHA2_INTERNAL_SEQ_PREFIX, ":", NULL);
    start_len = axutil_strlen(start_str);
    if(0 != axutil_strncmp(incoming_seq_id, start_str, start_len))
        return NULL;
    ret = axutil_strdup(env, (incoming_seq_id + start_len * sizeof(axis2_char_t)));
    
    return ret;    
}


AXIS2_EXTERN sandesha2_property_bean_t* AXIS2_CALL
sandesha2_utils_get_property_bean_from_op(
    const axutil_env_t *env,
    axis2_op_t *op)
{
        axutil_param_t *param = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, op, NULL);
    
    param = axis2_op_get_param(op, env, SANDESHA2_SANDESHA_PROPERTY_BEAN);
    if(!param)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
            "[sandesha2]Configuration not set.");
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_CONFIGURATION_NOT_SET,
            AXIS2_FAILURE);
        return NULL;
    }
    return (sandesha2_property_bean_t*)axutil_param_get_value(param, env);

}

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
sandesha2_utils_get_internal_seq_id(
    const axutil_env_t *env,
    axis2_char_t *to,
    axis2_char_t *seq_key)
{
    axis2_char_t *ret = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    if(!to && !seq_key)
    {
        return NULL;
    }
    else if(!to)
    {
        return axutil_strdup(env, seq_key);
    }
    else if(!seq_key)
    {
        return axutil_strdup(env, to);
    }
    else
    {
        ret = axutil_strcat(env, SANDESHA2_INTERNAL_SEQ_PREFIX, ":", to, ":", 
            seq_key, NULL);
        return ret;
    }
    return NULL;
}

AXIS2_EXTERN axis2_msg_ctx_t *AXIS2_CALL
sandesha2_utils_create_new_related_msg_ctx(
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *ref_rm_msg,
    axis2_op_t *op)
{
    axis2_msg_ctx_t *ref_msg = NULL;
    axis2_msg_ctx_t *new_msg = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_conf_t *conf = NULL;
    axis2_transport_out_desc_t *out_desc = NULL;
    axis2_transport_in_desc_t *in_desc = NULL;
    axis2_options_t *options = NULL;
    axis2_svc_t *svc = NULL;
    axis2_op_ctx_t *op_ctx = NULL;
    axiom_soap_envelope_t *soap_env = NULL;
    axutil_property_t *property = NULL;
    axis2_char_t *addr_ver = NULL;
    axis2_char_t *paused_phase_name = NULL;
    axis2_svc_grp_t *svc_grp = NULL;
    axutil_stream_t *out_stream = NULL;
    axis2_char_t *transport_to = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, ref_rm_msg, NULL);
    AXIS2_PARAM_CHECK(env->error, op, NULL);
    
    ref_msg = sandesha2_msg_ctx_get_msg_ctx(ref_rm_msg, env);
    conf_ctx = axis2_msg_ctx_get_conf_ctx(ref_msg, env);
    conf = axis2_conf_ctx_get_conf(conf_ctx, env);
    
    out_desc = axis2_msg_ctx_get_transport_out_desc(ref_msg, env);
    in_desc = axis2_msg_ctx_get_transport_in_desc(ref_msg, env);
    
    new_msg = axis2_msg_ctx_create(env, conf_ctx, in_desc, out_desc);
       
    options = axis2_options_create(env);
    axis2_msg_ctx_set_options(new_msg, env, options);
    svc_grp = axis2_msg_ctx_get_svc_grp(ref_msg, env); 
    if(svc_grp)
    {
        axis2_svc_grp_ctx_t *svc_grp_ctx = NULL;
        axis2_msg_ctx_set_svc_grp(new_msg, env, svc_grp);
        svc_grp_ctx = axis2_msg_ctx_get_svc_grp_ctx(ref_msg, env);
        if(svc_grp_ctx)
        {
            axis2_msg_ctx_set_svc_grp_ctx(new_msg, env, svc_grp_ctx); 
        }
        else
        {
            axis2_svc_grp_ctx_t *svc_grp_ctx = NULL;
            svc_grp_ctx = axis2_svc_grp_ctx_create(env, 
                        axis2_msg_ctx_get_svc_grp(ref_msg, env), conf_ctx);
            axis2_msg_ctx_set_svc_grp_ctx(new_msg, env, svc_grp_ctx);
        }
    }
    else
    {
        axis2_svc_grp_t *svc_grp = NULL;
        axis2_svc_grp_ctx_t *svc_grp_ctx = NULL;
        
        svc_grp = axis2_svc_grp_create_with_conf(env, conf);
        svc_grp_ctx = axis2_svc_grp_ctx_create(env, svc_grp, conf_ctx);
        axis2_msg_ctx_set_svc_grp(new_msg, env, svc_grp);
        axis2_msg_ctx_set_svc_grp_ctx(new_msg, env, svc_grp_ctx);
    }

    if(axis2_msg_ctx_get_svc(ref_msg, env))
    {
        axis2_msg_ctx_set_svc_grp(new_msg, env, (axis2_svc_grp_t *)
            axis2_msg_ctx_get_svc(ref_msg, env));
        if(axis2_msg_ctx_get_svc_ctx(ref_msg, env))
        {
            axis2_msg_ctx_set_svc_ctx(new_msg, env, 
                        axis2_msg_ctx_get_svc_ctx(ref_msg, env));
            axis2_msg_ctx_set_svc_ctx_id(new_msg, env, 
                        axis2_msg_ctx_get_svc_ctx_id(ref_msg, env));
        }
        else
        {
            axis2_svc_ctx_t *svc_ctx =  NULL;
            svc_ctx = axis2_svc_ctx_create(env, 
                        axis2_msg_ctx_get_svc(ref_msg, env),
                        axis2_msg_ctx_get_svc_grp_ctx(new_msg, env));
            axis2_msg_ctx_set_svc_ctx(new_msg, env, svc_ctx);
        }
    }
    else
    {
        axis2_svc_t *axis_svc = NULL;
        axutil_qname_t *svc_qname = NULL;
        axis2_svc_grp_t *svc_grp = NULL;
        axis2_svc_ctx_t *svc_ctx = NULL;
        axis2_svc_grp_ctx_t *svc_grp_ctx = NULL;
        
        svc_qname = axutil_qname_create(env, "AnonymousRMService", NULL, NULL);
        axis_svc = axis2_svc_create_with_qname(env, svc_qname);
        
        svc_grp = axis2_msg_ctx_get_svc_grp(new_msg, env);
        axis2_svc_set_parent(axis_svc, env, axis2_msg_ctx_get_svc_grp(new_msg,
                        env));
         axis2_svc_grp_add_svc(svc_grp, env, axis_svc);
        svc_grp_ctx = axis2_msg_ctx_get_svc_grp_ctx(new_msg, env);
        svc_ctx = axis2_svc_ctx_create(env, axis_svc, svc_grp_ctx);
    }
    axis2_msg_ctx_set_op(new_msg, env, op);
    svc = axis2_msg_ctx_get_svc(new_msg, env);
    
    if(svc && op)
    {
        axis2_svc_add_op(svc, env, op);
        axis2_op_set_parent(op, env, svc);
    }
    
    axutil_allocator_switch_to_global_pool(env->allocator);
    op_ctx = axis2_op_ctx_create(env, op, axis2_msg_ctx_get_svc_ctx(new_msg, 
        env));
    axutil_allocator_switch_to_local_pool(env->allocator);
    axis2_msg_ctx_set_op_ctx(new_msg, env, op_ctx);
     axis2_op_ctx_add_msg_ctx(op_ctx, env, new_msg);
    
    soap_env = axiom_soap_envelope_create_default_soap_envelope(env, 
                        sandesha2_utils_get_soap_version(env, 
                        axis2_msg_ctx_get_soap_envelope(ref_msg, env)));
    axis2_msg_ctx_set_soap_envelope(new_msg, env, soap_env);
    
    transport_to = axis2_msg_ctx_get_transport_url(ref_msg, env);
    if(transport_to)
    {
        axis2_msg_ctx_set_transport_url(new_msg, env, transport_to);
    }
    property = axis2_msg_ctx_get_property(ref_msg, env, AXIS2_WSA_VERSION);
    if(!property)
    {
        axis2_msg_ctx_t *req_msg = NULL;
        axis2_op_ctx_t *op_ctx = axis2_msg_ctx_get_op_ctx(ref_msg, env);
        
        req_msg =  axis2_op_ctx_get_msg_ctx(op_ctx, env, AXIS2_WSDL_MESSAGE_LABEL_IN);
        if(req_msg)
        {
            property = axis2_msg_ctx_get_property(req_msg, env, 
                        AXIS2_WSA_VERSION);
            if(property)
                addr_ver = axutil_property_get_value(property, env);
        }
    }
    else
    {
        addr_ver = axutil_property_get_value(property, env);
    }
    property = axutil_property_create_with_args(env, 0, 0, 0, addr_ver);
    axis2_msg_ctx_set_property(new_msg, env, AXIS2_WSA_VERSION, property);
    
    out_stream = axis2_msg_ctx_get_transport_out_stream(ref_msg, 
        env);
    axis2_msg_ctx_set_transport_out_stream(new_msg, env, out_stream);
    property = axis2_msg_ctx_get_property(ref_msg, env, 
        AXIS2_TRANSPORT_IN);
    if(property)
        axis2_msg_ctx_set_property(new_msg, env, AXIS2_TRANSPORT_IN, 
            axutil_property_clone(property, env));
    property = axis2_msg_ctx_get_property(ref_msg, env, 
        AXIS2_HTTP_OUT_TRANSPORT_INFO);
    if(property)
        axis2_msg_ctx_set_property(new_msg, env, AXIS2_HTTP_OUT_TRANSPORT_INFO, 
            axutil_property_clone(property, env));
    axis2_msg_ctx_set_http_out_transport_info(new_msg, env, 
        axis2_msg_ctx_get_http_out_transport_info(ref_msg, env));
    property = axis2_msg_ctx_get_property(ref_msg, env, 
        AXIS2_TRANSPORT_HEADERS);
    if(property)
        axis2_msg_ctx_set_property(new_msg, env, AXIS2_TRANSPORT_HEADERS, 
            axutil_property_clone(property, env));
    axis2_msg_ctx_set_execution_chain(new_msg, env, 
        axis2_msg_ctx_get_execution_chain(ref_msg, env));
    paused_phase_name = (axis2_char_t*)axis2_msg_ctx_get_paused_phase_name(
        ref_msg, env);
    axis2_msg_ctx_set_paused_phase_name(new_msg, env, paused_phase_name);

    return new_msg;
}

AXIS2_EXTERN  int AXIS2_CALL
sandesha2_utils_get_soap_version(
    const axutil_env_t *env, 
    axiom_soap_envelope_t *envelope)
{
    AXIS2_ENV_CHECK(env, -1);
    AXIS2_PARAM_CHECK(env->error, envelope, -1);
    
    return axiom_soap_envelope_get_soap_version(envelope, env);
}

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
sandesha2_utils_trim_string(
    const axutil_env_t *env, 
    axis2_char_t *orig_str)
{
    axis2_char_t *tmp = NULL;
    axis2_char_t *tmp2 = NULL;
    axis2_char_t *ret = NULL;
    int len = 0;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, orig_str, NULL);
    
    tmp = orig_str;
    while(' ' == *tmp)
        tmp++;
        
    tmp2 = orig_str + axutil_strlen(orig_str);
    while(' ' == *tmp2 && tmp2 != orig_str)
        tmp2--;
        
    len = tmp2 - tmp;
    if(len > 0)
        ret = AXIS2_MALLOC(env->allocator, len + sizeof(axis2_char_t));
        
    memcpy(ret, tmp, len);
    ret[len] = '\0';
    return ret;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL                        
sandesha2_utils_is_retrievable_on_faults(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    axis2_bool_t ret = AXIS2_FALSE;
    axis2_char_t *action = NULL;
    
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FALSE);
    
    action =  (axis2_char_t*)axis2_msg_ctx_get_wsa_action(msg_ctx, env);
    if(!action)
        return AXIS2_FALSE;
        
    if(0 == axutil_strcmp(action, SANDESHA2_SPEC_2005_02_ACTION_CREATE_SEQ))
        ret = AXIS2_TRUE;
    else if(0 == axutil_strcmp(action, SANDESHA2_SPEC_2006_08_ACTION_CREATE_SEQ))
        ret = AXIS2_TRUE;
        
    return ret;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
sandesha2_utils_is_rm_global_msg(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    axis2_bool_t is_global_msg = AXIS2_FALSE;
    axis2_char_t *action = NULL;
    axiom_soap_envelope_t *soap_env = NULL;
    axiom_soap_header_t *soap_header = NULL;
    axiom_element_t *header_element = NULL;
    axiom_node_t *header_node = NULL;
    axiom_element_t *seq_element = NULL;
    axiom_node_t *seq_node = NULL;
    axutil_qname_t *qname = NULL;
    
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FALSE);
    
    action = (axis2_char_t*)axis2_msg_ctx_get_wsa_action(msg_ctx, env);
    soap_env = axis2_msg_ctx_get_soap_envelope(msg_ctx, env);
    
    if(!soap_env)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[sandesha2] SOAP envelope is"
            " NULL");
        return AXIS2_FALSE;
    }
    soap_header = axiom_soap_envelope_get_header(soap_env, env);
    
    if(soap_header)
    {
        header_node = axiom_soap_header_get_base_node(soap_header, env);
        header_element = axiom_node_get_data_element(header_node, env);
    
        qname = axutil_qname_create(env, SANDESHA2_WSRM_COMMON_SEQ,
                        SANDESHA2_SPEC_2005_02_NS_URI, NULL);
        seq_element = axiom_element_get_first_child_with_qname(header_element, 
                        env, qname, header_node, &seq_node);
        if(!seq_element)
        {
            qname = axutil_qname_create(env, SANDESHA2_WSRM_COMMON_SEQ,
                        SANDESHA2_SPEC_2006_08_NS_URI, NULL);
            seq_element = axiom_element_get_first_child_with_qname(
                        header_element, env, qname, header_node, &seq_node);
        }
    }
    if(seq_element)
        is_global_msg = AXIS2_TRUE;
        
    if(0 == axutil_strcmp(action, 
                        SANDESHA2_SPEC_2005_02_ACTION_SEQ_ACKNOWLEDGEMENT))
        is_global_msg = AXIS2_TRUE;
        
    if(0 == axutil_strcmp(action, 
                        SANDESHA2_SPEC_2005_02_ACTION_CREATE_SEQ_RESPONSE))
        is_global_msg = AXIS2_TRUE;
        
    if(0 == axutil_strcmp(action, SANDESHA2_SPEC_2005_02_ACTION_TERMINATE_SEQ))
        is_global_msg = AXIS2_TRUE;    
        
    if(0 == axutil_strcmp(action, 
                        SANDESHA2_SPEC_2006_08_ACTION_SEQ_ACKNOWLEDGEMENT))
        is_global_msg = AXIS2_TRUE;
        
    if(0 == axutil_strcmp(action, 
                        SANDESHA2_SPEC_2006_08_ACTION_CREATE_SEQ_RESPONSE))
        is_global_msg = AXIS2_TRUE;
        
    if(0 == axutil_strcmp(action, SANDESHA2_SPEC_2006_08_ACTION_TERMINATE_SEQ))
        is_global_msg = AXIS2_TRUE;    
    
    return is_global_msg;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
sandesha2_utils_get_seq_id_from_rm_msg_ctx(
    const axutil_env_t *env, 
    sandesha2_msg_ctx_t *rm_msg_ctx)
{
    int msg_type = -1;
    axis2_char_t *seq_id = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, rm_msg_ctx, NULL);
    
    msg_type = sandesha2_msg_ctx_get_msg_type(rm_msg_ctx, env);
    
    if(SANDESHA2_MSG_TYPE_APPLICATION == msg_type)
    {
        sandesha2_seq_t *seq = NULL;
        seq = (sandesha2_seq_t*)sandesha2_msg_ctx_get_msg_part(rm_msg_ctx, env,
                        SANDESHA2_MSG_PART_SEQ);
        seq_id = sandesha2_identifier_get_identifier(
                        sandesha2_seq_get_identifier(seq, env), env);
    }
    else if(SANDESHA2_MSG_TYPE_ACK == msg_type)
    {
        sandesha2_seq_ack_t *seq_ack = NULL;
        seq_ack = (sandesha2_seq_ack_t*)sandesha2_msg_ctx_get_msg_part(
                        rm_msg_ctx, env, SANDESHA2_MSG_PART_SEQ_ACKNOWLEDGEMENT);
        seq_id = sandesha2_identifier_get_identifier(
                        sandesha2_seq_ack_get_identifier(seq_ack, env), env);
    }
    else if(SANDESHA2_MSG_TYPE_ACK_REQUEST == msg_type)
    {
        sandesha2_ack_requested_t *ack_requested = NULL;
        ack_requested = (sandesha2_ack_requested_t*)
                        sandesha2_msg_ctx_get_msg_part(rm_msg_ctx, env, 
                        SANDESHA2_MSG_PART_ACK_REQUEST);
        seq_id = sandesha2_identifier_get_identifier(
                        sandesha2_ack_requested_get_identifier(ack_requested, 
                        env), env);
    }
    else if(SANDESHA2_MSG_TYPE_CLOSE_SEQ == msg_type)
    {
        sandesha2_close_seq_t *close_seq = NULL;
        close_seq = (sandesha2_close_seq_t*)
                        sandesha2_msg_ctx_get_msg_part(rm_msg_ctx, env, 
                        SANDESHA2_MSG_PART_CLOSE_SEQ);
        seq_id = sandesha2_identifier_get_identifier(
                        sandesha2_close_seq_get_identifier(close_seq, 
                        env), env);
    }
    else if(SANDESHA2_MSG_TYPE_CLOSE_SEQ_RESPONSE == msg_type)
    {
        sandesha2_close_seq_res_t *close_seq_res = NULL;
        close_seq_res = (sandesha2_close_seq_res_t*)
                        sandesha2_msg_ctx_get_msg_part(rm_msg_ctx, env, 
                        SANDESHA2_MSG_PART_CLOSE_SEQ_RESPONSE);
        seq_id = sandesha2_identifier_get_identifier(
                        sandesha2_close_seq_res_get_identifier(close_seq_res, 
                        env), env);
    }
    return seq_id;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_utils_stop_invoker(
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, conf_ctx, AXIS2_FAILURE);
    
    /*TODO */
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_utils_stop_sender(
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, conf_ctx, AXIS2_FAILURE);
    
    /*TODO */
    return AXIS2_SUCCESS;
}
 
AXIS2_EXTERN axis2_status_t AXIS2_CALL                        
sandesha2_utils_stop_polling_mgr(
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx)
{
    sandesha2_polling_mgr_t *polling_mgr = NULL;
    axutil_property_t *property = NULL;
    
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, conf_ctx, AXIS2_FAILURE);
    
    property = axis2_ctx_get_property(axis2_conf_ctx_get_base(conf_ctx, env),
                        env, SANDESHA2_POLLING_MGR);
    if(property)
        polling_mgr = axutil_property_get_value(property, env);
       
    if(polling_mgr)
    {
        sandesha2_polling_mgr_stop_polling(polling_mgr, env);
    }
    return AXIS2_SUCCESS;
}
                 
/**
 * Used to convert a message number list (a comma seperated list of message
 * numbers) into a set of Acknowledgement Ranges. This breaks the list, sort
 * the items and group them to create the ack_range objects.
 * 
 * @param msg_no_str
 * @return
 */
AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
sandesha2_utils_get_ack_range_list(
    const axutil_env_t *env,
    axis2_char_t *msg_no_str,
    axis2_char_t *rm_ns_value)
{
    axutil_array_list_t *ack_ranges = NULL;
    axutil_array_list_t *sorted_msg_no_list = NULL;
    int i = 0, size = 0;
    long lower = 0;
    long upper = 0;
    axis2_bool_t completed = AXIS2_TRUE;

    ack_ranges = axutil_array_list_create(env, 0);
    sorted_msg_no_list = get_sorted_msg_no_list(env, msg_no_str, ",");
    if(sorted_msg_no_list)
        size = axutil_array_list_size(sorted_msg_no_list, env);
    for(i = 0; i < size; i++)
    {
        long *temp = axutil_array_list_get(sorted_msg_no_list, env, i);
        if(lower == 0)
        {
            lower = *temp;
            upper = *temp;
            completed = AXIS2_FALSE;
        }
        else if(*temp == (upper + 1))
        {
            upper = *temp;
            completed = AXIS2_FALSE;
        }
        else
        {
             sandesha2_ack_range_t *ack_range = NULL;
             
             ack_range = sandesha2_ack_range_create(env, rm_ns_value, NULL);
             sandesha2_ack_range_set_lower_value(ack_range, env, lower);
             sandesha2_ack_range_set_upper_value(ack_range, env, upper);
             axutil_array_list_add(ack_ranges, env, ack_range);
             lower = *temp;
             upper = *temp;
             completed = AXIS2_FALSE;
        }
    }
    if(!completed)
    {
         sandesha2_ack_range_t *ack_range = NULL;
         
         ack_range = sandesha2_ack_range_create(env, rm_ns_value, NULL);
         sandesha2_ack_range_set_lower_value(ack_range, env, lower);
         sandesha2_ack_range_set_upper_value(ack_range, env, upper);
         axutil_array_list_add(ack_ranges, env, ack_range);
         completed = AXIS2_TRUE;
    }
    /*axutil_array_list_free(sorted_msg_no_list, env);*/
    return ack_ranges;
}

static axutil_array_list_t *
get_sorted_msg_no_list(
    const axutil_env_t *env,
    axis2_char_t *msg_no_str,
    axis2_char_t *delim)
{
    axutil_array_list_t *msg_numbers = NULL;
    axutil_array_list_t *sorted_msg_no_list = NULL;
    axis2_char_t *dup_str = NULL;
    axis2_char_t *temp_str = NULL;

    dup_str = axutil_strdup(env, msg_no_str);
    msg_numbers = axutil_array_list_create(env, 0);
    temp_str = strtok(dup_str, delim);
    while(temp_str)
    {
        long *long_val = AXIS2_MALLOC(env->allocator, sizeof(long));

        *long_val = atol(temp_str);
        axutil_array_list_add(msg_numbers, env, long_val);
        temp_str = strtok(NULL, delim);
    }
    sorted_msg_no_list = sandesha2_utils_sort(env, msg_numbers);
    /*axutil_array_list_free(msg_numbers, env);*/
    AXIS2_FREE(env->allocator, dup_str);
    return sorted_msg_no_list;
}

static axutil_array_list_t *
sandesha2_utils_sort(
    const axutil_env_t *env,
    axutil_array_list_t *list)
{
    axutil_array_list_t *sorted_list = NULL;
    long max = 0;
    int i = 0, size = 0;
    long j = 0;
    
    sorted_list = axutil_array_list_create(env, 0);
    if(list)
        size = axutil_array_list_size(list, env);
    for(i = 0; i < size; i++)
    {
        long *temp_long = NULL;

        temp_long = (long *) axutil_array_list_get(list, env, i);
        if(*temp_long > max)
            max = *temp_long;
    }
    for(j = 1; j <= max; j++)
    {
        long *temp = AXIS2_MALLOC(env->allocator, sizeof(long));
        axis2_bool_t contains = AXIS2_FALSE;
        
        *temp = j;
        for(i = 0; i < size; i++)
        {
            long *value = NULL;
            value = axutil_array_list_get(list, env, i);
            if(*value == *temp)
            {
                contains = AXIS2_TRUE;
                break;
            }
        }
        if(contains)
        {
            axutil_array_list_add(sorted_list, env, temp);
        }
    }
    return sorted_list;    
}

axis2_bool_t AXIS2_CALL
sandesha2_utils_is_all_msgs_acked_upto(
    const axutil_env_t *env,
    long highest_in_msg_no,
    axis2_char_t *internal_seq_id,
    sandesha2_storage_mgr_t *storage_mgr)
{
    axis2_char_t *client_completed_msgs = NULL;
    axutil_array_list_t *acked_msgs_list = NULL;
    long smallest_msg_no = 1;
    long temp_msg_no = 0;

    client_completed_msgs = sandesha2_utils_get_seq_property(env, 
        internal_seq_id, SANDESHA2_SEQ_PROP_CLIENT_COMPLETED_MESSAGES, 
        storage_mgr);
    acked_msgs_list = sandesha2_utils_get_array_list_from_string(env, 
        client_completed_msgs);
    for(temp_msg_no = smallest_msg_no; temp_msg_no <= highest_in_msg_no; 
        temp_msg_no++)
    {
        axis2_char_t str_msg_no[32];
        sprintf(str_msg_no, "%ld", temp_msg_no);
        if(!sandesha2_utils_array_list_contains(env, acked_msgs_list, 
            str_msg_no))
        {
            return AXIS2_FALSE;
        }
    }
    return AXIS2_TRUE; /* All messages upto the highest have been acked */
}

axis2_status_t AXIS2_CALL
sandesha2_utils_execute_and_store(
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *rm_msg_ctx,
    axis2_char_t *storage_key)
{
    axis2_msg_ctx_t *msg_ctx = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_transport_out_desc_t *transport_out = NULL;
    axis2_transport_out_desc_t *sandesha2_transport_out = NULL;
    axutil_property_t *property = NULL;
    axis2_engine_t *engine = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    msg_ctx = sandesha2_msg_ctx_get_msg_ctx(rm_msg_ctx, env);
    if(msg_ctx)
        conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
    sandesha2_msg_ctx_set_msg_type(rm_msg_ctx, env, 
        SANDESHA2_MSG_TYPE_CREATE_SEQ);
    /* Message will be stored in the sandesha2_transport_sender */
    property = axutil_property_create_with_args(env, AXIS2_SCOPE_REQUEST,
        AXIS2_FALSE, 0, storage_key);
    axis2_msg_ctx_set_property(msg_ctx, env, SANDESHA2_MESSAGE_STORE_KEY, 
        property);
    
    transport_out = axis2_msg_ctx_get_transport_out_desc(msg_ctx, env);
    property = axutil_property_create_with_args(env, 3, 0, 
        axis2_transport_out_desc_free_void_arg, transport_out);
    axis2_msg_ctx_set_property(msg_ctx, env, 
        SANDESHA2_ORIGINAL_TRANSPORT_OUT_DESC, property);
    
    property = axutil_property_create_with_args(env, 0, 0, 0, AXIS2_VALUE_TRUE);
    axis2_msg_ctx_set_property(msg_ctx, env, SANDESHA2_SET_SEND_TO_TRUE, 
        property);
    sandesha2_transport_out = sandesha2_utils_get_transport_out(env);
    axis2_msg_ctx_set_transport_out_desc(msg_ctx, env, sandesha2_transport_out);
    /*Sending the message once through the sandesha2_transport_sender */
    engine = axis2_engine_create(env, conf_ctx);
    if(axis2_msg_ctx_is_paused(msg_ctx, env))
    {
        axis2_msg_ctx_set_current_handler_index(msg_ctx, env, 
            axis2_msg_ctx_get_current_handler_index(msg_ctx, env) + 1);
        status = axis2_engine_resume_send(engine, env, msg_ctx);
    }
    else
    {
        status = axis2_engine_send(engine, env, msg_ctx);
    }
    return status;
}

axis2_bool_t AXIS2_CALL
sandesha2_utils_is_wsrm_anon_reply_to(
    const axutil_env_t *env,
    const axis2_char_t *reply_to)
{
    if (reply_to && axutil_strstr(reply_to, "anonymous"))
        return AXIS2_TRUE;
    if (reply_to && axutil_strstr(reply_to, AXIS2_WS_RM_ANONYMOUS_URL))
        return AXIS2_TRUE;
    else
        return AXIS2_FALSE;
}

axis2_bool_t AXIS2_CALL
sandesha2_utils_is_anon_uri(
    const axutil_env_t *env,
    const axis2_char_t *address)
{
    axis2_char_t *address_l = NULL;
    if(!address)
        return AXIS2_TRUE;
    address_l = axutil_strtrim(env, address, NULL);

    if(0 == axutil_strcmp(AXIS2_WSA_ANONYMOUS_URL, address_l))
        return AXIS2_TRUE;
    if(0 == axutil_strcmp(AXIS2_WSA_ANONYMOUS_URL_SUBMISSION, address_l))
        return AXIS2_TRUE;
    else if (sandesha2_utils_is_wsrm_anon_reply_to(env, (axis2_char_t *) address))
        return AXIS2_TRUE;

    return AXIS2_FALSE;
}

axutil_array_list_t *AXIS2_CALL
sandesha2_utils_split(
    const axutil_env_t *env,
    axis2_char_t *str,
    axis2_char_t *pattern)
{
    axutil_array_list_t *list = axutil_array_list_create(env, 0);
    axis2_char_t *ptr = NULL;
    axis2_char_t *value = NULL;
    ptr = axutil_strstr(str, pattern);
    while(ptr)
    {
        ptr[0] = AXIS2_EOLN;
        value = axutil_strdup(env, str);
        if(value && 0 != axutil_strcmp(value, ""))
            axutil_array_list_add(list, env, value);
        str = ptr + 3;
        ptr = axutil_strstr(str, pattern);
    }
    value = axutil_strdup(env, str);
    if(value && 0 != axutil_strcmp(value, ""))
        axutil_array_list_add(list, env, value);

    return list;
}

axis2_bool_t AXIS2_CALL
sandesha2_utils_is_single_channel(
    const axutil_env_t *env,
    const axis2_char_t *rm_version,
    const axis2_char_t *acks_to_addr)
{
    if(sandesha2_utils_is_anon_uri(env, acks_to_addr) &&
        (0 == axutil_strcmp(SANDESHA2_SPEC_VERSION_1_0, rm_version)))
        return AXIS2_TRUE;
    else return AXIS2_FALSE;
}

