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

#include <axis2_desc_builder.h>
#include <axutil_string.h>
#include <axutil_class_loader.h>
#include <axutil_utils.h>
#include <axutil_generic_obj.h>
#include <axis2_raw_xml_in_out_msg_recv.h>

struct axis2_desc_builder
{
    /**
     * Store the full path to configuration file.
     */
    axis2_char_t *file_name;
    axiom_stax_builder_t *builder;
    struct axis2_dep_engine *engine;
};

static axis2_status_t
set_attrs_and_value(axutil_param_t *param,
    const axutil_env_t *env,
    axiom_element_t *param_element,
    axiom_node_t *param_node);

AXIS2_EXTERN axis2_desc_builder_t *AXIS2_CALL
axis2_desc_builder_create(const axutil_env_t *env)
{
    axis2_desc_builder_t *desc_builder = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    desc_builder = (axis2_desc_builder_t *) AXIS2_MALLOC(env->
            allocator, sizeof(axis2_desc_builder_t));


    if (! desc_builder)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    desc_builder->file_name = NULL;
    desc_builder->engine = NULL;
    desc_builder->builder = NULL;

    return desc_builder;
}

AXIS2_EXTERN axis2_desc_builder_t *AXIS2_CALL
axis2_desc_builder_create_with_file_and_dep_engine(const axutil_env_t *env,
    axis2_char_t *file_name,
    axis2_dep_engine_t *engine)
{
    axis2_desc_builder_t *desc_builder = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, file_name, NULL);
    AXIS2_PARAM_CHECK(env->error, engine, NULL);

    desc_builder = (axis2_desc_builder_t *)
        axis2_desc_builder_create(env);
    if (! desc_builder)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    desc_builder->file_name = axutil_strdup(env, file_name);
    if (!desc_builder->file_name)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    desc_builder->engine = engine;

    return desc_builder;
}

AXIS2_EXTERN axis2_desc_builder_t *AXIS2_CALL
axis2_desc_builder_create_with_dep_engine(const axutil_env_t *env,
    struct axis2_dep_engine *engine)
{
    axis2_desc_builder_t *desc_builder = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, engine, NULL);

    desc_builder = (axis2_desc_builder_t *)
        axis2_desc_builder_create(env);
    if (! desc_builder)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    desc_builder->engine = engine;

    return desc_builder;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_desc_builder_free(axis2_desc_builder_t *desc_builder,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (desc_builder->file_name)
    {
        AXIS2_FREE(env->allocator, desc_builder->file_name);
    }

    if (desc_builder->builder)
    {
        axiom_stax_builder_free(desc_builder->builder, env);
    }

    /* we cannot free deployment engine here */
    desc_builder->engine = NULL;

    if (desc_builder)
    {
        AXIS2_FREE(env->allocator, desc_builder);
    }
    return;
}

AXIS2_EXTERN axiom_node_t *AXIS2_CALL
axis2_desc_builder_build_om(axis2_desc_builder_t *desc_builder,
    const axutil_env_t *env)
{
    axiom_xml_reader_t *reader = NULL;
    axiom_document_t *document = NULL;
    axiom_node_t *root = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    if (!desc_builder->file_name)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_STATE_DESC_BUILDER,
            AXIS2_FAILURE);
        return NULL;
    }
    /** create pull parser using the file path to configuration file */
    reader = axiom_xml_reader_create_for_file(env, desc_builder->file_name,
        NULL);

    if (!reader)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_CREATING_XML_STREAM_READER,
            AXIS2_FAILURE)
        return NULL;
    }

    /** create axiom_stax_builder by parsing pull_parser struct */
    desc_builder->builder = axiom_stax_builder_create(env, reader);

    if (!(desc_builder->builder))
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_CREATING_XML_STREAM_READER,
            AXIS2_FAILURE)
        return NULL;
    }
    /**
        get the om document form builder 
        document is the container of om model created using builder
    */
    document = axiom_stax_builder_get_document(desc_builder->builder, env);

    /**
     * In description building we don't want defferred building. So build
     * the whole tree at once
     */
    axiom_document_build_all(document, env);
    /**
        get root element , building starts hear 
     */
    root = axiom_document_get_root_element(document, env);
    return root;
}

