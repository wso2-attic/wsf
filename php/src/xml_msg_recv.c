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
#include <axis2_util.h>
#include <axis2_error.h>
#include <axis2_env.h>
#include <php.h>
#include <string.h>
#include <axis2_string.h>
#include "wsf_util.h"
#include <php.h>
#include <string.h>
#include <axis2_string.h>
#include "wsf.h"

axis2_status_t AXIS2_CALL
ws_xml_msg_recv_invoke_business_logic_sync(
    axis2_msg_recv_t *msg_recv,
	const axis2_env_t *env,
	axis2_msg_ctx_t *in_msg_ctx,
	axis2_msg_ctx_t *out_msg_ctx);

/************************* Overridden Functions *******************************/
axis2_svc_skeleton_t * AXIS2_CALL
ws_xml_msg_recv_make_new_svc_obj(
    axis2_msg_recv_t *msg_recv,
	const axis2_env_t *env,
	struct axis2_msg_ctx *msg_ctx);

axis2_svc_skeleton_t * AXIS2_CALL
ws_xml_msg_recv_get_impl_obj(
    axis2_msg_recv_t *msg_recv,
	const axis2_env_t *env,
	struct axis2_msg_ctx *msg_ctx);

axis2_status_t AXIS2_CALL
ws_xml_msg_recv_delete_svc_obj(
    axis2_msg_recv_t *msg_recv,
	const axis2_env_t *env,
	axis2_msg_ctx_t *msg_ctx);

/************************* Private Functions **********************************/

static axis2_char_t* 
ws_xml_msg_recv_get_method_name(
    axis2_msg_ctx_t *msg_ctx,
	const axis2_env_t *env);
	
static axiom_node_t* 
ws_xml_msg_recv_invoke(
    const axis2_env_t *env,
	axis2_char_t *soap_ns,	
	axis2_char_t *op_name, 
	axiom_node_t *om_node, 
	axis2_msg_ctx_t *out_msg_ctx,
	axis2_hash_t *class_info,
    int enable_mtom,
    int request_xop);

static axis2_char_t* 
ws_xml_msg_recv_serialize_om(
    const axis2_env_t *env, 
	axiom_node_t *node);

static void 
ws_xml_msg_recv_set_soap_fault(
    const axis2_env_t *env,
    axis2_char_t *soap_ns,
    axis2_msg_ctx_t *out_msg_ctx,
    zval zval_soap_fault TSRMLS_DC);    
    
/************************** End of function prototypes ************************/

WSF_PHP_API axis2_msg_recv_t* WSF_CALL
ws_xml_msg_recv_create(const axis2_env_t *env){

	axis2_msg_recv_t *msg_recv = NULL;
	axis2_status_t status = AXIS2_FAILURE;
	
	AXIS2_ENV_CHECK(env, NULL);
	msg_recv = axis2_msg_recv_create(env);

	if(NULL == msg_recv){
		AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "xml msg recv null");
		return NULL;
 	}   
	status = AXIS2_MSG_RECV_SET_SCOPE(msg_recv, env, AXIS2_APPLICATION_SCOPE);
	
       if(AXIS2_TRUE != status){
		AXIS2_MSG_RECV_FREE(msg_recv, env);
		return NULL;
	}
    
	msg_recv->ops->invoke_in_out_business_logic_sync = 
		ws_xml_msg_recv_invoke_business_logic_sync;
	msg_recv->ops->make_new_svc_obj = 
		ws_xml_msg_recv_make_new_svc_obj;
	msg_recv->ops->get_impl_obj =
		ws_xml_msg_recv_get_impl_obj;
	msg_recv->ops->delete_svc_obj =
		ws_xml_msg_recv_delete_svc_obj;
	msg_recv->ops->receive = 
	    msg_recv->ops->receive_sync;
	return msg_recv;
}

/***************************Function implementation****************************/

