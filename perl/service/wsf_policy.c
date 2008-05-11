/*
 * Copyright 2005,2007 WSO2, Inc. http://wso2.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "php.h"
#include <axis2_addr.h>
#include "wsf.h"
#include "wsf_util.h"
#include <axutil_error_default.h>
#include <axutil_log_default.h>
#include <axutil_uuid_gen.h>
#include <axiom_util.h>
#include "wsf_policy.h"
#include <axiom.h>

#include <rampart_context.h>
#include <axis2_key_type.h>
#include <neethi_options.h>
#include <axis2_policy_include.h>
#include <neethi_engine.h>

#define ArrySize 8


int wsf_set_security_policy_options (
    zval * policy_obj,
    zval ** tmp,
    const axutil_env_t * env TSRMLS_DC);

axiom_node_t *wsf_create_policy_node (
    const axutil_env_t * env,
    axiom_node_t * node);


axis2_char_t *AXIS2_CALL wsf_password_provider_function (
    const axutil_env_t * env,
    const axis2_char_t * username,
    void *ctx);

char *wsf_get_rampart_token_value(char *token_ref);




int
wsf_policy_handle_client_security (
    zval * sec_token,
    zval * policy,
    axutil_env_t * env,
    axis2_svc_client_t * svc_client TSRMLS_DC)
{
    axiom_node_t *outgoing_policy_node = NULL;
    axiom_node_t *incoming_policy_node = NULL;
    HashTable *ht = NULL;
    zval *policy_type = NULL;
    zval **tmp_type = NULL;
    int is_multiple_flow = AXIS2_FALSE;

    rampart_context_t *rampart_ctx = NULL;
    tokenProperties_t tmp_rampart_ctx;

    axis2_svc_ctx_t *svc_ctx = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_conf_t *conf = NULL;

    axutil_param_t *security_param = NULL;

    axiom_element_t *root_ele = NULL;
    axis2_desc_t *desc = NULL;
    axis2_policy_include_t *policy_include = NULL;
    axis2_svc_t *svc = NULL;

    neethi_policy_t *neethi_policy = NULL;

    char *policy_xml = NULL;

    {                           /* initialize tmp_rampart_ctx structure */
        tmp_rampart_ctx.certificate = NULL;
        tmp_rampart_ctx.certificateFormat = NULL;
        tmp_rampart_ctx.password = NULL;
        tmp_rampart_ctx.passwordType = NULL;
        tmp_rampart_ctx.pvtKey = NULL;
        tmp_rampart_ctx.receiverCertificate = NULL;
        tmp_rampart_ctx.pvtKeyFormat = NULL;
        tmp_rampart_ctx.user = NULL;
        tmp_rampart_ctx.receiverCertificateFormat = NULL;
        tmp_rampart_ctx.ttl = 0;
        tmp_rampart_ctx.callback_function = NULL;
		
    }
    if (!sec_token && !policy)
        return AXIS2_FAILURE;

    /* if incoming policy and outgoing policy are diffrenet from each
       other */
    if (Z_TYPE_P (policy) == IS_OBJECT) {
        ht = Z_OBJPROP_P (policy);
        if (zend_hash_find (ht, WS_IN_POLICY, sizeof (WS_IN_POLICY),
                (void **) &tmp_type) == SUCCESS) {
            if (Z_TYPE_PP (tmp_type) == IS_ARRAY) {
                policy_type = *tmp_type;
                incoming_policy_node =
                    wsf_do_create_policy (sec_token, policy_type, AXIS2_FAILURE,
                    env TSRMLS_CC);
            }
            if (Z_TYPE_PP (tmp_type) == IS_STRING) {
                policy_xml = Z_STRVAL_PP (tmp_type);
                incoming_policy_node =
                    wsf_util_deserialize_buffer (env, policy_xml);
            }
            policy_type = NULL;
            tmp_type = NULL;
        }
        if (zend_hash_find (ht, WS_OUT_POLICY, sizeof (WS_OUT_POLICY),
                (void *) &tmp_type) == SUCCESS) {
            if (Z_TYPE_PP (tmp_type) == IS_ARRAY) {
                policy_type = *tmp_type;
                outgoing_policy_node =
                    wsf_do_create_policy (sec_token, policy_type, AXIS2_FAILURE,
                    env TSRMLS_CC);
                is_multiple_flow = AXIS2_SUCCESS;
            }
            if (Z_TYPE_PP (tmp_type) == IS_STRING) {
                policy_xml = Z_STRVAL_PP (tmp_type);
                outgoing_policy_node =
                    wsf_util_deserialize_buffer (env, policy_xml);
                is_multiple_flow = AXIS2_SUCCESS;
            }
        }
        if (zend_hash_find (ht, "policy_xml", sizeof ("policy_xml"),
                (void **) & tmp_type) == SUCCESS
            && (Z_TYPE_PP (tmp_type) == IS_STRING)) {
            policy_xml = Z_STRVAL_PP (tmp_type);
            outgoing_policy_node =
                wsf_util_deserialize_buffer (env, policy_xml);
            incoming_policy_node =
                wsf_util_deserialize_buffer (env, policy_xml);
            is_multiple_flow = AXIS2_SUCCESS;
        }
    }
    /* since creating policy xml is the same procedure use one
       function */
    if (Z_TYPE_P (policy) == IS_OBJECT && is_multiple_flow == AXIS2_FALSE) {
        outgoing_policy_node =
            wsf_do_create_policy (sec_token, policy, AXIS2_FAILURE, env TSRMLS_CC);
        incoming_policy_node =
            wsf_do_create_policy (sec_token, policy, AXIS2_FAILURE, env TSRMLS_CC);
    }

    /* get the values from the security token object and keep it in a
       temperary structure */
    tmp_rampart_ctx =
        wsf_set_tmp_rampart_options (tmp_rampart_ctx, sec_token, policy,
        env TSRMLS_CC);

    rampart_ctx = rampart_context_create (env);

    if (incoming_policy_node) {
        if (axiom_node_get_node_type (incoming_policy_node,
                env) == AXIOM_ELEMENT) {
            root_ele =
                (axiom_element_t *)
                axiom_node_get_data_element (incoming_policy_node, env);

            if (root_ele) {
                neethi_policy =
                    neethi_engine_get_policy (env, incoming_policy_node,
                    root_ele);
                if (!neethi_policy) {
                    return AXIS2_FAILURE;
                }
                svc = axis2_svc_client_get_svc (svc_client, env);
                if (!svc) {
                    return AXIS2_FAILURE;
                }
                desc = axis2_svc_get_base (svc, env);
                if (!desc) {
                    return AXIS2_FAILURE;
                }
                policy_include = axis2_desc_get_policy_include (desc, env);
                if (!policy_include) {
                    return AXIS2_FAILURE;
                }
                axis2_policy_include_add_policy_element (policy_include, env,
                    AXIS2_SERVICE_POLICY, neethi_policy);

                svc_ctx = axis2_svc_client_get_svc_ctx (svc_client, env);
                conf_ctx = axis2_svc_ctx_get_conf_ctx (svc_ctx, env);
                conf = axis2_conf_ctx_get_conf (conf_ctx, env);

                wsf_set_options_to_rampart_ctx (rampart_ctx, env,
                    incoming_policy_node, tmp_rampart_ctx);

                security_param =
                    axutil_param_create (env, WS_RAMPART_CONFIGURATION,
                    (void *) rampart_ctx);
                axis2_conf_add_param (conf, env, security_param);
            }
        }
    }

    axis2_svc_client_engage_module (svc_client, env, "rampart");

    /* for testing only ,should be remove later */
    if (outgoing_policy_node) {
        axis2_char_t *om_str_in = NULL;
        axis2_char_t *om_str_out = NULL;

        om_str_out = axiom_node_to_string (outgoing_policy_node, env);
        om_str_in = axiom_node_to_string (incoming_policy_node, env);

        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
            "[wsf_sec_policy]creating rampart client outgoing policy node \n\t %s \n",
            om_str_out);
        om_str_out = NULL;

        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
            "[wsf_sec_policy]creating rampart client incoming policy node \n\t %s \n",
            om_str_in);
        om_str_in = NULL;


    }
    return AXIS2_SUCCESS;
}

