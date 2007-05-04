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

#include "guththila_writer.h"


AXIS2_EXTERN guththila_writer_t * AXIS2_CALL
guththila_writer_create_for_file(axutil_env_t *env, char *fp)
{
    guththila_writer_impl_t *wt = NULL;
    if (!fp)
        return NULL;
    wt = (guththila_writer_impl_t *) AXIS2_MALLOC(env->allocator, sizeof(guththila_writer_impl_t));
    wt->outputstream = fopen(fp, "w");
    if (!wt->outputstream)
        return NULL;
    wt->writer.guththila_writer_type = GUTHTHILA_WRITER_FILE;
    return &(wt->writer);
}

AXIS2_EXTERN guththila_writer_t * AXIS2_CALL
guththila_writer_create_for_memory(axutil_env_t *env)
{
    guththila_writer_impl_t *wt = NULL;

    wt = (guththila_writer_impl_t *) AXIS2_MALLOC(env->allocator, 
												  sizeof(guththila_writer_impl_t));
    wt->outputstream = NULL;

    wt->buffer = guththila_buffer_create(env, GUTHTHILA_BUFFER_SIZE);

    if (!wt->buffer)
        return NULL;

    wt->writer.guththila_writer_type = GUTHTHILA_WRITER_MEMORY;
    return &(wt->writer);
}

AXIS2_EXTERN void AXIS2_CALL
guththila_writer_free(axutil_env_t *env, guththila_writer_t *wt)
{
    if (wt)
    {
		guththila_writer_impl_t *writer_impl = NULL;
		writer_impl = ((guththila_writer_impl_t *)wt);
        if (wt->guththila_writer_type == GUTHTHILA_WRITER_FILE)
        {
            if (writer_impl->outputstream)
                fclose(writer_impl->outputstream);
            writer_impl->outputstream = NULL;
        }
		else if (wt->guththila_writer_type ==  GUTHTHILA_WRITER_MEMORY)
		{
			guththila_buffer_free(env, writer_impl->buffer);
		}
        AXIS2_FREE(env->allocator, (guththila_writer_t *)wt);
        wt = NULL;
    }
}

AXIS2_EXTERN int AXIS2_CALL
guththila_writer_write(axutil_env_t *env,
					   char *buffer, int offset,
					   int length, guththila_writer_t *wt)
{
    int c = 0;
    guththila_writer_impl_t *writer_impl = NULL;

    if (wt->guththila_writer_type == GUTHTHILA_WRITER_FILE)
    {
        c = fwrite(buffer + offset, 1, length, ((guththila_writer_impl_t *)wt)->outputstream);
    }
    else if (wt->guththila_writer_type == GUTHTHILA_WRITER_MEMORY)
    {
        int size = 0;
/* 		int buffer_len = 0; */
/* 		buffer_len = strlen (buffer); */
        writer_impl = (guththila_writer_impl_t *)wt;

		 if (writer_impl->buffer->buff)
			 size = writer_impl->buffer->next;

		if (buffer)
		{
			memcpy (writer_impl->buffer->buff + size, buffer, length);
			writer_impl->buffer->next += length;
			c = length;
		}
    }
    return c;
}


AXIS2_EXTERN char * AXIS2_CALL
guththila_writer_get_buffer(axutil_env_t *env,
        guththila_writer_t *wt)
{
    guththila_writer_impl_t *writer_impl = NULL;
    writer_impl = (guththila_writer_impl_t *)wt;

    if (writer_impl->buffer->buff)
	{
        return (char *)writer_impl->buffer->buff;
	}
    else
        return (char *)NULL;
}

AXIS2_EXTERN unsigned int AXIS2_CALL
guththila_writer_get_buffer_size (axutil_env_t *env,
								  guththila_writer_t *wt)
{
	guththila_writer_impl_t *writer_impl = NULL;
	unsigned int size = 0;
	writer_impl = (guththila_writer_impl_t *)wt;

	if (writer_impl->buffer->buff)
		size = (unsigned int) writer_impl->buffer->next;
	return size;
}