AXIS2_EXTERN axis2_flow_t *AXIS2_CALL
axis2_desc_builder_process_flow(axis2_desc_builder_t *desc_builder,
    const axutil_env_t *env,
    axiom_element_t *flow_element,
    axutil_param_container_t *parent,
    axiom_node_t *flow_node)
{
    axis2_flow_t *flow = NULL;
    axiom_children_qname_iterator_t *handlers = NULL;
    axutil_qname_t *qchild = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, parent, NULL);
    AXIS2_PARAM_CHECK(env->error, flow_node, NULL);

    flow = axis2_flow_create(env);
    if (!flow)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    if (!flow_element)
    {
        return NULL;
    }

    qchild = axutil_qname_create(env, AXIS2_HANDLERST, NULL, NULL);
    handlers = axiom_element_get_children_with_qname(flow_element, env,
        qchild, flow_node);
    if (qchild)
    {
        axutil_qname_free(qchild, env);
    }

    while (AXIS2_TRUE == axiom_children_qname_iterator_has_next(handlers , env))
    {
        axiom_node_t *handler_node = NULL;
        axis2_handler_desc_t *handler_desc = NULL;
        axis2_status_t status = AXIS2_FAILURE;

        handler_node = (axiom_node_t *)
            axiom_children_qname_iterator_next(handlers, env);

        handler_desc = axis2_desc_builder_process_handler(desc_builder, env,
            handler_node, parent);
        status = axis2_flow_add_handler(flow, env, handler_desc);
        if (AXIS2_SUCCESS != status)
        {
            axis2_flow_free(flow, env);
            return NULL;
        }
    }

    return flow;
}

