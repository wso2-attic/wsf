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
 
#ifndef REMOTE_REGISTRY_COMMENT_H
#define REMOTE_REGISTRY_COMMENT_H

/**
  * @file remote_registry_comment.h
  * @brief 
  */

#include <axutil_utils_defines.h>
#include <axutil_env.h>
#include <axutil_error.h>
#include <axutil_string.h>
#include <axutil_array_list.h>
#include <axutil_date_time.h>
#include <axiom_node.h>

#ifdef __cplusplus
extern "C"
{
#endif

/** @defgroup remote_registry_comment
 * @ingroup remote_registry
 * @{
 */
typedef struct remote_registry_comment remote_registry_comment_t;
 
/**
 * @brief remote_registry_comment
 *    remote_registry_comment
 */
AXIS2_EXTERN remote_registry_comment_t* AXIS2_CALL
remote_registry_comment_create(
    const axutil_env_t *env);

AXIS2_EXTERN remote_registry_comment_t* AXIS2_CALL
remote_registry_comment_create_from_entry_node(
    const axutil_env_t *env,
    axiom_node_t *entry_node);

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
remote_registry_comment_free(
    remote_registry_comment_t *comment, 
    const axutil_env_t *env);


axutil_array_list_t* AXIS2_CALL
remote_registry_comment_load_from_feed(
    const axutil_env_t *env,
    axis2_char_t *buffer);


AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_comment_set_resource_path(
    remote_registry_comment_t *comment,
    const axutil_env_t *env,
    const axis2_char_t *resource_path);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_comment_set_comment_path(
    remote_registry_comment_t *comment,
    const axutil_env_t *env,
    const axis2_char_t *comment_path);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_comment_set_text(
    remote_registry_comment_t *comment,
    const axutil_env_t *env,
    const axis2_char_t *text);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_comment_set_user(
    remote_registry_comment_t *comment,
    const axutil_env_t *env,
    const axis2_char_t *user);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_comment_set_date_time(
    remote_registry_comment_t *comment,
    const axutil_env_t *env,
    axutil_date_time_t *date_time);


AXIS2_EXTERN axis2_char_t *AXIS2_CALL
remote_registry_comment_get_path(
    remote_registry_comment_t *comment,
    const axutil_env_t *env);

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
remote_registry_comment_get_comment_path(
    remote_registry_comment_t *comment,
    const axutil_env_t *env);

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
remote_registry_comment_get_text(
    remote_registry_comment_t *comment,
    const axutil_env_t *env);

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
remote_registry_comment_get_user(
    remote_registry_comment_t *comment,
    const axutil_env_t *env);

AXIS2_EXTERN axutil_date_time_t *AXIS2_CALL
remote_registry_comment_get_date_time(
    remote_registry_comment_t *comment,
    const axutil_env_t *env);


AXIS2_EXTERN axiom_node_t *AXIS2_CALL
remote_registry_comment_serialize(
    remote_registry_comment_t *comment,
    const axutil_env_t *env);

/** @} */
#ifdef __cplusplus
}
#endif

#endif  /* REMOTE_REGISTRY_COMMENT_H */

