%module "WSFC"

%{
#include "axiom.h"
#include "axis2_svc.h"
#include "axis2_msg_recv.h"
#include "axis2_const.h"
#include "axis2_defines.h"
#include "axutil_env.h"
#include "axutil_utils.h"
#include "axutil_string.h"
#include "axis2_conf_ctx.h"
#include "axiom_node.h"
#include "axis2_options.h"
#include "axis2_svc_client.h"
#include "axutil_qname.h"
#include "axutil_log.h"
%}

%include wsf_constants.i

%include "cpointer.i"
%include "typemaps.i"

typedef char         axis2_char_t;
typedef int          axis2_bool_t;
typedef int          axis2_status_t;
typedef int          axis2_scope_t;
typedef unsigned int axis2_ssize_t;
typedef char         axis2_byte_t;

axiom_node_t * 
axiom_document_build_all(axiom_document_t   *INOUT,
                         const axutil_env_t *INOUT);

axutil_env_t *
axutil_env_create_all(const axis2_char_t        *log_file,
                      const axutil_log_levels_t  log_level);

axis2_endpoint_ref_t *
axis2_endpoint_ref_create(const axutil_env_t *env,
                          const axis2_char_t *address);

axis2_status_t 
axis2_options_set_to(axis2_options_t      *options,
                     const axutil_env_t   *env,
                     axis2_endpoint_ref_t *to);

axis2_status_t
axis2_options_set_from(axis2_options_t      *options,
                       const axutil_env_t   *env,
                       axis2_endpoint_ref_t *from);

void
axis2_options_set_action(axis2_options_t    *options,
                         const axutil_env_t *env,
                         const axis2_char_t *action);

axis2_status_t
axis2_options_set_enable_rest(axis2_options_t    *options,
                              const axutil_env_t *env,
                              const axis2_bool_t  enable_rest);

axis2_status_t
axis2_options_set_http_method(axis2_options_t    *options,
                              const axutil_env_t *env,
                              const axis2_char_t *http_method);

axis2_status_t
axis2_options_set_soap_version(axis2_options_t    *options,
                               const axutil_env_t *env,
                               const int           soap_version);

axis2_status_t 
axis2_options_set_soap_action(axis2_options_t    *options,
                              const axutil_env_t *env,
                              axutil_string_t    *soap_action);

axis2_status_t 
axis2_options_set_reply_to(axis2_options_t      *options,
                           const axutil_env_t   *env,
                           axis2_endpoint_ref_t *reply_to);

axis2_status_t 
axis2_options_set_fault_to(axis2_options_t      *options,
                           const axutil_env_t   *env,
                           axis2_endpoint_ref_t *fault_to);

axis2_status_t
axis2_options_set_enable_mtom(axis2_options_t    *options,
                              const axutil_env_t *env,
                              axis2_bool_t        enable_mtom);

axis2_svc_client_t *
axis2_svc_client_create(const axutil_env_t *env,
                        const axis2_char_t *client_home);

axis2_status_t
axis2_svc_client_engage_module(axis2_svc_client_t *svc_client,
                               const axutil_env_t *env,
                               const axis2_char_t *module_name);

axis2_char_t * 
axiom_node_to_string(axiom_node_t       *om_node,
                     const axutil_env_t *env);

axiom_types_t
axiom_node_get_node_type(axiom_node_t       *om_node,
                         const axutil_env_t *env);

axiom_node_t *
axiom_node_get_first_child(axiom_node_t       *om_node,
                           const axutil_env_t *env);

axiom_node_t *
axiom_node_get_next_sibling(axiom_node_t       *om_node,
                            const axutil_env_t *env);   

%inline %{
axiom_element_t *
ruby_axiom_node_get_data_element(axiom_node_t       *om_node,
                                 const axutil_env_t *env)
{
  return (axiom_element_t *)axiom_node_get_data_element(om_node, env);
}
%}

%inline %{
axiom_text_t *
ruby_axiom_node_get_text_element(axiom_node_t       *om_node,
                                 const axutil_env_t *env)
{
  return (axiom_text_t *)axiom_node_get_data_element(om_node, env);
}
%}

axiom_child_element_iterator_t *
axiom_element_get_child_elements(axiom_element_t    *om_element,
                                 const axutil_env_t *env,
                                 axiom_node_t       *element_node);

axiom_node_t *
axiom_child_element_iterator_next(axiom_child_element_iterator_t *iterator,
                                  const axutil_env_t             *env);

axis2_char_t *
axiom_element_get_localname(axiom_element_t    *om_element,
                            const axutil_env_t *env);

axiom_namespace_t *
axiom_element_get_namespace(axiom_element_t    *om_element,
                            const axutil_env_t *env,
                            axiom_node_t       *ele_node);

axis2_char_t *
axiom_namespace_get_uri(axiom_namespace_t  *om_namespace,
                        const axutil_env_t *env);

axis2_char_t *
axiom_element_get_attribute_value_by_name(axiom_element_t    *om_ele,
                                          const axutil_env_t *env,
                                          axis2_char_t       *attr_name);

