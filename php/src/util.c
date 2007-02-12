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
#include <axis2_dll_desc.h>
#include <axis2_msg_recv.h>
#include <axis2_class_loader.h>
#include "wsf_worker.h"
#include "wsf_xml_msg_recv.h"
#include <axis2_http_transport.h>
#include <axis2_addr.h>
#include "wsf.h"
#include "wsf_util.h"
#include <axis2_error_default.h>
#include <axis2_log_default.h>
#include <axis2_uuid_gen.h>
#include <axiom_util.h>
/*#include <sandesha2_client.h>*/

static int current_ns_count = 0;

axiom_node_t* 
wsf_util_construct_header_node(const axis2_env_t *env, 
							   zval *header TSRMLS_DC)
{
	char *ns = NULL;
	char *localname = NULL;
	char prefix[6];
	axiom_namespace_t *header_ns = NULL;
	axiom_node_t *header_node = NULL;
	axiom_element_t *header_ele = NULL;
	axiom_namespace_t *soap_ns = NULL;
	int must_understand = 0;
	int role = 0;

	zval **tmp = NULL;
	if(zend_hash_find(Z_OBJPROP_P(header), "localname" , 
		sizeof("localname") ,(void**)&tmp) == SUCCESS){
			localname = Z_STRVAL_PP(tmp);
	}else{
		return NULL;
	}
	if(zend_hash_find(Z_OBJPROP_P(header), "namespace", sizeof("namespace"),
		(void **)&tmp) == SUCCESS && Z_TYPE_PP(tmp) == IS_STRING){
			ns = Z_STRVAL_PP(tmp);
	}else{
		return NULL;
	}
	
	sprintf(prefix, "ns%d", current_ns_count++);
	header_ns = axiom_namespace_create(env, ns, prefix);
	header_ele = axiom_element_create(env, NULL , localname, header_ns, &header_node);
	
	if(zend_hash_find(Z_OBJPROP_P(header), "mustUnderstand", 
		sizeof("mustUnderstand"), (void**)&tmp) == SUCCESS){
		axiom_attribute_t *mu_attr = NULL;
		axiom_namespace_t *env_ns = NULL;
		if(Z_TYPE_PP(tmp) == ZEND_BOOL){
			char must_val[2];
			must_understand = Z_BVAL_PP(tmp);
			sprintf(must_val,"%d", must_understand);
			soap_ns = axiom_namespace_create(env, WSF_GLOBAL(soap_uri), "soapenv");
			mu_attr = axiom_attribute_create(env, "mustUnderstand", must_val, soap_ns);
			axiom_element_add_attribute(header_ele, env, mu_attr, header_node);
		}		
	}
	if(zend_hash_find(Z_OBJPROP_P(header), "role", 
		sizeof("role"), (void**)&tmp) == SUCCESS){
			axiom_attribute_t *role_attr = NULL;
			char *role_val = NULL;
			if(Z_TYPE_PP(tmp) == IS_LONG){
				if(Z_LVAL_PP(tmp) == WS_SOAP_ROLE_NEXT){
					role_val = WS_SOAP_ROLE_NEXT_URI;
				}else if(Z_LVAL_PP(tmp) == WS_SOAP_ROLE_NONE){
					role_val = WS_SOAP_ROLE_NONE_URI;
				}else if(Z_LVAL_PP(tmp) == WS_SOAP_ROLE_ULTIMATE_RECEIVER){
					role_val = WS_SOAP_ROLE_ULTIMATE_RECEIVER_URI;
				}		
			}else if(Z_TYPE_PP(tmp) == IS_STRING){
				role_val = Z_STRVAL_PP(tmp);
			}
			if(!soap_ns)
				soap_ns = axiom_namespace_create(env, WSF_GLOBAL(soap_uri), "soapenv"); 
			/** role is only valid for soap12, for soap11 use actor, TODO */
			if(WSF_GLOBAL(soap_version) == AXIOM_SOAP12 && role_val){
				role_attr = axiom_attribute_create(env, "role", 
					role_val, soap_ns);
				axiom_element_add_attribute(header_ele, env, role_attr, header_node);
			}
	}
	return header_node;			
}


