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
#include <remote_registry_constants.h>
#include <remote_registry_util.h>
#include <remote_registry_rest_client.h>
#include <axutil_utils.h>
#include <axutil_url.h>
#include <curl/curl.h>
#include <curl/types.h>
#include <curl/easy.h>
#include <axutil_hash.h>

/** 
* @brief rest_client struct impl
*	Rest Client Interface for C
*/

struct remote_registry_rest_client
{
	remote_registry_conf_t *conf;
	/* just keep the sucess or the failure of the last response */
	axis2_status_t last_response_status;
	axis2_char_t *last_response_content_type;

	/* properties related to caching */
	axutil_hash_t *cached_entries;
	axutil_hash_t *cached_entries_len;
	axutil_hash_t *etags;

	/* keep the order of the cache */
	axutil_array_list_t *cached_order;
	axutil_hash_t *reverse_cached_order;
	int cached_order_index;
};

/* the callback to recieve data */
size_t static remote_registry_rest_client_write_data(void *buffer, 
													 size_t size, 
													 size_t nmemb, 
													 void *userp);


/* the callback to send data */
size_t static remote_registry_rest_client_read_data(void *buffer, 
													size_t size, 
													size_t nmemb, 
													void *userp);

/* internal functions, not exposed to public */
/* overwrite the cache */
axis2_status_t static 
remote_registry_rest_client_set_cache(remote_registry_rest_client_t *rest_client,
									  const axutil_env_t *env,
									  const axis2_char_t *url,
									  axis2_char_t *buffer, 
									  int buffer_len, 
									  axis2_char_t *new_etag);

static axis2_char_t*
remote_registry_rest_client_extract_etag_info(const axutil_env_t *env, axis2_char_t *buffer);

static long
remote_registry_rest_client_get_only_if_modified(
	remote_registry_rest_client_t *rest_client,
	const axutil_env_t *env,
	const axis2_char_t *url,
	axis2_char_t *uname_passwd,
	axis2_char_t **buffer,
	int *content_len);

static long
remote_registry_rest_client_get_internal(
	remote_registry_rest_client_t *rest_client,
	const axutil_env_t *env,
	const axis2_char_t *url,
	axis2_char_t *uname_passwd,
	axis2_char_t **buffer,
	int *content_len,
	struct curl_slist *headers);

/* the callback parameter structure to sync with the main call */
typedef struct {
	const axutil_env_t *env;
	axis2_char_t *buffer;
	int buffer_len;
} remote_registry_rest_client_callbk_param_t;


AXIS2_EXTERN remote_registry_rest_client_t* AXIS2_CALL
remote_registry_rest_client_create(
								   const axutil_env_t *env,  
								   remote_registry_conf_t *conf)
{
	remote_registry_rest_client_t *rest_client = NULL;

	AXIS2_PARAM_CHECK(env->error, conf, NULL);

	rest_client =  (remote_registry_rest_client_t *)AXIS2_MALLOC(env->allocator, 
		sizeof(remote_registry_rest_client_t));

	if(!rest_client)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
		return NULL;
	}

	/* initializing the values */
	rest_client->last_response_status = AXIS2_SUCCESS;
	rest_client->last_response_content_type = NULL;
	rest_client->conf = conf;


	rest_client->cached_entries = axutil_hash_make(env);
	rest_client->cached_entries_len = axutil_hash_make(env);
	rest_client->etags = axutil_hash_make(env);
	rest_client->reverse_cached_order = axutil_hash_make(env);
	rest_client->cached_order = axutil_array_list_create(env, 10);
	rest_client->cached_order_index = 0;


	return rest_client;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL 
