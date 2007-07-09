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
#ifndef GUTHTHILA_READER_H
#define GUTHTHILA_READER_H

#include <stdio.h>
#include <guththila_defines.h>
#include <axutil_utils.h>

EXTERN_C_START()

typedef int (GUTHTHILA_CALL *GUTHTHILA_READ_INPUT_CALLBACK)(char *buffer, int size, 
    void* ctx);

enum guththila_reader_type
{
	GUTHTHILA_FILE_READER = 1,
    GUTHTHILA_IO_READER,
    GUTHTHILA_MEMORY_READER
};

typedef struct guththila_reader_s
{
	int type;
	FILE *fp;
	int last_start; /*if -1 we are not in a token*/
	char *buff;
	int buff_size;
	GUTHTHILA_READ_INPUT_CALLBACK input_read_callback;
	void* context;	
} guththila_reader_t;

#ifndef GUTHTHILA_READER_SET_LAST_START
#define GUTHTHILA_READER_SET_LAST_START(_reader, _start) ((_reader)->start = _start)
#endif

#ifndef GUTHTHILA_READER_STEP_BACK
#define GUTHTHILA_READER_STEP_BACK(_reader) ((_reader->next--))
#endif

GUTHTHILA_EXPORT guththila_reader_t * GUTHTHILA_CALL
guththila_reader_create_for_file (char* filename, const axutil_env_t *env);

GUTHTHILA_EXPORT guththila_reader_t * GUTHTHILA_CALL 
guththila_reader_create_for_io(GUTHTHILA_READ_INPUT_CALLBACK input_read_callback, void *ctx, const axutil_env_t *env);

GUTHTHILA_EXPORT guththila_reader_t * GUTHTHILA_CALL
guththila_reader_create_for_memory(void *buffer, int size, const axutil_env_t *env); 

GUTHTHILA_EXPORT int GUTHTHILA_CALL
guththila_reader_read (guththila_reader_t *r, guththila_char *buffer, int offset, int length, const axutil_env_t *env);
                       
GUTHTHILA_EXPORT void GUTHTHILA_CALL
guththila_reader_free (guththila_reader_t * r, const axutil_env_t *env);

EXTERN_C_END()

#endif

