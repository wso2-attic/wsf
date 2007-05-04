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

#include <axis2_phase_resolver.h>
#include <axutil_property.h>

struct axis2_phase_resolver
{
    /** axis2 configuration */
    axis2_conf_t *axis2_config;

    /** service */
    axis2_svc_t *svc;
};

static axis2_status_t
axis2_phase_resolver_build_execution_chains(
    axis2_phase_resolver_t *phase_resolver,
    const axutil_env_t *env,
    int type,
    axis2_op_t *op);

static axis2_status_t
axis2_phase_resolver_build_in_transport_chains(
    axis2_phase_resolver_t *phase_resolver,
    const axutil_env_t *env,
    axis2_transport_in_desc_t *transport);

static axis2_status_t
axis2_phase_resolver_build_out_transport_chains(
    axis2_phase_resolver_t *phase_resolver,
    const axutil_env_t *env,
    axis2_transport_out_desc_t *transport);

static axis2_status_t
axis2_phase_resolver_engage_to_global_chain(
    axis2_phase_resolver_t *phase_resolver,
    const axutil_env_t *env,
    axis2_module_desc_t *module_desc);

AXIS2_EXTERN axis2_phase_resolver_t *AXIS2_CALL
axis2_phase_resolver_create(
    const axutil_env_t *env)
{
    axis2_phase_resolver_t *phase_resolver = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    phase_resolver = (axis2_phase_resolver_t *) AXIS2_MALLOC(env->allocator,
        sizeof(axis2_phase_resolver_t));

    if (! phase_resolver)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    phase_resolver->axis2_config = NULL;
    phase_resolver->svc = NULL;

    return phase_resolver;
}

AXIS2_EXTERN axis2_phase_resolver_t *AXIS2_CALL
axis2_phase_resolver_create_with_config(
    const axutil_env_t *env,
    axis2_conf_t *axis2_config)
{
    axis2_phase_resolver_t *phase_resolver = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, axis2_config, NULL);

    phase_resolver = (axis2_phase_resolver_t *)
        axis2_phase_resolver_create(env);

    phase_resolver->axis2_config = axis2_config;

    return phase_resolver;
}

AXIS2_EXTERN axis2_phase_resolver_t *AXIS2_CALL
axis2_phase_resolver_create_with_config_and_svc(
    const axutil_env_t *env,
    axis2_conf_t *axis2_config,
    axis2_svc_t *svc)
{
    axis2_phase_resolver_t *phase_resolver = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, axis2_config, NULL);

    phase_resolver = (axis2_phase_resolver_t *)
        axis2_phase_resolver_create(env);

    if (!phase_resolver)
    {
        return NULL;
    }
    phase_resolver->axis2_config = axis2_config;

    phase_resolver->svc = svc;
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "Service name is : %s",
        axis2_svc_get_name(phase_resolver->svc, env));

    return phase_resolver;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_phase_resolver_free(
    axis2_phase_resolver_t *phase_resolver,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (phase_resolver)
    {
        AXIS2_FREE(env->allocator, phase_resolver);
    }

    return;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_phase_resolver_build_chains(
    axis2_phase_resolver_t *phase_resolver,
    const axutil_env_t *env)
{
    axutil_hash_index_t *index_i = 0;
    axis2_status_t status = AXIS2_FAILURE;
    axis2_op_t *op = NULL;
    axutil_hash_t *ops = NULL;

    if (!(phase_resolver->svc))
        return AXIS2_FAILURE;

    ops = axis2_svc_get_all_ops(phase_resolver->svc, env);

    for (index_i = axutil_hash_first(ops, env); index_i; index_i =
        axutil_hash_next(env, index_i))
    {
        void *v = NULL;
        int j = 0;
        axutil_hash_this(index_i, NULL, NULL, &v);
        op = (axis2_op_t *)v;
        for (j = 1; j < 5; j++)
        {
            status = axis2_phase_resolver_build_execution_chains(phase_resolver,
                env, j, op);
        }
    }

    return status;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_phase_resolver_build_module_op(
    axis2_phase_resolver_t *phase_resolver,
    const axutil_env_t *env,
    axis2_op_t *op)
{
    int i = 0;
    axis2_status_t status = AXIS2_FAILURE;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, op, AXIS2_FAILURE);

    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "op name is:%s",
        axutil_qname_get_localpart(axis2_op_get_qname(op, env),
        env));
    for (i = 1; i < 5; i++)
    {
        status = axis2_phase_resolver_build_execution_chains(phase_resolver,
            env, i, op);
        if(!status)
	{
            break;
	}
    }
    return status;
}

