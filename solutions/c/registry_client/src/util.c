#include <remote_registry_constants.h>
#include <remote_registry_util.h>
#include <axutil_utils.h>
#include <axiom.h>



AXIS2_EXTERN axiom_node_t *AXIS2_CALL
remote_registry_util_serialize_rating(
    const axutil_env_t *env, 
    int rate)
{
    axiom_node_t *entry_node = NULL;
    axiom_element_t *entry_element = NULL;
    axiom_namespace_t *ns1 = NULL;
	axis2_char_t *content = NULL;

    axiom_node_t *content_node = NULL;
    axiom_element_t *content_element = NULL;
    axiom_node_t *summary_node = NULL;
    axiom_element_t *summary_element = NULL;
    axiom_attribute_t *type_attr = NULL;
    axis2_char_t *media_type = NULL;

    ns1 = axiom_namespace_create(env, REMOTE_REGISTRY_ATOM_NS, "ns1");
    entry_element = axiom_element_create(env, NULL, "entry", ns1, &entry_node);


    /* getting variables from the argument and rendering into an XML */
	content = AXIS2_MALLOC(env->allocator, 64);

    content_element = axiom_element_create(env, entry_node, "content", ns1, &content_node);
    axiom_element_set_text(content_element, env, content, content_node);

    type_attr = axiom_attribute_create(env, "type", "text", NULL); 
    axiom_element_add_attribute(content_element, env, type_attr, content_node);

	
    summary_element = axiom_element_create(env, entry_node, "content", ns1, &summary_node);
    axiom_element_set_text(summary_element, env, content, summary_node);

    type_attr = axiom_attribute_create(env, "type", "text", NULL); 
    axiom_element_add_attribute(summary_element, env, type_attr, summary_node);
    

    return entry_node;
}


AXIS2_EXTERN int AXIS2_CALL
remote_registry_util_get_ratings_from_feed(
    const axutil_env_t *env,
    axis2_char_t *feed)
{
	axiom_node_t *entry_node;
	
    axiom_children_iterator_t *entry_it = NULL;
    axiom_element_t *entry_ele = NULL;

	int rating = -1;


	entry_node = axiom_node_create_from_buffer(env, feed);
	if(!entry_node) {
		return -1;
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
		if(!axutil_strcmp(local_name, "AverageRating"))
		{
			axis2_char_t *rating_str = NULL;

			rating_str = axiom_element_get_text(child_ele, env, child);

			rating = atoi(rating_str);
			break;
		}
	}
	return rating;
}


AXIS2_EXTERN int AXIS2_CALL
remote_registry_util_get_user_ratings_from_feed(
    const axutil_env_t *env,
    axis2_char_t *feed)
{
	axiom_node_t *entry_node;
	
    axiom_children_iterator_t *entry_it = NULL;
    axiom_element_t *entry_ele = NULL;

	int rating = -1;


	entry_node = axiom_node_create_from_buffer(env, feed);
	if(!entry_node) {
		return -1;
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
		if(!axutil_strcmp(local_name, "entry"))
		{
			axiom_children_iterator_t *entry_child_it = NULL;

			entry_child_it = axiom_element_get_children(entry_ele, env, entry_node);

			while(axiom_children_iterator_has_next(entry_child_it, env))
			{
				axiom_element_t *entry_child_ele = NULL;
				axiom_node_t *entry_child = NULL;

				entry_child = axiom_children_iterator_next(entry_child_it, env);
				if(axiom_node_get_node_type(entry_child, env) != AXIOM_ELEMENT)
				{
					continue;
				}

				entry_child_ele = (axiom_element_t*)axiom_node_get_data_element(entry_child, env);

				local_name = axiom_element_get_localname(entry_child_ele, env);

				if(!axutil_strcmp(local_name, "content"))
				{
					axis2_char_t *rating_str = NULL;

					rating_str = axiom_element_get_text(entry_child_ele, env, entry_child);

					rating = atoi(rating_str);
					break;
				}
			}
		}
	}
	return rating;
}


AXIS2_EXTERN axiom_node_t *AXIS2_CALL
remote_registry_util_serialize_tag(
    const axutil_env_t *env, 
    axis2_char_t *tag)
{
    axiom_node_t *entry_node = NULL;
    axiom_element_t *entry_element = NULL;
    axiom_namespace_t *ns1 = NULL;
	axis2_char_t *content = NULL;

    axiom_node_t *content_node = NULL;
    axiom_element_t *content_element = NULL;
    axiom_node_t *summary_node = NULL;
    axiom_element_t *summary_element = NULL;
    axiom_attribute_t *type_attr = NULL;
    axis2_char_t *media_type = NULL;

    ns1 = axiom_namespace_create(env, REMOTE_REGISTRY_ATOM_NS, "ns1");
    entry_element = axiom_element_create(env, NULL, "entry", ns1, &entry_node);


    /* getting variables from the argument and rendering into an XML */

    content_element = axiom_element_create(env, entry_node, "content", ns1, &content_node);
    axiom_element_set_text(content_element, env, tag, content_node);

    type_attr = axiom_attribute_create(env, "type", "text", NULL); 
    axiom_element_add_attribute(content_element, env, type_attr, content_node);

    return entry_node;
}



AXIS2_EXTERN axutil_array_list_t* AXIS2_CALL
remote_registry_util_get_tags_from_feed(
    const axutil_env_t *env,
    axis2_char_t *feed)
{
	axiom_node_t *entry_node = NULL;
	
    axiom_children_iterator_t *entry_it = NULL;
    axiom_element_t *entry_ele = NULL;

	axutil_array_list_t *tags = NULL;


	entry_node = axiom_node_create_from_buffer(env, feed);
	if(!entry_node) {
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
		if(!axutil_strcmp(local_name, "entry"))
		{
			axiom_children_iterator_t *entry_child_it = NULL;
			axis2_char_t *is_tagging = NULL;

			entry_child_it = axiom_element_get_children(entry_ele, env, entry_node);

			while(axiom_children_iterator_has_next(entry_child_it, env))
			{
				axiom_element_t *entry_child_ele = NULL;
				axiom_node_t *entry_child = NULL;

				entry_child = axiom_children_iterator_next(entry_child_it, env);
				if(axiom_node_get_node_type(entry_child, env) != AXIOM_ELEMENT)
				{
					continue;
				}

				entry_child_ele = (axiom_element_t*)axiom_node_get_data_element(entry_child, env);

				local_name = axiom_element_get_localname(entry_child_ele, env);

				if(!axutil_strcmp(local_name, "taggings"))
				{
					is_tagging = axiom_element_get_text(entry_child_ele, env, entry_child);
				}
			}

			if(!axutil_strcmp("1", is_tagging))
			{
				axiom_children_iterator_reset(entry_child_it, env);
				while(axiom_children_iterator_has_next(entry_child_it, env))
				{
					axiom_element_t *entry_child_ele = NULL;
					axiom_node_t *entry_child = NULL;

					entry_child = axiom_children_iterator_next(entry_child_it, env);
					if(axiom_node_get_node_type(entry_child, env) != AXIOM_ELEMENT)
					{
						continue;
					}

					entry_child_ele = (axiom_element_t*)axiom_node_get_data_element(entry_child, env);

					local_name = axiom_element_get_localname(entry_child_ele, env);

					if(!axutil_strcmp(local_name, "title"))
					{
						axis2_char_t *tag_name = NULL;
						tag_name = axiom_element_get_text(entry_child_ele, env, entry_child);

						axutil_array_list_add(tags, env, tag_name);
					}
				}
			}
		}
	}
	return tags;
}

