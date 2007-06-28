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
#include "wsf_soap.h"
#include <axiom_soap_envelope.h>
#include <axis2_options.h>
#include <axis2_conf_ctx.h>
#include <axis2_msg_ctx.h>
#include <axiom_xml_reader.h>


#include "wsf.h"
#include "php_sdl.h"
#include "wsf_client.h"
#include "wsf_util.h"
#include "axis2_svc_client.h"


typedef struct _soapHeader {
    sdlFunctionPtr                    function;
    zval                              function_name;
    int                               mustUnderstand;
    int                               num_params;
    zval                            **parameters;
    zval                              retval;
    sdlSoapBindingFunctionHeaderPtr   hdr;
    struct _soapHeader               *next;
} soapHeader;

#define FIND_SDL_PROPERTY(ss,tmp) zend_hash_find(Z_OBJPROP_P(ss), "sdl", sizeof("sdl"), (void **)&tmp)
#define FETCH_SDL_RES(ss,tmp) ss = (sdlPtr) zend_fetch_resource(tmp TSRMLS_CC, -1, "sdl", NULL, 1, le_sdl)

#define FIND_TYPEMAP_PROPERTY(ss,tmp) zend_hash_find(Z_OBJPROP_P(ss), "typemap", sizeof("typemap"), (void **)&tmp)
#define FETCH_TYPEMAP_RES(ss,tmp) ss = (HashTable*) zend_fetch_resource(tmp TSRMLS_CC, -1, "typemap", NULL, 1, le_typemap)

/** initializing encoding array, from ext/soap */
void wsf_soap_prepare_ws_globals()
{
    int i;
    encodePtr enc;
    zend_hash_init(&defEnc, 0, NULL, NULL, 1);
    zend_hash_init(&defEncIndex, 0, NULL, NULL, 1);
    zend_hash_init(&defEncNs, 0, NULL, NULL, 1);
    i = 0;
    do {
        enc = &defaultEncoding[i];

        /* If has a ns and a str_type then index it */
        if (defaultEncoding[i].details.type_str) {
            if (defaultEncoding[i].details.ns != NULL) {
                char *ns_type;
                ns_type = emalloc(strlen(defaultEncoding[i].details.ns) + strlen(defaultEncoding[i].details.type_str) + 2);
                sprintf(ns_type, "%s:%s", defaultEncoding[i].details.ns, defaultEncoding[i].details.type_str);
                zend_hash_add(&defEnc, ns_type, strlen(ns_type) + 1, &enc, sizeof(encodePtr), NULL);
                efree(ns_type);
            } else {
                zend_hash_add(&defEnc, defaultEncoding[i].details.type_str, strlen(defaultEncoding[i].details.type_str) + 1
, &enc, sizeof(encodePtr), NULL);
            }
        }
        /* Index everything by number */
        if (!zend_hash_index_exists(&defEncIndex, defaultEncoding[i].details.type)) {
            zend_hash_index_update(&defEncIndex, defaultEncoding[i].details.type, &enc, sizeof(encodePtr), NULL);
        }
        i++;
    } while (defaultEncoding[i].details.type != END_KNOWN_TYPES);
    /* hash by namespace */
    zend_hash_add(&defEncNs, XSD_1999_NAMESPACE, sizeof(XSD_1999_NAMESPACE), XSD_NS_PREFIX, sizeof(XSD_NS_PREFIX), NULL);
    zend_hash_add(&defEncNs, XSD_NAMESPACE, sizeof(XSD_NAMESPACE), XSD_NS_PREFIX, sizeof(XSD_NS_PREFIX), NULL);
    zend_hash_add(&defEncNs, XSI_NAMESPACE, sizeof(XSI_NAMESPACE), XSI_NS_PREFIX, sizeof(XSI_NS_PREFIX), NULL);
    zend_hash_add(&defEncNs, XML_NAMESPACE, sizeof(XML_NAMESPACE), XML_NS_PREFIX, sizeof(XML_NS_PREFIX), NULL);

    zend_hash_add(&defEncNs, SOAP_1_1_ENC_NAMESPACE, sizeof(SOAP_1_1_ENC_NAMESPACE), 
            SOAP_1_1_ENC_NS_PREFIX, sizeof(SOAP_1_1_ENC_NS_PREFIX), NULL);

    zend_hash_add(&defEncNs, SOAP_1_2_ENC_NAMESPACE, sizeof(SOAP_1_2_ENC_NAMESPACE), 
            SOAP_1_2_ENC_NS_PREFIX, sizeof(SOAP_1_2_ENC_NS_PREFIX), NULL);
} 

static void soap_server_fault(char* code, char* string, char *actor, zval* details, char* name TSRMLS_DC)
{
    zval ret;

    INIT_ZVAL(ret);
    /*
    set_soap_fault(&ret, NULL, code, string, actor, details, name TSRMLS_CC);
    soap_server_fault_ex(NULL, &ret, NULL TSRMLS_CC);
    */
    zend_bailout();
}

void delete_url(void *handle)
{
    php_url_free((php_url*)handle);
}

void delete_hashtable(void *data)
{
	HashTable *ht = (HashTable*)data;
	zend_hash_destroy(ht);
	efree(ht);
}

static void function_to_string(sdlFunctionPtr function, smart_str *buf);

static void type_to_string(sdlTypePtr type, smart_str *buf, int level);
static sdlParamPtr get_param(sdlFunctionPtr function, char *param_name, int index, int);

static sdlFunctionPtr get_function(sdlPtr sdl, const char *function_name);

static sdlFunctionPtr get_doc_function(sdlPtr sdl, xmlNodePtr node);

static sdlFunctionPtr deserialize_function_call(sdlPtr sdl, xmlDocPtr request, char* actor, zval *function_name, int *num_params, zval **parameters[], int *version, soapHeader **headers TSRMLS_DC);


static xmlDocPtr serialize_response_call(sdlFunctionPtr function, char *function_name,char *uri,zval *ret, soapHeader *headers, int version TSRMLS_DC);

static xmlDocPtr serialize_function_call(zval *this_ptr, sdlFunctionPtr function, char *function_name, char *uri, zval **arguments, int arg_count, int version, HashTable *soap_headers TSRMLS_DC);

static xmlNodePtr serialize_parameter(sdlParamPtr param,zval *param_val,int index,char *name, int style, xmlNodePtr parent TSRMLS_DC);

static xmlNodePtr serialize_zval(zval *val, sdlParamPtr param, char *paramName, int style, xmlNodePtr parent TSRMLS_DC);

axiom_soap_envelope_t*
create_soap_envelope_from_doc(xmlDocPtr doc, const axutil_env_t *env, axis2_char_t *soap_version_uri)
{
	axiom_soap_envelope_t *soap_envelope = NULL;
	axiom_soap_builder_t *soap_builder = NULL;
	axiom_xml_reader_t *reader = NULL;
	axiom_stax_builder_t *builder = NULL;
	

	reader = axiom_xml_reader_create_for_memory(env, doc, 0, "utf-8", AXIS2_XML_PARSER_TYPE_DOC);
	
	builder = axiom_stax_builder_create(env, reader);

	soap_builder = axiom_soap_builder_create(env, builder, soap_version_uri); 

	soap_envelope = axiom_soap_builder_get_soap_envelope(soap_builder, env);

	return soap_envelope;
}

axiom_soap_envelope_t *
send_receive_soap_envelope_with_op_client(
        axutil_env_t *env, 
        axis2_svc_client_t *svc_client, 
        axis2_options_t *options,
        xmlDocPtr doc)
{
    axiom_soap_envelope_t *res_envelope = NULL, *req_envelope = NULL;
    axis2_svc_ctx_t *svc_ctx = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_msg_ctx_t *req_msg_ctx = NULL, *res_msg_ctx = NULL;
    axutil_qname_t *op_qname = NULL;
    axis2_op_client_t *op_client = NULL;
    axis2_char_t *soap_version_uri = NULL;    
    
    svc_ctx = axis2_svc_client_get_svc_ctx(svc_client, env);

    conf_ctx = axis2_svc_ctx_get_conf_ctx(svc_ctx, env);

    req_msg_ctx = axis2_msg_ctx_create(env, conf_ctx, NULL, NULL);

    op_qname = axutil_qname_create(env, AXIS2_ANON_OUT_IN_OP, NULL, NULL);

    op_client = axis2_svc_client_create_op_client(svc_client, env, op_qname);

    soap_version_uri = (axis2_char_t*)axis2_options_get_soap_version_uri(options, env);

    req_envelope =  create_soap_envelope_from_doc(doc , env, soap_version_uri);                              

    axis2_msg_ctx_set_soap_envelope(req_msg_ctx, env, req_envelope);

    axis2_op_client_add_msg_ctx(op_client, env, req_msg_ctx);

    axis2_op_client_execute(op_client, env, AXIS2_TRUE);

    res_msg_ctx = (axis2_msg_ctx_t *)axis2_op_client_get_msg_ctx(
                    op_client, env, AXIS2_WSDL_MESSAGE_LABEL_IN);

    if(!res_msg_ctx){
        return NULL;
    }else{
        res_envelope = axis2_msg_ctx_get_soap_envelope(res_msg_ctx, env);
    }
    return res_envelope;
}



