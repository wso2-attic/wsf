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

static axiom_node_t* 
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
    svc_info->use_mtom = 1;  /* default is true */
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

static char *get_time_to_live(char *buf, axis2_env_t *env)
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
    
    if(!payload_node || !attach_ht)
        return;
    if(AXIOM_NODE_GET_NODE_TYPE(payload_node, env) == AXIOM_ELEMENT)
        payload_element = (axiom_element_t *)AXIOM_NODE_GET_DATA_ELEMENT(payload_node, env);     
    node = AXIOM_NODE_GET_FIRST_CHILD(payload_node, env);
    if(node && AXIOM_NODE_GET_NODE_TYPE(node, env) == AXIOM_ELEMENT)
    {
        axiom_element_t *ele = NULL;
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


int wsf_util_set_headers(const axis2_env_t *env,
						 axis2_svc_client_t *svc_client, zval *msg TSRMLS_DC){
	if(!svc_client || !msg)
		return 0;
	{
		zval **tmp = NULL;
		HashTable *ht = NULL;
		ht = Z_OBJPROP_P(msg);
		if(WSF_HASH_FIND(ht, "headers", tmp, SUCCESS)){
			if(Z_TYPE_PP(tmp) == IS_ARRAY){
				HashPosition pos;
				HashTable *ht = Z_ARRVAL_PP(tmp);
				zval *val = NULL;
				zend_hash_internal_pointer_reset_ex(ht, &pos);
				while(zend_hash_get_current_data_ex(ht, (void**)&val , &pos) != FAILURE){
					zval *header = val;
					axiom_node_t *header_node = NULL;
					header_node = wsf_util_construct_header_node(env, header TSRMLS_CC);
					if(header_node)
					{
						AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] adding header block to svc_client");
						AXIS2_SVC_CLIENT_ADD_HEADER(svc_client, env, header_node);					
					}
					zend_hash_move_forward_ex(ht, &pos);
				}
			}
		}
	}
	return 1;
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

static void wsf_util_set_security_options(zval *zval_client, zval *zval_msg, 
	axis2_env_t *env, axis2_options_t *client_options, axis2_svc_client_t *svc_client TSRMLS_DC)
{
	zval **tmp = NULL;
	zval **msg_tmp = NULL;

	int username_present = AXIS2_FALSE;
	int password_present = AXIS2_FALSE;
	int timestamp_present = AXIS2_FALSE;
	
	AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] wsf_util_set_security_options" );
	if(zval_msg){
		if(zend_hash_find(Z_OBJPROP_P(zval_msg), "user", sizeof("user"), (void **)&msg_tmp) == SUCCESS && 
				Z_TYPE_PP(msg_tmp) == IS_STRING){
				char *username = NULL;
				axis2_property_t *property = NULL;
				username = Z_STRVAL_PP(msg_tmp);                
				property = axis2_property_create(env);
				AXIS2_PROPERTY_SET_VALUE(property, env, username);
				AXIS2_OPTIONS_SET_PROPERTY(client_options, env, "user" ,property);
				username_present = AXIS2_TRUE;
		}
		if(zend_hash_find(Z_OBJPROP_P(zval_msg), "password", sizeof("password"), (void **)&msg_tmp) == SUCCESS && 
			Z_TYPE_PP(msg_tmp) == IS_STRING){
			char *password = NULL;
			axis2_property_t *property = NULL;
			
			property = axis2_property_create(env);
			
			password = Z_STRVAL_PP(msg_tmp);
			
			AXIS2_PROPERTY_SET_VALUE(property,
									 env, 
									 password);

			AXIS2_OPTIONS_SET_PROPERTY(client_options,  
										env, 
										"password", 
										property);
			
			password_present = AXIS2_TRUE;

			AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] password present :- %s", password);
		}
		if(zend_hash_find(Z_OBJPROP_P(zval_msg), "digest", sizeof("digest"), (void **)&msg_tmp) == SUCCESS && 
			Z_TYPE_PP(msg_tmp) == IS_BOOL){
			int use_digest = 0;
			char *password_type = NULL;
			axis2_property_t *property = NULL;
			use_digest = Z_BVAL_PP(msg_tmp);
			if(use_digest){
				password_type = "passwordDigest";
				property = axis2_property_create(env);

				AXIS2_PROPERTY_SET_VALUE(property, env, password_type);

				AXIS2_OPTIONS_SET_PROPERTY(client_options, env, "passwordType" ,property);

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] password type is digest");
			}
		}
		else if(password_present){
			char *password_type = NULL;
				axis2_property_t *property = NULL;
				password_type = "passwordText";
				property = axis2_property_create(env);
				AXIS2_PROPERTY_SET_VALUE(property, env, password_type);
				AXIS2_OPTIONS_SET_PROPERTY(client_options, env, "passwordType" ,property);

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] passwordType :- passwordText");
		}	
		if(zend_hash_find(Z_OBJPROP_P(zval_msg), "timeToLive", sizeof("timeToLive"), 
			(void **)&msg_tmp) == SUCCESS && Z_TYPE_PP(msg_tmp) == IS_STRING){
			char *timeto_live = NULL;
			axis2_property_t *property = NULL;
			timeto_live = Z_STRVAL_PP(msg_tmp);
			if(timeto_live){
				property = axis2_property_create(env);
				AXIS2_PROPERTY_SET_VALUE(property, env, get_time_to_live(timeto_live, env));
				AXIS2_OPTIONS_SET_PROPERTY(client_options, env, "timeToLive" ,property);
			}
			AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] timeToLive :- %s", timeto_live);

			timestamp_present = AXIS2_TRUE;
		}
		if(username_present && password_present){
			
			axis2_property_t *sec_prop = NULL;
			axis2_property_t *outflow_prop = NULL;

			sec_prop = axis2_property_create(env);
			if(timestamp_present){
				
				AXIS2_PROPERTY_SET_VALUE(sec_prop, env, "UsernameToken Timestamp");        
				
				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] seurity properties :- UsernameToken Timestamp");
			}	
			else {

				AXIS2_PROPERTY_SET_VALUE(sec_prop, env, "UsernameToken");            

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] seurity properties :- UsernameToken");

			}	

			outflow_prop = axis2_property_create_with_args(env, AXIS2_SCOPE_APPLICATION, 0,
				NULL,"TRUE");
			
			AXIS2_OPTIONS_SET_PROPERTY(client_options, env, "OutflowSecurity", outflow_prop);

			AXIS2_OPTIONS_SET_PROPERTY(client_options, env, "items", sec_prop);
			AXIS2_SVC_CLIENT_ENGAGE_MODULE(svc_client , env, "rampart");
		}		
	}else{
		username_present = AXIS2_FALSE;
		password_present = AXIS2_FALSE;
		
		if(zend_hash_find(Z_OBJPROP_P(zval_client), "user", sizeof("user"), 
			(void **)&tmp) == SUCCESS && Z_TYPE_PP(tmp) == IS_STRING){
				char *username = NULL;
				axis2_property_t *property = NULL;
				username = Z_STRVAL_PP(tmp);                
				property = axis2_property_create(env);
				AXIS2_PROPERTY_SET_VALUE(property, env, username);
				AXIS2_OPTIONS_SET_PROPERTY(client_options, env, "user" ,property);
				username_present = AXIS2_TRUE;
		}
		if(zend_hash_find(Z_OBJPROP_P(zval_client), "password", sizeof("password"), (void **)&msg_tmp) == SUCCESS && 
			Z_TYPE_PP(tmp) == IS_STRING){
			char *password = NULL;
			axis2_property_t *property = NULL;
			property = axis2_property_create(env);
			password = Z_STRVAL_PP(tmp);
			AXIS2_PROPERTY_SET_VALUE(property,env, password);
			AXIS2_OPTIONS_SET_PROPERTY(client_options,  env, "password", property);
			password_present = AXIS2_TRUE;
		}
		
		if(zend_hash_find(Z_OBJPROP_P(zval_client), "digest", sizeof("digest"), (void **)&tmp) == SUCCESS && 
			Z_TYPE_PP(tmp) == IS_BOOL){
			int use_digest = 0;
			char *password_type = NULL;
			axis2_property_t *property = NULL;
			use_digest = Z_BVAL_PP(tmp);
			if(use_digest){
				password_type = "passwordDigest";
				property = axis2_property_create(env);
				AXIS2_PROPERTY_SET_VALUE(property, env, password_type);
				AXIS2_OPTIONS_SET_PROPERTY(client_options, env, "passwordType" ,property);
			}
		}else if(password_present){
				char *password_type = NULL;
			axis2_property_t *property = NULL;		
				password_type = "passwordText";
				property = axis2_property_create(env);
				AXIS2_PROPERTY_SET_VALUE(property, env, password_type);
				AXIS2_OPTIONS_SET_PROPERTY(client_options, env, "passwordType" ,property);
		}
		
		if(zend_hash_find(Z_OBJPROP_P(zval_client), "timeToLive", sizeof("timeToLive"), 
			(void **)&tmp) == SUCCESS && Z_TYPE_PP(tmp) == IS_STRING)
		{
			char *timeto_live = NULL;
			axis2_property_t *property = NULL;
			timeto_live = Z_STRVAL_PP(tmp);
			if(timeto_live){
				property = axis2_property_create(env);
				AXIS2_PROPERTY_SET_VALUE(property, env, get_time_to_live(timeto_live, env));
				AXIS2_OPTIONS_SET_PROPERTY(client_options, env, "timeToLive" ,property);
			}
			timestamp_present = AXIS2_TRUE;
		}                    
		if(username_present && password_present){
			axis2_property_t *sec_prop = NULL;
			axis2_property_t *outflow_prop = NULL;
			sec_prop = axis2_property_create(env);
			if(timestamp_present){
				AXIS2_PROPERTY_SET_VALUE(sec_prop, env, "UsernameToken Timestamp");        
			}else{
				AXIS2_PROPERTY_SET_VALUE(sec_prop, env, "UsernameToken");
			}            
			AXIS2_OPTIONS_SET_PROPERTY(client_options, env, "items", sec_prop);
			
			outflow_prop = axis2_property_create_with_args(env, AXIS2_SCOPE_APPLICATION, 0,
				NULL, "TRUE");
			
			AXIS2_OPTIONS_SET_PROPERTY(client_options, env, "OutflowSecurity", outflow_prop);

			AXIS2_SVC_CLIENT_ENGAGE_MODULE(svc_client , env, "rampart");
		}
	}
