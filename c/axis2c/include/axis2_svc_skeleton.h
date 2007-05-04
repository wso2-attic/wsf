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

#ifndef AXIS2_SVC_SKELETON_H
#define AXIS2_SVC_SKELETON_H

/**
 * @defgroup axis2_soc_api service API
 * @ingroup axis2
 * @{
 * @} 
 */

/** 
 * @defgroup axis2_svc_skeleton service skeleton
 * @ingroup axis2_svc_api
 * service skeleton API should be implemented by all services
 * that are to be deployed with Axis2/C engine. 
 * @{
 */

/**
 * @file axis2_svc_skeleton.h
 */

#include <axiom_node.h>
#include <axutil_array_list.h>
#include <axis2_msg_ctx.h>

#ifdef __cplusplus
extern "C"
{
#endif


    /** Type name for struct axis2_svc_skeleton_ops */
    typedef struct axis2_svc_skeleton_ops axis2_svc_skeleton_ops_t;
    /** Type name for struct axis2_svc_skeleton */
    typedef struct axis2_svc_skeleton axis2_svc_skeleton_t;
   
    /**
     * service skeleton ops struct.
     * Encapsulator struct for operations of axis2_svc_skeleton.
     */
    struct axis2_svc_skeleton_ops
    {

        /**
         * Initializes the service implementation.
         * @param svc_skeleton pointer to svc_skeleton struct
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        int (AXIS2_CALL *
                init)(
                    axis2_svc_skeleton_t *svc_skeleton,
                    const axutil_env_t *env);

        /**
         * Invokes the service. This function should be used to call up the
         * functions implementing service operations.
         * @param svc_skeli pointer to svc_skeli struct
         * @param env pointer to environment struct
         * @param node pointer to node struct
         * @param msg_ctx pointer to message context struct
         * @return pointer to AXIOM node resulting from the invocation. 
         * In case of one way operations, NULL would be returned with 
         * status in environment error set to AXIS2_SUCCESS. On error
         * NULL would be returned with error status set to AXIS2_FAILURE
         */
        axiom_node_t *(AXIS2_CALL*
                invoke)(
                    axis2_svc_skeleton_t *svc_skeli,
                    const axutil_env_t *env,
                    axiom_node_t *node,
                    axis2_msg_ctx_t *msg_ctx);

        /**
         * This method would be called if a fault is detected.
         * @param svc_skeli pointer to svc_skeli struct
         * @param env pointer to environment struct
         * @param node pointer to node struct
         * @return pointer to AXIOM node reflecting the fault, NULL on error
         */
        axiom_node_t *(AXIS2_CALL*
                on_fault)(
                    axis2_svc_skeleton_t *svc_skeli,
                    const axutil_env_t *env,
                    axiom_node_t *node);

        /**
         * Frees service implementation.
         * @param svc_skeli pointer to svc_skeli struct
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        int (AXIS2_CALL *
                free)(
                    axis2_svc_skeleton_t *svc_skeli,
                    const axutil_env_t *env);

    } ;

    /**
     * service skeleton struct.
     */
    struct axis2_svc_skeleton
    {
        /** operations of service skeleton */
        const axis2_svc_skeleton_ops_t *ops;
        /** Array list of functions, implementing the service operations */
        axutil_array_list_t *func_array;
    };


/*************************** Function macros **********************************/

/** Initialize the svc skeleton.
    @sa axis2_svc_skeleton_ops#init */
#define AXIS2_SVC_SKELETON_INIT(svc_skeleton, env) \
      ((svc_skeleton)->ops->init (svc_skeleton, env))

/** Frees the svc skeleton.
    @sa axis2_svc_skeleton_ops#free */
#define AXIS2_SVC_SKELETON_FREE(svc_skeleton, env) \
      ((svc_skeleton)->ops->free (svc_skeleton, env))

/** Invokes axis2 service skeleton.
    @sa axis2_svc_skeleton_ops#invoke */
#define AXIS2_SVC_SKELETON_INVOKE(svc_skeleton, env, node, msg_ctx) \
      ((svc_skeleton)->ops->invoke (svc_skeleton, env, node, msg_ctx))

/** Called on fault.
    @sa axis2_svc_skeleton_ops#on_fault */
#define AXIS2_SVC_SKELETON_ON_FAULT(svc_skeleton, env, node) \
      ((svc_skeleton)->ops->on_fault (svc_skeleton, env, node))

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* AXIS2_SVC_SKELETON_H */
