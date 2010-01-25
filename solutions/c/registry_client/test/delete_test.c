#include <stdio.h>
#include <remote_registry.h>


int delete_test_main()
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
	
	// creating the resource
	resource = remote_registry_resource_create_collection(env);

	remote_registry_resource_set_content(resource, env, axutil_strdup(env, "test"));
	remote_registry_resource_set_media_type(resource, env, "text/plain");
	remote_registry_resource_set_description(resource, env, "something");

	status = remote_registry_put(remote_registry, env, path, resource);

	// delete the resource
	remote_registry_delete(remote_registry, env, path);
    return 0;
}
