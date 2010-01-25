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
#include <remote_registry_resource.h>
#include <remote_registry_constants.h>
#include <axutil_utils.h>
#include <axiom.h>

/**
 * @brief resource struct impl
 *	Rest Client Interface for C
 */


struct remote_registry_resource
{
    axis2_char_t *id;
    axis2_char_t *author_name;
    axutil_date_time_t *created_time;
    axutil_date_time_t *last_modified_time;
    axis2_char_t *last_updated_username;
    int  updated; /*timestamp*/
    axis2_char_t *description;
    axis2_char_t *path;
    axis2_char_t *media_type;
    axis2_char_t *parent_path;


    /**
     * Used to detect whether the resource content is modified after it is retrieved from the
     * Registry. If this is set to true at the time of adding the resource back to the Registry, new
     * version will be created.
     */
    int content_modified; /*boolean*/

    /**
     * Normal resources have the state RegistryConstants.ACTIVE_STATE (100) Deleted resources have
     * the state RegistryConstants.DELETED_STATE (101)
     */
    int state;

    /* hash map of properties */
    axutil_hash_t *properties;

    axutil_array_list_t *depends_on; /*String[]*/
    axis2_char_t *depended_on_by;

    /*To store any kind of object*/
    char *content;
    int content_len;
    axis2_char_t *content_src_url;

    int is_collection; /*Bool*/

    axis2_char_t *subtitle;

    axis2_char_t *title;

    axis2_char_t *collection;

    axutil_array_list_t *entries;


    /* some internal links that we don't keep getters, setters */
    axis2_char_t *link_self;
    axis2_char_t *link_alternate;
    axis2_char_t *link_path;
    axis2_char_t *link_edit;
    axis2_char_t *link_edit_media;

    int is_content_loaded;

	/* we also keep the rest client */
	remote_registry_rest_client_t *rest_client;
	axutil_array_list_t *child_paths;
};

/* local functions */

static axis2_char_t*
remote_registry_resource_decode_url(
    const axutil_env_t *env,
    axis2_char_t *url);

/* public functions */
AXIS2_EXTERN remote_registry_resource_t* AXIS2_CALL
remote_registry_resource_create(
    const axutil_env_t *env)
{
    remote_registry_resource_t *resource = NULL;

    resource =  (remote_registry_resource_t *)AXIS2_MALLOC(env->allocator,
            sizeof(remote_registry_resource_t));
	
    if(!resource)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}

    resource->id = NULL;
    resource->author_name = NULL;
    resource->created_time = NULL;
    resource->last_updated_username = NULL;
    resource->last_modified_time = NULL;
    resource->updated = 0;
    resource->description = NULL;
    resource->path = NULL;
    resource->media_type = NULL;
    resource->parent_path = NULL;
    resource->content_modified = 0;
    resource->state = 0;
    resource->properties = NULL;
    resource->depends_on = NULL;
    resource->depended_on_by = NULL;
    resource->content = NULL;
    resource->content_src_url = NULL;
    resource->content_len = -1;
    resource->is_collection = 0;
    resource->subtitle = NULL;
    resource->title = NULL;
    resource->collection = NULL;
    resource->entries = NULL;

    resource->link_self = NULL;
    resource->link_alternate = NULL;
    resource->link_path = NULL;
    resource->link_edit = NULL;
    resource->link_edit_media = NULL;
    
    resource->is_content_loaded = 0;
	resource->rest_client = 0;
	resource->child_paths = 0;

	return resource;
}


AXIS2_EXTERN remote_registry_resource_t* AXIS2_CALL
remote_registry_resource_create_collection(
    const axutil_env_t *env)
{
    remote_registry_resource_t *resource = NULL;

    resource = remote_registry_resource_create(env);
	/* mark it as a collection */
	if(resource) {
		resource->is_collection = 1;
	}
	return resource;
}

AXIS2_EXTERN remote_registry_resource_t *AXIS2_CALL
remote_registry_resource_create_from_feed(
                const axutil_env_t *env,
                axis2_char_t *buffer,
				axis2_char_t *content_type)
{
    axiom_node_t *root = NULL;
    axiom_element_t *root_ele = NULL;
    remote_registry_resource_t *resource = NULL;

    if(!buffer) {
        return NULL;
    }

    root = axiom_node_create_from_buffer(env, buffer);
    if(!root) 
    {
        return NULL;
    }

    resource = remote_registry_resource_create(env);
    if(!resource)
	{
        axiom_node_free_tree(root, env);
        return NULL;
	}
	/* distinguising whether it s a collection or entry */
	if(!axutil_strcmp(content_type, REMOTE_REGISTRY_FEED_ENTRY_CONTENT_TYPE)) {
		resource->is_collection = 0;
	}
	else {
		resource->is_collection = 1;
	}

    remote_registry_resource_load_metadata_from_feed_node(env,
                            resource,
                            root);

    return resource;
}


