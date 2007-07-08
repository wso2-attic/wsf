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

#ifndef SAVAN_CONSTANTS_H
#define SAVAN_CONSTANTS_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @defgroup savan_constants
 * @ingroup Savan Constants
 * @{
 */

/* Eventing message types */
typedef enum savan_message_types
{
    SAVAN_MSG_TYPE_UNKNOWN = 0,
    SAVAN_MSG_TYPE_SUB,
    SAVAN_MSG_TYPE_SUB_RESPONSE,
    SAVAN_MSG_TYPE_UNSUB,
    SAVAN_MSG_TYPE_UNSUB_RESPONSE,
    SAVAN_MSG_TYPE_RENEW,
    SAVAN_MSG_TYPE_RENEW_RESPONSE,
    SAVAN_MSG_TYPE_GET_STATUS,
    SAVAN_MSG_TYPE_GET_STATUS_RESPONSE
} savan_message_types_t;

typedef struct savan_subs_mgr_info
{
    axis2_char_t *url;
    axis2_char_t *name;
    axutil_hash_t *list;
    axis2_svc_t *svc;
    axutil_env_t *env;
}savan_subs_mgr_info_t;

/* Eventing actions */
#define SAVAN_ACTIONS_SUB "http://schemas.xmlsoap.org/ws/2004/08/eventing/Subscribe"
#define SAVAN_ACTIONS_SUB_RESPONSE  "http://schemas.xmlsoap.org/ws/2004/08/eventing/SubscribeResponse"
#define SAVAN_ACTIONS_UNSUB "http://schemas.xmlsoap.org/ws/2004/08/eventing/Unsubscribe"
#define SAVAN_ACTIONS_UNSUB_RESPONSE "http://schemas.xmlsoap.org/ws/2004/08/eventing/UnsubscribeResponse"
#define SAVAN_ACTIONS_RENEW "http://schemas.xmlsoap.org/ws/2004/08/eventing/Renew"
#define SAVAN_ACTIONS_RENEW_RESPONSE "http://schemas.xmlsoap.org/ws/2004/08/eventing/RenewResponse"
#define SAVAN_ACTIONS_GET_STATUS "http://schemas.xmlsoap.org/ws/2004/08/eventing/GetStatus"
#define SAVAN_ACTIONS_GET_STATUS_RESPONSE "http://schemas.xmlsoap.org/ws/2004/08/eventing/GetStatusResponse"

#define EVENTING_NAMESPACE "http://schemas.xmlsoap.org/ws/2004/08/eventing"
#define EVENTING_NS_PREFIX "wse"
#define SAVAN_NAMESPACE "http://ws.apache.org/savan"
#define SAVAN_NS_PREFIX "savan"
#define ELEM_NAME_SUBSCRIBERS "Subscribers"
#define ELEM_NAME_ADD_SUBSCRIBER "AddSubscriber"
#define ELEM_NAME_REMOVE_SUBSCRIBER "RemoveSubscriber"
#define ELEM_NAME_TOPIC "Topic"
#define DEFAULT_DELIVERY_MODE "http://schemas.xmlsoap.org/ws/2004/08/eventing/DeliveryModes/Push"

/* Eventing element names */
#define ELEM_NAME_SUBSCRIBE             "Subscribe"
#define ELEM_NAME_SUB_RESPONSE          "SubscribeResponse"
#define ELEM_NAME_RENEW                 "Renew"
#define ELEM_NAME_RENEW_RESPONSE        "RenewResponse"
#define ELEM_NAME_UNSUB                 "Unsubscribe"
#define ELEM_NAME_UNSUB_RESPONSE        "UnsubscribeResponse"
#define ELEM_NAME_GETSTATUS             "GetStatus"
#define ELEM_NAME_GETSTATUS_RESPONSE    "GetStatusResponse"
#define ELEM_NAME_ENDTO                 "EndTo"
#define ELEM_NAME_DELIVERY              "Delivery"
#define ELEM_NAME_MODE                  "Mode"
#define ELEM_NAME_NOTIFYTO              "NotifyTo"
#define ELEM_NAME_EXPIRES               "Expires"
#define ELEM_NAME_FILTER                "Filter"
#define ELEM_NAME_ADDR                  "Address"
#define ELEM_NAME_REF_PARAM             "ReferenceParameter"
#define ELEM_NAME_ID                    "Identifier"
#define ELEM_NAME_SUB_MGR               "SubscriptionManager"

/* Keys to set options on the client side */
#define SAVAN_OP_KEY_ENDTO_EPR      "savan_op_key_endto"
#define SAVAN_OP_KEY_DELIVERY_MODE  "savan_op_key_del_mode"
#define SAVAN_OP_KEY_NOTIFY_EPR     "savan_op_key_notify"
#define SAVAN_OP_KEY_SUB_ID         "savan_op_key_sub_id"
#define SAVAN_OP_KEY_EXPIRES        "savan_op_key_expires"
#define SAVAN_OP_KEY_FILTER         "savan_op_key_filter"

#define SAVAN_KEY_SUB_ID            "savan_key_subscriber_id"
#define SAVAN_SUBSCRIBER_LIST       "savan_subs_list"

/** @} */
#ifdef __cplusplus
}
#endif

#endif /*SAVAN_CONSTANTS_H*/