axis2_status_t AXIS2_CALL
ws_xml_msg_recv_invoke_business_logic_sync(
    axis2_msg_recv_t *msg_recv,
    const axis2_env_t *env, 
    axis2_msg_ctx_t *in_msg_ctx, 
    axis2_msg_ctx_t *out_msg_ctx)
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
	axis2_property_t *prop = NULL;
	/*
	int is_class = 0;
	*/
	int soap_version = AXIOM_SOAP12;
	axis2_status_t status = AXIS2_SUCCESS;
	axis2_bool_t skel_invoked = AXIS2_FALSE;
	int use_mtom = AXIS2_TRUE;
	int request_xop = AXIS2_FALSE;

	axis2_hash_t *class_info = NULL;
	const axis2_char_t *style = NULL;
	axis2_char_t *local_name = NULL;
	axis2_char_t *soap_ns = AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI;
	axis2_char_t *operation_name = NULL;


	    /** stote in_msg_ctx envelope */
	axiom_soap_envelope_t *envelope = NULL;

	    /* store out_msg_ctx envelope */
	axiom_soap_envelope_t *default_envelope = NULL;

	axiom_soap_body_t *out_body = NULL;
	axiom_soap_header_t *out_header = NULL;
	axiom_soap_fault_t *soap_fault = NULL;


	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
	AXIS2_PARAM_CHECK(env->error, in_msg_ctx, AXIS2_FAILURE);
	AXIS2_PARAM_CHECK(env->error, out_msg_ctx, AXIS2_FAILURE);


	op_ctx = axis2_msg_ctx_get_op_ctx(in_msg_ctx, env);
	op_desc = axis2_op_ctx_get_op(op_ctx, env);

	style = axis2_op_get_style(op_desc, env);
	
	if(0 == AXIS2_STRCMP(AXIS2_STYLE_DOC, style)){
    
		axiom_soap_body_t *body = NULL;
			
		envelope = axis2_msg_ctx_get_soap_envelope(in_msg_ctx, env);
		body = axiom_soap_envelope_get_body(envelope, env);
		om_node = axiom_soap_body_get_base_node(body, env);
		om_element = axiom_node_get_data_element(om_node, env);
		om_node = axiom_node_get_first_child(om_node, env); 
		local_name = ws_xml_msg_recv_get_method_name(in_msg_ctx, env);

		if (!local_name){
        
			return AXIS2_FAILURE;
		}
	}
	else if(0 == AXIS2_STRCMP(AXIS2_STYLE_RPC, style)){
		axiom_soap_body_t *body = NULL;
		axiom_node_t *op_node = NULL;
		axiom_element_t *op_element = NULL;
			
		envelope = axis2_msg_ctx_get_soap_envelope(in_msg_ctx, env);
		body = axiom_soap_envelope_get_body(envelope, env);
		op_node = axiom_soap_body_get_base_node(body, env);
		op_element = axiom_node_get_data_element(op_node, env);
        
		if(!op_element)	{
        
			return AXIS2_FAILURE;
		}
		local_name = axiom_element_get_localname(op_element, env);
		
        if(!local_name)	{
        
			return AXIS2_FAILURE;
		}
		om_node = axiom_node_get_first_child(op_node, env);
		om_element = axiom_node_get_data_element(om_node, env);   
	}

    /** set soap version and soap namespace to local variables */
    if (in_msg_ctx && axis2_msg_ctx_get_is_soap_11(in_msg_ctx, env)){
    
		soap_ns = AXIOM_SOAP11_SOAP_ENVELOPE_NAMESPACE_URI; /* default is 1.2 */
		soap_version = AXIOM_SOAP11;
	}

    prop = axis2_msg_ctx_get_property(in_msg_ctx, env, WS_SVC_INFO, AXIS2_FALSE);
    if(prop){
        ws_svc_info_t *svc_info = (ws_svc_info_t *)AXIS2_PROPERTY_GET_VALUE(prop, env);
        if (svc_info){
            class_info = svc_info->class_info;
            use_mtom   = svc_info->use_mtom;
            request_xop = svc_info->request_xop;
            operation_name = axis2_hash_get(svc_info->ops_to_functions, local_name, AXIS2_HASH_KEY_STRING);
            if(!operation_name)
                return AXIS2_FAILURE;            
        }else{
            return AXIS2_FAILURE;
        }
    }  
	
	result_node = ws_xml_msg_recv_invoke(env, soap_ns, operation_name, om_node, 
        out_msg_ctx, class_info, use_mtom, request_xop);
	
	if (!result_node){
    
		status = AXIS2_ERROR_GET_STATUS_CODE(env->error);
	}else{
		AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf log]response node is not null");
	}

    prop = axis2_msg_ctx_get_property(in_msg_ctx, env, WS_SVC_INFO, AXIS2_FALSE);
    if(result_node)
    {
    	if(0 == AXIS2_STRCMP(style, AXIS2_STYLE_RPC)){
    
	    	axiom_namespace_t *ns = NULL;
		    axis2_char_t *res_name = NULL;
				
    		res_name = AXIS2_STRACAT(local_name, "Response", env);
	    	ns = axiom_namespace_create(env, "http://soapenc/", "res");
    		if(!ns)	{
    			return AXIS2_FAILURE;
	    	}
		
		    body_content_element = axiom_element_create(env, NULL, res_name, 
			    						ns, &body_content_node);
    		AXIOM_NODE_ADD_CHILD(body_content_node, env, result_node);
	    }				
    	else{
    
	    	body_content_node = result_node;
	    }
	}
    
	

	if (axis2_msg_ctx_get_soap_envelope(out_msg_ctx, env)){
		/* service implementation has set the envelope, 
		   useful when setting a SOAP fault.
		   No need to further process */
		   AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, " *********** soap fault set *********");
		   return AXIS2_SUCCESS;
	}
	
	/* create the soap envelope here*/
	env_ns = axiom_namespace_create(env, soap_ns, "soapenv"); 
	if (!env_ns){
    
		return AXIS2_FAILURE;
	}
	
	default_envelope = axiom_soap_envelope_create(env, env_ns);

	if (!default_envelope){
    
		return AXIS2_FAILURE;
	}

	out_header = axiom_soap_header_create_with_parent(env, default_envelope);
	if (!out_header){
    
		return AXIS2_FAILURE;
	}

	out_body = axiom_soap_body_create_with_parent(env, default_envelope);
	if (!out_body){
    
		return AXIS2_FAILURE;
	}

	out_node = axiom_soap_body_get_base_node(out_body, env);
	if (!out_node){
    
		return AXIS2_FAILURE;
	}
	
	if (status != AXIS2_SUCCESS){
    
		/* something went wrong. set a SOAP Fault*/
		axis2_char_t *fault_value_str = "env:Sender";
		axis2_char_t *fault_reason_str = NULL;
		axis2_char_t *err_msg = NULL;
		
		if (!skel_invoked)
			fault_value_str = "env:Receiver";
			
		err_msg =(char*) AXIS2_ERROR_GET_MESSAGE(env->error);
		
        if (err_msg){
        
			fault_reason_str = err_msg;
		}
		else{
        
			fault_reason_str = "Something went wrong";
		}
			
		soap_fault = axiom_soap_fault_create_default_fault(env, out_body, 
			fault_value_str, fault_reason_str, soap_version);
	}

	if (body_content_node){
    
		AXIOM_NODE_ADD_CHILD(out_node , env, body_content_node);
		status = axis2_msg_ctx_set_soap_envelope(out_msg_ctx, env, default_envelope);
	}
	else if (soap_fault){
    
		axis2_msg_ctx_set_soap_envelope(out_msg_ctx, env, default_envelope);
		status = AXIS2_FAILURE; /* if there is a failure we have to return a failure code */
	}
	else{
    
		/* we should free the memory as the envelope is not used, one way case */
		axiom_soap_envelope_free(default_envelope, env);
		default_envelope = NULL;
	}
	

	return AXIS2_SUCCESS;
}

