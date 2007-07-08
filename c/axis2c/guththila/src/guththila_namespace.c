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
#include <guththila_namespace.h>
#include <guththila_stack.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GUTHTHILA_CALL guththila_namespace_list_grow(guththila_namespace_list_t *namesp_list, int addition, const axutil_env_t *env)
{
	int  i = 0;
	if (addition > 0 || (addition < 0 && namesp_list->capacity + addition > 0 && namesp_list->capacity + addition >= namesp_list->size)) {
		namesp_list->list = (guththila_namespace_t *)realloc(namesp_list->list, sizeof(guththila_namespace_t) * (namesp_list->capacity + addition));
		if (namesp_list->list){			
			for (i = namesp_list->capacity; i < namesp_list->capacity + addition; i++){
				guththila_stack_push(&namesp_list->fr_stack, namesp_list->list + i, env);
			}
			namesp_list->capacity += addition;
		} else {
			return GUTHTHILA_FAILURE;
		}
	}
	return 0;
}

guththila_namespace_list_t * GUTHTHILA_CALL guththila_namespace_list_create(const axutil_env_t *env)
{
	int i = 0;
	guththila_namespace_list_t *namesp_list = (guththila_namespace_list_t *) AXIS2_MALLOC(env->allocator, sizeof(guththila_namespace_list_t));
	if (!namesp_list) return NULL;

	namesp_list->list = (guththila_namespace_t *)AXIS2_MALLOC(env->allocator, sizeof(guththila_namespace_t) * GUTHTHILA_NAMESPACE_DEF_SIZE);

	if (namesp_list->list && guththila_stack_init(&namesp_list->fr_stack, env)){
		namesp_list->capacity = GUTHTHILA_NAMESPACE_DEF_SIZE;
		namesp_list->size = 0;
		for (i = 0;i < GUTHTHILA_NAMESPACE_DEF_SIZE; i++){
			guththila_stack_push(&namesp_list->fr_stack, namesp_list->list + i, env);
		}
		return namesp_list;	
	}
	return NULL;
}

int GUTHTHILA_CALL guththila_namespace_list_init(guththila_namespace_list_t *namesp_list, const axutil_env_t *env)
{
	int i = 0;	
	namesp_list->list = (guththila_namespace_t *)AXIS2_MALLOC(env->allocator, sizeof(guththila_namespace_t) * GUTHTHILA_NAMESPACE_DEF_SIZE);

	if (namesp_list->list && guththila_stack_init(&namesp_list->fr_stack, env)){
		namesp_list->capacity = GUTHTHILA_NAMESPACE_DEF_SIZE;
		namesp_list->size = 0;
		for (i = 0;i < GUTHTHILA_NAMESPACE_DEF_SIZE; i++){
			guththila_stack_push(&namesp_list->fr_stack, namesp_list->list + i, env);
		}
		return GUTHTHILA_SUCCESS;	
	}
	return GUTHTHILA_FAILURE;
}

guththila_namespace_t * GUTHTHILA_CALL guththila_namespace_list_get(guththila_namespace_list_t *namesp_list, const axutil_env_t *env)
{
	if (namesp_list->fr_stack.top > 0 || guththila_namespace_list_grow(namesp_list, GUTHTHILA_NAMESPACE_DEF_SIZE, env)){
		return guththila_stack_pop(&namesp_list->fr_stack, env);			
	} 	
	return NULL;
}
int GUTHTHILA_CALL guththila_namespace_list_release(guththila_namespace_list_t *namesp_list, guththila_namespace_t *namespace, const axutil_env_t *env)
{
	return guththila_stack_push(&namesp_list->fr_stack, namespace, env); 			
}

void GUTHTHILA_CALL msuila_namespace_list_free_data(guththila_namespace_list_t *namesp_list, const axutil_env_t *env)
{
	AXIS2_FREE(env->allocator, namesp_list->list);
	guththila_stack_un_init(&namesp_list->fr_stack, env);
}

void GUTHTHILA_CALL guththila_namespace_list_free(guththila_namespace_list_t *namesp_list, const axutil_env_t *env)
{
	AXIS2_FREE(env->allocator, namesp_list->list);
	guththila_stack_un_init(&namesp_list->fr_stack, env);
	AXIS2_FREE(env->allocator, namesp_list);
}

