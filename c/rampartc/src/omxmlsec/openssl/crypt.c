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
#include <openssl_crypt.h>
#include <openssl/rand.h>

#define BUFSIZE 64

AXIS2_EXTERN int AXIS2_CALL
openssl_bc_crypt(const axutil_env_t *env,
                 openssl_cipher_ctx_t *oc_ctx,
                 oxs_buffer_t *input_buf,
                 oxs_buffer_t *output_buf,
                 int encrypt)
{
    EVP_CIPHER_CTX ctx ;
    oxs_key_t *okey = NULL;

    unsigned char iv[EVP_MAX_IV_LENGTH];
    unsigned char key[EVP_MAX_KEY_LENGTH];
    int ret =0, iv_length =0, block_length =0;
    int last = 0;
    axis2_status_t status = AXIS2_FAILURE;

    /********************************Initialize*****************************************************/

    iv_length = EVP_CIPHER_iv_length(openssl_cipher_ctx_get_cipher(oc_ctx, env));

    /*Get the IV. If encrypt, we need to generate the IV else we need to get it from the input buffer*/
    if(encrypt){
        /*Generate IV*/
        ret = RAND_bytes(iv, iv_length);
        /*IV to the output*/
        status = oxs_buffer_append(output_buf, env, iv, iv_length);
    }else{ /*Decrypt*/
        /*If data is less than the IV its an error*/
        if(oxs_buffer_get_size(input_buf, env) < iv_length){
            return -1;
        }
        /*Copy IV from the inbuf to our buffer*/
        memcpy(iv, oxs_buffer_get_data(input_buf, env), iv_length);
        /*And remove from input*/
        status = oxs_buffer_remove_head (input_buf, env, iv_length);
    }
    /*Get key*/
    okey = openssl_cipher_ctx_get_key(oc_ctx, env);
    memcpy(key,  oxs_key_get_data(okey, env), oxs_key_get_size(okey, env));

    /*Set the IV */
    ret = EVP_CipherInit(&ctx, (EVP_CIPHER *)openssl_cipher_ctx_get_cipher(oc_ctx, env), key, iv, encrypt);
#ifndef OXS_OPENSSL_096
    EVP_CIPHER_CTX_set_padding(&ctx, 0);
#endif

    /*Get the block length of the cipher*/
    block_length = EVP_CIPHER_block_size((EVP_CIPHER *)openssl_cipher_ctx_get_cipher(oc_ctx, env));

    /*********************************Update***********************************************************/
    for(;;){/*Loop untill all the data are encrypted*/
        unsigned char *out_buf = NULL;
        int  in_size =0, out_size =0, fixed=0, out_length = 0;

    if (0 == oxs_buffer_get_size(input_buf, env)) {
            last = 1;
            break; /*Quit loop if NO DATA!!! */
        }

        /*If the amnt of data available is greater than the buffer size, we limit it to buffer size */
        if(oxs_buffer_get_size(input_buf, env) > BUFSIZE){
            in_size = BUFSIZE;
        }else{
            in_size = oxs_buffer_get_size(input_buf, env);
        }

        out_size = oxs_buffer_get_size(output_buf, env);

        /*Set the output buffer size*/
        status = oxs_buffer_set_max_size(output_buf, env, out_size + in_size + block_length);

        out_buf = oxs_buffer_get_data(output_buf, env) + out_size;        /*position to write*/

#ifndef OXS_OPENSSL_096
        /*If decrypt, we copy the final data to the out_buf of size block_length*/
        if(!ctx.encrypt) {
            if(ctx.final_used) {
                memcpy(out_buf, ctx.final, block_length);
                out_buf += block_length;
                fixed = 1;
        }else {
            fixed = 0;
        }
    }
#endif
    /* encrypt or decrypt */
    ret = EVP_CipherUpdate(&ctx, out_buf, &out_length, oxs_buffer_get_data(input_buf, env), in_size);

#ifndef OXS_OPENSSL_096
        /*If decrypt, we copy data from the out_buf to the ctx.final*/
        if(!ctx.encrypt) {
            if (block_length > 1 && !ctx.buf_len) {
                out_length -= block_length;
                ctx.final_used = 1;
                memcpy(ctx.final, &out_buf[out_length], block_length);
            } else {
                ctx.final_used = 0;
            }
            if (fixed) {
                out_length += block_length;
            }
        }
#endif
        /* set correct output buffer size */
        status = oxs_buffer_set_size(output_buf, env, out_size + out_length);
        if(AXIS2_FAILURE == status){
            return -1;
        }
        /* remove the processed block from input */
        status = oxs_buffer_remove_head(input_buf, env, in_size);
        if(AXIS2_FAILURE == status){
            return -1;
        }

    }/*End of for loop*/

    /********************************Finalize*****************************************************/

    /* by now there should be no input */
    if(last == 1){
        unsigned char pad[EVP_MAX_BLOCK_LENGTH];
        unsigned char *out_buf = NULL;
        int out_size = 0,  out_length = 0, out_length2 = 0;

        out_size = oxs_buffer_get_size(output_buf, env);
        status = oxs_buffer_set_max_size(output_buf,  env, out_size + 2 * block_length);
        out_buf = oxs_buffer_get_data(output_buf, env)  + out_size;/*position to write*/
#ifndef OXS_OPENSSL_096
        if(encrypt){
            int pad_length;
            pad_length = block_length - ctx.buf_len;
            /* generate random padding */
            if(pad_length > 1) {
                ret = RAND_bytes(pad, pad_length - 1);
            }
            pad[pad_length - 1] = pad_length;
            /* write padding */
            ret = EVP_CipherUpdate(&ctx, out_buf, &out_length, pad, pad_length);
            out_buf += out_length;
        }
#endif
        /* finalize  */
        ret = EVP_CipherFinal(&ctx, out_buf, &out_length2);
#ifndef OXS_OPENSSL_096
        if(!encrypt){
            if(block_length > 1) {
                out_length2 = block_length - ctx.final[block_length - 1];
                if(out_length2 > 0) {
                    memcpy(out_buf, ctx.final, out_length2);
                } else if(out_length2 < 0) {
                    return(-1);
                }
            }
        }
#endif
        /* set correct output buffer size */
        status = oxs_buffer_set_size(output_buf, env, out_size + out_length + out_length2);

        EVP_CIPHER_CTX_cleanup(&ctx);
        /*return the length of the outputbuf*/
        return out_size + out_length + out_length2;
    }else{
        return -1;
    }

}

