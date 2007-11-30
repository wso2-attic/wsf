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

#include <axutil_dll_desc.h>
#include <axis2_msg_recv.h>
#include <axutil_class_loader.h>
#include "wsf_worker.h"
#include "wsf_xml_msg_recv.h"
#include <axis2_http_transport.h>
#include <axis2_addr.h>
#include "wsf_util.h"
#include <axutil_error_default.h>
#include <axutil_log_default.h>
#include <axutil_uuid_gen.h>
#include <axiom_util.h>
#include <axis2_http_client.h>

#include <ruby.h>

/*
xmlNodePtr
wsf_util_get_xml_node (
    zval * node TSRMLS_DC)
{
    php_libxml_node_object *object;
    xmlNodePtr nodep;

    object =
        (php_libxml_node_object *) zend_object_store_get_object (node
        TSRMLS_CC);
    nodep = php_libxml_import_node (node TSRMLS_CC);
    if (!nodep) {
        return NULL;
    }
    if (nodep->doc == NULL) {
        php_error_docref (NULL TSRMLS_CC, E_WARNING,
            "Imported Node must have \
							associated Document");
        return NULL;
    }
    if (nodep->type == XML_DOCUMENT_NODE
        || nodep->type == XML_HTML_DOCUMENT_NODE) {
        nodep = xmlDocGetRootElement ((xmlDocPtr) nodep);
    }
    return nodep;
}
*/

/*
char *
wsf_util_read_file_to_buffer (
    char *filename TSRMLS_DC)
{
    char *contents;
    php_stream *stream;
    int len;
    long maxlen = PHP_STREAM_COPY_ALL;
    zval *zcontext = NULL;
    php_stream_context *context = NULL;

    context = php_stream_context_from_zval (zcontext, 0);

    stream = php_stream_open_wrapper_ex (filename, "rb",
        (USE_PATH) | ENFORCE_SAFE_MODE | REPORT_ERRORS, NULL, context);
    if (!stream) {
        return NULL;
    }

    len = php_stream_copy_to_mem (stream, &contents, maxlen, 0);

    php_stream_close (stream);

    if (len <= 0) {
        return NULL;
    }
    return contents;
}
*/

/*
axiom_node_t *
wsf_util_construct_header_node (
    const axutil_env_t * env,
    zval * header TSRMLS_DC)
{
    char *ns = NULL;
    char *localname = NULL;
    char prefix[6];
    axiom_namespace_t *header_ns = NULL;
    axiom_node_t *header_node = NULL;
    axiom_element_t *header_ele = NULL;
    axiom_namespace_t *soap_ns = NULL;
    int must_understand = 0;

    zval **tmp = NULL;


    AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
        " [wsf_log] construct header node ");

    if (zend_hash_find (Z_OBJPROP_P (header), WS_HEADER_LOCALNAME,
            sizeof (WS_HEADER_LOCALNAME), (void **) &tmp) == SUCCESS) {
        localname = Z_STRVAL_PP (tmp);
    } else {
        return NULL;
    }
    if (zend_hash_find (Z_OBJPROP_P (header), WS_HEADER_NS,
            sizeof (WS_HEADER_NS), (void **) &tmp) == SUCCESS
        && Z_TYPE_PP (tmp) == IS_STRING) {
        ns = Z_STRVAL_PP (tmp);
    } else {
        return NULL;
    }

    sprintf (prefix, "ns%d", WSF_GLOBAL (curr_ns_index)++);
    header_ns = axiom_namespace_create (env, ns, prefix);
    header_ele =
        axiom_element_create (env, NULL, localname, header_ns, &header_node);

    if (zend_hash_find (Z_OBJPROP_P (header), WS_HEADER_MUST_UNDERSTAND,
            sizeof (WS_HEADER_MUST_UNDERSTAND), (void **) &tmp) == SUCCESS
        && Z_TYPE_PP (tmp) == IS_BOOL) {
        axiom_attribute_t *mu_attr = NULL;
        char must_val[2];

        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
            "[wsf_client] must understand value is set");

        must_understand = Z_BVAL_PP (tmp);
        sprintf (must_val, "%d", must_understand);
        soap_ns =
            axiom_namespace_create (env, WSF_GLOBAL (soap_uri), "soapenv");
        mu_attr =
            axiom_attribute_create (env, "mustUnderstand", must_val, soap_ns);
        axiom_element_add_attribute (header_ele, env, mu_attr, header_node);
    }
    if (zend_hash_find (Z_OBJPROP_P (header), WS_HEADER_ROLE,
            sizeof (WS_HEADER_ROLE), (void **) &tmp) == SUCCESS) {
        axiom_attribute_t *role_attr = NULL;
        char *role_val = NULL;
        if (Z_TYPE_PP (tmp) == IS_LONG) {
            if (Z_LVAL_PP (tmp) == WS_SOAP_ROLE_NEXT) {
                role_val = WS_SOAP_ROLE_NEXT_URI;
            } else if (Z_LVAL_PP (tmp) == WS_SOAP_ROLE_NONE) {
                role_val = WS_SOAP_ROLE_NONE_URI;
            } else if (Z_LVAL_PP (tmp) == WS_SOAP_ROLE_ULTIMATE_RECEIVER) {
                role_val = WS_SOAP_ROLE_ULTIMATE_RECEIVER_URI;
            }
        } else if (Z_TYPE_PP (tmp) == IS_STRING) {
            role_val = Z_STRVAL_PP (tmp);
        }
        if (!soap_ns)
            soap_ns =
                axiom_namespace_create (env, WSF_GLOBAL (soap_uri),
                "soapenv");
        
        if (WSF_GLOBAL (soap_version) == AXIOM_SOAP12 && role_val) {
            role_attr = axiom_attribute_create (env, WS_HEADER_ROLE,
                role_val, soap_ns);
            axiom_element_add_attribute (header_ele, env, role_attr,
                header_node);
        } else if (WSF_GLOBAL (soap_version) == AXIOM_SOAP11 && role_val) {
            role_attr = axiom_attribute_create (env, WS_HEADER_ACTOR,
                role_val, soap_ns);
            axiom_element_add_attribute (header_ele, env, role_attr,
                header_node);
        }
    }
    if (zend_hash_find (Z_OBJPROP_P (header), WS_HEADER_DATA,
            sizeof (WS_HEADER_DATA), (void **) &tmp) == SUCCESS
        && Z_TYPE_PP (tmp) == IS_STRING) {
        axiom_element_set_text (header_ele, env, Z_STRVAL_PP (tmp),
            header_node);
    }

    return header_node;
}
*/


