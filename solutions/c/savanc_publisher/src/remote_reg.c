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
#include <reg_client_remote_reg.h>
#include <reg_client_rest_client.h>
#include <curl/curl.h>
#include <axiom_xml_reader.h>
#include <axiom_stax_builder.h>
#include <axiom_document.h>
#include <axiom_node.h>
#include <axiom_element.h>
#include <savan_subscriber.h>
#include <savan_util.h>
#include <savan_db_mgr.h>
#include <savan_constants.h>
#include <reg_client_resource.h>

/** 
 * @brief remote_reg struct impl
 *	Registration Client Remote Registry
 */
  
struct reg_client_remote_reg_t 
{
    reg_client_rest_client_t *rest_client;
    axis2_char_t *reg_url;
    axis2_conf_t *conf;
};

static axis2_status_t AXIS2_CALL 
reg_client_remote_reg_process_subtitle(
    reg_client_remote_reg_t *remote_reg,
	const axutil_env_t *env,
    const axis2_char_t *link,
    axis2_conf_t *conf);

static axis2_status_t AXIS2_CALL 
reg_client_remote_reg_process_subscriber(
    reg_client_remote_reg_t *remote_reg,
	const axutil_env_t *env,
    const axis2_char_t *link,
    axis2_conf_t *conf);

static axis2_status_t AXIS2_CALL 
reg_client_remote_reg_parse_subscriber(
    reg_client_remote_reg_t *remote_reg,
    const axutil_env_t *env,
    axis2_conf_t *conf);

AXIS2_EXTERN reg_client_remote_reg_t* AXIS2_CALL
reg_client_remote_reg_create(
    const axutil_env_t *env,  
    axis2_conf_t *conf,
    axis2_char_t *publisher_svc)
{
    reg_client_remote_reg_t *remote_reg = NULL;
    axis2_char_t *reg_url = NULL;
    axis2_char_t *username = NULL;
    axis2_char_t *password = NULL;
    axis2_svc_t *subs_svc = NULL;
    axutil_param_t *param = NULL;

    remote_reg =  (reg_client_remote_reg_t *)AXIS2_MALLOC(env->allocator, 
            sizeof(reg_client_remote_reg_t));
	
    if(!remote_reg)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}

    if(conf)
    {
        subs_svc = axis2_conf_get_svc(conf, env, publisher_svc);
        if(!subs_svc)
        {
            subs_svc = axis2_conf_get_svc(conf, env, SAVAN_SUBSCRIPTION_MANAGER);
        }
        param = axis2_svc_get_param(subs_svc, env, REG_CLIENT_REGISTRY_URL);
        if(param)
        {
            reg_url = axutil_param_get_value(param, env);
        }

        param = axis2_svc_get_param(subs_svc, env, REG_CLIENT_REGISTRY_USERNAME);
        if(param)
        {
            username = axutil_param_get_value(param, env);
        }

        param = axis2_svc_get_param(subs_svc, env, REG_CLIENT_REGISTRY_PASSWORD);
        if(param)
        {
            password = axutil_param_get_value(param, env);
        }
    }
    else
    {
        reg_url = "http://localhost:8082/wso2registry/atom";
        username = "damitha";
        password = "damitha";
    }
   
    printf("username:%s\n", username);
    printf("password:%s\n", password);
    remote_reg->rest_client = reg_client_rest_client_create(env, reg_url, username, password);
    remote_reg->reg_url = axutil_strdup(env, reg_url);
    remote_reg->conf = conf;

	return remote_reg;
}


