#include "axis2_stub_Calculator.h"

int
main(int argc, char *argv)
{
    axutil_env_t* env = NULL;
    axis2_char_t* operation = NULL;
    axis2_char_t* client_home = NULL;
    axis2_char_t* endpoint_uri = NULL;
    axis2_stub_t* stub = NULL;

    axis2_addResponse_t *add_res = NULL;
    axis2_add_t *add_in = NULL;

    int res_val = 0;
    endpoint_uri = "http://localhost:9090/axis2/services/Calculator";

    env = axutil_env_create_all("alltest.log", AXIS2_LOG_LEVEL_TRACE);

    /* Set up deploy folder.*/
    client_home = AXIS2_GETENV("AXIS2C_HOME");
    if (!client_home)
        client_home = "../../../deploy";

    stub = axis2_stub_Calculator_create(env, client_home , endpoint_uri);

    add_in = axis2_add_create(env);

    axis2_add_set_arg_0_0(add_in, env, 10);
    axis2_add_set_arg_1_0(add_in, env, 10);

    add_res =  axis2_stub_Calculator_add(stub, env, add_in);

    if(!add_res)
    {
        printf("Error: response NULL\n");
        return -1;
    }

    res_val = axis2_addResponse_get_addReturn(add_res, env);

    printf("ADD Result:%d ", res_val);

    return 0;
}