axis2_svc_skeleton_t * AXIS2_CALL
ws_xml_msg_recv_make_new_svc_obj(axis2_msg_recv_t *msg_recv,
	const axis2_env_t *env, struct axis2_msg_ctx *msg_ctx){

	AXIS2_LOG_WARNING(env->log, AXIS2_LOG_SI, "Not Implemented");
	return NULL;
}

axis2_svc_skeleton_t * AXIS2_CALL
ws_xml_msg_recv_get_impl_obj(axis2_msg_recv_t *msg_recv,
    const axis2_env_t *env, struct axis2_msg_ctx *msg_ctx){
    
	AXIS2_LOG_WARNING(env->log, AXIS2_LOG_SI, "Not Implemented");
	return NULL;
}

axis2_status_t AXIS2_CALL
ws_xml_msg_recv_delete_svc_obj(axis2_msg_recv_t *msg_recv,
	const axis2_env_t *env, axis2_msg_ctx_t *msg_ctx){
    
	AXIS2_LOG_WARNING(env->log, AXIS2_LOG_SI, "Not Implemented");
	return AXIS2_SUCCESS;
}

/**
 * Following block distinguish the exposed part of the dll.
 */
AXIS2_EXPORT int axis2_get_instance(struct axis2_msg_recv **inst,
						const axis2_env_t *env){
                        
	*inst = ws_xml_msg_recv_create(env);
	if(!(*inst)){
    
		return AXIS2_FAILURE;
	}

	return AXIS2_SUCCESS;
}

