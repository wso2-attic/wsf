/*
 *   Copyright 2003-2004 The Apache Software Foundation.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 */



#include <axutil_utils_defines.h>
#include <axis2_defines.h>
#include <axutil_date_time.h>
#include <axutil_env.h>
#include <axutil_property.h>
#include <axis2_msg_ctx.h>
#include <rampart_authn_provider.h>
#include <rampart_credentials.h>
#include <rampart_callback.h>
/**
  * @file rampart_token_processor.h
  * @brief Token processing of rampart
  */
#ifndef RAMPART_TOKEN_PROCESSOR_H
#define RAMPART_TOKEN_PROCESSOR_H

#ifdef __cplusplus
extern "C" {
#endif
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_token_process_security_token_reference(const axutil_env_t *env,
            axiom_node_t *st_ref_node,
            axiom_node_t *scope_node,/*Can be NULL for all other scenarios but the Direct Reference*/
            oxs_x509_cert_t *cert);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_token_process_direct_ref(const axutil_env_t *env,
                                     axiom_node_t *ref_node,
                                     axiom_node_t *scope_node,
                                     oxs_x509_cert_t *cert);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_token_process_embedded(const axutil_env_t *env,
                                   axiom_node_t *embed_node,
                                   oxs_x509_cert_t *cert);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_token_process_key_identifier(const axutil_env_t *env,
                                         axiom_node_t *ki_node,
                                         oxs_x509_cert_t *cert);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_token_process_x509_data(const axutil_env_t *env,
                                    axiom_node_t *x509_data_node,
                                    oxs_x509_cert_t *cert);
    /* @} */
#ifdef __cplusplus
}
#endif

#endif    /* !RAMPART_TOKEN_PROCESSOR_H */