int
wsf_policy_handle_server_security (
    zval * sec_token,
    zval * policy,
    axutil_env_t * env,
    axis2_svc_t * svc,
    axis2_conf_t * conf TSRMLS_DC)
{
    axiom_node_t *outgoing_policy_node = NULL;
    axiom_node_t *incoming_policy_node = NULL;
    HashTable *ht = NULL;
    zval *policy_type = NULL;
    zval **tmp_type = NULL;
    int is_multiple_flow = AXIS2_FALSE;

    rampart_context_t *rampart_ctx = NULL;

    tokenProperties_t tmp_rampart_ctx;

    axutil_param_t *security_param = NULL;

    char *policy_xml = NULL;

    axiom_element_t *root_ele = NULL;
    axis2_desc_t *desc = NULL;
    axis2_policy_include_t *policy_include = NULL;

    {                           /* initialize tmp_rampart_ctx structure */
        tmp_rampart_ctx.certificate = NULL;
        tmp_rampart_ctx.certificateFormat = NULL;
        tmp_rampart_ctx.password = NULL;
        tmp_rampart_ctx.passwordType = NULL;
        tmp_rampart_ctx.pvtKey = NULL;
        tmp_rampart_ctx.receiverCertificate = NULL;
        tmp_rampart_ctx.pvtKeyFormat = NULL;
        tmp_rampart_ctx.user = NULL;
        tmp_rampart_ctx.receiverCertificateFormat = NULL;
        tmp_rampart_ctx.ttl = 0;
        tmp_rampart_ctx.callback_function = NULL;
		 
    }

    if (!sec_token && !policy && !svc && !conf)
        return AXIS2_FAILURE;

    /* if incoming policy and outgoing policy are diffrenet from each
       other */
    if (Z_TYPE_P (policy) == IS_OBJECT) {
        ht = Z_OBJPROP_P (policy);
        if (zend_hash_find (ht, WS_IN_POLICY, sizeof (WS_IN_POLICY),
                (void **) &tmp_type) == SUCCESS) {
            if (Z_TYPE_PP (tmp_type) == IS_ARRAY) {
                policy_type = *tmp_type;
                incoming_policy_node =
					wsf_do_create_policy (sec_token, policy_type, AXIS2_SUCCESS,
                    env TSRMLS_CC);
                is_multiple_flow = AXIS2_SUCCESS;
            }
            if (Z_TYPE_PP (tmp_type) == IS_STRING) {
                policy_xml = Z_STRVAL_PP (tmp_type);
                incoming_policy_node =
                    wsf_util_deserialize_buffer (env, policy_xml);
                is_multiple_flow = AXIS2_SUCCESS;
            }
            policy_type = NULL;
            tmp_type = NULL;
        }
        if (zend_hash_find (ht, WS_OUT_POLICY, sizeof (WS_OUT_POLICY),
                (void *) &tmp_type) == SUCCESS) {
            if (Z_TYPE_PP (tmp_type) == IS_ARRAY) {
                policy_type = *tmp_type;
                outgoing_policy_node =
                    wsf_do_create_policy (sec_token, policy_type, AXIS2_SUCCESS,
                    env TSRMLS_CC);
                is_multiple_flow = AXIS2_SUCCESS;
            }
            if (Z_TYPE_PP (tmp_type) == IS_STRING) {
                policy_xml = Z_STRVAL_PP (tmp_type);
                outgoing_policy_node =
                    wsf_util_deserialize_buffer (env, policy_xml);
                is_multiple_flow = AXIS2_SUCCESS;
            }
        }
        if (zend_hash_find (ht, "policy_xml", sizeof ("policy_xml"),
                (void **) & tmp_type) == SUCCESS
            && (Z_TYPE_PP (tmp_type) == IS_STRING)) {
            policy_xml = Z_STRVAL_PP (tmp_type);
            outgoing_policy_node =
                wsf_util_deserialize_buffer (env, policy_xml);
            incoming_policy_node =
                wsf_util_deserialize_buffer (env, policy_xml);
            is_multiple_flow = AXIS2_SUCCESS;
        }

    }
    /* since creating policy xml is the same procedure use one
       function */
    if (Z_TYPE_P (policy) == IS_OBJECT && is_multiple_flow == AXIS2_FALSE) {
        outgoing_policy_node =
            wsf_do_create_policy (sec_token, policy, AXIS2_SUCCESS, env TSRMLS_CC);
        incoming_policy_node =
            wsf_do_create_policy (sec_token, policy, AXIS2_SUCCESS, env TSRMLS_CC);
    }

    /* get the values from the security token object and keep it in a
       temperary structure */

    rampart_ctx = rampart_context_create (env);
    tmp_rampart_ctx =
        wsf_set_tmp_rampart_options (tmp_rampart_ctx, sec_token, policy,
        env TSRMLS_CC);
    wsf_set_options_to_rampart_ctx (rampart_ctx, env, incoming_policy_node,
        tmp_rampart_ctx);

    if (incoming_policy_node) {
        if (axiom_node_get_node_type (incoming_policy_node,
                env) == AXIOM_ELEMENT) {
            root_ele =
                (axiom_element_t *)
                axiom_node_get_data_element (incoming_policy_node, env);
            if (root_ele) {
                neethi_policy_t *neethi_policy = NULL;
                neethi_policy =
                    neethi_engine_get_policy (env, incoming_policy_node,
                    root_ele);
                if (!neethi_policy) {
                    return AXIS2_FAILURE;
                }
                if (!svc) {
                    return AXIS2_FAILURE;
                }
                desc = axis2_svc_get_base (svc, env);
                if (!desc) {
                    return AXIS2_FAILURE;
                }
                policy_include = axis2_desc_get_policy_include (desc, env);
                if (!policy_include) {
                    return AXIS2_FAILURE;
                }
                axis2_policy_include_add_policy_element (policy_include, env,
                    AXIS2_SERVICE_POLICY, neethi_policy);
                security_param =
                    axutil_param_create (env, WS_RAMPART_CONFIGURATION,
                    (void *) rampart_ctx);
                axis2_svc_add_param (svc, env, security_param);

            }
        }
    }

    /** engage module rampart */
    wsf_util_engage_module (conf, "rampart", env, svc);

    if (outgoing_policy_node && incoming_policy_node) {
        axis2_char_t *om_str_in = NULL;
        axis2_char_t *om_str_out = NULL;

        om_str_out = axiom_node_to_string (outgoing_policy_node, env);
        om_str_in = axiom_node_to_string (incoming_policy_node, env);

        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
            "[wsf_sec_policy]creating rampart service outgoing policy node \n\t %s \n",
            om_str_out);
        om_str_out = NULL;

        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
            "[wsf_sec_policy]creating rampart service incoming policy node \n\t %s \n",
            om_str_in);
        om_str_in = NULL;
    }
    return AXIS2_SUCCESS;
}


