
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
#include <axutil_base64_binary.h>

static void WSF_UNIT_CALL
test_axutil_base64_binary_create(    
    wsf_unit_test_case_t *tc,
    void *data);

static void WSF_UNIT_CALL
test_axutil_base64_binary_encode(    
    wsf_unit_test_case_t *tc,
    void *data);

static void WSF_UNIT_CALL
test_axutil_base64_binary_raw_binary(    
    wsf_unit_test_case_t *tc,
    void *data);

wsf_unit_status_t WSF_UNIT_CALL test_base64_binary(wsf_unit_suite_t * suite)
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

    wsf_unit_run_test(suite, test_axutil_base64_binary_create, data);
    wsf_unit_run_test(suite, test_axutil_base64_binary_encode, data);
    wsf_unit_run_test(suite, test_axutil_base64_binary_raw_binary, data);

    if (data)
    {
        data->test_env = NULL;
        if (data->test_data)
        {
            axutil_base64_binary_free((axutil_base64_binary_t *)data->test_data, env);
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

static void WSF_UNIT_CALL test_axutil_base64_binary_create(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;
    axutil_base64_binary_t *base64_binary = NULL;
    axutil_base64_binary_t *base64_binary_plain = NULL;
    FILE *input = NULL;
    long file_length = 0L;
    char *file_data = NULL;
    char *tmp1 = NULL;
    char *tmp2 = NULL;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);

    env = test_data->test_env;
    base64_binary = axutil_base64_binary_create(env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Base64 Binary Creation Failed", base64_binary);
    if (!base64_binary)
    {
        return;
    }
    test_data->test_data = base64_binary;

#ifndef WIN32
    input = fopen("resources/axis2.jpg", "r");
#else
    input = fopen("resources\\axis2.jpg", "r");
#endif

    WSF_UNIT_ASSERT_NOT_NULL(tc, "File Open Failed", input);

    if (!input)
    {
        return;
    }

    WSF_UNIT_ASSERT_EQUALS_INT(tc, "File Seek Failed", 0, fseek(input, 0L, SEEK_END));
    file_length = ftell(input);
    WSF_UNIT_ASSERT_NOT_EQUALS_LONG(tc, "Invalid File Size", 0L, file_length);
    rewind(input);
    file_data = calloc(file_length + 1, sizeof(char));

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Insufficient Memory to Read File", file_data);
    if(file_data == NULL)
    {
        if (input)
        {
            fclose(input);
        }
        return;
    }

    WSF_UNIT_ASSERT_EQUALS_SIZE(tc, "File Read Failed", 
        file_length, fread(file_data, sizeof(char), file_length, input));

    WSF_UNIT_ASSERT_TRUE(tc, "Setting Plain Binary Failed", 
    axutil_base64_binary_set_plain_binary(base64_binary, env, (unsigned char *)file_data, (int)file_length));

    base64_binary_plain = axutil_base64_binary_create_with_plain_binary(
                              env, (unsigned char *)file_data, (int)file_length);

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Base64 Binary Creation with Plain Binary Failed",
        base64_binary_plain);

    if (base64_binary_plain)
    {
        int *i = NULL;
        int *j = NULL;

        i = AXIS2_MALLOC(env->allocator, sizeof(int));
        j = AXIS2_MALLOC(env->allocator, sizeof(int));

        WSF_UNIT_ASSERT_NOT_NULL(tc, "Memory Allocation Failure", i);
        WSF_UNIT_ASSERT_NOT_NULL(tc, "Memory Allocation Failure", j);

        if (i && j)
        {
            WSF_UNIT_ASSERT_NOT_NULL(tc, "Binary Data Unavailable",
                (char *)axutil_base64_binary_get_plain_binary(base64_binary, env, i));
            WSF_UNIT_ASSERT_NOT_NULL(tc, "Binary Data Unavailable",
                (char *)axutil_base64_binary_get_plain_binary(base64_binary_plain, env, j));
            WSF_UNIT_ASSERT_EQUALS_INT(tc, "Binary Data Length Mismatch", *i, *j);
        }
        if (i)
        {
            AXIS2_FREE(env->allocator, i);
            i = NULL;
        }
        if (j)
        {
            AXIS2_FREE(env->allocator, j);
            j = NULL;
        }
        tmp1 = axutil_base64_binary_get_encoded_binary(base64_binary, env);
        WSF_UNIT_ASSERT_NOT_NULL(tc, "Retrieving Encoded Binary Failed", tmp1);
        tmp2 = axutil_base64_binary_get_encoded_binary(base64_binary_plain, env);
        WSF_UNIT_ASSERT_NOT_NULL(tc, "Retrieving Encoded Binary Failed", tmp2);
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Binary Data Mismatch", tmp1, tmp2);
        if (tmp1)
        {
            AXIS2_FREE(env->allocator, tmp1);
            tmp1 = NULL;
        }
        if (tmp2)
        {
            AXIS2_FREE(env->allocator, tmp2);
            tmp1 = NULL;
        }
        WSF_UNIT_ASSERT_NOT_EQUALS_PTR(tc, NULL, base64_binary,
            base64_binary_plain);

        axutil_base64_binary_free(base64_binary_plain, env);
    }

    if (file_data)
    {
        free(file_data);
        file_data = NULL;
    }

    if (input)
    {
        fclose(input);
    }
}

static void WSF_UNIT_CALL test_axutil_base64_binary_encode(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;
    axutil_base64_binary_t *base64_binary = NULL;
    axutil_base64_binary_t *base64_binary_encoded1 = NULL;
    axutil_base64_binary_t *base64_binary_encoded2 = NULL;
    char *tmp1 = NULL;
    char *tmp2 = NULL;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data->test_data);

    if (!test_data || !test_data->test_data)
    {
        return;
    }
    env = test_data->test_env;
    base64_binary = test_data->test_data;

    tmp1 = axutil_base64_binary_get_encoded_binary(base64_binary, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Retrieving Encoded Binary Failed", tmp1);
    if (tmp1)
    {
        base64_binary_encoded1 = axutil_base64_binary_create_with_encoded_binary(env, tmp1);
        AXIS2_FREE(env->allocator, tmp1);
        tmp1 = NULL;
    }    

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Base64 Binary Creation with Encoded Binary Failed",
        base64_binary_encoded1);

    if (base64_binary_encoded1)
    {
        int *i = NULL;
        int *j = NULL;

        i = AXIS2_MALLOC(env->allocator, sizeof(int));
        j = AXIS2_MALLOC(env->allocator, sizeof(int));

        WSF_UNIT_ASSERT_NOT_NULL(tc, "Memory Allocation Failure", i);
        WSF_UNIT_ASSERT_NOT_NULL(tc, "Memory Allocation Failure", j);

        if (i && j)
        {
            WSF_UNIT_ASSERT_NOT_NULL(tc, "Binary Data Unavailable",
                (char *)axutil_base64_binary_get_plain_binary(base64_binary, env, i));
            WSF_UNIT_ASSERT_NOT_NULL(tc, "Binary Data Unavailable",
                (char *)axutil_base64_binary_get_plain_binary(base64_binary_encoded1, env, j));
            WSF_UNIT_ASSERT_EQUALS_INT(tc, "Binary Data Length Mismatch", *i, *j);
        }
        if (i)
        {
            AXIS2_FREE(env->allocator, i);
            i = NULL;
        }
        if (j)
        {
            AXIS2_FREE(env->allocator, j);
            j = NULL;
        }
        tmp1 = axutil_base64_binary_get_encoded_binary(base64_binary, env);
        WSF_UNIT_ASSERT_NOT_NULL(tc, "Retrieving Encoded Binary Failed", tmp1);
        tmp2 = axutil_base64_binary_get_encoded_binary(base64_binary_encoded1, env);
        WSF_UNIT_ASSERT_NOT_NULL(tc, "Retrieving Encoded Binary Failed", tmp2);
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Binary Data Mismatch", tmp1, tmp2);
        if (tmp1)
        {
            AXIS2_FREE(env->allocator, tmp1);
            tmp1 = NULL;
        }
        if (tmp2)
        {
            AXIS2_FREE(env->allocator, tmp2);
            tmp1 = NULL;
        }
        WSF_UNIT_ASSERT_NOT_EQUALS_PTR(tc, NULL, base64_binary,
            base64_binary_encoded1);
    }

    base64_binary_encoded2 = axutil_base64_binary_create(env);

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Base64 Binary Creation with Encoded Binary Failed",
        base64_binary_encoded1);

    if (base64_binary_encoded2)
    {
        int *i = NULL;
        int *j = NULL;

        tmp1 = axutil_base64_binary_get_encoded_binary(base64_binary, env);
        WSF_UNIT_ASSERT_NOT_NULL(tc, "Retrieving Encoded Binary Failed", tmp1);
        axutil_base64_binary_set_encoded_binary(base64_binary_encoded2, env, tmp1);
        if (tmp1)
        {
            AXIS2_FREE(env->allocator, tmp1);
            tmp1 = NULL;
        }

        i = AXIS2_MALLOC(env->allocator, sizeof(int));
        j = AXIS2_MALLOC(env->allocator, sizeof(int));

        WSF_UNIT_ASSERT_NOT_NULL(tc, "Memory Allocation Failure", i);
        WSF_UNIT_ASSERT_NOT_NULL(tc, "Memory Allocation Failure", j);

        if (i && j)
        {
            WSF_UNIT_ASSERT_NOT_NULL(tc, "Binary Data Unavailable",
                (char *)axutil_base64_binary_get_plain_binary(base64_binary, env, i));
            WSF_UNIT_ASSERT_NOT_NULL(tc, "Binary Data Unavailable",
                (char *)axutil_base64_binary_get_plain_binary(base64_binary_encoded2, env, j));
            WSF_UNIT_ASSERT_EQUALS_INT(tc, "Binary Data Length Mismatch", *i, *j);
        }
        if (i)
        {
            AXIS2_FREE(env->allocator, i);
            i = NULL;
        }
        if (j)
        {
            AXIS2_FREE(env->allocator, j);
            j = NULL;
        }

        tmp1 = axutil_base64_binary_get_encoded_binary(base64_binary, env);
        WSF_UNIT_ASSERT_NOT_NULL(tc, "Retrieving Encoded Binary Failed", tmp1);
        tmp2 = axutil_base64_binary_get_encoded_binary(base64_binary_encoded2, env);
        WSF_UNIT_ASSERT_NOT_NULL(tc, "Retrieving Encoded Binary Failed", tmp2);
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Binary Data Mismatch", tmp1, tmp2);
        if (tmp1)
        {
            AXIS2_FREE(env->allocator, tmp1);
            tmp1 = NULL;
        }
        if (tmp2)
        {
            AXIS2_FREE(env->allocator, tmp2);
            tmp1 = NULL;
        }
        WSF_UNIT_ASSERT_NOT_EQUALS_PTR(tc, NULL, base64_binary,
            base64_binary_encoded2);

        if (base64_binary_encoded1)
        {
            tmp1 = axutil_base64_binary_get_encoded_binary(base64_binary_encoded1, env);
            WSF_UNIT_ASSERT_NOT_NULL(tc, "Retrieving Encoded Binary Failed", tmp1);
            tmp2 = axutil_base64_binary_get_encoded_binary(base64_binary_encoded2, env);
            WSF_UNIT_ASSERT_NOT_NULL(tc, "Retrieving Encoded Binary Failed", tmp2);
            WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Binary Data Mismatch", tmp1, tmp2);
            if (tmp1)
            {
                AXIS2_FREE(env->allocator, tmp1);
                tmp1 = NULL;
            }
            if (tmp2)
            {
                AXIS2_FREE(env->allocator, tmp2);
                tmp1 = NULL;
            }
            WSF_UNIT_ASSERT_EQUALS_INT(tc, "Binary Data Length Mismatch",
                axutil_base64_binary_get_decoded_binary_len(base64_binary_encoded1, env),
                axutil_base64_binary_get_decoded_binary_len(base64_binary_encoded2, env));
            WSF_UNIT_ASSERT_NOT_EQUALS_PTR(tc, NULL, base64_binary_encoded1,
                base64_binary_encoded2);

            axutil_base64_binary_free(base64_binary_encoded1, env);
        }
        axutil_base64_binary_free(base64_binary_encoded2, env);
    }
}

