
/*
 * Copyrighash_data->hash 2005-2008 WSO2, Inc. hash_data->hashtp://wso2.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * hash_data->hashtp://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <util.h>
#include <axutil_hash.h>

#define HASH_TEST_KEY_ONE "key1"
#define HASH_TEST_KEY_TWO "key2"
#define HASH_TEST_KEY_THREE "key3"
#define HASH_TEST_KEY_FOUR "key4"

typedef struct test_axutil_hash
    test_axutil_hash_t;

typedef struct a
    a_t;

static void WSF_UNIT_CALL
test_axutil_hash_create(
   wsf_unit_test_case_t *tc,
   void *data);

static void WSF_UNIT_CALL
test_axutil_hash_get(
   wsf_unit_test_case_t *tc,
   void *data);

static void WSF_UNIT_CALL
test_axutil_hash_reset(
   wsf_unit_test_case_t *tc,
   void *data);

static void WSF_UNIT_CALL
test_axutil_hash_this(
   wsf_unit_test_case_t *tc,
   void *data);

struct test_axutil_hash
{
    axutil_hash_t *hash;
    a_t *a1;
    a_t *a2;
    a_t *a3;
    a_t *a4;
};

struct a
{
    axis2_char_t *value;
};

wsf_unit_status_t WSF_UNIT_CALL test_hash(wsf_unit_suite_t * suite)
{
    wsf_unit_status_t status = WSF_UNIT_FAILURE;
    axutil_env_t *env = NULL;
    axutil_test_data_t *data = NULL;
    test_axutil_hash_t *test_data = NULL;

    status = WSF_UNIT_ADD_SUB_SUITE(suite);

    env = CREATE_TEST_ENV();
    if (env)
    {
        data = AXIS2_MALLOC(env->allocator, sizeof(axutil_test_data_t));
    }

    if (data)
    {
        data->test_env = env;
        test_data = AXIS2_MALLOC(env->allocator, sizeof(test_axutil_hash_t));
        if (test_data)
        {
            data->test_data = test_data;
            test_data->hash = NULL;
            test_data->a1 = (a_t *) AXIS2_MALLOC(env->allocator, sizeof(a_t));
            if (test_data->a1)
            {
                test_data->a1->value = "value1";
            }
            else
            {
                status = WSF_UNIT_FAILURE;
            }
            test_data->a2 = (a_t *) AXIS2_MALLOC(env->allocator, sizeof(a_t));
            if (test_data->a2)
            {
                test_data->a2->value = "value2";
            }
            else
            {
                status = WSF_UNIT_FAILURE;
            }
            test_data->a3 = (a_t *) AXIS2_MALLOC(env->allocator, sizeof(a_t));
            if (test_data->a3)
            {
                test_data->a3->value = (axis2_char_t *)axutil_strdup(env, "value3");
            }
            else
            {
                status = WSF_UNIT_FAILURE;
            }
            test_data->a4 = (a_t *) AXIS2_MALLOC(env->allocator, sizeof(a_t));
            if (test_data->a4)
            {
                test_data->a4->value = (axis2_char_t *)axutil_strdup(env, "value4");
            }
            else
            {
                status = WSF_UNIT_FAILURE;
            }
        }
        else
        {
            data->test_data = NULL;
        }
    }

    wsf_unit_run_test(suite, test_axutil_hash_create, data);
    wsf_unit_run_test(suite, test_axutil_hash_get, data);
    wsf_unit_run_test(suite, test_axutil_hash_reset, data);
    wsf_unit_run_test(suite, test_axutil_hash_this, data);

    if (test_data)
    {
        if (test_data->a1)
        {
            AXIS2_FREE(env->allocator, test_data->a1);
        }
        else
        {
            status = WSF_UNIT_FAILURE;
        }
        if (test_data->a2)
        {
            AXIS2_FREE(env->allocator, test_data->a2);
        }
        else
        {
            status = WSF_UNIT_FAILURE;
        }
        if (test_data->a3)
        {
            if (test_data->a3->value)
            {
                AXIS2_FREE(env->allocator, test_data->a3->value);
            }
            else
            {
                status = WSF_UNIT_FAILURE;
            }
            AXIS2_FREE(env->allocator, test_data->a3);
        }
        else
        {
            status = WSF_UNIT_FAILURE;
        }
        if (test_data->a4)
        {
            if (test_data->a4->value)
            {
                AXIS2_FREE(env->allocator, test_data->a4->value);
            }
            else
            {
                status = WSF_UNIT_FAILURE;
            }
            AXIS2_FREE(env->allocator, test_data->a4);
        }
        else
        {
            status = WSF_UNIT_FAILURE;
        }
        if (test_data->hash)
        {
            axutil_hash_free(test_data->hash, env);
        }
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

static void WSF_UNIT_CALL test_axutil_hash_create(wsf_unit_test_case_t *tc, void *data)
{
    axutil_hash_index_t *i = 0;
    void *v = NULL;
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = NULL;
    test_axutil_hash_t *hash_data = NULL;

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
        hash_data = (test_axutil_hash_t *)test_data->test_data;
    }
    else
    {
        return;
    }

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", hash_data);

    if (!hash_data)
    {
        return;
    }

    hash_data->hash = axutil_hash_make(env);

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Hash Create Failed", hash_data->hash);

    axutil_hash_set(hash_data->hash, HASH_TEST_KEY_ONE, 
        AXIS2_HASH_KEY_STRING, hash_data->a1);
    axutil_hash_set(hash_data->hash, HASH_TEST_KEY_TWO, 
        AXIS2_HASH_KEY_STRING, hash_data->a2);
    axutil_hash_set(hash_data->hash, HASH_TEST_KEY_THREE, 
        AXIS2_HASH_KEY_STRING, hash_data->a3);
    axutil_hash_set(hash_data->hash, HASH_TEST_KEY_FOUR, 
        AXIS2_HASH_KEY_STRING, hash_data->a4);
    
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Wrong Hash Count", 4,
        axutil_hash_count(hash_data->hash));
}

static void WSF_UNIT_CALL test_axutil_hash_get(wsf_unit_test_case_t *tc, void *data)
{
    axutil_hash_index_t *i = 0;
    void *v = NULL;
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = NULL;
    test_axutil_hash_t *hash_data = NULL;

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
        hash_data = (test_axutil_hash_t *)test_data->test_data;
    }
    else
    {
        return;
    }

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", hash_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Hash Unavailable", hash_data->hash);

    if (!hash_data || !hash_data->hash)
    {
        return;
    }

    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Wrong Hash Count", 4,
        axutil_hash_count(hash_data->hash));

    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Hash Get Failed", hash_data->a1->value,
        ((a_t *)axutil_hash_get(hash_data->hash, HASH_TEST_KEY_ONE,
          AXIS2_HASH_KEY_STRING))->value);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Hash Get Failed", hash_data->a2->value,
        ((a_t *)axutil_hash_get(hash_data->hash, HASH_TEST_KEY_TWO,
          AXIS2_HASH_KEY_STRING))->value);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Hash Get Failed", hash_data->a3->value,
        ((a_t *)axutil_hash_get(hash_data->hash, HASH_TEST_KEY_THREE,
          AXIS2_HASH_KEY_STRING))->value);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Hash Get Failed", hash_data->a4->value,
        ((a_t *)axutil_hash_get(hash_data->hash, HASH_TEST_KEY_FOUR,
          AXIS2_HASH_KEY_STRING))->value);
}

static void WSF_UNIT_CALL test_axutil_hash_reset(wsf_unit_test_case_t *tc, void *data)
{
    axutil_hash_index_t *i = 0;
    void *v = NULL;
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = NULL;
    test_axutil_hash_t *hash_data = NULL;

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
        hash_data = (test_axutil_hash_t *)test_data->test_data;
    }
    else
    {
        return;
    }

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", hash_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Hash Unavailable", hash_data->hash);

    if (!hash_data || !hash_data->hash)
    {
        return;
    }

    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Wrong Hash Count", 4,
        axutil_hash_count(hash_data->hash));

    axutil_hash_set(hash_data->hash, HASH_TEST_KEY_TWO, 
        AXIS2_HASH_KEY_STRING, NULL);
    WSF_UNIT_ASSERT_NULL(tc, "Hash Get Failed", axutil_hash_get(hash_data->hash, HASH_TEST_KEY_TWO,
          AXIS2_HASH_KEY_STRING));
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Wrong Hash Count", 3,
        axutil_hash_count(hash_data->hash));

    axutil_hash_set(hash_data->hash, HASH_TEST_KEY_TWO, 
        AXIS2_HASH_KEY_STRING, hash_data->a4);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Hash Get Failed", hash_data->a4->value,
        ((a_t *)axutil_hash_get(hash_data->hash, HASH_TEST_KEY_TWO,
          AXIS2_HASH_KEY_STRING))->value);
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Wrong Hash Count", 4,
        axutil_hash_count(hash_data->hash));

    axutil_hash_set(hash_data->hash, HASH_TEST_KEY_TWO, 
        AXIS2_HASH_KEY_STRING, hash_data->a2);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Hash Get Failed", hash_data->a2->value,
        ((a_t *)axutil_hash_get(hash_data->hash, HASH_TEST_KEY_TWO,
          AXIS2_HASH_KEY_STRING))->value);
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Wrong Hash Count", 4,
        axutil_hash_count(hash_data->hash));

    axutil_hash_set(hash_data->hash, HASH_TEST_KEY_THREE, 
        AXIS2_HASH_KEY_STRING, NULL);
    WSF_UNIT_ASSERT_NULL(tc, "Hash Get Failed", axutil_hash_get(hash_data->hash, HASH_TEST_KEY_THREE,
          AXIS2_HASH_KEY_STRING));
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Wrong Hash Count", 3,
        axutil_hash_count(hash_data->hash));

    axutil_hash_set(hash_data->hash, HASH_TEST_KEY_THREE, 
        AXIS2_HASH_KEY_STRING, hash_data->a3);
    WSF_UNIT_ASSERT_EQUALS_STRING(tc, "Hash Get Failed", hash_data->a3->value,
        ((a_t *)axutil_hash_get(hash_data->hash, HASH_TEST_KEY_THREE,
          AXIS2_HASH_KEY_STRING))->value);
    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Wrong Hash Count", 4,
        axutil_hash_count(hash_data->hash));
}

static void WSF_UNIT_CALL test_axutil_hash_this(wsf_unit_test_case_t *tc, void *data)
{
    a_t **a;
    axutil_hash_index_t *i = 0;
    int j = 0;
    void *v = NULL;
    a_t *u = NULL;
    axutil_env_t *env = NULL;
    axutil_test_data_t *test_data = NULL;
    test_axutil_hash_t *hash_data = NULL;

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
        hash_data = (test_axutil_hash_t *)test_data->test_data;
    }
    else
    {
        return;
    }

    WSF_UNIT_ASSERT_NOT_NULL(tc, "Test Data Unavailable", hash_data);
    WSF_UNIT_ASSERT_NOT_NULL(tc, "Hash Unavailable", hash_data->hash);

    if (!hash_data || !hash_data->hash)
    {
        return;
    }

    a = (a_t **) AXIS2_MALLOC(env->allocator, sizeof(a_t) * 4);
    a[0] = hash_data->a1;
    a[1] = hash_data->a2;
    a[2] = hash_data->a3;
    a[3] = hash_data->a4;

    WSF_UNIT_ASSERT_EQUALS_INT(tc, "Wrong Hash Count", 4,
        axutil_hash_count(hash_data->hash));

    for (i = axutil_hash_first(hash_data->hash, env); i; i = axutil_hash_next(env, i))
    {
        axutil_hash_this(i, NULL, NULL, &v);
        u = (a_t *) v;
        for (j = 0; j < 4; j++)
        {
            if (u == a[j])
            {
                break;
            }
        }
        WSF_UNIT_ASSERT_NOT_EQUALS_INT(tc, "Hash This Failed", 4, j);
    }
    if (a)
    {
        AXIS2_FREE(env->allocator, a);
    }
}
