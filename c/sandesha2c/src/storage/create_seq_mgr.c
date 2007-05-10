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
 
#include <sandesha2_create_seq_mgr.h>
#include <sandesha2_constants.h>
#include <sandesha2_error.h>
#include <axutil_log.h>
#include <axutil_hash.h>
#include <axutil_thread.h>
#include <axutil_property.h>

void AXIS2_CALL 
sandesha2_create_seq_mgr_free(
    sandesha2_create_seq_mgr_t *seq_mgr,
    const axutil_env_t *env)
{
    seq_mgr->ops.free(seq_mgr, env);
}

axis2_bool_t AXIS2_CALL
sandesha2_create_seq_mgr_insert(
    sandesha2_create_seq_mgr_t *seq_mgr,
    const axutil_env_t *env,
    sandesha2_create_seq_bean_t *bean)
{
    return seq_mgr->ops.insert(seq_mgr, env, bean);
}

axis2_bool_t AXIS2_CALL
sandesha2_create_seq_mgr_remove(
    sandesha2_create_seq_mgr_t *seq_mgr,
    const axutil_env_t *env,
    axis2_char_t *msg_id)
{
    return seq_mgr->ops.remove(seq_mgr, env, msg_id);
}

sandesha2_create_seq_bean_t *AXIS2_CALL
sandesha2_create_seq_mgr_retrieve(
    sandesha2_create_seq_mgr_t *seq_mgr,
    const axutil_env_t *env,
    axis2_char_t *msg_id)
{
    return seq_mgr->ops.retrieve(seq_mgr, env, msg_id);
}

axis2_bool_t AXIS2_CALL
sandesha2_create_seq_mgr_update(
    sandesha2_create_seq_mgr_t *seq_mgr,
    const axutil_env_t *env,
    sandesha2_create_seq_bean_t *bean)
{
    return seq_mgr->ops.update(seq_mgr, env, bean);
}

axutil_array_list_t *AXIS2_CALL
sandesha2_create_seq_mgr_find(
    sandesha2_create_seq_mgr_t *seq_mgr,
    const axutil_env_t *env,
    sandesha2_create_seq_bean_t *bean)
{
    return seq_mgr->ops.find(seq_mgr, env, bean);
}

sandesha2_create_seq_bean_t *AXIS2_CALL
sandesha2_create_seq_mgr_find_unique(
    sandesha2_create_seq_mgr_t *seq_mgr,
    const axutil_env_t *env,
    sandesha2_create_seq_bean_t *bean)
{
    return seq_mgr->ops.find_unique(seq_mgr, env, bean);
}
 
