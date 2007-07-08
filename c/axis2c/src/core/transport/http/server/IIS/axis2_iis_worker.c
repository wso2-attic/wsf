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


#include <axis2_http_transport.h>
#include <axis2_conf.h>
#include <axutil_string.h>
#include <axis2_msg_ctx.h>
#include <axis2_http_out_transport_info.h>
#include <axis2_http_transport_utils.h>
#include <axis2_op_ctx.h>
#include <axis2_engine.h>
#include <axutil_uuid_gen.h>
#include <axis2_conf_init.h>
#include <axutil_url.h>

#include "axis2_iis_out_transport_info.h"
#include "axis2_iis_stream.h"
#include "axis2_iis_worker.h"

// Files from iis
#include <httpfilt.h>
#include <httpext.h>

#include "axis2_iis_constants.h"

#define READ_SIZE  32

axis2_status_t AXIS2_CALL axis2_worker_get_original_url(char url[], 
														char ret_url[]);

axis2_char_t *AXIS2_CALL axis2_iis_worker_get_bytes(const axutil_env_t *env,
													axutil_stream_t *stream);

axis2_status_t AXIS2_CALL start_response(LPEXTENSION_CONTROL_BLOCK lpECB,
                                    int status,
                                    const char *reason,
                                    const char *const *header_names,
                                    const char *const *header_values,
                                    unsigned int num_of_headers);

axis2_status_t write_response(LPEXTENSION_CONTROL_BLOCK lpECB, 
							  const void *b, unsigned int l);

static struct reasons {    
    axis2_char_t *status_code;
	int status_len;
} reasons[] = {
	{"200 OK", 6}, 
	{"202 Accepted", 12},
	{"500 Internal Server Error", 25}
	};	

struct axis2_iis_worker
{
    axis2_conf_ctx_t *conf_ctx;
};

char *status_reason(int status);

axis2_iis_worker_t * AXIS2_CALL
axis2_iis_worker_create(
    const axutil_env_t *env, 
    axis2_char_t *repo_path)
{
    axis2_iis_worker_t *iis_worker = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    iis_worker = (axis2_iis_worker_t *)
            AXIS2_MALLOC(env->allocator, sizeof(axis2_iis_worker_t));

    if (! iis_worker)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    iis_worker->conf_ctx = axis2_build_conf_ctx(env, repo_path);

    if (! iis_worker->conf_ctx)
    {
        axis2_iis_worker_free((axis2_iis_worker_t *)iis_worker,
                env);
        return NULL;
    }

    return iis_worker;	
}

void AXIS2_CALL
axis2_iis_worker_free(
    axis2_iis_worker_t *iis_worker,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (iis_worker->conf_ctx)
    {
         axis2_conf_ctx_free(iis_worker->conf_ctx, env);
        iis_worker->conf_ctx = NULL;
    }

    AXIS2_FREE(env->allocator, iis_worker);

    return;
}

