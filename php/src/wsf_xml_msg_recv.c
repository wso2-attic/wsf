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

#include <axis2_msg_recv.h>
#include "wsf_xml_msg_recv.h"
#include <string.h>
#include <axiom.h>
#include <axiom_soap.h>
#include <axutil_error.h>
#include <axutil_env.h>
#include <php.h>
#include <string.h>
#include <axutil_string.h>
#include "wsf_util.h"
#include <php.h>
#include <string.h>
#include "wsf.h"
#include <php_main.h>
#include "wsf_wsdl.h"

axis2_status_t AXIS2_CALL wsf_xml_msg_recv_invoke_business_logic_sync (
    axis2_msg_recv_t * msg_recv,
    const axutil_env_t * env,
    axis2_msg_ctx_t * in_msg_ctx,
    axis2_msg_ctx_t * out_msg_ctx);

/************************* Private Functions **********************************/

static axis2_char_t *wsf_xml_msg_recv_get_method_name (
    axis2_msg_ctx_t * msg_ctx,
    const axutil_env_t * env);

static axiom_node_t *wsf_xml_msg_recv_invoke_wsmsg (
    const axutil_env_t * env,
    axis2_char_t * soap_ns,
    axis2_char_t * op_name,
    axiom_node_t * om_node,
    axis2_msg_ctx_t * out_msg_ctx,
    char * classname,
	wsf_svc_info_t *svc_info,
    int enable_mtom,
    int request_xop TSRMLS_DC);


static axiom_node_t *wsf_xml_msg_recv_invoke_mixed (
    const axutil_env_t * env,
    wsf_svc_info_t * svc_info,
    axis2_msg_ctx_t * in_msg_ctx,
    axis2_msg_ctx_t * out_msg_ctx,
    axis2_char_t * op_name,
    axis2_char_t * class_name TSRMLS_DC);

static void wsf_xml_msg_recv_set_soap_fault (
    const axutil_env_t * env,
    axis2_char_t * soap_ns,
    axis2_msg_ctx_t * out_msg_ctx,
    zval *zval_soap_fault TSRMLS_DC);

/************************** End of function prototypes ************************/

WSF_PHP_API axis2_msg_recv_t *WSF_CALL
wsf_xml_msg_recv_create (
    const axutil_env_t * env)
{

    axis2_msg_recv_t *msg_recv = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    AXIS2_ENV_CHECK (env, NULL);
    msg_recv = axis2_msg_recv_create (env);

    if (NULL == msg_recv) {
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, "xml msg recv null");
        return NULL;
    }
    status = axis2_msg_recv_set_scope (msg_recv, env,
        AXIS2_APPLICATION_SCOPE);

    if (AXIS2_TRUE != status) {
        axis2_msg_recv_free (msg_recv, env);
        return NULL;
    }

    axis2_msg_recv_set_invoke_business_logic (msg_recv, env,
        wsf_xml_msg_recv_invoke_business_logic_sync);

    return msg_recv;
}

/***************************Function implementation****************************/