AXIS2_EXTERN remote_registry_resource_t *AXIS2_CALL
remote_registry_resource_create_from_entry_node(
    const axutil_env_t *env,
    axiom_node_t *entry_node)
{
    remote_registry_resource_t *resource = NULL;

    resource = remote_registry_resource_create(env);
    if(!resource)
	{
        return NULL;
	}

    remote_registry_resource_load_metadata_from_feed_node(env,
                            resource,
                            entry_node);

    return resource;
}
AXIS2_EXTERN void AXIS2_CALL
remote_registry_resource_load_metadata_from_feed_node(const axutil_env_t *env,
                                remote_registry_resource_t *resource,
                                axiom_node_t *feed_node)
{
    axiom_children_iterator_t *node_it = NULL;
    axiom_element_t *feed_ele = NULL;
    
    feed_ele = axiom_node_get_data_element(feed_node, env);

    node_it = axiom_element_get_children(feed_ele, env, feed_node);

    /* iterate all the children */
    while(axiom_children_iterator_has_next(node_it, env)) 
    {
        axiom_node_t *child = NULL;
        axiom_element_t *child_ele = NULL;
        axis2_char_t *local_name = NULL;

        child = axiom_children_iterator_next(node_it, env);

        if(axiom_node_get_node_type(child, env) != AXIOM_ELEMENT) 
        {
            continue;
        }
        child_ele = (axiom_element_t *)axiom_node_get_data_element(child, env);
        
        local_name = axiom_element_get_localname(child_ele, env);

        /* retriving the attribute one by one */
        if(!axutil_strcmp(local_name, REMOTE_REGISTRY_FEED_KEY_ID)) 
        {
            axis2_char_t *id_text = NULL;

            id_text = axiom_element_get_text(child_ele, env, child);

            resource->id = id_text;
        }
        else if(!axutil_strcmp(local_name, REMOTE_REGISTRY_FEED_KEY_MEDIA_TYPE))
        {
            axis2_char_t *media_type = NULL;

            media_type = axiom_element_get_text(child_ele, env, child);

            /* for the root feed the feed xml is NULL */
            if(media_type != NULL) {
                if(!axutil_strcmp(media_type, REMOTE_REGISTRY_FEED_KEY_DIR)) 
                {
                    resource->is_collection = 1;
                }
                resource->media_type = media_type;
            }
        }
        else if(!axutil_strcmp(local_name, REMOTE_REGISTRY_FEED_KEY_ENTRY)) 
        {
            /* now iterate through the entries */
            axutil_array_list_t *entry_arr = NULL;
            remote_registry_resource_t *entry_resource = NULL;
			axis2_char_t *child_path = NULL;

            entry_arr = resource->entries;
            if(!entry_arr) {
                entry_arr = axutil_array_list_create(env, 5);
                resource->entries = entry_arr;
            }

            entry_resource = remote_registry_resource_create_from_entry_node(env, child);
            axutil_array_list_add(entry_arr, env, entry_resource);

			/* adding child as a path */
			child_path = entry_resource->link_path;
			if(!resource->child_paths)
			{
				resource->child_paths = axutil_array_list_create(env, 10);
			}
			axutil_array_list_add(resource->child_paths, env, child_path);
        }
        else if(!axutil_strcmp(local_name, REMOTE_REGISTRY_FEED_KEY_LINK))
        {
            /* loading all the links */
            axis2_char_t *href = NULL;
            axis2_char_t *rel = NULL;
                
            href = axiom_element_get_attribute_value_by_name(child_ele, env, REMOTE_REGISTRY_FEED_ATTR_HREF);
            rel = axiom_element_get_attribute_value_by_name(child_ele, env, REMOTE_REGISTRY_FEED_ATTR_REL);

            if(!axutil_strcmp(rel, REMOTE_REGISTRY_FEED_ATTR_SELF)) 
            {
                resource->link_self = axutil_strdup(env, href);
            }
            else if(!axutil_strcmp(rel, REMOTE_REGISTRY_FEED_ATTR_ALTERNATE))
            {
                resource->link_alternate = axutil_strdup(env, href);
            }
            else if(!axutil_strcmp(rel, REMOTE_REGISTRY_FEED_ATTR_PATH))
            {
                remote_registry_resource_set_link_path(resource, env, href);
            }
            else if(!axutil_strcmp(rel, REMOTE_REGISTRY_FEED_ATTR_EDIT))
            {
                resource->link_edit = axutil_strdup(env, href);
            }
            else if(!axutil_strcmp(rel, REMOTE_REGISTRY_FEED_ATTR_EDIT_MEDIA))
            {
                resource->link_edit_media = axutil_strdup(env, href);
            }

        }
        else if(!axutil_strcmp(local_name, REMOTE_REGISTRY_FEED_KEY_CONTENT))
        {
            axis2_char_t *content_src_url = NULL;

            content_src_url = axiom_element_get_attribute_value_by_name(child_ele, env, REMOTE_REGISTRY_FEED_ATTR_SRC);
            remote_registry_resource_set_content_src_url(resource, env, content_src_url);
			if(content_src_url != NULL) {
				resource->is_collection = 0;
			}
        }
        else if(!axutil_strcmp(local_name, REMOTE_REGISTRY_FEED_KEY_AUTHOR))
        {
            axiom_node_t *name_node = NULL;
            axiom_element_t *name_element = NULL;

            name_node = axiom_node_get_first_child(child, env);

            /* get the first child (with type AXIOM_ELEMENT) where we can find the name */
            if(name_node && axiom_node_get_node_type(name_node, env) != AXIOM_ELEMENT)
            {
                name_node = axiom_node_get_next_sibling(name_node, env);
            }

            if(name_node)
            {
                axis2_char_t *name = NULL;
                name_element = axiom_node_get_data_element(name_node, env);

                name = axiom_element_get_text(name_element, env, name_node);

                remote_registry_resource_set_author_name(resource, env, name);
            }
        }
		else if(!axutil_strcmp(local_name, REMOTE_REGISTRY_FEED_KEY_PROPERTIES))
		{
			axiom_children_iterator_t *properties_it = NULL;
			axiom_element_t *properties_ele = NULL;

			if(!resource->properties)
			{
				resource->properties = axutil_hash_make(env);
			}
		    
			properties_ele = axiom_node_get_data_element(child, env);

			properties_it = axiom_element_get_children(properties_ele, env, child);

			/* iterate all the properties */
			while(axiom_children_iterator_has_next(properties_it, env)) 
			{
				axiom_node_t *property_node = NULL;
				axiom_node_t *name_node = NULL;
				axiom_node_t *value_node = NULL;
				axiom_element_t *name_element = NULL;
				axiom_element_t *value_element = NULL;

				axis2_char_t *name = NULL;
				axis2_char_t *value = NULL;

				property_node = axiom_children_iterator_next(properties_it, env);

				if(axiom_node_get_node_type(property_node, env) != AXIOM_ELEMENT) 
				{
					continue;
				}
		        
				name_node = axiom_node_get_first_child(property_node, env);
				while(name_node && axiom_node_get_node_type(name_node, env) != AXIOM_ELEMENT) 
				{
					name_node = axiom_node_get_next_sibling(name_node, env);
				}

				if(!name_node) 
				{
					continue;
				}

				value_node = axiom_node_get_next_sibling(name_node, env);
				while(value_node && axiom_node_get_node_type(value_node, env) != AXIOM_ELEMENT) 
				{
					value_node = axiom_node_get_next_sibling(value_node, env);
				}

				if(!value_node) 
				{
					continue;
				}

				name_element = axiom_node_get_data_element(name_node, env);
				value_element = axiom_node_get_data_element(value_node, env);

				name = axiom_element_get_text(name_element, env, name_node);
				value = axiom_element_get_text(value_element, env, value_node);
				
				axutil_hash_set(resource->properties, name, AXIS2_HASH_KEY_STRING, value);
			}
		}
    }
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_free(
    remote_registry_resource_t *resource,
    const axutil_env_t *env)
{

    if(resource->author_name != NULL)
    {
        AXIS2_FREE(env->allocator, resource->author_name);
        resource->author_name = NULL;
    }
    if(resource->created_time != NULL)
    {
        axutil_date_time_free(resource->created_time, env);
        resource->created_time = NULL;
    }
    if(resource->last_updated_username != NULL)
    {
        AXIS2_FREE(env->allocator, resource->last_updated_username);
        resource->last_updated_username = NULL;
    }
    if(resource->description != NULL)
    {
        AXIS2_FREE(env->allocator, resource->description);
        resource->description = NULL;
    }
    if(resource->path != NULL)
    {
        AXIS2_FREE(env->allocator, resource->path);
        resource->path = NULL;
    }
    if(resource->media_type != NULL)
    {
        AXIS2_FREE(env->allocator, resource->media_type);
        resource->media_type = NULL;
    }
    if(resource->parent_path != NULL)
    {
        AXIS2_FREE(env->allocator, resource->parent_path);
        resource->parent_path = NULL;
    }
    if(resource->properties != NULL)
    {
        axutil_hash_index_t *hi;
        void *val;
        void *key;
        int sum = 0;
        for (hi = axutil_hash_first(resource->properties, env); hi; hi = axutil_hash_next(env, hi)) {
            axutil_hash_this(hi, (const void**)&key, NULL, &val);

            AXIS2_FREE(env->allocator, key);
            AXIS2_FREE(env->allocator, val);
        }
        axutil_hash_free(resource->properties, env);
        resource->properties = NULL;
    }
    if(resource->depends_on != NULL)
    {
        axutil_array_list_free(resource->depends_on, env);
        resource->depends_on = NULL;
    }
    if(resource->depended_on_by != NULL)
    {
        AXIS2_FREE(env->allocator, resource->depended_on_by);
        resource->depended_on_by = NULL;
    }
    if(resource->content != NULL)
    {
        AXIS2_FREE(env->allocator, resource->content);
        resource->content = NULL;
    }
    if(resource->subtitle != NULL)
    {
        AXIS2_FREE(env->allocator, resource->subtitle);
        resource->subtitle = NULL;
    }
    if(resource->title != NULL)
    {
        AXIS2_FREE(env->allocator, resource->title);
        resource->title = NULL;
    }
    if(resource->collection != NULL)
    {
        AXIS2_FREE(env->allocator, resource->collection);
        resource->collection = NULL;
    }
    if(resource->entries != NULL)
    {
        int i = 0;

        /* needed to free all the resouces recursively */
        for(i = 0; i < axutil_array_list_size(resource->entries, env); i ++ )
        {
            remote_registry_resource_t *res = NULL;
            res = axutil_array_list_get(resource->entries, env, i);

            remote_registry_resource_free(res, env);
        }
        axutil_array_list_free(resource->entries, env);
        resource->entries = NULL;
    }
	if(resource->child_paths != NULL)
	{
		axutil_array_list_free(resource->child_paths, env);
		resource->child_paths = NULL;
	}

    if(resource->link_self != NULL)
    {
        AXIS2_FREE(env->allocator, resource->link_self);
    }
    if(resource->link_alternate != NULL)
    {
        AXIS2_FREE(env->allocator, resource->link_alternate);
    }
    if(resource->link_path != NULL)
    {
        AXIS2_FREE(env->allocator, resource->link_path);
    }
    if(resource->link_edit != NULL)
    {
        AXIS2_FREE(env->allocator, resource->link_edit);
    }
    if(resource->link_edit_media != NULL)
    {
        AXIS2_FREE(env->allocator, resource->link_edit_media);
    }
    if(resource->content_src_url != NULL)
    {
        AXIS2_FREE(env->allocator, resource->content_src_url);
    }

	AXIS2_FREE(env->allocator, resource);

	return AXIS2_SUCCESS;
}



AXIS2_EXTERN axis2_char_t *AXIS2_CALL
remote_registry_resource_get_id(
    remote_registry_resource_t *resource,
    const axutil_env_t *env)
{
    return resource->id;
}

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
remote_registry_resource_get_author_name(
    remote_registry_resource_t *resource,
    const axutil_env_t *env)
{
    return resource->author_name;
}

AXIS2_EXTERN axutil_date_time_t* AXIS2_CALL
remote_registry_resource_get_created_time(
    remote_registry_resource_t *resource,
    const axutil_env_t *env)
{
    return resource->created_time;
}


AXIS2_EXTERN axutil_date_time_t* AXIS2_CALL
remote_registry_resource_get_last_modified_time(
    remote_registry_resource_t *resource,
    const axutil_env_t *env)
{
    return resource->last_modified_time;
}

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
remote_registry_resource_get_last_updated_username(
    remote_registry_resource_t *resource,
    const axutil_env_t *env)
{
    return resource->last_updated_username;
}

AXIS2_EXTERN int  AXIS2_CALL
remote_registry_resource_get_updated(
    remote_registry_resource_t *resource,
    const axutil_env_t *env)
{
    return resource->updated;
}

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
remote_registry_resource_get_description(
    remote_registry_resource_t *resource,
    const axutil_env_t *env)
{
    return resource->description;
}

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
remote_registry_resource_get_path(
    remote_registry_resource_t *resource,
    const axutil_env_t *env)
{
    return resource->path;
}

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
remote_registry_resource_get_media_type(
    remote_registry_resource_t *resource,
    const axutil_env_t *env)
{
    return resource->media_type;
}

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
remote_registry_resource_get_parent_path(
    remote_registry_resource_t *resource,
    const axutil_env_t *env)
{
    return resource->parent_path;
}
AXIS2_EXTERN int AXIS2_CALL
remote_registry_resource_get_content_modified(
    remote_registry_resource_t *resource,
    const axutil_env_t *env)
{
    return resource->content_modified;
}
AXIS2_EXTERN int AXIS2_CALL
remote_registry_resource_get_state(
    remote_registry_resource_t *resource,
    const axutil_env_t *env)
{
    return resource->state;
}

AXIS2_EXTERN axutil_hash_t* AXIS2_CALL
remote_registry_resource_get_properties(
    remote_registry_resource_t *resource,
    const axutil_env_t *env)
{
    return resource->properties;
}

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
remote_registry_resource_get_property(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    const axis2_char_t *key)
{
    return (axis2_char_t *) axutil_hash_get(resource->properties, key, axutil_strlen(key));
}

AXIS2_EXTERN void AXIS2_CALL
remote_registry_resource_remove_property(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    const axis2_char_t *key)
{
    axis2_char_t *value = axutil_hash_get(resource->properties, key, axutil_strlen(key));
    if(value)
    {
        AXIS2_FREE(env->allocator, value);
    }

    axutil_hash_set(resource->properties, key, axutil_strlen(key), NULL);
}

AXIS2_EXTERN axutil_array_list_t* AXIS2_CALL
remote_registry_resource_get_depends_on(
    remote_registry_resource_t *resource,
    const axutil_env_t *env)
{
    return resource->depends_on;
}

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
remote_registry_resource_get_depended_on_by(
    remote_registry_resource_t *resource,
    const axutil_env_t *env)
{
    return resource->depended_on_by;
}

AXIS2_EXTERN char* AXIS2_CALL
remote_registry_resource_get_content(
    remote_registry_resource_t *resource,
    const axutil_env_t *env)
{
	if(!resource->is_collection && !resource->is_content_loaded) {
		/* we have to load the content for the first time */
		axis2_char_t *buffer = NULL;
		axis2_status_t status;
		int buffer_len = 0;

		if(!resource->content_src_url) {
			return resource->content;
		}
		if(!resource->rest_client) {
			return resource->content;
		}
		
        buffer = remote_registry_rest_client_get(resource->rest_client, env,
						resource->content_src_url, NULL, 0, &buffer_len);
        status = remote_registry_rest_client_get_last_response_status(resource->rest_client, env);

        if(status == AXIS2_SUCCESS) 
		{
            remote_registry_resource_set_is_content_loaded(resource, env, 1);
            remote_registry_resource_set_content(resource, env, buffer);
            remote_registry_resource_set_content_len(resource, env, buffer_len);
        }
	}
    return resource->content;
}
AXIS2_EXTERN int AXIS2_CALL
remote_registry_resource_get_content_len(
    remote_registry_resource_t *resource,
    const axutil_env_t *env)
{
    return resource->content_len;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
remote_registry_resource_get_content_src_url(
    remote_registry_resource_t *resource,
    const axutil_env_t *env)
{
    return resource->content_src_url;
}
AXIS2_EXTERN int AXIS2_CALL
remote_registry_resource_get_is_collection(
    remote_registry_resource_t *resource,
    const axutil_env_t *env)
{
    return resource->is_collection;
}

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
remote_registry_resource_get_subtitle(
    remote_registry_resource_t *resource,
    const axutil_env_t *env)
{
    return resource->subtitle;
}

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
remote_registry_resource_get_title(
    remote_registry_resource_t *resource,
    const axutil_env_t *env)
{
    return resource->title;
}

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
remote_registry_resource_get_collection(
    remote_registry_resource_t *resource,
    const axutil_env_t *env)
{
    return resource->collection;
}

AXIS2_EXTERN axutil_array_list_t* AXIS2_CALL
remote_registry_resource_get_entries(
    remote_registry_resource_t *resource,
    const axutil_env_t *env)
{
    return resource->entries;
}

AXIS2_EXTERN axutil_array_list_t* AXIS2_CALL
remote_registry_resource_get_children(
    remote_registry_resource_t *resource,
    const axutil_env_t *env)
{
	return resource->child_paths;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
remote_registry_resource_get_link_alternate(
    remote_registry_resource_t *resource,
    const axutil_env_t *env)
{
    return resource->link_alternate;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
remote_registry_resource_get_link_path(
    remote_registry_resource_t *resource,
    const axutil_env_t *env)
{
    return resource->link_path;
}
AXIS2_EXTERN int AXIS2_CALL
remote_registry_resource_get_is_content_loaded(
    remote_registry_resource_t *resource,
    const axutil_env_t *env)
{
    return resource->is_content_loaded;
}




/* setter functions */
AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_id(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    axis2_char_t *id)
{
    resource->id = id;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_author_name(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    const axis2_char_t *author_name)
{
    resource->author_name = axutil_strdup(env, author_name);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_created_time(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    axutil_date_time_t *created_time)
{
    resource->created_time = created_time;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_last_modified_time(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    axutil_date_time_t *last_modified_time)
{
    resource->last_modified_time = last_modified_time;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_last_updated_username(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    const axis2_char_t *last_updated_username)
{
    resource->last_updated_username = axutil_strdup(env, last_updated_username);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_updated(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    int  updated)
{
    resource->updated = updated;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_description(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    const axis2_char_t *description)
{
    resource->description = axutil_strdup(env, description);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_path(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    const axis2_char_t *path)
{
    resource->path = axutil_strdup(env, path);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_media_type(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    const axis2_char_t *media_type)
{
    resource->media_type = axutil_strdup(env, media_type);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_parent_path(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    const axis2_char_t *parent_path)
{
    resource->parent_path = axutil_strdup(env, parent_path);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_content_modified(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    int content_modified)
{
    resource->content_modified = content_modified;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_state(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    int state)
{
    resource->state = state;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_properties(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    axutil_hash_t *properties)
{
    resource->properties = properties;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_depends_on(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    axutil_array_list_t *depends_on)
{
    resource->depends_on = depends_on;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_depended_on_by(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    const axis2_char_t *depended_on_by)
{
    resource->depended_on_by = axutil_strdup(env, depended_on_by);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_content_src_url(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    axis2_char_t *content_src_url)
{
    resource->content_src_url = 
			remote_registry_resource_decode_url(env, content_src_url);

    
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_content(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    char *content)
{
    resource->content = content;
	resource->content_modified = 1;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_content_len(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    int content_len)
{
    resource->content_len = content_len;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_is_collection(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    int is_collection)
{
    resource->is_collection = is_collection;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_subtitle(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    const axis2_char_t *subtitle)
{
    resource->subtitle = axutil_strdup(env, subtitle);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_title(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    const axis2_char_t *title)
{
    resource->title = axutil_strdup(env, title);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_collection(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    const axis2_char_t *collection)
{
    resource->collection = axutil_strdup(env, collection);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_entries(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    axutil_array_list_t *entries)
{
    resource->entries = entries;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_link_alternate(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    axis2_char_t *link_alternate)
{
    resource->link_alternate = axutil_strdup(env, link_alternate);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_link_path(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    axis2_char_t *link_path)
{
    resource->link_path = remote_registry_resource_decode_url(env, link_path);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_is_content_loaded(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    int is_content_loaded)
{
    resource->is_content_loaded = is_content_loaded;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axiom_node_t *AXIS2_CALL
remote_registry_resource_serialize(
    remote_registry_resource_t *resource,
    const axutil_env_t *env)
{
    axiom_node_t *entry_node = NULL;
    axiom_element_t *entry_element = NULL;
    axiom_namespace_t *ns1 = NULL;
    axiom_namespace_t *ns2 = NULL;
    axis2_char_t *description = NULL;
    axis2_char_t *author = NULL;
    axutil_hash_t *properties = NULL;
    axis2_char_t *content = NULL;
    int collection = 0;
    int content_modified= 0;
	axis2_char_t *id = NULL;
	axis2_char_t *title = NULL;
	
    axis2_char_t *media_type = NULL;
    axis2_char_t *parent_path = NULL;
	axutil_date_time_t *modified_date = NULL;

    ns1 = axiom_namespace_create(env, REMOTE_REGISTRY_ATOM_NS, REMOTE_REGISTRY_ATOM_NS_PREFIX);
    ns2 = axiom_namespace_create(env, REMOTE_REGISTRY_REGISTRY_NS, REMOTE_REGISTRY_REGISTRY_NS_PREFIX);

	if(resource->is_collection)
	{
		entry_element = axiom_element_create(env, NULL, REMOTE_REGISTRY_FEED_KEY_FEED, ns1, &entry_node);
	}
	else
	{
		entry_element = axiom_element_create(env, NULL, REMOTE_REGISTRY_FEED_KEY_ENTRY, ns1, &entry_node);
	}

	axiom_element_declare_namespace(entry_element, env, entry_node, ns1);
	axiom_element_declare_namespace(entry_element, env, entry_node, ns2);

    /* getting variables from the structure and rendering into an XML */
	id = remote_registry_resource_get_id(resource, env);
	if(id)
	{
		axiom_node_t *id_node = NULL;
		axiom_element_t *id_element = NULL;

		id_element = axiom_element_create(env, entry_node, REMOTE_REGISTRY_FEED_KEY_ID, ns1, &id_node);
		axiom_element_set_text(id_element, env, id, id_node);
	}


    title = remote_registry_resource_get_title(resource, env);
    if(title)
    {
        axiom_node_t *title_node = NULL;
        axiom_element_t *title_element = NULL;
        axiom_attribute_t *type_attr = NULL;

        title_element = axiom_element_create(env, entry_node,
						REMOTE_REGISTRY_FEED_KEY_TITLE, ns1, &title_node);
        axiom_element_set_text(title_element, env, title, title_node);

        type_attr = axiom_attribute_create(env, REMOTE_REGISTRY_FEED_ATTR_TYPE,
						REMOTE_REGISTRY_FEED_ATTR_TYPE_TEXT, NULL); 
        axiom_element_add_attribute(title_element, env, type_attr, title_node);
    }

    description = remote_registry_resource_get_description(resource, env);
    if(description)
    {
        axiom_node_t *summary_node = NULL;
        axiom_element_t *summary_element = NULL;
        axiom_attribute_t *type_attr = NULL;

        summary_element = axiom_element_create(env, entry_node, REMOTE_REGISTRY_FEED_KEY_SUMMARY, ns1, &summary_node);
        axiom_element_set_text(summary_element, env, description, summary_node);

        type_attr = axiom_attribute_create(env, REMOTE_REGISTRY_FEED_ATTR_TYPE,
					REMOTE_REGISTRY_FEED_ATTR_TYPE_TEXT, NULL); 
        axiom_element_add_attribute(summary_element, env, type_attr, summary_node);
    }

    author = remote_registry_resource_get_author_name(resource, env);
    if(author)
    {
        axiom_node_t *author_node = NULL;
        axiom_node_t *name_node = NULL;
        axiom_element_t *name_ele = NULL;

        axiom_element_create(env, entry_node, REMOTE_REGISTRY_FEED_KEY_AUTHOR, ns1, &author_node);
        name_ele = axiom_element_create(env, author_node, REMOTE_REGISTRY_FEED_KEY_NAME, ns1, &name_node);

        axiom_element_set_text(name_ele, env, author, name_node);
    }

	modified_date = remote_registry_resource_get_last_modified_time(resource, env);
	if(!modified_date) {
		modified_date = axutil_date_time_create(env);
		remote_registry_resource_set_last_modified_time(resource, env, modified_date);
	}
	if(modified_date) 
	{
        axiom_node_t *date_node = NULL;
        axiom_element_t *date_ele = NULL;
		axis2_char_t *modified_date_str = NULL;

		modified_date_str = axutil_date_time_serialize_date_time(modified_date, env);
        date_ele = axiom_element_create(env, entry_node, REMOTE_REGISTRY_FEED_KEY_UPDATED, ns1, &date_node);
        axiom_element_set_text(date_ele, env, modified_date_str, date_node);

		AXIS2_FREE(env->allocator, modified_date_str);
	}
	

    content = remote_registry_resource_get_content(resource, env);
    if(content)
    {
        axiom_node_t *content_node = NULL;
        axiom_element_t *content_element = NULL;
        axiom_attribute_t *type_attr = NULL;
		axis2_char_t *base64_content = NULL;

		int base64_len = 0;
		int content_len = -1;

		content_len = remote_registry_resource_get_content_len(resource, env);
		if(content_len == -1) /* which mean we have to derive the content length */
		{
			content_len = axutil_strlen(content);
		}

		base64_len = axutil_base64_encode_len(content_len);
		base64_content = AXIS2_MALLOC(env->allocator, base64_len+ 1);

		if(base64_content) 
		{
			axutil_base64_encode(base64_content, content, content_len);
			base64_content[base64_len] = '\0';


			content_element = axiom_element_create(env, entry_node, 
							REMOTE_REGISTRY_FEED_KEY_CONTENT, ns1, &content_node);
			axiom_element_set_text(content_element, env, base64_content, content_node);


			type_attr = axiom_attribute_create(env, REMOTE_REGISTRY_FEED_ATTR_TYPE, 
							REMOTE_REGISTRY_FEED_ATTR_TYPE_BASE64_VALUE, NULL); 
			axiom_element_add_attribute(content_element, env, type_attr, content_node);
			
			AXIS2_FREE(env->allocator, base64_content);
		}
    }
    else if(!resource->is_collection)
    {
        axiom_node_t *content_node = NULL;
        axiom_element_t *content_element = NULL;
        axiom_attribute_t *type_attr = NULL;

        content_element = axiom_element_create(env, entry_node, 
						REMOTE_REGISTRY_FEED_KEY_CONTENT, ns1, &content_node);
        axiom_element_set_text(content_element, env, 
						REMOTE_REGISTRY_FEED_VALUE_EMPTY_CONTENT, content_node);


        type_attr = axiom_attribute_create(env, REMOTE_REGISTRY_FEED_ATTR_TYPE, 
						REMOTE_REGISTRY_FEED_ATTR_TYPE_TEXT_VALUE, NULL); 
        axiom_element_add_attribute(content_element, env, type_attr, content_node);
    }

    properties = remote_registry_resource_get_properties(resource, env);
    if(properties)
    {
        axiom_node_t *properties_node = NULL;
        axiom_node_t *property_node = NULL;
        axiom_node_t *name_node = NULL;
        axiom_node_t *value_node = NULL;
        axiom_element_t *name_element = NULL;
        axiom_element_t *value_element = NULL;
        axutil_hash_index_t *hi;
        void *val;
        void *key;
        int sum = 0;

        axiom_element_create(env, entry_node, REMOTE_REGISTRY_FEED_KEY_PROPERTIES, ns2, &properties_node);
        
        for (hi = axutil_hash_first(resource->properties, env); hi; hi = axutil_hash_next(env, hi)) {
            axutil_hash_this(hi, (const void**)&key, NULL, &val);
            
            axiom_element_create(env, properties_node, REMOTE_REGISTRY_FEED_KEY_PROPERTY, ns2, &property_node);

            name_element = axiom_element_create(env, property_node, 
								REMOTE_REGISTRY_FEED_KEY_PROPERTY_KEY_NAME, ns2, &name_node);
            axiom_element_set_text(name_element, env, (axis2_char_t*)key, name_node);
            value_element = axiom_element_create(env, property_node, 
								REMOTE_REGISTRY_FEED_KEY_PROPERTY_KEY_VALUE, ns2, &value_node);
            axiom_element_set_text(value_element, env, (axis2_char_t*)val, value_node);
        }
    }
	
	media_type = remote_registry_resource_get_media_type(resource, env);
	if(media_type) 
	{
		axiom_element_t *media_element = NULL;
		axiom_node_t *media_node = NULL;
		media_element = axiom_element_create(env, entry_node, 
								REMOTE_REGISTRY_FEED_KEY_MEDIA_TYPE, ns2, &media_node);
		axiom_element_set_text(media_element, env, media_type, media_node);

	}

    parent_path = remote_registry_resource_get_parent_path(resource, env);
	if(parent_path) 
	{
		axiom_element_t *parent_path_element = NULL;
		axiom_node_t *parent_path_node = NULL;
		parent_path_element = axiom_element_create(env, entry_node, REMOTE_REGISTRY_FEED_KEY_PARENT_PATH, ns2, &parent_path_node);
		if(resource->is_collection) 
		{
			/* for collection parent path is always sent at the http request header */
			parent_path = "";
		}
		axiom_element_set_text(parent_path_element, env, parent_path, parent_path_node);
	}
	if(resource->is_collection)
	{
		axiom_element_t *content_modified_element = NULL;
		axiom_node_t *content_modified_node = NULL;
		content_modified_element = axiom_element_create(env, entry_node, 
				REMOTE_REGISTRY_FEED_KEY_CONTENT_MODIFIED, ns2, &content_modified_node);
		axiom_element_set_text(content_modified_element, env, 
				REMOTE_REGISTRY_FEED_KEY_TRUE_VALUE, content_modified_node);
	}

    return entry_node;
}


static axis2_char_t*
remote_registry_resource_decode_url(
    const axutil_env_t *env,
    axis2_char_t *url)
{

    axis2_char_t *url_dup = NULL;

    url_dup = axutil_strdup(env, url);
	axutil_url_decode(env, url_dup, url);
    
    return url_dup;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_rest_client(
	remote_registry_resource_t *resource, 
	const axutil_env_t *env,
	remote_registry_rest_client_t *rest_client)
{
	resource->rest_client = rest_client;
	return AXIS2_SUCCESS;
}