AXIS2_EXPORT int axis2_remove_instance(struct axis2_msg_recv *inst,
							const axis2_env_t *env){

    axis2_status_t status = AXIS2_FAILURE;
	if (inst){
    
		status = AXIS2_MSG_RECV_FREE(inst, env);
	}
	return status;
}

/** 
  * Private function implementations 
  */
static axis2_char_t* ws_xml_msg_recv_get_method_name(axis2_msg_ctx_t *msg_ctx,
														const axis2_env_t *env)
{
	axis2_op_ctx_t *op_ctx = NULL;
	axis2_op_t *op = NULL;
	const axis2_qname_t *qname = NULL;
	axis2_char_t *name = NULL;

	op_ctx = axis2_msg_ctx_get_op_ctx(msg_ctx, env);

	if (!op_ctx){
    
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Operation Context is not found");
		return NULL;
	}

	op = AXIS2_OP_CTX_GET_OP(op_ctx, env);

	if (!op){
    
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Operation is not found");
		return NULL;
	}

	qname = AXIS2_OP_GET_QNAME(op, env);

	if (!qname)	{
    
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Operation QName is not found");
		return NULL;
	}

	name = AXIS2_QNAME_GET_LOCALPART(qname, env);

	return name;
}

static axiom_node_t* 
ws_xml_msg_recv_invoke(
    const axis2_env_t *env, 
	axis2_char_t *soap_ns, 
	axis2_char_t *op_name, 
	axiom_node_t *om_node, 
    axis2_msg_ctx_t *out_msg_ctx,
    axis2_hash_t *class_info,
    int use_mtom,
    int request_xop)
{
    
	char *req_payload = NULL, *res_payload = NULL;
	axiom_node_t *res_om_node = NULL;
    zval func, retval, param;
    zval *params[1];
    HashTable *ft = NULL;
    axis2_char_t *class_name = NULL;
    zend_class_entry **ce = NULL;
    void *val = NULL;
    zval *msg = NULL;
    
	TSRMLS_FETCH();
	
	if(!om_node)
        return NULL;
	req_payload = ws_xml_msg_recv_serialize_om(env, om_node);

	if (!req_payload){
    
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Request Payload is NULL");
		return NULL;
	}

	AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, " [wsf_svr] calling php service ");
