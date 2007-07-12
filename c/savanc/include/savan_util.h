/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License")
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
 
#ifndef SAVAN_UTIL_H
#define SAVAN_UTIL_H

#include <axis2_const.h>
#include <axutil_error.h>
#include <axutil_hash.h>
#include <axis2_defines.h>
#include <axutil_utils_defines.h>
#include <axutil_env.h>
#include <axutil_allocator.h>
#include <axis2_msg_ctx.h>

#include <savan_constants.h>
#include <savan_subscriber.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @defgroup savan_util
 * @ingroup Savan Util
 * @{
 */
    
    savan_message_types_t AXIS2_CALL
    savan_util_get_message_type(
        axis2_msg_ctx_t *msg_ctx,
        const axutil_env_t *env);
    
    /**
    * Extracts the subscription ID from the given messsage
    * context.
    * @param env pointer to environment struct
    * @param msg_ctx pointer to message context
    * @return the ID on success, else NULL
    */
    axis2_char_t * AXIS2_CALL
    savan_util_get_subscription_id_from_msg(
        const axutil_env_t *env,
        axis2_msg_ctx_t *msg_ctx);

    /**
    * Find the subscriber object from the store using the given messsage
    * context.
    * @param env pointer to environment struct
    * @param msg_ctx pointer to message context
    * @param sub_id pointer to subscription id 
    * @return a pointer to subscriber on success, else NULL
    */
    savan_subscriber_t * AXIS2_CALL
    savan_util_get_subscriber_from_msg(
        const axutil_env_t *env,
        axis2_msg_ctx_t *msg_ctx,
        axis2_char_t *sub_id);

    /**
    * Get the subscriber store from the service
    * Note that if the subscription manager is a separate service from
    * the publisher service then both SubscriptionMgrName and SubscriptionMgrURL
    * must be set in the publishers services.xml
    * @param env pointer to environment struct
    * @param msg_ctx pointer to message context
    * @return the store on success, else NULL
    */
    axutil_hash_t * AXIS2_CALL
    savan_util_get_subscriber_store(
        const axutil_env_t *env,
        axis2_msg_ctx_t *msg_ctx);

    /**
    * Add the subscriber to subscription manager services' store
    * Note that if the subscription manager is a separate service from
    * the publisher service then both SubscriptionMgrName and SubscriptionMgrURL
    * must be set in the publishers services.xml
    * @param env pointer to environment struct
    * @param msg_ctx pointer to message context
    * @param subscriber
    * @return the store on success, else NULL
    */
    axis2_status_t AXIS2_CALL
    savan_util_add_subscriber(
        const axutil_env_t *env,
        axis2_msg_ctx_t *msg_ctx,
        savan_subscriber_t *subscriber);

    /**
    * Remove the subscriber from subscription manager services' store
    * Note that if the subscription manager is a separate service from
    * the publisher service then both SubscriptionMgrName and SubscriptionMgrURL
    * must be set in the publishers services.xml
    * @param env pointer to environment struct
    * @param msg_ctx pointer to message context
    * @param subscriber
    * @return the store on success, else NULL
    */
    axis2_status_t AXIS2_CALL
    savan_util_remove_subscriber(
        const axutil_env_t *env,
        axis2_msg_ctx_t *msg_ctx,
        savan_subscriber_t *subscriber);

    /**
    * Calculate and return an expiry time for the subscription
    * @param env pointer to environment struct
    * @return the expiry time on success, else NULL
    */
    axis2_char_t * AXIS2_CALL
    savan_util_get_expiry_time(
        const axutil_env_t *env);

     /**
    * Calculate and return a new expiry time for the subscription based on the
    * current expiry time.
    * @param env pointer to environment struct
    * @param expiry current expiry time
    * @return the new expiry time on success, else NULL
    */
    axis2_char_t * AXIS2_CALL
    savan_util_get_renewed_expiry_time(
        const axutil_env_t *env,
        axis2_char_t *expiry);
    
    /**
    * Create storage hash and set as a service parameter.
    * @param env pointer to environment struct
    * @param svc subscription service
    * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
    */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL 
    savan_util_set_store(
        axis2_svc_t *svc,
        const axutil_env_t *env,
        axis2_char_t *store_name);

    /**
    * Get the subscribers registered for a topic
    * @param env pointer to environment struct
    * @param topic topic for which the subscribers are registered
    * @param subs_mgr_url url of the subscription manager
    * @return subscribers in a hash table
    */
    AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
    savan_util_get_subscriber_list_from_remote_subs_mgr(
        const axutil_env_t *env,
        axis2_char_t *topic,
        axis2_char_t *subs_mgr_url,
        void *svc_client);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    savan_util_get_topic_name_from_topic_url(
        const axutil_env_t *env,
        axis2_char_t *topic_url);

/** @} */
#ifdef __cplusplus
}
#endif
 
#endif /*SAVAN_UTIL_H*/
