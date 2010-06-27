/*
 * Copyright 2005,2010 WSO2, Inc. http://wso2.com
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

#include "wsf.h"
#include "wsf_util.h"
#include <axis2_addr.h>
#include <axutil_error_default.h>
#include <axis2_http_transport.h>
#include <axutil_log_default.h>
#include <axutil_uuid_gen.h>
#include <axiom_util.h>
#include <axis2_http_header.h>
#include "wsf_client.h"
#include "wsf_policy.h"
#include "zend_exceptions.h"
#include "zend_variables.h"
#include <sandesha2_client.h>

axiom_xml_reader_t*wsf_client_get_reader_from_zval (
    zval ** param,
    axutil_env_t * env TSRMLS_DC);

int wsf_client_set_addressing_options_to_options (
    axutil_env_t * env,
    axis2_options_t * options,
    HashTable * ht TSRMLS_DC);

void wsf_client_handle_outgoing_attachments (
    axutil_env_t * env,
    HashTable * msg_ht,
    zval * msg,
    HashTable * client_ht,
    axiom_node_t * request_payload,
    axis2_options_t * options TSRMLS_DC);

int wsf_client_handle_incoming_attachments (
    axutil_env_t * env,
    HashTable * client_ht,
    zval * msg,
    axiom_soap_envelope_t * soap_envelope,
    axiom_node_t *response_payload TSRMLS_DC);

void wsf_client_set_security_options (
    HashTable * client_ht,
    HashTable * msg_ht,
    axutil_env_t * env,
    axis2_options_t * client_options,
    axis2_svc_client_t * svc_client TSRMLS_DC);

int wsf_client_get_rm_version (
    HashTable * ht TSRMLS_DC);

int wsf_client_set_soap_action (
    HashTable * client_ht,
    HashTable * msg_ht,
    axutil_env_t * env,
    axis2_options_t * client_options TSRMLS_DC);

int wsf_client_set_timeout(
    HashTable *client_ht,
    axutil_env_t *env,
    axis2_options_t *client_options TSRMLS_DC);
    
void wsf_client_set_http_headers (
    HashTable * client_ht,
    HashTable * msg_ht,
    axutil_env_t * env,
    axis2_options_t * client_options,
    axis2_svc_client_t * svc_client TSRMLS_DC);

int is_addr_action_present_in_options(
	HashTable *msg_ht, 
	HashTable *client_ht TSRMLS_DC);

int wsf_client_set_timeout(
    HashTable *client_ht,
    axutil_env_t *env,
    axis2_options_t *client_options TSRMLS_DC)
{
    zval **tmp = NULL;
    if(zend_hash_find(client_ht, WSF_TIMEOUT, sizeof(WSF_TIMEOUT), (void**)&tmp) == SUCCESS){
        return axis2_options_set_timeout_in_milli_seconds(client_options, env,1000* Z_LVAL_PP(tmp));
    }else{
        return 0;
    }
}

int is_addr_action_present_in_options(
	HashTable *msg_ht, 
	HashTable *client_ht TSRMLS_DC)
{
	zval **tmp;
	if (msg_ht
        && zend_hash_find (msg_ht, WSF_ACTION, sizeof (WSF_ACTION),
		(void **) &tmp) == SUCCESS && Z_TYPE_PP(tmp) == IS_STRING) {
			return AXIS2_TRUE;
	} else if (client_ht
        && zend_hash_find (client_ht, WSF_ACTION, sizeof (WSF_ACTION),
		(void **) &tmp) == SUCCESS && Z_TYPE_PP(tmp) == IS_STRING) {
			return AXIS2_TRUE;
	}
	return AXIS2_FALSE;
}

int
wsf_client_set_soap_action (
    HashTable * client_ht,
    HashTable * msg_ht,
    axutil_env_t * env,
    axis2_options_t * client_options TSRMLS_DC)
{
    zval **tmp;
    char *action = NULL;
    if (!client_options)
        return 0;

    if (msg_ht
        && zend_hash_find (msg_ht, WSF_ACTION, sizeof (WSF_ACTION),
            (void **) &tmp) == SUCCESS) {
        action = Z_STRVAL_PP (tmp);
    } else if (client_ht
        && zend_hash_find (client_ht, WSF_ACTION, sizeof (WSF_ACTION),
            (void **) &tmp) == SUCCESS) {
        action = Z_STRVAL_PP (tmp);
    }
    if (action) {
        axutil_string_t *action_string = axutil_string_create (env, action);
        axis2_options_set_soap_action (client_options, env, action_string);
    }
    return AXIS2_SUCCESS;
}

void
wsf_client_send_terminate_sequence (
    axutil_env_t * env,
    int will_continue_sequence,
    int rm_spec_version,
    char *sequence_key,
    axis2_svc_client_t * svc_client)
{
    if (!will_continue_sequence && rm_spec_version == WSF_RM_VERSION_1_1) 
	{
        {
			sandesha2_client_close_seq_with_svc_client(env, svc_client, NULL);
            sandesha2_client_terminate_seq_with_svc_client(env, svc_client, NULL);
        }
    }
}

int
wsf_client_get_rm_version (
    HashTable * ht TSRMLS_DC)
{
    zval **tmp;
    if (zend_hash_find (ht, WSF_RELIABLE, sizeof (WSF_RELIABLE),
            (void **) &tmp) == SUCCESS) {
        if (Z_TYPE_PP (tmp) == IS_BOOL && Z_BVAL_PP (tmp) == 1) {
            return WSF_RM_VERSION_1_0;
        } else if (Z_TYPE_PP (tmp) == IS_STRING
            && strcmp (Z_STRVAL_PP (tmp), "1.1") == 0) {
            return WSF_RM_VERSION_1_1;
        } else if (Z_TYPE_PP (tmp) == IS_STRING
            && strcmp (Z_STRVAL_PP (tmp), "1.0") == 0) {
            return WSF_RM_VERSION_1_0;
        } else if (Z_TYPE_PP (tmp) == IS_DOUBLE && Z_DVAL_PP (tmp) == 1.1) {
            return WSF_RM_VERSION_1_1;
        } else if (Z_TYPE_PP (tmp) == IS_DOUBLE && Z_DVAL_PP (tmp) == 1.0) {
            return WSF_RM_VERSION_1_0;
        }
    }
    return -1;
}


void
wsf_client_set_security_options (
    HashTable * client_ht,
    HashTable * msg_ht,
    axutil_env_t * env,
    axis2_options_t * client_options,
    axis2_svc_client_t * svc_client TSRMLS_DC)
{
    zval **tmp = NULL;
    zval *sec_token = NULL;
    zval *policy = NULL;


    if (zend_hash_find (client_ht, WSF_SECURITY_TOKEN,
            sizeof (WSF_SECURITY_TOKEN), (void **) &tmp) == SUCCESS
        && Z_TYPE_PP (tmp) == IS_OBJECT) {
        sec_token = *tmp;
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
			"wsf_client_set_security_options :- Security token object found ");
    }
    if (zend_hash_find (client_ht, WSF_POLICY_NAME, sizeof (WSF_POLICY_NAME),
            (void **) &tmp) == SUCCESS) {
        policy = *tmp;
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
            " Policy object found ");
    }

    if (sec_token) {
        wsf_policy_handle_client_security (sec_token, policy, env,
            svc_client TSRMLS_CC);
    }
}

int 
wsf_client_handle_incoming_attachments (
    axutil_env_t * env,
    HashTable * client_ht,
    zval * msg,
    axiom_soap_envelope_t * soap_envelope,
    axiom_node_t *response_payload TSRMLS_DC)
{
    zval **tmp = NULL;
	int attachments_found = 0;
    zval *cid2str = NULL;
    zval *cid2content_type = NULL;
            
    int response_xop = 0;
    
	if (!client_ht)
        return 0;

    AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
        "handle incoming attachments");

    if (client_ht && zend_hash_find (client_ht, WSF_RESPONSE_XOP, sizeof (WSF_RESPONSE_XOP),
		(void **) &tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_BOOL)
	{
        response_xop = Z_BVAL_PP (tmp);
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
            "responseXOP %d", response_xop);
    }

    if (response_xop == 1) 
	{

        MAKE_STD_ZVAL(cid2str);
        INIT_PZVAL(cid2str);
        MAKE_STD_ZVAL(cid2content_type);
        INIT_PZVAL(cid2content_type);

        array_init (cid2str);
        array_init (cid2content_type);

        attachments_found = wsf_util_get_attachments_from_soap_envelope(env,
                        soap_envelope, cid2str, cid2content_type TSRMLS_CC);

        add_property_zval (msg, WSF_ATTACHMENTS, cid2str);
        add_property_zval (msg, WSF_CID2CONTENT_TYPE, cid2content_type);
        zval_ptr_dtor(&cid2str);
        zval_ptr_dtor(&cid2content_type);

	}else if(response_xop == 0)
	{
		wsf_util_find_xop_content_and_convert_to_base64(env, response_payload);
	}
	return attachments_found;
}


void
wsf_client_handle_outgoing_attachments (
    axutil_env_t * env,
    HashTable * msg_ht,
    zval * msg,
    HashTable * client_ht,
    axiom_node_t * request_payload,
    axis2_options_t * options TSRMLS_DC)
{
    axis2_char_t *default_cnt_type = NULL;
    zval **tmp;
    HashTable *ht = NULL;
    /** default value for mtom is true */
    int enable_mtom = AXIS2_TRUE;
    int enable_swa = AXIS2_FALSE;

    if (!msg_ht)
        return;

    if (zend_hash_find (msg_ht, WSF_DEFAULT_ATTACHEMENT_CONTENT_TYPE,
            sizeof (WSF_DEFAULT_ATTACHEMENT_CONTENT_TYPE),
            (void **) &tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_STRING)
	{
        default_cnt_type = Z_STRVAL_PP (tmp);
    } else 
	{
        default_cnt_type = AXIOM_MIME_TYPE_OCTET_STREAM;
    }
    if (client_ht && zend_hash_find (client_ht, WSF_USE_MTOM, sizeof (WSF_USE_MTOM),
            (void **) &tmp) == SUCCESS) 
	{
        if (Z_TYPE_PP (tmp) == IS_BOOL && Z_BVAL_PP (tmp) == 0) 
		{
            enable_mtom = AXIS2_FALSE;
        } else if (Z_TYPE_PP (tmp) == IS_STRING) 
		{
            char *value = NULL;
            value = Z_STRVAL_PP (tmp);
            /* Check if SOAP with Attachments (SwA) has been enabled */
            if (value && (strcasecmp(value, WSF_SWA) == 0)) 
			{
                AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX "SwA enabled");
                enable_swa = AXIS2_TRUE;
            } 
        }
    }

    if (zend_hash_find (msg_ht, WSF_ATTACHMENTS, sizeof (WSF_ATTACHMENTS),
            (void **) &tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_ARRAY)
	{
        ht = Z_ARRVAL_PP (tmp);
    } else if (zend_hash_find (Z_OBJPROP_P (msg), WSF_ATTACHMENTS,
            sizeof (WSF_ATTACHMENTS), (void **) &tmp) == SUCCESS) 
	{
        ht = Z_ARRVAL_PP (tmp);
    } else return;

    axis2_options_set_enable_mtom (options, env, enable_mtom);

    AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX "Enable MTOM is %d", enable_mtom);


    if (ht) 
	{
        wsf_util_set_attachments_with_cids (env, enable_mtom, enable_swa, request_payload,
            ht, default_cnt_type TSRMLS_CC);
    }
}