static xmlNodePtr wsf_get_xml_node(zval *node TSRMLS_DC)
{
	php_libxml_node_object *object;
	xmlNodePtr nodep;

	object = (php_libxml_node_object *)zend_object_store_get_object(node TSRMLS_CC);
	nodep = php_libxml_import_node(node TSRMLS_CC);
    if (!nodep) {
		return NULL;
	}
	if (nodep->doc == NULL) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Imported Node must have \
							associated Document");
		return NULL;
	}
	if (nodep->type == XML_DOCUMENT_NODE || nodep->type == XML_HTML_DOCUMENT_NODE) {
		nodep = xmlDocGetRootElement((xmlDocPtr) nodep);
	}
	return nodep;
}

/* {{{ efree wrapper */
static void WSF_CALL wsf_free_wrapper_cli(axis2_allocator_t *allocator, void *ptr)
{
	efree(ptr);
}
/* }}} end efree wrapper */

/* {{{ malloc wrapper */
static void* WSF_CALL  wsf_malloc_wrapper_cli(axis2_allocator_t *allocator, size_t size)
{
    return emalloc(size);
}
/* }}} */
/* {{{ realloc wrapper */
static void* WSF_CALL  wsf_realloc_warpper_cli(axis2_allocator_t *allocator,void *ptr, size_t size)
{
    return erealloc(ptr, size);
}
/* }}} */

axis2_env_t *wsf_env_create_for_client(axis2_char_t *logpath)
{
	axis2_allocator_t *allocator = NULL;
    axis2_error_t *error = NULL;
    axis2_log_t *log = NULL;
    axis2_char_t client_log[250];
    axis2_thread_pool_t *thread_pool = NULL;
	const axis2_char_t *LOG_NAME = "wsf.log";
    
	allocator = emalloc(sizeof(axis2_allocator_t));
    
    allocator->free_fn = wsf_free_wrapper_cli;
    allocator->malloc_fn = wsf_malloc_wrapper_cli;
    allocator->realloc = wsf_realloc_warpper_cli;
    
    error = axis2_error_create(allocator);
	if (logpath && 
		0 == strcmp(logpath, "") || 
		0 == strcmp(logpath, ".")||
		0 == strcmp(logpath, "./")) {
		snprintf(client_log, 256, "%s", LOG_NAME);
	} else {
		snprintf(client_log, 256, "%s/%s", logpath, LOG_NAME);
	}

    thread_pool = axis2_thread_pool_init(allocator);
    log = axis2_log_create(allocator, NULL, client_log);
	return axis2_env_create_with_error_log_thread_pool(allocator, error, log, thread_pool);
}

/* {{{ malloc wrapper */
static void* WSF_CALL  wsf_malloc_wrapper(axis2_allocator_t *allocator, size_t size)
{
    return pemalloc(size,1);
}
/* }}} */
/* {{{ realloc wrapper */
static void* WSF_CALL  wsf_realloc_warpper(axis2_allocator_t *allocator,void *ptr, size_t size)
{
    return perealloc(ptr, size, 1);
}
/* }}} */
/* {{{ free wrapper */
static  void WSF_CALL wsf_free_wrapper(axis2_allocator_t *allocator, void *ptr)
{
	if (ptr)
		pefree(ptr, 1);
}
/* }}} */

