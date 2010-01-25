#include <remote_registry_rest_client.h>
#include <remote_registry_conf.h>
#include <stdio.h>
#include <remote_registry.h>
#include <remote_registry_resource.h>


int put_test_main()
{
    remote_registry_t *remote_registry = NULL;
    const axutil_env_t *env = NULL;
    axis2_char_t *path = "/weather3/test2";
    remote_registry_resource_t *res = NULL;
	remote_registry_resource_t *resource = NULL;
	axis2_status_t status;

    int res_len = 0;

    env = axutil_env_create_all("test.log", AXIS2_LOG_LEVEL_TRACE);
    remote_registry = remote_registry_create(env, "http://localhost:9762/registry", "admin", "admin");

	// creating the resource
	resource = remote_registry_resource_create_collection(env);

	remote_registry_resource_set_content(resource, env, axutil_strdup(env, "test"));
	remote_registry_resource_set_media_type(resource, env, "text/plain");
	remote_registry_resource_set_description(resource, env, "something");

	status = remote_registry_put(remote_registry, env, path, resource);

	if(status == AXIS2_SUCCESS) {
		printf("Success in putting the resource\n");
	}
	
	/* invoking it for the second time */
	status = remote_registry_put(remote_registry, env, path, resource);

	if(status == AXIS2_SUCCESS) {
		printf("Success in putting the resource\n");
	}

    return 0;
}
