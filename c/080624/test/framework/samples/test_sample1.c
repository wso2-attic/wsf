
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

static void WSF_UNIT_CALL test_sample1_test1(wsf_unit_test_case_t *tc, void *data);
static void WSF_UNIT_CALL test_sample1_test2(wsf_unit_test_case_t *tc, void *data);
static void WSF_UNIT_CALL test_sample1_test3(wsf_unit_test_case_t *tc, void *data);

wsf_unit_status_t WSF_UNIT_CALL test_sample1(wsf_unit_suite_t * suite)
{
    wsf_unit_status_t status = WSF_UNIT_FAILURE;
    status = WSF_UNIT_ADD_SUB_SUITE(suite);

    wsf_unit_run_test(suite, test_sample1_test1, NULL);
    wsf_unit_run_test(suite, test_sample1_test2, NULL);
    wsf_unit_run_test(suite, test_sample1_test3, NULL);
    return status;
}

static void WSF_UNIT_CALL test_sample1_test1(wsf_unit_test_case_t *tc, void *data)
{
    WSF_UNIT_ASSERT_TRUE(tc, NULL, 1);
    WSF_UNIT_ASSERT_FALSE(tc, NULL, 0);
}

static void WSF_UNIT_CALL test_sample1_test2(wsf_unit_test_case_t *tc, void *data)
{
    WSF_UNIT_ASSERT_NOT_EQUALS_CHAR(tc, NULL, 'a', 'b');
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, NULL, "test", "test");
}

static void WSF_UNIT_CALL test_sample1_test3(wsf_unit_test_case_t *tc, void *data)
{
    WSF_UNIT_ASSERT_EQUALS_PTR(tc, NULL, tc, tc);
    WSF_UNIT_ASSERT_NOT_EQUALS_SIZE(tc, NULL, sizeof(tc), sizeof(tc));
}
