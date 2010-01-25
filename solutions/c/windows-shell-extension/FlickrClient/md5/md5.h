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

#ifndef AXUTIL_MD5_H
#define AXUTIL_MD5_H

/**
 * @file axutil_md5.h
 * @brief MD5 Implementation for Axis2 based on rfc1321.
 */

#include <axutil_utils_defines.h>
#include <axutil_env.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /** 
     * @defgroup axis2_util utilities
     * @ingroup axis2
     * @{
     * @}
     */

    /**
     * @defgroup axutil_md5 md5
     * @ingroup axis2_util
     * @{
     */

    /** The MD5 digest size */
    #define AXIS2_MD5_DIGESTSIZE 16

    typedef struct axutil_md5_ctx
    {
        /** state (ABCD) */
        unsigned int state[4];
        /** number of bits, modulo 2^64 (lsb first) */
        unsigned int count[2];
        /** input buffer */
        unsigned char buffer[64];
    }
    axutil_md5_ctx_t;

    /**
     * Creates md5_ctx struct, which is used for the MD5 message-digest
     * operation. Initialization of the struct is done during the creation
     * process.
     * @param env, pointer to the env struct.
     * @return pointer to md5_ctx struct created.
     */ 
    AXIS2_EXTERN axutil_md5_ctx_t *AXIS2_CALL
    axutil_md5_ctx_create(
        const axutil_env_t * env);

    /** 
     * Frees the md5_ctx struct
     * @param md5_ctx, pointer to struct to free.
     * @param env, pointer to the env struct.
     */
    AXIS2_EXTERN void AXIS2_CALL
    axutil_md5_ctx_free(
        axutil_md5_ctx_t * md5_ctx,
        const axutil_env_t * env);

    /**
     * MD5 block update operation. Continue an MD5 message-digest operation, 
     * processing another message block, and updating the context.
     * @param context The MD5 content to update.
     * @param env, pointer to the env struct.
     * @param input_str next message block to update
     * @param inputLen The length of the next message block
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_md5_update(
        axutil_md5_ctx_t *context,
        const axutil_env_t * env,
        const void *input_str,
        size_t inputLen);

    /**
     * MD5 finalization. Ends an MD5 message-digest operation, writing the 
     * message digest and zeroing the context.
     * @param digest The final MD5 digest.
     * @param env, pointer to the env struct.
     * @param context The MD5 content we are finalizing.
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_md5_final(
        axutil_md5_ctx_t *context,
        const axutil_env_t * env,
        unsigned char digest[AXIS2_MD5_DIGESTSIZE]);

    /**
     * MD5 in one step.
     * @param env, pointer to the env struct.
     * @param digest The final MD5 digest.
     * @param input_str The message block to use.
     * @param inputLen The length of the message block.
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_md5(
         const axutil_env_t * env, 
         unsigned char digest[AXIS2_MD5_DIGESTSIZE],
         const void *input_str,
         size_t inputLen);

    /** @} */

#ifdef __cplusplus
}
#endif

#endif /* AXIS2_MD5_H */
