
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

static void WSF_UNIT_CALL
test_axutil_uri_create(    
    wsf_unit_test_case_t *tc,
    void *data);

static void WSF_UNIT_CALL
test_axutil_uri_parse_hostinfo(    
    wsf_unit_test_case_t *tc,
    void *data);

static void WSF_UNIT_CALL
test_axutil_uri_parse_string(    
    wsf_unit_test_case_t *tc,
    void *data);

static void WSF_UNIT_CALL
test_axutil_uri_parse_relative(    
    wsf_unit_test_case_t *tc,
    void *data);

static void WSF_UNIT_CALL
test_axutil_uri_port_of_scheme(    
    wsf_unit_test_case_t *tc,
    void *data);

static void WSF_UNIT_CALL
test_axutil_uri_to_string(    
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
    wsf_unit_run_test(suite, test_axutil_uri_parse_relative, data);
    wsf_unit_run_test(suite, test_axutil_uri_port_of_scheme, data);
    wsf_unit_run_test(suite, test_axutil_uri_to_string, data);

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

    str = axutil_uri_get_host(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Host Failed", str);

    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "CONNECT Parsing Identified Invalid Host",
        "home.netscape.com", str);

    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }

    if (uri)
    {
        axutil_uri_free(uri, env);
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

    str = axutil_uri_get_host(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Host Failed", str);

    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "CONNECT Parsing Identified Invalid Host",
        "sample.ipvsix.com", str);

    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }

    if (uri)
    {
        axutil_uri_free(uri, env);
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

    str = axutil_uri_get_host(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Host Failed", str);

    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "CONNECT Parsing Identified Invalid Host",
        "192.168.0.1", str);

    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }

    if (uri)
    {
        axutil_uri_free(uri, env);
        uri = NULL;
    }

    /* Error Tests */
    uri = axutil_uri_parse_hostinfo(env, "home.netscape.com");

    WSF_UNIT_ASSERT_NULL(tc, "CONNECT Parsing Must Fail But, Didn't", uri);
    if (uri)
    {
        axutil_uri_free(uri, env);
    }

    uri = axutil_uri_parse_hostinfo(env, ":443");

    WSF_UNIT_ASSERT_NULL(tc, "CONNECT Parsing Must Fail But, Didn't", uri);
    if (uri)
    {
        axutil_uri_free(uri, env);
    }

    uri = axutil_uri_parse_hostinfo(env, "[]:443");

    WSF_UNIT_ASSERT_NULL(tc, "CONNECT Parsing Must Fail But, Didn't", uri);
    if (uri)
    {
        axutil_uri_free(uri, env);
    }

    uri = axutil_uri_parse_hostinfo(env, "home.netscape.com:443/extra");

    WSF_UNIT_ASSERT_NULL(tc, "CONNECT Parsing Must Fail But, Didn't", uri);
    if (uri)
    {
        axutil_uri_free(uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_hostinfo(env, "home.netscape.com:443?extra");

    WSF_UNIT_ASSERT_NULL(tc, "CONNECT Parsing Must Fail But, Didn't", uri);
    if (uri)
    {
        axutil_uri_free(uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_hostinfo(env, "home.netscape.com:443#extra");

    WSF_UNIT_ASSERT_NULL(tc, "CONNECT Parsing Must Fail But, Didn't", uri);
    if (uri)
    {
        axutil_uri_free(uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_hostinfo(env, "http://home.netscape.com:443");

    WSF_UNIT_ASSERT_NULL(tc, "CONNECT Parsing Must Fail But, Didn't", uri);
    if (uri)
    {
        axutil_uri_free(uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_hostinfo(env, "//home.netscape.com:443");

    WSF_UNIT_ASSERT_NULL(tc, "CONNECT Parsing Must Fail But, Didn't", uri);
    if (uri)
    {
        axutil_uri_free(uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_hostinfo(env, ".home.netscape.com:443");

    WSF_UNIT_ASSERT_NULL(tc, "CONNECT Parsing Must Fail But, Didn't", uri);
    if (uri)
    {
        axutil_uri_free(uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_hostinfo(env, "[home.netscape.com]");

    WSF_UNIT_ASSERT_NULL(tc, "CONNECT Parsing Must Fail But, Didn't", uri);
    if (uri)
    {
        axutil_uri_free(uri, env);
        uri = NULL;
    }
    /* End of Error Tests */
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
    str = axutil_uri_get_host(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Host Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Host",
        "home.netscape.com", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_host(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Host Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Host",
        "home.netscape.com", str);
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
        axutil_uri_free(uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_string(env, "http://");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", uri);
    str = axutil_uri_get_server(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Server Should Fail. But, Didn't", str);
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
        "http://", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (uri)
    {
        axutil_uri_free(uri, env);
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
    str = axutil_uri_get_host(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Host Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Host",
        "home.netscape.com", str);
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
        axutil_uri_free(uri, env);
        uri = NULL;
    }

    uri = axutil_uri_parse_string(env, "http://[home.netscape.com]:9090");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", uri);
    str = axutil_uri_get_server(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Server Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "String Parsing Identified Invalid Server",
        "[home.netscape.com]:9090", str);
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
    str = axutil_uri_get_host(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Host Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Host",
        "home.netscape.com", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, 0);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://[home.netscape.com]:9090", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (uri)
    {
        axutil_uri_free(uri, env);
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
    str = axutil_uri_get_query(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Query Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Query String",
        "foo=bar", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_host(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Host Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Host",
        "home.netscape.com", str);
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
        axutil_uri_free(uri, env);
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
    str = axutil_uri_get_query(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Query Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Query String",
        "foo=bar", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_host(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Host Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Host",
        "home.netscape.com", str);
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
        axutil_uri_free(uri, env);
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
    str = axutil_uri_get_query(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Query Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Query String",
        "foo=bar", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_fragment(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Fragment Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Fragment",
        "rel", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_host(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Host Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Host",
        "home.netscape.com", str);
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
        axutil_uri_free(uri, env);
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
    str = axutil_uri_get_query(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Query Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Query String",
        "foo=bar", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_fragment(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Fragment Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Fragment",
        "rel", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_host(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Host Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Host",
        "home.netscape.com", str);
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
        axutil_uri_free(uri, env);
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
    str = axutil_uri_get_fragment(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Fragment Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Fragment",
        "rel", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_host(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Host Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Host",
        "home.netscape.com", str);
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
        axutil_uri_free(uri, env);
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
    str = axutil_uri_get_fragment(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Fragment Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Fragment",
        "rel", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_host(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Host Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Host",
        "home.netscape.com", str);
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
        axutil_uri_free(uri, env);
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
    str = axutil_uri_get_query(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Query Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Query String",
        "foo=bar", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_fragment(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Fragment Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Fragment",
        "rel", str);
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
        axutil_uri_free(uri, env);
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
    str = axutil_uri_get_fragment(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Fragment Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Fragment",
        "rel", str);
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
        axutil_uri_free(uri, env);
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
    str = axutil_uri_get_query(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Query Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Query String",
        "foo=bar", str);
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
        axutil_uri_free(uri, env);
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
        axutil_uri_free(uri, env);
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
    str = axutil_uri_get_query(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Query Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Query String",
        "foo=bar", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_fragment(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Fragment Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Fragment",
        "rel", str);
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
        axutil_uri_free(uri, env);
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
    str = axutil_uri_get_query(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Query Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Query String",
        "foo=bar", str);
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
        axutil_uri_free(uri, env);
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
    str = axutil_uri_get_fragment(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Fragment Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Fragment",
        "rel", str);
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
        axutil_uri_free(uri, env);
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
        axutil_uri_free(uri, env);
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
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Path Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Path",
        "/path", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_host(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Host Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Host",
        "home.netscape.com", str);
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
        axutil_uri_free(uri, env);
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
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Path Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Path",
        "/path", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_host(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Host Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Host",
        "home.netscape.com", str);
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
        axutil_uri_free(uri, env);
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
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Path Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Path",
        "/path", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_query(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Query Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Query String",
        "foo=bar", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_host(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Host Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Host",
        "home.netscape.com", str);
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
        axutil_uri_free(uri, env);
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
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Path Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Path",
        "/path", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_query(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Query Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Query String",
        "foo=bar", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_host(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Host Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Host",
        "home.netscape.com", str);
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
        axutil_uri_free(uri, env);
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
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Path Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Path",
        "/path", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_query(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Query Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Query String",
        "foo=bar", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_fragment(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Fragment Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Fragment",
        "rel", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_host(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Host Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Host",
        "home.netscape.com", str);
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
        axutil_uri_free(uri, env);
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
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Path Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Path",
        "/path", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_query(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Query Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Query String",
        "foo=bar", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_fragment(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Fragment Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Fragment",
        "rel", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_host(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Host Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Host",
        "home.netscape.com", str);
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
        axutil_uri_free(uri, env);
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
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Path Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Path",
        "/path", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_fragment(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Fragment Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Fragment",
        "rel", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_host(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Host Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Host",
        "home.netscape.com", str);
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
        axutil_uri_free(uri, env);
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
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Path Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Path",
        "/path", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_fragment(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Fragment Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Fragment",
        "rel", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_host(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Host Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Host",
        "home.netscape.com", str);
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
        axutil_uri_free(uri, env);
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
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Path Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Path",
        "/path", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_query(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Query Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Query String",
        "foo=bar", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_fragment(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Fragment Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Fragment",
        "rel", str);
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
        axutil_uri_free(uri, env);
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
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Path Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Path",
        "/path", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_fragment(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Fragment Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Fragment",
        "rel", str);
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
        axutil_uri_free(uri, env);
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
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Path Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Path",
        "/path", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_query(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Query Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Query String",
        "foo=bar", str);
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
        axutil_uri_free(uri, env);
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
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Path Failed", str);
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
        axutil_uri_free(uri, env);
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
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Path Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Path",
        "/path", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_query(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Query Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Query String",
        "foo=bar", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_fragment(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Fragment Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Fragment",
        "rel", str);
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
        axutil_uri_free(uri, env);
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
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Path Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Path",
        "/path", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_query(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Query Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Query String",
        "foo=bar", str);
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
        axutil_uri_free(uri, env);
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
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Path Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Path",
        "/path", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_fragment(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Fragment Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Fragment",
        "rel", str);
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
        axutil_uri_free(uri, env);
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
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Path Failed", str);
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
        axutil_uri_free(uri, env);
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
    str = axutil_uri_get_host(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Host Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Host",
        "home.netscape.com", str);
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
        axutil_uri_free(uri, env);
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
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Path Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Path",
        "/path", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_query(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Query Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Query String",
        "foo=bar", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_fragment(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Fragment Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Fragment",
        "rel", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_get_host(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Get Host Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Host",
        "home.netscape.com", str);
    if (str)
    {
        /*AXIS2_FREE(env->allocator, str);*/
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, 0);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "home.netscape.com:9090/path?foo=bar#rel", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (uri)
    {
        axutil_uri_free(uri, env);
        uri = NULL;
    }
    /* End of Abbreviated URI Block */

    /* Error Cases */
    uri = axutil_uri_parse_string(env, "http://:9090");
    WSF_UNIT_ASSERT_NULL(tc, "String Parsing Should Fail. But, Didn't", uri);
    if (uri)
    {
        axutil_uri_free(uri, env);
        uri = NULL;
    }
    uri = axutil_uri_parse_string(env, "http://user:pass");
    WSF_UNIT_ASSERT_NULL(tc, "String Parsing Should Fail. But, Didn't", uri);
    if (uri)
    {
        axutil_uri_free(uri, env);
        uri = NULL;
    }
    uri = axutil_uri_parse_string(env, "http://user:pass@:9090");
    WSF_UNIT_ASSERT_NULL(tc, "String Parsing Should Fail. But, Didn't", uri);
    if (uri)
    {
        axutil_uri_free(uri, env);
        uri = NULL;
    }
    uri = axutil_uri_parse_string(env, ".home.netscape.com:9090/path?foo=bar#rel");
    WSF_UNIT_ASSERT_NULL(tc, "String Parsing Should Fail. But, Didn't", uri);
    if (uri)
    {
        axutil_uri_free(uri, env);
        uri = NULL;
    }
    /* End of Error Cases */

    /* Unstoppable Errors */
    uri = axutil_uri_parse_string(env, "//home.netscape.com:9090/path?foo=bar#rel");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Shouldn't Fail.", uri);
    if (uri)
    {
        axutil_uri_free(uri, env);
        uri = NULL;
    }
    uri = axutil_uri_parse_string(env, "htpp://home.netscape.com:9090/path?foo=bar#rel");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Shouldn't Fail.", uri);
    if (uri)
    {
        axutil_uri_free(uri, env);
        uri = NULL;
    }
    uri = axutil_uri_parse_string(env, "http://home.netscape.com:9090//path?foo=bar#rel");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Shouldn't Fail.", uri);
    if (uri)
    {
        axutil_uri_free(uri, env);
        uri = NULL;
    }
    uri = axutil_uri_parse_string(env, "http://home.netscape.com/path:9090?foo=bar#rel");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Shouldn't Fail.", uri);
    if (uri)
    {
        axutil_uri_free(uri, env);
        uri = NULL;
    }
    uri = axutil_uri_parse_string(env, "http:9090//home.netscape.com/path?foo=bar#rel");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Shouldn't Fail.", uri);
    if (uri)
    {
        axutil_uri_free(uri, env);
        uri = NULL;
    }
    /* End of Unstoppable Errors */
}

static void WSF_UNIT_CALL test_axutil_uri_parse_relative(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;
    axutil_uri_t *uri = NULL;
    axutil_uri_t *temp = NULL;
    axutil_uri_t *base = NULL;
    char *str = NULL;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data->test_data);

    if (!test_data || !test_data->test_data)
    {
        return;
    }

    env = test_data->test_env;

    base = axutil_uri_parse_string(env, "http://");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", base);
    str = axutil_uri_to_string(base, env, 0);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    uri = axutil_uri_parse_relative(env, base, "/my_path?foo=bar#rel");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Relative Parsing Failed", uri);
    str = axutil_uri_to_string(uri, env, 0);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http:///my_path?foo=bar#rel", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (base)
    {
        axutil_uri_free(base, env);
        base = NULL;
    }
    if (uri)
    {
        axutil_uri_free(uri, env);
        uri = NULL;
    }

    base = axutil_uri_parse_string(env, "http://?bar=foo#xrel");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", base);
    str = axutil_uri_to_string(base, env, 0);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://?bar=foo#xrel", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    uri = axutil_uri_parse_relative(env, base, "/my_path?foo=bar#rel");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Relative Parsing Failed", uri);
    str = axutil_uri_to_string(uri, env, 0);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http:///my_path?foo=bar#rel", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (base)
    {
        axutil_uri_free(base, env);
        base = NULL;
    }
    if (uri)
    {
        axutil_uri_free(uri, env);
        uri = NULL;
    }

    base = axutil_uri_parse_string(env, "http://home.netscape.com:80");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", base);
    str = axutil_uri_to_string(base, env, 0);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://home.netscape.com", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    uri = axutil_uri_parse_relative(env, base, "/my_path?foo=bar#rel");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Relative Parsing Failed", uri);
    str = axutil_uri_to_string(uri, env, 0);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://home.netscape.com/my_path?foo=bar#rel", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (base)
    {
        axutil_uri_free(base, env);
        base = NULL;
    }
    if (uri)
    {
        axutil_uri_free(uri, env);
        uri = NULL;
    }

    base = axutil_uri_parse_string(env, "https://home.netscape.com:443");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", base);
    str = axutil_uri_to_string(base, env, 0);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "https://home.netscape.com", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    uri = axutil_uri_parse_string(env, "/my_path?foo=bar#rel");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", uri);
    temp = axutil_uri_resolve_relative(env, base, uri);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Relative Resolution Failed", uri);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Relative Resolution Failed", temp);
    WSF_UNIT_ASSERT_EQUALS_PTR(tc, "Invalid Reference Returned",
        uri, temp);
    temp = NULL;
    str = axutil_uri_to_string(uri, env, 0);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "https://home.netscape.com/my_path?foo=bar#rel", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (base)
    {
        axutil_uri_free(base, env);
        base = NULL;
    }
    if (uri)
    {
        axutil_uri_free(uri, env);
        uri = NULL;
    }
}

static void WSF_UNIT_CALL test_axutil_uri_port_of_scheme(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data->test_data);

    if (!test_data || !test_data->test_data)
    {
        return;
    }

    env = test_data->test_env;

    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Port", 80,
        axutil_uri_port_of_scheme("http"));
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Port", 80,
        AXIS2_URI_HTTP_DEFAULT_PORT);
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Port", 21,
        axutil_uri_port_of_scheme("ftp"));
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Port", 21,
        AXIS2_URI_FTP_DEFAULT_PORT);
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Port", 443,
        axutil_uri_port_of_scheme("https"));
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Port", 443,
        AXIS2_URI_HTTPS_DEFAULT_PORT);
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Port", 70,
        axutil_uri_port_of_scheme("gopher"));
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Port", 70,
        AXIS2_URI_GOPHER_DEFAULT_PORT);
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Port", 389,
        axutil_uri_port_of_scheme("ldap"));
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Port", 389,
        AXIS2_URI_LDAP_DEFAULT_PORT);
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Port", 119,
        axutil_uri_port_of_scheme("nntp"));
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Port", 119,
        AXIS2_URI_NNTP_DEFAULT_PORT);
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Port", 143,
        axutil_uri_port_of_scheme("imap"));
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Port", 143,
        AXIS2_URI_IMAP_DEFAULT_PORT);
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Port", 110,
        axutil_uri_port_of_scheme("pop"));
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Port", 110,
       AXIS2_URI_POP_DEFAULT_PORT);
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Port", 5060,
        axutil_uri_port_of_scheme("sip"));
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Port", 5060,
        AXIS2_URI_SIP_DEFAULT_PORT);
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Port", 23,
        axutil_uri_port_of_scheme("telnet"));
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Port", 23,
        AXIS2_URI_TELNET_DEFAULT_PORT);
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Port", 22,
        axutil_uri_port_of_scheme("ssh"));
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Port", 22,
        AXIS2_URI_SSH_DEFAULT_PORT);
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Port", 191,
        axutil_uri_port_of_scheme("prospero"));
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Port", 191,
        AXIS2_URI_PROSPERO_DEFAULT_PORT);
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Port", 2049,
        axutil_uri_port_of_scheme("nfs"));
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Port", 2049,
        AXIS2_URI_NFS_DEFAULT_PORT);
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Port", 3372,
        axutil_uri_port_of_scheme("tip"));
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Port", 3372,
        AXIS2_URI_TIP_DEFAULT_PORT);
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Port", 674,
        axutil_uri_port_of_scheme("acap"));
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Port", 674,
        AXIS2_URI_ACAP_DEFAULT_PORT);

    /* Ports Below are listed on IANA List as of 2008-02-28, at,
     * http://www.iana.org/assignments/port-numbers, as z39.50
     * in general.
     */
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Port", 210,
        axutil_uri_port_of_scheme("z39.50r"));
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Port", 210,
        axutil_uri_port_of_scheme("z39.50s"));

    /* Ports Below are not on IANA List as of 2008-02-28, at,
     * http://www.iana.org/assignments/port-numbers
     */
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Port", 554,
        axutil_uri_port_of_scheme("rtsp"));
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Port", 554,
        AXIS2_URI_RTSP_DEFAULT_PORT);
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Port", 210,
        axutil_uri_port_of_scheme("wais"));
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Port", 210,
        AXIS2_URI_WAIS_DEFAULT_PORT);

    /* Couldn't locate enough resources to determine the existence
     * of a scheme named "snews"
     */
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Port", 563,
        axutil_uri_port_of_scheme("snews"));
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Port", 563,
        AXIS2_URI_SNEWS_DEFAULT_PORT);
}

