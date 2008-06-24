
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
#include <axutil_rand.h>

#define AXIS2_RAND_MAX 32768

static void WSF_UNIT_CALL
test_axutil_rand_create(    
    wsf_unit_test_case_t *tc,
    void *data);

static void WSF_UNIT_CALL
test_axutil_rand_create_with_range(    
    wsf_unit_test_case_t *tc,
    void *data);


wsf_unit_status_t WSF_UNIT_CALL test_rand(wsf_unit_suite_t * suite)
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

    wsf_unit_run_test(suite, test_axutil_rand_create, data);
    wsf_unit_run_test(suite, test_axutil_rand_create_with_range, data);

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

static void WSF_UNIT_CALL test_axutil_rand_create(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;
    unsigned int seed1;
    unsigned int seed2;
    int rand_val1 = -1;
    int rand_val2 = -1;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);

    env = test_data->test_env;
    rand_val1 = axutil_rand(&seed1);
    seed2 = seed1;
    rand_val2 = axutil_rand(&seed1);
    WSF_UNIT_ASSERT_NOT_EQUALS_INT(tc, "Seed has not been Modified", seed2, seed1);
    WSF_UNIT_ASSERT_NOT_EQUALS_INT(tc, "Values Can't be Equal", rand_val1, rand_val2);
    rand_val1 = axutil_rand(&seed2);
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Values Aren't Equal", rand_val1, rand_val2);

    seed1 = axutil_rand_get_seed_value_based_on_time(env);
#if defined (WIN32)
    Sleep(1000);
#else
    sleep(2);
#endif
    seed2 = axutil_rand_get_seed_value_based_on_time(env);
    WSF_UNIT_ASSERT_NOT_EQUALS_INT(tc, "Invalid Seed Values", seed1, seed2);

}

static void WSF_UNIT_CALL test_axutil_rand_create_with_range(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;
    unsigned int seed1;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);

    env = test_data->test_env;

    /* Test Failure Returns */
    seed1 = axutil_rand_get_seed_value_based_on_time(env);
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Return Value", -1,
        axutil_rand_with_range(&seed1, 0, 0));
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Return Value", -1,
        axutil_rand_with_range(&seed1, AXIS2_RAND_MAX, AXIS2_RAND_MAX));
    WSF_UNIT_ASSERT_NOT_EQUALS_INT(tc, "Invalid Return Value", -1,
        axutil_rand_with_range(&seed1, 0, AXIS2_RAND_MAX));
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Return Value", -1,
        axutil_rand_with_range(&seed1, 2, 1));
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Return Value", -1,
        axutil_rand_with_range(&seed1, 1, 1));
    WSF_UNIT_ASSERT_TRUE(tc, "Number Out-of-Range",
        (axutil_rand_with_range(&seed1, 0, AXIS2_RAND_MAX) < AXIS2_RAND_MAX &&
         axutil_rand_with_range(&seed1, 0, AXIS2_RAND_MAX) > 0));
    WSF_UNIT_ASSERT_TRUE(tc, "Number Out-of-Range",
        (axutil_rand_with_range(&seed1, 2, 3) <= 3 &&
         axutil_rand_with_range(&seed1, 2, 3) >= 2));
    /* End Test */
}
