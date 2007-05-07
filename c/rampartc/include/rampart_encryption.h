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
#include <axutil_env.h>
#include <axiom_soap.h>
#include <axis2_msg_ctx.h>
#include <oxs_asym_ctx.h>
#include <oxs_xml_encryption.h>
#include <rampart_context.h>
/**
  * @file rampart_encryption.h
  * @brief encrypts a SOAP message 
  */
#ifndef RAMPART_ENCRYPTION_H
#define RAMPART_ENCRYPTION_H

#ifdef __cplusplus
extern "C" {
#endif

    /**
    * @param env pointer to environment struct
    * @param msg_ctx message context
    * @param soap_envelope the SOAP envelope
    * @param sec_node The security element
    * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
    */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_enc_encrypt_message(const axutil_env_t *env,
                                axis2_msg_ctx_t *msg_ctx,
                                rampart_context_t *rampart_context,
                                axiom_soap_envelope_t *soap_envelope,
                                axiom_node_t *sec_node);


    /* @} */
#ifdef __cplusplus
}
#endif

#endif    /* !RAMPART_ENCRYPTION_H */
