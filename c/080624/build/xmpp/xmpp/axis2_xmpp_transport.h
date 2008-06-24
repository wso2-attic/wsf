/*
* Copyright 2004,2005 The Apache Software Foundation.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain count copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef AXIS2_XMPP_TRANSPORT_H
#define AXIS2_XMPP_TRANSPORT_H

#include <axis2_const.h>
#include <axutil_error.h>

#ifdef __cplusplus
extern "C"
{
#endif

/** @defgroup axis2_core_trans_xmpp xmpp transport
 * @ingroup axis2_transport
 * Description.
 * @{
 */

/**
 * @defgroup axis2_core_transport_xmpp core xmpp transport
 * @ingroup axis2_core_trans_xmpp
 * @{
 */

/**
 * @brief XMPP protocol and message context constants.
 *
 */
#define AXIS2_XMPP_PARSER "XMPP_PARSER"

/**
 * DEFAULT_SO_TIMEOUT
 */
#define AXIS2_XMPP_DEFAULT_SO_TIMEOUT 30000

/**
 * DEFAULT_CONNECTION_TIMEOUT
 */
#define AXIS2_XMPP_DEFAULT_CONNECTION_TIMEOUT 60000

/**
 * Field TRANSPORT_XMPP
 */
#define AXIS2_TRANSPORT_XMPP "xmpp"

/**
 * JID of the client
 */
#define AXIS2_XMPP_CLIENT_JID "XMPP_CLIENT_JID"

/**
 * Key for the XMPP properties hash table
 */
#define AXIS2_XMPP_PROPERTIES "XMPP_PROPERTIES"

/**
 * Parameter which maps a service to a JID 
 */
#define AXIS2_XMPP_PARAM_ID "xmpp_id"


/**
 * Password for the given JID
 */
#define AXIS2_XMPP_PARAM_PASSWORD "xmpp_password"

/**
 * A JID to which the service should subscribe
 */
#define AXIS2_XMPP_PARAM_SUBSCRIBE_TO "xmpp_subscribe_to"

/**
 *
 * The type of the XMPP entity to subscribe
 */
#define AXIS2_XMPP_PARAM_SUBSCRIBE_TYPE "xmpp_subscribe_type"


/* Error codes */
#define AXIS2_XMPP_ERROR_START (AXIS2_ERROR_LAST + 3000)
#define AXIS2_XMPP_PARSER_CREATE_FAILED     (AXIS2_XMPP_ERROR_START + 0)
#define AXIS2_XMPP_SERVER_CONNECT_FAILED    (AXIS2_XMPP_ERROR_START + 1)

/* Subscribe entity types */
#define AXIS2_XMPP_SUB_TYPE_USER    "user"
#define AXIS2_XMPP_SUB_TYPE_ROOM    "room" 

/** @} */

#ifdef __cplusplus
}
#endif
#endif  /* AXIS2_XMPP_TRANSPORT_H */
