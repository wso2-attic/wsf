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
 
 
#ifndef SAVAN_CLIENT_H
#define SAVAN_CLIENT_H


/**
* @defgroup savan_client 
* @ingroup savan_client
* @{
*/

/**
* @file savan_client.h
*/

#include <axis2_defines.h>
#include <axutil_env.h>
#include <axis2_conf_ctx.h>
#include <axis2_svc_client.h>
#include <axutil_hash.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct savan_client_t savan_client_t;

    /**
     * Send Subscribe request using the given service client
     * @param client the client object
     * @param env pointer to environment struct
     * @param svc_client client for the publisher service
     * @param options map containing options for the Subscribe request
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    savan_client_subscribe(
        savan_client_t *client,
        const axutil_env_t *env,
        axis2_svc_client_t *svc_client,
        axutil_hash_t *options);
    
    /**
     * Send Renew request using the given service client
     * @param client the client object
     * @param env pointer to environment struct
     * @param svc_client client for the publisher service
     * @param options map containing options for the Renew request
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    savan_client_renew(
        savan_client_t *client,
        const axutil_env_t *env,
        axis2_svc_client_t *svc_client,
        axutil_hash_t *options);
            
    /**
     * Send Unsubscribe request using the given service client
     * @param client the client object
     * @param env pointer to environment struct
     * @param svc_client client for the publisher service
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    savan_client_unsubscribe(
        savan_client_t *client,
        const axutil_env_t *env,
        axis2_svc_client_t *svc_client); 

    /**
     * Send GetStatus request using the given service client
     * @param client the client object
     * @param env pointer to environment struct
     * @param svc_client client for the publisher service
     * @return expiry string on success, NULL on failure
     */
    AXIS2_EXTERN axis2_char_t * AXIS2_CALL
    savan_client_get_status(
        savan_client_t *client,
        const axutil_env_t *env,
        axis2_svc_client_t *svc_client);

    /**
     * Get the subscription id assigned by the event source
     * @param client the client object
     * @param env pointer to environment struct
     * @return id string on success, NULL on failure
     */
    AXIS2_EXTERN axis2_char_t * AXIS2_CALL
    savan_client_get_sub_id(
        savan_client_t *client);
 
    /**
     * Get the subscription url assigned by the event source
     * @param client the client object
     * @param env pointer to environment struct
     * @return id string on success, NULL on failure
     */
    AXIS2_EXTERN axis2_char_t * AXIS2_CALL
    savan_client_get_sub_url(
        savan_client_t *client);
   
    /**
     * Create a savan client
     * @param env pointer to environment struct
     * @return Pointer to client on success, NULL on failure
     */
    AXIS2_EXTERN savan_client_t * AXIS2_CALL
    savan_client_create(
        const axutil_env_t *env);
            
    
/** @} */
#ifdef __cplusplus
}
#endif

#endif /* SAVAN_CLIENT_H */
