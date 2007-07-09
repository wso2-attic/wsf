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

#include <axutil_stack.h>
#include <axutil_utils.h>
#include <axutil_env.h>
#include <stdlib.h>
#include <string.h>

#define AXIS2_STACK_DEFAULT_CAPACITY 10

struct axutil_stack
{
    void **data;
    /** current number of elements */
    int size;
    /** total capacity */
    int capacity;
    axis2_bool_t is_empty_stack;
};

AXIS2_EXTERN axutil_stack_t * AXIS2_CALL
axutil_stack_create(const axutil_env_t *env)
{
    axutil_stack_t *stack = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    stack = (axutil_stack_t*)AXIS2_MALLOC(env->allocator,
        sizeof(axutil_stack_t));

    if (!stack)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    stack->data = NULL;
    stack->size = 0;
    stack->capacity = AXIS2_STACK_DEFAULT_CAPACITY;
    stack->is_empty_stack = AXIS2_TRUE;

    stack->data = AXIS2_MALLOC(env->allocator, sizeof(void*) *
        AXIS2_STACK_DEFAULT_CAPACITY);
    if (!stack->data)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        axutil_stack_free(stack , env);
        return NULL;
    }

    return stack;
}

void AXIS2_CALL
axutil_stack_free(axutil_stack_t *stack,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (stack->data)
    {
        AXIS2_FREE(env->allocator, stack->data);
    }
    AXIS2_FREE(env->allocator, stack);
    return;
}

void* AXIS2_CALL
axutil_stack_pop(axutil_stack_t *stack,
    const axutil_env_t *env)
{
    void *value = NULL;
    AXIS2_ENV_CHECK(env, NULL);

    if (stack->is_empty_stack == AXIS2_TRUE ||
        stack->size == 0)
    {
        return NULL;
    }
    if (stack->size > 0)
    {
        value = stack->data[stack->size -1 ];
        stack->data[stack->size-1] = NULL;
        stack->size--;
        if (stack->size == 0)
        {
            stack->is_empty_stack = AXIS2_TRUE;
        }
    }
    return value;
}

axis2_status_t AXIS2_CALL
axutil_stack_push(axutil_stack_t *stack,
    const axutil_env_t *env,
    void* value)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, value, AXIS2_FAILURE);

    if ((stack->size  < stack->capacity) && (stack->capacity > 0))
    {
        stack->data[stack->size++] = value;
    }
    else
    {
        void **new_data = NULL;

        int new_capacity = stack->capacity + AXIS2_STACK_DEFAULT_CAPACITY;

        new_data = AXIS2_MALLOC(env->allocator, sizeof(void*) * new_capacity);
        if (!new_data)
        {
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            return AXIS2_FAILURE;
        }
        memset(new_data, 0, sizeof(void*)*new_capacity);
        memcpy(new_data, stack->data, sizeof(void*) *(stack->capacity));
        stack->capacity = new_capacity;

        AXIS2_FREE(env->allocator, stack->data);
        stack->data = new_data;

        stack->data[stack->size++] = value;
    }
    stack->is_empty_stack = AXIS2_FALSE;
    return AXIS2_SUCCESS;
}

int AXIS2_CALL
axutil_stack_size(axutil_stack_t *stack,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    return stack->size;
}

void * AXIS2_CALL
axutil_stack_get(axutil_stack_t *stack,
    const axutil_env_t *env)
{
    if (stack->size > 0)
    {
        return stack->data[stack->size-1];
    }
    return NULL;
}

void* AXIS2_CALL
axutil_stack_get_at(axutil_stack_t *stack,
    const axutil_env_t *env,
    int i)
{
    if ((stack->size == 0) || (i < 0) || (i >= stack->size))
    {
        return NULL;
    }
    return stack->data[i];
}
