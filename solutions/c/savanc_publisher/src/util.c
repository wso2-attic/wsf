#include <stdio.h>
#include <raptor.h>
#include <stdlib.h>
#include <axutil_string.h>
#include <axutil_env.h>
/*#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdlib.h>*/
#include <reg_client_util.h>
#include <reg_client_resource.h>

AXIS2_EXTERN reg_client_util_t* AXIS2_CALL
reg_client_util_create(
    const axutil_env_t *env)
{
    reg_client_util_t *util = NULL;

    util =  (reg_client_util_t *)AXIS2_MALLOC(env->allocator, 
            sizeof(reg_client_util_t));
	
    if(!util)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}

    util->env = NULL;
    util->resource = NULL;
    util->parse_entries = AXIS2_FALSE;
    util-> parse_entry = AXIS2_FALSE;
    util->entry = NULL;
    
	return util;

}
                        
void AXIS2_CALL 
reg_client_util_free(
    reg_client_util_t *util, 
    const axutil_env_t *env)
{
    if(util)
    {
        AXIS2_FREE(env->allocator, util);
    }
}


void
populate_resource(
    void* user_data, 
    const raptor_statement* statement) 
{
    axis2_char_t *predicate = NULL;
    axis2_char_t *object = NULL;
    const axutil_env_t *env = NULL;
    reg_client_resource_t *resource = NULL;
    reg_client_util_t *util = (reg_client_util_t *) user_data;
  
    env = util->env;
    resource = util->resource;

    if(statement->predicate_type != RAPTOR_IDENTIFIER_TYPE_ORDINAL)
    {
        #ifdef RAPTOR_DEBUG
            if(!statement->predicate)
            {
                RAPTOR_FATAL1("Statement has NULL predicate URI\n");
            }
        #endif

        predicate = (axis2_char_t*) raptor_uri_as_string((raptor_uri*)statement->predicate);
    }

    if(statement->object_type == RAPTOR_IDENTIFIER_TYPE_LITERAL || 
        statement->object_type == RAPTOR_IDENTIFIER_TYPE_XML_LITERAL) 
    {
        axis2_char_t *temp_object = NULL;
        object = (axis2_char_t *) malloc(1028);

        if(statement->object_type == RAPTOR_IDENTIFIER_TYPE_XML_LITERAL) 
        {
            temp_object = (axis2_char_t*) raptor_xml_literal_datatype_uri_string;
            sprintf(object, "<%s>", temp_object);
        } 
        else if(statement->object_literal_datatype) 
        {
            temp_object = (axis2_char_t *) raptor_uri_as_string((raptor_uri*) 
                    statement->object_literal_datatype);
            sprintf(object, "<%s>", temp_object);

        }

        temp_object = (axis2_char_t *) statement->object;
        sprintf(object, "\"%s\"", temp_object);
    } 
    else if(statement->object_type == RAPTOR_IDENTIFIER_TYPE_ANONYMOUS)
    {
        object = (axis2_char_t *) statement->object;
    }
    else if(statement->object_type == RAPTOR_IDENTIFIER_TYPE_ORDINAL)
    {
        /*fprintf(stream, "[rdf:_%d]", *((int*)statement->object));*/
    }
    else 
    {
        #ifdef RAPTOR_DEBUG
            if(!statement->object)
            {
                RAPTOR_FATAL1("Statement has NULL object URI\n");
            }
        #endif

        object = (axis2_char_t*)raptor_uri_as_string((raptor_uri*)statement->object);
    }

    if(!util->parse_entries)
    { 
        if(!axutil_strcmp(predicate, "http://purl.org/rss/1.0/title"))
        {
            resource->title = (axis2_char_t *) axutil_strdup(env, object);
            /*printf("\ntitle:%s\n", resource->title);*/
        }

        if(!axutil_strcmp(predicate, "http://www.w3.org/2005/Atomlink"))
        {
            /*resource->link = (axis2_char_t *) axutil_strdup(env, object);
            printf("\nlink:%s\n", resource->link);*/
        }
        
        if(!axutil_strcmp(predicate, "http://purl.org/dc/elements/1.1/date"))
        {
            resource->updated = (axis2_char_t *) axutil_strdup(env, object);
            /*printf("\nupdated:%s\n", resource->updated);*/
        }
        
        if(!axutil_strcmp(predicate, "http://www.w3.org/2005/Atomname"))
        {
            resource->author_username = (axis2_char_t *) axutil_strdup(env, object);
            /*printf("\nauthor_username:%s\n", resource->author_username);*/
        }

        if(!axutil_strcmp(predicate, "http://purl.org/rss/1.0/link"))
        {
            resource->id = (axis2_char_t *) axutil_strdup(env, object);
            /*printf("\nid:%s\n", resource->id);*/
        }
        
        if(!axutil_strcmp(predicate, "http://purl.org/rss/1.0/subtitle"))
        {
            resource->subtitle = (axis2_char_t *) axutil_strdup(env, object);
            /*printf("\nsubtitle:%s\n", resource->subtitle);*/
        }
        
        if(!axutil_strcmp(predicate, "http://purl.org/rss/1.0/media_type"))
        {
            resource->media_type = (axis2_char_t *) axutil_strdup(env, object);
            /*printf("\nmedia_type:%s\n", resource->media_type);*/
        }
        
        if(!axutil_strcmp(predicate, "http://purl.org/rss/1.0/parent_path"))
        {
            resource->parent_path = (axis2_char_t *) axutil_strdup(env, object);
            /*printf("\nparent_path:%s\n", resource->parent_path);*/
        }
        
        if(!axutil_strcmp(predicate, "http://purl.org/rss/1.0/last_updated_username"))
        {
            resource->last_updated_username = (axis2_char_t *) axutil_strdup(env, object);
            /*printf("\nlast_updated_username:%s\n", resource->last_updated_username);*/
        }
        
        if(!axutil_strcmp(predicate, "http://purl.org/rss/1.0/directory"))
        {
            resource->directory = (axis2_char_t *) axutil_strdup(env, object);
            /*printf("\ndirectory:%s\n", resource->directory);*/
        }

        if(!axutil_strcmp(predicate, "http://purl.org/rss/1.0/created_time"))
        {
            resource->created_time = (axis2_char_t *) axutil_strdup(env, object);
            /*printf("\ncreated_time:%s\n", resource->created_time);*/
        }

        if(!axutil_strcmp(predicate, "http://purl.org/rss/1.0/items"))
        {
            util->parse_entries = AXIS2_TRUE;
        }
    }
    else /* Parsing entries */
    {
        if(!axutil_strcmp(predicate, "http://www.w3.org/1999/02/22-rdf-syntax-ns#type"))
        {
            if(!axutil_strcmp(object, "http://purl.org/rss/1.0/item"))
            {
                util->parse_entry = AXIS2_TRUE;
                /*if(!util->entry)*/
                {
                    util->entry = reg_client_entry_create(env);
                    axutil_array_list_add(resource->entries, env, util->entry);
                }
            }
        }
        
        if(!axutil_strcmp(predicate, "http://purl.org/rss/1.0/title"))
        {
            util->parse_entry = AXIS2_FALSE;
            util->entry->title = (axis2_char_t *) axutil_strdup(env, object);
            /*printf("\nentry->title:%s\n", util->entry->title);*/
        }

        if(!axutil_strcmp(predicate, "http://www.w3.org/2005/Atomlink"))
        {
            util->parse_entry = AXIS2_FALSE;
            axutil_array_list_add(util->entry->link_list, env, (axis2_char_t *) axutil_strdup(env, object));
            /*printf("\nentry->link:%s\n", (axis2_char_t *) object);*/
        }

    } /* End of parsing entries */  
}

