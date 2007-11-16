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
    
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif  
    
#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "wsf.h"
#include "wsf_util.h"
#include "ext/standard/info.h"
#include <Zend/zend.h>
#include "zend_exceptions.h"
#include "zend_globals.h"
#include "zend_objects.h"
#include "wsf_common.h"
#include <axutil_env.h>
#include <axis2_svc_client.h>
#include <axiom_soap.h>
#include <axis2_http_transport.h>
#include <axis2_addr.h>
#include <axiom_util.h>
#include "wsf_client.h"
#include "wsf_policy.h"
#include "wsf_xml_msg_recv.h"
#include "wsf_version.h"
#include "php_version.h"
#include <php_main.h>
#include "wsf_wsdl.h"

ZEND_DECLARE_MODULE_GLOBALS (wsf) 

zend_class_entry * ws_client_class_entry;
zend_class_entry * ws_service_class_entry;
zend_class_entry * ws_header_class_entry;
zend_class_entry * ws_fault_class_entry;
zend_class_entry * ws_message_class_entry;
zend_class_entry * ws_var_class_entry;
zend_class_entry * ws_client_proxy_class_entry;
zend_class_entry * ws_security_token_class_entry;
zend_class_entry * ws_policy_class_entry;
zend_class_entry * ws_param_class_entry;

/* True global values, worker is thread safe,
 *  message receiver does not have state*/ 
static axutil_env_t *env;
static axutil_env_t *ws_env_svr;
axis2_msg_recv_t * wsf_msg_recv;
wsf_worker_t * worker;

#define WSF_RESET_GLOBALS() \
		WSF_GLOBAL(soap_version) = AXIOM_SOAP12; \
		WSF_GLOBAL(soap_uri) = AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI; \
		WSF_GLOBAL(curr_ns_index) = 0; 


/** WSMessage functions */ 
PHP_METHOD (ws_message, __construct);
PHP_METHOD (ws_message, __destruct);
PHP_METHOD (ws_message, __get);
ZEND_BEGIN_ARG_INFO (__ws_message_get_args, 0) 
ZEND_ARG_PASS_INFO (0)  ZEND_END_ARG_INFO ()  
/** Client functions */ 

PHP_METHOD (ws_client, __construct);
PHP_METHOD (ws_client, __destruct);
PHP_METHOD (ws_client, request);
PHP_METHOD (ws_client, send);
PHP_METHOD (ws_client, get_last_response);
PHP_METHOD (ws_client, get_last_request);
PHP_METHOD (ws_client, get_last_response_headers);
PHP_METHOD (ws_client, get_proxy);
PHP_METHOD (ws_client, terminate_outgoing_rm);

/** WSService */ 
PHP_METHOD (ws_service, set_class);
PHP_METHOD (ws_service, reply);
PHP_METHOD (ws_service, __construct);
PHP_METHOD (ws_service, __destruct);

/** WSHeader class functions */ 
PHP_METHOD (ws_header, __construct);

/* WSSecurityToken class functions */ 
PHP_METHOD (ws_security_token, __construct);
PHP_FUNCTION (ws_get_key_from_file);
PHP_FUNCTION (ws_get_cert_from_file);

/** WSFault */ 
PHP_METHOD (ws_fault, __construct);
PHP_METHOD (ws_fault, __destruct);
PHP_METHOD (ws_fault, __toString);

/** WSPolicy class functions */ 
PHP_METHOD (ws_policy, __construct);

/** WSClientProxy class functions */ 
PHP_METHOD (ws_client_proxy, __construct);
PHP_METHOD (ws_client_proxy, __call);
PHP_METHOD (ws_client_proxy, __destruct);
PHP_METHOD (ws_client_proxy, get_functions);
PHP_METHOD (ws_client_proxy, get_types);
PHP_METHOD (ws_client_proxy, get_location);

static 
ZEND_BEGIN_ARG_INFO ( ws_client_proxy_call_args, 0) 
	ZEND_ARG_PASS_INFO (0) 
	ZEND_ARG_PASS_INFO (0) 
ZEND_END_ARG_INFO ()

ZEND_BEGIN_ARG_INFO ( __ws_fault_get_args, 0) 
	ZEND_ARG_PASS_INFO (0) 
ZEND_END_ARG_INFO ()  
    
zend_function_entry php_ws_message_class_functions[] ={
    PHP_ME (ws_message, __construct, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME (ws_message, __destruct, NULL, ZEND_ACC_PUBLIC)
    PHP_ME (ws_message, __get, __ws_message_get_args, ZEND_ACC_PUBLIC) 
    { NULL, NULL, NULL} };


/** client function entry */ 
zend_function_entry php_ws_client_class_functions[] = {
    PHP_MALIAS (ws_client, request, request, NULL, ZEND_ACC_PUBLIC) 
    PHP_MALIAS (ws_client, send, send, NULL, ZEND_ACC_PUBLIC) 
    PHP_MALIAS (ws_client, getLastResponse, get_last_response, NULL, ZEND_ACC_PUBLIC)
    PHP_MALIAS (ws_client, getLastRequest, get_last_request, NULL, ZEND_ACC_PUBLIC)
    PHP_MALIAS (ws_client, getProxy, get_proxy, NULL, ZEND_ACC_PUBLIC)
    PHP_MALIAS (ws_client, terminateOutgoingRM, terminate_outgoing_rm, NULL, ZEND_ACC_PUBLIC)
    PHP_MALIAS (ws_client, getLastResponseHeaders,get_last_response_headers, NULL, ZEND_ACC_PUBLIC)
    PHP_ME (ws_client, __construct, NULL, ZEND_ACC_PUBLIC)
    PHP_ME (ws_client, __destruct,  NULL, ZEND_ACC_PUBLIC)
    { NULL, NULL, NULL} 
};

zend_function_entry php_ws_client_proxy_class_functions[] = {
    PHP_ME (ws_client_proxy, __call, ws_client_proxy_call_args, ZEND_ACC_PUBLIC)
        PHP_ME (ws_client_proxy, __construct, NULL, ZEND_ACC_PUBLIC)
        PHP_ME (ws_client, __destruct, NULL, ZEND_ACC_PUBLIC)
        PHP_MALIAS (ws_client_proxy, getFunctions, get_functions, NULL, ZEND_ACC_PUBLIC)  
        PHP_MALIAS (ws_client_proxy, getTypes, get_types, NULL, ZEND_ACC_PUBLIC)  
        PHP_MALIAS (ws_client_proxy, getLocation, get_location, NULL, ZEND_ACC_PUBLIC)  
        { NULL, NULL, NULL} 
};

/** service function entry */ 
zend_function_entry php_ws_service_class_functions[] = {
    PHP_MALIAS (ws_service, setClass, set_class, NULL, ZEND_ACC_PUBLIC) 
    PHP_MALIAS (ws_service, reply, reply, NULL, ZEND_ACC_PUBLIC) 
    PHP_ME (ws_service, __construct, NULL, ZEND_ACC_PUBLIC) 
    PHP_ME (ws_service, __destruct, NULL, ZEND_ACC_PUBLIC)  
    { NULL, NULL, NULL} 
};


/** WSFault class entry */ 
zend_function_entry php_ws_fault_class_functions[] = {
    PHP_ME (ws_fault, __construct, NULL, ZEND_ACC_PUBLIC) 
    PHP_ME (ws_fault, __destruct, NULL, ZEND_ACC_PUBLIC) 
    PHP_ME (ws_fault, __toString, NULL, ZEND_ACC_PUBLIC)  
    { NULL, NULL, NULL} 
};


/* {{{ WSHeader class functions */ 
zend_function_entry php_ws_header_class_functions[] = {
    PHP_ME (ws_header, __construct, NULL, ZEND_ACC_PUBLIC)  
    { NULL, NULL, NULL} 
};

zend_function_entry php_ws_security_token_class_functions[] = {
    PHP_ME (ws_security_token, __construct, NULL, ZEND_ACC_PUBLIC)
    { NULL, NULL, NULL} 
};

zend_function_entry php_ws_policy_class_functions[] = {
    PHP_ME (ws_policy, __construct, NULL, ZEND_ACC_PUBLIC)  
    { NULL, NULL, NULL} 
};


/* {{{ wsf_functions[] */ 
zend_function_entry wsf_functions[] = {
    PHP_FE (is_ws_fault, NULL) 
    PHP_FE (ws_get_key_from_file, NULL) 
    PHP_FE (ws_get_cert_from_file, NULL) 
    { NULL, NULL, NULL} 
};
/* }}} */ 

static zend_object_handlers ws_object_handlers;

/** object creation and destruction functions */ 
static zend_object_value 
php_ws_object_new ( zend_class_entry * class_type TSRMLS_DC);

static zend_object_value  
php_ws_object_new_ex ( zend_class_entry * class_type, ws_object ** obj TSRMLS_DC);

static void ws_objects_free_storage (void *object TSRMLS_DC);

/* {{{ proto ws_get_xml_node
*/ 
static xmlNodePtr
ws_get_xml_node(zval * node) 
{
    php_libxml_node_object * object;
    xmlNodePtr nodep;
    TSRMLS_FETCH ();
    object =  (php_libxml_node_object *) 
        zend_object_store_get_object (node TSRMLS_CC);

    nodep = php_libxml_import_node (node TSRMLS_CC);
    if (!nodep){
        return NULL;
    }
    if (nodep->doc == NULL){
        php_error_docref (NULL TSRMLS_CC, E_WARNING,
            "Imported Node must have associated Document");
        return NULL;
    }
    if (nodep->type == XML_DOCUMENT_NODE || nodep->type == XML_HTML_DOCUMENT_NODE){
        nodep = xmlDocGetRootElement ((xmlDocPtr) nodep);
    }
    return nodep;
}
/* }}} end ws_get_xml_node */

/* {{{ proto wsf_log_version_string 
 */
void wsf_log_version_string(axutil_env_t *env)
{
    if(!env || !env->log)
        return;
    
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "wsf version - %s " , WSF_VERSION_STRING);
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "php version - %s " , PHP_VERSION);

}
/* }}} */
    
/* {{{ wsf_module_entry */ 
zend_module_entry wsf_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901 
    STANDARD_MODULE_HEADER, 
