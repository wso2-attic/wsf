
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
#include "test_dir_handler.h"
#include <axutil_file.h>

static void WSF_UNIT_CALL
test_axutil_dir_handler_list_service_or_module_dirs(    
    wsf_unit_test_case_t *tc,
    void *data);

static void WSF_UNIT_CALL
test_axutil_dir_handler_list_services_or_modules_in_dir(    
    wsf_unit_test_case_t *tc,
    void *data);

wsf_unit_status_t WSF_UNIT_CALL test_dir_handler(wsf_unit_suite_t * suite)
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

    wsf_unit_run_test(suite,
        test_axutil_dir_handler_list_service_or_module_dirs, data);
    wsf_unit_run_test(suite,
        test_axutil_dir_handler_list_services_or_modules_in_dir, data);

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

static void WSF_UNIT_CALL
test_axutil_dir_handler_list_service_or_module_dirs(
    wsf_unit_test_case_t *tc,
    void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;
    axutil_array_list_t *dir_array = NULL;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);

    env = test_data->test_env;
#ifndef TEST_DIR_HANDLER_LIST_DIRS_IMPLEMENTED
    WSF_UNIT_NOT_IMPLEMENTED(tc, "Listing Service/Module Dir Test Not Enabled");
    /* Modify test_dir_handler.h, and rebuild to enable */
#else
    dir_array = axutil_dir_handler_list_service_or_module_dirs(env,
                    TEST_DIR_HANDLER_LIST_DIRS_PATH);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Returned Array of Directories is NULL", dir_array);
    WSF_UNIT_ASSERT_EQUALS_INT(tc, NULL, TEST_DIR_HANDLER_LIST_DIRS_FOLDER_COUNT,
        axutil_array_list_size(dir_array, env));
   if (dir_array)
   {
       int size = 0;
       int j = 0;
       axutil_file_t *del_dir = NULL;

       size = axutil_array_list_size(dir_array, env);
       for (j = 0; j < size; j++)
       {
           del_dir = axutil_array_list_get(dir_array, env, j);
           WSF_UNIT_ASSERT_NOT_NULL(tc, "Reference on List is NULL", del_dir);
           if (del_dir)
           {
               axutil_file_free(del_dir, env);
           }
       }
       axutil_array_list_free(dir_array, env);
   }
#endif
}

static void WSF_UNIT_CALL
test_axutil_dir_handler_list_services_or_modules_in_dir(
    wsf_unit_test_case_t *tc,
    void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = (axutil_test_data_t *)data;
    axutil_array_list_t *file_array = NULL;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);

    env = test_data->test_env;
#ifndef TEST_DIR_HANDLER_LIST_DLLS_IMPLEMENTED
    WSF_UNIT_NOT_IMPLEMENTED(tc, "Listing Services/Modules in Dir Test Not Enabled");
    /* Modify test_dir_handler.h, and rebuild to enable */
#else
    file_array = axutil_dir_handler_list_services_or_modules_in_dir(env,
                    TEST_DIR_HANDLER_LIST_DLLS_PATH);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Returned Array of Files is NULL", file_array);
    WSF_UNIT_ASSERT_EQUALS_INT(tc, NULL, TEST_DIR_HANDLER_LIST_DLLS_FILE_COUNT,
        axutil_array_list_size(file_array, env));
   if (file_array)
   {
       int size = 0;
       int j = 0;
       axutil_file_t *del_file = NULL;

       size = axutil_array_list_size(file_array, env);
       for (j = 0; j < size; j++)
       {
           del_file = axutil_array_list_get(file_array, env, j);
           WSF_UNIT_ASSERT_NOT_NULL(tc, "Reference on List is NULL", del_file);
           if (del_file)
           {
               axutil_file_free(del_file, env);
           }
       }
       axutil_array_list_free(file_array, env);
   }
#endif
}
