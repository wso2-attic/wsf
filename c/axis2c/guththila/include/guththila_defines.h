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

#if defined(WIN32)
#define	GUTHTHILA_EXPORT  __declspec(dllexport)
#else
#define GUTHTHILA_EXPORT
#endif

#if defined(__GNUC__)
#if defined(__i386)
#define GUTHTHILA_CALL __attribute__((cdecl))
#else
#define GUTHTHILA_CALL
#endif
#else
#if defined(__unix)
#define GUTHTHILA_CALL
#else
#define GUTHTHILA_CALL __stdcall
#endif
#endif

#ifndef guththila_char
#define guththila_char char
#endif

#ifndef GUTHTHILA_SUCCESS
#define GUTHTHILA_SUCCESS	1
#endif

#ifndef GUTHTHILA_FAILURE
#define GUTHTHILA_FAILURE	0
#endif

#ifdef __cplusplus
#define EXTERN_C_START() extern "C" {
#define EXTERN_C_END() }
#else
#define EXTERN_C_START() 
#define EXTERN_C_END() 
#endif

#ifndef GUTHTHILA_EOF
#define GUTHTHILA_EOF	(-1)
#endif

#ifndef GUTHTHILA_FALSE
#define GUTHTHILA_FALSE	0
#endif

#ifndef GUTHTHILA_TURE
#define GUTHTHILA_TRUE		1
#endif

#endif

