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

#ifndef AXIS2_HTTP_REQUEST_LINE_H
#define AXIS2_HTTP_REQUEST_LINE_H

/**
 * @defgroup axis2_http_request_line http request line
 * @ingroup axis2_core_trans_http
 * @{
 */

/**
 * @file axis2_http_request_line.h
 * @brief axis2 HTTP Request Line
 */

#include <axis2_const.h>
#include <axis2_defines.h>
#include <axutil_env.h>


#ifdef __cplusplus
extern "C"
{
#endif

    /** Type name for struct axis2_http_request_line */
    typedef struct axis2_http_request_line axis2_http_request_line_t;

    /**
     * @param request_line pointer to request line
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
	axis2_http_request_line_get_method(const axis2_http_request_line_t *request_line,
		const axutil_env_t *env);

    /**
     * @param request_line pointer to request line
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    axis2_http_request_line_get_http_version(const axis2_http_request_line_t *request_line,
        const axutil_env_t *env);

    /**
     * @param request_line pointer to request line
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    axis2_http_request_line_get_uri(const axis2_http_request_line_t *request_line,
        const axutil_env_t *env);

    /**
     * @param request_line pointer to request line
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    axis2_http_request_line_to_string(axis2_http_request_line_t *request_line,
        const axutil_env_t *env);

    /**
     * @param request_line pointer to request line
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_http_request_line_free(axis2_http_request_line_t *request_line,
        const axutil_env_t *env);

	/**
     * @param env pointer to environment struct
     * @param method pointer to method
     * @param uri pointer to uri
     * @param http_version pointer to http version
     */
    AXIS2_EXTERN axis2_http_request_line_t *AXIS2_CALL
    axis2_http_request_line_create(const axutil_env_t *env,
        const axis2_char_t *method,
        const axis2_char_t *uri,
        const axis2_char_t *http_version);

    /**
     * @param env pointer to environment struct
     * @param str pointer to str
     */
    AXIS2_EXTERN axis2_http_request_line_t *AXIS2_CALL
    axis2_http_request_line_parse_line(const axutil_env_t *env,
        const axis2_char_t *str);


/** @} */
#ifdef __cplusplus
}
#endif
#endif /* AXIS2_HTTP_REQUEST_LINE_H */