int
wsf_client_set_addressing_options_to_options (
    axutil_env_t * env,
    axis2_options_t * client_options,
    HashTable * ht TSRMLS_DC)
{
    zval **tmp = NULL;
    int addr_action_present = AXIS2_FALSE;

    if (!ht)
        return 0;

    if (zend_hash_find (ht, WSF_ACTION, sizeof (WSF_ACTION),
            (void **) &tmp) == SUCCESS) {

        axis2_options_set_action (client_options, env, Z_STRVAL_PP (tmp));
        addr_action_present = AXIS2_TRUE;

        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
            "Addressing action is :- %s", Z_STRVAL_PP (tmp));

    }
    if (zend_hash_find (ht, WSF_REPLY_TO, sizeof (WSF_REPLY_TO),
            (void **) &tmp) == SUCCESS) 
	{

        axis2_endpoint_ref_t *replyto_epr = NULL;
		if(Z_TYPE_PP(tmp) == IS_STRING)
		{
			char *replyto = Z_STRVAL_PP (tmp);
		    replyto_epr = axis2_endpoint_ref_create (env, replyto);
			AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
				"Addressing replyTo is :- %s", replyto);
		}
		else if(Z_TYPE_PP(tmp) == IS_ARRAY)
		{
			replyto_epr = wsf_util_set_values_to_endpoint_ref(env, Z_ARRVAL_PP(tmp) TSRMLS_CC);
		}
        axis2_options_set_reply_to (client_options, env, replyto_epr);
    }

    if (zend_hash_find (ht, WSF_FAULT_TO, sizeof (WSF_FAULT_TO),
            (void **) &tmp) == SUCCESS) {

        axis2_endpoint_ref_t *faultto_epr = NULL;
		if(Z_TYPE_PP(tmp) == IS_STRING)
		{
			char *faultto = Z_STRVAL_PP (tmp);

			faultto_epr = axis2_endpoint_ref_create (env, faultto);
		
			AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
				"faultTo is %s", faultto);
		}else if(Z_TYPE_PP(tmp) == IS_ARRAY)
		{
			faultto_epr = wsf_util_set_values_to_endpoint_ref(env, Z_ARRVAL_PP(tmp)  TSRMLS_CC);
		}
		axis2_options_set_fault_to (client_options, env, faultto_epr);

    }
    if (zend_hash_find (ht, WSF_FROM, sizeof (WSF_FROM),
            (void **) &tmp) == SUCCESS) 
	{
        axis2_endpoint_ref_t *from_epr = NULL;
		if(Z_TYPE_PP(tmp) == IS_STRING)
		{
			char *from = Z_STRVAL_PP (tmp);
			from_epr = axis2_endpoint_ref_create (env, from);
			AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,WSF_PHP_LOG_PREFIX \
				"from is  %s", from);
		}else if(Z_TYPE_PP(tmp) == IS_ARRAY)
		{
			from_epr = wsf_util_set_values_to_endpoint_ref(env, Z_ARRVAL_PP(tmp) TSRMLS_CC);
		}
        axis2_options_set_from (client_options, env, from_epr);
    }
	if (zend_hash_find (ht, WSF_ADDR_MUST_UNDERSTAND, sizeof (WSF_ADDR_MUST_UNDERSTAND),
		(void **) &tmp) == SUCCESS && Z_TYPE_PP(tmp) == IS_BOOL && Z_BVAL_PP(tmp) == 1) 
	{
		axutil_property_t *must_understand_prop = axutil_property_create_with_args(env, AXIS2_SCOPE_REQUEST, AXIS2_FALSE,
			NULL, AXIS2_VALUE_TRUE);
		if(must_understand_prop)
			axis2_options_set_property(client_options, env, AXIS2_ADDR_ADD_MUST_UNDERSTAND_TO_ADDR_HEADERS, must_understand_prop);
	}
    return addr_action_present;
}

axiom_xml_reader_t *
wsf_client_get_reader_from_zval (
    zval ** param,
    axutil_env_t * env TSRMLS_DC)
{
    axis2_char_t *str_payload = NULL;
    int str_payload_len = 0;
    axiom_xml_reader_t *reader = NULL;
    if (Z_TYPE_PP (param) == IS_STRING) 
	{
        str_payload = Z_STRVAL_PP (param);
        str_payload_len = Z_STRLEN_PP (param);
        reader = axiom_xml_reader_create_for_memory (env,  str_payload, 
			str_payload_len, AXIS2_UTF_8, AXIS2_XML_PARSER_TYPE_BUFFER);

    }
    if (!reader) {
		AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
			"XML Reader creation failed The input string payload is either null or malformed");
	}
    return reader;
}