tokenProperties_t
wsf_set_tmp_rampart_options (
    tokenProperties_t tmp_rampart_ctx,
    zval * sec_token,
    zval * policy,
    axutil_env_t * env TSRMLS_DC)
{
    HashTable *ht_policy = NULL;
    HashTable *ht_token = NULL;
    zval **token_val = NULL;

    if(policy){
        if (Z_TYPE_P (policy) == IS_OBJECT)
            ht_policy = Z_OBJPROP_P (policy);
        else
            ht_policy = Z_ARRVAL_P (policy);
    }

    ht_token = Z_OBJPROP_P (sec_token);
    
    AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                     "[wsf_policy] creating tmp rampart ctx ");
    
    
    if (zend_hash_find (ht_token, WS_TTL, sizeof (WS_TTL),
            (void **) &token_val) == SUCCESS
        && Z_TYPE_PP (token_val) == IS_LONG) {
        tmp_rampart_ctx.ttl = Z_LVAL_PP (token_val);
    }

    if (zend_hash_find (ht_token, WS_USER, sizeof (WS_USER),
            (void **) &token_val) == SUCCESS
        && Z_TYPE_PP (token_val) == IS_STRING) {
        tmp_rampart_ctx.user = Z_STRVAL_PP (token_val);
    }
    if (zend_hash_find (ht_token, WS_CERTIFICATE, sizeof (WS_CERTIFICATE),
            (void **) &token_val) == SUCCESS
        && Z_TYPE_PP (token_val) == IS_STRING) {
        tmp_rampart_ctx.certificate = Z_STRVAL_PP (token_val);
    }
    if (zend_hash_find (ht_token, WS_RECEIVER_CERTIFICATE,
            sizeof (WS_RECEIVER_CERTIFICATE), (void **) &token_val) == SUCCESS
        && Z_TYPE_PP (token_val) == IS_STRING) {
        tmp_rampart_ctx.receiverCertificate = Z_STRVAL_PP (token_val);
    }
    if (zend_hash_find (ht_token, WS_PRIVATE_KEY, sizeof (WS_PRIVATE_KEY),
            (void **) &token_val) == SUCCESS
        && Z_TYPE_PP (token_val) == IS_STRING) {
        tmp_rampart_ctx.pvtKey = Z_STRVAL_PP (token_val);
    }
    if (zend_hash_find (ht_token, WS_PASSWORD_TYPE, sizeof (WS_PASSWORD_TYPE),
            (void **) &token_val) == SUCCESS
        && Z_TYPE_PP (token_val) == IS_STRING) {
        tmp_rampart_ctx.passwordType = Z_STRVAL_PP (token_val);
    }
    if (zend_hash_find (ht_token, WS_PASSWORD, sizeof (WS_PASSWORD),
            (void **) &token_val) == SUCCESS
        && Z_TYPE_PP (token_val) == IS_STRING) {
        tmp_rampart_ctx.password = Z_STRVAL_PP (token_val);
    }
    if (zend_hash_find (ht_token, WS_PASSWORD_CALL_BACK,
            sizeof (WS_PASSWORD_CALL_BACK), (void **) &token_val) == SUCCESS
        && Z_TYPE_PP (token_val) == IS_STRING) {
        tmp_rampart_ctx.callback_function = Z_STRVAL_PP (token_val);
    }
    return tmp_rampart_ctx;
}

