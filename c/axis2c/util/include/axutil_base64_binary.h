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

#ifndef AXUTIL_BASE64_BINARY_H
#define AXUTIL_BASE64_BINARY_H

#include <axutil_base64.h>
#include <axutil_utils_defines.h>
#include <axutil_env.h>

/**
 * @defgroup axutil_base64_binary encoding holder
 * @ingroup axis2_util
 * @{
 */

/**
 * @file axutil_base64_binary.h
 * @brief axis2-util base64 encoding holder
 */

#ifdef __cplusplus
extern "C"
{
#endif

    /** Type name for struct axutil_base64_binary */
    typedef struct axutil_base64_binary axutil_base64_binary_t;

    /**
     * Creates axutil_base64_binary struct
     * @param env double pointer to environment struct. MUST NOT be NULL
     * @return pointer to newly created axutil_base64_binary struct
     */
    AXIS2_EXTERN axutil_base64_binary_t* AXIS2_CALL
    axutil_base64_binary_create(
        const axutil_env_t *env);

    /**
     * Creates axutil_base64_binary struct
     * @param env double pointer to environment struct. MUST NOT be NULL
     * @param plain_binary binary buffer to initialize
     * @return pointer to newly created axutil_base64_binary struct
     */
    AXIS2_EXTERN axutil_base64_binary_t* AXIS2_CALL
    axutil_base64_binary_create_with_plain_binary(
        const axutil_env_t *env,
        const unsigned char *plain_binary,
        int plain_binary_len);

    /**
     * Creates axutil_base64_binary struct.
     * @param env double pointer to environment struct. MUST NOT be NULL
     * @param encoded_binary binary buffer to initialize 
     * @return pointer to newly created axutil_base64_binary struct
     */
    AXIS2_EXTERN axutil_base64_binary_t* AXIS2_CALL
    axutil_base64_binary_create_with_encoded_binary(
        const axutil_env_t *env,
        const char *encoded_binary);

    /**
     * free the axutil_base64_binary.
     * @param base64_binary represet the type object
     * @param env pointer to environment struct. MUST NOT be NULL
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN void AXIS2_CALL 
    axutil_base64_binary_free(axutil_base64_binary_t *base64_binary,
        const axutil_env_t *env);

    /**
     * store the value from plain binary.
     * @param base64_binary represet the type object
     * @param env pointer to environment struct. MUST NOT be NULL
     * @param plain_binary binary buffer to store
     * @param plain_binary_len length of the plain_binary binary buffer
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL 
    axutil_base64_binary_set_plain_binary(axutil_base64_binary_t *base64_binary,
        const axutil_env_t *env,
        const unsigned char* plain_binary,
        int plain_binary_len);

    /**
     * retrieve the value from plain binary.
     * @param base64_binary represet the type object
     * @param env pointer to environment struct. MUST NOT be NULL
     * @param plain_binary_len length of the plain_binary binary buffer
     * @return the plain binary
     */

    AXIS2_EXTERN unsigned char* AXIS2_CALL 
    axutil_base64_binary_get_plain_binary(axutil_base64_binary_t *base64_binary,
        const axutil_env_t *env,
        int* plain_binary_len);

    /**
     * store the value from encoded binary.
     * @param base64_binary represet the type object
     * @param env pointer to environment struct. MUST NOT be NULL
     * @param encoded_binary encoded binary buffer to store
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL 
    axutil_base64_binary_set_encoded_binary(axutil_base64_binary_t *base64_binary,
        const axutil_env_t *env,
        const char* encoded_binary);

    /**
     * retrieve the value from encoded binary.
     * @param base64_binary represet the type object
     * @param env pointer to environment struct. MUST NOT be NULL
     * @return the encoded binary
     */
    AXIS2_EXTERN char* AXIS2_CALL 
    axutil_base64_binary_get_encoded_binary(axutil_base64_binary_t *base64_binary,
        const axutil_env_t *env);

    /**
     * retrieve the value from encoded binary length.
     * @param base64_binary represet the type object
     * @param env pointer to environment struct. MUST NOT be NULL
     * @return the encoded binary length
     */
    AXIS2_EXTERN int AXIS2_CALL 
    axutil_base64_binary_get_encoded_binary_len(axutil_base64_binary_t *base64_binary,
        const axutil_env_t *env);

    /**
     * retrieve the value from decoded binary length.
     * @param base64_binary represet the type object
     * @param env pointer to environment struct. MUST NOT be NULL
     * @return the decoded binary length
     */
    AXIS2_EXTERN int AXIS2_CALL 
    axutil_base64_binary_get_decoded_binary_len(axutil_base64_binary_t *base64_binary,
        const axutil_env_t *env);

#ifdef __cplusplus
}
#endif

#endif /* AXIS2_BASE64_BINARY_H */
