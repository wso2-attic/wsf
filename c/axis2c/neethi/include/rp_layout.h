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

#ifndef RP_LAYOUT_H
#define RP_LAYOUT_H

/** @defgroup rp_layout
 * @ingroup rp_layout
 * @{
 */

#include <rp_includes.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct rp_layout_t rp_layout_t;

    AXIS2_EXTERN rp_layout_t *AXIS2_CALL
    rp_layout_create(const axutil_env_t *env);

    AXIS2_EXTERN void AXIS2_CALL
    rp_layout_free(rp_layout_t *layout,
                   const axutil_env_t *env);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rp_layout_get_value(rp_layout_t *layout,
                        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_layout_set_value(rp_layout_t *layout,
                        const axutil_env_t *env,
                        axis2_char_t *value);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_layout_increment_ref(rp_layout_t *layout,
                            const axutil_env_t *env);
    

#ifdef __cplusplus
}
#endif
#endif
