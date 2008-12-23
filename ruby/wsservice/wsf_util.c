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
#include "wsf_common.h"
#include "wsf_policy.h"
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

#include "wsf_wsdl_mode.h"

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
    axis2_char_t log_path[1024];
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
        snprintf (log_path, sizeof(log_path), "%s", LOG_NAME);
    } else {
        snprintf (log_path, sizeof(log_path), "%s/%s", path_tolog, LOG_NAME);
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
    svc_info->class_to_args = NULL;
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
        if (svc_info->class_to_args) {
            axutil_hash_free (svc_info->class_to_args, env);
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
        temp_string[i] = '\0';
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
                  snprintf (operation, sizeof(operation), "%s", op_name);
                  if(TYPE(ht_mep) == T_HASH)
                  {
                    mep_value = rb_hash_aref(ht_mep, ID2SYM(rb_intern(operation)));
                  }
                  if(mep_value != Qnil)
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

void wsf_util_pack_attachments (
		axutil_env_t *env,
		axiom_node_t *node,
		VALUE 		  attach_ht,
		int 		  enable_mtom,
		char 		 *default_cnt_type)
{
	axiom_element_t *node_element = NULL;
	axiom_element_t *child_element = NULL;
	axiom_child_element_iterator_t *child_element_ite = NULL;
	axiom_node_t *child_node = NULL;
	int attachment_done = 0;
	axis2_char_t *element_localname = NULL;
	axiom_namespace_t *element_namespace = NULL;
	axis2_char_t *namespace_uri = NULL;

	if (!node)
		return;

	if (axiom_node_get_node_type(node, env) == AXIOM_ELEMENT)
	{
		node_element = axiom_node_get_data_element(node, env);
		if (node_element)
		{
			child_element_ite = axiom_element_get_child_elements(node_element, env, node);
	        if (child_element_ite)
			{
				child_node = axiom_child_element_iterator_next(child_element_ite, env);
				attachment_done = 0;
				
				while (child_node && !attachment_done)
				{
					child_element = axiom_node_get_data_element(child_node, env);
					
					element_localname = axiom_element_get_localname(child_element, env);
		         	if (element_localname && (axutil_strcmp(element_localname, AXIS2_ELEMENT_LN_INCLUDE) == 0))
					{
						element_namespace = axiom_element_get_namespace(child_element, env, child_node);
		          		if (element_namespace)
						{
							namespace_uri = axiom_namespace_get_uri(element_namespace, env);
							if (namespace_uri && (axutil_strcmp(namespace_uri, AXIS2_NAMESPACE_URI_INCLUDE) == 0))
							{
								axis2_char_t *cnt_type = NULL;
								axis2_char_t *content_type = NULL;
								axis2_char_t *href = NULL;
								axis2_char_t* pos = NULL;

								cnt_type = axiom_element_get_attribute_value_by_name(node_element, env, AXIS2_ELEMENT_ATTR_NAME_CONTENT_TYPE);
		              			content_type = !cnt_type ? default_cnt_type : cnt_type;

		           				href = axiom_element_get_attribute_value_by_name(child_element, env, AXIS2_ELEMENT_ATTR_NAME_HREF);

                        		if ((axutil_strlen(href) > 4) && (pos = axutil_strstr (href, "cid:")))
								{
									axis2_char_t* cid = NULL;
									VALUE content_tmp;
									void* content = NULL;
									unsigned int content_length = 0;

									cid = href + 4;

			            			content_tmp = rb_hash_aref(attach_ht, rb_str_new2(cid));
									content_length = RSTRING(content_tmp)->len;

									content = malloc(sizeof (char) * content_length);
									memcpy (content, (const void*)STR2CSTR(content_tmp), content_length);

									if (content)
									{
										void *data_buffer = NULL;
										axiom_data_handler_t *data_handler = NULL;
										axiom_node_t *text_node = NULL;
										axiom_text_t *text = NULL;
										  
										data_buffer = AXIS2_MALLOC (env->allocator, sizeof (char) * content_length);
										if (data_buffer)
										{
											memcpy (data_buffer, content, content_length);

											data_handler = axiom_data_handler_create (env, NULL, content_type);
											if (data_handler)
											{
												axiom_data_handler_set_binary_data (data_handler, env, (axis2_byte_t *)content, content_length);
												  
												text = axiom_text_create_with_data_handler (env, node, data_handler, &text_node);
												  
												if (enable_mtom == AXIS2_FALSE)
													axiom_text_set_optimize (text, env, AXIS2_FALSE);
												  
												axiom_node_detach (child_node, env);
											}
										}

										attachment_done = 1;
									}
								}
							}
						}
					}

					child_node = axiom_child_element_iterator_next(child_element_ite, env);
				}
			}
		}
	}

	// Process child nodes
	child_node = axiom_node_get_first_child(node, env);
	while (child_node)
	{
		wsf_util_pack_attachments(env, child_node, attach_ht, enable_mtom, default_cnt_type);
			
		child_node = axiom_node_get_next_sibling(child_node, env);
	}
}


void wsf_util_unpack_attachments (
		const axutil_env_t *env,
		axiom_node_t 	   *node,
		VALUE			   *message)
{
	axiom_text_t * text_element = NULL;
	axiom_data_handler_t *data_handler = NULL;
	axis2_char_t *content = NULL;
	unsigned int content_length = 0;
	axis2_char_t *content_type = NULL;
	axis2_char_t *cid = NULL;
	axiom_node_t *child_node = NULL;

	if (!node)
		return;
	
	// Process current node
	if (axiom_node_get_node_type (node, env) == AXIOM_TEXT)
	{
		text_element = (axiom_text_t *)axiom_node_get_data_element(node, env);
		if (text_element)
		{
			data_handler = axiom_text_get_data_handler (text_element, env);
			if (data_handler)
			{
				axiom_data_handler_read_from (data_handler, env, &content, &content_length);
				content_type = axiom_data_handler_get_content_type (data_handler, env);
				cid = axiom_text_get_content_id (text_element, env);

				if (content && content_type && cid)
				{
					VALUE cont_id;
					VALUE cont;
					VALUE cont_type;
					
					cont_id = rb_str_new2(cid);
					cont_type = rb_str_new2(content_type);
					cont = rb_str_new(content, content_length);

					rb_funcall(*message, rb_intern("add_attachment_content"), 2, cont_id, cont);
					rb_funcall(*message, rb_intern("add_content_type"), 2, cont_id, cont_type);
				}
			}
		}
	}

	// Process child nodes
	child_node = axiom_node_get_first_child (node, env);
	while (child_node)
	{
		wsf_util_unpack_attachments (env, child_node, message);

		child_node = axiom_node_get_next_sibling (child_node, env);
	}
}


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

VALUE
wsf_util_hash_each_ops_to_funcs(VALUE key_val_array, VALUE arg)
{
    char *op_name_to_store = NULL;
    char *op_name = NULL;
    unsigned int op_name_len = 0;
    char *func_name = NULL;
    wsservice_t *wsservice;
    VALUE key;
    VALUE value;

    wsf_svc_info_t *svc_info;

    key = rb_ary_entry(key_val_array, 0);               
    value = rb_ary_entry(key_val_array, 1);

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
        op_name_to_store,
        AXIS2_HASH_KEY_STRING,
        (void*)func_name);

    return Qnil;
}

VALUE
wsf_util_hash_each_action(VALUE key_val_array, VALUE arg)
{
    char *func_name = NULL;
    char *wsa_action = NULL;
    unsigned int str_length = 0;
    char *operation_name = NULL;
    VALUE f;
    wsservice_t *wsservice;
	  VALUE key, value;

    wsf_svc_info_t *svc_info;

	
    key = rb_ary_entry(key_val_array, 0);               
    value = rb_ary_entry(key_val_array, 1);  

    Data_Get_Struct(arg, wsservice_t, wsservice);

    svc_info = wsservice->svc_info;
    
    operation_name = RSTRING(value)->ptr;
    wsa_action = RSTRING(key)->ptr;

    func_name = (axis2_char_t*)axutil_hash_get (svc_info->ops_to_functions,
            operation_name, AXIS2_HASH_KEY_STRING);
    if (!func_name)
    {
        axutil_hash_set (svc_info->ops_to_functions,
                                operation_name,
                                AXIS2_HASH_KEY_STRING,
                                (void*)operation_name);
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
                    operation_name,
                    AXIS2_HASH_KEY_STRING,
                    (void*)wsa_action);
    }

    else
    {
        wsf_util_create_op_and_add_to_svc (svc_info, NULL,
                    wsservice->ws_env_svr, operation_name, wsservice->ht_ops_to_mep);
    }
    
    return Qnil;
	/* printf("key: %s, value: %s\n", operation_name, wsa_action); */
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
        rb_iterate(rb_each, ht_ops_to_funcs, wsf_util_hash_each_ops_to_funcs, self);
    }

    if(ht_classes != Qnil)
    {
        wsf_util_process_ws_service_classes(self);
    }

    if(ht_actions != Qnil)
    {
        rb_iterate(rb_each, ht_actions, wsf_util_hash_each_action, self);
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
        op_name,
        AXIS2_HASH_KEY_STRING,
        (void*)class_name);

    axutil_hash_set (svc_info->ops_to_functions,
        op_name,
        AXIS2_HASH_KEY_STRING,
        (void*)func_name);

}