int AXIS2_CALL
axis2_iis_worker_process_request(
    axis2_iis_worker_t *iis_worker,
    const axutil_env_t *env,
    LPEXTENSION_CONTROL_BLOCK lpECB)
{
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_msg_ctx_t *msg_ctx = NULL;
    axutil_stream_t *request_body = NULL;
    axutil_stream_t *out_stream = NULL;
    axis2_transport_out_desc_t *out_desc = NULL;
    axis2_transport_in_desc_t *in_desc = NULL;
    axis2_bool_t processed = AXIS2_FALSE;
    axis2_char_t *ctx_written = NULL;
    //int content_length = -1;
    //axis2_char_t *req_url = NULL;
    axis2_char_t *body_string = NULL;
    int send_status = -1;
    axutil_property_t *property = NULL;
    axutil_url_t *url = NULL;
    axis2_http_out_transport_info_t *iis_out_transport_info = NULL;
    axutil_qname_t *transport_qname = NULL;
    axis2_char_t *ctx_uuid = NULL;

    axis2_char_t soap_action[INTERNET_MAX_URL_LENGTH];
	axutil_string_t *soap_str_action = NULL;
	axis2_char_t original_url[INTERNET_MAX_URL_LENGTH];
	axis2_char_t req_url[INTERNET_MAX_URL_LENGTH];

	int body_str_len = 0;
	DWORD ret_val = 0;
	DWORD cbSize = 0;
	CHAR server_name[MAX_SERVERNAME]; 
	axis2_char_t port[MAX_TCP_PORT_LEN];
	CHAR redirect_url[INTERNET_MAX_PATH_LENGTH];

	soap_action[0] = '\0';
	// Check the parameters
	if (!env)
	{
		return HSE_STATUS_ERROR; 
	}
	if (!lpECB) 
    { 
        AXIS2_ERROR_SET_ERROR_NUMBER(env->error, AXIS2_ERROR_INVALID_NULL_PARAM);         
        return HSE_STATUS_ERROR; 
    }

	conf_ctx = iis_worker->conf_ctx;	

	if (! conf_ctx)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NULL_CONFIGURATION_CONTEXT,
                AXIS2_FAILURE);
        return HSE_STATUS_ERROR;
    }	

	cbSize = INTERNET_MAX_PATH_LENGTH; 
	ret_val = lpECB->GetServerVariable(lpECB->ConnID, 
                         "SERVER_NAME", 
                         server_name, 
                         &cbSize); 	

	cbSize = MAX_TCP_PORT_LEN;
	ret_val = lpECB->GetServerVariable(lpECB->ConnID, "SERVER_PORT", port, &cbSize);

	cbSize = INTERNET_MAX_PATH_LENGTH;
	ret_val = lpECB->GetServerVariable(lpECB->ConnID, "HTTP_URL", redirect_url, &cbSize);

	axis2_worker_get_original_url(redirect_url, original_url);
	
	// create the url using the above variables						
	sprintf(req_url, "%s%s%s%s", "http", server_name, port, original_url);

    out_stream = axutil_stream_create_basic(env);	
 
    out_desc =  axis2_conf_get_transport_out( axis2_conf_ctx_get_conf
            (iis_worker->conf_ctx, env), env,
            AXIS2_TRANSPORT_ENUM_HTTP);
    in_desc =  axis2_conf_get_transport_in( axis2_conf_ctx_get_conf
            (iis_worker->conf_ctx, env), env,
            AXIS2_TRANSPORT_ENUM_HTTP);

	msg_ctx = axis2_msg_ctx_create(env, conf_ctx, in_desc, out_desc);
     axis2_msg_ctx_set_server_side(msg_ctx, env, AXIS2_TRUE);

	axis2_msg_ctx_set_transport_out_stream(msg_ctx, env, out_stream);

	ctx_uuid = axutil_uuid_gen(env);
	if (ctx_uuid)
	{
        axutil_string_t *uuid_str = axutil_string_create_assume_ownership(env, &ctx_uuid);
         axis2_msg_ctx_set_svc_grp_ctx_id(msg_ctx, env, uuid_str);
        axutil_string_free(uuid_str, env);
	}

    iis_out_transport_info = axis2_iis_out_transport_info_create(env, lpECB);
    axis2_msg_ctx_set_http_out_transport_info(msg_ctx, env, iis_out_transport_info);
	
	cbSize = INTERNET_MAX_URL_LENGTH;
	if (lpECB->GetServerVariable(lpECB->ConnID, "HTTP_SOAPAction", soap_action, &cbSize))
	{
		soap_str_action = axutil_string_create(env, soap_action);	
	}
	request_body = axutil_stream_create_iis(env, lpECB);

	if (! request_body)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error occured in"
                " creating input stream.");
        return HSE_STATUS_ERROR;
    }	
	
	if (stricmp(lpECB->lpszMethod, "GET") == 0)
    {
        processed = axis2_http_transport_utils_process_http_get_request
                (env, msg_ctx, request_body, out_stream,
                        lpECB->lpszContentType , soap_str_action,
                        req_url,
                        conf_ctx,
                        axis2_http_transport_utils_get_request_params(env,
                                (axis2_char_t *)req_url));

		// If this is not a valid GET request display the list of displayed services.
		if (processed == AXIS2_FAILURE)
        {
            body_string = axis2_http_transport_utils_get_services_html(env,
                    conf_ctx);

			if (body_string)
			{
				body_str_len = strlen(body_string);
			}

            axis2_http_out_transport_info_set_content_type(iis_out_transport_info, env, "text/html");
            send_status = OK;
        }
    }
    else if (stricmp(lpECB->lpszMethod, "POST") == 0)
    {
        axis2_status_t status = AXIS2_FAILURE;
        status = axis2_http_transport_utils_process_http_post_request
                (env, msg_ctx, request_body, out_stream,
                        lpECB->lpszContentType , lpECB->cbTotalBytes,
                        soap_str_action,
                        req_url);

		// generate a soap fault and send it
        if (status == AXIS2_FAILURE)
        {
            axis2_msg_ctx_t *fault_ctx = NULL;
            axis2_engine_t *engine = axis2_engine_create(env, conf_ctx);
            if (! engine)
            {
                send_status =  HTTP_INTERNAL_SERVER_ERROR;
            }
            fault_ctx =  axis2_engine_create_fault_msg_ctx(engine, env, msg_ctx);
            axis2_engine_send_fault(engine, env, fault_ctx);
            if (out_stream)
            {
                body_string = axutil_stream_get_buffer(out_stream, env);
                body_str_len = axutil_stream_get_len(out_stream, env);
            }
            send_status =  HTTP_INTERNAL_SERVER_ERROR;
             axis2_msg_ctx_free(fault_ctx, env);
        }
    }
	// Nothing wrong has happen. So proceed with the request
    if (-1 == send_status)
    {
        axis2_op_ctx_t *op_ctx =  axis2_msg_ctx_get_op_ctx(msg_ctx, env);
        if (axis2_op_ctx_get_response_written(op_ctx, env))
        {
            if (out_stream)
            {
                body_string = axutil_stream_get_buffer(out_stream, env);
                body_str_len = axutil_stream_get_len(out_stream, env);
            }
			send_status = OK;
        }
        else
        {
            send_status = HTTP_ACCEPTED;
        }
    }

	if (body_string)
	{		
		const char *headers_names[] = {
					"Content-Type",
					"Content-Length"
					};
		const char *headers_vhtml[2];
					
		headers_vhtml[1] = (char *)malloc(16);
		headers_vhtml[0] = axis2_iis_out_transport_get_content(iis_out_transport_info);
		sprintf(headers_vhtml[1], "%d", body_str_len);
		if(!start_response(lpECB, send_status, NULL, headers_names, headers_vhtml, 2))
		{
			AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error occured in"
                " writing response.");			
		}
		
		if(!write_response(lpECB, body_string, body_str_len))
		{
			AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error occured in"
                " writing response.");
		}
        AXIS2_FREE(env->allocator, body_string);
        body_string = NULL;
    } 
	else 
	{		
		if(!start_response(lpECB, send_status, NULL, NULL, NULL, 0))
		{
			AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error occured in"
                " writing response.");			
		}
	}

    if (request_body)
    {
        axutil_stream_free(request_body, env);
        request_body = NULL;
    }
    msg_ctx = NULL;
    return HSE_STATUS_SUCCESS;
}

