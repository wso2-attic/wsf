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

#ifndef AXIS2_PHASE_RESOLVER_H
#define AXIS2_PHASE_RESOLVER_H

/**
 * @defgroup axis2_phase_resolver phase resolver
 * @ingroup axis2
 * @{
 * @}
 */

/** 
 * @defgroup axis2_phase_res phase resolver
 * @ingroup axis2_phase_resolver
 * holds phase information in relation to a given service. Encapsulates a 
 * reference to axis configuration, the service the phase resolver related to 
 * and a phase holder instance that holds the list of phases.
 * @{
 */

/**
 * @file axis2_phase_resolver.h
 */

#include <axis2_const.h>
#include <axutil_error.h>
#include <axis2_defines.h>
#include <axutil_env.h>
#include <axutil_allocator.h>
#include <axutil_qname.h>
#include <axutil_array_list.h>
#include <axutil_hash.h>
#include <axis2_handler_desc.h>
#include <axis2_phase.h>
#include <axis2_phase_rule.h>
#include <axis2_handler.h>
#include <axis2_handler_desc.h>
#include <axis2_flow.h>
#include <axis2_module_desc.h>
#include <axis2_phase_holder.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /** Type name for axis2_phase_resolver */
    typedef struct axis2_phase_resolver axis2_phase_resolver_t;

    struct axis2_phase;
    struct axis2_handler_desc;
    struct axis2_module_desc;
    struct axis2_handler;
    struct axis2_phase_rule;
    struct axis2_svc;
    struct axis2_conf;
    struct axis2_op;
    struct axis2_phase_holder;

    /** 
     * Frees phase resolver.
     * @param phase_resolver pointer to phase resolver
     * @param env pointer to environment struct
     * @return void
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_phase_resolver_free(axis2_phase_resolver_t *phase_resolver,
        const axutil_env_t *env);

    /**
     * Builds the execution chains. Execution chains are collection of 
     * phases that are invoked in the execution path.
     * @param phase_resolver pointer to phase resolver
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_phase_resolver_build_chains(axis2_phase_resolver_t *phase_resolver,
        const axutil_env_t *env);

    /**
     * Builds execution chains for given operation.
     * @param phase_resolver pointer to phase resolver
     * @param env pointer to environment struct
     * @param op pointer to operation
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_phase_resolver_build_module_op(axis2_phase_resolver_t *phase_resolver,
        const axutil_env_t *env,
        struct axis2_op *op);

    /**
     * Builds transport chains.
     * @param phase_resolver pointer to phase resolver
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_phase_resolver_build_transport_chains(axis2_phase_resolver_t *phase_resolver,
        const axutil_env_t *env);


    /**
     * Engages the given module globally. Engaging a module globally means 
     * that the given module would be engaged to all operations in all 
     * services.
     * @param phase_resolver pointer to phase resolver
     * @param env pointer to environment struct
     * @param module pointer to module
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_phase_resolver_engage_module_globally(axis2_phase_resolver_t *phase_resolver,
        const axutil_env_t *env,
        struct axis2_module_desc *module);

    /**
     * Engages the given global module to the given service. This means 
     * the given module would be engaged to all operations of the given 
     * service. 
     * @param phase_resolver pointer to phase resolver
     * @param env pointer to environment struct
     * @param svc pointer to service
     * @param module_desc pointer to module description
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_phase_resolver_engage_module_to_svc_from_global(axis2_phase_resolver_t *phase_resolver,
        const axutil_env_t *env,
        struct axis2_svc *svc,
        struct axis2_module_desc *module_desc);

    /**
     * Engages the given module to the given service. This means 
     * the given module would be engaged to all operations of the given 
     * service. 
     * @param phase_resolver pointer to phase resolver
     * @param env pointer to environment struct
     * @param svc pointer to service
     * @param module_desc pointer to module description
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_phase_resolver_engage_module_to_svc(axis2_phase_resolver_t *phase_resolver,
        const axutil_env_t *env,
        struct axis2_svc *svc,
        struct axis2_module_desc *module_desc);


    /**
     * Disengages the given module from the given service. This means 
     * the given module would be disengaged from all operations of the given 
     * service. 
     * @param phase_resolver pointer to phase resolver
     * @param env pointer to environment struct
     * @param svc pointer to service
     * @param module_desc pointer to module description
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_phase_resolver_disengage_module_from_svc(axis2_phase_resolver_t *phase_resolver,
        const axutil_env_t *env,
        struct axis2_svc *svc,
        struct axis2_module_desc *module_desc);

    /**
     * Engages the given module to the given operation.
     * @param phase_resolver pointer to phase resolver
     * @param env pointer to environment struct
     * @param axis_op pointer to axis operation
     * @param pointer to module description
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_phase_resolver_engage_module_to_op(axis2_phase_resolver_t *phase_resolver,
        const axutil_env_t *env,
        struct axis2_op *axis_op,
        struct axis2_module_desc *module_desc);


    /**
     * Disengages the given module from the given operation.
     * @param phase_resolver pointer to phase resolver
     * @param env pointer to environment struct
     * @param axis_op pointer to axis operation
     * @param pointer to module description
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_phase_resolver_disengage_module_from_op(axis2_phase_resolver_t *phase_resolver,
        const axutil_env_t *env,
        struct axis2_op *axis_op,
        struct axis2_module_desc *module_desc);


    /**
     * Creates phase resolver struct.
     * @param env pointer to environment struct
     * @return pointer to newly created phase resolver
     */
    AXIS2_EXTERN axis2_phase_resolver_t *AXIS2_CALL
    axis2_phase_resolver_create (const axutil_env_t *env);

    /**
     * Creates phase resolver struct with given configuration.
     * @param env pointer to environment struct
     * @param axis2_config pointer to aixs2 configuration, phase resolver 
     * created would not assume ownership of configuration
     * @return pointer to newly created phase resolver
     */
    AXIS2_EXTERN axis2_phase_resolver_t *AXIS2_CALL
    axis2_phase_resolver_create_with_config (const axutil_env_t *env,
        struct axis2_conf *axis2_config);

    /**
     * Creates phase resolver struct with given configuration and service.
     * @param env pointer to environment struct
     * @param aixs2_config pointer to aixs2 configuration,  phase resolver 
     * created would not assume ownership of configuration
     * @param svc pointer to service,  phase resolver 
     * created would not assume ownership of service
     * @return pointer to newly created phase resolver
     */
    AXIS2_EXTERN axis2_phase_resolver_t *AXIS2_CALL
    axis2_phase_resolver_create_with_config_and_svc(const axutil_env_t *env,
        struct axis2_conf *axis2_config,
        struct axis2_svc *svc);

/** @} */

#ifdef __cplusplus
}
#endif
#endif  /* AXIS2_PHASE_RESOLVER_H */
