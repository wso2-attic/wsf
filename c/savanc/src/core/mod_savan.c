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
#include <axis2_module.h>
#include <axis2_conf_ctx.h>

#include "mod_savan.h"

/**************************** Function Prototypes *****************************/

axis2_status_t AXIS2_CALL
mod_savan_shutdown(axis2_module_t *module,
                        const axutil_env_t *env);

axis2_status_t AXIS2_CALL
mod_savan_init(axis2_module_t *module,
        const axutil_env_t *env,
        axis2_conf_ctx_t *conf_ctx,
        axis2_module_desc_t *module_desc);

axis2_status_t AXIS2_CALL
mod_savan_fill_handler_create_func_map(
		axis2_module_t *module,
        const axutil_env_t *env);

static const axis2_module_ops_t savan_module_ops_var = {
	mod_savan_init,
	mod_savan_shutdown,
	mod_savan_fill_handler_create_func_map
};

/*************************** End of Function Prototypes ***********************/

axis2_module_t *
mod_savan_create(const axutil_env_t *env)
{
    axis2_module_t *module = NULL;
    module = AXIS2_MALLOC(env->allocator, 
        sizeof(axis2_module_t));
    
    module->ops = &savan_module_ops_var;
    return module;
}

/******************************************************************************/

axis2_status_t AXIS2_CALL
mod_savan_init(
        axis2_module_t *module,
        const axutil_env_t *env,
        axis2_conf_ctx_t *conf_ctx,
        axis2_module_desc_t *module_desc)
{
    /* Any initialization stuff of mod_savan goes here */
    return AXIS2_SUCCESS;
}

/******************************************************************************/

axis2_status_t AXIS2_CALL
mod_savan_shutdown(axis2_module_t *module,
                        const axutil_env_t *env)
{
    if(module->handler_create_func_map)
    {
        /* TODO
         *  do the neccessary clean in hash map
         */
        axutil_hash_free(module->handler_create_func_map, env);
    }
    
    if(module)
    {
        AXIS2_FREE(env->allocator, module);
    }
    return AXIS2_SUCCESS; 
}

/******************************************************************************/

axis2_status_t AXIS2_CALL
mod_savan_fill_handler_create_func_map(axis2_module_t *module,
                                            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    module->handler_create_func_map = axutil_hash_make(env);
    if(!module->handler_create_func_map)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, 
            AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    axutil_hash_set(module->handler_create_func_map, "SavanInHandler", 
        AXIS2_HASH_KEY_STRING, savan_in_handler_create);


    axutil_hash_set(module->handler_create_func_map, "SavanOutHandler", 
        AXIS2_HASH_KEY_STRING, savan_out_handler_create);
    
    return AXIS2_SUCCESS;
}

/******************************************************************************/

/**
 * Following block distinguish the exposed part of the dll.
 */

AXIS2_EXPORT int 
axis2_get_instance(axis2_module_t **inst,
                   const axutil_env_t *env)
{
   *inst = mod_savan_create(env);
    if(!(*inst))
    {
        return AXIS2_FAILURE;
    }

    return AXIS2_SUCCESS;
}

/******************************************************************************/

AXIS2_EXPORT int 
axis2_remove_instance(axis2_module_t *inst,
                      const axutil_env_t *env)
{
    axis2_status_t status = AXIS2_FAILURE;
   if (inst)
   {
        status = mod_savan_shutdown(inst, env);
    }
    return status;
}
