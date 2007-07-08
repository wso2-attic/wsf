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

#include <axiom_children_iterator.h>

struct axiom_children_iterator
{
    axiom_node_t *first_child;
    axiom_node_t *current_child;
    axiom_node_t *last_child;
    axis2_bool_t next_called;
    axis2_bool_t remove_called;
};

AXIS2_EXTERN  axiom_children_iterator_t * AXIS2_CALL
axiom_children_iterator_create(const axutil_env_t *env,
    axiom_node_t *current_child)
{
    axiom_children_iterator_t *iterator = NULL;
    AXIS2_ENV_CHECK(env, NULL);

    iterator = (axiom_children_iterator_t *)AXIS2_MALLOC(
        env->allocator, sizeof(axiom_children_iterator_t));

    if (!iterator)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    iterator->current_child = NULL;
    iterator->last_child    = NULL;
    iterator->first_child    = NULL;

    iterator->next_called = AXIS2_FALSE;
    iterator->remove_called = AXIS2_FALSE;

    iterator->first_child = current_child;
    iterator->current_child = current_child;

    return iterator;
}


AXIS2_EXTERN void AXIS2_CALL
axiom_children_iterator_free(axiom_children_iterator_t *iterator,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    AXIS2_FREE(env->allocator, iterator);
    return;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_children_iterator_remove(axiom_children_iterator_t *iterator,
    const axutil_env_t *env)
{
    axiom_node_t *om_node = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (!(iterator->next_called))
    {
        AXIS2_ERROR_SET(env->error, 
            AXIS2_ERROR_ITERATOR_NEXT_METHOD_HAS_NOT_YET_BEEN_CALLED, 
            AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    if (iterator->remove_called)
    {
        AXIS2_ERROR_SET(env->error,
            AXIS2_ERROR_ITERATOR_REMOVE_HAS_ALREADY_BEING_CALLED, 
            AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    iterator->remove_called = AXIS2_TRUE;

    if (!(iterator->last_child))
    {
        return AXIS2_FAILURE;
    }
    om_node = axiom_node_detach(iterator->last_child, env);
    if (om_node)
    {
        axiom_node_free_tree(om_node, env);
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axiom_children_iterator_has_next(axiom_children_iterator_t *iterator,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    return (iterator->current_child) ? AXIS2_TRUE : AXIS2_FALSE;
}

AXIS2_EXTERN axiom_node_t *AXIS2_CALL
axiom_children_iterator_next(axiom_children_iterator_t *iterator,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    iterator->next_called = AXIS2_TRUE;
    iterator->remove_called = AXIS2_FALSE;
    if (iterator->current_child)
    {
        iterator->last_child = iterator->current_child;
        iterator->current_child = axiom_node_get_next_sibling(
            iterator->current_child, env);
        return iterator->last_child;
    }
    return NULL;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_children_iterator_reset(axiom_children_iterator_t *iterator,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    iterator->current_child = iterator->first_child;
    return AXIS2_SUCCESS;
}


