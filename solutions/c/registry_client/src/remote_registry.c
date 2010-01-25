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
#include <remote_registry_rest_client.h>
#include <axutil_utils.h>
#include <axiom.h>
#include <remote_registry_util.h>
#include <remote_registry.h>



/** 
 * @brief remote_registry struct impl
 */
struct remote_registry
{
    remote_registry_rest_client_t *rest_client;
    remote_registry_conf_t *conf;
    axiom_node_t *last_feed_xml;

};

/* internally used function */
static axis2_status_t
remote_registry_load_child_resources(
            remote_registry_t *remote_registry,
            const axutil_env_t *env,
            remote_registry_resource_t *resource);

/* implemenation of the public function */
AXIS2_EXTERN remote_registry_t* AXIS2_CALL
remote_registry_create(
    const axutil_env_t *env,
    axis2_char_t *url,
    axis2_char_t *username,
    axis2_char_t *password)
{
	remote_registry_conf_t *conf = NULL;
	remote_registry_t *remote_registry = NULL;

	conf = remote_registry_conf_create(env);

	if(!conf) {
        return NULL;
	}
	remote_registry_conf_set_reg_url(conf, env, url);
	remote_registry_conf_set_username(conf, env, username);
	remote_registry_conf_set_password(conf, env, password);

	remote_registry = remote_registry_create_with_conf(env, conf);

	return remote_registry;
}
 
