#include <remote_registry_rest_client.h>
#include <remote_registry_conf.h>
#include <stdio.h>
#include <remote_registry.h>
#include <remote_registry_resource.h>

int print_comments(const axutil_env_t *env,
        axutil_array_list_t *comments)
{
	axis2_char_t *user = NULL;
	axis2_char_t *text = NULL;
	remote_registry_comment_t *comment = NULL;
	int i = 0;

	for(i = 0; i < axutil_array_list_size(comments, env); i ++)
	{
		comment = (remote_registry_comment_t*)axutil_array_list_get(comments, env, i);
		user = remote_registry_comment_get_user(comment, env);
		text = remote_registry_comment_get_text(comment, env);

		printf("%s:\t\%s\n", user, text);
	}
	return 0;
}


int comment_test_main()
{

    remote_registry_t *remote_registry = NULL;
    const axutil_env_t *env = NULL;
    axis2_char_t *path = "/";
    axutil_array_list_t *comments = NULL;

    int res_len = 0;

    env = axutil_env_create_all("test.log", AXIS2_LOG_LEVEL_TRACE);
    remote_registry = remote_registry_create(env, "http://localhost:9762/registry", "admin", "admin");

    comments = remote_registry_get_comments(remote_registry, env, path);

    if(comments) 
    {
        print_comments(env, comments);
    }

    printf("-----------------------------------------------------------------------\n");
    printf("Return the resources from the cache\n");
    printf("-----------------------------------------------------------------------\n");


    comments = remote_registry_get_comments(remote_registry, env, path);
   
    if(comments) 
    {
        print_comments(env, comments);
    }


    
    return 0;
}
