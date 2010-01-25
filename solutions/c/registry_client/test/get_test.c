#include <stdio.h>
#include <remote_registry.h>


int get_test_main()
{
    remote_registry_t *remote_registry = NULL;
    const axutil_env_t *env = NULL;
    axis2_char_t *path = "/test/10000.txt";
    remote_registry_resource_t *res = NULL;
	remote_registry_resource_t *resource = NULL;
	axis2_status_t status;
	axis2_char_t *content = NULL;
	int i = 0;
	axutil_array_list_t *child_paths = NULL;

    int res_len = 0;

    env = axutil_env_create_all("test.log", AXIS2_LOG_LEVEL_TRACE);
    remote_registry = remote_registry_create(env, "http://localhost:9762/registry", "admin", "admin");

	// getting the resource
	
	
	resource = remote_registry_get(remote_registry, env, path, NULL);
	content = remote_registry_resource_get_content(resource, env);
	printf("%s\n", content);

	resource = remote_registry_get(remote_registry, env, path, NULL);
	content = remote_registry_resource_get_content(resource, env);
	printf("%s\n", content);
	

	
	path = "/test/";
	resource = remote_registry_get(remote_registry, env, path, NULL);
	child_paths = remote_registry_resource_get_children(resource, env);

	for(i = 0; i < axutil_array_list_size(child_paths, env); i ++) 
	{
		axis2_char_t *child_path = axutil_array_list_get(child_paths, env, i);
		printf("%d: %s\n", i, child_path);
	}

	resource = remote_registry_get(remote_registry, env, path, NULL);
	child_paths = remote_registry_resource_get_children(resource, env);

	for(i = 0; i < axutil_array_list_size(child_paths, env); i ++) 
	{
		axis2_char_t *child_path = axutil_array_list_get(child_paths, env, i);
		printf("%d: %s\n", i, child_path);
	}
	

    return 0;
}
