#include <reg_client_constants.h>
#include <reg_client_rest_client.h>
#include <reg_client_remote_reg.h>
#include <axutil_url.h>
#include <axutil_string.h>
#include <curl/curl.h>
#include <curl/types.h>
#include <curl/easy.h>

int main(void)
{
    axutil_env_t *env = NULL;
    const axis2_char_t *filename = "atom_data.xml";

    env = axutil_env_create_all("test.log", AXIS2_LOG_LEVEL_TRACE);

    reg_client_util_populate_resource(env, filename);
    return 0;
}

