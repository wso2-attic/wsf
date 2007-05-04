/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef READDIR_H
#define READDIR_H
#include <search.h>
#include <string.h>
#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <windows.h>
#include <axutil_utils_defines.h>

/* struct dirent - same as Unix dirent.h */
 struct dirent 
{
   long            d_ino;                  /* inode number (always 1 in WIN32) */
   off_t            d_off;               /* offset to this dirent */
   unsigned short      d_reclen;      /* length of d_name */
   char            d_name[_MAX_FNAME + 1];   /* filename (null terminated) */
   /*unsigned char      d_type;*/      /*type of file*/
};


/* def struct DIR - different from Unix DIR */
 typedef struct
{
   long            handle;                  /* _findfirst/_findnext handle */
   short            offset;                  /* offset into directory */
   short            finished;                  /* 1 if there are not more files */
   struct _finddata_t   fileinfo;      /* from _findfirst/_findnext */
   char            *dirname;                  /* the dir we are reading */
   struct dirent      dent;               /* the dirent to return */
} DIR;

/* Function prototypes */

/**
  * open a directory on a given name
  * returns a DIR if successful, or NULL if the path cannot be opened
  */
AXIS2_EXTERN DIR* AXIS2_CALL opendir(const char *);

/**
  * Close the directory stream DIRP.
  * Return 0 if successful, -1 otherwise.
  */
AXIS2_EXTERN int AXIS2_CALL closedir(DIR *);

/**
  * Read a directory entry from DIRP.  Return a pointer to a `struct
  * dirent' describing the entry, or NULL for EOF or error.
  */
AXIS2_EXTERN struct dirent* AXIS2_CALL 
readdir(DIR *);

/**
  * Reentrant version of `readdir'
  */
AXIS2_EXTERN int AXIS2_CALL 
readdir_r(DIR *, struct dirent *, struct dirent **);

/**
  * Rewind DIRP to the beginning of the directory.
  */
AXIS2_EXTERN int AXIS2_CALL rewinddir(DIR *);

/**
  * Scan the directory DIR
  *  Returns the number of entries selected, or -1 on error
  */
AXIS2_EXTERN int AXIS2_CALL 
scandir(const char *_dirname, struct dirent **__namelist[], int (*selector) (const struct dirent *entry), int (*compare) (const struct dirent **a, const struct dirent **b));

/**
  * Compare two `struct dirent's alphabetically
  */
extern int
alphasort(const struct dirent **__d1, const struct dirent **__d2);

#endif /* READDIR_H */
