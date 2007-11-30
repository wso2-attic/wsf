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
#include "axis2_addr.h"
#include "wsf.h"
#include "wsf_util.h"
#include <axutil_error_default.h>
#include <axutil_log_default.h>
#include <axutil_uuid_gen.h>
#include <axiom_util.h>
#include "wsf_wsdl.h"
#include <axiom.h>
#include <php_main.h>
#include "wsf_client.h"
#include "zend_exceptions.h"

#include <axiom_soap_envelope.h>
#include <rampart_context.h>
#include <neethi_options.h>
#include <axis2_policy_include.h>
#include <neethi_engine.h>


zval *g_arguments;
zval *g_classmap;

void wsf_wsdl_do_request(zval *client_zval,
                         zval* function_return_value,
                         zval* return_value,
                         axutil_env_t *env TSRMLS_DC);

xmlDocPtr wsf_wsdl_create_request_envelope(char *php_payload,
                                           int soap_version,
                                           axutil_env_t *env TSRMLS_DC);

void wsf_wsdl_handle_client_security(HashTable *client_ht,
                                     zval **policy_array,
                                     axutil_env_t *env,
                                     axis2_svc_client_t * svc_client TSRMLS_DC);

void wsf_wsdl_handle_server_security(wsf_svc_info_t *svc,
                                     zval **policy_options,
                                     axutil_env_t *env TSRMLS_DC);

axiom_soap_envelope_t *
wsf_wsdl_send_receive_soap_envelope_with_op_client (
    axutil_env_t * env,
    axis2_svc_client_t * svc_client,
    axis2_options_t * options,
    xmlDocPtr doc);


void create_dynamic_client(zval *this_ptr, char *function, int function_len,
                           int arg_count, zval *args, zval *return_value,
                           axutil_env_t * env TSRMLS_DC)
{
    zval *client_zval = NULL;
    zval **tmp;
    zval **wsdl_location;
    zval **end_point;
    zval **class_map;
    zval request_function, retval, param1, param2;
    zend_file_handle script;
    smart_str script_file_name = { 0 };
    zval *params[2];
    zval *user_parameters;
    zval *function_parameters;
    smart_str xslt_location = { 0 };
    char *real_path = NULL;
    int path_len = 0;
    
	
    if(SG (request_info).request_method){
        real_path = estrdup(SG(request_info).path_translated);
        path_len = strlen(SG(request_info).path_translated)- strlen(SG(request_info).request_uri);
        real_path[path_len + 1] = '\0';
    }
    else{
        real_path = "./";
    }
    
    smart_str_appends(&script_file_name, real_path);
    smart_str_appends(&xslt_location, real_path);
   
    if (instanceof_function (Z_OBJCE_P (this_ptr),
                             ws_client_proxy_class_entry TSRMLS_CC)) {
        if (zend_hash_find (Z_OBJPROP_P (this_ptr), WS_WSDL_WSCLIENT,
                            sizeof (WS_WSDL_WSCLIENT), 
                            (void **) & tmp) == SUCCESS) {
            client_zval = *tmp;
        } else {
            php_error_docref (NULL TSRMLS_CC, E_ERROR,
                              " proxy created without wsclient");
            return;
        }
    } else if (instanceof_function (Z_OBJCE_P (this_ptr),
                                    ws_client_class_entry TSRMLS_CC)) {
        client_zval = this_ptr;
    }
    if ( zend_hash_find ( Z_OBJPROP_P (client_zval), WS_WSDL, sizeof (WS_WSDL),
                          (void **) &wsdl_location) == SUCCESS
         && Z_TYPE_PP (wsdl_location) == IS_STRING){
        smart_str_appends(&script_file_name, WS_WSDL_FILE_PATH);
        smart_str_0 (&script_file_name);
        
        smart_str_appends(&xslt_location, WS_WSDL_XSLT_PATH);
        smart_str_0(&xslt_location);
           
        params[0] = &param1;
        params[1] = &param2;
        
        MAKE_STD_ZVAL(user_parameters);
        array_init(user_parameters);
        add_assoc_string(user_parameters, WS_WSDL, 
                         Z_STRVAL_PP(wsdl_location), 1);
        
        if ( zend_hash_find ( Z_OBJPROP_P (client_zval), WS_TO, sizeof (WS_TO),
                              (void **) &end_point) == SUCCESS
             && Z_TYPE_PP (end_point) == IS_STRING){
            add_assoc_string(user_parameters, WS_WSDL_ENDPOINT, 
                             Z_STRVAL_PP(end_point), 1);
        }
        
        if ( zend_hash_find ( Z_OBJPROP_P (client_zval), WS_WSDL_CLASSMAP, 
                              sizeof (WS_WSDL_CLASSMAP),
                            (void **) &class_map) == SUCCESS
             && Z_TYPE_PP (class_map) == IS_ARRAY){
            add_assoc_zval(user_parameters, WS_WSDL_CLASSMAP, *class_map);
            g_classmap = *class_map;
            g_arguments = args;
        }
        add_assoc_string(user_parameters, WS_WSDL_XSLT_LOCATION, 
                         xslt_location.c, 1);
        
        MAKE_STD_ZVAL(function_parameters);
        array_init(function_parameters);
        add_assoc_string(function_parameters, WS_WSDL_INVOKE_FUNCTION, 
                         function, 1);
        add_assoc_long(function_parameters, WS_WSDL_ARG_COUNT, arg_count);
        add_assoc_zval(function_parameters, WS_WSDL_ARG_ARRAY, args);
        
        ZVAL_STRING(&request_function, WS_WSDL_REQ_FUNCTION, 0);
        ZVAL_ZVAL(params[0], user_parameters, NULL, NULL);
        INIT_PZVAL(params[0]);
        ZVAL_ZVAL(params[1], function_parameters, NULL, NULL);
        INIT_PZVAL(params[1]);
	
        script.type = ZEND_HANDLE_FP;
        script.filename = script_file_name.c;
        script.opened_path = NULL;
        script.free_filename = 0;
        if (!(script.handle.fp = VCWD_FOPEN (script.filename, "rb"))){
            php_error_docref (NULL TSRMLS_CC, E_ERROR, 
                              "Unable to open script file: %s", script.filename);
            return ;
        }
        else{
            php_lint_script (&script TSRMLS_CC);
            if (call_user_function (EG (function_table), (zval **) NULL,
                                    &request_function, &retval, 2,
                                    params TSRMLS_CC) == SUCCESS ){
                if (Z_TYPE_P(&retval) == IS_ARRAY && 
                    Z_TYPE_P (&retval) != IS_NULL)
                    wsf_wsdl_do_request(client_zval, &retval, return_value, 
                                        env TSRMLS_CC);
                else if (Z_TYPE_P(&retval) == IS_STRING){
                    php_error_docref(NULL TSRMLS_CC, E_ERROR, 
                                     "Error occured in script: %s",
                                     Z_STRVAL_P(&retval));
                }
            }
        }
    }
}


