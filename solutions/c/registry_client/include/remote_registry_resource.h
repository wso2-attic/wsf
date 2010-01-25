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
 
#ifndef REMOTE_REGISTRY_RESOURCE_H
#define REMOTE_REGISTRY_RESOURCE_H

/**
  * @file remote_registry_resource.h
  * @brief 
  */

#include <axutil_utils_defines.h>
#include <axutil_env.h>
#include <axutil_error.h>
#include <axutil_string.h>
#include <axutil_array_list.h>
#include <axutil_property.h>
#include <axutil_hash.h>
#include <axutil_date_time.h>
#include <axiom_node.h>
#include <remote_registry_rest_client.h>

#ifdef __cplusplus
extern "C"
{
#endif

/** @defgroup remote_registry_resource
 * @ingroup remote_registry
 * @{
 */
typedef struct remote_registry_resource remote_registry_resource_t;
 
/**
 * @brief remote_registry_resource
 *    remote_registry_resource
 */
AXIS2_EXTERN remote_registry_resource_t* AXIS2_CALL
remote_registry_resource_create(
    const axutil_env_t *env);

AXIS2_EXTERN remote_registry_resource_t* AXIS2_CALL
remote_registry_resource_create_collection(
    const axutil_env_t *env);


AXIS2_EXTERN remote_registry_resource_t *AXIS2_CALL
remote_registry_resource_create_from_feed(
    const axutil_env_t *env,
    axis2_char_t *buffer,
	axis2_char_t *content_type);


AXIS2_EXTERN remote_registry_resource_t *AXIS2_CALL
remote_registry_resource_create_from_entry_node(
    const axutil_env_t *env,
    axiom_node_t *entry_node);

AXIS2_EXTERN void AXIS2_CALL
remote_registry_resource_load_metadata_from_feed_node(
    const axutil_env_t *env,
    remote_registry_resource_t *resource,
    axiom_node_t *feed_node);
                        
AXIS2_EXTERN axis2_status_t AXIS2_CALL 
remote_registry_resource_free(
    remote_registry_resource_t *resource, 
    const axutil_env_t *env);


AXIS2_EXTERN axis2_char_t *AXIS2_CALL
remote_registry_resource_get_id(
    remote_registry_resource_t *resource,
    const axutil_env_t *env);

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
remote_registry_resource_get_author_name(
    remote_registry_resource_t *resource,
    const axutil_env_t *env);

AXIS2_EXTERN axutil_date_time_t* AXIS2_CALL
remote_registry_resource_get_created_time(
    remote_registry_resource_t *resource,
    const axutil_env_t *env);

AXIS2_EXTERN axutil_date_time_t* AXIS2_CALL
remote_registry_resource_get_last_modified_time(
    remote_registry_resource_t *resource,
    const axutil_env_t *env);

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
remote_registry_resource_get_last_updated_username(
    remote_registry_resource_t *resource,
    const axutil_env_t *env);

AXIS2_EXTERN int  AXIS2_CALL
remote_registry_resource_get_updated(
    remote_registry_resource_t *resource,
    const axutil_env_t *env);

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
remote_registry_resource_get_description(
    remote_registry_resource_t *resource,
    const axutil_env_t *env);

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
remote_registry_resource_get_path(
    remote_registry_resource_t *resource,
    const axutil_env_t *env);

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
remote_registry_resource_get_media_type(
    remote_registry_resource_t *resource,
    const axutil_env_t *env);

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
remote_registry_resource_get_parent_path(
    remote_registry_resource_t *resource,
    const axutil_env_t *env);

AXIS2_EXTERN int AXIS2_CALL
remote_registry_resource_get_content_modified(
    remote_registry_resource_t *resource,
    const axutil_env_t *env);

AXIS2_EXTERN int AXIS2_CALL
remote_registry_resource_get_state(
    remote_registry_resource_t *resource,
    const axutil_env_t *env);

AXIS2_EXTERN axutil_hash_t* AXIS2_CALL
remote_registry_resource_get_properties(
    remote_registry_resource_t *resource,
    const axutil_env_t *env);

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
remote_registry_resource_get_property(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    const axis2_char_t *key);

AXIS2_EXTERN void AXIS2_CALL
remote_registry_resource_remove_property(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    const axis2_char_t *key);

AXIS2_EXTERN axutil_array_list_t* AXIS2_CALL
remote_registry_resource_get_depends_on(
    remote_registry_resource_t *resource,
    const axutil_env_t *env);

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
remote_registry_resource_get_depended_on_by(
    remote_registry_resource_t *resource,
    const axutil_env_t *env);

AXIS2_EXTERN char* AXIS2_CALL
remote_registry_resource_get_content(
    remote_registry_resource_t *resource,
    const axutil_env_t *env);

AXIS2_EXTERN int AXIS2_CALL
remote_registry_resource_get_content_len(
    remote_registry_resource_t *resource,
    const axutil_env_t *env);

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
remote_registry_resource_get_content_src_url(
    remote_registry_resource_t *resource,
    const axutil_env_t *env);

AXIS2_EXTERN int AXIS2_CALL
remote_registry_resource_get_is_collection(
    remote_registry_resource_t *resource,
    const axutil_env_t *env);

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
remote_registry_resource_get_subtitle(
    remote_registry_resource_t *resource,
    const axutil_env_t *env);

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
remote_registry_resource_get_title(
    remote_registry_resource_t *resource,
    const axutil_env_t *env);

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
remote_registry_resource_get_collection(
    remote_registry_resource_t *resource,
    const axutil_env_t *env);

AXIS2_EXTERN axutil_array_list_t* AXIS2_CALL
remote_registry_resource_get_entries(
    remote_registry_resource_t *resource,
    const axutil_env_t *env);

AXIS2_EXTERN axutil_array_list_t* AXIS2_CALL
remote_registry_resource_get_children(
    remote_registry_resource_t *resource,
    const axutil_env_t *env);

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
remote_registry_resource_get_link_alternate(
    remote_registry_resource_t *resource,
    const axutil_env_t *env);

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
remote_registry_resource_get_link_path(
    remote_registry_resource_t *resource,
    const axutil_env_t *env);

AXIS2_EXTERN int AXIS2_CALL
remote_registry_resource_get_is_content_loaded(
    remote_registry_resource_t *resource,
    const axutil_env_t *env);

/* setter functions */
AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_id(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    axis2_char_t *id);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_author_name(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    const axis2_char_t *author_name);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_created_time(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    axutil_date_time_t *created_time);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_last_modified_time(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    axutil_date_time_t *last_modified_time);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_last_updated_username(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    const axis2_char_t *last_updated_username);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_updated(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    int  updated);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_description(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    const axis2_char_t *description);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_path(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    const axis2_char_t *path);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_media_type(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    const axis2_char_t *media_type);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_parent_path(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    const axis2_char_t *parent_path);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_content_modified(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    int content_modified);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_state(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    int state);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_properties(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    axutil_hash_t *properties);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_depends_on(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    axutil_array_list_t *depends_on);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_depended_on_by(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    const axis2_char_t *depended_on_by);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_content(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    char *content);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_content_len(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    int content_len);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_content_src_url(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    axis2_char_t *content_src_url);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_is_collection(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    int is_collection);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_subtitle(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    const axis2_char_t *subtitle);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_title(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    const axis2_char_t *title);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_collection(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    const axis2_char_t *collection);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_entries(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    axutil_array_list_t *entries);

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
remote_registry_resource_set_username(
    remote_registry_resource_t *resource,
	const axutil_env_t *env,
    const axis2_char_t *username);

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
remote_registry_resource_set_password(
    remote_registry_resource_t *resource,
	const axutil_env_t *env,
    const axis2_char_t *password);

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
remote_registry_resource_set_reg_url(
    remote_registry_resource_t *resource,
	const axutil_env_t *env,
    const axis2_char_t *reg_url);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_link_alternate(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    axis2_char_t *link_alternate);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_link_path(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    axis2_char_t *link_path);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_is_content_loaded(
    remote_registry_resource_t *resource,
    const axutil_env_t *env,
    int is_content_loaded);

AXIS2_EXTERN axiom_node_t *AXIS2_CALL
remote_registry_resource_serialize(
    remote_registry_resource_t *resource,
    const axutil_env_t *env);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_resource_set_rest_client(
	remote_registry_resource_t *resource, 
	const axutil_env_t *env,
	remote_registry_rest_client_t *rest_client);

/** @} */
#ifdef __cplusplus
}
#endif

#endif  /* REMOTE_REGISTRY_RESOURCE_H */

