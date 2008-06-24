
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
#include <axutil_date_time.h>
#include <time.h>

static void WSF_UNIT_CALL
test_axutil_date_time_create(    
    wsf_unit_test_case_t *tc,
    void *data);

static void WSF_UNIT_CALL
test_axutil_date_time_create_with_offset(    
    wsf_unit_test_case_t *tc,
    void *data);

static void WSF_UNIT_CALL
test_axutil_date_time_deserialize(    
    wsf_unit_test_case_t *tc,
    void *data);

static void WSF_UNIT_CALL
test_axutil_date_time_serialize(    
    wsf_unit_test_case_t *tc,
    void *data);

static void WSF_UNIT_CALL
test_axutil_date_time_error_input_failures(    
    wsf_unit_test_case_t *tc,
    void *data);

static void WSF_UNIT_CALL
test_axutil_date_time_create_with_offset_gmtime(
    wsf_unit_test_case_t *tc,
    void *data);

wsf_unit_status_t WSF_UNIT_CALL test_date_time(wsf_unit_suite_t * suite)
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

    wsf_unit_run_test(suite, test_axutil_date_time_create, data);
    wsf_unit_run_test(suite, test_axutil_date_time_create_with_offset, data);
    wsf_unit_run_test(suite, test_axutil_date_time_deserialize, data);
    wsf_unit_run_test(suite, test_axutil_date_time_serialize, data);
    wsf_unit_run_test(suite, test_axutil_date_time_error_input_failures, data);
    wsf_unit_run_test(suite, test_axutil_date_time_create_with_offset_gmtime, data);

    if (data)
    {
        data->test_env = NULL;
        if (data->test_data)
        {
            axutil_date_time_free(data->test_data, env);
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

static void WSF_UNIT_CALL test_axutil_date_time_create(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;
    axutil_date_time_t *date_time = NULL;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);

    if (!test_data)
    {
        return;
    }
    env = test_data->test_env;

    date_time = axutil_date_time_create(env);

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Date Time Creation Failed", date_time);
    if (!date_time)
    {
        return;
    }
    test_data->test_data = date_time;
}

static void WSF_UNIT_CALL test_axutil_date_time_create_with_offset(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;
    axutil_date_time_t *date_time1 = NULL;
    axutil_date_time_t *date_time2 = NULL;
    axutil_date_time_t *date_time3 = NULL;
    char *str1 = NULL;
    char *str2 = NULL;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);

    if (!test_data)
    {
        return;
    }
    env = test_data->test_env;

    date_time1 = axutil_date_time_create_with_offset(env, 100);
    date_time2 = axutil_date_time_create_with_offset(env, 0);
    date_time3 = axutil_date_time_create_with_offset(env, -100);

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Date Time Creation Failed", date_time1);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Date Time Creation Failed", date_time2);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Date Time Creation Failed", date_time3);
    if (!date_time1 || !date_time2 || !date_time3)
    {
        return;
    }
    WSF_UNIT_ASSERT_TRUE(tc, "Invalid Date Time",
        axutil_date_time_compare(date_time2, env, date_time1) == 
        AXIS2_DATE_TIME_COMP_RES_NOT_EXPIRED);
    WSF_UNIT_ASSERT_TRUE(tc, "Invalid Date Time",
        axutil_date_time_compare(date_time2, env, date_time3) == 
        AXIS2_DATE_TIME_COMP_RES_EXPIRED);

    str1 = axutil_date_time_serialize_date_time(date_time2, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Date Time Serialize Failed", str1);
    WSF_UNIT_ASSERT_TRUE(tc, "Date Time Deserialize Failed",
        axutil_date_time_deserialize_date_time(date_time2, env, str1));
    str2 = axutil_date_time_serialize_date_time(date_time2, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Date Time Serialize Failed", str1);

    if (str1 && str2)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Serialize/Deserialize Failed", str1, str2);
    }

    if (str1)
    {
        AXIS2_FREE(env->allocator, str1);
        str1 = NULL;
    }
    if (str2)
    {
        AXIS2_FREE(env->allocator, str2);
        str1 = NULL;
    }

    str1 = axutil_date_time_serialize_date(date_time2, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Date Time Serialize Failed", str1);
    WSF_UNIT_ASSERT_TRUE(tc, "Date Time Deserialize Failed",
        axutil_date_time_deserialize_date(date_time2, env, str1));
    str2 = axutil_date_time_serialize_date(date_time2, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Date Time Serialize Failed", str1);

    if (str1 && str2)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Serialize/Deserialize Failed", str1, str2);
    }

    if (str1)
    {
        AXIS2_FREE(env->allocator, str1);
        str1 = NULL;
    }
    if (str2)
    {
        AXIS2_FREE(env->allocator, str2);
        str1 = NULL;
    }

    str1 = axutil_date_time_serialize_time(date_time2, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Date Time Serialize Failed", str1);
    WSF_UNIT_ASSERT_TRUE(tc, "Date Time Deserialize Failed",
        axutil_date_time_deserialize_time(date_time2, env, str1));
    str2 = axutil_date_time_serialize_time(date_time2, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Date Time Serialize Failed", str1);

    if (str1 && str2)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Serialize/Deserialize Failed", str1, str2);
    }

    if (str1)
    {
        AXIS2_FREE(env->allocator, str1);
        str1 = NULL;
    }
    if (str2)
    {
        AXIS2_FREE(env->allocator, str2);
        str1 = NULL;
    }

    if (date_time1)
    {
        axutil_date_time_free(date_time1, env);
    }
    if (date_time2)
    {
        axutil_date_time_free(date_time2, env);
    }

    WSF_UNIT_ASSERT_TRUE(tc, "Invalid Year",
        axutil_date_time_get_year(date_time3,env) < 2100);
    WSF_UNIT_ASSERT_TRUE(tc, "Invalid Year",
        axutil_date_time_get_year(date_time3,env) > 2000);
    WSF_UNIT_ASSERT_TRUE(tc, "Invalid Month",
        axutil_date_time_get_month(date_time3,env) > 0);
    WSF_UNIT_ASSERT_TRUE(tc, "Invalid Month",
        axutil_date_time_get_month(date_time3,env) < 13);
    WSF_UNIT_ASSERT_TRUE(tc, "Invalid Day",
        axutil_date_time_get_date(date_time3,env) > 0);
    WSF_UNIT_ASSERT_TRUE(tc, "Invalid Day",
        axutil_date_time_get_date(date_time3,env) < 32);
    WSF_UNIT_ASSERT_TRUE(tc, "Invalid Hour",
        axutil_date_time_get_hour(date_time3,env) > -1);
    WSF_UNIT_ASSERT_TRUE(tc, "Invalid Hour",
        axutil_date_time_get_hour(date_time3,env) < 24);
    WSF_UNIT_ASSERT_TRUE(tc, "Invalid Minute",
        axutil_date_time_get_minute(date_time3,env) > -1);
    WSF_UNIT_ASSERT_TRUE(tc, "Invalid Minute",
        axutil_date_time_get_minute(date_time3,env) < 60);
    WSF_UNIT_ASSERT_TRUE(tc, "Invalid Second",
        axutil_date_time_get_second(date_time3,env) > -1);
    WSF_UNIT_ASSERT_TRUE(tc, "Invalid Second",
        axutil_date_time_get_second(date_time3,env) < 60);
    WSF_UNIT_ASSERT_TRUE(tc, "Invalid Millisecond",
        axutil_date_time_get_msec(date_time3,env) > -1);
    WSF_UNIT_ASSERT_TRUE(tc, "Invalid Millisecond",
        axutil_date_time_get_msec(date_time3,env) < 1000);

    if (date_time3)
    {
        axutil_date_time_free(date_time3, env);
    }
}

static void WSF_UNIT_CALL test_axutil_date_time_deserialize(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;
    axutil_date_time_t *date_time = NULL;
    axutil_date_time_t *date_time_tmp = NULL;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data->test_data);

    if (!test_data || !test_data->test_data)
    {
        return;
    }
    env = test_data->test_env;
    
    date_time = (axutil_date_time_t *)test_data->test_data;

    WSF_UNIT_ASSERT_TRUE(tc, "Date Time Deserialize Failed",
        axutil_date_time_deserialize_date_time(date_time, env, "2000-11-11T12:30:24.799Z"));

    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Year", 2000,
        axutil_date_time_get_year(date_time,env));

    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Month", 11,
        axutil_date_time_get_month(date_time,env));

    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Day", 11,
        axutil_date_time_get_date(date_time,env));

    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Hour", 12,
        axutil_date_time_get_hour(date_time,env));

    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Year", 30,
        axutil_date_time_get_minute(date_time,env));

    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Second", 24,
        axutil_date_time_get_second(date_time,env));

    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Invalid Millisecond", 799,
        axutil_date_time_get_msec(date_time,env));

    date_time_tmp = axutil_date_time_create(env);

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Date Time Creation Failed", date_time_tmp);
    if (!date_time_tmp)
    {
        return;
    }

    WSF_UNIT_ASSERT_TRUE(tc, "Date Time Deserialize Failed",
        axutil_date_time_deserialize_date(date_time_tmp, env, "2000-11-11"));

    WSF_UNIT_ASSERT_TRUE(tc, "Date Time Deserialize Failed",
        axutil_date_time_deserialize_time(date_time_tmp, env, "12:30:24.799Z"));

    WSF_UNIT_ASSERT_TRUE(tc, "Date Time Not Equal",
        axutil_date_time_compare(date_time, env, date_time_tmp) == 
        AXIS2_DATE_TIME_COMP_RES_EQUAL);

    if (date_time_tmp)
    {
        axutil_date_time_free(date_time_tmp, env);
    }
}

