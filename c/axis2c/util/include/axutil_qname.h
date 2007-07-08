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

#ifndef AXUTIL_QNAME_H
#define AXUTIL_QNAME_H

/**
 * @file axutil_qname.h
 * @brief represents a qualified name
 */

#include <axutil_utils_defines.h>
#include <axutil_env.h>

#include <axutil_string.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @defgroup axutil_qname qname
     * @ingroup axis2_util
     * @{
     */

    typedef struct axutil_qname axutil_qname_t;

    /**
     *   creates a qname struct
     *  returns a pointer to a qname struct
     *  @localpart   mandatory
     *  @prefix      mandatory
     *  @ns_uri      optional
     *  The prefix. Must not be null. Use "" (empty string) to indicate that no
     * namespace URI is present or the namespace URI is not relevant
     *  if null is passed for prefix and uri , "'(empty string ) will be assinged to
     * those fields
     * @return a pointer to newly created qname struct
     */

    AXIS2_EXTERN axutil_qname_t * AXIS2_CALL
    axutil_qname_create(const axutil_env_t *env,
        const axis2_char_t * localpart,
        const axis2_char_t * namespace_uri,
        const axis2_char_t * prefix);


    /**
     * returns a newly created qname using a string genarated from
     * axutil_qname_to_string method
     * freeing the returned qname is users responsibility
     */

    AXIS2_EXTERN axutil_qname_t* AXIS2_CALL
    axutil_qname_create_from_string(const axutil_env_t *env,
        const axis2_char_t *string);

    /**
     *  Free a qname struct
     *  @return Status code
     */
    AXIS2_EXTERN void AXIS2_CALL
    axutil_qname_free(struct axutil_qname * qname,
        const axutil_env_t *env);

    /**
     * Compare two qnames
     * prefix is ignored when comparing
     * If ns_uri and localpart of qname1 and qname2 is equal returns true
     * @return true if qname1 equals qname2, false otherwise 
     */

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axutil_qname_equals(const struct axutil_qname * qname,
        const axutil_env_t *env,
        const struct axutil_qname * qname1);
    /**
    * clones a given qname
    * @param qname , qname struct instance to be cloned
    * @env   environment , double pointer to environment
    * @returns the newly cloned qname struct instance
    */

    AXIS2_EXTERN struct axutil_qname* AXIS2_CALL
    axutil_qname_clone(struct axutil_qname *qname,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    axutil_qname_get_uri(const struct axutil_qname *qname,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    axutil_qname_get_prefix(const struct axutil_qname *qname,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    axutil_qname_get_localpart(const struct axutil_qname *qname,
        const axutil_env_t *env);

    /**
     * returns a unique string created by concatanting namespace uri 
     * and localpart .
     * The string is of the form localpart|url
     * The returned char* is freed when qname free function is called.
     */
    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    axutil_qname_to_string(struct axutil_qname *qname,
        const axutil_env_t *env);

    /** @} */

#ifdef __cplusplus
}
#endif

#endif /* AXIS2_QNAME_H */