struct axis2_handler_desc *AXIS2_CALL
axis2_desc_builder_process_handler(axis2_desc_builder_t *desc_builder,
    const axutil_env_t *env,
    axiom_node_t *handler_node,
    struct axutil_param_container *parent)
{
    axis2_handler_desc_t *handler_desc = NULL;
    axiom_attribute_t *name_attrib = NULL;
    axutil_qname_t *attr_qname = NULL;
    axiom_attribute_t *class_attrib = NULL;
    axutil_qname_t *class_qname = NULL;
    axis2_status_t status = AXIS2_FAILURE;
    axis2_char_t *attrib_value = NULL;
    axiom_element_t *handler_element = NULL;
    axiom_node_t *order_node = NULL;
    axiom_element_t *order_element = NULL;
    axutil_qname_t *order_qname = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, handler_node, NULL);
    AXIS2_PARAM_CHECK(env->error, parent, NULL);

    handler_desc = axis2_handler_desc_create(env, NULL);
    if (!handler_desc)
    {
        return NULL;
    }
    /* Setting Handler name */
    attr_qname = axutil_qname_create(env, AXIS2_ATTNAME, NULL, NULL);
    handler_element = axiom_node_get_data_element(handler_node, env);
    name_attrib = axiom_element_get_attribute(handler_element, env,
        attr_qname);
    if (attr_qname)
    {
        axutil_qname_free(attr_qname, env);
    }

    if (!name_attrib)
    {
        axis2_handler_desc_free(handler_desc, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_HANDLER_STATE,
            AXIS2_FAILURE);
        return NULL;
    }
    else
    {
        axutil_string_t *handler_name = NULL;
        axis2_char_t *value = NULL;

        value = axiom_attribute_get_value(name_attrib, env);
        handler_name = axutil_string_create(env, value);
        status = axis2_handler_desc_set_name(handler_desc, env, handler_name);
        if (handler_name)
        {
            axutil_string_free(handler_name, env);
        }

        if (AXIS2_SUCCESS != status)
        {
            axis2_handler_desc_free(handler_desc, env);
            return NULL;
        }
    }

    /*Setting Handler Class name */
    class_qname = axutil_qname_create(env, AXIS2_CLASSNAME, NULL, NULL);
    class_attrib = axiom_element_get_attribute(handler_element, env,
        class_qname);
    if (class_qname)
    {
        axutil_qname_free(class_qname, env);
    }

    if (! class_attrib)
    {
        axis2_handler_desc_free(handler_desc, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_HANDLER_STATE,
            AXIS2_FAILURE);
        return NULL;
    }
    else
    {
        attrib_value = axiom_attribute_get_value(class_attrib, env);
        status = axis2_handler_desc_set_class_name(handler_desc, env, attrib_value);
    }

    /*processing phase Rules (order) */

    order_qname = axutil_qname_create(env, AXIS2_ORDER, NULL, NULL);
    order_element = axiom_element_get_first_child_with_qname(handler_element,
        env, order_qname, handler_node, &order_node);
    if (order_qname)
    {
        axutil_qname_free(order_qname, env);
    }

    if (! order_element || ! order_node)
    {
        axis2_handler_desc_free(handler_desc, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_HANDLER_STATE,
            AXIS2_FAILURE);
        return NULL;
    }
    else
    {
        axutil_hash_t *order_itr = NULL;
        axiom_children_qname_iterator_t *params = NULL;
        axutil_qname_t *param_qname = NULL;
        axutil_hash_index_t *index_i = NULL;

        order_itr = axiom_element_get_all_attributes(order_element, env);
        if (!order_itr)
        {
            axis2_handler_desc_free(handler_desc, env);
            return NULL;
        }

        index_i = axutil_hash_first(order_itr, env);

        while (index_i)
        {
            axiom_attribute_t *order_attrib = NULL;
            axutil_qname_t *qname = NULL;
            axis2_char_t *name = NULL;
            axis2_char_t *value = NULL;
            void *v = NULL;

            axutil_hash_this(index_i, NULL, NULL, &v);
            order_attrib = (axiom_attribute_t *) v;
            qname = axiom_attribute_get_qname(order_attrib, env);
            name = axutil_qname_get_localpart(qname, env);

            value = axiom_attribute_get_value(order_attrib, env);
            if (0 == axutil_strcmp(AXIS2_AFTER, name))
            {
                struct axis2_phase_rule *phase_rule = NULL;

                phase_rule = axis2_handler_desc_get_rules(handler_desc, env);
                status = axis2_phase_rule_set_after(phase_rule, env, value);
                if (AXIS2_SUCCESS != status)
                {
                    axis2_handler_desc_free(handler_desc, env);
                    return NULL;
                }
            }
            if (0 == axutil_strcmp(AXIS2_BEFORE, name))
            {
                struct axis2_phase_rule *phase_rule = NULL;
                phase_rule = axis2_handler_desc_get_rules(handler_desc, env);
                status = axis2_phase_rule_set_before(phase_rule, env, value);
                if (AXIS2_SUCCESS != status)
                {
                    axis2_handler_desc_free(handler_desc, env);
                    return NULL;
                }
            }
            if (0 == axutil_strcmp(AXIS2_PHASE, name))
            {
                struct axis2_phase_rule *phase_rule = NULL;
                phase_rule = axis2_handler_desc_get_rules(handler_desc, env);
                status = axis2_phase_rule_set_name(phase_rule, env, value);
                if (AXIS2_SUCCESS != status)
                {
                    axis2_handler_desc_free(handler_desc, env);
                    return NULL;
                }
            }
            if (0 == axutil_strcmp(AXIS2_PHASEFIRST, name))
            {
                axis2_char_t *bool_val = NULL;

                bool_val = axis2_desc_builder_get_value(desc_builder, env,
                    value);
                if (0 == axutil_strcmp(bool_val, "true"))
                {
                    struct axis2_phase_rule *phase_rule = NULL;
                    phase_rule = axis2_handler_desc_get_rules(handler_desc, env);
                    status = axis2_phase_rule_set_first(phase_rule, env,
                        AXIS2_TRUE);
                    if (AXIS2_SUCCESS != status)
                    {
                        axis2_handler_desc_free(handler_desc, env);
                        AXIS2_FREE(env->allocator, bool_val);
                        return NULL;
                    }
                }
                else if (0 == axutil_strcmp(bool_val, "false"))
                {
                    struct axis2_phase_rule *phase_rule = NULL;
                    phase_rule = axis2_handler_desc_get_rules(handler_desc, env);
                    status = axis2_phase_rule_set_first(phase_rule, env,
                        AXIS2_FALSE);
                    if (AXIS2_SUCCESS != status)
                    {
                        axis2_handler_desc_free(handler_desc, env);
                        AXIS2_FREE(env->allocator, bool_val);
                        return NULL;
                    }
                }
                AXIS2_FREE(env->allocator, bool_val);
            }
            index_i = axutil_hash_next(env, index_i);
        }

        param_qname = axutil_qname_create(env, AXIS2_PARAMETERST, NULL, NULL);
        params = axiom_element_get_children_with_qname(handler_element,
            env, param_qname, handler_node);
        axutil_qname_free(param_qname, env);
        status = axis2_desc_builder_process_params(desc_builder, env, params,
            axis2_handler_desc_get_param_container(handler_desc, env), parent);
        if (AXIS2_SUCCESS != status)
        {
            axis2_handler_desc_free(handler_desc, env);
            return NULL;
        }
    }

    status = axis2_handler_desc_set_parent(handler_desc, env, parent);
    if (AXIS2_SUCCESS != status)
    {
        axis2_handler_desc_free(handler_desc, env);
        return NULL;
    }

    return handler_desc;
}