void
wsf_client_add_properties (
    zval * this_ptr,
    HashTable * ht TSRMLS_DC)
{
    zval **tmp = NULL;
    /** use soap */
    if (zend_hash_find (ht, WSF_USE_SOAP, sizeof (WSF_USE_SOAP),
            (void **) &tmp) == SUCCESS) 
	{
        if (Z_TYPE_PP (tmp) == IS_STRING) 
		{
            add_property_stringl (this_ptr, WSF_USE_SOAP, Z_STRVAL_PP (tmp),
                Z_STRLEN_PP (tmp), 1);
        } else if (Z_TYPE_PP (tmp) == IS_DOUBLE) 
		{
            add_property_double (this_ptr, WSF_USE_SOAP, Z_DVAL_PP (tmp));
        } else if (Z_TYPE_PP (tmp) == IS_BOOL) 
		{
            add_property_bool (this_ptr, WSF_USE_SOAP, Z_BVAL_PP (tmp));
        }
    }
    /** HTTP Method */
    if (zend_hash_find (ht, WSF_HTTP_METHOD, sizeof (WSF_HTTP_METHOD),
            (void **) &tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_STRING) 
	{
        add_property_stringl (this_ptr, WSF_HTTP_METHOD, Z_STRVAL_PP (tmp),
            Z_STRLEN_PP (tmp), 1);
    }
    /** endpoint address */
    if (zend_hash_find (ht, WSF_TO, sizeof (WSF_TO), (void **) &tmp) == SUCCESS) 
	{
		if(Z_TYPE_PP(tmp) == IS_STRING)
		{
			add_property_stringl (this_ptr, WSF_TO, Z_STRVAL_PP (tmp), Z_STRLEN_PP (tmp), 1);
		}else if(Z_TYPE_PP(tmp) == IS_ARRAY)
		{
			add_property_zval(this_ptr, WSF_TO, *tmp);
		}
    }

	if(zend_hash_find(ht, WSF_TRANSPORT_URL, sizeof(WSF_TRANSPORT_URL), (void**)&tmp) == SUCCESS )
	{
		if(Z_TYPE_PP(tmp) == IS_STRING)
		{
			add_property_stringl(this_ptr, WSF_TRANSPORT_URL, Z_STRVAL_PP(tmp), Z_STRLEN_PP(tmp), 1);
		}
	}

	if(zend_hash_find(ht, WSF_ADDR_MUST_UNDERSTAND, sizeof(WSF_ADDR_MUST_UNDERSTAND), (void**)&tmp) == SUCCESS )
	{
		if(Z_TYPE_PP(tmp) == IS_BOOL)
		{
			add_property_bool(this_ptr, WSF_ADDR_MUST_UNDERSTAND, Z_BVAL_PP(tmp));
		}
	}
    /** addressing properties */
    if (zend_hash_find (ht, WSF_ACTION, sizeof (WSF_ACTION),
            (void **) &tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_STRING) 
	{
        add_property_stringl (this_ptr, WSF_ACTION, Z_STRVAL_PP (tmp),
            Z_STRLEN_PP (tmp), 1);
    }
    if (zend_hash_find (ht, WSF_FROM, sizeof (WSF_FROM),
            (void **) &tmp) == SUCCESS ) 
	{	
		if(Z_TYPE_PP(tmp) == IS_STRING)
		{
			add_property_stringl (this_ptr, WSF_FROM, Z_STRVAL_PP (tmp), Z_STRLEN_PP (tmp), 1);
		}else if(Z_TYPE_PP(tmp) == IS_ARRAY)
		{
			add_property_zval(this_ptr, WSF_FROM, *tmp);
		}
    }
    if (zend_hash_find (ht, WSF_REPLY_TO, sizeof (WSF_REPLY_TO),
            (void **) &tmp) == SUCCESS ) 
	{
		if(Z_TYPE_PP (tmp) == IS_STRING)
		{
			add_property_stringl (this_ptr, WSF_REPLY_TO, Z_STRVAL_PP (tmp), Z_STRLEN_PP (tmp), 1);
		}else if(Z_TYPE_PP(tmp) == IS_ARRAY)
		{
			add_property_zval(this_ptr, WSF_REPLY_TO, *tmp);
		}
    }
    if (zend_hash_find (ht, WSF_FAULT_TO, sizeof (WSF_FAULT_TO),
            (void **) &tmp) == SUCCESS ) 
	{
		if(Z_TYPE_PP (tmp) == IS_STRING)
		{
			add_property_stringl (this_ptr, WSF_FAULT_TO, Z_STRVAL_PP (tmp), Z_STRLEN_PP (tmp), 1);
		}else if(Z_TYPE_PP(tmp) == IS_ARRAY)
		{
			add_property_zval(this_ptr, WSF_FAULT_TO, *tmp);
		}
    }	
    /** SSL And proxy properties */
    if (zend_hash_find (ht, WSF_SERVER_CERT, sizeof (WSF_SERVER_CERT),
            (void **) &tmp) == SUCCESS) {
        if (Z_TYPE_PP (tmp) == IS_STRING) {
            add_property_string (this_ptr, WSF_SERVER_CERT, Z_STRVAL_PP (tmp),
                1);
        }
    }

    if (zend_hash_find (ht, WSF_CLIENT_CERT, sizeof (WSF_CLIENT_CERT),
            (void **) &tmp) == SUCCESS) {
        if (Z_TYPE_PP (tmp) == IS_STRING) {
            add_property_string (this_ptr, WSF_CLIENT_CERT, Z_STRVAL_PP (tmp),
                1);
        }
    }
    if (zend_hash_find (ht, WSF_PASSPHRASE, sizeof (WSF_PASSPHRASE),
            (void **) &tmp) == SUCCESS) {
        if (Z_TYPE_PP (tmp) == IS_STRING) {
            add_property_string (this_ptr, WSF_PASSPHRASE, Z_STRVAL_PP (tmp),
                1);
        }
    }
    if (zend_hash_find (ht, WSF_PROXY_HOST, sizeof (WSF_PROXY_HOST),
            (void **) &tmp) == SUCCESS) {
        if (Z_TYPE_PP (tmp) == IS_STRING) {
            add_property_string (this_ptr, WSF_PROXY_HOST, Z_STRVAL_PP (tmp),
                1);
        }
    }
    if (zend_hash_find (ht, WSF_PROXY_PORT, sizeof (WSF_PROXY_PORT),
            (void **) &tmp) == SUCCESS) {
        if (Z_TYPE_PP (tmp) == IS_STRING) {
            add_property_string (this_ptr, WSF_PROXY_PORT, Z_STRVAL_PP (tmp),
                1);
        }
    }

    /** use WSA */
    if (zend_hash_find (ht, WSF_USE_WSA, sizeof (WSF_USE_WSA),
            (void **) &tmp) == SUCCESS) {
        if (Z_TYPE_PP (tmp) == IS_STRING) {
            add_property_stringl (this_ptr, WSF_USE_WSA, Z_STRVAL_PP (tmp),
                Z_STRLEN_PP (tmp), 1);
        } else if (Z_TYPE_PP (tmp) == IS_BOOL) {
            add_property_bool (this_ptr, WSF_USE_WSA, Z_BVAL_PP (tmp));
        } else if (Z_TYPE_PP (tmp) == IS_DOUBLE) {
            add_property_double (this_ptr, WSF_USE_WSA, Z_DVAL_PP (tmp));
        }
    }

    /** attachments properties */
    if (zend_hash_find (ht, WSF_RESPONSE_XOP, sizeof (WSF_RESPONSE_XOP),
            (void **) &tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_BOOL) {
        add_property_bool (this_ptr, WSF_RESPONSE_XOP, Z_BVAL_PP (tmp));
    }
    if (zend_hash_find (ht, WSF_USE_MTOM, sizeof (WSF_USE_MTOM),
        (void **) &tmp) == SUCCESS) {
        if (Z_TYPE_PP (tmp) == IS_BOOL) {
          add_property_bool (this_ptr, WSF_USE_MTOM, Z_BVAL_PP (tmp));
        }
        else if (Z_TYPE_PP (tmp) == IS_STRING) {
            add_property_stringl (this_ptr, WSF_USE_MTOM, Z_STRVAL_PP (tmp),
                Z_STRLEN_PP (tmp), 1);
        } 
    }
    if (zend_hash_find (ht, WSF_DEFAULT_ATTACHEMENT_CONTENT_TYPE,
            sizeof (WSF_DEFAULT_ATTACHEMENT_CONTENT_TYPE),
            (void **) &tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_STRING) {
        add_property_stringl (this_ptr, WSF_DEFAULT_ATTACHEMENT_CONTENT_TYPE,
            Z_STRVAL_PP (tmp), Z_STRLEN_PP (tmp), 1);
    }

    /** security */

    if (zend_hash_find (ht, WSF_SECURITY_TOKEN, sizeof (WSF_SECURITY_TOKEN),
            (void **) &tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_OBJECT) {
        add_property_zval (this_ptr, WSF_SECURITY_TOKEN, *tmp);
    }
    if (zend_hash_find (ht, WSF_POLICY_NAME, sizeof (WSF_POLICY_NAME),
            (void **) &tmp) == SUCCESS && (Z_TYPE_PP (tmp) == IS_OBJECT
            || Z_TYPE_PP (tmp) == IS_ARRAY)) {
        add_property_zval (this_ptr, WSF_POLICY_NAME, *tmp);
    }

    /** RM */

    if (zend_hash_find (ht, WSF_RELIABLE, sizeof (WSF_RELIABLE),
            (void **) &tmp) == SUCCESS) {
        if (Z_TYPE_PP (tmp) == IS_BOOL) {
            add_property_bool (this_ptr, WSF_RELIABLE, Z_BVAL_PP (tmp));
        } else if (Z_TYPE_PP (tmp) == IS_STRING) {
            add_property_string (this_ptr, WSF_RELIABLE, Z_STRVAL_PP (tmp), 1);
        } else if (Z_TYPE_PP (tmp) == IS_DOUBLE) {
            add_property_double (this_ptr, WSF_RELIABLE, Z_DVAL_PP (tmp));
        }
    }
    if (zend_hash_find (ht, WSF_SEQUENCE_EXPIRY_TIME,
        sizeof (WSF_SEQUENCE_EXPIRY_TIME), (void **) &tmp) == SUCCESS) {
		if (Z_TYPE_PP (tmp) == IS_LONG) {
			add_property_long (this_ptr, WSF_SEQUENCE_EXPIRY_TIME,
				Z_LVAL_PP (tmp));
		}
    }
    if (zend_hash_find (ht, WSF_WILL_CONTINUE_SEQUENCE,
        sizeof (WSF_WILL_CONTINUE_SEQUENCE), (void **) &tmp) == SUCCESS) {
		if (Z_TYPE_PP (tmp) == IS_BOOL) {
			add_property_bool (this_ptr, WSF_WILL_CONTINUE_SEQUENCE,
				Z_BVAL_PP (tmp));
		}
    }
    if (zend_hash_find (ht, WSF_SEQUENCE_KEY, sizeof (WSF_SEQUENCE_KEY),
            (void **) &tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_STRING) {
        add_property_string (this_ptr, WSF_SEQUENCE_KEY, Z_STRVAL_PP (tmp), 1);
    }

    if (zend_hash_find (ht, WSF_RM_RESPONSE_TIMEOUT,
            sizeof (WSF_RM_RESPONSE_TIMEOUT), (void **) &tmp) == SUCCESS) {
        add_property_string (this_ptr, WSF_RM_RESPONSE_TIMEOUT,
            Z_STRVAL_PP (tmp), 1);
    }
    /** timeout */
    if(zend_hash_find(ht, WSF_TIMEOUT, sizeof(WSF_TIMEOUT), (void **)&tmp) == SUCCESS &&
            Z_TYPE_PP(tmp) == IS_LONG){
        add_property_long(this_ptr, WSF_TIMEOUT, Z_LVAL_PP(tmp));
    }


    if (zend_hash_find (ht, WSF_WSDL, sizeof (WSF_WSDL), 
        (void **) &tmp) == SUCCESS) 
	{
		if(Z_TYPE_PP (tmp) == IS_STRING)
		{
			add_property_stringl (this_ptr, WSF_WSDL, Z_STRVAL_PP (tmp),
                              Z_STRLEN_PP (tmp), 1);
		}else if(Z_TYPE_PP(tmp) == IS_ARRAY)
		{
			zval_add_ref(tmp);
			add_property_zval(this_ptr, WSF_WSDL, *tmp);
		}
    }
    
    if (zend_hash_find (ht, WSF_CLASSMAP, sizeof (WSF_CLASSMAP),
       (void **) & tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_ARRAY) {
        add_property_zval(this_ptr, WSF_CLASSMAP, *tmp);
    }

    if (zend_hash_find (ht, WSF_HTTP_AUTH_USERNAME, sizeof (WSF_HTTP_AUTH_USERNAME),
       (void **) & tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_STRING) {
        add_property_zval(this_ptr, WSF_HTTP_AUTH_USERNAME, *tmp);
    }
    if (zend_hash_find (ht, WSF_HTTP_AUTH_PASSWORD, sizeof (WSF_HTTP_AUTH_PASSWORD),
       (void **) & tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_STRING) {
        add_property_zval(this_ptr, WSF_HTTP_AUTH_PASSWORD, *tmp);
    }
    if (zend_hash_find (ht, WSF_HTTP_AUTH_TYPE, sizeof (WSF_HTTP_AUTH_TYPE),
       (void **) & tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_STRING) {
        add_property_zval(this_ptr, WSF_HTTP_AUTH_TYPE, *tmp);
    }

    if (zend_hash_find (ht, WSF_PROXY_AUTH_USERNAME, sizeof (WSF_PROXY_AUTH_USERNAME),
       (void **) & tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_STRING) {
        add_property_zval(this_ptr, WSF_PROXY_AUTH_USERNAME, *tmp);
    }
    if (zend_hash_find (ht, WSF_PROXY_AUTH_PASSWORD, sizeof (WSF_PROXY_AUTH_PASSWORD),
       (void **) & tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_STRING) {
        add_property_zval(this_ptr, WSF_PROXY_AUTH_PASSWORD, *tmp);
    }
    if (zend_hash_find (ht, WSF_PROXY_AUTH_TYPE, sizeof (WSF_PROXY_AUTH_TYPE),
       (void **) & tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_STRING) {
        add_property_zval(this_ptr, WSF_PROXY_AUTH_TYPE, *tmp);
		
    }
	if (zend_hash_find (ht, WSF_HTTP_HEADERS, sizeof (WSF_HTTP_HEADERS),
		(void **) & tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_ARRAY) {
         add_property_zval(this_ptr, WSF_HTTP_HEADERS, *tmp);
    }
}

static int
wsf_client_set_module_param_option (
    axutil_env_t * env,
    axis2_svc_client_t * svc_client,
    axis2_char_t * module_name,
    axis2_char_t * module_option,
    axis2_char_t * module_option_value)
{
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_svc_ctx_t *svc_ctx = NULL;
    axis2_module_desc_t *module_desc = NULL;
    axis2_conf_t *conf = NULL;
    axutil_qname_t *module_qname = NULL;
    axutil_param_t *param = NULL;

    module_qname = axutil_qname_create (env, module_name, NULL, NULL);

    svc_ctx = axis2_svc_client_get_svc_ctx (svc_client, env);

    conf_ctx = axis2_svc_ctx_get_conf_ctx (svc_ctx, env);

    conf = axis2_conf_ctx_get_conf (conf_ctx, env);

    module_desc = axis2_conf_get_module (conf, env, module_qname);
    if (!module_desc)
        return AXIS2_FAILURE;

    param = axis2_module_desc_get_param (module_desc, env, module_option);
    if (!param)
        return AXIS2_FAILURE;

    axutil_param_set_value (param, env, axutil_strdup (env,
            module_option_value));

    AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
        "Setting %s module param %s to %s ", module_name,
        module_option, module_option_value);
    axutil_qname_free (module_qname, env);
    return AXIS2_SUCCESS;
}




int
wsf_client_set_headers (
    const axutil_env_t * env,
    axis2_svc_client_t * svc_client,
    zval * msg TSRMLS_DC)
{
    HashTable *ht = NULL;
    axis2_options_t *options = NULL;
    axis2_char_t *soap_version_uri = NULL;
    int soap_version = AXIOM_SOAP12; 
    if (!svc_client || !msg) 
	{
        return 0;
    } 
	else 
	{

        zval **tmp = NULL;
        ht = Z_OBJPROP_P (msg);
        options = (axis2_options_t *) axis2_svc_client_get_options (svc_client, env); 
        if(!options)
            return 0;
        soap_version_uri = (axis2_char_t*)axis2_options_get_soap_version_uri(options, env);
        soap_version = axis2_options_get_soap_version(options, env);

        if (zend_hash_find (ht, WSF_INPUT_HEADERS, sizeof (WSF_INPUT_HEADERS),
                (void **) &tmp) == SUCCESS) 
		{
            if (Z_TYPE_PP (tmp) == IS_ARRAY) 
			{
                HashPosition pos;
                HashTable *ht = Z_ARRVAL_PP (tmp);
                zval **val = NULL;
                zend_hash_internal_pointer_reset_ex (ht, &pos);

                AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
                    "sending headers found");

                while (zend_hash_get_current_data_ex (ht, (void **) &val, &pos) != FAILURE) 
				{
					if(Z_TYPE_PP(val) == IS_OBJECT && instanceof_function(Z_OBJCE_PP(val), 
						ws_header_class_entry TSRMLS_CC))
				{
					zval *header = *val;
					axiom_node_t *header_node = NULL;
					header_node = wsf_util_construct_header_node (env, 
						NULL, soap_version_uri , soap_version ,header TSRMLS_CC);
					if (header_node) 
					{
						AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
							"Adding header block to svc_client");
						axis2_svc_client_add_header (svc_client, env, header_node);
					}
				}
				else
				{
				php_error_docref(NULL TSRMLS_CC, E_ERROR,"Only WSHeader type objects are accepted");
				}
                    zend_hash_move_forward_ex (ht, &pos);
				}
            }
        }
    }
    return 1;
}

int
wsf_client_set_addr_options (
    HashTable * client_ht,
    HashTable * msg_ht,
    axutil_env_t * env,
    axis2_options_t * client_options,
    axis2_svc_client_t * svc_client TSRMLS_DC)
{

    zval **tmp = NULL;
    int is_addressing_engaged = AXIS2_FALSE;
    int addr_action_present = AXIS2_FALSE;
    char *value = NULL;

    AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX "Setting addressing options");

    if (client_ht) 
	{

        if (zend_hash_find (client_ht, WSF_USE_WSA, sizeof (WSF_USE_WSA), 
			(void **) & tmp) == SUCCESS) 
		{
            if (Z_TYPE_PP (tmp) == IS_BOOL) 
			{
                if (Z_BVAL_PP (tmp) == 1) 
				{
                    value = WSF_ADDRESSING_VERSION_1_0;

                    AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
						"useWSA true, version 1.0");
                } else 
				{
                    return AXIS2_FALSE;
                }

			} else if (Z_TYPE_PP (tmp) == IS_STRING ) 
			{
                if(strcmp(WSF_ADDRESSING_SUBMISSION , Z_STRVAL_PP(tmp)) == 0)
				{ 
                    value = Z_STRVAL_PP (tmp);
                    AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
                    " useWSA is string, value is %s", value);

                }else if(strcmp(WSF_ADDRESSING_VERSION_1_0 , Z_STRVAL_PP(tmp)) == 0)
				{
                    value = Z_STRVAL_PP (tmp);
                    AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
                    "useWSA is string, value is %s", value);
                }
            } else if (Z_TYPE_PP (tmp) == IS_DOUBLE && Z_DVAL_PP (tmp) == 1.0) 
			{

                value = WSF_ADDRESSING_VERSION_1_0;

                AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
                    "useWSA is double, value is %s", value);
            }
        }
    }

	if(value)
	{
		if (msg_ht) 
		{

			AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
				"WSMessage is present, Setting options using WSMessage properties ");

			addr_action_present = 
				wsf_client_set_addressing_options_to_options (env, client_options, msg_ht TSRMLS_CC);
		} else if (client_ht) 
		{

			addr_action_present =
				wsf_client_set_addressing_options_to_options (env, client_options,
				client_ht TSRMLS_CC);
		}
	}
    if (addr_action_present == AXIS2_TRUE && value) 
	{
        is_addressing_engaged = AXIS2_TRUE;

        axis2_svc_client_engage_module (svc_client, env, WSF_MODULE_ADDRESSING);

        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX "Engaged Addressing module");

        if (strcmp (value, WSF_ADDRESSING_SUBMISSION) == 0) 
		{

            axutil_property_t *prop = axutil_property_create_with_args (env, 0, AXIS2_TRUE, 
				0, axutil_strdup (env, AXIS2_WSA_NAMESPACE_SUBMISSION));

            axis2_options_set_property (client_options, env, AXIS2_WSA_VERSION, prop);

            AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
                "Addressing version is submission");
        }
    }
    return is_addressing_engaged;
}

int
wsf_client_set_endpoint_and_soap_action (
    HashTable * client_ht,
    HashTable * msg_ht,
    axutil_env_t * env,
    axis2_options_t * client_options TSRMLS_DC)
{
    zval **msg_tmp = NULL;

    if (msg_ht && zend_hash_find (msg_ht, WSF_TO, sizeof (WSF_TO),
            (void **) &msg_tmp) == SUCCESS ) 
	{
		axis2_endpoint_ref_t *to_epr = NULL;

		if(Z_TYPE_PP(msg_tmp) == IS_STRING)
		{
			char *to = Z_STRVAL_PP (msg_tmp);
			to_epr = axis2_endpoint_ref_create (env, to);
		}else if(Z_TYPE_PP(msg_tmp) == IS_ARRAY)
		{
			to_epr = wsf_util_set_values_to_endpoint_ref(env, Z_ARRVAL_PP(msg_tmp) TSRMLS_CC);
		}
		axis2_options_set_to (client_options, env, to_epr);
    } else if (client_ht && zend_hash_find (client_ht, WSF_TO, sizeof (WSF_TO), 
		(void **) &msg_tmp) == SUCCESS && Z_TYPE_PP(msg_tmp) == IS_STRING) 
	{
		axis2_endpoint_ref_t *to_epr = NULL;
		if(Z_TYPE_PP(msg_tmp) == IS_STRING)
		{
			char *to = Z_STRVAL_PP (msg_tmp);
			to_epr = axis2_endpoint_ref_create (env, to);
		}else if(Z_TYPE_PP(msg_tmp) == IS_ARRAY)
		{
			to_epr = wsf_util_set_values_to_endpoint_ref(env, client_ht TSRMLS_CC);
		}
        axis2_options_set_to (client_options, env, to_epr);
    } else 
	{
        return AXIS2_FAILURE;
    }


	/** Set transport URL */
	if (client_ht && zend_hash_find (client_ht, WSF_TRANSPORT_URL, sizeof (WSF_TRANSPORT_URL), 
		(void **) &msg_tmp) == SUCCESS && Z_TYPE_PP(msg_tmp) == IS_STRING) 
	{

		axutil_property_t *transport_url = 
			axutil_property_create_with_args(env, AXIS2_SCOPE_REQUEST, AXIS2_FALSE, NULL, Z_STRVAL_PP(msg_tmp));
		axis2_options_set_property(client_options, env, AXIS2_TRANSPORT_URL, transport_url);

    }
	/** set soap action */
    wsf_client_set_soap_action (client_ht, msg_ht, env, client_options TSRMLS_CC);
    return AXIS2_SUCCESS;
}


int
wsf_client_set_options (
    HashTable * client_ht,
    HashTable * msg_ht,
    axutil_env_t * env,
    axis2_options_t * client_options,
    axis2_svc_client_t * svc_client,
    int *rest_enabled TSRMLS_DC)
{
    zval **tmp = NULL;
    int status = AXIS2_SUCCESS;
    int use_soap = AXIS2_TRUE;
    int soap_version = AXIOM_SOAP12;

    if (client_ht) 
	{
        if (zend_hash_find (client_ht, WSF_USE_SOAP, sizeof (WSF_USE_SOAP), 
			(void **) &tmp) == SUCCESS) 
		{
            if (Z_TYPE_PP (tmp) == IS_STRING)  
			{
                char *value = NULL;
                value = Z_STRVAL_PP (tmp);
                if (value && strcmp (value, WSF_SOAP_VERSION_1_2) == 0) 
				{
                    AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
                        "Soap version SOAP12");

                } else if (value && strcmp (value, WSF_SOAP_VERSION_1_1) == 0) 
				{

                    soap_version = AXIOM_SOAP11;
                    AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX "SOAP Version SOAP11");
                }
            } else if (Z_TYPE_PP (tmp) == IS_DOUBLE) 
			{
                double val = Z_DVAL_PP (tmp);
                if (val == 1.2) 
				{

                    AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
						"useSOAP value is 1.2 ");

                } else if (val == 1.1) 
				{

                    soap_version = AXIOM_SOAP11;
                    AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
                        "SOAP Version soap11");

                }
            } else if (Z_TYPE_PP (tmp) == IS_BOOL && Z_BVAL_PP (tmp) == 0) 
			{
                use_soap = AXIS2_FALSE;
            }
        }

        if (use_soap) {
            if (soap_version == AXIOM_SOAP11) 
			{
                WSF_GLOBAL (soap_version) = AXIOM_SOAP11;
                WSF_GLOBAL (soap_uri) = WSF_SOAP_1_1_NAMESPACE_URI;
            } else if (soap_version == AXIOM_SOAP12) 
			{
                WSF_GLOBAL (soap_version) = AXIOM_SOAP12;
				WSF_GLOBAL (soap_uri) = WSF_SOAP_1_2_NAMESPACE_URI;
            }

            axis2_options_set_soap_version (client_options, env, soap_version);
            AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
                "useSOAP TRUE setting soap version %d", soap_version);
        } else 
		{
			/*
            axutil_property_t *rest_property = NULL;

            AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
                "useSOAP FALSE enabling rest ");

            rest_property = axutil_property_create (env);
			axis2_options_set_enable_rest()
            axutil_property_set_value (rest_property, env, axutil_strdup (env, AXIS2_VALUE_TRUE));

            axis2_options_set_property (client_options, env, AXIS2_ENABLE_REST, rest_property);
			*/
			axis2_options_set_enable_rest(client_options,env, AXIS2_TRUE);
			*rest_enabled = AXIS2_TRUE;
        }

        /** default header type is POST, so only setting the HTTP_METHOD if GET */
        if (zend_hash_find (client_ht, WSF_HTTP_METHOD,
                sizeof (WSF_HTTP_METHOD), (void **) &tmp) == SUCCESS) 
		{
            char *value = Z_STRVAL_PP (tmp);
			axutil_property_t *http_method_property = NULL;
            if (value && (stricmp (value, AXIS2_HTTP_GET) == 0)) 
			{
				
				http_method_property =	axutil_property_create (env);

				axutil_property_set_value (http_method_property, env, 
					axutil_strdup (env, AXIS2_HTTP_GET));

                axis2_options_set_property (client_options, env,
                    AXIS2_HTTP_METHOD, http_method_property);

                AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
					"Setting HTTPMethod GET property");

            }else if (value && (stricmp(value, AXIS2_HTTP_PUT) == 0)) 
			{
				
				http_method_property =	axutil_property_create (env);

				axutil_property_set_value (http_method_property, env,
                    axutil_strdup (env, AXIS2_HTTP_PUT));

                axis2_options_set_property (client_options, env,
                    AXIS2_HTTP_METHOD, http_method_property);

                AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
                    "Setting HTTPMethod PUT property");

            }else if (value && (stricmp(value, AXIS2_HTTP_HEAD) == 0)) 
			{
				
				http_method_property =	axutil_property_create (env);

				axutil_property_set_value (http_method_property, env,
                    axutil_strdup (env, AXIS2_HTTP_HEAD));

                axis2_options_set_property (client_options, env,
                    AXIS2_HTTP_METHOD, http_method_property);

                AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
                    "Setting HTTPMethod HEAD property");
            }else if (value && (stricmp(value, AXIS2_HTTP_DELETE) == 0)) {
				
				http_method_property =	axutil_property_create (env);

				axutil_property_set_value (http_method_property, env,
                    axutil_strdup (env, AXIS2_HTTP_DELETE));

                axis2_options_set_property (client_options, env,
                    AXIS2_HTTP_METHOD, http_method_property);

                AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
                    "Setting HTTPMethod DELETE property");
            }
        }
    }

    status = wsf_client_set_endpoint_and_soap_action (client_ht, msg_ht, env, 
		client_options TSRMLS_CC);
    if (client_ht)
	{
        wsf_client_set_security_options (client_ht, msg_ht, env,
            client_options, svc_client TSRMLS_CC);

        wsf_client_set_timeout(client_ht, env, client_options TSRMLS_CC);
		wsf_client_set_http_headers (client_ht, msg_ht, env,
							client_options, svc_client TSRMLS_CC);
    }
    return status;
}