static axis2_status_t
axis2_phase_resolver_build_execution_chains(
    axis2_phase_resolver_t *phase_resolver,
    const axutil_env_t *env,
    int type,
    axis2_op_t *op)
{
    axutil_array_list_t *all_handlers = NULL;
    axutil_array_list_t *moduleqnames = NULL;
    int i = 0;
    int size = 0;
    int status = AXIS2_FAILURE;
    axis2_flow_t *flow = NULL;
    axis2_phase_holder_t *phase_holder = NULL;

    /* engage handlers from axis2.xml from modules */

    moduleqnames =  axis2_conf_get_all_engaged_modules(
        phase_resolver->axis2_config, env);

    size = axutil_array_list_size(moduleqnames, env);
    status = AXIS2_ERROR_GET_STATUS_CODE(env->error);
    if (AXIS2_SUCCESS != status)
    {
        return status;
    }

    for (i = 0; i < size; i++)
    {
        axutil_qname_t *modulename = NULL;
        axis2_module_desc_t *module_desc = NULL;

        modulename = (axutil_qname_t *) axutil_array_list_get(moduleqnames, env,
            i);
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "module name is:%s",
            axutil_qname_get_localpart(modulename, env));
        module_desc =  axis2_conf_get_module(phase_resolver->axis2_config, env,
            modulename);
        if (module_desc)
        {
            switch (type)
            {
                case AXIS2_IN_FLOW:
                {
                    flow = axis2_module_desc_get_in_flow(module_desc, env);
                    break;
                }
                case AXIS2_OUT_FLOW:
                {
                    flow = axis2_module_desc_get_out_flow(module_desc, env);
                    break;
                }
                case AXIS2_FAULT_IN_FLOW:
                {
                    flow = axis2_module_desc_get_fault_in_flow(module_desc, env);
                    break;
                }
                case AXIS2_FAULT_OUT_FLOW:
                {
                    flow = axis2_module_desc_get_fault_out_flow(module_desc, env);
                    break;
                }
            }
            status = axis2_op_add_to_engaged_module_list(op, env, module_desc);
            if (AXIS2_SUCCESS != status)
            {
                return status;
            }

        }
        else
        {
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_MODULE_REF,
                AXIS2_FAILURE);
            return AXIS2_FAILURE;
        }

        if (flow)
        {
            int j = 0;
            int count = 0;
            count = axis2_flow_get_handler_count(flow, env);
            if (AXIS2_SUCCESS != AXIS2_ERROR_GET_STATUS_CODE(env->error))
            {
                return AXIS2_ERROR_GET_STATUS_CODE(env->error);
            }


            for (j = 0; j < count; j++)
            {
                axis2_handler_desc_t *metadata = NULL;
                const axis2_char_t *phase_name = NULL;
                axis2_phase_rule_t *phase_rule = NULL;

                metadata = axis2_flow_get_handler(flow, env, j);
                phase_rule = axis2_handler_desc_get_rules(metadata, env);
                phase_name = axis2_phase_rule_get_name(phase_rule, env);
                if (! phase_name)
                {
                    return AXIS2_FAILURE;
                }
                if ((0 != axutil_strcmp(AXIS2_PHASE_TRANSPORT_IN, phase_name)) &&
                    (0 != axutil_strcmp(AXIS2_PHASE_DISPATCH, phase_name)) &&
                    (0 != axutil_strcmp(AXIS2_PHASE_POST_DISPATCH, phase_name)) &&
                    (0 != axutil_strcmp(AXIS2_PHASE_PRE_DISPATCH, phase_name)))
                {
                    if (!all_handlers)
                    {
                        all_handlers = axutil_array_list_create(env, 0);
                        if (!all_handlers)
			{
                            return AXIS2_FAILURE;
			}
                    }
                    status = axutil_array_list_add(all_handlers, env, metadata);
                    if (AXIS2_SUCCESS != status)
                    {
                        if (all_handlers)
                        {
                            axutil_array_list_free(all_handlers, env);
                            all_handlers = NULL;
                        }
                        return status;
                    }
                }
                else
                {
                    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "This handler is\
                        trying to added to system pre defined phases , but those\
                        handlers are already added to global chain which run\
                        irrespective of the service");
                }
            }
        }

    }


    /* process handlers form service.xml */
    flow = NULL;

    if (flow)
    {
        int j = 0;
        int count = 0;
        count = axis2_flow_get_handler_count(flow, env);

        if (AXIS2_SUCCESS != AXIS2_ERROR_GET_STATUS_CODE(env->error))
        {
            if (all_handlers)
            {
                axutil_array_list_free(all_handlers, env);
                all_handlers = NULL;
            }
            return AXIS2_ERROR_GET_STATUS_CODE(env->error);
        }
        for (j = 0; j < count; j++)
        {
            axis2_handler_desc_t *metadata = NULL;
            const axis2_char_t *phase_name = NULL;
            axis2_phase_rule_t *phase_rule = NULL;

            metadata = axis2_flow_get_handler(flow, env, j);
            phase_rule = axis2_handler_desc_get_rules(metadata, env);
            if (phase_rule)
            {
                phase_name = axis2_phase_rule_get_name(phase_rule, env);
            }

            if (!phase_name || (0 == axutil_strcmp(phase_name, "")))
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_PHASE_IS_NOT_SPECIFED,
                    AXIS2_FAILURE);
                return AXIS2_FAILURE;

            }
            else if ((0 == axutil_strcmp(AXIS2_PHASE_TRANSPORT_IN, phase_name)) ||
                (0 == axutil_strcmp(AXIS2_PHASE_DISPATCH, phase_name)) ||
                (0 == axutil_strcmp(AXIS2_PHASE_POST_DISPATCH, phase_name)) ||
                (0 == axutil_strcmp(AXIS2_PHASE_PRE_DISPATCH, phase_name)))
            {
                if (all_handlers)
                {
                    axutil_array_list_free(all_handlers, env);
                    all_handlers = NULL;
                }
                AXIS2_ERROR_SET(env->error,
                    AXIS2_ERROR_SERVICE_MODULE_CAN_NOT_REFER_GLOBAL_PHASE, AXIS2_FAILURE);
                return AXIS2_FAILURE;

            }
            else
            {
                if (!all_handlers)
                {
                    all_handlers = axutil_array_list_create(env, 0);
                    if (!all_handlers)
		    {
                        return AXIS2_FAILURE;
		    }
                }

                status = axutil_array_list_add(all_handlers, env, metadata);

                if (AXIS2_SUCCESS != status)
                {
                    if (all_handlers)
                    {
                        int size = 0;
                        int i = 0;
                        size = axutil_array_list_size(all_handlers, env);
                        for (i = 0; i < size; i++)
                        {
                            axis2_handler_desc_t *handler_desc = NULL;

                            handler_desc = axutil_array_list_get(all_handlers,
                                env, i);
                            axis2_handler_desc_free(handler_desc, env);
                        }
                        axutil_array_list_free(all_handlers, env);
                        all_handlers = NULL;
                    }
                    return status;
                }
            }
        }
    }

    else if (!all_handlers)
    {
        /* no flows configured */
        return AXIS2_SUCCESS;
    }

    switch (type)
    {
        case AXIS2_IN_FLOW:
        {
            axutil_array_list_t *phase_list = NULL;

            phase_list = axis2_op_get_in_flow(op, env);
            phase_holder =
                axis2_phase_holder_create_with_phases(env, phase_list);
            break;
        }
        case AXIS2_OUT_FLOW:
        {
            axutil_array_list_t *phase_list = NULL;

            phase_list = axis2_op_get_out_flow(op, env);
            phase_holder =
                axis2_phase_holder_create_with_phases(env, phase_list);
            break;
        }
        case AXIS2_FAULT_IN_FLOW:
        {
            axutil_array_list_t *phase_list = NULL;

            phase_list = axis2_op_get_fault_in_flow(op, env);
            phase_holder =
                axis2_phase_holder_create_with_phases(env, phase_list);
            break;
        }
        case AXIS2_FAULT_OUT_FLOW:
        {
            axutil_array_list_t *phase_list = NULL;

            phase_list = axis2_op_get_fault_out_flow(op, env);
            phase_holder =
                axis2_phase_holder_create_with_phases(env, phase_list);
            break;
        }
    }

    size = axutil_array_list_size(all_handlers, env);
    if (AXIS2_SUCCESS != AXIS2_ERROR_GET_STATUS_CODE(env->error))
    {
        return AXIS2_ERROR_GET_STATUS_CODE(env->error);
    }

    for (i = 0; i < size; i++)
    {
        axis2_handler_desc_t *metadata = NULL;

        metadata = (axis2_handler_desc_t *)
            axutil_array_list_get(all_handlers, env, i);
        if (phase_holder)
        {
            status = axis2_phase_holder_add_handler(phase_holder,
                env, metadata);
            if(!status)
	    {
                break;
	    }
        }
    }

    /* Free the locally created all_handlers list */
    if (all_handlers)
    {
        axutil_array_list_free(all_handlers, env);
    }
    if(phase_holder)
    {
        axis2_phase_holder_free(phase_holder, env);
    }

    return status;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_phase_resolver_build_transport_chains(
    axis2_phase_resolver_t *phase_resolver,
    const axutil_env_t *env)
{
    axis2_transport_in_desc_t **transports_in = NULL;
    axis2_transport_out_desc_t **transports_out = NULL;
    int index_i = 0;
    axis2_status_t status = AXIS2_FAILURE;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    transports_in =  axis2_conf_get_all_in_transports(phase_resolver->axis2_config,
        env);
    if (!transports_in)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_TRANSPORT_IN_CONFIGURED,
            AXIS2_FAILURE);
        return AXIS2_SUCCESS;
    }

    transports_out =  axis2_conf_get_all_out_transports(phase_resolver->axis2_config,
        env);
    if (!transports_out)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_TRANSPORT_OUT_CONFIGURED,
            AXIS2_FAILURE);
        return AXIS2_SUCCESS;
    }

    for (index_i = 0; index_i < AXIS2_TRANSPORT_ENUM_MAX; index_i++)
    {
        if (transports_in[index_i])
        {
            status = axis2_phase_resolver_build_in_transport_chains(phase_resolver,
                env, transports_in[index_i]);
            if (AXIS2_SUCCESS != status)
            {
                return status;
            }
        }
    }

    for (index_i = 0; index_i < AXIS2_TRANSPORT_ENUM_MAX; index_i++)
    {
        if (transports_out[index_i])
        {
            status = axis2_phase_resolver_build_out_transport_chains(phase_resolver,
                env, transports_out[index_i]);
            if (AXIS2_SUCCESS != status)
            {
                return status;
            }
        }
    }

    /* If transport in or transport out maps are not null but still they don't
     * have chains configured then we return success, because there are no
     * chain to process
     */
    return AXIS2_SUCCESS;
}


