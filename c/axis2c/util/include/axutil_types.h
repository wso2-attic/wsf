/**
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

#ifndef AXUTIL_TYPES_H
#define AXUTIL_TYPES_H

#include <axutil_utils_defines.h>
#include <axutil_error.h>
#include <axutil_env.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @defgroup axutil_types type convertors
     * @ingroup axis2_util
     * @{
     */

    AXIS2_EXTERN int AXIS2_CALL
    axutil_atoi(const char *s);

#define AXIS2_ATOI(s) axutil_atoi(s)

    /** @} */

#ifdef __cplusplus
}
#endif

#endif                          /* AXIS2_TYPES_H */

