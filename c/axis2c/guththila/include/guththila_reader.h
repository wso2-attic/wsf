/*
 *   Copyright 2004,2005 The Apache Software Foundation.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *   
 */


#ifndef GUTHTHILA_READER_H
#define GUTHTHILA_READER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "guththila_buffer.h"
#include "guththila_defines.h"
#include <axutil_env.h>
#include "guththila_error.h"
#include <axutil_utils.h>

typedef enum guththila_reader_types
  {
    GUTHTHILA_FILE_READER = 1,
    GUTHTHILA_IO_READER,
    GUTHTHILA_MEMORY_READER
  } guththila_reader_types_t;

typedef struct guththila_reader_s
{
    int guththila_reader_type;
    
} guththila_reader_t;



typedef struct guththila_reader_impl_t
{
	guththila_reader_t reader;
	int buffer_size;
	FILE *fp;
	char *buffer;
	AXIS2_READ_INPUT_CALLBACK input_read_callback;
	void* context;
}guththila_reader_impl_t;


AXIS2_EXTERN guththila_reader_t * AXIS2_CALL
guththila_reader_create_for_file (axutil_env_t * environment,
                                  char* filename);

AXIS2_EXTERN guththila_reader_t * AXIS2_CALL 
guththila_reader_create_for_io(axutil_env_t *environment,
							   AXIS2_READ_INPUT_CALLBACK input_read_callback, void *ctx);

AXIS2_EXTERN guththila_reader_t * AXIS2_CALL
guththila_reader_create_for_memory(axutil_env_t *environment,
                                   void *buffer,
                                    int size,
				   void *ctx); 


AXIS2_EXTERN int AXIS2_CALL
guththila_reader_read (axutil_env_t * environment,
                       guththila_char_t * buffer, int offset, int length,
                       guththila_reader_t * r);

                       
AXIS2_EXTERN void AXIS2_CALL
guththila_reader_free (axutil_env_t * environment,
                       guththila_reader_t * r);

#endif /* GUTHTHILA_READER_H */
