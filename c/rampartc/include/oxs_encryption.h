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

#ifndef OXS_ENCRYPTION_H
#define OXS_ENCRYPTION_H


/**
  * @file oxs_encryption.h
  * @brief Provides data encryption and decryption functionalities of the OMXMLSec. 
  */

#include <axis2_defines.h>
#include <oxs_ctx.h>
#include <oxs_asym_ctx.h>
#include <axutil_env.h>
#include <axiom_node.h>
#include <axiom_element.h>
#include <axutil_qname.h>

#ifdef __cplusplus
extern "C"
{
#endif
    /**
     * En/Decrypts given data buffer depending on the information avalable in the encryption context using
     * a symmetric key.
     * The resulted data will be placed on the result buffer.
     * Data are not valid only if the method returns 	AXIS2_SUCCESS
     * @enc_ctx pointer to the OMXMLSec symmetric encryption context struct
     * @env pointer to environment struct
     * @input the input buffer	
     * @result the ouput or the ressulted data buffer		
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE	
     */
    AXIS2_EXTERN  axis2_status_t AXIS2_CALL
    oxs_encryption_symmetric_crypt(const axutil_env_t *env,
                                   oxs_ctx_t * enc_ctx,
                                   oxs_buffer_t *input,
                                   oxs_buffer_t *result);

    /**
     * En/Decrypts given data buffer deoending on the information avalable in the encryption context using an
     * asymmetric key, which can be a publik key extracted from a certificate or a private key. 
     * The resulted data will be placed on the result buffer.
     * Data are not valid only if the method returns 	AXIS2_SUCCESS
     * @enc_ctx pointer to the OMXMLSec asymmetric encryption context struct
     * @env pointer to environment struct
     * @input the input buffer	
     * @result the ouput or the ressulted data buffer			
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE	
     */
    AXIS2_EXTERN  axis2_status_t AXIS2_CALL
    oxs_encryption_asymmetric_crypt(const axutil_env_t *env,
                                    oxs_asym_ctx_t * enc_ctx,
                                    oxs_buffer_t *input,
                                    oxs_buffer_t *result);

    /** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* OXS_ENCRYPTION_H */
