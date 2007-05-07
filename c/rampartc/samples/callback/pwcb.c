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
#include <axis2_defines.h>
#include <axutil_error.h>
#include <axutil_env.h>
#include <axutil_utils.h>
#include <rampart_callback.h>
#include <axutil_string.h>
#include <axis2_svc_skeleton.h>
#include <axutil_string.h>


axis2_char_t* AXIS2_CALL
get_sample_password(rampart_callback_t *rcb,
        const axutil_env_t *env, 
        const axis2_char_t *username,
        void *param)
{
    /*First set pf password are for sample usernames*/
    axis2_char_t * pw = NULL;
    if (0 == axutil_strcmp(username, "Raigama"))
    {
        pw = "RaigamaPW" ;
    }
    else if (0 == axutil_strcmp(username, "Gampola"))
    {
        pw = "GampolaPW";
    }
    else if (0 == axutil_strcmp(username, "alice"))
    {
        pw = "password";
    }
    else if (0 == axutil_strcmp(username, "bob"))
    {
        pw = "bobPW";
    }
    /*These are for sample keystores*/
    else if (0 == axutil_strcmp(username, "a"))
    {
        pw = "a12345";
    }
    else if (0 == axutil_strcmp(username, "b"))
    {
        pw = "b12345";
    }
    else if (0 == axutil_strcmp(username, "x"))
    {
        pw = "x12345";
    }
    else if (0 == axutil_strcmp(username, "y"))
    {
        pw = "y12345";
    }
    else
    {
        /*Append 12345 for any name not specified above*/
        /*sprintf(pw, "%s%s",  username, "12345");*/
    }
    return pw;
};

/**
 * Following block distinguish the exposed part of the dll.
 */
AXIS2_EXPORT int
axis2_get_instance(rampart_callback_t **inst,
        const axutil_env_t *env)
{
    rampart_callback_t* rcb = NULL;

    rcb = AXIS2_MALLOC(env->allocator,
            sizeof(rampart_callback_t));

    rcb->ops = AXIS2_MALLOC(
                env->allocator, sizeof(rampart_callback_ops_t));

    /*assign function pointers*/

    rcb->ops->callback_password = get_sample_password;

    *inst = rcb;

    if (!(*inst))
    {
        return AXIS2_FAILURE;
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXPORT int
axis2_remove_instance(rampart_callback_t *inst,
        const axutil_env_t *env)
{
    axis2_status_t status = AXIS2_FAILURE;
    if (inst)
    {
        status = AXIS2_SVC_SKELETON_FREE(inst, env);
    }
    return status;
}