static axis2_status_t
set_attrs_and_value(axutil_param_t *param,
    const axutil_env_t *env,
    axiom_element_t *param_element,
    axiom_node_t *param_node)
{
    axis2_status_t status = AXIS2_FAILURE;
    axutil_hash_t *attrs = NULL;
    axiom_child_element_iterator_t *childs = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, param, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, param_element, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, param_node, AXIS2_FAILURE);

    /* Setting attributes */
    attrs = axiom_element_extract_attributes(param_element, env, param_node);
    if (attrs)
    {
        axutil_hash_index_t *i = NULL;

        for (i = axutil_hash_first(attrs, env); i; i =
            axutil_hash_next(env, i))
        {
            void *v = NULL;
            axiom_attribute_t *value = NULL;
            axutil_generic_obj_t *obj = NULL;
            axutil_qname_t *attr_qname = NULL;
            axis2_char_t *attr_name = NULL;

            axutil_hash_this(i, NULL, NULL, &v);
            if (!v)
            {
                axutil_param_free(param, env);
                return AXIS2_FAILURE;
            }
            obj = axutil_generic_obj_create(env);
            if (!obj)
            {
                axutil_param_free(param, env);
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY,
                    AXIS2_FAILURE);
                return AXIS2_FAILURE;
            }
            value = (axiom_attribute_t *) v;
             axutil_generic_obj_set_value(obj, env, value);
            axutil_generic_obj_set_free_func(obj, env,
                axiom_attribute_free_void_arg);
            attr_qname = axiom_attribute_get_qname(value, env);
            attr_name = axutil_qname_to_string(attr_qname, env);
            axutil_hash_set(attrs, attr_name, AXIS2_HASH_KEY_STRING, obj);
        }
        axutil_param_set_attributes(param, env, attrs);
    }

    childs = axiom_element_get_child_elements(param_element, env, param_node);
    if (childs)
    {
        axutil_array_list_t *value_list = NULL;

        value_list = axutil_array_list_create(env, 0);
        axutil_param_set_value_list(param, env, value_list);

        while (AXIS2_TRUE == AXIOM_CHILD_ELEMENT_ITERATOR_HAS_NEXT(childs, env))
        {
            axiom_node_t *node = NULL;
            axiom_element_t *element = NULL;
            axutil_param_t *param = NULL;
            axis2_char_t *pname = NULL;

            node = AXIOM_CHILD_ELEMENT_ITERATOR_NEXT(childs, env);
            element = axiom_node_get_data_element(node, env);
            param = axutil_param_create(env, NULL, NULL);
            pname = axiom_element_get_localname(element, env);
            status = axutil_param_set_name(param, env, pname);
            if (AXIS2_SUCCESS != status)
            {
                axutil_param_free(param, env);
                return status;
            }
            axutil_param_set_param_type(param, env, AXIS2_DOM_PARAM);
            set_attrs_and_value(param, env, element, node);
            axutil_array_list_add(value_list, env, param);
        }
    }
    else
    {
        axis2_char_t *para_test_value = NULL;
        axis2_char_t *temp = NULL;

        temp = axiom_element_get_text(
            param_element, env, param_node);
        para_test_value = axutil_strdup(env, temp);
        status = axutil_param_set_value(param, env, para_test_value);
        if (AXIS2_SUCCESS != status)
        {
            axutil_param_free(param, env);
            AXIS2_FREE(env->allocator, para_test_value);
            return status;
        }
        axutil_param_set_param_type(param, env, AXIS2_TEXT_PARAM);
    }
    return AXIS2_SUCCESS;
}