void wsf_wsdl_do_request(zval *client_zval, zval *function_return_value,
                         zval *return_value, axutil_env_t *env TSRMLS_DC)
{
    axis2_svc_client_t *svc_client = NULL;
    axis2_options_t *client_options = NULL;
    ws_object_ptr intern = NULL;
    xmlDocPtr request_doc = NULL;
    axiom_soap_envelope_t *response_envelope = NULL;
    char *php_payload = NULL;
    char *endpoint_address = NULL;
    axis2_endpoint_ref_t *to_epr = NULL;
    char *soap_action = NULL;
    char *wsa_action = NULL;
    int soap_version = 2; 
    zval **policy_options = NULL;
    char *response_sig_model_string = NULL;
    char *wsdl_dom_string = NULL;

    axiom_node_t *env_node = NULL;
    int has_fault = AXIS2_FALSE;
    axis2_char_t *res_text = NULL;
    axiom_soap_body_t *soap_body = NULL;
    axiom_soap_fault_t *soap_fault = NULL;
    axiom_node_t *body_base_node = NULL;
    axiom_node_t *fault_node = NULL;
    zval *rfault;
    
    zval response_function, *res_retval, res_param1, res_param2, res_param3, 
		res_param4;
    zval *res_params[4];
    axiom_node_t *axiom_soap_base_node = NULL;
    zval *response_parameters;

    HashTable *ht_return = Z_ARRVAL_P(function_return_value);
    zval **tmp_options = NULL;
    axis2_char_t *proxy_host = NULL;
    axis2_char_t *proxy_port = NULL;
    
    if(zend_hash_find(ht_return, WS_WSDL_ENDPOINT_URI, 
					  sizeof(WS_WSDL_ENDPOINT_URI),
					  (void **)&tmp_options) == SUCCESS && 
	   				  Z_TYPE_PP(tmp_options) == IS_STRING ){
        endpoint_address = Z_STRVAL_PP(tmp_options);
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, 
                         "[wsf_wsdl] endpoint address is :- %s",
                         endpoint_address);
    }
    if(zend_hash_find(ht_return, WS_WSDL_BINDING_DETAILS, 
                      sizeof(WS_WSDL_BINDING_DETAILS),
                      (void **)&tmp_options) == SUCCESS && 
       Z_TYPE_PP(tmp_options) == IS_ARRAY){
        HashTable *ht_binding = Z_ARRVAL_PP(tmp_options);
        zval **binding_options = NULL;
        
        if(zend_hash_find(ht_binding, WS_WSDL_WSA, sizeof(WS_WSDL_WSA), 
						  (void **)&binding_options) == SUCCESS
         				  && Z_TYPE_PP(binding_options) == IS_STRING){
            wsa_action = Z_STRVAL_PP(binding_options);
            AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, 
                             "[wsf_wsdl] wsa action is :- %s", wsa_action);
        }
        if(zend_hash_find(ht_binding, WS_WSDL_SOAP, sizeof(WS_WSDL_SOAP), 
						  (void **)&binding_options) == SUCCESS
           && Z_TYPE_PP(binding_options) == IS_STRING){
            soap_action = Z_STRVAL_PP(binding_options);
            AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, 
                             "[wsf_wsdl] soap action is :- %s", soap_action);
        }
        if(zend_hash_find(ht_binding, WS_WSDL_SOAP_VERSION, 
                          sizeof(WS_WSDL_SOAP_VERSION), 
                          (void **)&binding_options) == SUCCESS
           && Z_TYPE_PP(binding_options) == IS_LONG){
            soap_version = Z_LVAL_PP(binding_options);
            AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, 
                             "[wsf_wsdl] soap version is :- %d",
                             soap_version);
        }
    }
    
    if(zend_hash_find(ht_return, WS_WSDL_REQ_PAYLOAD, 
                      sizeof(WS_WSDL_REQ_PAYLOAD),
                      (void **)&tmp_options) == SUCCESS && 
       Z_TYPE_PP(tmp_options) == IS_STRING ){
         php_payload = Z_STRVAL_PP(tmp_options);
         AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, 
                          "[wsf_wsdl] request payload :- %s", php_payload);
    }
    
    if(zend_hash_find(ht_return, WS_WSDL_POLICY_NODE, sizeof(WS_WSDL_POLICY_NODE),
                      (void **)&tmp_options) == SUCCESS && 
       Z_TYPE_PP(tmp_options) == IS_ARRAY){
        policy_options = tmp_options;
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, "[wsf_wsdl] policy array found");
    }
    
    if(zend_hash_find(ht_return, WS_WSDL_RES_SIG_NODEL, 
                      sizeof(WS_WSDL_RES_SIG_NODEL),
                      (void **)&tmp_options) == SUCCESS && 
       Z_TYPE_PP(tmp_options) == IS_STRING ){
        response_sig_model_string = Z_STRVAL_PP(tmp_options);
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, 
						 "[wsf_wsdl] response sig model :- %s",
                         response_sig_model_string);
    }
    
    if(zend_hash_find(ht_return, WS_WSDL_DOM, sizeof(WS_WSDL_DOM),
                      (void **)&tmp_options) == SUCCESS && 
       Z_TYPE_PP(tmp_options) == IS_STRING ){
        wsdl_dom_string = Z_STRVAL_PP(tmp_options);
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, "[wsf_wsdl] WSDL DOM string found");
    }
    
    WSF_GET_OBJ (svc_client, client_zval, axis2_svc_client_t, intern);
    client_options =
        (axis2_options_t *) axis2_svc_client_get_options (svc_client, env);
    
    axis2_options_set_xml_parser_reset (client_options, env, AXIS2_FALSE);
    wsf_client_set_options(Z_OBJPROP_P (client_zval), NULL,
                           env, client_options, svc_client, 0 TSRMLS_CC);
    
    wsf_client_enable_ssl (Z_OBJPROP_P (client_zval), env, client_options,
                           svc_client TSRMLS_CC);
    
    if(policy_options)
        wsf_wsdl_handle_client_security(Z_OBJPROP_P (client_zval), 
                                        policy_options, env, svc_client TSRMLS_CC);

    if(zend_hash_find ( Z_OBJPROP_P (client_zval), WS_TO, sizeof (WS_TO),
                        (void **) &tmp_options) == SUCCESS
       && Z_TYPE_PP (tmp_options) == IS_STRING)
        endpoint_address = Z_STRVAL_PP (tmp_options);
    
    to_epr = axis2_endpoint_ref_create (env, endpoint_address);
    axis2_options_set_to (client_options, env, to_epr);
    
