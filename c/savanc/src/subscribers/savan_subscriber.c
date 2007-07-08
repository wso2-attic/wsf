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
 
#include <axiom.h>
#include <platforms/axutil_platform_auto_sense.h>

#include <axis2_endpoint_ref.h>
#include <axis2_svc_client.h>

#include <savan_subscriber.h>

struct savan_subscriber_t
{
    axis2_char_t *id;
    axis2_endpoint_ref_t *end_to;
    axis2_endpoint_ref_t *notify_to;
    axis2_char_t *delivery_mode;
    axis2_char_t *expires;
    axis2_char_t *filter;
    axis2_char_t *topic;
    axis2_bool_t renewed;
};

/*****************************************************************************/

AXIS2_EXTERN savan_subscriber_t * AXIS2_CALL
savan_subscriber_create(
    const axutil_env_t *env)
{
    savan_subscriber_t *subscriber = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    
    subscriber = AXIS2_MALLOC(env->allocator, sizeof(savan_subscriber_t));
     
    if (!subscriber)
    { 
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;        
    }
    
    subscriber->id = NULL;
    subscriber->end_to = NULL;
    subscriber->notify_to = NULL;
    subscriber->delivery_mode = NULL;
    subscriber->expires = NULL;
    subscriber->filter = NULL;
    subscriber->topic = NULL;
    subscriber->renewed = AXIS2_FALSE;
        
    return subscriber;
}

AXIS2_EXTERN void AXIS2_CALL
savan_subscriber_free(
    savan_subscriber_t *subscriber, 
    const axutil_env_t *env)
{
    if(subscriber->id)
        AXIS2_FREE(env->allocator, subscriber->id);
    if(subscriber->delivery_mode)
        AXIS2_FREE(env->allocator, subscriber->delivery_mode);
    if(subscriber->expires)
        AXIS2_FREE(env->allocator, subscriber->expires);
    if(subscriber->filter)
        AXIS2_FREE(env->allocator, subscriber->filter);
    if(subscriber->topic)
        AXIS2_FREE(env->allocator, subscriber->topic);
    AXIS2_FREE(env->allocator, subscriber);
}

/******************************************************************************/

axis2_char_t * AXIS2_CALL
savan_subscriber_get_id(
    savan_subscriber_t *subscriber,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return subscriber->id;
}

/******************************************************************************/

axis2_status_t AXIS2_CALL
savan_subscriber_set_id(
    savan_subscriber_t *subscriber,
    const axutil_env_t *env,
    const axis2_char_t *id)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    /* If id is already set, free it */
    if (subscriber->id != NULL)
    {
        AXIS2_FREE(env->allocator, subscriber->id);
        subscriber->id = NULL;
    }
    
    /* copy the new id */
    subscriber->id = axutil_strdup(env, id);

    return AXIS2_SUCCESS;
}

/******************************************************************************/

axis2_status_t AXIS2_CALL
savan_subscriber_set_end_to(
    savan_subscriber_t *subscriber,
    const axutil_env_t *env,
    axis2_endpoint_ref_t *end_to)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    subscriber->end_to = end_to;

    return AXIS2_SUCCESS;
}

axis2_endpoint_ref_t *AXIS2_CALL
savan_subscriber_get_end_to(
    savan_subscriber_t *subscriber,
    const axutil_env_t *env)
{
    return subscriber->end_to;
}

/******************************************************************************/

axis2_status_t AXIS2_CALL
savan_subscriber_set_notify_to(
    savan_subscriber_t *subscriber,
    const axutil_env_t *env,
    axis2_endpoint_ref_t *notify_to)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    subscriber->notify_to = notify_to;

    return AXIS2_SUCCESS;
}    
            
axis2_endpoint_ref_t *AXIS2_CALL
savan_subscriber_get_notify_to(
    savan_subscriber_t *subscriber,
    const axutil_env_t *env)
{
    return subscriber->notify_to;
}

/******************************************************************************/