int
wsf_set_options_to_rampart_ctx (
    rampart_context_t * x_rampart_ctx,
    axutil_env_t * env,
    axiom_node_t * x_policy_node,
    tokenProperties_t token_ctx)
{

    if (rampart_context_set_prv_key (x_rampart_ctx, env,
            (void *) token_ctx.pvtKey) == AXIS2_SUCCESS)
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
            "[wsf_sec_policy] setting pvt key  ");

    if (rampart_context_set_prv_key_type (x_rampart_ctx, env,
            AXIS2_KEY_TYPE_PEM) == AXIS2_SUCCESS)
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
            "[wsf_sec_policy] setting pvt key format ");

    if (rampart_context_set_certificate (x_rampart_ctx, env,
            (void *) token_ctx.certificate) == AXIS2_SUCCESS)
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
            "[wsf_sec_policy] setting pub key ");

    if (rampart_context_set_certificate_type (x_rampart_ctx, env,
            AXIS2_KEY_TYPE_PEM) == AXIS2_SUCCESS)
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
            "[wsf_sec_policy] setting pub key format ");

    if (rampart_context_set_receiver_certificate (x_rampart_ctx, env,
            (void *) token_ctx.receiverCertificate) == AXIS2_SUCCESS)
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
            "[wsf_sec_policy] setting pub key ");

    if (rampart_context_set_receiver_certificate_type (x_rampart_ctx, env,
            AXIS2_KEY_TYPE_PEM) == AXIS2_SUCCESS)
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
            "[wsf_sec_policy] setting pub key format ");

    if (rampart_context_set_user (x_rampart_ctx, env,
            (axis2_char_t *) token_ctx.user) == AXIS2_SUCCESS)
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
            "[wsf_sec_policy] setting username ");

    if (rampart_context_set_password (x_rampart_ctx, env,
            (axis2_char_t *) token_ctx.password) == AXIS2_SUCCESS)
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
            "[wsf_sec_policy] setting password ");

    if (rampart_context_set_password_type (x_rampart_ctx, env,
            (axis2_char_t *) token_ctx.passwordType) == AXIS2_SUCCESS)
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
            "[wsf_sec_policy] setting passwordType ");

    if (rampart_context_set_ttl (x_rampart_ctx, env,
            token_ctx.ttl) == AXIS2_SUCCESS)
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
            "[wsf_sec_policy]setting ttl value ");

    if (rampart_context_set_pwcb_function (x_rampart_ctx, env,
            wsf_password_provider_function,
            (void *) token_ctx.callback_function) == AXIS2_SUCCESS)
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
            "[wsf_sec_policy]setting callback function");

    return AXIS2_SUCCESS;

}