static void WSF_UNIT_CALL test_axutil_date_time_serialize(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;
    axutil_date_time_t *date_time = NULL;
    axutil_date_time_t *date_time_tmp = NULL;
    char *str = NULL;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data->test_data);

    if (!test_data || !test_data->test_data)
    {
        return;
    }
    env = test_data->test_env;
    
    date_time = (axutil_date_time_t *)test_data->test_data;

    str = axutil_date_time_serialize_date_time(date_time, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Date Time Serialize Failed", str);

    if (str)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Serialized String is invalid",
            "2000-11-11T12:30:24.799Z", str);
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }

    str = axutil_date_time_serialize_date(date_time, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Date Time Serialize Failed", str);

    if (str)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Serialized String is invalid",
            "2000-11-11", str);
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }

    str = axutil_date_time_serialize_time(date_time, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Date Time Serialize Failed", str);

    if (str)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Serialized String is invalid",
            "12:30:24.799Z", str);
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }

    date_time_tmp = axutil_date_time_create(env);

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Date Time Creation Failed", date_time_tmp);
    if (!date_time_tmp)
    {
        return;
    }

    WSF_UNIT_ASSERT_TRUE(tc, "Set Date Time Failed",
        axutil_date_time_set_date_time(date_time_tmp, env, 2000, 11, 11, 12, 30, 24, 799));

    str = axutil_date_time_serialize_date_time(date_time_tmp, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Date Time Serialize Failed", str);

    if (str)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Serialized String is invalid",
            "2000-11-11T12:30:24.799Z", str);
        AXIS2_FREE(env->allocator, str);
        str = NULL;
    }
    
    if (date_time_tmp)
    {
        AXIS2_FREE(env->allocator, date_time_tmp);
    }
}

