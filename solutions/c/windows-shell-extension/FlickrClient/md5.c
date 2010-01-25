
/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdio.h>
#include <axutil_string.h>
#include <axutil_env.h>
#include <md5/md5.h>

static void md5_file (char *filename, const axutil_env_t * env)
{
    FILE * file;
    axutil_md5_ctx_t * context;
    int len, i;
    unsigned char buffer[1024], digest[16];

    if ((file = fopen (filename, "rb")) == NULL)
    {
        printf ("%s can't be opened\n", filename);
    }
    else
    {
        context = axutil_md5_ctx_create(env);
        while ((len = fread (buffer, 1, 1024, file)) != 0)
        {
	printf("%i\n", len);
            axutil_md5_update(context, env, buffer, len);
        }
        axutil_md5_final(context, env, digest);
        axutil_md5_ctx_free(context, env);
        fclose (file);
        printf ("MD5 (%s) = ", filename);
        for (i = 0; i < 16; i++)
        {
            printf ("%02x", digest[i]);
        }
        printf ("\n");
    }
}

int
main(
    int argc,
    char **argv)
{
    const axutil_env_t *env = NULL;

    env = axutil_env_create_all("md5.log", AXIS2_LOG_LEVEL_DEBUG);
    if (argc > 1)
    {
        if (axutil_strcmp(argv[1], "-h") == 0)
        {
            printf("Usage : %s [file_name]\n", argv[0]);
            printf("use -h for help\n");
            return 0;
        }
        else
        {
            md5_file(argv[1], env);
        }
    }
    if (env)
    {
        axutil_env_free((axutil_env_t *) env);
        env = NULL;
    }
    return 0;
}
