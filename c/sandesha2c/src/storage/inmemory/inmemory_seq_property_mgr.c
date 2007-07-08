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
 
#include <sandesha2_seq_property_mgr.h>
#include <sandesha2_inmemory_seq_property_mgr.h>
#include "sandesha2_inmemory_bean_mgr.h"
#include <sandesha2_constants.h>
#include <sandesha2_error.h>
#include <sandesha2_utils.h>
#include <sandesha2_storage_mgr.h>
#include <sandesha2_seq_property_mgr.h>
#include <sandesha2_rm_bean.h>
#include <axutil_log.h>
#include <axutil_hash.h>
#include <axutil_thread.h>
#include <axutil_property.h>

/** 
 * @brief Sandesha Inmemory Sequence Property Manager Struct Impl
 *   Sandesha Inmemory Sequence Property Manager 
 */ 
typedef struct sandesha2_inmemory_seq_property_mgr
{
    sandesha2_seq_property_mgr_t seq_prop_mgr;
    sandesha2_inmemory_bean_mgr_t *bean_mgr;
    axutil_array_list_t *values;
} sandesha2_inmemory_seq_property_mgr_t;

#define SANDESHA2_INTF_TO_IMPL(seq_property_mgr) \
    ((sandesha2_inmemory_seq_property_mgr_t *) seq_property_mgr)

void AXIS2_CALL
sandesha2_inmemory_seq_property_mgr_free(
    sandesha2_seq_property_mgr_t *seq_prop_mgr,
    const axutil_env_t *env);

axis2_bool_t AXIS2_CALL
sandesha2_inmemory_seq_property_mgr_insert(
    sandesha2_seq_property_mgr_t *seq_prop_mgr,
    const axutil_env_t *env,
    sandesha2_seq_property_bean_t *bean);

axis2_bool_t AXIS2_CALL
sandesha2_inmemory_seq_property_mgr_remove(
        sandesha2_seq_property_mgr_t *seq_prop_mgr,
        const axutil_env_t *env,
        axis2_char_t *seq_id,
        axis2_char_t *name);

sandesha2_seq_property_bean_t *AXIS2_CALL
sandesha2_inmemory_seq_property_mgr_retrieve(
    sandesha2_seq_property_mgr_t *seq_prop_mgr,
    const axutil_env_t *env,
    axis2_char_t *seq_id,
    axis2_char_t *name);

axis2_bool_t AXIS2_CALL
sandesha2_inmemory_seq_property_mgr_update(
    sandesha2_seq_property_mgr_t *seq_prop_mgr,
    const axutil_env_t *env,
    sandesha2_seq_property_bean_t *bean);

axutil_array_list_t *AXIS2_CALL
sandesha2_inmemory_seq_property_mgr_find(
    sandesha2_seq_property_mgr_t *seq_prop_mgr,
    const axutil_env_t *env,
    sandesha2_seq_property_bean_t *bean);

sandesha2_seq_property_bean_t *AXIS2_CALL
sandesha2_inmemory_seq_property_mgr_find_unique(
    sandesha2_seq_property_mgr_t *seq_prop_mgr,
    const axutil_env_t *env,
    sandesha2_seq_property_bean_t *bean);

static axis2_bool_t AXIS2_CALL
sandesha2_inmemory_seq_property_mgr_match(
    sandesha2_inmemory_bean_mgr_t *seq_prop,
    const axutil_env_t *env,
    sandesha2_rm_bean_t *bean,
    sandesha2_rm_bean_t *candidate);

axutil_array_list_t *AXIS2_CALL
sandesha2_inmemory_seq_property_mgr_retrieve_all(
    sandesha2_seq_property_mgr_t *seq_prop_mgr,
    const axutil_env_t *env);

static axis2_char_t *
sandesha2_inmemory_seq_property_mgr_get_id_with_bean(
    const axutil_env_t *env,
    sandesha2_seq_property_bean_t *bean);

static axis2_char_t *
sandesha2_inmemory_seq_property_mgr_get_id_with_seq_id_and_name(
    const axutil_env_t *env,
    axis2_char_t *seq_id,
    axis2_char_t *name);

