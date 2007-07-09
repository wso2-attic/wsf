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

#ifndef OXS_XML_ENCRYPTION_H
#define OXS_XML_ENCRYPTION_H


/**
  * @file oxs_xml_encryption.h
  * @brief Does the XML encryption for OMXMLSecurity  
  */

#include <axis2_defines.h>
#include <oxs_ctx.h>
#include <axutil_env.h>
#include <axiom_node.h>
#include <axiom_element.h>
#include <axutil_qname.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * Encrypts a given node as specified in the @enc_ctx. 
     * A reference is taken for the EncryptedData to place the encrypted data.
     * @param env pointer to environment struct
     * @param enc_ctx encryption context
     * @param node the node tobe encrypted
     * @param enc_type_node reference to the EncryptedData node
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_xml_enc_encrypt_node(const axutil_env_t *env,
                             oxs_ctx_t * enc_ctx,
                             axiom_node_t *node,
                             axiom_node_t **enc_type_node);

    /**
     * Decrypts a node as specified in the @enc_ctx.
     * A reference is taken to assign the address of the decrypted node
     * @param env pointer to environment struct
     * @param enc_ctx encryption context
     * @param enc_type_node the EncryptedData node which needs to be decrypted
     * @param decrypted_node reference to the decrypted node
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_xml_enc_decrypt_node(const axutil_env_t *env,
                             oxs_ctx_t * enc_ctx,
                             axiom_node_t *enc_type_node,
                             axiom_node_t **decrypted_node);

    /**
     * Encrypts data or the content of the @content_buf as specified in the @enc_ctx.
     * A reference is taken for the EncryptedData to place the encrypted data
     * @param env pointer to environment struct
     * @param enc_ctx encryption context
     * @param content_buf the content to be encrypted. 
     * @param enc_type_node reference to the EncryptedData node
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_xml_enc_encrypt_data(const axutil_env_t *env,
                             oxs_ctx_t * enc_ctx,
                             oxs_buffer_t *content_buf,
                             axiom_node_t **enc_type_node);

    /**
     * Decrypts @enc_type_node and places the data inside the @result_buf
     * The name of the method is bit tricky as it doesn't exactly decrypts a data buffer.
     * @param env pointer to environment struct
     * @param enc_ctx encryption context
     * @param enc_type_node the EncryptedData node which needs to be decrypted
     * @param result_buf the buffer to keep the decrypted content
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_xml_enc_decrypt_data(const axutil_env_t *env,
                             oxs_ctx_t * enc_ctx,
                             axiom_node_t *enc_type_node,
                             oxs_buffer_t *result_buf);

    /**
     * Encrypts a key/data in asymmetric way as specified in @asym_ctx.
     * This method is specifically written to support the key encryption in WS-Secruity
     * @param env pointer to environment struct
     * @param enc_ctx encryption context
     * @param parent parent of the EncryptedKey node
     * @param sym_key, the symmetric key that needs to be encrypted
     * @param id_list the list of nodes that are encrypted by this particular key
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_xml_enc_encrypt_key(const axutil_env_t *env,
                            oxs_asym_ctx_t * asym_ctx,
                            axiom_node_t *parent,
                            oxs_key_t *sym_key,
                            axutil_array_list_t *id_list);

    /**
     * Decrypts  a key/data in asymmetric way as specified in @asym_ctx.
     * This method is specifically written to support the key decryption in WS-Secruity
     * @param env pointer to environment struct
     * @param enc_ctx encryption context
     * @param parent parent of the EncryptedKey node
     * @param encrypted_key_node the EncryptedKey node
     * @param key, the key which holds the decrypted key data
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_xml_enc_decrypt_key(const axutil_env_t *env,
                            oxs_asym_ctx_t * asym_ctx,
                            axiom_node_t *parent,
                            axiom_node_t *encrypted_key_node,
                            oxs_key_t *key);
    /** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* OXS_XML_ENCRYPTION_H */
