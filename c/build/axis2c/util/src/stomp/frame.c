#include <stdlib.h>
#include <strings.h>
#include <stdio.h>
#include <axutil_stomp_frame.h>

#define BUFF_SIZE 1024

#define MEM_ZERO(s) memset((void *)s, 0, sizeof (s))

static axis2_char_t *read_stomp_buffer(
    const axutil_env_t * env,
    axutil_stream_t * stream);

axutil_stomp_frame_t *
axutil_stomp_frame_create(
    const axutil_env_t * env)
{
    axutil_stomp_frame_t *frame = NULL;
    frame = AXIS2_MALLOC(env->allocator, sizeof(axutil_stomp_frame_t));
    memset((void *)frame, 0, sizeof (axutil_stomp_frame_t));
    frame->headers = axutil_array_list_create(env, 3);
    return frame;
}

void
axutil_stomp_frame_free(
    axutil_stomp_frame_t *frame,
    const axutil_env_t * env)
{
    void *headers;
    int i;
    int size;
    i = 0;
    size = 0;

    if (!frame)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[stomp]Frame is NULL");
        return;
    }

    if (frame->command)
    {
        AXIS2_FREE(env->allocator, frame->command);
    }

    if (frame->body)
    {
        AXIS2_FREE(env->allocator, frame->body);
    }

    size = axutil_array_list_size(frame->headers, env);

    if (size > 0)
    {
        for (i = 0; i < size; i++)
        {
            headers = axutil_array_list_remove(frame->headers, env, (size - i));
            AXIS2_FREE(env->allocator, headers);
        }
    }
    axutil_array_list_free(frame->headers, env);
    AXIS2_FREE(env->allocator, frame);
}

axis2_status_t
axutil_stomp_frame_set_command(
    axutil_stomp_frame_t * frame,
    const axutil_env_t * env,
    axis2_char_t * command)
{
    AXIS2_PARAM_CHECK(env->error, frame, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, command, AXIS2_FAILURE);
    frame->command = command;
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[stomp]%s stomp command is set",
                    command);
    return AXIS2_SUCCESS;
}

axis2_status_t
axutil_stomp_frame_set_header(
    axutil_stomp_frame_t * frame,
    const axutil_env_t * env,
    axis2_char_t * header,
    axis2_char_t * value)
{
    axis2_char_t *stomp_header = NULL;

    AXIS2_PARAM_CHECK(env->error, frame, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, header, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, value, AXIS2_FAILURE);

    stomp_header = axutil_strcat(env, header, ":", value, NULL);
    axutil_array_list_add(frame->headers, env, (void *) stomp_header);
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
                    "[stomp] %s stomp header is set, value is %s", header,
                    value);
    return AXIS2_SUCCESS;
}

axis2_status_t
axutil_stomp_frame_set_body(
    axutil_stomp_frame_t * frame,
    const axutil_env_t * env,
    axis2_char_t * body)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, frame, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, body, AXIS2_FAILURE);
    frame->body = body;
    if (body)
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "set stomp body length %d", strlen (body));
    }
    return AXIS2_SUCCESS;
}

int
axutil_stomp_frame_write(
    axutil_stomp_frame_t * frame,
    const axutil_env_t * env,
    axutil_stream_t * stream)
{
    int total = 0;

    /* headers */
    int size = 0;
    int i = 0;
    axis2_char_t *header = NULL;
    int len = 0;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, frame, AXIS2_FAILURE);

    /* command */
    if (frame->command)
    {
        len = strlen (frame->command);
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "%s stomp command length %d", frame->command, len);
    }

    total += axutil_stream_write(stream, env, frame->command, len);
    total += axutil_stream_write(stream, env, "\n", 1);

    size = axutil_array_list_size(frame->headers, env);
    if (size > 0)
    {
        for (i = 0; i < size; i++)
        {
            header =
                (axis2_char_t *) axutil_array_list_get(frame->headers, env, i);
            if (header)
            {
                len = 0;
                len = strlen (header);
            }

            total += axutil_stream_write(stream, env, header, len);
            total += axutil_stream_write(stream, env, "\n", 1);
        }
    }
    total += axutil_stream_write(stream, env, "\n", 1);

    /* body */
    if (frame->body)
    {
        len = 0;
        len = strlen (frame->body);
        total +=
            axutil_stream_write(stream, env, frame->body, len);
    }
    total += axutil_stream_write(stream, env, "\0\n", 2);
    axutil_stream_flush (stream, env);
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
                    "[stomp]stomp frame is write to stream %d of total bytes",
                    total);
    return total;
}