/*
static void WSF_CALL
wsf_free_wrapper_cli (
    axutil_allocator_t * allocator,
    void *ptr)
{
    if (ptr)
        pefree (ptr, 1);
}
*/


/* 
static void *WSF_CALL
wsf_malloc_wrapper_cli (
    axutil_allocator_t * allocator,
    size_t size)
{
    return pemalloc (size, 1);
}
*/

/* 
static void *WSF_CALL
wsf_realloc_warpper_cli (
    axutil_allocator_t * allocator,
    void *ptr,
    size_t size)
{
    return perealloc (ptr, size, 1);
}

*/

static void *WSF_CALL
wsf_malloc_wrapper (
    axutil_allocator_t * allocator,
    size_t size)
{
    return ruby_xmalloc(size);
}

static void *WSF_CALL
wsf_realloc_warpper (
    axutil_allocator_t * allocator,
    void *ptr,
    size_t size)
{
    return ruby_xrealloc(ptr, size);
}


static void WSF_CALL
wsf_free_wrapper (
    axutil_allocator_t * allocator,
    void *ptr)
{
    ruby_xfree(ptr);
}


/* }}} */
/* {{{ axis2_environment create function */
axutil_env_t *
wsf_env_create_svr (
    axis2_char_t * path_tolog, int loglevel)
{
    axutil_allocator_t *allocator = NULL;
    axutil_error_t *error = NULL;
    axutil_log_t *log = NULL;
    axis2_char_t log_path[250];
    axutil_env_t *env = NULL;
    axutil_thread_pool_t *thread_pool = NULL;
    const axis2_char_t *LOG_NAME = "wsf_ruby_server.log";
    allocator = malloc (sizeof (axutil_allocator_t));

    allocator->free_fn = wsf_free_wrapper;
    allocator->malloc_fn = wsf_malloc_wrapper;
    allocator->realloc = wsf_realloc_warpper;

    error = axutil_error_create (allocator);
    if (path_tolog && (
            (0 == strcmp (path_tolog, "")) ||
            (0 == strcmp (path_tolog, ".")) ||
            (0 == strcmp (path_tolog, "./")))) {
        snprintf (log_path, 256, "%s", LOG_NAME);
    } else {
        snprintf (log_path, 256, "%s/%s", path_tolog, LOG_NAME);
    }

    thread_pool = axutil_thread_pool_init (allocator);
    log = axutil_log_create (allocator, NULL, log_path);
    env = axutil_env_create_with_error_log_thread_pool (allocator, error, log,
        thread_pool);

    env->log->level = loglevel;
    return env;
}

/* }}} */

void
wsf_env_free (
    axutil_env_t * env)
{

}

wsf_svc_info_t *
wsf_svc_info_create (
    axutil_env_t * env)
{
    wsf_svc_info_t *svc_info = NULL;
    svc_info = AXIS2_MALLOC (env->allocator, sizeof (wsf_svc_info_t));

    svc_info->svc = NULL;
    svc_info->svc_name = NULL;
    svc_info->is_class = 0;
    svc_info->msg_recv = NULL;
    svc_info->ruby_worker = NULL;
    svc_info->use_mtom = 0;     /* default is false otherwise service side will send MIME
                                   headers which some servers can;t handle */
    svc_info->request_xop = 0;  /* default false */
    /* svc_info->policy = NULL; */
    /* svc_info->security_token = NULL; */

    svc_info->ops_to_functions = NULL;
    svc_info->ops_to_classes = NULL;
    svc_info->ops_to_actions = NULL;
    svc_info->modules_to_engage = NULL;
    svc_info->service = NULL;
    svc_info->op_name = NULL;
    return svc_info;
}

/* free svc info struct */
void
wsf_svc_info_free (
    wsf_svc_info_t * svc_info,
    axutil_env_t * env)
{
    if (NULL != svc_info) {
        if (svc_info->svc_name) {
            AXIS2_FREE (env->allocator, svc_info->svc_name);
            svc_info->svc_name = NULL;
        }
        if (svc_info->ops_to_functions) {
            axutil_hash_free (svc_info->ops_to_functions, env);
        }
        if (svc_info->ops_to_actions) {
            axutil_hash_free (svc_info->ops_to_actions, env);
        }
        if (svc_info->modules_to_engage) {
            axutil_array_list_free (svc_info->modules_to_engage, env);
        }
        if (svc_info->op_name != NULL) {
            AXIS2_FREE (env->allocator, svc_info->op_name);
        }
        AXIS2_FREE (env->allocator, svc_info);
    }
}

/** create ruby request info struct */
void 
wsf_ruby_req_info_init (wsf_req_info_t *req_info)
{
    /*
    wsf_req_info_t *req_info = NULL;
    req_info = emalloc (sizeof (wsf_req_info_t));
    */
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
    req_info->query_string = NULL;
	req_info->out_content_type = NULL;

    return;
}

void
wsf_ruby_req_info_cleanup (
    wsf_req_info_t * req_info,
	axutil_env_t *env)
{
	/* note request info is not malloced, so should not be freed */
    if (req_info) {
		if(req_info->result_payload){
			/* This is always allocated by axis2 */
			AXIS2_FREE(env->allocator, req_info->result_payload);
		}
		if(req_info->out_content_type){
			AXIS2_FREE(env->allocator, req_info->out_content_type);
			req_info->out_content_type = NULL;
		}
    }
}

/* {{{ ws_read_payload */
axiom_node_t *
wsf_util_read_payload (
    axiom_xml_reader_t * reader,
    const axutil_env_t * env)
{
    axiom_stax_builder_t *builder = NULL;
    axiom_document_t *document = NULL;
    axiom_node_t *payload = NULL;

    builder = axiom_stax_builder_create (env, reader);

    if (!builder) {
        return NULL;
    }

    document = axiom_stax_builder_get_document (builder, env);

    if (!document) {
        return NULL;
    }

    payload = axiom_document_get_root_element (document, env);

    if (!payload) {
        return NULL;
    }
    axiom_document_build_all (document, env);

    /** free stax builder and associated document only */
    axiom_stax_builder_free_self (builder, env);

    return payload;
}

