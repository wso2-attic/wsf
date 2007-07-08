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

#include <axutil_dir_handler.h>
#include <axutil_file.h>
#include <platforms/axutil_platform_auto_sense.h>
#include <axutil_string.h>
#ifndef S_ISDIR
#   define S_ISDIR(m) ((m & S_IFMT) == S_IFDIR)
#endif

#include <minizip/axis2_archive_extract.h>

extern int AXIS2_ALPHASORT();
#ifdef IS_MACOSX
int dir_select(struct dirent *entry);
#else
int dir_select(const struct dirent *entry);
#endif


/**
 * List the dll files in the given service or module folder path
 * @param pathname path to your service or module directory
 * @return array list of dll file names
 */
AXIS2_EXTERN axutil_array_list_t * AXIS2_CALL
axutil_dir_handler_list_services_or_modules_in_dir(const axutil_env_t *env,
        const axis2_char_t *pathname)
{
    axutil_array_list_t *file_list = NULL;
    struct stat *buf = NULL;
    int count = 1;
    int i = 0;
    struct dirent **files = NULL;
    int file_select();
    axis2_status_t status = AXIS2_FAILURE;

    AXIS2_ENV_CHECK(env, NULL);
    file_list = axutil_array_list_create(env, 100);
    count = AXIS2_SCANDIR(pathname, &files, file_select, AXIS2_ALPHASORT);
    /* If no files found, make a non-selectable menu item */
    if (count <= 0)
    {
        axutil_array_list_free(file_list, env);
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "No files in the path %s.", pathname);
        return NULL;
    }

    for (i = 1; i < (count + 1) ; ++i)
    {
        axis2_char_t *fname = NULL;
        axutil_file_t *arch_file = NULL;
        axis2_char_t *path = NULL;
        axis2_char_t *temp_path = NULL;

        fname = files[i-1]->d_name;
        arch_file = (axutil_file_t *) axutil_file_create(env);
        if (!arch_file)
        {
            int size = 0;
            int j = 0;
            axutil_file_t *del_file = NULL;

            size = axutil_array_list_size(file_list, env);
            for (j = 0; j < size; j++)
            {
                del_file = axutil_array_list_get(file_list, env, j);
                axutil_file_free(del_file, env);
            }
            axutil_array_list_free(file_list, env);
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            return NULL;
        }
         axutil_file_set_name(arch_file, env, fname);
        temp_path = axutil_stracat(env, pathname, AXIS2_PATH_SEP_STR);
        path = axutil_stracat(env, temp_path, fname);
        AXIS2_FREE(env->allocator, temp_path);
        if (!path)
        {
            int size = 0;
            int j = 0;
            axutil_file_t *del_file = NULL;

            axutil_file_free(arch_file, env);
            size = axutil_array_list_size(file_list, env);
            for (j = 0; j < size; j++)
            {
                del_file = axutil_array_list_get(file_list, env, j);
                axutil_file_free(del_file, env);
            }
            axutil_array_list_free(file_list, env);
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            return NULL;
        }
         axutil_file_set_path(arch_file, env, path);
        buf = AXIS2_MALLOC(env->allocator, sizeof(struct stat));
        if (!buf)
        {
            int size = 0;
            int j = 0;
            axutil_file_t *del_file = NULL;

            AXIS2_FREE(env->allocator, path);
            axutil_file_free(arch_file, env);
            size = axutil_array_list_size(file_list, env);
            for (j = 0; j < size; j++)
            {
                del_file = axutil_array_list_get(file_list, env, j);
                axutil_file_free(del_file, env);
            }
            axutil_array_list_free(file_list, env);
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            return NULL;
        }
        stat(path, buf);
         axutil_file_set_timestamp(arch_file, env, (time_t) buf->st_ctime);
        status = axutil_array_list_add(file_list, env, arch_file);
        if (AXIS2_SUCCESS != status)
        {
            int size = 0;
            int j = 0;
            axutil_file_t *del_file = NULL;

            axutil_file_free(arch_file, env);
            AXIS2_FREE(env->allocator, path);
            AXIS2_FREE(env->allocator, buf);
            size = axutil_array_list_size(file_list, env);
            for (j = 0; j < size; j++)
            {
                del_file = axutil_array_list_get(file_list, env, j);
                axutil_file_free(del_file, env);
            }
            axutil_array_list_free(file_list, env);
            return NULL;
        }
        AXIS2_FREE(env->allocator, path);
        AXIS2_FREE(env->allocator, buf);

    }
    return file_list;
}

/**
 * List services or modules directories in the services or modules folder
 * respectively
 * @param pathname path  your modules or services folder
 * @return array list of contents of services or modules folder
 */