static int
wsf_util_resolve_class_params(VALUE key, VALUE value, VALUE self)
{
    axis2_char_t *class_name;
    wsservice_t *wsservice;
    VALUE class_param_hash;

    Data_Get_Struct(self, wsservice_t, wsservice);

    class_param_hash= value;
    
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

    if(TYPE(class_param_hash) == T_HASH)
    {
        VALUE ht_ops;
        VALUE ht_args;

        ht_ops = rb_hash_aref(class_param_hash, ID2SYM(rb_intern("operations")));
        if(ht_ops == Qnil)
        {
            ht_ops = rb_hash_aref(class_param_hash, rb_str_new2("operations"));
        }
        if(ht_ops != Qnil)
        {
            AXIS2_LOG_DEBUG (wsservice->ws_env_svr->log, AXIS2_LOG_SI,
                  "[wsf_service] setting operation for classs %s", class_name);
            if(TYPE(ht_ops) == T_HASH)
            {
                /* operation to function map */
                rb_hash_foreach(ht_ops, wsf_util_resolve_op_to_func, self);
            }
        }

        ht_args = rb_hash_aref(class_param_hash, ID2SYM(rb_intern("args")));
        if(ht_args == Qnil)
        {
            ht_args = rb_hash_aref(class_param_hash, rb_str_new2("args"));
        }
        if(ht_args != Qnil)
        {
            AXIS2_LOG_DEBUG (wsservice->ws_env_svr->log, AXIS2_LOG_SI,
                  "[wsf_service] setting args for classs %s", class_name);
            if(TYPE(ht_args) == T_ARRAY)
            {
                /* array of constructor arguments */
                axutil_hash_set (wsservice->svc_info->class_to_args,
                    class_name,
                    AXIS2_HASH_KEY_STRING,
                    (void*)ht_args);
                
            }
        }
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
                rb_hash_foreach(class_hash, wsf_util_resolve_class_params, self);
            }
        }

    }
    else if(TYPE(wsservice->ht_classes) == T_HASH)
    {
        /* if this we only allow only class per service, it wourld have been redude to
           Just  iterate through classes hash */
        rb_hash_foreach(wsservice->ht_classes, wsf_util_resolve_class_params, self);
    }
}