/** add proxy options **/

    if (zend_hash_find (Z_OBJPROP_P (client_zval), WS_PROXY_HOST, sizeof (WS_PROXY_HOST),
                        (void **)&tmp_options) == SUCCESS) {
        proxy_host = Z_STRVAL_PP (tmp_options);
    }
    if (zend_hash_find (Z_OBJPROP_P (client_zval), WS_PROXY_PORT, sizeof (WS_PROXY_PORT),
                        (void **)&tmp_options) == SUCCESS) {
        proxy_port = Z_STRVAL_PP (tmp_options);
    }
    if (proxy_host && proxy_port) {
        axis2_svc_client_set_proxy (svc_client, env, proxy_host, proxy_port);
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                         "[wsf_wsdl_client] setting proxy options %s -- %s -- ", proxy_host,
                         proxy_port);
    }

    if(soap_action){
        axutil_string_t *action_string = axutil_string_create (env, soap_action);
        axis2_options_set_soap_action (client_options, env, action_string);
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                         "[wsf_wsdl] soap action present :- %s",
                         soap_action);
    }
    
    if(wsa_action){
        axis2_options_set_action(client_options, env, wsa_action);
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                         "[wsf_wsdl] addressing action present :- %s",
                         wsa_action);
        axis2_svc_client_engage_module (svc_client, env, WS_MODULE_ADDRESSING);
    }
    
    if (soap_version){
        axis2_options_set_soap_version (client_options, env,
                                        soap_version);
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                         "[wsf_wsdl]soap version in wsdl mode is %d",
                         soap_version);
    }
    
    if(!php_payload){
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                         "[wsf_wsdl]request payload is not found");
       /* return; */
    }
    
    request_doc = wsf_wsdl_create_request_envelope(php_payload, soap_version, 
                                                   env TSRMLS_CC);
    
    if (!request_doc){
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                         "[wsf_wsdl]Error in creating request payload dom");
        return;
    }
    response_envelope =
        wsf_wsdl_send_receive_soap_envelope_with_op_client (env, svc_client, 
                                                            client_options, 
                                                            request_doc);
    if (response_envelope) {
        env_node =
            axiom_soap_envelope_get_base_node (response_envelope, env);
        has_fault = AXIS2_TRUE;
        
        if (response_envelope)
            soap_body = axiom_soap_envelope_get_body (response_envelope, env);
        if (soap_body)
            soap_fault = axiom_soap_body_get_fault (soap_body, env);
        if (soap_fault) {
            soap_version = axis2_options_get_soap_version(client_options, env);
            fault_node = axiom_soap_fault_get_base_node(soap_fault, env);
            if(fault_node){
                res_text = axiom_node_to_string ( fault_node, env);
                AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                                 "[wsf_wsdl]Fault payload is %s", res_text);
                MAKE_STD_ZVAL (rfault);
                INIT_PZVAL(rfault);

                object_init_ex (rfault, ws_fault_class_entry);
                
                add_property_stringl (rfault, WS_MSG_PAYLOAD_STR, res_text,
                                      strlen (res_text), 1);
                
                wsf_util_handle_soap_fault(rfault, env, fault_node, 
                                           soap_version TSRMLS_CC);
                zend_throw_exception_object(rfault TSRMLS_CC);
                return ;
            }
            
        }
        if (soap_body)
            body_base_node = axiom_soap_body_get_base_node(soap_body, env);
        if (body_base_node && !soap_fault){
            axis2_char_t *response_buffer = NULL;
            axiom_soap_base_node = 
                axiom_soap_envelope_get_base_node(response_envelope, env);
            res_params[0] = &res_param1;
            res_params[1] = &res_param2;
            res_params[2] = &res_param3;
            res_params[3] = &res_param4;
            
            response_buffer = axiom_node_to_string (axiom_soap_base_node, env);
            AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                             "[wsf_wsdl]Response buffer is %s", response_buffer);
            
            MAKE_STD_ZVAL(response_parameters);
            array_init(response_parameters);
            if(g_classmap)
                add_assoc_zval(response_parameters, WS_WSDL_CLASSMAP, g_classmap);
            if(g_arguments)
                add_assoc_zval(response_parameters, WS_WSDL_ARGS, g_arguments);

            ZVAL_STRING(&response_function, WS_WSDL_RES_FUNCTION, 0);
            ZVAL_STRING(res_params[0], response_buffer, 0);
            INIT_PZVAL(res_params[0]);
            ZVAL_STRING(res_params[1], response_sig_model_string, 0);
            INIT_PZVAL(res_params[1]);
            ZVAL_ZVAL(res_params[2], response_parameters, NULL, NULL);
            INIT_PZVAL(res_params[2]);
            ZVAL_STRING(res_params[3], wsdl_dom_string, 0);
            INIT_PZVAL(res_params[3]);

            MAKE_STD_ZVAL(res_retval);
            INIT_PZVAL(res_retval);
            if (call_user_function (EG (function_table), (zval **) NULL,
                                    &response_function, res_retval, 4, 
                                    res_params TSRMLS_CC) == SUCCESS ){
                if (Z_TYPE_P(res_retval) == IS_STRING)
                    ZVAL_ZVAL(return_value, res_retval, 0, 0);
                if (Z_TYPE_P(res_retval) == IS_OBJECT)
                    ZVAL_ZVAL(return_value, res_retval, 0, 0); 
                if (Z_TYPE_P(res_retval) == IS_ARRAY)
                    ZVAL_ZVAL(return_value, res_retval, 0, 0);
            }
        }
    }
    else
        php_printf("\n response envelope not found \n");
    
}

