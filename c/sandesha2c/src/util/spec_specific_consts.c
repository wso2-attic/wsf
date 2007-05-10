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
 
#include <sandesha2_spec_specific_consts.h>
#include <sandesha2_constants.h>
#include <sandesha2_error.h>
#include <axutil_string.h>
#include <axis2_addr.h>

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
sandesha2_spec_specific_consts_get_spec_ver_str(
    const axutil_env_t *env,
    axis2_char_t *ns_val)
{       
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, ns_val, NULL);
    
    if(0 == axutil_strcmp(ns_val, SANDESHA2_SPEC_2005_02_NS_URI))
    {
        return SANDESHA2_SPEC_VERSION_1_0;
    }
    else if(0 == axutil_strcmp(ns_val, SANDESHA2_SPEC_2006_08_NS_URI))
    {
        return SANDESHA2_SPEC_VERSION_1_1;
    }
    else
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_INVALID_NS_URI, 
                        AXIS2_FAILURE);
        return NULL;                                
    }
    return NULL;
}

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
sandesha2_spec_specific_consts_get_rm_ns_val(
    const axutil_env_t *env,
    axis2_char_t *spec_ver)
{
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, spec_ver, NULL);
    if(0 == axutil_strcmp(SANDESHA2_SPEC_VERSION_1_0, spec_ver))
    {
        return SANDESHA2_SPEC_2005_02_NS_URI;
    }
    if(0 == axutil_strcmp(SANDESHA2_SPEC_VERSION_1_1, spec_ver))
    {
        return SANDESHA2_SPEC_2006_08_NS_URI;
    }
    return NULL;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
sandesha2_spec_specific_consts_is_ack_final_allowed(const axutil_env_t *env, 
                        axis2_char_t *rm_spec_ver)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, rm_spec_ver, AXIS2_FAILURE);
    
    if(0 == axutil_strcmp(rm_spec_ver, SANDESHA2_SPEC_VERSION_1_0))
    {
        return AXIS2_FALSE;
    }
    else if(0 == axutil_strcmp(rm_spec_ver, SANDESHA2_SPEC_VERSION_1_1))
    {
        return AXIS2_TRUE;
    }
    else
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_INVALID_SPEC_VERSION, 
                        AXIS2_FAILURE);
        return AXIS2_FALSE;
    }
    return AXIS2_FALSE;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
sandesha2_spec_specific_consts_is_ack_none_allowed(const axutil_env_t *env, 
                        axis2_char_t *rm_spec_ver)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, rm_spec_ver, AXIS2_FAILURE);
    if(0 == axutil_strcmp(rm_spec_ver, SANDESHA2_SPEC_VERSION_1_0))
    {
        return AXIS2_FALSE;
    }
    else if(0 == axutil_strcmp(rm_spec_ver, SANDESHA2_SPEC_VERSION_1_1))
    {
        return AXIS2_TRUE;
    }
    else
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_INVALID_SPEC_VERSION, 
                        AXIS2_FAILURE);
        return AXIS2_FALSE;
    }
    return AXIS2_FALSE;   
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
sandesha2_spec_specific_consts_get_default_spec_version(
        const axutil_env_t *env)
{
    return SANDESHA2_SPEC_VERSION_1_0;
}

axis2_char_t *AXIS2_CALL
sandesha2_spec_specific_consts_get_terminate_seq_action(
        const axutil_env_t *env,
        axis2_char_t *spec_version)
{
    if (0 == axutil_strcmp(SANDESHA2_SPEC_VERSION_1_0, spec_version)) 
        return SANDESHA2_SPEC_2005_02_ACTION_TERMINATE_SEQ;
    else if (0 == axutil_strcmp(SANDESHA2_SPEC_VERSION_1_1, spec_version)) 
        return SANDESHA2_SPEC_2006_08_ACTION_TERMINATE_SEQ;
    else
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_UNKNOWN_SPEC_ERROR_MESSAGE, 
                AXIS2_FAILURE);
    return NULL;
}

