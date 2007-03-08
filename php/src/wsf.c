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
#include "ext/standard/info.h"
#include <Zend/zend.h>
#include "zend_exceptions.h"
#include "zend_globals.h"
#include "zend_objects.h"
#include "wsf_common.h"
#include <axis2_env.h>

#include "wsf_util.h"

#include <axis2_svc_client.h>
#include <axiom_soap.h>
#include <axis2_http_transport.h>
#include <axis2_addr.h>
#include <axiom_util.h>
#include "wsf_client.h"
#include "wsf_policy.h"
#include <php_main.h>

ZEND_DECLARE_MODULE_GLOBALS(wsf)

zend_class_entry *ws_client_class_entry;
zend_class_entry *ws_service_class_entry;
zend_class_entry *ws_header_class_entry;
zend_class_entry *ws_fault_class_entry;
zend_class_entry *ws_message_class_entry;
zend_class_entry *ws_var_class_entry;
zend_class_entry *ws_client_proxy_class_entry;
zend_class_entry *ws_security_token_class_entry;
zend_class_entry *ws_policy_class_entry;


/* True global values, worker is thread safe */
static axis2_env_t *env;
static axis2_env_t *ws_env_svr;
wsf_worker_t *worker;

/** WSMessage functions */
PHP_METHOD(ws_message, __construct);
PHP_METHOD(ws_message, __get);

ZEND_BEGIN_ARG_INFO(__ws_message_get_args, 0)
ZEND_ARG_PASS_INFO(0)
ZEND_END_ARG_INFO()

/** Client functions */
PHP_METHOD(ws_client, __construct);
PHP_METHOD(ws_client, __destruct);
PHP_METHOD(ws_client, __call);
PHP_METHOD(ws_client, request);
PHP_METHOD(ws_client, send);
PHP_METHOD(ws_client, get_last_response);
PHP_METHOD(ws_client, get_last_request);
PHP_METHOD(ws_client, get_client);
PHP_METHOD(ws_client, terminate_outgoing_rm);


static 
ZEND_BEGIN_ARG_INFO(ws_client_call_args, 0)
ZEND_ARG_PASS_INFO(0)
ZEND_ARG_PASS_INFO(0)
ZEND_END_ARG_INFO()

/** WSService */
PHP_METHOD(ws_service , set_class);
PHP_METHOD(ws_service , reply);
PHP_METHOD(ws_service, __construct);
PHP_METHOD(ws_service, __destruct);

/** WSHeader class functions */
PHP_METHOD(ws_header, __construct);


PHP_METHOD(ws_security_token, __construct);
PHP_FUNCTION(ws_security_token_create_for_encryption);
PHP_FUNCTION(ws_security_token_create_for_decryption);
PHP_FUNCTION(ws_get_key_from_file);

/** WSFault */
PHP_METHOD(ws_fault, __construct);
PHP_METHOD(ws_fault, __destruct);
PHP_METHOD(ws_fault, __get);
PHP_METHOD(ws_fault, get_soap_fault_text);

/** WSPolicy class functions */
PHP_METHOD(ws_policy, __construct);

ZEND_BEGIN_ARG_INFO(__ws_fault_get_args, 0)
ZEND_ARG_PASS_INFO(0)
ZEND_END_ARG_INFO()


zend_function_entry php_ws_message_class_functions[] ={
            PHP_ME(ws_message, __construct, NULL, ZEND_ACC_PUBLIC)
            PHP_ME(ws_message, __get, __ws_message_get_args , ZEND_ACC_PUBLIC)
            {
                NULL , NULL, NULL
            }
        };

/** client function entry */
zend_function_entry php_ws_client_class_functions[]={
	PHP_MALIAS(ws_client, request, request, NULL,ZEND_ACC_PUBLIC)
	PHP_MALIAS(ws_client, send, send, NULL,ZEND_ACC_PUBLIC)
	PHP_MALIAS(ws_client,getLastResponse, get_last_response, NULL ,ZEND_ACC_PUBLIC)
	PHP_MALIAS(ws_client, getLastRequest, get_last_request , NULL , ZEND_ACC_PUBLIC)
	PHP_MALIAS(ws_client, getClient, get_client, NULL, ZEND_ACC_PUBLIC)
	PHP_MALIAS(ws_client, terminateOutgoingRM , terminate_outgoing_rm, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ws_client, __call, ws_client_call_args, ZEND_ACC_PUBLIC)
	PHP_ME(ws_client, __construct, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ws_client, __destruct, NULL, ZEND_ACC_PUBLIC)
	{NULL , NULL, NULL}
};


/** service function entry */
zend_function_entry php_ws_service_class_functions[]=
    {
        PHP_MALIAS(ws_service , setClass, set_class, NULL, ZEND_ACC_PUBLIC)
        PHP_MALIAS(ws_service , reply, reply, NULL, ZEND_ACC_PUBLIC)
        PHP_ME(ws_service, __construct, NULL, ZEND_ACC_PUBLIC)
        PHP_ME(ws_service, __destruct, NULL, ZEND_ACC_PUBLIC)
        {
            NULL , NULL, NULL
        }
    };

/** WSFault class entry */
zend_function_entry php_ws_fault_class_functions[]=
    {
        PHP_MALIAS(ws_fault ,getSoapFaultText, get_soap_fault_text, NULL, ZEND_ACC_PUBLIC)
        PHP_ME(ws_fault, __construct, NULL, ZEND_ACC_PUBLIC)
        PHP_ME(ws_fault, __destruct, NULL, ZEND_ACC_PUBLIC)
        PHP_ME(ws_fault, __get, __ws_fault_get_args, ZEND_ACC_PUBLIC)
        {
            NULL , NULL, NULL
        }
    };

/* {{{ WSHeader class functions */
zend_function_entry php_ws_header_class_functions[] =   {
        PHP_ME(ws_header, __construct, NULL, ZEND_ACC_PUBLIC)
        {  NULL, NULL, NULL  }
    };

zend_function_entry php_ws_security_token_class_functions[]={
            PHP_ME(ws_security_token, __construct, NULL, ZEND_ACC_PUBLIC)
            {    NULL, NULL, NULL   }
        };

zend_function_entry php_ws_policy_class_functions[]={
            PHP_ME(ws_policy, __construct, NULL, ZEND_ACC_PUBLIC)
            {   NULL, NULL, NULL   }
        };

/* {{{ wsf_functions[] */
zend_function_entry wsf_functions[] = {
	PHP_FE(is_ws_fault, NULL)
	PHP_FE(ws_get_key_from_file, NULL)
	PHP_FE(ws_test_function, NULL)
	{ NULL, NULL, NULL }	/* Must be the last line in wsf_functions[] */
};
/* }}} */

static zend_object_handlers ws_object_handlers;
/** object creation and destruction functions */
static zend_object_value
php_ws_object_new(zend_class_entry *class_type TSRMLS_DC);

static zend_object_value
php_ws_object_new_ex(zend_class_entry *class_type ,
                     ws_object **obj TSRMLS_DC);

static zval* ws_create_object(void *obj, int obj_type,
                              zend_class_entry* class_type TSRMLS_DC);

static void ws_object_dtor(void *object,
                           zend_object_handle handle TSRMLS_DC);

/* {{{ ws_worker_dtor() */
static void ws_worker_dtor(zend_rsrc_list_entry *rsrc TSRMLS_DC)
{
    /** TODO free worker */
}
/* }}} */

/* {{{ ws_convert_libxml_to_om
   */
static axiom_node_t* ws_convert_libxml_to_om(zval *node)
{
    axiom_node_t *om_node = NULL;
    axiom_xml_reader_t *reader = NULL;
    php_libxml_node_object *object;
    xmlNodePtr nodep;

    TSRMLS_FETCH();
    object = (php_libxml_node_object *)zend_object_store_get_object(node TSRMLS_CC);
    nodep = php_libxml_import_node(node TSRMLS_CC);
    if (!nodep)
    {
        return NULL;
    }
    if (nodep->doc == NULL)
    {
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "Imported Node must have \
                         associated Document");
        return NULL;
    }
    if (nodep->type == XML_DOCUMENT_NODE || nodep->type == XML_HTML_DOCUMENT_NODE)
    {
        nodep = xmlDocGetRootElement((xmlDocPtr) nodep);
    }
    reader = axiom_xml_reader_create_for_memory(env,
             (void*)nodep->doc, 0, "utf-8", AXIS2_XML_PARSER_TYPE_DOC);
    if (!reader)
    {
        return NULL;
    }
    om_node = ws_util_read_payload(reader, env);
    return om_node;
}
/* }}} end ws_convert_libxml_to_om */

