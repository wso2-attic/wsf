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

#include <axis2_msg_recv.h>
#include <axutil_param.h>
#include <axis2_description.h>
#include <axutil_class_loader.h>
#include <axis2_engine.h>
#include <axis2_core_utils.h>
#include <axutil_property.h>
#include <axiom_soap_envelope.h>
#include <axiom_soap_body.h>

struct axis2_msg_recv
{
    axis2_char_t *scope;

    void* derived;
    /**
     * This contain in out synchronous business invoke logic
     * @param msg_recv pointer to message receiver
     * @param env pointer to environment struct
     * @param in_msg_ctx pointer to in message context
     * @param out_msg_ctx pointer to out message context
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    axis2_status_t (AXIS2_CALL *
    invoke_business_logic)(axis2_msg_recv_t *msg_recv,
        const axutil_env_t *env,
        struct axis2_msg_ctx *in_msg_ctx,
        struct axis2_msg_ctx *out_msg_ctx);

    /**
     * This method is called from axis2_engine_receive method. This method's
     * actual implementation is decided from the create method of the 
     * extended message receiver object. There depending on the synchronous or
     * asynchronous type, receive metho is assigned with the synchronous or
     * asynchronous implementation of receive.
     * @see raw_xml_in_out_msg_recv_create method where receive is assigned
     * to receive_sync
     * @param msg_recv pointer to message receiver
     * @param env pointer to environment struct
     * @param in_msg_ctx pointer to in message context
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    axis2_status_t (AXIS2_CALL *
    receive)(axis2_msg_recv_t *msg_recv,
        const axutil_env_t *env,
        struct axis2_msg_ctx *in_msg_ctx,
        void *callback_recv_param);
};

static axis2_status_t AXIS2_CALL
axis2_msg_recv_receive_impl(axis2_msg_recv_t *msg_recv,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    void *callback_recv_param);

AXIS2_EXPORT axis2_msg_recv_t *AXIS2_CALL
axis2_msg_recv_create(const axutil_env_t *env)
{
    axis2_msg_recv_t *msg_recv = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    msg_recv = (axis2_msg_recv_t *) AXIS2_MALLOC(env->allocator,
        sizeof(axis2_msg_recv_t));

    if (!msg_recv)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    msg_recv->scope = axutil_strdup (env, "app*");
    msg_recv->derived = NULL;
    msg_recv->receive = axis2_msg_recv_receive_impl;
    return msg_recv;
}

AXIS2_EXPORT void AXIS2_CALL
axis2_msg_recv_free(axis2_msg_recv_t *msg_recv,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (msg_recv->scope)
    {
        AXIS2_FREE(env->allocator, msg_recv->scope);
    }

    if (msg_recv)
    {
        AXIS2_FREE(env->allocator, msg_recv);
    }

    return;
}

AXIS2_EXPORT axis2_svc_skeleton_t *AXIS2_CALL
axis2_msg_recv_make_new_svc_obj(axis2_msg_recv_t *msg_recv,
    const axutil_env_t *env,
    struct axis2_msg_ctx *msg_ctx)
{
    struct axis2_svc *svc = NULL;
    struct axis2_op_ctx *op_ctx = NULL;
    struct axis2_svc_ctx *svc_ctx = NULL;
    axutil_param_t *impl_info_param = NULL;
    void *impl_class = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, NULL);

    op_ctx = axis2_msg_ctx_get_op_ctx(msg_ctx, env);
    svc_ctx = axis2_op_ctx_get_parent(op_ctx, env);
    svc = axis2_svc_ctx_get_svc(svc_ctx, env);
    if (!svc)
    {
        return NULL;
    }

    impl_class = axis2_svc_get_impl_class(svc, env);
    if (impl_class)
    {
        return impl_class;
    }

    impl_info_param = axis2_svc_get_param(svc, env, AXIS2_SERVICE_CLASS);
    if (!impl_info_param)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_STATE_SVC,
            AXIS2_FAILURE);
        return NULL;
    }

    axutil_allocator_switch_to_global_pool(env->allocator);
    
    axutil_class_loader_init(env);

    impl_class = axutil_class_loader_create_dll(env, impl_info_param);
    axis2_svc_set_impl_class(svc, env, impl_class);

    if (impl_class)
    {
        AXIS2_SVC_SKELETON_INIT((axis2_svc_skeleton_t *)impl_class, env);
    }

    axutil_allocator_switch_to_local_pool(env->allocator);

    return impl_class;
}


AXIS2_EXPORT axis2_svc_skeleton_t *AXIS2_CALL
axis2_msg_recv_get_impl_obj(axis2_msg_recv_t *msg_recv,
    const axutil_env_t *env,
    struct axis2_msg_ctx *msg_ctx)
{
    struct axis2_svc *svc = NULL;
    struct axis2_op_ctx *op_ctx = NULL;
    struct axis2_svc_ctx *svc_ctx = NULL;

    AXIS2_PARAM_CHECK(env->error, msg_ctx, NULL);

    op_ctx = axis2_msg_ctx_get_op_ctx(msg_ctx, env);
    svc_ctx = axis2_op_ctx_get_parent(op_ctx, env);
    svc = axis2_svc_ctx_get_svc(svc_ctx, env);
    if (!svc)
    {
        return NULL;
    }
    
    return axis2_msg_recv_make_new_svc_obj(msg_recv, env, msg_ctx);
}

AXIS2_EXPORT axis2_status_t AXIS2_CALL
axis2_msg_recv_set_scope(axis2_msg_recv_t *msg_recv,
    const axutil_env_t *env,
    const axis2_char_t *scope)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, scope, AXIS2_FAILURE);

    if (msg_recv->scope)
    {
        AXIS2_FREE(env->allocator, msg_recv->scope);
    }
    msg_recv->scope = axutil_strdup(env, scope);
    if (!msg_recv->scope)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXPORT axis2_char_t *AXIS2_CALL
axis2_msg_recv_get_scope(axis2_msg_recv_t *msg_recv,
    const axutil_env_t *env)
{
    return msg_recv->scope;
}

AXIS2_EXPORT axis2_status_t AXIS2_CALL
axis2_msg_recv_delete_svc_obj(axis2_msg_recv_t *msg_recv,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    axis2_svc_t *svc = NULL;
    axis2_op_ctx_t *op_ctx = NULL;
    axis2_svc_ctx_t *svc_ctx = NULL;
    axutil_param_t *impl_info_param = NULL;
    axutil_param_t *scope_param = NULL;
    axis2_char_t *param_value = NULL;
    axutil_dll_desc_t *dll_desc = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);

    op_ctx = axis2_msg_ctx_get_op_ctx(msg_ctx, env);
    svc_ctx = axis2_op_ctx_get_parent(op_ctx, env);
    svc = axis2_svc_ctx_get_svc(svc_ctx, env);
    if (!svc)
    {
        return AXIS2_FAILURE;
    }

    scope_param = axis2_svc_get_param(svc, env, AXIS2_SCOPE);
    if (scope_param)
    {
        param_value = axutil_param_get_value(scope_param, env);
    }
    if (param_value && (0 == axutil_strcmp(AXIS2_APPLICATION_SCOPE,
        param_value)))
    {
        return AXIS2_SUCCESS;
    }

    impl_info_param = axis2_svc_get_param(svc, env, AXIS2_SERVICE_CLASS);
    if (!impl_info_param)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_STATE_SVC,
            AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    dll_desc = axutil_param_get_value(impl_info_param, env);
    return axutil_class_loader_delete_dll(env, dll_desc);
}

static axis2_status_t AXIS2_CALL
axis2_msg_recv_receive_impl(axis2_msg_recv_t *msg_recv,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    void *callback_recv_param)
{
    axis2_msg_ctx_t *out_msg_ctx = NULL;
    axis2_engine_t *engine = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_op_ctx_t *op_ctx = NULL;
    axis2_svc_ctx_t *svc_ctx = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);
        
    out_msg_ctx = axis2_core_utils_create_out_msg_ctx(env, msg_ctx);
    if (!out_msg_ctx)
    {
        return AXIS2_FAILURE;
    }
    op_ctx = axis2_msg_ctx_get_op_ctx(out_msg_ctx, env);
    if (!op_ctx)
    {
        axis2_core_utils_reset_out_msg_ctx(env, out_msg_ctx);
        axis2_msg_ctx_free(out_msg_ctx, env);
        return AXIS2_FAILURE;
    }
    
    status =  axis2_op_ctx_add_msg_ctx(op_ctx, env, out_msg_ctx);
    if (!status)
    {
        axis2_core_utils_reset_out_msg_ctx(env, out_msg_ctx);
        axis2_msg_ctx_free(out_msg_ctx, env);
        return status;
    }
    status =  axis2_op_ctx_add_msg_ctx(op_ctx, env, msg_ctx);

    if(!status)
    {
        return status;
    }

    status = axis2_msg_recv_invoke_business_logic(msg_recv, env,
        msg_ctx, out_msg_ctx);
    if (AXIS2_SUCCESS != status)
    {
        axis2_core_utils_reset_out_msg_ctx(env, out_msg_ctx);
        axis2_msg_ctx_free(out_msg_ctx, env);
        return status;
    }
    svc_ctx = axis2_op_ctx_get_parent(op_ctx, env);
    conf_ctx = axis2_svc_ctx_get_conf_ctx(svc_ctx, env);
    engine = axis2_engine_create(env, conf_ctx);
    if (!engine)
    {
        axis2_msg_ctx_free(out_msg_ctx, env);
        return AXIS2_FAILURE;
    }
    if ( axis2_msg_ctx_get_soap_envelope(out_msg_ctx, env))
    {
        axiom_soap_envelope_t *soap_envelope =  axis2_msg_ctx_get_soap_envelope(
            out_msg_ctx, env);
        if (soap_envelope)
        {
            axiom_soap_body_t *body = axiom_soap_envelope_get_body(soap_envelope,
                env);
            if (body)
            {
                /* in case of a SOAP fault, we got to return failure so that
                   transport gets to know that it should send 500 */
                if (axiom_soap_body_has_fault(body, env))
                {
                    status = AXIS2_FAILURE;
                    axis2_msg_ctx_set_fault_soap_envelope(msg_ctx, env,
                        soap_envelope);
                    axis2_msg_ctx_set_soap_envelope(out_msg_ctx, env, NULL);
                }
                else
                {
                    /* if it is two way and not a fault then send through engine.
                       if it is one way we do not need to do an engine send */
                    status = axis2_engine_send(engine, env, out_msg_ctx);
                }
            }
        }
    }
     axis2_engine_free(engine, env);
    if (!axis2_msg_ctx_is_paused(out_msg_ctx, env) && 
        !axis2_msg_ctx_is_keep_alive(out_msg_ctx, env))
    {
        axis2_core_utils_reset_out_msg_ctx(env, out_msg_ctx);
    }
    return status;
}