axis2_char_t *AXIS2_CALL
sandesha2_spec_specific_consts_get_create_seq_action(
        const axutil_env_t *env,
        axis2_char_t *spec_version)
{
    if (0 == axutil_strcmp(SANDESHA2_SPEC_VERSION_1_0, spec_version)) 
    {
        return SANDESHA2_SPEC_2005_02_ACTION_CREATE_SEQ;
    }
    else if (0 == axutil_strcmp(SANDESHA2_SPEC_VERSION_1_1, spec_version)) 
        return SANDESHA2_SPEC_2006_08_ACTION_CREATE_SEQ;
    else
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_UNKNOWN_SPEC_ERROR_MESSAGE, 
                AXIS2_FAILURE);
    return NULL;
}
	
axis2_char_t *AXIS2_CALL
sandesha2_spec_specific_consts_get_create_seq_res_action(
        const axutil_env_t *env,
        axis2_char_t *spec_version)
{
    if (0 == axutil_strcmp(SANDESHA2_SPEC_VERSION_1_0, spec_version)) 
    {
        return SANDESHA2_SPEC_2005_02_ACTION_CREATE_SEQ_RESPONSE;
    }
    else if (0 == axutil_strcmp(SANDESHA2_SPEC_VERSION_1_1, spec_version)) 
        return SANDESHA2_SPEC_2006_08_ACTION_CREATE_SEQ_RESPONSE;
    else
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_UNKNOWN_SPEC_ERROR_MESSAGE, 
                AXIS2_FAILURE);
    return NULL;
}
	
axis2_char_t *AXIS2_CALL
sandesha2_spec_specific_consts_get_close_seq_action(
        const axutil_env_t *env,
        axis2_char_t *spec_version)
{
    if (0 == axutil_strcmp(SANDESHA2_SPEC_VERSION_1_0, spec_version)) 
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_RM_SPEC_VERSION_DOES_NOT_DEFINE_A_SEQ_CLOSE_ACTION, 
                AXIS2_FAILURE);
        return NULL;
    }
    else if (0 == axutil_strcmp(SANDESHA2_SPEC_VERSION_1_1, spec_version)) 
        return SANDESHA2_SPEC_2006_08_ACTION_CLOSE_SEQ;
    else
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_UNKNOWN_SPEC_ERROR_MESSAGE, 
                AXIS2_FAILURE);
    return NULL;
}
	
axis2_char_t *AXIS2_CALL
sandesha2_spec_specific_consts_get_close_seq_res_action(
        const axutil_env_t *env,
        axis2_char_t *spec_version)
{
    if (0 == axutil_strcmp(SANDESHA2_SPEC_VERSION_1_0, spec_version)) 
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_RM_SPEC_VERSION_DOES_NOT_DEFINE_A_SEQ_CLOSE_ACTION, 
                AXIS2_FAILURE);
        return NULL;
    }
    else if (0 == axutil_strcmp(SANDESHA2_SPEC_VERSION_1_1, spec_version)) 
        return SANDESHA2_SPEC_2006_08_ACTION_CLOSE_SEQ_RESPONSE;
    else
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_UNKNOWN_SPEC_ERROR_MESSAGE, 
                AXIS2_FAILURE);
    return NULL;
}
	

axis2_char_t *AXIS2_CALL
sandesha2_spec_specific_consts_get_ack_req_action(
    const axutil_env_t *env,
    axis2_char_t *spec_version)
{
    if (0 == axutil_strcmp(SANDESHA2_SPEC_VERSION_1_0, spec_version)) 
    {
        AXIS2_ERROR_SET(env->error, 
            SANDESHA2_ERROR_SPEC_VERSION_DOES_NOT_DEFINE_A_ACK_REQUEST_ACTION, 
            AXIS2_FAILURE);
        return NULL;
    }
    else if (0 == axutil_strcmp(SANDESHA2_SPEC_VERSION_1_1, spec_version)) 
        return SANDESHA2_SPEC_2006_08_ACTION_ACK_REQUEST;
    else
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_UNKNOWN_SPEC_ERROR_MESSAGE, 
            AXIS2_FAILURE);
    return NULL;
}
	
