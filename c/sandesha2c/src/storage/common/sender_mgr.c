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
 
#include <sandesha2_sender_mgr.h>
#include <sandesha2_constants.h>
#include <sandesha2_error.h>
#include <sandesha2_utils.h>
#include <sandesha2_sender_bean.h>
#include <axutil_log.h>
#include <axutil_hash.h>
#include <axutil_thread.h>
#include <axutil_property.h>

void AXIS2_CALL
sandesha2_sender_mgr_free(
    sandesha2_sender_mgr_t *sender,
    const axutil_env_t *env)
{
    sender->ops.free(sender, env);
}

axis2_bool_t AXIS2_CALL
sandesha2_sender_mgr_insert(
    sandesha2_sender_mgr_t *sender,
    const axutil_env_t *env,
    sandesha2_sender_bean_t *bean)
{
    return sender->ops.insert(sender, env, bean);
}

axis2_bool_t AXIS2_CALL
sandesha2_sender_mgr_remove(
    sandesha2_sender_mgr_t *sender,
    const axutil_env_t *env,
    axis2_char_t *msg_id)
{
    return sender->ops.remove(sender, env, msg_id);
}

sandesha2_sender_bean_t *AXIS2_CALL
sandesha2_sender_mgr_retrieve(
    sandesha2_sender_mgr_t *sender,
    const axutil_env_t *env,
    axis2_char_t *msg_id)
{
    return sender->ops.retrieve(sender, env, msg_id);
}

axis2_bool_t AXIS2_CALL
sandesha2_sender_mgr_update(
    sandesha2_sender_mgr_t *sender,
    const axutil_env_t *env,
    sandesha2_sender_bean_t *bean)
{
    return sender->ops.update(sender, env, bean);
}

axutil_array_list_t *AXIS2_CALL
sandesha2_sender_mgr_find_by_internal_seq_id(
    sandesha2_sender_mgr_t *sender,
    const axutil_env_t *env,
    axis2_char_t *internal_seq_id)
{
    return sender->ops.find_by_internal_seq_id(sender, env, internal_seq_id);
}

axutil_array_list_t *AXIS2_CALL
sandesha2_sender_mgr_find_by_sender_bean(
    sandesha2_sender_mgr_t *sender,
    const axutil_env_t *env,
    sandesha2_sender_bean_t *bean)
{
    return sender->ops.find_by_sender_bean(sender, env, bean);
}

sandesha2_sender_bean_t *AXIS2_CALL
sandesha2_sender_mgr_find_unique(
    sandesha2_sender_mgr_t *sender,
    const axutil_env_t *env,
    sandesha2_sender_bean_t *bean)
{
    return sender->ops.find_unique(sender, env, bean);
}

sandesha2_sender_bean_t *AXIS2_CALL
sandesha2_sender_mgr_get_next_msg_to_send(
    sandesha2_sender_mgr_t *sender,
    const axutil_env_t *env,
    const axis2_char_t *seq_id)
{
    return sender->ops.get_next_msg_to_send(sender, env, seq_id);
}

