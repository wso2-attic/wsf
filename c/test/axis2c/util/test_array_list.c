
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
#include <axutil_array_list.h>

#define ARRAY_LIST_TEST_VAL_1 "value1"
#define ARRAY_LIST_TEST_VAL_2 "value2"
#define ARRAY_LIST_TEST_VAL_3 "value3"
#define ARRAY_LIST_TEST_VAL_4 "value4"
#define ARRAY_LIST_TEST_VAL_5 "value5"
#define ARRAY_LIST_TEST_VAL_6 "value6"

static void WSF_UNIT_CALL
test_axutil_array_list_create(    
    wsf_unit_test_case_t *tc,
    void *data);

static void WSF_UNIT_CALL
test_axutil_array_list_add(    
    wsf_unit_test_case_t *tc,
    void *data);

static void WSF_UNIT_CALL
test_axutil_array_list_set_remove(    
    wsf_unit_test_case_t *tc,
    void *data);

wsf_unit_status_t WSF_UNIT_CALL test_array_list(wsf_unit_suite_t * suite)
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

    wsf_unit_run_test(suite, test_axutil_array_list_create, data);
    wsf_unit_run_test(suite, test_axutil_array_list_add, data);
    wsf_unit_run_test(suite, test_axutil_array_list_set_remove, data);

    if (data)
    {
        data->test_env = NULL;
        if (data->test_data)
        {
            axutil_array_list_free_void_arg(data->test_data, env);
        }
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

static void WSF_UNIT_CALL test_axutil_array_list_create(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;
    axutil_array_list_t *list = NULL;
    char *val = NULL;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    if (!test_data)
    {
        return;
    }
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);
    env = test_data->test_env;
    list = axutil_array_list_create(env, 1);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Array List Creation Failed", list);
    if (!list)
    {
        return;
    }
    test_data->test_data = list;
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Incorrect List Size", 0,
        axutil_array_list_size(list, env));
    WSF_UNIT_ASSERT_TRUE(tc, "Array List Not Empty",
        axutil_array_list_is_empty(list, env));
    val = (char *)axutil_strdup(env, ARRAY_LIST_TEST_VAL_1);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Duplication Failed", val);
    axutil_array_list_add(list, env, val);
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Incorrect List Size", 1,
        axutil_array_list_size(list, env));
    val = NULL;
    val = (char *)axutil_strdup(env, ARRAY_LIST_TEST_VAL_2);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Duplication Failed", val);
    axutil_array_list_add(list, env, val);
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Incorrect List Size", 2,
        axutil_array_list_size(list, env));
    WSF_UNIT_ASSERT_FALSE(tc, "Array List Can't be Empty",
        axutil_array_list_is_empty(list, env));
    axutil_array_list_add(list, env, list);
}

static void WSF_UNIT_CALL test_axutil_array_list_add(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;
    axutil_array_list_t *list = NULL;
    char *val = NULL;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    if (!test_data)
    {
        return;
    }
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);
    env = test_data->test_env;
    list = (axutil_array_list_t *) test_data->test_data;
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", list);
    if (!list)
    {
        return;
    }
    WSF_UNIT_ASSERT_EQUALS_PTR(tc, "Invalid Reference on Array List", list,
        (axutil_array_list_t *) axutil_array_list_get(list, env, 2));
    axutil_array_list_add(list, env, ARRAY_LIST_TEST_VAL_3);
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Incorrect List Size", 4,
        axutil_array_list_size(list, env));
    WSF_UNIT_ASSERT_EQUALS_PTR(tc, "Invalid Reference on Array List", ARRAY_LIST_TEST_VAL_3,
        axutil_array_list_get(list, env, 3));
    val = (char *)axutil_strdup(env, ARRAY_LIST_TEST_VAL_4);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Duplication Failed", val);
    axutil_array_list_add(list, env, val);
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Incorrect List Size", 5,
        axutil_array_list_size(list, env));
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Reference on Array List", ARRAY_LIST_TEST_VAL_1,
        (char *)axutil_array_list_get(list, env, 0));
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Reference on Array List", ARRAY_LIST_TEST_VAL_2,
        (char *)axutil_array_list_get(list, env, 1));
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Reference on Array List", ARRAY_LIST_TEST_VAL_4,
        (char *)axutil_array_list_get(list, env, 4));
}

static void WSF_UNIT_CALL test_axutil_array_list_set_remove(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;
    axutil_array_list_t *list = NULL;
    char *val = NULL;
    char *temp = NULL;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    if (!test_data)
    {
        return;
    }
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);
    env = test_data->test_env;
    list = (axutil_array_list_t *) test_data->test_data;
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", list);
    if (!list)
    {
        return;
    }
    val = (char *)axutil_array_list_remove(list, env, 1);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Array List Remove Failed", val);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Array List Remove Retured Invalid Data",
        ARRAY_LIST_TEST_VAL_2, val);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Reference on Array List", ARRAY_LIST_TEST_VAL_4,
        (char *)axutil_array_list_get(list, env, 3));
    if (val)
    {
        AXIS2_FREE(env->allocator, val);
    }
    val = NULL;
    val = (char *)axutil_array_list_remove(list, env, 4);
    WSF_UNIT_ASSERT_NULL(tc, "Array List Remove Invalid", val);
    val = NULL;
    val = (char *)axutil_array_list_remove(list, env, 2);
    WSF_UNIT_ASSERT_EQUALS_PTR(tc, "Invalid Reference returned by Array List",
        ARRAY_LIST_TEST_VAL_3, val);
    val = NULL;
    WSF_UNIT_ASSERT_EQUALS_PTR(tc, "Invalid Reference returned by Array List",
        list, axutil_array_list_remove(list, env, 1));
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Incorrect List Size", 2,
        axutil_array_list_size(list, env));
    val = (char *)axutil_strdup(env, ARRAY_LIST_TEST_VAL_5);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Duplication Failed", val);
    temp = axutil_array_list_set(list, env, 0, val);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Array List Set Returned Null", temp);
    if (temp)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Reference retured by Array List Set",
            ARRAY_LIST_TEST_VAL_1, (char *)temp);
        AXIS2_FREE(env->allocator, temp);
        temp = NULL;
    }
    val = NULL;
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Incorrect List Size", 2,
        axutil_array_list_size(list, env));
    val = (char *)axutil_strdup(env, ARRAY_LIST_TEST_VAL_6);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Duplication Failed", val);
    temp = axutil_array_list_set(list, env, 2, val);
    WSF_UNIT_ASSERT_NULL(tc, "Array List Set Returned Invalid Value", temp);
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Incorrect List Size", 2,
        axutil_array_list_size(list, env));
    if (val)
    {
        AXIS2_FREE(env->allocator, val);
        val = NULL;
    }
    val = (char *)axutil_array_list_remove(list, env, 0);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Array List Remove Failed", val);
    if (val)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Reference retured by Array List",
            ARRAY_LIST_TEST_VAL_5, (char *)val);
        AXIS2_FREE(env->allocator, val);
        val = NULL;
    }
    val = (char *)axutil_array_list_remove(list, env, 0);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Array List Remove Failed", val);
    if (val)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Reference retured by Array List",
            ARRAY_LIST_TEST_VAL_4, (char *)val);
        AXIS2_FREE(env->allocator, val);
        val = NULL;
    }
    WSF_UNIT_ASSERT_TRUE(tc, "Array List Not Empty",
        axutil_array_list_is_empty(list, env));
}