/**
 * Populate the Axis2 Operation with details from the actionMapping,
 * outputActionMapping and faultActionMapping elements from the operation
 * element.
 *
 * @param operation
 * @param op_desc
 */
AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_desc_builder_process_action_mappings(axis2_desc_builder_t *desc_builder,
    const axutil_env_t *env,
    axiom_node_t *op_node,
    axis2_op_t *op_desc)
{
    axiom_element_t *op_element = NULL;
    axutil_qname_t *qname = NULL;
    axiom_children_qname_iterator_t *action_mappings = NULL;
    axutil_array_list_t *mapping_list = axutil_array_list_create(env, 0);
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, op_desc, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, op_desc, AXIS2_FAILURE);

    op_element = axiom_node_get_data_element(op_node, env);
    qname = axutil_qname_create(env, AXIS2_ACTION_MAPPING, NULL, NULL);
    if(op_element)
    {
        action_mappings = axiom_element_get_children_with_qname(op_element, env, 
            qname,op_node);
    }

    axutil_qname_free(qname, env);
    qname = NULL;
    if(!action_mappings)
    {
        if (mapping_list)
        {
            axutil_array_list_free(mapping_list, env);
            mapping_list = NULL;
        }
        return AXIS2_SUCCESS;
    }
    while (axiom_children_qname_iterator_has_next(action_mappings, env))
    {
        axiom_element_t *mapping_element = NULL;
        axiom_node_t *mapping_node = NULL;
        axis2_char_t *input_action_string = NULL;
        axis2_char_t *temp_str = NULL;

        /* This is to check whether some one has locked the parmter at the top
         * level
         */
        mapping_node = (axiom_node_t *)
            axiom_children_qname_iterator_next(action_mappings, env);
        mapping_element = axiom_node_get_data_element(mapping_node, env);
        temp_str = axiom_element_get_text(mapping_element, env, 
            mapping_node);
        input_action_string = axutil_strtrim(env, temp_str, NULL);
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "Input action mapping found %s", 
            input_action_string);
        if(0 != axutil_strcmp("", input_action_string))
        {
            axutil_array_list_add(mapping_list, env, input_action_string);
        }
        else
        {
            AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "Zero length " \
                "input_action_string found. Not added to the mapping list");
        }
    }
    axis2_op_set_wsamapping_list(op_desc, env, mapping_list); 
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_desc_builder_process_params(axis2_desc_builder_t *desc_builder,
    const axutil_env_t *env,
    axiom_children_qname_iterator_t *params,
    axutil_param_container_t *param_container,
    axutil_param_container_t *parent)
{
    axis2_status_t status = AXIS2_FAILURE;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, params, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, param_container, AXIS2_FAILURE);

    while (AXIS2_FALSE != axiom_children_qname_iterator_has_next(params, env))
    {
        axiom_element_t *param_element = NULL;
        axiom_node_t *param_node = NULL;
        axutil_param_t *param = NULL;
        axutil_param_t *parent_para = NULL;
        axiom_attribute_t *para_name = NULL;
        axiom_attribute_t *para_locked = NULL;
        axutil_qname_t *att_locked = NULL;
        axutil_qname_t *att_qname = NULL;
        axis2_char_t *pname = NULL;

        /* This is to check whether some one has locked the parmter at the top
         * level
         */
        param_node = (axiom_node_t *)
            axiom_children_qname_iterator_next(params, env);
        param_element = axiom_node_get_data_element(param_node, env);
        param = axutil_param_create(env, NULL, NULL);

        /* Setting paramter name */
        att_qname = axutil_qname_create(env, AXIS2_ATTNAME, NULL, NULL);
        para_name = axiom_element_get_attribute(param_element, env,
            att_qname);
        axutil_qname_free(att_qname, env);
        if (!para_name)
        {
            axutil_param_free(param, env);
            return AXIS2_FAILURE;
        }
        pname = axiom_attribute_get_value(para_name, env);
        status = axutil_param_set_name(param, env, pname);
        if (AXIS2_SUCCESS != status)
        {
            axutil_param_free(param, env);
            return status;
        }

        /* Setting paramter Value (the chiled elemnt of the paramter) */
        set_attrs_and_value(param, env, param_element, param_node);

        /* Setting locking attrib */
        att_locked = axutil_qname_create(env, AXIS2_ATTLOCKED, NULL, NULL);
        para_locked = axiom_element_get_attribute(param_element, env,
            att_locked);
        axutil_qname_free(att_locked, env);
        if (parent)
        {
            axis2_char_t *param_name = NULL;

            param_name = axutil_param_get_name(param, env);
            parent_para = axutil_param_container_get_param(parent, env,
                param_name);
        }
        if (para_locked)
        {
            axis2_char_t *locked_value = NULL;
            locked_value = axiom_attribute_get_value(para_locked, env);
            if (0 == axutil_strcmp("true", locked_value))
            {
                axis2_char_t *param_name = NULL;
                axis2_bool_t is_param_locked = AXIS2_FALSE;
                /*if the parameter is locked at some level parameter value replace
                 * by that   
                 */
                param_name = axutil_param_get_name(param, env);
                is_param_locked = axutil_param_container_is_param_locked(parent,
                    env, param_name);
                if (parent && AXIS2_TRUE == is_param_locked)
                {
                    axutil_param_free(param, env);
                    AXIS2_ERROR_SET(env->error,
                        AXIS2_ERROR_CONFIG_NOT_FOUND, AXIS2_FAILURE);
                    return AXIS2_FAILURE;
                }
                else
                {
                    axutil_param_set_locked(param, env, AXIS2_TRUE);
                }
            }
            else
            {
                axutil_param_set_locked(param, env, AXIS2_FALSE);
            }
        }


        if (parent)
        {
            axis2_char_t *name = NULL;
            axis2_bool_t bvalue = AXIS2_FALSE;

            name = axutil_param_get_name(param, env);
            bvalue = axutil_param_container_is_param_locked(parent, env, name);
            if (parent_para || AXIS2_FALSE == bvalue)
            {
                status = axutil_param_container_add_param(param_container, env,
                    param);
                if (AXIS2_SUCCESS != status)
                {
                    axutil_param_free(param, env);
                    return status;
                }
            }
        }
        else
        {
            status = axutil_param_container_add_param(param_container, env,
                param);
            if (AXIS2_SUCCESS != status)
            {
                axutil_param_free(param, env);
                return status;
            }
        }
    }
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_desc_builder_process_op_module_refs(axis2_desc_builder_t *desc_builder,
    const axutil_env_t *env,
    axiom_children_qname_iterator_t *module_refs,
    axis2_op_t *op)
{
    axiom_element_t *moduleref = NULL;
    axiom_attribute_t *module_ref_attrib = NULL;
    axutil_qname_t *qref = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, op, AXIS2_FAILURE);

    while (module_refs && AXIS2_TRUE == axiom_children_qname_iterator_has_next(module_refs,
        env))
    {
        moduleref = (axiom_element_t *)
            axiom_children_qname_iterator_next(module_refs, env);
        qref = axutil_qname_create(env, AXIS2_REF, NULL, NULL);
        module_ref_attrib = axiom_element_get_attribute(moduleref, env, qref);
        axutil_qname_free(qref, env);
        if (module_ref_attrib)
        {
            axis2_char_t *ref_name = NULL;
            axutil_qname_t *ref_qname = NULL;
            axis2_module_desc_t *module_desc = NULL;

            ref_name = axiom_attribute_get_value(module_ref_attrib, env);
            ref_qname = axutil_qname_create(env, ref_name, NULL, NULL);
            module_desc = axis2_dep_engine_get_module(desc_builder->engine, env,
                ref_qname);
            if (! module_desc)
            {
                axutil_qname_free(ref_qname, env);
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_MODULE_NOT_FOUND,
                    AXIS2_FAILURE);
                return AXIS2_FAILURE;
            }
            else
            {
                status = axis2_op_add_module_qname(op, env, ref_qname);
                axutil_qname_free(ref_qname, env);
                if (AXIS2_SUCCESS != status)
                {
                    AXIS2_ERROR_SET(env->error, AXIS2_ERROR_MODULE_NOT_FOUND,
                        AXIS2_FAILURE);
                    return AXIS2_FAILURE;
                }
            }
        }
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_msg_recv_t *AXIS2_CALL
axis2_desc_builder_load_msg_recv(axis2_desc_builder_t *desc_builder,
    const axutil_env_t *env,
    struct axiom_element *recv_element)
{
    axiom_attribute_t *recv_name = NULL;
    axis2_char_t *class_name = NULL;
    axis2_msg_recv_t *msg_recv = NULL;
    axutil_qname_t *class_qname = NULL;
    axutil_param_t *impl_info_param = NULL;
    axutil_dll_desc_t *dll_desc = NULL;
    axis2_char_t *repos_name = NULL;
    axis2_char_t *dll_name = NULL;
    axis2_char_t *temp_path = NULL;
    axis2_char_t *temp_path2 = NULL;
    axis2_char_t *temp_path3 = NULL;
    axis2_conf_t *conf = NULL;
    axis2_char_t *msg_recv_dll_name = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, recv_element, NULL);

    class_qname = axutil_qname_create(env, AXIS2_CLASSNAME, NULL, NULL);
    recv_name = axiom_element_get_attribute(recv_element, env, class_qname);
    axutil_qname_free(class_qname, env);
    class_name = axiom_attribute_get_value(recv_name, env);

    conf = axis2_dep_engine_get_axis_conf(desc_builder->engine, env);
    if (!conf)
    {
        return NULL;
    }
    impl_info_param =  axis2_conf_get_param(conf, env, class_name);

    if (!impl_info_param)
    {
        dll_desc = axutil_dll_desc_create(env);
        msg_recv_dll_name =
             axutil_dll_desc_create_platform_specific_dll_name(dll_desc, env,
                 class_name);
        repos_name = axis2_dep_engine_get_repos_path(desc_builder->engine, env);
        temp_path = axutil_stracat(env, repos_name, AXIS2_PATH_SEP_STR);
        temp_path2 = axutil_stracat(env, temp_path, AXIS2_LIB_FOLDER);
        temp_path3 = axutil_stracat(env, temp_path2, AXIS2_PATH_SEP_STR);
        dll_name = axutil_stracat(env, temp_path3, msg_recv_dll_name);
        AXIS2_FREE(env->allocator, temp_path);
        AXIS2_FREE(env->allocator, temp_path2);
        AXIS2_FREE(env->allocator, temp_path3);
         axutil_dll_desc_set_name(dll_desc, env, dll_name);
        AXIS2_FREE(env->allocator, dll_name);
         axutil_dll_desc_set_type(dll_desc, env, AXIS2_MSG_RECV_DLL);
        impl_info_param = axutil_param_create(env, class_name, NULL);
        axutil_param_set_value(impl_info_param, env, dll_desc);
        axutil_param_set_value_free(impl_info_param, env, axutil_dll_desc_free_void_arg);
        /* set the impl_info_param(which contain dll_desc as value) so that
         * loaded msg_recv loader lib can be re-used in future
         */
         axis2_conf_add_param(conf, env, impl_info_param);
    }

    axutil_class_loader_init(env);
    msg_recv = (axis2_msg_recv_t *) axutil_class_loader_create_dll(env,
        impl_info_param);
    return msg_recv;
}

