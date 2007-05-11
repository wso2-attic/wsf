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

#ifndef RP_BINDING_COMMONS_H
#define RP_BINDING_COMMONS_H

/** @defgroup rp_binding_commons
 * @ingroup rp_binding_commons
 * @{
 */
#include <rp_includes.h>
#include <rp_algorithmsuite.h>
#include <rp_layout.h>
#include <rp_supporting_tokens.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct rp_binding_commons_t rp_binding_commons_t;

    AXIS2_EXTERN rp_binding_commons_t *AXIS2_CALL
    rp_binding_commons_create(const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_binding_commons_free(rp_binding_commons_t *binding_commons,
                            const axutil_env_t *env);

    AXIS2_EXTERN rp_algorithmsuite_t *AXIS2_CALL
    rp_binding_commons_get_algorithmsuite(rp_binding_commons_t *binding_commons,
                                          const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_binding_commons_set_algorithmsuite(rp_binding_commons_t *binding_commons,
                                          const axutil_env_t *env,
                                          rp_algorithmsuite_t *algorithmsuite);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rp_binding_commons_get_include_timestamp(rp_binding_commons_t *binding_commons,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_binding_commons_set_include_timestamp(rp_binding_commons_t *binding_commons,
            const axutil_env_t *env,
            axis2_bool_t include_timestamp);

    AXIS2_EXTERN rp_layout_t *AXIS2_CALL
    rp_binding_commons_get_layout(rp_binding_commons_t *binding_commons,
                                  const axutil_env_t *env);


    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_binding_commons_set_layout(rp_binding_commons_t *binding_commons,
                                  const axutil_env_t *env,
                                  rp_layout_t *layout);

    AXIS2_EXTERN rp_supporting_tokens_t *AXIS2_CALL
    rp_binding_commons_get_signed_supporting_tokens(
        rp_binding_commons_t *binding_commons,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_binding_commons_set_signed_supporting_tokens(
        rp_binding_commons_t *binding_commons,
        const axutil_env_t *env,
        rp_supporting_tokens_t *signed_supporting_tokens);


    AXIS2_EXTERN rp_supporting_tokens_t *AXIS2_CALL
    rp_binding_commons_get_signed_endorsing_supporting_tokens(
        rp_binding_commons_t *binding_commons,
        const axutil_env_t *env);


    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_binding_commons_set_signed_endorsing_supporting_tokens(
        rp_binding_commons_t *binding_commons,
        const axutil_env_t *env,
        rp_supporting_tokens_t *signed_endorsing_supporting_tokens);

    AXIS2_EXTERN rp_supporting_tokens_t *AXIS2_CALL
    rp_binding_commons_get_endorsing_supporting_tokens(
        rp_binding_commons_t *binding_commons,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_binding_commons_set_endorsing_supporting_tokens(
        rp_binding_commons_t *binding_commons,
        const axutil_env_t *env,
        rp_supporting_tokens_t *endorsing_supporting_tokens);

    AXIS2_EXTERN rp_supporting_tokens_t *AXIS2_CALL
    rp_binding_commons_get_supporting_tokens(
        rp_binding_commons_t *binding_commons,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_binding_commons_set_supporting_tokens(
        rp_binding_commons_t *binding_commons,
        const axutil_env_t *env,
        rp_supporting_tokens_t *supporting_tokens);


#ifdef __cplusplus
}
#endif
#endif
