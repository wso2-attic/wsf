
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
#include <axutil_thread.h>

typedef struct test_axutil_thread
    test_axutil_thread_t;

#define THREAD_FUNCTION_TEST_VALUE_ONE 1
#define THREAD_FUNCTION_TEST_VALUE_TWO 5
#define THREAD_FUNCTION_TEST_VALUE_THREE 25
#define THREAD_FUNCTION_TEST_VALUE_FOUR 125

void *AXIS2_CALL
thread_function1(
    axutil_thread_t * td,
    void *param);

void *AXIS2_CALL
thread_function2(
    axutil_thread_t * td,
    void *param);

void
thread_once_function(
    void);

static void WSF_UNIT_CALL
test_axutil_thread_init(
   wsf_unit_test_case_t *tc,
   void *data);

static void WSF_UNIT_CALL
test_axutil_thread_create(
   wsf_unit_test_case_t *tc,
   void *data);

static void WSF_UNIT_CALL
test_axutil_thread_test_create(
   wsf_unit_test_case_t *tc,
   void *data);

static void WSF_UNIT_CALL
test_axutil_thread_detach(
   wsf_unit_test_case_t *tc,
   void *data);

static void WSF_UNIT_CALL
test_axutil_thread_test_values(
   wsf_unit_test_case_t *tc,
   void *data);

static void WSF_UNIT_CALL
test_axutil_thread_test_thread_free(
   wsf_unit_test_case_t *tc,
   void *data);

struct test_axutil_thread
{
    wsf_unit_test_case_t *tc;
    axutil_thread_mutex_t *thread_lock;
    axutil_thread_once_t *control;
    int lock_count;
    int *test_value1;
    int *test_value2;
    int *test_value3;
    int *test_value4;
    axutil_thread_t *t1;
    axutil_thread_t *t2;
    axutil_thread_t *t3;
    axutil_thread_t *t4;
};

static int value = 0;

