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
#include <string.h>
#include <axutil_string.h>
#include "wsf_util.h"
#include <string.h>
#include <ruby.h>
#include "wsf_common.h"

axis2_status_t AXIS2_CALL wsf_xml_msg_recv_invoke_business_logic_sync (
    axis2_msg_recv_t * msg_recv,
    const axutil_env_t * env,
    axis2_msg_ctx_t * in_msg_ctx,
    axis2_msg_ctx_t * out_msg_ctx);

axiom_node_t *
wsf_util_deserialize_buffer (
    const axutil_env_t * env,
    char *buffer);

char *
wsf_util_serialize_om (
    const axutil_env_t * env,
    axiom_node_t * ret_node);

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
    axis2_char_t *classname,
    int enable_mtom,
    int request_xop );


static int wsf_xml_msg_recv_invoke_mixed (
    const axutil_env_t * env,
    wsf_svc_info_t * svc_info,
    axis2_msg_ctx_t * in_msg_ctx,
    axis2_msg_ctx_t * out_msg_ctx,
    axis2_char_t * op_name);

static void wsf_xml_msg_recv_set_soap_fault (
    const axutil_env_t * env,
    axis2_char_t * soap_ns,
    axis2_msg_ctx_t * out_msg_ctx,
    VALUE zval_soap_fault);

/************************** End of function prototypes ************************/