int parse_packet_soap(zval *this_ptr, char *buffer, int buffer_size, sdlFunctionPtr fn, char *fn_name, zval *return_value, zval *soap_headers TSRMLS_DC)
{
        char* envelope_ns = NULL;
	xmlDocPtr response;
	xmlNodePtr trav, env, head, body, resp, cur, fault;
	xmlAttrPtr attr;
	int param_count = 0;
	int soap_version = SOAP_1_1;
	HashTable *hdrs = NULL;

	ZVAL_NULL(return_value);

	/* Response for one-way opearation */
	if (buffer_size == 0) {
		return TRUE;
	}

	/* Parse XML packet */
	response = soap_xmlParseMemory(buffer, buffer_size);

	if (!response) {
		add_soap_fault(this_ptr, "Client", "looks like we got no XML document", NULL, NULL TSRMLS_CC);
		return FALSE;
	}
	if (xmlGetIntSubset(response) != NULL) {
		add_soap_fault(this_ptr, "Client", "DTD are not supported by SOAP", NULL, NULL TSRMLS_CC);
		xmlFreeDoc(response);
		return FALSE;
	}

	/* Get <Envelope> element */
	env = NULL;
	trav = response->children;
	while (trav != NULL) {
		if (trav->type == XML_ELEMENT_NODE) {
			if (env == NULL && node_is_equal_ex(trav,"Envelope",SOAP_1_1_ENV_NAMESPACE)) {
				env = trav;
				envelope_ns = SOAP_1_1_ENV_NAMESPACE;
				soap_version = SOAP_1_1;
			} else if (env == NULL && node_is_equal_ex(trav,"Envelope",SOAP_1_2_ENV_NAMESPACE)) {
				env = trav;
				envelope_ns = SOAP_1_2_ENV_NAMESPACE;
				soap_version = SOAP_1_2;
			} else {
				add_soap_fault(this_ptr, "VersionMismatch", "Wrong Version", NULL, NULL TSRMLS_CC);
				xmlFreeDoc(response);
				return FALSE;
			}
		}
		trav = trav->next;
	}
	if (env == NULL) {
		add_soap_fault(this_ptr, "Client", "looks like we got XML without \"Envelope\" element", NULL, NULL TSRMLS_CC);
		xmlFreeDoc(response);
		return FALSE;
	}

	attr = env->properties;
	while (attr != NULL) {
		if (attr->ns == NULL) {
			add_soap_fault(this_ptr, "Client", "A SOAP Envelope element cannot have non Namespace qualified attributes", NULL, NULL TSRMLS_CC);
			xmlFreeDoc(response);
			return FALSE;
		} else if (attr_is_equal_ex(attr,"encodingStyle",SOAP_1_2_ENV_NAMESPACE)) {
			if (soap_version == SOAP_1_2) {
				add_soap_fault(this_ptr, "Client", "encodingStyle cannot be specified on the Envelope", NULL, NULL TSRMLS_CC);
				xmlFreeDoc(response);
				return FALSE;
			} else if (strcmp((char*)attr->children->content, SOAP_1_1_ENC_NAMESPACE) != 0) {
				add_soap_fault(this_ptr, "Client", "Unknown data encoding style", NULL, NULL TSRMLS_CC);
				xmlFreeDoc(response);
				return FALSE;
			}
		}
		attr = attr->next;
	}

	/* Get <Header> element */
	head = NULL;
	trav = env->children;
	while (trav != NULL && trav->type != XML_ELEMENT_NODE) {
		trav = trav->next;
	}
	if (trav != NULL && node_is_equal_ex(trav,"Header",envelope_ns)) {
		head = trav;
		trav = trav->next;
	}

	/* Get <Body> element */
	body = NULL;
	while (trav != NULL && trav->type != XML_ELEMENT_NODE) {
		trav = trav->next;
	}
	if (trav != NULL && node_is_equal_ex(trav,"Body",envelope_ns)) {
		body = trav;
		trav = trav->next;
	}
	while (trav != NULL && trav->type != XML_ELEMENT_NODE) {
		trav = trav->next;
	}
	if (body == NULL) {
		add_soap_fault(this_ptr, "Client", "Body must be present in a SOAP envelope", NULL, NULL TSRMLS_CC);
		xmlFreeDoc(response);
		return FALSE;
	}
	attr = body->properties;
	while (attr != NULL) {
		if (attr->ns == NULL) {
			if (soap_version == SOAP_1_2) {
				add_soap_fault(this_ptr, "Client", "A SOAP Body element cannot have non Namespace qualified attributes", NULL, NULL TSRMLS_CC);
				xmlFreeDoc(response);
				return FALSE;
			}
		} else if (attr_is_equal_ex(attr,"encodingStyle",SOAP_1_2_ENV_NAMESPACE)) {
			if (soap_version == SOAP_1_2) {
				add_soap_fault(this_ptr, "Client", "encodingStyle cannot be specified on the Body", NULL, NULL TSRMLS_CC);
				xmlFreeDoc(response);
				return FALSE;
			} else if (strcmp((char*)attr->children->content, SOAP_1_1_ENC_NAMESPACE) != 0) {
				add_soap_fault(this_ptr, "Client", "Unknown data encoding style", NULL, NULL TSRMLS_CC);
				xmlFreeDoc(response);
				return FALSE;
			}
		}
		attr = attr->next;
	}
	if (trav != NULL && soap_version == SOAP_1_2) {
		add_soap_fault(this_ptr, "Client", "A SOAP 1.2 envelope can contain only Header and Body", NULL, NULL TSRMLS_CC);
		xmlFreeDoc(response);
		return FALSE;
	}

	if (head != NULL) {
		attr = head->properties;
		while (attr != NULL) {
			if (attr->ns == NULL) {
				add_soap_fault(this_ptr, "Client", "A SOAP Header element cannot have non Namespace qualified attributes", NULL, NULL TSRMLS_CC);
				xmlFreeDoc(response);
				return FALSE;
			} else if (attr_is_equal_ex(attr,"encodingStyle",SOAP_1_2_ENV_NAMESPACE)) {
				if (soap_version == SOAP_1_2) {
					add_soap_fault(this_ptr, "Client", "encodingStyle cannot be specified on the Header", NULL, NULL TSRMLS_CC);
					xmlFreeDoc(response);
					return FALSE;
				} else if (strcmp((char*)attr->children->content, SOAP_1_1_ENC_NAMESPACE) != 0) {
					add_soap_fault(this_ptr, "Client", "Unknown data encoding style", NULL, NULL TSRMLS_CC);
					xmlFreeDoc(response);
					return FALSE;
				}
			}
			attr = attr->next;
		}
	}

	/* Check if <Body> contains <Fault> element */
	fault = get_node_ex(body->children,"Fault",envelope_ns);
	if (fault != NULL) {
		char *faultcode = NULL, *faultstring = NULL, *faultactor = NULL;
		zval *details = NULL;
		xmlNodePtr tmp;

		if (soap_version == SOAP_1_1) {
			tmp = get_node(fault->children, "faultcode");
			if (tmp != NULL && tmp->children != NULL) {
				faultcode = (char*)tmp->children->content;
			}

			tmp = get_node(fault->children, "faultstring");
			if (tmp != NULL && tmp->children != NULL) {
				zval *zv = master_to_zval(get_conversion(IS_STRING), tmp);
				faultstring = Z_STRVAL_P(zv);
				FREE_ZVAL(zv);
			}

			tmp = get_node(fault->children, "faultactor");
			if (tmp != NULL && tmp->children != NULL) {
				zval *zv = master_to_zval(get_conversion(IS_STRING), tmp);
				faultactor = Z_STRVAL_P(zv);
				FREE_ZVAL(zv);
			}

			tmp = get_node(fault->children, "detail");
			if (tmp != NULL) {
				details = master_to_zval(NULL, tmp);
			}
		} else {
			tmp = get_node(fault->children, "Code");
			if (tmp != NULL && tmp->children != NULL) {
				tmp = get_node(tmp->children, "Value");
				if (tmp != NULL && tmp->children != NULL) {
					faultcode = (char*)tmp->children->content;
				}
			}

			tmp = get_node(fault->children,"Reason");
			if (tmp != NULL && tmp->children != NULL) {
				/* TODO: lang attribute */
				tmp = get_node(tmp->children,"Text");
				if (tmp != NULL && tmp->children != NULL) {
					zval *zv = master_to_zval(get_conversion(IS_STRING), tmp);
					faultstring = Z_STRVAL_P(zv);
					FREE_ZVAL(zv);
				}
			}

			tmp = get_node(fault->children,"Detail");
			if (tmp != NULL) {
				details = master_to_zval(NULL, tmp);
			}
		}
		add_soap_fault(this_ptr, faultcode, faultstring, faultactor, details TSRMLS_CC);
		if (faultstring) {
			efree(faultstring);
		}
		if (faultactor) {
			efree(faultactor);
		}
#ifdef ZEND_ENGINE_2
		if (details) {
			details->refcount--;
		}
#endif
		xmlFreeDoc(response);
		return FALSE;
	}

	/* Parse content of <Body> element */
	array_init(return_value);
	resp = body->children;
	while (resp != NULL && resp->type != XML_ELEMENT_NODE) {
		resp = resp->next;
	}
	if (resp != NULL) {
		if (fn != NULL && fn->binding && fn->binding->bindingType == BINDING_SOAP) {
		  /* Function has WSDL description */
			sdlParamPtr *h_param, param = NULL;
			xmlNodePtr val = NULL;
			char *name, *ns = NULL;
			zval* tmp;
			sdlSoapBindingFunctionPtr fnb = (sdlSoapBindingFunctionPtr)fn->bindingAttributes;
			int res_count;

			hdrs = fnb->output.headers;

			if (fn->responseParameters) {
			  res_count = zend_hash_num_elements(fn->responseParameters);
				zend_hash_internal_pointer_reset(fn->responseParameters);
				while (zend_hash_get_current_data(fn->responseParameters, (void **)&h_param) == SUCCESS) {
					param = (*h_param);
					if (fnb->style == SOAP_DOCUMENT) {
						if (param->element) {
							name = param->element->name;
							ns = param->element->namens;
/*
							name = param->encode->details.type_str;
							ns = param->encode->details.ns;
*/
						} else {
							name = param->paramName;
						}
					} else {
						name = fn->responseName;
						/* ns = ? */
					}

					/* Get value of parameter */
					cur = get_node_ex(resp, name, ns);
					if (!cur) {
						cur = get_node(resp, name);
						/* TODO: produce warning invalid ns */
					}
					if (!cur && fnb->style == SOAP_RPC) {
					  cur = resp;
					}
					if (cur) {
						if (fnb->style == SOAP_DOCUMENT) {
							val = cur;
						} else {
							val = get_node(cur->children, param->paramName);
							if (res_count == 1) {
								if (val == NULL) {
									val = get_node(cur->children, "return");
								}
								if (val == NULL) {
									val = get_node(cur->children, "result");
								}
								if (val == NULL && cur->children && cur->children->next == NULL) {
									val = cur->children;								  
								}
							}
						}
					}

					if (!val) {
						/* TODO: may be "nil" is not OK? */
						MAKE_STD_ZVAL(tmp);
						ZVAL_NULL(tmp);
/*
						add_soap_fault(this_ptr, "Client", "Can't find response data", NULL, NULL TSRMLS_CC);
						xmlFreeDoc(response);
						return FALSE;
*/
					} else {
						/* Decoding value of parameter */
						if (param != NULL) {
							tmp = master_to_zval(param->encode, val);
						} else {
							tmp = master_to_zval(NULL, val);
						}
					}
					add_assoc_zval(return_value, param->paramName, tmp);

					param_count++;

					zend_hash_move_forward(fn->responseParameters);
				}
			}
		} else {
		  /* Function hasn't WSDL description */
			xmlNodePtr val;
			val = resp->children;
			while (val != NULL) {
				while (val && val->type != XML_ELEMENT_NODE) {
					val = val->next;
				}
				if (val != NULL) {
					if (!node_is_equal_ex(val,"result",RPC_SOAP12_NAMESPACE)) {
						zval *tmp;

						tmp = master_to_zval(NULL, val);
						if (val->name) {
							add_assoc_zval(return_value, (char*)val->name, tmp);
						} else {
							add_next_index_zval(return_value, tmp);
						}
						++param_count;
					}
					val = val->next;
				}
			}
		}
	}

	if (Z_TYPE_P(return_value) == IS_ARRAY) {
		if (param_count == 0) {
			zval_dtor(return_value);
			ZVAL_NULL(return_value);
		} else if (param_count == 1) {
			zval *tmp;

			zend_hash_internal_pointer_reset(Z_ARRVAL_P(return_value));
			zend_hash_get_current_data(Z_ARRVAL_P(return_value), (void**)&tmp);
			tmp = *(zval**)tmp;
			tmp->refcount++;
			zval_dtor(return_value);
			*return_value = *tmp;
			FREE_ZVAL(tmp);
		}
	}

	if (soap_headers && head) {
		trav = head->children;
		while (trav != NULL) {
			if (trav->type == XML_ELEMENT_NODE) {
				encodePtr enc = NULL;
				zval* val;

				if (hdrs) {
					smart_str key = {0};
					sdlSoapBindingFunctionHeaderPtr *hdr;

					if (trav->ns) {
						smart_str_appends(&key, (char*)trav->ns->href);
						smart_str_appendc(&key,':');
					}
					smart_str_appends(&key, (char*)trav->name);
					smart_str_0(&key);
					if (zend_hash_find(hdrs, key.c, key.len+1, (void**)&hdr) == SUCCESS) {
						enc = (*hdr)->encode;
					}
					smart_str_free(&key);
				}
				val = master_to_zval(enc, trav);
				add_assoc_zval(soap_headers, (char*)trav->name, val);
			}
			trav = trav->next;
		}
	}

	xmlFreeDoc(response);
	return TRUE;
}


