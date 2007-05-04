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

#ifndef AXIS2_OP_H
#define AXIS2_OP_H

/** 
 * @defgroup axis2_op operation
 * @ingroup axis2_desc
 * operation represents the static structure of an operation in a service. 
 * In Axis2 description hierarchy, an operation lives inside the service to 
 * which it belongs. 
 * operations are configured in services.xml files located in the respective 
 * service group folders of the services folder in the repository. 
 * In services.xml file, operations are declared in association with a given 
 * service. The deployment engine would create operation instances to represent 
 * those configured operations and would associate them with the respective 
 * service in the configuration.
 * operation encapsulates data on message exchange pattern (MEP), the 
 * execution flows, engaged module information, and the message receiver 
 * associated with the operation.
 * @{
 */

#include <axutil_param_container.h>
#include <axis2_svc.h>
#include <axis2_msg_recv.h>
#include <axutil_array_list.h>
#include <axis2_module_desc.h>
#include <axis2_description.h>
#include <axis2_phase_meta.h>
#include <axis2_relates_to.h>
#include <axis2_msg_ctx.h>
#include <axis2_op_ctx.h>
#include <axis2_svc_ctx.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /** Type name for struct axis2_op */
    typedef struct axis2_op axis2_op_t;

    struct axis2_svc;
    struct axis2_msg_recv;
    struct axutil_param_container;
    struct axis2_module_desc;
    struct axis2_op;
    struct axis2_relates_to;
    struct axis2_op_ctx;
    struct axis2_svc_ctx;
    struct axis2_msg_ctx;
    struct axis2_msg;
    struct axis2_conf;

