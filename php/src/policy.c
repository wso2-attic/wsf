/*
 * Copyright 2005,2006 WSO2, Inc. http://wso2.com
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
#include <axis2_error_default.h>
#include <axis2_log_default.h>
#include <axis2_uuid_gen.h>
#include <axiom_util.h>
#include "wsf_policy.h"
#include <axiom.h>

#include <rampart_context.h>

#define ArrySize 8


int set_security_policy_options(zval *policy_obj,
                                zval **tmp,
                                const axis2_env_t *env TSRMLS_DC);

axiom_node_t *
create_policy_node(const axis2_env_t *env,
                   axiom_node_t *node );

axiom_node_t *
create_initiator_token(const axis2_env_t *env,
                       axiom_node_t *node,
                       zval **optionVal TSRMLS_DC);

axiom_node_t *
create_recipient_token(const axis2_env_t *env,
                       axiom_node_t *node,
                       zval **optionVal TSRMLS_DC);

axiom_node_t*
create_algorithm_suite(const axis2_env_t *env,
                       axiom_node_t *node,
                       zval **optionVal TSRMLS_DC);

axiom_node_t *
create_sign_parts(const axis2_env_t *env,
                  axiom_node_t *parent_node,
                  zval **tmp TSRMLS_DC);

axiom_node_t *
create_encrypt_parts(const axis2_env_t *env,
                     axiom_node_t *parent_node,
                     zval **tmp TSRMLS_DC);

axiom_node_t *
create_layout(const axis2_env_t *env,
              axiom_node_t *node,
              zval **optionVal TSRMLS_DC);

axiom_node_t *
create_default_sign(const axis2_env_t *env,
                    axiom_node_t *node TSRMLS_DC);

axiom_node_t *
create_default_encrypt(const axis2_env_t *env,
                       axiom_node_t *node);

axiom_node_t *
create_username_token(const axis2_env_t *env,
                      axiom_node_t *parent_node,
                      zval **tmp TSRMLS_DC);

axiom_node_t *
create_token_reference(const axis2_env_t *env,
                       axiom_node_t *parent_node,
                       zval **tmp TSRMLS_DC);


char * algorithmArry[ArrySize]={
                                   BASIC256, BASIC192, BASIC128,
                                   TRIPLEDES, BASIC256_RSA15, BASIC192_RSA15,
                                   BASIC128_RSA15, TRIPLEDES_RSA15
                               };

typedef struct tokenProperties {
    char *user;
    char *publicKey;
    char *passwordType;
    char *password;
    char *pvtkey;
    char *publicKeyFormat;
    char *pvtKeyFormat;
    int ttl;
}
tokenProperties_t;


tokenProperties_t set_tmp_rampart_options(tokenProperties_t tmp_rampart_ctx,
        zval *sec_token,
        zval *policy,
        axis2_env_t *env TSRMLS_DC);

int set_options_to_rampart_ctx(rampart_context_t *in_rampart_ctx,
                               axis2_env_t *env,
                               axiom_node_t *incoming_policy_node,
                               tokenProperties_t tmp_rampart_ctx);


axiom_node_t *do_create_policy(zval *sec_token,
                               zval *policy,
                               axis2_env_t *env TSRMLS_DC);


int ws_policy_handle_client_security(zval *sec_token,
                                     zval *policy,
                                     axis2_env_t *env,
                                     axis2_svc_client_t *svc_client,
                                     axis2_options_t *options TSRMLS_DC) {

    axiom_node_t *outgoing_policy_node = NULL;
    axiom_node_t *incoming_policy_node = NULL;
    HashTable *ht = NULL;
    zval *policy_type = NULL;
    zval **tmp_type = NULL;
    int is_multiple_flow = AXIS2_FALSE;

    rampart_context_t *in_rampart_ctx = NULL;
    rampart_context_t *out_rampart_ctx = NULL;

    tokenProperties_t tmp_rampart_ctx;
    axis2_svc_ctx_t *svc_ctx = NULL;
    axis2_svc_t *svc = NULL;
    axis2_param_t *inflow_param = NULL;
    axis2_param_t *outflow_param = NULL;


    if (!sec_token && !policy)
        return AXIS2_FAILURE;

    /* if incoming policy and outgoing policy are diffrenet from each
       other */
    if ( Z_TYPE_P(policy) == IS_OBJECT) {
        ht = Z_OBJPROP_P(policy);
        if (zend_hash_find(ht, WS_IN_POLICY, sizeof(WS_IN_POLICY), (void **)&tmp_type) == SUCCESS &&
                (Z_TYPE_PP(tmp_type) == IS_ARRAY )) {
            policy_type = *tmp_type;
            incoming_policy_node = do_create_policy(sec_token, policy_type, env TSRMLS_CC);
            policy_type = NULL;
            tmp_type = NULL;
        }
        if (zend_hash_find(ht, WS_OUT_POLICY, sizeof(WS_OUT_POLICY), (void *)&tmp_type) == SUCCESS &&
                (Z_TYPE_PP(tmp_type) == IS_ARRAY )) {
            policy_type = *tmp_type;
            outgoing_policy_node = do_create_policy(sec_token, policy_type, env TSRMLS_CC);
        }
        is_multiple_flow = AXIS2_SUCCESS;
    }
    /* since creating policy xml is the same procedure use one
       function */
    if ( Z_TYPE_P(policy) == IS_OBJECT && is_multiple_flow == AXIS2_FALSE) {
        outgoing_policy_node = do_create_policy(sec_token, policy, env TSRMLS_CC);
        incoming_policy_node = outgoing_policy_node;
    }

    /* get the values from the security token object and keep it in a
       temperary structure */
    tmp_rampart_ctx = set_tmp_rampart_options(tmp_rampart_ctx, sec_token, policy, env TSRMLS_CC);

    in_rampart_ctx = rampart_context_create(env);
    out_rampart_ctx = rampart_context_create(env);

    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy]setting values for in_rampart_ctx... ");
    set_options_to_rampart_ctx(in_rampart_ctx, env, incoming_policy_node, tmp_rampart_ctx);

    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy]setting values for out_rampart_ctx... ");
    set_options_to_rampart_ctx(out_rampart_ctx, env, outgoing_policy_node, tmp_rampart_ctx);

    svc_ctx = AXIS2_SVC_CLIENT_GET_SVC_CTX(svc_client, env);
    svc = AXIS2_SVC_CTX_GET_SVC(svc_ctx, env);

    inflow_param = axis2_param_create(env, WS_INFLOW_SECURITY_POLICY, (void *)in_rampart_ctx) ;
    outflow_param = axis2_param_create(env, WS_OUTFLOW_SECURITY_POLICY, (void *)out_rampart_ctx);

    AXIS2_SVC_ADD_PARAM(svc, env, inflow_param);
    AXIS2_SVC_ADD_PARAM(svc, env, outflow_param);

    AXIS2_SVC_CLIENT_ENGAGE_MODULE(svc_client, env, "rampart");

    /* for testing only ,should be remove later */
    if (outgoing_policy_node) {
        FILE *fp = NULL;
        axis2_char_t *om_str_in = NULL;
        axis2_char_t *om_str_out = NULL;

        om_str_out = AXIOM_NODE_TO_STRING(outgoing_policy_node, env);
        om_str_in = AXIOM_NODE_TO_STRING(incoming_policy_node, env);
        if (om_str_in && om_str_out) {
            fp = fopen("/tmp/outgoing_policy.xml", "w");
            fprintf(fp, "%s", om_str_out );
            om_str_out = NULL;
            fp = fopen("/tmp/incoming_policy.xml", "w");
            fprintf(fp, "%s", om_str_in );
            om_str_in = NULL;

        }
    }
    return AXIS2_SUCCESS;
}