static xmlDocPtr serialize_function_call(zval *this_ptr, sdlFunctionPtr function, char *function_name, char *uri, zval **arguments, int arg_count, int version, HashTable *soap_headers TSRMLS_DC)
{
		xmlDoc *doc;
	xmlNodePtr envelope = NULL, body, method = NULL, head = NULL;
	xmlNsPtr ns = NULL;
	zval **zstyle, **zuse;
	int i, style, use;
	HashTable *hdrs = NULL;

	encode_reset_ns();

	doc = xmlNewDoc(BAD_CAST("1.0"));
	doc->encoding = xmlCharStrdup("UTF-8");
	doc->charset = XML_CHAR_ENCODING_UTF8;
	if (version == SOAP_1_1) {
		envelope = xmlNewDocNode(doc, NULL, BAD_CAST("Envelope"), NULL);
		ns = xmlNewNs(envelope, BAD_CAST(SOAP_1_1_ENV_NAMESPACE), BAD_CAST(SOAP_1_1_ENV_NS_PREFIX));
		xmlSetNs(envelope, ns);
	} else if (version == SOAP_1_2) {
		envelope = xmlNewDocNode(doc, NULL, BAD_CAST("Envelope"), NULL);
		ns = xmlNewNs(envelope, BAD_CAST(SOAP_1_2_ENV_NAMESPACE), BAD_CAST(SOAP_1_2_ENV_NS_PREFIX));
		xmlSetNs(envelope, ns);
	} else {
		soap_error0(E_ERROR, "Unknown SOAP version");
	}
	xmlDocSetRootElement(doc, envelope);

	if (soap_headers) {
		head = xmlNewChild(envelope, ns, BAD_CAST("Header"), NULL);
	}

	body = xmlNewChild(envelope, ns, BAD_CAST("Body"), NULL);

	if (function && function->binding->bindingType == BINDING_SOAP) {
		sdlSoapBindingFunctionPtr fnb = (sdlSoapBindingFunctionPtr)function->bindingAttributes;

		hdrs = fnb->input.headers;
		style = fnb->style;
		/*FIXME: how to pass method name if style is SOAP_DOCUMENT */
		/*style = SOAP_RPC;*/
		use = fnb->input.use;
		if (style == SOAP_RPC) {
			ns = encode_add_ns(body, fnb->input.ns);
			if (function->requestName) {
				method = xmlNewChild(body, ns, BAD_CAST(function->requestName), NULL);
			} else {
				method = xmlNewChild(body, ns, BAD_CAST(function->functionName), NULL);
			}
		}
	} else {
		if (zend_hash_find(Z_OBJPROP_P(this_ptr), "style", sizeof("style"), (void **)&zstyle) == SUCCESS) {
			style = Z_LVAL_PP(zstyle);
		} else {
			style = SOAP_RPC;
		}
		/*FIXME: how to pass method name if style is SOAP_DOCUMENT */
		/*style = SOAP_RPC;*/
		if (style == SOAP_RPC) {
			ns = encode_add_ns(body, uri);
			method = xmlNewChild(body, ns, BAD_CAST(function_name), NULL);
		}

		if (zend_hash_find(Z_OBJPROP_P(this_ptr), "use", sizeof("use"), (void **)&zuse) == SUCCESS &&
			  Z_LVAL_PP(zuse) == SOAP_LITERAL) {
			use = SOAP_LITERAL;
		} else {
			use = SOAP_ENCODED;
		}
	}

	for (i = 0;i < arg_count;i++) {
		xmlNodePtr param;
		sdlParamPtr parameter = get_param(function, NULL, i, FALSE);

		if (style == SOAP_RPC) {
			param = serialize_parameter(parameter, arguments[i], i, NULL, use, method TSRMLS_CC);
		} else if (style == SOAP_DOCUMENT) {
			param = serialize_parameter(parameter, arguments[i], i, NULL, use, body TSRMLS_CC);
			if (function && function->binding->bindingType == BINDING_SOAP) {
				if (parameter && parameter->element) {
					ns = encode_add_ns(param, parameter->element->namens);
					xmlNodeSetName(param, BAD_CAST(parameter->element->name));
					xmlSetNs(param, ns);
				}
			}
		}
	}

	if (function && function->requestParameters) {
		int n = zend_hash_num_elements(function->requestParameters);

		if (n > arg_count) {
			for (i = arg_count; i < n; i++) {
				xmlNodePtr param;
				sdlParamPtr parameter = get_param(function, NULL, i, FALSE);

				if (style == SOAP_RPC) {
					param = serialize_parameter(parameter, NULL, i, NULL, use, method TSRMLS_CC);
				} else if (style == SOAP_DOCUMENT) {
					param = serialize_parameter(parameter, NULL, i, NULL, use, body TSRMLS_CC);
					if (function && function->binding->bindingType == BINDING_SOAP) {
						if (parameter && parameter->element) {
							ns = encode_add_ns(param, parameter->element->namens);
							xmlNodeSetName(param, BAD_CAST(parameter->element->name));
							xmlSetNs(param, ns);
						}
					}
				}
			}
		}
	}

	if (head) {
		zval** header;

		zend_hash_internal_pointer_reset(soap_headers);
		while (zend_hash_get_current_data(soap_headers,(void**)&header) == SUCCESS) {
			HashTable *ht = Z_OBJPROP_PP(header);
			zval **name, **ns, **tmp;

			if (zend_hash_find(ht, "name", sizeof("name"), (void**)&name) == SUCCESS &&
			    Z_TYPE_PP(name) == IS_STRING &&
			    zend_hash_find(ht, "namespace", sizeof("namespace"), (void**)&ns) == SUCCESS &&
			    Z_TYPE_PP(ns) == IS_STRING) {
				xmlNodePtr h;
				xmlNsPtr nsptr;
				int hdr_use = SOAP_LITERAL;
				encodePtr enc = NULL;

				if (hdrs) {
					smart_str key = {0};
					sdlSoapBindingFunctionHeaderPtr *hdr;

					smart_str_appendl(&key, Z_STRVAL_PP(ns), Z_STRLEN_PP(ns));
					smart_str_appendc(&key, ':');
					smart_str_appendl(&key, Z_STRVAL_PP(name), Z_STRLEN_PP(name));
					smart_str_0(&key);
					if (zend_hash_find(hdrs, key.c, key.len+1,(void**)&hdr) == SUCCESS) {
						hdr_use = (*hdr)->use;
						enc = (*hdr)->encode;
						if (hdr_use == SOAP_ENCODED) {
							use = SOAP_ENCODED;
						}
					}
					smart_str_free(&key);
				}

				if (zend_hash_find(ht, "data", sizeof("data"), (void**)&tmp) == SUCCESS) {
					h = master_to_xml(enc, *tmp, hdr_use, head);
					xmlNodeSetName(h, BAD_CAST(Z_STRVAL_PP(name)));
				} else {
					h = xmlNewNode(NULL, BAD_CAST(Z_STRVAL_PP(name)));
					xmlAddChild(head, h);
				}
				nsptr = encode_add_ns(h, Z_STRVAL_PP(ns));
				xmlSetNs(h, nsptr);

				if (zend_hash_find(ht, "mustUnderstand", sizeof("mustUnderstand"), (void**)&tmp) == SUCCESS &&
				    Z_TYPE_PP(tmp) == IS_BOOL && Z_LVAL_PP(tmp)) {
					if (version == SOAP_1_1) {
						xmlSetProp(h, BAD_CAST(SOAP_1_1_ENV_NS_PREFIX":mustUnderstand"), BAD_CAST("1"));
					} else {
						xmlSetProp(h, BAD_CAST(SOAP_1_2_ENV_NS_PREFIX":mustUnderstand"), BAD_CAST("true"));
					}
				}
				if (zend_hash_find(ht, "actor", sizeof("actor"), (void**)&tmp) == SUCCESS) {
					if (Z_TYPE_PP(tmp) == IS_STRING) {
						if (version == SOAP_1_1) {
							xmlSetProp(h, BAD_CAST(SOAP_1_1_ENV_NS_PREFIX":actor"), BAD_CAST(Z_STRVAL_PP(tmp)));
						} else {
							xmlSetProp(h, BAD_CAST(SOAP_1_2_ENV_NS_PREFIX":role"), BAD_CAST(Z_STRVAL_PP(tmp)));
						}
					} else if (Z_TYPE_PP(tmp) == IS_LONG) {
						if (version == SOAP_1_1) {
							if (Z_LVAL_PP(tmp) == SOAP_ACTOR_NEXT) {
								xmlSetProp(h, BAD_CAST(SOAP_1_1_ENV_NS_PREFIX":actor"), BAD_CAST(SOAP_1_1_ACTOR_NEXT));
							}
						} else {
							if (Z_LVAL_PP(tmp) == SOAP_ACTOR_NEXT) {
								xmlSetProp(h, BAD_CAST(SOAP_1_2_ENV_NS_PREFIX":role"), BAD_CAST(SOAP_1_2_ACTOR_NEXT));
							} else if (Z_LVAL_PP(tmp) == SOAP_ACTOR_NONE) {
								xmlSetProp(h, BAD_CAST(SOAP_1_2_ENV_NS_PREFIX":role"), BAD_CAST(SOAP_1_2_ACTOR_NONE));
							} else if (Z_LVAL_PP(tmp) == SOAP_ACTOR_UNLIMATERECEIVER) {
								xmlSetProp(h, BAD_CAST(SOAP_1_2_ENV_NS_PREFIX":role"), BAD_CAST(SOAP_1_2_ACTOR_UNLIMATERECEIVER));
							}
						}
					}
				}
			}
			zend_hash_move_forward(soap_headers);
		}
	}

	if (use == SOAP_ENCODED) {
		xmlNewNs(envelope, BAD_CAST(XSD_NAMESPACE), BAD_CAST(XSD_NS_PREFIX));
		if (version == SOAP_1_1) {
			xmlNewNs(envelope, BAD_CAST(SOAP_1_1_ENC_NAMESPACE), BAD_CAST(SOAP_1_1_ENC_NS_PREFIX));
			xmlSetNsProp(envelope, envelope->ns, BAD_CAST("encodingStyle"), BAD_CAST(SOAP_1_1_ENC_NAMESPACE));
		} else if (version == SOAP_1_2) {
			xmlNewNs(envelope, BAD_CAST(SOAP_1_2_ENC_NAMESPACE), BAD_CAST(SOAP_1_2_ENC_NS_PREFIX));
			if (method) {
				xmlSetNsProp(method, envelope->ns, BAD_CAST("encodingStyle"), BAD_CAST(SOAP_1_2_ENC_NAMESPACE));
			}
		}
	}

	return doc;
}

void wsf_soap_do_soap_call(zval* this_ptr,
                         char* function,
                         int function_len,
                         int arg_count,
                         zval** real_args,
                         zval* return_value,
                         char* location,
                         char* soap_action,
                         char* call_uri,
                         HashTable* soap_headers,
                         zval* output_headers,
                         axutil_env_t *env
                         TSRMLS_DC)
{
	zval **tmp;
	zval **trace;
 	sdlPtr sdl = NULL;
 	sdlPtr old_sdl = NULL;
 	sdlFunctionPtr fn;
	xmlDocPtr request = NULL;
        /* int ret = FALSE;   */
	int soap_version;
	zval response;
	xmlCharEncodingHandlerPtr old_encoding;
	HashTable *old_class_map;
	int old_features;
	HashTable *old_typemap, *typemap = NULL;
    zval *client_zval = NULL;
	
    axiom_soap_envelope_t *res_envelope = NULL;

    axis2_svc_client_t *svc_client = NULL;
    axis2_options_t *client_options = NULL;
	ws_object_ptr intern= NULL;		
    
    /** find the object type */
    if(instanceof_function(Z_OBJCE_P(this_ptr), ws_client_proxy_class_entry TSRMLS_CC)){
        if(zend_hash_find(Z_OBJPROP_P(this_ptr), "wsclient", sizeof("wsclient"), (void**)&tmp) == SUCCESS){
            client_zval = *tmp;
        }else{
            php_error_docref(NULL TSRMLS_CC, E_ERROR," proxy created without wsclient");
            return;
        }
    }else if(instanceof_function(Z_OBJCE_P(this_ptr), ws_client_class_entry TSRMLS_CC)){
            client_zval = this_ptr;
    }

	if (zend_hash_find(Z_OBJPROP_P(client_zval), "trace", sizeof("trace"), (void **) &trace) == SUCCESS
		&& Z_LVAL_PP(trace) > 0) {
		zend_hash_del(Z_OBJPROP_P(client_zval), "__last_request", sizeof("__last_request"));
		zend_hash_del(Z_OBJPROP_P(client_zval), "__last_response", sizeof("__last_response"));
	}

	WSF_GET_OBJ(svc_client, client_zval , axis2_svc_client_t, intern);
	client_options = (axis2_options_t*)axis2_svc_client_get_options(svc_client, env);

	if (FIND_SDL_PROPERTY(client_zval,tmp) != FAILURE) {
		FETCH_SDL_RES(sdl,tmp);
	}
	if (FIND_TYPEMAP_PROPERTY(client_zval,tmp) != FAILURE) {
		FETCH_TYPEMAP_RES(typemap,tmp);
	}

	old_sdl = WSF_GLOBAL(sdl);
	WSF_GLOBAL(sdl) = sdl;
	old_encoding = WSF_GLOBAL(encoding);
	
	if (zend_hash_find(Z_OBJPROP_P(client_zval), "_encoding", sizeof("_encoding"), (void **) &tmp) == SUCCESS &&
	    Z_TYPE_PP(tmp) == IS_STRING) {
		WSF_GLOBAL(encoding) = xmlFindCharEncodingHandler(Z_STRVAL_PP(tmp));
	} else {
		WSF_GLOBAL(encoding) = NULL;
	}
	old_class_map = WSF_GLOBAL(class_map);
	
	if (zend_hash_find(Z_OBJPROP_P(client_zval), "_classmap", sizeof("_classmap"), (void **) &tmp) == SUCCESS &&
	    Z_TYPE_PP(tmp) == IS_ARRAY) {
		WSF_GLOBAL(class_map) = (*tmp)->value.ht;
	} else {
		WSF_GLOBAL(class_map) = NULL;
	}
	
	old_typemap = WSF_GLOBAL(typemap);
	
	WSF_GLOBAL(typemap) = typemap;
	
	old_features = WSF_GLOBAL(features);
	
	if (zend_hash_find(Z_OBJPROP_P(client_zval), "_features", sizeof("_features"), (void **) &tmp) == SUCCESS &&
	    Z_TYPE_PP(tmp) == IS_LONG) {
		WSF_GLOBAL(features) = Z_LVAL_PP(tmp);
	} else {
		WSF_GLOBAL(features) = 0;
	}
    
 	if (sdl != NULL) {
 		fn = get_function(sdl, function);
 		if (fn != NULL) {
			sdlBindingPtr binding = fn->binding;
			int one_way = 0;

			if (fn->responseName == NULL &&
			    fn->responseParameters == NULL &&
			    soap_headers == NULL) {
				one_way = 1;
			}

			if (location == NULL) {
                axis2_endpoint_ref_t *to_epr = NULL;
				location = binding->location;
                to_epr = axis2_endpoint_ref_create(env, location);
                axis2_options_set_to(client_options, env, to_epr);
                {/** set options */
                    HashTable *client_ht = NULL;
                    if(zend_hash_find(Z_OBJPROP_P(client_zval), WS_OPTIONS, sizeof(WS_OPTIONS), (void **) &tmp) == SUCCESS)                     {
                        if(Z_TYPE_PP(tmp) == IS_ARRAY){
                            client_ht = Z_ARRVAL_PP(tmp);
                        }   
                        
                    }
                    wsf_client_set_options(client_ht, NULL, env, client_options, svc_client, 0 TSRMLS_CC);
                }
                
			}

            soap_version = WSF_GLOBAL(soap_version);
			if (binding->bindingType == BINDING_SOAP) {
				/*
                xmlChar *buf = NULL;
                int size;
                */
				sdlSoapBindingFunctionPtr fnb = (sdlSoapBindingFunctionPtr)fn->bindingAttributes;
				request = serialize_function_call(client_zval, fn, NULL, fnb->input.ns, real_args, arg_count, soap_version, soap_headers TSRMLS_CC);
		
                if(fnb->soapAction){
                    axutil_string_t *action_string = axutil_string_create(env, fnb->soapAction);
                    axis2_options_set_soap_action(client_options, env, action_string);
                }
                res_envelope =  send_receive_soap_envelope_with_op_client(env, svc_client, client_options, request);
                if(res_envelope){
                    axis2_char_t *buffer = NULL;
                    int buffer_length = 0;
                    axiom_node_t *env_node = NULL;
                    env_node = axiom_soap_envelope_get_base_node(res_envelope, env);
                    if(env_node){
                        buffer = axiom_node_to_string(env_node, env);
                        if(buffer){
                            buffer_length = strlen(buffer);
                            parse_packet_soap(client_zval , buffer, 
                                              buffer_length , fn, NULL, return_value, NULL TSRMLS_CC);
                        }
                    }
                }
 			}
			xmlFreeDoc(request);
			zval_dtor(&response);

 		} else {
 			smart_str error = {0};
 			smart_str_appends(&error,"Function (\"");
 			smart_str_appends(&error,function);
 			smart_str_appends(&error,"\") is not a valid method for this service");
 			smart_str_0(&error);
			add_soap_fault(client_zval, "Client", error.c, NULL, NULL TSRMLS_CC);
			smart_str_free(&error);
		}
	} else {
		
        zval **uri;
		smart_str action = {0};

		if (zend_hash_find(Z_OBJPROP_P(client_zval), "uri", sizeof("uri"), (void *)&uri) == FAILURE) {
			add_soap_fault(client_zval, "Client", "Error finding \"uri\" property", NULL, NULL TSRMLS_CC);
		} else if (location == NULL) {
			add_soap_fault(client_zval, "Client", "Error could not find \"location\" property", NULL, NULL TSRMLS_CC);
		} else {
			if (call_uri == NULL) {
				call_uri = Z_STRVAL_PP(uri);
			}

	 		request = serialize_function_call(client_zval, NULL, function, call_uri, real_args, arg_count, soap_version, soap_headers TSRMLS_CC);

	 		if (soap_action == NULL) {
				smart_str_appends(&action, call_uri);
				smart_str_appendc(&action, '#');
				smart_str_appends(&action, function);
			} else {
				smart_str_appends(&action, soap_action);
			}
			smart_str_0(&action);
			res_envelope = send_receive_soap_envelope_with_op_client(env, svc_client, client_options, request);

	        if(res_envelope){
			   axis2_char_t *buffer = NULL;
				int buffer_length = 0;
				axiom_node_t *env_node = NULL;
				env_node = axiom_soap_envelope_get_base_node(res_envelope, env);
				if(env_node){
					buffer = axiom_node_to_string(env_node, env);
					if(buffer){
						buffer_length = strlen(buffer);
						parse_packet_soap(client_zval , buffer, 
                                buffer_length , fn, NULL, return_value, NULL TSRMLS_CC);
					}
				}
            }
		}
 	}
/*
	if (!ret) {
		zval** fault;
		if (zend_hash_find(Z_OBJPROP_P(this_ptr), "__soap_fault", sizeof("__soap_fault"), (void **) &fault) == SUCCESS) {
			*return_value = **fault;
			zval_copy_ctor(return_value);
		} else {
			*return_value = *add_soap_fault(this_ptr, "Client", "Unknown Error", NULL, NULL TSRMLS_CC);
			zval_copy_ctor(return_value);
		}
	} else {
		zval** fault;
		if (zend_hash_find(Z_OBJPROP_P(this_ptr), "__soap_fault", sizeof("__soap_fault"), (void **) &fault) == SUCCESS) {
			*return_value = **fault;
			zval_copy_ctor(return_value);
		}
	}
#ifdef ZEND_ENGINE_2
	if (!EG(exception) &&
	    Z_TYPE_P(return_value) == IS_OBJECT &&
	    instanceof_function(Z_OBJCE_P(return_value), ws_fault_class_entry TSRMLS_CC) &&
	    (zend_hash_find(Z_OBJPROP_P(this_ptr), "_exceptions", sizeof("_exceptions"), (void **) &tmp) != SUCCESS ||
		   Z_TYPE_PP(tmp) != IS_BOOL || Z_LVAL_PP(tmp) != 0)) {
		zval *exception;

		MAKE_STD_ZVAL(exception);
		*exception = *return_value;
		zval_copy_ctor(exception);
		INIT_PZVAL(exception);
		zend_throw_exception_object(exception TSRMLS_CC);
	}
#endif
*/
	if (WSF_GLOBAL(encoding) != NULL) {
		xmlCharEncCloseFunc(WSF_GLOBAL(encoding));
	}
	WSF_GLOBAL(features) = old_features;
	WSF_GLOBAL(typemap) = old_typemap;
	WSF_GLOBAL(class_map) = old_class_map;
	WSF_GLOBAL(encoding) = old_encoding;
	WSF_GLOBAL(sdl) = old_sdl;
	
}