AXIS2_EXTERN axutil_array_list_t * AXIS2_CALL
axutil_dir_handler_list_service_or_module_dirs(const axutil_env_t *env,
        const axis2_char_t *pathname)
{
    axutil_array_list_t *file_list = NULL;
    struct stat *buf = NULL;
    int count = 1;
    int i = 0;
    struct dirent **files = NULL;
    char cwd[500];

    /**FIXME:
     * This magic number 500 was selected as a temperary solution. It has to be
     * replaced with dinamic memory allocation. This will be done once the use of
     * errno after getwcd() on Windows is figured out.
     */

    axis2_status_t status = AXIS2_FAILURE;
    AXIS2_ENV_CHECK(env, NULL);
    file_list = axutil_array_list_create(env, 0);
    if (!getcwd(cwd, 500)) exit(1);
    chdir(pathname);
    axis2_archive_extract();

    count = AXIS2_SCANDIR(pathname, &files, dir_select, AXIS2_ALPHASORT);
    chdir(cwd);

    /* If no files found, make a non-selectable menu item */
    if (count <= 0)
    {
        axutil_array_list_free(file_list, env);
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "No files in the path %s.", pathname);
        return NULL;
    }

    for (i = 1; i < (count + 1) ; ++i)
    {
        axis2_char_t *fname = NULL;
        axutil_file_t *arch_file = NULL;
        axis2_char_t *path = NULL;
        axis2_char_t *temp_path = NULL;

        fname = files[i-1]->d_name;
        arch_file = (axutil_file_t *) axutil_file_create(env);
        if (!arch_file)
        {
            int size = 0;
            int j = 0;
            axutil_file_t *del_file = NULL;

            size = axutil_array_list_size(file_list, env);
            for (j = 0; j < size; j++)
            {
                del_file = axutil_array_list_get(file_list, env, j);
                axutil_file_free(del_file, env);
            }
            axutil_array_list_free(file_list, env);
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            return NULL;
        }
         axutil_file_set_name(arch_file, env, fname);
        temp_path = axutil_stracat(env, pathname, AXIS2_PATH_SEP_STR);
        path = axutil_stracat(env, temp_path, fname);
        if (!path)
        {
            int size = 0;
            int j = 0;
            axutil_file_t *del_file = NULL;

            axutil_file_free(arch_file, env);
            size = axutil_array_list_size(file_list, env);
            for (j = 0; j < size; j++)
            {
                del_file = axutil_array_list_get(file_list, env, j);
                axutil_file_free(del_file, env);
            }
            axutil_array_list_free(file_list, env);
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            return NULL;
        }
         axutil_file_set_path(arch_file, env, path);
        AXIS2_FREE(env->allocator, temp_path);
        buf = AXIS2_MALLOC(env->allocator, sizeof(struct stat));
        if (!buf)
        {
            int size = 0;
            int j = 0;
            axutil_file_t *del_file = NULL;

            axutil_file_free(arch_file, env);
            AXIS2_FREE(env->allocator, path);
            size = axutil_array_list_size(file_list, env);
            for (j = 0; j < size; j++)
            {
                del_file = axutil_array_list_get(file_list, env, j);
                axutil_file_free(del_file, env);
            }
            axutil_array_list_free(file_list, env);
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            return NULL;
        }
        stat(path, buf);
         axutil_file_set_timestamp(arch_file, env, (time_t) buf->st_ctime);
        status = axutil_array_list_add(file_list, env, arch_file);
        if (AXIS2_SUCCESS != status)
        {
            int size = 0;
            int j = 0;
            axutil_file_t *del_file = NULL;

            axutil_file_free(arch_file, env);
            AXIS2_FREE(env->allocator, path);
            AXIS2_FREE(env->allocator, buf);
            size = axutil_array_list_size(file_list, env);
            for (j = 0; j < size; j++)
            {
                del_file = axutil_array_list_get(file_list, env, j);
                axutil_file_free(del_file, env);
            }
            axutil_array_list_free(file_list, env);
            return NULL;
        }
        AXIS2_FREE(env->allocator, path);
        AXIS2_FREE(env->allocator, buf);
    }
#ifndef WIN32
    for (i = 0; i < count; i++)
    {
        AXIS2_FREE(env->allocator, files[i]);
    }
    AXIS2_FREE(env->allocator, files);
#endif
    return file_list;
}


int file_select(struct dirent *entry)

{
    axis2_char_t *ptr;

    if ((strcmp(entry->d_name, ".") == 0) ||
            (strcmp(entry->d_name, "..") == 0))
        return (AXIS2_FALSE);

    /* Check for filename extensions */
    ptr = axutil_rindex(entry->d_name, '.');
    if ((ptr) &&
            ((strcmp(ptr, AXIS2_LIB_SUFFIX) == 0)))
    {
        return (AXIS2_TRUE);
    }
    else
        return(AXIS2_FALSE);
}

#ifdef IS_MACOSX
int dir_select(struct dirent *entry)
#else
int dir_select(const struct dirent *entry)
#endif
{
    struct stat stat_p;

    if (-1 ==  stat(entry->d_name, &stat_p))
        return (AXIS2_FALSE);

    if ((entry->d_name[0] == '.') || (!S_ISDIR(stat_p.st_mode)))
    {
        return (AXIS2_FALSE);
    }

    return AXIS2_TRUE;
}