/* {{{ proto create an WSFault object */
void ws_throw_soap_fault(axiom_soap_body_t *soap_body TSRMLS_DC)
{

    if(soap_body)
    {
        /* TODO free */
        zval *zval_ws_fault = NULL;
        axiom_soap_fault_t *soap_fault = NULL;
        if(AXIOM_SOAP_BODY_HAS_FAULT(soap_body, env))
        {
            soap_fault = AXIOM_SOAP_BODY_GET_FAULT(soap_body, env);
            if(soap_fault)
            {
                /** default soap version */
                int soap_version;
                axis2_char_t *fault_code = NULL;
                axiom_soap_fault_code_t *sf_code = NULL;
                axiom_node_t *sf_code_node = NULL;
                axis2_char_t *fault_reason = NULL;
                axiom_soap_fault_reason_t *sf_reason = NULL;
                axiom_node_t *sf_reason_node = NULL;
                axis2_char_t *fault_role = NULL;
                axiom_soap_fault_role_t *sf_role = NULL;
                axiom_node_t *sf_role_node = NULL;
                axis2_char_t *fault_detail = NULL;
                axiom_node_t *sf_detail_node = NULL;
                axiom_soap_fault_detail_t *sf_detail = NULL;

                if(AXIOM_SOAP_BODY_GET_SOAP_VERSION(soap_body, env) == AXIOM_SOAP12)
                    soap_version = AXIOM_SOAP12;
                else if(AXIOM_SOAP_BODY_GET_SOAP_VERSION(soap_body, env) == AXIOM_SOAP11)
                    soap_version = AXIOM_SOAP11;
                else
                    return;


                MAKE_STD_ZVAL(zval_ws_fault);
                object_init_ex(zval_ws_fault, ws_fault_class_entry);
                add_property_long(zval_ws_fault, "soap_version", soap_version);

                sf_code = AXIOM_SOAP_FAULT_GET_CODE(soap_fault, env);
                if(sf_code)
                {
                    sf_code_node = AXIOM_SOAP_FAULT_CODE_GET_BASE_NODE(sf_code, env);
                    if(sf_code_node)
                    {
                        fault_code = AXIOM_NODE_TO_STRING(sf_code_node, env);
                        add_property_string(zval_ws_fault, "code", fault_code, 1);
                    }
                }
                sf_reason = AXIOM_SOAP_FAULT_GET_REASON(soap_fault, env);
                if(sf_reason)
                {
                    sf_reason_node = AXIOM_SOAP_FAULT_REASON_GET_BASE_NODE(sf_reason, env);
                    if(sf_reason_node)
                    {
                        fault_reason = AXIOM_NODE_TO_STRING(sf_reason_node, env);
                        add_property_string(zval_ws_fault, "reason", fault_reason, 1);
                    }
                }
                sf_role = AXIOM_SOAP_FAULT_GET_ROLE(soap_fault, env);
                if(sf_role)
                {
                    sf_role_node = AXIOM_SOAP_FAULT_GET_BASE_NODE(soap_fault, env);
                    if(sf_role_node)
                    {
                        fault_reason = AXIOM_NODE_TO_STRING(sf_role_node, env);
                        add_property_string(zval_ws_fault, "role", fault_role, 1);
                    }
                }
                sf_detail = AXIOM_SOAP_FAULT_GET_DETAIL(soap_fault, env);
                if(sf_detail)
                {
                    sf_detail_node = AXIOM_SOAP_FAULT_GET_BASE_NODE(soap_fault, env);
                    if(sf_detail_node)
                    {
                        fault_detail = AXIOM_NODE_TO_STRING(sf_detail_node, env);
                        add_property_string(zval_ws_fault, "detail", fault_detail, 1);
                    }
                }
                zend_throw_exception_object(zval_ws_fault TSRMLS_CC);
            }
        }
        else
        {
            zend_throw_exception_ex(zend_exception_get_default(TSRMLS_C), 1 TSRMLS_CC,
                                    "cannot find soap body");
        }
    }
}

/* {{{ proto ws_get_xml_node
*/
static xmlNodePtr ws_get_xml_node(zval *node)
{
    php_libxml_node_object *object;
    xmlNodePtr nodep;

    TSRMLS_FETCH();
    object = (php_libxml_node_object *)zend_object_store_get_object(node TSRMLS_CC);
    nodep = php_libxml_import_node(node TSRMLS_CC);
    if (!nodep)
    {
        return NULL;
    }
    if (nodep->doc == NULL)
    {
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "Imported Node must have \
                         associated Document");
        return NULL;
    }
    if (nodep->type == XML_DOCUMENT_NODE || nodep->type == XML_HTML_DOCUMENT_NODE)
    {
        nodep = xmlDocGetRootElement((xmlDocPtr) nodep);
    }
    return nodep;
}
/* }}} end ws_get_xml_node */


/* {{{ wsf_module_entry */
zend_module_entry wsf_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
     "wsf",
     wsf_functions,
     PHP_MINIT(wsf),
     PHP_MSHUTDOWN(wsf),
     PHP_RINIT(wsf),
     PHP_RSHUTDOWN(wsf),
     PHP_MINFO(wsf),
#if ZEND_MODULE_API_NO >= 20010901 
	 "0.1", /* Replace with version number for your extension */
#endif
    STANDARD_MODULE_PROPERTIES
};
/* }}} */

/*#ifdef COMPILE_DL_AXIS2*/
#ifdef COMPILE_DL_WSF
ZEND_GET_MODULE(wsf)
#endif

/* {{{ PHP_INI */
PHP_INI_BEGIN()
STD_PHP_INI_ENTRY("wsf.home", NULL, PHP_INI_ALL,
                  OnUpdateString, home, zend_wsf_globals, wsf_globals)
STD_PHP_INI_ENTRY("wsf.passwd_location","/usr/local/apache2/passwd/passwords", PHP_INI_ALL,
                  OnUpdateString, passwd_location, zend_wsf_globals, wsf_globals)
STD_PHP_INI_ENTRY("wsf.log_path", "/tmp", PHP_INI_ALL, OnUpdateString,
                  log_path, zend_wsf_globals, wsf_globals)
STD_PHP_INI_ENTRY("wsf.enable_trace", "1", PHP_INI_ALL, OnUpdateBool,
                  enable_trace, zend_wsf_globals, wsf_globals)
STD_PHP_INI_ENTRY("wsf.enable_exception", "1", PHP_INI_ALL, OnUpdateBool,
                  enable_exception, zend_wsf_globals, wsf_globals)
STD_PHP_INI_ENTRY("wsf.rm_db_dir", "/tmp", PHP_INI_ALL, OnUpdateString,
                  rm_db_dir, zend_wsf_globals, wsf_globals)
PHP_INI_END()
/* }}} */

/* {{{ ws_init_globals
 */
