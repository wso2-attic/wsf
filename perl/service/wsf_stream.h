/*
 * Copyright 2005 - 2008 WSO2, Inc. http://wso2.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef WSF_STREAM_H
#define WSF_STREAM_H

#include <axutil_stream.h>
#include <axis2_defines.h>
#include "wsf_defs.h"

#ifdef __cplusplus
extern "C"
{
#endif

axutil_stream_t* WSF_CALL 
wsf_stream_create (const axutil_env_t* env,
                   wsf_req_info_t*     req);


axis2_status_t WSF_CALL
wsf_stream_free (axutil_stream_t*    stream,
                 const axutil_env_t* env);

axutil_stream_type_t WSF_CALL 
wsf_stream_get_type (axutil_stream_t*    stream,
                     const axutil_env_t* env);

int WSF_CALL 
wsf_stream_write (axutil_stream_t*    stream,
                  const axutil_env_t* env,
                  const void*         buffer,
                  size_t              count);

int WSF_CALL 
wsf_stream_read (axutil_stream_t*    stream,
                 const axutil_env_t* env,
                 void*               buffer,
                 size_t              count);

int WSF_CALL 
wsf_stream_skip (axutil_stream_t*    stream,
                 const axutil_env_t* env,
                 int                 count);

#ifdef __cplusplus
}
#endif

#endif /* WSF_STREAM_H */