static void WSF_UNIT_CALL test_axutil_base64_binary_raw_binary(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;
    axutil_base64_binary_t *base64_binary = NULL;
    axutil_base64_binary_t *base64_binary_plain = NULL;
    FILE *output = NULL;
    long file_length = 0L;
    int *i = NULL;
    char *file_data = NULL;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data->test_data);

    if (!test_data || !test_data->test_data)
    {
        return;
    }
    env = test_data->test_env;
    base64_binary = test_data->test_data;

#ifndef WIN32
    output = fopen("resources/test_base64_binary_output.jpg", "w");
#else
    output = fopen("resources\\test_base64_binary_output.jpg", "w");
#endif

    WSF_UNIT_ASSERT_NOT_NULL(tc, "File Open Failed", output);

    if (!output)
    {
        if (output)
        {
            fclose(output);
        }
        return;
    }

    i = AXIS2_MALLOC(env->allocator, sizeof(int));
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Memory Allocation Failure", i);

    file_data = (char *)axutil_base64_binary_get_plain_binary(base64_binary, env, i);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Empty Binary Stream Returned", file_data);

    if (i)
    {
        file_length = (long)(*i);
        AXIS2_FREE(env->allocator, i);
        i = NULL;
    }

    WSF_UNIT_ASSERT_NOT_EQUALS_LONG(tc, "Invalid Binary Stream Length", 0L, file_length);
    
    WSF_UNIT_ASSERT_EQUALS_SIZE(tc, "File Write Failed", 
        file_length, fwrite(file_data, sizeof(char), file_length, output));

    if (file_data)
    {
        file_data = NULL;
    }

    if (output)
    {
        fclose(output);
    }
}

