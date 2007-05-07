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

#ifndef AXIS2_KEY_TYPE_H
#define AXIS2_KEY_TYPE_H


/**
  * @file axis2_key_file_type.h
  * @defines the key file type. 
  */

#include <axis2_defines.h>
#include <axutil_env.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /** @defgroup key_file_type
     * @ingroup 
     * @{
     */

    typedef enum
    {
        AXIS2_KEY_TYPE_UNKNOWN = 0,
        AXIS2_KEY_TYPE_PEM,
        AXIS2_KEY_TYPE_DER
    }axis2_key_type_t;



    /** @} */
#ifdef __cplusplus
}
#endif

#endif