axis2_status_t AXIS2_CALL 
reg_client_remote_reg_free(
    reg_client_remote_reg_t *remote_reg, 
    const axutil_env_t *env)
{
    if(remote_reg->rest_client)
    {
        reg_client_rest_client_free(remote_reg->rest_client, env);
        remote_reg->rest_client = NULL;
    }
    
    if(remote_reg->reg_url)
    {
        AXIS2_FREE(env->allocator, remote_reg->reg_url);
        remote_reg->reg_url = NULL;
    }
    
    remote_reg->conf = NULL;

	AXIS2_FREE(env->allocator, remote_reg);

	return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL 
reg_client_remote_reg_get(
    reg_client_remote_reg_t *remote_reg,
	const axutil_env_t *env,
    const axis2_char_t *path,
    const axutil_array_list_t *params,
    axis2_conf_t *conf)
{
    axis2_status_t status = AXIS2_SUCCESS;
    axis2_char_t *url = NULL;
    reg_client_resource_t *resource = NULL;

    url = axutil_strcat(env, remote_reg->reg_url, path, NULL);

    reg_client_rest_client_get(remote_reg->rest_client, env, url, params);
    if(reg_client_rest_client_get_status(remote_reg->rest_client, env) == 200)
    {
        resource = reg_client_util_populate_resource(env, REG_CLIENT_ATOM_DATA_FILE_NAME);
    }

    if(resource)
    {
        /* Populate the Topics table */
        int i = 0, size = 0;

        if(resource->entries)
        {
            size = axutil_array_list_size(resource->entries, env);
        }

        for(i = 0; i < size; i++)
        {
            reg_client_entry_t *entry = NULL;
            axis2_char_t *link = NULL;
            axis2_char_t *topic_url = NULL;
            axis2_char_t *topic_name = NULL;
            axis2_char_t *dbname = NULL;

            entry = axutil_array_list_get(resource->entries, env, i);
            topic_url = entry->title;
            topic_name = savan_util_get_topic_name_from_topic_url(env, topic_url);

            /*dbname = savan_util_get_dbname(env, remote_reg->conf);*/
            dbname = "/tmp/savan_db";
          
            /* Adding topic name. Later add the topic url at the initialization of the subscription 
             * manager service.
             */
            /*if(savan_db_mgr_insert_topic(env, dbname, topic_name, NULL))
            {
                printf("topic added:%s\n", topic_name);
                AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[savan] Topic %s added", topic_name);
            }
            else
            {
                AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[savan] Topic %s could not be added", topic_name);
            }*/

            /* TODO Insert into topic table */
            link = axutil_array_list_get(entry->link_list, env, 0);
            /* Now we go on and get the subscribers for the main topic and sub topics recursively */
            status = reg_client_remote_reg_process_subtitle(remote_reg, env, link, conf);
        }
    }

    return status;
}

axis2_status_t AXIS2_CALL 
reg_client_remote_reg_delete(
    reg_client_remote_reg_t *remote_reg,
	const axutil_env_t *env,
    const axis2_char_t *path)
{
    axis2_char_t *url = NULL;

    url = axutil_strcat(env, remote_reg->reg_url, path, NULL);

    reg_client_rest_client_delete(remote_reg->rest_client, env, url, NULL);
    if(reg_client_rest_client_get_status(remote_reg->rest_client, env) == 204)
    {
        return AXIS2_SUCCESS;
    }

    return AXIS2_FAILURE;
}

axis2_status_t AXIS2_CALL 
reg_client_remote_reg_post(
    reg_client_remote_reg_t *remote_reg,
	const axutil_env_t *env,
    const axis2_char_t *path,
    const axis2_char_t *data)
{
    axis2_char_t *url = NULL;
    axis2_char_t *content_type = NULL;

    url = axutil_strcat(env, remote_reg->reg_url, path, NULL);
    content_type = "application/atom+xml;type=entr";

    reg_client_rest_client_post(remote_reg->rest_client, env, url, data, content_type);
    if(reg_client_rest_client_get_status(remote_reg->rest_client, env) == 200)
    {
        return AXIS2_SUCCESS;
    }

    return AXIS2_FAILURE;
}

AXIS2_EXTERN void AXIS2_CALL
reg_client_remote_reg_init(
    const axutil_env_t *env)
{
    curl_global_init(CURL_GLOBAL_ALL);
}

AXIS2_EXTERN void AXIS2_CALL
reg_client_remote_reg_cleanup(
    const axutil_env_t *env)
{
    curl_global_cleanup();
}

static axis2_status_t AXIS2_CALL 
reg_client_remote_reg_process_subtitle(
    reg_client_remote_reg_t *remote_reg,
	const axutil_env_t *env,
    const axis2_char_t *link,
    axis2_conf_t *conf)
{
    axis2_status_t status = AXIS2_SUCCESS;
    reg_client_resource_t *child_resource = NULL;

    reg_client_rest_client_get(remote_reg->rest_client, env, link, NULL);
    if(reg_client_rest_client_get_status(remote_reg->rest_client, env) == 200)
    {
        child_resource = reg_client_util_populate_resource(env, REG_CLIENT_ATOM_DATA_FILE_NAME);
        if(child_resource)
        {
            int i = 0, size = 0;

            if(child_resource->entries)
            {
                if(child_resource->entries)
                {
                    size = axutil_array_list_size(child_resource->entries, env);
                }

                for(i = 0; i < size; i++)
                {
                    reg_client_entry_t *entry = NULL;
                    axis2_char_t *link = NULL;
                    axis2_char_t *title = NULL;
                    axis2_char_t *temp_str = NULL;

                    entry = axutil_array_list_get(child_resource->entries, env, i);
                    title = entry->title;
                    temp_str = axutil_strstr(title, "system.subscriptions");
                    link = axutil_array_list_get(entry->link_list, env, 0);
                    if(temp_str)
                    {
                        /* Get the subscriber xml and populate subscriber table */
                        reg_client_remote_reg_process_subscriber(remote_reg, env, link, conf);
                    }
                    else /* title is a sub topic */
                    {
                        /* Now we repeat the process until all the subtopics are consumed */
                        status = reg_client_remote_reg_process_subtitle(remote_reg, env, link, conf);
                        if(AXIS2_SUCCESS != status)
                        {
                            break;
                        }
                    }
                }
            }
        }
    }

    return status;
}

static axis2_status_t AXIS2_CALL 
reg_client_remote_reg_process_subscriber(
    reg_client_remote_reg_t *remote_reg,
	const axutil_env_t *env,
    const axis2_char_t *link,
    axis2_conf_t *conf)
{
    axis2_status_t status = AXIS2_SUCCESS;
    reg_client_resource_t *subs_resource = NULL;

    reg_client_rest_client_get(remote_reg->rest_client, env, link, NULL);
    if(reg_client_rest_client_get_status(remote_reg->rest_client, env) == 200)
    {
        subs_resource = reg_client_util_populate_resource(env, REG_CLIENT_ATOM_DATA_FILE_NAME);
        if(subs_resource)
        {
            int i = 0, size = 0;

            if(subs_resource->entries)
            {
                if(subs_resource->entries)
                {
                    size = axutil_array_list_size(subs_resource->entries, env);
                }

                for(i = 0; i < size; i++)
                {
                    reg_client_entry_t *entry = NULL;
                    axis2_char_t *link = NULL;
                    axis2_char_t *title = NULL;

                    entry = axutil_array_list_get(subs_resource->entries, env, i);
                    title = entry->title;
                    printf("title:%s\n", entry->title);
                    link = axutil_array_list_get(entry->link_list, env, 3);
                    printf("link:%s\n", link);
                    reg_client_rest_client_get(remote_reg->rest_client, env, link, NULL);
                    if(reg_client_rest_client_get_status(remote_reg->rest_client, env) == 200)
                    {
                        /* Parse and add the subscriber to the storage */
                        reg_client_remote_reg_parse_subscriber(remote_reg, env, conf);
                    }
                }
            }
        }
    }

    return status;
}

/* Parse the downloaded subscriber xml file and create a subscriber. Then store that subscriber
 * into the storage.
 */
static axis2_status_t AXIS2_CALL 
reg_client_remote_reg_parse_subscriber(
    reg_client_remote_reg_t *remote_reg,
    const axutil_env_t *env,
    axis2_conf_t *conf)
{
    savan_subscriber_t *subscriber = NULL;
    axiom_node_t *sub_node = NULL;
    axiom_xml_reader_t *reader = NULL;
    axiom_stax_builder_t *om_builder = NULL;
    axiom_document_t *document = NULL;
    axis2_char_t *dbname = NULL;
    axis2_status_t status = AXIS2_SUCCESS;
    
    AXIS2_LOG_TRACE(env->log, AXIS2_LOG_SI, "[savan] Entry:reg_client_remote_reg_parse_subscriber");
    
    reader = axiom_xml_reader_create_for_file(env, REG_CLIENT_ATOM_DATA_FILE_NAME, NULL);
    if(reader)
    {
        om_builder = axiom_stax_builder_create(env, reader);
        document = axiom_stax_builder_get_document(om_builder, env);
        axiom_document_build_all(document, env);
        sub_node = axiom_document_get_root_element(document, env);
    }

    if (!sub_node)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[savan] Failed to extract the xml node"); 
        return AXIS2_FAILURE;
    }
    
    /* Now read each parse Subscriber element */
    subscriber = savan_util_process_savan_specific_subscriber_node(env, sub_node, conf);
    if(!subscriber)
    {
        status = axutil_error_get_status_code(env->error);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[savan] Parsing subscriber node failed");
        return status;
    } 

    dbname = savan_util_get_dbname(env, remote_reg->conf);
    /*dbname = "/tmp/savan_db";*/
    status = savan_db_mgr_insert_subscriber(env, dbname, subscriber);

    AXIS2_LOG_TRACE(env->log, AXIS2_LOG_SI, "[savan] Exit:reg_client_remote_reg_parse_subscriber");

    return status;    
}

