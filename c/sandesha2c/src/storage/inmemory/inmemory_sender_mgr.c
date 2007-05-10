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
 
#include <sandesha2_inmemory_sender_mgr.h>
#include "sandesha2_inmemory_bean_mgr.h"
#include <sandesha2_sender_mgr.h>
#include <sandesha2_constants.h>
#include <sandesha2_error.h>
#include <sandesha2_utils.h>
#include <sandesha2_sender_bean.h>
#include <sandesha2_storage_mgr.h>
#include <axutil_log.h>
#include <axutil_hash.h>
#include <axutil_thread.h>
#include <axutil_property.h>

/** 
 * @brief Sandesha2 Inmemory Sender Manager Struct Impl
 *   Sandesha2 Inmemory Sender Manager 
 */ 
typedef struct sandesha2_inmemory_sender_mgr
{
    sandesha2_sender_mgr_t sender_mgr;
    sandesha2_inmemory_bean_mgr_t *bean_mgr;
} sandesha2_inmemory_sender_mgr_t;

#define SANDESHA2_INTF_TO_IMPL(sender_mgr) \
    ((sandesha2_inmemory_sender_mgr_t *) sender_mgr)

void AXIS2_CALL
sandesha2_inmemory_sender_mgr_free(
    sandesha2_sender_mgr_t *sender_mgr,
    const axutil_env_t *env);

axis2_bool_t AXIS2_CALL
sandesha2_inmemory_sender_mgr_insert(
    sandesha2_sender_mgr_t *sender_mgr,
    const axutil_env_t *env,
    sandesha2_sender_bean_t *bean);

axis2_bool_t AXIS2_CALL
sandesha2_inmemory_sender_mgr_remove(
    sandesha2_sender_mgr_t *sender_mgr,
    const axutil_env_t *env,
    axis2_char_t *msg_id);

sandesha2_sender_bean_t *AXIS2_CALL
sandesha2_inmemory_sender_mgr_retrieve(
    sandesha2_sender_mgr_t *sender_mgr,
    const axutil_env_t *env,
    axis2_char_t *msg_id);

axis2_bool_t AXIS2_CALL
sandesha2_inmemory_sender_mgr_update(
    sandesha2_sender_mgr_t *sender_mgr,
    const axutil_env_t *env,
    sandesha2_sender_bean_t *bean);

axutil_array_list_t *AXIS2_CALL
sandesha2_inmemory_sender_mgr_find_by_internal_seq_id(
    sandesha2_sender_mgr_t *sender_mgr,
    const axutil_env_t *env,
    axis2_char_t *internal_seq_id);

axutil_array_list_t *AXIS2_CALL
sandesha2_inmemory_sender_mgr_find_by_sender_bean(
    sandesha2_sender_mgr_t *sender_mgr,
    const axutil_env_t *env,
    sandesha2_sender_bean_t *bean);

sandesha2_sender_bean_t *AXIS2_CALL
sandesha2_inmemory_sender_mgr_find_unique(
    sandesha2_sender_mgr_t *sender_mgr,
    const axutil_env_t *env,
    sandesha2_sender_bean_t *bean);

axis2_bool_t AXIS2_CALL
sandesha2_inmemory_sender_mgr_match(
    sandesha2_inmemory_bean_mgr_t *sender_mgr,
    const axutil_env_t *env,
    sandesha2_rm_bean_t *bean,
    sandesha2_rm_bean_t *candidate);

sandesha2_sender_bean_t *AXIS2_CALL
sandesha2_inmemory_sender_mgr_get_next_msg_to_send(
    sandesha2_sender_mgr_t *sender_mgr,
    const axutil_env_t *env,
    const axis2_char_t *seq_id);

static const sandesha2_sender_mgr_ops_t sender_mgr_ops = 
{
    sandesha2_inmemory_sender_mgr_free,
    sandesha2_inmemory_sender_mgr_insert,
    sandesha2_inmemory_sender_mgr_remove,
    sandesha2_inmemory_sender_mgr_retrieve,
    sandesha2_inmemory_sender_mgr_update,
    sandesha2_inmemory_sender_mgr_find_by_internal_seq_id,
    sandesha2_inmemory_sender_mgr_find_by_sender_bean,
    sandesha2_inmemory_sender_mgr_find_unique,
    sandesha2_inmemory_sender_mgr_get_next_msg_to_send,
};

