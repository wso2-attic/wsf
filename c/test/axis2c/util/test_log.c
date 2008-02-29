
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

static void WSF_UNIT_CALL
test_axutil_log_create(    
    wsf_unit_test_case_t *tc,
    void *data);

static void WSF_UNIT_CALL
test_axutil_log_debug(    
    wsf_unit_test_case_t *tc,
    void *data);

static void WSF_UNIT_CALL
test_axutil_log_debug_off(    
    wsf_unit_test_case_t *tc,
    void *data);

static void WSF_UNIT_CALL
test_axutil_log_info(    
    wsf_unit_test_case_t *tc,
    void *data);

static void WSF_UNIT_CALL
test_axutil_log_info_off(    
    wsf_unit_test_case_t *tc,
    void *data);

static void WSF_UNIT_CALL
test_axutil_log_warning(    
    wsf_unit_test_case_t *tc,
    void *data);

static void WSF_UNIT_CALL
test_axutil_log_warning_off(
    wsf_unit_test_case_t *tc,
    void *data);

static void WSF_UNIT_CALL
test_axutil_log_error(
    wsf_unit_test_case_t *tc,
    void *data);

static void WSF_UNIT_CALL
test_axutil_log_critical(
    wsf_unit_test_case_t *tc,
    void *data);

wsf_unit_status_t WSF_UNIT_CALL test_log(wsf_unit_suite_t * suite)
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

    wsf_unit_run_test(suite, test_axutil_log_create, data);
    wsf_unit_run_test(suite, test_axutil_log_debug, data);
    wsf_unit_run_test(suite, test_axutil_log_info, data);
    wsf_unit_run_test(suite, test_axutil_log_debug_off, data);
    wsf_unit_run_test(suite, test_axutil_log_warning, data);
    wsf_unit_run_test(suite, test_axutil_log_info_off, data);
    wsf_unit_run_test(suite, test_axutil_log_error, data);
    wsf_unit_run_test(suite, test_axutil_log_warning_off, data);
    wsf_unit_run_test(suite, test_axutil_log_critical, data);

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

static void WSF_UNIT_CALL test_axutil_log_create(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_allocator_t *allocator = NULL;
    axutil_error_t *error = NULL;
    axutil_log_t *log = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);

    env = test_data->test_env;
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Log Does not exist", env->log);
    env->log->level = AXIS2_LOG_LEVEL_USER;

    allocator = axutil_allocator_init(NULL);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Could not create allocator", allocator);
    if (allocator)
    {
        error = (axutil_error_t *)axutil_error_create(allocator);
    }
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Could not create error", error);
    if (error)
    {
        log = (axutil_log_t *)axutil_log_create(allocator, NULL, NULL);
    }
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Could not create log", log);
    if (log)
    {
        AXIS2_LOG_FREE(allocator, log);
        log = NULL;
    }
    if (error)
    {
        AXIS2_ERROR_FREE(error);
        error = NULL;
    }
    if (allocator)
    {
        AXIS2_FREE(allocator, allocator);
        allocator = NULL;
    }
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Incorrect log level",
        AXIS2_LOG_LEVEL_USER, env->log->level);
}

static void WSF_UNIT_CALL test_axutil_log_debug(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);

    env = test_data->test_env;
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Log Does not exist", env->log);
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Incorrect log level",
        AXIS2_LOG_LEVEL_USER, env->log->level);
    env->log->level = AXIS2_LOG_LEVEL_DEBUG;
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "log_debug test %s %d", "foo", 1);
}

static void WSF_UNIT_CALL test_axutil_log_info(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);

    env = test_data->test_env;
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Log Does not exist", env->log);
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Incorrect log level",
        AXIS2_LOG_LEVEL_DEBUG, env->log->level);
    env->log->level = AXIS2_LOG_LEVEL_INFO;
    AXIS2_LOG_INFO(env->log, AXIS2_LOG_SI, "log_info test %s %d", "foo", 1);
}

static void WSF_UNIT_CALL test_axutil_log_debug_off(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);

    env = test_data->test_env;
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Log Does not exist", env->log);
    WSF_UNIT_ASSERT_TRUE(tc, "Incorrect log level",
        env->log->level <= AXIS2_LOG_LEVEL_INFO);
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
        "this should not be logged. log_debug test ", "foo", 1);
}

static void WSF_UNIT_CALL test_axutil_log_warning(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);

    env = test_data->test_env;
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Log Does not exist", env->log);
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Incorrect log level",
        AXIS2_LOG_LEVEL_INFO, env->log->level);
    env->log->level = AXIS2_LOG_LEVEL_WARNING;
    AXIS2_LOG_WARNING(env->log, AXIS2_LOG_SI, "log_warning test %s %d", "foo", 1);
}

static void WSF_UNIT_CALL test_axutil_log_info_off(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);

    env = test_data->test_env;
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Log Does not exist", env->log);
    WSF_UNIT_ASSERT_TRUE(tc, "Incorrect log level",
        env->log->level <= AXIS2_LOG_LEVEL_WARNING);
    AXIS2_LOG_INFO(env->log, AXIS2_LOG_SI,
        "this should not be logged. log_info test ", "foo", 1);
}

static void WSF_UNIT_CALL test_axutil_log_error(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);

    env = test_data->test_env;
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Log Does not exist", env->log);
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Incorrect log level",
        AXIS2_LOG_LEVEL_WARNING, env->log->level);
    env->log->level = AXIS2_LOG_LEVEL_ERROR;
    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "log_error test %s %d", "foo", 1);
}

static void WSF_UNIT_CALL test_axutil_log_warning_off(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);

    env = test_data->test_env;
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Log Does not exist", env->log);
    WSF_UNIT_ASSERT_TRUE(tc, "Incorrect log level",
        env->log->level <= AXIS2_LOG_LEVEL_ERROR);
    AXIS2_LOG_WARNING(env->log, AXIS2_LOG_SI,
        "this should not be logged. log_warning test ", "foo", 1);
}

static void WSF_UNIT_CALL test_axutil_log_critical(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);

    env = test_data->test_env;
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Log Does not exist", env->log);
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Incorrect log level",
        AXIS2_LOG_LEVEL_ERROR, env->log->level);
    env->log->level = AXIS2_LOG_LEVEL_CRITICAL;
    AXIS2_LOG_CRITICAL(env->log, AXIS2_LOG_SI, "log_critical test %s %d", "foo", 1);
}