/* }}} ws_read_payload */

axis2_char_t *
wsf_util_get_soap_msg_from_op_client (
    axis2_op_client_t * op_client,
    axutil_env_t * env,
    axis2_wsdl_msg_labels_t msg_label)
{
    if (op_client) {
        axiom_soap_envelope_t *soap_env = NULL;
        const axis2_msg_ctx_t *msg_ctx = NULL;
        axiom_node_t *node = NULL;

        msg_ctx = axis2_op_client_get_msg_ctx (op_client, env, msg_label);
        if (!msg_ctx)
            return NULL;
        soap_env = axis2_msg_ctx_get_soap_envelope (msg_ctx, env);
        if (!soap_env)
            return NULL;
        node = axiom_soap_envelope_get_base_node (soap_env, env);
        return axiom_node_to_string (node, env);
    }
    return NULL;
}

axis2_char_t *
wsf_util_get_http_headers_from_op_client (
    axis2_op_client_t * op_client,
    axutil_env_t * env,
    axis2_wsdl_msg_labels_t msg_label)
{
    if (op_client) {
        const axis2_msg_ctx_t *msg_ctx = NULL;
        axutil_property_t *client_property = NULL;
        axis2_http_client_t *client = NULL;
        axis2_http_simple_response_t *response = NULL;
        axutil_array_list_t *list = NULL;
        axis2_http_header_t *header = NULL;
        int i;
        char *header_buf = NULL;

        msg_ctx = axis2_op_client_get_msg_ctx (op_client, env, msg_label);
        if (!msg_ctx)
            return NULL;
        client_property =
            (axutil_property_t *) axis2_msg_ctx_get_property (msg_ctx, env,
            AXIS2_HTTP_CLIENT);

        if (client_property)
            client =
                (axis2_http_client_t *)
                axutil_property_get_value (client_property, env);
        else
            return NULL;

        if (client && (msg_label == AXIS2_WSDL_MESSAGE_LABEL_OUT)) {
            response = axis2_http_client_get_response (client, env);
            if (response)
                list = axis2_http_simple_response_get_headers (response, env);
            else
                return NULL;
        }

        if (list) {
            header_buf = malloc (500);
            if (!axutil_array_list_is_empty (list, env)) {
                for (i = 0; i < axutil_array_list_size (list, env); i++) {
                    header =
                        (axis2_http_header_t *) axutil_array_list_get (list,
                        env, i);
                    strcat (header_buf,
                        axis2_http_header_to_external_form (header, env));
                }
                return header_buf;
            }
        }

    }
    return NULL;
}

int
wsf_util_engage_module (
    axis2_conf_t * conf,
    axis2_char_t * module_name,
    axutil_env_t * env,
    axis2_svc_t * svc)
{
    axis2_module_desc_t *module = NULL;
    axutil_qname_t *mod_qname = NULL;
    axis2_phase_resolver_t *phase_resolver = NULL;
    int status = AXIS2_FAILURE;

    mod_qname = axutil_qname_create (env, module_name, NULL, NULL);
    module = axis2_conf_get_module (conf, env, mod_qname);
    if (module) {
        status = axis2_svc_engage_module (svc, env, module, conf);
        if (!status) {
            phase_resolver =
                axis2_phase_resolver_create_with_config (env, conf);
            if (!phase_resolver) {
                AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                    " [wsf-log] PHASE RESLOVER NULL");
                return AXIS2_FAILURE;
            }
            status =
                axis2_phase_resolver_engage_module_to_svc (phase_resolver,
                env, svc, module);
        }
    }
    return status;
}

/* genarate service name from uri */
char *
wsf_util_generate_svc_name_from_uri (
    char *req_uri,
    wsf_svc_info_t * svc_info,
    axutil_env_t * env)
{
	char *svc_name = NULL;
    char *temp_string = NULL;
    char *index = NULL;
    char *uri = NULL;
    int i;

    if (strncmp (req_uri, "/", 1) == 0) {
        /* start with a / */
        uri = req_uri + 1;
    } else {
        uri = req_uri;
    }

    temp_string = axutil_strdup(env, uri);

    /* index = rindex(temp_string, '/'); */
    for(i = axutil_strlen(temp_string) -1; i> 0; i--)
    {
	if(temp_string[i] == '/')
	{
	    break;
	}
    }

    if (i > 0) {
        char *op_index = NULL;
        op_index = temp_string + i + 1;
        temp_string[index - temp_string] = '\0';
        svc_info->op_name = axutil_strdup (env, op_index);
    }

    svc_name = axutil_replace (env, temp_string, '/', '|');

    AXIS2_FREE(env->allocator, temp_string);

    return svc_name;

}

/* create service */
void
wsf_util_create_svc_from_svc_info (
    wsf_svc_info_t * svc_info,
    axutil_env_t * env)
{
    axutil_qname_t *svc_qname = NULL;
    axis2_svc_t *svc = NULL;
    axis2_conf_t *conf = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;

    if (!svc_info->ruby_worker) {
        /* php_error_docref (NULL TSRMLS_CC, E_ERROR, "error creating service"); */
        return;
    }

    conf_ctx = wsf_worker_get_conf_ctx (svc_info->ruby_worker, env);

    conf = axis2_conf_ctx_get_conf (conf_ctx, env);
    if (!conf) {
        /* php_error_docref (NULL TSRMLS_CC, E_ERROR, "error creating qname"); */
        return;
    }

    svc = axis2_conf_get_svc (conf, env, svc_info->svc_name);

    if (NULL != svc) {

        svc_info->svc = svc;

    } else {
        svc_qname = axutil_qname_create (env, svc_info->svc_name, NULL, NULL);
        svc_info->svc = axis2_svc_create_with_qname (env, svc_qname);
        axutil_qname_free (svc_qname, env);
    }
    return;
}