axiom_node_t *
wsf_do_create_policy (
    zval * sec_token,
    zval * policy,
	axis2_bool_t is_server_side,
    axutil_env_t * env TSRMLS_DC)
{
    neethi_options_t *neethi_options = NULL;
    HashTable *ht_policy = NULL;
    axiom_node_t *return_node = NULL;
    zval **tmp = NULL;
    char *algo_suite = NULL;
    char *token_ref = NULL;
    char *protection_order = NULL;

    if (!policy)
        return NULL;
    if (Z_TYPE_P (policy) == IS_OBJECT)
        ht_policy = Z_OBJPROP_P (policy);
    else
        ht_policy = Z_ARRVAL_P (policy);

    AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
        "[wsf_policy] Creating the policy node");
    neethi_options = neethi_options_create (env);
    if (neethi_options) {
        if (zend_hash_find (ht_policy, WS_TIMESTAMP, sizeof (WS_TIMESTAMP),
                (void **) &tmp) == SUCCESS) {
            if (neethi_options_set_include_timestamp (neethi_options, env,
                    AXIS2_TRUE))
                AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                    "[wsf_sec_policy] timestamp_enabled ");
        }
        if (zend_hash_find (ht_policy, WS_UT, sizeof (WS_UT),
                (void **) &tmp) == SUCCESS) {
            if (neethi_options_set_is_username_token (neethi_options, env,
                    AXIS2_TRUE))
                AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                    "[wsf_sec_policy] token reference_enabled ");
        }
        if (zend_hash_find (ht_policy, WS_ENCRYPT, sizeof (WS_ENCRYPT),
                (void **) &tmp) == SUCCESS) {
            if (neethi_options_set_encrypt_body (neethi_options, env,
                    AXIS2_TRUE))
                AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                    "[wsf_sec_policy] encrypt_enabled ");
        }
        if (zend_hash_find (ht_policy, WS_ALGORITHM, sizeof (WS_ALGORITHM),
                (void **) &tmp) == SUCCESS && tmp != NULL
            && Z_TYPE_PP (tmp) == IS_STRING) {
            algo_suite = Z_STRVAL_PP (tmp);
            if (neethi_options_set_algorithmsuite (neethi_options, env,
                    algo_suite))
                AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                    "[wsf_sec_policy] algorithmSuite_enabled ");
        }
        if (zend_hash_find (ht_policy, WS_SIGN, sizeof (WS_SIGN),
                (void **) &tmp) == SUCCESS) {
            if (neethi_options_set_sign_body (neethi_options, env,
                    AXIS2_TRUE))
                AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                    "[wsf_sec_policy] sign_enabled ");
        }
        if (zend_hash_find (ht_policy, WS_TOKEN_REFERENCE, sizeof (WS_TOKEN_REFERENCE),
                            (void **) &tmp) == SUCCESS && tmp != NULL
            && Z_TYPE_PP (tmp) == IS_STRING) {
            token_ref = wsf_get_rampart_token_value(Z_STRVAL_PP (tmp));
            if (neethi_options_set_keyidentifier (neethi_options, env,
                                                  token_ref))
                AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                                 "[wsf_sec_policy] token_ref_enabled ");
		 if(is_server_side == AXIS2_SUCCESS)
		  neethi_options_set_server_side(neethi_options, env, is_server_side);
        }
        
        if (zend_hash_find (ht_policy, WS_ENCRYPT_SIGNATURE,
                            sizeof (WS_ENCRYPT_SIGNATURE), (void **) &tmp) == SUCCESS) {
            if (neethi_options_set_signature_protection(neethi_options, env,
                                              AXIS2_TRUE))
                AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                                 "[wsf_sec_policy] encrypt_sign_enabled ");
        }

        if (zend_hash_find (ht_policy, WS_PROTECTION_ORDER, 
                            sizeof (WS_PROTECTION_ORDER), (void **) &tmp) == SUCCESS && tmp != NULL
            && Z_TYPE_PP (tmp) == IS_STRING) {
            protection_order = Z_STRVAL_PP (tmp);
            if(strcmp(protection_order, ENCRYPT_BEFORE) == 0){
                 if (neethi_options_set_encrypt_before_sign (neethi_options, env,
                                                       AXIS2_TRUE))
                    AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                                     "[wsf_sec_policy]  encrypt_before_sign_enabled");
            }
            else if(strcmp(protection_order, SIGN_BEFORE) == 0){
                if (neethi_options_set_encrypt_before_sign (neethi_options, env,
                                                            AXIS2_FALSE))
                    AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                                     "[wsf_sec_policy]  sign_before_encrption_enabled");
            }
            else
                php_error_docref (NULL TSRMLS_CC, E_ERROR,
                                  "Wrong option for protection order");
        }
        
    }

    if (neethi_options) {
        return_node = neethi_options_get_root_node (neethi_options, env);
    }
    return return_node;
}

