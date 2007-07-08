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

#ifndef AXUTIL_ARRAY_LIST_H
#define AXUTIL_ARRAY_LIST_H

/**
 * @defgroup axutil_array_list array list
 * @ingroup axis2_util
 * Description.
 * @{
 */

/**
 * @file axutil_array_list.h
 * @brief Axis2 array_list interface
 */

#include <axutil_utils_defines.h>
#include <axutil_env.h>

#ifdef __cplusplus
extern "C"
{
#endif

    static const int AXIS2_ARRAY_LIST_DEFAULT_CAPACITY = 16;

    /**
     * Array List struct
     */
    typedef struct axutil_array_list axutil_array_list_t;

    /**
     * Constructs a new array list with the supplied initial capacity.
     * If capacity is invalid (<= 0) then default capacity is used
     * @param env pointer to environment struct
     * @param capacity initial capacity of this array_list
     */
    AXIS2_EXTERN axutil_array_list_t* AXIS2_CALL axutil_array_list_create(
        const axutil_env_t *env,
        int capacity);

    /**
     * Free array passed as void pointer.
     * @param array_list pointer to array list
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN void AXIS2_CALL
    axutil_array_list_free_void_arg(
        void *array_list,
        const axutil_env_t *env);

    /**
     * Guarantees that this list will have at least enough capacity to
     * hold min_capacity elements. This implementation will grow the list to
     * max(current * 2, min_capacity)
     * @param array_list pointer to array_list
     * @param env pointer to environment struct
     * @param min_capacity the minimum guaranteed capacity
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL 
    axutil_array_list_ensure_capacity(
        struct axutil_array_list *array_list,
        const axutil_env_t *env,
        int min_capacity);

    /**
     * Returns the number of elements in this list.
     * @param array_list pointer to array list
     * @param env pointer to environment struct
     * @return the list size
     */
    AXIS2_EXTERN int AXIS2_CALL 
    axutil_array_list_size(
        struct axutil_array_list *array_list,
        const axutil_env_t *env);

    /**
     * Checks if the list is empty.
     * @param array_list pointer to array list
     * @param env pointer to environment struct
     * @return true if there are no elements, else false
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL 
    axutil_array_list_is_empty(
        struct axutil_array_list *array_list,
        const axutil_env_t *env);

    /**
     * Returns true iff element is in this array_list.
     * @param array_list pointer to array list
     * @param env pointer to environment struct
     * @param e the element whose inclusion in the List is being tested
     * @return true if the list contains e
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL 
    axutil_array_list_contains(
        struct axutil_array_list *array_list,
        const axutil_env_t *env,
        void *e);

    /**
     * Returns the lowest index at which element appears in this List, or
     * -1 if it does not appear. This looks for the pointer value equality only, 
     * does not look into pointer content
     * @param array_list pointer to array list
     * @param env pointer to environment struct
     * @param e the element whose inclusion in the List is being tested
     * @return the index where e was found
     */
    AXIS2_EXTERN int AXIS2_CALL 
    axutil_array_list_index_of(
        struct axutil_array_list *array_list,
        const axutil_env_t *env,
        void *e);

    /**
     * Retrieves the element at the user-supplied index.
     * @param array_list pointer to array list
     * @param env pointer to environment struct
     * @param index the index of the element we are fetching
     * @return element at the given index
     */
    AXIS2_EXTERN void* AXIS2_CALL 
    axutil_array_list_get(struct axutil_array_list *array_list,
        const axutil_env_t *env,
        int index);

    /**
     * Sets the element at the specified index.  The new element, e,
     * can be an object of any type or null.
     * @param array_list pointer to array list
     * @param env pointer to environment struct
     * @param index the index at which the element is being set
     * @param e the element to be set
     * @return the element previously at the specified index
     */
    AXIS2_EXTERN void* AXIS2_CALL 
    axutil_array_list_set(
        struct axutil_array_list *array_list,
        const axutil_env_t *env,
        int index,
        void* e);

    /**
     * Appends the supplied element to the end of this list.
     * The element, e, can be a pointer of any type or NULL.
     * @param array_list pointer to array list
     * @param env pointer to environment struct
     * @param e the element to be appended to this list
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL 
    axutil_array_list_add(
        struct axutil_array_list *array_list,
        const axutil_env_t *env,
        const void* e);

    /**
     * Adds the supplied element at the specified index, shifting all
     * elements currently at that index or higher one to the right.
     * The element, e, can be a pointer of any type or NULL.
     * @param array_list pointer to array list
     * @param env pointer to environment struct
     * @param index the index at which the element is being added
     * @param e the item being added
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL 
    axutil_array_list_add_at(
        struct axutil_array_list *array_list,
        const axutil_env_t *env,
        const int index,
        const void* e);

    /**
     * Removes the element at the user-supplied index.
     * @param array_list pointer to array list
     * @param env pointer to environment struct
     * @param index the index of the element to be removed
     * @return the removed void* pointer
     */
    AXIS2_EXTERN void* AXIS2_CALL 
    axutil_array_list_remove(struct axutil_array_list *array_list,
        const axutil_env_t *env,
        int index);

    /**
     * Checks that the index is in the range of possible elements (inclusive).
     * @param array_list pointer to array list
     * @param env pointer to environment struct
     * @param index the index to check
     * @return AXIS2_FALSE if index &gt; size or index &lt; 0, else AXIS2_TRUE
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL 
    axutil_array_list_check_bound_inclusive(
        struct axutil_array_list *array_list,
        const axutil_env_t *env,
        int index);

    /**
     * Checks that the index is in the range of existing elements (exclusive).
     * @param array_list pointer to array list
     * @param env pointer to environment struct
     * @param index the index to check
     * @return AXIS2_FALSE if index &gt;= size or index &lt; 0, else AXIS2_TRUE
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL 
    axutil_array_list_check_bound_exclusive(
        struct axutil_array_list *array_list,
        const axutil_env_t *env,
        int index);

    /**
     * @param array_list pointer to array list
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN void AXIS2_CALL 
    axutil_array_list_free(
        struct axutil_array_list *array_list,
        const axutil_env_t *env);

#ifdef __cplusplus
}
#endif

#endif    /* AXIS2_ARRAY_LIST_H */
