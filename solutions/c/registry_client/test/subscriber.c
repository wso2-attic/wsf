#include <remote_registry_rest_client.h>
#include <remote_registry_conf.h>
#include <stdio.h>
#include <remote_registry.h>
#include <remote_registry_resource.h>
#include <axutil_uuid_gen.h>
#include <axutil_property.h>

#define SUBSCRIPTION_COLLECTION_NAME "system.subscriptions"
#define TOPIC_INDEX "/eventing/index/TopicIndex"

static void topic_index_init()
{
    remote_registry_t *remote_registry = NULL;
    const axutil_env_t *env = NULL;
    remote_registry_resource_t *res = NULL;
    axis2_char_t *id = NULL;
	
    axis2_char_t *reg_url = "http://localhost:9762/registry";

    env = axutil_env_create_all("test.log", AXIS2_LOG_LEVEL_TRACE);
    remote_registry = remote_registry_create(env, reg_url, "admin", "admin");

    res = remote_registry_get(remote_registry, env, TOPIC_INDEX, NULL);
    if(!res)
    {
        printf("came\n");
        res = remote_registry_resource_create(env);
        id = axutil_strcat(env, reg_url, TOPIC_INDEX, NULL);
        remote_registry_resource_set_id(res, env, id);
        remote_registry_resource_set_title(res, env, TOPIC_INDEX);
        remote_registry_resource_set_parent_path(res, env, "");
        remote_registry_resource_set_properties(res, env, axutil_hash_make(env));
        remote_registry_resource_set_author_name(res, env, "admin");
        remote_registry_resource_set_description(res, env, "");
        remote_registry_resource_set_last_modified_time(res, env, axutil_date_time_create(env));
        remote_registry_put(remote_registry, env, TOPIC_INDEX, res);
        return;
    }
}

int add_subscriber()
{
    remote_registry_t *remote_registry = NULL;
    const axutil_env_t *env = NULL;
    axis2_char_t *subscription_id = NULL;
    axis2_char_t *id = NULL;
    axis2_char_t *path = NULL; 
    axis2_char_t *index_path = NULL; 
    remote_registry_resource_t *res = NULL;
    axutil_hash_t *properties = NULL;
    int res_len = 0;
	
    char *content = strdup("<subscription><syn:endpoint xmlns:syn=\"http://ws.apache.org/ns/synapse\"><syn:address "\
                     "uri=\"http://localhost:9000/services/SimpleStockQuoteService\" /></syn:endpoint></subscription>");

    axis2_char_t *epr_type = "application/vnd.epr";
    axis2_char_t *filter = "/weather/4/";
    axis2_char_t *reg_url = "http://localhost:9762/registry";

    env = axutil_env_create_all("test.log", AXIS2_LOG_LEVEL_TRACE);
    subscription_id = axutil_strcat(env, "urn:uuid:", axutil_uuid_gen(env), NULL);
    path = axutil_strcat(env, filter, SUBSCRIPTION_COLLECTION_NAME, "/", subscription_id, NULL);
    id = axutil_strcat(env, reg_url, filter, SUBSCRIPTION_COLLECTION_NAME, "/", subscription_id, NULL);
    remote_registry = remote_registry_create(env, reg_url, "admin", "admin");

    topic_index_init();
    res = remote_registry_resource_create(env);
    remote_registry_resource_set_content(res, env, content);
    remote_registry_resource_set_content_len(res, env, axutil_strlen(content));
    remote_registry_resource_set_id(res, env, id);
    remote_registry_resource_set_media_type(res, env, epr_type);
    remote_registry_resource_set_title(res, env, path);
    remote_registry_resource_set_author_name(res, env, "admin");
    remote_registry_resource_set_description(res, env, "");
	remote_registry_resource_set_last_modified_time(res, env, axutil_date_time_create(env));

    properties = axutil_hash_make(env);
    if(properties)
    {
        axutil_hash_set(properties, axutil_strdup(env, "expires"), AXIS2_HASH_KEY_STRING, axutil_strdup(env, "*"));
        axutil_hash_set(properties, axutil_strdup(env, "staticFlag"), AXIS2_HASH_KEY_STRING, axutil_strdup(env, "false"));
        axutil_hash_set(properties, axutil_strdup(env, "filterValue"), AXIS2_HASH_KEY_STRING, axutil_strdup(env, filter));
        axutil_hash_set(properties, axutil_strdup(env, "subManagerURI"), AXIS2_HASH_KEY_STRING, axutil_strdup(env, "http://10.100.1.44:8280/services/SampleEventSource"));
        axutil_hash_set(properties, axutil_strdup(env, "filterDialect"), AXIS2_HASH_KEY_STRING, axutil_strdup(env, "http://synapse.apache.org/eventing/dialect/topicFilter"));
        remote_registry_resource_set_properties(res, env, properties);
    }

    remote_registry_put(remote_registry, env, path, res);
    if(id)
    {
        AXIS2_FREE(env->allocator, id);
    }
    if(path)
    {
        AXIS2_FREE(env->allocator, path);
        path = NULL;
    }
    if(res)
    {
        remote_registry_resource_free(res, env);
        res = NULL;
    }

    res = remote_registry_get(remote_registry, env, TOPIC_INDEX, NULL);
    if(!res)
    {
        return 0;
    }
    id = axutil_strcat(env, reg_url, TOPIC_INDEX, NULL);
    remote_registry_resource_set_id(res, env, id);
    remote_registry_resource_set_title(res, env, TOPIC_INDEX);
    properties = remote_registry_resource_get_properties(res, env);
    if(properties)
    {
        path = axutil_strcat(env, filter, SUBSCRIPTION_COLLECTION_NAME, NULL);
        axutil_hash_set(properties, subscription_id, AXIS2_HASH_KEY_STRING, path);
        remote_registry_resource_set_properties(res, env, properties);
    }

    remote_registry_resource_set_content(res, env, NULL);
    remote_registry_resource_set_content_len(res, env, 0);
    remote_registry_resource_set_parent_path(res, env, "/eventing/index");
    index_path = axutil_strcat(env, TOPIC_INDEX, "/TopicIndex", NULL);
    remote_registry_put(remote_registry, env, index_path, res);

    if(id)
    {
        AXIS2_FREE(env->allocator, id);
    }
    if(res)
    {
        remote_registry_resource_free(res, env);
        res = NULL;
    }
    printf("\n");

    return 0;
}

