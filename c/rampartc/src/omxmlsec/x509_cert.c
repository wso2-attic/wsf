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

#include <stdio.h>
#include <axis2_util.h>
#include <oxs_constants.h>
#include <oxs_x509_cert.h>


struct oxs_x509_cert_t
{
    int serial_number;
    axis2_char_t *subject;
    axis2_char_t *issuer;
    axis2_char_t *key_identifier;
    axis2_char_t *fingerprint;
    axis2_char_t *date;
    axis2_char_t *hash;
    axis2_char_t *data;
    openssl_pkey_t *public_key;
};



AXIS2_EXTERN oxs_x509_cert_t *AXIS2_CALL
oxs_x509_cert_create(const axutil_env_t *env)
{
    oxs_x509_cert_t *x509_cert = NULL;
    AXIS2_ENV_CHECK(env, NULL);

    x509_cert = (oxs_x509_cert_t *)AXIS2_MALLOC(env->allocator,
                sizeof(oxs_x509_cert_t));

    if(!x509_cert)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    /* initialize properties */
    x509_cert->serial_number = 0;
    x509_cert->subject =NULL;
    x509_cert->issuer =NULL;
    x509_cert->key_identifier =NULL;
    x509_cert->fingerprint =NULL;
    x509_cert->date =NULL;
    x509_cert->hash =NULL;
    x509_cert->data =NULL;
    x509_cert->public_key =NULL;

    return x509_cert;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_x509_cert_free(oxs_x509_cert_t *x509_cert,
                   const axutil_env_t *env)
{
    if(x509_cert->subject ){
        AXIS2_FREE(env->allocator, x509_cert->subject );
        x509_cert->subject =NULL;
    }
    if(x509_cert->issuer ){
        AXIS2_FREE(env->allocator, x509_cert->issuer );
        x509_cert->issuer =NULL;
    }
    if(x509_cert->key_identifier ){
        AXIS2_FREE(env->allocator, x509_cert->key_identifier );
        x509_cert->key_identifier =NULL;
    }
    if(x509_cert->fingerprint ){
        AXIS2_FREE(env->allocator, x509_cert->fingerprint );
        x509_cert->fingerprint =NULL;
    }
    if(x509_cert->date ){
        AXIS2_FREE(env->allocator, x509_cert->date );
        x509_cert->date =NULL;
    }
    if(x509_cert->hash ){
        AXIS2_FREE(env->allocator, x509_cert->hash );
        x509_cert->hash =NULL;
    }
    if(x509_cert->data ){
        AXIS2_FREE(env->allocator, x509_cert->data );
        x509_cert->data =NULL;
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_x509_cert_copy_to(oxs_x509_cert_t *x509_cert,
                      const axutil_env_t *env,
                      oxs_x509_cert_t *to)
{
    oxs_x509_cert_set_serial_number(to, env, x509_cert->serial_number);
    oxs_x509_cert_set_issuer(to, env, x509_cert->issuer);
    oxs_x509_cert_set_key_identifier(to, env, x509_cert->key_identifier);
    oxs_x509_cert_set_subject(to, env, x509_cert->subject);
    oxs_x509_cert_set_fingerprint(to, env, x509_cert->fingerprint);
    oxs_x509_cert_set_date(to, env, x509_cert->date);
    oxs_x509_cert_set_hash(to, env, x509_cert->hash);
    oxs_x509_cert_set_data(to, env, x509_cert->data);
    oxs_x509_cert_set_public_key(to, env, x509_cert->public_key);

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN int AXIS2_CALL
oxs_x509_cert_get_serial_number(oxs_x509_cert_t *x509_cert,
                                const axutil_env_t *env)
{
    return x509_cert->serial_number;
}
AXIS2_EXTERN axis2_char_t *AXIS2_CALL
oxs_x509_cert_get_subject(oxs_x509_cert_t *x509_cert,
                          const axutil_env_t *env)
{
    return x509_cert->subject;
}
AXIS2_EXTERN axis2_char_t *AXIS2_CALL
oxs_x509_cert_get_issuer(oxs_x509_cert_t *x509_cert,
                         const axutil_env_t *env)
{
    return x509_cert->issuer;
}
AXIS2_EXTERN axis2_char_t *AXIS2_CALL
oxs_x509_cert_get_key_identifier(oxs_x509_cert_t *x509_cert,
                                 const axutil_env_t *env)
{
    return x509_cert->key_identifier;
}
AXIS2_EXTERN axis2_char_t *AXIS2_CALL
oxs_x509_cert_get_fingerprint(oxs_x509_cert_t *x509_cert,
                              const axutil_env_t *env)
{
    return x509_cert->fingerprint;
}
AXIS2_EXTERN axis2_char_t *AXIS2_CALL
oxs_x509_cert_get_date(oxs_x509_cert_t *x509_cert,
                       const axutil_env_t *env)
{
    return x509_cert->date;
}
AXIS2_EXTERN axis2_char_t *AXIS2_CALL
oxs_x509_cert_get_hash(oxs_x509_cert_t *x509_cert,
                       const axutil_env_t *env)
{
    return x509_cert->hash;
}
AXIS2_EXTERN axis2_char_t *AXIS2_CALL
oxs_x509_cert_get_data(oxs_x509_cert_t *x509_cert,
                       const axutil_env_t *env)
{
    return x509_cert->data;
}

AXIS2_EXTERN openssl_pkey_t *AXIS2_CALL
oxs_x509_cert_get_public_key(oxs_x509_cert_t *x509_cert,
                             const axutil_env_t *env)
{
    return x509_cert->public_key;
}

/*Setters*/
AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_x509_cert_set_serial_number(oxs_x509_cert_t *x509_cert,
                                const axutil_env_t *env,
                                int value)
{
    x509_cert->serial_number= value;

    return AXIS2_SUCCESS;
}
AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_x509_cert_set_subject(oxs_x509_cert_t *x509_cert,
                          const axutil_env_t *env,
                          axis2_char_t *value)
{
    if(x509_cert->subject)
    {
        AXIS2_FREE(env->allocator, x509_cert->subject);
        x509_cert->subject = NULL;
    }
    x509_cert->subject = (axis2_char_t *)axutil_strdup(env, value);
    return AXIS2_SUCCESS;
}
AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_x509_cert_set_issuer(oxs_x509_cert_t *x509_cert,
                         const axutil_env_t *env,
                         axis2_char_t *value)
{
    if(x509_cert->issuer)
    {
        AXIS2_FREE(env->allocator, x509_cert->issuer);
        x509_cert->issuer = NULL;
    }
    x509_cert->issuer = (axis2_char_t *)axutil_strdup(env, value);
    return AXIS2_SUCCESS;
}
AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_x509_cert_set_key_identifier(oxs_x509_cert_t *x509_cert,
                                 const axutil_env_t *env,
                                 axis2_char_t *value)
{
    if(x509_cert->key_identifier)
    {
        AXIS2_FREE(env->allocator, x509_cert->key_identifier);
        x509_cert->key_identifier = NULL;
    }
    x509_cert->key_identifier = (axis2_char_t *)axutil_strdup(env, value);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_x509_cert_set_fingerprint(oxs_x509_cert_t *x509_cert,
                              const axutil_env_t *env,
                              axis2_char_t *value)
{
    if(x509_cert->fingerprint)
    {
        AXIS2_FREE(env->allocator, x509_cert->fingerprint);
        x509_cert->fingerprint = NULL;
    }
    x509_cert->fingerprint = (axis2_char_t *)axutil_strdup(env, value);
    return AXIS2_SUCCESS;
}
AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_x509_cert_set_date(oxs_x509_cert_t *x509_cert,
                       const axutil_env_t *env,
                       axis2_char_t *value)
{
    if(x509_cert->date)
    {
        AXIS2_FREE(env->allocator, x509_cert->date);
        x509_cert->date = NULL;
    }
    x509_cert->date = (axis2_char_t *)axutil_strdup(env, value);
    return AXIS2_SUCCESS;
}
AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_x509_cert_set_hash(oxs_x509_cert_t *x509_cert,
                       const axutil_env_t *env,
                       axis2_char_t *value)
{
    if(x509_cert->hash)
    {
        AXIS2_FREE(env->allocator, x509_cert->hash);
        x509_cert->hash = NULL;
    }
    x509_cert->hash = (axis2_char_t *)axutil_strdup(env, value);
    return AXIS2_SUCCESS;
}
AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_x509_cert_set_data(oxs_x509_cert_t *x509_cert,
                       const axutil_env_t *env,
                       axis2_char_t *value)
{
    if(x509_cert->data)
    {
        AXIS2_FREE(env->allocator, x509_cert->data);
        x509_cert->data = NULL;
    }
    x509_cert->data = (axis2_char_t *)axutil_strdup(env, value);
    return AXIS2_SUCCESS;
}
AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_x509_cert_set_public_key(oxs_x509_cert_t *x509_cert,
                             const axutil_env_t *env,
                             openssl_pkey_t *public_key)
{
    if(x509_cert->public_key)
    {
        AXIS2_FREE(env->allocator, x509_cert->public_key);
        x509_cert->public_key = NULL;
    }
    x509_cert->public_key = public_key;
    return AXIS2_SUCCESS;
}