static void ws_init_globals(zend_wsf_globals *wsf_globals)
{
    wsf_globals->home = NULL;
    wsf_globals->log_path = NULL;
    wsf_globals->enable_trace = 0;
    wsf_globals->enable_exception = 0;
    wsf_globals->soap_version = AXIOM_SOAP12;
    wsf_globals->passwd_location = NULL;
    wsf_globals->soap_uri = AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI;
    wsf_globals->rm_db_dir = NULL;
    wsf_globals->curr_ns_index= 0;

}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(wsf)
{
    zend_class_entry ce;
    char *home_folder = NULL;

    ZEND_INIT_MODULE_GLOBALS(wsf, ws_init_globals, NULL);
    REGISTER_INI_ENTRIES();
    if (INI_STR("extension_dir"))
    {
        char *home_dir = pemalloc(strlen(INI_STR("extension_dir")) + strlen("/wsf_c") + 1, 1);
        strcpy(home_dir, INI_STR("extension_dir"));
        strcat(home_dir, "/wsf_c");
        home_folder = home_dir;
    }

    memcpy(&ws_object_handlers, zend_get_std_object_handlers(),
           sizeof(zend_object_handlers));
    ws_object_handlers.clone_obj = NULL;

    REGISTER_WSF_CLASS(ce, "WSClient", NULL,
                       php_ws_client_class_functions, ws_client_class_entry);

    REGISTER_WSF_CLASS(ce, "WSService", NULL,
                       php_ws_service_class_functions, ws_service_class_entry);


    INIT_CLASS_ENTRY(ce, "WSMessage", php_ws_message_class_functions);
    ws_message_class_entry =  zend_register_internal_class(&ce TSRMLS_CC);

    INIT_CLASS_ENTRY(ce, "WSHeader", php_ws_header_class_functions);
    ws_header_class_entry = zend_register_internal_class(&ce TSRMLS_CC);

    INIT_CLASS_ENTRY(ce, "WSFault", php_ws_fault_class_functions);
    /**ws_fault_class_entry = zend_register_internal_class_ex(&ce, zend_exception_get_default(), NULL TSRMLS_CC);*/
    ws_fault_class_entry = zend_register_internal_class(&ce TSRMLS_CC);

    INIT_CLASS_ENTRY(ce, "WSSecurityToken", php_ws_security_token_class_functions);
    ws_security_token_class_entry = zend_register_internal_class(&ce TSRMLS_CC);

    INIT_CLASS_ENTRY(ce, "WSPolicy", php_ws_policy_class_functions);
    ws_policy_class_entry = zend_register_internal_class(&ce TSRMLS_CC);

    REGISTER_LONG_CONSTANT("WS_SOAP_ROLE_NEXT", WS_SOAP_ROLE_NEXT, CONST_CS | CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("WS_SOAP_ROLE_NONE", WS_SOAP_ROLE_NONE, CONST_CS | CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("WS_SOAP_ROLE_ULTIMATE_RECEIVER", WS_SOAP_ROLE_ULTIMATE_RECEIVER, CONST_CS | CONST_PERSISTENT);

    env = wsf_env_create(WSF_GLOBAL(log_path));
    if (WSF_GLOBAL(home))
        home_folder = WSF_GLOBAL(home);

    ws_env_svr = wsf_env_create_svr(WSF_GLOBAL(log_path));

    worker = wsf_worker_create(ws_env_svr, home_folder, WSF_GLOBAL(rm_db_dir));
    axiom_xml_reader_init();

    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(wsf)
{
    UNREGISTER_INI_ENTRIES();
    axiom_xml_reader_cleanup();
    return SUCCESS;
}
/* }}} */

/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(wsf)
{
    WSF_GLOBAL(soap_version) = AXIOM_SOAP12;
    return SUCCESS;
}
/* }}} */

/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(wsf)
{
    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(wsf)
{
    php_info_print_table_start();
    php_info_print_table_header(2, "wsf support", "enabled");
    php_info_print_table_end();
    DISPLAY_INI_ENTRIES();
}
/* }}} */

/* {{{ ws_object_new */
static zend_object_value
php_ws_object_new(zend_class_entry *class_type TSRMLS_DC)
{
    ws_object *tmp;
    return php_ws_object_new_ex(class_type, &tmp TSRMLS_CC);
}
/* }}} */

/* {{{ ws_object_new_ex */
static zend_object_value
php_ws_object_new_ex(zend_class_entry *class_type ,
                     ws_object **obj TSRMLS_DC)
{
    zend_object_value retval;
    ws_object *intern;
    zval *tmp;

    intern = emalloc(sizeof(ws_object));
    memset(intern, 0, sizeof(ws_object));
    intern->std.ce = class_type;
    *obj = intern;

    ALLOC_HASHTABLE(intern->std.properties);
    zend_hash_init(intern->std.properties, 0, NULL, ZVAL_PTR_DTOR, 0);
    zend_hash_copy(intern->std.properties, &class_type->default_properties,
                   (copy_ctor_func_t)zval_add_ref, (void *)&tmp, sizeof(void *));

    retval.handle = zend_objects_store_put(intern,
					(zend_objects_store_dtor_t)ws_object_dtor, NULL, NULL TSRMLS_CC);
    retval.handlers = &ws_object_handlers;
    return retval;
}
/* }}} */

/* {{{ create an zval with given class type and stores the provide obj */
static zval* ws_create_object(void *obj, int obj_type,
                              zend_class_entry* class_type TSRMLS_DC)
{
    zval *wrapper = NULL;
    zend_class_entry *ce = NULL;
    ws_object_ptr intern = NULL;
    if(!obj)
    {
        return NULL;
    }
    ce = class_type;
    ALLOC_ZVAL(wrapper);
    object_init_ex(wrapper, ce);
    intern = (ws_object_ptr)zend_objects_get_address(wrapper TSRMLS_CC);
    ZVAL_ADDREF(wrapper);
    intern->ptr = obj;
    intern->obj_type = obj_type;
    return wrapper;
}
/* }}} */

/* {{{ destructor function for all ws_objects */
static void ws_object_dtor(void *object,
                           zend_object_handle handle TSRMLS_DC)
{
    ws_object *intern = (ws_object *)object;
    zend_hash_destroy(intern->std.properties);
    FREE_HASHTABLE(intern->std.properties);
}

/*** {{{ is_ws_fault(Object obj) */
PHP_FUNCTION(is_ws_fault)
{
    zval *object = NULL;

    if (FAILURE == zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &object)){
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "Invalid parameters");
        return;
    }
    if(Z_TYPE_P(object) == IS_OBJECT && instanceof_function(Z_OBJCE_P(object), 
		ws_fault_class_entry TSRMLS_CC)){
        RETURN_TRUE;
    }
    else RETURN_FALSE;
}
/* }}} */

/* {{{ proto WSMessage::__construct(mixed payload[, array properties, array cidtostrings) */
PHP_METHOD(ws_message, __construct)
{
    zval *object = NULL;

    zval *payload = NULL;
    zval *properties = NULL;
    /*  zval *attachments = NULL; */

    if (FAILURE == zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|a", &payload ,
                                         &properties)){
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "Invalid parameters");
        return;
    }

    WSF_GET_THIS(object);
    WSF_OBJ_CHECK(env);

    if(Z_TYPE_P(payload) == IS_STRING){
		add_property_stringl(object , WS_MSG_PAYLOAD_STR, Z_STRVAL_P(payload), Z_STRLEN_P(payload), 1);
        add_property_long(object, WS_MSG_TYPE, WS_USING_STRING);
    }
    else if(Z_TYPE_P(payload) == IS_OBJECT &&
            instanceof_function(Z_OBJCE_P(payload), dom_node_class_entry TSRMLS_CC)) {
        add_property_zval(object, WS_MSG_PAYLOAD_DOM, payload);
        add_property_long(object, WS_MSG_TYPE, WS_USING_DOM);
    }
    else {
        return;
    }

    if (NULL != properties) {
        zval **tmp;
        HashTable *ht = Z_ARRVAL_P(properties);
        if(!ht){
            return;
        }
		
		add_property_zval(object, WS_OPTIONS, properties);

		/*
        if(zend_hash_find(ht, WS_TO, sizeof(WS_TO), (void **)&tmp) == SUCCESS &&
                Z_TYPE_PP(tmp) == IS_STRING)
        {
            add_property_stringl(object, WS_TO, Z_STRVAL_PP(tmp), Z_STRLEN_PP(tmp), 1);
        }

        if(zend_hash_find(ht, WS_ACTION, sizeof(WS_ACTION), (void **)&tmp) == SUCCESS &&
                Z_TYPE_PP(tmp) == IS_STRING)
        {
            add_property_stringl(object, WS_ACTION, Z_STRVAL_PP(tmp), Z_STRLEN_PP(tmp), 1);
        }
        if(zend_hash_find(ht, WS_FROM, sizeof(WS_FROM), (void **)&tmp) == SUCCESS &&
                Z_TYPE_PP(tmp) == IS_STRING)
        {
            add_property_stringl(object, WS_FROM, Z_STRVAL_PP(tmp), Z_STRLEN_PP(tmp), 1);
        }
        if(zend_hash_find(ht, WS_REPLY_TO, sizeof(WS_REPLY_TO), (void **)&tmp) == SUCCESS &&
                Z_TYPE_PP(tmp) == IS_STRING)
        {
            add_property_stringl(object, WS_REPLY_TO, Z_STRVAL_PP(tmp), Z_STRLEN_PP(tmp), 1);
        }
        if(zend_hash_find(ht, WS_FAULT_TO, sizeof(WS_FAULT_TO), (void **)&tmp) == SUCCESS &&
                Z_TYPE_PP(tmp) == IS_STRING)
        {
            add_property_stringl(object, WS_FAULT_TO, Z_STRVAL_PP(tmp), Z_STRLEN_PP(tmp), 1);
        }


		if(zend_hash_find(ht, WS_LAST_MESSAGE, sizeof(WS_LAST_MESSAGE), (void**)&tmp) == SUCCESS){
			if(Z_TYPE_PP(tmp) == IS_BOOL){
				add_property_bool(object, WS_LAST_MESSAGE, Z_BVAL_PP(tmp));
			}
		}


        if(zend_hash_find(ht, WS_USES_XOP, sizeof(WS_USES_XOP), (void **)&tmp) == SUCCESS &&
                Z_TYPE_PP(tmp) == IS_BOOL)
        {
            add_property_bool(object, WS_USES_XOP, Z_BVAL_PP(tmp));
        }
        else
        {
            add_property_bool(object, WS_USES_XOP, 1);
        }
        if(zend_hash_find(ht, WS_DEFAULT_ATTACHEMENT_CONTENT_TYPE, sizeof(WS_DEFAULT_ATTACHEMENT_CONTENT_TYPE), (void **)&tmp) == SUCCESS &&
                Z_TYPE_PP(tmp) == IS_STRING)
        {
            add_property_stringl(object, WS_DEFAULT_ATTACHEMENT_CONTENT_TYPE, Z_STRVAL_PP(tmp), Z_STRLEN_PP(tmp),1);
        }
        else
        {
            add_property_string(object, WS_DEFAULT_ATTACHEMENT_CONTENT_TYPE, estrdup("application/octet-stream"),1);
        }
		*/

        if(zend_hash_find(ht, WS_ATTACHMENTS, sizeof(WS_ATTACHMENTS), (void **)&tmp) == SUCCESS &&
                Z_TYPE_PP(tmp) == IS_ARRAY)
        {
            add_property_zval(object, WS_ATTACHMENTS, *tmp);
        }
		
        /** adding custom headers */
        if(zend_hash_find(ht, WS_HEADERS, sizeof(WS_HEADERS), (void**)&tmp) == SUCCESS){
            if(Z_TYPE_PP(tmp) == IS_ARRAY){
                add_property_zval(object, WS_HEADERS, *tmp);
            }
        }
    }
}
/* }}} */

/** desctructor */
PHP_METHOD(ws_message, __destruct)
{
	
}


static int get_message_storage_type(zval *this_ptr TSRMLS_DC)
{
    zval **param_val = NULL;
    if(zend_hash_find(Z_OBJPROP_P(this_ptr), WS_MSG_PAYLOAD_TYPE,
                      sizeof(WS_MSG_PAYLOAD_TYPE), (void**)&param_val) == SUCCESS &&
            Z_TYPE_PP(param_val) == IS_LONG)
    {
        return Z_LVAL_PP(param_val);
    }
    return -1;
}

