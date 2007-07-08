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
#include <oxs_buffer.h>
#include <oxs_key.h>
#include <oxs_error.h>
#include <openssl_cipher_ctx.h>
#include <openssl_sign.h>
#include <openssl_pkey.h>
#include <openssl/evp.h>
#include <openssl/x509.h>
#include <openssl/err.h>
#include <openssl/pem.h>
#include <openssl/ssl.h>
#include <openssl/bio.h>

#define BUFSIZE 64

AXIS2_EXTERN int AXIS2_CALL
openssl_sig_sign(const axutil_env_t *env,
                 openssl_pkey_t *prvkey,
                 oxs_buffer_t *input_buf,
                 oxs_buffer_t *output_buf)
{
    unsigned char sig_buf[4096]; /*Enough for the signature*/
    unsigned int sig_len;
    const EVP_MD*   digest;
    EVP_MD_CTX      md_ctx;
    EVP_PKEY*       pkey = NULL;
    int err, ret;
    /*Get the key*/
    /*open_pkey = oxs_sign_ctx_get_private_key(sign_ctx, env);*/
    pkey = openssl_pkey_get_key(prvkey, env);
    if(!pkey){
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_SIGN_FAILED,"Cannot load the private key" );
    }

    /*TODO: Set the digest according to the signature method*/
    digest = EVP_sha1();

    /*MD Ctx init*/
    EVP_MD_CTX_init(&md_ctx);

    /*Sign init*/
    ret = EVP_SignInit(&md_ctx, digest);
    AXIS2_LOG_INFO(env->log, "[openssl][sig] Signing content %s", oxs_buffer_get_data(input_buf, env) );
    EVP_SignUpdate (&md_ctx, oxs_buffer_get_data(input_buf, env), oxs_buffer_get_size(input_buf, env));
    sig_len = sizeof(sig_buf);
    err = EVP_SignFinal (&md_ctx,
                         sig_buf,
                         &sig_len,
                         pkey);
    if (err != 1) {
        ERR_print_errors_fp (stderr);
    }
    /*Fill the output buffer*/
    oxs_buffer_populate(output_buf, env, sig_buf, sig_len);

    return sig_len;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
openssl_sig_verify(const axutil_env_t *env,
                   openssl_pkey_t *pubkey,
                   oxs_buffer_t *input_buf,
                   oxs_buffer_t *sig_buf)
{
    axis2_status_t status = AXIS2_FAILURE;
    const EVP_MD*   digest;
    EVP_MD_CTX      md_ctx;
    EVP_PKEY*       pkey = NULL;
    int  ret;

    /*Get the publickey*/
    /*cert = oxs_sign_ctx_get_certificate(sign_ctx, env);
    open_pubkey = oxs_x509_cert_get_public_key(cert, env);*/
    pkey = openssl_pkey_get_key(pubkey, env);
    if(!pkey){
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_SIG_VERIFICATION_FAILED,"Cannot load the public key" );
    }
    /*TODO Set the digest according to the signature method*/
    digest = EVP_sha1();

    /*Init MD Ctx*/
    EVP_MD_CTX_init(&md_ctx);

    /*Intialize verification*/
    ret = EVP_VerifyInit(&md_ctx, digest);
    if(ret != 1) {
        /*Error*/
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_SIG_VERIFICATION_FAILED,"EVP_VerifyInit failed" );
        return AXIS2_FAILURE;
    }
    ret = EVP_VerifyUpdate(&md_ctx,  oxs_buffer_get_data(input_buf, env),  oxs_buffer_get_size(input_buf, env));
    if(ret != 1) {
        /*Error*/
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_SIG_VERIFICATION_FAILED,"EVP_VerifyUpdate failed" );
        return AXIS2_FAILURE;
    }

    ret = EVP_VerifyFinal(&md_ctx, oxs_buffer_get_data(sig_buf, env),
                          oxs_buffer_get_size(sig_buf, env),
                          pkey);
    if(ret == 0){
        /*Error. Signature verification FAILED */
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_SIG_VERIFICATION_FAILED,"Signature verification FAILED." );
        status = AXIS2_FAILURE;
    }else if(ret < 0){
        /*Erorr. Some other error*/
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_SIG_VERIFICATION_FAILED,"Error occured while verifying the signature." );
        status = AXIS2_FAILURE;
    }else{
        /*SUCCESS. Det ar bra :-)*/
        AXIS2_LOG_INFO(env->log, "[openssl][sig] Signature verification SUCCESS " );
        status = AXIS2_SUCCESS;
    }

    return status;

}

