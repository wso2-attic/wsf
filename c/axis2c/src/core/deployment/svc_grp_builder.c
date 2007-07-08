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

#include <axis2_svc_grp_builder.h>

struct axis2_svc_grp_builder
{
    axiom_node_t *svc_grp;
    axis2_desc_builder_t *desc_builder;
};

AXIS2_EXTERN axis2_svc_grp_builder_t *AXIS2_CALL
axis2_svc_grp_builder_create(const axutil_env_t *env)
{
    axis2_svc_grp_builder_t *svc_grp_builder = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    svc_grp_builder = (axis2_svc_grp_builder_t *) AXIS2_MALLOC(env->allocator,
        sizeof(axis2_svc_grp_builder_t));

    if (! svc_grp_builder)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    svc_grp_builder->svc_grp = NULL;
    svc_grp_builder->desc_builder = NULL;

    return svc_grp_builder;
}

AXIS2_EXTERN axis2_svc_grp_builder_t *AXIS2_CALL
axis2_svc_grp_builder_create_with_svc_and_dep_engine(const axutil_env_t *env,
    axiom_node_t *svc_grp,
    axis2_dep_engine_t *dep_engine)
{
    axis2_svc_grp_builder_t *svc_grp_builder = NULL;

    svc_grp_builder = (axis2_svc_grp_builder_t *)
        axis2_svc_grp_builder_create(env);
    if (!svc_grp_builder)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        svc_grp_builder = NULL;
    }
    svc_grp_builder->desc_builder =
        axis2_desc_builder_create_with_dep_engine(env, dep_engine);
    if (!svc_grp_builder->desc_builder)
    {
        axis2_svc_grp_builder_free(svc_grp_builder, env);
        return NULL;
    }
    svc_grp_builder->svc_grp = svc_grp;

    return svc_grp_builder;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_svc_grp_builder_free(axis2_svc_grp_builder_t *svc_grp_builder,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (svc_grp_builder->desc_builder)
    {
        axis2_desc_builder_free(svc_grp_builder->desc_builder,
            env);
    }
    if (svc_grp_builder)
    {
        AXIS2_FREE(env->allocator, svc_grp_builder);
    }

    return;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_svc_grp_builder_populate_svc_grp(axis2_svc_grp_builder_t *svc_grp_builder,
    const axutil_env_t *env,
    axis2_svc_grp_t *svc_grp)
{
    axiom_children_qname_iterator_t *itr = NULL;
    axiom_children_qname_iterator_t *module_ref_itr = NULL;
    axiom_children_qname_iterator_t *svc_itr = NULL;
    axutil_qname_t *qparamst = NULL;
    axutil_qname_t *qmodulest = NULL;
    axutil_qname_t *qsvc_element = NULL;
    axiom_element_t *svc_grp_element = NULL;
    axis2_status_t status = AXIS2_FAILURE;
    axis2_conf_t *parent = NULL;

    /* Processing service level paramters */
    svc_grp_element = axiom_node_get_data_element(svc_grp_builder->svc_grp, env);
    qparamst = axutil_qname_create(env, AXIS2_PARAMETERST, NULL, NULL);

    itr = axiom_element_get_children_with_qname(svc_grp_element, env, qparamst,
        svc_grp_builder->svc_grp);

    if (qparamst)
    {
        axutil_qname_free(qparamst, env);
        qparamst = NULL;
    }

    parent =  axis2_svc_grp_get_parent(svc_grp, env);
    status = axis2_desc_builder_process_params(svc_grp_builder->desc_builder, env, itr, 
        axis2_svc_grp_get_param_container(svc_grp, env), 
        axis2_conf_get_param_container(parent, env));

    /* Processing service modules required to be engaged globally */
    qmodulest = axutil_qname_create(env, AXIS2_MODULEST, NULL, NULL);
    module_ref_itr = axiom_element_get_children_with_qname(svc_grp_element, env,
        qmodulest, svc_grp_builder->svc_grp);

    if (qmodulest)
    {
        axutil_qname_free(qmodulest, env);
        qmodulest = NULL;
    }

    axis2_svc_grp_builder_process_module_refs(svc_grp_builder, env, module_ref_itr,
        svc_grp);
    qsvc_element = axutil_qname_create(env, AXIS2_SVC_ELEMENT, NULL, NULL);
    svc_itr = axiom_element_get_children_with_qname(svc_grp_element, env,
        qsvc_element, svc_grp_builder->svc_grp);

    if (qsvc_element)
    {
        axutil_qname_free(qsvc_element, env);
        qsvc_element = NULL;
    }

    while (AXIS2_TRUE == axiom_children_qname_iterator_has_next(svc_itr, env))
    {
        axiom_node_t *svc_node = NULL;
        axiom_element_t *svc_element = NULL;
        axiom_attribute_t *svc_name_att = NULL;
        axis2_char_t *svc_name = NULL;
        axutil_qname_t *qattname = NULL;

        svc_node = (axiom_node_t *) axiom_children_qname_iterator_next(
            svc_itr, env);
        svc_element = axiom_node_get_data_element(svc_node, env);
        qattname = axutil_qname_create(env, AXIS2_ATTNAME, NULL, NULL);
        svc_name_att = axiom_element_get_attribute(svc_element, env, qattname);

        if (qattname)
        {
            axutil_qname_free(qattname, env);
            qattname = NULL;
        }

        svc_name = axiom_attribute_get_value(svc_name_att, env);
        if (! svc_name)
        {
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_SVC_NAME_ERROR,
                AXIS2_FAILURE);
            return AXIS2_FAILURE;
        }
        else
        {
            axis2_svc_t *axis_svc = NULL;
            axis2_arch_file_data_t *file_data = NULL;
            axutil_array_list_t *deployable_svcs = NULL;
            axis2_svc_builder_t *svc_builder = NULL;

            file_data = axis2_dep_engine_get_current_file_item(
                axis2_desc_builder_get_dep_engine(svc_grp_builder->desc_builder, env), 
                env);
            axis_svc = axis2_arch_file_data_get_svc(file_data, env, svc_name);
            if (! axis_svc)
            {
                axutil_qname_t *qsvc_name = NULL;

                qsvc_name = axutil_qname_create(env, svc_name, NULL, NULL);
                axis_svc = axis2_svc_create_with_qname(env, qsvc_name);
                axutil_qname_free(qsvc_name, env);
                axis2_arch_file_data_add_svc(file_data, env, axis_svc);

            }
            /* the service that has to be deployed */

            deployable_svcs = axis2_arch_file_data_get_deployable_svcs(file_data,
                env);
            axutil_array_list_add(deployable_svcs, env, axis_svc);
            axis2_svc_set_parent(axis_svc, env, svc_grp);
            svc_builder = axis2_svc_builder_create_with_dep_engine_and_svc(env,
                axis2_desc_builder_get_dep_engine(svc_grp_builder->desc_builder, env), 
                axis_svc);
            status = axis2_svc_builder_populate_svc(svc_builder, env, svc_node);
            axis2_svc_builder_free(svc_builder, env);

        }
    }
    return status;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_svc_grp_builder_process_module_refs(axis2_svc_grp_builder_t *svc_grp_builder,
    const axutil_env_t *env,
    axiom_children_qname_iterator_t *module_refs ,
    axis2_svc_grp_t *svc_grp)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, module_refs, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, svc_grp, AXIS2_FAILURE);

    while (AXIS2_TRUE == axiom_children_qname_iterator_has_next(module_refs, env))
    {
        axiom_node_t *module_ref_node = NULL;
        axiom_element_t *module_ref_element = NULL;
        axiom_attribute_t *module_ref_att = NULL;
        axutil_qname_t *qref = NULL;

        module_ref_node = (axiom_node_t *) 
            axiom_children_qname_iterator_next(module_refs, env);
        module_ref_element = axiom_node_get_data_element(module_ref_node, env);
        qref = axutil_qname_create(env, AXIS2_REF, NULL, NULL);
        module_ref_att = axiom_element_get_attribute(module_ref_element, env,
            qref);
        if (module_ref_att)
        {
            axis2_char_t *ref_name = NULL;
            axutil_qname_t *qrefname = NULL;
            axis2_module_desc_t *module = NULL;


            ref_name = axiom_attribute_get_value(module_ref_att, env);
            qrefname = axutil_qname_create(env, ref_name, NULL, NULL);
            module = axis2_dep_engine_get_module(
                axis2_desc_builder_get_dep_engine(svc_grp_builder->desc_builder, env), 
                env, qrefname);
            if (! module)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_MODULE_NOT_FOUND,
                    AXIS2_FAILURE);
                return AXIS2_FAILURE;
            }
            else
            {
                 axis2_svc_grp_add_module_ref(svc_grp, env, qrefname);
            }
            axutil_qname_free(qrefname, env);
        }
        axutil_qname_free(qref, env);
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_desc_builder_t *AXIS2_CALL
axis2_svc_grp_builder_get_desc_builder(const axis2_svc_grp_builder_t *svc_grp_builder,
    const axutil_env_t *env)
{
    return svc_grp_builder->desc_builder;
}