static void deserialize_parameters(xmlNodePtr params, sdlFunctionPtr function, int *num_params, zval ***parameters)
{
	int cur_param = 0,num_of_params = 0;
	zval **tmp_parameters = NULL;

	if (function != NULL) {
		sdlParamPtr *param;
		xmlNodePtr val;
		int	use_names = 0;

		if (function->requestParameters == NULL) {
			return;
		}
		num_of_params = zend_hash_num_elements(function->requestParameters);
		zend_hash_internal_pointer_reset(function->requestParameters);
		while (zend_hash_get_current_data(function->requestParameters, (void **)&param) == SUCCESS) {
			if (get_node(params, (*param)->paramName) != NULL) {
				use_names = 1;
			}
			zend_hash_move_forward(function->requestParameters);
		}
		if (use_names) {
			tmp_parameters = safe_emalloc(num_of_params, sizeof(zval *), 0);
			zend_hash_internal_pointer_reset(function->requestParameters);
			while (zend_hash_get_current_data(function->requestParameters, (void **)&param) == SUCCESS) {
				val = get_node(params, (*param)->paramName);
				if (!val) {
					/* TODO: may be "nil" is not OK? */
					MAKE_STD_ZVAL(tmp_parameters[cur_param]);
					ZVAL_NULL(tmp_parameters[cur_param]);
				} else {
					tmp_parameters[cur_param] = master_to_zval((*param)->encode, val);
				}
				cur_param++;

				zend_hash_move_forward(function->requestParameters);
			}
			(*parameters) = tmp_parameters;
			(*num_params) = num_of_params;
			return;
		}
	}
	if (params) {
		xmlNodePtr trav;

		num_of_params = 0;
		trav = params;
		while (trav != NULL) {
			if (trav->type == XML_ELEMENT_NODE) {
				num_of_params++;
			}
			trav = trav->next;
		}
		if (num_of_params > 0) {
			tmp_parameters = safe_emalloc(num_of_params, sizeof(zval *), 0);

			trav = params;
			while (trav != 0 && cur_param < num_of_params) {
				if (trav->type == XML_ELEMENT_NODE) {
					encodePtr enc;
					sdlParamPtr *param = NULL;
					if (function != NULL &&
					    zend_hash_index_find(function->requestParameters, cur_param, (void **)&param) == FAILURE) {
						TSRMLS_FETCH();
						soap_server_fault("Client", "Error cannot find parameter", NULL, NULL, NULL TSRMLS_CC);
					}
					if (param == NULL) {
						enc = NULL;
					} else {
						enc = (*param)->encode;
					}
					tmp_parameters[cur_param] = master_to_zval(enc, trav);
					cur_param++;
				}
				trav = trav->next;
			}
		}
	}
	if (num_of_params > cur_param) {
		TSRMLS_FETCH();
		soap_server_fault("Client","Missing parameter", NULL, NULL, NULL TSRMLS_CC);
	}
	(*parameters) = tmp_parameters;
	(*num_params) = num_of_params;
}


static sdlFunctionPtr find_function(sdlPtr sdl, xmlNodePtr func, zval* function_name)
{
	sdlFunctionPtr function;

	function = get_function(sdl, (char*)func->name);
	if (function && function->binding && function->binding->bindingType == BINDING_SOAP) {
		sdlSoapBindingFunctionPtr fnb = (sdlSoapBindingFunctionPtr)function->bindingAttributes;
		if (fnb->style == SOAP_DOCUMENT) {
			function = NULL;
		}
	}
	if (sdl != NULL && function == NULL) {
		function = get_doc_function(sdl, func);
	}

	INIT_ZVAL(*function_name);
	if (function != NULL) {
		ZVAL_STRING(function_name, (char *)function->functionName, 1);
	} else {
		ZVAL_STRING(function_name, (char *)func->name, 1);
	}

	return function;

}


static sdlFunctionPtr deserialize_function_call(sdlPtr sdl, xmlDocPtr request, char* actor, zval *function_name, int *num_params, zval ***parameters, int *version, soapHeader **headers TSRMLS_DC)
{
	char* envelope_ns = NULL;
	xmlNodePtr trav,env,head,body,func;
	xmlAttrPtr attr;
	sdlFunctionPtr function;

/*	 Get <Envelope> element  */
	env = NULL;
	trav = request->children;
	while (trav != NULL) {
		if (trav->type == XML_ELEMENT_NODE) {
			if (env == NULL && node_is_equal_ex(trav,"Envelope",SOAP_1_1_ENV_NAMESPACE)) {
				env = trav;
				*version = SOAP_1_1;
				envelope_ns = SOAP_1_1_ENV_NAMESPACE;
				WSF_GLOBAL(soap_version) = SOAP_1_1;
			} else if (env == NULL && node_is_equal_ex(trav,"Envelope",SOAP_1_2_ENV_NAMESPACE)) {
				env = trav;
				*version = SOAP_1_2;
				envelope_ns = SOAP_1_2_ENV_NAMESPACE;
				WSF_GLOBAL(soap_version) = SOAP_1_2;
			} else {
				soap_server_fault("VersionMismatch", "Wrong Version", NULL, NULL, NULL TSRMLS_CC);
			}
		}
		trav = trav->next;
	}
	if (env == NULL) {
		soap_server_fault("Client", "looks like we got XML without \"Envelope\" element", NULL, NULL, NULL TSRMLS_CC);
	}

	attr = env->properties;
	while (attr != NULL) {
		if (attr->ns == NULL) {
			soap_server_fault("Client", "A SOAP Envelope element cannot have non Namespace qualified attributes", NULL, NULL, NULL TSRMLS_CC);
		} else if (attr_is_equal_ex(attr,"encodingStyle",SOAP_1_2_ENV_NAMESPACE)) {
			if (*version == SOAP_1_2) {
				soap_server_fault("Client", "encodingStyle cannot be specified on the Envelope", NULL, NULL, NULL TSRMLS_CC);
			} else if (strcmp((char*)attr->children->content,SOAP_1_1_ENC_NAMESPACE) != 0) {
				soap_server_fault("Client", "Unknown data encoding style", NULL, NULL, NULL TSRMLS_CC);
			}
		}
		attr = attr->next;
	}

    /*	 Get <Header> element  */
	head = NULL;
	trav = env->children;
	while (trav != NULL && trav->type != XML_ELEMENT_NODE) {
		trav = trav->next;
	}
	if (trav != NULL && node_is_equal_ex(trav,"Header",envelope_ns)) {
		head = trav;
		trav = trav->next;
	}

    /*	 Get <Body> element  */
	body = NULL;
	while (trav != NULL && trav->type != XML_ELEMENT_NODE) {
		trav = trav->next;
	}
	if (trav != NULL && node_is_equal_ex(trav,"Body",envelope_ns)) {
		body = trav;
		trav = trav->next;
	}
	while (trav != NULL && trav->type != XML_ELEMENT_NODE) {
		trav = trav->next;
	}
	if (body == NULL) {
		soap_server_fault("Client", "Body must be present in a SOAP envelope", NULL, NULL, NULL TSRMLS_CC);
	}
	attr = body->properties;
	while (attr != NULL) {
		if (attr->ns == NULL) {
			if (*version == SOAP_1_2) {
				soap_server_fault("Client", "A SOAP Body element cannot have non Namespace qualified attributes", NULL, NULL, NULL TSRMLS_CC);
			}
		} else if (attr_is_equal_ex(attr,"encodingStyle",SOAP_1_2_ENV_NAMESPACE)) {
			if (*version == SOAP_1_2) {
				soap_server_fault("Client", "encodingStyle cannot be specified on the Body", NULL, NULL, NULL TSRMLS_CC);
			} else if (strcmp((char*)attr->children->content,SOAP_1_1_ENC_NAMESPACE) != 0) {
				soap_server_fault("Client", "Unknown data encoding style", NULL, NULL, NULL TSRMLS_CC);
			}
		}
		attr = attr->next;
	}

	if (trav != NULL && *version == SOAP_1_2) {
		soap_server_fault("Client", "A SOAP 1.2 envelope can contain only Header and Body", NULL, NULL, NULL TSRMLS_CC);
	}

	func = NULL;
	trav = body->children;
	while (trav != NULL) {
		if (trav->type == XML_ELEMENT_NODE) {

			if (func != NULL) {
				soap_server_fault("Client", "looks like we got \"Body\" with several functions call", NULL, NULL, NULL TSRMLS_CC);
			}

			func = trav;
			break;
   /*FIXME: the rest of body is ignored */
		}
		trav = trav->next;
	}
	if (func == NULL) {
		function = get_doc_function(sdl, NULL);
		if (function != NULL) {
			INIT_ZVAL(*function_name);
			ZVAL_STRING(function_name, (char *)function->functionName, 1);
		} else {
			soap_server_fault("Client", "looks like we got \"Body\" without function call", NULL, NULL, NULL TSRMLS_CC);
		}
	} else {
		if (*version == SOAP_1_1) {
			attr = get_attribute_ex(func->properties,"encodingStyle",SOAP_1_1_ENV_NAMESPACE);
			if (attr && strcmp((char*)attr->children->content,SOAP_1_1_ENC_NAMESPACE) != 0) {
				soap_server_fault("Client","Unknown Data Encoding Style", NULL, NULL, NULL TSRMLS_CC);
			}
		} else {
			attr = get_attribute_ex(func->properties,"encodingStyle",SOAP_1_2_ENV_NAMESPACE);
			if (attr && strcmp((char*)attr->children->content,SOAP_1_2_ENC_NAMESPACE) != 0) {
				soap_server_fault("DataEncodingUnknown","Unknown Data Encoding Style", NULL, NULL, NULL TSRMLS_CC);
			}
		}
		function = find_function(sdl, func, function_name);
		if (sdl != NULL && function == NULL) {
			if (*version == SOAP_1_2) {
				soap_server_fault("rpc:ProcedureNotPresent","Procedure not present", NULL, NULL, NULL TSRMLS_CC);
			} else {
				php_error(E_ERROR, "Procedure '%s' not present", func->name);
			}
		}
	}

	*headers = NULL;
	if (head) {
		soapHeader *h, *last = NULL;

		attr = head->properties;
		while (attr != NULL) {
			if (attr->ns == NULL) {
				soap_server_fault("Client", "A SOAP Header element cannot have non Namespace qualified attributes", NULL, NULL, NULL TSRMLS_CC);
			} else if (attr_is_equal_ex(attr,"encodingStyle",SOAP_1_2_ENV_NAMESPACE)) {
				if (*version == SOAP_1_2) {
					soap_server_fault("Client", "encodingStyle cannot be specified on the Header", NULL, NULL, NULL TSRMLS_CC);
				} else if (strcmp((char*)attr->children->content,SOAP_1_1_ENC_NAMESPACE) != 0) {
					soap_server_fault("Client", "Unknown data encoding style", NULL, NULL, NULL TSRMLS_CC);
				}
			}
			attr = attr->next;
		}
		trav = head->children;
		while (trav != NULL) {
			if (trav->type == XML_ELEMENT_NODE) {
				xmlNodePtr hdr_func = trav;
				xmlAttrPtr attr;
				int mustUnderstand = 0;

				if (*version == SOAP_1_1) {
					attr = get_attribute_ex(hdr_func->properties,"encodingStyle",SOAP_1_1_ENV_NAMESPACE);
					if (attr && strcmp((char*)attr->children->content,SOAP_1_1_ENC_NAMESPACE) != 0) {
						soap_server_fault("Client","Unknown Data Encoding Style", NULL, NULL, NULL TSRMLS_CC);
					}
					attr = get_attribute_ex(hdr_func->properties,"actor",envelope_ns);
					if (attr != NULL) {
						if (strcmp((char*)attr->children->content,SOAP_1_1_ACTOR_NEXT) != 0 &&
						    (actor == NULL || strcmp((char*)attr->children->content,actor) != 0)) {
						  goto ignore_header;
						}
					}
				} else if (*version == SOAP_1_2) {
					attr = get_attribute_ex(hdr_func->properties,"encodingStyle",SOAP_1_2_ENV_NAMESPACE);
					if (attr && strcmp((char*)attr->children->content,SOAP_1_2_ENC_NAMESPACE) != 0) {
						soap_server_fault("DataEncodingUnknown","Unknown Data Encoding Style", NULL, NULL, NULL TSRMLS_CC);
					}
					attr = get_attribute_ex(hdr_func->properties,"role",envelope_ns);
					if (attr != NULL) {
						if (strcmp((char*)attr->children->content,SOAP_1_2_ACTOR_UNLIMATERECEIVER) != 0 &&
						    strcmp((char*)attr->children->content,SOAP_1_2_ACTOR_NEXT) != 0 &&
						    (actor == NULL || strcmp((char*)attr->children->content,actor) != 0)) {
						  goto ignore_header;
						}
					}
				}
				attr = get_attribute_ex(hdr_func->properties,"mustUnderstand",envelope_ns);
				if (attr) {
					if (strcmp((char*)attr->children->content,"1") == 0 ||
					    strcmp((char*)attr->children->content,"true") == 0) {
						mustUnderstand = 1;
					} else if (strcmp((char*)attr->children->content,"0") == 0 ||
					           strcmp((char*)attr->children->content,"false") == 0) {
						mustUnderstand = 0;
					} else {
						soap_server_fault("Client","mustUnderstand value is not boolean", NULL, NULL, NULL TSRMLS_CC);
					}
				}
				h = emalloc(sizeof(soapHeader));
				memset(h, 0, sizeof(soapHeader));
				h->mustUnderstand = mustUnderstand;
				h->function = find_function(sdl, hdr_func, &h->function_name);
				if (!h->function && sdl && function && function->binding && function->binding->bindingType == BINDING_SOAP) {
					sdlSoapBindingFunctionHeaderPtr *hdr;
					sdlSoapBindingFunctionPtr fnb = (sdlSoapBindingFunctionPtr)function->bindingAttributes;
					if (fnb->input.headers) {
						smart_str key = {0};

						if (hdr_func->ns) {
							smart_str_appends(&key, (char*)hdr_func->ns->href);
							smart_str_appendc(&key, ':');
						}
						smart_str_appendl(&key, Z_STRVAL(h->function_name), Z_STRLEN(h->function_name));
						smart_str_0(&key);
						if (zend_hash_find(fnb->input.headers, key.c, key.len+1, (void**)&hdr) == SUCCESS) {
							h->hdr = *hdr;
						}
						smart_str_free(&key);
					}
				}
				if (h->hdr) {
					h->num_params = 1;
					h->parameters = emalloc(sizeof(zval*));
					h->parameters[0] = master_to_zval(h->hdr->encode, hdr_func);
				} else {
					if (h->function && h->function->binding && h->function->binding->bindingType == BINDING_SOAP) {
						sdlSoapBindingFunctionPtr fnb = (sdlSoapBindingFunctionPtr)h->function->bindingAttributes;
						if (fnb->style == SOAP_RPC) {
							hdr_func = hdr_func->children;
						}
					}
					deserialize_parameters(hdr_func, h->function, &h->num_params, &h->parameters);
				}
				INIT_ZVAL(h->retval);
				if (last == NULL) {
					*headers = h;
				} else {
					last->next = h;
				}
				last = h;
			}
ignore_header:
			trav = trav->next;
		}
	}

	if (function && function->binding && function->binding->bindingType == BINDING_SOAP) {
		sdlSoapBindingFunctionPtr fnb = (sdlSoapBindingFunctionPtr)function->bindingAttributes;
		if (fnb->style == SOAP_RPC) {
			func = func->children;
		}
	} else {
		func = func->children;
	}
	deserialize_parameters(func, function, num_params, parameters);
	return function;
}