/* {{{ axis2_environment create function */
axis2_env_t* wsf_env_create(axis2_char_t *path_tolog)
{
    axis2_allocator_t *allocator = NULL;
    axis2_error_t *error = NULL;
    axis2_log_t *log = NULL;
    axis2_char_t log_path[250];
    axis2_env_t *env = NULL;
    axis2_thread_pool_t *thread_pool = NULL;
	const axis2_char_t *LOG_NAME = "wsf.log";
    allocator = pemalloc(sizeof(axis2_allocator_t), 1);
    
    allocator->free_fn = wsf_free_wrapper;
    allocator->malloc_fn = wsf_malloc_wrapper;
    allocator->realloc = wsf_realloc_warpper;
    
    error = axis2_error_create(allocator);
    if (path_tolog && 
        0 == strcmp(path_tolog, "") || 
		0 == strcmp(path_tolog, ".")||
		0 == strcmp(path_tolog, "./")) {
		snprintf(log_path, 256, "%s", LOG_NAME);
	} else {
		snprintf(log_path, 256, "%s/%s", path_tolog, LOG_NAME);
	}

    thread_pool = axis2_thread_pool_init(allocator);
    log = axis2_log_create(allocator, NULL, log_path);
    env = axis2_env_create_with_error_log_thread_pool(allocator, error, log, thread_pool);
    return env;
}
/* }}} */
/* {{{ axis2_environment create function */
axis2_env_t* wsf_env_create_svr(axis2_char_t *path_tolog)
{
    axis2_allocator_t *allocator = NULL;
    axis2_error_t *error = NULL;
    axis2_log_t *log = NULL;
    axis2_char_t log_path[250];
    axis2_env_t *env = NULL;
    axis2_thread_pool_t *thread_pool = NULL;
	const axis2_char_t *LOG_NAME = "wsf_svr.log";
    allocator = pemalloc(sizeof(axis2_allocator_t), 1);
    
    allocator->free_fn = wsf_free_wrapper;
    allocator->malloc_fn = wsf_malloc_wrapper;
    allocator->realloc = wsf_realloc_warpper;
    
    error = axis2_error_create(allocator);
    if (path_tolog && 
        0 == strcmp(path_tolog, "") || 
		0 == strcmp(path_tolog, ".")||
		0 == strcmp(path_tolog, "./")) {
		snprintf(log_path, 256, "%s", LOG_NAME);
	} else {
		snprintf(log_path, 256, "%s/%s", path_tolog, LOG_NAME);
	}

    thread_pool = axis2_thread_pool_init(allocator);
    log = axis2_log_create(allocator, NULL, log_path);
    env = axis2_env_create_with_error_log_thread_pool(allocator, error, log, thread_pool);
    return env;
}
/* }}} */

void wsf_env_free(axis2_env_t *env){

}

ws_svc_info_t* ws_svc_info_create()
{
	ws_svc_info_t *svc_info = NULL;
	svc_info = emalloc(sizeof(ws_svc_info_t));
	svc_info->svc = NULL;
	svc_info->svc_name = NULL;
	svc_info->is_class = 0;
	svc_info->msg_recv = NULL;
	svc_info->svc_path = NULL;
    svc_info->class_info = NULL;
    svc_info->modules_to_engage = NULL;
    svc_info->php_worker = NULL;
    svc_info->use_mtom = 0;  /* default is false other wise service side will send mime 
							 headers which some servers can;t handle*/
    svc_info->request_xop = 0; /* default false */
    svc_info->secure = 0; /* default is false */
    svc_info->ops_to_functions = NULL;
    svc_info->ops_to_actions = NULL;
    svc_info->password_location = NULL;
    return svc_info;
}

/* free svc info struct */
void ws_svc_info_free(ws_svc_info_t *svc_info)
{
	if(NULL != svc_info)
	{
		if(svc_info->svc_name)
		{
		    efree(svc_info->svc_name);
		    svc_info->svc_name = NULL;
        }		    
		if(svc_info->svc_path)
		{
			efree(svc_info->svc_path);
			svc_info->svc_path = NULL;
		}
		efree(svc_info); 
	}
}

/** create php request info struct */
php_req_info_t* wsf_php_req_info_create()
{
	php_req_info_t *req_info = NULL;
	req_info = emalloc(sizeof(php_req_info_t));
	req_info->svr_name = NULL;
	req_info->svr_port = -1;
	req_info->http_protocol = NULL;
	req_info->content_encoding = NULL;
	req_info->soap_action = NULL;
	req_info->request_uri = NULL;
	req_info->content_length = -1;
	req_info->content_type = NULL;
	req_info->request_method = NULL;	
	req_info->req_data = NULL;
	req_info->req_data_length = 0;
    req_info->result_length = 0;
	req_info->result_payload = NULL;
	req_info->transfer_encoding = NULL;
	return req_info;
}

