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
#include <remote_registry_comment.h>
#include <remote_registry_constants.h>
#include <axutil_utils.h>
#include <axiom.h>

/** 
 * @brief comment struct impl
 *	Rest Client Interface for C
 */
  
struct remote_registry_comment
{
    axis2_char_t *resource_path;
    axis2_char_t *comment_path;
    axis2_char_t *text;
    axis2_char_t *user;
    axutil_date_time_t *date_time;
};


AXIS2_EXTERN remote_registry_comment_t* AXIS2_CALL
remote_registry_comment_create(
    const axutil_env_t *env)
{
    remote_registry_comment_t *comment = NULL;
   
    comment =  (remote_registry_comment_t *)AXIS2_MALLOC(env->allocator, 
            sizeof(remote_registry_comment_t));
	
    if(!comment)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}

    comment->resource_path = NULL;
    comment->comment_path = NULL;
    comment->text = NULL;
    comment->user = NULL;
    comment->date_time = NULL;

	return comment;
}


AXIS2_EXTERN remote_registry_comment_t* AXIS2_CALL
remote_registry_comment_create_from_entry_node(
    const axutil_env_t *env,
    axiom_node_t *entry_node)
{
    remote_registry_comment_t *comment = NULL;
    axiom_children_iterator_t *entry_it = NULL;
    axiom_element_t *entry_ele = NULL;

    comment = remote_registry_comment_create(env);
    if(comment == NULL)
    {
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    entry_ele = axiom_node_get_data_element(entry_node, env);
    entry_it = axiom_element_get_children(entry_ele, env, entry_node);

    while(axiom_children_iterator_has_next(entry_it, env))
    {
        axiom_node_t *child = NULL;
        axiom_element_t *child_ele = NULL;
        axis2_char_t *local_name = NULL;

        child = axiom_children_iterator_next(entry_it, env);

        if(axiom_node_get_node_type(child, env) != AXIOM_ELEMENT) 
        {
            continue;
        }
        child_ele = (axiom_element_t *)axiom_node_get_data_element(child, env);
        
        local_name = axiom_element_get_localname(child_ele, env);

        /* retriving the attribute one by one */
        if(!axutil_strcmp(local_name, "updated")) 
        {
            axis2_char_t *updated_text = NULL;
            axutil_date_time_t *updated_datetime = NULL;

            updated_text = axiom_element_get_text(child_ele, env, child);
            updated_datetime = axutil_date_time_create(env);
            axutil_date_time_deserialize_time(updated_datetime, env, updated_text);

            remote_registry_comment_set_date_time(comment, env, updated_datetime);
        }
        else if(!axutil_strcmp(local_name, "content")) 
        {
            axis2_char_t *content = NULL;
            
            content = axiom_element_get_text(child_ele, env, child);
            remote_registry_comment_set_text(comment, env, content);
        }
        else if(!axutil_strcmp(local_name, "author"))
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

                remote_registry_comment_set_user(comment, env, name);
            }
        }
            
    }
   
    return comment;
}


axutil_array_list_t* AXIS2_CALL
remote_registry_comment_load_from_feed(
    const axutil_env_t *env,
    axis2_char_t *buffer)
{
    axiom_children_iterator_t *node_it = NULL;
    axiom_node_t *feed_node = NULL;
    axiom_element_t *feed_ele = NULL;
    axutil_array_list_t *comment_list = NULL;
    

    feed_node = axiom_node_create_from_buffer(env, buffer);
    if(!feed_node)
    {
        return NULL;
    }

    comment_list = axutil_array_list_create(env, 10);
    if(!comment_list)
    {
        return NULL;
    }

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
        if(!axutil_strcmp(local_name, "entry")) 
        {
            remote_registry_comment_t *comment = NULL;
            comment = remote_registry_comment_create_from_entry_node(env, child);

            axutil_array_list_add(comment_list, env, comment);
        }
    }

    return comment_list;
}

