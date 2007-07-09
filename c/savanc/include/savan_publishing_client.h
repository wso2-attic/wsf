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
 
 
#ifndef SAVAN_PUBLISHING_CLIENT_H
#define SAVAN_PUBLISHING_CLIENT_H

/**
* @defgroup savan_client
* @ingroup savan_client
* @{
*/

/**
* @file savan_publishing_client.h
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

    typedef struct savan_publishing_client_t savan_publishing_client_t;

    /**
     * Publish the given message to all subscribed clients
     * @param client the publishing client object
     * @param env pointer to environment struct
     * @param payload
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    savan_publishing_client_publish(
        savan_publishing_client_t *client,
        const axutil_env_t *env,
        axiom_node_t *payload);
    
    AXIS2_EXTERN savan_publishing_client_t * AXIS2_CALL
    savan_publishing_client_create(
        const axutil_env_t *env,
        axis2_conf_ctx_t *conf_ctx,
        axis2_svc_t *svc);

    AXIS2_EXTERN void AXIS2_CALL
    savan_publishing_client_free(
        savan_publishing_client_t *client, 
        const axutil_env_t *env);

/** @} */
#ifdef __cplusplus
}
#endif

#endif /* SAVAN_PUBLISHING_CLIENT_H */