/* {{{ WSMessage::__get() */
PHP_METHOD(ws_message, __get)
{
    zval *object = NULL;
    char *prop_name = NULL;
    long prop_name_len = 0;
    /*     zval **param_val = NULL; */
    /*     int msg_payload_type = -1; */

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s",
                              &prop_name, &prop_name_len) == FAILURE)
    {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "Invalid parameters");
    }
    if(prop_name_len <= 0)
    {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "Invalid property");
    }

    WSF_GET_THIS(object);
    if(strcmp(prop_name, WS_MSG_PAYLOAD_STR) == 0)
    {
        if(get_message_storage_type(object TSRMLS_CC) == WS_USING_DOM ||
                get_message_storage_type(object TSRMLS_CC) == WS_USING_SIMPLEXML)
        {
            xmlNodePtr nodep;
            axiom_node_t *payload = NULL;
            zval **tmp_val = NULL;
            axiom_xml_reader_t *reader = NULL;

            if((zend_hash_find(Z_OBJPROP_P(object), WS_MSG_PAYLOAD_DOM,
                               sizeof(WS_MSG_PAYLOAD_DOM), (void**)&tmp_val) == SUCCESS)||
                    (zend_hash_find(Z_OBJPROP_P(object), WS_MSG_PAYLOAD_SXML,
                                    sizeof(WS_MSG_PAYLOAD_SXML), (void**)&tmp_val) == SUCCESS))
            {
                nodep = ws_get_xml_node(*tmp_val);
                reader = axiom_xml_reader_create_for_memory(env,
                         (void*)nodep->doc, 0, "utf-8", AXIS2_XML_PARSER_TYPE_DOC);

                if (!reader)
                {
                    zend_throw_exception_ex(zend_exception_get_default(TSRMLS_C), 1 TSRMLS_CC,
                                            "xml reader create failed");
                }

                payload = ws_util_read_payload(reader, env);
                if(payload)
                {
                    axis2_char_t *res_text = NULL;
                    res_text = wsf_util_serialize_om(env, payload);
                    if(res_text)
                    {
                        add_property_string(object, WS_MSG_PAYLOAD_STR, res_text, 1);
                        RETURN_STRING(res_text, 1);
                    }
                    /** todo memory leaks */
                }
            }
        }
    }
    else if(strcmp(prop_name, WS_MSG_PAYLOAD_DOM) == 0)
    {
        if(get_message_storage_type(object TSRMLS_CC) == WS_USING_STRING)
        {
            axiom_node_t *payload = NULL;
            zval **tmp_val = NULL;
            axiom_xml_reader_t *reader = NULL;

            if(zend_hash_find(Z_OBJPROP_P(object), WS_MSG_PAYLOAD_DOM,
                              sizeof(WS_MSG_PAYLOAD_DOM), (void**)&tmp_val) == SUCCESS)
            {
                char *val = Z_STRVAL_PP(tmp_val);
                if(val)
                {
                    reader = axiom_xml_reader_create_for_memory(env,
                             val, 0, "utf-8", AXIS2_XML_PARSER_TYPE_BUFFER);

                    if (!reader)
                    {
                        zend_throw_exception_ex(zend_exception_get_default(TSRMLS_C), 1 TSRMLS_CC,
                                                "reader create failed");
                    }
                    payload = ws_util_read_payload(reader, env);
                    if(payload)
                    {
                        int ret;
                        zval *value = NULL;
                        xmlDocPtr doc = NULL;
                        doc = wsf_util_serialize_om_to_doc(env, payload);
                        if (!doc)
                        {
                            RETURN_NULL();
                        }
                        value = php_dom_create_object((xmlNodePtr)doc, &ret, NULL,  return_value, NULL TSRMLS_CC);
                        add_property_zval(object, WS_MSG_PAYLOAD_DOM, value);
                        RETURN_ZVAL(value, NULL, NULL);
                    }
                }
            }
        }
    }
}
/* }}} */

/* {{{ proto void WSClient::__construct(string uri[, array options]) */
PHP_METHOD(ws_client, __construct)
{
    ws_object_ptr intern = NULL;
    zval *obj = NULL;
    /* 	axis2_char_t *wsdl_path = NULL;     */
    char *home_folder = NULL;
    axis2_svc_client_t *svc_client = NULL;
    /* 	char *wsdlpath = NULL; */
    /* 	int wsdlpath_len = 0; */
    zval *options = NULL;
    if (FAILURE == zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|a",
                                         &options))
    {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "Invalid parameters");
        return;
    }
    WSF_OBJ_CHECK(env);

    WSF_GET_THIS(obj);
    intern = (ws_object*)zend_object_store_get_object(obj TSRMLS_CC);

    if (INI_STR("extension_dir"))
    {
        char *home_dir = pemalloc(strlen(INI_STR("extension_dir")) + strlen("/wsf_c") + 1, 1);
        strcpy(home_dir, INI_STR("extension_dir"));
        strcat(home_dir, "/wsf_c");
        home_folder = home_dir;
    }

    if (WSF_GLOBAL(home))
        home_folder = WSF_GLOBAL(home);
    svc_client = axis2_svc_client_create(env, home_folder);

    if (!svc_client)
    {
        zend_throw_exception_ex(zend_exception_get_default(TSRMLS_C), 1 TSRMLS_CC,
                                "ws client create failed");
    }

    intern->ptr = svc_client;
    intern->obj_type = WS_SVC_CLIENT;
    /*
        Please refer to API doc for input options processed below. 
           This implementation adheres to the API doc.
    */
    if (NULL != options)
    {
        zval **tmp;
        HashTable *ht = Z_ARRVAL_P(options);

        if(!ht)
            return;

		add_property_zval(obj, WS_OPTIONS, options);
		/**  wsf_client_add_properties(obj , ht TSRMLS_CC); */

        if(zend_hash_find(ht, WS_WSDL, sizeof(WS_WSDL), (void **)&tmp) == SUCCESS &&
                Z_TYPE_PP(tmp) == IS_STRING)
        {
            /*
            int wsdl_cache = 0, ret;
            sdlPtr sdl;
            wsdl_path = Z_STRVAL_PP(tmp);
            sdl = get_sdl(obj , wsdl_path, wsdl_cache TSRMLS_CC);
            ret = zend_list_insert(sdl, le_sdl);
            add_property_resource(obj , "sdl", ret); 
            */
        }
    }
}
/* }}} */

/* {{{ WSClient::__destruct() */
PHP_METHOD(ws_client, __destruct)
{
}
/* }}} */

/* {{{ proto string request(mixed payload)
	payload can be a string, dom element or a simple xml element.
	send and receives. if the input was a string or a simple xml element
	it would return a string, if the input was a dom node , it returns a dom
	node.
	*/
PHP_METHOD(ws_client , request)
{
    zval *param = NULL;
    ws_object_ptr intern = NULL;
    zval *obj = NULL;

    axis2_svc_client_t *svc_client = NULL;

    if (FAILURE == zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &param))
    {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "Invalid parameters");
        return;
    }
    WSF_OBJ_CHECK(env);
    WSF_GET_THIS(obj);
    WSF_GET_OBJ(svc_client, obj, axis2_svc_client_t, intern);
    wsf_client_do_request(obj, param, return_value, env, svc_client, AXIS2_FALSE TSRMLS_CC);
}
/* }}} end request */

/* {{{ proto send(string xmlpaylod)
    Sends the given payload in a robust manner.
    Means that SOAP faults are captured and reported.
    */
PHP_METHOD(ws_client , send)
{
    zval *param = NULL;
    ws_object_ptr intern = NULL;
    zval *obj = NULL;
    axis2_svc_client_t *svc_client = NULL;
    if (FAILURE == zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &param))
    {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "Invalid parameters");
        return;
    }
    WSF_OBJ_CHECK(env);
    WSF_GET_THIS(obj);
    WSF_GET_OBJ(svc_client, obj, axis2_svc_client_t, intern);
    wsf_client_do_request(obj, param, return_value, env, svc_client, AXIS2_TRUE TSRMLS_CC);
}
/* }}} end send*/

/* {{{ proto getLastResponse() */
PHP_METHOD(ws_client, get_last_response)
{
    axis2_svc_client_t *svc_client = NULL;
    ws_object_ptr intern = NULL;
    zval *obj = NULL;

    WSF_GET_THIS(obj);
    WSF_GET_OBJ(svc_client, obj, axis2_svc_client_t, intern);
    if(svc_client)
    {
        axis2_op_client_t *op_client = NULL;
        op_client = AXIS2_SVC_CLIENT_GET_OP_CLIENT(svc_client, env);

        if(op_client)
        {
            axis2_char_t *msg = ws_util_get_soap_msg_from_op_client(op_client, env,
                                AXIS2_WSDL_MESSAGE_LABEL_IN);
            if(msg)
            {
                RETURN_STRING(msg, 1);
            }
        }
    }
}
/* }}} */

/* {{{ proto getLastRequest() */
PHP_METHOD(ws_client , get_last_request)
{
    axis2_svc_client_t *svc_client = NULL;
    ws_object_ptr intern = NULL;
    zval *obj = NULL;

    WSF_GET_THIS(obj);
    WSF_GET_OBJ(svc_client, obj, axis2_svc_client_t, intern);
    if(svc_client){
        axis2_op_client_t *op_client = NULL;
        op_client = AXIS2_SVC_CLIENT_GET_OP_CLIENT(svc_client, env);
        if(op_client){
            axis2_char_t *msg = ws_util_get_soap_msg_from_op_client(op_client, env,
                                AXIS2_WSDL_MESSAGE_LABEL_OUT);
            if(msg){
                RETURN_STRING(msg, 1);
            }
        }
    }
}
/* }}} */

/* {{{ proto public WSClient::terminateOutgoingRM() */
PHP_METHOD(ws_client, terminate_outgoing_rm)
{
	zval *object = NULL;
	WSF_GET_THIS(object);
}
/* }}} */


/* {{{ WSClient::__call() */
PHP_METHOD(ws_client, __call)
{
    char *fn_name = NULL;
    long fn_name_len = 0;
    zval *options = NULL;
    zval *args = NULL;
    zval **real_args = NULL;
    zval **param = NULL;
    int arg_count = 0;
    HashPosition pos;
    int i = 0;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sz",
                              &fn_name, &fn_name_len, &args ) == FAILURE)
    {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "Invalid parameters");
        return;
    }
    arg_count = zend_hash_num_elements(Z_ARRVAL_P(args));
    if(arg_count > 0)
    {
        real_args = safe_emalloc(sizeof(zval *), arg_count, 0);
        for (zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(args), &pos);
                zend_hash_get_current_data_ex(Z_ARRVAL_P(args), (void **) &param, &pos) == SUCCESS;
                zend_hash_move_forward_ex(Z_ARRVAL_P(args), &pos))
        {
            if(Z_TYPE_PP(param) == IS_LONG)
            {
                php_printf(" index %d type %d", i, Z_LVAL_PP(param));
            }
            real_args[i++] = *param;
        }
    }
    /*
    do_soap_call(this_ptr, fn_name, fn_name_len, arg_count, real_args, return_value, NULL,
    	NULL, NULL, NULL, NULL TSRMLS_CC);
    */
}
/* }}} end call */
PHP_METHOD(ws_client, get_client)
{
    zval *tmp = NULL;
    zval *client_proxy_zval  =  NULL;
    char *service = NULL;
    int service_len = 0;
    char *port = NULL;
    int port_len =  0;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss", &service, &service_len,
                             &port, &port_len) == FAILURE){
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "Invalid Parameters,specify the service and port");
    }

    ALLOC_ZVAL(client_proxy_zval);
    object_init_ex(client_proxy_zval, ws_client_proxy_class_entry);
    add_property_string(client_proxy_zval, "service", service, 1);
    add_property_string(client_proxy_zval, "port", port, 1);

}