axis2_status_t AXIS2_CALL
wsf_xml_msg_recv_invoke_business_logic_sync (
    axis2_msg_recv_t * msg_recv,
    const axutil_env_t * env,
    axis2_msg_ctx_t * in_msg_ctx,
    axis2_msg_ctx_t * out_msg_ctx)
{

    axis2_op_ctx_t *op_ctx = NULL;
    axis2_op_t *op_desc = NULL;

    axiom_node_t *om_node = NULL;
    axiom_element_t *om_element = NULL;
    axiom_node_t *result_node = NULL;
    axiom_node_t *body_content_node = NULL;
    axiom_element_t *body_content_element = NULL;
    axiom_node_t *out_node = NULL;


    axiom_namespace_t *env_ns = NULL;
    axutil_property_t *prop = NULL;
    int soap_version = AXIOM_SOAP12;
    axis2_status_t status = AXIS2_SUCCESS;
    axis2_bool_t skel_invoked = AXIS2_FALSE;
    int use_mtom = AXIS2_TRUE;
	int request_xop = AXIS2_FALSE;

    const axis2_char_t *style = NULL;
    axis2_char_t *local_name = NULL;
    axis2_char_t *soap_ns = AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI;
    axis2_char_t *operation_name = NULL;
	char *classname = NULL;

    wsf_svc_info_t *svc_info = NULL;

    /** store in_msg_ctx envelope */
    axiom_soap_envelope_t *envelope = NULL;
	axiom_soap_body_t *body = NULL;


    /* store out_msg_ctx envelope */
    axiom_soap_envelope_t *default_envelope = NULL;

    axiom_soap_body_t *out_body = NULL;
    axiom_soap_header_t *out_header = NULL;
    axiom_soap_fault_t *soap_fault = NULL;

    TSRMLS_FETCH ();

    AXIS2_PARAM_CHECK (env->error, in_msg_ctx, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK (env->error, out_msg_ctx, AXIS2_FAILURE);

    op_ctx = axis2_msg_ctx_get_op_ctx (in_msg_ctx, env);
    op_desc = axis2_op_ctx_get_op (op_ctx, env);

    style = axis2_op_get_style (op_desc, env);

    envelope = axis2_msg_ctx_get_soap_envelope (in_msg_ctx, env);
    body = axiom_soap_envelope_get_body (envelope, env);


    if (0 == axutil_strcmp (AXIS2_STYLE_DOC, style)) {
        om_node = axiom_soap_body_get_base_node (body, env);
        om_element = axiom_node_get_data_element (om_node, env);
        om_node = axiom_node_get_first_child (om_node, env);
        local_name = wsf_xml_msg_recv_get_method_name (in_msg_ctx, env);

        if (!local_name) {

            return AXIS2_FAILURE;
        }
    } else if (0 == axutil_strcmp (AXIS2_STYLE_RPC, style)) {
     
        axiom_node_t *op_node = NULL;
        axiom_element_t *op_element = NULL;
        op_node = axiom_soap_body_get_base_node (body, env);
        op_element = axiom_node_get_data_element (op_node, env);

        if (!op_element) {

            return AXIS2_FAILURE;
        }
        local_name = axiom_element_get_localname (op_element, env);

        if (!local_name) {

            return AXIS2_FAILURE;
        }
        om_node = axiom_node_get_first_child (op_node, env);
        om_element = axiom_node_get_data_element (om_node, env);
    }

    /** set soap version and soap namespace to local variables */
    if (in_msg_ctx && axis2_msg_ctx_get_is_soap_11 (in_msg_ctx, env)) {

        soap_ns = AXIOM_SOAP11_SOAP_ENVELOPE_NAMESPACE_URI; /* default is 1.2 */
        soap_version = AXIOM_SOAP11;
    }

    prop = axis2_msg_ctx_get_property (in_msg_ctx, env, WS_SVC_INFO);
    if (prop) {
		svc_info = (wsf_svc_info_t *) axutil_property_get_value (prop, env);
        if (svc_info) {
            use_mtom = svc_info->use_mtom;
            request_xop = svc_info->request_xop;
            operation_name =
                axutil_hash_get (svc_info->ops_to_functions, local_name,
                AXIS2_HASH_KEY_STRING);
            if (!operation_name)
                return AXIS2_FAILURE;
        } else {
            return AXIS2_FAILURE;
        }
	    if(svc_info->ops_to_classes){
            classname = axutil_hash_get(svc_info->ops_to_classes, local_name, AXIS2_HASH_KEY_STRING);
        }
    }

    if (svc_info->ht_op_params) {
        zval **tmp;
        char *function_type = NULL;
        if (zend_hash_find (svc_info->ht_op_params,
                operation_name, strlen (operation_name) + 1,
                (void **) &tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_STRING) {
            function_type = Z_STRVAL_PP (tmp);
            if (strcmp (function_type, "MIXED") == 0) {
                result_node = wsf_xml_msg_recv_invoke_mixed (env, svc_info,
                    in_msg_ctx, out_msg_ctx, operation_name, classname TSRMLS_CC);
            } else if (strcmp (function_type, "WSMESSAGE") == 0) {
                result_node =
                    wsf_xml_msg_recv_invoke_wsmsg (env, soap_ns,
                    operation_name,
                    om_node, out_msg_ctx,
                    classname, svc_info, use_mtom, request_xop TSRMLS_CC);
            }
        }
    } else {
        /* this is where the default value for opParam is set,
           If the wsdl option is set go for the MIXED mode by default */
        if(svc_info->wsdl == NULL)
        {
            result_node =
                wsf_xml_msg_recv_invoke_wsmsg (env, soap_ns, operation_name,
                om_node, out_msg_ctx,
                classname, svc_info, use_mtom, request_xop TSRMLS_CC);
        }
        else
        {
            result_node = wsf_xml_msg_recv_invoke_mixed (env, svc_info,
                in_msg_ctx, out_msg_ctx, operation_name, classname TSRMLS_CC);
        }
    }
    if (!result_node) {

        status = AXIS2_ERROR_GET_STATUS_CODE (env->error);
    } else {
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
            "[wsf log]response node is not null");
    }

    prop = axis2_msg_ctx_get_property (in_msg_ctx, env, WS_SVC_INFO);
    if (result_node) {
        if (0 == axutil_strcmp (style, AXIS2_STYLE_RPC)) {

            axiom_namespace_t *ns = NULL;
            axis2_char_t *res_name = NULL;

            res_name = axutil_stracat (env, local_name, "Response");
            ns = axiom_namespace_create (env, "http://soapenc/", "res");
            if (!ns) {
                return AXIS2_FAILURE;
            }

            body_content_element = axiom_element_create (env, NULL, res_name,
                ns, &body_content_node);
            axiom_node_add_child (body_content_node, env, result_node);
        } else {

            body_content_node = result_node;
        }
    }



    if (axis2_msg_ctx_get_soap_envelope (out_msg_ctx, env)) {
        /* service implementation has set the envelope,
           useful when setting a SOAP fault.
           No need to further process */
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
            " *********** soap fault set *********");
        return AXIS2_SUCCESS;
    }

    /* create the soap envelope here */
    env_ns = axiom_namespace_create (env, soap_ns, "soapenv");
    if (!env_ns) {

        return AXIS2_FAILURE;
    }

    default_envelope = axiom_soap_envelope_create (env, env_ns);

    if (!default_envelope) {

        return AXIS2_FAILURE;
    }

    out_header = axiom_soap_header_create_with_parent (env, default_envelope);
    if (!out_header) {

        return AXIS2_FAILURE;
    }

    out_body = axiom_soap_body_create_with_parent (env, default_envelope);
    if (!out_body) {

        return AXIS2_FAILURE;
    }

    out_node = axiom_soap_body_get_base_node (out_body, env);
    if (!out_node) {

        return AXIS2_FAILURE;
    }

    if (status != AXIS2_SUCCESS) {

        /* something went wrong, set a SOAP Fault */
        axis2_char_t *fault_value_str = "env:Sender";
        axis2_char_t *fault_reason_str = NULL;
        axis2_char_t *err_msg = NULL;

        if (!skel_invoked)
            fault_value_str = "env:Receiver";

        err_msg = (char *) AXIS2_ERROR_GET_MESSAGE (env->error);

        if (err_msg) {

            fault_reason_str = err_msg;
        } else {

            fault_reason_str = "Error occured while processing SOAP message";
        }

        soap_fault = axiom_soap_fault_create_default_fault (env, out_body,
            fault_value_str, fault_reason_str, soap_version);
    }

    if (body_content_node) {

        axiom_node_add_child (out_node, env, body_content_node);
        status = axis2_msg_ctx_set_soap_envelope (out_msg_ctx, env,
            default_envelope);
    } else if (soap_fault) {

        axis2_msg_ctx_set_soap_envelope (out_msg_ctx, env, default_envelope);
        status = AXIS2_FAILURE; /* if there is a failure we have to return a failure code */
    } else {

        /* we should free the memory as the envelope is not used, one way case */
        axiom_soap_envelope_free (default_envelope, env);
        default_envelope = NULL;
    }


    return AXIS2_SUCCESS;
}


