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

#ifndef RP_HEADER_H
#define RP_HEADER_H

/** @defgroup rp_header
 * @ingroup rp_header
 * @{
 */

#include <rp_includes.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct rp_header_t rp_header_t;

    AXIS2_EXTERN rp_header_t *AXIS2_CALL
    rp_header_create(const axutil_env_t *env);

    AXIS2_EXTERN void AXIS2_CALL
    rp_header_free(rp_header_t *header,
                   const axutil_env_t *env);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rp_header_get_name(rp_header_t *header,
                       const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_header_set_name(rp_header_t *header,
                       const axutil_env_t *env,
                       axis2_char_t *name);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rp_header_get_namespace(rp_header_t *header,
                            const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_header_set_namespace(rp_header_t *header,
                            const axutil_env_t *env,
                            axis2_char_t *namespace);

#ifdef __cplusplus
}
#endif
#endif