/* create operation */
/* CHANGED */
void
wsf_util_create_op_and_add_to_svc (
    wsf_svc_info_t * svc_info,
    char *action,
    axutil_env_t * env,
    char *op_name,
    VALUE ht_mep)
{
    axis2_svc_t *svc = NULL;
    axis2_op_t *op = NULL;
    axutil_qname_t *op_qname = NULL;
    op_qname = axutil_qname_create (env, op_name, NULL, NULL);
    svc = svc_info->svc;

    if (NULL != svc && NULL != op_name) {
        op = axis2_svc_get_op_with_name (svc_info->svc, env, op_name);
        if (!op) {
            axis2_conf_t *conf = NULL;
            axis2_conf_ctx_t *conf_ctx = NULL;
            axis2_phases_info_t *info = NULL;

            op_qname = axutil_qname_create (env, op_name, NULL, NULL);

            op = axis2_op_create_with_qname (env, op_qname);

            axis2_op_set_msg_recv (op, env, svc_info->msg_recv);

            conf_ctx = wsf_worker_get_conf_ctx (svc_info->ruby_worker, env);

            conf = axis2_conf_ctx_get_conf (conf_ctx, env);

            info = axis2_conf_get_phases_info (conf, env);
            axis2_phases_info_set_op_phases (info, env, op);
            axis2_svc_add_op (svc_info->svc, env, op);

            if (ht_mep) {
                  char operation[300];
                  VALUE mep_value;
                  char *mep;

                  AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                    "[wsf_service] ht mep not null, %s", op_name);
                  sprintf (operation, "%s", op_name);
                  if(TYPE(ht_mep) == T_HASH)
                  {
                    mep_value = rb_hash_aref(ht_mep, ID2SYM(rb_intern(operation)));
                  }
                  if(mep_value == Qnil)
                  {
                     mep = RSTRING(mep_value)->ptr;
                     if (mep) {
                        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                            "[wsf_service] op mep %s", mep);
                        if (strcmp (mep, "IN_ONLY") == 0) {
                            axis2_op_set_msg_exchange_pattern (op, env,
                                AXIS2_MEP_URI_IN_ONLY);
                            AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                                "[wsf_service] AXIS2_MEP_URI_IN_ONLY");

                        } else if (strcmp (mep, "IN_OUT") == 0) {
                            axis2_op_set_msg_exchange_pattern (op, env,
                                AXIS2_MEP_URI_IN_OUT);
                            AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                                "[wsf_service] AXIS2_MEP_URI_IN_OUT");
                        }
                     }
                  }
                  else {
                    AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                        "[wsf service] message exchange pattern for %s not found",
                        op_name);
                  }
            }
            if (action) {
                axis2_svc_add_mapping (svc_info->svc, env, action, op);
            }
        }
    }
	if(op_qname){
		axutil_qname_free(op_qname, env);
	}

    return;
}

/*
void
wsf_util_set_attachments_with_cids (
    const axutil_env_t * env,
    int enable_mtom,
    axiom_node_t * payload_node,
    HashTable * attach_ht,
    char *default_cnt_type TSRMLS_DC)
{
    axiom_node_t *node = NULL;
    axiom_node_t *tmp_node = NULL;
    axiom_element_t *payload_element = NULL;
    axiom_element_t *ele = NULL;
    if (!payload_node || !attach_ht)
        return;

    if (axiom_node_get_node_type (payload_node, env) == AXIOM_ELEMENT) {
        payload_element =
            (axiom_element_t *) axiom_node_get_data_element (payload_node,
            env);
        axiom_element_get_first_element (payload_element, env, payload_node,
            &node);

        if (node && axiom_node_get_node_type (node, env) == AXIOM_ELEMENT) {

            ele = (axiom_element_t *) axiom_node_get_data_element (node, env);
            if (ele) {
                axiom_namespace_t *ns = NULL;
                axis2_char_t *ns_uri = NULL;
                axis2_char_t *ele_localname = NULL;
                ele_localname = axiom_element_get_localname (ele, env);
                if (ele_localname
                    && axutil_strcmp (ele_localname, "Include") == 0) {
                    ns = axiom_element_get_namespace (ele, env, node);
                    if (ns && (ns_uri = axiom_namespace_get_uri (ns, env)) &&
                        axutil_strcmp (ns_uri,
                            "http://www.w3.org/2004/08/xop/include") == 0) {
                        axis2_char_t *cnt_type = NULL;
                        // found a matching xop include element
                        axis2_char_t *cid = NULL;
                        axis2_char_t *pos = NULL;
                        axis2_char_t *id = NULL;
                        zval **tmp = NULL;
                        // look for content type in parent
                        cnt_type =
                            axiom_element_get_attribute_value_by_name
                            (payload_element, env, "xmlmime:contentType");
                        if (!cnt_type)
                            cnt_type = default_cnt_type;

                        id = axiom_element_get_attribute_value_by_name (ele,
                            env, "href");
                        if (!id)
                            return;
                        pos = axutil_strstr (id, "cid:");
                        if (pos) {
                            cid = id + 4;
                            if (zend_hash_find (attach_ht, cid,
                                    strlen (cid) + 1,
                                    (void **) &tmp) == SUCCESS
                                && Z_TYPE_PP (tmp) == IS_STRING) {

                                void *binary_data = NULL;
                                int binary_data_len = 0;

                                binary_data_len = Z_STRLEN_PP (tmp);
                                binary_data =
                                    AXIS2_MALLOC (env->allocator,
                                    sizeof (char) * binary_data_len);
                                memcpy (binary_data, Z_STRVAL_PP (tmp),
                                    binary_data_len);
                                if (binary_data) {
                                    // detach this node
                                    axiom_node_t *text_node = NULL;
                                    axiom_text_t *text = NULL;
                                    axiom_data_handler_t *data_handler = NULL;
                                    axiom_node_detach (node, env);
                                    data_handler =
                                        axiom_data_handler_create (env, NULL,
                                        cnt_type);
                                    axiom_data_handler_set_binary_data
                                        (data_handler, env, binary_data,
                                        binary_data_len);
                                    text =
                                        axiom_text_create_with_data_handler
                                        (env, payload_node, data_handler,
                                        &text_node);

                                    if (enable_mtom == AXIS2_FALSE) {
                                        axiom_text_set_optimize (text, env,
                                            AXIS2_FALSE);
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
    tmp_node = axiom_node_get_first_child (payload_node, env);
    while (tmp_node) {
        wsf_util_set_attachments_with_cids (env, enable_mtom, tmp_node,
            attach_ht, default_cnt_type TSRMLS_CC);
        tmp_node = axiom_node_get_next_sibling (tmp_node, env);
    }
    return;
}
*/