AXIS2_EXTERN sandesha2_sender_mgr_t * AXIS2_CALL
sandesha2_inmemory_sender_mgr_create(
    const axutil_env_t *env,
    sandesha2_storage_mgr_t *storage_mgr,
    axis2_ctx_t *ctx)
{
    sandesha2_inmemory_sender_mgr_t *sender_mgr_impl = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    sender_mgr_impl = AXIS2_MALLOC(env->allocator, 
        sizeof(sandesha2_inmemory_sender_mgr_t));

    sender_mgr_impl->bean_mgr = sandesha2_inmemory_bean_mgr_create(env,
        storage_mgr, ctx, SANDESHA2_BEAN_MAP_RETRANSMITTER);
    sender_mgr_impl->bean_mgr->ops.match = sandesha2_inmemory_sender_mgr_match;
    sender_mgr_impl->sender_mgr.ops = sender_mgr_ops;
    return &(sender_mgr_impl->sender_mgr);
}

void AXIS2_CALL
sandesha2_inmemory_sender_mgr_free(
    sandesha2_sender_mgr_t *sender_mgr,
    const axutil_env_t *env)
{
    sandesha2_inmemory_sender_mgr_t *sender_mgr_impl = NULL;
    sender_mgr_impl = SANDESHA2_INTF_TO_IMPL(sender_mgr);

    if(sender_mgr_impl->bean_mgr)
    {
        sandesha2_inmemory_bean_mgr_free(sender_mgr_impl->bean_mgr, env);
        sender_mgr_impl->bean_mgr = NULL;
    }
    if(sender_mgr_impl)
    {
        AXIS2_FREE(env->allocator, sender_mgr_impl);
        sender_mgr_impl = NULL;
    }
}

axis2_bool_t AXIS2_CALL
sandesha2_inmemory_sender_mgr_insert(
    sandesha2_sender_mgr_t *sender_mgr,
    const axutil_env_t *env,
    sandesha2_sender_bean_t *bean)
{
    axis2_char_t *msg_id = NULL;
    axis2_bool_t ret = AXIS2_FALSE;
    sandesha2_inmemory_sender_mgr_t *sender_mgr_impl = NULL;

    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Entry:sandesha2_inmemory_sender_mgr_insert");
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, bean, AXIS2_FALSE);
    sender_mgr_impl = SANDESHA2_INTF_TO_IMPL(sender_mgr);

    msg_id = sandesha2_sender_bean_get_msg_id((sandesha2_rm_bean_t *) bean, 
        env);
    if(!msg_id)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_KEY_IS_NULL, AXIS2_FAILURE);
        return AXIS2_FALSE;
    }
    ret = sandesha2_inmemory_bean_mgr_insert(sender_mgr_impl->bean_mgr, env,
        msg_id, (sandesha2_rm_bean_t *) bean);
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Exit:sandesha2_inmemory_sender_mgr_insert:return:%d", ret);
    return ret;
}

axis2_bool_t AXIS2_CALL
sandesha2_inmemory_sender_mgr_remove(
    sandesha2_sender_mgr_t *sender_mgr,
    const axutil_env_t *env,
    axis2_char_t *msg_id)
{
    sandesha2_inmemory_sender_mgr_t *sender_mgr_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, msg_id, AXIS2_FALSE);
    sender_mgr_impl = SANDESHA2_INTF_TO_IMPL(sender_mgr);
    return sandesha2_inmemory_bean_mgr_remove(sender_mgr_impl->bean_mgr, env,
        msg_id);
}

sandesha2_sender_bean_t *AXIS2_CALL
sandesha2_inmemory_sender_mgr_retrieve(
    sandesha2_sender_mgr_t *sender_mgr,
    const axutil_env_t *env,
    axis2_char_t *msg_id)
{
    sandesha2_sender_bean_t *ret = NULL;
    sandesha2_inmemory_sender_mgr_t *sender_mgr_impl = NULL;
    sender_mgr_impl = SANDESHA2_INTF_TO_IMPL(sender_mgr);

    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Entry:sandesha2_inmemory_sender_mgr_retrieve");
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, msg_id, AXIS2_FALSE);
    ret = (sandesha2_sender_bean_t *) sandesha2_inmemory_bean_mgr_retrieve(
        sender_mgr_impl->bean_mgr, env, msg_id);
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Exit:sandesha2_inmemory_sender_mgr_retrieve");
    return ret;
}

axis2_bool_t AXIS2_CALL
sandesha2_inmemory_sender_mgr_update(
    sandesha2_sender_mgr_t *sender_mgr,
    const axutil_env_t *env,
    sandesha2_sender_bean_t *bean)
{
    /*axis2_char_t *msg_id = NULL;
    axis2_bool_t ret = AXIS2_FALSE;*/
    sandesha2_inmemory_sender_mgr_t *sender_mgr_impl = NULL;

    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Entry:sandesha2_inmemory_sender_mgr_update");
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, bean, AXIS2_FALSE);
    sender_mgr_impl = SANDESHA2_INTF_TO_IMPL(sender_mgr);

    /* No need to update. Being a reference does the job. */
    return AXIS2_SUCCESS;
}