static const sandesha2_seq_property_mgr_ops_t seq_property_mgr_ops = 
{
    sandesha2_inmemory_seq_property_mgr_free,
    sandesha2_inmemory_seq_property_mgr_insert,
    sandesha2_inmemory_seq_property_mgr_remove,
    sandesha2_inmemory_seq_property_mgr_retrieve,
    sandesha2_inmemory_seq_property_mgr_update,
    sandesha2_inmemory_seq_property_mgr_find,
    sandesha2_inmemory_seq_property_mgr_find_unique,
    sandesha2_inmemory_seq_property_mgr_retrieve_all,
};

AXIS2_EXTERN sandesha2_seq_property_mgr_t * AXIS2_CALL
sandesha2_inmemory_seq_property_mgr_create(
    const axutil_env_t *env,
    sandesha2_storage_mgr_t *storage_mgr,
    axis2_ctx_t *ctx)
{
    sandesha2_inmemory_seq_property_mgr_t *seq_prop_mgr_impl = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    seq_prop_mgr_impl = AXIS2_MALLOC(env->allocator, 
        sizeof(sandesha2_inmemory_seq_property_mgr_t));

    seq_prop_mgr_impl->values = NULL;
    seq_prop_mgr_impl->bean_mgr = sandesha2_inmemory_bean_mgr_create(env,
        storage_mgr, ctx, SANDESHA2_BEAN_MAP_SEQ_PROPERTY);
    seq_prop_mgr_impl->bean_mgr->ops.match = sandesha2_inmemory_seq_property_mgr_match;
    seq_prop_mgr_impl->seq_prop_mgr.ops = seq_property_mgr_ops;
    return &(seq_prop_mgr_impl->seq_prop_mgr);
}

void AXIS2_CALL
sandesha2_inmemory_seq_property_mgr_free(
    sandesha2_seq_property_mgr_t *seq_prop_mgr,
    const axutil_env_t *env)
{
    sandesha2_inmemory_seq_property_mgr_t *seq_prop_mgr_impl = NULL;
    seq_prop_mgr_impl = SANDESHA2_INTF_TO_IMPL(seq_prop_mgr);

    if(seq_prop_mgr_impl->values)
    {
        axutil_array_list_free(seq_prop_mgr_impl->values, env);
        seq_prop_mgr_impl->values = NULL;
    }
    if(seq_prop_mgr_impl->bean_mgr)
    {
        sandesha2_inmemory_bean_mgr_free(seq_prop_mgr_impl->bean_mgr, env);
        seq_prop_mgr_impl->bean_mgr = NULL;
    }
    if(seq_prop_mgr_impl)
    {
        AXIS2_FREE(env->allocator, seq_prop_mgr_impl);
        seq_prop_mgr_impl = NULL;
    }
}

axis2_bool_t AXIS2_CALL
sandesha2_inmemory_seq_property_mgr_insert(
    sandesha2_seq_property_mgr_t *seq_prop_mgr,
    const axutil_env_t *env,
    sandesha2_seq_property_bean_t *bean)
{
    axis2_char_t *id = NULL;
    axis2_bool_t ret = AXIS2_FALSE;
    sandesha2_inmemory_seq_property_mgr_t *seq_prop_mgr_impl = NULL;

    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,  
        "Entry:[sandesha2]sandesha2_inmemory_seq_property_mgr_insert");
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, bean, AXIS2_FALSE);
    seq_prop_mgr_impl = SANDESHA2_INTF_TO_IMPL(seq_prop_mgr);

    id = sandesha2_inmemory_seq_property_mgr_get_id_with_bean(env, bean);
    ret = sandesha2_inmemory_bean_mgr_insert(seq_prop_mgr_impl->bean_mgr, env,
        id, (sandesha2_rm_bean_t *) bean);
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,  
        "Exit:[sandesha2]sandesha2_inmemory_seq_property_mgr_insert:return%d", 
            ret);
    return ret;
}