axis2_status_t AXIS2_CALL 
remote_registry_comment_free(
    remote_registry_comment_t *comment, 
    const axutil_env_t *env)
{
    if(comment->resource_path)
    {
        AXIS2_FREE(env->allocator, comment->resource_path);
        comment->resource_path = NULL;
    }
    
    if(comment->comment_path)
    {
        AXIS2_FREE(env->allocator, comment->comment_path);
        comment->comment_path = NULL;
    }
    
    if(comment->text)
    {
        AXIS2_FREE(env->allocator, comment->text);
        comment->text = NULL;
    }
    
    if(comment->user)
    {
        AXIS2_FREE(env->allocator, comment->user);
        comment->user = NULL;
    }
    
    if(comment->date_time)
    {
        axutil_date_time_free(comment->date_time, env);
        comment->date_time = NULL;
    }

	AXIS2_FREE(env->allocator, comment);

	return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_comment_set_resource_path(
    remote_registry_comment_t *comment,
    const axutil_env_t *env,
    const axis2_char_t *resource_path)
{
    comment->resource_path = axutil_strdup(env, resource_path);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_comment_set_comment_path(
    remote_registry_comment_t *comment,
    const axutil_env_t *env,
    const axis2_char_t *comment_path)
{
    comment->comment_path = axutil_strdup(env, comment_path);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_comment_set_text(
    remote_registry_comment_t *comment,
    const axutil_env_t *env,
    const axis2_char_t *text)
{
    comment->text = axutil_strdup(env, text);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_comment_set_user(
    remote_registry_comment_t *comment,
    const axutil_env_t *env,
    const axis2_char_t *user)
{
    comment->user = axutil_strdup(env, user);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_comment_set_date_time(
    remote_registry_comment_t *comment,
    const axutil_env_t *env,
    axutil_date_time_t *date_time)
{
    comment->date_time = date_time;
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axis2_char_t *AXIS2_CALL
remote_registry_comment_get_path(
    remote_registry_comment_t *comment,
    const axutil_env_t *env)
{
    return comment->resource_path;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
remote_registry_comment_get_comment_path(
    remote_registry_comment_t *comment,
    const axutil_env_t *env)
{
    return comment->comment_path;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
remote_registry_comment_get_text(
    remote_registry_comment_t *comment,
    const axutil_env_t *env)
{
    return comment->text;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
remote_registry_comment_get_user(
    remote_registry_comment_t *comment,
    const axutil_env_t *env)
{
    return comment->user;
}

AXIS2_EXTERN axutil_date_time_t *AXIS2_CALL
remote_registry_comment_get_date_time(
    remote_registry_comment_t *comment,
    const axutil_env_t *env)
{
    return comment->date_time;
}


AXIS2_EXTERN axiom_node_t *AXIS2_CALL
remote_registry_comment_serialize(
    remote_registry_comment_t *comment,
    const axutil_env_t *env)
{
    axiom_node_t *entry_node = NULL;
    axiom_element_t *entry_element = NULL;
    axiom_namespace_t *ns1 = NULL;
    axis2_char_t *author = NULL;
    axis2_char_t *content = NULL;

    ns1 = axiom_namespace_create(env, REMOTE_REGISTRY_ATOM_NS, "ns1");
    entry_element = axiom_element_create(env, NULL, "entry", ns1, &entry_node);

    /* getting variables from the structure and rendering into an XML */

    author = remote_registry_comment_get_user(comment, env);
    if(author)
    {
        axiom_node_t *author_node = NULL;
        axiom_node_t *name_node = NULL;
        axiom_element_t *name_ele = NULL;

        axiom_element_create(env, entry_node, "author", ns1, &author_node);
        name_ele = axiom_element_create(env, author_node, "name", ns1, &name_node);

        axiom_element_set_text(name_ele, env, author, name_node);
    }

    content = remote_registry_comment_get_text(comment, env);
    if(content)
    {
        axiom_node_t *content_node = NULL;
        axiom_element_t *content_element = NULL;
        axiom_attribute_t *type_attr = NULL;
        axis2_char_t *media_type = NULL;

        content_element = axiom_element_create(env, entry_node, "content", ns1, &content_node);
        axiom_element_set_text(content_element, env, content, content_node);

        type_attr = axiom_attribute_create(env, "type", "text", NULL); 
        axiom_element_add_attribute(content_element, env, type_attr, content_node);
    }

    return entry_node;
}
