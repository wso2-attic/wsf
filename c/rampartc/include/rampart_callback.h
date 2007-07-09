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

#ifndef RAMPART_CALLBACK_H
#define RAMPART_CALLBACK_H

/**
  * @file rampart_callack.h
  * @brief The callback module for a password 
  */


#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * Struct to get password using callbacks
     * @defgroup rampart_callback rampart callback
     * @ingroup rampart_util
     * @{
     */

    /**
     * Type name for struct rampart_callback_ops 
     */
    typedef struct rampart_callback_ops rampart_callback_ops_t;

    /**
     * Type name for struct rampart_callback
     */

    typedef struct rampart_callback rampart_callback_t;

    /**
     * Only operation get_password is to get the password
     * User should provide a function pointer to this
     */
    struct rampart_callback_ops
    {
        /**
         * Retuens a password for the given username. 
         * By providing a function to this function pointer 
         * user can write custom password callback module
         * @param callback rampart callback pointer
         * @param env environment must not be null
         * @param username The username of the password expected.
         * @param param any parameter that is to be passed to the callback function.
         * @return returns password if any. Otherwise NULL returns  
         */
        axis2_char_t *(AXIS2_CALL*
                       callback_password)(rampart_callback_t *callback,
                                          const axutil_env_t *env,
                                          const axis2_char_t *username,
                                          void *param);

        /**
         * Free function of the rampart callback
         * @param callback rampart callback pointer
         * @param env environment must not be null
         * @return AXIS2_SUCCESS on success AXIS2_FAILURE otherwise
         */
        axis2_status_t (AXIS2_CALL*
                        free)(rampart_callback_t *rcb,
                              const axutil_env_t* env);

    };

    struct rampart_callback
    {
        rampart_callback_ops_t *ops;
    };

    /*************************** Function macros **********************************/
#define RAMPART_CALLBACK_FREE(callback, env) \
      ((callback)->ops->free (callback, env))

#define RAMPART_CALLBACK_CALLBACK_PASSWORD(callback, env, username, param) \
      ((callback)->ops->callback_password(callback, env, username, param))

    /** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* RAMPART_CALLBACK_H */