remote_registry_rest_client_free(
								 remote_registry_rest_client_t *rest_client, 
								 const axutil_env_t *env)
{

	if(rest_client->conf)
	{
		remote_registry_conf_free(rest_client->conf, env);
		rest_client->conf = NULL;
	}
	if(rest_client->last_response_content_type) 
	{
		AXIS2_FREE(env->allocator, rest_client->last_response_content_type);
		rest_client->last_response_content_type = NULL;
	}

	if(rest_client->cached_entries)
	{
		axutil_hash_index_t *hi;
		void *val;
		void *key;
		int sum = 0;
		for (hi = axutil_hash_first(rest_client->cached_entries, env); hi; hi = axutil_hash_next(env, hi)) {
			axutil_hash_this(hi, (const void**)&key, NULL, &val);

			AXIS2_FREE(env->allocator, key);
			AXIS2_FREE(env->allocator, val);
		}
		axutil_hash_free(rest_client->cached_entries, env);
	}

	/* freeing the keys, and the value are just numbers */
	if(rest_client->cached_entries_len)
	{
		axutil_hash_index_t *hi;
		void *val;
		void *key;
		int sum = 0;
		for (hi = axutil_hash_first(rest_client->cached_entries_len, env); hi; hi = axutil_hash_next(env, hi)) {
			axutil_hash_this(hi, (const void**)&key, NULL, &val);

			AXIS2_FREE(env->allocator, key);
		}
		axutil_hash_free(rest_client->cached_entries_len, env);
	}

	/* freeing the keys, and the value are also should be freed*/
	if(rest_client->etags)
	{
		axutil_hash_index_t *hi;
		void *val;
		void *key;
		int sum = 0;
		for (hi = axutil_hash_first(rest_client->etags, env); hi; hi = axutil_hash_next(env, hi)) {
			axutil_hash_this(hi, (const void**)&key, NULL, &val);

			AXIS2_FREE(env->allocator, key);
			AXIS2_FREE(env->allocator, val);
		}
		axutil_hash_free(rest_client->etags, env);
	}

    if(rest_client->cached_order)
    {
        int i;
        void *cached_url;
        for(i = 0; i < axutil_array_list_size(rest_client->cached_order, env); i ++)
        {
            cached_url = axutil_array_list_get(rest_client->cached_order, env, i);
            AXIS2_FREE(env->allocator, cached_url);
        }
	    axutil_array_list_free(rest_client->cached_order, env);
    }

	if(rest_client->reverse_cached_order)
	{
		axutil_hash_index_t *hi;
		void *val;
		void *key;
		int sum = 0;
		for (hi = axutil_hash_first(rest_client->reverse_cached_order, env); hi; hi = axutil_hash_next(env, hi)) {
			axutil_hash_this(hi, (const void**)&key, NULL, &val);
			AXIS2_FREE(env->allocator, key);
		}
		axutil_hash_free(rest_client->reverse_cached_order, env);
	}

	/* we are keeping the cached entries key to the cached_entries_len
	* so no need to re free */
	axutil_hash_free(rest_client->cached_entries_len, env);

	AXIS2_FREE(env->allocator, rest_client);

	return AXIS2_SUCCESS;
}


AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
remote_registry_rest_client_get(
								remote_registry_rest_client_t *rest_client,
								const axutil_env_t *env,
								const axis2_char_t *url,
								const axutil_array_list_t *params,
								int relative,
								int *content_len)
{
	axis2_char_t *ret = NULL;
	int size = 0, i = 0;
	axis2_char_t *params_str = NULL;
	axis2_char_t *temp_str = NULL;
	axis2_status_t status = AXIS2_FAILURE;
	axis2_char_t *url_modified = NULL;
	long status_code;
	axis2_char_t *uname_passwd = NULL;

	/* to indicate the current request is cached */
	int cached = 0;
	int retrieved_from_cached = 0;
	remote_registry_conf_t *conf = NULL;

	conf  = rest_client->conf;
	if(params)
	{
		size = axutil_array_list_size((axutil_array_list_t *) params, env);
		params_str = axutil_strdup(env, "?");
	}

	/* preparing the url from the parameters */
	for(i = 0; i < size; i++)
	{
		remote_registry_url_param_t *url_param = NULL;
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
	if(relative) 
	{
		url_modified = axutil_strcat(env, remote_registry_conf_get_reg_url(rest_client->conf, env), 
			REMOTE_REGISTRY_BASE_URL_POSTFIX, url, params_str, NULL);
	}
	else
	{
		url_modified = axutil_strcat(env, url, params_str, NULL);
	}


	/* setting the username password */
	if(conf && remote_registry_conf_get_username(conf, env))
	{

		uname_passwd = axutil_strcat(env, remote_registry_conf_get_username(conf, env),
			":",
			remote_registry_conf_get_password(conf, env), 
			NULL);

	}

	/* TODO: check the caching here */
	status_code = remote_registry_rest_client_get_only_if_modified(
		rest_client, env, url_modified, 
		uname_passwd, &ret, content_len);

	if(status_code == 304) {
		/* retrive it from the cache */

		/* no modifications, so use the cache */

		axis2_char_t *prev_cache = NULL;
		axis2_char_t *prev_cache_dup = NULL;
		int prev_cache_len = 0;
		axis2_char_t *prev_cache_time = NULL;

		/* retrieving the values from the cache */
		prev_cache = axutil_hash_get(rest_client->cached_entries, url_modified, AXIS2_HASH_KEY_STRING);
		prev_cache_len = (int)axutil_hash_get(rest_client->cached_entries_len, url_modified, AXIS2_HASH_KEY_STRING);

		if(prev_cache) {
			/* when caching we keep a null character at the end, need to retrieve with that */
			prev_cache_dup = (axis2_char_t*)AXIS2_MALLOC(env->allocator, prev_cache_len + sizeof(axis2_char_t));
			memcpy(prev_cache_dup, prev_cache, prev_cache_len + sizeof(axis2_char_t));

			ret = prev_cache_dup;
			*content_len = prev_cache_len;

			retrieved_from_cached = 1;
			rest_client->last_response_status = AXIS2_SUCCESS;
		}
		else {
			/* if the cache doesn't exist, we anyway need to call the service */
			retrieved_from_cached = 0;
		}

	}

	if(!retrieved_from_cached && status_code != 200) {

		/* otherwise (including 200 OK,  we  better go and check for the server */
		remote_registry_rest_client_get_internal(rest_client, env, 
			url_modified, 
			uname_passwd, &ret, content_len, NULL);
	}

	if(uname_passwd) 
	{
		AXIS2_FREE(env->allocator, uname_passwd);
	}
	if(params_str)
	{
		AXIS2_FREE(env->allocator, params_str);
	}
	AXIS2_FREE(env->allocator, url_modified);

	return ret;
}

/* implementation of the callback */


AXIS2_EXTERN axis2_status_t AXIS2_CALL 
remote_registry_rest_client_post(
								 remote_registry_rest_client_t *rest_client,
								 const axutil_env_t *env,
								 const axis2_char_t *url,
								 const axis2_char_t *data,
								 int data_len,
								 const axis2_char_t *custom_headers)
{
	CURL *curl_handle;
	CURLcode res;
	axis2_status_t status = AXIS2_FAILURE;
	remote_registry_conf_t *conf = NULL;
	axis2_char_t *uname_passwd = NULL;
	axis2_char_t *url_modified = NULL;
	struct curl_slist *headers=NULL;


	conf  = rest_client->conf;


	url_modified = axutil_strcat(env, remote_registry_conf_get_reg_url(rest_client->conf, env), 
		REMOTE_REGISTRY_BASE_URL_POSTFIX, url, NULL);
	if(!url_modified)
	{
		return AXIS2_FAILURE;
	}

	curl_handle = curl_easy_init();
	if(curl_handle)
	{
		if(custom_headers)
		{
			headers = curl_slist_append(headers, custom_headers);
			curl_easy_setopt(curl_handle, CURLOPT_HTTPHEADER, headers);

		}
		curl_easy_setopt(curl_handle, CURLOPT_URL, url_modified);

		curl_easy_setopt(curl_handle, CURLOPT_POST, 1);
		curl_easy_setopt(curl_handle, CURLOPT_POSTFIELDS, data);
		curl_easy_setopt(curl_handle, CURLOPT_POSTFIELDSIZE, data_len);

		/*curl_easy_setopt(curl_handle, CURLOPT_RETURNTRANSFER, 1);*/
		curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, REMOTE_REGISTRY_USER_AGENT);


		if(conf && remote_registry_conf_get_username(conf, env))
		{

			uname_passwd = axutil_strcat(env, remote_registry_conf_get_username(conf, env),
				":",
				remote_registry_conf_get_password(conf, env), 
				NULL);

			curl_easy_setopt(curl_handle, CURLOPT_USERPWD, uname_passwd);
		}

		res = curl_easy_perform(curl_handle);
		if(res == CURLE_OK)
		{
			res = curl_easy_getinfo(curl_handle, CURLINFO_RESPONSE_CODE, &rest_client->last_response_status);
			if(res != CURLE_OK)
			{
				status = AXIS2_FAILURE;
			}
		}

		/* always cleanup */
		curl_easy_cleanup(curl_handle);
	}
	if(uname_passwd)
	{
		AXIS2_FREE(env->allocator, uname_passwd);
	}
	AXIS2_FREE(env->allocator, url_modified);

	if(headers)
	{ 
		curl_slist_free_all(headers); /* free the header list */ 
	}

	return status;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL 
remote_registry_rest_client_put(
								remote_registry_rest_client_t *rest_client,
								const axutil_env_t *env,
								const axis2_char_t *url,
								const axis2_char_t *data,
								int data_len,
								const axis2_char_t *custom_headers)
{
	CURL *curl_handle;
	CURLcode res;
	axis2_status_t status = AXIS2_FAILURE;
	remote_registry_conf_t *conf = NULL;
	axis2_char_t *uname_passwd = NULL;
	axis2_char_t *url_modified = NULL;
	struct curl_slist *headers=NULL;

	remote_registry_rest_client_callbk_param_t callbk_param;
	conf  = rest_client->conf;


	url_modified = axutil_strcat(env, remote_registry_conf_get_reg_url(rest_client->conf, env), 
		REMOTE_REGISTRY_BASE_URL_POSTFIX, url, NULL);
	if(!url_modified)
	{
		return AXIS2_FAILURE;
	}

	curl_handle = curl_easy_init();
	if(curl_handle)
	{
		if(custom_headers)
		{
			headers = curl_slist_append(headers, custom_headers);
			curl_easy_setopt(curl_handle, CURLOPT_HTTPHEADER, headers);

		}
		curl_easy_setopt(curl_handle, CURLOPT_URL, url_modified);

		// preparing the callback for the read function
		callbk_param.buffer = (axis2_char_t*)data;
		callbk_param.buffer_len = data_len;
		callbk_param.env = env;
		curl_easy_setopt(curl_handle, CURLOPT_UPLOAD, 1);
		curl_easy_setopt(curl_handle, CURLOPT_READDATA, &callbk_param);
		curl_easy_setopt(curl_handle, CURLOPT_INFILESIZE, data_len);
		curl_easy_setopt(curl_handle, CURLOPT_READFUNCTION, remote_registry_rest_client_read_data);

		curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, REMOTE_REGISTRY_USER_AGENT);


		if(conf && remote_registry_conf_get_username(conf, env))
		{

			uname_passwd = axutil_strcat(env, remote_registry_conf_get_username(conf, env),
				":",
				remote_registry_conf_get_password(conf, env), 
				NULL);

			curl_easy_setopt(curl_handle, CURLOPT_USERPWD, uname_passwd);
		}

		res = curl_easy_perform(curl_handle);
		if(res == CURLE_OK)
		{
			res = curl_easy_getinfo(curl_handle, CURLINFO_RESPONSE_CODE, &rest_client->last_response_status);
			if(res != CURLE_OK)
			{
				status = AXIS2_FAILURE;
			}
		}

		/* always cleanup */
		curl_easy_cleanup(curl_handle);
	}
	if(uname_passwd)
	{
		AXIS2_FREE(env->allocator, uname_passwd);
	}
	AXIS2_FREE(env->allocator, url_modified);

	if(headers)
	{ 
		curl_slist_free_all(headers); /* free the header list */ 
	}

	return status;
}


