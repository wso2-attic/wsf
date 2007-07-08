/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef OXS_C14N_H
#define OXS_C14N_H

/** @defgroup oxs_c14n c14n
 * @ingroup oxs_c14n
 * XML Canonicalization (XML-C14N).
 * @{
 */

/**
 * @file oxs_c14n.h
 * @brief
 */

#include <axis2_const.h>
#include <axutil_error.h>
#include <axutil_utils_defines.h>
#include <axutil_utils.h>
#include <axutil_env.h>
#include <axutil_string.h>
#include <axiom_document.h>
#include <axutil_array_list.h>
#include <axutil_stream.h>

#ifdef __cplusplus
extern "C"
{
#endif
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_c14n_apply_stream_algo(
        const axutil_env_t *env,
        const axiom_document_t *doc,
        axutil_stream_t *stream,
        const axutil_array_list_t *ns_prefixes,
        const axiom_node_t *node,
        const axis2_char_t* algo
    );

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_c14n_apply_algo(
        const axutil_env_t *env,
        const axiom_document_t *doc,
        axis2_char_t **outbuf,
        const axutil_array_list_t *ns_prefixes,
        const axiom_node_t *node,
        const axis2_char_t *algo
    );


    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_c14n_apply_stream(
        const axutil_env_t *env,
        const axiom_document_t *doc,
        axis2_bool_t comments,
        axutil_stream_t *stream,
        const axis2_bool_t exclusive,
        const axutil_array_list_t *ns_prefixes,
        const axiom_node_t *node
    );

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_c14n_apply (
        const axutil_env_t *env,
        const axiom_document_t *doc,
        const axis2_bool_t comments,
        axis2_char_t **outbuf,
        const axis2_bool_t exclusive,
        const axutil_array_list_t *ns_prefixes,
        const axiom_node_t *node
    );

#ifdef __cplusplus
}
#endif
#endif  /* OXS_C14N_H */
