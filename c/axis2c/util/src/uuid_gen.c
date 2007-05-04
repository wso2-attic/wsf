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

#include <axutil_uuid_gen.h>



AXIS2_EXTERN axis2_char_t * AXIS2_CALL
axutil_uuid_gen(const axutil_env_t *env)
{

    axis2_char_t *str = AXIS2_MALLOC(env->allocator, 40 * sizeof(char));
    axutil_platform_uuid_gen(str);
    if (!str)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_UUID_GEN_FAILED,
            AXIS2_FAILURE);
        return NULL;
    }
    return str;
}