static int serialize_response_call2(xmlNodePtr body, sdlFunctionPtr function, char *function_name, char *uri, zval *ret, int version, int main TSRMLS_DC)
{
	xmlNodePtr method = NULL, param;
	sdlParamPtr parameter = NULL;
	int param_count;
	int style, use;
	xmlNsPtr ns = NULL;

	if (function != NULL && function->binding->bindingType == BINDING_SOAP) {
		sdlSoapBindingFunctionPtr fnb = (sdlSoapBindingFunctionPtr)function->bindingAttributes;

		style = fnb->style;
		use = fnb->output.use;
		if (style == SOAP_RPC) {
			ns = encode_add_ns(body, fnb->output.ns);
			if (function->responseName) {
				method = xmlNewChild(body, ns, BAD_CAST(function->responseName), NULL);
			} else if (function->responseParameters) {
				method = xmlNewChild(body, ns, BAD_CAST(function->functionName), NULL);
			}
		}
	} else {
		style = main?SOAP_RPC:SOAP_DOCUMENT;
		use = main?SOAP_ENCODED:SOAP_LITERAL;
		if (style == SOAP_RPC) {
			ns = encode_add_ns(body, uri);
			method = xmlNewChild(body, ns, BAD_CAST(function_name), NULL);
		}
	}

	if (function != NULL) {
		if (function->responseParameters) {
			param_count = zend_hash_num_elements(function->responseParameters);
		} else {
		  param_count = 0;
		}
	} else {
	  param_count = 1;
	}

	if (param_count == 1) {
		parameter = get_param(function, NULL, 0, TRUE);

		if (style == SOAP_RPC) {
		  xmlNode *rpc_result;
			if (main && version == SOAP_1_2) {
				xmlNs *rpc_ns = xmlNewNs(body, BAD_CAST(RPC_SOAP12_NAMESPACE), BAD_CAST(RPC_SOAP12_NS_PREFIX));
				rpc_result = xmlNewChild(method, rpc_ns, BAD_CAST("result"), NULL);
				param = serialize_parameter(parameter, ret, 0, "return", use, method TSRMLS_CC);
				xmlNodeSetContent(rpc_result,param->name);
			} else {
				param = serialize_parameter(parameter, ret, 0, "return", use, method TSRMLS_CC);
			}
		} else {
			param = serialize_parameter(parameter, ret, 0, "return", use, body TSRMLS_CC);
			if (function && function->binding->bindingType == BINDING_SOAP) {
				if (parameter && parameter->element) {
					ns = encode_add_ns(param, parameter->element->namens);
					xmlNodeSetName(param, BAD_CAST(parameter->element->name));
					xmlSetNs(param, ns);
				}
			} else if (strcmp((char*)param->name,"return") == 0) {
				ns = encode_add_ns(param, uri);
				xmlNodeSetName(param, BAD_CAST(function_name));
				xmlSetNs(param, ns);
			}
		}
	} else if (param_count > 1 && Z_TYPE_P(ret) == IS_ARRAY) {
		HashPosition pos;
		zval **data;
		int i = 0;

		zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(ret), &pos);
		while (zend_hash_get_current_data_ex(Z_ARRVAL_P(ret), (void **)&data, &pos) != FAILURE) {
			char *param_name = NULL;
			unsigned int param_name_len;
			ulong param_index = i;

			zend_hash_get_current_key_ex(Z_ARRVAL_P(ret), &param_name, &param_name_len, &param_index, 0, &pos);
			parameter = get_param(function, param_name, param_index, TRUE);
			if (style == SOAP_RPC) {
				param = serialize_parameter(parameter, *data, i, param_name, use, method TSRMLS_CC);
			} else {
				param = serialize_parameter(parameter, *data, i, param_name, use, body TSRMLS_CC);
				if (function && function->binding->bindingType == BINDING_SOAP) {
					if (parameter && parameter->element) {
						ns = encode_add_ns(param, parameter->element->namens);
						xmlNodeSetName(param, BAD_CAST(parameter->element->name));
						xmlSetNs(param, ns);
					}
				}
			}

			zend_hash_move_forward_ex(Z_ARRVAL_P(ret), &pos);
			i++;
		}
	}
	if (use == SOAP_ENCODED && version == SOAP_1_2 && method != NULL) {
		xmlSetNsProp(method, body->ns, BAD_CAST("encodingStyle"), BAD_CAST(SOAP_1_2_ENC_NAMESPACE));
	}
	return use;
}

