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
#include <rampart_credentials.h>
#include <rampart_crypto_util.h> 
#include <axutil_string.h>
#include <axis2_svc_skeleton.h>
#include <axutil_string.h>


rampart_credentials_status_t AXIS2_CALL
rampart_sample_credentials_username_get(
                rampart_credentials_t *credentials,
                const axutil_env_t* env,
                axis2_msg_ctx_t *msg_ctx,
                axis2_char_t **username,
                axis2_char_t **password
            )
{
    *username = "Gampola";
    *password = "GampolaPW";

    return RAMPART_CREDENTIALS_PW_FOUND;
}

/**
 * Following block distinguishes the exposed part of the dll.
 */
AXIS2_EXPORT int
axis2_get_instance(rampart_credentials_t **inst,
        const axutil_env_t *env)
{
    rampart_credentials_t* cred_p = NULL;

    cred_p = AXIS2_MALLOC(env->allocator,
            sizeof(rampart_credentials_t));

    cred_p->ops = AXIS2_MALLOC(
                env->allocator, sizeof(rampart_credentials_t));

    /*assign function pointers*/

    cred_p->ops->rampart_credentials_username_get = rampart_sample_credentials_username_get;
   
    *inst = cred_p;

    if (!(*inst))
    {
        return AXIS2_FAILURE;
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXPORT int
axis2_remove_instance(rampart_credentials_t *inst,
        const axutil_env_t *env)
{
    axis2_status_t status = AXIS2_FAILURE;
    if (inst)
    {
        status = AXIS2_SVC_SKELETON_FREE(inst, env);
    }
    return status;
}

