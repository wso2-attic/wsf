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

#ifndef AXIS2_SVC_CTX_H
#define AXIS2_SVC_CTX_H

/** 
 * @defgroup axis2_svc_ctx service context
 * @ingroup axis2_context
 * service context represents a running "instance" of a service.
 * service context allows instance of operations belonging to a service to be 
 * grouped. 
 * @{
 */

/**
 * @file axis2_svc_ctx.h
 */

#include <axis2_defines.h>
#include <axutil_env.h>
#include <axis2_op_ctx.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /** Type name for struct axis2_svc_ctx */
    typedef struct axis2_svc_ctx axis2_svc_ctx_t;

    /** 
     * Creates a service context struct that corresponds to the given service
     * and with the given parent service group context.
     * @param env pointer to environment struct
     * @param svc pointer to service that this service context represents, 
     * service context does not assume the ownership of service
     * @param svc_grp_ctx pointer to service group context, the parent of the 
     * newly created service context. service context does not assume the 
     * ownership of parent
     * @return pointer to newly created service context
     */
    AXIS2_EXTERN axis2_svc_ctx_t *AXIS2_CALL 
    axis2_svc_ctx_create(const axutil_env_t *env,
        struct axis2_svc *svc,
        struct axis2_svc_grp_ctx *svc_grp_ctx);

    /**
     * Gets base which is of type context.
     * @param svc_ctx pointer to service context
     * @param env pointer to environment struct
     * @return pointer to context, returns a reference, not a cloned copy
     */
    AXIS2_EXTERN axis2_ctx_t *AXIS2_CALL
    axis2_svc_ctx_get_base(const axis2_svc_ctx_t *svc_ctx,
        const axutil_env_t *env);


    /**
     * Gets parent which is of type service group context.
     * @param svc_ctx pointer to service context
     * @param env pointer to environment struct
     * @return pointer to parent service group context
     */
    AXIS2_EXTERN struct axis2_svc_grp_ctx *AXIS2_CALL
    axis2_svc_ctx_get_parent(const axis2_svc_ctx_t *svc_ctx,
        const axutil_env_t *env);
        
    /**
     * Sets parent which is of type service group context.
     * @param svc_ctx pointer to service context
     * @param env pointer to environment struct
     * @param svc_grp_ctx
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_ctx_set_parent(
        axis2_svc_ctx_t *svc_ctx,
        const axutil_env_t *env,
        struct axis2_svc_grp_ctx *parent);


    /**
     * Frees service context instance.
     * @param svc_ctx pointer to service context
     * @param env pointer to environment struct
     * @return void
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_svc_ctx_free(struct axis2_svc_ctx *svc_ctx,
        const axutil_env_t *env);


    /**
     * Initializes service context. This method locates the corresponding 
     * service that is related to the service context from configuration
     * using service qname and keeps a reference to it for future use.
     * @param svc_ctx pointer to service context
     * @param env pointer to environment struct
     * @param conf pointer to configuration
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_ctx_init(struct axis2_svc_ctx *svc_ctx,
        const axutil_env_t *env,
        struct axis2_conf *conf);

    /**
     * Gets the ID of the service that this service context is an instance 
     * of.
     * @param svc_ctx pointer to service context
     * @param env pointer to environment struct
     * @return service ID string.
     */
    AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
    axis2_svc_ctx_get_svc_id(const axis2_svc_ctx_t *svc_ctx,
        const axutil_env_t *env);


    /**
     * Gets the service that this service context represents.
     * @param svc_ctx pointer to service context
     * @param env pointer to environment struct
     * @return pointer to service, returns a reference, not a cloned copy
     */
    AXIS2_EXTERN struct axis2_svc *AXIS2_CALL
    axis2_svc_ctx_get_svc(const axis2_svc_ctx_t *svc_ctx,
        const axutil_env_t *env);

    /**
     * Sets the service that this service context represents.
     * @param svc_ctx pointer to service context
     * @param env pointer to environment struct
     * @param svc pointer to service struct, service context does not assume
     * the ownership of the struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_ctx_set_svc(axis2_svc_ctx_t *svc_ctx,
        const axutil_env_t *env,
        struct axis2_svc *svc);


    /**
     * Gets configuration context which is the super root (super most parent)
     * of the context hierarchy to which this service context belongs.
     * @param svc_ctx pointer to service context
     * @param env pointer to environment struct
     * @return pointer to configuration context
     */
    AXIS2_EXTERN struct axis2_conf_ctx *AXIS2_CALL
    axis2_svc_ctx_get_conf_ctx(const axis2_svc_ctx_t *svc_ctx,
        const axutil_env_t *env);


    /**
     * Creates an operation context for the named operation. The named 
     * operation should be one of the operations in the service related
     * to this service context.
     * @param svc_ctx pointer to service context
     * @param env pointer to environment struct
     * @param qname pointer to qname that represents the operation name.
     * @return pointer to operation context
     */
    AXIS2_EXTERN struct axis2_op_ctx *AXIS2_CALL
    axis2_svc_ctx_create_op_ctx(struct axis2_svc_ctx *svc_ctx,
        const axutil_env_t *env,
        const axutil_qname_t *qname);

#ifdef __cplusplus
}
#endif

#endif                          /* AXIS2_SVC_CTX_H */
