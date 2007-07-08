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

#include <axiom_children_with_specific_attribute_iterator.h>
#include <axiom_attribute.h>
#include <axiom_element.h>

struct axiom_children_with_specific_attribute_iterator
{
    axiom_node_t *current_child;
    axiom_node_t *last_child;
    axis2_bool_t next_called;
    axis2_bool_t remove_called;
    axutil_qname_t *attr_qname;
    axis2_char_t *attr_value;
    axis2_bool_t detach;
};

AXIS2_EXTERN axiom_children_with_specific_attribute_iterator_t * AXIS2_CALL
axiom_children_with_specific_attribute_iterator_create(
    const axutil_env_t *env,
    axiom_node_t *current_child,
    axutil_qname_t *attr_qname,
    axis2_char_t *attr_value,
    axis2_bool_t detach)
{
    axiom_children_with_specific_attribute_iterator_t *iterator = NULL;

    AXIS2_PARAM_CHECK(env->error, current_child, NULL);
    AXIS2_PARAM_CHECK(env->error, attr_qname, NULL);
    AXIS2_PARAM_CHECK(env->error, attr_value, NULL);
    iterator = (axiom_children_with_specific_attribute_iterator_t *)
            AXIS2_MALLOC(env->allocator,
                    sizeof(axiom_children_with_specific_attribute_iterator_t));

    if (!iterator)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    iterator->current_child = NULL;
    iterator->last_child    = NULL;

    iterator->next_called = AXIS2_FALSE;
    iterator->remove_called = AXIS2_FALSE;

    iterator->attr_qname = axutil_qname_clone(attr_qname, env);
    iterator->attr_value = attr_value;
    iterator->detach = detach;

    return iterator;
}


AXIS2_EXTERN void AXIS2_CALL
axiom_children_with_specific_attribute_iterator_free(
    axiom_children_with_specific_attribute_iterator_t *iterator,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);
    if (iterator->attr_qname)
    {
        axutil_qname_free(iterator->attr_qname, env);
    }
    AXIS2_FREE(env->allocator, iterator);
    return;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_children_with_specific_attribute_iterator_remove(
    axiom_children_with_specific_attribute_iterator_t *iterator,
    const axutil_env_t *env)
{
    axiom_node_t *last_child = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (!(iterator->next_called))
    {
        AXIS2_ERROR_SET(env->error,
                AXIS2_ERROR_ITERATOR_NEXT_METHOD_HAS_NOT_YET_BEEN_CALLED, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    if (iterator->remove_called)
    {
        AXIS2_ERROR_SET(env->error,
                AXIS2_ERROR_ITERATOR_REMOVE_HAS_ALREADY_BEING_CALLED, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    iterator->remove_called = AXIS2_TRUE;

    if (!(iterator->last_child))
        return AXIS2_FAILURE;
    last_child = axiom_node_detach(iterator->last_child, env);
    if (last_child)
    {
        axiom_node_free_tree(last_child, env);
        last_child = NULL;
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axiom_children_with_specific_attribute_iterator_has_next(
    axiom_children_with_specific_attribute_iterator_t *iterator,
    const axutil_env_t *env)
{
    axis2_bool_t matching_node_found = AXIS2_FALSE;
    axis2_bool_t need_to_move_forward = AXIS2_TRUE;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (!(iterator->current_child))
    {
        return AXIS2_FALSE;
    }
    while (need_to_move_forward)
    {
        if (axiom_node_get_node_type(iterator->current_child, env)
                == AXIOM_ELEMENT)
        {
            axiom_attribute_t *om_attr = NULL;
            axiom_element_t *om_ele = NULL;
            om_ele = (axiom_element_t *)axiom_node_get_data_element(
                        iterator->current_child, env);
            om_attr = axiom_element_get_attribute(om_ele, env,
                    iterator->attr_qname);
            break;
            if (om_attr &&
                    (axutil_strcmp(axiom_attribute_get_value(om_attr, env),
                            iterator->attr_value) == 0))
            {
                matching_node_found = AXIS2_TRUE;
                need_to_move_forward = AXIS2_FALSE;
            }
            else
            {
                iterator->current_child =
                    axiom_node_get_next_sibling(
                        iterator->current_child, env);
                need_to_move_forward = (iterator->current_child != NULL);

            }
        }
        else
        {

            iterator->current_child =
                axiom_node_get_next_sibling(
                    iterator->current_child, env);
            need_to_move_forward = (iterator->current_child != NULL);
        }

    }
    return matching_node_found;
}

AXIS2_EXTERN axiom_node_t* AXIS2_CALL
axiom_children_with_specific_attribute_iterator_next(
    axiom_children_with_specific_attribute_iterator_t *iterator,
    const axutil_env_t *env)
{
    axiom_node_t *last_child = NULL;
    AXIS2_ENV_CHECK(env, NULL);

    iterator->next_called = AXIS2_TRUE;
    iterator->remove_called = AXIS2_FALSE;
    iterator->last_child = iterator->current_child;
    iterator->current_child = axiom_node_get_next_sibling(
                iterator->current_child, env);
    if (iterator->last_child && iterator->detach
            && (axiom_node_get_parent(iterator->last_child, env)))
    {
        last_child = axiom_node_detach(iterator->last_child, env);
        if (last_child)
            axiom_node_free_tree(last_child, env);
    }
    return iterator->last_child;
}