AXIS2_EXTERN remote_registry_t *AXIS2_CALL
remote_registry_create_with_conf(
    const axutil_env_t *env,
    remote_registry_conf_t *conf)
{

    remote_registry_t *remote_registry = NULL;

    remote_registry = (remote_registry_t *)AXIS2_MALLOC(env->allocator,
            sizeof(remote_registry_t));

    if(!remote_registry)
    {
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    /* registry client doesn't exist without the conf */
    remote_registry->conf = conf;
    remote_registry->last_feed_xml;


    remote_registry->rest_client = remote_registry_rest_client_create(env, conf);

    return remote_registry;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
remote_registry_free(
    remote_registry_t *remote_registry,
    const axutil_env_t *env)
{
    if(remote_registry->conf)
    {
        remote_registry_conf_free(remote_registry->conf, env);
        remote_registry->conf = NULL;
    }
    
    if(remote_registry->last_feed_xml)
    {
        axiom_node_free_tree(remote_registry->last_feed_xml, env);
        remote_registry->last_feed_xml = NULL;
    }

    if(remote_registry->rest_client)
    {
        remote_registry_rest_client_free(remote_registry->rest_client, env);
    }

	AXIS2_FREE(env->allocator, remote_registry); 
    
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN remote_registry_resource_t *AXIS2_CALL 
remote_registry_get(
                remote_registry_t *remote_registry,
                const axutil_env_t *env,
                axis2_char_t *url,
                axutil_array_list_t *params) 
{
    remote_registry_resource_t *res = NULL;
    axis2_char_t *buffer = NULL;
    axis2_status_t status;
    axis2_char_t *content_type = NULL;
    int buffer_len = 0;
    
    buffer = remote_registry_rest_client_get(remote_registry->rest_client, env, url, params, 1, &buffer_len);

    status = remote_registry_rest_client_get_last_response_status(remote_registry->rest_client, env);
    content_type = remote_registry_rest_client_get_last_response_content_type(remote_registry->rest_client, env);


    if(status == AXIS2_SUCCESS) 
	{
		res = remote_registry_resource_create_from_feed(env, buffer, content_type);
        if(res)
        {
		    remote_registry_resource_set_rest_client(res, env, remote_registry->rest_client);
        }
    }

    if(buffer) {
        AXIS2_FREE(env->allocator, buffer);
    }

    return res;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_load_content_for_resource(
        remote_registry_t *remote_registry,
        const axutil_env_t *env,
        remote_registry_resource_t *resource)
{
    axis2_status_t status;
    axis2_char_t *buffer = NULL;
    axis2_char_t *content_type = NULL;
    int buffer_len = 0;
	
    axis2_char_t *content_src_url = NULL;

    content_src_url = remote_registry_resource_get_content_src_url(resource, env);

    if(!content_src_url) /* indicates that this is a directory */
    {
        axis2_char_t *link_path = NULL;
        link_path = remote_registry_resource_get_link_path(resource, env);

        if(!link_path) 
		{
            /* we can't access the resouce content */
            return AXIS2_FAILURE;
        }

        buffer = remote_registry_rest_client_get(remote_registry->rest_client, env, link_path, NULL, 1, &buffer_len);
        status = remote_registry_rest_client_get_last_response_status(remote_registry->rest_client, env);
        content_type = remote_registry_rest_client_get_last_response_content_type(remote_registry->rest_client, env);

        if(status == AXIS2_SUCCESS) 
		{
            axiom_node_t *feed_node = NULL;

            feed_node = axiom_node_create_from_buffer(env, buffer);
            remote_registry_resource_load_metadata_from_feed_node(env, resource, feed_node);
        }

        if(buffer) 
		{
            AXIS2_FREE(env->allocator, buffer);
        }
    }
    else {

        if(!content_src_url) 
		{
            /* we can't access the resouce content */
            return AXIS2_FAILURE;
        }

        buffer = remote_registry_rest_client_get(remote_registry->rest_client, env, content_src_url, NULL, 0, &buffer_len);
        status = remote_registry_rest_client_get_last_response_status(remote_registry->rest_client, env);
        content_type = remote_registry_rest_client_get_last_response_content_type(remote_registry->rest_client, env);

        if(status == AXIS2_SUCCESS) 
		{
            remote_registry_resource_set_is_content_loaded(resource, env, 1);
            remote_registry_resource_set_content(resource, env, buffer);
            remote_registry_resource_set_content_len(resource, env, buffer_len);
        }
    }
	return AXIS2_SUCCESS;
}


AXIS2_EXTERN remote_registry_resource_t *AXIS2_CALL 
remote_registry_get_recursively(
                remote_registry_t *remote_registry,
                const axutil_env_t *env,
                axis2_char_t *url,
                axutil_array_list_t *params) 

{
    remote_registry_resource_t *root_resource = NULL;

    root_resource = remote_registry_get(remote_registry,
                        env,
                        url,
                        params);

    if(root_resource) 
	{
        remote_registry_load_child_resources(remote_registry, env, root_resource);
    }

    return root_resource;
}



static axis2_status_t
remote_registry_load_child_resources(
            remote_registry_t *remote_registry,
            const axutil_env_t *env,
            remote_registry_resource_t *resource)
{
    axutil_array_list_t *child_entries = NULL;
    int i = 0;

    child_entries = remote_registry_resource_get_entries(resource, env);

    if(child_entries)
    {
        /* load the child entries recursively */
        for(i = 0; i < axutil_array_list_size(child_entries, env); i ++)
        {
            remote_registry_resource_t *child_resource = NULL;
            child_resource = (remote_registry_resource_t*)axutil_array_list_get(child_entries, env, i);

            /* loading the resources */
            remote_registry_load_content_for_resource(remote_registry, env, child_resource);
            
            /* now do the same for the childs as well */
            remote_registry_load_child_resources(remote_registry, env, child_resource);
        }
    }

	return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
remote_registry_delete(
                remote_registry_t *remote_registry,
                const axutil_env_t *env,
                axis2_char_t *path)
{
    return remote_registry_rest_client_delete(remote_registry->rest_client, env, path, NULL);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
remote_registry_put(
                remote_registry_t *remote_registry,
                const axutil_env_t *env,
                axis2_char_t *path,
                remote_registry_resource_t *resource)
{
    axiom_node_t *node = NULL;
    axis2_char_t *node_str = NULL;
    axis2_char_t *custom_headers = NULL;
	axis2_status_t status = AXIS2_FAILURE;

	axis2_char_t *ri = NULL;
	axis2_char_t *id = NULL;
	axis2_char_t *title = NULL;
	axis2_char_t *author_name = NULL;
	axis2_char_t *path_dup = NULL;

	path_dup = axutil_strdup(env, path);
	if(!path_dup) {
		
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "No memory. Cannot create path");
        return AXIS2_FAILURE;
	}

	/* first of all check for the required fields */
	id = remote_registry_resource_get_id(resource, env);
	if(!id) {
		id = axutil_strcat(env, remote_registry_conf_get_reg_url(remote_registry->conf, env),
						REMOTE_REGISTRY_BASE_URL_POSTFIX, path_dup, NULL);
		remote_registry_resource_set_id(resource, env, id);
	}
	title = remote_registry_resource_get_title(resource, env);
	if(!title) {
		remote_registry_resource_set_title(resource, env, path_dup);
	}
	author_name = remote_registry_resource_get_author_name(resource, env);
	if(!author_name) {
		remote_registry_resource_set_author_name(resource, env, 
				remote_registry_conf_get_username(remote_registry->conf, env));
	}

	ri = axutil_rindex(path_dup, '/');

	if(ri) {
		axis2_char_t *resource_name = NULL;
		axis2_char_t *parent_path = NULL;

		*ri = '\0';

		/* setting the parent path */
		parent_path = remote_registry_resource_get_parent_path(resource, env);
		if(!parent_path)
		{
			parent_path = path_dup;
			remote_registry_resource_set_parent_path(resource, env, parent_path);
		}

		/* setting the resource name */
		resource_name = ri + 1;
		
		node = remote_registry_resource_serialize(resource, env);
		node_str = axiom_node_to_string(node, env);

		if(remote_registry_resource_get_is_collection(resource, env)) 
		{
			custom_headers = axutil_strcat(env, REMOTE_REGISTRY_CONTENT_TYPE_HEADER_NAME
										REMOTE_REGISTRY_FEED_CONTENT_TYPE_SENDING "\r\nSlug: ",
										resource_name, NULL);
		}
		else 
		{
			custom_headers = axutil_strcat(env, REMOTE_REGISTRY_CONTENT_TYPE_HEADER_NAME
										REMOTE_REGISTRY_FEED_ENTRY_CONTENT_TYPE_SENDING "\r\nSlug: ",
										resource_name, NULL);
		}
		if(custom_headers)
		{
			int http_status = 0;
			/* checking for existance */
			http_status = remote_registry_rest_client_head(remote_registry->rest_client, env, path, 1);
			if(http_status == 200)
			{
				/* when we are doing put the url should contain the slug, so getting the original path */
				status = remote_registry_rest_client_put(remote_registry->rest_client, env, path, node_str,
							axutil_strlen(node_str), custom_headers);
			}
			else 
			{
				status = remote_registry_rest_client_post(remote_registry->rest_client, env, path_dup, node_str,
							axutil_strlen(node_str), custom_headers);
			}

			AXIS2_FREE(env->allocator, custom_headers);
		}
		*ri = '/';
	}

	return status;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
remote_registry_post(
                remote_registry_t *remote_registry,
                const axutil_env_t *env,
                axis2_char_t *path,
                remote_registry_resource_t *resource)
{
    axiom_node_t *node = NULL;
    axis2_char_t *node_str = NULL;
    axis2_char_t *custom_headers = NULL;
	axis2_status_t status = AXIS2_FAILURE;

	axis2_char_t *ri = 0;

	path = axutil_strdup(env, path);
	if(!path) {
		
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "No memory. Cannot create path");
        return AXIS2_FAILURE;
	}
	ri = axutil_rindex(path, '/');

	if(ri) {
		axis2_char_t *resource_name = NULL;

		*ri = '\0';
		resource_name = ri + 1;
		
		node = remote_registry_resource_serialize(resource, env);
		node_str = axiom_node_to_string(node, env);

		if(remote_registry_resource_get_is_collection(resource, env)) 
		{
			custom_headers = axutil_strcat(env, REMOTE_REGISTRY_CONTENT_TYPE_HEADER_NAME 
												REMOTE_REGISTRY_FEED_CONTENT_TYPE_SENDING "\r\nSlug: ",
										resource_name, NULL);
		}
		else 
		{
			custom_headers = axutil_strcat(env, REMOTE_REGISTRY_CONTENT_TYPE_HEADER_NAME
												REMOTE_REGISTRY_FEED_ENTRY_CONTENT_TYPE_SENDING "\r\nSlug: ",
										resource_name, NULL);
		}

		if(custom_headers)
		{
			status = remote_registry_rest_client_post(remote_registry->rest_client, env, path, node_str,
						axutil_strlen(node_str), custom_headers);

			AXIS2_FREE(env->allocator, custom_headers);
		}
		*ri = '/';
	}

	return status;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
remote_registry_add_comment(
                remote_registry_t *remote_registry,
                const axutil_env_t *env,
                axis2_char_t *path,
                remote_registry_comment_t *comment)
{
	axis2_char_t *comment_feed = NULL;
	axiom_node_t *comment_node = NULL;
	axis2_char_t *url = NULL;
	axis2_status_t status =  AXIS2_FAILURE;

	comment_node = remote_registry_comment_serialize(comment, env);
	comment_feed = axiom_node_to_string(comment_node, env);

	/* building the url */
	url = axutil_strcat(env, path, REMOTE_REGISTRY_COMMENT_PARAMTER, NULL);
	if(!url) {
		
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "No memory. Cannot create url");
        return AXIS2_FAILURE;
	}
	
	status = remote_registry_rest_client_post(remote_registry->rest_client, env,
						url, comment_feed, axutil_strlen(comment_feed), 
						REMOTE_REGISTRY_CONTENT_TYPE_HEADER_NAME REMOTE_REGISTRY_COMMENT_MEDIA_TYPE);

	return status;
}


AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL 
remote_registry_get_comments(
                remote_registry_t *remote_registry,
                const axutil_env_t *env,
                axis2_char_t *path)
{
    axutil_array_list_t *comments = NULL;
    axis2_char_t *buffer = NULL;
    axis2_status_t status;
    axis2_char_t *content_type = NULL;
	axis2_char_t *url = NULL;
    int buffer_len = 0;
    
	/* building the url */
	url = axutil_strcat(env, path, REMOTE_REGISTRY_COMMENT_PARAMTER, NULL);
	if(!url) {
		
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "No memory. Cannot create url");
        return NULL;
	}
    buffer = remote_registry_rest_client_get(remote_registry->rest_client, env, url, NULL, 1, &buffer_len);

    status = remote_registry_rest_client_get_last_response_status(remote_registry->rest_client, env);
    content_type = remote_registry_rest_client_get_last_response_content_type(remote_registry->rest_client, env);


    if(status == AXIS2_SUCCESS && buffer) {
	    comments = remote_registry_comment_load_from_feed(env, buffer);
    }

    if(buffer) {
        AXIS2_FREE(env->allocator, buffer);
    }
	AXIS2_FREE(env->allocator, url);

    return comments;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL 
remote_registry_rate_resource(
                remote_registry_t *remote_registry,
                const axutil_env_t *env,
                axis2_char_t *path,
                int rate)
{
	axis2_char_t *rate_feed = NULL;
	axiom_node_t *rate_node = NULL;
	axis2_char_t *url = NULL;
	axis2_status_t status =  AXIS2_FAILURE;

	rate_node = remote_registry_util_serialize_rating(env, rate);
	rate_feed = axiom_node_to_string(rate_node, env);

	/* building the url */
	url = axutil_strcat(env, path, REMOTE_REGISTRY_RATING_PARAMTER, NULL);
	if(!url) {
		
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "No memory. Cannot create url");
        return AXIS2_FAILURE;
	}
	
	status = remote_registry_rest_client_post(remote_registry->rest_client, env, 
					url, rate_feed, axutil_strlen(rate_feed), 
					REMOTE_REGISTRY_CONTENT_TYPE_HEADER_NAME REMOTE_REGISTRY_RATING_MEDIA_TYPE);

	return status;
}


AXIS2_EXTERN int AXIS2_CALL 
remote_registry_get_average_rating(
                remote_registry_t *remote_registry,
                const axutil_env_t *env,
                axis2_char_t *path)
{
    int rating = -1;
    axis2_char_t *buffer = NULL;
    axis2_status_t status;
	axis2_char_t *url = NULL;
    int buffer_len = 0;
    
	/* building the url */
	url = axutil_strcat(env, path, REMOTE_REGISTRY_RATING_PARAMTER, NULL);
	if(!url) {
		
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "No memory. Cannot create url");
        return AXIS2_FAILURE;
	}
    buffer = remote_registry_rest_client_get(remote_registry->rest_client, env, url, NULL, 1, &buffer_len);

    status = remote_registry_rest_client_get_last_response_status(remote_registry->rest_client, env);


    if(status == AXIS2_SUCCESS && buffer) {
	    rating = remote_registry_util_get_ratings_from_feed(env, buffer);
    }

    if(buffer) {
        AXIS2_FREE(env->allocator, buffer);
    }
	AXIS2_FREE(env->allocator, url);

    return rating;
}



AXIS2_EXTERN int AXIS2_CALL 
remote_registry_get_user_rating(
                remote_registry_t *remote_registry,
                const axutil_env_t *env,
                axis2_char_t *path,
				axis2_char_t *username)
{
    int rating = -1;
    axis2_char_t *buffer = NULL;
    axis2_status_t status;
	axis2_char_t *url = NULL;
    int buffer_len = 0;

	/* building the url */
	url = axutil_strcat(env, path, REMOTE_REGISTRY_RATING_PARAMTER, ":", username, NULL);
	if(!url) {
		
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "No memory. Cannot create url");
        return AXIS2_FAILURE;
	}
    buffer = remote_registry_rest_client_get(remote_registry->rest_client, env, url, NULL, 1, &buffer_len);

    status = remote_registry_rest_client_get_last_response_status(remote_registry->rest_client, env);


    if(status == AXIS2_SUCCESS && buffer) {
	    rating = remote_registry_util_get_user_ratings_from_feed(env, buffer);
    }

    if(buffer) {
        AXIS2_FREE(env->allocator, buffer);
    }
	AXIS2_FREE(env->allocator, url);

    return rating;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL 
remote_registry_apply_tag(
                remote_registry_t *remote_registry,
                const axutil_env_t *env,
                axis2_char_t *path,
                axis2_char_t *tag)
{
	axis2_char_t *tag_feed = NULL;
	axiom_node_t *tag_node = NULL;
	axis2_char_t *url = NULL;
	axis2_status_t status =  AXIS2_FAILURE;

	tag_node = remote_registry_util_serialize_tag(env, tag);
	tag_feed = axiom_node_to_string(tag_node, env);

	/* building the url */
	url = axutil_strcat(env, path, REMOTE_REGISTRY_TAG_PARAMTER, NULL);
	if(!url) {
		
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "No memory. Cannot create url");
        return AXIS2_FAILURE;
	}
	
	status = remote_registry_rest_client_post(remote_registry->rest_client, env, 
					url, tag_feed, axutil_strlen(tag_feed), 
					REMOTE_REGISTRY_CONTENT_TYPE_HEADER_NAME REMOTE_REGISTRY_RATING_MEDIA_TYPE);

	return status;
}



AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL 
remote_registry_get_tags(
                remote_registry_t *remote_registry,
                const axutil_env_t *env,
                axis2_char_t *path)
{
    axutil_array_list_t *tags = NULL;
    axis2_char_t *buffer = NULL;
    axis2_status_t status;
	axis2_char_t *url = NULL;
    int buffer_len = 0;

	/* building the url */
	url = axutil_strcat(env, path, REMOTE_REGISTRY_TAG_PARAMTER, NULL);
	if(!url) {
		
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "No memory. Cannot create url");
        return NULL;
	}
    buffer = remote_registry_rest_client_get(remote_registry->rest_client, env, url, NULL, 1, &buffer_len);

    status = remote_registry_rest_client_get_last_response_status(remote_registry->rest_client, env);


    if(status == AXIS2_SUCCESS && buffer) {
	    tags = remote_registry_util_get_tags_from_feed(env, buffer);
    }

    if(buffer) {
        AXIS2_FREE(env->allocator, buffer);
    }
	AXIS2_FREE(env->allocator, url);

    return tags;
}



AXIS2_EXTERN remote_registry_resource_t *AXIS2_CALL 
remote_registry_get_paths_with_tag(
                remote_registry_t *remote_registry,
                const axutil_env_t *env,
                axis2_char_t *tag) 
{
    remote_registry_resource_t *res = NULL;
    axis2_char_t *buffer = NULL;
    axis2_status_t status;
    axis2_char_t *content_type = NULL;
    int buffer_len = 0;

	axis2_char_t *url = NULL;

	/* building the url */
	url = axutil_strcat(env, "/", REMOTE_REGISTRY_TAG_PARAMTER, ":", tag, NULL);
	if(!url) 
	{
		
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "No memory. Cannot create url");
        return NULL;
	}
    
    buffer = remote_registry_rest_client_get(remote_registry->rest_client, env, url, NULL, 1, &buffer_len);

    status = remote_registry_rest_client_get_last_response_status(remote_registry->rest_client, env);
    content_type = remote_registry_rest_client_get_last_response_content_type(remote_registry->rest_client, env);


    if(status == AXIS2_SUCCESS) 
	{
		res = remote_registry_resource_create_from_feed(env, buffer, content_type);
		remote_registry_resource_set_rest_client(res, env, remote_registry->rest_client);
    }

    if(buffer) 
	{
        AXIS2_FREE(env->allocator, buffer);
    }

    return res;
}