static axis2_status_t
axis2_phase_resolver_build_in_transport_chains(
    axis2_phase_resolver_t *phase_resolver,
    const axutil_env_t *env,
    axis2_transport_in_desc_t *transport)
{
    int type = 0;
    int j = 0;
    axis2_status_t status = AXIS2_FAILURE;
    axutil_array_list_t *handlers = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, transport, AXIS2_FAILURE);

    for (type = 1; type < 4; type++)
    {
        axis2_flow_t *flow = NULL;
        axis2_phase_t *phase = NULL;

        switch (type)
        {
            case AXIS2_IN_FLOW:
            {
                flow = axis2_transport_in_desc_get_in_flow(transport, env);
                phase = axis2_transport_in_desc_get_in_phase(transport, env);
                break;
            }
            case AXIS2_FAULT_IN_FLOW:
            {
                flow = axis2_transport_in_desc_get_fault_in_flow(transport, env);
                phase = axis2_transport_in_desc_get_fault_phase(transport, env);
                break;
            }
        }
        if (flow)
        {
            axis2_phase_holder_t *phase_holder = NULL;
            int size = 0;

            size = axis2_flow_get_handler_count(flow, env);
            handlers = axutil_array_list_create(env, 0);
            for (j = 0; j < size; j++)
            {
                axis2_handler_desc_t *metadata = NULL;
                axis2_phase_rule_t *rule = NULL;

                metadata = axis2_flow_get_handler(flow, env, j);
                rule = axis2_handler_desc_get_rules(metadata, env);
                if (rule)
                {
                    status = axis2_phase_rule_set_name(rule, env,
                        AXIS2_TRANSPORT_PHASE);
                }
                if (AXIS2_SUCCESS != status)
                {
                    if (handlers)
                    {
                        axis2_handler_desc_t *handler_d = NULL;
                        int i = 0;
                        int size = 0;

                        size = axutil_array_list_size(handlers, env);
                        for (i = 0; i < size; i++)
                        {
                            handler_d = axutil_array_list_get(handlers, env, i);
                            axis2_handler_desc_free(handler_d, env);
                        }
                        axutil_array_list_free(handlers, env);
                    }
                    return status;
                }
                status = axutil_array_list_add(handlers, env, metadata);
                if (AXIS2_SUCCESS != status)
                {
                    if (handlers)
                    {
                        axis2_handler_desc_t *handler_d = NULL;
                        int i = 0;
                        int size = 0;

                        size = axutil_array_list_size(handlers, env);
                        for (i = 0; i < size; i++)
                        {
                            handler_d = axutil_array_list_get(handlers, env, i);
                            axis2_handler_desc_free(handler_d, env);
                        }
                        axutil_array_list_free(handlers, env);
                    }
                    return status;
                }
            }
            phase_holder = axis2_phase_holder_create(env);
            if (!phase_holder)
            {
                if (handlers)
                {
                    axis2_handler_desc_t *handler_d = NULL;
                    int i = 0;
                    int size = 0;

                    size = axutil_array_list_size(handlers, env);
                    for (i = 0; i < size; i++)
                    {
                        handler_d = axutil_array_list_get(handlers, env, i);
                        axis2_handler_desc_free(handler_d, env);
                    }
                    axutil_array_list_free(handlers, env);
                }
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY,
                    AXIS2_FAILURE);
                return AXIS2_FAILURE;
            }

            status = axis2_phase_holder_build_transport_handler_chain(
                phase_holder, env, phase, handlers);
            if (phase_holder)
            {
                axis2_phase_holder_free(phase_holder, env);
            }
        }
        else
        {
            /* Do nothing */
        }
    }
    if (handlers)
    {
        axutil_array_list_free(handlers, env);
    }
    return status;
}