axiom_node_t *
axiom_node_detach(axiom_node_t       *om_node,
                  const axutil_env_t *env);

axiom_data_handler_t *
axiom_data_handler_create(const axutil_env_t *env,
                          const axis2_char_t *file_name,
                          const axis2_char_t *mime_type);

axiom_data_handler_t *
axiom_text_get_data_handler(axiom_text_t       *om_text,
                            const axutil_env_t *env);

%inline %{
void
ruby_axiom_attach_content(const axutil_env_t *env,
                          axiom_node_t       *node,
                          axiom_node_t       *parent_node,
                          axis2_bool_t        enable_mtom,
                          axis2_char_t       *content_type,
                          const char         *content,
                          int                 content_length)
{
  void *data_buffer = AXIS2_MALLOC (env->allocator, sizeof (char) * content_length);
  if (data_buffer == NULL)
    return;

  memcpy (data_buffer, (void*)content, content_length);

  axiom_data_handler_t *data_handler = axiom_data_handler_create (env, NULL, content_type);
  if (data_handler == NULL)
    return;

  axiom_data_handler_set_binary_data (data_handler, env, (axis2_byte_t *)content, content_length);

  axiom_node_t *text_node = NULL;
  axiom_text_t *text = axiom_text_create_with_data_handler (env, parent_node, data_handler, &text_node);

  if (enable_mtom == AXIS2_FALSE)
    axiom_text_set_optimize (text, env, AXIS2_FALSE);

  axiom_node_detach (node, env);
}
%}

%inline %{
axis2_char_t *
ruby_axiom_data_handler_get_base64_content(axiom_data_handler_t *data_handler,
                                           const axutil_env_t   *env)
{
  axis2_char_t *content = NULL;
  int           content_length = 0;

  axiom_data_handler_read_from (data_handler, env, &content, &content_length);

  if (content == NULL)
    return NULL;

  int encoded_length = axutil_base64_encode_len(content_length);
  axis2_char_t *encoded_str = AXIS2_MALLOC(env->allocator, encoded_length + 2);
                
  if (encoded_str == NULL)
    return NULL;

  encoded_length = axutil_base64_encode(encoded_str, content, content_length);
  encoded_str[encoded_length] = '\0';

  return encoded_str;
}
%}

%inline %{
int
ruby_file_put_base64_content(const char *file_name,
                             const char *base64_content)
{
  int decoded_length = axutil_base64_decode_len(base64_content);
  
  char *decoded_content = (char*)malloc(decoded_length);
  if (decoded_content == NULL)
    return 0;

  decoded_length = axutil_base64_decode(decoded_content, base64_content);
  if (decoded_content == NULL)
    return 0;

  FILE *file = fopen(file_name, "w");
  if (file == NULL)
    return 0;

  fwrite(decoded_content, sizeof(char), decoded_length, file);
  fclose(file);

  free(decoded_content);

  return 1;
}
%}

axis2_char_t *
axiom_data_handler_get_content_type(axiom_data_handler_t *data_handler,
                                    const axutil_env_t   *env);

axis2_char_t *
axiom_text_get_content_id(axiom_text_t       *om_text,
                          const axutil_env_t *env);

axiom_node_t * 
axis2_svc_client_send_receive(axis2_svc_client_t *svc_client,
                              const axutil_env_t *env,
                              const axiom_node_t *payload);

axis2_status_t
axis2_svc_client_send_robust(axis2_svc_client_t *svc_client,
                             const axutil_env_t *env,
                             const axiom_node_t *payload);

%inline %{
axiom_xml_reader_t *
ruby_axiom_xml_reader_create_for_memory(const axutil_env_t *env,
                                        char               *container,
                                        int                size,
                                        const axis2_char_t *encoding,
                                        int                type)
{
  return axiom_xml_reader_create_for_memory(env, container, size, encoding, type);
}
%}

axiom_stax_builder_t * 
axiom_stax_builder_create(const axutil_env_t *env,
                          axiom_xml_reader_t *parser);

axiom_document_t * 
axiom_stax_builder_get_document(axiom_stax_builder_t *builder,
                                const axutil_env_t   *env);

void
axiom_stax_builder_free_self(axiom_stax_builder_t *builder,
                             const axutil_env_t   *env);

axiom_node_t *
axiom_document_get_root_element(axiom_document_t   *document,
                                const axutil_env_t *env);

axis2_status_t 
axiom_node_serialize (axiom_node_t       *om_node,
                      const axutil_env_t *env,
                      axiom_output_t     *om_output);

axiom_xml_writer_t * 
axiom_xml_writer_create_for_memory(const axutil_env_t *env,
                                   axis2_char_t       *encoding,
                                   int                 is_prefix_default,
                                   int                 compression,
                                   int                 type);

axiom_output_t * 
axiom_output_create(const axutil_env_t  *env,
                     axiom_xml_writer_t *xml_writer);

