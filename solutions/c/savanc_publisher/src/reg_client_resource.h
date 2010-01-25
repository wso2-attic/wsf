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
 
#ifndef REG_CLIENT_RESOURCE_H
#define REG_CLIENT_RESOURCE_H

/**
  * @file reg_client_resource.h
  * @brief 
  */

#include <axutil_utils_defines.h>
#include <axutil_utils.h>
#include <axutil_env.h>
#include <axutil_error.h>
#include <axutil_array_list.h>

#ifdef __cplusplus
extern "C"
{
#endif

/** @defgroup reg_client_resource
 * @ingroup reg_client
 * @{
 */
 
typedef struct reg_client_resource
{
    axis2_char_t *id;
    axis2_char_t *author_username;
    axis2_char_t *created_time;
    axis2_char_t *last_updated_username;
    axis2_char_t *updated; /* timestamp */
    axis2_char_t *description;
    axis2_char_t *path;
    axis2_char_t *media_type;
    axis2_char_t *parent_path;

    /**
     * Used to detect whether the resource content is modified after it is retrieved from the
     * Registry. If this is set to true at the time of adding the resource back to the Registry, new
     * version will be created.
     */
    axis2_bool_t content_modified; /* boolean */

    /**
     * Normal resources have the state REG_CLIENT_ACTIVE_STATE (100) Deleted resources have the state 
     * REG_CLIENT_DELETED_STATE (101)
     */
    int state;

    /* hash map of properties */
    axutil_array_list_t *properties;

    axutil_array_list_t *depends_on; /* String[] */
    axis2_char_t *depended_on_by;

    /* To store any kind of object */
    void *content;

    axis2_bool_t is_directory; /* Bool */
    
    axis2_char_t *subtitle;
    
    axis2_char_t *title;
    
    axis2_char_t *directory;
    
    axutil_array_list_t *entries;
} reg_client_resource_t;

/**
 * @brief reg_client_resource
 *    reg_client_resource
 */
AXIS2_EXTERN reg_client_resource_t* AXIS2_CALL
reg_client_resource_create(
    const axutil_env_t *env);  
                        
axis2_status_t AXIS2_CALL 
reg_client_resource_free(
    reg_client_resource_t *resource, 
    const axutil_env_t *env);

/** @} */
#ifdef __cplusplus
}
#endif

#endif  /* REG_CLIENT_RESOURCE_H */

