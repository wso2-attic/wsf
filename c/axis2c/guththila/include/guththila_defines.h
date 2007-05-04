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

#ifndef GUTHTHILA_DEFINES_H
#define GUTHTHILA_DEFINES_H
/**
 * @file guththila_defines.h
 * @brief Useful definitions, which may have platform concerns
 */

#include <stddef.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef char guththila_char_t;
    typedef unsigned char guththila_unsigned_char_t;
    typedef int guththila_bool_t;
    typedef int guththila_status_t;
    typedef unsigned int guththila_ssize_t;

#define GUTHTHILA_TRUE 1
#define GUTHTHILA_FALSE 0



#ifdef __cplusplus
}
#endif

#endif                          /* GUTHTHILA_DEFINES_H */
