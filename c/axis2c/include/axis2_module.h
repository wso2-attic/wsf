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
#ifndef AXIS2_MODULE_H
#define AXIS2_MODULE_H

/** 
 * @defgroup axis2_module module
 * @ingroup axis2_desc
 * Every module provides an implementation of struct interface. Modules are in 
 * one of two states: "available" or "initialized". All modules that the run-time
 * detects (from the repository modules directory) are said to be in the 
 * "available" state. If some service indicates a dependency on this
 * module then the module is initialized (once for the life time of the system) 
 * and the state changes to "initialized".
 * Any module which is in the "initialized" state can be engaged as needed
 * by the engine to respond to a message. Module engagement is done by 
 * deployment engine using module.xml. 
 * @{
 */

/**
 * @file axis2_module.h
 */

#include <axis2_const.h>
#include <axutil_error.h>
#include <axis2_defines.h>
#include <axutil_env.h>
#include <axutil_allocator.h>
#include <axutil_string.h>
#include <axis2_conf.h>
#include <axis2_module_desc.h>
#include <axutil_hash.h>


#ifdef __cplusplus
extern "C"
{
#endif

    /** Type name for axis2_module_ops */
    typedef struct axis2_module_ops axis2_module_ops_t;
    /** Type name for axis2_module_ops */
    typedef struct axis2_module axis2_module_t;

    struct axis2_conf;

    struct axis2_module_ops
    {
        /**
         * Initializes module.
         * @param module pointer to module struct
         * @param env pointer to environment struct
         * @param conf_ctx pointer to configuration context
         * @param module_desc module description
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
         */
        axis2_status_t (AXIS2_CALL *
                init) (
                    axis2_module_t *module,
                    const axutil_env_t *env,
                    struct axis2_conf_ctx *conf_ctx,
                    axis2_module_desc_t *module_desc);

        /**
         * Shutdowns module.
         * @param module pointer to module struct
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
         */
        axis2_status_t (AXIS2_CALL *
                shutdown)(
                    axis2_module_t *module,
                    const axutil_env_t *env);

        /**
         * Fills the hash map of handler create functions for the module.
         * @param module pointer to module struct
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
         */        
        axis2_status_t (AXIS2_CALL *
                fill_handler_create_func_map)(
                    axis2_module_t *module,
                    const axutil_env_t *env);


    };

    /**
     * module struct.
     */
    struct axis2_module
    {
        /** operations of module */
        const axis2_module_ops_t *ops;
        /** hash map of handler create functions */
        axutil_hash_t *handler_create_func_map;
    };

    /**
     * Creates module struct.
     * @param env pointer to environment struct
     * @return pointer to newly created module
     */
    AXIS2_EXTERN axis2_module_t * AXIS2_CALL
    axis2_module_create (
        const axutil_env_t *env);

/** Initializes module.
    @sa axis2_module_ops#init */
#define AXIS2_MODULE_INIT(module, env, conf_ctx, module_desc) \
      ((module)->ops->init (module, env, conf_ctx, module_desc))

/** Shutdowns module.
    @sa axis2_module_ops#shutdown */
#define AXIS2_MODULE_SHUTDOWN(module, env) \
      ((module)->ops->shutdown (module, env))

/** Fills handler create function map.
    @sa axis2_module_ops#fill_handler_create_func_map */    
#define AXIS2_MODULE_FILL_HANDLER_CREATE_FUNC_MAP(module, env) \
      ((module)->ops->fill_handler_create_func_map (module, env))

/** @} */

#ifdef __cplusplus
}
#endif
#endif /* AXIS2_MODULE_H */