axis2_status_t AXIS2_CALL
savan_subscriber_set_delivery_mode(
    savan_subscriber_t *subscriber,
    const axutil_env_t *env,
    const axis2_char_t *mode)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    /* if already set, free it */
    if (subscriber->delivery_mode != NULL)
    {
        AXIS2_FREE(env->allocator, subscriber->delivery_mode);
        subscriber->delivery_mode = NULL;
    }
    
    /* copy the new one */
    subscriber->delivery_mode = axutil_strdup(env, mode);

    return AXIS2_SUCCESS;
}    
            
/******************************************************************************/

axis2_status_t AXIS2_CALL
savan_subscriber_set_expires(
    savan_subscriber_t *subscriber,
    const axutil_env_t *env,
    const axis2_char_t *expires)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    /* if already set, free it */
    if (subscriber->expires != NULL)
    {
        AXIS2_FREE(env->allocator, subscriber->expires);
        subscriber->expires = NULL;
    }
    
    /* copy the new one */
    subscriber->expires = axutil_strdup(env, expires);

    return AXIS2_SUCCESS;
}

/******************************************************************************/

axis2_char_t * AXIS2_CALL
savan_subscriber_get_expires(
    savan_subscriber_t *subscriber,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return subscriber->expires;
}

/******************************************************************************/

axis2_status_t AXIS2_CALL
savan_subscriber_set_filter(
    savan_subscriber_t *subscriber,
    const axutil_env_t *env,
    const axis2_char_t *filter)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    /* if already set, free it */
    if (subscriber->filter != NULL)
    {
        AXIS2_FREE(env->allocator, subscriber->filter);
        subscriber->filter = NULL;
    }
    
    /* copy the new one */
    subscriber->filter = axutil_strdup(env, filter);

    return AXIS2_SUCCESS;
}

axis2_char_t *AXIS2_CALL
savan_subscriber_get_filter(
    savan_subscriber_t *subscriber,
    const axutil_env_t *env)
{
    return subscriber->filter;
}

/******************************************************************************/

axis2_status_t AXIS2_CALL
savan_subscriber_publish(
    savan_subscriber_t *subscriber,
    const axutil_env_t *env,
    axiom_node_t *payload)
{
    axis2_svc_client_t *svc_client = NULL;
    axis2_char_t *path = NULL;
    axis2_options_t *options = NULL;
    axis2_status_t status = AXIS2_SUCCESS;
    axis2_endpoint_ref_t *to = NULL;
    const axis2_char_t *address = NULL;

    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
        "[savan] Start:savan_subscriber_publish");
	
    path = AXIS2_GETENV("AXIS2C_HOME");
    svc_client = axis2_svc_client_create(env, path);

    /* Setup options */
    options = axis2_options_create(env);
    address = axis2_endpoint_ref_get_address(subscriber->notify_to, env);
    to = axis2_endpoint_ref_create(env, address);
    axis2_options_set_to(options, env, to);
    axis2_options_set_xml_parser_reset(options, env, AXIS2_FALSE);

    /* Set service client options */
    axis2_svc_client_set_options(svc_client, env, options);
    axis2_svc_client_send_robust(svc_client, env, payload);

    if(svc_client)
        axis2_svc_client_free(svc_client, env);
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
        "[savan] End:savan_subscriber_publish");
    return status;
}

/******************************************************************************/

axis2_status_t AXIS2_CALL
savan_subscriber_set_renew_status(
    savan_subscriber_t *subscriber,
    const axutil_env_t *env,
    axis2_bool_t renewed)
{
    subscriber->renewed = renewed;

    return AXIS2_SUCCESS;
}

/******************************************************************************/

axis2_bool_t AXIS2_CALL
savan_subscriber_get_renew_status(
    savan_subscriber_t *subscriber,
    const axutil_env_t *env)
{
    return subscriber->renewed;
}

axis2_status_t AXIS2_CALL
savan_subscriber_set_topic(
    savan_subscriber_t *subscriber,
    const axutil_env_t *env,
    axis2_char_t *topic)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    subscriber->topic = axutil_strdup(env, topic);

    return AXIS2_SUCCESS;
}

axis2_char_t *AXIS2_CALL
savan_subscriber_get_topic(
    savan_subscriber_t *subscriber,
    const axutil_env_t *env)
{
    return subscriber->topic;
}


