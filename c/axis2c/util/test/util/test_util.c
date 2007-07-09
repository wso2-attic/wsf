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

#include <stdio.h>
#include <axutil_hash.h>
#include <axutil_string.h>
#include <axutil_error_default.h>
#include <axutil_array_list.h>
#include <platforms/axutil_platform_auto_sense.h>
#include <axutil_uuid_gen.h>
#include <axutil_log_default.h>
#include <axutil_log.h>
#include <axutil_dir_handler.h>
#include <axutil_file.h>
#include "axutil_log.h"
#include "test_thread.h"
#include <test_log.h>

typedef struct a
{
    axis2_char_t *value;
}
a;

const axutil_env_t *test_init()
{
    axutil_allocator_t *allocator = axutil_allocator_init(NULL);
    axutil_error_t *error = axutil_error_create(allocator);
    const axutil_env_t *env = axutil_env_create_with_error(allocator, error);
    return env;
}

int test_hash_get(const axutil_env_t *env)
{
    axutil_hash_t *ht;
    a *a1, *a2, *a3, *a4;

    axutil_hash_index_t *i = 0;
    void *v = NULL;

    char *key1 = "key1";
    char *key2 = "key2";
    char *key3 = "key3";
    char *key4 = "key4";

    a1 = (a *) AXIS2_MALLOC(env->allocator, sizeof(a));
    a2 = (a *) AXIS2_MALLOC(env->allocator, sizeof(a));
    a3 = (a *) AXIS2_MALLOC(env->allocator, sizeof(a));
    a4 = (a *) AXIS2_MALLOC(env->allocator, sizeof(a));


    a1->value = axutil_strdup(env, "value1");
    a2->value = axutil_strdup(env, "value2");
    a3->value = axutil_strdup(env, "value3");
    a4->value = axutil_strdup(env, "value4");

    ht = axutil_hash_make(env);

    axutil_hash_set(ht, key1, AXIS2_HASH_KEY_STRING, a1);
    axutil_hash_set(ht, key2, AXIS2_HASH_KEY_STRING, a2);
    axutil_hash_set(ht, key3, AXIS2_HASH_KEY_STRING, a3);
    axutil_hash_set(ht, key4, AXIS2_HASH_KEY_STRING, a4);

    axutil_hash_set(ht, key2, AXIS2_HASH_KEY_STRING, NULL);
    axutil_hash_set(ht, key2, AXIS2_HASH_KEY_STRING, a2);
    for (i = axutil_hash_first(ht, env); i; i = axutil_hash_next(env, i))
    {
        axutil_hash_this(i, NULL, NULL, &v);
        printf("\n %s \n", ((a *) v)->value);
    }

    printf("\n demo get %s ",
            ((a *) axutil_hash_get(ht, key1, AXIS2_HASH_KEY_STRING))->value);

    printf("\n demo get %s ",
            ((a *) axutil_hash_get(ht, key2, AXIS2_HASH_KEY_STRING))->value);

    printf("\n demo get %s ",
            ((a *) axutil_hash_get(ht, key3, AXIS2_HASH_KEY_STRING))->value);

    printf("\n demo get %s \n",
            ((a *) axutil_hash_get(ht, key4, AXIS2_HASH_KEY_STRING))->value);

    axutil_hash_free(ht, env);
    AXIS2_FREE(env->allocator, a1->value);
    AXIS2_FREE(env->allocator, a2->value);
    AXIS2_FREE(env->allocator, a3->value);
    AXIS2_FREE(env->allocator, a4->value);
    AXIS2_FREE(env->allocator, a1);
    AXIS2_FREE(env->allocator, a2);
    AXIS2_FREE(env->allocator, a3);
    AXIS2_FREE(env->allocator, a4);
    return 0;
}

void test_axutil_dir_handler_list_service_or_module_dirs()
{
    int i, isize;
    axutil_file_t *file = NULL;
    axis2_char_t *filename = NULL;
    axutil_allocator_t *allocator = axutil_allocator_init(NULL);
    axutil_error_t *error = axutil_error_create(allocator);
    axutil_log_t *log  = axutil_log_create(allocator, NULL, NULL);
    const axutil_env_t *env = axutil_env_create_with_error_log(allocator, error, log);

    axis2_char_t *pathname = axutil_strdup(env, "/tmp/test/");

    axutil_array_list_t *arr_folders = axutil_dir_handler_list_service_or_module_dirs(env, pathname);
    if (arr_folders == NULL)
    {
        printf("List of folders is NULL\n");
        return ;
    }


    isize = axutil_array_list_size(arr_folders, env);
    printf("Folder array size = %d \n", isize);

    for (i = 0;i < isize;++i)
    {
        file = (axutil_file_t*)axutil_array_list_get(arr_folders, env, i);
        filename =  axutil_file_get_name(file, env);
        printf("filename = %s \n", filename);
    }
    printf("----end of test_axutil_dir_handler_list_service_or_module_dirs----\n");

}


