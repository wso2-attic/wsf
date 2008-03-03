
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
#include <axutil_properties.h>

#define PROPERTIES_TEST_KEY_1 "c.interface.header.template"
#define PROPERTIES_TEST_KEY_2 "c.filename.extension"
#define PROPERTIES_TEST_KEY_3 "non.existent"
#define PROPERTIES_TEST_KEY_4 "all.new"
#define PROPERTIES_TEST_KEY_5 "c.service.template"

typedef struct test_axutil_properties
    test_axutil_properties_t;

static void WSF_UNIT_CALL
test_axutil_properties_create(    
    wsf_unit_test_case_t *tc,
    void *data);

struct test_axutil_properties
{
    char *input;
    char *output;
};

wsf_unit_status_t WSF_UNIT_CALL test_properties(wsf_unit_suite_t * suite)
{
    wsf_unit_status_t status = WSF_UNIT_FAILURE;
    axutil_env_t *env = NULL;
    axutil_test_data_t *data = NULL;
    test_axutil_properties_t *test_data = NULL;

    status = WSF_UNIT_ADD_SUB_SUITE(suite);

    env = CREATE_TEST_ENV();
    if (env)
    {
        data = AXIS2_MALLOC(env->allocator, sizeof(axutil_test_data_t));
    }
    if (data)
    {
        data->test_env = env;
        test_data = AXIS2_MALLOC(env->allocator, sizeof(test_axutil_properties_t));
        if (test_data)
        {
            data->test_data = test_data;
#ifndef WIN32
            test_data->input = "resources/codegen-config.properties";
            test_data->output = "resources/test_properties_output.properties";
#else
            test_data->input = "resources\\codegen-config.properties";
            test_data->output = "resources\\test_properties_output.properties";
#endif
        }
        else
        {
            data->test_data = NULL;
        }
    }

    wsf_unit_run_test(suite, test_axutil_properties_create, data);

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

static void WSF_UNIT_CALL test_axutil_properties_create(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;
    axutil_properties_t *prop = NULL;
    axutil_hash_t *prop_hash = NULL;
    FILE *output = NULL;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data->test_data);

    if (!test_data || !test_data->test_data)
    {
        return;
    }

    env = test_data->test_env;

    prop = axutil_properties_create(env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Properties Create Failed", prop);

    prop_hash = axutil_properties_get_all(prop, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Properties GetAll Failed", prop_hash);
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Wrong Hash Count", 0,
        axutil_hash_count(prop_hash));
    prop_hash = NULL;

    WSF_UNIT_ASSERT_TRUE(tc, "Load Properties Failed", 
        axutil_properties_load(prop, env,
            ((test_axutil_properties_t *)test_data->test_data)->input));

    prop_hash = axutil_properties_get_all(prop, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Properties GetAll Failed", prop_hash);
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Wrong Hash Count", 7,
        axutil_hash_count(prop_hash));

    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Hash Get Mismatch",
        (char *)axutil_hash_get(prop_hash, PROPERTIES_TEST_KEY_1,
            AXIS2_HASH_KEY_STRING),
        axutil_properties_get_property(prop, env, PROPERTIES_TEST_KEY_1));

    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Hash Get Mismatch",
        (char *)axutil_hash_get(prop_hash, PROPERTIES_TEST_KEY_2,
            AXIS2_HASH_KEY_STRING),
        axutil_properties_get_property(prop, env, PROPERTIES_TEST_KEY_2));

    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Value Returned", "c",
        axutil_properties_get_property(prop, env, PROPERTIES_TEST_KEY_2));

    WSF_UNIT_ASSERT_NULL(tc, "Value Was Not Null",
        axutil_properties_get_property(prop, env, PROPERTIES_TEST_KEY_3));

    WSF_UNIT_ASSERT_TRUE(tc, "Set Property Failed", 
        axutil_properties_set_property(prop, env, PROPERTIES_TEST_KEY_2, "this.was.changed"));

    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Hash Get Mismatch",
        (char *)axutil_hash_get(prop_hash, PROPERTIES_TEST_KEY_2,
            AXIS2_HASH_KEY_STRING),
        axutil_properties_get_property(prop, env, PROPERTIES_TEST_KEY_2));

    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Value Returned", "this.was.changed",
        axutil_properties_get_property(prop, env, PROPERTIES_TEST_KEY_2));

    WSF_UNIT_ASSERT_TRUE(tc, "Set Property Failed", 
        axutil_properties_set_property(prop, env, PROPERTIES_TEST_KEY_4, "this.is.all,new"));

    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Hash Get Mismatch",
        (char *)axutil_hash_get(prop_hash, PROPERTIES_TEST_KEY_4,
            AXIS2_HASH_KEY_STRING),
        axutil_properties_get_property(prop, env, PROPERTIES_TEST_KEY_4));

    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Value Returned", "this.is.all,new",
        axutil_properties_get_property(prop, env, PROPERTIES_TEST_KEY_4));

    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Invalid Value Returned",
        "org.apache.axis2.wsdl.codegen.writer.CServiceXMLWriter,/org/apache/axis2/wsdl/template/c/ServiceXMLTemplate.xsl",
        axutil_properties_get_property(prop, env, PROPERTIES_TEST_KEY_5));
    prop_hash = NULL;

    output = fopen(((test_axutil_properties_t *)test_data->test_data)->output,"w");

    WSF_UNIT_ASSERT_NOT_NULL(tc, "File Open Failed", output);

    if (output)
    {
        WSF_UNIT_ASSERT_TRUE(tc, "Store Properties Failed", 
            axutil_properties_store(prop, env, output));
        fclose(output);
    }
    if (prop)
    {
        axutil_properties_free(prop, env);
    }
}
