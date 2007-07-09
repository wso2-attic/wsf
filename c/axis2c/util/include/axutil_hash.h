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

#ifndef AXUTIL_HASH_H
#define AXUTIL_HASH_H

/**
 * @file axutil_hash.h
 * @brief Axis2 Hash Tables
 */

#include <axutil_utils_defines.h>
#include <axutil_env.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @defgroup axutil_hash hash
     * @ingroup axis2_util
     * @{
     */

    /**
     * When passing a key to axutil_hash_set or axutil_hash_get, this value can be
     * passed to indicate a string-valued key, and have axutil_hash compute the
     * length automatically.
     *
     * @remark axutil_hash will use strlen(key) for the length. The NUL terminator
     *         is not included in the hash value (why throw a constant in?).
     *         Since the hash table merely references the provided key (rather
     *         than copying it), axutil_hash_this() will return the NUL-term'd key.
     */
#define AXIS2_HASH_KEY_STRING     (-1)

    /**
     * Abstract type for hash tables.
     */
    typedef struct axutil_hash_t axutil_hash_t;

    /**
     * Abstract type for scanning hash tables.
     */
    typedef struct axutil_hash_index_t axutil_hash_index_t;

    /**
     * Callback functions for calculating hash values.
     * @param key The key.
     * @param klen The length of the key, or AXIS2_HASH_KEY_STRING to use the string
     *             length. If AXIS2_HASH_KEY_STRING then returns the actual key length.
     */
    typedef unsigned int(*axutil_hashfunc_t)(const char *key, axis2_ssize_t *klen);

    /**
     * The default hash function.
     */
    unsigned int axutil_hashfunc_default(const char *key, 
        axis2_ssize_t *klen);

    /**
     * Create a hash table.
     * @param env The environment to allocate the hash table out of
     * @return The hash table just created
      */
    AXIS2_EXTERN axutil_hash_t* AXIS2_CALL 
    axutil_hash_make(const axutil_env_t *env);

    /**
     * Create a hash table with a custom hash function
     * @param env The environment to allocate the hash table out of
     * @param hash_func A custom hash function.
     * @return The hash table just created
      */
    AXIS2_EXTERN axutil_hash_t* AXIS2_CALL 
    axutil_hash_make_custom(const axutil_env_t *env,
        axutil_hashfunc_t hash_func);

    /**
     * Make a copy of a hash table
     * @param ht The hash table to clone
     * @param env The environment from which to allocate the new hash table
     * @return The hash table just created
     * @remark Makes a shallow copy
     */
    AXIS2_EXTERN axutil_hash_t* AXIS2_CALL 
    axutil_hash_copy(const axutil_hash_t *ht,
        const axutil_env_t *env);

    /**
     * Associate a value with a key in a hash table.
     * @param ht The hash table
     * @param key Pointer to the key
     * @param klen Length of the key. Can be AXIS2_HASH_KEY_STRING to use the string length.
     * @param val Value to associate with the key
     * @remark If the value is NULL the hash entry is deleted.
     */
    AXIS2_EXTERN void AXIS2_CALL 
    axutil_hash_set(axutil_hash_t *ht, 
        const void *key,
        axis2_ssize_t klen, 
        const void *val);

    /**
     * Look up the value associated with a key in a hash table.
     * @param ht The hash table
     * @param key Pointer to the key
     * @param klen Length of the key. Can be AXIS2_HASH_KEY_STRING to use the string length.
     * @return Returns NULL if the key is not present.
     */
    AXIS2_EXTERN void* AXIS2_CALL 
    axutil_hash_get(axutil_hash_t *ht, 
        const void *key,
        axis2_ssize_t klen);

    /**
     * Start iterating over the entries in a hash table.
     * @param ht The hash table
     * @param p The environment to allocate the axutil_hash_index_t iterator. If this
     *          environment is NULL, then an internal, non-thread-safe iterator is used.
     * @remark  There is no restriction on adding or deleting hash entries during
     * an iteration (although the results may be unpredictable unless all you do
     * is delete the current entry) and multiple iterations can be in
     * progress at the same time.

     * @example
     */
    /**
     * <PRE>
     *
     * int sum_values(const axutil_env_t *env, axutil_hash_t *ht)
     * {
     *     axutil_hash_index_t *hi;
     *     void *val;
     *     int sum = 0;
     *     for (hi = axutil_hash_first(p, ht); hi; hi = axutil_hash_next(p, hi)) {
     *         axutil_hash_this(hi, NULL, NULL, &val);
     *         sum += *(int *)val;
     *     }
     *     return sum;
     * }
     * </PRE>
     */
    AXIS2_EXTERN axutil_hash_index_t* AXIS2_CALL 
    axutil_hash_first(axutil_hash_t *ht,
        const axutil_env_t *env);

    /**
     * Continue iterating over the entries in a hash table.
     * @param hi The iteration state
     * @return a pointer to the updated iteration state.  NULL if there are no more
     *         entries.
     */
    AXIS2_EXTERN axutil_hash_index_t* AXIS2_CALL 
    axutil_hash_next(const axutil_env_t *env,
        axutil_hash_index_t *hi);

    /**
     * Get the current entry's details from the iteration state.
     * @param hi The iteration state
     * @param key Return pointer for the pointer to the key.
     * @param klen Return pointer for the key length.
     * @param val Return pointer for the associated value.
     * @remark The return pointers should point to a variable that will be set to the
     *         corresponding data, or they may be NULL if the data isn't interesting.
     */
    AXIS2_EXTERN void AXIS2_CALL 
    axutil_hash_this(axutil_hash_index_t *hi, 
        const void **key,
        axis2_ssize_t *klen, 
        void **val);

    /**
     * Get the number of key/value pairs in the hash table.
     * @param ht The hash table
     * @return The number of key/value pairs in the hash table.
     */
    AXIS2_EXTERN  unsigned int AXIS2_CALL 
    axutil_hash_count(axutil_hash_t *ht);

    /**
     * Merge two hash tables into one new hash table. The values of the overlay
     * hash override the values of the base if both have the same key.  Both
     * hash tables must use the same hash function.
     * @param overlay The table to add to the initial table
     * @param p The environment to use for the new hash table
     * @param base The table that represents the initial values of the new table
     * @return A new hash table containing all of the data from the two passed in
     */
    AXIS2_EXTERN axutil_hash_t* AXIS2_CALL 
    axutil_hash_overlay(const axutil_hash_t *overlay,
        const axutil_env_t *env, 
        const axutil_hash_t *base);

    /**
     * Merge two hash tables into one new hash table. If the same key
     * is present in both tables, call the supplied merge function to
     * produce a merged value for the key in the new table.  Both
     * hash tables must use the same hash function.
     * @param h1 The first of the tables to merge
     * @param p The environment to use for the new hash table
     * @param h2 The second of the tables to merge
     * @param merger A callback function to merge values, or NULL to
     *  make values from h1 override values from h2 (same semantics as
     *  axutil_hash_overlay())
     * @param data Client data to pass to the merger function
     * @return A new hash table containing all of the data from the two passed in
     */
    AXIS2_EXTERN axutil_hash_t* AXIS2_CALL 
    axutil_hash_merge(const axutil_hash_t *h1,
        const axutil_env_t *env, 
        const axutil_hash_t *h2,
        void *(*merger)(const axutil_env_t *env, 
            const void *key,
            axis2_ssize_t klen, 
            const void *h1_val, 
            const void *h2_val,
            const void *data), 
        const void *data);

    /**
     * Query whether the hash table provided as parameter contains the
     * key provided as parameter.
     *
     * @param ht hash table to be queried for key
     * @return return whether hash table contains key
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axutil_hash_contains_key(axutil_hash_t *ht,
        const axutil_env_t *env,
        const axis2_char_t *key);

    /**
     * @param ht hash table to be freed
     * @param env The environment to use for hash table
     * @return return status code
     *
     */

    AXIS2_EXTERN void AXIS2_CALL 
    axutil_hash_free(axutil_hash_t *ht,
        const axutil_env_t *env);

    /**
     * Free a hash table with hash table given as void
     * @param ht hash table to be freed as a void *
     * @param env The environment to use for hash table
     * @return return status code
     */

    AXIS2_EXTERN void AXIS2_CALL
    axutil_hash_free_void_arg(void *ht_void, 
        const axutil_env_t* env);

    /** @} */

#ifdef __cplusplus
}
#endif

#endif                          /* !AXIS2_HASH_H */