/**
  * This test is intended to test whether given two files are equal or not.
  * Spaces and new lines are ignored in comparing
  */
int test_file_diff(const axutil_env_t *env)
{
  /*  axis2_char_t *expected_file_name = axutil_strdup("expected", env);
    axis2_char_t *actual_file_name = axutil_strdup("actual", env);*/
    return 0;
}

void test_array_list(const axutil_env_t *env)
{
    axutil_array_list_t *al;
    a *entry = NULL;
    int size;

    al = axutil_array_list_create(env, 1);
    printf("list size %d\n", axutil_array_list_size(al, env));

    entry = (a *) AXIS2_MALLOC(env->allocator, sizeof(a));
    entry->value = axutil_strdup(env, "value1");
    axutil_array_list_add(al, env, (void*)entry);

    entry = (a *) AXIS2_MALLOC(env->allocator, sizeof(a));
    entry->value = axutil_strdup(env, "value2");
    axutil_array_list_add(al, env, (void*)entry);

    entry = (a *) AXIS2_MALLOC(env->allocator, sizeof(a));
    entry->value = axutil_strdup(env, "value3");
    axutil_array_list_add(al, env, (void*)entry);

    entry = (a *) AXIS2_MALLOC(env->allocator, sizeof(a));
    entry->value = axutil_strdup(env, "value4");
    axutil_array_list_add(al, env, (void*)entry);

    entry = (a *) AXIS2_MALLOC(env->allocator, sizeof(a));
    entry->value = axutil_strdup(env, "value5");
    axutil_array_list_add(al, env, (void*)entry);

    entry = (a *) AXIS2_MALLOC(env->allocator, sizeof(a));
    entry->value = axutil_strdup(env, "value6");
    axutil_array_list_add(al, env, (void*)entry);

    entry = (a *) AXIS2_MALLOC(env->allocator, sizeof(a));
    entry->value = axutil_strdup(env, "value7");
    axutil_array_list_set(al, env, 3, (void*)entry);
    axutil_array_list_remove(al, env, 2);

    entry = (a *) axutil_array_list_get(al, env, 0);
    printf("entry->value:%s\n", entry->value);

    entry = (a *) axutil_array_list_get(al, env, 2);
    printf("entry->value:%s\n", entry->value);
    size = axutil_array_list_size(al, env);
    printf("list size %d\n", axutil_array_list_size(al, env));

}


void test_uuid_gen(const axutil_env_t *env)
{
    char *uuid = NULL;
    printf("starting uuid_gen test...\n");
    uuid = axutil_uuid_gen(env);
    printf("Generated UUID 1:%s\n", uuid);
    AXIS2_FREE(env->allocator, uuid);
    uuid = axutil_uuid_gen(env);
    printf("Generated UUID 2:%s\n", uuid);
    AXIS2_FREE(env->allocator, uuid);
    printf("finished uuid_gen test...\n");
}

void test_log_write()
{
    char msg[10];
    printf("start of test_log_write\n\n");
    axutil_allocator_t *allocator = axutil_allocator_init(NULL);
    if (!allocator)
    {
        printf("allocator is NULL\n");
        return;
    }
    axutil_error_t *error = axutil_error_create(allocator);
    if (!error)
    {
        printf("cannot create error\n");
        return;
    }
    axutil_log_t *log22  = axutil_log_create(allocator, NULL, NULL);
    if (!log22)
    {
        printf("cannot create log\n");
        return;
    }
    log22->level = AXIS2_LOG_LEVEL_DEBUG;

    const axutil_env_t *env = axutil_env_create_with_error_log(allocator, error, log22);
    if (!env)
    {
        printf("cannot create env with error and log\n");
        return;
    }
    strcpy(msg, "abcd test123");

    AXIS2_LOG_CRITICAL(env->log, AXIS2_LOG_SI, "log1 %s", "test1");
    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "log2 %d", 2);
    AXIS2_LOG_WARNING(env->log, AXIS2_LOG_SI, "log3 %s", "test3");
    AXIS2_LOG_INFO(env->log, AXIS2_LOG_SI, "log4 %s %s", "info1", "info2");
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "log5 %s %d", "test", 5);
    printf("end of test_log_write \n\n");

}

int main(void)
{
    const axutil_env_t *env = test_init();
    test_hash_get(env);
    test_file_diff(env);
    test_array_list(env);
    test_uuid_gen(env);
    run_test_log();
    run_test_string(env);
    test_axutil_dir_handler_list_service_or_module_dirs();
    axutil_allocator_t *allocator = env->allocator;
/*    axutil_env_free(env);*/
    axutil_allocator_free(allocator);
    return 0;
}
