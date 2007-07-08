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

#include <axutil_url.h>
#include <axutil_string.h>
#include <axutil_string.h>
#include <axutil_file_handler.h>
#include <axutil_network_handler.h>
#include <axutil_types.h>

struct axutil_url
{
    axis2_char_t *protocol;
    axis2_char_t *server;
    int port;
    axis2_char_t *path;
};

AXIS2_EXTERN axutil_url_t * AXIS2_CALL
axutil_url_create(const axutil_env_t *env,
    const axis2_char_t *protocol,
    const axis2_char_t *server,
    const int port,
    const axis2_char_t *path)
{
    axutil_url_t *url = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, protocol, NULL);

    url = (axutil_url_t *)AXIS2_MALLOC(env->allocator,
        sizeof(axutil_url_t));

    if (!url)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    url->protocol = axutil_strdup(env, protocol);
    url->server = NULL;
    url->path = NULL;
    url->port = port;

    if (server)
    {
        url->server = (axis2_char_t *)axutil_strdup(env, server);
    }
    /** if the path is not starting with / we have to make it so
     */
    if (path)
    {
        if (path[0] == '/')
        {
            url->path = (axis2_char_t *)axutil_strdup(env, path);
        }
        else
        {
            url->path = axutil_stracat(env, "/", path);
        }

    }

    return url;
}

AXIS2_EXTERN axutil_url_t * AXIS2_CALL
axutil_url_parse_string(const axutil_env_t *env, 
    const axis2_char_t *str_url)
{
    /**
     * Only accepted format is : 
     * protocol://server:port/path
      * Added file:///path
     * port is optional and the default port is assumed
     * if path is not present / (root) is assumed
     */
    axis2_char_t *tmp_url_str = NULL;
    axutil_url_t *ret = NULL;
    const axis2_char_t *protocol = NULL;
    axis2_char_t *path = NULL;
    axis2_char_t *port_str = NULL;
    axis2_char_t *server = NULL;
    axis2_char_t *params = NULL;
    int port = -1;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, str_url, NULL);

    tmp_url_str = axutil_strdup(env, str_url);
    if (!tmp_url_str)
    {
        return NULL;
    }
    protocol = tmp_url_str;
    server = strstr(tmp_url_str, "://");
    if (!server)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_ADDRESS,
            AXIS2_FAILURE);
        AXIS2_FREE(env->allocator, tmp_url_str);
        return NULL;
    }
    if (axutil_strlen(server) < 3 * sizeof(axis2_char_t))
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_ADDRESS,
            AXIS2_FAILURE);
        AXIS2_FREE(env->allocator, tmp_url_str);
        return NULL;
    }
    *server = '\0';
    server += 3 * sizeof(axis2_char_t); /* skip "://" part */
    if (axutil_strlen(server) <= 0)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_ADDRESS,
            AXIS2_FAILURE);
        AXIS2_FREE(env->allocator, tmp_url_str);
        return NULL;
    }
    /* if the url is file:// thing we need the protocol and
     * path only
     */
    if (0 == axutil_strcasecmp(protocol, (const axis2_char_t *)"file"))
    {
        ret = axutil_url_create(env, protocol, NULL, 0, server);
        AXIS2_FREE(env->allocator, tmp_url_str);
        return ret;
    }
    port_str = strchr(server, ':');
    if (!port_str)
    {
        if (0 == axutil_strcasecmp(protocol, "http"))
        {
            port = 80;
        }
        if (0 == axutil_strcasecmp(protocol, "ftp"))
        {
            port = 20;
        }
        if (0 == axutil_strcasecmp(protocol, "smtp"))
        {
            port = 25;
        }
        path = strchr(server, '/');
        if (!path)
        {
            /* No path - assume def path ('/') */
            params = strchr(server, '?');
            if (params)
            {
                *params = '\0';
            }
            /* here we have protocol + server + def port + def path */
            ret = axutil_url_create(env, protocol, server, port, "/");
            AXIS2_FREE(env->allocator, tmp_url_str);
            return ret;
        }
        else
        {
            *path++ = '\0';
            params = strchr(path, '?');
            if (params)
            {
                *params = '\0';
            }
            /* here we have protocol + server + def port + path */
            ret = axutil_url_create(env, protocol, server, port, path);
            AXIS2_FREE(env->allocator, tmp_url_str);
            return ret;
        }
    }
    else
    {
        *port_str++ = '\0';
        path = strchr(port_str, '/');
        if (!path)
        {
            port = AXIS2_ATOI(port_str);
            /* here we have protocol + server + port + def path */
            ret = axutil_url_create(env, protocol, server, port, "/");
            AXIS2_FREE(env->allocator, tmp_url_str);
            return ret;
        }
        else
        {
            *path++ = '\0';
            port = AXIS2_ATOI(port_str);
            if (axutil_strlen(path) > 0)
            {
                /* here we have protocol + server + port + path */
                ret = axutil_url_create(env, protocol, server, port, path);
                AXIS2_FREE(env->allocator, tmp_url_str);
                return ret;
            }
            else
            {
                /* here we have protocol + server + port + def path */
                ret = axutil_url_create(env, protocol, server, port, "/");
                AXIS2_FREE(env->allocator, tmp_url_str);
                return ret;
            }
        }
    }
}

