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

#include <axis2_op.h>
#include <axutil_property.h>
#include <axis2_msg.h>
#include <axis2_desc.h>
#include <axis2_conf_ctx.h>
#include <axis2_module.h>

struct axis2_op
{
    axis2_svc_t *parent;
    axis2_desc_t *base;
    axis2_msg_recv_t *msg_recv;

    int mep;
    /* to store deploy time modules */
    axutil_array_list_t *module_qnames;
    axutil_array_list_t *engaged_module_list;
    axutil_array_list_t *wsamapping_list;
    axis2_bool_t from_module;
    axutil_qname_t *qname;
    axis2_char_t *msg_exchange_pattern;
    axis2_char_t *style;
    /** parameter container to hold operation related parameters  */
    struct axutil_param_container *param_container;
};

AXIS2_EXTERN axis2_op_t *AXIS2_CALL
axis2_op_create(const axutil_env_t *env)
{
    axis2_op_t *op = NULL;
    axis2_msg_t *msg = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    op = (axis2_op_t *) AXIS2_MALLOC(env->allocator,
        sizeof(axis2_op_t));

    if (!op)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    op->parent = NULL;
    op->base = NULL;
    op->msg_recv = NULL;
    op->mep = AXIS2_MEP_CONSTANT_INVALID;
    op->param_container = NULL;
    op->module_qnames = NULL;
    op->engaged_module_list = NULL;
    op->from_module = AXIS2_FALSE;
    op->wsamapping_list = NULL;
    op->qname = NULL;
    op->msg_exchange_pattern = NULL;
    op->style = NULL;
    op->style = axutil_strdup(env, AXIS2_STYLE_DOC);

    op->param_container = (axutil_param_container_t *)
            axutil_param_container_create(env);
    if (!op->param_container)
    {
        axis2_op_free(op, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    op->base = axis2_desc_create(env);
    if (!op->base)
    {
        axis2_op_free(op, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    /* Create and set up children messages */
    msg = axis2_msg_create(env);
    if (!msg)
    {
        axis2_op_free(op, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    axis2_msg_set_direction(msg, env, AXIS2_WSDL_MESSAGE_DIRECTION_IN);
    axis2_msg_set_parent(msg, env, op);
    axis2_op_add_msg(op, env, AXIS2_MSG_IN, msg);

    msg = axis2_msg_create(env);
    if (!msg)
    {
        axis2_op_free(op, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    axis2_msg_set_direction(msg, env, AXIS2_WSDL_MESSAGE_DIRECTION_OUT);
    axis2_msg_set_parent(msg, env, op);
    axis2_op_add_msg(op, env, AXIS2_MSG_OUT, msg);

    msg = axis2_msg_create(env);
    if (!msg)
    {
        axis2_op_free(op, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    axis2_msg_set_parent(msg, env, op);
    axis2_msg_set_flow(msg, env, NULL);
    axis2_op_add_msg(op, env, AXIS2_MSG_IN_FAULT, msg);

    msg = axis2_msg_create(env);
    if (!msg)
    {
        axis2_op_free(op, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    axis2_msg_set_parent(msg, env, op);
    axis2_msg_set_flow(msg, env, NULL);
    axis2_op_add_msg(op, env, AXIS2_MSG_OUT_FAULT, msg);

    axis2_op_set_msg_exchange_pattern(op, env,
        (axis2_char_t *) AXIS2_MEP_URI_IN_OUT);

    return op;
}

AXIS2_EXTERN axis2_op_t *AXIS2_CALL
axis2_op_create_from_module(const axutil_env_t *env)
{
    axis2_op_t *op = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    op = (axis2_op_t *) axis2_op_create(env);
    op->from_module = AXIS2_TRUE;
    return op;
}


AXIS2_EXTERN axis2_op_t *AXIS2_CALL
axis2_op_create_with_qname(
    const axutil_env_t *env,
    const axutil_qname_t *qname)
{
    axis2_op_t *op = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, qname, AXIS2_FAILURE);

    op = (axis2_op_t *) axis2_op_create(env);


    if (!op)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    status = axis2_op_set_qname(op, env, qname);
    if (AXIS2_SUCCESS != status)
    {
        axis2_op_free(op, env);
        return NULL;
    }

    return op;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_op_free(
    axis2_op_t *op,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (op->base)
    {
        axis2_desc_free(op->base, env);
    }
    if (op->param_container)
    {
        axutil_param_container_free(op->param_container, env);
    }

    op->parent = NULL;

    if (op->msg_recv)
    {
        axis2_msg_recv_free(op->msg_recv, env);
    }
    if (op->module_qnames)
    {
        int i = 0;
        for (i = 0; i < axutil_array_list_size(op->module_qnames, env); i++)
        {
            axutil_qname_t *module_ref = NULL;
            module_ref = axutil_array_list_get(op->module_qnames, env, i);

            if (module_ref)
            {
                axutil_qname_free(module_ref, env);
            }
        }
        axutil_array_list_free(op->module_qnames, env);
    }
    if (op->engaged_module_list)
    {
        axutil_array_list_free(op->engaged_module_list, env);
    }
    if (op->wsamapping_list)
    {
        axutil_array_list_free(op->wsamapping_list, env);
    }

    if (op->qname)
    {
        axutil_qname_free(op->qname, env);
    }
    
    if (op->msg_exchange_pattern)
    {
        AXIS2_FREE(env->allocator, op->msg_exchange_pattern);
    }

    if (op->style)
    {
        AXIS2_FREE(env->allocator, op->style);
    }
    
    if (op)
    {
        AXIS2_FREE(env->allocator, op);
    }

    return;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_op_free_void_arg(void *op,
    const axutil_env_t *env)
{
    axis2_op_t *op_l = NULL;

    AXIS2_ENV_CHECK(env, void);

    op_l = (axis2_op_t *) op;
    axis2_op_free(op_l, env);
    return;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_add_param(axis2_op_t *op,
    const axutil_env_t *env,
    axutil_param_t *param)
{
    axis2_char_t *param_name = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, param, AXIS2_FALSE);

    param_name = axutil_param_get_name(param, env);
    if (AXIS2_TRUE == axis2_op_is_param_locked(op, env, param_name))
    {
        AXIS2_ERROR_SET(env->error,
            AXIS2_ERROR_PARAMETER_LOCKED_CANNOT_OVERRIDE, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    else
    {
        status = axutil_param_container_add_param(op->param_container, env,
            param);
    }

    return status;
}

AXIS2_EXTERN axutil_param_t *AXIS2_CALL
axis2_op_get_param(const axis2_op_t *op,
    const axutil_env_t *env,
    const axis2_char_t *param_name)
{
    axutil_param_t *param = NULL;

    AXIS2_PARAM_CHECK(env->error, param_name, NULL);

    param = axutil_param_container_get_param(op->param_container, env, param_name);
    if (!param && op->parent)
    {
        param = axis2_svc_get_param(op->parent, env, param_name);
    }
    return param;
}

AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
axis2_op_get_all_params(const axis2_op_t *op,
    const axutil_env_t *env)
{
    return axutil_param_container_get_params(op->param_container, env);
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axis2_op_is_param_locked(axis2_op_t *op,
    const axutil_env_t *env,
    const axis2_char_t *param_name)
{
    axis2_svc_t *parent = NULL;
    axutil_param_t *param = NULL;
    axis2_bool_t locked = AXIS2_FALSE;

    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, param_name, AXIS2_FALSE);

    /* Checking the locked value of parent */
    parent = axis2_op_get_parent(op, env);
    if (parent)
    {
        locked = axis2_svc_is_param_locked(parent, env, param_name);
    }
    if (AXIS2_TRUE == locked)
    {
        return AXIS2_TRUE;
    }
    param = axis2_op_get_param(op, env, param_name);
    return (param  && AXIS2_TRUE == axutil_param_is_locked(param, env));
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_set_parent(axis2_op_t *op,
    const axutil_env_t *env,
    axis2_svc_t *svc)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, svc, AXIS2_FAILURE);

    if (op->parent)
    {
        op->parent = NULL;
    }
    op->parent = svc;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_svc_t *AXIS2_CALL
axis2_op_get_parent(const axis2_op_t *op,
    const axutil_env_t *env)
{
    return op->parent;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_set_msg_recv(axis2_op_t *op,
    const axutil_env_t *env,
    struct axis2_msg_recv *msg_recv)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_recv, AXIS2_FAILURE);

    if (op->msg_recv)
    {
        axis2_msg_recv_free(op->msg_recv, env);
        op->msg_recv = NULL;
    }

    op->msg_recv = msg_recv;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN struct axis2_msg_recv *AXIS2_CALL
axis2_op_get_msg_recv(const axis2_op_t *op,
    const axutil_env_t *env)
{
    return op->msg_recv;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_set_qname(axis2_op_t *op,
    const axutil_env_t *env,
    const axutil_qname_t *qname)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (op->qname)
    {
        axutil_qname_free(op->qname, env);
        op->qname = NULL;
    }
		
	 if (qname)
	 {
        op->qname = axutil_qname_clone((axutil_qname_t *)qname, env);
    }
    
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN const axutil_qname_t *AXIS2_CALL
axis2_op_get_qname(void *op,
    const axutil_env_t *env)
{
    return ((axis2_op_t *)op)->qname;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_set_msg_exchange_pattern(axis2_op_t *op,
    const axutil_env_t *env,
    const axis2_char_t *pattern)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, pattern, AXIS2_FAILURE);

    if (op->msg_exchange_pattern)
    {
        AXIS2_FREE(env->allocator, op->msg_exchange_pattern);
        op->msg_exchange_pattern = NULL;
    }

    op->msg_exchange_pattern = axutil_strdup(env, pattern);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
axis2_op_get_msg_exchange_pattern(const axis2_op_t *op,
    const axutil_env_t *env)
{
    return op->msg_exchange_pattern;
}

AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
axis2_op_get_style(const axis2_op_t *op,
    const axutil_env_t *env)
{
    return op->style;
}

AXIS2_EXTERN axis2_status_t  AXIS2_CALL
axis2_op_set_style(axis2_op_t *op,
    const axutil_env_t *env,
    const axis2_char_t *style)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, style, AXIS2_FAILURE);

    if (op->style)
    {
        AXIS2_FREE(env->allocator, op->style);
        op->style = NULL;
    }

    op->style = axutil_strdup(env, style);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_engage_module(axis2_op_t *op,
    const axutil_env_t *env,
    axis2_module_desc_t *moduleref,
    axis2_conf_t *conf)
{
    int index = 0;
    int size = 0;
    axutil_array_list_t *collection_module = NULL;
    axis2_module_desc_t *module_desc = NULL;
    axis2_phase_resolver_t *pr = NULL;
    axis2_bool_t need_to_add = AXIS2_FALSE;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, moduleref, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, conf, AXIS2_FAILURE);

    collection_module = op->engaged_module_list;
    if (collection_module)
    {
        size = axutil_array_list_size(collection_module, env);
    }
    if (AXIS2_SUCCESS != AXIS2_ERROR_GET_STATUS_CODE(env->error))
    {
        return AXIS2_ERROR_GET_STATUS_CODE(env->error);
    }

    for (index = 0; index < size; index++)
    {
        const axutil_qname_t *qname1 = NULL;
        const axutil_qname_t *qname2 = NULL;

        module_desc = (axis2_module_desc_t *) axutil_array_list_get(collection_module,
            env, index);
        if (!module_desc)
        {
            return AXIS2_FAILURE;
        }
        qname1 = axis2_module_desc_get_qname(module_desc, env);
        qname2 = axis2_module_desc_get_qname(moduleref, env);
        if (axutil_qname_equals(qname1, env, qname2))
        {
            AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
                "Module already engaged to operation");
            need_to_add = AXIS2_FALSE;
            return AXIS2_FAILURE;
        }

    }
    pr = axis2_phase_resolver_create_with_config(env, conf);
    if (pr)
    {
        axis2_module_t *module = NULL;
        axis2_status_t status = AXIS2_FAILURE;

        status = axis2_phase_resolver_engage_module_to_op(pr, env,
            op, moduleref);
        if (AXIS2_SUCCESS != status)
        {
            /* ignore the status */
            AXIS2_ERROR_SET_STATUS_CODE(env->error, AXIS2_SUCCESS);
        }
        module = axis2_module_desc_get_module(moduleref, env);
        
        if (AXIS2_TRUE == need_to_add)
        {
            axutil_array_list_add(collection_module, env, moduleref);
        }
    }
    else
    {
        return AXIS2_FAILURE;
    }
    axis2_phase_resolver_free(pr, env);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_add_to_engaged_module_list(axis2_op_t *op,
    const axutil_env_t *env,
    axis2_module_desc_t *module_desc)
{
    axis2_module_desc_t *module_desc_l = NULL;
    int size = 0;
    int index = 0;
    const axutil_qname_t *module_qname = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, module_desc, AXIS2_FAILURE);

    if (!op->engaged_module_list)
    {
        op->engaged_module_list = axutil_array_list_create(env, 0);
    }
    size = axutil_array_list_size(op->engaged_module_list, env);

    if (AXIS2_SUCCESS != AXIS2_ERROR_GET_STATUS_CODE(env->error))
    {
        return AXIS2_ERROR_GET_STATUS_CODE(env->error);
    }
    module_qname = axis2_module_desc_get_qname(module_desc, env);
    for (index = 0; index < size; index++)
    {
        const axutil_qname_t *module_qname_l = NULL;

        module_desc_l = 
            (axis2_module_desc_t *) axutil_array_list_get(op->engaged_module_list, env, index);
        module_qname_l = axis2_module_desc_get_qname(module_desc_l, env);
        
        if (axutil_qname_equals(module_qname, env, module_qname_l))
        {
            return AXIS2_SUCCESS;
        }

    }

    return axutil_array_list_add(op->engaged_module_list, env, module_desc);
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_remove_from_engaged_module_list(axis2_op_t *op,
    const axutil_env_t *env,
    axis2_module_desc_t *module_desc)
{
    axis2_module_desc_t *module_desc_l = NULL;
    int size = 0;
    int index = 0;
    const axutil_qname_t *module_qname = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, module_desc, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, op->engaged_module_list, AXIS2_FAILURE);

    size = axutil_array_list_size(op->engaged_module_list, env);

    module_qname = axis2_module_desc_get_qname(module_desc, env);
    for (index = 0; index < size; index++)
    {
        const axutil_qname_t *module_qname_l = NULL;

        module_desc_l = 
            (axis2_module_desc_t *) axutil_array_list_get(op->engaged_module_list, env, index);
        module_qname_l = axis2_module_desc_get_qname(module_desc_l, env);        

        if (axutil_qname_equals(module_qname, env, module_qname_l))
        {
            axutil_array_list_remove(op->engaged_module_list, env, index);
            return AXIS2_SUCCESS;
        }

    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
axis2_op_get_all_modules(const axis2_op_t *op,
    const axutil_env_t *env)
{
    return op->engaged_module_list;
}

AXIS2_EXTERN int AXIS2_CALL
axis2_op_get_axis_specific_mep_const(axis2_op_t *op,
    const axutil_env_t *env)
{
    int temp = 0;

    if (op->mep != AXIS2_MEP_CONSTANT_INVALID)
    {
        return op->mep;
    }

    temp = AXIS2_MEP_CONSTANT_INVALID;

    if (axutil_strcmp(AXIS2_MEP_URI_IN_OUT,
        axis2_op_get_msg_exchange_pattern(op, env)) == 0)
    {
        temp = AXIS2_MEP_CONSTANT_IN_OUT;
    }
    else if (axutil_strcmp(AXIS2_MEP_URI_IN_ONLY,
        axis2_op_get_msg_exchange_pattern(op, env)) == 0)
    {
        temp = AXIS2_MEP_CONSTANT_IN_ONLY;
    }
    else if (axutil_strcmp(AXIS2_MEP_URI_IN_OPTIONAL_OUT,
        axis2_op_get_msg_exchange_pattern(op, env)) == 0)
    {
        temp = AXIS2_MEP_CONSTANT_IN_OPTIONAL_OUT;
    }
    else if (axutil_strcmp(AXIS2_MEP_URI_OUT_IN,
        axis2_op_get_msg_exchange_pattern(op, env)) == 0)
    {
        temp = AXIS2_MEP_CONSTANT_OUT_IN;
    }
    else if (axutil_strcmp(AXIS2_MEP_URI_OUT_ONLY,
        axis2_op_get_msg_exchange_pattern(op, env)) == 0)
    {
        temp = AXIS2_MEP_CONSTANT_OUT_ONLY;
    }
    else if (axutil_strcmp(AXIS2_MEP_URI_OUT_OPTIONAL_IN,
        axis2_op_get_msg_exchange_pattern(op, env)) == 0)
    {
        temp = AXIS2_MEP_CONSTANT_OUT_OPTIONAL_IN;
    }
    else if (axutil_strcmp(AXIS2_MEP_URI_ROBUST_IN_ONLY,
        axis2_op_get_msg_exchange_pattern(op, env)) == 0)
    {
        temp = AXIS2_MEP_CONSTANT_ROBUST_IN_ONLY;
    }
    else if (axutil_strcmp(AXIS2_MEP_URI_ROBUST_OUT_ONLY,
        axis2_op_get_msg_exchange_pattern(op, env)) == 0)
    {
        temp = AXIS2_MEP_CONSTANT_ROBUST_OUT_ONLY;
    }

    if (temp == AXIS2_MEP_CONSTANT_INVALID)
    {
        AXIS2_ERROR_SET(env->error,
            AXIS2_ERROR_COULD_NOT_MAP_MEP_URI_TO_MEP_CONSTANT, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    op->mep = temp;
    return op->mep;

}

AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
axis2_op_get_fault_in_flow(const axis2_op_t *op,
    const axutil_env_t *env)
{
    if (op->base)
    {
        axis2_msg_t *msg = NULL;
        msg = axis2_desc_get_child(op->base, env, AXIS2_MSG_IN_FAULT);
        if (msg)
        {
            return axis2_msg_get_flow(msg, env);
        }
    }
    return NULL;
}


AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
axis2_op_get_fault_out_flow(const axis2_op_t *op,
    const axutil_env_t *env)
{
    if (op->base)
    {
        axis2_msg_t *msg = NULL;
        msg = axis2_desc_get_child(op->base, env, AXIS2_MSG_OUT_FAULT);
        if (msg)
        {
            return axis2_msg_get_flow(msg, env);
        }
    }
    return NULL;
}


AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
axis2_op_get_out_flow(const axis2_op_t *op,
    const axutil_env_t *env)
{
    if (op->base)
    {
        axis2_msg_t *msg = NULL;
        msg = axis2_desc_get_child(op->base, env, AXIS2_MSG_OUT);
        if (msg)
        {
            return axis2_msg_get_flow(msg, env);
        }
    }
    return NULL;
}


AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
axis2_op_get_in_flow(const axis2_op_t *op,
    const axutil_env_t *env)
{
    if (op->base)
    {
        axis2_msg_t *msg = NULL;
        msg = axis2_desc_get_child(op->base, env, AXIS2_MSG_IN);
        if (msg)
        {
            return axis2_msg_get_flow(msg, env);
        }
    }
    return NULL;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_set_fault_in_flow(axis2_op_t *op,
    const axutil_env_t *env,
    axutil_array_list_t *list)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, list, AXIS2_FAILURE);

    if (op->base)
    {
        axis2_msg_t *msg = NULL;
        msg = axis2_desc_get_child(op->base, env, AXIS2_MSG_IN_FAULT);
        if (msg)
        {
            return axis2_msg_set_flow(msg, env, list);
        }
    }
    return AXIS2_FAILURE;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_set_fault_out_flow(axis2_op_t *op,
    const axutil_env_t *env,
    axutil_array_list_t *list)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, list, AXIS2_FAILURE);
    if (op->base)
    {
        axis2_msg_t *msg = NULL;
        msg = axis2_desc_get_child(op->base, env, AXIS2_MSG_OUT_FAULT);
        if (msg)
        {
            return axis2_msg_set_flow(msg, env, list);
        }
    }
    return AXIS2_FAILURE;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_set_out_flow(axis2_op_t *op,
    const axutil_env_t *env,
    axutil_array_list_t *list)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, list, AXIS2_FAILURE);

    if (op->base)
    {
        axis2_msg_t *msg = NULL;
        msg = axis2_desc_get_child(op->base, env, AXIS2_MSG_OUT);
        if (msg)
        {
            return axis2_msg_set_flow(msg, env, list);
        }
    }

    return AXIS2_FAILURE;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_set_in_flow(axis2_op_t *op,
    const axutil_env_t *env,
    axutil_array_list_t *list)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, list, AXIS2_FAILURE);

    if (op->base)
    {
        axis2_msg_t *msg = NULL;
        msg = axis2_desc_get_child(op->base, env, AXIS2_MSG_IN);
        if (msg)
        {
            return axis2_msg_set_flow(msg, env, list);
        }
    }
    return AXIS2_FAILURE;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_add_module_qname(axis2_op_t *op,
    const axutil_env_t *env,
    const axutil_qname_t *module_qname)
{
    axutil_qname_t *module_qname_l = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, module_qname, AXIS2_FAILURE);
    module_qname_l = axutil_qname_clone((axutil_qname_t *)module_qname, env);

    return axutil_array_list_add(op->module_qnames, env, module_qname_l);
}

AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
axis2_op_get_all_module_qnames(const axis2_op_t *op,
    const axutil_env_t *env)
{
    return op->module_qnames;
}

AXIS2_EXTERN axis2_op_ctx_t *AXIS2_CALL
axis2_op_find_op_ctx(axis2_op_t *op,
    const axutil_env_t *env,
    struct axis2_msg_ctx *msg_ctx,
    struct axis2_svc_ctx *svc_ctx)
{
    axis2_op_ctx_t *op_ctx = NULL;
    axis2_relates_to_t *relates_to = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, NULL);
    AXIS2_PARAM_CHECK(env->error, svc_ctx, NULL);

    relates_to =  axis2_msg_ctx_get_relates_to(msg_ctx, env);
    if (!relates_to)
    {
        op_ctx = axis2_op_ctx_create(env, op, svc_ctx);
        if (!op_ctx)
        {
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            return NULL;
        }
    }
    else
    {
        axis2_conf_ctx_t *conf_ctx = NULL;
        const axis2_char_t *value = NULL;

        conf_ctx =  axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
        value = axis2_relates_to_get_value(relates_to, env);
        op_ctx =  axis2_conf_ctx_get_op_ctx(conf_ctx, env, value);
        if (!op_ctx)
        {
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_CANNOT_CORRELATE_MSG,
                AXIS2_FAILURE);
            return NULL;
        }
    }

    status = axis2_op_register_op_ctx(op, env, msg_ctx, op_ctx);
    if (AXIS2_FAILURE == status)
    {
         axis2_op_ctx_free(op_ctx, env);
        return NULL;
    }
    else
    {
        return op_ctx;
    }    
}

AXIS2_EXTERN axis2_op_ctx_t *AXIS2_CALL
axis2_op_find_existing_op_ctx(axis2_op_t *op,
    const axutil_env_t *env,
    const axis2_msg_ctx_t *msg_ctx)
{
    axis2_op_ctx_t *op_ctx = NULL;
    axis2_relates_to_t *relates_to = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, NULL);

    op_ctx =  axis2_msg_ctx_get_op_ctx(msg_ctx, env);
    if (op_ctx)
    {
        return op_ctx;
    }

    relates_to =  axis2_msg_ctx_get_relates_to(msg_ctx, env);
    if (!relates_to)
    {
        return NULL;
    }
    else
    {
        axis2_conf_ctx_t *conf_ctx = NULL;
        axis2_char_t *value = NULL;
        conf_ctx =  axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
        op_ctx =  axis2_conf_ctx_get_op_ctx(conf_ctx, env, value);

        if (!op_ctx)
        {
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_CANNOT_CORRELATE_MSG,
                AXIS2_FAILURE);
            return NULL;
        }
    }

    return op_ctx;

}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_register_op_ctx(axis2_op_t *op,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    axis2_op_ctx_t *op_ctx)
{
    axis2_conf_ctx_t *conf_ctx = NULL;
    const axis2_char_t *msg_id = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, op_ctx, AXIS2_FAILURE);

    conf_ctx =  axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
    if (!conf_ctx)
    {
        return AXIS2_FAILURE;
    }
    msg_id =  axis2_msg_ctx_get_msg_id(msg_ctx, env);
    if (!msg_id)
    {
        return AXIS2_FAILURE;
    }
    /*status =  axis2_conf_ctx_register_op_ctx(conf_ctx, env, msg_id, op_ctx);
    if (AXIS2_FAILURE == status)
    {
        return AXIS2_FAILURE;
    }*/
    status =  axis2_msg_ctx_set_op_ctx(msg_ctx, env, op_ctx);
    if (AXIS2_FAILURE == status)
    {
        axutil_hash_t *op_ctx_map = NULL;
        op_ctx_map = (axutil_hash_t *)  axis2_conf_ctx_get_op_ctx_map(conf_ctx, env);
        axutil_hash_set(op_ctx_map, msg_id, AXIS2_HASH_KEY_STRING, NULL);
    }
    if (AXIS2_TRUE ==  axis2_op_ctx_get_is_complete(op_ctx, env))
    {
         axis2_op_ctx_cleanup(op_ctx, env);
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_add_msg_ctx_in_only(axis2_op_t *op,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    axis2_op_ctx_t *op_ctx)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, op_ctx, AXIS2_FAILURE);
    
    if (AXIS2_TRUE !=  axis2_op_ctx_get_is_complete(op_ctx, env))
    {
        axis2_msg_ctx_t **msg_ctxs = NULL;
        msg_ctxs =  axis2_op_ctx_get_msg_ctx_map(op_ctx, env);
        msg_ctxs[AXIS2_WSDL_MESSAGE_LABEL_IN] = msg_ctx;
         axis2_op_ctx_set_complete(op_ctx, env, AXIS2_TRUE);
    }
    else
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_MESSAGE_ADDITION,
            AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_add_msg_ctx_out_only(axis2_op_t *op,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    axis2_op_ctx_t *op_ctx)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, op_ctx, AXIS2_FAILURE);

    if (AXIS2_TRUE !=  axis2_op_ctx_get_is_complete(op_ctx, env))
    {
        axis2_msg_ctx_t **msg_ctxs = NULL;
        msg_ctxs =  axis2_op_ctx_get_msg_ctx_map(op_ctx, env);
        msg_ctxs[AXIS2_WSDL_MESSAGE_LABEL_OUT] =  msg_ctx;
         axis2_op_ctx_set_complete(op_ctx, env, AXIS2_TRUE);
    }
    else
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_MESSAGE_ADDITION,
            AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_add_msg_ctx_in_out(axis2_op_t *op,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    axis2_op_ctx_t *op_ctx)
{
    axis2_msg_ctx_t **mep = NULL;
    axis2_msg_ctx_t *in_msg_ctx = NULL;
    axis2_msg_ctx_t *out_msg_ctx = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, op_ctx, AXIS2_FAILURE);

    mep =  axis2_op_ctx_get_msg_ctx_map(op_ctx, env);
    in_msg_ctx = mep[AXIS2_WSDL_MESSAGE_LABEL_IN];
    out_msg_ctx = mep[AXIS2_WSDL_MESSAGE_LABEL_OUT];
    
    if (in_msg_ctx && NULL != out_msg_ctx)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_MESSAGE_ADDITION,
            AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    if (!in_msg_ctx)
    {
        mep[AXIS2_WSDL_MESSAGE_LABEL_IN] = msg_ctx;
    }
    else
    {
        mep[AXIS2_WSDL_MESSAGE_LABEL_OUT] = msg_ctx;
         axis2_op_ctx_set_complete(op_ctx, env, AXIS2_TRUE);
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_add_msg_ctx_out_in(axis2_op_t *op,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    axis2_op_ctx_t *op_ctx)
{
    axis2_msg_ctx_t **mep = NULL;
    axis2_msg_ctx_t *in_msg_ctx = NULL;
    axis2_msg_ctx_t *out_msg_ctx = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, op_ctx, AXIS2_FAILURE);

    mep =  axis2_op_ctx_get_msg_ctx_map(op_ctx, env);
    in_msg_ctx = mep[AXIS2_WSDL_MESSAGE_LABEL_IN];
    out_msg_ctx = mep[AXIS2_WSDL_MESSAGE_LABEL_OUT];
    if (in_msg_ctx && NULL != out_msg_ctx)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_MESSAGE_ADDITION,
            AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    if (!out_msg_ctx)
    {
        mep[AXIS2_WSDL_MESSAGE_LABEL_OUT] = msg_ctx;
    }
    else
    {
        mep[AXIS2_WSDL_MESSAGE_LABEL_IN] = msg_ctx;
         axis2_op_ctx_set_complete(op_ctx, env, AXIS2_TRUE);
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_msg_t *AXIS2_CALL
axis2_op_get_msg(const axis2_op_t *op,
    const axutil_env_t *env,
    const axis2_char_t *label)
{
    AXIS2_PARAM_CHECK(env->error, label, NULL);

    return (axis2_msg_t *)axis2_desc_get_child(op->base, env, label);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_add_msg(axis2_op_t *op,
    const axutil_env_t *env,
    const axis2_char_t *label,
    const axis2_msg_t *msg)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, label, AXIS2_FAILURE);

    return axis2_desc_add_child(op->base, env, label, msg);
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axis2_op_is_from_module(const axis2_op_t *op,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    return op->from_module;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_op_set_wsamapping_list(axis2_op_t *op,
    const axutil_env_t *env,
    axutil_array_list_t *mapping_list)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, mapping_list, AXIS2_FAILURE);
    
    if (op->wsamapping_list)
    {
        axutil_array_list_free(op->wsamapping_list, env);
        op->wsamapping_list = NULL;
    }
    op->wsamapping_list = mapping_list;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
axis2_op_get_wsamapping_list(axis2_op_t *op,
    const axutil_env_t *env)
{
    return op->wsamapping_list;
}

AXIS2_EXTERN axutil_param_container_t *AXIS2_CALL
axis2_op_get_param_container(const axis2_op_t *op,
    const axutil_env_t *env)
{
    return op->param_container;
}

