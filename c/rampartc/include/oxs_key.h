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

#ifndef OXS_KEY_H
#define OXS_KEY_H


/**
  * @file oxs_key.h
  * @brief represents a Key in OMXMLSecurity 
  */

#include <axis2_defines.h>
#include <oxs_constants.h>
#include <axutil_env.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /*Key is for signing*/
#define OXS_KEY_USAGE_SIGN          0
    /*Key is for verifying signature*/
#define OXS_KEY_USAGE_VERIFY        1
    /*Key is for encrypting */
#define OXS_KEY_USAGE_ENCRYPT       2
    /*Key is for decrypting*/
#define OXS_KEY_USAGE_DECRYPT       3
    /*Key usage is not specified yet*/
#define OXS_KEY_USAGE_NONE          4

#define OXS_KEY_DEFAULT_SIZE        64

    /** Type name for struct  oxs_key */
    typedef struct oxs_key_t oxs_key_t;

    /**
    * Gets data of the key.
    * @param key oxs_key ptr to key
    * @param env pointer to environment struct
    * @return data 
    */

    unsigned char *AXIS2_CALL
    oxs_key_get_data(
        const oxs_key_t *key,
        const axutil_env_t *env);
    /**
    * Gets the name of the key.
    * @param key oxs_key ptr to key
    * @param env pointer to environment struct
    * @return name of the key
    */
    axis2_char_t *AXIS2_CALL
    oxs_key_get_name(
        const oxs_key_t *key,
        const axutil_env_t *env);
    /**
    * Gets the size of the key.
    * @param key oxs_key ptr to key
    * @param env pointer to environment struct
    * @return size of the key
    */
    int AXIS2_CALL
    oxs_key_get_size(
        const oxs_key_t *key,
        const axutil_env_t *env);
    /**
    * Gets the usage of the key.
    * @param key oxs_key ptr to key
    * @param env pointer to environment struct
    * @return usage of the key
    */
    int AXIS2_CALL
    oxs_key_get_usage(
        const oxs_key_t *key,
        const axutil_env_t *env);


    /**
    * Sets the name of the key.
    * @param key oxs_key ptr to key
    * @param env pointer to environment struct
    * @param name name of the key
    * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
    */
    axis2_status_t AXIS2_CALL
    oxs_key_set_name(
        oxs_key_t *key,
        const axutil_env_t *env,
        axis2_char_t *name);


    /**
    * Set the usage of the key.
    * @param key oxs_key ptr to key
    * @param env pointer to environment struct
    * @param usage usage of the key
    * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
    */
    axis2_status_t AXIS2_CALL
    oxs_key_set_usage(
        oxs_key_t *key,
        const axutil_env_t *env,
        int usage);

    /**
    * Free function for key.
    * @param key oxs_key ptr to key
    * @param env pointer to environment struct
    * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
    */
    axis2_status_t AXIS2_CALL
    oxs_key_free(
        oxs_key_t *key,
        const axutil_env_t *env
    );

    /**
    * Populate a key.
    * @param key oxs_key ptr to key
    * @param env pointer to environment struct
    * @param data data of the key
    * @param name name of the key
    * @param size size of the key
    * @param usage usage of the key
    * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
    */
    axis2_status_t AXIS2_CALL
    oxs_key_populate(
        oxs_key_t *key,
        const axutil_env_t *env,
        unsigned char *data,
        axis2_char_t *name,
        int size,
        int usage);

    /**
    * Read a key from a file.
    * @param key oxs_key ptr to key
    * @param env pointer to environment struct
    * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
    */
    axis2_status_t AXIS2_CALL
    oxs_key_read_from_file(
        oxs_key_t *key,
        const axutil_env_t *env,
        axis2_char_t *file_name);

    /**
    * Fill the key for the given algo.
    * @param key oxs_key ptr to key
    * @param env pointer to environment struct
    * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
    */
    axis2_status_t AXIS2_CALL
    oxs_key_for_algo(oxs_key_t *key,
                     const axutil_env_t *env,
                     axis2_char_t *key_algo);


    AXIS2_EXTERN oxs_key_t *AXIS2_CALL
    oxs_key_create(const axutil_env_t *env);


#ifdef __cplusplus
}
#endif

#endif                          /* OXS_KEY_H */
