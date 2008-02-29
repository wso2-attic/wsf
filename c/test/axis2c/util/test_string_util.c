
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
#include <axutil_string_util.h>

static void WSF_UNIT_CALL
test_axutil_string_util_tokenize(    
    wsf_unit_test_case_t *tc,
    void *data);

static void WSF_UNIT_CALL
test_axutil_string_util_first_token(    
    wsf_unit_test_case_t *tc,
    void *data);

static void WSF_UNIT_CALL
test_axutil_string_util_last_token(    
    wsf_unit_test_case_t *tc,
    void *data);

wsf_unit_status_t WSF_UNIT_CALL test_string_util(wsf_unit_suite_t * suite)
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

    wsf_unit_run_test(suite, test_axutil_string_util_tokenize, data);
    wsf_unit_run_test(suite, test_axutil_string_util_first_token, data);
    wsf_unit_run_test(suite, test_axutil_string_util_last_token, data);

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

static void WSF_UNIT_CALL test_axutil_string_util_tokenize(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;
    char *input1 = "sample test string one";
    char delim1 = ' ';
    char *input2 = "sample,test,string,one";
    char delim2 = ',';
    char *input3 = "sample test,string one";
    axutil_array_list_t *tokens = NULL;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);

    env = test_data->test_env;

    tokens = axutil_tokenize(env, input1, delim1);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Tokenize Failed", tokens);
    if (tokens)
    {
        WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Token Count", 4,
            axutil_array_list_size(tokens, env));
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Token on Array List", "sample",
            (char *)axutil_array_list_get(tokens, env, 0));
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Token on Array List", "test",
            (char *)axutil_array_list_get(tokens, env, 1));
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Token on Array List", "string",
            (char *)axutil_array_list_get(tokens, env, 2));
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Token on Array List", "one",
            (char *)axutil_array_list_get(tokens, env, 3));
        /*while (axutil_array_list_size(tokens, env))
        {
            AXIS2_FREE(env->allocator, axutil_array_list_remove(tokens, env, 0));
        }*/
        axutil_array_list_free(tokens, env);
        tokens = NULL;
    }
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Tokenize Modified Input",
        "sample test string one", input1);
    WSF_UNIT_ASSERT_EQUALS_CHAR(tc, "Tokenize Modified Delimiter",
        ' ', delim1);

    tokens = axutil_tokenize(env, input2, delim2);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Tokenize Failed", tokens);
    if (tokens)
    {
        WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Token Count", 4,
            axutil_array_list_size(tokens, env));
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Token on Array List", "sample",
            (char *)axutil_array_list_get(tokens, env, 0));
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Token on Array List", "test",
            (char *)axutil_array_list_get(tokens, env, 1));
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Token on Array List", "string",
            (char *)axutil_array_list_get(tokens, env, 2));
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Token on Array List", "one",
            (char *)axutil_array_list_get(tokens, env, 3));
        /*while (axutil_array_list_size(tokens, env))
        {
            AXIS2_FREE(env->allocator, axutil_array_list_remove(tokens, env, 0));
        }*/
        axutil_array_list_free(tokens, env);
        tokens = NULL;
    }
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Tokenize Modified Input",
        "sample,test,string,one", input2);
    WSF_UNIT_ASSERT_EQUALS_CHAR(tc, "Tokenize Modified Delimiter",
        ',', delim2);

    tokens = axutil_tokenize(env, input3, delim1);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Tokenize Failed", tokens);
    if (tokens)
    {
        WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Token Count", 3,
            axutil_array_list_size(tokens, env));
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Token on Array List", "sample",
            (char *)axutil_array_list_get(tokens, env, 0));
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Token on Array List", "test,string",
            (char *)axutil_array_list_get(tokens, env, 1));
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Token on Array List", "one",
            (char *)axutil_array_list_get(tokens, env, 2));
        /*while (axutil_array_list_size(tokens, env))
        {
            AXIS2_FREE(env->allocator, axutil_array_list_remove(tokens, env, 0));
        }*/
        axutil_array_list_free(tokens, env);
        tokens = NULL;
    }
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Tokenize Modified Input",
        "sample test,string one", input3);
    WSF_UNIT_ASSERT_EQUALS_CHAR(tc, "Tokenize Modified Delimiter",
        ' ', delim1);

    tokens = axutil_tokenize(env, input3, delim2);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Tokenize Failed", tokens);
    if (tokens)
    {
        WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Token Count", 2,
            axutil_array_list_size(tokens, env));
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Token on Array List", "sample test",
            (char *)axutil_array_list_get(tokens, env, 0));
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Token on Array List", "string one",
            (char *)axutil_array_list_get(tokens, env, 1));
        /*while (axutil_array_list_size(tokens, env))
        {
            AXIS2_FREE(env->allocator, axutil_array_list_remove(tokens, env, 0));
        }*/
        axutil_array_list_free(tokens, env);
        tokens = NULL;
    }
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Tokenize Modified Input",
        "sample test,string one", input3);
    WSF_UNIT_ASSERT_EQUALS_CHAR(tc, "Tokenize Modified Delimiter",
        ',', delim2);

    tokens = axutil_tokenize(env, input2, delim1);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Tokenize Failed", tokens);
    if (tokens)
    {
        WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Token Count", 1,
            axutil_array_list_size(tokens, env));
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Token on Array List", "sample,test,string,one",
            (char *)axutil_array_list_get(tokens, env, 0));
        /*while (axutil_array_list_size(tokens, env))
        {
            AXIS2_FREE(env->allocator, axutil_array_list_remove(tokens, env, 0));
        }*/
        axutil_array_list_free(tokens, env);
        tokens = NULL;
    }
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Tokenize Modified Input",
        "sample,test,string,one", input2);
    WSF_UNIT_ASSERT_EQUALS_CHAR(tc, "Tokenize Modified Delimiter",
        ' ', delim1);
}

