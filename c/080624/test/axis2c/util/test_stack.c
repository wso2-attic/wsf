
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
#include <axutil_stack.h>

static void test_axutil_stack_all(    
    wsf_unit_test_case_t *tc,
    void *data);

wsf_unit_status_t WSF_UNIT_CALL test_stack(wsf_unit_suite_t * suite)
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

    wsf_unit_run_test(suite, test_axutil_stack_all, data);

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

static void WSF_UNIT_CALL test_axutil_stack_all(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;
    char *str1 = "value1";
    char *str2 = "value2";
    char *str3 = "value3";
    axutil_stack_t *stack = NULL;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);

    env = test_data->test_env;
    stack = axutil_stack_create(env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Stack Create Failed", stack);
    if (!stack)
    {
        return;
    }

    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Stack Size", 0,
        axutil_stack_size(stack, env));

    WSF_UNIT_ASSERT_TRUE(tc, "Stack Push Failed",
        axutil_stack_push(stack, env, str1));
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Stack Size", 1,
        axutil_stack_size(stack, env));
    WSF_UNIT_ASSERT_TRUE(tc, "Stack Push Failed",
        axutil_stack_push(stack, env, str2));
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Stack Size", 2,
        axutil_stack_size(stack, env));
    
    WSF_UNIT_ASSERT_EQUALS_PTR(tc, "Stack Get Failed", str2,
        axutil_stack_get(stack, env));
    WSF_UNIT_ASSERT_EQUALS_PTR(tc, "Stack GetAt Failed", str1,
        axutil_stack_get_at(stack, env, 0));
    WSF_UNIT_ASSERT_EQUALS_PTR(tc, "Stack GetAt Failed", str2,
        axutil_stack_get_at(stack, env, 1));
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Stack Size", 2,
        axutil_stack_size(stack, env));

    WSF_UNIT_ASSERT_EQUALS_PTR(tc, "Stack Pop Failed", str2,
        axutil_stack_pop(stack, env));
    WSF_UNIT_ASSERT_EQUALS_PTR(tc, "Stack GetAt Failed", str1,
        axutil_stack_get_at(stack, env, 0));
    WSF_UNIT_ASSERT_NULL(tc, "Stack GetAt Must Fail. But, Didn't",
        axutil_stack_get_at(stack, env, 1));
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Stack Size", 1,
        axutil_stack_size(stack, env));

    WSF_UNIT_ASSERT_TRUE(tc, "Stack Push Failed",
        axutil_stack_push(stack, env, str3));
    WSF_UNIT_ASSERT_EQUALS_PTR(tc, "Stack GetAt Failed", str1,
        axutil_stack_get_at(stack, env, 0));
    WSF_UNIT_ASSERT_EQUALS_PTR(tc, "Stack GetAt Failed", str3,
        axutil_stack_get_at(stack, env, 1));
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Stack Size", 2,
        axutil_stack_size(stack, env));

    WSF_UNIT_ASSERT_EQUALS_PTR(tc, "Stack Pop Failed", str3,
        axutil_stack_pop(stack, env));
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Stack Size", 1,
        axutil_stack_size(stack, env));
    WSF_UNIT_ASSERT_EQUALS_PTR(tc, "Stack Pop Failed", str1,
        axutil_stack_pop(stack, env));
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Stack Size", 0,
        axutil_stack_size(stack, env));

    WSF_UNIT_ASSERT_NULL(tc, "Stack GetAt Must Fail. But, Didn't",
        axutil_stack_get_at(stack, env, 0));
    WSF_UNIT_ASSERT_NULL(tc, "Stack Pop Must Fail. But, Didn't",
        axutil_stack_pop(stack, env));
    WSF_UNIT_ASSERT_NULL(tc, "Stack Get Must Fail. But, Didn't",
        axutil_stack_get(stack, env));
    if (stack)
    {
        axutil_stack_free(stack, env);
    }
}
