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
#ifndef GUTHTHILA_NAMESPACE_H
#define GUTHTHILA_NAMESPACE_H

#include <guththila_defines.h>
#include <guththila_token.h> 
#include <axutil_utils.h>

EXTERN_C_START()

#ifndef GUTHTHILA_NAMESPACE_DEF_SIZE
#define GUTHTHILA_NAMESPACE_DEF_SIZE 4
#endif

typedef struct guththila_namespace_s
{
    guththila_token_t *name;
    guththila_token_t *uri;	 
} guththila_namespace_t;

typedef struct guththila_namespace_list_s
{
	guththila_namespace_t *list;
	guththila_stack_t fr_stack;
	int size;
	int capacity;		
} guththila_namespace_list_t;

guththila_namespace_list_t * GUTHTHILA_CALL guththila_namespace_list_create(const axutil_env_t *env);
int GUTHTHILA_CALL guththila_namespace_list_init(guththila_namespace_list_t *at_list, const axutil_env_t *env);
guththila_namespace_t * GUTHTHILA_CALL guththila_namespace_list_get(guththila_namespace_list_t *at_list, const axutil_env_t *env);
int GUTHTHILA_CALL guththila_namespace_list_release(guththila_namespace_list_t *at_list, guththila_namespace_t *namesp, const axutil_env_t *env);
void GUTHTHILA_CALL msuila_namespace_list_free_data(guththila_namespace_list_t *at_list, const axutil_env_t *env);
void GUTHTHILA_CALL guththila_namespace_list_free(guththila_namespace_list_t *at_list, const axutil_env_t *env);

EXTERN_C_END()

#endif

