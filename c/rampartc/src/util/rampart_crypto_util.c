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


/* Rampart_crypto_util will contain crypto functionalities of the rampart model
 *
 */
#include <stdio.h>
#include <rampart_crypto_util.h>
#include <axis2_util.h>
#include <axutil_base64.h>
#include <openssl_digest.h>

/*Calculate the hash of concatenated string of
 * nonce, created and the password.
 *
 */

AXIS2_EXTERN axis2_char_t* AXIS2_CALL rampart_crypto_sha1(const axutil_env_t *env,
        const axis2_char_t *nonce,
        const axis2_char_t *created,
        const axis2_char_t *password)
{
    char* input = NULL;
    axis2_char_t* digest = NULL;
    axis2_char_t* decoded_nonce = NULL;
    int decoded_nonce_length = 0;

    /*Decode the nonce first*/
    if(nonce){
        int ret;
        decoded_nonce_length = axutil_base64_decode_len(nonce);
        decoded_nonce = AXIS2_MALLOC(env->allocator, axutil_base64_decode_len(nonce));
        ret = axutil_base64_decode(decoded_nonce, nonce);
    }

    if ((!nonce) && (!created))
    {/*If both nonce and created are omitted*/
        input = AXIS2_MALLOC(env->allocator,  axutil_strlen(password) + 1);
        sprintf(input, "%s",  password);
    }
    else if (!nonce)
    {/*If nonce is omitted*/
        input = AXIS2_MALLOC(env->allocator, axutil_strlen(created) + axutil_strlen(password) + 1);
        sprintf(input, "%s%s",  created, password);
    }
    else  if (!created)
    {/*If created is omitted*/
        input = AXIS2_MALLOC(env->allocator, decoded_nonce_length + axutil_strlen(password) + 1);
        sprintf(input, "%s%s",  decoded_nonce, password);
    }
    else
    {/*If all nonce, created and password are present*/
        input = AXIS2_MALLOC(env->allocator,
                             decoded_nonce_length + axutil_strlen(created) + axutil_strlen(password) + 1);
        sprintf(input, "%s%s%s", decoded_nonce, created, password);
    }

    digest = openssl_sha1(env, input, axutil_strlen(input));
    AXIS2_FREE(env->allocator, input);
    AXIS2_FREE(env->allocator, decoded_nonce);
    return digest;
}
