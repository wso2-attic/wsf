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
 
#ifndef REMOTE_REGISTRY_H
#define REMOTE_REGISTRY_H

/**
  * @file remote_registry.h
  * @brief 
  */

#include <axutil_utils_defines.h>
#include <axutil_env.h>
#include <axutil_error.h>
#include <axutil_string.h>
#include <axutil_array_list.h>
#include <remote_registry_resource.h>
#include <remote_registry_comment.h>
#include <remote_registry_conf.h>

#ifdef __cplusplus
extern "C"
{
#endif

/** @defgroup remote_registry
 * @ingroup remote_registry
 * @{
 */
typedef struct remote_registry remote_registry_t;
 
/**
 * @brief remote_registry
 *    remote_registry
 */

/**
 * creating the reg client with conf as an argument..
 */
AXIS2_EXTERN remote_registry_t* AXIS2_CALL
remote_registry_create(
    const axutil_env_t *env,
    axis2_char_t *url,
    axis2_char_t *username,
    axis2_char_t *password);
  

/**
 * creating the reg client with conf as an argument..
 */
AXIS2_EXTERN remote_registry_t* AXIS2_CALL
remote_registry_create_with_conf(
    const axutil_env_t *env,
    remote_registry_conf_t *conf);
  
/**
 * freeing the reg client
 */
AXIS2_EXTERN axis2_status_t AXIS2_CALL 
remote_registry_free(
    remote_registry_t *rest_client, 
    const axutil_env_t *env);

/**
 * loading perticular resource with its content,
 * initially only the meta content is avialbe. You
 * can check whether a resoure has content or not by
 * callilng remote_registry_is_resource_loaded on the resource
 * (Note that this is deprecated)
 */
AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_load_content_for_resource(
        remote_registry_t *remote_registry,
        const axutil_env_t *env,
        remote_registry_resource_t *resource);

/**
 * retriving the resource for a given atom url
 */
AXIS2_EXTERN remote_registry_resource_t *AXIS2_CALL
remote_registry_get(
                remote_registry_t *remote_registry,
                const axutil_env_t *env,
                axis2_char_t *url,
                axutil_array_list_t *params);

/**
 * loading a given resource and all its descendents 
 * (Note that this is deprecated)
 */
AXIS2_EXTERN remote_registry_resource_t *AXIS2_CALL
remote_registry_get_recursively(
                remote_registry_t *remote_registry,
                const axutil_env_t *env,
                axis2_char_t *url,
                axutil_array_list_t *params);


/**
 * get comments for a path
 */
AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL 
remote_registry_get_comments(
                remote_registry_t *remote_registry,
                const axutil_env_t *env,
                axis2_char_t *path);
/**
 * delete a resource declared in a path
 */
AXIS2_EXTERN axis2_status_t AXIS2_CALL 
remote_registry_delete(
                remote_registry_t *remote_registry,
                const axutil_env_t *env,
                axis2_char_t *path);

/** 
 * putting a resouce to a perticular path
 */
AXIS2_EXTERN axis2_status_t AXIS2_CALL 
remote_registry_put(
                remote_registry_t *remote_registry,
                const axutil_env_t *env,
                axis2_char_t *path,
                remote_registry_resource_t *resource);


/** 
 * putting a resouce to a perticular path
 * (Note that this is deprecated), instead use put for
 * evertying
 */
AXIS2_EXTERN axis2_status_t AXIS2_CALL 
remote_registry_post(
                remote_registry_t *remote_registry,
                const axutil_env_t *env,
                axis2_char_t *path,
                remote_registry_resource_t *resource);

/**
 * adding a comment
 */
AXIS2_EXTERN axis2_status_t AXIS2_CALL 
remote_registry_add_comment(
                remote_registry_t *remote_registry,
                const axutil_env_t *env,
                axis2_char_t *path,
                remote_registry_comment_t *comment);

/**
 * get the comments for a resource declared in the path
 */
AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL 
remote_registry_get_comments(
                remote_registry_t *remote_registry,
                const axutil_env_t *env,
                axis2_char_t *path);

/**
 * rating a resouce
 */
AXIS2_EXTERN axis2_status_t AXIS2_CALL 
remote_registry_rate_resource(
                remote_registry_t *remote_registry,
                const axutil_env_t *env,
                axis2_char_t *path,
                int rate);

/**
 * get average rating
 */
AXIS2_EXTERN int AXIS2_CALL 
remote_registry_get_average_rating(
                remote_registry_t *remote_registry,
                const axutil_env_t *env,
                axis2_char_t *path);

/**
 * get user rating for a given resource for a given username
 */
AXIS2_EXTERN int AXIS2_CALL 
remote_registry_get_user_rating(
                remote_registry_t *remote_registry,
                const axutil_env_t *env,
                axis2_char_t *path,
				axis2_char_t *username);

/**
 * apply a tag
 */
AXIS2_EXTERN axis2_status_t AXIS2_CALL 
remote_registry_apply_tag(
                remote_registry_t *remote_registry,
                const axutil_env_t *env,
                axis2_char_t *path,
                axis2_char_t *tag);

/**
 * get all tags for a resource
 */
AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL 
remote_registry_get_tags(
                remote_registry_t *remote_registry,
                const axutil_env_t *env,
                axis2_char_t *path);

/** @} */
#ifdef __cplusplus
}
#endif

#endif  /* REMOTE_REGISTRY_H */