xmlDocPtr wsf_wsdl_create_request_envelope(char *php_payload,
                                           int soap_version,
                                           axutil_env_t *env TSRMLS_DC)
{
    xmlDoc *doc, *payload_doc;
    xmlNodePtr envelope = NULL, body = NULL, head = NULL, payload = NULL; 
    xmlNsPtr ns = NULL;

    doc = xmlNewDoc (BAD_CAST (WS_WSDL_ENV_1_0));
    doc->encoding = xmlCharStrdup (WS_WSDL_ENV_UTF);
    doc->charset = XML_CHAR_ENCODING_UTF8;
    if (soap_version == 1) {
        envelope = xmlNewDocNode (doc, NULL, 
                                  BAD_CAST (AXIOM_SOAP_ENVELOPE_LOCAL_NAME), NULL);
        ns = xmlNewNs (envelope, BAD_CAST (AXIOM_SOAP11_SOAP_ENVELOPE_NAMESPACE_URI),
                       BAD_CAST (AXIOM_SOAP_DEFAULT_NAMESPACE_PREFIX));
        xmlSetNs (envelope, ns);
    } else if (soap_version == 2) {
        envelope = xmlNewDocNode (doc, NULL, 
                                  BAD_CAST (AXIOM_SOAP_ENVELOPE_LOCAL_NAME), NULL);
        ns = xmlNewNs (envelope, BAD_CAST (AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI),
                       BAD_CAST (AXIOM_SOAP_DEFAULT_NAMESPACE_PREFIX));
        xmlSetNs (envelope, ns);
    } else {
        php_printf ("Unknown SOAP version");
    }
    xmlDocSetRootElement (doc, envelope);
    
        head = xmlNewChild (envelope, ns, 
                            BAD_CAST (AXIOM_SOAP_HEADER_LOCAL_NAME), NULL);
		body = xmlNewChild (envelope, ns, BAD_CAST (AXIOM_SOAP_BODY_LOCAL_NAME),
                            NULL);
	
		if(php_payload){
        	payload_doc = xmlParseMemory(php_payload, strlen(php_payload) + 1);
        	if(!payload_doc)
            	return NULL;
        
        	payload = xmlDocGetRootElement(payload_doc);

        	if(!payload)
            	return NULL;
      
          	xmlAddChild(body, payload);
		}
        return doc;
}


axiom_soap_envelope_t *
wsf_wsdl_create_soap_envelope_from_doc (
    xmlDocPtr doc,
    const axutil_env_t * env,
    axis2_char_t * soap_version_uri)
{
    axiom_soap_envelope_t *soap_envelope = NULL;
    axiom_soap_builder_t *soap_builder = NULL;
    axiom_xml_reader_t *reader = NULL;
    axiom_stax_builder_t *builder = NULL;
    

    reader =
        axiom_xml_reader_create_for_memory (env, doc, 0, "utf-8",
                                            AXIS2_XML_PARSER_TYPE_DOC);

    builder = axiom_stax_builder_create (env, reader);

    soap_builder = axiom_soap_builder_create (env, builder, soap_version_uri);

    soap_envelope = axiom_soap_builder_get_soap_envelope (soap_builder, env);

    return soap_envelope;
}


axiom_soap_envelope_t *
wsf_wsdl_send_receive_soap_envelope_with_op_client (
    axutil_env_t * env,
    axis2_svc_client_t * svc_client,
    axis2_options_t * options,
    xmlDocPtr doc)
{
    axiom_soap_envelope_t *res_envelope = NULL, *req_envelope = NULL;
    axis2_svc_ctx_t *svc_ctx = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_msg_ctx_t *req_msg_ctx = NULL, *res_msg_ctx = NULL;
    axutil_qname_t *op_qname = NULL;
    axis2_op_client_t *op_client = NULL;
    axis2_char_t *soap_version_uri = NULL;

    svc_ctx = axis2_svc_client_get_svc_ctx (svc_client, env);

    conf_ctx = axis2_svc_ctx_get_conf_ctx (svc_ctx, env);

    req_msg_ctx = axis2_msg_ctx_create (env, conf_ctx, NULL, NULL);

    op_qname = axutil_qname_create (env, AXIS2_ANON_OUT_IN_OP, NULL, NULL);

    op_client = axis2_svc_client_create_op_client (svc_client, env, op_qname);

    soap_version_uri =
        (axis2_char_t *) axis2_options_get_soap_version_uri (options, env);

    req_envelope = wsf_wsdl_create_soap_envelope_from_doc (doc, env, 
                                                           soap_version_uri);
    
    axis2_msg_ctx_set_soap_envelope (req_msg_ctx, env, req_envelope);
    
    axis2_op_client_add_msg_ctx (op_client, env, req_msg_ctx);
    
    axis2_op_client_execute (op_client, env, AXIS2_TRUE);
    
    res_msg_ctx =
        (axis2_msg_ctx_t *) axis2_op_client_get_msg_ctx (op_client, env,
                                                         AXIS2_WSDL_MESSAGE_LABEL_IN);
    
    if (!res_msg_ctx) {
        return NULL;
    } else {
        res_envelope = axis2_msg_ctx_get_soap_envelope (res_msg_ctx, env);
    }
    return res_envelope;
}

