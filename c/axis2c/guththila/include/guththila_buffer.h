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
#ifndef GUTHTHILA_BUFFER_H
#define GUTHTHILA_BUFFER_H

#include <guththila_defines.h>
#include <axutil_utils.h>

EXTERN_C_START()

typedef enum guththila_buffer_type {	
	GUTHTHILA_SINGLE_BUFFER = 0,	
	GUTHTHILA_MULTIPLE_BUFFER
} guththila_buffer_type_t;

typedef struct guththila_buffer_s
{
    /* Required to manupulate multiple buffers*/
    size_t *data_size;
	size_t *buffs_size;
	char **buff;
	int cur_buff;
	int cur_buff_pos;
	size_t pre_tot_data;
	unsigned int no_buffers;
	short type;
} guththila_buffer_t;

#define GUTHTHILA_BUFFER_DEF_SIZE 4096
#define GUTHTHILA_BUFFER_NUMBER_OF_BUFFERS 4

#ifndef GUTHTHILA_BUFFER_SIZE
#define GUTHTHILA_BUFFER_SIZE(_buffer) (_buffer.size)
#endif

#ifndef GUTHTHILA_BUFFER_CURRENT_BUFF
#define GUTHTHILA_BUFFER_CURRENT_BUFF(_buffer) ((_buffer).buff[(_buffer).cur_buff] + (_buffer).data_size[(_buffer).cur_buff])
#endif

#ifndef GUTHTHILA_BUFFER_CURRENT_BUFF_SIZE
#define GUTHTHILA_BUFFER_CURRENT_BUFF_SIZE(_buffer) ((_buffer).buffs_size[(_buffer).cur_buff] - (_buffer).data_size[(_buffer).cur_buff])
#endif

#ifndef GUTHTHILA_BUFFER_CURRENT_DATA_SIZE
#define GUTHTHILA_BUFFER_CURRENT_DATA_SIZE(_buffer) ((_buffer).data_size[(_buffer).cur_buff])
#endif

#ifndef GUTHTHILA_BUFFER_PRE_DATA_SIZE
#define GUTHTHILA_BUFFER_PRE_DATA_SIZE(_buffer) ((_buffer).pre_tot_data)
#endif

/*We never consider tokens not in the current buffer*/
#ifndef GUTHTHILA_BUF_POS
#define GUTHTHILA_BUF_POS(_buffer, _pos) ((_buffer).buff[(_buffer).cur_buff] + _pos - (_buffer).pre_tot_data)
#endif 

int GUTHTHILA_CALL guththila_buffer_init(guththila_buffer_t *buffer, int size, const axutil_env_t *env);
int GUTHTHILA_CALL guththila_buffer_un_init(guththila_buffer_t *buffer, const axutil_env_t *env); 
int GUTHTHILA_CALL guththila_buffer_init_for_buffer (guththila_buffer_t *mu_buff, char *buffer, int size, const axutil_env_t *env);

void * GUTHTHILA_CALL guththila_get_position(guththila_buffer_t *buffer, int pos, const axutil_env_t *env);

int GUTHTHILA_CALL guththila_buffer_next(guththila_buffer_t * buffer, const axutil_env_t *env);
void * GUTHTHILA_CALL guththila_buffer_get(guththila_buffer_t * buffer, const axutil_env_t *env);
int GUTHTHILA_CALL guththila_buffer_shift(guththila_buffer_t * buffer, int no, const axutil_env_t *env);
int GUTHTHILA_CALL guththila_buffer_insert_data (guththila_buffer_t * buffer, void *buff, size_t buff_len, const axutil_env_t *env);

EXTERN_C_END()
#endif 

