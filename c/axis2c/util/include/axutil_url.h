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

#ifndef AXUTIL_URL_H
#define AXUTIL_URL_H


/**
  * @file axutil_url.h
  * @brief axis2 URL container implementation
  */

#include <axutil_utils.h>
#include <axutil_utils_defines.h>
#include <axutil_env.h>
#include <axutil_uri.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @ingroup axis2_core_transport_http
     * @{
     */

    typedef struct axutil_url axutil_url_t;

    AXIS2_EXTERN axutil_url_t * AXIS2_CALL
    axutil_url_create(
        const axutil_env_t *env,
        const axis2_char_t *protocol,
        const axis2_char_t *server,
        const int port,
        const axis2_char_t *path);

    AXIS2_EXTERN axutil_url_t * AXIS2_CALL
    axutil_url_parse_string(
        const axutil_env_t *env,
        const axis2_char_t *str_url);

    AXIS2_EXTERN axutil_uri_t *AXIS2_CALL
    axutil_url_to_uri(
        axutil_url_t *url,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    axutil_url_to_external_form(axutil_url_t *url,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_url_set_protocol(axutil_url_t *url,
        const axutil_env_t *env,
        axis2_char_t *protocol);

    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    axutil_url_get_protocol(axutil_url_t *url,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_url_set_server(axutil_url_t *url,
        const axutil_env_t *env,
        axis2_char_t *server);

    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    axutil_url_get_server(axutil_url_t *url,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_url_set_port(axutil_url_t *url,
        const axutil_env_t *env,
        int port);

    AXIS2_EXTERN int AXIS2_CALL
    axutil_url_get_port(axutil_url_t *url,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_url_set_path(axutil_url_t *url,
        const axutil_env_t *env,
        axis2_char_t *path);

    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    axutil_url_get_path(axutil_url_t *url,
        const axutil_env_t *env);

    AXIS2_EXTERN axutil_url_t* AXIS2_CALL
    axutil_url_clone(axutil_url_t *url,
        const axutil_env_t *env);

    AXIS2_EXTERN void AXIS2_CALL
    axutil_url_free(axutil_url_t *url,
        const axutil_env_t *env);

    /** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* AXIS2_URL_H */

