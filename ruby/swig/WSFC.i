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
                      const axutil_log_levels_t log_level);

axis2_endpoint_ref_t *
axis2_endpoint_ref_create(const axutil_env_t *env,
                          const axis2_char_t *address);

axis2_options_t *
axis2_options_create(const axutil_env_t *env);

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
axis2_options_set_soap_version_uri(axis2_options_t    *options,
                                   const axutil_env_t *env,
                                   const axis2_char_t *soap_version_uri);

axis2_status_t
axis2_options_set_soap_version(axis2_options_t    *options,
                               const axutil_env_t *env,
                               const int          soap_version);

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
                              axis2_bool_t       enable_mtom);

axis2_svc_client_t *
axis2_svc_client_create(const axutil_env_t *env,
                        const axis2_char_t *client_home);

axis2_status_t
axis2_svc_client_set_options(axis2_svc_client_t    *svc_client,
                             const axutil_env_t    *env,
                             const axis2_options_t *options);

axis2_status_t
axis2_svc_client_engage_module(axis2_svc_client_t *svc_client,
                               const axutil_env_t *env,
                               const axis2_char_t *module_name);

axiom_namespace_t *
axiom_namespace_create (const axutil_env_t *env,
                        const axis2_char_t *uri,
                        const axis2_char_t *prefix);

axiom_element_t *
axiom_element_create (const axutil_env_t *env,
                      axiom_node_t       *parent,
                      const axis2_char_t *localname,
                      axiom_namespace_t  *ns,
                      axiom_node_t       **node);

axis2_status_t 
axiom_element_set_text(axiom_element_t    *om_element,
                       const axutil_env_t *env,
                       const axis2_char_t *text,
                       axiom_node_t       *element_node);

axis2_char_t * 
axiom_node_to_string(axiom_node_t       *om_node,
                     const axutil_env_t *env);

axiom_types_t
axiom_node_get_node_type(axiom_node_t       *om_node,
                         const axutil_env_t *env);

axiom_node_t *
axiom_node_get_parent(axiom_node_t       *om_node,
                      const axutil_env_t *env);

