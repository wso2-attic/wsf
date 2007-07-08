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

#ifndef OXS_ERROR_H
#define OXS_ERROR_H


/**
  * @file oxs_error.h
  * @brief Represents an Error occured during the OMXMLSecurity execution 
  */

#include <axis2_defines.h>
#include <axutil_env.h>

#ifdef __cplusplus
extern "C"
{
#endif

#if defined( WIN32 ) && (_MSC_VER < 1300)
#define __FUNCTION__ NULL
#endif

    /*Macros for locating thr error*/
#define FUNCTION_NAME __FUNCTION__
#define LINE_NUMBER __LINE__
#define FILE_NAME __FILE__

#define ERROR_LOCATION FILE_NAME,LINE_NUMBER,FUNCTION_NAME

    /*Error codes*/
#define OXS_ERROR_DEFAULT               0
#define OXS_ERROR_ENCRYPT_FAILED        1
#define OXS_ERROR_DECRYPT_FAILED        2
#define OXS_ERROR_INVALID_DATA          3
#define OXS_ERROR_INVALID_SIZE          4
#define OXS_ERROR_INVALID_FORMAT        5
#define OXS_ERROR_ELEMENT_FAILED        6
#define OXS_ERROR_UNSUPPORTED_ALGO      7
#define OXS_ERROR_CREATION_FAILED       8
#define OXS_ERROR_INITIALIZATION_FAILED 9
#define OXS_ERROR_DATA_CONV_FAILED     10
#define OXS_ERROR_OPENSSL_FUNC_FAILED  11
#define OXS_ERROR_TRANSFORM_FAILED     12
#define OXS_ERROR_SIGN_FAILED          13
#define OXS_ERROR_SIG_VERIFICATION_FAILED        14

    typedef struct _oxs_error_description oxs_error_description, *oxs_error_description_ptr;

    /**
    *   Structure to hold error descriptions
    *   @param code Error Code
    *   @param message Error Message
    */
    struct _oxs_error_description
    {
        int code;
        const char* message;
    };

    /**
    * Given the error code @code get the error message from the table
    * @param code  Error code
    * @return error message
    */
    AXIS2_EXTERN const char* AXIS2_CALL
    oxs_errors_get_msg_by_code(int code);

    /**
    * Given position @pos get the error message from the table
    * @param pos  Position of the table
    * @return error message
    */
    AXIS2_EXTERN const char* AXIS2_CALL
    oxs_errors_get_msg(unsigned int pos);

    /**
    * Given position @pos get the error code from the table
    * @param pos  Position of the table
    * @return error code
    */
    AXIS2_EXTERN int AXIS2_CALL
    oxs_errors_get_code(unsigned int pos);

    /**
     * Print/log the error message
     * @file:      file name
     * @line:      line number 
     * @func:      function 
     * @code:      the error code.
     * @msg:       the error message 
     *
     */
    AXIS2_EXTERN void AXIS2_CALL
    oxs_error(const axutil_env_t *env, const char* file, int line, const char* func,
              int code, const char* msg,...);

    /** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* OXS_ERROR_H */
