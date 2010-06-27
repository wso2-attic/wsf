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

#ifndef WSF_H
#define WSF_H


#ifdef PHP_WIN32
#define WSF_PHP_API __declspec(dllexport)
#else
#define WSF_PHP_API
#endif

#include "php.h"
#include "php_globals.h"

#include "ext/standard/info.h"
#include "ext/standard/php_standard.h"
#include "ext/standard/php_smart_str.h"

#include "php_ini.h"
#include "SAPI.h"
#include "wsf_worker.h"

#ifndef PHP_WIN32
#define TRUE 1
#define FALSE 0
#define stricmp strcasecmp
#define WSF_TMP "/tmp"
#else
#define WSF_TMP "C:\\Windows\\temp"
#endif



#ifdef ZTS
#include "TSRM.h"
#endif

#include <axiom.h>
#include <axis2_svc_client.h>
#include <axiom_soap.h>
#include <axis2_http_transport.h>
#include <axis2_addr.h>
#include <axiom_util.h>
#include "zend_exceptions.h"

PHP_MINIT_FUNCTION (wsf);
PHP_MSHUTDOWN_FUNCTION (wsf);
PHP_RINIT_FUNCTION (wsf);
PHP_RSHUTDOWN_FUNCTION (wsf);
PHP_MINFO_FUNCTION (wsf);

typedef struct _ws_object
{
    zend_object std;
    void *ptr;
    int obj_type;
} ws_object;

typedef ws_object *ws_object_ptr;

/* class entries */

extern zend_module_entry wsf_module_entry;
#define phpext_wsf_ptr &wsf_module_entry


extern zend_class_entry *ws_client_class_entry;
extern zend_class_entry *ws_service_class_entry;
extern zend_class_entry *ws_header_class_entry;
extern zend_class_entry *ws_param_class_entry;
extern zend_class_entry *ws_fault_class_entry;
extern zend_class_entry *ws_message_class_entry;
extern zend_class_entry *ws_var_class_entry;
extern zend_class_entry *ws_client_proxy_class_entry;
extern zend_class_entry *ws_security_token_class_entry;
extern zend_class_entry *ws_policy_class_entry;
extern zend_class_entry *ws_data_class_entry;

extern wsf_worker_t *worker;

ZEND_BEGIN_MODULE_GLOBALS (wsf)
    char *home;
    char *log_path;
	int log_level;
    char *soap_uri;
    char *rm_db_dir;
    int curr_ns_index;
    int soap_version;
	char *attachment_cache_dir;
	int enable_attachment_caching;
ZEND_END_MODULE_GLOBALS (wsf)

ZEND_EXTERN_MODULE_GLOBALS (wsf)
#ifdef ZTS
#define WSF_GLOBAL(v) TSRMG(wsf_globals_id, zend_wsf_globals *, v)
#else
#define WSF_GLOBAL(v) (wsf_globals.v)
#endif

#ifdef ZEND_ENGINE_2
#define AXIS2_CTOR(class_name, func_name, arginfo, flags) \
            ZEND_FENTRY(__construct, ZEND_FN(class_name##_##func_name), \
			arginfo, flags)
#else
#define AXIS2_CTOR(class_name, func_name, arginfo, flags) \
            PHP_ME(class_name, func_name, arginfo, flags)
#endif
#define REGISTER_WSF_CLASS(ce, name, parent_ce, funcs, entry) \
INIT_CLASS_ENTRY(ce, name, funcs); \
ce.create_object = php_ws_object_new; \
entry = zend_register_internal_class_ex(&ce, parent_ce, NULL TSRMLS_CC);
#define WSF_GET_OBJ(__ptr, __id, __ptr_type, __intern) \
        { \
            __intern = (ws_object *)zend_object_store_get_object(__id TSRMLS_CC); \
            if((__intern->ptr)) \
            { \
                __ptr = (__ptr_type *)(__intern->ptr); \
            } \
        }
#define WSF_GET_THIS(zval) \
        if(NULL == (zval = getThis())) \
        { \
            php_error_docref(NULL TSRMLS_CC, E_WARNING, "object missing ");  \
            RETURN_FALSE; \
        }
#define WSF_OBJ_CHECK(obj) \
        if(!obj) \
        { \
            php_error_docref(NULL TSRMLS_CC, E_ERROR, "wsf error, obj null"); \
            return; \
        }
#define WSF_HASH_FIND(__ht, __key, __tmp, __status) \
	(zend_hash_find(__ht, __key, sizeof(__key), (void**)&__tmp) == __status)

#endif /* WSF_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