static void WSF_UNIT_CALL test_axutil_date_time_error_input_failures(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;
    axutil_date_time_t *date_time = NULL;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data->test_data);

    if (!test_data || !test_data->test_data)
    {
        return;
    }
    env = test_data->test_env;
    
    date_time = (axutil_date_time_t *)test_data->test_data;

    /* Out-of-Range Errors */
    WSF_UNIT_ASSERT_FALSE(tc, "Date Time Deserialize Invalid",
        axutil_date_time_deserialize_date_time(date_time, env, "2000-13-11T12:30:24.799Z"));
    WSF_UNIT_ASSERT_FALSE(tc, "Set Date Time Invalid",
        axutil_date_time_set_date_time(date_time, env, 2000, 13, 11, 12, 30, 24, 799));
    WSF_UNIT_ASSERT_FALSE(tc, "Date Time Deserialize Invalid",
        axutil_date_time_deserialize_date_time(date_time, env, "2000-0-11T12:30:24.799Z"));
    WSF_UNIT_ASSERT_FALSE(tc, "Set Date Time Invalid",
        axutil_date_time_set_date_time(date_time, env, 2000, 0, 11, 12, 30, 24, 799));
    WSF_UNIT_ASSERT_FALSE(tc, "Date Time Deserialize Invalid",
        axutil_date_time_deserialize_date_time(date_time, env, "2000-11-32T12:30:24.799Z"));
    WSF_UNIT_ASSERT_FALSE(tc, "Set Date Time Invalid",
        axutil_date_time_set_date_time(date_time, env, 2000, 11, 32, 12, 30, 24, 799));
    WSF_UNIT_ASSERT_FALSE(tc, "Date Time Deserialize Invalid",
        axutil_date_time_deserialize_date_time(date_time, env, "2000-11-0T12:30:24.799Z"));
    WSF_UNIT_ASSERT_FALSE(tc, "Set Date Time Invalid",
        axutil_date_time_set_date_time(date_time, env, 2000, 11, 0, 12, 30, 24, 799));
    WSF_UNIT_ASSERT_FALSE(tc, "Date Time Deserialize Invalid",
        axutil_date_time_deserialize_date_time(date_time, env, "2000-11-11T24:30:24.799Z"));
    WSF_UNIT_ASSERT_FALSE(tc, "Set Date Time Invalid",
        axutil_date_time_set_date_time(date_time, env, 2000, 11, 11, 24, 30, 24, 799));
    WSF_UNIT_ASSERT_FALSE(tc, "Date Time Deserialize Invalid",
        axutil_date_time_deserialize_date_time(date_time, env, "2000-11-11T12:60:24.799Z"));
    WSF_UNIT_ASSERT_FALSE(tc, "Set Date Time Invalid",
        axutil_date_time_set_date_time(date_time, env, 2000, 11, 11, 12, 60, 24, 799));
    WSF_UNIT_ASSERT_FALSE(tc, "Date Time Deserialize Invalid",
        axutil_date_time_deserialize_date_time(date_time, env, "2000-11-11T12:30:60.799Z"));
    WSF_UNIT_ASSERT_FALSE(tc, "Set Date Time Invalid",
        axutil_date_time_set_date_time(date_time, env, 2000, 11, 11, 12, 30, 60, 799));
    WSF_UNIT_ASSERT_TRUE(tc, "Date Time Deserialize Invalid",
        axutil_date_time_deserialize_date_time(date_time, env, "2000-11-11T12:30:24.1000Z"));
    WSF_UNIT_ASSERT_TRUE(tc, "Set Date Time Invalid",
        axutil_date_time_set_date_time(date_time, env, 2000, 11, 11, 12, 30, 24, 1000));
    /* End of Error set */

    /* Month Errors */
    WSF_UNIT_ASSERT_FALSE(tc, "Date Time Deserialize Invalid",
        axutil_date_time_deserialize_date_time(date_time, env, "2000-2-30T12:30:24.799Z"));
    WSF_UNIT_ASSERT_FALSE(tc, "Set Date Time Invalid",
        axutil_date_time_set_date_time(date_time, env, 2000, 2, 30, 12, 30, 24, 799));
    WSF_UNIT_ASSERT_FALSE(tc, "Date Time Deserialize Invalid",
        axutil_date_time_deserialize_date_time(date_time, env, "2000-4-31T12:30:24.799Z"));
    WSF_UNIT_ASSERT_FALSE(tc, "Set Date Time Invalid",
        axutil_date_time_set_date_time(date_time, env, 2000, 4, 31, 12, 30, 24, 799)); 
    WSF_UNIT_ASSERT_FALSE(tc, "Date Time Deserialize Invalid",
        axutil_date_time_deserialize_date_time(date_time, env, "2000-6-31T12:30:24.799Z"));
    WSF_UNIT_ASSERT_FALSE(tc, "Set Date Time Invalid",
        axutil_date_time_set_date_time(date_time, env, 2000, 6, 31, 12, 30, 24, 799)); 
    WSF_UNIT_ASSERT_FALSE(tc, "Date Time Deserialize Invalid",
        axutil_date_time_deserialize_date_time(date_time, env, "2000-9-31T12:30:24.799Z"));
    WSF_UNIT_ASSERT_FALSE(tc, "Set Date Time Invalid",
        axutil_date_time_set_date_time(date_time, env, 2000, 9, 31, 12, 30, 24, 799)); 
    WSF_UNIT_ASSERT_FALSE(tc, "Date Time Deserialize Invalid",
        axutil_date_time_deserialize_date_time(date_time, env, "2000-11-31T12:30:24.799Z"));
    WSF_UNIT_ASSERT_FALSE(tc, "Set Date Time Invalid",
        axutil_date_time_set_date_time(date_time, env, 2000, 11, 31, 12, 30, 24, 799));
    /* End of Error set */

    /* Leap Year Errors */
    WSF_UNIT_ASSERT_FALSE(tc, "Date Time Deserialize Invalid",
        axutil_date_time_deserialize_date_time(date_time, env, "2000-2-29T12:30:24.799Z"));
    WSF_UNIT_ASSERT_FALSE(tc, "Set Date Time Invalid",
        axutil_date_time_set_date_time(date_time, env, 2000, 2, 29, 12, 30, 24, 799));
    WSF_UNIT_ASSERT_FALSE(tc, "Date Time Deserialize Invalid",
        axutil_date_time_deserialize_date_time(date_time, env, "2001-2-29T12:30:24.799Z"));
    WSF_UNIT_ASSERT_FALSE(tc, "Set Date Time Invalid",
        axutil_date_time_set_date_time(date_time, env, 2001, 2, 29, 12, 30, 24, 799));
   /* End of Error set */
    WSF_UNIT_ASSERT_TRUE(tc, "Date Time Deserialize Invalid",
        axutil_date_time_deserialize_date_time(date_time, env, "2004-2-29T12:30:24.799Z"));
    WSF_UNIT_ASSERT_TRUE(tc, "Set Date Time Invalid",
        axutil_date_time_set_date_time(date_time, env, 2004, 2, 29, 12, 30, 24, 799));
   /* End of Error set */
}

