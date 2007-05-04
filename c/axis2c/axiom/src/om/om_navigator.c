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

#include <axiom_navigator.h>

static void
axiom_navigator_update_next_node(axiom_navigator_t *om_navigator,
    const axutil_env_t *env);

struct axiom_navigator
{
    axiom_node_t *node;

    axis2_bool_t visited;

    axiom_node_t *next;

    axiom_node_t *root;

    axis2_bool_t backtracked;

    axis2_bool_t end;

    axis2_bool_t start;

};

AXIS2_EXTERN axiom_navigator_t *AXIS2_CALL
axiom_navigator_create(const axutil_env_t *env,
    axiom_node_t *om_node)
{
    axiom_navigator_t *om_navigator = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, om_node, NULL);

    om_navigator =
        (axiom_navigator_t *)AXIS2_MALLOC(env->allocator, sizeof(axiom_navigator_t));
    if (!om_navigator)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    om_navigator->node = NULL;
    om_navigator->visited = AXIS2_FALSE;
    om_navigator->next = NULL;
    om_navigator->root = NULL;
    om_navigator->end = AXIS2_FALSE;
    om_navigator->start = AXIS2_TRUE;
    om_navigator->backtracked = AXIS2_FALSE;

    om_navigator->next = om_node;
    om_navigator->root = om_node;

    return om_navigator;
}


AXIS2_EXTERN void AXIS2_CALL
axiom_navigator_free(axiom_navigator_t *om_navigator,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env , AXIS2_FAILURE);
    AXIS2_FREE(env->allocator, om_navigator);
    return;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axiom_navigator_is_navigable(axiom_navigator_t *om_navigator,
    const axutil_env_t *env)
{
    if (AXIS2_TRUE == om_navigator->end)
    {
        return AXIS2_FALSE;
    }
    else
    {
        if (om_navigator->next)
        {
            return AXIS2_TRUE;
        }
    }
    return AXIS2_FALSE;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axiom_navigator_is_completed(axiom_navigator_t *om_navigator,
    const axutil_env_t *env)
{
    return om_navigator->end;
}


AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axiom_navigator_visited(axiom_navigator_t *om_navigator,
    const axutil_env_t *env)
{
    return om_navigator->visited;
}

AXIS2_EXTERN axiom_node_t *AXIS2_CALL
axiom_navigator_next(axiom_navigator_t *om_navigator,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    if (! om_navigator->next)
    {
        return NULL;
    }

    om_navigator->node = om_navigator->next;
    om_navigator->visited = om_navigator->backtracked;
    om_navigator->backtracked = AXIS2_FALSE;

    axiom_navigator_update_next_node(om_navigator, env);

    /** set the starting and ending flags */
    if (om_navigator->root == om_navigator->next)
    {
        if (!(om_navigator->start))
        {
            om_navigator->end = AXIS2_TRUE;
        }
        else
        {
            om_navigator->start = AXIS2_FALSE;
        }
    }
    return om_navigator->node;
}

/** this method encapsulate searching logic */
static void
axiom_navigator_update_next_node(axiom_navigator_t *om_navigator,
    const axutil_env_t *env)
{
    if (!om_navigator)
    {
        return;
    }

    if (!om_navigator->next)
    {
        return;
    }

    if ((AXIOM_ELEMENT == axiom_node_get_node_type(om_navigator->next, env)) &&
        !(om_navigator->visited))
    {
        if (axiom_node_get_first_child(om_navigator->next, env))
        {
            om_navigator->next = axiom_node_get_first_child(om_navigator->next, env);
        }
        else if (AXIS2_TRUE == axiom_node_is_complete(om_navigator->next, env))
        {
            om_navigator->backtracked = AXIS2_TRUE;
        }
        else
        {
            om_navigator->next = NULL;
        }
    }
    else
    {
        axiom_node_t  *parent = NULL;
        axiom_node_t *next_sibling = NULL;

        next_sibling = axiom_node_get_next_sibling(om_navigator->next, env);

        parent = axiom_node_get_parent(om_navigator->next, env);

        if (next_sibling)
        {
            om_navigator->next = next_sibling;
        }
        else if ((parent) && axiom_node_is_complete(parent, env))
        {
            om_navigator->next = parent;
            om_navigator->backtracked = AXIS2_TRUE;
        }
        else
        {
            om_navigator->next = NULL;
        }
    }
}