void
wsf_client_set_http_auth_info(
        HashTable * client_ht,
        axutil_env_t * env,
        axis2_options_t *options TSRMLS_DC)
{
    axis2_char_t *username = NULL;
    axis2_char_t *password = NULL;
    axis2_char_t *auth_type = NULL;
    
    zval **tmp = NULL;

    if (zend_hash_find (client_ht, WSF_HTTP_AUTH_USERNAME, sizeof (WSF_HTTP_AUTH_USERNAME),
                (void **) &tmp) == SUCCESS) 
	{
        username = Z_STRVAL_PP (tmp);
    }
    if (zend_hash_find (client_ht, WSF_HTTP_AUTH_PASSWORD, sizeof (WSF_HTTP_AUTH_PASSWORD),
                (void **) &tmp) == SUCCESS) 
	{
        password = Z_STRVAL_PP (tmp);
    }
    if (zend_hash_find (client_ht, WSF_HTTP_AUTH_TYPE, sizeof (WSF_HTTP_AUTH_TYPE),
                (void **) &tmp) == SUCCESS)
	{
        auth_type = Z_STRVAL_PP (tmp);
    }

    if(axis2_options_set_http_auth_info(options, env,
                 username, password, auth_type) == AXIS2_SUCCESS)
	{
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, 
			WSF_PHP_LOG_PREFIX "Success in setting HTTP authentication information");
    }
    else 
	{
        AXIS2_LOG_ERROR (env->log, AXIS2_LOG_SI,
            WSF_PHP_LOG_PREFIX "Failed in Setting HTTP authentication information");
    }
}


