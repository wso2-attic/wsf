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

#ifndef AXIS2_HTTP_CHUNKED_STREAM_H
#define AXIS2_HTTP_CHUNKED_STREAM_H

/**
 * @defgroup axis2_http_chunked_stream http chunked stream
 * @ingroup axis2_core_trans_http 
 * Description
 * @{
 */

/**
 * @file axis2_http_chunked_stream.h
 * @brief axis2 HTTP Chunked Stream
 */

#include <axis2_const.h>
#include <axis2_defines.h>
#include <axutil_env.h>
#include <axutil_stream.h>


#ifdef __cplusplus
extern "C"
{
#endif

    /** Type name for struct axis2_http_chunked_stream */
    typedef struct axis2_http_chunked_stream axis2_http_chunked_stream_t;


    /**
    * @param chunked_stream pointer to chunked stream
    * @param env pointer to environment struct
    * @param buffer 
    * @param count
    */
    AXIS2_EXTERN int AXIS2_CALL
    axis2_http_chunked_stream_read(axis2_http_chunked_stream_t *chunked_stream,
        const axutil_env_t *env,
        void *buffer,
        size_t count);

    /**
    * @param env pointer to environment struct
    * @param buffer
    * @param count
    */
    AXIS2_EXTERN int AXIS2_CALL
    axis2_http_chunked_stream_write(axis2_http_chunked_stream_t *chunked_stream,
        const axutil_env_t *env,
        const void *buffer,
        size_t count);

    /**
    * @param chunked_stream pointer to chunked stream
    * @param env pointer to environment struct
    */
    AXIS2_EXTERN int AXIS2_CALL
    axis2_http_chunked_stream_get_current_chunk_size(const axis2_http_chunked_stream_t *chunked_stream,
        const axutil_env_t *env);

    /**
    * @param chunked_stream pointer to chunked stream
    * @param env pointer to environment struct
    * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
    */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_http_chunked_stream_write_last_chunk(axis2_http_chunked_stream_t *chunked_stream,
        const axutil_env_t *env);

    /**
    * @param chunked_stream pointer to chunked stream
    * @param env pointer to environment struct
    * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
    */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_http_chunked_stream_free(axis2_http_chunked_stream_t *chunked_stream,
        const axutil_env_t *env);

    /**
     * @param env pointer to environment struct
     * @param stream pointer to stream
     */
    AXIS2_EXTERN axis2_http_chunked_stream_t * AXIS2_CALL
    axis2_http_chunked_stream_create(const axutil_env_t *env,
        axutil_stream_t* stream);

/** @} */
#ifdef __cplusplus
}
#endif
#endif /* AXIS2_HTTP_CHUNKED_STREAM_H */
