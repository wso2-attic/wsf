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

#include <string.h>
#include <stdlib.h>
#include "axis2_iis_stream.h"
#include <httpext.h>

/**
 * @brief Stream struct impl
 * Streaming mechanisms for iis web server
 */

typedef struct iis_stream_impl
{
    axutil_stream_t stream;
    axutil_stream_type_t stream_type;
    LPEXTENSION_CONTROL_BLOCK lpECB;
	unsigned int cur_pos;
	void *cur_position;
}
iis_stream_impl_t;


#define AXIS2_INTF_TO_IMPL(stream) ((iis_stream_impl_t *)(stream))

axutil_stream_type_t AXIS2_CALL
iis_stream_get_type(
    axutil_stream_t *stream,
    const axutil_env_t *env);

int AXIS2_CALL
iis_stream_write(
    axutil_stream_t *stream,
    const axutil_env_t *env,
    const void *buffer,
    size_t count);

int AXIS2_CALL
iis_stream_read(
    axutil_stream_t *stream,
    const axutil_env_t *env,
    void *buffer,
    size_t count);

int AXIS2_CALL
iis_stream_skip(
    axutil_stream_t *stream,
    const axutil_env_t *env,
    int count);

int AXIS2_CALL
iis_stream_get_char(
    axutil_stream_t *stream,
    const axutil_env_t *env);


axutil_stream_t * AXIS2_CALL
axutil_stream_create_iis(
    const axutil_env_t *env,
    LPEXTENSION_CONTROL_BLOCK lpECB)
{
    iis_stream_impl_t *stream_impl = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, lpECB, NULL);

    stream_impl = (iis_stream_impl_t *)AXIS2_MALLOC(
                env->allocator, sizeof(iis_stream_impl_t));

    if (! stream_impl)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
	stream_impl->cur_pos = 0;
	stream_impl->cur_position = NULL;
    stream_impl->lpECB = lpECB;
    stream_impl->stream_type = AXIS2_STREAM_MANAGED;

    axutil_stream_set_read(&(stream_impl->stream), env, iis_stream_read);
    axutil_stream_set_write(&(stream_impl->stream), env, iis_stream_write);
    axutil_stream_set_skip(&(stream_impl->stream), env, iis_stream_skip);

    return &(stream_impl->stream);
}

int AXIS2_CALL
iis_stream_read(
    axutil_stream_t *stream,
    const axutil_env_t *env,
    void *buffer,
    size_t count)
{
	void *temp_buff = NULL;
	unsigned int data_to_read = 0;
	int i = 0;
	DWORD ret_val = TRUE;
	DWORD read_bytes = (DWORD)count;
    iis_stream_impl_t *stream_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_CRITICAL_FAILURE);
    stream_impl = (iis_stream_impl_t *)stream;

	if (stream_impl->cur_pos == 0)
		stream_impl->cur_position = stream_impl->lpECB->lpbData;

	// If this is the case all the bytes are in the lpECB->lpbData buffer
	if (stream_impl->lpECB->cbAvailable == stream_impl->lpECB->cbTotalBytes)
	{	
		// Cannot read more than in the buffer.
		if (count + stream_impl->cur_pos <= stream_impl->lpECB->cbAvailable)
			data_to_read = (unsigned)count;
		else
			data_to_read = stream_impl->lpECB->cbAvailable - stream_impl->cur_pos;

		memcpy(buffer, stream_impl->cur_position, data_to_read);
		(char *)stream_impl->cur_position += data_to_read;
		stream_impl->cur_pos += data_to_read;
		read_bytes = data_to_read;
	}
	else if (stream_impl->lpECB->cbAvailable == -1)
	{
		ret_val = stream_impl->lpECB->ReadClient(stream_impl->lpECB->ConnID, buffer, &read_bytes);		
	}
	else if (stream_impl->lpECB->cbAvailable < stream_impl->lpECB->cbTotalBytes)
	{
		if (stream_impl->cur_pos > stream_impl->lpECB->cbAvailable)
		{
			ret_val = stream_impl->lpECB->ReadClient(stream_impl->lpECB->ConnID, buffer, &read_bytes);		
		} 
		else if (stream_impl->cur_pos + count > stream_impl->lpECB->cbAvailable && stream_impl->cur_pos < stream_impl->lpECB->cbAvailable) 
		{
			data_to_read = stream_impl->lpECB->cbAvailable - stream_impl->cur_pos;		
			memcpy(buffer, stream_impl->cur_position, data_to_read);
			
			read_bytes = stream_impl->cur_pos + count - stream_impl->lpECB->cbAvailable;			
			temp_buff = malloc(read_bytes);
			
			if (temp_buff == NULL) return data_to_read;

			ret_val = stream_impl->lpECB->ReadClient(stream_impl->lpECB->ConnID, temp_buff, &read_bytes);					
			memcpy(((char *)buffer + data_to_read + 1), temp_buff, read_bytes);
			read_bytes += data_to_read;
		}
		else 
		{									
			memcpy(buffer, stream_impl->cur_position, count);
			(char *)stream_impl->cur_position += count;
			stream_impl->cur_pos += (unsigned)count;
			read_bytes = (int)count;	
		}
	}
	if (ret_val == TRUE)
		return read_bytes;
	else
		return -1;
}

