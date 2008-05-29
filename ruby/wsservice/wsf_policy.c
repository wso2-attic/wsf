/*
 * Copyright 2005,2008 WSO2, Inc. http://wso2.com
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
#ifdef WIN32
	#include "winsock2.h"   // hack to avoid errors winsock redefinitions
#endif
#include "ruby.h"
#include <axis2_addr.h>
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


axiom_node_t *wsf_create_policy_node (
    const axutil_env_t * env,
    axiom_node_t * node);


axis2_char_t *WSF_CALL wsf_password_provider_function (
    const axutil_env_t * env,
    const axis2_char_t * username,
    void *ctx);

char *wsf_get_rampart_token_value(char *token_ref);

axiom_node_t *
wsf_str_to_axiom_node(const axutil_env_t *env,
                       char               *container,
                       int                 size);


axiom_node_t *
wsf_hash_to_axiom_node (axutil_env_t * env,
                        VALUE policy);

axis2_status_t
wsf_set_security_token_to_rampart_context(const axutil_env_t * env,
                                                rampart_context_t *rampart_context,
                                                VALUE security_token);

int
wsf_policy_handle_server_security (
    VALUE sec_token,
    VALUE policy,
    axutil_env_t * env,
    axis2_svc_t * svc,
    axis2_conf_t * conf)
{
    axiom_node_t *outgoing_policy_node = NULL;
    axiom_node_t *incoming_policy_node = NULL;
    int is_multiple_flow = AXIS2_FALSE;

    rampart_context_t *rampart_ctx = NULL;

    axutil_param_t *security_param = NULL;

    char *policy_xml = NULL;

    axiom_element_t *root_ele = NULL;
    axis2_desc_t *desc = NULL;
    axis2_policy_include_t *policy_include = NULL;
    
    char* policy_str = NULL;
    VALUE policy_string = Qnil;

    if ((sec_token == Qnil) && (policy == Qnil) && !svc && !conf)
        return AXIS2_FAILURE;

   	policy_string = rb_funcall(policy, rb_intern("get_policy"), 0);
   
	//if (!NIL_P(policy_string) && (TYPE(policy_string) == T_STRING))
	if (!NIL_P(policy_string))
   	{
        int length = -1;
		policy_str = RSTRING(policy_string)->ptr;
		length = RSTRING(policy_string)->len;

        incoming_policy_node = wsf_str_to_axiom_node(env, policy_str, length);
   	}
	else
	{	
		incoming_policy_node = wsf_hash_to_axiom_node(env, policy);
	}

    /* get the values from the security token object and keep it in a
       temperary structre */

	rampart_ctx = rampart_context_create (env);

	wsf_set_security_token_to_rampart_context(env, rampart_ctx, sec_token);

    if (incoming_policy_node) 
	{
        if (axiom_node_get_node_type (incoming_policy_node, env) == AXIOM_ELEMENT) 
		{
			root_ele = (axiom_element_t *)axiom_node_get_data_element (incoming_policy_node, env);
			if (root_ele) 
			{
                neethi_policy_t *neethi_policy = NULL;
                neethi_policy = neethi_engine_get_policy (env, incoming_policy_node, root_ele);
                
              	if (!neethi_policy) {
                    printf ("policy creation failed");
                    return AXIS2_FAILURE;
                }
                
				if (!svc) {
                    printf ("Service is NULL");
                    return AXIS2_FAILURE;
                }
                
				desc = axis2_svc_get_base (svc, env);
                
				if (!desc) {
                    printf ("Description is NULL");
                    return AXIS2_FAILURE;
                }
                
				policy_include = axis2_desc_get_policy_include (desc, env);
                
				if (!policy_include) {
                    printf ("Policy include is NULL");
                    return AXIS2_FAILURE;
                }
                
				axis2_policy_include_add_policy_element (policy_include, env, AXIS2_SERVICE_POLICY, neethi_policy);
				security_param =
                    axutil_param_create (env, WS_RAMPART_CONFIGURATION,
                    (void *) rampart_ctx);
                axis2_svc_add_param (svc, env, security_param);

            }
        }
    }

    /** engage module rampart */
    wsf_util_engage_module (conf, "rampart", env, svc);

    return AXIS2_SUCCESS;
}