void get_all_subscribers()
{
    remote_registry_t *remote_registry = NULL;
    const axutil_env_t *env = NULL;
    remote_registry_resource_t *res = NULL;
    axutil_hash_t *properties = NULL;
	
    axis2_char_t *path = NULL;
    axis2_char_t *reg_url = "http://localhost:9762/registry";

    env = axutil_env_create_all("test.log", AXIS2_LOG_LEVEL_TRACE);
    remote_registry = remote_registry_create(env, reg_url, "admin", "admin");

    res = remote_registry_get(remote_registry, env, TOPIC_INDEX, NULL);
    if(!res)
    {
        return;
    }

    properties = remote_registry_resource_get_properties(res, env);
    if(properties)
    {
        axutil_hash_index_t *hi;
        void *val;
        void *key;
        int sum = 0;
        for (hi = axutil_hash_first(properties, env); hi; hi = axutil_hash_next(env, hi)) 
        {
            axutil_hash_this(hi, (const void**)&key, NULL, &val);
            path = axutil_strcat(env, val, "/", key, NULL);
            res = remote_registry_get(remote_registry, env, path, NULL);
            if(res)
            {
                /*remote_registry_load_content_for_resource(remote_registry, env, res); */
                if(res)
                {
                    printf("\n\nresource id:%s\n\n",remote_registry_resource_get_id(res, env));
                }
            }
        }
    }

    remote_registry_resource_free(res, env);
}

void get_all_subscribers_for_topic(axis2_char_t *topic)
{
    remote_registry_t *remote_registry = NULL;
    const axutil_env_t *env = NULL;
    remote_registry_resource_t *res = NULL;
    axutil_hash_t *properties = NULL;
    remote_registry_resource_t *topic_resource = NULL;
	
    axis2_char_t *path = NULL;
    axis2_char_t *reg_url = "http://localhost:9762/registry";

    env = axutil_env_create_all("test.log", AXIS2_LOG_LEVEL_TRACE);
    remote_registry = remote_registry_create(env, reg_url, "admin", "admin");

    topic_resource = remote_registry_get(remote_registry, env, topic, NULL);
    if(topic_resource)
    {
        axutil_array_list_t *child_entries = NULL;
        int i = 0;

        child_entries = remote_registry_resource_get_entries(topic_resource, env);
        if(child_entries)
        {
            /* load the child entries recursively */
            for(i = 0; i < axutil_array_list_size(child_entries, env); i ++)
            {
                remote_registry_resource_t *child_resource = NULL;

                child_resource = (remote_registry_resource_t*)axutil_array_list_get(child_entries, env, i);

                /* loading the resources */
                /*remote_registry_load_content_for_resource(remote_registry, env, child_resource); */
                if(child_resource)
                {
                    printf("\n\nresource id:%s\n\n",remote_registry_resource_get_id(child_resource, env));
                }
            }
        }
    }
}

void remove_subscriber(axis2_char_t *id)
{
    remote_registry_t *remote_registry = NULL;
    const axutil_env_t *env = NULL;
    remote_registry_resource_t *res = NULL;
    axis2_char_t *val;
    axis2_char_t *index_path = NULL; 
    axis2_status_t status = AXIS2_FAILURE;
	
    axis2_char_t *path = NULL;
    axis2_char_t *reg_url = "http://localhost:9762/registry";

    env = axutil_env_create_all("test.log", AXIS2_LOG_LEVEL_TRACE);
    remote_registry = remote_registry_create(env, reg_url, "admin", "admin");

    res = remote_registry_get(remote_registry, env, TOPIC_INDEX, NULL);
    if(!res)
    {
        return;
    }
    printf("\n\nroot resource id:%s\n\n",remote_registry_resource_get_id(res, env));

    val = remote_registry_resource_get_property(res, env, id);
    if(val)
    {
        path = axutil_strcat(env, val, "/", id, NULL);
        printf("path:%s\n", path);
        status = remote_registry_delete(remote_registry, env, path);
    }
    if(AXIS2_SUCCESS != status)
    {
        printf("\nSubscription deletion failed\n");
    }

    res = remote_registry_get(remote_registry, env, TOPIC_INDEX, NULL);
    if(!res)
    {
        return;
    }
    printf("\n\nroot resource id:%s\n\n",remote_registry_resource_get_id(res, env));

    /*remote_registry_resource_remove_property(res, env, id);

    remote_registry_resource_set_content(res, env, NULL);
    remote_registry_resource_set_content_len(res, env, 0);
    remote_registry_resource_set_parent_path(res, env, "/eventing/index");
    index_path = axutil_strcat(env, TOPIC_INDEX, "/TopicIndex", NULL);
    remote_registry_put(remote_registry, env, index_path, res);*/
    remote_registry_resource_free(res, env);
}