int AXIS2_CALL
iis_stream_write(
    axutil_stream_t *stream,
    const axutil_env_t *env,
    const void *buf,
    size_t count)
{
	DWORD ret_val = NO_ERROR;
	unsigned bytes_sent = 0;
    iis_stream_impl_t *stream_impl = NULL;
    axis2_char_t *buffer = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_CRITICAL_FAILURE);
    AXIS2_PARAM_CHECK(env->error, buf, AXIS2_FAILURE);
    stream_impl = AXIS2_INTF_TO_IMPL(stream);
    buffer = (axis2_char_t*)buf;
	bytes_sent = (unsigned)strlen(buffer);
    if (count <= 0)
    {
        return (int)count;
    }
    /* assume that buffer is not null terminated */
    ret_val = stream_impl->lpECB->WriteClient(stream_impl->lpECB->ConnID, buffer, &bytes_sent, HSE_IO_SYNC); 
	if (ret_val == TRUE)
		return bytes_sent;
	else
		return -1;
}

int AXIS2_CALL
iis_stream_skip(
    axutil_stream_t *stream,
    const axutil_env_t *env,
    int count)
{
	DWORD ret_val = TRUE;	
    iis_stream_impl_t *stream_impl = NULL;
   	void *temp_buff = NULL;
	int data_to_read = 0;
	int i = 0;	
	DWORD read_bytes = (DWORD)count;
	AXIS2_ENV_CHECK(env, AXIS2_CRITICAL_FAILURE);
	stream_impl = (iis_stream_impl_t *)stream;

    if (stream_impl->cur_pos == 0)
		stream_impl->cur_position = stream_impl->lpECB->lpbData;

	if (stream_impl->lpECB->cbAvailable == stream_impl->lpECB->cbTotalBytes)
	{		
		if (count + stream_impl->cur_pos <= stream_impl->lpECB->cbAvailable)
			data_to_read = count;
		else
			data_to_read = stream_impl->lpECB->cbAvailable - stream_impl->cur_pos;
		
		(char *)stream_impl->cur_position += data_to_read;
		stream_impl->cur_pos += data_to_read;
		read_bytes = data_to_read;
	}
	else if (stream_impl->lpECB->cbAvailable == -1)
	{
		temp_buff = malloc(read_bytes);
		ret_val = stream_impl->lpECB->ReadClient(stream_impl->lpECB->ConnID, temp_buff, &read_bytes);		
		free(temp_buff);
	}
	else if (stream_impl->lpECB->cbAvailable < stream_impl->lpECB->cbTotalBytes)
	{
		if (stream_impl->cur_pos > stream_impl->lpECB->cbAvailable)
		{
			temp_buff = malloc(read_bytes);
			ret_val = stream_impl->lpECB->ReadClient(stream_impl->lpECB->ConnID, temp_buff, &read_bytes);		
			free(temp_buff);
		} 
		else if (stream_impl->cur_pos + count > stream_impl->lpECB->cbAvailable && stream_impl->cur_pos < stream_impl->lpECB->cbAvailable) 
		{
			data_to_read = stream_impl->lpECB->cbAvailable - stream_impl->cur_pos;							
			read_bytes = stream_impl->cur_pos + count - stream_impl->lpECB->cbAvailable;			
			temp_buff = malloc(read_bytes);
			
			if (temp_buff == NULL) return data_to_read;

			ret_val = stream_impl->lpECB->ReadClient(stream_impl->lpECB->ConnID, temp_buff, &read_bytes);							
			read_bytes += data_to_read;
			free(temp_buff);
		}
		else 
		{									
			(char *)stream_impl->cur_position += count;
			stream_impl->cur_pos += count;
			read_bytes = count;	
		}
	}	
	if (ret_val == FALSE)
	{
		return -1;
	}    
    return read_bytes;
}

int AXIS2_CALL
iis_stream_get_char(
    axutil_stream_t *stream,
    const axutil_env_t *env)
{
    int ret = -1;
    AXIS2_ENV_CHECK(env, AXIS2_CRITICAL_FAILURE);

    return ret;
}

axutil_stream_type_t AXIS2_CALL
iis_stream_get_type(
    axutil_stream_t *stream,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_CRITICAL_FAILURE);
    return AXIS2_INTF_TO_IMPL(stream)->stream_type;
}