static void WSF_UNIT_CALL test_axutil_uri_to_string(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;
    axutil_uri_t *uri = NULL;
    axutil_uri_t *temp = NULL;
    char *str = NULL;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data->test_data);

    if (!test_data || !test_data->test_data)
    {
        return;
    }

    env = test_data->test_env;

    uri = axutil_uri_parse_string(env, "http://user:pass@home.netscape.com:9090/path?foo=bar#rel");
    WSF_UNIT_ASSERT_NOT_NULL(tc, "String Parsing Failed", uri);

    temp = axutil_uri_clone(uri, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI Clone Failed", temp);

    str = axutil_uri_to_string(temp, env, AXIS2_URI_UNP_REVEALPASSWORD);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://user:pass@home.netscape.com:9090/path?foo=bar#rel", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (temp)
    {
        axutil_uri_free(temp, env);
        temp = NULL;
    }
    str = axutil_uri_to_string(uri, env, AXIS2_URI_UNP_OMITSITEPART | AXIS2_URI_UNP_OMITPATHINFO);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "", str);
    if (str && *str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, AXIS2_URI_UNP_OMITSITEPART | AXIS2_URI_UNP_OMITQUERY
                               | AXIS2_URI_UNP_OMITPATHINFO);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "", str);
    if (str && *str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, AXIS2_URI_UNP_OMITUSER | AXIS2_URI_UNP_REVEALPASSWORD);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://:pass@home.netscape.com:9090/path?foo=bar#rel", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, AXIS2_URI_UNP_OMITPASSWORD | AXIS2_URI_UNP_REVEALPASSWORD);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://user@home.netscape.com:9090/path?foo=bar#rel", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, AXIS2_URI_UNP_OMITPASSWORD);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://user@home.netscape.com:9090/path?foo=bar#rel", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, AXIS2_URI_UNP_OMITUSERINFO);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://home.netscape.com:9090/path?foo=bar#rel", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, AXIS2_URI_UNP_OMITPASSWORD | AXIS2_URI_UNP_OMITUSER);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://home.netscape.com:9090/path?foo=bar#rel", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, 0);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://user:XXXXXXXX@home.netscape.com:9090/path?foo=bar#rel", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, AXIS2_URI_UNP_OMITUSER);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://:XXXXXXXX@home.netscape.com:9090/path?foo=bar#rel", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, AXIS2_URI_UNP_OMITUSERINFO | AXIS2_URI_UNP_OMITPATHINFO);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "http://home.netscape.com:9090", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, AXIS2_URI_UNP_OMITSITEPART | AXIS2_URI_UNP_OMITQUERY);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "/path", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, AXIS2_URI_UNP_OMITSITEPART | AXIS2_URI_UNP_OMITQUERY_ONLY);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "/path#rel", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    str = axutil_uri_to_string(uri, env, AXIS2_URI_UNP_OMITSITEPART | AXIS2_URI_UNP_OMITFRAGMENT_ONLY);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "URI as String Failed", str);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid URI",
        "/path?foo=bar", str);
    if (str)
    {
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    if (uri)
    {
        axutil_uri_free(uri, env);
        uri = NULL;
    }
}
