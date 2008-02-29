
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

#include <util.h>
#include <axutil_uuid_gen.h>

static void WSF_UNIT_CALL
test_axutil_uuid_gen_create(    
    wsf_unit_test_case_t *tc,
    void *data);

wsf_unit_status_t WSF_UNIT_CALL test_uuid_gen(wsf_unit_suite_t * suite)
{
    wsf_unit_status_t status = WSF_UNIT_FAILURE;
    axutil_env_t *env = NULL;
    axutil_test_data_t *data = NULL;

    status = WSF_UNIT_ADD_SUB_SUITE(suite);

    env = CREATE_TEST_ENV();
    if (env)
    {
        data = AXIS2_MALLOC(env->allocator, sizeof(axutil_test_data_t));
    }
    if (data)
    {
        data->test_env = env;
        data->test_data = NULL;
    }

    wsf_unit_run_test(suite, test_axutil_uuid_gen_create, data);

    if (data)
    {
        data->test_env = NULL;
        AXIS2_FREE(env->allocator, data);
    }
    else
    {
        status = WSF_UNIT_FAILURE;
    }
    if (env)
    {
        axutil_env_free(env);
    }
    else
    {
        status = WSF_UNIT_FAILURE;
    }
    return status;
}

static void WSF_UNIT_CALL test_axutil_uuid_gen_create(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;
    char *uuid1 = NULL;
    char *uuid2 = NULL;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);

    env = test_data->test_env;
    uuid1 = axutil_uuid_gen(env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "UUID Create Failed", uuid1);
    uuid2 = axutil_uuid_gen(env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "UUID Create Failed", uuid2);
    if (uuid1 && uuid2)
    {
        WSF_UNIT_ASSERT_NOT_EQUALS_STRING(tc, "UUID Not Unique", uuid1, uuid2);
    }
    if (uuid1)
    {
        AXIS2_FREE(env->allocator, uuid1);
    }
    if (uuid2)
    {
        AXIS2_FREE(env->allocator, uuid2);
    }
}
