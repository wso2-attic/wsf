
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
#include <axutil_url.h>

static void WSF_UNIT_CALL
test_axutil_url_create(    
    wsf_unit_test_case_t *tc,
    void *data);

static void WSF_UNIT_CALL
test_axutil_url_parse(    
    wsf_unit_test_case_t *tc,
    void *data);

static void WSF_UNIT_CALL
test_axutil_url_beans(    
    wsf_unit_test_case_t *tc,
    void *data);

wsf_unit_status_t WSF_UNIT_CALL test_url(wsf_unit_suite_t * suite)
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

    wsf_unit_run_test(suite, test_axutil_url_create, data);
    wsf_unit_run_test(suite, test_axutil_url_parse, data);
    wsf_unit_run_test(suite, test_axutil_url_beans, data);

    if (data)
    {
        data->test_env = NULL;
        if (data->test_data)
        {
            axutil_url_free((axutil_url_t *)data->test_data, env);
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

static void WSF_UNIT_CALL test_axutil_url_create(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;
    axutil_url_t *url = NULL;
    axutil_uri_t *uri = NULL;
    axutil_url_t *clone = NULL;
    char *str = NULL;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);

    env = test_data->test_env;
    url = axutil_url_create(env, "http", "home.netscape.com", 443, "/my_data");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL Create Failed", url);
    str = axutil_url_to_external_form(url, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL To External Form Failed", url);
    if (str)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "External Form Invalid",
            "http://home.netscape.com:443/my_data", str);
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    clone = axutil_url_clone(url, env);
    if (url)
    {
        test_data->test_data = url;
        url = clone;
        clone = NULL;
    }
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL Clone Failed", url);
    str = axutil_url_to_external_form(url, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL To External Form Failed", url);
    if (str)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "External Form Invalid",
            "http://home.netscape.com:443/my_data", str);
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    uri = axutil_url_to_uri(url, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL To URI Failed", uri);
    str = axutil_uri_to_string(uri, env, 0);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://home.netscape.com:443/my_data", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (url)
    {
        axutil_url_free(url, env);
        url = NULL;
    }

    url = axutil_url_create(env, "http", "home.netscape.com", 443, NULL);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL Create Failed", url);
    str = axutil_url_to_external_form(url, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL To External Form Failed", url);
    if (str)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "External Form Invalid",
            "http://home.netscape.com:443", str);
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (url)
    {
        axutil_url_free(url, env);
        url = NULL;
    }

    url = axutil_url_create(env, "http", "home.netscape.com", 0, NULL);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL Create Failed", url);
    str = axutil_url_to_external_form(url, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL To External Form Failed", url);
    if (str)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "External Form Invalid",
            "http://home.netscape.com", str);
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (url)
    {
        axutil_url_free(url, env);
        url = NULL;
    }

    url = axutil_url_create(env, "http", NULL, 443, "/my_data");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL Create Failed", url);
    str = axutil_url_to_external_form(url, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL To External Form Failed", url);
    if (str)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "External Form Invalid",
            "http:///my_data", str);
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (url)
    {
        axutil_url_free(url, env);
        url = NULL;
    }

    url = axutil_url_create(env, "http", NULL, 443, NULL);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL Create Failed", url);
    str = axutil_url_to_external_form(url, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL To External Form Failed", url);
    if (str)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "External Form Invalid",
            "http://", str);
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (url)
    {
        axutil_url_free(url, env);
        url = NULL;
    }

    url = axutil_url_create(env, "http", "home.netscape.com", 443, "/my_data?foo=bar");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL Create Failed", url);
    str = axutil_url_to_external_form(url, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL To External Form Failed", url);
    if (str)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "External Form Invalid",
            "http://home.netscape.com:443/my_data?foo=bar", str);
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (url)
    {
        axutil_url_free(url, env);
        url = NULL;
    }

    url = axutil_url_create(env, "http", "home.netscape.com", 443, "/my_data?foo=bar#rel");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL Create Failed", url);
    str = axutil_url_to_external_form(url, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL To External Form Failed", url);
    if (str)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "External Form Invalid",
            "http://home.netscape.com:443/my_data?foo=bar#rel", str);
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (url)
    {
        axutil_url_free(url, env);
        url = NULL;
    }

    url = axutil_url_create(env, "http", "home.netscape.com", 443, "/my_data#rel");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL Create Failed", url);
    str = axutil_url_to_external_form(url, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL To External Form Failed", url);
    if (str)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "External Form Invalid",
            "http://home.netscape.com:443/my_data#rel", str);
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (url)
    {
        axutil_url_free(url, env);
        url = NULL;
    }

    url = axutil_url_create(env, "http", "home.netscape.com", 443, "/");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL Create Failed", url);
    str = axutil_url_to_external_form(url, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL To External Form Failed", url);
    if (str)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "External Form Invalid",
            "http://home.netscape.com:443/", str);
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (url)
    {
        axutil_url_free(url, env);
        url = NULL;
    }

    url = axutil_url_create(env, "http", "home.netscape.com", 443, "");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL Create Failed", url);
    str = axutil_url_to_external_form(url, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL To External Form Failed", url);
    if (str)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "External Form Invalid",
            "http://home.netscape.com:443/", str);
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (url)
    {
        axutil_url_free(url, env);
        url = NULL;
    }

    url = axutil_url_create(env, "http", "home.netscape.com", 443, "my_path");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL Create Failed", url);
    str = axutil_url_to_external_form(url, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL To External Form Failed", url);
    if (str)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "External Form Invalid",
            "http://home.netscape.com:443/my_path", str);
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (url)
    {
        axutil_url_free(url, env);
        url = NULL;
    }

    url = axutil_url_create(env, "https", "home.netscape.com", 443, "my_path");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL Create Failed", url);
    str = axutil_url_to_external_form(url, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL To External Form Failed", url);
    if (str)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "External Form Invalid",
            "https://home.netscape.com/my_path", str);
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (url)
    {
        axutil_url_free(url, env);
        url = NULL;
    }

    url = axutil_url_create(env, "http", "home.netscape.com/path", 443, NULL);
    WSF_UNIT_ASSERT_NULL(tc, "URL Create Must Fail But, Didn't", url);
    if (url)
    {
        axutil_url_free(url, env);
        url = NULL;
    }

    url = axutil_url_create(env, "http://", "home.netscape.com", 443, NULL);
    WSF_UNIT_ASSERT_NULL(tc, "URL Create Must Fail But, Didn't", url);
    if (url)
    {
        axutil_url_free(url, env);
        url = NULL;
    }

    url = axutil_url_create(env, "", "home.netscape.com", 443, NULL);
    WSF_UNIT_ASSERT_NULL(tc, "URL Create Must Fail But, Didn't", url);
    if (url)
    {
        axutil_url_free(url, env);
        url = NULL;
    }

    url = axutil_url_create(env, NULL, "home.netscape.com", 443, NULL);
    WSF_UNIT_ASSERT_NULL(tc, "URL Create Must Fail But, Didn't", url);
    if (url)
    {
        axutil_url_free(url, env);
        url = NULL;
    }
}

static void WSF_UNIT_CALL test_axutil_url_parse(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;
    axutil_url_t *url = NULL;
    char *str = NULL;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);

    env = test_data->test_env;

    url = axutil_url_parse_string(env, "http://home.netscape.com:443");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL Parse Failed", url);
    str = axutil_url_to_external_form(url, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL To External Form Failed", url);
    if (str)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "External Form Invalid",
            "http://home.netscape.com:443/", str);
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (url)
    {
        axutil_url_free(url, env);
        url = NULL;
    }

    url = axutil_url_parse_string(env, "http://home.netscape.com/path?foo=bar");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL Parse Failed", url);
    str = axutil_url_to_external_form(url, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL To External Form Failed", url);
    if (str)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "External Form Invalid",
            "http://home.netscape.com/path?foo=bar", str);
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (url)
    {
        axutil_url_free(url, env);
        url = NULL;
    }

    url = axutil_url_parse_string(env, "http://home.netscape.com:443/path?foo=bar");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL Parse Failed", url);
    str = axutil_url_to_external_form(url, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL To External Form Failed", url);
    if (str)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "External Form Invalid",
            "http://home.netscape.com:443/path?foo=bar", str);
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (url)
    {
        axutil_url_free(url, env);
        url = NULL;
    }

    url = axutil_url_parse_string(env, "http://home.netscape.com:443/path?foo=bar#rel");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL Parse Failed", url);
    str = axutil_url_to_external_form(url, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL To External Form Failed", url);
    if (str)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "External Form Invalid",
            "http://home.netscape.com:443/path?foo=bar#rel", str);
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (url)
    {
        axutil_url_free(url, env);
        url = NULL;
    }

    url = axutil_url_parse_string(env, "http://home.netscape.com:443/path#rel");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL Parse Failed", url);
    str = axutil_url_to_external_form(url, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL To External Form Failed", url);
    if (str)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "External Form Invalid",
            "http://home.netscape.com:443/path#rel", str);
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (url)
    {
        axutil_url_free(url, env);
        url = NULL;
    }

    url = axutil_url_parse_string(env, "http://home.netscape.com");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL Parse Failed", url);
    str = axutil_url_to_external_form(url, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL To External Form Failed", url);
    if (str)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "External Form Invalid",
            "http://home.netscape.com/", str);
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (url)
    {
        axutil_url_free(url, env);
        url = NULL;
    }

    url = axutil_url_parse_string(env, "file://");
    WSF_UNIT_ASSERT_NULL(tc, "URL Parse Should Fail. But, Didn't", url);
    if (url)
    {
        axutil_url_free(url, env);
        url = NULL;
    }

    url = axutil_url_parse_string(env, "http://");
    WSF_UNIT_ASSERT_NULL(tc, "URL Parse Should Fail. But, Didn't", url);
    if (url)
    {
        axutil_url_free(url, env);
        url = NULL;
    }

    url = axutil_url_parse_string(env, "https://home.netscape.com");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL Parse Failed", url);
    str = axutil_url_to_external_form(url, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL To External Form Failed", url);
    if (str)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "External Form Invalid",
            "https://home.netscape.com/", str);
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (url)
    {
        axutil_url_free(url, env);
        url = NULL;
    }

    url = axutil_url_parse_string(env, "https://home.netscape.com:443");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL Parse Failed", url);
    str = axutil_url_to_external_form(url, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL To External Form Failed", url);
    if (str)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "External Form Invalid",
            "https://home.netscape.com/", str);
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Get Port Failed",
        443, axutil_url_get_port(url, env));
    if (url)
    {
        axutil_url_free(url, env);
        url = NULL;
    }

    url = axutil_url_parse_string(env, "http://home.netscape.com");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL Parse Failed", url);
    str = axutil_url_to_external_form(url, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL To External Form Failed", url);
    if (str)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "External Form Invalid",
            "http://home.netscape.com/", str);
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Get Port Failed",
        80, axutil_url_get_port(url, env));
    if (url)
    {
        axutil_url_free(url, env);
        url = NULL;
    }

    url = axutil_url_parse_string(env, "file:///path");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL Parse Failed", url);
    str = axutil_url_to_external_form(url, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL To External Form Failed", url);
    if (str)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "External Form Invalid",
            "file:///path", str);
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (url)
    {
        axutil_url_free(url, env);
        url = NULL;
    }
}

