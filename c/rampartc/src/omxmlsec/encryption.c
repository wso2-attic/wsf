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

#include <stdio.h>
#include <axis2_util.h>
#include <oxs_constants.h>
#include <oxs_ctx.h>
#include <oxs_error.h>
#include <oxs_buffer.h>
#include <oxs_encryption.h>
#include <oxs_cipher.h>
#include <oxs_iv.h>
#include <openssl_cipher_ctx.h>
#include <openssl_crypt.h>
#include <openssl_constants.h>
#include <openssl_rsa.h>
#include <openssl_util.h>
#include <oxs_key_mgr.h>


AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_encryption_symmetric_crypt(const axutil_env_t *env,
                               oxs_ctx_t * enc_ctx,
                               oxs_buffer_t *input,
                               oxs_buffer_t *result)
{
    openssl_cipher_ctx_t *oc_ctx = NULL;
    openssl_cipher_property_t *cprop = NULL;
    axis2_char_t *iv = NULL;
    axis2_char_t *cipher_name = NULL;
    axis2_status_t ret = AXIS2_FAILURE;

    /*Get cipher property*/
    cprop =  oxs_get_cipher_property_for_url(env, oxs_ctx_get_enc_mtd_algorithm(enc_ctx, env));
    if(!cprop){
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_INVALID_DATA,
                  "Cipher property is NULL");
        return AXIS2_FAILURE;
    }
    /*Get the IV*/
    iv = axutil_strndup(env,
              (axis2_char_t*)oxs_iv_generate_for_algo(env,
                           oxs_ctx_get_enc_mtd_algorithm(enc_ctx, env)),
                       openssl_cipher_property_get_iv_size(cprop, env));

    /*Create the openssl context*/
    oc_ctx = openssl_cipher_ctx_create(env);
    if (!oc_ctx)
    {
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_INVALID_DATA,
                  "openssl_cipher_ctx_create failed");
        return AXIS2_FAILURE;
    }

    /*Set IV*/
    ret = openssl_cipher_ctx_set_iv(oc_ctx, env, iv);

    /*Set key*/
    ret = openssl_cipher_ctx_set_key(oc_ctx, env, oxs_ctx_get_key(enc_ctx, env));

    /*Set the cipher*/
    cipher_name = (axis2_char_t*)openssl_cipher_property_get_name(cprop, env);
    if (!cipher_name)
    {
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_INVALID_DATA,
                  "oxs_get_cipher failed");

        return AXIS2_FAILURE;
    }
    ret = openssl_cipher_ctx_set_cipher(oc_ctx,
                                        env,
                                        (EVP_CIPHER*)openssl_get_evp_cipher_by_name(
                                            env, (axis2_char_t*)cipher_name)
                                       );

    /*Now everything is ready for the en/decryption*/
    /*ENCRYPTION*/
    if (oxs_ctx_get_operation(enc_ctx, env) == OXS_CTX_OPERATION_ENCRYPT)
    {
        axis2_char_t *encoded_str = NULL;
        int enclen = -1;
        int encodedlen = -1;
        oxs_buffer_t *output = NULL;

        output = oxs_buffer_create(env);

        /*Encrypt*/
        enclen = openssl_bc_crypt(env, oc_ctx, input, output, OPENSSL_ENCRYPT);
        if(enclen < 0){
            oxs_error(env, ERROR_LOCATION, OXS_ERROR_ENCRYPT_FAILED,
                      "openssl_block_cipher_crypt FAILED");
            return AXIS2_FAILURE;
        }

        encodedlen = axutil_base64_encode_len(enclen);
        encoded_str = AXIS2_MALLOC(env->allocator, encodedlen);
        ret = axutil_base64_encode_binary(encoded_str, oxs_buffer_get_data(output, env), enclen);
        if (ret < 0)
        {
            oxs_error(env, ERROR_LOCATION, OXS_ERROR_INVALID_DATA,
                      "axutil_base64_encode_binary failed");
            return AXIS2_FAILURE;
        }

        /*Attach the result to the result buf*/
        ret = oxs_buffer_populate(result, env, (unsigned char*)axutil_strdup(env, encoded_str), encodedlen);

        /*Free*/
        oxs_buffer_free(output, env);
        output = NULL;
        AXIS2_FREE(env->allocator, encoded_str);
        encoded_str = NULL;

        /*DECRYPTION*/
    }else if(oxs_ctx_get_operation(enc_ctx, env) == OXS_CTX_OPERATION_DECRYPT){
        unsigned char *decoded_data = NULL;/*Can be binary*/
        int decoded_len = -1;
        int enclen = -1;
        int x=-1;
        oxs_buffer_t *decoded_buf = NULL;

        decoded_buf = oxs_buffer_create(env);

        /*First we need to base64 decode*/
        x =  axutil_base64_decode_len((const char*)oxs_buffer_get_data(input, env));
        decoded_data = AXIS2_MALLOC(env->allocator, x);
        decoded_len = axutil_base64_decode_binary(decoded_data, (char*)oxs_buffer_get_data(input, env) );
        if (decoded_len < 0)
        {
            oxs_error(env, ERROR_LOCATION, OXS_ERROR_DECRYPT_FAILED,
                      "axutil_base64_decode_binary failed");
            return AXIS2_FAILURE;
        }
        /*Populate decoded (input to the crypto function) buffer*/
        ret = oxs_buffer_populate(decoded_buf, env, decoded_data, decoded_len);
        /*Then we decrypt*/
        enclen = openssl_bc_crypt(env, oc_ctx, decoded_buf, result, OPENSSL_DECRYPT);

        if(enclen < 0){
            oxs_error(env, ERROR_LOCATION, OXS_ERROR_DECRYPT_FAILED,
                      "openssl_block_cipher_crypt FAILED");
            return AXIS2_FAILURE;
        }
        /*Free*/
        oxs_buffer_free(decoded_buf, env);
        decoded_buf = NULL;
        AXIS2_FREE(env->allocator, decoded_data);
        decoded_data = NULL;

    }else{
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_INVALID_DATA,
                  "Invalid operation type %d", oxs_ctx_get_operation(enc_ctx, env));
        return AXIS2_FAILURE;
    }

    /*Free*/
    AXIS2_FREE(env->allocator, iv);
    iv = NULL;
    openssl_cipher_ctx_free(oc_ctx, env);
    oc_ctx = NULL;
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN  axis2_status_t AXIS2_CALL
oxs_encryption_asymmetric_crypt(const axutil_env_t *env,
                                oxs_asym_ctx_t *ctx,
                                oxs_buffer_t *input,
                                oxs_buffer_t *result)
{
    openssl_pkey_t *pkey = NULL;
    oxs_asym_ctx_operation_t operation = -1;
    axis2_status_t status = AXIS2_FAILURE;
    axis2_char_t *password = NULL;
    axis2_char_t *algorithm = NULL;
    axis2_char_t *padding = NULL;

    algorithm = oxs_asym_ctx_get_algorithm(ctx, env);
    /* We support RSA v1.5 encryption only. If any other algorithm is specified, replace it with the proper one
    if(0 != (axutil_strcmp(OXS_HREF_RSA_PKCS1, algorithm ))) {
        oxs_asym_ctx_set_algorithm(ctx, env, OXS_HREF_RSA_PKCS1);
    }*/

    /*Set the proper padding for the algorithm*/
    if(0 == (axutil_strcmp(OXS_HREF_RSA_OAEP, algorithm))){
        padding = OPENSSL_RSA_PKCS1_OAEP_PADDING;
    }else if(0 == (axutil_strcmp(OXS_HREF_RSA_PKCS1, algorithm))){
        padding = OPENSSL_RSA_PKCS1_PADDING;
    }

    /*Load the key using key manager*/
    password = oxs_asym_ctx_get_password(ctx, env);
    status = oxs_key_mgr_load_key(env, ctx, password);
    if(AXIS2_FAILURE == status){
        return AXIS2_FAILURE;
    }

    /*Check for the operation and call appropriate method*/
    operation = oxs_asym_ctx_get_operation(ctx, env);
    if(   OXS_ASYM_CTX_OPERATION_PUB_ENCRYPT == operation ){
        axis2_char_t *encoded_str = NULL;
        oxs_x509_cert_t *x509_cert = NULL;
        oxs_buffer_t *out_buf = NULL;
        int enclen = -1;
        int encodedlen = -1;
        int ret = -1;

        /*Operation is PUB ENCRYPT; Get the public key from the context*/
        x509_cert = oxs_asym_ctx_get_certificate(ctx, env);
        pkey = oxs_x509_cert_get_public_key(x509_cert, env);

        /*Encrypt using the public key. Then base64 encode and populate the buffer */
        out_buf = oxs_buffer_create(env);
        enclen = openssl_rsa_pub_encrypt(env, pkey, padding, input, out_buf);
        encodedlen = axutil_base64_encode_len(enclen);
        encoded_str = AXIS2_MALLOC(env->allocator, encodedlen);
        ret = axutil_base64_encode(encoded_str, (const char *)oxs_buffer_get_data(out_buf, env), enclen);
        status = oxs_buffer_populate(result, env, (unsigned char*)axutil_strdup(env, encoded_str), encodedlen);

        /*Free*/
        oxs_buffer_free(out_buf, env);
        out_buf = NULL;
        AXIS2_FREE(env->allocator, encoded_str);
        encoded_str = NULL;

    }else if(OXS_ASYM_CTX_OPERATION_PRV_DECRYPT == operation ){
        unsigned char  *decoded_encrypted_str = NULL;
        oxs_buffer_t *dec_enc_buf = NULL;
        int ret = -1;
        int  declen = -1;

        /*Operation id PRV DECRYPT; Get the private key from the context*/
        pkey = oxs_asym_ctx_get_private_key(ctx, env);
        /*Base64 decode first. Then do the decryption and populate the buffer*/
        decoded_encrypted_str = AXIS2_MALLOC(env->allocator, axutil_base64_decode_len((char*)oxs_buffer_get_data(input, env)));
        ret = axutil_base64_decode((char*)decoded_encrypted_str, (char*)oxs_buffer_get_data(input, env));
        dec_enc_buf = oxs_buffer_create(env);
        oxs_buffer_populate(dec_enc_buf, env, decoded_encrypted_str, ret);
        declen = openssl_rsa_prv_decrypt(env, pkey, padding,  dec_enc_buf, result);

        /*Free*/
        AXIS2_FREE(env->allocator, decoded_encrypted_str);
        decoded_encrypted_str = NULL;
        oxs_buffer_free(dec_enc_buf, env);
        dec_enc_buf = NULL;

    }else{
        /**/
    }

    return AXIS2_SUCCESS;
}
