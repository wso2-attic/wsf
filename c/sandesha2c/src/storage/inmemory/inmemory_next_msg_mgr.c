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
 
#include <sandesha2_inmemory_next_msg_mgr.h>
#include "sandesha2_inmemory_bean_mgr.h"
#include <sandesha2_next_msg_mgr.h>
#include <sandesha2_constants.h>
#include <sandesha2_error.h>
#include <sandesha2_utils.h>
#include <sandesha2_storage_mgr.h>
#include <axutil_log.h>
#include <axutil_hash.h>
#include <axutil_thread.h>
#include <axutil_property.h>

/** 
 * @brief Sandesha2 Inmemory Next Message Manager Struct Impl
 *   Sandesha Sequence2 Inmemory Next Message Manager 
 */ 
typedef struct sandesha2_inmemory_next_msg_mgr
{
    sandesha2_next_msg_mgr_t next_msg_mgr;
    sandesha2_inmemory_bean_mgr_t *bean_mgr;
    axutil_array_list_t *values;
}sandesha2_inmemory_next_msg_mgr_t;

#define SANDESHA2_INTF_TO_IMPL(next_msg_mgr) \
    ((sandesha2_inmemory_next_msg_mgr_t *) next_msg_mgr)

void AXIS2_CALL
sandesha2_inmemory_next_msg_mgr_free(
    sandesha2_next_msg_mgr_t *next_msg_mgr,
    const axutil_env_t *env);

axis2_bool_t AXIS2_CALL
sandesha2_inmemory_next_msg_mgr_insert(
    sandesha2_next_msg_mgr_t *next_msg_mgr,
    const axutil_env_t *env,
    sandesha2_next_msg_bean_t *bean);

axis2_bool_t AXIS2_CALL
sandesha2_inmemory_next_msg_mgr_remove(
    sandesha2_next_msg_mgr_t *next_msg_mgr,
    const axutil_env_t *env,
    axis2_char_t *seq_id);

sandesha2_next_msg_bean_t *AXIS2_CALL
sandesha2_inmemory_next_msg_mgr_retrieve(
    sandesha2_next_msg_mgr_t *next_msg_mgr,
    const axutil_env_t *env,
    axis2_char_t *seq_id);

axis2_bool_t AXIS2_CALL
sandesha2_inmemory_next_msg_mgr_update(
    sandesha2_next_msg_mgr_t *next_msg_mgr,
    const axutil_env_t *env,
    sandesha2_next_msg_bean_t *bean);

axutil_array_list_t *AXIS2_CALL
sandesha2_inmemory_next_msg_mgr_find(
    sandesha2_next_msg_mgr_t *next_msg_mgr,
    const axutil_env_t *env,
    sandesha2_next_msg_bean_t *bean);

sandesha2_next_msg_bean_t *AXIS2_CALL
sandesha2_inmemory_next_msg_mgr_find_unique(
    sandesha2_next_msg_mgr_t *next_msg_mgr,
    const axutil_env_t *env,
    sandesha2_next_msg_bean_t *bean);

axis2_bool_t AXIS2_CALL
sandesha2_inmemory_next_msg_mgr_match(
    sandesha2_inmemory_bean_mgr_t *next_msg_mgr,
    const axutil_env_t *env,
    sandesha2_rm_bean_t *bean,
    sandesha2_rm_bean_t *candidate);

axutil_array_list_t *AXIS2_CALL
sandesha2_inmemory_next_msg_mgr_retrieve_all(
    sandesha2_next_msg_mgr_t *next_msg_mgr,
    const axutil_env_t *env);

static const sandesha2_next_msg_mgr_ops_t next_msg_mgr_ops = 
{
    sandesha2_inmemory_next_msg_mgr_free,
    sandesha2_inmemory_next_msg_mgr_insert,
    sandesha2_inmemory_next_msg_mgr_remove,
    sandesha2_inmemory_next_msg_mgr_retrieve,
    sandesha2_inmemory_next_msg_mgr_update,
    sandesha2_inmemory_next_msg_mgr_find,
    sandesha2_inmemory_next_msg_mgr_find_unique,
    sandesha2_inmemory_next_msg_mgr_retrieve_all
};

