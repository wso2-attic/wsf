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
# define TRUE 1
# define FALSE 0
# define stricmp strcasecmp
#endif


#ifdef ZTS
#include "TSRM.h"
#endif
#if PHP_LIBXML
#include <libxml/parser.h>
#include <libxml/parserInternals.h>
#include <libxml/tree.h>
#include <libxml/uri.h>
#include <libxml/xmlerror.h>
#include <libxml/xmlsave.h>
#include <libxml/xpath.h>
#endif
#include "ext/libxml/php_libxml.h"
#include "ext/dom/xml_common.h"
#include <axiom.h>


PHP_MINIT_FUNCTION(wsf);
PHP_MSHUTDOWN_FUNCTION(wsf);
PHP_RINIT_FUNCTION(wsf);
PHP_RSHUTDOWN_FUNCTION(wsf);
PHP_MINFO_FUNCTION(wsf);

PHP_FUNCTION(is_ws_fault);
PHP_FUNCTION(ws_test_function);


typedef struct _ws_object{
    zend_object std;
    void *ptr;
    int obj_type;
}ws_object;

typedef ws_object* ws_object_ptr;

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

extern wsf_worker_t* worker;

/************* ext soap stuff ***************************/

extern int le_url;

typedef struct _encodeType encodeType, *encodeTypePtr;
typedef struct _encode encode, *encodePtr;

typedef struct _sdl sdl, *sdlPtr;
typedef struct _sdlRestrictionInt sdlRestrictionInt, *sdlRestrictionIntPtr;
typedef struct _sdlRestrictionChar sdlRestrictionChar, *sdlRestrictionCharPtr;
typedef struct _sdlRestrictions sdlRestrictions, *sdlRestrictionsPtr;
typedef struct _sdlType sdlType, *sdlTypePtr;
typedef struct _sdlParam sdlParam, *sdlParamPtr;
typedef struct _sdlFunction sdlFunction, *sdlFunctionPtr;
typedef struct _sdlAttribute sdlAttribute, *sdlAttributePtr;
typedef struct _sdlBinding sdlBinding, *sdlBindingPtr;
typedef struct _sdlSoapBinding sdlSoapBinding, *sdlSoapBindingPtr;
typedef struct _sdlSoapBindingFunction sdlSoapBindingFunction, *sdlSoapBindingFunctionPtr;
typedef struct _sdlSoapBindingFunctionBody sdlSoapBindingFunctionBody, *sdlSoapBindingFunctionBodyPtr;

typedef struct _soapMapping soapMapping, *soapMappingPtr;
typedef struct _soapService soapService, *soapServicePtr;

#include "php_xml.h"
#include "php_encoding.h"
#include "php_sdl.h"
#include "php_schema.h"
#include "php_http.h"

struct _soapMapping {
	zval *to_xml;
	zval *to_zval;
};

struct _soapHeader;

struct _soapService {
	sdlPtr sdl;

	struct _soap_functions {
		HashTable *ft;
		int functions_all;
	} soap_functions;

	struct _soap_class {
		zend_class_entry *ce;
		zval **argv;
		int argc;
		int persistance;
	} soap_class;

	zval *soap_object;

	HashTable *typemap;
	int        version;
	int        type;
	char      *actor;
	char      *uri;
	xmlCharEncodingHandlerPtr encoding;
	HashTable *class_map;
	int        features;
	struct _soapHeader **soap_headers_ptr;
};

/************* end ext soap stuff ***********************/

ZEND_BEGIN_MODULE_GLOBALS(wsf)
	long  enable_trace;
	char *passwd_location;
	int soap_version_num;
	char *home;
	long enable_exception;
	char *log_path;
	char *soap_uri;
	char *rm_db_dir;
	int curr_ns_index;

	/*** ext soap **/

	HashTable  defEncNs;     /* mapping of default namespaces to prefixes */
	HashTable  defEnc;
	HashTable  defEncIndex;
	HashTable *typemap;
	int        cur_uniq_ns;
	int        soap_version;
	sdlPtr     sdl;
	zend_bool  use_soap_error_handler;
	char*      error_code;
	zval*      error_object;
	long       cache;
	char*      cache_dir;
	long       cache_ttl;
	long       cache_limit;
	HashTable *mem_cache;
	xmlCharEncodingHandlerPtr encoding;
	HashTable *class_map;
	int        features;
	HashTable  wsdl_cache;

ZEND_END_MODULE_GLOBALS(wsf)

ZEND_EXTERN_MODULE_GLOBALS(wsf)

#ifdef ZTS
#define WSF_GLOBAL(v) TSRMG(wsf_globals_id, zend_wsf_globals *, v)
#else
#define WSF_GLOBAL(v) (wsf_globals.v)
#endif

/** ext soap defined constants **/

#define SOAP_CLASS 1
#define SOAP_FUNCTIONS 2
#define SOAP_OBJECT 3
#define SOAP_FUNCTIONS_ALL 999

#define SOAP_MAP_FUNCTION 1
#define SOAP_MAP_CLASS 2

#define SOAP_PERSISTENCE_SESSION 1
#define SOAP_PERSISTENCE_REQUEST 2

#define SOAP_1_1 1
#define SOAP_1_2 2

#define SOAP_ACTOR_NEXT             1
#define SOAP_ACTOR_NONE             2
#define SOAP_ACTOR_UNLIMATERECEIVER 3

#define SOAP_1_1_ACTOR_NEXT             "http://schemas.xmlsoap.org/soap/actor/next"

#define SOAP_1_2_ACTOR_NEXT             "http://www.w3.org/2003/05/soap-envelope/role/next"
#define SOAP_1_2_ACTOR_NONE             "http://www.w3.org/2003/05/soap-envelope/role/none"
#define SOAP_1_2_ACTOR_UNLIMATERECEIVER "http://www.w3.org/2003/05/soap-envelope/role/ultimateReceiver"

#define SOAP_COMPRESSION_ACCEPT  0x20
#define SOAP_COMPRESSION_GZIP    0x00
#define SOAP_COMPRESSION_DEFLATE 0x10

#define SOAP_AUTHENTICATION_BASIC   0
#define SOAP_AUTHENTICATION_DIGEST  1

#define SOAP_SINGLE_ELEMENT_ARRAYS  (1<<0)
#define SOAP_WAIT_ONE_WAY_CALLS     (2<<0)

#define WSDL_CACHE_NONE     0x0
#define WSDL_CACHE_DISK     0x1
#define WSDL_CACHE_MEMORY   0x2
#define WSDL_CACHE_BOTH     0x3
/* wsf extension macros */

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

zval* add_soap_fault(zval *obj, char *fault_code, char *fault_string, char *fault_actor, zval *fault_detail TSRMLS_DC);

#define soap_error0(severity, format) \
	php_error(severity, "SOAP-ERROR: " format)

#define soap_error1(severity, format, param1) \
	php_error(severity, "SOAP-ERROR: " format, param1)

#define soap_error2(severity, format, param1, param2) \
	php_error(severity, "SOAP-ERROR: " format, param1, param2)

#define soap_error3(severity, format, param1, param2, param3) \
	php_error(severity, "SOAP-ERROR: " format, param1, param2, param3)
#endif	/* WSF_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