void
wsf_client_set_proxy_auth_info(
        HashTable * client_ht,
        axutil_env_t * env,
        axis2_options_t *options TSRMLS_DC)
{
    axis2_char_t *username = NULL;
    axis2_char_t *password = NULL;
    axis2_char_t *auth_type = NULL;
    
    zval **tmp = NULL;

    if (zend_hash_find (client_ht, WSF_PROXY_AUTH_USERNAME, sizeof (WSF_PROXY_AUTH_USERNAME),
                (void **) &tmp) == SUCCESS) 
	{
        username = Z_STRVAL_PP (tmp);
    }
    if (zend_hash_find (client_ht, WSF_PROXY_AUTH_PASSWORD, sizeof (WSF_PROXY_AUTH_PASSWORD),
                (void **) &tmp) == SUCCESS) 
	{
        password = Z_STRVAL_PP (tmp);
    }
    if (zend_hash_find (client_ht, WSF_PROXY_AUTH_TYPE, sizeof (WSF_PROXY_AUTH_TYPE),
                (void **) &tmp) == SUCCESS)
	{
        auth_type = Z_STRVAL_PP (tmp);
    }

    if(axis2_options_set_proxy_auth_info(options, env, username, password, auth_type) == AXIS2_SUCCESS)
	{
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
            "Success in setting proxy authentication information");
    }
    else 
	{
        AXIS2_LOG_ERROR (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
            "Failed in setting proxy authentication information");
    }
}