axiom_node_t *
wsf_str_to_axiom_node(const axutil_env_t *env,
                       char               *container,
                       int                 size)
{
	axiom_xml_reader_t *xml_reader = NULL;
	axiom_stax_builder_t *stax_builder = NULL;
	axiom_document_t *document = NULL;
	axiom_node_t *axiom_node = NULL;
   xml_reader= axiom_xml_reader_create_for_memory(env, container, size, "utf-8", AXIS2_XML_PARSER_TYPE_BUFFER);
  if (xml_reader == NULL)
    return NULL;

   stax_builder= axiom_stax_builder_create(env, xml_reader);
  if (stax_builder == NULL)
    return NULL;

   document = axiom_stax_builder_get_document(stax_builder, env);
  if (document == NULL)
    return NULL;

  axiom_node = axiom_document_get_root_element(document, env);
  if (axiom_node == NULL)
    return NULL;

  axiom_document_build_all(document, env);

  axiom_stax_builder_free_self(stax_builder, env);

  return axiom_node;
}

axis2_status_t
wsf_set_security_token_to_rampart_context(const axutil_env_t * env,
                                                rampart_context_t *rampart_context,
                                                VALUE security_token)
{
   char* prv_key = NULL;
   VALUE private_key = Qnil;
   char* certificate = NULL;
   VALUE cert = Qnil;
   char* receiver_certificate = NULL;
   VALUE rec_cert = Qnil;
   char* username = NULL;
   VALUE usr = Qnil;
   char* password = NULL;
   VALUE pwd = Qnil;
   char* password_type = NULL;
   VALUE pwd_type = Qnil;
   int ttl = -1;
   VALUE time_to_live = Qnil;
   char* callback_function_name = NULL;
   VALUE callback_fn = Qnil;

   private_key = rb_funcall(security_token, rb_intern("option"), 1, rb_str_new2("private_key"));
   if (!NIL_P(private_key) && (TYPE(private_key) == T_STRING))
   {
        prv_key = RSTRING(private_key)->ptr;
 
        if ((prv_key != NULL) && (rampart_context_set_prv_key(rampart_context, env, (void *)prv_key) == AXIS2_SUCCESS))
                AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy] setting pvt key  ");
   
        if ((prv_key != NULL) && (rampart_context_set_prv_key_type(rampart_context, env, AXIS2_KEY_TYPE_PEM) == AXIS2_SUCCESS))
                AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy] setting pvt key format ");
   }

   cert = rb_funcall(security_token, rb_intern("option"), 1, rb_str_new2("certificate"));
   if (!NIL_P(cert) && (TYPE(cert) == T_STRING))
   {
        certificate = RSTRING(cert)->ptr;

        if ((certificate != NULL) && (rampart_context_set_certificate(rampart_context, env, (void *)certificate) == AXIS2_SUCCESS))
                AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy] setting pub key  ");

        if ((certificate != NULL) && (rampart_context_set_certificate_type(rampart_context, env, AXIS2_KEY_TYPE_PEM) == AXIS2_SUCCESS))
                AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy] setting pub key type ");
   }

   rec_cert = rb_funcall(security_token, rb_intern("option"), 1, rb_str_new2("receiver_certificate"));
   if (!NIL_P(rec_cert) && (TYPE(rec_cert) == T_STRING))
   {
        receiver_certificate = RSTRING(rec_cert)->ptr;

        if ((receiver_certificate != NULL) && (rampart_context_set_receiver_certificate(rampart_context, env, receiver_certificate) == AXIS2_SUCCESS))
                AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy] setting receiver pub key");

        if ((receiver_certificate != NULL) && (rampart_context_set_receiver_certificate_type(rampart_context, env, AXIS2_KEY_TYPE_PEM) == AXIS2_SUCCESS)) 
                AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy] setting receiver pub key format");
   }

   usr = rb_funcall(security_token, rb_intern("option"), 1, rb_str_new2("user"));
   if (!NIL_P(usr) && (TYPE(usr) == T_STRING))
   {
        username = RSTRING(usr)->ptr;

        if ((username != NULL) && (rampart_context_set_user(rampart_context, env, username) == AXIS2_SUCCESS)) 
                AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy] setting username ");
   }

   pwd = rb_funcall(security_token, rb_intern("option"), 1, rb_str_new2("password"));
   if (!NIL_P(pwd) && (TYPE(pwd) == T_STRING))
   {
        password = RSTRING(pwd)->ptr;

        if ((password != NULL) && (rampart_context_set_password(rampart_context, env, password) == AXIS2_SUCCESS)) 
                AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy] setting password ");
   }

   pwd_type = rb_funcall(security_token, rb_intern("option"), 1, rb_str_new2("password_type"));
   if (!NIL_P(pwd_type) && (TYPE(pwd_type) == T_STRING))
   {
        password_type = RSTRING(pwd_type)->ptr;

        if ((password_type != NULL) && (rampart_context_set_password_type(rampart_context, env, password_type) == AXIS2_SUCCESS))
                AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy] setting password type ");
   }

   callback_fn = rb_funcall(security_token, rb_intern("option"), 1, rb_str_new2("password_callback"));
   if (!NIL_P(callback_fn) && (TYPE(callback_fn) == T_STRING))
   {
 		callback_function_name = RSTRING(callback_fn)->ptr;
                          
		if (rampart_context_set_pwcb_function (rampart_context, env, wsf_password_provider_function, (void *)callback_function_name) == AXIS2_SUCCESS)
         	AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, "[wsf_sec_policy]setting callback function");
   }

   time_to_live = rb_funcall(security_token, rb_intern("option"), 1, rb_str_new2("ttl"));
   if (!NIL_P(time_to_live) && (TYPE(time_to_live) == T_FIXNUM))
   {
        ttl = FIX2INT(time_to_live);

        if (rampart_context_set_ttl(rampart_context, env, ttl) == AXIS2_SUCCESS) 
                AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy) setting ttl");
   }

   return AXIS2_SUCCESS;
}