void wsf_php_req_info_free(php_req_info_t *req_info)
{
    if(req_info){
		/*
		if(req_info->content_encoding){
			efree(req_info->content_encoding);
		}
		if(req_info->http_protocol){
			efree(req_info->http_protocol);
		}
		if(req_info->request_uri){
			efree(req_info->request_uri);
		}
		if(req_info->result_payload){
			efree(req_info->result_payload);
		}
		if(req_info->result_payload){
			efree(req_info->result_payload);
		}
		if(req_info->content_type){
			efree(req_info->content_type);
		}
		*/
        efree(req_info);
    }
}

/* {{{ ws_read_payload */
axiom_node_t* ws_util_read_payload(
    axiom_xml_reader_t *reader, 
    axis2_env_t *env)
{
	axiom_stax_builder_t *builder = NULL;
	axiom_document_t *document = NULL;
	axiom_node_t *payload = NULL;
	
	builder = axiom_stax_builder_create(env, reader);
		
	if (!builder) {
		return NULL;
	}
		
	document = AXIOM_STAX_BUILDER_GET_DOCUMENT(builder, env);
		
	if (!document) {
		return NULL;
	}
		
	payload = AXIOM_DOCUMENT_GET_ROOT_ELEMENT(document, env);
	
	if (!payload) {
		return NULL;
	}
	AXIOM_DOCUMENT_BUILD_ALL(document, env);
	return payload;
}
/* }}} ws_read_payload */

char*wsf_util_get_ttl(char *buf, axis2_env_t *env)
{
    char *tmp_string = NULL;
    char *day = NULL;
    char *hour = NULL;
    char *minute = NULL;
    char *sec    = NULL;
    char *next = NULL;
    char *index = NULL;
    char *buffer = NULL;

    int d = 0, h = 0, m = 0;
    double s = 0.0;
    double ttl = 0.0;
    int timetolive = 0;
    if(!buf)
        return NULL;    
    tmp_string = strdup(buf);
    index = strchr(tmp_string, 'd');
    if(index)
    {
        /** find day */
        next = index+1;
        tmp_string[index - tmp_string] = '\0';    
        day = tmp_string;
        tmp_string = next;
        d = atoi(day);
    }
    index = strchr(tmp_string, 'h');
    if(index)
    {
        next = index + 1;
        tmp_string[index - tmp_string] = '\0';
        hour = tmp_string;
        tmp_string = next;
        h = atoi(hour);
    }
    index = strchr(tmp_string, 'm');
    if(index)
    {
        next = index + 1;
        tmp_string[index - tmp_string] = '\0';
        minute = tmp_string;
        tmp_string = next;
        m = atoi(minute);
    }
    index = strchr(tmp_string, 's');
    if(index)
    {
        next = index + 1;
        tmp_string[index - tmp_string] = '\0';
        sec = tmp_string;
        tmp_string = next;
        s = atof(sec);
    }
    
    ttl =     s
            + m * 60
            + h * 60 * 60
            + d * 24 * 60 * 60 ;
    
    timetolive = ttl;
    buffer = AXIS2_MALLOC(env->allocator, sizeof(char)*33);
    sprintf(buffer, "%d", timetolive);
    return buffer;
}

axis2_char_t *ws_util_get_soap_msg_from_op_client(
    axis2_op_client_t *op_client,
    axis2_env_t *env, 
	axis2_wsdl_msg_labels_t msg_label)
{
    if(op_client && msg_label)
    {
        axiom_soap_envelope_t *soap_env = NULL;
        const axis2_msg_ctx_t *msg_ctx = NULL;
        axiom_node_t *node = NULL;
        
		msg_ctx = AXIS2_OP_CLIENT_GET_MSG_CTX(op_client, env, msg_label);
        if(!msg_ctx)
            return NULL;
        soap_env = AXIS2_MSG_CTX_GET_SOAP_ENVELOPE(msg_ctx, env);
        if(!soap_env)
            return NULL;
        node = AXIOM_SOAP_ENVELOPE_GET_BASE_NODE(soap_env, env);
        return AXIOM_NODE_TO_STRING(node, env);
    }
    return NULL;    
}    