void
wsf_client_do_request (
    zval * this_ptr,
    zval * param,
    zval * return_value,
    axutil_env_t * env,
    axis2_svc_client_t * svc_client,
    int is_oneway TSRMLS_DC)
{
    int status = AXIS2_SUCCESS;
    int input_type = WSF_USING_INCORRECT_INPUT;

    axiom_node_t *request_payload = NULL;
    axiom_node_t *response_payload = NULL;
    axiom_xml_reader_t *reader = NULL;
    axis2_options_t *client_options = NULL;

    zval **client_tmp = NULL;
    zval **msg_tmp = NULL;
    HashTable *client_ht = NULL;
    HashTable *msg_ht = NULL;

    /** RM OPTION VARIABLES */
    int ws_client_will_continue_sequence = AXIS2_FALSE;
    int engage_rm = AXIS2_FALSE;
    int rm_spec_version = WSF_RM_VERSION_1_0;
    char *rm_spec_version_str = WSF_RM_VERSION_1_0_STR;
    int is_addressing_engaged = AXIS2_FALSE;
    int is_addressing_action_present = AXIS2_FALSE;
    int is_rm_engaged = AXIS2_FALSE;
    char *sequence_key = NULL;
	int rest_enabled = AXIS2_FALSE;

	smart_str sandesha2_db = { 0 };
	smart_str_appends(&sandesha2_db, WSF_GLOBAL(rm_db_dir));
    smart_str_appends(&sandesha2_db, "/");
    smart_str_appends(&sandesha2_db, WSF_SANDESHA2_DB);
    smart_str_0(&sandesha2_db);
	

    wsf_client_set_module_param_option (env, svc_client, WSF_MODULE_RM, 
		WSF_SANDESHA2_DB, sandesha2_db.c);

	smart_str_free(&sandesha2_db);

    if (Z_TYPE_P (param) == IS_OBJECT && instanceof_function (Z_OBJCE_P (param),
            ws_message_class_entry TSRMLS_CC)) 
	{
        zval **tmp_val = NULL;
        if (zend_hash_find (Z_OBJPROP_P (param), WSF_MSG_PAYLOAD_STR,
                    sizeof (WSF_MSG_PAYLOAD_STR), (void **) &tmp_val) == SUCCESS) 
		{
            reader = wsf_client_get_reader_from_zval (tmp_val, env TSRMLS_CC);
		}else 
		{
			return;
		}
		msg_ht = Z_OBJPROP_P(param);
        input_type = WSF_USING_MSG;
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
            "wsf_client do_request Input type is WSMessage ");
    }
	else 
	{
        reader = wsf_client_get_reader_from_zval (&param, env TSRMLS_CC);

        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
            "wsf_client_do_request Input  is not WSMessage ");
        input_type = WSF_USING_STRING;
    }

	client_options = (axis2_options_t *) axis2_svc_client_get_options (svc_client, env);

	/** Reset XML Parser free option. This is necessary to avoid the crash problem with libxml2 */
	axis2_options_set_xml_parser_reset (client_options, env, AXIS2_FALSE);

	client_ht = Z_OBJPROP_P (this_ptr);

    /** convert payload to an axiom node */
    request_payload = wsf_util_read_payload (reader, env);

    if (!request_payload) 
	{
		int throw_execption = AXIS2_TRUE;
		zval **tmp = NULL;
		AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
			"request payload node is null");
		
		if (zend_hash_find (client_ht, WSF_USE_SOAP, sizeof (WSF_USE_SOAP), 
			(void **) &tmp) == SUCCESS)
		{
			if (Z_TYPE_PP (tmp) == IS_BOOL && (Z_BVAL_PP (tmp) == 0)) 
			{
					throw_execption = AXIS2_FALSE;
			}
		}
		if(throw_execption)
		{
		    zend_throw_exception_ex (zend_exception_get_default (TSRMLS_C),
            1 TSRMLS_CC, "Invalid Input Message");
		}
	}
    

    /** add proxy settings */
    wsf_client_enable_proxy (client_ht, env, svc_client TSRMLS_CC);

    /** add ssl properties */
    wsf_client_enable_ssl (client_ht, env, client_options TSRMLS_CC);

    /** set http authentication parameters */
    wsf_client_set_http_auth_info(client_ht, env, client_options TSRMLS_CC);

    /** set proxy authentication parameters */
    wsf_client_set_proxy_auth_info(client_ht, env, client_options TSRMLS_CC);

    /** setting soap , rest and security options */
    status = wsf_client_set_options (client_ht, msg_ht, env, 
		client_options, svc_client, &rest_enabled TSRMLS_CC);
	
	/** set addressing options */
    is_addressing_engaged = wsf_client_set_addr_options (client_ht, msg_ht, env,
            client_options, svc_client TSRMLS_CC);
	
	if (input_type == WSF_USING_MSG) 
	{

        /** add set headers function here */
        wsf_client_set_headers (env, svc_client, param TSRMLS_CC);
		/** handle outgoing attachments */
        wsf_client_handle_outgoing_attachments (env, msg_ht, param, client_ht,
            request_payload, client_options TSRMLS_CC);
    } 

    if (status == AXIS2_FAILURE) 
	{
		zend_throw_exception_ex (zend_exception_get_default (TSRMLS_C),
			1 TSRMLS_CC, "service endpoint uri is needed for service invocation");
    }

	/** find whether addressing action is present if addressing is not engaged */
	if(!is_addressing_engaged){
		is_addressing_action_present = is_addr_action_present_in_options(msg_ht, client_ht TSRMLS_CC);
	}

    if (client_ht) 
	{
                  /** RM OPTIONS */
        axutil_property_t *rm_prop = NULL;
        int rm_version = -1;
        rm_version = wsf_client_get_rm_version (client_ht TSRMLS_CC);

        if (rm_version > 0) 
		{
            if (rm_version == WSF_RM_VERSION_1_0) 
			{
                rm_spec_version = WSF_RM_VERSION_1_0;
                rm_spec_version_str = WSF_RM_VERSION_1_0_STR;

                AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX "rm spec version 1.0");

            } else if (rm_version == WSF_RM_VERSION_1_1) 
			{
                rm_spec_version = WSF_RM_VERSION_1_1;
                rm_spec_version_str = WSF_RM_VERSION_1_1_STR;
                AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX "rm spec version 1.1");
            }

            if (rm_version > 0) 
			{
                rm_prop = axutil_property_create_with_args (env, 0, 0, 0, rm_spec_version_str);
                axis2_options_set_property (client_options, env,  
					WSF_SANDESHA2_CLIENT_RM_SPEC_VERSION, rm_prop);
                engage_rm = AXIS2_TRUE;
            }
		}

    /**
		reliable = TRUE
		1. addressing is engaged by user specifying useWSA and Action
		2. addressing is not specified by useWSA but action present
			then engage addressing
		If Addressing is engaged engage RM
	*/
        if ((is_addressing_engaged || 
			(!is_addressing_engaged && is_addressing_action_present)) && engage_rm) 
		{
            if (!is_addressing_engaged) 
			{
				if(msg_ht)
				{
					wsf_client_set_addressing_options_to_options(env, client_options, msg_ht TSRMLS_CC);
				}else
				{
					wsf_client_set_addressing_options_to_options(env, client_options, client_ht TSRMLS_CC);
				}

                axis2_svc_client_engage_module (svc_client, env, WSF_MODULE_ADDRESSING);
                AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
					"useWSA not specified, addressing engaged since rm is engaged");
            }

            axis2_svc_client_engage_module (svc_client, env, WSF_MODULE_RM);
            is_rm_engaged = AXIS2_TRUE;

            /** rm is engaged , process other rm params */
            if (zend_hash_find (client_ht, WSF_SEQUENCE_EXPIRY_TIME,
                    sizeof (WSF_SEQUENCE_EXPIRY_TIME), (void **) &client_tmp) == SUCCESS) 
			{
                char timeout_value[100];
                sprintf (timeout_value, "%ld", Z_LVAL_PP (client_tmp));
                wsf_client_set_module_param_option (env, svc_client, WSF_MODULE_RM, 
					WSF_SANDESHA2_INACTIVITY_TIMEOUT, timeout_value);

                AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,  WSF_PHP_LOG_PREFIX \
					"wsf_client sequenceExpiryTime is %d", Z_LVAL_PP (client_tmp));
            }
            if (zend_hash_find (client_ht, WSF_SEQUENCE_KEY, sizeof (WSF_SEQUENCE_KEY),
                    (void **) &client_tmp) == SUCCESS) 
			{

                if (Z_TYPE_PP (client_tmp) == IS_STRING) 
				{
					axutil_property_t *seq_property = NULL;
					sequence_key =axutil_strdup (env, Z_STRVAL_PP (client_tmp));
					seq_property =  axutil_property_create_with_args (env, 
						AXIS2_SCOPE_REQUEST, 1, NULL, sequence_key);
					
					axis2_options_set_property(client_options, env, 
						WSF_SANDESHA2_CLIENT_SEQ_KEY, seq_property);
					
					AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
						    " sequence key is %d", Z_STRVAL_PP (client_tmp));
                }
            }
            if (zend_hash_find (client_ht, WSF_WILL_CONTINUE_SEQUENCE, 
				sizeof (WSF_WILL_CONTINUE_SEQUENCE), (void **) &client_tmp) == SUCCESS)
			{
                if (Z_TYPE_PP (client_tmp) && Z_BVAL_PP (client_tmp) == 1) 
				{
                    ws_client_will_continue_sequence = 1;
                    AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
                        "willContinueSequence true");
                }
            }
        }
        if (is_rm_engaged) 
		{
            if (ws_client_will_continue_sequence && input_type == WSF_USING_MSG) 
			{
                /** if input_type is ws_message and continueSequence is true on client, we should look for 
					false value in ws_message to end the sequence */
                AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
                        "willContinueSeq TRUE, Input type Message");

                if (zend_hash_find (msg_ht, WSF_LAST_MESSAGE, sizeof (WSF_LAST_MESSAGE),
                        (void **) &msg_tmp) == SUCCESS && Z_BVAL_PP (msg_tmp) == 1)
				{
                    ws_client_will_continue_sequence = 0;
                    if (rm_spec_version == WSF_RM_VERSION_1_0) 
					{
                        axutil_property_t *last_msg_prop = axutil_property_create_with_args (env,
                            AXIS2_SCOPE_APPLICATION, 0, NULL, AXIS2_VALUE_TRUE);

                        axis2_options_set_property (client_options, env, 
							WSF_SANDHSHA2_LAST_MESSAGE , last_msg_prop);

                        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
							"Setting Sandesha2LastMessage");
                    }
                } /** END LastMessage */
            } else if (!ws_client_will_continue_sequence) 
			{
                AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
					"Setting TreminateSequence property");

                if (rm_spec_version == WSF_RM_VERSION_1_0) 
				{
                    axutil_property_t *last_msg_prop =
						axutil_property_create_with_args (env, 0, 0, 0, AXIS2_VALUE_TRUE);

                    axis2_options_set_property (client_options, env, 
                        WSF_SANDHSHA2_LAST_MESSAGE, last_msg_prop);

                    AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
                        "Setting Sandesha2LastMessage");
                }
            }
            /** two way single channel*/
            if (!is_oneway) 
			{

                char *timeout = NULL;
                axutil_property_t *timeout_property = NULL;

                {  /** set sequence offer with is mandatory for 
					single channel to work */
                    char *offered_seq_id = NULL;
                    axutil_property_t *sequence_property = NULL;

                    offered_seq_id = axutil_uuid_gen (env);

                    sequence_property = axutil_property_create (env);

                    axutil_property_set_value (sequence_property, env, 
						axutil_strdup (env, offered_seq_id));

                    axis2_options_set_property (client_options, env, 
						WSF_SANDHSHA2_SANDESHA2_OFFERED_SEQUENCE_ID , sequence_property);
                    
					AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
                        " Sandesha2OfferedSequenceId is set as property");
                }
                if (zend_hash_find (client_ht, WSF_RM_RESPONSE_TIMEOUT,
                        sizeof (WSF_RM_RESPONSE_TIMEOUT), (void **) &client_tmp) == SUCCESS) 
				{
                    if (Z_TYPE_PP (client_tmp) == IS_STRING) 
					{
                        timeout = Z_STRVAL_PP (client_tmp);
                    }
					else 
					{
                        char timeout_value[21];
                        snprintf (timeout_value, 20, "%ld", Z_LVAL_PP (client_tmp));
                        timeout = timeout_value;
                    }
                }
				else 
				{
                    /** default timeout value is 5 */
                    timeout = WSF_RM_DEFAULT_RESPONSE_TIMEOUT;
                }

                timeout_property = axutil_property_create_with_args (env, 0, 0, 0, timeout);

                if (timeout_property) 
				{
                    axis2_options_set_property (client_options, env, 
						AXIS2_TIMEOUT_IN_SECONDS, timeout_property);
                }
            }
        }
    }/** END RM OPTIONS */
    if (is_oneway) 
	{
        int ret_val = 0;
        ret_val = axis2_svc_client_send_robust (svc_client, env, request_payload);
        /** if rm is engaged and spec version is 1.1 send terminate sequence */
		if(!rest_enabled && is_rm_engaged)
		{
			wsf_client_send_terminate_sequence (env, ws_client_will_continue_sequence, 
				rm_spec_version, sequence_key, svc_client);
		}
        if (ret_val == 1) 
		{
            ZVAL_TRUE (return_value);
        } else 
		{
            ZVAL_FALSE (return_value);
        }
    } 
	else 
	{
        int has_fault = AXIS2_FALSE;
        axis2_char_t *res_text = NULL;
		int status_code = 0;
        response_payload = axis2_svc_client_send_receive (svc_client, env, request_payload);
		if(!rest_enabled && is_rm_engaged)
		{
        /** if rm is engaged and spec version is 1.1 send terminate sequence */
			wsf_client_send_terminate_sequence (env, ws_client_will_continue_sequence, 
				rm_spec_version, sequence_key, svc_client);
		}
		status_code = axis2_svc_client_get_http_status_code(svc_client, env);
	
		if((status_code != 200) && (status_code != 202) && rest_enabled)
		{
			zval *rfault = NULL;
			MAKE_STD_ZVAL(rfault);
			INIT_PZVAL(rfault);
			object_init_ex(rfault, ws_fault_class_entry);
			add_property_long(rfault,WSF_HTTP_STATUS_CODE  , status_code);
			if(response_payload)
			{
				res_text = axiom_node_to_string(response_payload, env);
				add_property_stringl(rfault, WSF_FAULT_STR , res_text, strlen(res_text), 1);
			}
			zend_throw_exception_object(rfault TSRMLS_CC);
			return;
		}
		if (axis2_svc_client_get_last_response_has_fault (svc_client, env)) 
		{
			axiom_soap_envelope_t *soap_envelope = NULL;
			axiom_soap_body_t *soap_body = NULL;
			axiom_soap_fault_t *soap_fault = NULL;
			has_fault = AXIS2_TRUE;

			soap_envelope = axis2_svc_client_get_last_response_soap_envelope (svc_client, env);
			if (soap_envelope)
				soap_body = axiom_soap_envelope_get_body (soap_envelope, env);
			if (soap_body)
				soap_fault = axiom_soap_body_get_fault (soap_body, env);
			if (soap_fault) 
			{

				int soap_version = 0;
				zval *rfault = NULL;
				axiom_node_t *fault_node = NULL;
				soap_version = axis2_options_get_soap_version(client_options, env);
				fault_node = axiom_soap_fault_get_base_node(soap_fault, env);
				if(fault_node)
				{
					res_text = axiom_node_to_string ( fault_node, env);
					MAKE_STD_ZVAL (rfault);
					INIT_PZVAL(rfault);
					object_init_ex (rfault, ws_fault_class_entry);
					add_property_stringl (rfault, WSF_FAULT_STR , res_text, strlen (res_text), 1);
					add_property_long(rfault,WSF_HTTP_STATUS_CODE  , status_code);
					wsf_util_handle_soap_fault(rfault, env, fault_node, soap_version TSRMLS_CC);
					zend_throw_exception_object(rfault TSRMLS_CC);
					return ;
				}
			}
		}else if (response_payload) 
		{
            int attachments_found = 0;
            zval *rmsg = NULL;
            axiom_soap_envelope_t *soap_envelope = NULL;

       	    MAKE_STD_ZVAL (rmsg);
            
            object_init_ex (rmsg, ws_message_class_entry);

            soap_envelope = axis2_svc_client_get_last_response_soap_envelope (svc_client, env);

            attachments_found = wsf_client_handle_incoming_attachments (env, client_ht, rmsg,
                soap_envelope, response_payload TSRMLS_CC);
            
            res_text = wsf_util_serialize_om (env, response_payload);
            
            add_property_stringl (rmsg, WSF_MSG_PAYLOAD_STR, res_text, strlen (res_text), 1);
			
            ZVAL_ZVAL (return_value, rmsg, 1, 0);
            zval_ptr_dtor(&rmsg);

        }else if (response_payload == NULL && has_fault == AXIS2_FALSE)
		{
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
                    "Response Payload NULL( Error number and code) => :" " %d :: %s",
                     env->error->error_number, AXIS2_ERROR_GET_MESSAGE(env->error));

            zend_throw_exception_ex (zend_exception_get_default (TSRMLS_C),
                1 TSRMLS_CC, "Error , NO Response Received");
        }
    }
    return ;
}