AXIS2_EXTERN sandesha2_next_msg_mgr_t * AXIS2_CALL
sandesha2_inmemory_next_msg_mgr_create(
    const axutil_env_t *env,
    sandesha2_storage_mgr_t *storage_mgr,
    axis2_ctx_t *ctx)
{
    sandesha2_inmemory_next_msg_mgr_t *next_msg_mgr_impl = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    next_msg_mgr_impl = AXIS2_MALLOC(env->allocator, 
        sizeof(sandesha2_inmemory_next_msg_mgr_t));

    next_msg_mgr_impl->values = axutil_array_list_create(env, 0);
    if(!next_msg_mgr_impl->values)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    next_msg_mgr_impl->bean_mgr = sandesha2_inmemory_bean_mgr_create(env,
        storage_mgr, ctx, SANDESHA2_BEAN_MAP_NEXT_MESSAGE);
    next_msg_mgr_impl->bean_mgr->ops.match = sandesha2_inmemory_next_msg_mgr_match;
    next_msg_mgr_impl->next_msg_mgr.ops = next_msg_mgr_ops;

    return &(next_msg_mgr_impl->next_msg_mgr);
}

void AXIS2_CALL
sandesha2_inmemory_next_msg_mgr_free(
    sandesha2_next_msg_mgr_t *next_msg_mgr,
    const axutil_env_t *env)
{
    sandesha2_inmemory_next_msg_mgr_t *next_msg_mgr_impl = NULL;
    next_msg_mgr_impl = SANDESHA2_INTF_TO_IMPL(next_msg_mgr);

    if(next_msg_mgr_impl->bean_mgr)
    {
        sandesha2_inmemory_bean_mgr_free(next_msg_mgr_impl->bean_mgr, env);
        next_msg_mgr_impl->bean_mgr = NULL;
    }
    if(next_msg_mgr_impl->values)
    {
        axutil_array_list_free(next_msg_mgr_impl->values, env);
        next_msg_mgr_impl->values = NULL;
    }
    if(next_msg_mgr_impl)
    {
        AXIS2_FREE(env->allocator, next_msg_mgr_impl);
        next_msg_mgr_impl = NULL;
    }
}

axis2_bool_t AXIS2_CALL
sandesha2_inmemory_next_msg_mgr_insert(
    sandesha2_next_msg_mgr_t *next_msg_mgr,
    const axutil_env_t *env,
    sandesha2_next_msg_bean_t *bean)
{
    axis2_char_t *seq_id = NULL;
    sandesha2_inmemory_next_msg_mgr_t *next_msg_mgr_impl = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, bean, AXIS2_FALSE);
    next_msg_mgr_impl = SANDESHA2_INTF_TO_IMPL(next_msg_mgr);

    seq_id = sandesha2_next_msg_bean_get_seq_id((sandesha2_rm_bean_t *) bean, 
        env);
    if(!seq_id)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_KEY_IS_NULL, AXIS2_FAILURE);
        return AXIS2_FALSE;
    }
    return sandesha2_inmemory_bean_mgr_insert(next_msg_mgr_impl->bean_mgr, env,
        seq_id, (sandesha2_rm_bean_t *) bean);
}

axis2_bool_t AXIS2_CALL
sandesha2_inmemory_next_msg_mgr_remove(
    sandesha2_next_msg_mgr_t *next_msg_mgr,
    const axutil_env_t *env,
    axis2_char_t *seq_id)
{
    sandesha2_inmemory_next_msg_mgr_t *next_msg_mgr_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, seq_id, AXIS2_FALSE);
    next_msg_mgr_impl = SANDESHA2_INTF_TO_IMPL(next_msg_mgr);
    return sandesha2_inmemory_bean_mgr_remove(next_msg_mgr_impl->bean_mgr, env,
        seq_id);
}

sandesha2_next_msg_bean_t *AXIS2_CALL
sandesha2_inmemory_next_msg_mgr_retrieve(
    sandesha2_next_msg_mgr_t *next_msg_mgr,
    const axutil_env_t *env,
    axis2_char_t *seq_id)
{
    sandesha2_inmemory_next_msg_mgr_t *next_msg_mgr_impl = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, seq_id, AXIS2_FALSE);
    next_msg_mgr_impl = SANDESHA2_INTF_TO_IMPL(next_msg_mgr);
    return (sandesha2_next_msg_bean_t *) sandesha2_inmemory_bean_mgr_retrieve(
        next_msg_mgr_impl->bean_mgr, env, seq_id);
}