zend_try {

    MAKE_STD_ZVAL(msg);
	object_init_ex(msg, ws_message_class_entry);
    add_property_string(msg, "str", req_payload, 1);
    
    if(request_xop == AXIS2_TRUE){
        
        zval *cid2str = NULL;
        zval *cid2contentType = NULL;

		AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_service] requestXOP is TRUE, setting attachements");

        MAKE_STD_ZVAL(cid2str);
        MAKE_STD_ZVAL(cid2contentType);

        array_init(cid2str);
        array_init(cid2contentType);
        
        wsf_util_get_attachments(env, om_node, cid2str, cid2contentType TSRMLS_CC);

        add_property_zval(msg, "attachments", cid2str);
        add_property_zval(msg, "cid2contentType", cid2contentType);
        
    }
    
    ZVAL_STRING(&func, op_name, 0);
    params[0] = &param;
    ZVAL_ZVAL(params[0], msg, NULL, NULL);
    INIT_PZVAL(params[0]);
    
    if(NULL != class_info && NULL != (val = axis2_hash_get(class_info, op_name, AXIS2_HASH_KEY_STRING))){
        class_name = (axis2_char_t *)val;
        zend_lookup_class(class_name, strlen(class_name), &ce TSRMLS_CC);
        if(ce)
        {
            ft = &(*ce)->function_table;
            if(call_user_function(ft , (zval**)NULL, &func, &retval, 1, params TSRMLS_CC) == SUCCESS){
                if(Z_TYPE(retval) == IS_STRING){
                    res_payload = AXIS2_STRDUP(Z_STRVAL(retval), env);
                }
                else if(Z_TYPE(retval) == IS_OBJECT && 
                    instanceof_function(Z_OBJCE(retval), ws_fault_class_entry TSRMLS_CC)){
                    ws_xml_msg_recv_set_soap_fault(env, soap_ns , out_msg_ctx, retval TSRMLS_CC);    
                } 
            }
        }            
    }else if(call_user_function(CG(function_table) , (zval**)NULL, &func, &retval, 1, params TSRMLS_CC) == SUCCESS ){
        if( Z_TYPE(retval) == IS_OBJECT &&
            instanceof_function(Z_OBJCE(retval), ws_message_class_entry TSRMLS_CC)){
            zval **msg_tmp = NULL;
            axis2_char_t *default_cnt_type = NULL;

            if(zend_hash_find(Z_OBJPROP(retval), "defaultAttachmentContentType",
                sizeof("defaultAttachmentContentType"), (void **)&msg_tmp) == SUCCESS && 
                Z_TYPE_PP(msg_tmp) == IS_STRING){
                    default_cnt_type = Z_STRVAL_PP(msg_tmp);
                }else{
                    default_cnt_type = "application/octet-stream";
            }
            if(zend_hash_find(Z_OBJPROP(retval), "action",
                sizeof("action"), (void **)&msg_tmp) == SUCCESS &&
                Z_TYPE_PP(msg_tmp) == IS_STRING){
                    axis2_char_t *action = NULL;
                    action = Z_STRVAL_PP(msg_tmp);
                    AXIS2_MSG_CTX_SET_WSA_ACTION(out_msg_ctx, env, action);
            }

            if(zend_hash_find(Z_OBJPROP(retval), "str", sizeof("str"), (void**)&msg_tmp) == SUCCESS 
                && Z_TYPE_PP(msg_tmp) == IS_STRING ) {
                res_payload = AXIS2_STRDUP(Z_STRVAL_PP(msg_tmp), env);
				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf log ]response payload %s", res_payload);
                if(res_payload){
                    res_om_node = wsf_util_deserialize_buffer(env, res_payload);
                }                    
            }
            if(zend_hash_find(Z_OBJPROP(retval), "attachments", sizeof("attachments"), 
                (void **)&msg_tmp) == SUCCESS && Z_TYPE_PP(msg_tmp) == IS_ARRAY){
                
                HashTable *ht = NULL;
                ht = Z_ARRVAL_PP(msg_tmp);
                if(ht && res_om_node){
                    wsf_util_set_attachments_with_cids(env, use_mtom, res_om_node, 
                        ht, default_cnt_type TSRMLS_CC);
                    if(use_mtom == 1){
							axis2_msg_ctx_set_doing_mtom(out_msg_ctx, env, AXIS2_TRUE);
		                }
                    }
            }
        }else if(Z_TYPE(retval) == IS_STRING){
            res_payload = AXIS2_STRDUP(Z_STRVAL(retval), env);
            if(res_payload){
                res_om_node = wsf_util_deserialize_buffer(env, res_payload);
            }                
        }
        else if( Z_TYPE(retval) == IS_OBJECT &&
            instanceof_function(Z_OBJCE(retval), ws_fault_class_entry TSRMLS_CC)){
                ws_xml_msg_recv_set_soap_fault(env, soap_ns,out_msg_ctx, retval TSRMLS_CC);   
        } 
    }
} zend_catch {

	/*
    if (Z_TYPE_P(EG(exception)) == IS_OBJECT && instanceof_function(Z_OBJCE_P(EG(exception)), 
            ws_fault_class_entry TSRMLS_CC)) {
            ws_xml_msg_recv_set_soap_fault(env, soap_ns,out_msg_ctx, retval TSRMLS_CC);   
		
	}*/
}zend_end_try();                                                                                
    
	if (!res_payload){
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Response Payload is NULL");
		return NULL;
	}
	return res_om_node;
}

