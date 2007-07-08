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

#include <stdio.h>
#include <axis2_util.h>
#include <oxs_axis2_utils.h>
#if 0
AXIS2_EXTERN oxs_buffer_t * AXIS2_CALL  oxs_base64_decode(axutil_env_t *env,
        oxs_buffer_t *coded_buf)
{
    axis2_char_t *plain_str = NULL;/* Here plain can be binary sometimes */
    oxs_buffer_t *out_buf = NULL;
    int  ret, length;

    length =  axutil_base64_decode_len((char*)(oxs_buffer_get_data(coded_buf, env)));
    plain_str = AXIS2_MALLOC(env->allocator, axutil_base64_decode_len((char*)(oxs_buffer_get_data(coded_buf, env))));
    ret =  axutil_base64_decode(plain_str, (char*)(oxs_buffer_get_data(coded_buf, env)));
    if (ret < 0) return NULL;
    out_buf = oxs_string_to_buffer(env, plain_str);
    return out_buf;
}

AXIS2_EXTERN oxs_buffer_t * AXIS2_CALL  oxs_base64_encode(axutil_env_t *env,
        oxs_buffer_t *plain_buf)
{
    axis2_char_t *encoded_str = NULL;
    oxs_buffer_t *out_buf = NULL;

    int ret;

    encoded_str = AXIS2_MALLOC(env->allocator, (unsigned int)axutil_base64_encode_len(axutil_strlen((char*)(plain_buf->data))));

    ret =  axutil_base64_encode(encoded_str, (char*)(plain_buf->data), plain_buf->size);
    if (ret < 0) return NULL;

    /*Set to the output buffer */

    out_buf = oxs_string_to_buffer(env, encoded_str);
    return out_buf;
}
#endif