int ws_policy_handle_server_security(zval *sec_token,
                                     zval *policy,
                                     axis2_env_t *env,
                                     axis2_options_t *options TSRMLS_DC) {
    axiom_node_t *outgoing_policy_node = NULL;
    axiom_node_t *incoming_policy_node = NULL;
    HashTable *ht = NULL;
    zval *policy_type = NULL;
    zval **tmp_type = NULL;
    int is_multiple_flow = AXIS2_FALSE;

    rampart_context_t *in_rampart_ctx = NULL;
    rampart_context_t *out_rampart_ctx = NULL;

    tokenProperties_t tmp_rampart_ctx;


    if (!sec_token && !policy)
        return AXIS2_FAILURE;

    /* if incoming policy and outgoing policy are diffrenet from each
       other */
    if ( Z_TYPE_P(policy) == IS_OBJECT) {
        ht = Z_OBJPROP_P(policy);
        if (zend_hash_find(ht, WS_IN_POLICY, sizeof(WS_IN_POLICY), (void **)&tmp_type) == SUCCESS &&
                (Z_TYPE_PP(tmp_type) == IS_ARRAY )) {
            policy_type = *tmp_type;
            incoming_policy_node = do_create_policy(sec_token, policy_type, env TSRMLS_CC);
            policy_type = NULL;
            tmp_type = NULL;
        }
        if (zend_hash_find(ht, WS_OUT_POLICY, sizeof(WS_OUT_POLICY), (void *)&tmp_type) == SUCCESS &&
                (Z_TYPE_PP(tmp_type) == IS_ARRAY )) {
            policy_type = *tmp_type;
            outgoing_policy_node = do_create_policy(sec_token, policy_type, env TSRMLS_CC);
        }
        is_multiple_flow = AXIS2_SUCCESS;
    }
    /* since creating policy xml is the same procedure use one
       function */
    if ( Z_TYPE_P(policy) == IS_OBJECT && is_multiple_flow == AXIS2_FALSE) {
        outgoing_policy_node = do_create_policy(sec_token, policy, env TSRMLS_CC);
        incoming_policy_node = outgoing_policy_node;
    }

    /* get the values from the security token object and keep it in a
       temperary structure */
    tmp_rampart_ctx = set_tmp_rampart_options(tmp_rampart_ctx, sec_token, policy, env TSRMLS_CC);

    in_rampart_ctx = rampart_context_create(env);
    out_rampart_ctx = rampart_context_create(env);

    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy]setting values for in_rampart_ctx... ");
    set_options_to_rampart_ctx(in_rampart_ctx, env, incoming_policy_node, tmp_rampart_ctx);

    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy]setting values for out_rampart_ctx... ");
    set_options_to_rampart_ctx(out_rampart_ctx, env, outgoing_policy_node, tmp_rampart_ctx);


    /* for testing only ,should be remove later */
    if (outgoing_policy_node) {
        FILE *fp = NULL;
        axis2_char_t *om_str_in = NULL;
        axis2_char_t *om_str_out = NULL;

        om_str_out = AXIOM_NODE_TO_STRING(outgoing_policy_node, env);
        om_str_in = AXIOM_NODE_TO_STRING(incoming_policy_node, env);
        if (om_str_in && om_str_out) {
            fp = fopen("/tmp/outgoing_policy.xml", "w");
            fprintf(fp, "%s", om_str_out );
            om_str_out = NULL;
            fp = fopen("/tmp/incoming_policy.xml", "w");
            fprintf(fp, "%s", om_str_in );
            om_str_in = NULL;

        }
    }

    return AXIS2_SUCCESS;
}


