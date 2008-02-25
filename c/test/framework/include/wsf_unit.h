
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

#ifndef WSF_UNIT_H
#define WSF_UNIT_H

#include <wsf_unit_defines.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef WIN32
#include <io.h>
#else
#include <unistd.h>
#endif

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct wsf_unit_sub_suite
        wsf_unit_sub_suite_t;

    typedef struct wsf_unit_suite
        wsf_unit_suite_t;

    typedef struct wsf_unit_test_case
        wsf_unit_test_case_t;

    typedef struct wsf_unit_test_list
        wsf_unit_test_list_t;

    typedef void (
        WSF_UNIT_CALL
        * WSF_UNIT_TEST)(
            wsf_unit_test_case_t *test, void *data);

    struct wsf_unit_test_list
    {
        wsf_unit_status_t (
            WSF_UNIT_CALL
            * execute)(
                wsf_unit_suite_t *suite);
    };

    WSF_UNIT_EXTERN wsf_unit_suite_t *WSF_UNIT_CALL
    wsf_unit_suite_create(
        const wsf_unit_char_t *suite_name);

    WSF_UNIT_EXTERN wsf_unit_status_t WSF_UNIT_CALL
    wsf_unit_suite_add_sub_suite(
        wsf_unit_suite_t * suite,
        const wsf_unit_char_t *sub_suite_name);

    WSF_UNIT_EXTERN void WSF_UNIT_CALL
    wsf_unit_suite_free(
        wsf_unit_suite_t * suite);

    WSF_UNIT_EXTERN wsf_unit_suite_t *WSF_UNIT_CALL
    wsf_unit_suite_create(
        const wsf_unit_char_t *suite_name);

    WSF_UNIT_EXTERN void WSF_UNIT_CALL
    wsf_unit_run_test(
        wsf_unit_suite_t * suite,
        WSF_UNIT_TEST test,
        void *value);

    WSF_UNIT_EXTERN void WSF_UNIT_CALL
    wsf_unit_print_message(
        const char *format,
        ...);

    WSF_UNIT_EXTERN void WSF_UNIT_CALL
    wsf_unit_print_error_message(
        const char *format,
        ...);

    WSF_UNIT_EXTERN void WSF_UNIT_CALL
    wsf_unit_assert_equals_int(
        wsf_unit_test_case_t *test_case,
        const char *message,
        const int expected,
        const int actual,
        const int line_no);

    WSF_UNIT_EXTERN void WSF_UNIT_CALL
    wsf_unit_assert_equals_long(
        wsf_unit_test_case_t *test_case,
        const char *message,
        const long expected,
        const long actual,
        const int line_no);

    WSF_UNIT_EXTERN void WSF_UNIT_CALL
    wsf_unit_assert_equals_float(
        wsf_unit_test_case_t *test_case,
        const char *message,
        const float expected,
        const float actual,
        const int line_no);

    WSF_UNIT_EXTERN void WSF_UNIT_CALL
    wsf_unit_assert_equals_double(
        wsf_unit_test_case_t *test_case,
        const char *message,
        const double expected,
        const double actual,
        const int line_no);

    WSF_UNIT_EXTERN void WSF_UNIT_CALL
    wsf_unit_assert_equals_char(
        wsf_unit_test_case_t *test_case,
        const char *message,
        const char expected,
        const char actual,
        const int line_no);

    WSF_UNIT_EXTERN void WSF_UNIT_CALL
    wsf_unit_assert_equals_string(
        wsf_unit_test_case_t *test_case,
        const char *message,
        const char *expected,
        const char *actual,
        const int line_no);

    WSF_UNIT_EXTERN void WSF_UNIT_CALL
    wsf_unit_assert_equals_ptr(
        wsf_unit_test_case_t *test_case,
        const char *message,
        const void *expected,
        const void *actual,
        const int line_no);

    WSF_UNIT_EXTERN void WSF_UNIT_CALL
    wsf_unit_assert_equals_size(
        wsf_unit_test_case_t *test_case,
        const char *message,
        const size_t expected,
        const size_t actual,
        const int line_no);

    WSF_UNIT_EXTERN void WSF_UNIT_CALL
    wsf_unit_assert_not_equals_int(
        wsf_unit_test_case_t *test_case,
        const char *message,
        const int expected,
        const int actual,
        const int line_no);

    WSF_UNIT_EXTERN void WSF_UNIT_CALL
    wsf_unit_assert_not_equals_long(
        wsf_unit_test_case_t *test_case,
        const char *message,
        const long expected,
        const long actual,
        const int line_no);

    WSF_UNIT_EXTERN void WSF_UNIT_CALL
    wsf_unit_assert_not_equals_float(
        wsf_unit_test_case_t *test_case,
        const char *message,
        const float expected,
        const float actual,
        const int line_no);

    WSF_UNIT_EXTERN void WSF_UNIT_CALL
    wsf_unit_assert_not_equals_double(
        wsf_unit_test_case_t *test_case,
        const char *message,
        const double expected,
        const double actual,
        const int line_no);

    WSF_UNIT_EXTERN void WSF_UNIT_CALL
    wsf_unit_assert_not_equals_char(
        wsf_unit_test_case_t *test_case,
        const char *message,
        const char expected,
        const char actual,
        const int line_no);

    WSF_UNIT_EXTERN void WSF_UNIT_CALL
    wsf_unit_assert_not_equals_string(
        wsf_unit_test_case_t *test_case,
        const char *message,
        const char *expected,
        const char *actual,
        const int line_no);

    WSF_UNIT_EXTERN void WSF_UNIT_CALL
    wsf_unit_assert_not_equals_ptr(
        wsf_unit_test_case_t *test_case,
        const char *message,
        const void *expected,
        const void *actual,
        const int line_no);

    WSF_UNIT_EXTERN void WSF_UNIT_CALL
    wsf_unit_assert_not_equals_size(
        wsf_unit_test_case_t *test_case,
        const char *message,
        const size_t expected,
        const size_t actual,
        const int line_no);

    WSF_UNIT_EXTERN void WSF_UNIT_CALL
    wsf_unit_assert_null(
        wsf_unit_test_case_t *test_case,
        const char *message,
        const void *pointer,
        const int line_no);

    WSF_UNIT_EXTERN void WSF_UNIT_CALL
    wsf_unit_assert_not_null(
        wsf_unit_test_case_t *test_case,
        const char *message,
        const void *pointer,
        const int line_no);

    WSF_UNIT_EXTERN void WSF_UNIT_CALL
    wsf_unit_assert_true(
        wsf_unit_test_case_t *test_case,
        const char *message,
        const int condition,
        const int line_no);

    WSF_UNIT_EXTERN void WSF_UNIT_CALL
    wsf_unit_assert_false(
        wsf_unit_test_case_t *test_case,
        const char *message,
        const int condition,
        const int line_no);

    WSF_UNIT_EXTERN void WSF_UNIT_CALL
    wsf_unit_not_implemented(
        wsf_unit_test_case_t *test_case,
        const char *message,
        const int line_no);

    WSF_UNIT_EXTERN void WSF_UNIT_CALL
    wsf_unit_fail(
        wsf_unit_test_case_t *test_case,
        const char *message,
        const int line_no);

    WSF_UNIT_EXTERN int WSF_UNIT_CALL
    wsf_unit_execute(
        const int argc,
        const char *const argv[],
        const wsf_unit_char_t *suite_name,
        const int testc,
        const wsf_unit_test_list_t testv[]);


    #define WSF_UNIT_SUITE_CREATE() \
        wsf_unit_suite_create(__FILE__)

    #define WSF_UNIT_ADD_SUB_SUITE(p) \
        wsf_unit_suite_add_sub_suite(p, __FILE__)

    #define WSF_UNIT_ASSERT_EQUALS_INT(p, q, r, s) \
        wsf_unit_assert_equals_int(p, q, r, s, __LINE__)

    #define WSF_UNIT_ASSERT_EQUALS_LONG(p, q, r, s) \
        wsf_unit_assert_equals_long(p, q, r, s, __LINE__)

    #define WSF_UNIT_ASSERT_EQUALS_FLOAT(p, q, r, s) \
        wsf_unit_assert_equals_float(p, q, r, s, __LINE__)

    #define WSF_UNIT_ASSERT_EQUALS_DOUBLE(p, q, r, s) \
        wsf_unit_assert_equals_double(p, q, r, s, __LINE__)

    #define WSF_UNIT_ASSERT_EQUALS_CHAR(p, q, r, s) \
        wsf_unit_assert_equals_char(p, q, r, s, __LINE__)

    #define WSF_UNIT_ASSERT_EQUALS_STRING(p, q, r, s) \
        wsf_unit_assert_equals_string(p, q, r, s, __LINE__)

    #define WSF_UNIT_ASSERT_EQUALS_PTR(p, q, r, s) \
        wsf_unit_assert_equals_ptr(p, q, r, s, __LINE__)

    #define WSF_UNIT_ASSERT_EQUALS_SIZE(p, q, r, s) \
        wsf_unit_assert_equals_size(p, q, r, s, __LINE__)

    #define WSF_UNIT_ASSERT_NOT_EQUALS_INT(p, q, r, s) \
        wsf_unit_assert_not_equals_int(p, q, r, s, __LINE__)

    #define WSF_UNIT_ASSERT_NOT_EQUALS_LONG(p, q, r, s) \
        wsf_unit_assert_not_equals_long(p, q, r, s, __LINE__)

    #define WSF_UNIT_ASSERT_NOT_EQUALS_FLOAT(p, q, r, s) \
        wsf_unit_assert_not_equals_float(p, q, r, s, __LINE__)

    #define WSF_UNIT_ASSERT_NOT_EQUALS_DOUBLE(p, q, r, s) \
        wsf_unit_assert_not_equals_double(p, q, r, s, __LINE__)

    #define WSF_UNIT_ASSERT_NOT_EQUALS_CHAR(p, q, r, s) \
        wsf_unit_assert_not_equals_char(p, q, r, s, __LINE__)

    #define WSF_UNIT_ASSERT_NOT_EQUALS_STRING(p, q, r, s) \
        wsf_unit_assert_not_equals_string(p, q, r, s, __LINE__)

    #define WSF_UNIT_ASSERT_NOT_EQUALS_PTR(p, q, r, s) \
        wsf_unit_assert_not_equals_ptr(p, q, r, s, __LINE__)

    #define WSF_UNIT_ASSERT_NOT_EQUALS_SIZE(p, q, r, s) \
        wsf_unit_assert_not_equals_size(p, q, r, s, __LINE__)

    #define WSF_UNIT_ASSERT_NULL(p, q, r) \
        wsf_unit_assert_null(p, q, r, __LINE__)

    #define WSF_UNIT_ASSERT_NOT_NULL(p, q, r) \
        wsf_unit_assert_not_null(p, q, r, __LINE__)

    #define WSF_UNIT_ASSERT_TRUE(p, q, r) \
        wsf_unit_assert_true(p, q, r, __LINE__)

    #define WSF_UNIT_ASSERT_FALSE(p, q, r) \
        wsf_unit_assert_false(p, q, r, __LINE__)

    #define WSF_UNIT_NOT_IMPLEMENTED(p, q) \
        wsf_unit_not_implemented(p, q, __LINE__)

    #define WSF_UNIT_FAIL(p, q) \
        wsf_unit_fail(p, q, __LINE__)

#ifdef __cplusplus
}
#endif

#endif                          /* WSF_UNIT_H */
