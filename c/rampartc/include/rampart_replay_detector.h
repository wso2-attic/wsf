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

#ifndef RAMPART_REPLAY_DETECTOR_H
#define RAMPART_REPLAY_DETECTOR_H

/**
  * @file rampart_replay_detector.h
  * @brief The replay_detector module for rampart 
  */
#include <axis2_defines.h>
#include <axutil_env.h>
#include <axis2_msg_ctx.h>
#include <axis2_conf_ctx.h>
#include <rampart_context.h>
#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * Struct to for replay_detectors
     * @defgroup rampart_replay_detector rampart replay_detector
     * @ingroup rampart_util
     * @{
     */

    /**
     * Type name for struct rampart_replay_detector_ops 
     */
    typedef struct rampart_replay_detector_ops rampart_replay_detector_ops_t;

    /**
     * Type name for struct rampart_replay_detector
     */

    typedef struct rampart_replay_detector rampart_replay_detector_t;

    /**
     * Only operation get_password is to get the password
     * User should provide a function pointer to this
     */
    struct rampart_replay_detector_ops
    {
        axis2_status_t (AXIS2_CALL*
                       load)(rampart_replay_detector_t *replay_detector,
                                          const axutil_env_t *env);

        axis2_status_t (AXIS2_CALL*
                        is_replayed)(rampart_replay_detector_t *rrd,
                              const axutil_env_t* env,
                              axis2_msg_ctx_t *msg_ctx);

        axis2_status_t (AXIS2_CALL*
                        free)(rampart_replay_detector_t *rrd,
                              const axutil_env_t* env);

    };

    struct rampart_replay_detector
    {
        rampart_replay_detector_ops_t *ops;
    };

    /*The default impl for RRD*/
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_replay_detector_default(const axutil_env_t *env,
                                axis2_msg_ctx_t *msg_ctx,
                                rampart_context_t *rampart_context);

    AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
    rampart_replay_detector_set_default_db(const axutil_env_t *env,
            axis2_ctx_t *ctx);

    /*A linked list based implementation for RRD
      This doesnt required addressing headers to be present*/
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_replay_detector_with_linked_list(const axutil_env_t *env,
                                    axis2_msg_ctx_t* msg_ctx,
                                    rampart_context_t *rampart_context);

    AXIS2_EXTERN axutil_linked_list_t *AXIS2_CALL
    rampart_replay_detector_set_ll_db(const axutil_env_t *env,
            axis2_ctx_t *ctx);
    
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_replay_detector_final_cleanup(const axutil_env_t *env,
                                    axis2_msg_ctx_t* msg_ctx);
    /*************************** Function macros **********************************/
#define RAMPART_REPLAY_DETECTOR_LOAD(replay_detector, env) \
      ((replay_detector)->ops->load(replay_detector, env))

#define RAMPART_REPLAY_DETECTOR_IS_REPLAYED(replay_detector, env, msg_ctx) \
      ((replay_detector)->ops->replay_detector_is_replayed(replay_detector, env, msg_ctx))

#define RAMPART_REPLAY_DETECTOR_FREE(replay_detector, env) \
        ((replay_detector)->ops->free(replay_detector, env))

    /** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* RAMPART_REPLAY_DETECTOR_H */