axutil_array_list_t *AXIS2_CALL
sandesha2_inmemory_sender_mgr_find_by_internal_seq_id(
    sandesha2_sender_mgr_t *sender_mgr,
    const axutil_env_t *env,
    axis2_char_t *internal_seq_id)
{
    sandesha2_sender_bean_t *bean = NULL;
    axutil_array_list_t *ret = NULL;
    sandesha2_inmemory_sender_mgr_t *sender_mgr_impl = NULL;
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Entry:sandesha2_inmemory_sender_mgr_find_by_internal_seq_id");
    AXIS2_ENV_CHECK(env, NULL);
    sender_mgr_impl = SANDESHA2_INTF_TO_IMPL(sender_mgr);
    
    bean = sandesha2_sender_bean_create(env);
    sandesha2_sender_bean_set_internal_seq_id(bean, env, 
        internal_seq_id);
    ret = sandesha2_inmemory_bean_mgr_find(sender_mgr_impl->bean_mgr, env,
        (sandesha2_rm_bean_t *) bean);
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Exit:sandesha2_inmemory_sender_mgr_find_by_internal_seq_id");
    return ret;
}

axutil_array_list_t *AXIS2_CALL
sandesha2_inmemory_sender_mgr_find_by_sender_bean(
    sandesha2_sender_mgr_t *sender_mgr,
    const axutil_env_t *env,
    sandesha2_sender_bean_t *bean)
{
    sandesha2_inmemory_sender_mgr_t *sender_mgr_impl = NULL;
    axutil_array_list_t *ret = NULL;
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Entry:sandesha2_inmemory_sender_mgr_find_by_sender_bean");
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    sender_mgr_impl = SANDESHA2_INTF_TO_IMPL(sender_mgr);
    ret = sandesha2_inmemory_bean_mgr_find(sender_mgr_impl->bean_mgr, env,
        (sandesha2_rm_bean_t *) bean);
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Exit:sandesha2_inmemory_sender_mgr_find_by_sender_bean");
    return ret;
}

sandesha2_sender_bean_t *AXIS2_CALL
sandesha2_inmemory_sender_mgr_find_unique(
    sandesha2_sender_mgr_t *sender_mgr,
    const axutil_env_t *env,
    sandesha2_sender_bean_t *bean)
{
    sandesha2_inmemory_sender_mgr_t *sender_mgr_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, bean, AXIS2_FALSE);
    sender_mgr_impl = SANDESHA2_INTF_TO_IMPL(sender_mgr);
    return (sandesha2_sender_bean_t *)
        sandesha2_inmemory_bean_mgr_find_unique(sender_mgr_impl->bean_mgr, env,
            (sandesha2_rm_bean_t *) bean);
}