axis2_status_t write_response(LPEXTENSION_CONTROL_BLOCK lpECB, const void *b, unsigned int l)
{    
    if (lpECB && b) {
        if (l) {
            unsigned int written = 0;
            char *buf = (char *)b;
			// If couldn't write the data at onece try again until all the data is written.
            while (written < l) {
                DWORD try_to_write = l - written;
                if (!lpECB->WriteClient(lpECB->ConnID,
                                           buf + written, &try_to_write, 0)) {
                    return FALSE;
                }
                written += try_to_write;
            }
        }        
        return TRUE;
    }    
    return FALSE;
}

axis2_status_t AXIS2_CALL start_response(LPEXTENSION_CONTROL_BLOCK lpECB,
                                    int status,
                                    const char *reason,
                                    const char *const *header_names,
                                    const char *const *header_values,
                                    unsigned int num_of_headers)
{
    static char crlf[3] = { (char)13, (char)10, '\0' };
    
    if (status < 100 || status > 1000) {        
        return FALSE;
    }

    if (lpECB) {
        size_t len_of_status;
        char *status_str;
        char *headers_str;

        /*
         * Create the status line
         */
        if (reason) {
			status_str = (char *)_alloca((6 + strlen(reason)) * sizeof(char));
			sprintf(status_str, "%d %s", status, reason);
			len_of_status = strlen(status_str);
        }
		else {
			switch (status) {
				case 200:
					status_str = reasons[0].status_code;
					len_of_status = reasons[0].status_len;
					break;
				case 202:
					status_str = reasons[1].status_code;
					len_of_status = reasons[1].status_len;
					break;
				case 500:
					status_str = reasons[2].status_code;
					len_of_status = reasons[2].status_len;
					break;
				default:
					status_str = reasons[0].status_code;
					len_of_status = reasons[0].status_len;
					break;
			}
		}

        /*
         * Create response headers string
         */
        if (num_of_headers) {
            size_t i, len_of_headers;
            for (i = 0, len_of_headers = 0; i < num_of_headers; i++) {
                len_of_headers += strlen(header_names[i]);
                len_of_headers += strlen(header_values[i]);
                len_of_headers += 4;        /* extra for colon, space and crlf */
            }

            len_of_headers += 3;    /* crlf and terminating null char */
            headers_str = (char *)_alloca(len_of_headers * sizeof(char));
            headers_str[0] = '\0';

            for (i = 0; i < num_of_headers; i++) {
                strcat(headers_str, header_names[i]);
                strcat(headers_str, ": ");
                strcat(headers_str, header_values[i]);
                strcat(headers_str, "\r\n");
            }
            strcat(headers_str, "\r\n");
        }
        else {
            headers_str = crlf;
        }

        if (!lpECB->ServerSupportFunction(lpECB->ConnID,
                                             HSE_REQ_SEND_RESPONSE_HEADER,
                                             status_str,
                                             (LPDWORD) &len_of_status,
                                             (LPDWORD) headers_str)) {            
            return FALSE;
        }
        return TRUE;
    }
    return FALSE;
}


