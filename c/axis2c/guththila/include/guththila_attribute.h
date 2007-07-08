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
#ifndef GUTHTHILA_ATTRIBUTE_H
#define GUTHTHILA_ATTRIBUTE_H

#include <guththila_defines.h>
#include <guththila_token.h>
#include <axutil_utils.h>

EXTERN_C_START()

#ifndef GUTHTHILA_ATTR_DEF_SIZE
#define GUTHTHILA_ATTR_DEF_SIZE 16
#endif

typedef struct guththila_attr_s
{
    guththila_token_t *pref;
    guththila_token_t *name;
    guththila_token_t *val;
} guththila_attr_t;

typedef struct guththila_attr_list_s
{
	guththila_attr_t *list;
	guththila_stack_t fr_stack;
	int size;
	int capacity;		
} guththila_attr_list_t;

guththila_attr_list_t * GUTHTHILA_CALL guththila_attr_list_create(const axutil_env_t *env);
int GUTHTHILA_CALL guththila_attr_list_init(guththila_attr_list_t *at_list, const axutil_env_t *env);
guththila_attr_t * GUTHTHILA_CALL guththila_attr_list_get(guththila_attr_list_t *at_list, const axutil_env_t *env);
int GUTHTHILA_CALL guththila_attr_list_release(guththila_attr_list_t *at_list, guththila_attr_t *attr, const axutil_env_t *env);
void GUTHTHILA_CALL msuila_attr_list_free_data(guththila_attr_list_t *at_list, const axutil_env_t *env);
void GUTHTHILA_CALL guththila_attr_list_free(guththila_attr_list_t *at_list, const axutil_env_t *env);

EXTERN_C_END()

#endif

