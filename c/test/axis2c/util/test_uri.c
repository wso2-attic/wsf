
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
#include <axutil_uri.h>

static void test_axutil_uri_create(    
    wsf_unit_test_case_t *tc,
    void *data);

static void test_axutil_uri_parse_hostinfo(    
    wsf_unit_test_case_t *tc,
    void *data);

static void test_axutil_uri_parse_string(    
    wsf_unit_test_case_t *tc,
    void *data);

wsf_unit_status_t WSF_UNIT_CALL test_uri(wsf_unit_suite_t * suite)
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

    wsf_unit_run_test(suite, test_axutil_uri_create, data);
    wsf_unit_run_test(suite, test_axutil_uri_parse_hostinfo, data);
    wsf_unit_run_test(suite, test_axutil_uri_parse_string, data);

    if (data)
    {
        data->test_env = NULL;
        if (data->test_data)
        {
            axutil_uri_free((axutil_uri_t *)data->test_data, env);
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

static void WSF_UNIT_CALL test_axutil_uri_create(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;
    axutil_uri_t *uri = NULL;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);

    env = test_data->test_env;
    uri = (axutil_uri_t *)axutil_uri_create(env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI Create Failed", uri);
    if (uri)
    {
        test_data->test_data = uri;
    }
    WSF_UNIT_FAIL(tc, "Add axutil_uri_create to Header and Remove this");
}

static void WSF_UNIT_CALL test_axutil_uri_parse_hostinfo(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;
    axutil_uri_t *uri = NULL;
    char *str = NULL;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);

    if (!test_data || !test_data->test_env)
    {
        return;
    }

    env = test_data->test_env;
    
    uri = axutil_uri_parse_hostinfo(env, "home.netscape.com:443");

    WSF_UNIT_ASSERT_NOT_NULL(tc, "CONNECT Parsing Failed", uri);

    WSF_UNIT_ASSERT_EQUALS_INT(tc, "CONNECT Parsing Identified Invalid Port",
        443, (int)axutil_uri_get_port(uri, env));

    str = axutil_uri_get_server(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Server Failed", str);

    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "CONNECT Parsing Identified Invalid Server",
        "home.netscape.com:443", str);

    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }

    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_hostinfo(env, "[sample.ipvsix.com]:443");

    WSF_UNIT_ASSERT_NOT_NULL(tc, "CONNECT Parsing Failed", uri);

    WSF_UNIT_ASSERT_EQUALS_INT(tc, "CONNECT Parsing Identified Invalid Port",
        443, (int)axutil_uri_get_port(uri, env));

    str = axutil_uri_get_server(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Server Failed", str);

    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "CONNECT Parsing Identified Invalid Server",
        "[sample.ipvsix.com]:443", str);

    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }

    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_hostinfo(env, "192.168.0.1:443");

    WSF_UNIT_ASSERT_NOT_NULL(tc, "CONNECT Parsing Failed", uri);

    WSF_UNIT_ASSERT_EQUALS_INT(tc, "CONNECT Parsing Identified Invalid Port",
        443, (int)axutil_uri_get_port(uri, env));

    str = axutil_uri_get_server(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Server Failed", str);

    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "CONNECT Parsing Identified Invalid Server",
        "192.168.0.1:443", str);

    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }

    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    /* Error Tests */
    uri = axutil_uri_parse_hostinfo(env, "home.netscape.com");

    WSF_UNIT_ASSERT_NULL(tc, "CONNECT Parsing Must Fail But, Didn't", uri);
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
    }

    uri = axutil_uri_parse_hostinfo(env, "home.netscape.com:443/extra");

    WSF_UNIT_ASSERT_NULL(tc, "CONNECT Parsing Must Fail But, Didn't", uri);
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_hostinfo(env, "home.netscape.com:443?extra");

    WSF_UNIT_ASSERT_NULL(tc, "CONNECT Parsing Must Fail But, Didn't", uri);
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_hostinfo(env, "home.netscape.com:443#extra");

    WSF_UNIT_ASSERT_NULL(tc, "CONNECT Parsing Must Fail But, Didn't", uri);
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_hostinfo(env, "http://home.netscape.com:443");

    WSF_UNIT_ASSERT_NULL(tc, "CONNECT Parsing Must Fail But, Didn't", uri);
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_hostinfo(env, "//home.netscape.com:443");

    WSF_UNIT_ASSERT_NULL(tc, "CONNECT Parsing Must Fail But, Didn't", uri);
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_hostinfo(env, ".home.netscape.com:443");

    WSF_UNIT_ASSERT_NULL(tc, "CONNECT Parsing Must Fail But, Didn't", uri);
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_hostinfo(env, "[home.netscape.com]:443");

    WSF_UNIT_ASSERT_NULL(tc, "CONNECT Parsing Must Fail But, Didn't", uri);
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }
    /* End of Error Tests */
    WSF_UNIT_FAIL(tc, "No Method to get Hostname");
    WSF_UNIT_FAIL(tc, "axutil_uri_get_server Returns Reference but NO Documentation");
}