/** SOAP action string constant */
#define AXIS2_SOAP_ACTION "soapAction"

    
    /**
     * Creates operation struct.
     * @param env pointer to environment struct
     * @return pointer to newly created operation
     */
    AXIS2_EXTERN axis2_op_t *AXIS2_CALL
    axis2_op_create(const axutil_env_t *env);


    /**
     * Frees operation.
     * @param op pointer to operation
     * @param env pointer to environment struct
     * @return void
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_op_free(axis2_op_t *op,
        const axutil_env_t *env);

    /**
     * Frees operation given as a void pointer.
     * @param op pointer to operation as a void pointer
     * @param env pointer to environment struct
     * @return void
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_op_free_void_arg(void *op,
        const axutil_env_t *env);


    /**
     * Adds a parameter to method.
     * @param op pointer to operation
     * @param env pointer to environment struct
     * @param param pointer parameter to be added, operation assumes 
     * ownership of parameter
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_op_add_param(axis2_op_t *op,
        const axutil_env_t *env,
        axutil_param_t *param);

    /**
     * Gets named parameter.
     * @param op pointer to operation
     * @param env pointer to environment struct
     * @param name name of parameter to be retrieved as a string 
     * @return pointer to named parameter if exists, else NULL. Returns a
     * reference, not a cloned copy
     */
    AXIS2_EXTERN axutil_param_t *AXIS2_CALL
    axis2_op_get_param(const axis2_op_t *op,
        const axutil_env_t *env,
        const axis2_char_t *name);

    /**
     * Gets all parameters.
     * @param op pointer to operation
     * @param env pointer to environment struct
     * @return pointer to array list containing all parameters, returns
     * a reference, not a cloned copy
     */
    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    axis2_op_get_all_params(const axis2_op_t *op,
        const axutil_env_t *env);

    /**
     * Checks if the named parameter is locked.
     * @param op pointer to operation
     * @param env pointer to environment struct
     * @param param_name name of the parameter to be checked
     * @return AXIS2_TRUE if named parameter is locked, else AXIS2_FALSE
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_op_is_param_locked(axis2_op_t *op,
        const axutil_env_t *env,
        const axis2_char_t *param_name);

    /**
     * Sets parent. Parent of an operation is of type service.
     * @param op pointer to operation
     * @param env pointer to environment struct
     * @param svc pointer to parent service, operation does not assume
     * ownership of service 
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_op_set_parent(axis2_op_t *op,
        const axutil_env_t *env,
        struct axis2_svc *svc);

    /**
     * Gets parent. Parent of an operation is of type service.
     * @param op pointer to operation
     * @param env pointer to environment struct
     * @return pointer to parent service, returns a reference, not a cloned 
     * copy
     */
    AXIS2_EXTERN struct axis2_svc *AXIS2_CALL
    axis2_op_get_parent(const axis2_op_t *op,
        const axutil_env_t *env);

    /**
     * Sets operation QName.
     * @param op pointer to operation as a void pointer, as this would be 
     * assigned to get_qname() method of base WSDL operation
     * @param env pointer to environment struct
     * @param qname pointer to QName, this method creates a clone of the 
     * QName
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_op_set_qname(axis2_op_t *op,
        const axutil_env_t *env,
        const axutil_qname_t *qname);

    /**
     * Gets operation QName.
     * @param op pointer to operation
     * @param env pointer to environment struct
     * @return pointer to QName, returns a reference, not a cloned copy
     */
    AXIS2_EXTERN const axutil_qname_t *AXIS2_CALL
    axis2_op_get_qname(void *op,
        const axutil_env_t *env);

    /**
     * Sets operation message exchange pattern (MEP).
     * @param op pointer to operation
     * @param env pointer to environment struct
     * @param pattern message exchange pattern string
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_op_set_msg_exchange_pattern(axis2_op_t *op,
        const axutil_env_t *env,
        const axis2_char_t *pattern);

    /**
     * Gets operation message exchange pattern (MEP).
     * @param op pointer to operation
     * @param env pointer to environment struct
     * @return MEP string
     */
    AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
    axis2_op_get_msg_exchange_pattern(const axis2_op_t *op,
        const axutil_env_t *env);

    /**
     * Sets message receiver. message receiver is responsible for invoking
     * the business logic associated with the operation.
     * @param op pointer to operation
     * @param env pointer to environment struct
     * @param msg_recv pointer to message receiver, operation assumes 
     * ownership of message receiver
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_op_set_msg_recv(axis2_op_t *op,
        const axutil_env_t *env,
        struct axis2_msg_recv *msg_recv);

    /**
     * Gets message receiver. message receiver is responsible for invoking
     * the business logic associated with the operation.
     * @param op pointer to operation
     * @param env pointer to environment struct
     * @return pointer to message receiver, returns a reference, not a 
     * cloned copy
     */
    AXIS2_EXTERN struct axis2_msg_recv *AXIS2_CALL
    axis2_op_get_msg_recv(const axis2_op_t *op,
        const axutil_env_t *env);

    /**
     * Gets style of operation. Style is that mentioned in WSDL, either 
     * RPC or document literal.
     * @param op pointer to operation
     * @param env pointer to environment struct
     * @return string representing style
     */
    AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
    axis2_op_get_style(const axis2_op_t *op,
        const axutil_env_t *env);

    /**
     * Sets style of operation. Style is that mentioned in WSDL, either 
     * RPC or document literal.
     * @param op pointer to operation
     * @param env pointer to environment struct
     * @param style string representing style
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_op_set_style(axis2_op_t *op,
        const axutil_env_t *env,
        const axis2_char_t *style);

    /**
     * Engages given module to operation.
     * @param op pointer to operation
     * @param env pointer to environment struct
     * @param module_desc pointer to module description, operation does not
     * assume ownership of struct
     * @param conf pointer to configuration, operation does not assume 
     * ownership of configuration
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_op_engage_module(axis2_op_t *op,
        const axutil_env_t *env,
        struct axis2_module_desc *module_desc,
        struct axis2_conf *conf);

    /**
     * Adds module description to engaged module list.
     * @param op pointer to operation
     * @param env pointer to environment struct
     * @param module_dec pointer to module description, operation does not
     * assume ownership of struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_op_add_to_engaged_module_list(axis2_op_t *op,
        const axutil_env_t *env,
        struct axis2_module_desc *module_dec);

    /**
     * Gets all modules associated to operation.
     * @param op pointer to operation
     * @param env pointer to environment struct
     * @return pointer to array list containing module descriptions
     */
    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    axis2_op_get_all_modules(const axis2_op_t *op,
        const axutil_env_t *env);

    /**
     * Gets Axis specific MEP constant. This method simply maps the string 
     * URI of the MEP to an integer. 
     * @param op pointer to operation
     * @param env pointer to environment struct
     * @return integer representing MEP
     */
    AXIS2_EXTERN int AXIS2_CALL
    axis2_op_get_axis_specific_mep_const(axis2_op_t *op,
        const axutil_env_t *env);

    /**
     * Gets fault in flow. Fault in flow is the list of phases invoked
     * when a fault happens along in path.
     * @param op pointer to operation
     * @param env pointer to environment struct
     * @return pointer to array list containing phases, returns a reference,
     * not a cloned copy
     */
    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    axis2_op_get_fault_in_flow(const axis2_op_t *op,
        const axutil_env_t *env);


    /**
     * Gets fault out flow. Fault out flow is the list of phases invoked
     * when a fault happens along out path.         
     * @param op pointer to operation
     * @param env pointer to environment struct
     * @return pointer to array list containing phases, returns a reference,
     * not a cloned copy
     */
    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    axis2_op_get_fault_out_flow(const axis2_op_t *op,
        const axutil_env_t *env);

    /**
     * Gets out flow. Out flow is the list of phases invoked
     * along out path.         
     * @param op pointer to operation
     * @param env pointer to environment struct
     * @return pointer to array list containing phases, returns a reference,
     * not a cloned copy         
     */
    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    axis2_op_get_out_flow(const axis2_op_t *op,
        const axutil_env_t *env);

    /**
     * Gets in flow. In flow is the list of phases 
     * invoked along in path.
     * @param op pointer to operation
     * @param env pointer to environment struct
     * @return pointer to array list containing phases, returns a reference,
     * not a cloned copy
     */
    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    axis2_op_get_in_flow(const axis2_op_t *op,
        const axutil_env_t *env);

    /**
     * Sets fault in flow. Fault in flow is the list of phases invoked
     * when a fault happens along in path.         
     * @param op pointer to operation
     * @param env pointer to environment struct
     * @param list pointer to array list containing phases, operation takes
     * over the ownership of list         
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_op_set_fault_in_flow(axis2_op_t *op,
        const axutil_env_t *env,
        axutil_array_list_t *list);

    /**
     * Sets fault out flow. Fault out flow is the list of phases invoked
     * when a fault happens along out path.         
     * @param op pointer to operation
     * @param env pointer to environment struct
     * @param list pointer to array list containing phases, operation takes
     * over the ownership of list
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_op_set_fault_out_flow(axis2_op_t *op,
        const axutil_env_t *env,
        axutil_array_list_t *list);

    /**
     * Sets out flow. Out flow is the list of phases invoked
     * along out path.         
     * @param op pointer to operation
     * @param env pointer to environment struct
     * @param list pointer to array list containing phases, operation takes
     * over the ownership of list
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_op_set_out_flow(axis2_op_t *op,
        const axutil_env_t *env,
        axutil_array_list_t *list);

    /**
     * Sets in flow. In flow is the list of phases 
     * invoked along in path.
     * @param op pointer to operation
     * @param env pointer to environment struct
     * @param list pointer to array list containing phases, operation takes
     * over the ownership of list
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_op_set_in_flow(axis2_op_t *op,
        const axutil_env_t *env,
        axutil_array_list_t *list);

    /**
     * Adds given QName to module QName list.
     * @param op pointer to operation
     * @param env pointer to environment struct
     * @param module_name pointer to module QName, QName would be cloned by 
     * this method 
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_op_add_module_qname(axis2_op_t *op,
        const axutil_env_t *env,
        const axutil_qname_t *module_qname);

    /**
     * Gets all module QNames as a list.
     * @param op pointer to operation
     * @param env pointer to environment struct
     * @return pointer to array list containing module QNames, 
     * returns a reference, not a cloned copy
     */
    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    axis2_op_get_all_module_qnames(const axis2_op_t *op,
        const axutil_env_t *env);

    /**
     * Finds operation context related to this operation using given message
     * context and service context. This method would create a new operation
     * context related to the operation, if one could not be found.
     * @param op pointer to operation
     * @param env pointer to environment struct
     * @param msg_ctx pointer to message context
     * @param svc_ctx pointer to service context
     * @return pointer to operation context, returns
     * a reference, not a cloned copy
     */
    AXIS2_EXTERN struct axis2_op_ctx *AXIS2_CALL
    axis2_op_find_op_ctx(axis2_op_t *op,
        const axutil_env_t *env,
        struct axis2_msg_ctx *msg_ctx,
        struct axis2_svc_ctx *svc_ctx);

    /**
     * Finds operation context related to this operation using given message
     * context. This method will not create a new operation context if 
     * an associated operation context could not be found.
     * @param op pointer to operation
     * @param env pointer to environment struct
     * @param msg_ctx pointer to message context
     * @return pointer to operation context if found, else NULL. Returns
     * a reference, not a cloned copy
     
     */
    AXIS2_EXTERN struct axis2_op_ctx *AXIS2_CALL
    axis2_op_find_existing_op_ctx(axis2_op_t *op,
        const axutil_env_t *env,
        const struct axis2_msg_ctx *msg_ctx);

    /**
     * Registers given operation context against this operation. Registration
     * happens within the given message context, as it is the message context
     * that captures the state information of a given invocation.
     * @param op pointer to operation
     * @param env pointer to environment struct
     * @param msg_ctx pointer to message context
     * @param op_ctx pointer to operation context, operation does not assume
     * ownership of operation context
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_op_register_op_ctx(axis2_op_t *op,
        const axutil_env_t *env,
        struct axis2_msg_ctx *msg_ctx,
        struct axis2_op_ctx *op_ctx);

    /**
     * Gets message with given label.
     * @param op pointer to operation
     * @param env pointer to environment struct
     * @return pointer to message corresponding to given label, returns 
     * a reference, not a cloned copy
     */
    AXIS2_EXTERN struct axis2_msg *AXIS2_CALL
    axis2_op_get_msg(const axis2_op_t *op,
        const axutil_env_t *env,
        const axis2_char_t *label);

    /**
     * Adds given message with the given label.
     * @param op pointer to operation
     * @param env pointer to environment struct
     * @param label label string
     * @param msg pointer to message 
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_op_add_msg(axis2_op_t *op,
        const axutil_env_t *env,
        const axis2_char_t *label,
        const struct axis2_msg *msg);

    /**
     * Checks if the operation is from a module.
     * @param op pointer to operation
     * @param env pointer to environment struct
     * AXIS2_TRUE if the operation is from a module, else AXIS2_FALSE
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_op_is_from_module(const axis2_op_t *op,
        const axutil_env_t *env);

    /**
     * Set the wsamapping list.
     * @param op pointer to operation
     * @param env pointer to environment struct
     * @param mapping_list list of action mappings
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_op_set_wsamapping_list(axis2_op_t *op,
        const axutil_env_t *env,
        axutil_array_list_t *mapping_list);

    /**
     * Get the wsamapping list.
     * @param op pointer to operation
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    axis2_op_get_wsamapping_list(axis2_op_t *op,
        const axutil_env_t *env);

    AXIS2_EXTERN axutil_param_container_t *AXIS2_CALL
    axis2_op_get_param_container(const axis2_op_t *op,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_op_remove_from_engaged_module_list(axis2_op_t *op,
        const axutil_env_t *env,
        struct axis2_module_desc *module_desc);

    /**
     * Creates operation struct for an operation defined in a module.
     * @param env pointer to environment struct
     * @return pointer to newly created operation
     */
    AXIS2_EXTERN axis2_op_t *AXIS2_CALL
    axis2_op_create_from_module(const axutil_env_t *env);

    /**
     * Creates operation struct with given QName.
     * @param env pointer to environment struct
     * @param name pointer to QName
     * @return pointer to newly created operation
     */
    AXIS2_EXTERN axis2_op_t *AXIS2_CALL
    axis2_op_create_with_qname(const axutil_env_t *env,
        const axutil_qname_t *name);

    /**
     * Frees the operation given as a void pointer. This method would cast the 
     * void parameter to an operation pointer and then call free method.
     * @param pointer to operation as a void pointer
     * @param env pointer to environment struct
     * @return void
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_op_free_void_arg(void *op,
        const axutil_env_t *env);

/** @} */
#ifdef __cplusplus
}
#endif
#endif  /* AXIS2_OP_H */