%inline %{
axiom_element_t *
ruby_axiom_node_get_data_element(axiom_node_t       *om_node,
                                 const axutil_env_t *env)
{
  return (axiom_element_t *)axiom_node_get_data_element(om_node, env);
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

%inline %{
axis2_status_t
ruby_axiom_data_handler_set_binary_data(axiom_data_handler_t *data_handler,
                                        const axutil_env_t   *env,
                                        axis2_byte_t         *input_stream,
                                        int                   input_stream_len)
{
  return axiom_data_handler_set_binary_data(data_handler, env, input_stream, input_stream_len);
}
%}

axiom_text_t *
axiom_text_create_with_data_handler(const axutil_env_t   *env,
                                    axiom_node_t         *parent,
                                    axiom_data_handler_t *data_handler,
                                    axiom_node_t         **node);

axis2_status_t
axiom_text_set_optimize(struct axiom_text  *om_text,
                        const axutil_env_t *env,
                        axis2_bool_t        optimize);

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

axiom_node_t * 
axis2_svc_client_send_receive(axis2_svc_client_t *svc_client,
                              const axutil_env_t *env,
                              const axiom_node_t *payload);

axis2_status_t
axis2_svc_client_send_robust(axis2_svc_client_t *svc_client,
                             const axutil_env_t *env,
                             const axiom_node_t *payload);

void
axutil_log_impl_log_error(axutil_log_t      *log,
                          const axis2_char_t *filename,
                          const int          linenumber,
                          const axis2_char_t *format, ...);


axiom_xml_reader_t * 
axiom_xml_reader_create_for_memory(const axutil_env_t *env,
                                   void               *container,
                                   int                size,
                                   const axis2_char_t *encoding,
                                   int                type);

%inline %{
axiom_xml_reader_t *
ruby_axiom_xml_reader_create_for_memory(const axutil_env_t *env,
                                        char               *container,
                                        int                size,
                                        const axis2_char_t *encoding,
                                        int                type)
{
  axiom_xml_reader_create_for_memory(env, container, size, encoding, type);
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

axutil_qname_t * 
axutil_qname_create (const axutil_env_t *env,
                     const axis2_char_t *localpart,
                     const axis2_char_t *namespace_uri,
                     const axis2_char_t *prefix);

axis2_char_t * 
axutil_qname_get_prefix(const axutil_qname_t *qname,
                        const axutil_env_t   *env);

axiom_soap_envelope_t * 
axiom_soap_envelope_create(const axutil_env_t *env,
                           axiom_namespace_t  *ns);

axis2_char_t * 
axutil_qname_to_string(struct axutil_qname *qname,
                       const axutil_env_t  *env);

axis2_status_t 
axiom_node_serialize (axiom_node_t       *om_node,
                      const axutil_env_t *env,
                      axiom_output_t     *om_output);

axiom_xml_writer_t * 
axiom_xml_writer_create_for_memory(const axutil_env_t *env,
                                   axis2_char_t       *encoding,
                                   int                is_prefix_default,
                                   int                compression,
                                   int                type);

axiom_output_t * 
axiom_output_create(const axutil_env_t  *env,
                     axiom_xml_writer_t *xml_writer);

axis2_options_t *
axis2_svc_client_get_options(const axis2_svc_client_t *svc_client,
                             const axutil_env_t       *env);

void *
axis2_libxml2_writer_wrapper_get_xml(axiom_xml_writer_t *writer,
                                     const axutil_env_t *env);

axis2_svc_ctx_t *
axis2_svc_client_get_svc_ctx(const axis2_svc_client_t *svc_client,
                             const axutil_env_t       *env);

axis2_conf_ctx_t *
axis2_svc_ctx_get_conf_ctx(const axis2_svc_ctx_t *svc_ctx,
                           const axutil_env_t    *env);

axis2_conf_t *
axis2_conf_ctx_get_conf(const axis2_conf_ctx_t  *conf_ctx,
                        const axutil_env_t       *env);

axis2_module_desc_t *
axis2_conf_get_module(const axis2_conf_t        *conf,
                      const axutil_env_t         *env,
                      const axutil_qname_t       *qname);

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
                                 axis2_scope_t       scope,
                                 axis2_bool_t        own_value,
                                 AXIS2_FREE_VOID_ARG free_func,
                                 void                *value);

%inline %{
axis2_char_t *
ruby_axutil_strdup(const axutil_env_t *env,
                   axis2_char_t       *ptr)
{
  return (void *)axutil_strdup(env, (void *)ptr);        
}
%}

%inline %{
int
ruby_axutil_strcmp(const axis2_char_t * s1,
                   const axis2_char_t * s2)
{
  return ((axutil_strcmp(s1, s2) == 0) ? AXIS2_TRUE : AXIS2_FALSE);
}
%}

axutil_property_t * 
axutil_property_create(const axutil_env_t *env);

axis2_status_t
axutil_property_set_value(axutil_property_t  *property,
                          const axutil_env_t *env,
                          void               *value);

%inline %{
axis2_status_t
ruby_axutil_property_set_value(axutil_property_t  *property,
                               const axutil_env_t *env,
                               axis2_char_t       *value)
{
  return axutil_property_set_value(property, env, value);
}
%}

axis2_status_t
axis2_options_set_property(axis2_options_t    *options,
                           const axutil_env_t *env,
                           const axis2_char_t *property_key,
                           const void         *property);

%inline %{
axis2_status_t
ruby_axis2_options_set_property(axis2_options_t *options,
                                const axutil_env_t  *env,
                                const axis2_char_t  *property_key,
                                axutil_property_t   *property)
{
  return axis2_options_set_property(options, env, property_key, (void *)property);
}
%}

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

int 
axis2_options_get_soap_version(const axis2_options_t *options,
                               const axutil_env_t    *env);

axiom_node_t * 
axiom_soap_fault_get_base_node(axiom_soap_fault_t *fault,
                               const axutil_env_t *env);

void * 
axiom_xml_writer_get_xml(axiom_xml_writer_t *writer,
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
                                   const axis2_bool_t paser_reset_flag);

%inline %{
void axis2_log_debug(axutil_env_t *env,
                     axis2_char_t *str)
{
  AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, str);
}
%}

%inline %{
void axis2_log_critical(axutil_env_t *env,
                        axis2_char_t *str)
{
  AXIS2_LOG_CRITICAL(env->log, AXIS2_LOG_SI, str);
}
%}

%inline %{
void axis2_log_error(axutil_env_t *env,
                     axis2_char_t *str)
{
  AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, str);
}
%}