/*************************/
/*
int
wsf_util_get_attachments (
    const axutil_env_t * env,
    axiom_node_t * om_node,
    zval * cid2str,
    zval * cid2contentType TSRMLS_DC)
{
    axiom_node_t *temp_node = NULL;
    axiom_node_t *nodes[256];
    int count = 0;
    int attachments_found = 0;

    if (!om_node)
    {
        return 0;
    }

    nodes[count++] = om_node;


    do {
		if (axiom_node_get_node_type(om_node, env) == AXIOM_TEXT) {
			axiom_text_t *text = NULL;
			axiom_data_handler_t *data_handler = NULL;
			
			
			text = (axiom_text_t*)axiom_node_get_data_element(om_node, env);
			if(text) {
				data_handler = axiom_text_get_data_handler (text, env);
        if (data_handler) 
        {
                        char *cnt_type = NULL;
                        char *data = NULL;
                        int data_len = 0;
    					char *cid = NULL;
    
              axiom_data_handler_read_from (data_handler, env, &data, &data_len);
              cnt_type = axiom_data_handler_get_content_type(data_handler, env);
    	      cid = axiom_text_get_content_id(text, env);
    		  //add_assoc_stringl (cid2str, cid, data, data_len, 1);
              //            attachments_found = 1;
              //if (cnt_type) 
              //{
              //              add_assoc_stringl (cid2contentType, cid, 
              //                  cnt_type, strlen (cnt_type), 1);
              //}
        }			
			}
    }
        temp_node = axiom_node_get_first_child(om_node, env);
        if (temp_node)
        {
            om_node = temp_node;
            nodes[count++] = om_node;
        }
        else
        {
            temp_node = axiom_node_get_next_sibling(om_node, env);
            if (temp_node)
            {
                om_node = temp_node;
                nodes[count -1] = om_node;
            }
            else
            {
                while (count > 1 && !temp_node)
                {
                    count--;
                    om_node = nodes[count -1];
                    temp_node = axiom_node_get_next_sibling(om_node, env);
                }
               
                if (temp_node && count > 1)
                {
                    om_node = temp_node;
                    nodes[count -1] = om_node;
                }
                else
                {
                    count--;
                }
            }
        }
    } while(count > 0);
    
    return attachments_found;
}
*/

/***************************/


char *
wsf_util_serialize_om (
    const axutil_env_t * env,
    axiom_node_t * ret_node)
{
    axiom_xml_writer_t *writer = NULL;
    axiom_output_t *om_output = NULL;
    axis2_char_t *buffer = NULL, *new_buffer = NULL;
    unsigned int buffer_len = 0;

    writer = axiom_xml_writer_create_for_memory (env, NULL, AXIS2_TRUE, 0,
        AXIS2_XML_PARSER_TYPE_BUFFER);
    om_output = axiom_output_create (env, writer);

    axiom_node_serialize (ret_node, env, om_output);
    buffer = (axis2_char_t *) axiom_xml_writer_get_xml (writer, env);
    buffer_len = axutil_strlen (buffer);

    new_buffer =
        AXIS2_MALLOC (env->allocator,
        sizeof (axis2_char_t) * (buffer_len + 1));
    memcpy (new_buffer, buffer, buffer_len);
    new_buffer[buffer_len] = '\0';

	axiom_output_free(om_output, env);

    return new_buffer;
}

/*
xmlDocPtr
wsf_util_serialize_om_to_doc (
    const axutil_env_t * env,
    axiom_node_t * ret_node)
{
    axiom_xml_writer_t *writer = NULL;
    axiom_output_t *om_output = NULL;
    xmlDocPtr doc = NULL;

    writer = axiom_xml_writer_create_for_memory (env,
        NULL, AXIS2_TRUE, 0, AXIS2_XML_PARSER_TYPE_DOC);
    om_output = axiom_output_create (env, writer);
    axiom_node_serialize (ret_node, env, om_output);
    doc = (xmlDocPtr) axiom_xml_writer_get_xml (writer, env);
    return doc;
}
*/

axiom_node_t *
wsf_util_deserialize_buffer (
    const axutil_env_t * env,
    char *buffer)
{
    axiom_xml_reader_t *reader = NULL;
    axiom_stax_builder_t *builder = NULL;
    axiom_document_t *document = NULL;
    axiom_node_t *payload = NULL;

    reader =
        axiom_xml_reader_create_for_memory (env, buffer,
        axutil_strlen (buffer), "utf-8", AXIS2_XML_PARSER_TYPE_BUFFER);
    if (!reader) {
        return NULL;
    }

    builder = axiom_stax_builder_create (env, reader);

    if (!builder) {
        return NULL;
    }
    document = axiom_stax_builder_get_document (builder, env);
    if (!document) {
        AXIS2_LOG_ERROR (env->log, AXIS2_LOG_SI, "Document is not found");
        return NULL;
    }

    payload = axiom_document_get_root_element (document, env);

    if (!payload) {
        AXIS2_LOG_ERROR (env->log, AXIS2_LOG_SI,
            "Root element of the document \
				is not found");
        return NULL;
    }
    axiom_document_build_all (document, env);
  
	  axiom_stax_builder_free_self (builder, env);

    return payload;
}

/*
void
wsf_util_get_contents_from_file (
    zval * return_value,
    char *filename,
    int filename_len TSRMLS_DC)
{
    char *contents;
    php_stream *stream;
    int len;
    long maxlen = PHP_STREAM_COPY_ALL;
    zval *zcontext = NULL;
    php_stream_context *context = NULL;
    char *DELIMITER = "-----";

    context = php_stream_context_from_zval (zcontext, 0);

    stream = php_stream_open_wrapper_ex (filename, "rb",
        (USE_PATH) | ENFORCE_SAFE_MODE | REPORT_ERRORS, NULL, context);
    if (!stream) {
        ZVAL_BOOL (return_value, 0);
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

        ZVAL_STRINGL (return_value, key, strlen (key), 0);
    } else if (len == 0) {
        ZVAL_EMPTY_STRING (return_value);
    } else {
        ZVAL_BOOL (return_value, 0);
    }
    php_stream_close (stream);
}
*/