axis2_msg_recv_t *WSF_CALL
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
    axis2_char_t *classname = NULL;

    wsf_svc_info_t *svc_info = NULL;

    /** store in_msg_ctx envelope */
    axiom_soap_envelope_t *envelope = NULL;
    axiom_soap_body_t *body = NULL;

    /* store out_msg_ctx envelope */
    axiom_soap_envelope_t *default_envelope = NULL;

    axiom_soap_body_t *out_body = NULL;
    axiom_soap_header_t *out_header = NULL;
    axiom_soap_fault_t *soap_fault = NULL;

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
        axiom_soap_body_t *body = NULL;
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
        if(svc_info->ops_to_classes) {
            classname = axutil_hash_get(svc_info->ops_to_classes, local_name, AXIS2_HASH_KEY_STRING);
        }
    }
    else
    {
        AXIS2_LOG_ERROR (env->log, AXIS2_LOG_SI,
            "[wsf log] unable to access the msg ctx properties");
        return AXIS2_FAILURE;
    }

    if (svc_info->ht_op_params != Qnil) {
        /* CHANGED */
        VALUE tmp;
        char *function_type = NULL;
        if ((tmp = rb_hash_aref(svc_info->ht_op_params,
                ID2SYM(rb_intern("actions")))) != Qnil && TYPE(tmp) == T_STRING)
        {
            function_type = RSTRING(tmp)->ptr;
            if (strcmp (function_type, "MIXED") == 0) {
                int status = AXIS2_SUCCESS;
                status = wsf_xml_msg_recv_invoke_mixed (env, svc_info,
                    in_msg_ctx, out_msg_ctx, operation_name);
                return status;
            } else if (strcmp (function_type, "WSMESSAGE") == 0) {
                result_node =
                    wsf_xml_msg_recv_invoke_wsmsg (env, soap_ns,
                    operation_name,
                    om_node, out_msg_ctx,
                    classname, use_mtom, request_xop);
            }
        }
    } else {
        result_node =
            wsf_xml_msg_recv_invoke_wsmsg (env, soap_ns, operation_name,
            om_node, out_msg_ctx,
            classname, use_mtom, request_xop);
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

static int
wsf_xml_msg_recv_invoke_mixed (
    const axutil_env_t * env,
    wsf_svc_info_t * svc_info,
    axis2_msg_ctx_t * in_msg_ctx,
    axis2_msg_ctx_t * out_msg_ctx,
    axis2_char_t * op_name)
{
/*
    return wsf_soap_do_function_call (env,
        svc_info, in_msg_ctx, out_msg_ctx, op_name);
*/
	  return 0;
}

static axiom_node_t *
wsf_xml_msg_recv_invoke_wsmsg (
    const axutil_env_t * env,
    axis2_char_t * soap_ns,
    axis2_char_t * op_name,
    axiom_node_t * om_node,
    axis2_msg_ctx_t * out_msg_ctx,
    axis2_char_t* classname,
    int use_mtom,
    int request_xop)
{

    char *req_payload = NULL, *res_payload = NULL;
    axiom_node_t *res_om_node = NULL;
    void *val = NULL;
    int _bailout = 0;

    VALUE msg;
    VALUE msg_klass;
    VALUE fault_klass;
    VALUE msg_params[3];
    VALUE func;
    VALUE retval;
    VALUE param;

    VALUE user_klass;
    VALUE user_obj;
    VALUE res;

    VALUE v_op_name;

    if (!om_node)
        return NULL;

    req_payload = wsf_util_serialize_om (env, om_node);

    if (!req_payload) {
        AXIS2_LOG_ERROR (env->log, AXIS2_LOG_SI, "Request Payload is NULL");
        return NULL;
    }

    AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
        " [wsf_svr] calling ruby service ");

    /* zend_try { */
        msg_klass = rb_define_class("WSMessage", rb_cObject);
        /* msg_params[0] = rb_str_new2(req_payload); */
        msg = rb_str_new2(req_payload);

        /* CHANGED
        MAKE_STD_ZVAL (msg);
        object_init_ex (msg, ws_message_class_entry);
        add_property_string (msg, "str", req_payload, 1);
        */

        /* TODO
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

        }
        */

        /* ZVAL_STRING (&func, op_name, 0); */
        v_op_name = rb_str_new2(op_name);

        /*
        params[0] = &param;
        ZVAL_ZVAL (params[0], msg, NULL, NULL);
        INIT_PZVAL (params[0]);
        */

        if (NULL != classname)
        { 
            VALUE method_exists;
            
            user_klass = rb_define_class(classname, rb_cObject);
            user_obj = rb_class_new_instance(0, NULL, user_klass);

            if(user_obj != Qnil)
            {
            
                method_exists = rb_funcall(user_obj, rb_intern("respond_to?"), 2, rb_str_new2(op_name), Qtrue);
                if(method_exists == Qtrue)
                {
                    res = rb_funcall(user_obj, rb_intern(op_name), 1, msg);
                }
                else
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
                                            "[wsf log ]The method %s doesnt exist", op_name);

                    return NULL;
                }

                if(res != Qnil)
                {
                    if(TYPE(res) == T_STRING)
                    {
                        res_payload = axutil_strdup(env, RSTRING(res)->ptr);
                    }
                    else if(rb_obj_is_kind_of(res, msg_klass))
                    {
                        res_payload = axutil_strdup(env, RSTRING_PTR(
                                              rb_funcall(res, rb_intern("payload_to_s"), 0)));
                    }
                    else if(rb_obj_is_kind_of(res, fault_klass))
                    {
                        wsf_xml_msg_recv_set_soap_fault(env, soap_ns,
                            out_msg_ctx, res);
                    }
                }
            }
        }
            /*
            zend_lookup_class (classname, strlen (classname),
                &ce TSRMLS_CC);
            if (ce) { 
                if (call_user_function
                    (ft, (zval **) NULL, &func, &retval, 1,
                        params TSRMLS_CC) == SUCCESS) {
                    if (Z_TYPE (retval) == IS_STRING) {
                        res_payload = axutil_strdup (env, Z_STRVAL (retval));
                    } else if (Z_TYPE (retval) == IS_OBJECT &&
                        instanceof_function (Z_OBJCE (retval),
                            ws_fault_class_entry TSRMLS_CC)) {
                        wsf_xml_msg_recv_set_soap_fault (env, soap_ns,
                            out_msg_ctx, &retval TSRMLS_CC);
                    }
                }
            }
            */

        else
        {
            VALUE method_exists = rb_funcall(rb_cObject, rb_intern("respond_to?"), 2, rb_str_new2(op_name), Qtrue);
            if(method_exists == Qtrue)
            {
                res = rb_funcall(T_NIL, rb_intern(op_name), 1, msg);
            }
            else
            {
		        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[wsf log ]The method %s doesnt exist", op_name);

                return NULL;
            }

            if(res != Qnil)
            {
                if(rb_obj_is_kind_of(res, msg_klass))
                {
                    axis2_char_t *default_cnt_type = NULL;
                    VALUE v_default_cnt_type;
                    VALUE properties;
                    VALUE attachments;
                    VALUE v_action;
                    axis2_char_t *action;

                    properties = rb_funcall(res, rb_intern("properties"), 0);

                    v_default_cnt_type = rb_hash_aref(properties, ID2SYM(rb_intern("defaultAttachmentContentType")));
                    if(v_default_cnt_type == Qnil)
                    {
                        default_cnt_type = "application/octet-stream";
                    }
                    else
                    {
                        default_cnt_type = RSTRING(v_default_cnt_type)->ptr;
                    }

                    v_action = rb_hash_aref(properties, ID2SYM(rb_intern(WS_ACTION)));
                    action = RSTRING(v_action)->ptr;
                    axis2_msg_ctx_set_wsa_action(out_msg_ctx, env, action);
             
                    res_payload = RSTRING(rb_hash_aref(properties, ID2SYM(rb_intern("str"))))->ptr;
					AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
							            "[wsf log ]response payload %s", res_payload);

                    if(res_payload)
                    {
                        res_om_node = wsf_util_deserialize_buffer(env, res_payload);
                    }

                    attachments = rb_hash_aref(properties, ID2SYM(rb_intern("attachments")));

                    if(TYPE(attachments) == T_ARRAY)
                    {/*
                        wsf_util_set_attachments_with_cids (env, use_mtom,
                            res_om_node, attachments, default_cnt_type);
                        if (use_mtom == 1) 
                        {
                            axis2_msg_ctx_set_doing_mtom (out_msg_ctx, env,
                                AXIS2_TRUE);
                        }
						*/
                    }
                }
                else if(TYPE(res) == T_STRING)
                {
                    res_payload = RSTRING(res)->ptr;
                }
                else if(rb_obj_is_kind_of(res, fault_klass))
                {
                    wsf_xml_msg_recv_set_soap_fault(env, soap_ns,
                                    out_msg_ctx, res);
                }
            }
        }
        /*
        else if (call_user_function
            (CG (function_table), (zval **) NULL, &func, &retval, 1,
                params TSRMLS_CC) == SUCCESS) {
            if (Z_TYPE (retval) == IS_OBJECT
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
            } else if (Z_TYPE (retval) == IS_OBJECT &&
                instanceof_function (Z_OBJCE (retval),
                    ws_fault_class_entry TSRMLS_CC)) {
                wsf_xml_msg_recv_set_soap_fault (env, soap_ns, out_msg_ctx,
                    &retval TSRMLS_CC);
            }
        }
        zval_ptr_dtor(&msg);
    }

    zend_catch {
        if (EG(exception) && Z_TYPE_P(EG(exception)) == IS_OBJECT && 
                instanceof_function(Z_OBJCE_P(EG(exception)), ws_fault_class_entry TSRMLS_CC)) {
                 wsf_xml_msg_recv_set_soap_fault (env, soap_ns, out_msg_ctx,
                                             EG(exception) TSRMLS_CC);
        }else{
            _bailout = 1;
        }
        
    }
    zend_end_try ();

    if(_bailout){
        zend_bailout();
    }
    */
	  if(req_payload){
		    AXIS2_FREE(env->allocator, req_payload);
	  }

    if (!res_payload) {
        AXIS2_LOG_ERROR (env->log, AXIS2_LOG_SI, "Response Payload is NULL");
        return NULL;
    }
   
    res_om_node = wsf_util_deserialize_buffer (env, res_payload);
    return res_om_node;
}