AXIS2_EXTERN axis2_char_t* AXIS2_CALL
sandesha2_spec_specific_consts_get_anon_uri(const axutil_env_t *env,
                        axis2_char_t *addr_ns_val)
{
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, addr_ns_val, NULL);
    
    if(0 == axutil_strcmp(AXIS2_WSA_NAMESPACE_SUBMISSION, addr_ns_val))
        return AXIS2_WSA_ANONYMOUS_URL_SUBMISSION;
    else if(0 == axutil_strcmp(AXIS2_WSA_NAMESPACE, addr_ns_val))
        return AXIS2_WSA_ANONYMOUS_URL;
    
    return NULL;
}
	
AXIS2_EXTERN axis2_bool_t AXIS2_CALL
sandesha2_spec_specific_consts_is_seq_closing_allowed(
        const axutil_env_t *env,
        axis2_char_t *spec_version)
{
    if (0 == axutil_strcmp(SANDESHA2_SPEC_VERSION_1_0, spec_version)) 
    {
        return AXIS2_FALSE;
    }
    else if (0 == axutil_strcmp(SANDESHA2_SPEC_VERSION_1_1, spec_version)) 
        return AXIS2_TRUE;
    else
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_UNKNOWN_SPEC_ERROR_MESSAGE, 
                AXIS2_FAILURE);
    return AXIS2_FALSE;
} 

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
sandesha2_spec_specific_consts_get_terminate_seq_soap_action(
        const axutil_env_t *env,
        axis2_char_t *spec_version)
{
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, spec_version, NULL);
    
    if (0 == axutil_strcmp(SANDESHA2_SPEC_VERSION_1_0, spec_version)) 
        return SANDESHA2_SPEC_2005_02_SOAP_ACTION_TERMINATE_SEQ;
    else if (0 == axutil_strcmp(SANDESHA2_SPEC_VERSION_1_1, spec_version)) 
        return SANDESHA2_SPEC_2006_08_SOAP_ACTION_TERMINATE_SEQ;
    else
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_UNKNOWN_SPEC_ERROR_MESSAGE, 
                AXIS2_FAILURE);
    return NULL;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
sandesha2_spec_specific_consts_get_ack_req_soap_action(
        const axutil_env_t *env,
        axis2_char_t *spec_version)
{
    if(0 == axutil_strcmp(SANDESHA2_SPEC_VERSION_1_0, spec_version))
    {
        AXIS2_ERROR_SET(env->error, 
                SANDESHA2_ERROR_SPEC_VERSION_DOES_NOT_DEFINE_A_ACK_REQUEST_SOAP_ACTION, 
                AXIS2_FAILURE);
        return NULL;
    }
    else if(0 == axutil_strcmp(SANDESHA2_SPEC_VERSION_1_1, spec_version))
    {
        return SANDESHA2_SPEC_2006_08_SOAP_ACTION_ACK_REQUEST;
    }
    else
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_UNKNOWN_SPEC_ERROR_MESSAGE, 
                AXIS2_FAILURE);
        return NULL;
    }
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL        
sandesha2_spec_specific_consts_is_term_seq_res_reqd(
    const axutil_env_t *env,
    axis2_char_t *spec_version)
{
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, spec_version, AXIS2_FALSE);
    
    if (0 == axutil_strcmp(SANDESHA2_SPEC_VERSION_1_0, spec_version)) 
        return AXIS2_FALSE;
    else if (0 == axutil_strcmp(SANDESHA2_SPEC_VERSION_1_1, spec_version)) 
        return AXIS2_TRUE;
    else
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_UNKNOWN_SPEC_ERROR_MESSAGE, 
                AXIS2_FAILURE);
                
    return AXIS2_FALSE;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL        