static xmlDocPtr serialize_response_call(sdlFunctionPtr function, char *function_name, char *uri, zval *ret, soapHeader* headers, int version TSRMLS_DC)
{
	xmlDocPtr doc;
	xmlNodePtr envelope = NULL, body, param;
	xmlNsPtr ns = NULL;
	int use = SOAP_LITERAL;
	xmlNodePtr head = NULL;

	encode_reset_ns();

	doc = xmlNewDoc(BAD_CAST("1.0"));
	doc->charset = XML_CHAR_ENCODING_UTF8;
	doc->encoding = xmlCharStrdup("UTF-8");

	if (version == SOAP_1_1) {
		envelope = xmlNewDocNode(doc, NULL, BAD_CAST("Envelope"), NULL);
		ns = xmlNewNs(envelope, BAD_CAST(SOAP_1_1_ENV_NAMESPACE), BAD_CAST(SOAP_1_1_ENV_NS_PREFIX));
		xmlSetNs(envelope,ns);
	} else if (version == SOAP_1_2) {
		envelope = xmlNewDocNode(doc, NULL, BAD_CAST("Envelope"), NULL);
		ns = xmlNewNs(envelope, BAD_CAST(SOAP_1_2_ENV_NAMESPACE), BAD_CAST(SOAP_1_2_ENV_NS_PREFIX));
		xmlSetNs(envelope,ns);
	} else {
		soap_server_fault("Server", "Unknown SOAP version", NULL, NULL, NULL TSRMLS_CC);
	}
	xmlDocSetRootElement(doc, envelope);

	if (Z_TYPE_P(ret) == IS_OBJECT &&
	    instanceof_function(Z_OBJCE_P(ret), ws_fault_class_entry TSRMLS_CC)) {
	  char *detail_name;
		HashTable* prop;
		zval **tmp;
		sdlFaultPtr fault = NULL;
		char *fault_ns = NULL;

		prop = Z_OBJPROP_P(ret);

		if (headers &&
		    zend_hash_find(prop, "headerfault", sizeof("headerfault"), (void**)&tmp) == SUCCESS) {
			xmlNodePtr head;
			encodePtr hdr_enc = NULL;
			int hdr_use = SOAP_LITERAL;
			zval *hdr_ret  = *tmp;
			char *hdr_ns   = headers->hdr?headers->hdr->ns:NULL;
			char *hdr_name = Z_STRVAL(headers->function_name);

			head = xmlNewChild(envelope, ns, BAD_CAST("Header"), NULL);
			if (Z_TYPE_P(hdr_ret) == IS_OBJECT &&
			    instanceof_function(Z_OBJCE_P(hdr_ret), ws_header_class_entry TSRMLS_CC)) {
				HashTable* ht = Z_OBJPROP_P(hdr_ret);
				zval **tmp;
				sdlSoapBindingFunctionHeaderPtr *hdr;
				smart_str key = {0};

				if (zend_hash_find(ht, "namespace", sizeof("namespace"), (void**)&tmp) == SUCCESS &&
			      Z_TYPE_PP(tmp) == IS_STRING) {
					smart_str_appendl(&key, Z_STRVAL_PP(tmp), Z_STRLEN_PP(tmp));
					smart_str_appendc(&key, ':');
					hdr_ns = Z_STRVAL_PP(tmp);
				}
				if (zend_hash_find(ht, "name", sizeof("name"), (void**)&tmp) == SUCCESS &&
				    Z_TYPE_PP(tmp) == IS_STRING) {
					smart_str_appendl(&key, Z_STRVAL_PP(tmp), Z_STRLEN_PP(tmp));
					hdr_name = Z_STRVAL_PP(tmp);
				}
				smart_str_0(&key);
				if (headers->hdr && headers->hdr->headerfaults &&
				    zend_hash_find(headers->hdr->headerfaults, key.c, key.len+1, (void**)&hdr) == SUCCESS) {
					hdr_enc = (*hdr)->encode;
					hdr_use = (*hdr)->use;
				}
				smart_str_free(&key);
				if (zend_hash_find(ht, "data", sizeof("data"), (void**)&tmp) == SUCCESS) {
					hdr_ret = *tmp;
				} else {
					hdr_ret = NULL;
				}
			}

			if (headers->function) {
				if (serialize_response_call2(head, headers->function, Z_STRVAL(headers->function_name), uri, hdr_ret, version, 0 TSRMLS_CC) == SOAP_ENCODED) {
					use = SOAP_ENCODED;
				}
			} else {
				xmlNodePtr xmlHdr = master_to_xml(hdr_enc, hdr_ret, hdr_use, head);
				if (hdr_name) {
					xmlNodeSetName(xmlHdr, BAD_CAST(hdr_name));
				}
				if (hdr_ns) {
					xmlNsPtr nsptr = encode_add_ns(xmlHdr, hdr_ns);
					xmlSetNs(xmlHdr, nsptr);
				}
			}
		}

		body = xmlNewChild(envelope, ns, BAD_CAST("Body"), NULL);
		param = xmlNewChild(body, ns, BAD_CAST("Fault"), NULL);

		if (zend_hash_find(prop, "faultcodens", sizeof("faultcodens"), (void**)&tmp) == SUCCESS && Z_TYPE_PP(tmp) == IS_STRING) {
			fault_ns = Z_STRVAL_PP(tmp);
		}
		use = SOAP_LITERAL;
		if (zend_hash_find(prop, "_name", sizeof("_name"), (void**)&tmp) == SUCCESS && Z_TYPE_PP(tmp) == IS_STRING) {
			sdlFaultPtr *tmp_fault;
			if (function && function->faults &&
			    zend_hash_find(function->faults, Z_STRVAL_PP(tmp), Z_STRLEN_PP(tmp)+1, (void**)&tmp_fault) == SUCCESS) {
			  fault = *tmp_fault;
				if (function->binding &&
				    function->binding->bindingType == BINDING_SOAP &&
				    fault->bindingAttributes) {
					sdlSoapBindingFunctionFaultPtr fb = (sdlSoapBindingFunctionFaultPtr)fault->bindingAttributes;
					use = fb->use;
					if (fault_ns == NULL) {
						fault_ns = fb->ns;
					}
				}
			}
		} else if (function && function->faults &&
		           zend_hash_num_elements(function->faults) == 1) {

			zend_hash_internal_pointer_reset(function->faults);
			zend_hash_get_current_data(function->faults, (void**)&fault);
			fault = *(sdlFaultPtr*)fault;
			if (function->binding &&
			    function->binding->bindingType == BINDING_SOAP &&
			    fault->bindingAttributes) {
				sdlSoapBindingFunctionFaultPtr fb = (sdlSoapBindingFunctionFaultPtr)fault->bindingAttributes;
				use = fb->use;
				if (fault_ns == NULL) {
				  fault_ns = fb->ns;
				}
			}
		}

		if (fault_ns == NULL &&
		    fault && 
		    fault->details && 
		    zend_hash_num_elements(fault->details) == 1) {
			sdlParamPtr sparam;

			zend_hash_internal_pointer_reset(fault->details);
			zend_hash_get_current_data(fault->details, (void**)&sparam);
			sparam = *(sdlParamPtr*)sparam;
			if (sparam->element) {
				fault_ns = sparam->element->namens;
			}
		}

		if (version == SOAP_1_1) {
			if (zend_hash_find(prop, "faultcode", sizeof("faultcode"), (void**)&tmp) == SUCCESS) {
				int new_len;
				xmlNodePtr node = xmlNewNode(NULL, BAD_CAST("faultcode"));
				char *str = php_escape_html_entities((unsigned char*)Z_STRVAL_PP(tmp), Z_STRLEN_PP(tmp), &new_len, 0, 0, NULL TSRMLS_CC);
				xmlAddChild(param, node);
				if (fault_ns) {
					xmlNsPtr nsptr = encode_add_ns(node, fault_ns);
					xmlChar *code = xmlBuildQName(BAD_CAST(str), nsptr->prefix, NULL, 0);
					xmlNodeSetContent(node, code);
					xmlFree(code);
				} else {	
					xmlNodeSetContentLen(node, BAD_CAST(str), new_len);
				}
				efree(str);
			}
			if (zend_hash_find(prop, "faultstring", sizeof("faultstring"), (void**)&tmp) == SUCCESS) {
				xmlNodePtr node = master_to_xml(get_conversion(IS_STRING), *tmp, SOAP_LITERAL, param);
				xmlNodeSetName(node, BAD_CAST("faultstring"));
			}
			if (zend_hash_find(prop, "faultactor", sizeof("faultactor"), (void**)&tmp) == SUCCESS) {
				xmlNodePtr node = master_to_xml(get_conversion(IS_STRING), *tmp, SOAP_LITERAL, param);
				xmlNodeSetName(node, BAD_CAST("faultactor"));
			}
			detail_name = "detail";
		} else {
			if (zend_hash_find(prop, "faultcode", sizeof("faultcode"), (void**)&tmp) == SUCCESS) {
				int new_len;
				xmlNodePtr node = xmlNewChild(param, ns, BAD_CAST("Code"), NULL);
				char *str = php_escape_html_entities((unsigned char*)Z_STRVAL_PP(tmp), Z_STRLEN_PP(tmp), &new_len, 0, 0, NULL TSRMLS_CC);
				node = xmlNewChild(node, ns, BAD_CAST("Value"), NULL);
				if (fault_ns) {
					xmlNsPtr nsptr = encode_add_ns(node, fault_ns);
					xmlChar *code = xmlBuildQName(BAD_CAST(str), nsptr->prefix, NULL, 0);
					xmlNodeSetContent(node, code);
					xmlFree(code);
				} else {	
					xmlNodeSetContentLen(node, BAD_CAST(str), new_len);
				}
				efree(str);
			}
			if (zend_hash_find(prop, "faultstring", sizeof("faultstring"), (void**)&tmp) == SUCCESS) {
				xmlNodePtr node = xmlNewChild(param, ns, BAD_CAST("Reason"), NULL);
				node = master_to_xml(get_conversion(IS_STRING), *tmp, SOAP_LITERAL, node);
				xmlNodeSetName(node, BAD_CAST("Text"));
				xmlSetNs(node, ns);
			}
			detail_name = SOAP_1_2_ENV_NS_PREFIX":Detail";
		}
		if (fault && fault->details && zend_hash_num_elements(fault->details) == 1) {
			xmlNodePtr node;
			zval *detail = NULL;
			sdlParamPtr sparam;
			xmlNodePtr x;

			if (zend_hash_find(prop, "detail", sizeof("detail"), (void**)&tmp) == SUCCESS &&
			    Z_TYPE_PP(tmp) != IS_NULL) {
				detail = *tmp;
			}
			node = xmlNewNode(NULL, BAD_CAST(detail_name));
			xmlAddChild(param, node);

			zend_hash_internal_pointer_reset(fault->details);
			zend_hash_get_current_data(fault->details, (void**)&sparam);
			sparam = *(sdlParamPtr*)sparam;

			if (detail &&
			    Z_TYPE_P(detail) == IS_OBJECT &&
			    sparam->element &&
			    zend_hash_num_elements(Z_OBJPROP_P(detail)) == 1 &&
			    zend_hash_find(Z_OBJPROP_P(detail), sparam->element->name, strlen(sparam->element->name)+1, (void**)&tmp) == SUCCESS) {
				detail = *tmp;
			}

			x = serialize_parameter(sparam, detail, 1, NULL, use, node TSRMLS_CC);

			if (function &&
			    function->binding &&
			    function->binding->bindingType == BINDING_SOAP &&
			    function->bindingAttributes) {
				sdlSoapBindingFunctionPtr fnb = (sdlSoapBindingFunctionPtr)function->bindingAttributes;
				if (fnb->style == SOAP_RPC && !sparam->element) {
				  if (fault->bindingAttributes) {
						sdlSoapBindingFunctionFaultPtr fb = (sdlSoapBindingFunctionFaultPtr)fault->bindingAttributes;
						if (fb->ns) {
							xmlNsPtr ns = encode_add_ns(x, fb->ns);
							xmlSetNs(x, ns);
						}
					}
				} else {
					if (sparam->element) {
						xmlNsPtr ns = encode_add_ns(x, sparam->element->namens);
						xmlNodeSetName(x, BAD_CAST(sparam->element->name));
						xmlSetNs(x, ns);
					}
				}
			}
			if (use == SOAP_ENCODED && version == SOAP_1_2) {
				xmlSetNsProp(x, envelope->ns, BAD_CAST("encodingStyle"), BAD_CAST(SOAP_1_2_ENC_NAMESPACE));
			}
		} else if (zend_hash_find(prop, "detail", sizeof("detail"), (void**)&tmp) == SUCCESS &&
		    Z_TYPE_PP(tmp) != IS_NULL) {
			serialize_zval(*tmp, NULL, detail_name, use, param TSRMLS_CC);
		}
	} else {

		if (headers) {
			soapHeader *h;

			head = xmlNewChild(envelope, ns, BAD_CAST("Header"), NULL);
			h = headers;
			while (h != NULL) {
				if (Z_TYPE(h->retval) != IS_NULL) {
					encodePtr hdr_enc = NULL;
					int hdr_use = SOAP_LITERAL;
					zval *hdr_ret = &h->retval;
					char *hdr_ns   = h->hdr?h->hdr->ns:NULL;
					char *hdr_name = Z_STRVAL(h->function_name);


					if (Z_TYPE(h->retval) == IS_OBJECT &&
					    instanceof_function(Z_OBJCE(h->retval), ws_header_class_entry TSRMLS_CC)) {
						HashTable* ht = Z_OBJPROP(h->retval);
						zval **tmp;
						sdlSoapBindingFunctionHeaderPtr *hdr;
						smart_str key = {0};

						if (zend_hash_find(ht, "namespace", sizeof("namespace"), (void**)&tmp) == SUCCESS &&
					      Z_TYPE_PP(tmp) == IS_STRING) {
							smart_str_appendl(&key, Z_STRVAL_PP(tmp), Z_STRLEN_PP(tmp));
							smart_str_appendc(&key, ':');
							hdr_ns = Z_STRVAL_PP(tmp);
						}
						if (zend_hash_find(ht, "name", sizeof("name"), (void**)&tmp) == SUCCESS &&
						    Z_TYPE_PP(tmp) == IS_STRING) {
							smart_str_appendl(&key, Z_STRVAL_PP(tmp), Z_STRLEN_PP(tmp));
							hdr_name = Z_STRVAL_PP(tmp);
						}
						smart_str_0(&key);
						if (function && function->binding && function->binding->bindingType == BINDING_SOAP) {
							sdlSoapBindingFunctionPtr fnb = (sdlSoapBindingFunctionPtr)function->bindingAttributes;

							if (fnb->output.headers &&
							    zend_hash_find(fnb->output.headers, key.c, key.len+1, (void**)&hdr) == SUCCESS) {
								hdr_enc = (*hdr)->encode;
								hdr_use = (*hdr)->use;
							}
						}
						smart_str_free(&key);
						if (zend_hash_find(ht, "data", sizeof("data"), (void**)&tmp) == SUCCESS) {
							hdr_ret = *tmp;
						} else {
							hdr_ret = NULL;
						}
					}

					if (h->function) {
						if (serialize_response_call2(head, h->function, Z_STRVAL(h->function_name), uri, hdr_ret, version, 0 TSRMLS_CC) == SOAP_ENCODED) {
							use = SOAP_ENCODED;
						}
					} else {
						xmlNodePtr xmlHdr = master_to_xml(hdr_enc, hdr_ret, hdr_use, head);
						if (hdr_name) {
							xmlNodeSetName(xmlHdr, BAD_CAST(hdr_name));
						}
						if (hdr_ns) {
							xmlNsPtr nsptr = encode_add_ns(xmlHdr,hdr_ns);
							xmlSetNs(xmlHdr, nsptr);
						}
					}
				}
				h = h->next;
			}

			if (head->children == NULL) {
				xmlUnlinkNode(head);
				xmlFreeNode(head);
			}
		}

		body = xmlNewChild(envelope, ns, BAD_CAST("Body"), NULL);

		if (serialize_response_call2(body, function, function_name, uri, ret, version, 1 TSRMLS_CC) == SOAP_ENCODED) {
			use = SOAP_ENCODED;
		}

	}

	if (use == SOAP_ENCODED) {
		xmlNewNs(envelope, BAD_CAST(XSD_NAMESPACE), BAD_CAST(XSD_NS_PREFIX));
		if (version == SOAP_1_1) {
			xmlNewNs(envelope, BAD_CAST(SOAP_1_1_ENC_NAMESPACE), BAD_CAST(SOAP_1_1_ENC_NS_PREFIX));
			xmlSetNsProp(envelope, envelope->ns, BAD_CAST("encodingStyle"), BAD_CAST(SOAP_1_1_ENC_NAMESPACE));
		} else if (version == SOAP_1_2) {
			xmlNewNs(envelope, BAD_CAST(SOAP_1_2_ENC_NAMESPACE), BAD_CAST(SOAP_1_2_ENC_NS_PREFIX));
		}
	}

	if (function && function->responseName == NULL && 
	    body->children == NULL && head == NULL) {
		xmlFreeDoc(doc);
		return NULL;
	}
	return doc;
}



static xmlNodePtr serialize_parameter(sdlParamPtr param, zval *param_val, int index, char *name, int style, xmlNodePtr parent TSRMLS_DC)
{
	char *paramName;
	xmlNodePtr xmlParam;
	char paramNameBuf[10];

	if (param_val &&
	    Z_TYPE_P(param_val) == IS_OBJECT &&
	    Z_OBJCE_P(param_val) == ws_param_class_entry) {
		zval **param_name;
		zval **param_data;

		if (zend_hash_find(Z_OBJPROP_P(param_val), "param_name", sizeof("param_name"), (void **)&param_name) == SUCCESS &&
		    zend_hash_find(Z_OBJPROP_P(param_val), "param_data", sizeof("param_data"), (void **)&param_data) == SUCCESS) {
			param_val = *param_data;
			name = Z_STRVAL_PP(param_name);
		}
	}

	if (param != NULL && param->paramName != NULL) {
		paramName = param->paramName;
	} else {
		if (name == NULL) {
			paramName = paramNameBuf;
			sprintf(paramName,"param%d",index);
		} else {
			paramName = name;
		}
	}
	/* php_printf("%s", paramName); */
	xmlParam = serialize_zval(param_val, param, paramName, style, parent TSRMLS_CC);

	return xmlParam;
}

static xmlNodePtr serialize_zval(zval *val, sdlParamPtr param, char *paramName, int style, xmlNodePtr parent TSRMLS_DC)
{
	xmlNodePtr xmlParam;
	encodePtr enc;
	zval defval;

	if (param != NULL) {
		enc = param->encode;
		if (val == NULL) {
			if (param->element) {
				if (param->element->fixed) {
					ZVAL_STRING(&defval, param->element->fixed, 0);
					val = &defval;
				} else if (param->element->def && !param->element->nillable) {
					ZVAL_STRING(&defval, param->element->def, 0);
					val = &defval;
				}
			}
		}
	} else {
		enc = NULL;
	}
	xmlParam = master_to_xml(enc, val, style, parent);
	if (!strcmp((char*)xmlParam->name, "BOGUS")) {
		xmlNodeSetName(xmlParam, BAD_CAST(paramName));
	}
	return xmlParam;
}

static sdlParamPtr get_param(sdlFunctionPtr function, char *param_name, int index, int response)
{
	sdlParamPtr *tmp;
	HashTable   *ht;

	if (function == NULL) {
		return NULL;
	}

	if (response == FALSE) {
		ht = function->requestParameters;
	} else {
		ht = function->responseParameters;
	}

	if (ht == NULL) {
	  return NULL;
	}

	if (param_name != NULL) {
		if (zend_hash_find(ht, param_name, strlen(param_name), (void **)&tmp) != FAILURE) {
			return *tmp;
		} else {
			HashPosition pos;
		
			zend_hash_internal_pointer_reset_ex(ht, &pos);
			while (zend_hash_get_current_data_ex(ht, (void **)&tmp, &pos) != FAILURE) {
				if ((*tmp)->paramName && strcmp(param_name, (*tmp)->paramName) == 0) {
					return *tmp;
				}
				zend_hash_move_forward_ex(ht, &pos);
			}
		}
	} else {
		if (zend_hash_index_find(ht, index, (void **)&tmp) != FAILURE) {
			return (*tmp);
		}
	}
	return NULL;
}

