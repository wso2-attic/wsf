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
#ifndef WSFES_SUBSCRIPTION_H
#define WSFES_SUBSCRIPTION_H


#include <axis2_svc_skeleton.h>
#include <axutil_log_default.h>
#include <axutil_error_default.h>
#include <axiom_text.h>
#include <axiom_node.h>
#include <axiom_element.h>

AXIS2_EXTERN axiom_node_t *AXIS2_CALL
savan_subs_mgr_add_subscriber(
    const axutil_env_t *env,
    axiom_node_t *node,
    axis2_msg_ctx_t *msg_ctx);

AXIS2_EXTERN void * AXIS2_CALL
savan_subs_mgr_remove_subscriber(
    const axutil_env_t *env,
    axiom_node_t *remove_sub_node,
    axis2_msg_ctx_t *msg_ctx);

AXIS2_EXTERN axiom_node_t *AXIS2_CALL
savan_subs_mgr_get_subscriber(
    const axutil_env_t *env,
    axiom_node_t *node,
    axis2_msg_ctx_t *msg_ctx);

AXIS2_EXTERN axiom_node_t *AXIS2_CALL
savan_subs_mgr_get_subscriber_list(
    const axutil_env_t *env,
    axiom_node_t *node,
    axis2_msg_ctx_t *msg_ctx);

AXIS2_EXTERN axiom_node_t *AXIS2_CALL
savan_subs_mgr_get_topic_list(
    const axutil_env_t *env,
    axiom_node_t *node,
    axis2_msg_ctx_t *msg_ctx);

#endif /* WSFES_SUBSCRIPTION_H*/