/*
	if(zval_msg){
		wsf_util_set_security_opts(Z_OBJPROP_P(zval_msg), env, svc_client TSRMLS_CC);
	}else if(zval_client){
		wsf_util_set_security_opts(Z_OBJPROP_P(zval_msg), env, svc_client TSRMLS_CC);
	}
*/		
}

static int wsf_util_set_addr_options(zval *zval_client, zval *zval_msg, axis2_env_t *env,
    axis2_options_t *client_options, axis2_svc_client_t *svc_client  TSRMLS_DC){
		
	zval **tmp = NULL;
    int is_addressing_engaged = AXIS2_FALSE;
	int addr_action_present = AXIS2_FALSE;
	char *value = NULL;	
	
	AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] setting addressing options ");

	if(zend_hash_find(Z_OBJPROP_P(zval_client), "useWSA", sizeof("useWSA"), 
        (void**)&tmp) == SUCCESS) {
        if(Z_TYPE_PP(tmp) == IS_BOOL && Z_BVAL_PP(tmp) == 1){ 
            	value = "1.0";

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] useWSA true, version 1.0");

       	} else if(Z_TYPE_PP(tmp) == IS_STRING){

				value = Z_STRVAL_PP(tmp);

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] useWSA is string, value is %s", value);
        }
	}else{
		return AXIS2_FALSE;	
	}
	
    if(zval_msg){
		
		AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] ws_message is present setting options using ws_message options");

		if(zend_hash_find(Z_OBJPROP_P(zval_msg), "action", sizeof("action"), 
					(void**)&tmp) == SUCCESS) {

				AXIS2_OPTIONS_SET_ACTION(client_options, env, Z_STRVAL_PP(tmp));
				
				addr_action_present = AXIS2_TRUE;   

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
					"[wsf_client] addressing action is %s", Z_STRVAL_PP(tmp));

		}
		if(zend_hash_find(Z_OBJPROP_P(zval_msg), "replyTo", sizeof("replyTo"), 
					(void**)&tmp) == SUCCESS) {

				axis2_endpoint_ref_t *replyto_epr = NULL;
				char *replyto = Z_STRVAL_PP(tmp);

				replyto_epr = axis2_endpoint_ref_create(env, replyto);
				
				AXIS2_OPTIONS_SET_REPLY_TO(client_options, env, replyto_epr);

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
					"[wsf_client] replyTo present :- %s", replyto);
		}
		if(zend_hash_find(Z_OBJPROP_P(zval_msg), "faultTo", sizeof("faultTo"), 
					(void**)&tmp) == SUCCESS) {

				axis2_endpoint_ref_t *faultto_epr = NULL;
				char *faultto = Z_STRVAL_PP(tmp);

				faultto_epr = axis2_endpoint_ref_create(env, faultto);
				AXIS2_OPTIONS_SET_FAULT_TO(client_options, env, faultto_epr);

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
					"[wsf_client] faultTo present :- %s" , faultto);
		}
		if(zend_hash_find(Z_OBJPROP_P(zval_msg), "from", sizeof("from"), 
			(void**)&tmp) == SUCCESS) {

				axis2_endpoint_ref_t *from_epr = NULL;
				char *from = Z_STRVAL_PP(tmp);
				
				from_epr = axis2_endpoint_ref_create(env, from);
				AXIS2_OPTIONS_SET_REPLY_TO(client_options, env, from_epr);

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
					"[wsf_client] from  present :- %s", from);
		}

		if(addr_action_present == AXIS2_TRUE){

				is_addressing_engaged = AXIS2_TRUE;
		
				AXIS2_SVC_CLIENT_ENGAGE_MODULE(svc_client, env, "addressing");
				
				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] engage addressing ");
				
				if(strcmp(value,"submission") == 0){

					axis2_property_t *property = NULL;
					
					property = axis2_property_create(env);
					
					AXIS2_PROPERTY_SET_SCOPE(property, env, AXIS2_SCOPE_REQUEST);
					
					AXIS2_PROPERTY_SET_VALUE(property, env, 
						AXIS2_STRDUP(AXIS2_WSA_NAMESPACE_SUBMISSION, env));

					AXIS2_OPTIONS_SET_PROPERTY(client_options, env, AXIS2_WSA_VERSION, property);

					AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] addressing version is submission");
			}
		}
	}				
    else{
			
		AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI , "[wsf_client] setting options using ws_client options");

			if(zend_hash_find(Z_OBJPROP_P(zval_client), "action", sizeof("action"), 
                (void**)&tmp) == SUCCESS) {

				AXIS2_OPTIONS_SET_ACTION(client_options, env, Z_STRVAL_PP(tmp));
                addr_action_present = AXIS2_TRUE;   

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] addressing action present :- %s", Z_STRVAL_PP(tmp));

            }
            if(zend_hash_find(Z_OBJPROP_P(zval_client), "replyTo", sizeof("replyTo"), 
                (void**)&tmp) == SUCCESS) {
             
				axis2_endpoint_ref_t *replyto_epr = NULL;
                
				char *replyto = Z_STRVAL_PP(tmp);
                
				replyto_epr = axis2_endpoint_ref_create(env, replyto);
                
				AXIS2_OPTIONS_SET_REPLY_TO(client_options, env, replyto_epr);

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
					"[wsf_client] replyTo present :- %s", replyto);
            }

			if(zend_hash_find(Z_OBJPROP_P(zval_client), "faultTo", sizeof("faultTo"), 
                (void**)&tmp) == SUCCESS) {

				axis2_endpoint_ref_t *faultto_epr = NULL;
                
				char *faultto = Z_STRVAL_PP(tmp);
                
				faultto_epr = axis2_endpoint_ref_create(env, faultto);
                
				AXIS2_OPTIONS_SET_FAULT_TO(client_options, env, faultto_epr);

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] faultTo present %s", faultto);

            }
            if(zend_hash_find(Z_OBJPROP_P(zval_client), "from", sizeof("from"), 
                (void**)&tmp) == SUCCESS) {
                axis2_endpoint_ref_t *from_epr = NULL;
                
				char *from = Z_STRVAL_PP(tmp);

                from_epr = axis2_endpoint_ref_create(env, from);
                AXIS2_OPTIONS_SET_REPLY_TO(client_options, env, from_epr);

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] from present %s", from);
            }
            if(addr_action_present == AXIS2_TRUE){
				is_addressing_engaged = AXIS2_TRUE;
				
                AXIS2_SVC_CLIENT_ENGAGE_MODULE(svc_client, env, "addressing");
			
				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] engage addressing");

				if(strcmp(value,"submission") == 0){
                    axis2_property_t *property = NULL;
                    property = axis2_property_create(env);
				    AXIS2_PROPERTY_SET_SCOPE(property, env, AXIS2_SCOPE_REQUEST);
				    AXIS2_PROPERTY_SET_VALUE(property, env, 
					AXIS2_STRDUP(AXIS2_WSA_NAMESPACE_SUBMISSION, env));
				    AXIS2_OPTIONS_SET_PROPERTY(client_options, env, AXIS2_WSA_VERSION, property);

					AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] addressing versio is submission");
                }
            }   
		}    
	return is_addressing_engaged;
}