static void WSF_UNIT_CALL test_axutil_uri_parse_string(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;
    axutil_uri_t *uri = NULL;
    char *str = NULL;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);

    if (!test_data || !test_data->test_env)
    {
        return;
    }

    env = test_data->test_env;
    
    uri = axutil_uri_parse_string(env, "http://home.netscape.com");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", uri);
    str = axutil_uri_get_server(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Server Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "String Parsing Identified Invalid Server",
        "home.netscape.com", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_protocol(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Protocol",
        "http", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, 0);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://home.netscape.com", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_string(env, "http://home.netscape.com:9090");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", uri);
    str = axutil_uri_get_server(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Server Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "String Parsing Identified Invalid Server",
        "home.netscape.com:9090", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "String Parsing Identified Invalid Port",
        9090, (int)axutil_uri_get_port(uri, env));
    str = axutil_uri_get_protocol(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Protocol",
        "http", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, 0);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://home.netscape.com:9090", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_string(env, "http://home.netscape.com:9090?foo=bar");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", uri);
    str = axutil_uri_get_server(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Server Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "String Parsing Identified Invalid Server",
        "home.netscape.com:9090", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "String Parsing Identified Invalid Port",
        9090, (int)axutil_uri_get_port(uri, env));
    str = axutil_uri_get_protocol(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Protocol",
        "http", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, 0);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://home.netscape.com:9090?foo=bar", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_string(env, "http://home.netscape.com?foo=bar");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", uri);
    str = axutil_uri_get_server(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Server Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "String Parsing Identified Invalid Server",
        "home.netscape.com", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_protocol(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Protocol",
        "http", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, 0);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://home.netscape.com?foo=bar", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_string(env, "http://home.netscape.com:9090?foo=bar#rel");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", uri);
    str = axutil_uri_get_server(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Server Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "String Parsing Identified Invalid Server",
        "home.netscape.com:9090", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "String Parsing Identified Invalid Port",
        9090, (int)axutil_uri_get_port(uri, env));
    str = axutil_uri_get_protocol(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Protocol",
        "http", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, 0);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://home.netscape.com:9090?foo=bar#rel", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_string(env, "http://home.netscape.com?foo=bar#rel");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", uri);
    str = axutil_uri_get_server(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Server Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "String Parsing Identified Invalid Server",
        "home.netscape.com", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_protocol(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Protocol",
        "http", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, 0);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://home.netscape.com?foo=bar#rel", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_string(env, "http://home.netscape.com#rel");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", uri);
    str = axutil_uri_get_server(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Server Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "String Parsing Identified Invalid Server",
        "home.netscape.com", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_protocol(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Protocol",
        "http", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, 0);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://home.netscape.com#rel", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_string(env, "http://home.netscape.com:9090#rel");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", uri);
    str = axutil_uri_get_server(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Server Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "String Parsing Identified Invalid Server",
        "home.netscape.com:9090", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_protocol(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Protocol",
        "http", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, 0);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://home.netscape.com:9090#rel", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_string(env, "http://user:pass@home.netscape.com:9090?foo=bar#rel");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", uri);
    str = axutil_uri_get_server(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Server Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "String Parsing Identified Invalid Server",
        "user:pass@home.netscape.com:9090", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "String Parsing Identified Invalid Port",
        9090, (int)axutil_uri_get_port(uri, env));
    str = axutil_uri_get_protocol(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Protocol",
        "http", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, AXIS2_URI_UNP_REVEALPASSWORD);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://user:pass@home.netscape.com:9090?foo=bar#rel", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_string(env, "http://user:pass@home.netscape.com:9090#rel");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", uri);
    str = axutil_uri_get_server(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Server Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "String Parsing Identified Invalid Server",
        "user:pass@home.netscape.com:9090", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "String Parsing Identified Invalid Port",
        9090, (int)axutil_uri_get_port(uri, env));
    str = axutil_uri_get_protocol(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Protocol",
        "http", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, AXIS2_URI_UNP_REVEALPASSWORD);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://user:pass@home.netscape.com:9090#rel", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_string(env, "http://user:pass@home.netscape.com:9090?foo=bar");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", uri);
    str = axutil_uri_get_server(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Server Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "String Parsing Identified Invalid Server",
        "user:pass@home.netscape.com:9090", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "String Parsing Identified Invalid Port",
        9090, (int)axutil_uri_get_port(uri, env));
    str = axutil_uri_get_protocol(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Protocol",
        "http", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, AXIS2_URI_UNP_REVEALPASSWORD);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://user:pass@home.netscape.com:9090?foo=bar", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_string(env, "http://user:pass@home.netscape.com:9090");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", uri);
    str = axutil_uri_get_server(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Server Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "String Parsing Identified Invalid Server",
        "user:pass@home.netscape.com:9090", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "String Parsing Identified Invalid Port",
        9090, (int)axutil_uri_get_port(uri, env));
    str = axutil_uri_get_protocol(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Protocol",
        "http", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, AXIS2_URI_UNP_REVEALPASSWORD);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://user:pass@home.netscape.com:9090", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_string(env, "http://user:pass@home.netscape.com?foo=bar#rel");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", uri);
    str = axutil_uri_get_server(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Server Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "String Parsing Identified Invalid Server",
        "user:pass@home.netscape.com", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_protocol(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Protocol",
        "http", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, AXIS2_URI_UNP_REVEALPASSWORD);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://user:pass@home.netscape.com?foo=bar#rel", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_string(env, "http://user:pass@home.netscape.com?foo=bar");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", uri);
    str = axutil_uri_get_server(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Server Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "String Parsing Identified Invalid Server",
        "user:pass@home.netscape.com", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_protocol(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Protocol",
        "http", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, AXIS2_URI_UNP_REVEALPASSWORD);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://user:pass@home.netscape.com?foo=bar", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_string(env, "http://user:pass@home.netscape.com#rel");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", uri);
    str = axutil_uri_get_server(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Server Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "String Parsing Identified Invalid Server",
        "user:pass@home.netscape.com", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_protocol(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Protocol",
        "http", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, AXIS2_URI_UNP_REVEALPASSWORD);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://user:pass@home.netscape.com#rel", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_string(env, "http://user:pass@home.netscape.com");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", uri);
    str = axutil_uri_get_server(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Server Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "String Parsing Identified Invalid Server",
        "user:pass@home.netscape.com", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_protocol(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Protocol",
        "http", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, AXIS2_URI_UNP_REVEALPASSWORD);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://user:pass@home.netscape.com", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_string(env, "http://home.netscape.com/path");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", uri);
    str = axutil_uri_get_server(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Server Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "String Parsing Identified Invalid Server",
        "home.netscape.com", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_protocol(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Protocol",
        "http", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_path(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Path",
        "/path", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, 0);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://home.netscape.com/path", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_string(env, "http://home.netscape.com:9090/path");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", uri);
    str = axutil_uri_get_server(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Server Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "String Parsing Identified Invalid Server",
        "home.netscape.com:9090", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "String Parsing Identified Invalid Port",
        9090, (int)axutil_uri_get_port(uri, env));
    str = axutil_uri_get_protocol(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Protocol",
        "http", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_path(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Path",
        "/path", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, 0);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://home.netscape.com:9090/path", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_string(env, "http://home.netscape.com:9090/path?foo=bar");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", uri);
    str = axutil_uri_get_server(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Server Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "String Parsing Identified Invalid Server",
        "home.netscape.com:9090", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "String Parsing Identified Invalid Port",
        9090, (int)axutil_uri_get_port(uri, env));
    str = axutil_uri_get_protocol(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Protocol",
        "http", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_path(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Path",
        "/path", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, 0);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://home.netscape.com:9090/path?foo=bar", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_string(env, "http://home.netscape.com/path?foo=bar");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", uri);
    str = axutil_uri_get_server(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Server Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "String Parsing Identified Invalid Server",
        "home.netscape.com", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_protocol(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Protocol",
        "http", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_path(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Path",
        "/path", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, 0);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://home.netscape.com/path?foo=bar", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_string(env, "http://home.netscape.com:9090/path?foo=bar#rel");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", uri);
    str = axutil_uri_get_server(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Server Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "String Parsing Identified Invalid Server",
        "home.netscape.com:9090", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "String Parsing Identified Invalid Port",
        9090, (int)axutil_uri_get_port(uri, env));
    str = axutil_uri_get_protocol(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Protocol",
        "http", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_path(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Path",
        "/path", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, 0);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://home.netscape.com:9090/path?foo=bar#rel", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_string(env, "http://home.netscape.com/path?foo=bar#rel");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", uri);
    str = axutil_uri_get_server(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Server Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "String Parsing Identified Invalid Server",
        "home.netscape.com", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_protocol(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Protocol",
        "http", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_path(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Path",
        "/path", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, 0);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://home.netscape.com/path?foo=bar#rel", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_string(env, "http://home.netscape.com/path#rel");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", uri);
    str = axutil_uri_get_server(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Server Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "String Parsing Identified Invalid Server",
        "home.netscape.com", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_protocol(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Protocol",
        "http", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_path(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Path",
        "/path", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, 0);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://home.netscape.com/path#rel", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_string(env, "http://home.netscape.com:9090/path#rel");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", uri);
    str = axutil_uri_get_server(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Server Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "String Parsing Identified Invalid Server",
        "home.netscape.com:9090", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_protocol(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Protocol",
        "http", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_path(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Path",
        "/path", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, 0);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://home.netscape.com:9090/path#rel", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_string(env, "http://user:pass@home.netscape.com:9090/path?foo=bar#rel");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", uri);
    str = axutil_uri_get_server(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Server Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "String Parsing Identified Invalid Server",
        "user:pass@home.netscape.com:9090", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "String Parsing Identified Invalid Port",
        9090, (int)axutil_uri_get_port(uri, env));
    str = axutil_uri_get_protocol(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Protocol",
        "http", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_path(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Path",
        "/path", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, AXIS2_URI_UNP_REVEALPASSWORD);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://user:pass@home.netscape.com:9090/path?foo=bar#rel", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_string(env, "http://user:pass@home.netscape.com:9090/path#rel");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", uri);
    str = axutil_uri_get_server(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Server Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "String Parsing Identified Invalid Server",
        "user:pass@home.netscape.com:9090", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "String Parsing Identified Invalid Port",
        9090, (int)axutil_uri_get_port(uri, env));
    str = axutil_uri_get_protocol(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Protocol",
        "http", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_path(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Path",
        "/path", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, AXIS2_URI_UNP_REVEALPASSWORD);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://user:pass@home.netscape.com:9090/path#rel", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_string(env, "http://user:pass@home.netscape.com:9090/path?foo=bar");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", uri);
    str = axutil_uri_get_server(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Server Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "String Parsing Identified Invalid Server",
        "user:pass@home.netscape.com:9090", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "String Parsing Identified Invalid Port",
        9090, (int)axutil_uri_get_port(uri, env));
    str = axutil_uri_get_protocol(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Protocol",
        "http", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_path(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Path",
        "/path", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, AXIS2_URI_UNP_REVEALPASSWORD);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://user:pass@home.netscape.com:9090/path?foo=bar", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_string(env, "http://user:pass@home.netscape.com:9090/path");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", uri);
    str = axutil_uri_get_server(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Server Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "String Parsing Identified Invalid Server",
        "user:pass@home.netscape.com:9090", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "String Parsing Identified Invalid Port",
        9090, (int)axutil_uri_get_port(uri, env));
    str = axutil_uri_get_protocol(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Protocol",
        "http", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_path(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Path",
        "/path", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, AXIS2_URI_UNP_REVEALPASSWORD);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://user:pass@home.netscape.com:9090/path", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_string(env, "http://user:pass@home.netscape.com/path?foo=bar#rel");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", uri);
    str = axutil_uri_get_server(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Server Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "String Parsing Identified Invalid Server",
        "user:pass@home.netscape.com", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_protocol(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Protocol",
        "http", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_path(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Path",
        "/path", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, AXIS2_URI_UNP_REVEALPASSWORD);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://user:pass@home.netscape.com/path?foo=bar#rel", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_string(env, "http://user:pass@home.netscape.com/path?foo=bar");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", uri);
    str = axutil_uri_get_server(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Server Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "String Parsing Identified Invalid Server",
        "user:pass@home.netscape.com", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_protocol(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Protocol",
        "http", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_path(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Path",
        "/path", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, AXIS2_URI_UNP_REVEALPASSWORD);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://user:pass@home.netscape.com/path?foo=bar", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_string(env, "http://user:pass@home.netscape.com/path#rel");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", uri);
    str = axutil_uri_get_server(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Server Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "String Parsing Identified Invalid Server",
        "user:pass@home.netscape.com", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_protocol(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Protocol",
        "http", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_path(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Path",
        "/path", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, AXIS2_URI_UNP_REVEALPASSWORD);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://user:pass@home.netscape.com/path#rel", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_string(env, "http://user:pass@home.netscape.com/path");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", uri);
    str = axutil_uri_get_server(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Server Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "String Parsing Identified Invalid Server",
        "user:pass@home.netscape.com", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_protocol(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Protocol",
        "http", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_path(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Path",
        "/path", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_path(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Path",
        "/path", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, AXIS2_URI_UNP_REVEALPASSWORD);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://user:pass@home.netscape.com/path", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    /* Abbreviated URLs
     * In order to preserve API consistency, we'll have to recognize
     * these cases as scheme-less URIs.
     */
    uri = axutil_uri_parse_string(env, "home.netscape.com");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", uri);
    str = axutil_uri_get_server(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Server Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "String Parsing Identified Invalid Server",
        "home.netscape.com", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_path(uri, env);
    WSF_UNIT_ASSERT_NULL(tc, "Get Path Must Fail. But, Didn't", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, 0);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "home.netscape.com", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_string(env, "home.netscape.com:9090/path?foo=bar#rel");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", uri);
    str = axutil_uri_get_server(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Server Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "String Parsing Identified Invalid Server",
        "home.netscape.com:9090", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "String Parsing Identified Invalid Port",
        9090, (int)axutil_uri_get_port(uri, env));
    str = axutil_uri_get_path(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Protocol Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Path",
        "/path", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, 0);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://home.netscape.com:9090/path?foo=bar#rel", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }
    /* End of Abbreviated URI Block */

    /* Error Cases */
    uri = axutil_uri_parse_string(env, ".home.netscape.com:9090/path?foo=bar#rel");
    WSF_UNIT_ASSERT_NULL(tc, "String Parsing Should Fail. But, Didn't", uri);
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }
    uri = axutil_uri_parse_string(env, "//home.netscape.com:9090/path?foo=bar#rel");
    WSF_UNIT_ASSERT_NULL(tc, "String Parsing Should Fail. But, Didn't", uri);
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }
    uri = axutil_uri_parse_string(env, "htpp://home.netscape.com:9090/path?foo=bar#rel");
    WSF_UNIT_ASSERT_NULL(tc, "String Parsing Should Fail. But, Didn't", uri);
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }
    uri = axutil_uri_parse_string(env, "http://home.netscape.com:9090//path?foo=bar#rel");
    WSF_UNIT_ASSERT_NULL(tc, "String Parsing Should Fail. But, Didn't", uri);
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }
    uri = axutil_uri_parse_string(env, "http://home.netscape.com/path:9090?foo=bar#rel");
    WSF_UNIT_ASSERT_NULL(tc, "String Parsing Should Fail. But, Didn't", uri);
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }
    uri = axutil_uri_parse_string(env, "http:9090//home.netscape.com/path?foo=bar#rel");
    WSF_UNIT_ASSERT_NULL(tc, "String Parsing Should Fail. But, Didn't", uri);
    if (uri)
    {
        axutil_uri_free((axutil_uri_t *)uri, env);
        uri = NULL;
    }
    /* End of Error Cases */

    WSF_UNIT_FAIL(tc, "No Method to get Hostname");
    WSF_UNIT_FAIL(tc, "No Method to get Query");
    WSF_UNIT_FAIL(tc, "No Method to get Fragment");
    WSF_UNIT_FAIL(tc, "axutil_uri_get_path Returns Reference but NO Documentation");
    WSF_UNIT_FAIL(tc, "axutil_uri_get_server Returns Reference but NO Documentation");
    WSF_UNIT_FAIL(tc, "axutil_uri_get_protocol Returns Reference but NO Documentation");
}