static void WSF_UNIT_CALL test_axutil_url_beans(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;
    axutil_url_t *url = NULL;
    char *str = NULL;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);

    env = test_data->test_env;
    url = axutil_url_create(env, "http", "home.netscape.com", 443, "/my_data");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL Create Failed", url);
    str = axutil_url_to_external_form(url, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL To External Form Failed", url);
    if (str)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "External Form Invalid",
            "http://home.netscape.com:443/my_data", str);
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Get Protocol Failed",
        "http", axutil_url_get_protocol(url, env));
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Get Server Failed",
        "home.netscape.com:443", axutil_url_get_server(url, env));
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Get Host Failed",
        "home.netscape.com", axutil_url_get_host(url, env));
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Get Path Failed",
        "/my_data", axutil_url_get_path(url, env));
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Get Port Failed",
        443, axutil_url_get_port(url, env));

    WSF_UNIT_ASSERT_TRUE(tc, "Set Protocol Failed",
        axutil_url_set_protocol(url, env, "https"));
    str = axutil_url_to_external_form(url, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL To External Form Failed", url);
    if (str)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "External Form Invalid",
            "https://home.netscape.com/my_data", str);
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }

    WSF_UNIT_ASSERT_TRUE(tc, "Set Server Failed",
        axutil_url_set_server(url, env, "sample.netscape.com:445"));
    str = axutil_url_to_external_form(url, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL To External Form Failed", url);
    if (str)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "External Form Invalid",
            "https://sample.netscape.com:445/my_data", str);
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Get Port Failed",
        445, axutil_url_get_port(url, env));

    WSF_UNIT_ASSERT_TRUE(tc, "Set Host Failed",
        axutil_url_set_host(url, env, "changed.netscape.com"));
    str = axutil_url_to_external_form(url, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL To External Form Failed", url);
    if (str)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "External Form Invalid",
            "https://changed.netscape.com:445/my_data", str);
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }

    WSF_UNIT_ASSERT_TRUE(tc, "Set Path Failed",
        axutil_url_set_path(url, env, "/new"));
    str = axutil_url_to_external_form(url, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL To External Form Failed", url);
    if (str)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "External Form Invalid",
            "https://changed.netscape.com:445/new", str);
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }

    WSF_UNIT_ASSERT_TRUE(tc, "Set Port Failed",
        axutil_url_set_port(url, env, 9090));
    str = axutil_url_to_external_form(url, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URL To External Form Failed", url);
    if (str)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "External Form Invalid",
            "https://changed.netscape.com:9090/new", str);
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Get Server Failed",
        "changed.netscape.com:9090", axutil_url_get_server(url, env));

    if (url)
    {
        axutil_url_free(url, env);
        url = NULL;
    }
}