void
wsf_evaluate_security_token_and_insert_to_hash(axutil_env_t* env,
                                               VALUE security_token,
                                               axutil_hash_t* hash)
{
    char* prv_key = NULL;
    VALUE private_key = Qnil;
    char* certificate = NULL;
    VALUE cert = Qnil;
    char* receiver_certificate = NULL;
    VALUE rec_cert = Qnil;
    char* username = NULL;
    VALUE usr = Qnil;
    char* password = NULL;
    VALUE pwd = Qnil;
    char* password_type = NULL;
    VALUE pwd_type = Qnil;
    int ttl = -1;
    VALUE time_to_live = Qnil;
    char* callback_function_name = NULL;
    VALUE callback_fn = Qnil;

    if (!hash)
        return;

    private_key = rb_funcall(security_token, rb_intern("option"), 1, rb_str_new2("private_key"));
    if (!NIL_P(private_key) && (TYPE(private_key) == T_STRING))
    {
        prv_key = RSTRING(private_key)->ptr;

        if (prv_key)
        {
            axutil_hash_set(hash, 
                WSF_WSDL_HK_PRIVATE_KEY, 
                AXIS2_HASH_KEY_STRING, 
                axutil_strdup(env, prv_key));
        }
    }

    cert = rb_funcall(security_token, rb_intern("option"), 1, rb_str_new2("certificate"));
    if (!NIL_P(cert) && (TYPE(cert) == T_STRING))
    {
        certificate = RSTRING(cert)->ptr;

        if (certificate)
        {
            axutil_hash_set(hash, 
                WSF_WSDL_HK_CERTIFICATE, 
                AXIS2_HASH_KEY_STRING, 
                axutil_strdup(env, certificate));
        }
    }

    rec_cert = rb_funcall(security_token, rb_intern("option"), 1, rb_str_new2("receiver_certificate"));
    if (!NIL_P(rec_cert) && (TYPE(rec_cert) == T_STRING))
    {
        receiver_certificate = RSTRING(rec_cert)->ptr;

        if (receiver_certificate)
        {
            axutil_hash_set(hash, 
                WSF_WSDL_HK_RECEIVER_CERTIFICATE, 
                AXIS2_HASH_KEY_STRING, 
                axutil_strdup(env, receiver_certificate));
        }
    }

    usr = rb_funcall(security_token, rb_intern("option"), 1, rb_str_new2("user"));
    if (!NIL_P(usr) && (TYPE(usr) == T_STRING))
    {
        username = RSTRING(usr)->ptr;

        if (username)
        {
            axutil_hash_set(hash, 
                WSF_WSDL_HK_USER, 
                AXIS2_HASH_KEY_STRING, 
                axutil_strdup(env, username));
        }
    }

    pwd = rb_funcall(security_token, rb_intern("option"), 1, rb_str_new2("password"));
    if (!NIL_P(pwd) && (TYPE(pwd) == T_STRING))
    {
        password = RSTRING(pwd)->ptr;

        if (password)
        {
            axutil_hash_set(hash, 
                WSF_WSDL_HK_PASSWORD, 
                AXIS2_HASH_KEY_STRING, 
                axutil_strdup(env, password));
        }
    }

    pwd_type = rb_funcall(security_token, rb_intern("option"), 1, rb_str_new2("password_type"));
    if (!NIL_P(pwd_type) && (TYPE(pwd_type) == T_STRING))
    {
        password_type = RSTRING(pwd_type)->ptr;

        if (password_type)
        {
            axutil_hash_set(hash, 
                WSF_WSDL_HK_PASSWORD_TYPE, 
                AXIS2_HASH_KEY_STRING, 
                axutil_strdup(env, password_type));
        }
    }

    callback_fn = rb_funcall(security_token, rb_intern("option"), 1, rb_str_new2("password_callback"));
    if (!NIL_P(callback_fn) && (TYPE(callback_fn) == T_STRING))
    {
        callback_function_name = RSTRING(callback_fn)->ptr;

        if (callback_function_name)
        {
            axutil_hash_set(hash, 
                WSF_WSDL_HK_PASSWORD_CALL_BACK, 
                AXIS2_HASH_KEY_STRING, 
                axutil_strdup(env, callback_function_name));
        }
    }

    time_to_live = rb_funcall(security_token, rb_intern("option"), 1, rb_str_new2("ttl"));
    if (!NIL_P(time_to_live) && (TYPE(time_to_live) == T_FIXNUM))
    {
        ttl = FIX2INT(time_to_live);

        if (ttl >= 0)
        {
            axutil_hash_set(hash, 
                WSF_WSDL_HK_TTL, 
                AXIS2_HASH_KEY_STRING, 
                (void*)ttl);
        }
    }
}