void wsf_wsdl_handle_client_security(HashTable *client_ht,
                                     zval **policy_array,
                                     axutil_env_t *env,
                                     axis2_svc_client_t * svc_client TSRMLS_DC)
{
    zval *sec_token = NULL;
    zval *policy = NULL;
    zval **tmp = NULL;
    HashTable *policy_ht = NULL;
    
    axiom_node_t *binding_policy_node = NULL;
    axiom_node_t *input_policy_node = NULL;
    axiom_node_t *output_policy_node = NULL;

    zval **policy_options = NULL;
    tokenProperties_t tmp_rampart_ctx;
    rampart_context_t *rampart_ctx = NULL;

    neethi_policy_t *binding_neethi_policy = NULL;
    axiom_element_t *binding_policy_root_ele = NULL;
    neethi_policy_t *normalized_binding_neethi_policy = NULL;

    neethi_policy_t *input_neethi_policy = NULL;
    axiom_element_t *input_policy_root_ele = NULL;
    neethi_policy_t *normalized_input_neethi_policy = NULL;

    neethi_policy_t *merged_input_neethi_policy = NULL;
    
    axis2_svc_ctx_t *svc_ctx = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_conf_t *conf = NULL;
    axutil_param_t *security_param = NULL;
    axis2_desc_t *desc = NULL;
    axis2_policy_include_t *policy_include = NULL;
    axis2_svc_t *svc = NULL;

    char *policy_xml = NULL;

	/* If there are user defined policies it well be set instead of policies in WSDL */
	
    if (zend_hash_find (client_ht, WS_POLICY_NAME, sizeof (WS_POLICY_NAME),
                        (void **) &tmp) == SUCCESS) {
        policy = *tmp;
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                         "[wsf_client] policy object found ");
		
        if (Z_TYPE_P (policy) == IS_OBJECT) {
            policy_ht = Z_OBJPROP_P (policy);
            if (zend_hash_find (policy_ht, "policy_xml", sizeof ("policy_xml"),
                	(void **) &tmp) == SUCCESS
            	&& (Z_TYPE_PP (tmp) == IS_STRING)) {
            	policy_xml = Z_STRVAL_PP (tmp);
              	input_policy_node = wsf_util_deserialize_buffer (env, policy_xml);
            }
            else
				input_policy_node = wsf_do_create_policy (NULL, policy, AXIS2_FALSE, env TSRMLS_CC);
        }
	
    }
    else{
    	HashTable *ht_policy = Z_ARRVAL_PP(policy_array);
        if(!ht_policy)
            return;
        
    	if(zend_hash_find(ht_policy, WS_WSDL_OP_POLICY, sizeof(WS_WSDL_OP_POLICY), 
                          (void **)&policy_options) == SUCCESS
           && Z_TYPE_PP(policy_options) == IS_STRING){
            binding_policy_node = 
            	wsf_util_deserialize_buffer (env, Z_STRVAL_PP(policy_options));
            AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                             "[wsf_wsdl]operation policy xml is  \n\t %s \n",
                             Z_STRVAL_PP(policy_options));
    	}
        
    	if(zend_hash_find(ht_policy, WS_WSDL_IN_POLICY, sizeof(WS_WSDL_IN_POLICY), 
            	          (void **)&policy_options) == SUCCESS
           && Z_TYPE_PP(policy_options) == IS_STRING){
            input_policy_node = 
            	wsf_util_deserialize_buffer (env, Z_STRVAL_PP(policy_options));
            AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                             "[wsf_wsdl]input policy xml is  \n\t %s \n",
                             Z_STRVAL_PP(policy_options));
    	}
        
    	if(zend_hash_find(ht_policy, WS_WSDL_OUT_POLICY, sizeof(WS_WSDL_OUT_POLICY),
                          (void **)&policy_options) == SUCCESS
           && Z_TYPE_PP(policy_options) == IS_STRING){
            output_policy_node = 
            	wsf_util_deserialize_buffer (env, Z_STRVAL_PP(policy_options));
            AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                             "[wsf_wsdl]output policy xml is  \n\t %s \n",
            	             Z_STRVAL_PP(policy_options));
    	}
    }
    /* no need to change so many things just want to public some functions in wsf_policy.c */
    
    {                          
        tmp_rampart_ctx.certificate = NULL;
        tmp_rampart_ctx.password = NULL;
        tmp_rampart_ctx.passwordType = NULL;
        tmp_rampart_ctx.pvtKey = NULL;
        tmp_rampart_ctx.receiverCertificate = NULL;
        tmp_rampart_ctx.user = NULL;
        tmp_rampart_ctx.ttl = 0;
        tmp_rampart_ctx.callback_function = NULL;
    }
    
    
    if (zend_hash_find (client_ht, WS_SECURITY_TOKEN,
                        sizeof (WS_SECURITY_TOKEN), (void **) &tmp) == SUCCESS
        && Z_TYPE_PP (tmp) == IS_OBJECT) {
        sec_token = *tmp;
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                         "[wsf_wsdl] security token object found ");
    }
    
    if(!sec_token){
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                         "[wsf_wsdl]security object not found \n");
        return;
    }
    tmp_rampart_ctx =
        wsf_set_tmp_rampart_options (tmp_rampart_ctx, sec_token, NULL,
                                     env TSRMLS_CC);
    
    
    rampart_ctx = rampart_context_create (env);
    
    if (binding_policy_node) {
        if (axiom_node_get_node_type (binding_policy_node,
                                      env) == AXIOM_ELEMENT) {
            binding_policy_root_ele =
                (axiom_element_t *)
                axiom_node_get_data_element (binding_policy_node, env);
            
            if (binding_policy_root_ele) {
                binding_neethi_policy =
                    neethi_engine_get_policy (env, binding_policy_node,
                                              binding_policy_root_ele);
                normalized_binding_neethi_policy = 
                    neethi_engine_get_normalize(env, AXIS2_FALSE, 
												binding_neethi_policy);
                neethi_policy_free(binding_neethi_policy, env);
                binding_neethi_policy = NULL;
            }
        }
    }
    
    if (input_policy_node) {
        if (axiom_node_get_node_type (input_policy_node,
                                      env) == AXIOM_ELEMENT) {
            input_policy_root_ele =
                (axiom_element_t *)
                axiom_node_get_data_element (input_policy_node, env);

            if (input_policy_root_ele) {
                input_neethi_policy =
                    neethi_engine_get_policy (env, input_policy_node,
                                              input_policy_root_ele);
                normalized_input_neethi_policy = 
                    neethi_engine_get_normalize(env, AXIS2_FALSE, 
                                                input_neethi_policy);
                neethi_policy_free(input_neethi_policy, env);
                input_neethi_policy = NULL;
            } 
        }
    }
    
    if(normalized_input_neethi_policy && normalized_binding_neethi_policy ){
        merged_input_neethi_policy = 
            neethi_engine_merge(env, normalized_input_neethi_policy, 
                                normalized_binding_neethi_policy);
        neethi_policy_free(normalized_binding_neethi_policy, env);
        neethi_policy_free(normalized_input_neethi_policy, env);
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                         "[wsf_wsdl]outgoing policies merged \n");
    }
    else if (!normalized_input_neethi_policy && normalized_binding_neethi_policy){
        merged_input_neethi_policy = normalized_binding_neethi_policy;
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                         "[wsf_wsdl]binding policy is set \n");
    }
    
    else if (normalized_input_neethi_policy && !normalized_binding_neethi_policy){
        merged_input_neethi_policy = normalized_input_neethi_policy;
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                         "[wsf_wsdl]input policy is set \n");
    }
    
    else{
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                         "[wsf_wsdl]valid policies not found \n");
        return;
    }
    
    
    svc = axis2_svc_client_get_svc (svc_client, env);
    if (!svc) {
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                         "[wsf_wsdl]Service is NULL \n");
        return ;
    }
    desc = axis2_svc_get_base (svc, env);
    if (!desc) {
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                         "[wsf_wsdl]Description is NULL \n");
        return ;
    }
    policy_include = axis2_desc_get_policy_include (desc, env);
    if (!policy_include) {
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                         "[wsf_wsdl]Policy Include is NULL \n");
        return ;
    }
    axis2_policy_include_add_policy_element (policy_include, env,
                                             AXIS2_SERVICE_POLICY, 
                                             merged_input_neethi_policy);
    
    svc_ctx = axis2_svc_client_get_svc_ctx (svc_client, env);
    conf_ctx = axis2_svc_ctx_get_conf_ctx (svc_ctx, env);
    conf = axis2_conf_ctx_get_conf (conf_ctx, env);
    
    wsf_set_options_to_rampart_ctx (rampart_ctx, env,
                                    NULL, tmp_rampart_ctx);
    
    security_param =
        axutil_param_create (env, WS_RAMPART_CONFIGURATION,
                             (void *) rampart_ctx);
    axis2_conf_add_param (conf, env, security_param);
    
    axis2_svc_client_engage_module (svc_client, env, WS_MODULE_SECURITY);
    
    
}