/**
 * Following block distinguish the exposed part of the dll.
 */
AXIS2_EXPORT int
axis2_get_instance (
    struct axis2_msg_recv **inst,
    const axutil_env_t * env)
{

    *inst = wsf_xml_msg_recv_create (env);
    if (!(*inst)) {

        return AXIS2_FAILURE;
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXPORT int
axis2_remove_instance (
    struct axis2_msg_recv *inst,
    const axutil_env_t * env)
{

    if (inst) {

        axis2_msg_recv_free (inst, env);
    }
    return AXIS2_SUCCESS;
}

/**
  * Private function implementations
  */
static axis2_char_t *
wsf_xml_msg_recv_get_method_name (
    axis2_msg_ctx_t * msg_ctx,
    const axutil_env_t * env)
{
    axis2_op_ctx_t *op_ctx = NULL;
    axis2_op_t *op = NULL;
    const axutil_qname_t *qname = NULL;
    axis2_char_t *name = NULL;

    op_ctx = axis2_msg_ctx_get_op_ctx (msg_ctx, env);

    if (!op_ctx) {

        AXIS2_LOG_ERROR (env->log, AXIS2_LOG_SI,
            "Operation Context is not found");
        return NULL;
    }

    op = axis2_op_ctx_get_op (op_ctx, env);

    if (!op) {

        AXIS2_LOG_ERROR (env->log, AXIS2_LOG_SI, "Operation is not found");
        return NULL;
    }

    qname = axis2_op_get_qname (op, env);

    if (!qname) {

        AXIS2_LOG_ERROR (env->log, AXIS2_LOG_SI,
            "Operation QName is not found");
        return NULL;
    }

    name = axutil_qname_get_localpart (qname, env);

    return name;
}

static axiom_node_t *
wsf_xml_msg_recv_invoke_mixed (
    const axutil_env_t * env,
    wsf_svc_info_t * svc_info,
    axis2_msg_ctx_t * in_msg_ctx,
    axis2_msg_ctx_t * out_msg_ctx,
    axis2_char_t * function_name,
    axis2_char_t * class_name TSRMLS_DC)
{
    axiom_soap_envelope_t *soap_envelope = NULL;
/*     axis2_char_t *soap_version_uri = NULL; */
    axiom_soap_body_t *soap_body = NULL;
    axiom_node_t *soap_body_node = NULL;
    char *in_msg_body_string = NULL;
    char *operation_name = NULL;
    axutil_hash_index_t * hi = NULL;

    char *real_path = NULL;
    int path_len = 0;
    smart_str script_file_name = { 0 };
    zval *params[1];
    zval request_function, retval, param1;
    zval *param_array;
    char *res_payload_str = NULL;
    axiom_node_t *res_om_node = NULL;
    axiom_node_t *soap_env_node = NULL;   

    zval *class_args;
    zval class_args_val;
    
    if (!in_msg_ctx || !function_name)
		return NULL;


    soap_envelope = axis2_msg_ctx_get_soap_envelope (in_msg_ctx, env);
    if(!soap_envelope){
        AXIS2_LOG_ERROR (env->log, AXIS2_LOG_SI,
                         "[wsf_wsdl] soap envelope not found");
		return NULL;
    }
    
    soap_body = axiom_soap_envelope_get_body(soap_envelope, env);
    if(!soap_body){
        AXIS2_LOG_ERROR (env->log, AXIS2_LOG_SI,
                         "[wsf_wsdl] soap body not found");
		return NULL;
    }
    soap_body_node = axiom_soap_body_get_base_node(soap_body, env);
    if(!soap_body_node){
        AXIS2_LOG_ERROR (env->log, AXIS2_LOG_SI,
                         "[wsf_wsdl] soap body base node not found");
		return NULL;
    }
    soap_env_node = axiom_soap_envelope_get_base_node(soap_envelope, env);
    in_msg_body_string = wsf_util_serialize_om(env, soap_env_node);
    if(in_msg_body_string){
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                     "[wsf_wsdl]Input soap body is \t %s \n", in_msg_body_string);
    }
    

    if(class_name && svc_info->class_args)
    {
        zval **tmp;
        if(zend_hash_find(Z_ARRVAL_P(svc_info->class_args), class_name, 
            strlen(class_name)+1, (void**)&tmp) == SUCCESS)
        {
            class_args = *tmp;        
            /* zval_add_ref(class_arg); */
        }
        else
        {
            class_args = &class_args_val;
            ZVAL_NULL(class_args);
            INIT_PZVAL(class_args);
        }
    }
    else
    {
          class_args = &class_args_val;
          ZVAL_NULL(class_args);
          INIT_PZVAL(class_args);
    }
    if(svc_info->sig_model_string){
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                         "[wsf_wsdl]sig model string found is \t \n %s \n", svc_info->sig_model_string);
    }
    else{
        zval ** server_vars, **data;
        char *server_name = NULL;
        char *port = NULL;
        smart_str req_uri = { 0 };

        if(SG(request_info).request_uri){
            if (zend_hash_find (&EG (symbol_table), "_SERVER", sizeof ("_SERVER"),
                                (void **) & server_vars) == SUCCESS && (Z_TYPE_PP (server_vars) == IS_ARRAY)) {
                if ((zend_hash_find (Z_ARRVAL_PP (server_vars), "SERVER_NAME",
                                     sizeof ("SERVER_NAME"), (void **)&data) == SUCCESS)  &&
                    Z_TYPE_PP (data) == IS_STRING) {
                    server_name = Z_STRVAL_PP (data);
                }
                if ((zend_hash_find (Z_ARRVAL_PP (server_vars), "SERVER_PORT",
                                     sizeof ("SERVER_PORT"), (void **)&data) == SUCCESS)  &&
                    Z_TYPE_PP (data) == IS_STRING) {
                    port = Z_STRVAL_PP (data);
                }
            }
            
            smart_str_appends(&req_uri, "http://");
            smart_str_appends(&req_uri, server_name);
            smart_str_appends(&req_uri, ":");
            smart_str_appends(&req_uri, port);
            smart_str_appends(&req_uri, SG(request_info).request_uri);
            smart_str_appends(&req_uri, "?wsdl");

            smart_str_0(&req_uri);
            wsf_wsdl_set_sig_model(req_uri.c, svc_info, env TSRMLS_CC);
        }
    }


    real_path = estrdup(SG(request_info).path_translated);
    path_len = strlen(SG(request_info).path_translated)- strlen(SG(request_info).request_uri);
    real_path[path_len + 1] = '\0';

    /* find the operation name */
    if (svc_info->ops_to_functions) {
        for (hi = axutil_hash_first (svc_info->ops_to_functions, env);hi;
             hi = axutil_hash_next (env, hi)) {
            void *v = NULL;
            const void *k = NULL;
            axutil_hash_this (hi, &k, NULL, &v);
            if(strcmp(function_name, (axis2_char_t *) v) == 0){
                operation_name = (axis2_char_t *) k;
                break;
            }
        } 
    }


    smart_str_appends(&script_file_name, real_path);
    smart_str_appends(&script_file_name, "scripts/dynamic_invocation/wsf_wsdl.php");
    smart_str_0 (&script_file_name);

    params[0] = &param1;

    MAKE_STD_ZVAL(param_array);
    array_init(param_array);

    add_assoc_string(param_array, "sig_model_string",  svc_info->sig_model_string, 1);
    add_assoc_string(param_array, "payload_string", in_msg_body_string, 1);
    add_assoc_string(param_array, "operation_name", operation_name, 1);
    add_assoc_string(param_array, "function_name", function_name, 1);
    if(class_name)
    {
        add_assoc_string(param_array, "class_name", class_name, 1);
    }
    add_assoc_zval(param_array, WS_WSDL_CLASSMAP, svc_info->class_map);

    
    add_assoc_zval(param_array, "class_args", class_args);

    ZVAL_STRING(&request_function, "wsf_wsdl_process_in_msg", 0);
    ZVAL_ZVAL(params[0], param_array, NULL, NULL);
    INIT_PZVAL(params[0]);
        
    if (call_user_function (EG (function_table), (zval **) NULL,
                            &request_function, &retval, 1, params TSRMLS_CC) == SUCCESS ){
        if(Z_TYPE_P(&retval) == IS_STRING){
            res_payload_str = Z_STRVAL_P(&retval);
            AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                             "[wsf_wsdl]return payload string is\t %s", res_payload_str);
            
        }
    }
    
    if(!res_payload_str)
        AXIS2_LOG_ERROR (env->log, AXIS2_LOG_SI,
                         "[wsf_wsdl] response payload string not found");
    
    res_om_node = wsf_util_deserialize_buffer(env, res_payload_str);
        
    if(res_om_node)
        return res_om_node; 
    else
        return NULL;
}

