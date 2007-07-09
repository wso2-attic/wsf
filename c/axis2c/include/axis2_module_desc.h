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
#ifndef AXIS2_MODULE_DESC_H
#define AXIS2_MODULE_DESC_H

/** 
 * @defgroup axis2_module_desc module description
 * @ingroup axis2_desc
 * module holds information about a module. This information includes module 
 * parameters and handler information. 
 * Modules are available to all services if axis2.xml has a module reference 
 * entry. Alternatively, a module could be made available to selected services
 * by including a module reference entry in services.xml.
 * @{
 */

#include <axis2_const.h>
#include <axutil_error.h>
#include <axis2_defines.h>
#include <axutil_env.h>
#include <axutil_allocator.h>
#include <axutil_string.h>
#include <axutil_array_list.h>
#include <axutil_param_container.h>
#include <axis2_flow_container.h>
#include <axutil_param.h>
#include <axis2_op.h>
#include <axis2_conf.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /** Type name for struct axis2_module_desc */
    typedef struct axis2_module_desc axis2_module_desc_t;

    struct axis2_op;
    struct axis2_conf;

    /**
     * Frees module description.
     * @param module_desc pointer to module description
     * @param env pointer to environment struct
     * @return void
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_module_desc_free(axis2_module_desc_t *module_desc,
        const axutil_env_t *env);

    /**
     * Gets flow representing in flow.
     * @param module_desc pointer to module description
     * @param env pointer to environment struct
     * @return pointer to flow that represents in flow, returns a reference
     * not a cloned copy
     */
    AXIS2_EXTERN axis2_flow_t *AXIS2_CALL
    axis2_module_desc_get_in_flow(const axis2_module_desc_t *module_desc,
        const axutil_env_t *env);

    /**
     * Sets flow representing in flow.
     * @param module_desc pointer to module description
     * @param env pointer to environment struct
     * @param in_flow pointer to flow representing in flow, module assumes 
     * ownership of flow
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_module_desc_set_in_flow(axis2_module_desc_t *module_desc,
        const axutil_env_t *env,
        axis2_flow_t *in_flow);

    /**
     * Gets flow representing out flow.
     * @param module_desc pointer to module description
     * @param env pointer to environment struct
     * @return pointer to flow that represents out flow, returns a reference
     * not a cloned copy         
     */
    AXIS2_EXTERN axis2_flow_t *AXIS2_CALL
    axis2_module_desc_get_out_flow(const axis2_module_desc_t *module_desc,
        const axutil_env_t *env);

    /**
     * Sets flow representing out flow.
     * @param module_desc pointer to module description
     * @param env pointer to environment struct
     * @param out_flow pointer to flow representing out flow, module assumes 
     * ownership of flow
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_module_desc_set_out_flow(axis2_module_desc_t *module_desc,
        const axutil_env_t *env,
        axis2_flow_t *out_flow);

    /**
     * Gets flow representing fault in flow.
     * @param module_desc pointer to module description
     * @param env pointer to environment struct
     * @return pointer to flow that represents fault in flow, returns a reference
     * not a cloned copy         
     */
    AXIS2_EXTERN axis2_flow_t *AXIS2_CALL
    axis2_module_desc_get_fault_in_flow(const axis2_module_desc_t *module_desc,
        const axutil_env_t *env);

    /**
     * Sets flow representing fault in flow.
     * @param module_desc pointer to module description
     * @param env pointer to environment struct
     * @param falut_in_flow pointer to flow representing fault in flow, 
     * module assumes ownership of flow
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_module_desc_set_fault_in_flow(axis2_module_desc_t *module_desc,
        const axutil_env_t *env,
        axis2_flow_t *falut_in_flow);

    /**
     * Gets flow representing fault out flow.
     * @param module_desc pointer to module description
     * @param env pointer to environment struct
     * @return pointer to flow that represents fault out flow, returns a 
     * reference not a cloned copy         
     */
    AXIS2_EXTERN axis2_flow_t *AXIS2_CALL
    axis2_module_desc_get_fault_out_flow(const axis2_module_desc_t *module_desc,
        const axutil_env_t *env);

    /**
     * Sets flow representing fault out flow.
     * @param module_desc pointer to module description
     * @param env pointer to environment struct
     * @param fault_out_flow pointer to flow representing fault out flow, 
     * module assumes ownership of flow
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_module_desc_set_fault_out_flow(axis2_module_desc_t *module_desc,
        const axutil_env_t *env,
        axis2_flow_t *fault_out_flow);

    /**
     * Gets module QName.
     * @param module_desc pointer to module description
     * @param env pointer to environment struct
     * @return pointer to QName
     */
    AXIS2_EXTERN const axutil_qname_t *AXIS2_CALL
    axis2_module_desc_get_qname(const axis2_module_desc_t *module_desc,
        const axutil_env_t *env);

    /**
     * Sets module QName.
     * @param module_desc pointer to module description
     * @param env pointer to environment struct
     * @param qname pointer to qname
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_module_desc_set_qname(axis2_module_desc_t *module_desc,
        const axutil_env_t *env,
        const axutil_qname_t *qname);

    /**
     * Adds given operation to module.
     * @param module_desc pointer to module description
     * @param env pointer to environment struct
     * @param op pointer to operation, module assumes ownership of operation
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_module_desc_add_op(axis2_module_desc_t *module_desc,
        const axutil_env_t *env,
        struct axis2_op *op);

    /**
     * Gets all operations associated with module.
     * @param module_desc pointer to module description
     * @param env pointer to environment struct
     * @return pointer to hash map containing the operations
     */
    AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
    axis2_module_desc_get_all_ops(const axis2_module_desc_t *module_desc,
        const axutil_env_t *env);

    /**
     * Gets parent which is of type configuration.
     * @param module_desc pointer to module description
     * @param env pointer to environment struct
     * @return pointer to configuration, returns a reference not a 
     * cloned copy
     */
    AXIS2_EXTERN struct axis2_conf *AXIS2_CALL
    axis2_module_desc_get_parent(const axis2_module_desc_t *module_desc,
        const axutil_env_t *env);

    /**
     * Sets parent which is of type configuration.
     * @param module_desc pointer to module description
     * @param env pointer to environment struct
     * @param parent pointer to parent configuration, module does not assume
     * the ownership of configuration
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_module_desc_set_parent(axis2_module_desc_t *module_desc,
        const axutil_env_t *env,
        struct axis2_conf *parent);

    /**
     * Add parameter
     * @param module_desc pointer to module description
     * @param env pointer to environment struct
     * @param param pointer to parameter struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_module_desc_add_param(axis2_module_desc_t *module_desc,
        const axutil_env_t *env,
        axutil_param_t *param);

    /**
     * Gets parameter with given name.
     * @param module_desc pointer to module description
     * @param env pointer to environment struct
     * @param name parameter name string
     * @return pointer to parameter corresponding to given name
     */
    AXIS2_EXTERN axutil_param_t *AXIS2_CALL
    axis2_module_desc_get_param(const axis2_module_desc_t *module_desc,
        const axutil_env_t *env,
        const axis2_char_t *name);

    /**
     * Gets all parameters associated with module.
     * @param module_desc pointer to module description
     * @param env pointer to environment struct
     * @param pointer to array list containing all parameters
     */
    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    axis2_module_desc_get_all_params(const axis2_module_desc_t *module_desc,
        const axutil_env_t *env);

    /**
     * Checks if a given parameter is locked.
     * @param module_desc pointer to module description
     * @param env pointer to environment struct
     * @param param_name parameter name string 
     * @return AXIS2_TRUE if named parameter is locked, else AXIS2_FALSE
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_module_desc_is_param_locked(const axis2_module_desc_t *module_desc,
        const axutil_env_t *env,
        const axis2_char_t *param_name);

    /**
     * Gets module associated with module description.
     * @param module_desc pointer to module description
     * @param env pointer to environment struct
     * @return pointer to module
     */
    AXIS2_EXTERN struct axis2_module *AXIS2_CALL
    axis2_module_desc_get_module(const axis2_module_desc_t *module_desc,
        const axutil_env_t *env);

    /**
     * @param module_desc pointer to module description
     * @param env pointer to environment struct
     * @param module pointer to module, module description assumes ownership
     * of module
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_module_desc_set_module(axis2_module_desc_t *module_desc,
        const axutil_env_t *env,
        struct axis2_module *module);

    AXIS2_EXTERN axutil_param_container_t *AXIS2_CALL
    axis2_module_desc_get_param_container(const axis2_module_desc_t *module_desc,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_flow_container_t *AXIS2_CALL
    axis2_module_desc_get_flow_container(const axis2_module_desc_t *module_desc,
        const axutil_env_t *env);

    /**
     * Creates module description struct instance.
     * @param env pointer to environment struct
     * @return pointer to newly created module description
     */
    AXIS2_EXTERN axis2_module_desc_t *AXIS2_CALL
    axis2_module_desc_create (const axutil_env_t *env);

    /**
     * Creates module description struct instance with given QName.
     * @param env pointer to environment struct
     * @param qname pointer to QName
     * @return pointer to newly created module description
     */
    AXIS2_EXTERN axis2_module_desc_t *AXIS2_CALL
    axis2_module_desc_create_with_qname(const axutil_env_t *env,
        const axutil_qname_t *qname);

    /**
     * Frees module description passed as void pointer. This method will cast 
     * the void pointer parameter into appropriate type and then call module 
     * description free method on top of that pointer.
     * @param module_desc pointer to module description as a void pointer
     * @param env pointer to environment struct
     * @return void
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_module_desc_free_void_arg(void *module_desc,
        const axutil_env_t *env);


/** @} */

#ifdef __cplusplus
}
#endif
#endif /* AXIS2_MODULE_DESC_H */
