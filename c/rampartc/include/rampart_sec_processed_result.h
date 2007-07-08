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


#include <rampart_constants.h>
#include <axutil_utils_defines.h>
#include <axis2_defines.h>
#include <axutil_env.h>

/**
  * @file rampart_sec_processed_result.h
  * @brief The module to keep  the results after processing the message 
  */
#ifndef RAMPART_SEC_PROCESSED_RESULT
#define RAMPART_SEC_PROCESSED_RESULT

#ifdef __cplusplus
extern "C" {
#endif

    /**
      * @defgroup Rampart_Util
      * @ingroup Rampart_Util
      */
    /**
    *   Set a security processed result to the message context
    */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_set_security_processed_result(const axutil_env_t *env,
                                          axis2_msg_ctx_t *msg_ctx,
                                          axis2_char_t *key,
                                          void *value);
    /**
    *   Get a security processed result from a message context.
    *   A service  may use this method to retirieve a particular result by the key
    *   @env the environment 
    *   @msg_ctx the message context in which data are extracted
    *   @key as specified in rampart_constants section SPR
    *
    */
    AXIS2_EXTERN void *AXIS2_CALL
    rampart_get_security_processed_result(const axutil_env_t *env,
                                          axis2_msg_ctx_t *msg_ctx,
                                          axis2_char_t *key);

    /**
    *   Set a security processed result property to the message context
    *   @env the environment 
    *   @msg_ctx the message context in which data are extracted
    */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_set_security_processed_results_property(const axutil_env_t *env,
            axis2_msg_ctx_t *msg_ctx);

    /**
    *   Get the complete set of security processed results
    *   @env the environment 
    *   @msg_ctx the message context in which data are extracted
    */
    AXIS2_EXTERN axutil_hash_t* AXIS2_CALL
    rampart_get_all_security_processed_results(const axutil_env_t *env,
            axis2_msg_ctx_t *msg_ctx);

    /**
     * Prints all ke/val pairs in the security processed results
     *   @env the environment 
     *   @msg_ctx the message context in which data are extracted
     *
     */
    AXIS2_EXTERN void AXIS2_CALL
    rampart_print_security_processed_results_set(const axutil_env_t *env,
            axis2_msg_ctx_t *msg_ctx);

    /* @} */
#ifdef __cplusplus
}
#endif

#endif    /* !RAMPART_SEC_PROCESSED_RESULT */
