/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <reg_client_constants.h>
#include <reg_client_rest_client.h>
#include <axutil_url.h>
#include <curl/curl.h>
#include <curl/types.h>
#include <curl/easy.h>

/** 
 * @brief rest_client struct impl
 *	Rest Client Interface for C
 */
  
struct reg_client_rest_client_t 
{
    axis2_char_t *username;
    axis2_char_t *password;
    axis2_char_t *reg_url;
    long status;
};

/* The data collector function passed to Curl in order to collect the transfered data */
static size_t 
reg_client_rest_client_write_data(void *ptr, 
        size_t size, 
        size_t nmemb, 
        void *stream)
{
    int written = fwrite(ptr, size, nmemb, (FILE *)stream);
    return written;
}

AXIS2_EXTERN reg_client_rest_client_t* AXIS2_CALL
reg_client_rest_client_create(
    const axutil_env_t *env,  
    const axis2_char_t *reg_url, 
	const axis2_char_t *username,
    const axis2_char_t *password)
{
    reg_client_rest_client_t *rest_client = NULL;

    AXIS2_PARAM_CHECK(env->error, reg_url, NULL);
    AXIS2_PARAM_CHECK(env->error, username, NULL);
    AXIS2_PARAM_CHECK(env->error, password, NULL);
    
    rest_client =  (reg_client_rest_client_t *)AXIS2_MALLOC(env->allocator, 
            sizeof(reg_client_rest_client_t));
	
    if(!rest_client)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}

    rest_client->username = axutil_strdup(env, username);
    rest_client->password = axutil_strdup(env, password);
    rest_client->reg_url = axutil_strdup(env, reg_url);
    rest_client->status = -1;
    
	return rest_client;
}


axis2_status_t AXIS2_CALL 
reg_client_rest_client_free(
    reg_client_rest_client_t *rest_client, 
    const axutil_env_t *env)
{
    if(rest_client->username)
    {
        AXIS2_FREE(env->allocator, rest_client->username);
        rest_client->username = NULL;
    }
    
    if(rest_client->password)
    {
        AXIS2_FREE(env->allocator, rest_client->password);
        rest_client->password = NULL;
    }
    
    if(rest_client->reg_url)
    {
        AXIS2_FREE(env->allocator, rest_client->reg_url);
        rest_client->reg_url = NULL;
    }

	AXIS2_FREE(env->allocator, rest_client);

	return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL 
reg_client_rest_client_get(
    reg_client_rest_client_t *rest_client,
	const axutil_env_t *env,
    const axis2_char_t *url,
    const axutil_array_list_t *params)
{
    CURL *curl_handle;
    CURLcode res;
    int size = 0, i = 0;
    axis2_char_t *params_str = "?";
    axis2_char_t *temp_str = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    if(params)
    {
        size = axutil_array_list_size((axutil_array_list_t *) params, env);
    }
    
    for(i = 0; i < size; i++)
    {
        reg_client_url_param_t *url_param = NULL;
        axis2_char_t *key = NULL;
        axis2_char_t *encoded_key = NULL;
        axis2_char_t *value = NULL;
        axis2_char_t *encoded_value = NULL;
        
        url_param = axutil_array_list_get((axutil_array_list_t *) params, env, i);
        key = url_param->key;
        value = url_param->value;
                
        encoded_key = (axis2_char_t *) AXIS2_MALLOC (env->allocator, strlen (key));
        memset (encoded_key, 0, strlen (key));
        encoded_key = axutil_url_encode (env, encoded_key, key, (int)strlen (key));
        
        encoded_value = (axis2_char_t *) AXIS2_MALLOC (env->allocator, strlen (value));
        memset (encoded_value, 0, strlen (value));
        encoded_value = axutil_url_encode (env, encoded_value, value, (int)strlen (value));
        temp_str = params_str;
        params_str = axutil_strcat(env, temp_str, encoded_key, "=", encoded_value, "&", NULL);
        if(temp_str)
        {
            AXIS2_FREE(env->allocator, temp_str);
            temp_str = NULL;
        }

        if(encoded_key)
        {
            AXIS2_FREE(env->allocator, encoded_key);
            encoded_key = NULL;
        }
        
        if(encoded_value)
        {
            AXIS2_FREE(env->allocator, encoded_value);
            encoded_value = NULL;
        }
    }

    temp_str = (axis2_char_t *) axutil_strdup(env,  url);
    url = axutil_strcat(env, temp_str, params_str, NULL);

    if(temp_str)
    {
        AXIS2_FREE(env->allocator, temp_str);
        temp_str = NULL;
    }

    curl_handle = curl_easy_init();
    if(curl_handle)
    {
        const char *datafilename = (const char *) REG_CLIENT_ATOM_DATA_FILE_NAME;
        FILE *datafile;

        curl_easy_setopt(curl_handle, CURLOPT_URL, url);
        curl_easy_setopt(curl_handle, CURLOPT_HTTPGET, 1);
        /*curl_easy_setopt(curl_handle, CURLOPT_RETURNTRANSFER, 1);*/
        curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, REG_CLIENT_USER_AGENT);

        if(rest_client->username)
        {
            axis2_char_t *uname_passwd = NULL;

            uname_passwd = axutil_strcat(env, rest_client->username, ":", rest_client->password, 
                    NULL);

            curl_easy_setopt(curl_handle, CURLOPT_USERPWD, uname_passwd);
        }

        /* Send all data to this function  */
        curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, reg_client_rest_client_write_data);

        /* Open the files */
        datafile = fopen(datafilename,"w");
        if (!datafile) 
        {
            curl_easy_cleanup(curl_handle);
            return AXIS2_FAILURE;
        }

        /* We want the data to this file handle */
        curl_easy_setopt(curl_handle,   CURLOPT_WRITEDATA, datafile);

        res = curl_easy_perform(curl_handle);
        if(res == CURLE_OK)
        {
            res = curl_easy_getinfo(curl_handle, CURLINFO_RESPONSE_CODE, &rest_client->status);
            if(res != CURLE_OK)
            {
                status = AXIS2_FAILURE;
            }
        }
         
        /* always cleanup */
        fclose(datafile);
        curl_easy_cleanup(curl_handle);
    }

    return status;
}

