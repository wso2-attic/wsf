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
#include <openssl_rsa.h>
#include <openssl_digest.h>
#include <openssl_constants.h>
#include <oxs_axutil_utils.h>

axutil_env_t *test_init()
{
    axutil_allocator_t *allocator = axutil_allocator_init(NULL);
    axutil_error_t *error = (axutil_error_t*)axis2_error_create(allocator);
    axutil_env_t *env = axutil_env_create_with_error(allocator, error);
    return env;
}

int md5(){
    axutil_env_t *env = NULL;
    axis2_char_t *plaintext = NULL;

    env = test_init();
    plaintxt = (unsigned char *)"We will we will rock ya...";

    openssl_md5(env, plaintxt , axutil_strlen(plaintxt));    
    printf("Finish  md5() \n");
    return 0;
}

int encdec()
{
    axutil_env_t *env = NULL;
    evp_pkey_ptr pubk, prvk = NULL;
    unsigned char *plaintxt = NULL, *encrypted = NULL, *decrypted = NULL;
    oxs_buffer_ptr randkey = NULL;
    int ret;


    env = test_init();
    plaintxt = (unsigned char *)"We will we will rock ya...";

    /******************/
    /* ret = generate_random_key(env, randkey, 24 );
     if(ret < 0 ){
         printf("Error generating random key  \n");
         return ret;
     }else{
         printf("Generated random key is %s", randkey->data);
     }*/
    /******************/


    pubk = evp_pkey_load(env, "rsapub.pem", "");
    ret = openssl_rsa_pub_encrypt(env, pubk, plaintxt, &encrypted);
    if (ret < 0)
    {
        printf("Encryption error \n");
        return ret;
    }

    printf("Encrypted text = [%d]\n", ret);

    prvk = evp_pkey_load(env, "rsakey.pem", "");
    ret = openssl_rsa_prv_decrypt(env, prvk, encrypted, &decrypted);
    if (ret < 0)
    {
        printf("Decryption error \n");
        return ret;
    }
    printf("Decrypted text = [%d]\n%s\n", ret, decrypted);
    return 0;
}




int main()
{
/*    return encdec();*/
    return md5();

}
