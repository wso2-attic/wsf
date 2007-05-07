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

#ifndef OXS_CTX_H
#define OXS_CTX_H


/**
  * @file oxs_ctx.h
  * @brief Keeps configurations for the OMXMLSecurity 
  */

#include <axis2_defines.h>
#include <axutil_env.h>
#include <axiom_node.h>
#include <oxs_buffer.h>
#include <oxs_key.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /** @defgroup oxs_ctx Message Context
     * @ingroup oxs_context
     * @{
     */

    /*TODO We need to change the name oxs_ctx -> oxs_sym_ctx.
     * The name is sounds too generic as there is another oxs_asym_ctx.
     * */

    typedef enum  {
        OXS_CTX_OPERATION_NONE = 0,
        OXS_CTX_OPERATION_ENCRYPT,
        OXS_CTX_OPERATION_DECRYPT
    } oxs_ctx_operation_t;

    typedef enum {
        OXS_CTX_MODE_ENCRYPTED_DATA = 0,
        OXS_CTX_MODE_ENCRYPTED_KEY
    } oxs_ctx_mode_t;


    /** Type name for struct oxs_ctx */
    typedef struct oxs_ctx_t oxs_ctx_t;



    /**
     * Free function of the context
     * @param ctx The OMXMLSecurity context 
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    axis2_status_t AXIS2_CALL
    oxs_ctx_free(
        oxs_ctx_t *ctx,
        const axutil_env_t *env
    );

    /**
     * Returns the mode of the context
     * @param ctx The OMXMLSecurity context 
     * @param env pointer to environment struct
     * @return mode of the context 
     */
    oxs_ctx_mode_t AXIS2_CALL
    oxs_ctx_get_mode(
        oxs_ctx_t *ctx,
        const axutil_env_t *env
    );

    /**
     * 
     * @param ctx The OMXMLSecurity context 
     * @param env pointer to environment struct
     * @return operation of the context 
     */
    oxs_ctx_operation_t AXIS2_CALL
    oxs_ctx_get_operation(
        oxs_ctx_t *ctx,
        const axutil_env_t *env
    );


    /**
     * 
     * @param ctx The OMXMLSecurity context 
     * @param env pointer to environment struct
     * @return of the context 
     */
    oxs_key_t *AXIS2_CALL
    oxs_ctx_get_key(
        oxs_ctx_t *ctx,
        const axutil_env_t *env
    );

    /**
     * 
     * @param ctx The OMXMLSecurity context 
     * @param env pointer to environment struct
     * @return of the context 
     */
    axis2_char_t *AXIS2_CALL
    oxs_ctx_get_id(
        oxs_ctx_t *ctx,
        const axutil_env_t *env
    );

    /**
     * 
     * @param ctx The OMXMLSecurity context 
     * @param env pointer to environment struct
     * @return of the context 
     */
    axis2_char_t *AXIS2_CALL
    oxs_ctx_get_type(
        oxs_ctx_t *ctx,
        const axutil_env_t *env
    );
    /**
     * 
     * @param ctx The OMXMLSecurity context 
     * @param env pointer to environment struct
     * @return of the context 
     */
    axis2_char_t *AXIS2_CALL
    oxs_ctx_get_mime_type(
        oxs_ctx_t *ctx,
        const axutil_env_t *env
    );

    /**
     * 
     * @param ctx The OMXMLSecurity context 
     * @param env pointer to environment struct
     * @return of the context 
     */
    axis2_char_t *AXIS2_CALL
    oxs_ctx_get_encoding(
        oxs_ctx_t *ctx,
        const axutil_env_t *env
    );

    /**
     * 
     * @param ctx The OMXMLSecurity context 
     * @param env pointer to environment struct
     * @return of the context 
     */
    axis2_char_t *AXIS2_CALL
    oxs_ctx_get_recipient(
        oxs_ctx_t *ctx,
        const axutil_env_t *env
    );

    /**
     * 
     * @param ctx The OMXMLSecurity context 
     * @param env pointer to environment struct
     * @return of the context 
     */
    axis2_char_t *AXIS2_CALL
    oxs_ctx_get_carried_key_name(
        oxs_ctx_t *ctx,
        const axutil_env_t *env
    );

    /**
     * 
     * @param ctx The OMXMLSecurity context 
     * @param env pointer to environment struct
     * @return of the context 
     */
    axis2_char_t *AXIS2_CALL
    oxs_ctx_get_enc_mtd_algorithm(
        oxs_ctx_t *ctx,
        const axutil_env_t *env
    );

    /**
     * 
     * @param ctx The OMXMLSecurity context 
     * @param env pointer to environment struct
     * @return of the context 
     */
    axis2_char_t *AXIS2_CALL
    oxs_ctx_get_input_data(
        oxs_ctx_t *ctx,
        const axutil_env_t *env
    );
    /**
     * 
     * @param ctx The OMXMLSecurity context 
     * @param env pointer to environment struct
     * @param mode the mode of operation, EncryptedData/EncryptedKey
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    axis2_status_t AXIS2_CALL
    oxs_ctx_set_mode(
        oxs_ctx_t *ctx,
        const axutil_env_t *env,
        oxs_ctx_mode_t mode
    );

    /**
     * 
     * @param ctx The OMXMLSecurity context 
     * @param env pointer to environment struct
     * @param operation the operation Encrypt/Decrypt/Sign/Verify
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    axis2_status_t AXIS2_CALL
    oxs_ctx_set_operation(
        oxs_ctx_t *ctx,
        const axutil_env_t *env,
        oxs_ctx_operation_t operation
    );

    /**
     * 
     * @param ctx The OMXMLSecurity context 
     * @param env pointer to environment struct
     * @param key the key used
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    axis2_status_t AXIS2_CALL
    oxs_ctx_set_key(
        oxs_ctx_t *ctx,
        const axutil_env_t *env,
        oxs_key_t *key
    );
    /**
     * 
     * @param ctx The OMXMLSecurity context 
     * @param env pointer to environment struct
     * @param id the id of the context 
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    axis2_status_t AXIS2_CALL
    oxs_ctx_set_id(
        oxs_ctx_t *ctx,
        const axutil_env_t *env,
        axis2_char_t *id
    );

    /**
     * 
     * @param ctx The OMXMLSecurity context 
     * @param env pointer to environment struct
     * @param type ???Depricated?
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    axis2_status_t AXIS2_CALL
    oxs_ctx_set_type(
        oxs_ctx_t *ctx,
        const axutil_env_t *env,
        axis2_char_t *type
    );

    /**
     * 
     * @param ctx The OMXMLSecurity context 
     * @param env pointer to environment struct
     * @param mime_type the mime type used
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    axis2_status_t AXIS2_CALL
    oxs_ctx_set_mime_type(
        oxs_ctx_t *ctx,
        const axutil_env_t *env,
        axis2_char_t *mime_type
    );


    /**
     * 
     * @param ctx The OMXMLSecurity context 
     * @param env pointer to environment struct
     * @param encoding the encoding used
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    axis2_status_t AXIS2_CALL
    oxs_ctx_set_encoding(
        oxs_ctx_t *ctx,
        const axutil_env_t *env,
        axis2_char_t *encoding
    );

    /**
     * 
     * @param ctx The OMXMLSecurity context 
     * @param env pointer to environment struct
     * @param recipient name of recipient
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    axis2_status_t AXIS2_CALL
    oxs_ctx_set_recipient(
        oxs_ctx_t *ctx,
        const axutil_env_t *env,
        axis2_char_t *recipient
    );


    /**
     * 
     * @param ctx The OMXMLSecurity context 
     * @param env pointer to environment struct
     * @param carried_key_name the key name 
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    axis2_status_t AXIS2_CALL
    oxs_ctx_set_carried_key_name(
        oxs_ctx_t *ctx,
        const axutil_env_t *env,
        axis2_char_t *carried_key_name
    );

    /**
     * 
     * @param ctx The OMXMLSecurity context 
     * @param env pointer to environment struct
     * @param enc_mtd_algorithm the encryption method algorithm
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    axis2_status_t AXIS2_CALL
    oxs_ctx_set_enc_mtd_algorithm(
        oxs_ctx_t *ctx,
        const axutil_env_t *env,
        axis2_char_t *enc_mtd_algorithm
    );
    /**
     * 
     * @param ctx The OMXMLSecurity context 
     * @param env pointer to environment struct
     * @param input_data the input data
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    axis2_status_t AXIS2_CALL
    oxs_ctx_set_input_data(
        oxs_ctx_t *ctx,
        const axutil_env_t *env,
        axis2_char_t *input_data
    );



    /*Create function*/
    AXIS2_EXTERN oxs_ctx_t *AXIS2_CALL
    oxs_ctx_create(const axutil_env_t *env);


    /** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* OXS_CTX_H */