/** load message receiver */
axis2_msg_recv_t* load_msg_recv(axis2_env_t *env, axis2_char_t *home)
{
 /* msg_receiver default location is home/lib */
	axis2_char_t *class_name = NULL;
	axis2_msg_recv_t *msg_recv = NULL;
	axis2_qname_t *class_qname = NULL;
	axis2_dll_desc_t *dll_desc = NULL;
	axis2_char_t *repos_name = NULL;
	axis2_char_t *dll_name = NULL;
	axis2_char_t *temp_path = NULL;
	axis2_char_t *temp_path2 = NULL;
	axis2_char_t *temp_path3 = NULL;
	axis2_conf_t *conf = NULL;
	axis2_char_t *msg_recv_dll_name = NULL;
	axis2_param_t *impl_info_param = NULL;
		
	dll_desc = axis2_dll_desc_create(env);
	msg_recv_dll_name = 
	AXIS2_DLL_DESC_CREATE_PLATFORM_SPECIFIC_DLL_NAME(dll_desc, env, 
		"ws_xml_msg_recv");
	repos_name = home;
	
	temp_path = AXIS2_STRACAT(repos_name, AXIS2_PATH_SEP_STR, env);
	temp_path2 = AXIS2_STRACAT(temp_path, "lib", env);
	temp_path3 = AXIS2_STRACAT(temp_path2, AXIS2_PATH_SEP_STR, env);
	dll_name = AXIS2_STRACAT(temp_path3, msg_recv_dll_name, env);
	AXIS2_DLL_DESC_SET_NAME(dll_desc, env, dll_name);
	AXIS2_DLL_DESC_SET_TYPE(dll_desc, env, AXIS2_MSG_RECV_DLL);
	
	impl_info_param = axis2_param_create(env, NULL , NULL);
	if(!impl_info_param)
	{
		return NULL;
	}/*
	AXIS2_PARAM_SET_VALUE(impl_info_param, env, dll_desc);
	impl_info_param->ops->value_free = axis2_dll_desc_free_void_arg;

	axis2_class_loader_init(env);
	msg_recv = (axis2_msg_recv_t *) axis2_class_loader_create_dll(env, 
		impl_info_param);
	*/
	return msg_recv;
}

int ws_util_engage_module(
    axis2_conf_t *conf, 
    axis2_char_t *module_name, 
    axis2_env_t *env, 
    axis2_svc_t *svc)
{
    axis2_module_desc_t *module = NULL;
    axis2_qname_t *mod_qname = NULL;
	axis2_phase_resolver_t *phase_resolver = NULL;
	int status = 0;
	
    mod_qname = axis2_qname_create(env, module_name, NULL, NULL);
    module = AXIS2_CONF_GET_MODULE(conf, env, mod_qname);
    if (module){
        status = AXIS2_SVC_ENGAGE_MODULE(svc, env, module, conf);
		if(!status){
			phase_resolver = axis2_phase_resolver_create_with_config(env, conf);
			if (!phase_resolver){
				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, " ++++++++++++ PHASE RESLOVER NULL");
				return AXIS2_FAILURE;
			}
		    status = AXIS2_PHASE_RESOLVER_ENGAGE_MODULE_TO_SVC(phase_resolver, env, svc,
				module);
		}
	}
	return AXIS2_FAILURE;
}

/* genarate service name from uri */
char* ws_util_generate_svc_name_from_uri(
    char *req_uri, 
    axis2_env_t *env)
{
	char *uri = NULL;
	char *svc_name = NULL;
	if(strncmp(req_uri, "/", 1) == 0)
	{
		/** start with a / */
		uri = req_uri + 1;
	}
	else
	{
		uri = req_uri;
	}
	svc_name = pestrdup(uri, 1);
	return AXIS2_REPLACE(env, svc_name, '/', ':');
}