tokenProperties_t  set_tmp_rampart_options(tokenProperties_t tmp_rampart_ctx,
        zval *sec_token,
        zval *policy,
        axis2_env_t *env TSRMLS_DC) {
    HashTable *ht_policy = NULL;
    HashTable *ht_token = NULL;

    zval **policy_val = NULL;
    zval **token_val = NULL;

    /*     if (policy == NULL || sec_token == NULL) */
    /*         return AXIS2_FALSE; */

    if ( Z_TYPE_P(policy) == IS_OBJECT)
        ht_policy = Z_OBJPROP_P(policy);
    else
        ht_policy = Z_ARRVAL_P(policy);

    ht_token = Z_OBJPROP_P(sec_token);

    /*     if (!ht_policy || !ht_token) */
    /*         return AXIS2_FALSE; */

    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_policy] creating tmp rampart ctx ");


    if (zend_hash_find(ht_policy, WS_TIMESTAMP, sizeof(WS_TIMESTAMP), (void **)&policy_val) == SUCCESS &&
            Z_TYPE_PP(policy_val) == IS_BOOL) {
        if (Z_BVAL_PP(policy_val)) {
            if (zend_hash_find(ht_token, WS_TTL, sizeof(WS_TTL), (void **)&token_val) == SUCCESS &&
                    Z_TYPE_PP(token_val) == IS_LONG) {
                tmp_rampart_ctx.ttl = Z_LVAL_PP(token_val);
            }
        }
    }
    if (zend_hash_find(ht_token, WS_USER, sizeof(WS_USER), (void **)&token_val) == SUCCESS &&
            Z_TYPE_PP(token_val) == IS_STRING) {
        tmp_rampart_ctx.user = Z_STRVAL_PP(token_val);
    }
    if (zend_hash_find(ht_token, WS_PUBLICKEY, sizeof(WS_PUBLICKEY), (void **)&token_val) == SUCCESS &&
            Z_TYPE_PP(token_val) == IS_STRING) {
        tmp_rampart_ctx.publicKey = Z_STRVAL_PP(token_val);
    }
    if (zend_hash_find(ht_token, WS_PASSWORD_TYPE, sizeof(WS_PASSWORD_TYPE), (void **)&token_val) == SUCCESS &&
            Z_TYPE_PP(token_val) == IS_STRING) {
        tmp_rampart_ctx.passwordType = Z_STRVAL_PP(token_val);
    }
    if (zend_hash_find(ht_token, WS_PASSWORD, sizeof(WS_PASSWORD), (void **)&token_val) == SUCCESS &&
            Z_TYPE_PP(token_val) == IS_STRING) {
        tmp_rampart_ctx.password = Z_STRVAL_PP(token_val);
    }
    if (zend_hash_find(ht_token, WS_PUB_KEY_FORMAT, sizeof(WS_PUB_KEY_FORMAT), (void **)&token_val) == SUCCESS &&
            Z_TYPE_PP(token_val) == IS_STRING) {
        tmp_rampart_ctx.publicKeyFormat = Z_STRVAL_PP(token_val);
    }
    if (zend_hash_find(ht_token, WS_PVT_KEY_FORMAT, sizeof(WS_PVT_KEY_FORMAT), (void **)&token_val) == SUCCESS &&
            Z_TYPE_PP(token_val) == IS_STRING) {
        tmp_rampart_ctx.pvtKeyFormat = Z_STRVAL_PP(token_val);
    }




    return tmp_rampart_ctx;
}

int set_options_to_rampart_ctx(rampart_context_t *x_rampart_ctx,
                               axis2_env_t *env,
                               axiom_node_t *x_policy_node,
                               tokenProperties_t token_ctx) {
    if (rampart_context_set_policy_node(x_rampart_ctx, env,
                                        x_policy_node) == AXIS2_SUCCESS)
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy] setting creating policy node ");

    if (rampart_context_set_prv_key(x_rampart_ctx, env,
                                    (void *)token_ctx.pvtkey) == AXIS2_SUCCESS)
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy] setting pvt key  ");

    /*     if (rampart_context_set_prv_key_type(x_rampart_ctx, env, */
    /* 					 token_ctx.pvtKeyFormat) == AXIS2_SUCCESS) */
    /* 	    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy] setting pvt key format "); */

    if (rampart_context_set_pub_key(x_rampart_ctx, env,
                                    (void *)token_ctx.publicKey) == AXIS2_SUCCESS)
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy] setting pub key ");

    /*     if(rampart_context_set_pub_key_type(x_rampart_ctx, env, */
    /* 					token_ctx.publicKeyFormat) == AXIS2_SUCCESS) */
    /* 	    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy] setting pub key format "); */

    if (rampart_context_set_user(x_rampart_ctx, env,
                                 (axis2_char_t *)token_ctx.user) == AXIS2_SUCCESS)
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy] setting username ");

    if(rampart_context_set_password(x_rampart_ctx, env,
                                    (axis2_char_t *)token_ctx.password) == AXIS2_SUCCESS)
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy] setting password ");

    if (rampart_context_set_ttl(x_rampart_ctx, env,
                                token_ctx.ttl) == AXIS2_SUCCESS)
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy]setting ttl value ");

    return AXIS2_SUCCESS;
}