static void WSF_UNIT_CALL test_axutil_date_time_create_with_offset_gmtime(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;
    axutil_date_time_t *date_time = NULL;
    char *str1 = NULL;
    char *str2 = NULL;
    time_t t;
    struct tm *utc_time = NULL;
    int y, m, d;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);

    if (!test_data)
    {
        return;
    }
    env = test_data->test_env;
    date_time = axutil_date_time_create_with_offset(env, 0);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Date Time Creation Failed", date_time);
    if (!date_time)
    {
        return;
    }
    t = time(NULL);

    utc_time = gmtime(&t);
    y = utc_time->tm_year + 1900;
    m = utc_time->tm_mon + 1;
    d = utc_time->tm_mday;

    str1 = (char *) AXIS2_MALLOC(env->allocator, sizeof(char) * 32);

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Memory Allocation Failure", str1);

    sprintf(str1, "%d-%02d-%02d", y, m, d);

    str2 = axutil_date_time_serialize_date(date_time, env);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Date Time Serialize Failed", str2);

    if (str1 && str2)
    {
        WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Serialized String is Invalid",
            str1, str2);
    }

    if (str1)
    {
        AXIS2_FREE(env->allocator, str1);
    }
    if (str2)
    {
        AXIS2_FREE(env->allocator, str2);
    }
    if (date_time)
    {
        axutil_date_time_free(date_time, env);
    }
}