wsf_unit_status_t WSF_UNIT_CALL test_thread(wsf_unit_suite_t * suite)
{
    wsf_unit_status_t status = WSF_UNIT_FAILURE;
    axutil_env_t *env = NULL;
    axutil_test_data_t *data = NULL;
    test_axutil_thread_t *thread_data = NULL;

    status = WSF_UNIT_ADD_SUB_SUITE(suite);

    env = CREATE_TEST_ENV();
    if (env)
    {
        data = AXIS2_MALLOC(env->allocator, sizeof(axutil_test_data_t));
    }
    if (data)
    {
        data->test_env = env;
        thread_data = AXIS2_MALLOC(env->allocator, sizeof(test_axutil_thread_t));
        if (thread_data)
        {
            data->test_data = thread_data;
            thread_data->tc = NULL;
            thread_data->thread_lock = NULL;
            thread_data->control = NULL;
            thread_data->lock_count = 0;
            thread_data->test_value1 = NULL;
            thread_data->test_value2 = NULL;
            thread_data->test_value3 = NULL;
            thread_data->test_value4 = NULL;
            thread_data->t1 = NULL;
            thread_data->t2 = NULL;
            thread_data->t3 = NULL;
            thread_data->t4 = NULL;
        }
        else
        {
            data->test_data = NULL;
        }
    }

    wsf_unit_run_test(suite, test_axutil_thread_init, data);
    wsf_unit_run_test(suite, test_axutil_thread_create, data);
    wsf_unit_run_test(suite, test_axutil_thread_test_create, data);
    wsf_unit_run_test(suite, test_axutil_thread_detach, data);
#if defined (WIN32)
    Sleep(1000);                /*to give time for detached threads to execute */
#else
    sleep(2);
#endif
    wsf_unit_run_test(suite, test_axutil_thread_test_values, data);

    if (thread_data)
    {
        if (thread_data->test_value1)
        {
            AXIS2_FREE(env->allocator, thread_data->test_value1);
            thread_data->test_value1 = NULL;
        }
        if (thread_data->test_value2)
        {
            AXIS2_FREE(env->allocator, thread_data->test_value2);
            thread_data->test_value2 = NULL;
        }
        if (thread_data->test_value3)
        {
            AXIS2_FREE(env->allocator, thread_data->test_value3);
            thread_data->test_value3 = NULL;
        }
        if (thread_data->test_value4)
        {
            AXIS2_FREE(env->allocator, thread_data->test_value4);
            thread_data->test_value4 = NULL;
        }
        if (thread_data->thread_lock)
        {
            axutil_thread_mutex_destroy(thread_data->thread_lock);
        }
    }
    wsf_unit_run_test(suite, test_axutil_thread_test_thread_free, data);

    if (thread_data)
    {
        AXIS2_FREE(env->allocator, thread_data);
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

void *AXIS2_CALL
thread_function1(
    axutil_thread_t * td,
    void *data)
{
    int i = 0;
    int *j = NULL;
    axutil_test_data_t *test_data = NULL;
    test_axutil_thread_t *thread_data = NULL;

    test_data = (axutil_test_data_t *)data;

    if (test_data)
    {
        thread_data = (test_axutil_thread_t *)test_data->test_data;
    }
    if (!thread_data || !thread_data->tc)
    {
        return NULL;
    }

    if (thread_data->test_value1)
    {
        i = *((int *) thread_data->test_value1);
        j = (int *) thread_data->test_value1;
        *j = i + 1;
    }

    WSF_UNIT_ASSERT_EQUALS_INT(thread_data->tc, NULL,
        THREAD_FUNCTION_TEST_VALUE_ONE, i);

    axutil_thread_once(thread_data->control, thread_once_function);

    axutil_thread_mutex_lock(thread_data->thread_lock);
    thread_data->lock_count++;
    axutil_thread_mutex_unlock(thread_data->thread_lock);

    return NULL;
}

void *AXIS2_CALL
thread_function2(
    axutil_thread_t * td,
    void *data)
{
    int i = 0;
    int *j = NULL;
    axutil_test_data_t *test_data = NULL;
    test_axutil_thread_t *thread_data = NULL;

    test_data = (axutil_test_data_t *)data;

    if (test_data)
    {
        thread_data = (test_axutil_thread_t *)test_data->test_data;
    }
    if (!thread_data || !thread_data->tc)
    {
        return NULL;
    }

    if (thread_data->test_value2)
    {
        i = *((int *) thread_data->test_value2);
        j = (int *) thread_data->test_value2;
        *j = i + 1;
    }

    WSF_UNIT_ASSERT_EQUALS_INT(thread_data->tc, NULL,
        THREAD_FUNCTION_TEST_VALUE_TWO, i);

    axutil_thread_once(thread_data->control, thread_once_function);

    axutil_thread_mutex_lock(thread_data->thread_lock);
    thread_data->lock_count += 2;
    axutil_thread_mutex_unlock(thread_data->thread_lock);

    return NULL;
}

void *AXIS2_CALL
thread_function3(
    axutil_thread_t * td,
    void *data)
{
    int i = 0;
    int *j = NULL;
    axutil_test_data_t *test_data = NULL;
    test_axutil_thread_t *thread_data = NULL;

    test_data = (axutil_test_data_t *)data;

    if (test_data)
    {
        thread_data = (test_axutil_thread_t *)test_data->test_data;
    }
    if (!thread_data || !thread_data->tc)
    {
        return NULL;
    }

    if (thread_data->test_value3)
    {
        i = *((int *) thread_data->test_value3);
        j = (int *) thread_data->test_value3;
        *j = i + 1;
    }

    WSF_UNIT_ASSERT_EQUALS_INT(thread_data->tc, NULL,
        THREAD_FUNCTION_TEST_VALUE_THREE, i);
}

void *AXIS2_CALL
thread_function4(
    axutil_thread_t * td,
    void *data)
{
    int i = 0;
    int *j = NULL;
    axutil_test_data_t *test_data = NULL;
    test_axutil_thread_t *thread_data = NULL;

    test_data = (axutil_test_data_t *)data;

    if (test_data)
    {
        thread_data = (test_axutil_thread_t *)test_data->test_data;
    }
    if (!thread_data || !thread_data->tc)
    {
        return NULL;
    }

    if (thread_data->test_value4)
    {
        i = *((int *) thread_data->test_value4);
        j = (int *) thread_data->test_value4;
        *j = i + 1;
    }

    WSF_UNIT_ASSERT_EQUALS_INT(thread_data->tc, NULL,
        THREAD_FUNCTION_TEST_VALUE_FOUR, i);
}

void
thread_once_function(
    void)
{
    value++;
}

static void WSF_UNIT_CALL test_axutil_thread_init(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = NULL;
    test_axutil_thread_t *thread_data = NULL;

    test_data = (axutil_test_data_t *)data;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);

    if (!test_data->test_env)
    {
        return;
    }
    else
    {
        env = test_data->test_env;
    }

    if (test_data)
    {
        thread_data = (test_axutil_thread_t *)test_data->test_data;
    }
    else
    {
        return;
    }
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", thread_data);

    if (!thread_data)
    {
        return;
    }

    thread_data->control = axutil_thread_once_init(env->allocator);
    WSF_UNIT_ASSERT_NOT_NULL(tc, 
        "Initializing of Control Variable for axutil_thread_once Failed",
        thread_data->control);

    thread_data->thread_lock = axutil_thread_mutex_create(env->allocator, 
                                   AXIS2_THREAD_MUTEX_DEFAULT);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Thread Mutex Creation Failed",
        thread_data->thread_lock);    

    env = NULL;
}