/* {{{ proto void WSService::__construct([ array options])*/
PHP_METHOD(ws_service, __construct)
{
    ws_object_ptr intern = NULL;
    zval *obj = NULL;
    ws_svc_info_t *svc_info = NULL;
    char *svc_name = NULL;
    char *location = NULL;
    int location_len = 0;
    zval *options = NULL;
    axis2_hash_index_t *hi = NULL;

    HashTable *ht_actions = NULL;
    HashTable *ht_ops_to_funcs = NULL;

    if (FAILURE == zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|a",
                                         &options))
    {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "Invalid parameters");
        return;
    }

    WSF_GET_THIS(obj);
    intern = (ws_object* )zend_object_store_get_object(obj TSRMLS_CC);
    svc_info = ws_svc_info_create();
    svc_info->class_info = axis2_hash_make(ws_env_svr);


    svc_info->ops_to_functions = axis2_hash_make(ws_env_svr);
    svc_info->ops_to_actions = axis2_hash_make(ws_env_svr);

    intern->ptr = svc_info;
    svc_info->php_worker = worker;


    if(options)
    {
        zval **tmp = NULL;
        HashTable *ht = Z_ARRVAL_P(options);
        if(ht)
        {
            if(zend_hash_find(ht, "actions", sizeof("actions"),
                              (void **)&tmp) == SUCCESS && Z_TYPE_PP(tmp) == IS_ARRAY) {
                ht_actions = Z_ARRVAL_PP(tmp);
		AXIS2_LOG_DEBUG(ws_env_svr->log, AXIS2_LOG_SI, "[wsf_service] setting actions ");
            }
            if(zend_hash_find(ht, "operations", sizeof("operations"),
                              (void **)&tmp) == SUCCESS && Z_TYPE_PP(tmp) == IS_ARRAY){
                ht_ops_to_funcs = Z_ARRVAL_PP(tmp);
		AXIS2_LOG_DEBUG(ws_env_svr->log, AXIS2_LOG_SI, "[wsf_service] setting operations");
            }
            if(zend_hash_find(ht, WS_USE_MTOM, sizeof(WS_USE_MTOM),
                              (void **)&tmp) == SUCCESS && Z_TYPE_PP(tmp) == IS_BOOL){
                svc_info->use_mtom = Z_BVAL_PP(tmp);
		AXIS2_LOG_DEBUG(ws_env_svr->log, AXIS2_LOG_SI, "[wsf_service] setting mtom property %d", svc_info->use_mtom);
            }
            else{
                svc_info->use_mtom = 0;
            }
            if(zend_hash_find(ht, WS_REQUEST_XOP, sizeof(WS_REQUEST_XOP),
                              (void **)&tmp) == SUCCESS && Z_TYPE_PP(tmp) == IS_BOOL){
                svc_info->request_xop = Z_BVAL_PP(tmp);
            }
            else
            {
                svc_info->request_xop = 0;
            }
	    AXIS2_LOG_DEBUG(ws_env_svr->log, AXIS2_LOG_SI, "[wsf_service] request xop %d", svc_info->request_xop);

            if(zend_hash_find(ht, WS_POLICY_NAME, sizeof(WS_POLICY_NAME),
				    (void **)&tmp) == SUCCESS ){
                svc_info->policy = *tmp;
		AXIS2_LOG_DEBUG(ws_env_svr->log, AXIS2_LOG_SI, "[wsf_service] policy object present");
		
                if(!svc_info->modules_to_engage)
                    svc_info->modules_to_engage = axis2_array_list_create(ws_env_svr, 3);
                axis2_array_list_add(svc_info->modules_to_engage, ws_env_svr, AXIS2_STRDUP("rampart", ws_env_svr));
            }
	    if(zend_hash_find(ht, WS_SECURITY_TOKEN, sizeof(WS_SECURITY_TOKEN), (void**)&tmp) == SUCCESS){
		svc_info->security_token = *tmp;
	    	AXIS2_LOG_DEBUG(ws_env_svr->log, AXIS2_LOG_SI, "[wsf_service] security token object present ");
	    }		
 
            

	    if(zend_hash_find(ht, WS_RELIABLE, sizeof(WS_RELIABLE),
                              (void **)&tmp) == SUCCESS && Z_TYPE_PP(tmp) == IS_BOOL){
                if(!svc_info->modules_to_engage)
                    svc_info->modules_to_engage = axis2_array_list_create(ws_env_svr, 3);
                axis2_array_list_add(svc_info->modules_to_engage, ws_env_svr, AXIS2_STRDUP("sandesha2", ws_env_svr));
            }

            if(zend_hash_find(ht, WS_BINDING_STYLE, sizeof(WS_BINDING_STYLE), (void **)&tmp) == SUCCESS &&
                    Z_TYPE_PP(tmp) == IS_STRING){
                add_property_stringl(obj, WS_BINDING_STYLE, Z_STRVAL_PP(tmp), Z_STRLEN_PP(tmp), 1);
            }
        }
    }
    if(SG(request_info).request_uri){
        svc_info->svc_name = ws_util_generate_svc_name_from_uri(SG(request_info).request_uri, svc_info, ws_env_svr);
        ws_util_create_svc_from_svc_info(svc_info , ws_env_svr TSRMLS_CC);
    }else{
        zend_throw_exception_ex(zend_exception_get_default(TSRMLS_C), 1 TSRMLS_CC,
                                "server does not support cli");
    }

    if (ht_ops_to_funcs){

        HashPosition pos;
        zval **tmp = NULL;
        int i =0;

        zend_hash_internal_pointer_reset_ex(ht_ops_to_funcs , &pos);
        while(zend_hash_get_current_data_ex(ht_ops_to_funcs, (void**)&tmp, &pos) != FAILURE)
        {
            char *op_name_to_store = NULL;
            char *op_name = NULL;
            unsigned int op_name_len = 0;
            unsigned long index = i;


            char *func_name = NULL;
        
            zend_hash_get_current_key_ex(ht_ops_to_funcs, &op_name, &op_name_len, &index, 0, &pos);
            zend_hash_move_forward_ex(ht_ops_to_funcs, &pos);

            i++;
            func_name = Z_STRVAL_PP(tmp);

            if(op_name)
                op_name_to_store = op_name;
            else
                op_name_to_store = func_name;
            axis2_hash_set(svc_info->ops_to_functions, AXIS2_STRDUP(op_name_to_store, ws_env_svr) ,
                           AXIS2_HASH_KEY_STRING,  AXIS2_STRDUP(func_name, ws_env_svr));
        }
    }
    if(ht_actions)
    {
        HashPosition pos;
        zval **tmp_function = NULL;
        zval **zval_tmp = NULL;

        zend_hash_internal_pointer_reset_ex(ht_actions, &pos);
        while (zend_hash_get_current_data_ex(ht_actions, (void **)&tmp_function, &pos) != FAILURE)
        {
            char *func_name = NULL;
            char *key = NULL;
            int   key_len = 0;
            zend_function *f;
            char* wsa_action = NULL;
            uint str_length = 0;
            ulong num_index = 0;
            char *operation_name = NULL;
            operation_name = Z_STRVAL_PP(tmp_function);

            if( zend_hash_get_current_key_ex (ht_actions , &wsa_action, &str_length, &num_index,
                                              AXIS2_TRUE, &pos ) == FAILURE)
            {}

            if (Z_TYPE_PP(tmp_function) != IS_STRING)
            {
                php_error_docref(NULL TSRMLS_CC, E_ERROR, "Tried to add a function that isn't a string");
            }

            func_name = axis2_hash_get(svc_info->ops_to_functions, Z_STRVAL_PP(tmp_function), AXIS2_HASH_KEY_STRING);
            if(!func_name)
            {
                axis2_hash_set(svc_info->ops_to_functions, AXIS2_STRDUP(Z_STRVAL_PP(tmp_function), ws_env_svr),
                               AXIS2_HASH_KEY_STRING, AXIS2_STRDUP(Z_STRVAL_PP(tmp_function), ws_env_svr));
                func_name = Z_STRVAL_PP(tmp_function);
            }
            key_len = strlen(func_name);

            key = emalloc(key_len + 1);
            zend_str_tolower_copy(key, func_name , key_len);

            if (zend_hash_find(EG(function_table), key, key_len+1, (void**)&f) == FAILURE)
            {
                php_error_docref(NULL TSRMLS_CC, E_ERROR, "Named function not in function table");
                continue;
            }

            if (wsa_action)
            {
                ws_util_create_op_and_add_to_svc(svc_info, wsa_action,
                                                 ws_env_svr, operation_name TSRMLS_CC);
                /* keep track of operations with actions */
                axis2_hash_set(svc_info->ops_to_actions, AXIS2_STRDUP(operation_name, ws_env_svr) ,
                               AXIS2_HASH_KEY_STRING,  AXIS2_STRDUP(wsa_action, ws_env_svr));
            }
            else
            {
                ws_util_create_op_and_add_to_svc(svc_info, NULL,
                                                 ws_env_svr, operation_name TSRMLS_CC);
            }
            efree(key);
            zend_hash_move_forward_ex(ht_actions , &pos);
        }
    }

    if(svc_info->ops_to_functions)
    {
        for(hi = axis2_hash_first(svc_info->ops_to_functions, ws_env_svr); hi;
                hi = axis2_hash_next(ws_env_svr, hi))
        {
            void *v = NULL;
            const void *k = NULL;
            char *key = NULL;
            char *val = NULL;
            zend_function *f;
            char *function_name = NULL;
            int key_len = 0;

            axis2_char_t *f_name = NULL;
            axis2_hash_this(hi, &k , NULL, &v);
            key = (axis2_char_t*)k;
            val = (axis2_char_t*)v;

            if (key && val)
            {
                /* check if the function is there */
                key_len = strlen(val);
                function_name = emalloc(key_len + 1);
                zend_str_tolower_copy(function_name, val, key_len);

                if (zend_hash_find(EG(function_table), function_name, key_len + 1, (void**)&f) == FAILURE)
                {
                    php_error_docref(NULL TSRMLS_CC, E_ERROR, "Named function not in function table");
                    continue;
                }

                /* function is there, add the operation to service */
                if (strcmp(key, val) == 0)
                {
                    ws_util_create_op_and_add_to_svc(svc_info, NULL, ws_env_svr, key TSRMLS_CC);
                }
                else
                {
                    char *action_for_op = NULL;
                    action_for_op = axis2_hash_get(svc_info->ops_to_actions,
                                                   key, AXIS2_HASH_KEY_STRING);
                    if (!action_for_op)
                    {
                        /* There was no mapping WSA action for this operation.
                           So this operation was not yet added, hence add. */
                        ws_util_create_op_and_add_to_svc(svc_info, NULL, ws_env_svr, key TSRMLS_CC);
                    }
                }
            }
        }
    }
}
/* }}} */

