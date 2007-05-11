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
#include <axutil_env.h>
#include <oxs_buffer.h>
#include <oxs_error.h>
#include <openssl_cipher_ctx.h>
#include <openssl_crypt.h>
#include <openssl_constants.h>
#include <oxs_axutil_utils.h>



axutil_env_t *test_init()
{
    axutil_allocator_t *allocator = axutil_allocator_init(NULL);
    axutil_error_t *error = (axutil_error_t*)axis2_error_create(allocator);
    axutil_env_t *env = axutil_env_create_with_error(allocator, error);
    return env;
}
#if 0
int decrypt(axutil_env_t *env, oxs_buffer_ptr in, unsigned char *key, unsigned char *iv)
{
    openssl_evp_block_cipher_ctx_ptr bc_ctx = NULL;
    oxs_buffer_ptr out = NULL;
    oxs_buffer_ptr decoded_buf = NULL;
    int ret;

    printf("--Decrypt started--------------------------------------------\n");

    out = oxs_create_buffer(env, OXS_BUFFER_INITIAL_SIZE);

    bc_ctx = openssl_evp_block_cipher_ctx_create(env);
    if (!bc_ctx) return(-1);

    /*Set the key*/
    bc_ctx->key = key;
    bc_ctx->key_initialized = 1;

    /*Set the IV*/
    bc_ctx->iv =  iv;

    ret =  openssl_evp_block_cipher_ctx_init(env, bc_ctx,  OPENSSL_DECRYPT, (unsigned char*)OPENSSL_EVP_aes_128_cbc);
    if (ret < 0)
    {
        return -1;
    }

    /*Now Decode */
    decoded_buf = oxs_base64_decode(env, in);
    if (!decoded_buf) return -1;

    ret =    openssl_block_cipher_crypt(env, bc_ctx, decoded_buf, out, OPENSSL_DECRYPT);
    if (ret < 0)
    {
        return -1;
    }

    printf("\nOut Size =\n %d ", out->size);
    printf("\nOut Data =\n %s ", out->data);

    return (0);
}
#endif
int main()
{
    FILE *outf;
    /*FILE *outf2;
    oxs_buffer_ptr encoded_buf = NULL;
    oxs_buffer_ptr out = NULL;
    */
    axutil_env_t *env = NULL;
    oxs_buffer_ptr in = NULL;
    axis2_char_t *plain_text = NULL;
    unsigned char *out_main_buf = NULL , *out_main_buf2 = NULL;

    unsigned char key[EVP_MAX_KEY_LENGTH] = "012345670123456701234567";
    unsigned char iv[EVP_MAX_IV_LENGTH] = "01234567";

    unsigned char *cipher_name = NULL;

    openssl_evp_block_cipher_ctx_ptr bc1_ctx = NULL;
    openssl_evp_block_cipher_ctx_ptr bc2_ctx = NULL;
    int ret, encrypted_len, decrypted_len;


    env = test_init();
    printf("--Testing started Openssl Block Cipher--------------------------------------------\n");
#if 0
    plain_text =  "Upon successful completion, fread() returns the number of ...END"
            "Upon successful completion, fread() returns the number of ...END";
    /*"This is an additional block :)";*/

#else

    plain_text = "PLAINTEXT";
#endif
    in =  oxs_string_to_buffer(env, plain_text);

    cipher_name = (unsigned char*)OPENSSL_EVP_des_ede3_cbc;

    bc1_ctx = openssl_evp_block_cipher_ctx_create(env);
    if (!bc1_ctx) return(-1);
    /*Set the key*/
    bc1_ctx->key = key; /*axutil_strdup(key, env);*/
    bc1_ctx->key_initialized = 1;
    /*Set the IV*/
    bc1_ctx->iv =  axutil_strdup(env, iv);
    ret =  openssl_evp_block_cipher_ctx_init(env, bc1_ctx,
            OPENSSL_ENCRYPT, cipher_name);
    if (ret < 0)
    {
        printf("openssl_evp_block_cipher_ctx_init failed\n");
        return -1;
    }

    ret =    openssl_block_cipher_crypt(env, bc1_ctx,
            in->data, strlen((char*)in->data), &out_main_buf, OPENSSL_ENCRYPT);
    if (ret < 0)
    {
        printf("openssl_block_cipher_crypt OPENSSL_ENCRYPT failed\n");
        return -1;
    }
    encrypted_len = ret;

    printf("\nEncrypted data size =%d \n ", ret);
    outf = fopen("outbuf", "wb");
    fwrite(out_main_buf, 1, ret, outf);

    /*    out = oxs_create_buffer(env, ret);*/

    /*********************Decrypt***********************/
    bc2_ctx = openssl_evp_block_cipher_ctx_create(env);
    if (!bc2_ctx) return(-1);
    /*Set the key*/
    bc2_ctx->key = key; /*axutil_strdup(key, env);*/
    bc2_ctx->key_initialized = 1;
    /*Set the IV*/
    bc2_ctx->iv =  axutil_strdup(env, iv);
    ret =  openssl_evp_block_cipher_ctx_init(env, bc2_ctx,
            OPENSSL_DECRYPT, cipher_name);
    if (ret < 0)
    {
        printf("openssl_evp_block_cipher_ctx_init failed\n");
        return -1;
    }

    ret =    openssl_block_cipher_crypt(env, bc2_ctx,
            out_main_buf, encrypted_len,  &out_main_buf, OPENSSL_DECRYPT);

    if (ret < 0)
    {
        printf("openssl_block_cipher_crypt  OPENSSL_DECRYPT failed\n");
        return -1;
    }
    decrypted_len = ret;

    printf("\nDecrypted data[%d] %s\n ", ret, out_main_buf2);


#if 0
    /*Now Encode */
    encoded_buf = oxs_base64_encode(env, out);

    if (!encoded_buf) return -1;


    printf("\nencrypted_encoded_buf Size =\n %d ", encoded_buf->size);
    printf("\nencrypted_encoded_buf Data =\n %s ", encoded_buf->data);

    /*Now we need to decrypt*/
    /*===============================================================*/

    ret = decrypt(env, encoded_buf, key, iv);
    if (ret < 0) return -1;
#endif
    return (0);
}
