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
#include <sandesha2_module.h>
#include <sandesha2_property_bean.h>
#include <sandesha2_property_mgr.h>
#include <sandesha2_utils.h>
#include <sandesha2_constants.h>

/******************************************************************************/
axis2_status_t AXIS2_CALL
mod_sandesha2_shutdown(
    axis2_module_t *module,
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL
mod_sandesha2_init(
    axis2_module_t *module,
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    axis2_module_desc_t *module_desc);

axis2_status_t AXIS2_CALL
mod_sandesha2_fill_handler_create_func_map(
    axis2_module_t *module,
    const axutil_env_t *env);
    
static const axis2_module_ops_t mod_sandesha2_ops_var =
{
    mod_sandesha2_init,
    mod_sandesha2_shutdown,
    mod_sandesha2_fill_handler_create_func_map
};

/******************************************************************************/

AXIS2_EXTERN axis2_module_t * AXIS2_CALL
mod_sandesha2_create(
    const axutil_env_t *env)
{
    axis2_module_t *module = NULL;
    module = AXIS2_MALLOC(env->allocator, 
        sizeof(axis2_module_t));

    
    module->ops = AXIS2_MALLOC(
        env->allocator, sizeof(axis2_module_ops_t));
    module->ops = &mod_sandesha2_ops_var;
    return module;
}

axis2_status_t AXIS2_CALL
mod_sandesha2_init(
    axis2_module_t *module,
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    axis2_module_desc_t *module_desc)
{
    sandesha2_property_bean_t *property_bean = NULL;
    axutil_param_t *param = NULL;
    axis2_conf_t *conf = NULL;
    axis2_ctx_t *ctx = NULL;
    sandesha2_storage_mgr_t *storage_mgr = NULL;
    
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, conf_ctx, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, module_desc, AXIS2_FAILURE);
    
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[sandesha2] module initializing ..");
    sandesha2_error_init();
    property_bean = sandesha2_property_mgr_load_properties_from_module_desc(env,
        module_desc);
    if(!property_bean)
        property_bean = sandesha2_property_mgr_load_properties_from_def_values
            (env);
        
    param = axutil_param_create(env, SANDESHA2_SANDESHA_PROPERTY_BEAN, 
        property_bean);
    
    conf = axis2_conf_ctx_get_conf(conf_ctx, env);
    axis2_conf_add_param(conf, env, param);

    ctx = axis2_conf_ctx_get_base(conf_ctx, env);
    axis2_ctx_set_property(ctx, env, SANDESHA2_INMEMORY_STORAGE_MGR, NULL);
    axis2_ctx_set_property(ctx, env, SANDESHA2_PERMANENT_STORAGE_MGR, NULL);
    
    storage_mgr = sandesha2_utils_get_inmemory_storage_mgr(env, conf_ctx);
    sandesha2_storage_mgr_init_storage(storage_mgr, env, module_desc);
    
    storage_mgr = sandesha2_utils_get_permanent_storage_mgr(env, conf_ctx);
    sandesha2_storage_mgr_init_storage(storage_mgr, env, module_desc);
    
    /* we need to add permenent storage mgr as well */
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
        "[sandesha2] module initializing completed");
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
mod_sandesha2_shutdown(axis2_module_t *module,
                        const axutil_env_t *env)
{

    /* currently we don't have conf_ctx passing to shutdown. When we have that
     * we need to write these util functions at sandesha2_utils
     * sandesha2_utils_stop_sender(env, conf_ctx);
     * sandesha2_utils_stop_invoker(env, conf_ctx);
     */
    if(module->handler_create_func_map)
    {
        /* TODO
         *  do the neccessary clean in hash map
         */
        axutil_hash_free(module->handler_create_func_map, env);
        module->handler_create_func_map = NULL;
    }
    
    if(module)
    {
        AXIS2_FREE(env->allocator, module);
        module = NULL;
    }
    return AXIS2_SUCCESS; 
}

axis2_status_t AXIS2_CALL
mod_sandesha2_fill_handler_create_func_map(axis2_module_t *module,
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
    axutil_hash_set(module->handler_create_func_map, "SandeshaGlobalInHandler", 
        AXIS2_HASH_KEY_STRING, sandesha2_global_in_handler_create);
    axutil_hash_set(module->handler_create_func_map, "SandeshaInHandler", 
        AXIS2_HASH_KEY_STRING, sandesha2_in_handler_create);
    axutil_hash_set(module->handler_create_func_map, "SandeshaOutHandler",
        AXIS2_HASH_KEY_STRING, sandesha2_out_handler_create);
    
    return AXIS2_SUCCESS;
}

/**
 * Following block distinguish the exposed part of the dll.
 */

AXIS2_EXPORT int 
axis2_get_instance(axis2_module_t **inst,
                   const axutil_env_t *env)
{
   *inst = mod_sandesha2_create(env);
    if(!(*inst))
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
        status = mod_sandesha2_shutdown(inst, env);
    }
    return status;
}
