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
#include <openssl_rsa.h>
#include <openssl/rand.h>
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/bio.h>
#include <openssl/rand.h>
#include <oxs_buffer.h>
#include <oxs_error.h>
#include <openssl_pkcs12.h>
#include <openssl_pem.h>

AXIS2_EXTERN axis2_status_t AXIS2_CALL
openssl_pem_buf_read_pkey(const axutil_env_t *env,
                          axis2_char_t *b64_encoded_buf,
                          axis2_char_t *password,
                          openssl_pem_pkey_type_t type,
                          EVP_PKEY **pkey)
{
    unsigned char *buff = NULL;
    BIO *bio = NULL;
    int ilen = 0;

    /*First we need to base64 decode*/
    EVP_ENCODE_CTX ctx;
    int len = 0;
    int ret = 0;
    int decode_len = 0;

    decode_len = axutil_base64_decode_len(b64_encoded_buf);
    buff = AXIS2_MALLOC(env->allocator, decode_len + 1000);

    ilen = axutil_strlen(b64_encoded_buf);
    EVP_DecodeInit(&ctx);
    EVP_DecodeUpdate(&ctx, (unsigned char*)buff, &len,
                     (unsigned char*)b64_encoded_buf, ilen);
    EVP_DecodeFinal(&ctx, (unsigned char*)buff, &ret);
    ret += len;
    if ((bio = BIO_new_mem_buf(buff, ilen)) == NULL)
    {
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_DEFAULT,
                  "BIO memeory allocation failure");
        return AXIS2_FAILURE;
    }
    /*Load*/
    if(OPENSSL_PEM_PKEY_TYPE_PUBLIC_KEY == type){
        *pkey = d2i_PUBKEY_bio(bio, NULL);
    }else{
        *pkey = d2i_PrivateKey_bio(bio, NULL);
    }

    /*Free*/
    BIO_free(bio);
    bio = NULL;
    AXIS2_FREE(env->allocator, buff);
    buff = NULL;

    if(!*pkey){
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_DEFAULT,
                  "private key is NULL");
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
openssl_pem_read_pkey(const axutil_env_t *env,
                      axis2_char_t *filename,
                      axis2_char_t *password,
                      openssl_pem_pkey_type_t type,
                      EVP_PKEY **pkey)
{
    BIO *bio;
    int ret;

    bio = BIO_new_file(filename, "r");

    if(type == OPENSSL_PEM_PKEY_TYPE_PRIVATE_KEY){
        *pkey = PEM_read_bio_PrivateKey(bio, NULL, 0 , password);
    }else if(type == OPENSSL_PEM_PKEY_TYPE_PUBLIC_KEY){
        *pkey = PEM_read_bio_PUBKEY(bio, NULL, 0 , password);
    }else{/*Type unknown*/
        /*Try to read the prv key first*/
        *pkey = PEM_read_bio_PrivateKey(bio, NULL, 0 , password);
        if (!*pkey)
        {
            /*If prv key is not found then read the public key*/
            ret  = BIO_reset(bio);
            *pkey = PEM_read_bio_PUBKEY(bio, NULL, 0 , password);
        }
    }

    ret = BIO_reset(bio);
    ret = BIO_free(bio);
    bio = NULL;
    if(!*pkey){
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}