int wsf_util_set_options(zval *zval_client, zval *zval_msg, axis2_env_t *env,
        axis2_options_t *client_options, axis2_svc_client_t *svc_client, int is_send TSRMLS_DC)
{
    zval **tmp = NULL;
    zval **msg_tmp = NULL;
    int username_present = AXIS2_FALSE;
    int password_present = AXIS2_FALSE;
    int timestamp_present = AXIS2_FALSE;
    int use_soap = 0;
	int is_addressing_engaged = AXIS2_FALSE;
	int is_rm_enabled = AXIS2_FALSE;

    if(zend_hash_find(Z_OBJPROP_P(zval_client), "useSOAP", sizeof("useSOAP"), 
        (void **)&tmp) == SUCCESS){
        if(Z_TYPE_PP(tmp) == IS_STRING){
            char *value = NULL;
            value = Z_STRVAL_PP(tmp);

            if(value && strcmp(value,"1.2") == 0){
            
				AXIS2_OPTIONS_SET_SOAP_VERSION(client_options, env, AXIOM_SOAP12);

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] soap version SOAP12");

            }
            else if(value && strcmp(value,"1.1") == 0){

                AXIS2_OPTIONS_SET_SOAP_VERSION(client_options, env, AXIOM_SOAP11);

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] soap version SOAP11");

				WSF_GLOBAL(soap_version) = AXIOM_SOAP11;

				WSF_GLOBAL(soap_uri) = WS_SOAP_1_1_NAMESPACE_URI;
			}
            else if(value && strcmp(value, "false") == 0) {
                use_soap = 0;

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] use soap value is false ");
            }
        }else if(Z_TYPE_PP(tmp) == IS_DOUBLE){
            double val = Z_DVAL_PP(tmp);
            if(val == 1.2){

                AXIS2_OPTIONS_SET_SOAP_VERSION(client_options, env, AXIOM_SOAP12);

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] use soap value is false ");

            }else if(val == 1.1){
                AXIS2_OPTIONS_SET_SOAP_VERSION(client_options, env, AXIOM_SOAP11);

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] soap version soap11");

				WSF_GLOBAL(soap_version) = AXIOM_SOAP11;
				WSF_GLOBAL(soap_uri) = WS_SOAP_1_1_NAMESPACE_URI;
            }
        }else if(Z_TYPE_PP(tmp) == IS_BOOL){
            int bval = Z_BVAL_PP(tmp);
            if(bval == 1){
                AXIS2_OPTIONS_SET_SOAP_VERSION(client_options, env, AXIOM_SOAP12);
            }else if(bval == 0){
                use_soap = 0;
            }    
        }
    }else
    {
        use_soap = 0;

		AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] soap version is soap12");

    }
    if(zend_hash_find(Z_OBJPROP_P(zval_client), "HTTPMethod", sizeof("HTTPMethod"), 
        (void **)&tmp) == SUCCESS){
        if(use_soap == 0){
            char *value = NULL;
            value = Z_STRVAL_PP(tmp);
            AXIS2_OPTIONS_SET_PROPERTY(client_options, env, AXIS2_ENABLE_REST,
                AXIS2_VALUE_TRUE);
            if(value && strcmp(value, "GET") == 0){
                AXIS2_OPTIONS_SET_PROPERTY(client_options, env, AXIS2_HTTP_METHOD,
                    AXIS2_HTTP_HEADER_GET);  
            }
        }       
    }
    
    if(zend_hash_find(Z_OBJPROP_P(zval_client), "useMTOM", sizeof("useMTOM"), 
        (void **)&tmp) == SUCCESS){
        if(Z_TYPE_PP(tmp) == IS_BOOL){
            int val = Z_BVAL_PP(tmp);
            if(val == 0){

                AXIS2_OPTIONS_SET_ENABLE_MTOM(client_options, env, AXIS2_FALSE);

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] enable mtom false");

            }else{

                AXIS2_OPTIONS_SET_ENABLE_MTOM(client_options, env, AXIS2_TRUE);

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] enable mtom true");

            }
        }                
    }
    if(zval_msg && zend_hash_find(Z_OBJPROP_P(zval_msg), "to", sizeof("to"), 
        (void**)&msg_tmp) == SUCCESS) {
        axis2_endpoint_ref_t *to_epr = NULL;
        char *to = Z_STRVAL_PP(msg_tmp);
        to_epr = axis2_endpoint_ref_create(env, to);
        AXIS2_OPTIONS_SET_TO(client_options, env, to_epr);
    }else if(zend_hash_find(Z_OBJPROP_P(zval_client), "to", sizeof("to"), 
        (void**)&msg_tmp) == SUCCESS) {
        axis2_endpoint_ref_t *to_epr = NULL;
        char *to = Z_STRVAL_PP(msg_tmp);
        to_epr = axis2_endpoint_ref_create(env, to);
        AXIS2_OPTIONS_SET_TO(client_options, env, to_epr);
    }
    else
    {
        return AXIS2_FAILURE;
    }
			
	is_addressing_engaged = wsf_util_set_addr_options(zval_client, zval_msg,
				env, client_options, svc_client TSRMLS_CC);

	wsf_util_set_security_options(zval_client, zval_msg, env, client_options, svc_client TSRMLS_CC);
	
	{
	int val = 0;
	val = wsf_util_set_rm_options(zval_client, zval_msg, env, client_options, svc_client, 
		is_addressing_engaged, is_send TSRMLS_CC);
		
	
	}
    /*
	if(zval_msg && zend_hash_find(Z_OBJPROP_P(zval_msg), "reliable", sizeof("reliable"), (void**)&msg_tmp) == SUCCESS
		&& Z_TYPE_PP(msg_tmp) == IS_BOOL){
			is_rm_enabled = Z_BVAL_PP(tmp);
			
	}else if(zend_hash_find(Z_OBJPROP_P(zval_client), "reliable", sizeof("reliable"),(void**)&tmp) == SUCCESS 
		&& Z_TYPE_PP(tmp) == IS_BOOL){
			is_rm_enabled = Z_BVAL_PP(tmp);
	}
	
	if(is_rm_enabled && is_addressing_engaged){
		axis2_property_t *rmprop = NULL;
		rmprop = axis2_property_create(env);
		AXIS2_PROPERTY_SET_SCOPE(rmprop, env, AXIS2_SCOPE_APPLICATION);
		AXIS2_PROPERTY_SET_VALUE(rmprop, env, AXIS2_VALUE_TRUE);
		AXIS2_OPTIONS_SET_PROPERTY(client_options, env, "Sandesha2LastMessage", rmprop);
        if(!is_send){
        AXIS2_OPTIONS_SET_USE_SEPARATE_LISTENER(client_options, env, AXIS2_TRUE);
        }
		AXIS2_SVC_CLIENT_ENGAGE_MODULE(svc_client, env, "sandesha2");
	}
	*/
    return AXIS2_SUCCESS;
}

