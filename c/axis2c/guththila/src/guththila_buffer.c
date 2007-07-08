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
#include <stdlib.h>
#include <string.h>
#include <guththila_buffer.h>

int GUTHTHILA_CALL guththila_buffer_init(guththila_buffer_t *buffer, int size, const axutil_env_t *env)
{
	buffer->type = GUTHTHILA_MULTIPLE_BUFFER;

	buffer->data_size = (size_t *)AXIS2_MALLOC(env->allocator, sizeof(size_t) * GUTHTHILA_BUFFER_NUMBER_OF_BUFFERS);
	buffer->buffs_size = (size_t *)AXIS2_MALLOC(env->allocator, sizeof(size_t) * GUTHTHILA_BUFFER_NUMBER_OF_BUFFERS);
	buffer->buff = (char **)AXIS2_MALLOC(env->allocator, sizeof(char *) * GUTHTHILA_BUFFER_NUMBER_OF_BUFFERS);
	buffer->cur_buff = -1;
	buffer->pre_tot_data = 0;
	buffer->no_buffers = GUTHTHILA_BUFFER_NUMBER_OF_BUFFERS;
	if (size > 0 ){
		buffer->buff[0] = (guththila_char *)AXIS2_MALLOC(env->allocator, sizeof(guththila_char) * size);	
		buffer->data_size[0] = 0;
		buffer->buffs_size[0] = size;
		buffer->cur_buff = 0;
	}		
	return GUTHTHILA_SUCCESS;
}

int GUTHTHILA_CALL guththila_buffer_un_init(guththila_buffer_t *buffer, const axutil_env_t *env) 
{
	int i = 0;	
	if (buffer->type == GUTHTHILA_SINGLE_BUFFER && buffer->buff && buffer->cur_buff == 0) {
		if (buffer->buff[0]) AXIS2_FREE(env->allocator, buffer->buff[0]);
		if (buffer->buffs_size) AXIS2_FREE(env->allocator, buffer->buffs_size);
		if (buffer->data_size) AXIS2_FREE(env->allocator, buffer->data_size);
		AXIS2_FREE(env->allocator, buffer->buff);
	} else if (buffer->type == GUTHTHILA_MULTIPLE_BUFFER && buffer->buff){
		for (i = 0; i <= buffer->cur_buff; i++) {
			AXIS2_FREE(env->allocator, buffer->buff[i]);
		}
		AXIS2_FREE(env->allocator, buffer->buff);
		if (buffer->data_size) AXIS2_FREE(env->allocator, buffer->data_size);
		if (buffer->buffs_size) AXIS2_FREE(env->allocator, buffer->buffs_size);
	}
	return GUTHTHILA_SUCCESS;
}

int GUTHTHILA_CALL guththila_buffer_init_for_buffer(guththila_buffer_t *buffer, char *buff, int size, const axutil_env_t *env)
{
	buffer->type = GUTHTHILA_SINGLE_BUFFER;	

	buffer->buff = (char **)AXIS2_MALLOC(env->allocator, sizeof(char *) * GUTHTHILA_BUFFER_DEF_SIZE);
	buffer->buff[0] = buff;
	buffer->cur_buff = 0;
	buffer->buffs_size = (size_t *)AXIS2_MALLOC(env->allocator, sizeof(size_t) * GUTHTHILA_BUFFER_DEF_SIZE);
	buffer->buffs_size[0] = size;
	buffer->pre_tot_data = 0;
	buffer->data_size = (size_t *)AXIS2_MALLOC(env->allocator, sizeof(size_t) * GUTHTHILA_BUFFER_DEF_SIZE);
	buffer->data_size[0] = size;
	buffer->no_buffers = 1;
	return GUTHTHILA_SUCCESS;
}

void * GUTHTHILA_CALL guththila_buffer_get(guththila_buffer_t * buffer, const axutil_env_t *env)
{
	size_t size = 0, current_size = 0;
	int i = 0;
	char *buff = NULL;
	for (i = 0; i <= buffer->cur_buff; i++) {
		size += buffer->data_size[i];
	}
	buff = (char *) AXIS2_MALLOC(env->allocator, sizeof(char) * (size + 1));

	for (i = 0; i <= buffer->cur_buff; i++) {
		memcpy(buff + current_size, buffer->buff[i] , buffer->data_size[i]);
		current_size += buffer->data_size[i];
	}
	buff[current_size] = '\0';
	return buff;
}