void
wsf_client_enable_ssl (
    HashTable * ht,
    axutil_env_t * env,
    axis2_options_t * options TSRMLS_DC)
{
    axutil_property_t *ssl_server_key_prop = NULL;
    axutil_property_t *ssl_client_key_prop = NULL;
    axutil_property_t *passphrase_prop = NULL;
    zval **tmp = NULL;
    char *ssl_server_key_filename = NULL;
    char *ssl_client_key_filename = NULL;
    char *passphrase = NULL;

    if (!ht)
        return;

    if (zend_hash_find (ht, WSF_SERVER_CERT, sizeof (WSF_SERVER_CERT),
            (void **) &tmp) == SUCCESS) 
	{
        ssl_server_key_filename = wsf_util_get_real_path(env, Z_STRVAL_PP (tmp) TSRMLS_CC);
    }
    if (zend_hash_find (ht, WSF_CLIENT_CERT, sizeof (WSF_CLIENT_CERT),
            (void **) &tmp) == SUCCESS) 
	{
        ssl_client_key_filename = wsf_util_get_real_path(env, Z_STRVAL_PP (tmp) TSRMLS_CC);
    }
    if (zend_hash_find (ht, WSF_PASSPHRASE, sizeof (WSF_PASSPHRASE),
            (void **) &tmp) == SUCCESS) 
	{
        passphrase = Z_STRVAL_PP (tmp);
    }

    ssl_server_key_prop = axutil_property_create_with_args (env, 0, AXIS2_TRUE, 0, 
		axutil_strdup (env, ssl_server_key_filename));

    axis2_options_set_property (options, env, AXIS2_SSL_SERVER_CERT, ssl_server_key_prop);

    ssl_client_key_prop = axutil_property_create_with_args (env, 0, AXIS2_TRUE, 0,
        axutil_strdup (env, ssl_client_key_filename));
    axis2_options_set_property (options, env, AXIS2_SSL_KEY_FILE, ssl_client_key_prop);

    passphrase_prop = axutil_property_create_with_args (env, 0, AXIS2_TRUE, 0,
        axutil_strdup (env, passphrase));
    axis2_options_set_property (options, env, AXIS2_SSL_PASSPHRASE, passphrase_prop);

    AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
		"setting SSL options %s -- %s ", 
			ssl_server_key_filename, ssl_client_key_filename);
	if(env->log->level == AXIS2_LOG_LEVEL_DEBUG && passphrase)
	{
			AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
				"passphrase found");
	}
}