int wsf_util_do_request(
		zval *this_ptr, 
		zval *param, 
		zval *return_value,
		axis2_env_t *env,
		axis2_svc_client_t *svc_client,
		int is_oneway TSRMLS_DC)
{
/** for dom  */
	xmlNodePtr nodep;
	zval **data = NULL;
	axiom_node_t *payload = NULL;
    axiom_node_t *res_payload = NULL;
    axiom_xml_reader_t *reader = NULL;
	axis2_options_t *client_options = NULL;
	int call_sandesha2_client_terminate = 0;
	axis2_char_t *rm_seq_key = NULL;

    /** for iterating this obj properties */
    zval **this_tmp = NULL;
    /** for iterating axis2_msg prop */
    zval **msg_tmp = NULL;
    int responseXOP = 0;
    int status = AXIS2_SUCCESS;
    char *str_payload = NULL;
	int str_payload_len = 0;
    int input_type = WS_USING_INCORRECT_INPUT;


    if(Z_TYPE_P(param) == IS_OBJECT &&
        instanceof_function(Z_OBJCE_P(param), ws_message_class_entry TSRMLS_CC))
    {
        zval **tmp_val = NULL;
        if(zend_hash_find(Z_OBJPROP_P(param), AXIS2_MSG_P_STR, 
            sizeof(AXIS2_MSG_P_STR), (void**)&tmp_val) == SUCCESS){
            
            str_payload = Z_STRVAL_PP(tmp_val);
	        str_payload_len = Z_STRLEN_PP(tmp_val);
       	    reader = axiom_xml_reader_create_for_memory(env, 
    			str_payload, str_payload_len, "utf-8", AXIS2_XML_PARSER_TYPE_BUFFER);
        	if (!reader) {
				zend_throw_exception_ex(zend_exception_get_default(TSRMLS_C), 1 TSRMLS_CC, 
	    			"xml reader create failed");
	        }
        }
        else if((zend_hash_find(Z_OBJPROP_P(param), AXIS2_MSG_P_DOM, 
            sizeof(AXIS2_MSG_P_DOM), (void**)&tmp_val) == SUCCESS) ||
                (zend_hash_find(Z_OBJPROP_P(param), AXIS2_MSG_P_SXML, 
                    sizeof(AXIS2_MSG_P_SXML), (void**)&tmp_val) == SUCCESS)){
						nodep = wsf_get_xml_node(*tmp_val TSRMLS_CC);
            reader = axiom_xml_reader_create_for_memory(env, 
				(void*)nodep->doc, 0, "utf-8", AXIS2_XML_PARSER_TYPE_DOC);
	        if (!reader) {
    	    	zend_throw_exception_ex(zend_exception_get_default(TSRMLS_C), 1 TSRMLS_CC, 
	    		"xml reader create failed");
	        }
        }
	  
        input_type = WS_USING_MSG;
		{/** hack to make rm work , refactor later */
			zval **tmp;
			if(zend_hash_find(Z_OBJPROP_P(param), "sequence_key", sizeof("sequence_key"), (void **)&tmp) == SUCCESS){
				if(Z_TYPE_PP(tmp) == IS_STRING){
					rm_seq_key = Z_STRVAL_PP(tmp);		
				}
			}
		}
                            
    }else if(Z_TYPE_P(param) == IS_STRING){
	    /** we have an xml string */
	    str_payload = Z_STRVAL_P(param);
	    str_payload_len = Z_STRLEN_P(param);
	    input_type = WS_USING_STRING;
	    reader = axiom_xml_reader_create_for_memory(env, 
    			str_payload, str_payload_len, "utf-8", AXIS2_XML_PARSER_TYPE_BUFFER);
    	if (!reader) {
		    zend_throw_exception_ex(zend_exception_get_default(TSRMLS_C), 1 TSRMLS_CC, 
	    		"xml reader create failed");
	    }
    }else if(Z_TYPE_P(param) == IS_OBJECT && instanceof_function(Z_OBJCE_P(param), dom_node_class_entry TSRMLS_CC)) {
		nodep = wsf_get_xml_node(param TSRMLS_CC);
        reader = axiom_xml_reader_create_for_memory(env, 
				(void*)nodep->doc, 0, "utf-8", AXIS2_XML_PARSER_TYPE_DOC);
	    if (!reader) {
    		zend_throw_exception_ex(zend_exception_get_default(TSRMLS_C), 1 TSRMLS_CC, 
	    		"xml reader create failed");
	    }
	    input_type = WS_USING_DOM;    

    }       
    	
	payload = ws_util_read_payload(reader, env);
	
	if (!payload) {
		zend_throw_exception_ex(zend_exception_get_default(TSRMLS_C), 1 TSRMLS_CC, 
			"payload is empty");
	}
	
	client_options = (axis2_options_t *)AXIS2_SVC_CLIENT_GET_OPTIONS(svc_client, env);

    if(input_type == WS_USING_MSG){
        zval **ztmp = NULL;
		zval **ztmp_this = NULL;
        axis2_char_t *default_cnt_type = NULL;
        
		status = wsf_util_set_options(this_ptr, param, env,
            client_options, svc_client, 0 TSRMLS_CC);
		
		wsf_util_set_headers(env, svc_client, param TSRMLS_CC);

        if(status == AXIS2_FAILURE){
            php_error_docref(NULL TSRMLS_CC, E_ERROR, "service endpoint uri is needed for invocation ");
        }
        if(zend_hash_find(Z_OBJPROP_P(param), "defaultAttachmentContentType", 
            sizeof("defaultAttachmentContentType"), 
            (void **)&ztmp) == SUCCESS && Z_TYPE_PP(ztmp) == IS_STRING){
            default_cnt_type = Z_STRVAL_PP(ztmp);   
        }else{
            default_cnt_type = "application/octet-stream";
        }
		if(zend_hash_find(Z_OBJPROP_P(this_ptr), "responseXOP", 
            sizeof("responseXOP"), 
            (void **)&ztmp_this) == SUCCESS && Z_TYPE_PP(ztmp_this) == IS_BOOL){
            responseXOP = Z_BVAL_PP(ztmp_this);
        }          
                 
        if(zend_hash_find(Z_OBJPROP_P(param), "attachments", sizeof("attachments"), 
            (void **)&ztmp) == SUCCESS && Z_TYPE_PP(ztmp) == IS_ARRAY){
            HashTable *ht = NULL;
			int enable_mtom = AXIS2_TRUE;
			enable_mtom = AXIS2_OPTIONS_GET_ENABLE_MTOM(client_options, env);
            ht = Z_ARRVAL_PP(ztmp);
                if(ht){
                    wsf_util_set_attachments_with_cids(env, enable_mtom, payload,
                        ht, default_cnt_type TSRMLS_CC);
                }                    
       }
    }else if(input_type == WS_USING_DOM || input_type == WS_USING_STRING){
		status = wsf_util_set_options(this_ptr, NULL, env,
            client_options, svc_client, 0 TSRMLS_CC);
        if(status == AXIS2_FAILURE){
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "service enpoint uri is needed for service invocation");
        }
    }

	if(AXIS2_OPTIONS_GET_PROPERTY(client_options, env, WSF_SANDESHA_CLIENT_PROP)){
		call_sandesha2_client_terminate = 1;
	}


	if(is_oneway)
	{
		int ret_val = 0;


		ret_val = AXIS2_SVC_CLIENT_SEND_ROBUST(svc_client, env, payload);


		if(ret_val == 1)
		{
			ZVAL_TRUE(return_value);
		}else{
			ZVAL_FALSE(return_value);
		}

	}else {
		res_payload = AXIS2_SVC_CLIENT_SEND_RECEIVE(svc_client, env, payload);	
		if (res_payload) {
			axis2_char_t *res_text = NULL;
    		axis2_char_t *fault = NULL;
	        
			fault = axiom_util_get_localname(res_payload, env);
		    
			if( fault && 0 == strcmp(fault, "Fault"))
			{
	    		zval *rfault = NULL;
				MAKE_STD_ZVAL(rfault);
    			object_init_ex(rfault, ws_fault_class_entry);
				res_text = wsf_util_serialize_om(env, res_payload);
				add_property_stringl(rfault, "str", res_text, strlen(res_text), 1);
				ZVAL_ZVAL(return_value, rfault, NULL, NULL);
			}
			else {
	    		zval *rmsg = NULL;
    			MAKE_STD_ZVAL(rmsg);
    			object_init_ex(rmsg, ws_message_class_entry);
	    		if(input_type == WS_USING_MSG){
    				if(responseXOP == 1)
	    			{
        				int attachments_found = AXIS2_FALSE;
	        			zval *cid2str = NULL;
						zval *cid2contentType = NULL;
		                
		        		MAKE_STD_ZVAL(cid2str);
        				MAKE_STD_ZVAL(cid2contentType);
		            
		        		array_init(cid2str);
        				array_init(cid2contentType);
		        		wsf_util_get_attachments(env, res_payload, cid2str, cid2contentType TSRMLS_CC);
		            
        				add_property_zval(rmsg, "attachments", cid2str);
        				add_property_zval(rmsg, "cid2contentType", cid2contentType);
					}
				}
				res_text = wsf_util_serialize_om(env , res_payload);
				add_property_stringl(rmsg, AXIS2_MSG_P_STR, res_text, strlen(res_text), 1); 
				ZVAL_ZVAL(return_value, rmsg, NULL, NULL);
			}
			
		} else {
			zend_throw_exception_ex(zend_exception_get_default(TSRMLS_C), 1 TSRMLS_CC, 
				"soap body is not found");
		}
	}
	return 0;
}