axis2_bool_t AXIS2_CALL
sandesha2_inmemory_seq_property_mgr_remove(
        sandesha2_seq_property_mgr_t *seq_prop_mgr,
        const axutil_env_t *env,
        axis2_char_t *seq_id,
        axis2_char_t *name)
{
    sandesha2_seq_property_bean_t *bean = NULL;
    axis2_char_t *key = NULL;
    axis2_status_t status = AXIS2_FAILURE;
    sandesha2_inmemory_seq_property_mgr_t *seq_prop_mgr_impl = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, seq_id, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, name, AXIS2_FALSE);
    seq_prop_mgr_impl = SANDESHA2_INTF_TO_IMPL(seq_prop_mgr);
    
    bean = sandesha2_inmemory_seq_property_mgr_retrieve(seq_prop_mgr, env, 
            seq_id, name);
    key = sandesha2_inmemory_seq_property_mgr_get_id_with_seq_id_and_name(env, 
        seq_id, name);
    status = sandesha2_inmemory_bean_mgr_remove(seq_prop_mgr_impl->bean_mgr, env,
        key);
    /*AXIS2_FREE(env->allocator, key);*/
    return status;
}

sandesha2_seq_property_bean_t *AXIS2_CALL
sandesha2_inmemory_seq_property_mgr_retrieve(
    sandesha2_seq_property_mgr_t *seq_prop_mgr,
    const axutil_env_t *env,
    axis2_char_t *seq_id,
    axis2_char_t *name)
{
    axis2_char_t *key = NULL;
    sandesha2_seq_property_bean_t *ret = NULL;
    sandesha2_inmemory_seq_property_mgr_t *seq_prop_mgr_impl = NULL;

    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,  
        "[sandesha2] Entry:sandesha2_inmemory_seq_property_mgr_retrieve");
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, seq_id, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, name, AXIS2_FALSE);
    seq_prop_mgr_impl = SANDESHA2_INTF_TO_IMPL(seq_prop_mgr);
    
    key = sandesha2_inmemory_seq_property_mgr_get_id_with_seq_id_and_name(env, 
        seq_id, name); 
    ret = (sandesha2_seq_property_bean_t *) sandesha2_inmemory_bean_mgr_retrieve(
        seq_prop_mgr_impl->bean_mgr, env, key);
    /*AXIS2_FREE(env->allocator, key);*/
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,  
        "[sandesha2] Exit:sandesha2_inmemory_seq_property_mgr_retrieve");
    return ret;
}

axis2_bool_t AXIS2_CALL
sandesha2_inmemory_seq_property_mgr_update(
    sandesha2_seq_property_mgr_t *seq_prop_mgr,
    const axutil_env_t *env,
    sandesha2_seq_property_bean_t *bean)
{
    axis2_char_t *id = NULL;
    axis2_bool_t ret = AXIS2_FALSE;
    sandesha2_inmemory_seq_property_mgr_t *seq_prop_mgr_impl = NULL;

    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,  
        "Entry:[sandesha2]sandesha2_inmemory_seq_property_mgr_update");
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, bean, AXIS2_FALSE);
    seq_prop_mgr_impl = SANDESHA2_INTF_TO_IMPL(seq_prop_mgr);
    id = sandesha2_inmemory_seq_property_mgr_get_id_with_bean(env, bean);
    if(!id)
    {
        return AXIS2_FALSE;
    }
    ret = sandesha2_inmemory_bean_mgr_update(seq_prop_mgr_impl->bean_mgr, env,
        id, (sandesha2_rm_bean_t *) bean);
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,  
        "Exit:[sandesha2]sandesha2_inmemory_seq_property_mgr_update:return:%d", ret);
    return ret;
}

axutil_array_list_t *AXIS2_CALL
sandesha2_inmemory_seq_property_mgr_find(
    sandesha2_seq_property_mgr_t *seq_prop_mgr,
    const axutil_env_t *env,
    sandesha2_seq_property_bean_t *bean)
{
    sandesha2_inmemory_seq_property_mgr_t *seq_prop_mgr_impl = NULL;
    axutil_array_list_t *ret = NULL;
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,  
        "[sandesha2] Entry:sandesha2_inmemory_seq_property_mgr_find");
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    seq_prop_mgr_impl = SANDESHA2_INTF_TO_IMPL(seq_prop_mgr);
    ret = sandesha2_inmemory_bean_mgr_find(seq_prop_mgr_impl->bean_mgr, env,
        (sandesha2_rm_bean_t *) bean);
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,  
        "[sandesha2] Exit:sandesha2_inmemory_seq_property_mgr_find");
    return ret;
}

