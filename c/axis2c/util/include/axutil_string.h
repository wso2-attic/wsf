/**
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

#ifndef AXUTIL_STRING_H
#define AXUTIL_STRING_H

#include <axutil_utils_defines.h>
#include <axutil_error.h>
#include <axutil_env.h>
#include <string.h>

#ifdef __cplusplus
extern "C"
{
#endif
    
    /**
     * @defgroup axutil_string string
     * @ingroup axis2_util
     * @{
     */

    typedef struct axutil_string axutil_string_t;

    /**
     * Creates a string struct.
     * @param str pointer to string. string struct would create a duplicate of 
     * this    
     * @param env pointer to environment struct
     * @return a pointer to newly created string struct
     */
    AXIS2_EXTERN axutil_string_t * AXIS2_CALL
    axutil_string_create(const axutil_env_t *env,
        const axis2_char_t *str);
    
    /**
     * Creates a string struct.
     * @param str pointer to string. string struct would not create a duplicate 
     * of this, but would assume ownership
     * @param env pointer to environment struct
     * @return a pointer to newly created string struct
     */
    AXIS2_EXTERN axutil_string_t * AXIS2_CALL
    axutil_string_create_assume_ownership(const axutil_env_t *env,
        axis2_char_t **str);

    /**
     * Creates a string struct.
     * @param str pointer to string. string struct would not create a duplicate 
     * of this and assumes the str would have longer life than that of itself
     * @param env pointer to environment struct
     * @return a pointer to newly created string struct     
     */
    AXIS2_EXTERN axutil_string_t* AXIS2_CALL
    axutil_string_create_const(const axutil_env_t *env,
        axis2_char_t **str);

    /**
     * Frees string struct.
     * @param string pointer to string struct
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN void AXIS2_CALL
    axutil_string_free(struct axutil_string *string,
        const axutil_env_t *env);

    /**
     * Compares two strings. Checks if the two strings point to the same buffer.
     * Do not cmpare the buffer contents.
     * @param string pointer to string struct
     * @param env pointer to environment struct
     * @param string1 pointer to string struct to be compared
     * @return AXIS2_TRUE if string equals string1, AXIS2_FALSE otherwise 
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axutil_string_equals(const struct axutil_string *string,
        const axutil_env_t *env,
        const struct axutil_string *string1);

    /**
     * Clones a given string. Does not duplicate the buffer, rather 
     * increments the reference count. Each call to clone needs to have a 
     * matching free, when the clone is done with. 
     * @param string pointer to string struct
     * @param env pointer to environment struct
     * @returns pointer to cloned string struct instance
     */
    AXIS2_EXTERN struct axutil_string *AXIS2_CALL
    axutil_string_clone(struct axutil_string *string,
        const axutil_env_t *env);

    /**
     * Gets string buffer.
     * @param string pointer to string struct
     * @param env pointer to environment struct
     * @returns pointer to string buffer
     */
    AXIS2_EXTERN const axis2_char_t* AXIS2_CALL
    axutil_string_get_buffer(const struct axutil_string *string,
        const axutil_env_t *env);

    /**
     * Gets string length.  * @param string pointer to string struct * @param env pointer to environment struct * @returns buffer length */
    AXIS2_EXTERN unsigned int AXIS2_CALL
    axutil_string_get_length(const struct axutil_string *string,
        const axutil_env_t *env);
    
    /** @} */

    /**
     * @defgroup axutil_string_utils string_utils
     * @ingroup axis2_util
     * @{
     */

    AXIS2_EXTERN void* AXIS2_CALL
    axutil_strdup(const axutil_env_t *env,
	    const void *ptr);

    /**
     * duplicate the first n characters of a string into memory allocated 
     * the new string will be null-terminated
     * @param ptr The string to duplicate
     * @param n The number of characters to duplicate
     * @return The new string
     */
    AXIS2_EXTERN void* AXIS2_CALL
    axutil_strndup(const axutil_env_t *env,
	    const void *ptr,
        int n);

    /**
     * Create a null-terminated string by making a copy of a sequence
     * of characters and appending a null byte
     * @param ptr The block of characters to duplicate
     * @param n The number of characters to duplicate
     * @return The new string
     * @remark This is a faster alternative to axis2_strndup, for use
     *         when you know that the string being duplicated really
     *         has 'n' or more characters.  If the string might contain
     *         fewer characters, use axis2_strndup.
     */
    AXIS2_EXTERN void * AXIS2_CALL
    axutil_strmemdup(const void *ptr,
        size_t n,
        const axutil_env_t *env);

    AXIS2_EXTERN void * AXIS2_CALL
    axutil_memchr(const void *ptr,
        int c,
        size_t n);

    AXIS2_EXTERN int AXIS2_CALL
    axutil_strcmp(const axis2_char_t * s1,
        const axis2_char_t * s2);

    AXIS2_EXTERN int AXIS2_CALL
    axutil_strncmp(const axis2_char_t * s1,
        const axis2_char_t * s2,
        int n);

    AXIS2_EXTERN axis2_ssize_t AXIS2_CALL
    axutil_strlen(const axis2_char_t * s);

    AXIS2_EXTERN int AXIS2_CALL
    axutil_strcasecmp(const axis2_char_t *s1,
        const axis2_char_t *s2);

    AXIS2_EXTERN int AXIS2_CALL
    axutil_strncasecmp(const axis2_char_t *s1,
        const axis2_char_t *s2, 
        const int n);

    /* much similar to the strcat behaviour. But the difference is
     * this allocates new memory to put the conatenated string rather than
     * modifying the first argument. The user should free the allocated
     * memory for the return value
     */
    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    axutil_stracat(const axutil_env_t *env,
	    const axis2_char_t *s1,
        const axis2_char_t *s2);

    /**
     * Concatenate multiple strings, allocating memory
     * @param ... The strings to concatenate.  The final string must be NULL
     * @return The new string
     */
    AXIS2_EXTERN axis2_char_t * AXIS2_CALL
    axutil_strcat(const axutil_env_t *env, ...);

    AXIS2_EXTERN axis2_char_t * AXIS2_CALL
    axutil_strstr(const axis2_char_t *heystack,
        const axis2_char_t *needle);

    AXIS2_EXTERN axis2_char_t * AXIS2_CALL
    axutil_rindex(const axis2_char_t *s,
        axis2_char_t c);

    /* replaces s1 with s2 */
    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    axutil_replace(const axutil_env_t *env,
        axis2_char_t *str,
        int s1,
        int s2);

    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    axutil_strltrim(const axutil_env_t *env,
        const axis2_char_t *_s,
        const axis2_char_t *_trim);

    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    axutil_strrtrim(const axutil_env_t *env,
        const axis2_char_t *_s,
        const axis2_char_t *_trim);

    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    axutil_strtrim(const axutil_env_t *env,
        const axis2_char_t *_s,
        const axis2_char_t *_trim);

    /**
     * replace given axis2_character with a new one.
     * @param str       string operation apply
     * @param old_char  the old axis2_character which would be replaced
     * @param new_char  new axis2_char_tacter
     * @return      replaced string
     */
    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    axutil_string_replace(axis2_char_t *str,
        axis2_char_t old_char,
        axis2_char_t new_char);

    /**
     * gives a sub string starting with given index.
     * @param str       string operation apply
     * @param c     starting index
     * @return      substring
     */
    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    axutil_string_substring_starting_at(axis2_char_t *str,
        int s);

    /**
     * gives a sub string ending with given index.
     * @param str       string operation apply
     * @param c     ending index
     * @return      substring
     */
    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    axutil_string_substring_ending_at(axis2_char_t *str,
        int e);

    /**
     * set a string to lowercase.
     * @param str   string
     * @return string with lowercase
     */
    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    axutil_string_tolower(axis2_char_t *str);

    /**
     * set a string to uppercase.
     * @param str   string
     * @return string with uppercase
     */
    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    axutil_string_toupper(axis2_char_t *str);

    /**
     * Finds the first occurrence of the substring needle in the string 
     * haystack, ignores the case of both arguments. 
     * @param haystack string in which the given string is to be found
     * @param needle string to be found in haystack
     * @return pointer to the beginning of the substring, 
     * or NULL  if  the  substring  is  not found
     */
    AXIS2_EXTERN axis2_char_t * AXIS2_CALL
    axutil_strcasestr(const axis2_char_t *heystack,
        const axis2_char_t *needle);

    /** @} */

#ifdef __cplusplus
}
#endif

#endif                          /* AXIS2_STRING_H */