reg_client_resource_t* AXIS2_CALL 
reg_client_util_populate_resource(
	const axutil_env_t *env,
    const axis2_char_t *filename)
{
  raptor_parser* atom_parser=NULL;
  unsigned char *uri_string;
  raptor_uri *uri, *base_uri;
  reg_client_resource_t *resource = NULL;
  reg_client_util_t *util = NULL;

  AXIS2_LOG_TRACE(env->log, AXIS2_LOG_SI, "[savan] Entry:reg_client_util_populate_resource");
  raptor_init();
  util = AXIS2_MALLOC(env->allocator, sizeof(reg_client_util_t));
  util = reg_client_util_create(env);
  resource = reg_client_resource_create(env);
  util->resource = resource;
  util->env = env;
  util->parse_entries = AXIS2_FALSE;

  atom_parser=raptor_new_parser("rss-tag-soup");

  raptor_set_statement_handler(atom_parser, util, populate_resource);

  uri_string=raptor_uri_filename_to_uri_string((char *) filename);
  uri=raptor_new_uri(uri_string);
  base_uri=raptor_uri_copy(uri);

  raptor_parse_file(atom_parser, uri, base_uri);

  raptor_free_parser(atom_parser);

  raptor_free_uri(base_uri);
  raptor_free_uri(uri);
  raptor_free_memory(uri_string);

  raptor_finish();
  AXIS2_LOG_TRACE(env->log, AXIS2_LOG_SI, "[savan] Exit:reg_client_util_populate_resource");

  return resource;
}

