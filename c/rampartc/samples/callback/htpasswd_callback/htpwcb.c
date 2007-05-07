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
get_ht_password(rampart_callback_t *rcb,
        const axutil_env_t *env, 
        const axis2_char_t *username, 
        void *param)
{
    axis2_char_t * password = NULL;
    FILE *file = NULL;
    /*The default location is the following. But this will be overridden by the property values set in the msg_ctx*/
    axis2_char_t *filename = "/usr/local/apache2/passwd/passwords";

    if(param){
        filename = (axis2_char_t *)param;
    }else{
       AXIS2_LOG_INFO(env->log, "Using the default password file location %s", filename);
    }

    
    file = fopen ( filename, "r" );
    if ( file != NULL )
    {
       axis2_char_t line [ 128 ]; 
       axis2_char_t ch = 0;
       axis2_char_t *res = NULL;
       axis2_char_t *un = NULL;
       axis2_char_t *pw = NULL;

       while ( fgets ( line, sizeof line, file ) != NULL ) 
       {
          res = axutil_strstr(line, ":");
          ch = res[0];
          res[0] = '\0';
          un = (axis2_char_t *) axutil_strdup(env, line);
          res[0] = ch;
          if(0 == axutil_strcmp(un, username)){
             pw = (axis2_char_t *) axutil_strdup( env, &(res[1]));
             password = axutil_strndup(env, pw, axutil_strlen(pw)-1); /*We need to remove the end of line character*/

             break;
          }
       }
       AXIS2_FREE(env->allocator, un);
       AXIS2_FREE(env->allocator, pw);
       fclose ( file );
    }else
    {
       AXIS2_LOG_INFO(env->log, "Cannot load the password file %s in the callback module", filename);
       perror ( filename ); 
    }
    return password;
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

    rcb->ops->callback_password = get_ht_password;

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