void wsf_wsdl_process_service(zval *this_ptr, wsf_req_info_t *request_info1, wsf_svc_info_t *svc_info, axutil_env_t *env TSRMLS_DC)
{
    char *real_path = NULL;
    int path_len = 0;
    smart_str script_file_name = { 0 };
    smart_str xslt_location = { 0 };
    zval **wsdl_location = NULL;
    zval *params[2];
    zval retval, param1, param2;
    zval *param_array;
    zval **class_map;
    zend_file_handle script;
    zval request_function;
    zval *operations;
    axutil_hash_index_t *hi = NULL;
    
    real_path = estrdup(SG(request_info).path_translated);
    path_len = 
        strlen(SG(request_info).path_translated)- strlen(SG(request_info).request_uri);
    real_path[path_len + 1] = '\0';
    
    smart_str_appends(&script_file_name, real_path);
    smart_str_appends(&xslt_location, real_path);
    
    zend_hash_find(Z_OBJPROP_P(this_ptr), WS_WSDL, sizeof(WS_WSDL),
                   (void **)&wsdl_location);
    
    smart_str_appends(&script_file_name, WS_WSDL_FILE_PATH);
    smart_str_0 (&script_file_name);
    
    smart_str_appends(&xslt_location, WS_WSDL_XSLT_PATH);
    smart_str_0(&xslt_location);
    
    params[0] = &param1;
    params[1] = &param2;
    
    MAKE_STD_ZVAL(param_array);
    array_init(param_array);
    add_assoc_string(param_array, WS_WSDL, Z_STRVAL_PP(wsdl_location), 1);
    
    if ( zend_hash_find ( Z_OBJPROP_P (this_ptr), WS_WSDL_CLASSMAP, 
                          sizeof (WS_WSDL_CLASSMAP),
                          (void **) &class_map) == SUCCESS
         && Z_TYPE_PP (class_map) == IS_ARRAY){
        add_assoc_zval(param_array, WS_WSDL_CLASSMAP, *class_map);
        
    }
    
    MAKE_STD_ZVAL (operations);
    array_init (operations);
    if (svc_info->ops_to_functions) {
        for (hi =
                 axutil_hash_first (svc_info->ops_to_functions, env);
             hi; hi = axutil_hash_next (env, hi)) {
            void *v = NULL;
            const void *k = NULL;
            axis2_char_t * f_key = NULL;
            axutil_hash_this (hi, &k, NULL, &v);
            f_key = (axis2_char_t *) k;
            add_next_index_string (operations, (char *)f_key , 1);
        } 
    }	
    
    
    ZVAL_STRING(&request_function, WS_WSDL_SERVICE_REQ_FUNCTION, 0);
    add_assoc_string(param_array, WS_WSDL_XSLT_LOCATION, xslt_location.c, 1);
    
    ZVAL_ZVAL(params[0], param_array, NULL, NULL);
    INIT_PZVAL(params[0]);
    ZVAL_ZVAL(params[1], operations, NULL, NULL);
    INIT_PZVAL(params[1]);
    
    script.type = ZEND_HANDLE_FP;
    script.filename = script_file_name.c;
    script.opened_path = NULL;
    script.free_filename = 0;
    if (!(script.handle.fp = VCWD_FOPEN (script.filename, "rb"))){
        php_error_docref (NULL TSRMLS_CC, E_ERROR, 
                          "Unable to open script file: %s", script.filename);
        return;
    }
    else{
        php_lint_script (&script TSRMLS_CC);
        if (call_user_function (EG (function_table), (zval **) NULL,
                                &request_function, &retval, 2, 
								params TSRMLS_CC) == SUCCESS ){
            if (Z_TYPE_P(&retval) == IS_STRING){
                svc_info->sig_model_string = Z_STRVAL_P(&retval);
                AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                                 "[wsf_wsdl]received data from scripts");
            }
            else if(Z_TYPE_P(&retval) == IS_ARRAY){
				zval **tmp = NULL;
                zval **policy_options = NULL;
                HashTable *ht_return = Z_ARRVAL_P(&retval);
                
                AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
                                "[wsf_wsdl]received array from scripts");
                if(zend_hash_find(ht_return, "sig_model_string", 
                                  sizeof("sig_model_string"), (void **)&tmp) == SUCCESS &&
                   Z_TYPE_PP(tmp) == IS_STRING){
                    svc_info->sig_model_string = Z_STRVAL_PP(tmp);
                    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
                                    "[wsf_wsdl]received sig model string");
                }
                if(zend_hash_find(ht_return, "policies", sizeof("policies"), 
                                  (void **)&tmp) == SUCCESS && Z_TYPE_PP(tmp) == IS_ARRAY){
                    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
                                    "[wsf_wsdl]policies found");
                    policy_options = tmp;
                    wsf_wsdl_handle_server_security(svc_info, policy_options,
                                                    env TSRMLS_CC);
                }
                                
            }
        }
    }
    
    
}

