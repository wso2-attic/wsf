/*
 * Copyright 2005,2009 WSO2, Inc. http://wso2.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef REPLAY_DETECTOR_H
#define REPLAY_DETECTOR_H

#include <WSFDefines.h>
#include <string>
#include <MessageContext.h>
#include <rampart_replay_detector.h>
#include <Environment.h>

/**
 * @file ReplayDetector.h
 * @brief ReplayDetector class which defines the interface for user specific replay detection logic is 
 * defined here.
 */

/**
 * @brief namespace wso2wsf Namespace of WSO2 Web Services Framework.
 */
namespace wso2wsf
{
    /**
     * @defgroup ReplayDetector ReplayDetector
     * @ingroup wso2wsf
     * @{
     */

    /**
     * @brief class ReplayDetector Represents an interface needed implement any user specific
     * replay detection logic.
     */
    class WSF_EXTERN ReplayDetector
    {
    public:
        /**
         * Handler to be invoked to check whether the message is a replay
         * Should return true if the message is valid. False if the message is a replay
         */
        virtual bool WSF_CALL isValid(MessageContext* msgctx) = 0;

        /**
         * destructor that can be overridden.
         */
        virtual WSF_CALL ~ReplayDetector();

        /**
         * Static Handler to be invoked to check whether it is a replay
         */
        static axis2_status_t WSF_CALL checkValidity(
            rampart_replay_detector_t *rrd,
            const axutil_env_t* env,
            axis2_msg_ctx_t *msg_ctx,
            rampart_context_t *rampart_context);
    };
    /** @} */
}
/**
 * stuct used to keep the information data for replay detection callback.
 */
typedef struct wsf_replay_detector
{
    rampart_replay_detector_ops_t *ops;
	axutil_param_t *param;
    wso2wsf::ReplayDetector* callback;
}wsf_replay_detector_t;
/**
 * Macro used to load the shared lib to the engine. The implementer should include this macro within the code,
 * and provide the class extending from the ReplayDetector class as the argument for this macro for proper
 * deployment and functioning of the replay detection callback.
 */

#define WSF_REPLAY_DETECTOR_INIT(class_name) \
extern "C" \
{ \
    WSF_EXTERN int \
    axis2_remove_instance( \
        wsf_replay_detector_t *inst, \
        const axutil_env_t *env) \
    { \
        if (inst) \
        { \
            delete inst->callback; \
            AXIS2_FREE(env->allocator, inst->ops); \
            AXIS2_FREE(env->allocator, inst); \
        } \
        return AXIS2_SUCCESS; \
    } \
\
    axis2_status_t WSF_CALL \
    wsf_rampart_replay_detector_free( \
        rampart_replay_detector_t *inst, \
        const axutil_env_t *env) \
    { \
        return axis2_remove_instance((wsf_replay_detector_t *)inst, env);\
    } \
\
    WSF_EXTERN int \
    axis2_get_instance( \
        wsf_replay_detector_t **inst, \
        const axutil_env_t *env) \
    { \
        wsf_replay_detector_t* replay_detector = NULL; \
    \
        replay_detector = (wsf_replay_detector_t*)AXIS2_MALLOC(env->allocator, sizeof(wsf_replay_detector_t)); \
    \
        replay_detector->ops = (rampart_replay_detector_ops_t *)AXIS2_MALLOC(env->allocator, sizeof(rampart_replay_detector_ops_t)); \
        replay_detector->ops->is_replayed = wso2wsf::ReplayDetector::checkValidity; \
        replay_detector->ops->free = wsf_rampart_replay_detector_free; \
    \
        replay_detector->callback = new class_name; \
    \
        *inst = replay_detector; \
        if (!(*inst)) \
        { \
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[wsf_rampart]Cannot initialize the Replay Detection module"); \
            return AXIS2_FAILURE; \
        } \
\
        wso2wsf::Environment::setEnv(env); \
\
        return AXIS2_SUCCESS; \
    } \
} \


#endif // REPLAY_DETECTOR_H