axis2_options_t *
axis2_svc_client_get_options(const axis2_svc_client_t *svc_client,
                             const axutil_env_t       *env);

void 
axiom_xml_reader_free(axiom_xml_reader_t *parser,
                      const axutil_env_t *env);

axis2_status_t 
axis2_svc_client_set_proxy(axis2_svc_client_t *svc_client,
                           const axutil_env_t *env,
                           axis2_char_t       *proxy_host,
                           axis2_char_t       *proxy_port);

axutil_property_t *
axutil_property_create_with_args(const axutil_env_t  *env,
                                 axis2_scope_t        scope,
                                 axis2_bool_t         own_value,
                                 AXIS2_FREE_VOID_ARG  free_func,
                                 void                *value);

%inline %{
int
ruby_axutil_strcmp(const axis2_char_t *s1,
                   const axis2_char_t *s2)
{
  return ((axutil_strcmp(s1, s2) == 0) ? AXIS2_TRUE : AXIS2_FALSE);
}
%}

axis2_status_t
axis2_options_set_property(axis2_options_t    *options,
                           const axutil_env_t *env,
                           const axis2_char_t *property_key,
                           const void         *property);

axutil_string_t * 
axutil_string_create(const axutil_env_t *env,
                     const axis2_char_t *str);

axis2_bool_t 
axis2_svc_client_get_last_response_has_fault(const axis2_svc_client_t *svc_client,
                                             const axutil_env_t       *env);

axiom_soap_envelope_t *
axis2_svc_client_get_last_response_soap_envelope(const axis2_svc_client_t *svc_client,
                                                 const axutil_env_t       *env);

axiom_soap_body_t * 
axiom_soap_envelope_get_body(axiom_soap_envelope_t *envelope,
                             const axutil_env_t    *env);

axiom_node_t * 
axiom_soap_body_get_base_node(axiom_soap_body_t  *body,
                              const axutil_env_t *env);

axiom_soap_fault_t * 
axiom_soap_body_get_fault(axiom_soap_body_t  *body,
                          const axutil_env_t *env);

/* SOAP fault CODE */
axiom_soap_fault_code_t *
axiom_soap_fault_get_code(axiom_soap_fault_t *fault,
                          const axutil_env_t *env);

axiom_soap_fault_value_t *
axiom_soap_fault_code_get_value(axiom_soap_fault_code_t *fault_code,
                                const axutil_env_t      *env);

axis2_char_t *
axiom_soap_fault_value_get_text(axiom_soap_fault_value_t *fault_value,
                                const axutil_env_t       *env);

/* SOAP fault REASON */
axiom_soap_fault_reason_t *
axiom_soap_fault_get_reason(axiom_soap_fault_t *fault,
                            const axutil_env_t *env);

axiom_soap_fault_text_t *
axiom_soap_fault_reason_get_first_soap_fault_text(axiom_soap_fault_reason_t *fault_reason,
                                                  const axutil_env_t        *env);

axis2_char_t *
axiom_soap_fault_text_get_text(axiom_soap_fault_text_t *fault_text,
                               const axutil_env_t      *env);

/* SOAP fault ROLE */
axiom_soap_fault_role_t *
axiom_soap_fault_get_role(axiom_soap_fault_t *fault,
                          const axutil_env_t *env);

axis2_char_t *
axiom_soap_fault_role_get_role_value(axiom_soap_fault_role_t *fault_role,
                                     const axutil_env_t      *env);

/* SOAP fault DETAIL */
axiom_soap_fault_detail_t *
axiom_soap_fault_get_detail(axiom_soap_fault_t *fault,
                            const axutil_env_t *env);

axiom_children_iterator_t *
axiom_soap_fault_detail_get_all_detail_entries(axiom_soap_fault_detail_t *fault_detail,
                                               const axutil_env_t        *env);

axiom_node_t *
axiom_children_iterator_next(axiom_children_iterator_t *iterator,
                             const axutil_env_t        *env);

axiom_node_t * 
axiom_soap_fault_get_base_node(axiom_soap_fault_t *fault,
                               const axutil_env_t *env);

%inline %{
axis2_char_t *
ruby_axiom_xml_writer_get_xml(axiom_xml_writer_t *writer,
                              const axutil_env_t *env)
{
  return (axis2_char_t *)axiom_xml_writer_get_xml(writer, env);
}
%}

axis2_status_t 
axis2_options_set_xml_parser_reset(axis2_options_t    *options,
                                   const axutil_env_t *env,
                                   const axis2_bool_t  paser_reset_flag);

%inline %{
void
axis2_log_debug(axutil_env_t *env,
                axis2_char_t *str)
{
  AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, str);
}
%}

%inline %{
void
axis2_log_critical(axutil_env_t *env,
                   axis2_char_t *str)
{
  AXIS2_LOG_CRITICAL(env->log, AXIS2_LOG_SI, str);
}
%}

%inline %{
void
axis2_log_error(axutil_env_t *env,
                axis2_char_t *str)
{
  AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, str);
}
%}
