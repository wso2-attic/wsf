/*
 *   Copyright 2003-2004 The Apache Software Foundation.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 */

#include <axis2_util.h>

/**
  * @file 
  * @brief 
  */
#ifndef OPENSSL_CONSTANTS_H
#define OPENSSL_CONSTANTS_H

#ifdef __cplusplus
extern "C" {
#endif

#define OPENSSL_ENCRYPT             1
#define OPENSSL_DECRYPT             0
#define OPENSSL_LEAVE_UNCHANGED     -1

    /**Supported Ciphers *************/

#define OPENSSL_EVP_des_ede3_cbc     "EVP_des_ede3_cbc"
#define OPENSSL_EVP_aes_128_cbc      "EVP_aes_128_cbc"
#define OPENSSL_EVP_aes_192_cbc      "EVP_aes_192_cbc"
#define OPENSSL_EVP_aes_256_cbc      "EVP_aes_256_cbc"

#define OPENSSL_RSA_ENCRYPTION      "rsaEncryption"
#define OPENSSL_RSA_PKCS1_PADDING    "RSA_PKCS1_PADDING"
#define OPENSSL_RSA_PKCS1_OAEP_PADDING     "RSA_PKCS1_OAEP_PADDING"

#define OPENSSL_DEFAULT_IV8          "01234567"
#define OPENSSL_DEFAULT_IV16         "0123456701234567"
#define OPENSSL_DEFAULT_IV24         "012345670123456701234567"


#ifdef __cplusplus
}
#endif

#endif    /* OPENSSL_CONSTANTS_H */