size_t static remote_registry_rest_client_read_data(void *buffer, 
													size_t size, 
													size_t nmemb, 
													void *userp)
{
	remote_registry_rest_client_callbk_param_t *param = (remote_registry_rest_client_callbk_param_t*)userp;

	if(size*nmemb < 1) 
	{
		return 0;
	}
	if(param->buffer_len <= 0)
	{
		*(char*)buffer = '\0';
		return 0;
	}

	if(size) {
		int min_to_transfer = param->buffer_len;

		// setup the min to transfer
		if(min_to_transfer > (int)size *nmemb) {
			min_to_transfer = (int)size*nmemb;
		}
		memcpy(buffer, param->buffer, min_to_transfer); /* copy evertything at once */


		param->buffer += min_to_transfer;                /* advance pointer */
		param->buffer_len -= min_to_transfer;                /* less data left */
		return min_to_transfer;                        /* we return the bytes transferring! */
	}

	return -1;                        /* no more data left to deliver */

	return nmemb;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
remote_registry_rest_client_delete(
								   remote_registry_rest_client_t *rest_client,
								   const axutil_env_t *env,
								   const axis2_char_t *url,
								   const axutil_array_list_t *params)
{
	CURL *curl_handle;
	CURLcode res;
	int size = 0, i = 0;
	axis2_char_t *params_str = NULL;
	axis2_char_t *url_modified = NULL;
	axis2_status_t status = AXIS2_FAILURE;
	remote_registry_conf_t *conf = NULL;
	axis2_char_t *uname_passwd = NULL;

	conf  = rest_client->conf;

	if(params)
	{
		size = axutil_array_list_size((axutil_array_list_t *) params, env);
		params_str = axutil_strdup(env, "?");
	}

	for(i = 0; i < size; i++)
	{
		remote_registry_url_param_t *url_param = NULL;
		axis2_char_t *key = NULL;
		axis2_char_t *encoded_key = NULL;
		axis2_char_t *value = NULL;
		axis2_char_t *encoded_value = NULL;
		axis2_char_t *temp_str = NULL;

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

	url_modified = axutil_strcat(env, remote_registry_conf_get_reg_url(rest_client->conf, env), 
		REMOTE_REGISTRY_BASE_URL_POSTFIX, url, params_str, NULL);

	if(!url_modified)
	{
		return AXIS2_FAILURE;
	}

	curl_handle = curl_easy_init();
	if(curl_handle)
	{
		curl_easy_setopt(curl_handle, CURLOPT_URL, url_modified);
		curl_easy_setopt(curl_handle, CURLOPT_CUSTOMREQUEST, "DELETE");
		curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, REMOTE_REGISTRY_USER_AGENT);

		if(conf && remote_registry_conf_get_username(conf, env))
		{

			uname_passwd = axutil_strcat(env, remote_registry_conf_get_username(conf, env),
				":",
				remote_registry_conf_get_password(conf, env), 
				NULL);

			curl_easy_setopt(curl_handle, CURLOPT_USERPWD, uname_passwd);
		}



		res = curl_easy_perform(curl_handle);
		if(res == CURLE_OK)
		{
			res = curl_easy_getinfo(curl_handle, CURLINFO_RESPONSE_CODE, &rest_client->last_response_status);
			if(res != CURLE_OK)
			{
				status = AXIS2_FAILURE;
			}
		}

		/* always cleanup */
		curl_easy_cleanup(curl_handle);
	}
	if(uname_passwd)
	{
		AXIS2_FREE(env->allocator, uname_passwd);
	}
	AXIS2_FREE(env->allocator, url_modified);

	return status;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_rest_client_get_last_response_status(
	remote_registry_rest_client_t *rest_client,
	const axutil_env_t *env)
{
	return rest_client->last_response_status;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
remote_registry_rest_client_get_last_response_content_type(
	remote_registry_rest_client_t *rest_client,
	const axutil_env_t *env)
{
	return rest_client->last_response_content_type;
}

axis2_status_t static
remote_registry_rest_client_set_cache(
									  remote_registry_rest_client_t *rest_client,
									  const axutil_env_t *env,
									  const axis2_char_t *url,
									  axis2_char_t *buffer, 
									  int buffer_len, 
									  axis2_char_t* new_etag)
{
	axis2_char_t *prev_cache = NULL;
	axis2_char_t *prev_cache_etag = NULL;
	int cache_replacing = 0;
	axis2_char_t *early_url = NULL;
	axis2_char_t *url_dup = NULL;
	axis2_char_t *buffer_dup = NULL;

    /* updating the env for all the hashes */
    axutil_hash_set_env(rest_client->cached_entries, env);
    axutil_hash_set_env(rest_client->cached_entries_len, env);
    axutil_hash_set_env(rest_client->etags, env);
    axutil_hash_set_env(rest_client->reverse_cached_order, env);

	/* check wether there were any old entries, if so free them */
	prev_cache = axutil_hash_get(rest_client->cached_entries, url, AXIS2_HASH_KEY_STRING);

	/* freeing the old entries */
	if(prev_cache)
	{
		int prev_cache_index;
		/* set a flag to identify that we replace already existed one */
		cache_replacing = 1;
		AXIS2_FREE(env->allocator, prev_cache);

		/* now we are going to check the place of it in the cached index */
		prev_cache_index = (int)axutil_hash_get(rest_client->reverse_cached_order, url, AXIS2_HASH_KEY_STRING);

		/* the value of the url and early_url is same, but different pointers */
		early_url = axutil_array_list_get(rest_client->cached_order, env, prev_cache_index);
		AXIS2_FREE(env->allocator, early_url);

        /* the reverse cache order will be cleard at the time it is overwritten */

		/* checking the next to clear (because of out of LIMIT) */
		early_url = axutil_array_list_get(rest_client->cached_order, env, rest_client->cached_order_index);
		if(early_url)
		{
			/* so actually we need to erase the existing one, rather we promot it to the prev_cache_index
			   so non of the cache will be erased other than the one that got replaced */
			axutil_array_list_set(rest_client->cached_order, env, prev_cache_index, early_url);
            early_url = axutil_strdup(env, early_url);
			axutil_hash_set(rest_client->reverse_cached_order, early_url, AXIS2_HASH_KEY_STRING, (void*)prev_cache_index);
		}

		/* and we are going to put our current url to the rest_client->cached_order_index */
		url_dup = axutil_strdup(env, url);
		axutil_array_list_set(rest_client->cached_order, env, rest_client->cached_order_index, url_dup);
		url_dup = axutil_strdup(env, url);
		axutil_hash_set(rest_client->reverse_cached_order, url_dup, AXIS2_HASH_KEY_STRING, (void*)rest_client->cached_order_index);
	}

	if(!cache_replacing)
	{
		int prev_cache_len;

		/* now we have to consider the limit of the cache for non-replacing case */
		early_url = axutil_array_list_get(rest_client->cached_order, env, rest_client->cached_order_index);
		if(early_url)
		{
			/* we have to remove this url for fit within the cache url */
			prev_cache = axutil_hash_get(rest_client->cached_entries, early_url, AXIS2_HASH_KEY_STRING);
			if(prev_cache)
			{
				AXIS2_FREE(env->allocator, prev_cache);
				axutil_hash_set(rest_client->cached_entries, early_url, AXIS2_HASH_KEY_STRING, NULL);
			}

			prev_cache_etag = axutil_hash_get(rest_client->etags, early_url, AXIS2_HASH_KEY_STRING);
			if(prev_cache_etag)
			{
				AXIS2_FREE(env->allocator, prev_cache_etag);
				axutil_hash_set(rest_client->etags, early_url, AXIS2_HASH_KEY_STRING, NULL);
			}

			prev_cache_len = (int)axutil_hash_get(rest_client->cached_entries_len, early_url, AXIS2_HASH_KEY_STRING);
			if(prev_cache_len)
			{
				axutil_hash_set(rest_client->cached_entries_len, early_url, AXIS2_HASH_KEY_STRING, NULL);
			}

			/* as the last we remove it from the order as well */
			axutil_hash_set(rest_client->reverse_cached_order, early_url, AXIS2_HASH_KEY_STRING, NULL);
			AXIS2_FREE(env->allocator, early_url);

            /* and we put our values in there */
            url_dup = axutil_strdup(env, url);
            axutil_array_list_set(rest_client->cached_order, env, rest_client->cached_order_index, url_dup);
            url_dup = axutil_strdup(env, url);
            axutil_hash_set(rest_client->reverse_cached_order, url_dup, AXIS2_HASH_KEY_STRING, (void*)rest_client->cached_order_index);
		}
        else {
            /* if no replacing is hapenning we can add the url to cached_order */
            url_dup = axutil_strdup(env, url);
            axutil_array_list_add(rest_client->cached_order, env, url_dup);
            url_dup = axutil_strdup(env, url);
            axutil_hash_set(rest_client->reverse_cached_order, url_dup, AXIS2_HASH_KEY_STRING, (void*)rest_client->cached_order_index);
        }
	}
    if(buffer)
    {
		buffer_dup = (axis2_char_t*)AXIS2_MALLOC(env->allocator, buffer_len + sizeof(axis2_char_t));
		memcpy(buffer_dup, buffer, buffer_len + sizeof(axis2_char_t));

		url_dup = axutil_strdup(env, url);
		axutil_hash_set(rest_client->cached_entries, url_dup, AXIS2_HASH_KEY_STRING, buffer_dup);
		url_dup = axutil_strdup(env, url);
		axutil_hash_set(rest_client->cached_entries_len, url_dup, AXIS2_HASH_KEY_STRING, (void*)buffer_len);
	}
	else 
	{
		url_dup = axutil_strdup(env, url);
		axutil_hash_set(rest_client->cached_entries, url_dup, AXIS2_HASH_KEY_STRING, NULL);
		url_dup = axutil_strdup(env, url);
		axutil_hash_set(rest_client->cached_entries_len, url_dup, AXIS2_HASH_KEY_STRING, (void*)0);
	}
	url_dup = axutil_strdup(env, url);
	axutil_hash_set(rest_client->etags, url_dup, AXIS2_HASH_KEY_STRING, new_etag);

	/* we need to increment the cached_order_index in cyclic manner .. */

	rest_client->cached_order_index ++;
	if(rest_client->cached_order_index >= remote_registry_conf_get_cache_entries_limit(rest_client->conf, env))
	{
		rest_client->cached_order_index = 0;
	}

	return AXIS2_SUCCESS;
}

AXIS2_EXTERN long AXIS2_CALL 
remote_registry_rest_client_head(remote_registry_rest_client_t *rest_client,
								 const axutil_env_t *env,
								 const axis2_char_t *url,
								 int relative)
{
	axis2_char_t *url_modified = NULL;
	remote_registry_conf_t *conf = NULL;
	axis2_char_t *uname_passwd = NULL;
	long status_code;
	CURL *curl_handle;
	CURLcode res;

	conf = rest_client->conf;

	if(relative) 
	{
		url_modified = axutil_strcat(env, remote_registry_conf_get_reg_url(rest_client->conf, env), 
			REMOTE_REGISTRY_BASE_URL_POSTFIX, url, NULL);
	}
	else
	{
		url_modified = axutil_strcat(env, url, NULL);
	}

	if(!url_modified) 
	{
		return -1;
	}

	/* setting the username password */
	if(conf && remote_registry_conf_get_username(conf, env))
	{

		uname_passwd = axutil_strcat(env, remote_registry_conf_get_username(conf, env),
			":",
			remote_registry_conf_get_password(conf, env), 
			NULL);

	}

	curl_handle = curl_easy_init();

	if(curl_handle)
	{
		curl_easy_setopt(curl_handle, CURLOPT_URL, url_modified);
		//curl_easy_setopt(curl_handle, CURLOPT_VERBOSE, 1);
		curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, REMOTE_REGISTRY_USER_AGENT);

		if(uname_passwd)
		{
			curl_easy_setopt(curl_handle, CURLOPT_USERPWD, uname_passwd);
		}

		curl_easy_setopt(curl_handle, CURLOPT_HEADER, 1);
		curl_easy_setopt(curl_handle, CURLOPT_NOBODY, 1);


		curl_easy_setopt(curl_handle, CURLOPT_SSL_VERIFYPEER, 0);
		curl_easy_setopt(curl_handle, CURLOPT_SSL_VERIFYHOST, 0);

		res = curl_easy_perform(curl_handle);
		if(res == CURLE_OK) 
		{
			curl_easy_getinfo(curl_handle, CURLINFO_RESPONSE_CODE, &status_code);
		}
		else {
			status_code = -1;
		}

	}
	else {
		status_code = -1; /* no success */
	}


	/* always cleanup */
	curl_easy_cleanup(curl_handle);
	if(uname_passwd) 
	{
		AXIS2_FREE(env->allocator, uname_passwd);
	}
	AXIS2_FREE(env->allocator, url_modified);

	return status_code;
}


static long
remote_registry_rest_client_get_only_if_modified(
	remote_registry_rest_client_t *rest_client,
	const axutil_env_t *env,
	const axis2_char_t *url,
	axis2_char_t *uname_passwd,
	axis2_char_t **buffer,
	int *content_len) 
{
	long status_code;
	axis2_char_t *last_etag = NULL;
	struct curl_slist *headers = NULL;
	axis2_char_t *if_none_match_header = NULL;

	/* get the last updated time, if the cache entry exist */
	last_etag =  axutil_hash_get(rest_client->etags, url, AXIS2_HASH_KEY_STRING);

	/* if the last updated time doesn't exist*/
	if(!last_etag)
	{
		return -1;
	}

	/* if the last etag exists, add it to the if-none-match header */
	if_none_match_header = axutil_strcat(env, "if-none-match: ", last_etag, NULL);
	if(if_none_match_header) 
	{
		headers = curl_slist_append(headers, if_none_match_header);

		AXIS2_FREE(env->allocator, if_none_match_header);
	}
	/* no need to sending the prior request */
	if(!headers) 
	{
		return -1;
	}

	status_code = remote_registry_rest_client_get_internal(rest_client, 
													env, 
													url, 
													uname_passwd, 
													buffer, content_len, 
													headers);

	if(headers)
	{ 
		curl_slist_free_all(headers); /* free the header list */ 
	}

	return status_code;
}

static long
remote_registry_rest_client_get_internal(
	remote_registry_rest_client_t *rest_client,
	const axutil_env_t *env,
	const axis2_char_t *url,
	axis2_char_t *uname_passwd,
	axis2_char_t **buffer,
	int *content_len,
	struct curl_slist *headers)
{
	long status_code = -1;
	CURL *curl_handle;
	CURLcode res;

	curl_handle = curl_easy_init();
	if(curl_handle)
	{
		axis2_char_t *response_content_type = NULL;

		remote_registry_rest_client_callbk_param_t callbk_param;
		memset(&callbk_param, 0, sizeof(callbk_param));

		curl_easy_setopt(curl_handle, CURLOPT_URL, url);
		//curl_easy_setopt(curl_handle, CURLOPT_VERBOSE, 1);
		curl_easy_setopt(curl_handle, CURLOPT_HTTPGET, 1);
		curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, REMOTE_REGISTRY_USER_AGENT);

		/* we need to know the headers as well */
		curl_easy_setopt(curl_handle, CURLOPT_HEADER, 1);

		if(uname_passwd)
		{
			curl_easy_setopt(curl_handle, CURLOPT_USERPWD, uname_passwd);
		}

		if(remote_registry_conf_get_conn_timeout(rest_client->conf, env)) 
		{
#ifdef CURLOPT_TIMEOUT_MS
			curl_easy_setopt(curl_handle, CURLOPT_TIMEOUT_MS, remote_registry_conf_get_conn_timeout(rest_client->conf, env));
#endif
		}
		/* setting the callback */
		curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, remote_registry_rest_client_write_data);
		if(headers)
		{
			curl_easy_setopt(curl_handle, CURLOPT_HTTPHEADER, headers);
		}

		/* preparing the parameter for the callback */
		callbk_param.env = env;
		curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, &callbk_param);

		curl_easy_setopt(curl_handle, CURLOPT_SSL_VERIFYPEER, 0);
		curl_easy_setopt(curl_handle, CURLOPT_SSL_VERIFYHOST, 0);
		res = curl_easy_perform(curl_handle);

		if(res == CURLE_OK) 
		{
			axis2_char_t *new_etag = NULL;
			int header_len= 0;
			axis2_char_t *headers_buffer = NULL;
			axis2_char_t *content = NULL;
			curl_easy_getinfo(curl_handle, CURLINFO_RESPONSE_CODE, &status_code);
			curl_easy_getinfo(curl_handle, CURLINFO_CONTENT_TYPE, &response_content_type);
			curl_easy_getinfo(curl_handle, CURLINFO_HEADER_SIZE, &header_len);
			if(status_code == 200)
			{
				rest_client->last_response_status = AXIS2_SUCCESS;
				rest_client->last_response_content_type = axutil_strdup(env, response_content_type);

				if(header_len > 0 && callbk_param.buffer)
				{
					/* deviding the output to header and content */
					*(callbk_param.buffer + header_len -1) = '\0';
					callbk_param.buffer_len -= header_len;

					content = AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t*)* (callbk_param.buffer_len + 1));
					memcpy(content, callbk_param.buffer + header_len, callbk_param.buffer_len + 1);
					headers_buffer = callbk_param.buffer;
					new_etag = remote_registry_rest_client_extract_etag_info(env, headers_buffer);
					AXIS2_FREE(env->allocator, callbk_param.buffer);
				}
				else {
					/* no header is retrieved */
					content = callbk_param.buffer;
				}
				*buffer = content;

				if(content_len)
				{
					*content_len = callbk_param.buffer_len;
				}

				/* do the caching */
				remote_registry_rest_client_set_cache(rest_client, env, url, *buffer, *content_len, new_etag);
			}
			else
			{
				rest_client->last_response_status = AXIS2_FAILURE;
			}
		}
		else 
		{
			AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
		}

		/* always cleanup */
		curl_easy_cleanup(curl_handle);
	}
	return status_code;
}

