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


#include "guththila_reader.h"
#include "guththila_defines.h"





AXIS2_EXTERN guththila_reader_t * AXIS2_CALL
guththila_reader_create_for_file(axutil_env_t * environment,
        char *filename)
{
    guththila_reader_impl_t *file_reader = NULL;
    if (!filename)
        return NULL;

    file_reader = (guththila_reader_impl_t *) AXIS2_MALLOC(environment->allocator,
            sizeof(guththila_reader_impl_t));
    if (!file_reader)
        return NULL;

    file_reader->fp  = fopen(filename, "r");

    if (!(file_reader->fp))
    {
        AXIS2_FREE(environment->allocator, file_reader);
        return NULL;
    }

    file_reader->reader.guththila_reader_type = GUTHTHILA_FILE_READER;

    return &(file_reader->reader);
}


AXIS2_EXTERN guththila_reader_t * AXIS2_CALL
guththila_reader_create_for_io(
    axutil_env_t *environment,
    AXIS2_READ_INPUT_CALLBACK input_read_callback, void* ctx)
{
    guththila_reader_impl_t *io_reader =
        (guththila_reader_impl_t *) AXIS2_MALLOC(environment->allocator,
                sizeof(guththila_reader_impl_t));
    if (!io_reader)
    {
        return NULL;
    }

    io_reader->input_read_callback  = input_read_callback;
    io_reader->context = ctx;
    io_reader->reader.guththila_reader_type = GUTHTHILA_IO_READER;

    return &(io_reader->reader);
}

AXIS2_EXTERN guththila_reader_t * AXIS2_CALL
guththila_reader_create_for_memory(
    axutil_env_t *environment,
    void *buffer,
    int size,
    void* ctx)
{
    guththila_reader_impl_t *memory_reader =
        (guththila_reader_impl_t *) AXIS2_MALLOC(environment->allocator,
                sizeof(guththila_reader_impl_t));
    if (!memory_reader)
    {
        return NULL;
    }

    if (buffer)
    {
        memory_reader->buffer  = (char *)buffer;
        memory_reader->buffer_size =  strlen((const char *) buffer);
    }
    memory_reader->context = ctx;
    memory_reader->reader.guththila_reader_type = GUTHTHILA_MEMORY_READER;

    return &(memory_reader->reader);
}

AXIS2_EXTERN void AXIS2_CALL
guththila_reader_free(axutil_env_t * environment,
        guththila_reader_t * r)
{

    if (!r)
        return;

    if (r->guththila_reader_type == GUTHTHILA_FILE_READER)
    {
        if (((guththila_reader_impl_t*)r)->fp)
            fclose(((guththila_reader_impl_t*)r)->fp);
    }
    AXIS2_FREE(environment->allocator, (guththila_reader_impl_t*)r);
    return;
}


AXIS2_EXTERN int AXIS2_CALL
guththila_reader_read(axutil_env_t * environment,
        guththila_char_t * buffer,
        int offset,
        int length,
        guththila_reader_t * r)
{

    if (r->guththila_reader_type == GUTHTHILA_FILE_READER)
    {
        return (int)fread(buffer + offset, 1, length, ((guththila_reader_impl_t*)r)->fp);
    }
    else if (r->guththila_reader_type == GUTHTHILA_IO_READER)
        return ((guththila_reader_impl_t*)r)->input_read_callback((buffer + offset), length,
                ((guththila_reader_impl_t*)r)->context);
    else if (r->guththila_reader_type == GUTHTHILA_MEMORY_READER)
    {
        return ((guththila_reader_impl_t *)r)->buffer_size;
    }

    return GUTHTHILA_FAILURE;
}