/* {{{ proto void WSService::__destruct()
   */
PHP_METHOD(ws_service, __destruct)
{}
/* } }} end WSService::__destruct */

/* {{{ proto long setClass(string classname) Set a class to the service */
PHP_METHOD(ws_service , set_class)
{
    /*
    #ifdef ZEND_ENGINE_2		
    	zend_class_entry **ce;
    #else
    	zend_class_entry *ce;
    	
    #endif
    	
    	ws_object_ptr intern = NULL;
    	zval *obj = NULL;
    	ws_svc_info_t *svc_info = NULL;	
    	
    	int found, argc;
    	zval ***argv;
     
    	WSF_GET_THIS(obj);
    	
    	intern = (ws_object*)zend_object_store_get_object(obj TSRMLS_CC);
    	svc_info = (ws_svc_info_t*)(intern->ptr);
     
    	argc = ZEND_NUM_ARGS();
    	argv = safe_emalloc(argc, sizeof(zval **), 0);
     
    	if (argc < 1 || zend_get_parameters_array_ex(argc, argv) == FAILURE) {
    		efree(argv);
    		WRONG_PARAM_COUNT;
    	}
     
    	if (Z_TYPE_PP(argv[0]) == IS_STRING) {
    #ifdef ZEND_ENGINE_2		
    		found = zend_lookup_class(Z_STRVAL_PP(argv[0]), Z_STRLEN_PP(argv[0]), &ce TSRMLS_CC);
    #else
    		char *class_name = estrdup(Z_STRVAL_PP(argv[0]));
    		found = zend_hash_find(EG(class_table), php_strtolower(class_name, Z_STRLEN_PP(argv[0])), Z_STRLEN_PP(argv[0])	 + 1, (void **)&ce);
    		efree(class_name);
    #endif
    		if (found != FAILURE) {
    		zend_function *f;
    		HashTable *ft = NULL;
    		HashPosition pos;
    		
    #ifdef 	ZEND_ENGINE_2
    		ft = &(*ce)->function_table;
    #else
    		ft = &(ce->function_table);
    #endif
    		zend_hash_internal_pointer_reset_ex(ft, &pos);
    		while (zend_hash_get_current_data_ex(ft, (void **)&f, &pos) != FAILURE) {
    				if (f->common.fn_flags & ZEND_ACC_PUBLIC) {
    					svc_info->is_class = 1;
                        axis2_hash_set(svc_info->class_info, AXIS2_STRDUP(f->common.function_name ,env),
                            AXIS2_HASH_KEY_STRING, AXIS2_STRDUP(Z_STRVAL_PP(argv[0]), env));
    					
    					ws_util_create_op_and_add_to_svc(svc_info, NULL, 
    					        env ,f->common.function_name TSRMLS_CC);
    				}
    				zend_hash_move_forward_ex(ft, &pos);
    			}		
    		} else {
    			php_error_docref(NULL TSRMLS_CC, E_ERROR, "Tried to set a non existant class (%s)", Z_STRVAL_PP(argv[0]));
    			return;				
    		}
    	} else {
    		php_error_docref(NULL TSRMLS_CC, E_ERROR, "You must pass in a string");
    		return;
    	}
    	efree(argv);
    */
}
/* }}} end setClass */

