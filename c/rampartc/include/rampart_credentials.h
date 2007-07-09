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

#ifndef RAMPART_CREDENTIALS_H
#define RAMPART_CREDENTIALS_H

#include <axis2_defines.h>
#include <axutil_error.h>
#include <axutil_env.h>
#include <axutil_utils.h>
#include <axis2_msg_ctx.h>

/**
  * @file rampart_credentials.h
  * @brief The credentials interface for rampart. To retrieve a username and password pair.
  */

#ifdef __cplusplus
extern "C"
{
#endif
    enum rampart_credentials_status{
        RAMPART_CREDENTIALS_PW_FOUND = 0,
        RAMPART_CREDENTIALS_PW_NOT_FOUND,
        RAMPART_CREDENTIALS_USER_FOUND,
        RAMPART_CREDENTIALS_USER_NOT_FOUND,
        RAMPART_CREDENTIALS_GENERAL_ERROR
    };

    typedef enum rampart_credentials_status rampart_credentials_status_t;

    /**
     * Struct to get username/password pair
     * @defgroup rampart_credentials rampart credentials
     * @ingroup rampart_util
     * @{
     */

    /**
     * Type name for struct rampart_credentials_ops 
     */
    typedef struct rampart_credentials_ops rampart_credentials_ops_t;

    /**
     * Type name for struct rampart_credentials
     */

    typedef struct rampart_credentials rampart_credentials_t;

    /**
     */
    struct rampart_credentials_ops
    {

        /**
         * Implementation must provide both username and the password.
         *
         */
        rampart_credentials_status_t (AXIS2_CALL*
                                      rampart_credentials_username_get)(
                                          rampart_credentials_t *credentials,
                                          const axutil_env_t* env,
                                          axis2_msg_ctx_t *msg_ctx,
                                          axis2_char_t **username,
                                          axis2_char_t **password
                                      );

        axis2_status_t (AXIS2_CALL*
                        free)(rampart_credentials_t *credentials,
                              const axutil_env_t* env);

    };

    struct rampart_credentials
    {
        rampart_credentials_ops_t *ops;
    };

    /*************************** Function macros **********************************/
#define RAMPART_CREDENTIALS_FREE(credentials, env) \
      ((credentials)->ops->free (credentials, env))

#define RAMPART_CREDENTIALS_USERNAME_GET(credentials, env, msg_ctx, username, password) \
      ((credentials)->ops->rampart_credentials_username_get(credentials, env, msg_ctx, username, password))



    /** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* RAMPART_CREDENTIALS_H */

