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
 
#ifndef REMOTE_REGISTRY_UTIL_H
#define REMOTE_REGISTRY_UTIL_H

/**
  * @file remote_registry_util.h
  * @brief 
  */

#include <axutil_utils_defines.h>
#include <axutil_env.h>
#include <axutil_error.h>
#include <axiom.h>

#ifdef __cplusplus
extern "C"
{
#endif

/** @defgroup remote_registry_util
 * @ingroup remote_registry
 * @{
 */
 
typedef struct remote_registry_url_param
{
    axis2_char_t *key;
    axis2_char_t *value;
} remote_registry_url_param_t;



AXIS2_EXTERN axiom_node_t *AXIS2_CALL
remote_registry_util_serialize_rating(
    const axutil_env_t *env,
    int rate);

AXIS2_EXTERN int AXIS2_CALL
remote_registry_util_get_ratings_from_feed(
    const axutil_env_t *env,
    axis2_char_t *feed);

AXIS2_EXTERN int AXIS2_CALL
remote_registry_util_get_user_ratings_from_feed(
    const axutil_env_t *env,
    axis2_char_t *feed);



AXIS2_EXTERN axiom_node_t *AXIS2_CALL
remote_registry_util_serialize_tag(
    const axutil_env_t *env, 
    axis2_char_t *tag);

AXIS2_EXTERN axutil_array_list_t* AXIS2_CALL
remote_registry_util_get_tags_from_feed(
    const axutil_env_t *env,
    axis2_char_t *feed);


/** @} */
#ifdef __cplusplus
}
#endif

#endif  /* REMOTE_REGISTRY_UTIL_H */

