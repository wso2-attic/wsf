
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

#ifndef UTIL_H
#define UTIL_H

#include <wsf_unit.h>
#include <axutil_env.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct axutil_test_data
        axutil_test_data_t;

    struct axutil_test_data
    {
        axutil_env_t *test_env;
        void *test_data;
    };

    #define CREATE_TEST_ENV() axutil_env_create_all("axutil_tests.log", AXIS2_LOG_LEVEL_TRACE)

    wsf_unit_status_t WSF_UNIT_CALL test_array_list(wsf_unit_suite_t * suite);
    wsf_unit_status_t WSF_UNIT_CALL test_base64_binary(wsf_unit_suite_t * suite);
    wsf_unit_status_t WSF_UNIT_CALL test_date_time(wsf_unit_suite_t * suite);
    wsf_unit_status_t WSF_UNIT_CALL test_dir_handler(wsf_unit_suite_t * suite);
    wsf_unit_status_t WSF_UNIT_CALL test_duration(wsf_unit_suite_t * suite);
    wsf_unit_status_t WSF_UNIT_CALL test_hash(wsf_unit_suite_t * suite);
    wsf_unit_status_t WSF_UNIT_CALL test_log(wsf_unit_suite_t * suite);
    wsf_unit_status_t WSF_UNIT_CALL test_md5(wsf_unit_suite_t * suite);
    wsf_unit_status_t WSF_UNIT_CALL test_properties(wsf_unit_suite_t * suite);
    wsf_unit_status_t WSF_UNIT_CALL test_rand(wsf_unit_suite_t * suite);
    wsf_unit_status_t WSF_UNIT_CALL test_stack(wsf_unit_suite_t * suite);
    wsf_unit_status_t WSF_UNIT_CALL test_string(wsf_unit_suite_t * suite);
    wsf_unit_status_t WSF_UNIT_CALL test_string_util(wsf_unit_suite_t * suite);
    wsf_unit_status_t WSF_UNIT_CALL test_thread(wsf_unit_suite_t * suite);
    wsf_unit_status_t WSF_UNIT_CALL test_uri(wsf_unit_suite_t * suite);
    wsf_unit_status_t WSF_UNIT_CALL test_url(wsf_unit_suite_t * suite);
    wsf_unit_status_t WSF_UNIT_CALL test_uuid_gen(wsf_unit_suite_t * suite);

#ifdef __cplusplus
}
#endif

#endif
