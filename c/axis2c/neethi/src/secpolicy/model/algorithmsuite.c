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


#include <rp_algorithmsuite.h>

struct rp_algorithmsuite_t
{
    axis2_char_t *algosuite_string;
    axis2_char_t *symmetric_signature;
    axis2_char_t *asymmetric_signature;
    axis2_char_t *computed_key;
    int max_symmetric_keylength;
    int min_asymmetric_keylength;
    int max_asymmetric_keylength;
    axis2_char_t *digest;
    axis2_char_t *encryption;
    axis2_char_t *symmetrickeywrap;
    axis2_char_t *asymmetrickeywrap;
    axis2_char_t *encryption_key_derivation;
    axis2_char_t *signature_key_derivation;
    int min_symmetric_keylength;
    axis2_char_t *c14n;
    axis2_char_t *soap_normalization;
    axis2_char_t *str_transformation;
    axis2_char_t *xpath;
    int ref;

};

AXIS2_EXTERN rp_algorithmsuite_t *AXIS2_CALL 
rp_algorithmsuite_create(const axutil_env_t *env)
{
    rp_algorithmsuite_t *algorithmsuite = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    algorithmsuite =  (rp_algorithmsuite_t *) AXIS2_MALLOC (env->allocator,
    sizeof (rp_algorithmsuite_t));

    if(algorithmsuite == NULL)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    algorithmsuite->algosuite_string = NULL;
    algorithmsuite->symmetric_signature = RP_HMAC_SHA1;
    algorithmsuite->asymmetric_signature = RP_RSA_SHA1;
    algorithmsuite->computed_key = RP_P_SHA1;
    algorithmsuite->max_symmetric_keylength = 256;
    algorithmsuite->min_asymmetric_keylength = 1024;
    algorithmsuite->max_asymmetric_keylength = 4096;
    algorithmsuite->digest = NULL;
    algorithmsuite->encryption = NULL;
    algorithmsuite->symmetrickeywrap = NULL;
    algorithmsuite->asymmetrickeywrap = NULL;
    algorithmsuite->encryption_key_derivation = NULL;
    algorithmsuite->signature_key_derivation = NULL;
    algorithmsuite->min_symmetric_keylength = 0;;
    algorithmsuite->c14n = RP_EX_C14N;
    algorithmsuite->soap_normalization = NULL;
    algorithmsuite->str_transformation = NULL;
    algorithmsuite->xpath = NULL;
    algorithmsuite->ref = 0;
    return algorithmsuite;
}

AXIS2_EXTERN void AXIS2_CALL 
rp_algorithmsuite_free(rp_algorithmsuite_t *algorithmsuite,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
        
    if(algorithmsuite)
    {
        if (--(algorithmsuite->ref) > 0)
        {
            return;
        }
        
        AXIS2_FREE(env->allocator, algorithmsuite);
        algorithmsuite = NULL;
    }
    return;
}


/* Implementations */

AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
rp_algorithmsuite_get_algosuite_string(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    if(!algorithmsuite)
        return NULL;
    else
        return algorithmsuite->algosuite_string;
    
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_algorithmsuite_set_algosuite(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env,
            axis2_char_t *algosuite_string)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,algosuite_string,AXIS2_FAILURE);   
 
    algorithmsuite->algosuite_string = algosuite_string;

    if(axutil_strcmp(algosuite_string,RP_ALGO_SUITE_BASIC256)==0)
    {
        algorithmsuite->digest = RP_SHA1;
        algorithmsuite->encryption = RP_AES256;
        algorithmsuite->symmetrickeywrap = RP_KW_AES256;
        algorithmsuite->asymmetrickeywrap = RP_KW_RSA_OAEP;
        algorithmsuite->encryption_key_derivation = RP_P_SHA1_L256;
        algorithmsuite->signature_key_derivation = RP_P_SHA1_L192;
        algorithmsuite->min_symmetric_keylength = 256;

        return AXIS2_SUCCESS;
    }
    else if(axutil_strcmp(algosuite_string,RP_ALGO_SUITE_BASIC192)==0)
    {
        algorithmsuite->digest = RP_SHA1;
        algorithmsuite->encryption = RP_AES192;
        algorithmsuite->symmetrickeywrap = RP_KW_AES192;
        algorithmsuite->asymmetrickeywrap = RP_KW_RSA_OAEP;
        algorithmsuite->encryption_key_derivation = RP_P_SHA1_L192;
        algorithmsuite->signature_key_derivation = RP_P_SHA1_L192;
        algorithmsuite->min_symmetric_keylength = 192;

        return AXIS2_SUCCESS;
    }        
    else if(axutil_strcmp(algosuite_string,RP_ALGO_SUITE_BASIC128)==0)
    {
        algorithmsuite->digest = RP_SHA1;
        algorithmsuite->encryption = RP_AES128;
        algorithmsuite->symmetrickeywrap = RP_KW_AES128;
        algorithmsuite->asymmetrickeywrap = RP_KW_RSA_OAEP;
        algorithmsuite->encryption_key_derivation = RP_P_SHA1_L128;
        algorithmsuite->signature_key_derivation = RP_P_SHA1_L128;
        algorithmsuite->min_symmetric_keylength = 128;

        return AXIS2_SUCCESS;
    }
    else if(axutil_strcmp(algosuite_string,RP_ALGO_SUITE_TRIPLE_DES)==0)
    {
        algorithmsuite->digest = RP_SHA1;
        algorithmsuite->encryption = RP_TRIPLE_DES;
        algorithmsuite->symmetrickeywrap = RP_KW_TRIPLE_DES;
        algorithmsuite->asymmetrickeywrap = RP_KW_RSA_OAEP;
        algorithmsuite->encryption_key_derivation = RP_P_SHA1_L192;
        algorithmsuite->signature_key_derivation = RP_P_SHA1_L192;
        algorithmsuite->min_symmetric_keylength = 192;

        return AXIS2_SUCCESS;
    }
    else if(axutil_strcmp(algosuite_string,RP_ALGO_SUITE_BASIC256_RSA15)==0)
    {
        algorithmsuite->digest = RP_SHA1;
        algorithmsuite->encryption = RP_AES256;
        algorithmsuite->symmetrickeywrap = RP_KW_AES256;
        algorithmsuite->asymmetrickeywrap = RP_KW_RSA15;
        algorithmsuite->encryption_key_derivation = RP_P_SHA1_L256;
        algorithmsuite->signature_key_derivation = RP_P_SHA1_L192;
        algorithmsuite->min_symmetric_keylength = 256;

        return AXIS2_SUCCESS;
    }
    else if(axutil_strcmp(algosuite_string,RP_ALGO_SUITE_BASIC192_RSA15)==0)
    {
        algorithmsuite->digest = RP_SHA1;
        algorithmsuite->encryption = RP_AES192;
        algorithmsuite->symmetrickeywrap = RP_KW_AES192;
        algorithmsuite->asymmetrickeywrap = RP_KW_RSA15;
        algorithmsuite->encryption_key_derivation = RP_P_SHA1_L192;
        algorithmsuite->signature_key_derivation = RP_P_SHA1_L192;
        algorithmsuite->min_symmetric_keylength = 192;

        return AXIS2_SUCCESS;
    }
    else if(axutil_strcmp(algosuite_string,RP_ALGO_SUITE_BASIC128_RSA15)==0)
    {
        algorithmsuite->digest = RP_SHA1;
        algorithmsuite->encryption = RP_AES128;
        algorithmsuite->symmetrickeywrap = RP_KW_AES128;
        algorithmsuite->asymmetrickeywrap = RP_KW_RSA15;
        algorithmsuite->encryption_key_derivation = RP_P_SHA1_L128;
        algorithmsuite->signature_key_derivation = RP_P_SHA1_L128;
        algorithmsuite->min_symmetric_keylength = 128;

        return AXIS2_SUCCESS;
    }
    else if(axutil_strcmp(algosuite_string,RP_ALGO_SUITE_TRIPLE_DES_RSA15)==0)
    {
        algorithmsuite->digest = RP_SHA1;
        algorithmsuite->encryption = RP_TRIPLE_DES;
        algorithmsuite->symmetrickeywrap = RP_KW_TRIPLE_DES;
        algorithmsuite->asymmetrickeywrap = RP_KW_RSA15;
        algorithmsuite->encryption_key_derivation = RP_P_SHA1_L192;
        algorithmsuite->signature_key_derivation = RP_P_SHA1_L192;
        algorithmsuite->min_symmetric_keylength = 192;

        return AXIS2_SUCCESS;
    }
    else if(axutil_strcmp(algosuite_string,RP_ALGO_SUITE_BASIC256_SHA256)==0)
    {
        algorithmsuite->digest = RP_SHA256;
        algorithmsuite->encryption = RP_AES256;
        algorithmsuite->symmetrickeywrap = RP_KW_AES256;
        algorithmsuite->asymmetrickeywrap = RP_KW_RSA_OAEP;
        algorithmsuite->encryption_key_derivation = RP_P_SHA1_L256;
        algorithmsuite->signature_key_derivation = RP_P_SHA1_L192;
        algorithmsuite->min_symmetric_keylength = 256;

        return AXIS2_SUCCESS;
    }
    else if(axutil_strcmp(algosuite_string,RP_ALGO_SUITE_BASIC192_SHA256)==0)
    {
        algorithmsuite->digest = RP_SHA256;
        algorithmsuite->encryption = RP_AES192;
        algorithmsuite->symmetrickeywrap = RP_KW_AES192;
        algorithmsuite->asymmetrickeywrap = RP_KW_RSA_OAEP;
        algorithmsuite->encryption_key_derivation = RP_P_SHA1_L192;
        algorithmsuite->signature_key_derivation = RP_P_SHA1_L192;
        algorithmsuite->min_symmetric_keylength = 192;

        return AXIS2_SUCCESS;
    }
    else if(axutil_strcmp(algosuite_string,RP_ALGO_SUITE_BASIC128_SHA256)==0)
    {
        algorithmsuite->digest = RP_SHA256;
        algorithmsuite->encryption = RP_AES128;
        algorithmsuite->symmetrickeywrap = RP_KW_AES128;
        algorithmsuite->asymmetrickeywrap = RP_KW_RSA_OAEP;
        algorithmsuite->encryption_key_derivation = RP_P_SHA1_L128;
        algorithmsuite->signature_key_derivation = RP_P_SHA1_L128;
        algorithmsuite->min_symmetric_keylength = 128;

        return AXIS2_SUCCESS;
    }
    else if(axutil_strcmp(algosuite_string,RP_ALGO_SUITE_TRIPLE_DES_SHA256)==0)
    {
        algorithmsuite->digest = RP_SHA256;
        algorithmsuite->encryption = RP_TRIPLE_DES;
        algorithmsuite->symmetrickeywrap = RP_KW_TRIPLE_DES;
        algorithmsuite->asymmetrickeywrap = RP_KW_RSA_OAEP;
        algorithmsuite->encryption_key_derivation = RP_P_SHA1_L192;
        algorithmsuite->signature_key_derivation = RP_P_SHA1_L192;
        algorithmsuite->min_symmetric_keylength = 192;

        return AXIS2_SUCCESS;
    }
    else if(axutil_strcmp(algosuite_string,RP_ALGO_SUITE_BASIC256_SHA256_RSA15)==0)
    {
        algorithmsuite->digest = RP_SHA256;
        algorithmsuite->encryption = RP_AES256;
        algorithmsuite->symmetrickeywrap = RP_KW_AES256;
        algorithmsuite->asymmetrickeywrap = RP_KW_RSA15;
        algorithmsuite->encryption_key_derivation = RP_P_SHA1_L256;
        algorithmsuite->signature_key_derivation = RP_P_SHA1_L192;
        algorithmsuite->min_symmetric_keylength = 256;

        return AXIS2_SUCCESS;
    }
    else if(axutil_strcmp(algosuite_string,RP_ALGO_SUITE_BASIC192_SHA256_RSA15)==0)
    {
        algorithmsuite->digest = RP_SHA256;
        algorithmsuite->encryption = RP_AES192;
        algorithmsuite->symmetrickeywrap = RP_KW_AES192;
        algorithmsuite->asymmetrickeywrap = RP_KW_RSA15;
        algorithmsuite->encryption_key_derivation = RP_P_SHA1_L192;
        algorithmsuite->signature_key_derivation = RP_P_SHA1_L192;
        algorithmsuite->min_symmetric_keylength = 192;

        return AXIS2_SUCCESS;
    }
    else if(axutil_strcmp(algosuite_string,RP_ALGO_SUITE_BASIC128_SHA256_RSA15)==0)
    {
        algorithmsuite->digest = RP_SHA256;
        algorithmsuite->encryption = RP_AES128;
        algorithmsuite->symmetrickeywrap = RP_KW_AES128;
        algorithmsuite->asymmetrickeywrap = RP_KW_RSA15;
        algorithmsuite->encryption_key_derivation = RP_P_SHA1_L128;
        algorithmsuite->signature_key_derivation = RP_P_SHA1_L128;
        algorithmsuite->min_symmetric_keylength = 128;

        return AXIS2_SUCCESS;
    }
    else if(axutil_strcmp(algosuite_string,RP_ALGO_SUITE_TRIPLE_DES_SHA256_RSA15)==0)
    {
        algorithmsuite->digest = RP_SHA256;
        algorithmsuite->encryption = RP_TRIPLE_DES;
        algorithmsuite->symmetrickeywrap = RP_KW_TRIPLE_DES;
        algorithmsuite->asymmetrickeywrap = RP_KW_RSA15;
        algorithmsuite->encryption_key_derivation = RP_P_SHA1_L192;
        algorithmsuite->signature_key_derivation = RP_P_SHA1_L192;
        algorithmsuite->min_symmetric_keylength = 192;

        return AXIS2_SUCCESS;
    }
    else
        return AXIS2_FAILURE;
}


AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
rp_algorithmsuite_get_symmetric_signature(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return algorithmsuite->symmetric_signature;
    
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_algorithmsuite_set_symmetric_signature(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env,
            axis2_char_t *symmetric_signature)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,symmetric_signature,AXIS2_FAILURE);
    
    algorithmsuite->symmetric_signature = symmetric_signature;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
rp_algorithmsuite_get_asymmetric_signature(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return algorithmsuite->asymmetric_signature;
    
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_algorithmsuite_set_asymmetric_signature(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env,
            axis2_char_t *asymmetric_signature)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,asymmetric_signature,AXIS2_FAILURE);
    
    algorithmsuite->asymmetric_signature = asymmetric_signature;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
rp_algorithmsuite_get_computed_key(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return algorithmsuite->computed_key;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_algorithmsuite_set_computed_key(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env,
            axis2_char_t *computed_key)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,computed_key,AXIS2_FAILURE);    
    
    algorithmsuite->computed_key = computed_key;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
rp_algorithmsuite_get_digest(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return algorithmsuite->digest;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
rp_algorithmsuite_get_encryption(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    return algorithmsuite->encryption;
}

AXIS2_EXTERN int AXIS2_CALL 
rp_algorithmsuite_get_max_symmetric_keylength(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return algorithmsuite->max_symmetric_keylength;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_algorithmsuite_set_max_symmetric_keylength(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env,
            int max_symmetric_keylength)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    algorithmsuite->max_symmetric_keylength = max_symmetric_keylength;

    return AXIS2_SUCCESS;
    
}

AXIS2_EXTERN int AXIS2_CALL 
rp_algorithmsuite_get_min_symmetric_keylength(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return algorithmsuite->min_symmetric_keylength;
}

AXIS2_EXTERN int AXIS2_CALL 
rp_algorithmsuite_get_max_asymmetric_keylength(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return algorithmsuite->max_asymmetric_keylength;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_algorithmsuite_set_max_asymmetric_keylength(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env,
            int max_asymmetric_keylength)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
        
    algorithmsuite->max_asymmetric_keylength = max_asymmetric_keylength;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN int AXIS2_CALL 
rp_algorithmsuite_get_min_asymmetric_keylength(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return algorithmsuite->min_asymmetric_keylength;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_algorithmsuite_set_min_asymmetric_keylength(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env,
            int min_asymmetric_keylength)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    algorithmsuite->min_asymmetric_keylength = min_asymmetric_keylength;
    return AXIS2_SUCCESS;
    
}


AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
rp_algorithmsuite_get_symmetrickeywrap(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return algorithmsuite->symmetrickeywrap;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
rp_algorithmsuite_get_asymmetrickeywrap(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return algorithmsuite->asymmetrickeywrap;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
rp_algorithmsuite_get_signature_key_derivation(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return algorithmsuite->signature_key_derivation;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
rp_algorithmsuite_get_encryption_key_derivation(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
        
    return algorithmsuite->encryption_key_derivation;
    
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
rp_algorithmsuite_get_soap_normalization(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return algorithmsuite->soap_normalization;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_algorithmsuite_set_soap_normalization(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env,
            axis2_char_t *soap_normalization)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,soap_normalization,AXIS2_FAILURE);    
    
    algorithmsuite->soap_normalization = soap_normalization;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
rp_algorithmsuite_get_str_transformation(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return algorithmsuite->str_transformation;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_algorithmsuite_set_str_transformation(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env,
            axis2_char_t *str_transformation)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,str_transformation,AXIS2_FAILURE);    
    
    algorithmsuite->str_transformation = str_transformation;

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
rp_algorithmsuite_get_c14n(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return algorithmsuite->c14n;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_algorithmsuite_set_c14n(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env,
            axis2_char_t *c14n)
{
        AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
        AXIS2_PARAM_CHECK(env->error,c14n,AXIS2_FAILURE);   
 
    algorithmsuite->c14n = c14n;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
rp_algorithmsuite_get_xpath(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
        
    return algorithmsuite->xpath;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_algorithmsuite_set_xpath(rp_algorithmsuite_t *algorithmsuite,
            const axutil_env_t *env,
            axis2_char_t *xpath)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,xpath,AXIS2_FAILURE);
    
    algorithmsuite->xpath = xpath;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rp_algorithmsuite_increment_ref(rp_algorithmsuite_t *algorithmsuite,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    algorithmsuite->ref++;
    return AXIS2_SUCCESS;
}

