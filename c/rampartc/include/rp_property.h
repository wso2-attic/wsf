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

#ifndef RP_PROPERTY_H
#define RP_PROPERTY_H

/** @defgroup rp_property
 * @ingroup rp_property
 * @{
 */
#include <rp_includes.h>
#include <rp_username_token.h>
#include <rp_x509_token.h>
#include <rp_security_context_token.h>
#include <rp_https_token.h>


#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct rp_property_t rp_property_t;


    AXIS2_EXTERN rp_property_t *AXIS2_CALL
    rp_property_create(const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_property_free(
        rp_property_t *property,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_property_set_value(
        rp_property_t *property,
        const axutil_env_t *env,
        void *value,
        int type);

    AXIS2_EXTERN void *AXIS2_CALL
    rp_property_get_value(
        rp_property_t *property,
        const axutil_env_t *env);

    AXIS2_EXTERN int AXIS2_CALL
    rp_property_get_type(
        rp_property_t *property,
        const axutil_env_t *env);

#ifdef __cplusplus
}
#endif
#endif
