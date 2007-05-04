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

#ifndef GUTHTHILA_WRITER_H
#define GUTHTHILA_WRITER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "guththila_buffer.h"
#include <axutil_env.h>
#include "guththila_defines.h"
#include "guththila_error.h"

typedef enum guththila_writer_types
  {
    GUTHTHILA_WRITER_FILE = 1,
    GUTHTHILA_WRITER_MEMORY
  }guththila_writer_types_t;

typedef struct guththila_writer_s
{
  int guththila_writer_type;  
}guththila_writer_t;

typedef struct guththila_writer_impl_t
{
  guththila_writer_t writer;
  FILE *outputstream;
  guththila_buffer_t *buffer;
}guththila_writer_impl_t; 

AXIS2_EXTERN guththila_writer_t* AXIS2_CALL
guththila_writer_create_for_file(axutil_env_t *env, 
    char *fp);

AXIS2_EXTERN guththila_writer_t* AXIS2_CALL
guththila_writer_create_for_memory (axutil_env_t *env);


AXIS2_EXTERN int AXIS2_CALL
guththila_writer_write(axutil_env_t *env, 
		       char *buffer, 
		       int offset, 
		       int length, 
		       guththila_writer_t *wt);


AXIS2_EXTERN void AXIS2_CALL
guththila_writer_free (axutil_env_t *env, 
		       guththila_writer_t *wt);

AXIS2_EXTERN char * AXIS2_CALL
guththila_writer_get_buffer (axutil_env_t *env, 
		       guththila_writer_t *wt);

AXIS2_EXTERN unsigned int AXIS2_CALL
guththila_writer_get_buffer_size (axutil_env_t *env,
								  guththila_writer_t *wt);

#endif	/* GUTHTHILA_WRITE_H */



