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
#include <sandesha2_constants.h>
#include <sandesha2_error.h>
#include <sandesha2_utils.h>
#include <axutil_log.h>
#include <axutil_hash.h>
#include <axutil_thread.h>
#include <axutil_property.h>

void AXIS2_CALL
sandesha2_seq_property_mgr_free(
    sandesha2_seq_property_mgr_t *seq_prop_mgr,
    const axutil_env_t *env)
{
    seq_prop_mgr->ops.free(seq_prop_mgr, env);
}

axis2_bool_t AXIS2_CALL
sandesha2_seq_property_mgr_insert(
    sandesha2_seq_property_mgr_t *seq_prop_mgr,
    const axutil_env_t *env,
    sandesha2_seq_property_bean_t *bean)
{
    return seq_prop_mgr->ops.insert(seq_prop_mgr, env, bean);
}

axis2_bool_t AXIS2_CALL
sandesha2_seq_property_mgr_remove(
        sandesha2_seq_property_mgr_t *seq_prop_mgr,
        const axutil_env_t *env,
        axis2_char_t *seq_id,
        axis2_char_t *name)
{
    return seq_prop_mgr->ops.remove(seq_prop_mgr, env, seq_id, name);
}

sandesha2_seq_property_bean_t *AXIS2_CALL
sandesha2_seq_property_mgr_retrieve(
    sandesha2_seq_property_mgr_t *seq_prop_mgr,
    const axutil_env_t *env,
    axis2_char_t *seq_id,
    axis2_char_t *name)
{
    return seq_prop_mgr->ops.retrieve(seq_prop_mgr, env, seq_id, name);
}

axis2_bool_t AXIS2_CALL
sandesha2_seq_property_mgr_update(
    sandesha2_seq_property_mgr_t *seq_prop_mgr,
    const axutil_env_t *env,
    sandesha2_seq_property_bean_t *bean)
{
    return seq_prop_mgr->ops.update(seq_prop_mgr, env, bean);
}

axutil_array_list_t *AXIS2_CALL
sandesha2_seq_property_mgr_find(
    sandesha2_seq_property_mgr_t *seq_prop_mgr,
    const axutil_env_t *env,
    sandesha2_seq_property_bean_t *bean)
{
    return seq_prop_mgr->ops.find(seq_prop_mgr, env, bean);
}

sandesha2_seq_property_bean_t *AXIS2_CALL
sandesha2_seq_property_mgr_find_unique(
    sandesha2_seq_property_mgr_t *seq_prop_mgr,
    const axutil_env_t *env,
    sandesha2_seq_property_bean_t *bean)
{
    return seq_prop_mgr->ops.find_unique(seq_prop_mgr, env, bean);
}

axutil_array_list_t *AXIS2_CALL
sandesha2_seq_property_mgr_retrieve_all(
    sandesha2_seq_property_mgr_t *seq_prop_mgr,
    const axutil_env_t *env)
{
    return seq_prop_mgr->ops.retrieve_all(seq_prop_mgr, env);
}

