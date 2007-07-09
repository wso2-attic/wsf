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



#include <rp_wss11.h>

struct rp_wss11_t
{
    axis2_bool_t must_support_ref_key_identifier;
    axis2_bool_t must_support_ref_issuer_serial;
    axis2_bool_t must_support_ref_external_uri;
    axis2_bool_t must_support_ref_embedded_token;
    axis2_bool_t must_support_ref_thumbprint;
    axis2_bool_t must_support_ref_encryptedkey;
    axis2_bool_t require_signature_confirmation;
    axis2_bool_t must_support_direct_reference;
};

AXIS2_EXTERN rp_wss11_t *AXIS2_CALL
rp_wss11_create(const axutil_env_t *env)
{
    rp_wss11_t *wss11 = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    wss11 =  (rp_wss11_t *) AXIS2_MALLOC (env->allocator,
    sizeof (rp_wss11_t));

    if(wss11 == NULL)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    wss11->must_support_ref_key_identifier = AXIS2_FALSE;
    wss11->must_support_ref_issuer_serial  = AXIS2_FALSE;
    wss11->must_support_ref_external_uri = AXIS2_FALSE;
    wss11->must_support_ref_embedded_token = AXIS2_FALSE;
    wss11->must_support_ref_thumbprint = AXIS2_FALSE;
    wss11->must_support_ref_encryptedkey = AXIS2_FALSE;
    wss11->require_signature_confirmation = AXIS2_FALSE;
    wss11->must_support_direct_reference = AXIS2_TRUE;

    return wss11;

}

AXIS2_EXTERN void AXIS2_CALL 
rp_wss11_free(rp_wss11_t *wss11,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    if(wss11)
    {
        AXIS2_FREE(env->allocator, wss11);
        wss11 = NULL;
    }
    return;
}


/* Implementations */
AXIS2_EXTERN axis2_bool_t AXIS2_CALL 
rp_wss11_get_must_support_ref_key_identifier(rp_wss11_t *wss11,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    
    return wss11->must_support_ref_key_identifier;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_wss11_set_must_support_ref_key_identifier(rp_wss11_t *wss11,
            const axutil_env_t *env,
            axis2_bool_t must_support_ref_key_identifier)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,must_support_ref_key_identifier,AXIS2_FAILURE);
    wss11->must_support_ref_key_identifier = must_support_ref_key_identifier;

    return AXIS2_SUCCESS;
    
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL 
rp_wss11_get_must_support_ref_issuer_serial(rp_wss11_t *wss11,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    
    return wss11->must_support_ref_issuer_serial;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_wss11_set_must_support_ref_issuer_serial(rp_wss11_t *wss11,
            const axutil_env_t *env,
            axis2_bool_t must_support_ref_issuer_serial)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,must_support_ref_issuer_serial,AXIS2_FAILURE);    
    wss11->must_support_ref_issuer_serial = must_support_ref_issuer_serial;

    return AXIS2_SUCCESS;
    
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL 
rp_wss11_get_must_support_ref_external_uri(rp_wss11_t *wss11,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
        
    return wss11->must_support_ref_external_uri;
    
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_wss11_set_must_support_ref_external_uri(rp_wss11_t *wss11,
            const axutil_env_t *env,
            axis2_bool_t must_support_ref_external_uri)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,must_support_ref_external_uri,AXIS2_FAILURE);    
    wss11->must_support_ref_external_uri = must_support_ref_external_uri;

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL 
rp_wss11_get_must_support_ref_embedded_token(rp_wss11_t *wss11,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
        
    return wss11->must_support_ref_embedded_token;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_wss11_set_must_support_ref_embedded_token(rp_wss11_t *wss11,
            const axutil_env_t *env,
            axis2_bool_t must_support_ref_embedded_token)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,must_support_ref_embedded_token,AXIS2_FAILURE);    
    wss11->must_support_ref_embedded_token = must_support_ref_embedded_token;

    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axis2_bool_t AXIS2_CALL 
rp_wss11_get_must_support_ref_thumbprint(rp_wss11_t *wss11,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
        
    return wss11->must_support_ref_thumbprint;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_wss11_set_must_support_must_support_ref_thumbprint(rp_wss11_t *wss11,
            const axutil_env_t *env,
            axis2_bool_t must_support_ref_thumbprint)
{
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error,must_support_ref_thumbprint,AXIS2_FAILURE);
    wss11->must_support_ref_thumbprint = must_support_ref_thumbprint;

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL 
rp_wss11_get_must_support_ref_encryptedkey(rp_wss11_t *wss11,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    
    return wss11->must_support_ref_encryptedkey;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_wss11_set_must_support_ref_encryptedkey(rp_wss11_t *wss11,
            const axutil_env_t *env,
            axis2_bool_t must_support_ref_encryptedkey)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,must_support_ref_encryptedkey,AXIS2_FAILURE);    
    wss11->must_support_ref_encryptedkey = must_support_ref_encryptedkey;

    return AXIS2_SUCCESS;
    
}


AXIS2_EXTERN axis2_bool_t AXIS2_CALL 
rp_wss11_get_require_signature_confirmation(rp_wss11_t *wss11,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
        
    return wss11->require_signature_confirmation;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_wss11_set_require_signature_confirmation(rp_wss11_t *wss11,
            const axutil_env_t *env,
            axis2_bool_t require_signature_confirmation)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,require_signature_confirmation,AXIS2_FAILURE);    
    wss11->require_signature_confirmation = require_signature_confirmation;

    return AXIS2_SUCCESS;
    
}