static axis2_status_t
axis2_phase_resolver_build_out_transport_chains(
    axis2_phase_resolver_t *phase_resolver,
    const axutil_env_t *env,
    axis2_transport_out_desc_t *transport)
{
    int type = 0;
    axis2_status_t status = AXIS2_FAILURE;
    axutil_array_list_t *handlers = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, transport, AXIS2_FAILURE);
    for (type = 1; type < 5; type++)
    {
        axis2_flow_t *flow = NULL;
        axis2_phase_t *phase = NULL;

        switch (type)
        {
            case AXIS2_OUT_FLOW:
            {
                flow = axis2_transport_out_desc_get_out_flow(transport, env);
                phase = axis2_transport_out_desc_get_out_phase(transport, env);
                break;
            }
            case AXIS2_FAULT_OUT_FLOW:
            {
                flow = axis2_transport_out_desc_get_fault_out_flow(transport, env);
                phase = axis2_transport_out_desc_get_fault_phase(transport, env);
                break;
            }
        }

        if (flow)
        {
            axis2_phase_holder_t *phase_holder = NULL;
            int hndlr_count = 0;
            int j = 0;
            hndlr_count = axis2_flow_get_handler_count(flow, env);
            if (AXIS2_SUCCESS != AXIS2_ERROR_GET_STATUS_CODE(env->error))
            {
                return AXIS2_ERROR_GET_STATUS_CODE(env->error);
            }
            handlers = axutil_array_list_create(env, 0);

            for (j = 0; j < hndlr_count; j++)
            {
                axis2_handler_desc_t *metadata = NULL;
                axis2_phase_rule_t *rule = NULL;

                metadata = axis2_flow_get_handler(flow, env, j);


                rule = axis2_handler_desc_get_rules(metadata, env);
                if (rule)
                {
                    status = axis2_phase_rule_set_name(rule, env,
                        AXIS2_TRANSPORT_PHASE);
                }
                if (AXIS2_SUCCESS != status)
                {
                    if (handlers)
                    {
                        axis2_handler_desc_t *handler_d = NULL;
                        int i = 0;
                        int size = 0;

                        size = axutil_array_list_size(handlers, env);
                        for (i = 0; i < size; i++)
                        {
                            handler_d = axutil_array_list_get(handlers, env, i);
                            axis2_handler_desc_free(handler_d, env);
                        }
                        axutil_array_list_free(handlers, env);
                    }
                    return status;
                }

                status = axutil_array_list_add(handlers, env, metadata);
                if (AXIS2_FAILURE == status)
                {
                    if (handlers)
                    {
                        axis2_handler_desc_t *handler_d = NULL;
                        int i = 0;
                        int size = 0;

                        size = axutil_array_list_size(handlers, env);
                        for (i = 0; i < size; i++)
                        {
                            handler_d = axutil_array_list_get(handlers, env, i);
                            axis2_handler_desc_free(handler_d, env);
                        }
                        axutil_array_list_free(handlers, env);
                    }
                    return status;
                }
            }
            phase_holder = axis2_phase_holder_create(env);
            if (!phase_holder)
            {
                if (handlers)
                {
                    axis2_handler_desc_t *handler_d = NULL;
                    int i = 0;
                    int size = 0;

                    size = axutil_array_list_size(handlers, env);
                    for (i = 0; i < size; i++)
                    {
                        handler_d = axutil_array_list_get(handlers, env, i);
                        axis2_handler_desc_free(handler_d, env);
                    }
                    axutil_array_list_free(handlers, env);
                }
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return AXIS2_FAILURE;
            }

            status = axis2_phase_holder_build_transport_handler_chain(
                phase_holder, env, phase, handlers);
            if (phase_holder)
	    {
                axis2_phase_holder_free(phase_holder, env);
	    }
        }
        else
        {
            /* Do nothing */
        }
    }
    if (handlers)
    {
        axutil_array_list_free(handlers, env);
    }
    return status;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_phase_resolver_engage_module_globally(
    axis2_phase_resolver_t *phase_resolver,
    const axutil_env_t *env,
    axis2_module_desc_t *module_desc)
{
    axutil_hash_t *svc_grps = NULL;
    axutil_hash_index_t *index_i = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, module_desc, AXIS2_FAILURE);

    status = axis2_phase_resolver_engage_to_global_chain(phase_resolver, env,
        module_desc);
    if (AXIS2_SUCCESS != status)
    {
        return status;
    }
    svc_grps =  axis2_conf_get_all_svc_grps(phase_resolver->axis2_config, env);
    if (!svc_grps)
    {
        return AXIS2_FAILURE;
    }
    for (index_i = axutil_hash_first(svc_grps, env); index_i; index_i =
        axutil_hash_next(env, index_i))
    {
        axutil_hash_t *svcs = NULL;
        axis2_svc_grp_t *svc_grp = NULL;
        void *v = NULL;
        axutil_hash_index_t *index_j = NULL;
        const axutil_qname_t *mod_name = NULL;

        axutil_hash_this(index_i, NULL, NULL, &v);
        svc_grp = (axis2_svc_grp_t *) v;
        svcs =  axis2_svc_grp_get_all_svcs(svc_grp, env);

        for (index_j = axutil_hash_first(svcs, env); index_j; index_j =
            axutil_hash_next(env, index_j))
        {
            axis2_svc_t *svc = NULL;
            void *w = NULL;

            axutil_hash_this(index_j, NULL, NULL, &w);
            svc = (axis2_svc_t *) w;
            AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "svc name is:%s",
                axis2_svc_get_name(svc, env));

            status = axis2_svc_add_module_ops(svc, env, module_desc,
                phase_resolver->axis2_config);
            if (AXIS2_SUCCESS != status)
            {
                return status;
            }
            status = axis2_phase_resolver_engage_module_to_svc_from_global(
                phase_resolver, env, svc, module_desc);

            if (AXIS2_SUCCESS != status)
            {
                return status;
            }

        }
        mod_name = axis2_module_desc_get_qname(module_desc, env);
        status =  axis2_svc_grp_add_module_qname(svc_grp, env,
            mod_name);

        if (AXIS2_SUCCESS != status)
        {
            return status;
        }
    }
    return status;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_phase_resolver_engage_module_to_svc_from_global(
    axis2_phase_resolver_t *phase_resolver,
    const axutil_env_t *env,
    axis2_svc_t *svc,
    axis2_module_desc_t *module_desc)
{
    axutil_hash_t *ops = NULL;
    axis2_bool_t engaged = AXIS2_FALSE;
    axutil_hash_index_t *index_i = NULL;
    int type = 0;
    axis2_status_t status = AXIS2_FAILURE;
    axis2_phase_holder_t *phase_holder = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, svc, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, module_desc, AXIS2_FAILURE);

    ops = axis2_svc_get_all_ops(svc, env);
    if (!ops)
    {
        return AXIS2_FAILURE;
    }

    for (index_i = axutil_hash_first(ops, env); index_i;
        index_i = axutil_hash_next(env, index_i))
    {
        void *v = NULL;
        axis2_op_t *op_desc = NULL;
        int j = 0;
        axutil_array_list_t *modules = NULL;
        axis2_flow_t *flow = NULL;
        const axutil_qname_t *module_desc_qname = NULL;
        int size = 0;

        axutil_hash_this(index_i, NULL, NULL, &v);
        op_desc = (axis2_op_t *) v;
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "Operation name is : %s",
            axutil_qname_get_localpart(axis2_op_get_qname(op_desc, env), env));
        modules = axis2_op_get_all_modules(op_desc, env);
        module_desc_qname = axis2_module_desc_get_qname(module_desc, env);
        if (modules)
	{
            size = axutil_array_list_size(modules, env);
	}
        for (j = 0; j < size; j++)
        {
            axis2_module_desc_t *module_desc_l = NULL;
            const axutil_qname_t *module_desc_qname_l = NULL;

            module_desc_l = (axis2_module_desc_t *)
                axutil_array_list_get(modules, env, j);

            module_desc_qname_l = axis2_module_desc_get_qname(module_desc_l ,
                env);
            if (axutil_qname_equals(module_desc_qname_l, env, module_desc_qname))
            {
                engaged = AXIS2_TRUE;
                break;
            }
        }
        
        if (AXIS2_TRUE == engaged)
        {
            continue;
        }
        
        for (type = 1; type < 5; type++)
        {
            switch (type)
            {
                case AXIS2_IN_FLOW:
                {
                    axutil_array_list_t *phase_list = NULL;

                    phase_list = axis2_op_get_in_flow(op_desc, env);
                    phase_holder =
                        axis2_phase_holder_create_with_phases(env, phase_list);
                    break;
                }
                case AXIS2_OUT_FLOW:
                {
                    axutil_array_list_t *phase_list = NULL;

                    phase_list = axis2_op_get_out_flow(op_desc, env);
                    phase_holder =
                        axis2_phase_holder_create_with_phases(env, phase_list);
                    break;
                }
                case AXIS2_FAULT_IN_FLOW:
                {
                    axutil_array_list_t *phase_list = NULL;

                    phase_list = axis2_op_get_fault_in_flow(op_desc, env);
                    phase_holder =
                        axis2_phase_holder_create_with_phases(env, phase_list);
                    break;
                }
                case AXIS2_FAULT_OUT_FLOW:
                {
                    axutil_array_list_t *phase_list = NULL;

                    phase_list = axis2_op_get_fault_out_flow(op_desc, env);
                    phase_holder =
                        axis2_phase_holder_create_with_phases(env, phase_list);
                    break;
                }
            }

            /* process modules referred by axis2.xml */

            switch (type)
            {
                case AXIS2_IN_FLOW:
                {
                    flow = axis2_module_desc_get_in_flow(module_desc, env);
                    break;
                }
                case AXIS2_OUT_FLOW:
                {
                    flow = axis2_module_desc_get_out_flow(module_desc, env);
                    break;
                }
                case AXIS2_FAULT_IN_FLOW:
                {
                    flow = axis2_module_desc_get_fault_in_flow(module_desc, env);
                    break;
                }
                case AXIS2_FAULT_OUT_FLOW:
                {
                    flow = axis2_module_desc_get_fault_out_flow(module_desc, env);
                    break;
                }
            }
            if (flow)
            {
                int handler_count = 0;

                handler_count  = axis2_flow_get_handler_count(flow, env);
                for (j = 0; j < handler_count; j++)
                {
                    axis2_handler_desc_t *metadata = NULL;
                    const axis2_char_t *phase_name = NULL;
                    axis2_phase_rule_t *phase_rule = NULL;

                    metadata = axis2_flow_get_handler(flow, env, j);
                    phase_rule = axis2_handler_desc_get_rules(metadata, env);
                    if (phase_rule)
                    {
                        phase_name = axis2_phase_rule_get_name(phase_rule, env);
                    }
                    if (!phase_name)
                    {
                        return AXIS2_FAILURE;
                    }
                    if ((0 != axutil_strcmp(AXIS2_PHASE_TRANSPORT_IN, phase_name)) &&
                        (0 != axutil_strcmp(AXIS2_PHASE_DISPATCH, phase_name)) &&
                        (0 != axutil_strcmp(AXIS2_PHASE_POST_DISPATCH, phase_name)) &&
                        (0 != axutil_strcmp(AXIS2_PHASE_PRE_DISPATCH, phase_name)))
                    {
                        if (phase_holder)
                        {
                            status = axis2_phase_holder_add_handler(
                                phase_holder, env, metadata);
                            if(!status)
                            {
                                axis2_phase_holder_free(phase_holder, env);
                                return status;
                            }
                        }
                    }
                }
            }
            
            if(phase_holder)
	    {
                axis2_phase_holder_free(phase_holder, env);
	    }
        }
        status = axis2_op_add_to_engaged_module_list(op_desc, env, module_desc);
        if (AXIS2_SUCCESS != status)
        {
            return status;
        }
    }

    return AXIS2_SUCCESS;
}