void
wsf_client_enable_proxy (
    HashTable * ht,
    axutil_env_t * env,
    axis2_svc_client_t * svc_client TSRMLS_DC)
{
    axis2_char_t *proxy_host = NULL;
    axis2_char_t *proxy_port = NULL;
    zval **tmp = NULL;

    if (!ht)
        return;

    if (zend_hash_find (ht, WSF_PROXY_HOST, sizeof (WSF_PROXY_HOST),
            (void **) &tmp) == SUCCESS)
	{
        proxy_host = Z_STRVAL_PP (tmp);
    }
    if (zend_hash_find (ht, WSF_PROXY_PORT, sizeof (WSF_PROXY_PORT),
            (void **) &tmp) == SUCCESS) 
	{
        proxy_port = Z_STRVAL_PP (tmp);
    }
    if (proxy_host && proxy_port) 
	{
        axis2_svc_client_set_proxy (svc_client, env, proxy_host, proxy_port);
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX \
            "Setting proxy options %s -- %s -- ", proxy_host, proxy_port);
    }
}

void
wsf_client_set_http_headers (
    HashTable * client_ht,
    HashTable * msg_ht,
    axutil_env_t * env,
    axis2_options_t * client_options,
    axis2_svc_client_t * svc_client TSRMLS_DC)
{
    zval **tmp = NULL;
    axutil_property_t *header_property;
    axutil_array_list_t *header_list = axutil_array_list_create (env, 2);

    if (zend_hash_find (client_ht, WSF_HTTP_HEADERS, sizeof (WSF_HTTP_HEADERS), 
		(void **) &tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_ARRAY) {
       
        HashTable *ht = Z_ARRVAL_PP (tmp);
        HashPosition pos;
        zval **val = NULL;
        char *key = NULL;
        uint key_length = 0;
        int key_flags = 0;
        ulong num_key = 0;

        zend_hash_internal_pointer_reset_ex(ht, &pos);

        while (zend_hash_get_current_data_ex (ht, (void **) &val, &pos) != FAILURE &&
            (key_flags = zend_hash_get_current_key_ex (ht, &key, &key_length, &num_key, FALSE, &pos)) != FAILURE)
        {
            if(Z_TYPE_PP(val) == IS_STRING && key_flags == HASH_KEY_IS_STRING)
            {
                axis2_http_header_t *axis2_header =  axis2_http_header_create(env, key, Z_STRVAL_PP(val));
                axutil_array_list_add (header_list, env, (void *)axis2_header);
                AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, WSF_PHP_LOG_PREFIX "wsf_client_set_http_headers adding header %s: %s", key, Z_STRVAL_PP(val));
            }
            zend_hash_move_forward_ex (ht, &pos);
        }

        header_property = axutil_property_create(env);
        if (header_property && header_list)
        {
            axutil_property_set_value(header_property, env, header_list);
            axutil_property_set_free_func (header_property, env, axutil_array_list_free_void_arg);
            axis2_options_set_property(client_options, env, AXIS2_TRANSPORT_HEADER_PROPERTY, header_property);
        }
        
    }
}