static void
wsf_xml_msg_recv_set_soap_fault (
    const axutil_env_t * env,
    axis2_char_t * soap_ns,
    axis2_msg_ctx_t * out_msg_ctx,
    VALUE soap_fault)
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
    axis2_char_t *full_code = NULL;
    axis2_char_t *reason = NULL;
    axis2_char_t *detail = NULL;
    axis2_char_t *role = NULL;

    VALUE v_code;
    VALUE v_reason;
    VALUE v_detail;
    VALUE v_role;

    axiom_node_t *detail_node = NULL;


    /*
    smart_str fcode = {0};
    zval **tmp;
    */

    if (!soap_ns || !out_msg_ctx)
        return;

    if (strcmp (soap_ns, AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI) == 0) {
        soap_version = AXIOM_SOAP12;
    } else if (strcmp (soap_ns, AXIOM_SOAP11_SOAP_ENVELOPE_NAMESPACE_URI) ==
        0) 
    {
        soap_version = AXIOM_SOAP11;
    } else
        return;

    env_ns = axiom_namespace_create (env, soap_ns, "env");
    if (!env_ns) {
        return;
    }

    /*
    if (zend_hash_find
        (Z_OBJPROP_P (zval_soap_fault), WS_FAULT_REASON,
            sizeof (WS_FAULT_REASON), (void **) &tmp) == SUCCESS
        && Z_TYPE_PP (tmp) == IS_STRING) {
        reason = Z_STRVAL_PP (tmp);
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
            "[wsf_service] setting fault reason %s", reason);
    } else {
        php_error_docref (NULL TSRMLS_CC, E_ERROR,
            "invalid value,  soap fault (reason|string) missing");
    }
    */
    
    /* attachments = rb_hash_aref(properties, ID2SYM(rb_intern("attachments"))); */
    
    v_code = rb_funcall(soap_fault, rb_intern(WS_FAULT_CODE), 0);
    if(v_code != Qnil)
    {
        code = RSTRING(v_code)->ptr;
        full_code = (axis2_char_t*)AXIS2_MALLOC(env-> allocator, sizeof(axis2_char_t)*
                     (axutil_strlen(code) + axutil_strlen(AXIOM_SOAP_DEFAULT_NAMESPACE_PREFIX) + 2));
        sprintf(full_code, "%s:%s", AXIOM_SOAP_DEFAULT_NAMESPACE_PREFIX, code);
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
            "[wsf_service] setting fault code %s", code);
    }
    v_reason = rb_funcall(soap_fault, rb_intern(WS_FAULT_REASON), 0);
    if(v_reason != Qnil)
    {
        reason = RSTRING(v_reason)->ptr;
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
            "[wsf_service] setting fault reason %s", reason);
    }
    v_role = rb_funcall(soap_fault, rb_intern(WS_FAULT_ROLE), 0);
    if(v_role != Qnil)
    {
        role = RSTRING(v_role)->ptr;
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
            "[wsf_service] setting fault role %s", role);
    }
    v_detail = rb_funcall(soap_fault, rb_intern(WS_FAULT_DETAIL), 0);

    if(v_detail!= Qnil)
    {
        axiom_node_t *text_node = NULL;

        detail = RSTRING(v_detail)->ptr;
        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
            "[wsf_service] setting fault detail %s", detail);
        axiom_element_create (env, NULL, "error", NULL, &detail_node);
        axiom_text_create (env, detail_node, detail, &text_node);
    }
    
    /* 
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
        php_error_docref (NULL TSRMLS_CC, E_ERROR,
            " Invalid fault,fault code missing");
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
    */

    out_envelope = axiom_soap_envelope_create (env, env_ns);
    out_header = axiom_soap_header_create_with_parent(env, out_envelope);
    out_body = axiom_soap_body_create_with_parent (env, out_envelope);
    out_fault = axiom_soap_fault_create_default_fault (env, out_body,
        full_code, reason, soap_version);
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
    
    AXIS2_FREE(env->allocator, full_code);
}



