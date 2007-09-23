#include <stdlib.h>
#include <strings.h>
#include <stdio.h>
#include <axutil_stomp_frame.h>

#define BUFF_SIZE 1024

static axis2_char_t *
read_stomp_buffer (
    const axutil_env_t *env,
    axutil_stream_t *stream);


axutil_stomp_frame_t *
axutil_stomp_frame_create (const axutil_env_t *env)
{
    AXIS2_ENV_CHECK (env, NULL);
    axutil_stomp_frame_t *frame = NULL;
    frame = AXIS2_MALLOC (env->allocator, sizeof (axutil_stomp_frame_t));
    frame->command = NULL;
    frame->headers = axutil_array_list_create (env, 3);
    frame->body = NULL;
    return frame;
}


void
axutil_stomp_frame_free (axutil_stomp_frame_t *frame,
    const axutil_env_t *env)
{
    if (!frame)
        return;

    int size = 0;
    int i = 0;
    void *headers;
    if (frame->command)
        AXIS2_FREE (env->allocator, frame->command);

    if (frame->body)
        AXIS2_FREE (env->allocator, frame->body);

    size = axutil_array_list_size (frame->headers, env);

    if (size > 0)
    {
        for (i = 0; i < size; i++)
        {
            headers = axutil_array_list_get (frame->headers, env, i);
            AXIS2_FREE (env->allocator, headers);
        }
    }
    axutil_array_list_free (frame->headers, env);

    AXIS2_FREE (env->allocator, frame);
}


axis2_status_t
axutil_stomp_frame_set_command (axutil_stomp_frame_t *frame,
    const axutil_env_t *env,
    axis2_char_t *command)
{
    AXIS2_ENV_CHECK (env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK (env->error, frame, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK (env->error, command, AXIS2_FAILURE);
    frame->command = command;
    AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, "%s stomp command is set", command);
    return AXIS2_SUCCESS;
}


axis2_status_t
axutil_stomp_frame_set_header (axutil_stomp_frame_t *frame,
    const axutil_env_t *env,
    axis2_char_t *header,
    axis2_char_t *value)
{
    AXIS2_ENV_CHECK (env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK (env->error, frame, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK (env->error, header, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK (env->error, value, AXIS2_FAILURE);

    axis2_char_t *stomp_header = NULL;
    stomp_header = axutil_strcat (env, header, ":", value, NULL);
    axutil_array_list_add (frame->headers, env, (void *)stomp_header);
    AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, 
        "%s stomp header is set, value is %s", header, value);
    return AXIS2_SUCCESS;
}


axis2_status_t 
axutil_stomp_frame_set_body (axutil_stomp_frame_t *frame,
    const axutil_env_t *env,
    axis2_char_t *body)
{
    AXIS2_ENV_CHECK (env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK (env->error, frame, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK (env->error, body, AXIS2_FAILURE);
    frame->body = body;
    AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, "%s stomp body is set", body);
    return AXIS2_SUCCESS;
}

int
axutil_stomp_frame_write (axutil_stomp_frame_t *frame,
    const axutil_env_t *env,
    axutil_stream_t *stream)
{
    AXIS2_ENV_CHECK (env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK (env->error, frame, AXIS2_FAILURE);
    int total = 0;
    /* command */
    total += axutil_stream_write (stream, env, frame->command, strlen (frame->command));
    total += axutil_stream_write (stream, env, "\n", 1);

    /* headers */
    int size = 0;
    int i = 0;
    axis2_char_t *header = NULL;
    size = axutil_array_list_size (frame->headers, env);
    if (size > 0)
    {
        for (i = 0; i < size; i++)
        {
            header = (axis2_char_t *) axutil_array_list_get (frame->headers, env, i);
                total += axutil_stream_write (stream, env, header, strlen (header));
                total += axutil_stream_write (stream, env, "\n", 1);
        }
    }
    total += axutil_stream_write (stream, env, "\n", 1);

    /* body */
    if (frame->body)
    {
        total += axutil_stream_write (stream, env, frame->body, strlen (frame->body));
    }
    total += axutil_stream_write (stream, env, "\0\n", 2);
    AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, 
                     "stomp frame is write to stream %d of total bytes", total);
    return total;
}


axis2_char_t *
read_stomp_buffer (const axutil_env_t *env,
    axutil_stream_t *stream)
{
    int size = BUFF_SIZE;
    axis2_char_t *tmp_buffer = (axis2_char_t *)AXIS2_MALLOC (env->allocator, size);
    axis2_char_t buff [1];
    axis2_char_t end[1];
    int i = 0;
    int len = 0;

    while (1)
    {
        len = axutil_stream_read (stream, env, &buff, 1);
        if (len > 0)
        {
            if (i >= size)
            {
                size <<= 2;
                axis2_char_t *new_buffer = (axis2_char_t *)AXIS2_MALLOC (env->allocator, size);
                memcpy (new_buffer, tmp_buffer, size);
                AXIS2_FREE (env->allocator, tmp_buffer);
                tmp_buffer = new_buffer;
            }
            memcpy (tmp_buffer + i, buff, 1);
            i++;

            if (tmp_buffer[i-1] == 0)
            {
                len = axutil_stream_read (stream, env, &end, 1);
                if (end [0] != '\n')
                {
                    return AXIS2_FAILURE;
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
axutil_stomp_frame_read (const axutil_env_t *env,
    axutil_stream_t *stream)
{
    axutil_stomp_frame_t *frame = NULL;
    axis2_char_t *buffer = NULL;
    axis2_char_t *p = NULL;
    int h;

    frame = axutil_stomp_frame_create (env);
    buffer = read_stomp_buffer (env, stream);
    p = strstr (buffer, "\n");
    h = p - buffer;
    if (!p)
    {
        return NULL;
    }
    *p = 0;
    frame->command = buffer;

    buffer = p + 1;
    while (h)
    {
        p = strstr (buffer, "\n");
        h = p - buffer;
        *p = 0;
        axutil_array_list_add (frame->headers, env, (void *)buffer);
        buffer = p + 1;
    }

    frame->body = buffer;
    return frame;
}
