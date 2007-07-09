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

#include <axiom_child_element_iterator.h>

struct axiom_child_element_iterator
{
    axiom_node_t *current_child;
    axiom_node_t *last_child;
    axis2_bool_t next_called;
    axis2_bool_t remove_called;
};

AXIS2_EXTERN  axiom_child_element_iterator_t * AXIS2_CALL
axiom_child_element_iterator_create(const axutil_env_t *env,
        axiom_node_t *current_child)
{
    axiom_child_element_iterator_t *iterator = NULL;
    AXIS2_ENV_CHECK(env, NULL);

    iterator = (axiom_child_element_iterator_t *)AXIS2_MALLOC(
                env->allocator,
                sizeof(axiom_child_element_iterator_t));

    if (!iterator)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    iterator->current_child = current_child;
    iterator->last_child    = NULL;

    iterator->next_called = AXIS2_FALSE;
    iterator->remove_called = AXIS2_FALSE;

    return iterator;
}


AXIS2_EXTERN  void AXIS2_CALL
axiom_child_element_iterator_free
(void *iterator,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_FREE(env->allocator, iterator);
    return;
}

AXIS2_EXTERN  axis2_status_t AXIS2_CALL
axiom_child_element_iterator_remove
(axiom_child_element_iterator_t *iterator,
        const axutil_env_t *env)
{
    axiom_node_t *last_child = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (!(iterator->next_called))
        return AXIS2_FAILURE;
    if (iterator->remove_called)
        return AXIS2_FAILURE;

    iterator->remove_called = AXIS2_TRUE;

    if (!(iterator->last_child))
        return AXIS2_FAILURE;
    last_child = axiom_node_detach(iterator->last_child, env);
    axiom_node_free_tree(last_child, env);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN  axis2_bool_t AXIS2_CALL
axiom_child_element_iterator_has_next
(axiom_child_element_iterator_t *iterator,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    return (iterator->current_child) ? AXIS2_TRUE : AXIS2_FALSE;
}

AXIS2_EXTERN  axiom_node_t* AXIS2_CALL
axiom_child_element_iterator_next
(axiom_child_element_iterator_t *iterator,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    iterator->next_called = AXIS2_TRUE;
    iterator->remove_called = AXIS2_FALSE;
    if (iterator->current_child)
    {
        iterator->last_child = iterator->current_child;
        do
        {
            iterator->current_child = axiom_node_get_next_sibling(
                        iterator->current_child, env);

        }
        while (iterator->current_child &&
                (axiom_node_get_node_type(iterator->current_child, env)
                        != AXIOM_ELEMENT));


        return iterator->last_child;
    }
    return NULL;
}
