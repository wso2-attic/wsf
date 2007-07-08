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

#ifndef AXIOM_MIME_PARSER_H
#define AXIOM_MIME_PARSER_H

/**
 * @file axiom_mime_parser.h
 * @brief axis2 mime_parser interface
 */

#include <axutil_utils.h>
#include <axutil_error.h>
#include <axutil_utils_defines.h>
#include <axutil_env.h>
#include <axutil_allocator.h>
#include <axutil_string.h>
#include <axutil_hash.h>
#include <axiom_mime_const.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct axiom_mime_parser axiom_mime_parser_t;


    /** @defgroup axiom_mime_parser Flow
      * @ingroup axiom_mime_parser
      * @{
      */

    AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
    axiom_mime_parser_parse(axiom_mime_parser_t *mime_parser,
        const axutil_env_t *env,
        AXIS2_READ_INPUT_CALLBACK,
        void *callback_ctx,
        axis2_char_t *mime_boundary);

    AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
    axiom_mime_parser_get_mime_parts_map(axiom_mime_parser_t *mime_parser,
        const axutil_env_t *env);

    /** Deallocate memory
      * @return status code
      */
    AXIS2_EXTERN void AXIS2_CALL
    axiom_mime_parser_free(axiom_mime_parser_t *mime_parser,
        const axutil_env_t *env);

    AXIS2_EXTERN int AXIS2_CALL
    axiom_mime_parser_get_soap_body_len(axiom_mime_parser_t *mime_parser,
       const axutil_env_t *env);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    axiom_mime_parser_get_soap_body_str(axiom_mime_parser_t *mime_parser,
        const axutil_env_t *env);

    /**
     * Creates mime_parser struct
     * @return pointer to newly created mime_parser
     */
    AXIS2_EXTERN axiom_mime_parser_t * AXIS2_CALL
    axiom_mime_parser_create(const axutil_env_t *env);

    /** @} */

#ifdef __cplusplus
}
#endif
#endif  /* AXIOM_MIME_PARSER_H */