int
wsf_policy_set_policy_options (
    zval * this_ptr,
    zval * property,
    const axutil_env_t * env TSRMLS_DC)
{

    zval **tmp = NULL;

    if (!property)
        return AXIS2_FAILURE;

    if (Z_TYPE_P (property) == IS_ARRAY) {
        HashTable *ht = Z_ARRVAL_P (property);

        if (!ht)
            return AXIS2_FAILURE;
        /* for security policy related things  */
        if (zend_hash_find (ht, "security", sizeof ("security"),
                (void **) & tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_ARRAY) {
            wsf_set_security_policy_options (this_ptr, tmp, env TSRMLS_CC);
            return AXIS2_SUCCESS;
        }
    }
    if (Z_TYPE_P (property) == IS_STRING) {
        add_property_zval (this_ptr, "policy_xml", property);
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
            "[wsf_policy] policy node creating from a file ");
        return AXIS2_SUCCESS;
    }
    return AXIS2_FAILURE;
}

int
wsf_set_security_policy_options (
    zval * policy_obj,
    zval ** sec_options,
    const axutil_env_t * env TSRMLS_DC)
{
    HashTable *ht_sec = NULL;
    zval **sec_prop = NULL;

    if (sec_options == NULL)
        return AXIS2_FAILURE;

    if (Z_TYPE_PP (sec_options) == IS_ARRAY) {

        ht_sec = Z_ARRVAL_PP (sec_options);
        if (!ht_sec)
            return AXIS2_FAILURE;


        if (zend_hash_find (ht_sec, WS_SIGN, sizeof (WS_SIGN),
                (void **) &sec_prop) == SUCCESS
            && (Z_TYPE_PP (sec_prop) == IS_STRING
                || Z_TYPE_PP (sec_prop) == IS_BOOL)) {
            add_property_zval (policy_obj, WS_SIGN, *sec_prop);
            AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                "[wsf_policy] signing is enable ");
        }

        if (zend_hash_find (ht_sec, WS_ENCRYPT, sizeof (WS_ENCRYPT),
                (void **) &sec_prop) == SUCCESS
            && (Z_TYPE_PP (sec_prop) == IS_STRING
                || Z_TYPE_PP (sec_prop) == IS_BOOL)) {
            add_property_zval (policy_obj, WS_ENCRYPT, *sec_prop);
            AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                "[wsf_policy]  encryption is enable ");

        }

        if (zend_hash_find (ht_sec, WS_ALGORITHM, sizeof (WS_ALGORITHM),
                (void **) &sec_prop) == SUCCESS
            && (Z_TYPE_PP (sec_prop) == IS_STRING)) {
            add_property_stringl (policy_obj, WS_ALGORITHM,
                Z_STRVAL_PP (sec_prop), Z_STRLEN_PP (sec_prop), 1);
            AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                "[wsf_policy] algorithmSuite is enable ");

        }

        if (zend_hash_find (ht_sec, WS_LAYOUT, sizeof (WS_LAYOUT),
                (void **) &sec_prop) == SUCCESS
            && (Z_TYPE_PP (sec_prop) == IS_STRING)) {
            add_property_stringl (policy_obj, WS_LAYOUT,
                Z_STRVAL_PP (sec_prop), Z_STRLEN_PP (sec_prop), 1);
            AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                "[wsf_policy] layout is enable ");

        }

        if (zend_hash_find (ht_sec, WS_TIMESTAMP, sizeof (WS_TIMESTAMP),
                (void **) &sec_prop) == SUCCESS
            && (Z_TYPE_PP (sec_prop) == IS_BOOL)) {
            add_property_bool (policy_obj, WS_TIMESTAMP,
                Z_BVAL_PP (sec_prop));
            AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                "[wsf_policy] timestamp is enable ");

        }

        if (zend_hash_find (ht_sec, WS_PROTECTION_ORDER,
                sizeof (WS_PROTECTION_ORDER), (void **) &sec_prop) == SUCCESS
            && (Z_TYPE_PP (sec_prop) == IS_STRING)) {
            add_property_stringl (policy_obj, WS_PROTECTION_ORDER,
                Z_STRVAL_PP (sec_prop), Z_STRLEN_PP (sec_prop), 1);
            AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                "[wsf_policy] protection order is enable ");

        }

        if (zend_hash_find (ht_sec, WS_UT, sizeof (WS_UT),
                (void **) &sec_prop) == SUCCESS
            && (Z_TYPE_PP (sec_prop) == IS_BOOL)) {
            add_property_bool (policy_obj, WS_UT, Z_BVAL_PP (sec_prop));
            AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                "[wsf_policy] UsernameToken is enable ");

        }

        if (zend_hash_find (ht_sec, WS_TOKEN_REFERENCE,
                sizeof (WS_TOKEN_REFERENCE), (void **) &sec_prop) == SUCCESS
            && (Z_TYPE_PP (sec_prop) == IS_STRING)) {
            add_property_stringl (policy_obj, WS_TOKEN_REFERENCE,
                Z_STRVAL_PP (sec_prop), Z_STRLEN_PP (sec_prop), 1);
            AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                "[wsf_policy] token reference  is enable ");

        }

        if (zend_hash_find (ht_sec, WS_PASSWORD_CALL_BACK,
                sizeof (WS_PASSWORD_CALL_BACK),
                (void **) &sec_prop) == SUCCESS
            && Z_TYPE_PP (sec_prop) == IS_STRING) {
            add_property_stringl (policy_obj, WS_PASSWORD_CALL_BACK,
                Z_STRVAL_PP (sec_prop), Z_STRLEN_PP (sec_prop), 1);
            AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                "[wsf_policy] callback is enable");
        }

        if (zend_hash_find (ht_sec, WS_ENCRYPT_SIGNATURE, 
                            sizeof (WS_ENCRYPT_SIGNATURE),(void **) &sec_prop) == SUCCESS
            && (Z_TYPE_PP (sec_prop) == IS_STRING
                || Z_TYPE_PP (sec_prop) == IS_BOOL)) {
            add_property_zval (policy_obj, WS_ENCRYPT_SIGNATURE, *sec_prop);
            AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                             "[wsf_policy] signature encryption is enable ");
        }

        /* if inflow security and outflow security exits in the array */
        if (zend_hash_find (ht_sec, WS_IN_POLICY, sizeof (WS_IN_POLICY),
                (void **) &sec_prop) == SUCCESS) {
            if (Z_TYPE_PP (sec_prop) == IS_ARRAY) {
                add_property_zval (policy_obj, WS_IN_POLICY, *sec_prop);
                wsf_set_security_policy_options (policy_obj, sec_prop,
                    env TSRMLS_CC);
                AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                    "[wsf_policy] in policy array is enable ");
            }
            if (Z_TYPE_PP (sec_prop) == IS_STRING) {
                add_property_stringl (policy_obj, WS_IN_POLICY,
                    Z_STRVAL_PP (sec_prop), Z_STRLEN_PP (sec_prop), 1);
                AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                    "[wsf_policy] in policy xml file is enable ");
            }

        }

        if (zend_hash_find (ht_sec, WS_OUT_POLICY, sizeof (WS_OUT_POLICY),
                (void **) &sec_prop) == SUCCESS) {
            if (Z_TYPE_PP (sec_prop) == IS_ARRAY) {
                add_property_zval (policy_obj, WS_OUT_POLICY, *sec_prop);
                wsf_set_security_policy_options (policy_obj, sec_prop,
                    env TSRMLS_CC);
                AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                    "[wsf_policy] out policy array is enable ");
            }
            if (Z_TYPE_PP (sec_prop) == IS_STRING) {
                add_property_stringl (policy_obj, WS_OUT_POLICY,
                    Z_STRVAL_PP (sec_prop), Z_STRLEN_PP (sec_prop), 1);
                AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                    "[wsf_policy] out policy xml file is enable ");
            }
        }
    }
    return AXIS2_SUCCESS;
}