void
wsf_evaluate_policy_options_and_insert_to_hash(axutil_env_t* env,
                                               VALUE policy,
                                               axutil_hash_t* hash)
{
    VALUE time_stamp;
    VALUE username_token;
    VALUE encryption;
    VALUE algorithm;
    VALUE sign;
    VALUE token_reference;
    VALUE encrypt_signature;
    VALUE protection_order;

    char* ts = NULL;
    char* ut = NULL;
    char* encrypt = NULL;
    char* algo_suite = NULL;
    char* sg = NULL;
    char* tkn = NULL;
    char* token_ref = NULL;
    char* encrypt_sign = NULL;
    char* order = NULL;

    if (policy != Qnil) 
    {
        time_stamp = rb_funcall(policy, rb_intern("option"), 1, rb_str_new2(WS_TIMESTAMP));

        if (!NIL_P(time_stamp) && (TYPE(time_stamp) == T_STRING))
        {
            ts = RSTRING(time_stamp)->ptr;

            if (ts) 
            {
                axutil_hash_set(hash, 
                    WSF_WSDL_HK_TIMESTAMP, 
                    AXIS2_HASH_KEY_STRING, 
                    axutil_strdup(env, ts)); 
            }
        }

        username_token = rb_funcall(policy, rb_intern("option"), 1, rb_str_new2(WS_UT));

        if (!NIL_P(username_token) && (TYPE(username_token) == T_STRING))
        {   
            ut = RSTRING(username_token)->ptr;
            if (ut)
            {
                axutil_hash_set(hash, 
                    WSF_WSDL_HK_USERNAME_TOKEN, 
                    AXIS2_HASH_KEY_STRING, 
                    axutil_strdup(env, ut)); 
            }
        }

        encryption = rb_funcall(policy, rb_intern("option"), 1, rb_str_new2(WS_ENCRYPT));

        if (!NIL_P(encryption) && (TYPE(encryption) == T_STRING))
        { 
            encrypt = RSTRING(encryption)->ptr;

            if (encrypt)
            {
                axutil_hash_set(hash, 
                    WSF_WSDL_HK_ENCRYPTION, 
                    AXIS2_HASH_KEY_STRING, 
                    axutil_strdup(env, encrypt)); 
            }
        }

        algorithm = rb_funcall(policy, rb_intern("option"), 1, rb_str_new2(WS_ALGORITHM));

        if (!NIL_P(algorithm) && (TYPE(algorithm) == T_STRING))
        {
            algo_suite = RSTRING(algorithm)->ptr;

            if (algo_suite)
            {
                axutil_hash_set(hash, 
                    WSF_WSDL_HK_ALGORITHM, 
                    AXIS2_HASH_KEY_STRING, 
                    axutil_strdup(env, algo_suite)); 
            }
        }

        sign = rb_funcall(policy, rb_intern("option"), 1, rb_str_new2(WS_SIGN));

        if (!NIL_P(sign) && (TYPE(sign) == T_STRING))
        {
            sg = RSTRING(sign)->ptr;

            if (sg)
            {
                axutil_hash_set(hash, 
                    WSF_WSDL_HK_SIGNING, 
                    AXIS2_HASH_KEY_STRING, 
                    axutil_strdup(env, sg)); 
            }
        }

        token_reference = rb_funcall(policy, rb_intern("option"), 1, rb_str_new2(WS_TOKEN_REFERENCE));

        if (!NIL_P(token_reference) && (TYPE(token_reference) == T_STRING))
        {
            tkn = RSTRING(token_reference)->ptr;

            if (tkn)
            {
                axutil_hash_set(hash, 
                    WSF_WSDL_HK_TOKEN_REFERENCE, 
                    AXIS2_HASH_KEY_STRING, 
                    axutil_strdup(env, tkn)); 
            }
        }

        encrypt_signature = rb_funcall(policy, rb_intern("option"), 1, rb_str_new2(WS_ENCRYPT_SIGNATURE)); 

        if (!NIL_P(encrypt_signature) && (TYPE(encrypt_signature) == T_STRING))
        {
            encrypt_sign = RSTRING(encrypt_signature)->ptr;

            if (encrypt_sign)
            {
                axutil_hash_set(hash, 
                    WSF_WSDL_HK_ENCRYPT_SIGNATURE, 
                    AXIS2_HASH_KEY_STRING, 
                    axutil_strdup(env, encrypt_sign)); 
            }
        }

        protection_order = rb_funcall(policy, rb_intern("option"), 1, rb_str_new2(WS_PROTECTION_ORDER));	

        if (!NIL_P(protection_order) && (TYPE(protection_order) == T_STRING))
        {
            order = RSTRING(protection_order)->ptr;

            if (order)
            {
                axutil_hash_set(hash, 
                    WSF_WSDL_HK_PROTECTION_ORDER, 
                    AXIS2_HASH_KEY_STRING, 
                    axutil_strdup(env, order)); 
            }
        }
    }   	
}



void
wsf_evaluate_policy_and_insert_to_hash(axutil_env_t* env,
                                       VALUE policy,
                                       axutil_hash_t* hash)
{
    VALUE policy_string;

    policy_string = rb_funcall(policy, rb_intern("get_policy"), 0);

    if (!NIL_P(policy_string))
    {
        axis2_char_t* policy_buffer = NULL;
        axis2_char_t* policy_str = NULL;
        policy_str = RSTRING(policy_string)->ptr;

        policy_buffer = axutil_strdup(env, policy_str);

        axutil_hash_set(hash, 
            WSF_WSDL_HK_POLICY_STRING, 
            AXIS2_HASH_KEY_STRING, 
            policy_buffer); 
    }
    else
    {	
        axutil_hash_t* policy_hash = NULL;
        policy_hash = axutil_hash_make(env);

        wsf_evaluate_policy_options_and_insert_to_hash(env, policy, policy_hash);

        axutil_hash_set(hash, 
            WSF_WSDL_HK_POLICY_HASH, 
            AXIS2_HASH_KEY_STRING, 
            policy_hash); 
    }
}