axiom_node_t *do_create_policy(zval *sec_token,
                               zval *policy,
                               axis2_env_t *env TSRMLS_DC) {
    axiom_node_t *root_om_node = NULL;
    axiom_node_t* exact_om_node = NULL;
    axiom_node_t *all_om_node = NULL;
    axiom_node_t *asymmetric_om_node = NULL;
    axiom_node_t *policy_om_node = NULL;
    axiom_node_t *timestamp_om_node = NULL;

    axiom_element_t* root_om_ele = NULL;
    axiom_element_t * exact_om_ele = NULL;
    axiom_element_t *all_om_ele = NULL;
    axiom_element_t *asymmetric_om_ele = NULL;

    axiom_namespace_t *wsp_ns = NULL;
    axiom_namespace_t *sp_ns = NULL;

    HashTable *ht_policy = NULL;
    HashTable *ht_token = NULL;

    /*     zval **policy_val = NULL; */
    /*     zval **token_val = NULL; */
    zval **tmp ;
    zval **tmp1;

    zval **sign_tmp = NULL;
    zval **encrypt_tmp = NULL;

    int is_encrypt = AXIS2_FALSE;
    int is_sign = AXIS2_FALSE;
    int is_default = AXIS2_TRUE; /* for the case when only
                                          * usernametoken or timestamp enable */

    if (policy == NULL || sec_token == NULL)
        return NULL;

    if ( Z_TYPE_P(policy) == IS_OBJECT)
        ht_policy = Z_OBJPROP_P(policy);
    else
        ht_policy = Z_ARRVAL_P(policy);

    ht_token = Z_OBJPROP_P(sec_token);

    if (!ht_policy || !ht_token)
        return NULL;

    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_policy] creating client out going policy node ");

    /* first it has to detertermine whether either sigining or
     * encryption is included in the policy object.If so proceed
     */

    if (zend_hash_find(ht_policy, WS_SIGN, sizeof(WS_SIGN), (void **)&tmp) == SUCCESS) {
        if (Z_TYPE_PP(tmp) == IS_STRING || Z_TYPE_PP(tmp) == IS_BOOL) {
            is_sign = AXIS2_TRUE;
            sign_tmp = tmp;
        }
    }

    if (zend_hash_find(ht_policy, WS_ENCRYPT, sizeof(WS_ENCRYPT), (void **)&tmp) == SUCCESS) {
        if (Z_TYPE_PP(tmp) == IS_STRING || Z_TYPE_PP(tmp) == IS_BOOL) {
            is_encrypt = AXIS2_TRUE;
            encrypt_tmp = tmp;
        }
    }

    wsp_ns = axiom_namespace_create(env, WS_POLICY_NAMESPACE_URI, WS_POLICY_NAMESPACE);
    root_om_ele = axiom_element_create(env, NULL, WS_POLICY, wsp_ns, &root_om_node);

    exact_om_ele = axiom_element_create(env, root_om_node, WS_POLICY_EXACTLYONE, wsp_ns, &exact_om_node);
    all_om_ele = axiom_element_create(env, exact_om_node, WS_POLICY_ALL, wsp_ns, &all_om_node);

    sp_ns = axiom_namespace_create(env, WS_SEC_POLICY_NAMESPACE_URI, WS_SEC_POLICY_NAMESPACE);
    asymmetric_om_ele = axiom_element_create(env, all_om_node, WS_POLICY_ASYMMETRIC_BINDING, sp_ns, &asymmetric_om_node);

    policy_om_node = create_policy_node(env, asymmetric_om_node );

    if ((is_sign == AXIS2_TRUE && sign_tmp != NULL) ||
            (is_encrypt == AXIS2_TRUE && encrypt_tmp != NULL)) {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy] encrypt or signing is enable");

        /*  if the sigining part is included in the user options */
        if (sign_tmp) {
            create_initiator_token(env, policy_om_node, sign_tmp TSRMLS_CC);
            create_sign_parts(env, policy_om_node, sign_tmp TSRMLS_CC);
            /* Signing is to be implemented in rampart */
            /* TODO */
        } else {
            /* Since initiator token is needed for the default case */
            create_default_sign(env, policy_om_node TSRMLS_CC);

        }
        /* if the encryption is included */
        if (encrypt_tmp) {
            create_recipient_token(env, policy_om_node, encrypt_tmp TSRMLS_CC);
            create_encrypt_parts(env, policy_om_node, encrypt_tmp TSRMLS_CC);
        } else {
            /* Since recipient token is needed for the default case */
            create_default_encrypt(env, policy_om_node);
        }
        /* if algorithm suite is presence in the options */
        if (zend_hash_find(ht_policy, WS_ALGORITHM, sizeof(WS_ALGORITHM), (void **)&tmp) == SUCCESS) {
            create_algorithm_suite(env, policy_om_node, tmp TSRMLS_CC);
        } else {
            AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy] No algorithm found so quit");
            /* 	    return NULL; */
        }
        /*if the Layout is presence call this function for the default
         * case layout is strict */
        if (zend_hash_find(ht_policy, WS_LAYOUT, sizeof(WS_LAYOUT), (void **)&tmp) == SUCCESS) {
            create_layout(env, policy_om_node, tmp TSRMLS_CC);
        } else
            create_layout(env, policy_om_node, tmp TSRMLS_CC);

        is_default = AXIS2_FALSE;
    }

    /* for timestamp */
    if (zend_hash_find(ht_policy, WS_TIMESTAMP, sizeof(WS_TIMESTAMP), (void **)&tmp) == SUCCESS &&
            zend_hash_find(ht_token, WS_TTL, sizeof(WS_TTL), (void **)&tmp) == SUCCESS ) {
        if ( is_default == AXIS2_TRUE) {
            create_default_sign(env, policy_om_node TSRMLS_CC);
            create_default_encrypt(env, policy_om_node);
            is_default = AXIS2_FALSE;
        }

        axiom_element_create(env, policy_om_node, "IncludeTimestamp", sp_ns, &timestamp_om_node);
    }

    /* for usernameToken */
    if (zend_hash_find(ht_policy, WS_UT, sizeof(WS_UT), (void **)&tmp) == SUCCESS &&
            zend_hash_find(ht_token, WS_USER, sizeof(WS_USER), (void **)&tmp1) == SUCCESS ) {
        if ( is_default == AXIS2_TRUE) {
            create_default_sign(env, policy_om_node TSRMLS_CC);
            create_default_encrypt(env, policy_om_node);
            is_default = AXIS2_FALSE;
        }
        create_username_token(env, policy_om_node, tmp TSRMLS_CC);
    }

    /* for security token reference */
    if (zend_hash_find(ht_policy, WS_TOKEN_REFERENCE, sizeof(WS_TOKEN_REFERENCE), (void **)&tmp) == SUCCESS) {
        if (is_default == AXIS2_FALSE)
            create_token_reference(env, policy_om_node, tmp TSRMLS_CC);
    }

    return root_om_node;
}

