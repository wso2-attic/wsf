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

#ifndef RP_TOKEN_IDENTIFIER_H
#define RP_TOKEN_IDENTIFIER_H

/** @defgroup rp_token_identifier
 * @ingroup rp_token_identifier
 * @{
 */

#include <rp_includes.h>
#include <rp_property.h>
#include <rp_x509_token.h>
#include <rp_username_token.h>
#include <neethi_assertion.h>

#ifdef __cplusplus
extern "C"
{
#endif

   AXIS2_EXTERN axis2_status_t AXIS2_CALL
   rp_token_identifier_set_token(
        rp_property_t *token,
        neethi_assertion_t *assertion,
        const axutil_env_t *env);
 
#ifdef __cplusplus
}
#endif
#endif