AXIS2_EXTERN void AXIS2_CALL
axutil_url_free(axutil_url_t *url, 
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    if (url->protocol)
    {
        AXIS2_FREE(env->allocator, url->protocol);
		url->protocol = NULL;
    }
    if (url->server)
    {
        AXIS2_FREE(env->allocator, url->server);
		url->server = NULL;
    }
    if (url->path)
    {
        AXIS2_FREE(env->allocator, url->path);
		url->path = NULL;
    }
    url->port = -1;

    AXIS2_FREE(env->allocator, url);

    return;
}

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
axutil_url_to_external_form(axutil_url_t *url,
    const axutil_env_t *env)
{
    axis2_char_t *external_form = NULL;
    axis2_ssize_t len = 0;
    axis2_char_t port_str[8];
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, url, NULL);

    sprintf(port_str, "%d", url->port);
    len = axutil_strlen(url->protocol) +
        axutil_strlen(url->server) + axutil_strlen(url->path) +
        strlen(port_str) + 7;
    external_form = (axis2_char_t*) AXIS2_MALLOC(env->allocator,
        len);
    sprintf(external_form, "%s://%s:%s%s", url->protocol, url->server,
        port_str, url->path);
    return external_form;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_url_set_protocol(axutil_url_t *url, 
    const axutil_env_t *env,
    axis2_char_t *protocol)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, protocol, AXIS2_FAILURE);
    if (url->protocol)
    {
        AXIS2_FREE(env->allocator, url->protocol);
        url->protocol = NULL;
    }
    url->protocol = axutil_strdup(env, protocol);
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axis2_char_t* AXIS2_CALL
axutil_url_get_protocol(axutil_url_t *url, 
    const axutil_env_t *env)
{
    return url->protocol;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_url_set_server(axutil_url_t *url, 
    const axutil_env_t *env,
    axis2_char_t *server)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, server, AXIS2_FAILURE);
    if (url->server)
    {
        AXIS2_FREE(env->allocator, url->server);
    }
    url->server = axutil_strdup(env, server);
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axis2_char_t* AXIS2_CALL
axutil_url_get_server(axutil_url_t *url, 
    const axutil_env_t *env)
{
    return url->server;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_url_set_port(axutil_url_t *url, 
    const axutil_env_t *env,
    int port)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    url->port = port;
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN int AXIS2_CALL
axutil_url_get_port(axutil_url_t *url, 
    const axutil_env_t *env)
{
    return url->port;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_url_set_path(axutil_url_t *url, 
    const axutil_env_t *env,
    axis2_char_t *path)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, path, AXIS2_FAILURE);
    if (url->path)
    {
        AXIS2_FREE(env->allocator, url->path);
    }
    url->path = axutil_strdup(env, path);
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axis2_char_t* AXIS2_CALL
axutil_url_get_path(axutil_url_t *url, 
    const axutil_env_t *env)
{
    return url->path;
}

AXIS2_EXTERN axutil_url_t* AXIS2_CALL
axutil_url_clone(axutil_url_t *url,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    return axutil_url_create(env, url->protocol,
        url->server,
        url->port,
        url->path);
}

AXIS2_EXTERN axutil_uri_t *AXIS2_CALL
axutil_url_to_uri(axutil_url_t *url,
    const axutil_env_t *env)
{
    axis2_char_t *url_str = NULL;
    axutil_uri_t *uri = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    url_str = axutil_url_to_external_form(url, env);
    uri = axutil_uri_parse_string(env, url_str);
    return uri;
}