static axis2_status_t
axis2_phase_resolver_engage_to_global_chain(
    axis2_phase_resolver_t *phase_resolver,
    const axutil_env_t *env,
    axis2_module_desc_t *module_desc)
{
    int type = 0;
    axis2_status_t status = AXIS2_FAILURE;
    axis2_phase_holder_t *phase_holder = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    for (type = 1; type < 5; type++)
    {
        axis2_flow_t *flow = NULL;

        switch (type)
        {
            case AXIS2_IN_FLOW:
            {
                axutil_array_list_t *phase_list = NULL;

                phase_list =
                     axis2_conf_get_in_phases_upto_and_including_post_dispatch(
                     phase_resolver->axis2_config, env);
                phase_holder =
                    axis2_phase_holder_create_with_phases(env, phase_list);
                if (!phase_holder) continue;
                break;
            }
            case AXIS2_OUT_FLOW:
            {
                axutil_array_list_t *phase_list = NULL;

                phase_list =  axis2_conf_get_out_flow(phase_resolver->axis2_config,
                    env);
                phase_holder =
                    axis2_phase_holder_create_with_phases(env, phase_list);
                if (!phase_holder) continue;
                break;
            }
            case AXIS2_FAULT_IN_FLOW:
            {
                axutil_array_list_t *phase_list = NULL;

                phase_list =  axis2_conf_get_in_fault_flow(phase_resolver->
                    axis2_config, env);
                phase_holder =
                    axis2_phase_holder_create_with_phases(env, phase_list);
                if (!phase_holder) continue;
                break;
            }
            case AXIS2_FAULT_OUT_FLOW:
            {
                axutil_array_list_t *phase_list = NULL;

                phase_list =  axis2_conf_get_out_fault_flow(phase_resolver->
                    axis2_config, env);
                phase_holder =
                    axis2_phase_holder_create_with_phases(env, phase_list);
                if (!phase_holder) continue;
                break;
            }
        }

        /* modules referred by axis2.xml */

        switch (type)
        {
            case AXIS2_IN_FLOW:
            {
                flow = axis2_module_desc_get_in_flow(module_desc, env);
                break;
            }
            case AXIS2_OUT_FLOW:
            {
                flow = axis2_module_desc_get_out_flow(module_desc, env);
                break;
            }
            case AXIS2_FAULT_IN_FLOW:
            {
                flow = axis2_module_desc_get_fault_in_flow(module_desc, env);
                break;
            }
            case AXIS2_FAULT_OUT_FLOW:
            {
                flow = axis2_module_desc_get_fault_out_flow(module_desc, env);
                break;
            }
        }
        if (flow)
        {
            int j = 0;
            for (j = 0; j < axis2_flow_get_handler_count(flow, env); j++)
            {
                axis2_handler_desc_t *metadata = NULL;
                const axis2_char_t *phase_name = NULL;
                axis2_phase_rule_t *phase_rule = NULL;

                metadata = axis2_flow_get_handler(flow, env, j);
                phase_rule = axis2_handler_desc_get_rules(metadata, env);
                if (phase_rule)
                {
                    phase_name = axis2_phase_rule_get_name(phase_rule, env);
                }
                if (!phase_name)
                {
                    return AXIS2_FAILURE;
                }
                if ((0 == axutil_strcmp(AXIS2_PHASE_TRANSPORT_IN, phase_name)) ||
                    (0 == axutil_strcmp(AXIS2_PHASE_DISPATCH, phase_name)) ||
                    (0 == axutil_strcmp(AXIS2_PHASE_POST_DISPATCH, phase_name)) ||
                    (0 == axutil_strcmp(AXIS2_PHASE_PRE_DISPATCH, phase_name)))
                {
                    status = axis2_phase_holder_add_handler(phase_holder, env, 
                        metadata);
                    if (!status)
                    {
                        axis2_phase_holder_free(phase_holder, env);
                        return status;
                    }

                }
            }
        }
    
        if(phase_holder)    
	{
            axis2_phase_holder_free(phase_holder, env);
	}
    }

    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_phase_resolver_engage_module_to_svc(
    axis2_phase_resolver_t *phase_resolver,
    const axutil_env_t *env,
    axis2_svc_t *svc,
    axis2_module_desc_t *module_desc)
{
    axutil_hash_t *ops = NULL;
    axutil_hash_index_t *index_i = NULL;
    axis2_status_t status = AXIS2_FAILURE;
    const axutil_qname_t *module_d_qname = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    ops = axis2_svc_get_all_ops(svc, env);
    if (!ops)
    {
        return AXIS2_FAILURE;
    }
    status = axis2_svc_add_module_ops(svc, env, module_desc,
        phase_resolver->axis2_config);

    if (AXIS2_SUCCESS != status)
    {
        return status;
    }
    module_d_qname = axis2_module_desc_get_qname(module_desc, env);
    for (index_i = axutil_hash_first(ops, env); index_i; index_i =
        axutil_hash_next(env, index_i))
    {
        axutil_array_list_t *modules = NULL;
        axis2_op_t *op_desc = NULL;
        int size = 0;
        int j = 0;
        void *v = NULL;
        axis2_bool_t engaged = AXIS2_FALSE;

        axutil_hash_this(index_i, NULL, NULL, &v);
        op_desc = (axis2_op_t *) v;
        modules = axis2_op_get_all_modules(op_desc, env);
        if (modules)
        {
            size = axutil_array_list_size(modules, env);
        }
        for (j = 0; j < size; j++)
        {
            axis2_module_desc_t *module_desc_l = NULL;
            const axutil_qname_t *module_d_qname_l = NULL;

            module_desc_l = axutil_array_list_get(modules, env, j);
            module_d_qname_l = axis2_module_desc_get_qname(module_desc_l, env);
            if (AXIS2_TRUE == axutil_qname_equals(module_d_qname, env,
                module_d_qname_l))
            {
                engaged = AXIS2_TRUE;
                status = AXIS2_SUCCESS;
                AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
                    "Module %s already engaged.", 
                    axutil_qname_get_localpart(module_d_qname, env));
                break;
            }
        }

        if (AXIS2_FALSE == engaged)
        {
            status = axis2_phase_resolver_engage_module_to_op(
                phase_resolver, env, op_desc, module_desc);
            if (AXIS2_SUCCESS != status)
            {
                return status;
            }

            status = axis2_op_add_to_engaged_module_list(op_desc, env,
                module_desc);
        }

    }
    return status; 
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_phase_resolver_disengage_module_from_svc(
    axis2_phase_resolver_t *phase_resolver,
    const axutil_env_t *env,
    axis2_svc_t *svc,
    axis2_module_desc_t *module_desc)
{
    axutil_hash_t *ops = NULL;
    axutil_hash_index_t *index_i = NULL;
    axis2_status_t status = AXIS2_FAILURE;
    const axutil_qname_t *module_d_qname = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    ops = axis2_svc_get_all_ops(svc, env);
    if (!ops)
    {
        return AXIS2_FAILURE;
    }
/*     status = axis2_svc_add_module_ops(svc, env, module_desc, */
/*         phase_resolver->axis2_config); */

/*     if (AXIS2_SUCCESS != status) */
/*     { */
/*         return status; */
/*     } */
    module_d_qname = axis2_module_desc_get_qname(module_desc, env);
    for (index_i = axutil_hash_first(ops, env); index_i; index_i =
        axutil_hash_next(env, index_i))
    {
        axutil_array_list_t *modules = NULL;
        axis2_op_t *op_desc = NULL;
        int size = 0;
        int j = 0;
        void *v = NULL;
        axis2_bool_t engaged = AXIS2_FALSE;

        axutil_hash_this(index_i, NULL, NULL, &v);
        op_desc = (axis2_op_t *) v;
        modules = axis2_op_get_all_modules(op_desc, env);
        if (modules)
        {
            size = axutil_array_list_size(modules, env);
        }
        for (j = 0; j < size; j++)
        {
            axis2_module_desc_t *module_desc_l = NULL;
            const axutil_qname_t *module_d_qname_l = NULL;

            module_desc_l = axutil_array_list_get(modules, env, j);
            module_d_qname_l = axis2_module_desc_get_qname(module_desc_l, env);
            if (AXIS2_TRUE == axutil_qname_equals(module_d_qname, env,
                module_d_qname_l))
            {
                engaged = AXIS2_TRUE;
                AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
                    "Module %s already engaged.", 
                    axutil_qname_get_localpart(module_d_qname, env));
                break;
            }
        }

        if (AXIS2_TRUE == engaged)
        {
            status = axis2_phase_resolver_disengage_module_from_op(
                phase_resolver, env, op_desc, module_desc);
            if (AXIS2_SUCCESS != status)
            {
                return status;
            }

            status = axis2_op_remove_from_engaged_module_list(op_desc, env,
                module_desc);
        }

    }
    return status; 
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_phase_resolver_engage_module_to_op(
    axis2_phase_resolver_t *phase_resolver,
    const axutil_env_t *env,
    axis2_op_t *axis_op,
    axis2_module_desc_t *module_desc)
{
    int type = 0;
    axis2_phase_holder_t *phase_holder = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, axis_op, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, module_desc, AXIS2_FAILURE);

    for (type = 1; type < 5; type++)
    {
        axis2_flow_t *flow = NULL;
        axutil_array_list_t *phases = NULL;

        switch (type)
        {
            case AXIS2_IN_FLOW:
            {
                phases = axis2_op_get_in_flow(axis_op, env);
                break;
            }
            case AXIS2_OUT_FLOW:
            {
                phases = axis2_op_get_out_flow(axis_op, env);
                break;
            }
            case AXIS2_FAULT_IN_FLOW:
            {
                phases = axis2_op_get_fault_in_flow(axis_op, env);
                break;
            }
            case AXIS2_FAULT_OUT_FLOW:
            {
                phases = axis2_op_get_fault_out_flow(axis_op, env);
                break;
            }
        }

        if (phases)
        {
            phase_holder =
                axis2_phase_holder_create_with_phases(env, phases);
        }


        switch (type)
        {
            case AXIS2_IN_FLOW:
            {
                flow = axis2_module_desc_get_in_flow(module_desc, env);
                break;
            }
            case AXIS2_OUT_FLOW:
            {
                flow = axis2_module_desc_get_out_flow(module_desc, env);
                break;
            }
            case AXIS2_FAULT_IN_FLOW:
            {
                flow = axis2_module_desc_get_fault_in_flow(module_desc, env);
                break;
            }
            case AXIS2_FAULT_OUT_FLOW:
            {
                flow = axis2_module_desc_get_fault_out_flow(module_desc, env);
                break;
            }
        }

        if (flow && phase_holder)
        {
            int j = 0;
            int handler_count = 0;

            handler_count = axis2_flow_get_handler_count(flow, env);
            for (j = 0; j < handler_count; j++)
            {
                axis2_handler_desc_t *metadata = NULL;
                const axis2_char_t *phase_name = NULL;
                axis2_phase_rule_t *phase_rule = NULL;
                axis2_status_t status = AXIS2_FAILURE;

                metadata = axis2_flow_get_handler(flow, env, j);
                phase_rule = axis2_handler_desc_get_rules(metadata, env);
                phase_name = axis2_phase_rule_get_name(phase_rule, env);
                if ((0 != axutil_strcmp(AXIS2_PHASE_TRANSPORT_IN, phase_name)) &&
                    (0 != axutil_strcmp(AXIS2_PHASE_DISPATCH, phase_name)) &&
                    (0 != axutil_strcmp(AXIS2_PHASE_POST_DISPATCH, phase_name)) &&
                    (0 != axutil_strcmp(AXIS2_PHASE_PRE_DISPATCH, phase_name)))
                {
                    status = axis2_phase_holder_add_handler(phase_holder,
                        env, metadata);
                    if (AXIS2_SUCCESS != status)
                    {
                        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
                            "Handler inclusion failed for %s phase", phase_name);
                        axis2_phase_holder_free(phase_holder, env);
                        return status;
                    }

                }
                if ((0 == axutil_strcmp(AXIS2_PHASE_TRANSPORT_IN, phase_name)) ||
                    (0 == axutil_strcmp(AXIS2_PHASE_DISPATCH, phase_name)) ||
                    (0 == axutil_strcmp(AXIS2_PHASE_POST_DISPATCH, phase_name)) ||
                    (0 == axutil_strcmp(AXIS2_PHASE_PRE_DISPATCH, phase_name)))
                {
                    axutil_array_list_t *phase_list = NULL;
                    axis2_phase_holder_t *phase_holder = NULL;

                    phase_list =
                         axis2_conf_get_in_phases_upto_and_including_post_dispatch(
                         phase_resolver->axis2_config, env);
                    if (phase_holder)
                    {
                        axis2_phase_holder_free(phase_holder, env);
                        phase_holder = NULL;
                    }
                    phase_holder =
                        axis2_phase_holder_create_with_phases(env, phase_list);

                    status = axis2_phase_holder_add_handler(phase_holder, env, metadata);
                    axis2_phase_holder_free(phase_holder, env);
                    phase_holder = NULL;
                    if (AXIS2_SUCCESS != status)
                    {
                        return status;
                    }
                }
            }
        }

        if(phase_holder)
        {
            axis2_phase_holder_free(phase_holder, env);
            phase_holder = NULL;
        }
    }
    
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_phase_resolver_disengage_module_from_op(
    axis2_phase_resolver_t *phase_resolver,
    const axutil_env_t *env,
    axis2_op_t *axis_op,
    axis2_module_desc_t *module_desc)
{
    int type = 0;
    axis2_phase_holder_t *phase_holder = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, axis_op, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, module_desc, AXIS2_FAILURE);

    for (type = 1; type < 5; type++)
    {
        axis2_flow_t *flow = NULL;
        axutil_array_list_t *phases = NULL;

        switch (type)
        {
            case AXIS2_IN_FLOW:
            {
                phases = axis2_op_get_in_flow(axis_op, env);
                break;
            }
            case AXIS2_OUT_FLOW:
            {
                phases = axis2_op_get_out_flow(axis_op, env);
                break;
            }
            case AXIS2_FAULT_IN_FLOW:
            {
                phases = axis2_op_get_fault_in_flow(axis_op, env);
                break;
            }
            case AXIS2_FAULT_OUT_FLOW:
            {
                phases = axis2_op_get_fault_out_flow(axis_op, env);
                break;
            }
        }

        if (phases)
        {
            phase_holder =
                axis2_phase_holder_create_with_phases(env, phases);
        }


        switch (type)
        {
            case AXIS2_IN_FLOW:
            {
                flow = axis2_module_desc_get_in_flow(module_desc, env);
                break;
            }
            case AXIS2_OUT_FLOW:
            {
                flow = axis2_module_desc_get_out_flow(module_desc, env);
                break;
            }
            case AXIS2_FAULT_IN_FLOW:
            {
                flow = axis2_module_desc_get_fault_in_flow(module_desc, env);
                break;
            }
            case AXIS2_FAULT_OUT_FLOW:
            {
                flow = axis2_module_desc_get_fault_out_flow(module_desc, env);
                break;
            }
        }

        if (flow && phase_holder)
        {
            int j = 0;
            int handler_count = 0;

            handler_count = axis2_flow_get_handler_count(flow, env);
            for (j = 0; j < handler_count; j++)
            {
                axis2_handler_desc_t *metadata = NULL;
                const axis2_char_t *phase_name = NULL;
                axis2_phase_rule_t *phase_rule = NULL;
                axis2_status_t status = AXIS2_FAILURE;

                metadata = axis2_flow_get_handler(flow, env, j);
                phase_rule = axis2_handler_desc_get_rules(metadata, env);
                phase_name = axis2_phase_rule_get_name(phase_rule, env);
                if ((0 != axutil_strcmp(AXIS2_PHASE_TRANSPORT_IN, phase_name)) &&
                    (0 != axutil_strcmp(AXIS2_PHASE_DISPATCH, phase_name)) &&
                    (0 != axutil_strcmp(AXIS2_PHASE_POST_DISPATCH, phase_name)) &&
                    (0 != axutil_strcmp(AXIS2_PHASE_PRE_DISPATCH, phase_name)))
                {
                    status = axis2_phase_holder_remove_handler(phase_holder,
                        env, metadata);
                    if (AXIS2_SUCCESS != status)
                    {
                        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
                            "Handler Removal failed for %s phase", phase_name);
                        axis2_phase_holder_free(phase_holder, env);
                        return status;
                    }

                }
                if ((0 == axutil_strcmp(AXIS2_PHASE_TRANSPORT_IN, phase_name)) ||
                    (0 == axutil_strcmp(AXIS2_PHASE_DISPATCH, phase_name)) ||
                    (0 == axutil_strcmp(AXIS2_PHASE_POST_DISPATCH, phase_name)) ||
                    (0 == axutil_strcmp(AXIS2_PHASE_PRE_DISPATCH, phase_name)))
                {
                    axutil_array_list_t *phase_list = NULL;
                    axis2_phase_holder_t *phase_holder = NULL;

                    phase_list =
                         axis2_conf_get_in_phases_upto_and_including_post_dispatch(
                         phase_resolver->axis2_config, env);
                    if (phase_holder)
                    {
                        axis2_phase_holder_free(phase_holder, env);
                        phase_holder = NULL;
                    }
                    phase_holder =
                        axis2_phase_holder_create_with_phases(env, phase_list);

                    status = axis2_phase_holder_remove_handler(phase_holder, env, metadata);
                    axis2_phase_holder_free(phase_holder, env);
                    phase_holder = NULL;
                    if (AXIS2_SUCCESS != status)
                    {
                        return status;
                    }
                }
            }
        }

        if(phase_holder)
        {
            axis2_phase_holder_free(phase_holder, env);
            phase_holder = NULL;
        }
    }
    
    return AXIS2_SUCCESS;
}

