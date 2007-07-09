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

#ifndef AXIS2_CONF_CTX_H
#define AXIS2_CONF_CTX_H

/** 
 * @defgroup axis2_conf_ctx configuration context
 * @ingroup axis2_context
 * configuration context is the holder for all the state information 
 * related to configuration. It holds all the service group context, service
 * context and operation context that exists within an engine instance. 
 * An engine instance has only one configuration context associated with it
 * (Singleton pattern). 
 * @{
 */

/**
 * @file axis2_conf_ctx.h
 */

#include <axis2_defines.h>
#include <axutil_hash.h>
#include <axutil_env.h>
#include <axis2_ctx.h>
#include <axis2_svc_grp_ctx.h>

#ifdef __cplusplus
extern "C"
{
#endif


    /** Type name for struct axis2_conf_ctx */
    typedef struct axis2_conf_ctx axis2_conf_ctx_t;
    struct axis2_conf;

    /**
     * Creates a configuration context struct instance.
     * @param env pointer to environment struct
     * @param conf pointer to configuration, configuration context assumes 
     * ownership of the configuration
     * @return pointer to newly created configuration context 
     */
    AXIS2_EXTERN axis2_conf_ctx_t *AXIS2_CALL
    axis2_conf_ctx_create(const axutil_env_t *env, 
        struct axis2_conf *conf);

    /**
     * Sets the configuration associated with the engine instance.
     * @param conf_ctx pointer to configuration context
     * @param env pointer to environment struct
     * @param conf pointer to configuration 
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t  AXIS2_CALL 
    axis2_conf_ctx_set_conf(axis2_conf_ctx_t *conf_ctx,
        const axutil_env_t *env,
        struct axis2_conf *conf);
    /**
     * Gets the base struct, which is of type context
     * @param conf_ctx pointer to configuration context
     * @param env pointer to environment struct
     * @return pointer to context struct, returns a reference not a cloned
     * copy
     */
    AXIS2_EXTERN axis2_ctx_t * AXIS2_CALL
    axis2_conf_ctx_get_base(const axis2_conf_ctx_t *conf_ctx,
        const axutil_env_t *env);

    /**
     * Gets the configuration of the engine.
     * @param conf_ctx pointer to configuration context
     * @param env pointer to environment struct
     * @return pointer to configuration struct, returns a reference not a 
     * cloned copy
     */
    AXIS2_EXTERN axis2_conf_t * AXIS2_CALL
    axis2_conf_ctx_get_conf(const axis2_conf_ctx_t *conf_ctx,
        const axutil_env_t *env);

    /**
     * Gets the hash map of operation context instances.
     * @param conf_ctx pointer to configuration context
     * @param env pointer to environment struct
     * @return pointer to hash map containing all operation contexts
     */
    AXIS2_EXTERN axutil_hash_t * AXIS2_CALL
    axis2_conf_ctx_get_op_ctx_map(const axis2_conf_ctx_t *conf_ctx,
        const axutil_env_t *env);

    /**
     * Gets the hash map of service context instances.
     * @param conf_ctx pointer to configuration context
     * @param env pointer to environment struct
     * @return pointer to hash map containing all service contexts
     */
    AXIS2_EXTERN axutil_hash_t * AXIS2_CALL
    axis2_conf_ctx_get_svc_ctx_map(const axis2_conf_ctx_t *conf_ctx,
        const axutil_env_t *env);

    /**
     * Gets the hash map of service group context instances.
     * @param conf_ctx pointer to configuration context
     * @param env pointer to environment struct
     * @return pointer to hash map containing all service group contexts
     */
    AXIS2_EXTERN axutil_hash_t * AXIS2_CALL
    axis2_conf_ctx_get_svc_grp_ctx_map(const axis2_conf_ctx_t *conf_ctx,
        const axutil_env_t *env);

    /**
     * Registers an operation context with the given message ID.
     * @param conf_ctx pointer to configuration context
     * @param env pointer to environment struct
     * @param message_id message id related to the operation context
     * @param op_ctx pointer to operation context, conf context assumes
     * ownership of the operation context 
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t  AXIS2_CALL
    axis2_conf_ctx_register_op_ctx(axis2_conf_ctx_t *conf_ctx,
        const axutil_env_t *env,
        const axis2_char_t *message_id,
        axis2_op_ctx_t *op_ctx);

    /**
     * Gets operation context corresponding to the given message ID.
     * @param conf_ctx pointer to configuration context
     * @param env pointer to environment struct
     * @param message_id message ID related to the operation to be retrieved
     * @return pointer to operation context related to the given message ID
     */
    AXIS2_EXTERN axis2_op_ctx_t * AXIS2_CALL
    axis2_conf_ctx_get_op_ctx(const axis2_conf_ctx_t *conf_ctx,
        const axutil_env_t *env,
        const axis2_char_t *message_id);

    /**
     * Registers a service context with the given service ID.
     * @param conf_ctx pointer t configuration context
     * @param env pointer to environment struct
     * @param svc_id ID of the service to be added
     * @param svc_ctx pointer to service context
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t  AXIS2_CALL
    axis2_conf_ctx_register_svc_ctx(axis2_conf_ctx_t *conf_ctx,
        const axutil_env_t *env,
        const axis2_char_t *svc_id,
        axis2_svc_ctx_t *svc_ctx);

    /**
     * Gets service context with the given service ID
     * @param conf_ctx pointer to configuration context
     * @param env pointer to environment struct
     * @param svc_id service ID
     * @return pointer to service context with the given service ID 
     */
    AXIS2_EXTERN struct axis2_svc_ctx * AXIS2_CALL
    axis2_conf_ctx_get_svc_ctx(const axis2_conf_ctx_t *conf_ctx,
        const axutil_env_t *env,
        const axis2_char_t *svc_id);

    /**
     * Registers a service group context with the given service group ID.
     * @param conf_ctx pointer to configuration context
     * @param env pointer to environment struct
     * @param svc_grp_id service group id
     * @param svc_grp_ctx pointer to service group context
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t  AXIS2_CALL
    axis2_conf_ctx_register_svc_grp_ctx(axis2_conf_ctx_t *conf_ctx,
        const axutil_env_t *env,
        const axis2_char_t *svc_grp_id,
        axis2_svc_grp_ctx_t *svc_grp_ctx);

    /**
     * Gets service group with the given service group ID.
     * @param conf_ctx pointer to configuration context
     * @param env pointer to environment struct
     * @param svc_grp_id service group id
     * @return pointer to service group context with the given ID
     */
    AXIS2_EXTERN axis2_svc_grp_ctx_t * AXIS2_CALL
    axis2_conf_ctx_get_svc_grp_ctx(const axis2_conf_ctx_t *conf_ctx,
        const axutil_env_t *env,
        const axis2_char_t *svc_grp_id);

    /**
     * Gets the root working directory. It is in this directory that the 
     * axis2.xml configuration file is located. The services and modules 
     * sub folders too are located in this directory.
     * @param conf_ctx pointer to configuration context
     * @param env pointer to environment struct
     * @return pointer to string containing the root folder name 
     */
    AXIS2_EXTERN const axis2_char_t * AXIS2_CALL
    axis2_conf_ctx_get_root_dir(const axis2_conf_ctx_t *conf_ctx,
        const axutil_env_t *env);

    /**
     * Sets the root working directory. It is in this directory that the 
     * axis2.xml configuration file is located. The services and modules 
     * sub folders too are located in this directory.
     * @param conf_ctx pointer to configuration context
     * @param env pointer to environment struct
     * @param path string containing the path of root directory
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t  AXIS2_CALL
    axis2_conf_ctx_set_root_dir(axis2_conf_ctx_t *conf_ctx,
        const axutil_env_t *env,
        const axis2_char_t *path);

    /**
     * Initializes the configuration context. Within this function, it would 
     * initialize all the service group context, service context and 
     * operation context instances stored within configuration context.
     * @param conf_ctx pointer to configuration context
     * @param env pointer to environment struct
     * @param conf pointer to configuration struct 
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t  AXIS2_CALL
    axis2_conf_ctx_init(axis2_conf_ctx_t *conf_ctx,
        const axutil_env_t *env,
        axis2_conf_t *conf);

    /**
     * Frees configuration context struct.
     * @param conf_ctx pointer to configuration context
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN void  AXIS2_CALL
    axis2_conf_ctx_free(axis2_conf_ctx_t *conf_ctx,
        const axutil_env_t *env);

    /**
     * This method fills the context hierarchy (service group, service and 
     * operation contexts that is) for the service and operation found in 
     * the given message context. If the context hierarchy is not already 
     * built it will create the contexts and build the context hierarchy.         
     * @param conf_ctx pointer to configuration context
     * @param env pointer to environment struct
     * @param msg_ctx pointer to message context with service and operation
     * for which the context hierarchy is to be built set
     * @return pointer to the service group context, which is the root of 
     * the context hierarchy for given service and operation
     */
    AXIS2_EXTERN axis2_svc_grp_ctx_t * AXIS2_CALL
    axis2_conf_ctx_fill_ctxs(axis2_conf_ctx_t *conf_ctx,
        const axutil_env_t *env,
        axis2_msg_ctx_t *msg_ctx);

#ifdef __cplusplus
}
#endif

#endif                          /* AXIS2_CONF_CTX_H */