axiom_node_t *
create_policy_node(const axis2_env_t *env,
                   axiom_node_t *parent_om_node) {
    axiom_node_t *policy_om_node = NULL;
    axiom_element_t *policy_om_ele = NULL;
    axiom_namespace_t *wsp_ns = NULL;

    wsp_ns = axiom_namespace_create(env, WS_POLICY_NAMESPACE_URI, WS_POLICY_NAMESPACE);
    policy_om_ele = axiom_element_create(env, parent_om_node, WS_POLICY, wsp_ns, &policy_om_node);

    return policy_om_node;


}


axiom_node_t *
create_initiator_token(const axis2_env_t *env,
                       axiom_node_t *parent_om_node,
                       zval **tmp TSRMLS_DC) {
    axiom_node_t *in_token_om_node = NULL;
    axiom_node_t *policy_om_node1 = NULL;
    axiom_node_t *x509_om_node = NULL;
    axiom_node_t *policy_om_node2 = NULL;
    axiom_node_t *token_id_om_node = NULL;
    axiom_node_t *tmp_node = NULL; /* if wrong option is found earlier
                                            * node should be given back */

    axiom_element_t *in_token_om_ele = NULL;
    axiom_element_t *x509_om_ele = NULL;

    axiom_attribute_t *attr = NULL;

    axiom_namespace_t *sp_ns = NULL;
    char *token_name = NULL;

    tmp_node = parent_om_node;

    /* for x509 token and kerberose tokens.. can be extend later */
    if( tmp != NULL && Z_TYPE_PP(tmp) == IS_STRING) {
        token_name = Z_STRVAL_PP(tmp);
        if (stricmp(token_name, "x509") == 0) {
            sp_ns = axiom_namespace_create(env, WS_SEC_POLICY_NAMESPACE_URI,  WS_SEC_POLICY_NAMESPACE);

            in_token_om_ele = axiom_element_create(env, parent_om_node, WS_INITIATOR_VAL, sp_ns, &in_token_om_node);
            policy_om_node1 = create_policy_node(env, in_token_om_node);

            x509_om_ele = axiom_element_create(env, policy_om_node1,  WS_X509_TOKEN_VAL, sp_ns, &x509_om_node);
            attr = axiom_attribute_create(env,WS_INCLUDE_TOKEN, WS_INCLUDE_TOKEN_URI,
                                          sp_ns);
            AXIOM_ELEMENT_ADD_ATTRIBUTE(x509_om_ele, env, attr, x509_om_node);
            policy_om_node2 = create_policy_node(env, x509_om_node);
            axiom_element_create(env, policy_om_node2, "WssX509V3Token10", sp_ns, &token_id_om_node);
            return token_id_om_node;
        }
        /** implement for othertoken types */

    }

    if (tmp != NULL && Z_TYPE_PP(tmp) == IS_BOOL) {
        /* for the default case also it is treated as X509 */
        if (Z_BVAL_PP(tmp)) {
            sp_ns = axiom_namespace_create(env,WS_SEC_POLICY_NAMESPACE_URI,  WS_SEC_POLICY_NAMESPACE);
            in_token_om_ele = axiom_element_create(env, parent_om_node, WS_INITIATOR_VAL, sp_ns, &in_token_om_node);
            policy_om_node1 = create_policy_node(env, in_token_om_node);

            x509_om_ele = axiom_element_create(env, policy_om_node1, WS_X509_TOKEN_VAL, sp_ns, &x509_om_node);

            attr = axiom_attribute_create(env,WS_INCLUDE_TOKEN,  WS_INCLUDE_TOKEN_URI,
                                          sp_ns);
            AXIOM_ELEMENT_ADD_ATTRIBUTE(x509_om_ele, env, attr, x509_om_node);
            policy_om_node2 = create_policy_node(env, x509_om_node);
            axiom_element_create(env, policy_om_node2, "WssX509V3Token10", sp_ns, &token_id_om_node);
            return token_id_om_node;
        } else {
            /* 	   php_error_docref(NULL TSRMLS_CC, E_WARNING, "sigining is not specified"); */
            return tmp_node;
        }
    }

    return tmp_node;
}