AXIS2_EXTERN struct axis2_msg_recv *AXIS2_CALL
axis2_desc_builder_load_default_msg_recv(const axutil_env_t *env)
{
    axis2_msg_recv_t *msg_recv = NULL;

    msg_recv = axis2_raw_xml_in_out_msg_recv_create(env);
    return msg_recv;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
axis2_desc_builder_get_short_file_name(const axis2_desc_builder_t *desc_builder,
    const axutil_env_t *env,
    axis2_char_t *file_name)
{
    const axis2_char_t *separator = NULL;
    axis2_char_t *value = NULL;
    axis2_char_t *file_name_l = NULL;
    axis2_char_t *short_name = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, file_name, NULL);

    file_name_l = axutil_strdup(env, file_name);
    if (!file_name_l)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    separator = ".";

    value = axutil_strstr(file_name_l, separator);

    value[0] = AXIS2_EOLN;
    short_name = file_name_l;

    return short_name;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
axis2_desc_builder_get_file_name_without_prefix(const axis2_desc_builder_t *desc_builder,
    const axutil_env_t *env,
    axis2_char_t *short_file_name)
{
    axis2_char_t *file_name_l = NULL;
    axis2_char_t *short_name = NULL;
    int len = 0;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, short_file_name, NULL);
    file_name_l = axutil_strdup(env, short_file_name);
    if (!file_name_l)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    len = axutil_strlen(AXIS2_LIB_PREFIX);
    short_name = &file_name_l[len];
    return short_name;

}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
axis2_desc_builder_get_value(const axis2_desc_builder_t *desc_builder,
    const axutil_env_t *env,
    axis2_char_t *in)
{
    const axis2_char_t *separator = ":";
    axis2_char_t *value = NULL;
    axis2_char_t *in_l = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, in, NULL);

    in_l = axutil_strdup(env, in);
    if (!in_l)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    value = axutil_strstr(in_l, separator);
    value = value + 1;

    return value;
}

AXIS2_EXTERN struct axis2_dep_engine *AXIS2_CALL
axis2_desc_builder_get_dep_engine(const axis2_desc_builder_t *desc_builder,
    const axutil_env_t *env)
{
    return desc_builder->engine;
}
