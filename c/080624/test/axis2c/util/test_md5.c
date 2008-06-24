
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
#include <axutil_md5.h>

typedef struct test_axutil_md5
    test_axutil_md5_t;

static void WSF_UNIT_CALL
test_axutil_md5_md_string(
   wsf_unit_test_case_t *tc,
   void *data);

struct test_axutil_md5
{
    char *in;
    char *out;
};

wsf_unit_status_t WSF_UNIT_CALL test_md5(wsf_unit_suite_t * suite)
{
    wsf_unit_status_t status = WSF_UNIT_FAILURE;
    axutil_env_t *env = NULL;
    axutil_test_data_t *data = NULL;
    test_axutil_md5_t *test_data = NULL;

    char *md_in_str1 = "";
    char *md_in_str2 = "a";
    char *md_in_str3 = "abc";
    char *md_in_str4 = "message digest";
    char *md_in_str5 = "abcdefghijklmnopqrstuvwxyz";
    char *md_in_str6 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    char *md_in_str7 = "12345678901234567890123456789012345678901234567890123456789012345678901234567890";

    char *md_out_str1 = "d41d8cd98f00b204e9800998ecf8427e";
    char *md_out_str2 = "0cc175b9c0f1b6a831c399e269772661";
    char *md_out_str3 = "900150983cd24fb0d6963f7d28e17f72";
    char *md_out_str4 = "f96b697d7cb7938d525a2f31aaf161d0";
    char *md_out_str5 = "c3fcd3d76192e4007dfb496cca67e13b";
    char *md_out_str6 = "d174ab98d277d9f5a5611c2c9f419d9f";
    char *md_out_str7 = "57edf4a22be3c955ac49da2e2107b67a";

    status = WSF_UNIT_ADD_SUB_SUITE(suite);

    env = CREATE_TEST_ENV();
    if (env)
    {
        data = AXIS2_MALLOC(env->allocator, sizeof(axutil_test_data_t));
    }
    if (data)
    {
        data->test_env = env;
        test_data = AXIS2_MALLOC(env->allocator, sizeof(test_axutil_md5_t));
        if (test_data)
        {
            data->test_data = test_data;
            test_data->in = NULL;
            test_data->out = NULL;
        }
        else
        {
            data->test_data = NULL;
        }
    }

    test_data->in = md_in_str1;
    test_data->out = md_out_str1;
    wsf_unit_run_test(suite, test_axutil_md5_md_string, data);

    test_data->in = md_in_str2;
    test_data->out = md_out_str2;
    wsf_unit_run_test(suite, test_axutil_md5_md_string, data);

    test_data->in = md_in_str3;
    test_data->out = md_out_str3;
    wsf_unit_run_test(suite, test_axutil_md5_md_string, data);

    test_data->in = md_in_str4;
    test_data->out = md_out_str4;
    wsf_unit_run_test(suite, test_axutil_md5_md_string, data);

    test_data->in = md_in_str5;
    test_data->out = md_out_str5;
    wsf_unit_run_test(suite, test_axutil_md5_md_string, data);

    test_data->in = md_in_str6;
    test_data->out = md_out_str6;
    wsf_unit_run_test(suite, test_axutil_md5_md_string, data);

    test_data->in = md_in_str7;
    test_data->out = md_out_str7;
    wsf_unit_run_test(suite, test_axutil_md5_md_string, data);

    if (test_data)
    {
        AXIS2_FREE(env->allocator, test_data);
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

static void WSF_UNIT_CALL test_axutil_md5_md_string(wsf_unit_test_case_t *tc, void *data)
{
    axutil_md5_ctx_t * context = NULL;
    unsigned char digest[16];
    unsigned int i = 0;
    unsigned int len = 0;
    char *out_str = NULL;
    char *temp = NULL;
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = NULL;
    test_axutil_md5_t *md5_data = NULL;

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
        md5_data = (test_axutil_md5_t *)test_data->test_data;
    }
    else
    {
        return;
    }

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", md5_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "MD5 Input Unavailable", md5_data->in);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "MD5 Output Unavailable", md5_data->out);

    if (!md5_data || !md5_data->in || !md5_data->out)
    {
        return;
    }

    len = axutil_strlen(md5_data->in);

    out_str = AXIS2_MALLOC(env->allocator, sizeof(char)*33);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Insufficient memory", out_str);
    if (!out_str)
    {
        return;
    }

    context = axutil_md5_ctx_create(env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "MD5 Context is NULL", context);
    if (!context)
    {
        return;
    }

    axutil_md5_update(context, env, md5_data->in, len);
    axutil_md5_final(context, env, digest);
    axutil_md5_ctx_free(context, env);

    temp = out_str;
    for (i = 0; i < 16; i++)
    {
        sprintf(temp, "%02x", digest[i]);
        temp += 2;
    }
  
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, NULL, md5_data->out, out_str);
    if (out_str)
    {
        AXIS2_FREE(env->allocator, out_str);
    }
    env = NULL;
}
