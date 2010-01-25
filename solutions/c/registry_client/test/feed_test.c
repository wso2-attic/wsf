#include <remote_registry_resource.h>
#include <stdio.h>

#define MAX_SIZE 100
#define MAX_ALLOC 100

axis2_char_t *
axutil_properties_read(
    FILE *input,
    const axutil_env_t *env);

int feed_test_main()
{
    axis2_char_t *buffer = NULL;
    axutil_env_t *env = NULL;
    FILE *file;

    remote_registry_resource_t *resource = NULL;

    env = axutil_env_create_all("test.log", AXIS2_LOG_LEVEL_TRACE);

    file = fopen("feed.xml", "r+");
    buffer = axutil_properties_read(file, env);

    resource = remote_registry_resource_create_from_feed(env, buffer, "text");
    

    printf("id: %s\n", remote_registry_resource_get_id(resource, env));
    return 0;
}


axis2_char_t *
axutil_properties_read(
    FILE *input,
    const axutil_env_t *env)
{
    size_t nread = 0;
    axis2_char_t *out_stream = NULL;
    size_t ncount = 0;
    size_t curr_alloc = MAX_SIZE * 2;
    size_t total_alloc = curr_alloc;

    out_stream =
        (axis2_char_t *) AXIS2_MALLOC(env->allocator,
                                      sizeof(axis2_char_t) * curr_alloc);
    if (!out_stream)
    {
        return NULL;
    }

    do
    {
        nread =
            fread(out_stream + ncount, sizeof(axis2_char_t), MAX_SIZE, input);
        ncount += nread;

        if (ncount + MAX_SIZE > total_alloc)
        {
            axis2_char_t *new_stream = NULL;
            if (curr_alloc < MAX_ALLOC)
            {
                curr_alloc *= 2;
            }

            total_alloc += curr_alloc;
            new_stream =
                AXIS2_MALLOC(env->allocator,
                             sizeof(axis2_char_t) * total_alloc);
            if (!new_stream)
            {
                if (out_stream)
                {
                    AXIS2_FREE(env->allocator, out_stream);
                }
                return NULL;
            }

            memcpy(new_stream, out_stream, sizeof(axis2_char_t) * ncount);
            if (out_stream)
            {
                AXIS2_FREE(env->allocator, out_stream);
            }

            out_stream = new_stream;
        }
    }
    while (nread == MAX_SIZE);

    out_stream[ncount] = '\0';
    return out_stream;
}

