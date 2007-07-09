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

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <platforms/windows/axutil_getopt_windows.h>

int      optind = 1;
int      opterr = 1;
int      optopt;
char*   optarg;

#define AXIS2_OPT_ERR_NO_ARG         1
#define AXIS2_OPT_ERR_INVALID_OPTION   2
#define AXIS2_OPT_ERR_BAD_ARG         3



int _axis2_opt_error(int __optopt, int __err, int __showerr)
{
    switch (__err)
    {
        case AXIS2_OPT_ERR_NO_ARG:
            if (__showerr)
                fprintf(stderr, " option requires an argument -- %c\n", __optopt);
            break;
        case AXIS2_OPT_ERR_INVALID_OPTION:
            if (__showerr)
                fprintf(stderr, " illegal option -- %c\n", __optopt);
            break;
        case AXIS2_OPT_ERR_BAD_ARG:
            return (int)':';
        default:
            if (__showerr)
                fprintf(stderr, "unknown\n");
    }
    return (int)'?';
}

AXIS2_EXTERN int AXIS2_CALL
axis2_getopt(int __argc, char * const *__argv, const char *__shortopts)
{
    static char *pos = "";
    char *olstindex;

    if (!*pos)
    {
        /* no option or invalid option*/
        if (optind >= __argc || *(pos = __argv[optind]) != '-')
        {
            pos = "";
            return -1;
        }
        /*-- option*/
        if (pos[1] && *++pos == '-')
        {
            ++optind;
            pos = "";
            return -1;
        }
    }

    if ((optopt = (int) * pos++) == (int)':' ||
            !(olstindex = strchr(__shortopts, optopt)))
    {

        if (optopt == (int)'-')
            return -1;
        if (!*pos)
            ++optind;
        if (*__shortopts != ':')
            return _axis2_opt_error(optopt, AXIS2_OPT_ERR_BAD_ARG, opterr);
        _axis2_opt_error(optopt, AXIS2_OPT_ERR_INVALID_OPTION, opterr);
    }

    if (*++olstindex != ':')
    {
        optarg = NULL;
        if (!*pos)
            ++optind;
    }
    else
    {
        if (*pos)
            optarg = pos;
        else if (__argc <= ++optind)
        {
            pos = "";
            if (*__shortopts == ':')
                return _axis2_opt_error(-1, AXIS2_OPT_ERR_BAD_ARG, opterr);
            return _axis2_opt_error(optopt, AXIS2_OPT_ERR_NO_ARG, opterr);
        }
        else
            optarg = __argv[optind];
        pos = "";
        ++optind;
    }
    return optopt;
}

