#include <remote_registry_rest_client.h>
#include <remote_registry_conf.h>
#include <stdio.h>

int rest_test_main()
{
    remote_registry_conf_t *conf = NULL;
    remote_registry_rest_client_t *rest_client = NULL;
    char *res = NULL;
    const axutil_env_t *env = NULL;
    /*const axis2_char_t *url = "http://www.google.lk/";*/
    const axis2_char_t *url = "https://localhost:9443/registry/atom/test";
    /*const axis2_char_t *url = "http://localhost/tests/13_speed_test/test.php";*/

    int res_len = 0;

    env = axutil_env_create_all("test.log", AXIS2_LOG_LEVEL_TRACE);
    conf = remote_registry_conf_create(env);
    rest_client = remote_registry_rest_client_create(env, conf);

    res = remote_registry_rest_client_get(rest_client, env, url, NULL, 0, &res_len);
    
    printf("%s (%d)\n", res, res_len);
    return 0;
}