static void WSF_UNIT_CALL test_axutil_thread_create(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = NULL;
    test_axutil_thread_t *thread_data = NULL;

    test_data = (axutil_test_data_t *)data;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);

    if (!test_data->test_env)
    {
        return;
    }
    else
    {
        env = test_data->test_env;
    }

    if (test_data)
    {
        thread_data = (test_axutil_thread_t *)test_data->test_data;
    }
    else
    {
        return;
    }
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", thread_data);

    if (!thread_data)
    {
        return;
    }

    thread_data->tc = tc;

    thread_data->test_value1 = AXIS2_MALLOC(env->allocator, sizeof(int));
    *(thread_data->test_value1) = THREAD_FUNCTION_TEST_VALUE_ONE;
    thread_data->t1 = axutil_thread_create(env->allocator, NULL,
                          thread_function1, test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Creation of Thread Failed", thread_data->t1);

    thread_data->test_value2 = AXIS2_MALLOC(env->allocator, sizeof(int));
    *(thread_data->test_value2) = THREAD_FUNCTION_TEST_VALUE_TWO;
    thread_data->t2 = axutil_thread_create(env->allocator, NULL,
                          thread_function2, test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Creation of Thread Failed", thread_data->t2);

    if (thread_data->t1)
    {
        WSF_UNIT_ASSERT_TRUE(tc, "Thread Join Failed",
            axutil_thread_join(thread_data->t1));
    }
    if (thread_data->t2)
    {
        WSF_UNIT_ASSERT_TRUE(tc, "Thread Join Failed",
            axutil_thread_join(thread_data->t2));
    }

    env = NULL;
}

static void WSF_UNIT_CALL test_axutil_thread_test_create(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = NULL;
    test_axutil_thread_t *thread_data = NULL;

    test_data = (axutil_test_data_t *)data;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);

    if (!test_data->test_env)
    {
        return;
    }
    else
    {
        env = test_data->test_env;
    }

    if (test_data)
    {
        thread_data = (test_axutil_thread_t *)test_data->test_data;
    }
    else
    {
        return;
    }
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", thread_data);

    if (!thread_data)
    {
        return;
    }
 
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Thread Locking Failed", 3, thread_data->lock_count);
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Thread Once Failed", 1, value);

    env = NULL;
}

