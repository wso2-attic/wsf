
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
#include <axutil_string.h>

typedef struct test_axutil_string_in_out
    test_axutil_string_in_out_t;

static void WSF_UNIT_CALL
test_axutil_string_strrtrim(
   wsf_unit_test_case_t *tc,
   void *data);

static void WSF_UNIT_CALL
test_axutil_string_strltrim(
   wsf_unit_test_case_t *tc,
   void *data);

static void WSF_UNIT_CALL
test_axutil_string_strtrim(
   wsf_unit_test_case_t *tc,
   void *data);

struct test_axutil_string_in_out
{
    char *in;
    char *out;
};

wsf_unit_status_t WSF_UNIT_CALL test_string(wsf_unit_suite_t * suite)
{
    wsf_unit_status_t status = WSF_UNIT_FAILURE;
    axutil_env_t *env = NULL;
    axutil_test_data_t *data = NULL;
    test_axutil_string_in_out_t *trim_data = NULL;

    char *trim_in_str = "    abcd efgh    ";
    char *trim_out_str1 = "    abcd efgh";
    char *trim_out_str2 = "abcd efgh    ";
    char *trim_out_str3 = "abcd efgh";

    status = WSF_UNIT_ADD_SUB_SUITE(suite);

    env = CREATE_TEST_ENV();
    if (env)
    {
        data = AXIS2_MALLOC(env->allocator, sizeof(axutil_test_data_t));
    }
    if (data)
    {
        data->test_env = env;
        trim_data = AXIS2_MALLOC(env->allocator, sizeof(test_axutil_string_in_out_t));
        if (trim_data)
        {
            data->test_data = trim_data;
            trim_data->in = NULL;
            trim_data->out = NULL;
        }
        else
        {
            data->test_data = NULL;
        }
    }

    trim_data->in = trim_in_str;
    trim_data->out = trim_out_str1;
    wsf_unit_run_test(suite, test_axutil_string_strrtrim, data);

    trim_data->in = trim_in_str;
    trim_data->out = trim_out_str2;
    wsf_unit_run_test(suite, test_axutil_string_strltrim, data);

    trim_data->in = trim_in_str;
    trim_data->out = trim_out_str3;
    wsf_unit_run_test(suite, test_axutil_string_strtrim, data);

    if (trim_data)
    {
        AXIS2_FREE(env->allocator, trim_data);
    }
    else
    {
        status = WSF_UNIT_FAILURE;
    }
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

static void WSF_UNIT_CALL test_axutil_string_strrtrim(wsf_unit_test_case_t *tc, void *data)
{
    char *out_str = NULL;
    char *temp = NULL;
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = NULL;
    test_axutil_string_in_out_t *trim_data = NULL;

    test_data = (axutil_test_data_t *)data;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);

    if (!test_data->test_env)
    {
        return;
    }
    else
    {
        env = test_data->test_env;
    }

    if (test_data)
    {
        trim_data = (test_axutil_string_in_out_t *)test_data->test_data;
    }
    else
    {
        return;
    }

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", trim_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "string Input Unavailable", trim_data->in);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "string Output Unavailable", trim_data->out);

    if (!trim_data || !trim_data->in || !trim_data->out)
    {
        return;
    }

    temp = axutil_strdup(env, trim_data->in);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Duplication Failed", temp);
    if (!temp)
    {
        return;
    }

    out_str = axutil_strrtrim(env, temp, " \t\r\n");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Trimmed Output is NULL", out_str);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Input made NULL", temp);
    if (out_str)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, NULL, trim_data->out, out_str);
        AXIS2_FREE(env->allocator, out_str);
        out_str = NULL;
    }
    if (temp)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Trim Function alterted input",
            trim_data->in, temp);
        AXIS2_FREE(env->allocator, temp);
    }

    out_str = axutil_strrtrim(env, trim_data->in, " \t\r\n");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Trimmed Output is NULL", out_str);
    if (out_str)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, NULL, trim_data->out, out_str);
        AXIS2_FREE(env->allocator, out_str);
    }
    env = NULL;
}

static void WSF_UNIT_CALL test_axutil_string_strltrim(wsf_unit_test_case_t *tc, void *data)
{
    char *out_str = NULL;
    char *temp = NULL;
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = NULL;
    test_axutil_string_in_out_t *trim_data = NULL;

    test_data = (axutil_test_data_t *)data;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);

    if (!test_data->test_env)
    {
        return;
    }
    else
    {
        env = test_data->test_env;
    }

    if (test_data)
    {
        trim_data = (test_axutil_string_in_out_t *)test_data->test_data;
    }
    else
    {
        return;
    }

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", trim_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "string Input Unavailable", trim_data->in);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "string Output Unavailable", trim_data->out);

    if (!trim_data || !trim_data->in || !trim_data->out)
    {
        return;
    }

    temp = axutil_strdup(env, trim_data->in);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Duplication Failed", temp);
    if (!temp)
    {
        return;
    }

    out_str = axutil_strltrim(env, temp, " \t\r\n");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Trimmed Output is NULL", out_str);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Input made NULL", temp);
    if (out_str)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, NULL, trim_data->out, out_str);
        AXIS2_FREE(env->allocator, out_str);
        out_str = NULL;
    }
    if (temp)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Trim Function alterted input",
            trim_data->in, temp);
        AXIS2_FREE(env->allocator, temp);
    }

    out_str = axutil_strltrim(env, trim_data->in, " \t\r\n");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Trimmed Output is NULL", out_str);
    if (out_str)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, NULL, trim_data->out, out_str);
        AXIS2_FREE(env->allocator, out_str);
    }
    env = NULL;
}

static void WSF_UNIT_CALL test_axutil_string_strtrim(wsf_unit_test_case_t *tc, void *data)
{
    char *out_str = NULL;
    char *temp = NULL;
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = NULL;
    test_axutil_string_in_out_t *trim_data = NULL;

    test_data = (axutil_test_data_t *)data;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);

    if (!test_data->test_env)
    {
        return;
    }
    else
    {
        env = test_data->test_env;
    }

    if (test_data)
    {
        trim_data = (test_axutil_string_in_out_t *)test_data->test_data;
    }
    else
    {
        return;
    }

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", trim_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "string Input Unavailable", trim_data->in);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "string Output Unavailable", trim_data->out);

    if (!trim_data || !trim_data->in || !trim_data->out)
    {
        return;
    }

    temp = axutil_strdup(env, trim_data->in);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Duplication Failed", temp);
    if (!temp)
    {
        return;
    }

    out_str = axutil_strtrim(env, temp, " \t\r\n");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Trimmed Output is NULL", out_str);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Input made NULL", temp);
    if (out_str)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, NULL, trim_data->out, out_str);
        AXIS2_FREE(env->allocator, out_str);
        out_str = NULL;
    }
    if (temp)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Trim Function alterted input",
            trim_data->in, temp);
        AXIS2_FREE(env->allocator, temp);
    }

    out_str = axutil_strtrim(env, trim_data->in, " \t\r\n");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Trimmed Output is NULL", out_str);
    if (out_str)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, NULL, trim_data->out, out_str);
        AXIS2_FREE(env->allocator, out_str);
    }
    env = NULL;
}