void wsf_wsdl_handle_server_security(wsf_svc_info_t *svc_info,
                                     zval **op_policies,
                                     axutil_env_t *env TSRMLS_DC)
{
    HashTable *operations = NULL;
    HashTable *ht_policy = NULL;
    HashPosition pos;
    zval **tmp = NULL;
    zval **policy_options = NULL;
    
    
    axiom_node_t *binding_policy_node = NULL;
    axiom_node_t *input_policy_node = NULL;
    axiom_node_t *output_policy_node = NULL;
    
    tokenProperties_t tmp_rampart_ctx;
    rampart_context_t *rampart_ctx = NULL;
    
    neethi_policy_t *binding_neethi_policy = NULL;
    axiom_element_t *binding_policy_root_ele = NULL;
    neethi_policy_t *normalized_binding_neethi_policy = NULL;
    
    neethi_policy_t *input_neethi_policy = NULL;
    axiom_element_t *input_policy_root_ele = NULL;
    neethi_policy_t *normalized_input_neethi_policy = NULL;
    
    neethi_policy_t *merged_input_neethi_policy = NULL;
	int i = 0;
	axutil_param_t *security_param = NULL;
	axis2_conf_t *conf = NULL;
    wsf_worker_t *worker = NULL;

    if(!op_policies)
        return;
    operations = Z_ARRVAL_PP(op_policies);
    if(!operations)
        return;
    
  
    zend_hash_internal_pointer_reset_ex (operations, &pos);
    while (zend_hash_get_current_data_ex (operations,
                                          (void **) &tmp, &pos) != FAILURE) {
        char *op_name = NULL;
        unsigned int op_name_len = 0;
        unsigned long index = i;
        zend_hash_get_current_key_ex (operations, &op_name, &op_name_len, &index, 0, &pos);
        zend_hash_move_forward_ex (operations, &pos);
        i++;
        ht_policy = Z_ARRVAL_PP (tmp);
        if (op_name){

			axis2_op_t *op = NULL;
            axutil_qname_t *op_qname = NULL;
            axis2_desc_t *desc = NULL;
            
            axis2_policy_include_t *policy_include = NULL;
            AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "operation name is %s", op_name);
            /* begin_line */
            
            if(zend_hash_find(ht_policy, WS_WSDL_OP_POLICY, sizeof(WS_WSDL_OP_POLICY), 
                              (void **)&policy_options) == SUCCESS
				   && Z_TYPE_PP(policy_options) == IS_STRING){
                binding_policy_node = 
                    wsf_util_deserialize_buffer (env, Z_STRVAL_PP(policy_options));
                AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                                 "[wsf_wsdl]operation policy xml is  \n\t %s \n",
                                 Z_STRVAL_PP(policy_options));
				   }
            
            if(zend_hash_find(ht_policy, WS_WSDL_IN_POLICY, sizeof(WS_WSDL_IN_POLICY), 
                              (void **)&policy_options) == SUCCESS
               && Z_TYPE_PP(policy_options) == IS_STRING){
                input_policy_node = 
                    wsf_util_deserialize_buffer (env, Z_STRVAL_PP(policy_options));
                AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                                 "[wsf_wsdl]input policy xml is  \n\t %s \n",
                                 Z_STRVAL_PP(policy_options));
            }
            
            if(zend_hash_find(ht_policy, WS_WSDL_OUT_POLICY, sizeof(WS_WSDL_OUT_POLICY),
								  (void **)&policy_options) == SUCCESS
               && Z_TYPE_PP(policy_options) == IS_STRING){
                output_policy_node = 
                    wsf_util_deserialize_buffer (env, Z_STRVAL_PP(policy_options));
                AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                                 "[wsf_wsdl]output policy xml is  \n\t %s \n",
										Z_STRVAL_PP(policy_options));
                
            }
            
            
				
            if (binding_policy_node) {
                if (axiom_node_get_node_type (binding_policy_node,
                                              env) == AXIOM_ELEMENT) {
                    binding_policy_root_ele =
                        (axiom_element_t *)
                        axiom_node_get_data_element (binding_policy_node, env);
                    
                    if (binding_policy_root_ele) {
                        binding_neethi_policy =
                            neethi_engine_get_policy (env, binding_policy_node,
                                                      binding_policy_root_ele);
                        normalized_binding_neethi_policy = 
                            neethi_engine_get_normalize(env, AXIS2_FALSE, 
                                                        binding_neethi_policy);
                        neethi_policy_free(binding_neethi_policy, env);
                        binding_neethi_policy = NULL;
                    }
                }
            }
            
            if (input_policy_node) {
                if (axiom_node_get_node_type (input_policy_node,
                                              env) == AXIOM_ELEMENT) {
                    input_policy_root_ele =
                        (axiom_element_t *)
                        axiom_node_get_data_element (input_policy_node, env);
                    
                    if (input_policy_root_ele) {
                        input_neethi_policy =
                            neethi_engine_get_policy (env, input_policy_node,
                                                      input_policy_root_ele);
                        normalized_input_neethi_policy = 
                            neethi_engine_get_normalize(env, AXIS2_FALSE, 
                                                        input_neethi_policy);
                        neethi_policy_free(input_neethi_policy, env);
                        input_neethi_policy = NULL;
                    } 
                }
            }
            
            if(normalized_input_neethi_policy && normalized_binding_neethi_policy ){
                merged_input_neethi_policy = 
                    neethi_engine_merge(env, normalized_input_neethi_policy, 
                                        normalized_binding_neethi_policy);
                neethi_policy_free(normalized_binding_neethi_policy, env);
					neethi_policy_free(normalized_input_neethi_policy, env);
					AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                                                         "[wsf_wsdl]outgoing policies merged \n");
            }
            else if (!normalized_input_neethi_policy && normalized_binding_neethi_policy){
                merged_input_neethi_policy = normalized_binding_neethi_policy;
                AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                                 "[wsf_wsdl]binding policy is set \n");
            }
				
            else if (normalized_input_neethi_policy && !normalized_binding_neethi_policy){
                merged_input_neethi_policy = normalized_input_neethi_policy;
                AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                                 "[wsf_wsdl]input policy is set \n");
            }
            
            else{
                AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                                 "[wsf_wsdl]valid policies not found \n");
                return;
            }
            /* end line */
				
            
         
            
            op_qname = axutil_qname_create (env, op_name, NULL, NULL);
            
            if (NULL != svc_info->svc && NULL != op_name) {
                op = axis2_svc_get_op_with_name (svc_info->svc, env, op_name);
                desc = axis2_op_get_base(op, env);
                policy_include = axis2_desc_get_policy_include(desc, env);
                axis2_policy_include_add_policy_element (policy_include, env,
                                                         AXIS2_SERVICE_POLICY, merged_input_neethi_policy);
                
            }
        }
        
    }	
    
		/* no need to change so many things just want to public some functions in wsf_policy.c */
  
    
    tmp_rampart_ctx.certificate = NULL;
    tmp_rampart_ctx.password = NULL;
    tmp_rampart_ctx.passwordType = NULL;
    tmp_rampart_ctx.pvtKey = NULL;
    tmp_rampart_ctx.receiverCertificate = NULL;
    tmp_rampart_ctx.user = NULL;
    tmp_rampart_ctx.ttl = 0;
    tmp_rampart_ctx.callback_function = NULL;
    
    
    if(!svc_info->security_token){
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                         "[wsf_wsdl]security object not found \n");
        return;
    }
    tmp_rampart_ctx = wsf_set_tmp_rampart_options (tmp_rampart_ctx, 
                                                   svc_info->security_token, NULL, env TSRMLS_CC);
    rampart_ctx = rampart_context_create (env);
    wsf_set_options_to_rampart_ctx (rampart_ctx, env,
                                    NULL, tmp_rampart_ctx);
    security_param =
        axutil_param_create (env, WS_RAMPART_CONFIGURATION,
                             (void *) rampart_ctx);
    axis2_svc_add_param (svc_info->svc, env, security_param);
    
    /** engage module rampart */

    worker = svc_info->php_worker;
				
    conf = axis2_conf_ctx_get_conf (wsf_worker_get_conf_ctx(worker, env), env);
    wsf_util_engage_module (conf, "rampart", env, svc_info->svc);
    
    
}