/* create service */
void ws_util_create_svc_from_svc_info(
    ws_svc_info_t *svc_info, 
    axis2_env_t *env TSRMLS_DC)
{
	axis2_qname_t *svc_qname = NULL;
	axis2_svc_t *svc = NULL;
	axis2_conf_t *conf = NULL;
	axis2_conf_ctx_t *conf_ctx = NULL;
	axis2_dll_desc_t *dll_des = NULL;
	axis2_param_t *param = NULL;
  
	if(!svc_info->php_worker){
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "error creating service");
		return;
	}
	
	conf_ctx = wsf_worker_get_conf_ctx(svc_info->php_worker , env);
	
	conf = AXIS2_CONF_CTX_GET_CONF(conf_ctx, env);
	if(!conf){
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "error creating qname");
		return;
	}	
  
	svc = AXIS2_CONF_GET_SVC(conf, env, svc_info->svc_name);
	if(NULL != svc){
		svc_info->svc = svc;
	}
	else {
	
	svc_qname = axis2_qname_create(env, svc_info->svc_name, NULL, NULL);
	svc_info->svc = axis2_svc_create_with_qname(env, svc_qname);
	} 
	svc_info->msg_recv = ws_xml_msg_recv_create(env);
	return;
}
/** create operation */
void ws_util_create_op_and_add_to_svc(
    ws_svc_info_t *svc_info, 
    char *action,
    axis2_env_t *env,
    char *op_name TSRMLS_DC)
{
	axis2_svc_t *svc = NULL;
	axis2_op_t *op = NULL;
	axis2_qname_t *op_qname = NULL;
    HashTable *ht = NULL;
    zval **tmp = NULL;
    
	op_qname = axis2_qname_create(env, op_name, NULL, NULL);
	svc = svc_info->svc;
	
	if(NULL != svc && NULL != op_name)
	{
        op = AXIS2_SVC_GET_OP_WITH_NAME(svc_info->svc, env, op_name);
        if(!op)
        {   
            axis2_conf_t *conf = NULL;
            axis2_conf_ctx_t *conf_ctx = NULL;
            axis2_phases_info_t *info = NULL;
        
            op_qname = axis2_qname_create(env, op_name, NULL, NULL);
    	
    	    op = axis2_op_create_with_qname(env, op_qname);
		
		    AXIS2_OP_SET_MSG_RECV(op, env, svc_info->msg_recv);
         
			conf_ctx = wsf_worker_get_conf_ctx(svc_info->php_worker , env);
                  
            conf = AXIS2_CONF_CTX_GET_CONF(conf_ctx, env);

            info = AXIS2_CONF_GET_PHASES_INFO(conf, env);
            AXIS2_PHASES_INFO_SET_OP_PHASES(info, env, op);
            AXIS2_SVC_ADD_OP(svc_info->svc, env, op);
            if(action){
                AXIS2_SVC_ADD_MAPPING(svc_info->svc, env, AXIS2_STRDUP(action, env), op);
            }                
        }
	}		
	return;
}