axis2_bool_t AXIS2_CALL
sandesha2_inmemory_next_msg_mgr_update(
    sandesha2_next_msg_mgr_t *next_msg_mgr,
    const axutil_env_t *env,
    sandesha2_next_msg_bean_t *bean)
{
    axis2_char_t *seq_id = NULL;
    sandesha2_inmemory_next_msg_mgr_t *next_msg_mgr_impl = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, bean, AXIS2_FALSE);
    next_msg_mgr_impl = SANDESHA2_INTF_TO_IMPL(next_msg_mgr);
    seq_id = sandesha2_next_msg_bean_get_seq_id((sandesha2_rm_bean_t *) bean, 
        env);
    if(!seq_id)
    {
        return AXIS2_FALSE;
    }
    return sandesha2_inmemory_bean_mgr_update(next_msg_mgr_impl->bean_mgr, env,
        seq_id, (sandesha2_rm_bean_t *) bean);
}

axutil_array_list_t *AXIS2_CALL
sandesha2_inmemory_next_msg_mgr_find(
    sandesha2_next_msg_mgr_t *next_msg_mgr,
    const axutil_env_t *env,
    sandesha2_next_msg_bean_t *bean)
{
    sandesha2_inmemory_next_msg_mgr_t *next_msg_mgr_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    next_msg_mgr_impl = SANDESHA2_INTF_TO_IMPL(next_msg_mgr);
    return sandesha2_inmemory_bean_mgr_find(next_msg_mgr_impl->bean_mgr, env,
        (sandesha2_rm_bean_t *) bean);
}

sandesha2_next_msg_bean_t *AXIS2_CALL
sandesha2_inmemory_next_msg_mgr_find_unique(
    sandesha2_next_msg_mgr_t *next_msg_mgr,
    const axutil_env_t *env,
    sandesha2_next_msg_bean_t *bean)
{
    sandesha2_inmemory_next_msg_mgr_t *next_msg_mgr_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, bean, AXIS2_FALSE);
    next_msg_mgr_impl = SANDESHA2_INTF_TO_IMPL(next_msg_mgr);
    return (sandesha2_next_msg_bean_t *)
        sandesha2_inmemory_bean_mgr_find_unique(next_msg_mgr_impl->bean_mgr, env,
        (sandesha2_rm_bean_t *) bean);
}

axutil_array_list_t *AXIS2_CALL
sandesha2_inmemory_next_msg_mgr_retrieve_all(
    sandesha2_next_msg_mgr_t *next_msg_mgr,
    const axutil_env_t *env)
{
    sandesha2_inmemory_next_msg_mgr_t *next_msg_mgr_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    next_msg_mgr_impl = SANDESHA2_INTF_TO_IMPL(next_msg_mgr);
    return sandesha2_inmemory_bean_mgr_find(next_msg_mgr_impl->bean_mgr, env,
        NULL);
}

axis2_bool_t AXIS2_CALL
sandesha2_inmemory_next_msg_mgr_match(
    sandesha2_inmemory_bean_mgr_t *next_msg_mgr,
    const axutil_env_t *env,
    sandesha2_rm_bean_t *bean,
    sandesha2_rm_bean_t *candidate)
{
    axis2_bool_t equal = AXIS2_TRUE;
    long next_msg_no = 0;
    long temp_next_msg_no = 0;
    axis2_char_t *seq_id = NULL;
    axis2_char_t *temp_seq_id = NULL;
    sandesha2_inmemory_next_msg_mgr_t *next_msg_mgr_impl = NULL;
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Entry:sandesha2_inmemory_next_msg_mgr_match");
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    next_msg_mgr_impl = SANDESHA2_INTF_TO_IMPL(next_msg_mgr);
    next_msg_no = sandesha2_next_msg_bean_get_next_msg_no_to_process(
        (sandesha2_next_msg_bean_t *) bean, env);
    temp_next_msg_no = sandesha2_next_msg_bean_get_next_msg_no_to_process(
        (sandesha2_next_msg_bean_t *) candidate, env);
    if(next_msg_no > 0 && (next_msg_no != temp_next_msg_no))
    {
        equal = AXIS2_FALSE;
    }
    seq_id = sandesha2_next_msg_bean_get_seq_id(
         (sandesha2_rm_bean_t *) bean, env);
    temp_seq_id = sandesha2_next_msg_bean_get_seq_id(
        (sandesha2_rm_bean_t *) candidate, env);
    if(seq_id && temp_seq_id && 0 != axutil_strcmp(seq_id, temp_seq_id))
    {
        equal = AXIS2_FALSE;
    }
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Exit:sandesha2_inmemory_next_msg_mgr_match:equal:%d", 
            equal);
    return equal;
}