axis2_status_t AXIS2_CALL 
reg_client_rest_client_post(
    reg_client_rest_client_t *rest_client,
	const axutil_env_t *env,
    const axis2_char_t *url,
    const axis2_char_t *data,
    const axis2_char_t *content_type)
{
    CURL *curl_handle;
    CURLcode res;
    axis2_status_t status = AXIS2_FAILURE;

    curl_handle = curl_easy_init();
    if(curl_handle)
    {
        curl_easy_setopt(curl_handle, CURLOPT_HTTPHEADER, content_type);
        curl_easy_setopt(curl_handle, CURLOPT_URL, url);
        curl_easy_setopt(curl_handle, CURLOPT_POST, 1);
        curl_easy_setopt(curl_handle, CURLOPT_POSTFIELDS, data);
        /*curl_easy_setopt(curl_handle, CURLOPT_RETURNTRANSFER, 1);*/
        curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, REG_CLIENT_USER_AGENT);

        if(rest_client->username)
        {
            axis2_char_t *uname_passwd = NULL;

            uname_passwd = axutil_strcat(env, rest_client->username, ":", rest_client->password, 
                    NULL);

            curl_easy_setopt(curl_handle, CURLOPT_USERPWD, uname_passwd);
        }

        res = curl_easy_perform(curl_handle);
        if(res == CURLE_OK)
        {
            res = curl_easy_getinfo(curl_handle, CURLINFO_RESPONSE_CODE, &rest_client->status);
            if(res != CURLE_OK)
            {
                status = AXIS2_FAILURE;
            }
        }
         
        /* always cleanup */
        curl_easy_cleanup(curl_handle);
    }

    return status;
}

axis2_status_t AXIS2_CALL 
reg_client_rest_client_delete(
    reg_client_rest_client_t *rest_client,
	const axutil_env_t *env,
    const axis2_char_t *url,
    const axutil_array_list_t *params)
{
    CURL *curl_handle;
    CURLcode res;
    int size = 0, i = 0;
    axis2_char_t *params_str = "?";
    axis2_char_t *temp_str = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    if(params)
    {
        size = axutil_array_list_size((axutil_array_list_t *) params, env);
    }
    
    for(i = 0; i < size; i++)
    {
        reg_client_url_param_t *url_param = NULL;
        axis2_char_t *key = NULL;
        axis2_char_t *encoded_key = NULL;
        axis2_char_t *value = NULL;
        axis2_char_t *encoded_value = NULL;
        
        url_param = axutil_array_list_get((axutil_array_list_t *) params, env, i);
        key = url_param->key;
        value = url_param->value;
                
        encoded_key = (axis2_char_t *) AXIS2_MALLOC (env->allocator, strlen (key));
        memset (encoded_key, 0, strlen (key));
        encoded_key = axutil_url_encode (env, encoded_key, key, (int)strlen (key));
        
        encoded_value = (axis2_char_t *) AXIS2_MALLOC (env->allocator, strlen (value));
        memset (encoded_value, 0, strlen (value));
        encoded_value = axutil_url_encode (env, encoded_value, value, (int)strlen (value));
        temp_str = params_str;
        params_str = axutil_strcat(env, temp_str, encoded_key, "=", encoded_value, "&", NULL);
        if(temp_str)
        {
            AXIS2_FREE(env->allocator, temp_str);
            temp_str = NULL;
        }

        if(encoded_key)
        {
            AXIS2_FREE(env->allocator, encoded_key);
            encoded_key = NULL;
        }
        
        if(encoded_value)
        {
            AXIS2_FREE(env->allocator, encoded_value);
            encoded_value = NULL;
        }
    }

    temp_str = (axis2_char_t *) axutil_strdup(env, url);
    url = axutil_strcat(env, temp_str, params_str, NULL);

    if(temp_str)
    {
        AXIS2_FREE(env->allocator, temp_str);
        temp_str = NULL;
    }

    curl_handle = curl_easy_init();
    if(curl_handle)
    {
        curl_easy_setopt(curl_handle, CURLOPT_URL, url);
        curl_easy_setopt(curl_handle, CURLOPT_CUSTOMREQUEST, "DELETE");
        /*curl_easy_setopt(curl_handle, CURLOPT_RETURNTRANSFER, 1);*/
        curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, REG_CLIENT_USER_AGENT);

        if(rest_client->username)
        {
            axis2_char_t *uname_passwd = NULL;

            uname_passwd = axutil_strcat(env, rest_client->username, ":", rest_client->password, 
                    NULL);

            curl_easy_setopt(curl_handle, CURLOPT_USERPWD, uname_passwd);
        }

        res = curl_easy_perform(curl_handle);
        if(res == CURLE_OK)
        {
            res = curl_easy_getinfo(curl_handle, CURLINFO_RESPONSE_CODE, &rest_client->status);
            if(res != CURLE_OK)
            {
                status = AXIS2_FAILURE;
            }
        }
         
        /* always cleanup */
        curl_easy_cleanup(curl_handle);
    }

    return status;
}

long AXIS2_CALL
reg_client_rest_client_get_status(
        reg_client_rest_client_t *rest_client,
        const axutil_env_t *env)
{
    return rest_client->status;
}

