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
#include "bam_publisher_util.h"
#include "bam_publisher_statistics.h"

/*#include <sqlite3.h>*/

axis2_status_t AXIS2_CALL
bam_publisher_shutdown(axis2_module_t *module,
                        const axutil_env_t *env);

axis2_status_t AXIS2_CALL
bam_publisher_init(axis2_module_t *module,
        const axutil_env_t *env,
        axis2_conf_ctx_t *conf_ctx,
        axis2_module_desc_t *module_desc);

axis2_status_t AXIS2_CALL
bam_publisher_fill_handler_create_func_map(
		axis2_module_t *module,
        const axutil_env_t *env);

static const axis2_module_ops_t statistics_admin_module_ops_var = {
	bam_publisher_init,
	bam_publisher_shutdown,
	bam_publisher_fill_handler_create_func_map
};

axis2_module_t *
bam_publisher_create(const axutil_env_t *env)
{
    axis2_module_t *module = NULL;
    module = AXIS2_MALLOC(env->allocator, sizeof(axis2_module_t));
    if(!module)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
           "[adminservices] Memory allocation failed for Statistics Admin Module");
        return NULL;
    }
    
    module->ops = &statistics_admin_module_ops_var;
    return module;
}

axis2_status_t AXIS2_CALL
bam_publisher_init(
        axis2_module_t *module,
        const axutil_env_t *env,
        axis2_conf_ctx_t *conf_ctx,
        axis2_module_desc_t *module_desc)
{
    axis2_status_t status = AXIS2_SUCCESS;
    
    AXIS2_LOG_TRACE(env->log, AXIS2_LOG_SI, "[adminservices] Entry:bam_publisher_init");

    AXIS2_LOG_TRACE(env->log, AXIS2_LOG_SI, "[adminservices] Exit:bam_publisher_init");

    return status;
}

axis2_status_t AXIS2_CALL
bam_publisher_shutdown(axis2_module_t *module,
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

axis2_status_t AXIS2_CALL
bam_publisher_fill_handler_create_func_map(axis2_module_t *module,
                                            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    module->handler_create_func_map = axutil_hash_make(env);
    if(!module->handler_create_func_map)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
           "[adminservices] Memory allocation failed for Statistics Admin Module");
        return AXIS2_FAILURE;
    }
    axutil_hash_set(module->handler_create_func_map, BAM_PUBLISHER_SERVICE_STAT_HANDLER, 
        AXIS2_HASH_KEY_STRING, bam_publisher_svc_stat_handler_create);

    axutil_hash_set(module->handler_create_func_map, BAM_PUBLISHER_OPERATION_STAT_HANDLER, 
        AXIS2_HASH_KEY_STRING, bam_publisher_op_stat_handler_create);
    
    return AXIS2_SUCCESS;
}

/**
 * Following block distinguish the exposed part of the dll.
 */

AXIS2_EXPORT int 
axis2_get_instance(axis2_module_t **inst,
                   const axutil_env_t *env)
{
   *inst = bam_publisher_create(env);
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
        status = bam_publisher_shutdown(inst, env);
    }
    return status;
}

