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

#ifndef RP_ALGORITHMSUITE_H
#define RP_ALGORITHMSUITE_H

/** @defgroup rp_algoruthmsuite
 * @ingroup rp_algorithmsuite
 * @{
 */

#include <rp_includes.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct rp_algorithmsuite_t rp_algorithmsuite_t;

    AXIS2_EXTERN rp_algorithmsuite_t *AXIS2_CALL
    rp_algorithmsuite_create(const axutil_env_t *env);

    AXIS2_EXTERN void AXIS2_CALL
    rp_algorithmsuite_free(rp_algorithmsuite_t *algorithmsuite,
                           const axutil_env_t *env);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rp_algorithmsuite_get_algosuite_string(rp_algorithmsuite_t *algorithmsuite,
                                           const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_algorithmsuite_set_algosuite(rp_algorithmsuite_t *algorithmsuite,
                                    const axutil_env_t *env,
                                    axis2_char_t *algosuite_string);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rp_algorithmsuite_get_symmetric_signature(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_algorithmsuite_set_symmetric_signature(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env,
            axis2_char_t *symmetric_signature);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rp_algorithmsuite_get_asymmetric_signature(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_algorithmsuite_set_asymmetric_signature(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env,
            axis2_char_t *asymmetric_signature);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rp_algorithmsuite_get_computed_key(rp_algorithmsuite_t *algorithmsuite,
                                       const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_algorithmsuite_set_computed_key(rp_algorithmsuite_t *algorithmsuite,
                                       const axutil_env_t *env,
                                       axis2_char_t *computed_key);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rp_algorithmsuite_get_digest(rp_algorithmsuite_t *algorithmsuite,
                                 const axutil_env_t *env);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rp_algorithmsuite_get_encryption(rp_algorithmsuite_t *algorithmsuite,
                                     const axutil_env_t *env);

    AXIS2_EXTERN int AXIS2_CALL
    rp_algorithmsuite_get_max_symmetric_keylength(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_algorithmsuite_set_max_symmetric_keylength(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env,
            int max_symmetric_keylength);

    AXIS2_EXTERN int AXIS2_CALL
    rp_algorithmsuite_get_min_symmetric_keylength(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env);

    AXIS2_EXTERN int AXIS2_CALL
    rp_algorithmsuite_get_max_asymmetric_keylength(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_algorithmsuite_set_max_asymmetric_keylength(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env,
            int max_asymmetric_keylength);

    AXIS2_EXTERN int AXIS2_CALL
    rp_algorithmsuite_get_min_asymmetric_keylength(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_algorithmsuite_set_min_asymmetric_keylength(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env,
            int min_asymmetric_keylength);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rp_algorithmsuite_get_symmetrickeywrap(rp_algorithmsuite_t *algorithmsuite,
                                           const axutil_env_t *env);


    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rp_algorithmsuite_get_asymmetrickeywrap(rp_algorithmsuite_t *algorithmsuite,
                                            const axutil_env_t *env);


    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rp_algorithmsuite_get_signature_key_derivation(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env);


    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rp_algorithmsuite_get_encryption_key_derivation(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env);


    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rp_algorithmsuite_get_soap_normalization(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_algorithmsuite_set_soap_normalization(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env,
            axis2_char_t *soap_normalization);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rp_algorithmsuite_get_str_transformation(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_algorithmsuite_set_str_transformation(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env,
            axis2_char_t *str_transformation);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rp_algorithmsuite_get_c14n(rp_algorithmsuite_t *algorithmsuite,
                               const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_algorithmsuite_set_c14n(rp_algorithmsuite_t *algorithmsuite,
                               const axutil_env_t *env,
                               axis2_char_t *c14n);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rp_algorithmsuite_get_xpath(rp_algorithmsuite_t *algorithmsuite,
                                const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_algorithmsuite_set_xpath(rp_algorithmsuite_t *algorithmsuite,
                                const axutil_env_t *env,
                                axis2_char_t *xpath);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_algorithmsuite_increment_ref(rp_algorithmsuite_t *algorithmsuite,
                                    const axutil_env_t *env);
    

#ifdef __cplusplus
}
#endif
#endif