/*
void
wsf_util_set_soap_fault (
    zval * this_ptr,
    char *fault_code_ns,
    char *fault_code,
    char *fault_reason,
    char *fault_role,
    zval * fault_detail,
    char *name)
{
    if (!this_ptr)
        return;

    if (fault_reason != NULL) {
        add_property_string (this_ptr, WS_FAULT_REASON, fault_reason, 1);

    }
    if (fault_code != NULL) {
        int soap_version = WSF_GLOBAL (soap_version);

        if (fault_code_ns) {
            add_property_string (this_ptr, WS_FAULT_CODE, fault_code, 1);
            add_property_string (this_ptr, WS_FAULT_CODE_NS, fault_code_ns,
                1);
        } else {
            if (soap_version == AXIOM_SOAP11) {
                add_property_string (this_ptr, WS_FAULT_CODE, fault_code, 1);
                if (strcmp (fault_code, "Client") == 0 ||
                    strcmp (fault_code, "Server") == 0 ||
                    strcmp (fault_code, "VersionMismatch") == 0 ||
                    strcmp (fault_code, "MustUnderstand") == 0) {
                    add_property_string (this_ptr, WS_FAULT_CODE_NS,
                        WS_SOAP_1_1_NAMESPACE_URI, 1);
                }
            } else if (soap_version == AXIOM_SOAP12) {
                if (strcmp (fault_code, "Client") == 0) {
                    add_property_string (this_ptr, WS_FAULT_CODE, "Sender",
                        1);
                    add_property_string (this_ptr, WS_FAULT_CODE_NS,
                        WS_SOAP_1_2_NAMESPACE_URI, 1);
                } else if (strcmp (fault_code, "Server") == 0) {
                    add_property_string (this_ptr, WS_FAULT_CODE, "Receiver",
                        1);
                    add_property_string (this_ptr, WS_FAULT_CODE_NS,
                        WS_SOAP_1_1_NAMESPACE_URI, 1);
                } else if (strcmp (fault_code, "VersionMismatch") == 0
                    || strcmp (fault_code, "MustUnderstand") == 0
                    || strcmp (fault_code, "DataEncodingUnknown") == 0) {
                    add_property_string (this_ptr, WS_FAULT_CODE, fault_code,
                        1);
                    add_property_string (this_ptr, WS_FAULT_CODE_NS,
                        WS_SOAP_1_2_NAMESPACE_URI, 1);
                } else {
                    add_property_string (this_ptr, WS_FAULT_CODE, fault_code,
                        1);
                }
            }
        }
    }
    if (fault_role != NULL) {
        add_property_string (this_ptr, WS_FAULT_ROLE, fault_role, 1);
    }
    if (fault_detail != NULL) {
        add_property_zval (this_ptr, WS_FAULT_DETAIL, fault_detail);
    }
    if (name != NULL) {
        add_property_string (this_ptr, "_name", name, 1);
    }
}
*/

/*
void
wsf_set_soap_fault_properties (
    axutil_env_t * env,
    axiom_soap_fault_t * soap_fault,
    zval * zval_ws_fault TSRMLS_DC)
{
    if (soap_fault) {

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

        sf_code = axiom_soap_fault_get_code (soap_fault, env);
        if (sf_code) {
            sf_code_node = axiom_soap_fault_code_get_base_node (sf_code, env);
            if (sf_code_node) {
                fault_code = axiom_node_to_string (sf_code_node, env);
                add_property_string (zval_ws_fault, "code", fault_code, 1);
            }
        }
        sf_reason = axiom_soap_fault_get_reason (soap_fault, env);
        if (sf_reason) {
            sf_reason_node =
                axiom_soap_fault_reason_get_base_node (sf_reason, env);
            if (sf_reason_node) {
                fault_reason = axiom_node_to_string (sf_reason_node, env);
                add_property_string (zval_ws_fault, "reason", fault_reason,
                    1);
            }
        }
        sf_role = axiom_soap_fault_get_role (soap_fault, env);
        if (sf_role) {
            sf_role_node = axiom_soap_fault_role_get_base_node (sf_role, env);
            if (sf_role_node) {
                fault_role = axiom_node_to_string (sf_role_node, env);
                add_property_string (zval_ws_fault, "role", fault_role, 1);
            }
        }
        sf_detail = axiom_soap_fault_get_detail (soap_fault, env);
        if (sf_detail) {
            sf_detail_node =
                axiom_soap_fault_detail_get_base_node (sf_detail, env);
            if (sf_detail_node) {
                fault_detail = axiom_node_to_string (sf_detail_node, env);
                add_property_string (zval_ws_fault, "detail", fault_detail,
                    1);
            }
        }
    }
	
}
*/

