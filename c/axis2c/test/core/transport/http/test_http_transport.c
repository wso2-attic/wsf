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

#include <stdio.h>
#include <axis2_http_request_line.h>
#include <axis2_http_status_line.h>
#include <axis2_http_header.h>
#include <axutil_error_default.h>
#include <axutil_url.h>
#include <axis2_http_client.h>

typedef struct a
{
    axis2_char_t *value;
}
a;

axutil_env_t *test_init()
{
    axutil_allocator_t *allocator = axutil_allocator_init(NULL);
    axutil_error_t *error = axutil_error_create(allocator);
    axutil_env_t *env = axutil_env_create_with_error(allocator, error);
    return env;
}

void test_http_request_line(const axutil_env_t *env)
{
    const char *request_line_str = "POST http://ws.apache.org/axis2/c/services/test_svc/test_op?x=1 HTTP/1.1\r\n";
    axis2_http_request_line_t *request_line;

    printf("Starting http_request_line tests\n");
    request_line = axis2_http_request_line_parse_line(env, request_line_str);
    printf("Method: %s|URI: %s|HTTP Version: %s|\n", axis2_http_request_line_get_method
            (request_line, env), axis2_http_request_line_get_uri(request_line, env),
            axis2_http_request_line_get_http_version(request_line, env));
    axis2_http_request_line_free(request_line, env);
    printf("Finished http_request_line tests ..........\n\n");
}


void test_http_status_line(const axutil_env_t *env)
{
    const char *status_line_str = "HTTP/1.1 202 Accepted\r\n";
    axis2_http_status_line_t *status_line;

    printf("Starting http_status_line tests\n");
    status_line = axis2_http_status_line_create(env, status_line_str);
    printf("Staus Line starts with HTTP ? :%d\n",
            axis2_http_status_line_starts_with_http(status_line, env));
    printf("HTTP Version :%s|Status Code:%d|Reason Phrase:%s|\n",
            axis2_http_status_line_get_http_version(status_line, env),
            axis2_http_status_line_get_status_code(status_line, env),
            axis2_http_status_line_get_reason_phrase(status_line, env));
    printf("to_string :%s\n", axis2_http_status_line_to_string(status_line, env));
    axis2_http_status_line_free(status_line, env);
    printf("Finished http_status_line tests ..........\n\n");
}

void test_http_header(const axutil_env_t *env)
{
    const char *header_name = "Content-Type";
    const char *header_value = "text/xml";
    const char *str_header = "Content-Type: text/xml; charset=UTF-8\r\n";
    axis2_http_header_t *http_header;
    axis2_char_t *external_form = NULL;

    printf("Starting http_header tests\n");
    http_header = axis2_http_header_create(env, header_name, header_value);
    external_form = axis2_http_header_to_external_form(http_header, env);
    printf("Heder Name :%s|Header Value:%s|External Form:%s\n",
            axis2_http_header_get_name(http_header, env),
            axis2_http_header_get_value(http_header, env),
            external_form);
    AXIS2_FREE(env->allocator, external_form);
    axis2_http_header_free(http_header, env);

    http_header = axis2_http_header_create_by_str(env, str_header);
    printf("Finished http_header tests ..........\n\n");
}

void test_url(const axutil_env_t *env)
{
    const axis2_char_t *str_url = "http://ws.apache.org/axis2/";
    axutil_url_t *url = axutil_url_parse_string(env, str_url);
    if (! url)
    {
        printf("URL is NULL\n");
        return;
    }
    printf("Starting URL Test ....\n");
    printf("Parsed URL : \n Protocol :%s|\n Server :%s|\n Port :%d|\n Path : %s|\n",
            axutil_url_get_protocol(url, env), axutil_url_get_server(url, env),
            axutil_url_get_port(url, env), axutil_url_get_path(url, env));
    printf("End of URL Test ... \n");
    axutil_url_free(url, env);
}

