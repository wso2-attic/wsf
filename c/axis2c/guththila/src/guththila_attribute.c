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
#include <guththila_attribute.h>
#include <guththila_stack.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GUTHTHILA_CALL guththila_attr_list_grow(guththila_attr_list_t *at_list, int addition, const axutil_env_t *env)
{
	int  i = 0;
	if (addition > 0 || (addition < 0 && at_list->capacity + addition > 0 && at_list->capacity + addition >= at_list->size)) {
		at_list->list = (guththila_attr_t *)realloc(at_list->list, sizeof(guththila_attr_t) * (at_list->capacity + addition));
		if (at_list->list){			
			for (i = at_list->capacity; i < at_list->capacity + addition; i++){
				guththila_stack_push(&at_list->fr_stack, at_list->list + i, env);
			}
			at_list->capacity += addition;
		} else {
			return GUTHTHILA_FAILURE;
		}
	}
	return 0;
}

guththila_attr_list_t * GUTHTHILA_CALL guththila_attr_list_create(const axutil_env_t *env)
{
	int i = 0;
	guththila_attr_list_t *at_list = (guththila_attr_list_t *) AXIS2_MALLOC(env->allocator, sizeof(guththila_attr_list_t));
	if (!at_list) return NULL;

	at_list->list = (guththila_attr_t *)AXIS2_MALLOC(env->allocator, sizeof(guththila_attr_t) * GUTHTHILA_ATTR_DEF_SIZE);

	if (at_list->list && guththila_stack_init(&at_list->fr_stack, env))
    {
		at_list->capacity = GUTHTHILA_ATTR_DEF_SIZE;
		at_list->size = 0;
		for (i = 0;i < GUTHTHILA_ATTR_DEF_SIZE; i++){
			guththila_stack_push(&at_list->fr_stack, at_list->list + i, env);
		}
		return at_list;	
	}
	return NULL;
}

int GUTHTHILA_CALL guththila_attr_list_init(guththila_attr_list_t *at_list, const axutil_env_t *env)
{
	int i = 0;	
	at_list->list = (guththila_attr_t *)AXIS2_MALLOC(env->allocator, sizeof(guththila_attr_t) * GUTHTHILA_ATTR_DEF_SIZE);

	if (at_list->list && guththila_stack_init(&at_list->fr_stack, env))
    {
		at_list->capacity = GUTHTHILA_ATTR_DEF_SIZE;
		at_list->size = 0;
		for (i = 0;i < GUTHTHILA_ATTR_DEF_SIZE; i++){
			guththila_stack_push(&at_list->fr_stack, at_list->list + i, env);
		}
		return GUTHTHILA_SUCCESS;	
	}
	return GUTHTHILA_FAILURE;
}

guththila_attr_t * GUTHTHILA_CALL guththila_attr_list_get(guththila_attr_list_t *at_list, const axutil_env_t *env)
{
	if (at_list->fr_stack.top > 0 || guththila_attr_list_grow(at_list, GUTHTHILA_ATTR_DEF_SIZE, env)){
		return guththila_stack_pop(&at_list->fr_stack, env);			
	} 	
	return NULL;
}
int GUTHTHILA_CALL guththila_attr_list_release(guththila_attr_list_t *at_list, guththila_attr_t *attr, const axutil_env_t *env)
{
	return guththila_stack_push(&at_list->fr_stack, attr, env); 			
}

void GUTHTHILA_CALL msuila_attr_list_free_data(guththila_attr_list_t *at_list, const axutil_env_t *env)
{
	AXIS2_FREE(env->allocator, at_list->list);
	guththila_stack_un_init(&at_list->fr_stack, env);
}

void GUTHTHILA_CALL guththila_attr_list_free(guththila_attr_list_t *at_list, const axutil_env_t *env)
{
	AXIS2_FREE(env->allocator, at_list->list);
	guththila_stack_un_init(&at_list->fr_stack, env);
	AXIS2_FREE(env->allocator, at_list);
}