void wsf_util_set_security_opts(HashTable *ht, axis2_env_t *env, axis2_svc_client_t *svc_client TSRMLS_DC)
{
	zval **tmp = NULL;
	axis2_param_t *outflow_param = NULL, *outflow_action = NULL;
	axis2_array_list_t *outflow_vl = NULL, *action_vl = NULL, *param_vl = NULL;

	axis2_param_t *inflow_param = NULL, *inflow_action = NULL, *inflow_params = NULL;
	axis2_array_list_t *inflow_vl = NULL, *inflow_action_vl = NULL, *inflow_params_vl = NULL;

	int usernametoken	= AXIS2_FALSE;
	int timestamp	= AXIS2_FALSE;
	int encrypt				= AXIS2_FALSE;
	int decrypt				= AXIS2_FALSE;
	int engage_rampart = AXIS2_TRUE;
	char *items_value = NULL;
	axis2_param_t *param = NULL;
	param_vl = axis2_array_list_create(env, 7);

	if(zend_hash_find(ht, "user", sizeof("user"), (void **)&tmp) == SUCCESS && 
		Z_TYPE_PP(tmp) == IS_STRING){
			char *username = NULL;
			username = Z_STRVAL_PP(tmp); 
			param = axis2_param_create(env, "user", username);
			axis2_param_set_param_type(param, env, AXIS2_TEXT_PARAM);
			axis2_array_list_add(param_vl, env, param);
			
			AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, " [wsf ]  user   %s", username);

		if(zend_hash_find(ht, "password", sizeof("password"), (void **)&tmp) == SUCCESS && 
			Z_TYPE_PP(tmp) == IS_STRING){
			char *password = NULL;
			password = Z_STRVAL_PP(tmp);
			param = axis2_param_create(env, "password", password);
			axis2_param_set_param_type(param, env, AXIS2_TEXT_PARAM);
			axis2_array_list_add(param_vl, env, param);
			AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, " [wsf ]  password   %s", password);
			usernametoken = AXIS2_TRUE;
			
			if(zend_hash_find(ht, "digest", sizeof("digest"), (void **)&tmp) == SUCCESS && 
			Z_TYPE_PP(tmp) == IS_BOOL){
				int use_digest = 0;
				char *password_type = NULL;
				use_digest = Z_BVAL_PP(tmp);
					if(use_digest){
						password_type = "passwordDigest";
					param = axis2_param_create(env, "passwordType", AXIS2_STRDUP("passwordDigest", env));
					axis2_array_list_add(param_vl, env, param);
					}
				}else{
				char *password_type = NULL;
				password_type = "passwordText";
				param = axis2_param_create(env, "passwordType", AXIS2_STRDUP("passwordText", env));
				axis2_array_list_add(param_vl, env, param);
				}		
		}
	}
	if(zend_hash_find(ht, "timeToLive", sizeof("timeToLive"), 
		(void **)&tmp) == SUCCESS && Z_TYPE_PP(tmp) == IS_STRING){
				char *timeto_live = NULL;
				timeto_live = Z_STRVAL_PP(tmp);
				if(timeto_live){
					param = axis2_param_create(env, "timeToLive", get_time_to_live(timeto_live, env)); 
					axis2_array_list_add(param_vl, env, param);
				}
				timestamp = AXIS2_TRUE;
	}	
	
	if(zend_hash_find(ht, "encrypt", sizeof("encrypt"), (void**)&tmp) == SUCCESS &&
			Z_TYPE_PP(tmp) == IS_OBJECT && 
			instanceof_function(Z_OBJCE_PP(tmp), ws_security_token_class_entry TSRMLS_CC)){
				zval **sec_tmp = NULL;
				HashTable *secht = Z_OBJPROP_PP(tmp);
				if(zend_hash_find(secht, "encryption_key", sizeof("encryption_key"), (void**)&sec_tmp) == SUCCESS &&
					Z_TYPE_PP(sec_tmp) == IS_STRING){
						axis2_char_t *key = NULL;
						encrypt = AXIS2_TRUE;
						key = Z_STRVAL_PP(sec_tmp);
						param = axis2_param_create(env, "keyBuffer", key);
						axis2_array_list_add(param_vl, env, param);
				}
				if(encrypt){
					if(zend_hash_find(secht, "encryption_method", sizeof("encryption_method"), 
						(void**)&sec_tmp) == SUCCESS && Z_TYPE_PP(sec_tmp) == IS_LONG){
						int algo_suit = -1;
						char *algorithm_asy = NULL, *algorithm_sym = NULL;
						algo_suit = Z_LVAL_PP(sec_tmp);
						algorithm_asy = wsf_util_get_algorithm(algo_suit, WS_ALGORITHM_ASYMMETRIC);
						param = axis2_param_create(env, "encryptionKeyTransportAlgorithm", algorithm_sym);
						axis2_array_list_add(param_vl, env, param);
						algorithm_sym = wsf_util_get_algorithm(algo_suit, WS_ALGORITHM_SYMMETRIC);
						param = axis2_param_create(env, "encryptionSymAlgorithm", algorithm_sym);
						axis2_array_list_add(param_vl, env, param);
					}
					if(zend_hash_find(secht, "sectoken_ref", sizeof("sectoken_ref"), 
						(void**)&sec_tmp) == SUCCESS && Z_TYPE_PP(sec_tmp) == IS_STRING){
						char *security_token_ref = NULL;
						security_token_ref = Z_STRVAL_PP(sec_tmp);
						param = axis2_param_create(env, "encryptionKeyIdentifier", security_token_ref);
						axis2_array_list_add(param_vl, env, param);								
					}
				}
	}		
	
	if(usernametoken && timestamp && encrypt)
	{	
		items_value = "UsernameToken Timestamp Encrypt";
	}else if(usernametoken && timestamp){
		items_value = "UsernameToken Timestamp";
	}else if(usernametoken && encrypt){
		items_value = "UsernameToken Encrypt";
	}else if(timestamp && encrypt){
		items_value = "Timestamp Encrypt";	
	}else if(usernametoken){
		items_value = "UsernameToken";
		AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, " [wsf ]  UsernameToken   %s", items_value);
	}else if(timestamp){
		items_value = "Timestamp";
	}else if(encrypt){
		items_value = "Encrypt";
	}else {
		engage_rampart = AXIS2_FALSE;
	}
	
	if(items_value){
		param = axis2_param_create(env, "items", AXIS2_STRDUP(items_value, env));
		axis2_array_list_add(param_vl, env, param);
		
		outflow_action = axis2_param_create(env, "action", NULL);
		axis2_param_set_value_list(outflow_action, env, param_vl);

		outflow_vl = axis2_array_list_create(env, 1);
		axis2_array_list_add(outflow_vl, env, outflow_action);
		outflow_param = axis2_param_create(env, "OutflowSecurity", NULL);
		axis2_param_set_value_list(outflow_param, env, outflow_vl);
	}
	if(engage_rampart){
		axis2_svc_ctx_t *svc_ctx = NULL;
		axis2_conf_ctx_t *conf_ctx = NULL;
		axis2_conf_t *conf = NULL;
		axis2_svc_t *svc = NULL;
		axis2_param_container_t *param_containter = NULL;

		svc_ctx = AXIS2_SVC_CLIENT_GET_SVC_CTX(svc_client, env);
		conf_ctx = AXIS2_SVC_CTX_GET_CONF_CTX(svc_ctx, env);
		conf = AXIS2_CONF_CTX_GET_CONF(conf_ctx,env);
		AXIS2_CONF_ADD_PARAM(conf, env, outflow_param);
		AXIS2_SVC_CLIENT_ENGAGE_MODULE(svc_client , env, "rampart");
	}
}