axis2_status_t AXIS2_CALL axis2_worker_get_original_url(char url[], char ret_url[])
{
	int i = 0;
	for (i = 0; i < 7 ; i++)
		ret_url[i] = url[i];

	for (i = 7; url[i] != '\0'; i++)
		ret_url[i] = url[i + 18];

	ret_url[i] = '\0';
		
	return URI_MATCHED;
}

axis2_char_t *AXIS2_CALL
axis2_iis_worker_get_bytes(
    const axutil_env_t *env,
    axutil_stream_t *stream)
{

    axutil_stream_t *tmp_stream = NULL;
    int return_size = -1;
    axis2_char_t *buffer = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, stream, NULL);

    tmp_stream = axutil_stream_create_basic(env);
    while (1)
    {
        int read = 0;
        int write = 0;

        char buf[READ_SIZE];
        read = axutil_stream_read(stream, env, buf, READ_SIZE);
        if (read < 0)
        {
            break;
        }
        write = axutil_stream_write(tmp_stream, env, buf, read);
        if (read < (READ_SIZE - 1))
        {
            break;
        }
    }
    return_size = axutil_stream_get_len(tmp_stream, env);

    if (return_size > 0)
    {
        buffer = (char *)AXIS2_MALLOC(env->allocator, sizeof(char) *
                (return_size + 2));
        return_size = axutil_stream_read(tmp_stream, env, buffer,
                return_size + 1);
        buffer[return_size + 1] = '\0';
    }
    axutil_stream_free(tmp_stream, env);
    return buffer;
}


