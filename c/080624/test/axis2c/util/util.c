
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

#include <stdio.h>
#include <util.h>

const struct wsf_unit_test_list axutil_tests[] =
{
    {test_array_list},
    {test_base64_binary},
    {test_date_time},
    {test_dir_handler},
    {test_duration},
    {test_hash},
    {test_log},
    {test_md5},
    {test_properties},
    {test_rand},
    {test_stack},
    {test_string},
    {test_string_util},
    {test_thread},
    {test_uri},
    {test_url},
    {test_uuid_gen}
};

int main(int argc, const char *const argv[])
{
    return wsf_unit_execute(argc, argv, "Axis2/C Util",
        (sizeof(axutil_tests) / sizeof(struct wsf_unit_test_list *)),
        axutil_tests);
    return 0;
}

WSF_UNIT_EXTERN axutil_env_t *WSF_UNIT_CALL
axutil_create_test_environment()
{
    return axutil_env_create_all("axutil_tests.log", AXIS2_LOG_LEVEL_TRACE);
}