/*
static void 
wsf_util_handle_fault_code(
   zval *fault_obj,
   axiom_node_t *code_node,
   axiom_element_t *code_element,
   axutil_env_t *env, 
   int soap_version)
{
    axiom_node_t *code_value_node = NULL;
    axiom_element_t *code_value_ele = NULL;
    char *code = NULL;
	if(soap_version == AXIOM_SOAP12){
        code_value_ele = axiom_element_get_first_element(code_element, env, 
                code_node, &code_value_node);
		code = axiom_element_get_text(code_value_ele, env, code_value_node);
        if(code){
            add_property_string(fault_obj, WS_FAULT_CODE, code, 1);
        }                  
	}else if(soap_version == AXIOM_SOAP11){
		code = axiom_element_get_text(code_element, env, code_node);
		if(code){
			add_property_string(fault_obj, WS_FAULT_CODE, code, 1);
		}
	}
}

static void 
wsf_util_handle_fault_reason(
    zval *fault_obj,
    axiom_node_t *reason_node,
    axiom_element_t *reason_element,
    axutil_env_t *env,
	int soap_version)
{
	axis2_char_t *text_value = NULL;

    if(soap_version == AXIOM_SOAP12){
        axiom_node_t *text_node = NULL;
        axiom_element_t *text_element = NULL;
        text_element = axiom_element_get_first_element(reason_element, env, reason_node,
                &text_node);
        if(text_element){
            text_value = axiom_element_get_text(text_element, env, text_node);
            if(text_value){
				add_property_string(fault_obj, WS_FAULT_REASON , text_value, 1);
            }
        }
	}else if(soap_version == AXIOM_SOAP11){
		text_value = axiom_element_get_text(reason_element, env, reason_node);
		if(text_value){
			add_property_string(fault_obj, WS_FAULT_REASON, text_value, 1);
		}
	}
}


static void
wsf_util_handle_fault_detail(
    zval *fault_obj,
    axiom_node_t *detail_node,
    axiom_element_t *detail_element,
    axutil_env_t *env TSRMLS_DC)
{
	axis2_char_t *detail_string = NULL;
	axiom_node_t *detail_entry_node = NULL;
	if(detail_node){
		detail_entry_node = axiom_node_get_first_element(detail_node, env);
		if(detail_entry_node){
			detail_string = axiom_node_to_string(detail_entry_node, env);
			add_property_string(fault_obj, WS_FAULT_DETAIL, detail_string, 1);
			if(detail_string){
				AXIS2_FREE(env->allocator, detail_string);
			}
		}
	}
}

static void
wsf_util_handle_fault_role(
	zval *fault_obj,
	axiom_node_t *role_node,
	axiom_element_t *role_element,
	axutil_env_t *env TSRMLS_DC)
{
	axis2_char_t *role_uri = NULL;
	if(role_node && role_element){
		role_uri = axiom_element_get_text(role_element, env, role_node);
		if(role_uri){
             add_property_string(fault_obj, WS_FAULT_ROLE, role_uri, 1);
		}
	}
}

void
wsf_util_handle_soap_fault(
	zval *fault_obj,
	axutil_env_t *env,
	axiom_node_t *fault_node,
	int soap_version)
{
    axiom_element_t *fault_element = NULL;
    axiom_node_t *node = NULL;
    axiom_element_t *element = NULL;
    axiom_child_element_iterator_t *ele_iterator = NULL;

    if(!fault_node) return;
    
    fault_element = axiom_node_get_data_element(fault_node, env);

    ele_iterator = axiom_element_get_child_elements(fault_element, env, fault_node);

    if(!ele_iterator)
        return;
    while(AXIOM_CHILD_ELEMENT_ITERATOR_HAS_NEXT(ele_iterator, env)){
        node = AXIOM_CHILD_ELEMENT_ITERATOR_NEXT(ele_iterator, env);
        if(node){
            element = axiom_node_get_data_element(node, env);
            if(element){
                char *localname = NULL;
                localname = axiom_element_get_localname(element, env);
                if(localname){
					if(strcmp(localname,"Code") == 0){
						wsf_util_handle_fault_code(fault_obj, node, element, env, AXIOM_SOAP12 TSRMLS_CC);
					}else if(strcmp(localname, "faultcode") == 0){
						wsf_util_handle_fault_code(fault_obj, node, element, env, AXIOM_SOAP11 TSRMLS_CC);
					}else if(strcmp(localname, "Reason") == 0){
                        wsf_util_handle_fault_reason(fault_obj, node, element, env, AXIOM_SOAP12 TSRMLS_CC);
					}else if(strcmp(localname,"faultstring") ==0){
						wsf_util_handle_fault_reason(fault_obj, node, element, env, AXIOM_SOAP11 TSRMLS_CC);
					}else if((strcmp(localname, "Detail")  == 0) || (strcmp(localname, "detail") == 0)){
                        wsf_util_handle_fault_detail(fault_obj, node, element, env TSRMLS_CC); 
                    }else if((strcmp(localname, "Role") == 0) ||(strcmp(localname, "faultactor") == 0)){
						wsf_util_handle_fault_role(fault_obj, node, element, env TSRMLS_CC);                        
                    }
                }
            }
        }                
    }
}

*/

void wsf_util_engage_modules_to_svc(
    axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    wsf_svc_info_t *svc_info)
{
    axis2_conf_t *conf = NULL;
    conf = axis2_conf_ctx_get_conf (conf_ctx, env);
    if (conf && !axis2_conf_get_svc (conf, env, svc_info->svc_name)){
        axis2_conf_add_svc (conf, env, svc_info->svc);
        if (NULL != svc_info->modules_to_engage){
            int i = 0;
            int size = axutil_array_list_size (svc_info->modules_to_engage,
                env);
            for (i = 0; i < size; i++){
                axis2_char_t * mod_name = (axis2_char_t *) axutil_array_list_get (
                    svc_info->modules_to_engage, env, i);
                    wsf_util_engage_module (conf, mod_name, env,
                        svc_info->svc);
            }
        }
    }
}

static int
wsf_util_hash_each_ops_to_funcs(VALUE key, VALUE value, VALUE arg)
{
    char *op_name_to_store = NULL;
    char *op_name = NULL;
    unsigned int op_name_len = 0;
    char *func_name = NULL;
    wsservice_t *wsservice;

    wsf_svc_info_t *svc_info;

    Data_Get_Struct(arg, wsservice_t, wsservice);

    svc_info = wsservice->svc_info;

    func_name = RSTRING(value)->ptr;
    op_name = RSTRING(key)->ptr;

    if (op_name)
    {
        op_name_to_store = op_name;
    }
    else 
    {
        op_name_to_store = func_name;
    }

    axutil_hash_set (svc_info->ops_to_functions,
        axutil_strdup (wsservice->ws_env_svr, op_name_to_store),
        AXIS2_HASH_KEY_STRING,
        axutil_strdup (wsservice->ws_env_svr, func_name));

}

static int
wsf_util_hash_each_action(VALUE key, VALUE value, VALUE arg)
{
    char *func_name = NULL;
    char *wsa_action = NULL;
    unsigned int str_length = 0;
    char *operation_name = NULL;
    VALUE f;
    wsservice_t *wsservice;

    wsf_svc_info_t *svc_info;

    Data_Get_Struct(arg, wsservice_t, wsservice);

    svc_info = wsservice->svc_info;
    
    operation_name = RSTRING(value)->ptr;
    wsa_action = RSTRING(key)->ptr;

    func_name = axutil_hash_get (svc_info->ops_to_functions,
            operation_name, AXIS2_HASH_KEY_STRING);
    if (!func_name)
    {
        axutil_hash_set (svc_info->ops_to_functions,
                            axutil_strdup (wsservice->ws_env_svr, operation_name),
                                AXIS2_HASH_KEY_STRING, axutil_strdup (wsservice->ws_env_svr,
                                operation_name));
        func_name = operation_name;
    }
   
    /* 
    key = rb_str_new2(axutil_string_tolower(func_name));
    */

    if (wsa_action)
    {
        wsf_util_create_op_and_add_to_svc (svc_info, wsa_action,
                    wsservice->ws_env_svr, operation_name, wsservice->ht_ops_to_mep);

        /* keep track of operations with actions */
        axutil_hash_set (svc_info->ops_to_actions,
                    axutil_strdup (wsservice->ws_env_svr, operation_name),
                    AXIS2_HASH_KEY_STRING, axutil_strdup (wsservice->ws_env_svr,
                        wsa_action));
    }

    else
    {
        wsf_util_create_op_and_add_to_svc (svc_info, NULL,
                    wsservice->ws_env_svr, operation_name, wsservice->ht_ops_to_mep);
    }
}