/* {{{ proto long reply([long style]) reply the SOAP request */
PHP_METHOD(ws_service , reply)
{
    ws_object_ptr intern = NULL;
    zval *obj = NULL;
    axis2_char_t *svc_name = NULL;
    axis2_conf_t *conf = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;
    ws_svc_info_t *svc_info = NULL;
    wsf_req_info_t *req_info = NULL;
    zval **server_vars, **data;
    wsf_worker_t *php_worker = NULL;
    zval **raw_post;
    int status = 0;
    char *response_str = NULL;
    char content_length[40];
    int soap_version =0;
    char status_line[100];
    char *content_type = NULL;

    WSF_GET_THIS(obj);
    intern = (ws_object*)zend_object_store_get_object(obj TSRMLS_CC);
    svc_info = (ws_svc_info_t *)(intern->ptr);

    php_worker = svc_info->php_worker;
    conf_ctx = wsf_worker_get_conf_ctx(php_worker, ws_env_svr);
    if(!conf_ctx)
    {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "conf ctx missing");
        return;
    }
    zend_is_auto_global("_SERVER", sizeof("_SERVER")-1 TSRMLS_CC);
    req_info = wsf_php_req_info_create();

    if (zend_hash_find(&EG(symbol_table), "_SERVER", sizeof("_SERVER"), (void **) &server_vars) == SUCCESS &&
            (Z_TYPE_PP(server_vars) == IS_ARRAY))
    {

        if ((zend_hash_find(Z_ARRVAL_PP(server_vars), "HTTP_CONTENT_ENCODING",
                            sizeof("HTTP_CONTENT_ENCODING"), (void **)&data) == SUCCESS)
                &&  Z_TYPE_PP(data) == IS_STRING)
        {
            req_info->content_encoding = Z_STRVAL_PP(data);
        }

        if ((zend_hash_find(Z_ARRVAL_PP(server_vars), "HTTP_TRANSFER_ENCODING",
                            sizeof("HTTP_TRANSFER_ENCODING"), (void **)&data) == SUCCESS)
                &&  Z_TYPE_PP(data) == IS_STRING)
        {
            req_info->transfer_encoding = Z_STRVAL_PP(data);
        }

        if ((zend_hash_find(Z_ARRVAL_PP(server_vars), "SERVER_NAME",
                            sizeof("SERVER_NAME"), (void **)&data) == SUCCESS)
                &&  Z_TYPE_PP(data) == IS_STRING)
        {
            req_info->svr_name = Z_STRVAL_PP(data);
        }
        if ((zend_hash_find(Z_ARRVAL_PP(server_vars), "SERVER_PORT",
                            sizeof("SERVER_PORT"), (void **)&data) == SUCCESS)
                &&  Z_TYPE_PP(data) == IS_STRING)
        {
            char *p = NULL;
            p = Z_STRVAL_PP(data);
            req_info->svr_port = atoi(p);
        }
        if ((zend_hash_find(Z_ARRVAL_PP(server_vars), "SERVER_PROTOCOL",
                            sizeof("SERVER_PROTOCOL"), (void **)&data) == SUCCESS)
                &&  Z_TYPE_PP(data) == IS_STRING)
        {
            req_info->http_protocol = Z_STRVAL_PP(data);
        }
        if ((zend_hash_find(Z_ARRVAL_PP(server_vars), "SOAP_ACTION",
                            sizeof("SOAP_ACTION"), (void **)&data) == SUCCESS)
                &&  Z_TYPE_PP(data) == IS_STRING)
        {
            req_info->soap_action = Z_STRVAL_PP(data);

        }
        if((zend_hash_find(Z_ARRVAL_PP(server_vars), "SCRIPT_FILENAME",
                           sizeof("SCRIPT_FILENAME"), (void **)&data) == SUCCESS)
                &&  Z_TYPE_PP(data) == IS_STRING)
        {
            svc_info->svc_path = Z_STRVAL_PP(data);
        }
    }

    req_info->request_uri = SG(request_info).request_uri;
    req_info->content_length = SG(request_info).content_length;
    req_info->content_type = (char*)SG(request_info).content_type;
    req_info->request_method = (char*)SG(request_info).request_method;
    req_info->query_string = (char*)SG(request_info).query_string;
	


    if (zend_hash_find(&EG(symbol_table), "HTTP_RAW_POST_DATA", sizeof("HTTP_RAW_POST_DATA"), (void **) &raw_post)!=FAILURE
            && ((*raw_post)->type==IS_STRING))
    {
        req_info->req_data = Z_STRVAL_PP(raw_post);
        req_info->req_data_length = Z_STRLEN_PP(raw_post);
    }
    
    /** begin Wsdl Generation */
    if(SG(request_info).query_string && ((stricmp(SG(request_info).query_string, "wsdl") == 0) ||
                                         (stricmp(SG(request_info).query_string, "wsdl2") == 0 )))
    {

        char *service_name = NULL;
        zval func, retval, param1, param2, param3, param4, param5, param6;
        zval *params[6];
        axis2_hash_index_t *hi = NULL;
        zval *f_val;
        zend_file_handle script;
        char *val = NULL;
        int len = 0;
        zval **tmpval;
        char *binding_name = NULL;
        char *wsdl_version = NULL;
        char *cwd = emalloc(100);
        char *full_path = emalloc(100);

        /* 	full_path = SG(request_info).http */
        service_name = svc_info->svc_name;
        strcpy(full_path, req_info->svr_name);
        strcat(full_path, req_info->request_uri);

        params[0] = &param1;
        params[1] = &param2;
        params[2] = &param3;
        params[3] = &param4;
        params[4] = &param5;
        params[5] = &param6;
        /** for Wsdl version. default is wsdl 1.1*/
        if((stricmp(SG(request_info).query_string, "wsdl")) == 0 )
            wsdl_version = strdup("wsdl1.1");
        else
            wsdl_version = strdup("wsdl2.0");

        /** getting the correct binding style */
        if ((zend_hash_find(Z_OBJPROP_P(obj), WS_BINDING_STYLE, sizeof(WS_BINDING_STYLE),
                            (void**)&tmpval)) == SUCCESS && Z_TYPE_PP(tmpval) == IS_STRING)
        {
            binding_name = Z_STRVAL_PP(tmpval);

        }

        else
        {
            binding_name = estrdup("doc-lit");
        }

        /** find the functions in the service.php file */
        MAKE_STD_ZVAL(f_val);
        array_init(f_val);

        if (svc_info->ops_to_functions)
        {
            for(hi = axis2_hash_first(svc_info->ops_to_functions, ws_env_svr);
                    hi; hi = axis2_hash_next(ws_env_svr, hi))
            {
                void *v = NULL;
                const void *k = NULL;

                char *function_name = NULL;
                int key_len = 0;

                axis2_char_t *f_key = NULL;
                axis2_char_t *f_name = NULL;
                axis2_hash_this(hi, &k, NULL, &v);
                f_key = (axis2_char_t *)k;
                f_name = (axis2_char_t *)v;
                add_next_index_string(f_val, (char *)f_name, 1);
            }
        }
        ZVAL_STRING(&func, "ws_generate_wsdl", 1);
        ZVAL_STRING(params[0], "scripts/wsdl/WS_WSDL_Creator.php", 1);
        ZVAL_STRING(params[1], service_name, 1);
        ZVAL_ZVAL(params[2], f_val, NULL, NULL);
        INIT_PZVAL(params[2]);
        ZVAL_STRING(params[3], binding_name, 1);
        ZVAL_STRING(params[4], wsdl_version, 1);
        ZVAL_STRING(params[5], full_path, 1);

        script.type = ZEND_HANDLE_FP;
        script.filename = "scripts/wsf.php";
        script.opened_path = NULL;
        script.free_filename = 0;

        if (!(script.handle.fp = VCWD_FOPEN(script.filename, "rb")))
        {
            php_printf("Unable to open script file or file not found:");
        }
        else
        {
            php_execute_script(&script TSRMLS_CC);
            if (call_user_function(CG(function_table), (zval**)NULL,
                                   &func, &retval, 6, params TSRMLS_CC ) == SUCCESS)
            {
                if (Z_TYPE_P(&retval) == IS_STRING && Z_TYPE_P(&retval) != IS_NULL)
                {
                    val = estrdup(Z_STRVAL(retval));
                    len = Z_STRLEN(retval);
                    sapi_add_header("Content-Type:application/xml", sizeof("Content-Type:application/xml"),1);
                    php_write(val, len TSRMLS_CC);
                }

                else
                    php_printf("A problem occured");
            }

        }
        /** end Wsdl generation stuff */
    }
    else
    {

        conf = AXIS2_CONF_CTX_GET_CONF(conf_ctx, ws_env_svr);
        if(!AXIS2_CONF_GET_SVC(conf, ws_env_svr, svc_info->svc_name))
        {
            AXIS2_CONF_ADD_SVC(conf, ws_env_svr, svc_info->svc);
            if(NULL != svc_info->modules_to_engage)
            {
                int i = 0;
                int size = axis2_array_list_size(svc_info->modules_to_engage, ws_env_svr);
                for(i = 0; i < size; i++)
                {
                    axis2_char_t *mod_name = (axis2_char_t *)axis2_array_list_get(svc_info->modules_to_engage,
                                             ws_env_svr, i);

                    ws_util_engage_module(conf, mod_name, ws_env_svr, svc_info->svc);
                }
            }
        }
        status = wsf_worker_process_request(php_worker, ws_env_svr, req_info, svc_info);
        if(status == WS_HTTP_ACCEPTED)
        {
            sprintf(status_line, "%s 202 Accepted", req_info->http_protocol);
            sapi_add_header(status_line, strlen(status_line), 1);
            sapi_add_header("Content-Length: 0",sizeof("Content-Length: 0")-1, 1);
        }
        else if(status == WS_HTTP_OK)
        {
            sprintf(status_line, "%s 200 OK", req_info->http_protocol);
            sapi_add_header(status_line,strlen(status_line), 1);

            sprintf(content_length,"Content-Length %d", req_info->content_length);
            content_type = AXIS2_MALLOC(ws_env_svr->allocator, strlen(req_info->content_type)*sizeof(char)+20);
            sprintf(content_type, "Content-Type: %s", req_info->content_type);
            sapi_add_header(content_type, strlen(content_type), 1);
            php_write(req_info->result_payload, req_info->result_length TSRMLS_CC);
        }
        else if(status == WS_HTTP_INTERNAL_SERVER_ERROR)
        {
            sprintf(status_line, "%s 500 Internal Server Error", req_info->http_protocol);
            sapi_add_header(status_line,strlen(status_line), 1);
            if(req_info->content_type)
            {
                content_type = AXIS2_MALLOC(ws_env_svr->allocator, strlen(req_info->content_type)*sizeof(char)+20);
                sprintf(content_type, "Content-Type: %s", req_info->content_type);
                if(content_type)
                {
                    sapi_add_header(content_type, strlen(content_type), 1);
                    php_write(req_info->result_payload, req_info->result_length TSRMLS_CC);
                }
            }
        }
    }
}
/* }}} end reply */

/************************* fault *********************************/
/* {{{ proto void WSFault(mixed fcode, mixed freason,mixed frole, mixed detail) */


PHP_METHOD(ws_fault, __construct)
{
    zval *value = NULL;
    char *name = NULL;
    char *sf_code      = NULL;
    long sf_code_len   = 0;
    char *sf_reason    = NULL;
    long sf_reason_len = 0;
    char *sf_role      = NULL;
    long sf_role_len   = 0;
    char *sf_detail    = NULL;
    long sf_detail_len = 0;

    if (FAILURE == zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss|ss", &sf_code,
                                         &sf_code_len, &sf_reason, &sf_reason_len ,&sf_role,
                                         &sf_role_len ,&sf_detail,&sf_detail_len))
    {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "Invalid Paramters");
        return;
    }

    if(!sf_code || !sf_reason)
    {
        if(WSF_GLOBAL(soap_version) == AXIOM_SOAP11)
        {
            php_error_docref(NULL TSRMLS_CC, E_ERROR, "faultcode and faultstring are mandatory ");
            return;
        }
        else if(WSF_GLOBAL(soap_version) == AXIOM_SOAP12)
        {
            php_error_docref(NULL TSRMLS_CC, E_ERROR, "Code and Reason are mandatory ");
        }
    }
    add_property_string(this_ptr, WS_FAULT_CODE, sf_code, 1);
    add_property_string(this_ptr, WS_FAULT_REASON, sf_reason, 1);
    if(sf_role)
        add_property_string(this_ptr, WS_FAULT_ROLE, sf_role, 1);
    if(sf_detail)
        add_property_string(this_ptr, WS_FAULT_DETAIL, sf_detail, 1);
}
/* }}} */

/* {{{ proto */
PHP_METHOD(ws_fault, __destruct)
{}
/* }}} */
PHP_METHOD(ws_fault, ws_fault_add_fault_header)
{}
PHP_METHOD(ws_fault, ws_fault_get_fault_headers)
{}
/* {{{ proto WSFault::getSoapFaultText [void ] */
PHP_METHOD(ws_fault , get_soap_fault_text)
{
    zval **tmp;
    if (zend_hash_find(Z_OBJPROP_P(this_ptr), WS_FAULT_REASON, sizeof(WS_FAULT_REASON), (void **)&tmp) != SUCCESS)
    {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, " Invalid fault");
        RETURN_NULL();
    }
    if(Z_TYPE_PP(tmp) == IS_STRING)
    {
        RETURN_STRINGL(Z_STRVAL_PP(tmp), Z_STRLEN_PP(tmp), 1);
    }
    else if(Z_TYPE_PP(tmp) == IS_ARRAY)
    {}
    RETURN_NULL();
}
/* }}} */

/* {{{ */
PHP_METHOD(ws_fault ,ws_fault_get_fault_code_value)
{
    zval **tmp;
    if (zend_hash_find(Z_OBJPROP_P(this_ptr), WS_FAULT_CODE, sizeof(WS_FAULT_CODE), (void **)&tmp) != SUCCESS)
    {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, " Invalid fault");
        RETURN_NULL();
    }
    if(Z_TYPE_PP(tmp) == IS_STRING)
    {
        RETURN_STRINGL(Z_STRVAL_PP(tmp), Z_STRLEN_PP(tmp), 1);
    }
    else if(Z_TYPE_PP(tmp) == IS_ARRAY)
    {
        zval **zval_tmp;
        HashTable *ht = Z_ARRVAL_PP(tmp);
        if(zend_hash_find(ht, "value", sizeof("value"), (void **)&zval_tmp) == SUCCESS &&
                Z_TYPE_PP(zval_tmp) == IS_STRING)
        {
            RETURN_STRINGL(Z_STRVAL_PP(zval_tmp), Z_STRLEN_PP(zval_tmp), 1);
        }
    }
    RETURN_NULL();
}
/* }}} */

