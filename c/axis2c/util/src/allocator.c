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

#include <axutil_allocator.h>
#include <axutil_utils.h>
#include <stdlib.h>

void *AXIS2_CALL
axutil_allocator_malloc_impl(axutil_allocator_t *allocator, size_t size);

void *AXIS2_CALL
axutil_allocator_realloc_impl(axutil_allocator_t *allocator, void *ptr, size_t size);

void AXIS2_CALL
axutil_allocator_free_impl(axutil_allocator_t *allocator, void *ptr);


AXIS2_EXTERN axutil_allocator_t * AXIS2_CALL
axutil_allocator_init(axutil_allocator_t *allocator)
{
    if (allocator)
        return allocator;

    else
    {
        allocator = (axutil_allocator_t *) malloc(sizeof(axutil_allocator_t));
        if (allocator)
        {
            allocator->malloc_fn = axutil_allocator_malloc_impl;
            allocator->realloc = axutil_allocator_realloc_impl;
            allocator->free_fn = axutil_allocator_free_impl;
            return allocator;
        }
    }
    return NULL;
}

AXIS2_EXTERN void AXIS2_CALL
axutil_allocator_free(axutil_allocator_t *allocator)
{
    if (allocator)
    {
        allocator->free_fn(allocator, allocator);
    }
    return;
}

void *AXIS2_CALL
axutil_allocator_malloc_impl(axutil_allocator_t *allocator, size_t size)
{
    return malloc(size);
}

void *AXIS2_CALL
axutil_allocator_realloc_impl(axutil_allocator_t *allocator, void *ptr, size_t size)
{
    return realloc(ptr, size);
}

void AXIS2_CALL
axutil_allocator_free_impl(axutil_allocator_t *allocator, void *ptr)
{
    free(ptr);
}


AXIS2_EXTERN void AXIS2_CALL 
axutil_allocator_switch_to_global_pool(axutil_allocator_t *allocator)
{   
    if (!allocator)
        return;
    allocator->current_pool = allocator->global_pool;
    return;
}

AXIS2_EXTERN void AXIS2_CALL 
axutil_allocator_switch_to_local_pool(axutil_allocator_t *allocator)
{
    if (!allocator)
        return;
    allocator->current_pool = allocator->local_pool;
    return;
}

