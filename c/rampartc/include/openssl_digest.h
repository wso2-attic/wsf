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

#include <openssl/sha.h>

#include <axutil_utils_defines.h>
#include <axis2_defines.h>
#include <axutil_env.h>

/**
  * @file openssl_digest.h
  * @brief 
  */
#ifndef OPENSSL_DIGEST
#define OPENSSL_DIGEST

#ifdef __cplusplus
extern "C" {
#endif

    /**
      * @defgroup 
      * @ingroup 
      */


    /**
    * Calculate the digest of the input
    * @return calculated digest
    */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    openssl_sha1(const axutil_env_t *env,
                 axis2_char_t *input,
                 int length);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    openssl_md5(const axutil_env_t *env,
                axis2_char_t *input,
                int length);
    /* @} */
#ifdef __cplusplus
}
#endif

#endif    /* OPENSSL_DIGEST */