axis2_char_t *AXIS2_CALL
wsf_password_provider_function (
    const axutil_env_t * env,
    const axis2_char_t * username,
    void *ctx)
{
    zval func, param1, retval;
    zval *params[1];
    char *val = NULL;


    TSRMLS_FETCH ();
    params[0] = &param1;
    ZVAL_STRING (&func, (char *) ctx, 1);
    ZVAL_STRING (params[0], (char *) username, 1);

    if (call_user_function (EG (function_table), (zval **) NULL,
            &func, &retval, 1, params TSRMLS_CC) == SUCCESS) {
        if (Z_TYPE_P (&retval) == IS_STRING && Z_TYPE_P (&retval) != IS_NULL) {
            val = estrdup (Z_STRVAL (retval));
            return val;

        }
    }
    return NULL;
}

char *wsf_get_rampart_token_value(char *token_ref)
{
    if(strcmp(token_ref, ISSUER_SERIAL) == 0)
        return RP_REQUIRE_ISSUER_SERIAL_REFERENCE;
    if(strcmp(token_ref, KEYIDENTIFIER) == 0)
        return RP_REQUIRE_KEY_IDENTIFIRE_REFERENCE;
    if(strcmp(token_ref, EMBEDDEDTOKEN) == 0)
        return RP_REQUIRE_EMBEDDED_TOKEN_REFERENCE;
    if(strcmp(token_ref, THUMBPRINT) == 0)
        return RP_REQUIRE_THUMBPRINT_REFERENCE;
    else
        return NULL;
}