axiom_node_t *
wsf_hash_to_axiom_node (axutil_env_t * env,
						VALUE policy)
{
    neethi_options_t *neethi_options = NULL;
    axiom_node_t *return_node = NULL;
    
	VALUE time_stamp;
	VALUE username_token;
	VALUE encryption;
	VALUE algorithm;
	VALUE sign;
	VALUE token_reference;
	VALUE encrypt_signature;
	VALUE protection_order;
	
	char* ts = NULL;
 	char* ut = NULL;
	char* encrypt = NULL;
	char* algo_suite = NULL;
	char* sg = NULL;
	char* tkn = NULL;
	char* token_ref = NULL;
	char* encrypt_sign = NULL;
	char* order = NULL;
	

    if (policy == Qnil)
        return NULL;
	
    AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
        "[wsf_policy] Creating the policy node");
    neethi_options = neethi_options_create (env);
  
    if (neethi_options) 
	{
      	time_stamp = rb_funcall(policy, rb_intern("option"), 1, rb_str_new2(WS_TIMESTAMP));
	
		if (!NIL_P(time_stamp) && (TYPE(time_stamp) == T_STRING))
		{
			ts = RSTRING(time_stamp)->ptr;
			
			if ((ts != NULL) 
				/*&& (strcmp(ts, "true") == 0)*/
				&& (neethi_options_set_include_timestamp (neethi_options, env, AXIS2_TRUE)))
					AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy] timestamp_enabled ");
		}
		
		username_token = rb_funcall(policy, rb_intern("option"), 1, rb_str_new2(WS_UT));
		
		if (!NIL_P(username_token) && (TYPE(username_token) == T_STRING))
        {   
            ut = RSTRING(username_token)->ptr;
            if ((ut != NULL)
				/*&& (strcmp(ut, "true") == 0)*/
				&& neethi_options_set_is_username_token (neethi_options, env, AXIS2_TRUE))
                	AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, "[wsf_sec_policy] token reference_enabled ");
        }

		encryption = rb_funcall(policy, rb_intern("option"), 1, rb_str_new2(WS_ENCRYPT));
        
		if (!NIL_P(encryption) && (TYPE(encryption) == T_STRING))
        { 
            encrypt = RSTRING(encryption)->ptr;

            if ((encrypt != NULL)
                /*&& (strcmp(encrypt, "true") == 0)*/
                && neethi_options_set_encrypt_body (neethi_options, env, AXIS2_TRUE))
                	AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, "[wsf_sec_policy] encrypt_enabled ");
        }

		algorithm = rb_funcall(policy, rb_intern("option"), 1, rb_str_new2(WS_ALGORITHM));

        if (!NIL_P(algorithm) && (TYPE(algorithm) == T_STRING))
        {
            algo_suite = RSTRING(algorithm)->ptr;
			
			if (algo_suite != NULL)
			{
				if (neethi_options_set_algorithmsuite (neethi_options, env, algo_suite))
	                AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, "[wsf_sec_policy] algorithmSuite_enabled ");
			}
		}
				 
        sign = rb_funcall(policy, rb_intern("option"), 1, rb_str_new2(WS_SIGN));
   		
		if (!NIL_P(sign) && (TYPE(sign) == T_STRING))
        {
		 	sg = RSTRING(sign)->ptr;

			if ((sg != NULL)
                /*&& (strcmp(sg, "true") == 0)*/
                && neethi_options_set_sign_body (neethi_options, env, AXIS2_TRUE))
                	AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, "[wsf_sec_policy] sign_enabled ");
        }

		token_reference = rb_funcall(policy, rb_intern("option"), 1, rb_str_new2(WS_TOKEN_REFERENCE));

		if (!NIL_P(token_reference) && (TYPE(token_reference) == T_STRING))
        {
            tkn = RSTRING(token_reference)->ptr;
            if (tkn != NULL)
			{
				token_ref = wsf_get_rampart_token_value(tkn);

            	if (neethi_options_set_keyidentifier (neethi_options, env, token_ref))
                	AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, "[wsf_sec_policy] token_ref_enabled ");
			}
        }
       
		encrypt_signature = rb_funcall(policy, rb_intern("option"), 1, rb_str_new2(WS_ENCRYPT_SIGNATURE)); 
		
		if (!NIL_P(encrypt_signature) && (TYPE(encrypt_signature) == T_STRING))
		{
			encrypt_sign = RSTRING(encrypt_signature)->ptr;
            if ((encrypt_sign != NULL)
				/*&& (strcmp(encrypt_sign, "true") == 0)*/
				&& neethi_options_set_signature_protection(neethi_options, env, AXIS2_TRUE))
                	AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                                 "[wsf_sec_policy] encrypt_sign_enabled ");
        }

		protection_order = rb_funcall(policy, rb_intern("option"), 1, rb_str_new2(WS_PROTECTION_ORDER));	

		if (!NIL_P(protection_order) && (TYPE(protection_order) == T_STRING))
        {
            order = RSTRING(protection_order)->ptr;

            if (order != NULL)
            {
				if(strcmp(order, ENCRYPT_BEFORE) == 0)
				{
					if (neethi_options_set_encrypt_before_sign (neethi_options, env, AXIS2_TRUE))
						AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, "[wsf_sec_policy]  encrypt_before_sign_enabled");
				}
				else if(strcmp(order, SIGN_BEFORE) == 0)
				{
					if (neethi_options_set_encrypt_before_sign (neethi_options, env, AXIS2_FALSE))
						AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, "[wsf_sec_policy]  sign_before_encrption_enabled");
				}
				else
				{
					AXIS2_LOG_ERROR (env->log, AXIS2_LOG_SI, "[wsf_sec_policy] Wrong option for protection order");
				}	
			}
		}
    }
 	
    if (neethi_options) {
        return_node = neethi_options_get_root_node (neethi_options, env);
    }
    return return_node;
}

axis2_char_t *WSF_CALL
wsf_password_provider_function (
    const axutil_env_t * env,
    const axis2_char_t * username,
    void *ctx)
{
	VALUE method_exists;
	VALUE res;
	char* op_name = (char *)ctx;
    method_exists = rb_funcall(rb_cObject, rb_intern("respond_to?"), 2, rb_str_new2(op_name), Qtrue);

    if(method_exists == Qtrue)
    {
        res = rb_funcall(T_NIL, rb_intern(op_name), 1, rb_str_new2((char*)username));
    }
    else
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[wsf log ]The method %s doesnt exist", op_name);

        return NULL;
    }


    if ((res != Qnil) && (TYPE(res) == T_STRING))
    {
		char* passwd = (RSTRING(res)->ptr);
		return (axis2_char_t *)passwd;	
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