AXIS2_EXPORT axis2_status_t AXIS2_CALL
axis2_msg_recv_set_invoke_business_logic(axis2_msg_recv_t *msg_recv,
    const axutil_env_t *env,
    void *func)
{
    msg_recv->invoke_business_logic = func;
    return AXIS2_SUCCESS;
}

AXIS2_EXPORT axis2_status_t AXIS2_CALL 
axis2_msg_recv_invoke_business_logic(axis2_msg_recv_t *msg_recv,
    const axutil_env_t *env,
    struct axis2_msg_ctx *in_msg_ctx,
    struct axis2_msg_ctx *out_msg_ctx)
{
    return msg_recv->invoke_business_logic (msg_recv, env, in_msg_ctx, 
        out_msg_ctx);
}        

AXIS2_EXPORT axis2_status_t AXIS2_CALL
axis2_msg_recv_set_derived(axis2_msg_recv_t *msg_recv,
    const axutil_env_t *env,
    void *derived)
{
    msg_recv->derived = derived;
    return AXIS2_SUCCESS;
}

AXIS2_EXPORT void *AXIS2_CALL
axis2_msg_recv_get_derived(const axis2_msg_recv_t *msg_recv,
    const axutil_env_t *env)
{
    return msg_recv->derived; 
}

AXIS2_EXPORT axis2_status_t AXIS2_CALL
axis2_msg_recv_set_receive(axis2_msg_recv_t *msg_recv,
    const axutil_env_t *env,
    void *func)
{
    msg_recv->receive = func;
    return AXIS2_SUCCESS;
}

AXIS2_EXPORT axis2_status_t AXIS2_CALL
axis2_msg_recv_receive(axis2_msg_recv_t *msg_recv,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    void *callback_recv_param)
{
    return msg_recv->receive(msg_recv, env, msg_ctx,
        callback_recv_param);
}

