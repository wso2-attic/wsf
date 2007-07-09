#include <stdio.h>
#include <rampart_util.h>
#include <rampart_crypto_util.h>
#include <axis2_util.h>
#include <axutil_base64.h>

axutil_env_t *test_init()
{
    axutil_allocator_t *allocator = axutil_allocator_init(NULL);
    axutil_error_t *error = (axutil_error_t*)axis2_error_create(allocator);
    axutil_env_t *env = axutil_env_create_with_error(allocator, error);
    return env;
}

int main()
{
    axis2_char_t* hash = NULL;
    axutil_env_t *env = NULL;
    axis2_char_t* nonce = NULL;
    axis2_char_t* created = NULL;

    env = test_init();

    printf("--Testing started--------------------------------------------\n");
    printf("\n--Testing hash-----------------------------------------------\n");

    hash = rampart_crypto_sha1(env, "WScqanjCEAC4mQoBE07sAQ==", "2003-07-16T01:24:32Z", "IloveDogs");
    if (!hash)
    {
        printf("No hash generated :( ...\n");
    }
    printf("Hash = %s", hash);
#if 0
    /*encode Base64*/
    axis2_char_t* encodedStr = NULL;


    encodedStr = AXIS2_MALLOC(env->allocator, 20);
    axutil_base64_encode_binary(encodedStr, hash, 20);

    printf("Hash = %s \n", encodedStr);
#endif
    printf("\n----Testing nonce------------------------------------------\n");
    nonce = rampart_generate_nonce(env);
    printf("NONCE: %s", nonce);

    printf("\n----Testing created----------------------------------------\n");
    created = rampart_generate_time(env, 300);
    printf("CREATED: %s", created);
    printf("\n----End of testings----------------------------------------\n");
    return 0;
}


