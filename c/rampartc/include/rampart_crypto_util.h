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


#include <axutil_utils_defines.h>
#include <axis2_defines.h>
#include <axutil_env.h>

/**
  * @file rampart_crypto_util.h
  * @brief Crypto related utility module
  */
#ifndef RAMPART_CRYPTO_UTIL
#define RAMPART_CRYPTO_UTIL

#ifdef __cplusplus
extern "C" {
#endif

    /**
      * @defgroup Rampart_Crypto_Util
      * @ingroup Rampart_Util
      */


    /**
    * Calculate the hash of concatenated string of followings
    * @param nonce
    * @param created 
    * @param password 
    * @return calculated hash
    */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rampart_crypto_sha1(const axutil_env_t *env,
                        const axis2_char_t *nonce,
                        const axis2_char_t *created,
                        const axis2_char_t *password);


    /* @} */
#ifdef __cplusplus
}
#endif

#endif    /* !RAMPART_CRYPTO_H */