/** for encryption part of the policy file */

axiom_node_t *
create_recipient_token(const axis2_env_t *env,
                       axiom_node_t *parent_om_node,
                       zval **tmp TSRMLS_DC) {
    axiom_node_t *rec_token_om_node = NULL;
    axiom_node_t *policy_om_node1 = NULL;
    axiom_node_t *x509_om_node = NULL;
    axiom_node_t *policy_om_node2 = NULL;
    axiom_node_t *token_id_om_node = NULL;
    axiom_node_t *tmp_node = NULL;

    axiom_element_t *rec_token_om_ele = NULL;
    axiom_element_t *x509_om_ele = NULL;

    axiom_attribute_t *attr = NULL;

    axiom_namespace_t *sp_ns = NULL;
    char *token_name = NULL;

    tmp_node = parent_om_node;

    if( tmp != NULL && Z_TYPE_PP(tmp) == IS_STRING) {
        token_name = Z_STRVAL_PP(tmp);
        if (stricmp(token_name, WS_DEFAULT_TOKEN_VAL) == 0) {

            sp_ns = axiom_namespace_create(env,WS_SEC_POLICY_NAMESPACE_URI,  WS_SEC_POLICY_NAMESPACE);

            rec_token_om_ele = axiom_element_create(env, parent_om_node,  WS_RECIPIENT_TOKEN, sp_ns, &rec_token_om_node);
            policy_om_node1 = create_policy_node(env, rec_token_om_node);
            x509_om_ele = axiom_element_create(env, policy_om_node1, WS_X509_TOKEN_VAL, sp_ns, &x509_om_node);

            /* Here uri may change according to the options difined in policy spec
             * e.g - 'Always' may be changed as 'Never'*/
            attr = axiom_attribute_create(env,WS_INCLUDE_TOKEN,  WS_INCLUDE_TOKEN_URI,
                                          sp_ns);
            AXIOM_ELEMENT_ADD_ATTRIBUTE(x509_om_ele, env, attr, x509_om_node);
            policy_om_node2 = create_policy_node(env, x509_om_node);
            axiom_element_create(env, policy_om_node2, "WssX509V3Token10", sp_ns, &token_id_om_node);
            return token_id_om_node;
        }
    }

    if ( tmp != NULL && Z_TYPE_PP(tmp) == IS_BOOL) {
        if ( Z_BVAL_PP(tmp)) {
            sp_ns = axiom_namespace_create(env,WS_SEC_POLICY_NAMESPACE_URI,  WS_SEC_POLICY_NAMESPACE);

            rec_token_om_ele = axiom_element_create(env, parent_om_node,  WS_RECIPIENT_TOKEN, sp_ns, &rec_token_om_node);
            policy_om_node1 = create_policy_node(env, rec_token_om_node);
            x509_om_ele = axiom_element_create(env, policy_om_node1, WS_X509_TOKEN_VAL, sp_ns, &x509_om_node);

            /* Here uri may change according to the options difined in policy spec
             * e.g - 'Always' may be changed as 'Never'*/
            attr = axiom_attribute_create(env,  WS_INCLUDE_TOKEN ,  WS_INCLUDE_TOKEN_URI,
                                          sp_ns);
            AXIOM_ELEMENT_ADD_ATTRIBUTE(x509_om_ele, env, attr, x509_om_node);
            policy_om_node2 = create_policy_node(env, x509_om_node);
            axiom_element_create(env, policy_om_node2, "WssX509V3Token10", sp_ns, &token_id_om_node);
            return token_id_om_node;

        }

    }
    return tmp_node;
}




axiom_node_t *
create_algorithm_suite(const axis2_env_t *env,
                       axiom_node_t *parent_node,
                       zval **tmp TSRMLS_DC) {
    axiom_node_t *alg_om_node = NULL;
    axiom_node_t *alg_name_om_node = NULL;
    axiom_node_t *policy_om_node = NULL;
    axiom_node_t *tmp_node = NULL;

    axiom_namespace_t *sp_ns = NULL;
    char *alg_name = NULL;

    tmp_node = parent_node;


    if ( tmp != NULL && Z_TYPE_PP(tmp) == IS_STRING) {
        int i ;
        alg_name = Z_STRVAL_PP(tmp);
        for (i = 0; i < ArrySize ; i++) {
            if ((strcmp(alg_name, algorithmArry[i]) == 0)) {
                sp_ns = axiom_namespace_create(env, WS_SEC_POLICY_NAMESPACE_URI,  WS_SEC_POLICY_NAMESPACE);
                axiom_element_create(env, parent_node, WS_ALGO_SUITE, sp_ns, &alg_om_node);
                policy_om_node = create_policy_node(env, alg_om_node);
                axiom_element_create(env, policy_om_node, algorithmArry[i], sp_ns, &alg_name_om_node);

                return alg_name_om_node;
            }
        }
    }

    return tmp_node;

}
/* this function is called if only user want to sign the xml
 * message.Now only we have only default case "OnlySignEntireHeadersAndBody */
axiom_node_t *
create_sign_parts(const axis2_env_t *env,
                  axiom_node_t *parent_node,
                  zval **tmp TSRMLS_DC) {
    axiom_node_t *sign_om_node = NULL;
    axiom_namespace_t *sp_ns = NULL;

    sp_ns = axiom_namespace_create(env, WS_SEC_POLICY_NAMESPACE_URI, WS_SEC_POLICY_NAMESPACE);
    axiom_element_create(env, parent_node, WS_ONLY_SIGN_HEADER_AND_BODY, sp_ns, &sign_om_node);
    return sign_om_node;
}