static void WSF_UNIT_CALL test_axutil_string_util_first_token(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;
    char *input1 = "sample test string one";
    char delim1 = ' ';
    char *input2 = "sample,test,string,one";
    char delim2 = ',';
    char *input3 = "sample test,string one";
    axutil_array_list_t *tokens = NULL;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);

    env = test_data->test_env;

    tokens = axutil_first_token(env, input1, delim1);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Tokenize Failed", tokens);
    if (tokens)
    {
        WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Token Count", 2,
            axutil_array_list_size(tokens, env));
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Token on Array List", "sample",
            (char *)axutil_array_list_get(tokens, env, 0));
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Token on Array List", "test string one",
            (char *)axutil_array_list_get(tokens, env, 1));
        /*while (axutil_array_list_size(tokens, env))
        {
            AXIS2_FREE(env->allocator, axutil_array_list_remove(tokens, env, 0));
        }*/
        axutil_array_list_free(tokens, env);
        tokens = NULL;
    }
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Tokenize Modified Input",
        "sample test string one", input1);
    WSF_UNIT_ASSERT_EQUALS_CHAR(tc, "Tokenize Modified Delimiter",
        ' ', delim1);

    tokens = axutil_first_token(env, input2, delim2);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Tokenize Failed", tokens);
    if (tokens)
    {
        WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Token Count", 2,
            axutil_array_list_size(tokens, env));
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Token on Array List", "sample",
            (char *)axutil_array_list_get(tokens, env, 0));
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Token on Array List", "test,string,one",
            (char *)axutil_array_list_get(tokens, env, 1));
        /*while (axutil_array_list_size(tokens, env))
        {
            AXIS2_FREE(env->allocator, axutil_array_list_remove(tokens, env, 0));
        }*/
        axutil_array_list_free(tokens, env);
        tokens = NULL;
    }
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Tokenize Modified Input",
        "sample,test,string,one", input2);
    WSF_UNIT_ASSERT_EQUALS_CHAR(tc, "Tokenize Modified Delimiter",
        ',', delim2);

    tokens = axutil_first_token(env, input3, delim1);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Tokenize Failed", tokens);
    if (tokens)
    {
        WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Token Count", 2,
            axutil_array_list_size(tokens, env));
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Token on Array List", "sample",
            (char *)axutil_array_list_get(tokens, env, 0));
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Token on Array List", "test,string one",
            (char *)axutil_array_list_get(tokens, env, 1));
        /*while (axutil_array_list_size(tokens, env))
        {
            AXIS2_FREE(env->allocator, axutil_array_list_remove(tokens, env, 0));
        }*/
        axutil_array_list_free(tokens, env);
        tokens = NULL;
    }
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Tokenize Modified Input",
        "sample test,string one", input3);
    WSF_UNIT_ASSERT_EQUALS_CHAR(tc, "Tokenize Modified Delimiter",
        ' ', delim1);

    tokens = axutil_first_token(env, input3, delim2);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Tokenize Failed", tokens);
    if (tokens)
    {
        WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Token Count", 2,
            axutil_array_list_size(tokens, env));
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Token on Array List", "sample test",
            (char *)axutil_array_list_get(tokens, env, 0));
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Token on Array List", "string one",
            (char *)axutil_array_list_get(tokens, env, 1));
        /*while (axutil_array_list_size(tokens, env))
        {
            AXIS2_FREE(env->allocator, axutil_array_list_remove(tokens, env, 0));
        }*/
        axutil_array_list_free(tokens, env);
        tokens = NULL;
    }
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Tokenize Modified Input",
        "sample test,string one", input3);
    WSF_UNIT_ASSERT_EQUALS_CHAR(tc, "Tokenize Modified Delimiter",
        ',', delim2);

    tokens = axutil_first_token(env, input2, delim1);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Tokenize Failed", tokens);
    if (tokens)
    {
        WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Token Count", 2,
            axutil_array_list_size(tokens, env));
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Token on Array List", "sample,test,string,one",
            (char *)axutil_array_list_get(tokens, env, 0));
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Token on Array List", "",
            (char *)axutil_array_list_get(tokens, env, 1));
        /*while (axutil_array_list_size(tokens, env))
        {
            AXIS2_FREE(env->allocator, axutil_array_list_remove(tokens, env, 0));
        }*/
        axutil_array_list_free(tokens, env);
        tokens = NULL;
    }
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Tokenize Modified Input",
        "sample,test,string,one", input2);
    WSF_UNIT_ASSERT_EQUALS_CHAR(tc, "Tokenize Modified Delimiter",
        ' ', delim1);
}