int wsf_util_set_rm_options(zval *zval_client, zval *zval_msg, 
		axis2_env_t *env,	axis2_options_t *client_options, axis2_svc_client_t *svc_client,
		int is_addr_engaged, int is_send TSRMLS_DC){

	zval **tmp = NULL;
	int is_rm_enabled = 0;

		if(zval_msg && zend_hash_find(Z_OBJPROP_P(zval_msg), 
			"reliable", sizeof("reliable"), (void**)&tmp) == SUCCESS){
			if(Z_TYPE_PP(tmp) == IS_BOOL){
					axis2_property_t *rm_prop = NULL;
					is_rm_enabled = Z_BVAL_PP(tmp);
					rm_prop = axis2_property_create_with_args(env, 0, 0, 0, WSF_SANDESHA2_SPEC_VERSION_1_0);
					if(rm_prop) 
						AXIS2_OPTIONS_SET_PROPERTY(client_options, env, WSF_SANDESHA2_CLIENT_RM_SPEC_VERSION, rm_prop);	
			}else if(Z_TYPE_PP(tmp) == IS_STRING){
				char *val  = Z_STRVAL_PP(tmp);
				if(strcmp(val,"1.1") == 0){
					axis2_property_t *rm_prop = NULL;
					rm_prop = axis2_property_create_with_args(env, 0, 0, 0, WSF_SANDESHA2_SPEC_VERSION_1_1);
					AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf log ] rm version is 1.1  ");
					if(rm_prop) {
						AXIS2_OPTIONS_SET_PROPERTY(client_options, env, WSF_SANDESHA2_CLIENT_RM_SPEC_VERSION, rm_prop);
						AXIS2_OPTIONS_SET_PROPERTY(client_options, env, WSF_SANDESHA_CLIENT_PROP, rm_prop);
					}
				}else{
					axis2_property_t *rm_prop = NULL;
					rm_prop = axis2_property_create_with_args(env, 0, 0, 0, WSF_SANDESHA2_SPEC_VERSION_1_0);
					if(rm_prop) 
						AXIS2_OPTIONS_SET_PROPERTY(client_options, env, WSF_SANDESHA2_CLIENT_RM_SPEC_VERSION, rm_prop);	
				}
			}
			if(zend_hash_find(Z_OBJPROP_P(zval_msg), "sequence_key", sizeof("sequence_key"), (void**)&tmp) == SUCCESS){
				if(Z_TYPE_PP(tmp) == IS_STRING){
					axis2_property_t *seq_key_prop = NULL;
					char *seq_key = Z_STRVAL_PP(tmp);				
					seq_key_prop = axis2_property_create(env);
					AXIS2_PROPERTY_SET_VALUE(seq_key_prop, env, AXIS2_STRDUP(seq_key, env));
					AXIS2_OPTIONS_SET_PROPERTY(client_options, env, WSF_SANDESHA2_CLIENT_SEQ_KEY, seq_key_prop);
				}			
			}
		}else if(zend_hash_find(Z_OBJPROP_P(zval_client), "reliable", sizeof("reliable"),(void**)&tmp) == SUCCESS){
			if(Z_TYPE_PP(tmp) == IS_BOOL){
					axis2_property_t *rm_prop = NULL;
					is_rm_enabled = Z_BVAL_PP(tmp);
					rm_prop = axis2_property_create_with_args(env, 0, 0, 0, WSF_SANDESHA2_SPEC_VERSION_1_0);
					if(rm_prop) 
						AXIS2_OPTIONS_SET_PROPERTY(client_options, env, WSF_SANDESHA2_CLIENT_RM_SPEC_VERSION, rm_prop);	
			}else if(Z_TYPE_PP(tmp) == IS_STRING){
				char *val  = Z_STRVAL_PP(tmp);
				if(strcmp(val,"1.1") == 0){
					axis2_property_t *rm_prop = NULL;
					rm_prop = axis2_property_create_with_args(env, 0, 0, 0, WSF_SANDESHA2_SPEC_VERSION_1_1);
					if(rm_prop) {
						AXIS2_OPTIONS_SET_PROPERTY(client_options, env, WSF_SANDESHA_CLIENT_PROP, rm_prop);					
						AXIS2_OPTIONS_SET_PROPERTY(client_options, env, WSF_SANDESHA2_CLIENT_RM_SPEC_VERSION, rm_prop);
					}
				}else{
					axis2_property_t *rm_prop = NULL;
					rm_prop = axis2_property_create_with_args(env, 0, 0, 0, WSF_SANDESHA2_SPEC_VERSION_1_0);
					if(rm_prop) 
						AXIS2_OPTIONS_SET_PROPERTY(client_options, env, WSF_SANDESHA2_CLIENT_RM_SPEC_VERSION, rm_prop);	
				}
			}
		}
	
	if(is_rm_enabled && is_addr_engaged){
		axis2_property_t *property = NULL;
		axis2_property_t *seq_prop = NULL;
		char* offered_seq_id = NULL;
		offered_seq_id = axis2_uuid_gen(env);

		seq_prop = axis2_property_create(env);
		AXIS2_PROPERTY_SET_VALUE(seq_prop, env, AXIS2_STRDUP(offered_seq_id, env));
		AXIS2_OPTIONS_SET_PROPERTY(client_options, env, "Sandesha2OfferedSequenceId", seq_prop);
		AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, " [wsf-log] Sandesha2OfferedSequenceId is set as property");
		property = axis2_property_create_with_args(env, 0, 0, 0, AXIS2_VALUE_TRUE);

		AXIS2_OPTIONS_SET_PROPERTY(client_options, env, "Sandesha2LastMessage", property);
		AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, " [wsf-log] setting Sandesha2LastMessage"); 
		AXIS2_SVC_CLIENT_ENGAGE_MODULE(svc_client, env, "sandesha2");
	}
	return is_rm_enabled;
}