sandesha2_spec_specific_consts_get_teminate_seq_res_action(
        const axutil_env_t *env,
        axis2_char_t *spec_version)
{
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, spec_version, NULL);
    
    if (0 == axutil_strcmp(SANDESHA2_SPEC_VERSION_1_1, spec_version)) 
        return SANDESHA2_SPEC_2006_08_ACTION_TERMINATE_SEQ_RESPONSE;
    else
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_UNKNOWN_SPEC_ERROR_MESSAGE, 
                AXIS2_FAILURE);

    return NULL;
}

axis2_char_t *AXIS2_CALL
sandesha2_spec_specific_consts_get_seq_ack_action(
        const axutil_env_t *env,
        axis2_char_t *spec_version)
{
    if (0 == axutil_strcmp(SANDESHA2_SPEC_VERSION_1_0, spec_version)) 
    {
        return SANDESHA2_SPEC_2005_02_ACTION_SEQ_ACKNOWLEDGEMENT;
    }
    else if (0 == axutil_strcmp(SANDESHA2_SPEC_VERSION_1_1, spec_version)) 
        return SANDESHA2_SPEC_2006_08_ACTION_SEQ_ACKNOWLEDGEMENT;
    else
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_UNKNOWN_SPEC_ERROR_MESSAGE, 
                AXIS2_FAILURE);
    return NULL;
}
	
AXIS2_EXTERN axis2_char_t *AXIS2_CALL
sandesha2_spec_specific_consts_get_seq_ack_soap_action(
    const axutil_env_t *env,
    axis2_char_t *spec_version)
{
    if(0 == axutil_strcmp(SANDESHA2_SPEC_VERSION_1_0, spec_version))
    {
        return SANDESHA2_SPEC_2005_02_SOAP_ACTION_SEQ_ACKNOWLEDGEMENT;
    }
    else if(0 == axutil_strcmp(SANDESHA2_SPEC_VERSION_1_1, spec_version))
    {
        return SANDESHA2_SPEC_2006_08_SOAP_ACTION_SEQ_ACKNOWLEDGEMENT;
    }
    else
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_UNKNOWN_SPEC_ERROR_MESSAGE, 
                AXIS2_FAILURE);
        return NULL;
    }
}

axis2_char_t *AXIS2_CALL
sandesha2_spec_specific_consts_get_make_connection_action(
    const axutil_env_t *env,
    axis2_char_t *spec_version)
{
    if (0 == axutil_strcmp(SANDESHA2_SPEC_VERSION_1_0, spec_version)) 
    {
        AXIS2_ERROR_SET(env->error, 
            SANDESHA2_ERROR_MAKE_CONNECTION_IS_NOT_SUPPORTED_IN_THIS_RM_VERSION, 
                AXIS2_FAILURE);
    }
    else if (0 == axutil_strcmp(SANDESHA2_SPEC_VERSION_1_1, spec_version)) 
        return SANDESHA2_SPEC_2006_08_ACTION_MAKE_CONNECTION;
    else
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_UNKNOWN_SPEC_ERROR_MESSAGE, 
                AXIS2_FAILURE);
    return NULL;
}

axis2_bool_t AXIS2_CALL
sandesha2_spec_specific_consts_is_last_msg_indicator_reqd(
    const axutil_env_t *env,
    axis2_char_t *spec_version)
{
    if (0 == axutil_strcmp(SANDESHA2_SPEC_VERSION_1_0, spec_version)) 
    {
        return AXIS2_TRUE;
    }
    else if (0 == axutil_strcmp(SANDESHA2_SPEC_VERSION_1_1, spec_version)) 
        return AXIS2_FALSE;
    else
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_UNKNOWN_SPEC_ERROR_MESSAGE, 
                AXIS2_FAILURE);
    return AXIS2_FALSE;
}
	