static axis2_char_t* ws_xml_msg_recv_serialize_om(const axis2_env_t *env, 
	axiom_node_t *node) {
    
	axiom_xml_writer_t *writer = NULL;
	axiom_output_t *om_output = NULL;
	axis2_char_t *buffer = NULL, *new_buffer = NULL;
    unsigned int buffer_len = 0; 

	writer = axiom_xml_writer_create_for_memory(env, NULL, AXIS2_TRUE, 0,
				AXIS2_XML_PARSER_TYPE_BUFFER);
	om_output = axiom_output_create (env, writer);

	AXIOM_NODE_SERIALIZE (node, env, om_output);
	buffer = (axis2_char_t*)AXIOM_XML_WRITER_GET_XML(writer, env);
    buffer_len = axis2_strlen(buffer);
    
    new_buffer = AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t)*(buffer_len + 1));
    memcpy(new_buffer, buffer, buffer_len);
    new_buffer[buffer_len] = '\0';

	AXIOM_OUTPUT_FREE(om_output, env);
	return new_buffer;
}

static void 
ws_xml_msg_recv_set_soap_fault(
    const axis2_env_t *env,
    axis2_char_t *soap_ns,
    axis2_msg_ctx_t *out_msg_ctx,
    zval zval_soap_fault TSRMLS_DC)
{
    axiom_soap_envelope_t *out_envelope = NULL;
    /*
    axiom_soap_header_t *out_header = NULL;
    axiom_soap_body_t *out_body = NULL;
    */
    axiom_namespace_t *env_ns = NULL;
    /*
    axiom_soap_fault_t *soap_fault = NULL;
    axis2_char_t *fault_value_str = "env:Sender";
    axis2_char_t *fault_reason_str = NULL;
   */	
    axis2_char_t *code = NULL;
    axis2_char_t *reason = NULL;
    axis2_char_t *detail = NULL;
    axis2_char_t *role = NULL;
    
    axiom_node_t *detail_node = NULL;
	
     int soap_version = AXIOM_SOAP12;
     zval **tmp;
         
    if(!soap_ns || !out_msg_ctx)
        return;
     env_ns = axiom_namespace_create(env, soap_ns, "env"); 
     if (!env_ns){
	return;
     }
     
    if(zend_hash_find(Z_OBJPROP(zval_soap_fault), WS_FAULT_REASON, sizeof(WS_FAULT_REASON), (void **)&tmp) == SUCCESS
        && Z_TYPE_PP(tmp) == IS_STRING){
        reason = Z_STRVAL_PP(tmp);
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_service] setting fault reason %s", reason);
	}else{
            php_error_docref(NULL TSRMLS_CC, E_ERROR, " Invalid fault");
    }

    if(zend_hash_find(Z_OBJPROP(zval_soap_fault), WS_FAULT_CODE, sizeof(WS_FAULT_CODE), (void **)&tmp) == SUCCESS
        && Z_TYPE_PP(tmp) == IS_STRING){
        code  = Z_STRVAL_PP(tmp);
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_service] setting fault code %s", code);
    }else{
            php_error_docref(NULL TSRMLS_CC, E_ERROR, " Invalid fault");
    }
 
    if(zend_hash_find(Z_OBJPROP(zval_soap_fault), WS_FAULT_ROLE, sizeof(WS_FAULT_ROLE), (void **)&tmp) == SUCCESS
        && Z_TYPE_PP(tmp) == IS_STRING){
        role  = Z_STRVAL_PP(tmp);
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_service] setting fault role %s", role);
    }
    if(zend_hash_find(Z_OBJPROP(zval_soap_fault), WS_FAULT_DETAIL, sizeof(WS_FAULT_DETAIL), (void **)&tmp) == SUCCESS
        && Z_TYPE_PP(tmp) == IS_STRING){
	axiom_node_t *text_node = NULL;
        detail  = Z_STRVAL_PP(tmp);
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_service] setting fault detail %s", detail);
        axiom_element_create(env, NULL, "error", NULL, &detail_node);
	axiom_text_create(env, detail_node, detail, &text_node);
        
    }    

    out_envelope = axiom_soap_envelope_create_default_soap_fault_envelope(env, code, reason, soap_version,
        NULL, detail_node);

    axis2_msg_ctx_set_soap_envelope(out_msg_ctx, env, out_envelope);

}    