static sdlFunctionPtr get_function(sdlPtr sdl, const char *function_name)
{
	sdlFunctionPtr *tmp;

	int len = strlen(function_name);
	char *str = estrndup(function_name,len);
	php_strtolower(str,len);
	if (sdl != NULL) {
		if (zend_hash_find(&sdl->functions, str, len+1, (void **)&tmp) != FAILURE) {
			efree(str);
			return (*tmp);
		} else if (sdl->requests != NULL && zend_hash_find(sdl->requests, str, len+1, (void **)&tmp) != FAILURE) {
			efree(str);
			return (*tmp);
		}
	}
	efree(str);
	return NULL;
}

static sdlFunctionPtr get_doc_function(sdlPtr sdl, xmlNodePtr params)
{
	if (sdl) {
		sdlFunctionPtr *tmp;
		sdlParamPtr    *param;

		zend_hash_internal_pointer_reset(&sdl->functions);
		while (zend_hash_get_current_data(&sdl->functions, (void**)&tmp) == SUCCESS) {
			if ((*tmp)->binding && (*tmp)->binding->bindingType == BINDING_SOAP) {
				sdlSoapBindingFunctionPtr fnb = (sdlSoapBindingFunctionPtr)(*tmp)->bindingAttributes;
				if (fnb->style == SOAP_DOCUMENT) {
					if (params == NULL) {
						if ((*tmp)->requestParameters == NULL ||
						    zend_hash_num_elements((*tmp)->requestParameters) == 0) {
						  return *tmp;
						}
					} else if ((*tmp)->requestParameters != NULL &&
					           zend_hash_num_elements((*tmp)->requestParameters) > 0) {
						int ok = 1;
						xmlNodePtr node = params;

						zend_hash_internal_pointer_reset((*tmp)->requestParameters);
						while (zend_hash_get_current_data((*tmp)->requestParameters, (void**)&param) == SUCCESS) {
							if ((*param)->element) {
								if (strcmp((*param)->element->name, (char*)node->name) != 0) {
									ok = 0;
									break;
								}
								if ((*param)->element->namens != NULL && node->ns != NULL) {
									if (strcmp((*param)->element->namens, (char*)node->ns->href) != 0) {
										ok = 0;
										break;
									}
								} else if ((void*)(*param)->element->namens != (void*)node->ns) {
									ok = 0;
									break;
								}
							} else if (strcmp((*param)->paramName, (char*)node->name) != 0) {
								ok = 0;
								break;
							}
							zend_hash_move_forward((*tmp)->requestParameters);
						}
						if (ok /*&& node == NULL*/) {
							return (*tmp);
						}
					}
				}
			}
			zend_hash_move_forward(&sdl->functions);
		}
	}
	return NULL;
}

void function_to_string(sdlFunctionPtr function, smart_str *buf)
{
	int i = 0;
	HashPosition pos;
	sdlParamPtr *param;

	if (function->responseParameters &&
	    zend_hash_num_elements(function->responseParameters) > 0) {
		if (zend_hash_num_elements(function->responseParameters) == 1) {
			zend_hash_internal_pointer_reset(function->responseParameters);
			zend_hash_get_current_data(function->responseParameters, (void**)&param);
			if ((*param)->encode && (*param)->encode->details.type_str) {
				smart_str_appendl(buf, (*param)->encode->details.type_str, strlen((*param)->encode->details.type_str));
				smart_str_appendc(buf, ' ');
			} else {
				smart_str_appendl(buf, "UNKNOWN ", 8);
			}
		} else {
			i = 0;
			smart_str_appendl(buf, "list(", 5);
			zend_hash_internal_pointer_reset_ex(function->responseParameters, &pos);
			while (zend_hash_get_current_data_ex(function->responseParameters, (void **)&param, &pos) != FAILURE) {
				if (i > 0) {
					smart_str_appendl(buf, ", ", 2);
				}
				if ((*param)->encode && (*param)->encode->details.type_str) {
					smart_str_appendl(buf, (*param)->encode->details.type_str, strlen((*param)->encode->details.type_str));
				} else {
					smart_str_appendl(buf, "UNKNOWN", 7);
				}
				smart_str_appendl(buf, " $", 2);
				smart_str_appendl(buf, (*param)->paramName, strlen((*param)->paramName));
				zend_hash_move_forward_ex(function->responseParameters, &pos);
				i++;
			}
			smart_str_appendl(buf, ") ", 2);
		}
	} else {
		smart_str_appendl(buf, "void ", 5);
	}

	smart_str_appendl(buf, function->functionName, strlen(function->functionName));

	smart_str_appendc(buf, '(');
	if (function->requestParameters) {
		i = 0;
		zend_hash_internal_pointer_reset_ex(function->requestParameters, &pos);
		while (zend_hash_get_current_data_ex(function->requestParameters, (void **)&param, &pos) != FAILURE) {
			if (i > 0) {
				smart_str_appendl(buf, ", ", 2);
			}
			if ((*param)->encode && (*param)->encode->details.type_str) {
				smart_str_appendl(buf, (*param)->encode->details.type_str, strlen((*param)->encode->details.type_str));
			} else {
				smart_str_appendl(buf, "UNKNOWN", 7);
			}
			smart_str_appendl(buf, " $", 2);
			smart_str_appendl(buf, (*param)->paramName, strlen((*param)->paramName));
			zend_hash_move_forward_ex(function->requestParameters, &pos);
			i++;
		}
	}
	smart_str_appendc(buf, ')');
	smart_str_0(buf);
}

static void model_to_string(sdlContentModelPtr model, smart_str *buf, int level)
{
	int i;

	switch (model->kind) {
		case XSD_CONTENT_ELEMENT:
			type_to_string(model->u.element, buf, level);
			smart_str_appendl(buf, ";\n", 2);
			break;
		case XSD_CONTENT_ANY:
			for (i = 0;i < level;i++) {
				smart_str_appendc(buf, ' ');
			}
			smart_str_appendl(buf, "<anyXML> any;\n", sizeof("<anyXML> any;\n")-1);
			break;
		case XSD_CONTENT_SEQUENCE:
		case XSD_CONTENT_ALL:
		case XSD_CONTENT_CHOICE: {
			sdlContentModelPtr *tmp;

			zend_hash_internal_pointer_reset(model->u.content);
			while (zend_hash_get_current_data(model->u.content, (void**)&tmp) == SUCCESS) {
				model_to_string(*tmp, buf, level);
				zend_hash_move_forward(model->u.content);
			}
			break;
		}
		case XSD_CONTENT_GROUP:
			model_to_string(model->u.group->model, buf, level);
		default:
		  break;
	}
}

static void type_to_string(sdlTypePtr type, smart_str *buf, int level)
{
	int i;
	smart_str spaces = {0};
	HashPosition pos;

	for (i = 0;i < level;i++) {
		smart_str_appendc(&spaces, ' ');
	}
	smart_str_appendl(buf, spaces.c, spaces.len);

	switch (type->kind) {
		case XSD_TYPEKIND_SIMPLE:
		case XSD_TYPEKIND_LIST:
		case XSD_TYPEKIND_UNION:
			if (type->encode) {
				smart_str_appendl(buf, type->encode->details.type_str, strlen(type->encode->details.type_str));
				smart_str_appendc(buf, ' ');
			} else {
				smart_str_appendl(buf, "anyType ", sizeof("anyType ")-1);
			}
			smart_str_appendl(buf, type->name, strlen(type->name));
			break;
		case XSD_TYPEKIND_COMPLEX:
		case XSD_TYPEKIND_RESTRICTION:
		case XSD_TYPEKIND_EXTENSION:
			if (type->encode &&
			    (type->encode->details.type == IS_ARRAY ||
			     type->encode->details.type == SOAP_ENC_ARRAY)) {
			  sdlAttributePtr *attr;
			  sdlExtraAttributePtr *ext;

				if (type->attributes &&
				    zend_hash_find(type->attributes, SOAP_1_1_ENC_NAMESPACE":arrayType",
				      sizeof(SOAP_1_1_ENC_NAMESPACE":arrayType"),
				      (void **)&attr) == SUCCESS &&
				      zend_hash_find((*attr)->extraAttributes, WSDL_NAMESPACE":arrayType", sizeof(WSDL_NAMESPACE":arrayType"), (void **)&ext) == SUCCESS) {
					char *end = strchr((*ext)->val, '[');
					int len;
					if (end == NULL) {
						len = strlen((*ext)->val);
					} else {
						len = end-(*ext)->val;
					}
					if (len == 0) {
						smart_str_appendl(buf, "anyType", sizeof("anyType")-1);
					} else {
						smart_str_appendl(buf, (*ext)->val, len);
					}
					smart_str_appendc(buf, ' ');
					smart_str_appendl(buf, type->name, strlen(type->name));
					if (end != NULL) {
						smart_str_appends(buf, end);
					}
				} else {
					sdlTypePtr elementType;
					if (type->attributes &&
					    zend_hash_find(type->attributes, SOAP_1_2_ENC_NAMESPACE":itemType",
					      sizeof(SOAP_1_2_ENC_NAMESPACE":itemType"),
					      (void **)&attr) == SUCCESS &&
					      zend_hash_find((*attr)->extraAttributes, WSDL_NAMESPACE":itemType", sizeof(WSDL_NAMESPACE":arrayType"), (void **)&ext) == SUCCESS) {
						smart_str_appends(buf, (*ext)->val);
						smart_str_appendc(buf, ' ');
					} else if (type->elements &&
					           zend_hash_num_elements(type->elements) == 1 &&
					           (zend_hash_internal_pointer_reset(type->elements),
					            zend_hash_get_current_data(type->elements, (void**)&elementType) == SUCCESS) &&
					           (elementType = *(sdlTypePtr*)elementType) != NULL &&
					           elementType->encode && elementType->encode->details.type_str) {
						smart_str_appends(buf, elementType->encode->details.type_str);
						smart_str_appendc(buf, ' ');
					} else {
						smart_str_appendl(buf, "anyType ", 8);
					}
					smart_str_appendl(buf, type->name, strlen(type->name));
					if (type->attributes &&
					    zend_hash_find(type->attributes, SOAP_1_2_ENC_NAMESPACE":arraySize",
					      sizeof(SOAP_1_2_ENC_NAMESPACE":arraySize"),
					      (void **)&attr) == SUCCESS &&
					      zend_hash_find((*attr)->extraAttributes, WSDL_NAMESPACE":itemType", sizeof(WSDL_NAMESPACE":arraySize"), (void **)&ext) == SUCCESS) {
						smart_str_appendc(buf, '[');
						smart_str_appends(buf, (*ext)->val);
						smart_str_appendc(buf, ']');
					} else {
						smart_str_appendl(buf, "[]", 2);
					}
				}
			} else {
				smart_str_appendl(buf, "struct ", 7);
				smart_str_appendl(buf, type->name, strlen(type->name));
				smart_str_appendc(buf, ' ');
				smart_str_appendl(buf, "{\n", 2);
				if ((type->kind == XSD_TYPEKIND_RESTRICTION ||
				     type->kind == XSD_TYPEKIND_EXTENSION) && type->encode) {
					encodePtr enc = type->encode;
					while (enc && enc->details.sdl_type &&
					       enc != enc->details.sdl_type->encode &&
					       enc->details.sdl_type->kind != XSD_TYPEKIND_SIMPLE &&
					       enc->details.sdl_type->kind != XSD_TYPEKIND_LIST &&
					       enc->details.sdl_type->kind != XSD_TYPEKIND_UNION) {
						enc = enc->details.sdl_type->encode;
					}
					if (enc) {
						smart_str_appendl(buf, spaces.c, spaces.len);
						smart_str_appendc(buf, ' ');
						smart_str_appendl(buf, type->encode->details.type_str, strlen(type->encode->details.type_str));
						smart_str_appendl(buf, " _;\n", 4);
					}
				}
				if (type->model) {
					model_to_string(type->model, buf, level+1);
				}
				if (type->attributes) {
					sdlAttributePtr *attr;

					zend_hash_internal_pointer_reset_ex(type->attributes, &pos);
					while (zend_hash_get_current_data_ex(type->attributes, (void **)&attr, &pos) != FAILURE) {
						smart_str_appendl(buf, spaces.c, spaces.len);
						smart_str_appendc(buf, ' ');
						if ((*attr)->encode && (*attr)->encode->details.type_str) {
							smart_str_appends(buf, (*attr)->encode->details.type_str);
							smart_str_appendc(buf, ' ');
						} else {
							smart_str_appendl(buf, "UNKNOWN ", 8);
						}
						smart_str_appends(buf, (*attr)->name);
						smart_str_appendl(buf, ";\n", 2);
						zend_hash_move_forward_ex(type->attributes, &pos);
					}
				}
				smart_str_appendl(buf, spaces.c, spaces.len);
				smart_str_appendc(buf, '}');
			}
			break;
		default:
			break;
	}
	smart_str_free(&spaces);
	smart_str_0(buf);
}

zval* add_soap_fault(zval *obj, char *fault_code, char *fault_string, char *fault_actor, zval *fault_detail TSRMLS_DC){
    return NULL;
}