#endif  /*  */
   "wsf", wsf_functions, 
   PHP_MINIT (wsf), 
   PHP_MSHUTDOWN (wsf),
   PHP_RINIT (wsf), 
   PHP_RSHUTDOWN (wsf), 
   PHP_MINFO (wsf), 
#if ZEND_MODULE_API_NO >= 20010901 
   "1.0", 
#endif  
STANDARD_MODULE_PROPERTIES };
/* }}} */ 
    
#ifdef COMPILE_DL_WSF
    ZEND_GET_MODULE (wsf) 
#endif  /*  */
ZEND_INI_MH (OnUpdateCacheEnabled) {
    long *p;
    
#ifndef ZTS
    char *base = (char *) mh_arg2;
#else   /*  */
    char *base;
    base = (char *) ts_resource (*((int *) mh_arg2));
#endif  /*  */
    p = (long *) (base + (size_t) mh_arg1);
    if (new_value_length == 2 && strcasecmp ("on", new_value) == 0) {
        *p = 1;
    }
    else if (new_value_length == 3 && strcasecmp ("yes", new_value) == 0) {
        *p = 1;
    }
    else if (new_value_length == 4 && strcasecmp ("true", new_value) == 0) {
        *p = 1;
    }
    else {
        *p = (long) (atoi (new_value) != 0);
    } return SUCCESS;
}


/* {{{ PHP_INI */ 
PHP_INI_BEGIN () 
STD_PHP_INI_ENTRY ("wsf.home", NULL, PHP_INI_ALL, 
        OnUpdateString, home, zend_wsf_globals, wsf_globals)
STD_PHP_INI_ENTRY ("wsf.log_path", "/tmp", PHP_INI_ALL, 
        OnUpdateString, log_path, zend_wsf_globals,wsf_globals)
STD_PHP_INI_ENTRY ("wsf.log_level", "4", PHP_INI_ALL, 
        OnUpdateLong, log_level, zend_wsf_globals, wsf_globals)
STD_PHP_INI_ENTRY ("wsf.enable_trace", "1", PHP_INI_ALL, 
        OnUpdateBool, enable_trace, zend_wsf_globals, wsf_globals)  
STD_PHP_INI_ENTRY ("wsf.enable_exception", "1", PHP_INI_ALL, 
        OnUpdateBool, enable_exception, zend_wsf_globals, wsf_globals)  
STD_PHP_INI_ENTRY ("wsf.rm_db_dir", "/tmp", PHP_INI_ALL,
    OnUpdateString, rm_db_dir, zend_wsf_globals, wsf_globals)  
PHP_INI_END () 
/* }}} */ 
    
/* {{{ ws_init_globals
 */ 
static void ws_init_globals (zend_wsf_globals * wsf_globals) 
{
    wsf_globals->home = NULL;
    wsf_globals->log_path = NULL;
	wsf_globals->log_level = 1;
    wsf_globals->enable_trace = 0;
    wsf_globals->enable_exception = 0;
    wsf_globals->soap_version = AXIOM_SOAP12;
    wsf_globals->soap_uri = AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI;
    wsf_globals->rm_db_dir = NULL;
    wsf_globals->curr_ns_index = 0;
} 

/* }}} */ 
    
/* {{{ PHP_MINIT_FUNCTION
 */ 
