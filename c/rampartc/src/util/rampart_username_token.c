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

#include <axutil_qname.h>
#include <axis2_svc.h>
#include <axiom_soap_header.h>
#include <axiom_soap_body.h>
#include <axiom_soap_header_block.h>
#include <axis2_endpoint_ref.h>
#include <axutil_property.h>
#include <rampart_username_token.h>
#include <rampart_constants.h>
#include <rampart_crypto_util.h>
#include <rampart_util.h>
#include <rampart_callback.h>
#include <rampart_handler_util.h>
#include <rampart_sec_processed_result.h>
#include <rampart_authn_provider.h>
#include <oxs_axiom.h>

/** public functions*/




axis2_status_t AXIS2_CALL
rampart_username_token_build(
    const axutil_env_t *env,
    rampart_context_t *rampart_context,
    axiom_node_t *sec_node,
    axiom_namespace_t *sec_ns_obj
)
{

    axiom_node_t *ut_node = NULL;
    axiom_node_t *un_node = NULL;
    axiom_node_t *pw_node = NULL;
    axiom_node_t *nonce_node = NULL;
    axiom_node_t *created_node = NULL;
    axiom_element_t  *ut_ele = NULL;
    axiom_element_t *un_ele = NULL;
    axiom_element_t *pw_ele = NULL;
    axiom_element_t *nonce_ele = NULL;
    axiom_element_t *created_ele = NULL;
    axiom_namespace_t *wsu_ns_obj = NULL;
    axiom_attribute_t *om_attr = NULL;
    axis2_char_t *password = NULL;
    axis2_char_t *username = NULL;
    rampart_callback_t *password_callback = NULL;
    /*  axis2_bool_t isdigest = AXIS2_FALSE;*/
    axis2_char_t *password_type = NULL;
    password_callback_fn password_function = NULL;
    void *param = NULL;


    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    /*Directly call the password from callback module*/

    username = rampart_context_get_user(rampart_context,env);
    if(!username)
    {
        AXIS2_LOG_INFO(env->log, "[rampart][rampart_usernametoken] User is not specified.");
        return AXIS2_FAILURE;
    }

    password = rampart_context_get_password(rampart_context,env);

    if(!password)
    {
        password_function = rampart_context_get_pwcb_function(rampart_context,env);
        if(password_function)
        {
            param = rampart_context_get_ctx(rampart_context,env);
            if(!param)
            {
                AXIS2_LOG_INFO(env->log, "[rampart][rampart_usernametoken] Param is not set.");
                return AXIS2_FAILURE;
            }
            password = (*password_function)(env,username,param);
        }
        else
        {
            password_callback = rampart_context_get_password_callback(rampart_context,env);
            if(!password_callback)
            {
                AXIS2_LOG_INFO(env->log, "[rampart][rampart_usernametoken] password callback module is not loaded. ERROR");
                return AXIS2_FAILURE;
            }
            password = rampart_callback_password(env, password_callback,username);
        }
    }
    if (!password)
    {
        AXIS2_LOG_INFO(env->log, "[rampart][rampart_usernametoken] Cannot find the password for user %s. ERROR", username);
        return AXIS2_FAILURE;
    }

    ut_ele = axiom_element_create(env, sec_node,
                                  RAMPART_SECURITY_USERNAMETOKEN,
                                  sec_ns_obj,
                                  &ut_node);

    wsu_ns_obj = axiom_namespace_create(env, RAMPART_WSU_XMLNS,
                                        RAMPART_WSU);
    axiom_element_declare_namespace(ut_ele, env,
                                    ut_node, wsu_ns_obj);

    if (ut_ele)
    {

        un_ele = axiom_element_create(env, ut_node, RAMPART_SECURITY_USERNAMETOKEN_USERNAME, sec_ns_obj,
                                      &un_node);
        if (un_ele)
        {
            axiom_namespace_t *dec_ns = NULL;
            axiom_element_set_text(un_ele, env, username, un_node);
            dec_ns = axiom_element_find_declared_namespace(un_ele, env,
                     RAMPART_WSSE_XMLNS,
                     RAMPART_WSSE);


            axiom_element_set_namespace(un_ele, env, sec_ns_obj, un_node);
        }

        password_type = rampart_context_get_password_type(rampart_context,env);
        if(!password_type)
            password_type = RAMPART_PASSWORD_TEXT;
        if (0 == axutil_strcmp(password_type, RAMPART_PASSWORD_DIGEST))
        {
            axis2_char_t *nonce_val = NULL;
            axis2_char_t *created_val = NULL;
            axis2_char_t *digest_val = NULL;
            axiom_namespace_t *dec_ns = NULL;

            nonce_val = rampart_generate_nonce(env) ;
            created_val = rampart_generate_time(env, 0);
            digest_val = rampart_crypto_sha1(env, nonce_val, created_val, password);

            pw_ele = axiom_element_create(env, ut_node, RAMPART_SECURITY_USERNAMETOKEN_PASSWORD, sec_ns_obj,
                                          &pw_node);
            if (pw_ele)
            {

                axiom_element_set_text(pw_ele, env, digest_val, pw_node);
                dec_ns = axiom_element_find_declared_namespace(pw_ele, env,
                         RAMPART_WSSE_XMLNS,
                         RAMPART_WSSE);


                om_attr = axiom_attribute_create(env,
                                                 RAMPART_SECURITY_USERNAMETOKEN_PASSWORD_ATTR_TYPE,
                                                 RAMPART_PASSWORD_DIGEST_URI,
                                                 NULL);

                axiom_element_add_attribute(pw_ele, env,
                                            om_attr, pw_node);

            }
            nonce_ele = axiom_element_create(env, ut_node, RAMPART_SECURITY_USERNAMETOKEN_NONCE, sec_ns_obj,
                                             &nonce_node);
            if (nonce_ele)
            {
                axiom_namespace_t *dec_ns = NULL;
                axiom_element_set_text(nonce_ele, env, nonce_val , nonce_node);
                dec_ns = axiom_element_find_declared_namespace(nonce_ele, env,
                         RAMPART_WSSE_XMLNS,
                         RAMPART_WSSE);
            }
            created_ele = axiom_element_create(env, ut_node, RAMPART_SECURITY_USERNAMETOKEN_CREATED, sec_ns_obj,
                                               &created_node);
            if (created_ele)
            {
                axiom_namespace_t *dec_ns = NULL;
                axiom_element_set_text(created_ele, env, created_val, created_node);
                dec_ns = axiom_element_find_declared_namespace(created_ele, env,
                         RAMPART_WSSE_XMLNS,
                         RAMPART_WSSE);

                axiom_element_set_namespace(created_ele, env, wsu_ns_obj, created_node);

            }

            if(nonce_val){
                /*AXIS2_FREE(env->allocator, nonce_val);
                nonce_val = NULL;*/
            }
            if(created_val){
                AXIS2_FREE(env->allocator, created_val);
                created_val = NULL;
            }
            if(digest_val){
                AXIS2_FREE(env->allocator, digest_val);
                digest_val = NULL;
            }
        }
        else /*default is passwordText*/
        {
            pw_ele = axiom_element_create(env, ut_node, RAMPART_SECURITY_USERNAMETOKEN_PASSWORD, sec_ns_obj,
                                          &pw_node);
            if (pw_ele)
            {
                axiom_namespace_t *dec_ns = NULL;
                axiom_element_set_text(pw_ele, env, password, pw_node);
                dec_ns = axiom_element_find_declared_namespace(pw_ele, env,
                         RAMPART_WSSE_XMLNS,
                         RAMPART_WSSE);

                om_attr = axiom_attribute_create(env,
                                                 RAMPART_SECURITY_USERNAMETOKEN_PASSWORD_ATTR_TYPE,
                                                 RAMPART_PASSWORD_TEXT_URI,
                                                 NULL);

                axiom_element_add_attribute(pw_ele, env,
                                            om_attr, pw_node);
            }
        } /*End if passwordType == passwordText*/
    }
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
rampart_username_token_validate(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    axiom_node_t *ut_node,
    rampart_context_t *rampart_context)
{
    axiom_child_element_iterator_t *children = NULL;
    axis2_char_t *username = NULL;
    axis2_char_t *password = NULL;
    axis2_char_t *nonce = NULL;
    axis2_char_t *created = NULL;
    axis2_char_t *password_type = NULL;
    rampart_callback_t *password_callback = NULL;
    rampart_authn_provider_t *authn_provider = NULL;
    axis2_char_t *password_from_svr = NULL;
    axis2_char_t *password_to_compare = NULL;
    axis2_ctx_t *ctx = NULL;
    rampart_authn_provider_status_t auth_status= RAMPART_AUTHN_PROVIDER_GENERAL_ERROR ;
    axiom_element_t *ut_ele = NULL;
    password_callback_fn password_function = NULL;
    void *param = NULL;
    auth_password_func authenticate_with_password = NULL;
    auth_digest_func authenticate_with_digest = NULL;
    axis2_char_t *password_type_pol = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    ut_ele = axiom_node_get_data_element(ut_node, env);
    if(!ut_ele)
        return AXIS2_FAILURE;

    /*Check: Any USERNAME_TOKEN MUST NOT have more than one PASSWORD*/
    if (1 <  oxs_axiom_get_number_of_children_with_qname(env, ut_node, RAMPART_SECURITY_USERNAMETOKEN_PASSWORD, RAMPART_WSSE_XMLNS, RAMPART_WSSE))
    {
        AXIS2_LOG_INFO(env->log, "[rampart][rampart_usernametoken] Username token must not have more than one password");
        return AXIS2_FAILURE;
    }

    /*Check: Any USERNAME_TOKEN MUST NOT have more than one CREATED*/
    if (1 <  oxs_axiom_get_number_of_children_with_qname(env, ut_node, RAMPART_SECURITY_USERNAMETOKEN_CREATED, RAMPART_WSSE_XMLNS, RAMPART_WSSE))
    {
        AXIS2_LOG_INFO(env->log, "[rampart][rampart_usernametoken] Username token must not have more than one creted element");
        return AXIS2_FAILURE;
    }

    /*Check: Any USERNAME_TOKEN MUST NOT have more than one NONCE*/
    if (1 <  oxs_axiom_get_number_of_children_with_qname(env, ut_node, RAMPART_SECURITY_USERNAMETOKEN_NONCE, RAMPART_WSSE_XMLNS, RAMPART_WSSE))
    {
        AXIS2_LOG_INFO(env->log, "[rampart][rampart_usernametoken] Username token must not have more than one nonce element");
        return AXIS2_FAILURE;
    }

    /*Get thru children of UsernameToken element*/
    children = axiom_element_get_child_elements(ut_ele, env, ut_node);
    if (children)
    {
        /*Go thru children and find username token parameters*/
        while (AXIS2_TRUE == axiom_child_element_iterator_has_next(children, env))
        {
            axiom_node_t *node = NULL;
            axiom_element_t *element = NULL;
            axis2_char_t *localname = NULL;

            node = axiom_child_element_iterator_next(children, env);
            element = axiom_node_get_data_element(node, env);
            localname =  axiom_element_get_localname(element, env);

            if (0 == axutil_strcmp(localname, RAMPART_SECURITY_USERNAMETOKEN_USERNAME))
            {
                username = axiom_element_get_text(element, env, node);

            }
            else if (0 == axutil_strcmp(localname , RAMPART_SECURITY_USERNAMETOKEN_PASSWORD))
            {
                password_type = axiom_element_get_attribute_value_by_name(element,
                                env,
                                RAMPART_SECURITY_USERNAMETOKEN_PASSWORD_ATTR_TYPE);

                if (!password_type)
                {
                    /*R4201 Any PASSWORD MUST specify a Type attribute */
                    AXIS2_LOG_INFO(env->log, "[rampart][rampart_usernametoken] Password Type is not specified in the password element");
                    return AXIS2_FAILURE;
                }
                /*Then we must check the password type with policy*/
                password_type_pol = rampart_context_get_password_type(rampart_context,env);
                if(!password_type_pol)
                    password_type_pol = RP_PLAINTEXT;

                if(axutil_strcmp(password_type_pol,RP_DIGEST)==0)
                {
                    if(0 != axutil_strcmp(password_type, RAMPART_PASSWORD_DIGEST_URI))
                    {
                        AXIS2_LOG_INFO(env->log, "[rampart][rampart_usernametoken] Password Type is Wrong");
                        return AXIS2_FAILURE;
                    }
                }
                else if(axutil_strcmp(password_type_pol,RP_PLAINTEXT)==0)
                {
                    if(0 == axutil_strcmp(password_type, RAMPART_PASSWORD_DIGEST_URI))
                    {
                        AXIS2_LOG_INFO(env->log, "[rampart][rampart_usernametoken] Password Type is Wrong");
                        return AXIS2_FAILURE;
                    }
                }
                password = axiom_element_get_text(element, env, node);

            }
            else if (0 == axutil_strcmp(localname,  RAMPART_SECURITY_USERNAMETOKEN_NONCE))
            {
                nonce = axiom_element_get_text(element, env, node);
                rampart_set_security_processed_result(env, msg_ctx, RAMPART_SPR_UT_NONCE, nonce);

            }
            else if (0 == axutil_strcmp(localname ,  RAMPART_SECURITY_USERNAMETOKEN_CREATED))
            {
                created = axiom_element_get_text(element, env, node);
                rampart_set_security_processed_result(env, msg_ctx, RAMPART_SPR_UT_CREATED, created);

            }
            else
            {
                AXIS2_LOG_INFO(env->log, "\n[rampart][rampart_usernametoken] Unknown element found %s -> %s", localname, axiom_element_get_text(element, env, node));
            }


        }/*end of while*/
    }
    else
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[rampart][rampart_usernametoken] Cannot find child elements of Usernametoken");
        return AXIS2_FAILURE;
    }

    /*Now we process collected usernametoken parameters*/
    if (!username)
    {
        AXIS2_LOG_INFO(env->log,  "[rampart][rampart_usernametoken] Username is not specified");
        return AXIS2_FAILURE;
    }

    /*Set the username to the SPR*/
    rampart_set_security_processed_result(env, msg_ctx, RAMPART_SPR_UT_USERNAME, username);
    ctx = axis2_msg_ctx_get_base(msg_ctx, env);

    /**
     * NOTE: Here we will try two apraoches to get the UT validated
     * 1. Authentication module
     * 2. Password callback module
     *
     * If authentication module is defined use it. 
     * Else try the usual approach to get password from the callback and compare
     * */
    /*In both authentication and password callback methods we should first try to
     *use function pointers. */

    /*authn_module_name = "/home/kau/axis2/c/deploy/bin/samples/rampart/authn_provider/libauthn.so";*/
    if (0 == axutil_strcmp(password_type, RAMPART_PASSWORD_DIGEST_URI))
    {
        authenticate_with_digest = rampart_context_get_auth_digest_function(rampart_context,env);
        if(authenticate_with_digest)
        {
            auth_status = authenticate_with_digest(env,username,nonce,created,password);
            if(RAMPART_AUTHN_PROVIDER_GRANTED == auth_status)
            {
                AXIS2_LOG_INFO(env->log,  "[rampart][rampart_usernametoken] User authenticated");
                rampart_set_security_processed_result(env, msg_ctx,RAMPART_SPR_UT_CHECKED, RAMPART_YES);
                return AXIS2_SUCCESS;
            }
            else
            {
                AXIS2_LOG_INFO(env->log, "[rampart][rampart_usernametoken] Password is not valid for user %s : status %d", username, auth_status);
                return AXIS2_FAILURE;
            }
        }
    }
    else
    {
        authenticate_with_password = rampart_context_get_auth_password_function(rampart_context,env);
        if(authenticate_with_password)
        {
            auth_status = authenticate_with_password(env,username,password);
            if(RAMPART_AUTHN_PROVIDER_GRANTED == auth_status)
            {
                AXIS2_LOG_INFO(env->log,  "[rampart][rampart_usernametoken] User authenticated");
                rampart_set_security_processed_result(env, msg_ctx,RAMPART_SPR_UT_CHECKED, RAMPART_YES);
                return AXIS2_SUCCESS;
            }
            else
            {
                AXIS2_LOG_INFO(env->log, "[rampart][rampart_usernametoken] Password is not valid for user %s : status %d", username, auth_status);
                return AXIS2_FAILURE;
            }
        }
    }
    authn_provider = rampart_context_get_authn_provider(rampart_context,env);
    /*printf("AUTHN_MODULE_NAME =%s", authn_module_name);*/
    if(authn_provider){
        AXIS2_LOG_INFO(env->log,  "[rampart][rampart_usernametoken] Password authentication using AUTH MODULE");
        auth_status = rampart_authenticate_un_pw(env, authn_provider, username, password, nonce, created, password_type, msg_ctx);
        if(RAMPART_AUTHN_PROVIDER_GRANTED == auth_status){
            AXIS2_LOG_INFO(env->log,  "[rampart][rampart_usernametoken] User authenticated");
            rampart_set_security_processed_result(env, msg_ctx,RAMPART_SPR_UT_CHECKED, RAMPART_YES);
            return AXIS2_SUCCESS;
        }else{
            AXIS2_LOG_INFO(env->log, "[rampart][rampart_usernametoken] Password is not valid for user %s : status %d", username, auth_status);
            return AXIS2_FAILURE;
        }

    }else{
        /*Auth module is NULL. Use Callback password*/
        /*First we must check the password in rampart_context.*/
        password_from_svr = rampart_context_get_password(rampart_context,env);

        /*If not then check the call  back function*/
        if(!password_from_svr)
        {
            password_function = rampart_context_get_pwcb_function(rampart_context,env);
            if(password_function)
            {
                param = rampart_context_get_ctx(rampart_context,env);
                if(!param)
                {
                    AXIS2_LOG_INFO(env->log,"[rampart][rampart_usernametoken] Param is NULL");
                    return AXIS2_FAILURE;
                }
                password_from_svr = (*password_function)(env,username,param);
            }
            else
            {
                password_callback = rampart_context_get_password_callback(rampart_context,env);
                if(!password_callback){
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[rampart][rampart_usernametoken] Password callback module is not specified");
                    return AXIS2_FAILURE;
                }
                AXIS2_LOG_INFO(env->log,  "[rampart][rampart_usernametoken] Password authentication using CALLBACK MODULE ");
                /*password_from_svr = rampart_callback_password(env, pw_callback_module, username, ctx);*/
                password_from_svr = rampart_callback_password(env, password_callback, username);
            }
        }

        if (!password_from_svr)
        {
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[rampart][rampart_usernametoken] Cannot get the password for user %s", username);
            return AXIS2_FAILURE;
        }

        /*Alright NOW we have the password. Is digest needed?*/
        if (0 == axutil_strcmp(password_type, RAMPART_PASSWORD_DIGEST_URI))
        {
            AXIS2_LOG_INFO(env->log,  "[rampart][rampart_usernametoken] Generating digest to compare from the password");
            password_to_compare = rampart_crypto_sha1(env, nonce, created, password_from_svr);
            rampart_set_security_processed_result(env, msg_ctx, RAMPART_SPR_UT_PASSWORD_TYPE, RAMPART_PASSWORD_DIGEST_URI);
        }else{
            password_to_compare = password_from_svr;
            rampart_set_security_processed_result(env, msg_ctx, RAMPART_SPR_UT_PASSWORD_TYPE, RAMPART_PASSWORD_TEXT_URI);
        }

        /*The BIG moment. Compare passwords*/
        if (0 == axutil_strcmp(password_to_compare , password))
        {
            AXIS2_LOG_INFO(env->log,  "[rampart][rampart_usernametoken] Password comparison SUCCESS");
            rampart_set_security_processed_result(env, msg_ctx,RAMPART_SPR_UT_CHECKED, RAMPART_YES);
            return AXIS2_SUCCESS;
        }else{
            AXIS2_LOG_INFO(env->log, "[rampart][rampart_usernametoken] Password is not valid for user %s", username);
            return AXIS2_FAILURE;
        }
    }
}