void test_http_client(const axutil_env_t *env)
{
    axis2_http_client_t *client = NULL;
    axis2_http_simple_request_t *request = NULL;
    axis2_http_request_line_t *request_line = NULL;
    axutil_url_t *url = NULL;
    axis2_http_header_t *header = NULL;
    axutil_stream_t *request_body = NULL;
    axis2_http_simple_response_t *response = NULL;
    int status = 0;
    char *body_bytes = NULL;
    int body_bytes_len = 0;

    printf("Starting http_client tests\n");
    request_line = axis2_http_request_line_create(env, "GET",
            "/axis2/services", "HTTP/1.0");
    request_body = axutil_stream_create_basic(env);
    request = axis2_http_simple_request_create(env, request_line,
            NULL, 0, NULL);
    url = axutil_url_create(env, "http", "localhost", 80,
            NULL);
    header = axis2_http_header_create(env, "Host", axutil_url_get_server(url, env));
    axis2_http_simple_request_add_header(request, env, header);
    client = axis2_http_client_create(env, url);

    status = axis2_http_client_send(client, env, request, NULL);
    if (status < 0)
    {
        printf("Test FAILED .........Can't send the request. Status :%d\n", status);
        return;
    }
    status = axis2_http_client_recieve_header(client, env);
    if (status < 0)
    {
        printf("Test FAILED ......... Can't recieve. Status: %d\n", status);
        return;
    }
    response = axis2_http_client_get_response(client, env);
    if (! response)
    {
        printf("Test Failed : NULL response");
        return;
    }
    printf("Content Type :%s\n", axis2_http_simple_response_get_content_type(
                response, env));
    printf("Content Length :%d\n", axis2_http_simple_response_get_content_length(
                response, env));
    printf("Status code :%d\n", status);
    body_bytes_len = axis2_http_simple_response_get_body_bytes(response, env, &body_bytes);
    printf("body :%s\n", body_bytes);

    axis2_http_client_free(client, env);
    axis2_http_simple_request_free(request, env);
    axutil_stream_free(request_body, env);
    AXIS2_FREE(env->allocator, body_bytes);
    printf("Finished http_client tests ..........\n\n");
}

void test_https_client(const axutil_env_t *env)
{
#ifndef AXIS2_SSL_ENABLED
    return;
#else
    axis2_http_client_t *client = NULL;
    axis2_http_simple_request_t *request = NULL;
    axis2_http_request_line_t *request_line = NULL;
    axutil_url_t *url = NULL;
    axis2_http_header_t *header = NULL;
    axutil_stream_t *request_body = NULL;
    axis2_http_simple_response_t *response = NULL;
    int status = 0;
    char *body_bytes = NULL;
    int body_bytes_len = 0;

    printf("Starting https_client tests\n");
    request_line = axis2_http_request_line_create(env, "GET",
            "/", "HTTP/1.0");
    request_body = axutil_stream_create_basic(env);
    request = axis2_http_simple_request_create(env, request_line,
            NULL, 0, NULL);
    url = axutil_url_create(env, "https", "localhost", 9090,
            NULL);
    
    header = axis2_http_header_create(env, "Host", axutil_url_get_server(url, env));
    axis2_http_simple_request_add_header(request, env, header);
    client = axis2_http_client_create(env, url);

    /* if you weant to test the proxy uncomment following */
    /*axis2_http_client_set_proxy(client, env, "127.0.0.1", 8080);*/
    
    /* Add CA/Server certificate */
    status = axis2_http_client_set_server_cert(client, env,
                "/home/dummy/dummyCA/demoCA/cacert.pem");

    status = axis2_http_client_send(client, env, request, NULL);
    if (status < 0)
    {
        printf("Test FAILED .........Can't send the request. Status :%d\n", status);
        return;
    }
    status = axis2_http_client_recieve_header(client, env);
    if (status < 0)
    {
        printf("Test FAILED ......... Can't recieve. Status: %d\n", status);
        return;
    }
    response = axis2_http_client_get_response(client, env);
    if (! response)
    {
        printf("Test Failed : NULL response");
        return;
    }
    printf("Content Type :%s\n", axis2_http_simple_response_get_content_type(
                response, env));
    printf("Content Length :%d\n", axis2_http_simple_response_get_content_length(
                response, env));
    printf("Status code :%d\n", status);
    body_bytes_len = axis2_http_simple_response_get_body_bytes(response, env, &body_bytes);

    axis2_http_client_free(client, env);
    axis2_http_simple_request_free(request, env);
    axutil_stream_free(request_body, env);
    AXIS2_FREE(env->allocator, body_bytes);
    printf("Finished https_client tests ..........\n\n");
#endif
}

int main(void)
{
    axutil_env_t *env = test_init();
    test_http_request_line(env);
    test_http_status_line(env);
    test_http_header(env);
    test_http_client(env);
    test_https_client(env);
    test_url(env);

    axutil_env_free(env);
    return 0;
}
