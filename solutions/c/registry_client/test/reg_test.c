#include <remote_registry_rest_client.h>
#include <remote_registry_conf.h>
#include <stdio.h>
#include <remote_registry.h>
#include <remote_registry_resource.h>

int print_ids(const axutil_env_t *env,
        remote_registry_resource_t *res, int level)
{
    int i = 0;
    axis2_char_t *id = NULL;
    axutil_array_list_t *entries = NULL;
    char *content = NULL;
    axis2_char_t *media_type = NULL;
    axis2_char_t *path = NULL;
    axis2_char_t *content_src_url = NULL;
	axutil_hash_t *properties = NULL;

    /* printing spaces */
    for(i = 0; i < level*4 ; i ++) {
        printf(" ");
    }
    
    id = remote_registry_resource_get_id(res, env);
	content = remote_registry_resource_get_content(res, env);
	properties = remote_registry_resource_get_properties(res, env);
    

	if(content) {
		printf("%s\n\n", content);
	}
	if(properties)
    {
        axutil_hash_index_t *hi;
        void *val;
        void *key;
        int sum = 0;
        for (hi = axutil_hash_first(properties, env); hi; hi = axutil_hash_next(env, hi)) 
		{
            axutil_hash_this(hi, (const void**)&key, NULL, &val);
			printf("%s=%s\n", key, val);
        }
    }

    entries = remote_registry_resource_get_entries(res, env);

    if(entries) {
        for(i = 0; i < axutil_array_list_size(entries, env); i ++) 
        {
            remote_registry_resource_t *child_res = NULL;

            child_res = axutil_array_list_get(entries, env, i);

            print_ids(env, child_res, level + 1);
        }
    }
}


int reg_test_main()
{
    remote_registry_t *remote_registry = NULL;
    const axutil_env_t *env = NULL;
    axis2_char_t *path = "/weather";
    remote_registry_resource_t *res = NULL;

    int res_len = 0;

    env = axutil_env_create_all("test.log", AXIS2_LOG_LEVEL_TRACE);
    remote_registry = remote_registry_create(env, "https://localhost:9443/registry/atom", "admin", "admin");

    res = remote_registry_get_recursively(remote_registry, env, path, NULL);

    if(res) 
    {
        print_ids(env, res, 0);
    }

    printf("-----------------------------------------------------------------------\n");
    printf("Return the resources from the cache\n");
    printf("-----------------------------------------------------------------------\n");

     if(res) 
    {
        remote_registry_resource_free(res, env);
    }

    res = remote_registry_get_recursively(remote_registry, env, path, NULL);
   
    if(res) 
    {
        print_ids(env, res, 0);
    }


    
    return 0;
}