void wsf_util_process_ws_service_operations_and_actions(VALUE self)
{
    wsservice_t *wsservice;

    VALUE ht_ops_to_funcs;
    VALUE ht_actions;
    VALUE ht_ops_to_mep;
    wsf_svc_info_t *svc_info;
    axutil_env_t *ws_env_svr;
    VALUE ht_classes;

    axutil_hash_index_t *hi;
    
    Data_Get_Struct(self, wsservice_t, wsservice);
    svc_info = wsservice->svc_info;

    ht_ops_to_funcs = wsservice->ht_ops_to_funcs;
    ht_actions = wsservice->ht_actions;
    ht_ops_to_mep = wsservice->ht_ops_to_mep;
    ht_classes = wsservice->ht_classes;

    svc_info = wsservice->svc_info;
    ws_env_svr = wsservice->ws_env_svr;


    if(ht_ops_to_funcs != Qnil)
    {
        rb_hash_foreach(ht_ops_to_funcs, wsf_util_hash_each_ops_to_funcs, self);
    }

    if(ht_classes != Qnil)
    {
        wsf_util_process_ws_service_classes(self);
    }

    if(ht_actions != Qnil)
    {
        rb_hash_foreach(ht_actions, wsf_util_hash_each_action, self);
    }

    if (svc_info->ops_to_functions) 
    {
        for (hi = axutil_hash_first (svc_info->ops_to_functions, ws_env_svr);
            hi; hi = axutil_hash_next (ws_env_svr, hi)) {

            void *v = NULL;
            const void *k = NULL;
            char *key = NULL;
            char *val = NULL;
            char *function_name = NULL;
            int key_len = 0;

            axutil_hash_this (hi, &k, NULL, &v);
            key = (axis2_char_t *) k;
            val = (axis2_char_t *) v;
            if (key && val) {

                /* function is there, add the operation to service */
                if (strcmp (key, val) == 0) {
                    wsf_util_create_op_and_add_to_svc (svc_info, NULL,
                        ws_env_svr, key, ht_ops_to_mep);
                }
                else {
                    char *action_for_op = NULL;
                    action_for_op = axutil_hash_get (svc_info->ops_to_actions, key,
                        AXIS2_HASH_KEY_STRING);

                    if (!action_for_op) {
                        /* There was no mapping WSA action for this operation.
                        So this operation was not yet added, hence add. */
                        wsf_util_create_op_and_add_to_svc (svc_info, NULL,
                        ws_env_svr, key, ht_ops_to_mep);
                    }
                }
            }
        }
    }
}

static int
wsf_util_resolve_op_to_func(VALUE key, VALUE value, VALUE self)
{
    axis2_char_t *op_name;
    axis2_char_t *func_name;
    axis2_char_t *class_name;

    wsservice_t *wsservice;
    wsf_svc_info_t *svc_info;

    /* retrieving key */
    if(TYPE(key) == T_STRING)
    {
        op_name = RSTRING(key)->ptr;
    }
    else if(TYPE(key) == T_SYMBOL)
    {
        op_name = rb_id2name(SYM2ID(key));
    }
    else
    {
        return 0;
    }

    /* retrieving value */
    if(TYPE(value) == T_STRING)
    {
        func_name = RSTRING(value)->ptr;
    }
    else if(TYPE(value) == T_SYMBOL)
    {
        func_name = rb_id2name(SYM2ID(key));
    }
    else
    {
        return 0;
    }

    Data_Get_Struct(self, wsservice_t, wsservice);
    svc_info = wsservice->svc_info;

    class_name = wsservice->temp_ops_class;

    axutil_hash_set (svc_info->ops_to_classes,
        axutil_strdup (wsservice->ws_env_svr, op_name),
        AXIS2_HASH_KEY_STRING,
        axutil_strdup (wsservice->ws_env_svr, class_name));

    axutil_hash_set (svc_info->ops_to_functions,
        axutil_strdup (wsservice->ws_env_svr, op_name),
        AXIS2_HASH_KEY_STRING,
        axutil_strdup (wsservice->ws_env_svr, func_name));

}

static int
wsf_util_resolve_class_ops(VALUE key, VALUE value, VALUE self)
{
    axis2_char_t *class_name;
    wsservice_t *wsservice;
    VALUE func_hash;

    Data_Get_Struct(self, wsservice_t, wsservice);

    func_hash = value;
    
    if(TYPE(key) == T_STRING)
    {
        class_name = RSTRING(key)->ptr;
    }
    else if(TYPE(key) == T_SYMBOL)
    {
        class_name = rb_id2name(SYM2ID(key));
    }
    else
    {
        return 0;
    }
    wsservice->temp_ops_class = class_name;

    if(TYPE(func_hash) == T_HASH)
    {  
        /* operation to function map */
        rb_hash_foreach(func_hash, wsf_util_resolve_op_to_func, self);
    }
    else
    {
        return 0;
    }
}

void wsf_util_process_ws_service_classes(VALUE self)
{
    VALUE ht_calsses;
    VALUE ht_ops_to_mep;
    /*HashTable *ht_classes,
    HashTable *ht_ops_to_mep, */
    wsf_svc_info_t *svc_info;
    axutil_env_t *ws_env_svr;

    VALUE class_hash;

    wsservice_t *wsservice;

    Data_Get_Struct(self, wsservice_t, wsservice);
    svc_info = wsservice->svc_info;

    if(TYPE(wsservice->ht_classes) == T_ARRAY)
    {
        /* classes array */
        while(Qnil != (class_hash = rb_ary_shift(wsservice->ht_classes)))
        {
            /* class_hash has the class_name=>(ops) map */
            if(TYPE(class_hash) == T_HASH)
            {
                rb_hash_foreach(class_hash, wsf_util_resolve_class_ops, self);
            }
        }
    }
}