static void WSF_UNIT_CALL test_axutil_thread_detach(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = NULL;
    test_axutil_thread_t *thread_data = NULL;
    axutil_threadattr_t *attr = NULL;

    test_data = (axutil_test_data_t *)data;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);

    if (!test_data->test_env)
    {
        return;
    }
    else
    {
        env = test_data->test_env;
    }

    if (test_data)
    {
        thread_data = (test_axutil_thread_t *)test_data->test_data;
    }
    else
    {
        return;
    }
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", thread_data);

    if (!thread_data)
    {
        return;
    }

    thread_data->tc = tc;

    attr = axutil_threadattr_create(env->allocator);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Thread Attributes Creation Failed", attr);
    if (!attr)
    {
        return;
    }

    WSF_UNIT_ASSERT_TRUE(tc, "Setting Detached State Failed",
        axutil_threadattr_detach_set(attr, WSF_UNIT_TRUE));

    thread_data->test_value3 = AXIS2_MALLOC(env->allocator, sizeof(int));
    *(thread_data->test_value3) = THREAD_FUNCTION_TEST_VALUE_THREE;
    thread_data->t3 = axutil_thread_create(env->allocator,
                          attr, thread_function3, test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Creation of Thread Failed", thread_data->t3);

    if (!thread_data->t3)
    {
        return;
    }

    WSF_UNIT_ASSERT_FALSE(tc, "Thread Detach Succeeded, when it Should'nt",
            axutil_thread_detach(thread_data->t3));

    attr = NULL;

    attr = axutil_threadattr_create(env->allocator);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Thread Attributes Creation Failed", attr);
    if (!attr)
    {
        return;
    }

    thread_data->test_value4 = AXIS2_MALLOC(env->allocator, sizeof(int));
    *(thread_data->test_value4) = THREAD_FUNCTION_TEST_VALUE_FOUR;
    thread_data->t4 = axutil_thread_create(env->allocator,
                          attr, thread_function4, test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Creation of Thread Failed", thread_data->t4);

    if (!thread_data->t4)
    {
        return;
    }

    WSF_UNIT_ASSERT_TRUE(tc, "Thread Detach Failed",
            axutil_thread_detach(thread_data->t4));

    env = NULL;
}

static void WSF_UNIT_CALL test_axutil_thread_test_values(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = NULL;
    test_axutil_thread_t *thread_data = NULL;
    axutil_threadattr_t *attr = NULL;

    test_data = (axutil_test_data_t *)data;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);

    if (!test_data->test_env)
    {
        return;
    }
    else
    {
        env = test_data->test_env;
    }

    if (test_data)
    {
        thread_data = (test_axutil_thread_t *)test_data->test_data;
    }
    else
    {
        return;
    }
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", thread_data);

    if (!thread_data)
    {
        return;
    }
    WSF_UNIT_ASSERT_EQUALS_INT(tc, NULL,
        THREAD_FUNCTION_TEST_VALUE_ONE + 1, *(thread_data->test_value1));
    WSF_UNIT_ASSERT_EQUALS_INT(tc, NULL,
        THREAD_FUNCTION_TEST_VALUE_TWO + 1, *(thread_data->test_value2));
    WSF_UNIT_ASSERT_EQUALS_INT(tc, NULL,
        THREAD_FUNCTION_TEST_VALUE_THREE + 1, *(thread_data->test_value3));
    WSF_UNIT_ASSERT_EQUALS_INT(tc, NULL,
        THREAD_FUNCTION_TEST_VALUE_FOUR + 1, *(thread_data->test_value4));
}

static void WSF_UNIT_CALL test_axutil_thread_test_thread_free(wsf_unit_test_case_t *tc, void *data)
{
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = NULL;
    test_axutil_thread_t *thread_data = NULL;
    axutil_threadattr_t *attr = NULL;

    test_data = (axutil_test_data_t *)data;

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", test_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Environment Unavailable", test_data->test_env);

    if (!test_data->test_env)
    {
        return;
    }
    else
    {
        env = test_data->test_env;
    }

    if (test_data)
    {
        thread_data = (test_axutil_thread_t *)test_data->test_data;
    }
    else
    {
        return;
    }
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", thread_data);

    if (!thread_data)
    {
        return;
    }
    WSF_UNIT_ASSERT_NULL(tc, "Value Not Freed", thread_data->test_value1);
    WSF_UNIT_ASSERT_NULL(tc, "Value Not Freed", thread_data->test_value2);
    WSF_UNIT_ASSERT_NULL(tc, "Value Not Freed", thread_data->test_value3);
    WSF_UNIT_ASSERT_NULL(tc, "Value Not Freed", thread_data->test_value4);
    WSF_UNIT_NOT_IMPLEMENTED(tc, "Testing of Free'ing Threads not Implemented");
}