static axiom_node_t *
wsf_xml_msg_recv_invoke_wsmsg (
    const axutil_env_t * env,
    axis2_char_t * soap_ns,
    axis2_char_t * op_name,
    axiom_node_t * om_node,
    axis2_msg_ctx_t * out_msg_ctx,
    char * class_name,
	wsf_svc_info_t *svc_info,
    int use_mtom,
    int request_xop TSRMLS_DC)
{

    char *req_payload = NULL, *res_payload = NULL;
    axiom_node_t *res_om_node = NULL;
    zval func, retval, param;
    zval *params[1];
    HashTable *ft = NULL;
    zend_class_entry **ce = NULL;
    zval *msg = NULL;
    int _bailout = 0;

    if (!om_node)
        return NULL;

    AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
        " [wsf_svr] calling php service ");
    zend_try {
        MAKE_STD_ZVAL (msg);
        object_init_ex (msg, ws_message_class_entry);
        
        if (request_xop == AXIS2_TRUE) {

            zval *cid2str = NULL;
            zval *cid2contentType = NULL;

            AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                "[wsf_service] requestXOP is TRUE, setting attachements");

            MAKE_STD_ZVAL (cid2str);
            MAKE_STD_ZVAL (cid2contentType);

            array_init (cid2str);
            array_init (cid2contentType);

            wsf_util_get_attachments (env, om_node, cid2str,
                cid2contentType TSRMLS_CC);

            add_property_zval (msg, "attachments", cid2str);
            add_property_zval (msg, "cid2contentType", cid2contentType);

		}else if(request_xop == AXIS2_FALSE){
			wsf_util_find_xop_content_and_convert_to_base64(env, om_node);
		}

		/** this should be after mtom processing */
		req_payload = wsf_util_serialize_om (env, om_node);
		add_property_string (msg, "str", req_payload, 1);


        ZVAL_STRING (&func, op_name, 0);
        params[0] = &param;
        ZVAL_ZVAL (params[0], msg, NULL, NULL);
        INIT_PZVAL (params[0]);

		if (class_name){
			zval **argv = NULL;
            zval **tmp = NULL;
			int argc =0;

            zend_lookup_class (class_name, strlen (class_name), &ce TSRMLS_CC);
			if(class_name && svc_info->class_args){
				if(zend_hash_find(Z_ARRVAL_P(svc_info->class_args), class_name, 
                    strlen(class_name)+1, (void**)&tmp) == SUCCESS){
    				if(Z_TYPE_PP(tmp) == IS_ARRAY){
                        zval **tmp1 = NULL;
                        HashPosition pos;
                        int i =0;
	    				argc = zend_hash_num_elements(Z_ARRVAL_PP(tmp));
                        argv = safe_emalloc(sizeof(zval), argc, 0);

                        zend_hash_internal_pointer_reset_ex (Z_ARRVAL_PP(tmp), &pos);
                        while(zend_hash_get_current_data_ex(Z_ARRVAL_PP(tmp), (void**)&tmp1, &pos) != FAILURE){
                            argv[i] = *tmp1;
                            i++;
                            zend_hash_move_forward_ex (Z_ARRVAL_PP(tmp), &pos);
                        }
		    		}
			   	}
			}
            if (*ce) {
				/* call constuctor function */
				zval *tmp_cls_obj;
				MAKE_STD_ZVAL(tmp_cls_obj);
				object_init_ex(tmp_cls_obj, *ce);
				if(zend_hash_exists(&Z_OBJCE_P(tmp_cls_obj)->function_table, 
					ZEND_CONSTRUCTOR_FUNC_NAME, sizeof(ZEND_CONSTRUCTOR_FUNC_NAME))){
						zval c_ret, constructor;
						INIT_ZVAL(c_ret);
						INIT_ZVAL(constructor);

						ZVAL_STRING(&constructor, ZEND_CONSTRUCTOR_FUNC_NAME, 1);
						if(call_user_function(NULL, &tmp_cls_obj, &constructor, &c_ret, argc, argv TSRMLS_CC) == FAILURE){
							php_error_docref(NULL TSRMLS_CC, E_ERROR, "Error Calling the constructor ");	
						}
						zval_dtor(&constructor);
						zval_dtor(&c_ret);
				}else if(zend_hash_exists(&Z_OBJCE_P(tmp_cls_obj)->function_table, 
					class_name, strlen(class_name)) == SUCCESS){
						zval c_ret, constructor;
						INIT_ZVAL(c_ret);
						INIT_ZVAL(constructor);

						ZVAL_STRING(&constructor, class_name, 1);
						if(call_user_function(NULL, &tmp_cls_obj, &constructor, &c_ret, argc, argv TSRMLS_CC) == FAILURE){
							php_error_docref(NULL TSRMLS_CC, E_ERROR, "Error Calling the constructor ");	
						}
						zval_dtor(&constructor);
						zval_dtor(&c_ret);
				}
				
                ft = &(*ce)->function_table;
				if(zend_hash_exists(ft, op_name, strlen(op_name)) == SUCCESS){
					if (call_user_function(NULL, &tmp_cls_obj, &func, &retval, 1, params TSRMLS_CC) != SUCCESS) {
					    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_xml_msg_recv] call_user_function failed ");
    					return NULL;
                    }
				}
			}
		}else if (call_user_function(CG (function_table), (zval **) NULL, &func, 
                    &retval, 1, params TSRMLS_CC) != SUCCESS) {
			AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[wsf_xml_msg_recv] call_user_function failed ");
			return NULL;
		}
            if (EG(exception) && Z_TYPE_P(EG(exception)) == IS_OBJECT &&
               instanceof_function(Z_OBJCE_P(EG(exception)), ws_fault_class_entry TSRMLS_CC)) {
                  wsf_xml_msg_recv_set_soap_fault (env, soap_ns, out_msg_ctx,
                  EG(exception) TSRMLS_CC);
                  zend_clear_exception(TSRMLS_C);
            }else if (Z_TYPE (retval) == IS_OBJECT
                && instanceof_function (Z_OBJCE (retval),
                    ws_message_class_entry TSRMLS_CC)) {
                zval **msg_tmp = NULL;
                axis2_char_t *default_cnt_type = NULL;

                if (zend_hash_find
                    (Z_OBJPROP (retval), "defaultAttachmentContentType",
                        sizeof ("defaultAttachmentContentType"),
                        (void **) & msg_tmp) == SUCCESS
                    && Z_TYPE_PP (msg_tmp) == IS_STRING) {
                    default_cnt_type = Z_STRVAL_PP (msg_tmp);
                } else {
                    default_cnt_type = "application/octet-stream";
                }
                
				if (zend_hash_find (Z_OBJPROP(retval), WS_ACTION, sizeof (WS_ACTION),
                	(void **) &msg_tmp) == SUCCESS && Z_TYPE_PP(msg_tmp) == IS_STRING) {
                        axis2_char_t *action = NULL;
                        action = Z_STRVAL_PP (msg_tmp);
                        axis2_msg_ctx_set_wsa_action (out_msg_ctx, env, action);
                }

                if (zend_hash_find (Z_OBJPROP (retval), "str", sizeof ("str"),
                   (void **) & msg_tmp) == SUCCESS && Z_TYPE_PP (msg_tmp) == IS_STRING) {

						res_payload = Z_STRVAL_PP (msg_tmp);
						AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
							"[wsf log ]response payload %s", res_payload);
						if (res_payload) {
							res_om_node = wsf_util_deserialize_buffer (env, res_payload);
						}
                }
                if (zend_hash_find (Z_OBJPROP (retval), "attachments", sizeof ("attachments"),
                   (void **) & msg_tmp) == SUCCESS && Z_TYPE_PP (msg_tmp) == IS_ARRAY) {

                    HashTable *ht = NULL;
                    ht = Z_ARRVAL_PP (msg_tmp);
                    if (ht && res_om_node) {
                        wsf_util_set_attachments_with_cids (env, use_mtom,
                            res_om_node, ht, default_cnt_type TSRMLS_CC);
                        if (use_mtom == 1) {
                            axis2_msg_ctx_set_doing_mtom (out_msg_ctx, env,
                                AXIS2_TRUE);
                        }
                    }
                }
            } else if (Z_TYPE (retval) == IS_STRING) {
                res_payload =  Z_STRVAL (retval);
                if (res_payload) {
                    res_om_node = wsf_util_deserialize_buffer (env, res_payload);
                }
            } /*
                else if (Z_TYPE (retval) == IS_OBJECT &&
                instanceof_function (Z_OBJCE (retval),
                    ws_fault_class_entry TSRMLS_CC)) {
                wsf_xml_msg_recv_set_soap_fault (env, soap_ns, out_msg_ctx,
                    &retval TSRMLS_CC);
                zend_clear_exception(TSRMLS_C);
            }
            */
         zval_ptr_dtor(&msg); 
    }
    
    zend_catch {
        
        if (EG(exception) && Z_TYPE_P(EG(exception)) == IS_OBJECT && 
                instanceof_function(Z_OBJCE_P(EG(exception)), ws_fault_class_entry TSRMLS_CC)) {
            wsf_xml_msg_recv_set_soap_fault (env, soap_ns, out_msg_ctx,
                                             EG(exception) TSRMLS_CC);
            zend_clear_exception(TSRMLS_C);
        }else{
            _bailout = 1;
        }
    }
    zend_end_try ();

    if(_bailout){
        zend_bailout();
    }
	if(req_payload){
		AXIS2_FREE(env->allocator, req_payload);
	}

    if (!res_payload) {
        AXIS2_LOG_ERROR (env->log, AXIS2_LOG_SI, "Response Payload is NULL");
        return NULL;
    }
    return res_om_node;
}


