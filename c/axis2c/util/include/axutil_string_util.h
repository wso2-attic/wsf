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

#ifndef AXUTIL_STRING_UTIL_H
#define AXUTIL_STRING_UTIL_H

#include <axutil_array_list.h>
#include <axutil_string.h>
#ifdef __cplusplus
extern "C"
{
#endif

    AXIS2_EXTERN axutil_array_list_t * AXIS2_CALL
    axutil_tokenize(const axutil_env_t *env,
        axis2_char_t *in,
        int delim);

    AXIS2_EXTERN axutil_array_list_t * AXIS2_CALL
    axutil_first_token(const axutil_env_t *env,
        axis2_char_t *in,
        int delim);

    AXIS2_EXTERN axutil_array_list_t * AXIS2_CALL
    axutil_last_token(const axutil_env_t *env,
        axis2_char_t *in,
        int delim);

#ifdef __cplusplus
}
#endif
#endif /* AXIS2_STRING_UTIL_H */