size_t static remote_registry_rest_client_write_data(void *buffer, size_t size, size_t nmemb, void *userp)
{
	int new_length = 0;
	remote_registry_rest_client_callbk_param_t *param = (remote_registry_rest_client_callbk_param_t*)userp;

	new_length = size * nmemb *sizeof(axis2_char_t);

	/*we allocting one extra by to keep the \0 */
	if(param->buffer_len == 0)
	{
		/* allocate new memeory */
		param->buffer = (axis2_char_t*)AXIS2_MALLOC(param->env->allocator,
			new_length + sizeof(axis2_char_t));
	}
	else 
	{
		/* reallocate memory */
		axis2_char_t *buffer_ptr = param->buffer;

		param->buffer = (axis2_char_t*)AXIS2_MALLOC(param->env->allocator,
			new_length + param->buffer_len + sizeof(axis2_char_t));
		memcpy(param->buffer, buffer_ptr, param->buffer_len);
		AXIS2_FREE(param->env->allocator, buffer_ptr);
	}

	memcpy(param->buffer + param->buffer_len, buffer, new_length);

	param->buffer_len += new_length;
	param->buffer[param->buffer_len] = '\0';

	return nmemb;
}

static axis2_char_t*
remote_registry_rest_client_extract_etag_info(const axutil_env_t *env, axis2_char_t *buffer)
{
	axis2_char_t *etag_value = NULL;
	etag_value = axutil_strstr(buffer, REMOTE_REGISTRY_ETAG_HADER_KEY);

	if(etag_value) {
		axis2_char_t *c;
		/* get until the etag start */
		etag_value += sizeof(REMOTE_REGISTRY_ETAG_HADER_KEY) -1;
		/* find the line end */
		for(c = etag_value; *c != '\0'  && *c != '\r'; c ++);
		*c = '\0';
		etag_value = axutil_strdup(env, etag_value);
	}
	return etag_value;
}
