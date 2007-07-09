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

#include <axis2_module_builder.h>
#include <axis2_arch_file_data.h>

struct axis2_module_builder
{
    axis2_module_desc_t *module_desc;
    struct axis2_desc_builder *desc_builder;
};

static axutil_array_list_t *AXIS2_CALL
axis2_module_builder_process_ops(axis2_module_builder_t *module_builder,
    const axutil_env_t *env,
    axiom_children_qname_iterator_t *op_itr);

AXIS2_EXTERN axis2_module_builder_t *AXIS2_CALL
axis2_module_builder_create(const axutil_env_t *env)
{
    axis2_module_builder_t *module_builder = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    module_builder = (axis2_module_builder_t *) AXIS2_MALLOC(env->allocator,
        sizeof(axis2_module_builder_t));


    if (! module_builder)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    return module_builder;
}

AXIS2_EXTERN axis2_module_builder_t *AXIS2_CALL
axis2_module_builder_create_with_file_and_dep_engine_and_module(const axutil_env_t *env,
    axis2_char_t *file_name,
    axis2_dep_engine_t *dep_engine,
    axis2_module_desc_t *module_desc)
{
    axis2_module_builder_t *module_builder = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    module_builder = (axis2_module_builder_t *) axis2_module_builder_create(env);
    if (! module_builder)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    module_builder->desc_builder =
        axis2_desc_builder_create_with_file_and_dep_engine(env, file_name,
            dep_engine);
    if (!module_builder->desc_builder)
    {
        axis2_module_builder_free(module_builder, env);
        return NULL;
    }
    module_builder->module_desc = module_desc;
    return module_builder;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_module_builder_free(axis2_module_builder_t *module_builder,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (module_builder->desc_builder)
    {
        axis2_desc_builder_free(module_builder->desc_builder, env);
    }

    if (module_builder)
    {
        AXIS2_FREE(env->allocator, module_builder);
    }

    return;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_module_builder_populate_module(axis2_module_builder_t *module_builder,
    const axutil_env_t *env)
{
    axiom_element_t *module_element = NULL;
    axiom_node_t *module_node = NULL;
    axutil_qname_t *qdllname = NULL;
    axutil_qname_t *qparamst = NULL;
    axutil_qname_t *qinflowst = NULL;
    axutil_qname_t *qoutflowst = NULL;
    axutil_qname_t *qinfaultflow = NULL;
    axutil_qname_t *qoutfaultflow = NULL;
    axutil_qname_t *qopst = NULL;
    axiom_attribute_t *module_dll_att = NULL;
    axiom_children_qname_iterator_t *itr = NULL;
    axiom_children_qname_iterator_t *op_itr = NULL;
    axiom_element_t *in_flow_element = NULL;
    axiom_node_t *in_flow_node = NULL;
    axiom_element_t *out_flow_element = NULL;
    axiom_node_t *out_flow_node = NULL;
    axiom_element_t *in_fault_flow_element = NULL;
    axiom_node_t *in_fault_flow_node = NULL;
    axiom_element_t *out_fault_flow_element = NULL;
    axiom_node_t *out_fault_flow_node = NULL;
    axis2_conf_t *parent = NULL;
    axutil_array_list_t *ops = NULL;
    axutil_param_container_t *parent_container = NULL;
    int size = 0;
    int i = 0;
    axis2_status_t status = AXIS2_FAILURE;

    AXIS2_LOG_TRACE(env->log, AXIS2_LOG_SI, "axis2_module_builder_populate_module start");

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    module_node = axis2_desc_builder_build_om(module_builder->desc_builder, env);
    module_element = axiom_node_get_data_element(module_node, env);
    if (!module_element)
    {
        return AXIS2_FAILURE;
    }
    {
        axis2_arch_file_data_t *file_data = NULL;
        axis2_char_t *module_name = NULL;
        axutil_qname_t *module_qname = NULL;

        file_data = axis2_dep_engine_get_current_file_item(
            axis2_desc_builder_get_dep_engine(module_builder->desc_builder, env), 
            env);
        module_name = axis2_arch_file_data_get_module_name(file_data, env);

        module_qname = axutil_qname_create(env, module_name, NULL, NULL);
        axis2_module_desc_set_qname(module_builder->module_desc, env, module_qname);

        if (module_qname)
        {
            axutil_qname_free(module_qname, env);
        }
    }

    /* Setting Module Dll Name , if it is there */

    qdllname = axutil_qname_create(env, AXIS2_CLASSNAME, NULL, NULL);
    module_dll_att = axiom_element_get_attribute(module_element, env, qdllname);
    if (qdllname)
    {
        axutil_qname_free(qdllname, env);
    }

    if (module_dll_att)
    {
        axis2_char_t *class_name = NULL;


        class_name = axiom_attribute_get_value(module_dll_att, env);
        if (class_name && (0 != axutil_strcmp("", class_name)))
        {
            axis2_dep_engine_t *dep_engine = 
                axis2_desc_builder_get_dep_engine(module_builder->desc_builder, env);
            if (dep_engine)
            {
                axis2_arch_file_data_t *file_data = NULL;

                file_data = axis2_dep_engine_get_current_file_item(
                    dep_engine, env);
                axis2_arch_file_data_set_module_dll_name(file_data, env,
                    class_name);
            }
        }
    }

    /* Processing Paramters */
    /* Processing service level paramters */

    qparamst = axutil_qname_create(env, AXIS2_PARAMETERST, NULL, NULL);
    itr = axiom_element_get_children_with_qname(module_element, env,
        qparamst, module_node);
    if (qparamst)
    {
        axutil_qname_free(qparamst, env);
    }
    parent = axis2_module_desc_get_parent(module_builder->module_desc, env);

    if (parent)
    {
        parent_container = axis2_conf_get_param_container(parent, env);
    }
    axis2_desc_builder_process_params(module_builder->desc_builder, env,
        itr, axis2_module_desc_get_param_container(module_builder->module_desc, env), 
        parent_container);

    /* Process IN_FLOW */
    qinflowst = axutil_qname_create(env, AXIS2_IN_FLOW_START, NULL, NULL);
    in_flow_element = axiom_element_get_first_child_with_qname(module_element,
        env, qinflowst, module_node, &in_flow_node);
    if (qinflowst)
    {
        axutil_qname_free(qinflowst, env);
    }

    if (in_flow_element && NULL != in_flow_node)
    {
        axis2_flow_t *flow = NULL;

        flow = axis2_desc_builder_process_flow(module_builder->desc_builder,
            env, in_flow_element, 
            axis2_module_desc_get_param_container(module_builder->module_desc, env),
            in_flow_node);
        status = axis2_module_desc_set_in_flow(module_builder->module_desc, env, flow);

        if (AXIS2_SUCCESS != status)
        {
            if (flow)
            {
                axis2_flow_free(flow, env);
            }
            return status;
        }
    }

    qoutflowst = axutil_qname_create(env, AXIS2_OUT_FLOW_START, NULL, NULL);
    out_flow_element = axiom_element_get_first_child_with_qname(module_element,
        env, qoutflowst, module_node, &out_flow_node);
    if (qoutflowst)
    {
        axutil_qname_free(qoutflowst, env);
    }

    if (out_flow_element && NULL != out_flow_node)
    {
        axis2_flow_t *flow = NULL;

        flow = axis2_desc_builder_process_flow(module_builder->desc_builder,
            env, out_flow_element, 
            axis2_module_desc_get_param_container(module_builder->module_desc, env),
            out_flow_node);
        status = axis2_module_desc_set_out_flow(module_builder->module_desc, env, flow);

        if (AXIS2_SUCCESS != status)
        {
            axis2_flow_free(flow, env);
            return status;
        }
    }

    qinfaultflow = axutil_qname_create(env, AXIS2_IN_FAILTFLOW, NULL, NULL);
    in_fault_flow_element = axiom_element_get_first_child_with_qname(module_element,
        env, qinfaultflow, module_node, &in_fault_flow_node);
    if (qinfaultflow)
    {
        axutil_qname_free(qinfaultflow, env);
    }

    if (in_fault_flow_element && NULL != in_fault_flow_node)
    {
        axis2_flow_t *flow = NULL;

        flow = axis2_desc_builder_process_flow(module_builder->desc_builder,
            env, in_fault_flow_element, 
            axis2_module_desc_get_param_container(module_builder->module_desc, env),
            in_fault_flow_node);
        status = axis2_module_desc_set_fault_in_flow(module_builder->module_desc,
            env, flow);

        if (AXIS2_SUCCESS != status)
        {
            axis2_flow_free(flow, env);
            return status;
        }
    }

    qoutfaultflow = axutil_qname_create(env, AXIS2_OUT_FAILTFLOW, NULL, NULL);
    out_fault_flow_element = axiom_element_get_first_child_with_qname(module_element,
        env, qoutfaultflow, module_node, &out_fault_flow_node);
    if (qoutfaultflow)
    {
        axutil_qname_free(qoutfaultflow, env);
    }

    if (out_fault_flow_element && NULL != out_fault_flow_node)
    {
        axis2_flow_t *flow = NULL;

        flow = axis2_desc_builder_process_flow(module_builder->desc_builder,
            env, out_fault_flow_element, 
            axis2_module_desc_get_param_container(module_builder->module_desc, env),
            out_fault_flow_node);
        status = axis2_module_desc_set_fault_out_flow(module_builder->module_desc,
            env, flow);
        if (AXIS2_SUCCESS != status)
        {
            axis2_flow_free(flow, env);
            return status;
        }
    }

    /* Processing Operations */
    qopst = axutil_qname_create(env, AXIS2_OPERATIONST, NULL, NULL);
    op_itr = axiom_element_get_children_with_qname(module_element, env,
        qopst, module_node);
    if (qopst)
    {
        axutil_qname_free(qopst, env);
    }
    ops = axis2_module_builder_process_ops(module_builder, env, op_itr);
    size = axutil_array_list_size(ops, env);
    for (i = 0; i < size; i++)
    {
        axis2_op_t *op_desc = NULL;

        op_desc = (axis2_op_t *) axutil_array_list_get(ops, env, i);
        axis2_module_desc_add_op(module_builder->module_desc, env, op_desc);
    }
    axutil_array_list_free(ops, env);
    AXIS2_LOG_TRACE(env->log, AXIS2_LOG_SI,
        "axis2_module_builder_populate_module end");
    return AXIS2_SUCCESS;
}


static axutil_array_list_t *AXIS2_CALL
axis2_module_builder_process_ops(axis2_module_builder_t *module_builder,
    const axutil_env_t *env,
    axiom_children_qname_iterator_t *op_itr)
{
    axutil_array_list_t *ops = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, op_itr, NULL);

    ops = axutil_array_list_create(env, 0);
    while (AXIS2_TRUE == axiom_children_qname_iterator_has_next(op_itr, env))
    {
        axiom_element_t *op_element = NULL;
        axiom_node_t *op_node = NULL;
        axiom_attribute_t *op_name_att = NULL;
        axiom_attribute_t *op_mep_att = NULL;
        axutil_qname_t *qattname = NULL;
        axis2_char_t *mep_url = NULL;
        axis2_char_t *op_name = NULL;
        axutil_qname_t *qopname = NULL;
        axutil_qname_t *qmsgrecv = NULL;
        axutil_qname_t *qparamst = NULL;
        axutil_qname_t *qmodulest = NULL;
        axutil_qname_t *qmep = NULL;
        axiom_children_qname_iterator_t *params = NULL;
        axiom_children_qname_iterator_t *modules = NULL;
        axiom_element_t *recv_element = NULL;
        axiom_node_t *recv_node = NULL;
        axis2_phases_info_t *info = NULL;
        axis2_op_t *op_desc = NULL;

        op_node = (axiom_node_t *)
            axiom_children_qname_iterator_next(op_itr, env);
        op_element = axiom_node_get_data_element(op_node, env);
        /* getting operation name */
        qattname = axutil_qname_create(env, AXIS2_ATTNAME, NULL, NULL);
        op_name_att = axiom_element_get_attribute(op_element, env, qattname);
        if (qattname)
        {
            axutil_qname_free(qattname, env);
        }

        if (! op_name_att)
        {
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_OP_NAME_MISSING,
                AXIS2_FAILURE);
            return NULL;
        }
        qmep = axutil_qname_create(env, AXIS2_MEP, NULL, NULL);
        op_mep_att = axiom_element_get_attribute(op_element, env, qmep);
        if (qmep)
        {
            axutil_qname_free(qmep, env);
        }

        if (op_mep_att)
        {
            mep_url = axiom_attribute_get_value(op_mep_att, env);
        }
        if (! mep_url)
        {
            /* Assuming in-out mep */
            op_desc = axis2_op_create_from_module(env);
        }
        else
        {
            op_desc = axis2_op_create_from_module(env);
        }

        op_name = axiom_attribute_get_value(op_name_att, env);
        qopname = axutil_qname_create(env, op_name, NULL, NULL);
        axis2_op_set_qname(op_desc, env, qopname);
        if (qopname)
        {
            axutil_qname_free(qopname, env);
        }

        /* Operation parameters */
        qparamst = axutil_qname_create(env, AXIS2_PARAMETERST, NULL, NULL);
        params = axiom_element_get_children_with_qname(op_element, env,
            qparamst, op_node);
        if (qparamst)
        {
            axutil_qname_free(qparamst, env);
        }

        axis2_desc_builder_process_params(module_builder->desc_builder, env,
            params, 
            axis2_op_get_param_container(op_desc, env), 
            axis2_module_desc_get_param_container(module_builder->module_desc, env));
        /* To process wsamapping */
        axis2_desc_builder_process_action_mappings(module_builder->desc_builder, 
            env, op_node, op_desc);

        /* setting the mep of the operation */

        /* loading the message receivers */
        qmsgrecv = axutil_qname_create(env, AXIS2_MESSAGERECEIVER, NULL, NULL);
        recv_element = axiom_element_get_first_child_with_qname(op_element,
            env, qmsgrecv, op_node, &recv_node);
        if (qmsgrecv)
        {
            axutil_qname_free(qmsgrecv, env);
        }
        if (recv_element && NULL != recv_node)
        {
            axis2_msg_recv_t *msg_recv = NULL;

            msg_recv = axis2_desc_builder_load_msg_recv(module_builder->
                desc_builder, env, recv_element);
            axis2_op_set_msg_recv(op_desc, env, msg_recv);
        }
        else
        {
            axis2_msg_recv_t *msg_recv = NULL;
            /* setting default message reciver */
            msg_recv = axis2_desc_builder_load_default_msg_recv(env);
            axis2_op_set_msg_recv(op_desc, env, msg_recv);
        }
        /* Process Module Refs */
        qmodulest = axutil_qname_create(env, AXIS2_MODULEST, NULL, NULL);
        modules = axiom_element_get_children_with_qname(op_element, env,
            qmodulest, op_node);
        if (qmodulest)
        {
            axutil_qname_free(qmodulest, env);
        }
        axis2_desc_builder_process_op_module_refs(module_builder->desc_builder,
            env, modules, op_desc);
        /* setting Operation phase */
        info = axis2_dep_engine_get_phases_info(
            axis2_desc_builder_get_dep_engine(module_builder->desc_builder, env),
            env);
        axis2_phases_info_set_op_phases(info, env, op_desc);

        /* adding operation */
        axutil_array_list_add(ops, env, op_desc);
    }
    return ops;
}