void wsf_util_set_attachments_with_cids(const axis2_env_t *env,
        int enable_mtom , axiom_node_t *payload_node,
        HashTable *attach_ht, char *default_cnt_type TSRMLS_DC)
{
    axiom_node_t *node = NULL;
    axiom_node_t *tmp_node = NULL;
    axiom_element_t *payload_element = NULL;
    axiom_element_t *ele = NULL;
    if(!payload_node || !attach_ht)
        return;

	if(AXIOM_NODE_GET_NODE_TYPE(payload_node, env) == AXIOM_ELEMENT){
        payload_element = (axiom_element_t *)AXIOM_NODE_GET_DATA_ELEMENT(payload_node, env);     
		axiom_element_get_first_element(payload_element, env, payload_node, &node);
    
		if(node && AXIOM_NODE_GET_NODE_TYPE(node, env) == AXIOM_ELEMENT)
		{
			
			ele = (axiom_element_t*)AXIOM_NODE_GET_DATA_ELEMENT(node, env);        
			if(ele)
			{
				axiom_namespace_t *ns = NULL;
				axis2_char_t *ns_uri = NULL;
				axis2_char_t *ele_localname = NULL;
				ele_localname = AXIOM_ELEMENT_GET_LOCALNAME(ele, env);
				if(ele_localname && AXIS2_STRCMP(ele_localname, "Include") == 0)
				{
					ns = AXIOM_ELEMENT_GET_NAMESPACE(ele, env, node);
					if(ns && (ns_uri = AXIOM_NAMESPACE_GET_URI(ns, env)) &&
						AXIS2_STRCMP(ns_uri, "http://www.w3.org/2004/08/xop/include") == 0)
					{
						axis2_char_t *cnt_type = NULL;
						/* found a matching xop include element */
						axis2_char_t *cid = NULL;
						axis2_char_t *pos = NULL;
						axis2_char_t *id = NULL;                    
						zval **tmp = NULL;
						/** look for content type in parent */
						cnt_type = AXIOM_ELEMENT_GET_ATTRIBUTE_VALUE_BY_NAME(payload_element, env, 
							"xmlmime:contentType");
						if(!cnt_type)
							cnt_type = default_cnt_type;                                        
	                    
						id = AXIOM_ELEMENT_GET_ATTRIBUTE_VALUE_BY_NAME(ele, env, "href");
						if(!id)
							return;
						pos = AXIS2_STRSTR(id, "cid:");
						if(pos){
							cid = id+4;
							if(zend_hash_find(attach_ht , cid, strlen(cid)+1, (void**)&tmp) == SUCCESS &&
								Z_TYPE_PP(tmp) == IS_STRING){
	                        
								void *binary_data = NULL;
								int binary_data_len = 0;
	                            
								/* binary_data = Z_STRVAL_PP(tmp); */
								binary_data_len = Z_STRLEN_PP(tmp);
								binary_data = AXIS2_MALLOC(env->allocator, sizeof(char)*binary_data_len);
								memcpy(binary_data, Z_STRVAL_PP(tmp) , binary_data_len);
								if(binary_data)
								{
									/** detach this node */
									axiom_node_t *text_node = NULL;
									axiom_text_t *text = NULL;
									axiom_data_handler_t *data_handler = NULL;
									AXIOM_NODE_DETACH(node, env);
									data_handler = axiom_data_handler_create(env, NULL, cnt_type);
									AXIOM_DATA_HANDLER_SET_BINARY_DATA(data_handler, env, binary_data, binary_data_len);
									text = axiom_text_create_with_data_handler(env, payload_node, data_handler, &text_node);
	                                
									if (enable_mtom == AXIS2_FALSE){
										AXIOM_TEXT_SET_OPTIMIZE(text, env, AXIS2_FALSE);
									}
									return;
								}
							}
						}
					}                    
				}
			}
		}
	}
    tmp_node = AXIOM_NODE_GET_FIRST_CHILD(payload_node, env);
    while(tmp_node)
    {
        wsf_util_set_attachments_with_cids(env, enable_mtom, tmp_node, attach_ht, default_cnt_type TSRMLS_CC);
        tmp_node = AXIOM_NODE_GET_NEXT_SIBLING(tmp_node, env);
    }        
    return;    
}        

void wsf_util_get_attachments(const axis2_env_t *env,
        axiom_node_t *payload_node, zval *cid2str,zval *cid2contentType TSRMLS_DC)
{
    axiom_node_t *node = NULL;
    axiom_node_t *tmp_node = NULL;
    axiom_element_t *payload_element = NULL;
    
    if(!payload_node || !cid2contentType || !cid2str)
        return;

    node = AXIOM_NODE_GET_FIRST_CHILD(payload_node, env);
    if(node && AXIOM_NODE_GET_NODE_TYPE(node, env) == AXIOM_ELEMENT){
        axiom_element_t *ele = NULL;
        ele = (axiom_element_t*)AXIOM_NODE_GET_DATA_ELEMENT(node, env);        
        if(ele){
            axiom_namespace_t *ns = NULL;
            axis2_char_t *ns_uri = NULL;
            axis2_char_t *ele_localname = NULL;
            ele_localname = AXIOM_ELEMENT_GET_LOCALNAME(ele, env);
            if(ele_localname && AXIS2_STRCMP(ele_localname, "Include") == 0)
            {
                ns = AXIOM_ELEMENT_GET_NAMESPACE(ele, env, node);
                if(ns && (ns_uri = AXIOM_NAMESPACE_GET_URI(ns, env)) &&
                    AXIS2_STRCMP(ns_uri, "http://www.w3.org/2004/08/xop/include") == 0)
                {
                    axiom_node_t *text_node = NULL;
                    axiom_text_t *text = NULL;
                    axis2_char_t *id = NULL;
                    axis2_char_t *pos = NULL;
                    axis2_char_t *cid = NULL;
                    axiom_data_handler_t *data_handler = NULL;
                    
                    id = AXIOM_ELEMENT_GET_ATTRIBUTE_VALUE_BY_NAME(ele, env, "href");
                    if(!id)
                        return;
                    pos = AXIS2_STRSTR(id, "cid:");
                    if(pos){
                        cid = id+4;
                        text_node = AXIOM_NODE_GET_FIRST_CHILD(node, env);
                        if(text_node && AXIOM_NODE_GET_NODE_TYPE(text_node, env) == AXIOM_TEXT){
                            text = (axiom_text_t*)AXIOM_NODE_GET_DATA_ELEMENT(text_node, env);
                            if(text){
                                data_handler = AXIOM_TEXT_GET_DATA_HANDLER(text, env);
                                if(data_handler){
                                    char *cnt_type = NULL;
                                    char *data = NULL;
                                    int data_len = 0;                               
                                    AXIOM_DATA_HANDLER_READ_FROM(data_handler, env,
                                        &data, &data_len);
                                    cnt_type = AXIOM_DATA_HANDLER_GET_CONTENT_TYPE(data_handler, env);
                                    add_assoc_stringl(cid2str, cid, data, data_len, 1); 
                                    
                                    if(cnt_type){
                                        add_assoc_stringl(cid2contentType, cid, cnt_type, strlen(cnt_type), 1);
                                    }                                        
                                    AXIOM_TEXT_SET_OPTIMIZE(text, env, AXIS2_TRUE);
                                    return;
                                }
                            }
                        }
                    }
                }                    
            }
        }
    }
    
    tmp_node = AXIOM_NODE_GET_FIRST_CHILD(payload_node, env);
    while(tmp_node)
    {
        wsf_util_get_attachments(env, tmp_node, cid2str, cid2contentType TSRMLS_CC);
        tmp_node = AXIOM_NODE_GET_NEXT_SIBLING(tmp_node, env);
    }        
    return;    
} 


