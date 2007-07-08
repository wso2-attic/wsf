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

#ifndef AXIS2_REPOS_LISTENER_H
#define AXIS2_REPOS_LISTENER_H

/** @defgroup axis2_repos_listener Repos Listener
 * @ingroup axis2_deployment
 * @{
 */

#include <axis2_const.h>
#include <axutil_error.h>
#include <axis2_defines.h>
#include <axutil_env.h>
#include <axutil_allocator.h>
#include <axutil_qname.h>
#include <axutil_array_list.h>
#include "axis2_ws_info_list.h"
#include "axis2_dep_engine.h"

#ifdef __cplusplus
extern "C"
{
#endif

    struct axis2_dep_engine;
    /** Type name for struct axis2_repos_listener */
    typedef struct axis2_repos_listener axis2_repos_listener_t;

    /** 
     * De-allocate memory
     * @param repos_listener pointer to repos listener
     * @param env pointer to environment struct
     * @return void
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_repos_listener_free(axis2_repos_listener_t *repos_listener,
        const axutil_env_t *env);

    /**
     * this method ask serachWS to serch for the folder to caheck
     * for updates
     * @param repos_listener pointer to repos listener
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_repos_listener_check_modules(axis2_repos_listener_t *listener,
        const axutil_env_t *env);

    /**
     * this method ask serachWS to serch for the folder to caheck
     * for updates
     * @param repos_listener pointer to repos listener
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_repos_listener_check_svcs(axis2_repos_listener_t *listener,
        const axutil_env_t *env);

    /**
     * call to update method of WSInfoList object
     * @param repos_listener pointer to repos listener
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_repos_listener_update(axis2_repos_listener_t *listener,
        const axutil_env_t *env);

    /**
     * First it call to initalize method of WSInfoList to initilizat that.
     * then it call to checkModules to load all the module.jar s
     * and then it call to update() method inorder to update the Deployment engine and
     * engine regsitry
     * @param repos_listener pointer to repos listener
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_repos_listener_init(axis2_repos_listener_t *listener,
        const axutil_env_t *env);

    /**
     * this is the actual method that is call from scheduler
     * @param repos_listener pointer to repos listener
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_repos_listener_start_listen(axis2_repos_listener_t *listener,
        const axutil_env_t *env);

    /**
     * @param env pointer to environment struct
     * @return pointer to newly created deployment engine
     */
    AXIS2_EXTERN axis2_repos_listener_t *AXIS2_CALL
    axis2_repos_listener_create(const axutil_env_t *env);

    /**
     * @param env pointer to environment struct
     * @param folder_name this is the axis2 deployment root directory(repository path)
     * @param dep_engine pointer to deployment engine
     * @return pointer to newly created deployment engine
     */
    AXIS2_EXTERN axis2_repos_listener_t *AXIS2_CALL
    axis2_repos_listener_create_with_folder_name_and_dep_engine(const axutil_env_t *env,
        axis2_char_t *folder_name,
        struct axis2_dep_engine *dep_engine);

/** @} */

#ifdef __cplusplus
}
#endif
#endif  /* AXIS2_REPOS_LISTENER_H */
