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
#include <openssl/sha.h>
#include <openssl/md5.h>
#include <openssl_digest.h>
#include <axutil_base64.h>
#include <axis2_util.h>

#define SIZE_HASH 32

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
openssl_sha1(const axutil_env_t *env,
             axis2_char_t *input,
             int length)
{
    SHA_CTX c ;
    unsigned char md[SHA_DIGEST_LENGTH];
    axis2_char_t* encoded_str = NULL;

    SHA1_Init(&c);
    SHA1_Update(&c,(unsigned char*)input,length);
    SHA1_Final(md,&c);

    encoded_str = AXIS2_MALLOC(env->allocator, axutil_base64_encode_len(SIZE_HASH));
    axutil_base64_encode(encoded_str, (char*)md, SHA_DIGEST_LENGTH);

    /*AXIS2_LOG_INFO(env->log, "[openssl][sha1-output]\n\n%s\n\n", encoded_str);*/
    return encoded_str;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
openssl_md5(const axutil_env_t *env,
            axis2_char_t *input,
            int length)
{
    MD5_CTX ctx;
    unsigned char md[MD5_DIGEST_LENGTH];
    axis2_char_t* encoded_str = NULL;

    MD5_Init(&ctx);
    MD5_Update(&ctx, (unsigned char*)input,length);
    MD5_Final(md, &ctx);

    encoded_str = AXIS2_MALLOC(env->allocator, MD5_DIGEST_LENGTH);
    axutil_base64_encode(encoded_str, (char*)md, MD5_DIGEST_LENGTH);

    return encoded_str;
}