axis2_char_t *
read_stomp_buffer(
    const axutil_env_t * env,
    axutil_stream_t * stream)
{
    int size = BUFF_SIZE;
    axis2_char_t *tmp_buffer =
        (axis2_char_t *) AXIS2_MALLOC(env->allocator, (size_t) size);
    axis2_char_t buff[1];
    axis2_char_t end[1];
    int i = 0;
    int len = 0;

    memset((void *) tmp_buffer, 0, (size_t) size);
    if (!stream)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                        "[stomp]stream is NULL");
        return tmp_buffer;
    }

    while (1)
    {
        len = axutil_stream_read(stream, env, &buff, 1);
        if (len > 0)
        {
            if (i >= size)
            {
                axis2_char_t *new_buffer =
                    (axis2_char_t *) AXIS2_MALLOC(env->allocator,
                                                  (size_t) size);
                size <<= 2;
                memcpy(new_buffer, tmp_buffer, (size_t) size);
                AXIS2_FREE(env->allocator, tmp_buffer);
                tmp_buffer = new_buffer;
            }
            memcpy(tmp_buffer + i, buff, 1);
            i++;

            if (tmp_buffer[i - 1] == 0)
            {
                len = axutil_stream_read(stream, env, &end, 1);
                if (end[0] != '\n')
                {
                    return NULL;
                }
                break;
            }
        }
        else
            return NULL;

    }
    return tmp_buffer;
}

axutil_stomp_frame_t *
axutil_stomp_frame_read(
    const axutil_env_t * env,
    axutil_stream_t * stream)
{
    axutil_stomp_frame_t *frame = NULL;
    axis2_char_t *buffer = NULL;
    axis2_char_t *p = NULL;
    int h;

    frame = axutil_stomp_frame_create(env);
    buffer = read_stomp_buffer(env, stream);

    if (!buffer)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                        "[stomp]read buffer is empty");
        return frame;
    }

    p = strstr(buffer, "\n");
    h = p - buffer;
    if (!p)
    {
        axutil_stomp_frame_free(frame, env);
        if (buffer)
        {
            AXIS2_FREE(env->allocator, buffer);
        }
        return NULL;
    }
    *p = 0;
    if (buffer)
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
                        "[stomp]read command %s", buffer);
    }
    frame->command = buffer;

    buffer = p + 1;
    while (h)
    {
        p = strstr(buffer, "\n");
        h = p - buffer;
        *p = 0;
        if (buffer)
        {
            AXIS2_LOG_DEBUG(env->log, 
                            AXIS2_LOG_SI, 
                            "[stomp]read header %s", buffer);
            axutil_array_list_add(frame->headers, env, (void *) buffer);
        }
        buffer = p + 1;
    }

    if (buffer)
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
                        "[stomp]read body %d length message", 
                        strlen (buffer));
    }
    frame->body = buffer;
    return frame;
}


void
axutil_stomp_frame_reset (axutil_stomp_frame_t *frame,
                          const axutil_env_t *env)
{
    int i = 0;
    int size = 0;
    axis2_char_t *header = NULL;

    if (!frame)
    {
        return;
    }

    if (frame->command)
    {
/*         AXIS2_FREE (env->allocator, frame->command); */
        frame->command = NULL;
    }

    if (frame->body)
    {
/*         AXIS2_FREE (env->allocator, frame->body); */
        frame->body = NULL;
    }

    if (frame->headers)
    {
        size = axutil_array_list_size(frame->headers, env);
        if (size > 0)
        {
            for (i = 0; i < size; i++)
            {
                header =
                    (axis2_char_t *) axutil_array_list_remove(frame->headers, env, 0);
                if (header)
                {
/*                     AXIS2_FREE (env->allocator, header); */
                    header = NULL;
         
                }
            }
        }
    }
}