static void WSF_UNIT_CALL test_axutil_string_util_last_token(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;
    char *input1 = "sample test string one";
    char delim1 = ' ';
    char *input2 = "sample,test,string,one";
    char delim2 = ',';
    char *input3 = "sample test,string one";
    axutil_array_list_t *tokens = NULL;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);

    env = test_data->test_env;

    tokens = axutil_last_token(env, input1, delim1);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Tokenize Failed", tokens);
    if (tokens)
    {
        WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Token Count", 2,
            axutil_array_list_size(tokens, env));
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Token on Array List", "one",
            (char *)axutil_array_list_get(tokens, env, 1));
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Token on Array List", "sample test string",
            (char *)axutil_array_list_get(tokens, env, 0));
        /*while (axutil_array_list_size(tokens, env))
        {
            AXIS2_FREE(env->allocator, axutil_array_list_remove(tokens, env, 0));
        }*/
        axutil_array_list_free(tokens, env);
        tokens = NULL;
    }
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Tokenize Modified Input",
        "sample test string one", input1);
    WSF_UNIT_ASSERT_EQUALS_CHAR(tc, "Tokenize Modified Delimiter",
        ' ', delim1);

    tokens = axutil_last_token(env, input2, delim2);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Tokenize Failed", tokens);
    if (tokens)
    {
        WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Token Count", 2,
            axutil_array_list_size(tokens, env));
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Token on Array List", "one",
            (char *)axutil_array_list_get(tokens, env, 1));
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Token on Array List", "sample,test,string",
            (char *)axutil_array_list_get(tokens, env, 0));
        /*while (axutil_array_list_size(tokens, env))
        {
            AXIS2_FREE(env->allocator, axutil_array_list_remove(tokens, env, 0));
        }*/
        axutil_array_list_free(tokens, env);
        tokens = NULL;
    }
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Tokenize Modified Input",
        "sample,test,string,one", input2);
    WSF_UNIT_ASSERT_EQUALS_CHAR(tc, "Tokenize Modified Delimiter",
        ',', delim2);

    tokens = axutil_last_token(env, input3, delim1);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Tokenize Failed", tokens);
    if (tokens)
    {
        WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Token Count", 2,
            axutil_array_list_size(tokens, env));
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Token on Array List", "one",
            (char *)axutil_array_list_get(tokens, env, 1));
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Token on Array List", "sample test,string",
            (char *)axutil_array_list_get(tokens, env, 0));
        /*while (axutil_array_list_size(tokens, env))
        {
            AXIS2_FREE(env->allocator, axutil_array_list_remove(tokens, env, 0));
        }*/
        axutil_array_list_free(tokens, env);
        tokens = NULL;
    }
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Tokenize Modified Input",
        "sample test,string one", input3);
    WSF_UNIT_ASSERT_EQUALS_CHAR(tc, "Tokenize Modified Delimiter",
        ' ', delim1);

    tokens = axutil_last_token(env, input3, delim2);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Tokenize Failed", tokens);
    if (tokens)
    {
        WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Token Count", 2,
            axutil_array_list_size(tokens, env));
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Token on Array List", "string one",
            (char *)axutil_array_list_get(tokens, env, 1));
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Token on Array List", "sample test",
            (char *)axutil_array_list_get(tokens, env, 0));
        /*while (axutil_array_list_size(tokens, env))
        {
            AXIS2_FREE(env->allocator, axutil_array_list_remove(tokens, env, 0));
        }*/
        axutil_array_list_free(tokens, env);
        tokens = NULL;
    }
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Tokenize Modified Input",
        "sample test,string one", input3);
    WSF_UNIT_ASSERT_EQUALS_CHAR(tc, "Tokenize Modified Delimiter",
        ',', delim2);

    tokens = axutil_last_token(env, input2, delim1);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Tokenize Failed", tokens);
    if (tokens)
    {
        WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Token Count", 2,
            axutil_array_list_size(tokens, env));
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Token on Array List", "sample,test,string,one",
            (char *)axutil_array_list_get(tokens, env, 1));
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Token on Array List", "",
            (char *)axutil_array_list_get(tokens, env, 0));
        /*while (axutil_array_list_size(tokens, env))
        {
            AXIS2_FREE(env->allocator, axutil_array_list_remove(tokens, env, 0));
        }*/
        axutil_array_list_free(tokens, env);
        tokens = NULL;
    }
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Tokenize Modified Input",
        "sample,test,string,one", input2);
    WSF_UNIT_ASSERT_EQUALS_CHAR(tc, "Tokenize Modified Delimiter",
        ' ', delim1);
}
