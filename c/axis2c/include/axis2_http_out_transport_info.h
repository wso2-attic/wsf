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

#ifndef AXIS2_HTTP_OUT_TRANSPORT_INFO_H
#define AXIS2_HTTP_OUT_TRANSPORT_INFO_H

/**
 * @defgroup axis2_http_out_transport_info http out transport info
 * @ingroup axis2_core_trans_http
 * Description
 * @{
 */

/**
 * @file axis2_http_out_transport_info.h
 * @brief axis2 HTTP Out Transport Info
 */

#include <axis2_const.h>
#include <axis2_defines.h>
#include <axutil_env.h>
#include <axis2_http_simple_response.h>


#ifdef __cplusplus
extern "C"
{
#endif

    /** Type name for struct axis2_http_out_transport_info */
    typedef struct axis2_http_out_transport_info axis2_http_out_transport_info_t;

	struct axis2_http_out_transport_info
	{
		axis2_http_simple_response_t *response;
		axis2_char_t *encoding;

		axis2_status_t (AXIS2_CALL *
        set_content_type)(axis2_http_out_transport_info_t *info,
			const axutil_env_t *env,
			const axis2_char_t *content_type);

		axis2_status_t (AXIS2_CALL *
        set_char_encoding)(axis2_http_out_transport_info_t *info,
			const axutil_env_t *env,
			const axis2_char_t *encoding);

		void (AXIS2_CALL *
        free_function)(axis2_http_out_transport_info_t *info,
			const axutil_env_t *env);
	};
    /**
     * @param info pointer to info
     * @param env pointer to environment struct
     * @param content_type pointer to content type
     */
    AXIS2_EXTERN int AXIS2_CALL
    axis2_http_out_transport_info_set_content_type(axis2_http_out_transport_info_t *info,
        const axutil_env_t *env,
        const axis2_char_t *content_type);

    /**
     * @param info pointer to info
     * @param env pointer to environment struct
     * @param encoding pointer to encoding
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_http_out_transport_info_set_char_encoding(axis2_http_out_transport_info_t *info,
        const axutil_env_t *env,
        const axis2_char_t *encoding);

    /**
     * @param out_transport_info pointer to out transport info
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_http_out_transport_info_free(axis2_http_out_transport_info_t *out_transport_info,
        const axutil_env_t *env);

    /**
     * @param env pointer to environment struct
     * @param response pointer to response
     */
    AXIS2_EXTERN axis2_http_out_transport_info_t *AXIS2_CALL
    axis2_http_out_transport_info_create(const axutil_env_t *env,
        axis2_http_simple_response_t *response);

    /**
     * Free http_out_transport_info passed as void pointer. This will be
     * cast into appropriate type and then pass the cast object
     * into the http_out_transport_info structure's free method
     * @param transport_info pointer to transport info
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_http_out_transport_info_free_void_arg(void *transport_info,
        const axutil_env_t *env);

	AXIS2_EXTERN void AXIS2_CALL
	axis2_http_out_transport_info_set_char_encoding_func(
			axis2_http_out_transport_info_t *out_transport_info,
			const axutil_env_t *env,
			axis2_status_t (AXIS2_CALL *set_encoding)
			(axis2_http_out_transport_info_t *,	const axutil_env_t *,const axis2_char_t *));

	AXIS2_EXTERN void AXIS2_CALL
	axis2_http_out_transport_info_set_content_type_func(
		axis2_http_out_transport_info_t *out_transport_info,
		const axutil_env_t *env,
		    axis2_status_t (AXIS2_CALL *set_content_type)(
			axis2_http_out_transport_info_t *,
			const axutil_env_t*, const axis2_char_t *));

	AXIS2_EXTERN void AXIS2_CALL
	axis2_http_out_transport_info_set_free_func(
		axis2_http_out_transport_info_t *out_transport_info,
		const axutil_env_t *env,
		void (AXIS2_CALL *free_function)(
		axis2_http_out_transport_info_t *,
		const axutil_env_t*));


/** Set content type. */
#define AXIS2_HTTP_OUT_TRANSPORT_INFO_SET_CONTENT_TYPE(out_transport_info, \
               env, content_type) axis2_http_out_transport_info_set_content_type (out_transport_info, env, content_type)

/** Set cahr encoding. */
#define AXIS2_HTTP_OUT_TRANSPORT_INFO_SET_CHAR_ENCODING(out_transport_info,\
               env, encoding) axis2_http_out_transport_info_set_char_encoding(out_transport_info, env, encoding)

/** Free. */
#define AXIS2_HTTP_OUT_TRANSPORT_INFO_FREE(out_transport_info, env)\
                    axis2_http_out_transport_info_free(out_transport_info, env)

/** @} */
#ifdef __cplusplus
}
#endif
#endif /* AXIS2_HTTP_OUT_TRANSPORT_INFO_H */
