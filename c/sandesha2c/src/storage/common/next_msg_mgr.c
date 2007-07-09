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
 
#include <sandesha2_next_msg_mgr.h>
#include <sandesha2_constants.h>
#include <sandesha2_error.h>
#include <sandesha2_utils.h>
#include <axutil_log.h>
#include <axutil_hash.h>
#include <axutil_thread.h>
#include <axutil_property.h>

void AXIS2_CALL
sandesha2_next_msg_mgr_free(
    sandesha2_next_msg_mgr_t *next_msg,
    const axutil_env_t *env)
{
    next_msg->ops.free(next_msg, env);
}

axis2_bool_t AXIS2_CALL
sandesha2_next_msg_mgr_insert(
    sandesha2_next_msg_mgr_t *next_msg,
    const axutil_env_t *env,
    sandesha2_next_msg_bean_t *bean)
{
    return next_msg->ops.insert(next_msg, env, bean);
}

axis2_bool_t AXIS2_CALL
sandesha2_next_msg_mgr_remove(
    sandesha2_next_msg_mgr_t *next_msg,
    const axutil_env_t *env,
    axis2_char_t *seq_id)
{
    return next_msg->ops.remove(next_msg, env, seq_id);
}

sandesha2_next_msg_bean_t *AXIS2_CALL
sandesha2_next_msg_mgr_retrieve(
    sandesha2_next_msg_mgr_t *next_msg,
    const axutil_env_t *env,
    axis2_char_t *seq_id)
{
    return next_msg->ops.retrieve(next_msg, env, seq_id);
}

axis2_bool_t AXIS2_CALL
sandesha2_next_msg_mgr_update(
    sandesha2_next_msg_mgr_t *next_msg,
    const axutil_env_t *env,
    sandesha2_next_msg_bean_t *bean)
{
    return next_msg->ops.update(next_msg, env, bean);
}

axutil_array_list_t *AXIS2_CALL
sandesha2_next_msg_mgr_find(
    sandesha2_next_msg_mgr_t *next_msg,
    const axutil_env_t *env,
    sandesha2_next_msg_bean_t *bean)
{
    return next_msg->ops.find(next_msg, env, bean);
}

sandesha2_next_msg_bean_t *AXIS2_CALL
sandesha2_next_msg_mgr_find_unique(
    sandesha2_next_msg_mgr_t *next_msg,
    const axutil_env_t *env,
    sandesha2_next_msg_bean_t *bean)
{
    return next_msg->ops.find_unique(next_msg, env, bean);
}

axutil_array_list_t *AXIS2_CALL
sandesha2_next_msg_mgr_retrieve_all(
    sandesha2_next_msg_mgr_t *next_msg,
    const axutil_env_t *env)
{
    return next_msg->ops.retrieve_all(next_msg, env);
}