char* wsf_util_serialize_om(axis2_env_t *env, axiom_node_t *ret_node)
{
	axiom_xml_writer_t *writer = NULL;
	axiom_output_t *om_output = NULL;
	axis2_char_t *buffer = NULL;
	
	writer = axiom_xml_writer_create_for_memory(env, NULL, AXIS2_TRUE, 0, AXIS2_XML_PARSER_TYPE_BUFFER);
	om_output = axiom_output_create (env, writer);
	AXIOM_NODE_SERIALIZE (ret_node, env, om_output);
	buffer = (axis2_char_t*)AXIOM_XML_WRITER_GET_XML(writer, env);
	return buffer;
}

xmlDocPtr wsf_util_serialize_om_to_doc(axis2_env_t *env, axiom_node_t *ret_node)
{
	axiom_xml_writer_t *writer = NULL;
	axiom_output_t *om_output = NULL;
	xmlDocPtr doc = NULL;
	
	writer = axiom_xml_writer_create_for_memory(env, 
	        NULL, AXIS2_TRUE, 0, AXIS2_XML_PARSER_TYPE_DOC);
	om_output = axiom_output_create (env, writer);
	AXIOM_NODE_SERIALIZE (ret_node, env, om_output);
	doc = (xmlDocPtr)AXIOM_XML_WRITER_GET_XML(writer, env);
	return doc;
}

char* wsf_util_get_algorithm(int algo_suit, int type)
{
	char *algorithm = NULL;
	if(type == WS_ALGORITHM_SYMMETRIC){
		switch(algo_suit){
			case WS_Basic128Rsa15:
				{
					algorithm = WS_Aes128;
				}
			case WS_Basic192Rsa15:
				{
					algorithm = WS_Aes192;
				}
			case WS_Basic256Rsa15:
				{
					algorithm = WS_Aes256;
				}
			case WS_TripleDesRsa15:
				{
					algorithm = WS_TripleDes;
				}
		}
	}else if(type == WS_ALGORITHM_ASYMMETRIC){
		switch(algo_suit){
			case WS_Basic128Rsa15:
				{
					algorithm = WS_KwRsa15;
				}
			case WS_Basic192Rsa15:
				{
					algorithm = WS_KwRsa15;
				}
			case WS_Basic256Rsa15:
				{
					algorithm = WS_KwRsa15;
				}
			case WS_TripleDesRsa15:
				{
					algorithm = WS_KwRsa15;
				}
		}	
	}
	return algorithm;
}
