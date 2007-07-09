/*
* Licensed to the Apache Software Foundation (ASF) under one or more
* contributor license agreements.  See the NOTICE file distributed with
* this work for additional information regarding copyright ownership.
* The ASF licenses this file to You under the Apache License, Version 2.0
* (the "License"); you may not use this file except in compliance with
* the License.  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef _TEST_LOG_H_
#define _TEST_LOG_H_

#include <axutil_env.h>

void run_test_log();
const axutil_env_t *create_env_with_error_log();
void test_axutil_log_write(const axutil_env_t *env);
void test_axutil_log_debug(const axutil_env_t *env);
void test_axutil_log_debug_off(const axutil_env_t *env);
void test_axutil_log_info(const axutil_env_t *env);
void test_axutil_log_info_off(const axutil_env_t *env);
void test_axutil_log_warning(const axutil_env_t *env);
void test_axutil_log_warning_off(const axutil_env_t *env);
void test_axutil_log_error(const axutil_env_t *env);
void test_axutil_log_critical(const axutil_env_t *env);

#endif /* _TEST_LOG_H_ */

