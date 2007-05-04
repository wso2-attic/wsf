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

#ifndef AXIS2_MODULE_BUILDER_H
#define AXIS2_MODULE_BUILDER_H

/** @defgroup axis2_module_builder Module Builder
 * @ingroup axis2_deployment
 * @{
 */

#include <axis2_const.h>
#include <axutil_error.h>
#include <axis2_defines.h>
#include <axutil_env.h>
#include <axutil_allocator.h>
#include <axutil_qname.h>
#include <axis2_module_desc.h>
#include <axis2_dep_engine.h>
#include <axis2_desc_builder.h>

#ifdef __cplusplus
extern "C"
{
#endif
    
    /** Type name for struct axis2_module_builder */
    typedef struct axis2_module_builder axis2_module_builder_t;

    /** 
     * De-allocate memory
     * @param module_builder pointer to module builder
     * @param env pointer to environment struct
     * @return void
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_module_builder_free(axis2_module_builder_t *module_builder,
        const axutil_env_t *env);

    /**
     * @param module_builder pointer to module builder
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_module_builder_populate_module(axis2_module_builder_t *module_builder,
        const axutil_env_t *env);

    /**
     * Creates module builder struct
     * @param env pointer to environment struct
     * @return pointer to newly created module builder
     */
    AXIS2_EXTERN axis2_module_builder_t *AXIS2_CALL
    axis2_module_builder_create(const axutil_env_t *env);

    /**
     * Creates module builder struct
     * @param env pointer to environment struct
     * @param file_name pointer to file name
     * @param dep_engine pointer to deployment engine
     * @return pointer to newly created module builder
     */
    AXIS2_EXTERN axis2_module_builder_t *AXIS2_CALL
    axis2_module_builder_create_with_file_and_dep_engine_and_module(const axutil_env_t *env,
        axis2_char_t *file_name,
        struct axis2_dep_engine *dep_engine,
        axis2_module_desc_t *module);

/** Populates the module. 
#define AXIS2_MODULE_BUILDER_POPULATE_MODULE(module_builder, env) \
      axis2_module_builder_populate_module (module_builder, env)*/

/** @} */

#ifdef __cplusplus
}
#endif
#endif  /* AXIS2_MODULE_BUILDER_H */