PHP_MINIT_FUNCTION (wsf) 
{
    zend_class_entry ce;

    char *home_folder = NULL;
    
    ZEND_INIT_MODULE_GLOBALS (wsf, ws_init_globals, NULL);
    
    REGISTER_INI_ENTRIES ();
    if (INI_STR ("extension_dir")){
        char *home_dir =  pemalloc (strlen (INI_STR ("extension_dir")) + strlen ("/wsf_c") + 1, 1);
        strcpy (home_dir, INI_STR ("extension_dir"));
        strcat (home_dir, "/wsf_c");
        home_folder = home_dir;
    }
    
    memcpy (&ws_object_handlers, zend_get_std_object_handlers (), sizeof (zend_object_handlers));

    ws_object_handlers.clone_obj = NULL;
    
    REGISTER_WSF_CLASS (ce, "WSClient", NULL,
        php_ws_client_class_functions, ws_client_class_entry);
    
    INIT_CLASS_ENTRY (ce, "WSClientProxy", php_ws_client_proxy_class_functions);
    ws_client_proxy_class_entry = zend_register_internal_class (&ce TSRMLS_CC);

    REGISTER_WSF_CLASS (ce, "WSService", NULL, php_ws_service_class_functions, ws_service_class_entry);

    INIT_CLASS_ENTRY (ce, "WSMessage", php_ws_message_class_functions);
    ws_message_class_entry = zend_register_internal_class (&ce TSRMLS_CC);
    
    INIT_CLASS_ENTRY (ce, "WSHeader", php_ws_header_class_functions);
    ws_header_class_entry = zend_register_internal_class (&ce TSRMLS_CC);
    
    INIT_CLASS_ENTRY (ce, "WSFault", php_ws_fault_class_functions);
 #ifdef ZEND_ENGINE_2    
    ws_fault_class_entry = zend_register_internal_class_ex(&ce, 
			zend_exception_get_default(TSRMLS_C), NULL TSRMLS_CC);
#else    
    ws_fault_class_entry = zend_register_internal_class (&ce TSRMLS_CC);
#endif

	INIT_CLASS_ENTRY (ce, "WSSecurityToken", php_ws_security_token_class_functions);
    ws_security_token_class_entry = zend_register_internal_class (&ce TSRMLS_CC);

    INIT_CLASS_ENTRY (ce, "WSPolicy", php_ws_policy_class_functions);
    ws_policy_class_entry = zend_register_internal_class (&ce TSRMLS_CC);
    
    REGISTER_LONG_CONSTANT ("WS_SOAP_ROLE_NEXT", WS_SOAP_ROLE_NEXT, CONST_CS | CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT ("WS_SOAP_ROLE_NONE", WS_SOAP_ROLE_NONE, CONST_CS | CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT ("WS_SOAP_ROLE_ULTIMATE_RECEIVER", WS_SOAP_ROLE_ULTIMATE_RECEIVER, CONST_CS | CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT ("WS_SOAP_DOCUMENT", WS_SOAP_DOCUMENT, CONST_CS | CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT ("WS_SOAP_RPC", WS_SOAP_RPC, CONST_CS | CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT ("WS_SOAP_ENCODED", WS_SOAP_ENCODED, CONST_CS | CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT ("WS_SOAP_LITERAL", WS_SOAP_LITERAL, CONST_CS | CONST_PERSISTENT);

    
    if (WSF_GLOBAL (home)) {
        home_folder = WSF_GLOBAL (home);
	}else{
		WSF_GLOBAL(home) = home_folder;
	}
    env = wsf_env_create (WSF_GLOBAL (log_path)); 
	env->log->level = WSF_GLOBAL(log_level);

    ws_env_svr = wsf_env_create_svr (WSF_GLOBAL (log_path));
	ws_env_svr->log->level = WSF_GLOBAL(log_level);

    wsf_log_version_string(ws_env_svr);
    wsf_log_version_string(env);

    wsf_msg_recv = wsf_xml_msg_recv_create (ws_env_svr);
    
    worker = wsf_worker_create (ws_env_svr, home_folder,
                    axutil_strdup(ws_env_svr, WSF_GLOBAL (rm_db_dir)));

    axiom_xml_reader_init ();


    return SUCCESS;
}


/* }}} */ 
    
/* {{{ PHP_MSHUTDOWN_FUNCTION
 */ 
PHP_MSHUTDOWN_FUNCTION (wsf) {

    wsf_worker_free(worker, ws_env_svr);
    axis2_msg_recv_free (wsf_msg_recv, ws_env_svr);
    axutil_env_free (env);
    axutil_env_free (ws_env_svr);
    axiom_xml_reader_cleanup();
    UNREGISTER_INI_ENTRIES ();
    return SUCCESS;
}


/* }}} */ 
    
/* {{{ PHP_RINIT_FUNCTION
 */ 
PHP_RINIT_FUNCTION (wsf) 
{
    WSF_GLOBAL (soap_version) = AXIOM_SOAP12;
	return SUCCESS;
}


/* }}} */ 
    
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */ 
PHP_RSHUTDOWN_FUNCTION (wsf) 
{
    return SUCCESS;
}


/* }}} */ 
    
/* {{{ PHP_MINFO_FUNCTION
 */ 
PHP_MINFO_FUNCTION (wsf) 
{
    php_info_print_table_start ();
    php_info_print_table_header (2, "wsf support", "enabled");
    php_info_print_table_end ();
    DISPLAY_INI_ENTRIES ();
}


/* }}} */ 
    
/* {{{ ws_object_new */ 
static zend_object_value 
php_ws_object_new (zend_class_entry * class_type TSRMLS_DC) 
{
    ws_object * tmp;
    return php_ws_object_new_ex (class_type, &tmp TSRMLS_CC);
}


/* }}} */ 
    
/* {{{ ws_object_new_ex */ 
static zend_object_value 
php_ws_object_new_ex (
    zend_class_entry * class_type,
    ws_object ** obj TSRMLS_DC) 
{
    zend_object_value retval;
    ws_object * intern;
    zval * tmp;

    intern = emalloc (sizeof (ws_object));
    memset (intern, 0, sizeof (ws_object));
    intern->std.ce = class_type;
    intern->obj_type = WS_NONE;
    *obj = intern;
    
	ALLOC_HASHTABLE(intern->std.properties);
    zend_hash_init(intern->std.properties, 0, NULL, ZVAL_PTR_DTOR, 0);
/*    
	zend_object_std_init (&intern->std, class_type TSRMLS_CC);
*/    
    zend_hash_copy (intern->std.properties, &class_type->default_properties,
        (copy_ctor_func_t) zval_add_ref, (void *) &tmp, sizeof (void *));
    
    retval.handle = zend_objects_store_put (intern,
        (zend_objects_store_dtor_t) zend_objects_destroy_object,
        (zend_objects_free_object_storage_t) ws_objects_free_storage, NULL TSRMLS_CC);

    retval.handlers = &ws_object_handlers;
    return retval;
}
/* }}} */ 
    
static void 
ws_objects_free_storage (void *object TSRMLS_DC)
{
	ws_object * intern = NULL;
	intern	= (ws_object *) object;
	if(!intern) return;

	if(intern->std.properties){
		zend_hash_destroy(intern->std.properties);
		FREE_HASHTABLE(intern->std.properties);
	}
/*    
	zend_object_std_dtor (&intern->std TSRMLS_CC);
*/
    if (intern->obj_type == WS_SVC_CLIENT) {
        axis2_svc_client_t * svc_client = NULL;
        svc_client = (axis2_svc_client_t *) intern->ptr;
		
        if (svc_client) {
			if(!wsf_util_is_module_engaged_to_svc_client(svc_client, env, "sandesha2")){
				axis2_svc_client_free (svc_client, env);
			}
        }
    }else if (intern->obj_type == WS_SVC) {
        wsf_svc_info_t * svc_info = NULL;
        svc_info = (wsf_svc_info_t *) intern->ptr;
        if (svc_info) {
            wsf_svc_info_free (svc_info, ws_env_svr);
        }
    }
    intern->ptr = NULL;
    efree (object);
}

/*** {{{ is_ws_fault(Object obj) */ 
PHP_FUNCTION (is_ws_fault) 
{
    zval * object = NULL;
    if (FAILURE == zend_parse_parameters (ZEND_NUM_ARGS ()TSRMLS_CC, "z", &object)) {
        php_error_docref (NULL TSRMLS_CC, E_ERROR, "Invalid parameters");
        return;
    }
    if (Z_TYPE_P (object) == IS_OBJECT && instanceof_function (Z_OBJCE_P (object), 
			ws_fault_class_entry TSRMLS_CC)) {
        RETURN_TRUE;
    
	}else{
        RETURN_FALSE;
	}
}
/* }}} */ 
    
/* {{{ proto WSMessage::__construct(mixed payload[, array properties]) */ 
PHP_METHOD (ws_message, __construct) 
{
    zval * object = NULL;
    zval * payload = NULL;
    zval * properties = NULL;
    
        /*  zval *attachments = NULL; */ 
    if (FAILURE == zend_parse_parameters (ZEND_NUM_ARGS ()TSRMLS_CC, "z|a", &payload, &properties)) {
        php_error_docref (NULL TSRMLS_CC, E_ERROR, "Invalid parameters");
        return;
    }

    WSF_GET_THIS (object);
    WSF_OBJ_CHECK (env);
    
	if (Z_TYPE_P (payload) == IS_STRING) {
        add_property_stringl (object, WS_MSG_PAYLOAD_STR, Z_STRVAL_P (payload), Z_STRLEN_P (payload), 1);
        add_property_long (object, WS_MSG_TYPE, WS_USING_STRING);
    }else if (Z_TYPE_P (payload) == IS_OBJECT &&  
		instanceof_function (Z_OBJCE_P (payload), dom_node_class_entry TSRMLS_CC)) {
			add_property_zval (object, WS_MSG_PAYLOAD_DOM, payload);
			add_property_long (object, WS_MSG_TYPE, WS_USING_DOM);
    } else {
        return;
    }
    if (NULL != properties) {
        zval ** tmp;
        HashTable * ht = Z_ARRVAL_P (properties);
        if (!ht) {
            return;
        }
	
		if (zend_hash_find (ht, WS_ATTACHMENTS, sizeof (WS_ATTACHMENTS),
                (void **) &tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_ARRAY) {
					add_property_zval (object, WS_ATTACHMENTS, *tmp);
        }
		if(zend_hash_find(ht, WS_DEFAULT_ATTACHEMENT_CONTENT_TYPE, sizeof(WS_DEFAULT_ATTACHEMENT_CONTENT_TYPE),
			(void**)&tmp) == SUCCESS && Z_TYPE_PP(tmp) == IS_STRING){
				add_property_stringl(object, WS_DEFAULT_ATTACHEMENT_CONTENT_TYPE, 
					Z_STRVAL_PP(tmp), Z_STRLEN_PP(tmp) ,1);
		}

		if(zend_hash_find(ht, WS_LAST_MESSAGE, sizeof(WS_LAST_MESSAGE),
			(void**)&tmp) == SUCCESS && Z_TYPE_PP(tmp) == IS_BOOL){
				add_property_bool(object, WS_LAST_MESSAGE, Z_BVAL_PP(tmp));
		}

		if(zend_hash_find(ht, WS_TO, sizeof(WS_TO), 
			(void**)&tmp) == SUCCESS && Z_TYPE_PP(tmp) == IS_STRING){
				add_property_stringl(object, WS_TO, Z_STRVAL_PP(tmp), Z_STRLEN_PP(tmp), 1);
		}
		if(zend_hash_find(ht, WS_ACTION, sizeof(WS_ACTION), 
			(void**)&tmp) == SUCCESS && Z_TYPE_PP(tmp) == IS_STRING){
				add_property_stringl(object, WS_ACTION, Z_STRVAL_PP(tmp), Z_STRLEN_PP(tmp), 1);	
		}
		if(zend_hash_find(ht, WS_REPLY_TO, sizeof(WS_REPLY_TO), 
			(void**)&tmp) == SUCCESS && Z_TYPE_PP(tmp) == IS_STRING){
				add_property_stringl(object, WS_REPLY_TO, Z_STRVAL_PP(tmp), Z_STRLEN_PP(tmp), 1);
		}
		if(zend_hash_find(ht, WS_FAULT_TO, sizeof(WS_FAULT_TO), 
			(void**)&tmp) == SUCCESS && Z_TYPE_PP(tmp) == IS_STRING){
				add_property_stringl(object, WS_FAULT_TO, Z_STRVAL_PP(tmp), Z_STRLEN_PP(tmp), 1);
		}
		if(zend_hash_find(ht, WS_FROM, sizeof(WS_FROM), 
			(void**)&tmp) == SUCCESS && Z_TYPE_PP(tmp) == IS_STRING){
				add_property_stringl(object, WS_FROM, Z_STRVAL_PP(tmp), Z_STRLEN_PP(tmp), 1);
		}
        if (zend_hash_find (ht, WS_HEADERS, sizeof (WS_HEADERS),
            (void **) &tmp) == SUCCESS) {
				if (Z_TYPE_PP (tmp) == IS_ARRAY) {
					add_property_zval (object, WS_HEADERS, *tmp);
				}
        }
    }
}


/* }}} */ 
    
/** desctructor */ 
PHP_METHOD (ws_message, __destruct) 
{
}

static int
get_message_storage_type (zval * this_ptr TSRMLS_DC) 
{
    zval ** param_val = NULL;
    if (zend_hash_find (Z_OBJPROP_P (this_ptr), WS_MSG_TYPE,
            sizeof (WS_MSG_TYPE), (void **) &param_val) == SUCCESS && 
            Z_TYPE_PP (param_val) == IS_LONG){
            
        return Z_LVAL_PP (param_val);
    }
    return -1;
}


/* {{{ WSMessage::__get() */ 
PHP_METHOD (ws_message, __get) 
{
    zval * object = NULL;
    char *prop_name = NULL;
    long prop_name_len = 0;
    if (zend_parse_parameters (ZEND_NUM_ARGS ()TSRMLS_CC, "s", &prop_name,
            &prop_name_len) == FAILURE){
            php_error_docref (NULL TSRMLS_CC, E_ERROR, "Invalid parameters");
    }
    if (prop_name_len <= 0){
        php_error_docref (NULL TSRMLS_CC, E_ERROR, "Invalid property");
    }

    WSF_GET_THIS (object);
    
    if (strcmp (prop_name, WS_MSG_PAYLOAD_STR) == 0) {
        if (get_message_storage_type (object TSRMLS_CC) == WS_USING_DOM) {

            xmlNodePtr nodep = NULL;
            axiom_node_t * payload = NULL;
            zval ** tmp_val = NULL;
            axiom_xml_reader_t * reader = NULL;
            if ((zend_hash_find (Z_OBJPROP_P (object), WS_MSG_PAYLOAD_DOM,
                sizeof (WS_MSG_PAYLOAD_DOM), (void **) &tmp_val) == SUCCESS)){
					nodep = ws_get_xml_node (*tmp_val);
					reader = axiom_xml_reader_create_for_memory (env, 
						(void *) nodep->doc, 0, "utf-8", AXIS2_XML_PARSER_TYPE_DOC);
					if (!reader) {
						zend_throw_exception_ex (zend_exception_get_default (TSRMLS_C), 
								1 TSRMLS_CC, "xml reader create failed");
					}
	                
					payload = wsf_util_read_payload (reader, env);
	                
					if (payload) {
						axis2_char_t * res_text = NULL;
						res_text = wsf_util_serialize_om (env, payload);
						axiom_node_free_tree (payload, env);
						if (res_text) {
							add_property_string (object, WS_MSG_PAYLOAD_STR, res_text, 1);
							RETURN_STRING (res_text, 1);
						}
					}
            }
        }
    }
    else if (strcmp (prop_name, WS_MSG_PAYLOAD_DOM) == 0) {
        if (get_message_storage_type (object TSRMLS_CC) == WS_USING_STRING) {
            zval ** tmp_val = NULL;
            if (zend_hash_find (Z_OBJPROP_P (object), WS_MSG_PAYLOAD_STR,
                sizeof (WS_MSG_PAYLOAD_STR), (void **) &tmp_val) == SUCCESS) {
					long length = 0;
					char *buffer = Z_STRVAL_PP (tmp_val);
					length = Z_STRLEN_PP (tmp_val);
					if (buffer) {
						int ret;
						zval * value = NULL;
						xmlDocPtr doc = NULL;
						doc =  xmlReadMemory (buffer, length, NULL, "UTF-8",  XML_PARSE_NOBLANKS | XML_PARSE_SAX1);
						if (!doc) {
							RETURN_NULL ();
						}
						value = php_dom_create_object ((xmlNodePtr) doc, &ret, NULL, 
							return_value, NULL TSRMLS_CC);
						add_property_zval (object, WS_MSG_PAYLOAD_DOM, value);
						RETURN_ZVAL (value, 0, 0);
					}
            }
        }
    }
}
/* }}} */ 
    
/* {{{ proto void WSClient::__construct(string uri[, array options]) */ 
PHP_METHOD (ws_client, __construct) 
{
    ws_object_ptr intern = NULL;
    zval * obj = NULL;
    char *home_folder = NULL;
    axis2_svc_client_t * svc_client = NULL;
    zval * options = NULL;
    long cache_wsdl;
    if (FAILURE == zend_parse_parameters (ZEND_NUM_ARGS ()TSRMLS_CC, "|a", &options)) {
        php_error_docref (NULL TSRMLS_CC, E_ERROR, "Invalid parameters");
        return;
    }

    WSF_OBJ_CHECK (env);
    
    WSF_GET_THIS (obj);
    
    intern = (ws_object *) zend_object_store_get_object (obj TSRMLS_CC);
    
    if (INI_STR ("extension_dir")) {
        char *home_dir = pemalloc (strlen (INI_STR ("extension_dir")) + strlen ("/wsf_c") + 1, 1);
        strcpy (home_dir, INI_STR ("extension_dir"));
        strcat (home_dir, "/wsf_c");
        home_folder = home_dir;
    }
    if (WSF_GLOBAL (home))
        home_folder = WSF_GLOBAL (home);

	svc_client = axis2_svc_client_create (env, home_folder);
    
    if (!svc_client) {
        zend_throw_exception_ex (zend_exception_get_default (TSRMLS_C), 1 TSRMLS_CC, "ws client create failed");
    }
    
    intern->ptr = svc_client;
    intern->obj_type = WS_SVC_CLIENT;
    
    if (NULL != options) {
        zval ** tmp;
        HashTable * ht = Z_ARRVAL_P (options);
        if (!ht) return;
	/** add properties defined in api doc */
        wsf_client_add_properties (obj, ht TSRMLS_CC);

        if (zend_hash_find (ht, WS_CACHE_WSDL, sizeof (WS_CACHE_WSDL),
			(void **) &tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_LONG) {
				cache_wsdl = Z_LVAL_PP (tmp);
        }

        if (zend_hash_find (ht, WS_WSDL, sizeof (WS_WSDL), 
			(void **) &tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_STRING) {
            add_property_stringl (this_ptr, WS_WSDL, Z_STRVAL_PP (tmp),
                                  Z_STRLEN_PP (tmp), 1);
        }
        
        if (zend_hash_find (ht, "classmap", sizeof ("classmap"),
           (void **) & tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_ARRAY) {
            add_property_zval(this_ptr, "classmap", *tmp);
        }

    }
}


/* }}} */ 
    
/* {{{ WSClient::__destruct() */ 
PHP_METHOD (ws_client, __destruct) 
{

}
/* }}} */ 
    
/* {{{ proto string request(mixed payload)
	payload can be a string, dom element.
	client sends and receiveds the payload 
	*/ 
PHP_METHOD (ws_client, request) 
{
    zval * param = NULL;
    ws_object_ptr intern = NULL;
    zval * obj = NULL;
    axis2_svc_client_t * svc_client = NULL;
    if (FAILURE == zend_parse_parameters (ZEND_NUM_ARGS ()TSRMLS_CC, "z", &param)) {
        php_error_docref (NULL TSRMLS_CC, E_ERROR, "Invalid parameters");
        return;
    }

    WSF_OBJ_CHECK (env);
    WSF_GET_THIS (obj);
    WSF_GET_OBJ (svc_client, obj, axis2_svc_client_t, intern);
    wsf_client_do_request (obj, param, return_value, env, svc_client, AXIS2_FALSE TSRMLS_CC);
	WSF_RESET_GLOBALS();
}


/* }}} end request */ 
    
/* {{{ proto send(string xmlpaylod)
    Sends the given payload in a robust manner.
    Means that SOAP faults are captured and reported.
    */ 
PHP_METHOD (ws_client, send) 
{
    zval * param = NULL;
    ws_object_ptr intern = NULL;
    zval * obj = NULL;
    axis2_svc_client_t * svc_client = NULL;

    if (FAILURE == zend_parse_parameters (ZEND_NUM_ARGS ()TSRMLS_CC, "z", &param)) {
        php_error_docref (NULL TSRMLS_CC, E_ERROR, "Invalid parameters");
        return;
    }
    WSF_OBJ_CHECK (env);
    WSF_GET_THIS (obj);
    WSF_GET_OBJ (svc_client, obj, axis2_svc_client_t, intern);
    wsf_client_do_request (obj, param, return_value, env, svc_client,
        AXIS2_TRUE TSRMLS_CC);

	WSF_RESET_GLOBALS();
}


/* }}} end send*/ 
    
/* {{{ proto getLastResponse() */ 
PHP_METHOD (ws_client, get_last_response) 
{
    axis2_svc_client_t * svc_client = NULL;
    ws_object_ptr intern = NULL;
    zval * obj = NULL;
    WSF_GET_THIS (obj);
    WSF_GET_OBJ (svc_client, obj, axis2_svc_client_t, intern);

    if (svc_client) {
        axis2_op_client_t * op_client = NULL;
        op_client = axis2_svc_client_get_op_client (svc_client, env);
        if (op_client) {
            axis2_char_t * msg =
                wsf_util_get_soap_msg_from_op_client (op_client, env,
                AXIS2_WSDL_MESSAGE_LABEL_IN);
            if (msg) {
                RETURN_STRING (msg, 1);
            }
        }
    }
}
/* }}} */ 
    
/* {{{ proto getLastRequest() */ 
PHP_METHOD (ws_client, get_last_request) 
{
    axis2_svc_client_t * svc_client = NULL;
    ws_object_ptr intern = NULL;
    zval * obj = NULL;
    WSF_GET_THIS (obj);
    WSF_GET_OBJ (svc_client, obj, axis2_svc_client_t, intern);
    if (svc_client) {
        axis2_op_client_t * op_client = NULL;
        op_client = axis2_svc_client_get_op_client (svc_client, env);
        if (op_client) {
            axis2_char_t * msg =
                wsf_util_get_soap_msg_from_op_client (op_client, env,
                AXIS2_WSDL_MESSAGE_LABEL_OUT);
            if (msg) {
                RETURN_STRING (msg, 1);
            }
        }
    }
}
/* }}} */ 
    
/* {{{ proto public WSClient::terminateOutgoingRM() */ 
PHP_METHOD (ws_client, terminate_outgoing_rm) 
{
    zval * object = NULL;
    WSF_GET_THIS (object);
}
/* }}} */ 
    
/* {{{ proto getLastResponseHeaders() */ 
PHP_METHOD (ws_client, get_last_response_headers) 
{
    axis2_svc_client_t * svc_client = NULL;
    ws_object_ptr intern = NULL;
    zval * obj = NULL;
    WSF_GET_THIS (obj);
    WSF_GET_OBJ (svc_client, obj, axis2_svc_client_t, intern);
    if (svc_client) {
        axis2_op_client_t * op_client = NULL;
        op_client = axis2_svc_client_get_op_client (svc_client, env);
        if (op_client) {
            axis2_char_t * msg =
                wsf_util_get_http_headers_from_op_client (op_client, env,
                AXIS2_WSDL_MESSAGE_LABEL_OUT);
            if (msg){
                RETURN_STRING (msg, 1);
            }
        }
    }
}
/* }}} */ 
    
/* }}} end call */ 
PHP_METHOD (ws_client, get_proxy) 
{
    zval * client_proxy_zval = NULL;
    char *service = NULL;
    int service_len = 0;
    char *port = NULL;
    int port_len = 0;
    zval * obj = NULL;
    if (zend_parse_parameters (ZEND_NUM_ARGS ()TSRMLS_CC, "|ss", &service,
        &service_len, &port, &port_len) == FAILURE) {
			php_error_docref (NULL TSRMLS_CC, E_ERROR,
				"Invalid Parameters,specify the service and port");
    }
    WSF_GET_THIS (obj);
    MAKE_STD_ZVAL (client_proxy_zval);
    object_init_ex (client_proxy_zval, ws_client_proxy_class_entry);
    if (service) {
        add_property_string (client_proxy_zval, "service", service, 1);
    }
    if (port) {
        add_property_string (client_proxy_zval, "port", port, 1);
    }
    
    add_property_zval (client_proxy_zval, "wsclient", this_ptr);

    RETURN_ZVAL (client_proxy_zval, 0, 1);
}


/* {{{ proto void WSService::__construct([ array options])*/ 
PHP_METHOD (ws_service, __construct) 
{
    ws_object_ptr intern = NULL;
    zval * obj = NULL;
    wsf_svc_info_t * svc_info = NULL;
    zval * options = NULL;
    HashTable * ht_options = NULL;
    HashTable * ht_actions = NULL;
    HashTable * ht_ops_to_funcs = NULL;
    HashTable * ht_ops_to_mep = NULL;
    HashTable * ht_opParams = NULL;
	HashTable * ht_classes = NULL;
    char *wsdl = NULL;
	zval **wsdl_tmp = NULL;
    
    if (FAILURE == zend_parse_parameters (ZEND_NUM_ARGS ()TSRMLS_CC, "|a",
            &options)) {
        php_error_docref (NULL TSRMLS_CC, E_ERROR, "Invalid parameters");
        return;
    }

    WSF_GET_THIS (obj);
    intern = (ws_object *) zend_object_store_get_object (obj TSRMLS_CC);
    
    svc_info = wsf_svc_info_create (ws_env_svr);
    
    svc_info->ops_to_functions = axutil_hash_make (ws_env_svr);
    
    svc_info->ops_to_actions = axutil_hash_make (ws_env_svr);
    
    intern->ptr = svc_info;
    
    intern->obj_type = WS_SVC;
    
    svc_info->php_worker = worker;
    
    if (options) {
        zval ** tmp = NULL;
        ht_options = Z_ARRVAL_P (options);
        if (ht_options) {
            if (zend_hash_find (ht_options, WS_ACTIONS , sizeof (WS_ACTIONS), 
                (void **) & tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_ARRAY) {
					ht_actions = Z_ARRVAL_PP (tmp);
					AXIS2_LOG_DEBUG (ws_env_svr->log, AXIS2_LOG_SI,
						"[wsf_service] setting actions ");
            }
            if (zend_hash_find (ht_options, WS_OPERATIONS, sizeof (WS_OPERATIONS), 
				(void **) & tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_ARRAY) {

					ht_ops_to_funcs = Z_ARRVAL_PP (tmp);
					AXIS2_LOG_DEBUG (ws_env_svr->log, AXIS2_LOG_SI,
						"[wsf_service] setting operations");
			}
            if (zend_hash_find (ht_options, WS_OP_MEP, sizeof (WS_OP_MEP), 
               (void **) & tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_ARRAY) {

					ht_ops_to_mep = Z_ARRVAL_PP (tmp);
					AXIS2_LOG_DEBUG (ws_env_svr->log, AXIS2_LOG_SI,
						"[wsf_service] setting message exchange pattern");
            }
            if (zend_hash_find (ht_options, WS_OP_PARAMS, sizeof (WS_OP_PARAMS),
               (void **) & tmp) == SUCCESS  && Z_TYPE_PP (tmp) == IS_ARRAY) {

	                ht_opParams = Z_ARRVAL_PP (tmp);
					svc_info->ht_op_params = ht_opParams;
					AXIS2_LOG_DEBUG (ws_env_svr->log, AXIS2_LOG_SI,
						"[wsf_service] setting message operation parameters");
			}
            
            if (zend_hash_find (ht_options, WS_WSDL, sizeof (WS_WSDL),
               (void **) & tmp) == SUCCESS  &&Z_TYPE_PP (tmp) == IS_STRING) {
				    wsdl = Z_STRVAL_PP (tmp);
                                    add_property_stringl (this_ptr, WS_WSDL, Z_STRVAL_PP (tmp),
                                                          Z_STRLEN_PP (tmp), 1);
            }
            if (zend_hash_find (ht_options , WS_CLASSMAP, sizeof (WS_CLASSMAP),
                   (void **) & tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_ARRAY) {
                    add_property_zval(this_ptr, WS_CLASSMAP, *tmp);
            }

            if (zend_hash_find (ht_options, WS_USE_MTOM, sizeof (WS_USE_MTOM), 
				(void **) &tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_BOOL) {

					svc_info->use_mtom = Z_BVAL_PP (tmp);
					AXIS2_LOG_DEBUG (ws_env_svr->log, AXIS2_LOG_SI,
						"[wsf_service] setting mtom property %d",
							svc_info->use_mtom);
            }else {
                svc_info->use_mtom = 0;
            }
            if (zend_hash_find (ht_options, WS_REQUEST_XOP, sizeof (WS_REQUEST_XOP), 
				(void **) &tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_BOOL) {
                
                    svc_info->request_xop = Z_BVAL_PP (tmp);
            }else {
                svc_info->request_xop = 0;
            }
            
            AXIS2_LOG_DEBUG (ws_env_svr->log, AXIS2_LOG_SI,
                "[wsf_service] request xop %d", svc_info->request_xop);
            
            if (zend_hash_find (ht_options, WS_POLICY_NAME, sizeof (WS_POLICY_NAME), 
				(void **) &tmp) == SUCCESS) {

					svc_info->policy = *tmp;
					AXIS2_LOG_DEBUG (ws_env_svr->log, AXIS2_LOG_SI,
						"[wsf_service] policy object present");
            }
            if (zend_hash_find (ht_options, WS_SECURITY_TOKEN, sizeof (WS_SECURITY_TOKEN), 
				(void **) &tmp) == SUCCESS) {
            
					svc_info->security_token = *tmp;
					AXIS2_LOG_DEBUG (ws_env_svr->log, AXIS2_LOG_SI,
						"[wsf_service] security token object present ");
            }
            if (zend_hash_find (ht_options, WS_RELIABLE, sizeof (WS_RELIABLE), 
				(void **) &tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_BOOL) {
                
					if (!svc_info->modules_to_engage){
						svc_info->modules_to_engage =  axutil_array_list_create (ws_env_svr, 3);
					}
					axutil_array_list_add (svc_info->modules_to_engage, 
						ws_env_svr, axutil_strdup (ws_env_svr, "sandesha2"));
            }
            if (zend_hash_find (ht_options, WS_BINDING_STYLE, sizeof (WS_BINDING_STYLE), 
				(void **) &tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_STRING) {
					add_property_stringl (obj, WS_BINDING_STYLE,
					Z_STRVAL_PP (tmp), Z_STRLEN_PP (tmp), 1);
            }

            if(zend_hash_find(ht_options, WS_CLASSES, sizeof(WS_CLASSES),
				(void**)&tmp) == SUCCESS && Z_TYPE_PP(tmp) == IS_ARRAY){
					ht_classes = Z_ARRVAL_PP(tmp);

            }
        }
    }
    
    if (SG (request_info).request_uri) {
        svc_info->svc_name = wsf_util_generate_svc_name_from_uri (SG (request_info).
                                request_uri, svc_info, ws_env_svr);
        svc_info->msg_recv = wsf_msg_recv;
        wsf_util_create_svc_from_svc_info (svc_info, ws_env_svr TSRMLS_CC);
    } else if(SG(request_info).path_translated) {
        svc_info->svc_name = wsf_util_generate_svc_name_from_uri (
            SG(request_info).path_translated, svc_info, ws_env_svr);
        svc_info->msg_recv = wsf_msg_recv;
        wsf_util_create_svc_from_svc_info (svc_info, ws_env_svr TSRMLS_CC);
    }

	if(ht_classes){
		wsf_util_process_ws_service_classes(ht_classes, svc_info, ws_env_svr TSRMLS_CC);
	}
    wsf_util_process_ws_service_operations_and_actions(ht_ops_to_funcs,
                                                       ht_actions, ht_ops_to_mep, svc_info, ws_env_svr TSRMLS_CC);
    
    wsf_util_engage_modules_to_svc(ws_env_svr, 
                                   wsf_worker_get_conf_ctx(worker, ws_env_svr), svc_info);
    
    
							
    if(zend_hash_find(Z_OBJPROP_P(this_ptr), WS_WSDL,
                      sizeof(WS_WSDL), (void **)&wsdl_tmp) == SUCCESS){
        wsf_wsdl_process_service(this_ptr, NULL, svc_info, ws_env_svr TSRMLS_CC);
    }

}


/* }}} */ 
    
/* {{{ proto void WSService::__destruct()
   */ 
PHP_METHOD (ws_service, __destruct) 
{
}


/* } }} end WSService::__destruct */ 
    
/* {{{ proto long setClass(string classname) Set a class to the service */ 
PHP_METHOD (ws_service, set_class) 
{
}
/* }}} end setClass */ 

static void generate_wsdl_for_service(zval *svc_zval, 
        wsf_svc_info_t *svc_info, 
        wsf_req_info_t *req_info, char *wsdl_ver_str,
        int in_cmd TSRMLS_DC)
{
        char *service_name = NULL;
        zval func, retval, param1, param2, param3, param4, param5, param6,
        param7;
        zval * params[7];
        axutil_hash_index_t * hi = NULL;
        zval * functions;
        zend_file_handle script;
        char *val = NULL;
        int len = 0;
        zval ** tmpval;
        char *binding_name = NULL;
        char *wsdl_version = NULL;
        int path_len = 0;
        smart_str script_path = { 0 };
        smart_str script_file_name = { 0 };
        smart_str full_path = {0};
        zval * op_val;

        char *real_path = NULL;
            
        if(!in_cmd){
            real_path = estrdup(SG(request_info).path_translated);
            path_len = strlen(SG(request_info).path_translated)- strlen(req_info->request_uri);
            real_path[path_len + 1] = '\0';
        }else{
            real_path = ".";
        }
       
        service_name = svc_info->svc_name;
        
        if(!in_cmd){
            smart_str_appends(&full_path, req_info->svr_name);
            smart_str_appends(&full_path, req_info->request_uri);
            smart_str_0 (&full_path);
        }else{
            smart_str_appends(&full_path, SG(request_info).path_translated); 
            smart_str_0 (&full_path);
        }
        params[0] = &param1;
        params[1] = &param2;
        params[2] = &param3;
        params[3] = &param4;
        params[4] = &param5;
        params[5] = &param6;
        params[6] = &param7;
        
        /** for Wsdl version. default is wsdl 1.1*/ 
        if ((stricmp (wsdl_ver_str , "wsdl")) == 0)
            wsdl_version = strdup ("wsdl1.1");
        
        else
            wsdl_version = strdup ("wsdl2.0");
        
        /** getting the correct binding style */ 
            if ((zend_hash_find (Z_OBJPROP_P (svc_zval), WS_BINDING_STYLE,
                    sizeof (WS_BINDING_STYLE), (void **) &tmpval)) == SUCCESS
            && Z_TYPE_PP (tmpval) == IS_STRING) {
            binding_name = Z_STRVAL_PP (tmpval);
        } else {
            binding_name ="doclit";  /* estrdup ("doclit"); */
        }
        
        /** find the functions in the service.php file */ 
        MAKE_STD_ZVAL (functions);
        array_init (functions);
        MAKE_STD_ZVAL (op_val);
        array_init (op_val);
        if (svc_info->ops_to_functions) {
            for (hi =
                axutil_hash_first (svc_info->ops_to_functions, ws_env_svr);
                hi; hi = axutil_hash_next (ws_env_svr, hi)) {
                void *v = NULL;
                const void *k = NULL;
                axis2_char_t * f_key = NULL;
                axis2_char_t * f_name = NULL;
                axutil_hash_this (hi, &k, NULL, &v);
                f_key = (axis2_char_t *) k;
                f_name = (axis2_char_t *) v;
                add_next_index_string (functions, (char *) f_name, 1);
                add_assoc_string (op_val, (char *) f_key, (char *) f_name,
                    1);
        } }

        if(!in_cmd){
            smart_str_appends(&script_path, real_path);
            smart_str_appends(&script_path, "scripts/wsdl/WS_WSDL_Creator.php");
            smart_str_0 (&script_path);

            smart_str_appends(&script_file_name, real_path);
            smart_str_appends(&script_file_name, "scripts/wsf.php");
            smart_str_0 (&script_file_name);

            efree(real_path);
        }else{
    
            smart_str_appends(&script_path, "scripts/wsdl/WS_WSDL_Creator.php");
            smart_str_0 (&script_path);

            smart_str_appends(&script_file_name, "scripts/wsf.php");
            smart_str_0 (&script_file_name);
        }

        ZVAL_STRING (&func, "ws_generate_wsdl", 0);
        ZVAL_STRING (params[0], script_path.c, 0);
        INIT_PZVAL (params[0]);
        ZVAL_STRING (params[1], service_name, 0);
        INIT_PZVAL (params[1]);
        ZVAL_ZVAL (params[2], functions, NULL, NULL);
        INIT_PZVAL (params[2]);
        ZVAL_STRING (params[3], binding_name, 0);
        INIT_PZVAL (params[3]);
        ZVAL_STRING (params[4], wsdl_version, 0);
        INIT_PZVAL (params[4]);
        ZVAL_STRING (params[5], full_path.c , 0);
        INIT_PZVAL (params[5]);
        ZVAL_ZVAL (params[6], op_val, NULL, NULL);
        INIT_PZVAL (params[6]);
        script.type = ZEND_HANDLE_FP;
        
        script.filename = script_file_name.c;
        
        script.opened_path = NULL;
        
        script.free_filename = 0;
        
       if (!(script.handle.fp = VCWD_FOPEN (script.filename, "rb"))){
                 php_printf ("Unable to open script file or file not found:");
        }
        else{
            php_lint_script (&script TSRMLS_CC);
            if (call_user_function (EG (function_table), (zval **) NULL,
                    &func, &retval, 7, params TSRMLS_CC) == SUCCESS){

                if (Z_TYPE_P (&retval) == IS_STRING && Z_TYPE_P (&retval) != IS_NULL){
                    val = estrdup (Z_STRVAL (retval));
                    len = Z_STRLEN (retval);
                    sapi_add_header ("Content-Type:application/xml",
                        sizeof ("Content-Type:application/xml"), 1);
                    php_write (val, len TSRMLS_CC);
                    if(val){
                        efree(val);
                    }
                }else
                    php_printf ("WSDL Generation Failed");
            }
       }
       smart_str_free (&script_path);
       smart_str_free (&script_file_name);
       smart_str_free(&full_path);
       zval_ptr_dtor(&op_val);
       zval_ptr_dtor(&functions); 
        /** end WSDL generation stuff */ 

}
    
/* {{{ proto long reply([long style]) reply the SOAP request */ 
PHP_METHOD (ws_service, reply) 
{
    ws_object_ptr intern = NULL;
    zval * obj = NULL;
/*  axis2_conf_t * conf = NULL; */
    axis2_conf_ctx_t * conf_ctx = NULL;
    wsf_svc_info_t * svc_info = NULL;
    wsf_req_info_t  req_info;
    zval ** server_vars, **data;
    wsf_worker_t * php_worker = NULL;
    zval ** raw_post;
    int status = 0;

 /*  Char content_length[40]; */

    char status_line[100];
    char *content_type = NULL;
    int raw_post_null = AXIS2_FALSE;
    
    char *arg_data = NULL;
    int arg_data_len = 0;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|s", &arg_data, &arg_data_len) == FAILURE) {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "Invalid parameters");
    }

    WSF_GET_THIS (obj);
    intern = (ws_object *) zend_object_store_get_object (obj TSRMLS_CC);
    
    svc_info = (wsf_svc_info_t *) (intern->ptr);
    
    php_worker = svc_info->php_worker;
    
    conf_ctx = wsf_worker_get_conf_ctx (php_worker, ws_env_svr);

    if (!conf_ctx) {
        php_error_docref (NULL TSRMLS_CC, E_ERROR, "conf ctx missing");
        return;
    }

	if (php_start_ob_buffer(NULL, 0, 0 TSRMLS_CC) != SUCCESS) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR,"ob_start failed");
	}


    zend_is_auto_global ("_SERVER", sizeof ("_SERVER") - 1 TSRMLS_CC);
    
    wsf_php_req_info_init (&req_info);
    
    if(SG(request_info).request_uri){        
    
        if (zend_hash_find (&EG (symbol_table), "_SERVER", sizeof ("_SERVER"),
            (void **) & server_vars) == SUCCESS && (Z_TYPE_PP (server_vars) == IS_ARRAY)) {
			
			if ((zend_hash_find (Z_ARRVAL_PP (server_vars),
                    "HTTP_CONTENT_ENCODING", sizeof ("HTTP_CONTENT_ENCODING"),
                    (void **) & data) == SUCCESS)  && Z_TYPE_PP (data) == IS_STRING) {
				req_info.content_encoding = Z_STRVAL_PP (data);
			}

			if ((zend_hash_find (Z_ARRVAL_PP (server_vars),
                    "HTTP_TRANSFER_ENCODING", sizeof ("HTTP_TRANSFER_ENCODING"),
                    (void **) & data) == SUCCESS)  && Z_TYPE_PP (data) == IS_STRING) {
				req_info.transfer_encoding = Z_STRVAL_PP (data);
			}
			if ((zend_hash_find (Z_ARRVAL_PP (server_vars), "SERVER_NAME",
                    sizeof ("SERVER_NAME"), (void **)&data) == SUCCESS)  && 
					Z_TYPE_PP (data) == IS_STRING) {
				req_info.svr_name = Z_STRVAL_PP (data);
			}
			if ((zend_hash_find (Z_ARRVAL_PP (server_vars), "SERVER_PORT",
                    sizeof ("SERVER_PORT"), (void **)&data) == SUCCESS)  && 
					Z_TYPE_PP (data) == IS_STRING) {
				char *p = NULL;
				p = Z_STRVAL_PP (data);
				req_info.svr_port = atoi (p);
			}
			if ((zend_hash_find (Z_ARRVAL_PP (server_vars), "SERVER_PROTOCOL",
                    sizeof ("SERVER_PROTOCOL"), (void **)&data) == SUCCESS)  && 
					Z_TYPE_PP (data) ==  IS_STRING) {
				req_info.http_protocol = Z_STRVAL_PP (data);
			}
			if ((zend_hash_find (Z_ARRVAL_PP (server_vars), "SOAP_ACTION",
                    sizeof ("SOAP_ACTION"), (void **)&data) == SUCCESS)  &&
					Z_TYPE_PP (data) == IS_STRING) {
				req_info.soap_action = Z_STRVAL_PP (data);
			}
		}
		
		req_info.request_uri = SG (request_info).request_uri;
		req_info.content_length = SG (request_info).content_length;
		req_info.content_type = (char *) SG (request_info).content_type;
		req_info.request_method = (char *) SG (request_info).request_method;
		req_info.query_string = (char *) SG (request_info).query_string;
    	
		if (zend_hash_find (&EG(symbol_table), "HTTP_RAW_POST_DATA", sizeof ("HTTP_RAW_POST_DATA"), 
                    (void **)&raw_post) != FAILURE  && ((*raw_post)->type ==  IS_STRING)){
			req_info.req_data = Z_STRVAL_PP (raw_post);
			req_info.req_data_length = Z_STRLEN_PP (raw_post);
		}else {
			AXIS2_LOG_DEBUG(ws_env_svr->log, AXIS2_LOG_SI, "raw post data not found");
			if(req_info.request_method && strcmp(req_info.request_method,"POST") == 0){
				php_error_docref(NULL TSRMLS_CC, E_ERROR, "raw post data not found");
			}
		}	
		{
			zval ret_val, func;
			zval **tmp_action = NULL;
			ZVAL_STRING (&func, "apache_request_headers", 0);
			if (call_user_function (CG (function_table), (zval **) NULL, &func,
				&ret_val, 0, NULL TSRMLS_CC) == SUCCESS) {
				if(Z_TYPE(ret_val) == IS_ARRAY){
					if(zend_hash_find(Z_ARRVAL(ret_val), "SOAPAction", sizeof("SOAPAction"), 
							(void**)&tmp_action) == SUCCESS && Z_TYPE_PP(tmp_action) == IS_STRING){
									req_info.soap_action = Z_STRVAL_PP(tmp_action);
							}
					}
			}
           
		}
    
    } else if(ZEND_NUM_ARGS() > 0 && arg_data_len > 0){
        /* If we come here, it is not an HTTP post, 
           rather a command line script execution. 
           So set some defaults to facilitate standalone execution. */
        if((arg_data_len == 4 || arg_data_len == 5) && (stricmp (arg_data , "wsdl") || stricmp(arg_data, "wsdl2"))){
            req_info.request_uri = svc_info->svc_name;
            req_info.svr_name = estrdup("localhost");
            generate_wsdl_for_service(obj ,svc_info, &req_info, arg_data , 1 TSRMLS_CC);
            efree(req_info.svr_name);
            return;
        }
        req_info.svr_name = strdup("localhost");
        req_info.svr_port = 9999;
        req_info.req_data = arg_data;
        req_info.req_data_length = arg_data_len;
        req_info.http_protocol = strdup("HTTP");
        req_info.request_uri = svc_info->svc_name;
        req_info.request_method = strdup("POST");
        req_info.content_type = strdup("application/soap+xml;charset=UTF-8");
        req_info.content_length = arg_data_len;
        raw_post_null = AXIS2_TRUE;
          
    }else{
        php_printf("please provide reply function's argument soap envelope xml string\n");
        return;
    }
    
   
   if (SG (request_info).query_string && 
	   ((stricmp (SG (request_info).query_string, "wsdl") == 0)
       || (stricmp (SG (request_info).query_string, "wsdl2") == 0))) {
		/** begin WSDL Generation */ 
		generate_wsdl_for_service(obj ,svc_info, &req_info, SG(request_info).query_string , 0 TSRMLS_CC);

   }else {
       /*
        conf = axis2_conf_ctx_get_conf (conf_ctx, ws_env_svr);
        if (!axis2_conf_get_svc (conf, ws_env_svr, svc_info->svc_name))
             {
            axis2_conf_add_svc (conf, ws_env_svr, svc_info->svc);
            if (NULL != svc_info->modules_to_engage)
                 {
                int i = 0;
                int size =
                    axutil_array_list_size (svc_info->modules_to_engage,
                    ws_env_svr);
                for (i = 0; i < size; i++)
                     {
                    axis2_char_t * mod_name =
                        (axis2_char_t *) axutil_array_list_get (svc_info->
                        modules_to_engage, ws_env_svr, i);
                    wsf_util_engage_module (conf, mod_name, ws_env_svr,
                        svc_info->svc);
                    }
                }
            }
        */
/*         if(zend_hash_find(Z_OBJPROP_P(this_ptr), WS_WSDL,
 *                           sizeof(WS_WSDL), (void **)&tmp) == SUCCESS){
 *             wsf_wsdl_process_service(this_ptr, &req_info, svc_info, ws_env_svr TSRMLS_CC);
 *         }
 */
        status = wsf_worker_process_request (php_worker, ws_env_svr, &req_info, svc_info TSRMLS_CC);
        
        php_end_ob_buffer(0, 0 TSRMLS_CC);

        if (status == WS_HTTP_ACCEPTED){
            sprintf (status_line, "%s 202 Accepted", req_info.http_protocol);
            sapi_add_header (status_line, strlen (status_line), 1);
            sapi_add_header ("Content-Length: 0", sizeof ("Content-Length: 0") - 1, 1);
            content_type = emalloc(strlen (req_info.content_type) * sizeof (char) + 20);
            sprintf (content_type, "Content-Type: %s", req_info.content_type);
            sapi_add_header (content_type, strlen (content_type), 1);
        
		}else if (status == WS_HTTP_OK) {
            sprintf (status_line, "%s 200 OK", req_info.http_protocol);
            sapi_add_header (status_line, strlen (status_line), 1);
			content_type = emalloc(strlen (req_info.out_content_type) * sizeof (char) + 20);
            sprintf (content_type, "Content-Type: %s", req_info.out_content_type);
			sapi_add_header (content_type, strlen (content_type), 1);
            php_write (req_info.result_payload,
                req_info.result_length TSRMLS_CC);
        
		}else if (status == WS_HTTP_INTERNAL_SERVER_ERROR) {

            sprintf (status_line, "%s 500 Internal Server Error", req_info.http_protocol);
            sapi_add_header (status_line, strlen (status_line), 1);
			if (req_info.content_type){
                content_type = emalloc(strlen (req_info.content_type) * sizeof (char) + 20);
                sprintf (content_type, "Content-Type: %s", req_info.content_type);
                if (content_type){
                    sapi_add_header (content_type, strlen (content_type), 1);
                    php_write (req_info.result_payload, req_info.result_length TSRMLS_CC);
                }
            }
        }
		wsf_php_req_info_cleanup(&req_info, ws_env_svr);
    }
}
/* }}} end reply */ 
    
/************************* fault *********************************/ 
/* {{{ proto void WSFault::__construct(string faultcode, string faultreason [,string faultrole [, mixed detail[, string faultname]]]) */ 
PHP_METHOD (ws_fault, __construct) 
{
    char *sf_code = NULL, *sf_code_ns = NULL, *sf_reason = NULL, *sf_role =
        NULL, *value = NULL;
    int sf_code_len = 0, sf_reason_len = 0, sf_role_len = 0, value_len = 0;
    zval * code = NULL, *details = NULL;
    if (FAILURE == zend_parse_parameters (ZEND_NUM_ARGS ()TSRMLS_CC,
            "zs|s!z!s", &code, &sf_reason, &sf_reason_len, &sf_role,
            &sf_role_len, &details, &value, &value_len)) {
        php_error_docref (NULL TSRMLS_CC, E_ERROR, "Invalid Paramters");
        return;
    }
    if (Z_TYPE_P (code) == IS_STRING) {
        sf_code = Z_STRVAL_P (code);
        sf_code_len = Z_STRLEN_P (code);
    } else if (Z_TYPE_P (code) == IS_ARRAY
        && zend_hash_num_elements (Z_ARRVAL_P (code)) == 2) {
        zval ** tmp_ns, **tmp_code;
        zend_hash_internal_pointer_reset (Z_ARRVAL_P (code));
        zend_hash_get_current_data (Z_ARRVAL_P (code), (void **) &tmp_ns);
        zend_hash_move_forward (Z_ARRVAL_P (code));
        zend_hash_get_current_data (Z_ARRVAL_P (code), (void **) &tmp_code);
        if (Z_TYPE_PP (tmp_ns) == IS_STRING
            && Z_TYPE_PP (tmp_code) == IS_STRING) {
            sf_code_ns = Z_STRVAL_PP (tmp_ns);
            sf_code = Z_STRVAL_PP (tmp_code);
            sf_code_len = Z_STRLEN_PP (tmp_code);
        } else {
            php_error_docref (NULL TSRMLS_CC, E_ERROR,
                "Invalid parameters. Invalid fault code.");
        }
    } else {
        php_error_docref (NULL TSRMLS_CC, E_ERROR,
            "Invalid Parameters, Invalid fault code");
    }
    if (!sf_code || !sf_reason)
         {
        if (WSF_GLOBAL (soap_version) == AXIOM_SOAP11)
             {
            php_error_docref (NULL TSRMLS_CC, E_ERROR,
                "faultcode and faultstring are mandatory ");
            return;
            }
        
        else if (WSF_GLOBAL (soap_version) == AXIOM_SOAP12) {
            php_error_docref (NULL TSRMLS_CC, E_ERROR,
                "Code and Reason are mandatory ");
        }
        }
    wsf_util_set_soap_fault (this_ptr, sf_code_ns, sf_code, sf_reason,
        sf_role, details, value TSRMLS_CC);
}
/* }}} */ 
    
/* {{{ proto */ 
PHP_METHOD (ws_fault, __destruct) 
{
}
/* }}} */ 
PHP_METHOD (ws_fault, __toString) 
{
	zval *code, *reason,  *detail;
	char *fault_string;
	int length;

	if(ZEND_NUM_ARGS() > 0){
		ZEND_WRONG_PARAM_COUNT();
	}
	
	code = zend_read_property(ws_fault_class_entry, this_ptr, 
				WS_FAULT_CODE, sizeof(WS_FAULT_CODE) -1, 1 TSRMLS_CC);
	reason = zend_read_property(ws_fault_class_entry, this_ptr, 
				WS_FAULT_REASON, sizeof(WS_FAULT_REASON) -1, 1 TSRMLS_CC);
	detail = zend_read_property(ws_fault_class_entry, this_ptr,
				WS_FAULT_DETAIL, sizeof(WS_FAULT_DETAIL) -1, 1 TSRMLS_CC);

	if(Z_STRVAL_P(detail)){
	length = spprintf(&fault_string, 0, "WS FAULT exception: [%s] %s %s",
		Z_STRVAL_P(code), Z_STRVAL_P(reason), Z_STRVAL_P(detail));
	}else{
	length = spprintf(&fault_string, 0, "WS FAULT exception: [%s] %s",
		Z_STRVAL_P(code), Z_STRVAL_P(reason));
	}
	RETURN_STRINGL(fault_string, length, 0);
}

PHP_METHOD (ws_header, __construct) 
{
    zval * data = NULL, *role = NULL;
    char *name, *ns;
    int name_len, ns_len;
    zend_bool must_understand = 0;
    if (zend_parse_parameters (ZEND_NUM_ARGS ()TSRMLS_CC, "ss|zbz", &ns,
            &ns_len, &name, &name_len, &data, &must_understand, &role) == FAILURE) {
        php_error_docref (NULL TSRMLS_CC, E_ERROR, "Invalid parameters");
    }
    if (ns_len == 0) {
        php_error_docref (NULL TSRMLS_CC, E_ERROR,
            "Invalid parameters. Invalid namespace.");
    }
    if (name_len == 0) {
        php_error_docref (NULL TSRMLS_CC, E_ERROR,
            "Invalid parameters. Invalid header name.");
    }
    add_property_stringl (this_ptr, WS_HEADER_NS, ns, ns_len, 1);
    add_property_stringl (this_ptr, WS_HEADER_LOCALNAME, name, name_len, 1);
    if (data) {
        
#ifndef ZEND_ENGINE_2
            zval_add_ref (&data);
        
#endif  /*  */
            add_property_zval (this_ptr, WS_HEADER_DATA, data);
    }
        
            
    if (must_understand) {
        add_property_bool (this_ptr, WS_HEADER_MUST_UNDERSTAND,
            must_understand);
    }
    if (role) {
        if (Z_TYPE_P (role) == IS_LONG && 
            (Z_LVAL_P (role) == WS_SOAP_ROLE_NEXT
                || Z_LVAL_P (role) == WS_SOAP_ROLE_NONE
                || Z_LVAL_P (role) == WS_SOAP_ROLE_ULTIMATE_RECEIVER)) {
            add_property_long (this_ptr, WS_HEADER_ROLE, Z_LVAL_P (role));
     }
     else if (Z_TYPE_P (role) == IS_STRING && Z_STRLEN_P (role) > 0) {
            add_property_stringl (this_ptr, WS_HEADER_ROLE,
                Z_STRVAL_P (role), Z_STRLEN_P (role), 1);
     }
     else {
            php_error_docref (NULL TSRMLS_CC, E_ERROR,
                "Invalid parameters. Invalid role.");
          }
     }
}


/* {{{ WSSecurityToken::__construct( */ 
PHP_METHOD (ws_security_token, __construct) 
{
    zval * object = NULL;
    zval * options = NULL;
    zval ** tmp = NULL;
    if (zend_parse_parameters (ZEND_NUM_ARGS ()TSRMLS_CC, "a",
            &options) == FAILURE) {
        php_error_docref (NULL TSRMLS_CC, E_ERROR,
            "An array should be passed here");
    }
    
    WSF_GET_THIS (object);
    if (options) {
        HashTable * ht = Z_ARRVAL_P (options);
        if (zend_hash_find (ht, WS_USER, sizeof (WS_USER),
                (void **) &tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_STRING) {
            add_property_stringl (object, WS_USER, Z_STRVAL_PP (tmp),
                Z_STRLEN_PP (tmp), 1);
        }
        if (zend_hash_find (ht, WS_CERTIFICATE, sizeof (WS_CERTIFICATE),
                (void **) &tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_STRING) {
            add_property_stringl (object, WS_CERTIFICATE, Z_STRVAL_PP (tmp),
                Z_STRLEN_PP (tmp), 1);
        }
        if (zend_hash_find (ht, WS_PASSWORD_TYPE, sizeof (WS_PASSWORD_TYPE),
                (void **) &tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_STRING) {
            add_property_stringl (object, WS_PASSWORD_TYPE,
                Z_STRVAL_PP (tmp), Z_STRLEN_PP (tmp), 1);
        }
        if (zend_hash_find (ht, WS_PASSWORD, sizeof (WS_PASSWORD),
                (void **) &tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_STRING) {
            add_property_string (object, WS_PASSWORD, Z_STRVAL_PP (tmp), 1);
        }
        if (zend_hash_find (ht, WS_PRIVATE_KEY, sizeof (WS_PRIVATE_KEY),
                (void **) &tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_STRING) {
            add_property_string (object, WS_PRIVATE_KEY, Z_STRVAL_PP (tmp), 1);
        }
/*         if (zend_hash_find (ht, WS_PVT_KEY_FORMAT, */
/*                 sizeof (WS_PVT_KEY_FORMAT), (void **) &tmp) == SUCCESS &&  */
/*                 Z_TYPE_PP (tmp) == IS_STRING) { */
/*                add_property_string (object, WS_PVT_KEY_FORMAT, */
/*                Z_STRVAL_PP (tmp), 1); */
/*         } */
        if (zend_hash_find (ht, WS_CERTIFICATE, sizeof (WS_CERTIFICATE),
                (void **) &tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_STRING) {
            add_property_string (object, WS_CERTIFICATE, Z_STRVAL_PP (tmp), 1);
        }
        if (zend_hash_find (ht, WS_RECEIVER_CERTIFICATE,
                sizeof (WS_RECEIVER_CERTIFICATE), (void **) &tmp) == SUCCESS
            && Z_TYPE_PP (tmp) == IS_STRING)  {
            add_property_string (object, WS_RECEIVER_CERTIFICATE,
                Z_STRVAL_PP (tmp), 1);
        }
/*         if (zend_hash_find (ht, WS_RECEIVER_CERTIFICATE_FORMAT, */
/*                 sizeof (WS_RECEIVER_CERTIFICATE_FORMAT), */
/*                 (void **) &tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_STRING) { */
/*             add_property_string (object, WS_RECEIVER_CERTIFICATE_FORMAT, */
/*                 Z_STRVAL_PP (tmp), 1); */
/*         } */
        if (zend_hash_find (ht, WS_TTL, sizeof (WS_TTL),
                (void **) &tmp) == SUCCESS && Z_TYPE_PP (tmp) == IS_LONG) {
            add_property_long (object, WS_TTL, Z_LVAL_PP (tmp));
        }
        if (zend_hash_find (ht, WS_PASSWORD_CALL_BACK,
                sizeof (WS_PASSWORD_CALL_BACK), (void **) &tmp) == SUCCESS
            && Z_TYPE_PP (tmp) == IS_STRING) {
            add_property_string (object, WS_PASSWORD_CALL_BACK, Z_STRVAL_PP (tmp), 1);
        }
    }
} 

/* }}} */ 
    
/* {{{ WSPolicy::__construct( */ 
PHP_METHOD (ws_policy, __construct) 
{
    zval * object = NULL;
    zval * properties = NULL;
    if (FAILURE == zend_parse_parameters (ZEND_NUM_ARGS ()TSRMLS_CC, "|z|a",
            &properties)) {
        php_error_docref (NULL TSRMLS_CC, E_ERROR, "Invalid parameters");
        return;
    }
    WSF_GET_THIS (object);
    WSF_OBJ_CHECK (env);
    if (NULL != properties) {
        wsf_policy_set_policy_options (object, properties, env TSRMLS_CC);
    }
}
/* }}} */ 
    
/* {{{ proto string file_get_contents(string filename)
    read a pem file and return the key portion of the file as a string */ 
PHP_FUNCTION (ws_get_key_from_file) 
{
    char *filename;
    int filename_len;
    char *contents;
    php_stream * stream;
    int len;
    long maxlen = PHP_STREAM_COPY_ALL;
    zval * zcontext = NULL;
    php_stream_context * context = NULL;
    char *DELIMITER = "-----";
    
        /* Parse arguments */ 
    if (zend_parse_parameters (ZEND_NUM_ARGS ()TSRMLS_CC, "s", &filename,
            &filename_len) == FAILURE) {
        return;
    }
    context = php_stream_context_from_zval (zcontext, 0);
    stream = php_stream_open_wrapper_ex (filename, "rb",  
            (USE_PATH) | ENFORCE_SAFE_MODE | REPORT_ERRORS, NULL, context);
    if (!stream) {
        RETURN_FALSE;
    }
    if ((len = php_stream_copy_to_mem (stream, &contents, maxlen, 0)) > 0) {
        char *key = NULL;
        char *start_index = NULL;
        char *tmp_index = NULL;
        tmp_index = strstr (contents, DELIMITER);
        if (!tmp_index)
            return;
        if (len > (tmp_index - contents)) {
            tmp_index += 5;
            tmp_index = strstr (tmp_index, DELIMITER);
            if (!tmp_index)
                return;
            start_index = tmp_index + 6;
            tmp_index[contents - tmp_index] = '\0';
        }
        tmp_index = strstr (start_index, DELIMITER);
        if (!tmp_index)
            return;
        tmp_index = tmp_index + 1;
        start_index[tmp_index - start_index] = '\0';
        key = estrdup (start_index);
        efree (contents);
        RETVAL_STRINGL (key, strlen (key), 0);
    } else if (len == 0) {
        RETVAL_EMPTY_STRING ();
    } else {
        RETVAL_FALSE;
    }
    php_stream_close (stream);
}
/* }}} */ 
    
/* {{{ proto string file_get_contents(string filename)
    read a pem file and return the key portion of the file as a string */ 
PHP_FUNCTION (ws_get_cert_from_file) 
{
    char *filename;
    int filename_len;
    char *contents;
    php_stream * stream;
    int len;
    long maxlen = PHP_STREAM_COPY_ALL;
    zval * zcontext = NULL;
    php_stream_context * context = NULL;
    char *DELIMITER = "-----";
    
        /* Parse arguments */ 
    if (zend_parse_parameters (ZEND_NUM_ARGS ()TSRMLS_CC, "s", &filename,
            &filename_len) == FAILURE) {
        return;
    }
    context = php_stream_context_from_zval (zcontext, 0);
    stream = php_stream_open_wrapper_ex (filename, "rb", 
        (USE_PATH) | ENFORCE_SAFE_MODE | REPORT_ERRORS, NULL, context);
    if (!stream) {
        RETURN_FALSE;
    }
    if ((len = php_stream_copy_to_mem (stream, &contents, maxlen, 0)) > 0) {
        char *key = NULL;
        char *start_index = NULL;
        char *tmp_index = NULL;
        tmp_index = strstr (contents, DELIMITER);
        if (!tmp_index)
            return;
        if (len > (tmp_index - contents)) {
            tmp_index += 5;
            tmp_index = strstr (tmp_index, DELIMITER);
            if (!tmp_index)
                return;
            start_index = tmp_index + 6;
            tmp_index[contents - tmp_index] = '\0';
        }
        tmp_index = strstr (start_index, DELIMITER);
        if (!tmp_index)
            return;
        tmp_index = tmp_index + 1;
        start_index[tmp_index - start_index] = '\0';
        key = estrdup (start_index);
        efree (contents);
        RETVAL_STRINGL (key, strlen (key), 0);
    } else if (len == 0) {
        RETVAL_EMPTY_STRING ();
    } else {
        RETVAL_FALSE;
    }
    php_stream_close (stream);
}
/* }}} */ 
    
/* {{{  proto  WSClientProxy::__construct(mixed options) */ 
PHP_METHOD (ws_client_proxy, __construct) 
{

}


/* }}} end WSClient_proxt */ 
    
/* {{{ proto void WSClientProxy::__destruct() */ 
PHP_METHOD (ws_client_proxy, __destruct) 
{

}
    
/* {{{ proto WSClientProxy::__call() */ 
PHP_METHOD (ws_client_proxy, __call) 
{
    char *fn_name = NULL;
    long fn_name_len = 0;
    zval * args = NULL;
    zval ** real_args = NULL;
    zval ** param = NULL;
    int arg_count = 0;
    HashPosition pos;
    int i = 0;
    if (zend_parse_parameters (ZEND_NUM_ARGS ()TSRMLS_CC, "sz", &fn_name,
            &fn_name_len, &args) == FAILURE) {
        php_error_docref (NULL TSRMLS_CC, E_ERROR, "Invalid parameters");
        return;
    }
    arg_count = zend_hash_num_elements (Z_ARRVAL_P (args));
    if (arg_count > 0) {
        real_args = safe_emalloc (sizeof (zval *), arg_count, 0);
        for (zend_hash_internal_pointer_reset_ex (Z_ARRVAL_P (args), &pos);
            zend_hash_get_current_data_ex (Z_ARRVAL_P (args),
                (void **) &param, &pos) == SUCCESS;
            zend_hash_move_forward_ex (Z_ARRVAL_P (args), &pos)) {
            real_args[i++] = *param;
    } }
    
    create_dynamic_client(this_ptr, fn_name, fn_name_len, arg_count,
                          args, return_value, env TSRMLS_CC);

    if (arg_count) {
        efree (real_args);
    }
}


/* }}} end _call */ 
    
/* {{{ proto getFunctions() */ 
PHP_METHOD (ws_client_proxy, get_functions) 
{
    /* wsf_soap_get_functions (this_ptr, return_value, env TSRMLS_CC); */
}


/* }}} */ 
    
/* {{{ proto getFunctions() */ 
PHP_METHOD (ws_client_proxy, get_types) 
{
   /*    wsf_soap_get_types (this_ptr, return_value, env TSRMLS_CC); */
}


/* }}} */ 
    
/* {{{ proto getLocation() */ 
PHP_METHOD (ws_client_proxy, get_location) 
{
   /*    wsf_soap_get_location (this_ptr, return_value, env TSRMLS_CC); */
}


/* }}} end getLocation */ 
