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

#ifndef AXIS2_SVC_GRP_CTX_H
#define AXIS2_SVC_GRP_CTX_H

/** 
 * @defgroup axis2_svc_grp_ctx service group context
 * @ingroup axis2_context
 * service group context represents a running "instance" of a service group.
 * service group context allows instance of services belonging to a service
 * group to be grouped.  
 * @{
 */

/**
 * @file axis2_svc_grp_ctx.h
 */

#include <axis2_defines.h>
#include <axutil_env.h>
#include <axis2_svc_ctx.h>
#include <axis2_svc_grp.h>

#ifdef __cplusplus
extern "C"
{
#endif

    struct axis2_svc_grp;
    /** Type name for struct svc_grp_ctx */
    typedef struct axis2_svc_grp_ctx axis2_svc_grp_ctx_t;

    /**
     * Creates a service group context struct.
     * @param env pointer to environment struct
     * @param svc_grp pointer to service group that this service context 
     * represents, service group context does not assume the ownership of the struct
     * @param conf_ctx pointer to configuration context, the parent context 
     * of the newly created service group context, service group context does not 
     * assume the ownership of the struct
     * @return pointer to newly created service group context
     */
    AXIS2_EXTERN axis2_svc_grp_ctx_t *AXIS2_CALL
    axis2_svc_grp_ctx_create(
        const axutil_env_t *env,
        struct axis2_svc_grp *svc_grp,
        struct axis2_conf_ctx *conf_ctx);

    /**
     * Gets base which is of type context.
     * @param svc_grp_ctx pointer to service group context
     * @param env pointer to environment
     * @return pointer to base context struct, returns a reference not a 
     * cloned copy
     */
    AXIS2_EXTERN axis2_ctx_t *AXIS2_CALL
    axis2_svc_grp_ctx_get_base(const axis2_svc_grp_ctx_t *svc_grp_ctx,
        const axutil_env_t *env);


    /**
     * Gets parent. configuration context is the parent of any service group 
     * context instance.
     * @param svc_grp_ctx pointer to service group context
     * @param env pointer to environment struct
     * @return pointer to configuration context, parent of service group 
     */
    AXIS2_EXTERN struct axis2_conf_ctx *AXIS2_CALL
    axis2_svc_grp_ctx_get_parent(const axis2_svc_grp_ctx_t *svc_grp_ctx,
        const axutil_env_t *env);


    /**
     * Frees service group context.
     * @param svc_grp_ctx pointer to service group context
     * @param env pointer to environment struct
     * @return void
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_svc_grp_ctx_free(struct axis2_svc_grp_ctx *svc_grp_ctx,
        const axutil_env_t *env);

    /**
     * Initializes service group context. In this method, it pics the 
     * related service group from configuration and keeps a reference
     * for future use. 
     * @param svc_grp_ctx pointer to service group context
     * @param env pointer to environment struct
     * @param conf pointer to configuration
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_grp_ctx_init(struct axis2_svc_grp_ctx *svc_grp_ctx,
        const axutil_env_t *env,
        struct axis2_conf *conf);

    /**
     * Gets service group context ID.
     * @param svc_grp_ctx pointer to service group context
     * @param env pointer to environment struct
     * @return service group context ID string
     */
    AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
    axis2_svc_grp_ctx_get_id(const axis2_svc_grp_ctx_t *svc_grp_ctx,
        const axutil_env_t *env);

    /**
     * Sets service group context ID.
     * @param svc_grp_ctx pointer to service group context
     * @param env pointer to environment struct
     * @return id service group context ID
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_grp_ctx_set_id(struct axis2_svc_grp_ctx *svc_grp_ctx,
        const axutil_env_t *env,
        const axis2_char_t *id);

    /** 
     * Gets named service context.
     * @param svc_grp_ctx pointer to service group context
     * @param env pointer to environment struct
     * @param svc_name name of service context to be retrieved
     * @return pointer to named service context
     */
    AXIS2_EXTERN struct axis2_svc_ctx *AXIS2_CALL
    axis2_svc_grp_ctx_get_svc_ctx(const axis2_svc_grp_ctx_t *svc_grp_ctx,
        const axutil_env_t *env,
        const axis2_char_t *svc_name);

    /**
     * Fills service context map. This will create one service context per 
     * each service in the service group related to this service context.
     * @param svc_grp_ctx pointer to service group context
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_grp_ctx_fill_svc_ctx_map(struct axis2_svc_grp_ctx *svc_grp_ctx,
        const axutil_env_t *env);

    /**
     * Gets service group related to this service context. 
     * @param svc_grp_ctx pointer to service group context
     * @param env pointer to environment struct
     * @return pointer to service group that this service group context 
     * represents
     */
    AXIS2_EXTERN struct axis2_svc_grp *AXIS2_CALL
    axis2_svc_grp_ctx_get_svc_grp(const axis2_svc_grp_ctx_t *svc_grp_ctx,
        const axutil_env_t *env);

    /**
     * Gets service context map containing all service contexts.
     * @param svc_grp_ctx pointer to service group context
     * @param env pointer to environment struct
     * @return pointer to hash table containing the service context map
     */
    AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
    axis2_svc_grp_ctx_get_svc_ctx_map(const axis2_svc_grp_ctx_t *svc_grp_ctx,
        const axutil_env_t *env);

#ifdef __cplusplus
}
#endif

#endif                          /* AXIS2_SVC_GRP_CTX_H */