axiom_node_t *
create_encrypt_parts(const axis2_env_t *env,
                     axiom_node_t *parent_node,
                     zval **tmp TSRMLS_DC) {
    axiom_node_t *encrypt_om_node = NULL;
    axiom_node_t *part_om_node = NULL;
    axiom_namespace_t *sp_ns = NULL;

    sp_ns = axiom_namespace_create(env, WS_SEC_POLICY_NAMESPACE_URI, WS_SEC_POLICY_NAMESPACE);
    axiom_element_create(env, parent_node, "EncryptedParts", sp_ns, &encrypt_om_node);
    axiom_element_create(env, encrypt_om_node, "Body", sp_ns, &part_om_node);
    return part_om_node;
}


axiom_node_t *
create_layout(const axis2_env_t *env,
              axiom_node_t *parent_node,
              zval **tmp TSRMLS_DC) {
    axiom_node_t *layout_om_node = NULL;
    axiom_node_t *policy_om_node = NULL;
    axiom_node_t *strict_om_node = NULL;

    axiom_namespace_t *sp_ns = NULL;

    sp_ns = axiom_namespace_create(env, WS_SEC_POLICY_NAMESPACE_URI,  WS_SEC_POLICY_NAMESPACE);
    axiom_element_create(env, parent_node, "Layout", sp_ns, &layout_om_node);
    policy_om_node = create_policy_node(env, layout_om_node);
    axiom_element_create(env, policy_om_node, "Strict", sp_ns, &strict_om_node);
    return strict_om_node;
}

axiom_node_t *
create_default_sign(const axis2_env_t *env,
                    axiom_node_t *parent_node TSRMLS_DC) {
    zval *test;
    MAKE_STD_ZVAL(test);
    ZVAL_STRING(test, WS_DEFAULT_TOKEN_VAL, 1);
    create_initiator_token(env, parent_node, &test TSRMLS_CC);

}

axiom_node_t *
create_default_encrypt(const axis2_env_t *env,
                       axiom_node_t *parent_node TSRMLS_DC) {
    zval *test;
    MAKE_STD_ZVAL(test);
    ZVAL_STRING(test, WS_DEFAULT_TOKEN_VAL, 1);
    create_recipient_token(env, parent_node, &test TSRMLS_CC);

}

axiom_node_t *
create_username_token(const axis2_env_t *env,
                      axiom_node_t *parent_node,
                      zval **tmp TSRMLS_DC) {
    axiom_node_t *signsupport_om_node = NULL;
    axiom_node_t *policy_om_node = NULL;
    axiom_node_t *ut_om_node = NULL;

    axiom_element_t *ele = NULL;
    axiom_attribute_t *attr = NULL;
    axiom_namespace_t *sp_ns = NULL;

    sp_ns = axiom_namespace_create(env, WS_SEC_POLICY_NAMESPACE_URI, WS_SEC_POLICY_NAMESPACE);
    axiom_element_create(env, parent_node, WS_SIGNSUPPORTING_TOKEN, sp_ns, &signsupport_om_node);
    policy_om_node = create_policy_node(env, signsupport_om_node);
    ele = axiom_element_create(env, policy_om_node, WS_USERNAMETOKEN, sp_ns, &ut_om_node);
    attr = axiom_attribute_create(env,  WS_INCLUDE_TOKEN ,  WS_INCLUDE_TOKEN_URI,
                                  sp_ns);
    AXIOM_ELEMENT_ADD_ATTRIBUTE(ele, env, attr, ut_om_node);

    return ut_om_node;

}

char * get_sec_token_Value(char *token_name);

axiom_node_t *
create_token_reference(const axis2_env_t *env,
                       axiom_node_t *parent_node,
                       zval **tmp TSRMLS_DC) {
    axiom_node_t *wss10_om_node = NULL;
    axiom_node_t *policy_om_node = NULL;
    axiom_node_t *token_om_node = NULL;

    char *token_name = NULL;
    axiom_namespace_t *sp_ns = NULL;
    char *token_val = NULL;

    sp_ns = axiom_namespace_create(env, WS_SEC_POLICY_NAMESPACE_URI, WS_SEC_POLICY_NAMESPACE);

    if ( tmp != NULL && Z_TYPE_PP(tmp) == IS_STRING) {
        int i ;
        token_name = Z_STRVAL_PP(tmp);
        if (strcmp(token_name, DIRECT) == 0) {
            AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_policy] DirectReference is chosen  ");
            return parent_node;
        } else {
            token_val = get_sec_token_Value(token_name);

            sp_ns = axiom_namespace_create(env, WS_SEC_POLICY_NAMESPACE_URI,  WS_SEC_POLICY_NAMESPACE);
            axiom_element_create(env, parent_node, "Wss10", sp_ns, &wss10_om_node);
            policy_om_node = create_policy_node(env, wss10_om_node);
            axiom_element_create(env, policy_om_node, token_val, sp_ns, &token_om_node);

            return token_om_node;
        }
    }
    return parent_node;
}

char * get_sec_token_Value(char *token_name) {
    if(strcmp(token_name, ISSUER_SERIAL) == 0)
        return ISSUER_SERIAL_VAL;
    if(strcmp(token_name, KEYIDENTIFIER) == 0)
        return KEYIDENTIFIER_VAL;
    if(strcmp(token_name, EMBEDDEDTOKEN) == 0)
        return EMBEDDEDTOKEN_VAL;
    if(strcmp(token_name, THUMBPRINT) == 0)
        return THUMBPRINT_VAL;

}