static void
wsf_xml_msg_recv_set_soap_fault (
    const axutil_env_t * env,
    axis2_char_t * soap_ns,
    axis2_msg_ctx_t * out_msg_ctx,
    zval *zval_soap_fault TSRMLS_DC)
{
    int soap_version = AXIOM_SOAP12;

    axiom_soap_envelope_t *out_envelope = NULL;
    axiom_soap_header_t *out_header = NULL;
    axiom_soap_body_t *out_body = NULL;
    axiom_soap_fault_t *out_fault = NULL;
    axiom_soap_fault_detail_t *fault_detail = NULL;
    axiom_soap_fault_role_t *fault_role = NULL;
    axiom_namespace_t *env_ns = NULL;
    axis2_char_t *code = NULL;
    axis2_char_t *reason = NULL;
    axis2_char_t *detail = NULL;
    axis2_char_t *role = NULL;

    axiom_node_t *detail_node = NULL;


    smart_str fcode = {0};
    zval **tmp;

    if (!soap_ns || !out_msg_ctx)
        return;

    if (strcmp (soap_ns, AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI) == 0) {
        soap_version = AXIOM_SOAP12;
    } else if (strcmp (soap_ns, AXIOM_SOAP11_SOAP_ENVELOPE_NAMESPACE_URI) == 0) {
        soap_version = AXIOM_SOAP11;
    } else
        return;

    env_ns = axiom_namespace_create (env, soap_ns, "env");
    if (!env_ns) {
        return;
    }

    if (zend_hash_find
        (Z_OBJPROP_P (zval_soap_fault), WS_FAULT_REASON,
            sizeof (WS_FAULT_REASON), (void **) &tmp) == SUCCESS
        && Z_TYPE_PP (tmp) == IS_STRING) {
        reason = Z_STRVAL_PP (tmp);
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
            "[wsf_service] setting fault reason %s", reason);
    } else {
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,"[wsf_service]invalid soap fault (reason|string) missing");
		reason = "Error Reason unspecified";
    }

    if (zend_hash_find
        (Z_OBJPROP_P (zval_soap_fault), WS_FAULT_CODE, sizeof (WS_FAULT_CODE),
            (void **) &tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_STRING) {
        smart_str_appends(&fcode,AXIOM_SOAP_DEFAULT_NAMESPACE_PREFIX);
        smart_str_appends(&fcode, ":");
        smart_str_appends(&fcode,Z_STRVAL_PP (tmp));
        smart_str_0(&fcode);
        code = fcode.c;
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
            "[wsf_service] setting fault code %s", code);
    } else {
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,"[wsf_service]invalid soap fault (reason|string) missing");
		code = "Receiver";
    }

    if (zend_hash_find
        (Z_OBJPROP_P (zval_soap_fault), WS_FAULT_ROLE, sizeof (WS_FAULT_ROLE),
            (void **) &tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_STRING) {
        role = Z_STRVAL_PP (tmp);
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
            "[wsf_service] setting fault role %s", role);
    }
    if (zend_hash_find
        (Z_OBJPROP_P (zval_soap_fault), WS_FAULT_DETAIL,
            sizeof (WS_FAULT_DETAIL), (void **) &tmp) == SUCCESS
        && Z_TYPE_PP (tmp) == IS_STRING) {
        axiom_node_t *text_node = NULL;
        detail = Z_STRVAL_PP (tmp);
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
            "[wsf_service] setting fault detail %s", detail);
        axiom_element_create (env, NULL, "error", NULL, &detail_node);
        axiom_text_create (env, detail_node, detail, &text_node);
    }

    out_envelope = axiom_soap_envelope_create (env, env_ns);
    out_header = axiom_soap_header_create_with_parent(env, out_envelope);
    out_body = axiom_soap_body_create_with_parent (env, out_envelope);
    out_fault = axiom_soap_fault_create_default_fault (env, out_body,
        code, reason, soap_version);
    if (detail) {
        fault_detail =
            axiom_soap_fault_detail_create_with_parent (env, out_fault);
        axiom_soap_fault_detail_add_detail_entry (fault_detail, env,
            detail_node);
    }
    if (role) {
        fault_role =
            axiom_soap_fault_role_create_with_parent (env, out_fault);
        axiom_soap_fault_role_set_role_value (fault_role, env, role);
    }
    axis2_msg_ctx_set_soap_envelope (out_msg_ctx, env, out_envelope);
    smart_str_free(&fcode);
}
