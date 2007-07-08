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
 
#include <sandesha2_invoker_mgr.h>
#include <sandesha2_constants.h>
#include <sandesha2_error.h>
#include <axutil_log.h>
#include <axutil_hash.h>
#include <axutil_thread.h>
#include <axutil_property.h>

void AXIS2_CALL
sandesha2_invoker_mgr_free(
    sandesha2_invoker_mgr_t *invoker,
    const axutil_env_t *env)
{
    invoker->ops.free(invoker, env);
}

axis2_bool_t AXIS2_CALL
sandesha2_invoker_mgr_insert(
    sandesha2_invoker_mgr_t *invoker,
    const axutil_env_t *env,
    sandesha2_invoker_bean_t *bean)
{
    return invoker->ops.insert(invoker, env, bean);
}

axis2_bool_t AXIS2_CALL
sandesha2_invoker_mgr_remove(
    sandesha2_invoker_mgr_t *invoker,
    const axutil_env_t *env,
    axis2_char_t *key)
{
    return invoker->ops.remove(invoker, env, key);
}

sandesha2_invoker_bean_t *AXIS2_CALL
sandesha2_invoker_mgr_retrieve(
    sandesha2_invoker_mgr_t *invoker,
    const axutil_env_t *env,
    axis2_char_t *key)
{
    return invoker->ops.retrieve(invoker, env, key);
}

axis2_bool_t AXIS2_CALL
sandesha2_invoker_mgr_update(
    sandesha2_invoker_mgr_t *invoker,
    const axutil_env_t *env,
    sandesha2_invoker_bean_t *bean)
{
    return invoker->ops.update(invoker, env, bean);
}

axutil_array_list_t *AXIS2_CALL
sandesha2_invoker_mgr_find(
    sandesha2_invoker_mgr_t *invoker,
    const axutil_env_t *env,
    sandesha2_invoker_bean_t *bean)
{
    return invoker->ops.find(invoker, env, bean);
}

sandesha2_invoker_bean_t *AXIS2_CALL
sandesha2_invoker_mgr_find_unique(
    sandesha2_invoker_mgr_t *invoker,
    const axutil_env_t *env,
    sandesha2_invoker_bean_t *bean)
{
    return invoker->ops.find_unique(invoker, env, bean);
}

