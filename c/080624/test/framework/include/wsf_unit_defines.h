
/*
 * Copyright 2005-2008 WSO2, Inc. http://wso2.com
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

#ifndef WSF_UNIT_DEFINES_H
#define WSF_UNIT_DEFINES_H

#ifdef __cplusplus
extern "C"
{
#endif

#if defined (AXUTIL_UTILS_DEFINES_H)
    typedef axis2_status_t wsf_unit_status_t;
    typedef axis2_char_t wsf_unit_char_t;
    typedef axis2_bool_t wsf_unit_bool_t;

    #define WSF_UNIT_TRUE       AXIS2_TRUE
    #define WSF_UNIT_FALSE      AXIS2_FALSE

    #define WSF_UNIT_CALL       AXIS2_CALL
    #define WSF_UNIT_EXTERN     AXIS2_EXTERN
#else
    typedef int wsf_unit_status_t;
    typedef char wsf_unit_char_t;
    typedef int wsf_unit_bool_t;

    #define WSF_UNIT_TRUE   1
    #define WSF_UNIT_FALSE  0

    #if defined(__GNUC__)
        #if defined(__i386)
            #define WSF_UNIT_CALL __attribute__((cdecl))
        #else
            #define WSF_UNIT_CALL
        #endif
    #else
        #if defined(__unix)
            #define WSF_UNIT_CALL
        #else                           /* WIN32 */
            #define WSF_UNIT_CALL __stdcall
        #endif
    #endif

    #if defined (WIN32)
        #define WSF_UNIT_EXTERN   __declspec(dllexport)
    #else
        #define WSF_UNIT_EXTERN
    #endif
#endif

#define WSF_UNIT_SUCCESS   1
#define WSF_UNIT_FAILURE   0

#ifdef __cplusplus
}
#endif

#endif                          /* WSF_UNIT_DEFINES_H */