soapServicePtr create_soap_service(HashTable *ht TSRMLS_DC){
	
	soapServicePtr service;
	zval **tmp;
	char *wsdl = NULL;
	HashTable *typemap_ht = NULL;
	int cache_wsdl;

	if(!ht)
		return NULL;

	if(zend_hash_find(ht, "wsdl", sizeof("wsdl"), (void**)&tmp) == SUCCESS){
		wsdl = Z_STRVAL_PP(tmp);				
	}else{
		return NULL;
	}
	
	service = emalloc(sizeof(soapService));
	memset(service, 0, sizeof(soapService));
	
	if (zend_hash_find(ht, "wsdl", sizeof("wsdl"), (void**)&tmp) == SUCCESS &&
		    Z_TYPE_PP(tmp) == IS_STRING) {
				wsdl = Z_STRVAL_PP(tmp);
	}
	if (zend_hash_find(ht, "uri", sizeof("uri"), (void**)&tmp) == SUCCESS &&
		    Z_TYPE_PP(tmp) == IS_STRING) {
			service->uri = estrndup(Z_STRVAL_PP(tmp), Z_STRLEN_PP(tmp));
	} else if (wsdl == NULL) {
			php_error_docref(NULL TSRMLS_CC, E_ERROR, "Invalid arguments. 'uri' option is required in nonWSDL mode.");
			return NULL;
	}

	if (zend_hash_find(ht, "actor", sizeof("actor"), (void**)&tmp) == SUCCESS &&
		    Z_TYPE_PP(tmp) == IS_STRING) {
			service->actor = estrndup(Z_STRVAL_PP(tmp), Z_STRLEN_PP(tmp));
	}

	if (zend_hash_find(ht, "encoding", sizeof("encoding"), (void**)&tmp) == SUCCESS &&
		    Z_TYPE_PP(tmp) == IS_STRING) {
		xmlCharEncodingHandlerPtr encoding;
		
		encoding = xmlFindCharEncodingHandler(Z_STRVAL_PP(tmp));
	   	if (encoding == NULL) {
				php_error_docref(NULL TSRMLS_CC, E_ERROR, "Invalid arguments. Invalid 'encoding' option - '%s'.", Z_STRVAL_PP(tmp));
	    } else {
	      service->encoding = encoding;
	    }
	}

	if (zend_hash_find(ht, "classmap", sizeof("classmap"), (void**)&tmp) == SUCCESS &&
		Z_TYPE_PP(tmp) == IS_ARRAY) {
		zval *ztmp;

		ALLOC_HASHTABLE(service->class_map);
		zend_hash_init(service->class_map, zend_hash_num_elements((*tmp)->value.ht), NULL, ZVAL_PTR_DTOR, 0);
		zend_hash_copy(service->class_map, (*tmp)->value.ht, (copy_ctor_func_t) zval_add_ref, (void *) &ztmp, sizeof(zval *));
	}

	if (zend_hash_find(ht, "typemap", sizeof("typemap"), (void**)&tmp) == SUCCESS &&
		Z_TYPE_PP(tmp) == IS_ARRAY &&
		zend_hash_num_elements(Z_ARRVAL_PP(tmp)) > 0) {
		typemap_ht = Z_ARRVAL_PP(tmp);
	}

	if (zend_hash_find(ht, "features", sizeof("features"), (void**)&tmp) == SUCCESS &&
		Z_TYPE_PP(tmp) == IS_LONG) {
		service->features = Z_LVAL_PP(tmp);
	}

	if (zend_hash_find(ht, "cache_wsdl", sizeof("cache_wsdl"), (void**)&tmp) == SUCCESS &&
	    Z_TYPE_PP(tmp) == IS_LONG) {
		cache_wsdl = Z_LVAL_PP(tmp);
	}
	return service;
}


void delete_service(void *data)
{
    soapServicePtr service = (soapServicePtr)data;

    if (service->soap_functions.ft) {
        zend_hash_destroy(service->soap_functions.ft);
        efree(service->soap_functions.ft);
    }

    if (service->typemap) {
        zend_hash_destroy(service->typemap);
        efree(service->typemap);
    }

    if (service->soap_class.argc) {
        int i;
        for (i = 0; i < service->soap_class.argc;i++) {
            zval_ptr_dtor(&service->soap_class.argv[i]);
        }
        efree(service->soap_class.argv);
    }

    if (service->actor) {
        efree(service->actor);
    }
    if (service->uri) {
        efree(service->uri);
    }
    if (service->sdl) {
        delete_sdl(service->sdl);
    }
    if (service->encoding) {
        xmlCharEncCloseFunc(service->encoding);
    }
    if (service->class_map) {
        zend_hash_destroy(service->class_map);
        FREE_HASHTABLE(service->class_map);
    }
    if (service->soap_object) {
        zval_ptr_dtor(&service->soap_object);
    }
    efree(service);
}

void wsf_soap_get_functions(zval *this_ptr,
                            zval *return_value,
                            axutil_env_t *env
                            TSRMLS_CC)
{
    zval **tmp = NULL;
    zval *client_zval = NULL;
    sdlPtr sdl;
    HashPosition pos;

    if(instanceof_function(Z_OBJCE_P(this_ptr), ws_client_proxy_class_entry TSRMLS_CC)){
        if(zend_hash_find(Z_OBJPROP_P(this_ptr), "wsclient", sizeof("wsclient"), (void**)&tmp) == SUCCESS){
            client_zval = *tmp;
        }else{
            php_error_docref(NULL TSRMLS_CC, E_ERROR," proxy created without wsclient");
            return;
        }
    }else if(instanceof_function(Z_OBJCE_P(this_ptr), ws_client_class_entry TSRMLS_CC)){
            client_zval = this_ptr;
    }
    
    if (FIND_SDL_PROPERTY(client_zval,tmp) != FAILURE) {
            FETCH_SDL_RES(sdl,tmp);
                }
    if (sdl) {
        smart_str buf = {0};
        sdlFunctionPtr *function;

        array_init(return_value);
        zend_hash_internal_pointer_reset_ex(&sdl->functions, &pos);

        while (zend_hash_get_current_data_ex(&sdl->functions, (void **)&function, &pos) != FAILURE) {
            function_to_string((*function), &buf);
            add_next_index_stringl(return_value, buf.c, buf.len,  1);
            smart_str_free(&buf);
            zend_hash_move_forward_ex(&sdl->functions, &pos);
        }
    }
}
void wsf_soap_get_types(zval *this_ptr,
                            zval *return_value,
                            axutil_env_t *env
                            TSRMLS_CC)
{
    zval **tmp = NULL;
    zval *client_zval = NULL;
    sdlPtr sdl;
    HashPosition pos;
    
    if(instanceof_function(Z_OBJCE_P(this_ptr), ws_client_proxy_class_entry TSRMLS_CC)){
        if(zend_hash_find(Z_OBJPROP_P(this_ptr), "wsclient", sizeof("wsclient"), (void**)&tmp) == SUCCESS){
            client_zval = *tmp;
        }else{
            php_error_docref(NULL TSRMLS_CC, E_ERROR," proxy created without wsclient");
            return;
        }
    }else if(instanceof_function(Z_OBJCE_P(this_ptr), ws_client_class_entry TSRMLS_CC)){
        client_zval = this_ptr;
    }
    
    if (FIND_SDL_PROPERTY(client_zval,tmp) != FAILURE) {
        FETCH_SDL_RES(sdl,tmp);
    }

    if (sdl) {
        sdlTypePtr *type;
        smart_str buf = {0};
        
        array_init(return_value);
        if (sdl->types) {
            zend_hash_internal_pointer_reset_ex(sdl->types, &pos);
            while (zend_hash_get_current_data_ex(sdl->types, (void **)&type, &pos) != FAILURE) {
                type_to_string((*type), &buf, 0);
                add_next_index_stringl(return_value, buf.c, buf.len, 1);
                zend_hash_move_forward_ex(sdl->types, &pos);
                smart_str_free(&buf);
            }
        }
    }
    
}

void wsf_soap_get_location(zval *this_ptr,
                            zval *return_value,
                            axutil_env_t *env
                            TSRMLS_CC)
{
    zval **tmp = NULL;
    zval *client_zval = NULL;
    sdlPtr sdl;
    char *location = NULL;
    sdlFunctionPtr *f_val = NULL;
    sdlFunctionPtr fn;
    char *f_name = NULL;
    sdlBindingPtr binding;
    
    if(instanceof_function(Z_OBJCE_P(this_ptr), ws_client_proxy_class_entry TSRMLS_CC)){
        if(zend_hash_find(Z_OBJPROP_P(this_ptr), "wsclient", sizeof("wsclient"), (void**)&tmp) == SUCCESS){
            client_zval = *tmp;
        }else{
            php_error_docref(NULL TSRMLS_CC, E_ERROR," proxy created without wsclient");
            return;
        }
    }else if(instanceof_function(Z_OBJCE_P(this_ptr), ws_client_class_entry TSRMLS_CC)){
        client_zval = this_ptr;
    }
    
    if (FIND_SDL_PROPERTY(client_zval,tmp) != FAILURE) {
        FETCH_SDL_RES(sdl,tmp);
    }

    if (sdl != NULL) {
        if (&sdl->functions) {
            zend_hash_internal_pointer_reset(&sdl->functions);
            while(zend_hash_get_current_data(&sdl->functions, (void **)&f_val) != FAILURE) {
                f_name = (*f_val)->functionName;
                zend_hash_move_forward(&sdl->functions);
            }
            if (f_name != NULL) {
                fn = get_function(sdl, f_name);
                if (fn != NULL) 
                    binding = fn->binding;
                if (binding)
                    location = binding->location;
                if (location)
                {
                    array_init(return_value);
                    add_next_index_stringl(return_value, location, strlen(location), 1);
                }
            }
        }
    }
}



axis2_bool_t 
wsf_soap_do_function_call(const axutil_env_t *env,
          wsf_svc_info_t *svc_info,
          axis2_msg_ctx_t *in_msg_ctx,
          axis2_msg_ctx_t *out_msg_ctx,
          char *op_name TSRMLS_DC)
{
    xmlDocPtr doc_request, doc_return;
    zval function_name,  **params;
    zval func,  retval; 
    int num_params =0, soap_version , call_status;
    sdlFunctionPtr function;

    soapHeader *soap_headers = NULL;
    soapServicePtr service;
    axiom_soap_envelope_t *soap_envelope = NULL, *res_soap_envelope = NULL;
    axiom_node_t *soap_envelope_node = NULL;
    axis2_char_t *soap_version_uri = NULL;

    char *buff = NULL;
    int length = 0;

    if(!in_msg_ctx || !op_name)
        return AXIS2_FAILURE;
    
    if(axis2_msg_ctx_get_is_soap_11(in_msg_ctx, env) == AXIS2_TRUE){
        soap_version = SOAP_1_1;
        soap_version_uri = AXIOM_SOAP11_SOAP_ENVELOPE_NAMESPACE_URI;
    }else{
        soap_version = SOAP_1_2;
        soap_version_uri = AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI;
    }
    
    soap_envelope = axis2_msg_ctx_get_soap_envelope(in_msg_ctx, env); 
    
    if(!soap_envelope)
        return AXIS2_FAILURE;

    soap_envelope_node = axiom_soap_envelope_get_base_node(soap_envelope, env);

    buff = axiom_node_to_string(soap_envelope_node, env);
    length = strlen(buff);


    doc_request = soap_xmlParseMemory(buff, length);

    service = (soapServicePtr)svc_info->service;

    function = deserialize_function_call(service->sdl, doc_request, 
            service->actor, &function_name, &num_params, 
            &params, &soap_version, &soap_headers TSRMLS_CC);

    xmlFreeDoc(doc_request);    

    ZVAL_STRING(&func, op_name, 0);
    call_status = call_user_function(CG(function_table) , (zval**)NULL, &func, &retval, num_params, params TSRMLS_CC);

    if (call_status == SUCCESS) {
        char *response_name;
        /*
        if (Z_TYPE(retval) == IS_OBJECT &&
            instanceof_function(Z_OBJCE(retval), soap_fault_class_entry TSRMLS_CC)) {
            php_end_ob_buffer(0, 0 TSRMLS_CC);
            soap_server_fault_ex(function, &retval, NULL TSRMLS_CC);
            goto fail;
        }
        */
        if (function && function->responseName) {
            response_name = estrdup(function->responseName);
        } else {
            response_name = emalloc(Z_STRLEN(function_name) + sizeof("Response"));
            memcpy(response_name,Z_STRVAL(function_name),Z_STRLEN(function_name));
            memcpy(response_name+Z_STRLEN(function_name),"Response",sizeof("Response"));
        }
        doc_return = serialize_response_call(function, response_name, 
                service->uri, &retval, soap_headers, soap_version TSRMLS_CC);
        efree(response_name);
    } else {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "Function '%s' call failed", Z_STRVAL(function_name));
    }

    res_soap_envelope = create_soap_envelope_from_doc(doc_return, env, soap_version_uri);

    axis2_msg_ctx_set_soap_envelope(out_msg_ctx, env, res_soap_envelope);

    return AXIS2_SUCCESS;
}



axis2_bool_t 
wsf_soap_do_function_call1(const axutil_env_t *env,
          wsf_svc_info_t *svc_info, zval *this_ptr,int soap_version, void *buff, int length TSRMLS_DC)
{
    xmlDocPtr doc_request, doc_return;
    zval function_name,  **params;
    zval func,  retval; 
    int num_params =0, call_status;
    sdlFunctionPtr function;

    soapHeader *soap_headers = NULL;
    soapServicePtr service;


    doc_request = soap_xmlParseMemory((char*)buff, length);

    service = (soapServicePtr)svc_info->service;

    function = deserialize_function_call(service->sdl, doc_request, 
            service->actor, &function_name, &num_params, 
            &params, &soap_version, &soap_headers TSRMLS_CC);

    xmlFreeDoc(doc_request);    

    ZVAL_STRING(&func, Z_STRVAL(function_name), 0);
    call_status = call_user_function(CG(function_table) , (zval**)NULL, &func, &retval, num_params, params TSRMLS_CC);

    if (call_status == SUCCESS) {
        char *response_name;
        /*
        if (Z_TYPE(retval) == IS_OBJECT &&
            instanceof_function(Z_OBJCE(retval), soap_fault_class_entry TSRMLS_CC)) {
            php_end_ob_buffer(0, 0 TSRMLS_CC);
            soap_server_fault_ex(function, &retval, NULL TSRMLS_CC);
            goto fail;
        }
        */
        if (function && function->responseName) {
            response_name = estrdup(function->responseName);
        } else {
            response_name = emalloc(Z_STRLEN(function_name) + sizeof("Response"));
            memcpy(response_name,Z_STRVAL(function_name),Z_STRLEN(function_name));
            memcpy(response_name+Z_STRLEN(function_name),"Response",sizeof("Response"));
        }
        doc_return = serialize_response_call(function, response_name, 
                service->uri, &retval, soap_headers, soap_version TSRMLS_CC);
        efree(response_name);
    } else {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "Function '%s' call failed", Z_STRVAL(function_name));
    }

    return AXIS2_SUCCESS;
}





















