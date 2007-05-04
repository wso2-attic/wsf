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
#include <axis2_module.h>
#include <axis2_addr_mod.h>
#include <axis2_conf_ctx.h>

axis2_status_t AXIS2_CALL
axis2_mod_addr_shutdown(axis2_module_t *module,
        const axutil_env_t *env);

axis2_status_t AXIS2_CALL
axis2_mod_addr_init(
    axis2_module_t *module,
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    axis2_module_desc_t *module_desc);

axis2_status_t AXIS2_CALL
axis2_mod_addr_fill_handler_create_func_map(axis2_module_t *module,
        const axutil_env_t *env);

static const axis2_module_ops_t addr_module_ops_var = {
    axis2_mod_addr_init,
    axis2_mod_addr_shutdown,
    axis2_mod_addr_fill_handler_create_func_map
};

axis2_module_t *
axis2_mod_addr_create(const axutil_env_t *env)
{
    axis2_module_t *module = NULL;
    module = AXIS2_MALLOC(env->allocator,
            sizeof(axis2_module_t));

    module->ops = &addr_module_ops_var;
    
    return module;
}

axis2_status_t AXIS2_CALL
axis2_mod_addr_init(
    axis2_module_t *module,
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    axis2_module_desc_t *module_desc)
{
    /* Any initialization stuff of mod_addr goes here */
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_mod_addr_shutdown(axis2_module_t *module,
        const axutil_env_t *env)
{
    if (module->handler_create_func_map)
    {
        axutil_hash_free(module->handler_create_func_map, env);
        module->handler_create_func_map = NULL;
    }

    if (module)
    {
        AXIS2_FREE(env->allocator, module);
        module = NULL;
    }
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_mod_addr_fill_handler_create_func_map(axis2_module_t *module,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    module->handler_create_func_map = axutil_hash_make(env);
    if (!module->handler_create_func_map)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY,
                AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    axutil_hash_set(module->handler_create_func_map, "AddressingInHandler",
            AXIS2_HASH_KEY_STRING, axis2_addr_in_handler_create);

    axutil_hash_set(module->handler_create_func_map, "AddressingOutHandler",
            AXIS2_HASH_KEY_STRING, axis2_addr_out_handler_create);

    return AXIS2_SUCCESS;
}

/**
 * Following block distinguish the exposed part of the dll.
 */

AXIS2_EXPORT int
axis2_get_instance(axis2_module_t **inst,
        const axutil_env_t *env)
{
    *inst = axis2_mod_addr_create(env);
    if (!(*inst))
    {
        return AXIS2_FAILURE;
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXPORT int
axis2_remove_instance(axis2_module_t *inst,
        const axutil_env_t *env)
{
    axis2_status_t status = AXIS2_FAILURE;
    if (inst)
    {
        status = axis2_mod_addr_shutdown(inst, env);
    }
    return status;
}