int ws_policy_set_policy_options(zval *this_ptr,
                                 HashTable *ht,
                                 const axis2_env_t *env TSRMLS_DC) {
    zval **tmp = NULL;

    if (!ht)
        return AXIS2_FAILURE;


    /* for security policy related things */
    if(zend_hash_find(ht, "security", sizeof("security"), (void **)&tmp) == SUCCESS &&
            Z_TYPE_PP(tmp) == IS_ARRAY) {
        set_security_policy_options(this_ptr, tmp , env TSRMLS_CC);
    }

    return AXIS2_SUCCESS;

}

int set_security_policy_options(zval *policy_obj,
                                zval **sec_options,
                                const axis2_env_t *env TSRMLS_DC) {
    HashTable *ht_sec = NULL;

    zval **sec_prop = NULL;

    if (sec_options == NULL)
        return AXIS2_FAILURE ;

    ht_sec = Z_ARRVAL_PP(sec_options);
    if (!ht_sec)
        return AXIS2_FAILURE;


    if (zend_hash_find(ht_sec, WS_SIGN, sizeof(WS_SIGN), (void **)&sec_prop) == SUCCESS &&
            (Z_TYPE_PP(sec_prop) == IS_STRING || Z_TYPE_PP(sec_prop) == IS_BOOL )) {
        add_property_zval(policy_obj, WS_SIGN, *sec_prop);
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_policy] signing is enable ");
    }

    if (zend_hash_find(ht_sec, WS_ENCRYPT, sizeof(WS_ENCRYPT), (void **)&sec_prop) == SUCCESS &&
            (Z_TYPE_PP(sec_prop) == IS_STRING || Z_TYPE_PP(sec_prop) == IS_BOOL)) {
        add_property_zval(policy_obj, WS_ENCRYPT, *sec_prop);
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_policy]  encryption is enable ");

    }

    if (zend_hash_find(ht_sec, WS_ALGORITHM, sizeof(WS_ALGORITHM), (void **)&sec_prop) == SUCCESS &&
            (Z_TYPE_PP(sec_prop) == IS_STRING )) {
        add_property_stringl(policy_obj, WS_ALGORITHM, Z_STRVAL_PP(sec_prop), Z_STRLEN_PP(sec_prop), 1 );
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_policy] algorithmSuite is enable ");

    }

    if (zend_hash_find(ht_sec, WS_LAYOUT, sizeof(WS_LAYOUT), (void **)&sec_prop) == SUCCESS &&
            (Z_TYPE_PP(sec_prop) == IS_STRING)) {
        add_property_stringl(policy_obj, WS_LAYOUT, Z_STRVAL_PP(sec_prop), Z_STRLEN_PP(sec_prop), 1 );
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_policy] layout is enable ");

    }

    if (zend_hash_find(ht_sec, WS_TIMESTAMP, sizeof(WS_TIMESTAMP), (void **)&sec_prop) == SUCCESS &&
            (Z_TYPE_PP(sec_prop) == IS_BOOL)) {
        add_property_bool(policy_obj, WS_TIMESTAMP, Z_BVAL_PP(sec_prop));
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_policy] timestamp is enable ");

    }

    if (zend_hash_find(ht_sec, WS_PROTECTION_ORDER, sizeof(WS_PROTECTION_ORDER), (void **)&sec_prop) == SUCCESS &&
            (Z_TYPE_PP(sec_prop) == IS_STRING)) {
        add_property_stringl(policy_obj, WS_PROTECTION_ORDER, Z_STRVAL_PP(sec_prop), Z_STRLEN_PP(sec_prop), 1 );
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_policy] protection order is enable ");

    }

    if (zend_hash_find(ht_sec, WS_UT, sizeof(WS_UT), (void **)&sec_prop) == SUCCESS &&
            (Z_TYPE_PP(sec_prop) == IS_BOOL)) {
        add_property_bool(policy_obj, WS_UT, Z_BVAL_PP(sec_prop));
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_policy] UsernameToken is enable ");

    }

    if (zend_hash_find(ht_sec, WS_TOKEN_REFERENCE, sizeof(WS_TOKEN_REFERENCE), (void **)&sec_prop) == SUCCESS &&
            (Z_TYPE_PP(sec_prop) == IS_STRING)) {
        add_property_stringl(policy_obj, WS_TOKEN_REFERENCE, Z_STRVAL_PP(sec_prop), Z_STRLEN_PP(sec_prop), 1 );
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_policy] token reference  is enable ");

    }

    /* if inflow security and outflow security exits in the array */
    if (zend_hash_find(ht_sec, WS_IN_POLICY, sizeof(WS_IN_POLICY), (void **)&sec_prop) == SUCCESS &&
            (Z_TYPE_PP(sec_prop) == IS_ARRAY)) {
        add_property_zval(policy_obj, WS_IN_POLICY, *sec_prop );
        set_security_policy_options(policy_obj, sec_prop , env TSRMLS_CC);
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_policy] in policy array is enable ");

    }

    if (zend_hash_find(ht_sec, WS_OUT_POLICY, sizeof(WS_OUT_POLICY), (void **)&sec_prop) == SUCCESS &&
            (Z_TYPE_PP(sec_prop) == IS_ARRAY)) {
        add_property_zval(policy_obj, WS_OUT_POLICY, *sec_prop );
        set_security_policy_options(policy_obj, sec_prop , env TSRMLS_CC);
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_policy] out policy array is enable ");

    }

    return AXIS2_SUCCESS;
}
