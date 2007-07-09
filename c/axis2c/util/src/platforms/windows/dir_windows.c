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


#include <malloc.h>
#include <string.h>
#include <errno.h>

#include <platforms/windows/axutil_dir_windows.h>

/*dirent.h style mehtods for win32*/

DIR * AXIS2_CALL opendir(const char *_dirname)
{
    DIR      *dirp;
    char   *filespec;
    long   handle;
    int      index;

    filespec = malloc(strlen(_dirname) + 2 + 1);
    strcpy(filespec, _dirname);
    index = (int)strlen(filespec) - 1;
    if (index >= 0 && (filespec[index] == '/' ||
            (filespec[index] == '\\' && !IsDBCSLeadByte(filespec[index-1]))))
        filespec[index] = '\0';
    strcat(filespec, "/*");

    dirp = (DIR *) malloc(sizeof(DIR));
    dirp->offset = 0;
    dirp->finished = 0;

    if ((handle = _findfirst(filespec, &(dirp->fileinfo))) < 0)
    {
        if (errno == ENOENT || errno == EINVAL)
            dirp->finished = 1;
        else
        {
            free(dirp);
            free(filespec);
            return NULL;
        }
    }
    dirp->dirname = strdup(_dirname);
    dirp->handle = handle;
    free(filespec);

    return dirp;
}

int AXIS2_CALL closedir(DIR *_dirp)
{
    int iret = -1;
    if (!_dirp)
        return iret;
    iret = _findclose(_dirp->handle);
    if (iret == 0 && _dirp->dirname)
        free(_dirp->dirname);
    if (iret == 0 && _dirp)
        free(_dirp);

    return iret;
}

struct dirent * AXIS2_CALL readdir(DIR *_dirp)
{
    if (!_dirp || _dirp->finished)
        return NULL;

    if (_dirp->offset != 0)
    {
        if (_findnext(_dirp->handle, &(_dirp->fileinfo)) < 0)
        {
            _dirp->finished = 1;
            return NULL;
        }
    }
    _dirp->offset++;

    strcpy(_dirp->dent.d_name, _dirp->fileinfo.name);/*, _MAX_FNAME+1);*/
    _dirp->dent.d_ino = 1;
    _dirp->dent.d_reclen = (unsigned short)strlen(_dirp->dent.d_name);
    _dirp->dent.d_off = _dirp->offset;

    return &(_dirp->dent);
}

int AXIS2_CALL readdir_r(DIR *_dirp, struct dirent *_entry, struct dirent **__result)
{
    if (!_dirp || _dirp->finished)
    {
        *__result = NULL;
        return -1;
    }

    if (_dirp->offset != 0)
    {
        if (_findnext(_dirp->handle, &(_dirp->fileinfo)) < 0)
        {
            _dirp->finished = 1;
            *__result = NULL;
            return -1;
        }
    }
    _dirp->offset++;

    strcpy(_dirp->dent.d_name, _dirp->fileinfo.name);/*, _MAX_FNAME+1);*/
    _dirp->dent.d_ino = 1;
    _dirp->dent.d_reclen = (unsigned short)strlen(_dirp->dent.d_name);
    _dirp->dent.d_off = _dirp->offset;

    memcpy(_entry, &_dirp->dent, sizeof(*_entry));

    *__result = &_dirp->dent;

    return 0;
}


int AXIS2_CALL rewinddir(DIR *dirp)
{
    char   *filespec;
    long   handle;
    int      index;

    _findclose(dirp->handle);

    dirp->offset = 0;
    dirp->finished = 0;

    filespec = malloc(strlen(dirp->dirname) + 2 + 1);
    strcpy(filespec, dirp->dirname);
    index = (int)(strlen(filespec) - 1);
    if (index >= 0 && (filespec[index] == '/' || filespec[index] == '\\'))
        filespec[index] = '\0';
    strcat(filespec, "/*");

    if ((handle = _findfirst(filespec, &(dirp->fileinfo))) < 0)
    {
        if (errno == ENOENT || errno == EINVAL)
            dirp->finished = 1;
    }
    dirp->handle = handle;
    free(filespec);

    return 0;
}

int alphasort(const struct dirent **__d1, const struct dirent **__d2)
{
    return strcoll((*__d1)->d_name, (*__d2)->d_name);
}


int AXIS2_CALL scandir(const char *_dirname, struct dirent **__namelist[], int(*selector)(const struct dirent *entry), int(*compare)(const struct dirent **__d1, const struct dirent **__d2))
{
    DIR            *dirp = NULL;
    struct dirent   **vector = NULL;
    struct dirent   *dp = NULL;
    int            vector_size = 0;
    int            nfiles = 0;

    if (__namelist == NULL)
    {
        return -1;
    }

    if (!(dirp = opendir(_dirname)))
    {
        return -1;
    }

    while ((dp = readdir(dirp)))
    {
        int dsize = 0;
        struct dirent *newdp = NULL;

        if (selector && (*selector)(dp) == 0)
        {
            continue;
        }

        if (nfiles == vector_size)
        {
            struct dirent **newv;
            if (vector_size == 0)
            {
                vector_size = 10;
            }
            else
            {
                vector_size *= 2;
            }

            newv = (struct dirent **) realloc(vector, vector_size * sizeof(struct dirent *));
            if (!newv)
            {
                return -1;
            }
            vector = newv;
        }

        dsize = (int)sizeof(struct dirent) + (int)((strlen(dp->d_name) + 1) * sizeof(char));
        newdp = (struct dirent *) malloc(dsize);

        if (newdp == NULL)
        {
            while (nfiles-- > 0)
            {
                free(vector[nfiles]);
            }
            free(vector);
            return -1;
        }

        vector[nfiles++] = (struct dirent *) memcpy(newdp, dp, dsize);
    }

    closedir(dirp);

    *__namelist = vector;

    if (compare)
    {
        qsort(*__namelist, nfiles, sizeof(struct dirent *), compare);
    }

    return nfiles;
}
