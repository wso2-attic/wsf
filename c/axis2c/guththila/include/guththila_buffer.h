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


#ifndef GUTHTHILA_BUFFER_H
#define GUTHTHILA_BUFFER_H

#include <stdlib.h>
/* #include "guththila_environment.h" */
#include "guththila_defines.h"
#include <axutil_env.h>

typedef struct guththila_buffer_s
{
  int size;
  int next;
  int last;
  int offset;
  int is_memory;
  guththila_char_t *buff;
} guththila_buffer_t;

#define GUTHTHILA_BUFFER_SIZE 1024

AXIS2_EXTERN guththila_buffer_t * AXIS2_CALL
guththila_buffer_create (axutil_env_t * environment, int size);

AXIS2_EXTERN guththila_buffer_t *
guththila_buffer_create_for_buffer (axutil_env_t * environment, char *buffer, int size);

AXIS2_EXTERN void
guththila_buffer_free (axutil_env_t * environment,
                       guththila_buffer_t * name);

AXIS2_EXTERN guththila_buffer_t *
guththila_buffer_grow (axutil_env_t * environment,
                       guththila_buffer_t * name,
					   int buffer_length);

#endif /* GUTHTHILA_BUFFER_H */