axis2_bool_t AXIS2_CALL
sandesha2_inmemory_sender_mgr_match(
    sandesha2_inmemory_bean_mgr_t *sender_mgr,
    const axutil_env_t *env,
    sandesha2_rm_bean_t *bean,
    sandesha2_rm_bean_t *candidate)
{
    axis2_bool_t add = AXIS2_TRUE;
    axis2_char_t *ref_key = NULL;
    axis2_char_t *temp_ref_key = NULL;
    long time_to_send = 0;
    long temp_time_to_send = 0;
    axis2_char_t *msg_id = NULL;
    axis2_char_t *temp_msg_id = NULL;
    axis2_char_t *internal_seq_id = NULL;
    axis2_char_t *temp_internal_seq_id = NULL;
    long msg_no = 0;
    long temp_msg_no = 0;
    int msg_type = 0;
    int temp_msg_type = 0;
    axis2_bool_t is_send = AXIS2_FALSE;
    axis2_bool_t temp_is_send = AXIS2_FALSE;
    
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Entry:sandesha2_inmemory_sender_mgr_match");
    ref_key = sandesha2_sender_bean_get_msg_ctx_ref_key(
        (sandesha2_sender_bean_t *) bean, env);
    temp_ref_key = sandesha2_sender_bean_get_msg_ctx_ref_key(
        (sandesha2_sender_bean_t *) candidate, env);
    if(ref_key && temp_ref_key && 0 != axutil_strcmp(ref_key, temp_ref_key))
    {
        add = AXIS2_FALSE;
    }
    time_to_send = sandesha2_sender_bean_get_time_to_send(
        (sandesha2_sender_bean_t *) bean, env);
    temp_time_to_send = sandesha2_sender_bean_get_time_to_send(
        (sandesha2_sender_bean_t *) candidate, env);
    /*if(time_to_send > 0 && (time_to_send != temp_time_to_send))*/
    if(time_to_send > 0 && (time_to_send < temp_time_to_send))
    {
        add = AXIS2_FALSE;
    }
    msg_id = sandesha2_sender_bean_get_msg_id(
        (sandesha2_rm_bean_t *) bean, env);
    temp_msg_id = sandesha2_sender_bean_get_msg_id(
        (sandesha2_rm_bean_t *) candidate, env);
    if(msg_id && temp_msg_id && 0 != axutil_strcmp(msg_id, temp_msg_id))
    {
        add = AXIS2_FALSE;
    }
    internal_seq_id = sandesha2_sender_bean_get_internal_seq_id(
        (sandesha2_sender_bean_t *) bean, env);
    temp_internal_seq_id = sandesha2_sender_bean_get_internal_seq_id(
        (sandesha2_sender_bean_t *) candidate, 
            env);
    if(internal_seq_id && temp_internal_seq_id && 0 != axutil_strcmp(
                internal_seq_id, temp_internal_seq_id))
    {
        add = AXIS2_FALSE;
    }
    msg_no = sandesha2_sender_bean_get_msg_no(
        (sandesha2_sender_bean_t *) bean, env);
    temp_msg_no = sandesha2_sender_bean_get_msg_no(
        (sandesha2_sender_bean_t *) candidate, env);
    if(msg_no > 0 && (msg_no != temp_msg_no))
    {
        add = AXIS2_FALSE;
    }
    msg_type = sandesha2_sender_bean_get_msg_type(
        (sandesha2_sender_bean_t *) bean, env);
    temp_msg_type = sandesha2_sender_bean_get_msg_type(
        (sandesha2_sender_bean_t *) candidate, env);
    if(msg_type != SANDESHA2_MSG_TYPE_UNKNOWN  && (msg_type != temp_msg_type))
    {
        add = AXIS2_FALSE;
    }
    is_send = sandesha2_sender_bean_is_send(
        (sandesha2_sender_bean_t *) bean, env);
    temp_is_send = sandesha2_sender_bean_is_send(
        (sandesha2_sender_bean_t *) candidate, env);
    if(is_send != temp_is_send)
    {
        add = AXIS2_FALSE;
    }
    /* Do not use the is_resend flag to match messages, as it can stop us from
     * detecting RM messages during 'get_next_msg_to_send'*/
    /*is_resend = sandesha2_sender_bean_is_resend(
        (sandesha2_sender_bean_t *) bean, env);
    temp_is_resend = sandesha2_sender_bean_is_resend(
        (sandesha2_sender_bean_t *) candidate, env);
    if(is_resend != temp_is_resend)
    {
        add = AXIS2_FALSE;
    }*/
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Exit:sandesha2_inmemory_sender_mgr_match:add:%d", 
            add);
    return add;
}

sandesha2_sender_bean_t *AXIS2_CALL
sandesha2_inmemory_sender_mgr_get_next_msg_to_send(
    sandesha2_sender_mgr_t *sender_mgr,
    const axutil_env_t *env,
    const axis2_char_t *seq_id)
{
    sandesha2_sender_bean_t *matcher = sandesha2_sender_bean_create(env);
    sandesha2_sender_bean_t *result = NULL;
    long time_now = 0;
    int i = 0, size = 0;
    axutil_array_list_t *match_list = NULL;
    sandesha2_inmemory_sender_mgr_t *sender_mgr_impl = NULL;
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Entry:sandesha2_inmemory_sender_mgr_get_next_msg_to_send");
    AXIS2_ENV_CHECK(env, NULL);
    sender_mgr_impl = SANDESHA2_INTF_TO_IMPL(sender_mgr);

    sandesha2_sender_bean_set_send(matcher, env, AXIS2_TRUE);
    time_now = sandesha2_utils_get_current_time_in_millis(env);
    sandesha2_sender_bean_set_time_to_send(matcher, env, time_now);
    match_list = sandesha2_inmemory_bean_mgr_find(sender_mgr_impl->bean_mgr, 
        env, (sandesha2_rm_bean_t *) matcher);
    /*
     * We either return an application message or an RM message. If we find
     * an application message first then we carry on through the list to be
     * sure that we send the lowest app message avaliable. If we hit a RM
     * message first then we are done.
     */
    if(match_list)
        size = axutil_array_list_size(match_list, env);
    for(i = 0; i < size; i++)
    {
        sandesha2_sender_bean_t *bean = NULL;
        int msg_type = -1;
        bean = (sandesha2_sender_bean_t *) axutil_array_list_get(match_list, 
            env, i);
        msg_type = sandesha2_sender_bean_get_msg_type(bean, env);
        if(msg_type == SANDESHA2_MSG_TYPE_APPLICATION)
        {
            long msg_no = sandesha2_sender_bean_get_msg_no(bean, env);
            long result_msg_no = -1;
            if(result)
                result_msg_no = sandesha2_sender_bean_get_msg_no(result, env);
            if(result == NULL || result_msg_no > msg_no)
                result = bean;
        }
        else if(!result)
        {
            result = bean;
            break;
        }
    }
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Exit:sandesha2_inmemory_sender_mgr_get_next_msg_to_send");
    return result;
}

