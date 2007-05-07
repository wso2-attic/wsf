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
#include <rampart_authn_provider.h>
#include <rampart_crypto_util.h> 
#include <axutil_string.h>
#include <axis2_svc_skeleton.h>
#include <axutil_string.h>

axis2_char_t* AXIS2_CALL
ramaprt_get_sample_password_from_file(const axutil_env_t *env,
        const axis2_char_t *username)
{
    axis2_char_t * password = NULL;
    FILE *file = NULL;
    axis2_char_t *filename = "samples/rampart/data/passwords.txt";

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
             pw = (axis2_char_t *) axutil_strdup(env, &(res[1]));
             password = axutil_strndup(env, pw, axutil_strlen(pw)-1); /*We need to remove the end of line character*/

             break;
          }
       }
       AXIS2_FREE(env->allocator, un);
       AXIS2_FREE(env->allocator, pw);
       fclose ( file );
    }else{
       AXIS2_LOG_INFO(env->log, "Cannot load the password file %s ", filename);
       perror ( filename );
    }
    return password; 
}
#if 0
axis2_char_t* AXIS2_CALL
ramaprt_get_sample_password(const axutil_env_t *env,
        const axis2_char_t *username)
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
#endif

/*Two sample implementations*/
rampart_authn_provider_status_t AXIS2_CALL
rampart_sample_authn_provider_check_password(rampart_authn_provider_t *authn_provider,
                const axutil_env_t* env,
                axis2_msg_ctx_t *msg_ctx,
                const axis2_char_t *username,
                const axis2_char_t *password)
{
    axis2_char_t *local_pw = NULL;

    /*local_pw = ramaprt_get_sample_password( env, username);*/
    local_pw = ramaprt_get_sample_password_from_file(env, username);
    if(local_pw){
        /*Compare passwords*/
        if(0 == axutil_strcmp(password, local_pw)){
            return RAMPART_AUTHN_PROVIDER_GRANTED;
        }else{
            return RAMPART_AUTHN_PROVIDER_DENIED;
        }
    }else{
        return RAMPART_AUTHN_PROVIDER_USER_NOT_FOUND;
    }
}

rampart_authn_provider_status_t AXIS2_CALL
rampart_sample_authn_provider_check_password_digest(rampart_authn_provider_t *authn_provider,
                const axutil_env_t* env,
                axis2_msg_ctx_t *msg_ctx,
                const axis2_char_t *username,
                const axis2_char_t *nonce,
                const axis2_char_t *created,
                const axis2_char_t *digest)
{

    axis2_char_t *local_pw = NULL;

    /*local_pw = ramaprt_get_sample_password( env, username);*/
    local_pw = ramaprt_get_sample_password_from_file(env, username);
    if(local_pw){
        axis2_char_t *local_digest = NULL;
        /*Generate the digest*/
        local_digest = rampart_crypto_sha1(env, nonce, created, local_pw);
        /*Compare digest*/
        if(0 == axutil_strcmp(digest, local_digest)){
            return RAMPART_AUTHN_PROVIDER_GRANTED;
        }else{
            return RAMPART_AUTHN_PROVIDER_DENIED;
        }
     
    }else{
        return RAMPART_AUTHN_PROVIDER_USER_NOT_FOUND;
    }
}

/**
 * Following block distinguishes the exposed part of the dll.
 */
AXIS2_EXPORT int
axis2_get_instance(rampart_authn_provider_t **inst,
        const axutil_env_t *env)
{
    rampart_authn_provider_t* authn_p = NULL;

    authn_p = AXIS2_MALLOC(env->allocator,
            sizeof(rampart_authn_provider_t));

    authn_p->ops = AXIS2_MALLOC(
                env->allocator, sizeof(rampart_authn_provider_ops_t));

    /*assign function pointers*/

    authn_p->ops->rampart_authn_provider_check_password = rampart_sample_authn_provider_check_password;
    authn_p->ops->rampart_authn_provider_check_password_digest = rampart_sample_authn_provider_check_password_digest;
   
    *inst = authn_p;

    if (!(*inst))
    {
        return AXIS2_FAILURE;
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXPORT int
axis2_remove_instance(rampart_authn_provider_t *inst,
        const axutil_env_t *env)
{
    axis2_status_t status = AXIS2_FAILURE;
    if (inst)
    {
        status = AXIS2_SVC_SKELETON_FREE(inst, env);
    }
    return status;
}

