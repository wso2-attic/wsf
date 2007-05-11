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
#include <oxs_error.h>
#include <oxs_buffer.h>
#include <oxs_cipher.h>
#include <oxs_sign_ctx.h>
#include <oxs_signature.h>
#include <oxs_buffer.h>
#include <openssl_rsa.h>
#include <openssl_sign.h>
#include <openssl_digest.h>

/*Private functions*/
AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_sig_sign_rsa_sha1(const axutil_env_t *env,
                      oxs_sign_ctx_t *sign_ctx,
                      oxs_buffer_t *input,
                      oxs_buffer_t *output)
{
    axis2_char_t *encoded_str = NULL;
    axis2_status_t status = AXIS2_FAILURE;
    oxs_buffer_t *signed_result_buf = NULL;
    openssl_pkey_t *prvkey = NULL;
    int signedlen = -1, encodedlen = -1, ret = -1;

    /*Create output buffer to store signed data*/
    signed_result_buf = oxs_buffer_create(env);

    /*Sign */
    prvkey = oxs_sign_ctx_get_private_key(sign_ctx, env);
    signedlen = openssl_sig_sign(env, prvkey, input, signed_result_buf);
    if(signedlen < 0){
        /*Error*/
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_SIGN_FAILED,
                  "Signature failed. The length of signature is %d", signedlen);
    }

    /*Base64 encode*/
    encodedlen = axutil_base64_encode_len(signedlen);
    encoded_str = AXIS2_MALLOC(env->allocator, encodedlen);
    ret = axutil_base64_encode(encoded_str, (const char *)oxs_buffer_get_data(signed_result_buf, env), signedlen);
    status = oxs_buffer_populate(output, env, (unsigned char*)axutil_strdup(env, encoded_str), encodedlen);

    /*Free signed_result_buf*/

    return AXIS2_SUCCESS;
}


/*Public functions*/
AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_sig_sign(const axutil_env_t *env,
             oxs_sign_ctx_t *sign_ctx,
             oxs_buffer_t *input,
             oxs_buffer_t *output)
{
    axis2_char_t *sign_algo = NULL;


    /*Get algo*/
    sign_algo = oxs_sign_ctx_get_sign_mtd_algo(sign_ctx, env);

    /*Prepare content and sign*/
    if(0==(axutil_strcmp(sign_algo, OXS_HREF_RSA_SHA1))){
        oxs_sig_sign_rsa_sha1(env, sign_ctx, input, output);
    }else if(0==(axutil_strcmp(sign_algo, OXS_HREF_DSA_SHA1))){
        /*Error we do not support*/
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_INVALID_DATA,
                  "Cannot support cipher %s", sign_algo);
        return AXIS2_FAILURE;
    }else{
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_INVALID_DATA,
                  "Cannot support cipher %s", sign_algo);
        return AXIS2_FAILURE;
    }


    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_sig_verify(const axutil_env_t *env,
               oxs_sign_ctx_t *sign_ctx,
               axis2_char_t *content,
               axis2_char_t *signature)
{
    axis2_status_t status = AXIS2_FAILURE;
    oxs_buffer_t *in_buf =  NULL;
    oxs_buffer_t *sig_buf =  NULL;
    openssl_pkey_t *pubkey = NULL;

    unsigned char* decoded_data = NULL;
    int decoded_len = -1;
    int ret = -1;

    /*Base64 decode the signature value and create the sig buffer*/
    /*Allocate enough space*/
    decoded_data = AXIS2_MALLOC(env->allocator, axutil_base64_decode_len(signature));
    decoded_len = axutil_base64_decode_binary(decoded_data, signature );
    if (decoded_len < 0)
    {
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_SIG_VERIFICATION_FAILED,
                  "axutil_base64_decode_binary failed");
        return AXIS2_FAILURE;
    }

    /*Create the signature buffer*/
    sig_buf = oxs_buffer_create(env);
    ret = oxs_buffer_populate(sig_buf, env, decoded_data, decoded_len);

    /*Create the input buffer*/
    in_buf = oxs_buffer_create(env);
    status = oxs_buffer_populate(in_buf, env, (unsigned char*)content, axutil_strlen(content));

    /*Get the public key. See.. this method is trickey. It might take the public key from the certificate, only if
     * the public key is not available directly*/
    pubkey = oxs_sign_ctx_get_public_key(sign_ctx, env);
    if(!pubkey){
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_SIG_VERIFICATION_FAILED,"Cannot obtain the public key.");
        return AXIS2_FAILURE;
    }

    /*Call OpenSSL function to verify the signature*/
    status = openssl_sig_verify(env, pubkey, in_buf, sig_buf);
    if(AXIS2_SUCCESS != status){
        /*Error in signature processing*/
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_SIG_VERIFICATION_FAILED,"Signature verification FAILED.");
        return AXIS2_FAILURE;
    }else{

        AXIS2_LOG_INFO(env->log, "[oxs][sig] Signature verification SUCCESS " );
        return AXIS2_SUCCESS;
    }

}