void wsf_wsdl_set_sig_model(char *wsdl_path, wsf_svc_info_t *svc_info, const axutil_env_t *env TSRMLS_DC)
{
    char *real_path = NULL;
    int path_len = 0;
    smart_str script_file_name = { 0 };
    smart_str xslt_location = { 0 };
    zval *params[2];
    zval retval, param1, param2;
    zval *param_array;
    zend_file_handle script;
    zval request_function;
    zval *operations;
    axutil_hash_index_t *hi = NULL;
    
    real_path = estrdup(SG(request_info).path_translated);
    path_len = 
        strlen(SG(request_info).path_translated)- strlen(SG(request_info).request_uri);
    real_path[path_len + 1] = '\0';
    
    smart_str_appends(&script_file_name, real_path);
    smart_str_appends(&xslt_location, real_path);
    
    
    smart_str_appends(&script_file_name, WS_WSDL_FILE_PATH);
    smart_str_0 (&script_file_name);
    
    smart_str_appends(&xslt_location, WS_WSDL_XSLT_PATH);
    smart_str_0(&xslt_location);
    
    params[0] = &param1;
    params[1] = &param2;
    
    MAKE_STD_ZVAL(param_array);
    array_init(param_array);
    add_assoc_string(param_array, WS_WSDL, wsdl_path, 1);
    
    
    MAKE_STD_ZVAL (operations);
    array_init (operations);
    if (svc_info->ops_to_functions) {
        for (hi =
                 axutil_hash_first (svc_info->ops_to_functions, env);
             hi; hi = axutil_hash_next (env, hi)) {
            void *v = NULL;
            const void *k = NULL;
            axis2_char_t * f_key = NULL;
            axutil_hash_this (hi, &k, NULL, &v);
            f_key = (axis2_char_t *) k;
            add_next_index_string (operations, (char *)f_key , 1);
        } 
    }	
    
    
    ZVAL_STRING(&request_function, WS_WSDL_SERVICE_REQ_FUNCTION, 0);
    add_assoc_string(param_array, WS_WSDL_XSLT_LOCATION, xslt_location.c, 1);
    
    ZVAL_ZVAL(params[0], param_array, NULL, NULL);
    INIT_PZVAL(params[0]);
    ZVAL_ZVAL(params[1], operations, NULL, NULL);
    INIT_PZVAL(params[1]);
    
    script.type = ZEND_HANDLE_FP;
    script.filename = script_file_name.c;
    script.opened_path = NULL;
    script.free_filename = 0;
    if (!(script.handle.fp = VCWD_FOPEN (script.filename, "rb"))){
        php_error_docref (NULL TSRMLS_CC, E_ERROR, 
                          "Unable to open script file: %s", script.filename);
        return;
    }
    else{
        php_lint_script (&script TSRMLS_CC);
        if (call_user_function (EG (function_table), (zval **) NULL,
                                &request_function, &retval, 2, 
                                params TSRMLS_CC) == SUCCESS ){
            if (Z_TYPE_P(&retval) == IS_STRING){
                svc_info->sig_model_string = Z_STRVAL_P(&retval);
                AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                                 "[wsf_wsdl]received data from scripts");
            }
            else if(Z_TYPE_P(&retval) == IS_ARRAY){
				zval **tmp = NULL;
                HashTable *ht_return = Z_ARRVAL_P(&retval);
                
                AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
                                "[wsf_wsdl]received array from scripts");
                if(zend_hash_find(ht_return, "sig_model_string", 
                                  sizeof("sig_model_string"), (void **)&tmp) == SUCCESS &&
                   Z_TYPE_PP(tmp) == IS_STRING){
                    svc_info->sig_model_string = Z_STRVAL_PP(tmp);
                    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
                                    "[wsf_wsdl]received sig model string");
                }
                                
            }
        }
    }
    
    
}