axis2_param_t *wsf_util_create_param_for_rampart(axis2_env_t *env,
												 HashTable *ht TSRMLS_DC)
{
	axis2_param_t *parameter = NULL, *action_param= NULL, *param = NULL ;
	zval **tmp = NULL;
	axis2_array_list_t *parameter_vl = NULL, *action_vl = NULL;

	parameter = axis2_param_create(env, "OutflowSecurity", NULL);
	parameter_vl = axis2_array_list_create(env, 1);
	axis2_param_set_value_list(param, env, parameter_vl);
	
	action_param = axis2_param_create(env, "action", NULL);
	action_vl = axis2_array_list_create(env, 10);
	axis2_param_set_param_type(action_param, env, AXIS2_DOM_PARAM);
	axis2_param_set_value_list(action_param, env, action_vl);

	/** set this from hash */
	
	param = axis2_param_create(env, "items", "Timestamp");
	axis2_param_set_param_type(param, env, AXIS2_TEXT_PARAM);
	axis2_array_list_add(action_vl, env, param);

	param = axis2_param_create(env, "user", "username");
	axis2_param_set_param_type(param, env, AXIS2_TEXT_PARAM);
	axis2_array_list_add(action_vl, env, param);


	param = axis2_param_create(env, "passwordType", "text or digest ");
	axis2_param_set_param_type(param, env, AXIS2_TEXT_PARAM);
	axis2_array_list_add(action_vl, env, param);
	

		




	return parameter;
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
