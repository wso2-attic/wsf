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

#ifndef TEST_LOG_H
#define TEST_LOG_H

#include <axutil_env.h>
#include <axutil_thread.h>


void init_func(void);
void thread_init(const axutil_env_t *env);
void * AXIS2_CALL test_function(axutil_thread_t *td,void *param);
void test_axutil_thread_create(const axutil_env_t *env);
void * AXIS2_CALL test_function2(axutil_thread_t *td,void *param);
void test_axutil_thread_detach(const axutil_env_t *env);
void test_axutil_thread_detach2(const axutil_env_t *env);
void check_locks();
/*call this method from main*/
void run_test_thread(const axutil_env_t *env);

#endif

