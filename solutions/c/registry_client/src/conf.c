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
#include <remote_registry_conf.h>
#include <axutil_utils.h>
#include <remote_registry_constants.h>

/** 
 * @brief conf struct impl
 *	Rest Client Interface for C
 */
  
struct remote_registry_conf
{
    axis2_char_t *username;
    axis2_char_t *password;
    axis2_char_t *reg_url;
    int conn_timeout;
    int cache_timeout;
    int cache_entries_limit;
};


AXIS2_EXTERN remote_registry_conf_t* AXIS2_CALL
remote_registry_conf_create(
    const axutil_env_t *env)
{
    remote_registry_conf_t *conf = NULL;
   
    conf =  (remote_registry_conf_t *)AXIS2_MALLOC(env->allocator, 
            sizeof(remote_registry_conf_t));
	
    if(!conf)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}

    conf->username = NULL;
    conf->password = NULL;
    conf->reg_url = NULL;
	conf->cache_entries_limit = REMOTE_REGISTRY_DEFAULT_CACHE_LIMIT;
    
	return conf;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
remote_registry_conf_free(
    remote_registry_conf_t *conf, 
    const axutil_env_t *env)
{
    if(conf->username)
    {
        AXIS2_FREE(env->allocator, conf->username);
        conf->username = NULL;
    }
    
    if(conf->password)
    {
        AXIS2_FREE(env->allocator, conf->password);
        conf->password = NULL;
    }
    
    if(conf->reg_url)
    {
        AXIS2_FREE(env->allocator, conf->reg_url);
        conf->reg_url = NULL;
    }

	AXIS2_FREE(env->allocator, conf);

	return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_conf_set_username(
    remote_registry_conf_t *conf,
    const axutil_env_t *env,
    const axis2_char_t *username) 
{
    conf->username = axutil_strdup(env, username);
    return AXIS2_SUCCESS;
}
AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_conf_set_password(
    remote_registry_conf_t *conf,
    const axutil_env_t *env,
    const axis2_char_t *password)
{
    conf->password = axutil_strdup(env, password);
    return AXIS2_SUCCESS;
}
AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_conf_set_reg_url(
    remote_registry_conf_t *conf,
    const axutil_env_t *env,
    const axis2_char_t *reg_url)
{
    conf->reg_url = axutil_strdup(env, reg_url);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_conf_set_conn_timeout(
    remote_registry_conf_t *conf,
    const axutil_env_t *env,
    int conn_timeout)
{
    conf->conn_timeout = conn_timeout;
    return AXIS2_SUCCESS;
}
AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_conf_set_cache_timeout(
    remote_registry_conf_t *conf,
    const axutil_env_t *env,
    int cache_timeout)
{
    conf->cache_timeout = cache_timeout;
    return AXIS2_SUCCESS;
}
AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_conf_set_cache_entries_limit(
    remote_registry_conf_t *conf,
    const axutil_env_t *env,
    int cache_entries_limit)
{
    conf->cache_entries_limit = cache_entries_limit;
    return AXIS2_SUCCESS;
}

/* getters */
AXIS2_EXTERN axis2_char_t *AXIS2_CALL
remote_registry_conf_get_username(
    remote_registry_conf_t *conf,
    const axutil_env_t *env)
{
    return conf->username;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
remote_registry_conf_get_password(
    remote_registry_conf_t *conf,
    const axutil_env_t *env)
{
    return conf->password;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
remote_registry_conf_get_reg_url(
    remote_registry_conf_t *conf,
    const axutil_env_t *env)
{
    return conf->reg_url;
}

AXIS2_EXTERN int AXIS2_CALL
remote_registry_conf_get_conn_timeout(
    remote_registry_conf_t *conf,
    const axutil_env_t *env)
{
    return conf->conn_timeout;
}
AXIS2_EXTERN int AXIS2_CALL remote_registry_conf_get_cache_timeout(
    remote_registry_conf_t *conf,
    const axutil_env_t *env)
{
    return conf->cache_timeout;
}

AXIS2_EXTERN int AXIS2_CALL remote_registry_conf_get_cache_entries_limit(
    remote_registry_conf_t *conf,
    const axutil_env_t *env)
{
    return conf->cache_entries_limit;
}
