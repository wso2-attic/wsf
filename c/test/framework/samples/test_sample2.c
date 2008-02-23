
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

#include <sample.h>

static void WSF_UNIT_CALL test_sample2_test1(wsf_unit_test_case_t *tc, void *data);
static void WSF_UNIT_CALL test_sample2_test2(wsf_unit_test_case_t *tc, void *data);

wsf_unit_status_t WSF_UNIT_CALL test_sample2(wsf_unit_suite_t * suite)
{
    wsf_unit_status_t status = WSF_UNIT_FAILURE;
    status = WSF_UNIT_ADD_SUB_SUITE(suite);

    wsf_unit_run_test(suite, test_sample2_test1, NULL);
    wsf_unit_run_test(suite, test_sample2_test2, suite);
    return status;
}

static void WSF_UNIT_CALL test_sample2_test1(wsf_unit_test_case_t *tc, void *data)
{
    WSF_UNIT_ASSERT_EQUALS_INT(tc, NULL, 1, 1);
    WSF_UNIT_ASSERT_NULL(tc, NULL, NULL);
}

static void WSF_UNIT_CALL test_sample2_test2(wsf_unit_test_case_t *tc, void *data)
{
    WSF_UNIT_ASSERT_NOT_EQUALS_FLOAT(tc, NULL, 1.1, 1.5);
    WSF_UNIT_ASSERT_NOT_NULL(tc, NULL, data);
}