sandesha2_seq_property_bean_t *AXIS2_CALL
sandesha2_inmemory_seq_property_mgr_find_unique(
    sandesha2_seq_property_mgr_t *seq_prop_mgr,
    const axutil_env_t *env,
    sandesha2_seq_property_bean_t *bean)
{
    sandesha2_inmemory_seq_property_mgr_t *seq_prop_mgr_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, bean, AXIS2_FALSE);
    seq_prop_mgr_impl = SANDESHA2_INTF_TO_IMPL(seq_prop_mgr);
    return (sandesha2_seq_property_bean_t *)
        sandesha2_inmemory_bean_mgr_find_unique(seq_prop_mgr_impl->bean_mgr, env,
        (sandesha2_rm_bean_t *) bean);
}

static axis2_bool_t AXIS2_CALL
sandesha2_inmemory_seq_property_mgr_match(
    sandesha2_inmemory_bean_mgr_t *seq_prop_mgr,
    const axutil_env_t *env,
    sandesha2_rm_bean_t *bean,
    sandesha2_rm_bean_t *candidate)
{
    axis2_bool_t equal = AXIS2_TRUE;
    axis2_char_t *seq_id = NULL;
    axis2_char_t *temp_seq_id = NULL;
    axis2_char_t *name = NULL;
    axis2_char_t *temp_name = NULL;
    axis2_char_t *value = NULL;
    axis2_char_t *temp_value = NULL;
    
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,  
        "[sandesha2] Entry:sandesha2_inmemory_seq_property_mgr_match");
    seq_id = sandesha2_seq_property_bean_get_seq_id(
        (sandesha2_seq_property_bean_t *) bean, env);
    temp_seq_id = sandesha2_seq_property_bean_get_seq_id(
        (sandesha2_seq_property_bean_t *) candidate, env);
    if(seq_id && temp_seq_id && 0 != axutil_strcmp(seq_id, temp_seq_id))
    {
        equal = AXIS2_FALSE;
    }
    name = sandesha2_seq_property_bean_get_name(
        (sandesha2_seq_property_bean_t *) bean, env);
    temp_name = sandesha2_seq_property_bean_get_name(
        (sandesha2_seq_property_bean_t *) candidate, env);
    if(name && temp_name && 0 != axutil_strcmp(name, temp_name))
    {
        equal = AXIS2_FALSE;
    }
    value = sandesha2_seq_property_bean_get_value(
        (sandesha2_seq_property_bean_t *) bean, env);
    temp_value = sandesha2_seq_property_bean_get_value(
        (sandesha2_seq_property_bean_t *) candidate, env);
    if(value && temp_value && 0 != axutil_strcmp(value, temp_value))
    {
        equal = AXIS2_FALSE;
    }
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,  
        "[sandesha2] Exit:sandesha2_inmemory_seq_property_mgr_match:equal:%d", 
            equal);
    return equal;
}

axutil_array_list_t *AXIS2_CALL
sandesha2_inmemory_seq_property_mgr_retrieve_all(
    sandesha2_seq_property_mgr_t *seq_prop_mgr,
    const axutil_env_t *env)
{
    sandesha2_inmemory_seq_property_mgr_t *seq_prop_mgr_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    seq_prop_mgr_impl = SANDESHA2_INTF_TO_IMPL(seq_prop_mgr);
    return sandesha2_inmemory_bean_mgr_find(seq_prop_mgr_impl->bean_mgr, env,
        NULL);
}

static axis2_char_t *
sandesha2_inmemory_seq_property_mgr_get_id_with_seq_id_and_name(
    const axutil_env_t *env,
    axis2_char_t *seq_id,
    axis2_char_t *name)
{
    axis2_char_t *id = NULL;

    id = axutil_strcat(env, seq_id, ":", name, NULL);
    return id;
}

static axis2_char_t *
sandesha2_inmemory_seq_property_mgr_get_id_with_bean(
    const axutil_env_t *env,
    sandesha2_seq_property_bean_t *bean)
{
    axis2_char_t *seq_id = NULL;
    axis2_char_t *name = NULL;
    axis2_char_t *id = NULL;

    seq_id = sandesha2_seq_property_bean_get_seq_id(bean, env);
    name = sandesha2_seq_property_bean_get_name(bean, env);
    id = axutil_strcat(env, seq_id, ":", name, NULL);

    return id;
}