PHP_METHOD(ws_fault ,ws_fault_get_fault_code_subcode_value)
{
    zval **tmp;
    if (zend_hash_find(Z_OBJPROP_P(this_ptr), WS_FAULT_CODE, sizeof(WS_FAULT_CODE), (void **)&tmp) != SUCCESS)
    {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, " Invalid fault");
        RETURN_NULL();
    }
    if(Z_TYPE_PP(tmp) == IS_STRING)
    {
        RETURN_STRINGL(Z_STRVAL_PP(tmp), Z_STRLEN_PP(tmp), 1);
    }
    else if(Z_TYPE_PP(tmp) == IS_ARRAY)
    {
        zval **zval_tmp;
        HashTable *ht = Z_ARRVAL_PP(tmp);
        if(zend_hash_find(ht, WS_FAULT_SUBCODE, sizeof(WS_FAULT_SUBCODE), (void **)&zval_tmp) == SUCCESS &&
                Z_TYPE_PP(zval_tmp) == IS_STRING)
        {
            RETURN_STRINGL(Z_STRVAL_PP(zval_tmp), Z_STRLEN_PP(zval_tmp), 1);
        }
    }
    RETURN_NULL();
}

PHP_METHOD(ws_fault, __get)
{}

PHP_METHOD(ws_header, __construct)
{
    zval *data = NULL, *role = NULL;
    char *name, *ns;
    int name_len, ns_len;
    zend_bool must_understand = 0;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss|zbz",
                              &ns, &ns_len, &name, &name_len, &data, &must_understand, &role) == FAILURE)
    {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "Invalid parameters");
    }
    if (ns_len == 0)
    {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "Invalid parameters. Invalid namespace.");
    }
    if (name_len == 0)
    {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "Invalid parameters. Invalid header name.");
    }

    add_property_stringl(this_ptr, WS_HEADER_NS, ns, ns_len, 1);
    add_property_stringl(this_ptr, WS_HEADER_LOCALNAME, name, name_len, 1);
    if (data)
    {
#ifndef ZEND_ENGINE_2
        zval_add_ref(&data);
#endif
        add_property_zval(this_ptr, WS_HEADER_DATA, data);
    }
    if(must_understand)
    {
        add_property_bool(this_ptr, WS_HEADER_MUST_UNDERSTAND, must_understand);
    }
    if(role)
    {
        if(Z_TYPE_P(role) == IS_LONG &&
                (Z_LVAL_P(role) == WS_SOAP_ROLE_NEXT ||
                 Z_LVAL_P(role) == WS_SOAP_ROLE_NONE ||
                 Z_LVAL_P(role) == WS_SOAP_ROLE_ULTIMATE_RECEIVER))
        {
            add_property_long(this_ptr, WS_HEADER_ROLE, Z_LVAL_P(role));
        }
        else if (Z_TYPE_P(role) == IS_STRING && Z_STRLEN_P(role) > 0)
        {
            add_property_stringl(this_ptr, WS_HEADER_ROLE, Z_STRVAL_P(role), Z_STRLEN_P(role), 1);
        }
        else
        {
            php_error_docref(NULL TSRMLS_CC, E_ERROR, "Invalid parameters. Invalid role.");
        }
    }
}

/* {{{ WSSecurityToken::__construct( */
PHP_METHOD(ws_security_token, __construct)
{
    zval *object = NULL;
    zval *options = NULL;
    zval **tmp = NULL;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "a", &options) == FAILURE)
    {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "An array should be passed here");
    }

    WSF_GET_THIS(object);

    if(options)
    {
        HashTable *ht = Z_ARRVAL_P(options);
        if(zend_hash_find(ht, WS_USER, sizeof(WS_USER), (void **)&tmp) == SUCCESS &&
                Z_TYPE_PP(tmp) == IS_STRING)
        {
            add_property_stringl(object, WS_USER, Z_STRVAL_PP(tmp), Z_STRLEN_PP(tmp), 1);
        }
        if(zend_hash_find(ht, WS_PUBLICKEY, sizeof(WS_PUBLICKEY), (void **)&tmp) == SUCCESS &&
                Z_TYPE_PP(tmp) == IS_STRING)
        {
            add_property_stringl(object, WS_PUBLICKEY, Z_STRVAL_PP(tmp), Z_STRLEN_PP(tmp), 1);
        }
        if(zend_hash_find(ht, WS_PASSWORD_TYPE , sizeof(WS_PASSWORD_TYPE), (void **)&tmp) == SUCCESS &&
                Z_TYPE_PP(tmp) == IS_STRING)
        {
            add_property_stringl(object, WS_PASSWORD_TYPE, Z_STRVAL_PP(tmp), Z_STRLEN_PP(tmp), 1);
        }
        if(zend_hash_find(ht, WS_PASSWORD, sizeof(WS_PASSWORD), (void **)&tmp) == SUCCESS &&
                Z_TYPE_PP(tmp) == IS_STRING)
        {
            add_property_string(object, WS_PASSWORD, Z_STRVAL_PP(tmp), 1);
        }
        if(zend_hash_find(ht, WS_PRIVATE_KEY, sizeof(WS_PRIVATE_KEY), (void **)&tmp) == SUCCESS &&
                Z_TYPE_PP(tmp) == IS_STRING)
        {
            add_property_string(object, WS_PRIVATE_KEY, Z_STRVAL_PP(tmp), 1);
        }
	if(zend_hash_find(ht, WS_TTL, sizeof(WS_TTL), (void **)&tmp) == SUCCESS &&
	   Z_TYPE_PP(tmp) == IS_LONG)
	{
	    add_property_long(object, WS_TTL, Z_LVAL_PP(tmp));
	}
    }
}

/* }}} */



/* {{{ WSPolicy::__construct( */
PHP_METHOD(ws_policy, __construct)
{
    zval *object = NULL;
    zval *payload = NULL;
    zval *properties = NULL;

    if (FAILURE == zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z|a",
                                         &properties))
    {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "Invalid parameters");
        return;
    }

    WSF_GET_THIS(object);
    WSF_OBJ_CHECK(env);

    /* if the wspolicy object ( option array is presence */

    if( NULL != properties && Z_TYPE_P(properties) == IS_ARRAY)
    {
        HashTable *ht = Z_ARRVAL_P(properties);
        axiom_node_t *policy_root_node = NULL;
        axis2_char_t *om_str = NULL;
        FILE *fp = NULL;

	if(ht)
	{
		ws_policy_set_policy_options(object, ht, env TSRMLS_CC);

        }
        else
            php_printf("\n The variable is of type %d", Z_TYPE_P(properties));

    }
}

/* }}} */

/* {{{ proto string file_get_contents(string filename)
    read a pem file and return the key portion of the file as a string */
PHP_FUNCTION(ws_get_key_from_file)
{
	char *filename;
	int filename_len;
	char *contents;
	php_stream *stream;
	int len, newlen;
	long offset = -1;
	long maxlen = PHP_STREAM_COPY_ALL;
	zval *zcontext = NULL;
	php_stream_context *context = NULL;
	char *DELIMITER = "-----";
	/* Parse arguments */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s",
				  &filename, &filename_len) == FAILURE) {
		return;
	}

	context = php_stream_context_from_zval(zcontext, 0);

	stream = php_stream_open_wrapper_ex(filename, "rb", 
				(USE_PATH ) | ENFORCE_SAFE_MODE | REPORT_ERRORS,
				NULL, context);
	if (!stream) {
		RETURN_FALSE;
	}

	if ((len = php_stream_copy_to_mem(stream, &contents, maxlen, 0)) > 0) {
		char *key = NULL;
		char *start_index = NULL;
		char *end_index = NULL;
		char *tmp_index = NULL;
		char *key_len = 0;			
		tmp_index = strstr(contents, DELIMITER);
		if(!tmp_index)
			return;
		if(len > (tmp_index - contents))
		{
			tmp_index += 5; 
			tmp_index = strstr(tmp_index, DELIMITER);	
			if(!tmp_index)
				return;
			start_index = tmp_index+6;
			tmp_index[contents - tmp_index] = '\0';
		}
		
		tmp_index = strstr(start_index, DELIMITER);
		if(!tmp_index)
			return;
		tmp_index = tmp_index +1;
		key_len = tmp_index - start_index;

		start_index[tmp_index - start_index] = '\0';
				
		key = estrdup(start_index);
		
		efree(contents);

		RETVAL_STRINGL(key,strlen(key), 0);
	} else if (len == 0) {
		RETVAL_EMPTY_STRING();
	} else {
		RETVAL_FALSE;
	}
	php_stream_close(stream);
}
/* }}} */


PHP_FUNCTION(ws_test_function)
{
	char *function_name, *data = NULL;
	int function_name_length = 0;
	int data_length = 0;
	
	zval *params[1];
	zval param, ret_val, func;

	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss",
		&function_name, &function_name_length, &data, &data_length) != SUCCESS){
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Invalid parameters");
        return;
	}
	ZVAL_STRING(&func, function_name, 0);
	params[0] = &param;
	ZVAL_STRING(params[0], data, 1);
	INIT_PZVAL(params[0]);
	if(call_user_function(EG(function_table) , (zval **)NULL, &func, &ret_val,1, params TSRMLS_CC) == SUCCESS)
	{
		php_printf("done ");		
	}
}



